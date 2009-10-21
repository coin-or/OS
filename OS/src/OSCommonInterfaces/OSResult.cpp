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

/**
 * ======== Constructor and destructor functions ========
 * (in the same order in which they appear in OSResult.h)
 */

GeneralSubstatus::GeneralSubstatus():
	name( ""),
	description( "")
{    
	#ifdef DEBUG_RESULT
	cout << "Inside the GeneralSubstatus Constructor" << endl;
	#endif
}// end GeneralSubstatus constructor  

GeneralSubstatus::~GeneralSubstatus(){
	#ifdef DEBUG_RESULT
	cout << "Inside the GeneralSubstatus Destructor" << endl;
	#endif
}//end GeneralSubstatus destructor


GeneralStatus::GeneralStatus():
	numberOfSubstatuses (0),
	type( ""),
	description( ""),
	substatus (NULL)
{    
	#ifdef DEBUG_RESULT
	cout << "Inside the GeneralStatus Constructor" << endl;
	#endif
}// end GeneralStatus constructor  

GeneralStatus::~GeneralStatus(){
	#ifdef DEBUG_RESULT
	cout << "Inside the GeneralStatus Destructor" << endl;
	#endif
	if (substatus != NULL)
	{	for (int i = 0; i < numberOfSubstatuses; i++)
		{
			delete substatus[i];
			substatus[i] = NULL;
		}
		delete[] substatus;
		substatus = NULL; 
	}
}//end GeneralStatus destructor


OtherResult::OtherResult():
	name( ""),
	value( ""),
	description( "")
{
	#ifdef DEBUG_RESULT
	cout << "Inside the OtherResult Constructor" << endl;
	#endif
}// end OtherResult constructor

OtherResult::~OtherResult()
{
	#ifdef DEBUG_RESULT
	cout << "Inside the OtherResult Destructor" << endl;
	#endif
}// end OtherResult destructor


OtherResults::OtherResults():
	numberOfOtherResults( 0),
	other( NULL)
{
	#ifdef DEBUG_RESULT
	cout << "Inside the OtherResults Constructor" << endl;
	#endif
}// end OtherResults constructor

OtherResults::~OtherResults()
{
	#ifdef DEBUG_RESULT
	cout << "Inside the OtherResults Destructor" << endl;
	#endif
	if (other != NULL)
	{	for (int i = 0; i < numberOfOtherResults; i++)
		{
			delete other[i];
			other[i] = NULL;
		}
		delete[] other;
		other = NULL; 
	}
}// end OtherResults destructor


GeneralResult::GeneralResult():
	generalStatus(NULL), 
	message(""),
	serviceURI(""),
	serviceName(""),
	instanceName(""),
	jobID(""),
	solverInvoked(""),
	timeStamp(""),
	otherResults(NULL)
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the GeneralResult Constructor" << endl;
	#endif
}//end GeneralResult constructor


GeneralResult::~GeneralResult(){
	#ifdef DEBUG_RESULT  
	cout << "GeneralResult Destructor Called" << endl;
	#endif
	if (generalStatus != NULL)
	{	delete generalStatus;
		generalStatus = NULL;
	}
	if (otherResults != NULL)
	{	delete otherResults;
		otherResults = NULL;
	}
}// end GeneralResult destructor


DiskSpace::DiskSpace():
	unit( "byte"),
	description( ""),
	value( 0.0)
{
	#ifdef DEBUG_RESULT
	cout << "Inside the DiskSpace Constructor" << endl;
	#endif
}// end DiskSpace constructor

DiskSpace::~DiskSpace()
{
	#ifdef DEBUG_RESULT
	cout << "Inside the DiskSpace Destructor" << endl;
	#endif
}// end DiskSpace destructor



MemorySize::MemorySize():
	unit( "byte"),
	description( ""),
	value( 0.0)
{
	#ifdef DEBUG_RESULT
	cout << "Inside the MemorySize Constructor" << endl;
	#endif
}// end MemorySize constructor

MemorySize::~MemorySize()
{
	#ifdef DEBUG_RESULT
	cout << "Inside the MemorySize Destructor" << endl;
	#endif
}// end MemorySize destructor


CPUSpeed::CPUSpeed():
	unit( "hertz"),
	description( ""),
	value( 0.0)
{
	#ifdef DEBUG_RESULT
	cout << "Inside the CPUSpeed Constructor" << endl;
	#endif
}// end CPUSpeed constructor

CPUSpeed::~CPUSpeed()
{
	#ifdef DEBUG_RESULT
	cout << "Inside the CPUSpeed Destructor" << endl;
	#endif
}// end CPUSpeed destructor


CPUNumber::CPUNumber():
	description( ""),
	value( 1)
{
	#ifdef DEBUG_RESULT
	cout << "Inside the CPUNumber Constructor" << endl;
	#endif
}// end CPUNumber constructor

CPUNumber::~CPUNumber()
{
	#ifdef DEBUG_RESULT
	cout << "Inside the CPUNumber Destructor" << endl;
	#endif
}// end CPUNumber destructor


SystemResult::SystemResult():
	systemInformation(""),
	availableDiskSpace(NULL),
	availableMemory(NULL),
	availableCPUSpeed(NULL),
	availableCPUNumber(NULL),
	otherResults(NULL)
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the SystemResult Constructor" << endl;
	#endif
}//end SystemResult constructor


SystemResult::~SystemResult(){
	#ifdef DEBUG_RESULT  
	cout << "SystemResult Destructor Called" << endl;
	#endif
	if (availableDiskSpace != NULL)
	{	delete availableDiskSpace;
		availableDiskSpace = NULL;
	}
	if (availableMemory != NULL)
	{	delete availableMemory;
		availableMemory = NULL;
	}
	if (availableCPUSpeed != NULL)
	{	delete availableCPUSpeed;
		availableCPUSpeed = NULL;
	}
	if (availableCPUNumber != NULL)
	{	delete availableCPUNumber;
		availableCPUNumber = NULL;
	}
	if (otherResults != NULL)
	{	delete otherResults;
		otherResults = NULL;
	}
}// end SystemResult destructor


ServiceResult::ServiceResult():
	currentState("noResponse"),
	currentJobCount(-1),
	totalJobsSoFar(-1),
	timeServiceStarted("1970-01-01T00:00:00-00:00"),
	serviceUtilization(-1.0),
	otherResults(NULL)
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the ServiceResult Constructor" << endl;
	#endif
}//end ServiceResult constructor


ServiceResult::~ServiceResult(){
	#ifdef DEBUG_RESULT  
	cout << "ServiceResult Destructor Called" << endl;
	#endif
	if (otherResults != NULL)
	{	delete otherResults;
		otherResults = NULL;
	}
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

}// end Time destructor


TimingInformation::TimingInformation():
	numberOfTimes(0),
	time(NULL)
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the TimingInformation Constructor" << endl;
	#endif
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
		delete[] time;
		time = NULL;
	}
}// end TimingInformation destructor

JobResult::JobResult():
	status("finished"),
	submitTime("1970-01-01T00:00:00-00:00"),
	scheduledStartTime("1970-01-01T00:00:00-00:00"),
	actualStartTime("1970-01-01T00:00:00-00:00"),
	endTime("1970-01-01T00:00:00-00:00"),
	timingInformation(NULL),
	usedCPUSpeed(NULL),
	usedCPUNumber(NULL),
	usedDiskSpace(NULL),
	usedMemory(NULL),
      otherResults(NULL)
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
	if (timingInformation != NULL)
	{	delete timingInformation;
		timingInformation = NULL;
	}
	if (usedCPUSpeed != NULL)
	{	delete usedCPUSpeed;
		usedCPUSpeed = NULL;
	}
	if (usedCPUNumber != NULL)
	{	delete usedCPUNumber;
		usedCPUNumber = NULL;
	}
	if (usedDiskSpace != NULL)
	{	delete usedDiskSpace;
		usedDiskSpace = NULL;
	}
	if (usedMemory != NULL)
	{	delete usedMemory;
		usedMemory = NULL;
	}
	if (otherResults != NULL)
	{	delete otherResults;
		otherResults = NULL;
	}
}// end JobResult destructor


OptimizationSolutionSubstatus::OptimizationSolutionSubstatus():
	type(""),
	description("")
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the OptimizationSolutionSubstatus Constructor" << endl;
	#endif
}//end OptimizationSolutionSubstatus constructor


OptimizationSolutionSubstatus::~OptimizationSolutionSubstatus(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the OptimizationSolutionSubstatus Destructor" << endl;
	#endif
}// end OptimizationSolutionSubstatus destructor


OptimizationSolutionStatus::OptimizationSolutionStatus():
	numberOfSubstatuses(0),
	type(""),
	description(""),
	substatus(NULL)
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the OptimizationSolutionStatus Constructor" << endl;
	#endif
}//end OptimizationSolutionStatus constructor


OptimizationSolutionStatus::~OptimizationSolutionStatus(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the OptimizationSolutionStatus Destructor" << endl;
	#endif
	if (substatus != NULL)
	{
		for (int i = 0; i < numberOfSubstatuses; i++)
		{	delete substatus[i];
			substatus[i] = NULL;
		}
		delete[] substatus;
		substatus = NULL;
	}
}// end OptimizationSolutionStatus destructor


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



VariableValues::VariableValues():
	numberOfVar(0),
	var(NULL) 
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the VariableValues Constructor" << endl;
	#endif
}//end VariableValues constructor


VariableValues::~VariableValues(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the VariableValues Destructor" << endl;
	#endif
	if(var != NULL)
	{	for(int i = 0; i < numberOfVar; i++)
		{
			delete var[i];
			var[i] = NULL;
		}
		delete[] var;
		var = NULL;
	}
}// end VariableValues destructor 


VarValueString::VarValueString():
	idx( -1),
	value( "")
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the VarValueString Constructor" << endl;
	#endif
}//end VarValueString constructor


VarValueString::~VarValueString(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the VarValueString Destructor" << endl;
	#endif
}// end VarValueString destructor 



VariableValuesString::VariableValuesString():
	numberOfVar(0),
	var(NULL) 
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the VariableValuesString Constructor" << endl;
	#endif
}//end VariableValuesString constructor


VariableValuesString::~VariableValuesString(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the VariableValuesString Destructor" << endl;
	#endif
	if(var != NULL)
	{	for(int i = 0; i < numberOfVar; i++)
		{
			delete var[i];
			var[i] = NULL;
		}
		delete[] var;
		var = NULL;
	}
}// end VariableValuesString destructor 


BasStatus::BasStatus():
	idx( -1),
	value( "")
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the BasStatus Constructor" << endl;
	#endif
}//end BasStatus constructor


BasStatus::~BasStatus(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the BasStatus Destructor" << endl;
	#endif
}// end BasStatus destructor 



BasisStatus::BasisStatus():
	numberOfVar(0),
	var(NULL) 
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the BasisStatus Constructor" << endl;
	#endif
}//end BasisStatus constructor


