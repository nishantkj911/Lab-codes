#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int rank, n, *arr, val, fact, factSum;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &n);
    if (rank == 0)
    {
        printf("Enter the values of the array\n");
        arr = calloc(n, sizeof(int));
        for (int i = 0; i < n; i++)
        {
            scanf("%i", &arr[i]);
        }
    }
    MPI_Scatter(arr, 1, MPI_INT, &val, 1, MPI_INT, 0, MPI_COMM_WORLD);

    fact = 1;
    for (int i = 1; i <= val; i++)
    {
        fact *= i;
    }

    // printf("Factorial calculated by rank %i is %i\n", rank, fact);
    MPI_Reduce(&fact, &factSum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if(rank == 0)
    {
        printf("The final sum calculated is %i\n", factSum);
    }

    MPI_Finalize();
    return 0;
}
