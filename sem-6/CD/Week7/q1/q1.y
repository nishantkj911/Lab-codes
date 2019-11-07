%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
int yyerror(char *msg);
extern FILE *yyin;
extern FILE *yyout;
%}

%token NUM DT ID SC COMMA LSB RSB

%%

decls:  DT idList SC decls
        | 
        ;

idList: ID I1
        ;
I1: COMMA idList
    | LSB NUM RSB I2
    | 
    ;

I2: COMMA idList
    | 
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