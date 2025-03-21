#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class Convertitore {
    string Va;
    string Vb;
    double tx;
    std::map<std::string, int> m;
public:
    Convertitore(const string& V1, const string& V2, double tasso = 1.20)
        : Va{V1}, Vb{V2}, tx{tasso} {
    }

    double convert(double v) const {
        return v / tx;
    }

    double iconvert(double v) const {
        // std::cout << m["k"];
        std::cout << m.at("k");
        return v * tx;
    }

    void displayInfo() const
    {
        cout << Va << "\t"  << Vb << endl;
        cout << tx << "\t1" << endl;
    }
		

};

void foo(const Convertitore& c) {
    c.displayInfo();

    cout << c.convert(100) << endl;
    cout << c.iconvert(100) << endl;
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
