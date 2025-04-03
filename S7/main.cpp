#include "meeple.h"
#include <iostream>

int Meeple::meeple_counter{0};

struct MeepleTown
{
    MeepleTown()
        : a{new Meeple{"Paul"}}
        , b{new Meeple{"Barbara"}}
    {}

    // Copy-constructor
    MeepleTown(const MeepleTown &o)
        : a{new Meeple{o.a->name()}} // costruisco esplicitamente una copia
        , b{new Meeple{*o.a}}        // uso il costruttore di copia implicito di Meeple
    {}

    ~MeepleTown()
    {
        delete a;
        delete b;
    }

    // operatore di assegnamento di copia
    MeepleTown &operator=(const MeepleTown &o)
    {
        *a = *o.a;
        *b = *o.b;
        return *this;
    }

    Meeple *a;
    Meeple *b;
};

void foo(MeepleTown x)
{
    std::cout << "(in Foo) Meeples:" << Meeple::counter() << '\n';
}

void foo(Meeple x)
{
    std::cout << "(in Foo) Meeples:" << Meeple::counter() << '\n';
}

struct B
{
    B() = default;
    B(const B &o) { std::cout << "Costruttore di copia di B\n"; }
};

struct A
{
    A() = default;
    //A(const A &o) { std::cout << "Costruttore di copia di A\n"; }

    B m_b;
};

void foo(A a) {}

int main()
{
    /*A a;
    foo(a);
    return 0;*/

    {
        std::cout << "Meeples:" << Meeple::counter() << std::endl;
        MeepleTown m;
        MeepleTown n;
        foo(m);
        n = m;
        std::cout << "Meeples:" << Meeple::counter() << std::endl;
    }
    std::cout << "Meeples:" << Meeple::counter() << std::endl;

    std::cout << "Meeples:" << Meeple::counter() << '\n';
    Meeple j{"John"};
    std::cout << "Meeples:" << Meeple::counter() << '\n';
    {
        Meeple m{"Mark"};
        std::cout << "Meeples:" << Meeple::counter() << '\n';
    }
    std::cout << "Meeples:" << Meeple::counter() << '\n';
    Meeple a{"Alan"};
    Meeple *p = new Meeple{"Paul"};
    //meeple_counter = 100;
    std::cout << "(80) Meeples:" << Meeple::counter() << '\n';
    // 3 meeples in total
    delete p;
    std::cout << "(83) Meeples:" << Meeple::counter() << '\n';
    // 2 meeples in total
    foo(a);
    std::cout << "(86) Meeples:" << Meeple::counter() << '\n';
}
