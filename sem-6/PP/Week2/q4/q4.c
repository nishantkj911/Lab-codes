#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int rank, n, sender = 0, tag = 0, num, ans;

    int *buffer = calloc(BUFSIZ, sizeof(int));

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &n);
    MPI_Buffer_attach(buffer, BUFSIZ);
    MPI_Status status;
    if (rank == sender)
    {
        /* printf("Enter the no. of elements\n");
        scanf("%i", &n); */

        int *arr = calloc(n, sizeof(int));
        printf("Enter the elements in the array\n");
        for (int i = 0; i < n; i++)
        {
            scanf("%i", &arr[i]);
            MPI_Bsend(&arr[i], 1, MPI_INT, i, tag, MPI_COMM_WORLD);
        }
        // printf("All sends done\n");
    }

    MPI_Recv(&num, 1, MPI_INT, sender, tag, MPI_COMM_WORLD, &status);
    if (rank % 2 == 0)
    {
        ans = num * num;
    }
    else
    {
        ans = num * num * num;
    }

    printf("The process with rank %i calculated its value as %i\n", rank, ans);

    int size = BUFSIZ;
    MPI_Buffer_detach(buffer, &size);
    MPI_Finalize();
    return 0;
}
