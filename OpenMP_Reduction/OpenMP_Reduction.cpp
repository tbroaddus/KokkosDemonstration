#include <iostream>
#include <omp.h>

#define N 1000

int main() {

  double array[N];

  for (int i = 0; i < N; i++)
    array[i] = 1.0;

  double sum = 0;

  #pragma omp parallel for reduction(+ : sum)
  for (int i = 0; i < N; i++) {
    sum += array[i];
  }

  std::cout << "Sum of array: " << sum << std::endl;

  return 0;
}