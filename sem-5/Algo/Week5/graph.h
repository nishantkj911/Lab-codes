#include <stdio.h>
#include <stdlib.h>

typedef struct _list
{
	int key;
	struct _list* next;
} AdjNode;

typedef AdjNode* AdjPtr;

typedef AdjPtr* AdjList;
typedef int** AdjMatrix;

AdjList insertKey(AdjList adj, int node, int neighbor, int n)
{
	if(neighbor > n-1)
	{
		// printf("Enter proper neigh\n");
		return adj;
	}

	if(adj[node] == NULL)
	{
		// printf("null node\n");
		AdjPtr temp = malloc(sizeof(AdjNode));
		temp->key = neighbor;
		temp->next = NULL;
		adj[node] = temp;
		return adj;
	}

	for(AdjPtr temp = adj[node]; temp != NULL; temp = temp->next)
	{
		if(temp->key == neighbor)
		{
			printf("Do not repeat adjacent nodes\n");
			return adj;
		}
	}

	// printf("not null node\n");
	AdjPtr temp = malloc(sizeof(AdjNode));
	temp->key = neighbor;
	temp->next = adj[node]->next;
	adj[node]->next = temp;

	/*for(AdjPtr temp = adj[node]; temp != NULL; temp = temp->next)
	{
		printf("%i ", temp->key);
	}
	printf("\n");*/
	return adj;
}

void displayAdjList(AdjList adj, int n)
{
	printf("The adjacency list is\n");
	for(int i=0; i<n; i++)
	{
		printf("Node %i----> ", i);
		for(AdjPtr temp = adj[i]; temp != NULL; temp = temp->next)
		{
			printf("%i ", temp->key);
		}
		printf("\n");
	}
	printf("\n");
}

void displayAdjMatrix(AdjMatrix mat, int n)
{
	printf("The adjacency matrix is\n");
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			printf("%i ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

AdjMatrix createGraph(int n)
{
	AdjList adj = malloc(sizeof(AdjPtr) * n);
	AdjMatrix adjM = malloc(sizeof(int*) * n);
	for(int i=0; i<n; i++)
	{
		adj[i] = NULL;
		adjM[i] = malloc(sizeof(int) * n);
		printf("For node %i please enter its neighbors and press 'Ctrl + D' to end\n", i);
		while(1)
		{
			int neighbor;
			int res = scanf("%i", &neighbor);
			if(res == EOF)
			{
				break;
			}
			if(res == 1)
			{
				adj = insertKey(adj, i, neighbor, n);
				if(neighbor >= n)
				{
					printf("Enter proper neighbor\n");
					continue;
				}
				adjM[i][neighbor] = 1;
			}
			else
			{
				printf("Enter proper input\n");
				scanf("%*[^\n]");
			}
		}
	}
	printf("\n");
	/*displayAdjList(adj, n);
	displayAdjMatrix(adjM, n);*/

	return adjM;
}

// returns -1 if all are visited else first node which is not
int checkAllVisited(int* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		if(arr[i] == 0)
		{
			// printf("First unvisited node is %i\n", i);
			return i;
		}
	}

	// printf("All nodes visited\n");
	return -1;
}