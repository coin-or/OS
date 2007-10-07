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

/*! \class OSiLParserData
 *  \brief The OSiLParserData Class, used to store parser data.
 * 
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 * 
 * \remarks
 * the OSiLParserData class is used to hold the nonlinear
 * part of the problem when an OSiL instance is parsed
 * we do this so we can have a reentrant parser. We do not
 * have to store the linear part because we do not use flex/bison
 * to parse the linear part of the problem
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
	
	/** a pointer to an OSnLNode object */
	OSnLNode *nlNodePoint;
	
	/** a pointer to an OSnLNode object that is a variable */
	OSnLNodeVariable *nlNodeVariablePoint;
	
	/** a pointer to an OSnLNode object that is a number */
	OSnLNodeNumber *nlNodeNumberPoint;
	
	/** store the number of quadratic terms */
	int qtermcount;
	
	/** qtermidxOneattON is true if we have found the first index
	 * of the quadratic term */
	bool qtermidxOneattON;
	
	/** qtermidxTwoattON is true if we have found the second index
	 * of the quadratic term */
	bool qtermidxTwoattON;
	
	/** qtermidxattON is true if we have found the row index of the 
	 * of a quadratic term */
	bool qtermidxattON;
	
	/** qtermidattON is true if we have found the id of the quadratic term */
	bool qtermidattON ;
	
	/** qtermcoefattON is true if we have found the coefficient of the
	 * quadratic term 
	 */
	bool qtermcoefattON;
	
	/** nlnodecout is the number of nl nodes in the instance*/
	int nlnodecount;
	
	/** tmpnlcount counts the number of nl nodes actually found, if this
	 * number differs from nlnodecount, then an exception is thrown
	 */
	int tmpnlcount;
	
	/** numbertypeattON is set to true if the type attribute has been parsed
	 * for an OSnLNodeNumber object, and exception is thrown if there is more than
	 * one value attribute 
	 */
	bool numbertypeattON ;
	
	/** numbervalueattON is set to true if the value attribute has been parsed
	 * for an OSnLNodeNumber object, an exception is thrown if there is more than one
	 * value attribute 
	 */	
	bool numbervalueattON;
	
	/** numberidattON is set to true if the id attribute has been parsed
	 * for an OSnLNodeNumber object, an exception is thrown if there is more than
	 * one id attribute 
	 */		
	bool numberidattON;

	/** variableidxattON is set to true if the idx attribute has been parsed
	 * for an OSnLNodeVariable, an exception is thrown if there is more than
	 * one idx attribute 
	 */	
	bool variableidxattON ;
	
	/** variablecoeffattON is set to true if the coeff attribute has been parsed
	 * for an OSnLNodeVariable, an exception is thrown if there is more than
	 * one coeff attribute 
	 */	
	bool variablecoefattON ;
	
	/** if there is a parser error, osillineno holds the line number in the
	 * OSiL file where the error occured.
	 */
	int osillineno;
	
	/** nlNodeVec holds a vector of pointers to OSnLNodes */
	std::vector<OSnLNode*> nlNodeVec;
	
	/** the OSnLNodeSum node can have any number of children, including 
	 * other children with an inderminent number of children so when 
	 * parsing we need to temporarily store  all of its children
	 */
	std::vector<OSnLNode*> sumVec;
	
	/** the OSnLNodeallDiff node can have any number of children, including 
	 * other children with an inderminent number of children so when 
	 * parsing we need to temporarily store  all of its children
	 */
	std::vector<OSnLNode*> allDiffVec;
	
	/** the OSnLNodeProduct node can have any number of children, including 
	 * other children with an inderminent number of children so when 
	 * parsing we need to temporarily store  all of its children
	 */
	std::vector<OSnLNode*> productVec;
	
	/** the OSnLNodeMax node can have any number of children, including 
	 * other children with an inderminent number of children so when 
	 * parsing we need to temporarily store  all of its children
	 */
	std::vector<OSnLNode*> maxVec;
	
	/** the OSnLNodeMin node can have any number of children, including 
	 * other children with an inderminent number of children so when 
	 * parsing we need to temporarily store  all of its children
	 */
	std::vector<OSnLNode*> minVec;
};

#endif /*OSILPARSERDATA_H_*/
