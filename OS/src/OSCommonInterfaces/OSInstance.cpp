/** @file OSInstance.cpp
 * \brief This file defines the OSInstance class along with its supporting classes..
 *
 * @author  Robert Fourer,  Jun Ma, Kipp Martin, m_mdConstraintFunctionValues
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
 *  
 */

#include "OSInstance.h"
#include "MathUtil.h"
#include "CommonUtil.h"
#include "ErrorClass.h"
#include "OSParameters.h"
#include<iostream> 
#include<sstream>


 
using namespace std;

OSInstance::OSInstance(): 
	m_sInstanceName(""),
	m_sInstanceSource(""),	
	m_sInstanceDescription(""),
	m_bProcessVariables(false),
	m_iVariableNumber(-1),
	m_iNumberOfBinaryVariables( 0),
	m_iNumberOfIntegerVariables( 0),
	m_msVariableNames(NULL),
	m_mdVariableInitialValues(NULL),
	m_msVariableInitialStringValues(NULL),
	m_mcVariableTypes(NULL),
	m_mdVariableLowerBounds(NULL),
	m_mdVariableUpperBounds(NULL),
	m_bProcessObjectives(false),
	m_iObjectiveNumber(-1),
	m_msObjectiveNames(NULL),
	m_msMaxOrMins(NULL),
	m_miNumberOfObjCoef(NULL),
	m_mdObjectiveConstants(NULL),
	m_mdObjectiveWeights(NULL),
	m_mdObjGradient(NULL),
	m_LagHessian(NULL),
	m_bLagHessianCreated( false),
	m_mObjectiveCoefficients(NULL),
	m_bGetDenseObjectives(false),
	m_mmdDenseObjectiveCoefficients(NULL),
	m_bProcessConstraints(false),
	m_iConstraintNumber(-1),
	m_msConstraintNames(NULL),
	m_mdConstraintLowerBounds(NULL),
	m_mdConstraintUpperBounds(NULL),
	m_mcConstraintTypes(NULL),
 	m_mdConstraintConstants( NULL),
	m_bDuplicateExpressionTreesMap( false),
	m_bSparseJacobianCalculated( false),
	m_miJacStart( NULL),
	m_miJacIndex( NULL),
	m_mdJacValue( NULL),
	m_miJacNumConTerms( NULL),
	m_sparseJacMatrix( NULL),
	m_bProcessLinearConstraintCoefficients(false),
	m_iLinearConstraintCoefficientNumber(-1),
	m_bColumnMajor(true),
	m_linearConstraintCoefficientsInColumnMajor(NULL),
	m_linearConstraintCoefficientsInRowMajor(NULL),
	m_bProcessQuadraticTerms(false),
	m_iQuadraticTermNumber(-1),
	m_quadraticTerms(0),
	m_iNonlinearExpressionNumber( -1),
	m_bProcessExpressionTrees( false),
	m_iConstraintNumberNonlinear( 0),
	m_iObjectiveNumberNonlinear( 0)
{    
	#ifdef DEBUG
	cout << "Inside OSInstance Constructor" << endl;
	#endif
	this->instanceHeader = new InstanceHeader();
	this->instanceData = new InstanceData();
}  

OSInstance::~OSInstance(){
	#ifdef DEBUG
	cout << "OSInstance Destructor Called" << endl;
	#endif
	std::map<int, OSExpressionTree*>::iterator posMapExpTree;
	// delete  the temporary arrays
	delete[] m_msVariableNames;
	m_msVariableNames = NULL;
	delete[] m_mdVariableInitialValues;
	m_mdVariableInitialValues = NULL ;
	delete[] m_msVariableInitialStringValues;
	m_msVariableInitialStringValues = NULL;
	delete[] m_mcVariableTypes;
	m_mcVariableTypes = NULL;
	delete[] m_msObjectiveNames;
	m_msObjectiveNames = NULL;
	delete[] m_msMaxOrMins;
	m_msMaxOrMins = NULL;
	delete[] m_miNumberOfObjCoef;
	m_miNumberOfObjCoef = NULL;
	delete[] m_mdObjectiveConstants; 
	m_mdObjectiveConstants = NULL;
	delete[] m_mdObjectiveWeights;
	m_mdObjectiveWeights = NULL;
	delete[] m_mObjectiveCoefficients;
	m_mObjectiveCoefficients = NULL;
	int i;
	if(instanceData->objectives->numberOfObjectives > 0 && m_mObjectiveCoefficients != NULL){
		for(i = 0; i < instanceData->objectives->numberOfObjectives; i++){
			delete m_mObjectiveCoefficients[i];
			m_mObjectiveCoefficients[i] = NULL;
		}
		m_mObjectiveCoefficients = NULL;
	}
	if(instanceData->objectives->numberOfObjectives > 0 && m_mmdDenseObjectiveCoefficients != NULL){
		for(i = 0; i < instanceData->objectives->numberOfObjectives; i++){
			delete[] m_mmdDenseObjectiveCoefficients[i];
			m_mmdDenseObjectiveCoefficients[i] = NULL;
		}
		m_mmdDenseObjectiveCoefficients = NULL;
	}
	delete[] m_msConstraintNames;
	m_msConstraintNames = NULL;
	delete[] m_mcConstraintTypes;
	m_mcConstraintTypes = NULL;
	delete[]  m_mdConstraintConstants;
	 m_mdConstraintConstants = NULL;
	delete[] m_mdConstraintLowerBounds;
	m_mdConstraintLowerBounds = NULL;
	delete[] m_mdConstraintUpperBounds;
	m_mdConstraintUpperBounds = NULL;
	delete[] m_mdVariableLowerBounds;
	m_mdVariableLowerBounds = NULL;
	delete[] m_mdVariableUpperBounds;
	m_mdVariableUpperBounds = NULL;
	std::cout << "Do garbagee collection for the gradient" << std::endl;
	// garbage collection for the gradient
	delete[] m_miJacStart;
	m_miJacStart = NULL;
	delete[] m_miJacIndex;
	m_miJacIndex = NULL;
	delete[] m_mdJacValue;
	m_mdJacValue = NULL;
	delete[] m_miJacNumConTerms;
	m_miJacNumConTerms = NULL;
	delete[] m_mdObjGradient;
	m_mdObjGradient = NULL;
	delete m_LagHessian;
	m_LagHessian = NULL;
	//delete m_sparseJacMatrix;
	m_sparseJacMatrix = NULL;
	//
	// delete the expression trees that got created
	// however they already got deleted if we have a lagrangian Hessian
	if( m_bLagHessianCreated == false){
		if( (m_bProcessExpressionTrees == true) && (m_bDuplicateExpressionTreesMap == false)  ) {
			for(posMapExpTree = m_mapExpressionTrees.begin(); posMapExpTree != m_mapExpressionTrees.end(); ++posMapExpTree){
				std::cout << "Deleting an expression tree from the map" << std::endl;
				delete m_mapExpressionTrees[ posMapExpTree->first ];
			}
		}
		if( m_bDuplicateExpressionTreesMap == true)   {
			for(posMapExpTree = m_mapExpressionTreesMod.begin(); posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree){
				std::cout << "Deleting an expression tree from the map" << std::endl;
				delete m_mapExpressionTreesMod[ posMapExpTree->first ];
			}
		}
	}
	//
	// delete the two children of OSInstance
	//delete instanceHeader object
	delete instanceHeader;
	instanceHeader = NULL;
	//delete instanceData object
	delete instanceData;
	instanceData = NULL;
}//OSInstance Destructor

InstanceHeader::InstanceHeader():
	description(""),
	name(""),
	source("")

{ 
	#ifdef DEBUG
	cout << "Inside the InstanceHeader Constructor" << endl;
	#endif
} 


InstanceHeader::~InstanceHeader(){
	#ifdef DEBUG  
	cout << "Inside the InstanceHeader Destructor" << endl;
	#endif
} 

Variable::Variable():
	name(""),
	init(OSNAN),
	lb(0.0),
	ub(OSINFINITY), 
	type('C'), 
	initString("")
{  
	#ifdef DEBUG
	cout << "Inside the Variable Constructor" << endl;
	#endif 
} 

Variable::~Variable(){  
	#ifdef DEBUG
	cout << "Inside the Variable Destructor" << endl; 
	#endif
} 

Variables::Variables(){  
	#ifdef DEBUG
	cout << "Inside the Variables Constructor" << endl; 
	#endif 
	numberOfVariables = 0;
	var = NULL; 
}

Variables::~Variables(){ 
	#ifdef DEBUG 
	cout << "Inside the Variables Destructor" << endl;
	#endif
	if(numberOfVariables > 0 && var != NULL){
		for(int i = 0; i < numberOfVariables; i++){
			delete var[i];
			var[i] = NULL;
		}
	}
	var = NULL; 
}  

ObjCoef::ObjCoef():
	idx(-1),
	value(0.0)  
{  
	#ifdef DEBUG
	cout << "Inside the Coef Constructor" << endl;
	#endif 
}

ObjCoef::~ObjCoef(){ 
	#ifdef DEBUG
	cout << "Inside the ObjCoef Desructor" << endl;  
	#endif
}

Objective::Objective():
	maxOrMin("min"),
	constant(0.0),
	weight(1.0),
	name("") , 
	numberOfObjCoef(0),
	coef(NULL)
{ 
 
	#ifdef DEBUG
	cout << "Inside the Objective Constructor" << endl;
	#endif
}

Objective::~Objective(){
	#ifdef DEBUG  
	cout << "Inside the Objective Destructor" << endl;
	#endif
	if(numberOfObjCoef > 0 && coef != NULL){
		for(int i = 0; i < numberOfObjCoef; i++){
			delete coef[i];
			coef[i] = NULL;
		}
	}
	coef = NULL;
}  

Objectives::Objectives()
{  
	#ifdef DEBUG
	cout << "Inside the Objectives Constructor" << endl; 
	#endif
	numberOfObjectives = 0;
	obj = NULL;
} 

Objectives::~Objectives(){ 
	#ifdef DEBUG 
	cout << "Inside the Objectives Destructor" << endl;
	#endif
	if(numberOfObjectives > 0 && obj != NULL){
		for(int i = 0; i < numberOfObjectives; i++){
			delete obj[i];
			obj[i] = NULL;
		}
	}
	obj = NULL;
}

