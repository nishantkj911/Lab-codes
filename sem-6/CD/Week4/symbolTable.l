
%{
    #include <string.h>
    #include "symbolTable.h"
    #include "tokenGen.h"
    // Need to add scope of variable in the symbolTable

    char datatypeBuf[100];

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

    int index;

    char *str = calloc(strlen(yytext), sizeof(char));
    strcpy(str, yytext);
    char *idType = calloc(20, sizeof(char));
    char *returnType = calloc(20, sizeof(char));
    Token *nextToken = yylex();
    size_t size = 0;

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

    manageID(str, &index, idType, size, returnType);
    assignValues(retToken, yytext, yyleng, index, lc, cc, ID);
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

    while((retToken = yylex()))
    {
    }

    printHT(st);
    printf("Done! check output file\n");
    return 0;
}

int yywrap()
{
    return 1;
}