using System;
using System.Collections;
using System.Xml;

using org.optimizationservices.oscommon.util;
using org.optimizationservices.oscommon.localinterface;
using org.optimizationservices.oscommon.datastructure.osprocess;
using org.optimizationservices.oscommon.datastructure.osgeneral;
using org.optimizationservices.oscommon.representationparser;

namespace org.optimizationservices.oscommon.representationparser{
	///	<summary>
	///	The	<c>OSpLReader</c> class	parses an OSpL instance	into a DOM tree	and
	///	provides a set of "get"	methods	that can be	
	///	used to	retrieve different pieces of information of	the	instance.
	///	@author	Jun	Ma	
	///	@version 1.0, 09/01/2005
	///	@since OS 1.0
	///	@copyright (c) 2005
	///	</summary>
	public class OSpLReader	: OSgLReader{	
		/// <summary>
		/// m_osProcess holds the standard OSProcess, which is a local interface for 
		/// storing Optimization Services process. 
		/// </summary>
		protected OSProcess m_osProcess = null;

		///	<summary>
		///	m_otherProcessHashMap holds a hash map of other alalyses.
		///	</summary>
		protected Hashtable	m_otherProcessHashMap = null;

		///	<summary>
		///	m_otherProcessDescriptionHashMap holds a hash map of other processes' descriptions.
		///	</summary>
		protected Hashtable	m_otherProcessDescriptionHashMap = null;

		///	<summary>
		///	constructor.
		///	</summary>
		///	<param name="validate">holds whether the reader	should be validating against the schema	or not.</param>
		public OSpLReader(bool validate){
			m_bXsdValidate = validate;
		}//constructor
	
		///	<summary>
		///	Default	constructor. 
		///	</summary>
		public OSpLReader(){
		}//constructor

		/// <summary>
		/// get the standard OSProcess, a local interface for 
		/// storing Optimization Services process.
		/// </summary>
		/// <returns>the OSProcess. </returns>
		public OSProcess getOSProcess(){
			if(m_osProcess != null){
				return m_osProcess;
			}
			m_osProcess = new OSProcess();
			string sRequestAction = getRequestAction();
			string sResponseStatus = getResponseStatus();
			if(sRequestAction != null && sRequestAction.Length > 0){
				if(!m_osProcess.setRequestAction(getRequestAction())) throw new Exception("setRequestAction Unsuccessful");
				if(!m_osProcess.setRequestDescription(getRequestDescription())) throw new Exception("setRequestDescription Unsuccessful");
			}
			else if(sResponseStatus != null && sResponseStatus.Length > 0){
				if(!m_osProcess.setResponseStatus(getResponseStatus())) throw new Exception("setResponseStatus Unsuccessful");
				if(!m_osProcess.setResponseDescription(getResponseDescription())) throw new Exception("setResponseDescription Unsuccessful");
			}
			if(!m_osProcess.setServiceURI(getServiceURI())) throw new Exception("setServiceURI Unsuccessful");
			if(!m_osProcess.setServiceName(getServiceName())) throw new Exception("setServiceName Unsuccessful");
			if(!m_osProcess.setProcessTime(getProcessTime())) throw new Exception("setProcessTime Unsuccessful");
			if(!m_osProcess.setProcessMessage(getProcessMessage())) throw new Exception("setProcessMessage Unsuccessful");
			if(!m_osProcess.setProcessStatistics(getProcessStatistics())) throw new Exception("setProcessStatistics Unsuccessful");
			if(!m_osProcess.setOptimizationProcess(getOptimizationProcess()))throw new Exception("setOptimizationProcess Unsuccessful");
			if(!m_osProcess.setOtherProcesses(getOtherProcessNames(), getOtherProcessDescriptions(), getOtherProcessValues())) throw new Exception("setOtherEntityInfo Unsuccessful");

			return m_osProcess;
		}//getOSProcess

		/// <summary>
		/// Get the request action, which can be: 
		/// ping, notifyJobCompletion, requestJob, getServiceStatistics, setServiceStatistics, 
		/// getJobStatistics, setJobStatistics, getOptimization, setOptimization, getAll, setAll. 
		/// </summary>
		/// <returns>the request action, null or empty string if none. </returns>
		public string getRequestAction(){
			XmlElement eProcessHeader = (XmlElement)XMLUtil.findChildNode(m_eRoot, "processHeader");
			XmlElement eRequest = (XmlElement)XMLUtil.findChildNode(eProcessHeader, "request");
			if(eRequest == null) return null;
			string sRequestAction = eRequest.GetAttribute("action");
			return sRequestAction;
		}//getRequestAction

		/// <summary>
		/// Get the request description.
		/// </summary>
		/// <returns>the request description, null or empty string if none. </returns>
		public string getRequestDescription(){
			XmlElement eProcessHeader = (XmlElement)XMLUtil.findChildNode(m_eRoot, "processHeader");
			XmlElement eRequest = (XmlElement)XMLUtil.findChildNode(eProcessHeader, "request");
			if(eRequest == null) return null;
			string sRequestDescription = XMLUtil.getElementValue(eRequest);
			return sRequestDescription;
		}//getRequestDescription

		/// <summary>
		/// Get the response status, which can be: 
		/// success, error, warning. 
		/// </summary>
		/// <returns>the response status, null or empty string if none. </returns>
		public string getResponseStatus(){
			XmlElement eProcessHeader = (XmlElement)XMLUtil.findChildNode(m_eRoot, "processHeader");
			XmlElement eResponse = (XmlElement)XMLUtil.findChildNode(eProcessHeader, "response");
			if(eResponse == null) return null;
			string sResponseStatus = eResponse.GetAttribute("status");
			return sResponseStatus;
		}//getResponseStatus

