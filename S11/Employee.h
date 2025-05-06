#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

struct Employee
{
    std::string name() const;
    std::string institute() const;
    int employeenr() const;

    Employee(const std::string &n, const std::string i, int nr);

    virtual std::string classname() const;

protected:
    std::string m_name;
    std::string m_institute;
    int m_nr;
};

#endif // EMPLOYEE_H
