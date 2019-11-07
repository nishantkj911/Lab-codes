#include "graph.h"
#include "stack.h"

void dfsTopo(AdjMatrix adjM, int n)
{
	int startDFS = -1;
	for (int i = 0; i < n; ++i)
	{
		int noIncomingEdgesFlag = 0;
		for (int j = 0; j < n; ++j)
		{
			if(adjM[j][i] == 1)
			{
				noIncomingEdgesFlag = 1;
				break;
			}
		}
		if(noIncomingEdgesFlag == 0)
		{
			startDFS = i;
			// printf("breaking when %i\n", i);
			break;
		}
	}

	/*int startDFS = -1;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (adjM[j][i] == 1)
			{
				break;
			}
		}
		startDFS = i;
		break;
		
	}*/

	if(startDFS == -1)
	{
		printf("Cannot do topological Sorting in the graph\n");
		return;
	}
	
	Stack st = NULL;
	int* pushOrder = malloc(sizeof(int) * n);
	int* popOrder = malloc(sizeof(int) * n);
	int* visited = malloc(sizeof(int) * n);
	int pushIter = -1, popIter = -1;


	st = push(st, startDFS);
	pushOrder[++pushIter] = startDFS;
	// printf("pushing %i\n", startDFS);

	int next;
	while(peek(st) != -1 || ((next = checkAllVisited(visited, n)) && next != -1))
	{
		if(st == NULL)
		{
			// printf("Starting second\n");
			pushOrder[++pushIter] = next;
			st = push(st, next);
		}
		int wnode = peek(st);
		// printf("working with %i\n", wnode);
		visited[wnode] = 1;
		// int nextPush = -1;

		int flag = 0;
		for (int i = 0; i < n; ++i)
		{
			if(adjM[wnode][i] == 1 && visited[i] == 0)
			{
				flag = 1;
				st = push(st, i);
				// printf("pushing %i\n", i);
				pushOrder[++pushIter] = i;
				break;
			}

		}

		if(flag == 0)
		{
			// printf("popping %i\n", wnode);
			popOrder[++popIter] = wnode;
			st = pop(st);
			// printf("Next item is %i\n", peek(st));
		}
	}

	/*printf("Push order:\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%i ", pushOrder[i]);
	}
	printf("\n");


	printf("Pop order:\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%i ", popOrder[i]);
	}
	printf("\n");*/

	printf("Topological sorting order:\n");
	for (int i = n-1; i >= 0; --i)
	{
		printf("%i ", popOrder[i]);
	}
	printf("\n");

}

int main(int argc, char const *argv[])
{
	int n;
	printf("Enter the no. of nodes in the graph\n");
	scanf("%i", &n);

	AdjMatrix  adjM = createGraph(n);

	displayAdjMatrix(adjM, n);
	dfsTopo(adjM, n);
	return 0;
}