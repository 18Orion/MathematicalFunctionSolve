#include "funcion.hpp"

funcion::funcion(){

}

funcion::~funcion(){

}

void funcion::prepare(string funcion){
    string cache;
    /*Separa la funcion en un vector para su uso más facil*/
    for (int i = 0; i <= funcion.length(); i++) {
        if(isdigit(funcion[i])||funcion[i]=='.'||funcion[i]=='x'){
            if(funcion[i]=='x'){
                if(isdigit(funcion[i-1])){
                    fnVector.push_back(cache);
                    cache="";
                    fnVector.push_back("*");
                    hasMult=true;
                }
                fnVector.push_back("x");
            }else{
                cache+=funcion[i];
            }
        }else{
            if(cache!="") fnVector.push_back(cache);
            cache="";
            fnVector.push_back({funcion[i]});
            if(isMult({funcion[i]})) hasMult=true;
            if(funcion[i]=='^') hasPower=true;

        }
    }
}

string funcion::returnFunction(){
    string function;
    for (int i = 0; i < fnVector.size(); i++){
        function+=fnVector[i];
    }
    return function;
}

double funcion::solve(double x){
    double result=0;
    vector<string> fn;
    /*Substituye las variables de la ecuación copiandolas a un nuevo vector que va a
    ser modificado según se va resolviendo la función                               */
    for (int i = 0; i < fnVector.size(); i++) {
        if(fnVector[i]=="x"){
            fn.push_back(to_string(x));
        }else{
            fn.push_back(fnVector[i]);
        }
    }
    if(hasPower){
        for (int i = 0; i < fn.size(); i++) {           //Hace las potencias
            if(fn[i]=="^"){
                fn[i-1]=to_string(pow(stod(fn[i-1]), stod(fn[i+1])));
                fn.erase(fn.begin()+i+1);
                fn.erase(fn.begin()+i);
            }
        }
    }
    if(hasMult){
        for (int i = 1; i < fn.size(); i++) {           //Hace las multiplicaciones y divisiones
            if(fn[i]=="*"){
                fn[i-1]=to_string(stod(fn[i-1])*stod(fn[i+1]));
                fn.erase(fn.begin()+i+1);
                fn.erase(fn.begin()+i);
            }
            if(fn[i]=="/"){
                fn[i-1]=to_string(stod(fn[i-1])/stod(fn[i+1]));
                fn.erase(fn.begin()+i+1);
                fn.erase(fn.begin()+i);
            }
        }
    }
    for (int i = 0; i < fn.size(); i++) {           //Hace las sumas y restas
        if(i==0&&!isSum(fn[0])){
            result+=stod(fn[0]);
        }
        if(fn[i]=="+"){
            result+=stod(fn[i+1]);
        }
        if(fn[i]=="-"){
            result=result-stod(fn[i+1]);
        }
    }
    return result;
}

bool funcion::isSum(string symbol){
    //Comprueba si un símbolo es una suma o resta
    bool is=false;
    if(symbol[0]=='+'||symbol[0]=='-'){
        is=true;
    }
    return is;
}

bool funcion::isMult(string symbol){
    //Comprueba si un símbolo es una multiplicación o división o derivados
    bool is=false;
    if(symbol[0]=='*'||symbol[0]=='/'){
        is=true;
    }
    return is;
}