/** @file amplClient.cpp
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
 * Please see the accompanying LICENSE file in OS root directory for terms.
 * 
 * This executable is designed to act as a "solver" for AMPL. It can be
 * used to solve problems locally or on a remote server.  For example,
 * to solve a problem locally, start AMPL. We assume that the model is
 * hs71.mod. Execute the following sequence of commands:
 * 
 * model hs71.mod;  <br />
 * option solver OSAmplClient; <br />
 * option OSAmplClient_options "solver bonmin"; <br />
 * write gtestfile; <br />
 * solve; <br />
 * display x1; <br />
 * you should get:
 * 
 * x1 = 1
 * 
 * display x2;  <br />
 * you should get:
 * 
 * x2 = 4.743
 * 
 * in general, specify options to the OSAmplclient solver by using the AMPL command OSAmplClient\_options
 *
 * \item there are three possible options to specify:
 *
 * \begin{itemize}
 *
 * \item the name of the solver using the  {\bf solver} option, valid values for this option  are {\tt clp},
 * {\tt cbc},  {\tt dylp},  {\tt ipopt}, {\tt bonmin},   {\tt couenne},  {\tt symphony}, and {\tt vol}.   
 *
 *
 * \item the location of the remote server using the {\bf serviceLocation} option
 *
 * \item the location of the option file using  the {\bf optionFile} option
 *
 * \end{itemize}
 *
 * if no options are specified using {\bf OSAmplClient\_options},   by default, for continuous
 * linear models  clp is used. For continuous nonlinear models ipopt is used. 
 * For mixed-integer linear models (MIP),   cbc is used. For mixed-integer nonlinear models 
 * bonmin is used.  All solvers are invoked locally.
 * 
 */

#include "OSCoinSolver.h"
#include "OSConfig.h"
#include "OSnl2osil.h"
#include "OSiLReader.h"
#include "OSrLReader.h"
#include "OSiLWriter.h"
#include "OSrLWriter.h"
#include "OSInstance.h"
#include "OSResult.h"
#include "OSOption.h"
#include "OSoLReader.h"
#include "OSoLWriter.h"
#ifdef COIN_HAS_LINDO    
#include "OSLindoSolver.h"
#endif 
#ifdef COIN_HAS_IPOPT    
#include "OSIpoptSolver.h"
#endif  
#ifdef COIN_HAS_BONMIN    
#include "OSBonminSolver.h"
#endif 
#ifdef COIN_HAS_COUENNE    
#include "OSCouenneSolver.h"
#endif
#include "OSFileUtil.h"
#include "OSDefaultSolver.h"
#include "OSSolverAgent.h"
#include "OShL.h"
#include "OSErrorClass.h"
#include "CoinError.hpp"

#include <sstream>

#ifdef HAVE_CSTRING
# include <cstring>
#else
# ifdef HAVE_STRING_H
#  include <string.h>
# else
#  error "don't have header file for string"
# endif
#endif

#include "CoinError.hpp"
#include "CoinHelperFunctions.hpp"


#include <iostream>
//AMPL includes must be last.
#include <asl.h>
using std::cerr;
using std::cout;
using std::endl;
using std::ostringstream;

