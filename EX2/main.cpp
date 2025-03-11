#include <iostream>
using namespace std;
void bar(int* b) {
    cout << 'A' << *b;
}
void bar(int b) {
    cout << 'B' << b;
}
void bar(int const* b) {
    cout << 'C' << *b;
}

// Cannot overload on non-references const
// int * const b === int * b
//void bar(int * const b) {
//    cout << 'D' << *b;
//}

// Cannot overload on non-references const
// int const b === int b
//void bar(int const b) {
//    cout << 'E' << *b;
//}

int
main(void)
{
    int* x = new int{1};
    int y = 2;
    int const * z = x;
    int * const q = &y;
    bar(x); // A1
    bar(y); // B2
    bar(z); // C1
    bar(q); // A2
    // Ex1. we need to release the memory allocated behind x
    delete x;
    return 0;
}
