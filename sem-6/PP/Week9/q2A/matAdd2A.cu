#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <stdlib.h>

__global__ void matAdd(int *A, int *B, int *C, int *col)
{
    int i = blockIdx.x;
    for (int j = 0; j < *col; j++)
    {
        C[i * (*col) + j] = A[i * (*col) + j] + B[i * (*col) + j];
    }
}

int main()
{
    int row, col;
    printf("Enter the row and columns of matrices\n");
    scanf("%i %i", &row, &col);
    int totalElements = row * col;

    int *matA = (int *)calloc(totalElements, sizeof(int)), *dA;
    int *matB = (int *)calloc(totalElements, sizeof(int)), *dB;
    int *matC = (int *)calloc(totalElements, sizeof(int)), *dC, *dCol;
    printf("Enter elements of A matrix\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%i", &matA[i * col + j]);
        }
    }

    printf("Enter elements of B matrix\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%i", &matB[i * col + j]);
        }
    }

    cudaMalloc(&dA, sizeof(int) * totalElements);
    cudaMalloc(&dB, sizeof(int) * totalElements);
    cudaMalloc(&dC, sizeof(int) * totalElements);
    cudaMalloc(&dCol, sizeof(int));

    cudaMemcpy(dA, matA, sizeof(int) * totalElements, cudaMemcpyHostToDevice);
    cudaMemcpy(dB, matB, sizeof(int) * totalElements, cudaMemcpyHostToDevice);
    cudaMemcpy(dCol, &col, sizeof(int), cudaMemcpyHostToDevice);

    matAdd<<<row, 1>>>(dA, dB, dC, dCol);

    cudaMemcpy(matC, dC, sizeof(int) * totalElements, cudaMemcpyDeviceToHost);

    printf("Result Matrix is\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%i ", matC[i * col + j]);
        }
        printf("\n");
    }
    
}
