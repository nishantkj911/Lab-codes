#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE (0x10000000)
#define alphabetLength 26

char switchCase(char c)
{
    if (islower(c))
    {
        return toupper(c);
    }
    else if (isupper(c))
    {
        return tolower(c);
    }
    else
    {
        printf("No special symbols\n");
        return c;
    }
}

char *encode(char *str, char *key)
{
    int len = strlen(str), keyLen = strlen(key);
    char *ret = calloc(len, sizeof(char));

    for (int i = 0, j = 0; i < len; i++, j = (j + 1) % keyLen)
    {
        int temp = 0;
        char x = str[i], y = key[j];
        if (isalpha(x)) // checking if ip is an alphabet
        {
            if (isupper(x) ^ isupper(y)) // if the cases are different, making them same as i/p
            {
                y = switchCase(y);
            }

            // printf("comparing %c and %c", x, y);
            if (isupper(x)) // ciphering upper case
            {
                temp = y + (x - 'A');
                if (temp > 'Z')
                {
                    // printf("YO\n");
                    temp = temp - alphabetLength;
                }
            }
            else // ciphering lower case
            {
                temp = y + (x - 'a');
                if (temp > 'z')
                {
                    temp = temp - alphabetLength;
                }
            }
            // printf(" and got the answer %c\n", temp);
        }
        else
        {
            temp = x;
            // j--;
        }

        ret[i] = temp;
    }

    return ret;
}

char *decode(char *str, char *key)
{
    int len = strlen(str), keyLen = strlen(key);
    char *ret = calloc(len, sizeof(char));

    for (int i = 0, j = 0; i < len; i++, j = (j + 1) % keyLen)
    {
        int temp = 0;
        char f = str[i], y = key[j];
        if (isalpha(f)) // checking if ip is an alphabet
        {
            if (isupper(f) ^ isupper(y)) // if the cases are different, making them same as i/p
            {
                y = switchCase(y);
            }

            // printf("comparing %c and %c", f, y);
            if (isupper(f)) // deciphering upper case
            {
                temp = f + ('A' - y);
                if (temp < 'A')
                {
                    // printf("YO\n");
                    temp = temp + alphabetLength;
                }
            }
            else // deciphering lower case
            {
                temp = f + ('a' - y);
                if (temp < 'a')
                {
                    temp = temp + alphabetLength;
                }
            }
            // printf(" and got the answer %c\n", temp);
        }
        else
        {
            temp = f;
            // j--;
        }

        ret[i] = temp;
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    char *str = calloc(MAX_SIZE, sizeof(char));
    // printf("Enter the string you want to encode\n");
    // scanf("%[^\n]%*c", str);

    char key[BUFSIZ];
    // printf("Enter the key\n");
    // scanf("%s", key);

    int ch = 1;

    printf("1. Encode\n2. Decode\nOther: Exit\nMake a choice? ");
    scanf("%i", &ch);

    char *ipFile = calloc(BUFSIZ, 1), *opFile = calloc(BUFSIZ, 1);
    FILE *f1, *f2;

    while (1)
    {
        if (ch == 1)
        {
            printf("Enter the file to encode\n");
            scanf("%s", ipFile);
            f1 = fopen(ipFile, "r");
            if (!f1)
            {
                printf("File not found\n");
                continue;
            }
            sprintf(opFile, "output_%s", ipFile);
            f2 = fopen(opFile, "w");

            fread(str, MAX_SIZE, 1, f1);

            printf("Enter the password: ");
            scanf("%s", key);

            fprintf(f2, "%s", encode(str, key));
            printf("Done, check encoded file\n");
            fclose(f1);
            fclose(f2);
        }
        else if (ch == 2)
        {
            printf("Enter the file to decode\n");
            scanf("%s", ipFile);
            f1 = fopen(ipFile, "r");
            if (!f1)
            {
                printf("File not found\n");
                continue;
            }

            sprintf(opFile, "output_%s", ipFile);
            f2 = fopen(opFile, "w");

            fread(str, MAX_SIZE, 1, f1);

            printf("Enter the password: ");
            scanf("%s", key);

            fprintf(f2, "%s", decode(str, key));
            printf("Done, check decoded file\n");
            fclose(f1);
            fclose(f2);
        }
        else
        {
            break;
        }
    }

    // char *encodedAns = encode(str, key);
    // printf("Encoded ans is %s\n", encodedAns);

    // printf("Decoded answer is %s\n", decode(encodedAns, key));
    return 0;
}
