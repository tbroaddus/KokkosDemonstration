cmake_minimum_required(VERSION 3.10)

project(KokkosDemonstration)

find_package(OpenMP REQUIRED)

add_executable(example OpenMP_Vector_Add.cpp)
target_link_libraries(example PRIVATE OpenMP::OpenMP_CXX)