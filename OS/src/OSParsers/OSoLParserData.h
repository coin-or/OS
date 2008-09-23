/** @file OSoLParserData.h
 * 
 * @author  Horand Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.0, 29/08/2008
 * @since   OS1.1
 *
 * \remarks
 * Copyright (C) 2005, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, Dalhousie University and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */
#ifndef OSOLPARSERDATA_H
#define OSOLPARSERDATA_H

#include "OSnLNode.h"
#include <vector> 





/*! \class OSoLParserData
 *  \brief The OSoLParserData  Class.
 * 
 * @author Horand Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 08/29/2008
 * @since OS 1.1
 * 
 * \remarks
 * the OSoLParserData class is used to temporarily 
 * hold data found in parsing the OSoL instance
 * we do this so we can have a reentrant parser.
 */
class OSoLParserData{
public:
	/** track which child elements are present */
	bool osolgeneralPresent;
	bool osolsystemPresent;
	bool osolservicePresent;
	bool osoljobPresent;
	bool osoloptimizationPresent;


	/** children of the <general> element */
	bool serviceIDPresent;
	bool serviceNamePresent;
	bool instanceNamePresent;
	bool instanceLocationPresent;
	bool instanceLocationTypeattON;
	bool jobIDPresent;
	bool solverToInvokePresent;
	bool licensePresent;
	bool usernamePresent;
	bool passwordPresent;
	bool contactPresent;
	bool transportTypeattON;

	bool otherGeneralOptionsPresent;
      int numberOfOtherGeneralOptions;


	/** children of the <system> element */
	bool minDiskSpacePresent;
	bool minDiskSpaceUnitPresent;

	bool minMemorySizePresent;
	bool minMemorySizeUnitPresent;

	bool minCPUSpeedPresent;
	bool minCPUSpeedUnitPresent;

	bool minCPUNumberPresent;

	bool otherSystemOptionsPresent;
      int numberOfOtherSystemOptions;


	/** children of the <service> element */
	bool serviceTypePresent;

	bool otherServiceOptionsPresent;
      int numberOfOtherServiceOptions;


	/** children of the <job> element */
	bool maxTimePresent;
	std::string maxTimeUnit;
	bool maxTimeUnitPresent;
	double maxTimeValue;

	bool scheduledStartTimePresent;
	std::string scheduledStartTime;

	bool dependenciesPresent;
	int numberOfDependencies;

	bool requiredDirectoriesPresent;
	int numberOfRequiredDirectories;

	bool requiredFilesPresent;
	int numberOfRequiredFiles;

	bool directoriesToMakePresent;
	int numberOfDirectoriesToMake;

	bool filesToCreatePresent;
	int numberOfFilesToCreate;

	bool inputDirectoriesToMovePresent;
	int numberOfInputDirectoriesToMove;

	bool inputFilesToMovePresent;
	int numberOfInputFilesToMove;

	bool outputDirectoriesToMovePresent;
	int numberOfOutputDirectoriesToMove;

	bool outputFilesToMovePresent;
	int numberOfOutputFilesToMove;

	bool DirectoriesToDeletePresent;
	int numberOfDirectoriesToDelete;

	bool FilesToDeletePresent;
	int numberOfFilesToDelete;

	bool processesToKillPresent;
	int numberOfPtocessesToKill;

	bool otherJobOptionsPresent;
      int numberOfOtherJobOptions;
	
	/** children of the <optimization> element */
	int numberOfVariables;
	int numberOfObjectives;
	int numberOfConstraints;
	bool variablesPresent;
	bool objectivesPresent;
	bool constraintsPresent;
	bool solverOptionsPresent;
	int numberOfOtherVariableOptions;
	bool initialVariableValuesPresent;
	int numberOfVar;
	int numberOfOtherObjectiveOptions;
	bool initialObjectiveValuesPresent;
	int numberOfObjValues;
	bool initialObjectiveBoundsPresent;
	int numberOfObjBounds;
	int numberOfOtherConstraintOptions;
	bool initialConstraintValuesPresent;
	int numberOfCon;
	bool initialDualVariableValuesPresent;
	int numberOfDuals;


	/** the OSoLParserData class constructor */
	OSoLParserData( );
	
	//** the OSoLParserData class destructor */
	~OSoLParserData() ;
	
	
	/**  the status type of the result */ 
	std::string statusType;
	
	/** the status Description of the solution */
	std::string statusDescription;

	/** scanner is used to store data in a reentrant lexer 
	 * we use this to pass an OSoLParserData object to the parser*/
	void* scanner;
	
	
	/**  if the parser finds invalid text it is held here and we delete
	 * if the file was not valid
	 */
	char *errorText;
};//OSoLPArserData

#endif /*OSOLPARSERDATA_H_*/
