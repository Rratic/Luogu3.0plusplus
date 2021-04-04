#include "work.h"
int main(int argc,char *argv[]){
    if(argc==2){
        string s1=argv[1];
        try{
        getfromfile(s1+".lgpp");
        initstackfromfile(s1+".in");
        }
        catch(LgErrorType i){
            if(i==FILE_ERROR)cout<<"Unable to find file.";
            if(i==FORMAT_ERROR)cout<<"Incorrect format.";
            exit(0);
        }
    }
    lgwork();
    return 0;
}
