#include "base.h"
#include <queue>
#include <algorithm>
using std::queue;
using std::sort;
extern luogu_stack Three[3];
extern uint32_t state_num,default_state;
extern vector<order>orders;
order copy_state();
bool initall(queue<string>s);
bool excute();
