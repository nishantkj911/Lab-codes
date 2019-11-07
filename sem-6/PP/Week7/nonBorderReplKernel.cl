__kernel void replFunc(__global int *matIn, __global int *matOut)
{
    int i = get_global_id(1);
    int j = get_global_id(0);
    int col = get_global_size(0);
    int row = get_global_size(1);

    if (i == 0 || j == 0 || i == row - 1 || j == col - 1)
    {
        matOut[i * col + j] = matIn[i * col + j];
    }
    else
    {
        int temp = matIn[i * col + j];
        for(int k = 0; k < 32; k++)
        {
            temp = temp ^ (1<<k);
        }
        matOut[i * col + j] = temp;
    }
}