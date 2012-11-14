/* A Bison parser, made by GNU Bison 2.6.4.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_HOME_CAI_PROJECTS_BASIC_PARSER_HPP_INCLUDED
# define YY_YY_HOME_CAI_PROJECTS_BASIC_PARSER_HPP_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     tNUMBER = 258,
     tSTRING = 259,
     tNUMSYM = 260,
     tSTRSYM = 261,
     tSEPARATOR = 262,
     tAND = 263,
     tOR = 264,
     tNOT = 265,
     tEOR = 266,
     tBREAK = 267,
     tCONTINUE = 268,
     tSUB = 269,
     tENDSUB = 270,
     tRETURN = 271,
     tCOMPILE = 272,
     tEXECUTERETURNNUMBER = 273,
     tEXECUTERETURNSTRING = 274,
     tCSUB = 275,
     tFROM = 276,
     tGOTO = 277,
     tGOSUB = 278,
     tLABEL = 279,
     tENABLE = 280,
     tDISABLE = 281,
     tEOPROG = 282,
     tNEWFILE = 283,
     tEXIT = 284,
     tEXPLICIT = 285,
     tFOR = 286,
     tTO = 287,
     tNEXT = 288,
     tSTEP = 289,
     tWHILE = 290,
     tWEND = 291,
     tREPEAT = 292,
     tUNTIL = 293,
     tDO = 294,
     tLOOP = 295,
     tIF = 296,
     tTHEN = 297,
     tELSE = 298,
     tELSEIF = 299,
     tENDIF = 300,
     tAS = 301,
     tLET = 302,
     tDIM = 303,
     tLOCAL = 304,
     tSTATIC = 305,
     tARDIM = 306,
     tARSIZE = 307,
     tINC = 308,
     tDEC = 309,
     tNEQ = 310,
     tLEQ = 311,
     tGEQ = 312,
     tLTN = 313,
     tGTN = 314,
     tEQU = 315,
     tPOW = 316,
     tPRINT = 317,
     tINPUT = 318,
     tLINE = 319,
     tUSING = 320,
     tSTRUCT = 321,
     tENDSTRUCT = 322,
     tSWITCH = 323,
     tSEND = 324,
     tCASE = 325,
     tDEFAULT = 326,
     tDATA = 327,
     tENDDATA = 328,
     tREAD = 329,
     tRESTORE = 330,
     tABS = 331,
     tSIG = 332,
     tRAN = 333,
     tSQR = 334,
     tSQRT = 335,
     tINT = 336,
     tFRAC = 337,
     tMIN = 338,
     tMAX = 339,
     tLEFT = 340,
     tRIGHT = 341,
     tMID = 342,
     tUPPER = 343,
     tLOWER = 344,
     tOPEN = 345,
     tCLOSE = 346,
     tEOF = 347,
     tSEEK = 348,
     tTELL = 349,
     tPEEK = 350,
     tPOKE = 351,
     tSIN = 352,
     tASIN = 353,
     tCOS = 354,
     tACOS = 355,
     tTAN = 356,
     tATAN = 357,
     tEXP = 358,
     tLOG = 359,
     tSTR = 360,
     tCHR = 361,
     tVAL = 362,
     tASC = 363,
     tLEN = 364,
     tSYSTEM = 365,
     tARG = 366,
     tENV = 367,
     tTIME = 368,
     tDATE = 369,
     tTOKEN = 370,
     tTOKENALT = 371,
     tSPLIT = 372,
     tSPLITALT = 373,
     tGLOB = 374,
     tTRIM = 375,
     tLTRIM = 376,
     tRTRIM = 377,
     tINSTR = 378,
     tRINSTR = 379,
     tMOD = 380,
     UPLUS = 381,
     UMINUS = 382
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2077 of yacc.c  */
#line 87 "parser.ypp"

   char *string;         /* quoted string */
   char *symbol;         /* general symbol */
   double number;        /* double number */
   int separator;        /* separator */


/* Line 2077 of yacc.c  */
#line 192 "/home/cai/projects/basic/parser.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_HOME_CAI_PROJECTS_BASIC_PARSER_HPP_INCLUDED  */
