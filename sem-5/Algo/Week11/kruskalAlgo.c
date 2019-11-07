#include <stdio.h>
#include <stdlib.h>	

typedef int** AdjMatrix;

AdjMatrix createWeightedGraph(int* N)
{
	int n;
	scanf("%i", &n);
	*N = n;

	AdjMatrix mat = calloc(n, sizeof(int*))
}