//$Id$
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
 * <b>INPUTS:</b>
 * <ul>
 * <li>
 * <b>-osil</b> xxx.osil (file name on local machine of optimization instance, 
 *       this is NULL by default, however if this remains NULL a problem
 * 		 instance must be specified in the osol file)
 * </li>  
 * <li>
 * <b>-osol</b> xxx.osol (file name on local machine of solver options, 
 *       default default value is NULL)
 * </li>
 * <li>
 * <b>-osrl</b> xxx.osrl (file name on local machine where the optimization 
 *       result is put, default is NULL)
 * </li> 
 * <li>
 * <b>-serviceLocation</b> location URL (the URL  of the server that is called 
 *       remotely if the problem not solved locally, default is NULL)
 * </li>
 * <li>
 * <b>-serviceMethod</b>  (send, solve, kill, knock, getJobID, retrieve, 
 *       default value is solve)
 * </li>
 * <li>
 * <b>-os</b> (Not used for now -- ignore)
 * </li>
 * <li>
 * <b>-osplInput</b> xxx.ospl name of file with input in OS Process Language
 * </li> 
 * <li>
 * <b>-osplOutput</b> xxx.ospl name of output file in OS Process Language
 * </li>
 * <li> 
 * <b>-mps</b> xxxx.mps (converts mps format to osil and has same effect as -osil)
 * </li>
 * <li>
 * <b>-nl</b> xxxx.nl (converts nl format to osil and has same effect as -osil)
 * </li>
 * <li>
 * <b>-solver</b> solverName (the name of the solver to be invoked)
 * </li>
 * <li>
 * <b>-browser</b> path location to browser e.g. 
 *       /Applications/Firefox.app/Contents/MacOS/firefox (default is NULL)
 * </li>
 * <li>
 * <b>-config</b> pathToConfigFile is the path to a configure file with the problem 
 * 	     parameters
 * </li>
 * <li>
 * <b>-insList</b> xxx.dat (used only for LINDO, file location on local 
 *       machine of LINDO instruction list)
 * </li>
 * </ul>
 */

#include "OSCoinSolver.h"
#include "OSResult.h" 
#include "OSiLReader.h"        
#include "OSiLWriter.h" 
#include "OSoLReader.h"
#include "OSrLReader.h"        
#include "OSrLWriter.h"      
#include "OSInstance.h"  
#include "OSOption.h"
#include "OSoLWriter.h"
#include "OSFileUtil.h"  
#include "OSConfig.h"  
#include "OSDefaultSolver.h"  
#include "OSWSUtil.h" 
#include "OSSolverAgent.h"   
#include "OShL.h"     
#include "OSErrorClass.h"
#include "OSmps2osil.h"   
#include "OSBase64.h"


#ifdef COIN_HAS_KNITRO    
#include "OSKnitroSolver.h"
#endif 

#ifdef COIN_HAS_LINDO    
#include "OSLindoSolver.h"
#endif 

#ifdef COIN_HAS_ASL
#include "OSnl2osil.h"
#endif

#ifdef COIN_HAS_GAMSUTILS
#include "OSgams2osil.hpp"
#endif

//#ifdef COIN_HAS_IPOPT  
//#include "OSIpoptSolver.h"
//#endif

#ifdef COIN_HAS_IPOPT  
#ifndef COIN_HAS_ASL
#include "OSIpoptSolver.h"
#undef COIN_HAS_ASL
#else
#include "OSIpoptSolver.h"
#endif
#endif

#ifdef COIN_HAS_BONMIN   
#include "OSBonminSolver.h"
#endif 

#ifdef COIN_HAS_COUENNE
#include "OSCouenneSolver.h"
#endif 

#include "OSOptionsStruc.h"  

#include<stdio.h>

using std::cout;
using std::endl;
using std::ostringstream;
using std::string;

//#define DEBUG_CL_INTERFACE


#define MAXCHARS 5000 

typedef struct yy_buffer_state *YY_BUFFER_STATE;
YY_BUFFER_STATE osss_scan_string(const char* osss, void* scanner);
//void osssset_extra (YY_EXTRA_TYPE user_defined ,yyscan_t yyscanner );
void setyyextra(osOptionsStruc *osoptions, void* scanner);
int ossslex(void* scanner);
int ossslex_init(void** ptr);
int ossslex_destroy(void* scanner);

std::string get_help();
std::string get_version();
std::string get_options();

// the serviceMethods  
void solve();
void getJobID();
void send();
void kill();
void retrieve();
void knock();


// additional methods
void getOSiLFromNl();
void getOSiLFromMps();
void getOSiLFromGams();
std::string buildSolver(std::string solverName, std::string osol,
		OSInstance *osinstance);

//std::string getServiceURI( std::string osol);
//std::string getInstanceLocation( std::string osol);
//std::string getSolverName( std::string osol);
//std::string setSolverName( std::string osol, std::string solverName);


//options structure
// this is the only global variable but 
// this is not a problem since this is a main routine
osOptionsStruc *osoptions;

