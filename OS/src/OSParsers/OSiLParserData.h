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

/*! \class
 *  \brief The OSiLParserData  Class.
 * 
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 * 
 * \remarks
 * the OSiLParserData class is used to hold the nonlinear
 * part of the problem when an OSiL instance is parsed
 * we do this so we can have a reentrant parser.
 */
class OSiLParserData{
public:
	/** the OSiLParserData class constructor */
	OSiLParserData( );
	
	/** the OSiLParserData class destructor */
	~OSiLParserData() ;

	/** scanner is used to store data in a reentrant lexer 
	 * we use this to pass an OSiLParserData object to the parser*/
	void* scanner;
	
	/** a point to an OSnLNode object */
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
	
	int osillineno;
	
	std::vector<OSnLNode*> nlNodeVec;
	std::vector<OSnLNode*> sumVec;
	std::vector<OSnLNode*> allDiffVec;
	std::vector<OSnLNode*> productVec;
	std::vector<OSnLNode*> maxVec;
	std::vector<OSnLNode*> minVec;
};

#endif /*OSILPARSERDATA_H_*/
