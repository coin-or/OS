/* $Id: OSColGenApp.h 3038 2009-11-07 11:43:44Z kmartin $ */
/** @file OSColGenApp.h
 * 
 * \remarks
 * Copyright (C) 2005-2008, Horand Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University,  Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */

#ifndef OSCOLGENAPP_H
#define OSCOLGENAPP_H

// --------------------------------------------------------------------- //
#include "OSDataStructures.h"
#include "OSDefaultSolver.h" 
#include "OSrLReader.h"
#include "OSOption.h"
#include "OSInstance.h"
#include "OSoLReader.h"
#include "OSCoinSolver.h"
#include "OSBearcatSolverXij.h"
#include "OSDecompParam.h"
#include  "OSDecompFactoryInitializer.h"

#include "OSNode.h"

#include<vector>

// --------------------------------------------------------------------- //
/*!
 * \class 
 * OSColGenApp
 * 
 *
 */
// --------------------------------------------------------------------- //
class OSColGenApp {
public:
	
	OSDecompFactoryInitializer *m_factoryInit;
	

	OSDecompSolver *m_osrouteSolver;
	
	//OSBearcatSolverXij *m_osrouteSolver;
	//OSDecompSolver *m_osrouteSolver;
	
	std::ostringstream outStr;
	
	OSInstance *m_osinstanceMaster;
	OSOption *m_osoption;
	OSResult *m_osresult;
	
	/** this variable is true if we have called
	 * the branchAndBound() method
	 */
	
	bool m_calledBranchAndBound;

	
	//the OS solver wrapper
	CoinSolver *m_solver;

	OsiSolverInterface *m_si;

	
	/** Application specific parameters. */
	OSDecompParam m_osDecompParam;
	
	/** kount the nodes generated **/
	int m_numNodesGenerated;
	
	/** kount the columns generated **/
	int m_numColumnsGenerated;
	
	/** when
	 * m_numColumnsGenerated - m_numColumnsOld
	 * hits masterColumnResetValue we do a 
	 * reset
	 */
	
	int m_numColumnsOld;
	
	/** m_message is the message to the pauHana routine*/
	std::string m_message;
	
	/** m_zUB is the upper bound */
	double m_zUB;
	
	/** m_zLB is the lower bound */
	double m_zLB;
	
	/** m_zRootLP is the value of the root LP relaxation */
	double m_zRootLP;
	
	/** nodeMap is the map of nodes in the
	 * branch and bound tree
	 */
	std::map<int, OSNode*> m_nodeMap;
	
	/** 
	 * m_zOptIndexes is the vector theta indexes
	 * corresponding to the current m_zUB
	 */
	std::vector<int> m_zOptIndexes;
	
	/** 
	 * m_zOptRootLP is the vector theta indexes
	 * corresponding to optimal LP solution 
	 * at the roor tnode
	 */
	std::vector<int> m_zOptRootLP;
	
	
	std::map<int, int> inVars;
	

	
	
	/** m_yA is the dual values for the initial restricted constraints */
	double *m_yA;
	
	/** m_yB is the dual for the cuts that get added */
	double *m_yB;
	
	/** m_theta is the primal values in the  master */
	double* m_theta;
	
	/** m_maxCols is the maximum number of columns we can have */
	int m_maxCols;
	
	/** m_maxRows is the maximum number of rows we can have */
	int m_maxRows;
	
	/** kipp -- document */
	void solveRestrictedMasterRelaxation( );

	
	void getOptions( OSOption *osoption);
	
	/** the method that invokes and controls
	 * branch and bound
	 */
	
	
	/** return true if nothing goes wrong */
	bool branchAndBound();
	
	void solve();
	
	/***  
	 * print the information about the current tree
	 */
	void printTreeInfo();
	
	
	void getInitialRestrictedMaster( );
	
