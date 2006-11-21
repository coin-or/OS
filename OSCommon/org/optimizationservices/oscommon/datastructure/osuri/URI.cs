using System;

namespace org.optimizationservices.oscommon.datastructure.osuri{
	/// <summary>
	/// A data structure class that corresponds to an xml element in the OSuL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class URI{

		public string serviceName = "";
	
		public string matchType = "exact";
	
		public bool licenseRequired = false;
	
		public bool userNameRequired = false;
	
		public bool passwordRequired = false;

		public string value = "";

	}//class URI
}//namespace