Constraint::Constraint():
	name(""),
	constant(0.0),
	lb(-OSINFINITY),
	ub(OSINFINITY)

{
	#ifdef DEBUG  
	cout << "Inside the Constraint Constructor" << endl;
	#endif
} 

Constraint::~Constraint(){  
	#ifdef DEBUG
	cout << "Inside the Constraint Destructor" << endl;
	#endif
} 

Constraints::Constraints():
	numberOfConstraints(0),
	con(NULL)
{
	#ifdef DEBUG
	cout << "Inside the Constraints Constructor" << endl;
	#endif
} 

Constraints::~Constraints(){  
	#ifdef DEBUG
	cout << "Inside the Constraints Destructor" << endl;
	#endif
	if(numberOfConstraints > 0 && con != NULL){
		for(int i = 0; i < numberOfConstraints; i++){
			delete con[i];
			con[i] = NULL;
		}
	}
	con = NULL;
} 



LinearConstraintCoefficients::LinearConstraintCoefficients():
	numberOfValues(0) 
{ 
	#ifdef DEBUG 
	cout << "Inside the LinearConstraintCoefficients Constructor" << endl; 
	#endif
	start = new IntVector();
	rowIdx = new IntVector();
	colIdx = new IntVector();
	value = new DoubleVector();
} 


LinearConstraintCoefficients::~LinearConstraintCoefficients(){  
	#ifdef DEBUG
	cout << "Inside the LinearConstraintCoefficients Destructor" << endl; 
	#endif
	delete start;
	start = NULL;
	delete rowIdx;
	rowIdx = NULL;
	delete colIdx;
	colIdx = NULL;
	delete value;
	value = NULL;
}

QuadraticTerm::QuadraticTerm():

	idx(0),   
	idxOne(-1),
	idxTwo(-1),
	coef(0.0)

{
	#ifdef DEBUG  
	cout << "Inside the QuadraticTerm Constructor" << endl;
	#endif
} 


QuadraticTerm::~QuadraticTerm(){  
	#ifdef DEBUG
	cout << "Inside the QuadraticTerm Destructor" << endl;
	#endif
}



QuadraticCoefficients::QuadraticCoefficients():
	qTerm(NULL), 
	numberOfQuadraticTerms(0)  
{ 
	#ifdef DEBUG 
	cout << "Inside the QuadraticCoefficients Constructor" << endl;
	#endif
}//end QuadraticCoefficients() 


QuadraticCoefficients::~QuadraticCoefficients(){
	#ifdef DEBUG  
	cout << "Inside the QuadraticCoefficients Destructor" << endl;
	#endif
	if(numberOfQuadraticTerms > 0 && qTerm != NULL){
		for(int i = 0; i < numberOfQuadraticTerms; i++){
			delete qTerm[i];
			qTerm[i] = NULL;
		}
	}
	qTerm = NULL;  
}//end ~QuadraticCoefficients()  


Nl::Nl(){
	idx = 0;
	osExpressionTree = NULL;
	m_bDeleteExpressionTree = true;
}//end Nl

 
Nl::~Nl(){
	#ifdef DEBUG  
	cout << "Inside the Nl Destructor" << endl;
	#endif
	// don't delete the expression tree if we created a map of the expression
	// trees, otherwise we would destroy twice
	if( m_bDeleteExpressionTree == true) delete osExpressionTree;
	osExpressionTree = NULL;
}//end ~Nl



NonlinearExpressions::NonlinearExpressions():
	nl(NULL), 
	numberOfNonlinearExpressions(0)  
{ 
	#ifdef DEBUG 
	cout << "Inside the NonlinearExpressions Constructor" << endl;
	#endif
}//end NonlinearExpressions() 

NonlinearExpressions::~NonlinearExpressions(){
	#ifdef DEBUG  
	cout << "Inside the NonlinearExpressions Destructor" << endl;
	#endif
	if(numberOfNonlinearExpressions > 0 && nl != NULL){
		for(int i = 0; i < numberOfNonlinearExpressions; i++){
			delete nl[i];
			nl[i] = NULL;
		}
	}
	nl = NULL;  
}//end ~NonlinearExpressions()  



InstanceData::InstanceData(){ 
	#ifdef DEBUG 
	cout << "Inside the InstanceData Constructor" << endl;
	#endif 
	variables = new Variables();
	objectives = new Objectives();
	constraints = new Constraints();
	linearConstraintCoefficients = new LinearConstraintCoefficients();
	quadraticCoefficients = new QuadraticCoefficients();
	nonlinearExpressions = new NonlinearExpressions();
	
} 

InstanceData::~InstanceData(){  
	#ifdef DEBUG
	cout << "Inside the InstanceData Destructor" << endl; 
	#endif
	delete variables;
	variables = NULL;
	delete objectives;
	objectives = NULL;
	delete constraints;
	constraints = NULL;
	delete linearConstraintCoefficients;
	linearConstraintCoefficients = NULL;
	delete quadraticCoefficients;
	quadraticCoefficients = NULL;
	delete nonlinearExpressions;
	nonlinearExpressions = NULL;
	
} 

string OSInstance::getInstanceName(){
	if(  m_sInstanceName.length() <= 0){
		m_sInstanceName = instanceHeader->name;
	}
	return m_sInstanceName;
}//getInstanceName


string OSInstance::getInstanceSource(){
	if( m_sInstanceSource.length() <= 0){
		m_sInstanceSource = instanceHeader->source;
	}
	return m_sInstanceSource;
}//getInstanceSource

string OSInstance::getInstanceDescription(){
	if(m_sInstanceDescription.length() <= 0){
		m_sInstanceDescription = instanceHeader->description;
	}
	return m_sInstanceDescription;
}//getInstanceDescription

int OSInstance::getVariableNumber(){
	if(m_iVariableNumber == -1){
		m_iVariableNumber = instanceData->variables->numberOfVariables;
	}
	return m_iVariableNumber;
}//getVariableNumber

int OSInstance::getNumberOfNonlinearExpressions(){
	if(m_iNonlinearExpressionNumber == -1){
		m_iNonlinearExpressionNumber = instanceData->nonlinearExpressions->numberOfNonlinearExpressions;
	}
	return m_iNonlinearExpressionNumber;
}//getNumberOfNonlinearExpressions



bool OSInstance::processVariables() {
	if(m_bProcessVariables) return true;
	m_bProcessVariables = true;
	string vartype ="CBIS";
	int i = 0;
	int n = instanceData->variables->numberOfVariables;
	try{
		if(instanceData->variables->var == NULL) throw ErrorClass("no variables defined");
		if(instanceData->variables->var[0]->name.length() > 0 || instanceData->variables->var[n-1]->name.length() > 0){
			m_msVariableNames = new string[n];
			for(i = 0; i < n; i++) m_msVariableNames[i] = instanceData->variables->var[i]->name;
		}

		if(CommonUtil::ISOSNAN(instanceData->variables->var[ 0]->init) == false ){ 
			m_mdVariableInitialValues = new double[n];
			for(i = 0; i < n; i++) m_mdVariableInitialValues[i] = instanceData->variables->var[i]->init;
		}
		if((instanceData->variables->var[0]->initString.length() > 0)){
			m_msVariableInitialStringValues = new string[n];
			for(i = 0; i < n; i++) m_msVariableInitialStringValues[i] = instanceData->variables->var[i]->initString;
		}
		m_mcVariableTypes = new char[n];
		m_mdVariableLowerBounds = new double[n];
		m_mdVariableUpperBounds = new double[n];
		for(i = 0; i < n; i++){
			if(vartype.find(instanceData->variables->var[i]->type) == string::npos) throw ErrorClass("wrong variable type");
			m_mcVariableTypes[i] = instanceData->variables->var[i]->type;
			if(m_mcVariableTypes[i] == 'B') m_iNumberOfBinaryVariables++;
			if(m_mcVariableTypes[i] == 'I') m_iNumberOfIntegerVariables++;
			m_mdVariableLowerBounds[i] = instanceData->variables->var[i]->lb;
			m_mdVariableUpperBounds[i] = instanceData->variables->var[i]->ub;
		}
		return true;
	} //end try
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	} 
}//processVariables
	
string* OSInstance::getVariableNames() {
	processVariables();
	return m_msVariableNames;
}//getVariableNames	

double* OSInstance::getVariableInitialValues() {
	processVariables();
	return m_mdVariableInitialValues;
}//getVariableInitialValues

string* OSInstance::getVariableInitialStringValues() {
	processVariables();
	return m_msVariableInitialStringValues;
}//getVariableInitialStringValues

char* OSInstance::getVariableTypes() {
	processVariables();
	return m_mcVariableTypes;
}//getVariableTypes

int OSInstance::getNumberOfIntegerVariables() {
	processVariables();
	return m_iNumberOfIntegerVariables;
}//getNumberOfIntegerVariables

int OSInstance::getNumberOfBinaryVariables() {
	processVariables();
	return m_iNumberOfBinaryVariables;
}//getNumberOfBinaryVariables

double* OSInstance::getVariableLowerBounds() {
	processVariables();
	return m_mdVariableLowerBounds;
}//getVariableLowerBounds

double* OSInstance::getVariableUpperBounds() {
	processVariables();
	return m_mdVariableUpperBounds;
}//getVariableUpperBounds

int OSInstance::getObjectiveNumber(){
	if(m_iObjectiveNumber == -1){
		m_iObjectiveNumber = instanceData->objectives->numberOfObjectives;
	}
	return m_iObjectiveNumber;
}//getObjectiveNumber


