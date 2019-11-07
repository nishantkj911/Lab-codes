#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// return 2 indicates that there is no input being consumed

enum tokens
{
    EOFO = -1,
    AO,
    keyword,
    identifier,
    LT,
    LTE,
    GT,
    LIT,
    GTE,
    EQ,
    NE,
    LO,
    BO,
    SYM,
    LB,
    RB,
    LCB,
    RCB,
    LSB,
    RSB,
    SC,
    COMMA,
    NUM,
    ARITHOP,
    ASS
};

typedef struct token
{
    int lc, cc;
    char *buf;
    int index;
    enum tokens type;
} Token;

Token *allocToken()
{
    Token *tk;
    tk = malloc(sizeof(Token));
    tk->buf = malloc(sizeof(char) * 256);
    tk->index = -1;
    tk->type = EOFO;
    return tk;
}

void setTokenArgs(Token *tk, char *buf, int l, int c, enum tokens type)
{
    if (tk == NULL)
        return;
    strcpy(tk->buf, buf);
    tk->lc = l;
    tk->cc = c;
    tk->type = type;
    // fprintf(yyout, "Lexeme: %s\tLine no: %d\tCol No: %d\tType: %d\n", tk->buf, tk->lc, tk->cc, tk->type);
    // cnt++;
}

Token **streamOfTokens;
void init()
{
    streamOfTokens = calloc(100, sizeof(Token *));
    for (int i = 0; i < 100; i++)
    {
        streamOfTokens[i] = NULL;
    }
}
Token *getNextToken()
{
    static int i = 0;
    Token *tk = streamOfTokens[i];
    tk != NULL ? printf("Lexeme: %s\tLine no: %d\tCol No: %d\tType: %d\n", tk->buf, tk->lc, tk->cc, tk->type) : printf("Null token\n");
    return streamOfTokens[i++];
}

Token *tk;