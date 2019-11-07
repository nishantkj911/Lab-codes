%{

#include <stdio.h>
#include <stdlib.h>
#include "lispSymbolTable.h"

int yylex();
int yyerror(char *msg);

extern FILE *yyin;
extern FILE *yyout;

int functionScope = 0;
int 
%}

%union {
    struct $ *myToken;
}

%token MOD INCF DECF TRUE FALSE DEFM SETQ OP NUM LP RP LIT ATOM DEFV FORMAT SQ
%token EQ NE GT GTE LT LTE MAX MIN AND OR NOT LA LO LXOR LNOR
%token LEQV IF BLOCK RETURN FOR LOOP DO IN COLLECT COND WHEN

%%

program: stList;

stList: stList stmt | ;

stmt: fnCall | formatSt |
      decl | sExpn | 
      fnDecl | blockSt | returnSt |
      decisionSt | loopSt; 

paramList: paramList optionalSQ seOrAtom | ;

atomList: atomList ATOM | ;

fnCall: LP ATOM paramList RP |
        LP ATOM fnCall RP;

optionalSQ: SQ | ;

decl: LP SETQ ATOM sExpn RP |
      LP DEFV ATOM sExpn RP;

formatSt: LP FORMAT TRUE LIT paramList RP;

fnDecl: LP DEFM ATOM LP atomList RP optionalLIT stList RP;

optionalLIT: LIT | ;

sExpn: LP arithOP paramList RP |
       LP INCF ATOM NUM RP |
       LP DECF ATOM NUM RP |
       LP NOT seOrAtom RP |
       LP LNOR seOrAtom seOrAtom RP |
       LP logicalOP paramList RP |
       NUM | TRUE | FALSE;

seOrAtom: sExpn | ATOM;

arithOP: OP | MOD | MAX | MIN;

logicalOP: AND | OR | LA | LO | LXOR | LEQV | GT | GTE | NE | EQ | LT | LTE;

decisionSt: LP IF seOrAtom stList RP |
            LP COND testCases RP |
            LP WHEN sExpn stList RP;

testCases: testCases LP sExpn stList RP | ;

blockSt: LP BLOCK ATOM stList RP;

loopSt: LP LOOP forConstructs loopStList RP |
        LP LOOP stList RP;
        

loopStList: loopStList execLoop | ;

execLoop: DO stmt |
          COLLECT LP atomList RP;

forConstructs: forConstructs FOR ATOM IN SQ LP paramList RP | ;

returnSt: LP RETURN ATOM optionalRetVal RP;
optionalRetVal: seOrAtom | ;

%%

int yyerror(char *msg)
{
    printf("%s\n", msg);
}

int main()
{
    yyin = fopen("input.lisp", "r");

    do
    {
        if(yyparse())
        {
            return 1;
        }
    } while(!feof(yyin));

    printf("Done!\n");
}

