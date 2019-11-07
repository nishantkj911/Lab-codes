#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int lc = 1, cc = 1, prevCC = 1;
enum types
{
    KW,
    ID,
    NUM,
    LSB,
    RSB,
    LP,
    RP,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    MATHOP,
    EQ,
    LCB,
    RCB,
    INC,
    COMMA,
    SC,
    SS,
};

typedef struct a
{
    unsigned int lc, cc;
    char *lexeme;
    enum types type;

} Token;
char keywords[][20] = {"scalar", "foreach"};
int isKeyword(char *buf)
{
    for (int i = 0; i < sizeof(keywords) / 20; i++)
    {
        if (strcmp(keywords[i], buf) == 0)
        {
            return 1;
        }
    }

    return 0;
}

Token *genToken(char *buf, int lc, int cc, enum types type)
{
    Token *tp = malloc(sizeof(Token));
    tp->type = type;
    tp->lc = lc;
    tp->cc = cc;
    tp->lexeme = calloc(strlen(buf), sizeof(char));
    strcpy(tp->lexeme, buf);

    return tp;
}
Token *getNextToken(FILE *f)
{
    char *buf = calloc(100, sizeof(char));
    int i = 0;
    char c, c2;
    c = fgetc(f);
    while (c == ' ' || c == '\t' || c == '\n')
    {
        c = fgetc(f);
    }
    if (c == '$') //ID's
    {
        do
        {
            buf[i++] = c;
            c = fgetc(f);
        } while (isalnum(c) || c == '_');
        buf[i++] = '\0';
        fseek(f, -1, SEEK_CUR);

        return genToken(buf, lc, cc, ID);
    }
    else if (isalpha(c) || c == '_')
    {
        c2 = c;
        do
        {
            buf[i++] = c2;
            c2 = fgetc(f);
        } while (isalnum(c2) || c2 == '_');
        buf[i++] = '\0';
        if (isKeyword(buf))
        {
            return genToken(buf, lc, cc, KW);
        }
    }
    else if (c >= '0' && c <= '9')
    {
        do
        {
            buf[i++] = c;
            c = fgetc(f);
        } while (c >= '0' && c <= '9');
        buf[i++] = '\0';

        fseek(f, -1, SEEK_CUR);
        return genToken(buf, lc, cc, NUM);
    }

    switch (c)
    {
    case '+':
        buf[i++] = c;
        c2 = fgetc(f);
        if (c2 == '=')
        {
            buf[i++] = c2;
            buf[i++] = '\0';
            return genToken(buf, lc, cc, INC);
        }
        buf[i++] = '\0';
        return genToken(buf, lc, cc, PLUS);

    case '@':
        buf[i++] = c;
        c2 = fgetc(f);
        if (c2 == '_')
        {
            buf[i++] = c2;
            buf[i++] = '\0';
            return genToken(buf, lc, cc, MATHOP);
        }
        buf[i++] = '\0';
        return genToken(buf, lc, cc, SS);
    case '[':
        buf[i++] = c;
        buf[i++] = '\0';
        return genToken(buf, lc, cc, LSB);
    case ']':
        buf[i++] = c;
        buf[i++] = '\0';
        return genToken(buf, lc, cc, RSB);
    case '(':
        buf[i++] = c;
        buf[i++] = '\0';
        return genToken(buf, lc, cc, LP);
    case ')':
        buf[i++] = c;
        buf[i++] = '\0';
        return genToken(buf, lc, cc, RP);
    case '{':
        buf[i++] = c;
        buf[i++] = '\0';
        return genToken(buf, lc, cc, LCB);
    case '}':
        buf[i++] = c;
        buf[i++] = '\0';
        return genToken(buf, lc, cc, RCB);
    case '=':
        buf[i++] = c;
        buf[i++] = '\0';
        return genToken(buf, lc, cc, EQ);
    }

    if (c != EOF)
    {
        buf[i++] = c;
        buf[i++] = '\0';
        return genToken(buf, lc, cc, SS);
    }
    else
    {
        return NULL;
    }
}

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        printf("Usage: ./eval1.c fileInput.c output.txt\n");
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    FILE *fp2 = fopen(argv[2], "w");

    char c, c2;
    c = fgetc(fp);
    printf("Read: %c\n", c);
    while (c == '#')
    {
        if (c == '#')
        {
            while (c != '\n') //preprocessor and comments
            {
                c = fgetc(fp);
                printf("Read Loop: '%c'\n", c);
            }
        }
        c = fgetc(fp);
    }
    fseek(fp, -1, SEEK_CUR);

    for (Token *i = getNextToken(fp); i != NULL; i = getNextToken(fp))
    {
        fprintf(fp2, "Lexeme: %s, Type: %i, Line: %u, Col: %u\n", i->lexeme, i->type, i->lc, i->cc);
    }

    printf("Done! Check output file\n");
    return 0;
}
