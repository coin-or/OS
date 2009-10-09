/* $Id$ */
/** @file OSrLParserData.h
 * 
 * @author  Horand Gassmann,  Jun Ma, Kipp Martin, 
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */
#ifndef OSRLPARSERDATA_H
#define OSRLPARSERDATA_H

#include "OSnLNode.h"
#include "OSDataStructures.h"

#include <vector> 
#include <sstream>



/*! \struct OtherVariableResultStruct
 * \brief A structure to information about an OtherVariableResult 
 * element
 */
struct OtherVariableResultStruct{
	/** name holds the text of the name attribute of the 
	 * OtherVariableResult element 
	 */
	std::string name;

	/** description holds the text of the description attribute 
	 * of the OtherVariableResult element
	 */ 
	std::string description;
	
	/** value holds the text of the value attribute 
	 * of the OtherVariableResult element
	 */ 
	std::string value;
	
	/** numberOfVar holds the number of variables in the <var> array
	 * of the OtherVariableResult element
	 */ 
	int numberOfVar;

	/** otherVarText is a pointer to an array with number of 
	 * elements equal to the number of variables. Each element of the
	 * array is the value of the variable corresponding to the
	 * OtherVariableResult, e.g. a variable name or variable
	 * reduced cost, etc.
	 */
	std::string *otherVarText;
	

	/** otherVarIndex is a pointer to an array with number of 
	 * elements equal to the number of variables. Each element of the
	 * array is the index of the variable corresponding to the
	 * OtherVariableResult, e.g. a variable name or variable
	 * reduced cost, etc.
	 */
	int *otherVarIndex;
		
};


/*! \class OSrLParserData
 *  \brief The OSrLParserData  Class.
 * 
 * @author Horand Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 * 
 * \remarks
 * the OSrLParserData class is used to temporarily 
 * hold data found in parsing the OSrL instance
 * we do this so we can have a reentrant parser.
 */
class OSrLParserData{
public:
	
	/** the OSrLParserData class constructor */
	OSrLParserData( );
	
	//** the OSrLParserData class destructor */
	~OSrLParserData() ;
	
	
	/**  the status type of the result */ 
	std::string statusType;
	
	/** the status Description of the solution */
	std::string statusDescription;

	/** the next few variables store a time measurement and associated 
	    attribute values */
	double timeValue;
	std::string timeType;
	std::string timeCategory;
	std::string timeUnit;
	std::string timeDescription;

	/** There could be more than one time measurement;
	 *  numberOfTimes stores the number of them */
	unsigned int numberOfTimes;

	/** Provide temporary storage for attribute values associated with an OtherVarResult */
	std::string tmpOtherValue;
	std::string tmpOtherName;
	std::string tmpOtherDescription;

	/** Provide temporary storage for a single <record> contained in an OtherSolutionResult */
	std::string itemContent;

	/** scanner is used to store data in a reentrant lexer 
	 *  we use this to pass an OSrLParserData object to the parser*/
	void* scanner;
	
	/** number of result solutions */
	int numberOfSolutions;
	
	/** total number of variables in the model instance */
	int numberOfVariables;
	
	/** total number of constraints in the model instance */
	int numberOfConstraints;
	
	/** total number of Objectives in the model instance */
	int numberOfObjectives;
	
	/** number of variables in the a solution instance,
	 * may change from solution to solution
	 */
	int numberOfVar;
	
	/** number of constraints in the a solution instance,
	 * may change from solution to solution
	 */
	int numberOfCon;
	
	/** number of Objectives in the a solution instance 
	 * may change from solution to solution
	 */
	int numberOfObj;
	
	/** a temporary variable to hold the number of entries in a list */
	int numberOf;

	/** a temporary counter to count variables, number of attributes, etc. */
	int kounter;

	/** a temporary counter to count other variable, objective and constraint results */
	int iOther;

	/** a temporary counter to count second-level objects */
	unsigned int ivar;

	/** a temporary variable to hold an integer index value */
	int idx;

	/** a temporary variable to hold an integer or double value */
	double tempVal;
	
	/** a temporary variable to hold a string */
	std::string tempStr;
	
	/** a temporary variable to hold an output stream value */
	std::ostringstream outStr;
	
	/** the number of types of variable results other
	 * than the value of the variable
	 */	
	int numberOfOtherVariableResults;
	
	/** an index of which solution we have found */
	unsigned int solutionIdx;

	/** set statusTypePresent to true if there is
	 * a status attribute parsed
	 */
	bool statusTypePresent;
	
