#include "core.h"
luogu_stack Three[3];
uint32_t state_num,default_state;
vector<order>orders;
order copy_state(){
    return orders[default_state-1];
    //索引方式不同
}
bool initall(queue<string>s){
    vector<string>t=split(s.front(),' ');
    state_num=s_to_i32(t[0]),default_state=s_to_i32(t[1]);
    if(state_num>MAX_STATE)throw TOO_MANY_STATES;
    s.pop();
    while(!s.empty()){
        order tt;
        tt.load(s.front());
        s.pop();
        orders.push_back(tt);
    }
    return true;
}
bool excute(){
    uint32_t c=0;
    bool doexit=false;
    try{
        while(true){
            order temp=copy_state();
            if(temp.name<12)++c;
            else c+=BIG_TIME_COST;
            if(c>TIME_LIMIT)throw TIME_LIMIT_EXCEEDED;
            switch(temp.name){
                case 0:{
                    Three[temp.args[0]].push(temp.args[1]);
                    default_state=temp.args[2];
                    break;
                }
                case 1:{
                    Three[temp.args[0]].pop();
                    default_state=temp.args[1];
                    break;
                }
                case 2:{
                    uint32_t t=Three[temp.args[1]].top();
                    Three[temp.args[0]].push(t);
                    Three[temp.args[1]].pop();
                    default_state=temp.args[2];
                    break;
                }
                case 3:{
                    uint32_t t=Three[temp.args[1]].top();
                    Three[temp.args[0]].push(t);
                    default_state=temp.args[2];
                    break;
                }
                case 4:{//ADD
                    uint32_t t1=Three[temp.args[1]].top();
                    uint32_t t2=Three[temp.args[2]].top();
                    Three[temp.args[0]].push((t1+t2)%do_mod_p);
                    default_state=temp.args[3];
                    break;
                }
                case 5:{//SUB
                    uint32_t t1=Three[temp.args[1]].top();
                    uint32_t t2=Three[temp.args[2]].top();
                    if(t1<t2)t1+=do_mod_p;
                    t1-=t2;
                    Three[temp.args[0]].push(t1);
                    default_state=temp.args[3];
                    break;
                }
                case 6:{//MUL
                    uint32_t t1=Three[temp.args[1]].top();
                    uint32_t t2=Three[temp.args[2]].top();
                    Three[temp.args[0]].push(uint64_t(t1)*t2%do_mod_p);
                    default_state=temp.args[3];
                    break;
                }
                case 7:{//DIV
                    uint32_t t1=Three[temp.args[1]].top();
                    uint32_t t2=Three[temp.args[2]].top();
                    if(t2==0)throw DIVIDE_BY_ZERO;
                    Three[temp.args[0]].push(t1/t2);
                    default_state=temp.args[3];
                    break;
                }
                case 8:{//MOD
                    uint32_t t1=Three[temp.args[1]].top();
                    uint32_t t2=Three[temp.args[2]].top();
                    if(t2==0)throw DIVIDE_BY_ZERO;
                    Three[temp.args[0]].push(t1%t2);
                    default_state=temp.args[3];
                    break;
                }
                case 9:{
                    if(Three[temp.args[0]].empty())default_state=temp.args[1];
                    else default_state=temp.args[2];
                    break;
                }
                case 10:{
                    if(Three[temp.args[0]].top()<=Three[temp.args[1]].top())default_state=temp.args[2];
                    else default_state=temp.args[3];
                    break;
                }
                case 11:{//TER
                    doexit=true;
                    break;
                }
                case 12:{//T00
                    uint32_t k=Three[temp.args[0]].poptop();
                    if(k>OPER_STACK_LIMIT)throw UNDEFINED_BEHAVIOR;
                    stack<uint32_t>b;
                    uint32_t ans=0;
                    for(uint32_t i=0;i<k;++k){
                        uint32_t a=Three[temp.args[0]].poptop();
                        ans+=a;
                        if(ans>=do_mod_p)ans-=do_mod_p;
                        b.push(ans);
                    }
                    while(!b.empty()){
                        Three[temp.args[0]].push(b.top());
                        b.pop();
                    }
                    Three[temp.args[0]].push(k);
                    default_state=temp.args[1];
                    break;
                }
                case 13:{//T01
                    uint32_t k=Three[temp.args[0]].poptop();
                    if(k>OPER_STACK_LIMIT)throw UNDEFINED_BEHAVIOR;
                    stack<uint32_t>b;
                    uint32_t ans=0;
                    for(uint32_t i=0;i<k;++k){
                        uint32_t a=Three[temp.args[0]].poptop();
                        b.push(a);
                    }
                    while(!b.empty()){
                        ans+=b.top();
                        if(ans>=do_mod_p)ans-=do_mod_p;
                        Three[temp.args[0]].push(ans);
                        b.pop();
                    }
                    Three[temp.args[0]].push(k);
                    default_state=temp.args[1];
                    break;
                }
                case 14:{//T02
                    uint32_t k=Three[temp.args[0]].poptop();
                    if(k>OPER_STACK_LIMIT)throw UNDEFINED_BEHAVIOR;
                    stack<uint32_t>b;
                    uint32_t ans=0;
                    for(uint32_t i=0;i<k;++k){
                        uint32_t a=Three[temp.args[0]].poptop();
                        if(a<ans)throw UNDEFINED_BEHAVIOR;
                        b.push(a-ans);
                        ans=a;
                    }
                    while(!b.empty()){
                        Three[temp.args[0]].push(b.top());
                        b.pop();
                    }
                    Three[temp.args[0]].push(k);
                    default_state=temp.args[1];
                    break;
                }
                case 15:{//T03
                    uint32_t k=Three[temp.args[0]].poptop();
                    if(k>OPER_STACK_LIMIT)throw UNDEFINED_BEHAVIOR;
                    stack<uint32_t>b;
                    for(uint32_t i=0;i<k;++k){
                        uint32_t a=Three[temp.args[0]].poptop();
                        b.push(a);
                    }
                    while(!b.empty()){
                        Three[temp.args[0]].push(b.top());
                        b.pop();
                    }
                    Three[temp.args[0]].push(k);
                    default_state=temp.args[1];
                    break;
                }
                case 16:{//T04
                    uint32_t k=Three[temp.args[0]].poptop();
                    if(k>OPER_STACK_LIMIT)throw UNDEFINED_BEHAVIOR;
                    vector<uint32_t>b;
                    for(uint32_t i=0;i<k;++k){
                        uint32_t a=Three[temp.args[0]].poptop();
                        b.push_back(a);
                    }
                    sort(b.begin(),b.end());
                    for(auto i=b.rbegin();i!=b.rend();i++){
                        Three[temp.args[0]].push(*i);
                    }
                    Three[temp.args[0]].push(k);
                    default_state=temp.args[1];
                    break;
                }
                case 17:{//T05
                    uint32_t k=Three[temp.args[0]].poptop();
                    if(k>OPER_STACK_LIMIT)throw UNDEFINED_BEHAVIOR;
                    vector<uint32_t>b;
                    for(uint32_t i=0;i<k;++k){
                        uint32_t a=Three[temp.args[0]].poptop();
                        b.push_back(a);
                    }
                    sort(b.begin(),b.end());
                    for(auto i:b)Three[temp.args[0]].push(i);
                    Three[temp.args[0]].push(k);
                    default_state=temp.args[1];
                    break;
                }
                case 18:{//T06
                    uint32_t k=Three[temp.args[0]].poptop(),q=Three[temp.args[1]].poptop();
                    if(k>OPER_STACK_LIMIT)throw UNDEFINED_BEHAVIOR;
                    vector<uint32_t>b;
                    for(uint32_t i=0;i<k;++k){
                        uint32_t a=Three[temp.args[0]].poptop();
                        b.push_back(a);
                    }
                    for(uint32_t i=1;i<=q;i++){
                        Three[temp.args[0]].push(b[q-i+1]);
                    }
                    q=k-q;
                    for(uint32_t i=1;i<=q;i++){
                        Three[temp.args[0]].push(b[k-i+1]);
                    }
                    Three[temp.args[0]].push(k);
                    default_state=temp.args[2];
                    break;
                }
                case 19:{//T07
                    uint32_t k=Three[temp.args[1]].poptop();
                    if(k>OPER_STACK_LIMIT)throw UNDEFINED_BEHAVIOR;
                    queue<uint32_t>b;
                    for(uint32_t i=0;i<k;++k){
                        uint32_t a=Three[temp.args[1]].poptop();
                        b.push(a);
                    }
                    while(!b.empty()){
                        Three[temp.args[0]].push(b.front());
                        b.pop();
                    }
                    Three[temp.args[0]].push(k);
                    default_state=temp.args[2];
                    break;
                }
                case 20:{//T08
                    uint32_t k=Three[temp.args[1]].poptop();
                    if(k>OPER_STACK_LIMIT)throw UNDEFINED_BEHAVIOR;
                    queue<uint32_t>b;
                    for(uint32_t i=0;i<k;++k){
                        uint32_t a=Three[temp.args[1]].poptop();
                        b.push(a);
                    }
                    while(!b.empty()){
                        Three[temp.args[0]].push(b.front());
                        Three[temp.args[1]].push(b.front());
                        b.pop();
                    }
                    Three[temp.args[0]].push(k);
                    default_state=temp.args[2];
                    break;
                }
                case 21:{//T09
                    uint32_t k=Three[temp.args[0]].poptop(),v=Three[temp.args[1]].ttop();
                    if(k>OPER_STACK_LIMIT)throw UNDEFINED_BEHAVIOR;
                    for(uint32_t i=0;i<k;++i)Three[temp.args[0]].push(v);
                    Three[temp.args[0]].push(k);
                    default_state=temp.args[2];
                    break;
                }
                case 22:{//T10
                    uint32_t k=Three[temp.args[0]].poptop(),v=Three[temp.args[1]].ttop();
                    if(k>OPER_STACK_LIMIT)throw UNDEFINED_BEHAVIOR;
                    for(uint32_t i=1;i<=k;++i)Three[temp.args[0]].push(v+k-i);
                    Three[temp.args[0]].push(k);
                    default_state=temp.args[2];
                    break;
                }
                case 23:{//T11
                    uint32_t k=Three[temp.args[1]].poptop();
                    if(k>OPER_STACK_LIMIT)throw UNDEFINED_BEHAVIOR;
                    queue<uint32_t>b;
                    uint32_t ans=0;
                    for(uint32_t i=0;i<k;++k){
                        uint32_t a=Three[temp.args[1]].poptop();
                        b.push(a);
                        ans+=a;
                        if(ans>=do_mod_p)ans-=do_mod_p;
                    }
                    while(!b.empty()){
                        Three[temp.args[1]].push(b.front());
                        b.pop();
                    }
                    Three[temp.args[0]].push(ans);
                    Three[temp.args[1]].push(k);
                    default_state=temp.args[2];
                    break;
                }
                case 24:{//T12
                    uint32_t k=Three[temp.args[1]].poptop();
                    if(k>OPER_STACK_LIMIT)throw UNDEFINED_BEHAVIOR;
                    queue<uint32_t>b;
                    uint32_t ans=1;
                    for(uint32_t i=0;i<k;++k){
                        uint32_t a=Three[temp.args[1]].poptop();
                        b.push(a);
                        ans*=a;
                        ans%=do_mod_p;
                    }
                    while(!b.empty()){
                        Three[temp.args[1]].push(b.front());
                        b.pop();
                    }
                    Three[temp.args[0]].push(ans);
                    Three[temp.args[1]].push(k);
                    default_state=temp.args[2];
                    break;
                }
                case 25:{//T13
                    break;
                }
                case 26:{//T14
                    uint32_t k=Three[temp.args[0]].poptop(),x=Three[temp.args[1]].poptop();
                    if(k>OPER_STACK_LIMIT)throw UNDEFINED_BEHAVIOR;
                    stack<uint32_t>b;
                    for(uint32_t i=0;i<k;++k){
                        uint32_t a=Three[temp.args[0]].poptop();
                        b.push(a);
                    }
                    while(!b.empty()){
                        Three[temp.args[0]].push(b.top()+x);
                        b.pop();
                    }
                    Three[temp.args[0]].push(k);
                    default_state=temp.args[2];
                    break;
                }
                case 27:{//T15
                    uint32_t k=Three[temp.args[0]].poptop(),x=Three[temp.args[1]].poptop();
                    if(k>OPER_STACK_LIMIT)throw UNDEFINED_BEHAVIOR;
                    stack<uint32_t>b;
                    for(uint32_t i=0;i<k;++k){
                        uint32_t a=Three[temp.args[0]].poptop();
                        b.push(a);
                    }
                    while(!b.empty()){
                        uint32_t t=b.top();
                        if(t<x)t+=do_mod_p;
                        Three[temp.args[0]].push(t-x);
                        b.pop();
                    }
                    Three[temp.args[0]].push(k);
                    default_state=temp.args[2];
                    break;
                }
                case 28:{//T16
                    uint32_t k=Three[temp.args[0]].poptop(),x=Three[temp.args[1]].poptop();
                    if(k>OPER_STACK_LIMIT)throw UNDEFINED_BEHAVIOR;
                    stack<uint32_t>b;
                    for(uint32_t i=0;i<k;++k){
                        uint32_t a=Three[temp.args[0]].poptop();
                        b.push(a);
                    }
                    while(!b.empty()){
                        Three[temp.args[0]].push(b.top()*x%do_mod_p);
                        b.pop();
                    }
                    Three[temp.args[0]].push(k);
                    default_state=temp.args[2];
                    break;
                }
                case 29:{//T17
                    uint32_t k=Three[temp.args[0]].poptop(),x=Three[temp.args[1]].poptop();
                    if(x==0||k>OPER_STACK_LIMIT)throw UNDEFINED_BEHAVIOR;
                    stack<uint32_t>b;
                    for(uint32_t i=0;i<k;++k){
                        uint32_t a=Three[temp.args[0]].poptop();
                        b.push(a);
                    }
                    while(!b.empty()){
                        Three[temp.args[0]].push(b.top()/x);
                        b.pop();
                    }
                    Three[temp.args[0]].push(k);
                    default_state=temp.args[2];
                    break;
                }
                case 30:{//T18
                    uint32_t k=Three[temp.args[0]].poptop(),x=Three[temp.args[1]].poptop();
                    if(x==0||k>OPER_STACK_LIMIT)throw UNDEFINED_BEHAVIOR;
                    stack<uint32_t>b;
                    for(uint32_t i=0;i<k;++k){
                        uint32_t a=Three[temp.args[0]].poptop();
                        b.push(a);
                    }
                    while(!b.empty()){
                        Three[temp.args[0]].push(b.top()%x);
                        b.pop();
                    }
                    Three[temp.args[0]].push(k);
                    default_state=temp.args[2];
                    break;
                }
                case 31:{//T19
                    uint32_t k=Three[temp.args[0]].poptop();
                    if(k>OPER_STACK_LIMIT)throw UNDEFINED_BEHAVIOR;
                    stack<uint32_t>c;
                    for(uint32_t i=0;i<k;++k){
                        uint32_t t=Three[temp.args[1]].poptop()+Three[temp.args[2]].poptop();
                        if(t>=do_mod_p)t-=do_mod_p;
                        c.push(t);
                    }
                    while(!c.empty()){
                        Three[temp.args[0]].push(c.top());
                        c.pop();
                    }
                    Three[temp.args[0]].push(k);
                    default_state=temp.args[3];
                    break;
                }
                case 32:{//T20
                    uint32_t k=Three[temp.args[0]].poptop();
                    if(k>OPER_STACK_LIMIT)throw UNDEFINED_BEHAVIOR;
                    stack<uint32_t>c;
                    for(uint32_t i=0;i<k;++k){
                        uint32_t t=Three[temp.args[1]].poptop()+do_mod_p;
                        t-=Three[temp.args[2]].poptop();
                        if(t>=do_mod_p)t-=do_mod_p;
                        c.push(t);
                    }
                    while(!c.empty()){
                        Three[temp.args[0]].push(c.top());
                        c.pop();
                    }
                    Three[temp.args[0]].push(k);
                    default_state=temp.args[3];
                    break;
                }
                case 33:{//T21
                    uint32_t k=Three[temp.args[0]].poptop();
                    if(k>OPER_STACK_LIMIT)throw UNDEFINED_BEHAVIOR;
                    stack<uint32_t>c;
                    for(uint32_t i=0;i<k;++k){
                        uint32_t t=Three[temp.args[1]].poptop()*Three[temp.args[2]].poptop()%do_mod_p;
                        c.push(t);
                    }
                    while(!c.empty()){
                        Three[temp.args[0]].push(c.top());
                        c.pop();
                    }
                    Three[temp.args[0]].push(k);
                    default_state=temp.args[3];
                    break;
                }
            }
            if(doexit)break;
        }
    }
    catch(LgErrorType i){
        if(i==STACK_OVERFLOW)public_message="STACK_OVERFLOW";
        if(i==STACK_UNDERFLOW)public_message="STACK_UNDERFLOW";
        if(i==ILLEGAL_ACCESS)public_message="ILLEGAL_ACCESS";
        if(i==DIVIDE_BY_ZERO)public_message="DIVIDE_BY_ZERO";
        if(i==UNDEFINED_BEHAVIOR)public_message="UNDEFINED_BEHAVIOR";
        throw UPLOAD;
    }
    return true;
}
