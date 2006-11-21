using System;

namespace org.optimizationservices.oscommon.datastructure.osentity{
	/// <summary>
	/// A data structure class that corresponds to an xml element in the OSeL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class FunctionType{
	
		public bool general = false;

		public bool basic = true;

		public bool arithmetic = true;

		public bool trigonometric = false;

		public bool statistics = false;

		public bool probability = false;

		public bool relationalAndLogic = false;

		public bool userFunction = false;

		public bool simulation = false;


	}//class FunctionType
}//namespace
