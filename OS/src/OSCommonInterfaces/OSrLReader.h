/** @file OSrLReader.h
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
 
 
#ifndef OSRLREADER_H
#define OSRLREADER_H



#include "OSResult.h"
#include <iostream>




using std::ostream;


class OSrLReader{  

private:
	FILE *file;

public:
	OSrLReader( );
	~OSrLReader();
	OSResult *readOSrL(string osrl);
};
#endif
