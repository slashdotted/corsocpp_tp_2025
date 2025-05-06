#include "Employee.h"

std::string Employee::name() const
{
    return m_name;
}

std::string Employee::institute() const
{
    return m_institute;
}

int Employee::employeenr() const
{
    return m_nr;
}

Employee::Employee(const std::string &n, const std::string i, int nr)
    : m_name{n}
    , m_institute{i}
    , m_nr{nr}
{}

std::string Employee::classname() const
{
    return "Employee";
}
