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

"/*" {
   yylval->separator = 0;
   BEGIN (block_comment);
}
<block_comment>{
"*/" {
   BEGIN (INITIAL);
   return token::tSEPARATOR;
}
\n {
   yylval->separator += 1;
}
<<EOF>> {
   error ("block comment not terminated");
}
. /* eat comment */
}

"//".* /* eat comment */ {
   yylval->separator = 0;
   return token::tSEPARATOR;
}

"'".* /* eat comment */ {
   yylval->separator = 0;
   return token::tSEPARATOR;
}

^"#".* /* eat comment */ {
   yylval->separator = 0;
   return token::tSEPARATOR;
}

"rem"{whitespace}+.*|"remark"{whitespace}+.*|"comment"{whitespace}+.* /* eat comment */ {
   yylval->separator = 0;
   return token::tSEPARATOR;
}

"doc"|"docu"|"documentation" /* add to program documentation */ {
 //  add_doc (strdup (""));
   yylval->separator = 0;
   return token::tSEPARATOR;
}

"doc"{whitespace}+.*|"docu"{whitespace}+.*|"documentation"{whitespace}+.* /* add to program documentation */ {
   for (count = 1; *yytext != ' ' && *yytext != '\r' && *yytext != '\t' && *yytext != '\f' && *yytext != '\v'; count++) {
      yytext ++;
   }
   yytext ++;
  // add_doc (mystrdup (yytext));
   yylval->separator = 0;
   return token::tSEPARATOR;
}

\n {
   yylval->separator = 1;
   return token::tSEPARATOR;
}

{lcchar}{whitespace}*\n {  /* handle line continuation */
   yylineno += 1;
}

: {
   yylval->separator = 0;
   return token::tSEPARATOR;
}

{whitespace}+ /* eat whitespace */


long return token::tLONG;/* variables type*/

as return token::tAS;

arraydim return token::tARDIM;
arraysize return token::tARSIZE;
break return token::tBREAK;
case return token::tCASE;
compile return token::tCOMPILE;
continue return token::tCONTINUE;
csub return token::tCSUB;
data return token::tDATA;
dec|decrement return token::tDEC;
default return token::tDEFAULT;
dim 	{ printf("got DIM\n");   return token::tDIM;}
disable return token::tDISABLE;
do return token::tDO;
elseif|elsif|elif return token::tELSEIF;
else return token::tELSE;
enable|option return token::tENABLE;

end{whitespace}*data return token::tENDDATA;
end{whitespace}*if|fi return token::tENDIF;
end{whitespace}*struct|end{whitespace}*structure return token::tENDSTRUCT;
end{whitespace}*sub|end{whitespace}*subroutine return token::tENDSUB;
end{whitespace}*function return token::tENDFUNCTION;
end|{whitespace}*while	 return token::tWEND;
end{whitespace}*switch|end{whitespace}*select return token::tSEND;

eor|xor return token::tEOR;
exit|end return token::tEXIT;
explicit return token::tEXPLICIT;
for return token::tFOR;
from return token::tFROM;
gosub return token::tGOSUB;
goto return token::tGOTO;
if return token::tIF;
inc|increment return token::tINC;
input return token::tINPUT;
label return token::tLABEL;
let return token::tLET;
line return token::tLINE;
local return token::tLOCAL;
loop return token::tLOOP;
next return token::tNEXT;
poke return token::tPOKE;
print|\? return token::tPRINT;
read return token::tREAD;
repeat return token::tREPEAT;
restore return token::tRESTORE;
return return token::tRETURN;
seek return token::tSEEK;
static return token::tSTATIC;
step return token::tSTEP;
struct|structure return token::tSTRUCT;
function         return token::tFUNCTION;
sub|subroutine return token::tSUB;
switch|select return token::tSWITCH;
then return token::tTHEN;
to return token::tTO;
until return token::tUNTIL;
using return token::tUSING;
wend return token::tWEND;
while return token::tWHILE;

abs return token::tABS;
acos return token::tACOS;
asc return token::tASC;
asin return token::tASIN;
atan return token::tATAN;
chr\$ return token::tCHR;
close return token::tCLOSE;
cos return token::tCOS;
eof return token::tEOF;
execute return token::tEXECUTERETURNNUMBER;
execute\$ return token::tEXECUTERETURNSTRING;
exp return token::tEXP;
frac return token::tFRAC;
glob return token::tGLOB;
instr return token::tINSTR;
int return token::tINT;
intger return token::tINT;
left\$ return token::tLEFT;
len return token::tLEN;
log return token::tLOG;
lower\$ return token::tLOWER;
ltrim\$ return token::tLTRIM;
max return token::tMAX;
mid\$ return token::tMID;
min return token::tMIN;
open return token::tOPEN;
peek return token::tPEEK;
ran return token::tRAN;
\^|\*\* return token::tPOW;
right\$ return token::tRIGHT;
rinstr return token::tRINSTR;
rtrim\$ return token::tRTRIM;
sig return token::tSIG;
sin return token::tSIN;
split return token::tSPLIT;
split\$ return token::tSPLITALT;
sqr return token::tSQR;
sqrt return token::tSQRT;
str\$ return token::tSTR;
system return token::tSYSTEM;
tan return token::tTAN;
tell return token::tTELL;
token return token::tTOKEN;
token\$ return token::tTOKENALT;
trim\$ return token::tTRIM;
upper\$ return token::tUPPER;
val return token::tVAL;
call return token::tCALL;

"and" return token::tAND;
"mod"|"%" return token::tMOD;
"not" return token::tNOT;
"or" return token::tOR;
"=" return token::tEQU;
">=" return token::tGEQ;
">" return token::tGTN;
"<=" return token::tLEQ;
"<" return token::tLTN;
"<>" return token::tNEQ;
"!" return token::tNOT;

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

__date\$ {
   return token::tDATE;
}

__time\$ {
   return token::tTIME;
}

__env\$|__environment\$ {
   return token::tENV;
}

__numparams? {
   yylval->symbol = strdup ("__numparam");
   return token::tNUMSYM;
}

__system\$ {
   yylval->symbol = strdup (SYSTEM_NAME);
   return token::tSTRING;
}

__version\$ {
   yylval->string = strdup (VERSION);
   return token::tSTRING;
}

__arg\$|__args\$|__argument\$|__arguments\$ {
   return token::tARG;
}

__[_a-z0-9]*|__[_a-z0-9]*\$ {
   error ("symbol prefix \"__\" is reserved for internal variables");
}

{name} {
   yylval->symbol = strdup (yytext);
   return token::tNUMSYM;
}

{name}\$ {
   yylval->symbol = strdup (yytext);
   return token::tSTRSYM;
}

(([0-9]+|([0-9]*\.[0-9]*))([eE][-+]?[0-9]+)?) {
   yylval->number = strtod (yytext, NULL);
   return token::tNUMBER;
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
