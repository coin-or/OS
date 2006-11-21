using System;

namespace org.optimizationservices.oscommon.datastructure.osinstance{
	/// <summary>
	/// A data structure class that corresponds to an xml element in the OSiL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class QuadraticCoefficients{

		public int numberOfQPTerms = 0;

		public QuadraticTerm[] qpTerm = null;

	}//class QuadraticCoefficients
}//namespace
