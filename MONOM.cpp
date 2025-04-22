#include "MONOM.h"
#include <iostream>
using namespace std;

Monom::Monom(int coef, int degree)
{
    Coef = coef;
    Degree = degree;
}

void Monom::SetCoef(int coef)
{
    Coef = coef;
}

int Monom::GetCoef()
{
    return Coef;
}

void Monom::SetDegree(int degree)
{
    Degree = degree;
}

int Monom::GetDegree()
{
    return Degree;
}

Monom Monom::operator * (int n)
{
    Monom result;
    result.SetCoef(Coef * n);
    result.SetDegree(Degree);
    return result;
}

Monom Monom::operator * (Monom M)
{
    Monom result;
    result.SetCoef(Coef * M.GetCoef());
    result.SetDegree(Degree + M.GetDegree());
    return result;
}

ostream& operator << (ostream& os, Monom a)
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
