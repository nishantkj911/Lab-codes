#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct _dynArray
{
	int maxSize, size;
	int* arr;
} DynamicArray;

void insertIntoDynArr(DynamicArray* dyn, int key)
{
	if(++dyn->size == dyn->maxSize)
	{
		dyn->arr = realloc(dyn->arr, sizeof(int) * dyn->maxSize * 2);
		dyn->maxSize*=2;
	}

	dyn->arr[dyn->size] = key;
	// return dyn;
}

DynamicArray createDynArr()
{
	DynamicArray dyn;
	dyn.maxSize = 1;
	dyn.arr = (int*) malloc(sizeof(int));
	dyn.size = -1;

	printf("Enter elements or press 'Ctrl + D' to end\n");
	int temp;
	while(1)
	{
		int res = scanf("%i", &temp);

		if(res == EOF)
			break;

		if(res != 1)
		{
			fprintf(stderr, "%s\n", "Enter proper Input");
			continue;
		}

		insertIntoDynArr(&dyn, temp);
	}
	return dyn;
}

// DynamicArray

int getDynArr(DynamicArray dyn, int index)
{
	if(dyn.size == -1)
	{
		fprintf(stderr, "%s\n", "Empty Array");
		return INT_MIN;
	}
	if(index < 0 || index > dyn.size)
	{
		fprintf(stderr, "%s\n", "Array index out of bounds");
		return INT_MIN;
	}

	return dyn.arr[index];
}

void printDynArr(DynamicArray dyn)
{
	// printf("size %i\n", dyn.size);
	for (int i = 0; i <= dyn.size; ++i)
	{
		printf("%i ", dyn.arr[i]);
	}
	printf("\n");
}