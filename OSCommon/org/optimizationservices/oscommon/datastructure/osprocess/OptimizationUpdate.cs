using System;

namespace org.optimizationservices.oscommon.datastructure.osprocess {
 	/// <summary>
	/// A data structure class that corresponds to an xml element in the OSpL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OptimizationUpdate{

		public int ObjectiveIdx = 0;
	
		public double updatedObjectiveValue = Double.NaN;

		public double updatedObjectiveLowerBound = Double.NaN;

		public double updatedObjectiveUpperBound = Double.NaN;
	
		public UpdatedVariableValues updatedVariableValues = null;
	
		public UpdatedVariableValuesString updatedVariableValuesString = null;
	
		public UpdatedVariableReducedCosts updatedVariableReducedCosts = null;
	
		public UpdatedConstraintValues updatedConstraintValues = null;
	
		public UpdatedDualValues updatedDualValues = null;

	}//class OptimizationUpdate
}//namespace
