using System;
using System.Xml.Serialization;
using System.Diagnostics;
using System.Web.Services.Protocols;
using System.Web.Services.Description;
using System.ComponentModel;
using System.Web.Services;
using System.Web;
using System.Collections;
using System.Data;
using System.Threading;
using System.IO;
using System.Reflection;

using org.optimizationservices.ossolver.solver;
using org.optimizationservices.oscommon.util;
using org.optimizationservices.oscommon.communicationinterface;
using org.optimizationservices.oscommon.localinterface;

/// <summary>
/// <c>SolverService</c> is the Solver's Web Service facade. 
/// @author Jun Ma	
/// @version 1.0, 09/01/2005
/// @since OS 1.0
/// @copyright (c) 2005
/// </summary>
[WebService(Namespace="http://www.optimizationservices.org")]	
[System.Web.Services.WebServiceBindingAttribute(Name="OSSolverServiceSoapBinding", Namespace="http://www.optimizationservices.org")]
[SoapDocumentService(SoapBindingUse.Default, SoapParameterStyle.Default, RoutingStyle=SoapServiceRoutingStyle.RequestElement)]
public class SolverService : System.Web.Services.WebService, OShL{
	/// <summary>
	/// m_osServiceUtil holds a default implementation of the solver service.  
	/// </summary>
	private OSServiceUtil m_osServiceUtil =  new OSServiceUtil();
	
	/// <summary>
	/// default constructor.
	/// </summary>
	public SolverService(){
		//CODEGEN: This call is required by the ASP.NET Web Services Designer
		InitializeComponent();
		m_osServiceUtil.serviceName = OSParameter.SERVICE_NAME;
		m_osServiceUtil.serviceURI = OSParameter.SERVICE_URI;
		m_osServiceUtil.serviceType = "solver";
		try {
			string sSolverClassName = OSParameter.SOLVER_CLASS_NAME; //"org.optimizationservices.ossolver.solver.StandardSolver";
			Type solverType;
			if(OSParameter.SOLVER_LIBRARY != null && OSParameter.SOLVER_LIBRARY.Length > 0 && 
				!OSParameter.SOLVER_LIBRARY.StartsWith("OSSolver")){
				Assembly assembly = Assembly.LoadFrom(OSParameter.SOLVER_LIBRARY);
				solverType = assembly.GetType(sSolverClassName);
			}
			else{
				solverType = Type.GetType(sSolverClassName);
			}
			
			m_osServiceUtil.solver = (DefaultSolver)Activator.CreateInstance(solverType);
		} 
		catch (Exception e) {
			IOUtil.log(e.ToString(), null);
		}		
	}//constructor

	#region Component Designer generated code
	
	//Required by the Web Services Designer 
	private IContainer components = null;
			
	/// <summary>
	/// Required method for Designer support - do not modify
	/// the contents of this method with the code editor.
	/// </summary>
	private void InitializeComponent() {
	}

	/// <summary>
	/// Clean up any resources being used.
	/// </summary>
	protected override void Dispose( bool disposing ) {
		if(disposing && components != null) {
			components.Dispose();
		}
		base.Dispose(disposing);		
	}
	
	#endregion
	
	/// <summary>
	/// get a job id 
	/// </summary>
	/// <param name="osol">option for job id retrieval</param>
	/// <returns>a jobID string</returns>
	[System.Web.Services.WebMethodAttribute()]
	[System.Web.Services.Protocols.SoapRpcMethodAttribute("OSSolverService#getJobID", 
		 RequestNamespace="http://www.optimizationservices.org", 
		 ResponseNamespace="http://www.optimizationservices.org")]
	[return: System.Xml.Serialization.SoapElementAttribute("jobID")]
	public string getJobID(string osol){
		return m_osServiceUtil.getJobID(osol);
	}//getJobID
	