bool OSInstance::processObjectives() {
	if(m_bProcessObjectives) return true;
	m_bProcessObjectives = true;
	int i = 0;
	int j = 0;
	if(instanceData == NULL || instanceData->objectives == NULL || instanceData->objectives->obj == NULL || instanceData->objectives->numberOfObjectives == 0) return true;
	int n = instanceData->objectives->numberOfObjectives;
	try{
		if(instanceData->objectives->obj[0]->name.length() > 0 || instanceData->objectives->obj[n-1]->name.length() > 0){
			m_msObjectiveNames = new string[n];
			for(i = 0; i < n; i++) m_msObjectiveNames[i] = instanceData->objectives->obj[i]->name;
		}
		m_msMaxOrMins = new string[n];
		m_miNumberOfObjCoef = new int[n];
		m_mdObjectiveConstants = new double[n];
		m_mdObjectiveWeights = new double[n];
		m_mObjectiveCoefficients = new SparseVector*[n];
		for(i = 0; i < n; i++) m_mObjectiveCoefficients[i] = new SparseVector(instanceData->objectives->obj[ j]->numberOfObjCoef);
		//for(i = 0; i < n; i++){
		//	m_mObjectiveCoefficients[i] = new SparseVector();
		//	m_mObjectiveCoefficients[i]->number = instanceData->objectives->obj[ j]->numberOfObjCoef;
		//}
		for(i = 0; i < n; i++){
			if((instanceData->objectives->obj[i]->maxOrMin.compare("max") != 0) && (instanceData->objectives->obj[i]->maxOrMin.compare("min") != 0 )) throw ErrorClass("wrong objective maxOrMin");
			m_msMaxOrMins[i] = instanceData->objectives->obj[i]->maxOrMin;
			m_miNumberOfObjCoef[i] = instanceData->objectives->obj[i]->numberOfObjCoef;
			m_mdObjectiveConstants[i] = instanceData->objectives->obj[i]->constant;
			m_mdObjectiveWeights[i] = instanceData->objectives->obj[i]->weight;
			if(instanceData->objectives->obj[i]->coef == NULL && m_miNumberOfObjCoef[i] != 0){
				throw ErrorClass("objective coefficient number inconsistent with objective coefficient array");
			}
			if(instanceData->objectives->obj[i]->coef != NULL){
				for(j = 0; j < m_mObjectiveCoefficients[i]->number; j++){
					m_mObjectiveCoefficients[i]->indexes[j] = instanceData->objectives->obj[i]->coef[j]->idx;
					m_mObjectiveCoefficients[i]->values[j] = instanceData->objectives->obj[i]->coef[j]->value;			
				}
			}
		} 		
		return true;
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	}
}//processObjectives

string* OSInstance::getObjectiveNames() {
	processObjectives();
	return m_msObjectiveNames;
}//getObjectiveNames

string* OSInstance::getObjectiveMaxOrMins() {
	processObjectives();
	return m_msMaxOrMins;
}//getObjectiveMaxOrMins

int* OSInstance::getObjectiveCoefficientNumbers(){
		processObjectives();
		return m_miNumberOfObjCoef;
	}//getObjectiveCoefficientNumbers

double* OSInstance::getObjectiveConstants() {
	processObjectives();
	return m_mdObjectiveConstants;
}//getObjectiveConstants

double* OSInstance::getObjectiveWeights() {
	processObjectives();
	return m_mdObjectiveWeights;
}//getObjectiveWeights

SparseVector** OSInstance::getObjectiveCoefficients() {
	processObjectives();
	return m_mObjectiveCoefficients;
}//getObjectiveCoefficients


double** OSInstance::getDenseObjectiveCoefficients() {
	if(m_bGetDenseObjectives) return m_mmdDenseObjectiveCoefficients;
	m_bGetDenseObjectives = true;
	if(instanceData->objectives->obj == NULL || instanceData->objectives->numberOfObjectives == 0) return m_mmdDenseObjectiveCoefficients;
	int m = instanceData->objectives->numberOfObjectives;
	int n = instanceData->variables->numberOfVariables;
	m_mmdDenseObjectiveCoefficients = new double*[m];
	int i, j, numobjcoef;
	SparseVector *sparsevec;
	for(i = 0; i < m; i++){
		sparsevec = this->getObjectiveCoefficients()[i];
		m_mmdDenseObjectiveCoefficients[ i] = new double[n];
		for(j = 0; j < n; j++){
			m_mmdDenseObjectiveCoefficients[ i][j] = 0.0;
		}
		sparsevec =  this->getObjectiveCoefficients()[i];
		numobjcoef = sparsevec->number;
		for(j = 0; j < numobjcoef; j++){
			m_mmdDenseObjectiveCoefficients[i][ sparsevec->indexes[ j]]
			= sparsevec->values[ j];
		}
	}
	return m_mmdDenseObjectiveCoefficients;
}//getDenseObjectiveCoefficients

int OSInstance::getConstraintNumber(){
	if(m_iConstraintNumber == -1){
		m_iConstraintNumber = instanceData->constraints->numberOfConstraints;
	}
	return m_iConstraintNumber;
}//getConstraintNumber

bool OSInstance::processConstraints() {
	if(m_bProcessConstraints) return true;
	m_bProcessConstraints = true;
	int i = 0;
	ostringstream outStr;
	if(instanceData == NULL || instanceData->constraints == NULL || instanceData->constraints->con == NULL || instanceData->constraints->numberOfConstraints == 0) return true;
	int n = instanceData->constraints->numberOfConstraints;
	try{
		if(instanceData->constraints->con[0]->name.length() > 0 || instanceData->constraints->con[n-1]->name.length() > 0){
			m_msConstraintNames = new string[n];
			for(i = 0; i < n; i++) m_msConstraintNames[i] = instanceData->constraints->con[i]->name;
		}
		m_mdConstraintLowerBounds = new double[n];
		m_mdConstraintUpperBounds = new double[n];
		m_mdConstraintConstants = new double[n];
		m_mcConstraintTypes = new char[n];
		for(i = 0; i < n; i++){
			m_mdConstraintLowerBounds[i] = instanceData->constraints->con[i]->lb;
			m_mdConstraintUpperBounds[i] = instanceData->constraints->con[i]->ub;
			m_mdConstraintConstants[i] = instanceData->constraints->con[i]->constant;
			if(m_mdConstraintLowerBounds[i] == OSINFINITY || m_mdConstraintUpperBounds[i] == -OSINFINITY) {
				throw ErrorClass( outStr.str() );
			}
			else if(m_mdConstraintLowerBounds[i] > m_mdConstraintUpperBounds[i]) {
				outStr << "Constraint  " ;
				outStr << i;
				outStr << " is infeasible";
				throw ErrorClass( outStr.str());
			}
			else if(m_mdConstraintLowerBounds[i] == -OSINFINITY && m_mdConstraintUpperBounds[i] == OSINFINITY)
				m_mcConstraintTypes[i] = 'U';
			else if(m_mdConstraintLowerBounds[i] == m_mdConstraintUpperBounds[i]) 
				m_mcConstraintTypes[i] = 'E';
			else if(m_mdConstraintLowerBounds[i] == -OSINFINITY)
				m_mcConstraintTypes[i] = 'L';
			else if(m_mdConstraintUpperBounds[i] == OSINFINITY)
				m_mcConstraintTypes[i] = 'G';
			else m_mcConstraintTypes[i] = 'R';
		}
		return true;
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	}
}//processConstraints


string* OSInstance::getConstraintNames() {
	processConstraints();
	return m_msConstraintNames;
}//getConstraintNames


double* OSInstance::getConstraintLowerBounds() {
	processConstraints();
	return m_mdConstraintLowerBounds;
}//getConstraintLowerBounds

char* OSInstance::getConstraintTypes() {
	processConstraints();
	return m_mcConstraintTypes;
}//getConstraintTypes

double* OSInstance::getConstraintUpperBounds() {
	processConstraints();
	return m_mdConstraintUpperBounds;
}//getConstraintUpperBounds

int OSInstance::getLinearConstraintCoefficientNumber(){
	if(m_iLinearConstraintCoefficientNumber == -1){
		m_iLinearConstraintCoefficientNumber = instanceData->linearConstraintCoefficients->numberOfValues;
	}
	return m_iLinearConstraintCoefficientNumber; 
}//getLinearConstraintCoefficientNumber

bool OSInstance::processLinearConstraintCoefficients() {
	if(m_bProcessLinearConstraintCoefficients) return true;
	m_bProcessLinearConstraintCoefficients = true;
	try{
		int n = instanceData->linearConstraintCoefficients->numberOfValues;
		//value array
		if((instanceData->linearConstraintCoefficients->value == NULL ) || (n == 0) ) return true;
		//index array
		if((instanceData->linearConstraintCoefficients->colIdx != NULL && instanceData->linearConstraintCoefficients->colIdx->el != NULL) 
		&& (instanceData->linearConstraintCoefficients->rowIdx != NULL && instanceData->linearConstraintCoefficients->rowIdx->el != NULL))
			throw ErrorClass("ambiguous linear constraint coefficient major");
		else if(instanceData->linearConstraintCoefficients->value->el == NULL) return true;
		else{
			if(instanceData->linearConstraintCoefficients->rowIdx->el != NULL){
				m_bColumnMajor = true;
				m_linearConstraintCoefficientsInColumnMajor = new SparseMatrix();
				m_linearConstraintCoefficientsInColumnMajor->isColumnMajor = true;
				m_linearConstraintCoefficientsInColumnMajor->valueSize = n;
				m_linearConstraintCoefficientsInColumnMajor->startSize = instanceData->variables->numberOfVariables + 1;
			}
			else{ 
				m_bColumnMajor = false;	
				m_linearConstraintCoefficientsInRowMajor = new SparseMatrix();
				m_linearConstraintCoefficientsInRowMajor->isColumnMajor = false;
				m_linearConstraintCoefficientsInRowMajor->valueSize = n;
				m_linearConstraintCoefficientsInRowMajor->startSize = instanceData->constraints->numberOfConstraints + 1;
			}
		}			
		if(m_bColumnMajor == true){
			m_linearConstraintCoefficientsInColumnMajor->values = instanceData->linearConstraintCoefficients->value->el;
			m_linearConstraintCoefficientsInColumnMajor->indexes = instanceData->linearConstraintCoefficients->rowIdx->el;
			m_linearConstraintCoefficientsInColumnMajor->starts = instanceData->linearConstraintCoefficients->start->el;			
		}
		else{
			m_linearConstraintCoefficientsInRowMajor->values = instanceData->linearConstraintCoefficients->value->el;
			m_linearConstraintCoefficientsInRowMajor->indexes = instanceData->linearConstraintCoefficients->colIdx->el;
			m_linearConstraintCoefficientsInRowMajor->starts = instanceData->linearConstraintCoefficients->start->el;						
		}
		return true;
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	}
}//processLinearConstraintCoefficients

