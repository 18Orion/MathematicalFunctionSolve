#include <iostream>
#include <vector>
#include <cmath> 

using namespace std;

class funcion{
    private:
        vector<string> fnVector;
        bool hasMult=false;
        bool hasPower=false;
        bool isSum(string symbol);
        bool isMult(string symbol);
    public:
        funcion();
            ~funcion();
        double solve(double x);         //Resuelve la función y devuelve el valor numérico
        void prepare(string funcion);   //Prepara la función para ser resuelta
        string returnFunction();            //Muestra la función
};