/* $Id$ */
/** @file FileUtil.cpp
 *
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2012, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 * <p>The <code>FileUtil</code> class contains methods for reading
 * and writing files from strings used by many classes in the
 * Optimization Services (OS) framework. </p>
 */

#include <cstring>
#include "OSFileUtil.h"
#include "OSErrorClass.h"
#include "OSOutput.h"

using std::endl;


FileUtil::FileUtil()
{
} // end constructor


FileUtil::~FileUtil()
{
} // end destructor

std::string FileUtil::getFileAsString( const char* fname)
{
    try
    {
        std::ostringstream outStr;
        std::ostringstream fileName;
        fileName << fname << std::endl;
        std::string soutString;
        char ch;
        std::ifstream inFile( fname);
        if( !inFile)
        {
            throw ErrorClass(" Could not open the given file: " + fileName.str());
        }

        while( inFile.get( ch ) )
        {
            outStr << ch;
        }

        if( !inFile.eof() )
        {
            throw ErrorClass(" There was a problem reading the file: " + fileName.str() );
        }
        soutString = outStr.str();
        inFile.close();
        return soutString;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg) ;
    }
} // end getFileAsString


char* FileUtil::getFileAsChar(const  char* fname)
{
    try
    {
        std::ostringstream fileName;
        fileName << fname << std::endl;
        std::filebuf *pbuf;
        long bufsize = 0;
        char *xml;
        char ch;
        std::ifstream inFile;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSUtils, ENUM_OUTPUT_LEVEL_info, fileName.str());
        inFile.open( fname);
        if(!inFile)
        {
            throw ErrorClass(" Could not read the given file: " + fileName.str() );
        }
        // get the input file stream into the buffer
        pbuf = inFile.rdbuf();
        // now get the size
        bufsize = pbuf->pubseekoff(0,std::ios_base::end);
        // set back to zero
        pbuf ->pubseekpos(0, std::ios::in);
        // allocate the character array
        xml = new char[bufsize + 1];
        xml[ bufsize] =  '\0';
        bufsize = 0;
        while( inFile.get( ch ) )
        {
            xml[ bufsize] = ch;
            bufsize++;
        }

        if( !inFile.eof() )
        {
            throw ErrorClass(" There was a problem reading the file: " + fileName.str());
        }
        return xml;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg) ;
    }
} // end getFileAsChar


bool FileUtil::writeFileFromString(char* fname, std::string sname)
{
    std::ostringstream fileName;
    fileName << fname << std::endl;
    FILE *ft ;
    try
    {
        ft = fopen ( fname, "w") ;
        if ( ft == NULL )
        {
            throw ErrorClass(" There was a problem opening the file: " + fileName.str());
        }
        char *cstr;
        cstr = new char [sname.size() + 1];
        strcpy (cstr, sname.c_str());
        size_t i;
        for(i = 0; i < sname.size() + 1; i++)
        {
            if(cstr[ i] != '\0')     fputc ( cstr[ i], ft )  ;
        }
        fclose ( ft);
        delete[] cstr;
        cstr = NULL;
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg) ;
    }
} // end writeFileFromString


bool FileUtil::writeFileFromString(std::string  fname, std::string sname)
{
    std::ostringstream fileName;
    fileName << fname << std::endl;
    FILE *ft ;
    try
    {
        ft = fopen ( fname.c_str(), "w") ;
        if ( ft == NULL )
        {
            throw ErrorClass(" There was a problem opening the file: " + fileName.str());
        }
        char *cstr;
        cstr = new char [sname.size() + 1];
        strcpy (cstr, sname.c_str());
        size_t i;
        for(i = 0; i < sname.size() + 1; i++)
        {
            if(cstr[ i] != '\0')     fputc ( cstr[ i], ft )  ;
        }
        fclose ( ft);
        delete[] cstr;
        cstr = NULL;
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg) ;
    }
} // end writeFileFromString


bool FileUtil::writeFileFromChar(char* fname, char* ch)
{
    //std::ofstream outFile;
    std::fstream outFile;
    outFile.open( fname);
    if(!outFile.is_open())
    {
        return false;
    }
    outFile << *ch;
    outFile.close();
    return true;
} // end writeFileFromChar

