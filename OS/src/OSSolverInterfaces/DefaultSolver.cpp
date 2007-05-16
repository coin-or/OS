/** @file DefaultSolver.cpp
 * 
 * @author  Robert Fourer,  Jun Ma, Kipp Martin, 
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005, Robert Fourer, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */
 

#include "ErrorClass.h"
#include "DefaultSolver.h"

#include<iostream>
using std::cout;
using std::endl;

DefaultSolver::DefaultSolver():
	osinstance(NULL),
	osresult(NULL),
	osil(""),
	osol(""),
	osrl(""),
	m_sSolverName(""),
	insList("")
{ 


}

DefaultSolver::~DefaultSolver(){
	#ifdef DEBUG
	cout << "Default Solver destructor called" << endl;
	#endif
	//cout << "Start Default Solver Destructor" << endl;
	/* we do not delete osinstance since it is not newed in any
	 * of the solvers, it is newed elesewhere and deleted elsewhere
	 */
	//if(osinstance != NULL) delete osinstance;
	//osinstance = NULL;
	//if(osresult != NULL) delete osresult;
	//osresult = NULL;
}