int main(int argC, const char* argV[]) {
	WindowsErrorPopupBlocker();
	void* scanner;
	FileUtil *fileUtil = NULL;
	FileUtil *inputFileUtil = NULL;
	char osss[MAXCHARS] = " ";
	const char *space = " ";
	//char *config = "-config";
	std::string configFileName = "";
	int i;

	std::cout << getVersionInfo() ;

	// initialize the OS options structure

	osoptions = new osOptionsStruc();
	osoptions->configFile = "";
	osoptions->osilFile = "";
	osoptions->osil = "";
	osoptions->osolFile = "";
	osoptions->osol = "";
	osoptions->osrlFile = "";
	osoptions->osrl = "";
	//osoptions->insListFile = ""; 
	osoptions->insList = "";
	osoptions->serviceLocation = "";
	osoptions->serviceMethod = "";
	osoptions->osplInputFile = "";
	osoptions->osplOutputFile = "";
	osoptions->mpsFile = "";
	osoptions->nlFile = "";
	osoptions->gamsControlFile = "";
	osoptions->solverName = "";
	osoptions->browser = "";
	osoptions->invokeHelp = false;
	osoptions->writeVersion = false;
	osoptions->quit = false;
	bool scannerActive = false;
	try {
		if (argC < 2) {
			//std::cout << "There must be at least one command line argument" << std::endl;
			//std::cout << "Try -h or --help" << std::endl;
			//throw ErrorClass(
			//		"There must be at least one command line argument\n  Try -h or --help");
			//delete osoptions;
			//return 1;
			getVersionInfo();
			//this is the interactive shell
			scannerActive = true;
			ossslex_init(&scanner);
			setyyextra(osoptions, scanner);
			std::string osss1;
			std::string osss2;

			std::string::size_type i;
			unsigned int k;
			while(osoptions->quit != true){
				
				std::cout << "At the prompt below type \"help\" for a list of valid options, " ;
				std::cout << "otherwise enter\na valid option and option value. Type \"quit\" to leave the application. "  << std::endl << std::endl;
				
				std::cout << "Please enter a valid option followed by the corresponding option value: ";
				std::cin.getline(osss, MAXCHARS);
				
				if(strcmp(osss, "quit") == 0){
					return 0;
				}else{
					if(strcmp(osss, "solve") == 0){
						solve();
					}else{
						if(strcmp(osss, "help") == 0){
							std::cout  << get_options() << std::endl;
						}else{
							
							//see if we have both an option and an option value
							
							for(i = 0; i < strlen( osss) ; i++){
								
							}
							
							
							std::cout << "scanning the line: " << osss  << std::endl;
							
							strcat(osss, space);
							osss_scan_string(osss, scanner);
							ossslex(scanner);
							
							cout << "HERE ARE THE OPTION VALUES SO FAR:" << endl;
							if(osoptions->configFile != "") cout << "Config file = " << osoptions->configFile << endl;
							if(osoptions->osilFile != "") cout << "OSiL file = " << osoptions->osilFile << endl;
							if(osoptions->osolFile != "") cout << "OSoL file = " << osoptions->osolFile << endl;
							if(osoptions->osrlFile != "") cout << "OSrL file = " << osoptions->osrlFile << endl;
							//if(osoptions->insListFile != "") cout << "Instruction List file = " << osoptions->insListFile << endl;
							if(osoptions->osplInputFile != "") cout << "OSpL Input file = " << osoptions->osplInputFile << endl;
							if(osoptions->serviceMethod != "") cout << "Service Method = " << osoptions->serviceMethod << endl;
							if(osoptions->mpsFile != "") cout << "MPS File Name = " << osoptions->mpsFile << endl;
							if(osoptions->nlFile != "") cout << "NL File Name = " << osoptions->nlFile << endl;
							if(osoptions->solverName != "") cout << "Selected Solver = " << osoptions->solverName << endl;
							if(osoptions->serviceLocation != "") cout << "Service Location = " << osoptions->serviceLocation << endl;
							
							
							//convert to lower case so there is no solver name ambiguity

							for (k = 0; k < osoptions->solverName.length(); k++) {
								osoptions->solverName[k] = tolower(osoptions->solverName[k]);
							}
							
							// make sure we can read the files
							try{

								if (osoptions->osolFile != "") {
	
									osoptions->osol = fileUtil->getFileAsString(
											(osoptions->osolFile).c_str());
	
								}
								if (osoptions->osilFile != "") {
									osoptions->osil = fileUtil->getFileAsString(
											(osoptions->osilFile).c_str());
								}
	
								if (osoptions->osplInputFile != "")
									osoptions->osplInput = fileUtil->getFileAsString(
											(osoptions->osplInputFile).c_str());
								if (osoptions->osplOutputFile != "")
									osoptions->osplOutput = fileUtil->getFileAsString(
											(osoptions->osplOutputFile).c_str());
							} 
							
							catch (const ErrorClass& eclass) {
								std::cout << eclass.errormsg << std::endl;
							}
							
							
							
						}
					}
				}


				std::cout << std::endl;
				
			}
			ossslex_destroy(scanner);
			scannerActive = false;
			
			//return 0;
			
		}
		// make sure we do not exceed max allowed characters in command line
		i = 1;
		while (i < argC) {
			if (strlen(osss) + strlen(argV[i]) + 1 > MAXCHARS)
				throw ErrorClass("the command line has too many characters");
			strcat(osss, argV[i]);
			strcat(osss, space);
			i++;
		}
#ifdef DEBUG_CL_INTERFACE
		cout << "Input String = " << osss << endl;
#endif
		scannerActive = true;
		ossslex_init(&scanner);
		//std::cout << "Call Text Extra" << std::endl;
		setyyextra(osoptions, scanner);
		//std::cout << "Call scan string " << std::endl;
		osss_scan_string(osss, scanner);
#ifdef DEBUG_CL_INTERFACE
		std::cout << "call ossslex" << std::endl;
#endif
		ossslex(scanner);
		ossslex_destroy(scanner);
		scannerActive = false;
#ifdef DEBUG_CL_INTERFACE
		std::cout << "done with call to ossslex" << std::endl;
#endif
		// if there is a config file, get those options
		if (osoptions->configFile != "") {
			scannerActive = true;
			ossslex_init(&scanner);
			configFileName = osoptions->configFile;
#ifdef DEBUG_CL_INTERFACE
			cout << "configFileName = " << configFileName << endl;
#endif
			std::string osolfileOptions = fileUtil->getFileAsString(
					configFileName.c_str());
#ifdef DEBUG_CL_INTERFACE
			std::cout << "Call Text Extra" << std::endl;
#endif
			setyyextra(osoptions, scanner);
#ifdef DEBUG_CL_INTERFACE
			std::cout << "Done with call Text Extra" << std::endl;
#endif
			osss_scan_string(osolfileOptions.c_str(), scanner);
			ossslex(scanner);
			ossslex_destroy(scanner);
			scannerActive = false;
		}
	} catch (const ErrorClass& eclass) {
		//cout << eclass.errormsg <<  endl;
		//cout << "try -h or --help for more information" <<  endl;

		//new stuff on April 17, 2010
		OSResult *osresult = NULL;
		OSrLWriter *osrlwriter = NULL;
		osrlwriter = new OSrLWriter();
		osresult = new OSResult();
		osresult->setGeneralMessage(eclass.errormsg);
		osresult->setGeneralStatusType("error");
		std::string osrl = osrlwriter->writeOSrL(osresult);
		if (osoptions->osrlFile != "") {
			//fileUtil->writeFileFromString(osoptions->osrlFile,  eclass.errormsg);
			fileUtil->writeFileFromString(osoptions->osrlFile, osrl);
			if (osoptions->browser != "") {
				std::string str = osoptions->browser + "  "
						+ osoptions->osrlFile;
				const char *ch = &str[0];
				std::system(ch);
			}
		} else {
			//std::cout <<  eclass.errormsg << std::endl;
			std::cout << osrl << std::endl;
		}
		//catch garbage collection
		delete osresult;
		osresult = NULL;
		delete osrlwriter;
		osrlwriter = NULL;
		// end new stuff

		if(scannerActive == true) ossslex_destroy(scanner);
		delete fileUtil;
		delete osoptions;
		return 1;
	}
	try {
		if (osoptions->invokeHelp == true) {
			std::string helpTxt = get_help();
			std::cout << std::endl << std::endl;
			std::cout << helpTxt << std::endl;
			delete osoptions;
			osoptions = NULL;
			return 0;
		}
		if (osoptions->writeVersion == true) {
			std::string writeTxt = get_version();
			std::cout << std::endl << std::endl;
			std::cout << writeTxt << std::endl;
			delete osoptions;
			osoptions = NULL;
			return 0;
		}
	} catch (const ErrorClass& eclass) {
		//cout << eclass.errormsg <<  endl;
		//cout << "try -h or --help" <<  endl;


		//new stuff on April 17, 2010
		OSResult *osresult = NULL;
		OSrLWriter *osrlwriter = NULL;
		osrlwriter = new OSrLWriter();
		osresult = new OSResult();
		osresult->setGeneralMessage(eclass.errormsg);
		osresult->setGeneralStatusType("error");
		std::string osrl = osrlwriter->writeOSrL(osresult);
		if (osoptions->osrlFile != "") {
			//fileUtil->writeFileFromString(osoptions->osrlFile,  eclass.errormsg);
			fileUtil->writeFileFromString(osoptions->osrlFile, osrl);
			if (osoptions->browser != "") {
				std::string str = osoptions->browser + "  "
						+ osoptions->osrlFile;
				const char *ch = &str[0];
				std::system(ch);
			}
		} else {
			//std::cout <<  eclass.errormsg << std::endl;
			std::cout << osrl << std::endl;
		}
		//catch garbage collection
		delete osresult;
		osresult = NULL;
		delete osrlwriter;
		osrlwriter = NULL;
		// end new stuff


		delete osoptions;
		osoptions = NULL;
		delete inputFileUtil;
		inputFileUtil = NULL;
		return 1;
	}

#ifdef DEBUG_CL_INTERFACE
	cout << "HERE ARE THE OPTION VALUES:" << endl;
	if(osoptions->configFile != "") cout << "Config file = " << osoptions->configFile << endl;
	if(osoptions->osilFile != "") cout << "OSiL file = " << osoptions->osilFile << endl;
	if(osoptions->osolFile != "") cout << "OSoL file = " << osoptions->osolFile << endl;
	if(osoptions->osrlFile != "") cout << "OSrL file = " << osoptions->osrlFile << endl;
	//if(osoptions->insListFile != "") cout << "Instruction List file = " << osoptions->insListFile << endl;
	if(osoptions->osplInputFile != "") cout << "OSpL Input file = " << osoptions->osplInputFile << endl;
	if(osoptions->serviceMethod != "") cout << "Service Method = " << osoptions->serviceMethod << endl;
	if(osoptions->mpsFile != "") cout << "MPS File Name = " << osoptions->mpsFile << endl;
	if(osoptions->nlFile != "") cout << "NL File Name = " << osoptions->nlFile << endl;
	if(osoptions->gamsControlFile != "") cout << "gams Control File Name = " << osoptions->gamsControlFile << endl;
	if(osoptions->browser != "") cout << "Browser Value = " << osoptions->browser << endl;
	if(osoptions->solverName != "") cout << "Selected Solver = " << osoptions->solverName << endl;
	if(osoptions->serviceLocation != "") cout << "Service Location = " << osoptions->serviceLocation << endl;
#endif

	//convert to lower case so there is no solver name ambiguity
	unsigned int k;
	for (k = 0; k < osoptions->solverName.length(); k++) {
		osoptions->solverName[k] = tolower(osoptions->solverName[k]);
	}

	// get the data from the files
	fileUtil = new FileUtil();
	try {
		//if(osoptions->insListFile != "") osoptions->insList = fileUtil->getFileAsChar( (osoptions->insListFile).c_str() );
		if (osoptions->osolFile != "") {

			osoptions->osol = fileUtil->getFileAsString(
					(osoptions->osolFile).c_str());

		}

		if (osoptions->osilFile != "") {
			//this takes precedence over what is in the OSoL file
			osoptions->osil = fileUtil->getFileAsString(
					(osoptions->osilFile).c_str());
		}
		/*
		 else{// we were not given an osil file
		 // make sure we don't have a service URI in the file or are using mps or nl
		 // if we have nl or mps assume a local solve
		 if( (osoptions->osol != "") && (osoptions->nlFile == "") && (osoptions->gamsControlFile == "") && (osoptions->mpsFile == "") && (osoptions->serviceLocation == "")  &&  (getServiceURI( osoptions->osol) == "") ) 
		 osoptions->osil = fileUtil->getFileAsString( getInstanceLocation( osoptions->osol).c_str()  );
		 }
		 */

		//if(osoptions->osplInputFile != "") osoptions->osplInput = fileUtil->getFileAsChar( (osoptions->osplInputFile).c_str()  );
		if (osoptions->osplInputFile != "")
			osoptions->osplInput = fileUtil->getFileAsString(
					(osoptions->osplInputFile).c_str());
		//if(osoptions->osplOutputFile != "") osoptions->osplOutput = fileUtil->getFileAsChar( (osoptions->osplOutputFile).c_str() );
		if (osoptions->osplOutputFile != "")
			osoptions->osplOutput = fileUtil->getFileAsString(
					(osoptions->osplOutputFile).c_str());
	} catch (const ErrorClass& eclass) {
		//cout << eclass.errormsg <<  endl;
		//cout << "could not open file properly" << endl;
		//cout << "try -h or --help" <<  endl;


		//new stuff on April 17, 2010
		OSResult *osresult = NULL;
		OSrLWriter *osrlwriter = NULL;
		osrlwriter = new OSrLWriter();
		osresult = new OSResult();
		osresult->setGeneralMessage(eclass.errormsg);
		osresult->setGeneralStatusType("error");
		std::string osrl = osrlwriter->writeOSrL(osresult);
		if (osoptions->osrlFile != "") {
			//fileUtil->writeFileFromString(osoptions->osrlFile,  eclass.errormsg);
			fileUtil->writeFileFromString(osoptions->osrlFile, osrl);
			if (osoptions->browser != "") {
				std::string str = osoptions->browser + "  "
						+ osoptions->osrlFile;
				const char *ch = &str[0];
				std::system(ch);
			}
		} else {
			//std::cout <<  eclass.errormsg << std::endl;
			std::cout << osrl << std::endl;
		}
		//catch garbage collection
		delete osresult;
		osresult = NULL;
		delete osrlwriter;
		osrlwriter = NULL;
		// end new stuff


		delete osoptions;
		osoptions = NULL;
		delete fileUtil;
		fileUtil = NULL;
		return 1;
	}
	// now call the correct serviceMethod
	// solve is the default
	if (osoptions->serviceMethod == "")
		solve();
	if ((osoptions->serviceMethod[0] == 's') && (osoptions->serviceMethod[1]
			== 'o'))
		solve();
	else {
		switch (osoptions->serviceMethod[0]) {
		case 'g':
			getJobID();
			break;
		case 'r':
			retrieve();
			break;
		case 's':
			send();
			break;
		case 'k':
			if (osoptions->serviceMethod[1] == 'i')
				kill();
			else
				knock();
			break;
		default:

			break;
		}
	}
	delete osoptions;
	osoptions = NULL;
	delete fileUtil;
	fileUtil = NULL;
	return 0;
}

