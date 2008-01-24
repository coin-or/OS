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
 * option OSAmplClient_options "solver ipopt"; <br />
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
 * now if you wanted to call a remote OS solver do something like: 
 * 
 *option ipopt_options "http://128.135.130.17:8080/os/OSSolverService.jws"; 
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
#ifdef COIN_HAS_LINDO    
#include "OSLindoSolver.h"
#endif 
#ifdef COIN_HAS_IPOPT    
#include "OSIpoptSolver.h"
#endif  
#include "OSFileUtil.h"
#include "OSDefaultSolver.h"
#include "OSSolverAgent.h"
#include "OShL.h"
#include "OSErrorClass.h"
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


//AMPL includes must be last.
#include <asl.h>
using std::cerr;
using std::cout;
using std::endl;


int main(int argc, char **argv)
{
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
	char *agent_address = NULL;
	char *solver_option = NULL;
	// set solver type default to clp
	DefaultSolver *solverType  = NULL;	
	OSrLReader *osrlreader = NULL;
	osrlreader = new OSrLReader();
	OSrLWriter *osrlwriter;
	osrlwriter = new OSrLWriter();
	OSResult *osresult = NULL;
	std::string osrl = "";
	std::string sSolverName = "";
	// note that default solver is coin and default subSolver is Cbc
	std::string osol = "<?xml version=\"1.0\" encoding=\"UTF-8\"?> <osol xmlns=\"os.optimizationservices.org\" xmlns:xs=\"http://www.w3.org/2001/XMLSchema\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:schemaLocation=\"os.optimizationservices.org http://www.optimizationservices.org/schemas/OSoL.xsd\"></osol>";
	
	char *num_procOption = NULL;
	char *num_processors = NULL;
	char *URL = NULL;
	char delims[] = " ";
	
	// get the solver set by AMPL
	amplclient_options = getenv("OSAmplClient_options");
	if( amplclient_options != NULL) cout << "HERE ARE THE AMPLCLIENT OPTIONS " <<   amplclient_options << endl;
	try{
		if(amplclient_options == NULL ) throw ErrorClass( "a local solver was not specified in AMPL option");
		else{
			if( strstr(amplclient_options, "lindo") != NULL) {
				// we are requesting the Lindo solver
				bool bLindoIsPresent = false;
				#ifdef COIN_HAS_LINDO
				sSolverName = "lindo";
				bLindoIsPresent = true;
				solver_option = getenv("lindo_options");
				if(( solver_option == NULL) ||  strstr(solver_option, "service") == NULL)  solverType = new LindoSolver();
				#endif
				if(bLindoIsPresent == false) throw ErrorClass( "the Lindo solver requested is not present");
			}
			else{ 
				if( strstr(amplclient_options, "clp") != NULL){
					if( solver_option != NULL) cout << "HERE ARE THE Clp SOLVER OPTIONS " <<   solver_option << endl;
					sSolverName = "clp";
					solver_option = getenv("clp_options");
					if( ( solver_option == NULL) || (strstr(solver_option, "service") == NULL) ){
						solverType = new CoinSolver();
						solverType->sSolverName = "clp";
					}
				}
				else{
					if( strstr(amplclient_options, "cbc") != NULL){
						sSolverName = "cbc";
						solver_option = getenv("cbc_options");
						if( solver_option != NULL) cout << "HERE ARE THE Cbc SOLVER OPTIONS " <<   solver_option << endl;
						if( ( solver_option == NULL) || (strstr(solver_option, "service") == NULL)){
							solverType = new CoinSolver();
							solverType->sSolverName = "cbc";
						}
					}
					else{
						if( strstr(amplclient_options, "cplex") != NULL){
							bool bCplexIsPresent = false;
							#ifdef COIN_HAS_CPX
								bCplexIsPresent = true;
								sSolverName = "cplex";
								solver_option = getenv("cplex_options");
								if( solver_option != NULL) cout << "HERE ARE THE Cplex SOLVER OPTIONS " <<   solver_option << endl;
								if(  ( solver_option == NULL) ||  (strstr(solver_option, "service") == NULL)){
									solverType = new CoinSolver();
									solverType->sSolverName = "cplex";
								}
							#endif
								if(bCplexIsPresent == false) throw ErrorClass( "the Cplex solver requested is not present");
						}
						else{
							if( strstr(amplclient_options, "glpk") != NULL){
								bool bGlpkIsPresent = false;
								#ifdef COIN_HAS_GLPK
									bGlpkIsPresent = true;
									solverType = new CoinSolver();
									sSolverName = "glpk";
									solver_option = getenv("glpk_options");
									if( solver_option != NULL) cout << "HERE ARE THE Glpk SOLVER OPTIONS " <<   solver_option << endl;
									if( ( solver_option == NULL) || (strstr(solver_option, "service") == NULL)){
										solverType = new CoinSolver();
										solverType->sSolverName = "glpk";
									}
								#endif
								if(bGlpkIsPresent == false) throw ErrorClass( "the Glpk solver requested is not present");
							}
							else{
								if( strstr(amplclient_options, "ipopt") != NULL){
									bool bIpoptIsPresent = false;
									#ifdef COIN_HAS_IPOPT
										bIpoptIsPresent = true;
										sSolverName = "ipopt";
										solver_option = getenv("ipopt_options");
										if( solver_option != NULL) cout << "HERE ARE THE Ipopt SOLVER OPTIONS " <<   solver_option << endl;
										if( ( solver_option == NULL) || (strstr(solver_option, "service") == NULL) ){
											solverType = new IpoptSolver();
											solverType->sSolverName = "ipopt";
										}
									#endif
									if(bIpoptIsPresent == false) throw ErrorClass( "the Ipopt solver requested is not present");
								}
								else{
									if( strstr(amplclient_options, "symphony") != NULL){
										bool bSymIsPresent = false;
										#ifdef COIN_HAS_SYMPHONY
											bSymIsPresent = true; 
											sSolverName = "symphony";
											solver_option = getenv("symphony_options");
											if( solver_option != NULL) cout << "HERE ARE THE SYMPHONY SOLVER OPTIONS " <<   solver_option << endl;
											// get the number of parallel parallel processors and insert into the osol
											// tokenize the symphony_options string
											// just test for now, make a subroutine later

											//
											if(solver_option != NULL){
												num_procOption = strstr(solver_option, "num_proc");
												if (num_procOption != NULL){
													// kipp -- probably should make this a subroutine in
													// case other solvers have options???
													// get the number of processors
													//move past the num_proc option name token
													num_procOption += 8;
													num_processors = strtok( num_procOption, delims );
													//
													string::size_type iStringpos;
													iStringpos = osol.find("</osol");
													std::string insertText = "<other name=\"num_proc\">";
													insertText +=  num_processors;
													insertText += "</other>";
													osol.insert(iStringpos, insertText);

												}
											}
											if(  ( solver_option == NULL) ||  (strstr(solver_option, "service") == NULL)){
												solverType = new CoinSolver();
												solverType->sSolverName = "symphony";
											}
										#endif
										if(bSymIsPresent == false) throw ErrorClass( "the SYMPHONY solver requested is not present");
									}
									else{
										if( strstr(amplclient_options, "dylp") != NULL){
											bool bDyLPIsPresent = false;
											#ifdef COIN_HAS_DYLP
												bDyLPIsPresent = true;
												sSolverName = "dylp";
												solver_option = getenv("dylp_options");
												if( solver_option != NULL) cout << "HERE ARE THE DyLP SOLVER OPTIONS " <<   solver_option << endl;
												if( ( solver_option == NULL) || (strstr(solver_option, "service") == NULL) ){
													solverType = new CoinSolver();
													solverType->sSolverName = "dylp";
												}
											#endif
											if(bDyLPIsPresent == false) throw ErrorClass( "the DyLP solver requested is not present");
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
		// do a local solve
		if( ( solver_option == NULL) || (strstr(solver_option, "service") == NULL)  ){
			solverType->osol = osol;
			//std::cout << osol << std::endl;
			solverType->osinstance = osinstance;
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
		write_sol(const_cast<char*>(osrl.c_str()), NULL, NULL, NULL);
		delete osresult;
		return 0;
	}
	try{
		// do the following for a remote solve
		if( (solver_option != NULL) && (strstr(solver_option, "service") != NULL)){
			OSSolverAgent* osagent = NULL;
			OSiLWriter *osilwriter = NULL;
			osilwriter = new OSiLWriter();
			std::string  osil = osilwriter->writeOSiL( osinstance);
			////
			agent_address = strstr(solver_option, "service");
			agent_address += 7;
			URL = strtok( agent_address, delims );
			std::string sURL = URL;
			///
			// we should be pointing to the start of the address
			osagent = new OSSolverAgent( URL);
			// if a solver option was specified put that in
			string::size_type iStringpos;
			iStringpos = osol.find("</osol");
			//std::cout <<  solverType->sSolverName << std::endl;
			std::string solverInput = "<other name=\"os_solver\">"
				+ sSolverName  + "</other>";
			osol.insert(iStringpos, solverInput);
			cout << "Place remote synchronous call: " + sURL << endl << endl << endl;
			cout << osol << endl;
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
		std::string sResultFileName = "solutionResult.osrl";
		FileUtil *fileUtil;
		fileUtil = new FileUtil();
		fileUtil->writeFileFromString(sResultFileName, osrl);
		delete fileUtil;
		cout << "WRITE THE SOLUTION BACK INTO AMPL" <<endl;
		string::size_type pos1 = osrl.find( "error");
		std::string sReport = "model was solved";
		if(pos1 == std::string::npos){
			osresult = osrlreader->readOSrL( osrl);
			write_sol(  const_cast<char*>(sReport.c_str()), 
					osresult->getOptimalPrimalVariableValues( -1), 
					osresult->getOptimalDualVariableValues( -1) , NULL);
			delete osresult;
		}else{
			write_sol(  const_cast<char*>(osrl.c_str()), NULL, NULL, NULL);
		}
		cout << "DONE WRITING THE SOLUTION BACK INTO AMPL" <<endl;
	}
	catch(const ErrorClass& eclass){
		cout << "There was an error parsing the OSrL" << endl << eclass.errormsg << endl << endl;
	}
	delete osrlreader;
	//cout << "osrlreader JUST DELETED" <<endl;
	osrlreader = NULL;
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
	return 0; 
} // end main
