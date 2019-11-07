#include "dynArray.h"

int count = 0;
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(DynamicArray* arr, int left, int right)
{
	/*if(left == right)
		return left;*/
	int pivot = arr->arr[left];
	// printf("pivot is %i with index %i\n", pivot, left);
	int div = right, i=left+1;

	for (i = left; i != div; ++i)
	{
		if (count++ && arr->arr[i] > pivot)
		{
			swap(&arr->arr[i], &arr->arr[div--]);
			i--;
		}
	}

	if(arr->arr[div] > pivot)
		div--;

	arr->arr[left] = arr->arr[div];
	arr->arr[div] = pivot;	
	return div;	
}

void quickSort(DynamicArray* arr, int left, int right)
{
	// printf("\nSorting with indices %i and %i\n", left, right);
	if(left >= right)
		return;
	int middle = partition(arr, left, right);
	// printf("middle is %i\n", middle);
	// printDynArr(*arr);
	quickSort(arr, left, middle-1);
	quickSort(arr, middle+1, right);
}

int main(int argc, char const *argv[])
{
	DynamicArray arr = createDynArr();

	quickSort(&arr, 0, arr.size);
	printf("Sorted Array is\n");
	
	count=0;
	quickSort(&arr, 0, arr.size);
	printDynArr(arr);

	printf("no. of operations:  %i\n", count);
	return 0;
}