bool OSInstance::getLinearConstraintCoefficientMajor() {
	processLinearConstraintCoefficients();	
	return m_bColumnMajor; 		
}//getLinearConstraintCoefficientMajor

SparseMatrix* OSInstance::getLinearConstraintCoefficientsInColumnMajor() {
	processLinearConstraintCoefficients();
	if(m_linearConstraintCoefficientsInColumnMajor != NULL) return m_linearConstraintCoefficientsInColumnMajor;
	if(!m_bColumnMajor){
		if(m_linearConstraintCoefficientsInRowMajor == NULL) return NULL;
		m_linearConstraintCoefficientsInColumnMajor = 
			MathUtil::convertLinearConstraintCoefficientMatrixToTheOtherMajor(false,
					  m_linearConstraintCoefficientsInRowMajor->startSize,
					  m_linearConstraintCoefficientsInRowMajor->valueSize,
					  m_linearConstraintCoefficientsInRowMajor->starts,
					  m_linearConstraintCoefficientsInRowMajor->indexes,
					  m_linearConstraintCoefficientsInRowMajor->values,
					  getVariableNumber());
	}
	return m_linearConstraintCoefficientsInColumnMajor; 		
}//getLinearConstraintCoefficientsInColumnMajor

SparseMatrix* OSInstance::getLinearConstraintCoefficientsInRowMajor() {
	processLinearConstraintCoefficients();
	if(m_linearConstraintCoefficientsInRowMajor != NULL) return m_linearConstraintCoefficientsInRowMajor;
	if(m_bColumnMajor){
		if(m_linearConstraintCoefficientsInColumnMajor == NULL) return NULL;
		m_linearConstraintCoefficientsInRowMajor = 
		MathUtil::convertLinearConstraintCoefficientMatrixToTheOtherMajor(true,
				  m_linearConstraintCoefficientsInColumnMajor->startSize,
				  m_linearConstraintCoefficientsInColumnMajor->valueSize,
				  m_linearConstraintCoefficientsInColumnMajor->starts,
				  m_linearConstraintCoefficientsInColumnMajor->indexes,
				  m_linearConstraintCoefficientsInColumnMajor->values,
				  getConstraintNumber());
	}
	return m_linearConstraintCoefficientsInRowMajor; 
}//getLinearConstraintCoefficientsInRowMajor


int OSInstance::getNumberOfQuadraticTerms(){
	if(m_iQuadraticTermNumber == -1){
	// if m_iQuadraticTermNumber == -1 then the parser did not find any q terms so 
	// must new the object
		if(instanceData->quadraticCoefficients == NULL)instanceData->quadraticCoefficients = new QuadraticCoefficients();
		m_iQuadraticTermNumber = instanceData->quadraticCoefficients->numberOfQuadraticTerms;
	}
	return m_iQuadraticTermNumber;
}//getNumberOfQuadraticTerms

QuadraticTerms* OSInstance::getQuadraticTerms() {
	if(m_bProcessQuadraticTerms) return m_quadraticTerms;
	m_bProcessQuadraticTerms = true;
	if(instanceData->quadraticCoefficients->qTerm == 0) return 0;
	try{
		int i = 0;
		QuadraticCoefficients* quadraticCoefs = instanceData->quadraticCoefficients;
		int n = quadraticCoefs->numberOfQuadraticTerms;
		if(!quadraticCoefs->qTerm  && n != 0) 
			throw ErrorClass("quadratic term number inconsistent with quadratic term array");		
		m_quadraticTerms = new QuadraticTerms();
		m_quadraticTerms->rowIndexes = new int[n];
		m_quadraticTerms->varOneIndexes = new int[n];
		m_quadraticTerms->varTwoIndexes = new int[n];
		m_quadraticTerms->coefficients = new double[n];
		for(i = 0; i < n; i++){
			m_quadraticTerms->rowIndexes[i] = quadraticCoefs->qTerm[i]->idx;
			m_quadraticTerms->varOneIndexes[i] = quadraticCoefs->qTerm[i]->idxOne;
			m_quadraticTerms->varTwoIndexes[i] = quadraticCoefs->qTerm[i]->idxTwo;
			m_quadraticTerms->coefficients[i] = quadraticCoefs->qTerm[i]->coef;
		} 
		return m_quadraticTerms;
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	} 
}//getQuadraticTerms

int OSInstance::getNumberOfNonlinearConstraints(){
	if( m_bProcessExpressionTrees == false ){
		getAllNonlinearExpressionTrees();
		return m_iConstraintNumberNonlinear;
	}
	else return m_iConstraintNumberNonlinear;
}//getNumberOfNonlinearConstraints

int OSInstance::getNumberOfNonlinearObjectives(){
	if( m_bProcessExpressionTrees == false ){
		getAllNonlinearExpressionTrees();
		return m_iObjectiveNumberNonlinear;
	}
	else return m_iObjectiveNumberNonlinear;
}//getNumberOfNonlinearObjectivess


OSExpressionTree* OSInstance::getNonlinearExpressionTree(int rowIdx){
	if( m_bProcessExpressionTrees == false ){
		getAllNonlinearExpressionTrees();
		return m_mapExpressionTrees[ rowIdx];
	}
	else{
		if( m_mapExpressionTrees.find( rowIdx) != m_mapExpressionTrees.end()) return NULL;
		else return m_mapExpressionTrees[ rowIdx];
		// check to make sure rowIdx has a nonlinear term and is in the map
		/** define an iterator for the expression trees map allExpTrees */
		//std::map<int, OSExpressionTree*>::iterator pos;
		///for(pos = m_mapExpressionTrees.begin(); pos != m_mapExpressionTrees.end(); ++pos){
		//	if(pos->first == rowIdx)return m_mapExpressionTrees[ rowIdx];
		//}
		// if we are rowIdx has no nonlinar terms so return a null
		//return NULL;
	}  
}// getNonlinearExpresssionTree for a specific index

std::map<int, OSExpressionTree*> OSInstance::getAllNonlinearExpressionTrees(){
	if(m_bProcessExpressionTrees == true) return m_mapExpressionTrees;
	std::map<int, int> foundIdx;
	std::map<int, int>::iterator pos;
	OSnLNodePlus *nlNodePlus;
	OSExpressionTree *expTree;
	m_iObjectiveNumberNonlinear = 0;
	m_iConstraintNumberNonlinear = 0;
	int i;
	int index;
	for(i = 0; i < instanceData->nonlinearExpressions->numberOfNonlinearExpressions; i++){
		index = instanceData->nonlinearExpressions->nl[ i]->idx;
		//if(foundIdx.find( index) != foundIdx.end() ){ 
		if(foundIdx[ index] > 0 ){ 
			nlNodePlus = new OSnLNodePlus();
			expTree = new OSExpressionTree();
			// set left child to old index and right child to new one
			nlNodePlus->m_mChildren[ 0] = m_mapExpressionTrees[ index]->m_treeRoot;
			nlNodePlus->m_mChildren[ 1] = instanceData->nonlinearExpressions->nl[ i]->osExpressionTree->m_treeRoot;
			m_mapExpressionTrees[ index] = expTree;
			m_mapExpressionTrees[ index]->m_treeRoot = nlNodePlus;
		}
		else{
			// we have a new index
			m_mapExpressionTrees[ index] = instanceData->nonlinearExpressions->nl[ i]->osExpressionTree;
			m_mapExpressionTrees[ index]->m_treeRoot = instanceData->nonlinearExpressions->nl[ i]->osExpressionTree->m_treeRoot;
		}
		foundIdx[ index]++;	
	}
	// count the number of constraints and objective functions with nonlinear terms.
	for(pos = foundIdx.begin(); pos != foundIdx.end(); ++pos){
		if(pos->first == -1) {
			m_iObjectiveNumberNonlinear++;
		}
		else m_iConstraintNumberNonlinear++;
	}
	foundIdx.clear();
	m_bProcessExpressionTrees = true;
	// important -- tell the nl nodes not to destroy the OSExpression Objects
	if( instanceData->nonlinearExpressions->numberOfNonlinearExpressions > 0 && instanceData->nonlinearExpressions->nl != NULL){
		for(int i = 0; i < instanceData->nonlinearExpressions->numberOfNonlinearExpressions; i++){
			instanceData->nonlinearExpressions->nl[i]->m_bDeleteExpressionTree = false;
		}
	}
	return m_mapExpressionTrees;
}// getAllNonlinearExpresssionTrees

/*
std::map<int, std::vector<OSnLNode*> > OSInstance::getAllNonlinearExpressionTreesInPostfix(){
	std::map<int, int> foundIdx;
	std::map<int, int>::iterator pos;
	OSnLNodePlus *nlNodePlus;
	std::vector<OSnLNode*> vPostFixTmp;
	m_iObjectiveNumberNonlinear = 0;
	m_iConstraintNumberNonlinear = 0;
	int i, j;
	int index;
	for(i = 0; i < instanceData->nonlinearExpressions->numberOfNonlinearExpressions; i++){
		index = instanceData->nonlinearExpressions->nl[ i]->idx;
		cout << "INDEX = " << index << endl;
		cout << "VALUE = " << foundIdx[ index] << endl;
		vPostFixTmp = instanceData->nonlinearExpressions->nl[ i]->osExpressionTree->getPostfix();
		for(j = 0; j < vPostFixTmp.size(); j++){
			m_mapExpressionTreesInPostfix[ index].push_back( vPostFixTmp[j] );
		}
		if(foundIdx[ index] > 0){ 
			nlNodePlus = new OSnLNodePlus();
			m_mapExpressionTreesInPostfix[ index].push_back( nlNodePlus );
		}
		foundIdx[ index]++;	
	}
	// count the number of constraints and objective functions with nonlinear terms.
	for(pos = foundIdx.begin(); pos != foundIdx.end(); ++pos){
		cout << "POSITION " << pos->first << endl;
		if(pos->first == -1) {
			m_iObjectiveNumberNonlinear++;
		}
		else m_iConstraintNumberNonlinear++;
	}
	m_bProcessExpressionTreesInPostfix = true;
	return m_mapExpressionTreesInPostfix;
}// getAllNonlinearExpresssionTreesInPostfix
*/