void getAmplClientOptions(char *options, std::string *solverName, 
std::string *optionFile, std::string *serviceLocation);
int main(int argc, char **argv)
{
	WindowsErrorPopupBlocker();
	char *stub;
	// set AMPL structures
	ASL *asl;
	asl = ASL_alloc(ASL_read_fg);
    stub = argv[1];
	jac0dim((char*)stub, (fint)strlen(stub));
	OSnl2osil *nl2osil = NULL;
	//initialize object with stub -- the nl file
	nl2osil = new OSnl2osil( stub);
	// create an osinstance object
	OSInstance *osinstance;
	std::cout << " call nl2osil" << std::endl;
	try{
		nl2osil->createOSInstance() ;
	}
	catch(const ErrorClass& eclass){
		std::cout << eclass.errormsg << std::endl;
		return 0;
	}
	std::cout << " return from  nl2osil" << std::endl;
	osinstance = nl2osil->osinstance;
	std::cout << " osinstance created" << std::endl;
	// turn the osinstance into osil 
	// not needed for a local solve
	// send an osinstance object in memory
	/**  amplclient_option: 
	 *   1. solver:
	 *		possible values - clp, glpk, cplex, cplex, lindo
	 *   2. location:
	 *      possible values - NULL (empty) or url of the solver service
	 *      
	 */
	char *amplclient_options = NULL;
	//char *agent_address = NULL;
	char *solver_option = NULL;
	// set solver type default to clp
	DefaultSolver *solverType  = NULL;	
	OSrLReader *osrlreader = NULL;
	OSrLWriter *osrlwriter;
	osrlwriter = new OSrLWriter();
	OSResult *osresult = NULL;
	std::string osrl = "";
	std::string sSolverName = "";
	std::string osol = "";
	std::string serviceLocation = "";
	//char *URL = NULL;
	//char delims[] = " ";

	
	
	// get the solver set by AMPL
	amplclient_options = getenv("OSAmplClient_options");
	if( amplclient_options != NULL){
		cout << "HERE ARE THE AMPLCLIENT OPTIONS " <<   amplclient_options << endl;
		getAmplClientOptions(amplclient_options, &sSolverName, &osol, &serviceLocation);
	}
	if(sSolverName.size() == 0){
		std::cout << "DETERMINE THE DEFAULT SOLVER " <<    endl;
		if(osinstance->getNumberOfIntegerVariables() + osinstance->getNumberOfBinaryVariables() > 0){//we have an integer program
			if( (osinstance->getNumberOfNonlinearExpressions() > 0)
			   || (osinstance->getNumberOfQuadraticTerms() > 0) ){ // we are nonlinear and integer
				sSolverName = "bonmin";
			}else{//we are linear integer 
				sSolverName = "cbc";
			}
		}else{// we have a continuous problem
			if( (osinstance->getNumberOfNonlinearExpressions() > 0)
			   || (osinstance->getNumberOfQuadraticTerms() > 0) ){ // we are nonlinear and continuous
				sSolverName = "ipopt";
			}else{//we have linear program 
				sSolverName = "clp";
			}
		}
	}
	
	std::cout << " solver Name = " << sSolverName << std::endl;
	std::cout << " solver Options = " << osol << std::endl;
	
	try{
		if( (amplclient_options == NULL)  && (sSolverName.size() == 0) ) throw ErrorClass( "a local solver was not specified in AMPL option");
		else{// don't do this if we have specify a remote location
			if(serviceLocation.size() == 0 ){
				if( sSolverName == "lindo") {
					// we are requesting the Lindo solver
					bool bLindoIsPresent = false;
					#ifdef COIN_HAS_LINDO
					bLindoIsPresent = true;
					solverType = new LindoSolver();
					solverType->sSolverName = "lindo";
					#endif
					if(bLindoIsPresent == false) throw ErrorClass( "the Lindo solver requested is not present");
				}
				else{ 
					if( sSolverName == "clp" ){
						if( solver_option != NULL) cout << "HERE ARE THE Clp SOLVER OPTIONS " <<   solver_option << endl;
						solverType = new CoinSolver();
						solverType->sSolverName = "clp";
					}
					else{
						if( sSolverName == "cbc"){

							solverType = new CoinSolver();
							solverType->sSolverName = "cbc";
						}
						else{
							if( sSolverName == "cplex"){
								bool bCplexIsPresent = false;
								#ifdef COIN_HAS_CPX
									bCplexIsPresent = true;
									solverType = new CoinSolver();
									solverType->sSolverName = "cplex";
								#endif
									if(bCplexIsPresent == false) throw ErrorClass( "the Cplex solver requested is not present");
							}
							else{
								if( sSolverName == "glpk"){
									bool bGlpkIsPresent = false;
									#ifdef COIN_HAS_GLPK
										bGlpkIsPresent = true;
										solverType = new CoinSolver();
										solverType = new CoinSolver();
										solverType->sSolverName = "glpk";
									#endif
									if(bGlpkIsPresent == false) throw ErrorClass( "the Glpk solver requested is not present");
								}
								else{
									if( sSolverName == "ipopt"){
										bool bIpoptIsPresent = false;
										#ifdef COIN_HAS_IPOPT
											bIpoptIsPresent = true;
											solverType = new IpoptSolver();
											solverType->sSolverName = "ipopt";
										#endif
										if(bIpoptIsPresent == false) throw ErrorClass( "the Ipopt solver requested is not present");
									}
									else{
										if( sSolverName == "symphony" ){
											bool bSymIsPresent = false;
											#ifdef COIN_HAS_SYMPHONY
												bSymIsPresent = true; 
												solverType = new CoinSolver();
												solverType->sSolverName = "symphony";
											#endif
											if(bSymIsPresent == false) throw ErrorClass( "the SYMPHONY solver requested is not present");
										}
										else{
											if( sSolverName == "dylp"){
												bool bDyLPIsPresent = false;
												#ifdef COIN_HAS_DYLP
													bDyLPIsPresent = true;
													solverType = new CoinSolver();
													solverType->sSolverName = "dylp";
												#endif
												if(bDyLPIsPresent == false) throw ErrorClass( "the DyLP solver requested is not present");
											}						
											else{
												if( sSolverName == "bonmin" ){
													bool bBonminIsPresent = false;
													#ifdef COIN_HAS_BONMIN
														bBonminIsPresent = true;
														solverType = new BonminSolver();
														solverType->sSolverName = "bonmin";
													#endif
													if(bBonminIsPresent == false) throw ErrorClass( "the Bonmin solver requested is not present");												
												}
												else{
													if( sSolverName == "couenne"){
														bool bCouenneIsPresent = false;
														#ifdef COIN_HAS_COUENNE
															bCouenneIsPresent = true;
															solverType = new CouenneSolver();
															solverType->sSolverName = "counenne";
														#endif
														if(bCouenneIsPresent == false) throw ErrorClass( "the Couenne solver requested is not present");	
													}
													else{
														throw ErrorClass( "a supported solver has not been selected");
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
		}
		// do a local solve
		//if( ( solver_option == NULL) || (strstr(solver_option, "service") == NULL)  ){
		if( serviceLocation.size() == 0 ){
			solverType->osol = osol;
			//std::cout << osol << std::endl;
			OSiLWriter osilwriter;
			std::cout << "WRITE THE INSTANCE" << std::endl;
			std::cout << osilwriter.writeOSiL( osinstance) << std::endl;
			std::cout << "DONE WRITE THE INSTANCE" << std::endl;

			solverType->osinstance = osinstance;
			solverType->buildSolverInstance();
			solverType->solve();
			osrl = solverType->osrl ;
			//std::cout << osrl << std::endl;
		}
	}
	catch(const ErrorClass& eclass){
		osresult = new OSResult();	
		osresult->setGeneralMessage( eclass.errormsg);
		osresult->setGeneralStatusType( "error");
		osrl = osrlwriter->writeOSrL( osresult);
		std::cout  << osrl << std::endl;
		osrl = " ";
		write_sol(const_cast<char*>(osrl.c_str()), NULL, NULL, NULL);
		delete osresult;
		return 0;
	}
	try{
		// do the following for a remote solve
		if( serviceLocation.size()  > 0){
			OSSolverAgent* osagent = NULL;
			OSiLWriter *osilwriter = NULL;
			osilwriter = new OSiLWriter();
			std::string  osil = osilwriter->writeOSiL( osinstance);
			////
		
			//agent_address = strstr(solver_option, "service");
			//agent_address += 7;
			//URL = strtok( agent_address, delims );
			//std::string sURL = URL;
			///
			// we should be pointing to the start of the address
			osagent = new OSSolverAgent( serviceLocation);
			cout << "Place remote synchronous call: " + serviceLocation << endl << endl << endl;
			//cout << osol << endl;
			osrl = osagent->solve(osil, osol);
			if (osrl.size() == 0) throw ErrorClass("Nothing was returned from the server, please check service address");
			delete osilwriter;
			delete osagent; 
		} 
	}
	catch(const ErrorClass& eclass){
		osresult = new OSResult();
		osresult->setGeneralMessage( eclass.errormsg);
		osresult->setGeneralStatusType( "error");
		osrl = osrlwriter->writeOSrL( osresult);	
		write_sol(const_cast<char*>(osrl.c_str()), NULL, NULL, NULL);
		delete osresult;
		return 0;
	}
	try{ 
		//need_nl = 0;
		std::string sResultFileName = "solutionResult.osrl";
		FileUtil *fileUtil;
		fileUtil = new FileUtil();
		fileUtil->writeFileFromString(sResultFileName, osrl);
		delete fileUtil;
		//cout << "WRITE THE SOLUTION BACK INTO AMPL" <<endl;
		string::size_type pos1 = osrl.find( "error");
		if(pos1 == std::string::npos){
			std::string sReport = "model was solved";
			std::cout << sReport << std::endl;
			//std::cout << osrl << std::endl;
			osrlreader = new OSrLReader();
			osresult = osrlreader->readOSrL( osrl);
			// do the following so output is not written twice
			// see page 23 of hooking solver to AMPL
			//need_nl = printf( sReport.c_str());

			//
			sReport = " ";
			int i;
			int vecSize;
			double *x;
			double *y;
			int numVars = osresult->getVariableNumber();
			int numCons = osresult->getConstraintNumber();
			x = new double[ numVars];
			y = new double[ numCons];
			
			std::vector<IndexValuePair*> primalValPair;
			std::vector<IndexValuePair*> dualValPair;
			dualValPair = osresult->getOptimalDualVariableValues( 0);
			primalValPair = osresult->getOptimalPrimalVariableValues( 0);
			
			for(i = 0; i < numVars; i++){
				x[ 0] = 0.0;
			}
			vecSize = primalValPair.size();
			for(i = 0; i < vecSize; i++){
				x[ primalValPair[i]->idx ] = primalValPair[i]->value;
				//std::cout << "index =  " <<   primalValPair[i]->idx  << std::endl;
				//std::cout << "value =  " <<   primalValPair[i]->value  << std::endl;
			}
			
			
			for(i = 0; i < numCons; i++){
				y[ 0] = 0.0;
			}
			vecSize = dualValPair.size();
			for(i = 0; i < vecSize; i++){
				y[ dualValPair[i]->idx ] = dualValPair[i]->value;  
				//std::cout << "index =  " <<   primalValPair[i]->idx  << std::endl;
				//std::cout << "value =  " <<   primalValPair[i]->value  << std::endl;
			}
			

			
			write_sol(  const_cast<char*>(sReport.c_str()),  x, y , NULL);
			
			delete osrlreader;
			osrlreader = NULL;
			//delete[] x;
			//x = NULL;
			//delete y;
			//y = NULL;
		}else{
			// do the following so output is not written twice
			// see page 23 of hooking solver to AMPL
			std::cout  << osrl << std::endl;
			osrl = " ";
			//
			write_sol(  const_cast<char*>(osrl.c_str()), NULL, NULL, NULL);
			need_nl = 0;
		}
		//cout << "DONE WRITING THE SOLUTION BACK INTO AMPL" <<endl;
	}
	catch(const ErrorClass& eclass){
		cout << "There was an error parsing the OSrL" << endl << eclass.errormsg << endl << endl;
	}
	if(  solverType != NULL ){
		//cout << "TRY TO DELETE solverType" <<endl;
		delete solverType;
		//cout << "solverType JUST DELETED" <<endl;
		solverType = NULL;
	}
	delete osrlwriter;
	//cout << "osrlwriter JUST DELETED" <<endl;
	osrlwriter = NULL;
	delete nl2osil;
	//cout << "nl2osil JUST DELETED" <<endl;
	nl2osil = NULL;
	ASL_free(&asl);
	return 0; 
} // end main


void getAmplClientOptions(char *amplclient_options, std::string *solverName, 
	std::string *solverOptions, std::string *serviceLocation){

	
	std::string amplOptions = "";
	std::ostringstream outStr; 
	std::string::size_type  pos1;
	std::string::size_type  pos2;
	std::string osolFileName = "";
	FileUtil *fileUtil = NULL;

	size_t i = 0;
	size_t n = strlen( amplclient_options);
	try{
		while( i < n){
			//std::cout << amplclient_options[ i] << std::endl;
			if( amplclient_options[ i]  == ' '){
				outStr << ',';
				i++;
				while( amplclient_options[ i] == ' '  ){
					i++;
				}
			}
			else{
				outStr << amplclient_options[ i];
				i++;
			}

		}
		//end with a comma
		outStr << ',';
		amplOptions = outStr.str();
		
		
		// see if a solver has been specified
		pos1 = amplOptions.find( "solver");
		if(pos1 != std::string::npos){
			//we have a solver specified
			pos1 += 6;
			//std::cout << "position 1 = " << pos1 << std::endl;
			// we are at at the comma after solver
			pos2 = amplOptions.find( ",", pos1 + 1);
			//std::cout << "position 2 = " << pos2 << std::endl;
			if(pos2 != std::string::npos){
				//std::cout << "solverName = " <<  amplOptions.substr(pos1 + 1, pos2-pos1 - 1) << std::endl;
				*solverName = amplOptions.substr(pos1 + 1, pos2-pos1 - 1);
				
			}
		}
		
		
		// see if an option file has been specified
		pos1 = amplOptions.find( "optionFile");
		if(pos1 != std::string::npos){
			//we have a option file specified  specified
			pos1 += 10;
			//std::cout << "position 1 = " << pos1 << std::endl;
			// we are at at the comma after optionfile
			pos2 = amplOptions.find( ",", pos1 + 1);
			//std::cout << "position 2 = " << pos2 << std::endl;
			if(pos2 != std::string::npos){
				//std::cout << "optionFile Name = " <<  amplOptions.substr(pos1 + 1, pos2-pos1 - 1) << std::endl;
				osolFileName = amplOptions.substr(pos1 + 1, pos2-pos1 - 1);
			}
		}
		
		//now go ahead and read the OSoL file if specified
		
		if( osolFileName.size() > 0 ){
			fileUtil = new FileUtil();
			*solverOptions  = fileUtil->getFileAsString( osolFileName.c_str());
			delete fileUtil;
			fileUtil = NULL;
		}else{ // go ahead and create the osol string
			*solverOptions = "<?xml version=\"1.0\" encoding=\"UTF-8\"?> <osol xmlns=\"os.optimizationservices.org\" xmlns:xs=\"http://www.w3.org/2001/XMLSchema\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:schemaLocation=\"os.optimizationservices.org http://www.optimizationservices.org/schemas/2.0/OSoL.xsd\"></osol>";
		}
		
		OSOption *osoption = NULL;
		OSoLReader *osolreader = NULL;
		osolreader = new OSoLReader();
		osoption = osolreader->readOSoL( *solverOptions);	
		OSoLWriter *osolwriter = NULL;
		osolwriter = new OSoLWriter();	
		
		// if a solver is specified it overrides what is in the osoptions file, otherwise,
		// see if we can get it from the solver option file
		if( (*solverName).size() == 0 ){
			*solverName = osoption->getSolverToInvoke();
		}else{ // insert this solver
			osoption->setSolverToInvoke( *solverName );
			*solverOptions = osolwriter->writeOSoL(  osoption);
		}

		
		// see if a serviceLocation has been specified
		pos1 = amplOptions.find( "serviceLocation");
		if(pos1 != std::string::npos){
			//we have a serviceLocation specified
			pos1 += 15;
			//std::cout << "position 1 = " << pos1 << std::endl;
			// we are at at the comma after solver
			pos2 = amplOptions.find( ",", pos1 + 1);
			//std::cout << "position 2 = " << pos2 << std::endl;
			if(pos2 != std::string::npos){
				//std::cout << "solverName = " <<  amplOptions.substr(pos1 + 1, pos2-pos1 - 1) << std::endl;
				*serviceLocation = amplOptions.substr(pos1 + 1, pos2-pos1 - 1);
				
			}
		}
		
		// if a serviceLocation is specified it overrides what is in the osoptions file, otherwise,
		// see if we can get it from the solver option file
		if( (*serviceLocation).size() == 0 ){
			*serviceLocation = osoption->getServiceURI();
		}		

		delete osolreader;
		osolreader = NULL;
		delete osolwriter;
		osolwriter = NULL;
		
	}//end try
	catch(const ErrorClass& eclass){
		cout << "There was an error processing OSAmplClient options: " << endl << eclass.errormsg << endl << endl;
		throw ErrorClass( eclass.errormsg) ;
	}	
}//getAmplClientOptions
