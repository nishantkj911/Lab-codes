
%{
#include <string.h>
#include "symbolTable.h"
#include "tokenGen.h"
// Need to add scope of variable in the symbolTable

char datatypeBuf[100];
char errorBuf[100];
Token *tk = NULL;
int expr();
int stList();
int id1();
int id2();
int assSt();
#define YY_DECL Token *yylex(void)
%}

letter_ [a-z_A-Z]
letters {letter}+
digit [0-9]
digits {digit}+
keywords "int"|"char"|"long"|"float"|"const"|"double"|"return"|"for"|"if"|"else"|"break"|"continue"|"switch"|"case"|"while"|"do"

%%

^#(.)*"\n" {
    lc++; cc=1;
}

"//"(.)*"\n" {lc++; cc=1;}

"/*"(.)*"*/" {int i = 0;
    while (yytext[i] != '\0')
    {
        if(yytext[i] == '\n')
        {
            cc = 1; lc++;
        }
        else
        {
            cc++;
        }

        i++;
    }
}

\n {lc++; cc=1;}

\"(.)*\" {
    assignValues(retToken, yytext, yyleng, -1, lc, cc, LIT);
    cc+=yyleng;
    return retToken;
}

\'(.)\' {
    assignValues(retToken, yytext, yyleng, -1, lc, cc, LIT);
    cc++;
    return retToken;
}

"<" {
    assignValues(retToken, yytext, yyleng, -1, lc, cc, LT);
    cc++;
    return retToken;
    }
"<=" {
    assignValues(retToken, yytext, yyleng, -1, lc, cc, LTE);
    cc+=2;
    return retToken;
}
">" {
    assignValues(retToken, yytext, yyleng, -1, lc, cc, GT);
    cc++;
    return retToken;
    }
">=" {
    assignValues(retToken, yytext, yyleng, -1, lc, cc, GTE);
    cc+=2;
    return retToken;
}
"==" {
    assignValues(retToken, yytext, yyleng, -1, lc, cc, EQ);
    cc+=2;
    return retToken;
}
"!=" {
    assignValues(retToken, yytext, yyleng, -1, lc, cc, NE);
    cc+=2;
    return retToken;
}
{keywords} {
    assignValues(retToken, yytext, yyleng, -1, lc, cc, KW);
    cc+=yyleng;
    strcpy(datatypeBuf, yytext);
    return retToken;
}

{letter_}({letter_}|{digit})* {

    static int index = 0;

    char *str = calloc(strlen(yytext), sizeof(char));
    strcpy(str, yytext);
    char *idType = calloc(20, sizeof(char));
    char *returnType = calloc(20, sizeof(char));
    /* size_t size = 0;

    if (nextToken->type == LP) //function
    {
        strcpy(idType, "function");
        strcpy(returnType, datatypeBuf);
    }
    else if(nextToken->type == LSB)
    {
        strcpy(idType, "array");
        nextToken = yylex();
        if(nextToken->type == NUM)
        {
            size = toNumber(nextToken->lexeme);

            if(strcmp(datatypeBuf, "int") == 0)
            {
                size*= sizeof(int);
            }
            else if(strcmp(datatypeBuf, "char") == 0)
            {
                size*= sizeof(char);
            }
            else if(strcmp(datatypeBuf, "double") == 0)
            {
                size*= sizeof(double);
            }
            else if(strcmp(datatypeBuf, "float") == 0)
            {
                size*= sizeof(float);
            }
        }
        else
        {
            printf("Invalid Syntax\n");
        }
    }
    else if(nextToken->type == COMMA || nextToken->type == SC || nextToken->type == ASS)
    {
        strcpy(idType, "variable");
    }

    manageID(str, &index, idType, size, returnType); */
    assignValues(retToken, yytext, yyleng, index++, lc, cc, ID);
    cc+=yyleng;
    return retToken;
}

")" {
    assignValues(retToken, yytext, yyleng, -1, lc, cc, RP);
    cc++;
    return retToken;
}

