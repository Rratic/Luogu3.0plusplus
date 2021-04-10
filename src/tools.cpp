#include "tools.h"
string ErrorMessage[]={
"STACK_OVERFLOW",
"STACK_UNDERFLOW",
"ILLEGAL_ACCESS",
"TOO_MANY_STATES",
"DIVIDE_BY_ZERO",
"TIME_LIMIT_EXCEEDED",
"UNDEFINED_BEHAVIOR",

"UNKNOWN_ORDER",
"FILE_ERROR",
"FORMAT_ERROR",
"STD_UNSUPPORTTED",
};
lguint \
_mod=119*(1<<23)+1/*998244353*/,\
_stack=1000000,\
_state=100000,\
_std=2,\
_t13_base=114514/*再次声明：此值由GitPinkRabbit制定*/,\
_time_limit=1000000,\
_txx_cost=10000,\
_txx_oper=10000;
string deal(string s){
    string t;
    for(auto i:s){
        if(i==' ')continue;
        if(i>='A'&&i<='Z')i=i-'A'+'a';
        t.push_back(i);
    }
    return t;
}
vector<string> split(string s,char sign){
    vector<string>ans;
    string temp;
    for(auto i:s){
        if(i==sign){
            if(temp!=""){
                ans.push_back(temp);
                temp="";
            }
        }
        else temp.push_back(i);
    }
    if(temp!="")ans.push_back(temp);
    return ans;
}
lguint SelectedStack(string s){
    if(s=="A")return 0;
    else if(s=="B")return 1;
    else if(s=="C")return 2;
    throw FORMAT_ERROR;
    return 0;
}
lguint s_to_i64(string s){
    lguint ans=0;
    for(auto i:s){
        if(i<'0'||i>'9')throw FORMAT_ERROR;
        ans*=10;
        ans+=(i-'0');
    }
    return ans;
}
lguint FastPow(lguint a,lguint b,lguint p){
    if(b==0)return 1;
    if(b==1)return a;
    lguint t=FastPow(a,b/2,p);
    if(b&1)return (t*t%p)*a%p;
    return t*t%p;
}
