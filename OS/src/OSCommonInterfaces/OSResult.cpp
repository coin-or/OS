/* $Id$ */
/** @file OSResult.cpp
 * 
 *
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin, 
 * @version 2.0, 19/07/2009
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005-2009, Robert Fourer, Jun Ma, Horand Gassmann, Kipp Martin,
 * Northwestern University, Dalhousie University and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */

#include "OSResult.h"
#include "OSParameters.h"
#include "OSErrorClass.h"


#include "OSDataStructures.h"
#include "OSParameters.h" 
#include "OSMathUtil.h"

#include<iostream>
#include<sstream>
//#define DEBUG_RESULT

using namespace std;

OSResult::OSResult():
	m_iVariableNumber( -1),
	m_iObjectiveNumber( -1),
	m_iConstraintNumber( -1),
	m_iNumberOfOtherVariableResults( -1),
	m_mdPrimalValues( NULL),
	m_mdDualValues( NULL)

{    
	#ifdef DEBUG_RESULT
	cout << "Inside OSResult Constructor" << endl;
	#endif
	this->general = new GeneralResult();
	this->system = new SystemResult();
	this->service = new ServiceResult();
	this->job = new JobResult();
	this->optimization = new OptimizationResult();
}// end OSResult constructor  

OSResult::~OSResult(){
	#ifdef DEBUG_RESULT
	cout << "OSResult Destructor Called" << endl;
	#endif
	// delete the children of OSResult
	// delete general object
	if(general != NULL) delete general;
	general = NULL;
	//delete system object
	if(system != NULL)  delete system;
	system = NULL;
	//delete service object
	if(service != NULL)  delete service;
	service = NULL;
	//delete job object
	if(job != NULL)  delete job;
	job = NULL;
	//delete optimization object
	if(optimization != NULL)  delete optimization;
	optimization = NULL;
	
	int k;

	if(m_mdPrimalValues != NULL) delete[] m_mdPrimalValues;
	m_mdPrimalValues = 0;
	if(m_mdDualValues != NULL) delete[] m_mdDualValues;
	m_mdDualValues = 0;
	
	int numPrimalVals =  this->primalVals.size();
  	for(k = 0; k < numPrimalVals; k++){	
  		if( this->primalVals[ k]  != NULL  ) 
			delete this->primalVals[ k];
  	}
  	this->primalVals.clear();
	
	
	int numDualVals =  this->dualVals.size();
  	for(k = 0; k < numDualVals; k++){
  		if( this->dualVals[ k]  != NULL  ) 
			delete this->dualVals[ k];
  	}
  	this->dualVals.clear();
}//end OSResult destructor

GeneralStatus::GeneralStatus():
	type( ""),
	description( "")
{    
	#ifdef DEBUG_RESULT
	cout << "Inside GeneralStatus Constructor" << endl;
	#endif
}// end GeneralStatus constructor  

GeneralStatus::~GeneralStatus(){
	#ifdef DEBUG_RESULT
	cout << "GeneralStatus Destructor Called" << endl;
	#endif
}//end GeneralStatus destructor


GeneralResult::GeneralResult():
	serviceURI(""),
	serviceName(""),
	instanceName(""),
	jobID(""),
	time("0.0"),
	message("")
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the GeneralResult Constructor" << endl;
	#endif
	generalStatus = new GeneralStatus();
}//end GeneralResult constructor


GeneralResult::~GeneralResult(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the GeneralResult Destructor" << endl;
	#endif
	delete generalStatus;
	generalStatus = NULL;
}// end GeneralResult destructor


SystemResult::SystemResult()  //:
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the SystemResult Constructor" << endl;
	#endif
}//end SystemResult constructor


SystemResult::~SystemResult(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the SystemResult Destructor" << endl;
	#endif
}// end SystemResult destructor



ServiceResult::ServiceResult()  //:
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the ServiceResult Constructor" << endl;
	#endif
}//end ServiceResult constructor


ServiceResult::~ServiceResult(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the ServiceResult Destructor" << endl;
	#endif
}// end ServiceResult destructor


Time::Time():
	type("elapsedTime"),
	category("total"),
	unit("second"),
	description(""),
	value(0.0)
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the Time Constructor" << endl;
	#endif
}//end Time constructor


Time::~Time(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the Time Destructor" << endl;
	#endif

}// end TimingInformation destructor

TimingInformation::TimingInformation():
	numberOfTimes(0)
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the TimingInformation Constructor" << endl;
	#endif
	time = NULL;
}//end TimingInformation constructor


TimingInformation::~TimingInformation(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the TimingInformation Destructor" << endl;
	#endif
	if (time != NULL)
	{
		for (int i = 0; i < numberOfTimes; i++)
		{	delete time[i];
			time[i] = NULL;
		}
		delete [] time;
		time = NULL;
	}
}// end TimingInformation destructor


JobResult::JobResult() //:
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the JobResult Constructor" << endl;
	#endif
	timingInformation = NULL;
}//end JobResult constructor


JobResult::~JobResult(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the JobResult Destructor" << endl;
	#endif
	if (timingInformation != NULL) delete timingInformation;
	timingInformation = NULL;
}// end JobResult destructor

VarValue::VarValue():
	idx( -1),
	value( 0)
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the VarValue Constructor" << endl;
	#endif
}//end VarValue constructor


VarValue::~VarValue(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the VarValue Destructor" << endl;
	#endif
}// end VarValue destructor 


OtherVarResult::OtherVarResult():
	idx( -1),
	value( "")
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the OtherVarResult Constructor" << endl;
	#endif
}//end OtherVarResult constructor


OtherVarResult::~OtherVarResult(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the OtherVarResult Destructor" << endl;
	#endif
}// end OtherVarResult destructor 


