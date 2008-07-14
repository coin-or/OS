/** @file OSInstance.cpp
 * \brief This file defines the OSInstance class along with its supporting classes..
 *
 * @author  Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin, 
 * @version 2.0, 12/21/2007
 * @since   OS1.0
 *initializeNonLinearStructures
 *
 * \remarks
 * Copyright (C) 2005, Robert Fourer, Gus Gassmann Jun Ma, Kipp Martin,
 * Northwestern University, Dalhousie University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 *
 */
 
#include "OSInstance.h"
#include "OSMathUtil.h"
#include "OSCommonUtil.h"
#include "OSErrorClass.h"
#include "OSParameters.h"
#include<iostream>  
#include<sstream>

//#define DEBUG
 
using namespace std;
using CppAD::NearEqual;

OSInstance::OSInstance(): 
	m_sInstanceName(""),
	m_sInstanceSource(""),	
	m_sInstanceDescription(""),
	m_bProcessVariables(false),
	m_iVariableNumber(-1),
	m_iNumberOfIntegerVariables( 0),
	m_iNumberOfBinaryVariables( 0),
	m_iNumberOfQuadraticRowIndexes( 0),
	m_bQuadraticRowIndexesProcessed( false),
	m_miQuadRowIndexes( NULL),
	m_iNumberOfNonlinearExpressionTreeIndexes( 0),
	m_bNonlinearExpressionTreeIndexesProcessed( false),
	m_miNonlinearExpressionTreeIndexes( NULL),
	m_iNumberOfNonlinearExpressionTreeModIndexes( 0),
	m_bNonlinearExpressionTreeModIndexesProcessed( false),
	m_miNonlinearExpressionTreeModIndexes( NULL),		
	m_msVariableNames(NULL),
	m_mdVariableInitialValues(NULL),
	m_msVariableInitialStringValues(NULL),
	m_mcVariableTypes(NULL),
	m_mdVariableLowerBounds(NULL),
	m_mdVariableUpperBounds(NULL),
	m_bProcessObjectives(false),
	m_iObjectiveNumber(-1),
	m_iObjectiveNumberNonlinear( 0),
	m_msObjectiveNames(NULL),
	m_msMaxOrMins(NULL),
	m_miNumberOfObjCoef(NULL),
	m_mdObjectiveConstants(NULL),
	m_mdObjectiveWeights(NULL),
	m_mObjectiveCoefficients(NULL),
	m_bGetDenseObjectives(false),
	m_mmdDenseObjectiveCoefficients(NULL),
	m_bProcessConstraints(false),
	m_iConstraintNumber(-1),
	m_iConstraintNumberNonlinear( 0),	
	m_msConstraintNames(NULL),
	m_mdConstraintLowerBounds(NULL),
	m_mdConstraintUpperBounds(NULL),
	m_mdConstraintConstants( NULL),
	m_mcConstraintTypes(NULL),
 	m_bProcessLinearConstraintCoefficients(false),	
	m_iLinearConstraintCoefficientNumber(-1),
	m_bColumnMajor(true),
	m_binitForAlgDiff( false),	
	m_linearConstraintCoefficientsInColumnMajor(NULL),
	m_linearConstraintCoefficientsInRowMajor(NULL),	
	m_bProcessQuadraticTerms(false),
	m_iQuadraticTermNumber(-1),
	m_mdConstraintFunctionValues( NULL),
	m_mdObjectiveFunctionValues( NULL),
	m_iJacValueSize( 0),
	m_miJacStart( NULL),
	m_miJacIndex( NULL),
	m_mdJacValue( NULL),
	m_miJacNumConTerms( NULL),
	m_sparseJacMatrix( NULL),	
	m_iHighestTaylorCoeffOrder(-1),	
	m_quadraticTerms( NULL),	
	m_bQTermsAdded( false),	
	m_iNumberOfNonlinearVariables( 0),
	m_bProcessNonlinearExpressions( false),
	m_iNonlinearExpressionNumber( -1),		
	m_miNonlinearExpressionIndexes( NULL),
	m_bProcessExpressionTrees( false),
	m_bProcessExpressionTreesMod( false),
	m_LagrangianExpTree(NULL),
	m_bLagrangianExpTreeCreated( false),
	m_LagrangianSparseHessian( NULL),
	m_bLagrangianSparseHessianCreated( false),
	m_miNonLinearVarsReverseMap( NULL),
	m_bAllNonlinearVariablesIndex( false),
	m_bCppADFunIsCreated( false),
	m_bCppADTapesBuilt( false),
	m_bCppADMustReTape( false),
	m_bDuplicateExpressionTreesMap( false),
	m_bNonLinearStructuresInitialized( false),
	m_bSparseJacobianCalculated( false),
	m_iHighestOrderEvaluated( -1),
	m_mmdObjGradient( NULL),
	m_bProcessTimeDomain( false),
	m_bProcessTimeStages( false),
	m_bProcessTimeInterval( false),
	m_bFiniteTimeStages( false),
	m_iNumberOfTimeStages(-1),
	m_msTimeDomainStageNames(NULL),
	m_miTimeDomainStageVariableNumber(NULL),
	m_mmiTimeDomainStageVarList(NULL),
	m_miTimeDomainStageConstraintNumber(NULL),
	m_mmiTimeDomainStageConList(NULL),
	m_miTimeDomainStageObjectiveNumber(NULL),
	m_mmiTimeDomainStageObjList(NULL),
	bUseExpTreeForFunEval( false)

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
	/**
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
	*/
	delete[] m_miNonLinearVarsReverseMap;
	m_miNonLinearVarsReverseMap = NULL;
	int i;
	//if(instanceData->objectives->numberOfObjectives > 0 && m_mObjectiveCoefficients != NULL){
	if(m_bProcessObjectives == true ){
		for(i = 0; i < instanceData->objectives->numberOfObjectives; i++){
			#ifdef DEBUG
			std::cout <<  "Delete m_mObjectiveCoefficients[i]" << std::endl;
			#endif
			delete m_mObjectiveCoefficients[i];
			m_mObjectiveCoefficients[i] = NULL;
		}
		#ifdef DEBUG
		std::cout <<  "Delete m_msObjectiveNames" << std::endl;
		std::cout <<  "Delete m_msMaxOrMins" << std::endl;
		std::cout <<  "Delete m_miNumberOfObjCoef" << std::endl;
		std::cout <<  "Delete m_mdObjectiveConstants" << std::endl;
		std::cout <<  "Delete m_mdObjectiveWeights" << std::endl;
		#endif		
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
	}
	if(instanceData->objectives->numberOfObjectives > 0 && m_mmdDenseObjectiveCoefficients != NULL){
		for(i = 0; i < instanceData->objectives->numberOfObjectives; i++){
			//delete m_mmdDenseObjectiveCoefficients[i];
			#ifdef DEBUG
			std::cout <<  "delete m_mmdDenseObjectiveCoefficients[i]" << std::endl;
			#endif
		    delete[] m_mmdDenseObjectiveCoefficients[i];
			m_mmdDenseObjectiveCoefficients[i] = NULL;
		}
		delete[] m_mmdDenseObjectiveCoefficients;
		m_mmdDenseObjectiveCoefficients = NULL;
	}

	if( (m_binitForAlgDiff == true)  ){	
		if(instanceData->objectives->numberOfObjectives > 0 && m_mmdObjGradient != NULL){
			
			#ifdef DEBUG
			std::cout <<  "The number of objectives =  " << instanceData->objectives->numberOfObjectives << std::endl;
			#endif
			for(i = 0; i < instanceData->objectives->numberOfObjectives; i++){
				#ifdef DEBUG
				std::cout << "deleting Objective function gradient " << i << std::endl;
				#endif
				delete[] m_mmdObjGradient[i];

				m_mmdObjGradient[i] = NULL;
			}
			delete[] m_mmdObjGradient;
			m_mmdObjGradient = NULL;
		}
	}

	if(m_bProcessLinearConstraintCoefficients == true && m_bColumnMajor == true) delete m_linearConstraintCoefficientsInColumnMajor;
	if(m_bProcessLinearConstraintCoefficients == true && m_bColumnMajor == false) delete m_linearConstraintCoefficientsInRowMajor;
	//if(m_linearConstraintCoefficientsInRowMajor != NULL) delete m_linearConstraintCoefficientsInRowMajor;
	//if(m_linearConstraintCoefficientsInColumnMajor != NULL) delete m_linearConstraintCoefficientsInColumnMajor;
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
	//std::cout << "Do garbage collection for the nonlinear API" << std::endl;
	// garbage collection for the gradient
	if(m_bNonLinearStructuresInitialized == true ){
		delete[] m_mdObjectiveFunctionValues; 
		m_mdObjectiveFunctionValues = NULL;	
		delete[] m_mdConstraintFunctionValues;
		m_mdConstraintFunctionValues = NULL;
	}
	if(m_bSparseJacobianCalculated == true){
		delete[] m_miJacStart;
		m_miJacStart = NULL;
		delete[] m_miJacIndex;
		m_miJacIndex = NULL;
		delete[] m_mdJacValue;
		m_mdJacValue = NULL;
		delete[] m_miJacNumConTerms;
		m_miJacNumConTerms = NULL;
	}
	if( m_bLagrangianExpTreeCreated == true){
		delete m_LagrangianExpTree;
		m_LagrangianExpTree = NULL;
	}
	if( m_bLagrangianSparseHessianCreated == true){
		delete m_LagrangianSparseHessian;
		m_LagrangianSparseHessian = NULL;
	}
	if( m_bSparseJacobianCalculated == true){
		delete m_sparseJacMatrix;
		m_sparseJacMatrix = NULL;
	}
	if( (instanceData->quadraticCoefficients->qTerm != NULL) && (m_bProcessQuadraticTerms == true) ){
		delete m_quadraticTerms;
		m_quadraticTerms = NULL;
	}
	if( (instanceData->quadraticCoefficients->qTerm != NULL)  && (m_bQuadraticRowIndexesProcessed == true) ){
		delete[] m_miQuadRowIndexes;
		m_miQuadRowIndexes = NULL;
	}
	//
	// delete the new expression trees that got created
	//if( m_bLagrangianExpTreeCreated == false  ||  m_bLagrangianExpTreeCreated == true){
	if( (m_bProcessExpressionTrees == true) && (m_bDuplicateExpressionTreesMap == false)  ) {
		for(posMapExpTree = m_mapExpressionTrees.begin(); posMapExpTree != m_mapExpressionTrees.end(); ++posMapExpTree){
			std::cout << "Deleting an expression tree from the map for row  " << posMapExpTree->first  << std::endl;
			delete m_mapExpressionTrees[ posMapExpTree->first ];
		}
	}
	if( m_bDuplicateExpressionTreesMap == true)   {
		for(posMapExpTree = m_mapExpressionTreesMod.begin(); posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree){		
			#ifdef DEBUG
				std::cout << "Deleting an expression tree from m_mapExpressionTreesMod" << std::endl;
			#endif
			delete m_mapExpressionTreesMod[ posMapExpTree->first ];
		}
	}
	//}
	///
	if( (m_bNonlinearExpressionTreeIndexesProcessed == true) && (m_mapExpressionTrees.size() > 0) ){
		std::cout << "Deleting  m_miNonlinearExpressionTreeIndexes" << std::endl;
		delete[] m_miNonlinearExpressionTreeIndexes;
		std::cout << "Done Deleting  m_miNonlinearExpressionTreeIndexes" << std::endl;
		m_miNonlinearExpressionTreeIndexes = NULL;
	}
	if( (m_bNonlinearExpressionTreeModIndexesProcessed == true) && (m_mapExpressionTreesMod.size() > 0) ){
		std::cout << "Deleting  m_miNonlinearExpressionTreeModIndexes" << std::endl;
		delete[] m_miNonlinearExpressionTreeModIndexes;
		std::cout << "Done Deleting  m_miNonlinearExpressionTreeModIndexes" << std::endl;
		m_miNonlinearExpressionTreeModIndexes = NULL;
	}
	if(m_bCppADFunIsCreated == true){
		delete Fad;
		Fad = NULL;
	}
//	if( (instanceData->timeDomain->stages->stage != NULL) && (m_bProcessTimeStages == true) ){
//		delete m_Stages;
//		m_Stages = NULL;
//	}

	if (m_msTimeDomainStageNames != NULL) {
		delete m_msTimeDomainStageNames;
		m_msTimeDomainStageNames = NULL;
	}

	if (m_miTimeDomainStageVariableNumber != NULL) {
		delete m_miTimeDomainStageVariableNumber;
		m_miTimeDomainStageVariableNumber = NULL;
	}

	if (m_mmiTimeDomainStageVarList != NULL) {
		delete m_mmiTimeDomainStageVarList;
		m_mmiTimeDomainStageVarList = NULL;
	}

	if (m_miTimeDomainStageConstraintNumber != NULL) {
		delete m_miTimeDomainStageConstraintNumber;
		m_miTimeDomainStageConstraintNumber = NULL;
	}

	if (m_mmiTimeDomainStageConList != NULL) {
		delete m_mmiTimeDomainStageConList;
		m_mmiTimeDomainStageConList = NULL;
	}

	if (m_miTimeDomainStageObjectiveNumber != NULL) {
		delete m_miTimeDomainStageObjectiveNumber;
		m_miTimeDomainStageObjectiveNumber = NULL;
	}

	if (m_mmiTimeDomainStageObjList != NULL) {
		delete m_mmiTimeDomainStageObjList;
		m_mmiTimeDomainStageObjList = NULL;
	}

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
	lb(0.0),
	ub(OSDBL_MAX),
	init(OSNAN), 
	type('C'), 
	name(""),
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
	int i;
	if(numberOfVariables > 0 && var != NULL){
		for(i = 0; i < numberOfVariables; i++){
			#ifdef DEBUG 
			cout << "Deleting var[ i]" << endl;
			#endif
			delete var[i];
			var[i] = NULL;
		}
	}
	delete[] var;
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
	cout << "Inside the ObjCoef Destructor" << endl;  
	#endif
}

Objective::Objective():
	name("") ,
	maxOrMin("min"),
	constant(0.0),
	weight(1.0),
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
	int i;
	if(numberOfObjCoef > 0 && coef != NULL){
		for(i = 0; i < numberOfObjCoef; i++){
			delete coef[i];
			coef[i] = NULL;
		}
	}
	delete[] coef;
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
	int i;
	if(numberOfObjectives > 0 && obj != NULL){
		for(i = 0; i < numberOfObjectives; i++){
			delete obj[i];
			obj[i] = NULL;
		}
	}
	delete[] obj;
	obj = NULL;
}

Constraint::Constraint():
	name(""),
	constant(0.0),
	lb(-OSDBL_MAX),
	ub(OSDBL_MAX)

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
	int i;
	if(numberOfConstraints > 0 && con != NULL){
		for( i = 0; i < numberOfConstraints; i++){
			delete con[i];
			con[i] = NULL;
		}
	}
	delete[] con;
	con = NULL;
} 



LinearConstraintCoefficients::LinearConstraintCoefficients():
	numberOfValues(0) ,
	iNumberOfStartElements( 0)
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
	numberOfQuadraticTerms(0),
	qTerm(NULL)
{ 
	#ifdef DEBUG 
	cout << "Inside the QuadraticCoefficients Constructor" << endl;
	#endif
}//end QuadraticCoefficients() 


QuadraticCoefficients::~QuadraticCoefficients(){
	#ifdef DEBUG  
	cout << "Inside the QuadraticCoefficients Destructor" << endl;
	#endif
	int i;
	if(numberOfQuadraticTerms > 0 && qTerm != NULL){
		for( i = 0; i < numberOfQuadraticTerms; i++){
			delete qTerm[i];
			qTerm[i] = NULL;
		}
	}
	delete[] qTerm;
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
	if( m_bDeleteExpressionTree == true){
		delete osExpressionTree;
		osExpressionTree = NULL;
	}
}//end ~Nl



NonlinearExpressions::NonlinearExpressions():
	numberOfNonlinearExpressions(0) ,
	nl(NULL)
{ 
	#ifdef DEBUG 
	cout << "Inside the NonlinearExpressions Constructor" << endl;
	#endif
}//end NonlinearExpressions() 

NonlinearExpressions::~NonlinearExpressions(){
	#ifdef DEBUG  
	cout << "Inside the NonlinearExpressions Destructor" << endl;
	cout << "NUMBER OF NONLINEAR EXPRESSIONS = " << numberOfNonlinearExpressions << endl;
	#endif
	int i;
	if(numberOfNonlinearExpressions > 0 && nl != NULL){
		for( i = 0; i < numberOfNonlinearExpressions; i++){
			#ifdef DEBUG  
				cout << "DESTROYING EXPRESSION " << nl[ i]->idx << endl;
			#endif
			delete nl[i];
			nl[i] = NULL;
		}
	}
	delete[] nl;
	nl = NULL;  
}//end ~NonlinearExpressions()  


TimeDomainStageVar::TimeDomainStageVar():
	idx(0)
{
	#ifdef DEBUG 
	cout << "Inside the Stage Objectives Var Constructor" << endl;
	#endif
} // end TimeDomainStageVar