void solve() {
	std::string osrl = "";
	OSiLReader *osilreader = NULL;
	OSmps2osil *mps2osil = NULL;
#ifdef COIN_HAS_ASL
	OSnl2osil *nl2osil = NULL;
#endif
#ifdef COIN_HAS_GAMSUTILS
	OSgams2osil *gams2osil = NULL;
#endif 
	OSSolverAgent* osagent = NULL;
	FileUtil *fileUtil = NULL;
	fileUtil = new FileUtil();
	// now solve either remotely or locally
	try {
		if (osoptions->serviceLocation != "") {
			// call a method here to get OSiL if we have an nl or mps file
			if (osoptions->osil == "") {
				//we better have an nl file present or mps file or osol file
				if (osoptions->nlFile != "") {
					getOSiLFromNl();
				} else {
					if (osoptions->mpsFile != "") {
						getOSiLFromMps();
					} else {
						if (osoptions->gamsControlFile != "") {

							getOSiLFromGams();
						} else {// send an empty osil string
							osoptions->osil = "";
						}
					}
				}
			}
			// place a remote call

			osagent = new OSSolverAgent(osoptions->serviceLocation);

			if (osoptions->osol == "") {// we have no osol string

				std::ostringstream outStr;
				outStr
						<< "<?xml version=\"1.0\" encoding=\"UTF-8\"?> <osol xmlns=\"os.optimizationservices.org\" xmlns:xs=\"http://www.w3.org/2001/XMLSchema\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:schemaLocation=\"os.optimizationservices.org http://www.optimizationservices.org/schemas/";
				outStr << OS_SCHEMA_VERSION;
				outStr << "/OSoL.xsd\"></osol>";
				osoptions->osol = outStr.str();
			}
			osrl = osagent->solve(osoptions->osil, osoptions->osol);
			if (osoptions->osrlFile != "") {
				fileUtil->writeFileFromString(osoptions->osrlFile, osrl);
				//const char *ch1 = "/Applications/Firefox.app/Contents/MacOS/firefox  ";
				if (osoptions->browser != "") {
					std::string str = osoptions->browser + "  "
							+ osoptions->osrlFile;
					const char *ch = &str[0];
					std::system(ch);
				}
			} else
				cout << osrl << endl;
			delete osagent;
			osagent = NULL;

		} else {// solve locally
			if (osoptions->osil != "") {
				osilreader = new OSiLReader();
				osrl = buildSolver(osoptions->solverName, osoptions->osol,
						osilreader->readOSiL(osoptions->osil));
			} else {
				//we better have an nl file present or mps file or osol file
				if (osoptions->nlFile != "") {
#ifdef COIN_HAS_ASL
					nl2osil = new OSnl2osil( osoptions->nlFile);
					nl2osil->createOSInstance();
					osrl = buildSolver(osoptions->solverName, osoptions->osol, nl2osil->osinstance);
#else
					throw ErrorClass(
							"nlFile specified locally but ASL not present");
#endif
				} else {
					if (osoptions->mpsFile != "") {
						mps2osil = new OSmps2osil(osoptions->mpsFile);
						mps2osil->createOSInstance();
						osrl = buildSolver(osoptions->solverName,
								osoptions->osol, mps2osil->osinstance);
					} else {
						if (osoptions->gamsControlFile != "") {
#ifdef COIN_HAS_GAMSUTILS
							gams2osil = new OSgams2osil( osoptions->gamsControlFile);
							gams2osil->createOSInstance();
							osrl = buildSolver(osoptions->solverName, osoptions->osol, gams2osil->osinstance);
#else
							throw ErrorClass(
									"a Gams Control specified locally but GAMSIP not present");
#endif

						} else {// need an osol file with an instanceLocation specified
							//if( osoptions->osol.find( "<instanceLocation") == std::string::npos){
							throw ErrorClass(
									"Error: no osil, GAMS dat, AMPL nl, or mps file given for a local solve --- \n information in the osol file is ignored for local solves.");
							//}
						}
					}
				}
			}
			//delete fileUtil;
			if (osoptions->osrlFile != "") {

				fileUtil->writeFileFromString(osoptions->osrlFile, osrl);

				//const char *ch1 = "/Applications/Firefox.app/Contents/MacOS/firefox  ";
				if (osoptions->browser != "") {
					std::string str = osoptions->browser + "  "
							+ osoptions->osrlFile;
					const char *ch = &str[0];
					std::system(ch);
				}
			} else
				cout << osrl << endl;

		}//end of local solve


		//garbage collection
		if (osilreader != NULL)
			delete osilreader;
		osilreader = NULL;
		if (mps2osil != NULL)
			delete mps2osil;
		mps2osil = NULL;
#ifdef COIN_HAS_ASL
		if(nl2osil != NULL) delete nl2osil;
		nl2osil = NULL;
#endif
#ifdef COIN_HAS_GAMSUTILS
		if(gams2osil != NULL) delete gams2osil;
		gams2osil = NULL;
#endif 
		delete fileUtil;
		fileUtil = NULL;

	}//end try
	catch (const ErrorClass& eclass) {

		OSResult *osresult = NULL;
		OSrLWriter *osrlwriter = NULL;
		osrlwriter = new OSrLWriter();
		osresult = new OSResult();
		osresult->setGeneralMessage(eclass.errormsg);
		osresult->setGeneralStatusType("error");
		std::string osrl = osrlwriter->writeOSrL(osresult);
		if (osoptions->osrlFile != "") {
			//fileUtil->writeFileFromString(osoptions->osrlFile,  eclass.errormsg);
			fileUtil->writeFileFromString(osoptions->osrlFile, osrl);
			if (osoptions->browser != "") {
				std::string str = osoptions->browser + "  "
						+ osoptions->osrlFile;
				const char *ch = &str[0];
				std::system(ch);
			}
		} else {
			//std::cout <<  eclass.errormsg << std::endl;
			std::cout << osrl << std::endl;
		}
		//catch garbage collection
		delete osresult;
		osresult = NULL;
		delete osrlwriter;
		osrlwriter = NULL;

		//regular garbage collection
		if (osilreader != NULL)
			delete osilreader;
		osilreader = NULL;
		if (mps2osil != NULL)
			delete mps2osil;
		mps2osil = NULL;
#ifdef COIN_HAS_ASL
		if(nl2osil != NULL) delete nl2osil;
		nl2osil = NULL;
#endif
#ifdef COIN_HAS_GAMSUTILS
		if(gams2osil != NULL) delete gams2osil;
		gams2osil = NULL;
#endif 		
		delete fileUtil;
		fileUtil = NULL;
	}//end local catch

}//end solve

