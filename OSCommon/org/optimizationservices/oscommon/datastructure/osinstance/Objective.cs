using System;

namespace org.optimizationservices.oscommon.datastructure.osinstance{
	/// <summary>
	/// A data structure class that corresponds to an xml element in the OSiL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class Objective{

		public string name = "";
	
		public string maxOrMin = "min";
	
		public int numberOfObjCoef = 0;
		
		public double constant = 0.0;
	
		public double weight = 1.0;
	
		public ObjCoef[] coef = null;

	}//class Objective
}//namespace
