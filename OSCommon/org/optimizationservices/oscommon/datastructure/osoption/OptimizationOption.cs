using System;

namespace org.optimizationservices.oscommon.datastructure.osoption{
	/// <summary>
	/// A data structure class that corresponds to an xml element in the OSoL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OptimizationOption{

		public int numberOfVariables = -1;
	
		public int numberOfObjectives = -1;

		public int numberOfConstraints = -1;

		public VariableOption variables = null;
	
		public ObjectiveOption objectives = null;
	
		public ConstraintOption constraints = null;
	
		public OtherOption[] other = null;

	}//class OptimizationOption
}//namespace
