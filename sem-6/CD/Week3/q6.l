%{
    #include <string.h>


    int lc = 1, cc = 1;
    enum types
        {
            KW,
            ID,
            NUM,
            LP,
            RP,
            LCB,
            RCB,
            LSB,
            RSB,
            LTE,
            LT,
            GTE,
            GT,
            NE,
            WS,
            EQ,
            ASS,
            INC,
            DEC,
            OP_ASS,
            AOP,
            LOR,
            LAND,
            BNOT,
            BOR,
            BAND,
            XOR,
            SS,
            LIT,
            EOFILE
        };

    typedef struct $
    {
        char *lexeme;
        int index;
        unsigned int row, col;
        enum types type;
    } Token;

    #define YY_DECL Token *yylex(void)
    Token *retToken = NULL;
    Token *allocToken()
    {
        retToken = malloc(sizeof(Token));
        retToken->index = -1;
        retToken->type = EOFILE;
        return retToken;
    }

    void assignValues(Token *retToken, char *lexeme, int len, unsigned int lc, unsigned int cc, enum types type)
    {
        if (retToken == NULL)
        {
            printf("Send a non-null token\n");
            return;
        }

        retToken->lexeme = calloc(len, sizeof(char));
        strcpy(retToken->lexeme, lexeme);
        retToken->row = lc;
        retToken->col = cc;
        retToken->type = type;
        return;
    }
%}

letter_ [a-z_A-Z]
letters {letter}+
digit [0-9]
digits {digit}+

%%

"//"(.)*"\n" {lc++; cc=1;}

"/*"(.)*"*/" {int i = 0;
    while (yytext[i] != '\0')
    {
        if(yytext[i] == '\n')
        {
            cc = 1; lc++;
        }
        else
        {
            cc++;
        }

        i++;
    }
}

\n {lc++; cc=1;}

\"(.)*\" {
    retToken = allocToken();
    assignValues(retToken, yytext, strlen(yytext) + 1, lc, cc, LIT);
    cc+=strlen(yytext);
    return retToken;
}

\'(.)\' {
    retToken = allocToken();
    assignValues(retToken, yytext, strlen(yytext) + 1, lc, cc, LIT);
    cc++;
    return retToken;
}

"<" {
    retToken = allocToken();
    assignValues(retToken, yytext, strlen(yytext) + 1, lc, cc, LT);
    cc++;
    return retToken;
    }
"<=" {
    retToken = allocToken();
    assignValues(retToken, yytext, strlen(yytext) + 1, lc, cc, LTE);
    cc+=2;
    return retToken;
}
">" {
    retToken = allocToken();
    assignValues(retToken, yytext, strlen(yytext) + 1, lc, cc, GT);
    cc++;
    return retToken;
    }
">=" {
    retToken = allocToken();
    assignValues(retToken, yytext, strlen(yytext) + 1, lc, cc, GTE);
    cc+=2;
    return retToken;
}
"==" {
    retToken = allocToken();
    assignValues(retToken, yytext, strlen(yytext) + 1, lc, cc, EQ);
    cc+=2;
    return retToken;
}
"!=" {
    retToken = allocToken();
    assignValues(retToken, yytext, strlen(yytext) + 1, lc, cc, NE);
    cc+=2;
    return retToken;
}
"int"|"char"|"long"|"float"|"double"|"return"|"for"|"if"|"else"|"break"|"continue"|"switch"|"case"|"while"|"do" {
    retToken = allocToken();
    assignValues(retToken, yytext, strlen(yytext) + 1, lc, cc, KW);
    cc+=strlen(yytext);
    return retToken;
}

{letter_}({letter_}|{digit})* {
    retToken = allocToken();
    assignValues(retToken, yytext, strlen(yytext) + 1, lc, cc, ID);
    cc+=strlen(yytext);
    return retToken;
}

")" {
    retToken = allocToken();
    assignValues(retToken, yytext, strlen(yytext) + 1, lc, cc, RP);
    cc++;
    return retToken;
}

