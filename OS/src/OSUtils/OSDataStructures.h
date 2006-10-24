/** @file OShL.h
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

/**
*
* <p>The <code>SparseMatrix</code> class holds the 3 list 
* data structure usually used for linear constraint coefficients   
* </p>
*/

#ifndef OSDATASTRUCTURES_H
#define OSDATASTRUCTURES_H

#include <stdlib.h>


class SparseVector{
	public:
	
	/**
	 * Constructor.
	 * 
	 * @param number holds the size of the vector.
	 */
	
	SparseVector(int number);
	
	/**
	 *
	 * Default Constructor. 
	 */	
	SparseVector();
	
	/**
	 *
	 * Default destructor. 
	 */	
	~SparseVector();
	
	/**
	 * number is the number of elements in the indexes and values arrays.
	 */
	int number;
	
	/**
	 * indexes holds an integer array of indexes, which corresponding values are nonzero.
	 */
	int* indexes;

	/**
	 * values holds a double array of nonzero values.
	 */
	double* values;

}; //SparseVector


class SparseMatrix {
	public:
	/**
	 * isColumnMajor holds whether the coefMatrix (AMatrix) holding linear program
	 * data is stored by column. If false, the matrix is stored by row.
	 */
	bool isColumnMajor;
	
	/**
	 * startSize is the dimension of the starts array
	 */
	int startSize;
	
	/**
	 * valueSize is the dimension of the starts array
	 */
	int valueSize;
	
	/**
	 * starts holds an integer array of start elements in coefMatrix (AMatrix),
	 * which points to the start of a column (row) of nonzero elements in coefMatrix (AMatrix).
	 */
	int* starts; 
	
	/**
	 * indexes holds an integer array of rowIdx (or colIdx) elements in coefMatrix (AMatrix).
	 * If the matrix is stored by column (row), rowIdx (colIdx) is the array of row (column) indices.
	 */
	int* indexes;

	/**
	 * values holds a double array of value elements in coefMatrix (AMatrix),
	 * which contains nonzero elements.
	 */
	double* values;
	
	/**
	 *
	 * Default constructor. 
	 */
	SparseMatrix();
	
	/**
	 * Constructor.
	 * 
	 * @param isColumnMajor holds whether the coefMatrix (AMatrix) holding linear program
	 * data is stored by column. If false, the matrix is stored by row.
	 * @param startSize holds the size of the start array.
	 * @param valueSize holds the size of the value and index arrays.
	 */
	SparseMatrix(bool isColumnMajor_, int startSize, int valueSize);
	/**
	 *
	 * Default destructor. 
	 */	
	~SparseMatrix();
	
	/**
	 * This method displays data structure in the matrix format.
	 * </p>
	 * @return
	 */
	bool display(int secondaryDim);

}; //SparseMatrix


class SparseJacobianMatrix {
	public:
	/**
	 * startSize is the dimension of the starts array
	 */
	int startSize;
	
	/**
	 * valueSize is the dimension of the starts array
	 */
	int valueSize;
	
	/**
	 * starts holds an integer array of start elements in coefMatrix (AMatrix),
	 * which points to the start of a column (row) of nonzero elements in coefMatrix (AMatrix).
	 */
	int* starts; 
	
	/**
	 * conVals holds an integer array of integers, conVals[i] is the number of constant terms
	 * in the gradient for row i.
	 */
	int* conVals; 
	
	/**
	 * indexes holds an integer array of rowIdx (or colIdx) elements in coefMatrix (AMatrix).
	 * If the matrix is stored by column (row), rowIdx (colIdx) is the array of row (column) indices.
	 */
	int* indexes;

	/**
	 * values holds a double array of value elements in coefMatrix (AMatrix),
	 * which contains nonzero elements.
	 */
	double* values;
	
	/**
	 *
	 * Default constructor. 
	 */
	SparseJacobianMatrix();
	
	/**
	 * Constructor.
	 * 
	 * @param startSize holds the size of the start array.
	 * @param valueSize holds the size of the value and index arrays.
	 */
	SparseJacobianMatrix(int startSize, int valueSize);

	/**
	 *
	 * Default destructor. 
	 */	
	~SparseJacobianMatrix();

}; //SparseJacobianMatrix


class SparseJacobianVector{
	public:
	
	/**
	 * Constructor.
	 * 
	 * @param number holds the size of the vector.
	 */
	
	SparseJacobianVector(int number);
	
	/**
	 *
	 * Default Constructor. 
	 */	
	SparseJacobianVector();
	
	/**
	 *
	 * Default destructor. 
	 */	
	~SparseJacobianVector();
	
	
	/**
	 * number is the number of elements in the indexes and values arrays.
	 */
	int number;
	
	/**
	 * numConstant is the number partials that do not change at each iteration
	 * the first numConstant components are constant.
	 */
	int numConstant;
	
	/**
	 * indexes holds an integer array of indexes, which corresponding values are nonzero.
	 */
	int* indexes;

	/**
	 * values holds a double array of nonzero values.
	 */
	double* values;

}; //SparseJacobianVector


/*! \class SparseHessianMatrix SparseHessianMatrix.h "SparseHessianMatrix.h"
 *  \brief The in-memory representation of a SparseHessianMatrix..
 *
 * \remarks 
<p>  Store and uppertriangular Hessian Matrix in sparse format </p>
<p>  Assume there are n variables in what follows </p>

 *
 * 
 */
class SparseHessianMatrix {
	public:

	/**
	 * hessDimension is the number of nonzeros in each array.
	 */
	int hessDimension;
	
	/**
	 * hessRowIdx is an integer array of row indicies in the range 0, ..., n - 1.
	 */
	int* hessRowIdx; 
	
	/**
	 * hessColIdx is an integer array of column indicies in the range 0, ..., n - 1.
	 */
	int* hessColIdx; 
	
	/**
	 * hessValues is a double array of the Hessian values.
	 */
	double* hessValues;

	/**
	 *
	 * Default constructor. 
	 */
	SparseHessianMatrix();
	
	/**
	 * An Alternative Constructor.
	 * 
	 * @param startSize holds the size of the start array.
	 * @param valueSize holds the size of the value and index arrays.
	 */
	SparseHessianMatrix(int startSize, int valueSize);

	/**
	 *
	 * Default destructor. 
	 */	
	~SparseHessianMatrix();

}; //SparseHessianMatrix

class QuadraticTerms {

	public:
	
	/**
	 * rowIndexes holds an integer array of row indexes of all the quadratic terms. 
	 * A negative integer corresponds to an objective row, e.g. -1 for 1st objective and -2 for 2nd.
	 */
	int* rowIndexes; 

	/**
	 * varOneIndexes holds an integer array of the first varialbe indexes of all the quadratic terms. 
	 */
	int* varOneIndexes; 

	/**
	 * varTwoIndexes holds an integer array of the second varialbe indexes of all the quadratic terms. 
	 */
	int* varTwoIndexes; 

	/**
	 * coefficients holds a double array all the quadratic term coefficients. 
	 */
	double* coefficients; 

	/**
	 *
	 * Default constructor. 
	 */
	QuadraticTerms();
	~QuadraticTerms();
}; //QuadraticTerms


	
class IntVector{
public:
	IntVector();
	~IntVector();
	int *el;
};//class IntVector

class DoubleVector{
public:
	DoubleVector();
	~DoubleVector();
	double *el;			
};//class DoubleVector

#endif

