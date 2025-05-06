#include "LecturerResearcher.h"

LecturerResearcher::LecturerResearcher(std::string name,
                                       std::string institute,
                                       int nr,
                                       std::string studies,
                                       std::string course,
                                       std::string researcharea,
                                       double researchpercentage)
    : Employee{name, institute, nr}
    , Lecturer{name, institute, nr, course, studies}
    , Researcher{name, institute, nr, researcharea}
    , m_researchpercentage{researchpercentage}
{}

double LecturerResearcher::researchpercentage() const
{
    return m_researchpercentage;
}

std::string LecturerResearcher::classname() const
{
    return "LecturerResearcher";
}
