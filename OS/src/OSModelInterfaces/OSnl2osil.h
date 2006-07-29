/** @file OSnl2osil.h
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


#ifndef OSNL2OSIL_H
#define OSNL2OSIL_H



#include "OSInstance.h"
#include "OSnLNode.h"
#include "nlp.h"
#include <asl.h>
#include <string>



class OSnl2osil
{
public:
	OSnl2osil( std::string nlfilename);
	~OSnl2osil();
	bool createOSInstance();
	OSnLNode* walkTree(expr *e);
	OSInstance *osinstance;
private:
	ograd *og;
	ASL *asl;
	FILE *nl;
	char *stub;

};
#endif
