/* $Id: OSGeneral.cpp 3186 2010-02-06 23:38:35Z Gassmann $ */
/** @file OSGeneral.cpp
 *
 * @author Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2012, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */

#include "OSGeneral.h"
#include "OSParameters.h"
#include "OSErrorClass.h"
#include "OSMathUtil.h"
#include "OSBase64.h"
#include "OSOutput.h"

#include <iostream>
#include <sstream>


using namespace std;
using std::endl;

GeneralFileHeader::GeneralFileHeader():
    name(""),
    source(""),
    description(""),
    fileCreator(""),
    licence("")
{
}// end GeneralFileHeader constructor

GeneralFileHeader::~GeneralFileHeader()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "inside file header destructor");
#endif
}// end GeneralFileHeader destructor

bool GeneralFileHeader::IsEqual(GeneralFileHeader *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_debug, "Start comparing in GeneralFileHeader");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_debug, "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_debug, "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if ((this->name        != that->name)        ||
                (this->source      != that->source)      ||
                (this->description != that->description) ||
                (this->fileCreator != that->fileCreator) ||
                (this->licence     != that->licence))
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "name: "        << this->name        << " vs. " << that->name        << endl;
                outStr << "source: "      << this->source      << " vs. " << that->source      << endl;
                outStr << "description: " << this->description << " vs. " << that->description << endl;
                outStr << "fileCreator: " << this->fileCreator << " vs. " << that->fileCreator << endl;
                outStr << "licence: "     << this->licence     << " vs. " << that->licence     << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_debug, outStr.str());

#endif
                return false;
            }
            return true;
        }
    }
}// end of GeneralFileHeader::IsEqual

bool GeneralFileHeader::setRandom(double density, bool conformant)
{
    if (OSRand() <= density) this->name        = "random string";
    if (OSRand() <= density) this->source      = "random string";
    if (OSRand() <= density) this->description = "random string";
    if (OSRand() <= density) this->fileCreator = "random string";
    if (OSRand() <= density) this->licence     = "random string";
    return true;
}// end of GeneralFileHeader::setRandom

bool GeneralFileHeader::deepCopyFrom(GeneralFileHeader *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of GeneralFileHeader");
#endif
    this->name        = that->name;
    this->source      = that->source;
    this->description = that->description;
    this->fileCreator = that->fileCreator;
    this->licence     = that->licence;
    return true;
}// end of GeneralFileHeader::deepCopyFrom

std::string GeneralFileHeader::getHeaderItem(std::string item)
{
	if (item == "name")        return name;
	if (item == "source")      return source;
	if (item == "description") return description;
	if (item == "fileCreator") return fileCreator;
	if (item == "licence")     return licence;
    throw ErrorClass("Attempting to access undefined header item in getHeaderItem");
}//end of GeneralFileHeader::getHeaderItem

bool GeneralFileHeader::setHeader(std::string name, std::string source,
                                  std::string description, std::string fileCreator, std::string licence)
{
    this->name        = name;
    this->source      = source;
    this->description = description;
    this->fileCreator = fileCreator;
    this->licence     = licence;
    return true;
}// end of GeneralFileHeader::setHeader

SparseVector::SparseVector( int number_):
    number( number_)
{
//    if (number > 0)
    {
        indexes = new int[ number];
        values = new double[ number];
    }
    bDeleteArrays = true;
}// end SparseVector constructor


SparseVector::SparseVector( ):
    bDeleteArrays(true),
    indexes( NULL),
    values( NULL)
{
}// end SparseVector constructor

SparseVector::~SparseVector()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "inside sparseVector destructor");
#endif
    if(	bDeleteArrays == true)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "delete[] indexes and arrays");
#endif
        if (indexes != NULL) delete[] indexes;
        if (values  != NULL) delete[] values;
        indexes = NULL;
        values  = NULL;
    }
}// end SparseVector destructor


SparseIntVector::SparseIntVector( int number_):
    number( number_)
{
    indexes = new int[ number];
    values  = new int[ number];
    bDeleteArrays = true;
}// end SparseIntVector constructor


SparseIntVector::SparseIntVector( ):
    bDeleteArrays(true),
    indexes( NULL),
    values( NULL)
{
}// end SparseIntVector constructor

SparseIntVector::~SparseIntVector()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "inside sparseIntVector destructor");
#endif
    if(	bDeleteArrays == true)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "delete[] indexes and arrays");
#endif
        if (indexes != NULL) delete[] indexes;
        if (values  != NULL) delete[] values;
        indexes = NULL;
        values = NULL;
    }
}// end SparseIntVector destructor


SparseMatrix::SparseMatrix():
    bDeleteArrays( true),
    isColumnMajor(true),
    startSize(0),
    valueSize(0),
    starts(NULL),
    indexes(NULL),
    values(NULL)
{
}// end SparseMatrix Constructor



