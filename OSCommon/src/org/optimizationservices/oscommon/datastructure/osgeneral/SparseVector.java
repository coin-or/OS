/**
 * @(#)SparseVector 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.datastructure.osgeneral;

/**
*
* <P>The <code>SparseVector</code> class holds a two array 
* data structure for sparse representation of vector. 
*  
* </p>
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2004
* @since OS 1.0
*/

public class SparseVector {

	
	/**
	 * indexes holds an integer array of indexes, which corresponding values are nonzero.
	 */
	public int[] indexes = null;

	/**
	 * values holds a double array of nonzero values.
	 */
	public double[] values = null;

	/**
	 *
	 * Default constructor. 
	 */
	public SparseVector(){
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

}//SparseVector
