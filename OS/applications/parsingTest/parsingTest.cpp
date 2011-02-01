/* $Id: parsingTest.cpp 3583 2010-07-13 20:39:42Z kmartin $ */
/** @file parsingTest.cpp
 * 
 * \brief This file tests the validity of an OSiL, OSoL or OSrL file.  
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin 
 *
 * \remarks
 * Copyright (C) 2010, Horand Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University, Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 * 
 */ 

#include <cppad/cppad.hpp> 
#include "OSConfig.h"
#include "OSInstance.h"  
#include "OSOption.h"
#include "OSResult.h" 
#include "OSiLReader.h"        
#include "OSiLWriter.h"        
#include "OSoLReader.h"        
#include "OSoLWriter.h"        
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

#define MY_DEBUG

bool interactiveShell(std::string *schema, std::string *testFileName, std::string *outFileName,
					  bool *compress, bool *addWhiteSpace, bool *verifyObjects, 
					  unsigned int *seed, int *nrep, double *density, bool *conformant);
void printHelp();
std::string getUserInput(bool defaultPresent);


int main(int argC, char* argV[])
{
	WindowsErrorPopupBlocker();

	// define the classes
	FileUtil *fileUtil = NULL;  
	OSiLReader *osilreader = NULL;
	OSoLReader *osolreader = NULL;
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
	bool verifyObjects = true;
	bool useRandomObjects = true;
	double check;

	int nrep = 1;
	unsigned int seed;
	double density = 0.5;
	bool conformant = true;
	
	seed = time(NULL);
//	Command line parser and user interface

	if (argC == 1)
	{
		if (interactiveShell(&schema, &testFileName, &outFileName, &compress, &addWhiteSpace, &verifyObjects,
			&seed, &nrep, &density, &conformant) != true) return 0;

		if (outFileName != "") doOutput = true;

#ifdef MY_DEBUG
			std::cout << "User dialog completed " << std::endl;
#endif
	}
	else //command line arguments were given
/****
 * command line arguments and default values
 * -schema=[osil|osol|osrl]  used to select the schema
 * -file=<filename>          name of the input file
 * -random=[YES|no]          should random objects be generated?
 * -replications=<nnn>       number of replications of the random test
 * -seed=<nnn>               seed for the random number generator
 * -density=<x.x>            average fraction of child elements
 * -conformant=[YES|no]      should side constraints be enforced?
 * -outfile=<filename>       name of the output file
 * -compress=[YES|no]        use mult and incr to compress output file?
 * -whitespace=[YES|no]      use whitespace between elements?
 * -verify=[yes|NO]          test input and output objects for equality?
 * 
 * -random is synonymous with -random=yes,
 * -norandom is synonymous with -random=no, etc.  
 */
	{
		int argM = 12; //maximal number of command line arguments including `parsingTest`
		if( argC > argM)
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
 /*
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
 */	
		size_t ipos, epos;
		std::string argument, option, value;
		char* p;
		for (int i=1; i<argC; i++)
		{
			if (argV[i][0] != '-') 
				throw ErrorClass(" Error while writing compressed file");
			argument = std::string(argV[i]);
			epos = argument.find('=');
			option = argument.substr(0,epos);
			if (epos < string::npos)
				value = argument.substr(epos+1);
			else
				value = "";

	std::cout << "option = \"" << option << "\"" << std::endl;		
	std::cout << "value  = \"" << value  << "\"" << std::endl;		
	
			if (option == "-schema")
			{
				if (value == "")
					throw ErrorClass("schema option must have a value");
				schema = value;
			}
			else if (option == "-file")
			{
				if (value == "")
					throw ErrorClass("file option must have a value");
				testFileName = value;
				useRandomObjects = false;
			}
			else if (option == "-replications")
			{
				if (value == "")
					throw ErrorClass("number of replications must be given");
				nrep = atoi(value.c_str());
			}
			else if (option == "-seed")
			{
				if (value == "")
					throw ErrorClass("seed option must have a value");
				seed = atoi(value.c_str());
			}
			else if (option == "-density")
			{
				if (value == "")
					throw ErrorClass("density option must have a value");
				density = os_strtod(value.c_str(), NULL);
			}
			else if (option == "-outfile")
			{
				if (value == "")
					throw ErrorClass("outfile option must have a value");
				outFileName = value;
			}
			else if (option == "-random")
			{
				useRandomObjects = (value == "YES" || value == "yes" || value == "Y" || value == "Y" || value == "y" || value == "");
				testFileName = "";
			}
			else if (option == "-conformant")
			{
				conformant = (value == "YES" || value == "yes" || value == "Y" || value == "Y" || value == "y" || value == "");
			}
			else if (option == "-compress")
			{
				compress = (value == "YES" || value == "yes" || value == "Y" || value == "Y" || value == "y" || value == "");
			}
			else if (option == "-whitespace")
			{
				addWhiteSpace = (value == "YES" || value == "yes" || value == "Y" || value == "Y" || value == "y" || value == "");
			}
			else if (option == "-verify")
			{
				if (value == "")
					verifyObjects = true;
				else 
					verifyObjects = !(value == "NO" || value == "no" || value == "N" || value == "N" || value == "");
			}
			else if (option == "-norandom")
			{
				useRandomObjects = false;
			}
			else if (option == "-noconformant")
			{
				conformant = false;
			}
			else if (option == "-nocompress")
			{
				compress = false;
			}
			else if (option == "-nowhitespace")
			{
				addWhiteSpace = false;
			}
			else if (option == "-noverify")
			{
				verifyObjects = false;
			}
		}
	}

	fileUtil = new FileUtil();

	try
	{

/*********************************************************************
 * Generate and parse random objects
 *********************************************************************/
		if (random)
		{
			if (schema == "osil")
			{
				for (int irep=0; irep < nrep; irep++)
				{
/* steps required:
 *	generate random object
 *	write to string	
 *	parse string
 *	if verify, compare
 */		
				}
			}
			else if (schema == "osol")
			{
				OSOption *osoption, *osoption2;
				osoption = new OSOption();
				OSoLWriter *osolwriter;
				osolwriter = new OSoLWriter();
				OSoLReader *osolreader;
				osolreader = new OSoLReader();

				for (int irep=0; irep < nrep; irep++)
				{
std::cout << "use random number seed: " << seed << std::endl;

					srand(seed);

std::cout << "set random osoption" << std::endl;

					osoption->setRandom(density, conformant);

std::cout << "write to string" << std::endl;

					osxl = osolwriter->writeOSoL(osoption);

std::cout << osxl << std::endl;

					osoption2 = osolreader->readOSoL( osxl);
					if (verifyObjects == true)
					{
						if (osoption->IsEqual(osoption2) == false)
							throw ErrorClass("Two objects are not equal!");
					}
					seed = rand();
				}
			}
			else if (schema == "osrl")
			{
				for (int irep=0; irep < nrep; irep++)
				{
				}
			}
		}
		else if (testFileName == "")
			throw ErrorClass("No filename given. Nothing to parse.");
		else
		{
#ifdef MY_DEBUG
			std::cout << "Processing file: " ;
			std::cout <<  testFileName << std::endl;
#endif

			osxl = fileUtil->getFileAsString( testFileName.c_str() );

#ifdef MY_DEBUG
			std::cout << "Done reading the file into memory" << std::endl;
#endif

/*********************************************************************
 * Parse OSiL file
 *********************************************************************/
			if (schema == "osil")
			{
				osilreader = new OSiLReader(); 
				OSInstance *osinstance;
#ifdef MY_DEBUG
				std::cout << "Start parsing the file" << std::endl;
#endif
				osinstance = osilreader->readOSiL( osxl);

#ifdef MY_DEBUG
				parsingTestResult << "Parsed file successfully" << std::endl;
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

/*********************************************************************
 * Parse OSoL file
 *********************************************************************/
			else if (schema == "osol")
			{
				osolreader = new OSoLReader(); 
				OSOption *osoption;
#ifdef MY_DEBUG
				std::cout << "Start parsing the file" << std::endl;
#endif
				osoption = osolreader->readOSoL( osxl);

#ifdef MY_DEBUG
				parsingTestResult << "Parsed file successfully" << std::endl;
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
						OSoLReader *osolreader2;
						osolreader2 = new OSoLReader(); 
						OSOption *osoption2;
						osoption2 = osolreader2->readOSoL( osxl);
#ifdef MY_DEBUG
						std::cout << "Compare in-memory objects" << std::endl;
#endif
						if (osoption2->IsEqual(osoption) == false)
							throw ErrorClass("Two objects are not equal!");
#ifdef MY_DEBUG
						else
							std::cout << "in-memory objects compare equal" << std::endl;
#endif
						delete osolreader2;
						osolreader2 = NULL;
					}

					delete osolwriter;
					osolwriter = NULL;
				}
				delete osolreader;
				osolreader = NULL;
			}

/*********************************************************************
 * Parse OSrL file
 *********************************************************************/
			else if (schema == "osrl")
			{
				osrlreader = new OSrLReader(); 
				OSResult *osresult;
#ifdef MY_DEBUG
				std::cout << "Start parsing the file" << std::endl;
#endif
				osresult = osrlreader->readOSrL( osxl);

#ifdef MY_DEBUG
				parsingTestResult << "Parsed file successfully" << std::endl;
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
					  bool *compress, bool *addWhiteSpace, bool *verifyObjects, 
					  unsigned int *seed, int *nrep, double *density, bool *conformant)
{
	std::string userInput;
	bool haveParser = false;
	std::cout << "Welcome to the parser test, which is part of the Optimization Services suite" << std::endl << std::endl;

	std::cout << "This program (c) 2011 Horand Gassmann, Jun Ma and Kipp Martin" << std::endl << std::endl;

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

	std::cout << "Input the file you want to parse or press return to generate random problems> ";
	*testFileName = getUserInput(true);

	if (*testFileName == "")
	{
		std::cout << std::endl << "Random problem generation selected." << std::endl;

		std::cout << std::endl << "Do you want to input a random number seed? [y|N] > ";
		std::string temp;
		temp = getUserInput(true);
		if (temp == "Y" || temp == "y")
		{
			std::cout << std::endl << "Input the random number seed (must be nonnegative integer) > ";
			std::cin >> *seed;			
		}

		std::cout << " Input number of replications > "; 
		std::cin  >> *nrep;

		std::cout << " Input density (0..1) > "; 
		std::cin  >> *density;

		std::cout << " Enforce side constraints (Y|n) > ";
		userInput = getUserInput(true);
		if ( (userInput == "no") || (userInput == "NO") || (userInput == "No") || (userInput == "N") || (userInput == "n") ) 
			*conformant = false;

		std::cout << "Do you want to verify that input and output represents the same object? (yes|NO) > ";
		userInput = getUserInput(true);
		if ( (userInput == "yes") || (userInput == "YES") || (userInput == "Yes")|| (userInput == "Y") || (userInput == "y") ) 
			*verifyObjects = true;
	}
	else
	{
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
	}
		
	std::cout << std::endl << "echo input parameters" << std::endl;
	std::cout << "schema:        \"" << *schema        << "\"" << std::endl;
	std::cout << "testFileName:  \"" << *testFileName  << "\"" << std::endl;
	std::cout << "outFileName:   \"" << *outFileName   << "\"" << std::endl;
	std::cout << "compress:      \"" << *compress      << "\"" << std::endl;
	std::cout << "addWhiteSpace: \"" << *addWhiteSpace << "\"" << std::endl;
	std::cout << "verifyObjects: \"" << *verifyObjects << "\"" << std::endl;
	std::cout << "replications:  \"" << *nrep          << "\"" << std::endl;
	std::cout << "random seed:   \"" << *seed          << "\"" << std::endl;
	std::cout << "density:       \"" << *density       << "\"" << std::endl;
	std::cout << "conformant:    \"" << *conformant    << "\"" << std::endl;

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
		std::cout << "You did not enter a valid option. Try again." << std::endl;
	} 
	return "";
}
