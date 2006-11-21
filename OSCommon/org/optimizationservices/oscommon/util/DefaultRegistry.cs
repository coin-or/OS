using System;
using System.Collections;
using System.Timers;
using System.Xml;
using System.Threading;
using System.Text;

using org.optimizationservices.oscommon.localinterface;
using org.optimizationservices.oscommon.representationparser;
using org.optimizationservices.oscommon.util;
using org.optimizationservices.oscommon.datastructure.osregistry;
using org.optimizationservices.oscommon.datastructure.osuri;
using org.optimizationservices.oscommon.communicationagent;
using org.optimizationservices.oscommon.datastructure.osgeneral;
using org.optimizationservices.oscommon.datastructure.osprocess;
using org.optimizationservices.oscommon.datastructure.osquery;

namespace org.optimizationservices.oscommon.util{
	/// <summary>
	/// The <c>DefaultRegistryService</c> class is a default registry 
	/// that is to be implemented by a registry that needs to be implemented as an 
	/// optimization service using OSServiceUtil. 
	/// @see org.optimizationservices.oscommon.util.OSServiceUtil
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class DefaultRegistry{
		/// <summary>
		/// m_sRegistryServiceName holds the registry service name.
		/// </summary>
		public static string m_sRegistryServiceName = "OSRegistryService";

		/// <summary>
		/// m_sSystemPassword holds the password used for communication between system components.
		/// </summary>
		private static string m_sSystemPassword = "";

		/// <summary>
		/// m_bValidate holds whether the parser should be validating against the xml schema or not.
		/// </summary>
		protected internal bool m_bValidate = OSParameter.VALIDATE; 

		/// <summary>
		/// serviceName holds the service name. 
		/// </summary>
		public string serviceName = m_sRegistryServiceName;
	
		/// <summary>
		/// serviceURI holds the service uri. 
		/// </summary>
		public string serviceURI = OSParameter.OS_REGISTRY_SITE;

		/// <summary>
		/// serviceType holds the service type. 
		/// </summary>
		public string serviceType = "registry";

		/// <summary>
		/// m_sInstanceName holds the name of the instance being solved.
		/// </summary>
		protected internal string m_sInstanceName = "";

		/// <summary>
		/// m_sJobID holds the job ID;
		/// </summary>
		protected internal string m_sJobID = "";
		
		/// <summary>
		/// m_sLicense holds the license. 
		/// </summary>
		protected internal string m_sLicense = "";

		/// <summary>
		/// m_sUserName holds the user name.  
		/// </summary>
		protected internal string m_sUserName = "";

		/// <summary>
		/// m_sPassword holds the password. 
		/// </summary>
		protected string m_sPassword = "";

		/// <summary>
		/// m_sContactTransportType holds the constact transport type. 
		/// </summary>
		protected internal string m_sContactTransportType = "";

		/// <summary>
		/// m_sContactAddress holds the contact address. 
		/// </summary>
		protected internal string m_sContactAddress = "";

		/// <summary>
		/// m_dMinDiskSpace holds the minimum disk sapce required by the job. 
		/// </summary>
		protected internal double m_dMinDiskSpace = 0;

		/// <summary>
		/// m_dMinMemorySize holds the minimum memory size required by the job. 
		/// </summary>
		protected internal double m_dMinMemorySize = 0;

		/// <summary>
		/// m_dMinCPUSpeed holds the minimum cpu speed required by the job. 
		/// </summary>
		protected internal double m_dMinCPUSpeed = 0;

		/// <summary>
		/// m_dJobMaxTime holds the maximum time allowed for the job. 
		/// </summary>
		protected internal double m_dJobMaxTime = OSParameter.JOB_MAX_TIME;

		/// <summary>
		/// m_jobScheduledStartTime holds the job's scheduled start time.
		/// </summary>
		protected internal DateTime m_jobScheduledStartTime = new DateTime(1970, 1, 1, 0, 0, 0);

		/// <summary>
		/// m_msJobDependencies holds a string array of jobIDs the the current job depends on. 
		/// </summary>
		protected internal string[] m_msJobDependencies = null;


		/// <summary>
		/// m_sCurrentState holds the current state of the service: which can be: 
		/// busy, busyButAccepting, idle, idleButNotAccepting, noResponse. 
		/// </summary>
		protected internal static string m_sCurrentState = "noResponse";

		/// <summary>
		/// m_dAvailableDiskSpace holds the available disk space. 
		/// </summary>
		protected internal static double m_dAvailableDiskSpace = Double.PositiveInfinity;

		/// <summary>
		/// m_dAvailableMemory holds the available memory. 
		/// </summary>
		protected internal static double m_dAvailableMemory = Double.PositiveInfinity;

		/// <summary>
		/// m_iCurrentJobCount holds the current number of active jobs. 
		/// </summary>
		protected internal static int m_iCurrentJobCount = 0;

		/// <summary>
		/// m_iTotalJobsSoFar holds the number of jobs so far received. 
		/// </summary>
		protected internal static int m_iTotalJobsSoFar = 0;
		
		/// <summary>
		/// m_lTimeLastJobEnded holds the time the last job ended (in millisecond since 1970 UTC).  
		/// </summary>
		protected static long m_lTimeLastJobEnded = -1;

		/// <summary>
		/// m_lLastJobTook holds the time the last job took in millisecond.  
		/// </summary>
		protected internal static long m_lLastJobTook = -1;

		/// <summary>
		/// m_lTimeServiceStarted holds the service start time (in millisecond since 1970 UTC).   
		/// </summary>
		protected internal static long m_lTimeServiceStarted = CommonUtil.currentTimeMillis();

		/// <summary>
		/// m_dServiceUtilization holds the service utilization (time solving jobs / total time since start)
		/// </summary>
		protected static double m_dServiceUtilization = -1.0;

		/// <summary>
		/// m_lTotalBusyTime holds the total busy time (solving jobs) since service start. 
		/// </summary>
		protected internal static long m_lTotalBusyTime = 0;

		/// <summary>
		/// m_sJobState holds the job state, which can be waiting, running, killed, finished or unknown.   
		/// </summary>
		protected string m_sJobState= "unknown";

		/// <summary>
		/// m_lJobStartTime holds the job start time (in millisecond since 1970 UTC).  
		/// </summary>
		protected internal long m_lJobStartTime = -1;

		/// <summary>
		/// m_lJobEndTime holds the job end time (in millisecond since 1970 UTC).   
		/// </summary>
		protected internal long m_lJobEndTime = -1;

		/// <summary>
		/// m_lJobDuration holds the time the job took in millisecond.
		/// </summary>
		protected internal long m_lJobDuration = -1;

		/// <summary>
		/// timer1 holds the timer thread for service task 1. 
		/// </summary>
		internal static System.Timers.Timer timer1  = null;

		/// <summary>
		/// timer2 holds the timer thread for service task 2. 
		/// </summary>
		internal static System.Timers.Timer timer2  = null;

		/// <summary>
		/// timer3 holds the timer thread for service task 3. 
		/// </summary>
		internal static System.Timers.Timer timer3  = null;

		/// <summary>
		/// osql holds the OSqL query input string.
		/// </summary>
		public string osql = null;

		/// <summary>
		/// osel holds the OSeL entity input string to be registered.
		/// </summary>
		public string osel = null;

		/// <summary>
		/// osxl holds the OSxL input string to be validated.
		/// </summary>
		public string osxl = null;

		/// <summary>
		/// osplInput hols the OSpL knock process string (input) 
		/// </summary>
		public string osplKnockInput = null;

		/// <summary>
		/// osolRegister holds the OSoL register option string (input). 
		/// </summary>
		public string osolRegister = null;

		/// <summary>
		/// osolKnock holds the OSoL knock option string (input). 
		/// </summary>
		public string osolKnock = null;

		/// <summary>
		/// osolFind holds the OSoL find option string (input). 
		/// </summary>
		public string osolFind = null;

		/// <summary>
		/// osolValidate holds the OSoL validate option string (input). 
		/// </summary>
		public string osolValidate = null;

		/// <summary>
		/// osplKnockOutput hols the OSpL knock process string (output) 
		/// </summary>
		public string osplKnockOutput = null;
	
		/// <summary>
		/// osplValiateOutput hols the OSpL validate process string (output) 
		/// </summary>
		public string osplValidateOutput = null;

		/// <summary>
		/// osplRegisterOutput hols the OSpL register process string (output) 
		/// </summary>
		public string osplRegisterOutput = null;

		/// <summary>
		/// osul holds the os uri/url string (output)
		/// </summary>
		public string osul = null;
	
		/// <summary>
		/// osRegistry holds the registry database information in the standard OSRegistry interface data structure.
		/// </summary>
		public static OSRegistry osRegistry = new OSRegistry();

		/// <summary>
		/// serviceHashTable holds a hash table of registered services. 
		/// The key is the serviceURI, and the value is the service of type ServiceEntry 
		/// </summary>
		public static Hashtable serviceHashTable = new Hashtable();

		/// <summary>
		/// m_osolReader holds the OSoL reader.
		/// </summary>
		protected internal OSoLReader m_osolReader = null;

		/// <summary>
		/// m_osplReader holds the OSpL reader.
		/// </summary>
		protected internal OSpLReader m_osplReader = null;

		/// <summary>
		/// m_osqlReader holds the OSqL reader.
		/// </summary>
		protected internal OSqLReader m_osqlReader = null;

		/// <summary>
		/// m_osulReader holds the OSuL reader.
		/// </summary>
		protected internal OSuLReader m_osulReader = null;

		/// <summary>
		/// m_osRegistryReader holds the OSRegistry reader.
		/// </summary>
		protected internal OSRegistryReader m_osRegistryReader = null;

		/// <summary>
		/// m_osolWriter holds the OSoL writer.
		/// </summary>
		protected internal OSoLWriter m_osolWriter = null;

		/// <summary>
		/// m_osplWriter holds the OSpL writer.
		/// </summary>
		protected internal OSpLWriter m_osplWriter = null;

		/// <summary>
		/// m_osqlWriter holds the OSqL writer.
		/// </summary>
		protected internal OSqLWriter m_osqlWriter = null;

		/// <summary>
		/// m_osulWriter holds the OSuL writer.
		/// </summary>
		protected internal OSuLWriter m_osulWriter = null;

		/// <summary>
		/// m_osRegistryWriter holds the OSRegistry writer.
		/// </summary>
		protected internal OSRegistryWriter m_osRegistryWriter = null;

		/// <summary>
		/// Default constructor.  
		/// </summary>
		public DefaultRegistry(){
		}//constructor

		/// <summary>
		/// Register a service at an OS Registry service whose input is given by a string following 
		/// the OSeL schema, along with an option that follows the OSoL schema,
		/// and returns the registration process output in a string that follows OSpL schema. 
		/// </summary>
		public void register(){
			m_osplWriter = new OSpLWriter();
			m_osplWriter.setServiceName((serviceName==null || serviceName.Length == 0)?OSParameter.SERVICE_NAME:serviceName);
			m_osplWriter.setServiceURI((serviceURI==null || serviceURI.Length == 0)?OSParameter.OS_REGISTRY_SITE:serviceURI);
			m_osplWriter.setProcessTime(DateTime.Now);

			//check osol
			bool bSystemAdmin = false;
			string sServiceURIInOSoL = "";
			m_osolReader = new OSoLReader(m_bValidate);
			if(osolRegister != null && osolRegister.Length > 0){
				try {
					//get system password
					bool bRead = m_osolReader.readString(osolRegister);
					if(!bRead){
						m_osplWriter.setResponseStatus("error");
						m_osplWriter.setResponseDescription("osol option string is invalid [registry]");
						osplRegisterOutput = m_osplWriter.writeToString();
						return;
					}
					m_sPassword = m_osolReader.getPassword();
					sServiceURIInOSoL = m_osolReader.getServiceURI();
					if(m_sPassword != null && m_sPassword.Length > 0 && OSParameter.checkSystemPassword(m_sPassword)){
						bSystemAdmin = true;
					}
				} 
				catch (Exception e) {
					m_osplWriter.setResponseStatus("error");
					m_osplWriter.setResponseDescription("osol option string is invalid: " + e.Message + " [registry]");
					m_osplWriter.setProcessMessage(e.ToString());
					osplRegisterOutput = m_osplWriter.writeToString();
					return;
				}
			}
			if(bSystemAdmin){
				try {
					//delete the service
					if(osel == null || osel.Length <= 0){
						int iService = osRegistry.service==null?0:osRegistry.service.Length;
						ServiceEntry serviceEntry = (ServiceEntry)serviceHashTable[sServiceURIInOSoL];
						if(serviceEntry != null){
							serviceHashTable.Remove(sServiceURIInOSoL);
							int iNewService =  ((iService-1)<=0)?0:(iService-1);
							ServiceEntry[] mNewServices = new ServiceEntry[iNewService];
							int j = 0;
							for(int i = 0; i < iService; i++){
								try{
									if(sServiceURIInOSoL.Equals(osRegistry.service[i].osel.getServiceURI())){
										continue;
									}
									mNewServices[j] = osRegistry.service[i];
									j++;
								}
								catch(Exception){
								}
							}
							osRegistry.service = mNewServices;
							m_osplWriter.setResponseStatus("success");
							m_osplWriter.setResponseDescription("The service is deleted [registry]");
							osplRegisterOutput = m_osplWriter.writeToString();
							return;
						}
						else{
							m_osplWriter.setResponseStatus("warning");
							m_osplWriter.setResponseDescription("Cannot find the service to delete in the registry given the serviceURI [registry]");
							osplRegisterOutput = m_osplWriter.writeToString();
							return;
						}
					}
					//add the service
					else{
						ServiceEntry newService = new ServiceEntry();
						OSeLReader oselReader = new OSeLReader(OSParameter.VALIDATE);
						if(!oselReader.readString(osel)){
							throw new Exception("Error reading OSeL file.");
						}
						newService.osel = oselReader.getOSEntity();
						newService.ospl.setServiceName(newService.osel.getServiceName());
						newService.ospl.setServiceURI(newService.osel.getServiceURI());
						newService.ospl.setProcessTime(DateTime.Now);
						newService.ospl.setCurrentState("noResponse");
	
						int iService = osRegistry.service==null?0:osRegistry.service.Length;
						ServiceEntry[] service = osRegistry.service;

						ServiceEntry serviceEntry = (ServiceEntry)serviceHashTable[newService.osel.getServiceURI()];
						//update
						if(serviceEntry != null){
							serviceHashTable.Remove(newService.osel.getServiceURI());
							serviceHashTable.Add(newService.osel.getServiceURI(), newService);
							for(int i = 0; i < iService; i++){
								try{
									if((newService.osel.getServiceURI()).Equals(osRegistry.service[i].osel.getServiceURI())){
										osRegistry.service[i] = newService;
										break;
									}
								}
								catch(Exception){								
								}
							}
							m_osplWriter.setResponseStatus("success");
							m_osplWriter.setResponseDescription("The new service OSeL is updated [registry]");
						}
						//add
						else{
							ServiceEntry[] mNewServices = new ServiceEntry[iService+1];
							for(int i = 0; i < iService; i++){
								try{
									mNewServices[i] = service[i];
								}
								catch(Exception){								
								}
							}
							mNewServices[iService] = newService; 
							serviceHashTable.Add(newService.osel.getServiceURI(), newService);
							osRegistry.service = mNewServices;		
							m_osplWriter.setResponseStatus("success");
							m_osplWriter.setResponseDescription("The new service is added [registry]");
						}
						osplRegisterOutput = m_osplWriter.writeToString();
		
						//update process w/ thread
						OSpLWriter osplWriter = new OSpLWriter();
						osplWriter.setRequestAction("getServiceStatistics");
						osplWriter.setServiceName(m_sRegistryServiceName);
						osplWriter.setServiceURI(OSParameter.OS_REGISTRY_SITE);
						osplWriter.setProcessTime(DateTime.Now);
						string sOSpLInput = osplWriter.writeToString();
				
						OSoLWriter osolWriter = new OSoLWriter();
						osolWriter.setPassword(OSParameter.getSystemPassword());
						string sOSoL = osolWriter.writeToString();
				
						KnockThread knockThread = new KnockThread();
						knockThread.m_sOSpLInput = sOSpLInput;
						knockThread.m_sOSoL = sOSoL;
				
						string sServiceType = newService.osel.getServiceType();
						if(sServiceType != null && sServiceType.Equals("scheduler")){
							knockThread.m_bSchedulerWithRegistry = OSParameter.SCHEDULER_WITH_REGISTRY;
						}
						else{
							knockThread.m_bSchedulerWithRegistry = false;
						}			
						knockThread.m_sAddress = newService.osel.getServiceURI();
						knockThread.m_bSetServiceStatistics = true;
						Thread thread = new Thread(new ThreadStart(knockThread.knock));
						thread.Start();	
						return;
					}
				} 
				catch (Exception e) {
					IOUtil.log("Error in registering using system admin rights: \n\r" + e.ToString(), OSParameter.REGISTRY_REGISTRATION_FILE);
					m_osplWriter.setResponseStatus("error");
					m_osplWriter.setResponseDescription("Error in registering using system admin rights [registry]");
					m_osplWriter.setProcessMessage(e.ToString());
					osplRegisterOutput = m_osplWriter.writeToString();			
					return;
				}
			}
			else{
				string sRegsitrationMessage = "\r\n" + osel + "\n\r\n\r" + osolRegister + "\r\n"; 
				IOUtil.log(sRegsitrationMessage, OSParameter.REGISTRY_REGISTRATION_FILE);
				string sSubject = "new OSRegistry registration";
				MailUtil.sendInThread(OSParameter.FROM_EMAIL, OSParameter.TO_EMAIL, null, null, sSubject, sRegsitrationMessage, null);
				m_osplWriter = new OSpLWriter();
				m_osplWriter.setResponseStatus("success");
				m_osplWriter.setResponseDescription("The registration has been received [registry]");
				string sMessage = "We will contact you according to the information that you provided.";
				m_osplWriter.setProcessMessage(sMessage);
				osplRegisterOutput = m_osplWriter.writeToString();
				return;
			}
		}//register

		/// <summary>
		/// Validates an OSxL string at an OS Registry service whose input is any OSxL string following 
		/// the corresponding OSxL schema, along with an option that follows the OSoL schema,
		/// and returns the validation process output in a string that follows OSpL schema. 
		/// </summary>
		public void validate(){
			m_osplWriter = new OSpLWriter();
			string sStatus = "success";
			m_osplWriter.setResponseStatus("success");
			string sResponseDescription = "The OSxL string is valid";
			string sMessage = "";
			m_osplWriter.setProcessTime(DateTime.Now);
			m_osplWriter.setServiceName((serviceName==null || serviceName.Length == 0)?OSParameter.SERVICE_NAME:serviceName);
			m_osplWriter.setServiceURI((serviceURI==null || serviceURI.Length == 0)?OSParameter.OS_REGISTRY_SITE:serviceURI);
			
			//check osol
			if(osolValidate != null && osolValidate.Length > 0){
				try {
					m_osolReader = new OSoLReader(m_bValidate);
					bool bRead = m_osolReader.readString(osolValidate);
					if(!bRead){
						m_osplWriter.setResponseStatus("error");
						m_osplWriter.setResponseDescription("osol option string is invalid [registry]");
						osplValidateOutput = m_osplWriter.writeToString();
						return;
					}
				} 
				catch (Exception e) {
					m_osplWriter.setResponseStatus("error");
					m_osplWriter.setResponseDescription("osol option string is invalid: " + e.Message + " [registry]");
					m_osplWriter.setProcessMessage(e.ToString());
					osplValidateOutput = m_osplWriter.writeToString();
					return;
				}
			}	

			try {
				XmlDocument document = new XmlDocument();
				XmlTextReader xmlTextReader = new XmlTextReader(osxl, XmlNodeType.Document, null);					
				XmlValidatingReader xmlValidatingReader = new XmlValidatingReader(xmlTextReader);
				xmlValidatingReader.ValidationType = ValidationType.Auto;
				document.Load(xmlValidatingReader);
			}
			catch(Exception e){
				sStatus = "error";
				sResponseDescription = e.Message;
				sMessage = e.ToString();
			}
			m_osplWriter.setResponseStatus(sStatus);
			m_osplWriter.setResponseDescription(sResponseDescription + " [registry]");
			m_osplWriter.setProcessMessage(sMessage);
			osplValidateOutput = m_osplWriter.writeToString();
			return;
		}//validate

		/// <summary>
		/// Find a service at an OS Registry service whose input query is given by a string following 
		/// the OSqL schema, along with an option that follows the OSoL schema,
		/// and returns the uri/url result in a string that follows OSuL schema. 
		/// </summary>
		public void find(){
			try{
				if(osql != null && osql.Length > 0){
					m_osqlReader = new OSqLReader(m_bValidate);
					bool bRead = m_osqlReader.readString(osql);
					if(!bRead){
						throw new Exception("OSqL query string is not valid");
					}
				}
			}
			catch(Exception e){
				IOUtil.log(e.ToString(), OSParameter.REGISTRY_LOG_FILE);
				m_osulWriter = new OSuLWriter();
				osul = m_osulWriter.writeToString();
				return;
			}
			try{
				if(osolFind != null && osolFind.Length > 0){
					m_osolReader = new OSoLReader(m_bValidate);
					bool  bRead = m_osolReader.readString(osolFind);
					if(!bRead){
						throw new Exception("OSoL option string is not valid");
					}
				}
			}
			catch(Exception e){
				IOUtil.log(e.ToString(), OSParameter.REGISTRY_LOG_FILE);
				m_osulWriter = new OSuLWriter();
				osul = m_osulWriter.writeToString();
				return;
			}
			m_osulWriter = new OSuLWriter();
			int iServiceNumber = (osRegistry.service == null)?0:osRegistry.service.Length;
			ServiceEntry[] service = osRegistry.service;

			StandardQuery standardQuery = null;
			string sXQuery = null;
			if(osql != null && osql.Length > 0){
				standardQuery = m_osqlReader.getStandardQuery();
				sXQuery = m_osqlReader.getXQuery();
			}
			try {
				if(standardQuery == null && (sXQuery == null || sXQuery.Length <= 0)){
					for(int i = 0; i < iServiceNumber; i++){
						try{
							string sServiceType = service[i].osel.getServiceType();
							if(sServiceType == null || sServiceType.Length <= 0) sServiceType = "solver";
							if(service[i] != null && service[i].ospl != null){
								string sCurrentState = service[i].ospl.getCurrentState();
								if(sCurrentState != null && (sCurrentState.Equals("idle") || sCurrentState.Equals("busyButAccepting")) && sServiceType.Equals("solver")){
									URI uri = new URI();
									uri.value = service[i].osel.getServiceURI();
									if(uri.value != null || uri.value.Length > 0){
										uri.licenseRequired = service[i].osel.getLicenseRequired();
										uri.userNameRequired = service[i].osel.getUserNameRequired();
										uri.passwordRequired = service[i].osel.getPasswordRequired();
										m_osulWriter.addURI(uri);						
									}
								}				
							}
						}
						catch(Exception){
						}
					}
					osul = m_osulWriter.writeToString();	
					return;
				}
				else if(sXQuery != null && sXQuery.Length > 0){//TODO XQuery
					osul = m_osulWriter.writeToString();		
					return;
				}
				else{//StandardQuery
					for(int i = 0; i < iServiceNumber; i++){
						try{
							if(service[i] == null) continue;
							//service type
							if(standardQuery.serviceType != null && standardQuery.serviceType.Length > 0){
								standardQuery.serviceType = "solver";
							}
							string sServiceType = service[i].osel.getServiceType();
							if(sServiceType == null || sServiceType.Length == 0) sServiceType = "solver";
							if(!sServiceType.Equals(standardQuery.serviceType)){
								continue;
							}
							//current state
							if(standardQuery.currentState != null && standardQuery.currentState.Length > 0){
								if(service[i].ospl == null) continue;
								string sCurrentState = service[i].ospl.getCurrentState();
								if(sCurrentState == null || sCurrentState.Length <= 0){
									continue;
								}
								if(standardQuery.currentState.Equals("accepting")){
									if(!sCurrentState.Equals("idle") && !sCurrentState.Equals("busyButAccepting")){
										continue;
									}
								}
								else if(standardQuery.currentState.Equals("notAccepting")){
									if(sCurrentState.Equals("idle") || sCurrentState.Equals("busyButAccepting")){
										continue;
									}
								}
								else{
									if(!sCurrentState.Equals(standardQuery.currentState)){
										continue;
									}
								}
							}
							if(standardQuery.optimization != null){
								//TODO
							}
							//add uri
							URI uri = new URI();
							uri.value = service[i].osel.getServiceURI();
							if(uri.value != null || uri.value.Length > 0){
								uri.licenseRequired = service[i].osel.getLicenseRequired();
								uri.userNameRequired = service[i].osel.getUserNameRequired();
								uri.passwordRequired = service[i].osel.getPasswordRequired();
								m_osulWriter.addURI(uri);
							}
						}
						catch(Exception){
						}
					}
					osul = m_osulWriter.writeToString();
					return;
				}
			}
			catch (Exception e) {
				IOUtil.log(e.ToString(), OSParameter.REGISTRY_LOG_FILE);
				osul = m_osulWriter.writeToString();
				return;
			}
		}//find

		/// <summary>
		/// Set (push) and/or get (pull) runtime dynamic process information to and/or from the service.  		
		/// </summary>
		public void knock(){
			m_osplWriter = new OSpLWriter();
			m_osplWriter.setServiceName((serviceName==null || serviceName.Length == 0)?OSParameter.SERVICE_NAME:serviceName);
			m_osplWriter.setServiceURI((serviceURI==null || serviceURI.Length == 0)?OSParameter.OS_REGISTRY_SITE:serviceURI);
			m_osplWriter.setProcessTime(DateTime.Now);
			m_osplWriter.setResponseDescription("Information provided by the registry may not be exactly the same as that from the services");


			//check osol
			m_osolReader = new OSoLReader(m_bValidate);
			string sServiceURIInOSoL = "";
			if(osolKnock != null && osolKnock.Length > 0){
				try {
					//get general options
					bool bRead = m_osolReader.readString(osolKnock);
					if(!bRead){
						m_osplWriter.setResponseStatus("error");
						m_osplWriter.setResponseDescription("osol option string is invalid [registry]");
						osplKnockOutput = m_osplWriter.writeToString();
						return;
					}
					m_sJobID = m_osolReader.getJobID();
					m_sInstanceName = m_osolReader.getInstanceName();
				
					//check license, userName, password
					m_sLicense = m_osolReader.getLicense();
					m_sUserName = m_osolReader.getUserName();
					m_sPassword = m_osolReader.getPassword();
					if(OSParameter.REQUIRE_LICENSE || OSParameter.REQUIRE_USER_NAME || OSParameter.REQUIRE_PASSWORD){
						bool bCheck = false;
						if(m_sPassword != null && m_sPassword.Length > 0 && OSParameter.checkSystemPassword(m_sPassword)){
							bCheck = true;
						}
						else{ 
							if(OSParameter.REQUIRE_LICENSE){
								bCheck = OSParameter.checkLicense(m_sUserName, m_sLicense);							
								if(!bCheck){
									m_osplWriter.setResponseStatus("error");
									m_osplWriter.setResponseDescription("Wrong licence [registry]");
								}
							}
							if(bCheck && (OSParameter.REQUIRE_USER_NAME || OSParameter.REQUIRE_PASSWORD)){
								bCheck = OSParameter.checkUserNameAndPassword(m_sUserName, m_sPassword);
								if(!bCheck){
									m_osplWriter.setResponseStatus("error");
									m_osplWriter.setResponseDescription("Wrong user name and/or password [registry]");
								}
							}
						}
						if(!bCheck){
							osplKnockOutput = m_osplWriter.writeToString();
							return;
						}
					}

					//get contact
					m_sContactTransportType = m_osolReader.getContactTransportType();
					if(m_sContactTransportType == null || m_sContactTransportType.Length > 0){
						m_sContactTransportType = "osp";
					}
					m_sContactAddress = m_osolReader.getContactAddress();			

					sServiceURIInOSoL = m_osolReader.getServiceURI();
				} 
				catch (Exception e) {
					IOUtil.log(e.ToString(), OSParameter.REGISTRY_LOG_FILE);
					m_osplWriter.setResponseStatus("error");
					m_osplWriter.setResponseDescription(e.Message + " [registry]");
					m_osplWriter.setProcessMessage(e.ToString());
					osplKnockOutput = m_osplWriter.writeToString();
					return;
				}
			}
			else{
				//if no options, check license, userName, password requirements
				bool bRequireLUP = false;
				if(m_sPassword != null && m_sPassword.Length > 0 && OSParameter.checkSystemPassword(m_sPassword)){
					bRequireLUP = false;
				}
				else{
					if(OSParameter.REQUIRE_LICENSE){
						bRequireLUP = true;
						m_osplWriter.setResponseStatus("error");
						m_osplWriter.setResponseDescription("The service requires license. [registry]");
					}
					if(!bRequireLUP && OSParameter.REQUIRE_USER_NAME){
						bRequireLUP = true;
						m_osplWriter.setResponseStatus("error");
						m_osplWriter.setResponseDescription("The service requires user name. [registry]");
					}
					if(!bRequireLUP && OSParameter.REQUIRE_PASSWORD){
						bRequireLUP = true;
						m_osplWriter.setResponseStatus("error");
						m_osplWriter.setResponseDescription("The service requires password. [registry]");
					}
				}
				if(bRequireLUP){
					osplKnockOutput = m_osplWriter.writeToString();
					return;
				}
			}
		
			//check ospl
			m_osplReader = new OSpLReader(m_bValidate);
			string sAction = "";
			string sServiceName = "";
			string sServiceURI = "";
			DateTime processTime = new DateTime(1970, 1, 1, 0, 0, 0);
			string sProcessMessage = "";
			ProcessStatistics processStatistics = null;
			JobStatistics[] mJobStatistics = null;
			OptimizationProcess optimizationProcess = null;
				
			if(osplKnockInput == null || osplKnockInput.Length == 0){
				m_osplWriter.setResponseStatus("error");
				m_osplWriter.setResponseDescription("ospl string is empty [registry]");
				osplKnockOutput = m_osplWriter.writeToString();
				return;
			}
			else{
				try {
					bool bRead = m_osplReader.readString(osplKnockInput);
					if(!bRead){
						m_osplWriter.setResponseStatus("error");
						m_osplWriter.setResponseDescription("ospl input string is invalid [registry]");
						osplKnockOutput = m_osplWriter.writeToString();
						return;
					}
					sAction = m_osplReader.getRequestAction();
					if((sAction == null || sAction.Length <= 0)){
						m_osplWriter.setResponseStatus("error");
						m_osplWriter.setResponseDescription("no request action specified in ospl [registry]");
						osplKnockOutput = m_osplWriter.writeToString();
						return;
					}
					else if(!sAction.Equals("ping") &&
						!sAction.Equals("notifyJobCompletion") &&
						!sAction.Equals("requestJob") &&
						!sAction.Equals("getServiceStatistics") &&
						!sAction.Equals("setServiceStatistics") &&
						!sAction.Equals("getJobStatistics") &&
						!sAction.Equals("setJobStatistics") &&
						!sAction.Equals("getOptimization") &&
						!sAction.Equals("setOptimization") &&
						!sAction.Equals("getAll") &&
						!sAction.Equals("setAll")){
						m_osplWriter.setResponseStatus("error");
						m_osplWriter.setResponseDescription("request action specified in ospl has to one of the following values: " +
							"ping, notifyJobCompletion, requestJob, " +
							"getServiceStatistics, setServiceStatistics, " +
							"getJobStatistics, setJobStatistics, getOptimization, setOptimization, getAll, setAll [registry]");
						osplKnockOutput = m_osplWriter.writeToString();
						return;
					}
					sServiceName = m_osplReader.getServiceName();
					sServiceURI = m_osplReader.getServiceURI();
					processTime = m_osplReader.getProcessTime();
					sProcessMessage = m_osplReader.getProcessMessage();
					processStatistics = m_osplReader.getProcessStatistics();
					mJobStatistics = (processStatistics==null || processStatistics.jobs==null)?null:processStatistics.jobs.job;
					optimizationProcess = m_osplReader.getOptimizationProcess();
				}
				catch (Exception e) {
					IOUtil.log(e.ToString(), OSParameter.REGISTRY_LOG_FILE);
					m_osplWriter.setResponseStatus("error");
					m_osplWriter.setResponseDescription(e.Message + "  [registry]");
					m_osplWriter.setProcessMessage(e.ToString());
					osplKnockOutput = m_osplWriter.writeToString();
					return;
				}
			}
			bool bKeepJobStatistics = true;
			bool bKeepOptimization = false;
			if(sAction.Equals("ping")){
				m_osplWriter.setResponseStatus("success");
				m_osplWriter.setResponseDescription("The registry service is alive [registry]");
				osplKnockOutput = m_osplWriter.writeToString();
				return;
			}//ping
			if(sAction.Equals("notifyJobCompletion")){
				if(sServiceURIInOSoL != null && sServiceURIInOSoL.Length <= 0){
					sServiceURI = sServiceURIInOSoL;
				}
				if(sServiceURI == null || sServiceURI.Length <= 0){
					m_osplWriter.setResponseStatus("error");
					m_osplWriter.setResponseDescription("No service URI is provided. [registry]");
					osplKnockOutput = m_osplWriter.writeToString();				
					return;
				}
				else{
					try{
						ServiceEntry service = (ServiceEntry)serviceHashTable[sServiceURI];
						if(service == null){
							m_osplWriter.setResponseStatus("warning");
							m_osplWriter.setResponseDescription("Cannot find the service in the registry given the serviceURI [registry]");
							return;
						}
						OSpLWriter osplWriter1 = new OSpLWriter();
						osplWriter1.setRequestAction("getServiceStatistics");
						osplWriter1.setServiceName(serviceName);
						osplWriter1.setServiceURI(serviceURI);
						osplWriter1.setProcessTime(DateTime.Now);
						string sOSpLInput = osplWriter1.writeToString();
					
						OSoLWriter osolWriter1 = new OSoLWriter();
						osolWriter1.setPassword(m_sSystemPassword);
						string sOSoLInput = osolWriter1.writeToString();
					
						KnockThread knockThread = new KnockThread();
						knockThread.m_sOSpLInput = sOSpLInput;
						knockThread.m_sOSoL = sOSoLInput;
					
						string sServiceType = service.osel.getServiceType();
						if(sServiceType != null && sServiceType.Equals("scheduler")){
							knockThread.m_bSchedulerWithRegistry = OSParameter.SCHEDULER_WITH_REGISTRY;
						}
						else{
							knockThread.m_bSchedulerWithRegistry = false;
						}			
						knockThread.m_sAddress = sServiceURI;
						knockThread.m_bSetServiceStatistics = true;
						Thread thread = new Thread(new ThreadStart(knockThread.knock));
						thread.Start();	
					}
					catch (Exception e){
						IOUtil.log(e.ToString(), OSParameter.REGISTRY_LOG_FILE);
					}
					m_osplWriter.setResponseStatus("success");
					m_osplWriter.setResponseDescription("The service has got the notification. [registry]");
					return;

				}
			}//notifyJobCompletion
			if(sAction.Equals("requestJob")){
				m_osplWriter.setResponseStatus("warning");
				m_osplWriter.setResponseDescription("The registry service does not take job request. [registry]");
				osplKnockOutput = m_osplWriter.writeToString();
				return;		
			}//requestJob
			if(sAction.Equals("getServiceStatistics")|| sAction.Equals("getAll")){
				if(sServiceURIInOSoL == null || sServiceURIInOSoL.Length <= 0){
					sServiceURIInOSoL = sServiceURI;
				}
				if(sServiceURIInOSoL == null || sServiceURIInOSoL.Length <= 0){
					m_osplWriter.setResponseStatus("error");
					m_osplWriter.setResponseDescription("No service URI is provided. [registry]");
					osplKnockOutput = m_osplWriter.writeToString();				
					return;
				}
				else{
					m_osplWriter.setServiceURI(sServiceURIInOSoL);
					try {
						ServiceEntry serviceEntry = (ServiceEntry)serviceHashTable[sServiceURIInOSoL];
						if(serviceEntry != null){
							m_osplWriter.setProcessStatistics(serviceEntry.ospl.getProcessStatistics());
							if(!sAction.Equals("getAll")){
								m_osplWriter.setResponseStatus("success");
								m_osplWriter.setResponseDescription("Got the service statistics. It may not exactly the same as that from the service");
								osplKnockOutput = m_osplWriter.writeToString();				
								return;					
							}
						}
						else{
							m_osplWriter.setResponseStatus("warning");
							m_osplWriter.setResponseDescription("cannot find the service URI provided. [registry]");
							osplKnockOutput = m_osplWriter.writeToString();				
							return;					
						}
					} 
					catch (Exception e) {
						IOUtil.log(e.ToString(), OSParameter.REGISTRY_LOG_FILE);
						m_osplWriter.setResponseStatus("warning");
						m_osplWriter.setResponseDescription("Unable to provide the information: " + e.Message + " [registry]");
						m_osplWriter.setProcessMessage(e.ToString());
						osplKnockOutput = m_osplWriter.writeToString();				
						return;					
					}			
				}
			}//getServiceStatistics
			if(sAction.Equals("setServiceStatistics") || sAction.Equals("setAll")){
				if(sServiceURIInOSoL == null || sServiceURIInOSoL.Length <= 0){
					sServiceURIInOSoL = sServiceURI;
				}
				if(sServiceURIInOSoL == null || sServiceURIInOSoL.Length <= 0){
					m_osplWriter.setResponseStatus("error");
					m_osplWriter.setResponseDescription("No service URI is provided. [registry]");
					osplKnockOutput = m_osplWriter.writeToString();				
					return;
				}
				else{
					m_osplWriter.setServiceURI(sServiceURIInOSoL);
					try {
						ServiceEntry serviceEntry = (ServiceEntry)serviceHashTable[sServiceURIInOSoL];
						if(serviceEntry != null){
							if(!bKeepJobStatistics){
								processStatistics.jobs = null;
							}
							string sNewState = processStatistics.currentState;
							if(sNewState != null && !sServiceURIInOSoL.Equals(OSParameter.OS_SCHEDULER_SITE) &&
								(sNewState.Equals("busy") || sNewState.Equals("idleButNotAccepting") || sNewState.Equals("noResponse"))){
								if(OSParameter.SCHEDULER_WITH_REGISTRY){
									OSServiceUtil.acceptingSolverURIs.Remove(sServiceURIInOSoL);
								}
							}
							serviceEntry.ospl.setProcessStatistics(processStatistics);
							if(!sAction.Equals("setAll")){
								m_osplWriter.setResponseStatus("success");
								m_osplWriter.setResponseDescription("Set the service statistics. [registry]");
								osplKnockOutput = m_osplWriter.writeToString();				
								return;					
							}
						}
						else{
							m_osplWriter.setResponseStatus("warning");
							m_osplWriter.setResponseDescription("cannot find the service URI provided. [registry]");
							osplKnockOutput = m_osplWriter.writeToString();				
							return;					
						}
					} 
					catch (Exception e) {
						IOUtil.log(e.ToString(), OSParameter.REGISTRY_LOG_FILE);
						m_osplWriter.setResponseStatus("warning");
						m_osplWriter.setResponseDescription("Unable to update information: " + e.Message + " [registry]");
						m_osplWriter.setProcessMessage(e.ToString());
						osplKnockOutput = m_osplWriter.writeToString();				
						return;					
					}			
				}
			}//setServiceStatistics
			if(sAction.Equals("getJobStatistics")){
				if(!bKeepJobStatistics){
					m_osplWriter.setResponseStatus("warning");
					m_osplWriter.setResponseDescription("The registry service does not keep job statistics. [registry]");
					osplKnockOutput = m_osplWriter.writeToString();
					return;		
				}
				if(sServiceURIInOSoL == null || sServiceURIInOSoL.Length <= 0){
					sServiceURIInOSoL = sServiceURI;
				}
				if(sServiceURIInOSoL == null || sServiceURIInOSoL.Length <= 0){
					m_osplWriter.setResponseStatus("error");
					m_osplWriter.setResponseDescription("No service URI is provided. [registry]");
					osplKnockOutput = m_osplWriter.writeToString();				
					return;
				}
				else{
					m_osplWriter.setServiceURI(sServiceURIInOSoL);
					try {
						ServiceEntry serviceEntry = (ServiceEntry)serviceHashTable[sServiceURIInOSoL];
						if(serviceEntry != null){
							m_osplWriter.setJobStatistics(serviceEntry.ospl.getJobStatistics());
							m_osplWriter.setResponseStatus("success");
							m_osplWriter.setResponseDescription("Got the job statistics. [registry]");
							osplKnockOutput = m_osplWriter.writeToString();				
							return;					
						}
						else{
							m_osplWriter.setResponseStatus("warning");
							m_osplWriter.setResponseDescription("cannot find the service URI provided. [registry]");
							osplKnockOutput = m_osplWriter.writeToString();				
							return;					
						}
					} 
					catch (Exception e) {
						IOUtil.log(e.ToString(), OSParameter.REGISTRY_LOG_FILE);
						m_osplWriter.setResponseStatus("warning");
						m_osplWriter.setResponseDescription("Unable to provide the information: " + e.Message + "  [registry]");
						m_osplWriter.setProcessMessage(e.ToString());
						osplKnockOutput = m_osplWriter.writeToString();				
						return;					
					}			
				}
			}//getJobStatistics
			if(sAction.Equals("setJobStatistics")){
				if(!bKeepJobStatistics){
					m_osplWriter.setResponseStatus("warning");
					m_osplWriter.setResponseDescription("The registry service does not keep job statistics. [registry]");
					osplKnockOutput = m_osplWriter.writeToString();
					return;		
				}
				if(sServiceURIInOSoL == null || sServiceURIInOSoL.Length <= 0){
					sServiceURIInOSoL = sServiceURI;
				}
				if(sServiceURIInOSoL == null || sServiceURIInOSoL.Length <= 0){
					m_osplWriter.setResponseStatus("error");
					m_osplWriter.setResponseDescription("No service URI is provided. [registry]");
					osplKnockOutput = m_osplWriter.writeToString();				
					return;
				}
				else{
					m_osplWriter.setServiceURI(sServiceURIInOSoL);
					try {
						ServiceEntry serviceEntry = (ServiceEntry)serviceHashTable[sServiceURIInOSoL];
						if(serviceEntry != null){
							serviceEntry.ospl.setJobStatistics(mJobStatistics);
							m_osplWriter.setResponseStatus("success");
							m_osplWriter.setResponseDescription("Set the job statistics. [registry]");
							osplKnockOutput = m_osplWriter.writeToString();				
							return;	
						}
						else{
							m_osplWriter.setResponseStatus("warning");
							m_osplWriter.setResponseDescription("cannot find the service URI provided. [registry]");
							osplKnockOutput = m_osplWriter.writeToString();				
							return;					
						}
					} 
					catch (Exception e) {
						IOUtil.log(e.ToString(), OSParameter.REGISTRY_LOG_FILE);
						m_osplWriter.setResponseStatus("warning");
						m_osplWriter.setResponseDescription("Unable to update information: " + e.Message + " [registry]");
						m_osplWriter.setProcessMessage(e.ToString());
						osplKnockOutput = m_osplWriter.writeToString();				
						return;					
					}			
				}	
			}//setJobStatistics
			if(sAction.Equals("getOptimization") || (sAction.Equals("getAll") && bKeepOptimization)){
				if(!bKeepOptimization){
					m_osplWriter.setResponseStatus("warning");
					m_osplWriter.setResponseDescription("The registry service does not keep optimization information. [registry]");
					osplKnockOutput = m_osplWriter.writeToString();
					return;		
				}
				if(sServiceURIInOSoL == null || sServiceURIInOSoL.Length <= 0){
					sServiceURIInOSoL = sServiceURI;
				}
				if(sServiceURIInOSoL == null || sServiceURIInOSoL.Length <= 0){
					m_osplWriter.setResponseStatus("error");
					m_osplWriter.setResponseDescription("No service URI is provided. [registry]");
					osplKnockOutput = m_osplWriter.writeToString();				
					return;
				}
				else{
					try {
						ServiceEntry serviceEntry = (ServiceEntry)serviceHashTable[sServiceURIInOSoL];
						if(serviceEntry != null){
							m_osplWriter.setOptimizationProcess(serviceEntry	.ospl.getOptimizationProcess());
							if(!sAction.Equals("getAll")){
								m_osplWriter.setResponseStatus("success");
								m_osplWriter.setResponseDescription("Got the optimization information. [registry]");
								osplKnockOutput = m_osplWriter.writeToString();				
								return;					
							}
						}
						else{
							m_osplWriter.setResponseStatus("warning");
							m_osplWriter.setResponseDescription("cannot find the service URI provided. [registry]");
							osplKnockOutput = m_osplWriter.writeToString();				
							return;					
						}
					} 
					catch (Exception e) {
						IOUtil.log(e.ToString(), OSParameter.REGISTRY_LOG_FILE);
						m_osplWriter.setResponseStatus("warning");
						m_osplWriter.setResponseDescription("Unable to provide the information: " + e.Message);
						m_osplWriter.setProcessMessage(e.ToString());
						osplKnockOutput = m_osplWriter.writeToString();				
						return;					
					}			
				}
			}//getOptimization
			if(sAction.Equals("setOptimization") || (sAction.Equals("setAll") && bKeepOptimization)){
				if(!bKeepOptimization){
					m_osplWriter.setResponseStatus("warning");
					m_osplWriter.setResponseDescription("The registry service does not keep optimization information. [registry]");
					osplKnockOutput = m_osplWriter.writeToString();
					return;		
				}
				if(sServiceURIInOSoL == null || sServiceURIInOSoL.Length <= 0){
					sServiceURIInOSoL = sServiceURI;
				}
				if(sServiceURIInOSoL == null || sServiceURIInOSoL.Length <= 0){
					m_osplWriter.setResponseStatus("error");
					m_osplWriter.setResponseDescription("No service URI is provided. [registry]");
					osplKnockOutput = m_osplWriter.writeToString();				
					return;
				}
				else{
					try {
						ServiceEntry serviceEntry = (ServiceEntry)serviceHashTable[sServiceURIInOSoL];
						if(serviceEntry != null){
							serviceEntry.ospl.setOptimizationProcess(optimizationProcess);
							if(!sAction.Equals("setAll")){
								m_osplWriter.setResponseStatus("success");
								m_osplWriter.setResponseDescription("Set the optimization information. [registry]");
								osplKnockOutput = m_osplWriter.writeToString();				
								return;					
							}
						}
						else{
							m_osplWriter.setResponseStatus("warning");
							m_osplWriter.setResponseDescription("cannot find the service URI provided. [registry]");
							osplKnockOutput = m_osplWriter.writeToString();				
							return;					
						}
					} 
					catch (Exception e) {
						IOUtil.log(e.ToString(), OSParameter.REGISTRY_LOG_FILE);
						m_osplWriter.setResponseStatus("warning");
						m_osplWriter.setResponseDescription("Unable to update information: " + e.Message + " [registry]");
						m_osplWriter.setProcessMessage(e.ToString());
						osplKnockOutput = m_osplWriter.writeToString();				
						return;					
					}			
				}	
			}//setOptimization
			if(sAction.Equals("getAll")){
				m_osplWriter.setResponseStatus("success");					
				m_osplWriter.setResponseDescription("All the information has been obtained.");
				osplKnockOutput = m_osplWriter.writeToString();
				return;	
			}//getAll
			if(sAction.Equals("setAll")){
				m_osplWriter.setResponseStatus("success");					
				m_osplWriter.setResponseDescription("All the information has been set.");
				osplKnockOutput = m_osplWriter.writeToString();
				return;	
			}//setAll

			m_osplWriter.setResponseStatus("error");
			m_osplWriter.setResponseDescription("Request action is not recognized.");
			osplKnockOutput = m_osplWriter.writeToString();
			return;				
		}//knock

		/// <summary>
		/// <c>KnockThread</c> is an internal thread controlled by <c>DefaultRegistry</c>.
		/// </summary>
		protected internal class KnockThread{
			/// <summary>
			/// m_sOSpLInput holds the OSpL process input for the knock. 
			/// </summary>
			protected internal string m_sOSpLInput = null;

			/// <summary>
			/// m_sOSoL holds the OSoL process input for the knock.
			/// </summary>
			protected internal string m_sOSoL = null;

			/// <summary>
			/// m_sAddress holds the address of the remote solver or scheduler. 
			/// </summary>
			protected internal string m_sAddress = null;

			/// <summary>
			/// m_bSchedulerWithRegistry holds whether the scheduler is with the registry. 
			/// </summary>
			protected internal bool m_bSchedulerWithRegistry = false;

			/// <summary>
			/// m_sOSpLOutput holds the OSpL process output for the knock.
			/// </summary>
			protected internal string m_sOSpLOutput = null;

			/// <summary>
			/// m_bSetServiceStatistics holds whether to set the service statistics after knocking. 
			/// </summary>
			protected internal bool m_bSetServiceStatistics = false;

			/// <summary>
			/// A knock method is implemented here. 
			/// </summary>
			protected internal virtual void knock(){
				ServiceEntry serviceEntry = (ServiceEntry)serviceHashTable[m_sAddress];
				if(m_bSchedulerWithRegistry){
					try{
						OSServiceUtil osServiceUtil = new OSServiceUtil();
						osServiceUtil.serviceName = OSParameter.SERVICE_NAME;
						osServiceUtil.serviceURI = OSParameter.OS_SCHEDULER_SITE;
						osServiceUtil.serviceType = "scheduler";
						osServiceUtil.solver = null;
						m_sOSpLOutput = osServiceUtil.knock(m_sOSpLInput, m_sOSoL);					
					}
					catch (Exception e) {
						IOUtil.log("Error invoking scheduler \n\r" + e.ToString(), OSParameter.REGISTRY_LOG_FILE);
						return;
					}
				}
				else{
					try {
						OSSolverAgent solverAgent = new OSSolverAgent(m_sAddress);
						m_sOSpLOutput = solverAgent.knock(m_sOSpLInput, m_sOSoL);
						if(m_sOSpLOutput == null || m_sOSpLOutput.Length <= 0){
							throw new Exception("Unable to contact at the provided service URI: " + m_sAddress);
						}
					} 
					catch (Exception e) {
						IOUtil.log("Error contacting " + m_sAddress + e.ToString(), OSParameter.REGISTRY_LOG_FILE);
						if(serviceEntry != null){
							serviceEntry.ospl.setCurrentState("noResponse");							
						}
						return;
					}
				}
				if(m_bSetServiceStatistics){
					if(serviceEntry != null){
						try {
							OSpLReader osplReader = new OSpLReader();
							osplReader.readString(m_sOSpLOutput);
							OSProcess osProcess = osplReader.getOSProcess();
							serviceEntry.ospl.processHeader = osProcess.processHeader;
							serviceEntry.ospl.setProcessStatistics(osplReader.getProcessStatistics());
						} 
						catch (Exception e){
							IOUtil.log("Can't set service statistics: \n\r" + e.ToString(), OSParameter.REGISTRY_LOG_FILE);			
							return;
						}        									
						try {
							OSRegistryWriter osRegistryWriter = new OSRegistryWriter();
							osRegistryWriter.setOSRegistry(DefaultRegistry.osRegistry);
							osRegistryWriter.writeToFile(OSParameter.REGISTRY_FILE+"_backup");
							return;
						} 
						catch (Exception e) {
							IOUtil.log(e.ToString(), OSParameter.REGISTRY_LOG_FILE);
							return;
						}
					}
					else{
						IOUtil.log("Cannot find service " + m_sAddress, OSParameter.REGISTRY_LOG_FILE);
						return;
					}
				}
			}//knock
	
		}//KnockThread

		/// <summary>
		/// an internal timer task called by <c>OSServiceUtil</c>.
		/// The task is relatively short. 
		/// </summary>
		/// <param name="source">holds the event source.</param>
		/// <param name="e">holds the event arguments.</param>
		internal static void serviceTask1(object source, ElapsedEventArgs e){//TODO delete IOUtil.log & make timer long
			int iService = osRegistry.service==null?0:osRegistry.service.Length;
			string sSystemPassword = OSParameter.getSystemPassword();
			//backup registry
			try {
				OSRegistryWriter osRegistryWriter = new OSRegistryWriter();
				osRegistryWriter.setOSRegistry(DefaultRegistry.osRegistry);
				osRegistryWriter.writeToFile(OSParameter.REGISTRY_FILE+"_backup");
			} 
			catch (Exception) {
				IOUtil.log(e.ToString(), OSParameter.REGISTRY_LOG_FILE);
			}

			//pull info and update services
			for(int i = 0; i < iService; i++){
				try{
					OSpLWriter osplWriter = new OSpLWriter();
					osplWriter.setRequestAction("getServiceStatistics");
					osplWriter.setServiceName(m_sRegistryServiceName);
					osplWriter.setServiceURI(OSParameter.OS_REGISTRY_SITE);
					osplWriter.setProcessTime(DateTime.Now);
					String sOSpLInput = osplWriter.writeToString();
				
					OSoLWriter osolWriter = new OSoLWriter();
					osolWriter.setPassword(sSystemPassword);
					String sOSoL = osolWriter.writeToString();

					KnockThread knockThread = new KnockThread();
					knockThread.m_sOSpLInput = sOSpLInput;
					knockThread.m_sOSoL = sOSoL;

					string sServiceType = osRegistry.service[i].osel.getServiceType();
					if(sServiceType != null && sServiceType.Equals("scheduler")){
						knockThread.m_bSchedulerWithRegistry = OSParameter.SCHEDULER_WITH_REGISTRY;
					}
					else{
						knockThread.m_bSchedulerWithRegistry = false;
					}			
					knockThread.m_sAddress = osRegistry.service[i].osel.getServiceURI();
					knockThread.m_bSetServiceStatistics = true;
					Thread thread = new Thread(new ThreadStart(knockThread.knock));
					thread.Start();
				}
				catch(Exception){
				}
			}
		}//serviceTask1

		/// <summary>
		/// an internal timer task called by <c>OSServiceUtil</c>.
		/// The task is carried out periodically in intervals that are neither too short nor too long. 
		/// </summary>
		/// <param name="source">holds the event source.</param>
		/// <param name="e">holds the event arguments.</param>
		internal static void serviceTask2(object source, ElapsedEventArgs e){
			//clean up disks
			if(!OSParameter.SCHEDULER_WITH_REGISTRY){
				IOUtil.cleanUpDisk();
			}
			//prepare report
			string sSummaryReport = "";
			StringBuilder sbDetailedReport = new StringBuilder();
			int iServiceNumber = (osRegistry.service == null)?0:osRegistry.service.Length;
			int iIdle = 0;
			int iIdleButNotAccepting = 0;
			int iBusy = 0;
			int iBusyButAccepting = 0;
			int iUnknown = 0;
			string sSchedulerState = "";
			string sTime = XMLUtil.createXSDateTime(DateTime.Now);
			sSummaryReport += (sTime + ",");
    		
			string sLine = "*************************************\r\n";
			sbDetailedReport.Append(sLine);
			sbDetailedReport.Append(sTime+"\r\n");
			ServiceEntry[] service = osRegistry.service;
			for(int i = 0; i < iServiceNumber; i++){
				try{
					string sServiceURI = service[i].osel.getServiceURI();
					string sServiceName = service[i].osel.getServiceName();
					string sServiceType = service[i].osel.getServiceType();
					if(sServiceType == null || sServiceType.Length == 0) sServiceType = "solver";
					sbDetailedReport.Append(sServiceURI+", " + sServiceName+", " + sServiceType+"\r\n");
					if(service[i] != null && service[i].ospl != null){
						string sCurrentState = service[i].ospl.getCurrentState();
						sbDetailedReport.Append(sCurrentState+",");
						sbDetailedReport.Append(service[i].ospl.getAvailableDiskSpace()+",");
						sbDetailedReport.Append(service[i].ospl.getAvailableMemory()+",");
						sbDetailedReport.Append(service[i].ospl.getCurrentJobCount()+",");
						sbDetailedReport.Append(service[i].ospl.getTotalJobsSoFar()+",");
						sbDetailedReport.Append(XMLUtil.createXSDateTime(service[i].ospl.getTimeLastJobEnded()));
						sbDetailedReport.Append(service[i].ospl.getTimeLastJobTook()+",");
						sbDetailedReport.Append(XMLUtil.createXSDateTime(service[i].ospl.getTimeServiceStarted()));
						sbDetailedReport.Append(service[i].ospl.getServiceUtilization()+"\r\n");
						if(sServiceType.Equals("solver")){
							if(sCurrentState == null){
								iUnknown++;
							}
							else if(sCurrentState.Equals("idle")){
								iIdle++;
							}
							else if(sCurrentState.Equals("idleButNotAccepting")){
								iIdleButNotAccepting++;
							}
							else if(sCurrentState.Equals("busy")){
								iBusy++;
							}
							else if(sCurrentState.Equals("busyButAccepting")){
								iBusyButAccepting++;
							}
							else{
								iUnknown++;
							}
						}
						else{
							sSchedulerState = sCurrentState;
						}
					}
					else{
						iUnknown++;
					}
				}
				catch(Exception){
				}
			}//for
			sSummaryReport += (iServiceNumber+","+sSchedulerState+","+iIdle+","+iIdleButNotAccepting+","+iBusy+","+iBusyButAccepting+"\r\n");
			IOUtil.appendStringToFile(sSummaryReport, OSParameter.REGISTRY_SUMMARY_REPORT);
			sbDetailedReport.Append(sLine);
			IOUtil.appendStringToFile(sbDetailedReport.ToString(), OSParameter.REGISTRY_DETAILED_REPORT); 
			//end preparing report

		}//serviceTask2

		/// <summary>
		/// an internal timer task called by <c>OSServiceUtil</c>.
		/// The task is carried out in long intervals periodically.
		/// </summary>
		/// <param name="source">holds the event source.</param>
		/// <param name="e">holds the event arguments.</param>
		internal static void serviceTask3(object source, ElapsedEventArgs e){
			int iService = osRegistry.service==null?0:osRegistry.service.Length;
			String sSystemPassword = OSParameter.getSystemPassword();
			//pull info and update services
			for(int i = 0; i < iService; i++){
				try{
					OSpLWriter osplWriter = new OSpLWriter();
					osplWriter.setRequestAction("getServiceStatistics");
					osplWriter.setServiceName(m_sRegistryServiceName);
					osplWriter.setServiceURI(OSParameter.OS_REGISTRY_SITE);
					osplWriter.setProcessTime(DateTime.Now);
					String sOSpLInput = osplWriter.writeToString();
				
					OSoLWriter osolWriter = new OSoLWriter();
					osolWriter.setPassword(sSystemPassword);
					String sOSoL = osolWriter.writeToString();				
				
					OSSolverAgent solverAgent = new OSSolverAgent();
					solverAgent.solverAddress = osRegistry.service[i].osel.getServiceURI();
					try {
						OSpLReader osplReader = new OSpLReader();
						string sOSpLOutput = solverAgent.knock(sOSpLInput, sOSoL);
						if(sOSpLOutput == null || sOSpLOutput.Length <= 0){
							throw new Exception("Unable to contact at the provided service URI: " + solverAgent.solverAddress);
						}
						bool bRead = osplReader.readString(sOSpLOutput);
						if(!bRead){
							throw new Exception("OSpL output string is not valid");
						}
						if(osplReader.getCurrentState().Equals("idleButNotAccepting")){
							string sError = "solver " + solverAgent.solverAddress + "is not accepting jobs";
							IOUtil.log(sError, OSParameter.REGISTRY_LOG_FILE);
							MailUtil.sendInThread(OSParameter.FROM_EMAIL, null, null, null, OSParameter.MAIL_SUBJECT, sError, null );					
						}
					} 
					catch (Exception){
						string sError = "unable to get service statistics from " + solverAgent.solverAddress;
						IOUtil.log(sError, OSParameter.REGISTRY_LOG_FILE);
						MailUtil.sendInThread(OSParameter.FROM_EMAIL, null, null, null, OSParameter.MAIL_SUBJECT, sError, null );					
					}    
				}
				catch(Exception){
				}
				MailUtil.sendInThread(OSParameter.FROM_EMAIL, null, null, null, "REGISTRY_SUMMARY_REPORT", "", OSParameter.REGISTRY_SUMMARY_REPORT );					
				MailUtil.sendInThread(OSParameter.FROM_EMAIL, null, null, null, "REGISTRY_DETAILED_REPORT", "", OSParameter.REGISTRY_DETAILED_REPORT );					
			}        

		}//serviceTask3

		/// <summary>
		/// static constructor
		/// </summary>
		static DefaultRegistry(){
			if(!OSParameter.SCHEDULER_WITH_REGISTRY){
				DefaultRegistry.m_sRegistryServiceName = OSParameter.SERVICE_NAME;
			}

			if(OSParameter.SERVICE_TYPE != null && 
				(OSParameter.SERVICE_TYPE.Equals("registry") || 
				(OSParameter.SERVICE_TYPE.Equals("scheduler") && OSParameter.SCHEDULER_WITH_REGISTRY))){
				m_sSystemPassword = OSParameter.getSystemPassword();
				//load osregistry information from backup file if it is more updated
				OSRegistryReader osRegistryReader = new OSRegistryReader();
				string sFileName = OSParameter.REGISTRY_FILE;
				string sBackupFileName = sFileName+"_backup";
				try {
					if((!IOUtil.existsFileOrDir(sFileName) && IOUtil.existsFileOrDir(sBackupFileName)) ||
						(IOUtil.existsFileOrDir(sBackupFileName) && IOUtil.getLastWriteTime(sBackupFileName) > IOUtil.getLastWriteTime(sFileName))){
						IOUtil.copyFile(sBackupFileName, sFileName);
					}
					osRegistryReader.readFile(sFileName);
					DefaultRegistry.osRegistry = osRegistryReader.getOSRegistry();
				} 
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}
				int iService = DefaultRegistry.osRegistry.service==null?0:DefaultRegistry.osRegistry.service.Length;
				for(int i = 0; i < iService; i++){	
					try{
						DefaultRegistry.serviceHashTable.Add(DefaultRegistry.osRegistry.service[i].osel.getServiceURI(), DefaultRegistry.osRegistry.service[i]);
					}
					catch(Exception){
					}
				}

				//carry out maintenance
				m_lTimeServiceStarted = CommonUtil.currentTimeMillis();

				//pull info and update services
				OSpLWriter osplWriter = new OSpLWriter();
				osplWriter.setRequestAction("getServiceStatistics");
				osplWriter.setServiceName(m_sRegistryServiceName);
				osplWriter.setServiceURI(OSParameter.OS_REGISTRY_SITE);
				osplWriter.setProcessTime(DateTime.Now);
				string sOSpLInput = osplWriter.writeToString();
			
				OSoLWriter osolWriter = new OSoLWriter();
				osolWriter.setPassword(m_sSystemPassword);
				string sOSoL = osolWriter.writeToString();

				Thread[] mThread = new Thread[iService];
				for(int i = 0; i < iService; i++){
					try{					
						KnockThread knockThread = new KnockThread();
						knockThread.m_sOSpLInput = sOSpLInput;
						knockThread.m_sOSoL = sOSoL;
					
						String sServiceType = osRegistry.service[i].osel.getServiceType();
						if(sServiceType != null && sServiceType.Equals("scheduler")){
							knockThread.m_bSchedulerWithRegistry = OSParameter.SCHEDULER_WITH_REGISTRY;
						}
						else{
							knockThread.m_bSchedulerWithRegistry = false;
						}			
						knockThread.m_sAddress = osRegistry.service[i].osel.getServiceURI();
						knockThread.m_bSetServiceStatistics = true;
						Thread thread = new Thread(new ThreadStart(knockThread.knock));
						mThread[i] = thread;
						thread.Start();
					}
					catch(Exception e){
						IOUtil.log(e.ToString(), null);
					}			
				}
				TimeSpan timeSpan = new TimeSpan(0, 0, 10);
				for(int i = 0; i < iService; i++){
					try{	
						mThread[i].Join(timeSpan);
					}
					catch(Exception e){
						IOUtil.log(e.ToString(), null);
					}			
				}

				timer1 = new System.Timers.Timer(OSParameter.SERVICE_POLLING_INTERVAL_SHORT);
				timer1.Elapsed += new ElapsedEventHandler(serviceTask1);
				timer1.Start();
				timer2 = new System.Timers.Timer(OSParameter.SERVICE_POLLING_INTERVAL_MEDIUM);
				timer2.Elapsed += new ElapsedEventHandler(serviceTask2);
				timer2.Start();
				timer3 = new System.Timers.Timer(OSParameter.SERVICE_POLLING_INTERVAL_LONG);
				timer3.Elapsed += new ElapsedEventHandler(serviceTask3);
				timer3.Start();
			}
		}//static constructor
	}//DefaultRegistry
}//namespace