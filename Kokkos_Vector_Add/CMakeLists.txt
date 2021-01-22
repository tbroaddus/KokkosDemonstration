cmake_minimum_required(VERSION 3.10)

project(KokkosDemonstration)

find_package(Kokkos REQUIRED)

add_executable(example Kokkos_Vector_Add.cpp)
target_link_libraries(example Kokkos::kokkos)