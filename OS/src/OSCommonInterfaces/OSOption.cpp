/* $Id$ */
/** @file OSOption.cpp
 * 
 *
 * @author Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2011, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, Dalhousie University and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */

//#define DEBUG

#ifdef  DEBUG
#define DEBUG_OSOPTION
#endif

#include "OSOption.h"
#include "OSParameters.h"
#include "OSGeneral.h"
#include "OSErrorClass.h"
#include "CoinFinite.hpp"
#include <iostream> 
#include <sstream>
#include <limits>
#include <cstdio>
#include "OSMathUtil.h"

using namespace std;

InstanceLocationOption::InstanceLocationOption(): 
	locationType ("local"),
	value ("")
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside InstanceLocationOption Constructor" << endl;
	#endif
}// end InstanceLocationOption constructor  

InstanceLocationOption::~InstanceLocationOption()
{    
	#ifdef DEBUG_OSOPTION
	cout << "InstanceLocationOption Destructor Called" << endl;
	#endif
}//end InstanceLocationOption destructor 


ContactOption::ContactOption(): 
	transportType ("osp"),
	value ("")
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside ContactOption Constructor" << endl;
	#endif
}// end ContactOption constructor 

ContactOption::~ContactOption()
{    
	#ifdef DEBUG_OSOPTION
	cout << "ContactOption Destructor Called" << endl;
	#endif
}//end ContactOption destructor


OtherOption::OtherOption(): 
	name (""),
	value (""),
	description ("")
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside OtherOption Constructor" << endl;
	#endif
}// end OtherOption constructor 

OtherOption::~OtherOption()
{    
	#ifdef DEBUG_OSOPTION
	cout << "OtherOption Destructor Called" << endl;
	#endif
}//end OtherOption destructor


OtherOptions::OtherOptions(): 
	numberOfOtherOptions(0)
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside OtherOptions Constructor" << endl;
	#endif
	other = NULL;
}// end OtherOptions constructor 

OtherOptions::~OtherOptions()
{    
	#ifdef DEBUG_OSOPTION
	cout << "OtherOptions Destructor Called" << endl;
	#endif

	if (other != NULL)
	{	int i;
		for (i=0; i<numberOfOtherOptions; i++)
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
	#ifdef DEBUG_OSOPTION
	cout << "Inside GeneralOption Constructor" << endl;
	#endif
	instanceLocation = NULL;
	contact = NULL;
	otherOptions = NULL;
}// end GeneralOption constructor  

GeneralOption::~GeneralOption()
{    
	#ifdef DEBUG_OSOPTION
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
	description(""),
	value (0.0)
{
	#ifdef DEBUG_OSOPTION
	cout << "Inside MinDiskSpace Constructor" << endl;
	#endif
}// end MinDiskSpace constructor

MinDiskSpace::~MinDiskSpace()
{
	#ifdef DEBUG_OSOPTION
	cout << "MinDiskSpace Destructor Called" << endl;
	#endif
}// end MinDiskSpace destructor


MinMemorySize::MinMemorySize():
	unit ("byte"),
	description(""),
	value (0.0)
{
	#ifdef DEBUG_OSOPTION
	cout << "Inside MinMemorySize Constructor" << endl;
	#endif
}// end MinMemorySize constructor

MinMemorySize::~MinMemorySize()
{
	#ifdef DEBUG_OSOPTION
	cout << "MinMemorySize Destructor Called" << endl;
	#endif
}// end MinMemorySize destructor


MinCPUSpeed::MinCPUSpeed():
	unit ("hertz"),
	description(""),
	value (0.0)
{
	#ifdef DEBUG_OSOPTION
	cout << "Inside MinCPUSpeed Constructor" << endl;
	#endif
}// end MinCPUSpeed constructor

MinCPUSpeed::~MinCPUSpeed()
{
	#ifdef DEBUG_OSOPTION
	cout << "MinCPUSpeed Destructor Called" << endl;
	#endif
}// end MinCPUSpeed destructor

MinCPUNumber::MinCPUNumber():
	description(""),
	value (0)
{
	#ifdef DEBUG_OSOPTION
	cout << "Inside MinCPUNumber Constructor" << endl;
	#endif
}// end MinCPUNumber constructor

MinCPUNumber::~MinCPUNumber()
{
	#ifdef DEBUG_OSOPTION
	cout << "MinCPUNumber Destructor Called" << endl;
	#endif
}// end MinCPUNumber destructor


SystemOption::SystemOption() 
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside SystemOption Constructor" << endl;
	#endif
	minDiskSpace = NULL;
	minMemorySize = NULL;
	minCPUSpeed = NULL;
	minCPUNumber = NULL;
	otherOptions = NULL;
}// end SystemOption constructor  

SystemOption::~SystemOption()
{    
	#ifdef DEBUG_OSOPTION
	cout << "SystemOption Destructor Called" << endl;
	#endif
	if (minDiskSpace != NULL) delete minDiskSpace;
	minDiskSpace = NULL;
	if (minMemorySize != NULL) delete minMemorySize;
	minMemorySize = NULL;
	if (minCPUSpeed != NULL) delete minCPUSpeed;
	minCPUSpeed = NULL;
	if (minCPUNumber != NULL) delete minCPUNumber;
	minCPUNumber = NULL;
	if (otherOptions != NULL) delete otherOptions;
	otherOptions = NULL;
}//end SystemOption destructor 


ServiceOption::ServiceOption(): 
	type ("solver")
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside ServiceOption Constructor" << endl;
	#endif
	otherOptions = NULL;
}// end ServiceOption constructor  

ServiceOption::~ServiceOption()
{    
	#ifdef DEBUG_OSOPTION
	cout << "ServiceOption Destructor Called" << endl;
	#endif
	if (otherOptions != NULL) delete otherOptions;
	otherOptions = NULL;
}//end ServiceOption destructor 


JobDependencies::JobDependencies():
	numberOfJobIDs (0)
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside JobDependencies Constructor" << endl;
	#endif
	jobID = NULL;
}// end JobDependencies constructor  

JobDependencies::~JobDependencies()
{    
	#ifdef DEBUG_OSOPTION
	cout << "JobDependencies Destructor Called" << endl;
	#endif

	if (jobID != NULL) 
	{	delete[] jobID;
		jobID = NULL;
	}
}//end JobDependencies destructor 


DirectoriesAndFiles::DirectoriesAndFiles():
	numberOfPaths (0)
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside DirectoriesAndFiles Constructor" << endl;
	#endif
	path = NULL;
}// end DirectoriesAndFiles constructor

DirectoriesAndFiles::~DirectoriesAndFiles()
{    
	#ifdef DEBUG_OSOPTION
	cout << "DirectoriesAndFiles Destructor Called" << endl;
	#endif
	if (path != NULL) 
	{	delete[] path;
		path = NULL;
	}
}//end DirectoriesAndFiles destructor 


PathPair::PathPair():
	from (""),
	to (""),
	makeCopy (false)
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside PathPair Constructor" << endl;
	#endif
}// end PathPair constructor  

PathPair::~PathPair()
{    
	#ifdef DEBUG_OSOPTION
	cout << "PathPair Destructor Called" << endl;
	#endif
}//end PathPair destructor 


PathPairs::PathPairs():
	numberOfPathPairs(0)
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside PathPairs Constructor" << endl;
	#endif
	pathPair = NULL;
}// end PathPairs constructor  

PathPairs::~PathPairs()
{    
	#ifdef DEBUG_OSOPTION
	cout << "PathPairs Destructor Called" << endl;
	#endif
	int i;
	if (pathPair != NULL) 
	{	for (i=0; i < numberOfPathPairs; i++)	
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
	#ifdef DEBUG_OSOPTION
	cout << "Inside Processes Constructor" << endl;
	#endif
	process = NULL;
}// end Processes constructor  

Processes::~Processes()
{    
	#ifdef DEBUG_OSOPTION
	cout << "Processes Destructor Called" << endl;
	#endif
	if (process != NULL) 
	{	delete[] process;
		process = NULL;
	}
}//end Processes destructor 


JobOption::JobOption():
	requestedStartTime("")
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside JobOption Constructor" << endl;
	#endif
	maxTime = NULL;
	dependencies = NULL;
	requiredDirectories = NULL;
	requiredFiles = NULL;
	directoriesToMake = NULL;
	filesToMake = NULL;
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
	#ifdef DEBUG_OSOPTION
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
	if (filesToMake != NULL) delete filesToMake;
	filesToMake = NULL;
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
	name (""),
	value (OSNAN)
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside InitVarValue Constructor" << endl;
	#endif
}// end InitVarValue constructor  

InitVarValue::~InitVarValue()
{    
	#ifdef DEBUG_OSOPTION
	cout << "InitVarValue Destructor Called" << endl;
	#endif
}//end InitVarValue destructor 


InitVariableValues::InitVariableValues():
	numberOfVar (0)
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside InitVariableValues Constructor" << endl;
	#endif
	var = NULL;
}// end InitVariableValues constructor  

InitVariableValues::~InitVariableValues()
{    
	#ifdef DEBUG_OSOPTION
	cout << "InitVariableValues Destructor Called" << endl;
	#endif
	int i;
	if (var != NULL) 
	{	for (i=0; i < numberOfVar; i++)
		{	delete var[i];
			var[i] = NULL;
		}
		delete[] var;
		var = NULL;
	}
}//end InitVariableValues destructor 


InitVarValueString::InitVarValueString(): 
	idx (-1),
	name (""),
	value ("")
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside InitVarValueString Constructor" << endl;
	#endif
}// end InitVarValueString constructor  

InitVarValueString::~InitVarValueString()
{    
	#ifdef DEBUG_OSOPTION
	cout << "InitVarValueString Destructor Called" << endl;
	#endif
}//end InitVarValueString destructor 


InitVariableValuesString::InitVariableValuesString():
	numberOfVar (0)
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside InitVariableValuesString Constructor" << endl;
	#endif
	var = NULL;
}// end InitVariableValuesString constructor  

InitVariableValuesString::~InitVariableValuesString()
{    
	#ifdef DEBUG_OSOPTION
	cout << "InitVariableValuesString Destructor Called" << endl;
	#endif
	int i;
	if (var != NULL) 
	{	for (i=0; i < numberOfVar; i++)
		{	delete var[i];
			var[i] = NULL;
		}
		delete[] var;
		var = NULL;
	}
}//end InitVariableValues destructor 

InitBasStatus::InitBasStatus(): 
	idx (-1),
	value ("unknown")
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside InitBasStatus Constructor" << endl;
	#endif
}// end InitBasStatus constructor  

InitBasStatus::~InitBasStatus()
{    
	#ifdef DEBUG_OSOPTION
	cout << "InitBasStatus Destructor Called" << endl;
	#endif
}//end InitBasStatus destructor 


InitialBasisStatus::InitialBasisStatus():
	numberOfVar (0)
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside InitialBasisStatus Constructor" << endl;
	#endif
	var = NULL;
}// end InitialBasisStatus constructor  

InitialBasisStatus::~InitialBasisStatus()
{    
	#ifdef DEBUG_OSOPTION
	cout << "InitialBasisStatus Destructor Called" << endl;
	#endif
	if (var != NULL) 
	{	int i;
		for (i=0; i < numberOfVar; i++)
		{	delete var[i];
			var[i] = NULL;
		}
		delete[] var;
		var = NULL;
	}
}//end InitialBasisStatus destructor 

BranchingWeight::BranchingWeight(): 
	idx (-1),
	name (""),
	value (0.0)
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside BranchingWeight Constructor" << endl;
	#endif
}// end BranchingWeight constructor  

BranchingWeight::~BranchingWeight()
{    
	#ifdef DEBUG_OSOPTION
	cout << "BranchingWeight Destructor Called" << endl;
	#endif
}//end BranchingWeight destructor 


IntegerVariableBranchingWeights::IntegerVariableBranchingWeights():
	numberOfVar (0)
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside IntegerVariableBranchingWeights Constructor" << endl;
	#endif
	var = NULL;
}// end IntegerVariableBranchingWeights constructor  

IntegerVariableBranchingWeights::~IntegerVariableBranchingWeights()
{    
	#ifdef DEBUG_OSOPTION
	cout << "IntegerVariableBranchingWeights Destructor Called; numberOfVar=" << numberOfVar << endl;
	#endif
	if (var != NULL) 
	{	int i;
		for (i=0; i < numberOfVar; i++)
		{	delete var[i];
			var[i] = NULL;
		}
		delete[] var;
		var = NULL;
	}
}//end IntegerVariableBranchingWeights destructor 

SOSWeights::SOSWeights():
	sosIdx (-1),
	groupWeight (1.0),
	numberOfVar (0)
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside SOSWeights Constructor" << endl;
	#endif
	var = NULL;
}// end SOSWeights constructor  

SOSWeights::~SOSWeights()
{    
	#ifdef DEBUG_OSOPTION
	cout << "SOSWeights Destructor Called" << endl;
	#endif
	if (var != NULL) 
	{	int i;
		for (i=0; i < numberOfVar; i++)
		{	delete var[i];
			var[i] = NULL;
		}
		delete[] var;
		var = NULL;
	}
}//end SOSWeights destructor 

SOSVariableBranchingWeights::SOSVariableBranchingWeights():
	numberOfSOS (0)
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside SOSVariableBranchingWeights Constructor" << endl;
	#endif
	sos = NULL;
}// end SOSVariableBranchingWeights constructor  

SOSVariableBranchingWeights::~SOSVariableBranchingWeights()
{    
	#ifdef DEBUG_OSOPTION
	cout << "SOSVariableBranchingWeights Destructor Called" << endl;
	#endif
	if (sos != NULL) 
	{	int i;
		for (i=0; i < numberOfSOS; i++)
		{	delete sos[i];
			sos[i] = NULL;
		}
		delete[] sos;
		sos = NULL;
	}
}//end SOSVariableBranchingWeights destructor 

OtherVarOption::OtherVarOption(): 
	idx (0),
	name (""),
	value (""),
	lbValue (""),
	ubValue ("")
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside OtherVarOption Constructor" << endl;
	#endif
}// end OtherVarOption constructor  

OtherVarOption::~OtherVarOption()
{    
	#ifdef DEBUG_OSOPTION
	cout << "OtherVarOption Destructor Called" << endl;
	#endif
}//end OtherVarOption destructor 


OtherVariableOption::OtherVariableOption(): 
	numberOfVar(0),
	numberOfEnumerations(0),
	name (""),
	value (""),
	solver(""),
	category (""),
	type ("string"),
	description ("")
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside OtherVariableOption Constructor" << endl;
	#endif
	var = NULL;
	enumeration = NULL;
}// end OtherVariableOption constructor  

OtherVariableOption::~OtherVariableOption()
{    
	#ifdef DEBUG_OSOPTION
	cout << "OtherVariableOption Destructor Called" << endl;
	#endif
	if (var != NULL) 
	{
		for (int i=0; i < numberOfVar; i++)
		{	delete var[i];
			var[i] = NULL;
		}
		delete[] var;
		var = NULL;
	}
	if (enumeration != NULL) 
	{
		for (int i=0; i < numberOfEnumerations; i++)
		{
			delete enumeration[i];
			enumeration[i] = NULL;
		}
		delete[] enumeration;
		enumeration = NULL;
	}
}//end OtherVariableOption destructor 


VariableOption::VariableOption():
	numberOfOtherVariableOptions(0)
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside VariableOption Constructor" << endl;
	#endif
	initialVariableValues = NULL;
	initialVariableValuesString = NULL;
	initialBasisStatus = NULL;
	integerVariableBranchingWeights = NULL;
	sosVariableBranchingWeights = NULL;
	other = NULL;
}// end VariableOption constructor  

VariableOption::~VariableOption()
{    
	#ifdef DEBUG_OSOPTION
	cout << "VariableOption Destructor Called" << endl;
	#endif
	if (initialVariableValues != NULL) delete initialVariableValues;
	initialVariableValues = NULL;
	if (initialVariableValuesString != NULL) delete initialVariableValuesString;
	initialVariableValuesString = NULL;
	if (initialBasisStatus != NULL) delete initialBasisStatus;
	initialBasisStatus = NULL;
	if (integerVariableBranchingWeights != NULL) delete integerVariableBranchingWeights;
	integerVariableBranchingWeights = NULL;
	if (sosVariableBranchingWeights != NULL) delete sosVariableBranchingWeights;
	sosVariableBranchingWeights = NULL;
	if (other != NULL) 
	{   int i;
		for (i=0; i < numberOfOtherVariableOptions; i++)
		{	if (other[i] != NULL)
				delete other[i];
				other[i] = NULL;
		
		};
 		delete[] other;
		other = NULL;
	};
}//end VariableOption destructor 


InitObjValue::InitObjValue(): 
	idx (-1),
	name (""),
	value (OSNAN)
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside InitObjValue Constructor" << endl;
	#endif
}// end InitObjValue constructor  

InitObjValue::~InitObjValue()
{    
	#ifdef DEBUG_OSOPTION
	cout << "InitObjValue Destructor Called" << endl;
	#endif
}//end InitObjValue destructor 


InitObjectiveValues::InitObjectiveValues():
	numberOfObj (0)
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside InitObjectiveValues Constructor" << endl;
	#endif
	obj = NULL;
}// end InitObjectiveValues constructor  

InitObjectiveValues::~InitObjectiveValues()
{    
	#ifdef DEBUG_OSOPTION
	cout << "InitObjectiveValues Destructor Called" << endl;
	#endif
	if (obj != NULL) 
	{	int i;
		for (i=0; i < numberOfObj; i++)
		{	delete obj[i];
			obj[i] = NULL;
		}
		delete[] obj;
		obj = NULL;
	};
}//end InitObjectiveValues destructor 


InitObjBound::InitObjBound(): 
	idx (-1),
	name (""),
	lbValue (-OSDBL_MAX),
	ubValue ( OSDBL_MAX)
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside InitObjBound Constructor" << endl;
	#endif
}// end  constructor  template

InitObjBound::~InitObjBound()
{    
	#ifdef DEBUG_OSOPTION
	cout << "InitObjBound Destructor Called" << endl;
	#endif
}//end InitObjBound destructor 


InitObjectiveBounds::InitObjectiveBounds():
	numberOfObj (0)
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside InitObjectiveBounds Constructor" << endl;
	#endif
	obj = NULL;
}// end InitObjectiveBounds constructor  

InitObjectiveBounds::~InitObjectiveBounds()
{    
	#ifdef DEBUG_OSOPTION
	cout << "InitObjectiveBounds Destructor Called" << endl;
	#endif
	if (obj != NULL) 
	{	int i;
		for (i=0; i < numberOfObj; i++)
		{	delete obj[i];
			obj[i] = NULL;
		}
		delete[] obj;
		obj = NULL;
	};
}//end InitObjectiveBounds destructor 


OtherObjOption::OtherObjOption(): 
	idx (-1),
	name (""),
	value (""),
	lbValue (""),
	ubValue ("")
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside OtherObjOption Constructor" << endl;
	#endif
}// end OtherObjOption constructor  

OtherObjOption::~OtherObjOption()
{    
	#ifdef DEBUG_OSOPTION
	cout << "OtherObjOption Destructor Called" << endl;
	#endif
}//end OtherObjOption destructor 


OtherObjectiveOption::OtherObjectiveOption(): 
	numberOfObj(0),
	numberOfEnumerations(0),
	name (""),
	value (""),
	solver(""),
	category (""),
	type ("string"),
	description ("")
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside OtherObjectiveOption Constructor" << endl;
	#endif
	obj = NULL;
	enumeration = NULL;
}// end OtherObjectiveOption constructor  

OtherObjectiveOption::~OtherObjectiveOption()
{    
	#ifdef DEBUG_OSOPTION
	cout << "OtherObjectiveOption Destructor Called" << endl;
	#endif
	if (obj != NULL) 
	{
		for (int i=0; i < numberOfObj; i++)
		{	delete obj[i];
			obj[i] = NULL;
		}
		delete[] obj;
		obj = NULL;
	}
	if (enumeration != NULL) 
	{
		for (int i=0; i < numberOfEnumerations; i++)
		{
			delete enumeration[i];
			enumeration[i] = NULL;
		}
		delete[] enumeration;
		enumeration = NULL;
	}
}//end OtherObjectiveOption destructor 


ObjectiveOption::ObjectiveOption(): 
	numberOfOtherObjectiveOptions (0)
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside ObjectiveOption Constructor" << endl;
	#endif
	initialObjectiveValues = NULL;
	initialObjectiveBounds = NULL;
	initialBasisStatus = NULL;
	other = NULL;
}// end ObjectiveOption constructor  

ObjectiveOption::~ObjectiveOption()
{    
	#ifdef DEBUG_OSOPTION
	cout << "ObjectiveOption Destructor Called" << endl;
	#endif
	if (initialObjectiveValues != NULL) delete initialObjectiveValues;
	initialObjectiveValues = NULL;
	if (initialObjectiveBounds != NULL) delete initialObjectiveBounds;
	initialObjectiveBounds = NULL;
	if (initialBasisStatus != NULL) delete initialBasisStatus;
	initialBasisStatus = NULL;
	if (other != NULL) 
	{	int i;
		for (i=0; i < numberOfOtherObjectiveOptions; i++)
		{	delete other[i];
			other[i] = NULL;
		}
		delete[] other;
		other = NULL;
	}
}//end ObjectiveOption destructor 


InitConValue::InitConValue(): 
	idx (0),
	name (""),
	value (OSNAN)
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside InitConValue Constructor" << endl;
	#endif
}// end InitConValue constructor  

InitConValue::~InitConValue()
{    
	#ifdef DEBUG_OSOPTION
	cout << "InitConValue Destructor Called" << endl;
	#endif
}//end InitConValue destructor 


InitConstraintValues::InitConstraintValues(): 
	numberOfCon (0)
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside InitConstraintValues Constructor" << endl;
	#endif
	con = NULL;
}// end InitConstraintValues constructor  

InitConstraintValues::~InitConstraintValues()
{    
	#ifdef DEBUG_OSOPTION
	cout << "InitConstraintValues Destructor Called" << endl;
	#endif
	if (con != NULL) 
	{	int i;
		for (i=0; i < numberOfCon; i++)
		{	delete con[i];
			con[i] = NULL;
		}
		delete[] con;
		con = NULL;
	};
}//end InitConstraintValues destructor


InitDualVarValue::InitDualVarValue(): 
	idx (0),
	name (""),
	lbDualValue (0.0),
	ubDualValue (0.0)
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside InitDualVarValue Constructor" << endl;
	#endif
}// end InitDualVarValue constructor  

InitDualVarValue::~InitDualVarValue()
{    
	#ifdef DEBUG_OSOPTION
	cout << "InitDualVarValue Destructor Called" << endl;
	#endif
}//end InitDualVarValue destructor


InitDualVariableValues::InitDualVariableValues(): 
	numberOfCon (0)
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside InitDualVariableValues Constructor" << endl;
	#endif
	con = NULL;
}// end InitDualVariableValues constructor  

InitDualVariableValues::~InitDualVariableValues()
{    
	#ifdef DEBUG_OSOPTION
	cout << "InitDualVariableValues Destructor Called" << endl;
	#endif
	if (con != NULL) 
	{	int i;
		for (i=0; i < numberOfCon; i++)
		{	delete con[i];
			con[i] = NULL;
		}
		delete[] con;
		con = NULL;
	};
}//end InitDualVariableValues destructor


OtherConOption::OtherConOption(): 
	idx (0),
	name (""),
	value (""),
	lbValue (""),
	ubValue ("")
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside OtherConOption Constructor" << endl;
	#endif
}// end OtherConOption constructor  

OtherConOption::~OtherConOption()
{    
	#ifdef DEBUG_OSOPTION
	cout << "OtherConOption Destructor Called" << endl;
	#endif
}//end OtherConOption destructor


OtherConstraintOption::OtherConstraintOption(): 
	numberOfCon(0),
	numberOfEnumerations(0),
	name (""),
	value (""),
	solver(""),
	category (""),
	type ("string"),
	description ("")
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside OtherConstraintOption Constructor" << endl;
	#endif
	con = NULL;
	enumeration = NULL;
}// end OtherConstraintOption constructor  

OtherConstraintOption::~OtherConstraintOption()
{    
	#ifdef DEBUG_OSOPTION
	cout << "OtherConstraintOption Destructor Called" << endl;
	#endif
	if (con != NULL) 
	{
		for (int i=0; i < numberOfCon; i++)
		{
			if (con[i]!= NULL) delete con[i];
			con[i] = NULL;
		}
		delete[] con;
		con = NULL;
	}
	if (enumeration != NULL) 
	{
		for (int i=0; i < numberOfEnumerations; i++)
		{
			delete enumeration[i];
			enumeration[i] = NULL;
		}
		delete[] enumeration;
		enumeration = NULL;
	}
}//end OtherConstraintOption destructor


ConstraintOption::ConstraintOption(): 
	numberOfOtherConstraintOptions (0)
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside ConstraintOption Constructor" << endl;
	#endif
	initialConstraintValues = NULL;
	initialDualValues = NULL;
	initialBasisStatus = NULL;
	other = NULL;
}// end ConstraintOption constructor  

ConstraintOption::~ConstraintOption()
{    
	#ifdef DEBUG_OSOPTION
	cout << "ConstraintOption Destructor Called" << endl;
	#endif
	if (initialConstraintValues != NULL) delete initialConstraintValues;
	initialConstraintValues = NULL;
	if (initialDualValues != NULL) delete initialDualValues;
	initialDualValues = NULL;
	if (initialBasisStatus != NULL) delete initialBasisStatus;
	initialBasisStatus = NULL;
	if (other != NULL) 
	{	int i;
		for (i=0; i < numberOfOtherConstraintOptions; i++)
		{	delete other[i];
			other[i] = NULL;
		}
		delete[] other;
		other = NULL;
	}
}//end ConstraintOption destructor


SolverOption::SolverOption(): 
	name (""),
	value (""),
	solver(""),
	category (""),
	type (""),
	description (""),
	numberOfItems(0),
	item(NULL)
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside SolverOption Constructor" << endl;
	#endif
}// end SolverOption constructor  

SolverOption::~SolverOption()
{    
	#ifdef DEBUG_OSOPTION
	cout << "SolverOption Destructor Called" << endl;
	#endif
	if (item != NULL) delete[] item;
	item = NULL;
}//end SolverOption destructor


SolverOptions::SolverOptions(): 
	numberOfSolverOptions(0)
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside SolverOptions Constructor" << endl;
	#endif
	solverOption = NULL;
}// end SolverOptions constructor 

SolverOptions::~SolverOptions()
{    
	#ifdef DEBUG_OSOPTION
	cout << "SolverOptions Destructor Called; numberOfSolverOptions=" << numberOfSolverOptions << endl;
	#endif
	if (solverOption != NULL)
	{	int i;
		for (i=0; i<numberOfSolverOptions; i++)
		{	delete solverOption[i];
			solverOption[i] = NULL;
		}
		delete[] solverOption;
		solverOption = NULL;
	}
}//end SolverOptions destructor


OptimizationOption::OptimizationOption(): 
	numberOfVariables (-1),
	numberOfObjectives (-1),
	numberOfConstraints (-1)
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside OptimizationOption Constructor" << endl;
	#endif
	variables = NULL;
	objectives = NULL;
	constraints = NULL;
	solverOptions = NULL;
}// end OptimizationOption constructor  

OptimizationOption::~OptimizationOption()
{    
	#ifdef DEBUG_OSOPTION
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


OSOption::OSOption() 
//(initializations)
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside OSOption Constructor" << endl;
	#endif

	optionHeader = NULL;
	general = NULL;
	system = NULL;
	service = NULL;
	job = NULL;
	optimization = NULL;
	m_mdInitVarValuesDense = NULL;
	m_mdInitVarValuesStringDense = NULL;
	m_mdInitBasisStatusDense = NULL;
	m_mdIntegerVariableBranchingWeightsDense = NULL;
	m_mdInitObjValuesDense = NULL;
	m_mdInitObjLowerBoundsDense = NULL;
	m_mdInitObjUpperBoundsDense = NULL;
	m_mdInitConValuesDense = NULL;
	m_mdInitDualVarLowerBoundsDense = NULL;
	m_mdInitDualVarUpperBoundsDense = NULL;
}// end OSOption constructor  

OSOption::~OSOption()
{    
	#ifdef DEBUG_OSOPTION
	cout << "OSOption Destructor Called" << endl;
	#endif
	if (optionHeader != NULL) delete optionHeader;
	optionHeader = NULL;
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

	if (m_mdInitVarValuesDense != NULL) 
		delete[] m_mdInitVarValuesDense;
	m_mdInitVarValuesDense = NULL;

	if (m_mdInitVarValuesStringDense != NULL) 
		delete[] m_mdInitVarValuesStringDense;
	m_mdInitVarValuesStringDense = NULL;

	if (m_mdInitBasisStatusDense != NULL) 
		delete[] m_mdInitBasisStatusDense;
	m_mdInitBasisStatusDense = NULL;

	if (m_mdIntegerVariableBranchingWeightsDense != NULL) 
		delete[] m_mdIntegerVariableBranchingWeightsDense;
	m_mdIntegerVariableBranchingWeightsDense = NULL;

	if (m_mdInitObjValuesDense != NULL) 
		delete[] m_mdInitObjValuesDense;
	m_mdInitObjValuesDense = NULL;

	if (m_mdInitObjLowerBoundsDense != NULL) 
		delete[] m_mdInitObjLowerBoundsDense;
	m_mdInitObjLowerBoundsDense = NULL;

	if (m_mdInitObjUpperBoundsDense != NULL) 
		delete[] m_mdInitObjUpperBoundsDense;
	m_mdInitObjUpperBoundsDense = NULL;

	if (m_mdInitConValuesDense != NULL) 
		delete[] m_mdInitConValuesDense;
	m_mdInitConValuesDense = NULL;

	if (m_mdInitDualVarLowerBoundsDense != NULL) 
		delete[] m_mdInitDualVarLowerBoundsDense;
	m_mdInitDualVarLowerBoundsDense = NULL;

	if (m_mdInitDualVarUpperBoundsDense != NULL) 
		delete[] m_mdInitDualVarUpperBoundsDense;
	m_mdInitDualVarUpperBoundsDense = NULL;
}//end OSOption destructor




/****************************************************************
 * get() methods
 ****************************************************************/

/*********************************** 
 * get() methods that return strings
 ***********************************/

/**
 * get the file name (in <optionHeader> element)
 */
std::string  OSOption::getFileName()
{	if (this->optionHeader != NULL) 
		return this->optionHeader->name;

	return "";
}//getFileName

/**
 * get the file source (in <optionHeader> element)
 */
std::string  OSOption::getFileSource()
{	if (this->optionHeader != NULL) 
		return this->optionHeader->source;

	return "";
}//getFileSource

/**
 * get the file description (in <optionHeader> element)
 */
std::string  OSOption::getFileDescription()
{	if (this->optionHeader != NULL) 
		return this->optionHeader->description;

	return "";
}//getFileDescription

/**
 * get the file creator (in <optionHeader> element)
 */
std::string  OSOption::getFileCreator()
{	if (this->optionHeader != NULL) 
		return this->optionHeader->fileCreator;

	return "";
}//getFileCreator

/**
 * get the file licence information (in <optionHeader> element)
 */
std::string  OSOption::getFileLicence()
{	if (this->optionHeader != NULL) 
		return this->optionHeader->licence;

	return "";
}//getFileLicence


/**
 * get the service URI (in <general> element)
 */
std::string  OSOption::getServiceURI()
{	if (this->general != NULL) 
		return this->general->serviceURI;

	return "";
}//getServiceURI

/**
 * get the service name (in <general> element)
 */
std::string  OSOption::getServiceName()
{	if (this->general != NULL) 
		return this->general->serviceName;

	return "";
}//getServiceName

/**
 * get the instance name (in <general> element)
 */
std::string  OSOption::getInstanceName()
{	if (this->general != NULL) 
		return this->general->instanceName;

	return "";
}//getInstanceName

/**
 * get the instance location (in <general> element)
 */
std::string  OSOption::getInstanceLocation()
{	if (this->general != NULL) 
		if (this->general->instanceLocation != NULL)
			return this->general->instanceLocation->value;

	return "";
}//getInstanceLocation

/**
 * get the instance location type (in <general> element)
 */
std::string  OSOption::getInstanceLocationType()
{	if (this->general != NULL) 
		if (this->general->instanceLocation != NULL)
			return this->general->instanceLocation->locationType;

	return "";
}//getLocationType

/**
 * get the job ID (in <general> element)
 */
std::string  OSOption::getJobID()
{	if (this->general != NULL) 
		return this->general->jobID;

	return "";
}//getJobID

/**
 * get the name of the solver to be invoked (in <general> element)
 */
std::string  OSOption::getSolverToInvoke()
{	if (this->general != NULL) 
		return this->general->solverToInvoke;

	return "";
}//getSolverToInvoke

/**
 * get the license information (in <general> element)
 */
std::string  OSOption::getLicense()
{	if (this->general != NULL) 
		return this->general->license;

	return "";
}//getLicense

/**
 * get the user name (in <general> element)
 */
std::string  OSOption::getUserName()
{	if (this->general != NULL) 
		return this->general->userName;

	return "";
}//getUserName

/**
 * get the password (in <general> element)
 */
std::string  OSOption::getPassword()
{	if (this->general != NULL) 
		return this->general->password;

	return "";
}//getPassword

/**
 * get the contact information (in <general> element)
 */
std::string  OSOption::getContact()
{	if (this->general != NULL) 
		if (this->general->contact != NULL)
			return this->general->contact->value;

	return "";
}//getContact

/**
 * get the transport type (in <general> element)
 */
std::string  OSOption::getContactTransportType()
{	if (this->general != NULL) 
		if (this->general->contact != NULL)
			return this->general->contact->transportType;

	return "";
}//getContactTransportType

/**
 * get the disk space units (in <system> element)
 */
std::string  OSOption::getMinDiskSpaceUnit()
{	if (this->system != NULL) 
		if (this->system->minDiskSpace != NULL)
			return this->system->minDiskSpace->unit;

	return "";
}//getMinDiskSpaceUnit

/**
 * get the disk space description (in <system> element)
 */
std::string  OSOption::getMinDiskSpaceDescription()
{	if (this->system != NULL) 
		if (this->system->minDiskSpace != NULL)
			return this->system->minDiskSpace->description;

	return "";
}//getMinDiskSpaceDescription

/**
 * get the memory units (in <system> element)
 */
std::string  OSOption::getMinMemoryUnit()
{	if (this->system != NULL) 
		if (this->system->minMemorySize != NULL)
			return this->system->minMemorySize->unit;

	return "";
}//getMinMemory

/**
 * get the memory description (in <system> element)
 */
std::string  OSOption::getMinMemoryDescription()
{	if (this->system != NULL) 
		if (this->system->minMemorySize != NULL)
			return this->system->minMemorySize->description;

	return "";
}//getMinMemoryDescription

/**
 * get the CPU speed units (in <system> element)
 */
std::string  OSOption::getMinCPUSpeedUnit()
{	if (this->system != NULL) 
		if (this->system->minCPUSpeed != NULL)
			return this->system->minCPUSpeed->unit;

	return "";
}//getMinCPUSpeed

/**
 * get the CPU speed description (in <system> element)
 */
std::string  OSOption::getMinCPUSpeedDescription()
{	if (this->system != NULL) 
		if (this->system->minCPUSpeed != NULL)
			return this->system->minCPUSpeed->description;

	return "";
}//getMinCPUSpeedDescription

/**
 * get the CPU description (in <system> element)
 */
std::string  OSOption::getMinCPUNumberDescription()
{	if (this->system != NULL) 
		if (this->system->minCPUNumber != NULL)
			return this->system->minCPUNumber->description;

	return "";
}//getMinCPUNumberDescription

/**
 * get the service type (in <service> element)
 */
std::string  OSOption::getServiceType()
{	if (this->service != NULL) 
		return this->service->type;

	return "";
}//getServiceType

/**
 * get the time unit (in <job> element)
 */
std::string  OSOption::getMaxTimeUnit()
{	if (this->job != NULL) 
		if (this->job->maxTime != NULL)
			return this->job->maxTime->unit;

	return "";
}//getMaxTimeUnit

/**
 * get the requested start time (in <job> element)
 */
std::string  OSOption::getRequestedStartTime()
{	if (this->job != NULL) 
		return this->job->requestedStartTime;

	return "";
}//getRequestedStartTime

/**
 * get the value of a string-valued option
 * @param optionName The name of the option
 * @return the value of the option optionName
 * @note This function returns the empty string "" if optionName is not found
 */
std::string  OSOption::getOptionStr(std::string optionName)
{	if (optionName == "serviceURI") 
		return this->getServiceURI();

	if (optionName == "serviceName") 
		return this->getServiceName();

	if (optionName == "instanceName") 
		return this->getInstanceName();

	if (optionName == "instanceLocation") 
		return this->getInstanceLocation();

	if (optionName == "instanceLocationType") 
		return this->getInstanceLocationType();

	if (optionName == "jobID") 
		return this->getJobID();

	if (optionName == "solverToInvoke") 
		return this->getSolverToInvoke();

	if (optionName == "license") 
		return this->getLicense();

	if (optionName == "userName") 
		return this->getUserName();

	if (optionName == "password") 
		return this->getPassword();

	if (optionName == "contact") 
		return this->getContact();

	if (optionName == "contactTransportType") 
		return this->getContactTransportType();

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

	if (optionName == "requestedStartTime") 
		return this->getRequestedStartTime();

	return "";
}//getOptionStr

/*********************************** 
 * get() methods that return doubles
 ***********************************/

/**
 * get the minimum disk space required (in <system> element)
 */
