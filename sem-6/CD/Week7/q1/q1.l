%{
#include <stdio.h>
#include <stdlib.h>
#include "q1.tab.h"

int lc = 1, cc = 1;

typedef struct $
{
    char *lexeme;
    int index;
    unsigned int row, col;
    unsigned int type;
} Token;

Token *retToken = NULL;

Token *allocToken()
{
    retToken = (Token *)malloc(sizeof(Token));
    retToken->index = -1;
    retToken->type = -1;
    return retToken;
}

void assignValues(Token *retToken, char *lexeme, int len, int index, unsigned int lc, unsigned int cc, unsigned int type)
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
    // printf("<%s\tLine No: %i\tCol No: %i\tType: %i\tIndex: %i>\n", retToken->lexeme, retToken->row, retToken->col, retToken->type, retToken->index);
    return;
}

Token *retToken;
%}

letter_ [a-zA-Z_]
letters {letter_}+
digit [0-9]
digits {digit}+
keywords "int"|"char"|"float"|"double"|"long"

%%

{digits}+ {
    assignValues(retToken, yytext, yyleng, -1, 0, 0, NUM);
    return retToken->type;
}

{keywords} {
    assignValues(retToken, yytext, yyleng, -1, 0, 0, DT);
    return retToken->type;
}

{letter_}({letter_}|{digit})* {
    assignValues(retToken, yytext, yyleng, -1, 0, 0, ID);
    return retToken->type;
}


";" {
    assignValues(retToken, yytext, yyleng, -1, 0, 0, SC);
    return retToken->type;
}
"[" {
    assignValues(retToken, yytext, yyleng, -1, 0, 0, LSB);
    return retToken->type;
}
"]" {
    assignValues(retToken, yytext, yyleng, -1, 0, 0, RSB);
    return retToken->type;
}
"," {
    assignValues(retToken, yytext, yyleng, -1, 0, 0, COMMA);
    return retToken->type;
}

%%

int yywrap()
{
    return 1;
}