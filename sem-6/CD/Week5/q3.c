#include "RDParser.h"

int S();
int B();
int A();
int A1();

int B()
{
    printf("In B\n");
    if (tk->type == LIT && strcmp(tk->buf, "d") == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int A()
{
    printf("In A\n");
    if (tk->type == LIT && strcmp(tk->buf, "b") == 0)
    {
        tk = getNextToken();
        return A1();
    }
}
int A1()
{
    printf("In A1\n");
    if (tk->type == LIT && strcmp(tk->buf, "b") == 0)
    {
        tk = getNextToken();
        return A1();
    }
    else
    {
        return 2;
    }
}

int S()
{
    printf("In S\n");
    if (tk->type == LIT && strcmp(tk->buf, "a") == 0)
    {
        tk = getNextToken();
        int ret = A();
        if (ret)
        {
            if (ret == 1)
            {
                tk = getNextToken();
            }
            if (tk->type == LIT && strcmp(tk->buf, "c") == 0)
            {
                tk = getNextToken();
                ret = B();
                if (ret)
                {
                    tk = getNextToken();
                    if (tk->type == LIT && strcmp(tk->buf, "e") == 0)
                    {
                        return 1;
                    }
                }
            }
        }
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    init();
    for (int i = 0; i < 25; i++)
    {
        streamOfTokens[i] = allocToken();
    }
    setTokenArgs(streamOfTokens[0], "a", 0, 0, LIT);
    setTokenArgs(streamOfTokens[1], "b", 0, 0, LIT);
    setTokenArgs(streamOfTokens[2], "b", 0, 0, LIT);
    setTokenArgs(streamOfTokens[3], "b", 0, 0, LIT);
    setTokenArgs(streamOfTokens[4], "b", 0, 0, LIT);
    setTokenArgs(streamOfTokens[5], "b", 0, 0, LIT);
    setTokenArgs(streamOfTokens[6], "b", 0, 0, LIT);
    setTokenArgs(streamOfTokens[7], "b", 0, 0, LIT);
    setTokenArgs(streamOfTokens[8], "b", 0, 0, LIT);
    setTokenArgs(streamOfTokens[9], "b", 0, 0, LIT);
    setTokenArgs(streamOfTokens[10], "b", 0, 0, LIT);
    setTokenArgs(streamOfTokens[11], "b", 0, 0, LIT);
    setTokenArgs(streamOfTokens[12], "b", 0, 0, LIT);
    setTokenArgs(streamOfTokens[13], "b", 0, 0, LIT);
    setTokenArgs(streamOfTokens[14], "b", 0, 0, LIT);
    setTokenArgs(streamOfTokens[15], "b", 0, 0, LIT);
    setTokenArgs(streamOfTokens[16], "b", 0, 0, LIT);
    setTokenArgs(streamOfTokens[17], "b", 0, 0, LIT);
    setTokenArgs(streamOfTokens[18], "b", 0, 0, LIT);
    setTokenArgs(streamOfTokens[19], "b", 0, 0, LIT);
    setTokenArgs(streamOfTokens[20], "b", 0, 0, LIT);
    setTokenArgs(streamOfTokens[21], "b", 0, 0, LIT);
    setTokenArgs(streamOfTokens[22], "c", 0, 0, LIT);
    setTokenArgs(streamOfTokens[23], "d", 0, 0, LIT);
    setTokenArgs(streamOfTokens[24], "e", 0, 0, LIT);
    streamOfTokens[25] = NULL;
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
