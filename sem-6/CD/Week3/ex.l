%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define YY_DECL struct token *yylex(void)

enum tokenType {EOFILE = -1, LT, LTE, GT, GTE, NE, EQ};

struct token
{
    char *lexeme;
    int index;
    unsigned int row, col;
    enum tokenType type;
};

int lineNo = 1, colNo = 1;

struct token *tk;
struct token *allocToken()
{
    struct token* tk;
    tk = (struct token*) malloc(sizeof(struct token));
    tk->lexeme = (char*) malloc(sizeof(char) * 3);
    tk->index = -1;
    tk->type = EOFILE;
    return tk;
}

void setTokenArgs(struct token *tk, char *lexeme, int index, int lc, int cc, enum tokenType type)
{
    if (tk == NULL)
        return;

    strcpy(tk->lexeme, lexeme);
    tk->index = index;
    tk->row = lc;
    tk->col = cc;
    tk->type = type;
}

%}

%%
"/*".*"*/" {int i = 0;
            while (yytext[i] != '\0')
            {
                if(yytext[i] == '\n')
                {

                    colNo = 1;
                    lineNo++;
                }
                else
                {
                    colNo++;
                }
                i++;
            }}

"//".*"\n" {lineNo++; colNo = 1;}

(\"(.)*\") {colNo+=strlen(yytext);}

(\'(.)\') {colNo += strlen(yytext);}

\n {lineNo++; colNo = 1;}
    
"<" {tk = allocToken();
    setTokenArgs(tk, yytext, -1, lineNo, colNo, LT);
    colNo++;
    return tk;
}
"<=" {tk = allocToken();
    setTokenArgs(tk, yytext, -1, lineNo, colNo, LTE);
    colNo+=2;
    return tk;
}
">" {tk = allocToken();
    setTokenArgs(tk, yytext, -1, lineNo, colNo, GT);
    colNo++;
    return tk;
}
">=" {tk = allocToken();
    setTokenArgs(tk, yytext, -1, lineNo, colNo, GTE);
    colNo+=2;
    return tk;
}
"==" {tk = allocToken();
    setTokenArgs(tk, yytext, -1, lineNo, colNo, EQ);
    colNo+=2;
    return tk;
}
"!=" {tk = allocToken();
    setTokenArgs(tk, yytext, -1, lineNo, colNo, NE);
    colNo+=2;
    return tk;
}

"\t" {colNo+=4;}
. {colNo++;}

%%

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Enter valid arguments (only two)\n");
        exit(0);
    }

    yyin = fopen(argv[1], "r");
    int cnt = 0;
    while((tk = yylex()))
    {
        printf("%i %i %i %s\n", cnt, tk->row, tk->col, tk->lexeme);
        cnt++;
    }

    return 0;
}

int yywrap()
{
    return 1;
}