SparseMatrix::SparseMatrix(bool isColumnMajor_, int startSize_, int valueSize_):
    isColumnMajor(isColumnMajor_),
    startSize(startSize_),
    valueSize(valueSize_)
{
    bDeleteArrays = true;
    starts = new int[startSize];
    indexes = new int[valueSize];
    values = new double[valueSize];

}//end SparseMatrix constructor


SparseMatrix::~SparseMatrix()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "inside SparseMatrix destructor");
#endif
    if( bDeleteArrays == true)
    {
        if (starts  != NULL) delete[] starts;
        if (indexes != NULL) delete[] indexes;
        if (values  != NULL) delete[] values;
        starts = NULL;
        indexes = NULL;
        values = NULL;
    }
}// end SparseMatrix Destructor


bool SparseMatrix::display(int secondaryDim)
{
    int i, j, k;
    for ( i = 0; i < startSize - 1; i++)
    {
        if (starts[i] == starts[i + 1])
        {
            for ( k = 0; k < secondaryDim; k++)
            {
                //System.out.print("0,");
            }
        }
        else
        {
            for ( j = 0; j < indexes[starts[i]]; j ++)
            {
                //System.out.print("0,");
            }

            for ( j = starts[ i ]; j < starts[i + 1]; j++)
            {
                //System.out.print (values[j] + ",");

                if ( j < starts[i + 1] - 1)
                {
                    for ( k = indexes [j] + 1; k < indexes[j + 1]; k++)
                    {
                        //System.out.print("0,");
                    }
                }
                else
                {
                    for ( k = indexes [j] + 1; k < secondaryDim; k++)
                    {
                        //System.out.print("0,");
                    }
                }
            }
        }
        //System.out.println();
    }

    return true;

}//display

SparseJacobianMatrix::SparseJacobianMatrix():
    bDeleteArrays( true),
    startSize(0),
    valueSize(0),
    starts(NULL),
    conVals(NULL),
    indexes(NULL),
    values(NULL)
{
}// end SparseJaccobianMatrix Constructor


SparseJacobianMatrix::SparseJacobianMatrix(int startSize_, int valueSize_):
    bDeleteArrays( true),
    startSize(startSize_),
    valueSize(valueSize_)
{
    starts = new int[startSize];
    conVals = new int[startSize];
    indexes = new int[valueSize];
    values = new double[valueSize];
}//end SparseJacobianMatrix constructor


SparseJacobianMatrix::~SparseJacobianMatrix()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "inside SparseJacobianMatrix destructor");
#endif
    if(bDeleteArrays == true)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "delete SparseJacobianArrays");
#endif
        if (starts  != NULL) delete[] starts;
        if (conVals != NULL) delete[] conVals;
        if (indexes != NULL) delete[] indexes;
        if (values  != NULL) delete[] values;
        starts  = NULL;
        conVals = NULL;
        indexes = NULL;
        values  = NULL;
    }
}// end SparseJacobianMatrix Destructor


SparseHessianMatrix::SparseHessianMatrix():
    bDeleteArrays( true),
    hessDimension(0),
    hessRowIdx( NULL),
    hessColIdx( NULL),
    hessValues( NULL)
{
}// end SparseHessianMatrix Constructor



SparseHessianMatrix::~SparseHessianMatrix()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "inside SparseHessianMatrix destructor");
#endif
    if(bDeleteArrays == true)
    {
        if (hessRowIdx != NULL) delete[] hessRowIdx;
        if (hessColIdx != NULL) delete[] hessColIdx;
        if (hessValues != NULL) delete[] hessValues;
        hessRowIdx = NULL;
        hessColIdx = NULL;
        hessValues = NULL;
    }
}// end SparseHessianMatrix Destructor



QuadraticTerms::QuadraticTerms():
    rowIndexes(NULL),
    varOneIndexes(NULL),
    varTwoIndexes(NULL),
    coefficients(NULL)
{
}

QuadraticTerms::~QuadraticTerms()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "inside QuadraticTerms destructor");
#endif
    if (rowIndexes    != NULL) delete[] rowIndexes;
    if (varOneIndexes != NULL) delete[] varOneIndexes;
    if (varTwoIndexes != NULL) delete[] varTwoIndexes;
    if (coefficients  != NULL) delete[] coefficients;
    rowIndexes    = NULL;
    varOneIndexes = NULL;
    varTwoIndexes = NULL;
    coefficients  = NULL;
}


IntVector::IntVector():
    bDeleteArrays(true),
    numberOfEl(0),
    el(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "inside IntVector Constructor");
#endif
}


IntVector::IntVector(int n):
    bDeleteArrays(true)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "inside alternate IntVector Constructor");
#endif

    numberOfEl = n;
    el = new int[n];
}

IntVector::~IntVector()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "inside IntVector destructor");
#endif
    if(	bDeleteArrays == true)
    {
        if (el != NULL) delete[] el;
        el = NULL;
    }
}

