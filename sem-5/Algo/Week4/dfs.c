#include "graph.h"
#include "stack.h"

void dfs(AdjList adj, int n)
{
	int* arr = malloc(sizeof(int) * n);
	int* pushOrder = malloc(sizeof(int) * n);
	int* popOrder = malloc(sizeof(int) * n);
	int i = 0, j = 0;
	Stack st = NULL;
	int vis = checkAllVisited(arr, n);
	st = push(st, vis);
	pushOrder[i++] = vis;
	while(st != NULL || ((vis = checkAllVisited(arr, n)) && vis != -1))
	{
		if(st == NULL)
		{
			st = push(st, vis);
			pushOrder[i++] = vis;
		}

		int node = peek(st);
		AdjPtr temp = adj[node];
		// printf("Working with %i\n", node);
		arr[node] = 1;
		int flag = 1;
		for(AdjPtr temp2 = temp; temp2 != NULL; temp2 = temp2->next)
		{
			flag = 0;
			if(!arr[temp2->key])
			{
				// printf("First unvisited neighbor found is %i\n", temp2->key);
				st = push(st, temp2->key);
				pushOrder[i++] = temp2->key;
				// arr[temp->key] = 1;
				break;
			}
			flag = 1;
		}

		if(flag == 1) //all the nodes of this are visited or it doesnt have any neighbor
		{
			// printf("Now all neighbors of %i are visited so popping it\n", node);
			popOrder[j++] = peek(st);
			st = pop(st);
		}

		// vis = checkAllVisited(arr, n);
	}

	printf("Push order:\n");
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
	printf("\n");
}

int main()
{
	int n;
	printf("Enter the no. of nodes: ");
	scanf("%i", &n);
	AdjList adj = malloc(sizeof(AdjPtr) * n);
	for(int i=0; i<n; i++)
	{
		adj[i] = NULL;
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
			}
			else
			{
				printf("Enter proper input\n");
				scanf("%*[^\n]");
			}
		}
	}
	printf("\n");
	displayAdjList(adj, n);

	dfs(adj, n);
	return 0;
}