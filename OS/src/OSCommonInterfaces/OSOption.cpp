/** @file OSOption.cpp
 * 
 *
 * @author Horand Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.0, 29/Nov/2008
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

	if (other != NULL){
		for ( int i=0; i<numberOfOtherOptions; i++){
			cout << "delete other general option " << i << endl;
			delete other[i];
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

	if (jobID != NULL) {
		delete[] jobID;
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

BranchingWeight::BranchingWeight(): 
	idx (-1),
	value (0.0)
{    
	#ifdef DEBUG
	cout << "Inside BranchingWeight Constructor" << endl;
	#endif
}// end BranchingWeight constructor  

BranchingWeight::~BranchingWeight()
{    
	#ifdef DEBUG
	cout << "BranchingWeight Destructor Called" << endl;
	#endif
}//end BranchingWeight destructor 


IntegerVariableBranchingWeights::IntegerVariableBranchingWeights():
	numberOfVar (0)
{    
	#ifdef DEBUG
	cout << "Inside IntegerVariableBranchingWeights Constructor" << endl;
	#endif
	var = NULL;
}// end IntegerVariableBranchingWeights constructor  

IntegerVariableBranchingWeights::~IntegerVariableBranchingWeights()
{    
	#ifdef DEBUG
	cout << "IntegerVariableBranchingWeights Destructor Called" << endl;
	#endif
	if (var != NULL) 
	{	for (int i=0; i < numberOfVar; i++)
		{	delete var[i];
			var[i] = NULL;
		}
		delete[] var;
		var = NULL;
	}
}//end IntegerVariableBranchingWeights destructor 

SOSWeights::SOSWeights():
	sosIdx (-1),
	groupWeight (0.0),
	numberOfVar (0)
{    
	#ifdef DEBUG
	cout << "Inside SOSWeights Constructor" << endl;
	#endif
	var = NULL;
}// end SOSWeights constructor  

SOSWeights::~SOSWeights()
{    
	#ifdef DEBUG
	cout << "SOSWeights Destructor Called" << endl;
	#endif
	if (var != NULL) 
	{	for (int i=0; i < numberOfVar; i++)
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
	#ifdef DEBUG
	cout << "Inside SOSVariableBranchingWeights Constructor" << endl;
	#endif
	sos = NULL;
}// end SOSVariableBranchingWeights constructor  

SOSVariableBranchingWeights::~SOSVariableBranchingWeights()
{    
	#ifdef DEBUG
	cout << "SOSVariableBranchingWeights Destructor Called" << endl;
	#endif
	if (sos != NULL) 
	{	for (int i=0; i < numberOfSOS; i++)
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
	integerVariableBranchingWeights = NULL;
	sosVariableBranchingWeights = NULL;
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
	if (integerVariableBranchingWeights != NULL) delete integerVariableBranchingWeights;
	integerVariableBranchingWeights = NULL;
	if (sosVariableBranchingWeights != NULL) delete sosVariableBranchingWeights;
	sosVariableBranchingWeights = NULL;
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


OSOption::OSOption() 
//(initializations)
{    
	#ifdef DEBUG
	cout << "Inside OSOption Constructor" << endl;
	#endif

	general = NULL;
	system = NULL;
	service = NULL;
	job = NULL;
	optimization = NULL;
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
}//getSolverName

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
}//getTransportType

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
 * get the scheduled start time (in <job> element)
 */
std::string  OSOption::getScheduledStartTime()
{	if (this->job != NULL) 
		return this->job->scheduledStartTime;

	return "";
}//getScheduledStartTime

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

	if (optionName == "scheduledStartTime") 
		return this->getScheduledStartTime();

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
 * get the number of proceses to kill (in <job> element)
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

	return 0;
}//getNumberOfVariables

/**
 * get the number of objectives (in <optimization> element)
 */
int  OSOption::getNumberOfObjectives()
{	if (this->optimization != NULL) 
		return this->optimization->numberOfObjectives;

	return 0;
}//getNumberOfObjectives

/**
 * get the number of constraints (in <optimization> element)
 */
int  OSOption::getNumberOfConstraints()
{	if (this->optimization != NULL) 
		return this->optimization->numberOfConstraints;

	return 0;
}//getNumberOfConstraints


/**
 * get the number of variables that have initial values (in <optimization> element)
 */
