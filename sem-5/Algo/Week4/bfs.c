#include "graph.h"
#include "queue.h"

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
	
void bfs(AdjMatrix adjM, int n)
{
	Queue q = initQ();
	int* order = malloc(sizeof(int) * n);
	int* visited = malloc(sizeof(int) * n);
	int iter = -1;

	q = enqueue(q, 0);
	order[++iter] = 0;

	int next;
	while(q.list != NULL || ((next = checkAllVisited(visited, n)) && next != -1))
	{
		if(q.list == NULL)
		{
			q = enqueue(q, next);
			order[++iter] = next;
		}
		int wNode = peek(q);
		visited[wNode] = 1;
		for (int i = 0; i < n; ++i)
		{
			if(adjM[wNode][i] == 1 && visited[i] == 0)
			{
				q = enqueue(q, i);
				order[++iter] = i;
			}
		}
		q = dequeue(q);
	}

	printf("Pushing and popping order\n");
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

	bfs(adjM, n);
	return 0;
}