OtherObjResult::OtherObjResult():
	idx( -1),
	value( "")
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the OtherObjResult Constructor" << endl;
	#endif
}//end OtherObjResult constructor


OtherObjResult::~OtherObjResult(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the OtherObjResult Destructor" << endl;
	#endif
}//end OtherObjResult destructor


OtherConResult::OtherConResult():
	idx( -1),
	value( "")
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the OtherConResult Constructor" << endl;
	#endif
}//end OtherConResult constructor


OtherConResult::~OtherConResult(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the OtherConResult Destructor" << endl;
	#endif
}//end OtherConResult destructor


ObjValue::ObjValue():
	idx( -1),
	value( OSNAN)
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the ObjValue Constructor" << endl;
	#endif
}//end ObjValue constructor

ObjValue::~ObjValue(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the ObjValue Destructor" << endl;
	#endif
}// end ObjValue destructor 

DualVarValue::DualVarValue():
	idx( -1),
	//lbValue( 0),
	//ubValue( 0),
	value( 0)
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the DualVarValue Constructor" << endl;
	#endif
}//end DualVarValue constructor


DualVarValue::~DualVarValue(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the DualVarValue Destructor" << endl;
	#endif
}// end DualVarValue destructor



VariableValues::VariableValues() { 
	#ifdef DEBUG_RESULT
	cout << "Inside the VariableValues Constructor" << endl;
	#endif

}//end VariableValues constructor


VariableValues::~VariableValues(){
	#ifdef DEBUG_RESULT  
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
	numberOfVar(-1),
	value(""),
	name(""),
	description("")
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the OtherVariableResult Constructor" << endl;
	#endif

}//end OtherVariableResult constructor


OtherVariableResult::~OtherVariableResult(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the OtherVariableResult Destructor" << endl;
	#endif
	int n = var.size();
	if (n > 0) {
		for(int i = 0; i < n; i++){
			delete var[i];
			var[i] = NULL;
		}
	}
	var.clear(); 
	#ifdef DEBUG_RESULT  
	cout << "Inside the OtherVariableResult Destructor - Done" << endl;
	#endif
}// end OtherVariableResult destructor 


OtherObjectiveResult::OtherObjectiveResult():
	name(""),
	description("")
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the OtherObjectiveResult Constructor" << endl;
	#endif
}//end OtherObjectiveResult constructor


OtherObjectiveResult::~OtherObjectiveResult(){
	#ifdef DEBUG_RESULT  
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
	#ifdef DEBUG_RESULT
	cout << "Inside the OtherConstraintResult Constructor" << endl;
	#endif
}//end OtherConstraintResult constructor


OtherConstraintResult::~OtherConstraintResult(){
	#ifdef DEBUG_RESULT  
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
	#ifdef DEBUG_RESULT
	cout << "Inside the ObjectiveValues Constructor" << endl;
	#endif

}//end ObjectiveValues constructor


ObjectiveValues::~ObjectiveValues(){
	#ifdef DEBUG_RESULT  
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



DualVariableValues::DualVariableValues() { 
	#ifdef DEBUG_RESULT
	cout << "Inside the DualVariableValues Constructor" << endl;
	#endif

}//end DualVariableValues constructor


DualVariableValues::~DualVariableValues(){
	#ifdef DEBUG_RESULT  
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



OptimizationSolutionStatus::OptimizationSolutionStatus():
	type(""),
	description("")
	//substatus( NULL),
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the OptimizationSolutionStatus Constructor" << endl;
	#endif
}//end OptimizationSolutionStatus constructor


OptimizationSolutionStatus::~OptimizationSolutionStatus(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the OptimzationSolutionStatus Destructor" << endl;
	#endif
}// end OptimizationSolutionStatus destructor 



VariableSolution::VariableSolution():
	numberOfOtherVariableResults( 0),
	values( NULL),
	other( NULL)

{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the VariableSolution Constructor" << endl;
	#endif
}//end VariableSolution constructor


VariableSolution::~VariableSolution(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the VariableSolution Destructor" << endl;
	#endif
	delete  values;
	values = NULL;
	if(numberOfOtherVariableResults > 0 && other != NULL){
		for(int i = 0; i < numberOfOtherVariableResults; i++){
			delete other[i];
			other[i] = NULL;
		}
	}
	delete[] other;
	other = NULL; 
}// end VariableSolution destructor 

ObjectiveSolution::ObjectiveSolution():
	numberOfOtherObjectiveResults( 0),
	values( NULL),
	other( NULL)

{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the ObjectiveSolution Constructor" << endl;
	#endif
}//end ObjectiveSolution constructor


ObjectiveSolution::~ObjectiveSolution(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the ObjectiveSolution Destructor" << endl;
	#endif
	delete  values;
	values = NULL;
	if(numberOfOtherObjectiveResults > 0 && other != NULL){
		for(int i = 0; i < numberOfOtherObjectiveResults; i++){
			delete other[i];
			other[i] = NULL;
		}
	}
	delete[] other;
	other = NULL; 
}// end ObjectiveSolution destructor 



ConstraintSolution::ConstraintSolution():
	numberOfOtherConstraintResults( 0),
	dualValues( NULL),
	other( NULL)
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the ConstraintSolution Constructor" << endl;
	#endif
}//end ConstraintSolution constructor


ConstraintSolution::~ConstraintSolution(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the ConstraintSolution Destructor" << endl;
	#endif
	delete  dualValues;
	dualValues = NULL;
	if(numberOfOtherConstraintResults > 0 && other != NULL){
		for(int i = 0; i < numberOfOtherConstraintResults; i++){
			delete other[i];
			other[i] = NULL;
		}
	}
	delete[] other;
	other = NULL; 
}// end ConstraintSolution destructor

