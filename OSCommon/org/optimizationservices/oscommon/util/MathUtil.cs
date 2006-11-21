using System;
using org.optimizationservices.oscommon.datastructure;
namespace org.optimizationservices.oscommon.util{
	/// <summary>
	/// The <c>MathUtil</c> class contains methods for performing
	/// math related operations used by all other classes and projects
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class MathUtil{
		public MathUtil(){
		}//constructor

		/// <summary>
		/// Round a double number to the precision specified. 
		/// </summary>
		/// <param name="x"> holds the number to be rounded. </param>
		/// <param name="precision">precision holds the number of digit after (or before if negative) the decimal point. </param>
		/// <returns>the rounded number</returns>
		public static double round (double x, int precision){
			double mask = 0.0, y, result;		
			try{
				mask = Math.Pow (10.0, -(double)precision);
			}
			catch(ArithmeticException){
				return x;
			}
			y  = mod(x, mask);
			result  = x - y;
			if (y / mask >= 0.5) result += mask;
			return result;
		}//round

		/// <summary>
		///Calculation of x mod y. 
		/// </summary>
		/// <param name="x">holds the number before the mod operator. </param>
		/// <param name="y">holds the number after the mod operator. </param>
		/// <returns>the result of x mod y. </returns>		
		public static double mod (double x, double y){
			return  x - Math.Floor(x / y) * y;
		}//mod

		/// <summary>
		/// convert linear constraint coefficient matrix (row or column major) to the other major (column or row)
		/// </summary>
		/// <param name="isColumnMajor">holds whether the coefMatrix (AMatrix) holding linear program
		/// data is stored by column. If false, the matrix is stored by row.</param>
		/// <param name="start">holds an integer array of start elements in coefMatrix (AMatrix),
		/// which points to the start of a column (row) of nonzero elements in coefMatrix (AMatrix).</param>
		/// <param name="index">holds an integer array of rowIdx (or colIdx) elements in coefMatrix (AMatrix).
		/// If the matrix is stored by column (row), rowIdx (colIdx) is the array of row (column) indices.</param>
		/// <param name="value">holds a double array of value elements in coefMatrix (AMatrix),
		/// which contains nonzero elements.</param>
		/// <param name="dimension">holds the column count if the input matrix is row major (row count = start.length-1)
		/// or the row number if the input matrix is column major (columnh count = start.length -1)</param>
		/// <returns>Linear constraint coefficient matrix in the other major of the input matrix. Return null if input matrix not valid.</returns>
		public static SparseMatrix convertLinearConstraintCoefficientMatrixToTheOtherMajor(
			bool isColumnMajor, int[] start, int[] index, double[] value, int dimension){
			if(start == null || start.Length <= 1 ) return null;
			if(value == null || index == null || value.Length != index.Length) return null;	
		
			int iStartSize = dimension + 1;
			SparseMatrix matrix = new SparseMatrix( !isColumnMajor, iStartSize, value.Length);		
		
			int i,j, iTemp;
			int iNumSource = start.Length - 1;
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


	}//class MathUtil
}//namespace
