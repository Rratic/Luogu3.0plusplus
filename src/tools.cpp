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
};
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
