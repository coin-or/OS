using System;

namespace org.optimizationservices.oscommon.datastructure{
	/// <summary>
	/// The <c>SparseMatrix</c> class holds the 3 list 
	/// data structure usually used for linear constraint coefficients  
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class SparseMatrix{
	
		/// <summary>
		/// isColumnMajor holds whether the coefMatrix (AMatrix) holding linear program
		/// data is stored by column. If false, the matrix is stored by row.
		/// </summary>
		public bool isColumnMajor = true;

		/// <summary>
		/// starts holds an integer array of start elements in coefMatrix (AMatrix),
		/// which points to the start of a column (row) of nonzero elements in coefMatrix (AMatrix).
		/// </summary>
		public int[] starts = null; 
	
		/// <summary>
		/// indexes holds an integer array of rowIdx (or colIdx) elements in coefMatrix (AMatrix).
		/// If the matrix is stored by column (row), rowIdx (colIdx) is the array of row (column) indices.
		/// </summary>
		public int[] indexes = null;

		/// <summary>
		/// values holds a double array of value elements in coefMatrix (AMatrix),
		/// which contains nonzero elements.
		/// </summary>
		public double[] values = null;

		/// <summary>
		/// Default constructor. 
		/// </summary>
		public SparseMatrix(){
		}//constructor

		/// <summary>
		/// Constructor
		/// </summary>
		/// <param name="isColumnMajor">holds whether the coefMatrix (AMatrix) holding linear program
		/// data is stored by column. If false, the matrix is stored by row.</param>
		/// <param name="startSize">holds the size of the start array.</param>
		/// <param name="valueSize">holds the size of the value and index arrays.</param>
		public SparseMatrix(bool isColumnMajor, int startSize, int valueSize){
			this.isColumnMajor = isColumnMajor; 
			starts = new int[startSize];
			indexes = new int[valueSize];
			values = new double[valueSize];		
		}//constructor

		/// <summary>
		/// This method displays data structure in the matrix format.
		/// </summary>
		/// <returns>whether display is successful </returns>
		public bool display(int secondaryDim){
			int i, j, k;
			for ( i = 0; i < starts.Length - 1; i++){			
				if (starts[i] == starts[i + 1]){
					for ( k = 0; k < secondaryDim; k++){
						Console.Write("0,");					
					}				
				}
				else {
					for ( j = 0; j < indexes[starts[i]]; j ++){				
						Console.Write("0,");					
					}
					for ( j = starts[ i ]; j < starts[i + 1]; j++){
						Console.Write(values[j] + ",");
						if ( j < starts[i + 1] - 1){
							for ( k = indexes [j] + 1; k < indexes[j + 1]; k++){
								Console.Write("0,");					
							}
						}
						else{
							for ( k = indexes [j] + 1; k < secondaryDim; k++){
								Console.Write("0,");					
							}
						}
					}
				}
				Console.WriteLine();
			}
			return true;
		}//display

	}//class SparseMatrix
}//namespace
