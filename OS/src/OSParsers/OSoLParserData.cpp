/** @file OSoLParserData.cpp
 * 
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, Dalhousie University and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */
 #include "OSoLParserData.h" 

 OSoLParserData::~OSoLParserData() {

 }//~OSoLParserData
 

 OSoLParserData::OSoLParserData() :
	osolgeneralPresent(false),
	osolsystemPresent(false),
	osolservicePresent(false),
	osoljobPresent(false),
	osoloptimizationPresent(false),

	serviceURIPresent(false),
	serviceNamePresent(false),
	instanceNamePresent(false),
	instanceLocationPresent(false),
	instanceLocationTypeattON(false),
	jobIDPresent(false),
	solverToInvokePresent(false),
	licensePresent(false),
	usernamePresent(false),
	passwordPresent(false),
	contactPresent(false),
	transportTypeattON(false),
	otherGeneralOptionsPresent(false),
      numberOfOtherGeneralOptions(0),

	minDiskSpacePresent(false),
	minDiskSpaceUnitPresent(false),
	minMemorySizePresent(false),
	minMemorySizeUnitPresent(false),
	minCPUSpeedPresent(false),
	minCPUSpeedUnitPresent(false),
	minCPUNumberPresent(false),
	otherSystemOptionsPresent(false),
      numberOfOtherSystemOptions(0),
	serviceTypePresent(false),
	otherServiceOptionsPresent(false),
      numberOfOtherServiceOptions(0),

	maxTimePresent(false),
	maxTimeUnitPresent(false),
	scheduledStartTimePresent(false),
	dependenciesPresent(false),
	numberOfDependencies(0),
	requiredDirectoriesPresent(false),
	numberOfRequiredDirectories(0),
	requiredFilesPresent(false),
	numberOfRequiredFiles(0),
	directoriesToMakePresent(false),
	numberOfDirectoriesToMake(0),
	filesToCreatePresent(false),
	numberOfFilesToCreate(0),
	pathPairFromPresent(false),
	pathPairToPresent(false),
	pathPairMakeCopyPresent(false),
	inputDirectoriesToMovePresent(false),
	numberOfInputDirectoriesToMove(0),
	inputFilesToMovePresent(false),
	numberOfInputFilesToMove(0),
	outputDirectoriesToMovePresent(false),
	numberOfOutputDirectoriesToMove(0),
	outputFilesToMovePresent(false),
	numberOfOutputFilesToMove(0),
	directoriesToDeletePresent(false),
	numberOfDirectoriesToDelete(0),
	filesToDeletePresent(false),
	numberOfFilesToDelete(0),
	processesToKillPresent(false),
	numberOfProcessesToKill(0),
	otherJobOptionsPresent(false),
      numberOfOtherJobOptions(0),

	numberOfVariables(0),
	numberOfVariablesPresent(false),
	numberOfObjectives(0),
	numberOfObjectivesPresent(false),
	numberOfConstraints(0),
	numberOfConstraintsPresent(false),
	variablesPresent(false),
	objectivesPresent(false),
	constraintsPresent(false),
	solverOptionsPresent(false),
	idxAttributePresent(false),
	valAttributePresent(false),
	lbvalAttributePresent(false),
	ubvalAttributePresent(false),
	numberOfOtherVariableOptions(0),
	initialVariableValuesPresent(false),
	numberOfVar(0),
	initialVariableValuesStringPresent(false),
	numberOfVarStr(0),
	numberOfOtherObjectiveOptions(0),
	initialObjectiveValuesPresent(false),
	numberOfObjValues(0),
	initialObjectiveBoundsPresent(false),
	numberOfObjBounds(0),
	numberOfOtherConstraintOptions(0),
	initialConstraintValuesPresent(false),
	numberOfCon(0),
	initialDualVariableValuesPresent(false),
	numberOfDuals(0),
	numberOfSolverOptions(0),

	numberOfObj(0),

	otherOptionNumberPresent(false),
	otherOptionNamePresent(false),
	otherOptionValuePresent(false),
	otherOptionSolverPresent(false),
	otherOptionCategoryPresent(false),
	otherOptionTypePresent(false),
	otherOptionDescriptionPresent(false),

	solverOptionNamePresent(false),
	solverOptionValuePresent(false),
	solverOptionSolverPresent(false),
	solverOptionCategoryPresent(false),
	solverOptionTypePresent(false),
	solverOptionDescriptionPresent(false),

 	statusType(""),
	statusDescription(""),
	errorText(NULL)
 {

 }//OSoLParserData
 
