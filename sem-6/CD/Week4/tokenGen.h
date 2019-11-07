#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int lc = 1, cc = 1;
enum types
{
    KW,
    ID,
    NUM,
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
    INC,
    DEC,
    OP_ASS,
    AOP,
    LOR,
    LAND,
    BNOT,
    BOR,
    BAND,
    XOR,
    SC,
    COMMA,
    LIT,
    EOFILE
};

typedef struct $
{
    char *lexeme;
    int index;
    unsigned int row, col;
    enum types type;
} Token;

Token *retToken = NULL;

Token *allocToken()
{
    retToken = (Token *)malloc(sizeof(Token));
    retToken->index = -1;
    retToken->type = EOFILE;
    return retToken;
}

void assignValues(Token *retToken, char *lexeme, int len, int index, unsigned int lc, unsigned int cc, enum types type)
{
    retToken = allocToken();
    retToken->lexeme = (char *)calloc(len, sizeof(char));
    strcpy(retToken->lexeme, lexeme);
    retToken->row = lc;
    if (type == ID)
    {
        retToken->index = index;
    }
    retToken->col = cc;
    retToken->type = type;

    fprintf(yyout, "<%s\tLine No: %i\tCol No: %i\tType: %i\tIndex: %i>\n", retToken->lexeme, retToken->row, retToken->col, retToken->type, retToken->index);
    return;
}