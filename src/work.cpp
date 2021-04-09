#include "work.h"
void incode(string name){
    ifstream fin;
    fin.open(name,std::ios::in);
    if(!fin.is_open()){
        cerr<<name<<".lgpp : ";
    }
}
