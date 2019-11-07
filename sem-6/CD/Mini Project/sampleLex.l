%option noyywrap
%{
    #include <stdio.h>
    #include <stdlib.h>

    extern FILE *yyin;
    int yylex();
%}

digit [0-9]

%%

";".*\n {
    printf("Lex Comment\n");
}

"\"".*"\"" {
    printf("Lex Literal %s\n", yytext);
    return 1;
}

{digit}+("."{digit}+)?([eE][+-]?{digit}+)? {
    printf("Number %s\n", yytext);
    return 1;
 }

[^\t\n ]+ {
    printf("Lex Atom %s\n", yytext);
    return 1;
}

\n|\t|" " {
    // printf("Lex heh\n");
}

%%

int main()
{
    yyin = fopen("input.txt", "r");
    while(yylex())
    {
        
    }
}