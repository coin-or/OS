/** @file OSOption.cpp
 * 
 *
 * @author Horand Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.0, 29/Nov/2008
 * @since   OS1.1
 *
 * \remarks
 * Copyright (C) 2005-2009, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, Dalhousie University and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */

//#define DEBUG

#ifdef  DEBUG
#define DEBUG_OSOPTION
#endif

#include "OSOption.h"
#include "OSParameters.h"
#include "OSErrorClass.h"
#include "CoinFinite.hpp"
#include <iostream> 
#include <sstream>
#include <limits>
#include <cstdio>

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
}// end MinDiskSpace constructor


MinMemorySize::MinMemorySize():
	unit ("byte"),
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
}// end MinMemorySize constructor


MinCPUSpeed::MinCPUSpeed():
	unit ("hertz"),
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
}// end MinCPUSpeed constructor


SystemOption::SystemOption(): 
	minCPUNumber (1)
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside SystemOption Constructor" << endl;
	#endif
	minDiskSpace = NULL;
	minMemorySize = NULL;
	minCPUSpeed = NULL;
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


MaxTime::MaxTime():
	unit ("second"),
	value (OSDBL_MAX)
{
	#ifdef DEBUG_OSOPTION
	cout << "Inside MaxTime Constructor" << endl;
	#endif
}// end MaxTime constructor

MaxTime::~MaxTime()
{
	#ifdef DEBUG_OSOPTION
	cout << "MaxTime Destructor Called" << endl;
	#endif
}// end MaxTime constructor


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
}// end DirectoriesAndFiles constructor  template

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
	numberOfVar (0),
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
}// end OtherVariableOption constructor  

OtherVariableOption::~OtherVariableOption()
{    
	#ifdef DEBUG_OSOPTION
	cout << "OtherVariableOption Destructor Called" << endl;
	#endif
	if (var != NULL) 
	{	int i;
		for (i=0; i < numberOfVar; i++)
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
	numberOfObj (0),
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
}// end OtherObjectiveOption constructor  

OtherObjectiveOption::~OtherObjectiveOption()
{    
	#ifdef DEBUG_OSOPTION
	cout << "OtherObjectiveOption Destructor Called" << endl;
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
}//end OtherObjectiveOption destructor 


ObjectiveOption::ObjectiveOption(): 
	numberOfOtherObjectiveOptions (0)
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside ObjectiveOption Constructor" << endl;
	#endif
	initialObjectiveValues = NULL;
	initialObjectiveBounds = NULL;
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
}// end OtherConstraintOption constructor  

OtherConstraintOption::~OtherConstraintOption()
{    
	#ifdef DEBUG_OSOPTION
	cout << "OtherConstraintOption Destructor Called" << endl;
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
}//end OtherConstraintOption destructor


ConstraintOption::ConstraintOption(): 
	numberOfOtherConstraintOptions (0)
{    
	#ifdef DEBUG_OSOPTION
	cout << "Inside ConstraintOption Constructor" << endl;
	#endif
	initialConstraintValues = NULL;
	initialDualValues = NULL;
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
	description ("")
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
		cout << "loop completed" << endl;
		delete[] solverOption;
		solverOption = NULL;
		cout << "SolverOptions destructor completed" << endl;
	}
}//end SolverOptions destructor


OptimizationOption::OptimizationOption(): 
	numberOfVariables (0),
	numberOfObjectives (1),
	numberOfConstraints (0)
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
 * get the memory units (in <system> element)
 */