double  OSOption::getMinDiskSpace()
{	if (this->system != NULL) 
		if (this->system->minDiskSpace != NULL)
			return this->system->minDiskSpace->value;

	return 0;
}//getMinDiskSpace

/**
 * get the minimum memory required (in <system> element)
 */
double  OSOption::getMinMemorySize()
{	if (this->system != NULL) 
		if (this->system->minMemorySize != NULL)
			return this->system->minMemorySize->value;

	return 0;
}//getMinMemorySize

/**
 * get the minimum CPU speed required (in <system> element)
 */
double  OSOption::getMinCPUSpeed()
{	if (this->system != NULL) 
		if (this->system->minCPUSpeed != NULL)
			return this->system->minCPUSpeed->value;

	return 0;
}//getMinCPUSpeed

/**
 * get the maximum time allowed (in <job> element)
 */
double  OSOption::getMaxTime()
{	if (this->job != NULL) 
		if (this->job->maxTime != NULL)
			return job->maxTime->value;

	return 0;
}//getMaxTime

/**
 * get the value of a double-valued option
 * @param optionName The name of the option
 * @return the value of the option optionName
 * @note returns 0 if optionName is not found
 */
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

/**
 * get the minimum number of CPUs required (in <system> element)
 */
int  OSOption::getMinCPUNumber()
{	if (this->system != NULL) 
		return this->system->minCPUNumber->value;

	return 0;
}//getMinCPUNumber

/**
 * get the number of other <general> options
 */
int  OSOption::getNumberOfOtherGeneralOptions()
{	if (this->general != NULL) 
		if (this->general->otherOptions != NULL) 
			return this->general->otherOptions->numberOfOtherOptions;

	return 0;
}//getNumberOfOtherGeneralOptions

/**
 * get the number of other <system> options
 */
int  OSOption::getNumberOfOtherSystemOptions()
{	if (this->system != NULL) 
		if (this->system->otherOptions != NULL) 
			return this->system->otherOptions->numberOfOtherOptions;

	return 0;
}//getNumberOfOtherSystemOptions

/**
 * get the number of other <service> options
 */
int  OSOption::getNumberOfOtherServiceOptions()
{	if (this->service != NULL) 
		if (this->service->otherOptions != NULL) 
			return this->service->otherOptions->numberOfOtherOptions;

	return 0;
}//getNumberOfOtherServiceOptions

/**
 * get the number of other <job> options
 */
int  OSOption::getNumberOfOtherJobOptions()
{	if (this->job != NULL) 
		if (this->job->otherOptions != NULL) 
			return this->job->otherOptions->numberOfOtherOptions;

	return 0;
}//getNumberOfOtherJobOptions

/**
 * get the number of job dependencies (in <job> element)
 */
int  OSOption::getNumberOfJobDependencies()
{	if (this->job != NULL) 
		if (this->job->dependencies != NULL) 
			return this->job->dependencies->numberOfJobIDs;

	return 0;
}//getNumberOfJobDependencies

/**
 * get the number of required directories (in <job> element)
 */
int  OSOption::getNumberOfRequiredDirectories()
{	if (this->job != NULL) 
		if (this->job->requiredDirectories != NULL) 
			return this->job->requiredDirectories->numberOfPaths;

	return 0;
}//getNumberOfRequiredDirectories

/**
 * get the number of required files (in <job> element)
 */
int  OSOption::getNumberOfRequiredFiles()
{	if (this->job != NULL) 
		if (this->job->requiredFiles != NULL) 
			return this->job->requiredFiles->numberOfPaths;

	return 0;
}//getNumberOfRequiredFiles

/**
 * get the number of directories to make (in <job> element)
 */
int  OSOption::getNumberOfDirectoriesToMake()
{	if (this->job != NULL) 
		if (this->job->directoriesToMake != NULL) 
			return this->job->directoriesToMake->numberOfPaths;

	return 0;
}//getNumberOfDirectoriesToMake

/**
 * get the number of files to create (in <job> element)
 */
int  OSOption::getNumberOfFilesToMake()
{	if (this->job != NULL) 
		if (this->job->filesToMake != NULL) 
			return this->job->filesToMake->numberOfPaths;

	return 0;
}//getNumberOfFilesToMake

/**
 * get the number of input directories to move or copy (in <job> element)
 */
int  OSOption::getNumberOfInputDirectoriesToMove()
{	if (this->job != NULL) 
		if (this->job->inputDirectoriesToMove != NULL) 
			return this->job->inputDirectoriesToMove->numberOfPathPairs;

	return 0;
}//getNumberOfInputDirectoriesToMove

/**
 * get the number of input files to move or copy (in <job> element)
 */
int  OSOption::getNumberOfInputFilesToMove()
{	if (this->job != NULL) 
		if (this->job->inputFilesToMove != NULL) 
			return this->job->inputFilesToMove->numberOfPathPairs;

	return 0;
}//getNumberOfInputFilesToMove

/**
 * get the number of output directories to move or copy (in <job> element)
 */
int  OSOption::getNumberOfOutputDirectoriesToMove()
{	if (this->job != NULL) 
		if (this->job->outputDirectoriesToMove != NULL) 
			return this->job->outputDirectoriesToMove->numberOfPathPairs;

	return 0;
}//getNumberOfOutputDirectoriesToMove

/**
 * get the number of output files to move or copy (in <job> element)
 */
int  OSOption::getNumberOfOutputFilesToMove()
{	if (this->job != NULL) 
		if (this->job->outputFilesToMove != NULL) 
			return this->job->outputFilesToMove->numberOfPathPairs;

	return 0;
}//getNumberOfOutputFilesToMove

/**
 * get the number of files to delete (in <job> element)
 */
int  OSOption::getNumberOfFilesToDelete()
{	if (this->job != NULL) 
		if (this->job->filesToDelete != NULL) 
			return this->job->filesToDelete->numberOfPaths;

	return 0;
}//getNumberOfFilesToDelete

/**
 * get the number of directories to delete (in <job> element)
 */
int  OSOption::getNumberOfDirectoriesToDelete()
{	if (this->job != NULL) 
		if (this->job->directoriesToDelete != NULL) 
			return this->job->directoriesToDelete->numberOfPaths;

	return 0;
}//getNumberOfDirectoriesToDelete

/**
 * get the number of processes to kill (in <job> element)
 */
int  OSOption::getNumberOfProcessesToKill()
{	if (this->job != NULL) 
		if (this->job->processesToKill != NULL) 
			return this->job->processesToKill->numberOfProcesses;

	return 0;
}//getNumberOfProcessesToKill

/**
 * get the number of variables (in <optimization> element)
 */
int  OSOption::getNumberOfVariables()
{	if (this->optimization != NULL) 
		return this->optimization->numberOfVariables;

	return -1;
}//getNumberOfVariables

/**
 * get the number of objectives (in <optimization> element)
 */
int  OSOption::getNumberOfObjectives()
{	if (this->optimization != NULL) 
		return this->optimization->numberOfObjectives;

	return -1;
}//getNumberOfObjectives

/**
 * get the number of constraints (in <optimization> element)
 */
int  OSOption::getNumberOfConstraints()
{	if (this->optimization != NULL) 
		return this->optimization->numberOfConstraints;

	return -1;
}//getNumberOfConstraints


/**
 * get the number of variables that have initial values (in <optimization> element)
 */
int OSOption::getNumberOfInitVarValues()
{	
	if (this->optimization != NULL) 
	{	
		if (this->optimization->variables != NULL) 
		{	
			if (this->optimization->variables->initialVariableValues != NULL) 
			{	
				return this->optimization->variables->initialVariableValues->numberOfVar;
			}
		}
	}
	return -1;
}//getNumberOfInitVarValues

/**
 * get the number of string-valued variables that have initial values (in <optimization> element)
 */
int OSOption::getNumberOfInitVarValuesString()
{	if (this->optimization != NULL) 
		if (this->optimization->variables != NULL) 
			if (this->optimization->variables->initialVariableValuesString != NULL) 
				return this->optimization->variables->initialVariableValuesString->numberOfVar;
	return -1;
}//getNumberOfInitVarValuesString


/**
 * get the number of variables that are given integer branching weights (in <optimization> element)
 */
int OSOption::getNumberOfIntegerVariableBranchingWeights()
{	if (this->optimization != NULL) 
		if (this->optimization->variables != NULL) 
			if (this->optimization->variables->integerVariableBranchingWeights != NULL) 
				return this->optimization->variables->integerVariableBranchingWeights->numberOfVar;
	return -1;
}//getNumberOfIntegerBranchingWeights

/**
 * get the number of SOS that are given branching weights (in <optimization> element)
 */
int OSOption::getNumberOfSOS()
{	if (this->optimization != NULL) 
		if (this->optimization->variables != NULL) 
			if (this->optimization->variables->sosVariableBranchingWeights != NULL) 
				return this->optimization->variables->sosVariableBranchingWeights->numberOfSOS;
	return -1;
}//getNumberOfSOS

/**
 * get the number of variables that are given integer branching weights (in <optimization> element)
 */
int OSOption::getNumberOfSOSVarBranchingWeights(int iSOS)
{	if (this->optimization != NULL) 
		if (this->optimization->variables != NULL) 
			if (this->optimization->variables->sosVariableBranchingWeights != NULL) 
			{	if (iSOS >= 0 && iSOS < this->optimization->variables->sosVariableBranchingWeights->numberOfSOS)
					if (this->optimization->variables->sosVariableBranchingWeights->sos[iSOS] != NULL) 
						return this->optimization->variables->sosVariableBranchingWeights->sos[iSOS]->numberOfVar;
			}
	return -1;
}//getNumberOfSOSVarBranchingWeights

/**
 * get the number of other variable options (in <optimization> element)
 */
int OSOption::getNumberOfOtherVariableOptions()
{	if (this->optimization != NULL)
		if (this->optimization->variables != NULL)
			return this->optimization->variables->numberOfOtherVariableOptions;

	return 0;
}//getNumberOfOtherVariableOptions

/**
 * get the number of objectives for which initial values are given (in <optimization> element)
 */
int OSOption::getNumberOfInitObjValues()
{	if (this->optimization != NULL) 
		if (this->optimization->objectives != NULL) 
			if (this->optimization->objectives->initialObjectiveValues != NULL) 
				return this->optimization->objectives->initialObjectiveValues->numberOfObj;

return -1;
}//getNumberOfInitObjValues

/**
 * get the number of objectives for which initial bounds are given (in <optimization> element)
 */
int OSOption::getNumberOfInitObjBounds()
{	if (this->optimization != NULL) 
		if (this->optimization->objectives != NULL) 
			if (this->optimization->objectives->initialObjectiveBounds != NULL) 
				return this->optimization->objectives->initialObjectiveBounds->numberOfObj;
	return -1;
}//getNumberOfInitObjBounds

/**
 * get the number of other objective options (in <optimization> element)
 */
int OSOption::getNumberOfOtherObjectiveOptions()
{	if (this->optimization != NULL)
		if (this->optimization->objectives != NULL)
			return this->optimization->objectives->numberOfOtherObjectiveOptions;
	return 0;
}//getNumberOfOtherObjectiveOptions

/**
 * get the number of constraints for which initial values are given (in <optimization> element)
 */
int OSOption::getNumberOfInitConValues()
{	if (this->optimization != NULL) 
		if (this->optimization->constraints != NULL) 
			if (this->optimization->constraints->initialConstraintValues != NULL) 
				return this->optimization->constraints->initialConstraintValues->numberOfCon;
	return -1;
}//getNumberOfInitConValues

/**
 * get the number of constraints for which initial dual values are given (in <optimization> element)
 */
int OSOption::getNumberOfInitDualVarValues()
{	if (this->optimization != NULL) 
		if (this->optimization->constraints != NULL) 
			if (this->optimization->constraints->initialDualValues != NULL) 
				return this->optimization->constraints->initialDualValues->numberOfCon;

	return -1;
}//getNumberOfInitDualVarValues

/**
 * get the number of other constraint options (in <optimization> element)
 */
int OSOption::getNumberOfOtherConstraintOptions()
{	if (this->optimization != NULL)
		if (this->optimization->constraints != NULL)
			return this->optimization->constraints->numberOfOtherConstraintOptions;

	return -1;
}//getNumberOfOtherConstraintOptions

/**
 * get the number of other solver options (in <optimization> element)
 */
int OSOption::getNumberOfSolverOptions()
{	if (this->optimization != NULL) 
		if (this->optimization->solverOptions != NULL) 
			return this->optimization->solverOptions->numberOfSolverOptions;
		
	return -1;
}//getNumberOfSolverOptions

/**
 * get the value of an integer-valued option
 * @param optionName The name of the option
 * @return the value of the option optionName
 * @note This function returns -1 if optionName is not found
 */
int  OSOption::getOptionInt(std::string optionName)
{	if (optionName == "minCPUNumber")
		return this->getMinCPUNumber();

	if (optionName == "numberOfOtherGeneralOptions")
		return this->getNumberOfOtherGeneralOptions();

	if (optionName == "numberOfOtherSystemOptions")
		return this->getNumberOfOtherSystemOptions();

	if (optionName == "numberOfOtherServiceOptions")
		return this->getNumberOfOtherServiceOptions();

	if (optionName == "numberOfOtherJobOptions")
		return this->getNumberOfOtherJobOptions();

	if (optionName == "numberOfJobDependencies")
		return this->getNumberOfJobDependencies();

	if (optionName == "numberOfRequiredDirectories")
		return this->getNumberOfRequiredDirectories();

	if (optionName == "numberOfRequiredFiles")
		return this->getNumberOfRequiredFiles();

	if (optionName == "numberOfDirectoriesToMake")
		return this->getNumberOfDirectoriesToMake();

	if (optionName == "numberOfFilesToMake")
		return this->getNumberOfFilesToMake();

	if (optionName == "numberOfInputDirectoriesToMove")
		return this->getNumberOfInputDirectoriesToMove();

	if (optionName == "numberOfInputFilesToMove")
		return this->getNumberOfInputFilesToMove();

	if (optionName == "numberOfOutputDirectoriesToMove")
		return this->getNumberOfOutputDirectoriesToMove();

	if (optionName == "numberOfOutputFilesToMove")
		return this->getNumberOfOutputFilesToMove();

	if (optionName == "numberOfFilesToDelete")
		return this->getNumberOfFilesToDelete();

	if (optionName == "numberOfDirectoriesToDelete")
		return this->getNumberOfDirectoriesToDelete();

	if (optionName == "numberOfProcessesToKill")
		return this->getNumberOfProcessesToKill();

	if (optionName == "numberOfVariables")
		return this->getNumberOfVariables();

	if (optionName == "numberOfObjectives")
		return this->getNumberOfObjectives();

	if (optionName == "numberOfConstraints")
		return this->getNumberOfConstraints();

	if (optionName == "numberOfInitVarValues")
		return this->getNumberOfInitVarValues();

	if (optionName == "numberOfInitVarValuesString")
		return this->getNumberOfInitVarValuesString();

	if (optionName == "numberOfIntegerVariableBranchingWeights")
		return this->getNumberOfIntegerVariableBranchingWeights();

	if (optionName == "numberOfSOS")
		return this->getNumberOfSOS();

	if (optionName == "numberOfOtherVariableOptions")
		return this->getNumberOfOtherVariableOptions();

	if (optionName == "numberOfInitObjValues")
		return this->getNumberOfInitObjValues();

	if (optionName == "numberOfInitObjBounds")
		return this->getNumberOfInitObjBounds();

	if (optionName == "numberOfOtherObjectiveOptions")
		return this->getNumberOfOtherObjectiveOptions();

	if (optionName == "numberOfInitConValues")
		return this->getNumberOfInitConValues();

	if (optionName == "numberOfInitDualVarValues")
		return this->getNumberOfInitDualVarValues();

	if (optionName == "numberOfOtherConstraintOptions")
		return this->getNumberOfOtherConstraintOptions();

	if (optionName == "numberOfSolverOptions")
		return this->getNumberOfSolverOptions();

	return -1;
}//getOptionInt


/**************************************************** 
 * get() methods that return arrays of various kinds
 ****************************************************/

/**
 * get the array of other <general> options
 */
OtherOption** OSOption::getOtherGeneralOptions()
{	if (this->general != NULL) 
	{	if (this->general->otherOptions != NULL)
			return this->general->otherOptions->other;
	}
	return NULL;
}//getOtherGeneralOptions

/**
 * get the array of other <system> options
 */
OtherOption** OSOption::getOtherSystemOptions()
{	if (this->system != NULL) 
	{	if (this->system->otherOptions != NULL)
			return this->system->otherOptions->other;
	}
	return NULL;
}//getOtherSystemOptions

/**
 * get the array of other <service> options
 */
OtherOption** OSOption::getOtherServiceOptions()
{	if (this->service != NULL) 
	{	if (this->service->otherOptions != NULL)
			return this->service->otherOptions->other;
	}
	return NULL;
}//getOtherServiceOptions

/**
 * get the array of other <job> options
 */
OtherOption** OSOption::getOtherJobOptions()
{	if (this->job != NULL) 
	{	if (this->job->otherOptions != NULL)
			return this->job->otherOptions->other;
	}
	return NULL;
}//getOtherJobOptions

/**
 * get the array of other options associated with a category
 * @param category - The name of the option category
 * @return other options associated with the element <"category">
 * @note This function returns NULL if category is not found
 */
OtherOption** OSOption::getOtherOptions(std::string category)
{	if (category == "general")
		return this->getOtherGeneralOptions();

	if (category == "system")
		return this->getOtherSystemOptions();

	if (category == "service")
		return this->getOtherServiceOptions();

	if (category == "job")
		return this->getOtherJobOptions();
	
	return NULL;
}//getOtherOptions

/**
 * get the array of other options associated with all children of <osol>
 */
OtherOption** OSOption::getAllOtherOptions()
{	OtherOption** optionVector = NULL;
	int prev_options[4];
	int num_options[4];
	int num_opt;
	int i;

	for (i = 0; i < 4; i++)
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

	if (num_options[0] > 0)
	{	
		for (i = 0; i < num_options[0]; i++)
		{	optionVector[prev_options[0] + i] = this->general->otherOptions->other[i];
		}
	}

	if (num_options[1] > 0)
	{	for (i = 0; i < num_options[1]; i++)
		{	optionVector[prev_options[1] + i] = this->system->otherOptions->other[i];
		}
	}

	if (num_options[2] > 0)
	{	for (i = 0; i < num_options[2]; i++)
		{	optionVector[prev_options[2] + i] = this->service->otherOptions->other[i];
		}
	}

	if (num_options[3] > 0)
	{	for (i = 0; i < num_options[3]; i++)
		{	optionVector[prev_options[3] + i] = this->job->otherOptions->other[i];
		}
	}

	return optionVector;
}//getOtherJobOptions

/**
 * get the array of job dependencies
 */
std::string*  OSOption::getJobDependencies()
{	std::string* dependenciesVector = NULL;
	if (this->job != NULL) 
	{	if (this->job->dependencies != NULL) 
			dependenciesVector = this->job->dependencies->jobID;				
		else
			throw ErrorClass("<dependencies> object must be defined before getting the jobIDs");
	}
	else
		throw ErrorClass("<job> object must be defined before getting the jobIDs");

	return dependenciesVector;
}//getJobDependencies

/**
 * get the list of required directories
 */
std::string*  OSOption::getRequiredDirectories()
{	std::string* pathVector = NULL;
	if (this->job != NULL) 
	{	if (this->job->requiredDirectories != NULL) 
			pathVector = this->job->requiredDirectories->path;				
		else
			throw ErrorClass("<requiredDirectories> object must be defined before getting the paths");
	}
	else
		throw ErrorClass("<job> object must be defined before getting the paths");
	return pathVector;
}//getRequiredDirectories

/**
 * get the list of required files
 */
std::string*  OSOption::getRequiredFiles()
{	std::string* pathVector = NULL;
	if (this->job != NULL) 
	{	if (this->job->requiredFiles != NULL) 
			pathVector = this->job->requiredFiles->path;				
		else
			throw ErrorClass("<requiredFiles> object must be defined before getting the paths");
	}
	else
		throw ErrorClass("<job> object must be defined before getting the paths");
	return pathVector;
}//getRequiredFiles

/**
 * get the list of directories that need to be created
 */
std::string*  OSOption::getDirectoriesToMake()
{	std::string* pathVector = NULL;
	if (this->job != NULL) 
	{	if (this->job->directoriesToMake != NULL) 
			pathVector = this->job->directoriesToMake->path;				
		else
			throw ErrorClass("<directoriesToMake> object must be defined before getting the paths");
	}
	else
		throw ErrorClass("<job> object must be defined before getting the paths");
	return pathVector;
}//getDirectoriesToMake

/**
 * get the list of files that need to be created
 */
std::string*  OSOption::getFilesToMake()
{	std::string* pathVector = NULL;
	if (this->job != NULL) 
	{	if (this->job->filesToMake != NULL) 
			pathVector = this->job->filesToMake->path;				
		else
			throw ErrorClass("<filesToMake> object must be defined before getting the paths");
	}
	else
		throw ErrorClass("<job> object must be defined before getting the paths");
	return pathVector;
}//getFilesToMake

/**
 * get the list of input directories that need to be moved or copied
 */
PathPair** OSOption::getInputDirectoriesToMove()
{	PathPair** pathPairVector = NULL;
	if (this->job != NULL) 
	{	if (this->job->inputDirectoriesToMove != NULL) 
			pathPairVector = this->job->inputDirectoriesToMove->pathPair;				
		else
			throw ErrorClass("<inputDirectoriesToMove> object must be defined before getting the paths");
	}
	else
		throw ErrorClass("<job> object must be defined before getting the paths");
	return pathPairVector;
}//getInputDirectoriesToMove

/**
 * get the list of input files that need to be moved or copied
 */
PathPair** OSOption::getInputFilesToMove()
{	PathPair** pathPairVector = NULL;
	if (this->job != NULL) 
	{	if (this->job->inputFilesToMove != NULL) 
			pathPairVector = this->job->inputFilesToMove->pathPair;				
		else
			throw ErrorClass("<inputFilesToMove> object must be defined before getting the paths");
	}
	else
		throw ErrorClass("<job> object must be defined before getting the paths");
	return pathPairVector;
}//getInputFilesToMove

/**
 * get the list of output files that need to be moved or copied
 */
PathPair** OSOption::getOutputFilesToMove()
{	PathPair** pathPairVector = NULL;
	if (this->job != NULL) 
	{	if (this->job->outputFilesToMove != NULL) 
			pathPairVector = this->job->outputFilesToMove->pathPair;				
		else
			throw ErrorClass("<outputFilesToMove> object must be defined before getting the paths");
	}
	else
		throw ErrorClass("<job> object must be defined before getting the paths");
	return pathPairVector;
}//getOutputFilesToMove

/**
 * get the list of output directories that need to be moved or copied
 */
PathPair** OSOption::getOutputDirectoriesToMove()
{	PathPair** pathPairVector = NULL;
	if (this->job != NULL) 
	{	if (this->job->outputDirectoriesToMove != NULL) 
			pathPairVector = this->job->outputDirectoriesToMove->pathPair;				
		else
			throw ErrorClass("<outputDirectoriesToMove> object must be defined before getting the paths");
	}
	else
		throw ErrorClass("<job> object must be defined before getting the paths");
	return pathPairVector;
}//getOutputDirectoriesToMove

/**
 * get the list of files that need to be deleted
 */
std::string*  OSOption::getFilesToDelete()
{	std::string* pathVector = NULL;
	if (this->job != NULL) 
	{	if (this->job->filesToDelete != NULL) 
			pathVector = this->job->filesToDelete->path;				
		else
			throw ErrorClass("<filesToDelete> object must be defined before getting the paths");
	}
	else
		throw ErrorClass("<job> object must be defined before getting the paths");
	return pathVector;
}//getFilesToDelete

/**
 * get the list of directories that need to be deleted
 */
std::string*  OSOption::getDirectoriesToDelete()
{	std::string* pathVector = NULL;
	if (this->job != NULL) 
	{	if (this->job->directoriesToDelete != NULL) 
			pathVector = this->job->directoriesToDelete->path;				
		else
			throw ErrorClass("<directoriesToDelete> object must be defined before getting the paths");
	}
	else
		throw ErrorClass("<job> object must be defined before getting the paths");
	return pathVector;
}//getDirectoriesToDelete

/**
 * get the list of processes that need to be killed
 */
std::string*  OSOption::getProcessesToKill()
{	std::string* processes = NULL;
	if (this->job != NULL) 
	{	if (this->job->processesToKill != NULL) 
			processes = this->job->processesToKill->process;
		else
			throw ErrorClass("<processesToKill> object must be defined before getting the processes");
	}
	else
		throw ErrorClass("<job> object must be defined before getting the processes");
	return processes;
}//getProcessesToKill



/**
 * get the list of initial variable values in sparse form
 * @return a list of index/value pairs
 */
InitVarValue**  OSOption::getInitVarValuesSparse()
{	InitVarValue**  initVarVector;
	if (this->optimization != NULL) 
	{	if (this->optimization->variables != NULL) 
		{	if (this->optimization->variables->initialVariableValues != NULL) 
				initVarVector = this->optimization->variables->initialVariableValues->var;
			else
				throw ErrorClass("<initialVariableValues> object must be defined before getting the data");
		}
		else
			throw ErrorClass("<variables> object must be defined before getting the data");
	}
	else
		throw ErrorClass("<optimization> object must be defined before getting the data");
	return initVarVector;
}//getInitVarValuesSparse

/**
 * get the list of initial variable values in dense form
 * @return an array of values
 * @note return OSNAN for variables that are not initialed
 */
