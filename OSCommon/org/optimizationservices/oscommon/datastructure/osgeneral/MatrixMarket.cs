using System;

namespace org.optimizationservices.oscommon.datastructure{
	/// <summary>
	/// The <c>MatrixMarket</c> class holds the matrix market  
	/// data structure (rowIndex, columnIndex, Value[rowIndex,columnIndex]) 
	/// for linear constraint coefficients.   																																								  * 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class MatrixMarket{

		/// <summary>
		/// rowIndexes holds an integer array of row indexes of the specified matrix elements (usually nonzero). 
		/// </summary>
		public int[] rowIndexes = null; 
	

		/// <summary>
		/// columnIndexes holds an integer array of column indexes of the specified matrix elements (usually nonzero). 
		/// </summary>
		public int[] columnIndexes = null;

		/// <summary>
		/// values holds a double array of the values of the specified matrix elements (usually nonzero). 
		/// </summary>
		public double[] values = null;

		/// <summary>
		/// Default constructor. 
		/// </summary>
		public MatrixMarket(){
		}//constructor

	}//class MatrixMarket
}//namespace
