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
#include<iostream>
#include<sstream>
#include <limits>

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
	cout << "Inside OtherOption Constructor" << endl;
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
		delete other;
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
	value (std::numeric_limits<double>::infinity())
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
//	{	for (int i; i < numberOfJobIDs; i++)
//		{	delete jobID[i];
//			jobID[i] = NULL;
//		}
		delete jobID;
		jobID = NULL;
//	}
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
//	{	for (int i=0; i < numberOfPaths; i++)
//		{	delete path[i];
//			path[i] = NULL;
//		}
		delete path;
		path = NULL;
//	}
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
		delete pathPair;
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
//	{	for (int i=0; i < numberOfProcesses; i++)	
//		{	delete process[i];
//			process[i] = NULL;
//		}
		delete process;
		process = NULL;
//	}
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
	outputDirectoriesToMove = NULL;
	outputFilesToMove = NULL;
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
	idx (0),
	value ("")
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
		delete var;
		var = NULL;
	}
}//end InitVariableValues destructor 


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
		delete var;
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
	other = NULL;
}// end VariableOption constructor  

VariableOption::~VariableOption()
{    
	#ifdef DEBUG
	cout << "VariableOption Destructor Called" << endl;
	#endif
	if (initialVariableValues != NULL) delete initialVariableValues;
	initialVariableValues = NULL;
	if (other != NULL) 
	{   for (int i=0; i < numberOfOtherVariableOptions; i++)
		{	if (other[i] != NULL)
				delete other[i];
				other[i] = NULL;
		};
 		delete other;
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
		delete obj;
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
		delete obj;
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
		delete con;
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
		delete con;
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
		delete solverOption;
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




//
// get methods

//GeneralStatus* OSResult::getGeneralStatus(){
//	return resultHeader->generalStatus;
//}//getGeneralStatus


//string OSResult::getGeneralStatusType(){
//	if(resultHeader->generalStatus == NULL) return "";
//	return resultHeader->generalStatus->type;
//}//getGeneralStatusType


//int OSResult::getVariableNumber(){
//	if(m_iVariableNumber == -1){
//		if(resultData->optimization == NULL) return -1;
//		m_iVariableNumber = resultData->optimization->numberOfVariables;
//	}
//	return m_iVariableNumber;
//}//getVariableNumber





//double* OSResult::getOptimalDualVariableValues(int objIdx){
//	if(resultData->optimization == NULL || resultData->optimization->solution == NULL) return NULL;
//	int iNumberOfConstraints = this->getConstraintNumber();
//	if(iNumberOfConstraints <= 0) return NULL;
//	int iSolutions = this->getSolutionNumber();
//	for(int i = 0; i < iSolutions; i++){
//		if(resultData->optimization->solution[i] == NULL) continue;
//		if(resultData->optimization->solution[i]->objectiveIdx != objIdx) continue;
//		if(resultData->optimization->solution[i]->constraints == NULL) continue;
//		if(resultData->optimization->solution[i]->constraints->dualValues == NULL) continue;
//		if((resultData->optimization->solution[i]->status->type.find("ptimal") != string::npos && m_mdDualValues == NULL) ||
//			resultData->optimization->solution[i]->status->type.compare("globallyOptimal") == 0){						
//			m_mdDualValues = new double[iNumberOfConstraints];
//			for(int j = 0; j < iNumberOfConstraints; j++){
//				m_mdDualValues[ j] = resultData->optimization->solution[i]->constraints->dualValues->con[j]->value;
//			}
//		}	
//		if(resultData->optimization->solution[i]->status->type.compare("globallyOptimal")){
//			return m_mdDualValues;
//		}
//	}
//	return m_mdDualValues;		
//}//getOptimalDualVariableValues

// set methods

//bool OSResult::setGeneralStatus(GeneralStatus *status){
//	resultHeader->generalStatus = status;
//	return true;
//}//setGeneralStatus

//bool OSResult::setGeneralStatusType(string type){
//	if(resultHeader->generalStatus == NULL) resultHeader->generalStatus = new GeneralStatus();
//	resultHeader->generalStatus->type = type;
//	return true;
//}//setGeneralStatusType


//bool OSResult::setSolutionNumber(int number){
//	//if(getVariableNumber() <= 0) return false;
//	//if(getObjectiveNumber() < 0) return false;
//	//if(getConstraintNumber() < 0) return false;
//	if(number < 0) return false; 
//	if(number == 0) return true;
//	if(resultData->optimization == NULL) resultData->optimization = new OptimizationResult();
//	resultData->optimization->numberOfSolutions = number;
//	resultData->optimization->solution = new OptimizationSolution*[number];
//	for(int i = 0; i < number; i++){
//		std::cout << "CREATING A NEW OPTIMIZATION SOLUTION" << std::endl;
//		resultData->optimization->solution[i] = new OptimizationSolution();
//		std::cout << "DONE CREATING A NEW OPTIMIZATION SOLUTION" << std::endl;
//	}
//	return true;
//}//setSolutionNumber



