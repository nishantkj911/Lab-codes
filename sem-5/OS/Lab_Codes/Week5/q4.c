#include "header.h"

typedef struct $
{
	int size;
	int* arr;
} Array;

void* sumEven(void* param)
{
	int* sum = malloc(sizeof(int));
	Array* arr = (Array*) param;
	for (int i = 0; i < arr->size; ++i)
	{
		if(arr->arr[i] % 2 == 0)
		{
			sum[0] += arr->arr[i];
		}
	}

	return (void*) sum;
}

void* sumOdd(void* param)
{
	int* sum = malloc(sizeof(int));
	Array* arr = (Array*) param;
	for (int i = 0; i < arr->size; ++i)
	{
		if(arr->arr[i] % 2 == 1)
		{
			sum[0] += arr->arr[i];
		}
	}

	return (void*) sum;
}

// make array dynamic
int main(int argc, char const *argv[])
{
	Array arr;
	printf("Enter the no. of numbers\n");
	scanf("%i", &arr.size);

	arr.arr = malloc(sizeof(int) * arr.size);

	for (int i = 0; i < arr.size; ++i)
	{
		scanf("%i", &arr.arr[i]);
	}

	pthread_t thEvenId, thOddId;
	
	pthread_attr_t attr1;
	pthread_attr_init(&attr1);
	pthread_attr_t attr2;
	pthread_attr_init(&attr2);
	
	pthread_create(&thEvenId, 0, &sumEven, &arr);
	pthread_create(&thOddId, 0, &sumOdd, &arr);

	int* sumEven,* sumOdd;

	pthread_join(thEvenId,(void**) &sumEven);
	pthread_join(thOddId, (void**) &sumOdd);

	printf("Even sum: %i\nOdd sum: %i\n", sumEven[0], sumOdd[0]);

	return 0;
}