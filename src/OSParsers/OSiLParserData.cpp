/* $Id$ */
/** @file OSiLParserData.cpp
 *
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 *
 * \remarks
 * Copyright (C) 2005-2011, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
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
#if 0
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
#endif
}//~OSiLParserData


OSiLParserData::OSiLParserData() :
    osillineno(0),
    qtermcount(0),
    qtermidxOneattON(false),
    qtermidxTwoattON(false),
    qtermidxattON(false),
    qtermidattON(false),
    qtermcoefattON(false),
//    nlnodecount(0),
//    tmpnlcount(0),
//    numbertypeattON(false),
//    numbervalueattON(false),
//    numberidattON(false),
//    variableidxattON(false),
//    variablecoefattON(false),
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
    intervalstart(0.0),

    numberOfMatricesPresent(false), 
    numberOfMatrices(0),
    numberOfConesPresent(false),
    numberOfCones(0),
    numberOfRowsPresent(false),
    numberOfRows(0),
    numberOfColumnsPresent(false),
    numberOfColumns(0),
    numberOfEl(0), 
    numberOf(0), 
    namePresent(false),
    name(""),
    referenceMatrixIdxPresent(false),
    referenceMatrixIdx(-1),
    normScaleFactorPresent(false),
    normScaleFactor(1.0),
    distortionMatrixPresent(false),
    distortionMatrix(-1),
    axisDirectionPresent(false),
    axisDirection(-1),
    firstAxisDirectionPresent(false),
    firstAxisDirection(-1),
    secondAxisDirectionPresent(false),
    secondAxisDirection(-1),
    semidefinitenessPresent(false),
    semidefiniteness(""),

    numberOfMatrixVar(-1),
    numberOfMatrixObj(-1),
    numberOfMatrixCon(-1),
    numberOfMatrixTerms(-1),
    numberOfMatrixExpr(-1),

    numberOfMatrixTermsPresent(false),
    matrixIdxPresent(false),
    lbMatrixIdxPresent(false),
    lbConeIdxPresent(false),
    ubMatrixIdxPresent(false),
    ubConeIdxPresent(false),
    orderConeIdxPresent(false),
    templateMatrixIdxPresent(false),
    constantMatrixIdxPresent(false),
    varReferenceMatrixIdxPresent(false),
    objReferenceMatrixIdxPresent(false),
    conReferenceMatrixIdxPresent(false),
    varTypePresent(false),

    matrixIdx(-1),
    lbMatrixIdx(-1),
    lbConeIdx(-1),
    ubMatrixIdx(-1),
    ubConeIdx(-1),
    orderConeIdx(-1),
    templateMatrixIdx(-1),
    constantMatrixIdx(-1),
    varReferenceMatrixIdx(-1),
    objReferenceMatrixIdx(-1),
    conReferenceMatrixIdx(-1),
    varType('C'),

    shapePresent(false),
    shape(""),

    matrixTermInObj(false),

    kounter(0),
    kount2(0),
    tempVal(0.0),
    ignoreDataAfterErrors(false),
    suppressFurtherErrorMessages(false),
    parser_errors("")
{
    m_miVarStageInfo = NULL;
    m_miConStageInfo = NULL;
    m_miObjStageInfo = NULL;

}//OSiLParserData
