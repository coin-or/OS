/* $Id: OSColGenApp.h 3038 2009-11-07 11:43:44Z kmartin $ */
/** @file OSBlockBearcatSolver.h
 * 
 *
 * @author  Gus Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.0, 21/July/2008
 * @since   OS1.1
 *
 * \remarks
 * Copyright (C) 2005-2008, Gus Gassmann, Jun Ma, Kipp Martin,
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

#include "OSRouteSolver.h"


#include<map>
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
	

	OSInstance *m_osinstanceMaster;
	OSOption *m_osoption;
	OSResult *m_osresult;
	
	OSRouteSolver *m_osrouteSolver;
	
	
	/** kipp -- document */
	void solveRestrictedMasterRelaxation();
	
	void getInitialRestrictedMaster( );
	
	void getOptions( OSOption *osoption);
	
	void getCuts(const  double* x) ;
	
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

