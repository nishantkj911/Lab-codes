%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
int yyerror(char *msg);
extern FILE *yyin;
extern FILE *yyout;

// for statement let it be only ID
%}

%token IF ELSE ID SC LP RP RCB LCB
%left '+' '-' '*' '/' '%' 

%%

declSt:  IF LP ID RP LCB stList RCB dPrime
        ;

dPrime: ELSE LCB stList RCB
        |
        ;

stList: st stList
        |
        ;

st: ID SC
    | declSt
    ;

%%

int yyerror(char *ma)
{
}

int main()
{
    printf("enter the expression\n");
    yyin = fopen("abc.txt", "r");
    yyout = fopen("output.txt", "w");
    do
    {
        if(yyparse())
        {
            printf("Failure\n");
            return 1;
        }
    } while(!feof(yyin));

    printf("Success\n");
}