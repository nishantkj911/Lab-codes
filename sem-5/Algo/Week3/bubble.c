#include <stdio.h>
#include <stdlib.h>

int* bubbleSort(int* arr, int n)
{
	int basicOp=0;
	for (int i = 0; i < n-1; ++i)
	{
		for (int j = 1; j < n - i; ++j)
		{
			basicOp++;
			if(arr[j] < arr[j-1])
			{
				int temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}
	}
	printf("Number of basic operations conducted is %i\n", basicOp);
}

int main(int argc, char const *argv[])
{
	printf("Enter the no. of integers to be entered:\n");
	int n;
	int r = scanf("%i", &n);
	if(r != 1)
	{
		printf("Enter proper input\n");
		exit(0);
	}

	int arr[n];
	printf("Enter the array\n");
	for (int i = 0; i < n; ++i)
	{
		scanf("%i", &arr[i]);
	}

	// int * arr2 = bubbleSort(arr, n);
	bubbleSort(arr, n);
	printf("The sorted array is\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%i ", arr[i]);
	}	
	printf("\n");
	return 0;
}