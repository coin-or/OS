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


/**
 * Below are the possible inputs to
 * this executable
 */
 
 
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
 * -config pathToConfigFile is the path to a configure file with the problem 
 * 	     parameters
 * -insList xxx.dat (used only for LINDO, file location on local 
 *       machine of LINDO instruction list)
*/


#include "OSResult.h" 
#include "OSiLReader.h"        
#include "OSiLWriter.h" 
#include "OSrLReader.h"        
#include "OSrLWriter.h"      
#include "OSInstance.h"  
#include "FileUtil.h"  
#include "OSConfig.h"  
#include "CoinSolver.h"
#include "DefaultSolver.h"  
#include "WSUtil.h" 
#include "OSSolverAgent.h"   
#include "OShL.h"     
#include "ErrorClass.h"
#include "OSmps2osil.h"   
#include "Base64.h"
#include "CommonUtil.h"

#ifdef COIN_HAS_KNITRO    
#include "KnitroSolver.h"
#endif

#ifdef COIN_HAS_ASL
#include "OSnl2osil.h"
#endif
#ifdef COIN_HAS_LINDO    
#include "LindoSolver.h"
#endif  
#ifdef COIN_HAS_IPOPT    
#include "IpoptSolver.h"
#endif 



#include "osOptionsStruc.h"  

    

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