bool IntVector::setIntVector(int *i, int ni)
{
    if (this->numberOfEl != 0)
        delete[] this->el;

    this->numberOfEl = ni;

    this->el = new int[ni];
    for (int j=0; j<ni; j++)
        this->el[j] = i[j];

    return true;
}//setIntVector

bool IntVector::extendIntVector(int i)
{
    int ni;
//	if (this == NULL)
//		this = new IntVector();

    if (this->el == NULL)
        ni = 0;
    else
        ni = this->numberOfEl;

    int* temp = new int[ni+1];
    for (int j = 0; j < ni; ++j)
        temp[j] = this->el[j];

    delete[] this->el;

    temp[ni] = i;

    this->el = temp;
    this->numberOfEl = ++ni;

    return true;
}//extendIntVector

int IntVector::getNumberOfEl()
{
    return this->numberOfEl;
}

int IntVector::getEl(int j)
{
    if (j < 0 || j >= this->numberOfEl)
        throw ErrorClass("Attempting to access undefined memory in IntVector::getEl(j)");
    return this->el[j];
}

bool IntVector::getEl(int* i)
{
    for (int j=0; j < this->numberOfEl; ++j)
        i[j] = this->el[j];
    return true;
}

bool IntVector::IsEqual(IntVector *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_debug, "Start comparing in IntVector");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_debug, "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_debug, "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (this->numberOfEl != that->numberOfEl)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "numberOfEl: " << this->numberOfEl << " vs. " << that->numberOfEl << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            for (int i=0; i<this->numberOfEl; i++)
            {
                if (this->el[i] != that->el[i])
                {

#ifndef NDEBUG
                    outStr.str("");
                    outStr.clear();
                    outStr << "El[" << i << "]: " << this->el[i] << " vs. " << that->el[i] << endl;
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                    return false;
                }
            }
            return true;
        }
    }
}//IntVector::IsEqual

bool IntVector::setRandom(double density, bool conformant, int iMin, int iMax)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "Set random IntVector");
#endif
    this->numberOfEl = (int)(4*OSRand());

    int n;

    if (conformant)	n = this->numberOfEl;
    else            n = (int)(4*OSRand());

    el = new int[n];
    for (int i = 0; i < n; i++)
        el[i] = (int)OSiRand(iMin, iMax);

    return true;
}//IntVector::setRandom

bool IntVector::deepCopyFrom(IntVector *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of IntVector");
#endif
    this->numberOfEl = that->numberOfEl;
    int n = this->numberOfEl;

    if (n  < 0) return false;
    if (n == 0) return true;

    this->el = new int[n];
    for (int i = 0; i < n; i++)
        this->el[i] = that->el[i];

    return true;
}//IntVector::deepCopyFrom

OtherOptionEnumeration::OtherOptionEnumeration():
    IntVector(),
    value(""),
    description("")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, 
        "Inside the OtherOptionEnumeration Constructor");
#endif
}

OtherOptionEnumeration::OtherOptionEnumeration(int n):
    IntVector(n),
    value(""),
    description("")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, 
        "Inside the alternate OtherOptionEnumeration Constructor");
#endif
}

OtherOptionEnumeration::~OtherOptionEnumeration()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, 
        "Inside the OtherOptionEnumeration Destructor");
#endif
}

bool OtherOptionEnumeration::setOtherOptionEnumeration(std::string value, std::string description, int *i, int ni)
{
    this->value = value;
    this->description = description;
    return this->IntVector::setIntVector(i, ni);
}

std::string OtherOptionEnumeration::getValue()
{
    return this->value;
}

std::string OtherOptionEnumeration::getDescription()
{
    return this->description;
}


bool OtherOptionEnumeration::IsEqual(OtherOptionEnumeration *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_debug, "Start comparing in OtherOptionEnumeration");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_debug, "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (this->value != that->value || this->description != that->description)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "value:       " << this->value       << " vs. " << that->value       << endl;
                outStr << "description: " << this->description << " vs. " << that->description << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }

            return this->IntVector::IsEqual(that);
        }
    }
}//OtherOptionEnumeration::IsEqual

bool OtherOptionEnumeration::setRandom(double density, bool conformant, int iMin, int iMax)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "Set random OtherOptionEnumeration");
#endif
    if (OSRand() <= density) this->value       = "random string";
    if (OSRand() <= density) this->description = "random string";

    if (OSRand() <= density) this->IntVector::setRandom(density,conformant,iMin,iMax);
    return true;
}//OtherOptionEnumeration::setRandom

bool OtherOptionEnumeration::deepCopyFrom(OtherOptionEnumeration *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of OtherOptionEnumeration");
#endif
    this->value       = that->value;
    this->description = that->description;

    if (!this->IntVector::deepCopyFrom(that))
        return false;

    return true;
}//OtherOptionEnumeration::deepCopyFrom


