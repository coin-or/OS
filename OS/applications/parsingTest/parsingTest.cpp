/* $Id: parsingTest.cpp 3583 2010-07-13 20:39:42Z kmartin $ */
/** @file parsingTest.cpp
 * 
 * \brief This file tests the validity of an OSiL, OSoL or OSrL file.  
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.0, 18/Sep/2010
 * @since   OS2.2
 *
 * \remarks
 * Copyright (C) 2010, Horand Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University, Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 * 
 */ 

#include <cppad/cppad.hpp> 
#include "OSConfig.h"
#include "OSInstance.h"  
//#include "OSOption.h"
#include "OSResult.h" 
#include "OSiLReader.h"        
#include "OSiLWriter.h"        
//#include "OSoLReader.h"        
//#include "OSoLWriter.h"        
#include "OSrLReader.h"          
#include "OSrLWriter.h"        
#include "OSFileUtil.h"  
#include "CoinError.hpp"

#include "OSWSUtil.h" 
#include "OShL.h"     
#include "OSErrorClass.h"
#include "OSBase64.h"
#include "OSMathUtil.h"


#include <CoinMpsIO.hpp>
#include <CoinPackedMatrix.hpp>


#include "CoinError.hpp"
#include "CoinHelperFunctions.hpp"

#ifdef HAVE_CTIME
# include <ctime>
#else
# ifdef HAVE_TIME_H
#  include <time.h>
# else
#  error "don't have header file for time"
# endif
#endif


#ifdef HAVE_CMATH
# include <cmath>
#else
# ifdef HAVE_CMATH_H
#  include <cmath.h>
# endif
#endif



#ifdef HAVE_CSTDIO
# include <cstdio>
#else
# ifdef HAVE_STDIO_H
#  include <stdio.h>
# else
#  error "don't have header file for stdio"
# endif
#endif

//#ifdef HAVE_WINDOWS_H
//#include <windows.h>
//#endif

using std::cout;   
using std::endl;
using std::ostringstream; 

//#define MY_DEBUG

bool interactiveShell(std::string *schema, std::string *testFileName, std::string *outFileName,
					  bool *compress, bool *addWhiteSpace, bool *verifyObjects);
void printHelp();
std::string getUserInput(bool defaultPresent);


