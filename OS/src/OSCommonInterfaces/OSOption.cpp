/** @file OSOption.cpp
 * 
 *
 * @author  Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.0, 29/Aug/2008
 * @since   OS1.1
 *
 * \remarks
 * Copyright (C) 2005, Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, Dalhousie University and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */

#include "OSOption.h"
#include "OSParameters.h"
#include "OSErrorClass.h"
#include <iostream>
#include <sstream>
#include <limits>
#include <cstdio>

//#define DEBUG

using namespace std;

InstanceLocationOption::InstanceLocationOption(): 
	locationType ("local"),
	value ("")
{    
	#ifdef DEBUG
	cout << "Inside InstanceLocationOption Constructor" << endl;
	#endif
}// end InstanceLocationOption constructor  

InstanceLocationOption::~InstanceLocationOption()
{    
	#ifdef DEBUG
	cout << "InstanceLocationOption Destructor Called" << endl;
	#endif
}//end InstanceLocationOption destructor 


ContactOption::ContactOption(): 
	transportType ("osp"),
	value ("")
{    
	#ifdef DEBUG
	cout << "Inside ContactOption Constructor" << endl;
	#endif
}// end ContactOption constructor 

ContactOption::~ContactOption()
{    
	#ifdef DEBUG
	cout << "ContactOption Destructor Called" << endl;
	#endif
}//end ContactOption destructor


OtherOption::OtherOption(): 
	name (""),
	value (""),
	description ("")
{    
	#ifdef DEBUG
	cout << "Inside OtherOption Constructor" << endl;
	#endif
}// end OtherOption constructor 

OtherOption::~OtherOption()
{    
	#ifdef DEBUG
	cout << "OtherOption Destructor Called" << endl;
	#endif
}//end OtherOption destructor


OtherOptions::OtherOptions(): 
	numberOfOtherOptions(0)
{    
	#ifdef DEBUG
	cout << "Inside OtherOptions Constructor" << endl;
	#endif
	other = NULL;
}// end OtherOptions constructor 

OtherOptions::~OtherOptions()
{    
	#ifdef DEBUG
	cout << "OtherOptions Destructor Called" << endl;
	#endif
	if (other != NULL)
	{	for ( int i=0; i<numberOfOtherOptions; i++)
		{	delete other[i];
			other[i] = NULL;
		}
		delete[] other;
		other = NULL;
	}
}//end OtherOptions destructor


GeneralOption::GeneralOption(): 
	serviceURI (""),
	serviceName (""),
	instanceName (""),
	jobID (""),
	solverToInvoke (""),
	license (""),
	userName (""),
	password ("")
{    
	#ifdef DEBUG
	cout << "Inside GeneralOption Constructor" << endl;
	#endif
	instanceLocation = NULL;
	contact = NULL;
	otherOptions = NULL;
}// end GeneralOption constructor  

GeneralOption::~GeneralOption()
{    
	#ifdef DEBUG
	cout << "GeneralOption Destructor Called" << endl;
	#endif
	if (instanceLocation != NULL) delete instanceLocation;
	instanceLocation = NULL;
	if (contact != NULL) delete contact;
	contact = NULL;
	if (otherOptions != NULL) delete otherOptions;
	otherOptions = NULL;
}//end GeneralOption destructor 


MinDiskSpace::MinDiskSpace():
	unit ("byte"),
	value (0.0)
{
	#ifdef DEBUG
	cout << "Inside MinDiskSpace Constructor" << endl;
	#endif
}// end MinDiskSpace constructor

MinDiskSpace::~MinDiskSpace()
{
	#ifdef DEBUG
	cout << "MinDiskSpace Destructor Called" << endl;
	#endif
}// end MinDiskSpace constructor


MinMemorySize::MinMemorySize():
	unit ("byte"),
	value (0.0)
{
	#ifdef DEBUG
	cout << "Inside MinMemorySize Constructor" << endl;
	#endif
}// end MinMemorySize constructor

MinMemorySize::~MinMemorySize()
{
	#ifdef DEBUG
	cout << "MinMemorySize Destructor Called" << endl;
	#endif
}// end MinMemorySize constructor


MinCPUSpeed::MinCPUSpeed():
	unit ("hertz"),
	value (0.0)
{
	#ifdef DEBUG
	cout << "Inside MinCPUSpeed Constructor" << endl;
	#endif
}// end MinCPUSpeed constructor

MinCPUSpeed::~MinCPUSpeed()
{
	#ifdef DEBUG
	cout << "MinCPUSpeed Destructor Called" << endl;
	#endif
}// end MinCPUSpeed constructor


SystemOption::SystemOption(): 
	minCPUNumber (1)
{    
	#ifdef DEBUG
	cout << "Inside SystemOption Constructor" << endl;
	#endif
	minDiskSpace = NULL;
	minMemorySize = NULL;
	minCPUSpeed = NULL;
	otherOptions = NULL;
}// end SystemOption constructor  

SystemOption::~SystemOption()
{    
	#ifdef DEBUG
	cout << "SystemOption Destructor Called" << endl;
	#endif
	if (minDiskSpace != NULL) delete minDiskSpace;
	minDiskSpace = NULL;
	if (minMemorySize != NULL) delete minMemorySize;
	minMemorySize = NULL;
	if (minCPUSpeed != NULL) delete minCPUSpeed;
	minCPUSpeed = NULL;
	if (otherOptions != NULL) delete otherOptions;
	otherOptions = NULL;
}//end SystemOption destructor 


ServiceOption::ServiceOption(): 
	type ("")
{    
	#ifdef DEBUG
	cout << "Inside ServiceOption Constructor" << endl;
	#endif
	otherOptions = NULL;
}// end ServiceOption constructor  

ServiceOption::~ServiceOption()
{    
	#ifdef DEBUG
	cout << "ServiceOption Destructor Called" << endl;
	#endif
	if (otherOptions != NULL) delete otherOptions;
	otherOptions = NULL;
}//end ServiceOption destructor 


MaxTime::MaxTime():
	unit ("second"),
	value (OSDBL_MAX)
{
	#ifdef DEBUG
	cout << "Inside MaxTime Constructor" << endl;
	#endif
}// end MaxTime constructor

MaxTime::~MaxTime()
{
	#ifdef DEBUG
	cout << "MaxTime Destructor Called" << endl;
	#endif
}// end MaxTime constructor


JobDependencies::JobDependencies():
	numberOfJobIDs (0)
{    
	#ifdef DEBUG
	cout << "Inside JobDependencies Constructor" << endl;
	#endif
	jobID = NULL;
}// end JobDependencies constructor  

JobDependencies::~JobDependencies()
{    
	#ifdef DEBUG
	cout << "JobDependencies Destructor Called" << endl;
	#endif
	if (jobID != NULL) 
	{	delete []jobID;
		jobID = NULL;
	}
}//end JobDependencies destructor 


DirectoriesAndFiles::DirectoriesAndFiles():
	numberOfPaths (0)
{    
	#ifdef DEBUG
	cout << "Inside DirectoriesAndFiles Constructor" << endl;
	#endif
	path = NULL;
}// end DirectoriesAndFiles constructor  template

DirectoriesAndFiles::~DirectoriesAndFiles()
{    
	#ifdef DEBUG
	cout << "DirectoriesAndFiles Destructor Called" << endl;
	#endif
	if (path != NULL) 
	{	delete []path;
		path = NULL;
	}
}//end DirectoriesAndFiles destructor 


PathPair::PathPair():
	from (""),
	to (""),
	makeCopy (false)
{    
	#ifdef DEBUG
	cout << "Inside PathPair Constructor" << endl;
	#endif
}// end PathPair constructor  

PathPair::~PathPair()
{    
	#ifdef DEBUG
	cout << "PathPair Destructor Called" << endl;
	#endif
}//end PathPair destructor 


PathPairs::PathPairs():
	numberOfPathPairs(0)
{    
	#ifdef DEBUG
	cout << "Inside PathPairs Constructor" << endl;
	#endif
	pathPair = NULL;
}// end PathPairs constructor  

PathPairs::~PathPairs()
{    
	#ifdef DEBUG
	cout << "PathPairs Destructor Called" << endl;
	#endif
	if (pathPair != NULL) 
	{	for (int i=0; i < numberOfPathPairs; i++)	
		{	delete pathPair[i];
			pathPair[i] = NULL;
		}
		delete[] pathPair;
		pathPair = NULL;
	}
}//end PathPairs destructor 



Processes::Processes():
	numberOfProcesses(0)
{    
	#ifdef DEBUG
	cout << "Inside Processes Constructor" << endl;
	#endif
	process = NULL;
}// end Processes constructor  

Processes::~Processes()
{    
	#ifdef DEBUG
	cout << "Processes Destructor Called" << endl;
	#endif
	if (process != NULL) 
	{	delete []process;
		process = NULL;
	}
}//end Processes destructor 


JobOption::JobOption():
	scheduledStartTime("")
{    
	#ifdef DEBUG
	cout << "Inside JobOption Constructor" << endl;
	#endif
	maxTime = NULL;
	dependencies = NULL;
	requiredDirectories = NULL;
	requiredFiles = NULL;
	directoriesToMake = NULL;
	filesToCreate = NULL;
	inputDirectoriesToMove = NULL;
	inputFilesToMove = NULL;
	outputFilesToMove = NULL;
	outputDirectoriesToMove = NULL;
	filesToDelete = NULL;
	directoriesToDelete = NULL;
	processesToKill = NULL;
	otherOptions = NULL;
}// end JobOption constructor  

JobOption::~JobOption()
{    
	#ifdef DEBUG
	cout << "JobOption Destructor Called" << endl;
	#endif
	if (maxTime != NULL) delete maxTime;
	maxTime = NULL;
	if (dependencies != NULL) delete dependencies;
	dependencies = NULL;
	if (requiredDirectories != NULL) delete requiredDirectories;
	requiredDirectories = NULL;
	if (requiredFiles != NULL) delete requiredFiles;
	requiredFiles = NULL;
	if (directoriesToMake != NULL) delete directoriesToMake;
	directoriesToMake = NULL;
	if (filesToCreate != NULL) delete filesToCreate;
	filesToCreate = NULL;
	if (inputDirectoriesToMove != NULL) delete inputDirectoriesToMove;
	inputDirectoriesToMove = NULL;
	if (inputFilesToMove != NULL) delete inputFilesToMove;
	inputFilesToMove = NULL;
	if (outputDirectoriesToMove != NULL) delete outputDirectoriesToMove;
	outputDirectoriesToMove = NULL;
	if (outputFilesToMove != NULL) delete outputFilesToMove;
	outputFilesToMove = NULL;
	if (filesToDelete != NULL) delete filesToDelete;
	filesToDelete = NULL;
	if (directoriesToDelete != NULL) delete directoriesToDelete;
	directoriesToDelete = NULL;
	if (processesToKill != NULL) delete processesToKill;
	processesToKill = NULL;
	if (otherOptions != NULL) delete otherOptions;
	otherOptions = NULL;
}//end JobOption destructor 


InitVarValue::InitVarValue(): 
	idx (-1),
	value (OSNAN)
{    
	#ifdef DEBUG
	cout << "Inside InitVarValue Constructor" << endl;
	#endif
}// end InitVarValue constructor  

InitVarValue::~InitVarValue()
{    
	#ifdef DEBUG
	cout << "InitVarValue Destructor Called" << endl;
	#endif
}//end InitVarValue destructor 


InitVariableValues::InitVariableValues():
	numberOfVar (0)
{    
	#ifdef DEBUG
	cout << "Inside InitVariableValues Constructor" << endl;
	#endif
	var = NULL;
}// end InitVariableValues constructor  

InitVariableValues::~InitVariableValues()
{    
	#ifdef DEBUG
	cout << "InitVariableValues Destructor Called" << endl;
	#endif
	if (var != NULL) 
	{	for (int i=0; i < numberOfVar; i++)
		{	delete var[i];
			var[i] = NULL;
		}
		delete[] var;
		var = NULL;
	}
}//end InitVariableValues destructor 


InitVarValueString::InitVarValueString(): 
	idx (-1),
	value ("")
{    
	#ifdef DEBUG
	cout << "Inside InitVarValueString Constructor" << endl;
	#endif
}// end InitVarValueString constructor  

InitVarValueString::~InitVarValueString()
{    
	#ifdef DEBUG
	cout << "InitVarValueString Destructor Called" << endl;
	#endif
}//end InitVarValueString destructor 


InitVariableValuesString::InitVariableValuesString():
	numberOfVar (0)
{    
	#ifdef DEBUG
	cout << "Inside InitVariableValuesString Constructor" << endl;
	#endif
	var = NULL;
}// end InitVariableValuesString constructor  

InitVariableValuesString::~InitVariableValuesString()
{    
	#ifdef DEBUG
	cout << "InitVariableValuesString Destructor Called" << endl;
	#endif
	if (var != NULL) 
	{	for (int i=0; i < numberOfVar; i++)
		{	delete var[i];
			var[i] = NULL;
		}
		delete[] var;
		var = NULL;
	}
}//end InitVariableValues destructor 

InitBasStatus::InitBasStatus(): 
	idx (-1),
	value ("")
{    
	#ifdef DEBUG
	cout << "Inside InitBasStatus Constructor" << endl;
	#endif
}// end InitBasStatus constructor  

InitBasStatus::~InitBasStatus()
{    
	#ifdef DEBUG
	cout << "InitBasStatus Destructor Called" << endl;
	#endif
}//end InitBasStatus destructor 


InitialBasisStatus::InitialBasisStatus():
	numberOfVar (0)
{    
	#ifdef DEBUG
	cout << "Inside InitialBasisStatus Constructor" << endl;
	#endif
	var = NULL;
}// end InitialBasisStatus constructor  

InitialBasisStatus::~InitialBasisStatus()
{    
	#ifdef DEBUG
	cout << "InitialBasisStatus Destructor Called" << endl;
	#endif
	if (var != NULL) 
	{	for (int i=0; i < numberOfVar; i++)
		{	delete var[i];
			var[i] = NULL;
		}
		delete[] var;
		var = NULL;
	}
}//end InitialBasisStatus destructor 


OtherVarOption::OtherVarOption(): 
	idx (0),
	value (""),
	lbValue (""),
	ubValue ("")
{    
	#ifdef DEBUG
	cout << "Inside OtherVarOption Constructor" << endl;
	#endif
}// end OtherVarOption constructor  

OtherVarOption::~OtherVarOption()
{    
	#ifdef DEBUG
	cout << "OtherVarOption Destructor Called" << endl;
	#endif
}//end OtherVarOption destructor 