BasisStatus::~BasisStatus(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the BasisStatus Destructor" << endl;
	#endif
	if(var != NULL)
	{	for(int i = 0; i < numberOfVar; i++)
		{
			delete var[i];
			var[i] = NULL;
		}
		delete[] var;
		var = NULL;
	}
}// end BasisStatus destructor 


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



OtherVariableResult::OtherVariableResult():
	numberOfVar(0),    //(-1),
	value(""),
	name(""),
	description(""),
	var(NULL)
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the OtherVariableResult Constructor" << endl;
	#endif

}//end OtherVariableResult constructor


OtherVariableResult::~OtherVariableResult(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the OtherVariableResult Destructor" << endl;
	#endif
	if (var != NULL)
	{	for(int i = 0; i < numberOfVar; i++){
			delete var[i];
			var[i] = NULL;
		}
		delete[] var;
		var = NULL;
	}
	#ifdef DEBUG_RESULT  
	cout << "Inside the OtherVariableResult Destructor - Done" << endl;
	#endif
}// end OtherVariableResult destructor 


VariableSolution::VariableSolution():
	numberOfOtherVariableResults( 0),
	values( NULL),
	valuesString( NULL),
	basisStatus(NULL),
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
	if (values != NULL)
	{	delete values;
		values = NULL;
	}
	if (valuesString != NULL)
	{	delete valuesString;
		valuesString = NULL;
	}
	if (basisStatus != NULL)
	{	delete basisStatus;
		basisStatus = NULL;
	}
	if(numberOfOtherVariableResults > 0 && other != NULL){
		for(int i = 0; i < numberOfOtherVariableResults; i++){
			delete other[i];
			other[i] = NULL;
		}
		delete[] other;
		other = NULL; 
	}
}// end VariableSolution destructor 



ObjValue::ObjValue():
	idx( -1),
	value(0.0)
//	value( OSNAN)
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



ObjectiveValues::ObjectiveValues():
	numberOfObj(0),
	obj(NULL)
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the ObjectiveValues Constructor" << endl;
	#endif

}//end ObjectiveValues constructor


ObjectiveValues::~ObjectiveValues(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the ObjectiveValues Destructor" << endl;
	#endif
	if((obj != NULL) && (numberOfObj > 0) ){
		for(int i = 0; i < numberOfObj; i++){
			delete obj[i];
			obj[i] = NULL;
		}
		delete[] obj; 
		obj = NULL;
	}
}// end ObjectiveValues destructor


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


OtherObjectiveResult::OtherObjectiveResult():
	numberOfObj(1),
	name(""),
	value(""),
	description(""),
	obj(NULL)
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the OtherObjectiveResult Constructor" << endl;
	#endif
}//end OtherObjectiveResult constructor


OtherObjectiveResult::~OtherObjectiveResult(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the OtherObjectiveResult Destructor" << endl;
	#endif
	if(obj != NULL) {
		for(int i = 0; i < numberOfObj; i++){
			delete obj[i];
			obj[i] = NULL;
		}
		delete[] obj; 
		obj = NULL;
	}
}// end OtherObjectiveResult destructor


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
	if (values != NULL)
	{	delete  values;
		values = NULL;
	}
	if(numberOfOtherObjectiveResults > 0 && other != NULL){
		for(int i = 0; i < numberOfOtherObjectiveResults; i++){
			delete other[i];
			other[i] = NULL;
		}
		delete[] other;
		other = NULL; 
	}
}// end ObjectiveSolution destructor 


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


DualVariableValues::DualVariableValues(): 
	numberOfCon(0),
	con(NULL)
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the DualVariableValues Constructor" << endl;
	#endif

}//end DualVariableValues constructor


DualVariableValues::~DualVariableValues(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the DualVariableValues Destructor" << endl;
	#endif
	if (con != NULL){
		for(int i = 0; i < numberOfCon; i++){
			delete con[i];
			con[i] = NULL;
		}
		delete[] con;
		con = NULL;
	}	
}// end DualVariableValues destructor 


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



OtherConstraintResult::OtherConstraintResult():
	numberOfCon(0),
	name(""),
	value(""),
	description(""),
	con(NULL)
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the OtherConstraintResult Constructor" << endl;
	#endif
}//end OtherConstraintResult constructor


OtherConstraintResult::~OtherConstraintResult(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the OtherConstraintResult Destructor" << endl;
	#endif
	if (con != NULL){
		for(int i = 0; i < numberOfCon; i++){
			delete con[i];
			con[i] = NULL;
		}
		delete[] con;
		con = NULL;
	}
}// end OtherConstraintResult destructor



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
	if (dualValues != NULL)
	{	delete  dualValues;
		dualValues = NULL;
	}
	if(numberOfOtherConstraintResults > 0 && other != NULL){
		for(int i = 0; i < numberOfOtherConstraintResults; i++){
			delete other[i];
			other[i] = NULL;
		}
		delete[] other;
		other = NULL; 
	}
}// end ConstraintSolution destructor



OtherSolutionResult::OtherSolutionResult():
	name( ""),
	category (""),
	description (""),
	numberOfItems (0),
	item( NULL)
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the OtherSolutionResult Constructor" << endl;
	#endif
}//end OtherSolutionResult constructor


OtherSolutionResult::~OtherSolutionResult(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the OtherSolutionResult Destructor" << endl;
	#endif
	if (item != NULL) 
	{	//for (int i=0; i < numberOfItems; i++)
		//{	delete item[i];
		//	item[i] = NULL;
		//}
		delete[] item;
		item = NULL;
	}
}// end OtherSolutionResult destructor



OtherSolutionResults::OtherSolutionResults():
	numberOfOtherSolutionResults( 0),
	otherSolutionResult( NULL)
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the OtherSolutionResults Constructor" << endl;
	#endif
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
		delete[] otherSolutionResult;
		otherSolutionResult = NULL; 
	}
}// end OtherSolutionResults destructor



OptimizationSolution::OptimizationSolution():
	targetObjectiveIdx( -1),
	weightedObjectives(false),
	status(NULL),
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
}//end OptimizationSolution constructor


OptimizationSolution::~OptimizationSolution(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the OptimzationSolution Destructor" << endl;
	#endif
	if(status != NULL){
		delete status;
		status = NULL;
	}
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
	if(otherSolutionResults != NULL){
		delete otherSolutionResults;
		otherSolutionResults = NULL;
	}
}// end OptimizationSolution destructor 
 

SolverOutput::SolverOutput():
	name( ""),
	category (""),
	description (""),
	numberOfItems (0),
	item( NULL)
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the SolverOutput Constructor" << endl;
	#endif
}//end SolverOutput constructor


SolverOutput::~SolverOutput(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the SolverOutput Destructor" << endl;
	#endif
	if (item != NULL) 
	{	//for (int i=0; i < numberOfItems; i++)
		//{	delete item[i];
		//	item[i] = NULL;
		//}
		delete[] item;
		item = NULL;
	}
}// end SolverOutput destructor



OtherSolverOutput::OtherSolverOutput(): 
	numberOfSolverOutputs(0),
	solverOutput(NULL)
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the OtherSolverOutput Constructor" << endl;
	#endif

}//end OtherSolverOutput constructor


OtherSolverOutput::~OtherSolverOutput(){
	#ifdef DEBUG_RESULT  
	cout << "Inside the OtherSolverOutput Destructor" << endl;
	#endif
	if (solverOutput != NULL){
		for(int i = 0; i < numberOfSolverOutputs; i++){
			delete solverOutput[i];
			solverOutput[i] = NULL;
		}
		delete[] solverOutput;
		solverOutput = NULL;
	}	
}// end OtherSolverOutput destructor 



OptimizationResult::OptimizationResult():
	numberOfVariables( -1),
	numberOfObjectives( -1),
	numberOfConstraints(-1),
	numberOfSolutions( -1),
	solution(NULL),
	otherSolverOutput(NULL)
{ 
	#ifdef DEBUG_RESULT
	cout << "Inside the OptimizationResult Constructor" << endl;
	#endif
}//end OptimizationResult constructor


OptimizationResult::~OptimizationResult(){
	#ifdef DEBUG_RESULT  
	cout << "OptimizationResult Destructor Called" << endl;
	#endif
	if( solution != NULL){
		for(int i = 0; i < this->numberOfSolutions; i++){
			delete solution[i];
			solution[i] = NULL;
			#ifdef DEBUG_RESULT  
			cout << "Deleting Solution: " << i << endl;
			#endif
		}
		delete[] solution;
		solution = NULL; 
	}
}// end OptimizationResult destructor 
 

OSResult::OSResult():
	m_iVariableNumber( -1),
	m_iObjectiveNumber( -1),
	m_iConstraintNumber( -1),
	m_iNumberOfOtherVariableResults( -1),
	m_mdPrimalValues( NULL),
	m_mdDualValues( NULL)

{    
	#ifdef DEBUG_RESULT
	cout << "Inside the OSResult Constructor" << endl;
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



// =============================================================
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
			numberOfVar = optimization->solution[i]->variables->values->numberOfVar;	
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
			numberOfCon = optimization->solution[i]->constraints->dualValues->numberOfCon;	
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
	if (general->generalStatus == NULL) general->generalStatus = new GeneralStatus();
	general->generalStatus->type = type;
	return true;
}//setGeneralStatusType

bool OSResult::setGeneralStatusDescription(string description){
	if(general->generalStatus == NULL) general->generalStatus = new GeneralStatus();
	general->generalStatus->description = description;
	return true;
}//setGeneralStatusDescription

bool OSResult::setNumberOfGeneralSubstatuses(int num){
	if(general->generalStatus == NULL) general->generalStatus = new GeneralStatus();
//	if (general->generalStatus->numberOfSubstatuses > 0)
//	{	throw ErrorClass("Attempting to reallocate substatus array. Potential loss of data.");
//		return false;
//	}
	general->generalStatus->numberOfSubstatuses = num;
	if (num > 0)
	{	general->generalStatus->substatus = new GeneralSubstatus*[num];
		for(int i = 0; i < num; i++) 	
			general->generalStatus->substatus[i] = new GeneralSubstatus();
	}
	return true;
}//setNumberOfGeneralSubstatuses

bool OSResult::setGeneralSubstatusName(int idx, string name){
	if (general->generalStatus == NULL) return false;
	if (idx < 0 || idx >= general->generalStatus->numberOfSubstatuses) return false;
	general->generalStatus->substatus[idx]->name = name;
	return true;
}//setGeneralSubstatusName

bool OSResult::setGeneralSubstatusDescription(int idx, string description){
	if (general->generalStatus == NULL) return false;
	if (idx < 0 || idx >= general->generalStatus->numberOfSubstatuses) return false;
	general->generalStatus->substatus[idx]->description = description;
	return true;
}//setGeneralSubstatusDescription

bool OSResult::setGeneralMessage(string message){
	general->message = message;
	return true;
}//setGeneralMessage

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

