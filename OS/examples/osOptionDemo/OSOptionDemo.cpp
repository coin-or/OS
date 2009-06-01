/** @file OSOptionDemo.cpp
 * 
 * @author  Gus Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.0, 26/06/2008
 * @since   OS1.1
 *
 * \remarks
 * Copyright (C) 2008, Gus Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University, Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */ 

#include "OSConfig.h"
#include "OSCoinSolver.h"
#include "OSIpoptSolver.h"
#include "OSResult.h" 
#include "OSiLReader.h"        
#include "OSiLWriter.h"   
#include "OSrLReader.h"          
#include "OSrLWriter.h"      
#include "OSInstance.h"  
#include "OSOption.h"
#include "OSoLWriter.h"
#include "OSFileUtil.h"   
#include "OSDefaultSolver.h"  
#include "OShL.h"     
#include "OSErrorClass.h"
#include "OSmps2osil.h"   
#include "OSBase64.h"
#include "OSCommonUtil.h"
#include "OSErrorClass.h"
#include "OSMathUtil.h"
#include "CoinError.hpp"
#include "CoinHelperFunctions.hpp"
#include<iostream> 


#ifdef COIN_HAS_COUENNE    
#include "OSCouenneSolver.h"
#endif
using std::string;
using std::cout;   
using std::endl;

void getOSResult(std::string osrl);

//int main(int argC, char* argV[]){
int main( ){
	WindowsErrorPopupBlocker();
	FileUtil *fileUtil = NULL; 
	fileUtil = new FileUtil();
	cout << "Start Building the Model" << endl;
	try{


		const char dirsep =  CoinFindDirSeparator();
		std::string osil;
		// Set directory containing mps data files.
		std::string dataDir;
		std::string osilFileName;
		dataDir = dirsep == '/' ? "../../data/" : "..\\..\\data\\";
		/// declare a generic solver
		
		DefaultSolver *solver  = NULL;
		OSiLReader *osilreader = NULL;
		OSInstance *osinstance = NULL;
		OSoLWriter *osolwriter = NULL;
		OSOption* osoption = NULL;
		
		/******************** Start Clp Example *************************/
		osilFileName =  dataDir  + "osilFiles" + dirsep +  "parincLinear.osil";
		osil = fileUtil->getFileAsString( osilFileName.c_str() );
		osilreader = new OSiLReader(); 
		osinstance = osilreader->readOSiL( osil);
		osoption = new OSOption();
		/** 
		 *  here is the format for setting options:
		 *	bool setAnotherSolverOption(std::string name, std::string value, std::string solver, 
		 *	std::string category, std::string type, std::string description);
		 */
		osoption->setAnotherSolverOption("OsiHintTry","","osi","","OsiHintStrength","");
		osoption->setAnotherSolverOption("OsiDoReducePrint","false","osi","","OsiHintParam","");
		osolwriter = new OSoLWriter();
		std::cout << osolwriter-> writeOSoL( osoption);
		solver = new CoinSolver();
		solver->osinstance = osinstance;
		solver->sSolverName ="clp"; 
		solver->osoption = osoption;
		solver->buildSolverInstance();		
		solver->solve();
		std::cout << solver->osrl << std::endl;
		
		//do garbage collection
		delete osilreader;
		osilreader = NULL;
		delete solver;
		solver = NULL;
		delete osoption;
		osoption = NULL;
		delete osolwriter;
		osolwriter = NULL;
		//finish garbage collection
		
		/******************** End Clp Example *************************/
		
		
		/******************** Start Cbc Example *************************/
		osilFileName =  dataDir  + "osilFiles" + dirsep +  "p0033.osil";
		osil = fileUtil->getFileAsString( osilFileName.c_str() );
		osilreader = new OSiLReader(); 
		
		osinstance = osilreader->readOSiL( osil);
		 osoption = new OSOption();
		/** 
		 *  here is the format for setting options:
		 *	bool setAnotherSolverOption(std::string name, std::string value, std::string solver, 
		 *	std::string category, std::string type, std::string description);
		 */
		osoption->setAnotherSolverOption("primalS","","cbc","","string","");
		//in primal simplex set the pivot choice -- use steepest edge
		osoption->setAnotherSolverOption("primalpivot","steepest","cbc","","string","");
		osoption->setAnotherSolverOption("log","10","cbc","","integer","");
		osolwriter = new OSoLWriter();
		std::cout << osolwriter-> writeOSoL( osoption);
		solver = new CoinSolver();
		solver->osinstance = osinstance;
		solver->sSolverName ="cbc"; 
		solver->osoption = osoption;
		solver->buildSolverInstance();		
		solver->solve();
		std::cout << solver->osrl << std::endl;
		
		// start garbage collection
		delete osilreader;
		osilreader = NULL;
		delete solver;
		solver = NULL;
		delete osoption;
		osoption = NULL;
		delete osolwriter;
		osolwriter = NULL;
		// finish garbage collection
		
		/******************** End Cbc Example *************************/
		
		
		/******************** Start SYMPHONY Example *************************/
		osilFileName =  dataDir  + "osilFiles" + dirsep +  "p0033.osil";
		osil = fileUtil->getFileAsString( osilFileName.c_str() );
		osilreader = new OSiLReader(); 
		
		osinstance = osilreader->readOSiL( osil);
		 osoption = new OSOption();
		/** 
		 *  here is the format for setting options:
		 *	bool setAnotherSolverOption(std::string name, std::string value, std::string solver, 
		 *	std::string category, std::string type, std::string description);
		 */
		 
		//turn off SYMPHONY output
		osoption->setAnotherSolverOption("verbosity","0","symphony","","","");
		osolwriter = new OSoLWriter();
		std::cout << osolwriter-> writeOSoL( osoption);
		solver = new CoinSolver();
		solver->osinstance = osinstance;
		solver->sSolverName ="symphony"; 
		solver->osoption = osoption;
		solver->buildSolverInstance();		
		solver->solve();
		//std::cout << solver->osrl << std::endl;
		
		// start garbage collection
		delete osilreader;
		osilreader = NULL;
		delete solver;
		solver = NULL;
		delete osoption;
		osoption = NULL;
		delete osolwriter;
		osolwriter = NULL;
		// finish garbage collection
		
		/******************** End SYMPHONY Example *************************/
		
#ifdef COIN_HAS_COUENNE		
		/******************** Start Couenne Example *************************/
		osilFileName =  dataDir  + "osilFiles" + dirsep +  "wayneQuadratic.osil";
		osil = fileUtil->getFileAsString( osilFileName.c_str() );
		osilreader = new OSiLReader(); 
		
		osinstance = osilreader->readOSiL( osil);
		 osoption = new OSOption();
		/** 
		 *  here is the format for setting options:
		 *	bool setAnotherSolverOption(std::string name, std::string value, std::string solver, 
		 *	std::string category, std::string type, std::string description);
		 */
		 
		// set Bonmin options through Couenne 
		// set a limit of 50000 nodes -- this is on Cbc
		osoption->setAnotherSolverOption("node_limit","50000","couenne","bonmin","integer","");
		// control some Bonmin output
		osoption->setAnotherSolverOption("bb_log_level","3","couenne","bonmin","integer","");
		osoption->setAnotherSolverOption("nlp_log_level","2","couenne","bonmin","integer","");
		//solve 3 times at each node and get best solution
		osoption->setAnotherSolverOption("num_resolve_at_node","3","couenne","bonmin","integer","");
		//solve 5 times at root node and get best solution
		osoption->setAnotherSolverOption("num_resolve_at_root","5","couenne","bonmin","integer","");

		
		// set Ipopt options through Couenne
		osoption->setAnotherSolverOption("max_iter","100","couenne","ipopt","integer","");
		
		// set a Couenne time limit option
		osoption->setAnotherSolverOption("time_limit",".1","couenne","","numeric","");
		osolwriter = new OSoLWriter();
		std::cout << osolwriter-> writeOSoL( osoption);
		solver = new CouenneSolver();
		solver->osinstance = osinstance;
		solver->osoption = osoption;
		solver->buildSolverInstance();		
		solver->solve();
		//std::cout << solver->osrl << std::endl;
		getOSResult( solver->osrl);
		// start garbage collection
		delete osilreader;
		osilreader = NULL;
		delete solver;
		solver = NULL;
		delete osoption;
		osoption = NULL;
		delete osolwriter;
		osolwriter = NULL;
		// finish garbage collection
		
		/******************** End Couenne Example *************************/
#endif		
		delete fileUtil;
		fileUtil = NULL;	
		return 0;
		//
	}
	catch(const ErrorClass& eclass){
		delete fileUtil;
		std::cout << eclass.errormsg <<  std::endl;
		return 0;
	} 
}// end main

