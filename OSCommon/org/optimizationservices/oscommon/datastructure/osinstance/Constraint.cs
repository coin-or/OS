using System;

namespace org.optimizationservices.oscommon.datastructure.osinstance{
	/// <summary>
	/// A data structure class that corresponds to an xml element in the OSiL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class Constraint{

		public string name = "";
	
		public double lb = Double.NegativeInfinity;
	
		public double ub = Double.PositiveInfinity;

		public double constant = 0.0;

	}//class Constraint
}//namespace
