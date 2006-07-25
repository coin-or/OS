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
#include <stdlib.h>
#include "OSInstance.h"
using namespace std;
class OSmps2osil
{
public:
	OSmps2osil( string mpsfilename);
	~OSmps2osil();
	bool createOSInstance();
	OSInstance *osinstance;
private:
	CoinMpsIO *m_MpsData;
	CoinPackedMatrix *m_CoinPackedMatrix;
};
#endif

