/* $Id: OSRouteSolver.h 3038 2009-11-07 11:43:44Z kmartin $ */
/** @file OSRouteSolver.h
 * 
 *
 * @author  Gus Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.0, 23/October/2010
 * @since   OS1.1
 *
 * \remarks
 * Copyright (C) 2005-2010, Gus Gassmann, Jun Ma, Kipp Martin,
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
	
	
	
	
	std::string m_initOSiLFile;
	std::map<int, std::map<int, std::vector<int> > > m_initSolMap;
	
	//variables for the q-route dynamic programming solution
	int m_numberOfVar;
	int m_numHubs;
	int m_numNodes;
	int m_routeCapacity;
	int m_minDemand;
	int* m_demand;
	
	/** the distance/cost vectors
	 */
	
	double** m_cost;
	
	/** the reduced cost vector
	 * we asssume order is (k, l, i, j)
	 */
	double* m_rc;
	/** dual vectors */
	/** the dual vector on convexity row
	 * see the paper for notation
	 */
	double* m_psi;
	/** the dual vector on node assignments row
	 * see the paper for notation
	 */
	double* m_phi;
	
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
	int m_upperBoundL;
	int m_numberOfSolutions;
	

	
	//these variable names are in x(i, j) space
	std::string* m_variableNames;
	
	//arrays for the coupling constraint matrix
	//we store indexes since values are 1.0
	int* m_pntAmatrix;
	int* m_Amatrix;
	//
	//arrays for the tour breaking contraints
	//
	int* m_pntBmatrix;
	int* m_Bmatrix;
	int* m_BmatrixRhs;
	int m_numTourBreakCon;
	int m_numTourBreakNonz;
	//
	
	//below  is a scatter array we scatter into in order
	//to multiply the transformation matrix times the A matrix
	int* m_tmpScatterArray;
	
	//arguments for getColumns
	double m_lowerBnd;
	int* m_nonzVec;
	double* m_costVec;
	
	int** m_newColumnRowIdx;
	double** m_newColumnRowValue;
	
	//the transformation matrix
	int* m_thetaPnt;
	int* m_thetaIndex;
	int m_numThetaVar;
	int m_numThetaNonz;
	double* m_thetaCost;


	double m_eps;
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
	//this method generates the instance for 
	//separating the tour breaking constraints
	OSInstance* getSeparationInstance();

	/** kipp -- document */
	// note -- this c vector is only for hub k
	double qrouteCost(const int& k, const int& l, const double* c, int* kountVar) ;
	
	//this c vector is for the entire cost vector
	void getOptL(const  double* c) ;
	
	//return true if cuts got generated
	bool getCuts(const  double* theta, const int numTheta) ;
	
	/**
	 * RETURN VALUES: 
	 * int numColumns -- number of new columns generated
	 * int* numNonz -- number of nonzeros in each column
	 * double* cost -- the objective function coefficient on each new column
	 * double* rcost -- the reduced cost of each new column
	 * double** rowIdx -- vectors row indexes of new columns
	 * double** values -- vectors of matrix coefficient values of new columns
	 * double lowerBound -- the lowerBound
	 * 
	 * INPUT:
	 * double* y -- the vector of dual values
	 * int numRows -- size of dual vector
	 */
	void getColumns(const  double* y, const int numRows,
			int &numColumns, int* numNonz, double* cost, double* rcost,
			int** rowIdx, double** values, double &lowerBound) ;
	
	
	void getOptions( OSOption *osoption);
	
	
	/** calculate the reduced costs
	 * c -- input of the objective function costs
	 * phi -- dual values on node assignment
	 * d -- reduced with convexity dual value
	 */
	void calcReducedCost( double** c, double* phi, double* d);
	
	//these are the variable in x(i, j) space
	void createVariableNames( );
	
	//this is the matrix that says we must visit each node
	//this A matrix defines the "coupling constraints"
	void createAmatrix();
	
	//this method gets called when we are done
	void pauHana(const double* theta);
	

	
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

