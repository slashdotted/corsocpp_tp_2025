set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(S12static static.cpp)
add_executable(S12dynamic dynamic.cpp)
add_executable(S12reinterpret reinterpret.cpp)
add_executable(S12const const.cpp)
add_executable(S12constcastusecase constcastusecase.cpp)
