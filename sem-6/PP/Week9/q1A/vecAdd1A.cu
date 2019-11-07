#include <stdio.h>
#include <stdlib.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

__global__ void vecadd(int *A, int *B, int *C)
{
    int i = blockIdx.x;
    C[i] = A[i] + B[i];
}

int main()
{
    int n;
    printf("Enter the no. of elements\n");
    scanf("%i", &n);

    int *hA = (int *)calloc(n, sizeof(int));
    int *hB = (int *)calloc(n, sizeof(int));
    int *hC = (int *)calloc(n, sizeof(int));

    printf("Enter array 1\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &hA[i]);
    }

    printf("Enter array 2\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &hB[i]);
    }

    int *dA, *dB, *dC;
    cudaMalloc(&dA, n * sizeof(int));
    cudaMalloc(&dB, n * sizeof(int));
    cudaMalloc(&dC, n * sizeof(int));

    cudaMemcpy(dA, hA, n * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(dB, hB, n * sizeof(int), cudaMemcpyHostToDevice);

    vecadd<<<n, 1>>>(dA, dB, dC);
    cudaError_t err = cudaGetLastError();
    if(err != cudaSuccess)
    {
    	printf("%s\n", cudaGetErrorString(err));
    }

    cudaMemcpy(hA, dC, n * sizeof(int), cudaMemcpyDeviceToHost);

    for (int i = 0; i < n; i++)
    {
        printf("%i ", hA[i]);
    }
    printf("\n");
    
    cudaFree(dA);
    cudaFree(dB);
    cudaFree(dC);
    return 0;
}
