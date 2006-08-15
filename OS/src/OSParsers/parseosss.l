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

#include <stdio.h> 
#include "lexyaccparser.h"
#include "externalvars.h"
#include "ErrorClass.h"
#include <iostream>
#include <sstream>   
#include "osssparservariables.h"  

bool osOption;  

#ifdef PARSERDEBUG
	#define YY_PRINT  printf("%s", ossstext);
#else     
	#define YY_PRINT  ;
#endif
#ifdef WIN_SOCK
#define YY_NO_UNISTD_H
#endif

/*
 * INPUTS:
 * -osil xxx.osil (File must be on local machine -- yes)
 * -osol xxx.osol (File must be on local machine -- yes)
 * -osrl xxx.osrl (File must be on local machine -- yes)
 * -insList xxx.dat (File must be on local machine -- yes)
 * -serviceLocation location URL (NOT USED ON SERVER???? -- only on client)
 * -serviceMethod  (send, solve, kill, knock, getJobID, retrieve) (if not specified solve by default)
 * -os (This requires a registry, we are just using optimization services, location is not needed)
 * -osplInput xxx.ospl  (Probably used only by client)
 * -osplOutput xxx.ospl ( location of where it goes, like OSrL)
 * -mps xxxx.mps (only used by local client, converts mps format to osil and has same effect as -osil)
 * -nl xxxx.nl (only used by local client, converts nl format to osil and has same effect as -osil)
 * -solver solver_name (this is also going to be in osol)
 * -browser on/off (default is off)
*/
	osOptionsStruc *osoptions;

%}
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
	if(osOption == false){
		printf("Found option:  %s\n", ossstext);   
		osoptions->os = true;
		osOption = true;
	}
}

(-config{xmlwhitespace}+{optionValue}) {
	printf("Found option:  %s\n", ossstext);  
	char *ch = strdup(ossstext);
	// move past -config
	ch+=7;
	for(; isspace(*ch); ch++);
	osoptions->configFile = &ch[0];
}


(-osil{xmlwhitespace}+{optionValue}) {
	if(osoptions->osilFile == NULL){
		printf("Found option:  %s\n", ossstext);  
		char *ch = strdup(ossstext);
		// move past -osil
		ch+=5;
		for(; isspace(*ch); ch++);
		osoptions->osilFile = &ch[0];
	} 
}

(-osrl{xmlwhitespace}+{optionValue}) {
	if(osoptions->osrlFile == NULL){
		printf("Found option:  %s\n", ossstext); 
		char *ch = strdup(ossstext);
		// move past -osrl
		ch+=5;
		for(; isspace(*ch); ch++);
		osoptions->osrlFile = &ch[0];
	}  
}  

(-insList{xmlwhitespace}+{optionValue}) {
	if(osoptions->insListFile == NULL){
		printf("Found option:  %s\n", ossstext); 
		char *ch = strdup(ossstext);
		// move past -insList
		ch+=8;
		for(; isspace(*ch); ch++);
		osoptions->insListFile = &ch[0];
	}  
}  

(-osol{xmlwhitespace}+{optionValue}) {
	if(osoptions->osolFile == NULL){
		printf("Found option:  %s\n", ossstext); 
		char *ch = strdup(ossstext);
		// move past -osol
		ch+=5;
		for(; isspace(*ch); ch++);
		osoptions->osolFile = &ch[0];  
	}
}



(-osplInput{xmlwhitespace}+{optionValue}) {
	if(osoptions->osplInputFile == NULL){
		printf("Found option:  %s\n", ossstext); 
		char *ch = strdup(ossstext);
		// move past -osplInput
		ch+=10;
		for(; isspace(*ch); ch++);
		osoptions->osplInputFile = &ch[0];  
	}
}

(-osplOutput{xmlwhitespace}+{optionValue}) {
	if(osoptions->osplOutputFile == NULL){
		printf("Found option:  %s\n", ossstext); 
		char *ch = strdup(ossstext);
		// move past -osplInput
		ch+=11;
		for(; isspace(*ch); ch++);
		osoptions->osplOutputFile = &ch[0];  
	}
}

(-serviceMethod{xmlwhitespace}+{serviceMethod}) {
	if(osoptions->serviceMethod == NULL){
		printf("Found option:  %s\n", ossstext); 
		char *ch = strdup(ossstext);
		// move past -serviceMethod
		ch+=14;
		for(; isspace(*ch); ch++);
		osoptions->serviceMethod = &ch[0]; 
	}
}

(-serviceLocation{xmlwhitespace}+{optionValue}) {
	if(osoptions->serviceLocation == NULL){
		printf("Found option:  %s\n", ossstext); 
		osoptions->serviceLocation = strdup(ossstext);
		char *ch = strdup(ossstext);
		// move past -serviceLocation
		ch+=16;
		for(; isspace(*ch); ch++);
		osoptions->serviceLocation = &ch[0]; 
	}
}

(-mps{xmlwhitespace}+{optionValue}) {
	if(osoptions->mpsFile == NULL){
		printf("Found option:  %s\n", ossstext); 
		char *ch = strdup(ossstext);
		// move past -mpsFile
		ch+=8;
		for(; isspace(*ch); ch++);
		osoptions->mpsFile = &ch[0]; 
	}
}

(-nl{xmlwhitespace}+{optionValue}) {
	if(osoptions->nlFile == NULL){
		printf("Found option:  %s\n", ossstext);
		char *ch = strdup(ossstext);
		// move past -nlFile
		ch+=7;
		for(; isspace(*ch); ch++);
		osoptions->nlFile = &ch[0];
	} 
}

(-solver{xmlwhitespace}+{optionValue}) {
	if(osoptions->solverName == NULL){
		printf("Found option:  %s\n", ossstext); 
		char *ch = strdup(ossstext);
		// move past -solver
		ch+=7;
		for(; isspace(*ch); ch++);
		osoptions->solverName = &ch[0];
	} 
}

(-browser{xmlwhitespace}+{browserState}) {
	if(osoptions->browser == NULL){
		printf("Found option:  %s\n", ossstext);  
		char *ch = strdup(ossstext);
		// move past -browser
		ch+=8;
		for(; isspace(*ch); ch++);
		osoptions->browser = &ch[0]; 
	}
}

. {ossserror( "ecountered a spurious character in the lexer");   }
%%

void ossserror(char* errormsg)
{
	try{
		ostringstream outStr;
		std::string error = errormsg;
		error = "Input is either not valid or well formed: "  + error;
		outStr << error << endl;
		outStr << "Here is the last token read: " << ossstext << endl;
		outStr << "See line number: " << ossslineno << endl;
		error = outStr.str();
		throw ErrorClass( error);
		throw error;
	}
		catch(const ErrorClass& eclass){
		throw ErrorClass(  eclass.errormsg);
	}
} // end ossserror