OtherVariableOption::OtherVariableOption(): 
	numberOfVar (0),
	name (""),
	value (""),
	solver(""),
	category (""),
	type (""),
	description ("")
{    
	#ifdef DEBUG
	cout << "Inside OtherVariableOption Constructor" << endl;
	#endif
	var = NULL;
}// end OtherVariableOption constructor  

OtherVariableOption::~OtherVariableOption()
{    
	#ifdef DEBUG
	cout << "OtherVariableOption Destructor Called" << endl;
	#endif
	if (var != NULL) {
		for (int i=0; i < numberOfVar; i++)
		{	delete var[i];
			var[i] = NULL;
		}
		delete[] var;
		var = NULL;
	};
}//end OtherVariableOption destructor 


VariableOption::VariableOption():
	numberOfOtherVariableOptions(0)
{    
	#ifdef DEBUG
	cout << "Inside VariableOption Constructor" << endl;
	#endif
	initialVariableValues = NULL;
	initialVariableValuesString = NULL;
	initialBasisStatus = NULL;
	other = NULL;
}// end VariableOption constructor  

VariableOption::~VariableOption()
{    
	#ifdef DEBUG
	cout << "VariableOption Destructor Called" << endl;
	#endif
	if (initialVariableValues != NULL) delete initialVariableValues;
	initialVariableValues = NULL;
	if (initialVariableValuesString != NULL) delete initialVariableValuesString;
	initialVariableValuesString = NULL;
	if (initialBasisStatus != NULL) delete initialBasisStatus;
	initialBasisStatus = NULL;
	if (other != NULL) 
	{   for (int i=0; i < numberOfOtherVariableOptions; i++)
		{	if (other[i] != NULL)
				delete other[i];
				other[i] = NULL;
		
		};
 		delete[] other;
		other = NULL;
	};
}//end VariableOption destructor 


InitObjValue::InitObjValue(): 
	idx (0),
	value (0.0)
{    
	#ifdef DEBUG
	cout << "Inside InitObjValue Constructor" << endl;
	#endif
}// end InitObjValue constructor  

InitObjValue::~InitObjValue()
{    
	#ifdef DEBUG
	cout << "InitObjValue Destructor Called" << endl;
	#endif
}//end InitObjValue destructor 


InitObjectiveValues::InitObjectiveValues():
	numberOfObj (0)
{    
	#ifdef DEBUG
	cout << "Inside InitObjectiveValues Constructor" << endl;
	#endif
	obj = NULL;
}// end InitObjectiveValues constructor  

InitObjectiveValues::~InitObjectiveValues()
{    
	#ifdef DEBUG
	cout << "InitObjectiveValues Destructor Called" << endl;
	#endif
	if (obj != NULL) 
	{	for (int i=0; i < numberOfObj; i++)
		{	delete obj[i];
			obj[i] = NULL;
		}
		delete[] obj;
		obj = NULL;
	};
}//end InitObjectiveValues destructor 


InitObjBound::InitObjBound(): 
	idx (0),
	lbValue (0.0),
	ubValue (0.0)
{    
	#ifdef DEBUG
	cout << "Inside InitObjBound Constructor" << endl;
	#endif
}// end  constructor  template

InitObjBound::~InitObjBound()
{    
	#ifdef DEBUG
	cout << "InitObjBound Destructor Called" << endl;
	#endif
}//end InitObjBound destructor 


InitObjectiveBounds::InitObjectiveBounds():
	numberOfObj (0)
{    
	#ifdef DEBUG
	cout << "Inside InitObjectiveBounds Constructor" << endl;
	#endif
	obj = NULL;
}// end InitObjectiveBounds constructor  

InitObjectiveBounds::~InitObjectiveBounds()
{    
	#ifdef DEBUG
	cout << "InitObjectiveBounds Destructor Called" << endl;
	#endif
	if (obj != NULL) 
	{	for (int i=0; i < numberOfObj; i++)
		{	delete obj[i];
			obj[i] = NULL;
		}
		delete[] obj;
		obj = NULL;
	};
}//end InitObjectiveBounds destructor 


OtherObjOption::OtherObjOption(): 
	idx (0),
	value ("")
{    
	#ifdef DEBUG
	cout << "Inside OtherObjOption Constructor" << endl;
	#endif
}// end OtherObjOption constructor  

OtherObjOption::~OtherObjOption()
{    
	#ifdef DEBUG
	cout << "OtherObjOption Destructor Called" << endl;
	#endif
}//end OtherObjOption destructor 


OtherObjectiveOption::OtherObjectiveOption(): 
	numberOfObj (0),
	name (""),
	value (""),
	solver(""),
	category (""),
	type (""),
	description ("")
{    
	#ifdef DEBUG
	cout << "Inside OtherObjectiveOption Constructor" << endl;
	#endif
	obj = NULL;
}// end OtherObjectiveOption constructor  

OtherObjectiveOption::~OtherObjectiveOption()
{    
	#ifdef DEBUG
	cout << "OtherObjectiveOption Destructor Called" << endl;
	#endif
	if (obj != NULL) 
	{	for (int i=0; i < numberOfObj; i++)
		{	delete obj[i];
			obj[i] = NULL;
		}
		delete obj;
		obj = NULL;
	};
}//end OtherObjectiveOption destructor 


ObjectiveOption::ObjectiveOption(): 
	numberOfOtherObjectiveOptions (0)
{    
	#ifdef DEBUG
	cout << "Inside ObjectiveOption Constructor" << endl;
	#endif
	initialObjectiveValues = NULL;
	initialObjectiveBounds = NULL;
	other = NULL;
}// end ObjectiveOption constructor  

ObjectiveOption::~ObjectiveOption()
{    
	#ifdef DEBUG
	cout << "ObjectiveOption Destructor Called" << endl;
	#endif
	if (initialObjectiveValues != NULL) delete initialObjectiveValues;
	initialObjectiveValues = NULL;
	if (initialObjectiveBounds != NULL) delete initialObjectiveBounds;
	initialObjectiveBounds = NULL;
	if (other != NULL) 
	{	for (int i=0; i < numberOfOtherObjectiveOptions; i++)
		{	delete other[i];
			other[i] = NULL;
		}
		delete other;
		other = NULL;
	}
}//end ObjectiveOption destructor 


InitConValue::InitConValue(): 
	idx (0),
	value (0.0)
{    
	#ifdef DEBUG
	cout << "Inside InitConValue Constructor" << endl;
	#endif
}// end InitConValue constructor  

InitConValue::~InitConValue()
{    
	#ifdef DEBUG
	cout << "InitConValue Destructor Called" << endl;
	#endif
}//end InitConValue destructor 


InitConstraintValues::InitConstraintValues(): 
	numberOfCon (0)
{    
	#ifdef DEBUG
	cout << "Inside InitConstraintValues Constructor" << endl;
	#endif
	con = NULL;
}// end InitConstraintValues constructor  

InitConstraintValues::~InitConstraintValues()
{    
	#ifdef DEBUG
	cout << "InitConstraintValues Destructor Called" << endl;
	#endif
	if (con != NULL) 
	{	for (int i=0; i < numberOfCon; i++)
		{	delete con[i];
			con[i] = NULL;
		}
		delete[] con;
		con = NULL;
	};
}//end InitConstraintValues destructor


InitDualVarValue::InitDualVarValue(): 
	idx (0),
	lbValue (0.0),
	ubValue (0.0)
{    
	#ifdef DEBUG
	cout << "Inside InitDualVarValue Constructor" << endl;
	#endif
}// end InitDualVarValue constructor  

InitDualVarValue::~InitDualVarValue()
{    
	#ifdef DEBUG
	cout << "InitDualVarValue Destructor Called" << endl;
	#endif
}//end InitDualVarValue destructor


InitDualVariableValues::InitDualVariableValues(): 
	numberOfCon (0)
{    
	#ifdef DEBUG
	cout << "Inside InitDualVariableValues Constructor" << endl;
	#endif
	con = NULL;
}// end InitDualVariableValues constructor  

InitDualVariableValues::~InitDualVariableValues()
{    
	#ifdef DEBUG
	cout << "InitDualVariableValues Destructor Called" << endl;
	#endif
	if (con != NULL) 
	{	for (int i=0; i < numberOfCon; i++)
		{	delete con[i];
			con[i] = NULL;
		}
		delete[] con;
		con = NULL;
	};
}//end InitDualVariableValues destructor


OtherConOption::OtherConOption(): 
	idx (0),
	value (""),
	lbValue (""),
	ubValue ("")
{    
	#ifdef DEBUG
	cout << "Inside OtherConOption Constructor" << endl;
	#endif
}// end OtherConOption constructor  

OtherConOption::~OtherConOption()
{    
	#ifdef DEBUG
	cout << "OtherConOption Destructor Called" << endl;
	#endif
}//end OtherConOption destructor


OtherConstraintOption::OtherConstraintOption(): 
	numberOfCon(0),
	name (""),
	value (""),
	solver(""),
	category (""),
	type (""),
	description ("")
{    
	#ifdef DEBUG
	cout << "Inside OtherConstraintOption Constructor" << endl;
	#endif
	con = NULL;
}// end OtherConstraintOption constructor  

OtherConstraintOption::~OtherConstraintOption()
{    
	#ifdef DEBUG
	cout << "OtherConstraintOption Destructor Called" << endl;
	#endif
	if (con != NULL) 
	{	for (int i=0; i < numberOfCon; i++)
		{	delete con[i];
			con[i] = NULL;
		}
		delete con;
		con = NULL;
	};
}//end OtherConstraintOption destructor


ConstraintOption::ConstraintOption(): 
	numberOfOtherConstraintOptions (0)
{    
	#ifdef DEBUG
	cout << "Inside ConstraintOption Constructor" << endl;
	#endif
	initialConstraintValues = NULL;
	initialDualValues = NULL;
	other = NULL;
}// end ConstraintOption constructor  

ConstraintOption::~ConstraintOption()
{    
	#ifdef DEBUG
	cout << "ConstraintOption Destructor Called" << endl;
	#endif
	if (initialConstraintValues != NULL) delete initialConstraintValues;
	initialConstraintValues = NULL;
	if (initialDualValues != NULL) delete initialDualValues;
	initialDualValues = NULL;
	if (other != NULL) 
	{	for (int i=0; i < numberOfOtherConstraintOptions; i++)
		{	delete other[i];
			other[i] = NULL;
		}
		delete other;
		other = NULL;
	}
}//end ConstraintOption destructor


SolverOption::SolverOption(): 
	name (""),
	value (""),
	solver(""),
	category (""),
	type (""),
	description ("")
{    
	#ifdef DEBUG
	cout << "Inside SolverOption Constructor" << endl;
	#endif
}// end SolverOption constructor  

SolverOption::~SolverOption()
{    
	#ifdef DEBUG
	cout << "SolverOption Destructor Called" << endl;
	#endif
}//end SolverOption destructor


SolverOptions::SolverOptions(): 
	numberOfSolverOptions(0)
{    
	#ifdef DEBUG
	cout << "Inside SolverOptions Constructor" << endl;
	#endif
	solverOption = NULL;
}// end SolverOptions constructor 

SolverOptions::~SolverOptions()
{    
	#ifdef DEBUG
	cout << "SolverOptions Destructor Called" << endl;
	#endif
	if (solverOption != NULL)
	{	for ( int i=0; i<numberOfSolverOptions; i++)
		{	delete solverOption[i];
			solverOption[i] = NULL;
		}
		delete[] solverOption;
		solverOption = NULL;
	}
}//end SolverOptions destructor


OptimizationOption::OptimizationOption(): 
	numberOfVariables (0),
	numberOfObjectives (0),
	numberOfConstraints (0)
{    
	#ifdef DEBUG
	cout << "Inside OptimizationOption Constructor" << endl;
	#endif
	variables = NULL;
	objectives = NULL;
	constraints = NULL;
	solverOptions = NULL;
}// end OptimizationOption constructor  

OptimizationOption::~OptimizationOption()
{    
	#ifdef DEBUG
	cout << "OptimizationOption Destructor Called" << endl;
	#endif
	if (variables != NULL) delete variables;
	variables = NULL;
	if (objectives != NULL) delete objectives;
	objectives = NULL;
	if (constraints != NULL) delete constraints;
	constraints = NULL;
	if (solverOptions != NULL) delete solverOptions;
	solverOptions = NULL;
}//end OptimizationOption destructor


OSOption::OSOption() :
//(initializations)
	general( NULL),
	system( NULL),
	service( NULL),
	job( NULL),
	optimization( NULL)
{    
	#ifdef DEBUG
	cout << "Inside OSOption Constructor" << endl;
	#endif

}// end OSOption constructor  

OSOption::~OSOption()
{    
	#ifdef DEBUG
	cout << "OSOption Destructor Called" << endl;
	#endif
	if (general != NULL) delete general;
	general = NULL;
	if (system != NULL) delete system;
	system = NULL;
	if (service != NULL) delete service;
	service = NULL;
	if (job != NULL) delete job;
	job = NULL;
	if (optimization != NULL) delete optimization;
	optimization = NULL;
}//end OSOption destructor




/****************************************************************
 * get() methods
 */

/** 
 * get() methods that return strings
 */

std::string  OSOption::getServiceURI()
{	if (this->general != NULL) 
		return this->general->serviceURI;

	return "";
}//getServiceURI

std::string  OSOption::getServiceName()
{	if (this->general != NULL) 
		return this->general->serviceName;

	return "";
}//getServiceName

std::string  OSOption::getInstanceName()
{	if (this->general != NULL) 
		return this->general->instanceName;

	return "";
}//getInstanceName

std::string  OSOption::getInstanceLocation()
{	if (this->general != NULL) 
		if (this->general->instanceLocation != NULL)
			return this->general->instanceLocation->value;

	return "";
}//getInstanceLocation

std::string  OSOption::getLocationType()
{	if (this->general != NULL) 
		if (this->general->instanceLocation != NULL)
			return this->general->instanceLocation->locationType;

	return "";
}//getLocationType

std::string  OSOption::getJobID()
{	if (this->general != NULL) 
		return this->general->jobID;

	return "";
}//getJobID

std::string  OSOption::getSolverName()
{	if (this->general != NULL) 
		return this->general->solverToInvoke;

	return "";
}//getSolverName

std::string  OSOption::getLicense()
{	if (this->general != NULL) 
		return this->general->license;

	return "";
}//getLicense

