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
	locationType (""),
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
	contactType (""),
	value ("")
{    
	#ifdef DEBUG
	cout << "Inside ContactOption Constructor" << endl;
	#endif
}// end ContactOption constructor  template

ContactOption::~ContactOption()
{    
	#ifdef DEBUG
	cout << "ContactOption Destructor Called" << endl;
	#endif
}//end ContactOption destructor


GeneralOption::GeneralOption(): 
	serviceURI (""),
	serviceName (""),
	instanceName (""),
	jobID (""),
	license (""),
	userName (""),
	password ("")
{    
	#ifdef DEBUG
	cout << "Inside GeneralOption Constructor" << endl;
	#endif
	instanceLocation = NULL;
	contact = NULL;
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
}//end GeneralOption destructor 


SystemOption::SystemOption(): 
	minDiskSpace (0.0),
	minMemorySize (0.0),
	minCPUSpeed (0.0)
{    
	#ifdef DEBUG
	cout << "Inside SystemOption Constructor" << endl;
	#endif
}// end SystemOption constructor  

SystemOption::~SystemOption()
{    
	#ifdef DEBUG
	cout << "SystemOption Destructor Called" << endl;
	#endif
}//end SystemOption destructor 


ServiceOption::ServiceOption(): 
	type ("")
{    
	#ifdef DEBUG
	cout << "Inside ServiceOption Constructor" << endl;
	#endif
}// end ServiceOption constructor  

ServiceOption::~ServiceOption()
{    
	#ifdef DEBUG
	cout << "ServiceOption Destructor Called" << endl;
	#endif
}//end ServiceOption destructor 


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
//	{	for (int i=0; , > numberOfPaths; i++)
//		{	delete path[i];
//			path[i] = NULL;
//		}
		delete path;
		path = NULL;
//	}
}//end DirectoriesAndFiles destructor 


Processes::Processes()
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
	maxTime = std::numeric_limits<double>::infinity();
	dependencies = NULL;
	requiredDirectoriesAndFiles = NULL;
	directoriesToMake = NULL;
	filesToCreate = NULL;
	inputFilesToCopyFrom = NULL;
	inputFilesToCopyTo = NULL;
	inputFilesToMoveFrom = NULL;
	inputFilesToMoveTo = NULL;
	outputFilesToCopyFrom = NULL;
	outputFilesToCopyTo = NULL;
	outputFilesToMoveFrom = NULL;
	outputFilesToMoveTo = NULL;
	filesToDelete = NULL;
	directoriesToDelete = NULL;
	processesToKill = NULL;
}// end JobOption constructor  

JobOption::~JobOption()
{    
	#ifdef DEBUG
	cout << "JobOption Destructor Called" << endl;
	#endif
	if (dependencies != NULL) delete dependencies;
	dependencies = NULL;
	if (requiredDirectoriesAndFiles != NULL) delete requiredDirectoriesAndFiles;
	requiredDirectoriesAndFiles = NULL;
	if (directoriesToMake != NULL) delete directoriesToMake;
	directoriesToMake = NULL;
	if (filesToCreate != NULL) delete filesToCreate;
	filesToCreate = NULL;
	if (inputFilesToCopyFrom != NULL) delete inputFilesToCopyFrom;
	inputFilesToCopyFrom = NULL;
	if (inputFilesToCopyTo != NULL) delete inputFilesToCopyTo;
	inputFilesToCopyTo = NULL;
	if (inputFilesToMoveFrom != NULL) delete inputFilesToMoveFrom;
	inputFilesToMoveFrom = NULL;
	if (inputFilesToMoveTo != NULL) delete inputFilesToMoveTo;
	inputFilesToMoveTo = NULL;
	if (outputFilesToCopyFrom != NULL) delete outputFilesToCopyFrom;
	outputFilesToCopyFrom = NULL;
	if (outputFilesToCopyTo != NULL) delete outputFilesToCopyTo;
	outputFilesToCopyTo = NULL;
	if (outputFilesToMoveFrom != NULL) delete outputFilesToMoveFrom;
	outputFilesToMoveFrom = NULL;
	if (outputFilesToMoveTo != NULL) delete outputFilesToMoveTo;
	outputFilesToMoveTo = NULL;
	if (filesToDelete != NULL) delete filesToDelete;
	filesToDelete = NULL;
	if (directoriesToDelete != NULL) delete directoriesToDelete;
	directoriesToDelete = NULL;
	if (processesToKill != NULL) delete processesToKill;
	processesToKill = NULL;
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
//	{	for (int i=0; i < numberOfVar; i++)
//		{	delete var[i];
//			var[i] = NULL;
//		}
		delete var;
		var = NULL;
//	}
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
//	{	for (int i=0; i < numberOfCon; i++)
//		{	delete con[i];
//			con[i] = NULL;
//		}
		delete con;
		con = NULL;
//	};
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


InitDualValues::InitDualValues(): 
	numberOfCon (0)
{    
	#ifdef DEBUG
	cout << "Inside InitDualValues Constructor" << endl;
	#endif
	con = NULL;
}// end InitDualValues constructor  

InitDualValues::~InitDualValues()
{    
	#ifdef DEBUG
	cout << "InitDualValues Destructor Called" << endl;
	#endif
	if (con != NULL) 
//	{	for (int i; i++, i < numberOfCon)
//		{	delete con[i];
//			con[i] = NULL;
//		}
		delete con;
		con = NULL;
//	};
}//end InitDualValues destructor


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
//	{	for (int i; i < numberOfCon; i++)
//		{	delete con[i];
//			con[i] = NULL;
//		}
		delete con;
		con = NULL;
//	};
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


OtherOption::OtherOption(): 
	name (""),
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


OptimizationOption::OptimizationOption(): 
	numberOfVariables (0),
	numberOfObjectives (0),
	numberOfConstraints (0),
	numberOfOtherOptions (0)
{    
	#ifdef DEBUG
	cout << "Inside OptimizationOption Constructor" << endl;
	#endif
	variables = NULL;
	objectives = NULL;
	constraints = NULL;
	other = NULL;
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
	if (other != NULL) 
	{	for (int i=0; i < numberOfOtherOptions; i++)
		{	delete other[i];
			other[i] = NULL;
		}
		delete other;
		other = NULL;
	};
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
	other = NULL;
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
	if (other != NULL) delete other;
	other = NULL;
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



