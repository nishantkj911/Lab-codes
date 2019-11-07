#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int rank, size, n, tag = 0;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Status status;
    if (rank == 0)
    {
        printf("Enter the number\n");
        scanf("%i", &n);

        // printf("All sends done\n");

        int newN;
        MPI_Send(&n, 1, MPI_INT, 1, tag, MPI_COMM_WORLD);
        MPI_Recv(&newN, 1, MPI_INT, size - 1, tag, MPI_COMM_WORLD, &status);
        printf("From rank %i, the modified value is %i\n", rank, newN);
    }
    else
    {
        MPI_Recv(&n, 1, MPI_INT, rank - 1, tag, MPI_COMM_WORLD, &status);
        n++;

        MPI_Send(&n, 1, MPI_INT, rank == size - 1 ? 0 : rank + 1, tag, MPI_COMM_WORLD);
        printf("From rank %i, the modified value is %i\n", rank, n);
    }

    MPI_Finalize();
    return 0;
}