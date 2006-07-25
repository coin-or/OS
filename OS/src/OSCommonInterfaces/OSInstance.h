/** @file OSInstance.h
 * \brief This file defines the OSInstance class along with its supporting classes..
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
 * 
<p> 1. Elements become objects of class type (the ComplexType is the class) </p>

<p> 2. The attributes, children of the element, and text correspond to members of the class.  </p>
(Note text does not have a name and becomes .value)

<p> 3. Model groups such as choice and sequence and all correspond to arrays </p>

<p><b>Exceptions:</b> </p>
<ol>
<li> anything specific to XML such as base64, multi, incr do not go into classes </li>
<li> The root OSnLNode of each <nl> element is called ExpressionTree </li>
<li> Root is not called osil it is called osinstance </li>
</ol>
 */
 
 

#ifndef OSINSTANCE_H
#define OSINSTANCE_H
#include "OSParameters.h"
#include "OSDataStructures.h"
#include "OSnLNode.h"
#include "OSExpressionTree.h"
#include <stdlib.h>
#include <string>
#include <map>
using namespace std;



/*! \class Variable
 * \brief The in-memory representation of the <b>variable</b> element..
 */


class Variable{
public:
	/** The Variable class constructor */
	Variable();
	
	/** The Variable class destructor */
	~Variable();

	/** lb corresponds to the optional attribute that holds the variable lower bound, 
	 * the  default value is 0
	 */
	double lb;

	/** ub corresponds to the optional attribute that holds the variable upper bound,
	 * the default value is OSINFINITY 
	 */
	double ub;
	
	/** init corresponds to the optional attribute that holds the variable initial value,
	 * the default value is OSNAN 
	 */
	double init;
	
	/** type corresponds to the attribute that holds the variable type: C (Continuous),
	 * B (binary), I (general integer), or S (string) the default is C
	 */
	char type;
	
	/** name corresponds to the optional attribute that holds the variable name, the 
	 * default value is empty 
	 */ 
	string name;
	
	/** initString corresponds to the optional attribute that holds the name string */
	string initString;
}; // class Variable

class Variables{
public:
	Variables();
	~Variables();
	int numberOfVariables;
	Variable **var;
}; // class Variables



class ObjCoef{
public:
	ObjCoef();
	~ObjCoef();
	int idx;
	double value;
};//class Coef


class Constraint{
public:
	Constraint();
	~Constraint();
	string name;
	double constant;
	double lb;
	double ub;
};//class Constraint

class Constraints{
public:
	Constraints();
	~Constraints();
	int numberOfConstraints;
	Constraint **con;
};//class Constraints



class InstanceHeader{
public:
	InstanceHeader();
	~InstanceHeader();
	string description;
	string name;
	string source;		
};//class InstanceHeader

class Objective{
public:
	Objective();
	~Objective();
	string name;
	string maxOrMin;
	double constant;
	double weight;
	int numberOfObjCoef;
	ObjCoef **coef;
};//class Objective

class Objectives{
public:
	Objectives();
	~Objectives();
	int numberOfObjectives;
	Objective **obj;
};//class Objectives

class LinearConstraintCoefficients{
public:
	LinearConstraintCoefficients();
	~LinearConstraintCoefficients();
	int numberOfValues;
	IntVector *start;
	IntVector *rowIdx;
	IntVector *colIdx;
	DoubleVector *value;
};//class LinearConstraintCoefficients

class QuadraticTerm{
    public:
	QuadraticTerm();
	~QuadraticTerm();
	int idx;
    string id;
    int idxOne;
    int idxTwo;
    double coef;
}; // QuadraticTerm



class QuadraticCoefficients {
    public:
	QuadraticCoefficients();
	~QuadraticCoefficients();
	int numberOfQuadraticTerms;
    QuadraticTerm** qTerm;
}; // QuadraticCoefficients



class Nl{  
public:	
	/** idx holds the row index of the nonlinear expression */
	int idx;
	
	/** osExpressionTree contains the root of the OSExpressionTree */
	OSExpressionTree *osExpressionTree;
	
	/**
	 * default constructor.
	 */
	Nl();

	/**
	 * default destructor.
	 */	
	~Nl();
};//end Nl


