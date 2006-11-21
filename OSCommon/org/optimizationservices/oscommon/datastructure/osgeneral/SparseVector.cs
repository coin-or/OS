using System;

namespace org.optimizationservices.oscommon.datastructure{
	/// <summary>
	/// The <c>SparseVector</c> class holds a two array 
	/// data structure for sparse representation of vector. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class SparseVector{

		/// <summary>
		/// indexes holds an integer array of indexes, which corresponding values are nonzero.
		/// </summary>
		public int[] indexes = null;

		/// <summary>
		/// values holds a double array of nonzero values.
		/// </summary>
		public double[] values = null;

		/// <summary>
		/// Default constructor. 
		/// </summary>
		public SparseVector(){
		}//constructor

	}//class SparseVector
}//namespace


