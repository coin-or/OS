/** @file OSrLParserData.cpp
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
#define PARSERDATA_DEBUG

#include "OSrLParserData.h" 

 OSrLParserData::~OSrLParserData() {
 	if(numberOfSolutions > 0){
#ifdef PARSERDATA_DEBUG
		std::cout << "delete objectiveIdx" << std::endl;
#endif
		if(objectiveIdx != NULL) delete[] objectiveIdx;
		objectiveIdx = NULL;
		for(int i = 0; i < numberOfSolutions; i++){
#ifdef PARSERDATA_DEBUG
		std::cout << "delete primalSolution" << std::endl;
#endif
			if(primalSolution[ i]  != NULL)   delete[] primalSolution[ i];
			primalSolution[ i] = NULL;
			// now delete other var
			for(int k = 0; k < numberOfOtherVariableResults; k++){
				// the following delete gets rid of otherVarText in otherVarStruct
#ifdef PARSERDATA_DEBUG
		std::cout << "delete otherVarText" << std::endl;
#endif
				if( (otherVarVec[ k]  != NULL) && (otherVarVec[ k]->otherVarText != NULL) ) 
					delete[] otherVarVec[ k]->otherVarText;
				if( (otherVarVec[ k]  != NULL) && (otherVarVec[ k]->otherVarIndex != NULL) ) 
					delete[] otherVarVec[ k]->otherVarIndex;
				
				// the following should delete each of otherVarStruct created
				// each element of otherVarVec is a pointer to an otherVarStruct
#ifdef PARSERDATA_DEBUG
		std::cout << "delete otherVarVec" << std::endl;
#endif
				if( otherVarVec[ k]  != NULL) delete otherVarVec[ k];
			}
#ifdef PARSERDATA_DEBUG
		std::cout << "clear otherVarVec" << std::endl;
#endif
			otherVarVec.clear();
#ifdef PARSERDATA_DEBUG
		std::cout << "delete dualSolution" << std::endl;
#endif
			if( (dualSolution != NULL)  && (numberOfConstraints > 0) ) {
				if(dualSolution[ i] != NULL) delete[] dualSolution[ i];
				dualSolution[ i] = NULL;
			}
#ifdef PARSERDATA_DEBUG
		std::cout << "delete objectiveValues" << std::endl;
#endif
			if( (objectiveValues != NULL)  && (objectiveValues[i] != NULL) ) delete[] objectiveValues[i];
			objectiveValues[i] = NULL;
		}
	}
#ifdef PARSERDATA_DEBUG
		std::cout << "delete primalSolution" << std::endl;
#endif
	if(primalSolution != NULL) delete[]  primalSolution;
	primalSolution = NULL;
#ifdef PARSERDATA_DEBUG
		std::cout << "delete dualSolution" << std::endl;
#endif
	if(dualSolution != NULL) delete[] dualSolution;
	dualSolution = NULL;
#ifdef PARSERDATA_DEBUG
		std::cout << "delete objectiveValues" << std::endl;
#endif
	if(objectiveValues != NULL) delete[] objectiveValues;
	objectiveValues = NULL;
#ifdef PARSERDATA_DEBUG
		std::cout << "success" << std::endl;
#endif


 }//~OSrLParserData
 

 OSrLParserData::OSrLParserData() :
 	statusType(""),
	statusDescription(""),
	timeValue(0.0),
	timeType("elapsedTime"),
	timeCategory("total"),
	timeUnit("second"),
	timeDescription(""),
	numberOfTimes(0),
	tmpOtherValue(""),
	tmpOtherName(""),
	tmpOtherDescription(""),
	numberOfSolutions(0),
	numberOfVariables(0),
	numberOfConstraints(0),
	numberOfObjectives(0),
	kounter( 0),
	iOther(0),
	ivar(0),
	tempVal(0.0),
	outStr(""),
	numberOfOtherVariableResults( 0),
	solutionIdx( 0),
	statusTypePresent( false),
	generalStatusTypePresent( false),
	otherNamePresent( false),
	objectiveIdx( NULL),
	objectiveValues( NULL),
	primalSolution( NULL),
	dualSolution( NULL),
	otherVarStruct( NULL),
	errorText(NULL)
 {

 }//OSrLParserData
 