class NonlinearExpressions {
    public:
	NonlinearExpressions();
	~NonlinearExpressions();
	int numberOfNonlinearExpressions;
    Nl **nl;
}; // NonlinearExpression
 

class InstanceData{
public:
	InstanceData();
	~InstanceData();
	Variables *variables;
	Objectives *objectives;
	Constraints *constraints;
	LinearConstraintCoefficients *linearConstraintCoefficients;
	QuadraticCoefficients* quadraticCoefficients;
	NonlinearExpressions* nonlinearExpressions;
}; // class InstanceData


/*! \class OSInstance OSInstance.h "OSInstance.h"
 *  \brief The in-memory representation of an OSiL instance..
 *
 * \remarks 
<p> 1. Elements become objects of class type (the ComplexType is the class) </p>

<p> 2. The attributes, children of the element, and text correspond to members of the class.  </p>
(Note text does not have a name and becomes .value)

<p> 3. Model groups such as choice and sequence and all correspond to arrays </p>

<p><b>Exceptions:</b> </p>
<ol>
<li> anything specific to XML such as base64, multi, incr do not go into classes </li>
<li> The root OSnLNode of each <nl> element is called ExpressionTree </li>
<li> Root is not called osil it is called osinstance </li>
</ol>
 *
 * 
 */
class OSInstance {
public:
	OSInstance(); 
	~OSInstance();
	InstanceHeader *instanceHeader;
	InstanceData *instanceData;

private:
	/**
	 * m_sInstanceName holds the instance name. 
	 */
	string m_sInstanceName;
	/**
	 * m_sInstanceSource holds the instance source. 
	 */
	string m_sInstanceSource;	
	/**
	 * m_sInstanceDescription holds the instance description. 
	 */
	string m_sInstanceDescription;
	
	/**
	 * m_bProcessVariables holds whether the variables are processed. 
	 */
	bool m_bProcessVariables ;
	
	/**
	 * m_iVariableNumber holds the variable number. 
	 */
	int m_iVariableNumber;
	
	/**
	 * m_iNumberOfIntegerVariables holds the number of integer variables. 
	 */
	int m_iNumberOfIntegerVariables;
	
	/**
	 * m_iNumberOfBinaryVariables holds the number of binary variables. 
	 */
	int m_iNumberOfBinaryVariables;

	/**
	 * m_msVariableNames holds an array of variable names. 
	 */
	string* m_msVariableNames;
	
	/**
	 * m_mdVariableInitialValues holds a double array of the initial variable values. 
	 */
	double* m_mdVariableInitialValues ;

	/**
	 * m_msVariableInitialStringValues holds a string array of the initial variable values. 
	 */
	string* m_msVariableInitialStringValues;

	/**
	 * m_mcVariableTypes holds a char array of variable types (default = 'C').
	 * (C for Continuous; B for Binary; I for Integer; S for String)
	 */
	char* m_mcVariableTypes;

	/**
	 * m_mdVariableLowerBounds holds a double array of variable lower bounds (default = 0.0).
	 */
	double* m_mdVariableLowerBounds;

	/**
	 * m_mdVariableUpperBounds holds a double array of variable upper bounds (default = INF).
	 */
	double* m_mdVariableUpperBounds;

	/**
	 * m_bProcessObjectives holds whether the objectives are processed. 
	 */
	bool m_bProcessObjectives;

	/**
	 * m_iObjectiveNumber is the number of objective functions. 
	 */
	int m_iObjectiveNumber;
	
	/**
	 * m_iObjectiveNumber is the number of objective functions with a nonlinear term. 
	 */
	int m_iObjectiveNumberNonlinear;
	
	/**
	 * m_msObjectiveNames holds an array of objective names. 
	 */
	string* m_msObjectiveNames;
	
	/**
	 * m_msMaxOrMins holds a string array of objective maxOrMins ("max" or "min").  
	 */
	string* m_msMaxOrMins;
	
	/**
	 * m_miNumberOfObjCoef holds an integer array of number of objective coefficients (default = 0.0). 
	 */
	int* m_miNumberOfObjCoef;
	
	/**
	 * m_mdObjectiveConstants holds an array of objective constants (default = 0.0). 
	 */
	double* m_mdObjectiveConstants;
	
	/**
	 * m_mdObjectiveWeights holds an array of objective weights (default = 1.0).
	 */
	double* m_mdObjectiveWeights;
	
