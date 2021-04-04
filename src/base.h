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
    //
    FILE_ERROR,
    FORMAT_ERROR,
};
extern uint16_t MAX_STATE,MAX_STACK,TIME_LIMIT;
extern uint32_t do_mod_p;
vector<string> split(string s,char sign);
uint16_t selected_stack(string s);
uint32_t s_to_i32(string s);
class luogu_stack{
    private:
    stack<uint32_t>data;
    uint16_t size;
    public:
    luogu_stack();
    void pop();
    uint32_t top();
    void push(uint32_t x);
    bool empty();
};
class order{
    public:
    uint8_t name;
    uint32_t args[4];
    bool load(string s);
};
