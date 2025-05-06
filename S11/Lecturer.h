#ifndef LECTURER_H
#define LECTURER_H
#include "Employee.h"
#include <string>

struct Lecturer : public Employee
{
    Lecturer(const std::string &n,
             const std::string &i,
             int nr,
             const std::string &c,
             const std::string &s);

    std::string course() const;
    std::string studies() const;
    std::string classname() const override;

private:
    std::string m_course;
    std::string m_studies;
};

#endif // LECTURER_H