	/**
	 * m_mObjectiveCoefficients holds an array of objective coefficients, one set of objective 
	 * coefficients for each objective. 
	 */
	SparseVector** m_mObjectiveCoefficients;
	
	/**
	 * m_bGetDenseObjectives holds whether the dense objective functions are processed. 
	 */
	bool m_bGetDenseObjectives;
	
	
	/**
	 * m_mmdDenseObjectiveCoefficients holds an array of pointers, each pointer points 
	 * to a vector of dense objective function coefficients 
	 */
	double** m_mmdDenseObjectiveCoefficients;

	/**
	 * m_bProcessConstraints holds whether the constraints are processed. 
	 */
	bool m_bProcessConstraints;
	
	/**
	 * m_iConstraintNumber is the number of constraints. 
	 */
	int m_iConstraintNumber;
	
	/**
	 * m_iConstraintNumberNonlinear is the number of constraints that have a nonlinear term. 
	 */
	int m_iConstraintNumberNonlinear;

	/**
	 * m_msConstraintNames holds an array of constraint names. 
	 */
	string* m_msConstraintNames;
	
	/**
	 * m_mdConstraintLowerBounds holds an array of constraint lower bounds (default = -INF). 
	 */
	double* m_mdConstraintLowerBounds;

	/**
	 * m_mdConstraintUpperBounds holds an array of constraint upper bounds (default = INF). 
	 */
	double* m_mdConstraintUpperBounds;

	/**
	 * m_mcConstraintTypes holds a char array of constraint types
	 * (R for range; L for <=; G for >=; E for =; U for unconstrained)
	 */
	char* m_mcConstraintTypes;
	
	/**
	 * m_bProcessLinearConstraintCoefficients holds whether the linear constraint coefficients are processed. 
	 */
	bool m_bProcessLinearConstraintCoefficients;
	
	/**
	 * m_iLinearConstraintCoefficientNumber holds the number of specified 
	 * (usually nonzero) linear constraint coefficient values. 
	 */
	int m_iLinearConstraintCoefficientNumber;

	/**
	 * m_bColumnMajor holds whether the linear constraint coefficients are stored in column major. 
	 */
	bool m_bColumnMajor;


	/**
	 * m_linearConstraintCoefficientsInColumnMajor holds the standard 3 array data structure for linear constraint coefficients 
	 * (starts, indexes and values) in column major. 
	 */
	SparseMatrix* m_linearConstraintCoefficientsInColumnMajor ;

	/**
	 * m_linearConstraintCoefficientsInRowMajor holds the standard 3 array data structure for linear constraint coefficients 
	 * (starts, indexes and values) in row major. 
	 */
	SparseMatrix* m_linearConstraintCoefficientsInRowMajor ;

	/**
	 * m_linearConstraintCoefficientsInMatrixMarket holds linear constraint coefficients in the matrix market  
	 * form (rowIndex, columnIndex, Value[rowIndex,columnIndex]). 
	 */
//	MatrixMarket m_linearConstraintCoefficientsInMatrixMarket;
	
	/**
	 * m_bProcessQuadraticTerms holds whether the quadratic terms are processed. 
	 */
	bool m_bProcessQuadraticTerms ;

	/**
	 * m_iQuadraticTermNumber holds the number of specified 
	 * (usually nonzero) qTerms in the quadratic coefficients. 
	 */
	int m_iQuadraticTermNumber ;

	/**
	 * m_quadraticTerms the data structure for all the quadratic terms in the instance. 
	 * (rowIdx, varOneIdx, varTwoIdx, coef)
	 */
	
	/**
	 * m_bProcessNonlinearExpressions holds whether the nonlinear expressions are processed. 
	 */
	bool m_bProcessNonlinearExpressions ;
	
	/**
	 * m_iNonlinearExpressionNumber holds the number of nonlinear expressions. 
	 */
	int m_iNonlinearExpressionNumber;

	/**
	 * m_miNonlinearExpressionIndexes holds an integer array of nonlinear expression indexes,
	 * negative indexes correspond to objectives.  
	 */
	int* m_miNonlinearExpressionIndexes ;
	
	/**
	 * m_bProcessExpressionTrees is true if the expression trees have been processed. 
	 */
	bool m_bProcessExpressionTrees;
	
