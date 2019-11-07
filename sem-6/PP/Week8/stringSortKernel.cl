__kernel void charSort(__global char *str, __global char *str2) {
    
    int i = get_global_id(0);
    int n = get_global_size(0);
    int pos = 0;

    char c = str[i];
    for (int j = 0; j < n; j++)
    {
        if((str[j] < c) || (str[j] == c && j < i))
            pos++;
    }

    str2[pos] = c;
}