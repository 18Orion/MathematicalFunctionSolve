#include <iostream>
#include "include/funcion.hh"
#include <ctime> 

using namespace std;

int main(){
    double x,a,time2,time;
    unsigned t0, t1;
    string func;
    cout<<"X: ";
    cin>>x;
    cout<<"Función: ";
    cin>>func;
    funcion *fn=new funcion();
    fn->prepare(func);
    t0=clock();
    a=fn->solve(x);
    t1 = clock();
    cout<<a;
    delete fn;
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout <<endl<<"Tiempo de ejcución de funcion input: "<<time<<endl;
    t0=clock();
    a=5*5+5;
    t1 = clock();
    cout<<a;
    time2 = (double(t1-t0)/CLOCKS_PER_SEC);
    cout <<endl<<"Tiempo de ejcución de funcion compilada: "<<time2<<endl;
    cout<<(time-time2);
    return 0;
}
