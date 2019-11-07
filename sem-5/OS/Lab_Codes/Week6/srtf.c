#include "jobScheduling.h"
#include <limits.h>

int findSRT(int** mat, int time, int n)
{
	int min = INT_MAX;
	int ret = -1;
	for (int i = 0; i < n; ++i)
	{
		if(mat[i][3] != 0 && time >= mat[i][1] && mat[i][3] < min) // '< min' implies that the one which arrived first
		{
			// printf("Found min at %i for process %i\n", time, mat[i][0]);
			min = mat[i][3];
			ret = mat[i][0];
		}
	}

	return ret;
}

int main(int argc, char const *argv[])
{
	
	printf("Enter the no. of processes\n");
	int n;
	scanf("%i", &n);

	int** mat = malloc(sizeof(int*) * n);
	for (int i = 0; i < n; ++i)
	{
		printf("For process %i (Arrival and Burst Time):", i+1);
		mat[i] = malloc(sizeof(int) * 7);
		mat[i][0] = i;
		scanf("%i %i", &mat[i][1], &mat[i][2]);
	}

	sortProcessesWrtAT(&mat, n);

	for (int i = 0; i < n; ++i)
	{
		mat[i][3] = mat[i][2];
	}
	int time = 0;
	int a = findSRT(mat, time, n);
	GanttChart gc = NULL;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			printf("%i ", mat[i][j]);
		}
		printf("\n");
	}
	while(a != -1)
	{
		// printf("inserting for process %i\n", a);
		insertIntoChart(&gc, a, time, ++time);
		mat[a][3]--;
		a = findSRT(mat, time, n);
	}


	printGChart(gc);
	return 0;
}