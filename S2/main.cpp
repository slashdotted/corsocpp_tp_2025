#include <iostream>
#include <string>

void foo() {
    int x{3};
    std::string msg{"Hi"};
}

int sum(int a, int b) {
    return a+b;
}

void increment(int* i) {
    *i += 1;
}

int main() {
    int x{6};
    int y{7};
    sum(x,y);
    std::cout << "x=" << x << '\n';
    int* n{nullptr}; // <--- NULL
    int* ptrx{&x};
    increment(ptrx);
    std::cout << "x=" << x << '\n';
    foo();
    //int* ptr = (int*) malloc(sizeof(int));
    // *ptr = 42;
    int* ptr{new int{42}};
    double* dptr{new double};
    float* farray{new float[10]};
    std::cout << "*ptr=" << *ptr << ", *dptr=" << *dptr << std::endl;
    delete ptr;
    delete dptr;
    delete[] farray;
}
