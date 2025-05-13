#include <iostream>

// Hint: draw a class diagram when you review this example

struct Foo
{};

struct Bar : public virtual Foo
{};

struct Baz : public Bar
{};

struct Paz : public Bar
{};

struct Raz : public Baz, public Paz
{};

struct Biz
{};

int main() {
    Foo foo;
    Bar bar;
    Baz baz;
    Paz paz;
    Raz raz;
    Biz biz;

    {
        // static_cast will not allow crossing to another "brach" branch of the hierarchy
        //Baz *x{static_cast<Baz *>(&paz)}; // <--- Invalid cast
        // ...even when this is legit
        Baz *y{static_cast<Baz *>(&raz)};
        // Paz *z{static_cast<Paz *>(y)};// <--- Invalid cast
    }

    // *******************************
    // Upcasting
    // *******************************

    {
        // Static cast can convert values (types)
        Bar x{static_cast<Bar>(baz)};
        // ...and recognize (some) invalid casts
        // Biz y{static_cast<Biz>(baz)}; // <--- Invalid cast
    }

    {
        // We can also cast pointers
        Bar *x{static_cast<Bar *>(&baz)};
        // Or references
        Bar &y{static_cast<Bar &>(baz)};
    }
    {
        // Static cast CANNOT remove const
        const Baz cbaz;
        // Baz *x{static_cast<Baz *>(&cbaz)}; // <--- Invalid cast
    }
    {
        // When upcasting static_cast can cross virtual inheritance
        Foo *x{static_cast<Foo *>(&baz)};
    }

    // *******************************
    // Downcasting
    // *******************************

    {
        // Static cast on downcasting cannot "recover" the missing pieces
        // Bar x{static_cast<Bar>(foo)}; // <--- Invalid cast (cannot get a Bar object out of a Foo object)
    }
    {
        Bar *x{static_cast<Bar *>(&baz)};
        // We can also downcast pointers
        Baz *y{static_cast<Baz *>(x)};
        // Or references
        Baz &z{static_cast<Baz &>(*x)};
    }
    {
        // When downcasting static_cast cannot cross virtual inheritance
        Foo *x{static_cast<Foo *>(&baz)};
        //Baz *y{static_cast<Baz *>(x)}; // <--- Invalid cast
    }
    {
        Bar *x{static_cast<Bar *>(&baz)};
        // static cast can make mistakes, both on pointers
        Paz *y{static_cast<Paz *>(x)}; // Error! x is a really a pointer to a Baz object
        // The same happens with references
        Paz &z{static_cast<Paz &>(*x)}; // Error! x is a really a pointer to a Baz object
    }
}