int OSOption::getNumberOfInitVarValues()
{	if (this->optimization != NULL) 
		if (this->optimization->variables != NULL) 
			if (this->optimization->variables->initialVariableValues != NULL) 
				return this->optimization->variables->initialVariableValues->numberOfVar;
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
int OSOption::getNumberOfSOSWeights()
{	if (this->optimization != NULL) 
		if (this->optimization->variables != NULL) 
			if (this->optimization->variables->sosVariableBranchingWeights != NULL) 
				return this->optimization->variables->sosVariableBranchingWeights->numberOfSOS;
	return -1;
}//getNumberOfSOSWeights

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
int OSOption::getNumberOfSolverOptions(){
	if (this->optimization != NULL) {
		if (this->optimization->solverOptions != NULL) {
			return this->optimization->solverOptions->numberOfSolverOptions;
		}
	}
	return -1;
}//getNumberOfSolverOptions

/**
 * get the value of an integer-valued option
 * @param optionName The name of the option
 * @return the value of the option optionName
 * @note This function returns 0 if optionName is not found
 */
int  OSOption::getOptionInt(std::string optionName)
{	if (optionName == "minCPUNumber")
		this->getMinCPUNumber();

	if (optionName == "numberOfOtherGeneralOptions")
		this->getNumberOfOtherGeneralOptions();

	if (optionName == "numberOfOtherSystemOptions")
		this->getNumberOfOtherSystemOptions();

	if (optionName == "numberOfOtherServiceOptions")
		this->getNumberOfOtherServiceOptions();

	if (optionName == "numberOfOtherJobOptions")
		this->getNumberOfOtherJobOptions();

	if (optionName == "numberOfJobDependencies")
		this->getNumberOfJobDependencies();

	if (optionName == "numberOfRequiredDirectories")
		this->getNumberOfRequiredDirectories();

	if (optionName == "numberOfRequiredFiles")
		this->getNumberOfRequiredFiles();

	if (optionName == "numberOfDirectoriesToMake")
		this->getNumberOfDirectoriesToMake();

	if (optionName == "numberOfFilesToMake")
		this->getNumberOfFilesToMake();

	if (optionName == "numberOfInputDirectoriesToMove")
		this->getNumberOfInputDirectoriesToMove();

	if (optionName == "numberOfInputFilesToMove")
		this->getNumberOfInputFilesToMove();

	if (optionName == "numberOfOutputDirectoriesToMove")
		this->getNumberOfOutputDirectoriesToMove();

	if (optionName == "numberOfOutputFilesToMove")
		this->getNumberOfOutputFilesToMove();

	if (optionName == "numberOfFilesToDelete")
		this->getNumberOfFilesToDelete();

	if (optionName == "numberOfDirectoriesToDelete")
		this->getNumberOfDirectoriesToDelete();

	if (optionName == "numberOfProcessesToKill")
		this->getNumberOfProcessesToKill();

	if (optionName == "numberOfVariables")
		this->getNumberOfVariables();

	if (optionName == "numberOfObjectives")
		this->getNumberOfObjectives();

	if (optionName == "numberOfConstraints")
		this->getNumberOfConstraints();

	if (optionName == "numberOfInitVarValues")
		this->getNumberOfInitVarValues();

	if (optionName == "numberOfInitVarValuesString")
		this->getNumberOfInitVarValuesString();

	if (optionName == "numberOfInitialBasisVariables")
		this->getNumberOfInitialBasisVariables();

	if (optionName == "numberOfIntegerVariableBranchingWeights")
		this->getNumberOfIntegerVariableBranchingWeights();

	if (optionName == "numberOfSOSWeights")
		this->getNumberOfSOSWeights();

	if (optionName == "numberOfOtherVariableOptions")
		this->getNumberOfOtherVariableOptions();

	if (optionName == "numberOfInitObjValues")
		this->getNumberOfInitObjValues();

	if (optionName == "numberOfInitObjBounds")
		this->getNumberOfInitObjBounds();

	if (optionName == "numberOfOtherObjectiveOptions")
		this->getNumberOfOtherObjectiveOptions();

	if (optionName == "numberOfInitConValues")
		this->getNumberOfInitConValues();

	if (optionName == "numberOfInitDualVarValues")
		this->getNumberOfInitDualVarValues();

	if (optionName == "numberOfOtherConstraintOptions")
		this->getNumberOfOtherConstraintOptions();

	if (optionName == "numberOfSolverOptions")
		this->getNumberOfSolverOptions();

	return 0;
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

/**
 * get the array of job dependencies
 */
std::string*  OSOption::getJobDependencies(){
	std::string* dependenciesVector = NULL;
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
std::string*  OSOption::getRequiredDirectories(){
	std::string* pathVector = NULL;
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
 * get the list of directories that need to be created
 */
std::string*  OSOption::getDirectoriesToMake(){
	std::string* pathVector = NULL;
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
std::string*  OSOption::getFilesToMake(){
	std::string* pathVector = NULL;
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
std::string*  OSOption::getFilesToDelete(){
	std::string* pathVector = NULL;
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
std::string*  OSOption::getDirectoriesToDelete(){
	std::string* pathVector = NULL;
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
std::string*  OSOption::getProcessesToKill(){
	std::string* processes = NULL;
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
double* OSOption::getInitVarValuesDense(int numberOfVariables){
	double *initVarVector;
	initVarVector = new double[numberOfVariables];
	for (int k = 0; k < numberOfVariables; k++) initVarVector[k] = OSNAN;
	try
	{	if (this->optimization != NULL) 
		{	if (this->optimization->variables != NULL) 
			{	if (this->optimization->variables->initialVariableValues != NULL) 
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

/**
 * get the list of initial values for string-valued variables in sparse form
 * @return a list of index/value pairs
 */
InitVarValueString**  OSOption::getInitVarStringsSparse()
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
}//getInitVarStringsSparse

/**
 * get the list of initial values for string-valued variables in dense form
 * @return an array of value strings
 * @note return the empty string "" for variables that are not initialed
 */
std::string *OSOption::getInitVarStringsDense(int numberOfVariables){
	std::string *initVarVector;
	initVarVector = new std::string[numberOfVariables];
	for (int k = 0; k < numberOfVariables; k++) initVarVector[k] = "";
	try
	{
		if (this->optimization != NULL) 
		{	if (this->optimization->variables != NULL) 
			{	if (this->optimization->variables->initialVariableValuesString != NULL) 
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
std::string *OSOption::getInitBasisStatusDense(int numberOfVariables){
	std::string *initBasVector;
	initBasVector = new std::string[numberOfVariables];
	for (int k = 0; k < numberOfVariables; k++) initBasVector[k] = "";
	try
	{
		if (this->optimization != NULL) 
		{	if (this->optimization->variables != NULL) 
			{	if (this->optimization->variables->initialBasisStatus != NULL) 
				{	int i,j;
					int num_var;
					num_var = this->getNumberOfInitVarValuesString();
					for(i = 0; i < num_var; i++)
					{	j = this->optimization->variables->initialVariableValuesString->var[i]->idx;
						if (j >= 0 && j < numberOfVariables)
							initBasVector[j] 
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
	return initBasVector;
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
 * get a list of branching weights for integer variables in sparse form
 * @return an array of values
 * @note return OSNAN for variables that are not initialed
 */
double* OSOption::getIntegerVariableBranchingWeightsDense(int numberOfVariables)
{	double *intVarVector;
	intVarVector = new double[numberOfVariables];
	for (int k = 0; k < numberOfVariables; k++) intVarVector[k] = OSNAN;
	try
	{	if (this->optimization != NULL) 
		{	if (this->optimization->variables != NULL) 
			{	if (this->optimization->variables->integerVariableBranchingWeights != NULL) 
				{	int i,j;
					int num_var;
					num_var = this->getNumberOfIntegerVariableBranchingWeights();
					for(i = 0; i < num_var; i++)
					{	j = this->optimization->variables->integerVariableBranchingWeights->var[i]->idx;
						if (j >= 0 && j < numberOfVariables)						
							intVarVector[j] 
							  = this->optimization->variables->integerVariableBranchingWeights->var[i]->value;						
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
	return intVarVector;

}//getIntegerVariableBranchingWeightsDense

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
double* OSOption::getInitObjValuesDense(int numberOfObjectives){
	double *initObjVector;
	initObjVector = new double[numberOfObjectives];
	for (int k = 0; k < numberOfObjectives; k++) initObjVector[k] = OSNAN;
	try
	{	if (this->optimization != NULL) 
		{	if (this->optimization->objectives != NULL) 
			{	if (this->optimization->objectives->initialObjectiveValues != NULL) 
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


/**
 * get the list of initial objective bounds in sparse form
 * @return a list of index/value/value triples
 */
InitObjBound**  OSOption::getInitObjBoundsSparse()
{	InitObjBound** initObjBounds;
	if (this->optimization != NULL) 
	{	if (this->optimization->objectives != NULL) 
		{	if (this->optimization->objectives->initialObjectiveBounds != NULL) 
				initObjBounds = this->optimization->objectives->initialObjectiveBounds->obj;			else
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
double* OSOption::getInitObjLowerBoundsDense(int numberOfObjectives){
	double *initObjBound;
	initObjBound = new double[numberOfObjectives];
	for (int k = 0; k < numberOfObjectives; k++) initObjBound[k] = OSNAN;
	try
	{	if (this->optimization != NULL) 
		{	if (this->optimization->objectives != NULL) 
			{	if (this->optimization->objectives->initialObjectiveBounds != NULL) 
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

/**
 * get the list of initial objective upper bounds in dense form
 * @return an array of values
 * @note return OSNAN for objectives that are not initialed
 */
double* OSOption::getInitObjUpperBoundsDense(int numberOfObjectives){
	double *initObjBound;
	initObjBound = new double[numberOfObjectives];
	for (int k = 0; k < numberOfObjectives; k++) initObjBound[k] = OSNAN;
	try
	{	if (this->optimization != NULL) 
		{	if (this->optimization->objectives != NULL) 
			{	if (this->optimization->objectives->initialObjectiveBounds != NULL) 
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
double* OSOption::getInitConValuesDense(int numberOfConstraints){
	double *initConVector;
	initConVector = new double[numberOfConstraints];
	for (int k = 0; k < numberOfConstraints; k++) initConVector[k] = OSNAN;
	try
	{	if (this->optimization != NULL) 
		{	if (this->optimization->constraints != NULL) 
			{	if (this->optimization->constraints->initialConstraintValues != NULL) 
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


/**
 * get the list of initial dual variable bounds in sparse form
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
 * get the list of initial dual variable lower bounds in dense form
 * @return an array of values
 * @note return OSNAN for dual variables that are not initialed
 */
double* OSOption::getInitDualVarLowerBoundsDense(int numberOfConstraints){
	double *initDualVector;
	initDualVector = new double[numberOfConstraints];
	for (int k = 0; k < numberOfConstraints; k++) initDualVector[k] = OSNAN;
	try
	{	if (this->optimization != NULL) 
		{	if (this->optimization->constraints != NULL) 
			{	if (this->optimization->constraints->initialDualValues != NULL) 
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

/**
 * get the list of initial dual variable lower bounds in dense form
 * @return an array of values
 * @note return OSNAN for dual variables that are not initialed
 */
double* OSOption::getInitDualVarUpperBoundsDense(int numberOfConstraints){
	double *initDualVector;
	initDualVector = new double[numberOfConstraints];
	for (int k = 0; k < numberOfConstraints; k++) initDualVector[k] = OSNAN;
	try
	{	if (this->optimization != NULL) 
		{	if (this->optimization->constraints != NULL) 
			{	if (this->optimization->constraints->initialDualValues != NULL) 
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




/**
 * get the array of solver options associated with a particular solver
 * @param solver_name is the name of the solver
 * @return an array of solver options associated with this solver
 */
std::vector<SolverOption*>  OSOption::getSolverOptions( std::string solver_name){
	std::vector<SolverOption*> optionsVector;
	if (this->optimization != NULL) {
		if (this->optimization->solverOptions != NULL) {
			int i;
			int num_options;
			num_options = this->getNumberOfSolverOptions();
			for(i = 0; i < num_options; i++){
				if (solver_name == this->optimization->solverOptions->solverOption[ i]->solver){
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

/** setOtherOptions()
 *  this function is used for <other> element in <general>, <system>, <service> and <job>
 */
bool OtherOptions::setOtherOptions(int numberOfOptions, OtherOption** other)
{	try
	{	if (this->other != NULL)
			throw 99;

		this->numberOfOtherOptions = numberOfOptions;
		this->other = new OtherOption*[numberOfOptions];
	
		for (int i = 0; i < numberOfOptions; i++){
			this->other[i] = new OtherOption();
			*this->other[i] = *other[i];
		}
		return true;
	}
	catch (int i){
		cout << "otherOptions array previously used." << endl;
		return false;
	}
}//setOtherOptions

/** setAnOtherOption()
 *  used to add an <other> element in <general>, <system>, <service> and <job>
 */
bool OtherOptions::setAnOtherOption(std::string name, std::string value, std::string description){	
	try
	{
		int nopt;
		if (this->other == NULL) 
			nopt = 0;
		else
			nopt = this->numberOfOtherOptions;
	
		OtherOption** temp = new OtherOption*[nopt+1];  //Allocate the new pointers
		for (int i = 0; i < nopt; i++)
			temp[i] = this->other[i];  //copy the pointers

		delete[] this->other; //delete old pointers
	
//	add in the new element
		temp[ nopt] = new OtherOption();
//		if (name == "" || name == NULL)
		if (name.empty() )
			throw 98;

		temp[ nopt]->name = name;
		temp[ nopt]->value = value;
		temp[ nopt]->description = description;

		this->other = temp;   //hook the new pointers into the data structure
		this->numberOfOtherOptions = ++nopt;

		return true;
	}

	catch (int i)
	{	cout << "the name of an option cannot be empty." << endl;
		return false;
	}
}//setAnOtherOption

	
	
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

bool OSOption::setOtherGeneralOptions(int numberOfOptions, OtherOption** other){
	if (this->general == NULL) 
		this->general = new GeneralOption();
	if (this->general->otherOptions == NULL) 
		this->general->otherOptions = new OtherOptions();
	else
	{	for (int i = 0; i < this->general->otherOptions->numberOfOtherOptions; i++)
			delete this->general->otherOptions->other[i];
		delete[] this->general->otherOptions->other;
		this->general->otherOptions->other = NULL;
	}
	return this->general->otherOptions->setOtherOptions(numberOfOptions, other);
}//setOtherGeneralOptions


bool OSOption::setAnOtherGeneralOption(std::string name, std::string value, std::string description){
	if (this->general == NULL) 
		this->general = new GeneralOption();
	if (this->general->otherOptions == NULL) 
		this->general->otherOptions = new OtherOptions();
	return this->general->otherOptions->setAnOtherOption(name, value, description);
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
	else
		delete this->system->otherOptions->other;
	this->system->otherOptions->numberOfOtherOptions = numberOfOptions;
	this->system->otherOptions->other = other;
	return true;
}//setOtherSystemOptions

bool OSOption::setAnOtherSystemOption(OtherOption* optionValue)
{	if (this->system == NULL) 
		this->system = new SystemOption();
	if (this->system->otherOptions == NULL) 
		this->system->otherOptions = new OtherOptions();
	int nopt;
	if (this->system->otherOptions->other == NULL) 
		nopt = 0;
	else
		nopt = this->system->otherOptions->numberOfOtherOptions;

	OtherOption** temp = new OtherOption*[nopt+1];
	for (int i = 0; i < nopt; i++)
		temp[i] = this->system->otherOptions->other[i];
		
	delete[] this->system->otherOptions->other; //delete old pointers

//	add in the new element
	temp[ nopt] = new OtherOption();
	temp[ nopt] = optionValue;

	this->system->otherOptions->other = temp;
	this->system->otherOptions->numberOfOtherOptions = ++nopt;

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
	else
		delete this->service->otherOptions->other;
	this->service->otherOptions->numberOfOtherOptions = numberOfOptions;
	this->service->otherOptions->other = other;
	return true;
}//setOtherServiceOptions

bool OSOption::setAnOtherServiceOption(OtherOption* optionValue)
{	if (this->service == NULL) 
		this->service = new ServiceOption();
	if (this->service->otherOptions == NULL) 
		this->service->otherOptions = new OtherOptions();
	int nopt;
	if (this->service->otherOptions->other == NULL) 
		nopt = 0;
	else
		nopt = this->service->otherOptions->numberOfOtherOptions;

	OtherOption** temp = new OtherOption*[nopt+1];
	for (int i = 0; i < nopt; i++)
		temp[i] = this->service->otherOptions->other[i];

	delete[] this->service->otherOptions->other;

	temp[ nopt] = new OtherOption();
	temp[ nopt] = optionValue;

	this->service->otherOptions->other = temp;
	this->service->otherOptions->numberOfOtherOptions = ++nopt;

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


bool OSOption::setNumberOfJobDependencies(int numberOfObjects)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->dependencies == NULL) 
		this->job->dependencies = new JobDependencies();
	this->job->dependencies->numberOfJobIDs = numberOfObjects;
	return true;
}//setNumberOfJobDependencies

bool OSOption::setJobDependencies(int numberOfDependencies, std::string* jobDependencies)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->dependencies == NULL) 
		this->job->dependencies = new JobDependencies();
	else 
		delete[] this->job->dependencies->jobID;
	this->job->dependencies->numberOfJobIDs = numberOfDependencies;
	this->job->dependencies->jobID = jobDependencies;
	return true;
}//setJobDependencies

bool OSOption::setAnotherJobDependency(std::string jobID){
	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->dependencies == NULL) 
		this->job->dependencies = new JobDependencies();

	int nopt;
	if (this->job->dependencies->jobID == NULL) 
		nopt = 0;
	else
		nopt = this->job->dependencies->numberOfJobIDs;
	std::string* temp = new std::string[nopt+1];
	for (int i = 0; i < nopt; i++){
		temp[i] = this->job->dependencies->jobID[i]; // create the new
	}
	delete[] this->job->dependencies->jobID;
	temp[nopt] = jobID ;
	// fill everything back in
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

bool OSOption::setRequiredDirectories(int numberOfPaths, std::string* paths)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->requiredDirectories == NULL) 
		this->job->requiredDirectories = new DirectoriesAndFiles();
	else
		delete[] this->job->requiredDirectories->path;
	this->job->requiredDirectories->numberOfPaths = numberOfPaths;
	this->job->requiredDirectories->path = paths;
	return true;
}//setRequiredDirectories

bool OSOption::setAnotherRequiredDirectory(std::string path)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->requiredDirectories == NULL) 
		this->job->requiredDirectories = new DirectoriesAndFiles();

	int nopt;
	if (this->job->requiredDirectories->path == NULL) 
		nopt = 0;
	else
		nopt = this->job->requiredDirectories->numberOfPaths;

	std::string* temp = new std::string[nopt+1];
	for (int i = 0; i < nopt; i++)
		temp[i] = this->job->requiredDirectories->path[i];
	
	delete[] this->job->requiredDirectories->path;

	temp[nopt] = path;
	this->job->requiredDirectories->path = temp;
	this->job->requiredDirectories->numberOfPaths = ++nopt;

	return true;
}//setAnotherRequiredDirectory

bool OSOption::setNumberOfRequiredFiles(int numberOfObjects)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->requiredFiles == NULL) 
		this->job->requiredFiles = new DirectoriesAndFiles();
	this->job->requiredFiles->numberOfPaths = numberOfObjects;
	return true;
}//setNumberOfRequiredFiles

bool OSOption::setRequiredFiles(int numberOfPaths, std::string* paths)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->requiredFiles == NULL) 
		this->job->requiredFiles = new DirectoriesAndFiles();
	else
		delete[] this->job->requiredFiles->path;
	this->job->requiredFiles->numberOfPaths = numberOfPaths;
	this->job->requiredFiles->path = paths;
	return true;
}//setRequiredFiles

bool OSOption::setAnotherRequiredFile(std::string path)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->requiredFiles == NULL) 
		this->job->requiredFiles = new DirectoriesAndFiles();

	int nopt;
	if (this->job->requiredFiles->path == NULL) 
		nopt = 0;
	else
		nopt = this->job->requiredFiles->numberOfPaths;

	std::string* temp = new std::string[nopt+1];
	for (int i = 0; i < nopt; i++)
		temp[i] = this->job->requiredFiles->path[i];
	
	delete[] this->job->requiredFiles->path;

	temp[nopt] = path;
	this->job->requiredFiles->path = temp;
	this->job->requiredFiles->numberOfPaths = ++nopt;

	return true;
}//setAnotherRequiredFile

bool OSOption::setNumberOfDirectoriesToMake(int numberOfObjects)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->directoriesToMake == NULL) 
		this->job->directoriesToMake = new DirectoriesAndFiles();
	this->job->directoriesToMake->numberOfPaths = numberOfObjects;
	return true;
}//setNumberOfDirectoriesToMake

bool OSOption::setDirectoriesToMake(int numberOfPaths, std::string* paths)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->directoriesToMake == NULL) 
		this->job->directoriesToMake = new DirectoriesAndFiles();
	else
		delete[] this->job->directoriesToMake->path;
	this->job->directoriesToMake->numberOfPaths = numberOfPaths;
	this->job->directoriesToMake->path = paths;
	return true;
}//setDirectoriesToMake

bool OSOption::setAnotherDirectoryToMake(std::string path)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->directoriesToMake == NULL) 
		this->job->directoriesToMake = new DirectoriesAndFiles();

	int nopt;
	if (this->job->directoriesToMake->path == NULL) 
		nopt = 0;
	else
		nopt = this->job->directoriesToMake->numberOfPaths;

	std::string* temp = new std::string[nopt+1];
	for (int i = 0; i < nopt; i++)
		temp[i] = this->job->directoriesToMake->path[i];
	
	delete[] this->job->directoriesToMake->path;

	temp[nopt] = path;
	this->job->directoriesToMake->path = temp;
	this->job->directoriesToMake->numberOfPaths = ++nopt;

	return true;
}//setAnotherDirectoryToMake

bool OSOption::setNumberOfFilesToMake(int numberOfObjects)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->filesToMake == NULL) 
		this->job->filesToMake = new DirectoriesAndFiles();
	this->job->filesToMake->numberOfPaths = numberOfObjects;
	return true;
}//setNumberOfFilesToMake

bool OSOption::setFilesToMake(int numberOfPaths, std::string* paths)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->filesToMake == NULL) 
		this->job->filesToMake = new DirectoriesAndFiles();
	else
		delete[] this->job->filesToMake->path;
	this->job->filesToMake->numberOfPaths = numberOfPaths;
	this->job->filesToMake->path = paths;
	return true;
}//setFilesToMake

bool OSOption::setAnotherFileToMake(std::string path)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->filesToMake == NULL) 
		this->job->filesToMake = new DirectoriesAndFiles();

	int nopt;
	if (this->job->filesToMake->path == NULL) 
		nopt = 0;
	else
		nopt = this->job->filesToMake->numberOfPaths;

	std::string* temp = new std::string[nopt+1];
	for (int i = 0; i < nopt; i++)
		temp[i] = this->job->filesToMake->path[i];
	
	delete[] this->job->filesToMake->path;

	temp[nopt] = path;
	this->job->filesToMake->path = temp;
	this->job->filesToMake->numberOfPaths = ++nopt;

	return true;
}//setAnotherFileToMake

bool OSOption::setNumberOfInputDirectoriesToMove(int numberOfObjects)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->inputDirectoriesToMove == NULL) 
		this->job->inputDirectoriesToMove = new PathPairs();
	this->job->inputDirectoriesToMove->numberOfPathPairs = numberOfObjects;
	return true;
}//setNumberOfInputDirectoriesToMove

bool OSOption::setInputDirectoriesToMove(int numberOfPathPairs, PathPair** pathPair)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->inputDirectoriesToMove == NULL) 
		this->job->inputDirectoriesToMove = new PathPairs();
	else
		delete[] this->job->inputDirectoriesToMove->pathPair;
	this->job->inputDirectoriesToMove->numberOfPathPairs = numberOfPathPairs;
	this->job->inputDirectoriesToMove->pathPair = pathPair;
	return true;
}//setInputDirectoriesToMove

bool OSOption::setAnotherInputDirectoryToMove(std::string fromPath, std::string toPath, bool makeCopy)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->inputDirectoriesToMove == NULL) 
		this->job->inputDirectoriesToMove = new PathPairs();

	int nopt;
	if (this->job->inputDirectoriesToMove->pathPair == NULL) 
		nopt = 0;
	else
		nopt = this->job->inputDirectoriesToMove->numberOfPathPairs;

	PathPair** temp = new PathPair*[nopt+1];
	for (int i = 0; i < nopt; i++)
		temp[i] = this->job->inputDirectoriesToMove->pathPair[i];
	
	delete[] this->job->inputDirectoriesToMove->pathPair;

	temp[nopt] = new PathPair();
	temp[nopt]->from = fromPath;
	temp[nopt]->to = toPath;
	temp[nopt]->makeCopy = makeCopy;

	this->job->inputDirectoriesToMove->pathPair = temp;
	this->job->inputDirectoriesToMove->numberOfPathPairs = ++nopt;

	return true;
}//setAnotherInputDirectoryToMove



bool OSOption::setNumberOfInputFilesToMove(int numberOfObjects)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->inputFilesToMove == NULL) 
		this->job->inputFilesToMove = new PathPairs();
	this->job->inputFilesToMove->numberOfPathPairs = numberOfObjects;
	return true;
}//setNumberOfInputFilesToMove

bool OSOption::setInputFilesToMove(int numberOfPathPairs, PathPair** pathPair)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->inputFilesToMove == NULL) 
		this->job->inputFilesToMove = new PathPairs();
	else
		delete[] this->job->inputFilesToMove->pathPair;
	this->job->inputFilesToMove->numberOfPathPairs = numberOfPathPairs;
	this->job->inputFilesToMove->pathPair = pathPair;
	return true;
}//setInputFilesToMove

bool OSOption::setAnotherInputFileToMove(std::string fromPath, std::string toPath, bool makeCopy)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->inputFilesToMove == NULL) 
		this->job->inputFilesToMove = new PathPairs();

	int nopt;
	if (this->job->inputFilesToMove->pathPair == NULL) 
		nopt = 0;
	else
		nopt = this->job->inputFilesToMove->numberOfPathPairs;

	PathPair** temp = new PathPair*[nopt+1];
	for (int i = 0; i < nopt; i++)
		temp[i] = this->job->inputFilesToMove->pathPair[i];
	
	delete[] this->job->inputFilesToMove->pathPair;

	temp[nopt] = new PathPair();
	temp[nopt]->from = fromPath;
	temp[nopt]->to = toPath;
	temp[nopt]->makeCopy = makeCopy;

	this->job->inputFilesToMove->pathPair = temp;
	this->job->inputFilesToMove->numberOfPathPairs = ++nopt;

	return true;
}//setAnotherInputFileToMove


bool OSOption::setNumberOfOutputFilesToMove(int numberOfObjects)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->outputFilesToMove == NULL) 
		this->job->outputFilesToMove = new PathPairs();
	this->job->outputFilesToMove->numberOfPathPairs = numberOfObjects;
	return true;
}//setNumberOfOutputFilesToMove

bool OSOption::setOutputFilesToMove(int numberOfPathPairs, PathPair** pathPair)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->outputFilesToMove == NULL) 
		this->job->outputFilesToMove = new PathPairs();
	else
		delete[] this->job->outputFilesToMove->pathPair;
	this->job->outputFilesToMove->numberOfPathPairs = numberOfPathPairs;
	this->job->outputFilesToMove->pathPair = pathPair;
	return true;
}//setOutputFilesToMove

bool OSOption::setAnotherOutputFileToMove(std::string fromPath, std::string toPath, bool makeCopy)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->outputFilesToMove == NULL) 
		this->job->outputFilesToMove = new PathPairs();

	int nopt;
	if (this->job->outputFilesToMove->pathPair == NULL) 
		nopt = 0;
	else
		nopt = this->job->outputFilesToMove->numberOfPathPairs;

	PathPair** temp = new PathPair*[nopt+1];
	for (int i = 0; i < nopt; i++)
		temp[i] = this->job->outputFilesToMove->pathPair[i];
	
	delete[] this->job->outputFilesToMove->pathPair;

	temp[nopt] = new PathPair();
	temp[nopt]->from = fromPath;
	temp[nopt]->to = toPath;
	temp[nopt]->makeCopy = makeCopy;

	this->job->outputFilesToMove->pathPair = temp;
	this->job->outputFilesToMove->numberOfPathPairs = ++nopt;

	return true;
}//setAnotherOutputFileToMove


bool OSOption::setNumberOfOutputDirectoriesToMove(int numberOfObjects)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->outputDirectoriesToMove == NULL) 
		this->job->outputDirectoriesToMove = new PathPairs();
	this->job->outputDirectoriesToMove->numberOfPathPairs = numberOfObjects;
	return true;
}//setNumberOfOutputDirectoriesToMove

bool OSOption::setOutputDirectoriesToMove(int numberOfPathPairs, PathPair** pathPair)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->outputDirectoriesToMove == NULL) 
		this->job->outputDirectoriesToMove = new PathPairs();
	else
		delete[] this->job->outputDirectoriesToMove->pathPair;
	this->job->outputDirectoriesToMove->numberOfPathPairs = numberOfPathPairs;
	this->job->outputDirectoriesToMove->pathPair = pathPair;
	return true;
}//setOutputDirectoriesToMove

bool OSOption::setAnotherOutputDirectoryToMove(std::string fromPath, std::string toPath, bool makeCopy)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->outputDirectoriesToMove == NULL) 
		this->job->outputDirectoriesToMove = new PathPairs();

	int nopt;
	if (this->job->outputDirectoriesToMove->pathPair == NULL) 
		nopt = 0;
	else
		nopt = this->job->outputDirectoriesToMove->numberOfPathPairs;

	PathPair** temp = new PathPair*[nopt+1];
	for (int i = 0; i < nopt; i++)
		temp[i] = this->job->outputDirectoriesToMove->pathPair[i];
	
	delete[] this->job->outputDirectoriesToMove->pathPair;

	temp[nopt] = new PathPair();
	temp[nopt]->from = fromPath;
	temp[nopt]->to = toPath;
	temp[nopt]->makeCopy = makeCopy;

	this->job->outputDirectoriesToMove->pathPair = temp;
	this->job->outputDirectoriesToMove->numberOfPathPairs = ++nopt;

	return true;
}//setAnotherOutputDirectoryToMove


bool OSOption::setNumberOfFilesToDelete(int numberOfObjects)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->filesToDelete == NULL) 
		this->job->filesToDelete = new DirectoriesAndFiles();
	this->job->filesToDelete->numberOfPaths = numberOfObjects;
	return true;
}//setNumberOfFilesToDelete

bool OSOption::setFilesToDelete(int numberOfPaths, std::string* paths)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->filesToDelete == NULL) 
		this->job->filesToDelete = new DirectoriesAndFiles();
	else
		delete[] this->job->filesToDelete->path;
	this->job->filesToDelete->numberOfPaths = numberOfPaths;
	this->job->filesToDelete->path = paths;
	return true;
}//setFilesToDelete

bool OSOption::setAnotherFileToDelete(std::string path)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->filesToDelete == NULL) 
		this->job->filesToDelete = new DirectoriesAndFiles();

	int nopt;
	if (this->job->filesToDelete->path == NULL) 
		nopt = 0;
	else
		nopt = this->job->filesToDelete->numberOfPaths;

	std::string* temp = new std::string[nopt+1];
	for (int i = 0; i < nopt; i++)
		temp[i] = this->job->filesToDelete->path[i];
	
	delete[] this->job->filesToDelete->path;

	temp[nopt] = path;
	this->job->filesToDelete->path = temp;
	this->job->filesToDelete->numberOfPaths = ++nopt;

	return true;
}//setAnotherFileToDelete

bool OSOption::setNumberOfDirectoriesToDelete(int numberOfObjects)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->directoriesToDelete == NULL) 
		this->job->directoriesToDelete = new DirectoriesAndFiles();
	this->job->directoriesToDelete->numberOfPaths = numberOfObjects;
	return true;
}//setNumberOfDirectoriesToDelete

bool OSOption::setDirectoriesToDelete(int numberOfPaths, std::string* paths)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->directoriesToDelete == NULL) 
		this->job->directoriesToDelete = new DirectoriesAndFiles();
	else
		delete[] this->job->directoriesToDelete->path;
	this->job->directoriesToDelete->numberOfPaths = numberOfPaths;
	this->job->directoriesToDelete->path = paths;
	return true;
}//setDirectoriesToMake

