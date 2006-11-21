using System;

namespace org.optimizationservices.oscommon.communicationinterface{
	/// <summary>
	/// The <c>OSdL</c> interface declares all the methods as specified in the 
	/// OSdL WSDL. The specified methods are called by an OS agent to invoke 
	/// any OS-based registry discovery service. 
	/// Any registry service that wants to become an OS-type callable on the 
	/// distributed system must implement this interface.  																* </p>
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public interface OSdL{

		/// <summary>
		/// Register a service at an OS Registry service whose input is given by a string following 
		/// the OSeL schema, along with an option that follows the OSoL schema,
		/// and returns the registration process output in a string that follows OSpL schema. 
		/// </summary>
		/// <param name="osel">holds the service entity information in a string which format follows OSeL schema</param>
		/// <param name="osol">holds the option in a string which format follows OSoL schema</param>
		/// <returns>ospl, the registration process output in a string which format follows the OSpL schema</returns>
		string register(string osel, string osol);

		/// <summary>
		/// Find a service at an OS Registry service whose input query is given by a string following 
		/// the OSqL schema, along with an option that follows the OSoL schema,
		/// and returns the uri/url result in a string that follows OSuL schema. 
		/// </summary>
		/// <param name="osql">holds the instance in a string which format follows OSqL schema</param>
		/// <param name="osol">holds the option in a string which format follows OSoL schema</param>
		/// <returns>osul, the uri/url result in a string which format follows the OSuL schema</returns>
		string find(string osql, string osol);

		/// <summary>
		/// Validates an OSxL string at an OS Registry service whose input is any OSxL string following 
		/// the corresponding OSxL schema, along with an option that follows the OSoL schema,
		/// and returns the validation process output in a string that follows OSpL schema. 
		/// </summary>
		/// <param name="osxl">holds the OSxL string which format follows the corresponding schema</param>
		/// <param name="osol">holds the option in a string which format follows OSoL schema</param>
		/// <returns>ospl, the validation process output in a string which format follows the OSpL schema</returns>
		string validate(string osxl, string osol);

		/// <summary>
		/// Set (push) and/or get (pull) runtime dynamic process information to and/or from the service.  		
		/// </summary>
		/// <param name="osplInput"> the input process information in a string which format follows OSpL schema.</param>
		/// <param name="osol">holds the option in a string which format follows OSoL schema</param>
		/// <returns>osplOutput, the ouput process information in a string which format follows the OSpL schema.</returns>
		string knock(string osplInput, string osol);

	}//interface OSdL
}//namespace
