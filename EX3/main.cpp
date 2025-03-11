#include <vector>
#include <map>
#include <iostream>

int showGrade(const std::map<std::string, int>& grades,
              const std::string& name);

void addStudent(std::vector<std::string>& students,
                std::map<std::string, int>& grades,
                const std::string& name) {
    if(grades.count(name) != 0) {
        throw std::runtime_error("the student already exists");
    }
    students.push_back(name);
    grades[name] = -1;
}
void updateGrade(std::map<std::string, int>& grades, const std::string& name,
                 int grade) {
    if(grades.count(name) == 0) {
        throw std::runtime_error("the student does not exist");
    }
    grades[name] = grade;
}
void displayGrades(const std::vector<std::string>& students, const
                   std::map<std::string, int>& grades) {
    for(const auto& s : students) {
        showGrade(grades,s);
    }

}
int showGrade(const std::map<std::string, int>& grades,
              const std::string& name)
{
    if(grades.count(name) == 0) {
        throw std::runtime_error("the student does not exist");
    }
    // Can't use [] because the map is const
    return grades.at(name);
}
void removeStudent(std::vector<std::string>& students, std::map<std::string,
                                                                int>& grades, const std::string& name) {
    if(grades.count(name) == 0) {
        throw std::runtime_error("the student does not exist");
    }
    grades.erase(name);
    auto idx{0};
    for(const auto& s : students) {
        if (s == name) {
            students.erase(students.begin() + idx);
            return;
        }
        ++idx;
    }
}


int main() {
    std::vector<std::string> students;
    std::map<std::string, int> grades;
    try {
        addStudent(students, grades, "Andrea");
        addStudent(students, grades, "Amos");
        updateGrade(grades, "Andrea", 5);
        updateGrade(grades, "Amos", 4);
        displayGrades(students, grades);
        std::cout << "Andrea: " << showGrade(grades, "Andrea") << std::endl;
        removeStudent(students, grades, "Luca"); // Luca does not exist! Throws!
        displayGrades(students, grades);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
