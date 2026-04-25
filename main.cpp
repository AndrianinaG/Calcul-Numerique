#include "CalculNumerique.hpp"

#define EPSILON 1e-6
#define MAX_ITER 1000

int main()
{
    CalculNumerique calcul;
    calcul.setIntervalle();
    calcul.setFunction();
    calcul.dichotomie(EPSILON, MAX_ITER);

    return 0;
}
