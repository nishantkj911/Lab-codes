#include <stdio.h>
#include <stdlib.h>

void printMatrix(int** mat, int r, int c, char* name)
{
	printf("The %s matrix is\n", name);
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			printf("%i ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int compareLess(int* arr1, int* arr2, int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (arr1[i] > arr2[i])
		{
			return 0;
		}
	}

	return 1;
}

int checkAllFinished(int* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		if(!arr[i])
			return 0;
	}

	return 1;
}

int main(int argc, char const *argv[])
{
	printf("Enter the no. of resources\n");
	int res;
	scanf("%i", &res);
	
	printf("Enter the no. of processes\n");
	int proc;
	scanf("%i", &proc);

	int available[res];
	printf("Give the no. of instances available for each resources\n");
	for (int i = 0; i < res; ++i)
	{
		scanf("%i", &available[i]);
	}

	printf("Give the requested resources for each process\n");
	int** request = calloc(proc, sizeof(int*));
	for (int i = 0; i < proc; ++i)
	{
		printf("For process %i\n", i);
		request[i] = calloc(res, sizeof(int));
		for (int j = 0; j < res; ++j)
		{
			scanf("%i", &request[i][j]);
		}
	}

	printf("Give the allocated resources for each process\n");
	int** allocation = calloc(proc, sizeof(int*));
	for (int i = 0; i < proc; ++i)
	{
		printf("For process %i\n", i);
		allocation[i] = calloc(res, sizeof(int));
		for (int j = 0; j < res; ++j)
		{
			scanf("%i", &allocation[i][j]);
		}
	}

	printMatrix(request, proc, res, "Request");
	printMatrix(allocation, proc, res, "Allocation");


	int work[res];
	int* finish = calloc(proc, sizeof(int));
	for (int i = 0; i < res; ++i)
	{
		work[i] = available[i];
	}

	int found;
	do
	{
		found = 0;
		for (int i = 0; i < proc; ++i)
		{
			if (!finish[i] && compareLess(request[i], work, res))
			{
				found = 1;
				for (int j = 0; j < res; ++j)
				{
					work[j]+=allocation[i][j];
				}
				finish[i] = 1;
			}
		}
	}while(found);

	if(checkAllFinished(finish, proc))
	{
		printf("The system is in a safe state\n");
	}
	else
	{
		printf("The system is DEADLOCKED!!!\nThe processes involved in it are\n");
		for (int i = 0; i < proc; ++i)
		{
			!finish[i] ? printf("%i ", i) : 1;
		}
		printf("\n");
	}

	return 0;
}