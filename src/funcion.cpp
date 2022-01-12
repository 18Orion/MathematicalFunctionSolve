#include "funcion.hh"

funcion::funcion(){
}

funcion::~funcion(){

}

void funcion::prepare(string funcion){
    string cache;
    for (int i = 0; i <= funcion.length(); i++) {
        if(isdigit(funcion[i])||funcion[i]=='.'||funcion[i]=='x'){
            if(funcion[i]=='x'){
                if(isdigit(funcion[i-1])||funcion[i]=='x'){
                    fnVector.push_back(cache);
                    cache="";
                    fnVector.push_back("*");
                }
                fnVector.push_back("x");
            }else{
                cache+=funcion[i];
            }
        }else{
            fnVector.push_back(cache);
            cache="";
            fnVector.push_back({funcion[i]});
        }
    }
}

void funcion::showFunction(){
    for (int i = 0; i < fnVector.size(); i++){
        cout<<fnVector[i]<<endl;
    }
}

double funcion::solve2(double x){
    double n1, n2, result;
    bool continueMultiplicating=false;
    vector<string> fn, fn2;
    for (int i = 0; i < fnVector.size(); i++) {
        if(fnVector[i]=="*"||fnVector[i]=="/"||fnVector[i]=="^"){
            if(fnVector.at(i-1)=="x"){
                n1=x;
            }else{
                n1=stod(fnVector[i-1]);
            }
            if(fnVector.at(i+1)=="x"){
                n2=x;
            }else{
                n2=stod(fnVector[i+1]);
            }
            if(fnVector[i]=="*"){
                fn.push_back(to_string(n1*n2));
            }
            if(fnVector[i]=="^"){
                fn.push_back(to_string(pow(n1, n2)));
            }
            if(fnVector[i]=="/"){
                fn.push_back(to_string(n1*n2));
            }
            i++;
        }else{
            if(fnVector[i]=="+"||fnVector[i]=="-"){
                fn.push_back(fnVector[i]);
            }else{
                if(i<fnVector.size()){
                    if(!(fnVector[i+1]=="*"||fnVector[i+1]=="/")){
                        fn.push_back(fnVector[i]);
                    }
                }
            }
        }
    }
    if(fn.size()==0){
        result=stod(fn[0]);
    }else{
        for (int i = 0; i < fn.size(); i++) {
            if(i==0&&(fn[i]!="+"||fn[i]!="-")){
                if(fn[i]=="x"){
                    n1=x;
                }else{
                    n1=stod(fn[i]);
                }
                result=result+n1;
            }
            if(fn[i-1]=="+"){
                if(fn[i]=="x"){n1=x;}else{n1=stod(fn[i]);}
                result=result+n1;
            }
            if(fn[i]=="-"){
                if(fn[i]=="x"){n1=x;}else{n1=stod(fn[i]);}
                result=result-n1;
            }
            
        }
    }
    return result;
}

double funcion::solve(double x){
    double n1, n2, result;
    bool continueMultiplicating=false;
    vector<string> fn, fn2;
    for (int i = 0; i < fnVector.size(); i++) {
        if(fnVector[i]!=""){
            if(fnVector[i]=="x"){
                fn.push_back(to_string(x));
            }else{
                fn.push_back(fnVector[i]);
            }
        }
    }
    for (int i = 0; i < fn.size(); i++) {
        if(fn[i]=="*"||fn[i]=="/"||fn[i]=="^"){
            n1=stod(fn[i-1]);
            n2=stod(fn[i+1]);
            if(fn[i]=="*"){
                result=(n1*n2);
            }
            if(fn[i]=="^"){
                result=pow(n1, n2);
            }
            if(fn[i]=="/"){
                result=(n1*n2);
            }
            fn2.push_back(to_string(result));
        }else{
            if(fn[i]=="+"||fn[i]=="-"){
                fn2.push_back(fn[i]);
            }else{
                if(i<fn.size()){
                    if(!(fn[i+1]=="*"||fn[i+1]=="/")){
                        fn2.push_back(fn[i]);
                    }
                }
            }
        }
    }
    if(fn2.size()==0){
        result=stod(fn2[0]);
    }else{
        for (int i = 0; i < fn2.size(); i++) {
            if(i==0&&(fn2[i]!="+"||fn2[i]!="-")){
                result=result+stod(fn2[i]);
            }
            if(fn2[i-1]=="+"){
                result=result+stod(fn2[i]);
            }
            if(fn2[i]=="-"){
                result=result-stod(fn2[i]);
            }
        }
    }
    return result;
}