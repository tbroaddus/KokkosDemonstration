#include <iostream>
#include <omp.h>

#define N 100 

int main(int argc, char** argv) {

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

  // Parallelized for loop with OpenMP 
  #pragma omp parallel for
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      product_vector[i] += matrix[i][j] * vector[j];
    }
  }

  std::cout << "Product Vector:\n";
  for (int i = 0; i < N; i++) {
    std::cout << product_vector[i] << ' ';
  }
  std::cout << std::endl;
  return 0;
}