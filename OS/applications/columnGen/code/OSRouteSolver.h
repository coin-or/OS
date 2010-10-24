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
	
	/** the distance/cost vectors */
	double** m_cost;
	

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
	int m_totalDemand;
	
	int m_upperBoundL;
	int m_numberOfSolutions;
	
	
	//kipp get rid of this
	int m_whichBlock;
	double m_trueMin;

	OSInstance* getInitialRestrictedMaster( );

	/** kipp -- document */
	// note -- this c vector is only for hub k
	double qrouteCost(const int& k, const int& l, const double* c, int* kountVar) ;
	
	//this c vector is for the entire cost vector
	void getOptL(const  double* c) ;
	
	
	//this c vector is for the entire cost vector
	void getColumns(const  double* c) ;
	
	
	void getOptions( OSOption *osoption);
	
	
	
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

