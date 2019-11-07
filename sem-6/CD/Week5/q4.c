#include "RDParser.h"

int L();
int L1();
int A();
int LS();
int LS1();

int L()
{
    if (tk->type == NUM || tk->type == identifier)
    {
        return A();
    }
    else if (tk->type == LB)
    {
        return L1();
    }
    else
    {
        return 0;
    }
}

int A()
{
    if (tk->type == NUM || tk->type == identifier)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int L1()
{
    if (tk->type == LB)
    {
        tk = getNextToken();
        int ret = LS();
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

int LS()
{
    int res = L();
    if (res)
    {
        tk = getNextToken();
        return LS1();
    }
    else
    {
        return 0;
    }
}

int LS1()
{
    if (tk->type == RB)
    {
        return 2;
    }
    else
    {
        int res = L();
        if (res)
        {
            tk = getNextToken();
            return LS1();
        }
    }
}

int main(int argc, char const *argv[])
{
    init();
    for (int i = 0; i < 14; i++)
    {
        streamOfTokens[i] = allocToken();
    }

    setTokenArgs(streamOfTokens[0], "(", 0, 0, LB);
    setTokenArgs(streamOfTokens[1], "(", 0, 0, LB);
    setTokenArgs(streamOfTokens[2], "32409", 0, 0, NUM);
    setTokenArgs(streamOfTokens[3], "num1", 0, 0, identifier);
    setTokenArgs(streamOfTokens[4], ")", 0, 0, RB);
    setTokenArgs(streamOfTokens[5], "(", 0, 0, LB);
    setTokenArgs(streamOfTokens[6], "num2", 0, 0, identifier);
    setTokenArgs(streamOfTokens[7], "18927", 0, 0, NUM);
    setTokenArgs(streamOfTokens[8], "3789", 0, 0, NUM);
    setTokenArgs(streamOfTokens[9], ")", 0, 0, RB);
    setTokenArgs(streamOfTokens[10], "(", 0, 0, LB);
    setTokenArgs(streamOfTokens[11], "138902", 0, 0, NUM);
    setTokenArgs(streamOfTokens[12], ")", 0, 0, RB);
    setTokenArgs(streamOfTokens[13], ")", 0, 0, RB);

    printf("Token args\n");
    tk = getNextToken();
    if (L())
    {
        printf("String accepted\n");
    }
    else
    {
        printf("String not accepted\n");
    }

    return 0;
}