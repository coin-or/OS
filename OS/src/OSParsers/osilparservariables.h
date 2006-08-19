/** @file osilparservariables.h
 * 
 * @author  Robert Fourer,  Jun Ma, Kipp Martin, 
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005, Robert Fourer, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */
 
#include "OSnLNode.h"
#include <vector> 
#include <string>
OSInstance* osinstance;

std::string sparseError;

int qtermcount;
int nlnodecount;

// qterm attribute boolean variables
bool qtermidxOneattON ;
bool qtermidxTwoattON ;
bool qtermidxattON ;
bool qtermidattON ;
bool qtermcoefattON ;
// number attribute boolean variables
bool numbertypeattON ;
bool numbervalueattON;
bool numberidattON;
// variable attribute boolean variables
bool variableidxattON ;
bool variablecoefattON ;
// kipp -- change later when nonlinear added to OSInstnace
int tmpnlcount;
/*  end header file */ 


std::vector<OSnLNode*> nlNodeVec;
std::vector<OSnLNode*> sumVec;
std::vector<OSnLNode*> productVec;
std::vector<OSnLNode*> maxVec;


OSnLNode *nlNodePoint;
OSnLNodeVariable *nlNodeVariablePoint;
OSnLNodeNumber *nlNodeNumberPoint;


int numChar;
char *attTextEnd;
int ki;

// extra methods
//OSnLNode *createExpressionTree(std::vector<OSnLNode*> nlNodeVec);

