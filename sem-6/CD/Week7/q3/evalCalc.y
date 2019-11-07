%{
   #include <stdio.h>
   #include <stdlib.h>
   int yylex();
   int yyerror(char*);
   #define YYSTYPE double
%}



%token  NUMBER 
%token NL
%left '+'
%left '*'
%left '-'
%left '/'


%%
stmt: exp NL {printf("=%lf\n",$1); exit(1);};

exp: exp '+' term {$$= $1 + $3;}
|
exp '-' term { $$= $1 - $3; }
|
term 
;


term: term '*' factor { $$= $1 * $3;}
|
term '/' factor { $$=  $1 / $3; }
|
factor 
;


factor : NUMBER
|
'(' exp ')' {$$=$2;}
|

;
%%

int yyerror(char* msg)
{
	printf("Invalid expression");
	exit(0);
	return 1;
	
}

int main()
 {
 yyparse();
 

 } 
