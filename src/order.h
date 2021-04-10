#include "lgstack.h"
class order_pattern{
    public:
    string name;
    unsigned short typen;
    bool type[4];
};
class order{
    public:
    static order_pattern basic[];
    static unsigned short order_pattern_num;
    unsigned short name;
    lguint args[4];
    unsigned short search_basic(string ordername);
    bool load(string s);
};