/*
std::vector<OSnLNode*> OSInstance::getNonlinearExpressionTreeInPostfix(int rowIdx){
	if( m_bProcessExpressionTreesInPostfix == false ){
		getAllNonlinearExpressionTreesInPostfix();
		return m_mapExpressionTreesInPostfix[ rowIdx];
	}
	else return m_mapExpressionTreesInPostfix[ rowIdx];
}// getNonlinearExpresssionTreeInPostfix
*/

// the set() methods

bool OSInstance::setInstanceSource(string source){
	instanceHeader->source = source;
	return true;
}//setInstanceSource

bool OSInstance::setInstanceDescription(string description){
	instanceHeader->description = description;
	return true;
}//setInstanceDescription


bool OSInstance::setInstanceName(string name){
	 instanceHeader->name = name;
	 return true;
}//setInstanceName


bool OSInstance::setVariableNumber(int number){
	// this method assume osinstance->instanceData->variables is not null
	if(number <= 0) return false;
	if(instanceData->variables->numberOfVariables != -1  && instanceData->variables->numberOfVariables != number){
		delete[] instanceData->variables->var;
		instanceData->variables->var = NULL;
	} 
	instanceData->variables->numberOfVariables = number;
	if(instanceData->variables->var == NULL){
		instanceData->variables->var = new Variable*[number];
	}
	return true;
}//setVariableNumber


bool OSInstance::addVariable(int index, string name, double lowerBound, double upperBound, char type, double init, string initString){
	instanceData->variables->var[index] = new Variable();
	if(index < 0 || instanceData->variables->numberOfVariables <= 0 || index >= instanceData->variables->numberOfVariables) return false;
	instanceData->variables->var[index]->name = name;
	if(lowerBound != -OSINFINITY && lowerBound != -OSDBL_MAX)instanceData->variables->var[index]->lb = lowerBound;
	if(upperBound != OSINFINITY && upperBound != OSDBL_MAX)instanceData->variables->var[index]->ub = upperBound;
	instanceData->variables->var[index]->type = type;
	if(init != OSNAN) instanceData->variables->var[index]->init = init;
	instanceData->variables->var[index]->initString = initString;
	return true;
}//addVariable


bool OSInstance::setVariables(int number, string *names, double *lowerBounds, 
	double *upperBounds, char *types, double *inits, string *initsString){
	if(number <= 0) return false;
	if(instanceData->variables == NULL) instanceData->variables = new Variables();
	instanceData->variables->numberOfVariables = number;
	instanceData->variables->var = new Variable*[number];
	int i;
	for(i = 0; i < number; i++){
		instanceData->variables->var[ i] = new Variable();
	}
	if(names  != NULL){
		for(i = 0; i < number; i++) instanceData->variables->var[i]->name = names[i];   			
	}
	if(lowerBounds != NULL){
		for(i = 0; i < number; i++){
			if(lowerBounds[i] != -OSINFINITY && lowerBounds[i] != -OSDBL_MAX)instanceData->variables->var[i]->lb = lowerBounds[i];  
		}
	}
	if(upperBounds != NULL){
		for(i = 0; i < number; i++){
			if(upperBounds[i] != OSINFINITY && upperBounds[i] != OSDBL_MAX)instanceData->variables->var[i]->ub = upperBounds[i]; 
		}
	}
	if(types != NULL){
		for(i = 0; i < number; i++){
			instanceData->variables->var[i]->type = types[i];
			if(types[i] != 'C' && types[i] != 'B' && types[i] != 'I' && types[i] != 'S') types[i] = 'C';
		}
	}
	if(inits != NULL){
		for(i = 0; i < number; i++) instanceData->variables->var[i]->init = inits[i];   			
	}
	if(initsString != NULL){
		for(i = 0; i < number; i++) instanceData->variables->var[i]->initString = initsString[i];   			
	}
	return true;
}//setVariables

// begin checking again with Jun Ma

bool OSInstance::setObjectiveNumber(int number){
	if(number < 0) return false;
	if(instanceData->objectives == NULL) instanceData->objectives = new Objectives();
	if(number == 0){
		instanceData->objectives->numberOfObjectives = 0;
		instanceData->objectives->obj = 0;
		return true;
	}
	instanceData->objectives->numberOfObjectives = number;
	instanceData->objectives->obj = new Objective*[number];  			
	return true;
}//setObjectiveNumber

bool OSInstance::addObjective(int index, string name, string maxOrMin, double constant, double weight, SparseVector *objectiveCoefficients){
	if(index >= 0 || instanceData->objectives->numberOfObjectives <= 0 || abs(index) > instanceData->objectives->numberOfObjectives) return false;
	int arrayIndex = abs(index) -1;
	if(instanceData->objectives->obj == NULL) return false;
	instanceData->objectives->obj[arrayIndex] = new Objective();
	instanceData->objectives->obj[arrayIndex]->name = name;
	if( (maxOrMin != "max") && (maxOrMin != "min") ) return false;
	else instanceData->objectives->obj[arrayIndex]->maxOrMin = maxOrMin;
	instanceData->objectives->obj[arrayIndex]->constant = constant;
	instanceData->objectives->obj[arrayIndex]->weight = weight;
	int n = objectiveCoefficients->number;   		
	instanceData->objectives->obj[arrayIndex]->numberOfObjCoef = n;
	if(n == 0){
		instanceData->objectives->obj[arrayIndex]->coef = 0;
	}
	else{
		int i = 0;
		instanceData->objectives->obj[arrayIndex]->coef = new ObjCoef*[n];
		for(i = 0; i < n; i++) instanceData->objectives->obj[arrayIndex]->coef[i] = new ObjCoef();
		for(i = 0; i < n; i++){
			instanceData->objectives->obj[arrayIndex]->coef[i]->idx = objectiveCoefficients->indexes[i];
			instanceData->objectives->obj[arrayIndex]->coef[i]->value = objectiveCoefficients->values[i];   
		}   			
	}
	return true;
}//addObjective

bool OSInstance::setObjectives(int number, string *names, string *maxOrMins, double *constants, double *weights, SparseVector **objectiveCoefficients){
	if(number < 0) return false;
	if(number == 0){
		instanceData->objectives = new Objectives();
		instanceData->objectives->numberOfObjectives = 0;
		instanceData->objectives->obj = NULL;
		return true;
	}
	
	instanceData->objectives->numberOfObjectives = number;
	instanceData->objectives->obj = new Objective*[number];
	int i = 0;
	for(int i = 0; i < number; i++)instanceData->objectives->obj[i] = new Objective();
	int j = 0;
	if(names != NULL){
		for(i = 0; i < number; i++) instanceData->objectives->obj[i]->name = names[i];   			
	}	
	if(maxOrMins != NULL){
		for(i = 0; i < number; i++){
			if(maxOrMins[i] == "" || (maxOrMins[i].compare("max") != 0 && maxOrMins[i].compare("min") !=0)) return false;
			instanceData->objectives->obj[i]->maxOrMin = maxOrMins[i];   			
		}
	}
	if(constants != NULL){
		for(i = 0; i < number; i++) instanceData->objectives->obj[i]->constant = constants[i];   			
	}
	if(weights != NULL){
		for(i = 0; i < number; i++) instanceData->objectives->obj[i]->weight = weights[i];   			
	}
	if(objectiveCoefficients != NULL){
		for(i = 0; i < number; i++){
			int n = (&objectiveCoefficients[i] == NULL || objectiveCoefficients[i]->indexes == NULL)?0:objectiveCoefficients[i]->number;   		
			instanceData->objectives->obj[i]->numberOfObjCoef = n;
			if(n == 0){
				instanceData->objectives->obj[i]->coef = NULL;
			}
			else{
				instanceData->objectives->obj[i]->coef = new ObjCoef*[n];
				for(j = 0; j < n; j++){
					instanceData->objectives->obj[i]->coef[j] = new ObjCoef();
					instanceData->objectives->obj[i]->coef[j]->idx  = objectiveCoefficients[i]->indexes[j];
					instanceData->objectives->obj[i]->coef[j]->value = objectiveCoefficients[i]->values[j];   			
				}   			
			}   			   				
		}
	}
	return true;
}//setObjectives


bool OSInstance::setConstraintNumber(int number){
	if(number < 0) return false;
	if(instanceData->constraints == NULL) instanceData->constraints = new Constraints();
	if(number == 0){
		instanceData->constraints = new Constraints();
		instanceData->constraints->numberOfConstraints = 0;
		instanceData->constraints->con = 0;
		return true;
	}
	instanceData->constraints->numberOfConstraints = number;
	if(instanceData->constraints->con == 0 ){
		instanceData->constraints->con = new Constraint*[number];
	}
	return true;
}//setConstraintNumber

bool OSInstance::addConstraint(int index, string name, double lowerBound, double upperBound, double constant) {
	instanceData->constraints->con[ index] = new Constraint();
	if(index < 0 || instanceData->constraints->numberOfConstraints <= 0 || index >= instanceData->constraints->numberOfConstraints) return false;
	instanceData->constraints->con[ index]->name = name;
	if(lowerBound != -OSINFINITY && lowerBound != -OSDBL_MAX) instanceData->constraints->con[ index]->lb = lowerBound;
	if(upperBound != OSINFINITY && upperBound != OSDBL_MAX)instanceData->constraints->con[ index]->ub = upperBound;
	instanceData->constraints->con[ index]->constant = constant;
	return true;
}//addConstraint