TimeDomainStageVar::~TimeDomainStageVar()
{
	#ifdef DEBUG 
	cout << "Inside the Stage Objectives Var Destructor" << endl;
	#endif
} // end ~TimeDomainStageVar


TimeDomainStageVariables::TimeDomainStageVariables():
	numberOfVariables(0),
	startIdx(-1)
{
	#ifdef DEBUG 
	cout << "Inside the Stage Variables Constructor" << endl;
	#endif
	var = NULL;
} // end TimeDomainStageVariables

TimeDomainStageVariables::~TimeDomainStageVariables()
{
	#ifdef DEBUG 
	cout << "Inside the Stage Variables Destructor" << endl;
	#endif
	if (numberOfVariables > 0 && var != NULL){
		for (int i = 0; i < numberOfVariables; i++) {
			delete var[i];
			var[i] = NULL;
		}
	}
	delete [] var;
	var = NULL;
} // end ~TimeDomainStageVariables

TimeDomainStageCon::TimeDomainStageCon():
	idx(0)
{
	#ifdef DEBUG 
	cout << "Inside the Stage Objectives Con Constructor" << endl;
	#endif
} // end TimeDomainStageCon


TimeDomainStageCon::~TimeDomainStageCon()
{
	#ifdef DEBUG 
	cout << "Inside the Stage Objectives Con Destructor" << endl;
	#endif
} // end ~TimeDomainStageCon


TimeDomainStageConstraints::TimeDomainStageConstraints():
	numberOfConstraints(0),
	startIdx(-1)
{
	#ifdef DEBUG 
	cout << "Inside the Stage Constraints Constructor" << endl;
	#endif
	con = NULL;
} // end TimeDomainStageConstraints

TimeDomainStageConstraints::~TimeDomainStageConstraints()
{
	#ifdef DEBUG 
	cout << "Inside the Stage Constraints Destructor" << endl;
	#endif
	if (numberOfConstraints > 0 && con != NULL){
		for (int i = 0; i < numberOfConstraints; i++) {
			delete con[i];
			con[i] = NULL;
		}
	}
	delete [] con;
	con = NULL;
} // end ~TimeDomainStageConstraints

TimeDomainStageObj::TimeDomainStageObj():
	idx(0)
{
	#ifdef DEBUG 
	cout << "Inside the Stage Objectives Obj Constructor" << endl;
	#endif
} // end TimeDomainStageObj


TimeDomainStageObj::~TimeDomainStageObj()
{
	#ifdef DEBUG 
	cout << "Inside the Stage Objectives Obj Destructor" << endl;
	#endif
} // end ~TimeDomainStageObj


TimeDomainStageObjectives::TimeDomainStageObjectives():
	numberOfObjectives(0),
	startIdx(-1)
{
	#ifdef DEBUG 
	cout << "Inside the Stage Objectives Constructor" << endl;
	#endif
	obj = NULL;
} // end TimeDomainStageObjectives

TimeDomainStageObjectives::~TimeDomainStageObjectives()
{
	#ifdef DEBUG 
	cout << "Inside the Stage Objectives Destructor" << endl;
	#endif
	if (numberOfObjectives > 0 && obj != NULL){
		for (int i = 0; i < numberOfObjectives; i++) {
			delete obj[i];
			obj[i] = NULL;
		}
	}
	delete [] obj;
	obj = NULL;
} // end ~TimeDomainStageObjectives

TimeDomainStage::TimeDomainStage():
	name("")
{ 
	#ifdef DEBUG 
	cout << "Inside the Stage Constructor" << endl;
	#endif
	variables   = NULL;
	constraints = NULL;
	objectives  = NULL;
}//end TimeDomainStage() 


TimeDomainStage::~TimeDomainStage(){
	#ifdef DEBUG  
	cout << "Inside the Stage Destructor" << endl;
	#endif
	if (variables != NULL)
	{	delete variables;
		variables = NULL;
	}
	if (constraints != NULL)
	{	delete constraints;
		constraints = NULL;
	}
	if (objectives != NULL)
	{	delete objectives;
		objectives = NULL;
	}
}//end ~TimeDomainStage()  


TimeDomainStages::TimeDomainStages():
	numberOfStages(0),
	stage(NULL)
{
	#ifdef DEBUG  
	cout << "Inside the Stages Constructor" << endl;
	#endif
} 


TimeDomainStages::~TimeDomainStages(){  
	#ifdef DEBUG
	cout << "Inside the Stages Destructor" << endl;
	#endif
	int i;
	if(numberOfStages > 0 && stage != NULL){
		for( i = 0; i < numberOfStages; i++){
			delete stage[i];
			stage[i] = NULL;
		}
	}
	delete[] stage;
	stage = NULL;  
}

TimeDomainInterval::TimeDomainInterval():
	start(0.0),
	horizon(0.0)
{
	#ifdef DEBUG  
	cout << "Inside the Interval Constructor" << endl;
	#endif
} 


TimeDomainInterval::~TimeDomainInterval(){  
	#ifdef DEBUG
	cout << "Inside the Interval Destructor" << endl;
	#endif
}

TimeDomain::TimeDomain()
{
	#ifdef DEBUG
	cout << "Inside the TimeDomain Constructor" << endl;
	#endif
	stages = NULL;
	interval = NULL;
}

TimeDomain::~TimeDomain()
{  
	#ifdef DEBUG
	cout << "Inside the TimeDomain Destructor" << endl;
	#endif
	if (stages != NULL)
	{	delete stages;
		stages = NULL;
	}
	if (interval != NULL)
	{	delete interval;
		interval = NULL;
	}
} 


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
	timeDomain = NULL;
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
	if (timeDomain != NULL)
	{   delete timeDomain;
		timeDomain = NULL;
	}
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
			m_mdVariableInitialValues = new double[n];
			for(i = 0; i < n; i++){
				if(CommonUtil::ISOSNAN(instanceData->variables->var[ 0]->init) == true ){				
					m_mdVariableInitialValues[i] =	1.7171;
				}
				else{
					m_mdVariableInitialValues[i] = instanceData->variables->var[i]->init;
				}
			}
		//}
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
		for(i = 0; i < n; i++){
			m_mObjectiveCoefficients[i] = new SparseVector(instanceData->objectives->obj[ j]->numberOfObjCoef);
			//m_mObjectiveCoefficients[i]->bDeleteArrays=false;
		}
		
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
			if(m_mdConstraintLowerBounds[i] == OSDBL_MAX || m_mdConstraintUpperBounds[i] == -OSDBL_MAX) {
				throw ErrorClass( outStr.str() );
			}
			else if(m_mdConstraintLowerBounds[i] > m_mdConstraintUpperBounds[i]) {
				outStr << "Constraint  " ;
				outStr << i;
				outStr << " is infeasible";
				throw ErrorClass( outStr.str());
			}
			else if(m_mdConstraintLowerBounds[i] == -OSDBL_MAX && m_mdConstraintUpperBounds[i] == OSDBL_MAX)
				m_mcConstraintTypes[i] = 'U';
			else if(m_mdConstraintLowerBounds[i] == m_mdConstraintUpperBounds[i]) 
				m_mcConstraintTypes[i] = 'E';
			else if(m_mdConstraintLowerBounds[i] == -OSDBL_MAX)
				m_mcConstraintTypes[i] = 'L';
			else if(m_mdConstraintUpperBounds[i] == OSDBL_MAX)
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
				m_linearConstraintCoefficientsInColumnMajor->bDeleteArrays = false;
				m_linearConstraintCoefficientsInColumnMajor->isColumnMajor = true;
				m_linearConstraintCoefficientsInColumnMajor->valueSize = n;
				m_linearConstraintCoefficientsInColumnMajor->startSize = instanceData->variables->numberOfVariables + 1;
			}
			else{ 
				m_bColumnMajor = false;	
				m_linearConstraintCoefficientsInRowMajor = new SparseMatrix();
				m_linearConstraintCoefficientsInRowMajor->bDeleteArrays = false;
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


int* OSInstance::getQuadraticRowIndexes() {
	if(m_bQuadraticRowIndexesProcessed == true) return m_miQuadRowIndexes;
	m_bQuadraticRowIndexesProcessed = true;
	int n = getNumberOfQuadraticTerms();	
	if(n <= 0) return NULL;
	QuadraticTerms *qTerms = NULL;
	qTerms = getQuadraticTerms();
	std::map<int, int> foundIdx;
	std::map<int, int>::iterator pos;
	int i;
	try{
		for(i = 0; i < n; i++){
			// add the terms
			foundIdx[ qTerms->rowIndexes[ i] ];	 
		}
		// now put the term into an array
		m_iNumberOfQuadraticRowIndexes = foundIdx.size();
		m_miQuadRowIndexes = new int[ m_iNumberOfQuadraticRowIndexes ]	;
		i = 0;
		for(pos = foundIdx.begin(); pos != foundIdx.end(); ++pos){
			m_miQuadRowIndexes[ i++] = pos->first;	
		}
		foundIdx.clear();	
		return m_miQuadRowIndexes;
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	} 
}//getQuadraticRowIndexes


int OSInstance::getNumberOfQuadraticRowIndexes() {
	if(m_bQuadraticRowIndexesProcessed == false) getQuadraticRowIndexes();
	return m_iNumberOfQuadraticRowIndexes;
}//getNumberOfQuadraticRowIndexes

int* OSInstance::getNonlinearExpressionTreeIndexes(){
	if(m_bNonlinearExpressionTreeIndexesProcessed == true) return m_miNonlinearExpressionTreeIndexes;
	m_bNonlinearExpressionTreeIndexesProcessed = true;
	std::map<int, OSExpressionTree*> expTrees;
	expTrees = getAllNonlinearExpressionTrees();	
	std::map<int, OSExpressionTree*>::iterator pos;
	try{
		// now put the term into an array
		m_iNumberOfNonlinearExpressionTreeIndexes = expTrees.size();
		m_miNonlinearExpressionTreeIndexes = new int[ m_iNumberOfNonlinearExpressionTreeIndexes ]	;
		int i = 0;
		for(pos = expTrees.begin(); pos != expTrees.end(); ++pos){
			m_miNonlinearExpressionTreeIndexes[ i++] = pos->first;	
		}
		expTrees.clear();	
		return m_miNonlinearExpressionTreeIndexes;
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	} 
}//getNonlinearExpressionTreeIndexes

int OSInstance::getNumberOfNonlinearExpressionTreeIndexes() {
	if(m_bNonlinearExpressionTreeIndexesProcessed == false) getNonlinearExpressionTreeIndexes();
	return m_iNumberOfNonlinearExpressionTreeIndexes;
}//getNumberOfNonlinearExpressionTreeIndexes



int* OSInstance::getNonlinearExpressionTreeModIndexes(){
	if(m_bNonlinearExpressionTreeModIndexesProcessed == true) return m_miNonlinearExpressionTreeModIndexes;
	m_bNonlinearExpressionTreeModIndexesProcessed = true;
	std::map<int, OSExpressionTree*> expTrees;
	expTrees = getAllNonlinearExpressionTreesMod();	
	std::map<int, OSExpressionTree*>::iterator pos;
	try{
		// now put the term into an array
		m_iNumberOfNonlinearExpressionTreeModIndexes = expTrees.size();
		m_miNonlinearExpressionTreeModIndexes = new int[ m_iNumberOfNonlinearExpressionTreeModIndexes ]	;
		int i = 0;
		for(pos = expTrees.begin(); pos != expTrees.end(); ++pos){
			m_miNonlinearExpressionTreeModIndexes[ i++] = pos->first;	
		}
		expTrees.clear();	
		return m_miNonlinearExpressionTreeModIndexes;
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	} 
}//getNonlinearExpressionTreeModIndexes

int OSInstance::getNumberOfNonlinearExpressionTreeModIndexes() {
	if(m_bNonlinearExpressionTreeModIndexesProcessed == false) getNonlinearExpressionTreeModIndexes();
	return m_iNumberOfNonlinearExpressionTreeModIndexes;
}//getNumberOfNonlinearExpressionTreeModIndexes


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
		//if( m_mapExpressionTrees.find( rowIdx) != m_mapExpressionTrees.end()) return NULL;
		//else return m_mapExpressionTrees[ rowIdx];
		if( m_mapExpressionTrees.find( rowIdx) != m_mapExpressionTrees.end()) return m_mapExpressionTrees[ rowIdx];
		else return NULL ;
		// check to make sure rowIdx has a nonlinear term and is in the map
		/** define an iterator for the expression trees map allExpTrees */
		//std::map<int, OSExpressionTree*>::iterator pos;
		///for(pos = m_mapExpressionTrees.begin(); pos != m_mapExpressionTrees.end(); ++pos){
		//	if(pos->first == rowIdx)return m_mapExpressionTrees[ rowIdx];
		//}
		// if we are rowIdx has no nonlinar terms so return a null
		//return NULL;
	}     
}// getNonlinearExpressionTree for a specific index   


OSExpressionTree* OSInstance::getNonlinearExpressionTreeMod(int rowIdx){
	if( m_bProcessExpressionTreesMod == false ){
		getAllNonlinearExpressionTreesMod();
		return m_mapExpressionTreesMod[ rowIdx];
	} 
	else{
		//if( m_mapExpressionTrees.find( rowIdx) != m_mapExpressionTrees.end()) return NULL;
		//else return m_mapExpressionTrees[ rowIdx];
		if( m_mapExpressionTreesMod.find( rowIdx) != m_mapExpressionTreesMod.end()) return m_mapExpressionTreesMod[ rowIdx];
		else return NULL ;
		// check to make sure rowIdx has a nonlinear term and is in the map
		/** define an iterator for the expression trees map allExpTrees */
		//std::map<int, OSExpressionTree*>::iterator pos;
		///for(pos = m_mapExpressionTrees.begin(); pos != m_mapExpressionTrees.end(); ++pos){
		//	if(pos->first == rowIdx)return m_mapExpressionTrees[ rowIdx];
		//}
		// if we are rowIdx has no nonlinar terms so return a null
		//return NULL;
	}     
}// getNonlinearExpressionTreeMod for a specific index 


std::vector<OSnLNode*> OSInstance::getNonlinearExpressionTreeInPostfix( int rowIdx){
	if( m_bProcessExpressionTrees == false ) getAllNonlinearExpressionTrees();
	std::vector<OSnLNode*> postfixVec;
	try{
		if( m_mapExpressionTrees.find( rowIdx) != m_mapExpressionTrees.end()){
			OSExpressionTree* expTree = getNonlinearExpressionTree( rowIdx);
			postfixVec = expTree->m_treeRoot->getPostfixFromExpressionTree();
			
		}  
		else{
			throw ErrorClass("Error in getNonlinearExpressionTreeInPostfix, rowIdx not valid");
		}
		return postfixVec;	
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	} 
}//getNonlinearExpressionTreeInPostfix


std::vector<OSnLNode*> OSInstance::getNonlinearExpressionTreeModInPostfix( int rowIdx){
	if( m_bProcessExpressionTreesMod == false ) getAllNonlinearExpressionTreesMod();
	std::vector<OSnLNode*> postfixVec;
	try{
		if( m_mapExpressionTreesMod.find( rowIdx) != m_mapExpressionTreesMod.end()){
			OSExpressionTree* expTree = getNonlinearExpressionTreeMod( rowIdx);
			postfixVec = expTree->m_treeRoot->getPostfixFromExpressionTree();
			
		}  
		else{
			throw ErrorClass("Error in getNonlinearExpressionTreeModInPostfix, rowIdx not valid");
		}
		return postfixVec;	
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	} 
}//getNonlinearExpressionTreeModInPostfix


std::vector<OSnLNode*> OSInstance::getNonlinearExpressionTreeInPrefix( int rowIdx){
	if( m_bProcessExpressionTrees == false ) getAllNonlinearExpressionTrees();
	std::vector<OSnLNode*> prefixVec;
	try{
		if( m_mapExpressionTrees.find( rowIdx) != m_mapExpressionTrees.end()){
			OSExpressionTree* expTree = getNonlinearExpressionTree( rowIdx);
			prefixVec = expTree->m_treeRoot->getPrefixFromExpressionTree();
			
		}  
		else{
			throw ErrorClass("Error in getNonlinearExpressionTreeInPrefix, rowIdx not valid");
		}
		return prefixVec;	
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	} 
}//getNonlinearExpressionTreeInPrefix

std::vector<OSnLNode*> OSInstance::getNonlinearExpressionTreeModInPrefix( int rowIdx){
	if( m_bProcessExpressionTreesMod == false ) getAllNonlinearExpressionTreesMod();
	std::vector<OSnLNode*> prefixVec;
	try{
		if( m_mapExpressionTreesMod.find( rowIdx) != m_mapExpressionTreesMod.end()){
			OSExpressionTree* expTree = getNonlinearExpressionTreeMod( rowIdx);
			prefixVec = expTree->m_treeRoot->getPrefixFromExpressionTree();
			
		}  
		else{
			throw ErrorClass("Error in getNonlinearExpressionTreeInPrefix, rowIdx not valid");
		}
		return prefixVec;	
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	} 
}//getNonlinearExpressionTreeInPrefix

