#include <iostream>
#include "fraction.h"

Fraction operator+(const Fraction &g, const Fraction &f)
{
    auto z{f};
    z += g;
    return z;
}

/*
// overload the prefix operator ++f
Fraction& operator++(Fraction& f) {
    // return the alredy incremented value
    return f += 1;
}

// overload the postfix operator f++
Fraction operator++(Fraction& f, int) {
    Fraction temp{f};
    f += 1;
    return temp; 
}
*/

void doSomething(double d) {}

int main()
{
    Fraction f;
    f = 6;

    Fraction g;
    //f.increaseBy(g);
    f += g; // f.operator+=(g)
    f + g; // f.operator+(g)
    g + f; // g.operator+(f)
    //f + 8; // f.operator+(8) -> f.operator+(Fraction(8))
    //8 + f; // operator+(Fraction(8),f)

    auto z = f;
    z += g;


    int x{9};
    x = x + 2;
    x += 2;

    doSomething(f);
}
