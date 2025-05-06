#include <iostream>

namespace bar {
struct Alpha
{
    operator double() const { return value; }

    void set(double v = 0)
    {
        std::cout << "set double: value " << v << std::endl;
        value = v;
    }

    virtual ~Alpha() { std::cout << "Alpha : destruction" << std::endl; }

protected:
    double value{-1};
};

struct Beta : public Alpha
{
    using Alpha::set;

    void set(int v)
    {
        std::cout << "set int: value " << v << std::endl;
        value = v;
    }

    ~Beta() { std::cout << "Beta : destruction" << std::endl; }
};
} // namespace bar

int main(int argc, char *argv[])
{
    using std::cout, std::endl;
    cout << "************* Start **************" << endl;
    bar::Alpha ak;
    double v1 = ak;
    cout << "v1 = "<< v1 << endl;
    ak.set(4.5);
    cout << "ak = " << (double) ak << endl;
    ak.set(4);
    cout << "ak = " << (double) ak << endl;
    ak.set();
    cout << "ak = " << (double) ak << endl;
    bar::Beta bk;
    double v2 = bk;
    cout << "v2 = "<< v2 << endl;
    bk.set(4.5);
    cout << "bk = " << (double) bk << endl;
    bk.set(4);
    cout << "bk = " << (double) bk << endl;
    bk.set();
    cout << "bk = " << (double) bk << endl;
    bar::Alpha* ptr2{new bar::Beta};
    delete ptr2;
    cout << "************* End **************" << endl;
}