// additional methods
void getOSiLFromNl(); 
void getOSiLFromMps();
string getServiceURI( std::string osol);
string getInstanceLocation( std::string osol);
string getSolverName( std::string osol);

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
	//char *config = "-config";
	std::string configFileName = "";
	int i;

	// initialize the OS options structure

	osoptions = new osOptionsStruc();
	osoptions->configFile = ""; 
	osoptions->osilFile = ""; 
	osoptions->osil = ""; 
	osoptions->osolFile = ""; 
	osoptions->osol = "";  
	osoptions->osrlFile = ""; 
	osoptions->osrl = ""; 
	osoptions->insListFile = ""; 
	osoptions->insList = ""; 
	osoptions->serviceLocation = ""; 
	osoptions->serviceMethod = ""; 
	osoptions->osplInputFile = ""; 
	osoptions->osplOutputFile = ""; 
	osoptions->mpsFile = ""; 
	osoptions->nlFile = ""; 
	osoptions->solverName = ""; 
	osoptions->os = false; 
	osoptions->browser = ""; 
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
		if(osoptions->configFile != ""){
			configFileName = osoptions->configFile;
			cout << "configFileName = " << configFileName << endl;
			std::string osolfileOptions = fileUtil->getFileAsString( &configFileName[ 0]);
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
		if(osoptions->configFile != "") cout << "Config file = " << osoptions->configFile << endl;
		if(osoptions->osilFile != "") cout << "OSiL file = " << osoptions->osilFile << endl;
		if(osoptions->osolFile != "") cout << "OSoL file = " << osoptions->osolFile << endl;
		if(osoptions->osrlFile != "") cout << "OSrL file = " << osoptions->osrlFile << endl;
		if(osoptions->insListFile != "") cout << "Instruction List file = " << osoptions->insListFile << endl;
		if(osoptions->osplInputFile != "") cout << "OSpL Input file = " << osoptions->osplInputFile << endl;
		if(osoptions->serviceMethod != "") cout << "Service Method = " << osoptions->serviceMethod << endl;
		if(osoptions->mpsFile != "") cout << "MPS File Name = " << osoptions->mpsFile << endl;
		if(osoptions->nlFile != "") cout << "NL File Name = " << osoptions->nlFile << endl;
		if(osoptions->solverName != ""){ 
			cout << "Solver Name = " << osoptions->solverName << endl;
		}
		else{
			if(osoptions->osolFile != "" && osoptions->osolFile !=""){
			osoptions->solverName  =    &getSolverName( &osoptions->osolFile[0] )[0];
			}
		}
		if(osoptions->browser != "") cout << "Browser Value = " << osoptions->browser << endl;
		if( osoptions->os == true ) cout << "OS = " << osoptions->os << endl;
		// get the data from the files
		fileUtil = new FileUtil();
		try{	
			if(osoptions->insListFile != "") osoptions->insList = fileUtil->getFileAsChar( &osoptions->insListFile[0]);
			if(osoptions->osolFile != "") osoptions->osol = fileUtil->getFileAsChar( &osoptions->osolFile[0]);
			if(osoptions->osilFile != ""){
				//this takes precedence over what is in the OSoL file
				 osoptions->osil = fileUtil->getFileAsString( &osoptions->osilFile[0]);
			}
			else{
				 if(osoptions->osolFile != "") osoptions->osil = fileUtil->getFileAsString( &getInstanceLocation( osoptions->osol)[ 0] );
			}
			if(osoptions->osplInputFile != "") osoptions->osplInput = fileUtil->getFileAsChar( &osoptions->osplInputFile[0]);
			if(osoptions->osplOutputFile != "") osoptions->osplOutput = fileUtil->getFileAsChar( &osoptions->osplOutputFile[0]);
			 cout << "Service Location Before IF= " << osoptions->serviceLocation << endl;
			if(osoptions->serviceLocation != ""){
				 cout << "Service Location = " << osoptions->serviceLocation << endl;
			}
			else{
				cout << "Service Location after else = " << osoptions->serviceLocation << endl;
				if( getServiceURI( osoptions->osol) != ""){
					osoptions->serviceLocation = &getServiceURI( osoptions->osol)[0];
					cout << "Service Location = " << osoptions->serviceLocation << endl;
				}
			}
		}
		catch(const ErrorClass& eclass){
			//cout << eclass.errormsg <<  endl;
			cout << "could not open file properly" << endl;
			return 0;
		}	
		// now call the correct serviceMethod
		// solve is the default
		if( osoptions->serviceMethod == "") solve();
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
		// call a method here to get OSiL if we have an nl or mps file
		if(osoptions->osil == ""){
			//we better have an nl file present or mps file or osol file
			if(osoptions->nlFile != ""){
				getOSiLFromNl();
			}
			else{
				if(osoptions->mpsFile != ""){
					getOSiLFromMps();
				}
				else{// need an osol file with an instanceLocation specified
					if( osoptions->osol.find( "<instanceLocation") == std::string::npos)
						throw ErrorClass("solve called and no osil, osol with osil specified, nl, or mps file given");
				}
			}
		}
		// now solve either remotely or locally
		if( (osoptions->serviceLocation != "" && osoptions->serviceLocation != "")  ){
			// place a remote call
			osagent = new OSSolverAgent( osoptions->serviceLocation );
			osrl = osagent->solve(osoptions->osil  , osoptions->osol);
			if(osoptions->osrlFile != "") fileUtil->writeFileFromString(osoptions->osrlFile, osrl);
			else cout << osrl << endl;
		}
		else{
			// solve locally
			// add IPOPT
			if(osoptions->solverName == "" ){
				string sSolverName = "cbc";
				osoptions->solverName = &sSolverName[0];
			}
			if( osoptions->solverName.find( "ipopt") != std::string::npos) {
				// we are requesting the Ipopt solver
				bool bIpoptIsPresent = false;
				#ifdef COIN_HAS_IPOPT
				bIpoptIsPresent = true;
				SmartPtr<IpoptSolver> ipoptSolver  = new IpoptSolver();	
				ipoptSolver->osol = osoptions->osol;
				ipoptSolver->osil = osoptions->osil;
				ipoptSolver->osinstance =NULL;
				ipoptSolver->solve();
				osrl = ipoptSolver->osrl ;
				#endif
				if(bIpoptIsPresent == false) throw ErrorClass( "the Ipopt solver requested is not present");
			}
			else{
				if( osoptions->solverName.find( "lindo") != std::string::npos) {
					// we are requesting the Lindo solver
					bool bLindoIsPresent = false;
					#ifdef COIN_HAS_LINDO
					bLindoIsPresent = true;
					std::cout << "calling the LINDO Solver " << std::endl;
					solverType = new LindoSolver();
					std::cout << "DONE calling the LINDO Solver " << std::endl;
					#endif
					if(bLindoIsPresent == false) throw ErrorClass( "the Lindo solver requested is not present");
				}
				else{ 
					if( osoptions->solverName.find( "clp") != std::string::npos){
						solverType = new CoinSolver();
						solverType->sSolverName = "clp";
					}
					else{
						if( osoptions->solverName.find( "cbc") != std::string::npos){
							solverType = new CoinSolver();
							solverType->sSolverName = "cbc";
						}
						else{
							if( osoptions->solverName.find( "cplex") != std::string::npos){
								solverType = new CoinSolver();
								solverType->sSolverName = "cplex";
							}
							else{
								if( osoptions->solverName.find( "glpk") != std::string::npos){
									solverType = new CoinSolver();
									solverType->sSolverName = "glpk";
								}
								else{
									if( osoptions->solverName.find( "dylp") != std::string::npos){
										solverType = new CoinSolver();
										solverType->sSolverName = "dylp";
									}
									else{
										if( osoptions->solverName.find( "symphony") != std::string::npos){
											solverType = new CoinSolver();
											solverType->sSolverName = "symphony";
										}
										else{
											throw ErrorClass( "a supported solver is not present");
										}
									}
								}
							}
						}
					}
				}
			}
			if( osoptions->solverName.find( "ipopt") == std::string::npos){
				solverType->osil = osoptions->osil;
				solverType->osol = osoptions->osol;
				solverType->osinstance = NULL;
				cout << "CALL SOLVER" << endl;
				solverType->solve();
				osrl = solverType->osrl;
				cout << "RETURN FROM SOLVER" << endl;
			}
			if(osoptions->osrlFile != ""){
				fileUtil->writeFileFromString(osoptions->osrlFile, osrl);
				//const char *ch1 = "/Applications/Firefox.app/Contents/MacOS/firefox  ";
				if(osoptions->browser != ""){
					std::string str = osoptions->browser + "  " +  osoptions->osrlFile;
					const char *ch = &str[ 0];
					std::system( ch );
				}
			}
			else cout << osrl << endl;
		}
	}
	catch(const ErrorClass& eclass){
		std::cout <<  eclass.errormsg << std::endl;
		if(osoptions->osrlFile != "") fileUtil->writeFileFromString(osoptions->osrlFile,  eclass.errormsg);
	}	
}//end solve