		/// <summary>
		/// Get the response description.
		/// </summary>
		/// <returns>the response description, null or empty string if none. </returns>
		public string getResponseDescription(){
			XmlElement eProcessHeader = (XmlElement)XMLUtil.findChildNode(m_eRoot, "processHeader");
			XmlElement eResponse = (XmlElement)XMLUtil.findChildNode(eProcessHeader, "response");
			if(eResponse == null) return null;
			string sResponseDescription = XMLUtil.getElementValue(eResponse);
			return sResponseDescription;
		}//getResponseDescription

		/// <summary>
		/// Get service uri.
		/// </summary>
		/// <returns>the service uri. </returns>
		public string getServiceURI(){
			XmlElement eProcessHeader = (XmlElement)XMLUtil.findChildNode(m_eRoot, "processHeader");
			string sServiceURI = XMLUtil.getElementValueByName(eProcessHeader, "serviceURI");
			if(sServiceURI == null) sServiceURI = "";
			return sServiceURI;	
		}//getServiceURI

		/// <summary>
		/// Get service name.
		/// </summary>
		/// <returns>the service name. </returns>
		public string getServiceName(){
			XmlElement eProcessHeader = (XmlElement)XMLUtil.findChildNode(m_eRoot, "processHeader");
			string sServiceName = XMLUtil.getElementValueByName(eProcessHeader, "serviceName");
			if(sServiceName == null) sServiceName = "";
			return sServiceName;	
		}//getServiceName

		/// <summary>
		/// Get time of the last process update.
		/// </summary>
		/// <returns>the time of the last process update.</returns>
		public DateTime getProcessTime(){
			XmlElement eProcessHeader = (XmlElement)XMLUtil.findChildNode(m_eRoot, "processHeader");
			string sProcessDate = XMLUtil.getElementValueByName(eProcessHeader, "time");
			if(sProcessDate == null) return new DateTime(1970, 1, 1, 0, 0, 0);
			DateTime date = XMLUtil.createNativeDateTime(sProcessDate);
			return date;
		}//getProcessTime


		/// <summary>
		/// Get the process message. 
		/// </summary>
		/// <returns>the process message. </returns>
		public string getProcessMessage(){
			XmlElement eProcessHeader = (XmlElement)XMLUtil.findChildNode(m_eRoot, "processHeader");
			string sMessage = XMLUtil.getElementValueByName(eProcessHeader, "message");
			if(sMessage == null) sMessage = "";
			return sMessage;
		}//getProcessMessage