bool OSResult::setSolverInvoked(string solverInvoked){
	general->solverInvoked = solverInvoked;
	return true;
}//setSolverInvoked
		
bool OSResult::setTimeStamp(string timeStamp){
	general->timeStamp = timeStamp;
	return true;
}//setTimeStamp

bool OSResult::setNumberOfOtherGeneralResults(int num){
	if(general->otherResults == NULL) general->otherResults = new OtherResults();
	general->otherResults->numberOfOtherResults = num;
//	if (general->otherResults->other != NULL)
//	{	throw ErrorClass("Attempting to reallocate other general results array. Potential loss of data.");
//		return false;
//	}
	if (num > 0)
	{	general->otherResults->other = new OtherResult*[num];
		for(int i = 0; i < num; i++) 	
			general->otherResults->other[i] = new OtherResult();
	}
	return true;
}//setNumberOfOtherGeneralResults


bool OSResult::setGeneralOtherResultName(int idx, string name){
	if (general->otherResults == NULL) return false;
	if (idx < 0 || idx >= general->otherResults->numberOfOtherResults) 
	{	throw ErrorClass("Attempting to access other general result outside of array boundaries.");
		return false;
	}
	general->otherResults->other[idx]->name = name;
	return true;
}//setGeneralOtherResultName

bool OSResult::setGeneralOtherResultValue(int idx, string value){
	if (general->otherResults == NULL) return false;
	if (idx < 0 || idx >= general->otherResults->numberOfOtherResults) 
	{	throw ErrorClass("Attempting to access other general result outside of array boundaries.");
		return false;
	}
	general->otherResults->other[idx]->value = value;
	return true;
}//setGeneralOtherResultValue

bool OSResult::setGeneralOtherResultDescription(int idx, string description){
	if (general->otherResults == NULL) return false;
	if (idx < 0 || idx >= general->otherResults->numberOfOtherResults) 
	{	throw ErrorClass("Attempting to access other general result outside of array boundaries.");
		return false;
	}
	general->otherResults->other[idx]->description = description;
	return true;
}//setGeneralOtherResultDescription

bool OSResult::setSystemInformation(string systemInformation){
	system->systemInformation = systemInformation;
	return true;
}//setServiceName

bool OSResult::setAvailableDiskSpaceUnit(std::string unit)
{	if (system->availableDiskSpace == NULL) system->availableDiskSpace = new DiskSpace();
	system->availableDiskSpace->unit = unit;
	return true;
}//setAvailableDiskSpaceUnit

bool OSResult::setAvailableDiskSpaceDescription(std::string description)
{	if (system->availableDiskSpace == NULL) system->availableDiskSpace = new DiskSpace();
	system->availableDiskSpace->description = description;
	return true;
}//setAvailableDiskSpaceDescription

bool OSResult::setAvailableDiskSpaceValue(double value)
{	if (system->availableDiskSpace == NULL) system->availableDiskSpace = new DiskSpace();
	system->availableDiskSpace->value = value;
	return true;
}//setAvailableDiskSpaceValue

bool OSResult::setAvailableMemoryUnit(std::string unit)
{	if (system->availableMemory == NULL) system->availableMemory = new MemorySize();
	system->availableMemory->unit = unit;
	return true;
}//setAvailableMemoryUnit

bool OSResult::setAvailableMemoryDescription(std::string description)
{	if (system->availableMemory == NULL) system->availableMemory = new MemorySize();
	system->availableMemory->description = description;
	return true;
}//setAvailableMemoryDescription

bool OSResult::setAvailableMemoryValue(double value)
{	if (system->availableMemory == NULL) system->availableMemory = new MemorySize();
	system->availableMemory->value = value;
	return true;
}//setAvailableMemoryValue

bool OSResult::setAvailableCPUSpeedUnit(std::string unit)
{	if (system->availableCPUSpeed == NULL) system->availableCPUSpeed = new CPUSpeed();
	system->availableCPUSpeed->unit = unit;
	return true;
}//setAvailableCPUSpeedUnit

bool OSResult::setAvailableCPUSpeedDescription(std::string description)
{	if (system->availableCPUSpeed == NULL) system->availableCPUSpeed = new CPUSpeed();
	system->availableCPUSpeed->description = description;
	return true;
}//setAvailableCPUSpeedDescription

bool OSResult::setAvailableCPUSpeedValue(double value)
{	if (system->availableCPUSpeed == NULL) system->availableCPUSpeed = new CPUSpeed();
	system->availableCPUSpeed->value = value;
	return true;
}//setAvailableCPUSpeedValue

bool OSResult::setAvailableCPUNumberDescription(std::string description)
{	if (system->availableCPUNumber == NULL) system->availableCPUNumber = new CPUNumber();
	system->availableCPUNumber->description = description;
	return true;
}//setAvailableCPUNumberDescription

bool OSResult::setAvailableCPUNumberValue(int value)
{	if (system->availableCPUNumber == NULL) system->availableCPUNumber = new CPUNumber();
	system->availableCPUNumber->value = value;
	return true;
}//setAvailableCPUNumberValue

bool OSResult::setNumberOfOtherSystemResults(int num){
	if(system->otherResults == NULL) system->otherResults = new OtherResults();
	system->otherResults->numberOfOtherResults = num;
//	if (system->otherResults->other != NULL)
//	{	throw ErrorClass("Attempting to reallocate other system results array. Potential loss of data.");
//		return false;
//	}
	if (num > 0)
	{	system->otherResults->other = new OtherResult*[num];
		for(int i = 0; i < num; i++) 	
			system->otherResults->other[i] = new OtherResult();
	}
	return true;
}//setNumberOfOtherSystemResults


bool OSResult::setSystemOtherResultName(int idx, string name){
	if (system->otherResults == NULL) return false;
	if (idx < 0 || idx >= system->otherResults->numberOfOtherResults) 
	{//	throw ErrorClass("Attempting to access other system result outside of array boundaries.");
		return false;
	}
	system->otherResults->other[idx]->name = name;
	return true;
}//setSystemOtherResultName

bool OSResult::setSystemOtherResultValue(int idx, string value){
	if (system->otherResults == NULL) return false;
	if (idx < 0 || idx >= system->otherResults->numberOfOtherResults) 
	{//	throw ErrorClass("Attempting to access other system result outside of array boundaries.");
		return false;
	}
	system->otherResults->other[idx]->value = value;
	return true;
}//setSystemOtherResultValue

bool OSResult::setSystemOtherResultDescription(int idx, string description){
	if (system->otherResults == NULL) return false;
	if (idx < 0 || idx >= system->otherResults->numberOfOtherResults) 
	{//	throw ErrorClass("Attempting to access other system result outside of array boundaries.");
		return false;
	}
	system->otherResults->other[idx]->description = description;
	return true;
}//setSystemOtherResultDescription

bool OSResult::setCurrentState(std::string currentState){
	service->currentState = currentState;
	return true;
}//setCurrentState

bool OSResult::setCurrentJobCount(int jobCount){
	service->currentJobCount = jobCount;
	return true;
}//setCurrentJobCount

bool OSResult::setTotalJobsSoFar(int number){
	service->totalJobsSoFar = number;
	return true;
}//setTotalJobsSoFar

bool OSResult::setTimeServiceStarted(std::string startTime){
	service->timeServiceStarted = startTime;
	return true;
}//setTimeServiceStarted

bool OSResult::setServiceUtilization(double value){
	service->serviceUtilization = value;
	return true;
}//setServiceUtilization

bool OSResult::setNumberOfOtherServiceResults(int num){
	if(service->otherResults == NULL) service->otherResults = new OtherResults();
	service->otherResults->numberOfOtherResults = num;
	if (service->otherResults->other != NULL)
	{//	throw ErrorClass("Attempting to reallocate other service results array. Potential loss of data.");
		return false;
	}
	if (num > 0)
	{	service->otherResults->other = new OtherResult*[num];
		for(int i = 0; i < num; i++) 	
			service->otherResults->other[i] = new OtherResult();
	}
	return true;
}//setNumberOfOtherServiceResults

bool OSResult::setServiceOtherResultName(int idx, string name){
	if (service->otherResults == NULL) return false;
	if (idx < 0 || idx >= service->otherResults->numberOfOtherResults) 
	{//	throw ErrorClass("Attempting to access other service result outside of array boundaries.");
		return false;
	}
	service->otherResults->other[idx]->name = name;
	return true;
}//setServiceOtherResultName

bool OSResult::setServiceOtherResultValue(int idx, string value){
	if (service->otherResults == NULL) return false;
	if (idx < 0 || idx >= service->otherResults->numberOfOtherResults) 
	{//	throw ErrorClass("Attempting to access other service result outside of array boundaries.");
		return false;
	}
	service->otherResults->other[idx]->value = value;
	return true;
}//setServiceOtherResultValue

bool OSResult::setServiceOtherResultDescription(int idx, string description){
	if (service->otherResults == NULL) return false;
	if (idx < 0 || idx >= service->otherResults->numberOfOtherResults) 
	{//	throw ErrorClass("Attempting to access other service result outside of array boundaries.");
		return false;
	}
	service->otherResults->other[idx]->description = description;
	return true;
}//setServiceOtherResultDescription

bool OSResult::setJobStatus(std::string status){
	job->status = status;
	return true;
}//setJobStatus
	
bool OSResult::setJobSubmitTime(std::string submitTime){
	job->submitTime = submitTime;
	return true;
}//setJobSubmitTime
	
bool OSResult::setScheduledStartTime(std::string scheduledStartTime){
	job->scheduledStartTime = scheduledStartTime;
	return true;
}//setScheduledStartTime
	
bool OSResult::setActualStartTime(std::string actualStartTime){
	job->actualStartTime = actualStartTime;
	return true;
}//setActualStartTime
	
bool OSResult::setJobEndTime(std::string endTime){
	job->endTime = endTime;
	return true;
}//setJobEndTime

bool OSResult::setTime(double time){
//	general->time = os_dtoa_format( time);
    return addTimingInformation("elapsedTime", "total", "second", "", time);
}//setTime

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


bool OSResult::setTimeNumber(int timeNumber)
{	if (job == NULL) 
	{//	throw ErrorClass("job instance was never defined");
		return false;
	}
	if (job->timingInformation == NULL) job->timingInformation = new TimingInformation();
    if (timeNumber <= 0) return false;
	job->timingInformation->numberOfTimes = timeNumber;
	return true;
}//setTimeNumber

bool OSResult::setUsedDiskSpaceUnit(std::string unit)
{	if (job == NULL) 
	{//	throw ErrorClass("job instance was never defined");
		return false;
	}
	if (job->usedDiskSpace == NULL) job->usedDiskSpace = new DiskSpace();
	job->usedDiskSpace->unit = unit;
	return true;
}//setUsedDiskSpaceUnit

bool OSResult::setUsedDiskSpaceDescription(std::string description)
{	if (job == NULL) 
	{//	throw ErrorClass("job instance was never defined");
		return false;
	}
	if (job->usedDiskSpace == NULL) job->usedDiskSpace = new DiskSpace();
	job->usedDiskSpace->description = description;
	return true;
}//setUsedDiskSpaceDescription