OtherSolutionResult::OtherSolutionResult():
	name( ""),
	category (""),
	description (""),
	numberOfRecords (0),
	record( NULL)
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the OtherSolutionResult Constructor" << endl;
	#endif
	record = NULL;
}//end OtherSolutionResult constructor


OtherSolutionResult::~OtherSolutionResult(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the OtherSolutionResult Destructor" << endl;
	#endif
	if (record != NULL) 
	{	delete[] record;
		record = NULL;
	}
}// end OtherSolutionResult destructor


OtherSolutionResults::OtherSolutionResults():
	numberOfOtherSolutionResults( 0),
	otherSolutionResult( NULL)
	
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the OtherSolutionResults Constructor" << endl;
	#endif
	otherSolutionResult = NULL;
}//end OtherSolutionResults constructor


OtherSolutionResults::~OtherSolutionResults(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the OtherSolutionResults Destructor" << endl;
	#endif
	if(numberOfOtherSolutionResults > 0 && otherSolutionResult != NULL){
		for(int i = 0; i < numberOfOtherSolutionResults; i++){
			delete otherSolutionResult[i];
			otherSolutionResult[i] = NULL;
		}
	}
	delete[] otherSolutionResult;
	otherSolutionResult = NULL; 
}// end OtherSolutionResults destructor


OptimizationSolution::OptimizationSolution():
	targetObjectiveIdx( -1),
	message( ""),
	variables( NULL),
	objectives( NULL),
	constraints( NULL),
	otherSolutionResults( NULL)
	//other(NULL)
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the OptimizationSolution Constructor" << endl;
	#endif
	status = new OptimizationSolutionStatus();
}//end OptimizationSolution constructor


OptimizationSolution::~OptimizationSolution(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the OptimzationSolution Destructor" << endl;
	#endif
	if(variables != NULL){
		delete variables;
		variables = NULL;
	}
	if(constraints != NULL) {
		delete constraints;
		constraints = NULL;
	}
	if(objectives != NULL){
		delete objectives;
		objectives = NULL;
	}
	if(status != NULL){
		delete status;
		status = NULL;
	}
	if(otherSolutionResults != NULL){
		delete otherSolutionResults;
		otherSolutionResults = NULL;
	}
}// end OptimizationSolution destructor 
 

OptimizationResult::OptimizationResult():
	numberOfVariables( -1),
	numberOfObjectives( -1),
	numberOfConstraints(-1),
	numberOfSolutions( -1),
	solution(NULL)
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the OptimizationResult Constructor" << endl;
	#endif
}//end OptimizationResult constructor


OptimizationResult::~OptimizationResult(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the OptimizationResult Destructor" << endl;
	#endif
	if( solution != NULL){
		for(int i = 0; i < this->numberOfSolutions; i++){
			delete solution[i];
			solution[i] = NULL;
			#ifdef DEBUG_RESULT  
			cout << "Deleting Solution: " << i << endl;
			#endif
		}
	}
	delete[] solution;
	solution = NULL; 
}// end OptimizationResult destructor 
 

//
// get methods

GeneralStatus* OSResult::getGeneralStatus(){
	return general->generalStatus;
}//getGeneralStatus


string OSResult::getGeneralStatusType(){
	if(general->generalStatus == NULL) return "";
	return general->generalStatus->type;
}//getGeneralStatusType

string OSResult::getGeneralStatusDescription(){
	if(general->generalStatus == NULL) return NULL;
	return general->generalStatus->description;
}//getGeneralStatusDescription

string OSResult::getServiceName(){
	return general->serviceName;
}//getServiceName

string OSResult::getServiceURI(){
	return general->serviceURI;
}//getServiceURI

string OSResult::getInstanceName(){
	return general->instanceName;
}//getInstanceName

string OSResult::getJobID(){
	return general->jobID;
}//getJobID


string OSResult::getGeneralMessage(){
	return general->message;
}//getGeneralMessage


double OSResult::getTimeValue()
{	if (job == NULL) return 0.0;
	if (job->timingInformation == NULL) return 0.0;
	if (job->timingInformation->numberOfTimes <= 0) return 0.0;
	return job->timingInformation->time[0]->value;
}//getTime


int OSResult::getTimeNumber()
{	if (job == NULL) return -1;
	if (job->timingInformation == NULL) return -1;
	return job->timingInformation->numberOfTimes;
}//getTime


int OSResult::getVariableNumber(){
	if(m_iVariableNumber == -1){
		if(optimization == NULL) return -1;
		m_iVariableNumber = optimization->numberOfVariables;
	}
	return m_iVariableNumber;
}//getVariableNumber



int OSResult::getObjectiveNumber(){
	if(m_iObjectiveNumber == -1){
		if(optimization == NULL) return -1;
		m_iObjectiveNumber = optimization->numberOfObjectives;
	}
	return m_iObjectiveNumber;
}//getObjectiveNumber


int OSResult::getConstraintNumber(){
	if(m_iConstraintNumber == -1){
		if(optimization == NULL) return -1;
		m_iConstraintNumber = optimization->numberOfConstraints;
	}
	return m_iConstraintNumber;
}//getConstraintNumber

int OSResult::getSolutionNumber(){
	if(optimization == NULL) return 0;
	if(optimization->solution == NULL) return 0;
	return optimization->numberOfSolutions;
}//getSolutionNumber


int OSResult::getNumberOfOtherVariableResults(int solIdx){
	if(m_iNumberOfOtherVariableResults == -1){
		if(optimization->solution[solIdx]->variables->other == NULL) return -1;
		m_iNumberOfOtherVariableResults = optimization->solution[solIdx]->variables->numberOfOtherVariableResults;
	}
	return m_iNumberOfOtherVariableResults;
}//getNumberOfOtherVariableResults


