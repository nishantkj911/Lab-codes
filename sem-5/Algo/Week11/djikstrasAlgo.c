#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef int **AdjMatrix;

AdjMatrix createWeightedGraph(int *N)
{
    int n;
    printf("Enter the no. of vertices in the graph\n");
    scanf("%i", &n);

    AdjMatrix adjM = (AdjMatrix)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        adjM[i] = (int *)calloc(n, sizeof(int));
        for (int j = 0; j < n; j++)
        {
            adjM[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter neighbors and weights to them, ctrl + d to end\n");
        int neigh, weigh;
        while (scanf("%i %i", &neigh, &weigh) != EOF)
        {
            if (neigh >= n)
            {
                printf("Enter proper neighbor\n");
                continue;
            }

            if (weigh <= 0)
            {
                printf("Weight cannot be negative\n");
                continue;
            }

            adjM[i][neigh] = weigh;
            adjM[neigh][i] = weigh;
        }
    }

    *N = n;
    return adjM;
}

void displayAdjMatrix(AdjMatrix mat, int n)
{
    printf("The adjacency matrix is\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%i\t", mat[i][j]);
        }
        printf("\n");
    }
}

int elementInArray(int *f, int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (f[i] == key)
            return 1;
    }

    return 0;
}
AdjMatrix djikstrasAlgo(AdjMatrix adjM, int n, int start)
{
    int *finish = calloc(1, sizeof(int));
    int size = 1;
    finish[size - 1] = start;

    //creating the min spa tree
    AdjMatrix minSpaTree = (AdjMatrix)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        minSpaTree[i] = calloc(n, sizeof(int));
        for (int j = 0; j < n; j++)
        {
            minSpaTree[i][j] = INT_MAX;
        }
    }
    // int work = start;
    while (size != n) // takes O(n)
    {
        printf("here\n");
        //finding the min vertex connected to the working node
        int min = 0, workMin = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adjM[finish[i]][j] < adjM[workMin][min] && !elementInArray(finish, n, j))
                {
                    workMin = finish[i];
                    min = j;
                    printf("Found new minimum: vertex %i connected to %i with value %i\n", workMin, min, adjM[workMin][min]);

                    /* else
                    {
                        printf("Found min but %i already in the set\n", j);
                    }
                } */
                }
            }

            printf("finally adding edge with vertex %i connected to %i\n", workMin, min);
            minSpaTree[workMin][min] = adjM[workMin][min];
            minSpaTree[min][workMin] = adjM[min][workMin];
            finish = realloc(finish, sizeof(int) * ++size);
            finish[size - 1] = min;
            /* printf("\nThe array is \n");
        for (int i = 0; i < size; i++)
        {
            printf("%i\n", finish[i]);
        }
        printf("\n"); */
        }

        return minSpaTree;
    }

    int main(int argc, char const *argv[])
    {
        int n;
        AdjMatrix adjM = createWeightedGraph(&n);

        // printf("Value of n: %i\n", n);
        displayAdjMatrix(adjM, n);
        printf("\n");
        AdjMatrix minSpaTree = djikstrasAlgo(adjM, n, 0);

        displayAdjMatrix(minSpaTree, n);
        return 0;
    }
