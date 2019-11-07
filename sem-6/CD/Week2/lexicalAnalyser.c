// CRASHES THE SYSTEM FOR NO REASON! TRY IT ON AN ONLINE COMPILER

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct $
{
    char *lexeme;
    unsigned int row, col, type;
    int index;
} Token;

int lc = 1, cc = 1, prevCC = 1;

enum types
{
    KEYWORD,
    IDENTIFIER,
    LP,
    RP,
    LCB,
    RCB,
    LSB,
    RSB,
    LTE,
    LT,
    GTE,
    GT,
    NE,
    WS,
    EQ,
    ASS,
    NUM,
    INC,
    DEC,
    OP_ASS,
    LNOT,
    AOP,
    LOR,
    LAND,
    BNOT,
    BOR,
    BAND,
    XOR,
    SS,
    LIT
};

void updateLineAndCol(char c)
{
    if (c == '\n')
    {
        lc++;
        prevCC = cc;
        cc = 1;
    }
    else
    {
        prevCC = cc;
        cc++;
    }
}

void retract(FILE *f1, char c)
{
    fseek(f1, -1, SEEK_CUR);
    if (c == '\n')
    {
        lc--;
        cc = prevCC;
    }
}
char keywords[][20] =
    {"int", "char", "long", "return", "break", "continue",
     "short", "float", "do", "double", "while", "for",
     "switch", "case", "default", "bool", "if", "else",
     "typedef", "struct", "sizeof", "void"};

