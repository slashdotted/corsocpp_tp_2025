#include <iostream>
struct BaseA
{
    int a;
};
struct BaseB
{
    int b;
};

struct Derived : BaseA, BaseB
{};

int main()
{
    Derived d;
    BaseB *b_cstyle = (BaseB *) (&d);                     // Readjust the pointer
    BaseB *b_reinterpret = reinterpret_cast<BaseB *>(&d); // Does not adjust the pointer
    std::cout << "&d=" << &d << '\n';
    std::cout << "b_cstyle=" << b_cstyle << '\n';
    std::cout << "b_reinterpret=" << b_reinterpret << '\n';
}
