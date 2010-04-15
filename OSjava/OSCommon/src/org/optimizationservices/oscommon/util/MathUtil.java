/**
 * @(#)MathUtil 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.util;

import org.optimizationservices.oscommon.datastructure.osgeneral.SparseMatrix;



/**
 *
 * <P>The <code>MathUtil</code> class contains methods for performing
 * mathematics related operations used by many classes in the
 * Optimization Services (OS) framework. </p>
 *
 * </p>
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin, Huanyuan Sheng
 * @version 1.0, 03/14/2004
 * @since   OS1.0
 */
public class MathUtil{
	
	/**
	 * Constructor.
	 *
	 */
	public MathUtil(){
		
	}//constructor
	
	/**
	 * Round a double number to the precision specified. 
	 * 
	 * @param x holds the number to be rounded. 
	 * @param precision holds the number of digit after (or before if negative) the decimal point. 
	 * @return the rounded number. 
	 */
	public static double round (double x, int precision){
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
	
	/**
	 * Calculation of x mod y. 
	 * 
	 * @param x holds the number before the mod operator. 
	 * @param y holds the number after the mod operator. 
	 * @return the result of x mod y. 
	 */
	public static double mod (double x, double y){
		return  x - Math.floor(x / y) * y;
	}//mod
	
	/**
	 * convert linear constraint coefficient matrix (row or column major) to the other major (column or row)
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
	public static SparseMatrix convertLinearConstraintCoefficientMatrixToTheOtherMajor(
			boolean isColumnMajor, int[] start, int[] index, double[] value, int dimension){
		if(start == null || start.length <= 1 ) return null;
		if(value == null || index == null || value.length != index.length) return null;	
		
		int iStartSize = dimension + 1;
		SparseMatrix matrix = new SparseMatrix( !isColumnMajor, iStartSize, value.length);		
		
		int i,j, iTemp;
		int iNumSource = start.length - 1;
		int [] miStart = matrix.starts;
		int [] miIndex = matrix.indexes;
		double [] mdValue = matrix.values;
		
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
	
	
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		int [] miStart ={0, 2, 5, 6, 7, 13, 13, 16};

		int [] miIndex = {0, 8, 9, 4, 1, 2, 3,         7, 6, 9, 4, 1, 8,                    4, 6, 9};
		double [] mdValues = {1.7, .13, 0.01, 0.02, 1, 1.5, 1.1,         
				0.09, 0.16, 0.53,            2.6,  0.02, 0.52,   
				0.16, 1.3, 0.56};
		
		
		SparseMatrix testCoeff;
		
		testCoeff = convertLinearConstraintCoefficientMatrixToTheOtherMajor(false, miStart, miIndex, mdValues, 10);
		
		testCoeff.display(miStart.length - 1);
		
		
		
	}//main
	
}//class MathUtil
