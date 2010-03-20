/**
 * @(#)MatrixMarket 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.datastructure.osgeneral;

/**
 *
 * <P>The <code>MatrixMarket</code> class holds the matrix market  
 * data structure (rowIndex, columnIndex, Value[rowIndex,columnIndex]) for linear constraint coefficients  
 *  
 * </p>
 * @author Robert Fourer, Jun Ma, Kipp Martin, Huanyuan Sheng
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */

public class MatrixMarket {

	/**
	 * rowIndexes holds an integer array of row indexes of the specified matrix elements (usually nonzero). 
	 */
	public int[] rowIndexes = null; 
	

	/**
	 * columnIndexes holds an integer array of column indexes of the specified matrix elements (usually nonzero). 
	 */
	public int[] columnIndexes = null;

	/**
	 * values holds a double array of the values of the specified matrix elements (usually nonzero). 
	 */
	public double[] values = null;

	/**
	 *
	 * Default constructor. 
	 */
	public MatrixMarket(){
	}//constructor
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] args) {
	}//main

}//MatrixMarket
