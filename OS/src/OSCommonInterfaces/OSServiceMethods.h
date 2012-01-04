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
	/** the string containing the output generated 
	 *  by the service method called via executeServiceMethod()
	 *
	 */
	std::string resultString;

	/** default constructor
	 */
	OSServiceMethods();

	/** default destructor
	 */
	~OSServiceMethods();

	/** nonstandard constructor
	 *  This version can be used to process the information contained in
	 *  the command line (reading of files, preparation of instance, etc.)
	 *  @param oscommandline holds the command line information
	 *  and location of the instance, options, etc.
	 */
	OSServiceMethods(OSCommandLine *oscommandline);

    /** executeServiceMethod is a wrapper around the six service methods 
	 *  implemented in OS: solve, send, retrieve, knock, kill, getJobID
	 *  @param oscommandline holds the command line information
	 *  and location of the instance, options, etc.
	 */
    bool executeServiceMethod(OSCommandLine *oscommandline);

	/**
	 *  print help
	 */
	std::string get_help();
};
 #endif

/*  end header file */
