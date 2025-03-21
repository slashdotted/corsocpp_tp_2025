#include <iostream>
#include "fraction.h"
#include <map>

void dothings(const Fraction& f) {

    f.print();
    //f.numerator(7);
    //f.denominator(3);
    f.print();
}

void foo(Fraction f) {
}

struct Memory {
    // Conversion / Converting constructor
    explicit Memory(int x) {}
};

void bar(Memory m) {
}

struct Baz {
    Baz(int) {}
    Baz() = default; //{}
};

int main()
{
    {
    bar(Memory{100});
    //bar(100);
    Fraction f1{2,3};
    Fraction f2;
    f2.print();
    f1 = f2;
    int x{7};
    int y{9};
    x = y;
    std::string hello{"hello world"};
    //x = hello;
    f2 = Fraction{42};
    foo(f2);
    foo(77);
    f2 = 77;

    //Fraction f3{7};
    //f1.numerator(2);
    //f1.denominator(3);
    //dothings(f1);
    }
    std::map<std::string,Baz> m;
    std::cout << "Size of m: " << m.size() << '\n';
    m["hello"];
    std::cout << "Size of m: " << m.size() << '\n';
}
