/** @file OSSolverService.cpp
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

#include <string> 
#include <OsiSolverInterface.hpp>
#include <OsiClpSolverInterface.hpp> 
#include <CoinMessageHandler.hpp>
#include "OSConfig.h" 

   
 
#ifdef COIN_HAS_LINDO
#include "LindoSolver.h" 
#endif 

  
  
#include "FileUtil.h" 
#include "CoinSolver.h"
#include "WSUtil.h" 
#include "OSSolverAgent.h"
#include "OShL.h" 
#include "lexyaccparser.h"  
#include "ErrorClass.h"
#include "osssparservariables.h" 
#include <string>
    

#define MAXCHARS 5000 
 
// the serviceMethods  
void solve();  
void getJobID(); 
void send();
void kill();
void retrieve(); 
void knock();

int main(int argC, const char* argV[])
{   
	FileUtil *fileUtil = NULL;
	char osss[MAXCHARS] = " ";
	const char *space = " "; 
	char *config = "-config";
	char *configFileName = NULL;
	int i, k;
	osOption = false;
	// initialize the OS options structure
	osoptions = new osOptionsStruc();
	osoptions->configFile = NULL; 
	osoptions->osilFile = NULL; 
	osoptions->osil = NULL; 
	osoptions->osolFile = NULL; 
	osoptions->osol = NULL; 
	osoptions->osrlFile = NULL; 
	osoptions->osrl = NULL; 
	osoptions->insListFile = NULL; 
	osoptions->insList = NULL; 
	osoptions->serviceLocation = NULL; 
	osoptions->serviceMethod = NULL; 
	osoptions->osplInputFile = NULL; 
	osoptions->osplOutputFile = NULL; 
	osoptions->mpsFile = NULL; 
	osoptions->nlFile = NULL; 
	osoptions->solverName = NULL; 
	osoptions->os = false; 
	osoptions->browser = NULL; 
	try{
		if(argC < 2) throw ErrorClass( "there must be at least one command line argument");
		// see if the first argument is a file name
		i = 1;
		while(i < argC) {
			if(strlen(osss) + strlen(argV[ i]) + 1 > MAXCHARS) throw ErrorClass( "the command line has too many arguments");
			strcat(osss, argV[ i]);
			strcat(osss, space);
			i++;
		}
		cout << "Input String = "  << osss << endl;
		osss_scan_string( osss); 
		ossslex();
		// if there is a config file, get those options
		if(osoptions->configFile != NULL){
			configFileName = osoptions->configFile;
			cout << "configFileName = " << configFileName << endl;
			std::string osolfileOptions = fileUtil->getFileAsString( configFileName);
			osss_scan_string( &osolfileOptions[0]);
			ossslex();		
		}
	}
		catch(const ErrorClass& eclass){
		cout << eclass.errormsg <<  endl;
		return 0;
	} 
		cout << "HERE ARE THE OPTION VALUES:" << endl;
		if(osoptions->configFile != NULL) cout << "Config file = " << osoptions->configFile << endl;
		if(osoptions->osilFile != NULL) cout << "OSiL file = " << osoptions->osilFile << endl;
		if(osoptions->osolFile != NULL) cout << "OSoL file = " << osoptions->osolFile << endl;
		if(osoptions->osrlFile != NULL) cout << "OSrL file = " << osoptions->osrlFile << endl;
		if(osoptions->insListFile != NULL) cout << "Instruction List file = " << osoptions->insListFile << endl;
		if(osoptions->osplInputFile != NULL) cout << "OSpL Input file = " << osoptions->osplInputFile << endl;
		if(osoptions->serviceLocation != NULL) cout << "Service Location = " << osoptions->serviceLocation << endl;
		if(osoptions->serviceMethod != NULL) cout << "Service Method = " << osoptions->serviceMethod << endl;
		if(osoptions->mpsFile != NULL) cout << "MPS File Name = " << osoptions->mpsFile << endl;
		if(osoptions->nlFile != NULL) cout << "NL File Name = " << osoptions->nlFile << endl;
		if(osoptions->solverName != NULL) cout << "Solver Name = " << osoptions->solverName << endl;
		if(osoptions->browser != NULL) cout << "Browser Value = " << osoptions->browser << endl;
		if( osoptions->os == true ) cout << "OS = " << osoptions->os << endl;
		// get the data from the files
		fileUtil = new FileUtil();
		try{	
			if(osoptions->osilFile != NULL) osoptions->osil = fileUtil->getFileAsChar( &osoptions->osilFile[0]);
			if(osoptions->insListFile != NULL) osoptions->insList = fileUtil->getFileAsChar( &osoptions->insListFile[0]);
			if(osoptions->osolFile != NULL) osoptions->osol = fileUtil->getFileAsChar( &osoptions->osolFile[0]);
			if(osoptions->osplInputFile != NULL) osoptions->osplInput = fileUtil->getFileAsChar( &osoptions->osplInputFile[0]);
			if(osoptions->osplOutputFile != NULL) osoptions->osplOutput = fileUtil->getFileAsChar( &osoptions->osplOutputFile[0]);
		}
		catch(const ErrorClass& eclass){
			//cout << eclass.errormsg <<  endl;
			cout << "could not open file properly" << endl;
			return 0;
		}	
		// now call the correct serviceMethod
		// solve is the default
		if( osoptions->serviceMethod == NULL) solve();
		else{
			switch(osoptions->serviceMethod[ 0]){
				case 'g':
					getJobID();
					break;
				case 'r':
					retrieve();
					break;
				case 's':
					if( osoptions->serviceMethod[ 1] == 'e') send();
					else solve();
					break;
				case 'k':
					if(osoptions->serviceMethod[ 1] == 'i') kill();
					else knock();
					break;
				default:
					break;
			}
		}
	return 0;
}

void solve(){
	OSSolverAgent* osagent = NULL;
	DefaultSolver *solverType  = NULL;
	FileUtil *fileUtil = NULL;
	fileUtil = new FileUtil();
	try{
		// solve either remotely of locally
		if(osoptions->serviceLocation != NULL){
			// place a remote call
			osagent = new OSSolverAgent( osoptions->serviceLocation );
			if(osoptions->osrlFile != NULL) fileUtil->writeFileFromString(osoptions->osrlFile, osagent->solve(osoptions->osil  , osoptions->osol));
			else cout << osagent->solve(osoptions->osil, osoptions->osol) << endl;
		}
		else{
			// solve locally
			if(osoptions->solverName == NULL ) throw ErrorClass( "a local solver was not specified");
			if( strstr(osoptions->solverName, "lindo") != NULL) {
				// we are requesting the Lindo solver
				bool bLindoIsPresent = false;
				#ifdef COIN_HAS_LINDO
				bLindoIsPresent = true;
				solverType = new LindoSolver();
				#endif
				if(bLindoIsPresent == false) throw ErrorClass( "the Lindo solver requested is not present");
			}
			else{ 
				if( strstr(osoptions->solverName, "clp") != NULL){
					solverType = new CoinSolver();
					solverType->m_sSolverName = "clp";
				}
				else{
					if( strstr(osoptions->solverName, "cbc") != NULL){
						solverType = new CoinSolver();
						solverType->m_sSolverName = "cbc";
					}
					else{
						if( strstr(osoptions->solverName, "cplex") != NULL){
							solverType = new CoinSolver();
							solverType->m_sSolverName = "cplex";
						}
						else{
							if( strstr(osoptions->solverName, "glpk") != NULL){
								solverType = new CoinSolver();
								solverType->m_sSolverName = "glpk";
							}
							else{
								throw ErrorClass( "a supported solver is not present");;
							}
						}
					}
				}
			}
			solverType->osil = osoptions->osil;
			solverType->osol = osoptions->osol;
			solverType->osinstance = NULL;
			cout << "CALL SOLVER" << endl;
			solverType->solve();
			cout << "RETURN FROM SOLVER" << endl;
			if(osoptions->osrlFile != NULL) fileUtil->writeFileFromString(osoptions->osrlFile, solverType->osrl);
			else cout << solverType->osrl << endl;
		}
	}
	catch(const ErrorClass& eclass){
		cout << eclass.errormsg <<  endl;
		solverType->osrl = eclass.errormsg;
		if(osoptions->osrlFile != NULL) fileUtil->writeFileFromString(osoptions->osrlFile, solverType->osrl);
	}	
}//end solve

void getJobID(){
	OSSolverAgent* osagent = NULL;
	try{
		osagent = new OSSolverAgent( osoptions->serviceLocation );
		cout << osagent->getJobID( osoptions->osol) << endl;
	}
	catch(const ErrorClass& eclass){
		cout << eclass.errormsg <<  endl;
	}	
}//end getJobID
 

void knock(){
	OSSolverAgent* osagent = NULL;
	FileUtil *fileUtil = NULL;
	fileUtil = new FileUtil();
	try{
		osagent = new OSSolverAgent( osoptions->serviceLocation );
		if(osoptions->osplOutputFile != NULL) fileUtil->writeFileFromString(osoptions->osplOutputFile, osagent->knock(osoptions->osplInput,  osoptions->osol));
		else cout << osagent->knock(osoptions->osplInput,  osoptions->osol) << endl;
	}
	catch(const ErrorClass& eclass){
		cout << eclass.errormsg <<  endl;
	}	
}//end knock


void send(){
	OSSolverAgent* osagent = NULL;
	// first get the jobID
	std::string sjobID = "";
	std::string sOSoL = "<?xml version=\"1.0\" encoding=\"UTF-8\"?> <osol xmlns=\"os.optimizationservices.org\" xmlns:xs=\"http://www.w3.org/2001/XMLSchema\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:schemaLocation=\"os.optimizationservices.org http://www.optimizationservices.org/schemas/OSoL.xsd\"><general> </general></osol>";
	int istringpos;
	bool bsend;
	try{
		osagent = new OSSolverAgent( osoptions->serviceLocation );
		sjobID =  osagent->getJobID( osoptions->osol) ;
		// check to see if there is an osol 
		if(osoptions->osolFile == NULL){
			// insert the jobID into the default osol
			istringpos = sOSoL.find("</general");
			cout << "startel ==  " << istringpos << endl;
			if(istringpos != std::string::npos) sOSoL.insert(istringpos, "<jobID>" + sjobID+ "</jobID>");
			cout << sOSoL << endl;
			if(osagent->send(osoptions->osil, sOSoL) == true) cout << "send is true" << endl;
			else cout << "send is false" << endl;
		}
		else{
			// see if a jobID is present in the OSiL
			sOSoL = osoptions->osol;
			istringpos = sOSoL.find("<jobID");
			if(istringpos != std::string::npos) bsend = osagent->send(osoptions->osil, osoptions->osol);
			else{
				istringpos = sOSoL.find("</general");
				if(istringpos != std::string::npos) sOSoL.insert(istringpos, "<jobID>" + sjobID+ "</jobID>");
				cout << sOSoL << endl;
				if(osagent->send(osoptions->osil, sOSoL) == true) cout << "send is true" << endl;
				else cout << "send is false" << endl;
				//cout << osagent->solve(osoptions->osil, sOSoL) << endl;
			}
		}
	}
	catch(const ErrorClass& eclass){
		cout << eclass.errormsg <<  endl;
	}	
}//end send

void retrieve(){
	OSSolverAgent* osagent = NULL;
	FileUtil *fileUtil = NULL;
	fileUtil = new FileUtil();
	osagent = new OSSolverAgent( osoptions->serviceLocation );
	std::string sOSrL = osagent->retrieve( osoptions->osol);
	if(osoptions->osrlFile != NULL) fileUtil->writeFileFromString(osoptions->osrlFile, sOSrL);
	else cout << sOSrL << endl;
}//end retrieve

void kill(){
	OSSolverAgent* osagent = NULL;
	FileUtil *fileUtil = NULL;
	fileUtil = new FileUtil();
	osagent = new OSSolverAgent( osoptions->serviceLocation );
	std::string sOSpL = osagent->kill( osoptions->osol);
	if(osoptions->osplOutputFile != NULL) fileUtil->writeFileFromString(osoptions->osplOutputFile, sOSpL);
	else cout << sOSpL << endl;
}//end kill

/*
 * INPUTS:
 * -osil xxx.osil (File must be on local machine -- yes)
 * -osol xxx.osol (File must be on local machine -- yes)
 * -osrl xxx.osrl (File must be on local machine -- yes)
 * -insList xxx.dat (File must be on local machine -- yes) -- the LINDO postfix instruction list
 * -serviceLocation location URL (NOT USED ON SERVER???? -- only on client)
 * -serviceMethod  (send, solve, kill, knock, getJobID, retrieve) (if not specified solve by default)
 * -os (This requires a registry, we are just using optimization services, location is not needed)
 * -osplInput xxx.ospl  (Probably used only by client)
 * -osplOutput xxx.ospl ( location of where it goes, like OSrL)
 * -mps xxxx.mps (only used by local client, converts mps format to osil and has same effect as -osil)
 * -nl xxxx.nl (only used by local client, converts nl format to osil and has same effect as -osil)
 * -solver solverName (this is also going to be in osol)
 * -browser on/off (default is off)
*/

/*

1. Ugh -- must be able to parse osol

2. Which parameters is the scheduler going to send??? Only the first three? 

3. Let's specify the options allowed AND their valid values

4. What about kill, retrieve, knock, getJobID -- how do they get specified? Through the service method

5. What does -OS do?

6. Which of the above are done on the local machine, which on the remote?

7. Assumption: if the client want to specify a remote instance, must this be done through osol? I think so.

8. Should client be able to invoke browser on local machine (perhaps browser name and path could be in osol) and then send it the osrl with an xslt specificiation???

9. Should we allow an additional option which is:

-config xxx.config

This config specifies all of the options. It could be overwritten by explicitly naming the other options, e.g.

OsSolverService -config myconfigs.config -osil test.osil

Possibly use XML

<OSParameter>
	<param name="" description="">value</param>
</OSParameter>

10. List the default values

11. Should we use -- as a flag so we can have - in file names
*/