DoubleVector::DoubleVector():
    bDeleteArrays(true),
    el(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "Inside the DoubleVector Constructor");
#endif

}


DoubleVector::~DoubleVector()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "Inside the DoubleVector Destructor");
#endif
    if(	bDeleteArrays == true)
    {
        if (el != NULL) delete[] el;
        el = NULL;
    }
}


bool DoubleVector::IsEqual(DoubleVector *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_debug, "Start comparing in DoubleVector");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_debug, "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_debug, "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (this->numberOfEl != that->numberOfEl)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "numberOfEl: " << this->numberOfEl << " vs. " << that->numberOfEl << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            for (int i=0; i<this->numberOfEl; i++)
            {
                if (!isEqual(this->el[i], that->el[i]))
                {

#ifndef NDEBUG
                    outStr.str("");
                    outStr.clear();
                    outStr << "El[" << i << "]: " << this->el[i] << " vs. " << that->el[i] << endl;
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                    return false;
                }
            }
            return true;
        }
    }
}//DoubleVector::IsEqual


BasisStatus::BasisStatus():
    basic(NULL),
    atLower(NULL),
    atUpper(NULL),
    atEquality(NULL),
    isFree(NULL),
    superbasic(NULL),
    unknown(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "Inside the BasisStatus Constructor");
#endif
}//end BasisStatus constructor


BasisStatus::~BasisStatus()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "Inside the BasisStatus Destructor");
#endif
    if (basic != NULL)
    {
        delete basic;
        basic = NULL;
    }
    if (atLower != NULL)
    {
        delete atLower;
        atLower = NULL;
    }
    if (atUpper != NULL)
    {
        delete atUpper;
        atUpper = NULL;
    }
    if (atEquality != NULL)
    {
        delete atEquality;
        atEquality = NULL;
    }
    if (isFree != NULL)
    {
        delete isFree;
        isFree = NULL;
    }
    if (superbasic != NULL)
    {
        delete superbasic;
        superbasic = NULL;
    }
    if (unknown != NULL)
    {
        delete unknown;
        unknown = NULL;
    }
}// end BasisStatus destructor


bool BasisStatus::setIntVector(int status, int *i, int ni)
{
    switch (status)
    {
    case ENUM_BASIS_STATUS_basic:
    {
        if (this->basic == NULL) this->basic = new IntVector();
//			else delete[] this->basic;
        return this->basic->setIntVector(i, ni);
    }
    case ENUM_BASIS_STATUS_atLower:
    {
        if (this->atLower == NULL) this->atLower = new IntVector(ni);
//			else delete[] this->atLower;
        return this->atLower->setIntVector(i, ni);
    }
    case ENUM_BASIS_STATUS_atUpper:
    {
        if (this->atUpper == NULL) this->atUpper = new IntVector(ni);
//			else delete[] this->atUpper;
        return this->atUpper->setIntVector(i, ni);
    }
    case ENUM_BASIS_STATUS_atEquality:
    {
        if (this->atEquality == NULL) this->atEquality = new IntVector(ni);
//			else delete[] this->atEquality;
        return this->atEquality->setIntVector(i, ni);
    }
    case ENUM_BASIS_STATUS_isFree:
    {
        if (this->isFree == NULL) this->isFree = new IntVector(ni);
//			else delete[] this->isFree;
        return this->isFree->setIntVector(i, ni);
    }
    case ENUM_BASIS_STATUS_superbasic:
    {
        if (this->superbasic == NULL) this->superbasic = new IntVector(ni);
//			else delete[] this->superbasic;
        return this->superbasic->setIntVector(i, ni);
    }
    case ENUM_BASIS_STATUS_unknown:
    {
        if (this->unknown == NULL) this->unknown = new IntVector(ni);
//			else delete[] this->unknown;
        return this->unknown->setIntVector(i, ni);
    }
    default:
        throw ErrorClass("Unknown basis status encountered in BasisStatus::setIntVector");
    }
}//BasisStatus::setIntVector

bool BasisStatus::addIdx(int status, int idx)
{
    switch (status)
    {
    case ENUM_BASIS_STATUS_basic:
    {
        if (this->basic == NULL) this->basic = new IntVector();
        return this->basic->extendIntVector(idx);
    }
    case ENUM_BASIS_STATUS_atLower:
    {
        if (this->atLower == NULL) this->atLower = new IntVector();
        return this->atLower->extendIntVector(idx);
    }
    case ENUM_BASIS_STATUS_atUpper:
    {
        if (this->atUpper == NULL) this->atUpper = new IntVector();
        return this->atUpper->extendIntVector(idx);
    }
    case ENUM_BASIS_STATUS_atEquality:
    {
        if (this->atEquality == NULL) this->atEquality = new IntVector();
        return this->atEquality->extendIntVector(idx);
    }
    case ENUM_BASIS_STATUS_isFree:
    {
        if (this->isFree == NULL) this->isFree = new IntVector();
        return this->isFree->extendIntVector(idx);
    }
    case ENUM_BASIS_STATUS_superbasic:
    {
        if (this->superbasic == NULL) this->superbasic = new IntVector();
        return this->superbasic->extendIntVector(idx);
    }
    case ENUM_BASIS_STATUS_unknown:
    {
        if (this->unknown == NULL) this->unknown = new IntVector();
        return this->unknown->extendIntVector(idx);
    }
    default:
        throw ErrorClass("Unknown basis status encountered in BasisStatus::addIdx");
    }
}//BasisStatus::addIdx


