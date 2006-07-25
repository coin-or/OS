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
 
 
#include <vector> 

OSResult* osresult;
int numberOfSolutions;
int numberOfVariables;
int numberOfConstraints;
int numberOfObjectives;
char *statusType;
char *statusDescription;
char *generalStatusType;
char *generalStatusDescription;
bool statusTypePresent;
bool generalStatusTypePresent;
bool otherNamePresent;
bool beginElementText;
int solutionIdx;
char *serviceURI;
char *serviceName;
char *instanceName;
char *jobID;
char *headerMessage;
double **objectiveValues;
double **primalSolution;
double **dualSolution;
int *objectiveIdx;
int kounter;
int numberOfOtherVariableResult;
struct OtherVariableResultStruct{
	string name;
	string description;
	string *rcost;
};
struct OtherVariableResultStruct *otherVarStruct;
std::vector<OtherVariableResultStruct*> otherVarVec;


/*  end header file */ 