bool OSResult::setUsedDiskSpaceValue(double value)
{	if (job == NULL) 
	{//	throw ErrorClass("job instance was never defined");
		return false;
	}
	if (job->usedDiskSpace == NULL) job->usedDiskSpace = new DiskSpace();
	job->usedDiskSpace->value = value;
	return true;
}//setUsedDiskSpaceValue

bool OSResult::setUsedMemoryUnit(std::string unit)
{	if (job == NULL) 
	{//	throw ErrorClass("job instance was never defined");
		return false;
	}
	if (job->usedMemory == NULL) job->usedMemory = new MemorySize();
	job->usedMemory->unit = unit;
	return true;
}//setUsedMemoryUnit

bool OSResult::setUsedMemoryDescription(std::string description)
{	if (job == NULL) 
	{//	throw ErrorClass("job instance was never defined");
		return false;
	}
	if (job->usedMemory == NULL) job->usedMemory = new MemorySize();
	job->usedMemory->description = description;
	return true;
}//setUsedMemoryDescription

bool OSResult::setUsedMemoryValue(double value)
{	if (job == NULL) 
	{//	throw ErrorClass("job instance was never defined");
		return false;
	}
	if (job->usedMemory == NULL) job->usedMemory = new MemorySize();
	job->usedMemory->value = value;
	return true;
}//setUsedMemoryValue

bool OSResult::setUsedCPUSpeedUnit(std::string unit)
{	if (job == NULL) 
	{//	throw ErrorClass("job instance was never defined");
		return false;
	}
	if (job->usedCPUSpeed == NULL) job->usedCPUSpeed = new CPUSpeed();
	job->usedCPUSpeed->unit = unit;
	return true;
}//setUsedCPUSpeedUnit

bool OSResult::setUsedCPUSpeedDescription(std::string description)
{	if (job == NULL) 
	{//	throw ErrorClass("job instance was never defined");
		return false;
	}
	if (job->usedCPUSpeed == NULL) job->usedCPUSpeed = new CPUSpeed();
	job->usedCPUSpeed->description = description;
	return true;
}//setUsedCPUSpeedDescription

bool OSResult::setUsedCPUSpeedValue(double value)
{	if (job == NULL) 
	{//	throw ErrorClass("job instance was never defined");
		return false;
	}
	if (job->usedCPUSpeed == NULL) job->usedCPUSpeed = new CPUSpeed();
	job->usedCPUSpeed->value = value;
	return true;
}//setUsedCPUSpeedValue

bool OSResult::setUsedCPUNumberDescription(std::string description)
{	if (job == NULL) 
	{//	throw ErrorClass("job instance was never defined");
		return false;
	}
	if (job->usedCPUNumber == NULL) job->usedCPUNumber = new CPUNumber();
	job->usedCPUNumber->description = description;
	return true;
}//setUsedCPUNumberDescription

bool OSResult::setUsedCPUNumberValue(int value)
{	if (job == NULL) 
	{//	throw ErrorClass("job instance was never defined");
		return false;
	}
	if (job->usedCPUNumber == NULL) job->usedCPUNumber = new CPUNumber();
	job->usedCPUNumber->value = value;
	return true;
}//setUsedCPUNumberValue

bool OSResult::setNumberOfOtherJobResults(int num){
	if (job == NULL) 
	{//	throw ErrorClass("job instance was never defined");
		return false;
	}
	if(job->otherResults == NULL) job->otherResults = new OtherResults();
	job->otherResults->numberOfOtherResults = num;
	if (job->otherResults->other != NULL)
	{//	throw ErrorClass("Attempting to reallocate other job results array. Potential loss of data.");
		return false;
	}
	if (num > 0)
	{	job->otherResults->other = new OtherResult*[num];
		for(int i = 0; i < num; i++) 	
			job->otherResults->other[i] = new OtherResult();
	}
	return true;
}//setNumberOfOtherJobResults


bool OSResult::setJobOtherResultName(int idx, string name){
	if (job == NULL) 
	{//	throw ErrorClass("job instance was never defined");
		return false;
	}
	if (job->otherResults == NULL) return false;
	if (idx < 0 || idx >= job->otherResults->numberOfOtherResults) 
	{//	throw ErrorClass("Attempting to access other job result outside of array boundaries.");
		return false;
	}
	job->otherResults->other[idx]->name = name;
	return true;
}//setJobOtherResultName

bool OSResult::setJobOtherResultValue(int idx, string value){
	if (job == NULL) 
	{//	throw ErrorClass("job instance was never defined");
		return false;
	}
	if (job->otherResults == NULL) return false;
	if (idx < 0 || idx >= job->otherResults->numberOfOtherResults) 
	{//	throw ErrorClass("Attempting to access other job result outside of array boundaries.");
		return false;
	}
	job->otherResults->other[idx]->value = value;
	return true;
}//setJobOtherResultValue

bool OSResult::setJobOtherResultDescription(int idx, string description){
	if (job == NULL) 
	{//	throw ErrorClass("job instance was never defined");
		return false;
	}
	if (job->otherResults == NULL) return false;
	if (idx < 0 || idx >= job->otherResults->numberOfOtherResults) 
	{//	throw ErrorClass("Attempting to access other job result outside of array boundaries.");
		return false;
	}
	job->otherResults->other[idx]->description = description;
	return true;
}//setJobOtherResultDescription




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


bool OSResult::setSolutionStatusType(int solIdx, std::string type){	
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
	return true;
}//setSolutionStatusType

bool OSResult::setSolutionStatusDescription(int solIdx, std::string description){
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
	optimization->solution[solIdx]->status->description = description;
	return true;
}//setSolutionStatusDescription


bool OSResult::setNumberOfSolutionSubstatuses(int solIdx, int num){
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
	optimization->solution[solIdx]->status->numberOfSubstatuses = num;
	optimization->solution[solIdx]->status->substatus = new OptimizationSolutionSubstatus*[num];
	for(int i = 0; i < num; i++){
		optimization->solution[solIdx]->status->substatus[i] = new OptimizationSolutionSubstatus();
	}
	return true;
}//setNumberOfSolutionSubstatuses


