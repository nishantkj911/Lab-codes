%{
    #include <stdio.h>
    #include <stdlib.h>
%}


letter_ [a-z_A-Z]
letters {letter}+
digit [0-9]
digits {digit}+

%%


\n|. {}
%%

int main(int argc, char const *argv[])
{
    yyin = fopen(argv[1], "r");

    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}