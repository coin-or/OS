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
 #include "OSiLParserData.h"
 OSiLParserData::~OSiLParserData(){
 	// clear the vectors of pointers
	nlNodeVec.clear();
	sumVec.clear();
	maxVec.clear();
	productVec.clear();
 }//~OSiLParserData
 

 OSiLParserData::OSiLParserData() :
 	numbertypeattON(false),
 	numbervalueattON(false),
 	numberidattON(false),
 	variableidxattON(false),
 	variablecoefattON(false),
 	qtermidxOneattON(false),
	qtermidxTwoattON(false),
	qtermidxattON(false),
	qtermidattON(false),
	qtermcoefattON(false),
	qtermcount(0),
	tmpnlcount(0),
	nlnodecount(0)
 {

 }//OSiLParserData

 