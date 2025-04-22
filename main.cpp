#include "POLYNOM.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Formules of multiplying:\n";
    Monom x(1, 1);
    Monom b(1, 0);
    Monom x2(1, 2);
    Polynom Polynom1 ({x, b});
    Polynom Polynom2 ({x, b*(-1)});
    Polynom Polynom3 ({x2, x, b});
    Polynom Polynom4 ({x2, x*(-1), b});
    cout << "(" << Polynom1 << ") * (" << Polynom2 << ") = " << Polynom1 * Polynom2 << "\n";
    cout << "(" << Polynom1 << ") * (" << Polynom4 << ") = " << Polynom1 * Polynom4 << "\n";
    cout << "(" << Polynom2 << ") * (" << Polynom3 << ") = " << Polynom2 * Polynom3 << "\n";

    cout << "Enter degree k for Chebyshev polynomial T_k(x): ";
    int k;
    cin >> k;
    cout << "Chebyshev polynomial T_" << k << "(x): ";
    cout << Chebyshev(k);

    return 0;
}