bool OSResult::setSolutionSubstatusType(int solIdx, int substatusIdx, std::string type){
	int nSols = this->getSolutionNumber();
	if(optimization == NULL) return false;
	if(optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if(optimization->solution[solIdx] == NULL) return false;
	if(optimization->solution[solIdx]->status == NULL) return false;
	int nSubs = optimization->solution[solIdx]->status->numberOfSubstatuses;
	if (substatusIdx < 0 || substatusIdx >= nSubs) return false;
	optimization->solution[solIdx]->status->substatus[substatusIdx]->type = type;
	return true;
}//setSolutionSubstatusType
	
bool OSResult::setSolutionSubstatusDescription(int solIdx, int substatusIdx, std::string description){
	int nSols = this->getSolutionNumber();
	if(optimization == NULL) return false;
	if(optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if(optimization->solution[solIdx] == NULL) return false;
	if(optimization->solution[solIdx]->status == NULL) return false;
	int nSubs = optimization->solution[solIdx]->status->numberOfSubstatuses;
	if (substatusIdx < 0 || substatusIdx >= nSubs) return false;
	optimization->solution[solIdx]->status->substatus[substatusIdx]->description = description;
	return true;
}//setSolutionSubstatusDescription


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

bool OSResult::setSolutionWeightedObjectives(int solIdx, std::string weightedObjectives){
	int nSols = this->getSolutionNumber();
	if (optimization == NULL) return false;
	if (nSols <= 0) return false;
	if (optimization == NULL) return false;
	if (optimization->solution == NULL || 
		solIdx < 0 || solIdx >=  nSols) return false;
	if (optimization->solution[solIdx] == NULL)
		optimization->solution[solIdx] = new OptimizationSolution();
	if (weightedObjectives == "true")
		optimization->solution[solIdx]->weightedObjectives = true;
	else
		optimization->solution[solIdx]->weightedObjectives = false;
	return true;		
}//setSolutionWeightedObjectives



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
	optimization->solution[solIdx]->variables->values->var = new VarValue*[numberOfVar];

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
	if (optimization->solution[solIdx]->variables->values == NULL){
		optimization->solution[solIdx]->variables->values = new VariableValues();
	}
	if (optimization->solution[solIdx]->variables->values->var == NULL){
		optimization->solution[solIdx]->variables->values->var = new VarValue*[numberOfVar];
	}
	optimization->solution[solIdx]->variables->values->numberOfVar = numberOfVar;
	if(x.size() == 0){
		//optimization->solution[solIdx]->variables->values->var = NULL;
		return true;
	}
	for(int i = 0; i < numberOfVar; i++){
		optimization->solution[solIdx]->variables->values->var[i] = new VarValue();
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
	if(optimization->solution[solIdx]->variables->values->var == NULL){
		optimization->solution[solIdx]->variables->values->var = new VarValue*[numberOfVar];
	}
	optimization->solution[solIdx]->variables->values->numberOfVar = numberOfVar;
	if(x == NULL){
		//optimization->solution[solIdx]->variables->values->var = NULL;
		return true;
	}
	for(int i = 0; i < numberOfVar; i++){
		optimization->solution[solIdx]->variables->values->var[i] = new VarValue();
		optimization->solution[solIdx]->variables->values->var[i]->idx = i;
		optimization->solution[solIdx]->variables->values->var[i]->value = x[i];
	}
	return true;
}//setPrimalVariableValuesDense

bool OSResult::setNumberOfVarValues(int solIdx, int numberOfVar){
	if (optimization == NULL || optimization->solution == NULL)
	{//	throw ErrorClass("No optimization or solution object defined");  
		return false;
	}
	int nSols = optimization->numberOfSolutions;
	if (solIdx < 0 || solIdx >=  nSols)
	{//	throw ErrorClass("Trying to use a solution that was not previously declared");  
		return false;
	}
	if (optimization->solution[solIdx] == NULL)
		optimization->solution[solIdx] = new OptimizationSolution();	
	if (optimization->solution[solIdx]->variables == NULL)
		optimization->solution[solIdx]->variables = new VariableSolution();
	if (optimization->solution[solIdx]->variables->values == NULL)
		optimization->solution[solIdx]->variables->values = new VariableValues();
	if (optimization->solution[solIdx]->variables->values->numberOfVar > 0)
	{//	throw ErrorClass("Trying to redefine var`array. Potential loss of data.");
		return false;
	}
	if (numberOfVar < 0)
	{//	throw ErrorClass("Size of var`array cannot be negative.");
		return false;
	}
	optimization->solution[solIdx]->variables->values->numberOfVar = numberOfVar;
	optimization->solution[solIdx]->variables->values->var = new VarValue*[numberOfVar];
	for(int i = 0; i < numberOfVar; i++)
		optimization->solution[solIdx]->variables->values->var[i] = new VarValue();
	return true;
}//setNumberOfVarValues

bool OSResult::setVarValue(int solIdx, int number, int idx, double val){
	if (optimization == NULL || optimization->solution == NULL)
	{//	throw ErrorClass("No optimization or solution object defined");  
		return false;
	}
	int nSols = optimization->numberOfSolutions;
	if (solIdx < 0 || solIdx >=  nSols)
	{//	throw ErrorClass("Trying to use a solution that was not previously declared");  
		return false;
	}
	if (optimization->solution[solIdx] == NULL)
	{//	throw ErrorClass("Solution object not previously defined");  
		return false;
	}
	if (optimization->solution[solIdx]->variables == NULL)
	{//	throw ErrorClass("variables object not previously defined");  
		return false;
	}
	if (optimization->solution[solIdx]->variables->values == NULL)
	{//	throw ErrorClass("values object not previously defined");  
		return false;
	}
	int nVar = 	optimization->solution[solIdx]->variables->values->numberOfVar;
	if (number < 0 || number >= nVar)
	{//	throw ErrorClass("Trying to set value outside of var array boundaries");
		return false;
	}
	if (idx < 0)
	{//	throw ErrorClass("Variable index cannot be negative.");
		return false;
	}
	optimization->solution[solIdx]->variables->values->var[number]->idx   = idx;
	optimization->solution[solIdx]->variables->values->var[number]->value = val;
	return true;
}//setVarValue


bool OSResult::setNumberOfVarValuesString(int solIdx, int numberOfVar){
	if (optimization == NULL || optimization->solution == NULL)
	{//	throw ErrorClass("No optimization or solution object defined");  
		return false;
	}
	int nSols = optimization->numberOfSolutions;
	if (solIdx < 0 || solIdx >=  nSols)
	{//	throw ErrorClass("Trying to use a solution that was not previously declared");  
		return false;
	}
	if (optimization->solution[solIdx] == NULL)
		optimization->solution[solIdx] = new OptimizationSolution();	
	if (optimization->solution[solIdx]->variables == NULL)
		optimization->solution[solIdx]->variables = new VariableSolution();
	if (optimization->solution[solIdx]->variables->valuesString == NULL)
		optimization->solution[solIdx]->variables->valuesString = new VariableValuesString();
	if (optimization->solution[solIdx]->variables->valuesString->numberOfVar > 0)
	{//	throw ErrorClass("Trying to redefine var`array. Potential loss of data.");
		return false;
	}
	if (numberOfVar < 0)
	{//	throw ErrorClass("Size of var`array cannot be negative.");
		return false;
	}
	optimization->solution[solIdx]->variables->valuesString->numberOfVar = numberOfVar;
	optimization->solution[solIdx]->variables->valuesString->var = new VarValueString*[numberOfVar];
	for(int i = 0; i < numberOfVar; i++)
		optimization->solution[solIdx]->variables->valuesString->var[i] = new VarValueString();
	return true;
}//setNumberOfVarValuesString

bool OSResult::setVarValueString(int solIdx, int number, int idx, std::string str){
	if (optimization == NULL || optimization->solution == NULL)
	{//	throw ErrorClass("No optimization or solution object defined");  
		return false;
	}
	int nSols = optimization->numberOfSolutions;
	if (solIdx < 0 || solIdx >=  nSols)
	{//	throw ErrorClass("Trying to use a solution that was not previously declared");  
		return false;
	}
	if (optimization->solution[solIdx] == NULL)
	{//	throw ErrorClass("Solution object not previously defined");  
		return false;
	}
	if (optimization->solution[solIdx]->variables == NULL)
	{//	throw ErrorClass("variables object not previously defined");  
		return false;
	}
	if (optimization->solution[solIdx]->variables->valuesString == NULL)
	{//	throw ErrorClass("values object not previously defined");  
		return false;
	}
	int nVar = 	optimization->solution[solIdx]->variables->valuesString->numberOfVar;
	if (number < 0 || number >= nVar)
	{//	throw ErrorClass("Trying to set value outside of var array boundaries");
		return false;
	}
	if (idx < 0)
	{//	throw ErrorClass("Variable index cannot be negative.");
		return false;
	}
	optimization->solution[solIdx]->variables->valuesString->var[number]->idx   = idx;
	optimization->solution[solIdx]->variables->valuesString->var[number]->value = str;
	return true;
}//setVarValueString

bool OSResult::setNumberOfBasisVar(int solIdx, int numberOfVar){
	if (optimization == NULL || optimization->solution == NULL)
	{//	throw ErrorClass("No optimization or solution object defined");  
		return false;
	}
	int nSols = optimization->numberOfSolutions;
	if (solIdx < 0 || solIdx >=  nSols)
	{//	throw ErrorClass("Trying to use a solution that was not previously declared");  
		return false;
	}
	if (optimization->solution[solIdx] == NULL)
		optimization->solution[solIdx] = new OptimizationSolution();	
	if (optimization->solution[solIdx]->variables == NULL)
		optimization->solution[solIdx]->variables = new VariableSolution();
	if (optimization->solution[solIdx]->variables->basisStatus == NULL)
		optimization->solution[solIdx]->variables->basisStatus = new BasisStatus();
	if (optimization->solution[solIdx]->variables->basisStatus->numberOfVar > 0)
	{//	throw ErrorClass("Trying to redefine var`array. Potential loss of data.");
		return false;
	}
	if (numberOfVar < 0)
	{//	throw ErrorClass("Size of var`array cannot be negative.");
		return false;
	}
	optimization->solution[solIdx]->variables->basisStatus->numberOfVar = numberOfVar;
	optimization->solution[solIdx]->variables->basisStatus->var = new BasStatus*[numberOfVar];
	for(int i = 0; i < numberOfVar; i++)
		optimization->solution[solIdx]->variables->basisStatus->var[i] = new BasStatus();
	return true;
}//setNumberOfBasisVar

bool OSResult::setBasisVar(int solIdx, int number, int idx, std::string str){
	if (optimization == NULL || optimization->solution == NULL)
	{//	throw ErrorClass("No optimization or solution object defined");  
		return false;
	}
	int nSols = optimization->numberOfSolutions;
	if (solIdx < 0 || solIdx >=  nSols)
	{//	throw ErrorClass("Trying to use a solution that was not previously declared");  
		return false;
	}
	if (optimization->solution[solIdx] == NULL)
	{//	throw ErrorClass("Solution object not previously defined");  
		return false;
	}
	if (optimization->solution[solIdx]->variables == NULL)
	{//	throw ErrorClass("variables object not previously defined");  
		return false;
	}
	if (optimization->solution[solIdx]->variables->basisStatus == NULL)
	{//	throw ErrorClass("values object not previously defined");  
		return false;
	}
	int nVar = 	optimization->solution[solIdx]->variables->basisStatus->numberOfVar;
	if (number < 0 || number >= nVar)
	{//	throw ErrorClass("Trying to set value outside of var array boundaries");
		return false;
	}
	if (idx < 0)
	{//	throw ErrorClass("Variable index cannot be negative.");
		return false;
	}
	optimization->solution[solIdx]->variables->basisStatus->var[number]->idx   = idx;
	optimization->solution[solIdx]->variables->basisStatus->var[number]->value = str;
	return true;
}//setVarValueString


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
	if (optimization->solution[solIdx]->variables->other[ otherIdx]->var == NULL)
		optimization->solution[solIdx]->variables->other[ otherIdx]->var = new OtherVarResult*[numberOfVar];
	for(int i = 0; i < numberOfVar; i++){
		optimization->solution[solIdx]->variables->other[ otherIdx]->var[i] = new OtherVarResult();
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
	if(optimization->solution[solIdx]->variables->other[ otherIdx]->var == NULL)
		optimization->solution[solIdx]->variables->other[ otherIdx]->var = new OtherVarResult*[numberOfVar];
	for(int i = 0; i < numberOfVar; i++){
		optimization->solution[solIdx]->variables->other[ otherIdx]->var[i] = new OtherVarResult();
		optimization->solution[solIdx]->variables->other[ otherIdx]->var[i]->idx = i;
		optimization->solution[solIdx]->variables->other[ otherIdx]->var[i]->value = s[i];
		;
	}
	return true;
}//setAnOtherVariableResultDense

bool OSResult::setOtherVariableResultNumberOfVar(int solIdx, int otherIdx, int numberOfVar){
	int iNumberOfVariables = numberOfVar;
	if (iNumberOfVariables <= -1) return false;
	int nSols = this->getSolutionNumber();
	if (optimization == NULL) return false;
	if (nSols <= 0) return false;
	if (optimization == NULL) return false;
	if (optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if (optimization->solution[solIdx] == NULL) return false;
	if (optimization->solution[solIdx]->variables == NULL)return false;
	if (optimization->solution[solIdx]->variables->other == NULL) return false;
	if (optimization->solution[solIdx]->variables->other[ otherIdx] == NULL) return false;
	if (optimization->solution[solIdx]->variables->other[ otherIdx]->var == NULL)
		optimization->solution[solIdx]->variables->other[ otherIdx]->var = new OtherVarResult*[numberOfVar];
	for(int i = 0; i < numberOfVar; i++)
		optimization->solution[solIdx]->variables->other[ otherIdx]->var[i] = new OtherVarResult();
	optimization->solution[solIdx]->variables->other[ otherIdx]->numberOfVar = numberOfVar;
	return true;
}//setOtherVariableResultNumberOfVar

bool OSResult::setOtherVariableResultName(int solIdx, int otherIdx, std::string name){
	int numberOfVar = this->getVariableNumber();
	int iNumberOfVariables = numberOfVar;
	if (iNumberOfVariables <= -1) return false;
	int nSols = this->getSolutionNumber();
	if (optimization == NULL) return false;
	if (nSols <= 0) return false;
	if (optimization == NULL) return false;
	if (optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if (optimization->solution[solIdx] == NULL) return false;
	if (optimization->solution[solIdx]->variables == NULL)return false;
	if (optimization->solution[solIdx]->variables->other == NULL) return false;
	if (optimization->solution[solIdx]->variables->other[ otherIdx] == NULL) return false;
	optimization->solution[solIdx]->variables->other[ otherIdx]->name = name;
	return true;
}//setOtherVariableResultName

bool OSResult::setOtherVariableResultValue(int solIdx, int otherIdx, std::string value){
	int numberOfVar = this->getVariableNumber();
	int iNumberOfVariables = numberOfVar;
	if (iNumberOfVariables <= -1) return false;
	int nSols = this->getSolutionNumber();
	if (optimization == NULL) return false;
	if (nSols <= 0) return false;
	if (optimization == NULL) return false;
	if (optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if (optimization->solution[solIdx] == NULL) return false;
	if (optimization->solution[solIdx]->variables == NULL)return false;
	if (optimization->solution[solIdx]->variables->other == NULL) return false;
	if (optimization->solution[solIdx]->variables->other[ otherIdx] == NULL) return false;
	optimization->solution[solIdx]->variables->other[ otherIdx]->value = value;
	return true;
}//setOtherVariableResultValue

bool OSResult::setOtherVariableResultDescription(int solIdx, int otherIdx, std::string description){
	int numberOfVar = this->getVariableNumber();
	int iNumberOfVariables = numberOfVar;
	if (iNumberOfVariables <= -1) return false;
	int nSols = this->getSolutionNumber();
	if (optimization == NULL) return false;
	if (nSols <= 0) return false;
	if (optimization == NULL) return false;
	if (optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if (optimization->solution[solIdx] == NULL) return false;
	if (optimization->solution[solIdx]->variables == NULL)return false;
	if (optimization->solution[solIdx]->variables->other == NULL) return false;
	if (optimization->solution[solIdx]->variables->other[ otherIdx] == NULL) return false;
	optimization->solution[solIdx]->variables->other[ otherIdx]->description = description;
	return true;
}//setOtherVariableResultDescription

bool OSResult::setOtherVariableResultVarIdx(int solIdx, int otherIdx, int varIdx, int idx){
	int nSols = this->getSolutionNumber();
	if(nSols <= 0) return false;
	if(optimization == NULL) return false;
	if(optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if(optimization->solution[solIdx] == NULL) return false;
	if(optimization->solution[solIdx]->variables == NULL) return false;
	if(optimization->solution[solIdx]->variables->other[otherIdx] == NULL) return false;
	if(optimization->solution[solIdx]->variables->other[otherIdx]->var == NULL) return false;
	optimization->solution[solIdx]->variables->other[otherIdx]->var[varIdx]->idx = idx;
	return true;		
}//setOtherVariableResultVarIdx

bool OSResult::setOtherVariableResultVar(int solIdx, int otherIdx, int varIdx, std::string value){
	int nSols = this->getSolutionNumber();
	if(nSols <= 0) return false;
	if(optimization == NULL) return false;
	if(optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if(optimization->solution[solIdx] == NULL) return false;
	if(optimization->solution[solIdx]->variables == NULL) return false;
	if(optimization->solution[solIdx]->variables->other[otherIdx] == NULL) return false;
	if(optimization->solution[solIdx]->variables->other[otherIdx]->var == NULL) return false;
	optimization->solution[solIdx]->variables->other[otherIdx]->var[varIdx]->value = value;
	return true;		
}//setOtherVariableResultVar

bool OSResult::setNumberOfOtherObjectiveResults(int solIdx, int numberOfOtherObjectiveResults){
	int nSols = this->getSolutionNumber();
	if (nSols <= 0) return false;
	if (optimization == NULL) return false;
	if (optimization->solution == NULL || 
	    solIdx < 0 || solIdx >=  nSols) return false;
	if (optimization->solution[solIdx] == NULL){
		optimization->solution[solIdx] = new OptimizationSolution();
	}
	if (optimization->solution[solIdx]->objectives == NULL){
		optimization->solution[solIdx]->objectives = new ObjectiveSolution();
	}
	optimization->solution[solIdx]->objectives->numberOfOtherObjectiveResults =  numberOfOtherObjectiveResults;
	optimization->solution[solIdx]->objectives->other = new OtherObjectiveResult*[numberOfOtherObjectiveResults];
	for(int i = 0; i < numberOfOtherObjectiveResults; i++){
		optimization->solution[solIdx]->objectives->other[ i]  = new OtherObjectiveResult();
	}
	return true;
}//setNumberOfOtherObjectiveResults

bool OSResult::setNumberOfObjValues(int solIdx, int numberOfObj){
	if (optimization == NULL || optimization->solution == NULL)
	{//	throw ErrorClass("No optimization or solution object defined");  
		return false;
	}
	int nSols = optimization->numberOfSolutions;
	if (solIdx < 0 || solIdx >=  nSols)
	{//	throw ErrorClass("Trying to use a solution that was not previously declared");  
		return false;
	}
	if (optimization->solution[solIdx] == NULL)
		optimization->solution[solIdx] = new OptimizationSolution();	
	if (optimization->solution[solIdx]->objectives == NULL)
		optimization->solution[solIdx]->objectives = new ObjectiveSolution();
	if (optimization->solution[solIdx]->objectives->values == NULL)
		optimization->solution[solIdx]->objectives->values = new ObjectiveValues();
	if (optimization->solution[solIdx]->objectives->values->numberOfObj > 0)
	{//	throw ErrorClass("Trying to redefine obj`array. Potential loss of data.");
		return false;
	}
	if (numberOfObj < 0)
	{//	throw ErrorClass("Size of obj`array cannot be negative.");
		return false;
	}
	optimization->solution[solIdx]->objectives->values->numberOfObj = numberOfObj;
	optimization->solution[solIdx]->objectives->values->obj = new ObjValue*[numberOfObj];
	for(int i = 0; i < numberOfObj; i++)
		optimization->solution[solIdx]->objectives->values->obj[i] = new ObjValue();
	return true;
}//setNumberOfObjValues

bool OSResult::setObjValue(int solIdx, int number, int idx, double val){
	if (optimization == NULL || optimization->solution == NULL)
	{//	throw ErrorClass("No optimization or solution object defined");  
		return false;
	}
	int nSols = optimization->numberOfSolutions;
	if (solIdx < 0 || solIdx >=  nSols)
	{//	throw ErrorClass("Trying to use a solution that was not previously declared");  
		return false;
	}
	if (optimization->solution[solIdx] == NULL)
	{//	throw ErrorClass("Solution object not previously defined");  
		return false;
	}
	if (optimization->solution[solIdx]->objectives == NULL)
	{//	throw ErrorClass("objectives object not previously defined");  
		return false;
	}
	if (optimization->solution[solIdx]->objectives->values == NULL)
	{//	throw ErrorClass("values object not previously defined");  
		return false;
	}
	int nObj = 	optimization->solution[solIdx]->objectives->values->numberOfObj;
	if (number < 0 || number >= nObj)
	{//	throw ErrorClass("Trying to set value outside of obj array boundaries");
		return false;
	}
	if (idx >= 0)
	{//	throw ErrorClass("Objective index must be negative.");
		return false;
	}
	optimization->solution[solIdx]->objectives->values->obj[number]->idx   = idx;
	optimization->solution[solIdx]->objectives->values->obj[number]->value = val;
	return true;
}//setObjValue

bool OSResult::setOtherObjectiveResultNumberOfObj(int solIdx, int otherIdx, int numberOfObj){
	int iNumberOfObjectives = numberOfObj;
	if (iNumberOfObjectives <= -1) return false;
	int nSols = this->getSolutionNumber();
	if (optimization == NULL) return false;
	if (nSols <= 0) return false;
	if (optimization == NULL) return false;
	if (optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if (optimization->solution[solIdx] == NULL) return false;
	if (optimization->solution[solIdx]->objectives == NULL)return false;
	if (optimization->solution[solIdx]->objectives->other == NULL) return false;
	if (optimization->solution[solIdx]->objectives->other[ otherIdx] == NULL) return false;
	if (optimization->solution[solIdx]->objectives->other[ otherIdx]->obj == NULL)
		optimization->solution[solIdx]->objectives->other[ otherIdx]->obj = new OtherObjResult*[numberOfObj];
	for(int i = 0; i < numberOfObj; i++)
		optimization->solution[solIdx]->objectives->other[ otherIdx]->obj[i] = new OtherObjResult();
	optimization->solution[solIdx]->objectives->other[ otherIdx]->numberOfObj = numberOfObj;
	return true;
}//setOtherObjectiveResultNumberOfObj

bool OSResult::setOtherObjectiveResultName(int solIdx, int otherIdx, std::string name){
	int numberOfObj = this->getObjectiveNumber();
	int iNumberOfObjectives = numberOfObj;
	if (iNumberOfObjectives <= -1) return false;
	int nSols = this->getSolutionNumber();
	if (optimization == NULL) return false;
	if (nSols <= 0) return false;
	if (optimization == NULL) return false;
	if (optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if (optimization->solution[solIdx] == NULL) return false;
	if (optimization->solution[solIdx]->objectives == NULL)return false;
	if (optimization->solution[solIdx]->objectives->other == NULL) return false;
	if (optimization->solution[solIdx]->objectives->other[ otherIdx] == NULL) return false;
	optimization->solution[solIdx]->objectives->other[ otherIdx]->name = name;
	return true;
}//setOtherObjectiveResultName

bool OSResult::setOtherObjectiveResultValue(int solIdx, int otherIdx, std::string value){
	int numberOfObj = this->getObjectiveNumber();
	int iNumberOfObjectives = numberOfObj;
	if (iNumberOfObjectives <= -1) return false;
	int nSols = this->getSolutionNumber();
	if (optimization == NULL) return false;
	if (nSols <= 0) return false;
	if (optimization == NULL) return false;
	if (optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if (optimization->solution[solIdx] == NULL) return false;
	if (optimization->solution[solIdx]->objectives == NULL)return false;
	if (optimization->solution[solIdx]->objectives->other == NULL) return false;
	if (optimization->solution[solIdx]->objectives->other[ otherIdx] == NULL) return false;
	optimization->solution[solIdx]->objectives->other[ otherIdx]->value = value;
	return true;
}//setOtherObjectiveResultValue

bool OSResult::setOtherObjectiveResultDescription(int solIdx, int otherIdx, std::string description){
	int numberOfObj = this->getObjectiveNumber();
	int iNumberOfObjectives = numberOfObj;
	if (iNumberOfObjectives <= -1) return false;
	int nSols = this->getSolutionNumber();
	if (optimization == NULL) return false;
	if (nSols <= 0) return false;
	if (optimization == NULL) return false;
	if (optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if (optimization->solution[solIdx] == NULL) return false;
	if (optimization->solution[solIdx]->objectives == NULL)return false;
	if (optimization->solution[solIdx]->objectives->other == NULL) return false;
	if (optimization->solution[solIdx]->objectives->other[ otherIdx] == NULL) return false;
	optimization->solution[solIdx]->objectives->other[ otherIdx]->description = description;
	return true;
}//setOtherObjectiveResultDescription

bool OSResult::setOtherObjectiveResultObjIdx(int solIdx, int otherIdx, int objIdx, int idx){
	int nSols = this->getSolutionNumber();
	if (nSols <= 0) return false;
	if (optimization == NULL) return false;
	if (optimization->solution == NULL || 
	    solIdx < 0 || solIdx >=  nSols) return false;
	if (optimization->solution[solIdx] == NULL) return false;
	if (optimization->solution[solIdx]->objectives == NULL) return false;
	if (optimization->solution[solIdx]->objectives->other[otherIdx] == NULL) return false;
	if (optimization->solution[solIdx]->objectives->other[otherIdx]->obj == NULL) return false;
	if (idx >= 0) return false;
	optimization->solution[solIdx]->objectives->other[otherIdx]->obj[objIdx]->idx = idx;
	return true;
}//setOtherObjectiveResultObjIdx

bool OSResult::setOtherObjectiveResultObj(int solIdx, int otherIdx, int objIdx, std::string value){
	int nSols = this->getSolutionNumber();
	if (nSols <= 0) return false;
	if (optimization == NULL) return false;
	if (optimization->solution == NULL || 
	    solIdx < 0 || solIdx >=  nSols) return false;
	if (optimization->solution[solIdx] == NULL) return false;
	if (optimization->solution[solIdx]->objectives == NULL) return false;
	if (optimization->solution[solIdx]->objectives->other[otherIdx] == NULL) return false;
	if (optimization->solution[solIdx]->objectives->other[otherIdx]->obj == NULL) return false;
	optimization->solution[solIdx]->objectives->other[otherIdx]->obj[objIdx]->value = value;
	return true;
}//setOtherObjectiveResultObj

bool OSResult::setNumberOfOtherConstraintResults(int solIdx, int numberOfOtherConstraintResults){
	int nSols = this->getSolutionNumber();
	if (nSols <= 0) return false;
	if (optimization == NULL) return false;
	if (optimization->solution == NULL || 
	    solIdx < 0 || solIdx >=  nSols) return false;
	if (optimization->solution[solIdx] == NULL){
		optimization->solution[solIdx] = new OptimizationSolution();
	}
	if (optimization->solution[solIdx]->constraints == NULL){
		optimization->solution[solIdx]->constraints = new ConstraintSolution();
	}
	optimization->solution[solIdx]->constraints->numberOfOtherConstraintResults =  numberOfOtherConstraintResults;
	optimization->solution[solIdx]->constraints->other = new OtherConstraintResult*[ numberOfOtherConstraintResults];
	for(int i = 0; i < numberOfOtherConstraintResults; i++){
		optimization->solution[solIdx]->constraints->other[ i]  = new OtherConstraintResult();
	}
	return true;
}//setNumberOfOtherConstraintResults

bool OSResult::setNumberOfDualValues(int solIdx, int numberOfCon){
	if (optimization == NULL || optimization->solution == NULL)
	{//	throw ErrorClass("No optimization or solution object defined");  
		return false;
	}
	int nSols = optimization->numberOfSolutions;
	if (solIdx < 0 || solIdx >=  nSols)
	{//	throw ErrorClass("Trying to use a solution that was not previously declared");  
		return false;
	}
	if (optimization->solution[solIdx] == NULL)
		optimization->solution[solIdx] = new OptimizationSolution();	
	if (optimization->solution[solIdx]->constraints == NULL)
		optimization->solution[solIdx]->constraints = new ConstraintSolution();
	if (optimization->solution[solIdx]->constraints->dualValues == NULL)
		optimization->solution[solIdx]->constraints->dualValues = new DualVariableValues();
	if (optimization->solution[solIdx]->constraints->dualValues->numberOfCon > 0)
	{//	throw ErrorClass("Trying to redefine con`array. Potential loss of data.");
		return false;
	}
	if (numberOfCon < 0)
	{//	throw ErrorClass("Size of con`array cannot be negative.");
		return false;
	}
	optimization->solution[solIdx]->constraints->dualValues->numberOfCon = numberOfCon;
	optimization->solution[solIdx]->constraints->dualValues->con = new DualVarValue*[numberOfCon];
	for(int i = 0; i < numberOfCon; i++)
		optimization->solution[solIdx]->constraints->dualValues->con[i] = new DualVarValue();
	return true;
}//setNumberOfDualValues

bool OSResult::setDualValue(int solIdx, int number, int idx, double val){
	if (optimization == NULL || optimization->solution == NULL)
	{//	throw ErrorClass("No optimization or solution object defined");  
		return false;
	}
	int nSols = optimization->numberOfSolutions;
	if (solIdx < 0 || solIdx >=  nSols)
	{//	throw ErrorClass("Trying to use a solution that was not previously declared");  
		return false;
	}
	if (optimization->solution[solIdx] == NULL)
	{//	throw ErrorClass("Solution object not previously defined");  
		return false;
	}
	if (optimization->solution[solIdx]->constraints == NULL)
	{//	throw ErrorClass("constraints object not previously defined");  
		return false;
	}
	if (optimization->solution[solIdx]->constraints->dualValues == NULL)
	{//	throw ErrorClass("values object not previously defined");  
		return false;
	}
	int nCon = 	optimization->solution[solIdx]->constraints->dualValues->numberOfCon;
	if (number < 0 || number >= nCon)
	{//	throw ErrorClass("Trying to set value outside of con array boundaries");
		return false;
	}
	if (idx < 0)
	{//	throw ErrorClass("Constraint index cannot be negative.");
		return false;
	}
	optimization->solution[solIdx]->constraints->dualValues->con[number]->idx   = idx;
	optimization->solution[solIdx]->constraints->dualValues->con[number]->value = val;
	return true;
}//setDualValue

bool OSResult::setOtherConstraintResultNumberOfCon(int solIdx, int otherIdx, int numberOfCon){
	int iNumberOfConstraints = numberOfCon;
	if (iNumberOfConstraints <= -1) return false;
	int nSols = this->getSolutionNumber();
	if (optimization == NULL) return false;
	if (nSols <= 0) return false;
	if (optimization == NULL) return false;
	if (optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if (optimization->solution[solIdx] == NULL) return false;
	if (optimization->solution[solIdx]->constraints == NULL)return false;
	if (optimization->solution[solIdx]->constraints->other == NULL) return false;
	if (optimization->solution[solIdx]->constraints->other[ otherIdx] == NULL) return false;
	if (optimization->solution[solIdx]->constraints->other[ otherIdx]->con == NULL)
		optimization->solution[solIdx]->constraints->other[ otherIdx]->con = new OtherConResult*[numberOfCon];
	for(int i = 0; i < numberOfCon; i++)
		optimization->solution[solIdx]->constraints->other[ otherIdx]->con[i] = new OtherConResult();
	optimization->solution[solIdx]->constraints->other[ otherIdx]->numberOfCon = numberOfCon;
	return true;
}//setOtherConstraintResultNumberOfCon

bool OSResult::setOtherConstraintResultName(int solIdx, int otherIdx, std::string name){
	int numberOfCon = this->getConstraintNumber();
	int iNumberOfConstraints = numberOfCon;
	if (iNumberOfConstraints <= -1) return false;
	int nSols = this->getSolutionNumber();
	if (optimization == NULL) return false;
	if (nSols <= 0) return false;
	if (optimization == NULL) return false;
	if (optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if (optimization->solution[solIdx] == NULL) return false;
	if (optimization->solution[solIdx]->constraints == NULL)return false;
	if (optimization->solution[solIdx]->constraints->other == NULL) return false;
	if (optimization->solution[solIdx]->constraints->other[ otherIdx] == NULL) return false;
	optimization->solution[solIdx]->constraints->other[ otherIdx]->name = name;
	return true;
}//setOtherConstraintResultName

bool OSResult::setOtherConstraintResultValue(int solIdx, int otherIdx, std::string value){
	int numberOfCon = this->getConstraintNumber();
	int iNumberOfConstraints = numberOfCon;
	if (iNumberOfConstraints <= -1) return false;
	int nSols = this->getSolutionNumber();
	if (optimization == NULL) return false;
	if (nSols <= 0) return false;
	if (optimization == NULL) return false;
	if (optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if (optimization->solution[solIdx] == NULL) return false;
	if (optimization->solution[solIdx]->constraints == NULL)return false;
	if (optimization->solution[solIdx]->constraints->other == NULL) return false;
	if (optimization->solution[solIdx]->constraints->other[ otherIdx] == NULL) return false;
	optimization->solution[solIdx]->constraints->other[ otherIdx]->value = value;
	return true;
}//setOtherConstraintResultValue

bool OSResult::setOtherConstraintResultDescription(int solIdx, int otherIdx, std::string description){
	int numberOfCon = this->getConstraintNumber();
	int iNumberOfConstraints = numberOfCon;
	if (iNumberOfConstraints <= -1) return false;
	int nSols = this->getSolutionNumber();
	if (optimization == NULL) return false;
	if (nSols <= 0) return false;
	if (optimization == NULL) return false;
	if (optimization->solution == NULL || 
	   solIdx < 0 || solIdx >=  nSols) return false;
	if (optimization->solution[solIdx] == NULL) return false;
	if (optimization->solution[solIdx]->constraints == NULL)return false;
	if (optimization->solution[solIdx]->constraints->other == NULL) return false;
	if (optimization->solution[solIdx]->constraints->other[ otherIdx] == NULL) return false;
	optimization->solution[solIdx]->constraints->other[ otherIdx]->description = description;
	return true;
}//setOtherConstraintResultDescription

bool OSResult::setOtherConstraintResultConIdx(int solIdx, int otherIdx, int conIdx, int idx){
	int nSols = this->getSolutionNumber();
	if (nSols <= 0) return false;
	if (optimization == NULL) return false;
	if (optimization->solution == NULL || 
	    solIdx < 0 || solIdx >=  nSols) return false;
	if (optimization->solution[solIdx] == NULL) return false;
	if (optimization->solution[solIdx]->constraints == NULL) return false;
	if (optimization->solution[solIdx]->constraints->other[otherIdx] == NULL) return false;
	if (optimization->solution[solIdx]->constraints->other[otherIdx]->con == NULL) return false;
	optimization->solution[solIdx]->constraints->other[otherIdx]->con[conIdx]->idx = idx;
	return true;
}//setOtherConstraintResultConIdx

bool OSResult::setOtherConstraintResultCon(int solIdx, int otherIdx, int conIdx, std::string value){
	int nSols = this->getSolutionNumber();
	if (nSols <= 0) return false;
	if (optimization == NULL) return false;
	if (optimization->solution == NULL || 
	    solIdx < 0 || solIdx >=  nSols) return false;
	if (optimization->solution[solIdx] == NULL) return false;
	if (optimization->solution[solIdx]->constraints == NULL) return false;
	if (optimization->solution[solIdx]->constraints->other[otherIdx] == NULL) return false;
	if (optimization->solution[solIdx]->constraints->other[otherIdx]->con == NULL) return false;
	optimization->solution[solIdx]->constraints->other[otherIdx]->con[conIdx]->value = value;
	return true;
}//setOtherConstraintResultCon

bool OSResult::setNumberOfOtherSolutionResults(int solIdx, int numberOfOtherSolutionResults){
	int nSols = this->getSolutionNumber();
	if (nSols <= 0) return false;
	if (optimization == NULL) return false;
	if (optimization->solution == NULL || 
	    solIdx < 0 || solIdx >=  nSols) return false;
	if (optimization->solution[solIdx] == NULL){
		optimization->solution[solIdx] = new OptimizationSolution();
	}
	if (optimization->solution[solIdx]->otherSolutionResults == NULL){
		optimization->solution[solIdx]->otherSolutionResults = new OtherSolutionResults();
	}
	optimization->solution[solIdx]->otherSolutionResults->numberOfOtherSolutionResults =  numberOfOtherSolutionResults;
	optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult = new OtherSolutionResult*[ numberOfOtherSolutionResults];
	for(int i = 0; i < numberOfOtherSolutionResults; i++){
		optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[ i]  = new OtherSolutionResult();
	}
	return true;
}//setNumberOfOtherSolutionResults

bool OSResult::setOtherSolutionResultName(int solIdx, int otherIdx, std::string name){
	int nSols = this->getSolutionNumber();
	if (nSols <= 0) return false;
	if (optimization == NULL) return false;
	if (optimization->solution == NULL || 
	    solIdx < 0 || solIdx >=  nSols) return false;
	if (optimization->solution[solIdx] == NULL) return false;
	if (optimization->solution[solIdx]->otherSolutionResults == NULL) return false;
	if (optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx] == NULL) return false;
	optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx]->name = name;
	return true;
}//setOtherSolutionResultName

bool OSResult::setOtherSolutionResultCategory(int solIdx, int otherIdx, std::string category){
	int nSols = this->getSolutionNumber();
	if (nSols <= 0) return false;
	if (optimization == NULL) return false;
	if (optimization->solution == NULL || 
	    solIdx < 0 || solIdx >=  nSols) return false;
	if (optimization->solution[solIdx] == NULL) return false;
	if (optimization->solution[solIdx]->otherSolutionResults == NULL) return false;
	if (optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx] == NULL) return false;
	optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx]->category = category;
	return true;
}//setOtherSolutionResultCategory


bool OSResult::setOtherSolutionResultDescription(int solIdx, int otherIdx, std::string description){
	int nSols = this->getSolutionNumber();
	if (nSols <= 0) return false;
	if (optimization == NULL) return false;
	if (optimization->solution == NULL || 
	    solIdx < 0 || solIdx >=  nSols) return false;
	if (optimization->solution[solIdx] == NULL) return false;
	if (optimization->solution[solIdx]->otherSolutionResults == NULL) return false;
	if (optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx] == NULL) return false;
	optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx]->description = description;
	return true;
}//setOtherSolutionResultDescription


bool OSResult::setOtherSolutionResultNumberOfItems(int solIdx, int otherIdx, int numberOfItems){
	int nSols = this->getSolutionNumber();
	if (nSols <= 0) return false;
	if (optimization == NULL) return false;
	if (optimization->solution == NULL || 
	    solIdx < 0 || solIdx >=  nSols) return false;
	if (optimization->solution[solIdx] == NULL) return false;
	if (optimization->solution[solIdx]->otherSolutionResults == NULL) return false;
	if (optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx] == NULL) 
		optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx] = new OtherSolutionResult();
	optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx]->numberOfItems = numberOfItems;
	if (optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx]->item == NULL)
		optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx]->item = new std::string[numberOfItems];
	return true;
}//setOtherSolutionResultNumberOfItems

bool OSResult::setOtherSolutionResultItem(int solIdx, int otherIdx, int itemIdx, std::string item){
	int nSols = this->getSolutionNumber();
	if (nSols <= 0) return false;
	if (optimization == NULL) return false;
	if (optimization->solution == NULL || 
	    solIdx < 0 || solIdx >=  nSols) return false;
	if (optimization->solution[solIdx] == NULL) return false;
	if (optimization->solution[solIdx]->otherSolutionResults == NULL) return false;
	if (optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx] == NULL) return false;
	if (optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx]->item == NULL) return false;
	optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx]->item[itemIdx] = item;
	return true;
}//setOtherSolutionResultItem

bool OSResult::setNumberOfSolverOutputs(int numberOfSolverOutputs){
	if (optimization == NULL) return false;
	if (optimization->otherSolverOutput == NULL){
		optimization->otherSolverOutput = new OtherSolverOutput();
	}
	optimization->otherSolverOutput->numberOfSolverOutputs =  numberOfSolverOutputs;
	optimization->otherSolverOutput->solverOutput = new SolverOutput*[ numberOfSolverOutputs];
	for(int i = 0; i < numberOfSolverOutputs; i++){
		optimization->otherSolverOutput->solverOutput[ i]  = new SolverOutput();
	}
	return true;
}//setNumberOfSolverOutputs

bool OSResult::setSolverOutputName(int otherIdx, std::string name){
	if (optimization == NULL) return false;
	if (optimization->otherSolverOutput == NULL) return false;
	if (optimization->otherSolverOutput->solverOutput[otherIdx] == NULL) return false;
	optimization->otherSolverOutput->solverOutput[otherIdx]->name = name;
	return true;
}//setSolverOutputName

bool OSResult::setSolverOutputCategory(int otherIdx, std::string category){
	if (optimization == NULL) return false;
	if (optimization->otherSolverOutput == NULL) return false;
	if (optimization->otherSolverOutput->solverOutput[otherIdx] == NULL) return false;
	optimization->otherSolverOutput->solverOutput[otherIdx]->category = category;
	return true;
}//setSolverOutputCategory

bool OSResult::setSolverOutputDescription(int otherIdx, std::string description){
	if (optimization == NULL) return false;
	if (optimization->otherSolverOutput == NULL) return false;
	if (optimization->otherSolverOutput->solverOutput[otherIdx] == NULL) return false;
	optimization->otherSolverOutput->solverOutput[otherIdx]->description = description;
	return true;
}//setSolverOutputDescription

bool OSResult::setSolverOutputNumberOfItems(int otherIdx, int numberOfItems){
	if (optimization == NULL) return false;
	if (optimization->otherSolverOutput == NULL) return false;
	if (optimization->otherSolverOutput->solverOutput[otherIdx] == NULL) 
		optimization->otherSolverOutput->solverOutput[otherIdx] = new SolverOutput();
	optimization->otherSolverOutput->solverOutput[otherIdx]->numberOfItems = numberOfItems;
	if (optimization->otherSolverOutput->solverOutput[otherIdx]->item == NULL)
		optimization->otherSolverOutput->solverOutput[otherIdx]->item = new std::string[numberOfItems];
	return true;
}//setSolverOutputNumberOfItems

bool OSResult::setSolverOutputItem(int otherIdx, int itemIdx, std::string item){
	if (optimization == NULL) return false;
	if (optimization->otherSolverOutput == NULL) return false;
	if (optimization->otherSolverOutput->solverOutput == NULL) return false;
	if (optimization->otherSolverOutput->solverOutput[otherIdx] == NULL) return false;
	if (optimization->otherSolverOutput->solverOutput[otherIdx]->item == NULL) return false;
	optimization->otherSolverOutput->solverOutput[otherIdx]->item[itemIdx] = item;
	return true;
}//setSolverOutputItem

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
	if(optimization->solution[solIdx]->objectives->values->obj == NULL){
		optimization->solution[solIdx]->objectives->values->obj = new ObjValue*[iNumberOfObjectives];
	}
	optimization->solution[solIdx]->objectives->values->numberOfObj = iNumberOfObjectives;
	for(int i = 0; i < iNumberOfObjectives; i++){
		optimization->solution[solIdx]->objectives->values->obj[i] = new ObjValue();
		optimization->solution[solIdx]->objectives->values->obj[i]->idx = x[i]->idx;
		optimization->solution[solIdx]->objectives->values->obj[i]->value = x[i]->value;
	}
	return true;
}//setObjectiveValuesSparse