	/**
	 * m_bProcessExpressionTreesInPostfix is true if the expression trees have been processed in postfix. 
	 */
	//bool m_bProcessExpressionTreesInPostfix;
	
	/**
	 * m_mNonlinearExpressionTrees holds an array of nonlinear expression trees, each tree is of the standard
	 * type OSExpressionTree. 
	 */
	//OSExpressionTree* m_mNonlinearExpressionTrees ;


	/**
	 * m_mapExpressionTrees holds a hash map of expression trees, with the key being the row index
	 * and value being the expression tree representing the nonlinear expression of that row.
	 */
	std::map<int, OSnLNode*> m_mapExpressionTrees ;
	
	/**
	 * m_mapExpressionTrees holds a hash map of expression trees in postfix format, with the key being the row index
	 * and value being the expression tree representing the nonlinear expression of that row.
	 */
	std::map<int, std::vector<OSnLNode*> > m_mapExpressionTreesInPostfix ;
	
	/**
	 * process variables. 
	 * 
	 * @return true if the variables are processed. 
	 * @throws Exception if the elements in variables are logically inconsistent. 
	 */
	bool processVariables()	;
	
	/**
	 * process objectives. 
	 * 
	 * @return true if the objectives are processed. 
	 * @throws Exception if the elements in objectives are logically inconsistent. 
	 */
	bool processObjectives();
	
	
	/**
	 * process constraints. 
	 * 
	 * @return true if the constraints are processed. 
	 * @throws Exception if the elements in constraints are logically inconsistent. 
	 */
	bool processConstraints();
	
	
	/**
	 * process linear constraint coefficients. 
	 * 
	 * @return true if the inear constraint coefficients are processed. 
	 * @throws Exception if the elements in inear constraint coefficients are logically inconsistent. 
	 */
	bool processLinearConstraintCoefficients();
	
	
	/**
	 * m_quadraticTerms the data structure for all the quadratic terms in the instance. 
	 * (rowIdx, varOneIdx, varTwoIdx, coef)
	 */
	QuadraticTerms* m_quadraticTerms;
	
public:

	/**
	 * Get instance name. 
	 * 
	 * @return instance name. Null or empty string ("") if there is no instance name. 
	 */
	string getInstanceName();
		

	/**
	 * Get instance source. 
	 * 
	 * @return instance source. Null or empty string ("") if there is no instance source. 
	 */
	string getInstanceSource();
	
	
	/**
	 * Get instance description. 
	 * 
	 * @return instance description. Null or empty string ("") if there is no instance description. 
	 */
	string getInstanceDescription();
	
	/**
	 * Get variable number. 
	 * 
	 * @return variable number. 
	 */
	int getVariableNumber();
	
	/**
	 * Get variable names. 
	 * 
	 * @return a string array of variable names, null if no variable names.
	 * @throws Exception if the elements in variables are logically inconsistent. 
	 */
	string* getVariableNames();
	
	/**
	 * Get variable initial values. 
	 * 
	 * @return a double array of variable initial values, null if no initial variable values.
	 * @throws Exception if the elements in variables are logically inconsistent. 
	 */
	double* getVariableInitialValues();
	
	/**
	 * Get variable initial string values. 
	 * 
	 * @return a string array of variable initial values, null if no initial variable string values.
	 * @throws Exception if the elements in variables are logically inconsistent. 
	 */
	string* getVariableInitialStringValues();
	
	/**
	 * Get variable types. 
	 * <ul>
	 * <li>C for Continuous </li>
	 * <li>B for Binary </li> 
	 * <li>I for Integer</li> 
	 * <li>S for String</li>
	 * </ul>
	 * @return a char array of variable types. 
	 * @throws Exception if the elements in variables are logically inconsistent. 
	 */
	char* getVariableTypes();
	
	/**
	 * getNumberOfIntegerVariables
	 * @return an integer which is the number of I variables. 
	 */
	int getNumberOfIntegerVariables();
	
	/**
	 * getNumberOfBinaryVariables
	 * @return an integer which is the number of B variables. 
	 */
	int getNumberOfBinaryVariables();
	
	/**
	 * Get variable lower bounds. 
	 * 
	 * @return a double array of variable lower bounds. 
	 * @throws Exception if the elements in variables are logically inconsistent. 
	 */
	double* getVariableLowerBounds();
	
