%{
    int words = 0, chars = 0, blanks = 0, lines = 1;
%}

%%

[a-zA-Z]+ {words++; chars+=yyleng;}
\n {lines++; chars++;}
" "+ {blanks+=yyleng; chars+=yyleng;}
. {chars++;}

%%

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("Invalid arguments\n");
        exit(EXIT_FAILURE);
    }

    yyin = fopen(argv[1], "r");

    while(yylex())
    {
        printf("Encountered %s\n", yytext);
    }

    printf("Words: %i\tCharacters: %i\tBlanks: %i\tLines: %i\n", words, chars, blanks, lines);
    return 0;
}

int yywrap()
{
    return 1;
}