#include"CalculNumerique.hpp"

CalculNumerique::CalculNumerique()
{
    this->parser.DefineVar("x", &this->x);
}

CalculNumerique::~CalculNumerique()
{
}

void CalculNumerique::setIntervalle()
{
    int a;
    int b;
    cout << "Entrer l'intervalle a et b : ";
    cin >> a >> b;
    cin.ignore();
    this->inter_a = a;
    this->inter_b = b;
}

void CalculNumerique::setFunction()
{
    string func;
    cout << "Entrer la fonction a etudier : ";
    getline(cin, func);
    this->func = func;
    this->parser.SetExpr(func);
}

double CalculNumerique::evaluateFunction(double x)
{
    this->x = x;
    return this->parser.Eval();
}

void CalculNumerique::dichotomie(double eps, int maxIter)
{
    double a = this->inter_a;
    double b = this->inter_b;
    double fa, fb, milieu, fmilieu;
    
    fa = evaluateFunction(a);
    fb = evaluateFunction(b);
    
    if (fa * fb > 0) 
    {
        cout << "Erreur : f(a) et f(b) doivent avoir des signes opposes." << endl;
        cout << "  f(" << a << ") = " << fa << endl;
        cout << "  f(" << b << ") = " << fb << endl;
        return;
    }

    cout << "\n--- Methode de Dichotomie ---" << endl;

    int iteration = 0;

    while ((b - a) / 2.0 > eps && iteration < maxIter)
    {
        milieu  = (a + b) / 2.0;
        fmilieu = evaluateFunction(milieu);

        if (fabs(fmilieu) < eps) 
        {
            break; 
        }

        if (fa * fmilieu < 0) 
        {
            b  = milieu;
            fb = fmilieu;
        } 
        else 
        {
            a  = milieu;
            fa = fmilieu;
        }

        iteration++;
    }

    double racine = (a + b) / 2.0;
    cout << "\nRacine approximative : x = " << racine << endl;
    cout << "Nombre d'iterations : " << iteration << endl;
}