int removeComments(char *FILENAME, char *FILENAME2)
{
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL)
    {
        perror("The read file doesn't exist\n");
        return 1;
    }

    FILE *file2 = fopen(FILENAME2, "w");
    if (file2 == NULL)
    {
        perror("The write file doesn't exist\n");
        return 1;
    }

    char c;
    while (1)
    {
        c = fgetc(file);
        if (c == EOF)
            break;

        if (c == '/')
        {
            char c2 = fgetc(file);
            // printf("the second char: %c\n", c2);
            if (c2 == EOF)
            {
                fputc(c, file2);
                perror("Incomplete comment or unidentified char\n");
                break;
            }
            else if (c2 == '/') //single line comment
            {
                char cTemp;
                do
                {
                    cTemp = fgetc(file);
                    if (cTemp == EOF)
                    {
                        // printf("EOF at single line comment\n");
                        return 1;
                    }

                } while (cTemp != '\n');
            }
            else if (c2 == '*') // multi-line comment
            {
                char cTemp;
                while (1)
                {
                    cTemp = fgetc(file);
                    if (cTemp == EOF)
                    {
                        perror("End of file encountered. Close the comment!\n");
                        return 1;
                    }
                    else if (cTemp == '*' && fgetc(file) == '/')
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
    return 0;
}

int ignorePreprocessorDirectives(char *FILENAME, char *FILENAME2)
{
    FILE *file1, *file2;
    file1 = fopen(FILENAME, "r");
    file2 = fopen(FILENAME2, "w");
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
        updateLineAndCol(c);
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
                updateLineAndCol(c2);
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
    return 0;
}

int isKeyword(char *buf)
{
    // printf("%lu\n", sizeof(keywords[0]));
    for (int i = 0; i < sizeof(keywords) / 20; i++)
    {
        if (strcmp(buf, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

Token *getNextToken(FILE *file1)
{
    Token *returnToken = malloc(sizeof(Token));
    int i = 0;
    char *buf = calloc(BUFSIZ, sizeof(char));
    char c = fgetc(file1);
    updateLineAndCol(c);
    char c2;
    // printf("'%c'\n", c);
    if (isalpha(c) || c == '_') // generating string of
    {
        do
        {
            buf[i++] = c;
            c = fgetc(file1);
            updateLineAndCol(c);
        } while (isalnum(c));
        buf[i++] = '\0';

        // printf("'%s' ", buf);
        returnToken->lexeme = calloc(strlen(buf), sizeof(char));
        strcpy(returnToken->lexeme, buf);

        if (isKeyword(buf))
        {
            // printf("is a keyword\n");

            //keep track line and column no. and add to the struct
            returnToken->type = KEYWORD;
            returnToken->row = lc;
            returnToken->col = cc;
        }
        else
        {
            // printf("is an identifier\n");
            returnToken->type = IDENTIFIER;
            returnToken->row = lc;
            returnToken->col = cc;
        }

        retract(file1, c2);
        return returnToken;
    }
    // number recognition is remaining
    if (c >= '0' && c <= '9')
    {
        i = 0;
        c2 = c;
        do
        {
            buf[i++] = c2;
            c2 = fgetc(file1);
            updateLineAndCol(c2);

        } while (c2 >= '0' && c2 <= '9');
        retract(file1, c2);

        buf[i++] = '\0';
        // printf("Encountered number '%s'\n", buf);
        returnToken->lexeme = calloc(strlen(buf), sizeof(char));
        strcpy(returnToken->lexeme, buf);
        returnToken->type = NUM;
        returnToken->row = lc;
        returnToken->col = cc;
        return returnToken;
    }
    // also for "___________"'s
    if (c == '\"')
    {
        i = 0;
        c2 = c;
        do
        {
            buf[i++] = c2;
            c2 = fgetc(file1);
            updateLineAndCol(c2);
        } while (c2 != '\"');
        buf[i++] = '\"';
        buf[i++] = '\0';

        returnToken->lexeme = calloc(strlen(buf), sizeof(char));
        strcpy(returnToken->lexeme, buf);
        returnToken->type = LIT;
        returnToken->row = lc;
        returnToken->col = cc;
        return returnToken;
    }

    if (c == ' ' || c == '\t' || c == '\n')
    {
        do
        {
            c2 = fgetc(file1);
            updateLineAndCol(c2);
        } while (c2 == ' ' || c2 == '\t' || c2 == '\n');

        returnToken->lexeme = calloc(1, sizeof(char));
        returnToken->lexeme[0] = c;
        returnToken->type = WS;
        returnToken->row = lc;
        returnToken->col = cc;
        retract(file1, c2);
        return returnToken;
    }

    switch (c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
        c2 = fgetc(file1);
        updateLineAndCol(c2);
        if (c2 == '=')
        {
            returnToken->lexeme = calloc(2, sizeof(char));
            returnToken->lexeme[0] = c;
            returnToken->lexeme[1] = '=';
            //keep track of line no and col no.
            returnToken->type = OP_ASS;
            returnToken->row = lc;
            returnToken->col = cc;
            return returnToken;
        }
        else if (c == '+' && c2 == '+')
        {
            returnToken->lexeme = calloc(2, sizeof(char));
            returnToken->lexeme[0] = c;
            returnToken->lexeme[1] = '+';
            returnToken->type = INC;
            returnToken->row = lc;
            returnToken->col = cc;
            return returnToken;
        }
        else if (c == '-' && c2 == '-')
        {
            returnToken->lexeme = calloc(2, sizeof(char));
            returnToken->lexeme[0] = c;
            returnToken->lexeme[1] = '-';
            returnToken->type = DEC;
            returnToken->row = lc;
            returnToken->col = cc;
            return returnToken;
        }
        else
        {
            returnToken->lexeme = calloc(1, sizeof(char));
            returnToken->lexeme[0] = c;
            returnToken->type = AOP;
            returnToken->row = lc;
            returnToken->col = cc;
            retract(file1, c2);
            return returnToken;
        }
        break;

    case '{':
        returnToken->lexeme = calloc(1, sizeof(char));
        returnToken->lexeme[0] = c;
        returnToken->type = LCB;
        returnToken->row = lc;
        returnToken->col = cc;
        return returnToken;

    case '}':
        returnToken->lexeme = calloc(1, sizeof(char));
        returnToken->lexeme[0] = c;
        returnToken->type = RCB;
        returnToken->row = lc;
        returnToken->col = cc;
        return returnToken;

    case '(':
        returnToken->lexeme = calloc(1, sizeof(char));
        returnToken->lexeme[0] = c;
        returnToken->type = LP;
        returnToken->row = lc;
        returnToken->col = cc;
        return returnToken;

    case ')':
        returnToken->lexeme = calloc(1, sizeof(char));
        returnToken->lexeme[0] = c;
        returnToken->type = RP;
        returnToken->row = lc;
        returnToken->col = cc;
        return returnToken;

    case '[':
        returnToken->lexeme = calloc(1, sizeof(char));
        returnToken->lexeme[0] = c;
        returnToken->type = LSB;
        returnToken->row = lc;
        returnToken->col = cc;
        return returnToken;

    case ']':
        returnToken->lexeme = calloc(1, sizeof(char));
        returnToken->lexeme[0] = c;
        returnToken->type = RSB;
        returnToken->row = lc;
        returnToken->col = cc;
        return returnToken;

        // Relational operators and '='
    case '<':
        c2 = fgetc(file1);
        updateLineAndCol(c2);
        if (c2 == '=')
        {
            returnToken->lexeme = calloc(2, sizeof(char));
            returnToken->lexeme[0] = c;
            returnToken->lexeme[1] = c2;
            returnToken->type = LTE;
            returnToken->row = lc;
            returnToken->col = cc;
            return returnToken;
        }
        else
        {
            returnToken->lexeme = calloc(1, sizeof(char));
            returnToken->lexeme[0] = c;
            returnToken->type = LT;
            returnToken->row = lc;
            returnToken->col = cc;
            retract(file1, c2);
            return returnToken;
        }
    case '>':
        c2 = fgetc(file1);
        updateLineAndCol(c2);
        if (c2 == '=')
        {
            returnToken->lexeme = calloc(2, sizeof(char));
            returnToken->lexeme[0] = c;
            returnToken->lexeme[1] = c2;
            returnToken->type = GTE;
            returnToken->row = lc;
            returnToken->col = cc;
            return returnToken;
        }
        else
        {
            returnToken->lexeme = calloc(1, sizeof(char));
            returnToken->lexeme[0] = c;
            returnToken->type = GT;
            returnToken->row = lc;
            returnToken->col = cc;
            retract(file1, c2);
            return returnToken;
        }
    case '!':
        c2 = fgetc(file1);
        updateLineAndCol(c2);
        if (c2 == '=')
        {
            returnToken->lexeme = calloc(2, sizeof(char));
            returnToken->lexeme[0] = c;
            returnToken->lexeme[1] = c2;
            returnToken->type = NE;
            returnToken->row = lc;
            returnToken->col = cc;
            return returnToken;
        }
        else
        {
            returnToken->lexeme = calloc(1, sizeof(char));
            returnToken->lexeme[0] = c;
            returnToken->type = BNOT;
            returnToken->row = lc;
            returnToken->col = cc;
            retract(file1, c2);
            return returnToken;
        }
    case '=':
        c2 = fgetc(file1);
        updateLineAndCol(c2);
        if (c2 == '=')
        {
            returnToken->lexeme = calloc(2, sizeof(char));
            returnToken->lexeme[0] = c;
            returnToken->lexeme[1] = c2;
            returnToken->type = EQ;
            returnToken->row = lc;
            returnToken->col = cc;
            return returnToken;
        }
        else
        {
            returnToken->lexeme = calloc(1, sizeof(char));
            returnToken->lexeme[0] = c;
            returnToken->type = ASS;
            returnToken->row = lc;
            returnToken->col = cc;
            retract(file1, c2);
            return returnToken;
        }

    case ',':
    case ';':
        returnToken->lexeme = calloc(1, sizeof(char));
        returnToken->lexeme[0] = c;
        returnToken->type = SS;
        returnToken->row = lc;
        returnToken->col = cc;
        // retract(file1, c2);
        return returnToken;
    case '&':
        c2 = fgetc(file1);
        if (c2 == '&')
        {
            returnToken->lexeme = calloc(2, sizeof(char));
            returnToken->lexeme[0] = c;
            returnToken->lexeme[1] = c2;
            returnToken->type = LAND;
            returnToken->row = lc;
            returnToken->col = cc;
            return returnToken;
        }
        else
        {
            returnToken->lexeme = calloc(1, sizeof(char));
            returnToken->lexeme[0] = c;
            returnToken->type = BAND;
            returnToken->row = lc;
            returnToken->col = cc;
            retract(file1, c2);
            return returnToken;
        }
    case '|':
        c2 = fgetc(file1);
        updateLineAndCol(c2);
        if (c2 == '|')
        {
            returnToken->lexeme = calloc(2, sizeof(char));
            returnToken->lexeme[0] = c;
            returnToken->lexeme[1] = c2;
            returnToken->type = LOR;
            returnToken->row = lc;
            returnToken->col = cc;
            return returnToken;
        }
        else
        {
            returnToken->lexeme = calloc(1, sizeof(char));
            returnToken->lexeme[0] = c;
            returnToken->type = BOR;
            returnToken->row = lc;
            returnToken->col = cc;
            retract(file1, c2);
            return returnToken;
        }
    case '^':
        returnToken->lexeme = calloc(1, sizeof(char));
        returnToken->lexeme[0] = c;
        returnToken->type = XOR;
        returnToken->row = lc;
        returnToken->col = cc;
        return returnToken;
    default:
        return NULL;
    }
}

int lexicalAnalysis(char *FILENAME, char *FILENAME2)
{
    FILE *file1 = fopen(FILENAME, "r");
    FILE *file2 = fopen(FILENAME2, "w");
    for (Token *i = getNextToken(file1); i != NULL; i = getNextToken(file1))
    {
        if (i->type == WS)
            continue;

        fprintf(file2, "%s\tLine: %i\tColumn: %i\tType: %i\n", i->lexeme, i->row, i->col, i->type);
    }

    fclose(file1);
    fclose(file2);
    return 0;
}

int main(int argc, char const *argv[])
{
    char input[20];
    // char output[20];
    printf("Input file\n");
    scanf("%s", input);
    // scanf("%s", output);
    if (removeComments(input, "fileOutput.c") != 0)
    {
        printf("Some error occurred in removing comments\n");
        return 1;
    }
    if (ignorePreprocessorDirectives("fileOutput.c", input) != 0)
    {
        printf("Some error occurred in ignoring preprocessor directives\n");
        return 1;
    }

    if (lexicalAnalysis(input, "tokenStream.txt") != 0)
    {
        perror("Some error occurred in lexical analysis\n");
        return 1;
    }

    printf("Done! Check output file\n");
    return 0;
}