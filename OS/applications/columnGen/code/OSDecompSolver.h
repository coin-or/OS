/* $Id: OSDecompSolver.h 3038 2009-11-07 11:43:44Z Gassmann $ */
/** @file OSDecompSolver.h
 * 
 * \remarks
 * Copyright (C) 2005-2008, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */

#ifndef OSDECOMPSOLVER_H
#define OSDECOMPSOLVER_H

// --------------------------------------------------------------------- //
#include "OSInstance.h"
#include "OSResult.h"
#include "OSDataStructures.h"
#include "OSErrorClass.h"
#include "OSOption.h"
#include "OSCoinSolver.h"
#include "OSDecompParam.h"
#include <vector>
#include <string>
#include <map>




// --------------------------------------------------------------------- //
/*!
 * \class 
 * OSBDecompSolver is a virtual class for solving the 
 *    Block subproblem
 * 
 *
 */
// --------------------------------------------------------------------- //
class OSDecompSolver{
public:
	

	OSInstance *m_osinstanceMaster;
	
	int m_multiCommodCutLimit;
	int m_numMultCuts;
	
	
	/** share the parameters with the 
	 * decomposition solver
	 */
	OSDecompParam m_osDecompParam;
	
	double m_bestIPValue;
	double m_bestLPValue;
	double m_rootLPValue;
	
	
	
	//the transformation matrix
	int* m_thetaPnt;
	int* m_thetaIndex;
	int m_numThetaVar;
	int m_numThetaNonz;
	
	
	//arrays for the added constraints
	//for now the added constraints are 
	//tour breaking and variable branching
	//constraints
	//
	int* m_pntBmatrix;
	//m_Bmatrix is the matrix of Xij indexes
	int* m_BmatrixIdx;  
	//m_Bmatrix is the matrix of Xij coefficients
	double* m_BmatrixVal;  
	
	
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
	
	
	
	//arrays for the coupling constraint matrix
	//we store indexes since values are 1.0
	//also the RHS is 1.0
	//the matrix has m_numNodes - m_numHubs rows
	int* m_pntAmatrix;
	//m_Amatrix holds the column indexes for each row
	int* m_Amatrix;
	//
	
	/** m_numBmatrixCon is the number of
	 * constraints in B - 1, we have the -1
	 * because:
	 * m_pntBmatrix[ k] points to the start of
	 * constraint k and m_pntBmatrix[ m_numBmatrixCon ]
	 * is equal to m_numBmatrixNonz
	 */
	int m_numBmatrixCon;   
	int m_numBmatrixNonz;
	
	
	/** m_maxBmatrixNonz is the maximum number of nonzero elements
	 * in the B matrix constraints 
	 */
	int m_maxBmatrixNonz;
	//
	//end arrays for added constaints
	
	
	/** m_maxBmatrixCon is the maximum number of B matrix constraints
	 * it is the number of tour breaking constraints plus variable 
	 * branch constraints
	 */
	int m_maxBmatrixCon;
	
	
	/** m_maxMasterColumns is the maximumn number
	 * of columns we allow in the master
	 */
	int m_maxMasterColumns;
	
	/** m_maxMasterColumns is the maximumn number
	 * of rows we allow in the master, in this
	 * application it is equal to m_maxBmatrixCon
	 * plus m_numNodes -- we therefore do not need
	 * to read this from an option file as we might
	 * for other problems
	 */
	int m_maxMasterRows;
	
	
	
	//these variable names are in the original variable space
	std::string* m_variableNames;
	
	
	OSOption *m_osoption;
	

