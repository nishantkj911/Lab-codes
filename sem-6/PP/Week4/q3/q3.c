#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int rank, size, row = 3, col = 3, noOfOccurances = 0, noOfTotalOccurances, occur;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int *myArr = calloc(col, sizeof(int));
    int mat[row][col];
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

        printf("Enter the no. to see occurrences\n");
        scanf("%i", &occur);
    }

    MPI_Scatter(mat, col, MPI_INT, myArr, col, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&occur, 1, MPI_INT, 0, MPI_COMM_WORLD);

    for (int i = 0; i < col; i++)
    {
        if (myArr[i] == occur)
        {
            noOfOccurances++;
        }
    }

    MPI_Reduce(&noOfOccurances, &noOfTotalOccurances, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    
    /* printf("For rank %i, the array is\n", rank);
    for (int i = 0; i < col; i++)
    {
        printf("%i ", myArr[i]);
    }
    printf("\n"); */

    if (rank == 0)
    {
        printf("The no. of occurrances of %i in the matrix is %i\n", occur, noOfTotalOccurances);
    }
    MPI_Finalize();
    return 0;
}