std::string  OSOption::getUserName()
{	if (this->general != NULL) 
		return this->general->userName;

	return "";
}//getUserName

std::string  OSOption::getPassword()
{	if (this->general != NULL) 
		return this->general->password;

	return "";
}//getPassword

std::string  OSOption::getContact()
{	if (this->general != NULL) 
		if (this->general->contact != NULL)
			return this->general->contact->value;

	return "";
}//getContact

std::string  OSOption::getTransportType()
{	if (this->general != NULL) 
		if (this->general->contact != NULL)
			return this->general->contact->transportType;

	return "";
}//getTransportType

std::string  OSOption::getMinDiskSpaceUnit()
{	if (this->system != NULL) 
		if (this->system->minDiskSpace != NULL)
			return this->system->minDiskSpace->unit;

	return "";
}//getMinDiskSpaceUnit

std::string  OSOption::getMinMemoryUnit()
{	if (this->system != NULL) 
		if (this->system->minMemorySize != NULL)
			return this->system->minMemorySize->unit;

	return "";
}//getMinMemory

std::string  OSOption::getMinCPUSpeedUnit()
{	if (this->system != NULL) 
		if (this->system->minCPUSpeed != NULL)
			return this->system->minCPUSpeed->unit;

	return "";
}//getMinCPUSpeed

std::string  OSOption::getServiceType()
{	if (this->service != NULL) 
		return this->service->type;

	return "";
}//getServiceType

std::string  OSOption::getMaxTimeUnit()
{	if (this->job != NULL) 
		if (this->job->maxTime != NULL)
			return this->job->maxTime->unit;

	return "";
}//getMaxTimeUnit

std::string  OSOption::getScheduledStartTime()
{	if (this->job != NULL) 
		return this->job->scheduledStartTime;

	return "";
}//getScheduledStartTime

std::string  OSOption::getOptionStr(std::string optionName)
{	if (optionName == "serviceURI") 
		return this->getServiceURI();

	if (optionName == "serviceName") 
		return this->getServiceName();

	if (optionName == "instanceName") 
		return this->getInstanceName();

	if (optionName == "instanceLocation") 
		return this->getInstanceLocation();

	if (optionName == "locationType") 
		return this->getLocationType();

	if (optionName == "jobID") 
		return this->getJobID();

	if (optionName == "solverName") 
		return this->getSolverName();

	if (optionName == "license") 
		return this->getLicense();

	if (optionName == "userName") 
		return this->getUserName();

	if (optionName == "password") 
		return this->getPassword();

	if (optionName == "contact") 
		return this->getContact();

	if (optionName == "transportType") 
		return this->getTransportType();

	if (optionName == "minDiskSpaceUnit") 
		return this->getMinDiskSpaceUnit();

	if (optionName == "minMemoryUnit") 
		return this->getMinMemoryUnit();

	if (optionName == "minCPUSpeedUnit") 
		return this->getMinCPUSpeedUnit();

	if (optionName == "serviceType") 
		return this->getServiceType();

	if (optionName == "maxTimeUnit") 
		return this->getMaxTimeUnit();

	if (optionName == "scheduledStartTime") 
		return this->getScheduledStartTime();

	return "";
}//getOptionStr

/** 
 * get() methods that return doubles
 */

double  OSOption::getMinDiskSpace()
{	if (this->system != NULL) 
		if (this->system->minDiskSpace != NULL)
			return this->system->minDiskSpace->value;

	return 0;
}//getMinDiskSpace

double  OSOption::getMinMemorySize()
{	if (this->system != NULL) 
		if (this->system->minMemorySize != NULL)
			return this->system->minMemorySize->value;

	return 0;
}//getMinMemorySize

double  OSOption::getMinCPUSpeed()
{	if (this->system != NULL) 
		if (this->system->minCPUSpeed != NULL)
			return this->system->minCPUSpeed->value;

	return 0;
}//getMinCPUSpeed

double  OSOption::getMaxTime()
{	if (this->job != NULL) 
		if (this->job->maxTime != NULL)
			return job->maxTime->value;

	return 0;
}//getMaxTime

double  OSOption::getOptionDbl(std::string optionName)
{	if (optionName == "minDiskSpace") 
		return this->getMinDiskSpace();

	if (optionName == "minMemory") 
		return this->getMinMemorySize();

	if (optionName == "minCPUSpeed") 
		return this->getMinCPUSpeed();

	if (optionName == "maxTime") 
		return this->getMaxTime();

	return 0;
}//getOptionDbl

/** 
 * get() methods that return integers
 */

int  OSOption::getMinCPUNumber()
{	if (this->system != NULL) 
		return this->system->minCPUNumber;

	return 0;
}//getMinCPUNumber

int  OSOption::getNumberOfOtherGeneralOptions()
{	if (this->general != NULL) 
		if (this->general->otherOptions != NULL) 
			return this->general->otherOptions->numberOfOtherOptions;

	return 0;
}//getNumberOfOtherGeneralOptions

int  OSOption::getNumberOfOtherSystemOptions()
{	if (this->system != NULL) 
		if (this->system->otherOptions != NULL) 
			return this->system->otherOptions->numberOfOtherOptions;

	return 0;
}//getNumberOfOtherSystemOptions

int  OSOption::getNumberOfOtherServiceOptions()
{	if (this->service != NULL) 
		if (this->service->otherOptions != NULL) 
			return this->service->otherOptions->numberOfOtherOptions;

	return 0;
}//getNumberOfOtherServiceOptions

int  OSOption::getNumberOfOtherJobOptions()
{	if (this->job != NULL) 
		if (this->job->otherOptions != NULL) 
			return this->job->otherOptions->numberOfOtherOptions;

	return 0;
}//getNumberOfOtherJobOptions

int  OSOption::getNumberOfJobDependencies()
{	if (this->job != NULL) 
		if (this->job->dependencies != NULL) 
			return this->job->dependencies->numberOfJobIDs;

	return 0;
}//getNumberOfJobDependencies

int  OSOption::getNumberOfRequiredDirectories()
{	if (this->job != NULL) 
		if (this->job->requiredDirectories != NULL) 
			return this->job->requiredDirectories->numberOfPaths;

	return 0;
}//getNumberOfRequiredDirectories

int  OSOption::getNumberOfRequiredFiles()
{	if (this->job != NULL) 
		if (this->job->requiredFiles != NULL) 
			return this->job->requiredFiles->numberOfPaths;

	return 0;
}//getNumberOfRequiredFiles

int  OSOption::getNumberOfDirectoriesToMake()
{	if (this->job != NULL) 
		if (this->job->directoriesToMake != NULL) 
			return this->job->directoriesToMake->numberOfPaths;

	return 0;
}//getNumberOfDirectoriesToMake

int  OSOption::getNumberOfFilesToCreate()
{	if (this->job != NULL) 
		if (this->job->filesToCreate != NULL) 
			return this->job->filesToCreate->numberOfPaths;

	return 0;
}//getNumberOfFilesToCreate

int  OSOption::getNumberOfInputDirectoriesToMove()
{	if (this->job != NULL) 
		if (this->job->inputDirectoriesToMove != NULL) 
			return this->job->inputDirectoriesToMove->numberOfPathPairs;

	return 0;
}//getNumberOfInputDirectoriesToMove

int  OSOption::getNumberOfInputFilesToMove()
{	if (this->job != NULL) 
		if (this->job->inputFilesToMove != NULL) 
			return this->job->inputFilesToMove->numberOfPathPairs;

	return 0;
}//getNumberOfInputFilesToMove

int  OSOption::getNumberOfOutputDirectoriesToMove()
{	if (this->job != NULL) 
		if (this->job->outputDirectoriesToMove != NULL) 
			return this->job->outputDirectoriesToMove->numberOfPathPairs;

	return 0;
}//getNumberOfOutputDirectoriesToMove

int  OSOption::getNumberOfOutputFilesToMove()
{	if (this->job != NULL) 
		if (this->job->outputFilesToMove != NULL) 
			return this->job->outputFilesToMove->numberOfPathPairs;

	return 0;
}//getNumberOfOutputFilesToMove

int  OSOption::getNumberOfFilesToDelete()
{	if (this->job != NULL) 
		if (this->job->filesToDelete != NULL) 
			return this->job->filesToDelete->numberOfPaths;

	return 0;
}//getNumberOfFilesToDelete

int  OSOption::getNumberOfDirectoriesToDelete()
{	if (this->job != NULL) 
		if (this->job->directoriesToDelete != NULL) 
			return this->job->directoriesToDelete->numberOfPaths;

	return 0;
}//getNumberOfDirectoriesToDelete

int  OSOption::getNumberOfProcessesToKill()
{	if (this->job != NULL) 
		if (this->job->processesToKill != NULL) 
			return this->job->processesToKill->numberOfProcesses;

	return 0;
}//getNumberOfProcessesToKill

int  OSOption::getNumberOfVariables()
{	if (this->optimization != NULL) 
		return this->optimization->numberOfVariables;

	return 0;
}//getNumberOfVariables

int  OSOption::getNumberOfObjectives()
{	if (this->optimization != NULL) 
		return this->optimization->numberOfObjectives;

	return 0;
}//getNumberOfObjectives

int  OSOption::getNumberOfConstraints()
{	if (this->optimization != NULL) 
		return this->optimization->numberOfConstraints;

	return 0;
}//getNumberOfConstraints


int OSOption::getNumberOfInitVarValues(){
	if (this->optimization != NULL) {
		if(this->optimization->variables != NULL) {
			if(this->optimization->variables->initialVariableValues != NULL) {
				return this->optimization->variables->initialVariableValues->numberOfVar;
			}
		}
	}
	return -1;
}//getNumberOfInitVarValues

int OSOption::getNumberOfInitVarValuesString(){
	if (this->optimization != NULL) {
		if(this->optimization->variables != NULL) {
			if(this->optimization->variables->initialVariableValuesString != NULL) {
				return this->optimization->variables->initialVariableValuesString->numberOfVar;
			}
		}
	}
	return -1;
}//getNumberOfInitVarValuesString

int OSOption::getNumberOfInitialBasisVariables(){
	if (this->optimization != NULL) {
		if(this->optimization->variables != NULL) {
			if(this->optimization->variables->initialBasisStatus != NULL) {
				return this->optimization->variables->initialBasisStatus ->numberOfVar;
			}
		}
	}
	return -1;
}//getNumberOfInitialBasisVariables


int OSOption::getNumberOfOtherVariableOptions()
{	if (this->optimization != NULL)
		if (this->optimization->variables != NULL)
			return this->optimization->variables->numberOfOtherVariableOptions;

	return 0;
}//getNumberOfOtherVariableOptions

int OSOption::getNumberOfInitObjValues(){
	if (this->optimization != NULL) {
		if(this->optimization->objectives != NULL) {
			if(this->optimization->objectives->initialObjectiveValues != NULL) {
				return this->optimization->objectives->initialObjectiveValues->numberOfObj;
			}
		}
	}
	return -1;
}//getNumberOfInitObjValues

int OSOption::getNumberOfInitObjBounds(){
	if (this->optimization != NULL) {
		if(this->optimization->objectives != NULL) {
			if(this->optimization->objectives->initialObjectiveBounds != NULL) {
				return this->optimization->objectives->initialObjectiveBounds->numberOfObj;
			}
		}
	}
	return -1;
}//getNumberOfInitObjBounds

int OSOption::getNumberOfOtherObjectiveOptions()
{	if (this->optimization != NULL)
		if (this->optimization->objectives != NULL)
			return this->optimization->objectives->numberOfOtherObjectiveOptions;

	return 0;
}//getNumberOfOtherObjectiveOptions

int OSOption::getNumberOfInitConValues(){
	if (this->optimization != NULL) {
		if(this->optimization->constraints != NULL) {
			if(this->optimization->constraints->initialConstraintValues != NULL) {
				return this->optimization->constraints->initialConstraintValues->numberOfCon;
			}
		}
	}
	return -1;
}//getNumberOfInitConValues

int OSOption::getNumberOfInitDualVarValues(){
	if (this->optimization != NULL) {
		if(this->optimization->constraints != NULL) {
			if(this->optimization->constraints->initialDualValues != NULL) {
				return this->optimization->constraints->initialDualValues->numberOfCon;
			}
		}
	}
	return -1;
}//getNumberOfInitDualVarValues

int OSOption::getNumberOfOtherConstraintOptions()
{	if (this->optimization != NULL)
		if (this->optimization->constraints != NULL)
			return this->optimization->constraints->numberOfOtherConstraintOptions;

	return -1;
}//getNumberOfOtherConstraintOptions

int OSOption::getNumberOfSolverOptions(){
	if (this->optimization != NULL) {
		if(this->optimization->solverOptions != NULL) {
			return this->optimization->solverOptions->numberOfSolverOptions;
		}
	}
	return -1;
}//getNumberOfSolverOptions

int  OSOption::getOptionInt(std::string optionName)
{	if(optionName == "minCPUNumber")
		this->getMinCPUNumber();

	if(optionName == "numberOfOtherGeneralOptions")
		this->getNumberOfOtherGeneralOptions();

	if(optionName == "numberOfOtherSystemOptions")
		this->getNumberOfOtherSystemOptions();

	if(optionName == "numberOfOtherServiceOptions")
		this->getNumberOfOtherServiceOptions();

	if(optionName == "numberOfOtherJobOptions")
		this->getNumberOfOtherJobOptions();

	if(optionName == "numberOfJobDependencies")
		this->getNumberOfJobDependencies();

	if(optionName == "numberOfRequiredDirectories")
		this->getNumberOfRequiredDirectories();

	if(optionName == "numberOfRequiredFiles")
		this->getNumberOfRequiredFiles();

	if(optionName == "numberOfDirectoriesToMake")
		this->getNumberOfDirectoriesToMake();

	if(optionName == "numberOfFilesToCreate")
		this->getNumberOfFilesToCreate();

	if(optionName == "numberOfInputDirectoriesToMove")
		this->getNumberOfInputDirectoriesToMove();

	if(optionName == "numberOfInputFilesToMove")
		this->getNumberOfInputFilesToMove();

	if(optionName == "numberOfOutputDirectoriesToMove")
		this->getNumberOfOutputDirectoriesToMove();

	if(optionName == "numberOfOutputFilesToMove")
		this->getNumberOfOutputFilesToMove();

	if(optionName == "numberOfFilesToDelete")
		this->getNumberOfFilesToDelete();

	if(optionName == "numberOfDirectoriesToDelete")
		this->getNumberOfDirectoriesToDelete();

	if(optionName == "numberOfProcessesToKill")
		this->getNumberOfProcessesToKill();

	if(optionName == "numberOfVariables")
		this->getNumberOfVariables();

	if(optionName == "numberOfObjectives")
		this->getNumberOfObjectives();

	if(optionName == "numberOfConstraints")
		this->getNumberOfConstraints();

	if(optionName == "numberOfInitVarValues")
		this->getNumberOfInitVarValues();

	if(optionName == "numberOfInitVarValuesString")
		this->getNumberOfInitVarValuesString();

	if(optionName == "numberOfInitialBasisVariables")
		this->getNumberOfInitialBasisVariables();

	if(optionName == "numberOfOtherVariableOptions")
		this->getNumberOfOtherVariableOptions();

	if(optionName == "numberOfInitObjValues")
		this->getNumberOfInitObjValues();

	if(optionName == "numberOfInitObjBounds")
		this->getNumberOfInitObjBounds();

	if(optionName == "numberOfOtherObjectiveOptions")
		this->getNumberOfOtherObjectiveOptions();

	if(optionName == "numberOfInitConValues")
		this->getNumberOfInitConValues();

	if(optionName == "numberOfInitDualVarValues")
		this->getNumberOfInitDualVarValues();

	if(optionName == "numberOfOtherConstraintOptions")
		this->getNumberOfOtherConstraintOptions();

	if(optionName == "numberOfSolverOptions")
		this->getNumberOfSolverOptions();

	return 0;
}//getOptionInt





