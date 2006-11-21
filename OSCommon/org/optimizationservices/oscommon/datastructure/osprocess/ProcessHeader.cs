using System;

namespace org.optimizationservices.oscommon.datastructure.osprocess{
	/// <summary>
	/// A data structure class that corresponds to an xml element in the OSpL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class ProcessHeader{
		
		public ProcessRequest request = null;

		public ProcessResponse response = null;
	
		public string serviceURI = "";

		public string serviceName = "";
	
		public DateTime time = new DateTime(1970, 1, 1, 0, 0, 0);

		public string message = "";

	}//class ProcessHeader
}//namespace
