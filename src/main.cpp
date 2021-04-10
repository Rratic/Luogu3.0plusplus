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
                    if(t[0]=="--mod")_mod=j;
                    else if(t[0]=="--stack")_stack=j;
                    else if(t[0]=="--state")_state=j;
                    else if(t[0]=="--std")_std=j;
                    else if(t[0]=="--t13-base")_t13_base=j;
                    else if(t[0]=="--time-limit")_time_limit=j;
                    else if(t[0]=="--txx-cost")_txx_cost=j;
                    else if(t[0]=="--txx-oper")_txx_oper=j;
                }
                else{
                    if(s=="(-disable-in")trace_in=false;
                    else if(s=="-disable-out")trace_out=false;
                    else if(s=="-revin")revin=true;
                    else if(s=="-revout")revout=true;
                }
            }
            else filepl=s;
        }
        if(filepl==""){
            cerr<<"NO INPUT FILE : ";
            throw FORMAT_ERROR;
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
