%{
#include <stdio.h>
#include "tokens.h"
#include "tabsimb.h"
int linha = 1;
%}

dig     [0-9]
letra   [a-zA-Z_]

%%

"int"                   { return INT ; }
"float"                 { return FLOAT ; }
"char"                  { return CHAR; }
"void"                  {return VOID;}


"if"                    { return IF ; }
"else"                  { return ELSE; }
"for"                   { return FOR; }
"while"                 { return WHILE; }


"and"                   { return AND; }
"||"                    { return OR; }
"not"                   { return NOT; }

\"[^\"]*\"              { return STRING; }
"["                     {return abrecolchete;}
"]"                     {return FECHACOLCHETE;}
">"                     { return GT; }
"<"                     { return LT; }
"<="                    { return LE; }
">="                    { return GE; }
"=="                    { return EQ; }
"("                     { return ABREPARENTESE; }
")"                     { return FECHAPARENTESE; }
"{"                     { return ABRECHAVE; }
"}"                     { return FECHACHAVE; }
";"                     { return PONTOVIRGULA; }
"="                     { return IGUAL; }
","                     { return VIRGULA; }
"return"                { return RETURN; }
"\%"                    {return PERCENTO;}
"\\"                    {return BARRAINVERTIDA;}
"\""                    {return PARENTESE;}
"."                    {return PONTOFINAL;}

"+"                     { return MAIS; }
"-"                     { return MENOS; }
"*"                     { return VEZES; }
"/"                     { return DIVIDIDO; }

"aspas"                 {return ASPAS;}


{dig}+("."{dig}+)?	{ return NUM;}
{letra}({letra}|{dig})*  { insere(yytext);
                           return ID;}  
[ \t\r] {}
\n	{ linha++; }
.	{printf("erro lexico na linha %d - %s\n",
             linha, yytext); }
%%
#ifndef yywrap
int yywrap() { return 1; }
#endif
void main(int argc, char **argv) {
int token,i=1;	
	yyin = fopen(argv[1],"r");
	token = yylex();
	while(token) {
		printf("%d) %d %s\n", i++, token, yytext);
		token = yylex();
	}
	imprime();
}
