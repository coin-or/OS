/* $Id: OSStringUtil.cpp 3729 2010-10-18 12:25:22Z Gassmann $ */
/** @file OSStringUtil.cpp
 * 
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin, 
 *
 * \remarks
 * Copyright (C) 2005-2011, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, Dalhousie University and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */


#include "OSStringUtil.h"
#include "OSParameters.h" 
#include "OSBase64.h"
#include "OSMathUtil.h"


#include <sstream>  

//using std::cout;
//using std::endl;
using std::ostringstream; 


/**
 * writeStringData
 *
 * Prepare and output a string that may contain special characters (single or double quotes)
 *
 * @param str holds the string to be output. 
 * If the string does not contain double quotes, it is output surrounded by double quotes,
 * if the string contains double quotes, it is output surrounded by single quotes,
 * @return the prepared string, ready to be printed
 *
 */
std::string writeStringData(std::string str)
{
	ostringstream outStr;
	char quote;

	size_t iIndex = str.rfind("\"");
	if (iIndex == std::string::npos)
		quote = '\"';
	else
		quote = '\'';

	outStr << quote << str << quote;
	return outStr.str();
}



std::string makeStringFromInt(std::string theString, int theInt){
	ostringstream outStr;
	outStr << theString;
	outStr << theInt;
	return outStr.str();
}//end makeStringFromInt