bool OSOption::setAnotherDirectoryToDelete(std::string path)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->directoriesToDelete == NULL) 
		this->job->directoriesToDelete = new DirectoriesAndFiles();

	int nopt;
	if (this->job->directoriesToDelete->path == NULL) 
		nopt = 0;
	else
		nopt = this->job->directoriesToDelete->numberOfPaths;

	std::string* temp = new std::string[nopt+1];
	for (int i = 0; i < nopt; i++)
		temp[i] = this->job->directoriesToDelete->path[i];
	
	delete[] this->job->directoriesToDelete->path;

	temp[nopt] = path;
	this->job->directoriesToDelete->path = temp;
	this->job->directoriesToDelete->numberOfPaths = ++nopt;

	return true;
}//setAnotherDirectoryToDelete

bool OSOption::setNumberOfProcessesToKill(int numberOfObjects)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->processesToKill == NULL) 
		this->job->processesToKill = new Processes();
	this->job->processesToKill->numberOfProcesses = numberOfObjects;
	return true;
}//setNumberOfProcessesToKill

bool OSOption::setProcessesToKill(int numberOfProcesses, std::string* processes)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->processesToKill == NULL) 
		this->job->processesToKill = new Processes();
	else
		delete[] this->job->processesToKill->process;
	this->job->processesToKill->numberOfProcesses = numberOfProcesses;
	this->job->processesToKill->process = processes;
	return true;
}//setProcessesToKill