	/**
	 * 
	 * INPUT:
	 * double* thetaVar -- the vector of primal master values
	 * int numThetaVar -- size of master primal vector
	 * tol -- is the tolerance on 0/1
	 * 
	 * return true if the solution is integer
	 */
	bool isInteger( const double *thetaVar, const int numThetaVar, 
			const double tol);
	

	void printDebugInfo( );
	
	/**
	 * RETURN VALUES: 
	 * int numNewRows -- number of new rows generated
	 * int* numNonz -- number of nonzeros in each row
	 * double** colIdx -- vectors column indexes of new rows
	 * double** values -- vectors of matrix coefficient values of new rows
	 * double* rowLB -- vector of row lower bounds
	 * double* rowUB -- vector of row upper bounds
	 * 
	 * INPUT:
	 * double* thetaVar -- the vector of primal master values
	 * int numThetaVar -- size of master primal vector
	 */
	void getCuts(const  double* thetaVar, const int numThetaVar,
			int &numNewRows, int*  &numNonz, int** &colIdx,
			double** &values, double* &rowLB, double* &rowUB) ;	
	
	/**
	 * RETURN VALUES: 
	 * int numNewColumns -- number of new columns generated
	 * int* numNonz -- number of nonzeros in each column
	 * double* cost -- the objective function coefficient on each new column
	 * double** rowIdx -- vectors row indexes of new columns
	 * double** values -- vectors of matrix coefficient values of new columns
	 * double lowerBound -- the lowerBound
	 * 
	 * INPUT:
	 * double* yA -- the vector of dual values on the coupling constraints
	 * int numARows -- size of the yA dual vector
	 * double* yB -- the vector of dual values on the tour breaking constaints
	 * int numBRows -- size of the yA dual vector
	 */
	void getColumns(const  double* yA, const int numARows,
			const  double* yB, const int numBRows,
			int &numNewColumns, int* &numNonz, double* &cost, 
			int** &rowIdx, double** &values, double &lowerBound) ;
	
	
	/**
	 * 
	 * INPUT:
	 * OSNode* osnode -- the parent node for which we create a child
	 * std::map<int, int> varConMap -- the variable constraint map
	 * rowIdx is the index of the branching row
	 * rowLB is the lower bound of the new branching row
	 * rowUB is the upper bound of the new branching row
	 * 
	 * method returns a pointer to a child node
	 * if a new branching variable is found we may add that to
	 * the map so varConMap can gen
	 */
	OSNode* createChild(const OSNode *osnode, std::map<int, int> &varConMap,
			const int rowIdx, const double rowLB, const double rowUB);
	
	
	
	/**
	 * 
	 * INPUT: -- sparse version
	 * int* thetaIdx -- index vector of nonzero theta variables 
	 * double* theta -- the sparse vector of primal master values
	 * int numThetaVar -- size of master primal vector
	 * std::map<int, int> varConMap -- the variable constraint map
	 * 
	 * RETURN:
	 * 
	 * rowIdx is the row index of the row used for branching
	 * 
	 */
	void createBranchingCut(const int* thetaIdx, const double* theta, 
			const int numThetaVar, std::map<int, int> &varConMap, int &rowIdx);
	
	
	/**
	 * 
	 * INPUT: -- dense version
	 * double* theta -- the dense vector of primal master values
	 * int numThetaVar -- size of master primal vector
	 * std::map<int, int> varConMap -- the variable constraint map
	 * 
	 * RETURN:
	 * 
	 * rowIdx is the row index of the row used for branching
	 * 
	 */
	void createBranchingCut(const double* theta, const int numThetaVar, 
			std::map<int, int> &varConMap, int &rowIdx);
	
	
	void resetMaster( );
	
	/**
	 *
	 * Default Constructor. 
	 */	
	OSColGenApp();
	
	/**
	 *
	 * Second Constructor. 
	 */	
	OSColGenApp( OSOption *osption);
	

	/**
	 *
	 * Default destructor. 
	 */	
	~OSColGenApp();	

	//
};//end class OSColGenApp

#endif

