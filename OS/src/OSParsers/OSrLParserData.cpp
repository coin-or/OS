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
	numberOf(0),
	kounter( 0),
	iOther(0),
	ivar(0),
	idx(0),
	tempVal(0.0),
	tempStr(""),
	outStr(""),
	numberOfOtherVariableResults( 0),
	solutionIdx( 0),
	statusTypePresent( false),
	generalStatusTypePresent( false),
	generalStatusDescriptionPresent( false),
	generalStatusNumberOfPresent( false),
	generalSubstatusNamePresent( false),
	generalSubstatusDescriptionPresent( false),
	generalStatusPresent( false),
	generalMessagePresent( false),
	generalServiceURIPresent( false),
	generalServiceNamePresent( false),
	generalInstanceNamePresent( false),
	generalJobIDPresent( false),
	generalSolverInvokedPresent( false), 
	generalTimeStampPresent( false),
	generalOtherResultsPresent( false),
	generalOtherResultNamePresent( false),
	generalOtherResultValuePresent( false),
	generalOtherResultDescriptionPresent( false),
	systemInformationPresent( false),
	systemAvailableDiskSpacePresent( false),
	systemAvailableMemoryPresent( false),
	systemAvailableCPUSpeedPresent( false),
	systemAvailableCPUNumberPresent( false),
	systemOtherResultsPresent( false),
	systemOtherResultNamePresent( false),
	systemOtherResultValuePresent( false),
	systemOtherResultDescriptionPresent( false),
	otherNamePresent( false),
	otherVarStruct( NULL),
	errorText(NULL)
 {

 }//OSrLParserData
 
