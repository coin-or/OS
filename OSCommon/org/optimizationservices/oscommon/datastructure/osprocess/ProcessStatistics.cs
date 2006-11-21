using System;

namespace org.optimizationservices.oscommon.datastructure.osprocess{
	/// <summary>
	/// A data structure class that corresponds to an xml element in the OSpL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class ProcessStatistics{
		
		public string currentState = "noReponse";

		public double availableDiskSpace = Double.PositiveInfinity;
	
		public double availableMemory = Double.PositiveInfinity;

		public int currentJobCount = -1;

		public int totalJobsSoFar = -1;

		public DateTime timeLastJobEnded = new DateTime(1970, 1, 1, 0, 0, 0);

		public double timeLastJobTook = Double.NaN;

		public DateTime timeServiceStarted = new DateTime(1970, 1, 1, 0, 0, 0);

		public double serviceUtilization = Double.NaN;

		public Jobs jobs = null;

	}//class ProcessStatistics
}//namespace
