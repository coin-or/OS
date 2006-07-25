/** @file FileUtil.cpp
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
 * <p>The <code>FileUtil</code> class contains methods for reading
 * and writing files from strings used by many classes in the
 * Optimization Services (OS) framework. </p>
 */

#include "FileUtil.h"

using namespace std;

FileUtil::FileUtil(){
} // end constructor


FileUtil::~FileUtil(){
} // end destructor

string FileUtil::getFileAsString(  char* fname){
	ostringstream outStr;
	char ch;
	ifstream inFile( fname);
	if(!inFile){
		cout << "Could not open file" << endl; 
		return "";
	}
	while((ch = inFile.get() ) != EOF){
		outStr << ch;
	}
	return outStr.str();
} // end getFileAsString



char* FileUtil::getFileAsChar(  char* fname){
	filebuf *pbuf;
	long bufsize = 0;
	char *xml;
	char ch;
	ifstream inFile;
	inFile.open( fname);
	// get the input file stream into the buffer
	pbuf = inFile.rdbuf();
	// now get the size
	bufsize = pbuf->pubseekoff(0,ios_base::end);
	// set back to zero
	pbuf ->pubseekpos(0, ios::in);
	// allocate the character array
	xml = new char[bufsize + 1];
	xml[ bufsize] =  '\0';
	bufsize = 0;
	while((ch = inFile.get()) != EOF ){
		xml[ bufsize] = ch;
		bufsize++;
	}
	return xml;
} // end getFileAsChar





bool FileUtil::writeFileFromString(char* fname, string sname){
	ofstream outFile;
	outFile.open( fname);
	if(!outFile.is_open()){
		return false;
	}
	outFile << sname;
	outFile.close();
	return true;
} // end writeFileFromString

bool FileUtil::writeFileFromChar(char* fname, char* ch){
	ofstream outFile;
	outFile.open( fname);
	if(!outFile.is_open()){
		return false;
	}
	outFile << *ch;
	outFile.close();
	return true;
} // end writeFileFromChar
 