double* OSOption::getInitVarValuesDense()
{	try
	{	int numberOfVariables;
		numberOfVariables = this->getNumberOfVariables();
		if (numberOfVariables < 0)
			throw ErrorClass("\"numberOfVariables\" must be present to use dense methods");		

		if (this->optimization != NULL) 
		{	if (this->optimization->variables != NULL) 
			{	if (this->optimization->variables->initialVariableValues != NULL) 
				{	int i,j,k;
					int num_var;
					num_var = this->getNumberOfInitVarValues();

					if (m_mdInitVarValuesDense != NULL)
						delete [] m_mdInitVarValuesDense;
					m_mdInitVarValuesDense = new double[numberOfVariables];
					for (k = 0; k < numberOfVariables; k++) m_mdInitVarValuesDense[k] = OSNAN;

					for (i = 0; i < num_var; i++)
					{	j = this->optimization->variables->initialVariableValues->var[i]->idx;
						if (j >= 0 && j < numberOfVariables)						
							m_mdInitVarValuesDense[j] 
							  = this->optimization->variables->initialVariableValues->var[i]->value;						
						else
							throw ErrorClass("Variable index out of range");
					}
					return m_mdInitVarValuesDense;
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return NULL;
}//getInitVarValuesDense

/**
 * get the list of initial variable values in dense form
 * @param numberOfVariables is the dimension of the array
 * @return an array of values
 * @note return OSNAN for variables that are not initialed
 */
double* OSOption::getInitVarValuesDense(int numberOfVariables)
{	try
	{	if (numberOfVariables < 0)
			throw ErrorClass("\"numberOfVariables\" must be present to use dense methods");		

		if (this->optimization != NULL) 
		{	if (this->optimization->variables != NULL) 
			{	if (this->optimization->variables->initialVariableValues != NULL) 
				{	int i,j,k;
					int num_var;
					num_var = this->getNumberOfInitVarValues();

					if (m_mdInitVarValuesDense != NULL)
						delete [] m_mdInitVarValuesDense;
					m_mdInitVarValuesDense = new double[numberOfVariables];
					for (k = 0; k < numberOfVariables; k++) m_mdInitVarValuesDense[k] = OSNAN;

					for (i = 0; i < num_var; i++)
					{	j = this->optimization->variables->initialVariableValues->var[i]->idx;
						if (j >= 0 && j < numberOfVariables)						
							m_mdInitVarValuesDense[j] 
							  = this->optimization->variables->initialVariableValues->var[i]->value;						
						else
							throw ErrorClass("Variable index out of range");
					}
					return m_mdInitVarValuesDense;
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return NULL;
}//getInitVarValuesDense

/**
 * get the list of initial values for string-valued variables in sparse form
 * @return a list of index/value pairs
 */
InitVarValueString**  OSOption::getInitVarValuesStringSparse()
{	InitVarValueString** initVarVector;
	if (this->optimization != NULL) 
	{	if (this->optimization->variables != NULL) 
		{	if (this->optimization->variables->initialVariableValuesString != NULL) 
				initVarVector = this->optimization->variables->initialVariableValuesString->var;
			else
				throw ErrorClass("<initialVariableValuesString> object must be defined before getting the data");
		}
		else
			throw ErrorClass("<variables> object must be defined before getting the data");
	}
	else
		throw ErrorClass("<optimization> object must be defined before getting the data");
	return initVarVector;
}//getInitVarValuesStringSparse

/**
 * get the list of initial values for string-valued variables in dense form
 * @return an array of value strings
 * @note return the empty string "" for variables that are not initialed
 */
std::string *OSOption::getInitVarValuesStringDense()
{	try
	{	int numberOfVariables;
		numberOfVariables = this->getNumberOfVariables();
		if (numberOfVariables < 0)
			throw ErrorClass("\"numberOfVariables\" must be present to use dense methods");		

		if (this->optimization != NULL) 
		{	if (this->optimization->variables != NULL) 
			{	if (this->optimization->variables->initialVariableValuesString != NULL) 
				{	int i,j,k;
					int num_var;
					num_var = this->getNumberOfInitVarValuesString();

					if (m_mdInitVarValuesStringDense != NULL)
						delete [] m_mdInitVarValuesStringDense;
					m_mdInitVarValuesStringDense = new std::string[numberOfVariables];
					for (k = 0; k < numberOfVariables; k++) m_mdInitVarValuesStringDense[k] = "";
		
					for (i = 0; i < num_var; i++)
					{	j = this->optimization->variables->initialVariableValuesString->var[i]->idx;
						if (j >= 0 && j < numberOfVariables)
							m_mdInitVarValuesStringDense[j] 
							  = this->optimization->variables->initialVariableValuesString->var[i]->value;
						else
							throw ErrorClass("Variable index out of range");
					}
					return m_mdInitVarValuesStringDense;
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return NULL;
}//getInitVarValuesStringDense

/**
 * get the list of initial values for string-valued variables in dense form
 * @param numberOfVariables is the dimension of the array
 * @return an array of value strings
 * @note return the empty string "" for variables that are not initialed
std::string *OSOption::getInitVarValuesStringDense(int numberOfVariables)
{	try
	{	if (numberOfVariables < 0)
			throw ErrorClass("\"numberOfVariables\" must be present to use dense methods");		

		if (this->optimization != NULL) 
		{	if (this->optimization->variables != NULL) 
			{	if (this->optimization->variables->initialVariableValuesString != NULL) 
				{	int i,j,k;
					int num_var;
					num_var = this->getNumberOfInitVarValuesString();

					if (m_mdInitVarValuesStringDense != NULL)
						delete [] m_mdInitVarValuesStringDense;
					m_mdInitVarValuesStringDense = new std::string[numberOfVariables];
					for (k = 0; k < numberOfVariables; k++) m_mdInitVarValuesStringDense[k] = "";
		
					for (i = 0; i < num_var; i++)
					{	j = this->optimization->variables->initialVariableValuesString->var[i]->idx;
						if (j >= 0 && j < numberOfVariables)
							m_mdInitVarValuesStringDense[j] 
							  = this->optimization->variables->initialVariableValuesString->var[i]->value;
						else
							throw ErrorClass("Variable index out of range");
					}
					return m_mdInitVarValuesStringDense;
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return NULL;
}//getInitVarValuesStringDense
 */


/**
 * get the basis status for all variables in dense form
 * @return an array of int, with values corresponding to ENUM_BASIS_STATUS -- see OSGeneral.g
 * @note returns ENUM_BASIS_STATUS_unknown for variables that are not initialed
 * @param numberOfVariables is the dimension of the array
 */
int* OSOption::getVariableInitialBasisStatusDense(int numberOfVariables)
{	try
	{	if (numberOfVariables < 0)
			throw ErrorClass("\"numberOfVariables\" must be set to use dense methods");		

		if (this->optimization == NULL) 
			throw ErrorClass("<optimization> element was never set");		

		if (this->optimization->variables == NULL) 
			throw ErrorClass("<optimization> <variables> element was never set");		

		if (this->optimization->variables->initialBasisStatus == NULL) 
			throw ErrorClass("initial basis was never set");

		int i,j,k;

		if (m_mdInitBasisStatusDense != NULL)
			delete [] m_mdInitBasisStatusDense;
		m_mdInitBasisStatusDense = new int[numberOfVariables];
		for (k = 0; k < numberOfVariables; k++) m_mdInitBasisStatusDense[k] = ENUM_BASIS_STATUS_unknown;
		
		int num_var;

		if (this->optimization->variables->initialBasisStatus->basic != NULL)
		{
			num_var = this->optimization->variables->initialBasisStatus->basic->numberOfEl;
			for (i = 0; i < num_var; i++)
			{	j = this->optimization->variables->initialBasisStatus->basic->el[i];
				if (j >= 0 && j < numberOfVariables)
					m_mdInitBasisStatusDense[j] = ENUM_BASIS_STATUS_basic;
				else
					throw ErrorClass("Variable index out of range");
			}
		}

		if (this->optimization->variables->initialBasisStatus->atLower != NULL)
		{
			num_var = this->optimization->variables->initialBasisStatus->atLower->numberOfEl;
			for (i = 0; i < num_var; i++)
			{	j = this->optimization->variables->initialBasisStatus->atLower->el[i];
				if (j >= 0 && j < numberOfVariables)
					m_mdInitBasisStatusDense[j] = ENUM_BASIS_STATUS_atLower;
				else
					throw ErrorClass("Variable index out of range");
			}
		}

		if (this->optimization->variables->initialBasisStatus->atUpper != NULL)
		{
			num_var = this->optimization->variables->initialBasisStatus->atUpper->numberOfEl;
			for (i = 0; i < num_var; i++)
			{	j = this->optimization->variables->initialBasisStatus->atUpper->el[i];
				if (j >= 0 && j < numberOfVariables)
					m_mdInitBasisStatusDense[j] = ENUM_BASIS_STATUS_atUpper;
				else
					throw ErrorClass("Variable index out of range");
			}
		}

		if (this->optimization->variables->initialBasisStatus->isFree != NULL)
		{
			num_var = this->optimization->variables->initialBasisStatus->isFree->numberOfEl;
			for (i = 0; i < num_var; i++)
			{	j = this->optimization->variables->initialBasisStatus->isFree->el[i];
				if (j >= 0 && j < numberOfVariables)
					m_mdInitBasisStatusDense[j] = ENUM_BASIS_STATUS_isFree;
				else
					throw ErrorClass("Variable index out of range");
			}
		}

		if (this->optimization->variables->initialBasisStatus->superbasic != NULL)
		{
			num_var = this->optimization->variables->initialBasisStatus->superbasic->numberOfEl;
			for (i = 0; i < num_var; i++)
			{	j = this->optimization->variables->initialBasisStatus->superbasic->el[i];
				if (j >= 0 && j < numberOfVariables)
					m_mdInitBasisStatusDense[j] = ENUM_BASIS_STATUS_superbasic;
				else
					throw ErrorClass("Variable index out of range");
			}
		}

		return m_mdInitBasisStatusDense;
	}

	catch(const ErrorClass& eclass)
	{
		throw ErrorClass(eclass.errormsg);
	}
	return NULL;
}//getVariableInitialBasisStatusDense


int OSOption::getNumberOfInitialBasisElements(int type, int status)
{
	if (this->optimization == NULL) 
			throw ErrorClass("<optimization> element was never set");		

	switch (type)
	{
		case ENUM_PROBLEM_COMPONENT_variables:
		{
			if (this->optimization->variables == NULL) 
				throw ErrorClass("<optimization> <variables> element was never set");		

			if (this->optimization->variables->initialBasisStatus == NULL) 
				throw ErrorClass("initial basis was never set");

			return this->optimization->variables->initialBasisStatus->getNumberOfEl(status);
		}
		case ENUM_PROBLEM_COMPONENT_objectives:
		{
			if (this->optimization->objectives == NULL) 
				throw ErrorClass("<optimization> <objectives> element was never set");		

			if (this->optimization->objectives->initialBasisStatus == NULL) 
				throw ErrorClass("initial basis was never set");

			return this->optimization->objectives->initialBasisStatus->getNumberOfEl(status);
		}
		case ENUM_PROBLEM_COMPONENT_constraints:
		{
			if (this->optimization->constraints == NULL) 
				throw ErrorClass("<optimization> <constraints> element was never set");		

			if (this->optimization->constraints->initialBasisStatus == NULL) 
				throw ErrorClass("initial basis was never set");

			return this->optimization->constraints->initialBasisStatus->getNumberOfEl(status);
		}
		default:
			throw ErrorClass("target object not implemented in setPathPairs");
	}
}//getNumberOfInitialBasisElements

bool OSOption::getInitialBasisElements(int type, int status, int* elem)
{
	if (this->optimization == NULL) 
			throw ErrorClass("<optimization> element was never set");		

	switch (type)
	{
		case ENUM_PROBLEM_COMPONENT_variables:
		{
			if (this->optimization->variables == NULL) 
				throw ErrorClass("<optimization> <variables> element was never set");		

			if (this->optimization->variables->initialBasisStatus == NULL) 
				throw ErrorClass("initial basis was never set");

			return this->optimization->variables->initialBasisStatus->getIntVector(status, elem);
		}
		case ENUM_PROBLEM_COMPONENT_objectives:
		{
			if (this->optimization->objectives == NULL) 
				throw ErrorClass("<optimization> <objectives> element was never set");		

			if (this->optimization->objectives->initialBasisStatus == NULL) 
				throw ErrorClass("initial basis was never set");

			return this->optimization->objectives->initialBasisStatus->getIntVector(status, elem);
		}
		case ENUM_PROBLEM_COMPONENT_constraints:
		{
			if (this->optimization->constraints == NULL) 
				throw ErrorClass("<optimization> <constraints> element was never set");		

			if (this->optimization->constraints->initialBasisStatus == NULL) 
				throw ErrorClass("initial basis was never set");

			return this->optimization->constraints->initialBasisStatus->getIntVector(status, elem);
		}
		default:
			throw ErrorClass("target object not implemented in setPathPairs");
	}
}//getInitialBasisElements

			
			

/**
 * get a list of branching weights for integer variables in sparse form
 * @return a list of index/value pairs
 */
BranchingWeight**  OSOption::getIntegerVariableBranchingWeightsSparse()
{	BranchingWeight** intVarVector;
	if (this->optimization != NULL) 
	{	if (this->optimization->variables != NULL) 
		{	if (this->optimization->variables->integerVariableBranchingWeights != NULL)
				intVarVector = this->optimization->variables->integerVariableBranchingWeights->var;
			else
				throw ErrorClass("<integerVariableBranchingWeights> object must be defined before getting the data");
		}
		else
			throw ErrorClass("<variables> object must be defined before getting the data");
	}
	else
		throw ErrorClass("<optimization> object must be defined before getting the data");
	return intVarVector;
}//getIntegerVariableBranchingWeightsSparse


/**
 * get a list of branching weights for integer variables in dense form
 * @return an array of values
 * @note return OSNAN for variables that are not initialed
 */
double* OSOption::getIntegerVariableBranchingWeightsDense()
{	try
	{	int numberOfVariables;
		numberOfVariables = this->getNumberOfVariables();
		if (numberOfVariables < 0)
			throw ErrorClass("\"numberOfVariables\" must be present to use dense methods");		

		if (this->optimization != NULL) 
		{	if (this->optimization->variables != NULL) 
			{	if (this->optimization->variables->integerVariableBranchingWeights != NULL) 
				{	int i,j,k;
					int num_var;
					num_var = this->getNumberOfIntegerVariableBranchingWeights();

					if (m_mdIntegerVariableBranchingWeightsDense != NULL)
						delete [] m_mdIntegerVariableBranchingWeightsDense;
					m_mdIntegerVariableBranchingWeightsDense = new double[numberOfVariables];
					for (k = 0; k < numberOfVariables; k++) m_mdIntegerVariableBranchingWeightsDense[k] = OSNAN;

					for (i = 0; i < num_var; i++)
					{	j = this->optimization->variables->integerVariableBranchingWeights->var[i]->idx;
						if (j >= 0 && j < numberOfVariables)						
							m_mdIntegerVariableBranchingWeightsDense[j] 
							  = this->optimization->variables->integerVariableBranchingWeights->var[i]->value;						
						else
							throw ErrorClass("Variable index out of range");
					}
					return m_mdIntegerVariableBranchingWeightsDense;
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return NULL;
}//getIntegerVariableBranchingWeightsDense

/**
 * get a list of branching weights for integer variables in dense form
 * @param numberOfVariables is the dimension of the array
 * @return an array of values
 * @note return OSNAN for variables that are not initialed
 */
double* OSOption::getIntegerVariableBranchingWeightsDense(int numberOfVariables)
{	try
	{	if (numberOfVariables < 0)
			throw ErrorClass("\"numberOfVariables\" must be present to use dense methods");		

		if (this->optimization != NULL) 
		{	if (this->optimization->variables != NULL) 
			{	if (this->optimization->variables->integerVariableBranchingWeights != NULL) 
				{	int i,j,k;
					int num_var;
					num_var = this->getNumberOfIntegerVariableBranchingWeights();

					if (m_mdIntegerVariableBranchingWeightsDense != NULL)
						delete [] m_mdIntegerVariableBranchingWeightsDense;
					m_mdIntegerVariableBranchingWeightsDense = new double[numberOfVariables];
					for (k = 0; k < numberOfVariables; k++) m_mdIntegerVariableBranchingWeightsDense[k] = OSNAN;

					for (i = 0; i < num_var; i++)
					{	j = this->optimization->variables->integerVariableBranchingWeights->var[i]->idx;
						if (j >= 0 && j < numberOfVariables)						
							m_mdIntegerVariableBranchingWeightsDense[j] 
							  = this->optimization->variables->integerVariableBranchingWeights->var[i]->value;						
						else
							throw ErrorClass("Variable index out of range");
					}
					return m_mdIntegerVariableBranchingWeightsDense;
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return NULL;
}//getIntegerVariableBranchingWeightsDense

/**
 * get a list of branching weights for SOS variables in sparse form
 * @return a list of SOSWeights objects
 */
SOSWeights**  OSOption::getSOSVariableBranchingWeightsSparse()
{	SOSWeights** sosVarVector;
	if (this->optimization != NULL) 
	{	if (this->optimization->variables != NULL) 
		{	if (this->optimization->variables->sosVariableBranchingWeights != NULL)
				sosVarVector = this->optimization->variables->sosVariableBranchingWeights->sos;
			else
				throw ErrorClass("<sosVariableBranchingWeights> object must be defined before getting the data");
		}
		else
			throw ErrorClass("<variables> object must be defined before getting the data");
	}
	else
		throw ErrorClass("<optimization> object must be defined before getting the data");
	return sosVarVector;
}//getSOSVariableBranchingWeightsSparse


/**
 * get the array of other variable options associated with a particular solver
 * @param solver_name is the name of the solver
 * @return an array of other variable options associated with this solver
 */
std::vector<OtherVariableOption*>  OSOption::getOtherVariableOptions( std::string solver_name)
{	std::vector<OtherVariableOption*> optionsVector;
	if (this->optimization != NULL) 
	{	if (this->optimization->variables != NULL) 
		{	int i;
			int num_options;
			num_options = this->getNumberOfOtherVariableOptions();
			for(i = 0; i < num_options; i++)
				if (solver_name == this->optimization->variables->other[ i]->solver)
					optionsVector.push_back( this->optimization->variables->other[ i]);
		}					
		else
			throw ErrorClass("<variables> object must be defined before getting the data");
	}
	else
		throw ErrorClass("<optimization> object must be defined before getting the data");
	return optionsVector;
}//getOtherVariableOptions


/**
 * get the array of all other variable options
 * @return an array of other variable options associated with this solver
 */
OtherVariableOption** OSOption::getAllOtherVariableOptions()
{	OtherVariableOption** optionsVector;
	if (this->optimization != NULL) 
	{	if (this->optimization->variables != NULL) 
			optionsVector = this->optimization->variables->other;
		else
			throw ErrorClass("<variables> object must be defined before getting the data");
	}
	else
		throw ErrorClass("<optimization> object must be defined before getting the data");
	return optionsVector;
}//getAllOtherVariableOptions

/**
 * get the list of initial objective values in sparse form
 * @return a list of index/value pairs
 */
InitObjValue**  OSOption::getInitObjValuesSparse()
{	InitObjValue** initObjVector;
	if (this->optimization != NULL) 
	{	if (this->optimization->objectives != NULL) 
		{	if (this->optimization->objectives->initialObjectiveValues != NULL) 
				initObjVector = this->optimization->objectives->initialObjectiveValues->obj;			
			else
				throw ErrorClass("<initialObjectiveValues> object must be defined before getting the data");
		}
		else
			throw ErrorClass("<objectives> object must be defined before getting the data");
	}
	else
		throw ErrorClass("<optimization> object must be defined before getting the data");
	return initObjVector;
}//getInitObjValuesSparse

/**
 * get the list of initial objective values in dense form
 * @return an array of values
 * @note return OSNAN for objectives that are not initialed
 */
double* OSOption::getInitObjValuesDense()
{	try
	{	int numberOfObjectives;
		numberOfObjectives = this->getNumberOfObjectives();
		if (numberOfObjectives < 0)
			throw ErrorClass("\"numberOfObjectives\" must be present to use dense methods");		

		if (this->optimization != NULL) 
		{	if (this->optimization->objectives != NULL) 
			{	if (this->optimization->objectives->initialObjectiveValues != NULL) 
				{	int i,j,k;
					int num_obj;
					num_obj = this->getNumberOfInitObjValues();

					if (m_mdInitObjValuesDense != NULL)
						delete [] m_mdInitObjValuesDense;
					m_mdInitObjValuesDense = new double[numberOfObjectives];
					for (k = 0; k < numberOfObjectives; k++) m_mdInitObjValuesDense[k] = OSNAN;
	
					for (i = 0; i < num_obj; i++)
					{	j = this->optimization->objectives->initialObjectiveValues->obj[i]->idx;
						if (j < 0 && -j <= numberOfObjectives)						
							m_mdInitObjValuesDense[-1-j] 
							  = this->optimization->objectives->initialObjectiveValues->obj[i]->value;						
						else
						{
							throw ErrorClass("Objective index out of range");
						}
					}
					return m_mdInitObjValuesDense;
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return NULL;
}//getInitObjValuesDense

/**
 * get the list of initial objective values in dense form
 * @param numberOfObjectives is the dimension of the array
 * @return an array of values
 * @note return OSNAN for objectives that are not initialed
 */
double* OSOption::getInitObjValuesDense(int numberOfObjectives)
{	try
	{	if (numberOfObjectives < 0)
			throw ErrorClass("\"numberOfObjectives\" must be present to use dense methods");		

		if (this->optimization != NULL) 
		{	if (this->optimization->objectives != NULL) 
			{	if (this->optimization->objectives->initialObjectiveValues != NULL) 
				{	int i,j,k;
					int num_obj;
					num_obj = this->getNumberOfInitObjValues();

					if (m_mdInitObjValuesDense != NULL)
						delete [] m_mdInitObjValuesDense;
					m_mdInitObjValuesDense = new double[numberOfObjectives];
					for (k = 0; k < numberOfObjectives; k++) m_mdInitObjValuesDense[k] = OSNAN;
	
					for (i = 0; i < num_obj; i++)
					{	j = this->optimization->objectives->initialObjectiveValues->obj[i]->idx;
						if (j < 0 && -j <= numberOfObjectives)						
							m_mdInitObjValuesDense[-1-j] 
							  = this->optimization->objectives->initialObjectiveValues->obj[i]->value;						
						else
						{
							throw ErrorClass("Objective index out of range");
						}
					}
					return m_mdInitObjValuesDense;
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return NULL;
}//getInitObjValuesDense

/**
 * get the list of initial objective bounds in sparse form
 * @return a list of index/value/value triples
 */
InitObjBound**  OSOption::getInitObjBoundsSparse()
{	InitObjBound** initObjBounds;
	if (this->optimization != NULL) 
	{	if (this->optimization->objectives != NULL) 
		{	if (this->optimization->objectives->initialObjectiveBounds != NULL) 
				initObjBounds = this->optimization->objectives->initialObjectiveBounds->obj;
			else
				throw ErrorClass("<initialObjectiveBounds> object must be defined before getting the data");
		}
		else
			throw ErrorClass("<objectives> object must be defined before getting the data");
	}
	else
		throw ErrorClass("<optimization> object must be defined before getting the data");
	return initObjBounds;
}//getInitObjBoundsSparse

/**
 * get the list of initial objective lower bounds in dense form
 * @return an array of values
 * @note return OSNAN for objectives that are not initialed
 */
double* OSOption::getInitObjLowerBoundsDense()
{	try
	{	int numberOfObjectives;
		numberOfObjectives = this->getNumberOfObjectives();
		if (numberOfObjectives < 0)
			throw ErrorClass("\"numberOfObjectives\" must be present to use dense methods");		

		if (this->optimization != NULL) 
		{	if (this->optimization->objectives != NULL) 
			{	if (this->optimization->objectives->initialObjectiveBounds != NULL) 
				{	int i,j,k;
					int num_obj;
					num_obj = this->getNumberOfInitObjBounds();

					if (m_mdInitObjLowerBoundsDense != NULL)
						delete [] m_mdInitObjLowerBoundsDense;
					m_mdInitObjLowerBoundsDense = new double[numberOfObjectives];
					for (k = 0; k < numberOfObjectives; k++) m_mdInitObjLowerBoundsDense[k] = OSNAN;

					for (i = 0; i < num_obj; i++)
					{	j = this->optimization->objectives->initialObjectiveBounds->obj[i]->idx;
						if (j < 0 && -j <= numberOfObjectives)						
							m_mdInitObjLowerBoundsDense[-1-j] 
							  = this->optimization->objectives->initialObjectiveBounds->obj[i]->lbValue;
						else
						{
							throw ErrorClass("Objective index out of range");
						}
					}
					return m_mdInitObjLowerBoundsDense;
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return NULL;
}//getInitObjLowerBoundsDense

/**
 * get the list of initial objective lower bounds in dense form
 * @param numberOfObjectives is the dimension of the array
 * @return an array of values
 * @note return OSNAN for objectives that are not initialed
 */
double* OSOption::getInitObjLowerBoundsDense(int numberOfObjectives)
{	try
	{	if (numberOfObjectives < 0)
			throw ErrorClass("\"numberOfObjectives\" must be present to use dense methods");		

		if (this->optimization != NULL) 
		{	if (this->optimization->objectives != NULL) 
			{	if (this->optimization->objectives->initialObjectiveBounds != NULL) 
				{	int i,j,k;
					int num_obj;
					num_obj = this->getNumberOfInitObjBounds();

					if (m_mdInitObjLowerBoundsDense != NULL)
						delete [] m_mdInitObjLowerBoundsDense;
					m_mdInitObjLowerBoundsDense = new double[numberOfObjectives];
					for (k = 0; k < numberOfObjectives; k++) m_mdInitObjLowerBoundsDense[k] = OSNAN;

					for (i = 0; i < num_obj; i++)
					{	j = this->optimization->objectives->initialObjectiveBounds->obj[i]->idx;
						if (j < 0 && -j <= numberOfObjectives)						
							m_mdInitObjLowerBoundsDense[-1-j] 
							  = this->optimization->objectives->initialObjectiveBounds->obj[i]->lbValue;
						else
						{
							throw ErrorClass("Objective index out of range");
						}
					}
					return m_mdInitObjLowerBoundsDense;
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return NULL;
}//getInitObjLowerBoundsDense

/**
 * get the list of initial objective upper bounds in dense form
 * @return an array of values
 * @note return OSNAN for objectives that are not initialed
 */
double* OSOption::getInitObjUpperBoundsDense()
{	try
	{	int numberOfObjectives;
		numberOfObjectives = this->getNumberOfObjectives();
		if (numberOfObjectives < 0)
			throw ErrorClass("\"numberOfObjectives\" must be present to use dense methods");		

		if (this->optimization != NULL) 
		{	if (this->optimization->objectives != NULL) 
			{	if (this->optimization->objectives->initialObjectiveBounds != NULL) 
				{	int i,j,k;
					int num_obj;
					num_obj = this->getNumberOfInitObjBounds();

					if (m_mdInitObjUpperBoundsDense != NULL)
						delete [] m_mdInitObjUpperBoundsDense;
					m_mdInitObjUpperBoundsDense = new double[numberOfObjectives];
					for (k = 0; k < numberOfObjectives; k++) m_mdInitObjUpperBoundsDense[k] = OSNAN;
					
					for (i = 0; i < num_obj; i++)
					{	j = this->optimization->objectives->initialObjectiveBounds->obj[i]->idx;
						if (j < 0 && -j <= numberOfObjectives)						
							m_mdInitObjUpperBoundsDense[-1-j] 
							  = this->optimization->objectives->initialObjectiveBounds->obj[i]->ubValue;
						else
						{
							throw ErrorClass("Objective index out of range");
						}
					}
					return m_mdInitObjUpperBoundsDense;
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return NULL;
}//getInitObjUpperBoundsDense

/**
 * get the list of initial objective upper bounds in dense form
 * @param numberOfObjectives is the dimension of the array
 * @return an array of values
 * @note return OSNAN for objectives that are not initialed
 */
double* OSOption::getInitObjUpperBoundsDense(int numberOfObjectives)
{	try
	{	if (numberOfObjectives < 0)
			throw ErrorClass("\"numberOfObjectives\" must be present to use dense methods");		

		if (this->optimization != NULL) 
		{	if (this->optimization->objectives != NULL) 
			{	if (this->optimization->objectives->initialObjectiveBounds != NULL) 
				{	int i,j,k;
					int num_obj;
					num_obj = this->getNumberOfInitObjBounds();

					if (m_mdInitObjUpperBoundsDense != NULL)
						delete [] m_mdInitObjUpperBoundsDense;
					m_mdInitObjUpperBoundsDense = new double[numberOfObjectives];
					for (k = 0; k < numberOfObjectives; k++) m_mdInitObjUpperBoundsDense[k] = OSNAN;
					
					for (i = 0; i < num_obj; i++)
					{	j = this->optimization->objectives->initialObjectiveBounds->obj[i]->idx;
						if (j < 0 && -j <= numberOfObjectives)						
							m_mdInitObjUpperBoundsDense[-1-j] 
							  = this->optimization->objectives->initialObjectiveBounds->obj[i]->ubValue;
						else
						{
							throw ErrorClass("Objective index out of range");
						}
					}
					return m_mdInitObjUpperBoundsDense;
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return NULL;
}//getInitObjUpperBoundsDense

/**
 * get the list of initial values for string-valued variables in dense form
 * @param numberOfVariables is the dimension of the array
 * @return an array of value strings
 * @note return the empty string "" for variables that are not initialed
 */
std::string *OSOption::getInitVarValuesStringDense(int numberOfVariables)
{	try
	{	if (numberOfVariables < 0)
			throw ErrorClass("\"numberOfVariables\" must be present to use dense methods");		

		if (this->optimization != NULL) 
		{	if (this->optimization->variables != NULL) 
			{	if (this->optimization->variables->initialVariableValuesString != NULL) 
				{	int i,j,k;
					int num_var;
					num_var = this->getNumberOfInitVarValuesString();

					if (m_mdInitVarValuesStringDense != NULL)
						delete [] m_mdInitVarValuesStringDense;
					m_mdInitVarValuesStringDense = new std::string[numberOfVariables];
					for (k = 0; k < numberOfVariables; k++) m_mdInitVarValuesStringDense[k] = "";
		
					for (i = 0; i < num_var; i++)
					{	j = this->optimization->variables->initialVariableValuesString->var[i]->idx;
						if (j >= 0 && j < numberOfVariables)
							m_mdInitVarValuesStringDense[j] 
							  = this->optimization->variables->initialVariableValuesString->var[i]->value;
						else
							throw ErrorClass("Variable index out of range");
					}
					return m_mdInitVarValuesStringDense;
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return NULL;
}//getInitVarValuesStringDense


/**
 * get the basis status for all objectives in dense form
 * @return an array of int, with values corresponding to ENUM_BASIS_STATUS -- see OSGeneral.g
 * @note returns ENUM_BASIS_STATUS_unknown for objectives that are not initialed
 * @param numberOfObjectives is the dimension of the array
 */
int* OSOption::getObjectiveInitialBasisStatusDense(int numberOfObjectives)
{	try
	{	if (numberOfObjectives < 0)
			throw ErrorClass("\"numberOfObjectives\" must be set to use dense methods");		

		if (this->optimization == NULL) 
			throw ErrorClass("<optimization> element was never set");		

		if (this->optimization->objectives == NULL) 
			throw ErrorClass("<optimization> <objectives> element was never set");		

		if (this->optimization->objectives->initialBasisStatus == NULL) 
			throw ErrorClass("initial basis was never set");

		int i,j,k;

		if (m_mdInitBasisStatusDense != NULL)
			delete [] m_mdInitBasisStatusDense;
		m_mdInitBasisStatusDense = new int[numberOfObjectives];
		for (k = 0; k < numberOfObjectives; k++) m_mdInitBasisStatusDense[k] = ENUM_BASIS_STATUS_unknown;
		
		int num_obj;

		if (this->optimization->objectives->initialBasisStatus->basic != NULL)
		{
			num_obj = this->optimization->objectives->initialBasisStatus->basic->numberOfEl;
			for (i = 0; i < num_obj; i++)
			{	j = this->optimization->objectives->initialBasisStatus->basic->el[i];
				if (j >= 0 || j < -numberOfObjectives)
					throw ErrorClass("Objective index out of range");
				else
					m_mdInitBasisStatusDense[j] = ENUM_BASIS_STATUS_basic;
			}
		}

		if (this->optimization->objectives->initialBasisStatus->atLower != NULL)
		{
			num_obj = this->optimization->objectives->initialBasisStatus->atLower->numberOfEl;
			for (i = 0; i < num_obj; i++)
			{	j = this->optimization->objectives->initialBasisStatus->atLower->el[i];
				if (j >= 0 || j < -numberOfObjectives)
					throw ErrorClass("Objective index out of range");
				else
					m_mdInitBasisStatusDense[j] = ENUM_BASIS_STATUS_atLower;
			}
		}

		if (this->optimization->objectives->initialBasisStatus->atUpper != NULL)
		{
			num_obj = this->optimization->objectives->initialBasisStatus->atUpper->numberOfEl;
			for (i = 0; i < num_obj; i++)
			{	j = this->optimization->objectives->initialBasisStatus->atUpper->el[i];
				if (j >= 0 || j < -numberOfObjectives)
					throw ErrorClass("Objective index out of range");
				else
					m_mdInitBasisStatusDense[j] = ENUM_BASIS_STATUS_atUpper;
			}
		}

		if (this->optimization->objectives->initialBasisStatus->isFree != NULL)
		{
			num_obj = this->optimization->objectives->initialBasisStatus->isFree->numberOfEl;
			for (i = 0; i < num_obj; i++)
			{	j = this->optimization->objectives->initialBasisStatus->isFree->el[i];
				if (j >= 0 || j < -numberOfObjectives)
					throw ErrorClass("Objective index out of range");
				else
					m_mdInitBasisStatusDense[j] = ENUM_BASIS_STATUS_isFree;
			}
		}

		if (this->optimization->objectives->initialBasisStatus->superbasic != NULL)
		{
			num_obj = this->optimization->objectives->initialBasisStatus->superbasic->numberOfEl;
			for (i = 0; i < num_obj; i++)
			{	j = this->optimization->objectives->initialBasisStatus->superbasic->el[i];
				if (j >= 0 || j < -numberOfObjectives)
					throw ErrorClass("Objective index out of range");
				else
					m_mdInitBasisStatusDense[j] = ENUM_BASIS_STATUS_superbasic;
			}
		}

		return m_mdInitBasisStatusDense;
	}

	catch(const ErrorClass& eclass)
	{
		throw ErrorClass(eclass.errormsg);
	}
	return NULL;
}//getVariableInitialBasisStatusDense




/**
 * get the array of other objective options associated with a particular solver
 * @param solver_name is the name of the solver
 * @return an array of other objective options associated with this solver
 */
std::vector<OtherObjectiveOption*>  OSOption::getOtherObjectiveOptions( std::string solver_name)
{	std::vector<OtherObjectiveOption*> optionsVector;
	if (this->optimization != NULL) 
	{	if (this->optimization->variables != NULL) 
		{	int i;
			int num_options;
			num_options = this->getNumberOfOtherObjectiveOptions();
			for(i = 0; i < num_options; i++)
				if (solver_name == this->optimization->objectives->other[ i]->solver)
					optionsVector.push_back( this->optimization->objectives->other[ i]);
		}					
		else
			throw ErrorClass("<objectives> object must be defined before getting the data");
	}
	else
		throw ErrorClass("<optimization> object must be defined before getting the data");
	return optionsVector;
}//getOtherObjectiveOptions

/**
 * get the array of all other objective options
 * @return an array of other objective options associated with this solver
 */
OtherObjectiveOption** OSOption::getAllOtherObjectiveOptions()
{	OtherObjectiveOption** optionsVector;
	if (this->optimization != NULL) 
	{	if (this->optimization->objectives != NULL) 
			optionsVector = this->optimization->objectives->other;
		else
			throw ErrorClass("<objectives> object must be defined before getting the data");
	}
	else
		throw ErrorClass("<optimization> object must be defined before getting the data");
	return optionsVector;
}//getAllOtherObjectiveOptions


/**
 * get the list of initial constraint values in sparse form
 * @return a list of index/value pairs
 */
InitConValue**  OSOption::getInitConValuesSparse()
{	InitConValue** initConVector;
	if (this->optimization != NULL) 
	{	if (this->optimization->constraints != NULL) 
		{	if (this->optimization->constraints->initialConstraintValues != NULL) 
				initConVector = this->optimization->constraints->initialConstraintValues->con;			
			else
				throw ErrorClass("<initialConstraintValues> object must be defined before getting the data");
		}
		else
			throw ErrorClass("<constraints> object must be defined before getting the data");
	}
	else
		throw ErrorClass("<optimization> object must be defined before getting the data");
	return initConVector;
}//getInitConValuesSparse

/**
 * get the list of initial constraint values in dense form
 * @return an array of values
 * @note return OSNAN for constraints that are not initialed
 */
double* OSOption::getInitConValuesDense()
{	try
	{	int numberOfConstraints;
		numberOfConstraints = this->getNumberOfConstraints();
		if (numberOfConstraints < 0)
			throw ErrorClass("\"numberOfConstraints\" must be present to use dense methods");		

		if (this->optimization != NULL) 
		{	if (this->optimization->constraints != NULL) 
			{	if (this->optimization->constraints->initialConstraintValues != NULL) 
				{	int i,j,k;
					int num_con;
					num_con = this->getNumberOfInitConValues();

					if (m_mdInitConValuesDense != NULL)
						delete [] m_mdInitConValuesDense;
					m_mdInitConValuesDense = new double[numberOfConstraints];
					for (k = 0; k < numberOfConstraints; k++) m_mdInitConValuesDense[k] = OSNAN;

					for (i = 0; i < num_con; i++)
					{	j = this->optimization->constraints->initialConstraintValues->con[i]->idx;
						if (j >= 0 && j < numberOfConstraints)						
							m_mdInitConValuesDense[j] 
							  = this->optimization->constraints->initialConstraintValues->con[i]->value;						
						else
							throw ErrorClass("Constraint index out of range");
					}
				return m_mdInitConValuesDense;
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return NULL;
}//getInitConValuesDense

/**
 * get the list of initial constraint values in dense form
 * @param numberOfConstraints is the dimension of the array
 * @return an array of values
 * @note return OSNAN for constraints that are not initialed
 */
double* OSOption::getInitConValuesDense(int numberOfConstraints)
{	try
	{	if (numberOfConstraints < 0)
			throw ErrorClass("\"numberOfConstraints\" must be present to use dense methods");		

		if (this->optimization != NULL) 
		{	if (this->optimization->constraints != NULL) 
			{	if (this->optimization->constraints->initialConstraintValues != NULL) 
				{	int i,j,k;
					int num_con;
					num_con = this->getNumberOfInitConValues();

					if (m_mdInitConValuesDense != NULL)
						delete [] m_mdInitConValuesDense;
					m_mdInitConValuesDense = new double[numberOfConstraints];
					for (k = 0; k < numberOfConstraints; k++) m_mdInitConValuesDense[k] = OSNAN;

					for (i = 0; i < num_con; i++)
					{	j = this->optimization->constraints->initialConstraintValues->con[i]->idx;
						if (j >= 0 && j < numberOfConstraints)						
							m_mdInitConValuesDense[j] 
							  = this->optimization->constraints->initialConstraintValues->con[i]->value;						
						else
							throw ErrorClass("Constraint index out of range");
					}
				return m_mdInitConValuesDense;
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return NULL;
}//getInitConValuesDense

/**
 * get the list of initial dual variables in sparse form
 * @return a list of index/value/value triples
 */
InitDualVarValue**  OSOption::getInitDualVarValuesSparse()
{	InitDualVarValue** initDualVector;
	if (this->optimization != NULL) 
	{	if (this->optimization->constraints != NULL) 
		{	if (this->optimization->constraints->initialDualValues != NULL) 
				initDualVector = this->optimization->constraints->initialDualValues->con;			
			else
				throw ErrorClass("<initialDualValues> object must be defined before getting the data");
		}
		else
			throw ErrorClass("<constraints> object must be defined before getting the data");
	}
	else
		throw ErrorClass("<optimization> object must be defined before getting the data");
	return initDualVector;
}//getInitDualVarValuesSparse

/**
 * get the list of initial dual variables associated with the lower bounds in dense form
 * @return an array of values
 * @note return OSNAN for dual variables that are not initialed
 */
double* OSOption::getInitDualVarLowerBoundsDense()
{	try
	{	int numberOfConstraints;
		numberOfConstraints = this->getNumberOfConstraints();
		if (numberOfConstraints < 0)
			throw ErrorClass("\"numberOfConstraints\" must be present to use dense methods");		

		if (this->optimization != NULL) 
		{	if (this->optimization->constraints != NULL) 
			{	if (this->optimization->constraints->initialDualValues != NULL) 
				{	int i,j,k;
					int num_con;
					num_con = this->getNumberOfInitDualVarValues();

					if (m_mdInitDualVarLowerBoundsDense != NULL)
						delete [] m_mdInitDualVarLowerBoundsDense;
					m_mdInitDualVarLowerBoundsDense = new double[numberOfConstraints];
					for (k = 0; k < numberOfConstraints; k++) m_mdInitDualVarLowerBoundsDense[k] = 0.0;

					for (i = 0; i < num_con; i++)
					{	j = this->optimization->constraints->initialDualValues->con[i]->idx;
						if (j >= 0 && j < numberOfConstraints)						
							m_mdInitDualVarLowerBoundsDense[j] 
							  = this->optimization->constraints->initialDualValues->con[i]->lbDualValue;						
						else
							throw ErrorClass("Constraint index out of range");
					}
					return m_mdInitDualVarLowerBoundsDense;
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return NULL;
}//getInitDualVarLowerBoundsDense

/**
 * get the list of initial dual variables associated with the lower bounds in dense form
 * @param numberOfConstraints is the dimension of the array
 * @return an array of values
 * @note return OSNAN for dual variables that are not initialed
 */
double* OSOption::getInitDualVarLowerBoundsDense(int numberOfConstraints)
{	try
	{	if (numberOfConstraints < 0)
			throw ErrorClass("\"numberOfConstraints\" must be present to use dense methods");		

		if (this->optimization != NULL) 
		{	if (this->optimization->constraints != NULL) 
			{	if (this->optimization->constraints->initialDualValues != NULL) 
				{	int i,j,k;
					int num_con;
					num_con = this->getNumberOfInitDualVarValues();

					if (m_mdInitDualVarLowerBoundsDense != NULL)
						delete [] m_mdInitDualVarLowerBoundsDense;
					m_mdInitDualVarLowerBoundsDense = new double[numberOfConstraints];
					for (k = 0; k < numberOfConstraints; k++) m_mdInitDualVarLowerBoundsDense[k] = 0.0;

					for (i = 0; i < num_con; i++)
					{	j = this->optimization->constraints->initialDualValues->con[i]->idx;
						if (j >= 0 && j < numberOfConstraints)						
							m_mdInitDualVarLowerBoundsDense[j] 
							  = this->optimization->constraints->initialDualValues->con[i]->lbDualValue;						
						else
							throw ErrorClass("Constraint index out of range");
					}
					return m_mdInitDualVarLowerBoundsDense;
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return NULL;
}//getInitDualVarLowerBoundsDense

/**
 * get the list of initial dual variables associated with the upper bounds in dense form
 * @return an array of values
 * @note return OSNAN for dual variables that are not initialed
 */
double* OSOption::getInitDualVarUpperBoundsDense()
{	try
	{	int numberOfConstraints;
		numberOfConstraints = this->getNumberOfConstraints();
		if (numberOfConstraints < 0)
			throw ErrorClass("\"numberOfConstraints\" must be present to use dense methods");		

		if (this->optimization != NULL) 
		{	if (this->optimization->constraints != NULL) 
			{	if (this->optimization->constraints->initialDualValues != NULL) 
				{	int i,j,k;
					int num_con;
					num_con = this->getNumberOfInitDualVarValues();
					numberOfConstraints = this->getNumberOfConstraints();

					if (m_mdInitDualVarUpperBoundsDense != NULL)
						delete [] m_mdInitDualVarUpperBoundsDense;
					m_mdInitDualVarUpperBoundsDense = new double[numberOfConstraints];
					for (k = 0; k < numberOfConstraints; k++) m_mdInitDualVarUpperBoundsDense[k] = 0.0;

					for (i = 0; i < num_con; i++)
					{	j = this->optimization->constraints->initialDualValues->con[i]->idx;
						if (j >= 0 && j < numberOfConstraints)						
							m_mdInitDualVarUpperBoundsDense[j] 
							  = this->optimization->constraints->initialDualValues->con[i]->ubDualValue;	
						else
							throw ErrorClass("Constraint index out of range");
					}
					return m_mdInitDualVarUpperBoundsDense;
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return NULL;
}//getInitDualVarUpperBoundsDense

/**
 * get the list of initial dual variables associated with the upper bounds in dense form
 * @param numberOfConstraints is the dimension of the array
 * @return an array of values
 * @note return OSNAN for dual variables that are not initialed
 */
double* OSOption::getInitDualVarUpperBoundsDense(int numberOfConstraints)
{	try
	{	if (numberOfConstraints < 0)
			throw ErrorClass("\"numberOfConstraints\" must be present to use dense methods");		

		if (this->optimization != NULL) 
		{	if (this->optimization->constraints != NULL) 
			{	if (this->optimization->constraints->initialDualValues != NULL) 
				{	int i,j,k;
					int num_con;
					num_con = this->getNumberOfInitDualVarValues();
					numberOfConstraints = this->getNumberOfConstraints();

					if (m_mdInitDualVarUpperBoundsDense != NULL)
						delete [] m_mdInitDualVarUpperBoundsDense;
					m_mdInitDualVarUpperBoundsDense = new double[numberOfConstraints];
					for (k = 0; k < numberOfConstraints; k++) m_mdInitDualVarUpperBoundsDense[k] = 0.0;

					for (i = 0; i < num_con; i++)
					{	j = this->optimization->constraints->initialDualValues->con[i]->idx;
						if (j >= 0 && j < numberOfConstraints)						
							m_mdInitDualVarUpperBoundsDense[j] 
							  = this->optimization->constraints->initialDualValues->con[i]->ubDualValue;	
						else
							throw ErrorClass("Constraint index out of range");
					}
					return m_mdInitDualVarUpperBoundsDense;
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return NULL;
}//getInitDualVarUpperBoundsDense


/**
 * get the basis status for all slack variables in dense form
 * @return an array of int, with values corresponding to ENUM_BASIS_STATUS -- see OSGeneral.g
 * @note returns ENUM_BASIS_STATUS_unknown for slackss that are not initialed
 * @param numberOfConstraints is the dimension of the array
 */
int* OSOption::getSlackVariableInitialBasisStatusDense(int numberOfConstraints)
{	try
	{	if (numberOfConstraints < 0)
			throw ErrorClass("\"numberOfConstraints\" must be set to use dense methods");		

		if (this->optimization == NULL) 
			throw ErrorClass("<optimization> element was never set");		

		if (this->optimization->constraints == NULL) 
			throw ErrorClass("<optimization> <constraints> element was never set");		

		if (this->optimization->constraints->initialBasisStatus == NULL) 
			throw ErrorClass("initial basis was never set");

		int i,j,k;

		if (m_mdInitBasisStatusDense != NULL)
			delete [] m_mdInitBasisStatusDense;
		m_mdInitBasisStatusDense = new int[numberOfConstraints];
		for (k = 0; k < numberOfConstraints; k++) m_mdInitBasisStatusDense[k] = ENUM_BASIS_STATUS_unknown;
		
		int num_slack;

		if (this->optimization->constraints->initialBasisStatus->basic != NULL)
		{
			num_slack = this->optimization->constraints->initialBasisStatus->basic->numberOfEl;
			for (i = 0; i < num_slack; i++)
			{	j = this->optimization->constraints->initialBasisStatus->basic->el[i];
				if (j >= 0 && j < numberOfConstraints)
					m_mdInitBasisStatusDense[j] = ENUM_BASIS_STATUS_basic;
				else
					throw ErrorClass("Constraint index out of range");
			}
		}

		if (this->optimization->constraints->initialBasisStatus->atLower != NULL)
		{
			num_slack = this->optimization->constraints->initialBasisStatus->atLower->numberOfEl;
			for (i = 0; i < num_slack; i++)
			{	j = this->optimization->constraints->initialBasisStatus->atLower->el[i];
				if (j >= 0 && j < numberOfConstraints)
					m_mdInitBasisStatusDense[j] = ENUM_BASIS_STATUS_atLower;
				else
					throw ErrorClass("Constraint index out of range");
			}
		}

		if (this->optimization->constraints->initialBasisStatus->atUpper != NULL)
		{
			num_slack = this->optimization->constraints->initialBasisStatus->atUpper->numberOfEl;
			for (i = 0; i < num_slack; i++)
			{	j = this->optimization->constraints->initialBasisStatus->atUpper->el[i];
				if (j >= 0 && j < numberOfConstraints)
					m_mdInitBasisStatusDense[j] = ENUM_BASIS_STATUS_atUpper;
				else
					throw ErrorClass("Constraint index out of range");
			}
		}

		if (this->optimization->constraints->initialBasisStatus->isFree != NULL)
		{
			num_slack = this->optimization->constraints->initialBasisStatus->isFree->numberOfEl;
			for (i = 0; i < num_slack; i++)
			{	j = this->optimization->constraints->initialBasisStatus->isFree->el[i];
				if (j >= 0 && j < numberOfConstraints)
					m_mdInitBasisStatusDense[j] = ENUM_BASIS_STATUS_isFree;
				else
					throw ErrorClass("Constraint index out of range");
			}
		}

		if (this->optimization->constraints->initialBasisStatus->superbasic != NULL)
		{
			num_slack = this->optimization->constraints->initialBasisStatus->superbasic->numberOfEl;
			for (i = 0; i < num_slack; i++)
			{	j = this->optimization->constraints->initialBasisStatus->superbasic->el[i];
				if (j >= 0 && j < numberOfConstraints)
					m_mdInitBasisStatusDense[j] = ENUM_BASIS_STATUS_superbasic;
				else
					throw ErrorClass("Constraint index out of range");
			}
		}

		return m_mdInitBasisStatusDense;
	}

	catch(const ErrorClass& eclass)
	{
		throw ErrorClass(eclass.errormsg);
	}
	return NULL;
}//getSlackVariableInitialBasisStatusDense


/**
 * get the array of other constraint options associated with a particular solver
 * @param solver_name is the name of the solver
 * @return an array of other constraint options associated with this solver
 */
std::vector<OtherConstraintOption*>  OSOption::getOtherConstraintOptions( std::string solver_name)
{	std::vector<OtherConstraintOption*> optionsVector;
	if (this->optimization != NULL) 
	{	if (this->optimization->constraints != NULL) 
		{	int i;
			int num_options;
			num_options = this->getNumberOfOtherConstraintOptions();
			for(i = 0; i < num_options; i++)
				if (solver_name == this->optimization->constraints->other[ i]->solver)
					optionsVector.push_back( this->optimization->constraints->other[ i]);
		}					
		else
			throw ErrorClass("<constraints> object must be defined before getting the data");
	}
	else
		throw ErrorClass("<optimization> object must be defined before getting the data");
	return optionsVector;
}//getOtherConstraintOptions

/**
 * get the array of all other constraint options
 * @return an array of other constraint options associated with this solver
 */
OtherConstraintOption** OSOption::getAllOtherConstraintOptions()
{	OtherConstraintOption** optionsVector;
	if (this->optimization != NULL) 
	{	if (this->optimization->constraints != NULL) 
			optionsVector = this->optimization->constraints->other;
		else
			throw ErrorClass("<constraints> object must be defined before getting the data");
	}
	else
		throw ErrorClass("<optimization> object must be defined before getting the data");
	return optionsVector;
}//getAllOtherConstraintOptions


/**
 * get the array of solver options associated with a particular solver
 * @param solver_name is the name of the solver
 * @return an array of solver options associated with this solver
 */
std::vector<SolverOption*>  OSOption::getSolverOptions( std::string solver_name)
{	std::vector<SolverOption*> optionsVector;
	if (this->optimization != NULL) 
	{	if (this->optimization->solverOptions != NULL) 
		{	int i;
			int num_options;
			num_options = this->getNumberOfSolverOptions();
			for(i = 0; i < num_options; i++)
				if (solver_name == this->optimization->solverOptions->solverOption[ i]->solver)
					optionsVector.push_back( this->optimization->solverOptions->solverOption[ i]);
		}					
		else
			throw ErrorClass("<solverOptions> object must be defined before getting the data");
	}
	else
		throw ErrorClass("<optimization> object must be defined before getting the data");
	return optionsVector;
}//getSolverOptions

/**
 * get the array of all solver options
 * @return an array of other constraint options associated with this solver
 */
SolverOption** OSOption::getAllSolverOptions()
{	SolverOption** optionsVector;
	if (this->optimization != NULL) 
	{	if (this->optimization->solverOptions != NULL) 
			optionsVector = this->optimization->solverOptions->solverOption;
		else
			throw ErrorClass("<solverOptions> object must be defined before getting the data");
	}
	else
		throw ErrorClass("<optimization> object must be defined before getting the data");
	return optionsVector;
}//getAllOtherConstraintOptions



/** 
 *  ---------------------------------------------------------
 *      set() options
 *  ---------------------------------------------------------
 */

/* ----------------------------------------------------------
 * Start with a number of set() and add() methods for arrays 
 * used in various subelements.
 * These have been put here in order of appearance
 * ----------------------------------------------------------*/

/** setOther()
 *  set an array of <other> elements in <general>, <system>, <service> and <job>
 */
bool OtherOptions::setOther(int numberOfOptions, OtherOption** other)
{	try
	{	if (this->other != NULL)
			throw ErrorClass( "otherOptions array previously used.");
		
		if (numberOfOptions < 0)
			throw ErrorClass( "length of otherOptions array cannot be negative.");

		this->numberOfOtherOptions = numberOfOptions;
		if (numberOfOptions == 0)
			return true;

		this->other = new OtherOption*[numberOfOptions];
	 
		int  i;
		for (i = 0; i < numberOfOptions; i++)
		{	 this->other[i] = new OtherOption();
			*this->other[i] = *other[i];
		}
		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//setOther

/** addOther()
 *  used to add an <other> element in <general>, <system>, <service>, <job> etc.
 */
bool OtherOptions::addOther(std::string name, std::string value, std::string description)
{	try
	{	int nopt; int i;
		if (name.empty() )
			throw ErrorClass( "the name of an option cannot be empty." );

		if (this->other == NULL) 
			nopt = 0;
		else
			nopt = this->numberOfOtherOptions;
	
		OtherOption** temp = new OtherOption*[nopt+1];  //Allocate the new pointers
		for (i = 0; i < nopt; i++)
			temp[i] = this->other[i];  //copy the pointers

		delete[] this->other; //delete old pointers
	
//	add in the new element
		temp[ nopt] = new OtherOption();

		temp[ nopt]->name = name;
		temp[ nopt]->value = value;
		temp[ nopt]->description = description;

		this->other = temp;   //hook the new pointers into the data structure
		this->numberOfOtherOptions = ++nopt;

		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//addOther

/**
 * A function to set an array of <jobID> elements
 * @param numberOfJobIDs: number of <jobID> elements to be set
 * @param jobID: the array of <jobID> elements that are to be set
 */
bool JobDependencies::setJobID(int numberOfJobIDs, std::string *jobID)
{	try
	{	if (this->jobID != NULL)
			throw ErrorClass( "jobID array previously used.");

		if (numberOfJobIDs < 0)
			throw ErrorClass( "length of jobID array cannot be negative.");

		this->numberOfJobIDs = numberOfJobIDs;
		if (numberOfJobIDs == 0)
			return true;

		this->jobID = new std::string[numberOfJobIDs];
		int i;
		for (i = 0; i < numberOfJobIDs; i++)
			this->jobID[i] = jobID[i];
		
		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//setJobID

/**
 *
 * A function to add an <jobID> element
 * @param jobID: the name of the <jobID> element to be added 
 */
bool JobDependencies::addJobID(std::string jobID)
{	try
	{	int nopt;
		if (jobID.empty() )
			throw ErrorClass( "the name of a jobID cannot be empty." );

		if (this->jobID == NULL) 
			nopt = 0;
		else
			nopt = this->numberOfJobIDs;

		std::string* temp = new std::string[nopt+1];
		int i;
		for (i = 0; i < nopt; i++)
			temp[i] = this->jobID[i]; // create the new jobID

		delete[] this->jobID;
		
		temp[nopt] = jobID;

		this->jobID = temp;
		this->numberOfJobIDs = ++nopt;
		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//addJobID

/**
 *
 * A function to set an array of <path> elements
 * @param numberOfPaths: number of <path> elements to be set
 * @param path: the array of <path> elements that are to be set
 */
bool DirectoriesAndFiles::setPath(int numberOfPaths, std::string *path)
{	try
	{	if (this->path != NULL)
			throw ErrorClass( "path array previously used.");

		if (numberOfPaths < 0)
			throw ErrorClass( "length of path array cannot be negative.");

		this->numberOfPaths = numberOfPaths;
		if (numberOfPaths == 0)
			return true;

		this->path = new std::string[numberOfPaths];
		int i;
		for (i = 0; i < numberOfPaths; i++)
			this->path[i] = path[i];
		
		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//setPath

/**
 *
 * A function to add a <path> element
 * @param path: the path to be added 
 */
bool DirectoriesAndFiles::addPath(std::string path)
{	try
	{	int nopt;
		if (path.empty() )
			throw ErrorClass( "the path cannot be empty." );

		if (this->path == NULL) 
			nopt = 0;
		else
			nopt = this->numberOfPaths;

		std::string* temp = new std::string[nopt+1];
		int i;
		for (i = 0; i < nopt; i++)
			temp[i] = this->path[i]; // create the new path

		delete[] this->path;
		
		temp[nopt] = path;

		this->path = temp;
		this->numberOfPaths = ++nopt;
		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//addPath

/**
 *
 * A function to set an array of <pathPair> elements
 * @param numberOfPathPairs: number of <pathPair> elements to be set
 * @param path: the array of <pathPair> elements that are to be set
 */
bool PathPairs::setPathPair(int numberOfPathPairs, PathPair **pathPair)
{	try
	{	if (this->pathPair != NULL)
			throw ErrorClass( "pathPair array previously used.");
		
		if (numberOfPathPairs < 0)
			throw ErrorClass( "length of pathPair array cannot be negative.");

		this->numberOfPathPairs = numberOfPathPairs;
		if (numberOfPathPairs == 0)
			return true;

		this->pathPair = new PathPair*[numberOfPathPairs];
	 
		int  i;
		for (i = 0; i < numberOfPathPairs; i++)
		{	 this->pathPair[i] = new PathPair();
			*this->pathPair[i] = *pathPair[i];
		}
		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//setPathPair


bool PathPairs::setPathPair(std::string *from, std::string *to, bool *makeCopy, int numberOfPathPairs)
{
//	if (this->pathPair != NULL)
//		return false;
		
	this->numberOfPathPairs = numberOfPathPairs;
	if (numberOfPathPairs == 0)
		return true;

	this->pathPair = new PathPair*[numberOfPathPairs];
	 
	int  i;
	for (i = 0; i < numberOfPathPairs; i++)
	{
		this->pathPair[i] = new PathPair();
		this->pathPair[i]->from = from[i];
		this->pathPair[i]->to = to[i];
		this->pathPair[i]->makeCopy = makeCopy[i];
	}
	return true;
}//setPathPair

/**
 *
 * A function to add a <pathPair> element
 * @param fromPath: the path from which to copy or move
 * @param toPath: the path to which to copy or move
 * @param makecopy: tracks whether a copy is to be made
 */
bool PathPairs::addPathPair(std::string fromPath, std::string toPath, bool makeCopy)
{	try
	{	int nopt; int i;
		if (fromPath.empty() )
			throw ErrorClass( "the \"from\" path cannot be empty." );
		if (toPath.empty() )
			throw ErrorClass( "the \"to\" path cannot be empty." );

		if (this->pathPair == NULL) 
			nopt = 0;
		else
			nopt = this->numberOfPathPairs;
	
		PathPair** temp = new PathPair*[nopt+1];  //Allocate the new pointers
		for (i = 0; i < nopt; i++)
			temp[i] = this->pathPair[i];  //copy the pointers

		delete[] this->pathPair; //delete old pointers
	
//	add in the new element
		temp[ nopt] = new PathPair();

		temp[ nopt]->from = fromPath;
		temp[ nopt]->to = toPath;
		temp[ nopt]->makeCopy = makeCopy;

		this->pathPair = temp;   //hook the new pointers into the data structure
		this->numberOfPathPairs = ++nopt;

		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//addPathPair

/**
 *
 * A function to set an array of <process> elements
 * @param numberOfProcesses: number of <process> elements to be set
 * @param path: the array of <process> elements that are to be set
 */
bool Processes::setProcess(int numberOfProcesses, std::string *process)
{	try
	{	if (this->process != NULL)
			throw ErrorClass( "process array previously used.");

		if (numberOfProcesses < 0)
			throw ErrorClass( "length of process array cannot be negative.");

		this->numberOfProcesses= numberOfProcesses;
		if (numberOfProcesses == 0)
			return true;

		this->process = new std::string[numberOfProcesses];
		int i;
		for (i = 0; i < numberOfProcesses; i++)
			this->process[i] = process[i];
		
		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//setProcess

/**
 *
 * A function to add a <process> element
 * @param process: the ID of the process to be added 
 */
bool Processes::addProcess(std::string process)
{	try
	{	int nopt;
		if (process.empty() )
			throw ErrorClass( "the name of a process cannot be empty." );

		if (this->process == NULL) 
			nopt = 0;
		else
			nopt = this->numberOfProcesses;

		std::string* temp = new std::string[nopt+1];
		int i;
		for (i = 0; i < nopt; i++)
			temp[i] = this->process[i]; // create the new jobID

		delete[] this->process;
		
		temp[nopt] = process;

		this->process = temp;
		this->numberOfProcesses = ++nopt;
		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//addProcess

/**
 *
 * A function to set an array of <var> elements 
 * @param numberOfVar: number of <var> elements to be set
 * @param var: the array of <var> elements that are to be set
 */
bool InitVariableValues::setVar(int numberOfVar, InitVarValue **var)
{	try
	{	if (this->var != NULL)
			throw ErrorClass( "InitVarValue array previously used.");
		
		if (numberOfVar < 0)
			throw ErrorClass( "length of var array cannot be negative.");

		this->numberOfVar = numberOfVar;
		if (numberOfVar == 0)
			return true;

		this->var = new InitVarValue*[numberOfVar];
	 
		int  i;
		for (i = 0; i < numberOfVar; i++)
		{	 this->var[i] = new InitVarValue();
			*this->var[i] = *var[i];
		}
		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//setVar

/**
 *
 * A function to set an array of <var> elements 
 * @param numberOfVar: number of <var> elements to be set
 * @param idx: the array of indices for the elements that are to be set
 * @param value: the array of the corresponding values
 * @param name: the array of the corresponding names
 */
bool InitVariableValues::setVar(int numberOfVar, int *idx, double *value, std::string *name)
{	
	if (this->var != NULL)
		return false;
		
	if (numberOfVar < 0)
		return false;

	this->numberOfVar = numberOfVar;
	if (numberOfVar == 0)
		return true;

	this->var = new InitVarValue*[numberOfVar];
	 
	int  i;
	for (i = 0; i < numberOfVar; i++)
	{
		this->var[i] = new InitVarValue();
		this->var[i]->idx = idx[i];
		this->var[i]->name = name[i];
		this->var[i]->value = value[i];
	}
	return true;
}//setVar


/**
 *
 * A function to add a <var> element
 * @param idx: the index of the variable to be given an initial value
 * @param value: the initial variable value to be added 
 */
bool InitVariableValues::addVar(int idx, double value)
{	try
	{	int nopt; int i;
		if (idx < 0)
			throw ErrorClass( "the index of a variable cannot be negative." );

		if (this->var == NULL) 
			nopt = 0;
		else
			nopt = this->numberOfVar;
	
		InitVarValue** temp = new InitVarValue*[nopt+1];  //Allocate the new pointers
		for (i = 0; i < nopt; i++)
			temp[i] = this->var[i];  //copy the pointers

		delete[] this->var; //delete old pointers
	
//	add in the new element
		temp[ nopt] = new InitVarValue();

		temp[ nopt]->idx = idx;
		temp[ nopt]->value = value;

		this->var = temp;   //hook the new pointers into the data structure
		this->numberOfVar = ++nopt;

		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//addVar

/**
 *
 * A function to set an array of <var> elements 
 * @param numberOfVar: number of <var> elements to be set
 * @param var: the array of <var> elements that are to be set
 */
bool InitVariableValuesString::setVar(int numberOfVar, InitVarValueString **var)
{	try
	{	if (this->var != NULL)
			throw ErrorClass( "InitVarValueString array previously used.");
		
		if (numberOfVar < 0)
			throw ErrorClass( "length of var array cannot be negative.");

		this->numberOfVar = numberOfVar;
		if (numberOfVar == 0)
			return true;

		this->var = new InitVarValueString*[numberOfVar];
	 
		int  i;
		for (i = 0; i < numberOfVar; i++)
		{	 this->var[i] = new InitVarValueString();
			*this->var[i] = *var[i];
		}
		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//setVar


/**
 *
 * A function to set an array of <var> elements 
 * @param numberOfVar: number of <var> elements to be set
 * @param idx: the array of indices for the elements that are to be set
 * @param value: the array of the corresponding values
 * @param name: the array of the corresponding names
 */
bool InitVariableValuesString::setVar(int numberOfVar, int *idx, std::string *value, std::string *name)
{	
	if (this->var != NULL)
		return false;
		
	if (numberOfVar < 0)
		return false;

	this->numberOfVar = numberOfVar;
	if (numberOfVar == 0)
		return true;

	this->var = new InitVarValueString*[numberOfVar];
	 
	int  i;
	for (i = 0; i < numberOfVar; i++)
	{
		this->var[i] = new InitVarValueString();
		this->var[i]->idx = idx[i];
		this->var[i]->name = name[i];
		this->var[i]->value = value[i];
	}
	return true;
}//setVar

/**
 *
 * A function to add a <var> element
 * @param idx: the index of the variable to be given an initial value
 * @param value: the initial string value to be added 
 */
bool InitVariableValuesString::addVar(int idx, std::string value)
{	try
	{	int nopt; int i;
		if (idx < 0)
			throw ErrorClass( "the index of a variable cannot be negative." );

		if (this->var == NULL) 
			nopt = 0;
		else
			nopt = this->numberOfVar;
	
		InitVarValueString** temp = new InitVarValueString*[nopt+1];  //Allocate the new pointers
		for (i = 0; i < nopt; i++)
			temp[i] = this->var[i];  //copy the pointers

		delete[] this->var; //delete old pointers
	
//	add in the new element
		temp[ nopt] = new InitVarValueString();

		temp[ nopt]->idx = idx;
		temp[ nopt]->value = value;

		this->var = temp;   //hook the new pointers into the data structure
		this->numberOfVar = ++nopt;

		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//addVar

/**
 *
 * A function to set an array of <var> elements 
 * @param numberOfVar: number of <var> elements to be set
 * @param var: the array of <var> elements to be that are to be set
 */
bool InitialBasisStatus::setVar(int numberOfVar, InitBasStatus **var)
{	try
	{	if (this->var != NULL)
			throw ErrorClass( "InitBasStatus array previously used.");
		
		if (numberOfVar < 0)
			throw ErrorClass( "length of var array cannot be negative.");

		this->numberOfVar = numberOfVar;
		if (numberOfVar == 0)
			return true;

		this->var = new InitBasStatus*[numberOfVar];
	 
		int  i;
		for (i = 0; i < numberOfVar; i++)
		{	 this->var[i] = new InitBasStatus();
			*this->var[i] = *var[i];
		}
		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//setVar

/**
 *
 * A function to add a <var> element
 * @param idx: the index of the variable to be given an initial basis status
 * @param value: the initial basis status to be added 
 */
bool InitialBasisStatus::addVar(int idx, std::string value)
{	try
	{	int nopt; int i;
		if (idx < 0)
			throw ErrorClass( "the index of a variable cannot be negative." );
		if (value != "atLower" && value != "basic" && value != "unknown" && 
			value != "atUpper" && value != "superbasic" )
			throw ErrorClass( "Illegal basis status " + value );

		if (this->var == NULL) 
			nopt = 0;
		else
			nopt = this->numberOfVar;
	
		InitBasStatus** temp = new InitBasStatus*[nopt+1];  //Allocate the new pointers
		for (i = 0; i < nopt; i++)
			temp[i] = this->var[i];  //copy the pointers

		delete[] this->var; //delete old pointers
	
//	add in the new element
		temp[ nopt] = new InitBasStatus();

		temp[ nopt]->idx = idx;
		temp[ nopt]->value = value;

		this->var = temp;   //hook the new pointers into the data structure
		this->numberOfVar = ++nopt;

		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//addVar

/**
 *
 * A function to set an array of <var> elements 
 * @param numberOfVar: number of <var> elements to be set
 * @param var: the array of <var> elements to be that are to be set
 */
bool IntegerVariableBranchingWeights::setVar(int numberOfVar, BranchingWeight **var)
{	try
	{	if (this->var != NULL)
		return false;
		
		if (numberOfVar < 0)
		return false;

		this->numberOfVar = numberOfVar;
		if (numberOfVar == 0)
			return true;

		this->var = new BranchingWeight*[numberOfVar];
	 
		int  i;
		for (i = 0; i < numberOfVar; i++)
		{	 this->var[i] = new BranchingWeight();
			*this->var[i] = *var[i];
		}
		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//setVar


/**
 *
 * A function to set an array of <var> elements 
 * @param numberOfVar: number of <var> elements to be set
 * @param idx: the array of indices for the elements that are to be set
 * @param value: the array of the corresponding values
 * @param name: the array of the corresponding names
 */
bool IntegerVariableBranchingWeights::setVar(int numberOfVar, int *idx, double *value, std::string *name)
{	
	if (this->var != NULL)
		return false;
		
	if (numberOfVar < 0)
		return false;

	this->numberOfVar = numberOfVar;
	if (numberOfVar == 0)
		return true;

	this->var = new BranchingWeight*[numberOfVar];
	 
	int  i;
	for (i = 0; i < numberOfVar; i++)
	{
		this->var[i] = new BranchingWeight();
		this->var[i]->idx = idx[i];
		this->var[i]->name = name[i];
		this->var[i]->value = value[i];
	}
	return true;
}//setVar




/**
 *
 * A function to add a <var> element
 * @param idx: the index of the variable to be given a branching weight 
 * @param value: the branching weight to be added 
 */
bool IntegerVariableBranchingWeights::addVar(int idx, double value)
{	try
	{	int nopt; int i;
		if (idx < 0)
			throw ErrorClass( "the index of a variable cannot be negative." );

		if (this->var == NULL) 
			nopt = 0;
		else
			nopt = this->numberOfVar;
	
		BranchingWeight** temp = new BranchingWeight*[nopt+1];  //Allocate the new pointers
		for (i = 0; i < nopt; i++)
			temp[i] = this->var[i];  //copy the pointers

		delete[] this->var; //delete old pointers
	
//	add in the new element
		temp[ nopt] = new BranchingWeight();

		temp[ nopt]->idx = idx;
		temp[ nopt]->value = value;

		this->var = temp;   //hook the new pointers into the data structure
		this->numberOfVar = ++nopt;

		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//addVar

/**
 *
 * A function to set an array of <var> elements 
 * @param numberOfVar: number of <var> elements to be set
 * @param var: the array of <var> elements that are to be set
 */
bool SOSWeights::setVar(int numberOfVar, BranchingWeight **var)
{	try
	{	if (this->var != NULL)
			throw ErrorClass( "BranchingWeight array previously used.");
		
		if (numberOfVar < 0)
			throw ErrorClass( "length of var array cannot be negative.");

		this->numberOfVar = numberOfVar;
		if (numberOfVar == 0)
			return true;

		this->var = new BranchingWeight*[numberOfVar];
	 
		int  i;
		for (i = 0; i < numberOfVar; i++)
		{	 this->var[i] = new BranchingWeight();
			*this->var[i] = *var[i];
		}
		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//setVar

/**
 *
 * A function to add a <var> element
 * @param idx: the index of the variable to be given a branching weight 
 * @param value: the branching weight to be added 
 */
bool SOSWeights::addVar(int idx, double value)
{	try
	{	int nopt; int i;
		if (idx < 0)
			throw ErrorClass( "the index of a variable cannot be negative." );

		if (this->var == NULL) 
			nopt = 0;
		else
			nopt = this->numberOfVar;
	
		BranchingWeight** temp = new BranchingWeight*[nopt+1];  //Allocate the new pointers
		for (i = 0; i < nopt; i++)
			temp[i] = this->var[i];  //copy the pointers

		delete[] this->var; //delete old pointers
	
//	add in the new element
		temp[ nopt] = new BranchingWeight();

		temp[ nopt]->idx = idx;
		temp[ nopt]->value = value;

		this->var = temp;   //hook the new pointers into the data structure
		this->numberOfVar = ++nopt;

		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//addVar

/**
 *
 * A function to set an array of <sos> elements 
 * @param numberOfSOS: number of <sos> elements to be set
 * @param sos: the array of <sos> elements that are to be set
 */
bool SOSVariableBranchingWeights::setSOS(int numberOfSOS, SOSWeights **sos)
{	try
	{	if (this->sos != NULL)
			throw ErrorClass( "SOS array previously used.");
		
		if (numberOfSOS < 0)
			throw ErrorClass( "length of sos array cannot be negative.");
		
		this->numberOfSOS = numberOfSOS;
		if (numberOfSOS == 0) return true;

		this->sos = new SOSWeights*[numberOfSOS];
	 
		int  i, j;
		for (i = 0; i < numberOfSOS; i++)
		{	this->sos[i] = new SOSWeights();
			this->sos[i]->sosIdx      = sos[i]->sosIdx;
			this->sos[i]->groupWeight = sos[i]->groupWeight;

			if (sos[i]->numberOfVar < 0)
				throw ErrorClass( "the number of variables in the SOS cannot be negative.");

			this->sos[i]->numberOfVar = sos[i]->numberOfVar;

			if (sos[i]->numberOfVar > 0) 
			{	this->sos[i]->var = new BranchingWeight*[sos[i]->numberOfVar];
				for (j = 0; j < sos[i]->numberOfVar; j++)
				{	 this->sos[i]->var[j] = new BranchingWeight();
					*this->sos[i]->var[j] = *sos[i]->var[j];
				}
			}
		}
		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//setSOS

/**
 *
 * A function to add an <sos> element
 * @param sos: the content of the <sos> element that is to be added 
 */
bool SOSVariableBranchingWeights::addSOS(int sosIdx, int nvar, double weight, int* idx, double* value, std::string* name)
{	try
	{	int nopt; int i;
		if (sosIdx < 0)
			throw ErrorClass( "the index of the SOS cannot be negative." );
		if (nvar < 0)
			throw ErrorClass( "the number of variables in the SOS cannot be negative." );

		if (this->sos  == NULL) 
			nopt = 0;
		else
			nopt = this->numberOfSOS;
	
		SOSWeights** temp = new SOSWeights*[nopt+1];  //Allocate the new pointers
		for (i = 0; i < nopt; i++)
			temp[i] = this->sos[i];  //copy the pointers

		delete[] this->sos; //delete old pointers
	
//	add in the new element
		temp[ nopt] = new SOSWeights();

		temp[ nopt]->sosIdx = sosIdx;
		temp[ nopt]->groupWeight = weight;
		temp[ nopt]->numberOfVar = nvar;
		temp[ nopt]->var = new BranchingWeight*[nvar];
		for (i = 0; i < nvar; i++)
		{	temp[nopt]->var[i] = new BranchingWeight();
			temp[nopt]->var[i]->idx   = idx[i];
			temp[nopt]->var[i]->name  = name[i];
			temp[nopt]->var[i]->value = value[i];
		}

		this->sos  = temp;   //hook the new pointers into the data structure
		this->numberOfSOS = ++nopt;

		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//addSOS

/**
 *
 * A function to set an array of <var> elements 
 * @param numberOfVar: number of <var> elements to be set
 * @param var: the array of <var> elements that are to be set
 */
bool OtherVariableOption::setVar(int numberOfVar, OtherVarOption **var)
{	try
	{	if (this->var != NULL)
			throw ErrorClass( "OtherVarOption array previously used.");
		
		if (numberOfVar < 0)
			throw ErrorClass( "length of <var> array cannot be negative.");

		this->numberOfVar = numberOfVar;
		if (numberOfVar == 0) return true;

		this->var = new OtherVarOption*[numberOfVar];
	 
		int  i;
		for (i = 0; i < numberOfVar; i++)
		{	 this->var[i] = new OtherVarOption();
			*this->var[i] = *var[i];
		}
		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//setVar

/**
 *
 * A function to add a <var> element
 * @param idx: the index of the variable  
 * @param value: the value associated with this variable 
 * @param lbValue: a lower bound associated with this variable 
 * @param ubValue: an upper bound associated with this variable 
 */
bool OtherVariableOption::addVar(int idx, std::string value, std::string lbValue, std::string ubValue)
{	try
	{	int nopt; int i;
		if (idx < 0)
			throw ErrorClass( "the index of a variable cannot be negative." );

		if (this->var == NULL) 
			nopt = 0;
		else
			nopt = this->numberOfVar;
	
		OtherVarOption** temp = new OtherVarOption*[nopt+1];  //Allocate the new pointers
		for (i = 0; i < nopt; i++)
			temp[i] = this->var[i];  //copy the pointers

		delete[] this->var; //delete old pointers
	
//	add in the new element
		temp[ nopt] = new OtherVarOption();

		temp[ nopt]->idx = idx;
		temp[ nopt]->value = value;
		temp[ nopt]->lbValue = lbValue;
		temp[ nopt]->ubValue = ubValue;

		this->var = temp;   //hook the new pointers into the data structure
		this->numberOfVar = ++nopt;

		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//addVar

/**
 *
 * A function to set an array of <other> elements
 * @param numberOfOptions: number of <other> elements to be set
 * @param other: the array of <other> elements that are to be set
 */
bool VariableOption::setOther(int numberOfOptions, OtherVariableOption  **other)
{	try
	{	if (this->other != NULL)
			throw ErrorClass( "otherVariableOptions array previously used.");
		
		if (numberOfOptions < 0)
			throw ErrorClass( "length of <other> array cannot be negative.");

		this->numberOfOtherVariableOptions = numberOfOptions;
		if (numberOfOptions == 0) return true;

		this->other = new OtherVariableOption*[numberOfOptions];
	 
		int  i, j;
		for (i = 0; i < numberOfOptions; i++)
		{	this->other[i] = new OtherVariableOption();
			this->other[i]->name        = other[i]->name;
			this->other[i]->value       = other[i]->value;
			this->other[i]->solver      = other[i]->solver;
			this->other[i]->category    = other[i]->category;
			this->other[i]->type        = other[i]->type;
			this->other[i]->description = other[i]->description;

			if (other[i]->numberOfVar < 0)
				throw ErrorClass( "the number of variables in otherVariableOption cannot be negative.");

			this->other[i]->numberOfVar = other[i]->numberOfVar;

			if (other[i]->numberOfVar > 0) 
			{
				this->other[i]->var = new OtherVarOption*[other[i]->numberOfVar];
				for (j = 0; j < other[i]->numberOfVar; j++)
				{	 this->other[i]->var[j] = new OtherVarOption();
					*this->other[i]->var[j] = *other[i]->var[j];
				}
			}
			this->other[i]->numberOfEnumerations = other[i]->numberOfEnumerations;

			if (this->other[i]->numberOfEnumerations > 0)
			{	
				this->other[i]->enumeration = new OtherOptionEnumeration*[this->other[i]->numberOfEnumerations];
				for (j = 0; j < this->other[i]->numberOfEnumerations; j++)
				{
					this->other[i]->enumeration[j]  = new OtherOptionEnumeration();
					this->other[i]->enumeration[j]->setOtherOptionEnumeration(
						other[i]->enumeration[j]->value, 
						other[i]->enumeration[j]->description, 
						other[i]->enumeration[j]->el, 
						other[i]->enumeration[j]->numberOfEl);
				}
			}
		}
		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//setOther

/**
 *
 * A function to add an <other> element
 * @param other: the content of the <other> element to be added
 */
bool VariableOption::addOther(OtherVariableOption *other)
{	try
	{	int nopt, i, j;
		if (this->other == NULL) 
			nopt = 0;
		else
			nopt = this->numberOfOtherVariableOptions;
	
		OtherVariableOption** temp = new OtherVariableOption*[nopt+1];  //Allocate the new pointers
		for (i = 0; i < nopt; i++)
			temp[i] = this->other[i];  //copy the pointers

		delete[] this->other; //delete old pointers
	
//	add in the new element
		temp[ nopt] = new OtherVariableOption();
		temp[ nopt]->name        = other->name;
		temp[ nopt]->value       = other->value;
		temp[ nopt]->solver      = other->solver;
		temp[ nopt]->category    = other->category;
		temp[ nopt]->type        = other->type;
		temp[ nopt]->description = other->description;

		if (other->numberOfVar < 0)
			throw ErrorClass( "the number of variables in otherVariableOption cannot be negative.");

		temp[ nopt]->numberOfVar = other->numberOfVar;

		if (other->numberOfVar > 0)
		{	
			temp[ nopt]->var = new OtherVarOption*[other->numberOfVar];
			for (j = 0; j < other->numberOfVar; j++)
			{	 temp[ nopt]->var[j] = new OtherVarOption();
				*temp[ nopt]->var[j] = *other->var[j];
			}
		}

		temp[ nopt]->numberOfEnumerations = other->numberOfEnumerations;

		if (other->numberOfEnumerations > 0)
		{	
			temp[ nopt]->enumeration = new OtherOptionEnumeration*[other->numberOfEnumerations];
			for (j = 0; j < other->numberOfEnumerations; j++)
			{
				temp[ nopt]->enumeration[j]  = new OtherOptionEnumeration();
				temp[ nopt]->enumeration[j]->setOtherOptionEnumeration(
					other->enumeration[j]->value, 
					other->enumeration[j]->description, 
					other->enumeration[j]->el, 
					other->enumeration[j]->numberOfEl);
			}
		}


		this->other = temp;   //hook the new pointers into the data structure
		this->numberOfOtherVariableOptions = ++nopt;

		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//addOther

/**
 *
 * A function to set an array of <obj> elements 
 * @param numberOfObj: number of <obj> elements to be set
 * @param obj: the array of <obj> elements that are to be set
 */
bool InitObjectiveValues::setObj(int numberOfObj, InitObjValue **obj)
{	try
	{	if (this->obj != NULL)
			throw ErrorClass( "InitObjValue array previously used.");
		
		if (numberOfObj < 0)
			throw ErrorClass( "length of obj array cannot be negative.");

		this->numberOfObj = numberOfObj;
		if (numberOfObj == 0)
			return true;

		this->obj = new InitObjValue*[numberOfObj];
	 
		int  i;
		for (i = 0; i < numberOfObj; i++)
		{	 this->obj[i] = new InitObjValue();
			*this->obj[i] = *obj[i];
		}
		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//setObj

bool InitObjectiveValues::setObj(int numberOfObj, int *idx, double *value, std::string *name)
{	
	if (this->obj != NULL) return false;
		
	if (numberOfObj < 0) return false;

	this->numberOfObj = numberOfObj;
	if (numberOfObj == 0) return true;

	this->obj = new InitObjValue*[numberOfObj];
	 
	int  i;
	for (i = 0; i < numberOfObj; i++)
	{
		this->obj[i] = new InitObjValue();
		this->obj[i]->idx = idx[i];
		this->obj[i]->name = name[i];
		this->obj[i]->value = value[i];
	}
	return true;
}//setObj


/**
 *
 * A function to add a <obj> element
 * @param idx: the index of the objective to be given an initial value
 * @param value: the inital value to be added 
 */
bool InitObjectiveValues::addObj(int idx, double value)
{	try
	{	int nopt; int i;
		if (idx >= 0)
			throw ErrorClass( "the index of an objective must be negative." );

		if (this->obj == NULL) 
			nopt = 0;
		else
			nopt = this->numberOfObj;
	
		InitObjValue** temp = new InitObjValue*[nopt+1];  //Allocate the new pointers
		for (i = 0; i < nopt; i++)
			temp[i] = this->obj[i];  //copy the pointers

		delete[] this->obj; //delete old pointers
	
//	add in the new element
		temp[ nopt] = new InitObjValue();

		temp[ nopt]->idx = idx;
		temp[ nopt]->value = value;

		this->obj = temp;   //hook the new pointers into the data structure
		this->numberOfObj = ++nopt;

		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//addObj

/**
 *
 * A function to set an array of <obj> elements 
 * @param numberOfObj: number of <obj> elements to be set
 * @param obj: the array of <obj> elements that are to be set
 */
bool InitObjectiveBounds::setObj(int numberOfObj, InitObjBound **obj)
{	try
	{	if (this->obj != NULL)
			throw ErrorClass( "InitObjBound array previously used.");
		
		if (numberOfObj < 0)
			throw ErrorClass( "length of obj array cannot be negative.");

		this->numberOfObj = numberOfObj;
		if (numberOfObj == 0)
			return true;

		this->obj = new InitObjBound*[numberOfObj];
	 
		int  i;
		for (i = 0; i < numberOfObj; i++)
		{	 this->obj[i] = new InitObjBound();
			*this->obj[i] = *obj[i];
		}
		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//setObj

bool InitObjectiveBounds::setObj(int numberOfObj, int *idx, double *lbValue, double *ubValue, std::string *name)
{	
	if (this->obj != NULL)
		return false;
		
	if (numberOfObj < 0)
		return false;

	this->numberOfObj = numberOfObj;
	if (numberOfObj == 0)
		return true;

	this->obj = new InitObjBound*[numberOfObj];
	 
	int  i;
	for (i = 0; i < numberOfObj; i++)
	{
		this->obj[i] = new InitObjBound();
		this->obj[i]->idx = idx[i];
		this->obj[i]->name = name[i];
		this->obj[i]->lbValue = lbValue[i];
		this->obj[i]->ubValue = ubValue[i];
	}
	return true;
}//setObj


/**
 *
 * A function to add a <obj> element
 * @param idx: the index of the objective to be given initial bounds
 * @param lbValue: the initial lower bound for the objective
 * @param ubValue: the initial upper bound for the objective
 */
bool InitObjectiveBounds::addObj(int idx, double lbValue, double ubValue)
{	try
	{	int nopt; int i;
		if (idx >= 0)
			throw ErrorClass( "the index of an objective must be negative." );

		if (this->obj == NULL) 
			nopt = 0;
		else
			nopt = this->numberOfObj;
	
		InitObjBound** temp = new InitObjBound*[nopt+1];  //Allocate the new pointers
		for (i = 0; i < nopt; i++)
			temp[i] = this->obj[i];  //copy the pointers

		delete[] this->obj; //delete old pointers
	
//	add in the new element
		temp[ nopt] = new InitObjBound();

		temp[ nopt]->idx = idx;
		temp[ nopt]->lbValue = lbValue;
		temp[ nopt]->ubValue = ubValue;

		this->obj = temp;   //hook the new pointers into the data structure
		this->numberOfObj = ++nopt;

		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//addObj

/**
 *
 * A function to set an array of <obj> elements 
 * @param numberOfObj: number of <obj> elements to be set
 * @param obj: the array of <obj> elements that are to be set
 */
bool OtherObjectiveOption::setObj(int numberOfObj, OtherObjOption **obj)
{	try
	{	if (this->obj != NULL)
			throw ErrorClass( "OtherObjOption array previously used.");
		
		if (numberOfObj < 0)
			throw ErrorClass( "length of <obj> array cannot be negative.");

		this->numberOfObj= numberOfObj;
		if (numberOfObj == 0)
			return true;

		this->obj = new OtherObjOption*[numberOfObj];
	 
		int  i;
		for (i = 0; i < numberOfObj; i++)
		{	 this->obj[i] = new OtherObjOption();
			*this->obj[i] = *obj[i];
		}
		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//setObj

/**
 *
 * A function to add a <obj> element
 * @param idx: the index of the objective 
 * @param value: the value associated with this objective 
 * @param lbValue: a lower bound associated with this objective 
 * @param ubValue: an upper bound associated with this objective 
 */
bool OtherObjectiveOption::addObj(int idx, std::string value, std::string lbValue, std::string ubValue)
{	try
	{	int nopt; int i;
		if (idx >= 0)
			throw ErrorClass( "the index of an objective must be negative." );

		if (this->obj == NULL) 
			nopt = 0;
		else
			nopt = this->numberOfObj;
	
		OtherObjOption** temp = new OtherObjOption*[nopt+1];  //Allocate the new pointers
		for (i = 0; i < nopt; i++)
			temp[i] = this->obj[i];  //copy the pointers

		delete[] this->obj; //delete old pointers
	
//	add in the new element
		temp[ nopt] = new OtherObjOption();

		temp[ nopt]->idx = idx;
		temp[ nopt]->value = value;
		temp[ nopt]->lbValue = lbValue;
		temp[ nopt]->ubValue = ubValue;

		this->obj = temp;   //hook the new pointers into the data structure
		this->numberOfObj = ++nopt;

		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//addObj

/**
 *
 * A function to set an array of <other> elements
 * @param numberOfOptions: number of <other> elements to be set
 * @param other: the array of <other> elements that are to be set
 */
bool ObjectiveOption::setOther(int numberOfOptions, OtherObjectiveOption  **other)
{	try
	{	if (this->other != NULL)
			throw ErrorClass( "otherObjectiveOptions array previously used.");
		
		if (numberOfOptions < 0)
			throw ErrorClass( "length of <other> array cannot be negative.");

		this->numberOfOtherObjectiveOptions = numberOfOptions;
		if (numberOfOptions == 0) return true;

		this->other = new OtherObjectiveOption*[numberOfOptions];
	 
		int  i, j;
		for (i = 0; i < numberOfOptions; i++)
		{	this->other[i] = new OtherObjectiveOption();
			this->other[i]->name        = other[i]->name;
			this->other[i]->value       = other[i]->value;
			this->other[i]->solver      = other[i]->solver;
			this->other[i]->category    = other[i]->category;
			this->other[i]->type        = other[i]->type;
			this->other[i]->description = other[i]->description;

			if (other[i]->numberOfObj < 0)
				throw ErrorClass( "the number of objectives in otherObjectiveOption cannot be negative.");

			this->other[i]->numberOfObj = other[i]->numberOfObj;

			if (other[i]->numberOfObj > 0) 
			{
				this->other[i]->obj = new OtherObjOption*[other[i]->numberOfObj];
				for (j = 0; j < other[i]->numberOfObj; j++)
				{	 this->other[i]->obj[j] = new OtherObjOption();
					*this->other[i]->obj[j] = *other[i]->obj[j];
				}
			}
			this->other[i]->numberOfEnumerations = other[i]->numberOfEnumerations;

			if (this->other[i]->numberOfEnumerations > 0)
			{	
				this->other[i]->enumeration = new OtherOptionEnumeration*[this->other[i]->numberOfEnumerations];
				for (j = 0; j < this->other[i]->numberOfEnumerations; j++)
				{
					this->other[i]->enumeration[j]  = new OtherOptionEnumeration();
					this->other[i]->enumeration[j]->setOtherOptionEnumeration(
						other[i]->enumeration[j]->value, 
						other[i]->enumeration[j]->description, 
						other[i]->enumeration[j]->el, 
						other[i]->enumeration[j]->numberOfEl);
				}
			}
		}
		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//setOther

/**
 *
 * A function to add an <other> element
 * @param other: the content of the <other> element to be added
 */
bool ObjectiveOption::addOther(OtherObjectiveOption *other)
{	try
	{	int nopt, i, j;
		if (this->other == NULL) 
			nopt = 0;
		else
			nopt = this->numberOfOtherObjectiveOptions;
	
		OtherObjectiveOption** temp = new OtherObjectiveOption*[nopt+1];  //Allocate the new pointers
		for (i = 0; i < nopt; i++)
			temp[i] = this->other[i];  //copy the pointers

		delete[] this->other; //delete old pointers
	
//	add in the new element
		temp[ nopt] = new OtherObjectiveOption();
		temp[ nopt]->name        = other->name;
		temp[ nopt]->value       = other->value;
		temp[ nopt]->solver      = other->solver;
		temp[ nopt]->category    = other->category;
		temp[ nopt]->type        = other->type;
		temp[ nopt]->description = other->description;

		if (other->numberOfObj < 0)
			throw ErrorClass( "the number of objectives in otherObjectiveOption cannot be negative.");

		temp[ nopt]->numberOfObj = other->numberOfObj;

		if (other->numberOfObj > 0) 
		{	
			temp[ nopt]->obj = new OtherObjOption*[other->numberOfObj];
			for (j = 0; j < other->numberOfObj; j++)
			{	 temp[ nopt]->obj[j] = new OtherObjOption();
				*temp[ nopt]->obj[j] = *other->obj[j];
			}
		}

		if (other->numberOfEnumerations < 0)
			throw ErrorClass( "the number of enumerations in otherObjectiveOption cannot be negative.");

		temp[ nopt]->numberOfEnumerations = other->numberOfEnumerations;

		if (other->numberOfEnumerations > 0)
		{	
			temp[ nopt]->enumeration = new OtherOptionEnumeration*[other->numberOfEnumerations];
			for (j = 0; j < other->numberOfEnumerations; j++)
			{
				temp[ nopt]->enumeration[j]  = new OtherOptionEnumeration();
				temp[ nopt]->enumeration[j]->setOtherOptionEnumeration(
					other->enumeration[j]->value, 
					other->enumeration[j]->description, 
					other->enumeration[j]->el, 
					other->enumeration[j]->numberOfEl);
			}
		}


		this->other = temp;   //hook the new pointers into the data structure
		this->numberOfOtherObjectiveOptions = ++nopt;

		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//addOther

/**
 *
 * A function to set an array of <con> elements 
 * @param numberOfCon: number of <con> elements to be set
 * @param con: the array of <con> elements that are to be set
 */
bool InitConstraintValues::setCon(int numberOfCon, InitConValue **con)
{	try
	{	if (this->con != NULL)
			throw ErrorClass( "InitConValue array previously used.");
		
		if (numberOfCon < 0)
			throw ErrorClass( "length of con array cannot be negative.");

		this->numberOfCon = numberOfCon;
		if (numberOfCon == 0)
			return true;

		this->con = new InitConValue*[numberOfCon];
	 
		int  i;
		for (i = 0; i < numberOfCon; i++)
		{	 this->con[i] = new InitConValue();
			*this->con[i] = *con[i];
		}
		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//setCon

bool InitConstraintValues::setCon(int numberOfCon, int *idx, double *value, std::string *name)
{	
	if (this->con != NULL)
		return false;
		
	if (numberOfCon < 0)
		return false;

	this->numberOfCon = numberOfCon;
	if (numberOfCon == 0)
		return true;

	this->con = new InitConValue*[numberOfCon];
	 
	int  i;
	for (i = 0; i < numberOfCon; i++)
	{
		this->con[i] = new InitConValue();
		this->con[i]->idx = idx[i];
		this->con[i]->name = name[i];
		this->con[i]->value = value[i];
	}
	return true;
}//setObj



/**
 *
 * A function to add a <con> element
 * @param idx: the index of the constraint to be given an inital value 
 * @param value: the initial value to be added 
 */
bool InitConstraintValues::addCon(int idx, double value)
{	try
	{	int nopt; int i;
		if (idx < 0)
			throw ErrorClass( "the index of a constraint cannot be negative." );

		if (this->con == NULL) 
			nopt = 0;
		else
			nopt = this->numberOfCon;
	
		InitConValue** temp = new InitConValue*[nopt+1];  //Allocate the new pointers
		for (i = 0; i < nopt; i++)
			temp[i] = this->con[i];  //copy the pointers

		delete[] this->con; //delete old pointers
	
//	add in the new element
		temp[ nopt] = new InitConValue();

		temp[ nopt]->idx = idx;
		temp[ nopt]->value = value;

		this->con = temp;   //hook the new pointers into the data structure
		this->numberOfCon = ++nopt;

		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//addCon

/**
 *
 * A function to set an array of <con> elements 
 * @param numberOfCon: number of <con> elements to be set
 * @param con: the array of <con> elements that are to be set
 */
bool InitDualVariableValues::setCon(int numberOfCon, InitDualVarValue **con)
{	try
	{	if (this->con != NULL)
			throw ErrorClass( "InitDualVarValue array previously used.");
		
		if (numberOfCon < 0)
			throw ErrorClass( "length of con array cannot be negative.");

		this->numberOfCon = numberOfCon;
		if (numberOfCon == 0)
			return true;

		this->con = new InitDualVarValue*[numberOfCon];
	 
		int  i;
		for (i = 0; i < numberOfCon; i++)
		{	 this->con[i] = new InitDualVarValue();
			*this->con[i] = *con[i];
		}
		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//setCon

bool InitDualVariableValues::setCon(int numberOfCon, int *idx, double *lbValue, double *ubValue, std::string *name)
{	
	if (this->con != NULL)
		return false;
		
	if (numberOfCon < 0)
		return false;

	this->numberOfCon = numberOfCon;
	if (numberOfCon == 0)
		return true;

	this->con = new InitDualVarValue*[numberOfCon];
	 
	int  i;
	for (i = 0; i < numberOfCon; i++)
	{
		this->con[i] = new InitDualVarValue();
		this->con[i]->idx = idx[i];
		this->con[i]->name = name[i];
		this->con[i]->lbDualValue = lbValue[i];
		this->con[i]->ubDualValue = ubValue[i];
	}
	return true;
}//setCon


/**
 *
 * A function to add a <con> element
 * @param idx: the index of the constraint to be given initial dual variable bounds 
 * @param lbValue: an initial lower bound for the dual variable 
 * @param ubValue: an initial upper bound for the dual variable 
 */
bool InitDualVariableValues::addCon(int idx, double lbDualValue, double ubDualValue)
{	try
	{	int nopt; int i;
		if (idx < 0)
			throw ErrorClass( "the index of a constraint cannot be negative." );

		if (this->con == NULL) 
			nopt = 0;
		else
			nopt = this->numberOfCon;
	
		InitDualVarValue** temp = new InitDualVarValue*[nopt+1];  //Allocate the new pointers
		for (i = 0; i < nopt; i++)
			temp[i] = this->con[i];  //copy the pointers

		delete[] this->con; //delete old pointers
	
//	add in the new element
		temp[ nopt] = new InitDualVarValue();

		temp[ nopt]->idx = idx;
		temp[ nopt]->lbDualValue = lbDualValue;
		temp[ nopt]->ubDualValue = ubDualValue;

		this->con = temp;   //hook the new pointers into the data structure
		this->numberOfCon = ++nopt;

		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//addCon

/**
 *
 * A function to set an array of <con> elements 
 * @param numberOfCon: number of <con> elements to be set
 * @param obj: the array of <con> elements that are to be set
 */
bool OtherConstraintOption::setCon(int numberOfCon, OtherConOption **con)
{	try
	{	if (this->con != NULL)
			throw ErrorClass( "OtherConOption array previously used.");
		
		if (numberOfCon < 0)
			throw ErrorClass( "length of <con> array cannot be negative.");

		this->numberOfCon = numberOfCon;
		if (numberOfCon == 0)
			return true;

		this->con = new OtherConOption*[numberOfCon];
	 
		int  i;
		for (i = 0; i < numberOfCon; i++)
		{	 this->con[i] = new OtherConOption();
			*this->con[i] = *con[i];
		}
		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//setCon

/**
 *
 * A function to add a <con> element
 * @param idx: the index of the constraint 
 * @param value: the value associated with this constraint 
 * @param lbValue: a lower bound associated with this constraint 
 * @param ubValue: an upper bound associated with this constraint 
 */
bool OtherConstraintOption::addCon(int idx, std::string value, std::string lbValue, std::string ubValue)
{	try
	{	int nopt; int i;
		if (idx < 0)
			throw ErrorClass( "the index of a variable cannot be negative." );

		if (this->con == NULL) 
			nopt = 0;
		else
			nopt = this->numberOfCon;
	
		OtherConOption** temp = new OtherConOption*[nopt+1];  //Allocate the new pointers
		for (i = 0; i < nopt; i++)
			temp[i] = this->con[i];  //copy the pointers

		delete[] this->con; //delete old pointers
	
//	add in the new element
		temp[ nopt] = new OtherConOption();

		temp[ nopt]->idx = idx;
		temp[ nopt]->value = value;
		temp[ nopt]->lbValue = lbValue;
		temp[ nopt]->ubValue = ubValue;

		this->con = temp;   //hook the new pointers into the data structure
		this->numberOfCon = ++nopt;

		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//addCon

/**
 *
 * A function to set an array of <other> elements
 * @param numberOfOptions: number of <other> elements to be set
 * @param other: the array of <other> elements that are to be set
 */
bool ConstraintOption::setOther(int numberOfOptions, OtherConstraintOption  **other)
{	try
	{	if (this->other != NULL)
			throw ErrorClass( "otherConstraintOptions array previously used.");
		
		if (numberOfOptions < 0)
			throw ErrorClass( "length of <other> array cannot be negative.");

		this->numberOfOtherConstraintOptions = numberOfOptions;
		if (numberOfOptions == 0)
			return true;

		this->other = new OtherConstraintOption*[numberOfOptions];
	 
		int  i, j;
		for (i = 0; i < numberOfOptions; i++)
		{	this->other[i] = new OtherConstraintOption();
			this->other[i]->name        = other[i]->name;
			this->other[i]->value       = other[i]->value;
			this->other[i]->solver      = other[i]->solver;
			this->other[i]->category    = other[i]->category;
			this->other[i]->type        = other[i]->type;
			this->other[i]->description = other[i]->description;

			if (other[i]->numberOfCon < 0)
				throw ErrorClass( "the number of constraints in otherConstraintOption cannot be negative.");

			this->other[i]->numberOfCon = other[i]->numberOfCon;

			if (other[i]->numberOfCon > 0) 
			{
				this->other[i]->con = new OtherConOption*[other[i]->numberOfCon];
				for (j = 0; j < other[i]->numberOfCon; j++)
				{	 this->other[i]->con[j] = new OtherConOption();
					*this->other[i]->con[j] = *other[i]->con[j];
				}
			}

			this->other[i]->numberOfEnumerations = other[i]->numberOfEnumerations;

			if (this->other[i]->numberOfEnumerations > 0)
			{	
				this->other[i]->enumeration = new OtherOptionEnumeration*[this->other[i]->numberOfEnumerations];
				for (j = 0; j < this->other[i]->numberOfEnumerations; j++)
				{
					this->other[i]->enumeration[j]  = new OtherOptionEnumeration();
					this->other[i]->enumeration[j]->setOtherOptionEnumeration(
						other[i]->enumeration[j]->value, 
						other[i]->enumeration[j]->description, 
						other[i]->enumeration[j]->el, 
						other[i]->enumeration[j]->numberOfEl);
				}
			}

		}
		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//setOther

/**
 *
 * A function to add an <other> element
 * @param other: the content of the <other> element to be added
 */
bool ConstraintOption::addOther(OtherConstraintOption *other)
{	try
	{	int nopt, i, j;
		if (this->other == NULL) 
			nopt = 0;
		else
			nopt = this->numberOfOtherConstraintOptions;
	
		OtherConstraintOption** temp = new OtherConstraintOption*[nopt+1];  //Allocate the new pointers
		for (i = 0; i < nopt; i++)
			temp[i] = this->other[i];  //copy the pointers

		delete[] this->other; //delete old pointers
	
//	add in the new element
	 temp[ nopt] = new OtherConstraintOption();
		temp[ nopt]->name        = other->name;
		temp[ nopt]->value       = other->value;
		temp[ nopt]->solver      = other->solver;
		temp[ nopt]->category    = other->category;
		temp[ nopt]->type        = other->type;
		temp[ nopt]->description = other->description;

		if (other->numberOfCon < 0)
			throw ErrorClass( "the number of constraints in otherConstraintOption cannot be negative.");

		temp[ nopt]->numberOfCon = other->numberOfCon;
		temp[ nopt]->numberOfEnumerations = other->numberOfEnumerations;

		if (other->numberOfCon > 0)
		{	
			temp[ nopt]->con = new OtherConOption*[other->numberOfCon];
			for (j = 0; j < other->numberOfCon; j++)
			{
				 temp[ nopt]->con[j] = new OtherConOption();
				*temp[ nopt]->con[j] = *other->con[j];
			}
		}

		if (other->numberOfEnumerations < 0)
			throw ErrorClass( "the number of enumerations in otherObjectiveOption cannot be negative.");

		if (other->numberOfEnumerations > 0)
		{	
			temp[ nopt]->enumeration = new OtherOptionEnumeration*[other->numberOfEnumerations];
			for (j = 0; j < other->numberOfEnumerations; j++)
			{
				temp[ nopt]->enumeration[j]  = new OtherOptionEnumeration();
				temp[ nopt]->enumeration[j]->setOtherOptionEnumeration(
					other->enumeration[j]->value, 
					other->enumeration[j]->description, 
					other->enumeration[j]->el, 
					other->enumeration[j]->numberOfEl);
			}
		}

		this->other = temp;   //hook the new pointers into the data structure
		this->numberOfOtherConstraintOptions = ++nopt;

		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//addOther

/**
 *
 * A function to set an array of solver options
 * @param numberOfOptions: number of solver options to be set
 * @param solverOption: the array of solver options that are to be set
 */
bool SolverOptions::setSolverOptions(int numberOfOptions, SolverOption **solverOption)
{	try
	{	if (this->solverOption != NULL)
			throw ErrorClass( "solverOptions array previously used.");
		
		if (numberOfOptions < 0)
			throw ErrorClass( "length of <solverOption> array cannot be negative.");

		this->numberOfSolverOptions = numberOfOptions;
		if (numberOfOptions == 0)
			return true;

		this->solverOption = new SolverOption*[numberOfOptions];
	 
		int  i;
		for (i = 0; i < numberOfOptions; i++)
		{
			this->solverOption[i] = new SolverOption();

			this->solverOption[i]->numberOfItems = solverOption[i]->numberOfItems;
			this->solverOption[i]->name = solverOption[i]->name;
			this->solverOption[i]->value = solverOption[i]->value;
			this->solverOption[i]->solver = solverOption[i]->solver;
			this->solverOption[i]->category = solverOption[i]->category;
			this->solverOption[i]->type = solverOption[i]->type;
			this->solverOption[i]->description = solverOption[i]->description;

			if (solverOption[i]->numberOfItems > 0)
			{
				this->solverOption[i]->item = new std::string[solverOption[i]->numberOfItems];
				for (int j=0; j<solverOption[i]->numberOfItems; j++)
					this->solverOption[i]->item[j] = solverOption[i]->item[j];
			}
		}
		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//setSolverOption

/**
 *
 * A function to add a solver option
 * @param name: the name of the solver option (required) 
 * @param value: a value associated with the option (optional) 
 * @param solver: the solver to which the option applies (optional) 
 * @param category: the category (and subcategories) of the option (optional) 
 * @param type: the type of the option (optional) 
 * @param description: a description associated with the option (optional) 
 */
bool SolverOptions::addSolverOption(std::string name, std::string value, std::string solver, 
		 std::string category, std::string type, std::string description)
{	try
	{
		int nopt; int i;
		if (name.empty() )
			throw ErrorClass( "the name of a solver option cannot be empty." );

		if (this->solverOption == NULL) 
			nopt = 0;
		else
			nopt = this->numberOfSolverOptions;
	
		SolverOption** temp = new SolverOption*[nopt+1];  //Allocate the new pointers
		for (i = 0; i < nopt; i++)
			temp[i] = this->solverOption[i];  //copy the pointers

		delete[] this->solverOption; //delete old pointers
	
//	add in the new element
		temp[ nopt] = new SolverOption();

		temp[ nopt]->numberOfItems = 0;
		temp[ nopt]->name = name;
		temp[ nopt]->value = value;
		temp[ nopt]->solver = solver;
		temp[ nopt]->type = type;
		temp[ nopt]->category = category;
		temp[ nopt]->description = description;

		this->solverOption = temp;   //hook the new pointers into the data structure
		this->numberOfSolverOptions = ++nopt;

		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//addSolverOption

/** 
 *  set option header
 */
	
bool OSOption::setOptionHeader(std::string name, std::string source, 
		           std::string description, std::string fileCreator, std::string licence)
{
	if (this->optionHeader == NULL) 
		this->optionHeader = new GeneralFileHeader();
	return this->optionHeader->setHeader(name, source, description, fileCreator, licence);
}// end of OSOption::setOptionHeader

/** 
 *  set() options in the <general> element
 */

bool OSOption::setServiceURI( std::string serviceURI)
{
	if (this->general == NULL) 
		this->general = new GeneralOption();
	this->general->serviceURI = serviceURI;
	return true;
}//setServiceURI

bool OSOption::setServiceName( std::string serviceName)
{
	if (this->general == NULL) 
		this->general = new GeneralOption();
	this->general->serviceName = serviceName;
	return true;
}//setServiceName

bool OSOption::setInstanceName( std::string instanceName)
{
	if (this->general == NULL) 
		this->general = new GeneralOption();
	this->general->instanceName = instanceName;
	return true;
}//setInstanceName

bool OSOption::setInstanceLocation( std::string instanceLocation)
{
	if (this->general == NULL) 
		this->general = new GeneralOption();
	if (this->general->instanceLocation == NULL) 
		this->general->instanceLocation = new InstanceLocationOption();
	this->general->instanceLocation->value = instanceLocation;
	return true;
}//setInstanceLocation

bool OSOption::setInstanceLocation( std::string instanceLocation, std::string locationType)
{
	if (verifyLocationType(locationType) == 0)
		return false;

	if (this->general == NULL) 
		this->general = new GeneralOption();
	if (this->general->instanceLocation == NULL) 
		this->general->instanceLocation = new InstanceLocationOption();
	this->general->instanceLocation->value = instanceLocation;
	this->general->instanceLocation->locationType = locationType;
	return true;
}//setInstanceLocation

bool OSOption::setInstanceLocationType( std::string locationType)
{
	try
	{	if (this->general == NULL) 
			this->general = new GeneralOption();
		if (this->general->instanceLocation == NULL) 
			this->general->instanceLocation = new InstanceLocationOption();
		
		if (verifyLocationType(locationType) == 0)
			return false;

		this->general->instanceLocation->locationType = locationType;
		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//setLocationType

bool OSOption::setJobID( std::string jobID)
{
	if (this->general == NULL) 
		this->general = new GeneralOption();
	this->general->jobID = jobID;
	return true;
}//setJobID

bool OSOption::setSolverToInvoke( std::string solverToInvoke)
{
	if (this->general == NULL) 
		this->general = new GeneralOption();
	this->general->solverToInvoke = solverToInvoke;
	return true;
}//setSolverToInvoke

bool OSOption::setLicense( std::string license)
{
	if (this->general == NULL) 
		this->general = new GeneralOption();
	this->general->license = license;
	return true;
}//setLicense

bool OSOption::setUserName( std::string userName)
{
	if (this->general == NULL) 
		this->general = new GeneralOption();
	this->general->userName = userName;
	return true;
}//setUserName

bool OSOption::setPassword( std::string password)
{
	if (this->general == NULL) 
		this->general = new GeneralOption();
	this->general->password = password;
	return true;
}//setPassword

bool OSOption::setContact( std::string contact)
{
	if (this->general == NULL) 
		this->general = new GeneralOption();
	if (this->general->contact == NULL) 
		this->general->contact = new ContactOption();
	this->general->contact->value = contact;
	return true;
}//setContact

bool OSOption::setContact(std::string contact,std::string transportType)
{
	if (verifyTransportType(transportType) == 0)
		return false;

	if (this->general == NULL) 
		this->general = new GeneralOption();
	if (this->general->contact == NULL) 
		this->general->contact = new ContactOption();
	this->general->contact->value = contact;
	this->general->contact->transportType = transportType;
	return true;
}//setContact

bool OSOption::setContactTransportType( std::string transportType)
{
	try
	{	if (this->general == NULL) 
			this->general = new GeneralOption();
		if (this->general->contact == NULL) 
			this->general->contact = new ContactOption();
		
		if (verifyTransportType(transportType) == 0)
			throw ErrorClass( "transport type not recognized.");

		this->general->contact->transportType = transportType;
		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//setContactTransportType

bool OSOption::setOtherGeneralOptions(int numberOfOptions, OtherOption** other)
{
	if (this->general == NULL) 
		this->general = new GeneralOption();
	if (this->general->otherOptions == NULL) 
		this->general->otherOptions = new OtherOptions();
	else
	{	int i;
		for (i = 0; i < this->general->otherOptions->numberOfOtherOptions; i++)
			delete this->general->otherOptions->other[i];
		delete[] this->general->otherOptions->other;
		this->general->otherOptions->other = NULL;
	}
	return this->general->otherOptions->setOther(numberOfOptions, other);
}//setOtherGeneralOptions

bool OSOption::setAnOtherGeneralOption(std::string name, std::string value, std::string description)
{
	if (this->general == NULL) 
		this->general = new GeneralOption();
	if (this->general->otherOptions == NULL) 
		this->general->otherOptions = new OtherOptions();
	return this->general->otherOptions->addOther(name, value, description);
}//setAnOtherGeneralOption



/** 
 *  set() options in the <system> element
 */

bool OSOption::setMinDiskSpace(std::string unit, std::string description, double value)
{
	if (verifyStorageUnit(unit) == 0)
		return false;

	if (this->system == NULL) 
		this->system = new SystemOption();
	if (this->system->minDiskSpace == NULL)
		this->system->minDiskSpace = new StorageCapacity();
	this->system->minDiskSpace->unit = unit;
	this->system->minDiskSpace->value = value;
	this->system->minDiskSpace->description = description;
	return true;
}//setMinDiskSpace

bool OSOption::setMinDiskSpace(double value)
{	if (this->system == NULL) 
		this->system = new SystemOption();
	if (this->system->minDiskSpace == NULL)
		this->system->minDiskSpace = new StorageCapacity();
	this->system->minDiskSpace->value = value;
	return true;
}//setMinDiskSpace

bool OSOption::setMinDiskSpaceUnit(std::string unit)
{	try
	{	if (this->system == NULL) 
			this->system = new SystemOption();
		if (this->system->minDiskSpace == NULL)
			this->system->minDiskSpace = new StorageCapacity();
		
		if (verifyStorageUnit(unit) == 0)
			throw ErrorClass( "disk space unit not recognized.");

		this->system->minDiskSpace->unit = unit;
		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//setMinDiskSpaceUnit

bool OSOption::setMinMemorySize(std::string unit, std::string description, double value)
{
	if (verifyStorageUnit(unit) == 0)
		return false;

	if (this->system == NULL) 
		this->system = new SystemOption();
	if (this->system->minMemorySize == NULL)
		this->system->minMemorySize = new StorageCapacity();
	this->system->minMemorySize->unit = unit;
	this->system->minMemorySize->value = value;
	this->system->minMemorySize->description = description;
	return true;
}//setMinDiskSpace

bool OSOption::setMinMemorySize(double value)
{	if (this->system == NULL) 
		this->system = new SystemOption();
	if (this->system->minMemorySize == NULL)
		this->system->minMemorySize = new StorageCapacity();
	this->system->minMemorySize->value = value;
	return true;
}//setMinMemorySize

bool OSOption::setMinMemoryUnit(std::string unit)
{	try
	{	if (this->system == NULL) 
			this->system = new SystemOption();
		if (this->system->minMemorySize == NULL)
			this->system->minMemorySize = new StorageCapacity();
		
		if (verifyStorageUnit(unit) == 0)
			throw ErrorClass( "memory size unit not recognized.");

		this->system->minMemorySize->unit = unit;
		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//setMinMemoryUnit

bool OSOption::setMinCPUSpeed(double value)
{	if (this->system == NULL) 
		this->system = new SystemOption();
	if (this->system->minCPUSpeed == NULL)
		this->system->minCPUSpeed = new CPUSpeed();
	this->system->minCPUSpeed->value = value;
	return true;
}//setMinCPUSpeed

bool OSOption::setMinCPUSpeed(std::string unit, std::string description, double value)
{
	if (verifyCPUSpeedUnit(unit) == 0)
		return false;

	if (this->system == NULL) 
		this->system = new SystemOption();
	if (this->system->minCPUSpeed == NULL)
		this->system->minCPUSpeed = new CPUSpeed();
	this->system->minCPUSpeed->unit = unit;
	this->system->minCPUSpeed->value = value;
	this->system->minCPUSpeed->description = description;
	return true;
}//setMinCPUSpeed

bool OSOption::setMinCPUSpeedUnit(std::string unit)
{	try
	{	if (this->system == NULL) 
			this->system = new SystemOption();
		if (this->system->minCPUSpeed == NULL)
			this->system->minCPUSpeed = new CPUSpeed();
		
		if (verifyCPUSpeedUnit(unit) == 0)
			throw ErrorClass( "CPU speed unit not recognized.");

		this->system->minCPUSpeed->unit = unit;
		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//setMinCPUSpeedUnit

bool OSOption::setMinCPUNumber(int number)
{
	if (this->system == NULL) 
		this->system = new SystemOption();
	if (this->system->minCPUNumber == NULL) 
		this->system->minCPUNumber = new CPUNumber();
	this->system->minCPUNumber->value = number;
	return true;
}//setMinCPUNumber

bool OSOption::setMinCPUNumber(int number, std::string description)
{
	if (this->system == NULL) 
		this->system = new SystemOption();
	if (this->system->minCPUNumber == NULL) 
		this->system->minCPUNumber = new CPUNumber();
	this->system->minCPUNumber->value = number;
	this->system->minCPUNumber->description = description;
	return true;
}//setMinCPUNumber

bool OSOption::setOtherSystemOptions(int numberOfOptions, OtherOption** other)
{	if (this->system == NULL) 
		this->system = new SystemOption();
	if (this->system->otherOptions == NULL) 
		this->system->otherOptions = new OtherOptions();
	else
	{	int i;
		for (i = 0; i < this->system->otherOptions->numberOfOtherOptions; i++)
			delete this->system->otherOptions->other[i];
		delete[] this->system->otherOptions->other;
		this->system->otherOptions->other = NULL;
		this->system->otherOptions->numberOfOtherOptions = 0;
	}
	return this->system->otherOptions->setOther(numberOfOptions, other);
}//setOtherSystemOptions

bool OSOption::setAnOtherSystemOption(std::string name, std::string value, std::string description)
{	if (this->system == NULL) 
		this->system = new SystemOption();
	if (this->system->otherOptions == NULL) 
		this->system->otherOptions = new OtherOptions();
	return this->system->otherOptions->addOther(name, value, description);
}//setAnOtherSystemOption


/** 
 *  set() options in the <service> element
 */

bool OSOption::setServiceType( std::string serviceType)
{	try
	{	if (this->service == NULL) 
			this->service = new ServiceOption();
		
		if (verifyServiceType(serviceType) == 0)
			throw ErrorClass( "service type not recognized.");

		this->service->type = serviceType;
		return true;
 	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//setServiceType

bool OSOption::setOtherServiceOptions(int numberOfOptions, OtherOption** other)
{	if (this->service == NULL) 
		this->service = new ServiceOption();
	if (this->service->otherOptions == NULL) 
		this->service->otherOptions = new OtherOptions();
	else
	{	int i;
		for (i = 0; i < this->service->otherOptions->numberOfOtherOptions; i++)
			delete this->service->otherOptions->other[i];
		delete[] this->service->otherOptions->other;
		this->service->otherOptions->other = NULL;
	}
	return this->service->otherOptions->setOther(numberOfOptions, other);
}//setOtherServiceOptions

bool OSOption::setAnOtherServiceOption(std::string name, std::string value, std::string description)
{	if (this->service == NULL) 
		this->service = new ServiceOption();
	if (this->service->otherOptions == NULL) 
		this->service->otherOptions = new OtherOptions();
	return this->service->otherOptions->addOther(name, value, description);
}//setAnOtherServiceOption

/** 
 *  set() options in the <job> element
 */

bool OSOption::setMaxTime(double value)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->maxTime == NULL)
		this->job->maxTime = new TimeSpan();
	this->job->maxTime->value = value;
	return true;
}//setMaxTime

bool OSOption::setMaxTime(double value, std::string unit)
{
	if (verifyTimeUnit(unit) == 0)
		return false;

	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->maxTime == NULL)
		this->job->maxTime = new TimeSpan();
	this->job->maxTime->value = value;
	this->job->maxTime->unit = unit;
	return true;
}//setMaxTime

bool OSOption::setMaxTimeUnit(std::string unit)
{	try
	{	if (this->job == NULL) 
			this->job = new JobOption();
		if (this->job->maxTime == NULL)
			this->job->maxTime = new TimeSpan();
		
		if (verifyTimeUnit(unit) == 0)
			throw ErrorClass( "time unit not recognized.");

		this->job->maxTime->unit = unit;
		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
}//setMaxTimeUnit

bool OSOption::setRequestedStartTime(std::string time)
{	if (this->job == NULL) 
		this->job = new JobOption();
	this->job->requestedStartTime = time;
	return true;
}//setRequestedStartTime


bool OSOption::setJobDependencies(int numberOfDependencies, std::string* jobDependencies)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->dependencies == NULL) 
		this->job->dependencies = new JobDependencies();
	else 
		delete[] this->job->dependencies->jobID;
	this->job->dependencies->jobID = NULL;
	return this->job->dependencies->setJobID(numberOfDependencies, jobDependencies);
}//setJobDependencies

bool OSOption::setAnotherJobDependency(std::string jobID)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->dependencies == NULL) 
		this->job->dependencies = new JobDependencies();
	return this->job->dependencies->addJobID(jobID);
}//setAnotherJobDependency


bool OSOption::setRequiredDirectories(int numberOfPaths, std::string* paths)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->requiredDirectories == NULL) 
		this->job->requiredDirectories = new DirectoriesAndFiles();
	else
		delete[] this->job->requiredDirectories->path;
	this->job->requiredDirectories->path = NULL;
	return this->job->requiredDirectories->setPath(numberOfPaths, paths);
}//setRequiredDirectories

bool OSOption::setAnotherRequiredDirectory(std::string path)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->requiredDirectories == NULL) 
		this->job->requiredDirectories = new DirectoriesAndFiles();
	return this->job->requiredDirectories->addPath(path);
}//setAnotherRequiredDirectory


bool OSOption::setRequiredFiles(int numberOfPaths, std::string* paths)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->requiredFiles == NULL) 
		this->job->requiredFiles = new DirectoriesAndFiles();
	else
		delete[] this->job->requiredFiles->path;
	this->job->requiredFiles->path = NULL;
	return this->job->requiredFiles->setPath(numberOfPaths, paths);
}//setRequiredFiles

bool OSOption::setAnotherRequiredFile(std::string path)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->requiredFiles == NULL) 
		this->job->requiredFiles = new DirectoriesAndFiles();
	return this->job->requiredFiles->addPath(path);
}//setAnotherRequiredFile


bool OSOption::setDirectoriesToMake(int numberOfPaths, std::string* paths)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->directoriesToMake == NULL) 
		this->job->directoriesToMake = new DirectoriesAndFiles();
	else
		delete[] this->job->directoriesToMake->path;
	this->job->directoriesToMake->path = NULL;
	return this->job->directoriesToMake->setPath(numberOfPaths, paths);
}//setDirectoriesToMake

bool OSOption::setAnotherDirectoryToMake(std::string path)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->directoriesToMake == NULL) 
		this->job->directoriesToMake = new DirectoriesAndFiles();
	return this->job->directoriesToMake->addPath(path);
}//setAnotherDirectoryToMake


bool OSOption::setFilesToMake(int numberOfPaths, std::string* paths)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->filesToMake == NULL) 
		this->job->filesToMake = new DirectoriesAndFiles();
	else
		delete[] this->job->filesToMake->path;
	this->job->filesToMake->path = NULL;
	return this->job->filesToMake->setPath(numberOfPaths, paths);
}//setFilesToMake

bool OSOption::setAnotherFileToMake(std::string path)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->filesToMake == NULL) 
		this->job->filesToMake = new DirectoriesAndFiles();
	return this->job->filesToMake->addPath(path);
}//setAnotherFileToMake

bool OSOption::setPathPairs(int object, std::string *from, std::string *to, bool *makeCopy, int numberOfPathPairs)
{
	if (numberOfPathPairs < 0) return false;
	if (this->job == NULL) 
		this->job = new JobOption();
	switch (object)
	{
		case ENUM_PATHPAIR_input_dir:
		{
			if (this->job->inputDirectoriesToMove == NULL) 
				this->job->inputDirectoriesToMove = new PathPairs();
			return this->job->inputDirectoriesToMove->setPathPair(from, to, makeCopy, numberOfPathPairs);
		}
		case ENUM_PATHPAIR_input_file:
		{
			if (this->job->inputFilesToMove == NULL) 
				this->job->inputFilesToMove = new PathPairs();
			return this->job->inputFilesToMove->setPathPair(from, to, makeCopy, numberOfPathPairs);
		}
		case ENUM_PATHPAIR_output_file:
		{
			if (this->job->outputFilesToMove == NULL) 
				this->job->outputFilesToMove = new PathPairs();
			return this->job->outputFilesToMove->setPathPair(from, to, makeCopy, numberOfPathPairs);
		}
		case ENUM_PATHPAIR_output_dir:
		{
			if (this->job->outputDirectoriesToMove == NULL) 
				this->job->outputDirectoriesToMove = new PathPairs();
			return this->job->outputDirectoriesToMove->setPathPair(from, to, makeCopy, numberOfPathPairs);
		}
		default:
			throw ErrorClass("target object not implemented in setPathPairs");
	}

}//setPathPairs


bool OSOption::setInputDirectoriesToMove(int numberOfPathPairs, PathPair** pathPair)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->inputDirectoriesToMove == NULL) 
		this->job->inputDirectoriesToMove = new PathPairs();
	else
		delete[] this->job->inputDirectoriesToMove->pathPair;
	this->job->inputDirectoriesToMove->pathPair = NULL;
	return this->job->inputDirectoriesToMove->setPathPair(numberOfPathPairs, pathPair);
}//setInputDirectoriesToMove

bool OSOption::setAnotherInputDirectoryToMove(std::string fromPath, std::string toPath, bool makeCopy)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->inputDirectoriesToMove == NULL) 
		this->job->inputDirectoriesToMove = new PathPairs();
	return this->job->inputDirectoriesToMove->addPathPair(fromPath, toPath, makeCopy);
}//setAnotherInputDirectoryToMove


bool OSOption::setInputFilesToMove(int numberOfPathPairs, PathPair** pathPair)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->inputFilesToMove == NULL) 
		this->job->inputFilesToMove = new PathPairs();
	else
		delete[] this->job->inputFilesToMove->pathPair;
	this->job->inputFilesToMove->pathPair = NULL;
	return this->job->inputFilesToMove->setPathPair(numberOfPathPairs, pathPair);
}//setInputFilesToMove

bool OSOption::setAnotherInputFileToMove(std::string fromPath, std::string toPath, bool makeCopy)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->inputFilesToMove == NULL) 
		this->job->inputFilesToMove = new PathPairs();
	return this->job->inputFilesToMove->addPathPair(fromPath, toPath, makeCopy);
}//setAnotherInputFileToMove


bool OSOption::setOutputFilesToMove(int numberOfPathPairs, PathPair** pathPair)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->outputFilesToMove == NULL) 
		this->job->outputFilesToMove = new PathPairs();
	else
		delete[] this->job->outputFilesToMove->pathPair;
	this->job->outputFilesToMove->pathPair = NULL;
	return this->job->outputFilesToMove->setPathPair(numberOfPathPairs, pathPair);
}//setOutputFilesToMove

bool OSOption::setAnotherOutputFileToMove(std::string fromPath, std::string toPath, bool makeCopy)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->outputFilesToMove == NULL) 
		this->job->outputFilesToMove = new PathPairs();
	return this->job->outputFilesToMove->addPathPair(fromPath, toPath, makeCopy);
}//setAnotherOutputFileToMove


bool OSOption::setOutputDirectoriesToMove(int numberOfPathPairs, PathPair** pathPair)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->outputDirectoriesToMove == NULL) 
		this->job->outputDirectoriesToMove = new PathPairs();
	else
		delete[] this->job->outputDirectoriesToMove->pathPair;
	this->job->outputDirectoriesToMove->pathPair = NULL;
	return this->job->outputDirectoriesToMove->setPathPair(numberOfPathPairs, pathPair);
}//setOutputDirectoriesToMove

bool OSOption::setAnotherOutputDirectoryToMove(std::string fromPath, std::string toPath, bool makeCopy)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->outputDirectoriesToMove == NULL) 
		this->job->outputDirectoriesToMove = new PathPairs();
	return this->job->outputDirectoriesToMove->addPathPair(fromPath, toPath, makeCopy);
}//setAnotherOutputDirectoryToMove


bool OSOption::setFilesToDelete(int numberOfPaths, std::string* paths)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->filesToDelete == NULL) 
		this->job->filesToDelete = new DirectoriesAndFiles();
	else
		delete[] this->job->filesToDelete->path;
	this->job->filesToDelete->path = NULL;
	return this->job->filesToDelete->setPath(numberOfPaths, paths);
}//setFilesToDelete

bool OSOption::setAnotherFileToDelete(std::string path)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->filesToDelete == NULL) 
		this->job->filesToDelete = new DirectoriesAndFiles();
	return this->job->filesToDelete->addPath(path);
}//setAnotherFileToDelete


bool OSOption::setDirectoriesToDelete(int numberOfPaths, std::string* paths)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->directoriesToDelete == NULL) 
		this->job->directoriesToDelete = new DirectoriesAndFiles();
	else
		delete[] this->job->directoriesToDelete->path;
	this->job->directoriesToDelete->path = NULL;
	return this->job->directoriesToDelete->setPath(numberOfPaths, paths);
}//setDirectoriesToDelete

bool OSOption::setAnotherDirectoryToDelete(std::string path)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->directoriesToDelete == NULL) 
		this->job->directoriesToDelete = new DirectoriesAndFiles();
	return this->job->directoriesToDelete->addPath(path);
}//setAnotherDirectoryToDelete


bool OSOption::setProcessesToKill(int numberOfProcesses, std::string* processes)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->processesToKill == NULL) 
		this->job->processesToKill = new Processes();
	else
		delete[] this->job->processesToKill->process;
	this->job->processesToKill->process = NULL;
	return this->job->processesToKill->setProcess(numberOfProcesses, processes);
}//setProcessesToKill

bool OSOption::setAnotherProcessToKill(std::string process)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->processesToKill == NULL) 
		this->job->processesToKill = new Processes();
	return this->job->processesToKill->addProcess(process);
}//setAnotherProcessToKill


bool OSOption::setOtherJobOptions(int numberOfOptions, OtherOption** other)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->otherOptions == NULL) 
		this->job->otherOptions = new OtherOptions();
	else
	{	int i;
		for (i = 0; i < this->job->otherOptions->numberOfOtherOptions; i++)
			delete this->job->otherOptions->other[i];
		delete[] this->job->otherOptions->other;
		this->job->otherOptions->other = NULL;
	}
	return this->job->otherOptions->setOther(numberOfOptions, other);
}//setOtherJobOptions

bool OSOption::setAnOtherJobOption(std::string name, std::string value, std::string description)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->otherOptions == NULL) 
		this->job->otherOptions = new OtherOptions();
	return this->job->otherOptions->addOther(name, value, description);
}//setAnOtherJobOption



bool OSOption::setNumberOfVariables(int numberOfVariables)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	this->optimization->numberOfVariables = numberOfVariables;
	return true;
}//setNumberOfVariables

bool OSOption::setNumberOfObjectives(int numberOfObjectives)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	this->optimization->numberOfObjectives = numberOfObjectives;
	return true;
}//setNumberOfObjectives

bool OSOption::setNumberOfConstraints(int numberOfConstraints)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	this->optimization->numberOfConstraints = numberOfConstraints;
	return true;
}//setNumberOfConstraints


bool OSOption::setInitVarValues(int numberOfVar, int* idx, double* value, std::string* name)
{
	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL) 
		this->optimization->variables = new VariableOption();
	if (this->optimization->variables->initialVariableValues != NULL) 
		return false;

	this->optimization->variables->initialVariableValues = new InitVariableValues();

	return this->optimization->variables->initialVariableValues->setVar(numberOfVar, idx, value, name);
}//setInitVarValues


bool OSOption::setInitVarValuesSparse(int numberOfVar, InitVarValue** var)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL) 
		this->optimization->variables = new VariableOption();
	if (this->optimization->variables->initialVariableValues == NULL) 
		this->optimization->variables->initialVariableValues = new InitVariableValues();
	else
	{	int i;
		for (i = 0; i < this->optimization->variables->initialVariableValues->numberOfVar; i++)
			delete this->optimization->variables->initialVariableValues->var[i];
		delete[] this->optimization->variables->initialVariableValues->var;
		this->optimization->variables->initialVariableValues->var = NULL;
	}
	return this->optimization->variables->initialVariableValues->setVar(numberOfVar, var);
}//setInitVarValuesSparse

bool OSOption::setInitVarValuesDense(int numberOfVar, double *value)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL) 
		this->optimization->variables = new VariableOption();
	if (this->optimization->variables->initialVariableValues == NULL) 
		this->optimization->variables->initialVariableValues = new InitVariableValues();
	else
	{	delete[] this->optimization->variables->initialVariableValues->var;
		this->optimization->variables->initialVariableValues->var = NULL;
	}

	int i;
	for (i = 0; i < numberOfVar; i++)
	{	
//		if (!CoinIsnan(value[i]))
			if (!this->optimization->variables->initialVariableValues->addVar(i, value[i]))
				return false;
	}
	return true;
}//setInitVarValuesDense

bool OSOption::setAnotherInitVarValue(int idx, double value)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL) 
		this->optimization->variables = new VariableOption();
	if (this->optimization->variables->initialVariableValues == NULL) 
		this->optimization->variables->initialVariableValues = new InitVariableValues();
	return this->optimization->variables->initialVariableValues->addVar(idx, value);
}//setAnotherInitVarValue

bool OSOption::setInitVarValuesString(int numberOfVar, int* idx, std::string* value, std::string* name)
{
	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL) 
		this->optimization->variables = new VariableOption();
	if (this->optimization->variables->initialVariableValuesString != NULL) 
		return false;

	this->optimization->variables->initialVariableValuesString = new InitVariableValuesString();

	return this->optimization->variables->initialVariableValuesString->setVar(numberOfVar, idx, value, name);
}//setInitVarValuesString

bool OSOption::setInitVarValuesStringSparse(int numberOfVar, InitVarValueString** var)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL) 
		this->optimization->variables = new VariableOption();
	if (this->optimization->variables->initialVariableValuesString == NULL) 
		this->optimization->variables->initialVariableValuesString = new InitVariableValuesString();
	else
	{	int i;
		for (i = 0; i < this->optimization->variables->initialVariableValuesString->numberOfVar; i++)
			delete this->optimization->variables->initialVariableValuesString->var[i];
		delete[] this->optimization->variables->initialVariableValuesString->var;
		this->optimization->variables->initialVariableValuesString->var = NULL;
	}
	return this->optimization->variables->initialVariableValuesString->setVar(numberOfVar, var);
}//setInitVarValuesStringSparse

bool OSOption::setInitVarValuesStringDense(int numberOfVar, std::string *value)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL) 
		this->optimization->variables = new VariableOption();
	if (this->optimization->variables->initialVariableValuesString == NULL) 
		this->optimization->variables->initialVariableValuesString = new InitVariableValuesString();
	else
	{	delete[] this->optimization->variables->initialVariableValuesString->var;
		this->optimization->variables->initialVariableValuesString->var = NULL;
	}
	int i;
	for (i = 0; i < numberOfVar; i++)
	{	if (value[i] != "")
			if (!this->optimization->variables->initialVariableValuesString->addVar(i, value[i]))
				return false;
	}
		return true;
}//setInitVarValuesStringDense

bool OSOption::setAnotherInitVarValueString(int idx, std::string value)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL) 
		this->optimization->variables = new VariableOption();
	if (this->optimization->variables->initialVariableValuesString == NULL) 
		this->optimization->variables->initialVariableValuesString = new InitVariableValuesString();
	return this->optimization->variables->initialVariableValuesString->addVar(idx, value);
}//setAnotherInitVarValueString

bool OSOption::setInitBasisStatus(int object, int status, int *i, int ni)
{
	if (optimization == NULL) return false;

	switch (object) 
	{
		case ENUM_PROBLEM_COMPONENT_variables:
		{
			std::cout << "setInitBasisStatus: at line 7094" << std::endl;
			if (optimization->variables == NULL)
				optimization->variables = new VariableOption();
			std::cout << "setInitBasisStatus: at line 7097" << std::endl;
			std::cout << "optimization->variables->initialBasisStatus == NULL?" << std::endl;
			std::cout << (optimization->variables->initialBasisStatus == NULL)  << std::endl;
			if (optimization->variables->initialBasisStatus == NULL)
				optimization->variables->initialBasisStatus = new BasisStatus();
			std::cout << "setInitBasisStatus: at line 7102" << std::endl;

			for (int j=0; j<ni; j++) 
			{
				std::cout << "component " << j;
				std::cout << ": " << i[j] << std::endl;
				if (i[j] < 0) return false;
			}
			std::cout << "setInitBasisStatus: at line 7105" << std::endl;
			std::cout << "parameter 1: " << status << std::endl;
			std::cout << "parameter 2: " << i      << std::endl;
			std::cout << "parameter 3: " << ni     << std::endl;
			return optimization->variables->initialBasisStatus->setIntVector(status, i, ni);
		}
		case ENUM_PROBLEM_COMPONENT_objectives:	
		{
			if (optimization->objectives == NULL)
				optimization->objectives = new ObjectiveOption();
			if (optimization->objectives->initialBasisStatus == NULL)
				optimization->objectives->initialBasisStatus = new BasisStatus();
			for (int j=0; j<ni; j++) if (i[j] >= 0) return false;
			return optimization->objectives->initialBasisStatus->setIntVector(status, i, ni);
		}
		case ENUM_PROBLEM_COMPONENT_constraints:	
		{
			if (optimization->constraints == NULL)
				optimization->constraints = new ConstraintOption();
			if (optimization->constraints->initialBasisStatus == NULL)
				optimization->constraints->initialBasisStatus = new BasisStatus();
			for (int j=0; j<ni; j++) if (i[j] < 0) return false;
			return optimization->constraints->initialBasisStatus->setIntVector(status, i, ni);
		}
		default: 
			throw ErrorClass("target object not implemented in setInitBasisStatus");
	}
}//setInitBasisStatus

bool OSOption::setAnotherInitBasisStatus(int object, int idx, int status)
{
	if (optimization == NULL) return false;

	switch (object) 
	{
		case ENUM_PROBLEM_COMPONENT_variables:
		{
			if (optimization->variables == NULL)
				optimization->variables = new VariableOption();
			if (optimization->variables->initialBasisStatus == NULL)
				optimization->variables->initialBasisStatus = new BasisStatus();
			if (idx < 0) return false;
			return optimization->variables->initialBasisStatus->addIdx(status, idx);
		}
		case ENUM_PROBLEM_COMPONENT_objectives:	
		{
			if (optimization->objectives == NULL)
				optimization->objectives = new ObjectiveOption();
			if (optimization->objectives->initialBasisStatus == NULL)
				optimization->objectives->initialBasisStatus = new BasisStatus();
			if (idx >= 0) return false;
			return optimization->objectives->initialBasisStatus->addIdx(status, idx);
		}
		case ENUM_PROBLEM_COMPONENT_constraints:	
		{
			if (optimization->constraints == NULL)
				optimization->constraints = new ConstraintOption();
			if (optimization->constraints->initialBasisStatus == NULL)
				optimization->constraints->initialBasisStatus = new BasisStatus();
			if (idx < 0) return false;
			return optimization->constraints->initialBasisStatus->addIdx(status, idx);
		}
		default: 
			throw ErrorClass("target object not implemented in setAnotherInitBasisStatus");
	}
}//setAnotherInitBasisStatus

bool OSOption::setIntegerVariableBranchingWeights(int numberOfVar, int* idx, double* value, std::string* name)
{
	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL) 
		this->optimization->variables = new VariableOption();
	if (this->optimization->variables->integerVariableBranchingWeights != NULL) 
		return false;

	this->optimization->variables->integerVariableBranchingWeights = new IntegerVariableBranchingWeights();

	return this->optimization->variables->integerVariableBranchingWeights->setVar(numberOfVar, idx, value, name);
}//setIntegerVariableBranchingWeights

bool OSOption::setIntegerVariableBranchingWeightsSparse(int numberOfVar, BranchingWeight** var)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL) 
		this->optimization->variables = new VariableOption();
	if (this->optimization->variables->integerVariableBranchingWeights == NULL) 
		this->optimization->variables->integerVariableBranchingWeights = new IntegerVariableBranchingWeights();
	else
	{	int i;
		for (i = 0; i < this->optimization->variables->integerVariableBranchingWeights->numberOfVar; i++)
			delete this->optimization->variables->integerVariableBranchingWeights->var[i];
		delete[] this->optimization->variables->integerVariableBranchingWeights->var;
		this->optimization->variables->integerVariableBranchingWeights->var = NULL;
	}
	return this->optimization->variables->integerVariableBranchingWeights->setVar(numberOfVar, var);
}//setIntegerVariableBranchingWeightsSparse

bool OSOption::setIntegerVariableBranchingWeightsDense(int numberOfVar, double *value)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL) 
		this->optimization->variables = new VariableOption();
	if (this->optimization->variables->integerVariableBranchingWeights == NULL) 
		this->optimization->variables->integerVariableBranchingWeights = new IntegerVariableBranchingWeights();
	else
	{	delete[] this->optimization->variables->integerVariableBranchingWeights->var;
		this->optimization->variables->integerVariableBranchingWeights->var = NULL;
	}
	int i;
	for (i = 0; i < numberOfVar; i++)
	{
//		if (!CoinIsnan(value[i]))
			if (!this->optimization->variables->integerVariableBranchingWeights->addVar(i, value[i]))
				return false;
	}
	return true;
}//setIntegerVariableBranchingWeightsDense

bool OSOption::setAnotherIntegerVariableBranchingWeight(int idx, double value)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL) 
		this->optimization->variables = new VariableOption();
	if (this->optimization->variables->integerVariableBranchingWeights == NULL) 
		this->optimization->variables->integerVariableBranchingWeights = new IntegerVariableBranchingWeights();
	return this->optimization->variables->integerVariableBranchingWeights->addVar(idx, value);
}//setAnotherIntegerVariableBranchingWeight


bool OSOption::setSOSVariableBranchingWeights(int numberOfSOS, SOSWeights** sos)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL) 
		this->optimization->variables = new VariableOption();
	if (this->optimization->variables->sosVariableBranchingWeights == NULL) 
		this->optimization->variables->sosVariableBranchingWeights = new SOSVariableBranchingWeights();
	else
	{	int i;
		for (i = 0; i < this->optimization->variables->sosVariableBranchingWeights->numberOfSOS; i++)
			delete this->optimization->variables->sosVariableBranchingWeights->sos[i];
		delete[] this->optimization->variables->sosVariableBranchingWeights->sos;
		this->optimization->variables->sosVariableBranchingWeights->sos = NULL;
	}
	return this->optimization->variables->sosVariableBranchingWeights->setSOS(numberOfSOS, sos);
}//setSOSVariableBranchingWeights

bool OSOption::setAnotherSOSVariableBranchingWeight(int sosIdx, int nvar, double weight, int* idx, double* value, std::string* name)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL) 
		this->optimization->variables = new VariableOption();
	if (this->optimization->variables->sosVariableBranchingWeights == NULL) 
		this->optimization->variables->sosVariableBranchingWeights = new SOSVariableBranchingWeights();
	return this->optimization->variables->sosVariableBranchingWeights->addSOS(sosIdx, nvar, weight, idx, value, name);
}//setAnotherSOSVariableBranchingWeight

bool OSOption::setNumberOfOtherVariableOptions(int numberOfOther)
{
	if (optimization == NULL) return false;
	if (optimization->variables == NULL) 
		optimization->variables = new VariableOption();
	if(optimization->variables->numberOfOtherVariableOptions < 0) return false;

	optimization->variables->numberOfOtherVariableOptions = numberOfOther;
	
	if (numberOfOther > 0)
	{
		optimization->variables->other = new OtherVariableOption*[numberOfOther];

		for (int j=0; j < numberOfOther; j++)
			optimization->variables->other[j] = new OtherVariableOption();
	}

	return true;
}//setNumberOfOtherVariableOptions

bool OSOption::setOtherVariableOptionAttributes(int iOther, int numberOfVar,
				int numberOfEnumerations, std::string name,
				std::string value, std::string solver,
				std::string category, std::string type,
				std::string description)
{
	if (optimization == NULL) return false;
	if (optimization->variables == NULL) return false;
	if (optimization->variables->other == NULL) return false;

	if (iOther < 0 || iOther >= optimization->variables->numberOfOtherVariableOptions) return false;
		
	optimization->variables->other[iOther]->numberOfVar          = numberOfVar;
	optimization->variables->other[iOther]->numberOfEnumerations = numberOfEnumerations;
	optimization->variables->other[iOther]->name                 = name;
	optimization->variables->other[iOther]->value                = value;
	optimization->variables->other[iOther]->solver               = solver;
	optimization->variables->other[iOther]->category             = category;
	optimization->variables->other[iOther]->type                 = type;
	optimization->variables->other[iOther]->description          = description;

	if (numberOfVar > 0)
	{
		optimization->variables->other[iOther]->var = new OtherVarOption*[numberOfVar];
		for (int j=0; j<numberOfVar; j++) 
			optimization->variables->other[iOther]->var[j] = new OtherVarOption();
	}

	if (numberOfEnumerations > 0)
	{
		optimization->variables->other[iOther]->enumeration = new OtherOptionEnumeration*[numberOfEnumerations];
		for (int j=0; j<numberOfEnumerations; j++) 
			optimization->variables->other[iOther]->enumeration[j] = new OtherOptionEnumeration();
	}
	return true;
}//setOtherVariableOptionAttributes

bool OSOption::setOtherOptionEnumeration(int object, int otherOptionNumber, int enumerationNumber,
			int numberOfEl, std::string value, std::string description, int* idxArray)
{
	if (optimization == NULL) return false;
	if (numberOfEl < 0) return false;

	switch (object) 
	{
		case ENUM_PROBLEM_COMPONENT_variables:
		{
			if (optimization->variables == NULL) return false;
			if (optimization->variables->other == NULL) return false;
			if (otherOptionNumber < 0 || otherOptionNumber >= optimization->variables->numberOfOtherVariableOptions) return false;
			if (optimization->variables->other[otherOptionNumber] == NULL) return false;
			for (int j=0; j<numberOfEl; j++) if (idxArray[j] < 0) return false;

			if (optimization->variables->other[otherOptionNumber]->enumeration == NULL) return false;
			if (enumerationNumber < 0 || enumerationNumber >= optimization->variables->other[otherOptionNumber]->numberOfEnumerations) return false;
			if (optimization->variables->other[otherOptionNumber]->enumeration[enumerationNumber] == NULL) return false; 

			return optimization->variables->other[otherOptionNumber]->enumeration[enumerationNumber]->setOtherOptionEnumeration(value, description, idxArray, numberOfEl);
		}

		case ENUM_PROBLEM_COMPONENT_objectives:
		{
			if (optimization->objectives == NULL) return false;
			if (optimization->objectives->other == NULL) return false;
			if (otherOptionNumber < 0 || otherOptionNumber >= optimization->objectives->numberOfOtherObjectiveOptions) return false;
			if (optimization->objectives->other[otherOptionNumber] == NULL) return false;
			for (int j=0; j<numberOfEl; j++) if (idxArray[j] >= 0) return false;

			if (optimization->objectives->other[otherOptionNumber]->enumeration == NULL) return false;
			if (enumerationNumber < 0 || enumerationNumber >= optimization->objectives->other[otherOptionNumber]->numberOfEnumerations) return false;
			if (optimization->objectives->other[otherOptionNumber]->enumeration[enumerationNumber] == NULL) return false; 

			return optimization->objectives->other[otherOptionNumber]->enumeration[enumerationNumber]->setOtherOptionEnumeration(value, description, idxArray, numberOfEl);
		}

		case ENUM_PROBLEM_COMPONENT_constraints:
		{
			if (optimization->constraints == NULL) return false;
			if (optimization->constraints->other == NULL) return false;
			if (otherOptionNumber < 0 || otherOptionNumber >= optimization->constraints->numberOfOtherConstraintOptions) return false;
			if (optimization->constraints->other[otherOptionNumber] == NULL) return false;
			for (int j=0; j<numberOfEl; j++) if (idxArray[j] < 0) return false;

			if (optimization->constraints->other[otherOptionNumber]->enumeration == NULL) return false;
			if (enumerationNumber < 0 || enumerationNumber >= optimization->constraints->other[otherOptionNumber]->numberOfEnumerations) return false;
			if (optimization->constraints->other[otherOptionNumber]->enumeration[enumerationNumber] == NULL) return false; 

			return optimization->constraints->other[otherOptionNumber]->enumeration[enumerationNumber]->setOtherOptionEnumeration(value, description, idxArray, numberOfEl);
		}
		default:
			throw ErrorClass("target object not implemented in setOtherOptionEnumeration");
	}

}//setOtherOptionEnumeration

bool OSOption::setOtherVariableOptionVar(int otherOptionNumber, int varNumber,
			int idx, std::string name, std::string value, std::string lbValue, std::string ubValue)
{
	if (optimization == NULL) return false;

	if (optimization->variables == NULL) return false;
	if (optimization->variables->other == NULL) return false;
	if (otherOptionNumber < 0 || otherOptionNumber >= optimization->variables->numberOfOtherVariableOptions) return false;
	if (optimization->variables->other[otherOptionNumber] == NULL) return false;
	if (idx < 0) return false;

	if (optimization->variables->other[otherOptionNumber]->var == NULL) return false;
	if (varNumber < 0 || varNumber >= optimization->variables->other[otherOptionNumber]->numberOfVar) return false;
	if (optimization->variables->other[otherOptionNumber]->var[varNumber] == NULL) return false; 

	optimization->variables->other[otherOptionNumber]->var[varNumber]->idx = idx;
	optimization->variables->other[otherOptionNumber]->var[varNumber]->name = name;
	optimization->variables->other[otherOptionNumber]->var[varNumber]->value = value;
	optimization->variables->other[otherOptionNumber]->var[varNumber]->lbValue = lbValue;
	optimization->variables->other[otherOptionNumber]->var[varNumber]->ubValue = ubValue;
	return true;
}//setOtherVariableOptionVar


bool OSOption::setOtherVariableOptions(int numberOfOptions, OtherVariableOption** other)
{	if (this->optimization == NULL)
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL)
		this->optimization->variables = new VariableOption();
	else
	{	int i;
		for (i = 0; i < this->optimization->variables->numberOfOtherVariableOptions; i++)
			delete this->optimization->variables->other[i];
		delete[] this->optimization->variables->other;
		this->optimization->variables->other = NULL;
	}
	return this->optimization->variables->setOther(numberOfOptions, other);
}//setOtherVariableOptions

bool OSOption::setAnOtherVariableOption(OtherVariableOption* optionValue)
{	if (this->optimization == NULL)
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL)
		this->optimization->variables = new VariableOption();
	return this->optimization->variables->addOther(optionValue);
}//setAnOtherVariableOption

bool OSOption::setInitObjValues(int numberOfObj, int* idx, double* value, std::string* name)
{
	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->objectives == NULL) 
		this->optimization->objectives = new ObjectiveOption();
	if (this->optimization->objectives->initialObjectiveValues != NULL) 
		return false;

	this->optimization->objectives->initialObjectiveValues = new InitObjectiveValues();

	return this->optimization->objectives->initialObjectiveValues->setObj(numberOfObj, idx, value, name);
}//setInitObjValues

bool OSOption::setInitObjValuesSparse(int numberOfObj, InitObjValue** obj)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->objectives == NULL) 
		this->optimization->objectives = new ObjectiveOption();
	if (this->optimization->objectives->initialObjectiveValues == NULL) 
		this->optimization->objectives->initialObjectiveValues = new InitObjectiveValues();
	else
	{	int i;
		for (i = 0; i < this->optimization->objectives->initialObjectiveValues->numberOfObj; i++)
			delete this->optimization->objectives->initialObjectiveValues->obj[i];
		delete[] this->optimization->objectives->initialObjectiveValues->obj;
		this->optimization->objectives->initialObjectiveValues->obj = NULL;
	}
	return this->optimization->objectives->initialObjectiveValues->setObj(numberOfObj, obj);
}//setInitObjValuesSparse

bool OSOption::setInitObjValuesDense(int numberOfObj, double *value)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->objectives == NULL) 
		this->optimization->objectives = new ObjectiveOption();
	if (this->optimization->objectives->initialObjectiveValues == NULL) 
		this->optimization->objectives->initialObjectiveValues = new InitObjectiveValues();
	else
	{	delete[] this->optimization->objectives->initialObjectiveValues->obj;
		this->optimization->objectives->initialObjectiveValues->obj = NULL;
	}
	int i;
	for (i = 0; i < numberOfObj; i++)
	{
//		if (!CoinIsnan(value[i]))
			if (!this->optimization->objectives->initialObjectiveValues->addObj(-1-i, value[i]))
				return false;
	}
	return true;
}//setInitObjValuesDense

bool OSOption::setAnotherInitObjValue(int idx, double value)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->objectives == NULL) 
		this->optimization->objectives = new ObjectiveOption();
	if (this->optimization->objectives->initialObjectiveValues == NULL) 
		this->optimization->objectives->initialObjectiveValues = new InitObjectiveValues();
	return this->optimization->objectives->initialObjectiveValues->addObj(idx, value);
}//setAnotherInitObjValue

bool OSOption::setInitObjBounds(int numberOfObj, int* idx, double* lbValue, double* ubValue, std::string* name)
{
	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->objectives == NULL) 
		this->optimization->objectives = new ObjectiveOption();
	if (this->optimization->objectives->initialObjectiveBounds != NULL) 
		return false;

	this->optimization->objectives->initialObjectiveBounds = new InitObjectiveBounds();

	return this->optimization->objectives->initialObjectiveBounds->setObj(numberOfObj, idx, lbValue, ubValue, name);
}//setInitObjBounds

bool OSOption::setInitObjBoundsSparse(int numberOfObj, InitObjBound** obj)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->objectives == NULL) 
		this->optimization->objectives = new ObjectiveOption();
	if (this->optimization->objectives->initialObjectiveBounds == NULL) 
		this->optimization->objectives->initialObjectiveBounds = new InitObjectiveBounds();
	else
	{	int i;
		for (i = 0; i < this->optimization->objectives->initialObjectiveBounds->numberOfObj; i++)
			delete this->optimization->objectives->initialObjectiveBounds->obj[i];
		delete[] this->optimization->objectives->initialObjectiveBounds->obj;
		this->optimization->objectives->initialObjectiveBounds->obj = NULL;
	}
	return this->optimization->objectives->initialObjectiveBounds->setObj(numberOfObj, obj);
}//setInitObjBoundsSparse

bool OSOption::setInitObjBoundsDense(int numberOfObj, double* lb, double* ub)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->objectives == NULL) 
		this->optimization->objectives = new ObjectiveOption();
	if (this->optimization->objectives->initialObjectiveBounds == NULL) 
		this->optimization->objectives->initialObjectiveBounds = new InitObjectiveBounds();
	else
	{	delete[] this->optimization->objectives->initialObjectiveBounds->obj;
		this->optimization->objectives->initialObjectiveBounds->obj = NULL;
	}
	int i;
	for (i = 0; i < numberOfObj; i++)
	{	if (!this->optimization->objectives->initialObjectiveBounds->addObj(-1-i, lb[i], ub[i]))
			return false;
	}
	return true;
}//setInitObjBoundsDense

bool OSOption::setAnotherInitObjBound(int idx, double lb, double ub)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->objectives == NULL) 
		this->optimization->objectives = new ObjectiveOption();
	if (this->optimization->objectives->initialObjectiveBounds == NULL) 
		this->optimization->objectives->initialObjectiveBounds = new InitObjectiveBounds();
	return this->optimization->objectives->initialObjectiveBounds->addObj(idx, lb, ub);
}//setAnotherInitObjBound

bool OSOption::setOtherObjectiveOptionObj(int otherOptionNumber, int objNumber,
			int idx, std::string name, std::string value, std::string lbValue, std::string ubValue)
{
	if (optimization == NULL) return false;

	if (optimization->objectives == NULL) return false;
	if (optimization->objectives->other == NULL) return false;
	if (otherOptionNumber < 0 || otherOptionNumber >= optimization->objectives->numberOfOtherObjectiveOptions) return false;
	if (optimization->objectives->other[otherOptionNumber] == NULL) return false;
	if (idx >= 0) return false;
	
	if (optimization->objectives->other[otherOptionNumber]->obj == NULL) return false;
	if (objNumber < 0 || objNumber >= optimization->objectives->other[otherOptionNumber]->numberOfObj) return false;
	if (optimization->objectives->other[otherOptionNumber]->obj[objNumber] == NULL) return false; 

	optimization->objectives->other[otherOptionNumber]->obj[objNumber]->idx = idx;
	optimization->objectives->other[otherOptionNumber]->obj[objNumber]->name = name;
	optimization->objectives->other[otherOptionNumber]->obj[objNumber]->value = value;
	optimization->objectives->other[otherOptionNumber]->obj[objNumber]->lbValue = lbValue;
	optimization->objectives->other[otherOptionNumber]->obj[objNumber]->ubValue = ubValue;
	return true;
}//setOtherOptionObj

bool OSOption::setNumberOfOtherObjectiveOptions(int numberOfOther)
{
	if (optimization == NULL) return false;
	if (optimization->objectives == NULL) 
		optimization->objectives = new ObjectiveOption();
	if (optimization->objectives->numberOfOtherObjectiveOptions < 0) return false;

	optimization->objectives->numberOfOtherObjectiveOptions = numberOfOther;

	if (numberOfOther > 0)
	{
		optimization->objectives->other = new OtherObjectiveOption*[numberOfOther];

		for (int j=0; j < numberOfOther; j++)
			optimization->objectives->other[j] = new OtherObjectiveOption();
	}
	return true;

}//setNumberOfOtherObjectiveOptions

bool OSOption::setOtherObjectiveOptionAttributes(int iOther, int numberOfObj,
				int numberOfEnumerations, std::string name,
				std::string value, std::string solver,
				std::string category, std::string type,
				std::string description)
{
	if (optimization == NULL) return false;
	if (optimization->objectives == NULL) return false;
	if (optimization->objectives->other == NULL) return false;

	if (iOther < 0 || iOther >= optimization->objectives->numberOfOtherObjectiveOptions) return false;
		
	optimization->objectives->other[iOther]->numberOfObj          = numberOfObj;
	optimization->objectives->other[iOther]->numberOfEnumerations = numberOfEnumerations;
	optimization->objectives->other[iOther]->name                 = name;
	optimization->objectives->other[iOther]->value                = value;
	optimization->objectives->other[iOther]->solver               = solver;
	optimization->objectives->other[iOther]->category             = category;
	optimization->objectives->other[iOther]->type                 = type;
	optimization->objectives->other[iOther]->description          = description;

	if (numberOfObj > 0)
	{
		optimization->objectives->other[iOther]->obj = new OtherObjOption*[numberOfObj];
		for (int j=0; j<numberOfObj; j++) 
			optimization->objectives->other[iOther]->obj[j] = new OtherObjOption();
	}

	if (numberOfEnumerations > 0)
	{
		optimization->objectives->other[iOther]->enumeration = new OtherOptionEnumeration*[numberOfEnumerations];
		for (int j=0; j<numberOfEnumerations; j++) 
			optimization->objectives->other[iOther]->enumeration[j] = new OtherOptionEnumeration();
	}
	return true;
}//setOtherObjOptionAttributes

bool OSOption::setOtherObjectiveOptions(int numberOfOptions, OtherObjectiveOption** other)
{	if (this->optimization == NULL)
		this->optimization = new OptimizationOption();
	if (this->optimization->objectives == NULL)
		this->optimization->objectives = new ObjectiveOption();
	else
	{	int i;
		for (i = 0; i < this->optimization->objectives->numberOfOtherObjectiveOptions; i++)
			delete this->optimization->objectives->other[i];
		delete[] this->optimization->objectives->other;
		this->optimization->objectives->other = NULL;
	}
	return this->optimization->objectives->setOther(numberOfOptions, other);
}//setOtherObjectiveOptions

bool OSOption::setAnOtherObjectiveOption(OtherObjectiveOption* optionValue)
{	if (this->optimization == NULL)
		this->optimization = new OptimizationOption();
	if (this->optimization->objectives == NULL)
		this->optimization->objectives = new ObjectiveOption();
	return this->optimization->objectives->addOther(optionValue);
}//setAnOtherVariableOption


bool OSOption::setInitConValues(int numberOfCon, int* idx, double* value, std::string* name)
{
	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->constraints == NULL) 
		this->optimization->constraints = new ConstraintOption();
	if (this->optimization->constraints->initialConstraintValues != NULL) 
		return false;

	this->optimization->constraints->initialConstraintValues = new InitConstraintValues();

	return this->optimization->constraints->initialConstraintValues->setCon(numberOfCon, idx, value, name);
}//setInitConValues


bool OSOption::setInitConValuesSparse(int numberOfCon, InitConValue** con)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->constraints == NULL) 
		this->optimization->constraints = new ConstraintOption();
	if (this->optimization->constraints->initialConstraintValues == NULL) 
		this->optimization->constraints->initialConstraintValues = new InitConstraintValues();
	else
	{	int i;
		for (i = 0; i < this->optimization->constraints->initialConstraintValues->numberOfCon; i++)
			delete this->optimization->constraints->initialConstraintValues->con[i];
		delete[] this->optimization->constraints->initialConstraintValues->con;
		this->optimization->constraints->initialConstraintValues->con = NULL;
	}
	return this->optimization->constraints->initialConstraintValues->setCon(numberOfCon, con);
}//setInitConValuesSparse

bool OSOption::setInitConValuesDense(int numberOfCon, double *value)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->constraints == NULL) 
		this->optimization->constraints = new ConstraintOption();
	if (this->optimization->constraints->initialConstraintValues == NULL) 
		this->optimization->constraints->initialConstraintValues = new InitConstraintValues();
	else
	{	delete[] this->optimization->constraints->initialConstraintValues->con;
		this->optimization->constraints->initialConstraintValues->con = NULL;
	}
	int i;
	for (i = 0; i < numberOfCon; i++)
	{
//		if (!CoinIsnan(value[i]))
			if (!this->optimization->constraints->initialConstraintValues->addCon(i, value[i]))
				return false;
	}
	return true;
}//setInitConValuesDense

bool OSOption::setAnotherInitConValue(int idx, double value)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->constraints == NULL) 
		this->optimization->constraints = new ConstraintOption();
	if (this->optimization->constraints->initialConstraintValues == NULL) 
		this->optimization->constraints->initialConstraintValues = new InitConstraintValues();
	return this->optimization->constraints->initialConstraintValues->addCon(idx, value);
}//setAnotherInitConValue

bool OSOption::setInitDualValues(int numberOfCon, int* idx, double* lbValue, double* ubValue, std::string* name)
{
	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->constraints == NULL) 
		this->optimization->constraints = new ConstraintOption();
	if (this->optimization->constraints->initialDualValues != NULL) 
		return false;

	this->optimization->constraints->initialDualValues = new InitDualVariableValues();

	return this->optimization->constraints->initialDualValues->setCon(numberOfCon, idx, lbValue, ubValue, name);
}//setInitDualValues


bool OSOption::setInitDualVarValuesSparse(int numberOfCon, InitDualVarValue** con)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->constraints == NULL) 
		this->optimization->constraints = new ConstraintOption();
	if (this->optimization->constraints->initialDualValues == NULL) 
		this->optimization->constraints->initialDualValues = new InitDualVariableValues();
	else
	{	int i;
		for (i = 0; i < this->optimization->constraints->initialDualValues->numberOfCon; i++)
			delete this->optimization->constraints->initialDualValues->con[i];
		delete[] this->optimization->constraints->initialDualValues->con;
		this->optimization->constraints->initialDualValues->con = NULL;
	}
	return this->optimization->constraints->initialDualValues->setCon(numberOfCon, con);
}//setInitDualVarValuesSparse

bool OSOption::setInitDualVarValuesDense(int numberOfCon, double* lb, double* ub)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->constraints == NULL) 
		this->optimization->constraints = new ConstraintOption();
	if (this->optimization->constraints->initialDualValues == NULL) 
		this->optimization->constraints->initialDualValues = new InitDualVariableValues();
	else
	{	delete[] this->optimization->constraints->initialDualValues->con;
		this->optimization->constraints->initialDualValues->con = NULL;
	}
	int i;
	for (i = 0; i < numberOfCon; i++)
	{	if ((lb[i] != 0.0) || (ub[i] != 0.0))
			if (!this->optimization->constraints->initialDualValues->addCon(i, lb[i], ub[i]))
				return false;	
	}
	return true;
}//setInitDualVarValuesDense

bool OSOption::setAnotherInitDualVarValue(int idx, double lbValue, double ubValue)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->constraints == NULL) 
		this->optimization->constraints = new ConstraintOption();
	if (this->optimization->constraints->initialDualValues == NULL) 
		this->optimization->constraints->initialDualValues = new InitDualVariableValues();
	return this->optimization->constraints->initialDualValues->addCon(idx, lbValue, ubValue);
}//setAnotherInitConValue

bool OSOption::setNumberOfOtherConstraintOptions(int numberOfOther)
{
	if (optimization == NULL) return false;
	if (optimization->constraints == NULL) 	
		optimization->constraints = new ConstraintOption();
	if (optimization->constraints->numberOfOtherConstraintOptions < 0) return false;

	optimization->constraints->numberOfOtherConstraintOptions = numberOfOther;

	if (numberOfOther > 0)
	{
		optimization->constraints->other = new OtherConstraintOption*[numberOfOther];

		for (int j=0; j < numberOfOther; j++)
			optimization->constraints->other[j] = new OtherConstraintOption();
	}

	return true;
}//setNumberOfOtherConstraintOptions

bool OSOption::setOtherConstraintOptionAttributes(int iOther, int numberOfCon,
				int numberOfEnumerations, std::string name,
				std::string value, std::string solver,
				std::string category, std::string type,
				std::string description)
{
	if (optimization == NULL) return false;
	if (optimization->constraints == NULL) return false;
	if (optimization->constraints->other == NULL) return false;
	if (iOther < 0 || iOther >= optimization->constraints->numberOfOtherConstraintOptions) return false;
		
	optimization->constraints->other[iOther]->numberOfCon          = numberOfCon;
	optimization->constraints->other[iOther]->numberOfEnumerations = numberOfEnumerations;
	optimization->constraints->other[iOther]->name                 = name;
	optimization->constraints->other[iOther]->value                = value;
	optimization->constraints->other[iOther]->solver               = solver;
	optimization->constraints->other[iOther]->category             = category;
	optimization->constraints->other[iOther]->type                 = type;
	optimization->constraints->other[iOther]->description          = description;

	if (numberOfCon > 0)
	{
		optimization->constraints->other[iOther]->con = new OtherConOption*[numberOfCon];
		for (int j=0; j<numberOfCon; j++) 
			optimization->constraints->other[iOther]->con[j] = new OtherConOption();
	}

	if (numberOfEnumerations > 0)
	{
		optimization->constraints->other[iOther]->enumeration = new OtherOptionEnumeration*[numberOfEnumerations];
		for (int j=0; j<numberOfEnumerations; j++) 
			optimization->constraints->other[iOther]->enumeration[j] = new OtherOptionEnumeration();
	}
	return true;
}//setOtherConOptionAttributes


bool OSOption::setOtherConstraintOptionCon(int otherOptionNumber, int conNumber,
			int idx, std::string name, std::string value, std::string lbValue, std::string ubValue)
{
	if (optimization == NULL) return false;

	if (optimization->constraints == NULL) return false;
	if (optimization->constraints->other == NULL) return false;
	if (otherOptionNumber < 0 || otherOptionNumber >= optimization->constraints->numberOfOtherConstraintOptions) return false;
	if (optimization->constraints->other[otherOptionNumber] == NULL) return false;
	if (idx < 0) return false;

	if (optimization->constraints->other[otherOptionNumber]->con == NULL) return false;
	if (conNumber < 0 || conNumber >= optimization->constraints->other[otherOptionNumber]->numberOfCon) return false;
	if (optimization->constraints->other[otherOptionNumber]->con[conNumber] == NULL) return false; 

	optimization->constraints->other[otherOptionNumber]->con[conNumber]->idx = idx;
	optimization->constraints->other[otherOptionNumber]->con[conNumber]->name = name;
	optimization->constraints->other[otherOptionNumber]->con[conNumber]->value = value;
	optimization->constraints->other[otherOptionNumber]->con[conNumber]->lbValue = lbValue;
	optimization->constraints->other[otherOptionNumber]->con[conNumber]->ubValue = ubValue;
	return true;
}//setOtherOptionCon



bool OSOption::setOtherConstraintOptions(int numberOfOptions, OtherConstraintOption** other)
{	if (this->optimization == NULL)
		this->optimization = new OptimizationOption();
	if (this->optimization->constraints == NULL)
		this->optimization->constraints = new ConstraintOption();
	else
	{	int i;
		for (i = 0; i < this->optimization->constraints->numberOfOtherConstraintOptions; i++)
			delete this->optimization->constraints->other[i];
		delete[] this->optimization->constraints->other;
		this->optimization->constraints->other = NULL;
	}
	return this->optimization->constraints->setOther(numberOfOptions, other);
}//setOtherConstraintOptions

bool OSOption::setAnOtherConstraintOption(OtherConstraintOption* optionValue)
{	if (this->optimization == NULL)
		this->optimization = new OptimizationOption();
	if (this->optimization->constraints == NULL)
		this->optimization->constraints = new ConstraintOption();
	return this->optimization->constraints->addOther(optionValue);
}//setAnOtherConstraintOption


bool OSOption::setNumberOfSolverOptions(int numberOfOptions)
{
	if (optimization == NULL) return false;
	if (optimization->solverOptions != NULL) return false;

	optimization->solverOptions = new SolverOptions();
	optimization->solverOptions->numberOfSolverOptions = numberOfOptions;
	optimization->solverOptions->solverOption = new SolverOption*[numberOfOptions];

	for (int j=0; j < numberOfOptions; j++)
		optimization->solverOptions->solverOption[j] = new SolverOption();
	return true;
}//setNumberOfSolverOptions

bool OSOption::setSolverOptionContent(int iOption, int numberOfItems,
				std::string name,
				std::string value, std::string solver,
				std::string category, std::string type,
				std::string description, std::string *itemList)
{
	if (optimization == NULL) return false;
	if (optimization->solverOptions == NULL) return false;
	if (optimization->solverOptions->solverOption == NULL) return false;

	if (iOption < 0 || iOption >= optimization->solverOptions->numberOfSolverOptions) return false;
		
	optimization->solverOptions->solverOption[iOption]->numberOfItems = numberOfItems;
	optimization->solverOptions->solverOption[iOption]->name          = name;
	optimization->solverOptions->solverOption[iOption]->value         = value;
	optimization->solverOptions->solverOption[iOption]->solver        = solver;
	optimization->solverOptions->solverOption[iOption]->category      = category;
	optimization->solverOptions->solverOption[iOption]->type          = type;
	optimization->solverOptions->solverOption[iOption]->description   = description;

	if (numberOfItems > 0)
	{
		optimization->solverOptions->solverOption[iOption]->item = new std::string[numberOfItems];
		for (int j=0; j<numberOfItems; j++) 
			optimization->solverOptions->solverOption[iOption]->item[j] = itemList[j];
	}

	return true;
}//setSolverOptionContent

bool OSOption::setSolverOptions(int numberOfSolverOptions, SolverOption** solverOption)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->solverOptions == NULL) 
		this->optimization->solverOptions = new SolverOptions();
	else
	{	int i;
		for (i = 0; i < this->optimization->solverOptions->numberOfSolverOptions; i++)
			delete this->optimization->solverOptions->solverOption[i];
		delete[] this->optimization->solverOptions->solverOption;
		this->optimization->solverOptions->solverOption = NULL;
	}
	return this->optimization->solverOptions->setSolverOptions(numberOfSolverOptions, solverOption);
}//setSolverOptions

bool OSOption::setAnotherSolverOption(std::string name, std::string value, std::string solver, 
		 std::string category, std::string type, std::string description)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->solverOptions == NULL) 
		this->optimization->solverOptions = new SolverOptions();
	return this->optimization->solverOptions->addSolverOption(name, value, solver, category, type, description);
}//setAnotherSolverOption


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
		return this->setInstanceLocationType(optionValue);

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
		return this->setContactTransportType(optionValue);

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

	if (optionName == "requestedStartTime") 
		return this->setRequestedStartTime(optionValue);

	return false;
}//setOptionStr


bool OSOption::setOptionInt(std::string optionName, int optionValue)
{	if (optionName == "minCPUNumber")
		return this->setMinCPUNumber(optionValue);

	return false;
}//setOptionInt


bool OSOption::setOptionDbl(std::string optionName, double value)
{	if (optionName == "minDiskSpaceValue") 
		return this->setMinDiskSpace(value);

	if (optionName == "minMemoryValue") 
		return this->setMinMemorySize(value);

	if (optionName == "minCPUSpeedValue") 
		return this->setMinCPUSpeed(value);

	if (optionName == "maxTime") 
		return this->setMaxTime(value);

	return false;
}//setOptionDbl

/***************************************************
 * methods to test whether two OSOption objects 
 * or their components are equal to each other
 ***************************************************/
bool OSOption::IsEqual(OSOption *that)
{
	#ifdef DEBUG_OSOPTION
		cout << "Start comparing in OSOption" << endl;
	#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{
			if (!this->optionHeader->IsEqual(that->optionHeader))
				return false;
			if (!this->general->IsEqual(that->general))
				return false;
			if (!this->system->IsEqual(that->system))
				return false;
			if (!this->service->IsEqual(that->service))
				return false;
			if (!this->job->IsEqual(that->job))
				return false;
			if (!this->optimization->IsEqual(that->optimization))
				return false;
			return true;
		}
	}
}//OSOption::IsEqual


bool GeneralOption::IsEqual(GeneralOption *that)
{	
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in GeneralOption" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	bool same;
			same =  (this->serviceURI     == that->serviceURI);
			same = ((this->serviceName    == that->serviceName )   && same);
			same = ((this->instanceName   == that->instanceName )  && same);
			same = ((this->jobID          == that->jobID )         && same);
			same = ((this->solverToInvoke == that->solverToInvoke) && same);
			same = ((this->license        == that->license )       && same);
			same = ((this->userName       == that->userName )      && same);
			same = ((this->password       == that->password )      && same);
			if (!same) 
			{
				#ifdef DEBUG_OSOPTION
				cout << "serviceURI:    " << this->serviceURI     << " vs. " << that->serviceURI     << endl;
				cout << "serviceName:   " << this->serviceName    << " vs. " << that->serviceName    << endl;
				cout << "instanceName:  " << this->instanceName   << " vs. " << that->instanceName   << endl;
				cout << "jobID:         " << this->jobID          << " vs. " << that->jobID          << endl;
				cout << "solverToInvoke:" << this->solverToInvoke << " vs. " << that->solverToInvoke << endl;
				cout << "license:       " << this->license        << " vs. " << that->license        << endl;
				cout << "userName:      " << this->userName       << " vs. " << that->userName       << endl;
				cout << "password:      " << this->password       << " vs. " << that->password       << endl;
				#endif
				return false;
			}
			if (!this->instanceLocation->IsEqual(that->instanceLocation))
				return false;
			if (!this->contact->IsEqual(that->contact))
				return false;
			if (!this->otherOptions->IsEqual(that->otherOptions))
				return false;
			return true;
		}
	}
}//GeneralOption::IsEqual


bool SystemOption::IsEqual(SystemOption *that)
{	
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in SystemOption" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{
			if (!this->minDiskSpace->IsEqual(that->minDiskSpace))
				return false;
			if (!this->minMemorySize->IsEqual(that->minMemorySize))
				return false;
			if (!this->minCPUSpeed->IsEqual(that->minCPUSpeed))
				return false;
			if (!this->minCPUNumber->IsEqual(that->minCPUNumber))
				return false;
			if (!this->otherOptions->IsEqual(that->otherOptions))
				return false;
			return true;
		}	
	}
}//SystemOption::IsEqual


bool ServiceOption::IsEqual(ServiceOption *that)
{	
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in ServiceOption" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else
		{	if (this->type != that->type)
			{
				#ifdef DEBUG_OSOPTION
				cout << "service type: " << this->type << " vs. " << that->type << endl;
				#endif
				return false;
			}

			if (!this->otherOptions->IsEqual(that->otherOptions))
				return false;
			return true;
		}
	}
}//ServiceOption::IsEqual


bool JobOption::IsEqual(JobOption *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in JobOption" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if (this->requestedStartTime != that->requestedStartTime)
			{
				#ifdef DEBUG_OSOPTION
				cout << "requestedStartTime: " << this->requestedStartTime << " vs. " << that->requestedStartTime << endl;
				#endif
				return false;
			}

			if (!this->maxTime->IsEqual(that->maxTime))
				return false;
			if (!this->dependencies->IsEqual(that->dependencies))
				return false;
			if (!this->requiredDirectories->IsEqual(that->requiredDirectories))
				return false;
			if (!this->requiredFiles->IsEqual(that->requiredFiles))
				return false;
			if (!this->directoriesToMake->IsEqual(that->directoriesToMake))
				return false;
			if (!this->filesToMake->IsEqual(that->filesToMake))
				return false;
			if (!this->inputDirectoriesToMove->IsEqual(that->inputDirectoriesToMove))
				return false;
			if (!this->inputFilesToMove->IsEqual(that->inputFilesToMove))
				return false;
			if (!this->outputFilesToMove->IsEqual(that->outputFilesToMove))
				return false;
			if (!this->outputDirectoriesToMove->IsEqual(that->outputDirectoriesToMove))
				return false;
			if (!this->filesToDelete->IsEqual(that->filesToDelete))
				return false;
			if (!this->directoriesToDelete->IsEqual(that->directoriesToDelete))
				return false;
			if (!this->processesToKill->IsEqual(that->processesToKill))
				return false;
			if (!this->otherOptions->IsEqual(that->otherOptions))
				return false;
			return true;
		}
	}
}//JobOption::IsEqual

bool OptimizationOption::IsEqual(OptimizationOption *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in OptimizationOption" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if ((this->numberOfVariables != that->numberOfVariables) && 
				(this->numberOfVariables *  that->numberOfVariables) != 0)
			{
				#ifdef DEBUG_OSOPTION
				cout << "numberOfVariables: " 
					 << this->numberOfVariables << " vs. " << that->numberOfVariables << endl;
				#endif
				return false;
			}
			if ((this->numberOfObjectives != that->numberOfObjectives) && 
				(this->numberOfObjectives *  that->numberOfObjectives) != 0)
			{
				#ifdef DEBUG_OSOPTION
				cout << "numberOfObjectives: " 
					 << this->numberOfObjectives << " vs. " << that->numberOfObjectives << endl;
				#endif
				return false;
			}
			if ((this->numberOfConstraints != that->numberOfConstraints) && 
				(this->numberOfConstraints *  that->numberOfConstraints) != 0)
			{
				#ifdef DEBUG_OSOPTION
				cout << "numberOfConstraints: " 
					 << this->numberOfConstraints << " vs. " << that->numberOfConstraints << endl;
				#endif
				return false;
			}

			if (!this->variables->IsEqual(that->variables))
				return false;
			if (!this->objectives->IsEqual(that->objectives))
				return false;
			if (!this->constraints->IsEqual(that->constraints))
				return false;
			if (!this->solverOptions->IsEqual(that->solverOptions))
				return false;
			return true;
		}
	}
}//OptimizationOption::IsEqual

bool InstanceLocationOption::IsEqual(InstanceLocationOption *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in InstanceLocationOption" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if ((this->locationType != that->locationType) || (this->value != that->value)) 
			{	
				#ifdef DEBUG_OSOPTION
				cout << "location type: " << this->locationType << " vs. " << that->locationType << endl;
				cout << "value: "         << this->value        << " vs. " << that->value        << endl;
				#endif
				return false;
			}
			return true;
		}
	}
}//InstanceLocationOption::IsEqual

bool ContactOption::IsEqual(ContactOption *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in ContactOption" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if ((this->transportType != that->transportType) || (this->value != that->value)) 
			{	
				#ifdef DEBUG_OSOPTION
				cout << "transport type: " << this->transportType << " vs. " << that->transportType << endl;
				cout << "value: "          << this->value         << " vs. " << that->value         << endl;
				#endif
				return false;
			}
			return true;
		}
	}
}//ContactOption::IsEqual

bool OtherOptions::IsEqual(OtherOptions *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in OtherOptions" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if (this->numberOfOtherOptions  != that->numberOfOtherOptions) 
			{
				#ifdef DEBUG_OSOPTION
				cout << "numberOfOtherOptions: " << this->numberOfOtherOptions << " vs. " << that->numberOfOtherOptions << endl;
				#endif
				return false;
			}
			int i;
			for (i = 0; i < this->numberOfOtherOptions; i++)
				if (!this->other[i]->IsEqual(that->other[i]))
					return false;
			return true;
		}
	}
}//OtherOptions::IsEqual


bool OtherOption::IsEqual(OtherOption *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in OtherOption" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if ((this->name  != that->name)  || 
				(this->value != that->value) || 
				(this->description != that->description) ) 
			{
				#ifdef DEBUG_OSOPTION
				cout << "name: "        << this->name        << " vs. " << that->name        << endl;
				cout << "value: "       << this->value       << " vs. " << that->value       << endl;
				cout << "description: " << this->description << " vs. " << that->description << endl;
				#endif
				return false;
			}
			return true;
		}
	}
}//OtherOption::IsEqual

bool MinDiskSpace::IsEqual(MinDiskSpace *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in MinDiskSpace" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if ((this->unit        != that->unit)  || 
				!isEqual(this->value, that->value) ||
				(this->description != that->description) ) 
			{	
#ifdef DEBUG_OSOPTION
				cout << "unit:        " << this->unit        << " vs. " << that->unit        << endl;
				cout << "value:       " << this->value       << " vs. " << that->value       << endl;
				cout << "description: " << this->description << " vs. " << that->description << endl;
#endif	
				return false;
			}
			return true;
		}
	}
}//MinDiskSpace::IsEqual

bool MinMemorySize::IsEqual(MinMemorySize *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in MinMemorySize" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if ((this->unit        != that->unit)  || 
				!isEqual(this->value, that->value) ||
				(this->description != that->description) ) 
			{
#ifdef DEBUG_OSOPTION
				cout << "unit: "  << this->unit  << " vs. " << that->unit  << endl;
				cout << "value: " << this->value << " vs. " << that->value << endl;
#endif	
				return false;
			}
			return true;
		}
	}
}//MinMemorySize::IsEqual

bool MinCPUSpeed::IsEqual(MinCPUSpeed *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in MinCPUSpeed" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if ((this->unit        != that->unit)  || 
				!isEqual(this->value, that->value) ||
				(this->description != that->description) ) 
			{
#ifdef DEBUG_OSOPTION
				cout << "unit: "  << this->unit  << " vs. " << that->unit  << endl;
				cout << "value: " << this->value << " vs. " << that->value << endl;
#endif	
				return false;
			}
			return true;
		}
	}
}//MinCPUSpeed::IsEqual

bool MinCPUNumber::IsEqual(MinCPUNumber *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in MinCPUNumber" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if ((this->description != that->description)  || 
				(this->value != that->value) )
			{
#ifdef DEBUG_OSOPTION
				cout << "description: " << this->description  << " vs. " << that->description  << endl;
				cout << "value:       " << this->value << " vs. " << that->value << endl;
#endif	
				return false;
			}
			return true;
		}
	}
}//MinCPUNumber::IsEqual

bool JobDependencies::IsEqual(JobDependencies *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in JobDependencies" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if (this->numberOfJobIDs != that->numberOfJobIDs)  
			{
#ifdef DEBUG_OSOPTION
				cout << "numberOfJobIDs: " << this->numberOfJobIDs << " vs. " << that->numberOfJobIDs << endl;
#endif	
				return false;
			}
			int i;
			for (i = 0; i < numberOfJobIDs; i++)
				if (this->jobID[i] != that->jobID[i])
				{
#ifdef DEBUG_OSOPTION
					cout << "jobID[" << i << "]: " << this->jobID[i] << " vs. " << that->jobID[i] << endl;
#endif	
					return false;
				}
			return true;
		}
	}
}//JobDependencies::IsEqual

bool DirectoriesAndFiles::IsEqual(DirectoriesAndFiles *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in DirectoriesAndFiles" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if (this->numberOfPaths != that->numberOfPaths)  
			{
#ifdef DEBUG_OSOPTION
				cout << "numberOfPaths: " << this->numberOfPaths << " vs. " << that->numberOfPaths << endl;
#endif	
				return false;
			}
			int i;
			for (i = 0; i < numberOfPaths; i++)
				if (this->path[i] != that->path[i])
				{
#ifdef DEBUG_OSOPTION
					cout << "path[" << i << "]: \'" << this->path[i] << "\' vs. \'" << that->path[i] << "\'" << endl;
#endif	
					return false;
				}
			return true;
		}
	}
}//DirectoriesAndFiles::IsEqual

bool PathPairs::IsEqual(PathPairs *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in PathPairs" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if (this->numberOfPathPairs != that->numberOfPathPairs)  
			{
#ifdef DEBUG_OSOPTION
				cout << "numberOfPathPairs: " << this->numberOfPathPairs << " vs. " << that->numberOfPathPairs << endl;
#endif	
				return false;
			}
			int i;
			for (i = 0; i < numberOfPathPairs; i++)
				if (!this->pathPair[i]->IsEqual(that->pathPair[i]))
					return false;
			return true;
		}
	}
}//PathPairs::IsEqual

	
bool PathPair::IsEqual(PathPair *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in PathPair" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if ((this->from != that->from) || (this->to != that->to) || 
				(this->makeCopy != that->makeCopy))  
			{
#ifdef DEBUG_OSOPTION
				cout << "from: "     << this->from     << " vs. " << that->from     << endl;
				cout << "to: "       << this->to       << " vs. " << that->to       << endl;
				cout << "makeCopy: " << this->makeCopy << " vs. " << that->makeCopy << endl;
#endif	
				return false;
			}
			return true;
		}
	}
}//PathPair::IsEqual

bool Processes::IsEqual(Processes *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in Processes" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if (this->numberOfProcesses != that->numberOfProcesses)  
			{
#ifdef DEBUG_OSOPTION
				cout << "numberOfProcesses: " << this->numberOfProcesses << " vs. " << that->numberOfProcesses << endl;
#endif	
				return false;
			}
			int i;
			for (i = 0; i < numberOfProcesses; i++)
				if (this->process[i] != that->process[i])
				{
#ifdef DEBUG_OSOPTION
					cout << "process[" << i << "]: " << this->process[i] << " vs. " << that->process[i] << endl;
#endif	
					return false;
				}
			return true;
		}
	}
}//Processes::IsEqual


bool VariableOption::IsEqual(VariableOption *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in VariableOption" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	
			if (!this->initialVariableValues->IsEqual(that->initialVariableValues))
				return false;
			if (!this->initialVariableValuesString->IsEqual(that->initialVariableValuesString))
				return false;
			if (!this->initialBasisStatus->IsEqual(that->initialBasisStatus))
				return false;
			if (!this->integerVariableBranchingWeights->IsEqual(that->integerVariableBranchingWeights))
				return false;
			if (!this->sosVariableBranchingWeights->IsEqual(that->sosVariableBranchingWeights))
				return false;

			if (this->numberOfOtherVariableOptions != that->numberOfOtherVariableOptions)  
			{
#ifdef DEBUG_OSOPTION
				cout << "numberOfOtherVariableOptions: " << this->numberOfOtherVariableOptions << " vs. " << that->numberOfOtherVariableOptions << endl;
#endif	
				return false;
			}

			int i;
			for (i = 0; i < numberOfOtherVariableOptions; i++)
				if (!this->other[i]->IsEqual(that->other[i]))
				{
#ifdef DEBUG_OSOPTION
					cout << "other[" << i << "]: " << this->other[i] << " vs. " << that->other[i] << endl;
#endif	
					return false;
				}

			return true;
		}
	}
}//VariableOption::IsEqual

bool InitVariableValues::IsEqual(InitVariableValues *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in InitVariableValues" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if (this->numberOfVar != that->numberOfVar)  
			{
#ifdef DEBUG_OSOPTION
				cout << "numberOfVar: " << this->numberOfVar << " vs. " << that->numberOfVar << endl;
#endif	
				return false;
			}
			int i;
			for (i = 0; i < numberOfVar; i++)
				if (!this->var[i]->IsEqual(that->var[i]))
					return false;
			return true;
		}
	}
}//InitVariableValues::IsEqual

bool InitVarValue::IsEqual(InitVarValue *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in InitVarValue" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if ((this->idx != that->idx) || this->name != that->name || !isEqual(this->value, that->value))

			{
#ifdef DEBUG_OSOPTION
				cout << "idx: "   << this->idx   << " vs. " << that->idx   << endl;
				cout << "value: " << this->value << " vs. " << that->value << endl;
#endif	
				return false;
			}
			return true;
		}
	}
}//InitVarValue::IsEqual


bool InitVariableValuesString::IsEqual(InitVariableValuesString *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in InitVariableValuesString" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if (this->numberOfVar != that->numberOfVar)  
			{
#ifdef DEBUG_OSOPTION
				cout << "numberOfVar: " << this->numberOfVar << " vs. " << that->numberOfVar << endl;
#endif	
				return false;
			}
			int i;
			for (i = 0; i < numberOfVar; i++)
				if (!this->var[i]->IsEqual(that->var[i]))
					return false;
			return true;
		}
	}
}//InitVariableValuesString::IsEqual

bool InitVarValueString::IsEqual(InitVarValueString *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in InitVarValueString" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if ((this->idx != that->idx) || this->name != that->name || (this->value != that->value))
			{
#ifdef DEBUG_OSOPTION
				cout << "idx: "   << this->idx   << " vs. " << that->idx   << endl;
				cout << "value: " << this->value << " vs. " << that->value << endl;
#endif	
				return false;
			}
			return true;
		}
	}
}//InitVarValueString::IsEqual

bool InitialBasisStatus::IsEqual(InitialBasisStatus *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in InitialBasisStatus" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if (this->numberOfVar != that->numberOfVar)  
			{
#ifdef DEBUG_OSOPTION
				cout << "numberOfVar: " << this->numberOfVar << " vs. " << that->numberOfVar << endl;
#endif	
				return false;
			}
			int i;
			for (i = 0; i < numberOfVar; i++)
				if (!this->var[i]->IsEqual(that->var[i]))
					return false;
			return true;
		}
	}
}//InitialBasisStatus::IsEqual

