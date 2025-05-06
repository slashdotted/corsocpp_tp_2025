#include "Employee.h"
#include "Lecturer.h"
#include "LecturerResearcher.h"
#include "Researcher.h"
#include <iostream>

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
    LecturerResearcher lr{"Luca", "ISTEPS", 4, "Gestionale", "Industry 4.0", "Machines", 0.5};
    std::cout << lr.name() << " : " << lr.researchpercentage() << '\n';
    lr.Lecturer::foo();

    foo(lr);
    Lecturer *lp{&l};
    Employee *ep{lp};
    std::cout << "lp=" << lp << ", ep=" << ep << std::endl;

    Lecturer *lp2{&lr};   // upcasting
    Researcher *rp2{&lr}; // upcasting
    auto l2{static_cast<LecturerResearcher *>(lp2)};
    //auto r2{static_cast<Researcher *>(lp2)};
    auto l3{static_cast<LecturerResearcher *>(&r)};
    std::cout << l3->researcharea() << std::endl;
    std::cout << l3->studies() << std::endl;
    //Employee *e2{&lr};
    //auto lr3{static_cast<LecturerResearcher *>(e2)};
}
