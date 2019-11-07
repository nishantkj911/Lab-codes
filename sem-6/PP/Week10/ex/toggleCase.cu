#include "device_launch_parameters.h"
#include "cuda_runtime.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

__global__ void toggleCase(char *ipStr, char *opStr)
{
    int i = threadIdx.x;
    if(ipStr[i] >= 'a' && ipStr[i] <= 'z')
    {
        opStr[i] = ipStr[i] - 'a' + 'A';
    }
    else if(ipStr[i] >= 'A' && ipStr[i] <= 'Z')
    {
        opStr[i] = ipStr[i] - 'A' + 'a';
    }
    else
    {
        opStr[i] = ipStr[i];
    }
}

int main()
{
    cudaEvent_t startEvent, stopEvent;
    cudaEventCreate(&startEvent);
    cudaEventCreate(&stopEvent);
    char *str = (char *) calloc(BUFSIZ, sizeof(char)), *dStr, *dOpStr;
    printf("Enter a string\n");
    scanf("%[^\n]%*c", str);

    int len = strlen(str);

    cudaEventRecord(startEvent, 0);

    cudaMalloc(&dStr, sizeof(char) * len);
    cudaMalloc(&dOpStr, sizeof(char) * len);

    cudaMemcpy(dStr, str, sizeof(char) * len, cudaMemcpyHostToDevice);

    toggleCase<<<1, len>>>(dStr, dOpStr);


    cudaMemcpy(str, dOpStr, sizeof(char) * len, cudaMemcpyDeviceToHost);

    cudaEventRecord(stopEvent, 0);
    cudaEventSynchronize(stopEvent);

    float timeElapsed;
    cudaEventElapsedTime(&timeElapsed, startEvent, stopEvent);

    printf("The resultant string: \n");
    printf("%s\n", str);

    printf("Time taken for CUDA operations %0.5fms\n", timeElapsed);

    cudaFree(dStr);
    cudaFree(dOpStr);
}
