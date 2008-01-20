/** @file OSDataStructures.cpp
 * 
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
 

 //#define DEBUG

#include "OSDataStructures.h"
#include <iostream>
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