		/// <summary>
		/// Get the process statistics. 
		/// </summary>
		/// <returns>the process statistics. </returns>
		public ProcessStatistics getProcessStatistics(){
			XmlElement eProcessData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "processData");
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(eProcessData, "statistics");
			if(eStatistics == null) return null;
			ProcessStatistics processStatistics = new ProcessStatistics();
			string sValue = "";
			int iValue;
			double dValue;
			sValue =  XMLUtil.getElementValueByName(eStatistics, "currentState");
			if(sValue != null && sValue.Length > 0){
				processStatistics.currentState = sValue;
			}
			try {
				sValue =  XMLUtil.getElementValueByName(eStatistics, "availableDiskSpace");
				if(sValue != null && sValue.Length > 0){
					if(sValue.Equals("INF")) {
						processStatistics.availableDiskSpace = Double.PositiveInfinity;
					}
					else{
						dValue = Double.Parse(sValue);
						processStatistics.availableDiskSpace = dValue;
					}
				}
			} 
			catch (Exception) {
				processStatistics.availableDiskSpace = Double.NaN;
			}
			try {
				sValue =  XMLUtil.getElementValueByName(eStatistics, "availableMemory");
				if(sValue != null && sValue.Length > 0){
					if(sValue.Equals("INF")) {
						processStatistics.availableMemory = Double.PositiveInfinity;
					}
					else{
						dValue = Double.Parse(sValue);
						processStatistics.availableMemory = dValue;
					}
				}
			} 
			catch (Exception) {
				processStatistics.availableMemory = Double.NaN;
			}
			try {
				sValue =  XMLUtil.getElementValueByName(eStatistics, "currentJobCount");
				if(sValue != null && sValue.Length > 0){
					iValue = Int32.Parse(sValue);
					processStatistics.currentJobCount = iValue;
				}
			} 
			catch (Exception) {
				processStatistics.currentJobCount = -1;
			}
			try {
				sValue =  XMLUtil.getElementValueByName(eStatistics, "totalJobsSoFar");
				if(sValue != null && sValue.Length > 0){
					iValue = Int32.Parse(sValue);
					processStatistics.totalJobsSoFar = iValue;
				}
			} 
			catch (Exception) {
				processStatistics.totalJobsSoFar = -1;
			}
			try {
				sValue =  XMLUtil.getElementValueByName(eStatistics, "timeLastJobEnded");
				if(sValue != null && sValue.Length > 0){
					processStatistics.timeLastJobEnded = XMLUtil.createNativeDateTime(sValue);
				}
			} 
			catch (Exception) {
				processStatistics.timeLastJobEnded = new DateTime(1970, 1, 1, 0, 0, 0);
			}
			try {
				sValue =  XMLUtil.getElementValueByName(eStatistics, "timeLastJobTook");
				if(sValue != null && sValue.Length > 0){
					if(sValue.Equals("INF")) {
						processStatistics.timeLastJobTook = Double.PositiveInfinity;
					}
					else{
						dValue = Double.Parse(sValue);
						processStatistics.timeLastJobTook = dValue;
					}
				}
			} 
			catch (Exception) {
				processStatistics.timeLastJobTook = Double.NaN;
			}
			try {
				sValue =  XMLUtil.getElementValueByName(eStatistics, "timeServiceStarted");
				if(sValue != null && sValue.Length > 0){
					processStatistics.timeServiceStarted = XMLUtil.createNativeDateTime(sValue);
				}
			} 
			catch (Exception) {
				processStatistics.timeServiceStarted = new DateTime(1970, 1, 1, 0, 0, 0);
			}
			try {
				sValue =  XMLUtil.getElementValueByName(eStatistics, "serviceUtilization");
				if(sValue != null && sValue.Length > 0){
					if(sValue.Equals("INF")) {
						processStatistics.serviceUtilization = Double.PositiveInfinity;
					}
					else{
						dValue = Double.Parse(sValue);
						processStatistics.serviceUtilization = dValue;
					}
				}
			} 
			catch (Exception) {
				processStatistics.serviceUtilization = Double.NaN;
			}
			XmlElement eJobs = (XmlElement)XMLUtil.findChildNode(eStatistics, "jobs");
			if(eJobs == null) return processStatistics;
			XmlNodeList jobList = eJobs.GetElementsByTagName("job");
			if(jobList == null || jobList.Count <= 0) return processStatistics;
			processStatistics.jobs = new Jobs();
			int iJobs = jobList.Count;
			processStatistics.jobs.job = new JobStatistics[iJobs];
			for(int i = 0; i < iJobs; i++){
				processStatistics.jobs.job[i] = new JobStatistics();
				XmlElement eJob = (XmlElement)jobList.Item(i);
				sValue =  eJob.GetAttribute("jobID");
				if(sValue != null && sValue.Length > 0){
					processStatistics.jobs.job[i].jobID = sValue;
				}
				sValue =  XMLUtil.getElementValueByName(eJob, "state");
				if(sValue != null && sValue.Length > 0){
					processStatistics.jobs.job[i].state = sValue;
				}
				sValue =  XMLUtil.getElementValueByName(eJob, "serviceURI");
				if(sValue != null && sValue.Length > 0){
					processStatistics.jobs.job[i].serviceURI = sValue;
				}
				sValue =  XMLUtil.getElementValueByName(eJob, "userName");
				if(sValue != null && sValue.Length > 0){
					processStatistics.jobs.job[i].userName = sValue;
				}
				try {
					sValue =  XMLUtil.getElementValueByName(eJob, "submitTime");
					if(sValue != null && sValue.Length > 0){
						processStatistics.jobs.job[i].submitTime = XMLUtil.createNativeDateTime(sValue);
					}
				} 
				catch (Exception) {
					processStatistics.jobs.job[i].submitTime = new DateTime(1970, 1, 1, 0, 0, 0);
				}
				try {
					sValue =  XMLUtil.getElementValueByName(eJob, "startTime");
					if(sValue != null && sValue.Length > 0){
						processStatistics.jobs.job[i].startTime = XMLUtil.createNativeDateTime(sValue);
					}
				} 
				catch (Exception) {
					processStatistics.jobs.job[i].startTime = new DateTime(1970, 1, 1, 0, 0, 0);
				}
				try {
					sValue =  XMLUtil.getElementValueByName(eJob, "endTime");
					if(sValue != null && sValue.Length > 0){
						processStatistics.jobs.job[i].endTime = XMLUtil.createNativeDateTime(sValue);
					}
				} 
				catch (Exception) {
					processStatistics.jobs.job[i].endTime = new DateTime(1970, 1, 1, 0, 0, 0);
				}
				try {
					sValue =  XMLUtil.getElementValueByName(eJob, "duration");
					if(sValue != null && sValue.Length > 0){
						if(sValue.Equals("INF")) {
							processStatistics.jobs.job[i].duration = Double.PositiveInfinity;
						}
						else{
							dValue = Double.Parse(sValue);
							processStatistics.jobs.job[i].duration = dValue;
						}
					}
				} 
				catch (Exception) {
					processStatistics.jobs.job[i].duration = Double.NaN;
				}
				try {
					sValue =  XMLUtil.getElementValueByName(eJob, "scheduledStartTime");
					if(sValue != null && sValue.Length > 0){
						processStatistics.jobs.job[i].scheduledStartTime = XMLUtil.createNativeDateTime(sValue);
					}
				} 
				catch (Exception) {
					processStatistics.jobs.job[i].scheduledStartTime = new DateTime(1970, 1, 1, 0, 0, 0);
				}
				XmlElement eDependencies = (XmlElement)XMLUtil.findChildNode(eJob, "dependencies");
				if(eDependencies != null){
					XmlNodeList jobIDList = eDependencies.GetElementsByTagName("jobID");
					if(jobIDList != null && jobIDList.Count > 0){
						int iJobIDs = jobIDList.Count;
						processStatistics.jobs.job[i].dependencies = new JobDependencies();
						processStatistics.jobs.job[i].dependencies.jobID = new string[iJobIDs];
						for(int j = 0; j < iJobIDs; j++){
							XmlElement eJobID = (XmlElement)jobIDList.Item(j);
							processStatistics.jobs.job[i].dependencies.jobID[j] =  XMLUtil.getElementValue(eJobID);
						}
					}
				}
				XmlElement eRequiredDirectoriesAndFiles = (XmlElement)XMLUtil.findChildNode(eJob, "requiredDirectoriesAndFiles");			
				if(eRequiredDirectoriesAndFiles != null){
					XmlNodeList pathList = eRequiredDirectoriesAndFiles.GetElementsByTagName("path");
					if(pathList != null && pathList.Count > 0){
						int iPaths = pathList.Count;
						processStatistics.jobs.job[i].requiredDirectoriesAndFiles = new DirectoriesAndFiles();
						processStatistics.jobs.job[i].requiredDirectoriesAndFiles.path = new string[iPaths];
						for(int j = 0; j < iPaths; j++){
							XmlElement ePath = (XmlElement)pathList.Item(j);
							processStatistics.jobs.job[i].requiredDirectoriesAndFiles.path[j] =  XMLUtil.getElementValue(ePath);
						}				
					}
				}
			}
			return processStatistics;
		}//getProcessStatistics

