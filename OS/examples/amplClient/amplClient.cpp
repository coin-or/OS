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





/*
Using AMLP with nl2fml.  Here is the sequence of AMPL commands
with the parinc problem:

If you want to name the file and not use the AMPL randomly 
generate file name, do the following:
   model hs71.mod;
   option solver amplClient;
   option amplClient_options "solver lindo";
   option lindo_options "<<any options for the lindo solver>>";
   write gtestfile;
   solve;
	
of course, replacing gtestfile with btestfile generates a binary nl file. 
// glpk is the default -- replace lindo with clp for that solver
// on the Mac it wants the nl file to be text and not binary 
solve;
display x;
//
you should get x1 = 540, x2 = 252
*/



 


#include <OsiSolverInterface.hpp>
#include <OsiClpSolverInterface.hpp> 
#include <OsiCbcSolverInterface.hpp> 
//#include <OsiGlpkSolverInterface.hpp>

#include "OSConfig.h"
#include "OSnl2osil.h"
#include "OSiLReader.h"
#include "OSrLReader.h"
#include "OSiLWriter.h"
#include "OSrLWriter.h"
#include "OSInstance.h"
#include "OSResult.h"
#include "LindoSolver.h"
#include "CoinSolver.h"
#include "DefaultSolver.h"
#include "OSSolverAgent.h"
#include "OShL.h"
#include "ErrorClass.h"
#include <sstream>
#include<string.h> 

//AMPL includes must be last.
#include <asl.h>
using std::cerr;
using std::string;


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
	nl2osil->createOSInstance() ;
	osinstance = nl2osil->osinstance;
	// turn the osinstance into osil 
	// not needed for a local solve
	// send an osinstance object in memory
	OSiLWriter *osilwriter = NULL;
	osilwriter = new OSiLWriter();
	string  osil = osilwriter->writeOSiL( osinstance);

	/**  amplclient_option: 
	 *   1. solver:
	 *		possible values - clp, glpk, cplex, cplex, lindo
	 *   2. location:
	 *      possible values - NULL (empty) or url of the solver service
	 *      
	 */
	

	char *amplclient_options = NULL;
	// set solver type default to clp
	DefaultSolver *solverType  = NULL;	
	OSrLReader *osrlreader = NULL;
	osrlreader = new OSrLReader();
	OSrLWriter *osrlwriter;
	osrlwriter = new OSrLWriter();
	OSResult *osresult = NULL;
	//
	string osrl = "";
	// note that default solver is coin and default subSolver is clp
	string osol = "<osol></osol>";
	// get the solver set by AMPLl
	amplclient_options = getenv("amplClient_options");
	cout << "HERE ARE THE AMPL CLIENT OPTIONS " <<   amplclient_options << endl;
	try{
		if(amplclient_options == NULL ) throw ErrorClass( "a local solver was not specified in AMPL option");
		else{
			if( strstr(amplclient_options, "lindo") != NULL) {
				// we are requesting the Lindo solver
				bool bLindoIsPresent = false;
				#ifdef COIN_HAS_LINDO
				bLindoIsPresent = true;
				solverType = new LindoSolver();
				#endif
				if(bLindoIsPresent == false) throw ErrorClass( "the Lindo solver requested is not present");
			}
			else{ 
				if( strstr(amplclient_options, "clp") != NULL){
					solverType = new CoinSolver();
					solverType->m_sSolverName = "clp";
				}
				else{
					if( strstr(amplclient_options, "cbc") != NULL){
						solverType = new CoinSolver();
						solverType->m_sSolverName = "cbc";
					}
					else{
						if( strstr(amplclient_options, "cplex") != NULL){
							solverType = new CoinSolver();
							solverType->m_sSolverName = "cplex";
						}
						else{
							if( strstr(amplclient_options, "glpk") != NULL){
								solverType = new CoinSolver();
								solverType->m_sSolverName = "glpk";
							}
							else{
								//throw ErrorClass( "a supported solver is not present");
								cout << "Generating a default LINDO solver" << endl;
								solverType = new LindoSolver();
							}
						}
					}
				}
			}
		}
		// do a local solve
		solverType->osil = osil;
		solverType->osol = osol;
		solverType->osinstance = NULL;
		solverType->solve();
		osrl = solverType->osrl ;
	}
	catch(const ErrorClass& eclass){
		osresult->setGeneralMessage( eclass.errormsg);
		osresult->setGeneralStatusType( "error");
		osrl = osrlwriter->writeOSrL( osresult);
	}
	// do the following for a remote solve
	//OSSolverAgent* osagent = NULL;
	//osagent = new OSSolverAgent("127.0.0.1:8080/os/ossolver/CoinSolverService.jws");
	//cout << "Place remote synchronous call" << endl;
	//osrl = osagent->solve(osil, osol);
	// okay start to test osrl parser 
	cout << "THE OSRL" << endl;
	cout << osrl << endl << endl <<endl;	
	osresult = osrlreader->readOSrL( osrl);
	cout << "Message = " << osresult->getSolutionMessage( 0) << endl;
	write_sol((char*)osresult->getSolutionMessage( 0).c_str(), 
		osresult->getOptimalPrimalVariableValues( -1), 
		osresult->getOptimalDualVariableValues( -1), 
		NULL);
	delete osrlreader;
	osrlreader = NULL;
	delete solverType;
	solverType = NULL;
	delete osrlwriter;
	osrlwriter = NULL;
	return 0;
} // end main