std::map<int, OSExpressionTree*> OSInstance::getAllNonlinearExpressionTrees(){
	if(m_bProcessExpressionTrees == true) return m_mapExpressionTrees;
	std::map<int, int> foundIdx;
	std::map<int, int>::iterator pos;
	OSnLNodePlus *nlNodePlus;
	OSExpressionTree *expTree;  
	m_iObjectiveNumberNonlinear = 0;   
	m_iConstraintNumberNonlinear = 0;    
	int i;   
	// important -- tell the nl nodes not to destroy the OSExpression Objects
	if( instanceData->nonlinearExpressions->numberOfNonlinearExpressions > 0 && instanceData->nonlinearExpressions->nl != NULL){
		for( i = 0; i < instanceData->nonlinearExpressions->numberOfNonlinearExpressions; i++){
			instanceData->nonlinearExpressions->nl[i]->m_bDeleteExpressionTree = false;
		}
	}
	int index;  
	// kipp -- what should we return if instanceData->nonlinearExpressions->numberOfNonlinearExpressions is zero
	for(i = 0; i < instanceData->nonlinearExpressions->numberOfNonlinearExpressions; i++){
		index = instanceData->nonlinearExpressions->nl[ i]->idx;
		if(foundIdx.find( index) != foundIdx.end() ){  
		//if(foundIdx[ index] > 0 ){ 
			//std::cout << "OLD INDEX FOUND " << index << std::endl;
			//std::cout << "foundIdx[ index] " << index << std::endl;
			// found an existing index
			// important -- at this time m_mapExpressionTrees[ index] points to 
			// the last OSExpressionTree with this index, it does not point to the 
			// the just found OSExpressionTree with this index
			nlNodePlus = new OSnLNodePlus();
			//expTree = new OSExpressionTree(); 
			expTree =  instanceData->nonlinearExpressions->nl[ i]->osExpressionTree;
			// set left child to old index and right child to new one 
			nlNodePlus->m_mChildren[ 0] = m_mapExpressionTrees[ index]->m_treeRoot;
			nlNodePlus->m_mChildren[ 1] = instanceData->nonlinearExpressions->nl[ i]->osExpressionTree->m_treeRoot;
			// we must delete the Expression tree corresponding to the old index value but not the nl nodes
			instanceData->nonlinearExpressions->nl[ foundIdx[ index]  ]->m_bDeleteExpressionTree = true;
			instanceData->nonlinearExpressions->nl[ foundIdx[ index]  ]->osExpressionTree->bDestroyNlNodes = false;
			//point to the new expression tree
			m_mapExpressionTrees[ index] = expTree;
			m_mapExpressionTrees[ index]->m_treeRoot = nlNodePlus;
			foundIdx[ index] = i;
		}
		else{  
			// we have a new index
			m_mapExpressionTrees[ index] = instanceData->nonlinearExpressions->nl[ i]->osExpressionTree;
			m_mapExpressionTrees[ index]->m_treeRoot = instanceData->nonlinearExpressions->nl[ i]->osExpressionTree->m_treeRoot;
			foundIdx[ index] = i;
		}
		//foundIdx[ index]++;	 
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
	return m_mapExpressionTrees;
}// getAllNonlinearExpressionTrees

std::map<int, OSExpressionTree*> OSInstance::getAllNonlinearExpressionTreesMod(){
	if( m_bProcessExpressionTreesMod == true ) return m_mapExpressionTreesMod;
 	m_bProcessExpressionTreesMod = true;
	// make sure we have the modified map available
	if( m_bNonLinearStructuresInitialized == false) initializeNonLinearStructures( );
	return m_mapExpressionTreesMod;
}// getAllNonlinearExpressionTreesMod


/**
 * Get the format of the time domain ("stages"/"interval")
 * 
 * @return the format of the time domain. 
 */
std::string OSInstance::getTimeDomainFormat()
{	if (instanceData->timeDomain == NULL)
		return "";
	if (instanceData->timeDomain->interval != NULL)
		return "interval";
	if (instanceData->timeDomain->stages != NULL)
		return "stages";
	return "";
} 

/**
 * Get the number of stages that make up the time domain
 * 
 * @return the number of time stages. 
 */
int OSInstance::getTimeDomainStageNumber()
{	if (instanceData->timeDomain == NULL)
		return 1;
	if (instanceData->timeDomain->interval != NULL)
		; //throw an error
	if (instanceData->timeDomain->stages == NULL)
		return 1;
	return instanceData->timeDomain->stages->numberOfStages;
} 
	
/**
 * Get the names of the stages (NULL or empty string ("") if a stage has not been given a name
 * 
 * @return the names of time stages. 
 */
std::string* OSInstance::getTimeDomainStageNames()
{	if (instanceData->timeDomain == NULL)
		return NULL;
	if (instanceData->timeDomain->interval != NULL)
		return NULL; //throw an error
	if (instanceData->timeDomain->stages == NULL)
		return NULL;
	if (m_msTimeDomainStageNames != NULL)
		delete [] m_msTimeDomainStageNames;
	if (instanceData->timeDomain->stages->numberOfStages == 0)
		return NULL;
	m_msTimeDomainStageNames = new std::string[instanceData->timeDomain->stages->numberOfStages];
	for (int i = 0; i < instanceData->timeDomain->stages->numberOfStages; i++)
		m_msTimeDomainStageNames[i] = instanceData->timeDomain->stages->stage[i]->name;
	return m_msTimeDomainStageNames;
} 
	
/**
 * Get the number of variables contained in each time stage
 * 
 * @return a vector of size numberOfStages. 
 */
int* OSInstance::getTimeDomainStageNumberOfVariables()
{	if (instanceData->timeDomain == NULL)
		return NULL;
	if (instanceData->timeDomain->interval != NULL)
		return NULL; //throw an error
	if (instanceData->timeDomain->stages == NULL)
		return NULL;
	if (m_miTimeDomainStageVariableNumber != NULL) 
		delete [] m_miTimeDomainStageVariableNumber;
	if (instanceData->timeDomain->stages->numberOfStages == 0)
		return NULL;
	m_miTimeDomainStageVariableNumber = new int[instanceData->timeDomain->stages->numberOfStages];
	for (int i = 0; i < instanceData->timeDomain->stages->numberOfStages; i++) 
		m_miTimeDomainStageVariableNumber[i] = instanceData->timeDomain->stages->stage[i]->variables->numberOfVariables;
	return m_miTimeDomainStageVariableNumber;
} 
	
/**
 * Get the number of variables contained in each time stage
 * 
 * @return a vector of size numberOfStages. 
 */
int* OSInstance::getTimeDomainStageNumberOfConstraints()
{	if (instanceData->timeDomain == NULL)
		return NULL;
	if (instanceData->timeDomain->interval != NULL)
		return NULL; //throw an error
	if (instanceData->timeDomain->stages == NULL)
		return NULL;
	if (m_miTimeDomainStageConstraintNumber != NULL)
		delete [] m_miTimeDomainStageConstraintNumber;
	if (instanceData->timeDomain->stages->numberOfStages == 0)
		return NULL;
	m_miTimeDomainStageConstraintNumber = new int[instanceData->timeDomain->stages->numberOfStages];
	for (int i = 0; i < instanceData->timeDomain->stages->numberOfStages; i++)
		m_miTimeDomainStageConstraintNumber[i] = instanceData->timeDomain->stages->stage[i]->constraints->numberOfConstraints;
	return m_miTimeDomainStageConstraintNumber;
} 

/**
 * Get the number of objectives contained in each time stage
 * 
 * @return a vector of size numberOfStages. 
 */
int* OSInstance::getTimeDomainStageNumberOfObjectives()
{	if (instanceData->timeDomain == NULL)
		return NULL;
	if (instanceData->timeDomain->interval != NULL)
		return NULL; //throw an error
	if (instanceData->timeDomain->stages == NULL)
		return NULL;
	if (m_miTimeDomainStageObjectiveNumber != NULL)
		delete [] m_miTimeDomainStageObjectiveNumber;
	if (instanceData->timeDomain->stages->numberOfStages == 0)
		return NULL;
	m_miTimeDomainStageObjectiveNumber = new int[instanceData->timeDomain->stages->numberOfStages];
	for (int i = 0; i < instanceData->timeDomain->stages->numberOfStages; i++)
		m_miTimeDomainStageObjectiveNumber[i] = instanceData->timeDomain->stages->stage[i]->objectives->numberOfObjectives;
	return m_miTimeDomainStageObjectiveNumber;
} 
	
/**
 * Get the list of variables in each stage
 * 
 * @return one array of integers for each stage. 
 */
int** OSInstance::getTimeDomainStageVarList()
{	if (instanceData->timeDomain == NULL)
		return NULL;
	if (instanceData->timeDomain->interval != NULL)
		return NULL; //throw an error
	if (instanceData->timeDomain->stages == NULL)
		return NULL;
	if (m_miTimeDomainStageVariableNumber == NULL)
		return NULL;
	if (m_mmiTimeDomainStageVarList != NULL)
		delete [] m_mmiTimeDomainStageVarList;
	if (instanceData->timeDomain->stages->numberOfStages == 0)
		return NULL;
	m_mmiTimeDomainStageVarList = new int*[instanceData->timeDomain->stages->numberOfStages];
	for (int i = 0; i < instanceData->timeDomain->stages->numberOfStages; i++)
	{	m_mmiTimeDomainStageVarList[i] = new int[m_miTimeDomainStageVariableNumber[i]];
		if (instanceData->timeDomain->stages->stage[i]->variables->startIdx == -1)
			for (int j = 0; j < m_miTimeDomainStageVariableNumber[i]; j++)
				m_mmiTimeDomainStageVarList[i][j] = instanceData->timeDomain->stages->stage[i]->variables->var[j]->idx;
		else
			for (int j = 0; j < m_miTimeDomainStageVariableNumber[i]; j++)
				m_mmiTimeDomainStageVarList[i][j] = instanceData->timeDomain->stages->stage[i]->variables->startIdx + j;
	}
	return m_mmiTimeDomainStageVarList;
} 
	
/**
 * Get the list of constraints in each stage
 * 
 * @return one array of integers for each stage. 
 */
int** OSInstance::getTimeDomainStageConList()
{	if (instanceData->timeDomain == NULL)
		return NULL;
	if (instanceData->timeDomain->interval != NULL)
		return NULL; //throw an error
	if (instanceData->timeDomain->stages == NULL)
		return NULL;
	if (m_miTimeDomainStageConstraintNumber == NULL)
		return NULL;
	if (m_mmiTimeDomainStageConList != NULL)
		delete [] m_mmiTimeDomainStageConList;
	if (instanceData->timeDomain->stages->numberOfStages == 0)
		return NULL;
	m_mmiTimeDomainStageConList = new int*[instanceData->timeDomain->stages->numberOfStages];
	for (int i = 0; i < instanceData->timeDomain->stages->numberOfStages; i++)
	{	m_mmiTimeDomainStageConList[i] = new int[m_miTimeDomainStageConstraintNumber[i]];
		if (instanceData->timeDomain->stages->stage[i]->constraints->startIdx == -1)
			for (int j = 0; j < m_miTimeDomainStageConstraintNumber[i]; j++)
				m_mmiTimeDomainStageConList[i][j] = instanceData->timeDomain->stages->stage[i]->constraints->con[j]->idx;
		else
			for (int j = 0; j < m_miTimeDomainStageConstraintNumber[i]; j++)
				m_mmiTimeDomainStageConList[i][j] = instanceData->timeDomain->stages->stage[i]->constraints->startIdx + j;
	}
	return m_mmiTimeDomainStageConList;
} 
/**
 * Get the list of objectives in each stage
 * 
 * @return one array of integers for each stage. 
 */
int** OSInstance::getTimeDomainStageObjList()
{	if (instanceData->timeDomain == NULL)
		return NULL;
	if (instanceData->timeDomain->interval != NULL)
		return NULL; //throw an error
	if (instanceData->timeDomain->stages == NULL)
		return NULL;
	if (m_miTimeDomainStageObjectiveNumber == NULL)
		return NULL;
	if (m_mmiTimeDomainStageObjList != NULL)
		delete [] m_mmiTimeDomainStageObjList;
	if (instanceData->timeDomain->stages->numberOfStages == 0)
		return NULL;
	m_mmiTimeDomainStageObjList = new int*[instanceData->timeDomain->stages->numberOfStages];
	for (int i = 0; i < instanceData->timeDomain->stages->numberOfStages; i++)
	{	m_mmiTimeDomainStageObjList[i] = new int[m_miTimeDomainStageObjectiveNumber[i]];
		if (instanceData->timeDomain->stages->stage[i]->objectives->startIdx == 0)
			for (int j = 0; j < m_miTimeDomainStageObjectiveNumber[i]; j++)
				m_mmiTimeDomainStageObjList[i][j] = instanceData->timeDomain->stages->stage[i]->objectives->obj[j]->idx;
		else
			for (int j = 0; j < m_miTimeDomainStageObjectiveNumber[i]; j++)
				m_mmiTimeDomainStageObjList[i][j] = instanceData->timeDomain->stages->stage[i]->objectives->startIdx - j;
	}
	return m_mmiTimeDomainStageObjList;
} 

/**
 * Get the start for the time domain interval
 * 
 * @return start end of the time interval. 
 */
double OSInstance::getTimeDomainIntervalStart()
{	if (instanceData->timeDomain == NULL)
		return 0.0;
	if (instanceData->timeDomain->stages != NULL)
		return 0.0; //throw an error
	if (instanceData->timeDomain->interval == NULL)
		return 0.0;
	return instanceData->timeDomain->interval->start;
} 

/**
 * Get the horizon for the time domain interval
 * 
 * @return the end of the time interval. 
 */
double OSInstance::getTimeDomainIntervalHorizon()
{	if (instanceData->timeDomain == NULL)
		return 0.0;
	if (instanceData->timeDomain->stages != NULL)
		return 0.0; //throw an error
	if (instanceData->timeDomain->interval == NULL)
		return 0.0;
	return instanceData->timeDomain->interval->horizon;
} 




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
	//if(instanceData->variables->numberOfVariables != -1  && instanceData->variables->numberOfVariables != number){
	//	delete[] instanceData->variables->var;
	//	instanceData->variables->var = NULL;
	//} 
	if(instanceData->variables == NULL) instanceData->variables = new Variables();
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
	//if(lowerBound != -OSDBL_MAX && lowerBound != -OSDBL_MAX)instanceData->variables->var[index]->lb = lowerBound;
	instanceData->variables->var[index]->lb = lowerBound;
	if(upperBound != OSDBL_MAX && upperBound != OSDBL_MAX)instanceData->variables->var[index]->ub = upperBound;
	instanceData->variables->var[index]->type = type;
	if(init != OSNAN) instanceData->variables->var[index]->init = init;
	instanceData->variables->var[index]->initString = initString;
	return true;
}//addVariable


