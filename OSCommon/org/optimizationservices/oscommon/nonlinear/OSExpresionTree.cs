using System;

namespace org.optimizationservices.oscommon.nonlinear{
	/// <summary>
	/// The <c>OSExpressionTree</c> class represents an expression tree for a
	/// nonlinear function (linear ones being special cases) and provide convenience
	/// methods to process the contained nonlinear function. In essence it contains
	/// the root node (of OSnLNode type) of an expression and hides all the internal
	/// nodes. It is the only public class that interfaces with any component (e.g. a
	/// solver) that needs to manipulate the nonlinear functions in an instance. For
	/// example, it is mainly used in the osilReader class to parse a nonlinear instance. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OSExpressionTree{
	
		/// <summary>
		/// Default constructor. 
		/// </summary>
		public OSExpressionTree(){
		}//constructor

		///TODO: implement OSExpressionTree

	}//class OSExpressionTree
}//namespace
