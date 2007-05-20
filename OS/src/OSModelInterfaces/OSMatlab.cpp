/** @file TestOS.cpp
 * 
 * @author  Robert Fourer,  Jun Ma, Kipp Martin, 
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005, Robert Fourer, Jun Ma, Kipp Martin, Huanyuan Sheng
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */


#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include "OSMatlab.h"

  

using std::cout;
using std::endl; 
using std::ostringstream; 


 

OSMatlab::OSMatlab() {
	sparseMat = NULL;
	bu = NULL;
  	bl = NULL;
  	obj = NULL;
  	vu = NULL;
  	vl = NULL;
  	vu = NULL;
  	objType = 0;
  	osinstance = NULL;
  	varType = NULL;
  	numQTerms = 0;
  	qRows = NULL;
  	qIndex1 = NULL;
  	qIndex2 = NULL;
  	qVal = NULL;
  	numVar = 0;
  	numCon = 0;
  	instanceName=" ";
}//end OSMatlab


OSMatlab::~OSMatlab() {
	delete osinstance;
}//end ~OSMatlab

std::string OSMatlab::solve() {
	ostringstream outStr;
	std::string osol = "";
	osil = "";
	if(osinstance != NULL){
		OSiLWriter *osilwriter;
		osilwriter = new OSiLWriter();
		osilwriter->m_bWhiteSpace = true;
		osil =  osilwriter->writeOSiL( osinstance);
		//outStr << osil;
		//outStr << endl;
		//outStr << "Now Solve remotely with  LINDO" << endl;
		//outStr << "create a new LINDO Solver for OSiL string solution" << endl;
		OSSolverAgent* osagent = NULL;
		osagent = new OSSolverAgent( "http://128.135.130.17:8080/lindo/LindoSolverService.jws" );
		outStr << osagent->solve(osil, osol);
		// do the garbage collection 
		//delete osilwriter;
		delete osagent;
		return outStr.str();
	}else
	return "there was no instance";
}//end solve

void OSMatlab::createOSInstance(){
	ostringstream outStr;
	int i;
	osinstance = new OSInstance();
	//
	// put in some of the OSInstance <instanceHeader> information
	//osinstance->setInstanceSource("An example from the LINDO API samples directory");
	osinstance->setInstanceDescription("A MATLAB Created Problem");
	osinstance->setInstanceName( instanceName);
	//
	// now put in the OSInstance <instanceData> information
	// 
	// first the variables
	std::string *varNames;
	varNames = new std::string[ numVar];
	for(i = 0; i < numVar; i++){
		outStr << "x";
		outStr << i ;
		varNames[ i] = outStr.str();
		//osinstance->addVariable(i, varNames[ i] , vl[ i], vu[ i], varType[ i], OSNAN, "");
		outStr.str("");
	}
	//
	osinstance->setVariables(numVar, varNames, vl, vu, varType, NULL, NULL);
	//
	// now add the objective function
	osinstance->setObjectiveNumber( 1);
	// now the coefficient
	SparseVector *objcoeff;
	objcoeff = new SparseVector( numVar);   
	objcoeff->indexes = new int[ numVar];
	objcoeff->values = new double[ numVar];
	for(i = 0; i < numVar; i++){
		objcoeff->indexes[ i] = i;
		objcoeff->values[ i] = obj[ i];
	}
	std::string maxOrMin = "min";
	if( objType == true) maxOrMin = "max";
	//bool addObjective(int index, string name, string maxOrMin, double constant, double weight, SparseVector* objectiveCoefficients);
	osinstance->addObjective(-1, "objfunction", maxOrMin, 0.0, 1.0, objcoeff);
	//
	// now the constraints
	
	std::string *conNames;
	conNames = new std::string[ numCon];
	outStr.str("");
	for(i = 0; i < numCon; i++){
		outStr << "r";
		outStr << i;
		conNames[ i] = outStr.str();
		//osinstance->addConstraint(i, outStr.str() , bl[ i], bu[ i], 0);
		outStr.str("");
	}
	
	osinstance->setConstraints( numCon, conNames, bl, bu, NULL);
	//
	// now add the <linearConstraintCoefficients>
	//bool setLinearConstraintCoefficients(int numberOfValues, bool isColumnMajor, 
	//double* values, int valuesBegin, int valuesEnd, 
	//int* indexes, int indexesBegin, int indexesEnd,   			
	//int* starts, int startsBegin, int startsEnd);	
	osinstance->setLinearConstraintCoefficients(sparseMat->valueSize, true, sparseMat->values, 0, sparseMat->valueSize - 1, 
		sparseMat->indexes, 0, sparseMat->valueSize - 1, sparseMat->starts, 0, sparseMat->startSize - 1);
	if(numQTerms > 0){
		osinstance->setQuadraticTermsInNonlinearExpressions(numQTerms, qRows, qIndex1, qIndex2, qVal);	
	}
	return;
}// end createOSInstance
