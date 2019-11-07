#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <stdlib.h>

__device__ int getGlobalId()
{
//    printf("Block ID: x = %i, y = %i\nThread ID: x = %i, y = %i\n", blockIdx.x, blockIdx.y, threadIdx.x, threadIdx.y);
    int blockId = blockIdx.y * gridDim.x + blockIdx.x;
    int threadId = (blockDim.x * blockDim.y) * blockId + threadIdx.y * blockDim.x + threadIdx.x;
    return threadId;
}

__global__ void matrixMultiplication(int *A, int *B, int *C)
{
    int i = getGlobalId();
//    printf("%i\n", i);
    
    //Add Code for multiplication
}

int main()
{
    int n;
    printf("Enter the order of matrices\n");
    scanf("%i", &n);
    int row = n, col = n;
    

    int *matA = (int *) calloc(row * col, sizeof(int)), *dA;
    int *matC = (int *) calloc(row * col, sizeof(int));
    int *matB = (int *) calloc(row * col, sizeof(int)), *dB, *dC;
     
    printf("Enter the first Matrix\n");
    for (int i = 0; i < row * col; i++)
    {
        scanf("%i", &matA[i]);
    }

    printf("Enter the second Matrix\n");
    for (int i = 0; i < row * col; i++)
    {
        scanf("%i", &matB[i]);
    }

    cudaMalloc(&dA, sizeof(int) * row * col);
    cudaMalloc(&dC, sizeof(int) * row * col);
    cudaMalloc(&dB, sizeof(int) * row * col);

    cudaMemcpy(dA, matA, sizeof(int) * row * col, cudaMemcpyHostToDevice);
    cudaMemcpy(dB, matB, sizeof(int) * row * col, cudaMemcpyHostToDevice);

    dim3 gridDim (2, 2);
    dim3 blockDim (row / 2, col / 2);

    matrixAddition<<< gridDim, blockDim>>>(dA, dB, dC);

    cudaMemcpy(matC, dC, sizeof(int) * row * col, cudaMemcpyDeviceToHost);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%i ", matC[i * col + j]);
        }
        printf("\n");
    }

    cudaFree(dA);
    cudaFree(dB);
    cudaFree(dC);
}
