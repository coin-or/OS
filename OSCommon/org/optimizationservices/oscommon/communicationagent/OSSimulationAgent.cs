using System;
using System.Diagnostics;
using System.Xml.Serialization;
using System.Web.Services.Protocols;
using System.ComponentModel;
using System.Web.Services;

using org.optimizationservices.oscommon.communicationinterface;

namespace org.optimizationservices.oscommon.communicationagent{
	/// <summary>
	/// The <c>OSSimulationAgent</c> class implements all the methods in 
	/// <c>OScL</c> interface. Thus it is OS-type simulation agent. 
	/// It implements all the methods as specified in the
	/// OS Framework, specifically the OScL Language (OScL).
	/// The <c>OSSimulationAgent</c> class is a library class that 
	/// contains methods to help simulation agents communicate with 
	/// OS Simulations as specified by the OS framework. It hides all 
	/// the SOAP protocol related technical details from a simulation optimization user.
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	[System.Diagnostics.DebuggerStepThroughAttribute()]
	[System.ComponentModel.DesignerCategoryAttribute("code")]
	[System.Web.Services.WebServiceBindingAttribute(
		 Name="OSSimulationServiceSoapBinding", 
		 Namespace="http://www.optimizationservices.org")]
	public class OSSimulationAgent : System.Web.Services.Protocols.SoapHttpClientProtocol, OScL {
		public string simulationAddress{
			get{
				return this.Url;
			}
			set{
				this.Url = value;
			}
		}//simulationAddress

		/// <summary>
		/// default constructor
		/// </summary>
		public OSSimulationAgent(){
		}//constructor

		/// <summary>
		/// constructor
		/// </summary>
		/// <param name="simulationAddress">simulationAddress holds the address (uri/url) of the OS simulation.</param>
		public OSSimulationAgent(string simulationAddress){
			this.Url = simulationAddress;
		}//constructor



		/// <summary>
		/// Call a simulation service whose input is given by a string following 
		/// the OSsL schema, along with an option input that follows the OSoL schema,
		/// and returns the result in a string that also follows OSsL schema. 
		/// </summary>
		/// <param name="osslInput">holds the simulation input in a string which format follows OSsL schema</param>
		/// <param name="osol">holds the option in a string which format follows OSoL schema</param>
		/// <returns>osslOutput, the simulation result in a string which format follows the OSsL schema</returns>
		[System.Web.Services.Protocols.SoapRpcMethodAttribute("OSSimulationService#call", 
			 RequestNamespace="http://www.optimizationservices.org", 
			 ResponseNamespace="http://www.optimizationservices.org")]
		[return: System.Xml.Serialization.SoapElementAttribute("osslOutput")]
		public string call(string osslInput, string osol) {
			object[] results = this.Invoke("call", new object[] {osslInput, osol});
			return ((string)(results[0]));
		}//call
        
		/// <remarks/>
		public System.IAsyncResult beginCall(string osslInput, string osol, System.AsyncCallback callback, object asyncState) {
			return this.BeginInvoke("call", new object[] {osslInput, osol}, callback, asyncState);
		}//beginCall
        
		/// <remarks/>
		public string endCall(System.IAsyncResult asyncResult) {
			object[] results = this.EndInvoke(asyncResult);
			return ((string)(results[0]));
		}//endCall		

	}//class OSSimulationAgent
}//namespace