	virtual OSInstance* getInitialRestrictedMaster( ) = 0;
	
	
	/**
	 * RETURN VALUES: 
	 * @param int numNewRows -- number of new rows generated
	 * @param int* numNonz -- number of nonzeros in each row
	 * @param int** colIdx -- vectors column indexes of new rows
	 * @param double** values -- vectors of matrix coefficient values of new rows
	 * @param double* rowLB -- vector of row lower bounds
	 * @param double* rowUB -- vector of row upper bounds
	 * 
	 * INPUT:
	 * @param double* thetaVar -- the vector of primal master values
	 * @param int numThetaVar -- size of master primal vector
	 */
	virtual void getCutsTheta(const  double* thetaVar, const int numThetaVar,
					  int &numNewRows, int*  &numNonz, int** &colIdx,
					  double** &values, double* &rowLB, double* &rowUB) = 0 ;	
	

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
	virtual void getCutsMultiCommod(const  double* thetaVar, const int numThetaVar,
			int &numNewRows, int*  &numNonz, int** &colIdx,
			double** &values, double* &rowLB, double* &rowUB) = 0;	
	
	
	
	
	/**
	 * RETURN VALUES: 
	 * @param iny numNewColumns -- number of new columns generated
	 * @param int* numNonz -- number of nonzeros in each column
	 * @param double* cost -- the objective function coefficient on each new column
	 * @param double** rowIdx -- vectors row indexes of new columns
	 * @param double** values -- vectors of matrix coefficient values of new columns
	 * @paramdouble lowerBound -- the lowerBound
	 * 
	 * INPUT:
	 * @param double* yA -- the vector of dual values on the coupling constraints
	 * @param int numARows -- size of the yA dual vector
	 * @paramdouble* yB -- the vector of dual values on the tour breaking constaints
	 * @param int numBRows -- size of the yA dual vector
	 */
	virtual void getColumns(const  double* yA, const int numARows,
					const  double* yB, const int numBRows,
					int &numNewColumns, int* &numNonz, double* &cost, 
					int** &rowIdx, double** &values, double &lowerBound)  = 0;
	
	
	
	/**
	 *
	 * Dense Version
	 *
	 * RETURN VALUES: 
	 * @param varIdx -- the variable number x_{ij} for branching
	 * @param numNonz -- number of theta indexes in the cut
	 * @param indexes -- the indexes of the theta variables
	 * @param values -- the number of times the theta indexed 
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
				int* &indexes,  double* &values) = 0 ;	
	
	
	
	/**
	 * 
	 * Sparse Version
	 * 
	 * RETURN VALUES: 
	 * @param varIdx -- the variable number x_{ij} for branching
	 * @paramnum Nonz -- number of theta indexes in the cut
	 * @param indexes -- the indexes of the theta variables
	 * @param values -- the number of times the theta indexed 
	 * in indexes appears in the cut 
	 * note -- set numNonz to zero if the generated cut
	 * variable already appears in varConMap
	 * 
	 * 
	 * INPUT:
	 * @param double* theta -- the vector of primal master values
	 * @param  int numThetaVar -- size of master primal vector
	 * @paramvarConMap -- the map of variables in x_{ij} space to 
	 * a consraint number
	 * 
	 */
	virtual void getBranchingCut(const int* thetaIdx, const double* theta, 
				const int numThetaVar, const std::map<int, int> &varConMap, 
				int &varIdx,  int &numNonz, int* &indexes, double* &values) = 0 ;
	

	
	
	
	//this method gets called when we are done
	virtual void pauHana(std::vector<int> &m_zOptIndexes, 
			std::vector<double> &m_zRootLPx_vals,
			int numNodes, int numColsGen, std::string message) = 0;
	
	

	/**
	 * 
	 * INPUT: 
	 * @param dstd::map<int, int> &inVars -- the mapping of variables, the first
	 * index is the variable number before resetting, the second index is the variable
	 * number after the reset
	 * @param OsiSolverInterface *si -- the solver interface that corresponds to the master
	 * this is what gets rebuilt
	 *
	 */
	virtual void resetMaster(std::map<int, int> &inVars, OsiSolverInterface *si ) = 0;
	
	
	
	/** allocate memory and initialize
	 * arrays
	 */
	virtual void initializeDataStructures() = 0;
	
	
	/**
	 *
	 * Default Constructor. 
	 */	
	OSDecompSolver();
	
	/**
	 *
	 * Constructor with OSOption Arg 
	 */	
	OSDecompSolver( OSOption* osoption);
		
	
	/**
	 *
	 * Default destructor. 
	 */	
	virtual ~OSDecompSolver() = 0;	
	

	
	//
};//end class OSDecompSolver



#endif
