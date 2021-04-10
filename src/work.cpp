#include "work.h"
void incode(string name){
    ifstream fin;
    fin.open(name,std::ios::in);
    if(!fin.is_open()){
        cerr<<name<<" : ";
        throw FILE_ERROR;
    }
    string s;
    if(!getline(fin,s))throw FORMAT_ERROR;
    vector<string>t=split(s,' ');
    default_state=s_to_i64(t.at(1));
    state_num=s_to_i64(t[0]);
    if(state_num>_state)throw TOO_MANY_STATES;
    for(lguint i=0;i<state_num;i++){
        if(!getline(fin,s))throw FORMAT_ERROR;
        order tt;
        tt.load(s);
        orders.push_back(tt);
    }
}
void instack(string name,bool rev){
    ifstream fin;
    fin.open(name,std::ios::in);
    if(!fin.is_open()){
        cerr<<name<<" : ";
        throw FILE_ERROR;
    }
    string s;
    while(getline(fin,s)){
        vector<string> t=split(s,' ');
        if(t.size()==0)throw FORMAT_ERROR;
        uint32_t tt=SelectedStack(t.at(0));
        t.erase(t.begin());
        if(rev)for(auto i=t.rbegin();i!=t.rend();i++)Three[tt].push(s_to_i64(*i));
        else for(auto i=t.begin();i!=t.end();i++)Three[tt].push(s_to_i64(*i));
    }
}
void excute(){
    lguint timer=0;
    while(true){
        if(excute_line(timer))break;
    }
}
void outstack(string name,bool rev){
    ofstream fout;
    fout.open(name,std::ios::out);
    if(!fout.is_open()){
        cerr<<name<<" : ";
        throw FILE_ERROR;
    }
    for(int i=0;i<3;++i){
        fout<<char('A'+i);
        if(rev){
            stack<lguint>t;
            while(!Three[i].empty()){
                t.push(Three[i].qtop());
                Three[i].qpop();
            }
            while(!t.empty()){
                fout<<" "<<t.top();
                t.pop();
            }
        }
        else{
            while(!Three[i].empty()){
                fout<<" "<<Three[i].top();
                Three[i].pop();
            }
        }
        fout<<'\n';
    }
}
