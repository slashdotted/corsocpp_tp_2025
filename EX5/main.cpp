#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class Convertitore {
    string Va;
    string Vb;
    double tx;
public:
    Convertitore(const string& V1, const string& V2, double tasso = 1.20)
        : Va{V1}, Vb{V2}, tx{tasso} {
    }

    double convert(double v) const {
        return v / tx;
    }

    double iconvert(double v) const {
        return v * tx;
    }

    void displayInfo() const
    {
        cout << Va << "\t"  << Vb << endl;
        cout << tx << "\t1" << endl;
    }

    //double operator<<(double v) const;
    double operator>>(double v) const { return iconvert(v); }

    friend ostream &operator<<(ostream &o, const Convertitore &c);
};

/*double Convertitore::operator<<(double v) const {
    return convert(v);
}*/
// oppure
double operator<<(const Convertitore &c, double v)
{
    return c.convert(v);
}

ostream &operator<<(ostream &o, const Convertitore &c)
{
    o << c.Va << "\t" << c.Vb << endl;
    o << c.tx << "\t1" << endl;
    return o;
}

istream &operator>>(istream &i, Convertitore &c)
{
    // ... lettura
    return i;
}

void foo(const Convertitore& c) {
    c.displayInfo();
    cout << c << "---";

    cout << c.convert(100) << endl;
    cout << c.iconvert(100) << endl;

    cout << (c << 100) << endl;
    cout << (c >> 100) << endl;
}

Convertitore get() {
   return Convertitore{"CHF", "EUR", 1.33};
}

int
main(void)
{
    Convertitore c{"CHF", "EUR", 1.33};
    foo(c);
    foo(get());

    return 0;
}
