#include <CL/cl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SOURCE_SIZE (0x10000000)

int main(int argc, char const *argv[])
{
    char *str1 = calloc(BUFSIZ, sizeof(char));
    str1 = memset(str1, '\0', BUFSIZ);
    printf("Enter the string to be copied\n");
    scanf("%s", str1);

    int n;
    printf("Enter the no. of times to be copied\n");
    scanf("%i", &n);

    int len[1];
    len[0] = strlen(str1);
    char *str2 = calloc(len[0] * n, sizeof(char));
    str2 = memset(str2, '\0', len[0] * n);
    printf("The string is '%s' and length is %i\n", str1, len[0]);
    FILE *fp = fopen("copyStringKernel.cl", "r");
    if (fp == NULL)
    {
        printf("Couldn't open kernel\n");
        exit(EXIT_FAILURE);
    }

    char *pgmStr = calloc(MAX_SOURCE_SIZE, sizeof(char));
    size_t pgmSize = fread(pgmStr, sizeof(char), MAX_SOURCE_SIZE, fp);
    fclose(fp);

    cl_platform_id plt;
    cl_device_id devid;
    cl_uint retDevNum, retPltNum;
    cl_int ret;

    clGetPlatformIDs(1, &plt, &retPltNum);
    clGetDeviceIDs(plt, CL_DEVICE_TYPE_GPU, 1, &devid, &retDevNum);

    cl_context context = clCreateContext(NULL, 1, &devid, NULL, NULL, &ret);
    cl_command_queue cq = clCreateCommandQueue(context, devid, NULL, &ret);

    cl_mem aMemObj = clCreateBuffer(context, CL_MEM_READ_ONLY, len[0] * sizeof(char), NULL, &ret);
    cl_mem bMemObj = clCreateBuffer(context, CL_MEM_WRITE_ONLY, n * len[0] * sizeof(char), NULL, &ret);
    cl_mem lenMemObj = clCreateBuffer(context, CL_MEM_READ_ONLY, sizeof(int), NULL, &ret);

    clEnqueueWriteBuffer(cq, aMemObj, CL_TRUE, 0, len[0] * sizeof(char), str1, 0, NULL, NULL);
    clEnqueueWriteBuffer(cq, lenMemObj, CL_TRUE, 0, sizeof(int), len, 0, NULL, NULL);

    cl_program pgm = clCreateProgramWithSource(context, 1, &pgmStr, &pgmSize, &ret);
    ret = clBuildProgram(pgm, 1, &devid, NULL, NULL, NULL);

    cl_kernel kernel = clCreateKernel(pgm, "copyString", &ret);

    clSetKernelArg(kernel, 0, sizeof(cl_mem), &aMemObj);
    clSetKernelArg(kernel, 1, sizeof(cl_mem), &bMemObj);
    clSetKernelArg(kernel, 2, sizeof(cl_mem), &lenMemObj);

    size_t globalWorkSize = n;
    size_t localWorkSize = 1;

    clEnqueueNDRangeKernel(cq, kernel, 1, NULL, &globalWorkSize, &localWorkSize, 0, NULL, NULL);
    ret = clFinish(cq);

    clEnqueueReadBuffer(cq, bMemObj, CL_TRUE, 0, n * sizeof(char) * len[0], str2, 0, NULL, NULL);

    printf("The new string formed is %i\n'%s'\n", str2[0], str2);

    ret = clFlush(cq);
    ret = clReleaseKernel(kernel);
    ret = clReleaseProgram(pgm);
    ret = clReleaseMemObject(bMemObj);
    ret = clReleaseMemObject(aMemObj);
    ret = clReleaseCommandQueue(cq);
    ret = clReleaseContext(context);

    free(str1);
    free(str2);
    return 0;
}
