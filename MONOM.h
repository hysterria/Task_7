#ifndef MONOM_H
#define MONOM_H

#include <iostream>
using namespace std;

class Monom
{
public:
    Monom(int coef = 0, int degree = 0);

    void SetCoef(int coef);
    int GetCoef();
    void SetDegree(int degree);
    int GetDegree();

    Monom operator * (int n);
    Monom operator * (Monom M);

private:
    int Coef;
    int Degree;
};
ostream& operator << (ostream& os, Monom a);

#endif // MONOM_H
