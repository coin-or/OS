/** @file OSResult.cpp
 * 
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

#include "OSResult.h"
#include "OSParameters.h"
#include "ErrorClass.h"
#include<iostream>
#include<sstream>

using namespace std;

GeneralStatus::GeneralStatus():
	type( ""),
	description( "")
{    
	#ifdef DEBUG
	cout << "Inside GeneralStatus Constructor" << endl;
	#endif
}// end GeneralStatus constructor  

GeneralStatus::~GeneralStatus(){
	#ifdef DEBUG
	cout << "GeneralStatus Destructor Called" << endl;
	#endif
}//end GeneralStatus destructor

OSResult::OSResult():
	m_iVariableNumber( -1),
	m_iObjectiveNumber( -1),
	m_iConstraintNumber( -1),
	m_iNumberOfOtherVariableResult( -1),
	m_mdPrimalValues( NULL),
	m_mdDualValues( NULL)

{    
	#ifdef DEBUG
	cout << "Inside OSResult Constructor" << endl;
	#endif
	this->resultHeader = new ResultHeader();
	this->resultData = new ResultData();
}// end OSResult constructor  

OSResult::~OSResult(){
	#ifdef DEBUG
	cout << "OSResult Destructor Called" << endl;
	#endif
	// delete the two children of OSResult
	// delete resultHeader object
	delete resultHeader;
	resultHeader = NULL;
	//delete resultData object
	delete resultData;
	resultData = NULL;
	delete[] m_mdPrimalValues;
	m_mdPrimalValues = 0;
	delete[] m_mdDualValues;
	m_mdDualValues = 0;
}//end OSResult destructor


ResultHeader::ResultHeader():
	serviceURI(""),
	serviceName(""),
	instanceName(""),
	jobID(""),
	time(""),
	message("")
{ 
	#ifdef DEBUG
	cout << "Inside the ResultHeader Constructor" << endl;
	#endif
	generalStatus = new GeneralStatus();
}//end ResultHeader constructor


ResultHeader::~ResultHeader(){
	#ifdef DEBUG  
	cout << "Inside the ResultHeader Destructor" << endl;
	#endif
	delete generalStatus;
	generalStatus = NULL;
}// end ResultHeader destructor


VarValue::VarValue():
	idx( -1),
	value( 0)
{ 
	#ifdef DEBUG
	cout << "Inside the VarValue Constructor" << endl;
	#endif
}//end VarValue constructor


VarValue::~VarValue(){
	#ifdef DEBUG  
	cout << "Inside the VarValue Destructor" << endl;
	#endif
}// end VarValue destructor 


OtherVarResult::OtherVarResult():
	idx( -1),
	value( "")
{ 
	#ifdef DEBUG
	cout << "Inside the OtherVarResult Constructor" << endl;
	#endif
}//end OtherVarResult constructor


OtherVarResult::~OtherVarResult(){
	#ifdef DEBUG  
	cout << "Inside the OtherVarResult Destructor" << endl;
	#endif
}// end OtherVarResult destructor 


OtherObjResult::OtherObjResult():
	idx( -1),
	value( "")
{ 
	#ifdef DEBUG
	cout << "Inside the OtherObjResult Constructor" << endl;
	#endif
}//end OtherObjResult constructor


OtherObjResult::~OtherObjResult(){
	#ifdef DEBUG  
	cout << "Inside the OtherObjResult Destructor" << endl;
	#endif
}//end OtherObjResult destructor


OtherConResult::OtherConResult():
	idx( -1),
	value( "")
{ 
	#ifdef DEBUG
	cout << "Inside the OtherConResult Constructor" << endl;
	#endif
}//end OtherConResult constructor


OtherConResult::~OtherConResult(){
	#ifdef DEBUG  
	cout << "Inside the OtherConResult Destructor" << endl;
	#endif
}//end OtherConResult destructor


ObjValue::ObjValue():
	idx( -1),
	value( OSNAN)
{ 
	#ifdef DEBUG
	cout << "Inside the ObjValue Constructor" << endl;
	#endif
}//end ObjValue constructor


ConValue::ConValue():
	idx( -1),
	value( 0)
{ 
	#ifdef DEBUG
	cout << "Inside the ConValue Constructor" << endl;
	#endif
}//end ConValue constructor


ConValue::~ConValue(){
	#ifdef DEBUG  
	cout << "Inside the ConValue Destructor" << endl;
	#endif
}// end ConValue destructor 

ObjValue::~ObjValue(){
	#ifdef DEBUG  
	cout << "Inside the ObjValue Destructor" << endl;
	#endif
}// end ObjValue destructor 

DualVarValue::DualVarValue():
	idx( -1),
	lbValue( 0),
	ubValue( 0),
	value( 0)
{ 
	#ifdef DEBUG
	cout << "Inside the DualVarValue Constructor" << endl;
	#endif
}//end DualVarValue constructor


DualVarValue::~DualVarValue(){
	#ifdef DEBUG  
	cout << "Inside the DualVarValue Destructor" << endl;
	#endif
}// end DualVarValue destructor



VariableValues::VariableValues() { 
	#ifdef DEBUG
	cout << "Inside the VariableValues Constructor" << endl;
	#endif

}//end VariableValues constructor


VariableValues::~VariableValues(){
	#ifdef DEBUG  
	cout << "Inside the VariableValues Destructor" << endl;
	#endif
	int n = var.size();
	if(n > 0 ){
		for(int i = 0; i < n; i++){
			delete var[i];
			var[i] = NULL;
		}
	}
	var.clear(); 

}// end VariableValues destructor 


OtherVariableResult::OtherVariableResult():
	name(""),
	description("")
{ 
	#ifdef DEBUG
	cout << "Inside the OtherVariableResult Constructor" << endl;
	#endif

}//end OtherVariableResult constructor


OtherVariableResult::~OtherVariableResult(){
	#ifdef DEBUG  
	cout << "Inside the OtherVariableResult Destructor" << endl;
	#endif
	int n = var.size();
	if(n  > 0) {
		for(int i = 0; i < n; i++){
			delete var[i];
			var[i] = NULL;
		}
	}
	var.clear(); 
}// end OtherVariableResult destructor 


OtherObjectiveResult::OtherObjectiveResult():
	name(""),
	description("")
{ 
	#ifdef DEBUG
	cout << "Inside the OtherObjectiveResult Constructor" << endl;
	#endif
}//end OtherObjectiveResult constructor


OtherObjectiveResult::~OtherObjectiveResult(){
	#ifdef DEBUG  
	cout << "Inside the OtherObjectiveResult Destructor" << endl;
	#endif
	int n = obj.size();
	if(n > 0) {
		for(int i = 0; i < n; i++){
			delete obj[i];
			obj[i] = NULL;
		}
	}
	obj.clear(); 
}// end OtherObjectiveResult destructor


OtherConstraintResult::OtherConstraintResult():
	name(""),
	description("")
{ 
	#ifdef DEBUG
	cout << "Inside the OtherConstraintResult Constructor" << endl;
	#endif
}//end OtherConstraintResult constructor


OtherConstraintResult::~OtherConstraintResult(){
	#ifdef DEBUG  
	cout << "Inside the OtherConstraintResult Destructor" << endl;
	#endif
	int n = con.size();
	if(n > 0){
		for(int i = 0; i < n; i++){
			delete con[i];
			con[i] = NULL;
		}
	}
	con.clear(); 
}// end OtherObjectiveResult destructor


ObjectiveValues::ObjectiveValues() { 
	#ifdef DEBUG
	cout << "Inside the ObjectiveValues Constructor" << endl;
	#endif

}//end ObjectiveValues constructor


ObjectiveValues::~ObjectiveValues(){
	#ifdef DEBUG  
	cout << "Inside the ObjectiveValues Destructor" << endl;
	#endif
	int n = obj.size();
	if(n > 0 ){
		for(int i = 0; i < n; i++){
			delete obj[i];
			obj[i] = NULL;
		}
	}
	obj.clear(); 

}// end ObjectiveValues destructor


ConstraintValues::ConstraintValues(){ 
	#ifdef DEBUG
	cout << "Inside the ConstraintValues Constructor" << endl;
	#endif
}//end ConstraintValues constructor


ConstraintValues::~ConstraintValues(){
	#ifdef DEBUG  
	cout << "Inside the ConstraintValues Destructor" << endl;
	#endif
	int n = con.size();
	if(n > 0){
		for(int i = 0; i < n; i++){
			delete con[i];
			con[i] = NULL;
		}
	}
	con.clear(); 
}// end ConstraintValues destructor 

DualVariableValues::DualVariableValues() { 
	#ifdef DEBUG
	cout << "Inside the DualVariableValues Constructor" << endl;
	#endif

}//end DualVariableValues constructor


DualVariableValues::~DualVariableValues(){
	#ifdef DEBUG  
	cout << "Inside the DualVariableValues Destructor" << endl;
	#endif
	int n = con.size();
	if(n > 0){
		for(int i = 0; i < n; i++){
			delete con[i];
			con[i] = NULL;
		}
	}	
	con.clear(); 
}// end DualVariableValues destructor 



VariableSolution::VariableSolution():
	numberOfOtherVariableResult( 0),
	values( NULL),
	other( NULL)

{ 
	#ifdef DEBUG
	cout << "Inside the VariableSolution Constructor" << endl;
	#endif
}//end VariableSolution constructor


VariableSolution::~VariableSolution(){
	#ifdef DEBUG  
	cout << "Inside the VariableSolution Destructor" << endl;
	#endif
	delete  values;
	values = NULL;
	if(numberOfOtherVariableResult > 0 && other != NULL){
		for(int i = 0; i < numberOfOtherVariableResult; i++){
			delete other[i];
			other[i] = NULL;
		}
	}
	delete[] other;
	other = NULL; 
}// end VariableSolution destructor 

ObjectiveSolution::ObjectiveSolution():
	numberOfOtherObjectiveResult( 0),
	values( NULL),
	other( NULL)

{ 
	#ifdef DEBUG
	cout << "Inside the ObjectiveSolution Constructor" << endl;
	#endif
}//end ObjectiveSolution constructor


ObjectiveSolution::~ObjectiveSolution(){
	#ifdef DEBUG  
	cout << "Inside the ObjectieSolution Destructor" << endl;
	#endif
	delete  values;
	values = NULL;
	if(numberOfOtherObjectiveResult > 0 && other != NULL){
		for(int i = 0; i < numberOfOtherObjectiveResult; i++){
			delete other[i];
			other[i] = NULL;
		}
	}
	delete[] other;
	other = NULL; 
}// end ObjectiveSolution destructor 



ConstraintSolution::ConstraintSolution():
	numberOfOtherConstraintResult( 0),
	values( NULL),
	dualValues( NULL),
	other( NULL)
{ 
	#ifdef DEBUG
	cout << "Inside the ConstraintSolution Constructor" << endl;
	#endif
}//end ConstraintSolution constructor


ConstraintSolution::~ConstraintSolution(){
	#ifdef DEBUG  
	cout << "Inside the ConstraintSolution Destructor" << endl;
	#endif
	delete values;
	values = NULL;
	delete  dualValues;
	dualValues = NULL;
	if(numberOfOtherConstraintResult > 0 && other != NULL){
		for(int i = 0; i < numberOfOtherConstraintResult; i++){
			delete other[i];
			other[i] = NULL;
		}
	}
	delete[] other;
	other = NULL; 
}// end ConstraintSolution destructor



OptimizationSolutionStatus::OptimizationSolutionStatus():
	type(""),
	description("")
	//substatus( NULL),
{ 
	#ifdef DEBUG
	cout << "Inside the OptimizationSolutionStatus Constructor" << endl;
	#endif
}//end OptimizationSolutionStatus constructor


OptimizationSolutionStatus::~OptimizationSolutionStatus(){
	#ifdef DEBUG  
	cout << "Inside the OptimzationSolutionStatus Destructor" << endl;
	#endif
}// end OptimizationSolutionStatus destructor 


OptimizationSolution::OptimizationSolution():
	objectiveIdx( -1),
	message( ""),
	variables( NULL),
	objectives( NULL),
	constraints( NULL)
	//other(NULL)
{ 
	#ifdef DEBUG
	cout << "Inside the OptimizationSolution Constructor" << endl;
	#endif
	status = new OptimizationSolutionStatus();
}//end OptimizationSolution constructor


OptimizationSolution::~OptimizationSolution(){
	#ifdef DEBUG  
	cout << "Inside the OptimzationSolution Destructor" << endl;
	#endif
	delete variables;
	variables = NULL;
	delete constraints;
	constraints = NULL;
	delete objectives;
	objectives = NULL;
	delete status;
	status = NULL;
}// end OptimizationSolution destructor 
 
 
 
OptimizationResult::OptimizationResult():
	numberOfVariables( -1),
	numberOfObjectives( -1),
	numberOfConstraints(-1),
	numberOfSolutions( -1),
	solution(NULL)
{ 
	#ifdef DEBUG
	cout << "Inside the OptimizationResult Constructor" << endl;
	#endif
}//end OptimizationResult constructor


OptimizationResult::~OptimizationResult(){
	#ifdef DEBUG  
	cout << "Inside the OptimzationResult Destructor" << endl;
	cout << "Number of solutions = " << this->numberOfSolutions << endl;
	#endif
	if( solution != NULL){
		for(int i = 0; i < this->numberOfSolutions; i++){
			delete solution[i];
			solution[i] = NULL;
			#ifdef DEBUG  
			cout << "Delelting Solution: " << i << endl;
			#endif
			i++;
		}
	}
	delete[] solution;
	solution = NULL; 
}// end OptimizationResult destructor 
 



ResultData::ResultData():
	optimization(NULL)
{ 
	#ifdef DEBUG
	cout << "Inside the ResultData Constructor" << endl;
	#endif
}//end ResultData constructor


ResultData::~ResultData(){
	#ifdef DEBUG  
	cout << "Inside the ResulData Destructor" << endl;
	#endif
	delete optimization;
	optimization = NULL;
}// end ResultData destructor 


//
// get methods

GeneralStatus* OSResult::getGeneralStatus(){
	return resultHeader->generalStatus;
}//getGeneralStatus


string OSResult::getGeneralStatusType(){
	if(resultHeader->generalStatus == NULL) return "";
	return resultHeader->generalStatus->type;
}//getGeneralStatusType

string OSResult::getGeneralStatusDescription(){
	if(resultHeader->generalStatus == NULL) return NULL;
	return resultHeader->generalStatus->description;
}//getGeneralStatusDescription

string OSResult::getServiceName(){
	return resultHeader->serviceName;
}//getServiceName

string OSResult::getServiceURI(){
	return resultHeader->serviceURI;
}//getServiceURI

string OSResult::getInstanceName(){
	return resultHeader->instanceName;
}//getInstanceName

string OSResult::getJobID(){
	return resultHeader->jobID;
}//getJobID


string OSResult::getGeneralMessage(){
	return resultHeader->message;
}//getGeneralMessage

int OSResult::getVariableNumber(){
	if(m_iVariableNumber == -1){
		if(resultData->optimization == NULL) return -1;
		m_iVariableNumber = resultData->optimization->numberOfVariables;
	}
	return m_iVariableNumber;
}//getVariableNumber



int OSResult::getObjectiveNumber(){
	if(m_iObjectiveNumber == -1){
		if(resultData->optimization == NULL) return -1;
		m_iObjectiveNumber = resultData->optimization->numberOfObjectives;
	}
	return m_iObjectiveNumber;
}//getObjectiveNumber


int OSResult::getConstraintNumber(){
	if(m_iConstraintNumber == -1){
		if(resultData->optimization == NULL) return -1;
		m_iConstraintNumber = resultData->optimization->numberOfConstraints;
	}
	return m_iConstraintNumber;
}//getConstraintNumber

int OSResult::getSolutionNumber(){
	if(resultData->optimization == NULL) return 0;
	if(resultData->optimization->solution == NULL) return 0;
	return resultData->optimization->numberOfSolutions;
}//getSolutionNumber


int OSResult::getNumberOfOtherVariableResult(int solIdx){
	if(m_iNumberOfOtherVariableResult == -1){
		if(resultData->optimization->solution[solIdx]->variables->other == NULL) return -1;
		m_iNumberOfOtherVariableResult = resultData->optimization->solution[solIdx]->variables->numberOfOtherVariableResult;
	}
	return m_iNumberOfOtherVariableResult;
}//getNumberOfOtherVariableResult


OptimizationSolutionStatus* OSResult::getSolutionStatus( int solIdx){
	if(resultData->optimization == NULL || resultData->optimization->solution == NULL) return NULL;
	if( resultData->optimization->numberOfSolutions <= 0 || 
	   solIdx < 0 || solIdx >=  resultData->optimization->numberOfSolutions) return NULL;
	if(resultData->optimization->solution[solIdx] == NULL) return NULL;
	return resultData->optimization->solution[solIdx]->status;
}//getSolutionStatus

string OSResult::getSolutionStatusType(int solIdx){
	if(resultData->optimization == NULL || resultData->optimization->solution == NULL) return NULL;
	if( resultData->optimization->numberOfSolutions <= 0 || 
	   solIdx < 0 || solIdx >=  resultData->optimization->numberOfSolutions) return NULL;
	if(resultData->optimization->solution[solIdx] == NULL) return NULL;
	if(resultData->optimization->solution[solIdx]->status == NULL) return NULL;
	return resultData->optimization->solution[solIdx]->status->type;		
}//getSolutionStatusType

string OSResult::getSolutionStatusDescription(int solIdx){
	if(resultData->optimization == NULL || resultData->optimization->solution == NULL) return NULL;
	if( resultData->optimization->numberOfSolutions <= 0 || 
	   solIdx < 0 || solIdx >=  resultData->optimization->numberOfSolutions) return NULL;
	if(resultData->optimization->solution[solIdx] == NULL) return NULL;
	if(resultData->optimization->solution[solIdx]->status == NULL) return NULL;
	return resultData->optimization->solution[solIdx]->status->description;		
}//getSolutionStatusDescription

string OSResult::getSolutionMessage(int solIdx){
	if(resultData->optimization == NULL) return "there is no solution";
	if(resultData->optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  resultData->optimization->numberOfSolutions) return "there is no solution";
	if(resultData->optimization->solution[solIdx] == NULL) return "there is no solution";
	return resultData->optimization->solution[solIdx]->message;
}//getSolutionMessage

double* OSResult::getOptimalPrimalVariableValues(int objIdx){
	if(resultData->optimization == NULL || resultData->optimization->solution == NULL) return NULL;
	int iNumberOfVariables = this->getVariableNumber();
	if(iNumberOfVariables <= 0) return NULL;
	int iSolutions = this->getSolutionNumber();
	for(int i = 0; i < iSolutions; i++){
		if(resultData->optimization->solution[i] == NULL) continue;
		if(resultData->optimization->solution[i]->objectiveIdx != objIdx) continue;
		if(resultData->optimization->solution[i]->variables == NULL) continue;
		if(resultData->optimization->solution[i]->variables->values == NULL) continue;
		if((resultData->optimization->solution[i]->status->type.find("ptimal") != string::npos && m_mdPrimalValues == NULL) ||
			resultData->optimization->solution[i]->status->type.compare("globallyOptimal") == 0){				
			m_mdPrimalValues = new double[iNumberOfVariables];
			for(int j = 0; j < iNumberOfVariables; j++){
				m_mdPrimalValues[ j] = resultData->optimization->solution[i]->variables->values->var[j]->value;
			}
		}	
		if(resultData->optimization->solution[i]->status->type.compare("globallyOptimal") == 0){
			return m_mdPrimalValues;
		}
	}
	return m_mdPrimalValues;		
}//getOptimalPrimalVariableValues


double* OSResult::getOptimalDualVariableValues(int objIdx){
	if(resultData->optimization == NULL || resultData->optimization->solution == NULL) return NULL;
	int iNumberOfConstraints = this->getConstraintNumber();
	if(iNumberOfConstraints <= 0) return NULL;
	int iSolutions = this->getSolutionNumber();
	for(int i = 0; i < iSolutions; i++){
		if(resultData->optimization->solution[i] == NULL) continue;
		if(resultData->optimization->solution[i]->objectiveIdx != objIdx) continue;
		if(resultData->optimization->solution[i]->constraints == NULL) continue;
		if(resultData->optimization->solution[i]->constraints->dualValues == NULL) continue;
		if((resultData->optimization->solution[i]->status->type.find("ptimal") != string::npos && m_mdDualValues == NULL) ||
			resultData->optimization->solution[i]->status->type.compare("globallyOptimal") == 0){						
			m_mdDualValues = new double[iNumberOfConstraints];
			for(int j = 0; j < iNumberOfConstraints; j++){
				m_mdDualValues[ j] = resultData->optimization->solution[i]->constraints->dualValues->con[j]->value;
			}
		}	
		if(resultData->optimization->solution[i]->status->type.compare("globallyOptimal")){
			return m_mdDualValues;
		}
	}
	return m_mdDualValues;		
}//getOptimalDualVariableValues

// set methods

bool OSResult::setGeneralStatus(GeneralStatus *status){
	resultHeader->generalStatus = status;
	return true;
}//setGeneralStatus

bool OSResult::setGeneralStatusType(string type){
	if(resultHeader->generalStatus == NULL) resultHeader->generalStatus = new GeneralStatus();
	resultHeader->generalStatus->type = type;
	return true;
}//setGeneralStatusType

bool OSResult::setGeneralStatusDescription(string description){
	if(resultHeader->generalStatus == NULL) resultHeader->generalStatus = new GeneralStatus();
	resultHeader->generalStatus->description = description;
	return true;
}//setGeneralStatusDescription



bool OSResult::setServiceName(string serviceName){
	resultHeader->serviceName = serviceName;
	return true;
}//setServiceName

bool OSResult::setServiceURI(string serviceURI){
	resultHeader->serviceURI = serviceURI;
	return true;
}//setServiceURI

bool OSResult::setInstanceName(string instanceName){
	resultHeader->instanceName = instanceName;
	return true;
}//setInstanceName

bool OSResult::setJobID(string jobID){
	resultHeader->jobID = jobID;
	return true;
}//setJobID

bool OSResult::setGeneralMessage(string message){
	resultHeader->message = message;
	return true;
}//setGeneralMessage

bool OSResult::setVariableNumber(int variableNumber){
	if(variableNumber <= 0){
		return false;
	}
	if(resultData->optimization == NULL) resultData->optimization = new OptimizationResult();
	resultData->optimization->numberOfVariables = variableNumber;
	return true;
}//setVariableNumber

bool OSResult::setObjectiveNumber(int objectiveNumber){
	if(objectiveNumber < 0){
		return false;
	}
	if(resultData->optimization == NULL) resultData->optimization = new OptimizationResult();
	resultData->optimization->numberOfObjectives = objectiveNumber;
	return true;
}//setObjectiveNumber

bool OSResult::setConstraintNumber(int constraintNumber){
	if(constraintNumber < 0){
		return false;
	}
	if(resultData->optimization == NULL) resultData->optimization = new OptimizationResult();
	resultData->optimization->numberOfConstraints = constraintNumber;
	return true;
}//setConstraintNumber

bool OSResult::setSolutionNumber(int number){
	//if(getVariableNumber() <= 0) return false;
	//if(getObjectiveNumber() < 0) return false;
	//if(getConstraintNumber() < 0) return false;
	if(number < 0) return false; 
	if(number == 0) return true;
	if(resultData->optimization == NULL) resultData->optimization = new OptimizationResult();
	resultData->optimization->numberOfSolutions = number;
	resultData->optimization->solution = new OptimizationSolution*[number];
	for(int i = 0; i < number; i++){
		std::cout << "CREATING A NEW OPTIMIZATION SOLUTION" << std::endl;
		resultData->optimization->solution[i] = new OptimizationSolution();
	}
	return true;
}//setSolutionNumber

bool OSResult::setSolutionStatus(int solIdx, string type, string description){
 	int nSols = this->getSolutionNumber();
	if(resultData->optimization == NULL) return false;
	if(nSols <= 0) return false;
	if(resultData->optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if(resultData->optimization->solution[solIdx] == NULL){
		resultData->optimization->solution[solIdx] = new OptimizationSolution();
	}
	if(resultData->optimization->solution[solIdx]->status == NULL){
		resultData->optimization->solution[solIdx]->status = new OptimizationSolutionStatus();
	}
	// Kipp later when we finalize on type come back and require that the type be correct
	resultData->optimization->solution[solIdx]->status->type = type;
	resultData->optimization->solution[solIdx]->status->description = description;
	return true;
}//setSolutionStatus

bool OSResult::setSolutionObjectiveIndex(int solIdx, int objectiveIdx){
	int nSols = this->getSolutionNumber();
	if(resultData->optimization == NULL) return false;
	if(nSols <= 0) return false;
	if(resultData->optimization == NULL) return false;
	if(resultData->optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if(resultData->optimization->solution[solIdx] == NULL){
		resultData->optimization->solution[solIdx] = new OptimizationSolution();
	}
	if(objectiveIdx >= 0) return false;
	resultData->optimization->solution[solIdx]->objectiveIdx = objectiveIdx;
	return true;		
}//setSolutionObjectiveIndex

bool OSResult::setPrimalVariableValues(int solIdx, double *x){
	int iNumberOfVariables = this->getVariableNumber();
	if(iNumberOfVariables <= 0) return false;
	if(x == NULL) return false;
	int nSols = this->getSolutionNumber();
	if(resultData->optimization == NULL) return false;
	if(nSols <= 0) return false;
	if(resultData->optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if(resultData->optimization->solution[solIdx] == NULL){
		resultData->optimization->solution[solIdx] = new OptimizationSolution();
	}
	if(resultData->optimization->solution[solIdx]->variables == NULL){
		resultData->optimization->solution[solIdx]->variables = new VariableSolution();
	}
	if(resultData->optimization->solution[solIdx]->variables->values == NULL){
		resultData->optimization->solution[solIdx]->variables->values = new VariableValues();
	}
	if(x == NULL){
		//resultData->optimization->solution[solIdx]->variables->values->var = NULL;
		return true;
	}
	for(int i = 0; i < iNumberOfVariables; i++){
		resultData->optimization->solution[solIdx]->variables->values->var.push_back(new VarValue());
		resultData->optimization->solution[solIdx]->variables->values->var[i]->idx = i;
		resultData->optimization->solution[solIdx]->variables->values->var[i]->value = x[i];
	}
	return true;
}//setPrimalVariableValues


bool OSResult::setNumberOfOtherVariableResult(int solIdx, int numberOfOtherVariableResult){
	int iNumberOfVariables = this->getVariableNumber();
	if(iNumberOfVariables <= 0) return false;
	int nSols = this->getSolutionNumber();
	if(resultData->optimization == NULL) return false;
	if(nSols <= 0) return false;
	if(resultData->optimization == NULL) return false;
	if(resultData->optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if(resultData->optimization->solution[solIdx] == NULL){
		resultData->optimization->solution[solIdx] = new OptimizationSolution();
	}
	if(resultData->optimization->solution[solIdx]->variables == NULL){
		resultData->optimization->solution[solIdx]->variables = new VariableSolution();
	}
	resultData->optimization->solution[solIdx]->variables->numberOfOtherVariableResult =  numberOfOtherVariableResult;
	resultData->optimization->solution[solIdx]->variables->other = new OtherVariableResult*[ numberOfOtherVariableResult];
	for(int i = 0; i < numberOfOtherVariableResult; i++){
		resultData->optimization->solution[solIdx]->variables->other[ i]  = new OtherVariableResult();
	}
	return true;		
}//setNumberOfOtherVariableResult



bool OSResult::setAnOtherVariableResult(int solIdx, int otherIdx, string name, string description, string *s){
	int iNumberOfVariables = this->getVariableNumber();
	if(iNumberOfVariables <= 0) return false;
	int nSols = this->getSolutionNumber();
	if(resultData->optimization == NULL) return false;
	if(nSols <= 0) return false;
	if(resultData->optimization == NULL) return false;
	if(resultData->optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if(resultData->optimization->solution[solIdx] == NULL) return false;
	if(resultData->optimization->solution[solIdx]->variables == NULL)return false;
	if(resultData->optimization->solution[solIdx]->variables->other == NULL) return false;
	if(resultData->optimization->solution[solIdx]->variables->other[ otherIdx] == NULL) return false;
	resultData->optimization->solution[solIdx]->variables->other[ otherIdx]->name = name;
	resultData->optimization->solution[solIdx]->variables->other[ otherIdx]->description = description;
	for(int i = 0; i < iNumberOfVariables; i++){
		resultData->optimization->solution[solIdx]->variables->other[ otherIdx]->var.push_back(new OtherVarResult());
		resultData->optimization->solution[solIdx]->variables->other[ otherIdx]->var[i]->idx = i;
		resultData->optimization->solution[solIdx]->variables->other[ otherIdx]->var[i]->value = s[i];
	}
	return true;
}//setAnOtherVariableResult



bool OSResult::setObjectiveValues(int solIdx, double *objectiveValues){
	int iNumberOfObjectives = this->getObjectiveNumber();
	if(iNumberOfObjectives < 0) return false;
	if(iNumberOfObjectives == 0) return true;
	if(objectiveValues == NULL) return false;
	int nSols = this->getSolutionNumber();
	if(resultData->optimization == NULL) return false;
	if(nSols <= 0) return false;
	if(resultData->optimization == NULL) return false;
	if(resultData->optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if(resultData->optimization->solution[solIdx] == NULL){
		resultData->optimization->solution[solIdx] = new OptimizationSolution();
	}
	if(resultData->optimization->solution[solIdx]->objectives == NULL){
		resultData->optimization->solution[solIdx]->objectives = new ObjectiveSolution();
	}
	if(resultData->optimization->solution[solIdx]->objectives->values == NULL){
		resultData->optimization->solution[solIdx]->objectives->values = new ObjectiveValues();
	}
	for(int i = 0; i < iNumberOfObjectives; i++){
		resultData->optimization->solution[solIdx]->objectives->values->obj.push_back( new ObjValue());
		resultData->optimization->solution[solIdx]->objectives->values->obj[i]->idx = -(i+1);
		resultData->optimization->solution[solIdx]->objectives->values->obj[i]->value = objectiveValues[i];
	}
	return true;
}//setObjectiveValues

bool OSResult::setDualVariableValues(int solIdx, double *lbValues, double *ubValues){
	int iNumberOfConstraints = this->getConstraintNumber();
	if(iNumberOfConstraints < 0) return false;
	if(iNumberOfConstraints == 0) return true;
	int nSols = this->getSolutionNumber();
	if(resultData->optimization == NULL) return false;
	if(nSols <= 0) return false;
	if(resultData->optimization == NULL) return false;
	if(resultData->optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if(resultData->optimization->solution[solIdx] == NULL){
		resultData->optimization->solution[solIdx] = new OptimizationSolution();
	}
	if(resultData->optimization->solution[solIdx]->constraints == NULL){
		resultData->optimization->solution[solIdx]->constraints = new ConstraintSolution();
	}
	if(resultData->optimization->solution[solIdx]->constraints->dualValues == NULL){
		resultData->optimization->solution[solIdx]->constraints->dualValues = new DualVariableValues();
	}
	if(lbValues == NULL && ubValues == NULL){
		//resultData->optimization->solution[solIdx]->constraints->dualValues->con = NULL;
		return true;
	}
	int iCons = 0;
	if(lbValues == NULL){
		for(int i = 0; i < iNumberOfConstraints; i++){
			if(ubValues[i] != 0) iCons++;
		}
	}
	else if(ubValues == NULL){
		for(int i = 0; i < iNumberOfConstraints; i++){
			if(lbValues[i] != 0) iCons++;
		}
	}
	else{
		for(int i = 0; i < iNumberOfConstraints; i++){
			if(lbValues[i] != 0 || ubValues[i] != 0) iCons++;
		}
	}
	
	//resultData->optimization->solution[solIdx]->constraints->dualValues->con = new DualVarValue*[iCons];
	for(int i = 0; i < iCons; i++) resultData->optimization->solution[solIdx]->constraints->dualValues->con.push_back( new DualVarValue());
	int j = 0;
	if(lbValues == NULL){
		for(int i = 0; i < iNumberOfConstraints; i++){
			if(ubValues[i] != 0){
				resultData->optimization->solution[solIdx]->constraints->dualValues->con[j]->idx = i;
				resultData->optimization->solution[solIdx]->constraints->dualValues->con[j]->ubValue = 0;
				resultData->optimization->solution[solIdx]->constraints->dualValues->con[j]->ubValue = ubValues[i];
				j++;
			}
		}			
	}
	else if(ubValues == NULL){
		for(int i = 0; i < iNumberOfConstraints; i++){
			if(lbValues[i] != 0){
				resultData->optimization->solution[solIdx]->constraints->dualValues->con[j]->idx = i;
				resultData->optimization->solution[solIdx]->constraints->dualValues->con[j]->lbValue = lbValues[i];
				resultData->optimization->solution[solIdx]->constraints->dualValues->con[j]->ubValue = 0;
				j++;
			}
		}
	}
	else{
		for(int i = 0; i < iNumberOfConstraints; i++){
			if(lbValues[i] != 0 || ubValues[i] != 0){
				resultData->optimization->solution[solIdx]->constraints->dualValues->con[j]->idx = i;
				resultData->optimization->solution[solIdx]->constraints->dualValues->con[j]->lbValue = lbValues[i];
				resultData->optimization->solution[solIdx]->constraints->dualValues->con[j]->ubValue = ubValues[i];
				j++;
			}
		}
	}
	return true;
}//setDualVariableValues

bool OSResult::setDualVariableValues(int solIdx, double *y){
	int iNumberOfConstraints = this->getConstraintNumber();
	if(iNumberOfConstraints < 0) return false;
	if(iNumberOfConstraints == 0) return true;
	int nSols = this->getSolutionNumber();
	if(resultData->optimization == NULL) return false;
	if(nSols <= 0) return false;
	if(resultData->optimization == NULL) return false;
	if(resultData->optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if(resultData->optimization->solution[solIdx] == NULL){
		resultData->optimization->solution[solIdx] = new OptimizationSolution();
	}
	if(resultData->optimization->solution[solIdx]->constraints == NULL){
		resultData->optimization->solution[solIdx]->constraints = new ConstraintSolution();
	}
	if(resultData->optimization->solution[solIdx]->constraints->dualValues == NULL){
		resultData->optimization->solution[solIdx]->constraints->dualValues = new DualVariableValues();
	}
	if(y == NULL){
		resultData->optimization->solution[solIdx]->constraints->dualValues = NULL;
		return true;
	} 
	for(int i = 0; i < iNumberOfConstraints; i++){
		resultData->optimization->solution[solIdx]->constraints->dualValues->con.push_back( new DualVarValue());
		resultData->optimization->solution[solIdx]->constraints->dualValues->con[i]->idx = i;
		resultData->optimization->solution[solIdx]->constraints->dualValues->con[i]->value = y[i];
	}
	return true;
}//setDualVariableValues

bool OSResult::setConstraintValues(int solIdx, double *constraintValues){
	int iNumberOfConstraints = this->getConstraintNumber();
	if(iNumberOfConstraints <= 0) return false;
	int nSols = this->getSolutionNumber();
	if(resultData->optimization == NULL) return false;
	if(nSols <= 0) return false;
	if(resultData->optimization == NULL) return false;
	if(resultData->optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if(resultData->optimization->solution[solIdx] == NULL){
		resultData->optimization->solution[solIdx] = new OptimizationSolution();
	}
	if(resultData->optimization->solution[solIdx]->constraints == NULL){
		resultData->optimization->solution[solIdx]->constraints = new ConstraintSolution();
	}
	if(resultData->optimization->solution[solIdx]->constraints->values == NULL){
		resultData->optimization->solution[solIdx]->constraints->values = new ConstraintValues();
	}
	if(constraintValues == NULL){
		resultData->optimization->solution[solIdx]->constraints->values = NULL;
		return true;
	}
	//resultData->optimization->solution[solIdx]->constraints->values->con = new ConValue*[ iNumberOfConstraints];
	
	for(int i = 0; i < iNumberOfConstraints; i++){
		resultData->optimization->solution[solIdx]->constraints->values->con.push_back( new ConValue());
		//resultData->optimization->solution[solIdx]->constraints->values->con[i] = new ConValue();
		resultData->optimization->solution[solIdx]->constraints->values->con[i]->idx = i;
		resultData->optimization->solution[solIdx]->constraints->values->con[i]->value = constraintValues[i];
	}
	return true;
}//setConstraintValues