void getOSResult(std::string osrl){
//see the example OSResultDemo for a more detailed example
	std::cout << std::endl << std::endl << std::endl;
	OSrLReader *osrlreader = NULL;
	OSResult *osresult = NULL;
	osrlreader = new OSrLReader();
	osresult  = osrlreader->readOSrL( osrl);
	
	//now use the OSResult API -- first make sure we got an optimal solution
	//get the status
	std::string solStatus;
	double optSolValue;
	// the argument is the solution index
	solStatus = osresult->getSolutionStatusType( 0 );
	// if solStatus is optimal get the optimal solution value
	if( solStatus.find("ptimal") != string::npos ){
	//first index is objIdx, second is solution index
		optSolValue = osresult->getOptimalObjValue( -1, 0);
		std::cout << "OPTIMAL SOLUTION VALUE  " <<  optSolValue << std::endl;
	}else{
		std::cout << "NO OPTIMAL SOLUTION FOUND " << std::endl;
	}
	
	int i;
	int vecSize;
	// now get the primal solution
	std::vector<IndexValuePair*> primalValPair;
	primalValPair = osresult->getOptimalPrimalVariableValues( 0);
	vecSize = primalValPair.size();
	for(i = 0; i < vecSize; i++){
		std::cout << "index = " <<  primalValPair[ i]->idx ;
		std::cout << "    value = " <<  primalValPair[ i]->value << std::endl;
	}
	delete osrlreader;
}// get OSResult

