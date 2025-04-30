#include <iostream>

struct Base
{
    virtual void foo() {}
};

struct ReBase : public Base
{
    void foo() final override {}
};

struct Derived final : public ReBase
{
    //void foo() override {}
};

// Errore: Derived è final
/*struct DoubleDerived : public Derived {
};*/

int main() {
    std::cout << "Hello world\n";
}
