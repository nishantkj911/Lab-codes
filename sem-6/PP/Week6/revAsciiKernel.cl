__kernel void revAscii(__global char *str)
{
    int i = get_global_id(0);
    // printf("%c\n", str[i]);
    int temp = (int) str[i];

    int newChar = 0;
    while(temp > 0)
    {
        newChar = (newChar * 10) + (temp % 10);
        temp /= 10;
    }
    char c = (char) newChar;
    str[i] = c;
}