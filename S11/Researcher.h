#ifndef RESEARCHER_H
#define RESEARCHER_H
#include "Employee.h"
#include <string>

struct Researcher : public virtual Employee
{
    Researcher(const std::string &n, const std::string &i, int nr, const std::string &ra);

    std::string researcharea() const;

    std::string classname() const override;

    void foo() {}

private:
    std::string m_researcharea;
};

#endif // RESEARCHER_H
