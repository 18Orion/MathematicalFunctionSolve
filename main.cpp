#include <iostream>
#include "include/funcion.hpp"

using namespace std;

int main(){
    double x;
    string func;
    cout<<"X: ";
    cin>>x;
    cout<<"Función: ";
    cin>>func;
    funcion *fn=new funcion();
    fn->prepare(func);
    cout<<fn->solve(x);
    delete fn;
    return 0;
}