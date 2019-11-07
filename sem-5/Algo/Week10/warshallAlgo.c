#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void warshalAlgo(AdjMatrix *Mat, int n)
{
	AdjMatrix adjMat = *Mat;
	for (int k = 0; k < n; ++k)
	{
		printf("Iteration: %i\n", k+1);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				adjMat[i][j] = adjMat[i][j] | (adjMat[k][j] & adjMat[i][k]);
			}
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				printf("%i ", adjMat[i][j]);
			}
			printf("\n");
		}
	}
}

int main(int argc, char const *argv[])
{
	int n;
	printf("Enter the no. of vertices in the graph\n");
	scanf("%i", &n);
	AdjMatrix adjMat = createGraph(n);

	displayAdjMatrix(adjMat, n);

	warshalAlgo(&adjMat, n);
	return 0;
}