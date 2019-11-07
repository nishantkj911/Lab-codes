#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int rank, size, m, *arr;
    float totalAvg;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0)
    {
        printf("Enter the value of M\n");
        scanf("%i", &m);

        arr = calloc(size * m, sizeof(int));
        printf("Enter all the values\n");
        for (int i = 0; i < size * m; i++)
        {
            scanf("%i", &arr[i]);
        }
    }
    MPI_Bcast(&m, 1, MPI_INT, 0, MPI_COMM_WORLD);

    int *arr2 = calloc(m, sizeof(int));
    MPI_Scatter(arr, m, MPI_INT, arr2, m, MPI_INT, 0, MPI_COMM_WORLD);

    float avg = 0;
    for (int i = 0; i < m; i++)
    {
        avg += (float) arr2[i] / m;
    }

    printf("Average calculated by rank %i is %f\n", rank, avg);

    MPI_Reduce(&avg, &totalAvg, 1, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD);
    if(rank == 0)
    {
        totalAvg /= size;
        printf("Average of all the numbers is %f\n", totalAvg);
    }
    MPI_Finalize();
    return 0;
}