void getJobID() {
	std::string jobID = "";
	OSSolverAgent* osagent = NULL;
	try {
		if (osoptions->serviceLocation != "") {
			osagent = new OSSolverAgent(osoptions->serviceLocation);
			jobID = osagent->getJobID(osoptions->osol);
			cout << jobID << endl;
			delete osagent;
			osagent = NULL;
		} else {
			delete osagent;
			osagent = NULL;
			throw ErrorClass("please specify service location (url)");
		}
	} catch (const ErrorClass& eclass) {
		FileUtil *fileUtil = NULL;
		fileUtil = new FileUtil();
		OSResult *osresult = NULL;
		OSrLWriter *osrlwriter = NULL;
		osrlwriter = new OSrLWriter();
		osresult = new OSResult();
		osresult->setGeneralMessage(eclass.errormsg);
		osresult->setGeneralStatusType("error");
		std::string osrl = osrlwriter->writeOSrL(osresult);
		if (osoptions->osrlFile != "")
			fileUtil->writeFileFromString(osoptions->osrlFile, osrl);
		else
			cout << osrl << endl;
		delete osresult;
		osresult = NULL;
		delete osrlwriter;
		osrlwriter = NULL;
		delete fileUtil;
		fileUtil = NULL;
	}
}//end getJobID


void knock() {
	std::string osplOutput = "";
	OSSolverAgent* osagent = NULL;
	FileUtil *fileUtil = NULL;
	fileUtil = new FileUtil();
	try {
		if (osoptions->serviceLocation != "") {
			osagent = new OSSolverAgent(osoptions->serviceLocation);
			osplOutput = osagent->knock(osoptions->osplInput, osoptions->osol);
			if (osoptions->osplOutputFile != "")
				fileUtil->writeFileFromString(osoptions->osplOutputFile,
						osplOutput);
			else
				cout << osplOutput << endl;
			delete osagent;
		} else {
			delete osagent;
			throw ErrorClass("please specify service location (url)");
		}
		delete fileUtil;
		fileUtil = NULL;
	} catch (const ErrorClass& eclass) {
		OSResult *osresult = NULL;
		OSrLWriter *osrlwriter = NULL;
		osrlwriter = new OSrLWriter();
		osresult = new OSResult();
		osresult->setGeneralMessage(eclass.errormsg);
		osresult->setGeneralStatusType("error");
		std::string osrl = osrlwriter->writeOSrL(osresult);
		if (osoptions->osrlFile != "")
			fileUtil->writeFileFromString(osoptions->osrlFile, osrl);
		else
			cout << osrl << endl;
		delete osresult;
		osresult = NULL;
		delete osrlwriter;
		osrlwriter = NULL;
		delete fileUtil;
		fileUtil = NULL;
	}
}//end knock


