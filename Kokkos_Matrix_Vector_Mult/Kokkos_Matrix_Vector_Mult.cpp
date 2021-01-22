#include <iostream>
#include "Kokkos_Core.hpp"

#define N 100

int main(int argc, char** argv) {

  
  // Kokkos init
  Kokkos::initialize(argc, argv);

  double vector[N];
  double matrix[N][N];
  double* solution_vector = new double[N];

  // Initializing vector values
  for (int i = 0; i < N; i++) 
    vector[i] = 1;

  // Initializing solution vector values
  for (int i = 0; i < N; i++)
    solution_vector[i] = 0;

  // Initializing matrix values 
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      matrix[i][j] = 1;

  // Parallelized for loop with Kokkos and C++11 Lambda
  Kokkos::parallel_for(N, [=](int i) {
    for (int j = 0; j < N; j++) {
      solution_vector[i] += matrix[i][j] * vector[j];
    }
  });

  // Kokkos finalize
  Kokkos::finalize();    

  std::cout << "Solution Vector:\n";
  for (int i = 0; i < N; i++) {
    std::cout << solution_vector[i] << ' ';
  }
  std::cout << std::endl;

  delete(solution_vector);

  return 0;
}