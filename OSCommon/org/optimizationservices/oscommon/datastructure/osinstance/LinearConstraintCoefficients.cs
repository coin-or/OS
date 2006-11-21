using System;
using org.optimizationservices.oscommon.datastructure.osgeneral;

namespace org.optimizationservices.oscommon.datastructure.osinstance{
	/// <summary>
	/// A data structure class that corresponds to an xml element in the OSiL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class LinearConstraintCoefficients{

		public int numberOfValues = 0;

		public IntVector start = new IntVector();
	
		public IntVector rowIdx = new IntVector();
	
		public IntVector colIdx = new IntVector();
	
		public DoubleVector value = new DoubleVector();

	}//class LinearConstraintCoefficients
}//namespace