/** 
 * get() methods that return arrays of various kinds
 */

OtherOption** OSOption::getOtherGeneralOptions()
{	OtherOption** optionVector = NULL;
	if (this->general != NULL) 
	{	if (this->general->otherOptions != NULL)
		{	int num_opt;
			num_opt = this->getNumberOfOtherGeneralOptions();
			optionVector = new OtherOption*[num_opt];
			for(int i = 0; i < num_opt; i++)
				optionVector[i] = this->general->otherOptions->other[ i];
		}					
	}
	return optionVector;
}//getOtherGeneralOptions

OtherOption** OSOption::getOtherSystemOptions()
{	OtherOption** optionVector = NULL;
	if (this->system != NULL) 
	{	if (this->system->otherOptions != NULL)
		{	int num_opt;
			num_opt = this->getNumberOfOtherSystemOptions();
			optionVector = new OtherOption*[num_opt];
			for(int i = 0; i < num_opt; i++)
				optionVector[i] = this->system->otherOptions->other[ i];
		}					
	}
	return optionVector;
}//getOtherSystemOptions

OtherOption** OSOption::getOtherServiceOptions()
{	OtherOption** optionVector = NULL;
	if (this->service != NULL) 
	{	if (this->service->otherOptions != NULL)
		{	int num_opt;
			num_opt = this->getNumberOfOtherServiceOptions();
			optionVector = new OtherOption*[num_opt];
			for(int i = 0; i < num_opt; i++)
				optionVector[i] = this->service->otherOptions->other[ i];
		}					
	}
	return optionVector;
}//getOtherServiceOptions

OtherOption** OSOption::getOtherJobOptions()
{	OtherOption** optionVector = NULL;
	if (this->job != NULL) 
	{	if (this->job->otherOptions != NULL)
		{	int num_opt;
			num_opt = this->getNumberOfOtherJobOptions();
			optionVector = new OtherOption*[num_opt];
			for(int i = 0; i < num_opt; i++)
				optionVector[i] = this->job->otherOptions->other[ i];
		}					
	}
	return optionVector;
}//getOtherJobOptions

OtherOption** OSOption::getOtherOptions(std::string optionName)
{	OtherOption** optionVector = NULL;
	if (optionName == "general")
		return this->getOtherGeneralOptions();

	if (optionName == "system")
		return this->getOtherSystemOptions();

	if (optionName == "service")
		return this->getOtherServiceOptions();

	if (optionName == "job")
		return this->getOtherJobOptions();

}//getOtherOptions

OtherOption** OSOption::getAllOtherOptions()
{	OtherOption** optionVector = NULL;
	int prev_options[4];
	int num_options[4];
	int num_opt;
	for (int i = 0; i < 4; i++)
	{	prev_options[i] = 0;
		num_options[i] = 0;
	}
	if (this->general != NULL) 
	{	if (this->general->otherOptions != NULL)
		{	num_opt = this->getNumberOfOtherGeneralOptions();
			num_options[0] = num_opt;
		}
	}

	if (this->system != NULL) 
	{	if (this->system->otherOptions != NULL)
		{	num_opt = this->getNumberOfOtherSystemOptions();
			num_options[1] = num_opt;
		}
	}
	prev_options[1] = prev_options[0] + num_options[0];

	if (this->service != NULL) 
	{	if (this->service->otherOptions != NULL)
		{	num_opt = this->getNumberOfOtherServiceOptions();
			num_options[2] = num_opt;
		}
	}
	prev_options[2] = prev_options[1] + num_options[1];

	if (this->job != NULL) 
	{	if (this->job->otherOptions != NULL)
		{	num_opt = this->getNumberOfOtherJobOptions();
			num_options[3] = num_opt;
		}
	}
	prev_options[3] = prev_options[2] + num_options[2];

	num_opt = num_options[0] + num_options[1] + num_options[2] + num_options[3];
	optionVector = new OtherOption*[num_opt];

	int j;
	if (num_options[0] > 0)
	{	for(int i = 0; i < num_options[0]; i++)
		{	optionVector[prev_options[0] + i] = this->general->otherOptions->other[i];
		}
	}

	if (num_options[1] > 0)
	{	for(int i = 0; i < num_options[1]; i++)
		{	optionVector[prev_options[1] + i] = this->system->otherOptions->other[i];
		}
	}

	if (num_options[2] > 0)
	{	for(int i = 0; i < num_options[2]; i++)
		{	optionVector[prev_options[2] + i] = this->service->otherOptions->other[i];
		}
	}

	if (num_options[3] > 0)
	{	for(int i = 0; i < num_options[3]; i++)
		{	optionVector[prev_options[3] + i] = this->job->otherOptions->other[i];
		}
	}

	return optionVector;
}//getOtherJobOptions

std::string*  OSOption::getJobDependencies(){
	std::string* dependenciesVector;
	if (this->job != NULL) 
	{	if (this->job->dependencies != NULL) 
		{	int i;
			int num_ID;
			num_ID = this->getNumberOfJobDependencies();
			dependenciesVector = new string[num_ID];
			for(i = 0; i < num_ID; i++)
				dependenciesVector[i] = this->job->dependencies->jobID[ i];
		}					
	}
	return dependenciesVector;
}//getJobDependencies

std::string*  OSOption::getRequiredDirectories(){
	std::string* pathVector;
	if (this->job != NULL) 
	{	if (this->job->requiredDirectories != NULL) 
		{	int i;
			int num_paths;
			num_paths = this->getNumberOfRequiredDirectories();
			pathVector = new string[num_paths];
			for(i = 0; i < num_paths; i++)
				pathVector[i] = this->job->requiredDirectories->path[i];
		}					
	}
	return pathVector;
}//getRequiredDirectories

std::string*  OSOption::getDirectoriesToMake(){
	std::string* pathVector;
	if (this->job != NULL) 
	{	if (this->job->directoriesToMake != NULL) 
		{	int i;
			int num_paths;
			num_paths = this->getNumberOfDirectoriesToMake();
			pathVector = new string[num_paths];
			for(i = 0; i < num_paths; i++)
				pathVector[i] = this->job->directoriesToMake->path[i];
		}					
	}
	return pathVector;
}//getDirectoriesToMake

std::string*  OSOption::getFilesToCreate(){
	std::string* pathVector;
	if (this->job != NULL) 
	{	if (this->job->filesToCreate != NULL) 
		{	int i;
			int num_paths;
			num_paths = this->getNumberOfFilesToCreate();
			pathVector = new string[num_paths];
			for(i = 0; i < num_paths; i++)
				pathVector[i] = this->job->filesToCreate->path[i];
		}					
	}
	return pathVector;
}//getFilesToCreate

PathPair** OSOption::getInputDirectoriesToMove()
{	PathPair** pathPairVector = NULL;
	if (this->job != NULL) 
	{	if(this->job->inputDirectoriesToMove != NULL) 
		{	int num_pp;
			num_pp = this->getNumberOfInputDirectoriesToMove();
			pathPairVector = new PathPair*[num_pp];
			for(int i = 0; i < num_pp; i++)
				pathPairVector[i] = this->job->inputDirectoriesToMove->pathPair[ i];
		}					
	}
	return pathPairVector;
}//getInputDirectoriesToMove

PathPair** OSOption::getInputFilesToMove()
{	PathPair** pathPairVector = NULL;
	if (this->job != NULL) 
	{	if(this->job->inputFilesToMove != NULL) 
		{	int num_pp;
			num_pp = this->getNumberOfInputFilesToMove();
			pathPairVector = new PathPair*[num_pp];
			for(int i = 0; i < num_pp; i++)
				pathPairVector[i] = this->job->inputFilesToMove->pathPair[ i];
		}					
	}
	return pathPairVector;
}//getInputFilesToMove

PathPair** OSOption::getOutputFilesToMove()
{	PathPair** pathPairVector = NULL;
	if (this->job != NULL) 
	{	if(this->job->outputFilesToMove != NULL) 
		{	int num_pp;
			num_pp = this->getNumberOfOutputFilesToMove();
			pathPairVector = new PathPair*[num_pp];
			for(int i = 0; i < num_pp; i++)
				pathPairVector[i] = this->job->outputFilesToMove->pathPair[ i];
		}					
	}
	return pathPairVector;
}//getOutputFilesToMove

PathPair** OSOption::getOutputDirectoriesToMove()
{	PathPair** pathPairVector = NULL;
	if (this->job != NULL) 
	{	if(this->job->outputDirectoriesToMove != NULL) 
		{	int num_pp;
			num_pp = this->getNumberOfOutputDirectoriesToMove();
			pathPairVector = new PathPair*[num_pp];
			for(int i = 0; i < num_pp; i++)
				pathPairVector[i] = this->job->outputDirectoriesToMove->pathPair[ i];
		}					
	}
	return pathPairVector;
}//getOutputDirectoriesToMove

std::string*  OSOption::getFilesToDelete(){
	std::string* pathVector;
	if (this->job != NULL) 
	{	if (this->job->filesToDelete != NULL) 
		{	int num_paths;
			num_paths = this->getNumberOfFilesToDelete();
			pathVector = new string[num_paths];
			for(int i = 0; i < num_paths; i++)
				pathVector[i] = this->job->filesToDelete->path[i];
		}					
	}
	return pathVector;
}//getFilesToDelete

std::string*  OSOption::getDirectoriesToDelete(){
	std::string* pathVector;
	if (this->job != NULL) 
	{	if (this->job->directoriesToDelete != NULL) 
		{	int i;
			int num_paths;
			num_paths = this->getNumberOfDirectoriesToDelete();
			pathVector = new string[num_paths];
			for(i = 0; i < num_paths; i++)
				pathVector[i] = this->job->directoriesToDelete->path[i];
		}					
	}
	return pathVector;
}//getDirectoriesToDelete

std::string*  OSOption::getProcessesToKill(){
	std::string* pathVector;
	if (this->job != NULL) 
	{	if (this->job->processesToKill != NULL) 
		{	int i;
			int num_paths;
			num_paths = this->getNumberOfProcessesToKill();
			pathVector = new string[num_paths];
			for(i = 0; i < num_paths; i++)
				pathVector[i] = this->job->processesToKill->process[i];
		}					
	}
	return pathVector;
}//getProcessesToKill



std::vector<InitVarValue*>  OSOption::getInitVarValuesSparse(){
	std::vector<InitVarValue*> initVarVector;
	if (this->optimization != NULL) {
		if(this->optimization->variables != NULL) {
			if(this->optimization->variables->initialVariableValues != NULL) {
			int i;
			int num_var;
			num_var = this->getNumberOfInitVarValues();
			for(i = 0; i < num_var; i++){
				printf("\n%d\n",this->optimization->variables->initialVariableValues->var[ i]->idx);
				printf("\n%d\n",this->optimization->variables->initialVariableValues->var[ i]->value);
				initVarVector.push_back( this->optimization->variables->initialVariableValues->var[ i]);
				}
			}
		}					
	}
	return initVarVector;
}//getInitVarValuesSparse

