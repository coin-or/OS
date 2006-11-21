using System;

namespace org.optimizationservices.oscommon.datastructure.osentity{
	/// <summary>
	/// A data structure class that corresponds to an xml element in the OSeL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class AccessLimits{

		public double maxDiskSpace = Double.PositiveInfinity;

		public double maxMemory = Double.PositiveInfinity;

		public int maxJobs = -1;
	
		public int maxVariables = -1;

		public int maxBinaryVariables = -1;

		public int maxIntegerVariables = -1;

		public int maxObjectives = -1;

		public int maxConstraints = -1;

		public int maxNonzeroLinearConstraintCoefficients = -1;

	}//class AccessLimits
}//namespace
