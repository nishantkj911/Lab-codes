#include "header.h"

typedef struct arr
{
	int size;
	int* arr;
} Array;

Array createArray()
{
	Array arr;
	printf("Enter the no. of elements\n");
	scanf("%i", &arr.size);


	arr.arr = (int*) malloc(sizeof(int) * arr.size);
	for (int i = 0; i < arr.size; ++i)
	{
		scanf("%i", &arr.arr[i]);
	}

	return arr;
}

void* sumFun(void* arr)
{
	Array* arrPtr = (Array*) arr;

	int* sum = malloc(sizeof(int));
	sum[0] = 0;
	// printf("Sum start\n");
	for (int i = 0; i < arrPtr->size; ++i)
	{
		if(arrPtr->arr[i] >= 0)
		{
			sum[0] += arrPtr->arr[i];
		}
	}

	// printf("sum done %i\n", sum[0]);
	return (void*) sum;
}

int main(int argc, char const *argv[])
{
	Array arr = createArray();
	Array* arrPtr;
	pthread_t thid;
	int* sum;
	pthread_create(&thid, 0, &sumFun, (void*) &arr);
	pthread_join(thid, &sum);

	printf("%i\n", sum[0]);
	return 0;
}