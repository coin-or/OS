/* $Id$ */
/** @file OSiLParserData.cpp
 *
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 *
 * \remarks
 * Copyright (C) 2005-2011, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University, Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */
#include "OSiLParserData.h"
#include <iostream>
using namespace std;
OSiLParserData::~OSiLParserData()
{
    // clear the vectors of pointers
    nlNodeVec.clear();
    //delete nlNodeVec.back();
    sumVec.clear();
    maxVec.clear();
    productVec.clear();
    minVec.clear();
    allDiffVec.clear();
    if (m_miVarStageInfo != NULL)
        delete []m_miVarStageInfo;
    m_miVarStageInfo = NULL;
    if (m_miConStageInfo != NULL)
        delete []m_miConStageInfo;
    m_miConStageInfo = NULL;
    if (m_miObjStageInfo != NULL)
        delete []m_miObjStageInfo;
    m_miObjStageInfo = NULL;

}//~OSiLParserData


OSiLParserData::OSiLParserData() :
    osillineno(0),
    qtermcount(0),
    qtermidxOneattON(false),
    qtermidxTwoattON(false),
    qtermidxattON(false),
    qtermidattON(false),
    qtermcoefattON(false),
    nlnodecount(0),
    tmpnlcount(0),
    numbertypeattON(false),
    numbervalueattON(false),
    numberidattON(false),
    variableidxattON(false),
    variablecoefattON(false),
    timeDomainStages(false),
    timeDomainInterval(false),
    stagecount(0),
    stagenameON(false),
    stagename(""),
    stageVariablesON(false),
    stageConstraintsON(false),
    stageObjectivesON(false),
    stageVariablesOrdered(false),
    stageConstraintsOrdered(false),
    stageObjectivesOrdered(false),
    stageVariableStartIdx(0),
    stageConstraintStartIdx(0),
    stageObjectiveStartIdx(0),
    stagevarcount(0),
    stageconcount(0),
    stageobjcount(0),
    nvarcovered(0),
    nconcovered(0),
    intervalhorizonON(false),
    intervalhorizon(0.0),
    intervalstartON(false),
    intervalstart(0.0)
{
    m_miVarStageInfo = NULL;
    m_miConStageInfo = NULL;
    m_miObjStageInfo = NULL;

}//OSiLParserData