bool OSInstance::setConstraints(int number, string* names, double* lowerBounds, double* upperBounds, double* constants){
	if(number < 0) return false;
	if(number == 0){
		instanceData->constraints = new Constraints();
		instanceData->constraints->numberOfConstraints = 0;
		instanceData->constraints->con = NULL;
		return true;
	}
	instanceData->constraints->numberOfConstraints = number;
	instanceData->constraints->con = new Constraint*[number];
	int i = 0;
	for(i = 0; i < number; i++){
		instanceData->constraints->con[i] = new Constraint();
	}
	if(names != NULL){
		for(i = 0; i < number; i++) instanceData->constraints->con[i]->name = names[i];   			
	}
	if(lowerBounds != NULL){
		for(i = 0; i < number; i++){
			if(lowerBounds[i] != -OSINFINITY && lowerBounds[i] != -OSDBL_MAX)instanceData->constraints->con[i]->lb = lowerBounds[i]; 
		}
	}
	if(upperBounds != NULL){
		for(i = 0; i < number; i++){
			if(upperBounds[i] != OSINFINITY && upperBounds[i] != OSDBL_MAX)instanceData->constraints->con[i]->ub = upperBounds[i]; 
		}
	}   
	if(constants != NULL){
		for(i = 0; i < number; i++) instanceData->constraints->con[i]->constant = constants[i];   			
	}
	return true;
}//setConstraints

bool OSInstance::setLinearConstraintCoefficients(int numberOfValues, bool isColumnMajor, 
		double* values, int valuesBegin, int valuesEnd, 
		int* indexes, int indexesBegin, int indexesEnd,   			
		int* starts, int startsBegin, int startsEnd){
		if(numberOfValues < 0) return false;
	if(instanceData->linearConstraintCoefficients == NULL) instanceData->linearConstraintCoefficients = new LinearConstraintCoefficients() ;
	if(numberOfValues == 0) return true;
	if((values == 0 ) ||
	   (valuesBegin < 0 || (valuesEnd - valuesBegin + 1) != numberOfValues) ||
	   (indexes == 0) ||
	   (indexesBegin < 0 || (indexesEnd - indexesBegin + 1) != numberOfValues) ||
	   (starts == 0 ) ||
	   (startsBegin < 0  || startsBegin >= startsEnd)) return false;
	instanceData->linearConstraintCoefficients->numberOfValues = numberOfValues;
	int i = 0;
	//starts
	if(instanceData->linearConstraintCoefficients->start == NULL) instanceData->linearConstraintCoefficients->start = new IntVector();
	if(startsBegin == 0 ){
		instanceData->linearConstraintCoefficients->start->el = starts;
	}
	else{
		instanceData->linearConstraintCoefficients->start->el = new int[startsEnd - startsBegin + 1];
		int k = 0;
		for(i = startsBegin; i <= startsEnd; i++){
			instanceData->linearConstraintCoefficients->start->el[k] = starts[i];
			k++;
		}
	}		 
	//values
	if(instanceData->linearConstraintCoefficients->value == NULL) instanceData->linearConstraintCoefficients->value = new DoubleVector();
	if(valuesBegin == 0 ){
		instanceData->linearConstraintCoefficients->value->el = values;
	}
	else{
		instanceData->linearConstraintCoefficients->value->el = new double[numberOfValues];
		int k = 0;
		for(i = valuesBegin; i <= valuesEnd; i++){
			instanceData->linearConstraintCoefficients->value->el[k] = values[i];
			k++;
		}
	}
	//indexes
	if(instanceData->linearConstraintCoefficients->rowIdx == NULL) instanceData->linearConstraintCoefficients->rowIdx = new IntVector();
	if(instanceData->linearConstraintCoefficients->colIdx == NULL) instanceData->linearConstraintCoefficients->colIdx = new IntVector();
	if(isColumnMajor){
		if(indexesBegin == 0 ){
			instanceData->linearConstraintCoefficients->rowIdx->el = indexes;
		}
		else{
			instanceData->linearConstraintCoefficients->rowIdx->el = new int[numberOfValues];
			int k = 0;
			for(i = indexesBegin; i <= indexesEnd; i++){
				instanceData->linearConstraintCoefficients->rowIdx->el[k] = indexes[i];
				k++;
			}
		}
	} 
	else{
		if(indexesBegin == 0 ){
			instanceData->linearConstraintCoefficients->colIdx->el = indexes;
		}
		else{
			instanceData->linearConstraintCoefficients->colIdx->el = new int[numberOfValues];
			int k = 0;
			for(i = indexesBegin; i <= indexesEnd; i++){
				instanceData->linearConstraintCoefficients->colIdx->el[k] = indexes[i];
				k++;
			}
		}
	}
	return true;
}//setLinearConstraintCoefficients

bool OSInstance::setQuadraticTerms(int number, 
		int* rowIndexes, int* varOneIndexes, int* varTwoIndexes, double* coefficients,
		int begin, int end){
	if(number < 0) return false;
	if(number == 0){
		instanceData->quadraticCoefficients = 0;
		return true;
	}
	if( ((end - begin + 1) != number) ||
	   (rowIndexes == 0) ||   		   
	   (varOneIndexes == 0) ||
	   (varTwoIndexes == 0) ||
	   (coefficients == 0) ) return false;
	instanceData->quadraticCoefficients = new QuadraticCoefficients();
	instanceData->quadraticCoefficients->numberOfQuadraticTerms = number;
	int i = 0;
	instanceData->quadraticCoefficients->qTerm = new QuadraticTerm*[number];
	for(i = 0; i < number; i++) instanceData->quadraticCoefficients->qTerm[i] = new QuadraticTerm();
	// Kipp: check logic below -- looks weird what is the k for???
	int k = 0;
	for(i = begin; i <= end; i++){
			instanceData->quadraticCoefficients->qTerm[k]->idx = rowIndexes[i];
			instanceData->quadraticCoefficients->qTerm[k]->idxOne = varOneIndexes[i];
			instanceData->quadraticCoefficients->qTerm[k]->idxTwo = varTwoIndexes[i];
			instanceData->quadraticCoefficients->qTerm[k]->coef = coefficients[i];
			k++;
	}
	return true;
}//setQuadraticTerms



SparseJacobianMatrix *OSInstance::getSparseJacobian( ){
	if( m_bSparseJacobianCalculated == true) return m_sparseJacMatrix;
	if( m_bProcessObjectives == false) processObjectives();
	if( m_bProcessConstraints == false) processConstraints();
	// get all of the expression trees
	if( m_bProcessExpressionTrees == false) getAllNonlinearExpressionTrees();
	// before proceeding get a copy of the map of the Expression Trees
	if( m_bDuplicateExpressionTreesMap == false) duplicateExpressionTreesMap();
	getDenseObjectiveCoefficients();
	addQTermsToExressionTree();
	m_mdConstraintFunctionValues = new double[ this->instanceData->constraints->numberOfConstraints];
	m_mdObjectiveFunctionValues = new double[ this->instanceData->objectives->numberOfObjectives];
	m_mdObjGradient = new double[ this->instanceData->variables->numberOfVariables];
	if( m_bColumnMajor == true) getSparseJacobianFromColumnMajor( );
	else getSparseJacobianFromRowMajor( );
	// now fill in the arrays of the sparseJacMatrix
	m_sparseJacMatrix = new SparseJacobianMatrix();
	m_sparseJacMatrix->starts = m_miJacStart;
	m_sparseJacMatrix->conVals = m_miJacNumConTerms;
	m_sparseJacMatrix->indexes = m_miJacIndex;
	m_sparseJacMatrix->values = m_mdJacValue;
	m_bSparseJacobianCalculated = true;
	return m_sparseJacMatrix;
}//getSparseJacobian

bool OSInstance::addQTermsToExressionTree(){
	int i, k, idx;
	// get the number of qTerms
	int numQTerms = instanceData->quadraticCoefficients->numberOfQuadraticTerms;	
	if(numQTerms <= 0) return true;
	OSnLNodeVariable* nlNodeVariableOne;
	OSnLNodeVariable* nlNodeVariableTwo;
	OSnLNodeTimes* nlNodeTimes;
	OSnLNodePlus* nlNodePlus;
	OSExpressionTree* expTree;
	getQuadraticTerms();	
	std::cout << "PROCESSING QUADRATIC TERMS" << std::endl;
	for(i = 0; i < numQTerms; i++){
		idx = m_quadraticTerms->rowIndexes[ i];
		std::cout << "PROCESSING QTERM  = "  << i <<std::endl;
		// see if row idx is in the expression tree
		if( m_mapExpressionTreesMod.find( idx) != m_mapExpressionTreesMod.end() ) {
			// row idx is in the expression tree
			// add the qTerm in row idx  to the expression tree	
			// define two new OSnLVariable nodes, an OSnLnodeTimes, and OSnLnodePlus 
			nlNodeVariableOne = new OSnLNodeVariable();
			nlNodeVariableOne->idx = m_quadraticTerms->varOneIndexes[ i];
			// see if the variable indexed by nlNodeVariableOne->idx is in the expression tree for row idx
			// if not, add to mapVarIdx
			if( (*m_mapExpressionTreesMod[ idx]->mapVarIdx).find( nlNodeVariableOne->idx) == (*m_mapExpressionTreesMod[ idx]->mapVarIdx).end()  ){
				// add to map
				k = (*m_mapExpressionTreesMod[ idx]->mapVarIdx).size();
				(*m_mapExpressionTreesMod[ idx]->mapVarIdx)[ nlNodeVariableOne->idx] =  k + 1;
				std::cout << "ADDED THE FOLLOWING VAIRABLE TO THE MAP" <<  nlNodeVariableOne->idx << std::endl;
			}
			nlNodeVariableOne->coef = m_quadraticTerms->coefficients[ i];
			nlNodeVariableTwo = new OSnLNodeVariable();
			nlNodeVariableTwo->idx = m_quadraticTerms->varTwoIndexes[ i];
			// see if the variable indexed by nlNodeVariableTwo->idx is in the expression tree for row idx
			// if not, add to mapVarIdx
			if( (*m_mapExpressionTreesMod[ idx]->mapVarIdx).find( nlNodeVariableTwo->idx) == (*m_mapExpressionTreesMod[ idx]->mapVarIdx).end()  ){
				// add to map
				k = (*m_mapExpressionTreesMod[ idx]->mapVarIdx).size();
				(*m_mapExpressionTreesMod[ idx]->mapVarIdx)[ nlNodeVariableTwo->idx] =  k + 1;
				std::cout << "ADDED THE FOLLOWING VAIRABLE TO THE MAP" <<  nlNodeVariableTwo->idx << std::endl;
			}
			nlNodeVariableTwo->coef = 1.;
			// now multiply the two new variable nodes together
			nlNodeTimes = new OSnLNodeTimes();
			nlNodeTimes->m_mChildren[ 0] = nlNodeVariableOne;
			nlNodeTimes->m_mChildren[ 1] = nlNodeVariableTwo;		
			// now add the result to the expression tree
			nlNodePlus = new OSnLNodePlus();
			nlNodePlus->m_mChildren[ 0] = m_mapExpressionTreesMod[ idx ]->m_treeRoot;
			nlNodePlus->m_mChildren[ 1] = nlNodeTimes;
			expTree = new OSExpressionTree();
			expTree->m_treeRoot = nlNodePlus ;
			expTree->mapVarIdx = m_mapExpressionTreesMod[ idx]->mapVarIdx;
			m_mapExpressionTreesMod[ idx ]  = expTree;	
		}
		else{
			// create the quadratic expression to add to the expression tree
			nlNodeVariableOne = new OSnLNodeVariable();
			nlNodeVariableOne->idx = m_quadraticTerms->varOneIndexes[ i];
			nlNodeVariableOne->coef = m_quadraticTerms->coefficients[ i];
			nlNodeVariableTwo = new OSnLNodeVariable();
			nlNodeVariableTwo->idx = m_quadraticTerms->varTwoIndexes[ i];
			nlNodeVariableTwo->coef = 1.;
			// now multiply the two new variable nodes together
			nlNodeTimes = new OSnLNodeTimes();
			nlNodeTimes->m_mChildren[ 0] = nlNodeVariableOne;
			nlNodeTimes->m_mChildren[ 1] = nlNodeVariableTwo;
			// create a new expression tree corresponding to row idx.
			expTree = new OSExpressionTree();						
			expTree->m_treeRoot = nlNodeTimes ;
			expTree->mapVarIdx = expTree->getVariableIndiciesMap();		
			m_mapExpressionTreesMod[ idx ]  = expTree;
			std::cout << "NUMBER OF EXPRESSION TREES = "  << m_mapExpressionTreesMod.size() <<std::endl;
		} 
	}
	return true;
}

