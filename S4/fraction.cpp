#include "fraction.h"
#include <iostream>

using std::cout;
using std::endl;

Fraction::Fraction(int numerator, int denominator)
    : n{numerator},d{denominator}
{
    //n = numerator;
    //d = denominator;
}

/*Fraction::Fraction()
{
    n = 0;
    d = 1;
}

Fraction::Fraction(int numerator)
{
    n = numerator;
}*/

int Fraction::numerator() const {
    return n;
}

void Fraction::numerator(int v) {
    n = v;
}

int Fraction::denominator() const
{
    return d;
}

void Fraction::denominator(int v)
{
    d = v;
}

/*void Fraction::print() {
    cout << this->n << "/" << this->d << endl;
}*/
