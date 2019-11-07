#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int pid;
	int startTime, endTime;
	struct node* next;
	struct node* prev;
} GanttNode;

typedef GanttNode* GanttChart;

// GanttChart
void insertIntoChart(GanttChart* chart, int pid, int startTime, int endTime)
{
	GanttChart temp = malloc(sizeof(GanttNode));
	temp->pid = pid;
	temp->startTime = startTime;
	temp->endTime = endTime;
	temp->next = NULL;

	if(*chart == NULL)
	{
		temp->prev = NULL;
		*chart = temp;
		return;
	}
	
	GanttChart temp2;
	for(temp2 = *chart; temp2->next != NULL; temp2 = temp2->next);

	temp2->next = temp;
	temp->prev = temp2;
	// return chart;
	
}void printGChart(GanttChart gc)
{
	for(GanttChart temp = gc; temp != NULL; temp = temp->next)
	{
		//Implement continuous blocks of time instead of one second at a time
		printf("Process %i executes from %i to %i\n", temp->pid, temp->startTime, temp->endTime);
	}
}

void computeFT(GanttChart gc, int*** mat, int n)
{
	GanttChart temp;
	for(temp = gc; temp->next != NULL; temp = temp->next);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if((*mat)[j][0] == temp->pid && (*mat)[j][5] == 0)
			{
				(*mat)[j][5] = temp->endTime;
				temp = temp->prev;
				break;
			}
		}
	}
}

void fillRemainingMatrix(int*** matPtr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		(*matPtr)[i][3] = (*matPtr)[i][5] - (*matPtr)[i][1];
		(*matPtr)[i][4] = (*matPtr)[i][3] - (*matPtr)[i][2];
	}
}

void sortProcessesWrtAT(int*** mat, int n)
{
	
	for(int i=0; i<n-1; i++)
	{
		for (int j = 0; j < n - i - 1; ++j)
		{
			if((*mat)[j][1] > (*mat)[j+1][1])
			{
				// printf("all okay. Now swapping\n");
				int* temp = (*mat)[j];
				(*mat)[j] = (*mat)[j+1];
				(*mat)[j+1] = temp;
			}
		}
	}

	// return mat;
}