bool InitBasStatus::IsEqual(InitBasStatus *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in InitBasStatus" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if ((this->idx != that->idx) || (this->value != that->value))
			if ((this->value != "unknown" && that->value != "") ||
				(that->value != "unknown" && this->value != "") )
			{
#ifdef DEBUG_OSOPTION
				cout << "idx: "   << this->idx   << " vs. " << that->idx   << endl;
				cout << "value: " << this->value << " vs. " << that->value << endl;
#endif	
				return false;
			}
			return true;
		}
	}
}//InitBasStatus::IsEqual


bool IntegerVariableBranchingWeights::IsEqual(IntegerVariableBranchingWeights *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in IntegerVariableBranchingWeights" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if (this->numberOfVar != that->numberOfVar)  
			{
#ifdef DEBUG_OSOPTION
				cout << "numberOfVar: " << this->numberOfVar << " vs. " << that->numberOfVar << endl;
#endif	
				return false;
			}
			int i;
			for (i = 0; i < numberOfVar; i++)
				if (!this->var[i]->IsEqual(that->var[i]))
					return false;
			return true;
		}
	}
}//IntegerVariableBranchingWeights::IsEqual

bool SOSVariableBranchingWeights::IsEqual(SOSVariableBranchingWeights *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in SOSVariableBranchingWeights" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if (this->numberOfSOS != that->numberOfSOS)  
			{
#ifdef DEBUG_OSOPTION
				cout << "numberOfSOS: " << this->numberOfSOS << " vs. " << that->numberOfSOS << endl;
#endif	
				return false;
			}
			int i;
			for (i = 0; i < numberOfSOS; i++)
			{	
				if (!this->sos[i]->IsEqual(that->sos[i]))
					return false;
			}
			return true;
		}
	}
}//SOSVariableBranchingWeights::IsEqual


