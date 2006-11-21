using System;

namespace org.optimizationservices.oscommon.datastructure.osoption{
	/// <summary>
	/// A data structure class that corresponds to an xml element in the OSoL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class GeneralOption{

	
		public string serviceURI = "";

		public string serviceName = "";

		public String instanceName = "";	

		public InstanceLocationOption instanceLocation = null;

		public string jobID = "";
	
		public string license = "";
	
		public string userName = "";
	
		public string password = "";
	
		public ContactOption contact = null;

	}//class GeneralOption
}//namespace
