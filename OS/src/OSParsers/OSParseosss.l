/* $Id$ */
/** @file OSParseosss.l
 * 
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2013, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License. 
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
#include "OSCommandLine.h" 


using std::cout;
using std::endl;
using std::ostringstream;

//#define PARSERDEBUG
#ifdef PARSERDEBUG
    #define YY_PRINT  printf("Found option:  %s\n", yytext);
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


#define YY_EXTRA_TYPE class OSCommandLine* 

void setyyextra( OSCommandLine* oscommandline, void* scanner);

 /**
 * INPUTS:
 * -osil xxx.osil (file name on local machine of optimization instance, 
 *       this is "" by default, however if this remains "" a problem
 *       instance must be specified in the osol file)
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
 *       parameters
 * -insList xxx.dat (used only for LINDO, file location on local 
 *       machine of LINDO instruction list)
 * -printLevel nnn (to control the amount of output to send to stdout)
 * -logFile xxx.log (to send a second output stream to a file --- 
 *       in addition to stdout)
 * -filePrintLevel nnn (to control the amount of output to send to file)
 */


%}
%option nounput
%option reentrant
%option yylineno
%option prefix="osss"
%option noyywrap   



xmlwhitespace ([ \t\r\n])
optionValue ([-a-zA-Z./~:_0-9$\?+\\!@#&*()]+|\"[^"\n]*\")
serviceMethod (solve|send|kill|retrieve|knock|getJobID)
browserState (on|off)
%% 

{xmlwhitespace}*
  


(-config{xmlwhitespace}+{optionValue}) {
    YY_PRINT  
    //char *ch = strdup(yytext);
    char *ch = yytext;
    // move past -config
    ch+=7;
    for(; isspace(*ch); ch++);
    std::string str(  ch);
    if (str[0] == '\"')
        yyextra->configFile = str.substr(1,str.length()-2);
    else
        yyextra->configFile = str;
}

(config{xmlwhitespace}+{optionValue}) {
    YY_PRINT  
    //char *ch = strdup(yytext);
    char *ch = yytext;
    // move past -config
    ch+=6;
    for(; isspace(*ch); ch++);
    std::string str(  ch);
    if (str[0] == '\"')
        yyextra->configFile = str.substr(1,str.length()-2);
    else
        yyextra->configFile = str;
}

(--help) {
    YY_PRINT  
    yyextra->invokeHelp = true;
}
             
 (help) {
    YY_PRINT  
    yyextra->invokeHelp = true;
 }

(-h) {
    YY_PRINT
    yyextra->invokeHelp = true;
}

(-\?) {
    YY_PRINT
    yyextra->invokeHelp = true;
}

(\?) {
    YY_PRINT
    yyextra->invokeHelp = true;
}

             
(--printModel) {
    YY_PRINT  
    yyextra->printModel = true;
 }

             
 (printModel) {
    YY_PRINT  
    yyextra->printModel = true;
 }

(-printRow{xmlwhitespace}+{optionValue}) {
    //if(yyextra->printRow == ""){
        YY_PRINT 
        //yyextra->printRowNumberAsString = strdup(yytext);
        yyextra->printRowNumberAsString =  yytext;
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past -printRow
        ch+=9;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        yyextra->printRowNumberAsString = str; 
    //}
}
             
 (printRow{xmlwhitespace}+{optionValue}) {
    //if(yyextra->printRow == ""){
        YY_PRINT 
        //yyextra->printRowNumberAsString = strdup(yytext);
        yyextra->printRowNumberAsString =  yytext;
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past printRow
        ch+=8;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        yyextra->printRowNumberAsString = str; 
    //}
}
             
 (printRow{xmlwhitespace}+) {
    //if(yyextra->printRow == ""){
        YY_PRINT 
        //yyextra->printRowNumberAsString = strdup(yytext);
        yyextra->printRowNumberAsString =  yytext;
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past printRow
        ch+=8;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        yyextra->printRowNumberAsString = str; 
    //}
}


(--version) {
    YY_PRINT  
    yyextra->writeVersion = true;
}
             
 (version) {
    YY_PRINT  
    yyextra->writeVersion = true;
}

(-v) {
    YY_PRINT 
    yyextra->writeVersion = true;
}
             
             
(quit) {
   YY_PRINT  
   yyextra->quit = true;
}

(exit) {
   YY_PRINT  
   yyextra->quit = true;
}


(-osil{xmlwhitespace}+{optionValue}) {
    //if(yyextra->osilFile == ""){
        YY_PRINT  
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past -osil
        ch+=5;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        if (str[0] == '\"')
            yyextra->osilFile = str.substr(1,str.length()-2);
        else
            yyextra->osilFile = str;
    //} 
}
             
 (osil{xmlwhitespace}+{optionValue}) {
    // if(yyextra->osilFile == ""){
        YY_PRINT  
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past osil
        ch+=4;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        if (str[0] == '\"')
            yyextra->osilFile = str.substr(1,str.length()-2);
        else
            yyextra->osilFile = str;
    // } 
 }
     
(-osilOutput{xmlwhitespace}+{optionValue}) {
        YY_PRINT 
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past -osilOutput
        ch+=11;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        yyextra->osilOutputFile = str;  
}

 (osilOutput{xmlwhitespace}+{optionValue}) {
         YY_PRINT 
         //char *ch = strdup(yytext);
         char *ch = yytext;
         // move past osilOutput
         ch+=10;
         for(; isspace(*ch); ch++);
         std::string str(  ch);
         yyextra->osilOutputFile = str;  
}
             
 (osilOutput{xmlwhitespace}+) {
         YY_PRINT 
         //char *ch = strdup(yytext);
         char *ch = yytext;
         // move past osilOutput
         ch+=10;
         for(; isspace(*ch); ch++);
         std::string str(  ch);
         yyextra->osilOutputFile = str;  
}
             
(-osol{xmlwhitespace}+{optionValue}) {
    //if(yyextra->osolFile == ""){
        YY_PRINT 
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past -osol
        ch+=5;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        if (str[0] == '\"')
            yyextra->osolFile = str.substr(1,str.length()-2);
        else
            yyextra->osolFile = str;
    //}
}
             
(osol{xmlwhitespace}+{optionValue}) {
    //if(yyextra->osolFile == ""){
        YY_PRINT 
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past osol
        ch+=4;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        if (str[0] == '\"')
            yyextra->osolFile = str.substr(1,str.length()-2);
        else
            yyextra->osolFile = str;
    //}
}
  
(-osolOutput{xmlwhitespace}+{optionValue}) {
        YY_PRINT 
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past -osolOutput
        ch+=11;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        if (str[0] == '\"')
            yyextra->osolOutputFile = str.substr(1,str.length()-2);
        else
            yyextra->osolOutputFile = str;
}

 (osolOutput{xmlwhitespace}+{optionValue}) {
        YY_PRINT 
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past osolOutput
        ch+=10;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        if (str[0] == '\"')
            yyextra->osolOutputFile = str.substr(1,str.length()-2);
        else
            yyextra->osolOutputFile = str;
}

 (osolOutput{xmlwhitespace}+) {
         YY_PRINT 
         //char *ch = strdup(yytext);
         char *ch = yytext;
         // move past osolOutput
         ch+=10;
         for(; isspace(*ch); ch++);
         std::string str(  ch);
         yyextra->osolOutputFile = str;  
}

(-osplInput{xmlwhitespace}+{optionValue}) {
    //if(yyextra->osplInputFile == ""){
        YY_PRINT 
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past -osplInput
        ch+=10;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        if (str[0] == '\"')
            yyextra->osplInputFile = str.substr(1,str.length()-2);
        else
            yyextra->osplInputFile = str;
    //}
}
             
 (osplInput{xmlwhitespace}+{optionValue}) {
        YY_PRINT 
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past osplInput
        ch+=9;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        if (str[0] == '\"')
            yyextra->osplInputFile = str.substr(1,str.length()-2);
        else
            yyextra->osplInputFile = str;
}
  
(-osplOutput{xmlwhitespace}+{optionValue}) {
        YY_PRINT 
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past -osplOutput
        ch+=11;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        if (str[0] == '\"')
            yyextra->osplOutputFile = str.substr(1,str.length()-2);
        else
            yyextra->osplOutputFile = str;
}

 (osplOutput{xmlwhitespace}+{optionValue}) {
        YY_PRINT 
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past osplOutput
        ch+=10;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        if (str[0] == '\"')
            yyextra->osplOutputFile = str.substr(1,str.length()-2);
        else
            yyextra->osplOutputFile = str;
}

(-osrl{xmlwhitespace}+{optionValue}) {
    //if(yyextra->osrlFile == ""){
        YY_PRINT 
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past -osrl
        ch+=5;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        if (str[0] == '\"')
            yyextra->osrlFile = str.substr(1,str.length()-2);
        else
            yyextra->osrlFile = str;
    //}  
}  
             
 (osrl{xmlwhitespace}+{optionValue}) {
     //if(yyextra->osrlFile == ""){
        YY_PRINT 
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past osrl
        ch+=4;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        if (str[0] == '\"')
            yyextra->osrlFile = str.substr(1,str.length()-2);
        else
            yyextra->osrlFile = str;
     //}  
 }              
             
(-insList{xmlwhitespace}+{optionValue}) {
        YY_PRINT
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past -insList
        ch+=8;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        if (str[0] == '\"')
            yyextra->insListFile = str.substr(1,str.length()-2);
        else
            yyextra->insListFile = str;
}  
             
 (insList{xmlwhitespace}+{optionValue}) {
        YY_PRINT
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past insList
        ch+=7;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        yyextra->insListFile = str;
        if (str[0] == '\"')
            yyextra->insListFile = str.substr(1,str.length()-2);
        else
            yyextra->insListFile = str;
 }
             
(-mps{xmlwhitespace}+{optionValue}) {
        YY_PRINT 
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past -mps
        ch+=4;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        if (str[0] == '\"')
            yyextra->mpsFile = str.substr(1,str.length()-2);
        else
            yyextra->mpsFile = str;
}
             
 (mps{xmlwhitespace}+{optionValue}) {
        YY_PRINT 
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past mps
        ch+=3;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        if (str[0] == '\"')
            yyextra->mpsFile = str.substr(1,str.length()-2);
        else
            yyextra->mpsFile = str;
}
             
(-nl{xmlwhitespace}+{optionValue}) {
        YY_PRINT
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past -nl
        ch+=3;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        if (str[0] == '\"')
            yyextra->nlFile = str.substr(1,str.length()-2);
        else
            yyextra->nlFile = str;
}
             
 (nl{xmlwhitespace}+{optionValue}) {
        YY_PRINT
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past nl
        ch+=2;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        if (str[0] == '\"')
            yyextra->nlFile = str.substr(1,str.length()-2);
        else
            yyextra->nlFile = str;
}
             
(-dat{xmlwhitespace}+{optionValue}) {
        YY_PRINT
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past -dat
        ch+=4;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        if (str[0] == '\"')
            yyextra->gamsControlFile = str.substr(1,str.length()-2);
        else
            yyextra->gamsControlFile = str;
}
             
 (dat{xmlwhitespace}+{optionValue}) {
        YY_PRINT
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past dat
        ch+=3;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        if (str[0] == '\"')
            yyextra->gamsControlFile = str.substr(1,str.length()-2);
        else
            yyextra->gamsControlFile = str;
}
             
(-serviceMethod{xmlwhitespace}+{serviceMethod}) {
        YY_PRINT
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past -serviceMethod
        ch+=14;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        if (str[0] == '\"')
            yyextra->serviceMethod = str.substr(1,str.length()-2);
        else
            yyextra->serviceMethod = str;
}
             
 (serviceMethod{xmlwhitespace}+{serviceMethod}) {
        YY_PRINT
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past serviceMethod
        ch+=13;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        yyextra->serviceMethod = str; 
        if (str[0] == '\"')
            yyextra->serviceMethod = str.substr(1,str.length()-2);
        else
            yyextra->serviceMethod = str;
}

(-serviceLocation{xmlwhitespace}+{optionValue}) {
        YY_PRINT 
        //yyextra->serviceLocation = strdup(yytext);
        yyextra->serviceLocation =  yytext;
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past -serviceLocation
        ch+=16;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        if (str[0] == '\"')
            yyextra->serviceLocation = str.substr(1,str.length()-2);
        else
            yyextra->serviceLocation = str;
}
             
 (serviceLocation{xmlwhitespace}+{optionValue}) {
        YY_PRINT 
        //yyextra->serviceLocation = strdup(yytext);
        yyextra->serviceLocation =  yytext;
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past serviceLocation
        ch+=15;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        if (str[0] == '\"')
            yyextra->serviceLocation = str.substr(1,str.length()-2);
        else
            yyextra->serviceLocation = str;
}

(-solver{xmlwhitespace}+{optionValue}) {
        YY_PRINT 
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past -solver
        ch+=7;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        if (str[0] == '\"')
            yyextra->solverName = str.substr(1,str.length()-2);
        else
            yyextra->solverName = str;
}
             
 (solver{xmlwhitespace}+{optionValue}) {
        YY_PRINT 
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past solver
        ch+=6;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        if (str[0] == '\"')
            yyextra->solverName = str.substr(1,str.length()-2);
        else
            yyextra->solverName = str;
}

(-browser{xmlwhitespace}+{optionValue}) {
        YY_PRINT  
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past -browser
        ch+=8;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        if (str[0] == '\"')
            yyextra->browser = str.substr(1,str.length()-2);
        else
            yyextra->browser = str;
}
             
 (browser{xmlwhitespace}+{optionValue}) {
        YY_PRINT  
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past browser
        ch+=7;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        if (str[0] == '\"')
            yyextra->browser = str.substr(1,str.length()-2);
        else
            yyextra->browser = str;
}

 (-printLevel{xmlwhitespace}+{optionValue}) {
        YY_PRINT  
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past browser
        ch+=11;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        std::string temp;
        if (str[0] == '\"')
            temp = str.substr(1,str.length()-2);
        else
            temp = str;
        yyextra->printLevel = atoi(temp.c_str());
}

 (printLevel{xmlwhitespace}+{optionValue}) {
        YY_PRINT  
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past browser
        ch+=10;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        std::string temp;
        if (str[0] == '\"')
            temp = str.substr(1,str.length()-2);
        else
            temp = str;
        yyextra->printLevel = atoi(temp.c_str());
}
          
 (-logFile{xmlwhitespace}+{optionValue}) {
        YY_PRINT  
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past browser
        ch+=8;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        if (str[0] == '\"')
            yyextra->logFile = str.substr(1,str.length()-2);
        else
            yyextra->logFile = str;
}
             
 (logFile{xmlwhitespace}+{optionValue}) {
        YY_PRINT  
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past browser
        ch+=7;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        if (str[0] == '\"')
            yyextra->logFile = str.substr(1,str.length()-2);
        else
            yyextra->logFile = str;
}

 (-filePrintLevel{xmlwhitespace}+{optionValue}) {
        YY_PRINT  
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past browser
        ch+=15;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        std::string temp;
        if (str[0] == '\"')
            temp = str.substr(1,str.length()-2);
        else
            temp = str;
        yyextra->filePrintLevel = atoi(temp.c_str());
}

 (filePrintLevel{xmlwhitespace}+{optionValue}) {
        YY_PRINT  
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past browser
        ch+=14;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        std::string temp;
        if (str[0] == '\"')
            temp = str.substr(1,str.length()-2);
        else
            temp = str;
        yyextra->filePrintLevel = atoi(temp.c_str());
}

(-jobID{xmlwhitespace}+{optionValue}) {
        YY_PRINT  
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past -browser
        ch+=6;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        yyextra->jobID = str;
}

(jobID{xmlwhitespace}+{optionValue}) {
        YY_PRINT  
        //char *ch = strdup(yytext);
        char *ch = yytext;
        // move past -browser
        ch+=5;
        for(; isspace(*ch); ch++);
        std::string str(  ch);
        yyextra->jobID = str;
}

. {
    std::string error;
    std::ostringstream outStr;
    outStr << "encountered a spurious character in the lexer" << endl;
    outStr << "Please make sure your options are spelled correctly" << endl;
    outStr << "Type OSSolverService -h or OSSolverService --help for valid commands" << endl;
    outStr << "The first character is: ";
    outStr <<  yytext;
    outStr << endl;
    //outStr << "See line number: " << yylineno << endl;  
    error = outStr.str();
    throw ErrorClass( error);  
}
%%

void setyyextra(OSCommandLine *oscommandline, void* scanner){
	osssset_extra(oscommandline, scanner);
}
