#include <stack>
#include "tools.h"
using std::stack;
class LgStack{
    private:
    stack<lguint>data;
    lguint size;
    public:
    LgStack();
    void pop();
    void qpop();//不检测
    lguint top();
    lguint qtop();//不检测
    lguint ttop();
    lguint poptop();
    void push(lguint x);
    bool empty();
    lguint length();
};