bool OSOption::setAnotherProcessToKill(std::string process)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->processesToKill == NULL) 
		this->job->processesToKill = new Processes();

	int nopt;
	if (this->job->processesToKill->process == NULL) 
		nopt = 0;
	else
		nopt = this->job->processesToKill->numberOfProcesses;

	std::string* temp = new std::string[nopt+1];
	for (int i = 0; i < nopt; i++)
		temp[i] = this->job->processesToKill->process[i];
	
	delete[] this->job->processesToKill->process;

	temp[nopt] = process;
	this->job->processesToKill->process = temp;
	this->job->processesToKill->numberOfProcesses = ++nopt;

	return true;
}//setAnotherProcessToKill

bool OSOption::setNumberOfOtherJobOptions(int numberOfObjects)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->otherOptions == NULL) 
		this->job->otherOptions = new OtherOptions();
	this->job->otherOptions->numberOfOtherOptions = numberOfObjects;
	return true;
}//setNumberOfOtherJobOptions

bool OSOption::setOtherJobOptions(int numberOfOptions, OtherOption** other)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->otherOptions == NULL) 
		this->job->otherOptions = new OtherOptions();
	else
		delete this->job->otherOptions->other;
	this->job->otherOptions->numberOfOtherOptions = numberOfOptions;
	this->job->otherOptions->other = other;
	return true;
}//setOtherJobOptions

