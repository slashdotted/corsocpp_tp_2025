#include "Lecturer.h"

Lecturer::Lecturer(
    const std::string &n, const std::string &i, int nr, const std::string &c, const std::string &s)
    : Employee{n, i, nr}
    , m_course{c}
    , m_studies{s}
{}

std::string Lecturer::course() const
{
    return m_course;
}

std::string Lecturer::studies() const
{
    return m_studies;
}

std::string Lecturer::classname() const
{
    return "Lecturer";
}