void getJobID(){
	std::string jobID = "";
	OSSolverAgent* osagent = NULL;
	FileUtil *fileUtil = NULL;
	fileUtil = new FileUtil();
	try{
		if(osoptions->serviceLocation != ""){
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
		if(osoptions->serviceLocation != ""){
			osagent = new OSSolverAgent( osoptions->serviceLocation );
			osplOutput = osagent->knock(osoptions->osplInput,  osoptions->osol);
			if(osoptions->osplOutputFile != "") fileUtil->writeFileFromString(osoptions->osplOutputFile, osplOutput);
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
	bool bSend = false;
	std::string jobID = "";
	OSSolverAgent* osagent = NULL;
	// first get the jobID
	std::string sOSoL = "<?xml version=\"1.0\" encoding=\"UTF-8\"?> <osol xmlns=\"os.optimizationservices.org\" xmlns:xs=\"http://www.w3.org/2001/XMLSchema\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:schemaLocation=\"os.optimizationservices.org http://www.optimizationservices.org/schemas/OSoL.xsd\"><general> </general></osol>";
	unsigned int iStringpos;
	try{
		// call a method here to get OSiL if we have an nl or mps file
		if(osoptions->osil == ""){
			//we better have an osil file present or mps file
			if(osoptions->nlFile != ""){
				getOSiLFromNl();
			}
			else{
				if(osoptions->mpsFile != ""){
					getOSiLFromMps();
				}
				else{
					throw ErrorClass("solve called and no osil, nl, or mps file given");
				}
			}
		}
		if(osoptions->serviceLocation != ""){
			osagent = new OSSolverAgent( osoptions->serviceLocation );
			// check to see if there is an osol 
			if(osoptions->osolFile == ""){
				// get a jobID
				jobID =  osagent->getJobID( sOSoL) ;
				// insert the jobID into the default osol
				iStringpos = sOSoL.find("</general");
				cout << "startel ==  " << iStringpos << endl;
				if(iStringpos != std::string::npos) sOSoL.insert(iStringpos, "<jobID>" + jobID+ "</jobID>");
			}
			else{
				// we have an osol file use it for the sOSoL
				sOSoL = osoptions->osol;
				// see if we have a jobID
				iStringpos = sOSoL.find("<jobID");
				// if we have a jobId send out the osil and osol files
				if(iStringpos == std::string::npos){
					// get a jobID and insert it
					jobID =  osagent->getJobID( osoptions->osol) ;
					iStringpos = sOSoL.find("</general");
					if(iStringpos != std::string::npos) sOSoL.insert(iStringpos, "<jobID>" + jobID+ "</jobID>");
				}
			}
			cout << sOSoL << endl;
			bSend = osagent->send(osoptions->osil, sOSoL);
			if(bSend == true) cout << "send is true" << endl;
			else cout << "send is false" << endl;
		}
		else{
			throw ErrorClass( "please specify service location (url)" );
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
		if(osoptions->serviceLocation != ""){
			osagent = new OSSolverAgent( osoptions->serviceLocation );
			std::cout << "HERE ARE THE OSOL OPTIONS " <<  osoptions->osol << std::endl;
			osrl = osagent->retrieve( osoptions->osol);
			if(osoptions->osrlFile != "") {
				fileUtil->writeFileFromString(osoptions->osrlFile, osrl); 
				if(osoptions->browser != ""){
					std::string str = osoptions->browser + "  " + osoptions->osrlFile ;
					const char *ch = &str[ 0];
					std::system( ch );
				}
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
		if(osoptions->serviceLocation != ""){
			osagent = new OSSolverAgent( osoptions->serviceLocation );
			osplOutput = osagent->kill( osoptions->osol);
			if(osoptions->osplOutputFile != "") fileUtil->writeFileFromString(osoptions->osplOutputFile, osplOutput);
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

void getOSiLFromNl(){
	try{
		#ifdef COIN_HAS_ASL
		OSnl2osil *nl2osil = NULL;
		nl2osil = new OSnl2osil( osoptions->nlFile);
		nl2osil->createOSInstance() ;
		OSiLWriter *osilwriter = NULL;
		osilwriter = new OSiLWriter();
		std::string osil;
		osil = osilwriter->writeOSiL(  nl2osil->osinstance) ;
		osoptions->osil = osil;
		delete nl2osil;
		nl2osil = NULL;
		delete osilwriter;
		osilwriter = NULL; 	
		#else
		throw("trying to convert nl to osil without AMPL ASL configured");
		#endif
	}
	catch(const ErrorClass& eclass){
		std::cout << eclass.errormsg <<  std::endl;
	}	
}//getOSiLFromNl


void getOSiLFromMps(){
	try{
		OSmps2osil *mps2osil = NULL;
		mps2osil = new OSmps2osil( osoptions->mpsFile);
		mps2osil->createOSInstance() ;
		OSiLWriter *osilwriter = NULL;
		osilwriter = new OSiLWriter();
		std::string osil;
		osil = osilwriter->writeOSiL(  mps2osil->osinstance) ;
		osoptions->osil = osil;
		delete mps2osil;
		mps2osil = NULL;
		delete osilwriter;
		osilwriter = NULL; 	
	}
	catch(const ErrorClass& eclass){
		std::cout << eclass.errormsg <<  std::endl;
	}	
	
}//getOSiLFromMps

string getServiceURI( std::string osol){
	if(osol == "") return osol;
	unsigned int pos2;
	unsigned int pos1 = osol.find( "<serviceURI");
	if(pos1 != std::string::npos){
		// get the end of the serviceURI start tag
		pos1 = osol.find(">", pos1 + 1);
		if(pos1 != std::string::npos){
			// get the start of serviceURI end tag
			pos2 = osol.find( "</serviceURI", pos1 + 1);
			if( pos2 != std::string::npos){
				// get the substring
				return osol.substr( pos1 + 1, pos2 - pos1 - 1); 
			}
			else return "";
		}
		else return "";
	}
	else return "";
}//getServiceURI

string getInstanceLocation( std::string osol){
	if(osol == "") return osol;
	unsigned int pos2;
	unsigned int pos1 = osol.find( "<instanceLocation");
	if(pos1 != std::string::npos){
		// get the end of the instanceLocation start tag
		pos1 = osol.find(">", pos1 + 1);
		if(pos1 != std::string::npos){
			// get the start of instanceLocation end tag
			pos2 = osol.find( "</instanceLocation", pos1 + 1);
			if( pos2 != std::string::npos){
				// get the substring
				return osol.substr( pos1 + 1, pos2 - pos1 - 1); 
			}
			else return "";
		}
		else return "";
	}
	else return "";
}//getInstanceLocation

string getSolverName( std::string osol){
	if(osol == "") return osol;
	unsigned int pos2;
	unsigned int pos1 = osol.find( "os_solver");
	if(pos1 != std::string::npos){
		// get the end of the instanceLocation start tag
		pos1 = osol.find(">", pos1 + 1);
		if(pos1 != std::string::npos){
			// get the start of instanceLocation end tag
			pos2 = osol.find( "</other", pos1 + 1);
			if( pos2 != std::string::npos){
				// get the substring
				return osol.substr( pos1 + 1, pos2 - pos1 - 1); 
			}
			else return "";
		}
		else return "";
	}
	else return "";
}//getSolverName





