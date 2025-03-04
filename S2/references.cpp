void foo(int x) {
    ++x;
}

void bar(int *x) {
    ++(*x);
}

void baz(int& x) {
    ++x;
}

void baz2(const int& x) {

}

void no_swap(int x, int y) {
    int t{x};
    x = y;
    y = t;
}

void swap(int *x, int *y) {
    int t{*x};
    *x = *y;
    *y = t;
}

void swap(int& x, int& y) {
    int t{x};
    x = y;
    y = t;
}

int get() {
    return 42;
}

int& ret() {
    int t{42};
    return t; /// NOOOOOO! t non esiste più dopo la chiamata a ret
}

int& ret(int& k) {
    ++k;
    return k;
}






int main() {
    int a{10};
    int* b{&a};
    int& c{a};
    ++c;
    ++a;
    ++(*b);
    foo(a);
    bar(b);
    bar(&a);
    baz(a);

    foo(7);
    foo(get());
    //bar(7);
    //bar(&get());
    //baz(7);
    //baz(get());
    baz2(7);
    baz2(get());
    baz2(a);
    baz2(c);

    // Swap con variabili locali
    int x{5};
    int y{7};
    int t{x};
    x = y;
    y = t;
    swap(&x,&y);
    swap(x,y);
}
