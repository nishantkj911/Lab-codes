#include <mpi.h>
#include <stdio.h>


// implement by taking input from user
int main(int argc, char *argv[])
{
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    FILE *input = fopen("input.txt", "r");
    if (input == NULL)
    {
        printf("Input file not found\n");
    }
    else
    {
        /*int r1, c1, r2, c2;
        fscanf(input, "%i", &r1);
        fscanf(input, "%i", &c1);
        fscanf(input, "%i", &r2);
        fscanf(input, "%i", &c2);

        printf("%i %i %i %i\n", r1, r2, c1, c2);*/

        /* if (c2 != r1)
        {
            printf("Matrix multiplication cannot be done\n");
        }
        else
        { */

            int mat1[2][3] = {{1, 2, 3}, {4, 5, 6}}, mat2[3][2] = {{1, 2}, {3, 4}, {4, 5}}, ans[2][2];
            /* for (int i = 0; i < r1; i++)
            {
                for (int j = 0; j < c1; j++)
                {
                    fscanf(input, "%i", &mat1[i][j]);
                }
            }

            for (int i = 0; i < r2; i++)
            {
                for (int j = 0; j < c2; j++)
                {
                    fscanf(input, "%i", &mat2[i][j]);
                }
            } */
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    for (int k = 0; k < 3; k++)
                    {
                        ans[i][j] += mat1[i][k] * mat2[k][j];
                    }
                }
            }

            printf("The result matrix is\n");
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    printf("%i ", ans[i][j]);
                }
                printf("\n");
            }
            fclose(input);
        // }
    }
    MPI_Finalize();
    return 0;
}