	/// <summary>
	/// a synchronous solve method with instance and option for the solver
	/// </summary>
	/// <param name="osil">input instance</param>
	/// <param name="osol">input option</param>
	/// <returns>result, null if any error.</returns>
	[System.Web.Services.WebMethodAttribute()]
	[System.Web.Services.Protocols.SoapRpcMethodAttribute("OSSolverService#solve", 
		 RequestNamespace="http://www.optimizationservices.org", 
		 ResponseNamespace="http://www.optimizationservices.org")]
	[return: System.Xml.Serialization.SoapElementAttribute("osrl")]	
	public string solve(string osil, string osol){
		return m_osServiceUtil.solve(osil, osol);
	}//solve

	/// <summary>
	/// An asynchronous send method with instance and option for the solver. 
	/// The option must contain a job id so that the job result can be retrieved later. 
	/// </summary>
	/// <param name="osil">input instance</param>
	/// <param name="osol">input option</param>
	/// <returns>whether the instance and option are sent and received by this method successfully</returns>
	[System.Web.Services.WebMethodAttribute()]
	[System.Web.Services.Protocols.SoapRpcMethodAttribute("OSSolverService#send", 
		 RequestNamespace="http://www.optimizationservices.org", 
		 ResponseNamespace="http://www.optimizationservices.org")]
	[return: System.Xml.Serialization.SoapElementAttribute("success")]
	public bool send(string osil, string osol){
		return m_osServiceUtil.send(osil, osol);
	}//send

	/// <summary>
	/// Retrieve a previously sent job's result with a job id. If the job result is not ready, an empty string 
	/// will be returned.  
	/// </summary>
	/// <param name="osol">input option, that contains the job id.</param>
	/// <returns>Retrieved result in a string, null or empty if result not ready.</returns>
	[System.Web.Services.WebMethodAttribute()]
	[System.Web.Services.Protocols.SoapRpcMethodAttribute("OSSolverService#retrieve", 
		 RequestNamespace="http://www.optimizationservices.org", 
		 ResponseNamespace="http://www.optimizationservices.org")]
	[return: System.Xml.Serialization.SoapElementAttribute("osrl")]		
	public string retrieve(string osol){
		return m_osServiceUtil.retrieve(osol);
	}//retrieve

	/// <summary>
	/// Kill a previously sent job.
	/// </summary>
	/// <param name="osol">input option, that contains the job id</param>
	/// <returns>the kill process status of the kill operation</returns>
	[System.Web.Services.WebMethodAttribute()]
	[System.Web.Services.Protocols.SoapRpcMethodAttribute("OSSolverService#kill", 
		 RequestNamespace="http://www.optimizationservices.org", 
		 ResponseNamespace="http://www.optimizationservices.org")]
	[return: System.Xml.Serialization.SoapElementAttribute("ospl")]
	public string kill(string osol){
		return m_osServiceUtil.kill(osol);
	}//kill

	/// <summary>
	/// Set (push) and/or get (pull) runtime dynamic process information to and/or from the service.  		
	/// </summary>
	/// <param name="osplInput"> the input process information in a string which format follows OSpL schema.</param>
	/// <param name="osol">holds the option in a string which format follows OSoL schema</param>
	/// <returns>the output process information in a string which format follows the OSpL schema.</returns>
	[System.Web.Services.WebMethodAttribute()]
	[System.Web.Services.Protocols.SoapRpcMethodAttribute("OSSolverService#knock", 
		 RequestNamespace="http://www.optimizationservices.org", 
		 ResponseNamespace="http://www.optimizationservices.org")]
	[return: System.Xml.Serialization.SoapElementAttribute("osplOutput")]	
	public string knock(string osplInput, string osol){
		return m_osServiceUtil.knock(osplInput, osol);
	}//knock

	/// <summary>
	/// static constructor
	/// </summary>
	static SolverService(){
		OSParameterFile.NAME = "/code/OSConfig/OSParameter.xml";
	}//static constructor
}//SolverService