	/**
	 * Get variable upper bounds. 
	 * 
	 * @return a double array of variable upper bounds. 
	 * @throws Exception if the elements in variables are logically inconsistent. 
	 */
	double* getVariableUpperBounds();
	
	/**
	 * Get objective number. 
	 * 
	 * @return objective number. 
	 */
	int getObjectiveNumber();
	
	
	/**
	 * Get objective names. 
	 * 
	 * @return a string array of objective names. Null if no objective names.
	 * @throws Exception if the elements in objectives are logically inconsistent. 
	 */
	string* getObjectiveNames();

	/**
	 * Get objective maxOrMins. One maxOrMin for each objective.
	 * 
	 * @return a string array of objective maxOrMins ("max" or "min"), null if no objectives. 
	 * @throws Exception if the elements in objectives are logically inconsistent. 
	 */
	string* getObjectiveMaxOrMins();
	
	/**
	 * Get objective coefficient number. One number for each objective.
	 * 
	 * @return an integer array of objective coefficient numbers, null if no objectives. 
	 * @throws Exception if the elements in objectives are logically inconsistent. 
	 */
	int* getObjectiveCoefficientNumbers();
	
	/**
	 * Get objective constants. One constant for each objective.
	 * 
	 * @return a double array of objective constants, null if no objectives. 
	 * @throws Exception if the elements in objectives are logically inconsistent. 
	 */
	double* getObjectiveConstants();
	
	/**
	 * Get objective weights. One weight for each objective.
	 * 
	 * @return a double array of objective weights, null if no objectives. 
	 * @throws Exception if the elements in objectives are logically inconsistent. 
	 */
	double* getObjectiveWeights();
	
	/**
	 * Get objective coefficients. One set of objective coefficients for each objective.
	 * 
	 * @see org.optimizationservices.oscommon.datastructure.SparseVector
	 * @return an array of objective coefficients, null if objective coefficients. 
	 * Each member of the array is of type
	 * ObjectiveCoefficients. The ObjectiveCoefficients class contains two arrays:
	 * variableIndexes is an integer array and values is a double array of coefficient values. 
	 * @throws Exception if the elements in objectives are logically inconsistent. 
	 */
	SparseVector** getObjectiveCoefficients();
	
	/**
	 * getDenseObjectiveCoefficients. 
	 * 
	 * @return an vector of pointers, each pointer points to a dense vector of 
	 * ObjectiveCoefficients. 
	 */
	double** getDenseObjectiveCoefficients();
	
	/**
	 * Get constraint number. 
	 * 
	 * @return constraint number. 
	 */
	int getConstraintNumber();
	
	/**
	 * Get constraint names. 
	 * 
	 * @return a string array of constraint names, null if no constraint names.
	 * @throws Exception if the elements in constraints are logically inconsistent. 
	 */
	string* getConstraintNames();
	
	/**
	 * Get constraint lower bounds. 
	 * 
	 * @return a double array of constraint lower bounds, null if constraints.
	 * @throws Exception if the elements in constraints are logically inconsistent. 
	 */
	double* getConstraintLowerBounds();
	
	/**
	 * Get constraint upper bounds. 
	 * 
	 * @return a double array of constraint upper bounds, null if constraints. 
	 * @throws Exception if the elements in constraints are logically inconsistent. 
	 */
	double *getConstraintUpperBounds();
	
	/**
	 * Get constraint types. 
	 * <ul>
	 * <li>R for range constraint lb <= constraint <= ub </li>
	 * <li>L for less than constraint  -INF <= con <= ub or con <= ub</li>
	 * <li>G for greater than constraint lb <= con <= INF or con >= lb </li>
	 * <li>E for equal to constraint  lb <= con <= ub where lb = ub  or con = lb/ub </li>
	 * <li>U for unconstrained constraint -INF <= con <= INF</li>
	 * </ul>
	 * @return a char array of constraint types, null if constraints.
	 * @throws Exception if the elements in constraints are logically inconsistent. 
	 */
	char* getConstraintTypes();
	
	/**
	 * Get number of specified (usually nonzero) linear constraint coefficient values. 
	 * 
	 * @return number of specified (usually nonzero) linear constraint coefficient values. 
	 */
	int getLinearConstraintCoefficientNumber();
	

