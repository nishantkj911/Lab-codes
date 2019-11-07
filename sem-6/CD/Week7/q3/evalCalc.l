%{
	#include "evalCalc.tab.h"
	#define YYSTYPE double

	

%}

%%

[0-9]+ {sscanf(yytext,"%lf",&yylval); 
return NUMBER; }
\n { return NL;}
" " {}
. { return yytext[0];}

%%

int yywrap()
{
	return 1;
}