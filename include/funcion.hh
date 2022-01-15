#include <iostream>
#include <vector>
#include <cmath> 
#include "cuda_runtime.h"

using namespace std;

class funcion{
    private:
        vector<string> fnVector;
        bool isSum(string symbol);
        bool isMult(string symbol);
    public:
        funcion();
            ~funcion();
        double solve(double x);         //Resuelve la función y devuelve el valor numérico
        __global__ double gpuSolve(double x);         //Resuelve la función y devuelve el valor numérico
        void prepare(string funcion);   //Prepara la función para ser resuelta
        void showFunction();            //Muestra la función
};