using System;

using org.optimizationservices.oscommon.localinterface;

namespace org.optimizationservices.oscommon.localinterface{
	/// <summary>
	/// The <c>DefaultSimulationService</c> class is a default abstract simulation 
	/// that is to be implemented by a simulation that needs to be implemented as an 
	/// optimization service using OSServiceUtil. 
	/// @see org.optimizationservices.oscommon.util.OSServiceUtil
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public abstract class DefaultSimulation{
	
		/// <summary>
		/// osslInput holds the OSsL input string.
		/// </summary>
		public string osslInput = null;
	
		/// <summary>
		/// osol holds the OSoL string (input).
		/// </summary>
		public string osol = null;

		/// <summary>
		/// osslOutput holds the OSsL output string.
		/// </summary>
		public string osslOutput = null;
	
		/// <summary>
		/// osSimulationInput holds the OS simulation object (input).
		/// </summary>
		public OSSimulation osSimulationInput = null;

		/// <summary>
		/// osSimulationOutput holds the OS simulation object (output). 
		/// </summary>
		public OSSimulation osSimulationOutput = null;

		/// <summary>
		/// osOption holds the OS option object (input).
		/// </summary>
		public OSOption osOption = null;

		/// <summary>
		/// default constructor.
		/// </summary>
		public DefaultSimulation(){

		}//constructor

		/// <summary>
		/// The call method that is to be implemented by an OS simulation service.  
		/// </summary>
		public abstract void call();
	}//DefaultSimulation
}//namespace