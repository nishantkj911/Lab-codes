#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int rank, size, row = 4, col = 4;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int *myArr = calloc(col, sizeof(int));
    int *myArr2 = calloc(col, sizeof(int));
    int mat[row][col], mat2[row][col];
    if (rank == 0)
    {
        //Take input of no of rows and columns
        printf("Enter the matrix\n");
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                scanf("%i", &mat[i][j]);
            }
        }
    }

    // printf("col: %i\n", col);
    MPI_Scatter(mat, col, MPI_INT, myArr, col, MPI_INT, 0, MPI_COMM_WORLD);

    /* printf("For rank %i, the array is\n", rank);
    for (int i = 0; i < col; i++)
    {
        printf("%i ", myArr[i]);
    }
    printf("\n"); */

    MPI_Scan(myArr, myArr2, col, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

    MPI_Gather(myArr2, col, MPI_INT, mat, col, MPI_INT, 0, MPI_COMM_WORLD);
    // MPI_Barrier(MPI_COMM_WORLD);
    // printf("Barrier reached\n");
    if (rank == 0)
    {
        printf("The modified matrix\n");
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                printf("%i ", mat[i][j]);
            }
            printf("\n");
        }
    }
    MPI_Finalize();
    return 0;
}
