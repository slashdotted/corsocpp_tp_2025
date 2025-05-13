#include <iostream>
#include <typeinfo>

// Hint: draw a class diagram when you review this example

struct Foo
{
    virtual ~Foo()
        = default; // dynamic_cast needs a polymorphic type, i.e. there must be at least a virtual method
};

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

int main()
{
    Foo foo;
    Bar bar;
    Baz baz;
    Paz paz;
    Raz raz;
    Biz biz;

    {
        // dyamic cast cannot convert values (types)
        // Bar x{dynamic_cast<Bar>(baz)}; // Invalid cast
    }
    {
        // dynamic_cast will return nullptr if the cast is invalid
        // Baz *x{dynamic_cast<Baz *>(&paz)}; // Invalid cast, returns nullptr
        Baz *y{dynamic_cast<Baz *>(&raz)};
        if (y) {
            std::cout << "Successfully cast Raz* to Baz*\n";
        } else {
            std::cout << "Failed to cast Raz* to Baz*\n";
        }

        Paz *z{dynamic_cast<Paz *>(y)};
        // This is really like instanceof
        // "y instanceof Paz"
        if (z) {
            std::cout << "Successfully cast Baz* to Paz*\n";
        } else {
            std::cout << "Failed to cast Baz* to Paz*\n";
        }
    }

    // *******************************
    // Upcasting
    // *******************************

    {
        Bar *x = dynamic_cast<Bar *>(&baz);
        if (x)
            std::cout << "Upcast Baz* to Bar* successful\n";

        Foo *f = dynamic_cast<Foo *>(&baz);
        if (f)
            std::cout << "Upcast Baz* to Foo* successful\n";
    }

    {
        const Baz cbaz;
        // dynamic_cast cannot remove const
        // Baz *x = dynamic_cast<Baz *>(&cbaz); // Invalid: discards const qualifier
    }

    // *******************************
    // Downcasting
    // *******************************

    {
        Foo *f = &baz;
        Bar *b = dynamic_cast<Bar *>(f);
        if (b)
            std::cout << "Downcast Foo* to Bar* successful\n";

        Baz *b2 = dynamic_cast<Baz *>(b);
        if (b2)
            std::cout << "Downcast Bar* to Baz* successful\n";
    }
    {
        // When downcasting dynamic_cast can cross virtual inheritance
        Foo *x{dynamic_cast<Foo *>(&baz)};
        Baz *y{dynamic_cast<Baz *>(x)};
    }
    {
        Bar *x = dynamic_cast<Bar *>(&baz);
        Paz *y = dynamic_cast<Paz *>(x); // Should fail
        if (!y)
            std::cout << "Invalid downcast Bar* to Paz* failed as expected\n";

        try {
            Paz &z = dynamic_cast<Paz &>(*x); // Throws std::bad_cast
        } catch (const std::bad_cast &e) {
            std::cout << "Caught bad_cast when casting Bar& to Paz&: " << e.what() << '\n';
        }
    }
}
