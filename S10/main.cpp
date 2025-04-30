#include <iostream>

// Overloading
void foo() {}
void foo(int i) {}

struct Esempio
{
    void bar() {}

    void bar(int i) {}

    void bar() const {}
};

// Override
struct A
{
    virtual void process() {}
};

struct B : public A
{
    void process() override {}
};

// Hiding
struct Base
{
    void write(double v) { std::cout << "Double:" << v << '\n'; }

    virtual ~Base() { std::cout << "Sto distruggendo Base\n"; }
};

struct Derived : public Base
{
    //void write(double v) { Base::write(v); }

    using Base::write;

    void write(int v) { std::cout << "Int:" << v << '\n'; }

    ~Derived() { std::cout << "Sto distruggendo Derived\n"; }
};

void distruggi(Base *b)
{
    delete b;
}

void distruggi(Base &b)
{
    delete &b;
}

int main()
{
    {
        Base b;
        b.write(3.14);
        b.write(10);
        Derived d;
        //d.Base::write(3.14);
        d.write(3.14);
        d.write(10);
    }
    std::cout << "------------------------\n";
    Derived *p{new Derived};
    distruggi(p);
}
