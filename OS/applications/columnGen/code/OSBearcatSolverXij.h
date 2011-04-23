/* $Id: OSBearcatSolverXij.h 3038 2009-11-07 11:43:44Z kmartin $ */
/** @file OSBearcatSolverXij.h
 * 
 * \remarks
 * Copyright (C) 2005-2010, Horand Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University,  Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */

#ifndef OSBEARCATSOLVERXIJ_H
#define OSBEARCATSOLVERXIJ_H

#include "OSDecompSolver.h"
#include "OSDecompSolverFactory.h"
#include "OSInstance.h"
#include "OSOption.h"
#include "ClpSimplex.hpp"
#include "OSCoinSolver.h"
#include<map>
// --------------------------------------------------------------------- //
/*!
 * \class 
 * OSBearcatSolverXij
 * 
 *
 */
// --------------------------------------------------------------------- //
class OSBearcatSolverXij : public OSDecompSolver {
public:
	
	


/***************** Bearcat Specific Solver Parameters ***********************/
	//kipp move to the method
	std::map<int, std::string> m_tmpVarMap;
	
	/** m_xVarIndexMap takes a variable indexed by (i,j)
	 * and returns the index of the variable in one dimension
	 */
	std::map<std::pair<int, int>,int>m_xVarIndexMap;
	
	
	std::string m_initOSiLFile;
	
	/** the index on the outer map is on the solution number,
	 * the index on the inner map indexes the route number, 
	 * the vector is the list of nodes assigned to that route
	 */
	std::map<int, std::map<int, std::vector<int> > > m_initSolMap;
	
	/** m_multCommodCutSolvers is a vector of solvers, one
	 * solver for each hub, used to find multicommodity flow
	 * cuts for the given hub
	 */
	std::vector<CoinSolver*> m_multCommodCutSolvers;
	
	/** if m_use1OPTstart is true we use the option file to
	 * fix the nodes to hubs found by SK's 1OPT heuristic
	 */
	bool m_use1OPTstart;
	
	/** m_maxMasterNonz is the maximumn number
	 * of nonzero elements we allow in the transformation matrix
	 * betwee the theta variables and the xij variables
	 */
	int m_maxThetaNonz;
	


	
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
	
	/** m_nodeName is the vector of node names */
	string* m_nodeName;
	
	/** the distance/cost vectors */
	double* m_cost;

	/** m_costSetInOption is true if the costs are set
	 * using the OSOption file
	 */
	bool m_costSetInOption;
	
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
		

	

	
	//kipp -- be carefull does m_thetaCost have
	// artificial variables -- it is 
	double* m_thetaCost;
	
	/** m_convexityRowIndex holds the index of the convexity row
	 * that the theta columns are in. If the theta is an artificial
	 * variable this value is -1
	 */
	int* m_convexityRowIndex;
	
	
	/** m_BmatrixRowIndex holds the index of the convexity row
	 * that the constraint corresponds to, this is for the
	 * multicommodity constraints --  if the constraint applies
	 * to theta regardless of k, then the value is -1
	 */
	int* m_BmatrixRowIndex;
	

	 /** m_separationIndexMap maps the variable index into the
	  * appropriate row in the separation problem for the 
	  * tour breaking constraints
	  */
	int* m_separationIndexMap;
	
	//
	OSInstance *m_osinstanceSeparation;
	
	//the Clp model 
	ClpSimplex*  m_separationClpModel;

	//create the initial restricted master
	virtual OSInstance* getInitialRestrictedMaster( );

	
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
	virtual void getBranchingCut(const double* thetaVar, const int numThetaVar,
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
	virtual void getBranchingCut(const int* thetaIdx, const double* theta, 
			const int numThetaVar, const std::map<int, int> &varConMap, 
			int &varIdx,  int &numNonz, int* &indexes, double* &values) ;
	
	
	
	/**
	 * This is the routine that generates the multi-item cuts.
	 * 
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
	void getCutsMultiCommod(const  double* thetaVar, const int numThetaVar,
			int &numNewRows, int*  &numNonz, int** &colIdx,
			double** &values, double* &rowLB, double* &rowUB) ;	
	
	
	
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
	virtual void getColumns(const  double* yA, const int numARows,
			const  double* yB, const int numBRows,
			int &numNewColumns, int*  &numNonz, double* &cost, 
			int** &rowIdx, double** &values, double &lowerBound) ;
	
	

	
	
	void getOptions( OSOption *osoption);
	
	/** this method will populate: 
	 * std::map<std::pair<int, int>,int>m_xVarIndexMap
	 * this gives us
	 * 
	 */
	void getVariableIndexMap();
	
	
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
	virtual void initializeDataStructures();
	
	/** generate an intitial feasible solution
	 * in theta space for the initial master
	 */
	void getInitialSolution();
		
	virtual void resetMaster( std::map<int, int> &inVars, 
			OsiSolverInterface *si );
	
	
	/** call this method to get a minimum TSP tour for
	 * a given assignment of nodes to routes
	 * INPUT:
	 * int numNodes -- number of cities/nodes in tour
	 * int hubIndex -- indexes the hub index
	 * CoinSolver* solver -- the coin solver
	 * numNodes*numNodes - numNodes entries, we are assuming
	 * zk -- indexes the non-hub nodes assigned this route
	 * asymmetric
	 * 
	 * OUTPUT:
	 * xVar the optimal solution
	 * 
	 */
	double getRouteDistance(int numNodes, int hubIndex, 
			CoinSolver* solver, std::vector<int> zk, 
			double* xVar);
	
	
	/** call this method to get a TSP instance
	 * 
	 * INPUT:
	 * int numNodes -- number of cities/nodes in tour
	 * double* cost -- the cost vector, this should have
	 * 
	 * RETURN:
	 * pointer to a CoinSolver with a TSP instance
	 * 
	 */
	CoinSolver* getTSP(int numNodes, double* cost);	
	
	
	
	/** call this method to get an instance that is
	 * used to generate a multicommodity cut
	 * 
	 * INPUT:
	 * 	hubIndex is the index associated with the hub for which
	 * we are looking for a cut
	 * RETURN:
	 * pointer to a CoinSolver with a cut generator instance
	 * 
	 */
	CoinSolver* getMultiCommodInstance(int hubIndex);
	
	
	/** call this method to get generate an instance
	 * of the generalized assignment problem and find
	 * a feasible solution to the problem
	 * 
	 * INPUT:
	 * 
	 * RETURN:
	 * void
	 * 
	 */
	void getFeasibleSolution();
	
	
	/** 
	 * try and find a feasible solution, return false
	 * if solution not feasible
	 * 
	 */
	bool OneOPT();	
	
		
	//this method gets called when we are done
	virtual void pauHana(std::vector<int> &m_zOptIndexes , int numNodes,
			int numColsGen);
	
	
	/**
	 *
	 * Default Constructor. 
	 */	
	OSBearcatSolverXij();
	
	/**
	 *
	 * Second  Constructor. 
	 */	
	OSBearcatSolverXij(OSOption* osoption);
	
	
	/** 
	 * Default Destructor
	 */
	
	~OSBearcatSolverXij();
	
	
	class Factory;
	class Factory : public OSDecompSolverFactory{
		
	public:
		
		Factory(){
			
		}
		
		~Factory(){
			
		}
		
		OSDecompSolver* create() {  return new OSBearcatSolverXij(  osoption); };
		
	};// end class OSDecompSolverFactory
	

};//end class OSBearcatSolverXij

#endif

