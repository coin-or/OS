/* $Id: OSNode.h 3038 2009-11-07 11:43:44Z kmartin $ */
/** @file OSNode.h
 *
 * \remarks
 * Copyright (C) 2005-2010, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */

#ifndef OSNODE_H
#define OSNODE_H

#include <vector>
#include <set>

// --------------------------------------------------------------------- //
/*!
 * \class 
 * OSNode
 * 
 *
 */
// --------------------------------------------------------------------- //

class OSNode {
	public:
	
	/** parentID is the node ID of the parent
	 * 
	 */
	int parentID;
	
	/** nodeID is the node ID 
	 * 
	 */
	int nodeID;
	
	/** rowIdxNumNonz is the number of non-zero elements in rowIndex */
	int rowIdxNumNonz;
	
	/** rowIdx is a vector of row indexes for which we are setting
	 * the upper and lower bounds
	 */
	int* rowIdx;
	
	/** rowUB is a vector of row upper bounds */
	double* rowUB;
	
	/** rowLB is a vector of row lower bounds */
	double* rowLB;
	
	/** lpValue is the LP relaxation for the node */
	double lpValue;
	
	/** thetaNumNonz is the number of non-zero elements in the
	 * theta variable solution at this node */
	int thetaNumNonz;
	
	/** theta is an array of primal solution
	 * variable indexes
	 */
	int* thetaIdx;
	
	/** theta is an array of primal positive values
	 * this is used for branching and creating new
	 * children nodes
	 */
	double* theta;
	
	/** colBasisStatus is vector of integer pairs, for 
	 * each element of the vector we store the pair
	 * (index, status) where status is:
	 * basis code:
	 *     <ul>
      <li> 0: free
      <li> 1: basic
      <li> 2: nonbasic at upper bound
      <li> 3: nonbasic at lower bound
    </ul>
	 */
	std::vector<std::pair<int, int> >  colBasisStatus;
	
	/** rowBasisStatus is the vector of pairs for rows
	 */
	std::vector<std::pair<int, int> >  rowBasisStatus;
	
	/** reducedCostVec will hold variables within a tolerance
	 * on their reduced costs. 
	 */
	std::set<int>  reducedCostIdx;
	
	
	/**
	 *
	 * Default Constructor. 
	 */	
	OSNode();
	
	/**
	 *
	 * Constructor for allocating arrays 
	 */	
	OSNode(int rowIdxNumNonz_, int thetaNumNonz_ );
	

	/**
	 *
	 * Default destructor. 
	 */	
	~OSNode();	
	
	
	
};//end class OSNode

#endif
