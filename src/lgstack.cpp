#include "lgstack.h"
LgStack::LgStack(){size=0;}
void LgStack::pop(){
    if(size==0)throw STACK_UNDERFLOW;
    data.pop();
    size--;
}
void LgStack::qpop(){
    data.pop();
}
lguint LgStack::top(){
    if(size==0)throw ILLEGAL_ACCESS;
    return data.top();
}
lguint LgStack::qtop(){
    return data.top();
}
lguint LgStack::ttop(){
    if(size==0)throw UNDEFINED_BEHAVIOR;
    return data.top();
}
lguint LgStack::poptop(){
    if(size==0)throw UNDEFINED_BEHAVIOR;
    lguint t=data.top();
    data.pop();
    size--;
    return t;
}
void LgStack::push(lguint x){
    if(size==_stack)throw STACK_OVERFLOW;
    data.push(x);
    size++;
}
bool LgStack::empty(){
    return size==0;
}
lguint LgStack::length(){
    return size;
}
