#include <iostream>
#include "Kokkos_Core.hpp"

#define N 1000

int main(int argc, char** argv) {

  // Kokkos init
  // 4 kokkos threads
  // 1 numa
  Kokkos::initialize(Kokkos::InitArguments(4,1));

  double array[N];
  
  for (int i = 0; i < N; i++) 
    array[i] = 1.0;
  
  // Resulting value of sum reduction
  double sum = 0;

  // Kokkos parallel reduction
  Kokkos::parallel_reduce(N, KOKKOS_LAMBDA (const int i, double& update) {
    update += array[i];
  }, sum);

  Kokkos::finalize();

  std::cout << "Sum of array: " << sum << std::endl;

  return 0;
}