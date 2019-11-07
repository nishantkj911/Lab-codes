#include <stdio.h>
#include <stdlib.h>

#define FILENAME "removeComment.c"
#define FILENAME2 "fileOutput.c"

int main(int argc, char const *argv[])
{
    FILE* file = fopen(FILENAME, "r");
    if(file == NULL)
    {
        perror("The read file doesn't exist\n");
        return 1;
    }

    FILE* file2 = fopen(FILENAME2, "w");
    if(file2 == NULL)
    {
        perror("The write file doesn't exist\n");
        return 1;
    }

    char c;
    while(1)
    {
        c = fgetc(file);
        if(c == EOF)
            break;
        
        if(c == '/')
        {
            char c2 = fgetc(file);
            // printf("the second char: %c\n", c2);
            if(c2 == EOF)
            {
                fputc(c, file2);
                perror("Incomplete comment or unidentified char\n");
                break;
            }
            else if(c2 == '/') //single line comment
            {
                char cTemp;
                do
                {
                    cTemp = fgetc(file);
                    if(cTemp == EOF)
                    {
                        // printf("EOF at single line comment\n");
                        return 1;
                    }
                    
                }while(cTemp != '\n');

            }
            else if(c2 == '*') // multi-line comment
            {
                char cTemp;
                while(1)
                {
                    cTemp = fgetc(file);
                    if(cTemp == EOF)
                    {
                        perror("End of file encountered. Close the comment!\n");
                        return 1;
                    }
                    else if(cTemp == '*' && fgetc(file) == '/')
                        break;
                    
                }
            }
            else //any other character
            {
                // printf("only a slash, not a comment\n");
                fputc(c, file2);
                fputc(c2, file2);
            }
        }
        else
        {
            fputc(c, file2);
        }
    }

    fclose(file);
    fclose(file2);
    printf("Done! check o/p file\n");
}
