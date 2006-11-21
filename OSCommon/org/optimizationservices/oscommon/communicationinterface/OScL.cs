using System;

namespace org.optimizationservices.oscommon.communicationinterface{
	/// <summary>
	/// The <c>OScL</c> interface declares all the methods as specified in the 
	/// OScL WSDL. The specified methods are called by an OS agent to invoke 
	/// any OS-based simulation service. 
	/// Any simulation service that wants to become an OS-type callable on the 
	/// distributed system must implement this interface.  																* </p>
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public interface OScL{

	/// <summary>
	/// Call a simulation service whose input is given by a string following 
	/// the OSsL schema and returns the result in a string that also follows 
	/// OSsL schema, since OSsL specifies both simulation service input and output.
	/// </summary>
	/// <param name="osslInput">holds the simulation input in a string which format follows the OSsL schema.</param>
	/// <param name="osol">holds the option in a string which format follows OSoL schema</param>
	/// <returns>osslOutput, the simulation output in a string which format follows OSsL schema</returns>
	string call(string osslInput, string osol);
	
	}//interface OScL
}//namespace
