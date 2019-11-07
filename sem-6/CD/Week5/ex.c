#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum tokens
{
    EOFO = -1,
    AO,
    keyword,
    identifier,
    LT,
    LTE,
    GT,
    GTE,
    EQ,
    NE,
    LO,
    BO,
    SYM,
    LB,
    RB,
    LC,
    RC,
    LS,
    RS,
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
Token *getNextToken()
{
    static int i = 0;
    return streamOfTokens[i++];
}

int T(Token *tk)
{
    if (tk == NULL)
    {
        return 1;
    }

    printf("Lexeme: %s\tLine no: %d\tCol No: %d\tType: %d\n", tk->buf, tk->lc, tk->cc, tk->type);
    if (tk->type == ARITHOP && strcmp(tk->buf, "*") == 0)
    {
        tk = getNextToken();

        printf("Lexeme: %s\tLine no: %d\tCol No: %d\tType: %d\n", tk->buf, tk->lc, tk->cc, tk->type);
        if (tk->type == NUM)
        {
            return T(getNextToken());
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

int E(Token *tk)
{
    printf("Lexeme: %s\tLine no: %d\tCol No: %d\tType: %d\n", tk->buf, tk->lc, tk->cc, tk->type);
    if (tk->type = NUM)
    {
        tk = getNextToken();
        return T(tk);
    }
    else
    {
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    streamOfTokens = calloc(10, sizeof(Token *));
    streamOfTokens[0] = allocToken();
    streamOfTokens[1] = allocToken();
    streamOfTokens[2] = allocToken();
    streamOfTokens[3] = allocToken();
    streamOfTokens[4] = allocToken();
    streamOfTokens[5] = allocToken();
    streamOfTokens[6] = allocToken();
    streamOfTokens[7] = NULL;
    setTokenArgs(streamOfTokens[0], "30", 0, 0, NUM);
    setTokenArgs(streamOfTokens[1], "*", 0, 0, ARITHOP);
    setTokenArgs(streamOfTokens[2], "50", 0, 0, NUM);
    setTokenArgs(streamOfTokens[3], "*", 0, 0, ARITHOP);
    setTokenArgs(streamOfTokens[4], "80", 0, 0, NUM);
    setTokenArgs(streamOfTokens[5], "*", 0, 0, ARITHOP);
    setTokenArgs(streamOfTokens[6], "1000", 0, 0, NUM);
    // printf("Token allocated\n");
    int result = E(getNextToken());
    if (result)
    {
        printf("String accepted\n");
    }
    else
    {
        printf("String not accepted\n");
    }

    return 0;
}
