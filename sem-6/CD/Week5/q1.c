#include "RDParser.h"

int S();
int T();
int T1();

int S()
{
    printf("In S\n");
    if(tk == NULL)
    {
        return 0;
    }
    else if (tk->type == LIT && strcmp(tk->buf, "a") == 0)
    {
        return 1;
    }
    else if (tk->type == GT)
    {
        return 1;
    }
    else if (tk->type == LB)
    {
        tk = getNextToken();
        int ret = T();
        if (ret > 0)
        {
            if (ret == 1)
            {
                tk = getNextToken();
            }

            // printf("Scanning %s\n", tk->buf);
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
            return 0;
    }
    else
    {
        return 0;
    }
}

int T()
{
    printf("In T\n");
    int ret = S();
    if (ret)
    {
        tk = getNextToken();
        return T1();
    }
}

int T1()
{
    printf("In T1\n");
    if (tk->type == COMMA)
    {
        tk = getNextToken();
        int ret = S();
        if (ret)
        {
            tk = getNextToken();
            return T1();
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 2;
    }
}

int main(int argc, char *argv[])
{
    init();
    for (int i = 0; i < 17; i++)
    {
        streamOfTokens[i] = allocToken();
    }
    setTokenArgs(streamOfTokens[0], "(", 0, 0, LB);
    setTokenArgs(streamOfTokens[1], "(", 0, 0, LB);
    setTokenArgs(streamOfTokens[2], "a", 0, 0, LIT);
    setTokenArgs(streamOfTokens[3], ",", 0, 0, COMMA);
    setTokenArgs(streamOfTokens[4], ">", 0, 0, GT);
    setTokenArgs(streamOfTokens[5], ",", 0, 0, COMMA);
    setTokenArgs(streamOfTokens[6], "a", 0, 0, LIT);
    setTokenArgs(streamOfTokens[7], ")", 0, 0, RB);
    setTokenArgs(streamOfTokens[8], ",", 0, 0, COMMA);
    setTokenArgs(streamOfTokens[9], "(", 0, 0, LB);
    setTokenArgs(streamOfTokens[10], ">", 0, 0, GT);
    setTokenArgs(streamOfTokens[11], ",", 0, 0, COMMA);
    setTokenArgs(streamOfTokens[12], ">", 0, 0, GT);
    setTokenArgs(streamOfTokens[13], ",", 0, 0, COMMA);
    setTokenArgs(streamOfTokens[14], ">", 0, 0, GT);
    setTokenArgs(streamOfTokens[15], ")", 0, 0, RB);
    setTokenArgs(streamOfTokens[16], ")", 0, 0, RB);
    streamOfTokens[17] = NULL;
    printf("Tokens allocated\n");
    tk = getNextToken();
    if (S())
    {
        printf("String accepted\n");
    }
    else
    {
        printf("String not accepted\n");
    }

    return 0;
}