OptimizationSolutionStatus* OSResult::getSolutionStatus( int solIdx){
	if(optimization == NULL || optimization->solution == NULL) return NULL;
	if( optimization->numberOfSolutions <= 0 || 
	   solIdx < 0 || solIdx >=  optimization->numberOfSolutions) return NULL;
	if(optimization->solution[solIdx] == NULL) return NULL;
	return optimization->solution[solIdx]->status;
}//getSolutionStatus

string OSResult::getSolutionStatusType(int solIdx){
	if(optimization == NULL || optimization->solution == NULL) return NULL;
	if( optimization->numberOfSolutions <= 0 || 
	   solIdx < 0 || solIdx >=  optimization->numberOfSolutions) return NULL;
	if(optimization->solution[solIdx] == NULL) return NULL;
	if(optimization->solution[solIdx]->status == NULL) return NULL;
	return optimization->solution[solIdx]->status->type;		
}//getSolutionStatusType

string OSResult::getSolutionStatusDescription(int solIdx){
	if(optimization == NULL || optimization->solution == NULL) return NULL;
	if( optimization->numberOfSolutions <= 0 || 
	   solIdx < 0 || solIdx >=  optimization->numberOfSolutions) return NULL;
	if(optimization->solution[solIdx] == NULL) return NULL;
	if(optimization->solution[solIdx]->status == NULL) return NULL;
	return optimization->solution[solIdx]->status->description;		
}//getSolutionStatusDescription

string OSResult::getSolutionMessage(int solIdx){
	if(optimization == NULL) return "there is no solution";
	if(optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  optimization->numberOfSolutions) return "there is no solution";
	if(optimization->solution[solIdx] == NULL) return "there is no solution";
	return optimization->solution[solIdx]->message;
}//getSolutionMessage

std::vector<IndexValuePair*> OSResult::getOptimalPrimalVariableValues(int solIdx){
	
	int numberOfVar;
	struct IndexValuePair *primalValPair;
	int iSolutions = this->getSolutionNumber();
	for(int i = 0; i < iSolutions; i++){
		if( i != solIdx) continue;
		if(optimization->solution[i] == NULL) continue;
		if(optimization->solution[i]->variables == NULL) continue;
		if(optimization->solution[i]->variables->values == NULL) continue;
		if((optimization->solution[i]->status->type.find("ptimal") != string::npos && m_mdPrimalValues == NULL) ||
			optimization->solution[i]->status->type.compare("globallyOptimal") == 0){	
			numberOfVar = optimization->solution[i]->variables->values->var.size();	
			for(int j = 0; j < numberOfVar; j++){
				primalValPair = new IndexValuePair();
				primalValPair->value = optimization->solution[i]->variables->values->var[j]->value;
				primalValPair->idx = optimization->solution[i]->variables->values->var[j]->idx;
				primalVals.push_back( primalValPair);
			}
		}	
		if(optimization->solution[i]->status->type.compare("globallyOptimal") == 0){
			return primalVals;
		}
	}
	return primalVals;		
}//getOptimalPrimalVariableValues


int OSResult::getAnOtherVariableResultNumberOfVar(int solIdx, int iOther){
	if(optimization == NULL || optimization->solution == NULL) return -1;
	int iSolutions = this->getSolutionNumber();
	if (solIdx < 0 || solIdx >= iSolutions) return -1;
	if (optimization->solution[solIdx]->variables == NULL) return -1;
	if (optimization->solution[solIdx]->variables->other == NULL) return -1;
	if (iOther < 0 || iOther >= optimization->solution[solIdx]->variables->numberOfOtherVariableResults) return -1;
	return optimization->solution[solIdx]->variables->other[iOther]->numberOfVar;
}
	
	
std::vector<IndexValuePair*>  OSResult::getOptimalDualVariableValues(int solIdx){

	int numberOfCon;
	struct IndexValuePair *dualValPair;
	int iSolutions = this->getSolutionNumber();
	for(int i = 0; i < iSolutions; i++){
		if(i != solIdx) continue;
		if(optimization->solution[i] == NULL) continue;
		if(optimization->solution[i]->constraints == NULL) continue;
		if(optimization->solution[i]->constraints->dualValues == NULL) continue;
		if((optimization->solution[i]->status->type.find("ptimal") != string::npos && m_mdDualValues == NULL) ||
			optimization->solution[i]->status->type.compare("globallyOptimal") == 0){						
			numberOfCon = optimization->solution[i]->constraints->dualValues->con.size();	
			for(int j = 0; j < numberOfCon;  j++){
				dualValPair = new IndexValuePair();
				dualValPair->idx = optimization->solution[i]->constraints->dualValues->con[j]->idx;
				dualValPair->value = optimization->solution[i]->constraints->dualValues->con[j]->value;
				dualVals.push_back( dualValPair);
			}
		}	
		if(optimization->solution[i]->status->type.compare("globallyOptimal") == 0){
			return dualVals;
		}
	}
	return dualVals;		
}//getOptimalDualVariableValues

double OSResult::getOptimalObjValue(int objIdx, int solIdx)
{
	try{
		if(this->optimization == NULL || this->optimization->solution == NULL)   
		throw ErrorClass("No optimization or solution object defined");  
		int iSolutions = this->getSolutionNumber();  
		for(int i = 0; i < iSolutions; i++){  
			if(i != solIdx) continue;  
			if(this->optimization->solution[i]->targetObjectiveIdx != objIdx) continue;  
			if((this->optimization->solution[i]->status->type.find("ptimal") != string::npos ) ||  
					this->optimization->solution[i]->status->type.compare("globallyOptimal") == 0){   
				return  this->optimization->solution[i]->objectives->values->obj[ abs( objIdx)  -1 ]->value;  
			}
			else{  
				throw ErrorClass("There is no optimal solution");  
			}
		}
		throw ErrorClass("There is no optimal solution");  
	}
	catch(const ErrorClass& eclass){  
		throw ErrorClass(  eclass.errormsg);   
	}
}//getOptimalObjValue  