void send() {
	bool bSend = false;
	std::string jobID = "";
	OSSolverAgent* osagent = NULL;
	// first get the jobID
	std::string
			sOSoL =
					"<?xml version=\"1.0\" encoding=\"UTF-8\"?> <osol xmlns=\"os.optimizationservices.org\" xmlns:xs=\"http://www.w3.org/2001/XMLSchema\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:schemaLocation=\"os.optimizationservices.org http://www.optimizationservices.org/schemas/OSoL.xsd\"><general> </general></osol>";
	string::size_type iStringpos;
	try {
		// call a method here to get OSiL if we have an nl or mps file
		if (osoptions->osil == "") {
			//we better have an nl file present or mps file
			if (osoptions->nlFile != "") {
				getOSiLFromNl();
			} else {
				if (osoptions->mpsFile != "") {
					getOSiLFromMps();
				} else {// send an empty osil string
					osoptions->osil = "";
				}
			}
		}
		if (osoptions->serviceLocation != "") {
			osagent = new OSSolverAgent(osoptions->serviceLocation);
			// check to see if there is an osol 
			if (osoptions->osolFile == "") {
				// get a jobID
				jobID = osagent->getJobID(sOSoL);
				// insert the jobID into the default osol
				iStringpos = sOSoL.find("</general");
				if (iStringpos != std::string::npos)
					sOSoL.insert(iStringpos, "<jobID>" + jobID + "</jobID>");
			} else {
				sOSoL = osoptions->osolFile;
			}

			bSend = osagent->send(osoptions->osil, sOSoL);
			delete osagent;
		} else {
			delete osagent;
			throw ErrorClass("please specify service location (url)");
		}
	} catch (const ErrorClass& eclass) {
		FileUtil *fileUtil = NULL;
		fileUtil = new FileUtil();
		OSResult *osresult = NULL;
		OSrLWriter *osrlwriter = NULL;
		osrlwriter = new OSrLWriter();
		osresult = new OSResult();
		osresult->setGeneralMessage(eclass.errormsg);
		osresult->setGeneralStatusType("error");
		std::string osrl = osrlwriter->writeOSrL(osresult);
		if (osoptions->osrlFile != "")
			fileUtil->writeFileFromString(osoptions->osrlFile, osrl);
		else
			cout << osrl << endl;
		delete osresult;
		osresult = NULL;
		delete osrlwriter;
		osrlwriter = NULL;
		delete fileUtil;
		fileUtil = NULL;
	}
}//end send

void retrieve() {
	FileUtil *fileUtil = NULL;
	fileUtil = new FileUtil();
	std::string osrl = "";
	OSSolverAgent* osagent = NULL;
	try {
		if (osoptions->serviceLocation != "") {
			osagent = new OSSolverAgent(osoptions->serviceLocation);
#ifdef DEBUG_CL_INTERFACE
			std::cout << "HERE ARE THE OSOL OPTIONS " << osoptions->osol << std::endl;
#endif
			osrl = osagent->retrieve(osoptions->osol);
			if (osoptions->osrlFile != "") {
				fileUtil->writeFileFromString(osoptions->osrlFile, osrl);
				if (osoptions->browser != "") {
					std::string str = osoptions->browser + "  "
							+ osoptions->osrlFile;
					const char *ch = &str[0];
					std::system(ch);
				}
			} else
				cout << osrl << endl;
			delete osagent;
			osagent = NULL;
		} else {
			delete osagent;
			osagent = NULL;
			throw ErrorClass("please specify service location (url)");
		}
		delete fileUtil;
		fileUtil = NULL;
	} catch (const ErrorClass& eclass) {
		OSResult *osresult = NULL;
		OSrLWriter *osrlwriter = NULL;
		osrlwriter = new OSrLWriter();
		osresult = new OSResult();
		osresult->setGeneralMessage(eclass.errormsg);
		osresult->setGeneralStatusType("error");
		std::string osrl = osrlwriter->writeOSrL(osresult);
		if (osoptions->osrlFile != "")
			fileUtil->writeFileFromString(osoptions->osrlFile, osrl);
		else
			cout << osrl << endl;
		delete osresult;
		osresult = NULL;
		delete osrlwriter;
		osrlwriter = NULL;
		delete fileUtil;
		fileUtil = NULL;
	}
}//end retrieve

void kill() {
	FileUtil *fileUtil = NULL;
	fileUtil = new FileUtil();
	std::string osplOutput = "";
	OSSolverAgent* osagent = NULL;
	try {
		if (osoptions->serviceLocation != "") {
			osagent = new OSSolverAgent(osoptions->serviceLocation);
			osplOutput = osagent->kill(osoptions->osol);
			if (osoptions->osplOutputFile != "")
				fileUtil->writeFileFromString(osoptions->osplOutputFile,
						osplOutput);
			else
				cout << osplOutput << endl;
			delete osagent;
			osagent = NULL;
		} else {
			delete osagent;
			osagent = NULL;
			throw ErrorClass("please specify service location (url)");
		}
		delete fileUtil;
		fileUtil = NULL;
	} catch (const ErrorClass& eclass) {
		OSResult *osresult = NULL;
		OSrLWriter *osrlwriter = NULL;
		osrlwriter = new OSrLWriter();
		osresult = new OSResult();
		osresult->setGeneralMessage(eclass.errormsg);
		osresult->setGeneralStatusType("error");
		std::string osrl = osrlwriter->writeOSrL(osresult);
		if (osoptions->osrlFile != "")
			fileUtil->writeFileFromString(osoptions->osrlFile, osrl);
		else
			cout << osrl << endl;
		delete osresult;
		osresult = NULL;
		delete osrlwriter;
		osrlwriter = NULL;
		delete fileUtil;
		fileUtil = NULL;
	}
}//end kill

void getOSiLFromNl() {
	try {
#ifdef COIN_HAS_ASL
		OSnl2osil *nl2osil = NULL;
		nl2osil = new OSnl2osil( osoptions->nlFile);
		nl2osil->createOSInstance();
		OSiLWriter *osilwriter = NULL;
		osilwriter = new OSiLWriter();
		std::string osil;
		osil = osilwriter->writeOSiL( nl2osil->osinstance);
		osoptions->osil = osil;
		delete nl2osil;
		nl2osil = NULL;
		delete osilwriter;
		osilwriter = NULL;
#else
		throw ErrorClass(
				"trying to convert nl to osil without AMPL ASL configured");
#endif
	} catch (const ErrorClass& eclass) {
		std::cout << eclass.errormsg << std::endl;
		throw ErrorClass(eclass.errormsg);
	}
}//getOSiLFromNl


void getOSiLFromGams() {
	try {
#ifdef COIN_HAS_GAMSIO  
		OSgams2osil *gams2osil = NULL;
		gams2osil = new OSgams2osil( osoptions->gamsControlFile);
		gams2osil->createOSInstance();
		OSiLWriter *osilwriter = NULL;
		osilwriter = new OSiLWriter();
		std::string osil;
		osil = osilwriter->writeOSiL( gams2osil->osinstance);
		osoptions->osil = osil;
		delete gams2osil;
		gams2osil = NULL;
		delete osilwriter;
		osilwriter = NULL;
#else
		throw ErrorClass(
				"trying to convert Gams control file to osil without GAMSUTILS configured");
#endif
	} catch (const ErrorClass& eclass) {
		std::cout << eclass.errormsg << std::endl;
		throw ErrorClass(eclass.errormsg);
	}
}//getOSiLFromGams