int main(int argC, char* argV[])
{
	WindowsErrorPopupBlocker();

	// define the classes
	FileUtil *fileUtil = NULL;  
	OSiLReader *osilreader = NULL;
//	OSoLReader *osolreader = NULL;
	OSrLReader *osrlreader = NULL;
	// end classes    

	std::string testFileName;
	std::string outFileName;
	std::string osxl;
	std::string schema;
	ostringstream parsingTestResult;
	ostringstream parsingTestResultFailure;
//	ostringstream outputString;
	std::string outputString;

	bool ok;
	bool doOutput = false;
	bool compress = true;
	bool addWhiteSpace = true;
	bool verifyObjects = false;
	double check;
	
//	Command line parser and user interface

	if (argC == 1)
	{
		if (interactiveShell(&schema, &testFileName, &outFileName, &compress, &addWhiteSpace, &verifyObjects) != true) return 0;

		if (outFileName != "") doOutput = true;

#ifdef MY_DEBUG
			std::cout << "User dialog completed " << std::endl;
#endif
	}
	else
	{
		if( argC > 7)
		{
			std::cout << "Too Many Input Parameters" << std::endl;
			return 1;
		}
		if ( (strcmp(argV[1],"--help") == 0) || (strcmp(argV[1],"-h") == 0) || (strcmp(argV[1],"-?") == 0) )
		{
			printHelp();
			return 0;
		}
		if ( (strcmp(argV[1],"quit") == 0) || (strcmp(argV[1],"exit") == 0) || (strcmp(argV[1],"stop") == 0) )
			return 0;
		if (argC < 3 || ((strcmp(argV[1],"osil") != 0) && (strcmp(argV[1],"osol") != 0) && (strcmp(argV[1],"osrl") != 0)))
		{
			std::cout << "usage: parsingtest <parser> <filename> [<outputFile> [(no)compress (no)addWhiteSpace (noverify]]" << std::endl;
			std::cout << "type \"parsingtest --help\" for more information" << std::endl;
			return 1;
		}
		schema = argV[1];
		testFileName =  argV[2];
		if (argC > 3)
		{
			outFileName = argV[3];
			doOutput = true;
		}
		if (argC > 4)
			compress = (strcmp(argV[4],"nocompress") != 0); 
		if (argC > 5)
			addWhiteSpace = (strcmp(argV[5],"noaddwhitespace") != 0); 
		if (argC == 7)
			verifyObjects = (strcmp(argV[6],"verifyobjects") == 0); 
	}

	fileUtil = new FileUtil();

	try
	{

#ifdef MY_DEBUG
		std::cout << "Processing file: " ;
		std::cout <<  testFileName << std::endl;
#endif

		osxl = fileUtil->getFileAsString( testFileName.c_str() );

#ifdef MY_DEBUG
		std::cout << "Done reading the file" << std::endl;
#endif

		if (schema == "osil")
		{
			osilreader = new OSiLReader(); 
			OSInstance *osinstance;
			osinstance = osilreader->readOSiL( osxl);

#ifdef MY_DEBUG
			parsingTestResult << "Reading files successfully" << std::endl;
#endif

			if (doOutput == true)
			{
				OSiLWriter *osilwriter;
				osilwriter = new OSiLWriter();
				osilwriter->m_bWriteBase64 = compress;
				osilwriter->m_bWhiteSpace  = addWhiteSpace;
#ifdef MY_DEBUG
				std::cout << "Create  output string from in-memory object" << std::endl;
#endif
				outputString = osilwriter->writeOSiL(osinstance);
#ifdef MY_DEBUG
				std::cout << "Created output string from in-memory object" << std::endl;
#endif
				if (fileUtil->writeFileFromString( outFileName.c_str(), outputString) != true)
					throw ErrorClass(" Error while writing compressed file");

				if (verifyObjects == true)
				{
					osxl = fileUtil->getFileAsString( outFileName.c_str() );
					OSInstance *osinstance2;
					osinstance2 = osilreader->readOSiL( osxl);
					if (osinstance2->IsEqual(osinstance) == false)
						throw ErrorClass("Two objects are not equal!");
				}

				delete osilwriter;
				osilwriter = NULL;
			}
			delete osilreader;
			osilreader = NULL;
		}
		else if (schema == "osol")
		{
/*
			osolreader = new OSoLReader(); 
			OSOption *osoption;
			osoption = osolreader->readOSoL( osxl);

#ifdef MY_DEBUG
			parsingTestResult << "Reading files successfully" << std::endl;
#endif

			if (doOutput == true)
			{
				OSoLWriter *osolwriter;
				osolwriter = new OSoLWriter();
				osolwriter->m_bWriteBase64 = compress;
				osolwriter->m_bWhiteSpace  = addWhiteSpace;
#ifdef MY_DEBUG
				std::cout << "Create  output string from in-memory object" << std::endl;
#endif
				outputString = osolwriter->writeOSoL(osoption);
#ifdef MY_DEBUG
				std::cout << "Created output string from in-memory object" << std::endl;
#endif
				if (fileUtil->writeFileFromString( outFileName.c_str(), outputString) != true)
					throw ErrorClass(" Error while writing compressed file");

				if (verifyObjects == true)
				{
					osxl = fileUtil->getFileAsString( outFileName.c_str() );
					OSOption *osoption2;
					osoption2 = osolreader->readOSoL( osxl);
					if (osoption2->IsEqual(osoption) == false)
						throw ErrorClass("Two objects are not equal!");
				}

				delete osolwriter;
				osolwriter = NULL;
			}
			delete osolreader;
			osolreader = NULL;
*/		}
		else if (schema == "osrl")
		{
			osrlreader = new OSrLReader(); 
			OSResult *osresult;
			osresult = osrlreader->readOSrL( osxl);

#ifdef MY_DEBUG
			parsingTestResult << "Reading files successfully" << std::endl;
#endif

			if (doOutput == true)
			{
				OSrLWriter *osrlwriter;
				osrlwriter = new OSrLWriter();
				osrlwriter->m_bWriteBase64 = compress;
				osrlwriter->m_bWhiteSpace  = addWhiteSpace;
#ifdef MY_DEBUG
				std::cout << "Create  output string from in-memory object" << std::endl;
#endif
				outputString = osrlwriter->writeOSrL(osresult);
#ifdef MY_DEBUG
				std::cout << "Created output string from in-memory object" << std::endl;
#endif
				if (fileUtil->writeFileFromString( outFileName.c_str(), outputString) != true)
					throw ErrorClass(" Error while writing compressed file");

				if (verifyObjects == true)
				{
					osxl = fileUtil->getFileAsString( outFileName.c_str() );
					OSrLReader *osrlreader2;
					osrlreader2 = new OSrLReader(); 
					OSResult *osresult2;
					osresult2 = osrlreader2->readOSrL( osxl);
#ifdef MY_DEBUG
					std::cout << "Compare in-memory objects" << std::endl;
#endif
					if (osresult2->IsEqual(osresult) == false)
						throw ErrorClass("Two objects are not equal!");
#ifdef MY_DEBUG
					else
						std::cout << "in-memory objects compare equal" << std::endl;
#endif
					delete osrlreader2;
					osrlreader2 = NULL;
				}

				delete osrlwriter;
				osrlwriter = NULL;
			}
			delete osrlreader;
			osrlreader = NULL;
		}
	}	
	catch(const ErrorClass& eclass)
	{
		cout << endl << endl << endl;
		if (osilreader != NULL) delete osilreader;
//		if (osolreader != NULL) delete osolreader;
		if (osrlreader != NULL) delete osrlreader;
		//  Problem with the parser
		parsingTestResultFailure << eclass.errormsg << endl;
		parsingTestResultFailure << "There was a failure in the " + schema + " parser; ";
		parsingTestResultFailure << "file " << testFileName << " not processed." << endl;
	}

	delete fileUtil;
	fileUtil = NULL;
	    
	if (parsingTestResultFailure.str().length() > 0)
	{
		cout << "PARSING TEST FAILED ON THE FOLLOWING:" << endl << endl;
		cout << parsingTestResultFailure.str() << endl << endl;
		return 1;
	}
	else
	{

#ifdef MY_DEBUG
		std::cout << "PARSING TEST SUCCEEDED" << std::endl;
#endif

		return 0;
	}
}//end main