bool OSInstance::setVariables(int number, string *names, double *lowerBounds, 
	double *upperBounds, char *types, double *inits, string *initsString){
	if(number <= 0) return false;
	try{
		if(instanceData->variables == NULL){
			throw ErrorClass("There is no variables object");
		}
		if(instanceData->variables->numberOfVariables != number){
			throw ErrorClass("input number of variables not equal to number in class");
		}
		//instanceData->variables->var = new Variable*[number];
		int i;
		for(i = 0; i < number; i++){
			instanceData->variables->var[ i] = new Variable();
		}
		if(names  != NULL){
			for(i = 0; i < number; i++) instanceData->variables->var[i]->name = names[i];   			
		}
		if(lowerBounds != NULL){
			for(i = 0; i < number; i++){
				if(lowerBounds[i] != -OSDBL_MAX && lowerBounds[i] != -OSDBL_MAX)instanceData->variables->var[i]->lb = lowerBounds[i];  
			}
		}
		if(upperBounds != NULL){
			for(i = 0; i < number; i++){
				if(upperBounds[i] != OSDBL_MAX && upperBounds[i] != OSDBL_MAX)instanceData->variables->var[i]->ub = upperBounds[i]; 
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
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass(  eclass.errormsg); 
	}
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
	try{
		if(instanceData->objectives == NULL){
			throw ErrorClass("there is no objectives object");		
		}		
		if(instanceData->objectives->numberOfObjectives != number){
			throw ErrorClass("input number of objective not equal to number in class");		
		}
		if(number == 0) return true;
		int i = 0;
		for(i = 0; i < number; i++)instanceData->objectives->obj[i] = new Objective();
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
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass(  eclass.errormsg); 
	}
}//setObjectives


bool OSInstance::setConstraintNumber(int number){
	if(number < 0) return false;
	if(instanceData->constraints == NULL) instanceData->constraints = new Constraints();
	if(number == 0){
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
	if(lowerBound != -OSDBL_MAX && lowerBound != -OSDBL_MAX) instanceData->constraints->con[ index]->lb = lowerBound;
	if(upperBound != OSDBL_MAX && upperBound != OSDBL_MAX)instanceData->constraints->con[ index]->ub = upperBound;
	instanceData->constraints->con[ index]->constant = constant;
	return true;
}//addConstraint


bool OSInstance::setConstraints(int number, string* names, double* lowerBounds, double* upperBounds, double* constants){
	if(number < 0) return false;
	if(number == 0){
		// this is done in setConstraintNumber
		//instanceData->constraints = new Constraints();
		//instanceData->constraints->numberOfConstraints = 0;
		//instanceData->constraints->con = NULL;
		return true;
	}
	try{
		
		if(instanceData->constraints  == NULL){
			throw ErrorClass("there is no constraints object");		
		}		
		if(instanceData->constraints->numberOfConstraints != number){
			throw ErrorClass("input number of constraints not equal to number in class");		
		}
		int i = 0;
		for(i = 0; i < number; i++){
			instanceData->constraints->con[i] = new Constraint();
		}
		if(names != NULL){
			for(i = 0; i < number; i++) instanceData->constraints->con[i]->name = names[i];   			
		}
		if(lowerBounds != NULL){
			for(i = 0; i < number; i++){
				if(lowerBounds[i] != -OSDBL_MAX && lowerBounds[i] != -OSDBL_MAX)instanceData->constraints->con[i]->lb = lowerBounds[i]; 
			}
		}
		if(upperBounds != NULL){
			for(i = 0; i < number; i++){
				if(upperBounds[i] != OSDBL_MAX && upperBounds[i] != OSDBL_MAX)instanceData->constraints->con[i]->ub = upperBounds[i]; 
			}
		}   
		if(constants != NULL){
			for(i = 0; i < number; i++) instanceData->constraints->con[i]->constant = constants[i];   			
		}
		return true;
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass(  eclass.errormsg); 
	}
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
	if(number != (end - begin) + 1) return false;
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

bool OSInstance::setQuadraticTermsInNonlinearExpressions(int numQPTerms, int* rowIndexes, int* varOneIndexes, int* varTwoIndexes, double* coefficients){
		instanceData->nonlinearExpressions->numberOfNonlinearExpressions = numQPTerms;
		instanceData->nonlinearExpressions->nl = new Nl*[ numQPTerms ];
		// define the vectors
		OSnLNode *nlNodePoint;
		OSnLNodeVariable *nlNodeVariablePoint;
		std::vector<OSnLNode*> nlNodeVec;
		//
		//
		int i;
		for(i = 0; i < numQPTerms; i++){
			instanceData->nonlinearExpressions->nl[ i] = new Nl();
			instanceData->nonlinearExpressions->nl[ i]->idx = rowIndexes[ i];
			instanceData->nonlinearExpressions->nl[ i]->osExpressionTree = new OSExpressionTree();
		// create a variable nl node for x0
		nlNodeVariablePoint = new OSnLNodeVariable();
		nlNodeVariablePoint->idx = varOneIndexes[ i];
		// give this variable the coefficient
		nlNodeVariablePoint->coef = coefficients[ i];
		nlNodeVec.push_back( nlNodeVariablePoint);
		// create the nl node for x1
		nlNodeVariablePoint = new OSnLNodeVariable();
		nlNodeVariablePoint->idx = varTwoIndexes[ i];
		nlNodeVec.push_back( nlNodeVariablePoint);
		// create the nl node for *
		nlNodePoint = new OSnLNodeTimes();
		nlNodeVec.push_back( nlNodePoint);
		// the vectors are in postfix format
		// now the expression tree
		instanceData->nonlinearExpressions->nl[ i]->osExpressionTree->m_treeRoot =
			nlNodeVec[ 0]->createExpressionTreeFromPostfix( nlNodeVec);
		nlNodeVec.clear();
		}
	return true;
}//setQuadraticTermsInNonlinearExpressions

bool OSInstance::initializeNonLinearStructures( ){
	std::map<int, OSExpressionTree*>::iterator posMapExpTree;
	if( m_bNonLinearStructuresInitialized == true) return true;
	if( m_bProcessVariables == false) processVariables();
	if( m_bProcessObjectives == false) processObjectives();
	if( m_bProcessConstraints == false) processConstraints();
	m_iVariableNumber = instanceData->variables->numberOfVariables;
	m_iConstraintNumber = instanceData->constraints->numberOfConstraints;
	m_iObjectiveNumber = instanceData->objectives->numberOfObjectives;
	// get all of the expression trees
	if( m_bProcessExpressionTrees == false) getAllNonlinearExpressionTrees();
	// before proceeding get a copy of the map of the Expression Trees
	if( m_bDuplicateExpressionTreesMap == false) duplicateExpressionTreesMap();
	// now create all of the variable maps for each expression tree
	for(posMapExpTree = m_mapExpressionTreesMod.begin(); posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree){	
		(posMapExpTree->second)->getVariableIndiciesMap() ;
	}
	// add the quadratic terms if necessary
	if(getNumberOfQuadraticTerms() > 0) addQTermsToExressionTree();
	// now get the map of all nonlinear variables
	getAllNonlinearVariablesIndexMap( );
	getDenseObjectiveCoefficients();
	m_mdConstraintFunctionValues = new double[ this->instanceData->constraints->numberOfConstraints];
	m_mdObjectiveFunctionValues = new double[ this->instanceData->objectives->numberOfObjectives];
	//m_mdObjGradient = new double[ this->instanceData->variables->numberOfVariables];
	m_bNonLinearStructuresInitialized = true;
	return true;
}

SparseJacobianMatrix *OSInstance::getJacobianSparsityPattern( ){
	// if already called return the sparse Jacobian
	// it is important that this method NOT get called twice -- if
	// there are linear terms in <linearConstraintCoefficients> that
	// also appear in <nonlinearExpressions> then they will keep getting added
	// to the modified expession tree with each call to this method
	if( m_bSparseJacobianCalculated == true) return m_sparseJacMatrix;
	//std::cout << "INSIDE GET JACOBIAN SPARSITY PATTERN" << std::endl;
	// determine if we are in column or row major
	getLinearConstraintCoefficientMajor();
	// make sure the data structures have been inialized
	if( m_bNonLinearStructuresInitialized == false) initializeNonLinearStructures( );
	try{
		if( m_bColumnMajor == true){
			 if( getSparseJacobianFromColumnMajor( ) == false) throw ErrorClass("An error occurred in getSpareJacobianFromColumnMajor");
		}
		else {
			if( getSparseJacobianFromRowMajor( ) == false) throw ErrorClass("An error occurred in getSpareJacobianFromRowMajor");
		}
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass(  eclass.errormsg); 
	}
	// now fill in the arrays of the sparseJacMatrix
	m_sparseJacMatrix = new SparseJacobianMatrix();
	// we point to memory already created so don't 
	// destroy during garbage collection
	m_sparseJacMatrix->bDeleteArrays = false;
	m_sparseJacMatrix->valueSize = 	m_iJacValueSize;
	m_sparseJacMatrix->starts = m_miJacStart;
	m_sparseJacMatrix->conVals = m_miJacNumConTerms;
	m_sparseJacMatrix->indexes = m_miJacIndex;
	m_sparseJacMatrix->values = m_mdJacValue;
	m_bSparseJacobianCalculated = true;
	return m_sparseJacMatrix;
}//getJacobianSparsityPatter

bool OSInstance::addQTermsToExressionTree(){
	int i, k, idx;
	// get the number of qTerms
	int numQTerms = instanceData->quadraticCoefficients->numberOfQuadraticTerms;	
	if(numQTerms <= 0 || m_bQTermsAdded == true) return true;
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
			expTree = m_mapExpressionTreesMod[ idx];
			if(  expTree->m_bIndexMapGenerated == false) expTree->getVariableIndiciesMap();
			if( (*expTree->mapVarIdx).find( nlNodeVariableOne->idx) == (*expTree->mapVarIdx).end()  ){
				// add to map
				k = (*expTree->mapVarIdx).size();
				(*expTree->mapVarIdx)[ nlNodeVariableOne->idx] =  k + 1;
				std::cout << "ADDED THE FOLLOWING VAIRABLE TO THE MAP" <<  nlNodeVariableOne->idx << std::endl;
			}
			nlNodeVariableOne->coef = m_quadraticTerms->coefficients[ i];
			nlNodeVariableTwo = new OSnLNodeVariable();
			nlNodeVariableTwo->idx = m_quadraticTerms->varTwoIndexes[ i];
			// see if the variable indexed by nlNodeVariableTwo->idx is in the expression tree for row idx
			// if not, add to mapVarIdx
			if( (*expTree->mapVarIdx).find( nlNodeVariableTwo->idx) == (*expTree->mapVarIdx).end()  ){
				// add to map
				k = (*expTree->mapVarIdx).size();
				(*expTree->mapVarIdx)[ nlNodeVariableTwo->idx] =  k + 1;
				std::cout << "ADDED THE FOLLOWING VAIRABLE TO THE MAP" <<  nlNodeVariableTwo->idx << std::endl;
			}
			nlNodeVariableTwo->coef = 1.;
			// now multiply the two new variable nodes together
			nlNodeTimes = new OSnLNodeTimes();
			nlNodeTimes->m_mChildren[ 0] = nlNodeVariableOne;
			nlNodeTimes->m_mChildren[ 1] = nlNodeVariableTwo;		
			// now add the result to the expression tree
			nlNodePlus = new OSnLNodePlus();
			nlNodePlus->m_mChildren[ 0] = expTree->m_treeRoot;
			nlNodePlus->m_mChildren[ 1] = nlNodeTimes;
			//expTree = new OSExpressionTree();
			expTree->m_treeRoot = nlNodePlus ;
			// get rid of old variable map
			if(expTree->m_bIndexMapGenerated == true){
				delete expTree->mapVarIdx;
				expTree->mapVarIdx = NULL;
				expTree->m_bIndexMapGenerated = false;
			}	
			//expTree->m_bIndexMapGenerated = false;
			//m_mapExpressionTreesMod[ idx ]  = expTree;	
			//expTree->mapVarIdx = m_mapExpressionTreesMod[ idx]->mapVarIdx;
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
			if(idx < 0){
				m_iObjectiveNumberNonlinear++;
				m_bProcessExpressionTrees = true;
			}
			else{
				m_iConstraintNumberNonlinear++;
				m_bProcessExpressionTrees = true;
			}
			std::cout << "NUMBER OF EXPRESSION TREES = "  << m_mapExpressionTreesMod.size() <<std::endl;
			std::cout << "NUMBER OF NONLINEAR OBJECTIVES = "  << getNumberOfNonlinearObjectives() <<std::endl;
		} 
		// if there were no nonlinear terms make this the expression tree
		if(m_iNonlinearExpressionNumber <= 0) m_mapExpressionTrees = m_mapExpressionTreesMod;
		m_bQTermsAdded =true;
	}
	return true;
}

double OSInstance::calculateFunctionValue(int idx, double *x, bool new_x){
	try{

		int i, j;
		double dvalue = 0;
		if( m_binitForAlgDiff == false) initForAlgDiff();
		if( m_bSparseJacobianCalculated == false) getJacobianSparsityPattern();
		if(idx >= 0){ // we have a constraint
			// make sure the index idx is valid
			if( getConstraintNumber() <= idx  ) throw 
			ErrorClass("constraint index not valid in OSInstance::calculateFunctionValue");
			if( new_x == false) return *(m_mdConstraintFunctionValues + idx);
			// get the nonlinear part
			if( m_mapExpressionTreesMod.find( idx) != m_mapExpressionTreesMod.end() ){
				dvalue = m_mapExpressionTreesMod[ idx]->calculateFunction( x,  new_x);
				//dvalue = vdFunVals[ idx + 1];
			}
			// now the linear part
			// be careful, loop over only the constant terms in sparseJacMatrix
			i = m_sparseJacMatrix->starts[ idx];
			j = m_sparseJacMatrix->starts[ idx + 1 ];
			//while ( i <  j &&  (i - m_sparseJacMatrix->starts[ idx])  < m_sparseJacMatrix->conVals[ idx] ){
			while ( (i - m_sparseJacMatrix->starts[ idx])  < m_sparseJacMatrix->conVals[ idx] ){
				//std::cout << "m_sparseJacMatrix->values[ i] " << m_sparseJacMatrix->values[ i] << std::endl;
				//std::cout << "m_sparseJacMatrix->indexes[ i] " << m_sparseJacMatrix->indexes[ i] << std::endl;
				dvalue += m_sparseJacMatrix->values[ i]*x[ m_sparseJacMatrix->indexes[ i] ];
				i++;
			}	
			// add in the constraint function constant
			dvalue += m_mdConstraintConstants[ idx ];
			return dvalue;
		}
		else{ // we have an objective function
			// make sure the index idx is valid
			if( getObjectiveNumber() <= ( abs( idx) - 1) ) throw 
			ErrorClass("objective function index not valid in OSInstance::calculateFunctionValue");
			if( new_x == false) return *(m_mdObjectiveFunctionValues + ( abs( idx) - 1));
			// get the nonlinear part
			if( m_mapExpressionTreesMod.find( idx) != m_mapExpressionTreesMod.end() ){
				dvalue = m_mapExpressionTreesMod[ idx]->calculateFunction( x,  new_x);
			}
			// get linear part
			SparseVector **objCoef = getObjectiveCoefficients();
			SparseVector *obj = objCoef[ abs( idx) - 1];
			for(i = 0; i < obj->number; i++){
				dvalue += x[ obj->indexes[i]]*(obj->values[ i]);
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


double *OSInstance::calculateAllConstraintFunctionValues( double* x, double *objLambda, double *conLambda,
	bool new_x, int highestOrder){	
	try{
		if( new_x == true || (highestOrder > m_iHighestOrderEvaluated)  ) 
			getIterateResults(x, objLambda, conLambda, new_x,  highestOrder);
	}
 	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	} 
	return m_mdConstraintFunctionValues;
}//calculateAllConstraintFunctionValues


double *OSInstance::calculateAllConstraintFunctionValues(double* x, bool new_x){
	try{
		m_iHighestOrderEvaluated = -1;
		if( new_x == false) return m_mdConstraintFunctionValues;
		int idx, numConstraints;
		numConstraints = getConstraintNumber();
		// loop over all constraints
		for(idx = 0; idx < numConstraints; idx++){
			m_mdConstraintFunctionValues[ idx]  = calculateFunctionValue(idx, x, new_x);	
		}
		
	}
 	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	} 
	return m_mdConstraintFunctionValues;	
}//end calculateAllConstraintFunctionValues


double *OSInstance::calculateAllObjectiveFunctionValues( double* x, double *objLambda, double *conLambda,
	bool new_x, int highestOrder){	
	try{
		if( new_x == true || (highestOrder > m_iHighestOrderEvaluated)  ) 
			getIterateResults(x, objLambda, conLambda, new_x,  highestOrder);
	}
 	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	} 
 	return m_mdObjectiveFunctionValues;
}//calculateAllConstraintFunctionValues


double *OSInstance::calculateAllObjectiveFunctionValues( double* x, bool new_x){	
	try{
		m_iHighestOrderEvaluated = -1;
		if( new_x == false) return m_mdObjectiveFunctionValues;
		int idx, numObjectives;
		numObjectives = getObjectiveNumber();
		// loop over all constraints
		for(idx = 0; idx < numObjectives; idx++){
			m_mdObjectiveFunctionValues[ idx]  = calculateFunctionValue(-idx -1, x, new_x);	
		}
	}
 	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	} 
	return m_mdObjectiveFunctionValues;
}//calculateAllObjectiveFunctionValues


SparseJacobianMatrix *OSInstance::calculateAllConstraintFunctionGradients(double* x, double *objLambda, double *conLambda,
		bool new_x, int highestOrder){
	try{
		if(highestOrder < 1 ) throw ErrorClass("When calling calculateAllConstraintFunctionGradients highestOrder should be 1 or 2");
		if( new_x == true || (highestOrder > m_iHighestOrderEvaluated)  ) 
			getIterateResults(x, objLambda, conLambda,  new_x,  highestOrder);
	}//end try
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	} 
	return m_sparseJacMatrix;
}//calculateAllConstraintFunctionGradients	



SparseVector *OSInstance::calculateConstraintFunctionGradient(double* x, double *objLambda, double *conLambda,
		int idx, bool new_x, int highestOrder){
	try{
		if(highestOrder < 1 ) throw ErrorClass("When calling calculateConstraintFunctionGradient highestOrder should be 1 or 2");
		if(idx > instanceData->variables->numberOfVariables ) 
			throw ErrorClass("invalid index passed to calculateConstraintFunctionGrad");
		SparseVector *sp;
		sp = new SparseVector();
		sp->bDeleteArrays = true;
		int i;
		if( new_x == true || (highestOrder > m_iHighestOrderEvaluated)  ) 
			getIterateResults(x, objLambda, conLambda,  new_x,  highestOrder);
		sp->number = m_miJacStart[ idx + 1] - m_miJacStart[ idx];
		sp->values = new double[ sp->number];
		sp->indexes = new int[ sp->number];
		for(i = 0; i < sp->number; i++){
			sp->values[ i] = m_mdJacValue[ m_miJacStart[ idx] +  i];
			sp->indexes[ i] = m_miJacIndex[ m_miJacStart[ idx] +  i];
		}
		return sp;
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	} 
}//calculateConstraintFunctionGradient


SparseVector *OSInstance::calculateConstraintFunctionGradient(double* x, int idx, bool new_x){
	try{
		if(idx > instanceData->variables->numberOfVariables ) 
			throw ErrorClass("invalid index passed to calculateConstraintFunctionGrad");
		SparseVector *sp;
		sp = new SparseVector();
		sp->bDeleteArrays = true;
		int i;
		if( new_x == true || (1 > m_iHighestOrderEvaluated)  ) 
			getIterateResults(x, NULL, NULL,  new_x,  1);
		sp->number = m_miJacStart[ idx + 1] - m_miJacStart[ idx];
		sp->values = new double[ sp->number];
		sp->indexes = new int[ sp->number];
		for(i = 0; i < sp->number; i++){
			sp->values[ i] = m_mdJacValue[ m_miJacStart[ idx] +  i];
			sp->indexes[ i] = m_miJacIndex[ m_miJacStart[ idx] + i];
		}
		return sp;
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	} 
}//calculateConstraintFunctionGradient


double **OSInstance::calculateAllObjectiveFunctionGradients(double* x, double *objLambda, double *conLambda,
		bool new_x, int highestOrder){
	try{
		if(highestOrder < 1 ) throw ErrorClass("When calling calculateAllObjectiveFunctionGradients highestOrder should be 1 or 2");
		if( new_x == true || (highestOrder > m_iHighestOrderEvaluated)  ) {
			std::map<int, OSExpressionTree*>::iterator posMapExpTree;
			for(posMapExpTree = m_mapExpressionTreesMod.begin(); posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree){
				if(posMapExpTree->first < 0){ // this nonlinear expression indexes an objective function
					m_mmdObjGradient[ abs( posMapExpTree->first) - 1 ] = calculateObjectiveFunctionGradient(x, objLambda, conLambda, 
							posMapExpTree->first, new_x, highestOrder);
				}	
			}
		}
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	} 
	return m_mmdObjGradient;
}// calculateAllObjectiveFunctionGradients

double *OSInstance::calculateObjectiveFunctionGradient(double* x, double *objLambda, double *conLambda,
		int objIdx, bool new_x, int highestOrder){
	/* if we are just doing an objective function gradient we should do a zero order forward sweep
	 * and a reverse first order reverse sweep
	 */
	try{
		if(highestOrder < 1 ) throw ErrorClass("When calling calculateObjectiveFunctionGradient highestOrder should be 1 or 2");	
		if( new_x == true || (highestOrder > m_iHighestOrderEvaluated)  ) {
			int domainIdx = 0;	
			std::map<int, OSExpressionTree*>::iterator posMapExpTree;
			std::map<int, int>::iterator posVarIndexMap;		
			int iHighestOrderEvaluatedStore;
			unsigned int i;
			iHighestOrderEvaluatedStore = m_iHighestOrderEvaluated;
			for(posMapExpTree = m_mapExpressionTreesMod.begin(); posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree){
				//kipp: modify for more than one obj
				if(posMapExpTree->first == objIdx){
					if( new_x == true ){
						if( m_vdX.size() > 0) m_vdX.clear();
						for(posVarIndexMap = m_mapAllNonlinearVariablesIndex.begin(); posVarIndexMap != m_mapAllNonlinearVariablesIndex.end(); ++posVarIndexMap){
							m_vdX.push_back( x[ posVarIndexMap->first]) ;
						}
						if( (m_bCppADFunIsCreated == false || m_bCppADMustReTape == true )  && (m_mapExpressionTreesMod.size() > 0) ) {
							createCppADFun( m_vdX);
						}						
					}	
					
					if(( new_x == true ) || (m_iHighestOrderEvaluated < 0) )this->forwardAD(0, m_vdX);
					
					if(( new_x == true ) || (m_iHighestOrderEvaluated < 1) ) {
						m_vdRangeUnitVec[ domainIdx] = 1.;
						m_vdYjacval = this->reverseAD(1, m_vdRangeUnitVec);
						for(i = 0; i < m_iNumberOfNonlinearVariables; i++){
							m_mmdObjGradient[ abs( objIdx) - 1 ][ m_miNonLinearVarsReverseMap[ i]] = m_vdYjacval[ i] + 
								m_mmdDenseObjectiveCoefficients[  abs( objIdx) - 1][ m_miNonLinearVarsReverseMap[ i]];
						}
					}
					m_iHighestOrderEvaluated = iHighestOrderEvaluatedStore;
					m_vdRangeUnitVec[ domainIdx] = 0.;
					// exit the loop
					break;
				}
				domainIdx++;
			}
		}			
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	} 
	return m_mmdObjGradient[abs( objIdx) - 1];
}//calculateObjectiveFunctionGradient


double *OSInstance::calculateObjectiveFunctionGradient(double* x, int objIdx, bool new_x){
	try{
		int domainIdx = 0;	
		std::map<int, OSExpressionTree*>::iterator posMapExpTree;
		std::map<int, int>::iterator posVarIndexMap;	
		unsigned int i;
		int  iHighestOrderEvaluatedStore;	
		iHighestOrderEvaluatedStore = m_iHighestOrderEvaluated;
		for(posMapExpTree = m_mapExpressionTreesMod.begin(); posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree){
			if(posMapExpTree->first == objIdx){
				if( new_x == true ){
					if( m_vdX.size() > 0) m_vdX.clear();
					for(posVarIndexMap = m_mapAllNonlinearVariablesIndex.begin(); posVarIndexMap != m_mapAllNonlinearVariablesIndex.end(); ++posVarIndexMap){
						m_vdX.push_back( x[ posVarIndexMap->first]) ;
					}
					if( (m_bCppADFunIsCreated == false || m_bCppADMustReTape == true )  && (m_mapExpressionTreesMod.size() > 0) ) {
						createCppADFun( m_vdX);
					}						
				}	
				
				if(( new_x == true ) || (m_iHighestOrderEvaluated < 0) )this->forwardAD(0, m_vdX);
				
				if(( new_x == true ) || (m_iHighestOrderEvaluated < 1) ) {
					m_vdRangeUnitVec[ domainIdx] = 1.;
					m_vdYjacval = this->reverseAD(1, m_vdRangeUnitVec);
					for(i = 0; i < m_iNumberOfNonlinearVariables; i++){
						m_mmdObjGradient[ abs( objIdx) - 1 ][ m_miNonLinearVarsReverseMap[ i]] = m_vdYjacval[ i] + 
							m_mmdDenseObjectiveCoefficients[  abs( objIdx) - 1][ m_miNonLinearVarsReverseMap[ i]];
					}
				}
				m_iHighestOrderEvaluated = iHighestOrderEvaluatedStore;
				m_vdRangeUnitVec[ domainIdx] = 0.;
				// exit the loop
				break;
			}
			domainIdx++;
		}
	}	
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	} 
	return m_mmdObjGradient[abs( objIdx) - 1];
}//calculateObjectiveFunctionGradient	

