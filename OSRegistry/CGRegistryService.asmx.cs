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

using org.optimizationservices.oscommon.util;
using org.optimizationservices.oscommon.communicationinterface;
using org.optimizationservices.oscommon.localinterface;
using org.optimizationservices.oscommon.datastructure.osregistry;
using org.optimizationservices.oscommon.datastructure.osprocess;
using org.optimizationservices.oscommon.datastructure.osentity;
using org.optimizationservices.oscommon.datastructure.osgeneral;
using org.optimizationservices.oscommon.representationparser;


/// <summary>
/// <c>CGRegistryService</c> is the CG Registry's Web Service facade. 
/// @author Jun Ma	
/// @version 1.0, 09/01/2005
/// @since OS 1.0
/// @copyright (c) 2005
/// </summary>
[WebService(Namespace="http://www.optimizationservices.org")]	
[System.Web.Services.WebServiceBindingAttribute(Name="OSRegistryServiceSoapBinding", Namespace="http://www.optimizationservices.org")]
[SoapDocumentService(SoapBindingUse.Default, SoapParameterStyle.Default, RoutingStyle=SoapServiceRoutingStyle.RequestElement)]
public class CGRegistryService : System.Web.Services.WebService, OSdL{
	/// <summary>
	/// m_osServiceUtil holds a default implementation of the registry service.  
	/// </summary>
	private OSServiceUtil m_osServiceUtil = new OSServiceUtil();

	/// <summary>
	/// default constructor.
	/// </summary>
	public CGRegistryService(){
		//CODEGEN: This call is required by the ASP.NET Web Services Designer
		InitializeComponent();
		if(OSParameter.SCHEDULER_WITH_REGISTRY){
			DefaultRegistry.m_sRegistryServiceName = "OSRegistryService";
			m_osServiceUtil.serviceName = DefaultRegistry.m_sRegistryServiceName;
		}
		else{
			m_osServiceUtil.serviceName = OSParameter.SERVICE_NAME;
		}
		m_osServiceUtil.serviceURI = OSParameter.OS_REGISTRY_SITE;
		m_osServiceUtil.serviceType = "registry";
		m_osServiceUtil.registry = new DefaultRegistry();

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
	/// Find a service at an OS Registry service whose input query is given by a string following 
	/// the OSqL schema, along with an option that follows the OSoL schema,
	/// and returns the uri/url result in a string that follows OSuL schema. 
	/// </summary>
	/// <param name="osql">holds the instance in a string which format follows OSqL schema</param>
	/// <param name="osol">holds the option in a string which format follows OSoL schema</param>
	/// <returns>osul, the uri/url result in a string which format follows the OSuL schema</returns>
	[System.Web.Services.WebMethodAttribute()]
	[System.Web.Services.Protocols.SoapRpcMethodAttribute("OSRegistryService#find", 
		 RequestNamespace="http://www.optimizationservices.org", 
		 ResponseNamespace="http://www.optimizationservices.org")]
	[return: System.Xml.Serialization.SoapElementAttribute("osul")]
	public string find(string osql, string osol){
		return m_osServiceUtil.find(osql, osol);
	}//find
	
	/// <summary>
	/// Register a service at an OS Registry service whose input is given by a string following 
	/// the OSeL schema, along with an option that follows the OSoL schema,
	/// and returns the registration process output in a string that follows OSpL schema. 
	/// </summary>
	/// <param name="osel">holds the service entity information in a string which format follows OSeL schema</param>
	/// <param name="osol">holds the option in a string which format follows OSoL schema</param>
	/// <returns>ospl, the registration process output in a string which format follows the OSpL schema</returns>
	[System.Web.Services.WebMethodAttribute()]
	[System.Web.Services.Protocols.SoapRpcMethodAttribute("OSRegistryService#register", 
		 RequestNamespace="http://www.optimizationservices.org", 
		 ResponseNamespace="http://www.optimizationservices.org")]
	[return: System.Xml.Serialization.SoapElementAttribute("ospl")]	
	public string register(string osel, string osol){
		return m_osServiceUtil.register(osel, osol);
	}//register

	/// <summary>
	/// Validates an OSxL string at an OS Registry service whose input is any OSxL string following 
	/// the corresponding OSxL schema, along with an option that follows the OSoL schema,
	/// and returns the validation process output in a string that follows OSpL schema. 
	/// </summary>
	/// <param name="osxl">holds the OSxL string which format follows the corresponding schema</param>
	/// <param name="osol">holds the option in a string which format follows OSoL schema</param>
	/// <returns>ospl, the validation process output in a string which format follows the OSpL schema</returns>
	[System.Web.Services.WebMethodAttribute()]
	[System.Web.Services.Protocols.SoapRpcMethodAttribute("OSRegistryService#validate", 
		 RequestNamespace="http://www.optimizationservices.org", 
		 ResponseNamespace="http://www.optimizationservices.org")]
	[return: System.Xml.Serialization.SoapElementAttribute("ospl")]	
	public string validate(string osxl, string osol){
		return m_osServiceUtil.validate(osxl, osol);
	}//validate

	/// <summary>
	/// Set (push) and/or get (pull) runtime dynamic process information to and/or from the service.  		
	/// </summary>
	/// <param name="osplInput"> the input process information in a string which format follows OSpL schema.</param>
	/// <param name="osol">holds the option in a string which format follows OSoL schema</param>
	/// <returns>osplOutput, the ouput process information in a string which format follows the OSpL schema.</returns>
	[System.Web.Services.WebMethodAttribute()]
	[System.Web.Services.Protocols.SoapRpcMethodAttribute("OSRegistryService#knock", 
		 RequestNamespace="http://www.optimizationservices.org", 
		 ResponseNamespace="http://www.optimizationservices.org")]
	[return: System.Xml.Serialization.SoapElementAttribute("osplOutput")]	
	public string knock(string osplInput, string osol){
		return m_osServiceUtil.knock(osplInput, osol);
	}//knock

	/// <summary>
	/// static constructor
	/// </summary>
	static CGRegistryService(){
		OSParameterFile.NAME = "c:/code/OSConfig/OSParameter.xml";
	}//static constructor
}//CGRegistryService