"{" {
    assignValues(retToken, yytext, yyleng, -1, lc, cc, LCB);
    cc++;
    return retToken;
}

"}" {
    assignValues(retToken, yytext, yyleng, -1, lc, cc, RCB);
    cc++;
    return retToken;
}

"[" {
    assignValues(retToken, yytext, yyleng, -1, lc, cc, LSB);
    cc++;
    return retToken;
}

"]" {
    assignValues(retToken, yytext, yyleng, -1, lc, cc, RSB);
    cc++;
    return retToken;
}

"(" {
    assignValues(retToken, yytext, yyleng, -1, lc, cc, LP);
    cc++;
    return retToken;
}

"=" {
    assignValues(retToken, yytext, yyleng, -1, lc, cc, ASS);
    cc++;
    return retToken;
}

" " {cc++;}

\t {cc+=4;}

"+="|"-="|"*="|"/="|"%=" {
    assignValues(retToken, yytext, yyleng, -1, lc, cc, OP_ASS);
    cc+=2;
    return retToken;
}

"+"?{digit}+|"+"?{digit}+.{digit}+|-{digit}+|-{digit}+.{digit}+ {
    assignValues(retToken, yytext, yyleng, -1, lc, cc, NUM);
    cc+=yyleng;
    return retToken;
}

"++" {
    assignValues(retToken, yytext, yyleng, -1, lc, cc, INC);
    cc+=2;
    return retToken;
}

"--" {
    assignValues(retToken, yytext, yyleng, -1, lc, cc, DEC);
    cc+=2;
    return retToken;
}

"||" {
    assignValues(retToken, yytext, yyleng, -1, lc, cc, LOR);
    cc+=2;
    return retToken;
}

"&&" {
    assignValues(retToken, yytext, yyleng, -1, lc, cc, LAND);
    cc+=2;
    return retToken;
}


"!" {
    assignValues(retToken, yytext, yyleng, -1, lc, cc, BNOT);
    cc++;
    return retToken;
}

"&" {
    assignValues(retToken, yytext, yyleng, -1, lc, cc, BAND);
    cc++;
    return retToken;
}

"|" {
    assignValues(retToken, yytext, yyleng, -1, lc, cc, BOR);
    cc++;
    return retToken;
}

"^" {
    assignValues(retToken, yytext, yyleng, -1, lc, cc, XOR);
    cc++;
    return retToken;
}

";" {
    assignValues(retToken, yytext, yyleng, -1, lc, cc, SC);
    cc++;
    return retToken;
}

"," {
    assignValues(retToken, yytext, yyleng, -1, lc, cc, COMMA);
    cc++;
    return retToken;
}

"+"|"-"|"*"|"/"|"%" {
    assignValues(retToken, yytext, yyleng, -1, lc, cc, AOP);
    cc++;
    return retToken;
}

%%

void errorRecovery()
{
    printf("%s\n", errorBuf);
}

int mulop()
{
    // printf("in mulop\n");
    if (tk != NULL && tk->type == AOP && (!strcmp(tk->lexeme, "/") || !strcmp(tk->lexeme, "*") || !strcmp(tk->lexeme, "%")))
    {
        return 1;
    }

    return 0;
}

int addop()
{
    // printf("in addop\n");
    if (tk != NULL && tk->type == AOP && (!strcmp(tk->lexeme, "+") || !strcmp(tk->lexeme, "-")))
    {
        return 1;
    }

    // printf("Error occurred at Line No: %i and Col No: %i\n", tk->row, tk->col);
    return 0;
}

int relop()
{
    if (tk != NULL && (tk->type == EQ || tk->type == GTE || tk->type == GT || tk->type == LTE || tk->type == LT || tk->type == NE))
    {
        return 1;
    }

    // printf("Error occurred at Line No: %i and Col No: %i\n", tk->row, tk->col);
    return 0;
}

