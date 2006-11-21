using System;
using System.Xml.Serialization;
using System.Diagnostics;
using System.Web.Services.Protocols;
using System.Web.Services.Description;
using System.ComponentModel;
using System.Web.Services;
using System.Collections;
using System.Data;
using System.Threading;
using System.IO;
using System.Timers;
using System.Reflection;

using org.optimizationservices.oscommon.util;
using org.optimizationservices.oscommon.communicationinterface;
using org.optimizationservices.oscommon.localinterface;
using org.optimizationservices.oscommon.representationparser;
using org.optimizationservices.oscommon.datastructure.osprocess;
using org.optimizationservices.oscommon.communicationagent;
using org.optimizationservices.oscommon.datastructure.osgeneral;
using org.optimizationservices.oscommon.datastructure.osquery;
using org.optimizationservices.oscommon.datastructure.osuri;

namespace org.optimizationservices.oscommon.util{
	/// <summary>
	/// The <c>OSServiceUtil</c> class provides a default implementation
	/// of optimization services.  
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	[WebService(Namespace="http://www.optimizationservices.org")]	
	[System.Web.Services.WebServiceBindingAttribute(
		 Name="OSSolverServiceSoapBinding", 
		 Namespace="http://www.optimizationservices.org")]
	[SoapDocumentService(SoapBindingUse.Default, 
		 SoapParameterStyle.Default, 
		 RoutingStyle=SoapServiceRoutingStyle.RequestElement)]
	public class OSServiceUtil : System.Web.Services.WebService, OShL, OScL, OSdL {
		

		/// <summary>
		/// m_sSystemPassword holds the password used for communication between system components.
		/// </summary>
		private static string m_sSystemPassword = "";

		/// <summary>
		/// m_bSendEmailOnLowDiskSpace holds whether an email has been sent on low disk space warning. 
		/// </summary>
		private static bool m_bSendEmailOnLowDiskSpace = false;

		/// <summary>
		/// m_bValidate holds whether the parser should be validating against the xml schema or not.
		/// </summary>
		protected internal bool m_bValidate = OSParameter.VALIDATE; 
	
		/// <summary>
		/// serviceURI holds the service uri. 
		/// </summary>
		public string serviceURI = OSParameter.SERVICE_URI;

		/// <summary>
		/// serviceName holds the service name. 
		/// </summary>
		public string serviceName = OSParameter.SERVICE_NAME;

		/// <summary>
		/// serviceType holds the service type. 
		/// </summary>
		public string serviceType = OSParameter.SERVICE_TYPE;

		/// <summary>
		/// m_sServiceURIInOSoL holds the service uri in osol. 
		/// </summary>
		public string m_sServiceURIInOSoL = "";
	
		/// <summary>
		/// m_sServiceNameInOSoL holds the service name in osol. 
		/// </summary>
		public string m_sServiceNameInOSoL = "";

		/// <summary>
		/// m_sInstanceName holds the name of the instance being solved.
		/// </summary>
		protected internal string m_sInstanceName = "";

		/// <summary>
		/// m_sInstanceLocationType holds the instance location type. 
		/// </summary>
		protected internal string m_sInstanceLocationType = "";

		/// <summary>
		/// m_sInstanceAddress holds the instance address. 
		/// </summary>
		protected internal string m_sInstanceAddress = "";

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
		/// m_sServiceTypeInOSoL holds the service type in the osol
		/// </summary>
		protected string m_sServiceTypeInOSoL = "";

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
		/// m_msRequiredDirectoriesAndFiles holds a list of file and directory names needed to run the job. 
		/// </summary>
		protected string[] m_msRequiredDirectoriesAndFiles = null;

		/// <summary>
		/// m_sCurrentState holds the current state of the service: which can be: 
		/// busy, busyButAccepting, idle, idleButNotAccepting, noResponse. 
		/// </summary>
		protected internal static string m_sCurrentState = "idle";

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
		protected static double m_dServiceUtilization = 0;

		/// <summary>
		/// m_lTotalBusyTime holds the total busy time (solving jobs) since service start. 
		/// </summary>
		protected internal static long m_lTotalBusyTime = 0;

		/// <summary>
		/// m_sJobState holds the job state, which can be waiting, running, killed, finished or unknown.   
		/// </summary>
		protected string m_sJobState= "unknown";

		/// <summary>
		/// serviceURI holds the service uri. 
		/// </summary>
		//public string serviceURI = OSParameter.SERVICE_URI;

		/// <summary>
		/// m_sUserName holds the user name.  
		/// </summary>
		//protected internal string m_sUserName = "";

		/// <summary>
		/// m_lJobSubmitTime holds the job submit time (in millisecond since 1970 UTC).  
		/// </summary>
		protected internal long m_lJobSubmitTime = -1;

		/// <summary>
		/// m_lJobStartTime holds the job start time (in millisecond since 1970 UTC).  
		/// </summary>
		protected internal long m_lJobStartTime = -1;

		/// <summary>
		/// m_lJobScheduledStartTime holds the job scheduled start time. 
		/// </summary>
		protected internal long m_lJobScheduledStartTime = -1;

		/// <summary>
		/// m_lJobEndTime holds the job end time (in millisecond since 1970 UTC).   
		/// </summary>
		protected internal long m_lJobEndTime = -1;

		/// <summary>
		/// m_lJobDuration holds the time the job took in millisecond.
		/// </summary>
		protected internal long m_lJobDuration = -1;

		/// <summary>
		/// m_jobScheduledStartTime holds the job's scheduled start time.
		/// </summary>
		//protected internal DateTime m_jobScheduledStartTime = new DateTime(1970, 1, 1, 0, 0, 0);

		/// <summary>
		/// m_msJobDependencies holds a string array of jobIDs the the current job depends on. 
		/// </summary>
		//protected internal string[] m_msJobDependencies = null;

		/// <summary>
		/// m_msRequiredDirectoriesAndFiles holds a list of file and directory names needed to run the job. 
		/// </summary>
		//protected string[] m_msRequiredDirectoriesAndFiles = null;

		/// <summary>
		/// m_solver holds the solver engine
		/// </summary>
		protected internal DefaultSolver m_solver = null;
		
		/// <summary>
		/// m_solverThread holds the solver thread. 
		/// </summary>
		protected SolverThread m_solverThread = null;

		/// <summary>
		/// m_simulation holds the simulation engine
		/// </summary>
		protected internal DefaultSimulation m_simulation = null;

		/// <summary>
		/// m_registry holds the registry
		/// </summary>
		protected internal DefaultRegistry m_registry = null;

		/// <summary>
		/// solver holds the solver engine
		/// </summary>
		public DefaultSolver solver{
			get{
				return m_solver;
			}
			set{
				this.m_solver = value;
			}
		}//solver

		/// <summary>
		/// simulation holds the simulation engine
		/// </summary>
		public DefaultSimulation simulation{
			get{
				return m_simulation;
			}
			set{
				this.m_simulation = value;
			}
		}//simulation

		/// <summary>
		/// registry holds the OS registry
		/// </summary>
		public DefaultRegistry registry{
			get{
				return m_registry;
			}
			set{
				this.m_registry = value;
			}
		}//registry

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
		/// m_osilReader holds the OSiL reader.
		/// </summary>
		protected internal OSiLReader m_osilReader = null;

		/// <summary>
		/// m_osolReader holds the OSoL reader.
		/// </summary>
		protected internal OSoLReader m_osolReader = null;

		/// <summary>
		/// m_osOption holds the parsed OSOption data structure read from the OSoL string.
		/// </summary>
		protected OSOption m_osOption = null;

		/// <summary>
		/// m_bReadOSoL holds whehter the OSoL string has been read or not.
		/// </summary>
		protected bool m_bReadOSoL = false;

		/// <summary>
		/// m_osslReader holds the OSsL reader.
		/// </summary>
		protected internal OSsLReader m_osslReader = null;

		/// <summary>
		/// m_osrlReader holds the OSrL reader.
		/// </summary>
		protected internal OSrLReader m_osrlReader = null;

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
		/// m_osilWriter holds the OSiL writer.
		/// </summary>
		protected internal OSiLWriter m_osilWriter = null;

		/// <summary>
		/// m_osolWriter holds the OSoL writer.
		/// </summary>
		protected internal OSoLWriter m_osolWriter = null;

		/// <summary>
		/// m_osslWriter holds the OSsL writer.
		/// </summary>
		protected internal OSsLWriter m_osslWriter = null;

		/// <summary>
		/// m_osrlWriter holds the OSrL writer.
		/// </summary>
		protected internal OSrLWriter m_osrlWriter = null;

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
		/// m_solverThreadHashTable holds the solverThread instance that will 
		/// be launched by a separate thread. 
		/// </summary>
		internal static Hashtable m_solverThreadHashTable = new Hashtable();

		/// <summary>
		/// m_threadHashTable holds a hashtable of all the threads that started the solve() 
		/// methods launched by this service. 
		/// The hashtable names are the thread names (same as the jobIDs) and 
		/// the hashtable objects are the threads
		/// </summary>
		internal static Hashtable m_threadHashTable = new Hashtable();

		/// <summary>
		/// m_jobStatisticsTable holds a hashtable of job statistics. 
		/// The hashtable keys are the jobIDs and the hashtable objects are the job statistics.
		/// </summary>
		internal protected static Hashtable m_jobStatisticsTable = new Hashtable();

		/// <summary>
		/// m_vCurrentJobIDs holds a sequence of current jobIDs according to the time the jobs are 
		/// submitted, with the first one being the earliest. 
		/// </summary>
		internal static ArrayList m_vCurrentJobIDs = new ArrayList();

		/// <summary>
		/// m_vWaitingJobIDs holds a sequence of waiting jobIDs. 
		/// </summary>
		internal static ArrayList m_vWaitingJobIDs = new ArrayList();

		/// <summary>
		/// m_vFinishedJobIDs holds a sequence of current jobIDs according to the time the jobs are
		/// finished, with the first one being the earliest. 
		/// </summary>
		internal static ArrayList m_vFinishedJobIDs = new ArrayList();

		/// <summary>
		/// m_userJobCountTable holds the number of jobs currently run by a user. 
		/// </summary>
		internal static Hashtable m_userJobCountTable = new Hashtable();

		/// <summary>
		///  acceptingSolverURIs holds the URIs of accepting solvers. 
		/// </summary>
		protected internal static ArrayList acceptingSolverURIs = new ArrayList();

		/// <summary>
		/// m_processsHashTable holds a hashtable of all the process launched by this service. 
		/// The hashtable names are the thread names (same as the jobIDs) and 
		/// the hashtable objects are the an arraylist of process IDs launched by the thread. 
		/// </summary>
		protected internal static Hashtable m_processsHashTable = new Hashtable();

		/// <summary>
		/// processsHashTable holds a hashtable of all the process launched by this service. 
		/// The hashtable names are the thread names (same as the jobIDs) and 
		/// the hashtable objects are the an arraylist of process IDs launched by the thread. 
		/// </summary>
		public static Hashtable processsHashTable{
			get{
				return m_processsHashTable;
			}
			set{
				m_processsHashTable = value;
			}
		}//processsHashTable

		/// <summary>
		/// Default constructor. 
		/// </summary>
		public OSServiceUtil(){
		}//constructor

		/// <summary>
		/// Get a unique job id from a service, before calling the service to solve a problem. This method call is always
		/// required before an asynchronous send call. It may be or may not be used before a synchronous solve call. 
		/// </summary>
		/// <param name="osol">holds the option in a string which format follows OSoL schema.</param>
		/// <returns>jobID, a unique job ID generated by the service.</returns>
		[System.Web.Services.WebMethodAttribute()]
		[System.Web.Services.Protocols.SoapRpcMethodAttribute("OSSolverService#getJobID", 
			 RequestNamespace="http://www.optimizationservices.org", 
			 ResponseNamespace="http://www.optimizationservices.org")]
		[return: System.Xml.Serialization.SoapElementAttribute("jobID")]
		public string getJobID(string osol){
			if(osol == null) osol = "";
			return CommonUtil.getJobID(osol);
		}//getJobID
		

		/// <summary>
		/// read and parse the osol string. 
		/// </summary>
		/// <param name="osol">holds the option string to read. </param>
		/// <returns>whether the osol string is read successfully. </returns>
		protected bool readOSoL(string osol){
			if(osol == null) osol = "";
			if(m_bReadOSoL) return true;
			m_osOption = new OSOption();

			if(osol == null || osol.Length <= 0){
				return true;
			}
			m_osolReader = new OSoLReader(m_bValidate);
			try{
				bool bRead = m_osolReader.readString(osol);
				if(!bRead) throw new Exception("Invalid OSoL option");
				m_osOption = m_osolReader.getOSOption();
				if(m_osOption == null){
					m_osOption = new OSOption();
					throw new Exception("Invalid OSoL option");
				}
			
				//get general options
				m_sServiceURIInOSoL = m_osOption.getServiceURI();
				m_sServiceNameInOSoL = m_osOption.getServiceName();
				m_sInstanceName = m_osOption.getInstanceName();
				m_sInstanceLocationType = m_osOption.getInstanceLocationType();
				if(m_sInstanceLocationType == null || m_sInstanceLocationType.Length <= 0){
					m_sInstanceLocationType = "local";
				}
				m_sInstanceAddress = m_osOption.getInstanceAddress();
				m_sJobID = m_osOption.getJobID();
				m_sLicense = m_osOption.getLicense();
				m_sUserName = m_osOption.getUserName();
				if(m_sUserName == null) m_sUserName = "";
				m_sPassword = m_osOption.getPassword();
				m_sContactTransportType = m_osOption.getContactTransportType();
				if(m_sContactTransportType == null || m_sContactTransportType.Length <= 0){
					m_sContactTransportType = "osp";
				}
				m_sContactAddress = m_osOption.getContactAddress();		
			
				//get system related options
				m_dMinDiskSpace = m_osOption.getSystemMinDiskSpace();
				m_dMinMemorySize = m_osOption.getSystemMinMemorySize();
				m_dMinCPUSpeed = m_osOption.getSystemMinCPUSpeed();

				//get service related options
				m_sServiceTypeInOSoL = m_osOption.getServiceType();
			
				//get job related options
				double dJobMaxTime = m_osOption.getJobMaxTime();
				if(dJobMaxTime != Double.PositiveInfinity && dJobMaxTime < OSParameter.JOB_MAX_TIME && dJobMaxTime > 0){
					m_dJobMaxTime  = dJobMaxTime;
				}
				DateTime jobScheduledStartTime = m_osOption.getJobScheduledStartTime();
				if(jobScheduledStartTime.Year > 1970){
					m_jobScheduledStartTime  = jobScheduledStartTime;
					m_lJobScheduledStartTime = CommonUtil.timeMillis(m_jobScheduledStartTime);
				}
				m_msJobDependencies = m_osOption.getJobDependencies();
				m_msRequiredDirectoriesAndFiles = m_osOption.getRequiredDirectoriesAndFiles();
			
				m_bReadOSoL = true;
				return true;
			}
			catch(Exception e){
				IOUtil.log(e.ToString(), null);
				return false;
			}
		}//readOSoL

		/// <summary>
		/// check if the job is permitted. 
		/// </summary>
		/// <returns>if the job should be permitted.</returns>
		protected internal bool checkPermision(){
			bool bCheck = true;
			string sMessage = "";
			if(OSParameter.REQUIRE_LICENSE || OSParameter.REQUIRE_USER_NAME || OSParameter.REQUIRE_PASSWORD){
				if(m_sPassword != null && m_sPassword.Length > 0 && OSParameter.checkSystemPassword(m_sPassword)){
					bCheck = true;
					return bCheck;
				}
				if(OSParameter.REQUIRE_LICENSE){
					bCheck = OSParameter.checkLicense(m_sUserName, m_sLicense);
					if(!bCheck){
						sMessage = "Permission error: wrong licence";
					}
				}
				if(bCheck && (OSParameter.REQUIRE_USER_NAME || OSParameter.REQUIRE_PASSWORD)){
					bCheck = OSParameter.checkUserNameAndPassword(m_sUserName, m_sPassword);
					if(!bCheck){
						sMessage = "Permission error: wrong user name and/or password";
					}
				}
				if(!bCheck){
					throw new Exception(sMessage);
				}
			}
			return bCheck;
		}//checkPermision
	
		/// <summary>
		/// check whether the job meets system requirement. 
		/// </summary>
		/// <returns>whether the job meets system requirement</returns>
		protected bool checkSystemRequirement(){
			bool bCheck	= true;
			string sMessage = "";
		
			//check if service is full
			m_iCurrentJobCount = m_vCurrentJobIDs.Count;
			if(m_iCurrentJobCount >= OSParameter.MAX_JOB_NUMBERS){
				sMessage = "System warning: server is busy and is already taking on maximum number of jobs.";
				throw new Exception(sMessage);
			}

			//check if disk space is enough
			try{
				m_dAvailableDiskSpace = IOUtil.getFreeDiskSpace(OSParameter.CODE_DRIVE);	
			}
			catch(Exception){
				sMessage = "System warning: Service (" + (OSParameter.SERVICE_URI) +") cannot check disk space.";
				IOUtil.log(sMessage, null);
				m_dAvailableDiskSpace = Double.PositiveInfinity;
				sMessage = "";
			}
			if(m_dAvailableDiskSpace <= OSParameter.MINIMUM_DISKSPACE_TRIGGER){
				sMessage = "System warning: service (" + (OSParameter.SERVICE_URI) +") is running low on disk space (" + m_dAvailableDiskSpace + ")";
				m_iCurrentJobCount = m_vCurrentJobIDs.Count;
				if(m_iCurrentJobCount > 0){
					m_sCurrentState = "busy";				
				}
				else{
					m_sCurrentState = "idleButNotAccepting";
				}
				throw new Exception(sMessage);
			}

			//check if memory size is enough
			try{
				m_dAvailableMemory = ProcessUtil.getFreeMemory();	
			}
			catch(Exception){
				sMessage = "System warning: service (" + (OSParameter.SERVICE_URI) +") cannot check available memory size";
				IOUtil.log(sMessage, null);
				m_dAvailableMemory = Double.PositiveInfinity;
				sMessage = "";
			}
			if(m_dAvailableMemory <= ((double)OSParameter.MINIMUM_MEMORY_TRIGGER)){
				sMessage = "System warning: server (" + (OSParameter.SERVICE_URI) +") is running low on memory (" + m_dAvailableMemory + ")";
				m_iCurrentJobCount = m_vCurrentJobIDs.Count;
				if(m_iCurrentJobCount > 0){
					m_sCurrentState = "busy";				
				}
				else{
					m_sCurrentState = "idleButNotAccepting";
				}
				throw new Exception(sMessage);
			}

			//check user quota
			if(m_sUserName == null) m_sUserName = "";
			if(OSParameter.MAX_JOBS_PER_USER > 0 && !m_vWaitingJobIDs.Contains(m_sJobID)){
				string sCount = (string)m_userJobCountTable[m_sUserName];
				int iCount;
				if(sCount == null || sCount.Length <= 0){
					iCount = 0;
				}
				else{
					try {
						iCount = Int32.Parse(sCount);
					} 
					catch (Exception) {
						iCount = 0;
					}
					if(iCount < 0) iCount = 0;
				}
				if(iCount >= OSParameter.MAX_JOBS_PER_USER){
					sMessage = "System warning: the jobs submitted by the user " + m_sUserName + " has exceeded maximum allowed.";
					throw new Exception(sMessage);
				}
			}
			//check minimum system requirement
			if(serviceType == null || !serviceType.Equals("scheduler")){
				if(m_dAvailableDiskSpace < m_dMinDiskSpace){
					sMessage = "System warning: the server cannot meet the disk space requirement for the job";
				}
				else if(m_dAvailableMemory <  m_dMinMemorySize){
					sMessage = "System warning: the server cannot meet the memory space requirement for the job";
				}
				else if(OSParameter.CPU_SPEED < m_dMinCPUSpeed){
					sMessage = "System warning: the server cannot meet the cpu space requirement for the job";				
				}
			}
			if(sMessage != null && sMessage.Length > 0){
				throw new Exception(sMessage);
			}
			return bCheck;
		}//checkSystemRequirement

		/// <summary>
		/// initialize statistics. 
		/// </summary>
		protected internal void initializeStatistics(){
			JobStatistics jobStatistics  = (JobStatistics)m_jobStatisticsTable[m_sJobID];
			if(jobStatistics == null){
				jobStatistics = new JobStatistics();						
				jobStatistics.jobID = m_sJobID;
				m_jobStatisticsTable.Add(m_sJobID, jobStatistics);
				m_iTotalJobsSoFar++;

				if(m_sUserName == null) m_sUserName = "";
				string sCount = (string)m_userJobCountTable[m_sUserName];
				int iCount;
				if(sCount == null || sCount.Length <= 0){
					iCount = 0;
				}
				else{
					try {
						iCount = Int32.Parse(sCount);
					} 
					catch (Exception) {
						iCount = 0;
					}
					if(iCount < 0) iCount = 0;
				}
				iCount += 1;
				m_userJobCountTable.Remove(m_sUserName);
				m_userJobCountTable.Add(m_sUserName, iCount+"");

			}
			m_vWaitingJobIDs.Remove(m_sJobID);
			m_vCurrentJobIDs.Remove(m_sJobID);
			m_vCurrentJobIDs.Add(m_sJobID);
			m_iCurrentJobCount = m_vCurrentJobIDs.Count;

			if(m_iCurrentJobCount >= OSParameter.MAX_JOB_NUMBERS){
				m_sCurrentState = "busy";
			}
			else{
				m_sCurrentState = "busyButAccepting";
			}

			jobStatistics.jobID = m_sJobID;	
			jobStatistics.state = "running";
			m_sJobState = jobStatistics.state;

			if(serviceType.Equals("scheduler")){
				jobStatistics.serviceURI = "";			
			}
			else{
				jobStatistics.serviceURI = (OSParameter.SERVICE_URI);
			}
			jobStatistics.userName = m_sUserName;
			if(jobStatistics.submitTime.Year <= 1970){
				jobStatistics.submitTime = DateTime.Now;
			}
			m_lJobSubmitTime = CommonUtil.timeMillis(jobStatistics.submitTime);
			jobStatistics.scheduledStartTime = m_jobScheduledStartTime;
			if(m_jobScheduledStartTime.Year > 1970){
				m_lJobScheduledStartTime = CommonUtil.timeMillis(m_jobScheduledStartTime);
			}
			else{
				m_lJobScheduledStartTime = -1;			
			}			
			jobStatistics.startTime = DateTime.Now;
			m_lJobStartTime = CommonUtil.timeMillis(jobStatistics.startTime);
			jobStatistics.endTime = new DateTime(1970, 1, 1, 0, 0, 0);
			m_lJobEndTime = -1;
			jobStatistics.duration = Double.NaN; 
			m_lJobDuration = -1;
			if(m_msJobDependencies != null && m_msJobDependencies.Length > 0){
				jobStatistics.dependencies = new JobDependencies();
				jobStatistics.dependencies.jobID = m_msJobDependencies;			
			}
			if(m_msRequiredDirectoriesAndFiles != null && m_msRequiredDirectoriesAndFiles.Length > 0){
				jobStatistics.requiredDirectoriesAndFiles = new DirectoriesAndFiles();
				jobStatistics.requiredDirectoriesAndFiles.path = m_msRequiredDirectoriesAndFiles;
			}	
			
			//save ospl
			saveOSpL();

		}//initializeStatistics

