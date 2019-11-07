#include "RDParser.h"

int E();
int E1();
int T();
int T1();
int F();

int E()
{
    printf("In E\n");
    int ret = T();
    if (ret)
    {
        if (ret == 1)
        {
            tk = getNextToken();
        }
        return E1();
    }
}

int T()
{
    printf("In T\n");
    int ret = F();
    if (ret)
    {
        if (ret == 1)
        {
            tk = getNextToken();
        }
        return T1();
    }
}

int F()
{
    printf("In F\n");
    if (tk->type == identifier)
    {
        printf("Identifier\n");
        return 1;
    }
    else if (tk->type == LB)
    {
        tk = getNextToken();
        int ret = E();
        if (ret)
        {
            if (ret == 1)
            {
                tk = getNextToken();
            }
            if (tk->type == RB)
            {
                return 1;
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
    else
    {
        return 0;
    }
}

int E1()
{
    printf("In E1\n");
    if (tk == NULL)
    {
        return 2;
    }
    if (tk->type == ARITHOP && strcmp(tk->buf, "+") == 0)
    {
        tk = getNextToken();
        int ret = T();
        if (ret)
        {
            if (ret == 1)
            {
                tk = getNextToken();
            }
            return E1();
        }
    }
    else
    {
        return 2;
    }

    // return 0;
}

int T1()
{
    printf("In T1\n");
    if (tk == NULL)
    {
        return 2;
    }
    if (tk->type == ARITHOP && strcmp(tk->buf, "*") == 0)
    {
        tk = getNextToken();
        int ret = F();
        if (ret)
        {
            if (ret == 1)
            {
                tk = getNextToken();
                return T1();
            }
            else
                return 0;
        }
        else
            return 0;
    }
    else
    {
        return 2;
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    init();
    for (int i = 0; i < 17; i++)
    {
        streamOfTokens[i] = allocToken();
    }
    setTokenArgs(streamOfTokens[0], "(", 0, 0, LB);
    setTokenArgs(streamOfTokens[1], "(", 0, 0, LB);
    setTokenArgs(streamOfTokens[2], "(", 0, 0, LB);
    setTokenArgs(streamOfTokens[3], "n1", 0, 0, identifier);
    setTokenArgs(streamOfTokens[4], "*", 0, 0, ARITHOP);
    setTokenArgs(streamOfTokens[5], "n2", 0, 0, identifier);
    setTokenArgs(streamOfTokens[6], ")", 0, 0, RB);
    setTokenArgs(streamOfTokens[7], "+", 0, 0, ARITHOP);
    setTokenArgs(streamOfTokens[8], "(", 0, 0, LB);
    setTokenArgs(streamOfTokens[9], "n3", 0, 0, identifier);
    setTokenArgs(streamOfTokens[10], "*", 0, 0, ARITHOP);
    setTokenArgs(streamOfTokens[11], "n4", 0, 0, identifier);
    setTokenArgs(streamOfTokens[12], ")", 0, 0, RB);
    setTokenArgs(streamOfTokens[13], ")", 0, 0, RB);
    setTokenArgs(streamOfTokens[14], "+", 0, 0, ARITHOP);
    setTokenArgs(streamOfTokens[15], "n5", 0, 0, identifier);
    setTokenArgs(streamOfTokens[16], ")", 0, 0, RB);

    /* setTokenArgs(streamOfTokens[0], "(", 0, 0, LB);
    setTokenArgs(streamOfTokens[1], "n1", 0, 0, identifier);
    setTokenArgs(streamOfTokens[2], "+", 0, 0, ARITHOP);
    setTokenArgs(streamOfTokens[3], "n2", 0, 0, identifier);
    setTokenArgs(streamOfTokens[4], ")", 0, 0, RB); */

    streamOfTokens[17] = NULL;
    printf("Token args\n");
    tk = getNextToken();
    if (E())
    {
        printf("String accepted\n");
    }
    else
    {
        printf("String not accepted\n");
    }

    return 0;
}
