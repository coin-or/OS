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
		delete objectiveIdx;
		objectiveIdx = NULL;
		for(int i = 0; i < numberOfSolutions; i++){
			delete primalSolution[ i];
			primalSolution[ i] = NULL;
			// now delete other var
			for(int k = 0; k < numberOfOtherVariableResult; k++){
				delete[] otherVarVec[ k]->otherVarText;				
			}
			otherVarVec.clear();
			if( numberOfConstraints > 0){
				delete dualSolution[ i];
				dualSolution[ i] = NULL;
			}
			delete objectiveValues[i];
			objectiveValues[i] = NULL;
		}
	}
	delete[]  primalSolution;
	primalSolution = NULL;
	delete[] dualSolution;
	dualSolution = NULL;
	delete[] objectiveValues;
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
	otherVarStruct( NULL)
 {

 }//OSrLParserData
 
