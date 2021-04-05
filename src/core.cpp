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