bool BasisStatus::getIntVector(int status, int *i)
{
    switch (status)
    {
    case ENUM_BASIS_STATUS_basic:
    {
        if (this->basic == NULL) return false;
        return this->basic->getEl(i);
    }
    case ENUM_BASIS_STATUS_atLower:
    {
        if (this->atLower == NULL) return false;
        return this->atLower->getEl(i);
    }
    case ENUM_BASIS_STATUS_atUpper:
    {
        if (this->atUpper == NULL) return false;
        return this->atUpper->getEl(i);
    }
    case ENUM_BASIS_STATUS_atEquality:
    {
        if (this->atEquality == NULL) return false;
        return this->atEquality->getEl(i);
    }
    case ENUM_BASIS_STATUS_isFree:
    {
        if (this->isFree == NULL) return false;
        return this->isFree->getEl(i);
    }
    case ENUM_BASIS_STATUS_superbasic:
    {
        if (this->superbasic == NULL) return false;
        return this->superbasic->getEl(i);
    }
    case ENUM_BASIS_STATUS_unknown:
    {
        if (this->unknown == NULL) return false;
        return this->unknown->getEl(i);
    }
    default:
        throw ErrorClass("Unknown basis status encountered in setIntVector");
    }
}//BasisStatus::getIntVector


int BasisStatus::getNumberOfEl(int status)
{
    switch (status)
    {
    case ENUM_BASIS_STATUS_basic:
    {
        if (this->basic == NULL) return -1;
        else return	this->basic->numberOfEl;
    }
    case ENUM_BASIS_STATUS_atLower:
    {
        if (this->atLower == NULL) return -1;
        else return	this->atLower->numberOfEl;
    }
    case ENUM_BASIS_STATUS_atUpper:
    {
        if (this->atUpper == NULL) return -1;
        else return	this->atUpper->numberOfEl;
    }
    case ENUM_BASIS_STATUS_atEquality:
    {
        if (this->atEquality == NULL) return -1;
        else return	this->atEquality->numberOfEl;
    }
    case ENUM_BASIS_STATUS_isFree:
    {
        if (this->isFree == NULL) return -1;
        else return	this->isFree->numberOfEl;
    }
    case ENUM_BASIS_STATUS_superbasic:
    {
        if (this->superbasic == NULL) return -1;
        else return	this->superbasic->numberOfEl;
    }
    case ENUM_BASIS_STATUS_unknown:
    {
        if (this->unknown == NULL) return -1;
        else return	this->unknown->numberOfEl;
    }
    default:
        throw ErrorClass("Unknown basis status encountered in getBasisStatusNumberOfEl");
    }
}//getNumberOfEl


int BasisStatus::getEl(int status, int j)
{
    switch (status)
    {
    case ENUM_BASIS_STATUS_basic:
    {
        if (this->basic == NULL)
            throw ErrorClass("\"basic\" index array never defined in routine BasisStatus::getEl()");
        else return	this->basic->el[j];
    }
    case ENUM_BASIS_STATUS_atLower:
    {
        if (this->atLower == NULL)
            throw ErrorClass("\"atLower\" index array never defined in routine BasisStatus::getEl()");
        else return	this->atLower->el[j];
    }
    case ENUM_BASIS_STATUS_atUpper:
    {
        if (this->atUpper == NULL)
            throw ErrorClass("\"atUpper\" index array never defined in routine BasisStatus::getEl()");
        else return	this->atUpper->el[j];
    }
    case ENUM_BASIS_STATUS_atEquality:
    {
        if (this->atEquality == NULL)
            throw ErrorClass("\"atEquality\" index array never defined in routine BasisStatus::getEl()");
        else return	this->atEquality->el[j];
    }
    case ENUM_BASIS_STATUS_isFree:
    {
        if (this->isFree == NULL)
            throw ErrorClass("\"isFree\" index array never defined in routine BasisStatus::getEl()");
        else return	this->isFree->el[j];
    }
    case ENUM_BASIS_STATUS_superbasic:
    {
        if (this->superbasic == NULL)
            throw ErrorClass("\"superbasic\" index array never defined in routine BasisStatus::getEl()");
        else return	this->superbasic->el[j];
    }
    case ENUM_BASIS_STATUS_unknown:
    {
        if (this->unknown == NULL)
            throw ErrorClass("\"unknown\" index array never defined in routine BasisStatus::getEl()");
        else return	this->unknown->el[j];
    }
    default:
        throw ErrorClass("Unknown basis status encountered in getBasisStatusNumberOfEl");
    }
}//getEl

