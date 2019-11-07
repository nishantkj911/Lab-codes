#include <stdio.h>
#include <CL/cl.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SOURCE_SIZE (0x100000)
int main()
{

	char *str = calloc(BUFSIZ, sizeof(char));
	char *ans = calloc(BUFSIZ, sizeof(char));

	printf("enter the string");
	scanf("%[^\n]%*c", str);
	int lenString = strlen(str), k = 0;
	printf("enter the word");
	scanf("%s", ans);
	int lenWord = strlen(ans);
	int *index = calloc(20, sizeof(int));
	index[k++] = -1;
	for (int i = 0; i < lenString; i++)
	{
		if (str[i] == ' ')
			index[k++] = i;
	}
	index[k++] = lenString;
	int lenArrayMode[1];
	lenArrayMode[0] = lenWord;

	int *ansArray = calloc(k - 1, sizeof(int));

	printf("Index array\n");
	for (int i = 0; i < k; i++)
	{
		printf("%i ", index[i]);
	}
	printf("\n");

	FILE *fp;
	char *source_str;
	size_t source_size;
	fp = fopen("find.cl", "r");
	if (!fp)
	{
		fprintf(stderr, "Failed to load kernel.\n");
		getchar();
		exit(1);
	}
	source_str = (char *)malloc(MAX_SOURCE_SIZE);
	source_size = fread(source_str, 1, MAX_SOURCE_SIZE, fp);
	fclose(fp);
	cl_platform_id platform_id = NULL;
	cl_device_id device_id = NULL;
	cl_uint ret_num_devices;
	cl_uint ret_num_platforms;

	cl_int ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
	ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_GPU, 1, &device_id, &ret_num_devices);

	cl_context context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);
	cl_command_queue command_queue = clCreateCommandQueue(context, device_id, NULL, &ret);

	cl_mem a_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, lenString * sizeof(char), NULL, &ret);
	cl_mem b_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, lenWord * sizeof(char), NULL, &ret);
	cl_mem c_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, k * sizeof(int), NULL, &ret);
	cl_mem len_mem_obj = clCreateBuffer(context, CL_MEM_READ_WRITE, sizeof(int), NULL, &ret);
	cl_mem num_mem_obj = clCreateBuffer(context, CL_MEM_READ_WRITE, (k - 1) * sizeof(int), NULL, &ret);

	ret = clEnqueueWriteBuffer(command_queue, a_mem_obj, CL_TRUE, 0, lenString * sizeof(char), str, 0, NULL, NULL);
	ret = clEnqueueWriteBuffer(command_queue, b_mem_obj, CL_TRUE, 0, strlen(ans) * sizeof(char), ans, 0, NULL, NULL);
	ret = clEnqueueWriteBuffer(command_queue, c_mem_obj, CL_TRUE, 0, k * sizeof(int), index, 0, NULL, NULL);
	ret = clEnqueueWriteBuffer(command_queue, len_mem_obj, CL_TRUE, 0, sizeof(int), &lenWord, 0, NULL, NULL);
	ret = clEnqueueWriteBuffer(command_queue, num_mem_obj, CL_TRUE, 0, (k - 1) * sizeof(int), ansArray, 0, NULL, NULL);

	cl_program program = clCreateProgramWithSource(context, 1, (const char **)&source_str, (const size_t *)&source_size, &ret);
	ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);

	cl_kernel kernel = clCreateKernel(program, "find", &ret);

	ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&a_mem_obj);
	ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&b_mem_obj);
	ret = clSetKernelArg(kernel, 2, sizeof(cl_mem), (void *)&c_mem_obj);
	ret = clSetKernelArg(kernel, 3, sizeof(cl_mem), &len_mem_obj);
	ret = clSetKernelArg(kernel, 4, sizeof(cl_mem), &num_mem_obj);

	size_t global_item_size = k - 1;
	size_t local_item_size = 1;

	ret = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, &global_item_size, &local_item_size, 0, NULL, NULL);
	ret = clFinish(command_queue);

	ret = clEnqueueReadBuffer(command_queue, num_mem_obj, CL_TRUE, 0, (k - 1) * sizeof(int), ansArray, 0, NULL, NULL);
	int sum = 0;
	for (int i = 0; i < k - 1; i++)
	{
		sum += ansArray[i];
	}

	printf("Answer: %i\n", sum);

	ret = clFlush(command_queue);
	ret = clReleaseKernel(kernel);
	ret = clReleaseProgram(program);
	ret = clReleaseMemObject(a_mem_obj);
	ret = clReleaseMemObject(c_mem_obj);
	ret = clReleaseCommandQueue(command_queue);
	ret = clReleaseContext(context);
	free(str);
	getchar();
	return 0;
}
