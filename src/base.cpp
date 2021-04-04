#include "base.h"
uint16_t MAX_STATE=100000,MAX_STACK=1000000,TIME_LIMIT=1000000;
uint32_t do_mod_p=(1<<23)+1;
vector<string> split(string s,char sign){
    vector<string>ans;
    size_t l=s.length();
    string temp;
    for(size_t i=0;i<l;++i){
        if(s[i]==sign){
            if(temp!=""){
                ans.push_back(temp);
                temp="";
            }
        }
        else temp+=s[i];
    }
    if(temp!="")ans.push_back(temp);
    return ans;
}
uint16_t selected_stack(string s){
    if(s=="A")return 0;
    else if(s=="B")return 1;
    else if(s=="C")return 2;
    throw FORMAT_ERROR;
    return 0;
}
uint32_t s_to_i32(string s){
    uint32_t ans=0;
    for(auto i:s){
        if(i<'0'||i>'9')throw FORMAT_ERROR;
        ans*=10;
        ans+=(i-'0');
    }
    return ans;
}
luogu_stack::luogu_stack(){size=0;}
void luogu_stack::pop(){
    if(size==0)throw STACK_UNDERFLOW;
    data.pop();
}
uint32_t luogu_stack::top(){
    if(size==0)throw ILLEGAL_ACCESS;
    return data.top();
}
void luogu_stack::push(uint32_t x){
    if(size==MAX_STACK)throw STACK_OVERFLOW;
    data.push(x);
}
