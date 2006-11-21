using System;

namespace org.optimizationservices.oscommon.datastructure.osentity{
	/// <summary>
	/// A data structure class that corresponds to an xml element in the OSeL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class SystemInfo{

		public string description = "";
	
		public double dedication = Double.NaN;
	
		public HardwareInfo hardware = null;

	}//class SystemInfo
}//namespace
