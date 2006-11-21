using System;

namespace org.optimizationservices.oscommon.datastructure.osentity{
	/// <summary>
	/// A data structure class that corresponds to an xml element in the OSeL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class HardwareInfo{

		public int cpuNumber = 1;
	
		public double cpuSpeed = Double.NaN;

		public double memorySize = Double.NaN;

		public double busSpeed = Double.NaN;

		public double diskSpace = Double.NaN;

		public double nicSpeed = Double.NaN;

		public double downloadSpeed = Double.NaN;

		public double uploadSpeed = Double.NaN;

	}//class HardwareInfo
}//namespace
