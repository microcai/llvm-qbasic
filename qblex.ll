%{

#include "ast.h"
#include "parser.hpp"
#define SAVE_TOKEN yylval.string = new std::string(yytext, yyleng)
#define TOKEN(t) (yylval.token = t)
extern "C" int yywrap() { }
%}

%%

[\r\n]				{return TOKEN(NEWLINE);}

[ \t]*					;
\0177 return TOKEN(NEWLINE);

asdfsdfskdjhfksf	 return WHITESPACE;

PRINT 		{return TOKEN(TPRINT);}
print  		{return TOKEN(TPRINT);}

LET				{return TOKEN(LET);}


[a-zA-Z_][a-zA-Z0-9_]*  SAVE_TOKEN; return TIDENTIFIER;
[0-9]+\.[0-9]*          SAVE_TOKEN; return TDOUBLE;
[0-9]+                  SAVE_TOKEN; return TINTEGER;
;


"="                     return TOKEN(TQBEQUAL);
.	printf("Unknown token : (%s)(%d)@%d\n",yytext,yytext[0],(int)yyleng);yyterminate();

%%