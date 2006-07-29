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



class OSiLReader{  

private:
	FILE *file;

public:
	OSiLReader( );
	~OSiLReader();
	OSInstance* readOSiL(std::string osil) throw(ErrorClass);
};
#endif
