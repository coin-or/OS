/** @file OSrLReader.cpp
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

#include "OSrLReader.h"
#include "OSResult.h"
#include "lexyaccparser.h"   
//#include <iostream> 
//#include <sstream>
#include "ErrorClass.h" 



OSrLReader::OSrLReader( ) {								
}

OSrLReader::~OSrLReader(){
	osrlClearMemory();
} 

OSResult* OSrLReader::readOSrL(string osrl){   
	try{
		return yygetOSResult( osrl);
	}
		catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg); 
	}
}




