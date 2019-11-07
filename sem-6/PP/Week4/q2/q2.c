#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <math.h>

double f(double x)
{
    double ans = 4;
    ans /= (1 + x * x);

    return ans;
}

int main(int argc, char *argv[])
{
    int rank, size;
    long n;
    double h, x, myPi, actPi = 3.141592653589793238462643;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0)
    {
        printf("Enter the no. of intervals to take\n");
        scanf("%li", &n);
    }

    MPI_Bcast(&n, 1, MPI_LONG, 0, MPI_COMM_WORLD);
    h = (double)1 / (double)n;

    x = 0.0;

    for (int i = rank; i < n; i += size)
    {
        x += f(h * ((double)i - 0.5));
    }

    x *= h;

    MPI_Reduce(&x, &myPi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        printf("The calculated value of pi is %.25f\n", myPi);
        printf("The error is %.25f\n", fabs(actPi - myPi));
    }
    MPI_Finalize();
    return 0;
}
