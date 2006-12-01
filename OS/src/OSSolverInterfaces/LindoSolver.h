/** @file LindoSolver.h
 * 
 * @author  Robert Fourer,  Jun Ma, Kipp Martin, 
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005, Robert Fourer, Jun Ma, Kipp Martin, Huanyuan Sheng
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */
 
#ifndef LINDOSOLVER_H
#define LINDOSOLVER_H

#include "DefaultSolver.h"
#include "OSInstance.h"
#include "lindo.h"
#include "OSrLWriter.h"
#include "OSConfig.h" 
#include <string>

class LindoSolver : public DefaultSolver{  

public:

	LindoSolver();
	~LindoSolver();
	virtual void  solve() ;
	void solveInsList();
	// Lindo specific methods
	bool optimize();
	bool getLPData();
	bool processVariables();
	bool processConstraints();
	bool generateLindoModel();
	bool addSlackVars();
	bool processQuadraticTerms();
	bool processNonlinearExpressions();
	void dataEchoCheck();


	
private:

  /** declare an instance of the LINDO environment object */
	pLSenv pEnv_;  
	
   /** declare an instance of the LINDO model object */
    pLSmodel pModel_;
	
   /** m_iErrorCode is a variable for LINDO error codes */
    int m_iLindoErrorCode;
	
   /** because LINDO API does not take row ranges we need some extra suff 
   * m_miSlackIdx indexes the rows that get additional slack variable*/
    int *m_miSlackIdx;
	
   /** m_iNumberNewSlacks is the number of slack variables to add */
    int m_iNumberNewSlacks; 
	
	/** m_mdRhsValue is used to the store the constraint rhs if
	 * we do not use row upper and lower bounds
	 */
	double *m_mdRhsValue; 
   
	/** m_mcRowType  - E for equality, L for less than, G for greater than -- 
     * used if we do not store rows using upper and lower bounds
     */
	char *m_mcRowType;
	
	/**
	 * m_mdLb holds an array of variable lower bounds.
	 */
	 double* m_mdVarLB;
	 
	/**
	 * m_mdUb holds an array of variable upper bounds.
	 */
	 double* m_mdVarUB;
	
	/**
	 * m_mdLhs holds an array of the constraint lower bounds.
	 */
	 double* m_mdConLB;
	
	/**
	 * m_mdRhs holds an array of the constraint upper bounds.
	 */
	 double* m_mdConUB;
	
	/**
	 * m_mmcVarName holds an array of char arrays.
	 */
	 char** m_mmcVarName;
	 
	/**
	 * m_msVarName holds an array of variable std::string names.
	 */
	 std::string* m_msVarName;
	 
	/**
	 * m_msConName holds an array of constraint std::string names.
	 */
	 std::string* m_msConName;
	
	/**
	 * m_vcVarType holds an array of variable types (character), e.g. 'C' for continuous
	 * type, 'I' for integer type, 'B' for binary type, 'S' for std::string type).
	 */
	 char* m_mcVarType;
	/**
	 * m_mdObjConstant holds an array of objective function constants.
	 */
	 double m_mdObjConstant; // change to array later

	/** osrlwriter object used to write osrl from and OSResult object */
	OSrLWriter  *osrlwriter;
	
	protected:
	 /**
	  * Lindo's generalized error Reporting function
	  * 
	  */
	void lindoAPIErrorCheck( std::string errormsg);

};



#endif
