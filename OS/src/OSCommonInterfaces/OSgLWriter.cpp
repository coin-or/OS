/* $Id: OSgLWriter.cpp 3729 2010-10-18 12:25:22Z Gassmann $ */
/** @file OSgLWriter.cpp
 * 
 *
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, Dalhousie University and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */


#include "OSgLWriter.h"
#include "OSGeneral.h"
#include "OSParameters.h" 
#include "OSBase64.h"
#include "OSMathUtil.h"
#include "CoinFinite.hpp"

#include <sstream>  

using std::cout;
using std::endl;
using std::ostringstream; 

/*! \brief Take an IntVector object and write
 * a string that validates against the OSgL schema.
 *
 * @param v is the IntVector to be output
 * @param addWhiteSpace controls whether whitespace (i.e., line feed) is to be added 
 * @param writeBase64 controls whether the IntVector is to be output in base64 format 
 *        or as a sequence of <el> (including mult and incr attributes) 
 */
std::string writeIntVectorData(IntVector *v, bool addWhiteSpace, bool writeBase64)
{
	ostringstream outStr;
	int mult, incr;

	if (v->numberOfEl > 0)
	{
		if(writeBase64 == false)
		{
			for(int i = 0; i < v->numberOfEl;)
			{
				getMultIncr(&(v->el[i]), &mult, &incr, (v->numberOfEl) - i, 0);
				if (mult == 1)
					outStr << "<el>" ;
				else if (incr == 1)
					outStr << "<el mult=\"" << mult << "\">";
				else
					outStr << "<el mult=\"" << mult << "\" incr=\"" << incr << "\">";
				outStr << v->el[i];
				outStr << "</el>" ;
				if(addWhiteSpace == true) outStr << endl;
				i += mult;
			}
		}
		else
		{
			outStr << "<base64BinaryData sizeOf=\"" << sizeof(int) << "\">" ;
			outStr << Base64::encodeb64( (char*)v->el, (v->numberOfEl)*sizeof(int) );
			outStr << "</base64BinaryData>" ;
			if(addWhiteSpace == true) outStr << endl;
		}
	}
	return outStr.str();
}// end writeIntVectorData


/*! \brief Take an OtherOptionEnumeration object and write
 * a string that validates against the OSgL schema.
 *
 * @param e is the OtherOptionEnumeration to be output
 * @param addWhiteSpace controls whether whitespace (i.e., line feed) is to be added 
 * @param writeBase64 controls whether the embedded integer array is to be output in base64 format 
 *        or as a sequence of <el> (including mult and incr attributes) 
 */
std::string writeOtherOptionEnumeration(OtherOptionEnumeration *e, bool addWhiteSpace, bool writeBase64)
{
	ostringstream outStr;

	outStr << "<enumeration ";
	outStr << "numberOfEl=\"" << e->numberOfEl << "\" ";
	if (e->value != "") outStr << "value=\"" << e->value << "\" ";
	if (e->description != "") outStr << "description=\"" << e->description << "\" ";
	outStr << ">";
	outStr << writeIntVectorData(e, addWhiteSpace, writeBase64);
	outStr << "</enumeration>";
	return outStr.str();
}// end writeOtherOptionEnumeration



/*! \brief Take a DoubleVector object and write
 * a string that validates against the OSgL schema.
 *
 * @param v is the DoubleVector to be output
 * @param addWhiteSpace controls whether whitespace (i.e., line feed) is to be added 
 * @param writeBase64 controls whether the IntVector is to be output in base64 format 
 *        or as a sequence of <el> (including mult and incr attributes) 
 */