bool SOSWeights::IsEqual(SOSWeights *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in SOSWeights" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if ((this->sosIdx != that->sosIdx) ||
				!isEqual(this->groupWeight, that->groupWeight))  
			{
#ifdef DEBUG_OSOPTION
				cout << "sosIdx: "      << this->sosIdx      << " vs. " << that->sosIdx      << endl;
				cout << "groupWeight: " << this->groupWeight << " vs. " << that->groupWeight << endl;
#endif	
				return false;
			}

			if (this->numberOfVar != that->numberOfVar)  
			{
#ifdef DEBUG_OSOPTION
				cout << "numberOfVar: " << this->numberOfVar << " vs. " << that->numberOfVar << endl;
#endif	
				return false;
			}
			int i;
			for (i = 0; i < numberOfVar; i++)
			{	//cout << "var[" << i << "] of " << numberOfVar << endl;
				if (!this->var[i]->IsEqual(that->var[i]))
					return false;
			}
			return true;
		}
	}
}//SOSWeights::IsEqual


bool BranchingWeight::IsEqual(BranchingWeight *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in BranchingWeight" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if ((this->idx != that->idx) || this->name != that->name || !isEqual(this->value, that->value))
			{
#ifdef DEBUG_OSOPTION
				cout << "idx: "   << this->idx   <<  " vs. "  << that->idx   << endl;
				cout << "value: " << this->value <<  " vs. "  << that->value << endl;
				cout << "name: -" << this->name  << "- vs. -" << that->name  << "-" << endl;
#endif	
				return false;
			}
			return true;
		}
	}
}//BranchingWeight::IsEqual