		/*
		org.optimizationservices.oscommon.localinterface.OSRegistry osRegistry = new org.optimizationservices.oscommon.localinterface.OSRegistry();
		osRegistry.description = "CGRegistryService";
		osRegistry.news = new News();
		osRegistry.news.el = new NewsElement[1];
		osRegistry.news.el[0] = new NewsElement();
		osRegistry.news.el[0].time = DateTime.Now;
		osRegistry.news.el[0].value = "Welcome to the CGRegistryService";

		int iServiceNumber = 2;
		string[] msSolverServiceNames ={
			"CGSolverService0", 
			"CGSolverService1"};
		string[] msSolverServiceURIs ={
			"http://localhost/OSSolver/CGSolverService.asmx",
			"http://localhost:8080/os/ossolver/CGSolverService.jws"};
		osRegistry.service = new org.optimizationservices.oscommon.datastructure.osregistry.ServiceEntry[iServiceNumber];
		for(int i = 0; i < iServiceNumber; i++){
			osRegistry.service[i] = new org.optimizationservices.oscommon.datastructure.osregistry.ServiceEntry();
			osRegistry.service[i].osel.setServiceName(msSolverServiceNames[i]);
			osRegistry.service[i].osel.setServiceURI(msSolverServiceURIs[i]);
			
			osRegistry.service[i].ospl.setServiceName(msSolverServiceNames[i]);
			osRegistry.service[i].ospl.setServiceURI(msSolverServiceURIs[i]);
			osRegistry.service[i].ospl.setProcessTime(DateTime.Now);
			osRegistry.service[i].ospl.setProcessMessage("welcome");
			osRegistry.service[i].ospl.setProcessStatistics(new ProcessStatistics());
			DefaultRegistry.serviceHashTable.Add(msSolverServiceURIs[i], osRegistry.service[i]);
		}
		DefaultRegistry.osRegistry = osRegistry;	
		*/