double* OSOption::getInitVarValuesDense(int numberOfVariables){
	double *initVarVector;
	initVarVector = new double[numberOfVariables];
	for (int k = 0; k < numberOfVariables; k++) initVarVector[k] = OSNAN;
	try
	{	if (this->optimization != NULL) 
		{	if(this->optimization->variables != NULL) 
			{	if(this->optimization->variables->initialVariableValues != NULL) 
				{	int i,j;
					int num_var;
					num_var = this->getNumberOfInitVarValues();
					for(i = 0; i < num_var; i++)
					{	j = this->optimization->variables->initialVariableValues->var[i]->idx;
						if (j >= 0 && j < numberOfVariables)						
							initVarVector[j] 
							  = this->optimization->variables->initialVariableValues->var[i]->value;						
						else
							throw ErrorClass("Variable index out of range");
					}
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return initVarVector;
}//getInitVarValuesDense


std::vector<InitVarValueString*>  OSOption::getInitVarStringsSparse(){
	std::vector<InitVarValueString*> initVarVector;
	if (this->optimization != NULL) {
		if(this->optimization->variables != NULL) {
			if(this->optimization->variables->initialVariableValuesString != NULL) {
			int i;
			int num_var;
			num_var = this->getNumberOfInitVarValuesString();
			for(i = 0; i < num_var; i++){
				initVarVector.push_back( this->optimization->variables->initialVariableValuesString->var[ i]);
				}
			}
		}					
	}
	return initVarVector;
}//getInitVarStringsSparse

std::string *OSOption::getInitVarStringsDense(int numberOfVariables){
	std::string *initVarVector;
	initVarVector = new std::string[numberOfVariables];
	for (int k = 0; k < numberOfVariables; k++) initVarVector[k] = "";
	try
	{
		if (this->optimization != NULL) 
		{	if(this->optimization->variables != NULL) 
			{	if(this->optimization->variables->initialVariableValuesString != NULL) 
				{	int i,j;
					int num_var;
					num_var = this->getNumberOfInitVarValuesString();
					for(i = 0; i < num_var; i++)
					{	j = this->optimization->variables->initialVariableValuesString->var[i]->idx;
						if (j >= 0 && j < numberOfVariables)
							initVarVector[j] 
							  = this->optimization->variables->initialVariableValuesString->var[i]->value;
						else
							throw ErrorClass("Variable index out of range");
					}
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return initVarVector;
}//getInitVarStringsDense


std::vector<InitObjValue*>  OSOption::getInitObjValuesSparse(){
	std::vector<InitObjValue*> initObjVector;
	if (this->optimization != NULL) {
		if(this->optimization->objectives != NULL) {
			if(this->optimization->objectives->initialObjectiveValues != NULL) {
			int i;
			int num_obj;
			num_obj = this->getNumberOfInitObjValues();
			for(i = 0; i < num_obj; i++){
				printf("\n%d\n",this->optimization->objectives->initialObjectiveValues->obj[ i]->idx);
				printf("\n%d\n",this->optimization->objectives->initialObjectiveValues->obj[ i]->value);
				initObjVector.push_back( this->optimization->objectives->initialObjectiveValues->obj[ i]);
				}
			}
		}					
	}
	return initObjVector;
}//getInitObjValuesSparse

double* OSOption::getInitObjValuesDense(int numberOfObjectives){
	double *initObjVector;
	initObjVector = new double[numberOfObjectives];
	for (int k = 0; k < numberOfObjectives; k++) initObjVector[k] = OSNAN;
	try
	{	if (this->optimization != NULL) 
		{	if(this->optimization->objectives != NULL) 
			{	if(this->optimization->objectives->initialObjectiveValues != NULL) 
				{	int i,j;
					int num_obj;
					num_obj = this->getNumberOfInitObjValues();
					for(i = 0; i < num_obj; i++)
					{	j = this->optimization->objectives->initialObjectiveValues->obj[i]->idx;
						if (j < 0 && -j <= numberOfObjectives)						
							initObjVector[j] 
							  = this->optimization->objectives->initialObjectiveValues->obj[i]->value;						
						else
							throw ErrorClass("Objective index out of range");
					}
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return initObjVector;
}//getInitObjValuesDense


std::vector<InitObjBound*>  OSOption::getInitObjBoundsSparse()
{	std::vector<InitObjBound*> initObjBounds;
	if (this->optimization != NULL) 
	{	if(this->optimization->objectives != NULL) 
		{	if(this->optimization->objectives->initialObjectiveBounds != NULL) 
			{	int i;
				int num_obj;
				num_obj = this->getNumberOfInitObjBounds();
				for(i = 0; i < num_obj; i++)
				{	printf("\n%d\n",this->optimization->objectives->initialObjectiveBounds->obj[ i]->idx);
					printf("\n%d\n",this->optimization->objectives->initialObjectiveBounds->obj[ i]->lbValue);
					printf("\n%d\n",this->optimization->objectives->initialObjectiveBounds->obj[ i]->ubValue);
					initObjBounds.push_back( this->optimization->objectives->initialObjectiveBounds->obj[ i]);
				}
			}
		}					
	}
	return initObjBounds;
}//getInitObjBoundsSparse

double* OSOption::getInitObjLowerBoundsDense(int numberOfObjectives){
	double *initObjBound;
	initObjBound = new double[numberOfObjectives];
	for (int k = 0; k < numberOfObjectives; k++) initObjBound[k] = OSNAN;
	try
	{	if (this->optimization != NULL) 
		{	if(this->optimization->objectives != NULL) 
			{	if(this->optimization->objectives->initialObjectiveBounds != NULL) 
				{	int i,j;
					int num_obj;
					num_obj = this->getNumberOfInitObjBounds();
					for(i = 0; i < num_obj; i++)
					{	j = this->optimization->objectives->initialObjectiveBounds->obj[i]->idx;
						if (j < 0 && -j <= numberOfObjectives)						
							initObjBound[j] 
							  = this->optimization->objectives->initialObjectiveBounds->obj[i]->lbValue;
						else
							throw ErrorClass("Objective index out of range");
					}
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return initObjBound;
}//getInitObjLowerBoundsDense

double* OSOption::getInitObjUpperBoundsDense(int numberOfObjectives){
	double *initObjBound;
	initObjBound = new double[numberOfObjectives];
	for (int k = 0; k < numberOfObjectives; k++) initObjBound[k] = OSNAN;
	try
	{	if (this->optimization != NULL) 
		{	if(this->optimization->objectives != NULL) 
			{	if(this->optimization->objectives->initialObjectiveBounds != NULL) 
				{	int i,j;
					int num_obj;
					num_obj = this->getNumberOfInitObjBounds();
					for(i = 0; i < num_obj; i++)
					{	j = this->optimization->objectives->initialObjectiveBounds->obj[i]->idx;
						if (j < 0 && -j <= numberOfObjectives)						
							initObjBound[j] 
							  = this->optimization->objectives->initialObjectiveBounds->obj[i]->ubValue;
						else
							throw ErrorClass("Objective index out of range");
					}
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return initObjBound;
}//getInitObjUpperBoundsDense


std::vector<InitConValue*>  OSOption::getInitConValuesSparse(){
	std::vector<InitConValue*> initConVector;
	if (this->optimization != NULL) {
		if(this->optimization->constraints != NULL) {
			if(this->optimization->constraints->initialConstraintValues != NULL) {
			int i;
			int num_con;
			num_con = this->getNumberOfInitConValues();
			for(i = 0; i < num_con; i++){
				printf("\n%d\n",this->optimization->constraints->initialConstraintValues->con[ i]->idx);
				printf("\n%d\n",this->optimization->constraints->initialConstraintValues->con[ i]->value);
				initConVector.push_back( this->optimization->constraints->initialConstraintValues->con[ i]);
				}
			}
		}					
	}
	return initConVector;
}//getInitConValuesSparse

double* OSOption::getInitConValuesDense(int numberOfConstraints){
	double *initConVector;
	initConVector = new double[numberOfConstraints];
	for (int k = 0; k < numberOfConstraints; k++) initConVector[k] = OSNAN;
	try
	{	if (this->optimization != NULL) 
		{	if(this->optimization->constraints != NULL) 
			{	if(this->optimization->constraints->initialConstraintValues != NULL) 
				{	int i,j;
					int num_con;
					num_con = this->getNumberOfInitConValues();
					for(i = 0; i < num_con; i++)
					{	j = this->optimization->constraints->initialConstraintValues->con[i]->idx;
						if (j >= 0 && j < numberOfConstraints)						
							initConVector[j] 
							  = this->optimization->constraints->initialConstraintValues->con[i]->value;						
						else
							throw ErrorClass("Constraint index out of range");
					}
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return initConVector;
}//getInitConValuesDense


std::vector<InitDualVarValue*>  OSOption::getInitDualVarValuesSparse(){
	std::vector<InitDualVarValue*> initDualVector;
	if (this->optimization != NULL) {
		if(this->optimization->constraints != NULL) {
			if(this->optimization->constraints->initialDualValues != NULL) {
			int i;
			int num_con;
			num_con = this->getNumberOfInitDualVarValues();
			for(i = 0; i < num_con; i++){
				printf("\n%d\n",this->optimization->constraints->initialDualValues->con[ i]->idx);
				printf("\n%d\n",this->optimization->constraints->initialDualValues->con[ i]->lbValue);
				printf("\n%d\n",this->optimization->constraints->initialDualValues->con[ i]->ubValue);
				initDualVector.push_back( this->optimization->constraints->initialDualValues->con[ i]);
				}
			}
		}					
	}
	return initDualVector;
}//getInitDualVarValuesSparse

double* OSOption::getInitDualVarLowerBoundsDense(int numberOfConstraints){
	double *initDualVector;
	initDualVector = new double[numberOfConstraints];
	for (int k = 0; k < numberOfConstraints; k++) initDualVector[k] = OSNAN;
	try
	{	if (this->optimization != NULL) 
		{	if(this->optimization->constraints != NULL) 
			{	if(this->optimization->constraints->initialDualValues != NULL) 
				{	int i,j;
					int num_con;
					num_con = this->getNumberOfInitDualVarValues();
					for(i = 0; i < num_con; i++)
					{	j = this->optimization->constraints->initialDualValues->con[i]->idx;
						if (j >= 0 && j < numberOfConstraints)						
							initDualVector[j] 
							  = this->optimization->constraints->initialDualValues->con[i]->lbValue;						
						else
							throw ErrorClass("Constraint index out of range");
					}
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return initDualVector;
}//getInitDualVarLowerBoundsDense

double* OSOption::getInitDualVarUpperBoundsDense(int numberOfConstraints){
	double *initDualVector;
	initDualVector = new double[numberOfConstraints];
	for (int k = 0; k < numberOfConstraints; k++) initDualVector[k] = OSNAN;
	try
	{	if (this->optimization != NULL) 
		{	if(this->optimization->constraints != NULL) 
			{	if(this->optimization->constraints->initialDualValues != NULL) 
				{	int i,j;
					int num_con;
					num_con = this->getNumberOfInitDualVarValues();
					for(i = 0; i < num_con; i++)
					{	j = this->optimization->constraints->initialDualValues->con[i]->idx;
						if (j >= 0 && j < numberOfConstraints)						
							initDualVector[j] 
							  = this->optimization->constraints->initialDualValues->con[i]->ubValue;	
						else
							throw ErrorClass("Constraint index out of range");
					}
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return initDualVector;
}//getInitDualVarUpperBoundsDense


std::vector<SolverOption*>  OSOption::getSolverOptions( std::string solver_name){
	std::vector<SolverOption*> optionsVector;
	if (this->optimization != NULL) {
		if (this->optimization->solverOptions != NULL) {
			int i;
			int num_options;
			num_options = this->getNumberOfSolverOptions();
			for(i = 0; i < num_options; i++){
				if(solver_name == this->optimization->solverOptions->solverOption[ i]->solver){
					optionsVector.push_back( this->optimization->solverOptions->solverOption[ i]);
				}
			}
		}					
	}
	return optionsVector;
}//getSolverOptions


/** ---------------------------------------------------------
 *      set() options
 *  ---------------------------------------------------------
 */

/** 
 *  set() options in the <general> element
 */

bool OSOption::setServiceURI( std::string serviceURI)
{	if (this->general == NULL) 
		this->general = new GeneralOption();
	this->general->serviceURI = serviceURI;
	return true;
}//setServiceURI

bool OSOption::setServiceName( std::string serviceName)
{	if (this->general == NULL) 
		this->general = new GeneralOption();
	this->general->serviceName = serviceName;
	return true;
}//setServiceName

bool OSOption::setInstanceName( std::string instanceName)
{	if (this->general == NULL) 
		this->general = new GeneralOption();
	this->general->instanceName = instanceName;
	return true;
}//setInstanceName

bool OSOption::setInstanceLocation( std::string instanceLocation)
{	if (this->general == NULL) 
		this->general = new GeneralOption();
	if (this->general->instanceLocation == NULL) 
		this->general->instanceLocation = new InstanceLocationOption();
	this->general->instanceLocation->value = instanceLocation;
	return true;
}//setInstanceLocation

bool OSOption::setLocationType( std::string locationType)
{	if (this->general == NULL) 
		this->general = new GeneralOption();
	if (this->general->instanceLocation == NULL) 
		this->general->instanceLocation = new InstanceLocationOption();
	this->general->instanceLocation->locationType = locationType;
	return true;
}//setLocationType

bool OSOption::setJobID( std::string jobID)
{	if (this->general == NULL) 
		this->general = new GeneralOption();
	this->general->jobID = jobID;
	return true;
}//setJobID

bool OSOption::setSolverToInvoke( std::string solverToInvoke)
{	if (this->general == NULL) 
		this->general = new GeneralOption();
	this->general->solverToInvoke = solverToInvoke;
	return true;
}//setSolverToInvoke

bool OSOption::setLicense( std::string license)
{	if (this->general == NULL) 
		this->general = new GeneralOption();
	this->general->license = license;
	return true;
}//setLicense

bool OSOption::setUserName( std::string userName)
{	if (this->general == NULL) 
		this->general = new GeneralOption();
	this->general->userName = userName;
	return true;
}//setUserName

bool OSOption::setPassword( std::string password)
{	if (this->general == NULL) 
		this->general = new GeneralOption();
	this->general->password = password;
	return true;
}//setPassword

bool OSOption::setContact( std::string contact)
{	if (this->general == NULL) 
		this->general = new GeneralOption();
	if (this->general->contact == NULL) 
		this->general->contact = new ContactOption();
	this->general->contact->value = contact;
	return true;
}//setContact

bool OSOption::setTransportType( std::string transportType)
{	if (this->general == NULL) 
		this->general = new GeneralOption();
	if (this->general->contact == NULL) 
		this->general->contact = new ContactOption();
	this->general->contact->transportType = transportType;
	return true;
}//setTransportType

bool OSOption::setNumberOfOtherGeneralOptions(int numberOfObjects)
{	if (this->general == NULL) 
		this->general = new GeneralOption();
	if (this->general->otherOptions == NULL) 
		this->general->otherOptions = new OtherOptions();
	this->general->otherOptions->numberOfOtherOptions = numberOfObjects;
	return true;
}//setNumberOfOtherGeneralOptions

bool OSOption::setOtherGeneralOptions(int numberOfOptions, OtherOption** other)
{	if (this->general == NULL) 
		this->general = new GeneralOption();
	if (this->general->otherOptions == NULL) 
		this->general->otherOptions = new OtherOptions();
	else
		if (numberOfOptions != this->general->otherOptions->numberOfOtherOptions)
			throw ErrorClass("Inconsistent size of <general> <other> element");

	if (this->general->otherOptions->other == NULL) 
	{	this->general->otherOptions->other = new OtherOption*[numberOfOptions];
		for (int i = 0; i < numberOfOptions; i++)
			this->general->otherOptions->other[i] = new OtherOption();
	}

	for (int i = 0; i < numberOfOptions; i++)
		this->general->otherOptions->other[i] = other[i];

	return true;
}//setOtherGeneralOptions

bool OSOption::setAnOtherGeneralOption(OtherOption* optionValue)
{	if (this->general == NULL) 
		this->general = new GeneralOption();
	if (this->general->otherOptions == NULL) 
		this->general->otherOptions = new OtherOptions();

	int nopt;
	if (this->general->otherOptions->other == NULL) 
		nopt = 0;
	else
		nopt = this->general->otherOptions->numberOfOtherOptions;

	OtherOption** temp = new OtherOption*[nopt+1];
	for (int i = 0; i < nopt; i++)
	{	temp[i] = new OtherOption();
		temp[i] = this->general->otherOptions->other[i];
		delete this->general->otherOptions->other[i];
	}
	temp[nopt] = new OtherOption();
	temp[nopt] = optionValue;

	this->general->otherOptions->other = temp;
	this->general->otherOptions->numberOfOtherOptions = ++nopt;

	return true;
}//setAnOtherGeneralOption

/** 
 *  set() options in the <system> element
 */

bool OSOption::setMinDiskSpace(double value)
{	if (this->system == NULL) 
		this->system = new SystemOption();
	if (this->system->minDiskSpace == NULL)
		this->system->minDiskSpace = new MinDiskSpace();
	this->system->minDiskSpace->value = value;
	return true;
}//setMinDiskSpace

bool OSOption::setMinDiskSpaceUnit(std::string unit)
{	if (this->system == NULL) 
		this->system = new SystemOption();
	if (this->system->minDiskSpace == NULL)
		this->system->minDiskSpace = new MinDiskSpace();
	this->system->minDiskSpace->unit = unit;
	return true;
}//setMinDiskSpaceUnit

bool OSOption::setMinMemorySize(double value)
{	if (this->system == NULL) 
		this->system = new SystemOption();
	if (this->system->minMemorySize == NULL)
		this->system->minMemorySize = new MinMemorySize();
	this->system->minMemorySize->value = value;
	return true;
}//setMinMemorySize

bool OSOption::setMinMemoryUnit(std::string unit)
{	if (this->system == NULL) 
		this->system = new SystemOption();
	if (this->system->minMemorySize == NULL)
		this->system->minMemorySize = new MinMemorySize();
	this->system->minMemorySize->unit = unit;
	return true;
}//setMinMemoryUnit

bool OSOption::setMinCPUSpeed(double value)
{	if (this->system == NULL) 
		this->system = new SystemOption();
	if (this->system->minCPUSpeed == NULL)
		this->system->minCPUSpeed = new MinCPUSpeed();
	this->system->minCPUSpeed->value = value;
	return true;
}//setMinCPUSpeed

bool OSOption::setMinCPUSpeedUnit(std::string unit)
{	if (this->system == NULL) 
		this->system = new SystemOption();
	if (this->system->minCPUSpeed == NULL)
		this->system->minCPUSpeed = new MinCPUSpeed();
	this->system->minCPUSpeed->unit = unit;
	return true;
}//setMinCPUSpeedUnit

bool OSOption::setMinCPUNumber(int number)
{	if (this->system == NULL) 
		this->system = new SystemOption();
	this->system->minCPUNumber = number;
	return true;
}//setMinCPUNumber

bool OSOption::setNumberOfOtherSystemOptions(int numberOfObjects)
{	if (this->system == NULL) 
		this->system = new SystemOption();
	if (this->system->otherOptions == NULL) 
		this->system->otherOptions = new OtherOptions();
	this->system->otherOptions->numberOfOtherOptions = numberOfObjects;
	return true;
}//setNumberOfOtherSystemOptions

bool OSOption::setOtherSystemOptions(int numberOfOptions, OtherOption** other)
{	if (this->system == NULL) 
		this->system = new SystemOption();
	if (this->system->otherOptions == NULL) 
		this->system->otherOptions = new OtherOptions();
//	if (this->system->otherOptions->other == NULL) 
//		this->system->otherOptions->other = new OtherOption[numberOfOptions];
//needs more work
	return true;
}//setOtherSystemOptions

bool OSOption::setAnOtherSystemOption(OtherOption* optionValue)
{	if (this->system == NULL) 
		this->system = new SystemOption();
	if (this->system->otherOptions == NULL) 
		this->system->otherOptions = new OtherOptions();
//	if (this->system->otherOptions->other == NULL) 
//		this->system->otherOptions->other = new OtherOption[numberOfOptions];
//needs more work
	return true;
}//setAnOtherSystemOption

/** 
 *  set() options in the <service> element
 */

bool OSOption::setServiceType( std::string serviceType)
{	if (this->service == NULL) 
		this->service = new ServiceOption();
	this->service->type = serviceType;
	return true;
}//setServiceType

bool OSOption::setNumberOfOtherServiceOptions(int numberOfObjects)
{	if (this->service == NULL) 
		this->service = new ServiceOption();
	if (this->service->otherOptions == NULL) 
		this->service->otherOptions = new OtherOptions();
	this->service->otherOptions->numberOfOtherOptions = numberOfObjects;
	return true;
}//setNumberOfOtherServiceOptions

bool OSOption::setOtherServiceOptions(int numberOfOptions, OtherOption** other)
{	if (this->service == NULL) 
		this->service = new ServiceOption();
	if (this->service->otherOptions == NULL) 
		this->service->otherOptions = new OtherOptions();
//	if (this->service->otherOptions->other == NULL) 
//		this->service->otherOptions->other = new OtherOption[numberOfOptions];
//needs more work
	return true;
}//setOtherServiceOptions

bool OSOption::setAnOtherServiceOption(OtherOption* optionValue)
{	if (this->service == NULL) 
		this->service = new ServiceOption();
	if (this->service->otherOptions == NULL) 
		this->service->otherOptions = new OtherOptions();
//	if (this->service->otherOptions->other == NULL) 
//		this->service->otherOptions->other = new OtherOption[numberOfOptions];
//needs more work
	return true;
}//setAnOtherServiceOption

/** 
 *  set() options in the <job> element
 */

bool OSOption::setMaxTime(double value)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->maxTime == NULL)
		this->job->maxTime = new MaxTime();
	this->job->maxTime->value = value;
	return true;
}//setMaxTime

bool OSOption::setMaxTimeUnit(std::string unit)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->maxTime == NULL)
		this->job->maxTime = new MaxTime();
	this->job->maxTime->unit = unit;
	return true;
}//setMaxTimeUnit

bool OSOption::setScheduledStartTime(std::string time)
{	if (this->job == NULL) 
		this->job = new JobOption();
	this->job->scheduledStartTime = time;
	return true;
}//setScheduledStartTime


bool OSOption::setOptionStr(std::string optionName, std::string optionValue)
{	if (optionName == "serviceURI") 
		return this->setServiceURI(optionValue);

	if (optionName == "serviceName") 
		return this->setServiceName(optionValue);

	if (optionName == "instanceName") 
		return this->setInstanceName(optionValue);

	if (optionName == "instanceLocation") 
		return this->setInstanceLocation(optionValue);

	if (optionName == "locationType") 
		return this->setLocationType(optionValue);

	if (optionName == "jobID") 
		return this->setJobID(optionValue);

	if (optionName == "solverName") 
		return this->setSolverToInvoke(optionValue);

	if (optionName == "solverToInvoke") 
		return this->setSolverToInvoke(optionValue);

	if (optionName == "license") 
		return this->setLicense(optionValue);

	if (optionName == "userName") 
		return this->setUserName(optionValue);

	if (optionName == "password") 
		return this->setPassword(optionValue);

	if (optionName == "contact") 
		return this->setContact(optionValue);

	if (optionName == "transportType") 
		return this->setTransportType(optionValue);

	if (optionName == "minDiskSpaceUnit") 
		return this->setMinDiskSpaceUnit(optionValue);

	if (optionName == "minMemoryUnit") 
		return this->setMinMemoryUnit(optionValue);

	if (optionName == "minCPUSpeedUnit") 
		return this->setMinCPUSpeedUnit(optionValue);

	if (optionName == "serviceType") 
		return this->setServiceType(optionValue);

	if (optionName == "maxTimeUnit") 
		return this->setMaxTimeUnit(optionValue);

	if (optionName == "scheduledStartTime") 
		return this->setScheduledStartTime(optionValue);

	return false;
}//setOptionStr



bool OSOption::setOptionDbl(std::string optionName, double value)
{	if (optionName == "minDiskSpace") 
		return this->setMinDiskSpace(value);

	if (optionName == "minMemory") 
		return this->setMinMemorySize(value);

	if (optionName == "minCPUSpeed") 
		return this->setMinCPUSpeed(value);

	if (optionName == "maxTime") 
		return this->setMaxTime(value);

	return false;
}//setOptionDbl



bool OSOption::setNumberOfOtherJobOptions(int numberOfObjects)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->otherOptions == NULL) 
		this->job->otherOptions = new OtherOptions();
	this->job->otherOptions->numberOfOtherOptions = numberOfObjects;
	return true;
}//setNumberOfOtherJobOptions

bool OSOption::setNumberOfJobDependencies(int numberOfObjects)
{	if (this->job != NULL) 
		this->job = new JobOption();
	if (this->job->dependencies == NULL) 
		this->job->dependencies = new JobDependencies();
	this->job->dependencies->numberOfJobIDs = numberOfObjects;
	return true;
}//setNumberOfJobDependencies

bool OSOption::setJobDependencies(int numberOfDependencies, std::string* jobDependencies)
{	cout << "Inside setJobDependencies" << endl;
	if (this->job == NULL) 
	{	cout << "JobOption needs to be allocated" << endl;
		this->job = new JobOption();
		cout << "JobOption allocated" << endl; }
	cout << "JobOption exists" << endl;
	if (this->job->dependencies == NULL) 
		this->job->dependencies = new JobDependencies();
	else
		if (this->job->dependencies->numberOfJobIDs != numberOfDependencies)
			throw ErrorClass("Inconsistent size of <job> <dependencies> element");
	cout << "JobDependencies exists" << endl;
	if (this->job->dependencies->jobID == NULL)
		this->job->dependencies->jobID = new std::string[numberOfDependencies];
	cout << "jobID exists" << endl;
	for (int i = 0; i < numberOfDependencies; i++)
		this->job->dependencies->jobID[i] = jobDependencies[i];
	this->job->dependencies->numberOfJobIDs = numberOfDependencies;
    cout << "jobID has been set" << endl;
	return true;
}//setJobDependencies

bool OSOption::setAnotherJobDependency(std::string jobID)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->dependencies == NULL) 
		this->job->dependencies = new JobDependencies();

	int nopt;
	if (this->job->dependencies->jobID == NULL) 
		nopt = 0;
	else
		nopt = this->job->dependencies->numberOfJobIDs;

	std::string* temp = new std::string[nopt+1];
	for (int i = 0; i < nopt; i++)
		temp[i] = this->job->dependencies->jobID[i];
	
	temp[nopt] = jobID;
	this->job->dependencies->jobID = temp;
	this->job->dependencies->numberOfJobIDs = ++nopt;

	return true;
}//setAnotherJobDependency


bool OSOption::setNumberOfRequiredDirectories(int numberOfObjects)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->requiredDirectories == NULL) 
		this->job->requiredDirectories = new DirectoriesAndFiles();
	this->job->requiredDirectories->numberOfPaths = numberOfObjects;
	return true;
}//setNumberOfRequiredDirectories

bool OSOption::setNumberOfRequiredFiles(int numberOfObjects)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->requiredFiles == NULL) 
		this->job->requiredFiles = new DirectoriesAndFiles();
	this->job->requiredFiles->numberOfPaths = numberOfObjects;
	return true;
}//setNumberOfRequiredFiles

bool OSOption::setNumberOfDirectoriesToMake(int numberOfObjects)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->directoriesToMake == NULL) 
		this->job->directoriesToMake = new DirectoriesAndFiles();
	this->job->directoriesToMake->numberOfPaths = numberOfObjects;
	return true;
}//setNumberOfDirectoriesToMake

bool OSOption::setNumberOfFilesToCreate(int numberOfObjects)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->filesToCreate == NULL) 
		this->job->filesToCreate = new DirectoriesAndFiles();
	this->job->filesToCreate->numberOfPaths = numberOfObjects;
	return true;
}//setNumberOfFilesToCreate

bool OSOption::setNumberOfInputDirectoriesToMove(int numberOfObjects)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->inputDirectoriesToMove == NULL) 
		this->job->inputDirectoriesToMove = new PathPairs();
	this->job->inputDirectoriesToMove->numberOfPathPairs = numberOfObjects;
	return true;
}//setNumberOfInputDirectoriesToMove

bool OSOption::setNumberOfInputFilesToMove(int numberOfObjects)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->inputFilesToMove == NULL) 
		this->job->inputFilesToMove = new PathPairs();
	this->job->inputFilesToMove->numberOfPathPairs = numberOfObjects;
	return true;
}//setNumberOfInputFilesToMove

bool OSOption::setNumberOfOutputFilesToMove(int numberOfObjects)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->outputFilesToMove == NULL) 
		this->job->outputFilesToMove = new PathPairs();
	this->job->outputFilesToMove->numberOfPathPairs = numberOfObjects;
	return true;
}//setNumberOfOutputFilesToMove

bool OSOption::setNumberOfOutputDirectoriesToMove(int numberOfObjects)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->outputDirectoriesToMove == NULL) 
		this->job->outputDirectoriesToMove = new PathPairs();
	this->job->outputDirectoriesToMove->numberOfPathPairs = numberOfObjects;
	return true;
}//setNumberOfOutputDirectoriesToMove

bool OSOption::setNumberOfFilesToDelete(int numberOfObjects)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->filesToDelete == NULL) 
		this->job->filesToDelete = new DirectoriesAndFiles();
	this->job->filesToDelete->numberOfPaths = numberOfObjects;
	return true;
}//setNumberOfFilesToDelete

bool OSOption::setNumberOfDirectoriesToDelete(int numberOfObjects)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->directoriesToDelete == NULL) 
		this->job->directoriesToDelete = new DirectoriesAndFiles();
	this->job->directoriesToDelete->numberOfPaths = numberOfObjects;
	return true;
}//setNumberOfDirectoriesToDelete

bool OSOption::setNumberOfProcessesToKill(int numberOfObjects)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->processesToKill == NULL) 
		this->job->processesToKill = new Processes();
	this->job->processesToKill->numberOfProcesses = numberOfObjects;
	return true;
}//setNumberOfProcessesToKill

//================got to here



bool OSOption::setNumberOfVariables(int numberOfObjects)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	this->optimization->numberOfVariables = numberOfObjects;
	return true;
}//setNumberOfVariables

bool OSOption::setNumberOfObjectives(int numberOfObjects)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	this->optimization->numberOfObjectives = numberOfObjects;
	return true;
}//setNumberOfObjectives

