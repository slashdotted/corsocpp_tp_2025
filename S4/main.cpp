#include <iostream>
#include "fraction.h"

void dothings(const Fraction& f) {
    //f.numerator(2);
    //f.denominator(3);
    f.print();
    //f.numerator(7);
    //f.denominator(3);
    f.print();
}

int main()
{
    Fraction f1;
    dothings(f1);

}
