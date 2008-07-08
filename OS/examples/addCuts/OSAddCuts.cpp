/** @file osTestCode.cpp
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
 * This is a dummy executable that does nothing but 
 * print <I>Hello World</I>. I put in test code here when doing
 * various tests.
 * 
 */
 


#include <cppad/cppad.hpp> 
#include "OSConfig.h"
#include "OSCoinSolver.h"
#include "OSResult.h" 
#include "OSiLReader.h"        
#include "OSiLWriter.h"   
#include "OSrLReader.h"          
#include "OSrLWriter.h"      
#include "OSInstance.h"  
#include "OSFileUtil.h"   
#include "OSDefaultSolver.h"  
#include "OSWSUtil.h" 
#include "OSSolverAgent.h"   
#include "OShL.h"     
#include "OSErrorClass.h"
#include "OSmps2osil.h"   
#include "OSBase64.h"
#include "OSCommonUtil.h"
#include "OSErrorClass.h"
#include "CglGomory.hpp"
#include "CglSimpleRounding.hpp"
#include "CglKnapsackCover.hpp"
#include "OSMathUtil.h"

#include<iostream> 
using std::cout;   
using std::endl;

int main( ){
	WindowsErrorPopupBlocker();
// test OS code samples here
	FileUtil *fileUtil = NULL; 
	fileUtil = new FileUtil();
	const char dirsep =  CoinFindDirSeparator();
 	// Set directory containing mps data files.
 	std::string dataDir;
   dataDir = dirsep == '/' ? "../../data/" : "..\\..\\data\\";
	cout << "Start Building the Model" << endl;
	try{
		// get the p0033 problem
		std::string osilFileName;
		osilFileName =  dataDir  + "osilFiles" + dirsep +  "p0033.osil";
		std::cout << "Try to read a sample file" << std::endl;
		std::cout << "The file is: " ;
		std::cout <<  osilFileName << std::endl;
		std::string osil = fileUtil->getFileAsString( osilFileName.c_str() );
		OSiLReader *osilreader = NULL;
		osilreader = new OSiLReader(); 
		// done writing the model
		cout << "Done writing the Model" << endl;
		// now solve the model
		CoinSolver *solver  = NULL;
		solver = new CoinSolver();
		solver->sSolverName ="clp"; 
		solver->osinstance = osilreader->readOSiL( osil);;
		cout << "call the COIN - Clp Solver" << endl;
		solver->buildSolverInstance();
		// suppress LP output
		solver->osiSolver->setHintParam(OsiDoReducePrint, true, OsiHintTry);
		solver->osiSolver->initialSolve();
		cout << endl << endl << endl;
		cout << "Here is the p0033 objective value "  << solver->osiSolver->getObjValue()  << endl;
		//
		// done solving the model
		// add Rounding and Cover cuts
		//
	    CglKnapsackCover cover;
	    CglSimpleRounding round;  
	    CoinRelFltEq eq(0.0001);
	    OsiSolverInterface::ApplyCutsReturnCode acRc;    
	    OsiCuts cuts;
	    cover.generateCuts(*(solver->osiSolver), cuts);
	    round.generateCuts(*(solver->osiSolver), cuts);
	    acRc = solver->osiSolver->applyCuts(cuts,  0.0);
	    // Print applyCuts return code
	    cout <<  endl <<endl;
	    cout << cuts.sizeCuts() <<" cuts were generated" <<endl;
	    cout <<"  " <<acRc.getNumInconsistent() <<" were inconsistent" <<endl;
	    cout <<"  " <<acRc.getNumInconsistentWrtIntegerModel() 
           <<" were inconsistent for this problem" <<endl;
	    cout <<"  " <<acRc.getNumInfeasible() <<" were infeasible" <<endl;
	    cout <<"  " <<acRc.getNumIneffective() <<" were ineffective" <<endl;
	    cout <<"  " <<acRc.getNumApplied() <<" were applied" <<endl;
      	cout <<endl <<endl;
        // Resolve
      	solver->osiSolver->resolve();
        cout <<endl;
        cout <<"After applying cuts, objective value changed to: "
             <<   solver->osiSolver->getObjValue() <<endl <<endl;
    	// do garbage collection
		delete solver;
		solver = NULL;
		delete osilreader;
		osilreader = NULL;
		delete fileUtil;
		fileUtil  = NULL;
		cout << "Done with garbage collection" << endl;
		return 0;
	}
	catch(const ErrorClass& eclass){
		delete fileUtil;
		std::cout << eclass.errormsg <<  std::endl;
		return 0;
	} 
}// end main

