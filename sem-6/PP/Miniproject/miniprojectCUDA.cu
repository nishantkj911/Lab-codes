%%cu
#include "cuda_runtime.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE (0x10000000)
#define alphabetLength 26

__device__ char switchCase(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return c - 32;
    }
    else if (c >= 'A' && c <= 'Z')
    {
        return c + 32;
    }
    else
    {
        printf("No special symbols\n");
        return c;
    }
}

__device__ int getGlobalID()
{
    return blockIdx.x * blockDim.x + threadIdx.x;
}

__global__ void encode(char *str, size_t len, char *key, int keyLen, char *ret)
{
    int i = getGlobalID();
    int j = i % keyLen;

    int temp = 0;
    char x = str[i], y = key[j];

    if ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z')) // checking if ip is an alphabet
    {
        if ((x >= 'A' && x <= 'Z') ^ (y >= 'A' && y <= 'Z')) // if the cases are different, making them same as i/p
        {
            y = switchCase(y);
        }
        
        // printf("comparing %c and %c", x, y);
        if (x >= 'A' && x <= 'Z') // ciphering upper case
        {
            temp = y + (x - 'A');
            if (temp > 'Z')
            {
                // printf("YO\n");
                temp = temp - alphabetLength;
            }
        }
        else // ciphering lower case
        {
            temp = y + (x - 'a');
            if (temp > 'z')
            {
                temp = temp - alphabetLength;
            }
        }
        // printf(" and got the answer %c\n", temp);
    }
    else
    {
        temp = x;
    }
    
    ret[i] = temp;
}

__global__ void decode(char *str, size_t len, char *key, int keyLen, char *ret)
{
    int i = getGlobalID();
    if (i >= len)
    return;
    
    int j = i % keyLen;
    
    int temp = 0;
    char f = str[i], y = key[j];

    if ((f >= 'A' && f <= 'Z') || (f >= 'a' && f <= 'z')) // checking if ip is an alphabet
    {
        if ((f >= 'A' && f <= 'Z') ^ (y >= 'A' && y <= 'Z')) // if the cases are different, making them same as i/p
        {
            y = switchCase(y);
        }

        // printf("comparing %c and %c", f, y);
        if (f >= 'A' && f <= 'Z') // deciphering upper case
        {
            temp = f + ('A' - y);
            if (temp < 'A')
            {
                // printf("YO\n");
                temp = temp + alphabetLength;
            }
        }
        else // deciphering lower case
        {
            temp = f + ('a' - y);
            if (temp < 'a')
            {
                temp = temp + alphabetLength;
            }
        }
        // printf(" and got the answer %c\n", temp);
    }
    else
    {
        temp = f;
    }

    ret[i] = temp;
}

int main(int argc, char const *argv[])
{
    // Initializing host and device variables.
    char *str = (char *) calloc(MAX_SIZE, sizeof(char)), *dStr;
    char key[BUFSIZ], *dKey;

    char *outputStr = (char *) calloc(MAX_SIZE, 1), *dOpStr;
    // printf("Enter the string you want to encode\n");
    // scanf("%[^\n]%*c", str);

    // printf("Enter the key\n");
    // scanf("%s", key);


    
    char *ipFile = (char *) calloc(BUFSIZ, 1), *opFile = (char *) calloc(BUFSIZ, 1);
    FILE *f1, *f2;
    FILE *f3 = fopen("inputPwd.txt", "r"); // comment for lab
    
    // Take input for the choice of operation
    printf("\n1. Encode\n2. Decode\nOther: Exit\nMake a choice? ");
    int ch;
    // scanf("%i", &ch); // uncomment
    fscanf(f3, "%i", &ch); // comment for lab
    printf("'%i'\n");
    
    if (ch == 1)
    {
        printf("Enter the file to encode\n");
    }
    else if (ch == 2)
    {
        printf("Enter the file to decode\n");
    }
    else
    {
        printf("Enter proper choice next time\n");
        return 1;
    }
    
    // check if input file exists
    //  scanf("%s", ipFile);
    fscanf(f3, "%s", ipFile);
    printf("'%s'", ipFile);
    
    f1 = fopen(ipFile, "r");
    if (!f1)
    {
        printf("File not found\n");
        return 1;
    }
    
    // create and open output file to write into
    sprintf(opFile, "output_%s", ipFile);
    f2 = fopen(opFile, "w");
    size_t len = fread(str, 1, MAX_SIZE, f1);
    
    // Take input of the password
    printf("Enter the password: ");
    // scanf("%s", key); // Uncomment in Lab
    fscanf(f3, "%s", key);
    printf("'%s'\n", key);

    size_t keylen = strlen(key);

    fclose(f3);

    printf("StrLen: %i\nKeylen: %i\n", len, keylen);
    
    //create mem objects 
    cudaMalloc(&dStr, len);
    cudaMalloc(&dOpStr, len);
    cudaMalloc(&dKey, keylen);

    // copy host string to device
    cudaMemcpy(dStr, str, len, cudaMemcpyHostToDevice);
    cudaMemcpy(dKey, key, keylen, cudaMemcpyHostToDevice);

    // encode or decode the code
    if (ch == 1)
    {
        encode <<<50, 100>>> (dStr, len, dKey, keylen, dOpStr);
        cudaError_t err;
        err = cudaGetLastError();
        if (err != cudaSuccess)

        printf("Cuda Error: %s\n", cudaGetErrorString(err));
        
    } 
    else if (ch == 2)
    {
        decode <<<50, 100>>> (dStr, len, dKey, keylen, dOpStr);
        // printf("BOOM!\n");
    }
    else
    {
        // printf("MEH!\n");
    }
        

    // copy device answer back to host and then to file
    cudaMemcpy(outputStr, dOpStr, len, cudaMemcpyDeviceToHost);
    int bytesWritten = fprintf(f2, "%s", outputStr);

    // printf("Bytes written are %i, actual length is %i\n", bytesWritten, len);

    printf("Done, check %s file\n", ch == 1 ? "encoded" : "decoded");
    
    // close the file handles
    fclose(f1);
    fclose(f2);
    
    scanf("%s", NULL);
    return 0;
}