bool OSOption::setAnOtherJobOption(OtherOption* optionValue)
{	if (this->job == NULL) 
		this->job = new JobOption();
	if (this->job->otherOptions == NULL) 
		this->job->otherOptions = new OtherOptions();
	int nopt;
	if (this->job->otherOptions->other == NULL) 
		nopt = 0;
	else
		nopt = this->job->otherOptions->numberOfOtherOptions;

	OtherOption** temp = new OtherOption*[nopt+1];
	for (int i = 0; i < nopt; i++)
		temp[i] = this->job->otherOptions->other[i];

	delete[] this->job->otherOptions->other;

	temp[ nopt] = new OtherOption();
	temp[ nopt] = optionValue;

	this->job->otherOptions->other = temp;
	this->job->otherOptions->numberOfOtherOptions = ++nopt;

	return true;
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

bool OSOption::setInitVarValuesSparse(int numberOfVar, InitVarValue** var)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL) 
		this->optimization->variables = new VariableOption();
	if (this->optimization->variables->initialVariableValues == NULL) 
		this->optimization->variables->initialVariableValues = new InitVariableValues();
	else
		delete[] this->optimization->variables->initialVariableValues->var;
	this->optimization->variables->initialVariableValues->numberOfVar = numberOfVar;
	this->optimization->variables->initialVariableValues->var = var;
		return true;
}//setInitVarValuesSparse

