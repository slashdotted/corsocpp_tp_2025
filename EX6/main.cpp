#include <iostream>

// ***************************************************************
class MultiplyBy
{
public:
    MultiplyBy(int factor)
        : factor_(factor)
    {}
    int operator()(int value) const { return value * factor_; }

private:
    int factor_;
};

void ex6_1()
{
    //MultiplyBy two{2};
    // Variante A
    auto two = [factor_ = 2](int value) { return value * factor_; };
    // Variante B (meno precisa)
    int f{2};
    auto two_b = [f](int value) { return value * f; };

    std::cout << two(4);
}
// ***************************************************************
class AddTo
{
public:
    AddTo(int &increment)
        : increment_(increment)
    {}
    int operator()(int value) const { return value + increment_; }

private:
    int &increment_;
};

void ex6_2()
{
    int i{4};
    //AddTo addToI{i};
    auto addToI = [&i](int value) { return value + i; };
    // Catturando per riferimento posso cambiare il valore (senza usare mutable)
    auto addToIb = [&i](int value) { return value + i++; };
    std::cout << addToI(4) << '\n';
    i = 7;
    std::cout << addToI(4) << '\n';
}
// ***************************************************************
class Accumulate
{
public:
    Accumulate(int start)
        : start_(start)
    {}
    int operator()(int value) { return start_ += value; }

private:
    int start_;
};

void ex6_3()
{
    //Accumulate a{0};
    auto a = [start_ = 0](int value) mutable { return start_ += value; };
    std::cout << a(2) << '\n';
    std::cout << a(3) << '\n';
}
// ***************************************************************
int main() {
    ex6_1();
    ex6_2();
    ex6_3();
}
