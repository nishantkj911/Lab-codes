%option noyywrap caseless
%{
    #include "lisp.tab.h"
    #include "lispSymbolTable.h"

    extern FILE *yyin;
    int yylex();

Token *tk;
int globalLC = 0, globalCC = 0;

Token *allocToken()
{
    tk = malloc(sizeof(Token));
    tk->lc = tk->cc = 0;
    tk->type = -1;
    tk->index = -1;
}

void setTokenArguments(Token *tk, char *lexeme, int len, int lc, int cc, int type)
{
    tk->lexeme = calloc(len, sizeof(char));
    strcpy(tk->lexeme, lexeme);
    tk->lc = lc;
    tk->cc = cc;
    tk->type = type;
}
%}

digit [0-9]

%%

";".*\n {
    // printf("Lex Comment\n");
}

\' {
    printf("<Token: %s\tType: %i>\n", yytext, SQ);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, SQ);
    yylval.myToken = tk;
    return SQ;
}

"t" {
    printf("<Token: %s\tType: %i>\n", yytext, TRUE);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, TRUE);
    yylval.myToken = tk;
    return TRUE;
}

"nil" {
    printf("<Token: %s\tType: %i>\n", yytext, FALSE);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, FALSE);
    yylval.myToken = tk;
    return FALSE;
}

"defmacro"|"defun" {
    printf("<Token: %s\tType: %i>\n", yytext, DEFM);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, DEFM);
    yylval.myToken = tk;
    return DEFM;
}

"format" {
    printf("<Token: %s\tType: %i>\n", yytext, FORMAT);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, FORMAT);
    yylval.myToken = tk;
    return FORMAT;
}

"defvar" {
    printf("<Token: %s\tType: %i>\n", yytext, DEFV);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, DEFV);
    yylval.myToken = tk;
    return DEFV;
}

"setq" {
    printf("<Token: %s\tType: %i>\n", yytext, SETQ);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, SETQ);
    yylval.myToken = tk;
    return SETQ;
}

"mod"|"rem" {
    printf("<Token: %s\tType: %i>\n", yytext, MOD);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, MOD);
    yylval.myToken = tk;
    return MOD;
}

"incf" {
    printf("<Token: %s\tType: %i>\n", yytext, INCF);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, INCF);
    yylval.myToken = tk;
    return INCF;
}

"decf" {
    printf("<Token: %s\tType: %i>\n", yytext, DECF);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, DECF);
    yylval.myToken = tk;
    return DECF;
}

"max" {
    printf("<Token: %s\tType: %i>\n", yytext, MAX);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, MAX);
    yylval.myToken = tk;
    return MAX;
}

"min" {
    printf("<Token: %s\tType: %i>\n", yytext, MIN);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, MIN);
    yylval.myToken = tk;
    return MIN;
}

"and" {
    printf("<Token: %s\tType: %i>\n", yytext, AND);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, AND);
    yylval.myToken = tk;
    return AND;
}

"or" {
    printf("<Token: %s\tType: %i>\n", yytext, OR);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, OR);
    yylval.myToken = tk;
    return OR;
}

"not" {
    printf("<Token: %s\tType: %i>\n", yytext, NOT);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, NOT);
    yylval.myToken = tk;
    return NOT;
}

"logand" {
    printf("<Token: %s\tType: %i>\n", yytext, LA);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, LA);
    yylval.myToken = tk;
    return LA;
}

"logior" {
    printf("<Token: %s\tType: %i>\n", yytext, LO);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, LO);
    yylval.myToken = tk;
    return LO;
}

"logxor" {
    printf("<Token: %s\tType: %i>\n", yytext, LXOR);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, LXOR);
    yylval.myToken = tk;
    return LXOR;
}

"lognor" {
    printf("<Token: %s\tType: %i>\n", yytext, LNOR);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, LNOR);
    yylval.myToken = tk;
    return LNOR;
}

"logeqv" {
    printf("<Token: %s\tType: %i>\n", yytext, LEQV);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, LEQV);
    yylval.myToken = tk;
    return LEQV;
}

