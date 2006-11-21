using System;

namespace org.optimizationservices.oscommon.datastructure.osentity{
	/// <summary>
	/// A data structure class that corresponds to an xml element in the OSeL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class SpecialAlgorithm{

		public bool decomposition = false;
	
		public bool globalOptimization = false;

		public bool dynamicProgramming = false;

		public bool heuristic = false;


	}//class SpecialAlgorithm
}//namespace
