/** @file parseosol.l
 * 
 * @author  Robert Fourer,  Jun Ma, Kipp Martin, 
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005, Robert Fourer, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */
%{

#include <stdio.h> 
#include "OSConfig.h"
#include <iostream>

#ifdef PARSERDEBUG
	#define YY_PRINT  printf("%s", osoltext);
#else     
	#define YY_PRINT  ;
#endif
#ifdef WIN_
#define YY_NO_UNISTD_H
#include <io.h>
#include <process.h>
#endif
     
%}

%option prefix="osol"
%option noyywrap
%option reentrant

%option yylineno   


  


xmlwhitespace ([ \t\r\n])
anumber (-?((([0-9]+)|([0-9]*\.[0-9]+))([eE][-+]?[0-9]+)?))
%% 

{xmlwhitespace}*

{anumber} 

%%


