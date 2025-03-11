#include <iostream>
#include "fraction.h"

void dothings(const Fraction& f) {

    f.print();
    //f.numerator(7);
    //f.denominator(3);
    f.print();
}

int main()
{
    Fraction f1{2,3};
    Fraction f2;
    Fraction f3{7};
    //f1.numerator(2);
    //f1.denominator(3);
    dothings(f1);

}
