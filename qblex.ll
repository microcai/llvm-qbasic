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


%{

/* Include main header file. */
#include "qbc.h"

/* Get tokens from parser library. */
#include "parser.hpp"

#define error printf
/* Local variables. */
int count = 0;                  /* for strings */
int scanning_string = false;    /* scanning a string as opposed to a file? */
%}

name [_a-z][_a-z0-9]*
whitespace [ \r\t\f\v]
lcchar [\\_]

%option caseless
%option noinput
%option nounput
%option noyywrap

%x block_comment

%%

<INITIAL><<EOF>> {

   return tEOPROG;
   
}

"/*" {
   yylval.separator = 0;
   BEGIN (block_comment);
}
<block_comment>{
"*/" {
   BEGIN (INITIAL);
   return tSEPARATOR;
}
\n {
   yylval.separator += 1;
}
<<EOF>> {
   error ("block comment not terminated");
}
. /* eat comment */
}

"//".* /* eat comment */ {
   yylval.separator = 0;
   return tSEPARATOR;
}

"'".* /* eat comment */ {
   yylval.separator = 0;
   return tSEPARATOR;
}

^"#".* /* eat comment */ {
   yylval.separator = 0;
   return tSEPARATOR;
}

"rem"{whitespace}+.*|"remark"{whitespace}+.*|"comment"{whitespace}+.* /* eat comment */ {
   yylval.separator = 0;
   return tSEPARATOR;
}

"doc"|"docu"|"documentation" /* add to program documentation */ {
 //  add_doc (strdup (""));
   yylval.separator = 0;
   return tSEPARATOR;
}

"doc"{whitespace}+.*|"docu"{whitespace}+.*|"documentation"{whitespace}+.* /* add to program documentation */ {
   for (count = 1; *yytext != ' ' && *yytext != '\r' && *yytext != '\t' && *yytext != '\f' && *yytext != '\v'; count++) {
      yytext ++;
   }
   yytext ++;
  // add_doc (mystrdup (yytext));
   yylval.separator = 0;
   return tSEPARATOR;
}

\n {
   yylval.separator = 1;
   return tSEPARATOR;
}

{lcchar}{whitespace}*\n {  /* handle line continuation */
   yylineno += 1;
}

: {
   yylval.separator = 0;
   return tSEPARATOR;
}

{whitespace}+ /* eat whitespace */

arraydim return tARDIM;
arraysize return tARSIZE;
as return tAS;
break return tBREAK;
case return tCASE;
compile return tCOMPILE;
continue return tCONTINUE;
csub return tCSUB;
data return tDATA;
dec|decrement return tDEC;
default return tDEFAULT;
dim return tDIM;
disable return tDISABLE;
do return tDO;
elseif|elsif|elif return tELSEIF;
else return tELSE;
enable|option return tENABLE;
end{whitespace}*data return tENDDATA;
end{whitespace}*if|fi return tENDIF;
end{whitespace}*struct|end{whitespace}*structure return tENDSTRUCT;
end{whitespace}*sub|end{whitespace}*subroutine return tENDSUB;
end{whitespace}*switch|end{whitespace}*select return tSEND;
eor|xor return tEOR;
exit|end return tEXIT;
explicit return tEXPLICIT;
for return tFOR;
from return tFROM;
gosub return tGOSUB;
goto return tGOTO;
if return tIF;
inc|increment return tINC;
input return tINPUT;
label return tLABEL;
let return tLET;
line return tLINE;
local return tLOCAL;
loop return tLOOP;
next return tNEXT;
poke return tPOKE;
print|\? return tPRINT;
read return tREAD;
repeat return tREPEAT;
restore return tRESTORE;
return return tRETURN;
seek return tSEEK;
static return tSTATIC;
step return tSTEP;
struct|structure return tSTRUCT;
sub|subroutine return tSUB;
switch|select return tSWITCH;
then return tTHEN;
to return tTO;
until return tUNTIL;
using return tUSING;
wend return tWEND;
while return tWHILE;