void getOSiLFromMps() {
	try {
		OSmps2osil *mps2osil = NULL;
		mps2osil = new OSmps2osil(osoptions->mpsFile);
		mps2osil->createOSInstance();
		OSiLWriter *osilwriter = NULL;
		osilwriter = new OSiLWriter();
		std::string osil;
		osil = osilwriter->writeOSiL(mps2osil->osinstance);
		osoptions->osil = osil;
		delete mps2osil;
		mps2osil = NULL;
		delete osilwriter;
		osilwriter = NULL;
	} catch (const ErrorClass& eclass) {
		std::cout << eclass.errormsg << std::endl;
		throw ErrorClass(eclass.errormsg);
	}

}//getOSiLFromMps

//string getServiceURI( std::string osol){
//	if(osol == "") return osol;
//	string::size_type pos2;
//	string::size_type  pos1 = osol.find( "<serviceURI");
//	if(pos1 != std::string::npos){
//		// get the end of the serviceURI start tag
//		pos1 = osol.find(">", pos1 + 1);
//		if(pos1 != std::string::npos){
//			// get the start of serviceURI end tag
//			pos2 = osol.find( "</serviceURI", pos1 + 1);
//			if( pos2 != std::string::npos){
//				// get the substring
//				return osol.substr( pos1 + 1, pos2 - pos1 - 1); 
//			}
//			else return "";
//		}
//		else return "";
//	}
//	else return "";
//}//getServiceURI

//string getInstanceLocation( std::string osol){
//	if(osol == "") return osol;
//	string::size_type pos2;
//	string::size_type pos1 = osol.find( "<instanceLocation");
//	if(pos1 != std::string::npos){
//		// get the end of the instanceLocation start tag
//		pos1 = osol.find(">", pos1 + 1);
//		if(pos1 != std::string::npos){
//			// get the start of instanceLocation end tag
//			pos2 = osol.find( "</instanceLocation", pos1 + 1);
//			if( pos2 != std::string::npos){
//				// get the substring
//				return osol.substr( pos1 + 1, pos2 - pos1 - 1); 
//			}
//			else return "";
//		}
//		else return "";
//	}
//	else return "";
//}//getInstanceLocation


//std::string getSolverName( std::string osol){
//#ifdef DEBUG_CL_INTERFACE
//	std::cout << "inside getSolverName" << std::endl;
//	std::cout <<  osol << std::endl;
//	std::cout << "done with osol" << std::endl;
//#endif
//	OSOption *osoption = NULL;
//	OSoLReader *osolreader = NULL;
//	osolreader = new OSoLReader();
//
//	osoption = osolreader->readOSoL( osol);
//#ifdef DEBUG_CL_INTERFACE
//	std::cout <<  "invoke getSolverToInvoke" << std::endl;
//#endif
//	std::string optionstring = osoption->getSolverToInvoke();
//#ifdef DEBUG_CL_INTERFACE
//	std::cout <<  "done with invoke getSolverToInvoke" << std::endl;
//#endif
////	delete osoption;
//	delete osolreader;
//	return optionstring;
//	/*
//	if(osol == "") return osol;
//	string::size_type pos2;
//	string::size_type pos1 = osol.find( "solverToInvoke");
//	if(pos1 != std::string::npos){
//		// get the end of the instanceLocation start tag
//		pos1 = osol.find(">", pos1 + 1);
//		if(pos1 != std::string::npos){
//			// get the start of instanceLocation end tag
//			pos2 = osol.find( "</solverToInvoke", pos1 + 1);
//			if( pos2 != std::string::npos){
//				// get the substring
//				return osol.substr( pos1 + 1, pos2 - pos1 - 1); 
//			}
//			else return "";
//		}
//		else return "";
//	}
//	else return "";
//	*/
//}//getSolverName


//std::string setSolverName( std::string osol, std::string solverName){
//#ifdef DEBUG_CL_INTERFACE
//	std::cout << "inside setSolverName" << std::endl;
//#endif
//	OSOption *osoption = NULL;
//	OSoLReader *osolreader = NULL;
//	osolreader = new OSoLReader();
//	osoption = osolreader->readOSoL( osol);
////	std::cout <<  "invoke getSolverToInvoke" << std::endl;
//	osoption->setSolverToInvoke( solverName);
////	std::cout <<  "Solver Name =  " << solverName << std::endl;
////	std::cout <<  "done with invoke getSolverToInvoke" << std::endl;
//	OSoLWriter *osolwriter = NULL;
//	osolwriter = new OSoLWriter();
//	std::string newOSoL = osolwriter->writeOSoL( osoption);
////	std::cout << "NEW OSOL" << std::endl;
////	std::cout << newOSoL << std::endl;
////	delete osoption;
//	delete osolreader;
//	delete osolwriter;
//	return newOSoL;
//}//setSolverName