bool OSOption::setInitVarValuesDense(int numberOfVar, int *idx, double *value)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL) 
		this->optimization->variables = new VariableOption();
	if (this->optimization->variables->initialVariableValues == NULL) 
		this->optimization->variables->initialVariableValues = new InitVariableValues();
	else
	{	delete[] this->optimization->variables->initialVariableValues->var;
		delete   this->optimization->variables->initialVariableValues->var;
	}
		this->optimization->variables->initialVariableValues->var = new InitVarValue*[numberOfVar];
	for (int i = 0; i < numberOfVar; i++)
	{	this->optimization->variables->initialVariableValues->var[i] = new InitVarValue();
		this->optimization->variables->initialVariableValues->var[i]->idx = idx[i];
		this->optimization->variables->initialVariableValues->var[i]->value = value[i];
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
	int nvar;
	if (this->optimization->variables->initialVariableValues->var == NULL) 
		nvar = 0;
	else
		nvar = this->optimization->variables->initialVariableValues->numberOfVar;

	InitVarValue** temp = new InitVarValue*[nvar+1];
	for (int i = 0; i < nvar; i++)
		temp[i] = this->optimization->variables->initialVariableValues->var[i];
	
	delete[] this->optimization->variables->initialVariableValues->var;
	
	temp[nvar] = new InitVarValue();
	temp[nvar]->idx = idx;
	temp[nvar]->value = value;

	this->optimization->variables->initialVariableValues->var = temp;
	this->optimization->variables->initialVariableValues->numberOfVar = ++nvar;

	return true;
}//setAnotherInitVarValue


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


