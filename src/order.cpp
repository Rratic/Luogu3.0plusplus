#include "order.h"
unsigned short order::order_pattern_num=53;
order_pattern order::basic[]={
/*
true=字母
false=数字
{"",,{,,,}},
*/

//std=1
{"pus",3,{1,0,0}},{"pop",2,{1,0}},
{"mov",3,{1,1,0}},{"cpy",3,{1,1,0}},
{"add",4,{1,1,1,0}},{"sub",4,{1,1,1,0}},
{"mul",4,{1,1,1,0}},{"div",4,{1,1,1,0}},
{"mod",4,{1,1,1,0}},{"emp",3,{1,0,0}},
{"cmp",4,{1,1,0,0}},{"ter",0},
{"t00",2,{1,0}},{"t01",2,{1,0}},
{"t02",2,{1,0}},{"t03",2,{1,0}},
{"t04",2,{1,0}},{"t05",2,{1,0}},
{"t06",3,{1,1,0}},{"t07",3,{1,1,0}},
{"t08",3,{1,1,0}},{"t09",3,{1,1,0}},
{"t10",3,{1,1,0}},{"t11",3,{1,1,0}},
{"t12",3,{1,1,0}},{"t13",2,{1,0}},
{"t14",3,{1,1,0}},{"t15",3,{1,1,0}},
{"t16",3,{1,1,0}},{"t17",3,{1,1,0}},
{"t18",3,{1,1,0}},{"t19",4,{1,1,1,0}},
{"t20",4,{1,1,1,0}},{"t21",4,{1,1,1,0}},
//std=2
{"pow",4,{1,1,1,0}},{"sqrt",3,{1,1,0}},
{"and",4,{1,1,1,0}},{"or",4,{1,1,1,0}},
{"xor",4,{1,1,1,0}},{"lsh",4,{1,1,1,0}},
{"rsh",4,{1,1,1,0}},{"addi",4,{1,1,0,0}},
{"subi",4,{1,1,0,0}},{"muli",4,{1,1,0,0}},
{"divi",4,{1,1,0,0}},{"modi",4,{1,1,0,0}},
{"getchar",2,{1,0}},{"getline",2,{1,0}},
{"getstring",2,{1,0}},{"putchar",2,{1,0}},
{"putnum",2,{1,0}},{"print",2,{1,0}},
{"println",2,{1,0}},
};
unsigned short order::search_basic(string ordername){
    for(unsigned short i=0;i<order_pattern_num;i++){
        if(basic[i].name==ordername)return i;
    }
    return 65535;
}
bool order::load(string s){
    vector<string>t=split(s,' ');
    name=search_basic(deal(t.at(0)));
    if(name==65535)throw UNKNOWN_ORDER;
    if(_std==1&&name>=34)throw STD_UNSUPPORTTED;//不支持
    if(t.size()<=basic[name].typen)throw FORMAT_ERROR;
    for(uint8_t i=1;i<=basic[name].typen;i++){
        if(basic[name].type[i-1])args[i-1]=SelectedStack(t[i]);
        else args[i-1]=s_to_i64(t[i]);
    }
    return true;
}