// set methods

bool OSResult::setGeneralStatus(GeneralStatus *status){
	general->generalStatus = status;
	return true;
}//setGeneralStatus

bool OSResult::setGeneralStatusType(string type){
	if(general->generalStatus == NULL) general->generalStatus = new GeneralStatus();
	general->generalStatus->type = type;
	return true;
}//setGeneralStatusType

bool OSResult::addTimingInformation(std::string type, std::string category,
									std::string unit, std::string description, double value)
{	int nt; int i;
	if (job == NULL) job = new JobResult();
	if (job->timingInformation == NULL) job->timingInformation = new TimingInformation();

	nt = job->timingInformation->numberOfTimes;
	Time** temp = new Time*[nt+1];  //Allocate the new pointers
	for (i = 0; i < nt; i++)
		temp[i] = job->timingInformation->time[i];  //copy the pointers

	delete[] job->timingInformation->time; //delete old pointers
	
//	add in the new element
	temp[ nt] = new Time();

	temp[ nt]->type = type;
	temp[ nt]->category = category;
	temp[ nt]->unit = unit;
	temp[ nt]->description = description;
	temp[ nt]->value = value;

	job->timingInformation->time = temp;   //hook the new pointers into the data structure
	job->timingInformation->numberOfTimes = ++nt;

	return true;
}//addTimingInformation


bool OSResult::setGeneralStatusDescription(string description){
	if(general->generalStatus == NULL) general->generalStatus = new GeneralStatus();
	general->generalStatus->description = description;
	return true;
}//setGeneralStatusDescription



bool OSResult::setServiceName(string serviceName){
	general->serviceName = serviceName;
	return true;
}//setServiceName

bool OSResult::setServiceURI(string serviceURI){
	general->serviceURI = serviceURI;
	return true;
}//setServiceURI

bool OSResult::setInstanceName(string instanceName){
	general->instanceName = instanceName;
	return true;
}//setInstanceName

bool OSResult::setJobID(string jobID){
	general->jobID = jobID;
	return true;
}//setJobID

bool OSResult::setTime(double time){
//	general->time = os_dtoa_format( time);
    return addTimingInformation("elapsedTime", "total", "second", "", time);
}//setTime

bool OSResult::setTimeNumber(int timeNumber)
{	if (job == NULL) job = new JobResult();
	if (job->timingInformation == NULL) job->timingInformation = new TimingInformation();
    if (timeNumber <= 0) return false;
	job->timingInformation->numberOfTimes = timeNumber;
	return true;
}//setTimeNumber

bool OSResult::setGeneralMessage(string message){
	general->message = message;
	return true;
}//setGeneralMessage

bool OSResult::setVariableNumber(int variableNumber){
	if(variableNumber <= 0){
		return false;
	}
	if(optimization == NULL) optimization = new OptimizationResult();
	optimization->numberOfVariables = variableNumber;
	return true;
}//setVariableNumber

bool OSResult::setObjectiveNumber(int objectiveNumber){
	if(objectiveNumber < 0){
		return false;
	}
	if(optimization == NULL) optimization = new OptimizationResult();
	optimization->numberOfObjectives = objectiveNumber;
	return true;
}//setObjectiveNumber

bool OSResult::setConstraintNumber(int constraintNumber){
	if(constraintNumber < 0){
		return false;
	}
	if(optimization == NULL) optimization = new OptimizationResult();
	optimization->numberOfConstraints = constraintNumber;
	return true;
}//setConstraintNumber

bool OSResult::setSolutionNumber(int number){
	//if(getVariableNumber() <= 0) return false;
	//if(getObjectiveNumber() < 0) return false;
	//if(getConstraintNumber() < 0) return false;
	if(number < 0) return false; 
	if(number == 0) return true;
	if(optimization == NULL) optimization = new OptimizationResult();
	optimization->numberOfSolutions = number;
	optimization->solution = new OptimizationSolution*[number];
	for(int i = 0; i < number; i++){
		optimization->solution[i] = new OptimizationSolution();
	}
	return true;
}//setSolutionNumber

