/* $Id: OSgLWriter.cpp 3729 2010-10-18 12:25:22Z Gassmann $ */
/** @file OSgLWriter.cpp
 *
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2011, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */

#include "OSgLWriter.h"
#include "OSStringUtil.h"
#include "OSGeneral.h"
#include "OSParameters.h"
#include "OSBase64.h"
#include "OSMathUtil.h"
#include "CoinFinite.hpp"

#include <sstream>

using std::endl;
using std::ostringstream;


/*! \brief Take a GeneralFileHeader object and write
 * a string that validates against the OSgL schema.
 *
 * @param v is the object to be output
 * @param addWhiteSpace controls whether whitespace (i.e., line feed) is to be added
 */
std::string writeGeneralFileHeader(GeneralFileHeader *v, bool addWhiteSpace)
{
    ostringstream outStr;

    if (v->name != "")
    {
        outStr << "<name>" << v->name << "</name>" ;
        if(addWhiteSpace == true) outStr << endl;
    }

    if (v->source != "")
    {
        outStr << "<source>" << v->source << "</source>" ;
        if(addWhiteSpace == true) outStr << endl;
    }

    if (v->description != "")
    {
        outStr << "<description>" << v->description << "</description>" ;
        if(addWhiteSpace == true) outStr << endl;
    }

    if (v->fileCreator != "")
    {
        outStr << "<fileCreator>" << v->fileCreator << "</fileCreator>" ;
        if(addWhiteSpace == true) outStr << endl;
    }

    if (v->licence != "")
    {
        outStr << "<licence>" << v->licence << "</licence>" ;
        if(addWhiteSpace == true) outStr << endl;
    }
    return outStr.str();
}// end writeGeneralFileHeader


/*! \brief Take an OtherOptionOrResultEnumeration object and write
 * a string that validates against the OSgL schema.
 *
 * @param e is the OtherOptionOrResultEnumeration to be output
 * @param addWhiteSpace controls whether whitespace (i.e., line feed) is to be added
 * @param writeBase64 controls whether the embedded integer array is to be output in base64 format
 *        or as a sequence of <el> (including mult and incr attributes)
 */
std::string writeOtherOptionOrResultEnumeration(OtherOptionOrResultEnumeration *e, bool addWhiteSpace, bool writeBase64)
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
}// end writeOtherOptionOrResultEnumeration


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
                else if (incr == 0)
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
    int mult;

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

    if (bs->basic != NULL)
    {
        outStr << "<basic numberOfEl=\"" << bs->basic->numberOfEl << "\">";
        if(addWhiteSpace == true) outStr << endl;
        outStr << writeIntVectorData(bs->basic, addWhiteSpace, writeBase64);
        outStr << "</basic>";
        if(addWhiteSpace == true) outStr << endl;
    }

    if (bs->atLower != NULL)
    {
        outStr << "<atLower numberOfEl=\"" << bs->atLower->numberOfEl << "\">";
        if(addWhiteSpace == true) outStr << endl;
        outStr << writeIntVectorData(bs->atLower, addWhiteSpace, writeBase64);
        outStr << "</atLower>";
        if(addWhiteSpace == true) outStr << endl;
    }

    if (bs->atUpper != NULL)
    {
        outStr << "<atUpper numberOfEl=\"" << bs->atUpper->numberOfEl << "\">";
        if(addWhiteSpace == true) outStr << endl;
        outStr << writeIntVectorData(bs->atUpper, addWhiteSpace, writeBase64);
        outStr << "</atUpper>";
        if(addWhiteSpace == true) outStr << endl;
    }

    if (bs->atEquality != NULL)
    {
        outStr << "<atEquality numberOfEl=\"" << bs->atEquality->numberOfEl << "\">";
        if(addWhiteSpace == true) outStr << endl;
        outStr << writeIntVectorData(bs->atEquality, addWhiteSpace, writeBase64);
        outStr << "</atEquality>";
        if(addWhiteSpace == true) outStr << endl;
    }

    if (bs->isFree != NULL)
    {
        outStr << "<isFree numberOfEl=\"" << bs->isFree->numberOfEl << "\">";
        if(addWhiteSpace == true) outStr << endl;
        outStr << writeIntVectorData(bs->isFree, addWhiteSpace, writeBase64);
        outStr << "</isFree>";
        if(addWhiteSpace == true) outStr << endl;
    }

    if (bs->superbasic != NULL)
    {
        outStr << "<superbasic numberOfEl=\"" << bs->superbasic->numberOfEl << "\">";
        if(addWhiteSpace == true) outStr << endl;
        outStr << writeIntVectorData(bs->superbasic, addWhiteSpace, writeBase64);
        outStr << "</superbasic>";
        if(addWhiteSpace == true) outStr << endl;
    }

    if (bs->unknown != NULL)
    {
        outStr << "<unknown numberOfEl=\"" << bs->unknown->numberOfEl << "\">";
        if(addWhiteSpace == true) outStr << endl;
        outStr << writeIntVectorData(bs->unknown, addWhiteSpace, writeBase64);
        outStr << "</unknown>";
        if(addWhiteSpace == true) outStr << endl;
    }

    return outStr.str();
}// end writeBasisStatus
