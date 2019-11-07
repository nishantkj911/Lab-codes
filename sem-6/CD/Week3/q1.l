%{
int vowels = 0, cons = 0;
%}

vow [a,e,i,o,u,A,I,O,E,U]
cons [b-d,f-h,j-n,p-t,v-z,B-D,F-H,J-N,P-T,V-Z]
%%

{vow} {vowels++;}
{cons} {cons++;}
. {}
%%

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("Enter proper arguments\n");
        exit(0);
    }

    yyin = fopen(argv[1], "r");

    while(yylex())
    {
        printf("Encountered %s\n", yytext);
    }

    printf("In total %i vowels were encountered\n", vowels);
    printf("In total %i consonants were encountered\n", cons);
    return 0;
}

int yywrap()
{
    return 1;
}