SparseHessianMatrix *OSInstance::calculateLagrangianHessian( double* x, double *objLambda, double *conLambda,
	bool new_x, int highestOrder){
	try{
		if(highestOrder != 2 ) throw ErrorClass("When calling calculateLagrangianHessian highestOrder should be 2");
		if( new_x == true || (highestOrder > m_iHighestOrderEvaluated)  ) {
			//std::cout  << "CALL getIterateResults() FROM calculateLagrangianHessain" << std::endl;
			getIterateResults(x, objLambda, conLambda,  new_x,  highestOrder);
		}
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	} 
	return m_LagrangianSparseHessian;
}//calculateLagrangianHessian

SparseHessianMatrix *OSInstance::calculateHessian(double* x, int idx, bool new_x){
	try{
		if(idx > instanceData->variables->numberOfVariables ) 
			throw ErrorClass("invalid index passed to calculateHessian");
		double *objLambda = new double[ getObjectiveNumber() ];
		double *conLambda = new double[ getConstraintNumber() ];
		//std::cout << "NUMBER OF OBJECTIVES = " << getObjectiveNumber() << std::endl;
		//std::cout << "NUMBER OF CONSTRAINTS = " << getConstraintNumber() << std::endl;
		int i;
		// initialize all to zero
		for(i = 0; i < getObjectiveNumber(); i++){
			objLambda[ i] = 0.0;
		}
		for(i = 0; i < getConstraintNumber(); i++){
			conLambda[ i] = 0.0;
		}
		// see if we have the index of an objective function or a constraint
		// and more corresponding component 1.0
		if(idx < 0){
			objLambda[ abs(idx) - 1] = 1.0;
		}
		else{
			conLambda[ idx] = 1.0;
		}
		if( new_x == true || (2 > m_iHighestOrderEvaluated)  ) {
			getIterateResults(x, objLambda, conLambda, new_x,  2);
			std::cout  << "CALL getIterateResults() FROM calculateHessian" << std::endl;
		}
		delete[] objLambda;
		delete[] conLambda;
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	} 
	return m_LagrangianSparseHessian;
}//calculateHessian			



