#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    FILE *f1 = fopen("ip.txt", "r");
    char str[100], str2[1000];
    fscanf(f1, "%s", str);
    fscanf(f1, "%s", str2);

    printf("'%s'   '%s'\n", str, str2);
    return 0;
}
