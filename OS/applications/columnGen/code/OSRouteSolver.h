/* $Id: OSRouteSolver.h 3038 2009-11-07 11:43:44Z kmartin $ */
/** @file OSRouteSolver.h
 * 
 * \remarks
 * Copyright (C) 2005-2010, Horand Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University,  Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */

#ifndef OSROUTESOLVER_H
#define OSROUTESOLVER_H

#include "OSInstance.h"
#include "OSOption.h"
#include "ClpSimplex.hpp"
#include "OSDecompParam.h"
#include "OSCoinSolver.h"
#include<map>
// --------------------------------------------------------------------- //
/*!
 * \class 
 * OSRouteSolver
 * 
 *
 */
// --------------------------------------------------------------------- //
class OSRouteSolver {
public:
	
	
	OSOption *m_osoption;
	
	/** share the parameters with the 
	 * decomposition solver
	 */
	OSDecompParam m_osDecompParam;
	
	double m_bestIPValue;
	double m_bestLPValue;
	
	std::string m_initOSiLFile;
	
	/** the index on the outer map is on the solution number,
	 * the index on the inner map indexes the route number, 
	 * the vector is the list of nodes assigned to that route
	 */
	std::map<int, std::map<int, std::vector<int> > > m_initSolMap;
	
	/** intVarSet holds and std::pair where the first
	 * element is the index of an integer variable and 
	 * the second is the variable upper bound
	 */
	std::set<std::pair<int, double> > intVarSet;
	
	
	/** m_numHubs is the number of hubs/routes */
	int m_numHubs;
	
	/** m_numNodes is the number of nodes (both pickup 
	 * and hub) in the model
	 */
	int m_numNodes;
	
	
	/*****************Route Solver Parameters***********************/
	
	
	/** m_maxMasterColumns is the maximumn number
	 * of columns we allow in the master
	 */
	int m_maxMasterColumns;
	
	/** m_masterRestValue triggers deleting all the
	 * columns from the master except those corresponding
	 * to the current basis and the columns correxponding
	 * to the best integer value
	 */
	int m_masterResetValue;
	
	/** m_maxMasterNonz is the maximumn number
	 * of nonzero elements we allow in the transformation matrix
	 * betwee the theta variables and the xij variables
	 */
	int m_maxThetaNonz;
	
	/** m_maxBmatrixCon is the maximum number of B matrix constraints
	 * it is the number of tour breaking constraints plus variable 
	 * branch constraints
	 */
	int m_maxBmatrixCon;
	
	/** m_maxBmatrixNonz is the maximum number of nonzero elements
	 * in the B matrix constraints 
	 */
	int m_maxBmatrixNonz;
	
	
	/*****************End Route Solver Parameters***********************/	

	
	
	/** the route capacity -- bus seating limit 
	 * this can vary with the route/hub
	 */
	int* m_routeCapacity;
	
	/** the minimum number of students that we
	 * pickup on a route this can vary with the 
	 * route/hub
	 */
	int* m_routeMinPickup;
	
	
	
	/** largest possible L-value on a route --
	 * this will be the minimum of m_routeCapacity
	 * and total demand
	 */
	int* m_upperBoundL;
	
	
	/**  smallest possible L-value on a route
	 *  for now this will equal 
	 */
	int* m_lowerBoundL;
	
	/**  largest possible L-value over all routes */
	int m_upperBoundLMax;
	
	/**m_minDemand is the value of the minimum demand 
	 * node -- it is not the minimum demand that must
	 *  be carried on a route
	 */
	int m_minDemand;
	
	/** m_demand is the vector of node demands */
	int* m_demand;
	
	/** the distance/cost vectors */
	double** m_cost;
	
	/** the reduced cost vector
	 * for each k, we asssume order is (l, i, j)
	 */
	double** m_rc;
	

	//will be the optimal reduced cost for each hub
	double* m_optValHub;
	
	
	//start variables for the q-route dynamic program
	double** m_u; 
	double** m_v;
	int** m_px;
	int** m_tx;
	double** m_g;
	int* m_varIdx;
	//end variables for the q-route  dynamic programming solution
	
	//variables for the outer dynamic program 
	//get the optimal l value for each route
	int* m_optL; //size is number of routes
	int* m_optD; //size is number of routes
	double** m_vv;
	int** m_vvpnt;
	//end of variable on the outer dynamic program
	
	
	int m_totalDemand;
	int m_numberOfSolutions;
	

	
	//these variable names are in x(i, j) space
	std::string* m_variableNames;

	
	//below  is a scatter array we scatter into in order
	//to multiply the transformation matrix times the A matrix
	int* m_tmpScatterArray;
	