bool OSOption::setNumberOfConstraints(int numberOfObjects)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	this->optimization->numberOfConstraints = numberOfObjects;
	return true;
}//setNumberOfConstraints


bool OSOption::setNumberOfInitVarValues(int numberOfObjects)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL) 
		this->optimization->variables = new VariableOption();
	if (this->optimization->variables->initialVariableValues == NULL) 
		this->optimization->variables->initialVariableValues = new InitVariableValues();
	this->optimization->variables->initialVariableValues->numberOfVar = numberOfObjects;
	return true;
}//setNumberOfInitVarValues

bool OSOption::setNumberOfInitVarValuesString(int numberOfObjects)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL) 
		this->optimization->variables = new VariableOption();
	if (this->optimization->variables->initialVariableValuesString == NULL) 
		this->optimization->variables->initialVariableValuesString = new InitVariableValuesString();
	this->optimization->variables->initialVariableValuesString->numberOfVar = numberOfObjects;
	return true;
}//setNumberOfInitVarValuesString

bool OSOption::setNumberOfInitialBasisVariables(int numberOfObjects)
{	if (this->optimization == NULL)
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL) 
		this->optimization->variables = new VariableOption();
	if (this->optimization->variables->initialBasisStatus == NULL) 
		this->optimization->variables->initialBasisStatus = new InitialBasisStatus();
	this->optimization->variables->initialBasisStatus ->numberOfVar = numberOfObjects;
	return true;
}//setNumberOfInitialBasisVariables


