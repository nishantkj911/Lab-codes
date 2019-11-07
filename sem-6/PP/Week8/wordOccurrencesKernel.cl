__kernel void searchWord(__global char *str, __global char *word, __global int *wordStart, __global int *len, __global int *noOfOccurrances)
{
    int i = get_global_id(0);
    int n = get_global_size(0);
    int flag = 1;
    int strIndex = wordStart[i];

    printf("YO!\n");
    for (int j = strIndex, k = 0; j < i == n - 1 ? *len : wordStart[i+1]; j++, k++)
    {
        if (word[k] != str[j])
            flag = 1;
    }

    if (flag)
    {
        *noOfOccurrances++;
    }
}