	//arguments for getColumns
	double m_lowerBnd;
	int* m_newColumnNonz;
	double* m_costVec;
	int** m_newColumnRowIdx;
	double** m_newColumnRowValue;
		
	//arguments for getRows
	int* m_newRowNonz;
	int** m_newRowColumnIdx;
	double** m_newRowColumnValue;
	double* m_newRowUB;
	double* m_newRowLB;
	
	//arguments for the getBranchingCut
	int* branchCutIndexes;
	double* branchCutValues;
	//end arguments for the getBranchingCut
		
	//arrays for the coupling constraint matrix
	//we store indexes since values are 1.0
	//also the RHS is 1.0
	//the matrix has m_numNodes - m_numHubs rows
	int* m_pntAmatrix;
	//m_Amatrix holds the column indexes for each row
	int* m_Amatrix;
	//
	//arrays for the added constraints
	//for now the added constraints are 
	//tour breaking and variable branching
	//constraints
	//
	int* m_pntBmatrix;
	int* m_Bmatrix;   
	
	/** m_numBmatrixCon is the number of
	 * constraints in B - 1, we have the -1
	 * because:
	 * m_pntBmatrix[ k] points to the start of
	 * constraint k and m_pntBmatrix[ m_numBmatrixCon ]
	 * is equal to m_numBmatrixNonz
	 */
	int m_numBmatrixCon;   
	int m_numBmatrixNonz;
	//
	//end arrays for added constaints
	
	//the transformation matrix
	int* m_thetaPnt;
	int* m_thetaIndex;
	int m_numThetaVar;
	int m_numThetaNonz;
	
	//kipp -- be carefull does m_thetaCost have
	// artificial variables -- it is 
	double* m_thetaCost;
	
	/** conconvexityRowIndex holds the index of the convexity row
	 * that the theta columns are in. If the theta is an artificial
	 * variable this value is -1
	 */
	int* convexityRowIndex;
	

	 /** m_separationIndexMap maps the variable index into the
	  * appropriate row in the separation problem for the 
	  * tour breaking constraints
	  */
	int* m_separationIndexMap;
	
	OSInstance *m_osinstanceMaster;
	OSInstance *m_osinstanceSeparation;
	
	//the Clp model 
	ClpSimplex*  m_separationClpModel;

	//create the initial restricted master
	OSInstance* getInitialRestrictedMaster( );
	

	//create the initial restricted master a second way
	OSInstance* getInitialRestrictedMaster2( );
	
	
	//this method generates the instance for 
	//separating the tour breaking constraints
	OSInstance* getSeparationInstance();

	/** kipp -- document */
	// note -- this c vector is only for hub k
	double qrouteCost(const int& k, const int& l, const double* c, int* kountVar) ;
	
