/** @file OSmps2osil.h
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



#ifndef OSMPS2OSIL_H
#define OSMPS2OSIL_H


#include <CoinMpsIO.hpp>
#include <CoinPackedMatrix.hpp>
#include <string>
#include "OSInstance.h"
class OSmps2osil
{
public:
	/** the OSmps2osil class constructor */
	OSmps2osil( std::string mpsfilename);
	
	/** the OSmps2osil class deconstructor */
	~OSmps2osil();

   	/**
   	 * create an OSInstance from the MPS instance representation
   	 * 
   	 * @return whether the variable is added successfully. 
   	 */
	bool createOSInstance();
	
	/** osinstance is a pointer to the OSInstance object that gets
	 * created from the instance represented in MPS format
	 */
	OSInstance *osinstance;
private:
	/** m_MpsData is a pointer to a CoinMpsIO object */
	CoinMpsIO *m_MpsData;
	/**  m_CoinPackedMatrix is a pointer to a CoinPackedMatrix object */
	CoinPackedMatrix *m_CoinPackedMatrix;
};
#endif