bool OSOption::setNumberOfOtherVariableOptions(int numberOfObjects)
{	if (this->optimization == NULL)
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL)
		this->optimization->variables = new VariableOption();
	this->optimization->variables->numberOfOtherVariableOptions = numberOfObjects;
	return true;
}//setNumberOfOtherVariableOptions

bool OSOption::setNumberOfInitObjValues(int numberOfObjects)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->objectives == NULL) 
		this->optimization->objectives = new ObjectiveOption();
	if (this->optimization->objectives->initialObjectiveValues == NULL) 
		this->optimization->objectives->initialObjectiveValues = new InitObjectiveValues();
	this->optimization->objectives->initialObjectiveValues->numberOfObj = numberOfObjects;
	return true;
}//setNumberOfInitObjValues

bool OSOption::setNumberOfInitObjBounds(int numberOfObjects)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->objectives == NULL) 
		this->optimization->objectives = new ObjectiveOption();
	if (this->optimization->objectives->initialObjectiveBounds == NULL) 
		this->optimization->objectives->initialObjectiveBounds = new InitObjectiveBounds();
	this->optimization->objectives->initialObjectiveBounds->numberOfObj = numberOfObjects;
	return true;
}//setNumberOfInitObjBounds

bool OSOption::setNumberOfOtherObjectiveOptions(int numberOfObjects)
{	if (this->optimization == NULL)
		this->optimization = new OptimizationOption();
	if (this->optimization->objectives == NULL) 
		this->optimization->objectives = new ObjectiveOption();
	this->optimization->objectives->numberOfOtherObjectiveOptions = numberOfObjects;
	return true;
}//setNumberOfOtherObjectiveOptions

bool OSOption::setNumberOfInitConValues(int numberOfObjects)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->constraints == NULL) 
		this->optimization->constraints = new ConstraintOption();
	if (this->optimization->constraints->initialConstraintValues == NULL) 
		this->optimization->constraints->initialConstraintValues = new InitConstraintValues();
	this->optimization->constraints->initialConstraintValues->numberOfCon = numberOfObjects;
	return true;
}//setNumberOfInitConValues

bool OSOption::setNumberOfInitDualVarValues(int numberOfObjects)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->constraints == NULL) 
		this->optimization->constraints = new ConstraintOption();
	if (this->optimization->constraints->initialDualValues == NULL) 
		this->optimization->constraints->initialDualValues = new InitDualVariableValues();
	this->optimization->constraints->initialDualValues->numberOfCon = numberOfObjects;
	return true;
}//setNumberOfInitDualVarValues

bool OSOption::setNumberOfOtherConstraintOptions(int numberOfObjects)
{	if (this->optimization == NULL)
		this->optimization = new OptimizationOption();
	if (this->optimization->constraints == NULL) 
		this->optimization->constraints = new ConstraintOption();
	this->optimization->constraints->numberOfOtherConstraintOptions = numberOfObjects;
	return true;
}//setNumberOfOtherConstraintOptions

bool OSOption::setNumberOfSolverOptions(int numberOfObjects)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->solverOptions == NULL) 
		this->optimization->solverOptions = new SolverOptions();
	this->optimization->solverOptions->numberOfSolverOptions = numberOfObjects;
	return true;
}//setNumberOfSolverOptions



bool OSOption::setOptionInt(std::string optionName, int optionValue)
{	if(optionName == "minCPUNumber")
		return this->setMinCPUNumber(optionValue);

	if(optionName == "numberOfOtherGeneralOptions")
		return this->setNumberOfOtherGeneralOptions(optionValue);

	if(optionName == "numberOfOtherSystemOptions")
		return this->setNumberOfOtherSystemOptions(optionValue);

	if(optionName == "numberOfOtherServiceOptions")
		return this->setNumberOfOtherServiceOptions(optionValue);

	if(optionName == "numberOfOtherJobOptions")
		return this->setNumberOfOtherJobOptions(optionValue);

	if(optionName == "numberOfJobDependencies")
		return this->setNumberOfJobDependencies(optionValue);

	if(optionName == "numberOfRequiredDirectories")
		return this->setNumberOfRequiredDirectories(optionValue);

	if(optionName == "numberOfRequiredFiles")
		return this->setNumberOfRequiredFiles(optionValue);

	if(optionName == "numberOfDirectoriesToMake")
		return this->setNumberOfDirectoriesToMake(optionValue);

	if(optionName == "numberOfFilesToCreate")
		return this->setNumberOfFilesToCreate(optionValue);

	if(optionName == "numberOfInputDirectoriesToMove")
		return this->setNumberOfInputDirectoriesToMove(optionValue);

	if(optionName == "numberOfInputFilesToMove")
		return this->setNumberOfInputFilesToMove(optionValue);

	if(optionName == "numberOfOutputDirectoriesToMove")
		return this->setNumberOfOutputDirectoriesToMove(optionValue);

	if(optionName == "numberOfOutputFilesToMove")
		return this->setNumberOfOutputFilesToMove(optionValue);

	if(optionName == "numberOfFilesToDelete")
		return this->setNumberOfFilesToDelete(optionValue);

	if(optionName == "numberOfDirectoriesToDelete")
		return this->setNumberOfDirectoriesToDelete(optionValue);

	if(optionName == "numberOfProcessesToKill")
		return this->setNumberOfProcessesToKill(optionValue);

	if(optionName == "numberOfVariables")
		return this->setNumberOfVariables(optionValue);

	if(optionName == "numberOfObjectives")
		return this->setNumberOfObjectives(optionValue);

	if(optionName == "numberOfConstraints")
		return this->setNumberOfConstraints(optionValue);

	if(optionName == "numberOfInitVarValues")
		return this->setNumberOfInitVarValues(optionValue);

	if(optionName == "numberOfInitVarValuesString")
		return this->setNumberOfInitVarValuesString(optionValue);

	if(optionName == "numberOfInitialBasisVariables")
		return this->setNumberOfInitialBasisVariables(optionValue);

	if(optionName == "numberOfOtherVariableOptions")
		return this->setNumberOfOtherVariableOptions(optionValue);

	if(optionName == "numberOfInitObjValues")
		return this->setNumberOfInitObjValues(optionValue);

	if(optionName == "numberOfInitObjBounds")
		return this->setNumberOfInitObjBounds(optionValue);

	if(optionName == "numberOfOtherObjectiveOptions")
		return this->setNumberOfOtherObjectiveOptions(optionValue);

	if(optionName == "numberOfInitConValues")
		return this->setNumberOfInitConValues(optionValue);

	if(optionName == "numberOfInitDualVarValues")
		return this->setNumberOfInitDualVarValues(optionValue);

	if(optionName == "numberOfOtherConstraintOptions")
		return this->setNumberOfOtherConstraintOptions(optionValue);

	if(optionName == "numberOfSolverOptions")
		return this->setNumberOfSolverOptions(optionValue);

	return false;
}//setOptionInt





/** 
 * set() methods that populate arrays of various kinds
 */


bool OSOption::setOtherOptions(std::string optionName)
/*{	OtherOption** optionVector = NULL;
	if (optionName == "general")
		return this->setOtherGeneralOptions();

	if (optionName == "system")
		return this->setOtherSystemOptions();

	if (optionName == "service")
		return this->setOtherServiceOptions();

	if (optionName == "job")
		return this->setOtherJobOptions();

}*/
//setOtherOptions
{return false;}

bool OSOption::setAllOtherOptions()
/*{	OtherOption** optionVector = NULL;
	int prev_options[4];
	int num_options[4];
	int num_opt;
	for (int i = 0; i < 4; i++)
	{	prev_options[i] = 0;
		num_options[i] = 0;
	}
	if (this->general != NULL) 
	{	if (this->general->otherOptions != NULL)
		{	num_opt = this->setNumberOfOtherGeneralOptions();
			num_options[0] = num_opt;
		}
	}

	if (this->system != NULL) 
	{	if (this->system->otherOptions != NULL)
		{	num_opt = this->setNumberOfOtherSystemOptions();
			num_options[1] = num_opt;
		}
	}
	prev_options[1] = prev_options[0] + num_options[0];

	if (this->service != NULL) 
	{	if (this->service->otherOptions != NULL)
		{	num_opt = this->setNumberOfOtherServiceOptions();
			num_options[2] = num_opt;
		}
	}
	prev_options[2] = prev_options[1] + num_options[1];

	if (this->job != NULL) 
	{	if (this->job->otherOptions != NULL)
		{	num_opt = this->setNumberOfOtherJobOptions();
			num_options[3] = num_opt;
		}
	}
	prev_options[3] = prev_options[2] + num_options[2];

	num_opt = num_options[0] + num_options[1] + num_options[2] + num_options[3];
	optionVector = new OtherOption*[num_opt];

	int j;
	if (num_options[0] > 0)
	{	for(int i = 0; i < num_options[0]; i++)
		{	optionVector[prev_options[0] + i] = this->general->otherOptions->other[i];
		}
	}

	if (num_options[1] > 0)
	{	for(int i = 0; i < num_options[1]; i++)
		{	optionVector[prev_options[1] + i] = this->system->otherOptions->other[i];
		}
	}

	if (num_options[2] > 0)
	{	for(int i = 0; i < num_options[2]; i++)
		{	optionVector[prev_options[2] + i] = this->service->otherOptions->other[i];
		}
	}

	if (num_options[3] > 0)
	{	for(int i = 0; i < num_options[3]; i++)
		{	optionVector[prev_options[3] + i] = this->job->otherOptions->other[i];
		}
	}

	return optionVector;
}*/
//setOtherJobOptions
{return false;}