bool OtherVariableOption::IsEqual(OtherVariableOption *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in OtherVariableOption" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if ((this->name        != that->name)     ||
				(this->value       != that->value)    ||
				(this->solver      != that->solver)   ||
				(this->category    != that->category) ||
				(this->type        != that->type)     ||
				(this->description != that->description))  
			{
#ifdef DEBUG_OSOPTION
				cout << "name: "        << this->name        << " vs. " << that->name        << endl;
				cout << "value: "       << this->value       << " vs. " << that->value       << endl;
				cout << "solver: "      << this->solver      << " vs. " << that->solver      << endl;
				cout << "category: "    << this->category    << " vs. " << that->category    << endl;
				cout << "type: "        << this->type        << " vs. " << that->type        << endl;
				cout << "description: " << this->description << " vs. " << that->description << endl;
#endif	
				return false;
			}

			if (this->numberOfVar != that->numberOfVar)  
			{
#ifdef DEBUG_OSOPTION
				cout << "numberOfVar: " << this->numberOfVar << " vs. " << that->numberOfVar << endl;
#endif	
				return false;
			}
			int i;
			for (i = 0; i < numberOfVar; i++)
				if (!this->var[i]->IsEqual(that->var[i]))
					return false;

			if (this->numberOfEnumerations != that->numberOfEnumerations)  
			{
#ifdef DEBUG_OSOPTION
				cout << "numberOfEnumerations: " << this->numberOfEnumerations << " vs. " << that->numberOfEnumerations << endl;
#endif	
				return false;
			}
			for (i = 0; i < numberOfEnumerations; i++)
				if (!this->enumeration[i]->IsEqual(that->enumeration[i]))
					return false;
			return true;
		}
	}
}//OtherVariableOption::IsEqual