std::string  OSOption::getMinMemoryUnit()
{	if (this->system != NULL) 
		if (this->system->minMemorySize != NULL)
			return this->system->minMemorySize->unit;

	return "";
}//getMinMemory

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
		return this->system->minCPUNumber;

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
	//cout << "step through getNumberOfInitVarValues" << endl;
	if (this->optimization != NULL) 
	{	
		//cout << "optimization is not NULL" << endl;
		if (this->optimization->variables != NULL) 
		{	
			//cout << "variables is not NULL" << endl;
			if (this->optimization->variables->initialVariableValues != NULL) 
			{	
				//cout << "initialVariableValues is not NULL: ";
				cout << this->optimization->variables->initialVariableValues->numberOfVar << endl;
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
 * get the number of variables that are given initial basis status (in <optimization> element)
 */
int OSOption::getNumberOfInitialBasisVariables()
{	if (this->optimization != NULL) 
		if (this->optimization->variables != NULL) 
			if (this->optimization->variables->initialBasisStatus != NULL) 
				return this->optimization->variables->initialBasisStatus->numberOfVar;
	return -1;
}//getNumberOfInitialBasisVariables

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

	if (optionName == "numberOfInitialBasisVariables")
		return this->getNumberOfInitialBasisVariables();

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
					cout << "Initial variables: (OSNAN = " << OSNAN << ")" << endl;
					for (i = 0; i < numberOfVariables; i++) cout << m_mdInitVarValuesDense[i] << endl;
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
 * get the list of initial basic and nonbasic variables in sparse form
 * @return a list of index/value pairs
 */
InitBasStatus**  OSOption::getInitBasisStatusSparse()
{	InitBasStatus** initBasVector;
	if (this->optimization != NULL) 
	{	if (this->optimization->variables != NULL) 
		{	if (this->optimization->variables->initialBasisStatus != NULL)
				initBasVector = this->optimization->variables->initialBasisStatus->var;
			else
				throw ErrorClass("<initialBasisStatus> object must be defined before getting the data");
		}
		else
			throw ErrorClass("<variables> object must be defined before getting the data");
	}
	else
		throw ErrorClass("<optimization> object must be defined before getting the data");
	return initBasVector;
}//getInitVarStringsSparse

/**
 * get the list of initial basic and nonbasic variables in dense form
 * @return an array of value strings
 * @note return the empty string "" for variables that are not initialed
 */
std::string *OSOption::getInitBasisStatusDense()
{	try
	{	int numberOfVariables;
		numberOfVariables = this->getNumberOfVariables();
		if (numberOfVariables < 0)
			throw ErrorClass("\"numberOfVariables\" must be present to use dense methods");		

		if (this->optimization != NULL) 
		{	if (this->optimization->variables != NULL) 
			{	if (this->optimization->variables->initialBasisStatus != NULL) 
				{	int i,j,k;
					int num_var;
					num_var = this->getNumberOfInitialBasisVariables();

					if (m_mdInitBasisStatusDense != NULL)
						delete [] m_mdInitBasisStatusDense;
					m_mdInitBasisStatusDense = new std::string[numberOfVariables];
					for (k = 0; k < numberOfVariables; k++) m_mdInitBasisStatusDense[k] = "";
		
					for (i = 0; i < num_var; i++)
					{	j = this->optimization->variables->initialBasisStatus->var[i]->idx;
						if (j >= 0 && j < numberOfVariables)
							m_mdInitBasisStatusDense[j] 
							  = this->optimization->variables->initialBasisStatus->var[i]->value;
						else
							throw ErrorClass("Variable index out of range");
					}
					return m_mdInitBasisStatusDense;
				}
			}
		}					
	}
	catch(const ErrorClass& eclass)
	{	throw ErrorClass(eclass.errormsg);
	}
	return NULL;
}//getInitBasisStatusDense

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
							throw ErrorClass("Objective index out of range");
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
							throw ErrorClass("Objective index out of range");
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
							throw ErrorClass("Objective index out of range");
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
 *  used to add an <other> element in <general>, <system>, <service> and <job>
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
bool SOSVariableBranchingWeights::addSOS(int sosIdx, int nvar, double weight, int* idx, double* value)
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
}//setVar

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

		if (other->numberOfCon > 0)
		{	
			temp[ nopt]->con = new OtherConOption*[other->numberOfCon];
			for (j = 0; j < other->numberOfCon; j++)
			{	 temp[ nopt]->con[j] = new OtherConOption();
				*temp[ nopt]->con[j] = *other->con[j];
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
		{	 this->solverOption[i] = new SolverOption();
			*this->solverOption[i] = *solverOption[i];
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
	{	int nopt; int i;
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

bool OSOption::setInstanceLocationType( std::string locationType)
{	try
	{	if (this->general == NULL) 
			this->general = new GeneralOption();
		if (this->general->instanceLocation == NULL) 
			this->general->instanceLocation = new InstanceLocationOption();
		
		if ((locationType != "local") && (locationType != "http") && (locationType != "ftp"))
			throw ErrorClass( "location type not recognized.");

		this->general->instanceLocation->locationType = locationType;
		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
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

bool OSOption::setContactTransportType( std::string transportType)
{	try
	{	if (this->general == NULL) 
			this->general = new GeneralOption();
		if (this->general->contact == NULL) 
			this->general->contact = new ContactOption();
		
		if ((transportType != "osp") && (transportType != "http") && (transportType != "smtp") && 
			(transportType != "ftp") && (transportType != "other"))
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
{	if (this->general == NULL) 
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
{	if (this->general == NULL) 
		this->general = new GeneralOption();
	if (this->general->otherOptions == NULL) 
		this->general->otherOptions = new OtherOptions();
	return this->general->otherOptions->addOther(name, value, description);
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
{	try
	{	if (this->system == NULL) 
			this->system = new SystemOption();
		if (this->system->minDiskSpace == NULL)
			this->system->minDiskSpace = new MinDiskSpace();
		
		if ((unit != "petabyte") && (unit != "terabyte") && (unit != "gigabyte") &&
			(unit != "megabyte") && (unit != "kilobyte") && (unit != "byte"))
			throw ErrorClass( "disk space unit not recognized.");

		this->system->minDiskSpace->unit = unit;
		return true;
	}
	catch(const ErrorClass& eclass)
	{	cout << eclass.errormsg << endl;
		return false;
	}
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
{	try
	{	if (this->system == NULL) 
			this->system = new SystemOption();
		if (this->system->minMemorySize == NULL)
			this->system->minMemorySize = new MinMemorySize();
		
		if ((unit != "petabyte") && (unit != "terabyte") && (unit != "gigabyte") &&
			(unit != "megabyte") && (unit != "kilobyte") && (unit != "byte"))
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
		this->system->minCPUSpeed = new MinCPUSpeed();
	this->system->minCPUSpeed->value = value;
	return true;
}//setMinCPUSpeed

bool OSOption::setMinCPUSpeedUnit(std::string unit)
{	try
	{	if (this->system == NULL) 
			this->system = new SystemOption();
		if (this->system->minCPUSpeed == NULL)
			this->system->minCPUSpeed = new MinCPUSpeed();
		
		if ((unit != "petaflops") && (unit != "teraflops") && (unit != "gigaflops") &&
			(unit != "megaflops") && (unit != "kiloflops") && (unit != "flops")     &&
			(unit != "petahertz") && (unit != "terahertz") && (unit != "gigahertz") &&
			(unit != "megahertz") && (unit != "kilohertz") && (unit != "hertz")        	)
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
{	if (this->system == NULL) 
		this->system = new SystemOption();
	this->system->minCPUNumber = number;
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
		
		if ((serviceType != "analyzer" ) && (serviceType != "solver" ) && 
			(serviceType != "scheduler") && (serviceType != "modeler") &&
			(serviceType != "registry" ) && (serviceType != "agent"  ) && 
			(serviceType != "simulations"))
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
		this->job->maxTime = new MaxTime();
	this->job->maxTime->value = value;
	return true;
}//setMaxTime

bool OSOption::setMaxTimeUnit(std::string unit)
{	try
	{	if (this->job == NULL) 
			this->job = new JobOption();
		if (this->job->maxTime == NULL)
			this->job->maxTime = new MaxTime();
		
		if ((unit != "second") && (unit != "minute") && (unit != "hour")  &&
			(unit != "day")    && (unit != "week")   && (unit != "month") && 
			(unit != "year"))
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
	{	cout << OSNAN << "   " << value[i] << "  " << CoinIsnan(value[i]) << endl;
		if (!CoinIsnan(value[i]))
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


bool OSOption::setInitBasisStatusSparse(int numberOfVar, InitBasStatus** var)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL) 
		this->optimization->variables = new VariableOption();
	if (this->optimization->variables->initialBasisStatus == NULL) 
		this->optimization->variables->initialBasisStatus = new InitialBasisStatus();
	else
	{	int i;
		for (i = 0; i < this->optimization->variables->initialBasisStatus->numberOfVar; i++)
			delete this->optimization->variables->initialBasisStatus->var[i];
		delete[] this->optimization->variables->initialBasisStatus->var;
		this->optimization->variables->initialBasisStatus->var = NULL;
	}
	return this->optimization->variables->initialBasisStatus->setVar(numberOfVar, var);
}//setInitBasisStatusSparse

bool OSOption::setInitBasisStatusDense(int numberOfVar, std::string *value)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL) 
		this->optimization->variables = new VariableOption();
	if (this->optimization->variables->initialBasisStatus == NULL) 
		this->optimization->variables->initialBasisStatus = new InitialBasisStatus();
	else
	{	delete[] this->optimization->variables->initialBasisStatus->var;
		this->optimization->variables->initialBasisStatus->var = NULL;
	}
	int i;
	for (i = 0; i < numberOfVar; i++)
	{	if ((value[i] == "superbasic") || (value[i] == "atLower") || (value[i] == "basic")
	                                   || (value[i] == "atUpper") || (value[i] == "unknown"))
			if (!this->optimization->variables->initialBasisStatus->addVar(i, value[i]))
				return false;
	}
	return true;
}//setInitBasisStatusDense

bool OSOption::setAnotherInitBasisStatus(int idx, std::string value)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL) 
		this->optimization->variables = new VariableOption();
	if (this->optimization->variables->initialBasisStatus == NULL) 
		this->optimization->variables->initialBasisStatus = new InitialBasisStatus();
	return this->optimization->variables->initialBasisStatus->addVar(idx, value);
}//setAnotherInitBasisStatus


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
	{	if (!CoinIsnan(value[i]))
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

bool OSOption::setAnotherSOSVariableBranchingWeight(int sosIdx, int nvar, double weight, int* idx, double* value)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL) 
		this->optimization->variables = new VariableOption();
	if (this->optimization->variables->sosVariableBranchingWeights == NULL) 
		this->optimization->variables->sosVariableBranchingWeights = new SOSVariableBranchingWeights();
	return this->optimization->variables->sosVariableBranchingWeights->addSOS(sosIdx, nvar, weight, idx, value);
}//setAnotherSOSVariableBranchingWeight


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
	{	if (!CoinIsnan(value[i]))
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
	{	if (!CoinIsnan(value[i]))
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
		{	if (!this->general->IsEqual(that->general))
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
		{	if (this->minCPUNumber != that->minCPUNumber)
			{
				#ifdef DEBUG_OSOPTION
				cout << "minCPUNumber: " << this->minCPUNumber << " vs. " << that->minCPUNumber << endl;
				#endif
				return false;
			}

			if (!this->minDiskSpace->IsEqual(that->minDiskSpace))
				return false;
			if (!this->minMemorySize->IsEqual(that->minMemorySize))
				return false;
			if (!this->minCPUSpeed->IsEqual(that->minCPUSpeed))
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
			if (!this->otherOptions->IsEqual(that->otherOptions))
				return false;
			if (!this->otherOptions->IsEqual(that->otherOptions))
				return false;
			if (!this->otherOptions->IsEqual(that->otherOptions))
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
		{	if ((this->unit  != that->unit)  || 
				(this->value != that->value) ) 
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
		{	if ((this->unit  != that->unit)  || 
				(this->value != that->value) ) 
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


bool MaxTime::IsEqual(MaxTime *that)
{
#ifdef DEBUG_OSOPTION
	cout << "Start comparing in MaxTime" << endl;
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
		{	if ((this->unit  != that->unit)  || 
				(this->value != that->value) ) 
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
}//MaxTime::IsEqual

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
		{	if ((this->unit  != that->unit)  || 
				(this->value != that->value) ) 
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
		{	if ((this->idx != that->idx) || (this->value != that->value))
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
		{	if ((this->idx != that->idx) || (this->value != that->value))
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
			{	cout << "SOS " << i << " of " << numberOfSOS << endl;
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
				(this->groupWeight != that->groupWeight))  
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
			{	cout << "var[" << i << "] of " << numberOfVar << endl;
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
		{	if ((this->idx != that->idx) || (this->value != that->value))
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
		{	if ((this->idx     != that->idx)     || (this->value   != that->value) ||
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
		{	if ((this->idx != that->idx) || (this->value != that->value))
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
		{	if ((this->idx     != that->idx)    || (this->lbValue != that->lbValue) || 
				(this->ubValue != that->ubValue) )
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
		{	if ((this->idx     != that->idx)     || (this->value   != that->value) ||
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
		{	if ((this->idx != that->idx) || (this->value != that->value))
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
		{	if ((this->idx != that->idx) || (this->lbDualValue != that->lbDualValue) ||
				(this->ubDualValue != that->ubDualValue))
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
		{	if ((this->idx     != that->idx)     || (this->value   != that->value) ||
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

bool SolverOption::IsEqual(SolverOption *that)
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
