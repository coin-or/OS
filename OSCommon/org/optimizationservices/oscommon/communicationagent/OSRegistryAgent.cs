using System;
using System.Diagnostics;
using System.Xml.Serialization;
using System.Web.Services.Protocols;
using System.ComponentModel;
using System.Web.Services;

using org.optimizationservices.oscommon.communicationinterface;

namespace org.optimizationservices.oscommon.communicationagent{
	/// <summary>
	/// The <c>OSRegistryAgent</c> class implements all the methods in 
	/// <c>OSdL</c> interface. Thus it is OS-type registry agent. 
	/// It implements all the methods as specified in the
	/// OS Framework, specifically the OSdL Language (OSdL).
	/// The <c>OSRegistryAgent</c> class is a library class that 
	/// contains methods to help registry agents communicate with an
	/// OS Registry as specified by the OS framework, in particular it allows clients
	/// to find and register OS Services and validate OSxL arguments. It hides all 
	/// the SOAP protocol related technical details from an optimization user.
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	[System.Diagnostics.DebuggerStepThroughAttribute()]
	[System.ComponentModel.DesignerCategoryAttribute("code")]
	[System.Web.Services.WebServiceBindingAttribute(
		 Name="OSRegistryServiceSoapBinding", 
		 Namespace="http://www.optimizationservices.org")]
	public class OSRegistryAgent : System.Web.Services.Protocols.SoapHttpClientProtocol, OSdL {
		public string registryAddress{
			get{
				return this.Url;
			}
			set{
				this.Url = value;
			}
		}//registryAddress

		/// <summary>
		/// default constructor
		/// </summary>
		public OSRegistryAgent(){
		}//constructor

		/// <summary>
		/// constructor
		/// </summary>
		/// <param name="registryAddress">registryAddress holds the address (uri/url) of the OS registry.</param>
		public OSRegistryAgent(string registryAddress){
			this.Url = registryAddress;
		}//constructor

		/// <summary>
		/// Find a service at an OS Registry service whose input query is given by a string following 
		/// the OSqL schema, along with an option that follows the OSoL schema,
		/// and returns the uri/url result in a string that follows OSuL schema. 
		/// </summary>
		/// <param name="osql">holds the instance in a string which format follows OSqL schema</param>
		/// <param name="osol">holds the option in a string which format follows OSoL schema</param>
		/// <returns>osul, the uri/url result in a string which format follows the OSuL schema</returns>
		[System.Web.Services.Protocols.SoapRpcMethodAttribute("OSRegistryService#find", 
			 RequestNamespace="http://www.optimizationservices.org", 
			 ResponseNamespace="http://www.optimizationservices.org")]
		[return: System.Xml.Serialization.SoapElementAttribute("osul")]
		public string find(string osql, string osol) {
			object[] results = this.Invoke("find", new object[] {osql, osol});
			return ((string)(results[0]));
		}//find

		/// <summary>
		/// Register a service at an OS Registry service whose input is given by a string following 
		/// the OSeL schema, along with an option that follows the OSoL schema,
		/// and returns the registration process output in a string that follows OSpL schema. 
		/// </summary>
		/// <param name="osel">holds the service entity information in a string which format follows OSeL schema</param>
		/// <param name="osol">holds the option in a string which format follows OSoL schema</param>
		/// <returns>ospl, the registration process output in a string which format follows the OSpL schema</returns>
		[System.Web.Services.Protocols.SoapRpcMethodAttribute("OSRegistryService#register", 
			 RequestNamespace="http://www.optimizationservices.org", 
			 ResponseNamespace="http://www.optimizationservices.org")]
		[return: System.Xml.Serialization.SoapElementAttribute("ospl")]
		public string register(string osel, string osol) {
			object[] results = this.Invoke("register", new object[] {osel, osol});
			return ((string)(results[0]));
		}//register
        
		/// <summary>
		/// Validates an OSxL string at an OS Registry service whose input is any OSxL string following 
		/// the corresponding OSxL schema, along with an option that follows the OSoL schema,
		/// and returns the validation process output in a string that follows OSpL schema. 
		/// </summary>
		/// <param name="osxl">holds the OSxL string which format follows the corresponding schema</param>
		/// <param name="osol">holds the option in a string which format follows OSoL schema</param>
		/// <returns>ospl, the validation process output in a string which format follows the OSpL schema</returns>
		[System.Web.Services.Protocols.SoapRpcMethodAttribute("OSRegistryService#validate", 
			 RequestNamespace="http://www.optimizationservices.org", 
			 ResponseNamespace="http://www.optimizationservices.org")]
		[return: System.Xml.Serialization.SoapElementAttribute("ospl")]
		public string validate(string osxl, string osol) {
			object[] results = this.Invoke("validate", new object[] {osxl, osol});
			return ((string)(results[0]));
		}//validate

		/// <summary>
		/// Set (push) and/or get (pull) runtime dynamic process information to and/or from the service.  		
		/// </summary>
		/// <param name="osplInput"> the input process information in a string which format follows OSpL schema.</param>
		/// <param name="osol">holds the option in a string which format follows OSoL schema</param>
		/// <returns>the output process information in a string which format follows the OSpL schema.</returns>
		[System.Web.Services.Protocols.SoapRpcMethodAttribute("OSRegistryService#knock", 
			 RequestNamespace="http://www.optimizationservices.org", 
			 ResponseNamespace="http://www.optimizationservices.org")]
		[return: System.Xml.Serialization.SoapElementAttribute("osplOutput")]
		public string knock(string osplInput, string osol) {
			object[] results = this.Invoke("knock", new object[] {osplInput, osol});
			return ((string)(results[0]));
		}//knock


	}//class OSRegistryAgent
}//namespace