	//this c vector is for the entire cost vector
	void getOptL( double** c) ;
	
	
	/**
	 * RETURN VALUES: 
	 * int numNewRows -- number of new rows generated
	 * int* numNonz -- number of nonzeros in each row
	 * int** colIdx -- vectors column indexes of new rows
	 * double** values -- vectors of matrix coefficient values of new rows
	 * double* rowLB -- vector of row lower bounds
	 * double* rowUB -- vector of row upper bounds
	 * 
	 * INPUT:
	 * double* thetaVar -- the vector of primal master values
	 * int numThetaVar -- size of master primal vector
	 */
	void getCutsTheta(const  double* thetaVar, const int numThetaVar,
			int &numNewRows, int*  &numNonz, int** &colIdx,
			double** &values, double* &rowLB, double* &rowUB) ;	
	
	
	/**
	 * RETURN VALUES: 
	 * int numNewRows -- number of new rows generated
	 * int* numNonz -- number of nonzeros in each row
	 * int** colIdx -- vectors column indexes of new rows
	 * double** values -- vectors of matrix coefficient values of new rows
	 * double* rowLB -- vector of row lower bounds
	 * double* rowUB -- vector of row upper bounds
	 * 
	 * INPUT:
	 * double* xVar -- the vector of primal  values
	 * int numXVar -- size of master primal vector
	 */
	void getCutsX(const  double* xVar, const int numXVar,
			int &numNewRows, int*  &numNonz, int** &colIdx,
			double** &values, double* &rowLB, double* &rowUB) ;	
	
	
	/**
	 * RETURN VALUES: 
	 * varIdx -- the variable number x_{ij} for branching
	 * numNonz -- number of theta indexes in the cut
	 * indexes -- the indexes of the theta variables
	 * values -- the number of times the theta indexed 
	 * in indexes appears in the cut 
	 * note -- set numNonz to zero if the generated cut
	 * variable already appears in varConMap
	 * 
	 * 
	 * INPUT:
	 * double* thetaVar -- the vector of primal master values
	 * int numThetaVar -- size of master primal vector
	 * varConMap -- the map of variables in x_{ij} space to 
	 * a consraint number
	 * 
	 */
	void getBranchingCut(const double* thetaVar, const int numThetaVar,
			const std::map<int, int> &varConMap, int &varIdx,  int &numNonz, 
			int* &indexes,  double* &values) ;	
	
	
	/**
	 * 
	 * Sparse Version
	 * 
	 * RETURN VALUES: 
	 * varIdx -- the variable number x_{ij} for branching
	 * numNonz -- number of theta indexes in the cut
	 * indexes -- the indexes of the theta variables
	 * values -- the number of times the theta indexed 
	 * in indexes appears in the cut 
	 * note -- set numNonz to zero if the generated cut
	 * variable already appears in varConMap
	 * 
	 * 
	 * INPUT:
	 * double* theta -- the vector of primal master values
	 * int numThetaVar -- size of master primal vector
	 * varConMap -- the map of variables in x_{ij} space to 
	 * a consraint number
	 * 
	 */
	void getBranchingCut(const int* thetaIdx, const double* theta, 
			const int numThetaVar, const std::map<int, int> &varConMap, 
			int &varIdx,  int &numNonz, int* &indexes, double* &values) ;
	
	
	/**
	 * RETURN VALUES: 
	 * return the integer index of a fractional x_{ij} variable
	 * 
	 * INPUT:
	 * double* theta -- the vector of primal master values
	 * int numThetaVar -- size of master primal vector
	 * 
	 */
	int getBranchingVar(const  double* theta, const int numThetaVar ) ;	
	
	
	/**
	 * Sparse Version
	 * 
	 * RETURN VALUES: 
	 * return the integer index of a fractional x_{ij} variable
	 * 
	 * INPUT:
	 * int* thetaIdx -- index vector of nonzero theta variables 
	 * double* theta -- the sparse vector of primal master values
	 * int numThetaVar -- size of master primal vector
	 * 
	 */
	int getBranchingVar(const int* thetaIdx, const double* theta, const int numThetaVar ) ;	
	
	
	/**
	 * RETURN VALUES: 
	 * int numNewColumns -- number of new columns generated
	 * int* numNonz -- number of nonzeros in each column
	 * double* cost -- the objective function coefficient on each new column
	 * double** rowIdx -- vectors row indexes of new columns
	 * double** values -- vectors of matrix coefficient values of new columns
	 * double lowerBound -- the lowerBound, this is a value on the LP relaxation
	 * 
	 * INPUT:
	 * double* y -- the vector of dual values
	 * int numRows -- size of dual vector
	 */
	void getColumns(const  double* yA, const int numARows,
			const  double* yB, const int numBRows,
			int &numNewColumns, int*  &numNonz, double* &cost, 
			int** &rowIdx, double** &values, double &lowerBound) ;
	
	

	
	
	void getOptions( OSOption *osoption);
	
	
	//some utility methods are below
	
	/** calculate the reduced costs
	 * c -- input of the objective function costs
	 * yA -- dual values on node assignment -- coupling constraints
	 * yB -- dual values on tour breaking constraints
	 * d -- reduced with convexity dual value
	 */
	void calcReducedCost(const double* yA,  const double* yB );
	
	//these are the variable in x(i, j) space
	void createVariableNames( );
	
	//this is the matrix that says we must visit each node
	//this A matrix defines the "coupling constraints"
	void createAmatrix();
	
	
	/** allocate memory and initialize
	 * arrays
	 */
	void initializeDataStructures();
	
	/** generate an intitial feasible solution
	 * in theta space for the initial master
	 */
	void getInitialSolution();
	
	//this method gets called when we are done
	void pauHana(std::vector<int> &m_zOptIndexes);
	
	/** use this method to reset the master
	 * RETURN VALUES: 
	 * 
	 * INPUT:
	 * std::set<int> inVars -- variables to include in new master
	 * OsiSolverInterface *si -- the current solver interface for 
	 * the master
	 */
	
	void resetMaster( std::map<int, int> &inVars, OsiSolverInterface *si );
	
	/**
	 *
	 * Default Constructor. 
	 */	
	OSRouteSolver();
	
	/**
	 *
	 * Second  Constructor. 
	 */	
	OSRouteSolver(OSOption* osoption);
	
	
	/** 
	 * Default Destructor
	 */
	
	~OSRouteSolver();
	

};//end class OSRouteSolver

#endif

