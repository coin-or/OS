/* $Id: OSColGenApp.cpp 3038 2009-11-07 11:43:44Z kmartin $ */
/** @file OSColGenApp.cpp
 * 
 * \remarks
 * Copyright (C) 2005-2008, Horand Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University,  Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */


#ifndef OSDECOMPPARAM_H
#define OSDECOMPPARAM_H


// --------------------------------------------------------------------- //
/*!
 * \class 
 * OSNode
 * 
 *
 */
// --------------------------------------------------------------------- //

class OSDecompParam {
	public:
	
	/** columnLimit is the limit on the number of columns that
	 * can be generated in a single call to solveRestrictedMasterRelaxation, 
	 * this number is different than the maximum number of columns
	 * allowed in the master
	 */
	int columnLimit;
	
	/** nodeLimit is the limit on the number of nodes that are
	 * allowed in the branch and bound tree
	 */
	int nodeLimit;
	
	/** when the number of columns in the master hits
	 * masterColumnResetValue do a column purge
	 */
	int masterColumnResetValue;
	
	/** we terminate column generation when the reduced costs are 
	 * not smaller than zeroTol
	 */
	double zeroTol;
	
	/** artVarCoeff is the coefficient of the artificial variable
	 * in the objective function
	 */
	double artVarCoeff;
	
	
	/** we fathom a node if UB*(1 - optTolPerCent) <= LB */
	double optTolPerCent;
	
	

	
	
};//end class OSDecompParam

#endif
