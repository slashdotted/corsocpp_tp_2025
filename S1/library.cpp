#include "library.h"
#include <iostream>

namespace ch {
    namespace supsi {
        namespace debug {
            int multiply(int a, int b, int c, int d) {
                std::cout << "multiply(a=" << a
                          << ",b=" << b
                          << ",c=" << c
                          << ",c=" << d << ")" << std::endl;
                return a*b*c*d;
            }
        }
    }
}

namespace ch {
    namespace supsi {
        namespace release {
            int multiply(int a, int b, int c, int d) {
                return a*b*c*d;
            }
        }
    }
}