"block" {
    printf("<Token: %s\tType: %i>\n", yytext, BLOCK);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, BLOCK);
    yylval.myToken = tk;
    return BLOCK;
}

"return-from" {
    printf("<Token: %s\tType: %i>\n", yytext, RETURN);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, RETURN);
    yylval.myToken = tk;
    return RETURN;
}

"if" {
    printf("<Token: %s\tType: %i>\n", yytext, IF);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, IF);
    yylval.myToken = tk;
    return IF;
}

"in" {
    printf("<Token: %s\tType: %i>\n", yytext, IN);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, IN);
    yylval.myToken = tk;
    return IN;
}
 
 "do" {
    printf("<Token: %s\tType: %i>\n", yytext, DO);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, DO);
    yylval.myToken = tk;
    return DO;
 }

"loop" {
    printf("<Token: %s\tType: %i>\n", yytext, LOOP);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, LOOP);
    yylval.myToken = tk;
    return LOOP;
}

"when" {
    printf("<Token: %s\tType: %i>\n", yytext, WHEN);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, WHEN);
    yylval.myToken = tk;
    return WHEN;
}

"cond" {
    printf("<Token: %s\tType: %i>\n", yytext, COND);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, COND);
    yylval.myToken = tk;
    return COND;
}

"collect" {
    printf("<Token: %s\tType: %i>\n", yytext, COLLECT);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, COLLECT);
    yylval.myToken = tk;
    return COLLECT;
}

"for" {
    printf("<Token: %s\tType: %i>\n", yytext, FORMAT);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, FORMAT);
    yylval.myToken = tk;
    return FOR;
}

{digit}+("."{digit}+)?([eE][+-]?{digit}+)? {
    printf("<Token: %s\tType: %i>\n", yytext, NUM);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, NUM);
    yylval.myToken = tk;
    return NUM;
 }

"+"|"-"|"*"|"/" {
    printf("<Token: %s\tType: %i>\n", yytext, OP);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, OP);
    yylval.myToken = tk;
    return OP;
}

"=" {
    printf("<Token: %s\tType: %i>\n", yytext, EQ);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, EQ);
    yylval.myToken = tk;
    return EQ;
}
">" {
    printf("<Token: %s\tType: %i>\n", yytext, GT);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, GT);
    yylval.myToken = tk;
    return GT;
}
"/=" {
    printf("<Token: %s\tType: %i>\n", yytext, NE);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, NE);
    yylval.myToken = tk;
    return NE;
}
">=" {
    printf("<Token: %s\tType: %i>\n", yytext, GTE);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, GTE);
    yylval.myToken = tk;
    return GTE;
}
"<=" {
    printf("<Token: %s\tType: %i>\n", yytext, LTE);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, LTE);
    yylval.myToken = tk;
    return LTE;
}
"<" {
    printf("<Token: %s\tType: %i>\n", yytext, LT);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, LT);
    yylval.myToken = tk;
    return LT;
}

"(" {
    printf("<Token: %s\tType: %i>\n", yytext, LP);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, LP);
    yylval.myToken = tk;
    return LP;
}

")" {   
    printf("<Token: %s\tType: %i>\n", yytext, RP);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, RP);
    yylval.myToken = tk;
    return RP;
}

"\"".*"\"" {
    // printf("Lex Literal %s\n", yytext);
    printf("<Token: %s\tType: %i>\n", yytext, LIT);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, LIT);
    yylval.myToken = tk;
    return LIT;
}

\n|\t|" " {
    // printf("Lex heh\n");
}

[^\t\n ()'"\\,:;|]*[a-zA-Z][^\t\n ()'"\\,:;|]* {
    printf("<Token: %s\tType: %i>\n", yytext, ATOM);
    tk = allocToken();
    setTokenArguments(tk, yytext, yyleng, globalLC, globalCC, ATOM);
    yylval.myToken = tk;
    return ATOM;
}

%%
