#include <iostream>
#include "Kokkos_Core.hpp"

#define N 256


int main(int argc, char** argv) {

  Kokkos::initialize(argc, argv);

  double* a = new double[N];
  double* b = new double[N];
  double* c = new double[N];

  // Initializing a
  for (int i = 0; i < N; i++) {
    a[i] = 1.0;
  }

  // Initializing b
  for (int i = 0; i < N; i++) {
    b[i] = 1.0;
  }

  Kokkos::parallel_for(N, KOKKOS_LAMBDA (const int i) {
    c[i] = a[i] + b[i];
  });

  Kokkos::finalize();

  std::cout << "Solution Vector:\n";
  for (int i = 0; i < N; i++) {
    std::cout << c[i] << ' ';
  }
  std::cout << std::endl;

  delete(a);
  delete(b);
  delete(c);

  return 0;
}