bool OSInstance::getSparseJacobianFromColumnMajor( ){
	// we assume column major matrix
	if( m_bColumnMajor == false) return false;
	int iNumRowStarts = getConstraintNumber() + 1;	
	int i,j, iTemp;
	int iNumVariableStarts = getVariableNumber() ;
	int *start = NULL;
	int *index = NULL;
	double *value = NULL;
	if(this->instanceData->linearConstraintCoefficients->numberOfValues > 0){
		start = this->instanceData->linearConstraintCoefficients->start->el;
		index = this->instanceData->linearConstraintCoefficients->rowIdx->el;
		value = this->instanceData->linearConstraintCoefficients->value->el;
	}
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
	// only execute the following code if there are linear constraint coefficients
	if(this->instanceData->linearConstraintCoefficients->numberOfValues > 0){
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
					expTree = m_mapExpressionTreesMod[ index[j]  ];
					nlNodeVariable = new OSnLNodeVariable();
					nlNodeVariable->coef = value[ j];
					nlNodeVariable->idx = i;
					nlNodePlus = new OSnLNodePlus();
					nlNodePlus->m_mChildren[ 0] = m_mapExpressionTreesMod[ index[ j] ]->m_treeRoot;
					nlNodePlus->m_mChildren[ 1] = nlNodeVariable;
					//expTree = new OSExpressionTree();
					expTree->m_treeRoot = nlNodePlus ;
					//expTree->mapVarIdx = m_mapExpressionTreesMod[ index[ j]]->mapVarIdx;
					//m_mapExpressionTreesMod[ index[ j] ]  = expTree;	
					//std::cout << m_mapExpressionTreesMod[ index[ j] ]->m_treeRoot->getNonlinearExpressionInXML() << std::endl;	
					//std::cout << m_mapExpressionTrees[ index[ j] ]->m_treeRoot->getNonlinearExpressionInXML() << std::endl;
				}
				else{ 
					m_miJacStart[ index[j] + 1] ++;
				}				
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
	m_iJacValueSize = 	m_miJacStart[ iNumRowStarts - 1];
	m_miJacIndex = new int[  m_iJacValueSize];
	m_mdJacValue = new double[ m_iJacValueSize ];
	// now get the values of the constant terms if there are any
	if(this->instanceData->linearConstraintCoefficients->numberOfValues > 0){
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
	#ifdef DEBUG
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
	#endif
	return true;
}//getSparseJacobianFromColumnMajor



bool OSInstance::getSparseJacobianFromRowMajor( ){
	// we assume row major matrix
	if( m_bColumnMajor == true) return false;
	int iNumJacRowStarts = getConstraintNumber() + 1;
	std::map<int, int>::iterator posVarIdx;	
	int i,j, k;
	int *start = NULL;
	int *index = NULL;
	double *value = NULL;
	if(this->instanceData->linearConstraintCoefficients->numberOfValues > 0){
		start = this->instanceData->linearConstraintCoefficients->start->el;
		index = this->instanceData->linearConstraintCoefficients->colIdx->el;
		value = this->instanceData->linearConstraintCoefficients->value->el;
	}
	m_miJacStart = new int[ iNumJacRowStarts];
	m_miJacNumConTerms = new int[ getConstraintNumber()];
	OSnLNodePlus *nlNodePlus;
	OSnLNodeVariable *nlNodeVariable;
	//OSExpressionTree *expTree = NULL;
	// now initialize starts and variable index maps 
	for ( i = 0; i < iNumJacRowStarts; i++){			
		m_miJacStart [ i ] = 0;
		// map the variables  in the nonlinear rows
		if( m_mapExpressionTreesMod.find( i) != m_mapExpressionTreesMod.end() ){
			// the following is equivalent to  m_treeRoot->getVariableIndexMap( i);
			m_mapExpressionTreesMod[ i]->getVariableIndiciesMap();
			
		}
	}
	int loopLimit =  getConstraintNumber();
	// only execute the following code if there are linear constraint coefficients
	// determine the number of terms in constraint with constant partial derivative
	if(this->instanceData->linearConstraintCoefficients->numberOfValues > 0){
		// i is indexing rows (constrains) and j is indexing column numbers 
		for (i = 0; i < loopLimit; i++){
			m_miJacNumConTerms[ i] = 0;
			for (j = start[i]; j < start[ i + 1 ]; j++){
				// determine if variable index[j] appears in the Expression Tree for row i
				// if we pass if test below then variable i is in the expresssion tree and we add
				// the linear term to the expession tree
				if( (m_mapExpressionTreesMod.find( i) != m_mapExpressionTreesMod.end() ) &&
					( (*m_mapExpressionTreesMod[ i]->mapVarIdx).find( index[ j]) != (*m_mapExpressionTreesMod[ i]->mapVarIdx).end()) ){
					// variable index[ j] appears in the expression tree for row i
					// add the coefficient corresponding to variable index[j] in row i to the expression tree	
					// define a new OSnLVariable and OSnLnodePlus 
					nlNodeVariable = new OSnLNodeVariable();
					nlNodeVariable->coef = value[ j];
					nlNodeVariable->idx = index[ j];
					nlNodePlus = new OSnLNodePlus();
					nlNodePlus->m_mChildren[ 0] = m_mapExpressionTreesMod[ i ]->m_treeRoot;
					nlNodePlus->m_mChildren[ 1] = nlNodeVariable;
					//expTree = new OSExpressionTree();
					//expTree->m_treeRoot = nlNodePlus ;
					//expTree->mapVarIdx = m_mapExpressionTreesMod[ i]->mapVarIdx;
					//m_mapExpressionTreesMod[ i ]  = expTree;	
					m_mapExpressionTreesMod[ i ]->m_treeRoot = nlNodePlus;
				}
				else{ 
					//the partial derivative of variable j in row i is constant
					m_miJacNumConTerms[ i]++;
				}				
			}
		}
	}
	//
	m_miJacStart[0] = 0;
	for (i = 1; i < iNumJacRowStarts; i++ ){
		if( m_mapExpressionTreesMod.find( i - 1) != m_mapExpressionTreesMod.end() ){
			m_miJacStart[i] = m_miJacStart[i - 1] + (m_miJacNumConTerms[ i - 1] + (*m_mapExpressionTreesMod[ i - 1]->mapVarIdx).size() );
		}
		else{
			m_miJacStart[i] = m_miJacStart[i - 1] + m_miJacNumConTerms[ i - 1];
		}	
	}
	// we know how many constant terms and size of arrays
	// dimension miIndex and mdValue here
	m_iJacValueSize = 	m_miJacStart[ iNumJacRowStarts - 1];
	m_miJacIndex = new int[  m_iJacValueSize];
	m_mdJacValue = new double[ m_iJacValueSize ];
	// now loop again and put in values and indicies
	// first put in the constant terms
	if(this->instanceData->linearConstraintCoefficients->numberOfValues > 0){
		for (i = 0; i < loopLimit; i++){
			k = 0;
			for (j = start[i]; j < start[ i + 1 ]; j++){
				if( (m_mapExpressionTreesMod.find( i) == m_mapExpressionTreesMod.end() ) ||
					( (*m_mapExpressionTreesMod[ i]->mapVarIdx).find( index[ j]) == (*m_mapExpressionTreesMod[ i]->mapVarIdx).end()) ){
						m_miJacIndex[ m_miJacStart[i] + k ] = index[ j];
						m_mdJacValue[ m_miJacStart[i] + k ] = value[ j];
						k++;
					}			
			}
		}
	}
	// put in terms from the modified nonlinear expression tree
	for (i = 0; i < loopLimit; i++ ){
		k = m_miJacStart[i] + m_miJacNumConTerms[ i ];
		// if the row is in the list of expression trees read in idicies and values
		if( m_mapExpressionTreesMod.find( i) != m_mapExpressionTreesMod.end() ){
			for(posVarIdx = (*m_mapExpressionTreesMod[ i]->mapVarIdx).begin(); posVarIdx 
			!= (*m_mapExpressionTreesMod[ i]->mapVarIdx).end(); ++posVarIdx){
				m_miJacIndex[ k] = posVarIdx->first;
				m_mdJacValue[ k] = 0;
				k++;
			}
		}
	}
	#ifdef DEBUG
	std::cout << "HERE ARE ROW STARTS:" << std::endl;
	for (i = 0; i < iNumJacRowStarts; i++ ){
		std::cout <<  m_miJacStart[ i] << "  ";	
	}
	std::cout << std::endl << std::endl;
	std::cout << "HERE ARE VARIABLE INDICIES:" << std::endl;
	for (i = 0; i < m_miJacStart[ iNumJacRowStarts - 1]; i++ ){
		std::cout <<  m_miJacIndex[ i] << "  ";	
	}
	std::cout << std::endl << std::endl;
	std::cout << "HERE ARE VALUES:" << std::endl;
	for (i = 0; i < m_miJacStart[ iNumJacRowStarts - 1]; i++ ){
		std::cout <<  m_mdJacValue[ i] << "  ";	
	}
	std::cout << std::endl << std::endl;

	std::cout << "HERE ARE NUMBER OF CONSTANT TERMS:" << std::endl;
	for (i = 0; i < iNumJacRowStarts - 1; i++ ){
		std::cout <<  m_miJacNumConTerms[ i ] << "  ";	
	}
	std::cout << std::endl << std::endl;
	#endif
	return true;
}//getSparseJacobianFromRowMajor

OSExpressionTree* OSInstance::getLagrangianExpTree( ){
	if( m_bLagrangianExpTreeCreated == true) return m_LagrangianExpTree;
	// we calculate the Lagrangian for all the objectives and constraints
	// with nonlinear terms
	// first initialize everything for nonlinear work
	if(m_bSparseJacobianCalculated == false) getJacobianSparsityPattern( );	
	std::map<int, OSExpressionTree*>::iterator posMapExpTree;
	OSnLNodeTimes* nlNodeTimes = NULL;
	OSnLNodeVariable* nlNodeVariable = NULL;
	OSnLNodeSum* nlNodeSum = NULL;
	int numChildren = 0;
	int rowIdx;
	// create the sum node
	nlNodeSum = new OSnLNodeSum();
	nlNodeSum->inumberOfChildren = m_mapExpressionTreesMod.size();
	nlNodeSum->m_mChildren = new OSnLNode*[ nlNodeSum->inumberOfChildren];
	// create and expression tree for the sum node
	m_LagrangianExpTree = new OSExpressionTree();
	m_LagrangianExpTree->m_treeRoot = nlNodeSum;
	// now create the children of the sum node
	for(posMapExpTree = m_mapExpressionTreesMod.begin(); posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree){
		// this variable is the Lagrange multiplier
		nlNodeVariable = new OSnLNodeVariable();
		nlNodeVariable->coef = 1.;
		// get the correct index --
		// for rowIdx = 0, ..., m - 1 set idx = numVar + rowIdx
		rowIdx = posMapExpTree->first;
		if(rowIdx >= 0){
			nlNodeVariable->idx = instanceData->variables->numberOfVariables + rowIdx;
		}
		else{
			nlNodeVariable->idx = instanceData->variables->numberOfVariables + 
			instanceData->constraints->numberOfConstraints + (abs(rowIdx) - 1);
		}
		// now create a times multiply the new variable times the root of the expression tree
		nlNodeTimes = new OSnLNodeTimes();
		nlNodeTimes->m_mChildren[ 0] = nlNodeVariable;
		nlNodeTimes->m_mChildren[ 1] = m_mapExpressionTreesMod[ posMapExpTree->first ]->m_treeRoot;	
		// the times node is the new child
		nlNodeSum->m_mChildren[ numChildren] = nlNodeTimes;
		numChildren++;
	}	
	// get a variable index map for the expression tree
	m_LagrangianExpTree->getVariableIndiciesMap();
	// print out the XML for this puppy
	//std::cout << "Here comes the Lagrangian Tree" << std::endl;
	//std::cout << m_LagrangianExpTree->m_treeRoot->getNonlinearExpressionInXML() << std::endl;
	//
	m_bLagrangianExpTreeCreated = true;
	return m_LagrangianExpTree;
}//getLagrangianExpTree

std::map<int, int> OSInstance::getAllNonlinearVariablesIndexMap( ){
	if(m_bAllNonlinearVariablesIndex == true) return m_mapAllNonlinearVariablesIndex;
	//loop over the map of expression tree and get a unique listing of all variables
	// put these in the map m_mapAllNonlinearVariablesIndex
	std::map<int, OSExpressionTree*>::iterator posMapExpTree;
	std::map<int, int>::iterator posVarIdx;
	OSExpressionTree *expTree;
	for(posMapExpTree = m_mapExpressionTreesMod.begin(); posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree){
		// get the index map for the expression tree
		expTree = posMapExpTree->second;
		if(expTree->m_bIndexMapGenerated == false)expTree->getVariableIndiciesMap();
		for(posVarIdx = (*expTree->mapVarIdx).begin(); posVarIdx != (*expTree->mapVarIdx).end(); ++posVarIdx){
			if( m_mapAllNonlinearVariablesIndex.find( posVarIdx->first) == m_mapAllNonlinearVariablesIndex.end() ){
			// add the variable to the Lagragian map
			m_mapAllNonlinearVariablesIndex[ posVarIdx->first] = 1;
			}
		}
	}
	m_miNonLinearVarsReverseMap = new int[m_mapAllNonlinearVariablesIndex.size()];
	// now order appropriately
	int kount = 0;
	//std::cout << "HERE IS THE LAGRANGIANN VARIABLE MAPPING" << std::endl;
	for(posVarIdx = m_mapAllNonlinearVariablesIndex.begin(); posVarIdx !=m_mapAllNonlinearVariablesIndex.end(); ++posVarIdx){
		posVarIdx->second = kount;
		m_miNonLinearVarsReverseMap[ kount] = posVarIdx->first;
		kount++;
		#ifdef DEBUG
		std::cout <<  "POSITION FIRST =  "  << posVarIdx->first ;
		std::cout <<  "   POSITION SECOND = "  << posVarIdx->second << std::endl;
		#endif
	}
	m_iNumberOfNonlinearVariables = kount;
	//std::cout <<  "NUMBER OF NONLINEAR VARIABLES =  "  << kount ;
	m_bAllNonlinearVariablesIndex = true;
	return m_mapAllNonlinearVariablesIndex;
}//getAllNonlinearVariablesIndexMap 	

SparseHessianMatrix* OSInstance::getLagrangianHessianSparsityPattern( ){
	// fill in the nonzeros in the sparse Hessian
	if( m_bLagrangianSparseHessianCreated == true) return m_LagrangianSparseHessian;
	if( m_iNumberOfNonlinearVariables == 0) return NULL;
	if( m_binitForAlgDiff == false ) initForAlgDiff();
	unsigned int i = 0;
	int numNonz = 0;
	// Create the CppAD function if necessary
	//
	std::vector<double> vx;
	std::map<int, int>::iterator posMap1, posMap2;	
	if( (m_bCppADFunIsCreated == false || m_bCppADMustReTape == true )  && (m_mapExpressionTreesMod.size() > 0) ) {
		for(posMap1 = m_mapAllNonlinearVariablesIndex.begin(); posMap1 != m_mapAllNonlinearVariablesIndex.end(); ++posMap1){
			vx.push_back( 1.0) ;
		}
		createCppADFun( vx);
	}
	//
	// Use CppAD to do a forward sparsity calculation
	std::vector<bool> r(m_iNumberOfNonlinearVariables * m_iNumberOfNonlinearVariables);
	unsigned int j;
	for(i = 0; i < m_iNumberOfNonlinearVariables; i++) { 
		for(j = 0; j < m_iNumberOfNonlinearVariables; j++)
			r[ i * m_iNumberOfNonlinearVariables + j ] = false;
			r[ i * m_iNumberOfNonlinearVariables + i] = true;
	}
	// compute sparsity pattern for J(x) = F^{(1)} (x)
	(*Fad).ForSparseJac(m_iNumberOfNonlinearVariables, r);
	//
	//now the second derivative
	unsigned int m = m_mapExpressionTreesMod.size();
	std::vector<bool> e( m);
	//Vector s(m);
	for(i = 0; i < m; i++) e[i] = true;
	std::cout << "Computing Sparse Hessian" << std::endl;
	//m_vbLagHessNonz holds the sparsity pattern Lagrangian of the Hessian
	m_vbLagHessNonz = (*Fad).RevSparseHes(m_iNumberOfNonlinearVariables, e);
	for(i = 0; i < m_iNumberOfNonlinearVariables; i++){
		//std::cout << "Row " << i << "  of Hessian " << std::endl;
		for(j = i; j < m_iNumberOfNonlinearVariables; j++){
			if(m_vbLagHessNonz[ i*m_iNumberOfNonlinearVariables + j]  == true) numNonz++;
			//std::cout << m_vbLagHessNonz[ i*m_iNumberOfNonlinearVariables + j] <<  "  " ;
		}
		//std::cout << std::endl;
	}
	//std::cout << "Lagrangian Hessian Nonzeros = " << numNonz << std::endl;
	i = 0;
	// now that we have the dimension create SparseHessianMatrix (upper triangular)
	m_LagrangianSparseHessian = new SparseHessianMatrix();
	m_LagrangianSparseHessian->bDeleteArrays = true;
	m_LagrangianSparseHessian->hessDimension = numNonz;
	m_LagrangianSparseHessian->hessRowIdx = new int[m_LagrangianSparseHessian->hessDimension];
	m_LagrangianSparseHessian->hessColIdx = new int[m_LagrangianSparseHessian->hessDimension];
	m_LagrangianSparseHessian->hessValues = new double[m_LagrangianSparseHessian->hessDimension];
	//std::cout << "HESSIAN DIMENSION = " << m_LagrangianSparseHessian->hessDimension << std::endl;
	numNonz = 0;
	for(posMap1 = m_mapAllNonlinearVariablesIndex.begin(); posMap1 != m_mapAllNonlinearVariablesIndex.end(); ++posMap1){
		//std::cout << "posMap1->first  " << posMap1->first << std::endl;
		j = i;
		for(posMap2 = posMap1; posMap2 != m_mapAllNonlinearVariablesIndex.end(); ++posMap2){
			//std::cout << "posMap2->first  " << posMap2->first << std::endl;
			if(m_vbLagHessNonz[ i*m_iNumberOfNonlinearVariables + j] == true){
				*(m_LagrangianSparseHessian->hessRowIdx + numNonz) = posMap1->first;
				*(m_LagrangianSparseHessian->hessColIdx + numNonz) = posMap2->first;
				numNonz++;
			}
			//std::cout << m_vbLagHessNonz[ i*m_iNumberOfNonlinearVariables + j] <<  "  " << std::endl;
			j++;
		}
		i++;
	}
	#ifdef DEBUG
	std::cout << "HESSIAN SPARSITY PATTERN" << std::endl;
	int kj;
	for(kj = 0; kj < m_LagrangianSparseHessian->hessDimension; kj++){
		std::cout <<  "Row Index = " << *(m_LagrangianSparseHessian->hessRowIdx + kj) << std::endl;
		std::cout <<  "Column Index = " << *(m_LagrangianSparseHessian->hessColIdx + kj) << std::endl;
	}
	#endif
	//
	m_bLagrangianSparseHessianCreated = true;
	return m_LagrangianSparseHessian;
}//getLagrangianHessianSparsityPattern


void OSInstance::duplicateExpressionTreesMap(){
	//std::cout << "I AM IN DUPLICATE EXPRSSION TREES MAP" << std::endl;
	// we do this so that we can keep the integrity of the original formulation
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


bool OSInstance::createCppADFun(std::vector<double> vdX){
	if(m_bCppADFunIsCreated == true) return true;
	//if( m_bNonLinearStructuresInitialized == false) initializeNonLinearStructures( );
	if(m_binitForAlgDiff == false) initForAlgDiff();
	
	//if( m_bAllNonlinearVariablesIndex == false) getAllNonlinearVariablesIndexMap( );
	std::map<int, OSExpressionTree*>::iterator posMapExpTree;
	unsigned int i;
	size_t n = vdX.size();
	// declare a CppAD vector and fill it in
	CppADvector< AD<double> > vdaX( n );
	for(i = 0; i < n; i++){
		vdaX[ i] = vdX[ i];
		//std::cout << "vdX =  " << vdX[ i] << std::endl;
	}
	// declare the independent variables and start recording
	CppAD::Independent( vdaX);
	/**
	 * For expression tree, record the operations for CppAD and put into
	 *  the range vector m_vFG and it is a vector of CppAD 
	 * objective and constraint functions.
	 */
	CppAD::vector< AD<double> > m_vFG;	
	int kount = 0;
	for(posMapExpTree = m_mapExpressionTreesMod.begin(); posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree){	
		m_vFG.push_back( (posMapExpTree->second)->m_treeRoot->constructCppADTape(&m_mapAllNonlinearVariablesIndex, &vdaX) );
		//std::cout << "PUSHING BACK EXPRESSION NUMBER " << posMapExpTree->first << std::endl;
		if( m_mapCppADFunRangeIndex.find( posMapExpTree->first) == m_mapCppADFunRangeIndex.end() ){
			// count which nonlinear obj/constraint this is
			m_mapCppADFunRangeIndex[ posMapExpTree->first] = kount;
			kount++;
		}
	}	
	//create the function and stop recording
	std::cout << "create the function and stop recording"  << std::endl;
	Fad = new CppAD::ADFun<double>(vdaX, m_vFG);
	std::cout << "range space dimension =  " << m_vFG.size() << std::endl;
	// no forward sweeps done yet
	m_iHighestTaylorCoeffOrder = -1;
	m_bCppADFunIsCreated = true;
	return true;
}//end createCppADFun


std::vector<double> OSInstance::forwardAD(int p, std::vector<double> vdX){
	try{
		// make sure a CppADFun has been created
		if(m_bCppADFunIsCreated == false) createCppADFun( vdX);
		if(p > (m_iHighestTaylorCoeffOrder + 1) ) throw 
			ErrorClass( "trying to calculate a p order forward when p-1 Taylor coefficient not available");
		// adjust the order of the Taylor coefficient
		m_iHighestTaylorCoeffOrder = p;	
		m_iHighestOrderEvaluated = p;
		//for(int i  = 0; i < vdX.size(); i++){
			//std::cout << "ForwardAD Primal Variables " << i   << " " << vdX[ i] << std::endl;
		//}
		return (*Fad).Forward(p, vdX);
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	}  
}//end forwardAD


std::vector<double> OSInstance::reverseAD(int p, std::vector<double> vdlambda){
	try{
		if(p == 0) throw 
			ErrorClass( "reverseAD must have p >= 1");
		if(p > (m_iHighestTaylorCoeffOrder + 1) ) throw 
			ErrorClass( "trying to calculate a p order reverse when p-1 Taylor coefficient not available");
		//for(int i  = 0; i < vdlambda.size(); i++){
		//	std::cout << "ReverseAD Multiplier " << i   << " " << vdlambda[ i] << std::endl;
		//}
		m_iHighestOrderEvaluated = p;
		return (*Fad).Reverse(p, vdlambda);
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	}  
}//end forwardAD

bool OSInstance::getIterateResults( double *x, double *objLambda, double* conMultipliers, 
		bool new_x, int highestOrder){
	try{ 
		if( m_binitForAlgDiff == false) initForAlgDiff();
		std::map<int, int>::iterator posVarIndexMap;
		
		if(new_x == true){
			if( m_vdX.size() > 0) m_vdX.clear();
			for(posVarIndexMap = m_mapAllNonlinearVariablesIndex.begin(); posVarIndexMap != m_mapAllNonlinearVariablesIndex.end(); ++posVarIndexMap){
				m_vdX.push_back( x[ posVarIndexMap->first]) ;
			}
			if( (m_bCppADFunIsCreated == false || m_bCppADMustReTape == true )  && (m_mapExpressionTreesMod.size() > 0) ) {
				createCppADFun( m_vdX);
			}	
		}
		else{ // make sure vector not empty -- this could happen if we have linear obj and nonlinear constraints
			if( m_vdX.size() == 0) {
				for(posVarIndexMap = m_mapAllNonlinearVariablesIndex.begin(); posVarIndexMap != m_mapAllNonlinearVariablesIndex.end(); ++posVarIndexMap){
					m_vdX.push_back( x[ posVarIndexMap->first]) ;
				}
				if( (m_bCppADFunIsCreated == false || m_bCppADMustReTape == true )  && (m_mapExpressionTreesMod.size() > 0) ) {
					createCppADFun( m_vdX);
				}	
			}
		}
		switch( highestOrder){		
			case 0:	
				if(new_x == true || m_iHighestOrderEvaluated < 0){	
					if(bUseExpTreeForFunEval == true){
						calculateAllConstraintFunctionValues( x, new_x);
						calculateAllObjectiveFunctionValues( x, new_x);
					}
					else{
						getZeroOrderResults(x, objLambda, conMultipliers);
					}

				}
				break;	
			case 1:
				if(new_x == true || m_iHighestOrderEvaluated < 0)	
					getZeroOrderResults(x, objLambda, conMultipliers);
				if(new_x == true || m_iHighestOrderEvaluated < 1)	
					getFirstOrderResults(x, objLambda, conMultipliers);
				break;
			case 2:	
				if(new_x == true || m_iHighestOrderEvaluated < 0)	
					getZeroOrderResults(x, objLambda, conMultipliers);
				if(new_x == true || m_iHighestOrderEvaluated < 2)	
					getSecondOrderResults(x, objLambda, conMultipliers);
				break;
			default:
				throw ErrorClass("Derivative should be order 0, 1, or 2");	
		}//end switch
		return true;
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	}  
}//end getIterateResults


bool OSInstance::getZeroOrderResults(double *x, double *objLambda, double *conMultipliers){
	try{ 
		// initialize everything
		int i, j, rowNum, objNum;
		if( m_mapExpressionTreesMod.size() > 0){
			m_vdYval = this->forwardAD(0, m_vdX);	
		}
		// now get all function and constraint values using forward result
		for(rowNum = 0; rowNum < m_iConstraintNumber; rowNum++){
			m_mdConstraintFunctionValues[ rowNum] = 0.0;
			if( m_mapExpressionTreesMod.find( rowNum) != m_mapExpressionTreesMod.end() ){
				m_mdConstraintFunctionValues[ rowNum] = m_vdYval[  m_mapCppADFunRangeIndex[ rowNum]];
			}
			// now the linear part
			// be careful, loop over only the constant terms in sparseJacMatrix
			i = m_sparseJacMatrix->starts[ rowNum];
			j = m_sparseJacMatrix->starts[ rowNum + 1 ];
			while ( (i - m_sparseJacMatrix->starts[ rowNum])  < m_sparseJacMatrix->conVals[ rowNum] ){
				m_mdConstraintFunctionValues[ rowNum] += m_sparseJacMatrix->values[ i]*x[ m_sparseJacMatrix->indexes[ i] ];
				i++;
			}	
			// add in the constraint function constant
			m_mdConstraintFunctionValues[ rowNum] += m_mdConstraintConstants[ rowNum ];
			#ifdef DEBUG
			std::cout << "Constraint " <<  rowNum << " function value =  " << m_mdConstraintFunctionValues[ rowNum ] << std::endl;
			#endif
		}
		// now get the objective function values from the forward result
		for(objNum = 0; objNum < m_iObjectiveNumber; objNum++){
			m_mdObjectiveFunctionValues[ objNum] = 0.0;
			if( m_mapExpressionTreesMod.find( -objNum -1) != m_mapExpressionTreesMod.end() ){
				m_mdObjectiveFunctionValues[ objNum] = m_vdYval[ objNum];
			}
			for(i = 0; i < m_iVariableNumber; i++){
				m_mdObjectiveFunctionValues[ objNum] += m_mmdDenseObjectiveCoefficients[ objNum][i]*x[ i];
			}
			#ifdef DEBUG
			std::cout << "Objective " << objNum << " function value =  " << m_mdObjectiveFunctionValues[ objNum] << std::endl;
			#endif
		}
	return true;
	}//end try
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	}  
}//end getZeroOrderResults



bool OSInstance::getFirstOrderResults(double *x, double *objLambda, double *conMultipliers){
	try{
		// initialize everything
		unsigned int i, j;
		int rowNum,  jacIndex;
		unsigned int jstart, jend;
		int idx;
		OSExpressionTree *expTree = NULL;
		int domainIdx = 0;	
		std::map<int, OSExpressionTree*>::iterator posMapExpTree;
		std::map<int, int>::iterator posVarIdx;
		
		/** if the number of columns exceeds the number of rows we will get the 
		 * Jacobian by row, however, if the number of rows exceeds the number of 
		 * columns we get the Jacobian by column
		 */		
		
		if(m_iNumberOfNonlinearVariables >= m_mapExpressionTreesMod.size() ){
			// calculate the gradient by doing a reverse sweep over each row
			// loop over the constraints that have a nonlinear term and get their gradients
			for(posMapExpTree = m_mapExpressionTreesMod.begin(); posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree){
				idx = posMapExpTree->first;
				// we are considering only constraints, not objective function
				if(idx >= 0){
					m_vdRangeUnitVec[ domainIdx] = 1.;
					m_mapExpressionTreesMod[ idx]->getVariableIndiciesMap(); 
					m_vdYjacval = this->reverseAD(1, m_vdRangeUnitVec);
					// check size
					jstart = m_miJacStart[ idx] + m_miJacNumConTerms[ idx];
					jend = m_miJacStart[ idx + 1 ];
					if( (*m_mapExpressionTreesMod[ idx]->mapVarIdx).size() != (jend - jstart)) throw 
					ErrorClass("number of partials not consistent");
					j = 0;
					jacIndex = 0;
					for(posVarIdx = m_mapAllNonlinearVariablesIndex.begin(); posVarIdx 
						!= m_mapAllNonlinearVariablesIndex.end(); ++posVarIdx){
						//std::cout << "Constraint Function Jacobian Values" << "For Constraint  " << idx  << std::endl;
						//std::cout << "Jac Val for index " << posVarIdx->first  << " = " << m_vdYjacval[ jacIndex] << std::endl;
						//if(m_miJacIndex[ jstart] != posVarIdx->first) throw ErrorClass("error calculating Jacobian matrix");
						// we are working with variable posVarIdx->first in the original variable space
						// we need to see which variable this is in the individual constraint map
						if( (*m_mapExpressionTreesMod[ idx]->mapVarIdx).find( posVarIdx->first) != (*m_mapExpressionTreesMod[ idx]->mapVarIdx).end()){
							m_mdJacValue[ jstart] = m_vdYjacval[ jacIndex];
							jstart++;
							j++;
						}
						jacIndex++;
					}
					
					m_vdRangeUnitVec[ domainIdx] = 0.;
					domainIdx++;
				}
				else{    // we have an objective function
					

					domainIdx++;
				}
			}
		}
		else{  
			// calculate the gradients using a forward sweep over all the variables. 		
			for(i = 0; i < m_iNumberOfNonlinearVariables; i++){
				m_vdDomainUnitVec[i] = 1.;     
				rowNum = 0;
				if( m_mapExpressionTreesMod.size() > 0){          
					m_vdYjacval = this->forwardAD(1, m_vdDomainUnitVec);
				} 
				// fill in Jacobian here, we have column i 
				// start Jacobian calculation
				for(posMapExpTree = m_mapExpressionTreesMod.begin(); posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree){
					idx = posMapExpTree->first;
					// we are considering only constraints, not objective function
					if(idx >= 0){
						//figure out original variable this corresponds to
						//then use (*m_mapExpressionTreesMod[ idx]->mapVarIdx) to figure out which variable it is within row idx
						//m_mapAllNonlinearVariablesIndex
						//std::cout << "This is the following variable in the expression tree  " <<  (*m_mapExpressionTreesMod[ idx]->mapVarIdx)[ m_miNonLinearVarsReverseMap[ i]]<< std::endl; 			
						expTree = m_mapExpressionTreesMod[ idx];		
						if( (*expTree->mapVarIdx).find( m_miNonLinearVarsReverseMap[ i]) != (*expTree->mapVarIdx).end()  ){		
							jacIndex = (*m_mapExpressionTreesMod[ idx]->mapVarIdx)[ m_miNonLinearVarsReverseMap[ i]];
							jstart = m_miJacStart[ idx] + m_miJacNumConTerms[ idx];
							// kipp change 1 to number of objective functions
							m_mdJacValue[ jstart + jacIndex] = m_vdYjacval[m_iObjectiveNumberNonlinear + rowNum];
						}
						rowNum++;
					}//end Jacobian calculation
			}			
			//
			m_vdDomainUnitVec[i] = 0.;
			}
		}
		#ifdef DEBUG
		int k;
		std::cout  << "JACOBIAN DATA " << std::endl;
		for(idx = 0; idx < m_iConstraintNumber; idx++){
			for(k = *(m_sparseJacMatrix->starts + idx); k < *(m_sparseJacMatrix->starts + idx + 1); k++){
				std::cout << "row idx = " << idx <<  "  col idx = "<< *(m_sparseJacMatrix->indexes + k)
				<< " value = " << *(m_sparseJacMatrix->values + k) << std::endl;
			}
		}
		#endif
		return true;
	}//end try
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	} 
}// end getFirstOrderResults
			

