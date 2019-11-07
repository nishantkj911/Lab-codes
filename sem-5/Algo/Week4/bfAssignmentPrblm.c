#include <stdio.h>
#include <stdlib.h>

int* genPermutations(int* arr, int* finArr, int tempSize, int n, int** costMatrix)
{
	// static int* finArr = (int*) malloc(sizeof(int) * n);
	static int minSum = 2147483647;
	if(tempSize == 1)
	{
		int tempSum = 0;
		for (int i = 0; i < n; ++i)
		{
			tempSum+=costMatrix[i][arr[i]];
			// printf("%i ", arr[i]);
		}
		// printf("\nsum = %i\n", tempSum);
		if(tempSum < minSum)
		{
			for (int i = 0; i < n; ++i)
			{
				finArr[i] = arr[i];
				minSum = tempSum;
			}
		}
		/*printf("finArr is\n");
		for (int i = 0; i < n; ++i)
		{
			printf("%i ", finArr[i]);
		}
		printf("\n\n");
		printf("minSum = %i\n", minSum);*/

		return finArr;
	}

	for (int i = n - tempSize; i < n; ++i)
	{
		//swapping the first element of remaining array with rest of the elements
		int temp = arr[n - tempSize];
		arr[n - tempSize] = arr[i];
		arr[i] = temp;

		genPermutations(arr, finArr, tempSize-1, n, costMatrix);

		//undoing the swapping
		temp = arr[n - tempSize];
		arr[n - tempSize] = arr[i];
		arr[i] = temp;
	}

	return finArr;
}

int main()
{
	printf("No. of people or jobs: ");
	int n;
	scanf("%i", &n);
	int arr[n];
	for(int i=0; i<n; i++)
	{
		arr[i] = i;
	}

	printf("Enter the cost matrix\n");
	int** costMatrix = (int**) malloc(sizeof(int*) * n);
	for (int i = 0; i < n; ++i)
	{
		costMatrix[i] = malloc(sizeof(int) * n);
		for (int j = 0; j < n; ++j)
		{
			scanf("%i", &costMatrix[i][j]);
		}
	}

	int* finArr = (int*) malloc(sizeof(int) * n);
	finArr = genPermutations(arr, finArr, n, n, costMatrix);

	int sum = 0;
	// printf("permutations done\n");
	for (int i = 0; i < n; ++i)
	{
		sum+=costMatrix[i][finArr[i]];
		printf("Person %i gets Job %i \n", i+1, finArr[i] + 1);
	}
	printf("\n");
	printf("The minimum cost is %i\n", sum);
	return 0;
}