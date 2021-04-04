#include <stack>
#include <vector>
#include <string>
#include <stdint.h>
using std::stack;
using std::vector;
using std::string;
enum LgErrorType{
    STACK_OVERFLOW,
    STACK_UNDERFLOW,
    ILLEGAL_ACCESS,
    TOO_MANY_STATES,
    DIVIDE_BY_ZERO,
    TIME_LIMIT_EXCEEDED,
};
extern uint16_t MAX_STATE,MAX_STACK,TIME_LIMIT;
extern uint32_t do_mod_p;
vector<string> split(string s,char sign);
class luogu_stack{
    private:
    stack<uint32_t>data;
    uint16_t size;
    public:
    luogu_stack();
    void pop();
    uint32_t top();
    void push(uint32_t x);
};
class order{
    public:
    uint8_t name;
    uint32_t args[4];
    bool load(string s);
};
