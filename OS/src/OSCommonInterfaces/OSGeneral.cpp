/* $Id: OSGeneral.cpp 3186 2010-02-06 23:38:35Z Gassmann $ */
/** @file OSGeneral.cpp
 * 
 *
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.0, 19/07/2010
 * @since   OS2.2
 *
 * \remarks
 * Copyright (C) 2005-2010, Robert Fourer, Jun Ma, Horand Gassmann, Kipp Martin,
 * Northwestern University, Dalhousie University and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */

#include "OSGeneral.h"
#include "OSParameters.h"
#include "OSErrorClass.h"
#include "OSMathUtil.h"
#include "OSBase64.h"

#include<iostream>
#include<sstream>

//#define DEBUG_OSGENERAL

using namespace std;
using std::cout;
using std::endl;


SparseVector::SparseVector( int number_):
number( number_)
{
	indexes = new int[ number];
	values = new double[ number];
	bDeleteArrays = true;
}// end SparseVector constructor


SparseVector::SparseVector( ):
	bDeleteArrays(true),
	indexes( NULL),
	values( NULL)
{
}// end SparseVector constructor

SparseVector::~SparseVector(){
	#ifdef DEBUG
	cout << "inside sparseVector destructor" << endl;
	#endif
	if(	bDeleteArrays == true){
#ifdef DEBUG
cout << "delete[] indexes and arrays" << endl;
#endif
		delete[] indexes;
		delete[] values;
	}
	values = NULL;
	indexes = NULL;
}// end SparseVector constructor

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


SparseMatrix::~SparseMatrix(){
	#ifdef DEBUG
	cout << "inside SparseMatrix destructor" << endl;
	#endif
	if( bDeleteArrays == true){
		delete[] starts;
		delete[] indexes;
		delete[] values;

	}
	starts = NULL;
	indexes = NULL;
	values = NULL;
}// end SparseMatrix Destructor


