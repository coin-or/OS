/** @file FileUtil.h
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
 
#ifndef FILEUTIL_H
#define FILEUTIL_H

/**
 * \class FileUtil
 * <p>The <code>FileUtil</code> class contains methods for reading
 * and writing files from strings used by many classes in the
 * Optimization Services (OS) framework. </p>
 *
 */
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;
class FileUtil{
public:
	public:
	/**
	 * Constructor.
	 *
	 */
	FileUtil();
	~FileUtil();
	string getFileAsString(  char* fname);
	char* getFileAsChar(  char* fname);
	bool writeFileFromString(char* fname, string thestring);
	bool writeFileFromChar(char* fname, char* ch);

	
	
};//class MathUtil
#endif
