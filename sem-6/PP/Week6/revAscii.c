#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <CL/cl.h>

#define MAX_SOURCE_SIZE (0x1000000)

int main(int argc, char const *argv[])
{
    char *initString = calloc(BUFSIZ, sizeof(char));
    printf("Enter the string (all chars less than %c)\n", (char)100);
    scanf("%[^\n]%*c", initString);

    int len = strlen(initString);
    FILE *fp = fopen("revAsciiKernel.cl", "r");
    if (fp == NULL)
    {
        printf("Cannot open kernel\n");
        exit(EXIT_FAILURE);
    }

    char *pgmStr = calloc(MAX_SOURCE_SIZE, sizeof(char));
    size_t pgmSize = fread(pgmStr, sizeof(char), MAX_SOURCE_SIZE, fp);
    fclose(fp);

    cl_platform_id plt;
    cl_device_id devid;
    cl_uint retPltNum, retDevNum;
    cl_int ret;

    clGetPlatformIDs(1, &plt, &retPltNum);
    clGetDeviceIDs(plt, CL_DEVICE_TYPE_GPU, 1, &devid, &retDevNum);

    cl_context context = clCreateContext(NULL, 1, &devid, NULL, NULL, &ret);
    cl_command_queue cq = clCreateCommandQueue(context, devid, NULL, &ret);

    cl_mem aMemObj = clCreateBuffer(context, CL_MEM_READ_WRITE, len * sizeof(char), NULL, &ret);
    cl_mem bMemObj = clCreateBuffer(context, CL_MEM_READ_WRITE, len * sizeof(char), NULL, &ret);

    ret = clEnqueueWriteBuffer(cq, aMemObj, CL_TRUE, 0, len * sizeof(char), initString, 0, NULL, NULL);

    cl_program pgm = clCreateProgramWithSource(context, 1, &pgmStr, &pgmSize, &ret);
    clBuildProgram(pgm, 1, &devid, NULL, NULL, NULL);

    cl_kernel kernel = clCreateKernel(pgm, "revAscii", &ret);

    clSetKernelArg(kernel, 0, sizeof(cl_mem), &aMemObj);

    size_t globalWorkSize = len, localWorkSize = 1;

    ret = clEnqueueNDRangeKernel(cq, kernel, 1, NULL, &globalWorkSize, &localWorkSize, 0, NULL, NULL);
    ret = clFinish(cq);

    clEnqueueReadBuffer(cq, aMemObj, CL_TRUE, 0, len, initString, 0, NULL, NULL);

    printf("The final string is \n%s", initString);

    ret = clFlush(cq);
    ret = clReleaseKernel(kernel);
    ret = clReleaseProgram(pgm);
    ret = clReleaseMemObject(aMemObj);
    ret = clReleaseCommandQueue(cq);
    ret = clReleaseContext(context);
    return 0;
}