bool OSInstance::getSecondOrderResults(double *x, double *objLambda, double *conMultipliers){
	try{
		// initialize everything
		unsigned int i, j;
		int rowNum,  jacIndex;
		int jstart,  idx;
		OSExpressionTree *expTree = NULL;
		int hessValuesIdx = 0;	
		std::map<int, OSExpressionTree*>::iterator posMapExpTree;
		std::map<int, int>::iterator posVarIndexMap;
		if( conMultipliers == NULL) throw ErrorClass("cannot have a null vector of lagrange multipliers when calculating Hessian of Lagrangian");
		if( m_vdLambda.size() > 0) m_vdLambda.clear();
		for(posMapExpTree = m_mapExpressionTreesMod.begin(); posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree){	
			if( posMapExpTree->first >= 0){
				m_vdLambda.push_back( conMultipliers[ posMapExpTree->first]);
			}
			else{
				// kipp correct when there is more than one obj
				m_vdLambda.push_back( objLambda[ abs(posMapExpTree->first) - 1] );
			}
		}
		for(i = 0; i < m_iNumberOfNonlinearVariables; i++){
			m_vdDomainUnitVec[i] = 1.;     
			rowNum = 0;
			if( m_mapExpressionTreesMod.size() > 0){          
				m_vdYjacval = this->forwardAD(1, m_vdDomainUnitVec);
			} 
			// fill in Jacobian here, we have column i 
			// start Jacobian calculation
			for(posMapExpTree = m_mapExpressionTreesMod.begin(); posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree){
				idx = posMapExpTree->first;
				// we are considering only constraints, not objective function
				if(idx >= 0){
					//figure out original variable this corresponds to
					//then use (*m_mapExpressionTreesMod[ idx]->mapVarIdx) to figure out which variable it is within row idx
					//m_mapAllNonlinearVariablesIndex
					//std::cout << "This is the following variable in the expression tree  " <<  (*m_mapExpressionTreesMod[ idx]->mapVarIdx)[ m_miNonLinearVarsReverseMap[ i]]<< std::endl; 			
					expTree = m_mapExpressionTreesMod[ idx];		
					if( (*expTree->mapVarIdx).find( m_miNonLinearVarsReverseMap[ i]) != (*expTree->mapVarIdx).end()  ){		
						jacIndex = (*m_mapExpressionTreesMod[ idx]->mapVarIdx)[ m_miNonLinearVarsReverseMap[ i]];
						jstart = m_miJacStart[ idx] + m_miJacNumConTerms[ idx];
						m_mdJacValue[ jstart + jacIndex] = m_vdYjacval[m_iObjectiveNumberNonlinear + rowNum];
					}
					rowNum++;
				}//end Jacobian calculation
				else{
					// see if we have the objective function of interest
					//kipp fix if more than one obj
						m_mmdObjGradient[  (abs( idx) - 1)][ m_miNonLinearVarsReverseMap[ i]] = m_vdYjacval[ (abs( idx) - 1)] + 
						m_mmdDenseObjectiveCoefficients[  (abs( idx) - 1)][ m_miNonLinearVarsReverseMap[ i]];					
			}//end Obj gradient calculation 
		}			
		// now calculate the Hessian
		if( m_mapExpressionTreesMod.size() > 0){   
			m_vdw = reverseAD(2, m_vdLambda);   // derivtative of partial
		}
		for(j = i; j < m_iNumberOfNonlinearVariables; j++){
			if( m_vbLagHessNonz[i*m_iNumberOfNonlinearVariables + j] == true){
				m_LagrangianSparseHessian->hessValues[ hessValuesIdx] =  m_vdw[  j*2 + 1];
				#ifdef DEBUG
				std::cout << "reverse 2 " << m_LagrangianSparseHessian->hessValues[ hessValuesIdx] << std::endl;
				#endif
				hessValuesIdx++;
			}
		}
		//
		//
		m_vdDomainUnitVec[i] = 0.;
	}
	#ifdef DEBUG
	int k;
	std::cout  << "JACOBIAN DATA " << std::endl;
	for(idx = 0; idx < m_iConstraintNumber; idx++){
		for(k = *(m_sparseJacMatrix->starts + idx); k < *(m_sparseJacMatrix->starts + idx + 1); k++){
			std::cout << "row idx = " << idx <<  "  col idx = "<< *(m_sparseJacMatrix->indexes + k)
			<< " value = " << *(m_sparseJacMatrix->values + k) << std::endl;
		}
	}
	#endif
	return true;
	}//end try
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	} 
}// end getSecondOrderResults

bool OSInstance::initForAlgDiff(){
	if( m_binitForAlgDiff == true ) return true;
	initializeNonLinearStructures( );
	initObjGradients();
	getAllNonlinearVariablesIndexMap( );
	if(m_bSparseJacobianCalculated  == false) getJacobianSparsityPattern();
	//see if we need to retape 
	//loop over expression tree and see if one requires it
	std::map<int, OSExpressionTree*>::iterator posMapExpTree;
	for(posMapExpTree = m_mapExpressionTreesMod.begin(); posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree){
		if(posMapExpTree->second->bCppADMustReTape == true) m_bCppADMustReTape = true;
	}				

	#ifdef DEBUG
	std::cout << "RETAPE ==  " << m_bCppADMustReTape << std::endl;
	#endif
	unsigned int i;
	for(i = 0; i < m_iNumberOfNonlinearVariables; i++){
		m_vdDomainUnitVec.push_back( 0.0 );
	}
	for(i = 0; i < m_mapExpressionTreesMod.size(); i++){
		m_vdRangeUnitVec.push_back( 0.0 );
	}
	m_binitForAlgDiff = true;
	return true;
}//end initForAlgDiff

bool OSInstance::initObjGradients(){
	int i, j;
	int m, n;
	m = getObjectiveNumber();
	n = getVariableNumber();
	getDenseObjectiveCoefficients();
	m_mmdObjGradient = new double*[m];
	for(i = 0; i < m; i++){
		m_mmdObjGradient[i] = new double[n];
		for(j = 0; j < n; j++){
			m_mmdObjGradient[i][j] =  m_mmdDenseObjectiveCoefficients[ i][j];
			#ifdef DEBUG
			std::cout << "m_mmdObjGradient[i][j] = " << m_mmdObjGradient[i][j]  << std::endl;
			#endif
		}
	}
	return true;
}//end initObjGradients
/**
 * end revised AD test code
 */


/**
 * set methods for timeDomain object
 */
bool OSInstance::setTimeDomain(std::string format)
{   if ((format != "stages") && (format != "interval") && (format != "none")) 
		return false;
	if (instanceData->timeDomain == NULL)
	{	instanceData->timeDomain = new TimeDomain();
	}
	if (format == "stages")
	{	if (instanceData->timeDomain->interval != NULL)
		{	delete instanceData->timeDomain->interval;
			instanceData->timeDomain->interval = NULL;
		}
		if (instanceData->timeDomain->stages == NULL)
			instanceData->timeDomain->stages = new TimeDomainStages();
		m_sTimeDomainFormat = format;
	}
	if (format == "interval")
	{	if (instanceData->timeDomain->stages != NULL)
		{	delete instanceData->timeDomain->stages;
			instanceData->timeDomain->stages = NULL;
		}
		if (instanceData->timeDomain->interval == NULL)
			instanceData->timeDomain->interval = new TimeDomainInterval();
		m_sTimeDomainFormat = format;
	}
	if (format == "none")
	{	if (instanceData->timeDomain->stages != NULL)
		{	delete instanceData->timeDomain->stages;
			instanceData->timeDomain->stages = NULL;
		}
		if (instanceData->timeDomain->interval != NULL)
		{	delete instanceData->timeDomain->interval;
			instanceData->timeDomain->interval = NULL;
		}
		m_sTimeDomainFormat = "";
	}
	return true;
} //end setTimeDomain

/**
 * set time domain stages
 */
bool OSInstance::setTimeDomainStages(int number, std::string *names)
{   if (instanceData->timeDomain == NULL)
		instanceData->timeDomain = new TimeDomain();
	if (instanceData->timeDomain->interval != NULL)
		return false;
	if (instanceData->timeDomain->stages == NULL)
	{	instanceData->timeDomain->stages = new TimeDomainStages;
	}
	else
	{	if (instanceData->timeDomain->stages->numberOfStages != number)
		{	for (int i = 0; i < instanceData->timeDomain->stages->numberOfStages; i++)
			{	if (instanceData->timeDomain->stages->stage[i]->variables != NULL)
				{	delete instanceData->timeDomain->stages->stage[i]->variables;
					instanceData->timeDomain->stages->stage[i]->variables = NULL;
				}
				if (instanceData->timeDomain->stages->stage[i]->constraints != NULL)
				{	delete instanceData->timeDomain->stages->stage[i]->constraints;
					instanceData->timeDomain->stages->stage[i]->constraints = NULL;
				}
				if (instanceData->timeDomain->stages->stage[i]->objectives != NULL)
				{	delete instanceData->timeDomain->stages->stage[i]->objectives;
					instanceData->timeDomain->stages->stage[i]->objectives = NULL;
				}
				delete instanceData->timeDomain->stages->stage[i];
				instanceData->timeDomain->stages->stage[i] = NULL;
			}
			delete []instanceData->timeDomain->stages->stage;
			instanceData->timeDomain->stages->stage = NULL;
		}
	}
	if (number != 0 )
	{	if (instanceData->timeDomain->stages->stage == NULL)
			instanceData->timeDomain->stages->stage = new TimeDomainStage*[number];
		for (int i = 0; i < number; i++)
		{	instanceData->timeDomain->stages->stage[i] = new TimeDomainStage();
		}
		instanceData->timeDomain->stages->numberOfStages = number;
	}
	for (int i = 0; i < number; i++)
	//initial or empty vars, cons, objectives and set default to all objectives
	{	if (instanceData->timeDomain->stages->stage[i]->variables != NULL)
		{	delete instanceData->timeDomain->stages->stage[i]->variables;
			instanceData->timeDomain->stages->stage[i]->variables = NULL;
		}
		instanceData->timeDomain->stages->stage[i]->variables = new TimeDomainStageVariables();
		if (instanceData->timeDomain->stages->stage[i]->constraints != NULL)
		{	delete instanceData->timeDomain->stages->stage[i]->constraints;
			instanceData->timeDomain->stages->stage[i]->constraints = NULL;
		}
		instanceData->timeDomain->stages->stage[i]->constraints = new TimeDomainStageConstraints();
		if (instanceData->timeDomain->stages->stage[i]->objectives != NULL)
		{	delete instanceData->timeDomain->stages->stage[i]->objectives;
			instanceData->timeDomain->stages->stage[i]->objectives = NULL;
		}
		instanceData->timeDomain->stages->stage[i]->objectives = new TimeDomainStageObjectives();
		instanceData->timeDomain->stages->stage[i]->objectives->numberOfObjectives = instanceData->objectives->numberOfObjectives;
		instanceData->timeDomain->stages->stage[i]->objectives->obj = new TimeDomainStageObj*[instanceData->objectives->numberOfObjectives];
		for (int j = 0; j < instanceData->objectives->numberOfObjectives; j++)
		{	instanceData->timeDomain->stages->stage[i]->objectives->obj[j] = new TimeDomainStageObj();
			instanceData->timeDomain->stages->stage[i]->objectives->obj[j]->idx = -(j+1);
		}
		if (names != NULL)
			instanceData->timeDomain->stages->stage[i]->name = names[i];
	}
	return true;
} //end setTimeDomainStages

