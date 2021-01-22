#include <iostream>
#include <omp.h>

#define N 256

int main() {

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


  #pragma omp parallel for
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      c[i] = a[i] + b[i];
    }
  }

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
