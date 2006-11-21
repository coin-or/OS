using System;

using org.optimizationservices.oscommon.datastructure.osentity;

namespace org.optimizationservices.oscommon.datastructure.osquery{
	/// <summary>
	/// A data structure class that corresponds to an xml element in the OSqL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class StandardQuery{

		public string currentState = null;

		public string serviceType = "solver";
	
		public OptimizationInfo optimization = null;

	}//class StandardQuery
}//namespace
