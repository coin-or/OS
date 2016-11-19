/* $Id: OSGeneral.cpp 3186 2010-02-06 23:38:35Z Gassmann $ */
/** @file OSGeneral.cpp
 *
 * @author Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2014, Horand Gassmann, Jun Ma, Kipp Martin,
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
#include "OSgLWriter.h"

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
    if(    bDeleteArrays == true)
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
    if(    bDeleteArrays == true)
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
    if(    bDeleteArrays == true)
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
//    if (this == NULL)
//        this = new IntVector();

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
    if (this == NULL || this->numberOfEl == 0)
    {
        if (that == NULL || that->numberOfEl == 0)
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
        if (that == NULL || that->numberOfEl == 0)
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

    if (conformant)    n = this->numberOfEl;
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
    if(    bDeleteArrays == true)
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
    if (this == NULL || this-numberOfEl == 0)
    {
        if (that == NULL || that-numberOfEl == 0)
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
        if (that == NULL || that-numberOfEl == 0)
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
                if (!OSIsEqual(this->el[i], that->el[i]))
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
                 !OSIsEqual(this->value, that->value))
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
                !OSIsEqual(this->value, that->value))
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
            if (!OSIsEqual(this->value,  that->value) ||
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
//            else delete[] this->basic;
        return this->basic->setIntVector(i, ni);
    }
    case ENUM_BASIS_STATUS_atLower:
    {
        if (this->atLower == NULL) this->atLower = new IntVector(ni);
//            else delete[] this->atLower;
        return this->atLower->setIntVector(i, ni);
    }
    case ENUM_BASIS_STATUS_atUpper:
    {
        if (this->atUpper == NULL) this->atUpper = new IntVector(ni);
//            else delete[] this->atUpper;
        return this->atUpper->setIntVector(i, ni);
    }
    case ENUM_BASIS_STATUS_atEquality:
    {
        if (this->atEquality == NULL) this->atEquality = new IntVector(ni);
//            else delete[] this->atEquality;
        return this->atEquality->setIntVector(i, ni);
    }
    case ENUM_BASIS_STATUS_isFree:
    {
        if (this->isFree == NULL) this->isFree = new IntVector(ni);
//            else delete[] this->isFree;
        return this->isFree->setIntVector(i, ni);
    }
    case ENUM_BASIS_STATUS_superbasic:
    {
        if (this->superbasic == NULL) this->superbasic = new IntVector(ni);
//            else delete[] this->superbasic;
        return this->superbasic->setIntVector(i, ni);
    }
    case ENUM_BASIS_STATUS_unknown:
    {
        if (this->unknown == NULL) this->unknown = new IntVector(ni);
//            else delete[] this->unknown;
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
        else return    this->basic->numberOfEl;
    }
    case ENUM_BASIS_STATUS_atLower:
    {
        if (this->atLower == NULL) return -1;
        else return    this->atLower->numberOfEl;
    }
    case ENUM_BASIS_STATUS_atUpper:
    {
        if (this->atUpper == NULL) return -1;
        else return    this->atUpper->numberOfEl;
    }
    case ENUM_BASIS_STATUS_atEquality:
    {
        if (this->atEquality == NULL) return -1;
        else return    this->atEquality->numberOfEl;
    }
    case ENUM_BASIS_STATUS_isFree:
    {
        if (this->isFree == NULL) return -1;
        else return    this->isFree->numberOfEl;
    }
    case ENUM_BASIS_STATUS_superbasic:
    {
        if (this->superbasic == NULL) return -1;
        else return    this->superbasic->numberOfEl;
    }
    case ENUM_BASIS_STATUS_unknown:
    {
        if (this->unknown == NULL) return -1;
        else return    this->unknown->numberOfEl;
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
        else return    this->basic->el[j];
    }
    case ENUM_BASIS_STATUS_atLower:
    {
        if (this->atLower == NULL)
            throw ErrorClass("\"atLower\" index array never defined in routine BasisStatus::getEl()");
        else return    this->atLower->el[j];
    }
    case ENUM_BASIS_STATUS_atUpper:
    {
        if (this->atUpper == NULL)
            throw ErrorClass("\"atUpper\" index array never defined in routine BasisStatus::getEl()");
        else return    this->atUpper->el[j];
    }
    case ENUM_BASIS_STATUS_atEquality:
    {
        if (this->atEquality == NULL)
            throw ErrorClass("\"atEquality\" index array never defined in routine BasisStatus::getEl()");
        else return    this->atEquality->el[j];
    }
    case ENUM_BASIS_STATUS_isFree:
    {
        if (this->isFree == NULL)
            throw ErrorClass("\"isFree\" index array never defined in routine BasisStatus::getEl()");
        else return    this->isFree->el[j];
    }
    case ENUM_BASIS_STATUS_superbasic:
    {
        if (this->superbasic == NULL)
            throw ErrorClass("\"superbasic\" index array never defined in routine BasisStatus::getEl()");
        else return    this->superbasic->el[j];
    }
    case ENUM_BASIS_STATUS_unknown:
    {
        if (this->unknown == NULL)
            throw ErrorClass("\"unknown\" index array never defined in routine BasisStatus::getEl()");
        else return    this->unknown->el[j];
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


OtherOptionOrResultElementString::OtherOptionOrResultElementString():
    idx(-1),
    name(""),
    description(""),
    value(""),
//    valueType(""),
    lbValue(""),
//    lbValueType(""),
    ubValue("")
//    ubValueType("")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, 
        "Inside the OtherOptionOrResultElementString Constructor");
#endif
}

OtherOptionOrResultElementString::~OtherOptionOrResultElementString()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, 
        "Inside the OtherOptionOrResultElementString Destructor");
#endif
}

bool OtherOptionOrResultElementString::IsEqual(OtherOptionOrResultElementString *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug,
        "Start comparing in OtherOptionOrResultElementString");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if ((this->idx         != that->idx)         ||
                (this->name        != that->name)        ||
                (this->description != that->description) ||
                (this->value       != that->value)       ||
//                (this->valueType   != that->valueType)   ||
                (this->lbValue     != that->lbValue)     ||
//                (this->lbValueType != that->lbValueType) ||
                (this->ubValue     != that->ubValue)     )    // ||
//                (this->ubValueType != that->ubValueType)   )
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "idx: "         << this->idx         << " vs. " << that->idx         << endl;
                outStr << "name: "        << this->name        << " vs. " << that->name        << endl;
                outStr << "description: " << this->description << " vs. " << that->description << endl;
                outStr << "value: "       << this->value       << " vs. " << that->value       << endl;
//                outStr << "valueType: "   << this->valueType   << " vs. " << that->valueType   << endl;
                outStr << "lbValue: "     << this->lbValue     << " vs. " << that->lbValue     << endl;
//                outStr << "lbValueType: " << this->lbValueType << " vs. " << that->lbValueType << endl;
                outStr << "ubValue: "     << this->ubValue     << " vs. " << that->ubValue     << endl;
//                outStr << "ubValueType: " << this->ubValueType << " vs. " << that->ubValueType << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            return true;
        }
    }
}//OtherOptionOrResultElementString::IsEqual

bool OtherOptionOrResultElementString::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Set random OtherOptionOrResultElementString");
#endif
    if (OSRand() <= density || conformant) this->idx = 17;
    if (OSRand() <= density) this->name        = "random string";
    if (OSRand() <= density) this->description = "random string";
    if (OSRand() <= density) this->value       = "random string";
//    if (OSRand() <= density) this->valueType   = "random string";
    if (OSRand() <= density) this->lbValue     = "random string";
//    if (OSRand() <= density) this->lbValueType = "random string";
    if (OSRand() <= density) this->ubValue     = "random string";
//    if (OSRand() <= density) this->ubValueType = "random string";
    return true;
}//OtherOptionOrResultElementString::setRandom

bool OtherOptionOrResultElementString::deepCopyFrom(OtherOptionOrResultElementString *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Make deep copy of OtherOptionOrResultElementString");
#endif
    this->idx         = that->idx;
    this->name        = that->name;
    this->description = that->description;
    this->value       = that->value;
//    this->valueType   = that->valueType;
    this->lbValue     = that->lbValue;
//    this->lbValueType = that->lbValueType;
    this->ubValue     = that->ubValue;
//    this->ubValueType = that->ubValueType;
    return true;
}//OtherOptionOrResultElementString::deepCopyFrom


OtherObjOptionOrResultElementString::OtherObjOptionOrResultElementString():
    idx(0),
    name(""),
    description(""),
    value(""),
//    valueType(""),
    constantValue(""),
//    constantValueType(""),
    weightValue("")
//    weightValueType("")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, 
        "Inside the OtherObjOptionOrResultElementString Constructor");
#endif
}

OtherObjOptionOrResultElementString::~OtherObjOptionOrResultElementString()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, 
        "Inside the OtherObjOptionOrResultElementString Destructor");
#endif
}

bool OtherObjOptionOrResultElementString::IsEqual(OtherObjOptionOrResultElementString *that)
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug,
        "Start comparing in OtherObjOptionOrResultElementString");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if ((this->idx               != that->idx)               ||
                (this->name              != that->name)              ||
                (this->description       != that->description)       ||
                (this->value             != that->value)             ||
//                (this->valueType         != that->valueType)         ||
                (this->constantValue     != that->constantValue)     ||
//                (this->constantValueType != that->constantValueType) ||
                (this->weightValue       != that->weightValue)      )   // ||
//                (this->weightValueType   != that->weightValueType)     )
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "idx: "
                       << this->idx               << " vs. " << that->idx               << endl;
                outStr << "name: "
                       << this->name              << " vs. " << that->name              << endl;
                outStr << "description: "
                       << this->description       << " vs. " << that->description       << endl;
                outStr << "value: "
                       << this->value             << " vs. " << that->value             << endl;
//                outStr << "valueType: "
//                       << this->valueType         << " vs. " << that->valueType         << endl;
                outStr << "constantValue: "
                       << this->constantValue     << " vs. " << that->constantValue     << endl;
//                outStr << "constantValueType: "
//                       << this->constantValueType << " vs. " << that->constantValueType << endl;
                outStr << "weightValue: "
                       << this->weightValue       << " vs. " << that->weightValue       << endl;
//                outStr << "weightValueType: "
//                       << this->weightValueType   << " vs. " << that->weightValueType   << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            return true;
        }
    }
}//OtherObjOptionOrResultElementString::IsEqual

bool OtherObjOptionOrResultElementString::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Set random OtherObjOptionOrResultElementString");
#endif
    if (OSRand() <= density || conformant) this->idx = -3;
    if (OSRand() <= density) this->name              = "random string";
    if (OSRand() <= density) this->description       = "random string";
    if (OSRand() <= density) this->value             = "random string";
//    if (OSRand() <= density) this->valueType         = "random string";
    if (OSRand() <= density) this->constantValue     = "random string";
//    if (OSRand() <= density) this->constantValueType = "random string";
    if (OSRand() <= density) this->weightValue       = "random string";
//    if (OSRand() <= density) this->weightValueType   = "random string";
    return true;

}//OtherObjOptionOrResultElementString::setRandom


bool OtherObjOptionOrResultElementString::deepCopyFrom(OtherObjOptionOrResultElementString *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Make deep copy of OtherObjOptionOrResultElementString");
#endif
    this->idx               = that->idx;
    this->name              = that->name;
    this->description       = that->description;
    this->value             = that->value;
//    this->valueType         = that->valueType;
    this->constantValue     = that->constantValue;
//    this->constantValueType = that->constantValueType;
    this->weightValue       = that->weightValue;
//    this->weightValueType   = that->weightValueType;
    return true;
}//OtherObjOptionOrResultElementString::deepCopyFrom


OtherOptionOrResultEnumeration::OtherOptionOrResultEnumeration():
    IntVector(),
    value(""),
    description("")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, 
        "Inside the OtherOptionOrResultEnumeration Constructor");
#endif
}

OtherOptionOrResultEnumeration::OtherOptionOrResultEnumeration(int n):
    IntVector(n),
    value(""),
    description("")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, 
        "Inside the alternate OtherOptionOrResultEnumeration Constructor");
#endif
}

OtherOptionOrResultEnumeration::~OtherOptionOrResultEnumeration()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, 
        "Inside the OtherOptionOrResultEnumeration Destructor");
#endif
}

bool OtherOptionOrResultEnumeration::setOtherOptionOrResultEnumeration(std::string value, std::string description, int *i, int ni)
{
    this->value = value;
    this->description = description;
    return this->IntVector::setIntVector(i, ni);
}

std::string OtherOptionOrResultEnumeration::getValue()
{
    return this->value;
}

std::string OtherOptionOrResultEnumeration::getDescription()
{
    return this->description;
}


bool OtherOptionOrResultEnumeration::IsEqual(OtherOptionOrResultEnumeration *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_debug, "Start comparing in OtherOptionOrResultEnumeration");
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
}//OtherOptionOrResultEnumeration::IsEqual

bool OtherOptionOrResultEnumeration::setRandom(double density, bool conformant, int iMin, int iMax)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "Set random OtherOptionOrResultEnumeration");
#endif
    if (OSRand() <= density) this->value       = "random string";
    if (OSRand() <= density) this->description = "random string";

    if (OSRand() <= density) this->IntVector::setRandom(density,conformant,iMin,iMax);
    return true;
}//OtherOptionOrResultEnumeration::setRandom

bool OtherOptionOrResultEnumeration::deepCopyFrom(OtherOptionOrResultEnumeration *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of OtherOptionOrResultEnumeration");
#endif
    this->value       = that->value;
    this->description = that->description;

    if (!this->IntVector::deepCopyFrom(that))
        return false;

    return true;
}//OtherOptionOrResultEnumeration::deepCopyFrom


OtherVariableOptionOrResult::OtherVariableOptionOrResult():
    name (""),
    description (""),
    value (""),
    type (""),
    solver(""),
    category (""),
    numberOfEnumerations(0),
    enumType (""),
    numberOfVar(0),
    varType("")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Inside OtherVariableOptionOrResult Constructor");
#endif
    var = NULL;
    enumeration = NULL;
}// end OtherVariableOptionOrResult constructor

OtherVariableOptionOrResult::~OtherVariableOptionOrResult()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "OtherVariableOptionOrResult Destructor Called");
#endif
    if (numberOfVar > 0)
        if (var != NULL)
        {
            for (int i=0; i< numberOfVar; ++i)
                if (var[i] != NULL)
                    delete var[i];
            delete [] var;
            var = NULL;
        }

    if (numberOfEnumerations > 0)
        if (enumeration != NULL)
        {
            for (int i=0; i< numberOfEnumerations; ++i)
                if (enumeration[i] != NULL)
                    delete enumeration[i];
            delete [] var;
            enumeration = NULL;
        }
}//end OtherVariableOptionOrResult destructor


bool OtherVariableOptionOrResult::IsEqual(OtherVariableOptionOrResult *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug,
        "Start comparing in OtherVariableOptionOrResult");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if ((this->name                 != that->name)        ||
                (this->description          != that->description) ||
                (this->value                != that->value)       ||
                (this->type                 != that->type)        ||
                (this->solver               != that->solver)      ||
                (this->category             != that->category)    ||
                (this->enumType             != that->enumType)    || 
                (this->varType              != that->varType)      )
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "name: "        << this->name        << " vs. " << that->name        << endl;
                outStr << "description: " << this->description << " vs. " << that->description << endl;
                outStr << "value: "       << this->value       << " vs. " << that->value       << endl;
                outStr << "type: "        << this->type        << " vs. " << that->type        << endl;
                outStr << "solver: "      << this->solver      << " vs. " << that->solver      << endl;
                outStr << "category: "    << this->category    << " vs. " << that->category    << endl;
                outStr << "enumType: "    << this->enumType    << " vs. " << that->enumType    << endl;
                outStr << "varType: "     << this->varType     << " vs. " << that->varType     << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }

            if (this->numberOfVar != that->numberOfVar)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "numberOfVar: " << this->numberOfVar << " vs. " << that->numberOfVar << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            int i;
            for (i = 0; i < numberOfVar; i++)
                if (!this->var[i]->IsEqual(that->var[i]))
                    return false;

            if (this->numberOfEnumerations != that->numberOfEnumerations)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "numberOfEnumerations: " << this->numberOfEnumerations << " vs. " << that->numberOfEnumerations << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            for (i = 0; i < numberOfEnumerations; i++)
                if (!this->enumeration[i]->IsEqual(that->enumeration[i]))
                    return false;
            return true;
        }
    }
}//OtherVariableOptionOrResult::IsEqual

bool OtherVariableOptionOrResult::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Set random OtherVariableOptionOrResult");
#endif
    this->name = "random string";
    if (OSRand() <= density) this->description = "random string";
    if (OSRand() <= density) this->value       = "random string";
    if (OSRand() <= density) this->type        = "random string";
    if (OSRand() <= density) this->solver      = "random string";
    if (OSRand() <= density) this->category    = "random string";
    if (OSRand() <= density) this->enumType    = "random string";
    if (OSRand() <= density) this->varType     = "random string";

    if (OSRand() <= density)
    {
        if (OSRand() <= 0.5)
        {
            this->numberOfVar = (int)(4*OSRand());

            int n;

            if (conformant) n = this->numberOfVar;
            else            n = (int)(4*OSRand());

            var = new OtherOptionOrResultElementString*[n];
            for (int i = 0; i < n; i++)
            {
                var[i] = new OtherOptionOrResultElementString();
                var[i]->setRandom(density, conformant);
            }
        }
        else
        {
            this->numberOfEnumerations = (int)(4*OSRand());

            int n;

            if (conformant) n = this->numberOfEnumerations;
            else            n = (int)(4*OSRand());

            enumeration = new OtherOptionOrResultEnumeration*[n];
            for (int i = 0; i < n; i++)
            {
                enumeration[i] = new OtherOptionOrResultEnumeration();
                enumeration[i]->setRandom(density, conformant, 0, 9);
            }
        }
    }
    return true;
}//OtherVariableOptionOrResult::setRandom


bool OtherVariableOptionOrResult::deepCopyFrom(OtherVariableOptionOrResult *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Make deep copy of OtherVariableOptionOrResult");
#endif
    this->name        = that->name;
    this->description = that->description;
    this->value       = that->value;
    this->type        = that->type;
    this->solver      = that->solver;
    this->category    = that->category;
    this->enumType    = that->enumType;
    this->varType     = that->varType;

    int n;
    this->numberOfVar = that->numberOfVar;
    n = this->numberOfVar;

    if (n < 0) return false;
    if (n > 0) 
    {
        this->var = new OtherOptionOrResultElementString*[n];
        for (int i = 0; i < n; i++)
        {
            this->var[i] = new OtherOptionOrResultElementString();
            if (!this->var[i]->deepCopyFrom(that->var[i]))
                return false;
        }
    }

    this->numberOfEnumerations = that->numberOfEnumerations;
    n = this->numberOfEnumerations;

    if (n  < 0) return false;
    if (n == 0) return true;

    this->enumeration = new OtherOptionOrResultEnumeration*[n];
    for (int i = 0; i < n; i++)
    {
        this->enumeration[i] = new OtherOptionOrResultEnumeration();
        if (!this->enumeration[i]->deepCopyFrom(that->enumeration[i]))
            return false;
    }
    return true;
}//OtherVariableOptionOrResult::deepCopyFrom


OtherObjectiveOptionOrResult::OtherObjectiveOptionOrResult():
    name (""),
    description (""),
    value (""),
    type (""),
    solver(""),
    category (""),
    numberOfEnumerations(0),
    enumType (""),
    numberOfObj(0),
    objType ("")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Inside OtherObjectiveOptionOrResult Constructor");
#endif
    obj = NULL;
    enumeration = NULL;
}// end OtherObjectiveOptionOrResult constructor

OtherObjectiveOptionOrResult::~OtherObjectiveOptionOrResult()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "OtherObjectiveOptionOrResult Destructor Called");
#endif
    if (numberOfObj > 0)
        if (obj != NULL)
        {
            for (int i=0; i< numberOfObj; ++i)
                if (obj[i] != NULL)
                    delete obj[i];
            delete [] obj;
            obj = NULL;
        }

    if (numberOfEnumerations > 0)
        if (enumeration != NULL)
        {
            for (int i=0; i< numberOfEnumerations; ++i)
                if (enumeration[i] != NULL)
                    delete enumeration[i];
            delete [] enumeration;
            enumeration = NULL;
        }
}//end OtherObjectiveOptionOrResult destructor


bool OtherObjectiveOptionOrResult::IsEqual(OtherObjectiveOptionOrResult *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug,
        "Start comparing in OtherObjectiveOptionOrResult");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if ((this->name                 != that->name)        ||
                (this->description          != that->description) ||
                (this->value                != that->value)       ||
                (this->type                 != that->type)        ||
                (this->solver               != that->solver)      ||
                (this->category             != that->category)    ||
                (this->enumType             != that->enumType)    ||
                (this->objType              != that->objType)      )
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "name: "        << this->name        << " vs. " << that->name        << endl;
                outStr << "description: " << this->description << " vs. " << that->description << endl;
                outStr << "value: "       << this->value       << " vs. " << that->value       << endl;
                outStr << "type: "        << this->type        << " vs. " << that->type        << endl;
                outStr << "solver: "      << this->solver      << " vs. " << that->solver      << endl;
                outStr << "category: "    << this->category    << " vs. " << that->category    << endl;
                outStr << "enumType: "    << this->enumType    << " vs. " << that->enumType    << endl;
                outStr << "objType: "     << this->objType     << " vs. " << that->objType     << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }

            if (this->numberOfObj != that->numberOfObj)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "numberOfObj: " << this->numberOfObj << " vs. " << that->numberOfObj << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }

            int i;

            for (i = 0; i < numberOfObj; i++)
                if (!this->obj[i]->IsEqual(that->obj[i]))
                    return false;

            if (this->numberOfEnumerations != that->numberOfEnumerations)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "numberOfEnumerations: "
                       << this->numberOfEnumerations << " vs. " << that->numberOfEnumerations << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }

            for (i = 0; i < numberOfEnumerations; i++)
                if (!this->enumeration[i]->IsEqual(that->enumeration[i]))
                    return false;
            return true;
        }
    }
}//OtherObjectiveOptionOrResult::IsEqual


bool OtherObjectiveOptionOrResult::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Set random OtherObjectiveOptionOrResult");
#endif
    this->name = "random string";
    if (OSRand() <= density) this->description = "random string";
    if (OSRand() <= density) this->value       = "random string";
    if (OSRand() <= density) this->type        = "random string";
    if (OSRand() <= density) this->solver      = "random string";
    if (OSRand() <= density) this->category    = "random string";
    if (OSRand() <= density) this->enumType    = "random string";
    if (OSRand() <= density) this->objType     = "random string";

    if (OSRand() <= density)
    {
        if (OSRand() <= 0.5)
        {
            this->numberOfObj = (int)(4*OSRand());

            int n;

            if (conformant) n = this->numberOfObj;
            else            n = (int)(4*OSRand());

            obj = new OtherObjOptionOrResultElementString*[n];

            for (int i = 0; i < n; i++)
            {
                obj[i] = new OtherObjOptionOrResultElementString();
                obj[i]->setRandom(density, conformant);
            }
        }
        else
        {
            this->numberOfEnumerations = (int)(4*OSRand());

            int n;

            if (conformant) n = this->numberOfEnumerations;
            else            n = (int)(4*OSRand());

            enumeration = new OtherOptionOrResultEnumeration*[n];

            for (int i = 0; i < n; i++)
            {
                enumeration[i] = new OtherOptionOrResultEnumeration();
                enumeration[i]->setRandom(density, conformant, 0, 9);
            }
        }
    }
    return true;
}//OtherObjectiveOptionOrResult::setRandom


bool OtherObjectiveOptionOrResult::deepCopyFrom(OtherObjectiveOptionOrResult *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Make deep copy of OtherObjectiveOptionOrResult");
#endif
    this->name        = that->name;
    this->description = that->description;
    this->value       = that->value;
    this->type        = that->type;
    this->solver      = that->solver;
    this->category    = that->category;
    this->enumType    = that->enumType;
    this->objType     = that->objType;

    int n;

    this->numberOfObj = that->numberOfObj;

    n = this->numberOfObj;

    if (n < 0) return false;
    if (n > 0) 
    {
        this->obj = new OtherObjOptionOrResultElementString*[n];

        for (int i = 0; i < n; i++)
        {
            this->obj[i] = new OtherObjOptionOrResultElementString();

            if (!this->obj[i]->deepCopyFrom(that->obj[i]))
                return false;
        }
    }
    this->numberOfEnumerations = that->numberOfEnumerations;

    n = this->numberOfEnumerations;

    if (n  < 0) return false;
    if (n == 0) return true;

    this->enumeration = new OtherOptionOrResultEnumeration*[n];

    for (int i = 0; i < n; i++)
    {
        this->enumeration[i] = new OtherOptionOrResultEnumeration();
        if (!this->enumeration[i]->deepCopyFrom(that->enumeration[i]))
            return false;
    }
    return true;
}//OtherObjectiveOptionOrResult::deepCopyFrom


OtherConstraintOptionOrResult::OtherConstraintOptionOrResult():
    name (""),
    description (""),
    value (""),
    type (""),
    solver(""),
    category (""),
    numberOfEnumerations(0),
    enumType (""),
    numberOfCon(0),
    conType ("")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Inside OtherConstraintOptionOrResult Constructor");
#endif
    con = NULL;
    enumeration = NULL;
}// end OtherConstraintOptionOrResult constructor

OtherConstraintOptionOrResult::~OtherConstraintOptionOrResult()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "OtherConstraintOptionOrResult Destructor Called");
#endif
    if (numberOfCon > 0)
        if (con != NULL)
        {
            for (int i=0; i< numberOfCon; ++i)
                if (con[i] != NULL)
                    delete con[i];
            delete [] con;
            con = NULL;
        }

    if (numberOfEnumerations > 0)
        if (enumeration != NULL)
        {
            for (int i=0; i< numberOfEnumerations; ++i)
                if (enumeration[i] != NULL)
                    delete enumeration[i];
            delete [] enumeration;
            enumeration = NULL;
        }
}//end OtherConstraintOptionOrResult destructor


bool OtherConstraintOptionOrResult::IsEqual(OtherConstraintOptionOrResult *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug,
        "Start comparing in OtherConstraintOptionOrResult");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if ((this->name                 != that->name)        ||
                (this->description          != that->description) ||
                (this->value                != that->value)       ||
                (this->type                 != that->type)        ||
                (this->solver               != that->solver)      ||
                (this->category             != that->category)    ||
                (this->enumType             != that->enumType)    ||
                (this->conType              != that->conType)      )
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "name: "        << this->name        << " vs. " << that->name        << endl;
                outStr << "description: " << this->description << " vs. " << that->description << endl;
                outStr << "value: "       << this->value       << " vs. " << that->value       << endl;
                outStr << "type: "        << this->type        << " vs. " << that->type        << endl;
                outStr << "solver: "      << this->solver      << " vs. " << that->solver      << endl;
                outStr << "category: "    << this->category    << " vs. " << that->category    << endl;
                outStr << "enumType: "    << this->enumType    << " vs. " << that->enumType    << endl;
                outStr << "conType: "     << this->conType     << " vs. " << that->conType     << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }

            if (this->numberOfCon != that->numberOfCon)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "numberOfCon: " << this->numberOfCon << " vs. " << that->numberOfCon << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            int i;

            for (i = 0; i < numberOfCon; i++)
                if (!this->con[i]->IsEqual(that->con[i]))
                    return false;

            if (this->numberOfEnumerations != that->numberOfEnumerations)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "numberOfEnumerations: "
                       << this->numberOfEnumerations << " vs. " << that->numberOfEnumerations << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }

            for (i = 0; i < numberOfEnumerations; i++)
                if (!this->enumeration[i]->IsEqual(that->enumeration[i]))
                    return false;
            return true;
        }
    }
}//OtherConstraintOptionOrResult::IsEqual


bool OtherConstraintOptionOrResult::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Set random OtherConstraintOptionOrResult");
#endif
    this->name = "random string";
    if (OSRand() <= density) this->description = "random string";
    if (OSRand() <= density) this->value       = "random string";
    if (OSRand() <= density) this->type        = "random string";
    if (OSRand() <= density) this->solver      = "random string";
    if (OSRand() <= density) this->category    = "random string";
    if (OSRand() <= density) this->enumType    = "random string";
    if (OSRand() <= density) this->conType     = "random string";

    if (OSRand() <= density)
    {
        if (OSRand() <= 0.5)
        {
            this->numberOfCon = (int)(4*OSRand());

            int n;

            if (conformant) n = this->numberOfCon;
            else            n = (int)(4*OSRand());

            con = new OtherOptionOrResultElementString*[n];

            for (int i = 0; i < n; i++)
            {
                con[i] = new OtherOptionOrResultElementString();
                con[i]->setRandom(density, conformant);
            }
        }
        else
        {
            this->numberOfEnumerations = (int)(4*OSRand());

            int n;

            if (conformant) n = this->numberOfEnumerations;
            else            n = (int)(4*OSRand());

            enumeration = new OtherOptionOrResultEnumeration*[n];

            for (int i = 0; i < n; i++)
            {
                enumeration[i] = new OtherOptionOrResultEnumeration();
                enumeration[i]->setRandom(density, conformant, 0, 9);
            }
        }
    }
    return true;
}//OtherConstraintOptionOrResult::setRandom


bool OtherConstraintOptionOrResult::deepCopyFrom(OtherConstraintOptionOrResult *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Make deep copy of OtherConstraintOptionOrResult");
#endif
    this->name        = that->name;
    this->description = that->description;
    this->value       = that->value;
    this->type        = that->type;
    this->solver      = that->solver;
    this->category    = that->category;
    this->enumType    = that->enumType;
    this->conType     = that->conType;

    int n;

    this->numberOfCon = that->numberOfCon;

    n = this->numberOfCon;

    if (n < 0) return false;
    if (n > 0) 
    {
        this->con = new OtherOptionOrResultElementString*[n];

        for (int i = 0; i < n; i++)
        {
            this->con[i] = new OtherOptionOrResultElementString();

            if (!this->con[i]->deepCopyFrom(that->con[i]))
                return false;
        }
    }
    this->numberOfEnumerations = that->numberOfEnumerations;
    n = this->numberOfEnumerations;
    if (n  < 0) return false;
    if (n == 0) return true;
    this->enumeration = new OtherOptionOrResultEnumeration*[n];
    for (int i = 0; i < n; i++)
    {
        this->enumeration[i] = new OtherOptionOrResultEnumeration();
        if (!this->enumeration[i]->deepCopyFrom(that->enumeration[i]))
            return false;
    }
    return true;
}//OtherConstraintOptionOrResult::deepCopyFrom


OtherSOSOptionOrResult::OtherSOSOptionOrResult():
    idx(-1),
    name (""),
    description (""),
    value (""),
    type (""),
    numberOfEnumerations(0),
    enumType (""),
    numberOfVar(0),
    varType ("")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Inside OtherSOSOptionOrResult Constructor");
#endif
    var = NULL;
    enumeration = NULL;
}// end OtherSOSOptionOrResult constructor

OtherSOSOptionOrResult::~OtherSOSOptionOrResult()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "OtherSOSOptionOrResult Destructor Called");
#endif
    if (numberOfVar > 0)
        if (var != NULL)
        {
            for (int i=0; i< numberOfVar; ++i)
                if (var[i] != NULL)
                    delete var[i];
            delete [] var;
            var = NULL;
        }

    if (numberOfEnumerations > 0)
        if (enumeration != NULL)
        {
            for (int i=0; i< numberOfEnumerations; ++i)
                if (enumeration[i] != NULL)
                    delete enumeration[i];
            delete [] enumeration;
            enumeration = NULL;
        }
}//end OtherSOSOptionOrResult destructor


bool OtherSOSOptionOrResult::IsEqual(OtherSOSOptionOrResult *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug,
        "Start comparing in OtherSOSOptionOrResult");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if ((this->idx                  != that->idx)         ||
                (this->name                 != that->name)        ||
                (this->description          != that->description) ||
                (this->value                != that->value)       ||
                (this->type                 != that->type)        ||
                (this->enumType             != that->enumType)    ||
                (this->varType              != that->varType)      )
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "idx: "         << this->idx         << " vs. " << that->idx         << endl;
                outStr << "name: "        << this->name        << " vs. " << that->name        << endl;
                outStr << "description: " << this->description << " vs. " << that->description << endl;
                outStr << "value: "       << this->value       << " vs. " << that->value       << endl;
                outStr << "type: "        << this->type        << " vs. " << that->type        << endl;
                outStr << "enumType: "    << this->enumType    << " vs. " << that->enumType    << endl;
                outStr << "varType: "     << this->varType     << " vs. " << that->varType     << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            if (this->numberOfVar != that->numberOfVar)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "numberOfVar: " << this->numberOfVar << " vs. " << that->numberOfVar << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            int i;
            for (i = 0; i < numberOfVar; i++)
                if (!this->var[i]->IsEqual(that->var[i]))
                    return false;
            if (this->numberOfEnumerations != that->numberOfEnumerations)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "numberOfEnumerations: " << this->numberOfEnumerations << " vs. " << that->numberOfEnumerations << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            for (i = 0; i < numberOfEnumerations; i++)
                if (!this->enumeration[i]->IsEqual(that->enumeration[i]))
                    return false;
            return true;
        }
    }
}//OtherSOSOptionOrResult::IsEqual

bool OtherSOSOptionOrResult::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Set random OtherSOSOptionOrResult");
#endif
    this->idx = (int)(4*OSRand());
    if (OSRand() <= density) this->name        = "random string";
    if (OSRand() <= density) this->description = "random string";
    if (OSRand() <= density) this->value       = "random string";
    if (OSRand() <= density) this->type        = "random string";
    if (OSRand() <= density) this->enumType    = "random string";
    if (OSRand() <= density) this->varType     = "random string";
    if (OSRand() <= density)
    {
        if (OSRand() <= 0.5)
        {
            this->numberOfVar = (int)(4*OSRand());
            int n;
            if (conformant) n = this->numberOfVar;
            else            n = (int)(4*OSRand());
            var = new OtherOptionOrResultElementString*[n];
            for (int i = 0; i < n; i++)
            {
                var[i] = new OtherOptionOrResultElementString();
                var[i]->setRandom(density, conformant);
            }
        }
        else
        {
            this->numberOfEnumerations = (int)(4*OSRand());
            int n;
            if (conformant) n = this->numberOfEnumerations;
            else            n = (int)(4*OSRand());
            enumeration = new OtherOptionOrResultEnumeration*[n];
            for (int i = 0; i < n; i++)
            {
                enumeration[i] = new OtherOptionOrResultEnumeration();
                enumeration[i]->setRandom(density, conformant, 0, 9);
            }
        }
    }
    return true;
}//OtherSOSOptionOrResult::setRandom

bool OtherSOSOptionOrResult::deepCopyFrom(OtherSOSOptionOrResult *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Make deep copy of OtherSOSOptionOrResult");
#endif
    this->idx         = that->idx;
    this->name        = that->name;
    this->description = that->description;
    this->value       = that->value;
    this->type        = that->type;
    this->enumType    = that->enumType;
    this->varType     = that->varType;

    int n;

    this->numberOfVar = that->numberOfVar;
    n = this->numberOfVar;
    if (n < 0) return false;
    if (n > 0) 
    {
        this->var = new OtherOptionOrResultElementString*[n];
        for (int i = 0; i < n; i++)
        {
            this->var[i] = new OtherOptionOrResultElementString();
            if (!this->var[i]->deepCopyFrom(that->var[i]))
                return false;
        }
    }
    this->numberOfEnumerations = that->numberOfEnumerations;
    n = this->numberOfEnumerations;
    if (n  < 0) return false;
    if (n == 0) return true;
    this->enumeration = new OtherOptionOrResultEnumeration*[n];
    for (int i = 0; i < n; i++)
    {
        this->enumeration[i] = new OtherOptionOrResultEnumeration();
        if (!this->enumeration[i]->deepCopyFrom(that->enumeration[i]))
            return false;
    }
    return true;
}//OtherSOSOptionOrResult::deepCopyFrom


OtherSpecialOrderedSetsOptionOrResult::OtherSpecialOrderedSetsOptionOrResult():
    name (""),
    description (""),
    value (""),
    type (""),
    solver(""),
    category (""),
    numberOfEnumerations(0),
    enumType (""),
    numberOfSOS(0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Inside OtherSpecialOrderedSetsOptionOrResult Constructor");
#endif
    sos = NULL;
    enumeration = NULL;
}// end OtherSpecialOrderedSetsOptionOrResult constructor

OtherSpecialOrderedSetsOptionOrResult::~OtherSpecialOrderedSetsOptionOrResult()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "OtherSpecialOrderedSetsOptionOrResult Destructor Called");
#endif
    if (numberOfSOS> 0)
        if (sos != NULL)
        {
            for (int i=0; i< numberOfSOS; ++i)
                if (sos[i] != NULL)
                    delete sos[i];
            delete [] sos;
            sos = NULL;
        }

    if (numberOfEnumerations > 0)
        if (enumeration != NULL)
        {
            for (int i=0; i< numberOfEnumerations; ++i)
                if (enumeration[i] != NULL)
                    delete enumeration[i];
            delete [] enumeration;
            enumeration = NULL;
        }
}//end OtherSpecialOrderedSetsOptionOrResult destructor


bool OtherSpecialOrderedSetsOptionOrResult::IsEqual(OtherSpecialOrderedSetsOptionOrResult *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug,
        "Start comparing in OtherSpecialOrderedSetsOptionOrResult");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if ((this->name                 != that->name)        ||
                (this->description          != that->description) ||
                (this->value                != that->value)       ||
                (this->type                 != that->type)        ||
                (this->solver               != that->solver)      ||
                (this->category             != that->category)    ||
                (this->enumType             != that->enumType)      )
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "name: "        << this->name        << " vs. " << that->name        << endl;
                outStr << "description: " << this->description << " vs. " << that->description << endl;
                outStr << "value: "       << this->value       << " vs. " << that->value       << endl;
                outStr << "type: "        << this->type        << " vs. " << that->type        << endl;
                outStr << "solver: "      << this->solver      << " vs. " << that->solver      << endl;
                outStr << "category: "    << this->category    << " vs. " << that->category    << endl;
                outStr << "enumType: "    << this->enumType    << " vs. " << that->enumType    << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            if (this->numberOfSOS != that->numberOfSOS)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "numberOfSOS: " << this->numberOfSOS << " vs. " << that->numberOfSOS << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            int i;
            for (i = 0; i < numberOfSOS; i++)
                if (!this->sos[i]->IsEqual(that->sos[i]))
                    return false;
            if (this->numberOfEnumerations != that->numberOfEnumerations)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "numberOfEnumerations: " << this->numberOfEnumerations << " vs. " << that->numberOfEnumerations << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            for (i = 0; i < numberOfEnumerations; i++)
                if (!this->enumeration[i]->IsEqual(that->enumeration[i]))
                    return false;
            return true;
        }
    }
}//OtherSpecialOrderedSetsOptionOrResult::IsEqual

bool OtherSpecialOrderedSetsOptionOrResult::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Set random OtherSpecialOrderedSetsOptionOrResult");
#endif
    this->name = "random string";
    if (OSRand() <= density) this->description = "random string";
    if (OSRand() <= density) this->value       = "random string";
    if (OSRand() <= density) this->type        = "random string";
    if (OSRand() <= density) this->solver      = "random string";
    if (OSRand() <= density) this->category    = "random string";
    if (OSRand() <= density) this->enumType    = "random string";
    if (OSRand() <= density)
    {
        if (OSRand() <= 0.5)
        {
            this->numberOfSOS = (int)(4*OSRand());
            int n;
            if (conformant) n = this->numberOfSOS;
            else            n = (int)(4*OSRand());
            sos = new OtherSOSOptionOrResult*[n];
            for (int i = 0; i < n; i++)
            {
                sos[i] = new OtherSOSOptionOrResult();
                sos[i]->setRandom(density, conformant);
            }
        }
        else
        {
            this->numberOfEnumerations = (int)(4*OSRand());
            int n;
            if (conformant) n = this->numberOfEnumerations;
            else            n = (int)(4*OSRand());
            enumeration = new OtherOptionOrResultEnumeration*[n];
            for (int i = 0; i < n; i++)
            {
                enumeration[i] = new OtherOptionOrResultEnumeration();
                enumeration[i]->setRandom(density, conformant, 0, 9);
            }
        }
    }
    return true;
}//OtherSpecialOrderedSetsOptionOrResult::setRandom

bool OtherSpecialOrderedSetsOptionOrResult::deepCopyFrom(OtherSpecialOrderedSetsOptionOrResult *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Make deep copy of OtherSpecialOrderedSetsOptionOrResult");
#endif
    this->name        = that->name;
    this->description = that->description;
    this->value       = that->value;
    this->type        = that->type;
    this->solver      = that->solver;
    this->category    = that->category;
    this->enumType    = that->enumType;
    int n;

    this->numberOfSOS = that->numberOfSOS;
    n = this->numberOfSOS;
    if (n < 0) return false;
    if (n > 0) 
    {
        this->sos = new OtherSOSOptionOrResult*[n];
        for (int i = 0; i < n; i++)
        {
            this->sos[i] = new OtherSOSOptionOrResult();
            if (!this->sos[i]->deepCopyFrom(that->sos[i]))
                return false;
        }
    }
    this->numberOfEnumerations = that->numberOfEnumerations;
    n = this->numberOfEnumerations;
    if (n  < 0) return false;
    if (n == 0) return true;
    this->enumeration = new OtherOptionOrResultEnumeration*[n];
    for (int i = 0; i < n; i++)
    {
        this->enumeration[i] = new OtherOptionOrResultEnumeration();
        if (!this->enumeration[i]->deepCopyFrom(that->enumeration[i]))
            return false;
    }
    return true;
}//OtherSpecialOrderedSetsOptionOrResult::deepCopyFrom


OtherMatrixVariableOptionOrResult::OtherMatrixVariableOptionOrResult():
    name(""),
    description(""),
    value(""),
    type(""),
    solver(""),
    category(""),
    numberOfEnumerations(0),
    enumType(""),
    numberOfMatrixVar(0),
    matrixVar(NULL),
    enumeration(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Inside OtherMatrixVariableOptionOrResult Constructor");
#endif
}// end OtherMatrixVariableOptionOrResult constructor

OtherMatrixVariableOptionOrResult::~OtherMatrixVariableOptionOrResult()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "OtherMatrixVariableOptionOrResult Destructor Called");
#endif
    if (numberOfMatrixVar > 0)
        if (matrixVar != NULL)
        {
            for (int i=0; i< numberOfMatrixVar; ++i)
                if (matrixVar[i] != NULL)
                    delete matrixVar[i];
            delete [] matrixVar;
            matrixVar = NULL;
        }

    if (numberOfEnumerations > 0)
        if (enumeration != NULL)
        {
            for (int i=0; i < numberOfEnumerations; i++)
                if (enumeration[i] != NULL)
                    delete enumeration[i];
            delete[] enumeration;
            enumeration = NULL;
        }
}//end OtherMatrixVariableOptionOrResult destructor


bool OtherMatrixVariableOptionOrResult::IsEqual(OtherMatrixVariableOptionOrResult *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug,
        "Start comparing in OtherMatrixVariableOptionOrResult");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if ((this->name                 != that->name)        ||
                (this->description          != that->description) ||
                (this->value                != that->value)       ||
                (this->type                 != that->type)        ||
                (this->solver               != that->solver)      ||
                (this->category             != that->category)    ||
                (this->enumType             != that->enumType)      )
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "name: "        << this->name        << " vs. " << that->name        << endl;
                outStr << "description: " << this->description << " vs. " << that->description << endl;
                outStr << "value: "       << this->value       << " vs. " << that->value       << endl;
                outStr << "type: "        << this->type        << " vs. " << that->type        << endl;
                outStr << "solver: "      << this->solver      << " vs. " << that->solver      << endl;
                outStr << "category: "    << this->category    << " vs. " << that->category    << endl;
                outStr << "enumType: "    << this->enumType    << " vs. " << that->enumType    << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            if (this->numberOfMatrixVar != that->numberOfMatrixVar)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "numberOfMatrixVar: "
                       << this->numberOfMatrixVar << " vs. " << that->numberOfMatrixVar << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            int i;
            for (i = 0; i < numberOfMatrixVar; i++)
                if (!this->matrixVar[i]->IsEqual(that->matrixVar[i]))
                    return false;

            if (this->numberOfEnumerations != that->numberOfEnumerations)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "numberOfEnumerations: " << this->numberOfEnumerations << " vs. " << that->numberOfEnumerations << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            for (i = 0; i < numberOfEnumerations; i++)
                if (!this->enumeration[i]->IsEqual(that->enumeration[i]))
                    return false;
            return true;
        }
    }
}//OtherMatrixVariableOptionOrResult::IsEqual

bool OtherMatrixVariableOptionOrResult::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Set random OtherMatrixVariableOptionOrResult");
#endif
    this->name = "random string";
    if (OSRand() <= density) this->description = "random string";
    if (OSRand() <= density) this->value       = "random string";
    if (OSRand() <= density) this->type        = "random string";
    if (OSRand() <= density) this->solver      = "random string";
    if (OSRand() <= density) this->category    = "random string";
    if (OSRand() <= density) this->enumType    = "random string";
    if (OSRand() <= density)
    {
        if (OSRand() <= 0.5)
        {
            this->numberOfMatrixVar = (int)(4*OSRand());
            int n;
            if (conformant) n = this->numberOfMatrixVar;
            else            n = (int)(4*OSRand());
            matrixVar = new OSMatrixWithMatrixVarIdx*[n];
            for (int i = 0; i < n; i++)
            {
                matrixVar[i] = new OSMatrixWithMatrixVarIdx();
                matrixVar[i]->setRandom(density, conformant);
            }
        }
        else
        {
            this->numberOfEnumerations = (int)(4*OSRand());
            int n;
            if (conformant) n = this->numberOfEnumerations;
            else            n = (int)(4*OSRand());
            enumeration = new OtherOptionOrResultEnumeration*[n];
            for (int i = 0; i < n; i++)
            {
                enumeration[i] = new OtherOptionOrResultEnumeration();
                enumeration[i]->setRandom(density, conformant, 0, 9);
            }
        }
    }
    return true;
}//OtherMatrixVariableOptionOrResult::setRandom

bool OtherMatrixVariableOptionOrResult::deepCopyFrom(OtherMatrixVariableOptionOrResult *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Make deep copy of OtherMatrixVariableOptionOrResult");
#endif
    this->name        = that->name;
    this->description = that->description;
    this->value       = that->value;
    this->type        = that->type;
    this->solver      = that->solver;
    this->category    = that->category;
    this->enumType    = that->enumType;
    int n;
    this->numberOfMatrixVar = that->numberOfMatrixVar;
    n = this->numberOfMatrixVar;
    if (n < 0) return false;
    if (n > 0) 
    {
        this->matrixVar = new OSMatrixWithMatrixVarIdx*[n];
        for (int i = 0; i < n; i++)
        {
//            this->matrixVar[i] = new OSMatrixWithMatrixVarIdx();
//            if (!this->matrixVar[i]->deepCopyFrom(that->matrixVar[i]))
//                return false;
            this->matrixVar[i] = that->matrixVar[i]->cloneMatrixNode();
        }
    }
    this->numberOfEnumerations = that->numberOfEnumerations;
    n = this->numberOfEnumerations;
    if (n  < 0) return false;
    if (n == 0) return true;
    this->enumeration = new OtherOptionOrResultEnumeration*[n];
    for (int i = 0; i < n; i++)
    {
        this->enumeration[i] = new OtherOptionOrResultEnumeration();
        if (!this->enumeration[i]->deepCopyFrom(that->enumeration[i]))
            return false;
    }
    return true;
}//OtherMatrixVariableOptionOrResult::deepCopyFrom


OtherMatrixObjectiveOptionOrResult::OtherMatrixObjectiveOptionOrResult():
    name(""),
    description(""),
    value(""),
    type(""),
    solver(""),
    category(""),
    numberOfEnumerations(0),
    enumType(""),
    numberOfMatrixObj(0),
    matrixObj(NULL),
    enumeration(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Inside OtherMatrixObjectiveOptionOrResult Constructor");
#endif
}// end OtherMatrixObjectiveOptionOrResult constructor


OtherMatrixObjectiveOptionOrResult::~OtherMatrixObjectiveOptionOrResult()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "OtherMatrixObjectiveOptionOrResult Destructor Called");
#endif
    if (numberOfMatrixObj > 0)
        if (matrixObj != NULL)
        {
            for (int i=0; i< numberOfMatrixObj; ++i)
                if (matrixObj[i] != NULL)
                    delete matrixObj[i];
            delete [] matrixObj;
            matrixObj = NULL;
        }

    if (numberOfEnumerations > 0)
        if (enumeration != NULL)
        {
            for (int i=0; i < numberOfEnumerations; i++)
                if (enumeration[i] != NULL)
                    delete enumeration[i];
            delete[] enumeration;
            enumeration = NULL;
        }
}//end OtherMatrixObjectiveOptionOrResult destructor


bool OtherMatrixObjectiveOptionOrResult::IsEqual(OtherMatrixObjectiveOptionOrResult *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug,
        "Start comparing in OtherMatrixObjectiveOptionOrResult");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if ((this->name                 != that->name)        ||
                (this->description          != that->description) ||
                (this->value                != that->value)       ||
                (this->type                 != that->type)        ||
                (this->solver               != that->solver)      ||
                (this->category             != that->category)    ||
                (this->enumType             != that->enumType)      )
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "name: "        << this->name        << " vs. " << that->name        << endl;
                outStr << "description: " << this->description << " vs. " << that->description << endl;
                outStr << "value: "       << this->value       << " vs. " << that->value       << endl;
                outStr << "type: "        << this->type        << " vs. " << that->type        << endl;
                outStr << "solver: "      << this->solver      << " vs. " << that->solver      << endl;
                outStr << "category: "    << this->category    << " vs. " << that->category    << endl;
                outStr << "enumType: "    << this->enumType    << " vs. " << that->enumType    << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            if (this->numberOfMatrixObj != that->numberOfMatrixObj)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "numberOfMatrixObj: "
                       << this->numberOfMatrixObj << " vs. " << that->numberOfMatrixObj << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            int i;
            for (i = 0; i < numberOfMatrixObj; i++)
                if (!this->matrixObj[i]->IsEqual(that->matrixObj[i]))
                    return false;

            if (this->numberOfEnumerations != that->numberOfEnumerations)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "numberOfEnumerations: " << this->numberOfEnumerations << " vs. " << that->numberOfEnumerations << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            for (i = 0; i < numberOfEnumerations; i++)
                if (!this->enumeration[i]->IsEqual(that->enumeration[i]))
                    return false;
            return true;
        }
    }
}//OtherMatrixObjectiveOptionOrResult::IsEqual

bool OtherMatrixObjectiveOptionOrResult::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Set random OtherMatrixObjectiveOptionOrResult");
#endif
    this->name = "random string";
    if (OSRand() <= density) this->description = "random string";
    if (OSRand() <= density) this->value       = "random string";
    if (OSRand() <= density) this->type        = "random string";
    if (OSRand() <= density) this->solver      = "random string";
    if (OSRand() <= density) this->category    = "random string";
    if (OSRand() <= density) this->enumType    = "random string";
    if (OSRand() <= density)
    {
        if (OSRand() <= 0.5)
        {
            this->numberOfMatrixObj = (int)(4*OSRand());
            int n;
            if (conformant) n = this->numberOfMatrixObj;
            else            n = (int)(4*OSRand());
            matrixObj = new OSMatrixWithMatrixObjIdx*[n];
            for (int i = 0; i < n; i++)
            {
                matrixObj[i] = new OSMatrixWithMatrixObjIdx();
                matrixObj[i]->setRandom(density, conformant);
            }
        }
        else
        {
            this->numberOfEnumerations = (int)(4*OSRand());
            int n;
            if (conformant) n = this->numberOfEnumerations;
            else            n = (int)(4*OSRand());
            enumeration = new OtherOptionOrResultEnumeration*[n];
            for (int i = 0; i < n; i++)
            {
                enumeration[i] = new OtherOptionOrResultEnumeration();
                enumeration[i]->setRandom(density, conformant, 0, 9);
            }
        }
    }
    return true;
}//OtherMatrixObjectiveOptionOrResult::setRandom

bool OtherMatrixObjectiveOptionOrResult::deepCopyFrom(OtherMatrixObjectiveOptionOrResult *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Make deep copy of OtherMatrixObjectiveOptionOrResult");
#endif
    this->name        = that->name;
    this->description = that->description;
    this->value       = that->value;
    this->type        = that->type;
    this->solver      = that->solver;
    this->category    = that->category;
    this->enumType    = that->enumType;
    int n;
    this->numberOfMatrixObj = that->numberOfMatrixObj;
    n = this->numberOfMatrixObj;
    if (n < 0) return false;
    if (n > 0) 
    {
        this->matrixObj = new OSMatrixWithMatrixObjIdx*[n];
        for (int i = 0; i < n; i++)
        {
//            this->matrixObj[i] = new OSMatrixWithMatrixObjIdx();
//            if (!this->matrixObj[i]->deepCopyFrom(that->matrixObj[i]))
//                return false;
            this->matrixObj[i] = that->matrixObj[i]->cloneMatrixNode();
        }
    }
    this->numberOfEnumerations = that->numberOfEnumerations;
    n = this->numberOfEnumerations;
    if (n  < 0) return false;
    if (n == 0) return true;
    this->enumeration = new OtherOptionOrResultEnumeration*[n];
    for (int i = 0; i < n; i++)
    {
        this->enumeration[i] = new OtherOptionOrResultEnumeration();
        if (!this->enumeration[i]->deepCopyFrom(that->enumeration[i]))
            return false;
    }
    return true;
}//OtherMatrixObjectiveOptionOrResult::deepCopyFrom


OtherMatrixConstraintOptionOrResult::OtherMatrixConstraintOptionOrResult():
    name(""),
    description(""),
    value(""),
    type(""),
    solver(""),
    category(""),
    numberOfEnumerations(0),
    enumType(""),
    numberOfMatrixCon(0),
    matrixCon(NULL),
    enumeration(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Inside OtherMatrixConstraintOptionOrResult Constructor");
#endif
}// end OtherMatrixConstraintOptionOrResult constructor

OtherMatrixConstraintOptionOrResult::~OtherMatrixConstraintOptionOrResult()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "OtherMatrixConstraintOptionOrResult Destructor Called");
#endif
    if (numberOfMatrixCon > 0)
        if (matrixCon != NULL)
        {
            for (int i=0; i< numberOfMatrixCon; ++i)
                if (matrixCon[i] != NULL)
                    delete matrixCon[i];
            delete [] matrixCon;
            matrixCon = NULL;
        }

    if (numberOfEnumerations > 0)
        if (enumeration != NULL)
        {
            for (int i=0; i < numberOfEnumerations; i++)
                if (enumeration[i] != NULL)
                    delete enumeration[i];
            delete[] enumeration;
            enumeration = NULL;
        }
}//end OtherMatrixConstraintOptionOrResult destructor


bool OtherMatrixConstraintOptionOrResult::IsEqual(OtherMatrixConstraintOptionOrResult *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug,
        "Start comparing in OtherMatrixConstraintOptionOrResult");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if ((this->name                 != that->name)        ||
                (this->description          != that->description) ||
                (this->value                != that->value)       ||
                (this->type                 != that->type)        ||
                (this->solver               != that->solver)      ||
                (this->category             != that->category)    ||
                (this->enumType             != that->enumType)      )
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "name: "        << this->name        << " vs. " << that->name        << endl;
                outStr << "description: " << this->description << " vs. " << that->description << endl;
                outStr << "value: "       << this->value       << " vs. " << that->value       << endl;
                outStr << "type: "        << this->type        << " vs. " << that->type        << endl;
                outStr << "solver: "      << this->solver      << " vs. " << that->solver      << endl;
                outStr << "category: "    << this->category    << " vs. " << that->category    << endl;
                outStr << "enumType: "    << this->enumType    << " vs. " << that->enumType    << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            if (this->numberOfMatrixCon != that->numberOfMatrixCon)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "numberOfMatrixCon: "
                       << this->numberOfMatrixCon << " vs. " << that->numberOfMatrixCon << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            int i;
            for (i = 0; i < numberOfMatrixCon; i++)
                if (!this->matrixCon[i]->IsEqual(that->matrixCon[i]))
                    return false;

            if (this->numberOfEnumerations != that->numberOfEnumerations)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "numberOfEnumerations: " << this->numberOfEnumerations << " vs. " << that->numberOfEnumerations << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            for (i = 0; i < numberOfEnumerations; i++)
                if (!this->enumeration[i]->IsEqual(that->enumeration[i]))
                    return false;
            return true;
        }
    }
}//OtherMatrixConstraintOptionOrResult::IsEqual

bool OtherMatrixConstraintOptionOrResult::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Set random OtherMatrixConstraintOptionOrResult");
#endif
    this->name = "random string";
    if (OSRand() <= density) this->description = "random string";
    if (OSRand() <= density) this->value       = "random string";
    if (OSRand() <= density) this->type        = "random string";
    if (OSRand() <= density) this->solver      = "random string";
    if (OSRand() <= density) this->category    = "random string";
    if (OSRand() <= density) this->enumType    = "random string";
    if (OSRand() <= density)
    {
        if (OSRand() <= 0.5)
        {
            this->numberOfMatrixCon = (int)(4*OSRand());
            int n;
            if (conformant) n = this->numberOfMatrixCon;
            else            n = (int)(4*OSRand());
            matrixCon = new OSMatrixWithMatrixConIdx*[n];
            for (int i = 0; i < n; i++)
            {
                matrixCon[i] = new OSMatrixWithMatrixConIdx();
                matrixCon[i]->setRandom(density, conformant);
            }
        }
        else
        {
            this->numberOfEnumerations = (int)(4*OSRand());
            int n;
            if (conformant) n = this->numberOfEnumerations;
            else            n = (int)(4*OSRand());
            enumeration = new OtherOptionOrResultEnumeration*[n];
            for (int i = 0; i < n; i++)
            {
                enumeration[i] = new OtherOptionOrResultEnumeration();
                enumeration[i]->setRandom(density, conformant, 0, 9);
            }
        }
    }
    return true;
}//OtherMatrixConstraintOptionOrResult::setRandom

bool OtherMatrixConstraintOptionOrResult::deepCopyFrom(OtherMatrixConstraintOptionOrResult *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Make deep copy of OtherMatrixConstraintOptionOrResult");
#endif
    this->name        = that->name;
    this->description = that->description;
    this->value       = that->value;
    this->type        = that->type;
    this->solver      = that->solver;
    this->category    = that->category;
    this->enumType    = that->enumType;
    int n;
    this->numberOfMatrixCon = that->numberOfMatrixCon;
    n = this->numberOfMatrixCon;
    if (n < 0) return false;
    if (n > 0) 
    {
        this->matrixCon = new OSMatrixWithMatrixConIdx*[n];
        for (int i = 0; i < n; i++)
        {
//            this->matrixCon[i] = new OSMatrixWithMatrixConIdx();
//            if (!this->matrixCon[i]->deepCopyFrom(that->matrixCon[i]))
//                return false;
            this->matrixCon[i] = that->matrixCon[i]->cloneMatrixNode();
        }
    }
    this->numberOfEnumerations = that->numberOfEnumerations;
    n = this->numberOfEnumerations;
    if (n  < 0) return false;
    if (n == 0) return true;
    this->enumeration = new OtherOptionOrResultEnumeration*[n];
    for (int i = 0; i < n; i++)
    {
        this->enumeration[i] = new OtherOptionOrResultEnumeration();
        if (!this->enumeration[i]->deepCopyFrom(that->enumeration[i]))
            return false;
    }
    return true;
}//OtherMatrixConstraintOptionOrResult::deepCopyFrom


OtherOptionOrResult::OtherOptionOrResult():
    name (""),
    description (""),
    value (""),
    type ("")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Inside OtherOptionOrResult Constructor");
#endif
}// end OtherOptionOrResult constructor

OtherOptionOrResult::~OtherOptionOrResult()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "OtherOptionOrResult Destructor Called");
#endif
}//end OtherOptionOrResult destructor


bool OtherOptionOrResult::IsEqual(OtherOptionOrResult *that )
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug,
        "Start comparing in OtherOptionOrResult");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if ((this->name        != that->name)        ||
                (this->description != that->description) ||
                (this->value       != that->value)       ||
                (this->type        != that->type)          )
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "name: "        << this->name        << " vs. " << that->name        << endl;
                outStr << "description: " << this->description << " vs. " << that->description << endl;
                outStr << "value: "       << this->value       << " vs. " << that->value       << endl;
                outStr << "type: "        << this->type        << " vs. " << that->type        << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            return true;
        }
    }
}//OtherOptionOrResult::IsEqual


bool OtherOptionOrResult::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Set random SolverOptionOrResult");
#endif
    if (OSRand() <= density || conformant) this->name = "random string";
    if (OSRand() <= density) this->description = "random string";
    if (OSRand() <= density) this->value       = "random string";
    if (OSRand() <= density) this->type        = "random string";
    return true;
}//OtherOptionOrResult::setRandom

bool OtherOptionOrResult::deepCopyFrom(OtherOptionOrResult *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Make deep copy of OtherOptionOrResult");
#endif
    this->name        = that->name;
    this->description = that->description;
    this->value       = that->value;
    this->type        = that->type;
    return true;
}//OtherOptionOrResult::deepCopyFrom


SolverOptionOrResult::SolverOptionOrResult():
    name (""),
    description (""),
    value (""),
    type (""),
    solver(""),
    category (""),
    numberOfMatrices(0),
    numberOfItems(0),
    matrix(NULL),
    item(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Inside SolverOptionOrResult Constructor");
#endif
}// end SolverOptionOrResult constructor

SolverOptionOrResult::~SolverOptionOrResult()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "SolverOptionOrResult Destructor Called");
#endif
    if (numberOfMatrices > 0)
        if (matrix != NULL)
        {
            for (int i=0; i< numberOfMatrices; ++i)
                if (matrix[i] != NULL)
                    delete matrix[i];
            delete [] matrix;
            matrix = NULL;
        }
        
    if (item != NULL) delete[] item;
    item = NULL;
}//end SolverOptionOrResult destructor


bool SolverOptionOrResult::IsEqual(SolverOptionOrResult *that )
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug,
        "Start comparing in SolverOptionOrResult");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if ((this->name        != that->name)     ||
                (this->value       != that->value)    ||
                (this->solver      != that->solver)   ||
                (this->category    != that->category) ||
                (this->type        != that->type)     ||
                (this->description != that->description))
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "name: "        << this->name        << " vs. " << that->name        << endl;
                outStr << "value: "       << this->value       << " vs. " << that->value       << endl;
                outStr << "solver: "      << this->solver      << " vs. " << that->solver      << endl;
                outStr << "category: "    << this->category    << " vs. " << that->category    << endl;
                outStr << "type: "        << this->type        << " vs. " << that->type        << endl;
                outStr << "description: " << this->description << " vs. " << that->description << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            return true;
        }
    }
}//SolverOptionOrResult::IsEqual


bool SolverOptionOrResult::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Set random SolverOptionOrResult");
#endif
    if (OSRand() <= density || conformant) this->name = "random string";

    if (OSRand() <= density) this->value       = "random string";
    if (OSRand() <= density) this->solver      = "random string";
    if (OSRand() <= density) this->category    = "random string";
    if (OSRand() <= density) this->type        = "random string";
    if (OSRand() <= density) this->description = "random string";

    if (OSRand() <= density)
    {
        this->numberOfItems = (int)(4*OSRand());

        int n;

        if (conformant)    n = this->numberOfItems;
        else            n = (int)(4*OSRand());

        item = new std::string[n];
        for (int i = 0; i < n; i++)
            item[i] = "random string";
    }
    return true;
}//SolverOptionOrResult::setRandom

bool SolverOptionOrResult::deepCopyFrom(SolverOptionOrResult *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Make deep copy of SolverOptionOrResult");
#endif
    this->name        = that->name;
    this->value       = that->value;
    this->solver      = that->solver;
    this->category    = that->category;
    this->type        = that->type;
    this->description = that->description;

    this->numberOfItems = that->numberOfItems;
    int n = this->numberOfItems;

    if (n  < 0) return false;
    if (n == 0) return true;

    this->item = new std::string[n];
    for (int i = 0; i < n; i++)
        this->item[i] = that->item[i];

    return true;
}//SolverOptionOrResult::deepCopyFrom

