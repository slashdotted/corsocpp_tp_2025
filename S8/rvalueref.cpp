#include <iostream>

void foo(int x) {}

// "L-Value reference"
void bar(int &x) {}

// int&& = R-Value reference
void bar(int &&x) {}

int baz()
{
    return 5;
}

int main() {
    int a{10};
    foo(a);
    foo(5);
    foo(baz());
    bar(a);
    bar(5);
    bar(baz());
}
