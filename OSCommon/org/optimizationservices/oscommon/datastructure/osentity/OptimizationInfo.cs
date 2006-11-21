using System;

namespace org.optimizationservices.oscommon.datastructure.osentity{
	/// <summary>
	/// A data structure class that corresponds to an xml element in the OSeL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OptimizationInfo{

		public string description = "";

		public string variableType = "";

		public string objectiveType = "";

		public string constraintType = "";

		public string objectiveLinearity = "";

		public string constraintLinearity = "";

		public string objectiveDifferentiability = "";

		public string constraintDifferentiability = "";

		public string parameterType = "";

		public string stochasticity = "";

		public bool realTime = false;
	
		public FunctionType functionType = null;

		public SpecialStructure specialStructure = null;

		public SpecialAlgorithm specialAlgorithm = null;

	}//class OptimizationInfo
}//namespace
