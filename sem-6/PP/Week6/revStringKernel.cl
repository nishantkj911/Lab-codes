__kernel void revString(__global char *str, __global int *len, __global char *str2)
{
    int i = get_global_id(0);
    printf("%i\n", i);
    char c = str[i];
    str[i] = str[len[0] - i - 1];
    str[len[0] - i - 1] = c;
}