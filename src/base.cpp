#include "base.h"
uint16_t MAX_STATE=100000,MAX_STACK=1000000,TIME_LIMIT=1000000,BIG_TIME_COST=10000;
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
bool luogu_stack::empty(){
    return size==0;
}
uint16_t order::order_pattern_num=34;
order_pattern order::basic[]={
/*
true=字母
false=数字
*/
{"PUS",3,{0,1,1}},
{"POP",2,{0,1}},
{"MOV",3,{0,0,1}},
{"CPY",3,{1,1,0}},
{"ADD",4,{1,1,1,0}},
{"SUB",4,{1,1,1,0}},
{"MUL",4,{1,1,1,0}},
{"DIV",4,{1,1,1,0}},
{"MOD",4,{1,1,1,0}},
{"EMP",3,{1,0,0}},
{"CMP",4,{1,1,0,0}},
{"TER",0},
//{"",,{,,,}},
};
uint16_t order::search_basic(string ordername){
    for(uint16_t i=0;i<order_pattern_num;i++){
        if(basic[i].name==ordername)return i;
    }
    return 65536;
}
bool order::load(string s){
    vector<string>t=split(s,' ');
    name=search_basic(t[0]);
    if(name==65536)throw UNKNOWN_ORDER;
    for(uint8_t i=1;i<=basic[name].typen;i++){
        if(basic[name].type)args[i-1]=selected_stack(t[i]);
        else args[i-1]=s_to_i32(t[i]);
    }
}
