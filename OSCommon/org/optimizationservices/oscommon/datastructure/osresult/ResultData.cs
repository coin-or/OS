using System;

using org.optimizationservices.oscommon.datastructure.osprocess;

namespace org.optimizationservices.oscommon.datastructure.osresult{
	/// <summary>
	/// A data structure class that corresponds to an xml element in the OSrL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class ResultData{

		public OptimizationResult optimization = null;
		
		public ProcessStatistics statistics = null;
		
		public OtherResult[] other = null;

	}//class ResultData
}//namespace
