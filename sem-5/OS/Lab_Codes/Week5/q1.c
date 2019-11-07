#include "header.h"

void* fibGen(void* param)
{
	// printf("In thread\n");
	int num = (int) param;
	int* arr = malloc(sizeof(int) * num);
	// printf("%i\n", num);
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i < num; ++i)
	{
		arr[i] = arr[i-1] + arr[i-2];
	}

	/*for (int i = 0; i < num; ++i)
	{
		printf("%i ", arr[i]);
	}*/
	return (void*) arr;
}

int main(int argc, char const *argv[])
{
	pthread_t th;
	int num;
	printf("Enter the number of fibonaccis to generate\n");
	scanf("%i", &num);
	int* arr = malloc(sizeof(int) * num);

	pthread_create(&th, 0, &fibGen, (void*) num);
	pthread_join(th, (void **)&arr);
	// printf("BAck in main\n");

	for (int i = 0; i < num; ++i)
	{
		printf("%i ", arr[i]);
	}
	printf("\n");
	return 0;
}