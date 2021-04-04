#include "work.h"
vector<string> getfromfile(string filename){
    vector<string>s;
    ifstream fin;
    fin.open(filename,std::ios::in);
    if(!fin.is_open())throw FILE_ERROR;
    string t;
    while(getline(fin,t)){
        s.push_back(t);
    }
    return s;
}
bool initstackfromfile(string filename){
    vector<string>s;
    ifstream fin;
    fin.open(filename,std::ios::in);
    if(!fin.is_open())throw FILE_ERROR;
    string t;
    while(getline(fin,t)){
        s=split(t,' ');
        if(s.size()==0)return FORMAT_ERROR;
        uint32_t tt=selected_stack(s[0]);
        s.erase(s.begin());
        for(auto i:s){
            Three[tt].push(s_to_i32(i));
        }
    }
    return true;
}
