#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <limits.h>

typedef struct $
{
	int** mat;
	int n;
} procStruct;

void* calcWT(void * param)
{
	procStruct* ps = (procStruct*) param;

	int n = ps->n;
	int time = 0;
	for (int i = 0; i < n; ++i)
	{
		int min = -1; // find min priority
		for (int j = 0; j < n; ++j)
		{
			if(min >= 0)
			{
				if (ps->mat[j][6] > 0 && ps->mat[j][0] < ps->mat[min][0]) //rem time > 0 
				{
					printf("Min changed to %i\n", j);
					min = j;
				}
			}
			else
			{
				min = i;
			}
		}

		time += ps->mat[min][2];
		ps->mat[min][6] = 0;
		for (int j = 0; j < n; ++j)
		 {
		 	if(ps->mat[j][6] > 0 && j != min)
		 	{
		 		ps->mat[j][3] = time;
		 	}
		 }

		ps->mat[min][5] = time; // setting final time to time
	}

}

void* calcTAT(void* param)
{
	procStruct* ps = (procStruct*) param;

	for (int i = 0; i < ps->n; ++i)
		
	{
		ps->mat[i][4] = ps->mat[i][5] - ps->mat[i][1];
	}
	for (int i = 0; i < ps->n; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			printf("%i\t", ps->mat[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	printf("No of proc\n");
	int n;
	scanf("%i", &n);

	int** mat = calloc(n, sizeof(int*));
	printf("Enter priority and burst time\n");
	int bt, pr;
	for (int i = 0; i < n; ++i)
	{
		scanf("%i %i", &pr, &bt);
		mat[i] = calloc(7, sizeof(int));
		mat[i][0] = pr;
		mat[i][1] = 0;
		mat[i][2] = bt;

		mat[i][6] = bt;
	}

	procStruct ps;
	ps.mat = mat;
	ps.n = n;

	pthread_t th[2];
	pthread_create(&th[0], NULL, &calcWT, &ps);
	pthread_join(th[0], NULL);

	pthread_create(&th[1], NULL, &calcTAT, &ps);
	pthread_join(th[1], NULL);

	return 0;
}