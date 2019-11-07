#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int rank, n, fact = 1;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &n);

    for (int i = 1; i <= rank + 1; i++)
    {
        fact *= i;
    }

    int cumFactSum;
    MPI_Scan(&fact, &cumFactSum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

    if (rank == n - 1)
    {
        printf("Sum of the factorials is %i\n", cumFactSum);
    }

    MPI_Finalize(); 
    return 0;
}
