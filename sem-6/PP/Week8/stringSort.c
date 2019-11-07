#include <string.h>
#include <CL/cl.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SOURCE_SIZE (0x100000000)

int main(int argc, char const *argv[])
{
    char *str = calloc(BUFSIZ, sizeof(char));
    char *str2 = calloc(BUFSIZ, sizeof(char));
    printf("Enter a string to be sorted\n");
    scanf("%[^\n]%*c", str);

    int n = strlen(str);

    FILE *fp = fopen("stringSortKernel.cl", "r");
    if (fp == NULL)
    {
        printf("Cannot open kernel\n");
        exit(EXIT_FAILURE);
    }

    char *pgmStr = calloc(MAX_SOURCE_SIZE, sizeof(char));
    size_t pgmSize = fread(pgmStr, sizeof(char), MAX_SOURCE_SIZE, fp);
    fclose(fp);

    cl_platform_id plt;
    cl_device_id devID;
    cl_uint retNumDev, retNumPlt;
    cl_int ret;

    ret = clGetPlatformIDs(1, &plt, &retNumPlt);
    ret = clGetDeviceIDs(plt, CL_DEVICE_TYPE_GPU, 1, &devID, &retNumDev);

    cl_context context = clCreateContext(NULL, 1, &devID, NULL, NULL, &ret);
    cl_command_queue cq = clCreateCommandQueue(context, devID, NULL, &ret);

    cl_mem aMemObj = clCreateBuffer(context, CL_MEM_READ_ONLY, n * sizeof(char), NULL, &ret);
    cl_mem bMemObj = clCreateBuffer(context, CL_MEM_WRITE_ONLY, n * sizeof(char), NULL, &ret);

    clEnqueueWriteBuffer(cq, aMemObj, CL_TRUE, 0, n * sizeof(char), str, 0, NULL, NULL);

    cl_program pgm = clCreateProgramWithSource(context, 1, &pgmStr, &pgmSize, &ret);
    clBuildProgram(pgm, 1, &devID, NULL, NULL, NULL);

    cl_kernel kernel = clCreateKernel(pgm, "charSort", &ret);

    clSetKernelArg(kernel, 0, sizeof(cl_mem), &aMemObj);
    clSetKernelArg(kernel, 1, sizeof(cl_mem), &bMemObj);

    size_t globalWorkSize = n;
    size_t localWorkSize = 1;

    clEnqueueNDRangeKernel(cq, kernel, 1, NULL, &globalWorkSize, &localWorkSize, 0, NULL, NULL);
    clFinish(cq);

    clEnqueueReadBuffer(cq, bMemObj, CL_TRUE, 0, n * sizeof(char), str2, 0, NULL, NULL);

    printf("End string is: '%s'\n", str2);

    ret = clFlush(cq);
    ret = clReleaseKernel(kernel);
    ret = clReleaseProgram(pgm);
    ret = clReleaseMemObject(aMemObj);
    ret = clReleaseMemObject(bMemObj);
    ret = clReleaseCommandQueue(cq);
    ret = clReleaseContext(context);
    return 0;
}
