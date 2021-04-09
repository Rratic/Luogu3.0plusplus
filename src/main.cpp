#include "work.h"
int main(int argc,char *argv[]){
    bool trace_in=true,revin=false,revout=false,trace_out=true;
    string filepl;
    try{
        for(int i=1;i<argc;i++){
            string s=argv[i];
            if(s=="")continue;
            if(s[0]=='-'){
                s=deal(s);
                if(s=="-")throw FORMAT_ERROR;
                if(s[1]=='-'){
                    auto t=split(s,' ');
                    lguint j=s_to_i64(t.at(1));
                    if(j==0||(j>>31)!=0){
                        cerr<<"Out of range "<<j<<": ";
                        throw FORMAT_ERROR;
                    }
                }
            }
            else filepl=s;
        }
        incode(filepl+".lgpp");
        if(trace_in)instack(filepl+".in",revin);
        excute();
        if(trace_out)outstack(filepl+".out",revout);
    }
    catch(out_of_range){
        cerr<<"FATAL FORMAT ERROR";
    }
    catch(LgErrorType i){
        cerr<<"["<<ErrorMessage[i]<<"]";
        exit(-1);
    }
    return 0;
}