bool OSOption::setInitVarValuesStringDense(int numberOfVar, int *idx, std::string *value)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL) 
		this->optimization->variables = new VariableOption();
	if (this->optimization->variables->initialVariableValuesString == NULL) 
		this->optimization->variables->initialVariableValuesString = new InitVariableValuesString();
	else
		if (numberOfVar != this->optimization->variables->initialVariableValuesString->numberOfVar)
			throw ErrorClass("Inconsistent size of <initialVariableValuesString> element");
	if (this->optimization->variables->initialVariableValuesString->var == NULL) 
	{	this->optimization->variables->initialVariableValuesString->var = new InitVarValueString*[numberOfVar];
		for (int i = 0; i < numberOfVar; i++)
			this->optimization->variables->initialVariableValuesString->var[i] = new InitVarValueString();
		
	}
	for (int i = 0; i < numberOfVar; i++)
	{	this->optimization->variables->initialVariableValuesString->var[i]->idx = idx[i];
		this->optimization->variables->initialVariableValuesString->var[i]->value = value[i];
	}

		return true;
}//setInitVarValuesStringDense

bool OSOption::setInitVarValuesStringSparse(int numberOfVar, InitVarValueString** var)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL) 
		this->optimization->variables = new VariableOption();
	if (this->optimization->variables->initialVariableValuesString == NULL) 
		this->optimization->variables->initialVariableValuesString = new InitVariableValuesString();
	else
		if (numberOfVar != this->optimization->variables->initialVariableValuesString->numberOfVar)
			throw ErrorClass("Inconsistent size of <initialVariableValuesString> element");
	if (this->optimization->variables->initialVariableValuesString->var == NULL) 
	{	this->optimization->variables->initialVariableValuesString->var = new InitVarValueString*[numberOfVar];
		for (int i = 0; i < numberOfVar; i++)
			this->optimization->variables->initialVariableValuesString->var[i] = new InitVarValueString();
	}
	for (int i = 0; i < numberOfVar; i++)
		this->optimization->variables->initialVariableValuesString->var[i] = var[i];

		return true;
}//setInitVarValuesStringSparse

bool OSOption::setAnotherInitVarValueString(int idx, std::string value)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL) 
		this->optimization->variables = new VariableOption();
	if (this->optimization->variables->initialVariableValuesString == NULL) 
		this->optimization->variables->initialVariableValuesString = new InitVariableValuesString();
	int nvar;
	if (this->optimization->variables->initialVariableValuesString->var == NULL) 
		nvar = 0;
	else
		nvar = this->optimization->variables->initialVariableValuesString->numberOfVar;

	InitVarValueString** temp = new InitVarValueString*[nvar+1];
	for (int i = 0; i < nvar; i++)
		temp[i] = this->optimization->variables->initialVariableValuesString->var[i];

	delete[] this->optimization->variables->initialVariableValuesString->var;
	
	temp[nvar] = new InitVarValueString();
	temp[nvar]->idx = idx;
	temp[nvar]->value = value;

	this->optimization->variables->initialVariableValuesString->var = temp;
	this->optimization->variables->initialVariableValuesString->numberOfVar = ++nvar;

	return true;
}//setAnotherInitVarValueString



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

bool OSOption::setInitBasisStatusDense(int numberOfVar, int *idx, std::string *value)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL) 
		this->optimization->variables = new VariableOption();
	if (this->optimization->variables->initialBasisStatus == NULL) 
		this->optimization->variables->initialBasisStatus = new InitialBasisStatus();
	else
		if (numberOfVar != this->optimization->variables->initialBasisStatus->numberOfVar)
			throw ErrorClass("Inconsistent size of <initialBasisStatus> element");
	if (this->optimization->variables->initialBasisStatus->var == NULL) 
	{	this->optimization->variables->initialBasisStatus->var = new InitBasStatus*[numberOfVar];
		for (int i = 0; i < numberOfVar; i++)
			this->optimization->variables->initialBasisStatus->var[i] = new InitBasStatus();
		
	}
	for (int i = 0; i < numberOfVar; i++)
	{	this->optimization->variables->initialBasisStatus->var[i]->idx = idx[i];
		this->optimization->variables->initialBasisStatus->var[i]->value = value[i];
	}

		return true;
}//setInitBasisStatusDense

bool OSOption::setInitBasisStatusSparse(int numberOfVar, InitBasStatus** var)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL) 
		this->optimization->variables = new VariableOption();
	if (this->optimization->variables->initialBasisStatus == NULL) 
		this->optimization->variables->initialBasisStatus = new InitialBasisStatus();
	else
		if (numberOfVar != this->optimization->variables->initialBasisStatus->numberOfVar)
			throw ErrorClass("Inconsistent size of <initialBasisStatus> element");
	if (this->optimization->variables->initialBasisStatus->var == NULL) 
	{	this->optimization->variables->initialBasisStatus->var = new InitBasStatus*[numberOfVar];
		for (int i = 0; i < numberOfVar; i++)
			this->optimization->variables->initialBasisStatus->var[i] = new InitBasStatus();
	}
	for (int i = 0; i < numberOfVar; i++)
		this->optimization->variables->initialBasisStatus->var[i] = var[i];

		return true;
}//setInitBasisStatusSparse

bool OSOption::setAnotherInitBasisStatus(int idx, std::string value)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL) 
		this->optimization->variables = new VariableOption();
	if (this->optimization->variables->initialBasisStatus == NULL) 
		this->optimization->variables->initialBasisStatus = new InitialBasisStatus();
	int nvar;
	if (this->optimization->variables->initialBasisStatus->var == NULL) 
		nvar = 0;
	else
		nvar = this->optimization->variables->initialBasisStatus->numberOfVar;

	InitBasStatus** temp = new InitBasStatus*[nvar+1];
	for (int i = 0; i < nvar; i++)
		temp[i] = this->optimization->variables->initialBasisStatus->var[i];

	delete[] this->optimization->variables->initialBasisStatus->var;
	
	temp[nvar] = new InitBasStatus();
	temp[nvar]->idx = idx;
	temp[nvar]->value = value;

	this->optimization->variables->initialBasisStatus->var = temp;
	this->optimization->variables->initialBasisStatus->numberOfVar = ++nvar;

	return true;
}//setAnotherInitBasisStatus


bool OSOption::setNumberOfOtherVariableOptions(int numberOfObjects)
{	if (this->optimization == NULL)
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL)
		this->optimization->variables = new VariableOption();
	this->optimization->variables->numberOfOtherVariableOptions = numberOfObjects;
	return true;
}//setNumberOfOtherVariableOptions

bool OSOption::setOtherVariableOptions(int numberOfOptions, OtherVariableOption** other)
{	if (this->optimization == NULL)
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL)
		this->optimization->variables = new VariableOption();
	else
		if (numberOfOptions != this->optimization->variables->numberOfOtherVariableOptions)
			throw ErrorClass("Inconsistent size of other variable option element");
	if (this->optimization->variables->other == NULL) 
	{	this->optimization->variables->other = new OtherVariableOption*[numberOfOptions];
		for (int i = 0; i < numberOfOptions; i++)
			this->optimization->variables->other[i] = new OtherVariableOption();
	}
	for (int i = 0; i < numberOfOptions; i++)
		this->optimization->variables->other[i] = other[i];

	return true;
}//setOtherVariableOptions

