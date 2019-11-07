#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

__global__ void revStr(char *str, int *length)
{
    int i = threadIdx.x;
    int len = *length;

    int temp = str[i];
    str[i] = str[len - i - 1];
    str[len - i - 1] = temp;
}

int main()
{
    char *str = (char *) calloc(BUFSIZ, sizeof(char)), *dStr;
    printf("Enter the string\n");
    scanf("%[^\n]%*c", str);
    int len = strlen(str), *dLen;

    cudaMalloc(&dStr, len);
    cudaMalloc(&dLen, sizeof(int));

    cudaMemcpy(dStr, str, len, cudaMemcpyHostToDevice);
    cudaMemcpy(dLen, &len, sizeof(int), cudaMemcpyHostToDevice);

    revStr<<<1, len / 2>>>(dStr, dLen);

    cudaMemcpy(str, dStr, len, cudaMemcpyDeviceToHost);

    printf("The reversed string:\n%s", str);

    cudaFree(dStr);
}
