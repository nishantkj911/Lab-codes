%{
    int compoundFlag = 0;
%}

%%

\n {}
" and "|" but" {compoundFlag = 1;}
. {}
%%

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("Enter proper arguments\n");
        exit(EXIT_FAILURE);
    }

    yyin = fopen(argv[1], "r");

    yylex();

    if (compoundFlag)
        printf("Yes the statement is a compound statement\n");
    else
    {
        printf("No it is not\n");
    }
    return 0;
}

int yywrap()
{
    return 1;
}