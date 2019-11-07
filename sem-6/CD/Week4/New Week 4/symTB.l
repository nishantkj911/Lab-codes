%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "symTB.h"

	int cnt=0, scopeCount = 0;
	char scope = 'G';
enum tokens
{
	EOFO=-1,
	AO,
	keyword,
	identifier,
	LT,
	LTE,
	GT,
	GTE,
	EQ,
	NE,
	LO,
	BO,
	SYM,
	LB,
	RB,
	LC,
	RC,
	LS,
	RS,
	SC,
	COMMA,
	NUM,
	ASS
};
	struct token
{
	int lc, cc;
	char *buf;
	int index;
	enum tokens type;
};

typedef struct token Token;

#define YY_DECL Token* yylex(void)

int lc=1,cc=1;
Token *tk;
char buf[BUFSIZ];

Token* allocToken(){
	Token *tk;
	tk=malloc(sizeof(Token));
	tk->buf=malloc(sizeof(char)*256);
	tk->index=-1;
	tk->type=EOFO;
	return tk;

}

void setTokenArgs(Token *tk,char *buf,int l,int c,enum tokens type)
{
	if(tk==NULL)
		return;
	strcpy(tk->buf,buf);
	tk->lc=l;
	tk->cc=c;
	tk->type=type;	

	fprintf(yyout,"Lexeme: %s\tLine no: %d\tCol No: %d\tType: %d\n",tk->buf,tk->lc,tk->cc,tk->type);
	cnt++;
}

%}

letter_ [a-zA-Z_]
digit [0-9]
datatype "int"|"char"|"double"|"float"
otherkeywords "if"|"else"|"while"|"for"|"do"|"break"|"continue"|"return"

