#include "fraction.h"
#include <iostream>

using std::cout;
using std::endl;

Fraction::Fraction() : Fraction{0,1} /*n{5}*/ {
    //Fraction{0,1};
}

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

//void Fraction::increaseBy(const Fraction &f)
Fraction& Fraction::operator+=(const Fraction& f)
{
    d = d * f.d;
    n = n * f.d;
    n = n + (f.n * d);
    return *this;
}

/*Fraction Fraction::operator+(const Fraction &f)
{
    auto z{f};
    z += *this;
    return z;
}*/

/*void Fraction::print() {
    cout << this->n << "/" << this->d << endl;
}*/
