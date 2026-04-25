#include<iostream>
#include<cmath>
#include<muParser.h>
#include<string>

using namespace std;
using namespace mu;

class CalculNumerique
{
    private:
        int inter_a;
        int inter_b;
        string func;
        Parser parser;
        double x;
    public:
        CalculNumerique();
        ~CalculNumerique();
        void setIntervalle();
        void setFunction();
        double evaluateFunction(double x);
        void dichotomie(double eps, int maxIter);
};
