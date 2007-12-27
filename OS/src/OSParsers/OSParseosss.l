/** @file parseosssl.l
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


#include <iostream>
#include "OSConfig.h"

#ifdef HAVE_CSTRING
# include <cstring>
#else
# ifdef HAVE_STRING_H
#  include <string.h>
# else
#  error "don't have header file for string"
# endif
#endif

#ifdef HAVE_CSTDIO
# include <cstdio>
#else
# ifdef HAVE_STDIO_H
#  include <stdio.h>
# else
#  error "don't have header file for stdio"
# endif
#endif
#include "OSErrorClass.h"
#include <sstream>   
#include "OSOptionsStruc.h" 


using std::cout;
using std::endl;
using std::ostringstream;

  
#define PARSERDEBUG
#ifdef PARSERDEBUG
	#define YY_PRINT  printf("%s", yytext);
#else     
	#define YY_PRINT  ;
#endif


#ifdef WIN_
  #define YY_NO_UNISTD_H
  #include <io.h>
  #include <process.h>
  #ifdef USE_OLD_UNISTD
     #include<sys/unistd.h>  
  #endif
#endif


#define YY_EXTRA_TYPE struct osOptionsStruc*

void setyyextra( osOptionsStruc *osoptions, void* scanner);

 /*
 * INPUTS:
 * -osil xxx.osil (file name on local machine of optimization instance, 
 *       this is "" by default, however if this remains "" a problem
 * 		 instance must be specified in the osol file)
 * -osol xxx.osol (file name on local machine of solver options, 
 *       default default value is "")
 * -osrl xxx.osrl (file name on local machine where the optimization 
 *       result is put, default is "")
 * -serviceLocation location URL (the URL  of the server that is called 
 *       remotely if the problem not solved locally, default is "")
 * -serviceMethod  (send, solve, kill, knock, getJobID, retrieve, 
 *       default value is solve)
 * -osplInput xxx.ospl  (Not used for now -- ignore)
 * -osplOutput xxx.ospl (Not used for now -- ignore)
 * -mps xxxx.mps (converts mps format to osil and has same effect as -osil)
 * -nl xxxx.nl (converts nl format to osil and has same effect as -osil)
 * -solver solverName (the name of the solver to be invoked)
 * -browser path location to browser e.g. 
 *       /Applications/Firefox.app/Contents/MacOS/firefox (default is "")
 * -config pathToConfigFile is the path to a configure file with the problem 
 * 	     parameters
 * -insList xxx.dat (used only for LINDO, file location on local 
 *       machine of LINDO instruction list)
*/
	int ossslex_init(void** ptr_yy_globals);

%}

%option reentrant
%option yylineno
%option prefix="osss"
%option noyywrap   



