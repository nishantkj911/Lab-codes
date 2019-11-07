#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

__global__ void findSubstr(char *str, char *substr, int *len, int *count)
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

//    printf("Substring present at index %i\n", k);
    count[k] = 1;
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
    int subStrLen = strlen(substr), len = strLen - subStrLen + 1;

    char *dStr, *dSubStr;
    int *dLen, *dCount, hCount, *hCountArr = (int *) calloc(len, sizeof(int));

    cudaMalloc(&dStr,strLen);
    cudaMalloc(&dSubStr, subStrLen);
    cudaMalloc(&dLen, sizeof(int));
    cudaMalloc(&dCount, sizeof(int) * len);

    cudaMemcpy(dStr, str, strLen, cudaMemcpyHostToDevice);
    cudaMemcpy(dSubStr, substr, subStrLen, cudaMemcpyHostToDevice);
    cudaMemcpy(dLen, &subStrLen, sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(dCount, hCountArr, sizeof(int) * len, cudaMemcpyHostToDevice);

    findSubstr<<<1, len>>>(dStr, dSubStr, dLen, dCount);
    err = cudaGetLastError();
    if(err != cudaSuccess)
    {
        printf("The error string: %s\n", cudaGetErrorString(err));
    }
    cudaMemcpy(hCountArr, dCount, sizeof(int) * len, cudaMemcpyDeviceToHost);

    hCount = 0;
    for (int i = 0; i < len; i++)
    {
        hCount += hCountArr[i];
    }

    printf("No. of occurrances of '%s' is %i\n", substr, hCount);

    cudaFree(dStr);
    cudaFree(dSubStr);
    cudaFree(dCount);
    cudaFree(dLen);
}
