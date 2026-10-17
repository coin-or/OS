/* $Id: OSDefaultSolver.cpp 4943 2015-02-04 19:10:42Z Gassmann $ */
/** @file DefaultSolver.cpp
 *
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2015, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
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
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces,
                      ENUM_OUTPUT_LEVEL_debug, "Default Solver constructor called");
#endif
}

DefaultSolver::~DefaultSolver()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces,
                      ENUM_OUTPUT_LEVEL_debug, "Default Solver destructor called");
#endif
}