%%
"//".*"\n" {lc++;cc=1;}
(\"(.)*\") {cc+=strlen(yytext);}
(\'(.)\') {cc+=strlen(yytext);}
\n {cc=1;lc++;
memset(buf,'\0',BUFSIZ);}
\t {cc+=8;}
" " {cc+=1;}
"#".*"\n" {lc++;}

"/*"(.|"\n")*"*/" {
	printf("%s\n",yytext);
	int i=0;
	while(yytext[i]!='\0')
	{
		if(yytext[i]=='\n')
		{ 
			lc++;
		    cc=1;
		}
		else
		cc++;
		i++;
	}
	
}

{otherkeywords} {

	tk = allocToken();
	setTokenArgs(tk, yytext, lc, cc, keyword);
	cc+=yyleng;
	return tk;
}

{datatype} {
	tk = allocToken();
	setTokenArgs(tk, yytext, lc, cc, keyword);
	cc+=yyleng;
	strcpy(buf,yytext);
	return tk;
}


"<=" {
	tk=allocToken();
    setTokenArgs(tk,yytext,lc,cc,LTE);
    cc+=2;
    return tk;
}  
"<" {
	tk=allocToken();
    setTokenArgs(tk,yytext,lc,cc,LT);
    cc++;
    return tk;
}
">=" {
	tk=allocToken();
    setTokenArgs(tk,yytext,lc,cc,GTE);
    cc+=2;
    return tk;
}  

">" {
	tk=allocToken();
    setTokenArgs(tk,yytext,lc,cc,GT);
    cc++;
    return tk;
} 
"==" {tk=allocToken();
    setTokenArgs(tk,yytext,lc,cc,EQ);
    cc+=2;
    return tk;}    
"!=" {tk=allocToken();
    setTokenArgs(tk,yytext,lc,cc,NE);
    cc+=2;
    return tk;}


{letter_}({letter_}|{digit})* {
	Token *idToken = allocToken();
	int size = 0;
	setTokenArgs(idToken, yytext, lc, cc, identifier);
	cc+=strlen(yytext);
	int index = 0;
	char temp[100];
	strcpy(temp, idToken->buf);

	// printf("\ntk->buf:%s",tk->buf);

	Token *tk1 = yylex();
	// printf("\ntk1->buf:%s",tk1->buf);
	index=search(st, temp);


	if(tk1->type==LB)
	{
		// function
		// printf("index:%d\n",index);

		if(st[index].name==NULL)
		{

			//printf("Coming into decl of fn %s\n", temp);
			int argindex = 0;
			int *args=calloc(20,sizeof(int));
			Token* argtok;	
			do
			{
				if(strcmp(temp, "printf") == 0 || strcmp(temp, "scanf") == 0)
				{
					insert(st, index, temp, 0, "function", scope, 0, NULL, buf);
					idToken->index = index;
					return idToken;
				}

				argtok=yylex();
				//printf("Argument: '%s'\n", argtok->buf);
				if(argtok->type == identifier)
				{
					args[argindex++] = search(st, argtok->buf);
				}
					
			} while(argtok->type != LC);

			insert(st, index, temp, 0, "function", scope, argindex, args, buf);
		}
	}

	//printf("identifier: %s\tbuf val: '%s'\n", idToken->buf, buf);
	if(strcmp(buf,"int")==0)
		size=sizeof(int);
	else if(strcmp(buf,"char")==0)
		size=sizeof(char);
	else if(strcmp(buf,"float")==0)
		size=sizeof(float);
	else if(strcmp(buf,"double")==0)
		size=sizeof(double);

	if(tk1->type==COMMA || tk1->type==SC || tk1->type==assignment || tk1->type==RB)
	{
		if(st[index].name==NULL)
		{
			insert(st, index, temp, size, "Variable", scope, 0, NULL, buf);
		}
	}
	else if(tk1->type==LS)
	{
		Token *tk2=yylex();
		if(st[index].name==NULL  && tk2->type == NUM)
		{
			//printf("\nnum:%d",toNum(tk2->buf));
			insert(st, index, temp, size* toNum(tk2->buf), "Array", scope, 0, NULL, buf);
		}

	}


	idToken->index=index;
		
	// printST(st);
	return idToken;
}

{digit}+ {
	tk=allocToken();
    setTokenArgs(tk,yytext,lc,cc,NUM);
    cc+=strlen(yytext);
    return tk;}


"++" {
	tk=allocToken();
    setTokenArgs(tk,yytext,lc,cc,AO);
    cc+=2;
    return tk;}
"+=" {tk=allocToken();
    setTokenArgs(tk,yytext,lc,cc,AO);
    cc+=2;
    return tk;}
"--" {tk=allocToken();
    setTokenArgs(tk,yytext,lc,cc,AO);
    cc+=2;
    return tk;}
"-=" {tk=allocToken();
    setTokenArgs(tk,yytext,lc,cc,AO);
    cc+=2;
    return tk;}
"*=" {tk=allocToken();
    setTokenArgs(tk,yytext,lc,cc,AO);
    cc+=2;
    return tk;}
"/=" {tk=allocToken();
    setTokenArgs(tk,yytext,lc,cc,AO);
    cc+=2;
    return tk;}
"+|-|*|/" {tk=allocToken();
    setTokenArgs(tk,yytext,lc,cc,AO);
    cc+=1;
    return tk;}    
"&&" {tk=allocToken();
    setTokenArgs(tk,yytext,lc,cc,LO);
    cc+=2;
    return tk;}
"&" {tk=allocToken();
    setTokenArgs(tk,yytext,lc,cc,BO);
    cc+=1;
    return tk;}
"||" {tk=allocToken();
    setTokenArgs(tk,yytext,lc,cc,AO);
    cc+=2;
    return tk;}
"|" {tk=allocToken();
    setTokenArgs(tk,yytext,lc,cc,BO);
    cc+=1;
    return tk;}
"=" {tk=allocToken();
    setTokenArgs(tk,yytext,lc,cc,assignment);
    cc+=1;
    return tk;}
"{" {tk=allocToken();
    setTokenArgs(tk,yytext,lc,cc,LC);
    cc+=1;
	scopeCount++;
	scope = 'L';
    return tk;}
"}" {tk=allocToken();
    setTokenArgs(tk,yytext,lc,cc,RC);
    cc+=1;
	scopeCount--;
	if (scopeCount == 0)
	{
		scope = 'G';
	}
    return tk;}
"(" {tk=allocToken();
    setTokenArgs(tk,yytext,lc,cc,LB);
	scopeCount++;
	scope = 'L';
    cc+=1;
    return tk;}
")" {tk=allocToken();
    setTokenArgs(tk,yytext,lc,cc,RB);
    cc+=1;
	scopeCount--;
	if (scopeCount == 0)
	{
		scope = 'G';
	}
    return tk;}
"[" {tk=allocToken();
    setTokenArgs(tk,yytext,lc,cc,LS);
    cc+=1;
    return tk;}
"]" {tk=allocToken();
    setTokenArgs(tk,yytext,lc,cc,RS);
    cc+=1;
    return tk;}
";" {tk=allocToken();
    setTokenArgs(tk,yytext,lc,cc,SC);
    cc+=1;
    return tk;}
"," {
	tk=allocToken();
    setTokenArgs(tk,yytext,lc,cc,COMMA);
    cc+=1;
	return tk;
}	
%%

int main(int argc,char* argv[])
{
	yyin=fopen("evalTest.c","r");
	yyout=fopen("output1.txt","w");
	st = init();
	while((tk = yylex()))
	{
		//calling yylex repeatedly
	}

	printST(st);
	return 0;
}

int yywrap()
{
	return 1;
}