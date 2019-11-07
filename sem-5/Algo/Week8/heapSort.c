#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


int isAHeap(int** Arr, int i, int n) //returns the index which has to be swapped with its parent and -1 if no swap required
{
	if(2 * i >= n)
		return -1;
	int* arr = *Arr;

	if(2 * i == n)
	{
		// printf("\tOnly child\n");
		if(arr[i] >= arr[n])
		{
			// printf("\tAll okay\n");
			return -1;
		}
		else
			return n;
	}
	else
	{
		// printf("\tTwo children\n");
		if(arr[i] >= arr[2 * i] && arr[i] >= arr[2 * i + 1])
		{
			// printf("\tAll okay\n");
			return -1;
		}
		else return arr[2 * i + 1] > arr[2 * i] ? 2 * i + 1 : 2 * i;
	}
}

void heapify(int** Arr, int n)
{
	int* arr = *Arr;

	for (int i = n / 2; i > 0; i--)
	{
		// printf("Working with %ith parent\n", i);
		int swap1, temp = i;
		while((swap1 = isAHeap(Arr, temp, n)) != -1)
		{
			// printf("Swapping %i with index %i and %i with index %i \n", arr[swap1], swap1, arr[temp], temp);
			swap(arr+swap1, arr+temp);
			temp = swap1;
		}
	}
}

void heapSort(int**Arr, int n)
{
	int* arr = *Arr;

	for (int i = n; i > 0; --i)
	{
		swap(&arr[1], &arr[i]);
		heapify(Arr, i-1);
	}
}

int main(int argc, char const *argv[])
{
	int n;
	printf("Enter the no. of elements\n"); 
	scanf("%i", &n);

	int* arr = (int*) calloc(n+1, sizeof(int));

	for (int i = 0; i < n; i++)
	{
		scanf("%i", &arr[i+1]);
	}

	heapify(&arr, n);

	heapSort(&arr, n);
	for (int i = 0; i < n; i++)
	{
		printf("%i ", arr[i+1]);
	}
	printf("\n");
	return 0;
}
