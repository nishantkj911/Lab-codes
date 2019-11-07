__kernel void sort(__global int *A, __global int *B)
{
    int i = get_global_id(0);
    int n = get_global_size(0);

    int pos = 0, data = A[i];
    for (int j = 0; j < n; j++)
    {
        if((A[j] < data) || (A[j] == data && j < i))
        {
            pos++;
        }
    }

    B[pos] = data;
}