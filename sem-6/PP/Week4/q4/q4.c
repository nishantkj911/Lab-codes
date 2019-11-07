#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

void myErrorHandler(int ec)
{
    if (ec == MPI_SUCCESS)
        return;

    int lenErrStr, eCl;
    char errStr[BUFSIZ];

    MPI_Error_class(ec, &eCl);
    // MPI_Error_string(eCl, errStr, &lenErrStr);
    // fprintf(stderr, "%s\n", errStr);

    MPI_Error_string(ec, errStr, &lenErrStr);
    fprintf(stderr, "%s\n", errStr);
}

int main(int argc, char *argv[])
{
    int c = 3, rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Errhandler_set(MPI_COMM_WORLD, MPI_ERRORS_RETURN);
    int ec = MPI_Comm_size(c, &size);
    if (rank == 0)
    {
        myErrorHandler(ec);
    }
    printf("From rank %i, Hello world!\n", rank);
    MPI_Finalize();
    return 0;
}