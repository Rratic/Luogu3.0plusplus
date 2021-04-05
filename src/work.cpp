#include "work.h"
queue<string> getfromfile(string filename){
    public_message=filename;
    queue<string>s;
    ifstream fin;
    fin.open(filename,std::ios::in);
    if(!fin.is_open())throw FILE_ERROR;
    string t;
    while(getline(fin,t)){
        s.push(t);
#ifdef LG_DEBUG
        cout<<"Source file read: "<<t<<'\n';
#endif
    }
    return s;
}
bool initstackfromfile(string filename){
    public_message=filename;
    vector<string>s;
    ifstream fin;
    fin.open(filename,std::ios::in);
    if(!fin.is_open())return false;//无文件：无初始化
    string t;
    while(getline(fin,t)){
        s=split(t,' ');
#ifdef LG_DEBUG
        cout<<"Init file read: "<<t<<'\n';
#endif
        if(s.size()==0)throw FORMAT_ERROR;
        uint32_t tt=selected_stack(s.at(0));
        s.erase(s.begin());
        for(auto i:s){
            Three[tt].push(s_to_i32(i));
        }
#ifdef LG_DEBUG
        cout<<"["<<tt<<"](";
        for(auto i:s)cout<<i<<",";
        cout<<")Stack:["<<Three[tt].length()<<"]\n";
#endif
    }
    return true;
}
bool lgwork(string filename){
    public_message=filename;
    try{
        excute();
    }
    catch(LgErrorType i){
        if(i==UPLOAD)cout<<public_message;
        return false;
    }
    {//savefile
        ofstream fout;
        fout.open(filename,std::ios::out);
        if(!fout.is_open())throw FILE_ERROR;
        for(size_t i=0;i<3;++i){
            fout<<char('A'+i);
            while(!Three[i].empty()){
                fout<<" "<<Three[i].top();
                Three[i].pop();
            }
            fout<<'\n';
        }
    }
    return true;
}
