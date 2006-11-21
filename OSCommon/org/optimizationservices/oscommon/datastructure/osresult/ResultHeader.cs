using System;

namespace org.optimizationservices.oscommon.datastructure.osresult{
	/// <summary>
	/// A data structure class that corresponds to an xml element in the OSrL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class ResultHeader{
		
		public GeneralStatus generalStatus = new GeneralStatus();

		public string serviceURI = "";
		
		public string serviceName = "";

		public string instanceName = "";

		public string jobID = "";

		public DateTime time = new DateTime(1970, 1, 1, 0, 0, 0);

		public string message = "";

	}//class ResultHeader
}//namespace
