using System;

using org.optimizationservices.oscommon.localinterface;

namespace org.optimizationservices.oscommon.datastructure.osprocess{
	/// <summary>
	/// A data structure class that corresponds to an xml element in the OSpL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class JobOptimization{

		public String jobID = "";

		public StandardOptimizationProcessInformation standard = null;
	
		public OSResult osrl = new OSResult();

	}//class JobOptimization
}//namespace
