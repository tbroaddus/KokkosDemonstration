cmake_minimum_required(VERSION 3.3)

project(KokkosDemonstration)

find_package(Kokkos REQUIRED)

add_executable(example example.cpp)
target_link_libraries(example Kokkos::kokkos)