bool OSResult::setSolutionStatus(int solIdx, string type, string description){
 	int nSols = this->getSolutionNumber();
	if(optimization == NULL) return false;
	if(nSols <= 0) return false;
	if(optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if(optimization->solution[solIdx] == NULL){
		optimization->solution[solIdx] = new OptimizationSolution();
	}
	if(optimization->solution[solIdx]->status == NULL){
		optimization->solution[solIdx]->status = new OptimizationSolutionStatus();
	}
	// Kipp later when we finalize on type come back and require that the type be correct
	optimization->solution[solIdx]->status->type = type;
	optimization->solution[solIdx]->status->description = description;
	return true;
}//setSolutionStatus

bool OSResult::setSolutionTargetObjectiveIdx(int solIdx, int objectiveIdx){
	int nSols = this->getSolutionNumber();
	if(optimization == NULL) return false;
	if(nSols <= 0) return false;
	if(optimization == NULL) return false;
	if(optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if(optimization->solution[solIdx] == NULL){
		optimization->solution[solIdx] = new OptimizationSolution();
	}
	if(objectiveIdx >= 0) return false;
	optimization->solution[solIdx]->targetObjectiveIdx = objectiveIdx;
	return true;		
}//setSolutionTargetObjectiveIdx


bool OSResult::setSolutionMessage(int solIdx, std::string msg){
	int nSols = this->getSolutionNumber();
	if(optimization == NULL) return false;
	if(nSols <= 0) return false;
	if(optimization == NULL) return false;
	if(optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if(optimization->solution[solIdx] == NULL){
		optimization->solution[solIdx] = new OptimizationSolution();
	}
	optimization->solution[solIdx]->message = msg;
	return true;		
}//setSolutionMessage



bool OSResult::setNumberOfPrimalVariableValues(int solIdx, int numberOfVar){
	int nSols = this->getSolutionNumber();
	int nVar  = this->getVariableNumber();
	if (numberOfVar <= 0 || numberOfVar > nVar) return false;
	if(optimization == NULL) return false;
	if(nSols <= 0) return false;
	if(optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if(optimization->solution[solIdx] == NULL){
		optimization->solution[solIdx] = new OptimizationSolution();
	}
	if(optimization->solution[solIdx]->variables == NULL){
		optimization->solution[solIdx]->variables = new VariableSolution();
	}
	if(optimization->solution[solIdx]->variables->values == NULL){
		optimization->solution[solIdx]->variables->values = new VariableValues();
	}
	optimization->solution[solIdx]->variables->values->numberOfVar = numberOfVar;
//	optimization->solution[solIdx]->variables->values->var = new VarValue*[numberOfVar];

	return true;
}//setNumberOfPrimalVariableValues

bool OSResult::setPrimalVariableValuesSparse(int solIdx, std::vector<IndexValuePair*> x){
	int nSols = this->getSolutionNumber();
	int numberOfVar = x.size();
	if(optimization == NULL) return false;
	if(nSols <= 0) return false;
	if(optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if(optimization->solution[solIdx] == NULL){
		optimization->solution[solIdx] = new OptimizationSolution();
	}
	if(optimization->solution[solIdx]->variables == NULL){
		optimization->solution[solIdx]->variables = new VariableSolution();
	}
	if(optimization->solution[solIdx]->variables->values == NULL){
		optimization->solution[solIdx]->variables->values = new VariableValues();
	}
	optimization->solution[solIdx]->variables->values->numberOfVar = numberOfVar;
	if(x.size() == 0){
		//optimization->solution[solIdx]->variables->values->var = NULL;
		return true;
	}
	for(int i = 0; i < numberOfVar; i++){
		optimization->solution[solIdx]->variables->values->var.push_back(new VarValue());
		optimization->solution[solIdx]->variables->values->var[i]->idx = x[i]->idx;
		optimization->solution[solIdx]->variables->values->var[i]->value = x[i]->value;
	}
	return true;
}//setPrimalVariableValuesSparse

bool OSResult::setPrimalVariableValuesDense(int solIdx, double *x){
	int numberOfVar = this->getVariableNumber();
	int nSols = this->getSolutionNumber();
	if(optimization == NULL) return false;
	if(nSols <= 0) return false;
	if(optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if(optimization->solution[solIdx] == NULL){
		optimization->solution[solIdx] = new OptimizationSolution();
	}
	if(optimization->solution[solIdx]->variables == NULL){
		optimization->solution[solIdx]->variables = new VariableSolution();
	}
	if(optimization->solution[solIdx]->variables->values == NULL){
		optimization->solution[solIdx]->variables->values = new VariableValues();
	}
	optimization->solution[solIdx]->variables->values->numberOfVar = numberOfVar;
	if(x == NULL){
		//optimization->solution[solIdx]->variables->values->var = NULL;
		return true;
	}
	for(int i = 0; i < numberOfVar; i++){
		optimization->solution[solIdx]->variables->values->var.push_back(new VarValue());
		optimization->solution[solIdx]->variables->values->var[i]->idx = i;
		optimization->solution[solIdx]->variables->values->var[i]->value = x[i];
	}
	return true;
}//setPrimalVariableValuesDense


bool OSResult::setNumberOfOtherVariableResults(int solIdx, int numberOfOtherVariableResults){
	//int iNumberOfVariables = this->getVariableNumber();
	//if(iNumberOfVariables <= 0) return false;
	int nSols = this->getSolutionNumber();
	if(nSols <= 0) return false;
	if(optimization == NULL) return false;
	if(optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if(optimization->solution[solIdx] == NULL){
		optimization->solution[solIdx] = new OptimizationSolution();
	}
	if(optimization->solution[solIdx]->variables == NULL){
		optimization->solution[solIdx]->variables = new VariableSolution();
	}
	optimization->solution[solIdx]->variables->numberOfOtherVariableResults =  numberOfOtherVariableResults;
	optimization->solution[solIdx]->variables->other = new OtherVariableResult*[ numberOfOtherVariableResults];
	for(int i = 0; i < numberOfOtherVariableResults; i++){
		optimization->solution[solIdx]->variables->other[ i]  = new OtherVariableResult();
	}
	return true;		
}//setNumberOfOtherVariableResults


bool OSResult::setAnOtherVariableResultSparse(int solIdx, int otherIdx, string name, string value, string description, int  *idx,  string *s, int numberOfVar){
	int iNumberOfVariables = numberOfVar;
	if(iNumberOfVariables <= -1) return false;
	int nSols = this->getSolutionNumber();
	if(optimization == NULL) return false;
	if(nSols <= 0) return false;
	if(optimization == NULL) return false;
	if(optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if(optimization->solution[solIdx] == NULL) return false;
	if(optimization->solution[solIdx]->variables == NULL)return false;
	if(optimization->solution[solIdx]->variables->other == NULL) return false;
	if(optimization->solution[solIdx]->variables->other[ otherIdx] == NULL) return false;
	optimization->solution[solIdx]->variables->other[ otherIdx]->name = name;
	optimization->solution[solIdx]->variables->other[ otherIdx]->value = value;
	optimization->solution[solIdx]->variables->other[ otherIdx]->description = description;
	optimization->solution[solIdx]->variables->other[ otherIdx]->numberOfVar = numberOfVar;
	for(int i = 0; i < iNumberOfVariables; i++){
		optimization->solution[solIdx]->variables->other[ otherIdx]->var.push_back(new OtherVarResult());
		optimization->solution[solIdx]->variables->other[ otherIdx]->var[i]->idx = idx[i];
		optimization->solution[solIdx]->variables->other[ otherIdx]->var[i]->value = s[i];
		
	}
	return true;
}//setAnOtherVariableResultSparse


bool OSResult::setAnOtherVariableResultDense(int solIdx, int otherIdx, string name, string value, string description, string *s){
	int numberOfVar = this->getVariableNumber();
	int iNumberOfVariables = numberOfVar;
	if(iNumberOfVariables <= -1) return false;
	int nSols = this->getSolutionNumber();
	if(optimization == NULL) return false;
	if(nSols <= 0) return false;
	if(optimization == NULL) return false;
	if(optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if(optimization->solution[solIdx] == NULL) return false;
	if(optimization->solution[solIdx]->variables == NULL)return false;
	if(optimization->solution[solIdx]->variables->other == NULL) return false;
	if(optimization->solution[solIdx]->variables->other[ otherIdx] == NULL) return false;
	optimization->solution[solIdx]->variables->other[ otherIdx]->name = name;
	optimization->solution[solIdx]->variables->other[ otherIdx]->value = value;
	optimization->solution[solIdx]->variables->other[ otherIdx]->description = description;
	optimization->solution[solIdx]->variables->other[ otherIdx]->numberOfVar = numberOfVar;
	for(int i = 0; i < iNumberOfVariables; i++){
		optimization->solution[solIdx]->variables->other[ otherIdx]->var.push_back(new OtherVarResult());
		optimization->solution[solIdx]->variables->other[ otherIdx]->var[i]->idx = i;
		optimization->solution[solIdx]->variables->other[ otherIdx]->var[i]->value = s[i];
		;
	}
	return true;
}//setAnOtherVariableResultDense

bool OSResult::setNumberOfObjectiveValues(int solIdx, int numberOfObj){
	int nSols = this->getSolutionNumber();
	int nObj  = this->getObjectiveNumber();
	if (numberOfObj <= 0 || numberOfObj > nObj) return false;
	if(optimization == NULL) return false;
	if(nSols <= 0) return false;
	if(optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if(optimization->solution[solIdx] == NULL){
		optimization->solution[solIdx] = new OptimizationSolution();
	}
	if(optimization->solution[solIdx]->objectives == NULL){
		optimization->solution[solIdx]->objectives = new ObjectiveSolution();
	}
	if(optimization->solution[solIdx]->objectives->values == NULL){
		optimization->solution[solIdx]->objectives->values = new ObjectiveValues();
	}
	optimization->solution[solIdx]->objectives->values->numberOfObj = numberOfObj;
//	optimization->solution[solIdx]->objectives->values->obj = new ObjValue*[numberOfObj];

	return true;
}//setNumberOfObjectiveValues



bool OSResult::setObjectiveValuesSparse(int solIdx, std::vector<IndexValuePair*> x){
	int numberOfObj = x.size();
	int iNumberOfObjectives = numberOfObj;
	if(iNumberOfObjectives < 0) return false;
	if(iNumberOfObjectives == 0) return true;
	if(x.size() == 0) return false;
	int nSols = this->getSolutionNumber();
	if(optimization == NULL) return false;
	if(nSols <= 0) return false;
	if(optimization == NULL) return false;
	if(optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if(optimization->solution[solIdx] == NULL){
		optimization->solution[solIdx] = new OptimizationSolution();
	}
	if(optimization->solution[solIdx]->objectives == NULL){
		optimization->solution[solIdx]->objectives = new ObjectiveSolution();
	}
	if(optimization->solution[solIdx]->objectives->values == NULL){
		optimization->solution[solIdx]->objectives->values = new ObjectiveValues();
	}
	optimization->solution[solIdx]->objectives->values->numberOfObj = iNumberOfObjectives;
	for(int i = 0; i < iNumberOfObjectives; i++){
		optimization->solution[solIdx]->objectives->values->obj.push_back( new ObjValue());
		optimization->solution[solIdx]->objectives->values->obj[i]->idx = x[i]->idx;
		optimization->solution[solIdx]->objectives->values->obj[i]->value = x[i]->value;
	}
	return true;
}//setObjectiveValuesSparse


bool OSResult::setObjectiveValuesDense(int solIdx, double *objectiveValues){
	int numberOfObj = this->getObjectiveNumber();
	int iNumberOfObjectives = numberOfObj;
	if(iNumberOfObjectives < 0) return false;
	if(iNumberOfObjectives == 0) return true;
	if(objectiveValues == NULL) return false;
	int nSols = this->getSolutionNumber();
	if(optimization == NULL) return false;
	if(nSols <= 0) return false;
	if(optimization == NULL) return false;
	if(optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if(optimization->solution[solIdx] == NULL){
		optimization->solution[solIdx] = new OptimizationSolution();
	}
	if(optimization->solution[solIdx]->objectives == NULL){
		optimization->solution[solIdx]->objectives = new ObjectiveSolution();
	}
	if(optimization->solution[solIdx]->objectives->values == NULL){
		optimization->solution[solIdx]->objectives->values = new ObjectiveValues();
	}
	optimization->solution[solIdx]->objectives->values->numberOfObj = iNumberOfObjectives;
	for(int i = 0; i < iNumberOfObjectives; i++){
		optimization->solution[solIdx]->objectives->values->obj.push_back( new ObjValue());
		optimization->solution[solIdx]->objectives->values->obj[i]->idx = -(i+1);
		optimization->solution[solIdx]->objectives->values->obj[i]->value = objectiveValues[i];
	}
	return true;
}//setObjectiveValuesDense


bool OSResult::setNumberOfDualVariableValues(int solIdx, int numberOfCon){
	int nSols = this->getSolutionNumber();
	int nCon  = this->getConstraintNumber();
	if (numberOfCon <= 0 || numberOfCon > nCon) return false;
	if(optimization == NULL) return false;
	if(nSols <= 0) return false;
	if(optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if(optimization->solution[solIdx] == NULL){
		optimization->solution[solIdx] = new OptimizationSolution();
	}
	if(optimization->solution[solIdx]->constraints == NULL){
		optimization->solution[solIdx]->constraints = new ConstraintSolution();
	}
	if(optimization->solution[solIdx]->constraints->dualValues == NULL){
		optimization->solution[solIdx]->constraints->dualValues = new DualVariableValues();
	}
	optimization->solution[solIdx]->constraints->dualValues->numberOfCon = numberOfCon;
//	optimization->solution[solIdx]->constraints->dualValues->con = new DualVarValue*[numberOfCon];

	return true;
}//setNumberOfDualVariableValues

   

bool OSResult::setDualVariableValuesSparse(int solIdx, std::vector<IndexValuePair*> x){
	int numberOfCon = x.size();
	int iNumberOfConstraints = numberOfCon;
	if(iNumberOfConstraints < 0) return false;
	if(iNumberOfConstraints == 0) return true;
	int nSols = this->getSolutionNumber();
	if(optimization == NULL) return false;
	if(nSols <= 0) return false;
	if(optimization == NULL) return false;
	if(optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if(optimization->solution[solIdx] == NULL){
		optimization->solution[solIdx] = new OptimizationSolution();
	}
	if(optimization->solution[solIdx]->constraints == NULL){
		optimization->solution[solIdx]->constraints = new ConstraintSolution();
	}
	if(optimization->solution[solIdx]->constraints->dualValues == NULL){
		optimization->solution[solIdx]->constraints->dualValues = new DualVariableValues();
	}
	if(x.size() == 0){
		optimization->solution[solIdx]->constraints->dualValues = NULL;
		return true;
	} 
	optimization->solution[solIdx]->constraints->dualValues->numberOfCon = numberOfCon;
	for(int i = 0; i < iNumberOfConstraints; i++){
		optimization->solution[solIdx]->constraints->dualValues->con.push_back( new DualVarValue());
		optimization->solution[solIdx]->constraints->dualValues->con[i]->idx = x[i]->idx;
		optimization->solution[solIdx]->constraints->dualValues->con[i]->value = x[i]->value;
	}
	return true;
}//setDualVariableValuesSparse

bool OSResult::setDualVariableValuesDense(int solIdx, double *y){
	int numberOfCon = this->getConstraintNumber();
	int iNumberOfConstraints = numberOfCon;
	if(iNumberOfConstraints < 0) return false;
	if(iNumberOfConstraints == 0) return true;
	int nSols = this->getSolutionNumber();
	if(optimization == NULL) return false;
	if(nSols <= 0) return false;
	if(optimization == NULL) return false;
	if(optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if(optimization->solution[solIdx] == NULL){
		optimization->solution[solIdx] = new OptimizationSolution();
	}
	if(optimization->solution[solIdx]->constraints == NULL){
		optimization->solution[solIdx]->constraints = new ConstraintSolution();
	}
	if(optimization->solution[solIdx]->constraints->dualValues == NULL){
		optimization->solution[solIdx]->constraints->dualValues = new DualVariableValues();
	}
	if(y == NULL){
		optimization->solution[solIdx]->constraints->dualValues = NULL;
		return true;
	} 
	optimization->solution[solIdx]->constraints->dualValues->numberOfCon = numberOfCon;
	for(int i = 0; i < iNumberOfConstraints; i++){
		optimization->solution[solIdx]->constraints->dualValues->con.push_back( new DualVarValue());
		optimization->solution[solIdx]->constraints->dualValues->con[i]->idx = i;
		optimization->solution[solIdx]->constraints->dualValues->con[i]->value = y[i];
	}
	return true;
}//setDualVariableValuesDense

bool OSResult::setConstraintValuesDense(int solIdx, double *dualVarValues){
	int numberOfCon = this->getConstraintNumber();
	int iNumberOfConstraints = numberOfCon;
	if(iNumberOfConstraints <= 0) return false;
	int nSols = this->getSolutionNumber();
	if(optimization == NULL) return false;
	if(nSols <= 0) return false;
	if(optimization == NULL) return false;
	if(optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if(optimization->solution[solIdx] == NULL){
		optimization->solution[solIdx] = new OptimizationSolution();
	}
	if(optimization->solution[solIdx]->constraints == NULL){
		optimization->solution[solIdx]->constraints = new ConstraintSolution();
	}
	if(optimization->solution[solIdx]->constraints->dualValues == NULL){
		optimization->solution[solIdx]->constraints->dualValues = new DualVariableValues();
	}
	if(dualVarValues == NULL){
		optimization->solution[solIdx]->constraints->dualValues = NULL;
		return true;
	}
	//optimization->solution[solIdx]->constraints->dualValues->con = new ConValue*[ iNumberOfConstraints];
	optimization->solution[solIdx]->constraints->dualValues->numberOfCon = numberOfCon;
	for(int i = 0; i < iNumberOfConstraints; i++){
		optimization->solution[solIdx]->constraints->dualValues->con.push_back( new DualVarValue());
		//optimization->solution[solIdx]->constraints->dualValues->con[i] = new ConValue();
		optimization->solution[solIdx]->constraints->dualValues->con[i]->idx = i;
		optimization->solution[solIdx]->constraints->dualValues->con[i]->value = dualVarValues[i];
	}
	return true;
}//setConstraintValuesDense


