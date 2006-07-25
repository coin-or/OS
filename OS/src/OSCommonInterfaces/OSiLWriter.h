/** @file OSiLWriter.h
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


#ifndef OSiLWRITER_H
#define OSiLWRITER_H



#include <iostream>
using std::ostream;
#include "OSInstance.h"

/*! \class OSiLWriter OSiLWriter.h "OSiLWriter.h"
 *  \brief Take an OSInstance object and write a string that validates against OSiL..
 *
 * 
 */
class OSiLWriter{  
private:
	/** 
	 * m_cOSInstance is an object in the class OSInstance
	 */
	OSInstance *m_OSInstance;
public:

	/**
	 *
	 * Default constructor. 
	 */
	OSiLWriter( );

	/**
	 *
	 * Class destructor. 
	 */	
	~OSiLWriter();

   	/**
   	 * create an osil string from an OSInstance object
   	 * <p>
   	 * @param theosinstance is a pointer to an OSInstance object 
   	 * @return a string with the OSInstance data that validates against the OSiL schema.
	 * </p> 
   	 */		
	string writeOSiL( OSInstance *theosinstance);

	/** m_bWriteBase64 is set to true if we encode the linear constraint coefficients
	 * in base64 binary
	 */
	bool m_bWriteBase64;
	
	/** m_bWhiteSpace is set to true if we write white space in the file
	 */
	bool m_bWhiteSpace;

	/** m_sB64encoded is a string of data (start, colIdx, rowIdx, or values) from
	 * linear constraints coefficients encoded in base64 binary
	 */	
	string m_sB64encoded;
};
#endif