bool OtherVarOption::IsEqual(OtherVarOption *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in OtherVarOption" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if ((this->idx     != that->idx)     ||  this->name != that->name   || (this->value   != that->value) ||
				(this->lbValue != that->lbValue) || (this->ubValue != that->ubValue))
			{
#ifdef DEBUG_OSOPTION
				cout << "idx: "     << this->idx     << " vs. " << that->idx     << endl;
				cout << "value: "   << this->value   << " vs. " << that->value   << endl;
				cout << "lbValue: " << this->lbValue << " vs. " << that->lbValue << endl;
				cout << "ubValue: " << this->ubValue << " vs. " << that->ubValue << endl;
#endif	
				return false;
			}
			return true;
		}
	}
}//OtherVarOption::IsEqual

bool ObjectiveOption::IsEqual(ObjectiveOption *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in ObjectiveOption" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	
			if (!this->initialObjectiveValues->IsEqual(that->initialObjectiveValues))
				return false;
			if (!this->initialObjectiveBounds->IsEqual(that->initialObjectiveBounds))
				return false;
			if (!this->initialBasisStatus->IsEqual(that->initialBasisStatus))
				return false;

			if (this->numberOfOtherObjectiveOptions != that->numberOfOtherObjectiveOptions)  
			{
#ifdef DEBUG_OSOPTION
				cout << "numberOfOtherObjectiveOptions: " << this->numberOfOtherObjectiveOptions << " vs. " << that->numberOfOtherObjectiveOptions << endl;
#endif	
				return false;
			}
			int i;
			for (i = 0; i < numberOfOtherObjectiveOptions; i++)
				if (!this->other[i]->IsEqual(that->other[i]))
					return false;

			return true;
		}
	}
}//ObjectiveOption::IsEqual

bool InitObjectiveValues::IsEqual(InitObjectiveValues *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in InitObjectiveValues" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if (this->numberOfObj != that->numberOfObj)  
			{
#ifdef DEBUG_OSOPTION
				cout << "numberOfObj: " << this->numberOfObj << " vs. " << that->numberOfObj << endl;
#endif	
				return false;
			}
			int i;
			for (i = 0; i < numberOfObj; i++)
				if (!this->obj[i]->IsEqual(that->obj[i]))
					return false;
			return true;
		}
	}
}//InitObjectiveValues::IsEqual

bool InitObjValue::IsEqual(InitObjValue *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in InitObjValue" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if ((this->idx != that->idx) || this->name != that->name || !isEqual(this->value, that->value))
			{
#ifdef DEBUG_OSOPTION
				cout << "idx: "   << this->idx   << " vs. " << that->idx   << endl;
				cout << "value: " << this->value << " vs. " << that->value << endl;
#endif	
				return false;
			}
			return true;
		}
	}
}//InitObjValue::IsEqual

bool InitObjectiveBounds::IsEqual(InitObjectiveBounds *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in InitObjectiveBounds" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if (this->numberOfObj != that->numberOfObj)  
			{
#ifdef DEBUG_OSOPTION
				cout << "numberOfObj: " << this->numberOfObj << " vs. " << that->numberOfObj << endl;
#endif	
				return false;
			}
			int i;
			for (i = 0; i < numberOfObj; i++)
				if (!this->obj[i]->IsEqual(that->obj[i]))
					return false;
			return true;
		}
	}
}//InitObjectiveBounds::IsEqual