/*
std::string*  OSOption::setJobDependencies(){
	std::string* dependenciesVector;
	if (this->job != NULL) 
	{	if (this->job->dependencies != NULL) 
		{	int i;
			int num_ID;
			num_ID = this->setNumberOfJobDependencies();
			dependenciesVector = new string[num_ID];
			for(i = 0; i < num_ID; i++)
				dependenciesVector[i] = this->job->dependencies->jobID[ i];
		}					
	}
	return dependenciesVector;
}//setJobDependencies

std::string*  OSOption::setRequiredDirectories(){
	std::string* pathVector;
	if (this->job != NULL) 
	{	if (this->job->requiredDirectories != NULL) 
		{	int i;
			int num_paths;
			num_paths = this->setNumberOfRequiredDirectories();
			pathVector = new string[num_paths];
			for(i = 0; i < num_paths; i++)
				pathVector[i] = this->job->requiredDirectories->path[i];
		}					
	}
	return pathVector;
}//setRequiredDirectories

std::string*  OSOption::setDirectoriesToMake(){
	std::string* pathVector;
	if (this->job != NULL) 
	{	if (this->job->directoriesToMake != NULL) 
		{	int i;
			int num_paths;
			num_paths = this->setNumberOfDirectoriesToMake();
			pathVector = new string[num_paths];
			for(i = 0; i < num_paths; i++)
				pathVector[i] = this->job->directoriesToMake->path[i];
		}					
	}
	return pathVector;
}//setDirectoriesToMake

std::string*  OSOption::setFilesToCreate(){
	std::string* pathVector;
	if (this->job != NULL) 
	{	if (this->job->filesToCreate != NULL) 
		{	int i;
			int num_paths;
			num_paths = this->setNumberOfFilesToCreate();
			pathVector = new string[num_paths];
			for(i = 0; i < num_paths; i++)
				pathVector[i] = this->job->filesToCreate->path[i];
		}					
	}
	return pathVector;
}//setFilesToCreate

PathPair** OSOption::setInputDirectoriesToMove()
{	PathPair** pathPairVector = NULL;
	if (this->job != NULL) 
	{	if(this->job->inputDirectoriesToMove != NULL) 
		{	int num_pp;
			num_pp = this->setNumberOfInputDirectoriesToMove();
			pathPairVector = new PathPair*[num_pp];
			for(int i = 0; i < num_pp; i++)
				pathPairVector[i] = this->job->inputDirectoriesToMove->pathPair[ i];
		}					
	}
	return pathPairVector;
}//setInputDirectoriesToMove

PathPair** OSOption::setInputFilesToMove()
{	PathPair** pathPairVector = NULL;
	if (this->job != NULL) 
	{	if(this->job->inputFilesToMove != NULL) 
		{	int num_pp;
			num_pp = this->setNumberOfInputFilesToMove();
			pathPairVector = new PathPair*[num_pp];
			for(int i = 0; i < num_pp; i++)
				pathPairVector[i] = this->job->inputFilesToMove->pathPair[ i];
		}					
	}
	return pathPairVector;
}//setInputFilesToMove

PathPair** OSOption::setOutputFilesToMove()
{	PathPair** pathPairVector = NULL;
	if (this->job != NULL) 
	{	if(this->job->outputFilesToMove != NULL) 
		{	int num_pp;
			num_pp = this->setNumberOfOutputFilesToMove();
			pathPairVector = new PathPair*[num_pp];
			for(int i = 0; i < num_pp; i++)
				pathPairVector[i] = this->job->outputFilesToMove->pathPair[ i];
		}					
	}
	return pathPairVector;
}//setOutputFilesToMove

PathPair** OSOption::setOutputDirectoriesToMove()
{	PathPair** pathPairVector = NULL;
	if (this->job != NULL) 
	{	if(this->job->outputDirectoriesToMove != NULL) 
		{	int num_pp;
			num_pp = this->setNumberOfOutputDirectoriesToMove();
			pathPairVector = new PathPair*[num_pp];
			for(int i = 0; i < num_pp; i++)
				pathPairVector[i] = this->job->outputDirectoriesToMove->pathPair[ i];
		}					
	}
	return pathPairVector;
}//setOutputDirectoriesToMove

std::string*  OSOption::setFilesToDelete(){
	std::string* pathVector;
	if (this->job != NULL) 
	{	if (this->job->filesToDelete != NULL) 
		{	int num_paths;
			num_paths = this->setNumberOfFilesToDelete();
			pathVector = new string[num_paths];
			for(int i = 0; i < num_paths; i++)
				pathVector[i] = this->job->filesToDelete->path[i];
		}					
	}
	return pathVector;
}//setFilesToDelete

std::string*  OSOption::setDirectoriesToDelete(){
	std::string* pathVector;
	if (this->job != NULL) 
	{	if (this->job->directoriesToDelete != NULL) 
		{	int i;
			int num_paths;
			num_paths = this->setNumberOfDirectoriesToDelete();
			pathVector = new string[num_paths];
			for(i = 0; i < num_paths; i++)
				pathVector[i] = this->job->directoriesToDelete->path[i];
		}					
	}
	return pathVector;
}//setDirectoriesToDelete

std::string*  OSOption::setProcessesToKill(){
	std::string* pathVector;
	if (this->job != NULL) 
	{	if (this->job->processesToKill != NULL) 
		{	int i;
			int num_paths;
			num_paths = this->setNumberOfProcessesToKill();
			pathVector = new string[num_paths];
			for(i = 0; i < num_paths; i++)
				pathVector[i] = this->job->processesToKill->process[i];
		}					
	}
	return pathVector;
}//setProcessesToKill



std::vector<InitVarValue*>  OSOption::setInitVarValuesSparse(){
	std::vector<InitVarValue*> initVarVector;
	if (this->optimization != NULL) {
		if(this->optimization->variables != NULL) {
			if(this->optimization->variables->initialVariableValues != NULL) {
			int i;
			int num_var;
			num_var = this->setNumberOfInitVarValues();
			for(i = 0; i < num_var; i++){
				printf("\n%d\n",this->optimization->variables->initialVariableValues->var[ i]->idx);
				printf("\n%d\n",this->optimization->variables->initialVariableValues->var[ i]->value);
				initVarVector.push_back( this->optimization->variables->initialVariableValues->var[ i]);
				}
			}
		}					
	}
	return initVarVector;
}//setInitVarValuesSparse

double* OSOption::setInitVarValuesDense(int numberOfVariables){
	double *initVarVector;
	initVarVector = new double[numberOfVariables];
	for (int k = 0; k < numberOfVariables; k++) initVarVector[k] = OSNAN;
	try
	{	if (this->optimization != NULL) 
		{	if(this->optimization->variables != NULL) 
			{	if(this->optimization->variables->initialVariableValues != NULL) 
				{	int i,j;
					int num_var;
					num_var = this->setNumberOfInitVarValues();
					for(i = 0; i < num_var; i++)
					{	j = this->optimization->variables->initialVariableValues->var[i]->idx;
						if (j >= 0 && j < numberOfVariables)						
							initVarVector[j] 
							  = this->optimization->variables->initialVariableValues->var[i]->value;						
						else
							throw ErrorClass("Variable index out of range");
					}
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return initVarVector;
}//setInitVarValuesDense


std::vector<InitVarValueString*>  OSOption::getInitVarStringsSparse(){
	std::vector<InitVarValueString*> initVarVector;
	if (this->optimization != NULL) {
		if(this->optimization->variables != NULL) {
			if(this->optimization->variables->initialVariableValuesString != NULL) {
			int i;
			int num_var;
			num_var = this->getNumberOfInitVarValuesString();
			for(i = 0; i < num_var; i++){
				initVarVector.push_back( this->optimization->variables->initialVariableValuesString->var[ i]);
				}
			}
		}					
	}
	return initVarVector;
}//getInitVarStringsSparse

std::string *OSOption::getInitVarStringsDense(int numberOfVariables){
	std::string *initVarVector;
	initVarVector = new std::string[numberOfVariables];
	for (int k = 0; k < numberOfVariables; k++) initVarVector[k] = "";
	try
	{
		if (this->optimization != NULL) 
		{	if(this->optimization->variables != NULL) 
			{	if(this->optimization->variables->initialVariableValuesString != NULL) 
				{	int i,j;
					int num_var;
					num_var = this->getNumberOfInitVarValuesString();
					for(i = 0; i < num_var; i++)
					{	j = this->optimization->variables->initialVariableValuesString->var[i]->idx;
						if (j >= 0 && j < numberOfVariables)
							initVarVector[j] 
							  = this->optimization->variables->initialVariableValuesString->var[i]->value;
						else
							throw ErrorClass("Variable index out of range");
					}
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return initVarVector;
}//getInitVarStringsDense


std::vector<InitObjValue*>  OSOption::getInitObjValuesSparse(){
	std::vector<InitObjValue*> initObjVector;
	if (this->optimization != NULL) {
		if(this->optimization->objectives != NULL) {
			if(this->optimization->objectives->initialObjectiveValues != NULL) {
			int i;
			int num_obj;
			num_obj = this->getNumberOfInitObjValues();
			for(i = 0; i < num_obj; i++){
				printf("\n%d\n",this->optimization->objectives->initialObjectiveValues->obj[ i]->idx);
				printf("\n%d\n",this->optimization->objectives->initialObjectiveValues->obj[ i]->value);
				initObjVector.push_back( this->optimization->objectives->initialObjectiveValues->obj[ i]);
				}
			}
		}					
	}
	return initObjVector;
}//getInitObjValuesSparse

double* OSOption::getInitObjValuesDense(int numberOfObjectives){
	double *initObjVector;
	initObjVector = new double[numberOfObjectives];
	for (int k = 0; k < numberOfObjectives; k++) initObjVector[k] = OSNAN;
	try
	{	if (this->optimization != NULL) 
		{	if(this->optimization->objectives != NULL) 
			{	if(this->optimization->objectives->initialObjectiveValues != NULL) 
				{	int i,j;
					int num_obj;
					num_obj = this->getNumberOfInitObjValues();
					for(i = 0; i < num_obj; i++)
					{	j = this->optimization->objectives->initialObjectiveValues->obj[i]->idx;
						if (j < 0 && -j <= numberOfObjectives)						
							initObjVector[j] 
							  = this->optimization->objectives->initialObjectiveValues->obj[i]->value;						
						else
							throw ErrorClass("Objective index out of range");
					}
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return initObjVector;
}//getInitObjValuesDense


std::vector<InitObjBound*>  OSOption::getInitObjBoundsSparse()
{	std::vector<InitObjBound*> initObjBounds;
	if (this->optimization != NULL) 
	{	if(this->optimization->objectives != NULL) 
		{	if(this->optimization->objectives->initialObjectiveBounds != NULL) 
			{	int i;
				int num_obj;
				num_obj = this->getNumberOfInitObjBounds();
				for(i = 0; i < num_obj; i++)
				{	printf("\n%d\n",this->optimization->objectives->initialObjectiveBounds->obj[ i]->idx);
					printf("\n%d\n",this->optimization->objectives->initialObjectiveBounds->obj[ i]->lbValue);
					printf("\n%d\n",this->optimization->objectives->initialObjectiveBounds->obj[ i]->ubValue);
					initObjBounds.push_back( this->optimization->objectives->initialObjectiveBounds->obj[ i]);
				}
			}
		}					
	}
	return initObjBounds;
}//getInitObjBoundsSparse

double* OSOption::getInitObjLowerBoundsDense(int numberOfObjectives){
	double *initObjBound;
	initObjBound = new double[numberOfObjectives];
	for (int k = 0; k < numberOfObjectives; k++) initObjBound[k] = OSNAN;
	try
	{	if (this->optimization != NULL) 
		{	if(this->optimization->objectives != NULL) 
			{	if(this->optimization->objectives->initialObjectiveBounds != NULL) 
				{	int i,j;
					int num_obj;
					num_obj = this->getNumberOfInitObjBounds();
					for(i = 0; i < num_obj; i++)
					{	j = this->optimization->objectives->initialObjectiveBounds->obj[i]->idx;
						if (j < 0 && -j <= numberOfObjectives)						
							initObjBound[j] 
							  = this->optimization->objectives->initialObjectiveBounds->obj[i]->lbValue;
						else
							throw ErrorClass("Objective index out of range");
					}
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return initObjBound;
}//getInitObjLowerBoundsDense

double* OSOption::getInitObjUpperBoundsDense(int numberOfObjectives){
	double *initObjBound;
	initObjBound = new double[numberOfObjectives];
	for (int k = 0; k < numberOfObjectives; k++) initObjBound[k] = OSNAN;
	try
	{	if (this->optimization != NULL) 
		{	if(this->optimization->objectives != NULL) 
			{	if(this->optimization->objectives->initialObjectiveBounds != NULL) 
				{	int i,j;
					int num_obj;
					num_obj = this->getNumberOfInitObjBounds();
					for(i = 0; i < num_obj; i++)
					{	j = this->optimization->objectives->initialObjectiveBounds->obj[i]->idx;
						if (j < 0 && -j <= numberOfObjectives)						
							initObjBound[j] 
							  = this->optimization->objectives->initialObjectiveBounds->obj[i]->ubValue;
						else
							throw ErrorClass("Objective index out of range");
					}
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return initObjBound;
}//getInitObjUpperBoundsDense


std::vector<InitConValue*>  OSOption::getInitConValuesSparse(){
	std::vector<InitConValue*> initConVector;
	if (this->optimization != NULL) {
		if(this->optimization->constraints != NULL) {
			if(this->optimization->constraints->initialConstraintValues != NULL) {
			int i;
			int num_con;
			num_con = this->getNumberOfInitConValues();
			for(i = 0; i < num_con; i++){
				printf("\n%d\n",this->optimization->constraints->initialConstraintValues->con[ i]->idx);
				printf("\n%d\n",this->optimization->constraints->initialConstraintValues->con[ i]->value);
				initConVector.push_back( this->optimization->constraints->initialConstraintValues->con[ i]);
				}
			}
		}					
	}
	return initConVector;
}//getInitConValuesSparse

double* OSOption::getInitConValuesDense(int numberOfConstraints){
	double *initConVector;
	initConVector = new double[numberOfConstraints];
	for (int k = 0; k < numberOfConstraints; k++) initConVector[k] = OSNAN;
	try
	{	if (this->optimization != NULL) 
		{	if(this->optimization->constraints != NULL) 
			{	if(this->optimization->constraints->initialConstraintValues != NULL) 
				{	int i,j;
					int num_con;
					num_con = this->getNumberOfInitConValues();
					for(i = 0; i < num_con; i++)
					{	j = this->optimization->constraints->initialConstraintValues->con[i]->idx;
						if (j >= 0 && j < numberOfConstraints)						
							initConVector[j] 
							  = this->optimization->constraints->initialConstraintValues->con[i]->value;						
						else
							throw ErrorClass("Constraint index out of range");
					}
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return initConVector;
}//getInitConValuesDense


std::vector<InitDualVarValue*>  OSOption::getInitDualVarValuesSparse(){
	std::vector<InitDualVarValue*> initDualVector;
	if (this->optimization != NULL) {
		if(this->optimization->constraints != NULL) {
			if(this->optimization->constraints->initialDualValues != NULL) {
			int i;
			int num_con;
			num_con = this->getNumberOfInitDualVarValues();
			for(i = 0; i < num_con; i++){
				printf("\n%d\n",this->optimization->constraints->initialDualValues->con[ i]->idx);
				printf("\n%d\n",this->optimization->constraints->initialDualValues->con[ i]->lbValue);
				printf("\n%d\n",this->optimization->constraints->initialDualValues->con[ i]->ubValue);
				initDualVector.push_back( this->optimization->constraints->initialDualValues->con[ i]);
				}
			}
		}					
	}
	return initDualVector;
}//getInitDualVarValuesSparse

double* OSOption::getInitDualVarLowerBoundsDense(int numberOfConstraints){
	double *initDualVector;
	initDualVector = new double[numberOfConstraints];
	for (int k = 0; k < numberOfConstraints; k++) initDualVector[k] = OSNAN;
	try
	{	if (this->optimization != NULL) 
		{	if(this->optimization->constraints != NULL) 
			{	if(this->optimization->constraints->initialDualValues != NULL) 
				{	int i,j;
					int num_con;
					num_con = this->getNumberOfInitDualVarValues();
					for(i = 0; i < num_con; i++)
					{	j = this->optimization->constraints->initialDualValues->con[i]->idx;
						if (j >= 0 && j < numberOfConstraints)						
							initDualVector[j] 
							  = this->optimization->constraints->initialDualValues->con[i]->lbValue;						
						else
							throw ErrorClass("Constraint index out of range");
					}
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return initDualVector;
}//getInitDualVarLowerBoundsDense

double* OSOption::getInitDualVarUpperBoundsDense(int numberOfConstraints){
	double *initDualVector;
	initDualVector = new double[numberOfConstraints];
	for (int k = 0; k < numberOfConstraints; k++) initDualVector[k] = OSNAN;
	try
	{	if (this->optimization != NULL) 
		{	if(this->optimization->constraints != NULL) 
			{	if(this->optimization->constraints->initialDualValues != NULL) 
				{	int i,j;
					int num_con;
					num_con = this->getNumberOfInitDualVarValues();
					for(i = 0; i < num_con; i++)
					{	j = this->optimization->constraints->initialDualValues->con[i]->idx;
						if (j >= 0 && j < numberOfConstraints)						
							initDualVector[j] 
							  = this->optimization->constraints->initialDualValues->con[i]->ubValue;	
						else
							throw ErrorClass("Constraint index out of range");
					}
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return initDualVector;
}//getInitDualVarUpperBoundsDense


std::vector<SolverOption*>  OSOption::setSolverOptions( std::string solver_name){
	std::vector<SolverOption*> optionsVector;
	if (this->optimization != NULL) {
		if (this->optimization->solverOptions != NULL) {
			int i;
			int num_options;
			num_options = this->getNumberOfSolverOptions();
			for(i = 0; i < num_options; i++){
				if(solver_name == this->optimization->solverOptions->solverOption[ i]->solver){
					optionsVector.push_back( this->optimization->solverOptions->solverOption[ i]);
				}
			}
		}					
	}
	return optionsVector;
}//setSolverOptions
*/
