#include <iostream>

// C++ supports overloading (like Java)
int multiply(int a, int b = 1, int c = 1, int d = 1);

int multiply(int a, int b, int c, int d) {
    return a*b*c*d;
}

/*int multiply(int a, int b, int c) {
    return multiply(a,b,c,1);
}

int multiply(int a, int b) {
    return multiply(a,b,1,1);
}*/

int main() {
    std::cout << multiply(3,4) << '\n';
    std::cout << multiply(3,4,5) << '\n';
    std::cout << multiply(3,4,5,6) << '\n';
}
