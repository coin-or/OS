/** @file MathUtil.h
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
 * 
 */
 
 
#ifndef MATHUTIL_H
#define MATHUTIL_H
 
#include "OSParameters.h"
#include "OSdtoa.h"

#include <sstream>  
#include<string>


using std::ostringstream; 

/*!  \class MathUtil
 *  \brief this class has routines for linear algebra.
 * 
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 * 
 * \remarks
 * This class will hold linear algebra routines used by other
 * OS classes. Right now it has a routine to change the column/row 
 * storage of a sparse matrix 
 */
class MathUtil{
	public:

	/** the class constructor */
	MathUtil();
	
	/** the class destructor */
	~MathUtil();
	
	/**
	 * Round a double number to the precision specified. 
	 * 
	 * @param X holds the number to be rounded. 
	 * @param precision holds the number of digit after (or before if negative) the decimal point. 
	 * @return the rounded number. 
	 */
	/*public static double round (double x, int precision){
		double mask = 0.0, y, result;		
		try{
			mask = Math.pow (10.0, -(double)precision);
		}
		catch(ArithmeticException e){
			return x;
		}
		y  = mod(x, mask);
		result  = x - y;
		if (y / mask >= 0.5) result += mask;
		return result;
	}//round
	*/
	/**
	 * Calculation of x mod y. 
	 * 
	 * @param x holds the number before the mod operator. 
	 * @param x holds the number after the mod operator. 
	 * @return the result of x mod y. 
	 */
	/*public static double mod (double x, double y){
		return  x - Math.floor(x / y) * y;
	}//mod
	*/
	/**
	 * 
	 * @param isColumnMajor holds whether the coefMatrix (AMatrix) holding linear program
	 * data is stored by column. If false, the matrix is stored by row.
	 * @param start holds an integer array of start elements in coefMatrix (AMatrix),
	 * which points to the start of a column (row) of nonzero elements in coefMatrix (AMatrix).
	 * @param index holds an integer array of rowIdx (or colIdx) elements in coefMatrix (AMatrix).
	 * If the matrix is stored by column (row), rowIdx (colIdx) is the array of row (column) indices.
	 * @param value holds a double array of value elements in coefMatrix (AMatrix),
	 * which contains nonzero elements.
	 * @param dimension holds the column count if the input matrix is row major (row count = start.length-1)
	 * or the row number if the input matrix is column major (columnh count = start.length -1)
	 * @return Linear constraint coefficient matrix in the other major of the input matrix. Return null if input matrix not valid.
	 */
	static SparseMatrix* convertLinearConstraintCoefficientMatrixToTheOtherMajor(
			bool isColumnMajor, int startSize, int valueSize, int* start, int* index, 
			double* value, int dimension);
	
	/**
	 * 
	 * @param x is the double that gets converted into a string
	 */
	std::string format_os_dtoa( double x);
			
};//class MathUtil
#endif
