/* $Id$ */
/** @file DefaultSolver.cpp
 *
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 *
 * \remarks
 * Copyright (C) 2005-2011, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */

#include "OSOutput.h"
#include "OSErrorClass.h"
#include "OSDefaultSolver.h"

#include<iostream>

using std::cout;
using std::endl;

DefaultSolver::DefaultSolver():
    osil(""),
    osol(""),
    osrl(""),
    osinstance( NULL),
    osoption( NULL),
    osresult( NULL),
    sSolverName(""),
    bCallbuildSolverInstance( false),
    bSetSolverOptions( false)

{


}

DefaultSolver::~DefaultSolver()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, "Default Solver destructor called");
#endif
    /* we do not delete osinstance since it is not newed in any
     * of the solvers, it is newed elesewhere and deleted elsewhere
     */
    //if(osinstance != NULL) delete osinstance;
    //osinstance = NULL;
    //if(osresult != NULL) delete osresult;
    //osresult = NULL;
}

