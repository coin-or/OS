using System;

namespace org.optimizationservices.oscommon.datastructure.osentity{
	/// <summary>
	/// A data structure class that corresponds to an xml element in the OSeL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class EntityData{

		public GeneralInfo general = null;
	
		public SystemInfo system = null;
	
		public ServiceInfo service = null;
	
		public JobInfo job = null;
	
		public OptimizationInfo optimization = null;
	
		public OtherEntityInfo[] other = null;


	}//class EntityData
}//namespace
