#include <CL/cl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SOURCE_SIZE (0x1000000)

//the output comes same as input. the kernel is not printing anything
int main(int argc, char const *argv[])
{
    char *str = calloc(BUFSIZ, sizeof(char));
    char *str2 = calloc(BUFSIZ, sizeof(char));
    printf("Enter the string to be reversed\n");
    scanf("%[^\n]%*c", str);

    int n[1];
    n[0] = strlen(str);

    FILE *fp = fopen("revStringKernel.cl", "r");
    if (!fp)
    {
        printf("Cannot open kernel\n");
        exit(EXIT_FAILURE);
    }

    char *pgmStr = calloc(MAX_SOURCE_SIZE, sizeof(char));
    size_t pgmSize = fread(pgmStr, sizeof(char), MAX_SOURCE_SIZE, fp);
    fclose(fp);

    cl_platform_id plt;
    cl_device_id devid;
    cl_uint retNumDev, retNumPlt;
    cl_int ret;

    clGetPlatformIDs(1, &plt, &retNumPlt);
    clGetDeviceIDs(plt, CL_DEVICE_TYPE_GPU, 1, &devid, &retNumDev);

    cl_context context = clCreateContext(NULL, 1, &devid, NULL, NULL, &ret);
    cl_command_queue cq = clCreateCommandQueue(context, devid, NULL, &ret);

    cl_mem aMemObj = clCreateBuffer(context, CL_MEM_READ_WRITE, sizeof(char) * n[0], NULL, &ret);
    cl_mem bMemObj = clCreateBuffer(context, CL_MEM_READ_ONLY, sizeof(int), NULL, &ret);

    ret = clEnqueueWriteBuffer(cq, aMemObj, CL_TRUE, 0, n[0] * sizeof(char), str, 0, NULL, NULL);
    printf("%i\n", n[0]);
    ret = clEnqueueWriteBuffer(cq, bMemObj, CL_TRUE, 0, sizeof(int), n, 0, NULL, NULL);

    cl_program pgm = clCreateProgramWithSource(context, 1, &pgmStr, &pgmSize, &ret);
    clBuildProgram(pgm, 1, &devid, NULL, NULL, NULL);

    cl_kernel kernel = clCreateKernel(pgm, "revString", &ret);

    clSetKernelArg(kernel, 0, sizeof(cl_mem), &aMemObj);
    clSetKernelArg(kernel, 1, sizeof(cl_mem), &bMemObj);

    size_t globalWorkSize = n[0] / 2;
    size_t localWorkSize = 1;

    ret = clEnqueueNDRangeKernel(cq, kernel, 1, NULL, &globalWorkSize, &localWorkSize, 0, NULL, NULL);
    ret = clFinish(cq);

    clEnqueueReadBuffer(cq, aMemObj, CL_TRUE, 0, n[0] * sizeof(char), str2, 0, NULL, NULL);

    printf("The reversed string is '%s'\n", str2);

    ret = clFlush(cq);
    ret = clReleaseKernel(kernel);
    ret = clReleaseProgram(pgm);
    ret = clReleaseMemObject(aMemObj);
    ret = clReleaseCommandQueue(cq);
    ret = clReleaseContext(context);
    return 0;
}
