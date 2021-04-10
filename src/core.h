#include "order.h"
#include <fstream>
#include <iostream>
#include <queue>
using std::ifstream;
using std::ofstream;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::getchar;
using std::getline;
using std::queue;
extern LgStack Three[3];
extern lguint state_num,default_state;
extern vector<order>orders;
bool excute_line(lguint &timer);//位置用default_state存
