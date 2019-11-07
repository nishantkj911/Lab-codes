#include <CL/cl.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SOURCE_SIZE (0x100000000)

int main(int argc, char const *argv[])
{
    int row, col;
    printf("Enter the no. of rows and columns\n");
    scanf("%i %i", &row, &col);

    int len = row * col;
    int mat[len];
    int mat2[len];

    printf("Enter the elemenets of the matrix\n");
    for (int i = 0; i < len; i++)
    {
        scanf("%i", &mat[i]);
    }

    FILE *fp = fopen("nonBorderReplKernel.cl", "r");
    if (fp == NULL)
    {
        printf("Cannot open kernel\n");
        return 1;
    }

    char *pgmStr = calloc(MAX_SOURCE_SIZE, sizeof(char));
    size_t pgmSize = fread(pgmStr, sizeof(char), MAX_SOURCE_SIZE, fp);

    cl_platform_id plt;
    cl_device_id devID;
    cl_uint retNumDev, retNumPlt;
    cl_int ret;

    clGetPlatformIDs(1, &plt, &retNumPlt);
    clGetDeviceIDs(plt, CL_DEVICE_TYPE_GPU, 1, &devID, &retNumDev);

    cl_context context = clCreateContext(NULL, 1, &devID, NULL, NULL, &ret);
    cl_command_queue cq = clCreateCommandQueue(context, devID, NULL, &ret);

    cl_mem aMemObj = clCreateBuffer(context, CL_MEM_READ_ONLY, sizeof(int) * len, NULL, &ret);
    cl_mem bMemObj = clCreateBuffer(context, CL_MEM_WRITE_ONLY, sizeof(int) * len, NULL, &ret);

    clEnqueueWriteBuffer(cq, aMemObj, CL_TRUE, 0, len * sizeof(int), mat, 0, NULL, NULL);

    cl_program pgm = clCreateProgramWithSource(context, 1, &pgmStr, &pgmSize, &ret);
    clBuildProgram(pgm, 1, &devID, NULL, NULL, NULL);

    cl_kernel kernel = clCreateKernel(pgm, "replFunc", &ret);

    clSetKernelArg(kernel, 0, sizeof(cl_mem), &aMemObj);
    clSetKernelArg(kernel, 1, sizeof(cl_mem), &bMemObj);

    size_t globalWorkSize[] = {col, row};
    size_t localWorkSize[] = {1, 1};

    ret = clEnqueueNDRangeKernel(cq, kernel, 2, NULL, globalWorkSize, localWorkSize, 0, NULL, NULL);
    clFinish(cq);

    clEnqueueReadBuffer(cq, bMemObj, CL_TRUE, 0, sizeof(int) * len, mat2, 0, NULL, NULL);

    for (int i = 0; i < len; i++)
    {
        printf("%i ", mat2[i]);
        if (i % col == col - 1)
        {
            printf("\n");
        }
    }
    printf("\n");

    return 0;
}
