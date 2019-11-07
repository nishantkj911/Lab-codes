#include <stdio.h>
#include <stdlib.h>
#include <CL/cl.h>
#define MAX_SOURCE_SIZE (0x100000000)

// Try with one program

int main(int argc, char const *argv[])
{
    printf("Enter the no. of elements\n");
    int n;
    scanf("%i", &n);

    int *A = calloc(n, sizeof(int));
    printf("Enter the array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &A[i]);
    }

    FILE *fp1 = fopen("oddEvenExchange.cl", "r");
    if (fp1 == NULL)
    {
        printf("Cannot open kernel\n");
        exit(EXIT_FAILURE);
    }
    FILE *fp2 = fopen("evenOddExchange.cl", "r");
    if (fp2 == NULL)
    {
        printf("Cannot open kernel\n");
        exit(EXIT_FAILURE);
    }

    char *pgmStr1 = calloc(MAX_SOURCE_SIZE, sizeof(char));
    size_t pgmSize1 = fread(pgmStr1, sizeof(char), MAX_SOURCE_SIZE, fp1);
    fclose(fp1);

    char *pgmStr2 = calloc(MAX_SOURCE_SIZE, sizeof(char));
    size_t pgmSize2 = fread(pgmStr2, sizeof(char), MAX_SOURCE_SIZE, fp2);
    fclose(fp2);

    cl_platform_id plt;
    cl_device_id devID;
    cl_uint retNumDev, retNumPlt;
    cl_int ret;

    ret = clGetPlatformIDs(1, &plt, &retNumPlt);
    ret = clGetDeviceIDs(plt, CL_DEVICE_TYPE_GPU, 1, &devID, &retNumDev);

    cl_context context = clCreateContext(NULL, 1, &devID, NULL, NULL, &ret);
    cl_command_queue cq = clCreateCommandQueue(context, devID, NULL, &ret);

    cl_mem aMemObj = clCreateBuffer(context, CL_MEM_READ_WRITE, n * sizeof(int), NULL, &ret);

    clEnqueueWriteBuffer(cq, aMemObj, CL_TRUE, 0, n * sizeof(int), A, 0, NULL, NULL);

    cl_program pgm1 = clCreateProgramWithSource(context, 1, &pgmStr1, &pgmSize1, &ret);
    clBuildProgram(pgm1, 1, &devID, NULL, NULL, NULL);
    cl_program pgm2 = clCreateProgramWithSource(context, 1, &pgmStr2, &pgmSize2, &ret);
    clBuildProgram(pgm2, 1, &devID, NULL, NULL, NULL);

    cl_kernel kernel1 = clCreateKernel(pgm1, "oddEven", &ret);
    cl_kernel kernel2 = clCreateKernel(pgm2, "evenOdd", &ret);

    clSetKernelArg(kernel1, 0, sizeof(cl_mem), &aMemObj);
    clSetKernelArg(kernel2, 0, sizeof(cl_mem), &aMemObj);

    size_t globalWorkSize = n;
    size_t localWorkSize = 1;

    for (int i = 1; i <= (n + 1) / 2; i++)
    {
        clEnqueueNDRangeKernel(cq, kernel1, 1, NULL, &globalWorkSize, &localWorkSize, 0, NULL, NULL);
        clEnqueueNDRangeKernel(cq, kernel2, 1, NULL, &globalWorkSize, &localWorkSize, 0, NULL, NULL);
    }

    clFinish(cq);

    clEnqueueReadBuffer(cq, aMemObj, CL_TRUE, 0, n * sizeof(int), A, 0, NULL, NULL);

    printf("Sorted Array is\n");
    for (int i = 0; i < n; i++)
    {
        printf("%i ", A[i]);
    }
    printf("\n");

    ret = clFlush(cq);
    ret = clReleaseKernel(kernel1);
    ret = clReleaseKernel(kernel2);
    ret = clReleaseProgram(pgm1);
    ret = clReleaseProgram(pgm2);
    ret = clReleaseMemObject(aMemObj);
    ret = clReleaseCommandQueue(cq);
    ret = clReleaseContext(context);
    return 0;
}