bool interactiveShell(std::string *schema, std::string *testFileName, std::string *outFileName,
					  bool *compress, bool *addWhiteSpace, bool *verifyObjects)
{
	std::string userInput;
	bool haveParser = false;
	std::cout << "Welcome to the parser test, which is part of the Optimization Services suite" << std::endl << std::endl;

	std::cout << "This program (c) 2010 Horand Gassmann, Jun Ma and Kipp Martin" << std::endl << std::endl;

	while (haveParser == false)
	{
		std::cout << "Input the parser you want to test (osil|osol|osrl)" << std::endl;
		std::cout << "    or \"quit\" to exit the program > ";
		*schema = getUserInput(false);
		if (*schema == "osil") break; 
		if (*schema == "osol") break; 
		if (*schema == "osrl") break; 
		if (*schema == "quit") return false; 
	}

	std::cout << "Input the file you want to parse > ";
	*testFileName = getUserInput(false);

	std::cout << std::endl << "The remaining arguments are optional." << std::endl;

	std::cout << "Name of the output file to which you want to print the object after processing" << std::endl;
	std::cout << "> ";
	*outFileName = getUserInput(true);

	if (*outFileName == "")
		std::cout << "No output generated; remaining options skipped." << std::endl; 
	else
	{
		std::cout << "Do you want to compress the output (using mult and incr attributes where possible)? (YES|no) > ";
		userInput = getUserInput(true);
		if ( (userInput == "no") || (userInput == "NO") || (userInput == "No") || (userInput == "N") || (userInput == "n") ) 
			*compress = false;

		std::cout << "Do you want to add whitespace (newline characters) between elements? (YES|no) > ";
		userInput = getUserInput(true);
		if ( (userInput == "no") || (userInput == "NO") || (userInput == "No") ) *addWhiteSpace = false;

		std::cout << "Do you want to verify that input and output represents the same object? (yes|NO) > ";
		userInput = getUserInput(true);
		if ( (userInput == "yes") || (userInput == "YES") || (userInput == "Yes")|| (userInput == "Y") || (userInput == "y") ) 
			*verifyObjects = true;
	}
	std::cout << std::endl << "echo input parameters" << std::endl;
	std::cout << "schema:        \"" << *schema        << "\"" << std::endl;
	std::cout << "testFileName:  \"" << *testFileName  << "\"" << std::endl;
	std::cout << "outFileName:   \"" << *outFileName   << "\"" << std::endl;
	std::cout << "compress:      \"" << *compress      << "\"" << std::endl;
	std::cout << "addWhiteSpace: \"" << *addWhiteSpace << "\"" << std::endl;
	std::cout << "verifyObjects: \"" << *verifyObjects << "\"" << std::endl;
	return true;
}

void printHelp()
{
	std::cout << "usage: parsertest <parser> <filename>" << std::endl;
	std::cout << "            [<outfile> [(no)compress (no)addwhitespace (no)verify]]" << std::endl << std::endl;

 	std::cout << "where <parser> is \'osil\' or \'osol\' or \'osrl\'" << std::endl;
	std::cout << "      <filename> is the (path to the) input file you want to parse" << std::endl;
	std::cout << "      <outfile> is the (path to the) output file to print the object just read" << std::endl;
	std::cout << "      compress|nocompress controls the use of mult and incr attributes" << std::endl;
	std::cout << "            to compress the output file. (The default is compress)" << std::endl;
	std::cout << "      addwhitespace|noaddwhitespace governs the use of whitespace (linefeed" << std::endl;
	std::cout << "            characters between elements. (The default is addwhitespace)" << std::endl;
	std::cout << "      verify|noverify governs checks whether the input and output files " << std::endl;
	std::cout << "            represent the same in-memory object. (The default is noverify)" << std::endl;
	return;
}

std::string getUserInput(bool defaultPresent)
{
	std::string lineText;
	bool validName;

	std::string wordSep = " ";
	std::string optionName = "";
	std::string optionValue = "";
	std::string::size_type indexStart;
	std::string::size_type indexEnd;

	for (;;)
	{
		getline(std::cin, lineText);
		lineText = " " + lineText + " ";
		indexStart = lineText.find_first_not_of(wordSep);
		if (indexStart != string::npos) 
		{
			indexEnd = lineText.find_first_of(wordSep, indexStart + 1);
			return lineText.substr(indexStart, indexEnd - indexStart);
		}
		if (defaultPresent) return "";
		std::cout << std::endl;
		std::cout << "You did not enter a valid option." << std::endl;
	} 
	return "";
}