		/// <summary>
		/// Get the current state, , which can be:
		/// "busy", "busyButAccepting", "idle", "idleButNotAccepting" and "noResponse".
		/// </summary>
		/// <returns>the current status, "noResponse" if none.</returns>
		public string getCurrentState(){
			XmlElement eProcessData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "processData");
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(eProcessData, "statistics");
			if(eStatistics == null) return "noResponse";
			string sValue =  XMLUtil.getElementValueByName(eStatistics, "currentState");
			if(sValue == null || sValue.Length <= 0){
				return "noResponse";
			}
			return sValue;
		}//getCurrentState

		/// <summary>
		/// Get the available disk space (in bytes). 
		/// </summary>
		/// <returns>the available disk space, Double.NaN if none. </returns>
		public double getAvailableDiskSpace(){
			XmlElement eProcessData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "processData");
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(eProcessData, "statistics");
			if(eStatistics == null) return Double.NaN;
			string sValue =  XMLUtil.getElementValueByName(eStatistics, "availableDiskSpace");
			Double dValue;
			if(sValue == null || sValue.Length <= 0){
				return Double.NaN;
			}		
			try {
				if(sValue.Equals("INF")) {
					dValue = Double.PositiveInfinity;
				}
				else{
					dValue = Double.Parse(sValue);
				}
			}
			catch (Exception) {
				dValue = Double.NaN;
			}
			return dValue;
		}//getAvailableDiskSpace

		/// <summary>
		/// Get the available memory (in bytes). 
		/// </summary>
		/// <returns>the available memory, Double.NaN if none. </returns>
		public double getAvailableMemory(){
			XmlElement eProcessData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "processData");
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(eProcessData, "statistics");
			if(eStatistics == null) return Double.NaN;
			string sValue =  XMLUtil.getElementValueByName(eStatistics, "availableMemory");
			Double dValue;
			if(sValue == null || sValue.Length <= 0){
				return Double.NaN;
			}		
			try {
				if(sValue.Equals("INF")) {
					dValue = Double.PositiveInfinity;
				}
				else{
					dValue = Double.Parse(sValue);
				}
			}
			catch (Exception) {
				dValue = Double.NaN;
			}
			return dValue;
		}//getAvailableMemory

		/// <summary>
		/// Get the current job count. 
		/// </summary>
		/// <returns>the current job count, -1 if none. </returns>
		public int getCurrentJobCount(){
			XmlElement eProcessData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "processData");
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(eProcessData, "statistics");
			if(eStatistics == null) return -1;
			string sValue =  XMLUtil.getElementValueByName(eStatistics, "currentJobCount");
			int iValue;
			if(sValue == null || sValue.Length <= 0){
				return -1;
			}		
			try {
				iValue = Int32.Parse(sValue);
			}
			catch (Exception) {
				iValue = -1;
			}
			return iValue;
		}//getCurrentJobCount

		/// <summary>
		/// Get the total jobs received so far. 
		/// </summary>
		/// <returns>the total jobs received so far, -1 if none. </returns>
		public int getTotalJobsSoFar(){
			XmlElement eProcessData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "processData");
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(eProcessData, "statistics");
			if(eStatistics == null) return -1;
			string sValue =  XMLUtil.getElementValueByName(eStatistics, "totalJobsSoFar");
			int iValue;
			if(sValue == null || sValue.Length <= 0){
				return -1;
			}		
			try {
				iValue = Int32.Parse(sValue);
			}
			catch (Exception) {
				iValue = -1;
			}
			return iValue;
		}//getTotalJobsSoFar

		/// <summary>
		/// Get the time last job ended. 
		/// </summary>
		/// <returns>the time last job ended. If none, it returns unix creation time: DateTime(1970, 1, 1, 0, 0, 0). </returns>
		public DateTime getTimeLastJobEnded(){
			XmlElement eProcessData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "processData");
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(eProcessData, "statistics");
			if(eStatistics == null) return new DateTime(1970, 1, 1, 0, 0, 0);
			string sValue =  XMLUtil.getElementValueByName(eStatistics, "timeLastJobEnded");
			if(sValue == null || sValue.Length <= 0) return new DateTime(1970, 1, 1, 0, 0, 0);
			try{
				DateTime time = XMLUtil.createNativeDateTime(sValue);
				return time;
			}
			catch(Exception){
				return new DateTime(1970, 1, 1, 0, 0, 0);
			}
		}//getTimeLastJobEnded

		/// <summary>
		/// Get the time last job took (in seconds). 
		/// </summary>
		/// <returns>the the time last job took, Double.NaN if none. </returns>
		public double getTimeLastJobTook(){
			XmlElement eProcessData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "processData");
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(eProcessData, "statistics");
			if(eStatistics == null) return Double.NaN;
			string sValue =  XMLUtil.getElementValueByName(eStatistics, "timeLastJobTook");
			Double dValue;
			if(sValue == null || sValue.Length <= 0){
				return Double.NaN;
			}		
			try {
				if(sValue.Equals("INF")) {
					dValue = Double.PositiveInfinity;
				}
				else{
					dValue = Double.Parse(sValue);
				}
			}
			catch (Exception) {
				dValue = Double.NaN;
			}
			return dValue;
		}//getTimeLastJobTook

		/// <summary>
		/// Get the time the service started. 
		/// </summary>
		/// <returns>the time last job ended. If none, it returns unix creation time: DateTime(1970, 1, 1, 0, 0, 0). </returns>
		public DateTime getTimeServiceStarted(){
			XmlElement eProcessData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "processData");
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(eProcessData, "statistics");
			if(eStatistics == null) return new DateTime(1970, 1, 1, 0, 0, 0);
			string sValue =  XMLUtil.getElementValueByName(eStatistics, "timeServiceStarted");
			if(sValue == null || sValue.Length <= 0) return new DateTime(1970, 1, 1, 0, 0, 0);
			try{
				DateTime time = XMLUtil.createNativeDateTime(sValue);
				return time;
			}
			catch(Exception){
				return new DateTime(1970, 1, 1, 0, 0, 0);
			}
		}//getTimeServiceStarted


		/// <summary>
		/// Get the service utilization ([0, 1]). 
		/// </summary>
		/// <returns>the the time last job took, Double.NaN if none. </returns>
		public double getServiceUtilization(){
			XmlElement eProcessData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "processData");
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(eProcessData, "statistics");
			if(eStatistics == null) return Double.NaN;
			string sValue =  XMLUtil.getElementValueByName(eStatistics, "serviceUtilization");
			Double dValue;
			if(sValue == null || sValue.Length <= 0){
				return Double.NaN;
			}		
			try {
				if(sValue.Equals("INF")) {
					dValue = Double.PositiveInfinity;
				}
				else{
					dValue = Double.Parse(sValue);
				}
			}
			catch (Exception) {
				dValue = Double.NaN;
			}
			return dValue;
		}//getServiceUtilization

		/// <summary>
		/// Get the statistics of all the jobs. 
		/// </summary>
		/// <returns>the statistics of all the jobs, which is an array of jobStatistics with
		///  each member corresponding to one job; null if none. 
		/// </returns>
		public JobStatistics[] getJobStatistics(){
			XmlElement eProcessData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "processData");
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(eProcessData, "statistics");
			if(eStatistics == null) return null;
			XmlElement eJobs = (XmlElement)XMLUtil.findChildNode(eStatistics, "jobs");
			if(eJobs == null) return null;
			XmlNodeList jobList = eJobs.GetElementsByTagName("job");
			if(jobList == null || jobList.Count <= 0) return null;
			Jobs jobs = new Jobs();
			int iJobs = jobList.Count;
			jobs.job = new JobStatistics[iJobs];
			String sValue = "";
			double dValue;
			for(int i = 0; i < iJobs; i++){
				jobs.job[i] = new JobStatistics();
				XmlElement eJob = (XmlElement)jobList.Item(i);
				sValue =  eJob.GetAttribute("jobID");
				if(sValue != null && sValue.Length > 0){
					jobs.job[i].jobID = sValue;
				}
				sValue =  XMLUtil.getElementValueByName(eJob, "state");
				if(sValue != null && sValue.Length > 0){
					jobs.job[i].state = sValue;
				}
				sValue =  XMLUtil.getElementValueByName(eJob, "serviceURI");
				if(sValue != null && sValue.Length > 0){
					jobs.job[i].serviceURI = sValue;
				}
				sValue =  XMLUtil.getElementValueByName(eJob, "userName");
				if(sValue != null && sValue.Length > 0){
					jobs.job[i].userName = sValue;
				}
				try {
					sValue =  XMLUtil.getElementValueByName(eJob, "submitTime");
					if(sValue != null && sValue.Length > 0){
						jobs.job[i].submitTime = XMLUtil.createNativeDateTime(sValue);
					}
				} 
				catch (Exception) {
					jobs.job[i].submitTime = new DateTime(1970, 1, 1, 0, 0, 0);
				}
				try {
					sValue =  XMLUtil.getElementValueByName(eJob, "startTime");
					if(sValue != null && sValue.Length > 0){
						jobs.job[i].startTime = XMLUtil.createNativeDateTime(sValue);
					}
				} 
				catch (Exception) {
					jobs.job[i].startTime = new DateTime(1970, 1, 1, 0, 0, 0);
				}
				try {
					sValue =  XMLUtil.getElementValueByName(eJob, "endTime");
					if(sValue != null && sValue.Length > 0){
						jobs.job[i].endTime = XMLUtil.createNativeDateTime(sValue);
					}
				} 
				catch (Exception) {
					jobs.job[i].endTime = new DateTime(1970, 1, 1, 0, 0, 0);
				}
				try {
					sValue =  XMLUtil.getElementValueByName(eJob, "duration");
					if(sValue != null && sValue.Length > 0){
						if(sValue.Equals("INF")) {
							jobs.job[i].duration = Double.PositiveInfinity;
						}
						else{
							dValue = Double.Parse(sValue);
							jobs.job[i].duration = dValue;
						}
					}
				} 
				catch (Exception) {
					jobs.job[i].duration = Double.NaN;
				}
				try {
					sValue =  XMLUtil.getElementValueByName(eJob, "scheduledStartTime");
					if(sValue != null && sValue.Length > 0){
						jobs.job[i].scheduledStartTime = XMLUtil.createNativeDateTime(sValue);
					}
				} 
				catch (Exception) {
					jobs.job[i].scheduledStartTime = new DateTime(1970, 1, 1, 0, 0, 0);
				}
				XmlElement eDependencies = (XmlElement)XMLUtil.findChildNode(eJob, "dependencies");
				if(eDependencies != null){
					XmlNodeList jobIDList = eDependencies.GetElementsByTagName("jobID");
					if(jobIDList != null && jobIDList.Count > 0){
						int iJobIDs = jobIDList.Count;
						jobs.job[i].dependencies = new JobDependencies();
						jobs.job[i].dependencies.jobID = new String[iJobIDs];
						for(int j = 0; j < iJobIDs; j++){
							XmlElement eJobID = (XmlElement)jobIDList.Item(j);
							jobs.job[i].dependencies.jobID[j] =  XMLUtil.getElementValue(eJobID);
						}
					}
				}
				XmlElement eRequiredDirectoriesAndFiles = (XmlElement)XMLUtil.findChildNode(eJob, "requiredDirectoriesAndFiles");			
				if(eRequiredDirectoriesAndFiles != null){
					XmlNodeList pathList = eRequiredDirectoriesAndFiles.GetElementsByTagName("path");
					if(pathList != null && pathList.Count > 0){
						int iPaths = pathList.Count;
						jobs.job[i].requiredDirectoriesAndFiles = new DirectoriesAndFiles();
						jobs.job[i].requiredDirectoriesAndFiles.path = new string[iPaths];
						for(int j = 0; j < iPaths; j++){
							XmlElement ePath = (XmlElement)pathList.Item(j);
							jobs.job[i].requiredDirectoriesAndFiles.path[j] =  XMLUtil.getElementValue(ePath);
						}				
					}
				}

			}
			return jobs.job;
		}//getJobStatistics

		/// <summary>
		/// Get the optimization process of all the jobs, which are in effect
		/// intermediate (or occasionally final) optimization results. The intermediate process 
		/// can be some pre-built standard optimization information and/or the standard OSrL (Optimization
		/// Services result Language.
		/// </summary>
		/// <returns>the optimization process, null if none. It contains an array, with each member 
		/// corresponding to an optimization job. Each optimization job has a job id string; 
		/// and contains some pre-built standard optimization information and/or 
		/// an optimization result, which data structure follow the OSrL schema.
		/// </returns>
		public OptimizationProcess getOptimizationProcess(){
			XmlElement eProcessData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "processData");
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(eProcessData, "optimization");
			if(eOptimization == null) return null;
			XmlNodeList jobList = eOptimization.GetElementsByTagName("job");
			if(jobList == null || jobList.Count <= 0) return null;
			int iJobs = jobList.Count;
			OptimizationProcess optimizqationProcess = new OptimizationProcess();
			JobOptimization[] mJobOptimization = new JobOptimization[iJobs]; 
			optimizqationProcess.job = mJobOptimization;
			for(int i = 0; i < iJobs; i++){
				mJobOptimization[i] = new JobOptimization();
				XmlElement eJob = (XmlElement)jobList.Item(i);

				XmlElement eStandard = (XmlElement)XMLUtil.findChildNode(eJob, "standard");
				if(eStandard == null){
					mJobOptimization[i].standard = null;
				}
				else{
					XmlNodeList updateList = eStandard.GetElementsByTagName("update");
					if(updateList != null && updateList.Count > 0){
						mJobOptimization[i].standard = new StandardOptimizationProcessInformation();
						int iUpdate = updateList.Count;
						mJobOptimization[i].standard.update = new OptimizationUpdate[iUpdate];
						String sValue = "";
						int iValue;
						double dValue;
						for(int j = 0; j < iUpdate; j++){
							mJobOptimization[i].standard.update[j] = new OptimizationUpdate();
							XmlElement eUpdate = (XmlElement)updateList.Item(j);
							sValue =  eUpdate.GetAttribute("objectiveIdx");
							if(sValue != null && sValue.Length > 0){
								try {
									iValue = Int32.Parse(sValue);
								} 
								catch (Exception) {
									iValue = -1;
								}
								if(iValue > 0){
									iValue = 0;
								}
								mJobOptimization[i].standard.update[j].ObjectiveIdx = iValue;
							}
							try {
								sValue =  XMLUtil.getElementValueByName(eUpdate, "updatedObjectiveValue");
								if(sValue != null && sValue.Length > 0){
									if(sValue.Equals("INF")) {
										mJobOptimization[i].standard.update[j].updatedObjectiveValue = Double.PositiveInfinity;
									}
									else if(sValue.Equals("-INF")) {
										mJobOptimization[i].standard.update[j].updatedObjectiveValue = Double.NegativeInfinity;
									}
									else{
										dValue = Double.Parse(sValue);
										mJobOptimization[i].standard.update[j].updatedObjectiveValue = dValue;
									}
								}
							} 
							catch (Exception) {
								mJobOptimization[i].standard.update[j].updatedObjectiveValue = Double.NaN;
							}

							try {
								sValue =  XMLUtil.getElementValueByName(eUpdate, "updatedObjectiveLowerBound");
								if(sValue != null && sValue.Length > 0){
									if(sValue.Equals("INF")) {
										mJobOptimization[i].standard.update[j].updatedObjectiveLowerBound = Double.PositiveInfinity;
									}
									else if(sValue.Equals("-INF")) {
										mJobOptimization[i].standard.update[j].updatedObjectiveLowerBound = Double.NegativeInfinity;
									}
									else{
										dValue = Double.Parse(sValue);
										mJobOptimization[i].standard.update[j].updatedObjectiveLowerBound = dValue;
									}
								}
							} 
							catch (Exception) {
								mJobOptimization[i].standard.update[j].updatedObjectiveLowerBound = Double.NaN;
							}

							try {
								sValue =  XMLUtil.getElementValueByName(eUpdate, "updatedObjectiveUpperBound");
								if(sValue != null && sValue.Length > 0){
									if(sValue.Equals("INF")) {
										mJobOptimization[i].standard.update[j].updatedObjectiveUpperBound = Double.PositiveInfinity;
									}
									else if(sValue.Equals("-INF")) {
										mJobOptimization[i].standard.update[j].updatedObjectiveUpperBound = Double.NegativeInfinity;
									}
									else{
										dValue = Double.Parse(sValue);
										mJobOptimization[i].standard.update[j].updatedObjectiveUpperBound = dValue;
									}
								}
							} 
							catch (Exception) {
								mJobOptimization[i].standard.update[j].updatedObjectiveUpperBound = Double.NaN;
							}

							XmlElement eUpdatedVariableValues = (XmlElement)XMLUtil.findChildNode(eUpdate, "updatedVariableValues");
							if(eUpdatedVariableValues != null){
								XmlNodeList varList = eUpdatedVariableValues.GetElementsByTagName("var");
								if(varList != null && varList.Count > 0){
									int iVars = varList.Count;
									mJobOptimization[i].standard.update[j].updatedVariableValues = new UpdatedVariableValues();
									mJobOptimization[i].standard.update[j].updatedVariableValues.var = new double[iVars];
									XmlElement eVar;
									for(int k = 0; k < iVars; k++){
										eVar = (XmlElement)varList.Item(k);
										try {
											sValue = XMLUtil.getElementValue(eVar);
											if(sValue.Equals("INF")) {
												mJobOptimization[i].standard.update[j].updatedVariableValues.var[k] = Double.PositiveInfinity;
											}
											else if(sValue.Equals("-INF")) {
												mJobOptimization[i].standard.update[j].updatedVariableValues.var[k] = Double.NegativeInfinity;
											}
											else{
												mJobOptimization[i].standard.update[j].updatedVariableValues.var[k] = Double.Parse(sValue);
											}
										} 
										catch (Exception) {
											mJobOptimization[i].standard.update[j].updatedVariableValues.var[k] = Double.NaN;	
										}
									}
								}
							}

							XmlElement eUpdatedVariableReducedCosts = (XmlElement)XMLUtil.findChildNode(eUpdate, "updatedVariableReducedCosts");
							if(eUpdatedVariableReducedCosts != null){
								XmlNodeList varList = eUpdatedVariableReducedCosts.GetElementsByTagName("var");
								if(varList != null && varList.Count > 0){
									int iVars = varList.Count;
									mJobOptimization[i].standard.update[j].updatedVariableReducedCosts = new UpdatedVariableReducedCosts();
									mJobOptimization[i].standard.update[j].updatedVariableReducedCosts.var = new double[iVars];
									XmlElement eVar;
									for(int k = 0; k < iVars; k++){
										eVar = (XmlElement)varList.Item(k);
										try {
											sValue = XMLUtil.getElementValue(eVar);
											if(sValue.Equals("INF")) {
												mJobOptimization[i].standard.update[j].updatedVariableReducedCosts.var[k] = Double.PositiveInfinity;
											}
											else if(sValue.Equals("-INF")) {
												mJobOptimization[i].standard.update[j].updatedVariableReducedCosts.var[k] = Double.NegativeInfinity;
											}
											else{
												mJobOptimization[i].standard.update[j].updatedVariableReducedCosts.var[k] = Double.Parse(sValue);
											}
										} 
										catch (Exception) {
											mJobOptimization[i].standard.update[j].updatedVariableReducedCosts.var[k] = Double.NaN;	
										}
									}
								}
							}

							XmlElement eUpdatedVariableValuesString = (XmlElement)XMLUtil.findChildNode(eUpdate, "updatedVariableValuesString");
							if(eUpdatedVariableValuesString != null){
								XmlNodeList varList = eUpdatedVariableValuesString.GetElementsByTagName("var");
								if(varList != null && varList.Count > 0){
									int iVars = varList.Count;
									mJobOptimization[i].standard.update[j].updatedVariableValuesString = new UpdatedVariableValuesString();
									mJobOptimization[i].standard.update[j].updatedVariableValuesString.var = new String[iVars];
									XmlElement eVar;
									for(int k = 0; k < iVars; k++){
										eVar = (XmlElement)varList.Item(k);
										mJobOptimization[i].standard.update[j].updatedVariableValuesString.var[k] = XMLUtil.getElementValue(eVar);
									}
								}
							}

							XmlElement eUpdatedConstraintValues = (XmlElement)XMLUtil.findChildNode(eUpdate, "updatedConstraintValues");
							if(eUpdatedConstraintValues != null){
								XmlNodeList conList = eUpdatedConstraintValues.GetElementsByTagName("con");
								if(conList != null && conList.Count > 0){
									int iCons = conList.Count;
									mJobOptimization[i].standard.update[j].updatedConstraintValues = new UpdatedConstraintValues();
									mJobOptimization[i].standard.update[j].updatedConstraintValues.con = new double[iCons];
									XmlElement eCon;
									for(int k = 0; k < iCons; k++){
										eCon = (XmlElement)conList.Item(k);
										try {
											sValue = XMLUtil.getElementValue(eCon);
											if(sValue.Equals("INF")) {
												mJobOptimization[i].standard.update[j].updatedConstraintValues.con[k] = Double.PositiveInfinity;
											}
											else if(sValue.Equals("-INF")) {
												mJobOptimization[i].standard.update[j].updatedConstraintValues.con[k] = Double.NegativeInfinity;
											}
											else{
												mJobOptimization[i].standard.update[j].updatedConstraintValues.con[k] = Double.Parse(sValue);
											}
										} 
										catch (Exception) {
											mJobOptimization[i].standard.update[j].updatedConstraintValues.con[k] = Double.NaN;	
										}
									}
								}
							}

							XmlElement eUpdatedDualValues = (XmlElement)XMLUtil.findChildNode(eUpdate, "updatedDualValues");
							if(eUpdatedDualValues != null){
								XmlNodeList conList = eUpdatedDualValues.GetElementsByTagName("con");
								if(conList != null && conList.Count > 0){
									int iCons = conList.Count;
									mJobOptimization[i].standard.update[j].updatedDualValues = new UpdatedDualValues();
									mJobOptimization[i].standard.update[j].updatedDualValues.con = new double[iCons];
									XmlElement eCon;
									for(int k = 0; k < iCons; k++){
										eCon = (XmlElement)conList.Item(k);
										try {
											sValue = XMLUtil.getElementValue(eCon);
											if(sValue.Equals("INF")) {
												mJobOptimization[i].standard.update[j].updatedDualValues.con[k] = Double.PositiveInfinity;
											}
											else if(sValue.Equals("-INF")) {
												mJobOptimization[i].standard.update[j].updatedDualValues.con[k] = Double.NegativeInfinity;
											}
											else{
												mJobOptimization[i].standard.update[j].updatedDualValues.con[k] = Double.Parse(sValue);
											}
										} 
										catch (Exception) {
											mJobOptimization[i].standard.update[j].updatedDualValues.con[k] = Double.NaN;	
										}
									}
								}
							}
						}
					}
				}
				
				XmlElement eOSrL = (XmlElement)XMLUtil.findChildNode(eJob, "osrl");
				if(eOSrL == null){
					mJobOptimization[i].osrl = null;
				}
				else{
					OSrLReader osrlReader = new OSrLReader(OSParameter.VALIDATE);
					osrlReader.setRootElement(eOSrL);
					OSResult osResult;
					try {
						osResult = osrlReader.getOSResult();
						mJobOptimization[i].osrl = osResult;
					} 
					catch (Exception){
						mJobOptimization[i].osrl = null;				
					}
				}
			}
			return optimizqationProcess;
		}//getOptimizationProcess

		/// <summary>
		/// Get the hash map of other processes. 
		/// </summary>
		/// <returns>the hash map of other processes.</returns>
		public Hashtable getOtherProcesses(){
			if(m_otherProcessHashMap != null) return m_otherProcessHashMap;
			m_otherProcessHashMap = new Hashtable();
			m_otherProcessDescriptionHashMap = new Hashtable();

			XmlElement eProcessData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "processData");
			ArrayList vOtherElement = XMLUtil.getChildElementsByTagName(eProcessData, "other");
			int iNls	= vOtherElement.Count;
			for(int i = 0; i < iNls; i++){
				XmlElement eOther = (XmlElement)(vOtherElement[i]);
				XmlNamedNodeMap	attributes =  eOther.Attributes;
				int n =attributes.Count;
				string sName = "";
				string sDescription = "";
				string sValue = XMLUtil.getElementValue(eOther);
				for (int j = 0; j < n; j++){
					XmlNode	attr = attributes.Item(j);
					string sAttributeName  = attr.LocalName;
					string sAttributeValue = attr.Value;
					if (sAttributeName.Equals("name")){
						sName = sAttributeValue;
					}
					else if (sAttributeName.Equals("description")){
						sDescription = sAttributeValue;
					}
				}
				m_otherProcessHashMap.Add(sName, sValue);
				m_otherProcessDescriptionHashMap.Add(sName, sDescription);
			}
			return m_otherProcessHashMap;
		}//getOtherProcesses

		/// <summary>
		/// Get the number of other processes.  
		/// </summary>
		/// <returns>the number of other processes. </returns>
		public int getOtherProcessNumber(){
			getOtherProcesses();
			return m_otherProcessHashMap.Count;
		}//getOtherProcessNumber

		/// <summary>
		/// Get the string value from the other process hash map. 
		/// </summary>
		/// <param name="name">holds the name of process to get. </param>
		/// <returns>string value from the other process hash map, null if none. </returns>
		public string getOtherProcessValueByName(string name){
			getOtherProcesses();
			if(m_otherProcessHashMap.Contains(name)){
				return (string)m_otherProcessHashMap[name];
			}
			else{ 
				return null;
			}
		}//getOtherProcessValueByName

		/// <summary>
		/// Get the string value from the other process hash map. 
		/// </summary>
		/// <param name="name">holds the name of process to get. </param>
		/// <returns>string value from the other process hash map, null if none. </returns>
		public string getOtherProcessDescriptionByName(string name){
			getOtherProcesses();
			if(m_otherProcessDescriptionHashMap.Contains(name)){
				return (string)m_otherProcessDescriptionHashMap[name];
			}
			else{ 
				return null;
			}
		}//getOtherProcessDescriptionByName

		/// <summary>
		/// Get the names of all other processes. 
		/// </summary>
		/// <returns>the names of all other processes. </returns>
		public string[] getOtherProcessNames(){
			getOtherProcesses();	
			System.Collections.ICollection nameCollection = m_otherProcessHashMap.Keys;
			string[] msName = new string[nameCollection.Count];
			IDictionaryEnumerator dictionaryEnumerator = m_otherProcessHashMap.GetEnumerator();
			int i = 0;
			while(dictionaryEnumerator.MoveNext()){
				msName[i] = (string)dictionaryEnumerator.Key;
				i++;
			}
			return msName;
		}//getOtherProcessNames

		/// <summary>
		/// Get the values of all other processes. 
		/// </summary>
		/// <returns>the values of all other processes. </returns>
		public string[] getOtherProcessValues(){
			getOtherProcesses();	
			System.Collections.ICollection valueCollection = m_otherProcessHashMap.Values;
			string[] msValue = new string[valueCollection.Count];
			IDictionaryEnumerator dictionaryEnumerator = m_otherProcessHashMap.GetEnumerator();
			int i = 0;
			while(dictionaryEnumerator.MoveNext()){
				msValue[i] = (string)dictionaryEnumerator.Value;
				i++;
			}
			return msValue;
		}//getOtherProcessValues

		/// <summary>
		/// Get the descriptions of all other processes. 
		/// </summary>
		/// <returns>the descriptions of all other processes. </returns>
		public string[] getOtherProcessDescriptions(){
			getOtherProcesses();	
			System.Collections.ICollection descriptionCollection = m_otherProcessDescriptionHashMap.Values;
			string[] msDescription = new string[descriptionCollection.Count];
			IDictionaryEnumerator dictionaryEnumerator = m_otherProcessDescriptionHashMap.GetEnumerator();
			int i = 0;
			while(dictionaryEnumerator.MoveNext()){
				msDescription[i] = (string)dictionaryEnumerator.Value;
				i++;
			}
			return msDescription;
		}//getOtherProcessDescriptions

	}//class OSpLReader
}//namespace