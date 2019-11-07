#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char const *argv[])
{
    int rank, size;
    int a, b, c;

    FILE *input = fopen("input.txt", "r");
    if (input == NULL)
    {
        perror("no input file found\n");
        return 0;
    }

    fscanf(input, "%i %i", &a, &b);
    fclose(input);

    /*a = 6;
    b = 9;*/

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    switch (rank)
    {
    case 0:
        c = a + b;
        break;
    case 1:
        c = a * b;
        break;
    case 2:
        c = a - b;
        break;
    case 3:
        c = a / b;
        break;
    }
    
    printf("%i\n", c);

    MPI_Finalize();
    return 0;
}