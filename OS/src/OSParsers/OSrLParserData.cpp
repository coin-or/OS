/** @file OSrLParserData.h
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
 #include "OSrLParserData.h"
 OSrLParserData::~OSrLParserData() {
 	if(numberOfSolutions > 0){
 		if(objectiveIdx != NULL) delete[] objectiveIdx;
		objectiveIdx = NULL;
		for(int i = 0; i < numberOfSolutions; i++){
			if(primalSolution[ i]  != NULL)   delete[] primalSolution[ i];
			primalSolution[ i] = NULL;
			// now delete other var
			for(int k = 0; k < numberOfOtherVariableResult; k++){
				// the following delete gets rid of otherVarText in otherVarStruct
				if( (otherVarVec[ k]  != NULL) && (otherVarVec[ k]->otherVarText != NULL) ) delete[] otherVarVec[ k]->otherVarText;
				// the following should delete each of otherVarStruct created
				// each element of otherVarVec is a pointer to an otherVarStruct
				if( otherVarVec[ k]  != NULL) delete otherVarVec[ k];
			}
			otherVarVec.clear();
			if( (dualSolution != NULL)  && (numberOfConstraints > 0) ) {
				if(dualSolution[ i] != NULL) delete[] dualSolution[ i];
				dualSolution[ i] = NULL;
			}
			if( (objectiveValues != NULL)  && (objectiveValues[i] != NULL) ) delete[] objectiveValues[i];
			objectiveValues[i] = NULL;
		}
	}
	if(primalSolution != NULL) delete[]  primalSolution;
	primalSolution = NULL;
	if(dualSolution != NULL) delete[] dualSolution;
	dualSolution = NULL;
	if(objectiveValues != NULL) delete[] objectiveValues;
	objectiveValues = NULL;



 }//~OSrLParserData
 

 OSrLParserData::OSrLParserData() :
 	statusType(""),
	statusDescription(""),
	numberOfSolutions(0),
	numberOfVariables(0),
	numberOfConstraints(0),
	numberOfObjectives(0),
	kounter( 0),
	numberOfOtherVariableResult( 0),
	solutionIdx( 0),
	statusTypePresent( false),
	generalStatusTypePresent( false),
	otherNamePresent( false),
	objectiveIdx( NULL),
	otherVarStruct( NULL),
	objectiveValues( NULL),
	primalSolution( NULL),
	dualSolution( NULL),
	errorText(NULL)
 {

 }//OSrLParserData
 
