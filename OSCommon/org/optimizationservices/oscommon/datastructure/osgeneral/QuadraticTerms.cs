using System;

namespace org.optimizationservices.oscommon.datastructure{
	/// <summary>
	/// The <c>QuadraticTerms</c> class holds the data structure 
	/// for all quadratic terms in the optimization instance. 
	/// (rowIndexes, varOneIndexes, varTwoIndexes, coefficients)
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class QuadraticTerms{

		/// <summary>
		/// rowIndexes holds an integer array of row indexes of all the quadratic terms. 
		/// A negative integer corresponds to an objective row, e.g. -1 for 1st objective and -2 for 2nd.																																											/// </summary>
		/// </summary>
		public int[] rowIndexes = null; 
	
		/// <summary>
		/// varOneIndexes holds an integer array of the first varialbe indexes of all the quadratic terms. 
		/// </summary>
		public int[] varOneIndexes = null; 

		/// <summary>
		/// varTwoIndexes holds an integer array of the second varialbe indexes of all the quadratic terms. 
		/// </summary>

		public int[] varTwoIndexes = null; 

		/// <summary>
		/// coefficients holds a double array all the quadratic term coefficients. 
		/// </summary>
		public double[] coefficients = null; 

		/// <summary>
		/// Default constructor. 
		/// </summary>
		public QuadraticTerms(){
		}//constructor

	}//class QuadraticTerms
}//namespace
