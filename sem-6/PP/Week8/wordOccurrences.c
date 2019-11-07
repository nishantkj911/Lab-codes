#include <stdio.h>
#include <stdlib.h>
#include <CL/cl.h>
#include <string.h>

#define MAX_SOURCE_SIZE (0x100000000)

int main(int argc, char const *argv[])
{
    char *str = calloc(BUFSIZ, sizeof(char));
    char *word = calloc(BUFSIZ, sizeof(char));

    printf("Enter the string to be searched\n");
    scanf("%[^\n]%*c", str);

    printf("Enter the word to be searched for\n");
    scanf("%s", word);

    int noOfOccurrences = 0;
    int len = strlen(str), wordLen = strlen(word), noOfWords = 0, maxSize = 1;
    int *spaces = calloc(1, sizeof(int));
    for (int i = 0; i < len; i++)
    {
        if(str[i] == ' ' || str[i] == '\t')
        {
            if(noOfWords == maxSize)
            {
                maxSize *= 2;
                spaces = realloc(spaces, sizeof(int) * maxSize);
            }
            
            spaces[noOfWords++] = i;
        }
    }

    if(spaces[noOfWords - 1] != len - 1)
    {
        if(noOfWords == maxSize)
        {
            maxSize++;
            spaces = realloc(spaces, sizeof(int) * maxSize);
        }
        spaces[noOfWords++] = len - 1;

    }
    

    /*printf("The words start and end at\n");
    for (int i = 0; i < noOfWords; i++)
    {
        printf("%i ", spaces[i]);
    }
    printf("\n");*/

    cl_platform_id plt;
    cl_device_id devID;
    cl_uint retDevID, retPltID;
    cl_int ret;

    clGetPlatformIDs(1, &plt, &retPltID);
    clGetDeviceIDs(plt, CL_DEVICE_TYPE_GPU, 1, &devID, &retDevID);

    cl_context context = clCreateContext(NULL, 1, &devID, NULL, NULL, &ret);
    cl_command_queue cq = clCreateCommandQueueWithProperties(context, devID, NULL, &ret);

    cl_mem aMemObj = clCreateBuffer(context, CL_MEM_READ_ONLY, len * sizeof(char), NULL, &ret);
    cl_mem a1MemObj = clCreateBuffer(context, CL_MEM_READ_ONLY, wordLen * sizeof(char), NULL, &ret);
    cl_mem bMemObj = clCreateBuffer(context, CL_MEM_READ_ONLY, (noOfWords + 1) * sizeof(int), NULL, &ret);
    cl_mem cMemObj = clCreateBuffer(context, CL_MEM_READ_WRITE, sizeof(int), NULL, &ret);
    cl_mem dMemObj = clCreateBuffer(context, CL_MEM_READ_WRITE, sizeof(int), NULL, &ret);


    clEnqueueWriteBuffer(cq, aMemObj, CL_TRUE, 0, len, str, 0, NULL, NULL);
    clEnqueueWriteBuffer(cq, a1MemObj, CL_TRUE, 0, wordLen, word, 0, NULL, NULL);
    clEnqueueWriteBuffer(cq, bMemObj, CL_TRUE, 0, (noOfWords+1) * sizeof(int), spaces, 0, NULL, NULL);
    clEnqueueWriteBuffer(cq, cMemObj, CL_TRUE, 0, sizeof(int), &len, 0, NULL, NULL);
    clEnqueueWriteBuffer(cq, dMemObj, CL_TRUE, 0, sizeof(int), &noOfOccurrences, 0, NULL, NULL);

    FILE *fp = fopen("wordOccurrencesKernel.cl", "r");
    if(!fp)
    {
        printf("Cannot open kernel\n");
        exit(EXIT_FAILURE);
    }

    char *pgmStr = calloc(MAX_SOURCE_SIZE, 1);
    size_t pgmSize = fread(pgmStr, 1, MAX_SOURCE_SIZE, fp);
    fclose(fp);

    cl_program pgm = clCreateProgramWithSource(context, 1, &pgmStr, &pgmSize, &ret);
    clBuildProgram(pgm, 1, &devID, NULL, NULL, NULL);

    cl_kernel kernel = clCreateKernel(pgm, "searchWord", &ret);
    
    clSetKernelArg(kernel, 0, sizeof(cl_mem), &aMemObj);
    clSetKernelArg(kernel, 1, sizeof(cl_mem), &a1MemObj);
    clSetKernelArg(kernel, 2, sizeof(cl_mem), &bMemObj);
    clSetKernelArg(kernel, 3, sizeof(cl_mem), &cMemObj);
    clSetKernelArg(kernel, 4, sizeof(cl_mem), &dMemObj);

    size_t globalWorkSize = noOfWords, localWorkSize = 1;

    clEnqueueNDRangeKernel(cq, kernel, 1, NULL, &globalWorkSize, &localWorkSize, 0, NULL, NULL);
    clFinish(cq);

    clEnqueueReadBuffer(cq, dMemObj, CL_TRUE, 0, sizeof(int), &noOfOccurrences, 0, NULL, NULL);

    printf("No of occurrances of the word '%s' is %i\n", word, noOfOccurrences);

    ret = clFlush(cq);
    ret = clReleaseKernel(kernel);
    ret = clReleaseProgram(pgm);
    ret = clReleaseMemObject(aMemObj);
    ret = clReleaseMemObject(bMemObj);
    ret = clReleaseCommandQueue(cq);
    ret = clReleaseContext(context);
    return 0;
}
