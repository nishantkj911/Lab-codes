%{
    int arr[4];
%}

digit [0-9]
digits {digit}+
%%

"+"?{digits} {arr[0]++;  printf("%s\n", yytext);}
-{digits} {arr[1]++;}
"+"?{digits}.{digits} {arr[2]++;}
-{digits}.{digits} {arr[3]++;}
\n {}
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

    printf("No. of +ve integers %i\n", arr[0]);
    printf("No. of -ve integers %i\n", arr[1]);
    printf("No. of +ve fp nos %i\n", arr[2]);
    printf("No. of -ve fp nos %i\n", arr[3]);   
    return 0;
}

int yywrap()
{
    return 1;
}