"{" {
    retToken = allocToken();
    assignValues(retToken, yytext, strlen(yytext) + 1, lc, cc, LCB);
    cc++;
    return retToken;
}

"}" {
    retToken = allocToken();
    assignValues(retToken, yytext, strlen(yytext) + 1, lc, cc, RCB);
    cc++;
    return retToken;
}

"[" {
    retToken = allocToken();
    assignValues(retToken, yytext, strlen(yytext) + 1, lc, cc, LSB);
    cc++;
    return retToken;
}

"]" {
    retToken = allocToken();
    assignValues(retToken, yytext, strlen(yytext) + 1, lc, cc, RSB);
    cc++;
    return retToken;
}

"(" {
    retToken = allocToken();
    assignValues(retToken, yytext, strlen(yytext) + 1, lc, cc, LP);
    cc++;
    return retToken;
}

"=" {
    retToken = allocToken();
    assignValues(retToken, yytext, strlen(yytext) + 1, lc, cc, ASS);
    cc++;
    return retToken;
}

" " {cc++;}

\t {cc+=4;}

"+="|"-="|"*="|"/="|"%=" {
    retToken = allocToken();
    assignValues(retToken, yytext, strlen(yytext) + 1, lc, cc, OP_ASS);
    cc+=2;
    return retToken;
}

"+"?{digit}+|"+"?{digit}+.{digit}+|-{digit}+|-{digit}+.{digit}+ {
    retToken = allocToken();
    assignValues(retToken, yytext, strlen(yytext) + 1, lc, cc, NUM);
    cc+=strlen(yytext);
    return retToken;
}

"++" {
    retToken = allocToken();
    assignValues(retToken, yytext, strlen(yytext) + 1, lc, cc, INC);
    cc+=2;
    return retToken;
}

"--" {
    retToken = allocToken();
    assignValues(retToken, yytext, strlen(yytext) + 1, lc, cc, DEC);
    cc+=2;
    return retToken;
}

"||" {
    retToken = allocToken();
    assignValues(retToken, yytext, strlen(yytext) + 1, lc, cc, LOR);
    cc+=2;
    return retToken;
}

"&&" {
    retToken = allocToken();
    assignValues(retToken, yytext, strlen(yytext) + 1, lc, cc, LAND);
    cc+=2;
    return retToken;
}


"!" {
    retToken = allocToken();
    assignValues(retToken, yytext, strlen(yytext) + 1, lc, cc, BNOT);
    cc++;
    return retToken;
}

"&" {
    retToken = allocToken();
    assignValues(retToken, yytext, strlen(yytext) + 1, lc, cc, BAND);
    cc++;
    return retToken;
}

"|" {
    retToken = allocToken();
    assignValues(retToken, yytext, strlen(yytext) + 1, lc, cc, BOR);
    cc++;
    return retToken;
}

"^" {
    retToken = allocToken();
    assignValues(retToken, yytext, strlen(yytext) + 1, lc, cc, XOR);
    cc++;
    return retToken;
}

";"|"," {
    retToken = allocToken();
    assignValues(retToken, yytext, strlen(yytext) + 1, lc, cc, SS);
    cc++;
    return retToken;
}

"+"|"-"|"*"|"/"|"%" {
    retToken = allocToken();
    assignValues(retToken, yytext, strlen(yytext) + 1, lc, cc, OP);
    cc++;
    return retToken;
}

%%

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        printf("Enter proper arguments\n");
        return 1;
    }

    yyin = fopen(argv[1], "r");
    yyout = fopen(argv[2], "w");

    while((retToken = yylex()))
    {
        fprintf(yyout, "<%s\tLine No: %i\tCol No: %i\tType: %i>\n", retToken->lexeme, retToken->row, retToken->col, retToken->type);
    }

    printf("Done! check output file\n");
    return 0;
}

int yywrap()
{
    return 1;
}