int BasisStatus::getBasisDense(int *resultArray, int dim, bool flipIdx)
{
    int  i, n, nCopied;
    int* statusArray = NULL;

    nCopied = 0;

    if (this->basic != NULL)
    {
        n = this->basic->getNumberOfEl();
        statusArray = new int[n];
        this->basic->getEl(statusArray);
        for (i=0; i < n; i++)
        {
            if (!flipIdx)
                resultArray[statusArray[i]] = ENUM_BASIS_STATUS_basic;
            else
                resultArray[-1 - statusArray[i]] = ENUM_BASIS_STATUS_basic;
        }
        delete [] statusArray;
        statusArray = NULL;
        nCopied += n;
    }
    
    if (this->atLower != NULL)
    {
        n = this->atLower->getNumberOfEl();
        statusArray = new int[n];
        this->atLower->getEl(statusArray);
        for (i=0; i < n; i++)
        {
            if (!flipIdx)
                resultArray[statusArray[i]] = ENUM_BASIS_STATUS_atLower;
            else
                resultArray[-1 - statusArray[i]] = ENUM_BASIS_STATUS_atLower;
        }
        delete [] statusArray;
        nCopied += n;
    }
    
    if (this->atUpper != NULL)
    {
        n = this->atUpper->getNumberOfEl();
        statusArray = new int[n];
        this->atUpper->getEl(statusArray);
        for (i=0; i < n; i++)
        {
            if (!flipIdx)
                resultArray[statusArray[i]] = ENUM_BASIS_STATUS_atUpper;
            else
                resultArray[-1 - statusArray[i]] = ENUM_BASIS_STATUS_atUpper;
        }
        delete [] statusArray;
        nCopied += n;
    }
    
    if (this->atEquality != NULL)
    {
        n = this->atEquality->getNumberOfEl();
        statusArray = new int[n];
        this->atEquality->getEl(statusArray);
        for (i=0; i < n; i++)
        {
            if (!flipIdx)
                resultArray[statusArray[i]] = ENUM_BASIS_STATUS_atEquality;
            else
                resultArray[-1 - statusArray[i]] = ENUM_BASIS_STATUS_atEquality;
        }
        delete [] statusArray;
        nCopied += n;
    }
    
    if (this->isFree != NULL)
    {
        n = this->isFree->getNumberOfEl();
        statusArray = new int[n];
        this->isFree->getEl(statusArray);
        for (i=0; i < n; i++)
        {
            if (!flipIdx)
                resultArray[statusArray[i]] = ENUM_BASIS_STATUS_isFree;
            else
                resultArray[-1 - statusArray[i]] = ENUM_BASIS_STATUS_isFree;
        }
        delete [] statusArray;
        nCopied += n;
    }
    
    if (this->superbasic != NULL)
    {
        n = this->superbasic->getNumberOfEl();
        statusArray = new int[n];
        this->superbasic->getEl(statusArray);
        for (i=0; i < n; i++)
        {
            if (!flipIdx)
                resultArray[statusArray[i]] = ENUM_BASIS_STATUS_superbasic;
            else
                resultArray[-1 - statusArray[i]] = ENUM_BASIS_STATUS_superbasic;
        }
        delete [] statusArray;
        nCopied += n;
    }
    
    if (this->unknown != NULL)
    {
        n = this->unknown->getNumberOfEl();
        statusArray = new int[n];
        this->unknown->getEl(statusArray);
        for (i=0; i < n; i++)
        {
            if (!flipIdx)
                resultArray[statusArray[i]] = ENUM_BASIS_STATUS_unknown;
            else
                resultArray[-1 - statusArray[i]] = ENUM_BASIS_STATUS_unknown;
        }
        delete [] statusArray;
        nCopied += n;
    }
    return nCopied;
}//getBasisDense

bool BasisStatus::IsEqual(BasisStatus *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_debug, "Start comparing in BasisStatus");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_debug, "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {

#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_debug, "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (      !this->basic->IsEqual(that->basic)      ) return false;
            if (    !this->atLower->IsEqual(that->atLower)    ) return false;
            if (    !this->atUpper->IsEqual(that->atUpper)    ) return false;
            if ( !this->atEquality->IsEqual(that->atEquality) ) return false;
            if (     !this->isFree->IsEqual(that->isFree)     ) return false;
            if ( !this->superbasic->IsEqual(that->superbasic) ) return false;
            if (    !this->unknown->IsEqual(that->unknown)    ) return false;

            return true;
        }
    }
}//BasisStatus::IsEqual

