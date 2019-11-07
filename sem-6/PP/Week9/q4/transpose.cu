#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <stdlib.h>

__global__ void transpose(int *A, int *B)
{
    int i = blockIdx.x;
    int j = threadIdx.x;
    int row = gridDim.x;
    int col = blockDim.x;

    B[j * row + i] = A[i * col + j];
}

int main()
{
    int row, col;
    printf("Enter the no. of rows and columns\n");
    scanf("%i %i", &row, &col);
    int totalElements = row * col;

    int *matA = (int *) calloc(totalElements, sizeof(int)), *dA, *dB;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%i", &matA[i * col + j]);
        }
    }

    cudaMalloc(&dA, totalElements * sizeof(int));
    cudaMalloc(&dB, totalElements * sizeof(int));

    cudaMemcpy(dA, matA, totalElements * sizeof(int), cudaMemcpyHostToDevice);

    transpose<<<row, col>>>(dA, dB);

    cudaMemcpy(matA, dB, totalElements * sizeof(int), cudaMemcpyDeviceToHost);

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            printf("%i ", matA[i * row + j]);
        }
        printf("\n");
    }
    
    cudaFree(dA);
    cudaFree(dB);
}
