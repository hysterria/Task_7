#ifndef MONOM_H
#define MONOM_H

#include <iostream>
using namespace std;

class Monom
{
public:
    Monom(int coef = 0, int degree = 0);

    friend ostream& operator << (ostream& os, Monom a)
    {
        if (a.GetDegree() == 0)    os << a.GetCoef();
        else
        {
            if (abs(a.GetCoef()) == 1)
            {
                if (a.GetCoef() < 0)    os << "-";
            }

            else    os << a.GetCoef();

            os << "x";

            if (a.GetDegree() == 1)    return os;

            if (a.GetDegree() > 1)
                os << "^" << a.GetDegree();
        }
        return os;
    }

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

#endif // MONOM_H
