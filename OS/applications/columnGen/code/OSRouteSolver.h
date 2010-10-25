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
	
	
	std::string* m_variableNames;
	
	//arrays for the coupling constraint matrix
	int* m_pntAmatrix;
	int* m_Amatrix;
	
	int* m_tmpVarArray;
	
	
	//kipp get rid of this and replace with a local
	double m_trueMin;
	
	OSInstance *m_osinstanceMaster;

	OSInstance* getInitialRestrictedMaster( );

	/** kipp -- document */
	// note -- this c vector is only for hub k
	double qrouteCost(const int& k, const int& l, const double* c, int* kountVar) ;
	
	//this c vector is for the entire cost vector
	void getOptL(const  double* c) ;
	
	
	void getCuts(const  double* x) ;
	
	//y is a pointer to the dual vars
	void getColumns( const double* y,  const int numRows ) ;
	
	
	void getOptions( OSOption *osoption);
	
	
	/** calculate the reduced costs
	 * c -- input of the objective function costs
	 * phi -- dual values on node assignment
	 * d -- reduced with convexity dual value
	 */
	void calcReducedCost( double** c, double* phi, double* d);
	
	
	void createVariableNames( );
	
	//this is the matrix that says we must visit each node
	void createAmatrix();
	
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

