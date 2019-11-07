%{
#include "cGrammar.tab.h"

struct token
{
    int lc, cc;
    char *buf;
    int index;
    int type;
};

typedef struct token Token;

int lc = 1, cc = 1;
Token *tk;

Token *allocToken()
{
    Token *tk;
    tk = malloc(sizeof(Token));
    tk->buf = malloc(sizeof(char) * 256);
    tk->index = -1;
    tk->type = -1;
    return tk;

}

void setTokenArgs(Token * tk, char *buf, int l, int c, int type)
{
    if (tk == NULL)
        return;
    strcpy(tk->buf, buf);
    tk->lc = l;
    tk->cc = c;
    tk->type = type;
}
%}

letter_ [a-zA-Z_]
digit [0-9]
keywords "do"|"break"|"continue"|"return"
datatype "int"|"char"|"double"|"float"

%%
"//".*"\n" {
    lc++;
    cc = 1;
}

(\"(.)*\") {cc+=strlen(yytext);}

(\'(.)\') {cc+=strlen(yytext);}

\n {
    cc = 1;
    lc++;
}

\t {
    cc += 8;
}

" " {
    cc += 1;
}

"#".*"\n" {
    lc++;
}

"/*"(.|"\n")*"*/" {
    printf("%s\n", yytext);
    int i = 0;
    while (yytext[i] != '\0')
    {
        if (yytext[i] == '\n')
        {
            lc++;
            cc = 1;
        }
        else
            cc++;
        i++;
    }
	
}

"<=" {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, LTE);
    cc += 2;
    return tk->type;
}

"<" {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, LT);
    cc++;
    return tk->type;
}

">=" {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, GTE);
    cc += 2;
    return tk->type;
}  
  
">" {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, GT);
    cc++;
    return tk->type;
} 
"==" {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, EQ);
    cc += 2;
    return tk->type;
}    

"!=" {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, NE);
    cc += 2;
    return tk->type;
}

"for" {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, FOR);
    cc += strlen(yytext);
    return tk->type;
}

"if" {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, IF);
    cc += strlen(yytext);
    return tk->type;
}

"else" {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, ELSE);
    cc += strlen(yytext);
    return tk->type;
}

"while" {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, WHILE);
    cc += strlen(yytext);
    return tk->type;
}

"main" {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, MAIN);
    cc += strlen(yytext);
    return tk->type;
}

{keywords} {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, KW);
    cc += strlen(yytext);
    return tk->type;
}

{datatype} {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, DT);
    cc += strlen(yytext);
    return tk->type;
}

{letter_}({letter_}|{digit})* {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, ID);
    cc += strlen(yytext);
    return tk->type;
}

{digit}+ {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, NUM);
    cc += strlen(yytext);
    return tk->type;
}

"++" {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, INC);
    cc += 2;
    return tk->type;
}

"+=" {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, INC);
    cc += 2;
    return tk->type;
}

"--" {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, DEC);
    cc += 2;
    return tk->type;
}

"-=" {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, DEC);
    cc += 2;
    return tk->type;
}

"*=" {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, AO);
    cc += 2;
    return tk->type;
}

"/=" {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, AO);
    cc += 2;
    return tk->type;
}

"+"|"-" {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, ADDOP);
    cc += 1;
    return tk->type;
}

"*"|"/"|"%" {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, MULOP);
    cc += 1;
    return tk->type;

}

"&&" {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, LA);
    cc += 2;
    return tk->type;
}

"&" {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, BA);
    cc += 1;
    return tk->type;
}

"||" {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, LO);
    cc += 2;
    return tk->type;
}

"|" {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, BO);
    cc += 1;
    return tk->type;
}

"=" {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, ASS);
    cc += 1;
    return tk->type;
}

"{" {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, LC);
    cc += 1;
    return tk->type;
}

"}" {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, RC);
    cc += 1;
    return tk->type;
}

"(" {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, LB);
    cc += 1;
    return tk->type;
}

")" {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, RB);
    cc += 1;
    return tk->type;
}

"[" {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, LS);
    cc += 1;
    return tk->type;
}

"]" {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, RS);
    cc += 1;
    return tk->type;
}

"," {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, COMMA);
    cc += 1;
    return tk->type;
}

";" {
    tk = allocToken();
    setTokenArgs(tk, yytext, lc, cc, SC);
    cc += 1;
    return tk->type;
}

%%

int yywrap()
{
    return 1;
}