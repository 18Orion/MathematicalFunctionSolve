#include <iostream>
#include <vector>
#include <cmath> 

using namespace std;

class funcion{
    private:
        vector<string> fnVector;
    public:
        funcion();
            ~funcion();
        double solve(double x);
        double solve2(double x);
        void prepare(string funcion);
        void showFunction();
};