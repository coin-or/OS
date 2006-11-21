using System;

using org.optimizationservices.oscommon.localinterface;

namespace org.optimizationservices.oscommon.datastructure.osresult{
	/// <summary>
	/// A data structure class that corresponds to an xml element in the OSrL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OptimizationResult{

		public int numberOfVariables = -1;
	
		public int numberOfObjectives = -1;

		public int numberOfConstraints = -1;

		public int numberOfSolutions = -1;

		public OptimizationSolution[] solution = null;
	
		public OSAnalysis osal = null;

	}//class OptimizationResult
}//namespace
