#include "POLYNOM.h"
#include <iostream>

using namespace std;

void Polynom::PushMonom (Monom M)
{
    Mnogoclen.push_back(M);
}


Polynom Polynom::Privedenie()
{
    Polynom P = *this;
    if (P.Mnogoclen.empty())    return P;

    // Сортируем по убыванию степеней
    sort (P.Mnogoclen.begin(), P.Mnogoclen.end(), [](Monom a, Monom b)
    {
        return a.GetDegree() > b.GetDegree();
    });

    //Сливаем рядом стоящие мономы с одинаковой степенью
    vector<Monom>::iterator it = P.Mnogoclen.begin();
    while (it != P.Mnogoclen.end())
    {
        while (((*(it+1)).GetDegree() == (*it).GetDegree()) && (it + 1 != P.Mnogoclen.end()))
        {
            (*it).SetCoef((*it).GetCoef() + (*(it+1)).GetCoef());
            P.Mnogoclen.erase(it + 1);
        }
        it++;
    }

    // Удаляем нулевые коэффициенты
    it = P.Mnogoclen.begin();
    while (it != P.Mnogoclen.end())
    {
        if ((*it).GetCoef() == 0)    it = P.Mnogoclen.erase(it);
        else    it++;
    }
    return P;
}


Polynom Polynom::operator + (Polynom P)
{
    Polynom R = *this;
    for (vector<Monom>::iterator it = P.Mnogoclen.begin(); it != P.Mnogoclen.end(); it++)
    {
        R.PushMonom(*it);
    }
    return R.Privedenie();
}


Polynom Polynom::operator - (Polynom P)
{
    return *this + (P * (-1));
}


Polynom Polynom::operator * (Monom M)
{
    Polynom Q;
    for (Monom N : Mnogoclen)    Q.PushMonom(N * M);
    return Q;
}

Polynom Polynom::operator * (Polynom P)
{
    Polynom R;
    for (Monom m : Mnogoclen)    R = R + P * m;
    return R;
}


Polynom Polynom::operator * (int n)
{
    Monom N (n, 0);
    return *this * N;
}


Polynom Chebyshev (int n)
{
    if (n == 0)
    {
        Monom m1(1, 0);
        Polynom T0 ({m1});
        return T0;
    }

    else if (n == 1)
    {
        Monom m2(1, 1);
        Polynom T1 ({m2});
        return T1;
    }

    Polynom Tn_2 = Chebyshev(n - 2);
    Polynom Tn_1 = Chebyshev(n - 1);
    Monom x(1, 1);
    Polynom Tn = Tn_1 * x * 2 - Tn_2;

    return Tn.Privedenie();
}
