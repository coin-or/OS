/** @file OSiLParserData.h
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
#ifndef OSILPARSERDATA_H
#define OSILPARSERDATA_H

#include "OSnLNode.h"
#include <vector> 


class OSiLParserData{
public:
	OSiLParserData( );
	~OSiLParserData() ;
	OSnLNode *nlNodePoint;
	OSnLNodeVariable *nlNodeVariablePoint;
	OSnLNodeNumber *nlNodeNumberPoint;
	int qtermcount;
	bool qtermidxOneattON;
	bool qtermidxTwoattON;
	bool qtermidxattON;
	bool qtermidattON ;
	bool qtermcoefattON;
	//
	int nlnodecount;
	int tmpnlcount;
	// number attribute boolean variables
	bool numbertypeattON ;
	bool numbervalueattON;
	bool numberidattON;
	// variable attribute boolean variables
	bool variableidxattON ;
	bool variablecoefattON ;
	
	std::vector<OSnLNode*> nlNodeVec;
	std::vector<OSnLNode*> sumVec;
	std::vector<OSnLNode*> productVec;
	std::vector<OSnLNode*> maxVec;
};

#endif /*OSILPARSERDATA_H_*/
