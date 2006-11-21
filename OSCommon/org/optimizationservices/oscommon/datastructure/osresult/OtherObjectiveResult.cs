using System;

namespace org.optimizationservices.oscommon.datastructure.osresult{
	/// <summary>
	/// A data structure class that corresponds to an xml element in the OSrL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OtherObjectiveResult{	
	
		public string name = "";
	
		public string description = "";
	
		public string value = "";

		public OtherObjResult[] obj = null;

	}//class OtherObjectiveResult
}//namespace
