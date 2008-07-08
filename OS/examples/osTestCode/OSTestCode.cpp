/** @file osTestCode.cpp
 * 
 * @author  Jun Ma, Kipp Martin, 
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */ 
 


#include <cppad/cppad.hpp> 
#include "OSConfig.h"
#include "OSCoinSolver.h"

#ifdef COIN_HAS_IPOPT  
	#ifndef COIN_HAS_ASL
		#include "OSIpoptSolver.h"
		#undef COIN_HAS_ASL
	#else
		#include "OSIpoptSolver.h"
	#endif
#endif

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
#include "OSMathUtil.h"

#include "OSBonminSolver.h"

#include<iostream> 
using std::cout;   
using std::endl;

//int main(int argC, char* argV[]){
int main( ){
	WindowsErrorPopupBlocker();
// test OS code samples here
	FileUtil *fileUtil = NULL; 
	fileUtil = new FileUtil();
	cout << "Start Building the Model" << endl;
	std::string osilFileName;
	std::string sosil;
	// get the input file
	const char dirsep =  CoinFindDirSeparator();
  	// Set directory containing mps data files.
  	std::string dataDir;
    dataDir = dirsep == '/' ? "../../data/" : "..\\..\\data\\";
	//osilFileName =  dataDir + "HS071_NLP.osil";
	osilFileName =  dataDir + "osilFiles" + dirsep  + "bonminEx1.osil";
	std::cout  << "osilFileName  =  " << osilFileName << std::endl;
	fileUtil = new FileUtil();
	sosil = fileUtil->getFileAsString( &osilFileName[0]);	
	std::cout << sosil << std::endl;
	BonminSolver *bonminSolver  =  NULL;
	bonminSolver = new BonminSolver();
	bonminSolver->osol = " ";
	OSiLReader *osilrdr = NULL;
	osilrdr = new OSiLReader(); 
	bonminSolver->osinstance = osilrdr->readOSiL( sosil);
	bonminSolver->buildSolverInstance();	
	bonminSolver->solve();
	OSrLWriter *osrlwrt;
	osrlwrt = new OSrLWriter();
	std::cout <<  osrlwrt->writeOSrL( bonminSolver->osresult ) << std::endl;
	//osilreader = new OSiLReader();
	//osinstance = osilreader->readOSiL( osil);
	return 0;
	
	
	
	try{
		
		OSInstance *osinstance = new OSInstance();

		// put in some of the OSInstance <instanceHeader> information
		osinstance->setInstanceSource("From Anderson, Sweeney, Williams, and Martin");
		osinstance->setInstanceDescription("The Par Inc. Problem");
		//
		// now put in the OSInstance <instanceData> information
		// 
		// first the variables
		osinstance->setVariableNumber( 2);   
		//addVariable(int index, string name, double lowerBound, double upperBound, char type, double init, string initString);
		// we could use setVariables() and add all the variable with one method call -- below is easier
		osinstance->addVariable(0, "x0", 0, OSDBL_MAX, 'C', OSNAN, "");
		osinstance->addVariable(1, "x1", 0, OSDBL_MAX, 'C', OSNAN, "");
		//
		// now add the objective function
		osinstance->setObjectiveNumber( 1);
		// now the coefficient
		SparseVector *objcoeff = new SparseVector(2);   
		objcoeff->indexes[ 0] = 0;
		objcoeff->values[ 0] = 10;
		objcoeff->indexes[ 1] = 1;
		objcoeff->values[ 1] = 9;
		//bool addObjective(int index, string name, string maxOrMin, double constant, double weight, SparseVector* objectiveCoefficients);
		osinstance->addObjective(-1, "objfunction", "max", 0.0, 1.0, objcoeff);
		objcoeff->bDeleteArrays = true;
		delete objcoeff;
		//
		// now the constraints
		osinstance->setConstraintNumber( 4); 
		//bool addConstraint(int index, string name, double lowerBound, double upperBound, double constant);
		// note: we could use setConstraints() and add all the constraints with one method call -- below is easier
		osinstance->addConstraint(0, "row0", -OSDBL_MAX, 630, 0); 
		osinstance->addConstraint(1, "row1", -OSDBL_MAX, 600, 0);
		osinstance->addConstraint(2, "row2", -OSDBL_MAX, 708, 0);
		osinstance->addConstraint(3, "row3", -OSDBL_MAX, 135, 0); 
		/*
		now add the <linearConstraintCoefficients>
		first do column major
		bool setLinearConstraintCoefficients(int numberOfValues, bool isColumnMajor, 
		double* values, int valuesBegin, int valuesEnd, 
		int* indexes, int indexesBegin, int indexesEnd,   			
		int* starts, int startsBegin, int startsEnd);	
		double *values = new double[ 8];
		int *indexes = new int[ 8];
		int *starts = new int[ 3];  
		values[ 0] = .7;
		values[ 1] = .5;
		values[ 2] = 1.0;
		values[ 3] = .1;
		values[ 4] = 1.0;
		values[ 5] = 5./6.;
		values[ 6] = 2./3.;
		values[ 7] = .25;
		indexes[ 0] = 0;
		indexes[ 1] = 1;
		indexes[ 2] = 2;
		indexes[ 3] = 3;
		indexes[ 4] = 0;
		indexes[ 5] = 1;
		indexes[ 6] = 2;  
		indexes[ 7] = 3;
		starts[ 0] = 0;
		starts[ 1] = 4;
		starts[ 2] = 8; 
		cout << "Call setLinearConstraintCoefficients" << endl;
		osinstance->setLinearConstraintCoefficients(8, true, values, 0, 7, 
			indexes, 0, 7, starts, 0, 2);	
		
		now row major
		*/
		double *values = new double[ 8];
		int *indexes = new int[ 8];
		int *starts = new int[ 5];  
		values[ 0] = .7;
		values[ 1] = 1;
		values[ 2] = .5;
		values[ 3] = 5./6.;
		values[ 4] = 1.0;
		values[ 5] = 2./3.;
		values[ 6] = .1;
		values[ 7] = .25;
		indexes[ 0] = 0;
		indexes[ 1] = 1;
		indexes[ 2] = 0;
		indexes[ 3] = 1;
		indexes[ 4] = 0;
		indexes[ 5] = 1;
		indexes[ 6] = 0;  
		indexes[ 7] = 1;
		starts[ 0] = 0;
		starts[ 1] = 2;
		starts[ 2] = 4;
		starts[ 3] = 6;
		starts[ 4] = 8;
		cout << "Call setLinearConstraintCoefficients" << endl;
		osinstance->setLinearConstraintCoefficients(8, false, values, 0, 7, 
			indexes, 0, 7, starts, 0, 4);
		cout << "End Building the Model" << endl; 
		// Write out the model
		OSiLWriter *osilwriter; 
		osilwriter = new OSiLWriter();
		std::string osil = osilwriter->writeOSiL( osinstance);
		cout << osil;
		// done writing the model
		cout << "Done writing the Model" << endl;
		// now solve the model
		CoinSolver *solver = new CoinSolver();
		//IpoptSolver *solver = new IpoptSolver();
		solver->osinstance = osinstance;
		solver->sSolverName ="clp"; 
		cout << "call the COIN - Clp Solver" << endl;
		solver->buildSolverInstance();
		solver->solve();
		std::cout << solver->osrl << std::endl;
		
		
		// now solve remotely
		
		OSSolverAgent* osagent = NULL;
		osagent = new OSSolverAgent("gsbkip.chicagogsb.edu/os/OSSolverService.jws");	
		
		std::string osol = "<osol></osol>";
		cout << "osil:" << endl << endl;
		cout << osil  << endl << endl;
		std::string osrl = osagent->solve(osil, osol);
		cout << "osrl result from osagent:" << endl << endl;
		cout << osrl  << endl << endl;
 
		// do garbage collection
		delete osinstance;
		osinstance = NULL;
		delete osilwriter;
		osilwriter = NULL;
		delete solver;
		solver = NULL;
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

