#include <iostream>
#include <map>

struct Computer
{
    unsigned long fact(unsigned long n) const
    {
        if (cache.count(n)) {
            return cache.at(n);
        }
        // If fact(n) has already been computed,
        // simply return the previous result
        unsigned long r = 1;
        for (unsigned long i = n; i > 1; --i) {
            r = r * i;
        }
        //Computer* ncthis{const_cast<Computer*>(this)};
        //ncthis->cache[n] = r;
        auto &nccache{const_cast<std::map<unsigned long, unsigned long> &>(cache)};
        nccache[n] = r;

        return r;
    }

private:
    std::map<unsigned long, unsigned long> cache;
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
