#ifndef POLYNOM_H_INCLUDED
#define POLYNOM_H_INCLUDED

#include "MONOM.h"
#include <vector>
#include <algorithm>

using namespace std;

class Polynom
{
public:

    vector<Monom> Mnogoclen;

    Polynom () : Mnogoclen{} {};

    Polynom (vector<Monom> vect)
    {
        Mnogoclen = vect;
    }

    friend ostream& operator << (ostream& os, Polynom P)
    {
        vector<Monom> vect = P.Mnogoclen;
        os << (*vect.begin());

        if (vect.begin() == vect.end())    return os;

        for (vector<Monom>::iterator it = vect.begin() + 1; it != vect.end(); it++)
        {
            os << " ";
            if ((*it).GetCoef() > 0)    os << "+";
            else    os << "-";

            os << " ";
            if ((*it).GetDegree() == 0)    os << abs((*it).GetCoef());
            else
            {
                if (abs((*it).GetCoef()) != 1)    os << abs((*it).GetCoef());
                os << "x";
                if ((*it).GetDegree() >= 2)    os << "^" << (*it).GetDegree();
            }
        }
        return os;
    }

    void PushMonom (Monom M);
    Polynom operator + (Polynom P);
    Polynom operator - (Polynom P);
    Polynom operator * (Monom M);
    Polynom operator * (Polynom P);
    Polynom operator * (int n);
    Polynom Privedenie();
};

Polynom Chebyshev(int n);

#endif // POLYNOM_H_INCLUDED
