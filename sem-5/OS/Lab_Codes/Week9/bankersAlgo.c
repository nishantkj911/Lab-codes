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

void safetyAlgo(int** max, int** alloc, int** need, int* available, int proc, int res)
{
	int* finish = calloc(proc, sizeof(int));
	int* work = calloc(res, sizeof(int));
	for (int i = 0; i < res; ++i)
	{
		work[i] = available[i];
	}

	int* safeSeq = calloc(proc, sizeof(int));
	int iter = 0;

	int found;
	do
	{
		found = 0;
		for (int i = 0; i < proc; ++i)
		{
			if(!finish[i] && compareLess(need[i], work, res))
			{
				found = 1;
				safeSeq[iter++] = i;
				printf("Adding alloc of process %i to work\n", i);
				for (int j = 0; j < res; ++j)
				{
					work[j] = work[j] + alloc[i][j];
				}
				finish[i] = 1;
			}
		}

	}while(found);

	if(checkAllFinished(finish, proc))
	{
		printf("Safe sequence exists\n");
		for (int i = 0; i < proc; ++i)
		{
			printf("%i ", safeSeq[i]);
		}
		printf("\n");
	}
	else
	{
		printf("No safe sequence exists");
	}

}

int main(int argc, char const *argv[])
{
	printf("No. of resources\n");
	int res;
	scanf("%i", &res);

	printf("Enter the total no. of instances for each resource\n");
	int total[res];
	for (int i = 0; i < res; ++i)
	{
		printf("For resource %i: ", i+1);
		scanf("%i", total+i);
	}

	printf("No. of processes\n");
	int proc;
	scanf("%i", &proc);

	int** max = calloc(proc, sizeof(int*));
	printf("Enter the maximum allocations for each process\n");
	for (int i = 0; i < proc; ++i)
	{
		printf("For process %i\n", i+1);
		max[i] = calloc(res, sizeof(int*));
		for (int j = 0; j < res; ++j)
		{
			scanf("%i", &max[i][j]);
		}
	}
	
	int** alloc = calloc(proc, sizeof(int*));
	int** need = calloc(proc, sizeof(int*));
	printf("Enter the current allocations for each process\n");
	for (int i = 0; i < proc; ++i)
	{
		printf("For process %i\n", i+1);
		alloc[i] = calloc(res, sizeof(int*));
		need[i] = calloc(res, sizeof(int*));
		for (int j = 0; j < res; ++j)
		{
			scanf("%i", &alloc[i][j]);
			need[i][j] = max[i][j] - alloc[i][j];
		}
	}

	printMatrix(max, proc, res, "Max");
	printMatrix(alloc, proc, res, "Allocation");
	printMatrix(need, proc, res, "Need");

	

	printf("Enter no. of instances available for each resouce\n");
	int available[res];
	for (int i = 0; i < res; ++i)
	{
		printf("For resource %i\n", i);
		scanf("%i", &available[i]);
	}

	safetyAlgo(max, alloc, need, available, proc, res);

	//Additional requests need to be accomodated
	int c=1;
	
	while(c)
	{
		printf("Any additional requests? (1/0)\n");
		scanf("%i", &c);
		if(!c)
			break;

		printf("Which process is requesting?\n");
		int pr;
		scanf("%i", &pr);

		printf("How many instances of each resource is it requesting\n");
		int request[res];
		for (int i = 0; i < res; ++i)
		{
			scanf("%i", request + i);
		}

		if(!compareLess(request, need[pr], res))
		{
			printf("You cannot request more than your max allocation\n");
			continue;
		}

		if(!compareLess(request, available, res))
		{
			printf("You have to wait for resources to be freed\n");
			continue;
		}

		for (int i = 0; i < res; ++i)
		{
			available[i]-=request[i];
			alloc[pr][i]+=request[i];
			need[pr][i]-=request[i];
		}

		/*printMatrix(max, proc, res, "Max");
		printMatrix(alloc, proc, res, "Allocation");
		printMatrix(need, proc, res, "Need");*/

		safetyAlgo(max, alloc, need, available, proc, res);
	}
	return 0;
}