double OSInstance::calculateFunctionValue(int idx, double *x, bool functionEvaluated){
	try{
		// make sure the index idx is valid
		if( getConstraintNumber() <= idx || getObjectiveNumber() <= ( abs( idx) - 1) ) throw 
			ErrorClass("row or column index not valid in OSInstance::calculateFunctionValue");
		int i, j;
		double dvalue = 0;
		// if we have not filled in the Sparse Jacobian matrix do so now
		if( m_bSparseJacobianCalculated == false) getSparseJacobian();
		//
		if(idx >= 0){ // we have a constraint
			if( functionEvaluated == true) return *(m_mdConstraintFunctionValues + idx);
			// get the nonlinear part
			if( m_mapExpressionTreesMod.find( idx) != m_mapExpressionTreesMod.end() ){
				dvalue = m_mapExpressionTreesMod[ idx]->calculateFunction( x,  functionEvaluated);
			}
			// now the linear part
			// be careful, loop over only the constant terms in sparseJacMatrix
			i = m_sparseJacMatrix->starts[ idx];
			j = m_sparseJacMatrix->starts[ idx + 1 ];
			while ( i <  j &&  (i - m_sparseJacMatrix->starts[ idx])  < m_sparseJacMatrix->conVals[ idx] ){
				dvalue += m_sparseJacMatrix->values[ i]*x[ m_sparseJacMatrix->indexes[ i] ];
				i++;
			}	
			// add in the constraint function constant
			dvalue += m_mdConstraintConstants[ idx ];
			*(m_mdConstraintFunctionValues + idx) = dvalue;
			return *(m_mdConstraintFunctionValues + idx);
		}
		else{ // we have an objective function
			if( functionEvaluated == true) return *(m_mdObjectiveFunctionValues + ( abs( idx) - 1));
			// get the nonlinear part
			if( m_mapExpressionTreesMod.find( idx) != m_mapExpressionTreesMod.end() ){
				dvalue = m_mapExpressionTreesMod[ idx]->calculateFunction( x,  functionEvaluated);
			}
			// get linear part
			SparseVector **objCoef = getObjectiveCoefficients();
			SparseVector *obj = objCoef[ abs( idx) - 1];
			for(i = 0; i < obj->number; i++){
				dvalue += x[ obj->indexes[i]]*obj->values[ i];
			}
			// add in the objective function constant
			dvalue += m_mdObjectiveConstants[ abs( idx) - 1 ];
			// get the coefficients for objective function idx
			*(m_mdObjectiveFunctionValues + ( abs( idx) - 1)) = dvalue;
			return *(m_mdObjectiveFunctionValues + ( abs( idx) - 1));
		}
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	} 
}//calculateFunctionValue


double *OSInstance::calculateAllConstraintFunctionValues( double* x, bool allFunctionsEvaluated){
	if(allFunctionsEvaluated == true) return m_mdConstraintFunctionValues;
	int idx, numConstraints;
	numConstraints = getConstraintNumber();
	// loop over all constraints
	for(idx = 0; idx < numConstraints; idx++){
		// calculateFunctionValue will define *(m_mdConstraintFunctionValues + idx)
		calculateFunctionValue(idx, x, false);	
	}
	return m_mdConstraintFunctionValues;
}//calculateAllConstraintFunctionValues

double *OSInstance::calculateAllObjectiveFunctionValues( double* x, bool allFunctionsEvaluated){
	if(allFunctionsEvaluated == true) return m_mdObjectiveFunctionValues;
	int idx, numObjectives;
	numObjectives = getObjectiveNumber();
	// loop over all objectives
	for(idx = 0; idx < numObjectives; idx++){
		// calculateFunctionValue will define *(m_mdObjectiveFunctionValues + ( abs( idx) - 1))
		calculateFunctionValue(-idx - 1, x, false);	
	}
	return m_mdObjectiveFunctionValues;
}//calculateAllObjectiveFunctionValues

SparseJacobianMatrix *OSInstance::calculateAllConstraintFunctionGradients(double* x, bool functionEvaluated, bool allGradientsEvaluated){
	try{
		// make sure the index idx is valid
		if( allGradientsEvaluated == true  ) return m_sparseJacMatrix;
		int idx, j;
		int jstart, jend;
		std::map<int, int>::iterator posVarIdx;
		std::map<int, OSExpressionTree*>::iterator posMapExpTree;
		std::vector<double> jac;
		// loop over the constraints that have a nonlinear term and get their gradients
		for(posMapExpTree = m_mapExpressionTreesMod.begin(); posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree){
			idx = posMapExpTree->first;
			// we are considering only constraints, not objective function
			if(idx >= 0){
				std::cout << "Getting the gradient for the row indexed by " <<  idx << std::endl;
				jac = m_mapExpressionTreesMod[ idx]->calculateGradient(x, functionEvaluated);
				// check size
				jstart = m_miJacStart[ idx] + m_miJacNumConTerms[ idx];
				jend = m_miJacStart[ idx + 1 ];
				if( jac.size() != (jend - jstart)) throw 
				ErrorClass("number of partials not consistent");
				j = 0;
				for(posVarIdx = (*m_mapExpressionTreesMod[ idx]->mapVarIdx).begin(); posVarIdx 
					!= (*m_mapExpressionTreesMod[ idx]->mapVarIdx).end(); ++posVarIdx){
					if(m_miJacIndex[ jstart] != posVarIdx->first) throw ErrorClass("error calculating Jacobian matrix");
					m_mdJacValue[ jstart] = jac[ j];
					//std::cout << "Constraint  Partial = " <<  jac[ j] << std::endl;
					jstart++;
					j++;
				}
			}
		}
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	} 
	return m_sparseJacMatrix;
}//calculateAllConstraintFunctionGradients	

double *OSInstance::calculateObjectiveFunctionGradient(int idx, double* x, bool functionEvaluated, bool gradientEvaluated){
	try{
		// make sure the index idx is valid
		if(idx >0 && getObjectiveNumber() <= ( abs( idx) - 1)  ) throw 
			ErrorClass("obj index not valid in OSInstance::calculateObjectiveFunctionGradient");
		if( gradientEvaluated == true) return m_mdObjGradient;
		int i;
		int numVar = getVariableNumber();
		std::map<int, int>::iterator posVarIdx;
		std::vector<double> jac;
		// get the constant terms
		for(i = 0; i <= numVar; i++){
			*(m_mdObjGradient + i) = m_mmdDenseObjectiveCoefficients[ (abs( idx) - 1)][i];
		}
		// get the gradient
		if( m_mapExpressionTreesMod.find( idx) != m_mapExpressionTreesMod.end() ){
			jac = m_mapExpressionTreesMod[ idx]->calculateGradient(x, functionEvaluated);
			// check size
			i = 0;
			for(posVarIdx = (*m_mapExpressionTreesMod[ idx]->mapVarIdx).begin(); posVarIdx 
			!= (*m_mapExpressionTreesMod[ idx]->mapVarIdx).end(); ++posVarIdx){
				*(m_mdObjGradient + posVarIdx->first) += jac[ i];	
				std::cout << "Objective  Partial = " <<  jac[ i] << std::endl;
				i++;
			}
		}
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	} 
	return m_mdObjGradient;
}				


bool OSInstance::getSparseJacobianFromRowMajor( ){
	// Kipp -- todo
	return true;
}//getSparseJacobianFromRowMajor