bool SparseMatrix::display(int secondaryDim){
		int i, j, k;
		for ( i = 0; i < startSize - 1; i++){			
			
			if (starts[i] == starts[i + 1]){
				
				for ( k = 0; k < secondaryDim; k++){
					//System.out.print("0,");					
				}				
			}
			else {
				for ( j = 0; j < indexes[starts[i]]; j ++){				
					//System.out.print("0,");					
				}
				
				for ( j = starts[ i ]; j < starts[i + 1]; j++){
					
					//System.out.print (values[j] + ",");
					
					if ( j < starts[i + 1] - 1){
						for ( k = indexes [j] + 1; k < indexes[j + 1]; k++){
							//System.out.print("0,");					
						}
					}
					else {
						
						for ( k = indexes [j] + 1; k < secondaryDim; k++){
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


SparseJacobianMatrix::~SparseJacobianMatrix(){
	#ifdef DEBUG
	cout << "inside SparseJacobianMatrix destructor" << endl;
	#endif
	if(bDeleteArrays == true){
		#ifdef DEBUG
		cout << "delete SparseJacobianArrays" << endl;
		#endif
		delete[] starts;
		delete[] conVals;
		delete[] indexes;
		delete[] values;
	}
		starts = NULL;
		conVals = NULL;
		indexes = NULL;
		values = NULL;
}// end SparseJacobianMatrix Destructor


SparseHessianMatrix::SparseHessianMatrix():
	bDeleteArrays( true),
	hessDimension(0),
	hessRowIdx( NULL),
	hessColIdx( NULL),
	hessValues( NULL)
{
}// end SparseHessianMatrix Constructor



SparseHessianMatrix::~SparseHessianMatrix(){
	#ifdef DEBUG
	cout << "inside SparseHessianMatrix destructor" << endl;
	#endif
	if(bDeleteArrays == true){
		delete[] hessRowIdx;
		delete[] hessColIdx;
		delete[] hessValues;
	}
	hessRowIdx = NULL;
	hessColIdx = NULL;
	hessValues = NULL;
}// end SparseHessianMatrix Destructor


	
QuadraticTerms::QuadraticTerms():
	rowIndexes(NULL),
	varOneIndexes(NULL),
	varTwoIndexes(NULL),
	coefficients(NULL)
{
}

QuadraticTerms::~QuadraticTerms(){
	#ifdef DEBUG
	cout << "inside Quadratic Terms destructor" << endl;
	#endif
	delete[] rowIndexes;
	rowIndexes = NULL;
	delete[] varOneIndexes;
	varOneIndexes = NULL;
	delete[] varTwoIndexes;
	varTwoIndexes = NULL;
	delete[] coefficients;
	coefficients = NULL;
}


IntVector::IntVector():
	bDeleteArrays(true),
	numberOfEl(0),
	el(NULL)
{  
	#ifdef DEBUG
	cout << "Inside the IntVector Constructor" << endl;
	#endif
} 

IntVector::~IntVector(){  
	#ifdef DEBUG
	cout << "Inside the IntVector Destructor" << endl;
	#endif
	if(	bDeleteArrays == true){
		delete[] el;
		el = NULL;
	}

} 

std::string IntVector::writeEl(bool addWhiteSpace, bool writeBase64)
{
	ostringstream outStr;
	int mult, incr;

	if (this->numberOfEl > 0)
	{
		if(writeBase64 == false)
		{
			for(int i = 0; i <= this->numberOfEl;)
			{
				getMultIncr(&(this->el[i]), &mult, &incr, (this->numberOfEl) - i, 1);
				if (mult == 1)
					outStr << "<el>" ;
				else if (incr == 1)
					outStr << "<el mult=\"" << mult << "\">";
				else
					outStr << "<el mult=\"" << mult << "\" incr=\"" << incr << "\">";
				outStr << this->el[i];
				outStr << "</el>" ;
				if(addWhiteSpace == true) outStr << endl;
				i += mult;
			}
		}
		else
		{
			outStr << "<base64BinaryData sizeOf=\"" << sizeof(int) << "\"  >" ;
			outStr << Base64::encodeb64( (char*)this->el, (this->numberOfEl)*sizeof(int) );
			outStr << "</base64BinaryData>" ;
			if(addWhiteSpace == true) outStr << endl;
		}
	}
	return outStr.str();
}// end IntVector::writeEl


DoubleVector::DoubleVector():
	bDeleteArrays(true),
	el(NULL)
{
	#ifdef DEBUG
	cout << "Inside the DoubleVector Constructor" << endl;
	#endif

}


DoubleVector::~DoubleVector(){  
	#ifdef DEBUG
	cout << "Inside the DoubleVector Destructor" << endl;
	#endif
	if(	bDeleteArrays == true){
		delete[] el;
		el = NULL;
	}
}

std::string DoubleVector::writeEl(bool addWhiteSpace, bool writeBase64)
{
	ostringstream outStr;
	int mult, incr;

	if (this->numberOfEl > 0)
	{
		if(writeBase64 == false)
		{
			for(int i = 0; i <= this->numberOfEl;)
			{
				mult = getMult(&(this->el[i]), (this->numberOfEl) - i);
				if (mult == 1)
					outStr << "<el>" ;
				else 
					outStr << "<el mult=\"" << mult << "\">";
				outStr << os_dtoa_format(this->el[i] );
				outStr << "</el>" ;
				if(addWhiteSpace == true) outStr << endl;
				i += mult;
			}
		}
		else
		{
			outStr << "<base64BinaryData sizeOf=\"" << sizeof(double) << "\"  >" ;
			outStr << Base64::encodeb64( (char*)this->el, (this->numberOfEl)*sizeof(double) );
			outStr << "</base64BinaryData>" ;
			if(addWhiteSpace == true) outStr << endl;
		}
	}
	return outStr.str();
}// end DoubleVector::writeEl


