#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

__global__ void convertToBinary(char *str, int *arr)
{
    int i = threadIdx.x;
    int num = str[i], p = 1, temp = num, ans = 0;
    while (temp > 0)
    {
        ans = ans + p * (temp % 2);
        temp /= 2;
        p *= 10;
    }

    arr[i] = ans;
}

int main()
{
    char *str = (char *) calloc(BUFSIZ, sizeof(char)), *dStr;
    printf("Enter the string\n");
    scanf("%[^\n]%*c", str);
    int len = strlen(str), *dArr;
    int *arr = (int *) calloc(len, sizeof(int));

    cudaMalloc(&dStr, len);
    cudaMalloc(&dArr, sizeof(int) * len);

    cudaMemcpy(dStr, str, len, cudaMemcpyHostToDevice);
    cudaMemcpy(dArr, arr, sizeof(int) * len, cudaMemcpyHostToDevice);

    convertToBinary<<<1, len>>>(dStr, dArr);

    cudaMemcpy(arr, dArr, sizeof(int) * len, cudaMemcpyDeviceToHost);

    printf("The binary values of each character is\n");
    for (int i = 0; i < len; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
    

    cudaFree(dStr);
}