	/**
	 * Get whether the constraint coefficients is in column major (true) or row major (false). 
	 * 
	 * @return whether the constraint coefficients is in column major (true) or row major (false).
	 * @throws Exception if the elements in linear constraint coefficients are logically inconsistent. 
	 */
	bool getLinearConstraintCoefficientMajor();
	
	
	/**
	 * Get linear constraint coefficients in column major. 
	 * @return a sparse matrix reprsentation of linear constraint coefficients in column major, null if no linear constraint coefficients. 
	 * @throws Exception if the elements in linear constraint coefficients are logically inconsistent. 
	 * @see org.optimizationservices.oscommon.datastructure.SparseMatrix	 
	 */
	SparseMatrix* getLinearConstraintCoefficientsInColumnMajor();
	
	/**
	 * Get linear constraint coefficients in row major. 
	 * @return a sparse matrix reprsentation of linear constraint coefficients in row major, null if no linear constraint coefficients. 
	 * @throws Exception if the elements in linear constraint coefficients are logically inconsistent. 
	 * @see org.optimizationservices.oscommon.datastructure.SparseMatrix
	 */
	SparseMatrix* getLinearConstraintCoefficientsInRowMajor();
	
	/**
	 * Get the number of specified (usually nonzero) qTerms in the quadratic coefficients. 
	 * 
	 * @return qTerm number. 
	 */
	int getNumberOfQuadraticTerms();
	
	/**
	 * Get all the quadratic terms in the instance. 
	 * 
	 * @return the QuadraticTerms data structure for all quadratic terms in the instance, null if no quadratic terms. 
	 * The QuadraticTerms contains four arrays: rowIndexes, varOneIndexes, varTwoIndexes, coefficients.
	 * @throws Exception if the elements in quadratic coefficients are logically inconsistent. 
	 * @see org.optimizationservices.oscommon.datastructure.QuadraticTerms
	 */
	QuadraticTerms* getQuadraticTerms();
	
	/**
	 * Get number of nonlinear expressions. 
	 * 
	 * @return the number of nonlinear expressions. 
	 */
	int getNumberOfNonlinearExpressions();
	
	
	/**
	 * Get the postfix tokens for a given row index  
	 * 
	 * @return a vector of pointers to OSnLNodes in postfix, if rowIdx
	 * does not index a row with a nonlinear term NULL is returned
	 */
	//std::vector<OSnLNode*> getNonlinearExpressionTreeInPostfix(int rowIdx);
	
	/**
	 * Get the expression tree for a given row index  
	 * 
	 * @return an expression tree
	 */
	OSnLNode* getNonlinearExpressionTree(int rowIdx);
	
	/**
	 * @return the number of Objectives with a nonlinear term
	 */	
	int getNumberOfNonlinearObjectives();

	/**
	 * @return the number of Constraints with a nonlinear term
	 */		
	int getNumberOfNonlinearConstraints();
	
	/**
	 * @return a map: the key is the row index and the value is the corresponding expression tree
	 */		
	std::map<int, OSnLNode* > getAllNonlinearExpressionTrees();
	
	// the set() methods
	
	
   	/**
   	 * set the instance source. 
   	 * 
   	 * @param source holds the instance source. 
   	 * @return whether the instance source is set successfully. 
   	 */
   	bool setInstanceSource(string source);
	
 	/**
   	 * set the instance description. 
   	 * 
   	 * @param description holds the instance description. 
   	 * @return whether the instance description is set successfully. 
   	 */
   	bool setInstanceDescription(string description);
	
					
   	/**
   	 * set the instance name. 
   	 * 
   	 * @param name holds the instance name. 
   	 * @return whether the instance name is set successfully. 
   	 */
   	bool setInstanceName(string name);
	
   	/**
   	 * set the variable number. 
   	 * 
   	 * @param number holds the variable number. 
   	 * @return whether the variable number is set successfully. 
  	 */
   	bool setVariableNumber(int number);
	
