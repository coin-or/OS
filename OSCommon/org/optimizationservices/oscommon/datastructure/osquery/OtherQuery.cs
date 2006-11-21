using System;

namespace org.optimizationservices.oscommon.datastructure.osquery{
	/// <summary>
	/// A data structure class that corresponds to an xml element in the OSqL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OtherQuery{
		
		public string name = "";

		public string value = "";

		public string description = "";

		public string type = "exact";

	}//class OtherQuery
}//namespace
