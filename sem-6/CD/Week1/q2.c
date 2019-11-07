#include <stdio.h>
#include <stdlib.h>

#define FILEINPUT "fileInput.c"
#define FILEOUTPUT "fileOutput.c"

int main(int argc, char const *argv[])
{
    FILE *file1, *file2;
    file1 = fopen(FILEINPUT, "r");
    file2 = fopen(FILEOUTPUT, "w");
    if (file1 == NULL || file2 == NULL)
    {
        perror("Either of input or output file don't exist\n");
        return 1;
    }

    char c;
    int colNo = 0;
    while (1)
    {
        c = fgetc(file1);
        if (c == EOF)
        {
            break;
        }
        else if (c == '\n')
        {
            colNo = 0;
            fputc(c, file2);
        }
        else if (c == '#' && colNo == 0)
        {
            char c2;
            do
            {
                c2 = fgetc(file1);
            } while (c2 != '\n');
        }
        else
        {
            colNo++;
            fputc(c, file2);
        }
    }

    fclose(file1);
    fclose(file2);
    printf("Done! check o/p file\n");
}