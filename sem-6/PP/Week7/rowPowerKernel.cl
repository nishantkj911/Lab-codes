__kernel void rowPow(__global int *matInput, __global int *matOutput)
{
    int j = get_global_id(0);
    int i = get_global_id(1);
    int col = get_global_size(0);
    printf("Row: %i\tCol: %i\tTotalRow: %i\tItem: %i\n", i, j, col, matInput[i * col + j]);
    int num = 1;
    for (int k = 1; k <= i + 1; k++)
    {
        num *= matInput[i * col + j];
    }

    matOutput[i * col + j] = num;
}