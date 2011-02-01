/* $Id: OSDecompSolver.h 3038 2009-11-07 11:43:44Z Gassmann $ */
/** @file OSDecompSolver.h
 * 
 * \remarks
 * Copyright (C) 2005-2008, Gus Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University,  Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
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
	


	virtual OSInstance* getInitialRestrictedMaster( ) = 0;
	
	
	/**
	 * RETURN VALUES: 
	 * @paramint numNewRows -- number of new rows generated
	 * @param int* numNonz -- number of nonzeros in each row
	 * @param double** colIdx -- vectors column indexes of new rows
	 * @param double** values -- vectors of matrix coefficient values of new rows
	 * @param double* rowLB -- vector of row lower bounds
	 * @paramdouble* rowUB -- vector of row upper bounds
	 * 
	 * INPUT:
	 * @param double* thetaVar -- the vector of primal master values
	 * @param int numThetaVar -- size of master primal vector
	 */
	virtual void getCuts(const  double* thetaVar, const int numThetaVar,
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
	 * INPUT: -- sparse version
	 * @param int* thetaIdx -- index vector of nonzero theta variables 
	 * @param double* theta -- the sparse vector of primal master values
	 * @param int numThetaVar -- size of master primal vector
	 * @param std::map<int, int> varConMap -- the variable constraint map
	 * 
	 * RETURN:
	 * 
	 * rowIdx is the row index of the row used for branching
	 * 
	 */
	virtual void createBranchingCut(const int* thetaIdx, const double* theta, 
							const int numThetaVar, std::map<int, int> &varConMap, int &rowIdx) = 0;
	
	
	/**
	 * 
	 * INPUT: -- dense version
	 * @param double* theta -- the dense vector of primal master values
	 * @param int numThetaVar -- size of master primal vector
	 * @param std::map<int, int> varConMap -- the variable constraint map
	 * 
	 * RETURN:
	 * 
	 * @param rowIdx is the row index of the row used for branching
	 * 
	 */
	virtual void createBranchingCut(const double* theta, const int numThetaVar, 
						std::map<int, int> &varConMap, int &rowIdx) = 0;
	
	

	
	
	
	//this method gets called when we are done
	virtual void pauHana(std::vector<int> &m_zOptIndexes , int numNodes,
				 int numColsGen) = 0;
	
	
		virtual void resetMaster( ) = 0;
	
	
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
