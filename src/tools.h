#include <stdexcept>
#include <vector>
#include <string>
using std::vector;
using std::string;
using std::out_of_range;
enum LgErrorType{
    //语法错误
    STACK_OVERFLOW,
    STACK_UNDERFLOW,
    ILLEGAL_ACCESS,
    TOO_MANY_STATES,
    DIVIDE_BY_ZERO,
    TIME_LIMIT_EXCEEDED,
    UNDEFINED_BEHAVIOR,
    //其他错误
    UNKNOWN_ORDER,
    FILE_ERROR,
    FORMAT_ERROR,
};
typedef unsigned long long lguint;
extern string ErrorMessage[];
extern lguint \
_mod,\
_stack,\
_state,\
_std,\
_t13_base,\
_time_limit,\
_txx_cost,\
_txx_oper;
string deal(string s);
vector<string> split(string s,char sign);
lguint SelectedStack(string s);
lguint s_to_i64(string s);
lguint FastPow(lguint a,lguint b,lguint p);//a^b%p,a<p