bool OSOption::setAnOtherVariableOption(OtherVariableOption* optionValue)
{	if (this->optimization == NULL)
		this->optimization = new OptimizationOption();
	if (this->optimization->variables == NULL)
		this->optimization->variables = new VariableOption();
	int nopt;
	if (this->optimization->variables->other == NULL) 
		nopt = 0;
	else
		nopt = this->optimization->variables->numberOfOtherVariableOptions;

	OtherVariableOption** temp = new OtherVariableOption*[nopt+1];
	for (int i = 0; i < nopt; i++)
		temp[i] = this->optimization->variables->other[i];

	delete[] this->optimization->variables->other;
	
	temp[nopt] = new OtherVariableOption();
	temp[nopt] = optionValue;

	this->optimization->variables->other = temp;
	this->optimization->variables->numberOfOtherVariableOptions = ++nopt;

	return true;
}//setAnOtherVariableOption



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

//	bool setInitObjValuesSparse(int numberOfObj, InitObjValue** obj);
//	bool setInitObjValuesDense(int numberOfObj, double* obj);
//	bool setAnotherInitObjValue(int idx, double value);

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


//	bool setInitObjBoundsSparse(int numberOfObj, InitObjValue** obj);
//	bool setInitObjBoundsDense(int numberOfObj, double* lb, double* ub);
//	bool setAnotherInitObjBound(int idx, double lbValue, double ubValue);

bool OSOption::setNumberOfOtherObjectiveOptions(int numberOfObjects)
{	if (this->optimization == NULL)
		this->optimization = new OptimizationOption();
	if (this->optimization->objectives == NULL) 
		this->optimization->objectives = new ObjectiveOption();
	this->optimization->objectives->numberOfOtherObjectiveOptions = numberOfObjects;
	return true;
}//setNumberOfOtherObjectiveOptions


//	bool setOtherObjectiveOptions(int numberOfObj, OtherObjOption** obj);
//	bool setAnOtherObjectiveOption(OtherObjOption* objOption);

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


//	bool setInitConValuesSparse(int numberOfCon, InitConValue** con);
//	bool setInitConValuesDense(int numberOfCon, double* con);
//	bool setAnotherInitConValue(int idx, double value);

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


//	bool setInitDualVarValuesSparse(int numberOfCon, InitDualVarValue** con);
//	bool setInitDualVarValuesDense(int numberOfCon, double* lb, double* ub);
//	bool setAnotherInitDualVarValue(int idx, double lbValue, double ubValue);

bool OSOption::setNumberOfOtherConstraintOptions(int numberOfObjects)
{	if (this->optimization == NULL)
		this->optimization = new OptimizationOption();
	if (this->optimization->constraints == NULL) 
		this->optimization->constraints = new ConstraintOption();
	this->optimization->constraints->numberOfOtherConstraintOptions = numberOfObjects;
	return true;
}//setNumberOfOtherConstraintOptions


//	bool setOtherConstraintOptions(int numberOfCon, OtherConOption** con);
//	bool setAnOtherConstraintOption(OtherConOption* conOption);


bool OSOption::setNumberOfSolverOptions(int numberOfObjects)
{	if (this->optimization == NULL) 
		this->optimization = new OptimizationOption();
	if (this->optimization->solverOptions == NULL) 
		this->optimization->solverOptions = new SolverOptions();
	this->optimization->solverOptions->numberOfSolverOptions = numberOfObjects;
	return true;
}//setNumberOfSolverOptions





//	bool setSolverOptions(int numberOfSolverOptions, Solveroption** solverOption);
//	bool setAnotherSolverOption(Solveroption* solverOption);






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


bool OSOption::setOptionInt(std::string optionName, int optionValue)
{	if (optionName == "minCPUNumber")
		return this->setMinCPUNumber(optionValue);

	if (optionName == "numberOfOtherGeneralOptions")
		return this->setNumberOfOtherGeneralOptions(optionValue);

	if (optionName == "numberOfOtherSystemOptions")
		return this->setNumberOfOtherSystemOptions(optionValue);

	if (optionName == "numberOfOtherServiceOptions")
		return this->setNumberOfOtherServiceOptions(optionValue);

	if (optionName == "numberOfOtherJobOptions")
		return this->setNumberOfOtherJobOptions(optionValue);

	if (optionName == "numberOfJobDependencies")
		return this->setNumberOfJobDependencies(optionValue);

	if (optionName == "numberOfRequiredDirectories")
		return this->setNumberOfRequiredDirectories(optionValue);

	if (optionName == "numberOfRequiredFiles")
		return this->setNumberOfRequiredFiles(optionValue);

	if (optionName == "numberOfDirectoriesToMake")
		return this->setNumberOfDirectoriesToMake(optionValue);

	if (optionName == "numberOfFilesToMake")
		return this->setNumberOfFilesToMake(optionValue);

	if (optionName == "numberOfInputDirectoriesToMove")
		return this->setNumberOfInputDirectoriesToMove(optionValue);

	if (optionName == "numberOfInputFilesToMove")
		return this->setNumberOfInputFilesToMove(optionValue);

	if (optionName == "numberOfOutputDirectoriesToMove")
		return this->setNumberOfOutputDirectoriesToMove(optionValue);

	if (optionName == "numberOfOutputFilesToMove")
		return this->setNumberOfOutputFilesToMove(optionValue);

	if (optionName == "numberOfFilesToDelete")
		return this->setNumberOfFilesToDelete(optionValue);

	if (optionName == "numberOfDirectoriesToDelete")
		return this->setNumberOfDirectoriesToDelete(optionValue);

	if (optionName == "numberOfProcessesToKill")
		return this->setNumberOfProcessesToKill(optionValue);

	if (optionName == "numberOfVariables")
		return this->setNumberOfVariables(optionValue);

	if (optionName == "numberOfObjectives")
		return this->setNumberOfObjectives(optionValue);

	if (optionName == "numberOfConstraints")
		return this->setNumberOfConstraints(optionValue);

	if (optionName == "numberOfInitVarValues")
		return this->setNumberOfInitVarValues(optionValue);

	if (optionName == "numberOfInitVarValuesString")
		return this->setNumberOfInitVarValuesString(optionValue);

	if (optionName == "numberOfInitialBasisVariables")
		return this->setNumberOfInitialBasisVariables(optionValue);

	if (optionName == "numberOfOtherVariableOptions")
		return this->setNumberOfOtherVariableOptions(optionValue);

	if (optionName == "numberOfInitObjValues")
		return this->setNumberOfInitObjValues(optionValue);

	if (optionName == "numberOfInitObjBounds")
		return this->setNumberOfInitObjBounds(optionValue);

	if (optionName == "numberOfOtherObjectiveOptions")
		return this->setNumberOfOtherObjectiveOptions(optionValue);

	if (optionName == "numberOfInitConValues")
		return this->setNumberOfInitConValues(optionValue);

	if (optionName == "numberOfInitDualVarValues")
		return this->setNumberOfInitDualVarValues(optionValue);

	if (optionName == "numberOfOtherConstraintOptions")
		return this->setNumberOfOtherConstraintOptions(optionValue);

	if (optionName == "numberOfSolverOptions")
		return this->setNumberOfSolverOptions(optionValue);

	return false;
}//setOptionInt
