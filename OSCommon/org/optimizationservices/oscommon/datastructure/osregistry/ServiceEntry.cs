using System;
using org.optimizationservices.oscommon.localinterface;

namespace org.optimizationservices.oscommon.datastructure.osregistry{
	/// <summary>
	/// A data structure class that corresponds to an xml element in the OSRegistry schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class ServiceEntry{


		public OSEntity osel = new OSEntity();

		public OSProcess ospl = new OSProcess();

		public OSBenchmark osbl = new OSBenchmark();

	}//class ServiceEntry
}//namespace
