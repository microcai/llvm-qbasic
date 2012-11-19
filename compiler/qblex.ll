/*
    lexcial analize for QBASIC
	Copyright (C) 2009-2010 Thomas Larsen and Pedro Sá.
	Copyright (C) 1995-2005 Marc-Oliver Ihm.
    Copyright (C) 2012  microcai <microcai@fedoraproject.org>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 3 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

%option caseless
%option noinput
%option nounput
%option noyywrap
%option nounistd
%option bison-bridge
%x block_comment
%x remark
%x documentation

%{

/* Include main header file. */
#include "qbc.h"

/* Get tokens from parser library. */
#include "parser.hpp"

using namespace qb;

typedef parser::semantic_type YYSTYPE;
typedef location YYLTYPE;
typedef parser::token token;

#define error printf
/* Local variables. */
int count = 0;                  /* for strings */

%}

name [_a-z][_a-z0-9]*
whitespace [ \r\t\f\v]
lcchar [\\_]
 

%%

<INITIAL><<EOF>> {
   return token::tEOPROG;
}

rem {
	BEGIN(remark);
}

"/*" {
   BEGIN (block_comment);
}

"//".* /* eat comment */ {
   
}

"'".* /* eat comment */ {
}

\n* {
	yylineno += strlen(yytext);
   return token::tNEWLINE;
}

end{whitespace}*sub|end{whitespace}*subroutine	return token::tSUBEND;
end{whitespace}*function 						return token::tFUNCTIONEND;
fi|end{whitespace}*if							return token::tENDIF;
end{whitespace}*while							return token::tENDWHILE;
end{whitespace}*for								return token::tENDFOR;

wend				{ printf("while end ! ======\n");return token::tENDWHILE; }
while 				{ printf("while begin ! ======\n");return token::tWHILE; }

function			return token::tFUNCTION;
sub|subroutine		return token::tSUB;
if					return token::tIF;
then				return token::tTHEN;
else				return token::tELSE;
elif|elseif			return token::tELSEIF;
return				return token::tRETURN;
for					return token::tFOR;
to 					return token::tTO;
setp				return token::tSTEP;

str|string			return token::tSTR;
int|long			return token::tLONG;/* variables type*/

as 					return token::tAS;
dim					return token::tDIM;

let					return token::tLET;

print				return token::tPRINT;

"->" 				return token::tDREF;

\^|\*\* 			return token::tPOW;

"and"				return token::tAND;
"&&"				return token::tAND;

"mod"|"%"|"\\"		return token::tMOD;
"|"|"or"			return token::tOR;
"="|"=="			return token::tEQU;

">="				return token::tGEQ;
">"					return token::tGTN;
"<="				return token::tLEQ;
"<"					return token::tLTN;
"<>"				return token::tNEQ;
"not"|"!"			return token::tNOT;

{whitespace}+ /* eat whitespace */

[-+*/:(),.;] {
   return yytext[1 - 1];
}

inf|infinity {
   yylval->number = strtod ("inf", NULL);
   return token::tNUMBER;
}

nan {
   yylval->number = strtod ("nan", NULL);
   return token::tNUMBER;
}

pi {
   yylval->number = 3.1415926535897932;
   return token::tNUMBER;
}

euler {
   yylval->number = 2.7182818284590452;
   return token::tNUMBER;
}

true {
   yylval->number = 1;
   return token::tNUMBER;
}

false {
   yylval->number = 0;
   return token::tNUMBER;
}



-[0-9]* {
   yylval->integer = atol (yytext);
   printf("got %d\n",yylval->integer);
   return token::tInteger;
}

\+[0-9]* {
   yylval->integer = atol (yytext);
   printf("got %d\n",yylval->integer);
   return token::tInteger;
}


[0-9]* {
   yylval->integer = atol (yytext);
   printf("got %d\n",yylval->integer);
   return token::tInteger;
}

(([0-9]+|([0-9]*\.[0-9]+))([eE][-+]?[0-9]+)?) {
   yylval->number = strtod (yytext, NULL);
    printf("got %f\n",yylval->number);

   return token::tNUMBER;
}

{name} {
   yylval->id = new std::string (yytext);
//   printf("got %s\n", yytext);
   return token::tID;
}

{name}\$ {
   yylval->id = new std::string (yytext);
   return token::tID;
}


\"[^"\n]*(\"|\n) {
   if (yytext[yyleng - 1] == '\n') {
      printf ("string not terminated");
   }
   for (count = 0; yytext[(yyleng - count - 1) - 1] == '\\'; count++);
   if (count % 2) {
      yyless (yyleng - 1);
      yymore ();
   }
   else {
      yylval->string = strdup (yytext + 1);
      *(yylval->string + yyleng - 2) = '\0';
      replace (yylval->string);
      return token::tSTRING;
   }
}

. {
   return yytext[1 - 1];
}

<block_comment>{

"*/"    BEGIN (INITIAL);

<<EOF>>   error ("block comment not terminated");

.
\n yylineno ++;

}

<remark>{
.

\n	BEGIN(INITIAL);
}

%%

/* Report an error. */
void yyerror (char *msg) {
   /* Report the error. */
   if (*yytext == '\n' || *yytext == '\0') {
      printf ("%s at end of line", msg);
   }
   else {
      printf ("%s at \"%s\"", msg, yytext);
   }

   /* Return. */
   return;
}

/* Replace escape characters. */
char *replace (char *string) {
   char *from, *to, *pointer;
   char *hexdigits = "0123456789abcdef";
   int value;

   /* Initialise. */
   from = string;
   to = string;

   /* Replace. */
   while (*from) {
      if (*from == '\\') {
         from++;
         switch (*from) {
            case 'n':
               *to = '\n';
               break;
            case 't':
               *to = '\t';
               break;
            case 'v':
               *to = '\v';
               break;
            case 'b':
               *to = '\b';
               break;
            case 'r':
               *to = '\r';
               break;
            case 'f':
               *to = '\f';
               break;
            case 'a':
               *to = '\a';
               break;
            case '\\':
               *to = '\\';
               break;
            case '\?':
               *to = '\?';
               break;
            case '\'':
               *to = '\'';
               break;
            case '\"':
               *to = '\"';
               break;
            case 'x':
               value = 0;
               if ((pointer =
                    strchr (hexdigits, tolower (*(from + 1))))
                   && pointer - hexdigits < 16) {
                  from++;
                  value = pointer - hexdigits;
                  if ((pointer =
                       strchr (hexdigits, tolower (*(from + 1))))
                      && pointer - hexdigits < 16) {
                     from++;
                     value *= 16;
                     value += pointer - hexdigits;
                  }
               }
               *to = value;
               break;
            default:
               *to = '\\';
               to++;
               *to = *from;
               break;
         }
      }
      else
         *to = *from;
      from++;
      to++;
   }
   *to = '\0';

   /* Return. */
   return string;
}
