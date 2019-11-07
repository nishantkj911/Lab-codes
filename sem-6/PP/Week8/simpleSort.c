#include <stdio.h>
#include <stdlib.h>
#include <CL/cl.h>
#include <time.h>

#define MAX_SOURCE_SIZE (0x1000000)

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the no. of elements\n");
    scanf("%i", &n);

    int *A = calloc(n, sizeof(int));
    int *B = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%i", &A[i]);
    }

    cl_platform_id pl;
    cl_device_id devid;
    cl_uint ret_pl_num, ret_dev_nums;
    cl_int ret;

    ret = clGetPlatformIDs(1, &pl, &ret_pl_num);
    ret = clGetDeviceIDs(pl, CL_DEVICE_TYPE_GPU, 1, &devid, &ret_dev_nums);

    cl_context context = clCreateContext(NULL, 1, &devid, NULL, NULL, &ret);
    cl_command_queue cq = clCreateCommandQueue(context, devid, NULL, &ret);

    cl_mem aMemObj = clCreateBuffer(context, CL_MEM_READ_ONLY, n * sizeof(int), NULL, &ret);
    cl_mem bMemObj = clCreateBuffer(context, CL_MEM_WRITE_ONLY, n * sizeof(int), NULL, &ret);

    ret = clEnqueueWriteBuffer(cq, aMemObj, CL_TRUE, 0, n * sizeof(int), A, 0, NULL, NULL);

    FILE *fp = fopen("simpleSortKernel.cl", "r");
    if (fp == NULL)
    {
        printf("Cannot open kernel file\n");
        return 1;
    }

    char *prgrmStr = calloc(MAX_SOURCE_SIZE, sizeof(char));
    size_t prgrmSize = fread(prgrmStr, sizeof(char), MAX_SOURCE_SIZE, fp);
    fclose(fp);

    cl_program prgm = clCreateProgramWithSource(context, 1, &prgrmStr, &prgrmSize, &ret);
    ret = clBuildProgram(prgm, 1, &devid, NULL, NULL, NULL);

    cl_kernel kernel = clCreateKernel(prgm, "sort", &ret);

    clSetKernelArg(kernel, 0, sizeof(cl_mem), &aMemObj);
    clSetKernelArg(kernel, 1, sizeof(cl_mem), &bMemObj);

    size_t global_work_size = n;
    size_t local_work_size = 1;

    clEnqueueNDRangeKernel(cq, kernel, 1, NULL, &global_work_size, &local_work_size, 0, NULL, NULL);
    ret = clFinish(cq);

    ret = clEnqueueReadBuffer(cq, bMemObj, CL_TRUE, 0, n * sizeof(int), B, 0, NULL, NULL);

    printf("Sorted array is\n");
    for (int i = 0; i < n; i++)
    {
        printf("%i ", B[i]);
    }
    printf("\n");

    ret = clFlush(cq);
    ret = clReleaseKernel(kernel);
    ret = clReleaseProgram(prgm);
    ret = clReleaseMemObject(aMemObj);
    ret = clReleaseMemObject(bMemObj);
    ret = clReleaseCommandQueue(cq);
    ret = clReleaseContext(context);

    return 0;
}
