/* $Id$ */
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
//#define PARSERDATA_DEBUG

#include "OSrLParserData.h" 

 OSrLParserData::~OSrLParserData() {
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
	itemContent(""),
	numberOfSolutions(0),
	numberOfVariables(0),
	numberOfConstraints(0),
	numberOfObjectives(0),
	numberOfIdx(0),
	numberOfVar(0),
	numberOfVarIdx(0),
	numberOfCon(0),
	numberOfEnumerations(0),
	numberOfObj(0),
	numberOf(0),
	kounter( 0),
	iOther(0),
	ivar(0),
	idx(0),
	tempVal(0.0),
	tempInt(0),
	tempStr(""),
	name(""),
	outStr(""),
	numberOfOtherVariableResults( 0),
	numberOfOtherObjectiveResults( 0),
	numberOfOtherConstraintResults( 0),
	solutionIdx( 0),
	mult(1),
	incr(0),
	numberAttributePresent( false),
	incrPresent(false),
	multPresent(false),
	idxAttributePresent( false),
	categoryAttributePresent( false),
	descriptionAttributePresent( false),
	nameAttributePresent( false),
	numberOfVarAttributePresent( false),
	numberOfVarIdxAttributePresent( false),
	numberOfObjAttributePresent( false),
	numberOfObjIdxAttributePresent( false),
	numberOfConAttributePresent( false),
	numberOfConIdxAttributePresent( false),
	numberOfEnumerationsAttributePresent( false),
	typeAttributePresent( false),
	unitAttributePresent( false),
	valueAttributePresent( false),
	weightedObjAttributePresent( false),
	categoryAttribute(""),
	descriptionAttribute(""),
	nameAttribute(""),
	typeAttribute(""),
	unitAttribute(""),
	valueAttribute(""),
	nVarPresent( false),
	nObjPresent( false),
	nConPresent( false),
	generalStatusPresent( false),
	generalMessagePresent( false),
	generalServiceURIPresent( false),
	generalServiceNamePresent( false),
	generalInstanceNamePresent( false),
	generalJobIDPresent( false),
	generalSolverInvokedPresent( false), 
	generalTimeStampPresent( false),
	otherGeneralResultsPresent( false),
	systemInformationPresent( false),
	systemAvailableDiskSpacePresent( false),
	systemAvailableMemoryPresent( false),
	systemAvailableCPUSpeedPresent( false),
	systemAvailableCPUNumberPresent( false),
	otherSystemResultsPresent( false),
	serviceCurrentStatePresent( false),
	serviceCurrentJobCountPresent( false),
	serviceTotalJobsSoFarPresent( false),
	timeServiceStartedPresent( false),
	serviceUtilizationPresent( false),
	otherServiceResultsPresent( false),
	jobStatusPresent( false),
	jobSubmitTimePresent( false),
	scheduledStartTimePresent( false),
	actualStartTimePresent( false),
	jobEndTimePresent( false),
	jobTimingInformationPresent( false),
	jobUsedDiskSpacePresent( false),
	jobUsedMemoryPresent( false),
	jobUsedCPUSpeedPresent( false),
	jobUsedCPUNumberPresent( false),
	otherJobResultsPresent( false),
	numberOfItemsPresent( false),
	numberOfItems(0),
	otherVarStruct( NULL),
	errorText(NULL)
 {

 }//OSrLParserData
 
