using System;

namespace org.optimizationservices.oscommon.datastructure.osinstance{
	/// <summary>
	/// A data structure class that corresponds to an xml element in the OSiL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class Variable{

		public string name = "";
	
		public double init = Double.NaN;
	
		public string initString = "";
	
		public char type = 'C';
	
		public double lb = 0;
	
		public double ub = Double.PositiveInfinity;

	}//class Variable
}//namespace