	/** set generalStatus...Present to true if the corresponding
	 *  general status attribute parsed
	 */	
	bool generalStatusTypePresent;
	bool generalStatusDescriptionPresent;
	bool generalStatusNumberOfPresent;
	
	/** set generalSubstatus...Present to true if the corresponding
	 *  generalStatus substatus attribute parsed
	 */	
	bool generalSubstatusNamePresent;
	bool generalSubstatusDescriptionPresent;

	/** set general...Present to true if the corresponding 
	 *  element (child of the <general> element) has been parsed
	 */
	bool generalStatusPresent; 
	bool generalMessagePresent; 
	bool generalServiceURIPresent; 
	bool generalServiceNamePresent; 
	bool generalInstanceNamePresent; 
	bool generalJobIDPresent; 
	bool generalSolverInvokedPresent; 
	bool generalTimeStampPresent; 
	bool generalOtherResultsPresent; 

	/** set generalOtherResult...Present to true if the corresponding
	 *  attribute has been parsed for the current <other> child in the <general> element
	 */	
	bool generalOtherResultNamePresent;
	bool generalOtherResultValuePresent;
	bool generalOtherResultDescriptionPresent;

	/** set system...Present to true if the corresponding 
	 *  element (child of the <system> element) has been parsed
	 */
	bool systemInformationPresent; 
	bool systemAvailableDiskSpacePresent; 
	bool systemAvailableMemoryPresent; 
	bool systemAvailableCPUSpeedPresent; 
	bool systemAvailableCPUNumberPresent; 
	bool systemOtherResultsPresent;

	/** set systemOtherResult...Present to true if the corresponding
	 *  attribute has been parsed for the current <other> child in the <system> element
	 */	
	bool systemOtherResultNamePresent;
	bool systemOtherResultValuePresent;
	bool systemOtherResultDescriptionPresent;

	/** set service...Present to true if the corresponding 
	 *  element (child of the <service> element) has been parsed
	 */
	bool serviceCurrentStatePresent;
	bool serviceCurrentJobCountPresent;
	bool serviceTotalJobsSoFarPresent;
	bool timeServiceStartedPresent;
	bool serviceUtilizationPresent;
	bool serviceOtherResultsPresent;

	/** set serviceOtherResult...Present to true if the corresponding
	 *  attribute has been parsed for the current <other> child in the <service> element
	 */	
	bool serviceOtherResultNamePresent;
	bool serviceOtherResultValuePresent;
	bool serviceOtherResultDescriptionPresent;



	/** set job...Present to true if the corresponding 
	 *  element (child of the <job> element) has been parsed
	 */
	bool jobStatusPresent;
	bool jobSubmitTimePresent;
	bool scheduledStartTimePresent;
	bool actualStartTimePresent;
	bool jobEndTimePresent;
	bool jobTimingInformationPresent;
	bool jobUsedDiskSpacePresent;
	bool jobUsedMemoryPresent;
	bool jobUsedCPUSpeedPresent;
	bool jobUsedCPUNumberPresent;
	bool jobOtherResultsPresent;

	/** set jobOtherResult...Present to true if the corresponding
	 *  attribute has been parsed for the current <other> child in the <job> element
	 */	
	bool jobOtherResultNamePresent;
	bool jobOtherResultValuePresent;
	bool jobOtherResultDescriptionPresent;

	/** set otherNamePresent to true if there is
	 * a name attribute in anotherVarResult
	 */	
	bool otherNamePresent;
	
	
	/**  for each solution we will build a vector of index-value
	 * pairs of primal values */
	struct IndexValuePair *primalValPair;
	std::vector<IndexValuePair*> primalVals;
	
	
	/**  for each solution we will build a vector of index-value
	 * pairs of objective function values */
	struct IndexValuePair *objValPair;
	std::vector<IndexValuePair*> objVals;
	

	/**  for each solution we will build a vector of index-value
	 * pairs of dual values */
	struct IndexValuePair *dualValPair;
	std::vector<IndexValuePair*> dualVals;
	

	/** a pointer to an OtherVariableResultStruct structure  */
	struct OtherVariableResultStruct *otherVarStruct;
	
	/** store a vector of pointers to otherVarVec structures */
	std::vector<OtherVariableResultStruct*> otherVarVec;
	
	/**  if the parser finds invalid text it is held here and we delete
	 *   if the file was not valid
	 */
	char *errorText;
};

#endif /*OSRLPARSERDATA_H_*/
