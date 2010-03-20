/**
 * @(#)QuadraticTerms 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.datastructure.osgeneral;

/**
*
* <P>The <code>QuadraticTerms</code> class holds the data structure 
* for all quadratic terms in the optimization instance. 
* (rowIndexes, varOneIndexes, varTwoIndexes, coefficients)
* </p>
* @author Robert Fourer, Jun Ma, Kipp Martin, Huanyuan Sheng
* @version 1.0, 03/14/2004
* @since OS 1.0
*/

public class QuadraticTerms {
	
	/**
	 * rowIndexes holds an integer array of row indexes of all the quadratic terms. 
	 * A negative integer corresponds to an objective row, e.g. -1 for 1st objective and -2 for 2nd.
	 */
	public int[] rowIndexes = null; 

	/**
	 * varOneIndexes holds an integer array of the first varialbe indexes of all the quadratic terms. 
	 */
	public int[] varOneIndexes = null; 

	/**
	 * varTwoIndexes holds an integer array of the second varialbe indexes of all the quadratic terms. 
	 */
	public int[] varTwoIndexes = null; 

	/**
	 * coefficients holds a double array all the quadratic term coefficients. 
	 */
	public double[] coefficients = null; 

	/**
	 *
	 * Default constructor. 
	 */
	public QuadraticTerms(){
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

}//QuadraticTerms
