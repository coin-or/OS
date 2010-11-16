/* $Id: OSgLParserData.cpp 3710 2010-10-04 03:39:42Z Gassmann $ */
/** @file OSgLParserData.cpp
 * 
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.0, 20/Oct/2010
 * @since   OS2.2
 *
 * \remarks
 * Copyright (C) 2005-2010, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, Dalhousie University and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */
#include "OSgLParserData.h" 
#include <stdio.h>

 OSgLParserData::~OSgLParserData() 
 {
	if (osglIntArray != NULL)
		delete[] osglIntArray;
	osglIntArray = NULL;
 }//~OSgLParserData
 

 OSgLParserData::OSgLParserData() :
	osglMultPresent(false),
	osglIncrPresent(false),
	osglNumberOfElPresent(false),
	osglNumberOfEl(-1),
	osglIntArray(NULL),
	osglMult(1),
	osglIncr(1),
	osglSize(0),
 	osglCounter(0),
	osglTempint(0)
{

 }//OSgLParserData
 
