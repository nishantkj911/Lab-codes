#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

__global__ void findSubstr(char *str, char *substr, int *len)
{
    int subStrLen = *len;
    int k = threadIdx.x;

    for (int j = 0, i = k; j < subStrLen; j++, i++)
    {
        if(str[i] != substr[j])
        {
            return;
        }
    }

    printf("Substring present at index %i\n", k);
}

int main()
{
    cudaError_t err;

    char *str = (char *) calloc(BUFSIZ, sizeof(char));
    printf("Enter the String\n");
    scanf("%[^\n]%*c", str);
    int strLen = strlen(str);

    char *substr = (char *) calloc(BUFSIZ, sizeof(char));
    printf("Enter the substring\n");
    scanf("%[^\n]%*c", substr);
    int subStrLen = strlen(substr);

    char *dStr, *dSubStr;
    int *dLen;

    cudaMalloc(&dStr,strLen);
    cudaMalloc(&dSubStr, subStrLen);
    cudaMalloc(&dLen, sizeof(int));

    cudaMemcpy(dStr, str, strLen, cudaMemcpyHostToDevice);
    cudaMemcpy(dSubStr, substr, subStrLen, cudaMemcpyHostToDevice);
    cudaMemcpy(dLen, &subStrLen, sizeof(int), cudaMemcpyHostToDevice);

    findSubstr<<<1, strLen - subStrLen + 1>>>(dStr, dSubStr, dLen);
    err = cudaGetLastError();
    if(err != cudaSuccess)
    {
        printf("The error string: %s\n", cudaGetErrorString(err));
    }

    cudaFree(dStr);
    cudaFree(dSubStr);
    cudaFree(dLen);
}
