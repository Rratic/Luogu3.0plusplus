#include "core.h"
luogu_stack Three[3];
uint32_t state_num,default_state;
vector<order>orders;
string public_message;
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
    uint32_t now_state=default_state;
    try{
        while(true){
            ++c;
            if(c>TIME_LIMIT)throw TIME_LIMIT_EXCEEDED;
            order temp=copy_state();
            switch(temp.name){
                case 0:{
                    Three[temp.args[0]].push(temp.args[1]);
                    default_state=temp.args[2];
                    break;
                }
            }
        }
    }
    catch(LgErrorType i){}
}
