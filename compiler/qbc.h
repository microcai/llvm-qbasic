#pragma once
/*
    main header file
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
#include <stdio.h>
#include <string>
#include <list>
#include <boost/shared_ptr.hpp>
#include <llvm/Value.h>
#include <llvm/Module.h>
#include <llvm/Support/IRBuilder.h>

#include "ast.hpp"

#ifdef __linux__
#define SYSTEM_NAME "Linux"
#endif

#define VERSION "0.1"

/* Yabasic commands. */
enum {
   cAND, cANDSHORT, cARDIM, cARRAYLINK, cARSIZE, cBREAK, cBREAK_HERE,
   cBREAK_MARK, cCALL, cCALL_EXTERNAL, cCHANGESTRING,
   cCLEAN_SWITCH_MARK, cCLEARREFS, cCLOSE, cCOMPILE, cCONCAT,
   cCONTINUE,
   cCONTINUE_CORRECTION, cCONTINUE_HERE, cDECIDE, cDIM,
   cDOARRAY, cDUPLICATE, cEND_FUNCTION, cENDSTRUCT, cEOPROG,
   cEXECUTERETURNNUMBER, cEXECUTERETURNSTRING, cEXIT,
   cFINDNOP, cFORCHECK, cFORINCREMENT, cFUNCTION, cGLOB, cGOSUB,
   cGOTO, cLABEL, cMAKELOCAL, cMAKESTATIC, cMINOR_BREAK, cNEGATE,
   cNEXT_CASE, cNOP, cNOT, cNUMADD, cNUMBER_FUNCTION_OR_ARRAY,
   cNUMDIV, cNUMEQ, cNUMGE, cNUMGT, cNUMLE, cNUMLT, cNUMMIN, cNUMMOD,
   cNUMMUL, cNUMNE, cNUMPARAM, cNUMPOW, cOPEN, cOPTEXPLICIT, cOR,
   cORSHORT, cPOKEFILE, cPOP, cPOPNUMSYM, cPOPSTREAM, cPOPSTRSYM,
   cPOPSYMLIST,
   cPRINT, cPUSHARRAYREF, cPUSHFREE, cPUSHNUM, cPUSHNUMSYM, cPUSHSTR,
   cPUSHSTREAM, cPUSHSTRPTR, cPUSHSTRSYM, cPUSH_SWITCH_MARK,
   cPUSHSYMLIST, cQCALL, cQGOSUB, cQGOTO, cQRESTORE, cREAD, cDATAREAD, cQDATAREAD, cDATARESTORE, cQDATARESTORE, cREQUIRE,
   cRESETSKIPONCE, cRET_FROM_FUN, cRETURN, cRETVAL, cSEEK, cSEEK2,
   cSKIPONCE, cSPLIT, cSPLIT2, cSPLITALT, cSPLITALT2, cSTARTFOR,
   cSTREQ, cSTRGE, cSTRGT, cSTRING_FUNCTION_OR_ARRAY, cSTRLE, cSTRLT,
   cSTRNE, cSTRUCT, cSTRUCTARGPOP, cSTRUCTVAR, cSWAP, cSWITCH_COMPARE,
   cTESTEOF, cTOKEN, cTOKEN2, cTOKENALT, cTOKENALT2, cUSER_FUNCTION
};

char *replace (char *);         /* replace escape characters */
