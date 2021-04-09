#include "work.h"
int main(int argc,char *argv[]){
    try{
        for(int i=1;i<argc;i++){
            string s=argv[i];
            if(s=="")continue;
        }
    }
    catch(LgErrorType i){
        exit(-1);
    }
    return 0;
}