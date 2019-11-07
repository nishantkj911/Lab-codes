%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
int yyerror(char*);
extern FILE *yyin;
extern FILE *yyout;
%}

%token NUM NL

%%

I: I L
  |
  ;

L: NL
  | E NL
  ;

E: NUM
  | E E '+'
  | E E '-'
  | E E '*'
  | E E '/'
  | E E '^'
  | E 'n'
  ;

%%

int yyerror(char *msg)
{
    printf("%s\n", msg);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./op <inputFile>\n");
        return 1;
    }

    yyin = fopen(argv[1], "r");

    do
    {
        if(yyparse())
        {
            printf("Failure\n");
        }
    } while(!feof(yyin));

    printf("Successfully parsed!\n");
}