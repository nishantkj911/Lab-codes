#include "jobScheduling.h"

// int**

//Ma'am said in exam they would want to ask FOR EVERY SECOND if there are anymore processes and if yes, take input
int main(int argc, char const *argv[])
{
	printf("Enter the no. of processes\n");
	int no;
	scanf("%i", &no);

	int** mat = malloc(sizeof(int*) * no);
	for (int i = 0; i < no; ++i)
	{
		printf("For process %i (Arrival and Burst Time):", i+1);
		mat[i] = malloc(sizeof(int) * 6);
		mat[i][0] = i;
		scanf("%i %i", &mat[i][1], &mat[i][2]);
	}

	sortProcessesWrtAT(&mat, no);

	// printf("sorting done\n");

	GanttChart gc = NULL;
	int time = mat[0][1];
	for (int i = 0; i < no; ++i)
	{
		// printf("Process %i executes from %i to %i\n", i, time, time + mat[i][2]);
		insertIntoChart(&gc, mat[i][0], time, time + mat[i][2]);
		time += mat[i][2];
	}

	// printGChart(gc);
	computeFT(gc, &mat, no);

	fillRemainingMatrix(&mat, no);
	
	float avgWT = 0, avgTAT = 0;
	printf("\n");
	for (int i = 0; i < no; ++i)
	{
		printf("For process %i waiting time is %i and turn-around time is %i\n", mat[i][0], mat[i][4], mat[i][3]);
		avgWT += mat[i][4];
		avgTAT += mat[i][3];
	}
	avgTAT/=no;
	avgWT/=no;

	printf("Avg waiting time: %f\nAvg turn-around Time: %f\n", avgWT, avgTAT);
	return 0;
}