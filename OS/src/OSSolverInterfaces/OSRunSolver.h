/* $Id: OSRunSolver.h 4263 2011-09-09 20:19:26Z Martin $ */
/** @file OSRunSolver.h
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin,
 *
 * \remarks
 * Copyright (C) 2005-2011, Horand Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University, Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */

#ifndef OSRUNSOLVER_H
#define OSRUNSOLVER_H

//std::string runSolver(std::string solverName, 
//		OSOption *osoption, OSInstance *osinstance);

std::string runSolver(std::string solverName, 
		std::string osol, OSInstance *osinstance);


#endif
