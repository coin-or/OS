using System;

namespace org.optimizationservices.oscommon.datastructure.osinstance{
	/// <summary>
	/// A data structure class that corresponds to an xml element in the OSiL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class InstanceData{
	
		public Variables variables = new Variables();
	
		public Objectives objectives = new Objectives();
	
		public Constraints constraints = new Constraints();
	
		public LinearConstraintCoefficients linearConstraintCoefficients = new LinearConstraintCoefficients();
	
		public QuadraticCoefficients quadraticCoefficients = new QuadraticCoefficients();

		public NonlinearExpressions nonlinearExpressions = new NonlinearExpressions();
	
		public XMLData xmlData = new XMLData();

	}//class InstanceData
}//namespace
