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


#include "OSDataStructures.h"
#include <iostream>
using std::cout;
using std::endl;


 


SparseVector::SparseVector( int number_):
number( number_)
{
	indexes = new int[ number];
	values = new double[ number];
}// end SparseVector constructor


SparseVector::SparseVector( ):
	indexes( NULL),
	values( NULL)
{
}// end SparseVector constructor

SparseVector::~SparseVector(){
	#ifdef DEBUG
	cout << "inside sparseVector destructor" << endl;
	#endif
	delete[] indexes;
	indexes = NULL;
	delete[] values;
	values = NULL;
}// end SparseVector constructor

SparseMatrix::SparseMatrix():
	isColumnMajor(true),
	starts(NULL),
	indexes(NULL),
	values(NULL),
	startSize(0),
	valueSize(0)

{
}// end SparseMatrix Constructor



SparseMatrix::SparseMatrix(bool isColumnMajor_, int startSize_, int valueSize_):
	isColumnMajor(isColumnMajor_), 
	startSize(startSize_),
	valueSize(valueSize_)
{
	starts = new int[startSize];
	indexes = new int[valueSize];
	values = new double[valueSize];		
}//end SparseMatrix constructor


SparseMatrix::~SparseMatrix(){
	#ifdef DEBUG
	cout << "inside SparseMatrix destructor" << endl;
	#endif
	delete[] starts;
	starts = NULL;
	delete[] indexes;
	indexes = NULL;
	delete[] values;
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
	starts(NULL),
	indexes(NULL),
	values(NULL),
	conVals(NULL),
	startSize(0),
	valueSize(0)

{
}// end SparseJaccobianMatrix Constructor


SparseJacobianMatrix::SparseJacobianMatrix(int startSize_, int valueSize_):
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
	if(starts != NULL){
		delete[] starts;
		starts = NULL;
	}
	if(conVals != NULL){
		delete[] conVals;
		conVals = NULL;
	}
	if(indexes != NULL){
		delete[] indexes;
		indexes = NULL;
	}
	if(values != NULL){
		delete[] values;
		values = NULL;
	}
}// end SparseJacobianMatrix Destructor

SparseJacobianVector::SparseJacobianVector( int number_):
number( number_)
{
	indexes = new int[ number];
	values = new double[ number];
}// end SparseJacobianVector constructor


SparseJacobianVector::SparseJacobianVector( ):
	indexes( NULL),
	values( NULL)
{
}// end SparseJacobianVector constructor


SparseJacobianVector::~SparseJacobianVector(){
	#ifdef DEBUG
	cout << "inside sparseVector destructor" << endl;
	#endif
	delete[] indexes;
	indexes = NULL;
	delete[] values;
	values = NULL;
}// end SparseJacobianVector constructor


	
SparseHessianMatrix::SparseHessianMatrix():
	hessRowIdx( NULL),
	hessColIdx( NULL),
	hessValues( NULL),
	hessDimension(0)
{
}// end SparseHessianMatrix Constructor



SparseHessianMatrix::~SparseHessianMatrix(){
	#ifdef DEBUG
	cout << "inside SparseJacobianMatrix destructor" << endl;
	#endif
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
	delete[] el;
	el = NULL;
} 

DoubleVector::DoubleVector():
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
	delete[] el;
	el = NULL;
}

