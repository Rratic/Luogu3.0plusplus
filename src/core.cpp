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
    queue<lguint>b;
    for(lguint i=0;i<k;++i){
        lguint a=T0.poptop();
        b.push(a);
    }
    while(!b.empty()){
        T0.push(b.front());b.pop();
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
case 18:{//旋转
    lguint k=T0.poptop(),q=T1.poptop();
    if(k>_txx_oper)throw UNDEFINED_BEHAVIOR;
    vector<lguint>b;
    for(lguint i=0;i<k;++i)b.push_back(T0.poptop());
    for(lguint i=1;i<=q;i++)T0.push(b[q-i]);
    q=k-q;
    for(lguint i=1;i<=q;i++)T0.push(b[k-i]);
    Pk0;D2;break;
}
case 19:{//批量移动
    lguint k=T1.poptop();
    if(k>_txx_oper)throw UNDEFINED_BEHAVIOR;
    stack<lguint>b;
    for(lguint i=0;i<k;++i)b.push(T1.poptop());
    while(!b.empty()){
        T0.push(b.top());b.pop();
    }
    Pk0;D2;break;
}
case 20:{//批量复制
    lguint k=T1.poptop();
    if(k>_txx_oper)throw UNDEFINED_BEHAVIOR;
    stack<lguint>b;
    for(lguint i=0;i<k;++i)b.push(T1.poptop());
    while(!b.empty()){
        T0.push(b.top());T1.push(b.top());b.pop();
    }
    Pk0;D2;break;
}
case 21:{//填充
    lguint k=T0.poptop(),v=T1.ttop();
    if(k>_txx_oper)throw UNDEFINED_BEHAVIOR;
    for(lguint i=0;i<k;++i)T0.push(v);
    Pk0;D2;break;
}
case 22:{//ι 这符号smg
    lguint k=T0.poptop(),v=T1.ttop();
    if(k>_txx_oper)throw UNDEFINED_BEHAVIOR;
    for(lguint i=1;i<=k;++i)T0.push(v+k-i);
    Pk0;D2;break;
}
case 23:{//求和
    lguint k=T1.poptop();
    if(k>_txx_oper)throw UNDEFINED_BEHAVIOR;
    stack<lguint>b;
    lguint ans=0;
    for(lguint i=0;i<k;++i){
        lguint a=T1.poptop();b.push(a);
        ans=addp(ans,a,_mod);
    }
    while(!b.empty()){
        T1.push(b.top());b.pop();
    }
    T0.push(ans);T1.push(k);D2;break;
}
case 24:{//求积
    lguint k=T1.poptop();
    if(k>_txx_oper)throw UNDEFINED_BEHAVIOR;
    stack<lguint>b;
    lguint ans=0;
    for(lguint i=0;i<k;++i){
        lguint a=T1.poptop();b.push(a);
        ans=ans*a%_mod;
    }
    while(!b.empty()){
        T1.push(b.top());b.pop();
    }
    T0.push(ans);T1.push(k);D2;break;
}
case 25:{//DFT
    lguint k=T0.poptop();
    if(k==0||k>_txx_oper)throw UNDEFINED_BEHAVIOR;
    while(k!=1){
        if(k&1)throw UNDEFINED_BEHAVIOR;
        k>>=1;
    }
    lguint t=FastPow(_t13_base,(_mod-1)/k,_mod);//预处理
    vector<lguint>a;
    for(lguint i=0;i<k;++i)a.push_back(T0.poptop());
    for(lguint i=k;i>=1;--i){//k-1;0;--会挂
        lguint ans=0;
        for(lguint j=0;j<k;++j){
            ans+=(a[j]*FastPow(t,(i-1)*j%_mod,_mod)%_mod);
        }
        T0.push(ans);
    }
    //似乎可以优化？
    Pk0;D1;break;
}
case 26:{//批量加法
    lguint k=T0.poptop(),x=T1.ttop();
    if(k>_txx_oper)throw UNDEFINED_BEHAVIOR;
    stack<lguint>b;
    for(lguint i=0;i<k;++i)b.push(T0.poptop());
    while(!b.empty()){
        T0.push(addp(b.top(),x,_mod));b.pop();
    }
    Pk0;D2;break;
}
case 27:{//批量减法
    lguint k=T0.poptop(),x=T1.ttop();
    if(k>_txx_oper)throw UNDEFINED_BEHAVIOR;
    stack<lguint>b;
    for(lguint i=0;i<k;++i)b.push(T0.poptop());
    while(!b.empty()){
        T0.push(subp(b.top(),x,_mod));b.pop();
    }
    Pk0;D2;break;
}
case 28:{//批量乘法
    lguint k=T0.poptop(),x=T1.ttop();
    if(k>_txx_oper)throw UNDEFINED_BEHAVIOR;
    stack<lguint>b;
    for(lguint i=0;i<k;++i)b.push(T0.poptop());
    while(!b.empty()){
        T0.push(b.top()*x%_mod);b.pop();
    }
    Pk0;D2;break;
}
case 29:{//批量整数除法
    lguint k=T0.poptop(),x=T1.ttop();
    if(x==0||k>_txx_oper)throw UNDEFINED_BEHAVIOR;
    stack<lguint>b;
    for(lguint i=0;i<k;++i)b.push(T0.poptop());
    while(!b.empty()){
        T0.push(b.top()/x);b.pop();
    }
    Pk0;D2;break;
}
case 30:{//批量整数取模
    lguint k=T0.poptop(),x=T1.ttop();
    if(x==0||k>_txx_oper)throw UNDEFINED_BEHAVIOR;
    stack<lguint>b;
    for(lguint i=0;i<k;++i)b.push(T0.poptop());
    while(!b.empty()){
        T0.push(b.top()%x);b.pop();
    }
    Pk0;D2;break;
}
case 31:{//向量加法
    lguint k=T0.poptop();
    if(k>_txx_oper)throw UNDEFINED_BEHAVIOR;
    stack<lguint>c,a,b;
    for(lguint i=0;i<k;++i){
        a.push(T1.poptop());
        b.push(T2.poptop());
        lguint t=addp(a.top(),b.top(),_mod);
        c.push(t);
    }
    for(lguint i=0;i<k;i++){
        T1.push(a.top());a.pop();
        T2.push(b.top());b.pop();
        T0.push(c.top());c.pop();
    }
    Pk0;D3;break;
}
case 32:{//向量减法
    lguint k=T0.poptop();
    if(k>_txx_oper)throw UNDEFINED_BEHAVIOR;
    stack<lguint>c,a,b;
    for(lguint i=0;i<k;++i){
        a.push(T1.poptop());
        b.push(T2.poptop());
        lguint t=subp(a.top(),b.top(),_mod);
        c.push(t);
    }
    for(lguint i=0;i<k;i++){
        T1.push(a.top());a.pop();
        T2.push(b.top());b.pop();
        T0.push(c.top());c.pop();
    }
    Pk0;D3;break;
    Pk0;D3;break;
}
case 33:{//向量乘法
    lguint k=T0.poptop();
    if(k>_txx_oper)throw UNDEFINED_BEHAVIOR;
    stack<lguint>c,a,b;
    for(lguint i=0;i<k;++i){
        a.push(T1.poptop());
        b.push(T2.poptop());
        lguint t=a.top()*b.top()%_mod;
        c.push(t);
    }
    for(lguint i=0;i<k;i++){
        T1.push(a.top());a.pop();
        T2.push(b.top());b.pop();
        T0.push(c.top());c.pop();
    }
    Pk0;D3;break;
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
