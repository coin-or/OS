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

#include <stdio.h> 
#include "ErrorClass.h"
#include <sstream>   
#include "osOptionsStruc.h" 


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
#endif
#define YY_EXTRA_TYPE struct osOptionsStruc*

void setyyextra( osOptionsStruc *osoptions, void* scanner);

 /*
 * INPUTS:
 * -osil xxx.osil (file name on local machine of optimization instance, 
 *       this is NULL by default, however if this remains NULL a problem
 * 		 instance must be specified in the osol file)
 * -osol xxx.osol (file name on local machine of solver options, 
 *       default default value is NULL)
 * -osrl xxx.osrl (file name on local machine where the optimization 
 *       result is put, default is NULL)
 * -serviceLocation location URL (the URL  of the server that is called 
 *       remotely if the problem not solved locally, default is NULL)
 * -serviceMethod  (send, solve, kill, knock, getJobID, retrieve, 
 *       default value is solve)
 * -os (Not used for now -- ignore)
 * -osplInput xxx.ospl  (Not used for now -- ignore)
 * -osplOutput xxx.ospl (Not used for now -- ignore)
 * -mps xxxx.mps (converts mps format to osil and has same effect as -osil)
 * -nl xxxx.nl (converts nl format to osil and has same effect as -osil)
 * -solver solverName (the name of the solver to be invoked)
 * -browser path location to browser e.g. 
 *       /Applications/Firefox.app/Contents/MacOS/firefox (default is NULL)
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
optionValue ([-a-zA-Z./:_0-9]+|\"[^"\n]*["\n])
serviceMethod (solve|send|kill|retrieve|knock|getJobID)
browserState (on|off)
%% 

{xmlwhitespace}*
  

-os {
	if(yyextra->osOption == false){
		printf("Found option:  %s\n", yytext);   
		yyextra->os = true;
		yyextra->osOption = true;
	}
}

(-config{xmlwhitespace}+{optionValue}) {
	printf("Found option:  %s\n", yytext);  
	char *ch = strdup(yytext);
	// move past -config
	ch+=7;
	for(; isspace(*ch); ch++);
	yyextra->configFile = &ch[0];
	//printf("gsgersdf= %d\n", gster);
}


(-osil{xmlwhitespace}+{optionValue}) {
	if(yyextra->osilFile == NULL){
		printf("Found option:  %s\n", yytext);  
		char *ch = strdup(yytext);
		// move past -osil
		ch+=5;
		for(; isspace(*ch); ch++);
		yyextra->osilFile = &ch[0];
	} 
}

(-osrl{xmlwhitespace}+{optionValue}) {
	if(yyextra->osrlFile == NULL){
		printf("Found option:  %s\n", yytext); 
		char *ch = strdup(yytext);
		// move past -osrl
		ch+=5;
		for(; isspace(*ch); ch++);
		yyextra->osrlFile = &ch[0];
	}  
}  

(-insList{xmlwhitespace}+{optionValue}) {
	if(yyextra->insListFile == NULL){
		printf("Found option:  %s\n", yytext); 
		char *ch = strdup(yytext);
		// move past -insList
		ch+=8;
		for(; isspace(*ch); ch++);
		yyextra->insListFile = &ch[0];
	}  
}  

(-osol{xmlwhitespace}+{optionValue}) {
	if(yyextra->osolFile == NULL){
		printf("Found option:  %s\n", yytext); 
		char *ch = strdup(yytext);
		// move past -osol
		ch+=5;
		for(; isspace(*ch); ch++);
		yyextra->osolFile = &ch[0];  
	}
}



(-osplInput{xmlwhitespace}+{optionValue}) {
	if(yyextra->osplInputFile == NULL){
		printf("Found option:  %s\n", yytext); 
		char *ch = strdup(yytext);
		// move past -osplInput
		ch+=10;
		for(; isspace(*ch); ch++);
		yyextra->osplInputFile = &ch[0];  
	}
}

(-osplOutput{xmlwhitespace}+{optionValue}) {
	if(yyextra->osplOutputFile == NULL){
		printf("Found option:  %s\n", yytext); 
		char *ch = strdup(yytext);
		// move past -osplInput
		ch+=11;
		for(; isspace(*ch); ch++);
		yyextra->osplOutputFile = &ch[0];  
	}
}

(-serviceMethod{xmlwhitespace}+{serviceMethod}) {
	if(yyextra->serviceMethod == NULL){
		printf("Found option:  %s\n", yytext); 
		char *ch = strdup(yytext);
		// move past -serviceMethod
		ch+=14;
		for(; isspace(*ch); ch++);
		yyextra->serviceMethod = &ch[0]; 
	}
}

(-serviceLocation{xmlwhitespace}+{optionValue}) {
	if(yyextra->serviceLocation == NULL){
		printf("Found option:  %s\n", yytext); 
		yyextra->serviceLocation = strdup(yytext);
		char *ch = strdup(yytext);
		// move past -serviceLocation
		ch+=16;
		for(; isspace(*ch); ch++);
		yyextra->serviceLocation = &ch[0]; 
	}
}

(-mps{xmlwhitespace}+{optionValue}) {
	if(yyextra->mpsFile == NULL){
		printf("Found option:  %s\n", yytext); 
		char *ch = strdup(yytext);
		// move past -mps
		ch+=4;
		for(; isspace(*ch); ch++);
		yyextra->mpsFile = &ch[0]; 
	}
}

(-nl{xmlwhitespace}+{optionValue}) {
	if(yyextra->nlFile == NULL){
		printf("Found option:  %s\n", yytext);
		char *ch = strdup(yytext);
		// move past -nl
		ch+=3;
		for(; isspace(*ch); ch++);
		yyextra->nlFile = &ch[0];
	} 
}

(-solver{xmlwhitespace}+{optionValue}) {
	if(yyextra->solverName == NULL){
		printf("Found option:  %s\n", yytext); 
		char *ch = strdup(yytext);
		// move past -solver
		ch+=7;
		for(; isspace(*ch); ch++);
		yyextra->solverName = &ch[0];
	} 
}
 
(-browser{xmlwhitespace}+{optionValue}) {
	if(yyextra->browser == NULL){
		printf("Found option:  %s\n", yytext);  
		char *ch = strdup(yytext);
		// move past -browser
		ch+=8;
		for(; isspace(*ch); ch++);
		yyextra->browser = &ch[0]; 
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


