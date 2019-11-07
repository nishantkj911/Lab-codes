%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
int yyerror(char *);
extern FILE *yyin;
extern FILE *yyout;
%}

%token NUM ID PLUS MINUS SC
%left '+' '-'

%%
stmt: exp SC
    ;
exp: exp PLUS term
    | exp MINUS term
    | term
    ;
term: ID
    | NUM
    ;
%%

int yyerror(char *msg)
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