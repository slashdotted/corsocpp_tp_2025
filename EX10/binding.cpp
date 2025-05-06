#include <iostream>

using namespace std;

class Base {
       public:
           void foo()
           {
               cout << "\tBase::foo()" << endl;
               bar();
           }
           /*virtual*/ void bar()
           {
               cout << "\tBase::bar()" << endl;
               cout << "\tCalling baz()" << endl;
               baz();
           }
           void baz() { cout << "\tBase::baz()" << endl; }
};

class Derived : public Base
{
public:
    void bar()
    {
        cout << "\tDerived::bar()" << endl;
        cout << "\tCalling baz()" << endl;
        baz();
    }
    void baz() { cout << "\tDerived::baz()" << endl; }
};

int main()
{
       Base b;
       Derived d;
       Base& bd = d;

       cout << "Calling b.foo()" << endl;
       b.foo();
       cout << "Calling d.foo()" << endl;
       d.foo();
       cout << "Calling bd.foo()" << endl;
       bd.foo();
}

/*
 
Desired output
==============

Calling b.foo()
Base::foo()
Base::bar()
Calling baz()
Base::baz()

Calling d.foo()
Base::foo()
Base::bar()
Calling baz()
Base::baz()

Calling bd.foo()
Base::foo()
Base::bar()
Calling baz()
Base::baz()

*/
