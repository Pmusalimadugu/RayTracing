#include <iostream>
#include "Vec3.h"

#define print(x) std::cout << x 
#define println(x) std::cout << x << std::endl


__global__
void add(int n, Vec3* x, Vec3* y)
{
	int index = threadIdx.x;
	int stride = blockDim.x;
	for (int i = index; i < n; i += stride)
	{
		y[i] += x[i];
	}

}


int test()
{
	int N = 1 << 30; // 1M elements

	println(N);

	Vec3* x;
	Vec3* y;


	cudaMallocManaged(&x, N * sizeof(Vec3));
	cudaMallocManaged(&y, N * sizeof(Vec3));



	// Run kernel on 1M elements on the CPU
	add(N, x, y);
	//add<<<1, 256 >>> (N, x, y);


	cudaDeviceSynchronize();

	// Free memory
	cudaFree(x);
	cudaFree(y);


	return 0;
}
