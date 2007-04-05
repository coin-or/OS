/** @file osssparservariables.h
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


 
#ifndef OSOPTIONSSTRUC_H
#define OSOPTIONSSTRUC_H


struct osOptionsStruc{
	char *configFile;
	char *osilFile;
	char *osil;
	char *osolFile;
	char *osol;
	char *osrlFile;
	char *osrl;
	char *insListFile;
	char *insList;
	char *serviceLocation;
	char *serviceMethod;
	bool os;
	char *osplInputFile;
	char *osplOutputFile;
	char *osplInput;
	char *osplOutput;
	char *mpsFile;
	char *nlFile;
	char *solverName;
	char *browser;
	bool osOption;
	
};


#endif

/*  end header file */ 