bool OSInstance::getSparseJacobianFromColumnMajor( ){
	// we assume column major matrix
	if( m_bColumnMajor == false) return false;
	int iNumRowStarts = getConstraintNumber() + 1;	
	int i,j, iTemp;
	int iNumVariableStarts = getVariableNumber() - 1;
	int *start = this->instanceData->linearConstraintCoefficients->start->el;
	int *index = this->instanceData->linearConstraintCoefficients->rowIdx->el;
	double *value = this->instanceData->linearConstraintCoefficients->value->el;
	m_miJacStart = new int[ iNumRowStarts];
	m_miJacNumConTerms = new int[ getConstraintNumber()];
	OSnLNodePlus *nlNodePlus;
	OSnLNodeVariable *nlNodeVariable;
	OSExpressionTree *expTree = NULL;
	// now initialize starts and variable index maps 
	for ( i = 0; i < iNumRowStarts; i++){			
		m_miJacStart [ i ] = 0;
		// map the variables  in the nonlinear rows
		if( m_mapExpressionTreesMod.find( i) != m_mapExpressionTreesMod.end() ){
			// the following is equivalent to  m_treeRoot->getVariableIndexMap( i);
			m_mapExpressionTreesMod[ i]->getVariableIndiciesMap();
			
		}
	}
	// i is indexing columns (variables) and j is indexing row numbers 
	for (i = 0; i < iNumVariableStarts; i++){	
		for (j = start[i]; j < start[ i + 1 ]; j++){
			// index[ j] is a row index, we have just found an occurance of row index[j]
			// therefore we increase by 1 (or push back) the start of the row indexed by index[j] + 1, 
			// i.e. the start of the next row
			// check to see if variable i is linear/constant in the row index[ j] 
			// if so, increment m_miJacStart[ index[j] + 1]
			//
			if( (m_mapExpressionTreesMod.find( index[ j]) != m_mapExpressionTreesMod.end() ) &&
				( (*m_mapExpressionTreesMod[ index[ j]]->mapVarIdx).find( i) != (*m_mapExpressionTreesMod[ index[ j]]->mapVarIdx).end()) ){
				// variable i is appears in the expression tree for row index[ j]
				// add the coefficient corresponding to variable i in row index[ j] to the expression tree	
				// define a new OSnLVariable and OSnLnodePlus 
				nlNodeVariable = new OSnLNodeVariable();
				nlNodeVariable->coef = value[ j];
				nlNodeVariable->idx = i;
				nlNodePlus = new OSnLNodePlus();
				nlNodePlus->m_mChildren[ 0] = m_mapExpressionTreesMod[ index[ j] ]->m_treeRoot;
				nlNodePlus->m_mChildren[ 1] = nlNodeVariable;
				expTree = new OSExpressionTree();
				expTree->m_treeRoot = nlNodePlus ;
				expTree->mapVarIdx = m_mapExpressionTreesMod[ index[ j]]->mapVarIdx;
				m_mapExpressionTreesMod[ index[ j] ]  = expTree;	
				std::cout << m_mapExpressionTreesMod[ index[ j] ]->m_treeRoot->getNonlinearExpressionInXML() << std::endl;	
				//std::cout << m_mapExpressionTrees[ index[ j] ]->m_treeRoot->getNonlinearExpressionInXML() << std::endl;
			}
			else{ 
				m_miJacStart[ index[j] + 1] ++;
			}				
		}
	}

	// at this point, m_miJacStart[ i] holds the number of columns with a linear/constant nonzero in row i - 1
	// we are not done with the start indicies, if we are here, and we
	// knew the correct starting point of row i -1, the correct starting point
	// for row i is m_miJacStart[i] + m_miJacStart [i - 1]
	m_miJacStart[0] = 0;
	for (i = 1; i < iNumRowStarts; i++ ){
		m_miJacNumConTerms[ i - 1] = m_miJacStart[i];
		if( m_mapExpressionTreesMod.find( i - 1) != m_mapExpressionTreesMod.end() ){
			m_miJacStart[i] += (m_miJacStart[i - 1] + (*m_mapExpressionTreesMod[ i - 1]->mapVarIdx).size() );
		}
		else{
			m_miJacStart[i] += m_miJacStart[i - 1];
		}	
	}
	// dimension miIndex and mdValue here	
	m_miJacIndex = new int[ m_miJacStart[ iNumRowStarts - 1] ];
	m_mdJacValue = new double[ m_miJacStart[ iNumRowStarts - 1] ];
	// now get the values of the constant terms
	// loop over variables	
	for (i = 0; i < iNumVariableStarts; i++){
		// get row indices and values of the A matrix
		// kipp -- should we have a check to see if start[i+1] > start[i]
		for (j = start[i]; j < start[ i + 1 ]; j++){
			// store this variable index in every row where the variable appears
			// however, don't store this as constant term if it appears in mapVarIdx
			if( (m_mapExpressionTreesMod.find( index[ j]) == m_mapExpressionTreesMod.end() ) ||
				( (*m_mapExpressionTreesMod[ index[ j]]->mapVarIdx).find( i) == (*m_mapExpressionTreesMod[ index[ j]]->mapVarIdx).end()) ){
				iTemp = m_miJacStart[ index[j]];
				m_miJacIndex[ iTemp] = i;
				m_mdJacValue[ iTemp] = value[j];
				m_miJacStart[ index[j]]++;	
			}		
		}			
	} 
	//
	std::map<int, int>::iterator posVarIdx;
	// m_miJacStart[ i] is now equal to the correct m_miJacStart[ i] + m_miJacNumConTerms[ i], so readjust
	for (i = 0; i < iNumRowStarts - 1; i++ ){
		m_miJacStart[ i] = m_miJacStart [ i] - m_miJacNumConTerms[ i] ;	
		iTemp = m_miJacStart[ i] + m_miJacNumConTerms[ i];
		// if the row is in the list of expression trees read in idicies and values
		if( m_mapExpressionTreesMod.find( i) != m_mapExpressionTreesMod.end() ){
			for(posVarIdx = (*m_mapExpressionTreesMod[ i]->mapVarIdx).begin(); posVarIdx 
			!= (*m_mapExpressionTreesMod[ i]->mapVarIdx).end(); ++posVarIdx){
				m_miJacIndex[ iTemp] = posVarIdx->first;
				m_mdJacValue[ iTemp] = 0;
				iTemp++;
			}
		}
	}
	std::cout << "HERE ARE ROW STARTS:" << std::endl;
	for (i = 0; i < iNumRowStarts; i++ ){
		std::cout <<  m_miJacStart[ i] << "  ";	
	}
	std::cout << std::endl << std::endl;
	std::cout << "HERE ARE VARIABLE INDICIES:" << std::endl;
	for (i = 0; i < m_miJacStart[ iNumRowStarts - 1]; i++ ){
		std::cout <<  m_miJacIndex[ i] << "  ";	
	}
	std::cout << std::endl << std::endl;
	std::cout << "HERE ARE VALUES:" << std::endl;
	for (i = 0; i < m_miJacStart[ iNumRowStarts - 1]; i++ ){
		std::cout <<  m_mdJacValue[ i] << "  ";	
	}
	std::cout << std::endl << std::endl;

	std::cout << "HERE ARE NUMBER OF CONSTANT TERMS:" << std::endl;
	for (i = 0; i < iNumRowStarts - 1; i++ ){
		std::cout <<  m_miJacNumConTerms[ i ] << "  ";	
	}
	std::cout << std::endl << std::endl;
	return true;
}//getSparseJacobianFromColumnMajor

OSExpressionTree* OSInstance::getLagrangianOfHessian( ){
	if( m_bLagHessianCreated == true) return m_LagHessian;
	// we calculate the Lagrangian for all the objectives and constraints
	// with nonlinear terms
	// first initialize everything for nonlinear work
	getSparseJacobian( );	
	std::map<int, OSExpressionTree*>::iterator posMapExpTree;
	OSnLNodeTimes* nlNodeTimes = NULL;
	OSnLNodeVariable* nlNodeVariable = NULL;
	OSnLNodeSum* nlNodeSum = NULL;
	int rowIdx;
	int numChildren = 0;
	// create the sum node
	nlNodeSum = new OSnLNodeSum();
	nlNodeSum->inumberOfChildren = m_mapExpressionTreesMod.size();
	std::cout << "NUMBER OF KIDS = " << m_mapExpressionTreesMod.size()<< std::endl;
	nlNodeSum->m_mChildren = new OSnLNode*[ nlNodeSum->inumberOfChildren];
	// create and expression tree for the sum node
	m_LagHessian = new OSExpressionTree();
	m_LagHessian->m_treeRoot = nlNodeSum;
	// now create the children of the sum node
	for(posMapExpTree = m_mapExpressionTreesMod.begin(); posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree){
		nlNodeVariable = new OSnLNodeVariable();
		nlNodeVariable->coef = 1.;
		/**
		 * the variable we just created is a Lagrange multplier and needs the appropriate index
		 * if the Expression tree row index is constraint k then the variable index is
		 * number of variables + row index
		 * if the expression tree corresponds to an objective function then the variable index
		 * is number of variables + number of rows + (abs(row idx) - 1) 
		 */
		 rowIdx = posMapExpTree->first;
		 if( rowIdx >= 0){
		 	nlNodeVariable->idx = this->instanceData->variables->numberOfVariables + rowIdx;
		 }
		 else{
		 	nlNodeVariable->idx = this->instanceData->variables->numberOfVariables 
		 		+ this->instanceData->constraints->numberOfConstraints + (abs(rowIdx) - 1);
		 } 
		// now create a times multiply the new variable times the root of the expression tree
		nlNodeTimes = new OSnLNodeTimes();
		nlNodeTimes->m_mChildren[ 0] = nlNodeVariable;
		nlNodeTimes->m_mChildren[ 1] = m_mapExpressionTreesMod[ rowIdx ]->m_treeRoot;	
		// the times node is the new child
		nlNodeSum->m_mChildren[ numChildren] = nlNodeTimes;
		numChildren++;
	}	
	// get a variable index map for the expression tree
	m_LagHessian->getVariableIndiciesMap();
	// print out the XML for this puppy
	std::cout << m_LagHessian->m_treeRoot->getNonlinearExpressionInXML() << std::endl;
	//
	m_bLagHessianCreated = true;
	return m_LagHessian;
}//getLagrangianOfHessian

void OSInstance::duplicateExpressionTreesMap(){
	if(m_bDuplicateExpressionTreesMap == false){ 
		// first make sure the map was created
		if( m_bProcessExpressionTrees == false) getAllNonlinearExpressionTrees();
		m_mapExpressionTreesMod = m_mapExpressionTrees;
		m_bDuplicateExpressionTreesMap = true;
		return;
	}
	else{
		return;
	}
}//duplicateExpressionTreesMap

