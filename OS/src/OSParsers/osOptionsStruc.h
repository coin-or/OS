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
	std::string configFile;
	std::string osilFile;
	std::string osil;
	std::string osolFile;
	std::string osol;
	std::string osrlFile;
	std::string  osrl;
	std::string insListFile;
	std::string insList;
	std::string serviceLocation;
	std::string serviceMethod;
	bool os;
	std::string osplInputFile;
	std::string osplOutputFile;
	std::string osplInput;
	std::string osplOutput;
	std::string mpsFile;
	std::string nlFile;
	std::string solverName;
	std::string browser;
	bool osOption;
};


#endif

/*  end header file */ 