bool BasisStatus::setRandom(double density, bool conformant, int iMin, int iMax)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "Set random BasisStatus");
#endif
    if (OSRand() <= density)
    {
        this->basic = new IntVector();
        this->basic->setRandom(density, conformant, iMin, iMax);
    }
    if (OSRand() <= density)
    {
        this->atLower = new IntVector();
        this->atLower->setRandom(density, conformant, iMin, iMax);
    }
    if (OSRand() <= density)
    {
        this->atUpper = new IntVector();
        this->atUpper->setRandom(density, conformant, iMin, iMax);
    }
    if (OSRand() <= density)
    {
        this->atEquality = new IntVector();
        this->atEquality->setRandom(density, conformant, iMin, iMax);
    }
    if (OSRand() <= density)
    {
        this->isFree = new IntVector();
        this->isFree->setRandom(density, conformant, iMin, iMax);
    }
    if (OSRand() <= density)
    {
        this->superbasic = new IntVector();
        this->superbasic->setRandom(density, conformant, iMin, iMax);
    }
    if (OSRand() <= density)
    {
        this->unknown = new IntVector();
        this->unknown->setRandom(density, conformant, iMin, iMax);
    }

    return true;
}//BasisStatus::setRandom

bool BasisStatus::deepCopyFrom(BasisStatus *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of BasisStatus");
#endif
    if (that->basic != NULL)
    {
        this->basic = new IntVector();
        if (!this->basic->deepCopyFrom(that->basic))
            return false;
    }
    if (that->atLower != NULL)
    {
        this->atLower = new IntVector();
        if (!this->atLower->deepCopyFrom(that->atLower))
            return false;
    }
    if (that->atUpper != NULL)
    {
        this->atUpper = new IntVector();
        if (!this->atUpper->deepCopyFrom(that->atUpper))
            return false;
    }
    if (that->atEquality != NULL)
    {
        this->atEquality = new IntVector();
        if (!this->atEquality->deepCopyFrom(that->atEquality))
            return false;
    }
    if (that->isFree != NULL)
    {
        this->isFree = new IntVector();
        if (!this->isFree->deepCopyFrom(that->isFree))
            return false;
    }
    if (that->superbasic != NULL)
    {
        this->superbasic = new IntVector();
        if (!this->superbasic->deepCopyFrom(that->superbasic))
            return false;
    }
    if (that->unknown != NULL)
    {
        this->unknown = new IntVector();
        if (!this->unknown->deepCopyFrom(that->unknown))
            return false;
    }

    return true;
}//BasisStatus::deepCopyFrom

StorageCapacity::StorageCapacity():
    unit("byte"),
    description(""),
    value(0.0)
{
}// end StorageCapacity constructor

StorageCapacity::~StorageCapacity()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "inside StorageCapacity destructor");
#endif
}// end StorageCapacity destructor

bool StorageCapacity::IsEqual(StorageCapacity *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_debug, "Start comparing in StorageCapacity");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_debug, "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_debug, "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if ( (this->unit        != that->unit)        ||
                 (this->description != that->description) ||
                 !isEqual(this->value, that->value))
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "unit: "        << this->unit        << " vs. " << that->unit        << endl;
                outStr << "description: " << this->description << " vs. " << that->description << endl;
                outStr << "value: "       << this->value       << " vs. " << that->value       << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            return true;
        }
    }
}// end of StorageCapacity::IsEqual

bool StorageCapacity::setRandom(double density, bool conformant)
{
    if (OSRand() <= density)
    {
        double temp = OSRand();
        if (conformant) temp = 0.5*temp;

        if      (temp <= 0.25) this->unit = "byte";
        else if (temp <= 0.50) this->unit = "megabyte";
        else if (temp <= 0.75) this->unit = "";
        else                   this->unit = "overbyte";
    }
    if (OSRand() <= density) this->description   = "random string";
    if (OSRand() <= density)
    {
        if (OSRand() <= 0.5) this->value = 3.14156;
        else                 this->value = 2.71828;
    }
    return true;
}// end of StorageCapacity::setRandom

bool StorageCapacity::deepCopyFrom(StorageCapacity *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of StorageCapacity");
#endif
    this->unit        = that->unit;
    this->description = that->description;
    this->value       = that->value;
    return true;
}// end of StorageCapacity::deepCopyFrom

CPUSpeed::CPUSpeed():
    unit("hertz"),
    description(""),
    value(0.0)
{
}// end CPUSpeed constructor

CPUSpeed::~CPUSpeed()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "inside CPUSpeed destructor");
#endif
}// end CPUSpeed destructor

