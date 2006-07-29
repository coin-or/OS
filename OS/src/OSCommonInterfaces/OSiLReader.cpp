/** @file OSiLReader.cpp
 * 
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

#include "OSiLReader.h"
#include "OSInstance.h"
#include "lexyaccparser.h" 
#include "ErrorClass.h"


OSiLReader::OSiLReader( ) {								
}

OSiLReader::~OSiLReader(){
	osilClearMemory();
} 

OSInstance* OSiLReader::readOSiL(std::string osil){   
	try{
		return yygetOSInstance( osil);
	}
		catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	}
}




