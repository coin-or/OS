/* $Id: OSnLParserData.cpp 3710 2010-10-04 03:39:42Z Gassmann $ */
/** @file OSnLParserData.cpp
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin,
 *
 * \remarks
 * Copyright (C) 2005-2014, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */
#include "OSnLParserData.h"
#include "OSnLNode.h"
#include <stdio.h>


OSnLParserData::~OSnLParserData()
{
}//~OSnLParserData


OSnLParserData::OSnLParserData() :
    nlnodecount(0),
    tmpnlcount(0),
    numbertypeattON(false),
    numbervalueattON(false),
    numberidattON(false),
    variableidxattON(false),
    variablecoefattON(false),
    includeDiagonalAttributePresent(false),
    includeDiagonalAttribute(true)
{

}//OSnLParserData

