#include "Employee.h"
#include "Lecturer.h"
#include "Researcher.h"
#include <iostream>

struct Pinguino
{};

void foo(Employee *e)
{
    std::cout << "In foo(Employee*) = " << e->classname() << '\n';
}

void foo(const Employee &e)
{
    std::cout << "In foo(const Employee&) = " << e.classname() << '\n';
}

void baz(Employee e)
{
    std::cout << "In baz(Employee) = " << e.classname() << '\n';
}

int main()
{
    Employee e{"John", "ISIN", 1};
    Lecturer l{"Alice", "ISEA", 2, "Tecnica digitale", "Elettronica"};
    Researcher r{"Andrea", "ISIN", 3, "Computer vision"};
    Pinguino p;
    //foo(&p);

    Lecturer *lp{&l};
    Employee *ep{lp};
    std::cout << "lp=" << lp << ", ep=" << ep << std::endl;

    std::cout << "==== Employee ====\n";
    foo(&e);
    foo(e);
    baz(e);

    std::cout << "==== Lecturer ====\n";
    foo(&l);
    foo(l);
    baz(l);

    std::cout << "==== Researcher ====\n";
    foo(&r);
    foo(r);
    baz(r);
}
