#include "core.h"
LgStack Three[3];
lguint state_num,default_state;
vector<order>orders;
bool excute_line(lguint &timer){
    order temp=orders[default_state-1];
    if(temp.name<12||temp.name>33)++timer;
    else timer=_txx_cost;//txx操作
    if(timer>_time_limit)throw TIME_LIMIT_EXCEEDED;
    switch(temp.name){
//宏定义
#define A1 temp.args[1]
#define A2 temp.args[2]
#define A3 temp.args[3]
#define T0 Three[temp.args[0]]
#define T1 Three[A1]
#define T2 Three[A2]
#define D1 default_state=A1
#define D2 default_state=A2
#define D3 default_state=A3
#define Dk0 lguint k=T0.poptop();
#define k_txx if(k>_txx_oper)throw UNDEFINED_BEHAVIOR
#define Pk0 T0.push(k)
//分类
//std==1
case 0:T0.push(A1);D2;break;
case 1:T0.pop();D1;break;
case 2:T0.push(T1.top());T1.pop();D2;break;
case 3:T0.push(T1.top());D2;break;
case 4:T0.push(addp(T1.top(),T2.top(),_mod));D3;break;//ADD
case 5:T0.push(subp(T1.top(),T2.top(),_mod));D3;break;//SUB
case 6:T0.push(T1.top()*T2.top()%_mod);D3;break;//MUL
case 7:{lguint t1=T1.top(),t2=T2.top();if(t2==0)throw DIVIDE_BY_ZERO;T0.push(t1/t2);D3;break;}//DIV
case 8:{lguint t1=T1.top(),t2=T2.top();if(t2==0)throw DIVIDE_BY_ZERO;T0.push(t1%t2);D3;break;}//MOD
case 9:if(T0.empty())D1;else D2;break;
case 10:if(T0.top()<=T1.top())D2;else D3;break;
case 11:return true;//TER

case 12:{//前缀和
    Dk0;k_txx;
    stack<lguint>b;
    lguint ans=0;
    for(lguint i=0;i<k;++i){
        lguint a=T0.poptop();
        ans+=a;if(ans>=_mod)ans-=_mod;
        b.push(ans);
    }
    while(!b.empty()){
        T0.push(b.top());b.pop();
    }
    Pk0;D1;break;
}
case 13:{//后缀和
    Dk0;k_txx;
    stack<lguint>b;
    lguint ans=0;
    for(lguint i=0;i<k;++i){
        lguint a=T0.poptop();
        b.push(a);
    }
    while(!b.empty()){
        ans+=b.top();b.pop();
        if(ans>=_mod)ans-=_mod;T0.push(ans);
    }
    Pk0;D1;break;
}
case 14:{//差分
    Dk0;k_txx;
    stack<lguint>b;
    lguint ans=0;
    for(lguint i=0;i<k;++i){
        lguint a=T0.poptop();
        b.push(subp(a,ans,_mod));
        ans=a;
    }
    while(!b.empty()){
        T0.push(b.top());b.pop();
    }
    Pk0;D1;break;
}
case 15:{//反转
    Dk0;k_txx;
    stack<lguint>b;
    for(lguint i=0;i<k;++i){
        lguint a=T0.poptop();
        b.push(a);
    }
    while(!b.empty()){
        T0.push(b.top());b.pop();
    }
    Pk0;D1;break;
}
case 16:{//排序
    Dk0;k_txx;
    vector<lguint>b;
    for(lguint i=0;i<k;++i)b.push_back(T0.poptop());
    sort(b.begin(),b.end());
    for(auto i=b.rbegin();i!=b.rend();i++)T0.push(*i);
    Pk0;D1;break;
}
case 17:{//反向排序
    Dk0;k_txx;
    vector<lguint>b;
    for(lguint i=0;i<k;++i)b.push_back(T0.poptop());
    sort(b.begin(),b.end());
    for(auto i:b)T0.push(i);
    Pk0;D1;break;
}

//std==2
case 34:T0.push(FastPow(T1.top(),T2.top(),_mod));D3;break;
case 35:T0.push(isqrt(T1.top()));D2;break;
case 36:T0.push(T1.top()&T2.top());D3;break;
case 37:T0.push(T1.top()|T2.top());D3;break;
case 38:T0.push(T1.top()^T2.top());D3;break;
case 39:T0.push(T1.top()*FastPow(2,T2.top(),_mod)%_mod);D3;break;
case 40:T0.push(T1.top()>>T2.top());D3;break;
case 41:T0.push(addp(T1.top(),A2,_mod));D3;break;
case 42:T0.push(subp(T1.top(),A2,_mod));D3;break;
case 43:T0.push(T1.top()*A2%_mod);D3;break;
case 44:if(A2==0)throw DIVIDE_BY_ZERO;T0.push(T1.top()/A2);D3;break;
case 45:if(A2==0)throw DIVIDE_BY_ZERO;T0.push(T1.top()%A2);D3;break;
case 46:{int i=getchar();if(i==EOF)T0.push(0);else T0.push(i);D1;break;}
case 47:{
    queue<int>t;lguint c=0;
    while(true){int i=getchar();if(i=='\n'||i==EOF)break;t.push(i);++c;}
    while(!t.empty()){T0.push(t.front());t.pop();}
    D1;break;
}
case 48:{
    queue<int>t;lguint c=0;
    while(true){int i=getchar();if(i==' '||i=='\n'||i==EOF)break;t.push(i);++c;}
    while(!t.empty()){T0.push(t.front());t.pop();}
    D1;break;
}
case 49:if(T0.top()>127)throw UNDEFINED_BEHAVIOR;cout<<char(T0.top());T0.pop();D1;break;
case 50:cout<<T0.top();D1;break;
case 51:{
    lguint k=T0.ttop();T0.pop();
    if(T0.length()<k)throw UNDEFINED_BEHAVIOR;
    for(lguint i=0;i<k;++i){
        if(T0.top()>127)throw UNDEFINED_BEHAVIOR;cout<<char(T0.top());T0.pop();
    }D1;break;
}
case 52:{
    lguint k=T0.ttop();T0.pop();
    if(T0.length()<k)throw UNDEFINED_BEHAVIOR;
    for(lguint i=0;i<k;++i){
        if(T0.top()>127)throw UNDEFINED_BEHAVIOR;cout<<char(T0.top());T0.pop();
    }cout<<endl;D1;break;
}
//删除定义
#undef A1
#undef A2
#undef A3
#undef T0
#undef T1
#undef T2
#undef D1
#undef D2
#undef D3
#undef Dk0
#undef k_txx
#undef Pk0
    }
    return false;
}
