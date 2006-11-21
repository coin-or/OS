/**
 * @(#)SparseMatrix 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.datastructure.osgeneral;

/**
*
* <P>The <code>SparseMatrix</code> class holds the 3 list 
* data structure usually used for linear constraint coefficients  
*  
* </p>
* @author Robert Fourer, Jun Ma, Kipp Martin, Huanyuan Sheng
* @version 1.0, 03/14/2004
* @since OS 1.0
*/

public class SparseMatrix {

	/**
	 * isColumnMajor holds whether the coefMatrix (AMatrix) holding linear program
	 * data is stored by column. If false, the matrix is stored by row.
	 */
	public boolean isColumnMajor = true;
	
	/**
	 * starts holds an integer array of start elements in coefMatrix (AMatrix),
	 * which points to the start of a column (row) of nonzero elements in coefMatrix (AMatrix).
	 */
	public int[] starts = null; 
	
	/**
	 * indexes holds an integer array of rowIdx (or colIdx) elements in coefMatrix (AMatrix).
	 * If the matrix is stored by column (row), rowIdx (colIdx) is the array of row (column) indices.
	 */
	public int[] indexes = null;

	/**
	 * values holds a double array of value elements in coefMatrix (AMatrix),
	 * which contains nonzero elements.
	 */
	public double[] values = null;

	/**
	 *
	 * Default constructor. 
	 */
	public SparseMatrix(){
	}//constructor
	

	/**
	 * Constructor.
	 * 
	 * @param isColumnMajor holds whether the coefMatrix (AMatrix) holding linear program
	 * data is stored by column. If false, the matrix is stored by row.
	 * @param startSize holds the size of the start array.
	 * @param valueSize holds the size of the value and index arrays.
	 */
	public SparseMatrix(boolean isColumnMajor, int startSize, int valueSize){
		this.isColumnMajor = isColumnMajor; 
		starts = new int[startSize];
		indexes = new int[valueSize];
		values = new double[valueSize];		
	}//constructor
	
	
	
	/**
	 * This method displays data structure in the matrix format.
	 * </p>
	 * @return true if display is successful 
	 */
	public boolean display(int secondaryDim){
		int i, j, k;

		for ( i = 0; i < starts.length - 1; i++){			
			
			if (starts[i] == starts[i + 1]){
				
				for ( k = 0; k < secondaryDim; k++){
					System.out.print("0,");					
				}				
			}
			else {
				for ( j = 0; j < indexes[starts[i]]; j ++){				
					System.out.print("0,");					
				}
				
				for ( j = starts[ i ]; j < starts[i + 1]; j++){
					
					System.out.print (values[j] + ",");
					
					
					if ( j < starts[i + 1] - 1){
						for ( k = indexes [j] + 1; k < indexes[j + 1]; k++){
							System.out.print("0,");					
						}
					}
					else {
						
						for ( k = indexes [j] + 1; k < secondaryDim; k++){
							System.out.print("0,");					
						}
					}
				}
			}
			System.out.println();
		}

		return true;
		
	}//display
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] args) {
	}//main

}//SparseMatrix
