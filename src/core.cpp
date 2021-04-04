#include "core.h"
luogu_stack Three[3];
uint32_t state_num,default_state;
vector<order>orders;
string public_message;
bool initall(queue<string>s){
    vector<string>t=split(s.front(),' ');
    state_num=s_to_i32(t[0]),default_state=s_to_i32(t[1]);
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
}