bool OSResult::setObjectiveValuesDense(int solIdx, double *objectiveValues){
	int numberOfObj = this->getObjectiveNumber();
	int iNumberOfObjectives = numberOfObj;
	if (iNumberOfObjectives < 0) return false;
	if (iNumberOfObjectives == 0) return true;
	if (objectiveValues == NULL) return false;
	int nSols = this->getSolutionNumber();
	if (optimization == NULL) return false;
	if (nSols <= 0) return false;
	if (optimization == NULL) return false;
	if (optimization->solution == NULL || 
	    solIdx < 0 || solIdx >=  nSols) return false;
	if (optimization->solution[solIdx] == NULL){
		optimization->solution[solIdx] = new OptimizationSolution();
	}
	if (optimization->solution[solIdx]->objectives == NULL){
		optimization->solution[solIdx]->objectives = new ObjectiveSolution();
	}
	if (optimization->solution[solIdx]->objectives->values == NULL){
		optimization->solution[solIdx]->objectives->values = new ObjectiveValues();
	}
	if (optimization->solution[solIdx]->objectives->values->obj == NULL){
		optimization->solution[solIdx]->objectives->values->obj = new ObjValue*[iNumberOfObjectives];
	}

	optimization->solution[solIdx]->objectives->values->numberOfObj = iNumberOfObjectives;
	for(int i = 0; i < iNumberOfObjectives; i++){
		optimization->solution[solIdx]->objectives->values->obj[i] = new ObjValue();
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
	if(optimization->solution[solIdx]->constraints->dualValues->con == NULL){
		optimization->solution[solIdx]->constraints->dualValues->con = new DualVarValue*[numberOfCon];
	}
	if(x.size() == 0){
		optimization->solution[solIdx]->constraints->dualValues = NULL;
		return true;
	} 
	optimization->solution[solIdx]->constraints->dualValues->numberOfCon = numberOfCon;
	for(int i = 0; i < iNumberOfConstraints; i++){
		optimization->solution[solIdx]->constraints->dualValues->con[i] = new DualVarValue();
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
	if(optimization->solution[solIdx]->constraints->dualValues->con == NULL){
		optimization->solution[solIdx]->constraints->dualValues->con = new DualVarValue*[numberOfCon];
	}
	if(y == NULL){
		optimization->solution[solIdx]->constraints->dualValues = NULL;
		return true;
	} 
	optimization->solution[solIdx]->constraints->dualValues->numberOfCon = numberOfCon;
	for(int i = 0; i < iNumberOfConstraints; i++){
		optimization->solution[solIdx]->constraints->dualValues->con[i] = new DualVarValue();
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
	if(optimization->solution[solIdx]->constraints->dualValues->con == NULL){
		optimization->solution[solIdx]->constraints->dualValues->con = new DualVarValue*[numberOfCon];
	}
	if(dualVarValues == NULL){
		optimization->solution[solIdx]->constraints->dualValues = NULL;
		return true;
	}
	//optimization->solution[solIdx]->constraints->dualValues->con = new ConValue*[ iNumberOfConstraints];
	optimization->solution[solIdx]->constraints->dualValues->numberOfCon = numberOfCon;
	for(int i = 0; i < iNumberOfConstraints; i++){
		optimization->solution[solIdx]->constraints->dualValues->con[i] = new DualVarValue();
		//optimization->solution[solIdx]->constraints->dualValues->con[i] = new ConValue();
		optimization->solution[solIdx]->constraints->dualValues->con[i]->idx = i;
		optimization->solution[solIdx]->constraints->dualValues->con[i]->value = dualVarValues[i];
	}
	return true;
}//setConstraintValuesDense


