/** @file MathUtil.cpp
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
 * <p>The <code>MathUtil</code> class contains methods for performing
 * mathematics related operations used by many classes in the
 * Optimization Services (OS) framework. </p>
 */
 
#include "OSDataStructures.h" 
//#include "OSInstance.h"
#include "MathUtil.h"
#include <iostream>
using namespace std;
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
		 
		for (i = 0; i < iNumSource; i++){
			
			for (j = start[i]; j < start[ i + 1 ]; j++){
				miStart[ index[j] + 1] ++;				
			}
		}
		
		//compute running sum from 
		miStart[0] = 0;
		for (i = 1; i < iStartSize; i++ ){
			miStart[i] += miStart [i - 1] ;		
		}
				
		for (i = 0; i < iNumSource; i++){
			
			for (j = start[i]; j < start[ i + 1 ]; j++){
				iTemp = miStart[index[j]];
				miIndex [iTemp] = i;
				mdValue [iTemp] = value[j];
				miStart[ index[j]] ++;				
			}			
		} 	
		
		for (i = iStartSize - 1; i >= 1; i-- ){
			miStart[i] = miStart [i - 1] ;		
		}
			
		miStart[0] = 0;
		return matrix;		
	}//convertLinearConstraintCoefficientMatrixToTheOtherMajor
	