		/// <summary>
		/// check if the job should wait. 
		/// </summary>
		/// <param name="osil">holds the instance in a string which format follows OSiL schema.</param>
		/// <param name="osol">holds the option in a string which format follows OSoL schema.</param>
		/// <param name="checkSolverAvailability">holds whether the method should check solver availability. </param>
		/// <param name="process">holds whether the method should process the waiting jobs.</param>
		/// <returns>if the job should wait. </returns>
		protected internal bool checkWaiting(string osil, string osol, bool checkSolverAvailability, bool process){
			if(osil == null) osil = "";
			if(osol == null) osol = "";

			bool bWait = false;
			string sMessage = "";

			//check job scheduling
			if(m_lJobScheduledStartTime > 0){
				long lNow = CommonUtil.currentTimeMillis();
				if(m_lJobScheduledStartTime > lNow){				
					bWait = true;
				}
			}
			//check job dependencies
			if(!bWait && m_msJobDependencies != null && m_msJobDependencies.Length > 0){
				int iFinishedJob = m_vFinishedJobIDs.Count;
				int iJobDependences =  m_msJobDependencies == null?0:m_msJobDependencies.Length;
				for(int i = 0; i < iJobDependences; i++){
					bool bFound = false;
					for(int j = iFinishedJob-1; j >= 0 ; j--){
						try{
							if( ((string)m_msJobDependencies[i]).Equals((string)m_vFinishedJobIDs[j])){
								bFound = true;
								break;
							}
						}
						catch(Exception){
						}
					}
					if(!bFound){
						bWait = true;
						break;
					}
				}
			}
			//check required file or directory dependencies
			if(!bWait && m_msRequiredDirectoriesAndFiles != null && m_msRequiredDirectoriesAndFiles.Length > 0){
				int iRequiredDirectoriesAndFiles = m_msRequiredDirectoriesAndFiles.Length;
				for(int i = 0; i < iRequiredDirectoriesAndFiles; i++){
					if(!IOUtil.existsFileOrDir(m_msRequiredDirectoriesAndFiles[i])){
						bWait = true;
						break;
					}
				}
			}
			//if scheduler check for available solver service
			if(!bWait && serviceType.Equals("scheduler") && checkSolverAvailability){
				if(acceptingSolverURIs.Count <= 0){
					m_osqlWriter = new OSqLWriter();
					StandardQuery standardQuery = new StandardQuery();
					standardQuery.currentState = "accepting";
					standardQuery.serviceType = "solver";
					m_osqlWriter.setStandardQuery(standardQuery);
					string sOSqL = m_osqlWriter.writeToString();
				
					m_osolWriter = new OSoLWriter();
					m_osolWriter.setServiceURI(OSParameter.SERVICE_URI);
					m_osolWriter.setServiceName(OSParameter.SERVICE_NAME);
					m_osolWriter.setJobID(m_sJobID);
					m_osolWriter.setUserName(m_sUserName);				
					m_osolWriter.setPassword(OSParameter.getSystemPassword());
					m_osolWriter.setServiceType("scheduler");
					String sOSoL = m_osolWriter.writeToString();
				
					string sOSuL = "";
					try{
						FindThread findThread = new FindThread();
						if(OSParameter.SCHEDULER_WITH_REGISTRY){
							OSServiceUtil osServiceUtil = new OSServiceUtil();						
							osServiceUtil.serviceName = "OSRegistryService";
							osServiceUtil.serviceURI = OSParameter.OS_REGISTRY_SITE; 
							osServiceUtil.serviceType = "registry";
							osServiceUtil.registry = new DefaultRegistry();
							findThread.m_osServiceUtil = osServiceUtil;						
						}
						else{
							OSRegistryAgent osRegistryAgent = new OSRegistryAgent(OSParameter.OS_REGISTRY_SITE);
							findThread.m_osRegistryAgent = osRegistryAgent;
						}
						findThread.m_sOSqL = sOSqL;
						findThread.m_sOSoL = sOSoL;
								
		
						Thread thread = new Thread(new ThreadStart(findThread.find));	
						thread.Start();

						TimeSpan timeSpan = new TimeSpan(0, 0, 30);
						thread.Join(timeSpan);

						sOSuL = findThread.m_sOSuL;	
					}
					catch(Exception e){
						IOUtil.log(e.ToString(), null);
					}
					if(sOSuL != null && sOSuL.Length > 0){
						try {
							m_osulReader = new OSuLReader();
							bool bRead = m_osulReader.readString(sOSuL);
							if(!bRead) throw new Exception("Invalid OSuL URIs");
							URI[] mURI = m_osulReader.getURIMatches();
							int iURIs = (mURI==null?0:mURI.Length);
							for(int i = 0; i < iURIs; i++){
								acceptingSolverURIs.Add(mURI[i].value);
							}
							acceptingSolverURIs.Remove(OSParameter.OS_SCHEDULER_SITE);
							acceptingSolverURIs.Remove(OSParameter.OS_REGISTRY_SITE);
						} 
						catch (Exception e) {
							IOUtil.log(e.ToString(), null);
						}
					}
				}
				if(acceptingSolverURIs.Count <= 0){
					bWait = true;
				}
				else{
					if(m_solverThread == null){
						m_solverThread = new SolverThread();	
					}	
					m_solverThread.m_msURIs = new string[1];	
					m_solverThread.m_msURIs[0] = (string)acceptingSolverURIs[0];
					acceptingSolverURIs.RemoveAt(0);
				}
			}

			//process
			if(bWait && process){
				//update statistics
				JobStatistics jobStatistics  = (JobStatistics)m_jobStatisticsTable[m_sJobID];
				if(jobStatistics == null){
					jobStatistics = new JobStatistics();	
					jobStatistics.jobID = m_sJobID;
					m_jobStatisticsTable.Add(m_sJobID, jobStatistics);
				}
				m_threadHashTable.Remove(m_sJobID);
				m_solverThreadHashTable.Remove(m_sJobID);
				processsHashTable.Remove(m_sJobID);			
				m_vCurrentJobIDs.Remove(m_sJobID);
				m_vWaitingJobIDs.Remove(m_sJobID);
				m_vWaitingJobIDs.Add(m_sJobID);			
				m_iCurrentJobCount = m_vCurrentJobIDs.Count;
                
				if(m_iCurrentJobCount >= OSParameter.MAX_JOB_NUMBERS){
					m_sCurrentState = "busy";
				}
				else if(m_iCurrentJobCount > 0){
					m_sCurrentState = "busyButAccepting";
				}
				else {
					m_sCurrentState = "idle";
				}

				jobStatistics.jobID = m_sJobID;			
				jobStatistics.state = "waiting";
				m_sJobState = jobStatistics.state;			
				if(serviceType.Equals("scheduler")){
					jobStatistics.serviceURI = "";			
				}
				else{
					jobStatistics.serviceURI = (OSParameter.SERVICE_URI);
				}
				if(jobStatistics.userName == null || jobStatistics.userName.Length <= 0){
					jobStatistics.userName = m_sUserName;								
				}
				if(jobStatistics.submitTime.Year <= 1970){
					jobStatistics.submitTime = DateTime.Now; 
				}
				m_lJobSubmitTime = CommonUtil.timeMillis(jobStatistics.submitTime);			
				jobStatistics.scheduledStartTime = m_jobScheduledStartTime;
				if(m_jobScheduledStartTime.Year > 1970){
					m_lJobScheduledStartTime = CommonUtil.timeMillis(m_jobScheduledStartTime);
				}
				else{
					m_lJobScheduledStartTime = -1;
				}			
				jobStatistics.startTime = new DateTime(1970, 1, 1, 0, 0, 0); 
				m_lJobStartTime = -1;
				jobStatistics.endTime = new DateTime(1970, 1, 1, 0, 0, 0); 
				m_lJobEndTime = -1;
				jobStatistics.duration = Double.NaN;
				m_lJobDuration = -1;
				if(m_msJobDependencies != null && m_msJobDependencies.Length > 0){
					jobStatistics.dependencies = new JobDependencies();
					jobStatistics.dependencies.jobID = m_msJobDependencies;
				}			
				if(m_msRequiredDirectoriesAndFiles != null && m_msRequiredDirectoriesAndFiles.Length > 0){
					jobStatistics.requiredDirectoriesAndFiles = new DirectoriesAndFiles();
					jobStatistics.requiredDirectoriesAndFiles.path = m_msRequiredDirectoriesAndFiles;
				}	
				//save ospl
				saveOSpL();
				
				bool bRemoveWaitingJob = false;
				if(m_vWaitingJobIDs.Count > OSParameter.MAX_WAITING_NUMBERS){
					sMessage = "Waiting error: maximum waiting number reached";
					bRemoveWaitingJob = true;
				}
				else{
					//save files
					string sInstanceFile = OSParameter.TEMP_FILE_FOLDER+m_sJobID+".osil";
					string sOptionFile = OSParameter.TEMP_FILE_FOLDER+m_sJobID+".osol";
					bool bWriteOSiL = true;
					if(!IOUtil.existsFileOrDir(sInstanceFile)){
						bWriteOSiL = IOUtil.writeStringToFile(osil, sInstanceFile);
					}
					if(!bWriteOSiL){
						bRemoveWaitingJob = true;
						sMessage = "Waiting error: unable to save OSiL arguments for future computation";
						IOUtil.log("the service is not able to write osil to file", null);
						IOUtil.deleteFile(sInstanceFile);
					}
					bool bWriteOSoL = true;
					if(bWriteOSiL){
						if(!IOUtil.existsFileOrDir(sOptionFile)){
							bWriteOSoL = IOUtil.writeStringToFile(osol, sOptionFile);
						}
						if(!bWriteOSoL){
							bRemoveWaitingJob = true;
							sMessage = "Waiting error: unable to save OSoL arguments for future computation";
							IOUtil.log("the service is not able to write osol to file", null);
							IOUtil.deleteFile(sOptionFile);
						}
					}
				}
				if(bRemoveWaitingJob){
					removeWaitingJob(m_sJobID);			
					throw new Exception(sMessage);
				}
			}
			return bWait;
		}//checkWaiting

		/// <summary>
		/// postprocess after the solve or send method. 
		/// </summary>
		/// <param name="kill">holds whether the process is called from a kill command. </param>
		protected void postprocess(bool kill){	
			if(m_vFinishedJobIDs.Contains(m_sJobID)){
				return;
			}
			if(serviceType.Equals("solver") || serviceType.Equals("analyzer")){
				ArrayList vProcess = (ArrayList)processsHashTable[m_sJobID];
				if(vProcess != null && vProcess.Count > 0){
					for(int i = 0; i < vProcess.Count; i++){
						try{
							Process process = Process.GetProcessById((int)vProcess[i]);
							process.Kill();
						}
						catch(Exception e){
							IOUtil.log(e.ToString(), null);
						}
					}
				}
				processsHashTable.Remove(m_sJobID);
			}
				
			Thread thread = (Thread)m_threadHashTable[m_sJobID];

			JobStatistics jobStatistics  = (JobStatistics)m_jobStatisticsTable[m_sJobID];
			if(jobStatistics == null){
				jobStatistics = new JobStatistics();
				jobStatistics.jobID = m_sJobID;
				m_jobStatisticsTable.Add(m_sJobID, jobStatistics);
			}

			if(m_sUserName == null) m_sUserName = "";
			string sCount = (string)m_userJobCountTable[m_sUserName];
			int iCount;
			if(sCount == null || sCount.Length <= 0){
				iCount = 0;
			}
			else{
				try {
					iCount = Int32.Parse(sCount);
				} 
				catch (Exception) {
					iCount = 0;
				}
				if(iCount <= 0){
					iCount = 0;
				}
				else if(m_vWaitingJobIDs.Contains(m_sJobID) || m_vCurrentJobIDs.Contains(m_sJobID)){
					iCount -= 1;
				}
			}

			m_userJobCountTable.Remove(m_sUserName);
			m_userJobCountTable.Add(m_sUserName, iCount+"");

			m_threadHashTable.Remove(m_sJobID);
			m_solverThreadHashTable.Remove(m_sJobID);
			processsHashTable.Remove(m_sJobID);
			m_vWaitingJobIDs.Remove(m_sJobID);
			m_vCurrentJobIDs.Remove(m_sJobID);
			m_vFinishedJobIDs.Remove(m_sJobID);
			m_vFinishedJobIDs.Add(m_sJobID);
			m_iCurrentJobCount = m_vCurrentJobIDs.Count;			

			try{
				m_dAvailableDiskSpace = IOUtil.getFreeDiskSpace(OSParameter.CODE_DRIVE);	
			}
			catch(Exception e){
				IOUtil.log(e.ToString(), null);
				m_dAvailableDiskSpace = Double.PositiveInfinity;
			}
			try{
				System.GC.Collect();
				m_dAvailableMemory = ProcessUtil.getFreeMemory();	
			}
			catch(Exception e){
				IOUtil.log(e.ToString(), null);
				m_dAvailableMemory = Double.PositiveInfinity;
			}
			if(m_dAvailableDiskSpace <= OSParameter.MINIMUM_DISKSPACE_TRIGGER ||
				m_dAvailableMemory <= ((double)OSParameter.MINIMUM_MEMORY_TRIGGER)){
				if(m_iCurrentJobCount > 0){
					m_sCurrentState = "busy";				
				}
				else{
					m_sCurrentState = "idleButNotAccepting";
				}
			}
			else{
				if(m_iCurrentJobCount == 0){
					m_sCurrentState = "idle";
				}
				else if(m_iCurrentJobCount >= OSParameter.MAX_JOB_NUMBERS){
					m_sCurrentState = "busy";
				}
				else{
					m_sCurrentState = "busyButAccepting";
				}
			}

			jobStatistics.jobID = m_sJobID;
			jobStatistics.state = kill?"killed":"finished";
			m_sJobState = jobStatistics.state;

			jobStatistics.endTime = DateTime.Now;
			m_lJobEndTime = CommonUtil.timeMillis(jobStatistics.endTime);
			m_lTimeLastJobEnded = m_lJobEndTime;

			if(jobStatistics.startTime.Year > 1970){
				m_lJobStartTime = CommonUtil.timeMillis(jobStatistics.startTime);
				m_lJobDuration = m_lJobEndTime - m_lJobStartTime;
				jobStatistics.duration = m_lJobDuration/1000;
				m_lLastJobTook = m_lJobDuration;
				if(m_lJobDuration >= 0){
					m_lTotalBusyTime += m_lJobDuration;
				}
				else{
					m_lJobDuration = -1;
					jobStatistics.duration = -1;
					m_lLastJobTook = -1;
				}
			}
			else{
				m_lJobStartTime = -1;
				m_lJobDuration = -1;
				jobStatistics.duration = -1;
				m_lLastJobTook = -1;
			}
			m_dServiceUtilization = (m_lTotalBusyTime/(m_lJobEndTime - m_lTimeServiceStarted));						
			
			//contact registry
			updateRegistry(false);

			//save ospl	
			saveOSpL();

			//contact the sender
			contactSender();

			//request job at scheduler
			requestJob();

			if(kill){
				if(thread != null){
					try{
						thread.Abort();
					}
					catch(Exception e){
						IOUtil.log(e.ToString(), null);
					}
				}
			}
		}//postprocess

		/// <summary>
		/// update the registry
		/// </summary>
		/// <param name="wait">holds whether updateRegistry should be waited before it is finished.</param>
		/// <returns>if the registry is updated. </returns>
		protected internal bool updateRegistry(bool wait){
			try {
			if(OSParameter.OS_REGISTRY_SITE == null || OSParameter.OS_REGISTRY_SITE.Length <= 0) return true;

				m_osplWriter = new OSpLWriter();
				m_osplWriter.setRequestAction("setServiceStatistics");
				m_osplWriter.setServiceURI(OSParameter.SERVICE_URI);
				m_osplWriter.setServiceName(OSParameter.SERVICE_NAME);
				m_osplWriter.setProcessTime(DateTime.Now);
				m_osplWriter.setCurrentState(m_sCurrentState);
				m_osplWriter.setAvailableDiskSpace(m_dAvailableDiskSpace);
				m_osplWriter.setAvailableMemory(m_dAvailableMemory);
				m_osplWriter.setCurrentJobCount(m_iCurrentJobCount);
				m_osplWriter.setTotalJobsSoFar(m_iTotalJobsSoFar);
				m_osplWriter.setTimeLastJobEnded(CommonUtil.createNativeDateTime(m_lTimeLastJobEnded));
				if(m_lLastJobTook < 0){
					m_osplWriter.setTimeLastJobTook(-1);					
				}
				else{
					m_osplWriter.setTimeLastJobTook((double)(m_lLastJobTook/1000.0));
				}
				m_osplWriter.setTimeServiceStarted(CommonUtil.createNativeDateTime(m_lTimeServiceStarted));
				m_osplWriter.setServiceUtilization(m_dServiceUtilization);
				string sProcessInput = m_osplWriter.writeToString();

				m_osolWriter = new OSoLWriter();
				m_osolWriter.setServiceURI(OSParameter.SERVICE_URI);
				m_osolWriter.setServiceName(OSParameter.SERVICE_NAME);
				m_osolWriter.setJobID(m_sJobID);
				m_osolWriter.setLicense(m_sLicense);
				m_osolWriter.setUserName(m_sUserName);		
				m_osolWriter.setPassword(OSParameter.getSystemPassword());			
				string sServiceType = (serviceType==null||serviceType.Length <= 0)?"solver":serviceType;
				m_osolWriter.setServiceType(sServiceType);
				string sOption = m_osolWriter.writeToString();

				KnockRegistryThread knockRegistryThread = new KnockRegistryThread();
				if(sServiceType.Equals("scheduler") && OSParameter.SCHEDULER_WITH_REGISTRY){
					OSServiceUtil osServiceUtil = new OSServiceUtil();						
					osServiceUtil.serviceName = "OSRegistryService";
					osServiceUtil.serviceURI = OSParameter.OS_REGISTRY_SITE; 
					osServiceUtil.serviceType = "registry";
					osServiceUtil.registry = new DefaultRegistry();
					knockRegistryThread.m_osServiceUtil = osServiceUtil;						
				}
				else{
					OSRegistryAgent osRegistryAgent = new OSRegistryAgent(OSParameter.OS_REGISTRY_SITE);
					knockRegistryThread.m_osRegistryAgent = osRegistryAgent;
				}
				knockRegistryThread.m_sOSpLInput = sProcessInput;
				knockRegistryThread.m_sOSoL = sOption;
								
				Thread thread = new Thread(new ThreadStart(knockRegistryThread.knock));	
				thread.Start();
				if(wait){
					int iHour = 0;
					int iMin = 0;
					int iSec = 10;
					TimeSpan timeSpan = new TimeSpan(iHour, iMin, iSec);
					thread.Join(timeSpan);
				}
				return true;
			} 
			catch (Exception e) {
				IOUtil.log(e.ToString(), null);
				return false;
			}
		}//updateRegistry

		/// <summary>
		/// contact the sender
		/// </summary>
		/// <returns>whether the sender is contacted successfully</returns>
		protected internal bool contactSender(){
			if(m_sContactAddress != null && m_sContactAddress.Length > 0  || 
				(m_sServiceTypeInOSoL != null && m_sServiceTypeInOSoL.Equals("scheduler"))){
				if(m_sContactTransportType == null || m_sContactTransportType.Length <= 0){
					m_sContactTransportType = "osp";
				}
				string sMessage1 = "Your job " + m_sJobID + " has completed on " + (OSParameter.SERVICE_URI);
				try {
					if(m_sContactTransportType.Equals("smtp") && (m_sContactAddress != null && m_sContactAddress.Length > 0)){
						MailUtil.sendInThread(OSParameter.FROM_EMAIL, m_sContactAddress, null, null, "notifyJobCompletion", sMessage1, null);
					}
					if(m_sContactTransportType.Equals("osp") || (m_sServiceTypeInOSoL != null && m_sServiceTypeInOSoL.Equals("scheduler"))){
						m_osplWriter = new OSpLWriter();
						m_osplWriter.setRequestAction("notifyJobCompletion");
						m_osplWriter.setServiceURI(OSParameter.SERVICE_URI);
						m_osplWriter.setServiceName(OSParameter.SERVICE_NAME);
						m_osplWriter.setProcessTime(DateTime.Now);
						m_osplWriter.setProcessMessage(sMessage1);
						JobStatistics[] mJobStatistics = new JobStatistics[1];
						mJobStatistics[0] = (JobStatistics)m_jobStatisticsTable[m_sJobID];
						m_osplWriter.setJobStatistics(mJobStatistics);
						string sProcessInput = m_osplWriter.writeToString();

						m_osolWriter = new OSoLWriter();
						m_osolWriter.setServiceURI(OSParameter.SERVICE_URI);
						m_osolWriter.setServiceName(OSParameter.SERVICE_NAME);
						m_osolWriter.setJobID(m_sJobID);
						m_osolWriter.setLicense(m_sLicense);
						m_osolWriter.setUserName(m_sUserName);		
						m_osolWriter.setPassword(OSParameter.getSystemPassword());
						string sServiceType = (serviceType==null||serviceType.Length <= 0)?"solver":serviceType;
						m_osolWriter.setServiceType(sServiceType);
						string sOption = m_osolWriter.writeToString();
					
						if(m_sContactAddress != null && m_sContactAddress.Length > 0 && m_sContactTransportType.Equals("osp")){
							if(!(serviceType.Equals("scheduler") && m_sContactAddress.Equals(OSParameter.OS_SCHEDULER_SITE))){
								KnockSolverThread knockSolverThread1 = new KnockSolverThread();
								OSSolverAgent osSolverAgent1 = new OSSolverAgent(m_sContactAddress);
								knockSolverThread1.m_osSolverAgent = osSolverAgent1;
								knockSolverThread1.m_osplInput = sProcessInput;
								knockSolverThread1.m_osol = sOption;
										
								Thread thread1 = new Thread(new ThreadStart(knockSolverThread1.knock));	
								thread1.Start();
							}
						}
						if(((m_sContactAddress == null || m_sContactAddress.Length <= 0) || 
							(m_sContactAddress != null && !m_sContactAddress.Equals(OSParameter.OS_SCHEDULER_SITE))) &&
							(m_sServiceTypeInOSoL != null && m_sServiceTypeInOSoL.Equals("scheduler"))){
							if(!serviceType.Equals("scheduler")){
								KnockSolverThread knockSolverThread2 = new KnockSolverThread();
								OSSolverAgent osSolverAgent2 = new OSSolverAgent(OSParameter.OS_SCHEDULER_SITE);
								knockSolverThread2.m_osSolverAgent = osSolverAgent2;
								knockSolverThread2.m_osplInput = sProcessInput;
								knockSolverThread2.m_osol = sOption;
						
								Thread thread2 = new Thread(new ThreadStart(knockSolverThread2.knock));	
								thread2.Start();		
							}
						}

					}	
					return true;
				} 
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
					return false;
				}		
			}
			return true;
		}//contactSender
		
