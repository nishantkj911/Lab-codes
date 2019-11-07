__kernel void dToO(__global int *A, __global long *B)
{
    int i = get_global_id(0);
    long temp = A[i], mulFact = 1;
    B[i] = 0;
    while (temp > 0)
    {
        B[i] = B[i] + (temp % 8) * mulFact;
        temp /= 8;
        mulFact *= 10;
    }
}