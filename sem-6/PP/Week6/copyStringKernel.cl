__kernel void copyString(__global char *initString, __global char *finalString, __global int *len)
{
    int i = get_global_id(0);
    for (int j = 0; j < len[0]; j++)
    {
    	finalString[i * len[0] + j] = initString[j];
    }
}