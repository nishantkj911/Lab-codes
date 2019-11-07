__kernel void transpose(__global int *matIn, __global int *matOut)
{
    int j = get_global_id(0);
    int i = get_global_id(1);
    int col = get_global_size(0);
    int row = get_global_size(1);

    matOut[j * row + i] = matIn[i * col + j];
}