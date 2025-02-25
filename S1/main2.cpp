#include "library.h"
#include <iostream>
/*int multiply(int a, int b) {
    return multiply(a,b,1,1);
}*/

namespace org {
namespace blabla {

}
}

using namespace org::blabla;
namespace p = org::blabla;



namespace t = ch::supsi::release;

void foo() {
    using ch::supsi::debug::multiply;
    multiply(2,2);
}

int getValue() {
    return 5;
}

std::string getMessage() {
    return "hello world";
}

int main() {
    using namespace std;
    cout << t::multiply(3,4) << endl;

    int year{2025};
    int month = 2;
    month = 3;
    // year{2026};
    int pi = 3.14;
    //int pi{3.14};
    //auto pi{3.14};
    auto d{getValue()};
    auto k{3};
    pi = k + d + year;
    auto m{getMessage()};
    auto n{getMessage()};
    auto p{m+n};




}


