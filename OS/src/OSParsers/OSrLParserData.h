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
#ifndef OSRLPARSERDATA_H
#define OSRLPARSERDATA_H

#include "OSnLNode.h"
#include <vector> 



class OSrLParserData{
public:
	//methods
	OSrLParserData( );
	~OSrLParserData() ;
	//properties
	void* scanner;
	int numberOfSolutions;
	int numberOfVariables;
	int numberOfConstraints;
	int numberOfObjectives;


	bool statusTypePresent;
	bool generalStatusTypePresent;
	
	
	int solutionIdx;

	double **objectiveValues;
	double **primalSolution;
	double **dualSolution;
	int *objectiveIdx;
	int kounter;
	int numberOfOtherVariableResult;
	struct OtherVariableResultStruct{
		std::string name;
		std::string description;
		std::string *rcost;
	};
	struct OtherVariableResultStruct *otherVarStruct;
	std::vector<OtherVariableResultStruct*> otherVarVec;
	};

#endif /*OSRLPARSERDATA_H_*/
