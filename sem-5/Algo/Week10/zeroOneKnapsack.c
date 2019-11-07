#include <stdio.h>
#include <stdlib.h>

void takeInput(int* n, int** weights, int** values, int* wKnapsack)
{
	//Figure out implementation
}

typedef int** Matrix;

int max(int a, int b)
{
	return a > b ? a : b;
}

void solveKnapsack(Matrix* Mat, int* w, int* v, int n, int wKnapsack)
{	
	Matrix mat = *Mat;
	for (int i = 0; i <= n; ++i)
	{
		mat[i] = calloc(wKnapsack + 1, sizeof(int));
		if(i == 0) continue;

		for (int j = 0; j <= wKnapsack; ++j)
		{
			if(j - w[i-1] < 0)
				mat[i][j] = mat[i-1][j];
			else
			{
				mat[i][j] = max(mat[i-1][j], v[i-1] + mat[i-1][j - w[i-1]]);
				
			}
			
		}
	}
}

int main(int argc, char const *argv[])
{
	// int* weights, *values, n, wKnapsack;
	int n, wKnapsack;
	printf("Enter the no. of elements\n");
	scanf("%i", &n);

	int* w = (int*) calloc(n, sizeof(int));
	int* v = (int*) calloc(n, sizeof(int));

	printf("Enter the weights and their corresponding values\n");
	for (int i = 0; i < n; ++i)
	{
		scanf("%i %i", &w[i], &v[i]);
	}

	printf("Enter the total weight of Knapsack\n");
	scanf("%i", &wKnapsack);

	/*weights = &w;
	values = &v;
	takeInput(&n, &weights, &values, &wKnapsack);*/

	/*printf("The weights and values of each elements\n");
	for (int i = 0; i < n; ++i)
	{
		printf("For element %i, weight: %x\tvalue: %x\n", i, w[i], v[i]);
	}*/


	Matrix weightItemMatrix = calloc(n + 1, sizeof(int*));
	solveKnapsack(&weightItemMatrix, w, v, n, wKnapsack);

	printf("Matrix at the end is\n");
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= wKnapsack; ++j)
		{
			printf("%i\t", weightItemMatrix[i][j]);
		}
		printf("\n");
	}

	printf("The max value which can be obtained is %i\n", weightItemMatrix[n][wKnapsack]);
	//backtrack the ans

	int* arr = calloc(n, sizeof(int));
	for (int i = n, j = wKnapsack; i > 0; --i)
	{
		if(weightItemMatrix[i][j] > weightItemMatrix[i-1][j]) 
		{
			arr[i-1] = 1;
			j -= w[i-1];
			printf("shifting left: %i for i: %i\n", w[i], i);
		}
	}

	//not coming correct. element 2 is also included which is wrong
	printf("The items included are: \n");
	for (int i = 0; i < n; ++i)
	{
		if (arr[i])
		{
			printf("%i ", i);
		}
	}
	printf("\n");
	return 0;
}