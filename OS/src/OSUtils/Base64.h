/** @file Base64.h
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


#ifndef BASE64_H
#define BASE64_H

#include<string>
using namespace std;

class Base64{
public:
	/**
	 * Constructor.
	 *
	 */
	Base64();
	~Base64();
	static string encodeb64(char* bytes, int size);
	static string decodeb64(char* b64bytes);
};//class Base64


#endif

