/** @file OSiLReader.h
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
 
 
#ifndef OSILREADER_H
#define OSILREADER_H



#include "OSInstance.h"
#include "OSiLWriter.h"
#include "ErrorClass.h"

#include <string>


/*! \class OSiLReader
 *  \brief Used to read an OSiL string.
 *
 * \remarks 
 * <p> This class wraps around the OSiL parser and sends
 * the parser an OSiL string and is returned an OSInstance
 * object. </p>
 */
class OSiLReader{  

public:

	/**
	 * Default constructor. 
	 */
	OSiLReader( );
	
	/**
	 * Class destructor. 
	 */	
	~OSiLReader();
	
   	/**
   	 * parse the OSiL model instance.
   	 * 
   	 * <p>
   	 * @param osil a string that holds the problem instance. 
   	 * @return the instance as an OSInstance object.
	 * </p> 
   	 */	
	OSInstance* readOSiL(std::string *osil) throw(ErrorClass);

private:
	/** osintance is the OSInstance object returned by 
	 * the OSiLReader
	 */
	OSInstance *m_osinstance;
};



#endif
