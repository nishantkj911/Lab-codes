%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
int yyerror();
extern FILE *yyin;
extern FILE *yyout;
%}

%token LTE LT GTE GT EQ NE FOR IF ELSE WHILE KW DT ID NUM INC DEC AO ADDOP MULOP LA BA LO BO ASS LC RC LB RB LS RS COMMA SC MAIN
%left '+' '-' '*' '/' '%'

%%

program: MAIN LB RB LC decl stList RC
        ;

decl: DT idList SC decl
	  |
	  ;
idList: ID
        | ID COMMA idList
        | ID LS NUM RS COMMA idList 
        | ID LS NUM RS
        ;

stList: stmt stList
        |
        ;

stmt: assSt SC | loopSt | decisionSt
    ;

assSt: ID ASS expn
    ;

expn: simpleExpn E1
    ;

E1: relop simpleExpn
    |
    ;

simpleExpn: term SE1
    ;

SE1: ADDOP term SE1
    |
    ;

term: factor T1
    ;

T1: MULOP factor T1
    |
    ;

factor: ID | NUM
    ;

decisionSt: IF LB expn RB LC stList RC D1
    ;

D1: ELSE LC stList RC
    |
    ;

loopSt: FOR LB assSt SC expn SC assSt RB LC stList RC
    | WHILE LB expn RB LC stList RC
    ;

relop: GT | LT | GTE | LTE | EQ | NE
    ;

%%

int yyerror(char *msg)
{
    printf("%s\n", msg);
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./op <inputfile>\n");
        return 1;
    }

    yyin = fopen(argv[1], "r");

    do
    {
        if(yyparse())
        {
            printf("Failure!\n");
            return 1;
        }
    } while (!feof(yyin));
    printf("Successfully parsed program\n");
}