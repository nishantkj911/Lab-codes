#include <stdio.h>
#include <stdlib.h>

__global__ void oddEvenExchange(int *A)
{
    int i = threadIdx.x;
    int n = blockDim.x;

    if (i % 2 && i != n - 1)
    {
        printf("printing from OE and %i\n", i);        
        if (A[i] > A[i+1])
        {
            int temp = A[i];
            A[i] = A[i+1];
            A[i+1] = temp;
        }
    }
}

__global__ void evenOddExchange(int *A)
{
    int i = threadIdx.x;
    int n = blockDim.x;
    
    if (!(i % 2) && i != n - 1)
    {
        printf("printing from EO and %i\n", i);        
        if (A[i] > A[i+1])
        {
            int temp = A[i];
            A[i] = A[i+1];
            A[i+1] = temp;
        }
    }
}

int main()
{
    FILE *f1 = fopen("inputOESort.txt", "r");
    FILE *f2 = fopen("outputOESort.txt", "w");

    int n;
    fscanf(f1, "%i", &n);

    fprintf(f2, "n = %i\n", n);
    int *A = (int *) calloc(n, sizeof(int)), *dA;
    for (int i = 0; i < n; i++)
    {
        fscanf(f1, "%i", &A[i]);
    }
    
    /* fprintf(f2, "The initial array is\n");
    for (int i = 0; i < n; i++)
    {
        fprintf(f2, "%i ", A[i]);
    }
    fprintf(f2, "\n"); */

    cudaMalloc(&dA, n * sizeof(int));
    cudaMemcpy(dA, A, n * sizeof(int), cudaMemcpyHostToDevice);
    
    for (int i = 0; i < n / 2; i++)
    {
        oddEvenExchange<<<1, n>>>(dA);
        evenOddExchange<<<1, n>>>(dA);
        
        /* cudaMemcpy(A, dA, n * sizeof(int), cudaMemcpyDeviceToHost);

        fprintf(f2, "The array after iter %i is\n", i + 1);
        for (int i = 0; i < n; i++)
        {
            fprintf(f2, "%i ", A[i]);
        }
        fprintf(f2, "\n"); */
    }
    
    cudaMemcpy(A, dA, n * sizeof(int), cudaMemcpyDeviceToHost);

    fprintf(f2, "The sorted array is\n");
    for (int i = 0; i < n; i++)
    {
        fprintf(f2, "%i ", A[i]);
    }
    fprintf(f2, "\n");
    
    fclose(f1);
    fclose(f2);
}