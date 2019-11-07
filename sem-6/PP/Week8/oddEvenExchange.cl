__kernel void oddEven(__global int *A) {
    int i = get_global_id(0);
    int n = get_global_size(0);

    if (i % 2 == 1 && i != n - 1)
    {
        if(A[i] > A[i+1])
        {
            int temp = A[i];
            A[i] = A[i+1];
            A[i+1] = temp;
        }
    }
}