		/// <summary>
		/// request job at scheduler
		/// </summary>
		/// <returns>if the job request is successful.</returns>
		protected internal bool requestJob(){
			if((m_sCurrentState.Equals("busyButAccepting") || m_sCurrentState.Equals("idle")) && 
				(serviceType == null || serviceType.Length <= 0 || serviceType.Equals("solver") || serviceType.Equals("analyzer"))){
				try {
					string sMessage = "The current state of the service (" + (OSParameter.SERVICE_URI) + ") is: " + m_sCurrentState;
					m_osplWriter = new OSpLWriter();
					m_osplWriter.setRequestAction("requestJob");
					m_osplWriter.setServiceURI(OSParameter.SERVICE_URI);
					m_osplWriter.setServiceName(OSParameter.SERVICE_NAME);
					m_osplWriter.setProcessTime(DateTime.Now);
					m_osplWriter.setProcessMessage(sMessage);
					string sProcessInput = m_osplWriter.writeToString();
				
					m_osolWriter = new OSoLWriter();
					m_osolWriter.setServiceURI(OSParameter.SERVICE_URI);
					m_osolWriter.setServiceName(OSParameter.SERVICE_NAME);
					m_osolWriter.setJobID(m_sJobID);
					m_osolWriter.setLicense(m_sLicense);
					m_osolWriter.setUserName(m_sUserName);		
					m_osolWriter.setPassword(OSParameter.getSystemPassword());						
					string sServiceType = (serviceType==null||serviceType.Length <= 0)?"solver":serviceType;
					m_osolWriter.setServiceType(sServiceType);
					String sOption = m_osolWriter.writeToString();
				
					KnockSolverThread knockSolverThread = new KnockSolverThread();
					OSSolverAgent osSolverAgent = new OSSolverAgent(OSParameter.OS_SCHEDULER_SITE);
					knockSolverThread.m_osSolverAgent = osSolverAgent;
					knockSolverThread.m_osplInput = sProcessInput;
					knockSolverThread.m_osol = sOption;
									
					Thread thread = new Thread(new ThreadStart(knockSolverThread.knock));	
					thread.Start();
					return true;
				} 
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
					return false;
				}
			}
			return true;
		}//requestJob


		/// <summary>
		/// presolve handles prerequisites before invoking the solve method.
		/// </summary>
		/// <param name="osil">holds the instance in a string which format follows OSiL schema.</param>
		/// <param name="osol">holds the option in a string which format follows OSoL schema.</param>
		/// <returns>whether the presolve is successful. </returns>
		protected internal bool presolve(string osil, string osol){
			if(osil == null) osil = "";
			if(osol == null) osol = "";

			//from OSParameter
			if(OSParameter.DIRECTORIES_TO_MAKE !=null && OSParameter.DIRECTORIES_TO_MAKE.Length > 0){
				for(int i = 0; i < OSParameter.DIRECTORIES_TO_MAKE.Length; i++){
					bool bSuccess = IOUtil.makeDir(OSParameter.DIRECTORIES_TO_MAKE[i]);
					if(! bSuccess){
						IOUtil.log("not able to make dir " + OSParameter.DIRECTORIES_TO_MAKE[i], null);	
					}
				}
			}
			if(OSParameter.FILES_TO_CREATE !=null && OSParameter.FILES_TO_CREATE.Length > 0){
				for(int i = 0; i < OSParameter.FILES_TO_CREATE.Length; i++){
					bool bSuccess = IOUtil.createFile(OSParameter.FILES_TO_CREATE[i]);
					if(! bSuccess){
						IOUtil.log("not able to create file " + OSParameter.FILES_TO_CREATE[i], null);	
					}
				}
			}
			if(OSParameter.SAVE_INPUTS){
				string sInstanceFile = OSParameter.TEMP_FILE_FOLDER+m_sJobID+".osil";
				string sOptionFile = OSParameter.TEMP_FILE_FOLDER+m_sJobID+".osol";				
				bool bWrite = true;
				if(!IOUtil.existsFileOrDir(sInstanceFile)){
					bWrite = IOUtil.writeStringToFile(osil, sInstanceFile);
				}
				if(!bWrite){
					IOUtil.log("the solve method is not able to write osil to file", null);
					IOUtil.deleteFile(sInstanceFile);
				}
				bWrite = true;
				if(!IOUtil.existsFileOrDir(sOptionFile)){
					bWrite = IOUtil.writeStringToFile(osol, sOptionFile);
				}
				if(!bWrite){
					IOUtil.log("the solve method is not able to write osol to file", null);
					IOUtil.deleteFile(sOptionFile);
				}
			}
			if((OSParameter.INPUT_FILES_TO_COPY_FROM != null && OSParameter.INPUT_FILES_TO_COPY_FROM.Length > 0) ||
				(OSParameter.INPUT_FILES_TO_COPY_TO !=null && OSParameter.INPUT_FILES_TO_COPY_TO.Length > 0)){
				int m = OSParameter.INPUT_FILES_TO_COPY_FROM==null?0:OSParameter.INPUT_FILES_TO_COPY_FROM.Length;
				int n = OSParameter.INPUT_FILES_TO_COPY_TO==null?0:OSParameter.INPUT_FILES_TO_COPY_TO.Length;
				if(m != n){
					IOUtil.log("number of INPUT_FILES_TO_COPY_FROM not equal to number of INPUT_FILES_TO_COPY_TO", null);
				}
				else{
					for(int i = 0; i < m; i++){
						bool bSuccess  = IOUtil.copyFile(OSParameter.INPUT_FILES_TO_COPY_FROM[i], OSParameter.INPUT_FILES_TO_COPY_TO[i]);
						if(! bSuccess){
							IOUtil.log("not able to copy file from " + OSParameter.INPUT_FILES_TO_COPY_FROM[i] + " to " +  OSParameter.INPUT_FILES_TO_COPY_TO[i], null);	
						}
					}
				}
			}
			if((OSParameter.INPUT_FILES_TO_MOVE_FROM != null && OSParameter.INPUT_FILES_TO_MOVE_FROM.Length > 0) ||
				(OSParameter.INPUT_FILES_TO_MOVE_TO !=null && OSParameter.INPUT_FILES_TO_MOVE_TO.Length > 0)){
				int m = OSParameter.INPUT_FILES_TO_MOVE_FROM==null?0:OSParameter.INPUT_FILES_TO_MOVE_FROM.Length;
				int n = OSParameter.INPUT_FILES_TO_MOVE_TO==null?0:OSParameter.INPUT_FILES_TO_MOVE_TO.Length;
				if(m != n){
					IOUtil.log("number of INPUT_FILES_TO_MOVE_FROM not equal to number of INPUT_FILES_TO_MOVE_TO", null);
				}
				else{
					for(int i = 0; i < m; i++){
						bool bSuccess  = IOUtil.moveFile(OSParameter.INPUT_FILES_TO_MOVE_FROM[i], OSParameter.INPUT_FILES_TO_MOVE_TO[i]);
						if(! bSuccess){
							IOUtil.log("not able to move file from " + OSParameter.INPUT_FILES_TO_MOVE_FROM[i] + " to " +  OSParameter.INPUT_FILES_TO_MOVE_TO[i], null);	
						}
					}
				}
			}
			
			//from OSoL
			if(OSParameter.ALLOW_IO_OPERATIONS_BY_USERS){
				string[] msDirectoriesToMake = m_osOption.getDirectoriesToMake();
				if(msDirectoriesToMake !=null && msDirectoriesToMake.Length > 0){
					for(int i = 0; i < msDirectoriesToMake.Length; i++){
						bool bSuccess = IOUtil.makeDir(msDirectoriesToMake[i]);
						if(! bSuccess){
							IOUtil.log("not able to make dir " + msDirectoriesToMake[i], null);	
						}
					}
				}
				string[] msFilesToCreate = m_osOption.getFilesToCreate();
				if(msFilesToCreate !=null && msFilesToCreate.Length > 0){
					for(int i = 0; i < msFilesToCreate.Length; i++){
						bool bSuccess = IOUtil.createFile(msFilesToCreate[i]);
						if(! bSuccess){
							IOUtil.log("not able to create file " + msFilesToCreate[i], null);	
						}
					}
				}
				string[] msInputFilesToCopyFrom = m_osOption.getInputFilesToCopyFrom();
				string[] msInputFilesToCopyTo = m_osOption.getInputFilesToCopyTo();
				if((msInputFilesToCopyFrom != null && msInputFilesToCopyFrom.Length > 0) ||
					(msInputFilesToCopyTo !=null && msInputFilesToCopyTo.Length > 0)){
					int m = msInputFilesToCopyFrom==null?0:msInputFilesToCopyFrom.Length;
					int n = msInputFilesToCopyTo==null?0:msInputFilesToCopyTo.Length;
					if(m != n){
						IOUtil.log("number of INPUT_FILES_TO_COPY_FROM not equal to number of INPUT_FILES_TO_COPY_TO", null);
					}
					else{
						for(int i = 0; i < m; i++){
							bool bSuccess  = IOUtil.copyFile(msInputFilesToCopyFrom[i], msInputFilesToCopyTo[i]);
							if(! bSuccess){
								IOUtil.log("not able to copy file from " + msInputFilesToCopyFrom[i] + " to " +  msInputFilesToCopyTo[i], null);	
							}
						}
					}
				}
				string[] msInputFilesToMoveFrom = m_osOption.getInputFilesToMoveFrom();
				string[] msInputFilesToMoveTo = m_osOption.getInputFilesToMoveTo();
				if((msInputFilesToMoveFrom != null && msInputFilesToMoveFrom.Length > 0) ||
					(msInputFilesToMoveTo !=null && msInputFilesToMoveTo.Length > 0)){
					int m = msInputFilesToMoveFrom==null?0:msInputFilesToMoveFrom.Length;
					int n = msInputFilesToMoveTo==null?0:msInputFilesToMoveTo.Length;
					if(m != n){
						IOUtil.log("number of INPUT_FILES_TO_MOVE_FROM not equal to number of INPUT_FILES_TO_MOVE_TO", null);
					}
					else{
						for(int i = 0; i < m; i++){
							bool bSuccess  = IOUtil.moveFile(msInputFilesToMoveFrom[i], msInputFilesToMoveTo[i]);
							if(! bSuccess){
								IOUtil.log("not able to move file from " + msInputFilesToMoveFrom[i] + " to " +  msInputFilesToMoveTo[i], null);	
							}
						}
					}
				}				
			}
			return true;
		}//presolve

		/// <summary>
		/// postsolve handles works after invoking the solve method.
		/// </summary>
		/// <returns>whether the postsolve is successful. </returns>
		protected internal bool postsolve(){
			m_iCurrentJobCount = m_vCurrentJobIDs.Count;
			if(m_iCurrentJobCount <= 1){
				if((OSParameter.OUTPUT_FILES_TO_COPY_FROM != null && OSParameter.OUTPUT_FILES_TO_COPY_FROM.Length > 0) ||
					(OSParameter.OUTPUT_FILES_TO_COPY_TO !=null && OSParameter.OUTPUT_FILES_TO_COPY_TO.Length > 0)){
					int m = OSParameter.OUTPUT_FILES_TO_COPY_FROM==null?0:OSParameter.OUTPUT_FILES_TO_COPY_FROM.Length;
					int n = OSParameter.OUTPUT_FILES_TO_COPY_TO==null?0:OSParameter.OUTPUT_FILES_TO_COPY_TO.Length;
					if(m != n){
						IOUtil.log("number of OUTPUT_FILES_TO_COPY_FROM not equal to number of OUTPUT_FILES_TO_COPY_TO", null);
					}
					else{
						for(int i = 0; i < m; i++){
							bool bSuccess  = IOUtil.copyFile(OSParameter.OUTPUT_FILES_TO_COPY_FROM[i], OSParameter.OUTPUT_FILES_TO_COPY_TO[i]);
							if(! bSuccess){
								IOUtil.log("not able to copy file from " + OSParameter.OUTPUT_FILES_TO_COPY_FROM[i] + " to " +  OSParameter.OUTPUT_FILES_TO_COPY_TO[i], null);	
							}
						}
					}
				}
				if((OSParameter.OUTPUT_FILES_TO_MOVE_FROM != null && OSParameter.OUTPUT_FILES_TO_MOVE_FROM.Length > 0) ||
					(OSParameter.OUTPUT_FILES_TO_MOVE_TO !=null && OSParameter.OUTPUT_FILES_TO_MOVE_TO.Length > 0)){
					int m = OSParameter.OUTPUT_FILES_TO_MOVE_FROM==null?0:OSParameter.OUTPUT_FILES_TO_MOVE_FROM.Length;
					int n = OSParameter.OUTPUT_FILES_TO_MOVE_TO==null?0:OSParameter.OUTPUT_FILES_TO_MOVE_TO.Length;
					if(m != n){
						IOUtil.log("number of OUTPUT_FILES_TO_MOVE_FROM not equal to number of OUTPUT_FILES_TO_MOVE_TO", null);
					}
					else{
						for(int i = 0; i < m; i++){
							bool bSuccess  = IOUtil.moveFile(OSParameter.OUTPUT_FILES_TO_MOVE_FROM[i], OSParameter.OUTPUT_FILES_TO_MOVE_TO[i]);
							if(! bSuccess){
								IOUtil.log("not able to move file from " + OSParameter.OUTPUT_FILES_TO_MOVE_FROM[i] + " to " +  OSParameter.OUTPUT_FILES_TO_MOVE_TO[i], null);	
							}
						}
					}
				}
				if(OSParameter.FILES_TO_DELETE !=null && OSParameter.FILES_TO_DELETE.Length > 0){
					for(int i = 0; i < OSParameter.FILES_TO_DELETE.Length; i++){
						bool bSuccess = IOUtil.deleteFile(OSParameter.FILES_TO_DELETE[i]);
						if(! bSuccess){
							IOUtil.log("not able to delete file " + OSParameter.FILES_TO_DELETE[i], null);	
						}
					}
				}
				if(OSParameter.DIRECTORIES_TO_DELETE !=null && OSParameter.DIRECTORIES_TO_DELETE.Length > 0){
					for(int i = 0; i < OSParameter.DIRECTORIES_TO_DELETE.Length; i++){
						bool bSuccess = IOUtil.deleteDir(OSParameter.DIRECTORIES_TO_DELETE[i]);
						if(! bSuccess){
							IOUtil.log("not able to delete dir " + OSParameter.DIRECTORIES_TO_DELETE[i], null);	
						}
					}
				}

				if(OSParameter.PROCESSES_TO_KILL != null && OSParameter.PROCESSES_TO_KILL.Length > 0){
					for(int i = 0; i < OSParameter.PROCESSES_TO_KILL.Length; i++){
						bool bSuccess = ProcessUtil.killProcessByName(OSParameter.PROCESSES_TO_KILL[i]);
						if(!bSuccess){
							IOUtil.log("not able to kill process " + OSParameter.PROCESSES_TO_KILL[i], null);
						}
					}
				}
			}
			//from osol
			if(OSParameter.ALLOW_IO_OPERATIONS_BY_USERS){
				string[] msOutputFilesToCopyFrom = m_osOption.getOutputFilesToCopyFrom();
				string[] msOutputFilesToCopyTo = m_osOption.getOutputFilesToCopyTo();
				if((msOutputFilesToCopyFrom != null && msOutputFilesToCopyFrom.Length > 0) ||
					(msOutputFilesToCopyTo !=null && msOutputFilesToCopyTo.Length > 0)){
					int m = msOutputFilesToCopyFrom==null?0:msOutputFilesToCopyFrom.Length;
					int n = msOutputFilesToCopyTo==null?0:msOutputFilesToCopyTo.Length;
					if(m != n){
						IOUtil.log("number of OUTPUT_FILES_TO_COPY_FROM not equal to number of OUTPUT_FILES_TO_COPY_TO", null);
					}
					else{
						for(int i = 0; i < m; i++){
							bool bSuccess  = IOUtil.copyFile(msOutputFilesToCopyFrom[i], msOutputFilesToCopyTo[i]);
							if(! bSuccess){
								IOUtil.log("not able to copy file from " + msOutputFilesToCopyFrom[i] + " to " +  msOutputFilesToCopyTo[i], null);	
							}
						}
					}
				}
				string[] msOutputFilesToMoveFrom = m_osOption.getOutputFilesToMoveFrom();
				string[] msOutputFilesToMoveTo = m_osOption.getOutputFilesToMoveTo();
				if((msOutputFilesToMoveFrom != null && msOutputFilesToMoveFrom.Length > 0) ||
					(msOutputFilesToMoveTo !=null && msOutputFilesToMoveTo.Length > 0)){
					int m = msOutputFilesToMoveFrom==null?0:msOutputFilesToMoveFrom.Length;
					int n = msOutputFilesToMoveTo==null?0:msOutputFilesToMoveTo.Length;
					if(m != n){
						IOUtil.log("number of OUTPUT_FILES_TO_MOVE_FROM not equal to number of OUTPUT_FILES_TO_MOVE_TO", null);
					}
					else{
						for(int i = 0; i < m; i++){
							bool bSuccess  = IOUtil.moveFile(msOutputFilesToMoveFrom[i], msOutputFilesToMoveTo[i]);
							if(! bSuccess){
								IOUtil.log("not able to move file from " + msOutputFilesToMoveFrom[i] + " to " +  msOutputFilesToMoveTo[i], null);	
							}
						}
					}
				}

				string[] msFilesToDelete = m_osOption.getFilesToDelete();
				if(msFilesToDelete !=null && msFilesToDelete.Length > 0){
					for(int i = 0; i < msFilesToDelete.Length; i++){
						bool bSuccess = IOUtil.deleteFile(msFilesToDelete[i]);
						if(! bSuccess){
							IOUtil.log("not able to delete file " + msFilesToDelete[i], null);	
						}
					}
				}
				string[] msDirectoriesToDelete = m_osOption.getDirectoriesToDelete();
				if(msDirectoriesToDelete !=null && msDirectoriesToDelete.Length > 0){
					for(int i = 0; i < msDirectoriesToDelete.Length; i++){
						bool bSuccess = IOUtil.deleteDir(msDirectoriesToDelete[i]);
						if(! bSuccess){
							IOUtil.log("not able to delete dir " + msDirectoriesToDelete[i], null);	
						}
					}
				}
				string[] msProcessesToKill = m_osOption.getProcessesToKill();
				if(msProcessesToKill != null && msProcessesToKill.Length > 0){
					for(int i = 0; i < msProcessesToKill.Length; i++){
						bool bSuccess = ProcessUtil.killProcessByName(msProcessesToKill[i]);
						if(!bSuccess){
							IOUtil.log("not able to kill process " + msProcessesToKill[i], null);
						}
					}
				}
			}
			return true;
		}//postsolve

		/// <summary>
		/// Call a solver or analyzer service whose input is given by a string following 
		/// the OSiL schema and returns the result in a string that follows 
		/// OSrL schema. 
		/// </summary>
		/// <param name="osil">holds the instance in a string which format follows OSiL schema.</param>
		/// <param name="osol">holds the option in a string which format follows OSoL schema.</param>
		/// <returns>osrl, the result in a string which format follows the OSrL schema.</returns>
		[System.Web.Services.WebMethodAttribute()]
		[System.Web.Services.Protocols.SoapRpcMethodAttribute("OSSolverService#solve", 
			 RequestNamespace="http://www.optimizationservices.org", 
			 ResponseNamespace="http://www.optimizationservices.org")]
		[return: System.Xml.Serialization.SoapElementAttribute("osrl")]		
		public string solve(string osil, string osol){
			if(osil == null) osil = "";
			if(osol == null) osol = "";
			string sOSrL = "";
			m_osrlWriter = new OSrLWriter();
			m_osrlWriter.setServiceURI(OSParameter.SERVICE_URI);
			m_osrlWriter.setServiceName(OSParameter.SERVICE_NAME);
			m_osrlWriter.setResultTime(DateTime.Now);

			//read osol
			if(osol != null && osol.Length > 0){
				if(!readOSoL(osol)){
					m_osrlWriter.setGeneralStatusType("error");
					m_osrlWriter.setGeneralStatusDescription("Invalid OSoL option");
					sOSrL = m_osrlWriter.writeToString();
					return sOSrL;
				}
			}
			if(m_osOption == null) m_osOption = new OSOption();

			//check permission
			try {
				if(!checkPermision()){
					m_osrlWriter.setGeneralStatusType("error");
					m_osrlWriter.setGeneralStatusDescription("Permission error.");
					sOSrL = m_osrlWriter.writeToString();
					return sOSrL;
				}
			} 
			catch (Exception e) {
				IOUtil.log(e.Message, null);
				m_osrlWriter.setGeneralStatusType("error");
				m_osrlWriter.setGeneralStatusDescription(e.Message);
				sOSrL = m_osrlWriter.writeToString();
				return sOSrL;
			}

			//if no jobID exists, automatically create one and establish job statistics 
			if(m_sJobID == null || m_sJobID.Length <= 0 ){
				m_sJobID = "AUTOJOBID_" + CommonUtil.getJobID(null);
				m_osOption.setJobID(m_sJobID);
			}
			m_osrlWriter.setJobID(m_sJobID);
			string sTime = XMLUtil.createXSDateTime(DateTime.Now);
			IOUtil.log("job ID: "+m_sJobID+":" + sTime, null);

			//see if the job is resubmit
			JobStatistics jobStatistics = (JobStatistics)m_jobStatisticsTable[m_sJobID];
			if(jobStatistics != null){
				if(jobStatistics.state.Equals("finished") ){
					m_osrlWriter.setGeneralStatusType("error");
					m_osrlWriter.setGeneralStatusDescription("Job " + m_sJobID + " is alreday finished. Cannot submit again. ");
					sOSrL = m_osrlWriter.writeToString();
					return sOSrL;
				}
				else if(jobStatistics.state.Equals("killed") ){
					m_osrlWriter.setGeneralStatusType("error");
					m_osrlWriter.setGeneralStatusDescription("Job " + m_sJobID + " is alreday killed. Cannot submit again. ");
					sOSrL = m_osrlWriter.writeToString();
					return sOSrL;
				}
				else if(jobStatistics.state.Equals("running") ){
					m_osrlWriter.setGeneralStatusType("error");
					m_osrlWriter.setGeneralStatusDescription("Job " + m_sJobID + " is alreday running. Cannot submit again. ");
					sOSrL = m_osrlWriter.writeToString();
					return sOSrL;
				}
			}

			//check system requirement
			try {
				if(!checkSystemRequirement()) {
					m_osrlWriter.setGeneralStatusType("warning");
					m_osrlWriter.setGeneralStatusDescription("System warning: system requirement not met.");
					sOSrL = m_osrlWriter.writeToString();
					return sOSrL;
				}
			} 
			catch (Exception e) {
				IOUtil.log(e.Message, null);
				m_osrlWriter.setGeneralStatusType("warning");
				m_osrlWriter.setGeneralStatusDescription(e.Message);
				sOSrL = m_osrlWriter.writeToString();
				return sOSrL;
			}

			string osol2 = osol; 
			try {
				osol2 = m_osOption.writeOSoL();
			} 
			catch (Exception e) {
				IOUtil.log(e.ToString(), null);
				m_osrlWriter.setGeneralStatusType("error");
				m_osrlWriter.setGeneralStatusDescription(e.Message);
				m_osrlWriter.setGeneralMessage(e.ToString());
				sOSrL = m_osrlWriter.writeToString();
				return sOSrL;
			}

			//check waiting: scheduleTime, jobdependencies, required files/directories, solver availability
			if(m_solverThread == null){
				m_solverThread = new SolverThread();	
			}	
			if((m_sServiceTypeInOSoL != null && !m_sServiceTypeInOSoL.Equals("scheduler")) || m_sServiceTypeInOSoL == null || 
				(serviceType != null && serviceType.Equals("scheduler"))){
				try {
					if(checkWaiting(osil, osol2, serviceType.Equals("scheduler"), false)){
						m_osrlWriter.setGeneralStatusType("warning");
						m_osrlWriter.setGeneralStatusDescription("System warning: no waiting allowed for the solve method. Please call send.");
						sOSrL = m_osrlWriter.writeToString();
						return sOSrL;
					}			
				} 
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
					m_osrlWriter.setGeneralStatusType("warning");
					m_osrlWriter.setGeneralStatusDescription(e.Message);
					m_osrlWriter.setGeneralMessage(e.ToString());
					sOSrL = m_osrlWriter.writeToString();
					return sOSrL;			
				}
			}

			//initializeStatistics
			initializeStatistics();

			//launch solver thread
			try{
				m_solverThread.m_sOSiL = osil;
				m_solverThread.m_sOSoL = osol2;
				m_solverThread.m_osOption = m_osOption;
				m_solverThread.m_bCalledFromSend = false;
				m_solverThread.m_osServiceUtil = this;

				m_osrlWriter.setGeneralStatusType("warning");
				m_osrlWriter.setGeneralStatusDescription("No result returned or no result yet.");
				m_solverThread.m_sOSrL = m_osrlWriter.writeToString();

				Thread thread = new Thread(new ThreadStart(m_solverThread.solve));
				thread.Name = m_sJobID;		
				
				m_solverThreadHashTable.Remove(m_sJobID);
				m_solverThreadHashTable.Add(m_sJobID, m_solverThread);
				m_threadHashTable.Remove(m_sJobID);
				m_threadHashTable.Add(m_sJobID, thread);

				thread.Start();

				int iHour = (int)m_dJobMaxTime/3600;
				int iMin = (int)(m_dJobMaxTime-iHour*3600)/60;
				int iSec = (int)m_dJobMaxTime%60;
				TimeSpan timeSpan = new TimeSpan(iHour, iMin, iSec);
				thread.Join(timeSpan);
				if(!m_vFinishedJobIDs.Contains(m_sJobID)){
					kill(osol2);
					m_osrlWriter.setGeneralStatusType("warning");
					m_osrlWriter.setGeneralStatusDescription("maximum job time reached");
					sOSrL = m_osrlWriter.writeToString();
				}
				else{
					sOSrL = m_solverThread.m_sOSrL;	
				}
			}
			catch(Exception e){
				string sResult = "";
				IOUtil.log(e.ToString(), null);
				string sResultFile = OSParameter.TEMP_FILE_FOLDER+m_sJobID+".osrl";
				bool bWriteResult = false;
				if(!IOUtil.existsFileOrDir(sResultFile)) bWriteResult = true;
				else{
					sResult = IOUtil.readStringFromFile(sResultFile);
					if(sResult == null || sResult.Length <= 0){
						sResult = "";
						bWriteResult = true;
					}
					else{
						OSrLReader osrlReader = new OSrLReader();
						try {
							bool bRead = osrlReader.readString(sResult);
							if(!bRead) throw new Exception("Invalid OSrL result");
							string sStatus = osrlReader.getGeneralStatusType();
							if(sStatus == null || !sStatus.Equals("success")){
								bWriteResult = true;
							}
							else{
								bWriteResult = false;
							}
						}
						catch (Exception e1) {
							IOUtil.log(e1.ToString(), null);
							bWriteResult = true;
						}
					}
				}
				if(bWriteResult){
					m_osrlWriter.setGeneralStatusType("error");
					m_osrlWriter.setGeneralStatusDescription(e.Message);
					m_osrlWriter.setGeneralMessage(e.ToString());
					sOSrL = m_osrlWriter.writeToString();
					IOUtil.writeStringToFile(sOSrL, sResultFile);	
				}
				else{
					sOSrL = sResult;
				}
				try {
					postprocess(false);				
				} 
				catch (Exception e2) {
					IOUtil.log(e2.ToString(), null);
				}
			}
			if(sOSrL == null || sOSrL.Length <= 0){
				m_osrlWriter.setGeneralStatusType("warning");
				m_osrlWriter.setGeneralStatusDescription("No result");
				sOSrL = m_osrlWriter.writeToString();			
			}
			return sOSrL;
		}//solve
    
		/// <summary>
		/// Send (or asynchronously solve) an instance to a solver, analyzer or scheduler service
		/// whose input is given by a string following the OSiL schema and returns the result 
		/// in a string that follows OSrL schema. 
		/// </summary>
		/// <param name="osil">holds the instance in a string which format follows OSiL schema.</param>
		/// <param name="osol">holds the option in a string which format follows OSoL schema. 
		/// It should contain the jobID information that is previous obtained from the service.</param>
		/// <returns>success, whether the asynchronous communication is successful or not.</returns>
		[System.Web.Services.WebMethodAttribute()]
		[System.Web.Services.Protocols.SoapRpcMethodAttribute("OSSolverService#send", 
			 RequestNamespace="http://www.optimizationservices.org", 
			 ResponseNamespace="http://www.optimizationservices.org")]
		[return: System.Xml.Serialization.SoapElementAttribute("success")]
		public bool send(string osil, string osol){
			if(osil == null) osil = "";
			if(osol == null) osol = "";
			m_osrlWriter = new OSrLWriter();

			//read osol
			if(osol == null || osol.Length <= 0){
				IOUtil.log("Empty string for the send method", null);
				return false;
			}
			if(!readOSoL(osol)) return false;	
			if(m_osOption == null) m_osOption = new OSOption();

			//check permission
			try {
				if(!checkPermision()) return false;
			} 
			catch (Exception e) {
				IOUtil.log(e.Message, null);
				return false;
			}

			//check if jobID exists 
			if(m_sJobID == null || m_sJobID.Length <= 0 ){
				IOUtil.log("No jobID in OSoL", null);
				return false;
			}
			string sTime = XMLUtil.createXSDateTime(DateTime.Now);
			IOUtil.log("job ID: "+m_sJobID+":" + sTime, null);

			//see if the job is resubmit
			JobStatistics jobStatistics = (JobStatistics)m_jobStatisticsTable[m_sJobID];
			if(jobStatistics != null){
				if(jobStatistics.state.Equals("finished") ){
					IOUtil.log("Job " + m_sJobID + " is alreday finished. Cannot submit again. ", null);
					return false;
				}
				else if(jobStatistics.state.Equals("killed") ){
					IOUtil.log("Job " + m_sJobID + " is alreday killed. Cannot submit again. ", null);
					return false;
				}
				else if(jobStatistics.state.Equals("running") ){
					IOUtil.log("Job " + m_sJobID + " is alreday running. Cannot submit again. ", null);
					return false;
				}
			}

			//check system requirement
			try {
				if(!checkSystemRequirement()) return false;
			} 
			catch (Exception e) {
				IOUtil.log(e.Message, null);
				return false;
			}

			//initializeStatistics
			initializeStatistics();

			if(m_solverThread == null){
				m_solverThread = new SolverThread();	
			}	

			string osol2 = osol; 
			try {
				osol2 = m_osOption.writeOSoL();
			} 
			catch (Exception e) {
				IOUtil.log(e.ToString(), null);
				return false;
			}

			//check waiting: scheduleTime, jobdependencies, required files/directories, solver availability
			if((m_sServiceTypeInOSoL != null && !m_sServiceTypeInOSoL.Equals("scheduler")) || m_sServiceTypeInOSoL == null ||
				(serviceType != null && serviceType.Equals("scheduler"))){
				try {
					if(checkWaiting(osil, osol2, serviceType.Equals("scheduler"), true)) return true;			
				} 
				catch (Exception e) {
					IOUtil.log(e.Message, null);
					return false;
				}
			}

			//launch thread
			try{
				m_solverThread.m_sOSiL = osil;
				m_solverThread.m_sOSoL = osol2;
				m_solverThread.m_osOption = m_osOption;
				m_solverThread.m_bCalledFromSend = true;
				m_solverThread.m_osServiceUtil = this;

				m_osrlWriter.setGeneralStatusType("warning");
				m_osrlWriter.setGeneralStatusDescription("No result returned or no result yet.");
				m_solverThread.m_sOSrL = m_osrlWriter.writeToString();

				Thread thread = new Thread(new ThreadStart(m_solverThread.solve));
				thread.Name = m_sJobID;	

				m_solverThreadHashTable.Remove(m_sJobID);
				m_solverThreadHashTable.Add(m_sJobID, m_solverThread);
				m_threadHashTable.Remove(m_sJobID);
				m_threadHashTable.Add(m_sJobID, thread);

				thread.Start();
			}
			catch(Exception e){
				string sResult = "";
				IOUtil.log(e.ToString(), null);
				string sResultFile = OSParameter.TEMP_FILE_FOLDER+m_sJobID+".osrl";
				bool bWriteResult = false;
				if(!IOUtil.existsFileOrDir(sResultFile)) bWriteResult = true;
				else{
					sResult = IOUtil.readStringFromFile(sResultFile);
					if(sResult == null || sResult.Length <= 0){
						sResult = "";
						bWriteResult = true;
					}
					else{
						OSrLReader osrlReader = new OSrLReader();
						try {
							bool bRead = osrlReader.readString(sResult);
							if(!bRead) throw new Exception("Invalid OSrL result");
							string sStatus = osrlReader.getGeneralStatusType();
							if(sStatus == null || !sStatus.Equals("success")){
								bWriteResult = true;
							}
							else{
								bWriteResult = false;
							}
						}
						catch (Exception e1) {
							IOUtil.log(e1.ToString(), null);
							bWriteResult = true;
						}
					}
				}

				if(bWriteResult){
					m_osrlWriter = new OSrLWriter();
					m_osrlWriter.setServiceURI(OSParameter.SERVICE_URI);
					m_osrlWriter.setServiceName(OSParameter.SERVICE_NAME);
					m_osrlWriter.setJobID(m_sJobID);
					m_osrlWriter.setResultTime(DateTime.Now);
					m_osrlWriter.setGeneralStatusType("error");
					m_osrlWriter.setGeneralStatusDescription(e.Message);
					m_osrlWriter.setGeneralMessage(e.ToString());
					string sOSrL = m_osrlWriter.writeToString();
					IOUtil.writeStringToFile(sOSrL, sResultFile);	
								
					try {
						postprocess(false);				
					} 
					catch (Exception e2) {
						IOUtil.log(e2.ToString(), null);
					}
					return false;			
				}
				else{
					postprocess(false);
					return true;
				}
			}
			return true;
		}//send
    
		/// <summary>
		/// Retrieve results from a previously sent/solved optimization job.  		
		/// </summary>
		/// <param name="osol">holds the option in a string which format follows OSoL schema
		/// It should contain the jobID information that is previous obtained from the service.</param>
		/// <returns>osrl, the result in a string which format follows the OSrL schema.  
		/// If the result cannot be retrieved, it should be indicated in 
		/// the message/status section of OSrL.</returns>
		[System.Web.Services.WebMethodAttribute()]
		[System.Web.Services.Protocols.SoapRpcMethodAttribute("OSSolverService#retrieve", 
			 RequestNamespace="http://www.optimizationservices.org", 
			 ResponseNamespace="http://www.optimizationservices.org")]
		[return: System.Xml.Serialization.SoapElementAttribute("osrl")]		
		public string retrieve(string osol){
			if(osol == null) osol = "";

			string sOSrL = "";
			m_osrlWriter = new OSrLWriter();
			m_osrlWriter.setServiceURI(OSParameter.SERVICE_URI);
			m_osrlWriter.setServiceName(OSParameter.SERVICE_NAME);
			m_osrlWriter.setResultTime(DateTime.Now);

			//read osol
			if(osol == null || osol.Length <= 0){
				m_osrlWriter.setGeneralStatusType("error");
				m_osrlWriter.setGeneralStatusDescription("No OSoL option specified");
				sOSrL = m_osrlWriter.writeToString();
				return sOSrL;	
			}
			if(!readOSoL(osol)){
				m_osrlWriter.setGeneralStatusType("error");
				m_osrlWriter.setGeneralStatusDescription("Invalid OSoL option");
				sOSrL = m_osrlWriter.writeToString();
				return sOSrL;
			}
			if(m_osOption == null) m_osOption = new OSOption();

			//check permission
			if(!OSParameter.REQUIRE_ONLY_JOB_ID_TO_RETRIEVE_JOB_RESULT){
				try {
					if(!checkPermision()){
						m_osrlWriter.setGeneralStatusType("error");
						m_osrlWriter.setGeneralStatusDescription("Permission error.");
						sOSrL = m_osrlWriter.writeToString();
						return sOSrL;
					}
				} 
				catch (Exception e) {
					IOUtil.log(e.Message, null);
					m_osrlWriter.setGeneralStatusType("error");
					m_osrlWriter.setGeneralStatusDescription(e.Message);
					sOSrL = m_osrlWriter.writeToString();
					return sOSrL;
				}
			}	

			//check jobID
			if(m_sJobID == null || m_sJobID.Length <= 0 ){
				m_osrlWriter.setGeneralStatusType("error");
				m_osrlWriter.setGeneralStatusDescription("no job id found");
				sOSrL = m_osrlWriter.writeToString();
				return sOSrL;
			}
			m_osrlWriter.setJobID(m_sJobID);


			//retrieve
			try {
				sOSrL = IOUtil.readStringFromFile(OSParameter.TEMP_FILE_FOLDER+m_sJobID+".osrl");
				if(sOSrL == null){
					sOSrL = "";
				}
			} 
			catch (Exception) {
			}

			//check if there is the job
			JobStatistics jobStatistics =  (JobStatistics)m_jobStatisticsTable[m_sJobID];
			if(jobStatistics == null && (sOSrL == null || sOSrL.Length <= 0)){
				m_osrlWriter.setGeneralStatusType("warning");
				m_osrlWriter.setGeneralStatusDescription( m_sJobID+" is not found");
				sOSrL = m_osrlWriter.writeToString();
				return sOSrL;
			}

			if(sOSrL == null || sOSrL.Length <= 0){
				bool bWarning = true;
				if(serviceType.Equals("scheduler")){
					try {
						OSSolverAgent solverAgent = new OSSolverAgent();
						solverAgent.solverAddress = jobStatistics.serviceURI; 
						if(solverAgent.solverAddress != null && solverAgent.solverAddress.Length > 0 
							&& !solverAgent.solverAddress.Equals(OSParameter.OS_SCHEDULER_SITE) && 
							!solverAgent.solverAddress.Equals(OSParameter.SERVICE_URI)){
							sOSrL = solverAgent.retrieve(osol);
							if(sOSrL != null && sOSrL.Length > 0){
								try{
									OSrLReader osrlReader = new OSrLReader();
									bool bRead = osrlReader.readString(sOSrL);
									if(!bRead) throw new Exception("Invalid OSrL result");
									bWarning = false;
									string sStatus = osrlReader.getGeneralStatusType();
									if(sStatus != null && sStatus.Equals("success") || sStatus.Equals("error")){
										string sResultFile = OSParameter.TEMP_FILE_FOLDER+m_sJobID+".osrl";
										bool bWrite = IOUtil.writeStringToFile(sOSrL, sResultFile);										
										if(!bWrite){
											IOUtil.log("result file not written successfully", null);
										}
									}
								}
								catch (Exception e) {
									IOUtil.log(e.ToString(), null);
								}
							}
							else{
								throw new Exception("no result found");
							}
						}
						else{
							throw new Exception("cannot find the right service address to retrieve the job");
						}
					} 
					catch (Exception e) {
						IOUtil.log(e.ToString(), null);
					}
				}
				if(bWarning){
					m_osrlWriter.setGeneralStatusType("warning");
					m_osrlWriter.setGeneralStatusDescription("no result found");
					sOSrL = m_osrlWriter.writeToString();
					return sOSrL;
				}
			}

			if(m_vFinishedJobIDs.Contains(m_sJobID)) return sOSrL;

			Thread thread = (Thread)m_threadHashTable[m_sJobID];
			if(thread != null){
				try{
					thread.Abort();
				}
				catch(Exception e){
					IOUtil.log(e.ToString(), null);
				}
			}

			jobStatistics  = (JobStatistics)m_jobStatisticsTable[m_sJobID];
			if(jobStatistics == null){
				jobStatistics = new JobStatistics();						
				jobStatistics.jobID = m_sJobID;
				m_jobStatisticsTable.Add(m_sJobID, jobStatistics);
			}

			if(jobStatistics.userName == null || jobStatistics.userName.Length <= 0){
				jobStatistics.userName = m_sUserName;
			}

			string sUserName = jobStatistics.userName;
			if(sUserName == null) sUserName = "";
			string sCount = (string)m_userJobCountTable[sUserName];
			int iCount;
			if(sCount == null || sCount.Length <= 0){
				iCount = 0;
			}
			else{
				try {
					iCount = Int32.Parse(sCount);
				} 
				catch (Exception) {
					iCount = 0;
				}
				if(iCount <= 0){
					iCount = 0;
				}
				else if(m_vWaitingJobIDs.Contains(m_sJobID) || m_vCurrentJobIDs.Contains(m_sJobID)){
					iCount -= 1;
				}
			}
			m_userJobCountTable.Remove(sUserName);
			m_userJobCountTable.Add(sUserName, iCount+"");	


			m_solverThreadHashTable.Remove(m_sJobID);
			m_threadHashTable.Remove(m_sJobID);
			m_vCurrentJobIDs.Remove(m_sJobID);
			m_vWaitingJobIDs.Remove(m_sJobID);
			m_vFinishedJobIDs.Remove(m_sJobID);
			m_vFinishedJobIDs.Add(m_sJobID);
			m_iCurrentJobCount = m_vCurrentJobIDs.Count;

			if(jobStatistics.jobID == null || jobStatistics.jobID.Length <= 0){
				jobStatistics.jobID = m_sJobID;
			}
			if((jobStatistics.serviceURI == null ||  jobStatistics.serviceURI.Length <= 0) && !serviceType.Equals("scheduler")){
				jobStatistics.serviceURI = (OSParameter.SERVICE_URI);
			}
			if(jobStatistics.serviceURI != null && jobStatistics.serviceURI.Equals(OSParameter.OS_SCHEDULER_SITE)){
				jobStatistics.serviceURI = "";
			}
			if(jobStatistics.state == null || (!jobStatistics.state.Equals("finished") && !jobStatistics.state.Equals("killed"))){
				jobStatistics.state = "finished";			
			}		
			if(jobStatistics.endTime.Year <= 1970){
				if(serviceType.Equals("scheduler")){
					string sOSpLOutput = "";
					OSSolverAgent solverAgent = new OSSolverAgent();
					solverAgent.solverAddress = jobStatistics.serviceURI; 
					if(solverAgent.solverAddress != null && solverAgent.solverAddress.Length > 0 && 
							!solverAgent.solverAddress.Equals(OSParameter.OS_SCHEDULER_SITE) &&
							!solverAgent.solverAddress.Equals(OSParameter.SERVICE_URI)){
						OSpLWriter osplWriter = new OSpLWriter();
						osplWriter.setRequestAction("getJobStatistics");
						osplWriter.setServiceName(OSParameter.SERVICE_NAME);
						osplWriter.setServiceURI(OSParameter.OS_SCHEDULER_SITE);
						osplWriter.setProcessTime(DateTime.Now);
						string sOSpLInput = osplWriter.writeToString();
		
						OSoLWriter osolWriter = new OSoLWriter();
						osolWriter.setServiceName(OSParameter.SERVICE_NAME);
						osolWriter.setServiceURI(OSParameter.OS_SCHEDULER_SITE);
						osolWriter.setJobID(m_sJobID);
						osolWriter.setPassword(m_sSystemPassword);
						string sOSoL = osolWriter.writeToString();

						try{
							sOSpLOutput = solverAgent.knock(sOSpLInput, sOSoL);					
						} 
						catch(Exception e){
							IOUtil.log(e.ToString(), null);
						}
						JobStatistics[] mJobStatistics = null;
						OSpLReader osplReader = new OSpLReader(OSParameter.VALIDATE);
						try {
							osplReader.readString(sOSpLOutput);
							mJobStatistics = osplReader.getJobStatistics();					
						} 
						catch (Exception e) {
							IOUtil.log(e.ToString(), null);
						}
						if(mJobStatistics != null && mJobStatistics.Length > 0){
							int iJobStatistics = mJobStatistics.Length;
							for(int i = 0; i < iJobStatistics; i++){
								if(mJobStatistics[i] == null) continue;
								string sJobID = mJobStatistics[i].jobID;
								if(sJobID == null || !sJobID.Equals(m_sJobID)) continue;
								string sJobState = mJobStatistics[i].state;
								if(sJobState != null && (sJobState.Equals("finished") || sJobState.Equals("killed"))){
									jobStatistics.endTime = mJobStatistics[i].endTime;
									jobStatistics.startTime = mJobStatistics[i].startTime;
									jobStatistics.state = mJobStatistics[i].state;
									break;
								}							
							}
						}
					}
				}
				else{
					jobStatistics.endTime = DateTime.Now;
				}
			}
			if(jobStatistics.startTime.Year > 1970 && jobStatistics.endTime.Year > 1970){
				jobStatistics.duration = (CommonUtil.timeMillis(jobStatistics.endTime) - CommonUtil.timeMillis(jobStatistics.startTime))/1000;
			}

			//save ospl	
			saveOSpL();
			
			return sOSrL;
		}//retrieve
    
		/// <summary>
		/// Kill a previously sent/solved optimization job.  		
		/// </summary>
		/// <param name="osol">holds the option in a string which format follows OSoL schema
		/// It should contain the jobID information that is previous obtained from the service.</param>
		/// <returns>ospl, the kill process status of the kill operation.</returns>
		[System.Web.Services.WebMethodAttribute()]
		[System.Web.Services.Protocols.SoapRpcMethodAttribute("OSSolverService#kill", 
			 RequestNamespace="http://www.optimizationservices.org", 
			 ResponseNamespace="http://www.optimizationservices.org")]
		[return: System.Xml.Serialization.SoapElementAttribute("ospl")]
		public string kill(string osol){
			if(osol == null) osol = "";

			string sOSpL = "";
			m_osplWriter = new OSpLWriter();
			m_osplWriter.setServiceName(OSParameter.SERVICE_NAME);
			m_osplWriter.setServiceURI(OSParameter.SERVICE_URI);
			m_osplWriter.setProcessTime(DateTime.Now);

			//parse osol
			if(osol == null || osol.Length <= 0){
				m_osplWriter.setResponseStatus("error");
				m_osplWriter.setResponseDescription("No OSoL option specified");
				sOSpL = m_osplWriter.writeToString();
				return sOSpL;	
			}
			if(!readOSoL(osol)){
				m_osplWriter.setResponseStatus("error");
				m_osplWriter.setResponseDescription("Invalid OSoL option");
				sOSpL = m_osplWriter.writeToString();
				return sOSpL;
			}
			if(m_osOption == null) m_osOption = new OSOption();

			//check permission
			if(!OSParameter.REQUIRE_ONLY_JOB_ID_TO_KILL_JOB){
				try {
					if(!checkPermision()){
						m_osplWriter.setResponseStatus("error");
						m_osplWriter.setResponseDescription("Permission error.");
						sOSpL = m_osplWriter.writeToString();
						return sOSpL;
					}
				} 
				catch (Exception e) {
					IOUtil.log(e.Message, null);
					m_osplWriter.setResponseStatus("error");
					m_osplWriter.setResponseDescription(e.Message);
					sOSpL = m_osplWriter.writeToString();
					return sOSpL;
				}
			}
			
			//check jobID
			if(m_sJobID == null || m_sJobID.Length <= 0 ){
				m_osplWriter.setResponseStatus("error");
			    m_osplWriter.setResponseDescription("no job id found");
				sOSpL = m_osplWriter.writeToString();
				return sOSpL;
			}

			//check if there is the job
			JobStatistics jobStatistics =  (JobStatistics)m_jobStatisticsTable[m_sJobID];
			if(jobStatistics == null){
				m_osplWriter.setResponseStatus("success");
				m_osplWriter.setResponseDescription( m_sJobID+" is not there to kill");
				sOSpL = m_osplWriter.writeToString();
				return sOSpL;
			}

			//check if already finished or killed
			if(jobStatistics.state != null && (jobStatistics.state.Equals("finished"))){
				m_osplWriter.setResponseStatus("success");
				m_osplWriter.setResponseDescription( m_sJobID+" is already finished");
				sOSpL = m_osplWriter.writeToString();
				return sOSpL;
			}
			if(jobStatistics.state != null && (jobStatistics.state.Equals("killed"))){
				m_osplWriter.setResponseStatus("success");
				m_osplWriter.setResponseDescription( m_sJobID+" is already killed");
				sOSpL = m_osplWriter.writeToString();
				return sOSpL;
			}

			//kill
			OSServiceUtil osServiceUtil = new OSServiceUtil();
			osServiceUtil.m_sJobID = m_sJobID;

			string sError = "";
			if(serviceType.Equals("solver") || serviceType.Equals("analyzer")){
				ArrayList vProcess = (ArrayList)processsHashTable[m_sJobID];
				if(vProcess != null && vProcess.Count > 0){
					for(int i = 0; i < vProcess.Count; i++){
						try{
							Process process = Process.GetProcessById((int)vProcess[i]);
							process.Kill();
						}
						catch(Exception e){
							IOUtil.log(e.ToString(), null);
							sError += (e.ToString() + "\r\n\r\n");
						}
					}
				}
				processsHashTable.Remove(m_sJobID);
			}
				
			Thread thread = (Thread)m_threadHashTable[m_sJobID];
			if(thread != null){
				try{
					thread.Abort();
				}
				catch(Exception e){
					IOUtil.log(e.ToString(), null);
					sError += (e.ToString() + "\r\n\r\n");
				}
			}
			if(serviceType.Equals("scheduler") && 
			   jobStatistics != null && 
			   jobStatistics.serviceURI != null && 
			   !jobStatistics.serviceURI.Equals(OSParameter.OS_SCHEDULER_SITE)){

				OSSolverAgent solverAgent = new OSSolverAgent();
				solverAgent.solverAddress = jobStatistics.serviceURI; 
				if(solverAgent.solverAddress != null && solverAgent.solverAddress.Length > 0){
					try {
						string sKillOSpL = solverAgent.kill(osol);
						OSpLReader osplReader = new OSpLReader();
						bool bRead = osplReader.readString(sKillOSpL);
						if(!bRead) throw new Exception("Invalid OSpL process string");
						string sStatus = osplReader.getResponseStatus();
						if(!sStatus.Equals("success")){
							sError += (osplReader.getResponseDescription() + "\r\n" + osplReader.getProcessMessage() + "\r\n\r\n");
						}
					} 
					catch (Exception e) {
						IOUtil.log(e.ToString(), null);
					}
				}
			}
			else{//not scheduler  
				//postsolve
				string sOptionFile = OSParameter.TEMP_FILE_FOLDER+m_sJobID+".osol";
				string sOSoL = "";
				if(IOUtil.existsFileOrDir(sOptionFile)){
					sOSoL = IOUtil.readStringFromFile(sOptionFile);
					if(sOSoL != null && sOSoL.Length > 0){
						OSoLReader osolReader = new OSoLReader(m_bValidate);
						try {
							bool bRead = osolReader.readString(sOSoL);
							if(bRead){
								osServiceUtil.readOSoL(sOSoL);
								osServiceUtil.postsolve();
							}
						} 
						catch (Exception) {}
					}
					else{
						sOSoL = "";
					}
				}
			}

			//postprocess
			if(osServiceUtil.m_sJobID == null || osServiceUtil.m_sJobID.Length <= 0){
				osServiceUtil.m_sJobID = m_sJobID;
			}

			try{
				osServiceUtil.postprocess(true);
			}
			catch(Exception e){
				IOUtil.log(e.ToString(), null);
				sError += (e.ToString() + "\r\n\r\n");
			}
			if(sError.Length > 0){
				m_osplWriter.setResponseStatus("warning");
				m_osplWriter.setResponseDescription(m_sJobID + " is not killed completely");			
				m_osplWriter.setProcessMessage(sError);		
			}
			else{
				m_osplWriter.setResponseStatus("success");
				m_osplWriter.setResponseDescription(m_sJobID+" is killed successfully");	
			}
			sOSpL = m_osplWriter.writeToString();
			return sOSpL;
		}//kill
    
		/// <summary>
		/// Set (push) and/or get (pull) runtime dynamic process information to and/or from the service.  		
		/// </summary>
		/// <param name="osplInput"> the input process information in a string which format follows OSpL schema.</param>
		/// <param name="osol">holds the option in a string which format follows OSoL schema</param>
		/// <returns>osplOutput, the output process information in a string which format follows the OSpL schema.</returns>
		[System.Web.Services.WebMethodAttribute()]
		[System.Web.Services.Protocols.SoapRpcMethodAttribute("OSSolverService#knock", 
			 RequestNamespace="http://www.optimizationservices.org", 
			 ResponseNamespace="http://www.optimizationservices.org")]
		[return: System.Xml.Serialization.SoapElementAttribute("osplOutput")]
		public string knock(string osplInput, string osol){
			/*
			if(serviceType != null && serviceType.Equals("scheduler")){
				IOUtil.log(m_userJobCountTable.ToString(), null);
			}
			*/
			if(osplInput == null) osplInput = "";
			if(osol == null) osol = "";

			if(solver!=null || serviceType == null || serviceType.Equals("solver") || serviceType.Equals("analyzer") || serviceType.Equals("scheduler")){
				string sOSpLOutput = "";
				m_osplWriter = new OSpLWriter();
				m_osplWriter.setServiceName(OSParameter.SERVICE_NAME);
				m_osplWriter.setServiceURI(OSParameter.SERVICE_URI);
				m_osplWriter.setProcessTime(DateTime.Now);

				//read osol
				if(osol != null && osol.Length > 0){
					if(!readOSoL(osol)){
						m_osplWriter.setResponseStatus("error");
						m_osplWriter.setResponseDescription("Invalid OSoL option");
						sOSpLOutput = m_osplWriter.writeToString();
						return sOSpLOutput;
					}
				}
				if(m_osOption == null) m_osOption = new OSOption();

				//check permission
				try {
					if(!checkPermision()){
						m_osplWriter.setResponseStatus("error");
						m_osplWriter.setResponseDescription("Permission error.");
						sOSpLOutput = m_osplWriter.writeToString();
						return sOSpLOutput;
					}
				} 
				catch (Exception e) {
					IOUtil.log(e.Message, null);
					m_osplWriter.setResponseStatus("error");
					m_osplWriter.setResponseDescription(e.Message);
					sOSpLOutput = m_osplWriter.writeToString();
					return sOSpLOutput;
				}

				//check ospl
				m_osplReader = new OSpLReader(m_bValidate);
				string sAction = "";
				string sRequestDescription = "";
				string sServiceName = "";
				string sServiceURI = "";
				DateTime processTime = new DateTime(1970, 1, 1, 0, 0, 0);
				string sProcessMessage = "";
				ProcessStatistics processStatistics = null;
				JobStatistics[] mJobStatistics = null;
				OptimizationProcess optimizationProcess = null;

				if(osplInput == null || osplInput.Length == 0){
					m_osplWriter.setResponseStatus("error");
					m_osplWriter.setResponseDescription("ospl string is empty");
					sOSpLOutput = m_osplWriter.writeToString();
					return sOSpLOutput;
				}
				else{
					try {
						bool bRead = m_osplReader.readString(osplInput);
						if(!bRead){
							m_osplWriter.setResponseStatus("error");
							m_osplWriter.setResponseDescription("Invalid OSpL process input");
							sOSpLOutput = m_osplWriter.writeToString();
							return sOSpLOutput;
						}
						sAction = m_osplReader.getRequestAction();
						if((sAction == null || sAction.Length <= 0)){
							m_osplWriter.setResponseStatus("error");
							m_osplWriter.setResponseDescription("no request action specified in ospl");
							sOSpLOutput = m_osplWriter.writeToString();
							return sOSpLOutput;
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
								"getJobStatistics, setJobStatistics, getOptimization, setOptimization, getAll, setAll");
							sOSpLOutput = m_osplWriter.writeToString();
							return sOSpLOutput;
						}
						sRequestDescription = m_osplReader.getRequestAction();
						sServiceName = m_osplReader.getServiceName();
						sServiceURI = m_osplReader.getServiceURI();
						processTime = m_osplReader.getProcessTime();
						sProcessMessage = m_osplReader.getProcessMessage();
						processStatistics = m_osplReader.getProcessStatistics();
						mJobStatistics = (processStatistics==null || processStatistics.jobs==null)?null:processStatistics.jobs.job;
						optimizationProcess = m_osplReader.getOptimizationProcess();
					}
					catch (Exception e) {
						IOUtil.log(e.ToString(), null);
						m_osplWriter.setResponseStatus("error");
						m_osplWriter.setResponseDescription(e.ToString());
						m_osplWriter.setProcessMessage(e.ToString());
						sOSpLOutput = m_osplWriter.writeToString();
						return sOSpLOutput;
					}
				}
				if(sAction.Equals("ping")){
					m_osplWriter.setResponseStatus("success");
					m_osplWriter.setResponseDescription("The service is alive");
					sOSpLOutput = m_osplWriter.writeToString();
					return sOSpLOutput;
				}//ping
				if(sAction.Equals("notifyJobCompletion")){
					if((m_sJobID == null || m_sJobID.Length <= 0) && 
						(mJobStatistics==null || mJobStatistics.Length <= 0)){
						m_osplWriter.setResponseStatus("error");
						m_osplWriter.setResponseDescription("No job id is provided.");
						sOSpLOutput = m_osplWriter.writeToString();				
						return sOSpLOutput;
					}
					if((m_sJobID == null || m_sJobID.Length <= 0) && (mJobStatistics != null && mJobStatistics.Length >0)){
						m_sJobID = mJobStatistics[0].jobID;
					}
					if(m_sServiceURIInOSoL != null && m_sServiceURIInOSoL.Length > 0){
						sServiceURI = m_sServiceURIInOSoL;
					}
					if(sServiceURI == null || sServiceURI.Length <= 0){
						JobStatistics jobStatistics = (JobStatistics)m_jobStatisticsTable[m_sJobID];
						if(jobStatistics != null){
							sServiceURI = jobStatistics.serviceURI;	
						}
					}
					if(sServiceURI == null || sServiceURI.Length <= 0){
						m_osplWriter.setResponseStatus("warning");
						m_osplWriter.setResponseDescription("No service URI is provided.");
						sOSpLOutput = m_osplWriter.writeToString();				
						return sOSpLOutput;
					}
					string sWarningDescription = "";
					string sWarningMessage = "";
					if(serviceType.Equals("scheduler") && 
						!sServiceURI.Equals(OSParameter.OS_REGISTRY_SITE) &&
						!sServiceURI.Equals(OSParameter.OS_SCHEDULER_SITE)){
						//retrieve job from solvers if it is scheduler as it is the client of solvers. 
						//no need to retrieve job if it is solver as a solver never sends jobs. 
						try {
							m_osolWriter = new OSoLWriter();
							m_osolWriter.setServiceName(OSParameter.SERVICE_NAME);
							m_osolWriter.setServiceURI(OSParameter.SERVICE_URI);
							m_osolWriter.setJobID(m_sJobID);
							m_osolWriter.setPassword(m_sSystemPassword);
							m_osolWriter.setServiceType("scheduler");
							string sOSoLInput = m_osolWriter.writeToString();							
						
							RetrieveThread retrieveThread = new RetrieveThread();
							OSSolverAgent osSolverAgent = new OSSolverAgent(sServiceURI);
							retrieveThread.m_osSolverAgent = osSolverAgent;
							retrieveThread.m_sOSoL = sOSoLInput;
							string sResultFile = OSParameter.TEMP_FILE_FOLDER+m_sJobID+".osrl";
							retrieveThread.m_sResultFile = sResultFile;

							Thread thread = new Thread(new ThreadStart(retrieveThread.retrieve));	
							thread.Start();
						}	
						catch (Exception e){
							IOUtil.log(e.ToString(), null);
							sWarningDescription = "The service has got the notification. But there are some exceptions. See the message part.";
							sWarningMessage += (e.ToString()+"\r\n"); 
						}
						//notify the client of the scheduler
						string sOSoL = "";
						try {
							sOSoL = IOUtil.readStringFromFile(OSParameter.TEMP_FILE_FOLDER+m_sJobID+".osol");			
						} 
						catch (Exception){
						}
						if(sOSoL == null){
							sOSoL = "";
						}
						if(sOSoL != null && sOSoL.Length > 0){
							try {
								OSoLReader osolReader = new OSoLReader();
								bool bRead = osolReader.readString(sOSoL);
								if(!bRead) throw new Exception("Invalid OSoL option");
								string sContactTransportType = osolReader.getContactTransportType();
								string sContactAddress = osolReader.getContactAddress();								
								if(sContactAddress != null && sContactAddress.Length > 0 && 
									!sContactAddress.Equals(OSParameter.OS_SCHEDULER_SITE)){
									if(sContactTransportType == null || sContactTransportType.Length <= 0){
										sContactTransportType = "osp";
									}
									string sMessage = "Your job " + m_sJobID + " has completed on " + (OSParameter.SERVICE_URI);
									try {
										if(sContactTransportType.Equals("smtp")){
											MailUtil.sendInThread(OSParameter.FROM_EMAIL, sContactAddress, null, null, "notifyJobCompletion", sMessage, null);
										}
										if(sContactTransportType.Equals("osp")){
											m_osplWriter = new OSpLWriter();
											m_osplWriter.setRequestAction("notifyJobCompletion");
											m_osplWriter.setServiceURI(OSParameter.SERVICE_URI);
											m_osplWriter.setServiceName(OSParameter.SERVICE_NAME);
											m_osplWriter.setProcessTime(DateTime.Now);
											m_osplWriter.setProcessMessage(sMessage);
											m_osplWriter.setJobStatistics(mJobStatistics);
											string sProcessInput = m_osplWriter.writeToString();

											m_osolWriter = new OSoLWriter();
											m_osolWriter.setServiceURI(OSParameter.SERVICE_URI);
											m_osolWriter.setServiceName(OSParameter.SERVICE_NAME);
											m_osolWriter.setJobID(m_sJobID);
											m_osolWriter.setLicense(m_sLicense);
											m_osolWriter.setUserName(m_sUserName);		
											m_osolWriter.setPassword(OSParameter.getSystemPassword());
											string sServiceType = serviceType;
											m_osolWriter.setServiceType(sServiceType);
											string sOption = m_osolWriter.writeToString();

											KnockSolverThread knockSolverThread = new KnockSolverThread();
											OSSolverAgent osSolverAgent = new OSSolverAgent(sContactAddress);
											knockSolverThread.m_osSolverAgent = osSolverAgent;
											knockSolverThread.m_osplInput = sProcessInput;
											knockSolverThread.m_osol = sOption;
															
											Thread thread = new Thread(new ThreadStart(knockSolverThread.knock));	
											thread.Start();						
										}
									} 
									catch (Exception e) {
										IOUtil.log(e.ToString(), null);
									}
								}
							} 
							catch (Exception e) {
								IOUtil.log(e.ToString(), null);
							}
						}	
					}//if scheduler
					//set job statistics
					try {
						int iJobs = mJobStatistics==null?0:mJobStatistics.Length;
						for(int i = 0; i < iJobs; i++){
							if(mJobStatistics[i] != null && 
								mJobStatistics[i].jobID != null && mJobStatistics[i].jobID.Length > 0 && 
								mJobStatistics[i].state != null && 
								(mJobStatistics[i].state.Equals("killed") || mJobStatistics[i].state.Equals("finished"))){
								Thread thread = (Thread)m_threadHashTable[mJobStatistics[i].jobID];
								if(thread != null){
									try{
										thread.Abort();
									}
									catch(Exception e){
										IOUtil.log(e.ToString(), null);
									}
								}

								if(m_vWaitingJobIDs.Contains(mJobStatistics[i].jobID) || m_vCurrentJobIDs.Contains(mJobStatistics[i].jobID)){
									string sUserName = mJobStatistics[i].userName;
									if(sUserName == null) sUserName = "";
									string sCount = (string)m_userJobCountTable[sUserName];
									int iCount;
									if(sCount == null || sCount.Length <= 0){
										iCount = 0;
									}
									else{
										try {
											iCount = Int32.Parse(sCount);				
										} 
										catch (Exception) {
											iCount = 0;
										}
										if(iCount <= 0){
											iCount = 0;
										}
										else{
											iCount -= 1;
										}
									}
									m_userJobCountTable.Remove(sUserName);
									m_userJobCountTable.Add(sUserName, iCount+"");	
								}						


								m_solverThreadHashTable.Remove(mJobStatistics[i].jobID);
								m_threadHashTable.Remove(mJobStatistics[i].jobID);
								m_vCurrentJobIDs.Remove(mJobStatistics[i].jobID);
								m_vWaitingJobIDs.Remove(mJobStatistics[i].jobID);
								m_vFinishedJobIDs.Remove(mJobStatistics[i].jobID);
								m_vFinishedJobIDs.Add(mJobStatistics[i].jobID);
								m_iCurrentJobCount = m_vCurrentJobIDs.Count;

								JobStatistics jobStatistics = (JobStatistics)m_jobStatisticsTable[mJobStatistics[i].jobID];
								if(jobStatistics == null){
									m_jobStatisticsTable.Add(mJobStatistics[i].jobID, mJobStatistics[i]);
								}
								else{
									jobStatistics.jobID = mJobStatistics[i].jobID;
									if(mJobStatistics[i].state != null && (mJobStatistics[i].state.Equals("finished") || mJobStatistics[i].state.Equals("killed"))){
										jobStatistics.state = mJobStatistics[i].state;												
									}
									if(mJobStatistics[i].endTime.Year > 1970){
										jobStatistics.endTime = mJobStatistics[i].endTime;
										long lJobEndTime = CommonUtil.timeMillis(jobStatistics.endTime);
										if(lJobEndTime > m_lTimeLastJobEnded){
											m_lTimeLastJobEnded = lJobEndTime;
										}
									}
									if(mJobStatistics[i].startTime.Year > 1970){
										jobStatistics.startTime = mJobStatistics[i].startTime;
									}
									if(!Double.IsNaN(mJobStatistics[i].duration) && mJobStatistics[i].duration >= 0){
										jobStatistics.duration = mJobStatistics[i].duration;
									}
									if(mJobStatistics[i].endTime.Year > 1970 &&
										mJobStatistics[i].startTime.Year > 1970	){
										jobStatistics.duration = (CommonUtil.timeMillis(mJobStatistics[i].endTime) - CommonUtil.timeMillis(mJobStatistics[i].startTime))/1000;
									}
									if(jobStatistics.serviceURI != null &&  jobStatistics.serviceURI.Length > 0){
										jobStatistics.serviceURI = mJobStatistics[i].serviceURI;
									}
									if((jobStatistics.serviceURI == null ||  jobStatistics.serviceURI.Length <= 0) && !sServiceURI.Equals(OSParameter.OS_SCHEDULER_SITE)){
										jobStatistics.serviceURI = sServiceURI;
									}
									if(jobStatistics.serviceURI != null && jobStatistics.serviceURI.Equals(OSParameter.OS_SCHEDULER_SITE)){
										jobStatistics.serviceURI = "";
									}	

									if(jobStatistics.userName == null || jobStatistics.userName.Length <= 0){
										jobStatistics.userName = mJobStatistics[i].userName;
									}
									if(jobStatistics.submitTime.Year <= 1970){
										jobStatistics.submitTime = mJobStatistics[i].submitTime;
									}
									if(jobStatistics.scheduledStartTime.Year <= 1970){
										jobStatistics.scheduledStartTime = mJobStatistics[i].scheduledStartTime;
									}
									if(jobStatistics.dependencies.jobID == null || jobStatistics.dependencies.jobID.Length <= 0){
										jobStatistics.dependencies = mJobStatistics[i].dependencies;
									}
									if(jobStatistics.requiredDirectoriesAndFiles == null || jobStatistics.requiredDirectoriesAndFiles.path == null || jobStatistics.requiredDirectoriesAndFiles.path.Length <= 0){
										jobStatistics.requiredDirectoriesAndFiles = mJobStatistics[i].requiredDirectoriesAndFiles;
									}
								}
							}
						}
						Thread thread1 = (Thread)m_threadHashTable[m_sJobID];
						if(thread1 != null){
							try{
								thread1.Abort();
							}
							catch(Exception e){
								IOUtil.log(e.ToString(), null);
							}
						}

						JobStatistics jobStatistics1  = (JobStatistics)m_jobStatisticsTable[m_sJobID];		
						if(jobStatistics1 == null){
							jobStatistics1 = new JobStatistics();						
							jobStatistics1.jobID = m_sJobID;
							m_jobStatisticsTable.Add(m_sJobID, jobStatistics1);
						}

						if(jobStatistics1.userName == null || jobStatistics1.userName.Length <= 0){
							jobStatistics1.userName = m_sUserName;
						}
						string sUserName1 = jobStatistics1.userName;
						if(sUserName1 == null) sUserName1 = "";
						string sCount1 = (string)m_userJobCountTable[sUserName1];
						int iCount1;
						if(sCount1 == null || sCount1.Length <= 0){
							iCount1 = 0;
						}
						else{
							try {
								iCount1 = Int32.Parse(sCount1);					
							} 
							catch (Exception) {
								iCount1 = 0;
							}
							if(iCount1 <= 0){
								iCount1 = 0;
							}
							else if(m_vWaitingJobIDs.Contains(m_sJobID) || m_vCurrentJobIDs.Contains(m_sJobID)){
								iCount1 -= 1;
							}
						}
						m_userJobCountTable.Remove(sUserName1);
						m_userJobCountTable.Add(sUserName1, iCount1+"");


						m_solverThreadHashTable.Remove(m_sJobID);
						m_threadHashTable.Remove(m_sJobID);
						m_vCurrentJobIDs.Remove(m_sJobID);
						m_vWaitingJobIDs.Remove(m_sJobID);
						m_vFinishedJobIDs.Remove(m_sJobID);
						m_vFinishedJobIDs.Add(m_sJobID);

						jobStatistics1.jobID = m_sJobID;
						if((jobStatistics1.serviceURI == null ||  jobStatistics1.serviceURI.Length <= 0) && !sServiceURI.Equals(OSParameter.OS_SCHEDULER_SITE)){
							jobStatistics1.serviceURI = sServiceURI;
						}
						if(jobStatistics1.serviceURI != null && jobStatistics1.serviceURI.Equals(OSParameter.OS_SCHEDULER_SITE)){
							jobStatistics1.serviceURI = "";
						}
						if(jobStatistics1.state == null || (!jobStatistics1.state.Equals("finished") && !jobStatistics1.state.Equals("killed"))){
							jobStatistics1.state = "finished";			
						}
						if(jobStatistics1.endTime.Year <= 1970){
							jobStatistics1.endTime = DateTime.Now;
							if(jobStatistics1.startTime.Year > 1970){
								jobStatistics1.duration = (CommonUtil.timeMillis(jobStatistics1.endTime) - CommonUtil.timeMillis(jobStatistics1.startTime))/1000;
							}
						}
						else{
							long lJobEndTime = CommonUtil.timeMillis(jobStatistics1.endTime);
							if(lJobEndTime > m_lTimeLastJobEnded){
								m_lTimeLastJobEnded = lJobEndTime;
							}
						}
						if(jobStatistics1.userName == null || jobStatistics1.userName.Length <= 0){
							jobStatistics1.userName = m_sUserName;
						}
					} 
					catch (Exception e) {
						IOUtil.log(e.ToString(), null);
						sWarningDescription = "The service has got the notification. But there are some exceptions. See the message part.";
						sWarningMessage += (e.ToString()+"\r\n"); 
					}
					//save ospl
					saveOSpL();

					//prepare result
					if(sWarningDescription.Length <= 0){
						m_osplWriter.setResponseStatus("success");
						m_osplWriter.setResponseDescription("The service has successfully processed the notification.");
					}
					else{
						m_osplWriter.setResponseStatus("warning");	
						m_osplWriter.setResponseDescription(sWarningDescription);
						m_osplWriter.setProcessMessage(sWarningMessage);
					}
					sOSpLOutput = m_osplWriter.writeToString();
					return sOSpLOutput;
				}//notifyJobCompletion
				if(sAction.Equals("requestJob")){
					if(serviceType != null && serviceType.Equals("scheduler")){
						if(m_sServiceURIInOSoL != null && m_sServiceURIInOSoL.Length > 0){
							sServiceURI = m_sServiceURIInOSoL;
						}
						if(sServiceURI == null || sServiceURI.Length <= 0){
							m_osplWriter.setResponseStatus("warning");
							m_osplWriter.setResponseDescription("No service URI is provided.");
							sOSpLOutput = m_osplWriter.writeToString();				
							return sOSpLOutput;
						}
						//process waiting jobs		
						try {
							int iWaitingJobs = (m_vWaitingJobIDs==null?0:m_vWaitingJobIDs.Count);
							if(iWaitingJobs > 0){
								ProcessJobRequestThread processJobRequestThread = new ProcessJobRequestThread();
								acceptingSolverURIs.Remove(sServiceURI);
								processJobRequestThread.m_sRequestingServiceURI = sServiceURI;		
								Thread thread = new Thread(new ThreadStart(processJobRequestThread.processJobRequest));	
								thread.Start();
							}
							m_osplWriter.setResponseStatus("success");
							m_osplWriter.setResponseDescription("Job request notification is processed.");
							sOSpLOutput = m_osplWriter.writeToString();
							return sOSpLOutput;	
						} 
						catch (Exception e) {
							IOUtil.log(e.ToString(), null);
							m_osplWriter.setResponseStatus("error");
							m_osplWriter.setResponseDescription("Job request notification is received but there is some error in processing.");
							m_osplWriter.setProcessMessage(e.ToString());
							sOSpLOutput = m_osplWriter.writeToString();
							return sOSpLOutput;	
						}				
					}
					else{
						m_osplWriter.setResponseStatus("warning");
						m_osplWriter.setResponseDescription("The solver service does not take job request.");
						sOSpLOutput = m_osplWriter.writeToString();
						return sOSpLOutput;			
					}
				}//requestJob
				if(sAction.Equals("getServiceStatistics")|| sAction.Equals("getAll")){		
					try{
						m_iCurrentJobCount = m_vCurrentJobIDs.Count;
						try{
							m_dAvailableDiskSpace = IOUtil.getFreeDiskSpace(OSParameter.CODE_DRIVE);	
						}
						catch(Exception e){
							IOUtil.log(e.ToString(), null);
							m_dAvailableDiskSpace = Double.PositiveInfinity;
						}
						try{
							m_dAvailableMemory = ProcessUtil.getFreeMemory();	
						}
						catch(Exception e){
							IOUtil.log(e.ToString(), null);
							m_dAvailableMemory = Double.PositiveInfinity;
						}

						if(m_dAvailableDiskSpace <= OSParameter.MINIMUM_DISKSPACE_TRIGGER ||
						   m_dAvailableMemory <= ((double)OSParameter.MINIMUM_MEMORY_TRIGGER)){
							if(m_iCurrentJobCount > 0){
								m_sCurrentState = "busy";				
							}
							else{
								m_sCurrentState = "idleButNotAccepting";
							}
						}
						else{
							if(m_iCurrentJobCount == 0){
								m_sCurrentState = "idle";
							}
							else if(m_iCurrentJobCount >= OSParameter.MAX_JOB_NUMBERS){
								m_sCurrentState = "busy";
							}
							else{
								m_sCurrentState = "busyButAccepting";
							}
						}
						m_osplWriter.setCurrentState(m_sCurrentState);
						m_osplWriter.setAvailableDiskSpace(m_dAvailableDiskSpace);
						m_osplWriter.setAvailableMemory(m_dAvailableMemory);
						m_osplWriter.setCurrentJobCount(m_iCurrentJobCount);
						m_osplWriter.setTotalJobsSoFar(m_iTotalJobsSoFar);
						m_osplWriter.setTimeLastJobEnded(CommonUtil.createNativeDateTime(m_lTimeLastJobEnded));
						if(m_lLastJobTook < 0){
							m_osplWriter.setTimeLastJobTook(-1);					
						}
						else{
							m_osplWriter.setTimeLastJobTook((double)(m_lLastJobTook/1000.0));
						}
						m_osplWriter.setTimeServiceStarted(CommonUtil.createNativeDateTime(m_lTimeServiceStarted));
						m_osplWriter.setServiceUtilization(m_dServiceUtilization);

						string sCurrentJobIDs = "";
						int iCurrentJobIDs = m_vCurrentJobIDs.Count;
						string[] msCurrentJobIDs = new string[iCurrentJobIDs];
						for(int i = iCurrentJobIDs-1; i >= 0; i--){
							try{
								msCurrentJobIDs[i] = (string)m_vCurrentJobIDs[i];							
							}
							catch(Exception){
								msCurrentJobIDs[i] = "";
							}
						}
						if(iCurrentJobIDs > 0){
							if(msCurrentJobIDs[0] != null && msCurrentJobIDs[0].Length > 0){
								sCurrentJobIDs += msCurrentJobIDs[0];
							}							
						}
						for(int i = 1; i < iCurrentJobIDs; i++){
							if(msCurrentJobIDs[i] != null && msCurrentJobIDs[i].Length > 0){
								sCurrentJobIDs += "\r\n";
								sCurrentJobIDs += msCurrentJobIDs[i];							
							}
						}
						if(sCurrentJobIDs != null && sCurrentJobIDs.Length > 0){
							m_osplWriter.addOtherProcess("currentJobIDs", sCurrentJobIDs, "jobs that are currently running");
						}

						IDictionaryEnumerator dictionaryEnumerator = processsHashTable.GetEnumerator();
						string sProcesses = "";
						while(dictionaryEnumerator.MoveNext()){
							try{
								ArrayList vProcess = (ArrayList)dictionaryEnumerator.Value;
								Process process;
								int iProcess = vProcess==null?0:vProcess.Count;
								for(int i = 0; i < iProcess; i++){
									try{
										process = Process.GetProcessById((int)vProcess[i]);
										sProcesses += ("process" + i + " (name: " +process.ProcessName + ", id:" +  process.Id + ")\n\r");				
									}
									catch(Exception){
									}
								}
							}
							catch(Exception){
							}
						}
						if(sProcesses.Length > 0){
							m_osplWriter.addOtherProcess("processes", sProcesses, "processes launched by the current jobs");					
						}

						//save ospl
						saveOSpL();

						if(!sAction.Equals("getAll")){
							m_osplWriter.setResponseStatus("success");					
							m_osplWriter.setResponseDescription("The service statistics has been obtained. (No Job Statistics are included. To get job statistics, use action \"getJobStatistics\")");
							sOSpLOutput = m_osplWriter.writeToString();
							return sOSpLOutput;		
						}

					}
					catch(Exception e){
						IOUtil.log(e.ToString(), null);
						m_osplWriter.setResponseStatus("warning");				
						m_osplWriter.setResponseDescription(e.Message + " (No Job Statistics are included. To get job statistics, use action \"getJobStatistics\")");
						m_osplWriter.setProcessMessage(e.ToString());
						sOSpLOutput = m_osplWriter.writeToString();
						return sOSpLOutput;			
					}
				}//getServiceStatistics
				if(sAction.Equals("setServiceStatistics")){
					m_osplWriter.setResponseStatus("warning");
					m_osplWriter.setResponseDescription("The service does not allow setting service statistics externally.");
					sOSpLOutput = m_osplWriter.writeToString();
					return sOSpLOutput;
				}//setServiceStatistics
				if(sAction.Equals("getJobStatistics") || sAction.Equals("getAll")){
					try{
						JobStatistics[] mAllJobStatistics = null;
						if(m_sJobID != null && m_sJobID.Length > 0){
							JobStatistics jobStatistics = (JobStatistics)m_jobStatisticsTable[m_sJobID];
							if(jobStatistics != null){
								mAllJobStatistics = new JobStatistics[1];
								mAllJobStatistics[0] = jobStatistics;
								m_osplWriter.setJobStatistics(mAllJobStatistics);
							}
						}
						else{
							int iCurrentJobs = m_vCurrentJobIDs.Count;
							int iWaitingJobs = m_vWaitingJobIDs.Count;
							int iFinishedJobs = m_vFinishedJobIDs.Count;
						
							int iJobs =  iCurrentJobs + iWaitingJobs + iFinishedJobs;
							mAllJobStatistics = new JobStatistics[iJobs];
							int j = 0;
							for(int i = iCurrentJobs-1; i >= 0 ; i--){
								try{
									mAllJobStatistics[j] = (JobStatistics)m_jobStatisticsTable[(string)m_vCurrentJobIDs[i]];
									j++;
								}
								catch(Exception){
								}
							}
							for(int i = iWaitingJobs-1; i >= 0 ; i--){
								try{
									mAllJobStatistics[j] = (JobStatistics)m_jobStatisticsTable[(string)m_vWaitingJobIDs[i]];
									j++;
								}
								catch(Exception){
								}
							}
							for(int i = iFinishedJobs-1; i >= 0 ; i--){
								try{
									mAllJobStatistics[j] = (JobStatistics)m_jobStatisticsTable[(string)m_vFinishedJobIDs[i]];
									j++;
								}
								catch(Exception){
								}
							}
							if(iJobs > 0){
								m_osplWriter.setJobStatistics(mAllJobStatistics);
							}
						}
						if(!sAction.Equals("getAll")){
							if(mAllJobStatistics == null || mAllJobStatistics.Length <= 0){
								m_osplWriter.setResponseStatus("warning");					
								m_osplWriter.setResponseDescription("No job statistics has been obtained.");
							}
							else{
								m_osplWriter.setResponseStatus("success");					
								m_osplWriter.setResponseDescription("The job statistics has been obtained.");
							}
							sOSpLOutput = m_osplWriter.writeToString();
							return sOSpLOutput;		
						}
					}
					catch(Exception e){
						IOUtil.log(e.ToString(), null);
						m_osplWriter.setResponseStatus("warning");				
						m_osplWriter.setResponseDescription(e.Message);
						m_osplWriter.setProcessMessage(e.ToString());
						sOSpLOutput = m_osplWriter.writeToString();
						return sOSpLOutput;			
					}
				}//getJobStatistics
				if(sAction.Equals("setJobStatistics")){
					m_osplWriter.setResponseStatus("warning");
					m_osplWriter.setResponseDescription("The service does not allow setting job statistics externally.");
					sOSpLOutput = m_osplWriter.writeToString();
					return sOSpLOutput;
				}//setJobStatistics
				if(sAction.Equals("getOptimization") || sAction.Equals("getAll")){
					if(!sAction.Equals("getAll")){
						m_osplWriter.setResponseStatus("warning");
						m_osplWriter.setResponseDescription("Getting optimization information is not implemented.");
						sOSpLOutput = m_osplWriter.writeToString();
						return sOSpLOutput;
					}
				}//getOptimization
				if(sAction.Equals("setOptimization") || sAction.Equals("setAll")){
					if(!sAction.Equals("setAll")){
						m_osplWriter.setResponseStatus("warning");
						m_osplWriter.setResponseDescription("Setting optimization information is not implemented.");
						sOSpLOutput = m_osplWriter.writeToString();
						return sOSpLOutput;
					}
				}//setOptimization
				if(sAction.Equals("getAll")){
					m_osplWriter.setResponseStatus("success");					
					m_osplWriter.setResponseDescription("All the information has been obtained.");
					sOSpLOutput = m_osplWriter.writeToString();
					return sOSpLOutput;	
				}//getAll
				if(sAction.Equals("setAll")){
					m_osplWriter.setResponseStatus("success");					
					m_osplWriter.setResponseDescription("All the information has been set.");
					sOSpLOutput = m_osplWriter.writeToString();
					return sOSpLOutput;	
				}//setAll

				m_osplWriter.setResponseStatus("error");
				m_osplWriter.setResponseDescription("Request action is not recognized.");
				sOSpLOutput = m_osplWriter.writeToString();
				return sOSpLOutput;				
			}
			else if(m_registry!=null || serviceType.Equals("registry")){
				string sOSpLOutput = "";
				//log
				IOUtil.log("knock:"+DateTime.Now, OSParameter.REGISTRY_LOG_FILE);
				//set input
				registry.serviceName = serviceName;
				registry.serviceURI = serviceURI;
				registry.serviceType = "registry";			
				try{
					m_registry.osplKnockInput = osplInput;
				}
				catch(Exception e){
					IOUtil.log(e.ToString(), null);
				}
				try{
					m_registry.osolKnock = osol;
				}
				catch(Exception e){
					IOUtil.log(e.ToString(), null);
				}
				
				//knock
				try{
					m_registry.knock();
				}
				catch(Exception e){
					IOUtil.log(e.ToString(), null);
				}

				//get output
				try{
					sOSpLOutput = m_registry.osplKnockOutput;
				}
				catch(Exception e){
					IOUtil.log(e.ToString(), null);
				}
				return sOSpLOutput;			
			}
			else{
				string sOSpLOutput = "";
				IOUtil.log("no service engine (e.g. solver, registry) found", null);
				m_osplWriter = new OSpLWriter();
				m_osplWriter.setResponseStatus("error");
				m_osplWriter.setResponseDescription("no service engine (e.g. solver, scheduler, registry) found");
				sOSpLOutput = m_osplWriter.writeToString();
				return sOSpLOutput;
			}
		}//knock 

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
			if(osql == null) osql = "";
			if(osol == null) osol = "";

			string sOSuL = "";
			//log
			string sTime = XMLUtil.createXSDateTime(DateTime.Now);
			IOUtil.log("find:"+sTime, OSParameter.REGISTRY_LOG_FILE);
			//set input
			registry.serviceName = serviceName;
			registry.serviceURI = serviceURI;
			registry.serviceType = "registry";			
			try{
				m_registry.osql = osql;
			}
			catch(Exception e){
				IOUtil.log(e.ToString(), null);
			}
			try{
				m_registry.osolFind = osol;
			}
			catch(Exception e){
				IOUtil.log(e.ToString(), null);
			}
			//find
			try{
				m_registry.find();
			}
			catch(Exception e){
				IOUtil.log(e.ToString(), null);
			}
			//get output
			try{
				sOSuL = m_registry.osul;
			}
			catch(Exception e){
				IOUtil.log(e.ToString(), null);
			}
			return sOSuL;
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
			if(osel == null) osel = "";
			if(osol == null) osol = "";

			string sOSpLOutput = "";
			//log
			string sTime = XMLUtil.createXSDateTime(DateTime.Now);
			IOUtil.log("register:"+sTime, OSParameter.REGISTRY_LOG_FILE);
			//set input
			registry.serviceName = serviceName;
			registry.serviceURI = serviceURI;
			registry.serviceType = "registry";			
			try{
				m_registry.osel = osel;
			}
			catch(Exception e){
				IOUtil.log(e.ToString(), null);
			}
			try{
				m_registry.osolRegister = osol;
			}
			catch(Exception e){
				IOUtil.log(e.ToString(), null);
			}
			//register
			try{
				m_registry.register();
			}
			catch(Exception e){
				IOUtil.log(e.ToString(), null);
			}
			//get output
			try{
				sOSpLOutput = m_registry.osplRegisterOutput;
			}
			catch(Exception e){
				IOUtil.log(e.ToString(), null);
			}
			return sOSpLOutput;
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
			if(osxl == null) osxl = "";
			if(osol == null) osol = "";

			string sOSpLOutput = "";
			//log
			string sTime = XMLUtil.createXSDateTime(DateTime.Now);
			IOUtil.log("validate:"+sTime, OSParameter.REGISTRY_LOG_FILE);
			//set input
			registry.serviceName = serviceName;
			registry.serviceURI = serviceURI;
			registry.serviceType = "registry";			
			try{
				m_registry.osxl = osxl;
			}
			catch(Exception e){
				IOUtil.log(e.ToString(), null);
			}
			try{
				m_registry.osolValidate = osol;
			}
			catch(Exception e){
				IOUtil.log(e.ToString(), null);
			}
			//validate
			try{
				m_registry.validate();
			}
			catch(Exception e){
				IOUtil.log(e.ToString(), null);
			}
			//get output
			try{
				sOSpLOutput = m_registry.osplValidateOutput;
			}
			catch(Exception e){
				IOUtil.log(e.ToString(), null);
			}
			return sOSpLOutput;
		}//validate

		/// <summary>
		/// Call a simulation service whose input is given by a string following 
		/// the OSsL schema and returns the result in a string that also follows 
		/// OSsL schema, since OSsL specifies both simulation service input and output.
		/// </summary>
		/// <param name="osslInput">holds the simulation input in a string which format follows the OSsL schema.</param>
		/// <param name="osol">holds the option in a string which format follows OSoL schema</param>
		/// <returns>osslOutput, the simulation output in a string which format follows OSsL schema</returns>
		[System.Web.Services.WebMethodAttribute()]
		[System.Web.Services.Protocols.SoapRpcMethodAttribute("OSSimulationService#call", 
			 RequestNamespace="http://www.optimizationservices.org", 
			 ResponseNamespace="http://www.optimizationservices.org")]
		[return: System.Xml.Serialization.SoapElementAttribute("osslOutput")]
		public string call(string osslInput, string osol){	
			if(osslInput == null) osslInput = "";
			if(osol == null) osol = "";

			string sOSsLOutput = "";
			try{
				//set input
				SimulationThread simulationThread = new SimulationThread();
				simulationThread.m_simulation = this.m_simulation;
				simulationThread.m_sOSsLInput = osslInput;
				simulationThread.m_sOSoL = osol;
			
				//launch simulation thread
				Thread thread = new Thread(new ThreadStart(simulationThread.call));
				thread.Start();
				
				int iHour = (int)m_dJobMaxTime/3600;
				int iMin = (int)(m_dJobMaxTime-iHour*3600)/60;
				int iSec = (int)m_dJobMaxTime%60;
				TimeSpan timeSpan = new TimeSpan(iHour, iMin, iSec);
				thread.Join(timeSpan);
				
				//get output
				sOSsLOutput = simulationThread.m_sOSsLOutput;	
				return sOSsLOutput;
			}
			catch(Exception e){
				IOUtil.log(e.ToString(), null);
				return sOSsLOutput;
			}
		}//call
	
		/// <summary>
		/// <c>SolveThread</c> is an internal thread controlled by <c>OSServiceUtil</c> to call the solve method.
		/// </summary>
		protected internal class SolveThread{
			/// <summary>
			/// osServiceUtil holds the interface to call the local solve method. 
			/// </summary>
			protected internal OSServiceUtil m_osServiceUtil = null;

			/// <summary>
			/// m_osSolverAgent holds the agent to call the remote solve method. 
			/// </summary>
			protected internal OSSolverAgent m_osSolverAgent = null;

			/// <summary>
			/// m_sOSiL holds the osil input for the solve method. 
			/// </summary>
			protected internal string m_sOSiL = "";
		
			/// <summary>
			/// m_sOSoL holds the osol input for the solve method. 
			/// </summary>
			protected internal string m_sOSoL = "";

			/// <summary>
			/// m_sOSrL holds the osrl output for the solve method. 
			/// </summary>
			protected internal string m_sOSrL = "";

			/// <summary>
			/// A solve method is implemented here. 
			/// </summary>
			protected internal virtual void solve(){
				try {
					if(m_osServiceUtil != null){
						m_sOSrL = m_osServiceUtil.solve(m_sOSiL, m_sOSoL);
					}
					else if(m_osSolverAgent != null){
						m_sOSrL = m_osSolverAgent.solve(m_sOSiL, m_sOSoL);
					}				
				} 
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}
			}//solve
		}//SolveThread

		/// <summary>
		/// <c>SendThread</c> is an internal thread controlled by <c>OSServiceUtil</c> to call the send method.
		/// </summary>
		protected internal class SendThread{
			/// <summary>
			/// osServiceUtil holds the interface to call the local send method. 
			/// </summary>
			protected internal OSServiceUtil m_osServiceUtil = null;

			/// <summary>
			/// m_osSolverAgent holds the agent to call the remote send method. 
			/// </summary>
			protected internal OSSolverAgent m_osSolverAgent = null;

			/// <summary>
			/// m_sOSiL holds the osil input for the send method. 
			/// </summary>
			protected internal string m_sOSiL = "";
			
			/// <summary>
			/// m_osol holds the osol input for the solve method. 
			/// </summary>
			protected internal string m_sOSoL = "";

			/// <summary>
			/// m_bSend holds the boolean output for the send method. 
			/// </summary>
			protected bool m_bSend = false;

			/// <summary>
			/// A send method is implemented here. 
			/// </summary>
			protected internal virtual void send(){
				try {
					if(m_osServiceUtil != null){
						m_bSend = m_osServiceUtil.send(m_sOSiL, m_sOSoL);
					}
					else if(m_osSolverAgent != null){
						m_bSend = m_osSolverAgent.send(m_sOSiL, m_sOSoL);
					}				
				} 
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}
			}//send
		}//SendThread

		/// <summary>
		/// <c>RetrieveThread</c> is an internal thread controlled by <c>OSServiceUtil</c> to call the retrieve method.
		/// </summary>
		protected internal class RetrieveThread{
			/// <summary>
			/// osServiceUtil holds the interface to call the local retrieve method. 
			/// </summary>
			protected internal OSServiceUtil m_osServiceUtil = null;

			/// <summary>
			/// m_osSolverAgent holds the agent to call the remote retrieve method. 
			/// </summary>
			protected internal OSSolverAgent m_osSolverAgent = null;
		
			/// <summary>
			/// m_sOSoL holds the osol input for the retrieve method. 
			/// </summary>
			protected internal string m_sOSoL = "";
			
			/// <summary>
			/// m_sOSrL holds the osrl output for the retrieve method. 
			/// </summary>
			protected internal string m_sOSrL = "";

			/// <summary>
			/// m_sResultFile holds the result file name.  
			/// </summary>
			protected internal string m_sResultFile = "";

			/// <summary>
			/// A retrieve method is implemented here. 
			/// </summary>
			protected internal virtual void retrieve(){
				if(m_sResultFile != null && m_sResultFile.Length > 0  && IOUtil.existsFileOrDir(m_sResultFile)){
					OSrLReader osrlReader = new OSrLReader();
					try {
						bool bRead = osrlReader.readFile(m_sResultFile);
						if(bRead){
							string sStatus = osrlReader.getGeneralStatusType();
							if(sStatus != null && (sStatus.Equals("success") || sStatus.Equals("error"))){
								m_sOSrL = IOUtil.readStringFromFile(m_sResultFile);
								if(m_sOSrL == null){
									m_sOSrL = "";
								}
								return;
							}	
						}
					}
					catch (Exception e) {
						IOUtil.log(e.ToString(), null);
					}
				}

				try {
					if(m_osServiceUtil != null){
						m_sOSrL = m_osServiceUtil.retrieve(m_sOSoL);
					}
					else if(m_osSolverAgent != null){
						m_sOSrL = m_osSolverAgent.retrieve(m_sOSoL);
					}				
				} 
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
					return;
				}

				if(m_sResultFile == null || m_sResultFile.Length <= 0) return;

				if(m_sOSrL != null && m_sOSrL.Length > 0){
					OSrLReader osrlReader = new OSrLReader();
					try {
						bool bRead = osrlReader.readString(m_sOSrL);
						if(!bRead) throw new Exception("Invalid OSrL result");
						string sStatus = osrlReader.getGeneralStatusType();
						if(sStatus != null && (sStatus.Equals("success") || sStatus.Equals("error"))){
							bool bWrite = IOUtil.writeStringToFile(m_sOSrL, m_sResultFile);
							if(!bWrite){
								IOUtil.log("result file " + m_sResultFile + " not written successfully", null);
							}
						}	
					}
					catch (Exception e) {
						IOUtil.log(e.ToString(), null);
					}
				}
				return;
			}//retrieve
		}//RetrieveThread

		/// <summary>
		/// <c>KillThread</c> is an internal thread controlled by <c>OSServiceUtil</c> to call the kill method.
		/// </summary>
		protected internal class KillThread{
			/// <summary>
			/// osServiceUtil holds the interface to call the local kill method. 
			/// </summary>
			protected internal OSServiceUtil m_osServiceUtil = null;

			/// <summary>
			/// m_osSolverAgent holds the agent to call the remote kill method. 
			/// </summary>
			protected internal OSSolverAgent m_osSolverAgent = null;
		
			/// <summary>
			/// m_sOSoL holds the osol input for the kill method. 
			/// </summary>
			protected internal string m_sOSoL = "";

			/// <summary>
			/// m_sOSpL holds the ospl output for the kill method. 
			/// </summary>
			protected internal string m_sOSpL = "";

			/// <summary>
			/// A kill method is implemented here. 
			/// </summary>
			protected internal virtual void kill(){
				try {
					if(m_osServiceUtil != null){
						m_sOSpL = m_osServiceUtil.kill(m_sOSoL);
					}
					else if(m_osSolverAgent != null){
						m_sOSpL = m_osSolverAgent.kill(m_sOSoL);
					}			
				} 
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}
			}//kill
		}//KillThread

		/// <summary>
		/// <c>KnockSolverThread</c> is an internal thread controlled by <c>OSServiceUtil</c> to call the knock method on a solver.
		/// </summary>
		protected internal class KnockSolverThread{
			/// <summary>
			/// osServiceUtil holds the interface to call the local knock method. 
			/// </summary>
			protected internal OSServiceUtil m_osServiceUtil = null;

			/// <summary>
			/// m_osSolverAgent holds the agent to call the remote knock method. 
			/// </summary>
			protected internal OSSolverAgent m_osSolverAgent = null;

			/// <summary>
			/// m_osplInput holds the ospl input for the knock method.  
			/// </summary>
			protected internal string m_osplInput = "";

			/// <summary>
			/// m_osol holds the osol input for the knock method. 
			/// </summary>
			protected internal string m_osol = "";

			/// <summary>
			/// m_osplOutput holds the ospl output for the knock method. 
			/// </summary>
			protected internal string m_osplOutput = "";

			/// <summary>
			/// A knock method is implemented here. 
			/// </summary>
			protected internal virtual void knock(){
				try {
					if(m_osServiceUtil != null){
						m_osplOutput = m_osServiceUtil.knock(m_osplInput, m_osol);
					}
					else if(m_osSolverAgent != null){
						m_osplOutput = m_osSolverAgent.knock(m_osplInput, m_osol);
					}				
				}
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}
			}//knock
		}//KnockSolverThread

		/// <summary>
		/// <c>KnockRegistryThread</c> is an internal thread controlled by <c>OSServiceUtil</c> to call the knock method on a registry.
		/// </summary>
		protected internal class KnockRegistryThread{
			/// <summary>
			/// osServiceUtil holds the interface to call the local knock method. 
			/// </summary>
			protected internal OSServiceUtil m_osServiceUtil = null;

			/// <summary>
			/// m_osRegistryAgent holds the agent to call the remote knock method. 
			/// </summary>
			protected internal OSRegistryAgent m_osRegistryAgent = null;

			/// <summary>
			/// m_sOSpLInput holds the ospl input for the knock method.  
			/// </summary>
			protected internal string m_sOSpLInput = "";

			/// <summary>
			/// m_sOSoL holds the osol input for the knock method. 
			/// </summary>
			protected internal string m_sOSoL = "";

			/// <summary>
			/// m_sOSpLOutput holds the ospl output for the knock method. 
			/// </summary>
			protected internal string m_sOSpLOutput = "";

			/// <summary>
			/// A knock method is implemented here. 
			/// </summary>
			protected internal virtual void knock(){
				try {
					if(m_osServiceUtil != null){
						m_sOSpLOutput = m_osServiceUtil.knock(m_sOSpLInput, m_sOSoL);
					}
					else if(m_osRegistryAgent != null){
						m_sOSpLOutput = m_osRegistryAgent.knock(m_sOSpLInput, m_sOSoL);
					}			
				}
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}
			}//knock
		}//KnockSolverThread

		/// <summary>
		/// <c>FindThread</c> is an internal thread controlled by <c>OSServiceUtil</c> to call the find method on a registry.
		/// </summary>
		protected internal class FindThread{
			/// <summary>
			/// osServiceUtil holds the interface to call the local find method. 
			/// </summary>
			protected internal OSServiceUtil m_osServiceUtil = null;

			/// <summary>
			/// m_osRegistryAgent holds the agent to call the remote find method. 
			/// </summary>
			protected internal OSRegistryAgent m_osRegistryAgent = null;

			/// <summary>
			/// m_sOSqL holds the osql input for the find method. 
			/// </summary>
			protected internal string m_sOSqL = "";

			/// <summary>
			/// m_sOSoL holds the osol input for the find method. 
			/// </summary>
			protected internal string m_sOSoL = "";

			/// <summary>
			/// m_sOSuL holds the osul output for the find method. 
			/// </summary>
			protected internal string m_sOSuL = "";

			/// <summary>
			/// A find method is implemented here. 
			/// </summary>
			protected internal virtual void find(){
				try {
					if(m_osServiceUtil != null){
						m_sOSuL = m_osServiceUtil.find(m_sOSqL, m_sOSoL);
					}
					else if(m_osRegistryAgent != null){
						m_sOSuL = m_osRegistryAgent.find(m_sOSqL, m_sOSoL);
					}			
				}
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}
			}//find
		}//FindThread
			
		/// <summary>
		/// remove a waiting job
		/// </summary>
		/// <param name="jobID">holds the jobID of the waiting job to remove. </param>
		/// <returns>whether the job is removed from the waiting list. </returns>
		protected internal static bool removeWaitingJob(String jobID){
			if(m_vFinishedJobIDs.Contains(jobID)){
				return true;
			}
			Thread thread = (Thread)m_threadHashTable[jobID];
			if(thread != null){
				try{
					thread.Abort();
				}
				catch(Exception e){
					IOUtil.log(e.ToString(), null);
				}
			}

			JobStatistics jobStatistics  = (JobStatistics)m_jobStatisticsTable[jobID];
			if(jobStatistics == null){
				jobStatistics = new JobStatistics();
				jobStatistics.jobID = jobID;
				m_jobStatisticsTable.Add(jobID, jobStatistics);
			}

			string sUserName = jobStatistics.userName;
			if(sUserName == null) sUserName = "";
			string sCount = (string)m_userJobCountTable[sUserName];
			int iCount;
			if(sCount == null || sCount.Length <= 0){
				iCount = 0;
			}
			else{
				try {
					iCount = Int32.Parse(sCount);
				} 
				catch (Exception) {
					iCount = 0;
				}
				if(iCount <= 0){
					iCount = 0;
				}
				else if( m_vWaitingJobIDs.Contains(jobID) || m_vCurrentJobIDs.Contains(jobID)){
					iCount -= 1;
				}
			}
			m_userJobCountTable.Remove(sUserName);
			m_userJobCountTable.Add(sUserName, iCount+"");

			m_solverThreadHashTable.Remove(jobID);
			m_threadHashTable.Remove(jobID);
			m_vCurrentJobIDs.Remove(jobID);
			m_vWaitingJobIDs.Remove(jobID);
			processsHashTable.Remove(jobID);
			m_vFinishedJobIDs.Remove(jobID);
			m_vFinishedJobIDs.Add(jobID);
			m_iCurrentJobCount = m_vCurrentJobIDs.Count;

			jobStatistics.jobID = jobID;
			jobStatistics.state = "killed";
			jobStatistics.startTime = DateTime.Now;
			jobStatistics.endTime = jobStatistics.startTime;
			m_lTimeLastJobEnded = CommonUtil.timeMillis(jobStatistics.endTime);
			jobStatistics.duration = 0;			
			m_dServiceUtilization = (m_lTotalBusyTime/(m_lTimeLastJobEnded - m_lTimeServiceStarted));
			
			//save ospl
			saveOSpL();

			return true;
		}//removeWaitingJob

		/// <summary>
		/// <c>ProcessJobRequestThread</c> is an internal thread controlled by <c>OSServiceUtil</c> 
		/// to process job request. 
		/// </summary>
		protected internal class ProcessJobRequestThread {
			/// <summary>
			/// m_sRequestingServiceURI holds the serviceURI of the requesting service. 
			/// </summary>
			protected internal string m_sRequestingServiceURI = "";

			/// <summary>
			/// The job request process is implemented here. 
			/// </summary>
			protected internal virtual void processJobRequest(){
				if(OSParameter.SERVICE_TYPE == null || !OSParameter.SERVICE_TYPE.Equals("scheduler")){
					return;
				}
				if(!m_sCurrentState.Equals("idle") && !m_sCurrentState.Equals("busyButAccepting")){
					return;
				}
				int iWaitingJobs = (m_vWaitingJobIDs==null?0:m_vWaitingJobIDs.Count);
				if(iWaitingJobs <= 0){
					return;
				}
				string[] msWaitingJobIDs = new string[iWaitingJobs];
				for(int i = iWaitingJobs-1; i >=0; i--){
					try{
						msWaitingJobIDs[i] = (string)m_vWaitingJobIDs[i];
					}
					catch(Exception){
						msWaitingJobIDs[i] = "";
					}
				}
				for(int i = 0; i < iWaitingJobs; i++){
					string sJobID = msWaitingJobIDs[i];

					acceptingSolverURIs.Remove(m_sRequestingServiceURI);
					OSServiceUtil osServiceUtil = new OSServiceUtil();						
					osServiceUtil.serviceName = OSParameter.SERVICE_NAME;
					osServiceUtil.serviceURI = OSParameter.OS_SCHEDULER_SITE; 
					osServiceUtil.serviceType = "scheduler";
					osServiceUtil.m_sJobID = sJobID;

					if(sJobID == null || sJobID.Length <= 0){
						continue;
					}
					if(!m_vWaitingJobIDs.Contains(sJobID)){
						continue;
					}
					string sOptionFile = OSParameter.TEMP_FILE_FOLDER+sJobID+".osol";
					if(!IOUtil.existsFileOrDir(sOptionFile)){
						removeWaitingJob(sJobID);
						continue;
					}
					string sOSoL = IOUtil.readStringFromFile(sOptionFile);
					if(sOSoL == null || sOSoL.Length <= 0){
						sOSoL = "";
						removeWaitingJob(sJobID);
						continue;
					}
					if(!osServiceUtil.readOSoL(sOSoL)){
						removeWaitingJob(sJobID);
						continue;
					}			
					try {
						if(osServiceUtil.checkWaiting("", sOSoL, false, false)){
							continue;
						}
					} 
					catch (Exception) {
						removeWaitingJob(sJobID);
					}			
					string sInstanceFile = OSParameter.TEMP_FILE_FOLDER+sJobID+".osil";
					string sOSiL = IOUtil.readStringFromFile(sInstanceFile);
					if(sOSiL == null){
						sOSiL = "";
					}
					acceptingSolverURIs.Remove(m_sRequestingServiceURI);
					acceptingSolverURIs.Insert(0, m_sRequestingServiceURI);
					bool bSend = osServiceUtil.send(sOSiL, sOSoL);
					if(m_vWaitingJobIDs.Contains(sJobID)){ 
						m_vWaitingJobIDs.Remove(sJobID);
						m_vWaitingJobIDs.Add(sJobID);
					}
					if(!acceptingSolverURIs.Contains(sJobID)){
						return;
					}
					if(!m_sCurrentState.Equals("idle") && !m_sCurrentState.Equals("busyButAccepting")){
						return;
					}
				}
			}//processJobRequest
		}//ProcessJobRequestThread

		/// <summary>
		/// <c>ProcessJobRequestThread</c> is an internal thread controlled by <c>OSServiceUtil</c> 
		/// to process job waiting jobs. 
		/// </summary>
		protected internal class ProcessWaitingJobsThread {
			/// <summary>
			/// The waiting job process is implemented here. 
			/// </summary>
			protected internal virtual void processWaitingJobs(){
				if(!m_sCurrentState.Equals("idle") && !m_sCurrentState.Equals("busyButAccepting")){
					return;
				}
				int iWaitingJobs = (m_vWaitingJobIDs==null?0:m_vWaitingJobIDs.Count);
				if(iWaitingJobs <= 0){
					return;
				}
				string[] msWaitingJobIDs = new string[iWaitingJobs];
				for(int i = iWaitingJobs-1; i >=0; i--){
					try{
						msWaitingJobIDs[i] = (string)m_vWaitingJobIDs[i];
					}
					catch(Exception){
						msWaitingJobIDs[i] = "";
					}
				}
				int iEmptyAcceptingSolverURIs = 0;
				if(OSParameter.SERVICE_TYPE != null && OSParameter.SERVICE_TYPE.Equals("scheduler")){
					int iAcceptingSolverURIs = (acceptingSolverURIs == null?0:acceptingSolverURIs.Count);
					if(iAcceptingSolverURIs == 0) iEmptyAcceptingSolverURIs++;
				}
				for(int i = 0; i < iWaitingJobs; i++){
					string sJobID = msWaitingJobIDs[i];
					OSServiceUtil osServiceUtil = new OSServiceUtil();						
					osServiceUtil.m_sJobID = sJobID;

					if(sJobID == null || sJobID.Length <= 0){
						continue;
					}
					if(!m_vWaitingJobIDs.Contains(sJobID)){
						continue;
					}

					long lNow = CommonUtil.currentTimeMillis();						
					JobStatistics jobStatistics  = (JobStatistics)m_jobStatisticsTable[sJobID];
					if(jobStatistics == null){
						jobStatistics = new JobStatistics();
						jobStatistics.jobID = sJobID;
						m_jobStatisticsTable.Add(sJobID, jobStatistics);
					}
					if(jobStatistics.submitTime.Year <= 1970){
						jobStatistics.submitTime = DateTime.Now;
					}
					if(((lNow - CommonUtil.timeMillis(jobStatistics.submitTime))/1000 > (2*OSParameter.JOB_MAX_TIME))){	
						removeWaitingJob(sJobID);
						continue;
					}
					string sOptionFile = OSParameter.TEMP_FILE_FOLDER+sJobID+".osol";
					if(!IOUtil.existsFileOrDir(sOptionFile)){
						removeWaitingJob(sJobID);
						continue;
					}
					string sOSoL = IOUtil.readStringFromFile(sOptionFile);
					if(sOSoL == null || sOSoL.Length <= 0){
						sOSoL = "";
						removeWaitingJob(sJobID);
						continue;
					}
					if(!osServiceUtil.readOSoL(sOSoL)){
						removeWaitingJob(sJobID);
						continue;
					}
					try {
						if(osServiceUtil.checkWaiting("", sOSoL, false, false)){
							continue;
						}
					} 
					catch (Exception) {
						removeWaitingJob(sJobID);
					}								
					string sInstanceFile = OSParameter.TEMP_FILE_FOLDER+sJobID+".osil";
					string sOSiL = IOUtil.readStringFromFile(sInstanceFile);
					if(sOSiL == null){
						sOSiL = "";
					}
					bool bSend = osServiceUtil.send(sOSiL, sOSoL);
					if(m_vWaitingJobIDs.Contains(sJobID)){ 		
						m_vWaitingJobIDs.Remove(sJobID);
						m_vWaitingJobIDs.Add(sJobID);			
					}
					if(!m_sCurrentState.Equals("idle") && !m_sCurrentState.Equals("busyButAccepting")){
						return;
					}
					if(OSParameter.SERVICE_TYPE != null && OSParameter.SERVICE_TYPE.Equals("scheduler")){
						int iAcceptingSolverURIs = (acceptingSolverURIs == null?0:acceptingSolverURIs.Count);
						if(iAcceptingSolverURIs == 0) iEmptyAcceptingSolverURIs++;

						if(iEmptyAcceptingSolverURIs >= 2){
							return;
						}
					}
				}
			}//processWaitingJobs
		}//ProcessWaitingJobsThread

		/// <summary>
		/// <c>CheckSchedulerCurrentJobsThread</c> is an internal thread controlled by <c>OSServiceUtil</c> 
		/// to process current jobs in the scheduler. 
		/// </summary>
		protected internal class CheckSchedulerCurrentJobsThread {
			/// <summary>
			/// m_sCurrentJobID holds the jobID of the current Job. 
			/// </summary>
			protected String m_sCurrentJobID = "";

			/// <summary>
			/// The current scheculer jobs processing are implemented here. 
			/// </summary>
			protected internal virtual void checkSchedulerCurrentJobs(){
				
				/* get job statistics from scheduler to solver reference*/
				if(OSParameter.SERVICE_TYPE == null && !OSParameter.SERVICE_TYPE.Equals("scheduler")) return;
				if(m_sCurrentJobID == null || m_sCurrentJobID.Length <= 0) return;
				JobStatistics jobStatistics = (JobStatistics)m_jobStatisticsTable[m_sCurrentJobID];
				if(jobStatistics == null){
					jobStatistics = new JobStatistics();						
					jobStatistics.jobID = m_sCurrentJobID;
					m_jobStatisticsTable.Add(m_sCurrentJobID, jobStatistics);
				}
				jobStatistics.jobID = m_sCurrentJobID;
				string sServiceURI = jobStatistics.serviceURI;
				if(sServiceURI != null && sServiceURI.Equals(OSParameter.OS_SCHEDULER_SITE)) sServiceURI = "";
				if(sServiceURI == null || sServiceURI.Length <= 0){
					jobStatistics.state = "waiting";
					jobStatistics.startTime = new DateTime(1970, 1, 1, 0, 0, 0);
					m_vCurrentJobIDs.Remove(m_sCurrentJobID);
					m_vWaitingJobIDs.Remove(m_sCurrentJobID);
					m_vWaitingJobIDs.Add(m_sCurrentJobID);
					return;
				}
				try {
					OSpLWriter osplWriter = new OSpLWriter();
					osplWriter.setRequestAction("getJobStatistics");
					osplWriter.setServiceName(OSParameter.SERVICE_NAME);
					osplWriter.setServiceURI(OSParameter.OS_SCHEDULER_SITE);
					osplWriter.setProcessTime(DateTime.Now);
					string sOSpLInput = osplWriter.writeToString();

					OSoLWriter osolWriter = new OSoLWriter();
					osolWriter.setServiceName(OSParameter.SERVICE_NAME);
					osolWriter.setServiceURI(OSParameter.OS_SCHEDULER_SITE);
					osolWriter.setJobID(m_sCurrentJobID);
					osolWriter.setPassword(m_sSystemPassword);
					string sOSoL = osolWriter.writeToString();

					string sOSpLOutput = "";
					try{
						OSSolverAgent osSolverAgent = new OSSolverAgent(sServiceURI);
						sOSpLOutput = osSolverAgent.knock(sOSpLInput, sOSoL);					
					} 
					catch(Exception e){
						IOUtil.log(e.ToString(), null);
						return;
					}
					JobStatistics[] mJobStatistics = null;
					OSpLReader osplReader = new OSpLReader(OSParameter.VALIDATE);
				
					try {
						osplReader.readString(sOSpLOutput);
						mJobStatistics = osplReader.getJobStatistics();					
					} 
					catch (Exception e) {
						IOUtil.log(e.ToString(), null);
					}
					if(mJobStatistics == null || mJobStatistics.Length <= 0) return;
					int iJobStatistics = mJobStatistics.Length;
					bool bRemoveCurrentJob = false;
					JobStatistics newJobStatistics = null;
					for(int i = 0; i < iJobStatistics; i++){
						if(mJobStatistics[i] == null) continue;
						string sJobID = mJobStatistics[i].jobID;
						if(sJobID == null || !sJobID.Equals(m_sCurrentJobID)){
							continue;
						}
						else{
							string sJobState = mJobStatistics[i].state;
							if(sJobState != null && (sJobState.Equals("finished") || sJobState.Equals("killed"))){
								newJobStatistics = mJobStatistics[i];
								bRemoveCurrentJob = true;
							}
							break;
						}
					}
					if(bRemoveCurrentJob){
						osplWriter = new OSpLWriter();
						osplWriter.setRequestAction("notifyJobCompletion");
						osplWriter.setServiceURI(sServiceURI);
						osplWriter.setProcessTime(DateTime.Now);
						JobStatistics[] mJobStatistics1 = new JobStatistics[1];
						mJobStatistics1[0] = newJobStatistics;
						osplWriter.setJobStatistics(mJobStatistics1);
						string sProcessInput = osplWriter.writeToString();
					
						osolWriter = new OSoLWriter();
						osolWriter.setServiceURI(sServiceURI);
						osolWriter.setJobID(m_sCurrentJobID);
						osolWriter.setPassword(OSParameter.getSystemPassword());			
						osolWriter.setServiceType("solver");
						string sOption = osolWriter.writeToString();
					
						OSServiceUtil osServiceUtil = new OSServiceUtil();						
						osServiceUtil.m_sJobID = m_sCurrentJobID;
						osServiceUtil.knock(sProcessInput, sOption);
						/* The following does partially what the osServiceUtil.knock (action="notifyJobCompletion") does.  
						if(jobStatistics.userName == null || jobStatistics.userName.Length <= 0){
							jobStatistics.userName = newJobStatistics.userName;
						}
						Thread thread = (Thread)m_threadHashTable[m_sCurrentJobID];
						if(thread != null){
							try{
								thread.Abort();
							}
							catch(Exception e){
								IOUtil.log(e.ToString(), null);
							}
						}
						string sUserName = jobStatistics.userName;
						if(sUserName == null) sUserName = "";
						string sCount = (string)m_userJobCountTable[sUserName];
						int iCount;
						if(sCount == null || sCount.Length <= 0){
							iCount = 0;
						}
						else{
							try {
								iCount = Int32.Parse(sCount);					
							} 
							catch (Exception) {
								iCount = 0;
							}
							if(iCount <= 0){
								iCount = 0;
							}
							else if(m_vWaitingJobIDs.Contains(m_sCurrentJobID) || m_vCurrentJobIDs.Contains(m_sCurrentJobID)){
								iCount -= 1;
							}
						}
						m_userJobCountTable.Remove(sUserName);
						m_userJobCountTable.Add(sUserName, iCount+"");

						m_solverThreadHashTable.Remove(m_sCurrentJobID);
						m_threadHashTable.Remove(m_sCurrentJobID);
						m_vCurrentJobIDs.Remove(m_sCurrentJobID);
						m_vWaitingJobIDs.Remove(m_sCurrentJobID);
						m_vFinishedJobIDs.Remove(m_sCurrentJobID);
						m_vFinishedJobIDs.Add(m_sCurrentJobID);
						m_iCurrentJobCount = m_vCurrentJobIDs.Count;
					
						jobStatistics.state = newJobStatistics.state;
						if(jobStatistics.submitTime.Year <= 1970){
							jobStatistics.submitTime = newJobStatistics.submitTime;
						}
						if(newJobStatistics.startTime.Year > 1970){
							jobStatistics.startTime = newJobStatistics.startTime;
						}
						if(newJobStatistics.endTime.Year > 1970){
							jobStatistics.endTime = newJobStatistics.endTime;
						}
						if(jobStatistics.startTime.Year > 1970 &&
							jobStatistics.startTime.Year > 1970){
							jobStatistics.duration = (CommonUtil.timeMillis(jobStatistics.endTime) - CommonUtil.timeMillis(jobStatistics.startTime))/1000.0;
						}
						//retrieve job
						try{
							OSoLWriter osolWriter2 = new OSoLWriter();
							osolWriter2.setServiceName(OSParameter.SERVICE_NAME);
							osolWriter2.setServiceURI(OSParameter.SERVICE_URI);
							osolWriter2.setJobID(m_sCurrentJobID);
							osolWriter2.setPassword(m_sSystemPassword);
							osolWriter2.setServiceType("scheduler");
							String sOSoLInput = osolWriter2.writeToString();					
						
							RetrieveThread retrieveThread = new RetrieveThread();
							OSSolverAgent osSolverAgent = new OSSolverAgent(sServiceURI);
							retrieveThread.m_osSolverAgent = osSolverAgent;
							retrieveThread.m_sOSoL = sOSoLInput;
							string sResultFile = OSParameter.TEMP_FILE_FOLDER+m_sCurrentJobID+".osrl";
							retrieveThread.m_sResultFile = sResultFile;
						
							Thread thread2 = new Thread(new ThreadStart(retrieveThread.retrieve));	
							thread.Start();
						}	
						catch (Exception e){
							IOUtil.log(e.ToString(),null);
						}		
						*/
					}
				} 
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}
			}//checkSchedulerCurrentJobs
		}//CheckSchedulerCurrentJobsThread

		/// <summary>
		/// save process information in OSpL. 
		/// </summary>
		/// <returns>whether the process information is save successfully or not.</returns>
		protected internal static bool saveOSpL(){
			try{
				OSpLWriter osplWriter = new OSpLWriter();
				osplWriter.setServiceURI(OSParameter.SERVICE_URI);
				osplWriter.setServiceName(OSParameter.SERVICE_NAME);
				osplWriter.setProcessTime(DateTime.Now);
				osplWriter.setCurrentState(m_sCurrentState);
				osplWriter.setAvailableDiskSpace(m_dAvailableDiskSpace);
				osplWriter.setAvailableMemory(m_dAvailableMemory);
				osplWriter.setCurrentJobCount(m_vCurrentJobIDs==null?0:m_vCurrentJobIDs.Count);
				osplWriter.setTotalJobsSoFar(m_iTotalJobsSoFar);
				osplWriter.setTimeLastJobEnded(CommonUtil.createNativeDateTime(m_lTimeLastJobEnded));
				if(m_lLastJobTook < 0){
					osplWriter.setTimeLastJobTook(-1);					
				}
				else{
					osplWriter.setTimeLastJobTook((double)(m_lLastJobTook/1000.0));
				}
				osplWriter.setTimeServiceStarted(CommonUtil.createNativeDateTime(m_lTimeServiceStarted));
				osplWriter.setServiceUtilization(m_dServiceUtilization);
				/* keep the comment for only reference of dictionaryEnumerator. The following code is replaced by the lines below.
				IDictionaryEnumerator dictionaryEnumerator = m_jobStatisticsTable.GetEnumerator();
				int iJobStats = m_jobStatisticsTable==null?0:m_jobStatisticsTable.Count;
				JobStatistics[] mCurrentJobStatistics = new JobStatistics[iJobStats];
				int i = 0;
				while(dictionaryEnumerator.MoveNext()){
					try{
						mCurrentJobStatistics[i] = (JobStatistics)dictionaryEnumerator.Value;
						i++;
					}
					catch(Exception){
						mCurrentJobStatistics[i] = null;
					}
				}
				if(iJobStats > 0){
					osplWriter.setJobStatistics(mCurrentJobStatistics);
				}
				*/

				int iCurrentJobs = m_vCurrentJobIDs.Count;
				int iWaitingJobs = m_vWaitingJobIDs.Count;
				int iFinishedJobs = m_vFinishedJobIDs.Count;
						
				int iJobs =  iCurrentJobs + iWaitingJobs + iFinishedJobs;
				JobStatistics[] mAllJobStatistics = new JobStatistics[iJobs];
				int j = 0;
				for(int i = iCurrentJobs-1; i >= 0 ; i--){
					try{
						mAllJobStatistics[j] = (JobStatistics)m_jobStatisticsTable[(string)m_vCurrentJobIDs[i]];
						j++;
					}
					catch(Exception){
					}
				}
				for(int i = iWaitingJobs-1; i >= 0 ; i--){
					try{
						mAllJobStatistics[j] = (JobStatistics)m_jobStatisticsTable[(string)m_vWaitingJobIDs[i]];
						j++;
					}
					catch(Exception){
					}
				}
				for(int i = iFinishedJobs-1; i >= 0 ; i--){
					try{
						mAllJobStatistics[j] = (JobStatistics)m_jobStatisticsTable[(string)m_vFinishedJobIDs[i]];
						j++;
					}
					catch(Exception){
					}
				}
				if(iJobs > 0){
					osplWriter.setJobStatistics(mAllJobStatistics);
				}

				osplWriter.writeToFile(OSParameter.PROCESS_FILE+"_backup");
				return true;
			
			}
			catch(Exception e){
				IOUtil.log(e.ToString(), null);
				return false;
			}
		}//saveOSpL 

		/// <summary>
		/// clear up jobs from the three queues in memory and also files from the disk.
		/// </summary>
		/// <returns>whether the jobs are cleared up successfully.</returns>
		protected internal static bool clearUpJobs(){
			int iCurrentJobs = (m_vCurrentJobIDs==null?0:m_vCurrentJobIDs.Count);
			string[] msCurrentJobIDs = new string[iCurrentJobs];
			for(int i = iCurrentJobs-1; i >= 0; i--){
				try	{
					msCurrentJobIDs[i] = (string)m_vCurrentJobIDs[i];
				}
				catch(Exception){
					msCurrentJobIDs[i] = "";
				}
			}

			for(int i = 0; i < iCurrentJobs; i++){
				String sJobID = msCurrentJobIDs[i];
				if(sJobID == null || sJobID.Length <= 0){
					continue;
				}
				if(!m_vCurrentJobIDs.Contains(sJobID)){
					continue;
				}
				OSServiceUtil osServiceUtil = new OSServiceUtil();						
				osServiceUtil.m_sJobID = sJobID;

				long lNow = CommonUtil.currentTimeMillis();						
				JobStatistics jobStatistics = (JobStatistics)m_jobStatisticsTable[sJobID];
				if(jobStatistics == null){
					jobStatistics = new JobStatistics();
					jobStatistics.jobID = sJobID;
					m_jobStatisticsTable.Add(sJobID, jobStatistics);
				}
				if(jobStatistics.startTime.Year <= 1970){
					jobStatistics.startTime = DateTime.Now;
				}
				if((lNow - CommonUtil.timeMillis(jobStatistics.startTime))/1000 > OSParameter.JOB_MAX_TIME){	
					try {
						string sOptionFile = OSParameter.TEMP_FILE_FOLDER+sJobID+".osol";
						string sOSoL = IOUtil.readStringFromFile(sOptionFile);
						if(sOSoL == null || sOSoL.Length <= 0 || !osServiceUtil.readOSoL(sOSoL)){
							OSoLWriter osolWriter = new OSoLWriter();
							osolWriter.setServiceURI(OSParameter.SERVICE_URI);
							osolWriter.setServiceName(OSParameter.SERVICE_NAME);
							osolWriter.setJobID(sJobID);
							osolWriter.setPassword(OSParameter.getSystemPassword());
							osolWriter.setServiceType(OSParameter.SERVICE_TYPE);
							sOSoL = osolWriter.writeToString();
						}
						osServiceUtil.kill(sOSoL);		
					} 
					catch (Exception e) {
						IOUtil.log(e.ToString(), null);
						osServiceUtil.m_sJobID = sJobID;
						osServiceUtil.m_sJobID = sJobID;
						osServiceUtil.postprocess(true);
					}	
				}
			}
			m_iCurrentJobCount = m_vCurrentJobIDs.Count;

			while(m_vCurrentJobIDs.Count > OSParameter.MAX_JOB_NUMBERS){
				string sJobID = "";
				try {
					sJobID = (string)m_vCurrentJobIDs[0];
				} 
				catch (Exception) {
					break;
				}

				OSServiceUtil osServiceUtil = new OSServiceUtil();						
				osServiceUtil.m_sJobID = sJobID;

				try {
					string sOptionFile = OSParameter.TEMP_FILE_FOLDER+sJobID+".osol";
					string sOSoL = IOUtil.readStringFromFile(sOptionFile);
					if(sOSoL == null || sOSoL.Length <= 0 || !osServiceUtil.readOSoL(sOSoL)){
						OSoLWriter osolWriter = new OSoLWriter();
						osolWriter.setServiceURI(OSParameter.SERVICE_URI);
						osolWriter.setServiceName(OSParameter.SERVICE_NAME);
						osolWriter.setJobID(sJobID);
						osolWriter.setPassword(OSParameter.getSystemPassword());
						osolWriter.setServiceType(OSParameter.SERVICE_TYPE);
						sOSoL = osolWriter.writeToString();
					}
					osServiceUtil.kill(sOSoL);		
				} 
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
					IOUtil.log(e.ToString(), null);
					osServiceUtil.m_sJobID = sJobID;
					osServiceUtil.postprocess(true);
				}
			}
			m_iCurrentJobCount = m_vCurrentJobIDs.Count;
		
			while(m_vWaitingJobIDs.Count > OSParameter.MAX_WAITING_NUMBERS){
				try {
					string sJobID = (string)m_vWaitingJobIDs[0];
					removeWaitingJob(sJobID);
				} 
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}
			}

			while(m_vFinishedJobIDs.Count > OSParameter.MAX_JOBIDS_TO_KEEP){
				try {
					string sJobID = (string)m_vFinishedJobIDs[0];
					m_vFinishedJobIDs.RemoveAt(0);
					m_jobStatisticsTable.Remove(sJobID);
					string sInstanceFile = OSParameter.TEMP_FILE_FOLDER+sJobID+".osil";
					string sOptionFile = OSParameter.TEMP_FILE_FOLDER+sJobID+".osol";
					string sResultFile = OSParameter.TEMP_FILE_FOLDER+sJobID+".osrl";
					string sDatFile = OSParameter.BACKUP_FOLDER+sJobID+".dat";
					string sTxtFile = OSParameter.BACKUP_FOLDER+sJobID+".txt";
					string sTmpFile = OSParameter.BACKUP_FOLDER+sJobID+".tmp";
					string sInstanceFileBackup = OSParameter.BACKUP_FOLDER+sJobID+".osil";
					string sOptionFileBackup = OSParameter.BACKUP_FOLDER+sJobID+".osol";
					string sResultFileBackup = OSParameter.BACKUP_FOLDER+sJobID+".osrl";
					IOUtil.deleteFile(sDatFile);
					IOUtil.deleteFile(sTxtFile);
					IOUtil.deleteFile(sTmpFile);

					IOUtil.deleteFile(sInstanceFile);
					IOUtil.deleteFile(sOptionFile);				
				} 
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}
			}		
			return true;
		}//clearUpJobs

		/// <summary>
		/// update process statistics  
		/// </summary>
		/// <returns>whether the process statistics is updated successfully or not.</returns>
		protected internal static bool updateProcessStatistics(){
			IDictionaryEnumerator dictionaryEnumerator = m_jobStatisticsTable.GetEnumerator();
			while(dictionaryEnumerator.MoveNext()){
				try{
					string sJobID = (string)dictionaryEnumerator.Key;
					JobStatistics jobStatistics = (JobStatistics)dictionaryEnumerator.Value;
					//make sure all jobStatistics are not null
					if(jobStatistics == null){
						jobStatistics = new JobStatistics();
						if(OSParameter.SERVICE_TYPE == null || OSParameter.SERVICE_TYPE.Length <= 0 || 
							OSParameter.SERVICE_TYPE.Equals("solver") || OSParameter.SERVICE_TYPE.Equals("analyzer")){
							jobStatistics.serviceURI = OSParameter.SERVICE_URI;
						}
						m_jobStatisticsTable.Add(sJobID, jobStatistics);
					}
					//make sure all jobStatistics have jobIDs
					jobStatistics.jobID = sJobID;

					//make sure serviceURI is correct
					if(jobStatistics.serviceURI == null){
						jobStatistics.serviceURI = "";
					}
					if(jobStatistics.serviceURI.Equals(OSParameter.OS_SCHEDULER_SITE)){
						jobStatistics.serviceURI = "";
					}

					//make sure all jobStatistics have states: waiting, running, finished/killed
					if(jobStatistics.state == null || jobStatistics.state.Length <= 0 || jobStatistics.state.Equals("unknown")){
						if(m_vFinishedJobIDs.Contains(sJobID)){
							jobStatistics.state = "finished";
						}
						else if(m_vCurrentJobIDs.Contains(sJobID)){
							jobStatistics.state = "running";
						}
						else{
							jobStatistics.state = "waiting";
							m_vWaitingJobIDs.Remove(sJobID);
							m_vWaitingJobIDs.Add(sJobID);
						}
					}
					//make sure all jobs are in one of the three queues (waiting, running, finished/killed)
					if(jobStatistics.state.Equals("running")){
						if(!m_vCurrentJobIDs.Contains(sJobID)){
							if(m_threadHashTable.ContainsKey(sJobID)|| (OSParameter.SERVICE_TYPE != null && OSParameter.SERVICE_TYPE.Equals("scheduler"))){
								m_vCurrentJobIDs.Add(sJobID);							
							}
							else{
								jobStatistics.state = "waiting";
								m_vWaitingJobIDs.Remove(sJobID);
								m_vWaitingJobIDs.Add(sJobID);	
							}
						}
					}
					else if(jobStatistics.state.Equals("waiting")){
						if(!m_vWaitingJobIDs.Contains(sJobID)){
							m_vWaitingJobIDs.Add(sJobID);
						}
					}
					else if(jobStatistics.state.Equals("killed") || jobStatistics.state.Equals("finished")){
						if(!m_vFinishedJobIDs.Contains(sJobID)){
							m_vFinishedJobIDs.Add(sJobID);
						}
						//update time related values
						if(jobStatistics.endTime.Year <= 1970){
							jobStatistics.endTime = DateTime.Now;
							if(jobStatistics.startTime.Year > 1970){
								jobStatistics.duration = (CommonUtil.timeMillis(jobStatistics.endTime) - CommonUtil.timeMillis(jobStatistics.startTime))/1000;
							}
						}
						if(jobStatistics.duration < 0 && jobStatistics.endTime.Year > 1970 && jobStatistics.startTime.Year > 1970){
							jobStatistics.duration = (CommonUtil.timeMillis(jobStatistics.endTime) - CommonUtil.timeMillis(jobStatistics.startTime))/1000;
						}
					}
					else{
						jobStatistics.state = "waiting";
						m_vWaitingJobIDs.Remove(sJobID);
						m_vWaitingJobIDs.Add(sJobID);
					}				
				}
				catch(Exception e){
					IOUtil.log(e.ToString(), null);
				}
			}
			m_iCurrentJobCount = m_vCurrentJobIDs.Count;
			//make sure each job is only in one queue. 
			//make sure that all jobs have a corresponding job statistics
			//make sure running jobs are in thread table.
			int iFinishedJobs = m_vFinishedJobIDs.Count;

			for(int i = 0; i < iFinishedJobs; i++){
				string sJobID = "";
				try {
					sJobID = (string)m_vFinishedJobIDs[i];				
				} 
				catch (Exception){
					break;
				}
				if(sJobID == null || sJobID.Length <= 0){
					break;
				}

				JobStatistics jobStatistics = (JobStatistics)m_jobStatisticsTable[sJobID];
				if(jobStatistics == null){
					jobStatistics = new JobStatistics();
					jobStatistics.jobID = sJobID;
					jobStatistics.endTime = DateTime.Now;
					if(OSParameter.SERVICE_TYPE == null || OSParameter.SERVICE_TYPE.Length <= 0 || 
						OSParameter.SERVICE_TYPE.Equals("solver") || OSParameter.SERVICE_TYPE.Equals("analyzer")){
						jobStatistics.serviceURI = OSParameter.SERVICE_URI;
					}
					m_jobStatisticsTable.Add(sJobID, jobStatistics);
				}
				if(jobStatistics.state == null || !(jobStatistics.state.Equals("finished") || jobStatistics.state.Equals("killed"))){
					jobStatistics.state = "finished";
				}
				m_vWaitingJobIDs.Remove(sJobID);
				if(m_vCurrentJobIDs.Contains(sJobID)){
					if(m_threadHashTable.ContainsKey(sJobID)|| (OSParameter.SERVICE_TYPE != null && OSParameter.SERVICE_TYPE.Equals("scheduler"))){
						m_vFinishedJobIDs.Remove(sJobID);
						jobStatistics.state = "running";
						jobStatistics.endTime = new DateTime(1970, 1, 1, 0, 0, 0);
					}
					else{					
						m_vCurrentJobIDs.Remove(sJobID);

					}
				}
			}
			m_iCurrentJobCount = m_vCurrentJobIDs.Count;

			//make sure that all jobs in the waiting queue have a corresponding job statistics
			int iWaitingJobs = m_vWaitingJobIDs.Count;
			for(int i = 0; i < iWaitingJobs; i++){
				string sJobID = "";
				try {
					sJobID = (string)m_vWaitingJobIDs[i];				
				} 
				catch (Exception) {
					break;
				}
				if(sJobID == null || sJobID.Length <= 0){
					break;
				}
				JobStatistics jobStatistics = (JobStatistics)m_jobStatisticsTable[sJobID];
				if(jobStatistics == null){
					jobStatistics = new JobStatistics();
					jobStatistics.jobID = sJobID;
					if(OSParameter.SERVICE_TYPE == null || OSParameter.SERVICE_TYPE.Length <= 0 || 
						OSParameter.SERVICE_TYPE.Equals("solver") || OSParameter.SERVICE_TYPE.Equals("analyzer")){
						jobStatistics.serviceURI = OSParameter.SERVICE_URI;
					}
					m_jobStatisticsTable.Add(sJobID, jobStatistics);
				}
				if(jobStatistics.state == null || !jobStatistics.state.Equals("waiting")){
					jobStatistics.state = "waiting";
				}
				if(m_vCurrentJobIDs.Contains(sJobID)|| (OSParameter.SERVICE_TYPE != null && OSParameter.SERVICE_TYPE.Equals("scheduler"))){
					if(m_threadHashTable.ContainsKey(sJobID)){
						m_vWaitingJobIDs.Remove(sJobID);
						jobStatistics.state = "running";
					}
					else{					
						m_vCurrentJobIDs.Remove(sJobID);

					}
				}
			}
			m_iCurrentJobCount = m_vCurrentJobIDs.Count;

			//make sure that all jobs in the running queue have a corresponding job statistics
			int iCurrentJobs = m_vCurrentJobIDs.Count;
			for(int i = 0; i < iCurrentJobs; i++){
				string sJobID = "";
				try {
					sJobID = (string)m_vCurrentJobIDs[i];				
				} 
				catch (Exception) {
					break;
				}
				if(sJobID == null || sJobID.Length <= 0){
					break;
				}
				JobStatistics jobStatistics = (JobStatistics)m_jobStatisticsTable[sJobID];
				if(jobStatistics == null){
					jobStatistics = new JobStatistics();
					jobStatistics.jobID = sJobID;
					if(OSParameter.SERVICE_TYPE == null || OSParameter.SERVICE_TYPE.Length <= 0 || 
						OSParameter.SERVICE_TYPE.Equals("solver") || OSParameter.SERVICE_TYPE.Equals("analyzer")){
						jobStatistics.serviceURI = OSParameter.SERVICE_URI;
					}
					m_jobStatisticsTable.Add(sJobID, jobStatistics);
				}
				if(jobStatistics.state == null || !jobStatistics.state.Equals("running")){
					jobStatistics.state = "running";
				}
			}
			m_iCurrentJobCount = m_vCurrentJobIDs.Count;

			//update user statistics
			bool bSuccess = true;
			iCurrentJobs = (m_vCurrentJobIDs==null?0:m_vCurrentJobIDs.Count);
			iWaitingJobs = (m_vWaitingJobIDs==null?0:m_vWaitingJobIDs.Count);
			int iUnfinishedJobs = iCurrentJobs + iWaitingJobs;
			string[] msUnfinishedJobIDs = new String[iUnfinishedJobs];
			int j = 0;
			for(int i = 0; i < iCurrentJobs; i++){
				try{
					msUnfinishedJobIDs[j] = (string)m_vCurrentJobIDs[i];
					j++;
					if(m_vCurrentJobIDs.Count != iCurrentJobs){
						bSuccess = false;
						break;
					}
				}
				catch(Exception){
					bSuccess = false;
					break;
				}
			}
			if(bSuccess){
				for(int i = 0; i < iWaitingJobs; i++){
					try{
						msUnfinishedJobIDs[j] = (string)m_vWaitingJobIDs[i];
						j++;
						if(m_vWaitingJobIDs.Count != iWaitingJobs){
							bSuccess = false;
							break;
						}
					}
					catch(Exception){
						bSuccess = false;
						break;
					}
				}
			}
			if(bSuccess){
				m_userJobCountTable = new Hashtable();
				for(int i = 0; i < iUnfinishedJobs; i++){
					JobStatistics jobStatistics = (JobStatistics)m_jobStatisticsTable[msUnfinishedJobIDs[i]];
					string sUserName = "";
					if(jobStatistics != null){
						sUserName = jobStatistics.userName;					
					}
					if(sUserName == null){
						sUserName = "";
					}
					string sCount = (string)m_userJobCountTable[sUserName];
					int iCount;
					if(sCount == null || sCount.Length <= 0){
						iCount = 0;
					}
					else{
						try {
							iCount = Int32.Parse(sCount);					
						} 
						catch (Exception) {
							iCount = 0;
						}
						if(iCount < 0) iCount = 0;
					}
					if(m_vWaitingJobIDs.Contains(msUnfinishedJobIDs[i]) || m_vCurrentJobIDs.Contains(msUnfinishedJobIDs[i])){
						iCount += 1;
						m_userJobCountTable.Remove(sUserName);
						m_userJobCountTable.Add(sUserName, iCount+"");				
					}
				}
			}

			//update stats
			m_dServiceUtilization = (m_lTotalBusyTime/(CommonUtil.currentTimeMillis() - m_lTimeServiceStarted));
			try{
				m_dAvailableDiskSpace = IOUtil.getFreeDiskSpace(OSParameter.CODE_DRIVE);	
			}
			catch(Exception e){
				IOUtil.log(e.ToString(), null);
				m_dAvailableDiskSpace = Double.PositiveInfinity;
			}
			try{
				m_dAvailableMemory = ProcessUtil.getFreeMemory();	
			}
			catch(Exception e){
				IOUtil.log(e.ToString(), null);
				m_dAvailableMemory = Double.PositiveInfinity;
			}
		
			if(m_dAvailableDiskSpace <= OSParameter.MINIMUM_DISKSPACE_TRIGGER ||
				m_dAvailableMemory <= ((double)OSParameter.MINIMUM_MEMORY_TRIGGER)){
				if(m_iCurrentJobCount > 0){
					m_sCurrentState = "busy";				
				}
				else{
					m_sCurrentState = "idleButNotAccepting";
				}
			}
			else{
				if(m_iCurrentJobCount == 0){
					m_sCurrentState = "idle";
				}
				else if(m_iCurrentJobCount >= OSParameter.MAX_JOB_NUMBERS){
					m_sCurrentState = "busy";
				}
				else{
					m_sCurrentState = "busyButAccepting";
				}
			}
			return true;
		}//updateProcessStatistics 

		/// <summary>
		/// <c>SolverThread</c> is an internal thread controlled by <c>OSServiceUtil</c>.
		/// </summary>
		protected internal class SolverThread{		
			/// <summary>
			/// m_osServiceUtil holds the the OSServiceUtil instance. 
			/// It is mainly for member field access between the inner and outer class. 
			/// </summary>
			protected internal OSServiceUtil m_osServiceUtil = null;

			/// <summary>
			/// m_bCalledFromSend holds whether the SolverThread is called from solve or send.
			/// </summary>
			protected internal bool m_bCalledFromSend = false; 

			/// <summary>
			/// m_msURIs holds the found service URIs.  
			/// </summary>
			protected internal string[] m_msURIs = null;

			/// <summary>
			/// m_sOSiL holds the osil string.
			/// </summary>
			protected internal string m_sOSiL = null;
		
			/// <summary>
			/// m_sOSoL holds the osol string.
			/// </summary>
			protected internal string m_sOSoL = null;

			/// <summary>
			/// m_osOption holds the parsed OSOption data structure read from the OSoL string.
			/// </summary>
			protected internal OSOption m_osOption = null;

			/// <summary>
			/// m_sOSrL holds osrl string.
			/// </summary>
			protected internal string m_sOSrL = null;
	 
			/// <summary>
			/// default constructor.
			/// </summary>
			protected internal SolverThread(){
			}//constructor

			/// <summary>
			/// A synchronous call method is implemented here. 
			/// </summary>
			protected internal virtual void solve(){
				Monitor.Enter(this);
				Thread thread = Thread.CurrentThread;
				string sTime = XMLUtil.createXSDateTime(DateTime.Now);
				IOUtil.log("thread name: "+thread.Name+":"+":"+ sTime, null);

				//updateRegistry
				m_osServiceUtil.updateRegistry(true);

				//save ospl
				saveOSpL();

				//solver
				if(m_osServiceUtil.serviceType == null || m_osServiceUtil.serviceType.Length <= 0 || 
					m_osServiceUtil.serviceType.Equals("solver") || m_osServiceUtil.serviceType.Equals("analyzer")){
					//make sure solver is registered
					if(m_osServiceUtil.solver == null){
						try {
							string sSolverClassName = OSParameter.SOLVER_CLASS_NAME; 
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
					}
					if(m_osServiceUtil.solver != null){
						//presolve
						m_osServiceUtil.presolve(m_sOSiL, m_sOSoL);

						//prepare osol
						m_osServiceUtil.solver.osol = this.m_sOSoL;
						m_osServiceUtil.solver.osOption = m_osOption;


						//prepare osil
						if(m_osServiceUtil.m_sInstanceAddress != null && m_osServiceUtil.m_sInstanceAddress.Length > 0 && (m_sOSiL == null || m_sOSiL.Length <= 0)){
							if(m_osServiceUtil.m_sInstanceLocationType == null || m_osServiceUtil.m_sInstanceLocationType.Length <= 0 || m_osServiceUtil.m_sInstanceLocationType.Equals("local")){
								if(OSParameter.SAVE_INPUTS){
									string sInstanceFile = OSParameter.TEMP_FILE_FOLDER+m_osServiceUtil.m_sJobID+".osil";
									bool bCopy  = IOUtil.copyFile(m_osServiceUtil.m_sInstanceAddress, sInstanceFile);
									if(! bCopy){
										IOUtil.log("not able to copy file from " + m_osServiceUtil.m_sInstanceAddress + " to " +  sInstanceFile, null);	
									}
								}
								m_sOSiL = IOUtil.readStringFromFile(m_osServiceUtil.m_sInstanceAddress);
								if(m_sOSiL == null || m_sOSiL.Length <= 0){
									m_sOSiL = "";
									IOUtil.log("not able to read from file " + m_osServiceUtil.m_sInstanceAddress, null);								
								}
							}
							else if(m_osServiceUtil.m_sInstanceLocationType.Equals("http")){
								m_sOSiL = IOUtil.readStringFromURL(m_osServiceUtil.m_sInstanceAddress);
								if(m_sOSiL == null || m_sOSiL.Length <= 0){
									m_sOSiL = "";
									IOUtil.log("not able to read from file " + m_osServiceUtil.m_sInstanceAddress, null);								
								}
								if(OSParameter.SAVE_INPUTS){
									string sInstanceFile = OSParameter.TEMP_FILE_FOLDER+m_osServiceUtil.m_sJobID+".osil";
									bool bSave  = IOUtil.writeStringToFile(m_sOSiL, sInstanceFile);
									if(!bSave){
										IOUtil.log("not able to save osil string to " +  sInstanceFile, null);	
									}							
								}
							}

						}
						try{
							m_osServiceUtil.solver.osil = this.m_sOSiL;
							if(m_osServiceUtil.solver.osInstance == null && m_osServiceUtil.solver.osil != null && m_osServiceUtil.solver.osil.Length > 0 && OSParameter.PARSE_INSTANCE_INPUT){
								OSiLReader osilReader = new OSiLReader(OSParameter.VALIDATE);
								bool bRead = osilReader.readString(this.m_sOSiL);
								if(bRead){
									m_osServiceUtil.solver.osInstance = osilReader.getOSInstance();							
								}
							}				
						}
						catch(Exception){}

						//start solve
						for(int i = 0; i < OSParameter.MAXIMUM_TRIAL_NUMBER_FOR_SOLVE; i++){
							try{
								m_osServiceUtil.m_solver.solve();
								if(m_osServiceUtil.solver.osResult != null || (m_osServiceUtil.solver.osrl != null && m_osServiceUtil.solver.osrl.Length > 0)){
									break;
								}
							}
							catch(Exception e){
								IOUtil.log(e.ToString(), null);
							}
							if(i < OSParameter.MAXIMUM_TRIAL_NUMBER_FOR_SOLVE - 1){
								try{
									Random random = new Random();
									System.Threading.Thread.Sleep((int)(random.NextDouble()*
										(OSParameter.MAXIMUM_WAIT_TIME_BEFORE_NEXT_TRIAL-OSParameter.MINIMUM_WAIT_TIME_BEFORE_NEXT_TRIAL)
										+OSParameter.MINIMUM_WAIT_TIME_BEFORE_NEXT_TRIAL));
								}
								catch (Exception){}
							}
						}

						//prepare osrl
						try{
							if(m_osServiceUtil.solver.osResult != null && (m_osServiceUtil.solver.osrl == null || m_osServiceUtil.solver.osrl.Length <= 0)){
								try {
									m_osServiceUtil.solver.osrl = m_osServiceUtil.solver.osResult.writeOSrL();
								} 
								catch (Exception e) {
									IOUtil.log(e.ToString(), null);
								}
							}
							if(m_osServiceUtil.solver.osrl != null && m_osServiceUtil.solver.osrl.Length > 0){
								m_sOSrL = m_osServiceUtil.solver.osrl;
								string sResultFile = OSParameter.TEMP_FILE_FOLDER+m_osServiceUtil.m_sJobID+".osrl";
								bool bWrite = IOUtil.writeStringToFile(m_sOSrL, sResultFile);
								if(!bWrite){
									IOUtil.log("standard output file not written successfully", null);
								}
							}
							else{
								IOUtil.log("no result returned from solver", null);
								m_osServiceUtil.m_osrlWriter = new OSrLWriter();
								m_osServiceUtil.m_osrlWriter.setGeneralStatusType("error");
								m_osServiceUtil.m_osrlWriter.setGeneralStatusDescription("no result returned from the solver");
								m_osServiceUtil.m_osrlWriter.setServiceURI(OSParameter.SERVICE_URI);
								m_osServiceUtil.m_osrlWriter.setServiceName(OSParameter.SERVICE_NAME);
								m_osServiceUtil.m_osrlWriter.setJobID(m_osServiceUtil.m_sJobID);
								m_osServiceUtil.m_osrlWriter.setResultTime(DateTime.Now);
								m_sOSrL = m_osServiceUtil.m_osrlWriter.writeToString();
							}
						}
						catch(Exception e){
							IOUtil.log(e.ToString(), null);
							m_osServiceUtil.m_osrlWriter = new OSrLWriter();
							m_osServiceUtil.m_osrlWriter.setGeneralStatusType("warning");
							m_osServiceUtil.m_osrlWriter.setGeneralStatusDescription(e.Message);
							m_osServiceUtil.m_osrlWriter.setServiceURI(OSParameter.SERVICE_URI);
							m_osServiceUtil.m_osrlWriter.setServiceName(OSParameter.SERVICE_NAME);
							m_osServiceUtil.m_osrlWriter.setJobID(m_osServiceUtil.m_sJobID);
							m_osServiceUtil.m_osrlWriter.setResultTime(DateTime.Now);
							m_osServiceUtil.m_osrlWriter.setGeneralMessage(e.ToString());
							m_sOSrL = m_osServiceUtil.m_osrlWriter.writeToString();
							string sResultFile = OSParameter.TEMP_FILE_FOLDER+m_osServiceUtil.m_sJobID+".osrl";
							bool bWrite = IOUtil.writeStringToFile(m_sOSrL, sResultFile);
							if(!bWrite){
								IOUtil.log("standard output file not written successfully", null);
							}
						}
					
						//postsolve
						m_osServiceUtil.postsolve();
				
						//postprocess
						m_osServiceUtil.postprocess(false);
					}
					else{//no solver engine
						m_osServiceUtil.postprocess(false);					
					}
				}//solver
					
				//scheduler
				else{
					int iURI = (m_msURIs == null)?0:m_msURIs.Length;
					//save inputs
					string sInstanceFile = OSParameter.TEMP_FILE_FOLDER+m_osServiceUtil.m_sJobID+".osil";
					string sOptionFile = OSParameter.TEMP_FILE_FOLDER+m_osServiceUtil.m_sJobID+".osol";
					bool bWrite = true;
					if(!IOUtil.existsFileOrDir(sInstanceFile)){
						bWrite = IOUtil.writeStringToFile(m_sOSiL, sInstanceFile);
					}
					if(!bWrite){
						IOUtil.log("the solve method is not able to write osil to file", null);
						IOUtil.deleteFile(sInstanceFile);
					}
					bWrite = true;
					if(!IOUtil.existsFileOrDir(sOptionFile)){
						bWrite = IOUtil.writeStringToFile(m_sOSoL, sOptionFile);
					}
					if(!bWrite){
						IOUtil.log("the solve method is not able to write osol to file", null);
						IOUtil.deleteFile(sOptionFile);
					}

					JobStatistics jobStatistics  = (JobStatistics)m_jobStatisticsTable[m_osServiceUtil.m_sJobID];
					if(jobStatistics == null){
						m_osServiceUtil.initializeStatistics();
						jobStatistics  = (JobStatistics)m_jobStatisticsTable[m_osServiceUtil.m_sJobID];
					}

					//called from send
					if(m_bCalledFromSend){
						bool bSend = false;
						for(int i = 0; i < iURI; i++){
							try {
								string sServiceType = m_osOption.getServiceType();
								string sContactTransportType = m_osOption.getServiceType();
								string sContactAddress = m_osOption.getContactAddress();
								m_osOption.setServiceType("scheduler");	
								m_osOption.setContactTransportType("osp");
								m_osOption.setContactAddress(OSParameter.SERVICE_URI);
								string sOSoL = m_osOption.writeOSoL();
								m_osOption.setServiceType(sServiceType);	
								m_osOption.setContactTransportType(sContactTransportType);
								m_osOption.setContactAddress(sContactAddress);

								OSSolverAgent solverAgent = new OSSolverAgent();
								solverAgent.solverAddress = m_msURIs[i];
								bSend = solverAgent.send(m_sOSiL, m_sOSoL);
								jobStatistics.serviceURI = m_msURIs[i];
								if(bSend){
									break;
								}
								else{
									IOUtil.log("job not sent successfully", null);
								}
							}
							catch (Exception e) {
								IOUtil.log(e.ToString(), null);
							}
						}
						if(bSend){
							m_threadHashTable.Remove(m_osServiceUtil.m_sJobID);
							m_solverThreadHashTable.Remove(m_osServiceUtil.m_sJobID);
							processsHashTable.Remove(m_osServiceUtil.m_sJobID);
							m_vWaitingJobIDs.Remove(m_osServiceUtil.m_sJobID);
							m_vCurrentJobIDs.Remove(m_osServiceUtil.m_sJobID);
							m_vCurrentJobIDs.Add(m_osServiceUtil.m_sJobID);						
							m_iCurrentJobCount = m_vCurrentJobIDs.Count;
						
							if(m_iCurrentJobCount >= OSParameter.MAX_JOB_NUMBERS){
								m_sCurrentState = "busy";
							}
							else if(m_iCurrentJobCount > 0){
								m_sCurrentState = "busyButAccepting";
							}
							else {
								m_sCurrentState = "idle";
							}

							jobStatistics.jobID = m_osServiceUtil.m_sJobID;
							jobStatistics.state = "running";
							m_osServiceUtil.m_sJobState = jobStatistics.state;
							if(jobStatistics.userName == null || jobStatistics.userName.Length <= 0){
								jobStatistics.userName = m_osServiceUtil.m_sUserName;		
							}
							if(jobStatistics.submitTime.Year <= 1970){
								jobStatistics.submitTime = DateTime.Now; 
							}
							m_osServiceUtil.m_lJobSubmitTime = CommonUtil.timeMillis(jobStatistics.submitTime);			

							jobStatistics.startTime = DateTime.Now;
							m_osServiceUtil.m_lJobStartTime = CommonUtil.timeMillis(jobStatistics.startTime);

							jobStatistics.endTime = new DateTime(1970, 1, 1, 0, 0, 0); 
							m_osServiceUtil.m_lJobEndTime = -1;

							jobStatistics.duration = Double.NaN;
							m_osServiceUtil.m_lJobDuration = -1;
						}
						else{
							//put on wait list
							m_threadHashTable.Remove(m_osServiceUtil.m_sJobID);
							m_solverThreadHashTable.Remove(m_osServiceUtil.m_sJobID);
							processsHashTable.Remove(m_osServiceUtil.m_sJobID);
							m_vCurrentJobIDs.Remove(m_osServiceUtil.m_sJobID);
							m_vWaitingJobIDs.Remove(m_osServiceUtil.m_sJobID);
							m_vWaitingJobIDs.Add(m_osServiceUtil.m_sJobID);	
							m_iCurrentJobCount = m_vCurrentJobIDs.Count;
						
							if(m_iCurrentJobCount >= OSParameter.MAX_JOB_NUMBERS){
								m_sCurrentState = "busy";
							}
							else if(m_iCurrentJobCount > 0){
								m_sCurrentState = "busyButAccepting";
							}
							else {
								m_sCurrentState = "idle";
							}

							jobStatistics.jobID = m_osServiceUtil.m_sJobID;
							jobStatistics.state = "waiting";
							m_osServiceUtil.m_sJobState = jobStatistics.state;
							jobStatistics.serviceURI = "";			
							if(jobStatistics.userName == null || jobStatistics.userName.Length <= 0){
								jobStatistics.userName = m_osServiceUtil.m_sUserName;		
							}						
							if(jobStatistics.submitTime.Year <= 1970){
								jobStatistics.submitTime = DateTime.Now; 
							}
							m_osServiceUtil.m_lJobSubmitTime = CommonUtil.timeMillis(jobStatistics.submitTime);			

							jobStatistics.startTime = new DateTime(1970, 1, 1, 0, 0, 0); 
							m_osServiceUtil.m_lJobStartTime = -1;

							jobStatistics.endTime = new DateTime(1970, 1, 1, 0, 0, 0); 
							m_osServiceUtil.m_lJobEndTime = -1;

							jobStatistics.duration = Double.NaN;
							m_osServiceUtil.m_lJobDuration = -1;
						}
						//save ospl
						saveOSpL();

						//updateRegistry
						m_osServiceUtil.updateRegistry(true);

					}
					//called from solve
					else{
						bool bSolved = false;
						bool bWarning = false;
						for(int i = 0; i < iURI; i++){
							try {
								string sServiceType = m_osOption.getServiceType();
								string sContactTransportType = m_osOption.getServiceType();
								string sContactAddress = m_osOption.getContactAddress();
								m_osOption.setServiceType("scheduler");	
								m_osOption.setContactTransportType("osp");
								m_osOption.setContactAddress(OSParameter.SERVICE_URI);
								string sOSoL = m_osOption.writeOSoL();
								m_osOption.setServiceType(sServiceType);	
								m_osOption.setContactTransportType(sContactTransportType);
								m_osOption.setContactAddress(sContactAddress);

								OSSolverAgent solverAgent = new OSSolverAgent();
								solverAgent.solverAddress = m_msURIs[i];
								jobStatistics.serviceURI = m_msURIs[i];
								m_sOSrL = solverAgent.solve(m_sOSiL, m_sOSoL);
								if(m_sOSrL != null && m_sOSrL.Length > 0){
									try {
										OSrLReader osrlReader = new OSrLReader(m_osServiceUtil.m_bValidate);
										bool bRead = osrlReader.readString(m_sOSrL);
										if(bRead){
											bSolved = true;
											string sStatus = osrlReader.getGeneralStatusType();
											if(sStatus != null && sStatus.Equals("warning")) bWarning = true;
											break;
										}
										else{
											IOUtil.log("result not read successfully", null);
										}
									} 
									catch (Exception e) {
										IOUtil.log(e.ToString(), null);
									}
								}
								else{
									IOUtil.log("empty result returned", null);
								}
							} 
							catch (Exception e) {
								IOUtil.log(e.ToString(), null);
							}
							//alwasy kill the remote process when the solve is finished. 
							//If the remote solver has already finished the job, it is ok as the remote solver will simply return. 
							KillThread killThread = new KillThread();
							OSSolverAgent osSolverAgent = new OSSolverAgent(m_msURIs[i]);
							killThread.m_osSolverAgent = osSolverAgent;
							killThread.m_sOSoL = m_sOSoL;
							Thread thread0 = new Thread(new ThreadStart(killThread.kill));
							thread.Start();
						}
						if(bSolved && !bWarning){
							string sResultFile = OSParameter.TEMP_FILE_FOLDER+m_osServiceUtil.m_sJobID+".osrl";
							bWrite = IOUtil.writeStringToFile(m_sOSrL, sResultFile);
							if(!bWrite){
								IOUtil.log("not able to save file " + m_osServiceUtil.m_sJobID, null);
							}							
						}
						else{
							IOUtil.log("not able to get a solver to solve the problem", null);
							m_osServiceUtil.m_osrlWriter = new OSrLWriter();
							m_osServiceUtil.m_osrlWriter.setGeneralStatusType("warning");
							m_osServiceUtil.m_osrlWriter.setGeneralStatusDescription("not able to get a solver to solve the problem");
							m_osServiceUtil.m_osrlWriter.setServiceURI(OSParameter.SERVICE_URI);
							m_osServiceUtil.m_osrlWriter.setServiceName(OSParameter.SERVICE_NAME);
							m_osServiceUtil.m_osrlWriter.setJobID(m_osServiceUtil.m_sJobID);
							m_osServiceUtil.m_osrlWriter.setResultTime(DateTime.Now);
							m_sOSrL = m_osServiceUtil.m_osrlWriter.writeToString();
						}
						//postprocess
						m_osServiceUtil.postprocess(false);
					}
				}//scheduler		

				Monitor.Pulse(this);
				Monitor.Exit(this);
			}//solve
		}//class SolverThread

		/// <summary>
		/// <c>SimulationThread</c> is an internal thread controlled by <c>CGSolverService</c>.
		/// </summary>
		protected internal class SimulationThread{

			/// <summary>
			/// m_sOSsLInput holds the ossl input string.
			/// </summary>
			protected internal string m_sOSsLInput = null;
		
			/// <summary>
			/// m_sOSoL holds the osol string.
			/// </summary>
			protected internal string m_sOSoL = null;

			/// <summary>
			/// m_sOSsLOutput holds the ossl output string.
			/// </summary>
			protected internal string m_sOSsLOutput = null;

			/// <summary>
			/// m_simulation holds the simulation engine.
			/// </summary>
			protected internal DefaultSimulation m_simulation = null;
	 
			/// <summary>
			/// default constructor.
			/// </summary>
			protected internal SimulationThread(){
			}//constructor

			/// <summary>
			/// A synchronous simulation call method is implemented here. 
			/// </summary>
			protected internal virtual void call(){
				Monitor.Enter(this);		
				Thread thread = Thread.CurrentThread;
				string sTime = XMLUtil.createXSDateTime(DateTime.Now);
				IOUtil.log("thread name:"+thread.Name+":"+":"+sTime, null);
				try{
					m_simulation.osslInput = this.m_sOSsLInput;
					if(m_simulation.osSimulationInput == null && m_simulation.osslInput != null){
						OSsLReader osslReader = new OSsLReader(OSParameter.VALIDATE);
						osslReader.readString(this.m_sOSsLInput);
						m_simulation.osSimulationInput = osslReader.getOSSimulation();
					}				
				}
				catch(Exception e){
					IOUtil.log(e.ToString(), null);
				}
				try{
					m_simulation.osol = this.m_sOSoL;
					if(m_simulation.osOption == null && m_simulation.osol != null){
						OSoLReader osolReader = new OSoLReader(OSParameter.VALIDATE);
						osolReader.readString(this.m_sOSoL);
						m_simulation.osOption = osolReader.getOSOption();
					}				
				}
				catch(Exception e){
					IOUtil.log(e.ToString(), null);
				}

				try{
					m_simulation.call();
				}
				catch(Exception e){
					IOUtil.log(e.ToString(), null);
				}

				try{
					if(m_simulation.osslOutput != null){
						m_sOSsLOutput = m_simulation.osslOutput;
					}
					else if(m_simulation.osSimulationOutput != null){
						OSsLWriter osslWriter = new OSsLWriter();
						osslWriter.setOSSimulation(m_simulation.osSimulationOutput);
						m_simulation.osslOutput = osslWriter.writeToString();
					}
					else{
						throw new Exception("no result returned");
					}
				}
				catch(Exception e){
					IOUtil.log(e.ToString(), null);
				}

				Monitor.Pulse(this);
				Monitor.Exit(this);
			}//call
		}//class SimulationThread

		/// <summary>
		/// an internal timer task called by <c>OSServiceUtil</c>.
		/// The task is relatively short. 
		/// </summary>
		/// <param name="source">holds the event source.</param>
		/// <param name="e">holds the event arguments.</param>
		internal static void serviceTask1(object source, ElapsedEventArgs e){
			//process waiting jobs
			ProcessWaitingJobsThread processWaitingJobsThread = new ProcessWaitingJobsThread();
			Thread thread = new Thread(new ThreadStart(processWaitingJobsThread.processWaitingJobs));	
			thread.Start();

			//send periodic warning
			if(m_dAvailableDiskSpace <= OSParameter.MINIMUM_DISKSPACE_TRIGGER){
				if(m_bSendEmailOnLowDiskSpace){
					string sMessage = "System warning: service (" + (OSParameter.SERVICE_URI) +") is running low on disk space (" + m_dAvailableDiskSpace + ")";
					MailUtil.sendInThread(OSParameter.FROM_EMAIL, OSParameter.TO_EMAIL, null, null, "System Warning: low disk space", sMessage, null);
					m_bSendEmailOnLowDiskSpace = true;
				}
			}
			else{
				m_bSendEmailOnLowDiskSpace = false;
			}

			//save ospl
			saveOSpL();
		}//serviceTask1

		/// <summary>
		/// an internal timer task called by <c>OSServiceUtil</c>.
		/// The task is carried out periodically in intervals that are neither too short nor too long. 
		/// </summary>
		/// <param name="source">holds the event source.</param>
		/// <param name="e">holds the event arguments.</param>
		internal static void serviceTask2(object source, ElapsedEventArgs e){
			//update process statistics
			updateProcessStatistics();

			//clear up jobs (from memory and disks)
			clearUpJobs();

			//clean up disk
			IOUtil.cleanUpDisk();

			//save ospl
			saveOSpL();

			//check scheduler's current jobs statistics
			if(OSParameter.SERVICE_TYPE != null && OSParameter.SERVICE_TYPE.Equals("scheduler")){
				CheckSchedulerCurrentJobsThread checkSchedulerCurrentJobsThread = new CheckSchedulerCurrentJobsThread();
				Thread thread = new Thread(new ThreadStart(checkSchedulerCurrentJobsThread.checkSchedulerCurrentJobs));	
				thread.Start();
			}

		}//serviceTask2

		/// <summary>
		/// an internal timer task called by <c>OSServiceUtil</c>.
		/// The task is carried out in long intervals periodically.
		/// </summary>
		/// <param name="source">holds the event source.</param>
		/// <param name="e">holds the event arguments.</param>
		internal static void serviceTask3(object source, ElapsedEventArgs e){
			try{
				m_dAvailableDiskSpace = IOUtil.getFreeDiskSpace(OSParameter.CODE_DRIVE);	
			}
			catch(Exception){
				m_dAvailableDiskSpace = Double.PositiveInfinity;
			}
			try{
				System.GC.Collect();
				m_dAvailableMemory = ProcessUtil.getFreeMemory();	
			}
			catch(Exception){
				m_dAvailableMemory = Double.PositiveInfinity;
			}
			saveOSpL();
			//send process info to admin. 
			string sSubject = "Service Status [" + OSParameter.SERVICE_URI + "]";
			string sProcessFileName = OSParameter.PROCESS_FILE+"_backup";
			string sMessage = IOUtil.readStringFromFile(sProcessFileName);
			if(sMessage == null || sMessage.Length <= 0){
				sMessage = "Not able to retrieve process info of the service [" + OSParameter.SERVICE_URI + "]"; 
			}
			MailUtil.sendInThread(OSParameter.FROM_EMAIL, OSParameter.TO_EMAIL, null, null, sSubject, sMessage, null );					

		}//serviceTask3

		/// <summary>
		/// static constructor
		/// </summary>
		static OSServiceUtil(){
			if(OSParameter.SERVICE_TYPE == null || !OSParameter.SERVICE_TYPE.Equals("registry")){
				m_sSystemPassword = OSParameter.getSystemPassword();

				m_lTimeServiceStarted = CommonUtil.currentTimeMillis();
				try{
					m_dAvailableDiskSpace = IOUtil.getFreeDiskSpace(OSParameter.CODE_DRIVE);	
				}
				catch(Exception e){
					IOUtil.log(e.ToString(), null);
					m_dAvailableDiskSpace = Double.PositiveInfinity;
				}
				try{
					m_dAvailableMemory = ProcessUtil.getFreeMemory();	
				}
				catch(Exception e){
					IOUtil.log(e.ToString(), null);
					m_dAvailableMemory = Double.PositiveInfinity;
				}
				//load ospl information from backup file if it is more updated
				OSpLReader osplReader = new OSpLReader();
				string sFileName = OSParameter.PROCESS_FILE;
				string sBackupFileName = sFileName+"_backup";
				try {
					if((!IOUtil.existsFileOrDir(sFileName) && IOUtil.existsFileOrDir(sBackupFileName)) || 
						(IOUtil.existsFileOrDir(sBackupFileName) && IOUtil.getLastWriteTime(sBackupFileName) > IOUtil.getLastWriteTime(sFileName))){
						IOUtil.copyFile(sBackupFileName, sFileName);				
					}
					if(IOUtil.existsFileOrDir(sFileName)){
						bool bRead = osplReader.readFile(sFileName);
						if(bRead){
							ProcessStatistics processStatistics = osplReader.getProcessStatistics();
							JobStatistics[] mJobStatistics = (processStatistics==null || processStatistics.jobs==null)?null:processStatistics.jobs.job;
						
							int iJobs = mJobStatistics==null?0:mJobStatistics.Length;
						
						
							for(int i = iJobs-1; i >= 0; i--){						
								if(mJobStatistics[i] != null && mJobStatistics[i].jobID != null && mJobStatistics[i].jobID.Length > 0){
									if(m_jobStatisticsTable.ContainsKey(mJobStatistics[i].jobID)){
										continue;
									}
									m_jobStatisticsTable.Add(mJobStatistics[i].jobID, mJobStatistics[i]);
									if(mJobStatistics[i].state == null || mJobStatistics[i].state.Length <= 0 || mJobStatistics[i].state.Equals("unknown")){
										mJobStatistics[i].state = "waiting";
									}
									if(mJobStatistics[i].state.Equals("finished") || mJobStatistics[i].state.Equals("killed")){
										m_vFinishedJobIDs.Remove(mJobStatistics[i].jobID);
										m_vFinishedJobIDs.Add(mJobStatistics[i].jobID);
									}
									else{
										m_iTotalJobsSoFar++;
										string sUserName = mJobStatistics[i].userName;
										if(sUserName == null){
											sUserName = "";
										}
										string sCount = (string)m_userJobCountTable[sUserName];
										int iCount;
										if(sCount == null || sCount.Length <= 0){
											iCount = 0;
										}
										else{
											try {
												iCount = Int32.Parse(sCount);					
											} 
											catch (Exception) {
												iCount = 0;
											}
											if(iCount < 0) iCount = 0;
										}
										iCount += 1;
										m_userJobCountTable.Remove(sUserName);
										m_userJobCountTable.Add(sUserName, iCount+"");
									}
									if(mJobStatistics[i].state.Equals("waiting") || mJobStatistics[i].state.Equals("unknown")){ 
										m_vWaitingJobIDs.Remove(mJobStatistics[i].jobID);
										m_vWaitingJobIDs.Add(mJobStatistics[i].jobID);
										mJobStatistics[i].state = "waiting";
									}
									if(mJobStatistics[i].state.Equals("running")){
										if(OSParameter.SERVICE_TYPE == null || !OSParameter.SERVICE_TYPE.Equals("scheduler")){
											m_vWaitingJobIDs.Remove(mJobStatistics[i].jobID);
											m_vWaitingJobIDs.Add(mJobStatistics[i].jobID);
											mJobStatistics[i].state = "waiting";
										}
										else{
											if(mJobStatistics[i].serviceURI == null || mJobStatistics[i].serviceURI.Length <= 0){
												m_vWaitingJobIDs.Remove(mJobStatistics[i].jobID);
												m_vWaitingJobIDs.Add(mJobStatistics[i].jobID);
												mJobStatistics[i].state = "waiting";										
											}
											else{
												m_vCurrentJobIDs.Remove(mJobStatistics[i].jobID);
												m_vCurrentJobIDs.Add(mJobStatistics[i].jobID);
											}
										}
									}
								}					
							}
							m_iCurrentJobCount = m_vCurrentJobIDs.Count;
							if(m_iCurrentJobCount == 0){
								m_sCurrentState = "idle";
							}
							else if(m_iCurrentJobCount >= OSParameter.MAX_JOB_NUMBERS){
								m_sCurrentState = "busy";
							}
							else{
								m_sCurrentState = "busyButAccepting";
							}
						}
					}
				} 
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}
			
				saveOSpL();

				new OSServiceUtil().updateRegistry(false);

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

	}//class OSServiceUtil

}//namespace



