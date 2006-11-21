using System;

using org.optimizationservices.oscommon.localinterface;

namespace org.optimizationservices.oscommon.localinterface{
	/// <summary>
	/// The <c>DefaultSolverService</c> class is a default abstract solver 
	/// that is to be implemented by a solver that needs to be implemented as an 
	/// optimization service using OSServiceUtil. 
	/// @see org.optimizationservices.oscommon.util.OSServiceUtil
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public abstract class DefaultSolver{
	
		/// <summary>
		/// osil holds the OSiL string (input)
		/// </summary>
		public string osil = "";
	
		/// <summary>
		/// osol holds the OSoL string (input)
		/// </summary>
		public string osol = "";

		/// <summary>
		/// osrl holds the OSrL string (output)
		/// </summary>
		public string osrl = "";

		/// <summary>
		/// osInstance holds OS instance object (input)
		/// </summary>
		public OSInstance osInstance = null;
	
		/// <summary>
		/// osOption holds the OS option object (input)
		/// </summary>
		public OSOption osOption = null;

		/// <summary>
		/// osResult holds the OS result object (output)
		/// </summary>
		public OSResult osResult = null;

		/// <summary>
		/// default constructor.
		/// </summary>
		public DefaultSolver(){

		}//constructor

		/// <summary>
		/// The solve method that is to be implemented by an OS solver service.  
		/// </summary>
		public abstract void solve();
	}//DefaultSolver
}//namespace