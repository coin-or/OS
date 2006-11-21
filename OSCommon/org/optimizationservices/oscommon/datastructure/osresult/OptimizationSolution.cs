using System;

namespace org.optimizationservices.oscommon.datastructure.osresult{
	/// <summary>
	/// A data structure class that corresponds to an xml element in the OSrL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OptimizationSolution{

		public int objectiveIdx = 0;
	
		public OptimizationSolutionStatus status = new OptimizationSolutionStatus();
	
		public string message = "";
	
		public VariableSolution variables = null;
	
		public ObjectiveSolution objectives = null;
	
		public ConstraintSolution constraints = null;
	
		public OtherOptimizationResult[] other = null;


	}//class OptimizationSolution
}//namespace
