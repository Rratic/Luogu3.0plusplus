#include "work.h"
int main(int argc,char *argv[]){
    if(argc==2){
        string s1=argv[1];
        getfromfile(s1+".lgpp");
        initstackfromfile(s1+".in");
    }
    lgwork();
    return 0;
}
