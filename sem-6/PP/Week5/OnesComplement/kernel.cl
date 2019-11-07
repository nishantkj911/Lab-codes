__kernel void oneCompl(__global unsigned int *A, __global int *B)
{
    int i = get_global_id(0);
    for (int j = 0; j < 32; j++)
    {
        A[i] = A[i] ^ (1<<j);
    }
}