/** @file osrlparservariables.h
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
 
#include <string>
#include <vector> 
using std::string ;

//OSResult* osresult;
//int numberOfSolutions;
//int numberOfVariables;
//int numberOfConstraints;
//sint numberOfObjectives;
//string  statusType;
//string statusDescription;
//string generalStatusType;
//string generalStatusDescription;
bool statusTypePresent;
bool generalStatusTypePresent;
bool otherNamePresent;
bool beginElementText;
int solutionIdx;
//string serviceURI;
//string serviceName;
//string instanceName;
//string jobID;
//string headerMessage;
double **objectiveValues;
double **primalSolution;
double **dualSolution;
int *objectiveIdx;
//int kounter;
int numberOfOtherVariableResult;
struct OtherVariableResultStruct{
	std::string name;
	std::string description;
	std::string *otherVarText;
};
struct OtherVariableResultStruct *otherVarStruct;
std::vector<OtherVariableResultStruct*> otherVarVec;


/*  end header file */ 
