#include <iostream>

struct Computer
{
    unsigned long fact(unsigned long n) const
    {
        // If fact(n) has already been computed,
        // simply return the previous result
        unsigned long r = 1;
        for (unsigned long i = n; i > 1; --i) {
            r = r * i;
        }
        return r;
    }
};

void foo(const Computer &c, unsigned long v)
{
    std::cout << "Factorial of " << v << ": " << c.fact(v) << std::endl;
}
int main()
{
    Computer c;
    foo(c, 15);
    foo(c, 12);
    foo(c, 15);
}
