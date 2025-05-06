set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(S11 main.cpp
    Employee.h
    Employee.cpp
    Researcher.h
    Researcher.cpp
    Lecturer.h
    Lecturer.cpp
    LecturerResearcher.h
    LecturerResearcher.cpp)