std::string writeDblVectorData(DoubleVector *v, bool addWhiteSpace, bool writeBase64)
{
	ostringstream outStr;
	int mult, incr;

	if (v->numberOfEl > 0)
	{
		if(writeBase64 == false)
		{
			for(int i = 0; i < v->numberOfEl;)
			{
				mult = getMult(&(v->el[i]), (v->numberOfEl) - i);
				if (mult == 1)
					outStr << "<el>" ;
				else 
					outStr << "<el mult=\"" << mult << "\">";
				outStr << os_dtoa_format(v->el[i] );
				outStr << "</el>" ;
				if(addWhiteSpace == true) outStr << endl;
				i += mult;
			}
		}
		else
		{
			outStr << "<base64BinaryData sizeOf=\"" << sizeof(double) << "\">" ;
			outStr << Base64::encodeb64( (char*)v->el, (v->numberOfEl)*sizeof(double) );
			outStr << "</base64BinaryData>" ;
			if(addWhiteSpace == true) outStr << endl;
		}
	}
	return outStr.str();
}// end writeDblVectorData


/*! \brief Take a BasisStatus object and write
 * a string that validates against the OSgL schema.
 *
 * @param bs is the basisStatus object to be output
 * @param addWhiteSpace controls whether whitespace (i.e., line feed) is to be added 
 * @param writeBase64 controls whether the IntVectors contained in the enumerations are to be output in base64 format 
 *        or as a sequence of <el> (including mult and incr attributes) 
 */
std::string writeBasisStatus(BasisStatus *bs, bool addWhiteSpace, bool writeBase64)
{
	ostringstream outStr;
	outStr << "<basisStatus>" << endl;
	
	if (bs->basic != NULL && bs->basic->numberOfEl > 0)
	{
		outStr << "<basic numberOfEl=\"" << bs->basic->numberOfEl << "\">";
		if(addWhiteSpace == true) outStr << endl;
		outStr << writeIntVectorData(bs->basic, addWhiteSpace, writeBase64);
		outStr << "</basic>";
		if(addWhiteSpace == true) outStr << endl;
	}
	
	if (bs->atLower != NULL && bs->atLower->numberOfEl > 0)
	{
		outStr << "<atLower numberOfEl=\"" << bs->atLower->numberOfEl << "\">";
		if(addWhiteSpace == true) outStr << endl;
		outStr << writeIntVectorData(bs->atLower, addWhiteSpace, writeBase64);
		outStr << "</atLower>";
		if(addWhiteSpace == true) outStr << endl;
	}
	
	if (bs->atUpper != NULL && bs->atUpper->numberOfEl > 0)
	{
		outStr << "<atUpper numberOfEl=\"" << bs->atUpper->numberOfEl << "\">";
		if(addWhiteSpace == true) outStr << endl;
		outStr << writeIntVectorData(bs->atUpper, addWhiteSpace, writeBase64);
		outStr << "</atUpper>";
		if(addWhiteSpace == true) outStr << endl;
	}
	
	if (bs->isFree != NULL && bs->isFree->numberOfEl > 0)
	{
		outStr << "<isFree numberOfEl=\"" << bs->isFree->numberOfEl << "\">";
		if(addWhiteSpace == true) outStr << endl;
		outStr << writeIntVectorData(bs->isFree, addWhiteSpace, writeBase64);
		outStr << "</isFree>";
		if(addWhiteSpace == true) outStr << endl;
	}
	
	if (bs->superbasic != NULL && bs->superbasic->numberOfEl > 0)
	{
		outStr << "<superbasic numberOfEl=\"" << bs->superbasic->numberOfEl << "\">";
		if(addWhiteSpace == true) outStr << endl;
		outStr << writeIntVectorData(bs->superbasic, addWhiteSpace, writeBase64);
		outStr << "</superbasic>";
		if(addWhiteSpace == true) outStr << endl;
	}

	if (bs->unknown != NULL && bs->unknown->numberOfEl > 0)
	{
		outStr << "<unknown numberOfEl=\"" << bs->unknown->numberOfEl << "\">";
		if(addWhiteSpace == true) outStr << endl;
		outStr << writeIntVectorData(bs->unknown, addWhiteSpace, writeBase64);
		outStr << "</unknown>";
		if(addWhiteSpace == true) outStr << endl;
	}
	
	outStr << "</basisStatus>" << endl;
	
	return outStr.str();
}// end writeDblVectorData
