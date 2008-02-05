/** @file MathUtil.cpp
 * 
 * @author  Robert Fourer,  Jun Ma, Kipp Martin, 
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005, Robert Fourer, Jun Ma, Kipp Martin, and Wayne Sheng
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 * <p>The <code>MathUtil</code> class contains methods for performing
 * mathematics related operations used by many classes in the
 * Optimization Services (OS) framework. </p>
 */
 
#include "OSDataStructures.h" 
#include "OSMathUtil.h"


#include <iostream>

#define	ISWHITESPACE( char_) ((char_) == ' ' || \
                     (char_) == '\t' ||  (char_) == '\r')


MathUtil::MathUtil(){
}

MathUtil::~MathUtil(){
}


 
SparseMatrix* MathUtil::convertLinearConstraintCoefficientMatrixToTheOtherMajor(
	bool isColumnMajor, int startSize, int valueSize, int* start, int* index, 
	double* value, int dimension){
	if(!start || startSize <= 1 ) return NULL;
	if(!value  || !index  ) return NULL;	

	int iStartSize = dimension + 1;
	SparseMatrix *matrix ;
	matrix = new SparseMatrix( !isColumnMajor, iStartSize, valueSize);		
	int i,j, iTemp;
	int iNumSource = startSize - 1;
	int* miStart = matrix->starts;
	int* miIndex = matrix->indexes;
	double* mdValue = matrix->values;
	
	for ( i = 0; i < iStartSize; i++){			
		miStart [ i ] = 0;
	}
	// for illustration assume we are converting from column to row major	
	// i is indexing columns (variables) and j is indexing row numbers 
	for (i = 0; i < iNumSource; i++){	
		for (j = start[i]; j < start[ i + 1 ]; j++){
			// index[ j] is a row index, we have just found an occurance of row index[j]
			// therefore we increase by 1 (or push back) the start of the row indexed by index[j] + 1, 
			// i.e. the start of the next row
			miStart[ index[j] + 1] ++;				
		}
	}
	// at this point, miStart[ i] holds the number of columns with a nonzero in row i - 1
	// we are not done with the start indicies, if we are here, and we
	// knew the correct starting point of row i -1, the correct starting point
	// for row i is miStart[i] + miStart [i - 1]
	miStart[0] = 0;
	for (i = 1; i < iStartSize; i++ ){
		miStart[i] += miStart [i - 1] ;		
	}
	
	// now get the correct values
	// again assume we are converting column major to row major
	// loop over bariables		
	for (i = 0; i < iNumSource; i++){
		// get row indices and values of the A matrix
		for (j = start[i]; j < start[ i + 1 ]; j++){
			iTemp = miStart[ index[j]];
			miIndex [ iTemp] = i;
			mdValue [ iTemp] = value[j];
			miStart[ index[j]] ++;				
		}			
	} 
		
	// miStart[ i] is now equal to miStart[ i + 1], so readjust
	for (i = iStartSize - 1; i >= 1; i-- ){
		miStart[i] = miStart [i - 1] ;		
	}
		
	miStart[0] = 0;
	return matrix;		
}//convertLinearConstraintCoefficientMatrixToTheOtherMajor

std::string MathUtil::format_os_dtoa(double  x){
	ostringstream outStr;
#ifndef USE_DTOA
	outStr << x;
	return outStr.str();
#endif
	outStr << "";
	char *charResult;
    int decimalPointPos;
    int sign;  
    int strLength = 0;
    int k = 0;
    charResult = os_dtoa(x, 0, 0, &decimalPointPos, &sign, NULL);
    // get the length
    strLength = strlen( charResult);
    // return charResult if we have nan or infinity  -- if so, return orginal string
    if(decimalPointPos == 9999){
    	
    	for(k = 0; k < strLength; k++)outStr << charResult[ k];
    	return outStr.str();    	
    }
    // get the sign, 1 for negative
    if( sign == 1) outStr << "-";
    if(decimalPointPos == strLength){ //don't we have an integer?
    	for(k = 0; k < strLength; k++)outStr << charResult[ k];
    	return outStr.str();
    } 
    if(decimalPointPos >= 0){
    	if(decimalPointPos > strLength){
    		// put in all of the characters from charResult
    		outStr << charResult[ 0];
    		outStr <<  ".";
    		for(k = 1; k < strLength; k++) outStr << charResult[ k];
    		//for(k = strLength; k < decimalPointPos; k++) outStr <<  "0";
    		outStr <<  "e";
    		outStr <<  decimalPointPos -  1;
    	}else{
    		for(k = 0; k < decimalPointPos; k++) outStr << charResult[ k];
    		outStr <<  ".";
    		for(k = decimalPointPos; k < strLength; k++) outStr << charResult[ k];
    	}
    }else{
		outStr << charResult[ 0];
		outStr <<  ".";
    	//for(k = 0; k < -decimalPointPos; k++) outStr << "0";
    	for(k = 1; k < strLength; k++)outStr <<  charResult[ k];
		outStr <<  "e";
		outStr <<  decimalPointPos -1 ;
    }
    //
    os_freedtoa( charResult);
	return outStr.str();
}// end dtoa

double os_strtod_wrap(const char *str) throw(ErrorClass){
	double val;
   	char *pEnd;
	try{
		#ifdef USE_DTOA
			val = os_strtod(str, &pEnd);
			// pEnd should now point to the first character after the number;
			// there should not be anything but white space
			// burn off any white space	
			//if( (pchar - *p) != 12)
			for( ; *pEnd == ' ' |  *pEnd == '\t' |  *pEnd == '\r' |   *pEnd == '\n'   ; pEnd++ ) ;
			// pEnd should now point to str, if not we have an error
			if(*pEnd != '\0') throw ErrorClass( "error in parsing an XSD:double");
			return val;
		#else
			val = strtod(str, &pEnd);
			// pEnd should now point to the first character after the number;
			// there should not be anything but white space
			// burn off any white space	
			//if( (pchar - *p) != 12)
			for( ; *pEnd == ' ' |  *pEnd == '\t' |  *pEnd == '\r' |   *pEnd == '\n'   ; pEnd++ ) ;
			// pEnd should now point to str, if not we have an error
			if(*pEnd != '\0') throw ErrorClass( "error in parsing an XSD:double");
			return val;
		#endif
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg) ;
	}
}
