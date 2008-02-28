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
#include "OSMathUtil.h"

#include<iostream> 
using std::cout;   
using std::endl;





//int main(int argC, char* argV[]){
int main( ){
// test OS code samples here
	FileUtil *fileUtil = NULL; 
	fileUtil = new FileUtil();
	cout << "Start Building the Model" << endl;
	try{
		OSInstance *osinstance;
		osinstance = new OSInstance();
		//
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
		osinstance->addVariable(0, "x0", 0, OSDBL_MAX, 'I', OSNAN, "");
		osinstance->addVariable(1, "x1", 0, OSDBL_MAX, 'I', OSNAN, "");
		//
		// now add the objective function
		osinstance->setObjectiveNumber( 1);
		// now the coefficient
		SparseVector *objcoeff;
		objcoeff = new SparseVector(2);   
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
		//
		//
		// now add the <linearConstraintCoefficients>
		//bool setLinearConstraintCoefficients(int numberOfValues, bool isColumnMajor, 
		//double* values, int valuesBegin, int valuesEnd, 
		//int* indexes, int indexesBegin, int indexesEnd,   			
		//int* starts, int startsBegin, int startsEnd);	
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
		cout << "End Building the Model" << endl; 
		// Write out the model
		OSiLWriter *osilwriter;
		osilwriter = new OSiLWriter();
		cout << osilwriter->writeOSiL( osinstance);
		// done writing the model
		cout << "Done writing the Model" << endl;
		// now solve the model
		CoinSolver *solver  = NULL;
		solver = new CoinSolver();
		solver->osinstance = osinstance;
		solver->sSolverName ="clp"; 
		cout << "call the COIN - Cbc Solver" << endl;
		// we want a fractional solution
		osinstance->instanceData->constraints->con[0]->ub = 620;
		solver->solve();
		cout << "Here is the COIN Cbc solver solution" << endl;
		cout << solver->osrl << endl;
		//
		//
		// done solving the model
		// add a Gomory Cut

	    CglGomory gomory;
	    OsiCuts cuts;
	    OsiSolverInterface::ApplyCutsReturnCode acRc;
	    gomory.generateCuts(*solver->m_OsiSolver, cuts);
	    acRc = solver->m_OsiSolver->applyCuts(cuts,0.0);
	    // Print applyCuts return code
	    cout <<endl <<endl;
	    cout <<cuts.sizeCuts() <<" cuts were generated" <<endl;
	    cout <<"  " <<acRc.getNumInconsistent() <<" were inconsistent" <<endl;
	    cout <<"  " <<acRc.getNumInconsistentWrtIntegerModel() 
           <<" were inconsistent for this problem" <<endl;
	    cout <<"  " <<acRc.getNumInfeasible() <<" were infeasible" <<endl;
	    cout <<"  " <<acRc.getNumIneffective() <<" were ineffective" <<endl;
	    cout <<"  " <<acRc.getNumApplied() <<" were applied" <<endl;
      	cout <<endl <<endl;
		solver->solve();
		cout << "Here is the COIN Cbc solver solution" << endl;
		cout << solver->osrl << endl;
		// do garbage collection
		delete osinstance;
		osinstance = NULL;
		delete osilwriter;
		osilwriter = NULL;
		cout << "Done with garbage collection" << endl;
		return 0;
		//
		/*
		if(argC != 2) throw ErrorClass( "there must be exactly one command line argument");
		std::string osilFileName;
		std::string osil;
		// get the input file
	    osilFileName =  argV[1];
	    osil = fileUtil->getFileAsString( osilFileName.c_str());
	    OSInstance *osinstance = NULL;
	    OSiLReader *osilreader = NULL;
	    OSiLWriter *osilwriter = NULL;
	    osilwriter = new OSiLWriter();
	    osilreader = new OSiLReader(); 
	    osinstance = osilreader->readOSiL( osil);
	    cout << osilwriter->writeOSiL( osinstance) << endl;
	    delete osilreader;
	    delete osilwriter;
	    delete fileUtil;
	   // delete osinstance;
	    */
	}
	catch(const ErrorClass& eclass){
		delete fileUtil;
		std::cout << eclass.errormsg <<  std::endl;
		return 0;
	} 
}// end main