/**
 * set time domain stage variables in temporal order
 */
bool OSInstance::setTimeDomainStageVariablesOrdered(int numberOfStages, int *numberOfVariables, int *startIdx)
{  	if (instanceData->timeDomain == NULL)
		instanceData->timeDomain = new TimeDomain();
	if (instanceData->timeDomain->interval != NULL)
		return false;
	if (instanceData->timeDomain->stages == NULL)
		instanceData->timeDomain->stages = new TimeDomainStages();	
	if (instanceData->timeDomain->stages != NULL)
	{	if ((instanceData->timeDomain->stages->numberOfStages != numberOfStages) &&
			(instanceData->timeDomain->stages->numberOfStages != 0))
			 return false;
	}
	if (instanceData->timeDomain->stages->numberOfStages == 0)
	{	instanceData->timeDomain->stages->numberOfStages = numberOfStages;
		if (instanceData->timeDomain->stages->stage == NULL)
			instanceData->timeDomain->stages->stage = new TimeDomainStage*[numberOfStages];
		for (int i = 0; i < numberOfStages; i++)
			instanceData->timeDomain->stages->stage[i] = new TimeDomainStage();
	}
	int checksum = 0;
	for (int i = 0; i < numberOfStages; i++)
	//initial or empty vars, cons, objectives and set default to all objectives
	{	if (instanceData->timeDomain->stages->stage[i]->variables != NULL)
		{	delete instanceData->timeDomain->stages->stage[i]->variables;
			instanceData->timeDomain->stages->stage[i]->variables = NULL;
		}
		instanceData->timeDomain->stages->stage[i]->variables = new TimeDomainStageVariables();
		instanceData->timeDomain->stages->stage[i]->variables->startIdx = startIdx[i];
		instanceData->timeDomain->stages->stage[i]->variables->numberOfVariables = numberOfVariables[i];
		checksum += numberOfVariables[i];
	}
	return (checksum == instanceData->variables->numberOfVariables);
} //end setTimeDomainVariablesOrdered

/**
 * set time domain stage variables in arbitrary order
 */
bool OSInstance::setTimeDomainStageVariablesUnordered(int numberOfStages, int *numberOfVariables, int **varIndex)
{   if (instanceData->timeDomain == NULL)
		instanceData->timeDomain = new TimeDomain();
	if (instanceData->timeDomain->interval != NULL)
		return false;
	if (instanceData->timeDomain->stages == NULL)
		instanceData->timeDomain->stages = new TimeDomainStages();	
	if (instanceData->timeDomain->stages != NULL)
	{	if ((instanceData->timeDomain->stages->numberOfStages != numberOfStages) &&
			(instanceData->timeDomain->stages->numberOfStages != 0))
			 return false;
	}
	if (instanceData->timeDomain->stages->numberOfStages == 0 )
	{	instanceData->timeDomain->stages->numberOfStages = numberOfStages;
		if (instanceData->timeDomain->stages->stage == NULL)
			instanceData->timeDomain->stages->stage = new TimeDomainStage*[numberOfStages];
		for (int i = 0; i < numberOfStages; i++)
			instanceData->timeDomain->stages->stage[i] = new TimeDomainStage();
	}
	int checksum = 0;
	for (int i = 0; i < numberOfStages; i++)
	//initial or empty vars, cons, objectives and set default to all objectives
	{	if (instanceData->timeDomain->stages->stage[i]->variables != NULL)
		{	delete instanceData->timeDomain->stages->stage[i]->variables;
			instanceData->timeDomain->stages->stage[i]->variables = NULL;
		}
		instanceData->timeDomain->stages->stage[i]->variables = new TimeDomainStageVariables();
		instanceData->timeDomain->stages->stage[i]->variables->numberOfVariables = numberOfVariables[i];
		instanceData->timeDomain->stages->stage[i]->variables->var = new TimeDomainStageVar*[numberOfVariables[i]];
		for (int j = 0; j < numberOfVariables[i]; j++)
		{	instanceData->timeDomain->stages->stage[i]->variables->var[j] = new TimeDomainStageVar();
			instanceData->timeDomain->stages->stage[i]->variables->var[j]->idx = varIndex[i][j];
		}
		checksum += numberOfVariables[i];
	}
	if (checksum != instanceData->variables->numberOfVariables) return false;
	int *checkvar = new int[instanceData->variables->numberOfVariables];
	for (int j = 0; j < instanceData->variables->numberOfVariables; j++)
		checkvar[j] = -1;
	int k;
	for (int i = 0; i < numberOfStages; i++)
		for (int j = 0; j < instanceData->timeDomain->stages->stage[i]->variables->numberOfVariables; j++)
		{	k = instanceData->timeDomain->stages->stage[i]->variables->var[j]->idx;
			if (checkvar[k] != -1) 
			{	delete [] checkvar;
				checkvar = NULL;
				return false;
			}
			checkvar[k] = instanceData->timeDomain->stages->stage[i]->variables->var[j]->idx;
		}
	delete [] checkvar;
	checkvar = NULL;			
	return true;
} //end setTimeDomainVariablesUnordered

/**
 * set time domain stage constraints in temporal order
 */
bool OSInstance::setTimeDomainStageConstraintsOrdered(int numberOfStages, int *numberOfConstraints, int *startIdx)
{   if (instanceData->timeDomain == NULL)
		instanceData->timeDomain = new TimeDomain();
	if (instanceData->timeDomain->interval != NULL)
		return false;
	if (instanceData->timeDomain->stages == NULL)
		instanceData->timeDomain->stages = new TimeDomainStages();	
	if (instanceData->timeDomain->stages != NULL)
	{	if ((instanceData->timeDomain->stages->numberOfStages != numberOfStages) &&
			(instanceData->timeDomain->stages->numberOfStages != 0))
			 return false;
	}
	if (instanceData->timeDomain->stages->numberOfStages == 0 )
	{	instanceData->timeDomain->stages->numberOfStages = numberOfStages;
		if (instanceData->timeDomain->stages->stage == NULL)
			instanceData->timeDomain->stages->stage = new TimeDomainStage*[numberOfStages];
		for (int i = 0; i < numberOfStages; i++)
			instanceData->timeDomain->stages->stage[i] = new TimeDomainStage();
	}
	int checksum = 0;
	for (int i = 0; i < numberOfStages; i++)
	//initial or empty vars, cons, objectives and set default to all objectives
	{	if (instanceData->timeDomain->stages->stage[i]->constraints != NULL)
		{	delete instanceData->timeDomain->stages->stage[i]->constraints;
			instanceData->timeDomain->stages->stage[i]->constraints = NULL;
		}
		instanceData->timeDomain->stages->stage[i]->constraints = new TimeDomainStageConstraints();
		instanceData->timeDomain->stages->stage[i]->constraints->startIdx = startIdx[i];
		instanceData->timeDomain->stages->stage[i]->constraints->numberOfConstraints = numberOfConstraints[i];
		checksum += numberOfConstraints[i];
	}
	return (checksum == instanceData->constraints->numberOfConstraints);
} // end of setTimeStageConstraintsOrdered

/**
 * set time domain stage constraints in arbitrary order
 */
bool OSInstance::setTimeDomainStageConstraintsUnordered(int numberOfStages, int *numberOfConstraints, int **conIndex)
{   if (instanceData->timeDomain == NULL)
		instanceData->timeDomain = new TimeDomain();
	if (instanceData->timeDomain->interval != NULL)
		return false;
	if (instanceData->timeDomain->stages == NULL)
		instanceData->timeDomain->stages = new TimeDomainStages();	
	if (instanceData->timeDomain->stages != NULL)
	{	if ((instanceData->timeDomain->stages->numberOfStages != numberOfStages) &&
			(instanceData->timeDomain->stages->numberOfStages != 0))
			 return false;
	}
	if ( instanceData->timeDomain->stages->numberOfStages == 0 )
	{	instanceData->timeDomain->stages->numberOfStages = numberOfStages;
		if (instanceData->timeDomain->stages->stage == NULL)
			instanceData->timeDomain->stages->stage = new TimeDomainStage*[numberOfStages];
		for (int i = 0; i < numberOfStages; i++)
			instanceData->timeDomain->stages->stage[i] = new TimeDomainStage();
	}
	int checksum = 0;
	for (int i = 0; i < numberOfStages; i++)
	//initial or empty vars, cons, objectives and set default to all objectives
	{	if (instanceData->timeDomain->stages->stage[i]->constraints != NULL)
		{	delete instanceData->timeDomain->stages->stage[i]->constraints;
			instanceData->timeDomain->stages->stage[i]->constraints = NULL;
		}
		instanceData->timeDomain->stages->stage[i]->constraints = new TimeDomainStageConstraints();
		instanceData->timeDomain->stages->stage[i]->constraints->numberOfConstraints = numberOfConstraints[i];
		instanceData->timeDomain->stages->stage[i]->constraints->con = new TimeDomainStageCon*[numberOfConstraints[i]];
		for (int j = 0; j < numberOfConstraints[i]; j++)
		{	instanceData->timeDomain->stages->stage[i]->constraints->con[j] = new TimeDomainStageCon();
			instanceData->timeDomain->stages->stage[i]->constraints->con[j]->idx = conIndex[i][j];
		}
		checksum += numberOfConstraints[i];
	}
	if (checksum != instanceData->constraints->numberOfConstraints) return false;
	int *checkvar = new int[instanceData->constraints->numberOfConstraints];
	for (int j = 0; j < instanceData->constraints->numberOfConstraints; j++)
		checkvar[j] = -1;
	int k;
	for (int i = 0; i < numberOfStages; i++)
		for (int j = 0; j < instanceData->timeDomain->stages->stage[i]->constraints->numberOfConstraints; j++)
		{	k = instanceData->timeDomain->stages->stage[i]->constraints->con[j]->idx;
			if (checkvar[k] != -1) 
			{	delete [] checkvar;
				checkvar = NULL;
				return false;
			}
			checkvar[k] = instanceData->timeDomain->stages->stage[i]->constraints->con[j]->idx;
		}
	delete [] checkvar;
	checkvar = NULL;			
	return true;
}// end setTimeDomainStageConstraintsUnordered()

/**
 * set time domain stage objectives in temporal order
 */
bool OSInstance::setTimeDomainStageObjectivesOrdered(int numberOfStages, int *numberOfObjectives, int *startIdx)
{   if (instanceData->timeDomain == NULL)
		instanceData->timeDomain = new TimeDomain();
	if (instanceData->timeDomain->interval != NULL)
		return false;
	if (instanceData->timeDomain->stages == NULL)
		instanceData->timeDomain->stages = new TimeDomainStages();	
	if (instanceData->timeDomain->stages != NULL)
	{	if ((instanceData->timeDomain->stages->numberOfStages != numberOfStages) &&
			(instanceData->timeDomain->stages->numberOfStages != 0))
			 return false;
	}
	if (instanceData->timeDomain->stages->numberOfStages == 0)
	{	instanceData->timeDomain->stages->numberOfStages = numberOfStages;
		if (instanceData->timeDomain->stages->stage == NULL)
			instanceData->timeDomain->stages->stage = new TimeDomainStage*[numberOfStages];
		for (int i = 0; i < numberOfStages; i++)
			instanceData->timeDomain->stages->stage[i] = new TimeDomainStage();
	}
	for (int i = 0; i < numberOfStages; i++)
	//initial or empty vars, cons, objectives and set default to all objectives
	{	if (instanceData->timeDomain->stages->stage[i]->objectives != NULL)
		{	delete instanceData->timeDomain->stages->stage[i]->objectives;
			instanceData->timeDomain->stages->stage[i]->objectives = NULL;
		}
		instanceData->timeDomain->stages->stage[i]->objectives = new TimeDomainStageObjectives();
		instanceData->timeDomain->stages->stage[i]->objectives->startIdx = startIdx[i];
		instanceData->timeDomain->stages->stage[i]->objectives->numberOfObjectives = numberOfObjectives[i];
	}
	return true;
}

/**
 * set time domain stage objectives in arbitrary order
 */
bool OSInstance::setTimeDomainStageObjectivesUnordered(int numberOfStages, int *numberOfObjectives, int **objIndex)
{   if (instanceData->timeDomain == NULL)
		instanceData->timeDomain = new TimeDomain();
	if (instanceData->timeDomain->interval != NULL)
		return false;
	if (instanceData->timeDomain->stages == NULL)
		instanceData->timeDomain->stages = new TimeDomainStages();	
	if (instanceData->timeDomain->stages != NULL)
	{	if ((instanceData->timeDomain->stages->numberOfStages != numberOfStages) &&
			(instanceData->timeDomain->stages->numberOfStages != 0))
			 return false;
	}
	if (instanceData->timeDomain->stages->numberOfStages == 0)
	{	instanceData->timeDomain->stages->numberOfStages = numberOfStages;
		if (instanceData->timeDomain->stages->stage == NULL)
			instanceData->timeDomain->stages->stage = new TimeDomainStage*[numberOfStages];
		for (int i = 0; i < numberOfStages; i++)
			instanceData->timeDomain->stages->stage[i] = new TimeDomainStage();
	}
	for (int i = 0; i < numberOfStages; i++)
	//initial or empty vars, cons, objectives and set default to all objectives
	{	if (instanceData->timeDomain->stages->stage[i]->objectives != NULL)
		{	delete instanceData->timeDomain->stages->stage[i]->objectives;
			instanceData->timeDomain->stages->stage[i]->objectives = NULL;
		}
		instanceData->timeDomain->stages->stage[i]->objectives = new TimeDomainStageObjectives();
		instanceData->timeDomain->stages->stage[i]->objectives->numberOfObjectives = numberOfObjectives[i];
		instanceData->timeDomain->stages->stage[i]->objectives->obj = new TimeDomainStageObj*[numberOfObjectives[i]];
		for (int j = 0; j < numberOfObjectives[i]; j++)
		{	instanceData->timeDomain->stages->stage[i]->objectives->obj[j] = new TimeDomainStageObj();
			instanceData->timeDomain->stages->stage[i]->objectives->obj[j]->idx = objIndex[i][j];
		}
	}
	int *checkvar = new int[instanceData->objectives->numberOfObjectives];
	for (int j = 0; j < instanceData->objectives->numberOfObjectives; j++)
		checkvar[j] = 0;
	int k;
	for (int i = 0; i < numberOfStages; i++)
		for (int j = 0; j < instanceData->timeDomain->stages->stage[i]->objectives->numberOfObjectives; j++)
		{	k = -instanceData->timeDomain->stages->stage[i]->objectives->obj[j]->idx-1;
			checkvar[k] = instanceData->timeDomain->stages->stage[i]->objectives->obj[j]->idx;
		}
	for (int i = 0; i < instanceData->objectives->numberOfObjectives; i++)
		if (checkvar[i] == 0)
		{	delete [] checkvar;
			checkvar = NULL;
			return false;
		}
	delete [] checkvar;
	checkvar = NULL;			
	return true;
}

/**
 * set time domain interval
 */
bool OSInstance::setTimeDomainInterval(double start, double horizon)
{   if (instanceData->timeDomain == NULL)
		instanceData->timeDomain = new TimeDomain();
	if (instanceData->timeDomain->stages != NULL)
		return false;
	if (instanceData->timeDomain->interval == NULL)
		instanceData->timeDomain->interval = new TimeDomainInterval();	
	instanceData->timeDomain->interval->start = start;
	instanceData->timeDomain->interval->horizon = horizon;
	return true;
} //end setTimeDomainInterval

