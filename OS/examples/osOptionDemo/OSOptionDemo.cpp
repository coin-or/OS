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
using std::cout;   
using std::endl;

//int main(int argC, char* argV[]){
int main( ){
	WindowsErrorPopupBlocker();
	FileUtil *fileUtil = NULL; 
	fileUtil = new FileUtil();
	cout << "Start Building the Model" << endl;
	try{


		const char dirsep =  CoinFindDirSeparator();
		// Set directory containing mps data files.
		std::string dataDir;
		std::string osilFileName;
		dataDir = dirsep == '/' ? "../../data/" : "..\\..\\data\\";
		
		osilFileName =  dataDir  + "osilFiles" + dirsep +  "p0033.osil";
		std::cout << "Try to read a sample file" << std::endl;
		std::cout << "The file is: " ;
		std::cout <<  osilFileName << std::endl;
		std::string osil = fileUtil->getFileAsString( osilFileName.c_str() );
		//now create some options
		OSiLReader *osilreader = NULL;
		osilreader = new OSiLReader(); 
		OSInstance *osinstance;
		osinstance = osilreader->readOSiL( osil);
		
		
		OSOption* osoption = new OSOption();

		osoption->setNumberOfVariables( osinstance->getVariableNumber() ) ;
		osoption->setNumberOfObjectives( 1);
		osoption->setNumberOfConstraints( osinstance->getConstraintNumber());
		osoption->setAnotherSolverOption("log","10","cbc","","integer","");
		OSoLWriter *osolwriter;
		osolwriter = new OSoLWriter();
		std::cout << osolwriter-> writeOSoL( osoption);
		

		
		CoinSolver *solver = new CoinSolver();
		solver->osinstance = osinstance;
		solver->sSolverName ="cbc"; 
		solver->osoption = osoption;
		solver->buildSolverInstance();		
		solver->solve();
		std::cout << solver->osrl << std::endl;

		
		delete osinstance;
		osinstance = NULL;
		delete solver;
		solver = NULL;
		delete osoption;
		osoption = NULL;
		delete fileUtil;
		fileUtil = NULL;
		cout << "Done with garbage collection" << endl;
		return 0;
		//
	}
	catch(const ErrorClass& eclass){
		delete fileUtil;
		std::cout << eclass.errormsg <<  std::endl;
		return 0;
	} 
}// end main