std::string get_help() {

	std::ostringstream helpMsg;

	helpMsg << "************************* HELP *************************"
			<< endl << endl;
	helpMsg
			<< "In this HELP file we assume that the solve service method is used and "
			<< endl;
	helpMsg
			<< "that we are solving problems locally, that is the solver is on the "
			<< endl;
	helpMsg
			<< "machine running this OSSolverService.  See Section 10.3 of the User\'s  "
			<< endl;
	helpMsg
			<< "Manual for other service methods or calling a server remotely. "
			<< endl;
	helpMsg << "The OSSolverService takes the parameters listed below.  "
			<< endl;
	helpMsg
			<< "The order of the parameters is irrelevant.  Not all the parameters  "
			<< endl;
	helpMsg << "are required.  However, the location of an instance file is  "
			<< endl;
	helpMsg
			<< "required when using the solve service method. The location of the "
			<< endl;
	helpMsg << "instance file is specified using the osil option. " << endl;

	helpMsg << endl;

	helpMsg
			<< "-osil xxx.osil this is the name of the file that contains the  "
			<< endl;
	helpMsg << "optimization instance in OSiL format.  This option may be  "
			<< endl;
	helpMsg << "specified in the OSoL solver options file. " << endl;

	helpMsg << endl;

	helpMsg
			<< "-osol xxx.osol  this is the name of the file that contains the solver options.   "
			<< endl;
	helpMsg << "It is not necessary to specify this option. " << endl;

	helpMsg << endl;

	helpMsg
			<< "-osrl xxx.osrl  this is the name of the file to which the solver solution is written.  "
			<< endl;
	helpMsg
			<< "It is not necessary to specify this option. If this option is not specified,  "
			<< endl;
	helpMsg << "the result will be printed to standard out.  " << endl;

	helpMsg << endl;

	helpMsg
			<< "-osplInput xxx.ospl  this is the name of an input file in the OS Process"
			<< endl;
	helpMsg << " Language (OSpL), this is used as input  to the knock method."
			<< endl;

	helpMsg << endl;

	helpMsg
			<< "-osplOutput xxx.ospl this is the name of an output file in the  OS Process"
			<< endl;
	helpMsg
			<< "Language (OSpL), this the output string from the knock and kill methods."
			<< endl;

	helpMsg << endl;

	helpMsg << "-serviceLocation url is the URL of the solver service.  "
			<< endl;
	helpMsg
			<< "This is not required, and if not specified it is assumed that   "
			<< endl;
	helpMsg << "the problem is solved locally.  " << endl;

	helpMsg << endl;

	helpMsg
			<< "-serviceMethod  methodName this is the method on the solver service to be invoked.  "
			<< endl;
	helpMsg
			<< "The options are  solve,  send,  kill,  knock,  getJobID, and retrieve.   "
			<< endl;
	helpMsg
			<< "This option is not required, and the default value is  solve.  "
			<< endl;

	helpMsg << endl;

	helpMsg
			<< "-mps  xxx.mps  this is the name of the mps file if the problem instance  "
			<< endl;
	helpMsg
			<< "is in mps format. The default file format is OSiL so this option is not required.  "
			<< endl;

	helpMsg << endl;

	helpMsg
			<< "-nl  xxx.nl  this is the name of the AMPL nl file if the problem  "
			<< endl;
	helpMsg
			<< "instance is in AMPL nl  format. The default file format is OSiL  "
			<< endl;
	helpMsg << "so this option is not required.  " << endl;

	helpMsg << endl;

	helpMsg
			<< "-solver  solverName  Possible values for default OS installation  "
			<< endl;
	helpMsg
			<< "are  bonmin(COIN-OR Bonmin), couenne (COIN-OR Couenne), clp (COIN-OR Clp),"
			<< endl;
	helpMsg << "cbc (COIN-OR Cbc), dylp (COIN-OR DyLP), ipopt (COIN-OR Ipopt),"
			<< endl;
	helpMsg << "and symphony (COIN-OR SYMPHONY). Other solvers supported"
			<< endl;
	helpMsg
			<< "(if the necessary libraries are present) are cplex (Cplex through COIN-OR Osi),"
			<< endl;
	helpMsg
			<< "glpk (glpk through COIN-OR Osi), knitro (Knitro), and lindo (LINDO)."
			<< endl;
	helpMsg << "If no value is specified for this parameter," << endl;
	helpMsg << "then cbc is the default value of this parameter." << endl;

	helpMsg << endl;

	helpMsg
			<< "-browser  browserName this paramater is a path to the browser on the  "
			<< endl;
	helpMsg
			<< "local machine. If this optional parameter is specified then the  "
			<< endl;
	helpMsg << "solver result in OSrL format is transformed using XSLT into  "
			<< endl;
	helpMsg << "HTML and displayed in the browser.  " << endl;

	helpMsg << endl;

	helpMsg
			<< "-config pathToConfigureFile this parameter specifies a path on  "
			<< endl;
	helpMsg
			<< "the local machine to a text file containing values for the input parameters.  "
			<< endl;
	helpMsg
			<< "This is convenient for the user not wishing to constantly retype parameter values.  "
			<< endl;
	helpMsg
			<< "This configure file can contain values for all of the other parameters. "
			<< endl;

	helpMsg << endl;

	helpMsg << "--version or -v get the current version of this executable  "
			<< endl;

	helpMsg << endl;

	helpMsg << "--help or -h  to get this help file " << endl;

	helpMsg << endl;

	helpMsg
			<< "Note: If you specify a configure file by using the -config option, you can  "
			<< endl;
	helpMsg
			<< "override the values of the options in the configure file by putting them in   "
			<< endl;
	helpMsg << "at the command line. " << endl << endl;

	helpMsg
			<< "See the OS User\' Manual: http://www.coin-or.org/OS/doc/osUsersManual_2.0.pdf"
			<< endl;
	helpMsg << "for more detail on how to use the OS project. " << endl;

	helpMsg << endl;
	helpMsg << "********************************************************"
			<< endl << endl;

	return helpMsg.str();
}// get help


std::string get_version() {

	std::ostringstream versionMsg;
	versionMsg << "In order to find the version of this project " << endl;
	versionMsg << "connect to the directory where you downloaded " << endl;
	versionMsg << "and do: " << endl;
	versionMsg << "svn info " << endl;

	return versionMsg.str();
}// get version


