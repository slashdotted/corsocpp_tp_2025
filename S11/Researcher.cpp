#include "Researcher.h"

Researcher::Researcher(const std::string &n, const std::string &i, int nr, const std::string &ra)
    : Employee{n, i, nr}
    , m_researcharea{ra}
{}

std::string Researcher::researcharea() const
{
    return m_researcharea;
}

std::string Researcher::classname() const
{
    return "Researcher";
}