abs return tABS;
acos return tACOS;
asc return tASC;
asin return tASIN;
atan return tATAN;
chr\$ return tCHR;
close return tCLOSE;
cos return tCOS;
eof return tEOF;
execute return tEXECUTERETURNNUMBER;
execute\$ return tEXECUTERETURNSTRING;
exp return tEXP;
frac return tFRAC;
glob return tGLOB;
instr return tINSTR;
int return tINT;
left\$ return tLEFT;
len return tLEN;
log return tLOG;
lower\$ return tLOWER;
ltrim\$ return tLTRIM;
max return tMAX;
mid\$ return tMID;
min return tMIN;
open return tOPEN;
peek return tPEEK;
ran return tRAN;
\^|\*\* return tPOW;
right\$ return tRIGHT;
rinstr return tRINSTR;
rtrim\$ return tRTRIM;
sig return tSIG;
sin return tSIN;
split return tSPLIT;
split\$ return tSPLITALT;
sqr return tSQR;
sqrt return tSQRT;
str\$ return tSTR;
system return tSYSTEM;
tan return tTAN;
tell return tTELL;
token return tTOKEN;
token\$ return tTOKENALT;
trim\$ return tTRIM;
upper\$ return tUPPER;
val return tVAL;

"and" return tAND;
"mod"|"%" return tMOD;
"not" return tNOT;
"or" return tOR;
"=" return tEQU;
">=" return tGEQ;
">" return tGTN;
"<=" return tLEQ;
"<" return tLTN;
"<>" return tNEQ;
"!" return tNOT;

[-+*/:(),.;] {
   return yytext[1 - 1];
}

inf|infinity {
   yylval.number = strtod ("inf", NULL);
   return tNUMBER;
}

nan {
   yylval.number = strtod ("nan", NULL);
   return tNUMBER;
}

pi {
   yylval.number = 3.1415926535897932;
   return tNUMBER;
}

euler {
   yylval.number = 2.7182818284590452;
   return tNUMBER;
}

true {
   yylval.number = 1;
   return tNUMBER;
}

false {
   yylval.number = 0;
   return tNUMBER;
}

__date\$ {
   return tDATE;
}

__time\$ {
   return tTIME;
}

__env\$|__environment\$ {
   return tENV;
}

__numparams? {
   yylval.symbol = strdup ("__numparam");
   return tNUMSYM;
}

__system\$ {
   yylval.symbol = strdup (SYSTEM_NAME);
   return tSTRING;
}

__version\$ {
   yylval.string = strdup (VERSION);
   return tSTRING;
}

__arg\$|__args\$|__argument\$|__arguments\$ {
   return tARG;
}

__[_a-z0-9]*|__[_a-z0-9]*\$ {
   error ("symbol prefix \"__\" is reserved for internal variables");
}

{name} {
   yylval.symbol = strdup (yytext);
   return tNUMSYM;
}

{name}\$ {
   yylval.symbol = strdup (yytext);
   return tSTRSYM;
}

(([0-9]+|([0-9]*\.[0-9]*))([eE][-+]?[0-9]+)?) {
   yylval.number = strtod (yytext, NULL);
   return tNUMBER;
}

\"[^"\n]*(\"|\n) {
   if (yytext[yyleng - 1] == '\n') {
      error ("string not terminated");
   }
   for (count = 0; yytext[(yyleng - count - 1) - 1] == '\\'; count++);
   if (count % 2) {
      yyless (yyleng - 1);
      yymore ();
   }
   else {
      yylval.string = strdup (yytext + 1);
      *(yylval.string + yyleng - 2) = '\0';
      replace (yylval.string);
      return tSTRING;
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
      error ("%s at end of line", msg);
   }
   else {
      error ("%s at \"%s\"", msg, yytext);
   }

   /* Return. */
   return;
}

/* Open a string for scanning. Note that this function should only be
 * used either *before* the first file has been parsed or *after* the
 * last file has been parsed. */
void open_string (char *string) {
   /* Switch to string buffer. */
   scanning_string = true;
   yy_switch_to_buffer (yy_scan_string (string));
   //current_file = current->file;
  // yylineno = current->line;

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
