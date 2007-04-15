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

#ifdef COIN_HAS_IPOPT     
#include "IpoptSolver.h"
#endif   
  
#include "FileUtil.h"  
#include "CoinSolver.h"
#include "WSUtil.h" 
#include "OSSolverAgent.h"
#include "OShL.h"  
#include "ErrorClass.h"
#include "osOptionsStruc.h" 
#include <string>
    

#define MAXCHARS 5000 

typedef struct yy_buffer_state *YY_BUFFER_STATE;
YY_BUFFER_STATE osss_scan_string(const char* osss, void* scanner ); 
//void osssset_extra (YY_EXTRA_TYPE user_defined ,yyscan_t yyscanner );
void setyyextra(osOptionsStruc *osoptions, void* scanner);
int ossslex(void* scanner );
int ossslex_init(void** ptr);
 
// the serviceMethods  
void solve();  
void getJobID(); 
void send();
void kill();
void retrieve(); 
void knock();

//options structure
// this is the only global variable but 
// this is not a problem since this is a main routine
osOptionsStruc *osoptions;




using std::cout;
using std::endl;
using std::ostringstream;

int main(int argC, const char* argV[])
{   
	
	void* scanner;
	FileUtil *fileUtil = NULL;
	char osss[MAXCHARS] = " ";
	const char *space = " "; 
	char *config = "-config";
	char *configFileName = NULL;
	int i, k;

	// initialize the OS options structure

	osoptions = new osOptionsStruc();
	osoptions->configFile = NULL; 
	osoptions->osilFile = NULL; 
	osoptions->osil = ""; 
	osoptions->osolFile = NULL; 
	osoptions->osol = ""; 
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
	osoptions->osOption = false;
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
		ossslex_init( &scanner);
		std::cout << "Call Text Extra" << std::endl;
		setyyextra( osoptions, scanner);
		std::cout << "Call scan string " << std::endl;
		osss_scan_string( osss, scanner); 
		std::cout << "call ossslex" << std::endl;
		ossslex( scanner);
		std::cout << "done with call to ossslex" << std::endl;
		// if there is a config file, get those options
		if(osoptions->configFile != NULL){
			configFileName = osoptions->configFile;
			cout << "configFileName = " << configFileName << endl;
			std::string osolfileOptions = fileUtil->getFileAsString( configFileName);
			ossslex_init( &scanner);
			std::cout << "Call Text Extra" << std::endl;
			setyyextra( osoptions, scanner);
			std::cout << "Done with call Text Extra" << std::endl;
			osss_scan_string( &osolfileOptions[0], scanner);
			ossslex(scanner );		
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
	std::string osrl = "";
	OSSolverAgent* osagent = NULL;
	DefaultSolver *solverType  = NULL;
	FileUtil *fileUtil = NULL;
	fileUtil = new FileUtil();
	try{
		// solve either remotely of locally
		if(osoptions->serviceLocation != NULL){
			// place a remote cal
			osagent = new OSSolverAgent( osoptions->serviceLocation );
			osrl = osagent->solve(osoptions->osil  , osoptions->osol);
			if(osoptions->osrlFile != NULL) fileUtil->writeFileFromString(osoptions->osrlFile, osrl);
			else cout << osrl << endl;
		}
		else{
			// solve locally
			// add IPOPT
			if(osoptions->solverName == NULL ) throw ErrorClass( "a local solver was not specified");
			if( strstr(osoptions->solverName, "ipopt") != NULL) {
				// we are requesting the Ipopt solver
				bool bIpoptIsPresent = false;
				#ifdef COIN_HAS_IPOPT
				bIpoptIsPresent = true;
				SmartPtr<IpoptSolver> ipoptSolver  = new IpoptSolver();	
				ipoptSolver->osol = osoptions->osol;
				ipoptSolver->osil = osoptions->osil;
				ipoptSolver->osinstance = NULL;
				ipoptSolver->solve();
				osrl = ipoptSolver->osrl ;
				#endif
				if(bIpoptIsPresent == false) throw ErrorClass( "the Ipopt solver requested is not present");
			}
			else{
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
									throw ErrorClass( "a supported solver is not present");
								}
							}
						}
					}
				}
			}
			if( strstr(osoptions->solverName, "ipopt") == NULL){
				solverType->osil = osoptions->osil;
				solverType->osol = osoptions->osol;
				solverType->osinstance = NULL;
				cout << "CALL SOLVER" << endl;
				solverType->solve();
				osrl = solverType->osrl;
				cout << "RETURN FROM SOLVER" << endl;
			}
			if(osoptions->osrlFile != NULL){
				fileUtil->writeFileFromString(osoptions->osrlFile, osrl);
				//const char *ch1 = "/Applications/Firefox.app/Contents/MacOS/firefox  ";
				if(osoptions->browser != NULL){
					const char *ch1 = osoptions->browser;
					char *ch2;
	      			ch2 = new char[strlen( ch1) + strlen(osoptions->osrlFile) + 2];
	      			ch2 = strcpy(ch2, ch1);	
	      			char const *ch3  = " ";
	      			ch2 = strcat(ch2, ch3);
	      			ch2 = strcat(ch2, osoptions->osrlFile);
					std::system(ch2  );
				}
			}
			else cout << osrl << endl;
		}
	}
	catch(const ErrorClass& eclass){
		std::cout <<  eclass.errormsg << std::endl;
		if(osoptions->osrlFile != NULL) fileUtil->writeFileFromString(osoptions->osrlFile,  eclass.errormsg);
	}	
}//end solve

