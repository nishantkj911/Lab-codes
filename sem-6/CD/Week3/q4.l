%{
    #include <stdio.h>
    #include <stdlib.h>
    int noOfSts = 0;
%}

%%

"scanf" {fputs("read", yyout); noOfSts++;}
"printf" {fputs("write", yyout); noOfSts++;}
. {fputc(yytext[0], yyout);}

%%

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        printf("Enter proper arguments\n");
        exit(EXIT_FAILURE);
    }

    yyin = fopen(argv[1], "r");
    yyout = fopen(argv[2], "w");

    yylex();

    printf("No of printf's and scanf's encountered are %i\n", noOfSts);
    return 0;
}

int yywrap()
{
    return 1;
}