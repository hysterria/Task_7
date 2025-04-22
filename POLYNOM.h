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


    void PushMonom (Monom M);
    Polynom operator + (Polynom P);
    Polynom operator - (Polynom P);
    Polynom operator * (Monom M);
    Polynom operator * (Polynom P);
    Polynom operator * (int n);
    Polynom Privedenie();
};

Polynom Chebyshev(int n);
ostream& operator << (ostream& os, Polynom P);
#endif // POLYNOM_H_INCLUDED
