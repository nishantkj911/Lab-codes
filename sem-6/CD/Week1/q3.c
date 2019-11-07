#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define FILENAME "fileInput.c"

int main(int argc, char const *argv[])
{
    FILE *file1 = fopen(FILENAME, "r");
    if (file1 == NULL)
    {
        perror("The i/p file doesn't exist\n");
        return 1;
    }

    char *keywords[10];
    keywords[0] = "int";
    keywords[1] = "char";
    keywords[2] = "return";
    keywords[3] = "while";
    keywords[4] = "if";
    keywords[5] = "case";
    keywords[6] = "for";
    keywords[7] = "else";
    keywords[8] = "break";
    keywords[9] = "continue";

    char ch, *buf = calloc(BUFSIZ, sizeof(char));
    int lineNo = 1, colNo = 0;
    do
    {
        ch = fgetc(file1);
        if (ch == '\n')
        {
            lineNo++;
            colNo = 0;
            continue;
        }
        if (ch == '\t')
            colNo += 3;
        // printf("read %c\n", ch);
        colNo++;
        int i = 0;
        while (isalpha(ch))
        {
            buf[i++] = ch;
            ch = fgetc(file1);
            if (ch == '\t')
                colNo += 3;
            colNo++;
        }
        buf[i++] = '\0';

        // printf("'%s'\n", buf);

        // int flag = 0;
        for (int i = 0; i < 10; i++)
        {
            if (strcmp(buf, keywords[i]) == 0)
            {
                for (int i = 0; i < strlen(buf); i++)
                {
                    buf[i] = toupper(buf[i]);
                }
                printf("%s\tLine No: %i\tColumn No: %i\n", buf, lineNo, colNo - strlen(buf));
            }
        }
    } while (ch != EOF);

    return 0;
}