   	/**
   	 * add a variable. In order to use the add method, the setVariableNumber must first be called
   	 * so that the variable number is known ahead of time to assign appropriate memory.  
   	 * If a variable with the given variable index already exists, the old variable will be replaced. 
   	 * 
   	 * <p>
   	 * 
   	 * @param index holds the variable index. It is required.  
   	 * @param name holds the variable name; use null or empty string ("") if no variable name. 
   	 * @param lowerBound holds the variable lower bound; use Double.NEGATIVE_INFINITY if no lower bound. 
   	 * @param upperBound holds the variable upper bound; use Double.POSITIVE_INFINITY if no upper bound. 
   	 * @param type holds the variable type character, B for Binary, I for Integer, S for String, C or any other char for Continuous)
   	 * @param init holds the double variable initial value; use Double.NaN if no initial value. 
   	 * @param initString holds the string variable initial value; use null or empty string ("") if no initial string value.  
   	 * @return whether the variable is added successfully. 
   	 */
   	bool addVariable(int index, string name, double lowerBound, double upperBound, char type, double init, string initString);
	
   	/**
   	 * set all the variable related elements. All the previous variable-related elements will be deleted. 
   	 * 
   	 * <p>
   	 * 
   	 * @param number holds the number of variables. It is required.  
   	 * @param names holds a string array of variable names; use null if no variable names. 
   	 * @param lowerBounds holds a double array of variable lower bounds; use null all lower bounds are 0; use Double.NEGATIVE_INFINITY if no lower bound for a specific variable in the array. 
   	 * @param upperBounds holds a double array of variable upper bounds; use null if no upper bounds; use Double.POSITIVE_INFINITY if no upper bound for a specific variable in the array. 
   	 * @param types holds a char array of variable types; use null if all variables are continuous; 
   	 * for a specfic variable in the array use B for Binary, I for Integer, S for String, C or any other char for Continuous,)  
   	 * @param inits holds a double array of varible initial values; use null if no initial values. 
   	 * @param initsString holds a string array of varible initial values; use null if no initial string values.  
   	 * @return whether the variables are set successfully. 
   	 */
   	bool setVariables(int number, string* names, double* lowerBounds, 
		double* upperBounds, char* types, double* inits, string* initsString);

   	/**
   	 * set the objective number. 
   	 * 
   	 * @param number holds the objective number. 
   	 * @return whether the objective number is set successfully. 
   	 */
   	bool setObjectiveNumber(int number);
	
  	/**
   	 * add an objective. In order to use the add method, the setObjectiveNumber must first be called
   	 * so that the objective number is known ahead of time to assign appropriate memory.  
   	 * If a objective with the given objective index already exists, the old objective will be replaced.
   	 * Objective index will start from -1, -2, -3, ... down, with -1 corresponding to the first objective.  
   	 * 
   	 * <p>
   	 * 
   	 * @param index holds the objective index. Remember the first objective index is -1, second -2, ...
   	 * @param name holds the objective name; use null or empty string ("") if no objective name. 
   	 * @param maxOrMin holds the objective sense or direction; it can only take two values: "max" or "min". 
   	 * @param constant holds the objective constant; use 0.0 if no objective constant. 
   	 * @param weight holds the objective weight; use 1.0 if no objective weight.
   	 * @param objectiveCoefficients holds the objective coefficients (null if no objective coefficients) in a sparse 
   	 * representation that holds two arrays: index array and a value array.  
   	 * @return whether the objective is added successfully. 
   	 */
   	bool addObjective(int index, string name, string maxOrMin, double constant, double weight, SparseVector* objectiveCoefficients);

   	/**
   	 * set all the objectives related elements. All the previous objective-related elements will be deleted. 
   	 * 
   	 * <p>
   	 * 
   	 * @param number holds the number of objectives. It is required.  
   	 * @param names holds a string array of objective names; use null if no objective names. 
   	 * @param maxOrMins holds a string array of objective objective senses or directions: "max" or "min"; use null if all objectives are "min".   
   	 * @param constants holds a double array of objective constants; use null if all objective constants are 0.0. 
   	 * @param weights holds a double array of objective weights; use null if all objective weights are 1.0. 
     * @param objectitiveCoefficients holds an array of objective coefficients, (null if no objective have any coefficeints)
     * For each objective, the coefficients are stored in a sparse representation that holds two arrays: index array and a value array.  
     * If for a specific objective, there are no objecitve coefficients, use null for the corresponding array member. 
  	 * @return whether the objectives are set successfully. 
   	 */
   	bool setObjectives(int number, string *names, string *maxOrMins, double *constants, double *weights, SparseVector **objectitiveCoefficients);
					