void getJobID(){
	std::string jobID = "";
	OSSolverAgent* osagent = NULL;
	FileUtil *fileUtil = NULL;
	fileUtil = new FileUtil();
	try{
		if(osoptions->serviceLocation != NULL){
			osagent = new OSSolverAgent( osoptions->serviceLocation );
			jobID = osagent->getJobID( osoptions->osol);
			cout << jobID << endl;
		}
		else{
			cout << "please specify service location (url)" << endl;
		}
	}
	catch(const ErrorClass& eclass){
		std::cout << eclass.errormsg <<  std::endl;
	}	
}//end getJobID
 

void knock(){
	std::string osplOutput = "";
	OSSolverAgent* osagent = NULL;
	FileUtil *fileUtil = NULL;
	fileUtil = new FileUtil();
	try{
		if(osoptions->serviceLocation != NULL){
			osagent = new OSSolverAgent( osoptions->serviceLocation );
			osplOutput = osagent->knock(osoptions->osplInput,  osoptions->osol);
			if(osoptions->osplOutputFile != NULL) fileUtil->writeFileFromString(osoptions->osplOutputFile, osplOutput);
			else cout << osplOutput << endl;
		}
		else{
			cout << "please specify service location (url)" << endl;
		}
	}
	catch(const ErrorClass& eclass){
		std::cout << eclass.errormsg <<  std::endl;
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
		std::cout << eclass.errormsg <<  std::endl;
	}	
}//end send

void retrieve(){
	std::string osrl = "";
	OSSolverAgent* osagent = NULL;
	FileUtil *fileUtil = NULL;
	fileUtil = new FileUtil();
	try{
		if(osoptions->serviceLocation != NULL){
			osagent = new OSSolverAgent( osoptions->serviceLocation );
			osrl = osagent->retrieve( osoptions->osol);
			if(osoptions->osrlFile != NULL) {
				fileUtil->writeFileFromString(osoptions->osrlFile, osrl); 
			}
			else cout << osrl << endl;
		}
		else{
			cout << "please specify service location (url)" << endl;
		}

	}
	catch(const ErrorClass& eclass){
		std::cout << eclass.errormsg <<  std::endl;
	}	
}//end retrieve

void kill(){
	std::string osplOutput = "";
	OSSolverAgent* osagent = NULL;
	FileUtil *fileUtil = NULL;
	fileUtil = new FileUtil();
	try{
		if(osoptions->serviceLocation != NULL){
			osagent = new OSSolverAgent( osoptions->serviceLocation );
			osplOutput = osagent->kill( osoptions->osol);
			if(osoptions->osplOutputFile != NULL) fileUtil->writeFileFromString(osoptions->osplOutputFile, osplOutput);
			else cout << osplOutput << endl;
		}
		else{
			cout << "please specify service location (url)" << endl;
		}
	}
	catch(const ErrorClass& eclass){
		std::cout << eclass.errormsg <<  std::endl;
	}	
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

