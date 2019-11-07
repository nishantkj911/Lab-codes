__kernel void rowcolsum(__global int *matIn, __global int *matOut)
{
    int j = get_global_id(0);
    int i = get_global_id(1);
    int col = get_global_size(0);
    int row = get_global_size(1);

	int rowSum = 0, colSum = 0;
	for (int k = 0; k < col; k++)
    {
        colSum += matIn[i * col + k];
    }
    for (int k = 0; k < row; k++)
    {
        rowSum += matIn[k * col + j];
    }

    // printf("Row: %i, Col: %i, Row sum: %i, Col Sum: %i\n", i, j, rowSum, colSum);

    matOut[i * col + j] = rowSum + colSum;
}