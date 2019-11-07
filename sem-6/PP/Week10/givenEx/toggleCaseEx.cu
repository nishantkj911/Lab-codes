#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <stdlib.h>

#define N 1025

__global__ void CUDAStrCopy(char *A, char C[N])
{
    int i = threadIdx.x;
    C[i] = A[i] - 32;
//    printf("%c\n", C[i]);
}

int main()
{
    char A[N];
    char C[N];
    char *pA, *pC;
    for (int i = 0; i < N; i++)
    {
        A[i] = 'a';
    }
    printf("C = \n");
    cudaEvent_t start, stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);
    cudaEventRecord(start, 0);
    cudaMalloc((void **)&pA, N * sizeof(char));
    cudaMalloc((void **)&pC, N * sizeof(char));
    cudaMemcpy(pA, A, N * sizeof(char), cudaMemcpyHostToDevice);
    cudaError_t error = cudaGetLastError();
    if (error != cudaSuccess)
    {
        printf("CUDA  Error1:  %s\n", cudaGetErrorString(error));
    }
    CUDAStrCopy<<<1, N>>>(pA, pC);
    error = cudaGetLastError();
    if (error != cudaSuccess)
    {
        printf("CUDA  Error2:  %s\n", cudaGetErrorString(error));
    }
    cudaMemcpy(C, pC, N * sizeof(char), cudaMemcpyDeviceToHost);
    cudaEventRecord(stop, 0);
    cudaEventSynchronize(stop);
    float elapsedTime;
    cudaEventElapsedTime(&elapsedTime, start, stop);
    printf("VALUE OF C IN HOST AFTER KERNEL EXECUTION\n");
    for (int i = 0; i < N; i++)
        printf("%c\n", C[i]);
    printf("Time Taken=%f", elapsedTime);
    cudaFree(pA);
    cudaFree(pC);
    printf("\n");
    return 0;
}
