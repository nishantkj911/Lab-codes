#include "graph.h"

void sourceRemovalTopo(AdjMatrix adjM, int n)
{
	/*int start = -1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (adjM[j][i] == 1)
			{
				printf("breaking at %i\n", start);
				break;
			}
		}
		start = i;
		break;
	}*/

	
	// printf("start: %i\n", start);

	int* visited = (int*) malloc(sizeof(int) * n);
	int* order = (int*) malloc(sizeof(int) * n);
	int iter = -1;
	// order[++iter] = start;
	// while(checkAllVisited(visited, n) != -1)
	for (int x = 0; x < n; ++x)
	{
		if(x == n-1)
		{
			for (int i = 0; i < n; ++i)
			{
				if(adjM[i][i] == 0)
				{
					order[++iter] = i;
					
				}
			}
			continue;
		}
		int start = -1;
		for (int i = 0; i < n; ++i)
		{

			// printf("checking for node %i\n", i);
			int noIncomingEdgesFlag = 0;
			int pro = 1;
			for (int j = 0; j < n; ++j)
			{
				if(adjM[j][i] == 1)
				{
					// printf("found incoming edge, so continue\n");
					noIncomingEdgesFlag = 1;
					break;
				}
				pro*=adjM[j][i];
				if(adjM[j][i] == -1)
				{
					// printf("found omitted edge so continue\n");
					noIncomingEdgesFlag = -1;
					// continue;
				}
			}

			if(noIncomingEdgesFlag != 1 && pro == 0)
			{
				start = i;
				// printf("breaking when %i\n", i);
				break;
			}
		}

		if (start == -1)
		{
			fprintf(stderr, "%s\n", "Contains a cycle");
			return;
		}

		visited[start] = 1;
		// printf("Working with %i\n", start);
		for (int i = 0; i < n; ++i)
		{
			/*if (adjM[start][i] == 1)
			{
				int flag = 0;
				printf("For %i connected to %i\n", i, start);
				for (int j = 0; j < n; ++j)
				{
					if(j != i && j != start && adjM[j][i] == 1 && visited[j] == 0) // not the current node but not visited already
					{
						printf("Rejecting %i\n", j);
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					start = i;
					order[++iter] = i;
					break;
				}

			}*/

			adjM[start][i] = adjM[i][start] = -1;
		}
		// printf("omitted %i\n", start);
		displayAdjMatrix(adjM, n);
		order[++iter] = start;

	}

	printf("Topological sorting order:\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%i ", order[i]);
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	int n;
	printf("Enter the no. of nodes\n");
	scanf("%i", &n);

	AdjMatrix adjM = createGraph(n);

	displayAdjMatrix(adjM, n);
	sourceRemovalTopo(adjM, n);
	return 0;
}