bool InitObjBound::IsEqual(InitObjBound *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in InitObjBound" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if ((this->idx  != that->idx) || 
				 this->name != that->name ||
				!isEqual(this->lbValue, that->lbValue) || 
				!isEqual(this->ubValue, that->ubValue) )
			{
#ifdef DEBUG_OSOPTION
				cout << "idx: "     << this->idx     << " vs. " << that->idx     << endl;
				cout << "lbValue: " << this->lbValue << " vs. " << that->lbValue << endl;
				cout << "ubValue: " << this->ubValue << " vs. " << that->ubValue << endl;
#endif	
				return false;
			}
			return true;
		}
	}
}//InitObjBound::IsEqual

bool OtherObjectiveOption::IsEqual(OtherObjectiveOption *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in OtherObjectiveOption" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if ((this->name        != that->name)     ||
				(this->value       != that->value)    ||
				(this->solver      != that->solver)   ||
				(this->category    != that->category) ||
				(this->type        != that->type)     ||
				(this->description != that->description))  
			{
#ifdef DEBUG_OSOPTION
				cout << "name: "        << this->name        << " vs. " << that->name        << endl;
				cout << "value: "       << this->value       << " vs. " << that->value       << endl;
				cout << "solver: "      << this->solver      << " vs. " << that->solver      << endl;
				cout << "category: "    << this->category    << " vs. " << that->category    << endl;
				cout << "type: "        << this->type        << " vs. " << that->type        << endl;
				cout << "description: " << this->description << " vs. " << that->description << endl;
#endif	
				return false;
			}

			if (this->numberOfObj != that->numberOfObj)  
			{
#ifdef DEBUG_OSOPTION
				cout << "numberOfObj: " << this->numberOfObj << " vs. " << that->numberOfObj << endl;
#endif	
				return false;
			}
			int i;
			for (i = 0; i < numberOfObj; i++)
				if (!this->obj[i]->IsEqual(that->obj[i]))
					return false;
			return true;
		}
	}
}//OtherObjectiveOption::IsEqual

bool OtherObjOption::IsEqual(OtherObjOption *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in OtherObjOption" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if ((this->idx     != that->idx)     || this->name != that->name  || (this->value   != that->value) ||
				(this->lbValue != that->lbValue) || (this->ubValue != that->ubValue))
			{
#ifdef DEBUG_OSOPTION
				cout << "idx: "     << this->idx     << " vs. " << that->idx     << endl;
				cout << "value: "   << this->value   << " vs. " << that->value   << endl;
				cout << "lbValue: " << this->lbValue << " vs. " << that->lbValue << endl;
				cout << "ubValue: " << this->ubValue << " vs. " << that->ubValue << endl;
#endif	
				return false;
			}
			return true;
		}
	}
}//OtherObjOption::IsEqual

bool ConstraintOption::IsEqual(ConstraintOption *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in ConstraintOption" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	
			if (!this->initialConstraintValues->IsEqual(that->initialConstraintValues))
				return false;
			if (!this->initialDualValues->IsEqual(that->initialDualValues))
				return false;
			if (!this->initialBasisStatus->IsEqual(that->initialBasisStatus))
				return false;

			if (this->numberOfOtherConstraintOptions != that->numberOfOtherConstraintOptions)  
			{
#ifdef DEBUG_OSOPTION
				cout << "numberOfOtherConstraintOptions: " << this->numberOfOtherConstraintOptions << " vs. " << that->numberOfOtherConstraintOptions << endl;
#endif	
				return false;
			}
			int i;
			for (i = 0; i < numberOfOtherConstraintOptions; i++)
				if (!this->other[i]->IsEqual(that->other[i]))
					return false;

			return true;
		}
	}
}//ConstraintOption::IsEqual

bool InitConstraintValues::IsEqual(InitConstraintValues *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in InitConstraintValues" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if (this->numberOfCon != that->numberOfCon)  
			{
#ifdef DEBUG_OSOPTION
				cout << "numberOfCon: " << this->numberOfCon << " vs. " << that->numberOfCon << endl;
#endif	
				return false;
			}
			int i;
			for (i = 0; i < numberOfCon; i++)
				if (!this->con[i]->IsEqual(that->con[i]))
					return false;
			return true;
		}
	}
}//InitConstraintValues::IsEqual

bool InitConValue::IsEqual(InitConValue *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in InitConValue" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if ((this->idx != that->idx) || this->name != that->name || !isEqual(this->value, that->value))
			{
#ifdef DEBUG_OSOPTION
				cout << "idx: "   << this->idx   << " vs. " << that->idx   << endl;
				cout << "value: " << this->value << " vs. " << that->value << endl;
#endif	
				return false;
			}
			return true;
		}
	}
}//InitConValue::IsEqual

bool InitDualVariableValues::IsEqual(InitDualVariableValues *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in InitDualVariableValues" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if (this->numberOfCon != that->numberOfCon)  
			{
#ifdef DEBUG_OSOPTION
				cout << "numberOfCon: " << this->numberOfCon << " vs. " << that->numberOfCon << endl;
#endif	
				return false;
			}
			int i;
			for (i = 0; i < numberOfCon; i++)
				if (!this->con[i]->IsEqual(that->con[i]))
					return false;
			return true;
		}
	}
}//InitDualVariableValues::IsEqual

bool InitDualVarValue::IsEqual(InitDualVarValue *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in InitDualVarValue" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if ((this->idx != that->idx) || this->name != that->name || 
				!isEqual(this->lbDualValue, that->lbDualValue) ||
	                        !isEqual(this->ubDualValue, that->ubDualValue))
			{
#ifdef DEBUG_OSOPTION
				cout << "idx: "         << this->idx         << " vs. " << that->idx         << endl;
				cout << "lbDualValue: " << this->lbDualValue << " vs. " << that->lbDualValue << endl;
				cout << "ubDualValue: " << this->ubDualValue << " vs. " << that->ubDualValue << endl;
#endif	
				return false;
			}
			return true;
		}
	}
}//InitDualVarValue::IsEqual

bool OtherConstraintOption::IsEqual(OtherConstraintOption *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in OtherConstraintOption" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if ((this->name        != that->name)     ||
				(this->value       != that->value)    ||
				(this->solver      != that->solver)   ||
				(this->category    != that->category) ||
				(this->type        != that->type)     ||
				(this->description != that->description))  
			{
#ifdef DEBUG_OSOPTION
				cout << "name: "        << this->name        << " vs. " << that->name        << endl;
				cout << "value: "       << this->value       << " vs. " << that->value       << endl;
				cout << "solver: "      << this->solver      << " vs. " << that->solver      << endl;
				cout << "category: "    << this->category    << " vs. " << that->category    << endl;
				cout << "type: "        << this->type        << " vs. " << that->type        << endl;
				cout << "description: " << this->description << " vs. " << that->description << endl;
#endif	
				return false;
			}

			if (this->numberOfCon != that->numberOfCon)  
			{
#ifdef DEBUG_OSOPTION
				cout << "numberOfCon: " << this->numberOfCon << " vs. " << that->numberOfCon << endl;
#endif	
				return false;
			}
			int i;
			for (i = 0; i < numberOfCon; i++)
				if (!this->con[i]->IsEqual(that->con[i]))
					return false;
			return true;
		}
	}
}//OtherConstraintOption::IsEqual

bool OtherConOption::IsEqual(OtherConOption *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in OtherConOption" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if ((this->idx     != that->idx)     || this->name != that->name || (this->value   != that->value) ||
				(this->lbValue != that->lbValue) || (this->ubValue != that->ubValue))
			{
#ifdef DEBUG_OSOPTION
				cout << "idx: "     << this->idx     << " vs. " << that->idx     << endl;
				cout << "value: "   << this->value   << " vs. " << that->value   << endl;
				cout << "lbValue: " << this->lbValue << " vs. " << that->lbValue << endl;
				cout << "ubValue: " << this->ubValue << " vs. " << that->ubValue << endl;
#endif	
				return false;
			}
			return true;
		}
	}
}//OtherConOption::IsEqual


bool SolverOptions::IsEqual(SolverOptions *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in SolverOptions" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{   if (this->numberOfSolverOptions != that->numberOfSolverOptions)  
			{
#ifdef DEBUG_OSOPTION
				cout << "numberOfSolverOptions: " << this->numberOfSolverOptions << " vs. " << that->numberOfSolverOptions << endl;
#endif	
				return false;
			}

			int i;
			for (i = 0; i < numberOfSolverOptions; i++)
				if (!this->solverOption[i]->IsEqual(that->solverOption[i]))
					return false;

			return true;
		}
	}
}//SolverOptions::IsEqual

bool SolverOption::IsEqual(SolverOption *that )
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in SolverOption" << endl;
#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_OSOPTION
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_OSOPTION
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{	if ((this->name        != that->name)     ||
				(this->value       != that->value)    ||
				(this->solver      != that->solver)   ||
				(this->category    != that->category) ||
				(this->type        != that->type)     ||
				(this->description != that->description))  
			{
#ifdef DEBUG_OSOPTION
				cout << "name: "        << this->name        << " vs. " << that->name        << endl;
				cout << "value: "       << this->value       << " vs. " << that->value       << endl;
				cout << "solver: "      << this->solver      << " vs. " << that->solver      << endl;
				cout << "category: "    << this->category    << " vs. " << that->category    << endl;
				cout << "type: "        << this->type        << " vs. " << that->type        << endl;
				cout << "description: " << this->description << " vs. " << that->description << endl;
#endif	
				return false;
			}
			return true;
		}
	}
}//SolverOption::IsEqual


/***********************************************************************
 *
 * Methods to set a random OSOption object.
 *
 * These methods are mostly useful during the debugging process 
 * but might come in handy in other ways
 * The calling sequence is identical in all cases: setRandom( double density, bool conformant ) 
 * @param density gives the probability that a particular child element is generated
 * @param conformant controls whether side constraints (such as agreement of "numberOfChildren" 
 *      attributes with the number of <child> elements) should be enforced (conformant=true) or not
 *
 ***********************************************************************/
bool OSOption::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random OSOption" << endl;
#endif
	if (OSRand() <= density)
	{
		optionHeader = new GeneralFileHeader();
		optionHeader->setRandom(density, conformant);
	}
	if (OSRand() <= density)
	{
		general = new GeneralOption();
		general->setRandom(density, conformant);
	}
	if (OSRand() <= density)       
	{
		system = new SystemOption();
		system->setRandom(density, conformant);
	}
	if (OSRand() <= density)      
	{
		service = new ServiceOption();
		service->setRandom(density, conformant);
	}
	if (OSRand() <= density)          
	{
		job = new JobOption();
		job->setRandom(density, conformant);
	}
	if (OSRand() <= density) 
	{
		optimization = new OptimizationOption();
		optimization->setRandom(density, conformant);
	}
	return true;
}//OSOption::setRandom


bool GeneralOption::setRandom( double density, bool conformant )
{	
#ifdef DEBUG_OSOPTION
	cout << "Set random GeneralOption" << endl;
#endif
	if (OSRand() <= density) this->serviceURI     = "random string";
	if (OSRand() <= density) this->serviceName    = "random string";
	if (OSRand() <= density) this->instanceName   = "random string";
	if (OSRand() <= density) this->jobID          = "random string";
	if (OSRand() <= density) this->solverToInvoke = "random string";
	if (OSRand() <= density) this->license        = "random string";
	if (OSRand() <= density) this->userName       = "random string";
	if (OSRand() <= density) this->password       = "random string";

	if (OSRand() <= density)
	{
		instanceLocation = new InstanceLocationOption(); 
		instanceLocation->setRandom(density, conformant);
	}
	if (OSRand() <= density)          
	{
		contact = new ContactOption(); 
		contact->setRandom(density, conformant);
	}
	if (OSRand() <= density)     
	{
		otherOptions = new OtherOptions(); 
		otherOptions->setRandom(density, conformant);
	}
	return true;
}//GeneralOption::setRandom


bool SystemOption::setRandom( double density, bool conformant )
{	
#ifdef DEBUG_OSOPTION
	cout << "Set random SystemOption" << endl;
#endif
	if (OSRand() <= density)  
	{
		minDiskSpace = new StorageCapacity(); 
		minDiskSpace->setRandom(density, conformant);
	}
	if (OSRand() <= density) 
	{
		minMemorySize = new StorageCapacity(); 
		minMemorySize->setRandom(density, conformant);
	}
	if (OSRand() <= density)   
	{
		minCPUSpeed = new CPUSpeed(); 
		minCPUSpeed->setRandom(density, conformant);
	}
	if (OSRand() <= density)  
	{
		minCPUNumber = new CPUNumber(); 
		minCPUNumber->setRandom(density, conformant);
	}
	if (OSRand() <= density)     
	{
		otherOptions = new OtherOptions(); 
		otherOptions->setRandom(density, conformant);
	}
	return true;
}//SystemOption::setRandom


bool ServiceOption::setRandom( double density, bool conformant )
{	
#ifdef DEBUG_OSOPTION
	cout << "Set random ServiceOption" << endl;
#endif
	if (OSRand() <= density) 
	{
		double temp = OSRand();
		if (conformant) temp = 0.5*temp;

		if      (temp <= 0.25) this->type = "solver";
		else if (temp <= 0.50) this->type = "agent";
		else if (temp <= 0.75) this->type = "";
		else                   this->type = "spy";
	} 

	if (OSRand() <= density)  
	{
		otherOptions = new OtherOptions(); 
		otherOptions->setRandom(density, conformant);
	}
	return true;
}//ServiceOption::setRandom


bool JobOption::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random JobOption" << endl;
#endif
	if (OSRand() <= density) this->requestedStartTime = "1997-08-11T01:23:45-09:13";

	if (OSRand() <= density)                 
	{
		maxTime = new TimeSpan(); 
		maxTime->setRandom(density, conformant);
	}
	if (OSRand() <= density)            
	{
		dependencies = new JobDependencies(); 
		dependencies->setRandom(density, conformant);
	}
	if (OSRand() <= density)     
	{
		requiredDirectories = new DirectoriesAndFiles(); 
		requiredDirectories->setRandom(density, conformant);
	}
	if (OSRand() <= density)           
	{
		requiredFiles = new DirectoriesAndFiles(); 
		requiredFiles->setRandom(density, conformant);
	}
	if (OSRand() <= density)       
	{
		directoriesToMake = new DirectoriesAndFiles(); 
		directoriesToMake->setRandom(density, conformant);
	}
	if (OSRand() <= density)             
	{
		filesToMake = new DirectoriesAndFiles(); 
		filesToMake->setRandom(density, conformant);
	}
	if (OSRand() <= density)  
	{
		inputDirectoriesToMove = new PathPairs(); 
		inputDirectoriesToMove->setRandom(density, conformant);
	}
	if (OSRand() <= density)        
	{
		inputFilesToMove = new PathPairs(); 
		inputFilesToMove->setRandom(density, conformant);
	}
	if (OSRand() <= density)       
	{
		outputFilesToMove = new PathPairs(); 
		outputFilesToMove->setRandom(density, conformant);
	}
	if (OSRand() <= density) 
	{
		outputDirectoriesToMove = new PathPairs(); 
		outputDirectoriesToMove->setRandom(density, conformant);
	}
	if (OSRand() <= density)           
	{
		filesToDelete = new DirectoriesAndFiles(); 
		filesToDelete->setRandom(density, conformant);
	}
	if (OSRand() <= density)     
	{
		directoriesToDelete = new DirectoriesAndFiles(); 
		directoriesToDelete->setRandom(density, conformant);
	}
	if (OSRand() <= density)         
	{
		processesToKill = new Processes(); 
		processesToKill->setRandom(density, conformant);
	}
	if (OSRand() <= density)
	{
		otherOptions = new OtherOptions(); 
		otherOptions->setRandom(density, conformant);
	}
	return true;
}//JobOption::setRandom

bool OptimizationOption::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random OptimizationOption" << endl;
#endif
	if (OSRand() <= density && !conformant) this->numberOfVariables   = (int)(1+9*OSRand());
	if (OSRand() <= density && !conformant) this->numberOfObjectives  = (int)(1+9*OSRand());
	if (OSRand() <= density && !conformant) this->numberOfConstraints = (int)(1+9*OSRand());

	if (OSRand() <= density)    
	{
		variables = new VariableOption(); 
		variables->setRandom(density, conformant);
	}
	if (OSRand() <= density)    
	{
		objectives = new ObjectiveOption(); 
		objectives->setRandom(density, conformant);
	}
	if (OSRand() <= density)   
	{
		constraints = new ConstraintOption(); 
		constraints->setRandom(density, conformant);
	}
	if (OSRand() <= density) 
	{
		solverOptions = new SolverOptions(); 
		solverOptions->setRandom(density, conformant);
	}

	return true;
}//OptimizationOption::setRandom

bool InstanceLocationOption::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random InstanceLocationOption" << endl;
#endif
	if (OSRand() <= density) this->value = "http://www.google.com";
	if (OSRand() <= density) 
	{
		double temp = OSRand();
		if (conformant) temp = 0.5*temp;

		if      (temp <= 0.25) this->locationType = "local";
		else if (temp <= 0.50) this->locationType = "ftp";
		else if (temp <= 0.75) this->locationType = "";
		else                   this->locationType = "global";
	} 
	return true;
}//InstanceLocationOption::setRandom

bool ContactOption::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random ContactOption" << endl;
#endif
	if (OSRand() <= density) this->value = "http://www.google.com";
	if (OSRand() <= density) 
	{
		double temp = OSRand();
		if (conformant) temp = 0.5*temp;

		if      (temp <= 0.25) this->transportType = "osp";
		else if (temp <= 0.50) this->transportType = "ftp";
		else if (temp <= 0.75) this->transportType = "";
		else                   this->transportType = "nlp";
	} 
	return true;
}//ContactOption::setRandom

bool OtherOptions::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random OtherOptions" << endl;
#endif
	int n;

	this->numberOfOtherOptions = (int)(1+4*OSRand());

	if (conformant)	n = this->numberOfOtherOptions;
	else            n = (int)(1+4*OSRand());

	other = new OtherOption*[n];

	for (int i = 0; i < n; i++)
	{
		other[i] = new OtherOption();
		other[i]->setRandom(density, conformant);
	}

	return true;
}//OtherOptions::setRandom

bool OtherOption::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random OtherOption" << endl;
#endif
	if (OSRand() <= density || conformant) this->name = "random string"; 
	if (OSRand() <= density) this->value       = "random string"; 
	if (OSRand() <= density) this->description = "random string"; 
	return true;
}//OtherOption::setRandom



bool JobDependencies::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random JobDependencies" << endl;
#endif
	int n;

	this->numberOfJobIDs = (int)(1+4*OSRand());

	if (conformant)	n = this->numberOfJobIDs;
	else            n = (int)(1+4*OSRand());

	jobID = new std::string[n];
	for (int i = 0; i < n; i++)
		jobID[i] = "random string";

	return true;
}//JobDependencies::setRandom

bool DirectoriesAndFiles::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random DirectoriesAndFiles" << endl;
#endif
	int n;

	this->numberOfPaths = (int)(1+4*OSRand());

	if (conformant)	n = this->numberOfPaths;
	else            n = (int)(1+4*OSRand());

	path = new std::string[n];
	for (int i = 0; i < n; i++)
		path[i] = "random string";

	return true;
}//DirectoriesAndFiles::setRandom

bool PathPairs::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random PathPairs" << endl;
#endif
	int n;

	this->numberOfPathPairs = (int)(1+4*OSRand());

	if (conformant)	n = this->numberOfPathPairs;
	else            n =(int)(1+4*OSRand());

	pathPair = new PathPair*[n];
	for (int i = 0; i < n; i++)
	{
		this->pathPair[i] = new PathPair();
		this->pathPair[i]->setRandom(density, conformant);
	}

	return true;
}//PathPairs::setRandom

bool PathPair::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random PathPair" << endl;
#endif
	this->from = "random string";
	this->to   = "random string";
	if (OSRand() <= density) this->makeCopy = (OSRand() <= 0.5);
	return true;
}//PathPair::setRandom

bool Processes::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random Processes" << endl;
#endif
	int n;

	this->numberOfProcesses = (int)(1+4*OSRand());

	if (conformant)	n = this->numberOfProcesses;
	else            n = (int)(1+4*OSRand());

	process = new std::string[n];	
	for (int i = 0; i < n; i++)
		process[i] = "random string";

	return true;
}//Processes::setRandom

bool VariableOption::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random VariableOption" << endl;
#endif
	if (OSRand() <= density) 
	{
		this->initialVariableValues = new InitVariableValues();
		this->initialVariableValues->setRandom(density, conformant);
	}
				return false;
	if (OSRand() <= density) 
	{
		this->initialVariableValuesString = new InitVariableValuesString();
		this->initialVariableValuesString->setRandom(density, conformant);
	}
	if (OSRand() <= density) 
	{
		this->initialBasisStatus = new BasisStatus();
		this->initialBasisStatus->setRandom(density, conformant, 0, 9);
	}
	if (OSRand() <= density) 
	{
		this->integerVariableBranchingWeights = new IntegerVariableBranchingWeights();
		this->integerVariableBranchingWeights->setRandom(density, conformant);
	}
	if (OSRand() <= density) 
	{
		this->sosVariableBranchingWeights = new SOSVariableBranchingWeights();
		this->sosVariableBranchingWeights->setRandom(density, conformant);
	}


	this->numberOfOtherVariableOptions = (int)(4*OSRand());

	int n;

	if (conformant)	n = this->numberOfOtherVariableOptions;
	else            n = (int)(4*OSRand());

	other = new OtherVariableOption*[n];	
	for (int i = 0; i < n; i++)
	{
		other[i] = new OtherVariableOption();
		other[i]->setRandom(density, conformant);
	}
	return true;
}//VariableOption::setRandom

bool InitVariableValues::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random InitVariableValues" << endl;
#endif
	this->numberOfVar = (int)(1+4*OSRand());

	int n;

	if (conformant)	n = this->numberOfVar;
	else            n = (int)(1+4*OSRand());

	var = new InitVarValue*[n];	
	for (int i = 0; i < n; i++)
	{
		var[i] = new InitVarValue();
		var[i]->setRandom(density, conformant);
	}
	return true;
}//InitVariableValues::setRandom

bool InitVarValue::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random InitVarValue" << endl;
#endif
	this->idx = (int)(4*OSRand());

	if (OSRand() <= density) 
		this->name = "random string";

	if (OSRand() <= density) 
	{
		if (OSRand() <= 0.5) this->value = 3.14156;
		else                 this->value = 2.71828;
	}
	return true;
}//InitVarValue::setRandom


bool InitVariableValuesString::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random InitVariableValuesString" << endl;
#endif
	this->numberOfVar = (int)(1+4*OSRand());

	int n;

	if (conformant)	n = this->numberOfVar;
	else            n = (int)(1+4*OSRand());

	var = new InitVarValueString*[n];	
	for (int i = 0; i < n; i++)
	{
		var[i] = new InitVarValueString();
		var[i]->setRandom(density, conformant);
	}
	return true;
}//InitVariableValuesString::setRandom

bool InitVarValueString::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random InitVarValueString" << endl;
#endif
	this->idx = (int)(4*OSRand());

	if (OSRand() <= density) this->name  = "random string";
	if (OSRand() <= density) this->value = "random string";

	return true;
}//InitVarValueString::setRandom


bool IntegerVariableBranchingWeights::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random IntegerVariableBranchingWeights" << endl;
#endif
	this->numberOfVar = (int)(1+4*OSRand());

	int n;

	if (conformant)	n = this->numberOfVar;
	else            n = (int)(1+4*OSRand());

	var = new BranchingWeight*[n];	
	for (int i = 0; i < n; i++)
	{
		var[i] = new BranchingWeight();
		var[i]->setRandom(density, conformant);
	}
	return true;
}//IntegerVariableBranchingWeights::setRandom

bool SOSVariableBranchingWeights::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random SOSVariableBranchingWeights" << endl;
#endif
	this->numberOfSOS = (int)(1+4*OSRand());

	int n;

	if (conformant)	n = this->numberOfSOS;
	else            n = (int)(1+4*OSRand());

	sos = new SOSWeights*[n];	
	for (int i = 0; i < n; i++)
	{
		sos[i] = new SOSWeights();
		sos[i]->setRandom(density, conformant);
	}
	return true;
}//SOSVariableBranchingWeights::setRandom


bool SOSWeights::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random SOSWeights" << endl;
#endif
	this->sosIdx      = (int)(4*OSRand());
	this->numberOfVar = (int)(4*OSRand());

	if (OSRand() <= density) this->groupWeight = OSRand();


	int n;

	if (conformant)	n = this->numberOfVar;
	else            n = (int)(4*OSRand());

	var = new BranchingWeight*[n];	
	for (int i = 0; i < n; i++)
	{
		var[i] = new BranchingWeight();
		var[i]->setRandom(density, conformant);
	}
	return true;
}//SOSWeights::setRandom


bool BranchingWeight::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random BranchingWeight" << endl;
#endif
	this->idx = (int)(4*OSRand());

	if (OSRand() <= density) this->name  = "random string";

	if (OSRand() <= density) 
		this->value = OSRand();
	return true;
}//BranchingWeight::setRandom

bool OtherVariableOption::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random OtherVariableOption" << endl;
#endif
	this->name = "random string";
	if (OSRand() <= density) this->name        = "randon string";
	if (OSRand() <= density) this->value       = "randon string";
	if (OSRand() <= density) this->solver      = "randon string";
	if (OSRand() <= density) this->category    = "randon string";
	if (OSRand() <= density) this->type        = "randon string";
	if (OSRand() <= density) this->description = "randon string";

	if (OSRand() <= density) 
	{
		if (OSRand() <= 0.5)
		{
			this->numberOfVar = (int)(4*OSRand());

			int n;

			if (conformant)	n = this->numberOfVar;
			else            n = (int)(4*OSRand());

			var = new OtherVarOption*[n];	
			for (int i = 0; i < n; i++)
			{
				var[i] = new OtherVarOption();
				var[i]->setRandom(density, conformant);
			}
		}
		else
		{
			this->numberOfEnumerations = (int)(4*OSRand());

			int n;

			if (conformant)	n = this->numberOfEnumerations;
			else            n = (int)(4*OSRand());

			enumeration = new OtherOptionEnumeration*[n];	
			for (int i = 0; i < n; i++)
			{
				enumeration[i] = new OtherOptionEnumeration();
				enumeration[i]->setRandom(density, conformant, 0, 9);
			}
		}
	}
	return true;
}//OtherVariableOption::setRandom

bool OtherVarOption::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random OtherVarOption" << endl;
#endif
	this->idx = (int)(4*OSRand());
	if (OSRand() <= density) this->name    = "random string";
	if (OSRand() <= density) this->value   = "random string";
	if (OSRand() <= density) this->lbValue = "random string";
	if (OSRand() <= density) this->ubValue = "random string";
	return true;
}//OtherVarOption::setRandom

bool ObjectiveOption::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random ObjectiveOption" << endl;
#endif
	if (OSRand() <= density) 
	{
		this->initialObjectiveValues = new InitObjectiveValues();
		this->initialObjectiveValues->setRandom(density, conformant);
	}
				return false;
	if (OSRand() <= density) 
	{
		this->initialObjectiveBounds = new InitObjectiveBounds();
		this->initialObjectiveBounds->setRandom(density, conformant);
	}
	if (OSRand() <= density) 
	{
		this->initialBasisStatus = new BasisStatus();
		this->initialBasisStatus->setRandom(density, conformant, -2, -1);
	}

	if (OSRand() <= density) 
	{
		this->numberOfOtherObjectiveOptions = (int)(4*OSRand());

		int n;

		if (conformant)	n = this->numberOfOtherObjectiveOptions;
		else            n = (int)(4*OSRand());

		other = new OtherObjectiveOption*[n];	
		for (int i = 0; i < n; i++)
		{
			other[i] = new OtherObjectiveOption();
			other[i]->setRandom(density, conformant);
		}
	}
	return true;
}//ObjectiveOption::setRandom

bool InitObjectiveValues::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random InitObjectiveValues" << endl;
#endif
	this->numberOfObj = (int)(1+4*OSRand());

	int n;

	if (conformant)	n = this->numberOfObj;
	else            n = (int)(1+4*OSRand());

	obj = new InitObjValue*[n];	
	for (int i = 0; i < n; i++)
	{
		obj[i] = new InitObjValue();
		obj[i]->setRandom(density, conformant);
	}
	return true;
}//InitObjectiveValues::setRandom

bool InitObjValue::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random InitObjValue" << endl;
#endif
	if (OSRand() <= 0.5) idx = -1;
	else                 idx = -2;

	if (OSRand() <= density) this->name  = "random string";

	if (OSRand() <= density) 
	{
		if (OSRand() <= 0.5) this->value = 3.14156;
		else                 this->value = 2.71828;
	}
	return true;
}//InitObjValue::setRandom

bool InitObjectiveBounds::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random InitObjectiveBounds" << endl;
#endif
	this->numberOfObj = (int)(1+4*OSRand());

	int n;

	if (conformant)	n = this->numberOfObj;
	else            n = (int)(1+4*OSRand());

	obj = new InitObjBound*[n];	
	for (int i = 0; i < n; i++)
	{
		obj[i] = new InitObjBound();
		obj[i]->setRandom(density, conformant);
	}
	return true;
}//InitObjectiveBounds::setRandom

bool InitObjBound::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random InitObjBound" << endl;
#endif
	if (OSRand() <= 0.5) idx = -1;
	else                 idx = -2;

	if (OSRand() <= density) this->name  = "random string";

	if (OSRand() <= density) 
	{
		if (OSRand() <= 0.5) this->lbValue = 3.14156;
		else                 this->lbValue = 2.71828;
		if (OSRand() <= 0.5) this->ubValue = 3.14156;
		else                 this->ubValue = 2.71828;
	}
	return true;
}//InitObjBound::setRandom

bool OtherObjectiveOption::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random OtherObjectiveOption" << endl;
#endif
	this->name = "random string";
	if (OSRand() <= density) this->name        = "randon string";
	if (OSRand() <= density) this->value       = "randon string";
	if (OSRand() <= density) this->solver      = "randon string";
	if (OSRand() <= density) this->category    = "randon string";
	if (OSRand() <= density) this->type        = "randon string";
	if (OSRand() <= density) this->description = "randon string";

	if (OSRand() <= density) 
	{
		if (OSRand() <= 0.5)
		{
			this->numberOfObj = (int)(4*OSRand());

			int n;

			if (conformant)	n = this->numberOfObj;
			else            n = (int)(4*OSRand());

			obj = new OtherObjOption*[n];	
			for (int i = 0; i < n; i++)
			{
				obj[i] = new OtherObjOption();
				obj[i]->setRandom(density, conformant);
			}
		}
		else
		{
			this->numberOfEnumerations = (int)(4*OSRand());

			int n;

			if (conformant)	n = this->numberOfEnumerations;
			else            n = (int)(4*OSRand());

			enumeration = new OtherOptionEnumeration*[n];	
			for (int i = 0; i < n; i++)
			{
				enumeration[i] = new OtherOptionEnumeration();
				enumeration[i]->setRandom(density, conformant, -2, -1);
			}
		}
	}
	return true;
}//OtherObjectiveOption::setRandom

bool OtherObjOption::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random OtherObjOption" << endl;
#endif
	if (OSRand() <= 0.5) this->idx = -1;
	else                 this->idx = -2;
	if (OSRand() <= density) this->name    = "random string";
	if (OSRand() <= density) this->value   = "random string";
	if (OSRand() <= density) this->lbValue = "random string";
	if (OSRand() <= density) this->ubValue = "random string";
	return true;
}//OtherObjOption::setRandom

bool ConstraintOption::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random ConstraintOption" << endl;
#endif
	if (OSRand() <= density) 
	{
		this->initialConstraintValues = new InitConstraintValues();
		this->initialConstraintValues->setRandom(density, conformant);
	}
				return false;
	if (OSRand() <= density) 
	{
		this->initialDualValues = new InitDualVariableValues();
		this->initialDualValues->setRandom(density, conformant);
	}
	if (OSRand() <= density) 
	{
		this->initialBasisStatus = new BasisStatus();
		this->initialBasisStatus->setRandom(density, conformant, 0, 4);
	}

	if (OSRand() <= density) 
	{
		this->numberOfOtherConstraintOptions = (int)(4*OSRand());

		int n;

		if (conformant)	n = this->numberOfOtherConstraintOptions;
		else            n = (int)(4*OSRand());

		other = new OtherConstraintOption*[n];	
		for (int i = 0; i < n; i++)
		{
			other[i] = new OtherConstraintOption();
			other[i]->setRandom(density, conformant);
		}
	}
	return true;
}//ConstraintOption::setRandom

bool InitConstraintValues::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random InitConstraintValues" << endl;
#endif
	this->numberOfCon = (int)(1+4*OSRand());

	int n;

	if (conformant)	n = this->numberOfCon;
	else            n = (int)(1+4*OSRand());

	con = new InitConValue*[n];	
	for (int i = 0; i < n; i++)
	{
		con[i] = new InitConValue();
		con[i]->setRandom(density, conformant);
	}
	return true;
}//InitConstraintValues::setRandom

bool InitConValue::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random InitConValue" << endl;
#endif
	this->idx = (int)(4*OSRand());

	if (OSRand() <= density) this->name  = "random string";

	if (OSRand() <= density) 
	{
		if (OSRand() <= 0.5) this->value = 3.14156;
		else                 this->value = 2.71828;
	}
	return true;
}//InitConValue::setRandom

bool InitDualVariableValues::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random InitDualVariableValues" << endl;
#endif
	this->numberOfCon = (int)(1+4*OSRand());

	int n;

	if (conformant)	n = this->numberOfCon;
	else            n = (int)(1+4*OSRand());

	con = new InitDualVarValue*[n];	
	for (int i = 0; i < n; i++)
	{
		con[i] = new InitDualVarValue();
		con[i]->setRandom(density, conformant);
	}
	return true;
}//InitDualVariableValues::setRandom

bool InitDualVarValue::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random InitDualVarValue" << endl;
#endif
	this->idx = (int)(4*OSRand());

	if (OSRand() <= density) this->name  = "random string";

	if (OSRand() <= density) 
	{
		if (OSRand() <= 0.5) this->lbDualValue = 3.14156;
		else                 this->lbDualValue = 2.71828;
		if (OSRand() <= 0.5) this->ubDualValue = 3.14156;
		else                 this->ubDualValue = 2.71828;
	}
	return true;
}//InitDualVarValue::setRandom

bool OtherConstraintOption::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random OtherConstraintOption" << endl;
#endif
	this->name = "random string";
	if (OSRand() <= density) this->name        = "randon string";
	if (OSRand() <= density) this->value       = "randon string";
	if (OSRand() <= density) this->solver      = "randon string";
	if (OSRand() <= density) this->category    = "randon string";
	if (OSRand() <= density) this->type        = "randon string";
	if (OSRand() <= density) this->description = "randon string";

	if (OSRand() <= density) 
	{
		if (OSRand() <= 0.5)
		{
			this->numberOfCon = (int)(4*OSRand());

			int n;

			if (conformant)	n = this->numberOfCon;
			else            n = (int)(4*OSRand());

			con = new OtherConOption*[n];	
			for (int i = 0; i < n; i++)
			{
				con[i] = new OtherConOption();
				con[i]->setRandom(density, conformant);
			}
		}
		else
		{
			this->numberOfEnumerations = (int)(4*OSRand());

			int n;

			if (conformant)	n = this->numberOfEnumerations;
			else            n = (int)(4*OSRand());

			enumeration = new OtherOptionEnumeration*[n];	
			for (int i = 0; i < n; i++)
			{
				enumeration[i] = new OtherOptionEnumeration();
				enumeration[i]->setRandom(density, conformant, 0, 4);
			}
		}
	}
	return true;
}//OtherConstraintOption::setRandom

bool OtherConOption::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random OtherConOption" << endl;
#endif
	this->idx = (int)(4*OSRand());
	if (OSRand() <= density) this->name    = "random string";
	if (OSRand() <= density) this->value   = "random string";
	if (OSRand() <= density) this->lbValue = "random string";
	if (OSRand() <= density) this->ubValue = "random string";
	return true;
}//OtherConOption::setRandom


bool SolverOptions::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random SolverOptions" << endl;
#endif
	this->numberOfSolverOptions = (int)(1+4*OSRand());

	int n;

	if (conformant)	n = this->numberOfSolverOptions;
	else            n = (int)(1+4*OSRand());

	solverOption = new SolverOption*[n];	
	for (int i = 0; i < n; i++)
	{
		solverOption[i] = new SolverOption();
		solverOption[i]->setRandom(density, conformant);
	}
	return true;
}//SolverOptions::setRandom

bool SolverOption::setRandom( double density, bool conformant )
{
#ifdef DEBUG_OSOPTION
	cout << "Set random SolverOption" << endl;
#endif
	if (OSRand() <= density || conformant) this->name = "random string";

	if (OSRand() <= density) this->value       = "random string";
	if (OSRand() <= density) this->solver      = "random string";
	if (OSRand() <= density) this->category    = "random string";
	if (OSRand() <= density) this->type        = "random string";
	if (OSRand() <= density) this->description = "random string";

	if (OSRand() <= density)
	{
		this->numberOfItems = (int)(4*OSRand());

		int n;

		if (conformant)	n = this->numberOfItems;
		else            n = (int)(4*OSRand());

		item = new std::string[n];	
		for (int i = 0; i < n; i++)
			item[i] = "random string";
	}
	return true;
}//SolverOption::setRandom
