#include "dynArray.h"

// DynamicArray
void merge(DynamicArray* arr, int left, int leftEnd, int rightStart, int right)
{
	int* newArr = (int*) malloc(sizeof(int) * arr->maxSize);
	int i=left, j=rightStart, k=0;

	// printf("size = %i\n", arr->size);

	while(i <= leftEnd && j <= right)
	{
		// printf("Collective Merging\n");
		if (arr->arr[i] < arr->arr[j])
		{
			// printf("Adding left\n");
			newArr[k++] = arr->arr[i++];
		}
		else 
		{
			//("Adding right\n");
			newArr[k++] = arr->arr[j++];
		}
	}

	if(i <= leftEnd)
	{
		while(i <= leftEnd)
		{
			// printf("Left Merging\n");
			newArr[k++] = arr->arr[i++];
		}
	}

	if(j <= right)
	{
		while(j <= right)
		{
			// printf("Right Merging\n");
			newArr[k++] = arr->arr[j++];
		}
	}

	// printf("Assigning array\n");
	for (int l = left, m=0; l <= right; ++l, m++)
	{
		arr->arr[l] = newArr[m];
	}

	// return arr;
}

// DynamicArray 
void mergeSort(DynamicArray* arr, int left, int right)
{
	if(left == right) return;
		// return arr;

	int middle = left + (right - left) / 2;
	// printf("Sorting left: %i, right: %i\n", left, middle);
	mergeSort(arr, left, middle);
	// printf("Sorting left: %i, right: %i\n", middle + 1, right);
	mergeSort(arr, middle + 1, right);
	// printf("Merging left: %i, right: %i\n", left, right);
	merge(arr, left, middle, middle + 1, right);

	// printf("Merge Done\n");
	// printDynArr(arr);
	/*for (int i = 0; i < arr->size; ++i)
	{
		printf("%i ", arr->arr[i]);
	}
	printf("\n");*/
}

int main(int argc, char const *argv[])
{
	DynamicArray arr = createDynArr();
	
	mergeSort(&arr, 0, arr.size);
	printDynArr(arr);
	return 0;
}