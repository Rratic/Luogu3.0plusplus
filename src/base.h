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
    UNDEFINED_BEHAVIOR,
    //
    UNKNOWN_ORDER,
    FILE_ERROR,
    FORMAT_ERROR,
    UPLOAD,//上传
};
extern uint16_t MAX_STATE,MAX_STACK,TIME_LIMIT,BIG_TIME_COST;
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
class order_pattern{
    public:
    string name;
    uint8_t typen;
    bool type[4];
};
class order{
    public:
    static order_pattern basic[];
    static uint16_t order_pattern_num;
    uint16_t name;
    uint32_t args[4];
    uint16_t search_basic(string ordername);
    bool load(string s);
};