xmlwhitespace ([ \t\r\n])
optionValue ([-a-zA-Z./~:_0-9$]+|\"[^"\n]*["\n])
serviceMethod (solve|send|kill|retrieve|knock|getJobID)
browserState (on|off)
%% 

{xmlwhitespace}*
  


(-config{xmlwhitespace}+{optionValue}) {
	printf("Found option:  %s\n", yytext);  
	char *ch = strdup(yytext);
	// move past -config
	ch+=7;
	for(; isspace(*ch); ch++);
	std::string str(  ch);
	yyextra->configFile = str;
	//printf("gsgersdf= %d\n", gster);
}


(-osil{xmlwhitespace}+{optionValue}) {
	if(yyextra->osilFile == ""){
		printf("Found option:  %s\n", yytext);  
		char *ch = strdup(yytext);
		// move past -osil
		ch+=5;
		for(; isspace(*ch); ch++);
		std::string str(  ch);
		yyextra->osilFile = str;
	} 
}

(-osrl{xmlwhitespace}+{optionValue}) {
	if(yyextra->osrlFile == ""){
		printf("Found option:  %s\n", yytext); 
		char *ch = strdup(yytext);
		// move past -osrl
		ch+=5;
		for(; isspace(*ch); ch++);
		std::string str(  ch);
		yyextra->osrlFile = str;
	}  
}  

(-insList{xmlwhitespace}+{optionValue}) {
	if(yyextra->insListFile == ""){
		printf("Found option:  %s\n", yytext); 
		char *ch = strdup(yytext);
		// move past -insList
		ch+=8;
		for(; isspace(*ch); ch++);
		std::string str(  ch);
		yyextra->insListFile = str;
	}  
}  

(-osol{xmlwhitespace}+{optionValue}) {
	if(yyextra->osolFile == ""){
		printf("Found option:  %s\n", yytext); 
		char *ch = strdup(yytext);
		// move past -osol
		ch+=5;
		for(; isspace(*ch); ch++);
		std::string str(  ch);
		yyextra->osolFile = str;  
	}
}



(-osplInput{xmlwhitespace}+{optionValue}) {
	if(yyextra->osplInputFile == ""){
		printf("Found option:  %s\n", yytext); 
		char *ch = strdup(yytext);
		// move past -osplInput
		ch+=10;
		for(; isspace(*ch); ch++);
		std::string str(  ch);
		yyextra->osplInputFile = str;  
	}
}

(-osplOutput{xmlwhitespace}+{optionValue}) {
	if(yyextra->osplOutputFile == ""){
		printf("Found option:  %s\n", yytext); 
		char *ch = strdup(yytext);
		// move past -osplInput
		ch+=11;
		for(; isspace(*ch); ch++);
		std::string str(  ch);
		yyextra->osplOutputFile = str;  
	}
}

(-serviceMethod{xmlwhitespace}+{serviceMethod}) {
	if(yyextra->serviceMethod == ""){
		printf("Found option:  %s\n", yytext); 
		char *ch = strdup(yytext);
		// move past -serviceMethod
		ch+=14;
		for(; isspace(*ch); ch++);
		std::string str(  ch);
		yyextra->serviceMethod = str; 
	}
}

(-serviceLocation{xmlwhitespace}+{optionValue}) {
	if(yyextra->serviceLocation == ""){
		printf("Found option:  %s\n", yytext); 
		yyextra->serviceLocation = strdup(yytext);
		char *ch = strdup(yytext);
		// move past -serviceLocation
		ch+=16;
		for(; isspace(*ch); ch++);
		std::string str(  ch);
		yyextra->serviceLocation = str; 
	}
}

(-mps{xmlwhitespace}+{optionValue}) {
	if(yyextra->mpsFile == ""){
		printf("Found option:  %s\n", yytext); 
		char *ch = strdup(yytext);
		// move past -mps
		ch+=4;
		for(; isspace(*ch); ch++);
		std::string str(  ch);
		yyextra->mpsFile = str; 
	}
}

(-nl{xmlwhitespace}+{optionValue}) {
	if(yyextra->nlFile == ""){
		printf("Found option:  %s\n", yytext);
		char *ch = strdup(yytext);
		// move past -nl
		ch+=3;
		for(; isspace(*ch); ch++);
		std::string str(  ch);
		yyextra->nlFile = str;
	} 
}

(-solver{xmlwhitespace}+{optionValue}) {
	if(yyextra->solverName == ""){
		printf("Found option:  %s\n", yytext); 
		char *ch = strdup(yytext);
		// move past -solver
		ch+=7;
		for(; isspace(*ch); ch++);
		std::string str(  ch);
		yyextra->solverName = str;
	} 
}
 
(-browser{xmlwhitespace}+{optionValue}) {
	if(yyextra->browser == ""){
		printf("Found option:  %s\n", yytext);  
		char *ch = strdup(yytext);
		// move past -browser
		ch+=8;
		for(; isspace(*ch); ch++);
		std::string str(  ch);
		yyextra->browser = str; 
	}
}

. {
	std::string error;
	std::ostringstream outStr;
	outStr << "ecountered a spurious character in the lexer" << endl;
	outStr << "The first character is: ";
	outStr <<  yytext;
	outStr << endl;
	outStr << "See line number: " << yylineno << endl;  
	error = outStr.str();
	throw ErrorClass( error);  
}
%%

void setyyextra(osOptionsStruc *osoptions, void* scanner){
	osssset_extra(osoptions, scanner);
}


