#include <iostream>
#include "fraction.h"

Fraction operator+(const Fraction &g, const Fraction &f)
{
    auto z{f};
    z += g;
    return z;
}

int main()
{
    Fraction f;
    f = 6;

    Fraction g;
    //f.increaseBy(g);
    f += g; // f.operator+=(g)
    f + g; // f.operator+(g)
    g + f; // g.operator+(f)
    f + 8; // f.operator+(8) -> f.operator+(Fraction(8))
    8 + f; // operator+(Fraction(8),f)

    auto z = f;
    z += g;


    int x{9};
    x = x + 2;
    x += 2;

}