std::string buildSolver(std::string solverName, std::string osol,
		OSInstance *osinstance) {
	DefaultSolver *solverType = NULL;
	//std::cout << "SOLVER NAME = " << solverName << std::endl;
	try {
		if (solverName == "") {// must determine the default solver
			if (osinstance == NULL)
				throw ErrorClass(
						"there was a NULL instance sent to buildSolver");
			//see if we have an integer program 
			if (osinstance->getNumberOfIntegerVariables()
					+ osinstance->getNumberOfBinaryVariables() > 0) {//we have an integer program
				if ((osinstance->getNumberOfNonlinearExpressions() > 0)
						|| (osinstance->getNumberOfQuadraticTerms() > 0)) { // we are nonlinear and integer
					solverName = "bonmin";
				} else {//we are linear integer 
					solverName = "cbc";
				}
			} else {// we have a continuous problem
				if ((osinstance->getNumberOfNonlinearExpressions() > 0)
						|| (osinstance->getNumberOfQuadraticTerms() > 0)) { // we are nonlinear and continuous
					solverName = "ipopt";
				} else {//we have linear program 
					solverName = "clp";
				}
			}
		}//end of if on solverName

		//now build the solver through its constructor

		//std::cout << "SOLVER NAME =  " << solverName << std::endl;

		if (solverName.find("ipopt") != std::string::npos) {
			// we are requesting the Ipopt solver
			bool bIpoptIsPresent = false;
#ifdef COIN_HAS_IPOPT
			bIpoptIsPresent = true;
			solverType = new IpoptSolver();
#endif
			if (bIpoptIsPresent == false)
				throw ErrorClass("the Ipopt solver requested is not present");
		} else {
			if (solverName.find("lindo") != std::string::npos) {
				// we are requesting the Lindo solver
				bool bLindoIsPresent = false;
#ifdef COIN_HAS_LINDO
				bLindoIsPresent = true;
				std::cout << "calling the LINDO Solver " << std::endl;
				solverType = new LindoSolver();
				std::cout << "DONE calling the LINDO Solver " << std::endl;
#endif
				if (bLindoIsPresent == false)
					throw ErrorClass(
							"the Lindo solver requested is not present");
			} else {
				if (solverName.find("clp") != std::string::npos) {
					//std::cout << "NEWING SOLVER TYPE " << std::endl;
					solverType = new CoinSolver();
					//std::cout << "END NEWING SOLVER TYPE " << std::endl;
					solverType->sSolverName = "clp";
				} else {
					if (solverName.find("cplex") != std::string::npos) {
						bool bCplexIsPresent = false;
#ifdef COIN_HAS_CPX
						bCplexIsPresent = true;
						solverType = new CoinSolver();
						solverType->sSolverName = "cplex";
#endif
						if (bCplexIsPresent == false)
							throw ErrorClass(
									"the Cplex solver requested is not present");
					} else {
						if (solverName.find("glpk") != std::string::npos) {
							bool bGlpkIsPresent = false;
#ifdef COIN_HAS_GLPK
							bGlpkIsPresent = true;
							solverType = new CoinSolver();
							solverType->sSolverName = "glpk";
#endif
							if (bGlpkIsPresent == false)
								throw ErrorClass(
										"the GLPK solver requested is not present");
						} else {
							if (solverName.find("dylp") != std::string::npos) {
								bool bDyLPIsPresent = false;
#ifdef COIN_HAS_DYLP
								bDyLPIsPresent = true;
								solverType = new CoinSolver();
								solverType->sSolverName = "dylp";
								bDyLPIsPresent = true;
#endif
								if (bDyLPIsPresent == false)
									throw ErrorClass(
											"the DyLP solver requested is not present");
							} else {
								if (solverName.find("symphony")
										!= std::string::npos) {
									bool bSymphonyIsPresent = false;
#ifdef COIN_HAS_SYMPHONY
									bSymphonyIsPresent = true;
									solverType = new CoinSolver();
									solverType->sSolverName = "symphony";
#endif
									if (bSymphonyIsPresent == false)
										throw ErrorClass(
												"the SYMPHONY solver requested is not present");
								} else {
									if (solverName.find("knitro")
											!= std::string::npos) {
										bool bKnitroIsPresent = false;
#ifdef COIN_HAS_KNITRO
										bKnitroIsPresent = true;
										std::cout << "calling the KNITRO Solver " << std::endl;
										solverType = new KnitroSolver();
										std::cout << "DONE calling the KNITRO Solver " << std::endl;
#endif
										if (bKnitroIsPresent == false)
											throw ErrorClass(
													"the Knitro solver requested is not present");
									} else {
										if (solverName.find("vol")
												!= std::string::npos) {
											bool bVolIsPresent = false;
#ifdef COIN_HAS_VOL
											bVolIsPresent = true;
											solverType = new CoinSolver();
											solverType->sSolverName = "vol";
#endif
											if (bVolIsPresent == false)
												throw ErrorClass(
														"the Vol solver requested is not present");
										} else {
											if (solverName.find("bonmin")
													!= std::string::npos) {
												// we are requesting the Bonmin solver
												bool bBonminIsPresent = false;
#ifdef COIN_HAS_BONMIN
												bBonminIsPresent = true;
												solverType = new BonminSolver();
#endif												
												if (bBonminIsPresent == false)
													throw ErrorClass(
															"the Bonmin solver requested is not present");
											} else {
												if (solverName.find("couenne")
														!= std::string::npos) {
													// we are requesting the Couenne solver
													bool bCouenneIsPresent =
															false;
#ifdef COIN_HAS_COUENNE
													bCouenneIsPresent = true;
													solverType = new CouenneSolver();
#endif												
													if (bCouenneIsPresent
															== false)
														throw ErrorClass(
																"the Couenne solver requested is not present");
												} else { //cbc is the default
													solverType
															= new CoinSolver();
													solverType->sSolverName
															= "cbc";
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}

		//std::cout << "SET SOLVER INSTANCE " << std::endl;
		solverType->osinstance = osinstance;
		solverType->osol = osol;
		solverType->buildSolverInstance();
		solverType->setSolverOptions();
		solverType->solve();
		std::string resultString = solverType->osrl;
		if (solverType != NULL)
			delete solverType;
		solverType = NULL;
		return resultString;

	} catch (const ErrorClass& eclass) {
		throw eclass;
	}

}//buildSolver


std::string get_options() {

	std::ostringstream optionMsg;

	optionMsg << "************************* VALID OPTIONS *************************"
			<< endl << endl;

	optionMsg << "The OSSolverService takes the options listed below.  "
			<< endl;
	optionMsg
			<< "The order of the options is irrelevant.  Not all option values  "
			<< endl;
	optionMsg << "are required.  However, the location of an instance file is  "
			<< endl;
	optionMsg
			<< "required when using the solve service method. The location of the "
			<< endl;
	optionMsg << "instance file is specified using the osil option. " << endl;

	optionMsg << endl;
	
	optionMsg
			<< "quit -- this option does not require a value and will terminate the executable "
			<< endl;
	
	optionMsg
			<< "help -- this option does not require a value and will produce this list of options "
			<< endl;

	optionMsg
			<< "solve -- this option does not require a value and call the solver "
			<< endl;

	optionMsg << endl;	


	
	optionMsg
			<< "osil -- the value of this option is the location of the model instance in OSiL format"
			<< endl;
	
	

	optionMsg
			<< "osol -- the value of this option is the location of the solver option file in OSoL format   "
			<< endl;

	optionMsg
			<< "osrl -- the value of this option is the location of the solver result file in OSrL format   "
			<< endl;

	optionMsg
			<< "osplInput -- the value of this option is the name of an input file in the OS Process"
			<< endl;
	optionMsg << " Language (OSpL), this is used as input  to the knock method."
			<< endl;

	optionMsg << endl;

	optionMsg
			<< "osplOutput -- the value of this option is the name of an input file in the OS Process"
			<< endl;
	optionMsg
			<< "Language (OSpL), this the output string from the knock and kill methods."
			<< endl;

	optionMsg << endl;

	optionMsg << "serviceLocation -- the value of this option is the URL of the solver service.  "
			<< endl;
	optionMsg
			<< "This is not required, and if not specified it is assumed that   "
			<< endl;
	optionMsg << "the problem is solved locally.  " << endl;

	optionMsg << endl;

	optionMsg
			<< "serviceMethod  -- the value of  this option is the method on the solver service to be invoked.  "
			<< endl;
	optionMsg
			<< "Valid option values are solve,  send,  kill,  knock,  getJobID, and retrieve.   "
			<< endl;
	optionMsg
			<< "This option is not required, and the default value is  solve.  "
			<< endl;

	optionMsg << endl;

	optionMsg
			<< "mps  -- the value of this option is the name of the mps file if the problem instance  "
			<< endl;
	optionMsg
			<< "is in mps format. The default file format is OSiL so this option is not required.  "
			<< endl;

	optionMsg << endl;

	optionMsg
			<< "nl  the value of this option is the name of the AMPL nl file if the problem  "
			<< endl;
	optionMsg
			<< "instance is in AMPL nl  format. The default file format is OSiL  "
			<< endl;
	optionMsg << "so this option is not required.  " << endl;

	optionMsg << endl;

	optionMsg
			<< "solver -- the value of this option is the solver to invoke "
			<< endl;
	optionMsg
			<< "are  bonmin(COIN-OR Bonmin), couenne (COIN-OR Couenne), clp (COIN-OR Clp),"
			<< endl;
	optionMsg << "cbc (COIN-OR Cbc), dylp (COIN-OR DyLP), ipopt (COIN-OR Ipopt),"
			<< endl;
	optionMsg << "and symphony (COIN-OR SYMPHONY). Other solvers supported"
			<< endl;
	optionMsg
			<< "(if the necessary libraries are present) are cplex (Cplex through COIN-OR Osi),"
			<< endl;
	optionMsg
			<< "glpk (glpk through COIN-OR Osi), knitro (Knitro), and lindo (LINDO)."
			<< endl;
	optionMsg << "If no value is specified for this parameter," << endl;
	optionMsg << "then cbc is the default value of this parameter." << endl;

	optionMsg << endl;


	optionMsg
			<< "config -- the value of this parameter specifies a path on  "
			<< endl;
	optionMsg
			<< "the local machine to a text file containing values for the input parameters.  "
			<< endl;
	optionMsg
			<< "This is convenient for the user not wishing to constantly retype parameter values.  "
			<< endl;
	optionMsg
			<< "This configure file can contain values for all of the other parameters. "
			<< endl;


	optionMsg
			<< "See the OS User\' Manual: http://www.coin-or.org/OS/doc/osUsersManual_2.1.pdf"
			<< endl;
	optionMsg << "for more detail on how to use the OS project. " << endl;

	optionMsg << endl;
	optionMsg << "********************************************************"
			<< endl << endl;

	return optionMsg.str();
}// get_options

