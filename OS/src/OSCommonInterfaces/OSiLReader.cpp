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



OSiLReader::OSiLReader( ) {								
}

OSiLReader::~OSiLReader(){
	delete osinstance;
	osinstance = NULL;
} 

OSInstance* OSiLReader::readOSiL(std::string *posil) throw(ErrorClass){   
	try{
		//OSInstance* p;
		//std::string *pstring;
		//pstring = new std::string( osil);
		const char *ch = posil->c_str();
		//cout << "HERE IS THE PROBLEM TO PARSE: " << ch << endl;
		osinstance = yygetOSInstance( ch);
		//p = yygetOSInstance( ch);
		//std::string *pstring;
		//pstring = new std::string("This is a test");
		//const char *ch = pstring->c_str();
		//char *ch2;
      	//ch2 = new char[pstring->size() + 1];
      	//strcpy(ch2, pstring->c_str());
		//ch++;
		//ch2[2] = 'K';
		//std::cout << ch << std::endl;
		//std::cout << ch2 << std::endl;
		return osinstance;
	}
		catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	}
}