int loopSt()
{
    // printf("in loop st\n");
    int ret; // while (expr) {stList}
    if (tk != NULL && tk->type == KW && !strcmp(tk->lexeme, "while"))
    {
        tk = yylex();
        if (tk != NULL && tk->type == LP)
        {
            tk = yylex();
            ret = expr();
            if (ret) // DO NOT WRITE ERROR RECOVERY FOR THIS IF, CUZ IT WILL BE TAKEN CARE IN THE NON-TERMINAL ITSELF
            {
                if (ret == 1)
                {
                    tk = yylex();
                }
                if (tk != NULL && tk->type == RP)
                {
                    tk = yylex();
                    if (tk != NULL && tk->type == LCB)
                    {
                        tk = yylex();
                        ret = stList();
                        if (ret)
                        {
                            if (ret == 1)
                            {
                                tk = yylex();
                            }
                            if (tk != NULL && tk->type == RCB)
                            {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    } // for (assSt;expr;assSt) {stList}
    else if (tk != NULL && tk->type == KW && !strcmp(tk->lexeme, "for"))
    {
        tk = yylex();
        if (tk != NULL && tk->type == LP)
        {
            tk = yylex();
            ret = assSt();
            if (ret)
            {
                if (ret == 1)
                {
                    tk = yylex();
                }

                if (tk != NULL && tk->type == SC)
                {
                    tk = yylex();
                    ret = expr();
                    if (ret)
                    {
                        if (ret == 1)
                        {
                            tk = yylex();
                        }

                        if (tk != NULL && tk->type == SC)
                        {
                            tk = yylex();
                            ret = assSt();
                            if (ret)
                            {
                                if (ret == 1)
                                {
                                    tk = yylex();
                                }

                                if (tk != NULL && tk->type == RP)
                                {
                                    //{stList}
                                    tk = yylex();
                                    if (tk != NULL && tk->type == LCB)
                                    {
                                        tk = yylex();
                                        ret = stList();
                                        if (ret)
                                        {
                                            if (ret == 1)
                                            {
                                                tk = yylex();
                                            }
                                            if (tk != NULL && tk->type == RCB)
                                            {
                                                return 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if (tk == NULL)
    {
        printf("Reached unexpected end of program\n");
    }
    else
    {
        // printf("Some error occurred in looping statement\n");
    }

    return 0;
}

int dPrime()
{
    // printf("in d prime\n");
    int ret;
    if (tk != NULL && tk->type == KW && !strcmp(tk->lexeme, "else"))
    {
        tk = yylex();
        if (tk != NULL && tk->type == LCB)
        {
            ret = stList();
            if (ret)
            {
                if (ret == 1)
                {
                    tk = yylex();
                }
                if (tk != NULL && tk->type == RCB)
                {
                    return 1;
                }
            }
        }
    }
    else
    {
        return 2;
    }

    if (tk == NULL)
    {
        printf("Reached unexpected end of program\n");
    }
    else
    {
        // printf("Some other error occurred in dPrime\n");
    }

    return 0;
}

int decisionSt()
{
    // printf("in decisionSt st\n");
    int ret;
    if (tk != NULL && tk->type == KW && !strcmp(tk->lexeme, "if"))
    {
        tk = yylex();
        if (tk != NULL && tk->type == LP)
        {
            tk = yylex();
            ret = expr();
            // printf("Returned to decisionSt\n");
            if (ret)
            {
                if (ret == 1)
                {
                    tk = yylex();
                }
                if (tk != NULL && tk->type == RP)
                {
                     tk = yylex();
                    if (tk != NULL && tk->type == LCB)
                    {
                        tk = yylex();
                        ret = stList();
                        if (ret)
                        {
                            if (ret == 1)
                            {
                                tk = yylex();
                            }
                            if (tk != NULL && tk->type == RCB)
                            {
                                tk = yylex();
                                ret = dPrime();
                                return ret;
                            }
                        }
                    }
                }
            }
        }
    }

    if (tk == NULL)
    {
        printf("Reached unexpected end of program\n");
    }
    else
    {
        // printf("Some other error occurred in Decision Statement\n");
    }

    return 0;
}

int factor()
{
    // printf("in factor\n");
    if (tk != NULL && (tk->type == ID || tk->type == NUM))
    {
        return 1;
    }

    if (tk == NULL)
    {
        printf("Reached unexpected end of program\n");
    }
    else
    {
        printf("Some error occurred in factor\n");
    }

    return 0;
}

int tPrime()
{
    // printf("in t prime\n");
    int ret;
    ret = mulop();
    if (ret)
    {
        tk = yylex();
        ret = factor();
        if (ret)
        {
            tk = yylex();
            ret = tPrime();
            return ret;
        }
    }
    else
    {
        return 2;
    }

    printf("Some error occurred in tPrime\n");
    return 0;
}

int term()
{
    // printf("in term\n");
    int ret = factor();
    if (ret)
    {
        tk = yylex();
        ret = tPrime();
        return ret;
    }

    printf("Some error occurred in term\n");
    return 0;
}

int sePrime()
{
    // printf("in se prime\n");
    int ret = addop();
    if (ret)
    {
        if (ret == 1)
        {
            tk = yylex();
        }

        ret = term();
        if (ret)
        {
            if (ret == 1)
            {
                tk = yylex();
            }

            ret = sePrime();
            return ret;
        }
    }
    else
    {
        return 2;
    }

    printf("Some error occurred in se Prime\n");
    return 0;
}

int simpleExpr()
{
    // printf("in simple expr\n");
    int ret = term();
    if (ret)
    {
        if (ret == 1)
        {
            tk = yylex();
        }

        ret = sePrime();
        return ret;
    }

    // printf("Some error occurred in simple expression\n");
    return 0;
}

int ePrime()
{
    // printf("in expr prime\n");
    int ret = relop();
    if (ret)
    {
        tk = yylex();
        ret = simpleExpr();
        return ret;
    }
    else
    {
        return 2;
    }

    printf("Some error occurred in ePrime\n");
    return 0;
}

int expr()
{
    // printf("in expr\n");
    int ret = simpleExpr();
    if (ret)
    {
        if (ret == 1)
        {
            tk = yylex();
        }
        ret = ePrime();
        return ret;
    }

    printf("Some error occurred in Expr\n");
    return 0;
}

int assSt()
{
    // printf("in assignment st\n");
    int ret;
    if (tk != NULL && tk->type == ID)
    {
        tk = yylex();
        if (tk != NULL && tk->type == ASS)
        {
            tk = yylex();
            ret = expr();
            return ret;
        }
        else
        {
            strcpy(errorBuf, "Invalid operator");
            errorRecovery();
        }
    }
    else
    {
        strcpy(errorBuf, "Invalid identifier");
        errorRecovery();
    }

    if (tk == NULL)
    {
        printf("Reached unexpected end of program\n");
    }
    return 0;
}

int stmt()
{
    // printf("in stmt\n");
    int ret = assSt();
    if (ret)
    {
        if (ret == 1)
        {
            tk = yylex();
        }

        if (tk != NULL && tk->type == SC)
        {
            return 1;
        }
        else
        {
            strcpy(errorBuf, "Expected a semi-colon");
            errorRecovery();
        }
    }
    else
    {
        ret = decisionSt();
        if (ret)
        {
            return ret;
        }
        else
        {
            return loopSt();
        }
    }

    return 0;
}

int stList()
{
    // printf("in stmt list\n");
    int ret = stmt();
    if (ret)
    {
        // printf("returned to stmt list\n");
        if (ret == 1)
        {
            tk = yylex();
        }
        return stList();
    }
    else
    {
        return 2;
    }
    return 0;
}

int idList()
{
    // printf("in id List\n");
    int ret;
    if (tk != NULL && tk->type == ID)
    {
        tk = yylex();
        return id1();
    }
    else
    {
        strcpy(errorBuf, "Expected an identifier");
        errorRecovery();
    }

    return 0;
}

int id1()
{
    // printf("in id1\n");
    int ret;
    if (tk != NULL && tk->type == COMMA)
    {
        tk = yylex();
        ret = idList();
        return ret;
    }
    else if (tk != NULL && tk->type == LSB)
    {
        tk = yylex();
        if (tk != NULL && tk->type == NUM)
        {
            tk = yylex();
            if (tk != NULL && tk->type == RSB)
            {
                tk = yylex();
                ret = id2();
                return ret;
            }
            else
            {
                strcpy(errorBuf, "Expected closing bracket");
                errorRecovery();
            }
        }
        else
        {
            strcpy(errorBuf, "Expected a number");
            errorRecovery();
        }
    }
    else
    {
        return 2;
    }

    printf("error in id1\n");
    return 0;
}

int id2()
{
    // printf("in id2\n");
    int ret;
    if (tk != NULL && tk->type == COMMA)
    {
        tk = yylex();
        ret = idList();
        return ret;
    }
    else
    {
        return 2;
    }

    printf("error in id2\n");
    return 0;
}

int datatype()
{
    // printf("in datatype\n");
    if (tk != NULL && tk->type == KW && (!strcmp(tk->lexeme, "int") || !strcmp(tk->lexeme, "char") || !strcmp(tk->lexeme, "float") || !strcmp(tk->lexeme, "long") || !strcmp(tk->lexeme, "double")))
    {
        return 1;
    }

    strcpy(errorBuf, "Invalid datatype");
    errorRecovery();
    return 0;
}

int declarations()
{
    // printf("In declarations\n");
    int ret = datatype();
    if (ret)
    {
        tk = yylex();
        ret = idList();
        if (ret)
        {
            if (ret == 1)
            {
                tk = yylex();
            }

            if (tk != NULL && tk->type == SC)
            {
                tk = yylex();
                ret = declarations();
                return ret;
            }
            else
            {
                strcpy(errorBuf, "Expected a semi colon");
                errorRecovery();
            }
        }
    }
    else
    {
        return 2;
    }
}

int program()
{
    int ret = datatype();
    if (ret)
    {
        tk = yylex();
        if (tk != NULL && tk->type == ID && !strcmp(tk->lexeme, "main"))
        {
            tk = yylex();
            if (tk != NULL && tk->type == LP)
            {
                tk = yylex();
                if (tk != NULL && tk->type == RP)
                {
                    tk = yylex();
                    if (tk != NULL && tk->type == LCB)
                    {
                        tk = yylex();
                        ret = declarations();
                        if (ret)
                        {
                            if (ret == 1)
                            {
                                tk = yylex();
                            }

                            ret = stList();
                            if (ret)
                            {
                                if (ret == 1)
                                {
                                    tk = yylex();
                                }
                                if (tk != NULL && tk->type == RCB)
                                {
                                    tk = yylex();
                                    return 1;
                                }
                                else
                                {
                                    strcpy(errorBuf, "Expected a closing curly bracket");
                                    errorRecovery();
                                }
                            }
                        }
                    }
                    else
                    {
                        strcpy(errorBuf, "Declare the function after prototype");
                        errorRecovery();
                    }
                }
                else
                {
                    strcpy(errorBuf, "Main function shouldn't have any arguments");
                    errorRecovery();
                }
            }
            else
            {
                strcpy(errorBuf, "Left Parenthesis should follow");
                errorRecovery();
            }
        }
        else
        {
            strcpy(errorBuf, "Not main function");
            errorRecovery();
        }
    }

    if (tk == NULL)
    {
        printf("Reached unexpected end of program\n");
    }
    else
    {
        printf("Some other error occurred in program\n");
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        printf("Enter proper arguments\n");
        return 1;
    }

    yyin = fopen(argv[1], "r");
    yyout = fopen(argv[2], "w");

    initHT(st);
    // printHT(st);


    tk = yylex();
    if(program())
    {
        printf("The program is successfully parsed\n");
    }
    else
    {
        printf("Check for errors\n");
    }
    
    // printHT(st);
    printf("Done! check output file\n");
    return 0;
}

int yywrap()
{
    return 1;
}