bool CPUSpeed::IsEqual(CPUSpeed *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_debug, "Start comparing in CPUSpeed");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_debug, "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if ((this->unit        != that->unit)        ||
                (this->description != that->description) ||
                !isEqual(this->value, that->value))
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "unit: "        << this->unit        << " vs. " << that->unit        << endl;
                outStr << "description: " << this->description << " vs. " << that->description << endl;
                outStr << "value: "       << this->value       << " vs. " << that->value       << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            return true;
        }
    }
}// end of CPUSpeed::IsEqual

bool CPUSpeed::setRandom(double density, bool conformant)
{
    if (OSRand() <= density)
    {
        double temp = OSRand();
        if (conformant) temp = 0.5*temp;

        if      (temp <= 0.25) this->unit = "hertz";
        else if (temp <= 0.50) this->unit = "gigaflops";
        else if (temp <= 0.75) this->unit = "";
        else                   this->unit = "bellyflops";
    }
    if (OSRand() <= density) this->description   = "random string";
    if (OSRand() <= density)
    {
        if (OSRand() <= 0.5) this->value = 3.14156;
        else                 this->value = 2.71828;
    }
    return true;
}// end of CPUSpeed::setRandom

bool CPUSpeed::deepCopyFrom(CPUSpeed *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of CPUSpeed");
#endif
    this->unit        = that->unit;
    this->description = that->description;
    this->value       = that->value;
    return true;
}// end of CPUSpeed::deepCopyFrom

CPUNumber::CPUNumber():
    description(""),
    value(0)
{
}// end CPUNumber constructor

CPUNumber::~CPUNumber()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "inside CPUNumber destructor");
#endif
}// end CPUNumber destructor

bool CPUNumber::IsEqual(CPUNumber *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_debug, "Start comparing in CPUNumber");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "Second object is NULL, first is not");
#endif
            return false;
        }
        else

        {
            if ((this->description != that->description) ||
                    (this->value       != that->value))
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "description: " << this->description << " vs. " << that->description << endl;
                outStr << "value: "       << this->value       << " vs. " << that->value       << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            return true;
        }
    }
}// end of CPUNumber::IsEqual

bool CPUNumber::setRandom(double density, bool conformant)
{
    if (OSRand() <= density) this->description = "random string";
    if (OSRand() <= density) this->value = (int)(4*OSRand());
    return true;
}// end of CPUNumber::setRandom

bool CPUNumber::deepCopyFrom(CPUNumber *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of CPUNumber");
#endif
    this->description = that->description;
    this->value       = that->value;
    return true;
}// end of CPUNumber::deepCopyFrom


TimeSpan::TimeSpan():
    unit("second"),
    value(0.0)
{
}// end TimeSpan constructor

TimeSpan::~TimeSpan()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "inside TimeSpan destructor");
#endif
}// end TimeSpan destructor

bool TimeSpan::IsEqual(TimeSpan *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_debug, "Start comparing in TimeSpan");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (!isEqual(this->value,  that->value) ||
                    this->unit != that->unit )

            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "unit: "  << this->unit  << " vs. " << that->unit  << endl;
                outStr << "value: " << this->value << " vs. " << that->value << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            return true;
        }
    }
}// end of TimeSpan::IsEqual

bool TimeSpan::setRandom(double density, bool conformant)
{
    if (OSRand() <= density)
    {
        double temp = OSRand();
        if (conformant) temp = 0.5*temp;

        if      (temp <= 0.25) this->unit = "second";
        else if (temp <= 0.50) this->unit = "tick";
        else if (temp <= 0.75) this->unit = "";
        else                   this->unit = "flea";
    }
    if (OSRand() <= density)
    {
        if (OSRand() <= 0.5) this->value = 3.14156;
        else                 this->value = 2.71828;
    }
    return true;
}// end of TimeSpan::setRandom

bool TimeSpan::deepCopyFrom(TimeSpan *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of TimeSpan");
#endif
    this->unit        = that->unit;
    this->value       = that->value;
    return true;
}// end of TimeSpan::deepCopyFrom

MatrixType::MatrixType():
    baseMatrix(NULL),
    matrixConstructor(NULL)
{
}

MatrixType::~MatrixType()
{
    if (baseMatrix != NULL)
        delete baseMatrix;
    baseMatrix = NULL;
}


OSMatrix::OSMatrix():
    numberOfRows(0),
    numberOfColumns(0),
    idx(-1),
    name("")
{
}// end of OSMatrix

OSMatrix::~OSMatrix()
{
}// end of ~OSMatrix


BaseMatrix::BaseMatrix():
    baseMatrixIdx(-1),
    targetMatrixFirstRow(0),
    targetMatrixFirstCol(0),
    baseMatrixStartRow(0),
    baseMatrixStartCol(0),
    baseMatrixEndRow(-1),
    baseMatrixEndCol(-1),
    baseTranspose(false),
    scalarMultiplier(1.0)
{
} // end of BaseMatrix

BaseMatrix::~BaseMatrix()
{
} // end of ~BaseMatrix

