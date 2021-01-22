#include <stdio.h>
#include <cuda.h>

#define N 256

__global__ void vector_add(double *a, double *b, double *c) {
  if (threadIdx.x < N) 
    c[threadIdx.x] = a[threadIdx.x] + b[threadIdx.x]; 
}

int main() {
  double *a, *b, *c;
  int size = N * sizeof(double)

  cudaMalloc((void **)&d_a, size);
  cudaMalloc((void **)&d_b, size);
  cudaMalloc((void **)&d_c, size);


  a = (double*)malloc(size);
  b = (double*)malloc(size);
  c = (double*)malloc(size);

  cudaMemcpy(d_a, a, size, cudaMemcpyHostToDevice);
  cudaMemcpy(d_a, b, size, cudaMemcpyHostToDevice);

  vector_add<<<1,N>>>(d_a, d_b, d_c);

  cudaMemcpy(d_c, c, size, cudaMemcpyDeviceToHost);

  free(a);
  free(b);
  free(c);

  cudaFree(d_a);
  cudaFree(d_b);
  cudaFree(d_c);

  return 0;
}
