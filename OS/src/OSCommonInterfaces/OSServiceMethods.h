/* $Id: OSServiceMethods.h 4403 2011-12-08 14:03:28Z Gassmann $ */
/** @file OSServiceMethods.h
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin,
 *
 * \remarks
 * Copyright (C) 2011, Horand Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University, Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */


#ifndef OSSERVICEMETHODS_H
#define OSSERVICEMETHODS_H

#include "OSCommandLine.h"
#include <string>


/*! \class OSServiceMethods
 *  \brief This class implements wrappers for the different service methods.
 *  By exposing the API these methods can be used by the OSAmplClient
 *  and OSSolverService executable as well as other third-party programs .
 *
 * @author Horand Gassmann, Jun Ma, Kipp Martin
 *
 */

class OSServiceMethods
{
public:
    /**  configFile is the name of the file that holds the configuration options
     * if the OSSolverService reads its options from a file rather than command
     * line inputs
     */
    std::string executeServiceMethod(OSCommandLine *oscommandline);
};
 #endif

/*  end header file */
