#include <iostream>
#include "Kokkos_Core.hpp"

#define N 100

int main(int argc, char** argv) {

  
  // Kokkos init
  Kokkos::initialize(argc, argv);

  double vector[N];
  double matrix[N][N];
  double* product_vector = new double[N];

  // Initializing vector values
  for (int i = 0; i < N; i++) 
    vector[i] = 1;

  // Initializing product vector values
  for (int i = 0; i < N; i++)
    product_vector[i] = 0;

  // Initializing matrix values 
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      matrix[i][j] = 1;

  // Parallelized for loop with Kokkos and C++11 Lambda
  Kokkos::parallel_for(N, [=](int i) {
    for (int j = 0; j < N; j++) {
      product_vector[i] += matrix[i][j] * vector[j];
    }
  });

  // Kokkos finalize
  Kokkos::finalize();    

  std::cout << "Product Vector:\n";
  for (int i = 0; i < N; i++) {
    std::cout << product_vector[i] << ' ';
  }
  std::cout << std::endl;
  return 0;
}