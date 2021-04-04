#include "work.h"
int main(int argc,char *argv[]){
    string s1;
    if(argc==2){
        s1=argv[1];
        try{
            initall(getfromfile(s1+".lgpp"));
            initstackfromfile(s1+".in");
            lgwork(s1+".out");
        }
        catch(LgErrorType i){
            if(i==FILE_ERROR)cout<<"Failed to open file:"<<public_message;
            if(i==FORMAT_ERROR)cout<<"Incorrect format.";
            exit(0);
        }
    }
    else cout<<"Format: luogu++ fileplace";
    return 0;
}
