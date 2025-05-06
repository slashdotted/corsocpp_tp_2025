#ifndef LECTURERRESEARCHER_H
#define LECTURERRESEARCHER_H
#include "Lecturer.h"
#include "Researcher.h"
#include <string>

class LecturerResearcher : public Lecturer, public Researcher
{
public:
    LecturerResearcher(std::string name,
                       std::string institute,
                       int nr,
                       std::string studies,
                       std::string course,
                       std::string researcharea,
                       double researchpercentage);

    double researchpercentage() const;

    std::string classname() const override;

protected:
    double m_researchpercentage;
};
#endif