  	/**
   	 * set the constraint number. 
   	 * 
   	 * @param number holds the constraint number. 
   	 * @return whether the constraint number is set successfully. 
   	 */
   	bool setConstraintNumber(int number);

/**
 * add a constraint. In order to use the add method, the setConstraintNumber must first be called
 * so that the constraint number is known ahead of time to assign appropriate memory.  
 * If a constraint with the given constraint index already exists, the old constraint will be replaced. 
 * 
 * <p>
 * 
 * @param index holds the constraint index. It is required.  
 * @param name holds the constraint name; use null or empty string ("") if no constraint name. 
 * @param lowerBound holds the constraint lower bound; use Double.NEGATIVE_INFINITY if no lower bound. 
 * @param upperBound holds the constraint upper bound; use Double.POSITIVE_INFINITY if no upper bound. 
 * @return whether the constraint is added successfully. 
 */
bool addConstraint(int index, string name, double lowerBound, double upperBound, double constant);

/**
 * set all the constraint related elements. All the previous constraint-related elements will be deleted. 
 * 
 * <p>
 * 
 * @param number holds the number of constraints. It is required.  
 * @param names holds a string array of constraint names; use null if no constraint names. 
 * @param lowerBounds holds a double array of constraint lower bounds; use null if no lower bounds; use Double.NEGATIVE_INFINITY if no lower bound for a specific constraint in the array. 
 * @param upperBounds holds a double array of constraint upper bounds; use null if no upper bounds; use Double.POSITIVE_INFINITY if no upper bound for a specific constraint in the array. 
 * @return whether the constraints are set successfully. 
 */
bool setConstraints(int number, string* names, double* lowerBounds, double* upperBounds, double* constants);

/**
 * set linear constraint coefficients
 * 
 * <p>
 * 
 * @param numberOfValues holds the number of specified coefficient values (usually nonzero) in the coefficient matrix. 
 * @param isColumnMajor holds whether the coefficient matrix is stored in column major (true) or row major (false).
 * @param values holds a double array coefficient values in the matrix. 
 * @param valuesBegin holds the begin index of the values array to copy from (usually 0). 
 * @param valuesEnd holds the end index of the values array to copy till (usually values.lenght - 1). 
 * @param indexes holds an integer array column/row indexes for each value in the values array.
 * @param indexesBegin holds the begin index of the indexes array to copy from (usually 0).
 * @param indexesEnd holds the end index of the indexes array to copy till (usually indexes.lenght - 1).
 * @param starts holds an integer array start indexes in the matrix; the first value of starts should always be 0. 
 * @param startsBegin holds the begin index of the starts array to copy from (usually 0).
 * @param startsEnd holds the end index of the starts array to copy till (usually starts.lenght - 1). 
 * @return whether the linear constraint coefficients are set successfully.  
 */
bool setLinearConstraintCoefficients(int numberOfValues, bool isColumnMajor, 
	double* values, int valuesBegin, int valuesEnd, 
	int* indexes, int indexesBegin, int indexesEnd,   			
	int* starts, int startsBegin, int startsEnd);
	
  	/**
   	 * set quadratic terms
   	 * 
   	 * <p>
   	 * 
   	 * @param number holds the number of quadratic terms. 
   	 * @param rowIndexes holds an integer array of row indexes of all the quadratic terms. 
	 * A negative integer corresponds to an objective row, e.g. -1 for 1st objective and -2 for 2nd.
   	 * @param varOneIndexes holds an integer array of the first varialbe indexes of all the quadratic terms.
   	 * @param varTwoIndexes holds an integer array of the second varialbe indexes of all the quadratic terms.
   	 * @param coefficients holds a double array all the quadratic term coefficients.
   	 * @param begin holds the begin index of all the arrays to copy from (usually = 0). 
   	 * @param end holds the end index of all the arrays to copy till (usually = array length -1).
   	 * @return whether the quadratic terms are set successfully.  
   	 */
bool setQuadraticTerms(int number, 
	int* rowIndexes, int* varOneIndexes, int* varTwoIndexes, double* coefficients,
	int begin, int end);

																																																								
}; //class OSInstance

#endif

