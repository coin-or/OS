using System;
using System.Collections;
using System.Xml;

using org.optimizationservices.oscommon.util;
using org.optimizationservices.oscommon.localinterface;
using org.optimizationservices.oscommon.datastructure.osresult;
using org.optimizationservices.oscommon.datastructure.osgeneral;
using org.optimizationservices.oscommon.datastructure.osprocess;

namespace org.optimizationservices.oscommon.representationparser{
	///	<summary>
	///	The	<c>OSrLReader</c> class	parses an OSrL instance	into a DOM tree	and
	///	provides a set of "get"	methods	that can be	
	///	used to	retrieve different pieces of information of	the	instance.
	///	@author	Jun	Ma	
	///	@version 1.0, 09/01/2005
	///	@since OS 1.0
	///	@copyright (c) 2005
	///	</summary>
	public class OSrLReader	: OSgLReader{
		/// <summary>
		/// m_osResult holds the standard OSResult, which is a local interface for 
		/// storing Optimization Services result. 
		/// </summary>
		protected OSResult m_osResult = null;

		/// <summary>
		/// m_iVariableNumber holds the variable number. 
		/// </summary>
		private int m_iVariableNumber = -1;

		/// <summary>
		/// m_iObjectiveNumber holds the objective number. 
		/// </summary>
		private int m_iObjectiveNumber = -1;

		/// <summary>
		/// m_iConstraintNumber holds the constraint number. 
		/// </summary>
		private int m_iConstraintNumber = -1;

		/// <summary>
		/// m_iSolutionNumber holds the solution number. 
		/// </summary>
		private int m_iSolutionNumber = -1;

		/// <summary>
		/// m_bProcessOptimizationResult holds whether the optimization result has been processed or not. 
		/// </summary>
		private bool m_bProcessOptimizationResult = false;

		/// <summary>
		/// m_optimizationResult holds the optimization result in the result data. 
		/// </summary>
		private OptimizationResult m_optimizationResult = null;

		///	<summary>
		///	m_otherResultHashMap holds a hash map of other result information.
		///	</summary>
		protected Hashtable	m_otherResultHashMap = null;

		///	<summary>
		///	m_otherResultDescriptionHashMap holds a hash map of other result descriptions.
		///	</summary>
		protected Hashtable	m_otherResultDescriptionHashMap = null;

		///	<summary>
		///	constructor.
		///	</summary>
		///	<param name="validate">holds whether the reader	should be validating against the schema	or not.</param>
		public OSrLReader(bool validate){
			m_bXsdValidate = validate;
		}//constructor
	
		///	<summary>
		///	Default	constructor. 
		///	</summary>
		public OSrLReader(){
		}//constructor
		
		/// <summary>
		/// get the standard OSResult, a local interface for 
		/// storing Optimization Services result.
		/// </summary>
		/// <returns>the OSResult. </returns>
		public OSResult getOSResult(){
			if(m_osResult != null){
				return m_osResult;
			}
			m_osResult = new OSResult();
			if(!m_osResult.setGeneralStatus(getGeneralStatus())) throw new Exception("setGeneralStatus Unsuccessful");
			if(!m_osResult.setServiceURI(getServiceURI())) throw new Exception("setServiceURI Unsuccessful");
			if(!m_osResult.setServiceName(getServiceName())) throw new Exception("setServiceName Unsuccessful");
			if(!m_osResult.setInstanceName(getInstanceName())) throw new Exception("setInstanceName Unsuccessful");
			if(!m_osResult.setJobID(getJobID())) throw new Exception("setJobID Unsuccessful");
			if(!m_osResult.setResultTime(getResultTime())) throw new Exception("setResultTime Unsuccessful");
			if(!m_osResult.setGeneralMessage(getGeneralMessage())) throw new Exception("setGeneralMessage Unsuccessful");
			if(!m_osResult.setVariableNumber(getVariableNumber())) throw new Exception("setVariableNumber Unsuccessful");
			if(!m_osResult.setObjectiveNumber(getObjectiveNumber())) throw new Exception("setObjectiveNumber Unsuccessful");
			if(!m_osResult.setConstraintNumber(getConstraintNumber())) throw new Exception("setConstraintNumber Unsuccessful");
			if(!m_osResult.setSolutionNumber(getSolutionNumber())) throw new Exception("setSolutionNumber Unsuccessful");
			if(!m_osResult.setProcessStatistics(getProcessStatistics())) throw new Exception("setProcessStatistics Unsuccessful");
			processOptimizationResult();
			m_osResult.resultData.optimization = m_optimizationResult;
			if(!m_osResult.setOtherResults(getOtherResultNames(), getOtherResultDescriptions(), getOtherResultValues())) throw new Exception("setOtherResults Unsuccessful");
			return m_osResult;
		}//getOSResult

		/// <summary>
		/// Get the general status.
		/// </summary>
		/// <returns> the general status. </returns>
		public GeneralStatus getGeneralStatus(){
			XmlElement eResultHeader = (XmlElement)XMLUtil.findChildNode(m_eRoot, "resultHeader");
			XmlElement eGeneralStatus = (XmlElement)XMLUtil.findChildNode(eResultHeader, "generalStatus");
			if(eGeneralStatus == null) return null;
			GeneralStatus status = new GeneralStatus();
			string sStatusType = eGeneralStatus.GetAttribute("type");
			string sStatusDescription = eGeneralStatus.GetAttribute("description");
			status.type = sStatusType;
			status.description = sStatusDescription;
			XmlNodeList nodeList = eGeneralStatus.GetElementsByTagName("substatus");
			int iChildren = nodeList.Count;
			if(iChildren <= 0) return status;
			status.substatus = new GeneralSubstatus[iChildren];
			for(int i = 0; i < iChildren; i++){
				status.substatus[i] = new GeneralSubstatus();
				XmlElement eSubstatus = (XmlElement)(nodeList.Item(i));
				XmlNamedNodeMap attributes =  eSubstatus.Attributes;
				int n =attributes.Count;
				string sSubstatusName = "";
				string sSubstatusDescription = "";
				string sSubstatusValue = XMLUtil.getElementValue(eSubstatus);
				status.substatus[i].value = sSubstatusValue;
				for (int j = 0; j < n; j++) {
					XmlNode attr = attributes.Item(j);
					string sLocalName = attr.LocalName;
					string sValue = attr.Value;
					if (sLocalName.Equals("name")){
						sSubstatusName = sValue;
						status.substatus[i].name = sSubstatusName;
					}
					else if (sLocalName.Equals("description")){
						sSubstatusDescription = sValue;
						status.substatus[i].description = sSubstatusDescription;
					}
				}
			}
			return status;
		}//getGeneralStatus
	
		/// <summary>
		/// Get the general status type, which can be: 
		/// success, error, warning. 
		/// </summary>
		/// <returns> the general status type, null if none. </returns>
		public string getGeneralStatusType(){
			XmlElement eResultHeader = (XmlElement)XMLUtil.findChildNode(m_eRoot, "resultHeader");
			XmlElement eGeneralStatus = (XmlElement)XMLUtil.findChildNode(eResultHeader, "generalStatus");
			if(eGeneralStatus == null) return null;
			string sStatusType = eGeneralStatus.GetAttribute("type");
			return sStatusType;
		}//getGeneralStatusType

		/// <summary>
		/// Get the general status description. 
		/// </summary>
		/// <returns> the general status description, null or empty string if none.</returns> 
		public string getGeneralStatusDescription(){
			XmlElement eResultHeader = (XmlElement)XMLUtil.findChildNode(m_eRoot, "resultHeader");
			XmlElement eGeneralStatus = (XmlElement)XMLUtil.findChildNode(eResultHeader, "generalStatus");
			if(eGeneralStatus == null) return null;
			string sStatusDescription = eGeneralStatus.GetAttribute("description");
			return sStatusDescription;
		}//getGeneralStatusDescription
	
		/// <summary>
		/// Get service uri.
		/// </summary>
		/// <returns> the service uri. </returns>
		public string getServiceURI(){
			XmlElement eResultHeader = (XmlElement)XMLUtil.findChildNode(m_eRoot, "resultHeader");
			string sServiceURI = XMLUtil.getElementValueByName(eResultHeader, "serviceURI");
			if(sServiceURI == null) sServiceURI = "";
			return sServiceURI;	
		}//getServiceURI
	
		/// <summary>
		/// Get service name.
		/// </summary>
		/// <returns> the service name.</returns>
		public string getServiceName(){
			XmlElement eResultHeader = (XmlElement)XMLUtil.findChildNode(m_eRoot, "resultHeader");
			string sServiceName = XMLUtil.getElementValueByName(eResultHeader, "serviceName");
			if(sServiceName == null) sServiceName = "";
			return sServiceName;
		}//getServiceName

		/// <summary>
		/// Get instance name.
		/// </summary>
		/// <returns> the instance name. </returns>
		public string getInstanceName(){
			XmlElement eResultHeader = (XmlElement)XMLUtil.findChildNode(m_eRoot, "resultHeader");
			string sInstanceName = XMLUtil.getElementValueByName(eResultHeader, "instanceName");
			if(sInstanceName == null) sInstanceName = "";
			return sInstanceName;
		}//getInstanceName
	
		/// <summary>
		/// Get the job id.
		/// </summary>
		/// <returns> the job id.</returns>
		public string getJobID(){
			XmlElement eResultHeader = (XmlElement)XMLUtil.findChildNode(m_eRoot, "resultHeader");
			string sJobID = XMLUtil.getElementValueByName(eResultHeader, "jobID");
			if(sJobID == null) sJobID = "";
			return sJobID;	
		}//getJobID
	
		/// <summary>
		/// Get time of the result.
		/// </summary>
		/// <returns> the time of the result.</returns>
		public DateTime getResultTime(){
			XmlElement eResultHeader = (XmlElement)XMLUtil.findChildNode(m_eRoot, "resultHeader");
			string sTime = XMLUtil.getElementValueByName(eResultHeader, "time");
			if(sTime == null) return new DateTime(1970, 1, 1, 0, 0, 0);
			DateTime time = XMLUtil.createNativeDateTime(sTime);
			return time;	
		}//getResultTime
	
		/// <summary>
		/// Get the general message. 
		/// </summary>
		/// <returns> the general message. </returns>
		public string getGeneralMessage(){
			XmlElement eResultHeader = (XmlElement)XMLUtil.findChildNode(m_eRoot, "resultHeader");
			string sMessage = XMLUtil.getElementValueByName(eResultHeader, "message");
			if(sMessage == null) sMessage = "";
			return sMessage;
		}//getGeneralMessage
	
		/// <summary>
		/// Get the process statistics. 
		/// </summary>
		/// <returns> the process statistics. </returns>
		public ProcessStatistics getProcessStatistics(){
			XmlElement eResultData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "resultData");
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(eResultData, "statistics");
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
				if(eDependencies == null) continue;
				XmlNodeList jobIDList = eDependencies.GetElementsByTagName("jobID");
				if(jobIDList == null || jobIDList.Count <= 0) continue;
				int iJobIDs = jobIDList.Count;
				processStatistics.jobs.job[i].dependencies = new JobDependencies();
				processStatistics.jobs.job[i].dependencies.jobID = new string[iJobIDs];
				for(int j = 0; j < iJobIDs; j++){
					XmlElement eJobID = (XmlElement)jobIDList.Item(j);
					processStatistics.jobs.job[i].dependencies.jobID[j] =  XMLUtil.getElementValue(eJobID);
				}
			}
			return processStatistics;
		}//getProcessStatistics
	
		/// <summary>
		/// Get the statistics of all the jobs. 
		/// </summary>
		/// <returns> the statistics of all the jobs, which is an array of jobStatistics with 
		/// each member corresponding to one job; null if none. 
		/// </returns>
		public JobStatistics[] getJobStatistics(){
			XmlElement eResultData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "resultData");
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(eResultData, "statistics");
			if(eStatistics == null) return null;
			XmlElement eJobs = (XmlElement)XMLUtil.findChildNode(eStatistics, "jobs");
			if(eJobs == null) return null;
			XmlNodeList jobList = eJobs.GetElementsByTagName("job");
			if(jobList == null || jobList.Count <= 0) return null;
			Jobs jobs = new Jobs();
			int iJobs = jobList.Count;
			jobs.job = new JobStatistics[iJobs];
			string sValue = "";
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
				if(eDependencies == null) continue;
				XmlNodeList jobIDList = eDependencies.GetElementsByTagName("jobID");
				if(jobIDList == null || jobIDList.Count <= 0) continue;
				int iJobIDs = jobIDList.Count;
				jobs.job[i].dependencies = new JobDependencies();
				jobs.job[i].dependencies.jobID = new string[iJobIDs];
				for(int j = 0; j < iJobIDs; j++){
					XmlElement eJobID = (XmlElement)jobIDList.Item(j);
					jobs.job[i].dependencies.jobID[j] =  XMLUtil.getElementValue(eJobID);
				}
			}
			return jobs.job;
		}//getJobStatistics

		/// <summary>
		/// Get the current state, , which can be:
		/// "busy", "busyButAccepting", "idle", "idleButNotAccepting" and "noResponse".
		/// </summary>
		/// <returns>the current status, "noResponse" if none.</returns>
		public string getCurrentState(){
			XmlElement eResultData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "resultData");
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(eResultData, "statistics");
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
			XmlElement eResultData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "resultData");
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(eResultData, "statistics");
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
			XmlElement eResultData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "resultData");
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(eResultData, "statistics");
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
			XmlElement eResultData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "resultData");
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(eResultData, "statistics");
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
			XmlElement eResultData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "resultData");
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(eResultData, "statistics");
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
			XmlElement eResultData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "resultData");
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(eResultData, "statistics");
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
			XmlElement eResultData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "resultData");
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(eResultData, "statistics");
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
			XmlElement eResultData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "resultData");
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(eResultData, "statistics");
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
			XmlElement eResultData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "resultData");
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(eResultData, "statistics");
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
		/// Get the hash map of other result information. 
		/// </summary>
		/// <returns>the hash map of other result information.</returns>
		public Hashtable getOtherResults(){
			if(m_otherResultHashMap != null) return m_otherResultHashMap;
			m_otherResultHashMap = new Hashtable();
			m_otherResultDescriptionHashMap = new Hashtable();

	
			XmlElement eResultData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "resultData");
			ArrayList vNodeList = XMLUtil.getChildElementsByTagName(eResultData, "other"); 
			int iNls = vNodeList==null?0:vNodeList.Count;
			for(int i = 0; i < iNls; i++){
				XmlElement eOtherResult = (XmlElement)(vNodeList[i]);
				XmlNamedNodeMap	attributes =  eOtherResult.Attributes;
				int n =attributes.Count;
				string sName = "";
				string sDescription = "";
				string sValue = XMLUtil.getElementValue(eOtherResult);
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
				m_otherResultHashMap.Add(sName, sValue);
				m_otherResultDescriptionHashMap.Add(sName, sDescription);
			}
			return m_otherResultHashMap;
		}//getOtherResults

		/// <summary>
		/// Get the number of other result information.  
		/// </summary>
		/// <returns>the number of other result information. </returns>
		public int getOtherResultNumber(){
			getOtherResults();
			return m_otherResultHashMap.Count;
		}//getOtherResultNumber

		/// <summary>
		/// Get the string value from the other info hash map. 
		/// </summary>
		/// <param name="name">holds the name of the other info to get. </param>
		/// <returns>string value from the other info hash map, null if none. </returns>
		public string getOtherResultValueByName(string name){
			getOtherResults();
			if(m_otherResultHashMap.Contains(name)){
				return (string)m_otherResultHashMap[name];
			}
			else{ 
				return null;
			}
		}//getOtherResultValueByName

		/// <summary>
		/// Get the string value from the other info hash map. 
		/// </summary>
		/// <param name="name">holds the name of the other info to get. </param>
		/// <returns>string value from the other info hash map, null if none. </returns>
		public string getOtherResultDescriptionByName(string name){
			getOtherResults();
			if(m_otherResultDescriptionHashMap.Contains(name)){
				return (string)m_otherResultDescriptionHashMap[name];
			}
			else{ 
				return null;
			}
		}//getOtherResultDescriptionByName

		/// <summary>
		/// Get the names of all other result information. 
		/// </summary>
		/// <returns>the names of all other result information. </returns>
		public string[] getOtherResultNames(){
			getOtherResults();	
			System.Collections.ICollection nameCollection = m_otherResultHashMap.Keys;
			string[] msName = new string[nameCollection.Count];
			IDictionaryEnumerator dictionaryEnumerator = m_otherResultHashMap.GetEnumerator();
			int i = 0;
			while(dictionaryEnumerator.MoveNext()){
				msName[i] = (string)dictionaryEnumerator.Key;
				i++;
			}
			return msName;
		}//getOtherResultNames

		/// <summary>
		/// Get the values of all other result information. 
		/// </summary>
		/// <returns>the values of all other result information. </returns>
		public string[] getOtherResultValues(){
			getOtherResults();	
			System.Collections.ICollection valueCollection = m_otherResultHashMap.Values;
			string[] msValue = new string[valueCollection.Count];
			IDictionaryEnumerator dictionaryEnumerator = m_otherResultHashMap.GetEnumerator();
			int i = 0;
			while(dictionaryEnumerator.MoveNext()){
				msValue[i] = (string)dictionaryEnumerator.Value;
				i++;
			}
			return msValue;
		}//getOtherResultValues

		/// <summary>
		/// Get the descriptions of all other result information. 
		/// </summary>
		/// <returns>the descriptions of all other result information. </returns>
		public string[] getOtherResultDescriptions(){
			getOtherResults();	
			System.Collections.ICollection descriptionCollection = m_otherResultDescriptionHashMap.Values;
			string[] msDescription = new string[descriptionCollection.Count];
			IDictionaryEnumerator dictionaryEnumerator = m_otherResultDescriptionHashMap.GetEnumerator();
			int i = 0;
			while(dictionaryEnumerator.MoveNext()){
				msDescription[i] = (string)dictionaryEnumerator.Value;
				i++;
			}
			return msDescription;
		}//getOtherResultDescriptions

		/// <summary>
		/// Get variable number. 
		/// </summary>
		/// <returns> variable number, -1 if no information. </returns>
		public int getVariableNumber(){
			if(m_iVariableNumber == -1){
				XmlElement eResultData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "resultData");
				XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(eResultData, "optimization");
				if(eOptimization == null) return -1;
				string sNumber =  eOptimization.GetAttribute("numberOfVariables");
				m_iVariableNumber = Int32.Parse(sNumber);
			}
			return m_iVariableNumber;
		}//getVariableNumber

		/// <summary>
		/// Get objective number. 
		/// </summary>
		/// <returns> objective number, -1 if no information. </returns>
		public int getObjectiveNumber(){
			if(m_iObjectiveNumber == -1){
				XmlElement eResultData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "resultData");
				XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(eResultData, "optimization");
				if(eOptimization == null) return -1;
				string sNumber =  eOptimization.GetAttribute("numberOfObjectives");
				m_iObjectiveNumber = Int32.Parse(sNumber);
			}
			return m_iObjectiveNumber;
		}//getObjectiveNumber
	
		/// <summary>
		/// Get constraint number. 
		/// </summary>
		/// <returns> constraint number, -1 if no information. </returns>
		public int getConstraintNumber(){
			if(m_iConstraintNumber == -1){
				XmlElement eResultData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "resultData");
				XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(eResultData, "optimization");
				if(eOptimization == null) return -1;
				string sNumber =  eOptimization.GetAttribute("numberOfConstraints");
				m_iConstraintNumber = Int32.Parse(sNumber);
			}
			return m_iConstraintNumber;
		}//getConstraintNumber

		/// <summary>
		/// get the number of solutions. 
		/// </summary>
		/// <returns> the number of solutions, 0 if none.  </returns>
		public int getSolutionNumber(){
			if(m_iSolutionNumber == -1){
				XmlElement eResultData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "resultData");
				XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(eResultData, "optimization");
				if(eOptimization == null) return -1;
				string sNumber =  eOptimization.GetAttribute("numberOfSolutions");
				m_iSolutionNumber = Int32.Parse(sNumber);
			}
			return m_iSolutionNumber;
		}//getSolutionNumber

		/// <summary>
		/// process the optimization result
		/// </summary>
		/// <returns>whether the optimization result is process successfully or not.</returns>
		private bool processOptimizationResult(){
			if(m_bProcessOptimizationResult){
				return true;
			}
			XmlElement eResultData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "resultData");
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(eResultData, "optimization");
			if(eOptimization == null){
				m_bProcessOptimizationResult = true;
				return true;
			}
			m_optimizationResult = new OptimizationResult();

			string sVariableNumber =  eOptimization.GetAttribute("numberOfVariables");
			m_iVariableNumber = Int32.Parse(sVariableNumber);
			m_optimizationResult.numberOfSolutions = m_iVariableNumber;

			string sObjectiveNumber =  eOptimization.GetAttribute("numberOfObjectives");
			m_iObjectiveNumber = Int32.Parse(sObjectiveNumber);
			m_optimizationResult.numberOfObjectives = m_iObjectiveNumber;
		
			string sConstraintNumber =  eOptimization.GetAttribute("numberOfConstraints");
			m_iConstraintNumber = Int32.Parse(sConstraintNumber);
			m_optimizationResult.numberOfConstraints = m_iConstraintNumber;

			string sSolutionNumber =  eOptimization.GetAttribute("numberOfSolutions");
			m_iSolutionNumber = Int32.Parse(sSolutionNumber);
			m_optimizationResult.numberOfSolutions = m_iSolutionNumber;
				
			ArrayList vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
			if(vSolutions != null || vSolutions.Count > 0){
				int iSolutions = vSolutions.Count;
				m_optimizationResult.solution = new OptimizationSolution[iSolutions];
				for(int i = 0; i < iSolutions; i++){
					XmlElement eSolution = (XmlElement)vSolutions[i];
					if(eSolution == null){
						continue;
					}
					m_optimizationResult.solution[i] = new OptimizationSolution();
					OptimizationSolution solution = m_optimizationResult.solution[i];
					string sObjectiveIdx = eSolution.GetAttribute("objectiveIdx");
					if(sObjectiveIdx != null && sObjectiveIdx.Length > 0){
						solution.objectiveIdx = Int32.Parse(sObjectiveIdx);
					}//solution objectiveIdx
				
					XmlElement eStatus = (XmlElement)XMLUtil.findChildNode(eSolution, "status");
					if(eStatus != null){
						solution.status = new OptimizationSolutionStatus();
						string sStatusType = eStatus.GetAttribute("type");
						string sStatusDescription = eStatus.GetAttribute("description");
						solution.status.type = sStatusType;
						solution.status.description = sStatusDescription;
						XmlNodeList nodeList = eStatus.GetElementsByTagName("substatus");
						int iChildren = nodeList.Count;
						if(iChildren > 0){
							solution.status.substatus = new OptimizationSolutionSubstatus[iChildren];
							for(int j = 0; j < iChildren; j++){
								solution.status.substatus[j] = new OptimizationSolutionSubstatus();
								XmlElement eSubstatus = (XmlElement)(nodeList.Item(j));
								XmlNamedNodeMap attributes =  eSubstatus.Attributes;
								int n =attributes.Count;
								string sSubstatusName = "";
								string sSubstatusDescription = "";
								string sSubstatusValue = XMLUtil.getElementValue(eSubstatus);
								solution.status.substatus[j].value = sSubstatusValue;
								for (int k = 0; k < n; k++) {
									XmlNode attr = attributes.Item(k);
									string sLocalName = attr.LocalName;
									string sValue = attr.Value;
									if (sLocalName.Equals("name")){
										sSubstatusName = sValue;
										solution.status.substatus[j].name = sSubstatusName;
									}
									else if (sLocalName.Equals("description")){
										sSubstatusDescription = sValue;
										solution.status.substatus[j].description = sSubstatusDescription;
									}
								}
							}
						}					
					}//solution status 
				
					XmlElement eMessage = (XmlElement)XMLUtil.findChildNode(eSolution, "message");
					if(eMessage != null){
						solution.message = XMLUtil.getElementValue(eMessage);					
					}//solution message
				
					XmlElement eVariables = (XmlElement)XMLUtil.findChildNode(eSolution, "variables");
					if(eVariables != null){
						solution.variables = new VariableSolution();			
						//variable values
						XmlElement eValues = (XmlElement)XMLUtil.findChildNode(eVariables, "values");
						if(eValues != null){
							solution.variables.values = new VariableValues(); 
							XmlNodeList vars = eValues.GetElementsByTagName("var");
							if(vars != null && vars.Count > 0){
								int iVars = vars.Count;
								solution.variables.values.var = new VarValue[iVars];
								for(int j = 0; j < iVars; j++){
									solution.variables.values.var[j] = new VarValue();
									try{
										int iIndex = Int32.Parse(((XmlElement)vars.Item(j)).GetAttribute("idx"));
										solution.variables.values.var[j].idx = iIndex;
										string sValue = XMLUtil.getElementValue((XmlElement)vars.Item(j));
										double dValue = 0;
										if(sValue == null || sValue.Length == 0){
											dValue = 0;
										}
										else if(sValue.Equals("INF")){
											dValue = Double.PositiveInfinity;
										}
										else if(sValue.Equals("-INF")){
											dValue = Double.NegativeInfinity;
										}
										else{
											dValue = Double.Parse(sValue);
										}
										solution.variables.values.var[j].value = dValue;
									}
									catch(Exception){									
									}
								}
							}
						}
						//variable valuesString
						XmlElement eValuesString = (XmlElement)XMLUtil.findChildNode(eVariables, "valuesString");
						if(eValuesString != null){
							solution.variables.valuesString = new VariableStringValues(); 
							XmlNodeList vars = eValuesString.GetElementsByTagName("var");
							if(vars != null && vars.Count > 0){
								int iVars = vars.Count;
								solution.variables.valuesString.var = new VarStringValue[iVars];
								for(int j = 0; j < iVars; j++){
									solution.variables.valuesString.var[j] = new VarStringValue();
									int iIndex = Int32.Parse(((XmlElement)vars.Item(j)).GetAttribute("idx"));
									solution.variables.valuesString.var[j].idx = iIndex;
									string sValue = XMLUtil.getElementValue((XmlElement)vars.Item(j));
									solution.variables.valuesString.var[j].value = sValue;
								}
							}
						}	
						//variable other
						ArrayList vOther = XMLUtil.getChildElementsByTagName(eVariables, "other");
						if(vOther != null && vOther.Count > 0){
							int iOther = vOther.Count;
							solution.variables.other = new OtherVariableResult[iOther];
							for(int j = 0; j < iOther; j++){
								XmlElement eOther = (XmlElement)vOther[j];
								solution.variables.other[j] = new OtherVariableResult(); 
								XmlNodeList vars = eOther.GetElementsByTagName("var");
								if(vars != null && vars.Count > 0){
									int iVars = vars.Count;
									solution.variables.other[j].var = new OtherVarResult[iVars];
									solution.variables.other[j].name = eOther.GetAttribute("name");
									solution.variables.other[j].value = eOther.GetAttribute("value");
									solution.variables.other[j].description = eOther.GetAttribute("description");
									for(int k = 0; k < iVars; k++){
										solution.variables.other[j].var[k] = new OtherVarResult();
										try{
											int iIndex = Int32.Parse(((XmlElement)vars.Item(k)).GetAttribute("idx"));
											solution.variables.other[j].var[k].idx = iIndex;
											string sValue = XMLUtil.getElementValue((XmlElement)vars.Item(k));
											if(sValue != null && sValue.Length > 0){
												solution.variables.other[j].var[k].value = sValue;
											}
										}
										catch(Exception){									
										}
									}
								}
							}
						}
					}//solution variables
				
					XmlElement eObjectives = (XmlElement)XMLUtil.findChildNode(eSolution, "objectives");
					if(eObjectives != null){
						solution.objectives = new ObjectiveSolution();
						//objective values
						XmlElement eValues = (XmlElement)XMLUtil.findChildNode(eObjectives, "values");
						if(eValues != null){
							solution.objectives.values = new ObjectiveValues(); 
							XmlNodeList objs = eValues.GetElementsByTagName("obj");
							if(objs != null && objs.Count > 0){
								int iObjs = objs.Count;
								solution.objectives.values.obj = new ObjValue[iObjs];
								for(int j = 0; j < iObjs; j++){
									solution.objectives.values.obj[j] = new ObjValue();
									try{
										int iIndex = Int32.Parse(((XmlElement)objs.Item(j)).GetAttribute("idx"));
										solution.objectives.values.obj[j].idx = iIndex;
										string sValue = XMLUtil.getElementValue((XmlElement)objs.Item(j));
										double dValue = 0;
										if(sValue == null || sValue.Length == 0){
											dValue = 0;
										}
										else if(sValue.Equals("INF")){
											dValue = Double.PositiveInfinity;
										}
										else if(sValue.Equals("-INF")){
											dValue = Double.NegativeInfinity;
										}
										else{
											dValue = Double.Parse(sValue);
										}
										solution.objectives.values.obj[j].value = dValue;
									}
									catch(Exception){									
									}
								}
							}
						}
						//objective other
						ArrayList vOther = XMLUtil.getChildElementsByTagName(eObjectives, "other");
						if(vOther != null && vOther.Count > 0){
							int iOther = vOther.Count;
							solution.objectives.other = new OtherObjectiveResult[iOther];
							for(int j = 0; j < iOther; j++){
								XmlElement eOther = (XmlElement)vOther[j];
								solution.objectives.other[j] = new OtherObjectiveResult(); 
								XmlNodeList objs = eOther.GetElementsByTagName("obj");
								if(objs != null && objs.Count > 0){
									int iObjs = objs.Count;
									solution.objectives.other[j].obj = new OtherObjResult[iObjs];
									solution.objectives.other[j].name = eOther.GetAttribute("name");
									solution.objectives.other[j].value = eOther.GetAttribute("value");
									solution.objectives.other[j].description = eOther.GetAttribute("description");
									for(int k = 0; k < iObjs; k++){
										solution.objectives.other[j].obj[k] = new OtherObjResult();
										try{
											int iIndex = Int32.Parse(((XmlElement)objs.Item(k)).GetAttribute("idx"));
											solution.objectives.other[j].obj[k].idx = iIndex;
											string sValue = XMLUtil.getElementValue((XmlElement)objs.Item(k));
											if(sValue != null && sValue.Length > 0){
												solution.objectives.other[j].obj[k].value = sValue;
											}
										}
										catch(Exception){									
										}
									}
								}
							}
						}
					}//solution objectives
				
					XmlElement eConstraints = (XmlElement)XMLUtil.findChildNode(eSolution, "constraints");
					if(eConstraints != null){
						solution.constraints = new ConstraintSolution();
						//constraint dualValues
						XmlElement eDualValues = (XmlElement)XMLUtil.findChildNode(eConstraints, "dualValues");
						if(eDualValues != null){
							solution.constraints.dualValues = new DualVariableValues(); 
							XmlNodeList cons = eDualValues.GetElementsByTagName("con");
							if(cons != null && cons.Count > 0){
								int icons = cons.Count;
								solution.constraints.dualValues.con = new DualVarValue[icons];
								for(int j = 0; j < icons; j++){
									solution.constraints.dualValues.con[j] = new DualVarValue();
									try{
										int iIndex = Int32.Parse(((XmlElement)cons.Item(j)).GetAttribute("idx"));
										solution.constraints.dualValues.con[j].idx = iIndex;
										string sValue = XMLUtil.getElementValue((XmlElement)cons.Item(j));
										double dValue = 0;
										if(sValue == null || sValue.Length == 0){
											dValue = 0;
										}
										else if(sValue.Equals("INF")){
											dValue = Double.PositiveInfinity;
										}
										else if(sValue.Equals("-INF")){
											dValue = Double.NegativeInfinity;
										}
										else{
											dValue = Double.Parse(sValue);
										}
										solution.constraints.dualValues.con[j].value = dValue;
									}
									catch(Exception){									
									}
								}
							}
						}
						//constraint other
						ArrayList vOther = XMLUtil.getChildElementsByTagName(eConstraints, "other");
						if(vOther != null && vOther.Count > 0){
							int iOther = vOther.Count;
							solution.constraints.other = new OtherConstraintResult[iOther];
							for(int j = 0; j < iOther; j++){
								XmlElement eOther = (XmlElement)vOther[j];
								solution.constraints.other[j] = new OtherConstraintResult(); 
								XmlNodeList cons = eOther.GetElementsByTagName("con");
								if(cons != null && cons.Count > 0){
									int icons = cons.Count;
									solution.constraints.other[j].con = new OtherConResult[icons];
									solution.constraints.other[j].name = eOther.GetAttribute("name");
									solution.constraints.other[j].value = eOther.GetAttribute("value");
									solution.constraints.other[j].description = eOther.GetAttribute("description");
									for(int k = 0; k < icons; k++){
										solution.constraints.other[j].con[k] = new OtherConResult();
										try{
											int iIndex = Int32.Parse(((XmlElement)cons.Item(k)).GetAttribute("idx"));
											solution.constraints.other[j].con[k].idx = iIndex;
											string sValue = XMLUtil.getElementValue((XmlElement)cons.Item(k));
											if(sValue != null && sValue.Length > 0){
												solution.constraints.other[j].con[k].value = sValue;
											}
										}
										catch(Exception){									
										}
									}
								}
							}
						}
					}//solution constraints
				
					ArrayList vOtherOptimizationResults = XMLUtil.getChildElementsByTagName(eSolution, "other");
					if(vOtherOptimizationResults != null && vOtherOptimizationResults.Count > 0){
						int iOthers = vOtherOptimizationResults.Count;
						solution.other = new OtherOptimizationResult[iOthers];
						for(int j = 0; j < iOthers; j++){
							XmlElement eOther = (XmlElement)vOtherOptimizationResults[j];						
							solution.other[j] = new OtherOptimizationResult();
							solution.other[j].name = eOther.GetAttribute("name");
							solution.other[j].value = XMLUtil.getElementValue(eOther);
							solution.other[j].description = eOther.GetAttribute("description");
						}//for each other result
					}//solution other results
				}//for each solution	
			
				XmlElement eOSaL = (XmlElement)XMLUtil.findChildNode(eOptimization, "osal");
				if(eOSaL != null){
					OSaLReader osalReader = new OSaLReader(OSParameter.VALIDATE);
					osalReader.setRootElement(eOSaL);
					OSAnalysis osAnalysis;
					try {
						osAnalysis = osalReader.getOSAnalysis();
						m_optimizationResult.osal = osAnalysis;
					} 
					catch (Exception){
						return false;
					}
				}//last optional osal		
			}//if there are solutions

			m_bProcessOptimizationResult = true;
			return true;
		}//processOptimizationResult

		/// <summary>
		/// Get one solution of optimal primal variable values. 
		/// </summary>
		/// <param name="objIdx"> holds the objective index the optimal value corresponds to. </param>
		/// <returns> a double dense array of the optimal values, null if no optimal value. </returns>
		public double[] getOptimalPrimalVariableValues(int objIdx){
			processOptimizationResult();
			if(m_optimizationResult == null) return null;
			if(m_optimizationResult.solution == null || m_optimizationResult.solution.Length <= 0) return null;
			int iNumberOfVariables = this.getVariableNumber();
			if(iNumberOfVariables <= 0) return null;
			int iSolutions = m_optimizationResult.solution.Length;
			double[] mdValues = null;
			for(int i = 0; i < iSolutions; i++){
				if(m_optimizationResult.solution[i] == null) continue;
				if(m_optimizationResult.solution[i].objectiveIdx != objIdx) continue;
				if(m_optimizationResult.solution[i].variables == null) continue;
				if(m_optimizationResult.solution[i].variables.values == null) continue;
				if((m_optimizationResult.solution[i].status.type.EndsWith("ptimal") && mdValues == null)||
					m_optimizationResult.solution[i].status.type.Equals("globallyOptimal")){				
					VarValue[] var = m_optimizationResult.solution[i].variables.values.var; 
					int iVars = (var==null)?0:var.Length;
					mdValues = new double[iNumberOfVariables];
					for(int j = 0; j < iVars; j++){
						mdValues[var[j].idx] = var[j].value;
					}
				}	
				if(m_optimizationResult.solution[i].status.type.Equals("globallyOptimal")){
					return mdValues;
				}
			}
			return mdValues;
		}//getOptimalPrimalVariableValues

		/// <summary>
		/// Get one solution of optimal primal variable string values.
		/// </summary>
		/// <param name="objIdx"> holds the objective index the optimal value corresponds to.</param> 
		/// <returns> a string dense array of the optimal string values, null if no optimal value. </returns>
		public string[] getOptimalPrimalVariableStringValues(int objIdx){
			processOptimizationResult();
			if(m_optimizationResult == null) return null;
			if(m_optimizationResult.solution == null || m_optimizationResult.solution.Length <= 0) return null;
			int iNumberOfVariables = this.getVariableNumber();
			if(iNumberOfVariables <= 0) return null;
			int iSolutions = m_optimizationResult.solution.Length;
			string[] msValues = null;
			for(int i = 0; i < iSolutions; i++){
				if(m_optimizationResult.solution[i] == null) continue;
				if(m_optimizationResult.solution[i].objectiveIdx != objIdx) continue;
				if(m_optimizationResult.solution[i].variables == null) continue;
				if(m_optimizationResult.solution[i].variables.valuesString == null) continue;
				if((m_optimizationResult.solution[i].status.type.EndsWith("ptimal") && msValues == null)||
					m_optimizationResult.solution[i].status.type.Equals("globallyOptimal")){
					VarStringValue[] var = m_optimizationResult.solution[i].variables.valuesString.var; 
					int iVars = (var==null)?0:var.Length;
					msValues = new string[iNumberOfVariables];
					for(int j = 0; j < iVars; j++){
						msValues[var[j].idx] = var[j].value;
					}
				}	
				if(m_optimizationResult.solution[i].status.type.Equals("globallyOptimal")){
					return msValues;
				}
			}
			return msValues;
		}//getOptimalPrimalVariableStringValues
	
		/// <summary>
		/// Get one solution of optimal dual variable values. 
		/// </summary>
		/// <param name="objIdx"> holds the objective index the optimal value corresponds to. </param>
		/// <returns> a double dense array of the optimal dual values, null if no optimal value. </returns>
		public double[] getOptimalDualVariableValues(int objIdx){
			processOptimizationResult();
			if(m_optimizationResult == null) return null;
			if(m_optimizationResult.solution == null || m_optimizationResult.solution.Length <= 0) return null;
			int iNumberOfConstraints = this.getConstraintNumber();
			if(iNumberOfConstraints <= 0) return null;
			int iSolutions = m_optimizationResult.solution.Length;
			double[] mdValues = null;
			for(int i = 0; i < iSolutions; i++){
				if(m_optimizationResult.solution[i] == null) continue;
				if(m_optimizationResult.solution[i].objectiveIdx != objIdx) continue;
				if(m_optimizationResult.solution[i].constraints == null) continue;
				if(m_optimizationResult.solution[i].constraints.dualValues == null) continue;
				if((m_optimizationResult.solution[i].status.type.EndsWith("ptimal") && mdValues == null)||
					m_optimizationResult.solution[i].status.type.Equals("globallyOptimal")){				
					DualVarValue[] con = m_optimizationResult.solution[i].constraints.dualValues.con; 
					int iCons = (con==null)?0:con.Length;
					mdValues = new double[iNumberOfConstraints];
					for(int j = 0; j < iCons; j++){
						if(!Double.IsNaN(con[j].value) && con[j].value != 0){
							mdValues[con[j].idx] = con[j].value;
						}
					}
				}	
				if(m_optimizationResult.solution[i].status.type.Equals("globallyOptimal")){
					return mdValues;
				}
			}
			return mdValues;	
		}//getOptimalDualVariableValues
	
		/// <summary>
		/// Get the [i]th optimization solution, where i equals the given solution index.
		/// </summary>
		/// <param name="solIdx"> holds the solution index to get the solution. 
		/// <returns> the optimization solution that corresponds to solIdx, null if none. 
		public OptimizationSolution getSolution(int solIdx){
			processOptimizationResult();
			if(m_optimizationResult == null) return null;
			if(m_optimizationResult.solution == null || 
				m_optimizationResult.solution.Length <= 0 || 
				solIdx < 0 || solIdx >=  m_optimizationResult.solution.Length) return null;
			return m_optimizationResult.solution[solIdx];
		}//getSolution
	
	
		/// <summary>
		/// Get the [i]th optimization solution status, where i equals the given solution index.   
		/// The solution status includes the status type, optional descriptions and possibly substatuses.
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolutionStatus
		/// </summary>
		/// <param name="solIdx"> holds the solution index to get the solution status. </param>
		/// <returns> the optimization solution status that corresponds to solIdx, null if none. </returns>
		public OptimizationSolutionStatus getSolutionStatus( int solIdx){
			processOptimizationResult();
			if(m_optimizationResult == null) return null;
			if(m_optimizationResult.solution == null || 
				m_optimizationResult.solution.Length <= 0 || 
				solIdx < 0 || solIdx >=  m_optimizationResult.solution.Length) return null;
			if(m_optimizationResult.solution[solIdx] == null) return null;
			return m_optimizationResult.solution[solIdx].status;
		}//getSolutionStatus
	
		/// <summary>
		/// Get the [i]th optimization solution status type, where i equals the given solution index.   
		/// The solution status type can be: 
		/// unbounded, globallyOptimal, locallyOptimal, optimal, bestSoFar, feasible, infeasible, 
		/// stoppedByLimit, unsure, error, other 
		/// </summary>
		/// <param name="solIdx"> holds the solution index to get the solution status type. </param>
		/// <returns> the optimization solution status type that corresponds to solIdx, null or empty string if none. </returns>
		public string getSolutionStatusType(int solIdx){
			processOptimizationResult();
			if(m_optimizationResult == null) return null;
			if(m_optimizationResult.solution == null || 
				m_optimizationResult.solution.Length <= 0 || 
				solIdx < 0 || solIdx >=  m_optimizationResult.solution.Length) return null;
			if(m_optimizationResult.solution[solIdx] == null) return null;
			if(m_optimizationResult.solution[solIdx].status == null) return null;
			return m_optimizationResult.solution[solIdx].status.type;
		}//getSolutionStatusType
	
		/// <summary>
		/// Get the [i]th optimization solution status description, where i equals the given solution index.   
		/// </summary>
		/// <param name="solIdx"> holds the solution index to get the solution status description. </param>
		/// <returns> the optimization solution status description that corresponds to solIdx, null or empty string if none.</returns>
		public string getSolutionStatusDescription(int solIdx){
			processOptimizationResult();
			if(m_optimizationResult == null) return null;
			if(m_optimizationResult.solution == null || 
				m_optimizationResult.solution.Length <= 0 || 
				solIdx < 0 || solIdx >=  m_optimizationResult.solution.Length) return null;
			if(m_optimizationResult.solution[solIdx] == null) return null;
			if(m_optimizationResult.solution[solIdx].status == null) return null;
			return m_optimizationResult.solution[solIdx].status.description;	
		}//getSolutionStatusDescription
	
		/// <summary>
		/// Get the [i]th optimization solution subStatuses, where i equals the given solution index.   
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolutionSubstatus;
		/// </summary>
		/// <param name="solIdx"> holds the solution index to get the solution substatuses. </param>
		/// <returns> an array optimization solution subStatuses that corresponds to solIdx, null or empty string if none.</returns>
		public OptimizationSolutionSubstatus[] getSolutionSubStatuses(int solIdx){
			processOptimizationResult();
			if(m_optimizationResult == null) return null;
			if(m_optimizationResult.solution == null || 
				m_optimizationResult.solution.Length <= 0 || 
				solIdx < 0 || solIdx >=  m_optimizationResult.solution.Length) return null;
			if(m_optimizationResult.solution[solIdx] == null) return null;
			if(m_optimizationResult.solution[solIdx].status == null) return null;
			return m_optimizationResult.solution[solIdx].status.substatus;
		}//getSolutionSubStatuses

		/// <summary>
		/// Get the [i]th optimization solution message, where i equals the given solution index.  
		/// </summary>
		/// <param name="solIdx"> holds the solution index to get the solution message. </param>
		/// <returns> the optimization solution message that corresponds to solIdx, null or empty if none.</returns>
		public string getSolutionMessage(int solIdx){
			processOptimizationResult();
			if(m_optimizationResult == null) return null;
			if(m_optimizationResult.solution == null || 
				m_optimizationResult.solution.Length <= 0 || 
				solIdx < 0 || solIdx >=  m_optimizationResult.solution.Length) return null;
			if(m_optimizationResult.solution[solIdx] == null) return null;
			return m_optimizationResult.solution[solIdx].message;
		}//getSolutionMessage
	
		/// <summary>
		/// Get the [i]th optimization solution's objective index, where i equals the given solution index. 
		/// The first objective's index should be -1, the second -2, and so on.  
		/// </summary>
		/// <param name="solIdx"> holds the solution index to get the variable string values. </param>
		/// <returns> the optimization objective index that corresponds to solIdx, 0 if none.
		/// All the objective indexes are negative starting from -1 downward. </returns>
		public int getSolutionObjectiveIndex(int solIdx){
			processOptimizationResult();
			if(m_optimizationResult == null) return 0;
			if(m_optimizationResult.solution == null || 
				m_optimizationResult.solution.Length <= 0 || 
				solIdx < 0 || solIdx >=  m_optimizationResult.solution.Length) return 0;
			if(m_optimizationResult.solution[solIdx] == null) return 0;
			return m_optimizationResult.solution[solIdx].objectiveIdx;	
		}//getSolutionObjectiveIndex
	
		/// <summary>
		/// Get the [i]th optimization solution's variable values, where i equals the given solution index. 
		/// </summary>
		/// <param name="solIdx"> holds the solution index to get the variable values. </param>
		/// <returns> a double dense array of variable values, null if no variable values. </returns>
		public double[] getVariableValues(int solIdx){
			processOptimizationResult();
			if(m_optimizationResult == null) return null;
			if(m_optimizationResult.solution == null || m_optimizationResult.solution.Length <= 0) return null;
			int iNumberOfVariables = this.getVariableNumber();
			if(iNumberOfVariables <= 0) return null;
			int iSolutions = m_optimizationResult.solution.Length;
			if(solIdx < 0 || solIdx >= iSolutions) return null;
			if(m_optimizationResult.solution[solIdx] == null) return null;
			if(m_optimizationResult.solution[solIdx].variables == null) return null;
			if(m_optimizationResult.solution[solIdx].variables.values == null) return null;
			VarValue[] var = m_optimizationResult.solution[solIdx].variables.values.var; 
			int iVars = (var==null)?0:var.Length;
			double[] mdValues = new double[iNumberOfVariables];
			for(int i = 0; i < iVars; i++){
				mdValues[var[i].idx] = var[i].value;
			}
			return mdValues;	
		}//getVariableValues
	
		/// @see org.optimizationservices.oscommon.datastructure.osresult.VariableValues
		/// @see org.optimizationservices.oscommon.datastructure.osresult.VarValue
		/// <summary>
		/// Get the [i]th optimization solution's variable values in a sparse data structure, where i equals the given solution index. 
		/// The sparse data stucture is of the VariableValues data structure. VariableValues holds var[], an array of VarValues. 
		/// Each var member contains an idx and a value. If var[] is null, all the variable values are 0. 
		/// </summary>
		/// <param name="solIdx"> holds the solution index to get the sparse variable values. </param>
		/// <returns> a sparse variable value data structure in VaribleValues, null if no variable values.</returns> 
		public VariableValues getSparseVariableValues(int solIdx){
			processOptimizationResult();
			if(m_optimizationResult == null) return null;
			if(m_optimizationResult.solution == null || m_optimizationResult.solution.Length <= 0) return null;
			int iNumberOfVariables = this.getVariableNumber();
			if(iNumberOfVariables <= 0) return null;
			int iSolutions = m_optimizationResult.solution.Length;
			if(solIdx < 0 || solIdx >= iSolutions) return null;
			if(m_optimizationResult.solution[solIdx] == null) return null;
			if(m_optimizationResult.solution[solIdx].variables == null) return null;
			return m_optimizationResult.solution[solIdx].variables.values;
		}//getSparseVariableValues
	
		/// <summary>
		/// Get the [i]th optimization solution's variable string values, where i equals the given solution index. 
		/// </summary>
		/// <param name="solIdx"> holds the solution index to get the variable string values. </param>
		/// <returns> a string dense array of variable values, null if no variable values. </returns>
		public string[] getVariableStringValues(int solIdx){
			processOptimizationResult();
			if(m_optimizationResult == null) return null;
			if(m_optimizationResult.solution == null || m_optimizationResult.solution.Length <= 0) return null;
			int iNumberOfVariables = this.getVariableNumber();
			if(iNumberOfVariables <= 0) return null;
			int iSolutions = m_optimizationResult.solution.Length;
			if(solIdx < 0 || solIdx >= iSolutions) return null;
			if(m_optimizationResult.solution[solIdx] == null) return null;
			if(m_optimizationResult.solution[solIdx].variables == null) return null;
			if(m_optimizationResult.solution[solIdx].variables.valuesString == null) return null;
			VarStringValue[] var = m_optimizationResult.solution[solIdx].variables.valuesString.var; 
			int iVars = (var==null)?0:var.Length;
			string[] msValues = new String[iNumberOfVariables];
			for(int i = 0; i < iVars; i++){
				msValues[var[i].idx] = var[i].value;
			}
			return msValues;	
		}//getVariableStringValues
	
	
		/// <summary>
		/// Get the [i]th optimization solution's other (non-standard/solver specific)variable-related results, 
		/// where i equals the given solution index. 
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OtherVariableResult
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OtherVarResult
		/// </summary>
		/// <param name="solIdx"> holds the solution index to get the other variable results. </param>
		/// <returns> an array of other variable results in OtherVariableResult[] array data structure, null if none. 
		/// Each other variable result contains the name (required), an optional description (string) and an optional
		/// value (string). Each other variable result can also optionally contain an array OtherVarResult for each variable. 
		/// The OtherVarResult contains a variable idx (required), and an optional string value.  
		/// </returns>
		public OtherVariableResult[] getOtherVariableResults(int solIdx){
			processOptimizationResult();
			if(m_optimizationResult == null) return null;
			if(m_optimizationResult.solution == null || m_optimizationResult.solution.Length <= 0) return null;
			int iNumberOfVariables = this.getVariableNumber();
			if(iNumberOfVariables <= 0) return null;
			int iSolutions = m_optimizationResult.solution.Length;
			if(solIdx < 0 || solIdx >= iSolutions) return null;
			if(m_optimizationResult.solution[solIdx] == null) return null;
			if(m_optimizationResult.solution[solIdx].variables == null) return null;
			return m_optimizationResult.solution[solIdx].variables.other;
		}//getOtherVariableResults
	
		/// <summary>
		/// Get the [i]th optimization solution's objective values, where i equals the given solution index. 
		/// Usually one of the objective is what the solution was solved for (or based on). Its index should be indicated 
		/// in the solution's objectiveIdx attribute. Based on this objective's solution, the rest of the objective 
		/// values are (optionally) calculated. 
		/// </summary>
		/// <param name="solIdx"> holds the solution index to get the objective values. </param>
		/// <returns> a double dense array of objective values, null if null if no objective values. 
		/// Possibly only the objective that the solution is based on has the value, and the rest of the objective
		/// values all get a Double.NaN value, meaning that they are not calculated. </returns>  
		public double[] getObjectiveValues(int solIdx){
			processOptimizationResult();
			if(m_optimizationResult == null) return null;
			if(m_optimizationResult.solution == null || m_optimizationResult.solution.Length <= 0) return null;
			int iNumberOfObjectives = this.getObjectiveNumber();
			if(iNumberOfObjectives <= 0) return null;
			int iSolutions = m_optimizationResult.solution.Length;
			if(solIdx < 0 || solIdx >= iSolutions) return null;
			if(m_optimizationResult.solution[solIdx] == null) return null;
			if(m_optimizationResult.solution[solIdx].objectives == null) return null;
			if(m_optimizationResult.solution[solIdx].objectives.values == null) return null;
			ObjValue[] obj = m_optimizationResult.solution[solIdx].objectives.values.obj; 
			int iObjs = (obj==null)?0:obj.Length;
			double[] mdValues = new double[iNumberOfObjectives];
			for(int i = 0; i < iNumberOfObjectives; i++){
				mdValues[i] = Double.NaN;
			}
			for(int i = 0; i < iObjs; i++){
				mdValues[Math.Abs(obj[i].idx)-1] = obj[i].value;
			}
			return mdValues;
		}//getObjectiveValues
	
	
		/// <summary>
		/// Get the [i]th optimization solution's other (non-standard/solver specific)objective-related results, 
		/// where i equals the given solution index. 
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OtherObjectiveResult
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OtherObjResult
		/// </summary>
		/// <param name="solIdx"> holds the solution index to get the other objective results. </param>
		/// <returns> an array of other objective results in OtherObjectiveResult[] array data structure, null if none. 
		/// Each other objective result contains the name (required), an optional description (string) and an optional
		/// value (string). Each other objective result can also optionally contain an array OtherObjResult for each objective. 
		/// The OtherObjResult contains an objective idx (required) and an optional string value.  
		/// </returns>
		public OtherObjectiveResult[] getOtherObjectiveResults(int solIdx){
			processOptimizationResult();
			if(m_optimizationResult == null) return null;
			if(m_optimizationResult.solution == null || m_optimizationResult.solution.Length <= 0) return null;
			int iNumberOfObjectives = this.getObjectiveNumber();
			if(iNumberOfObjectives <= 0) return null;
			int iSolutions = m_optimizationResult.solution.Length;
			if(solIdx < 0 || solIdx >= iSolutions) return null;
			if(m_optimizationResult.solution[solIdx] == null) return null;
			if(m_optimizationResult.solution[solIdx].objectives == null) return null;
			return m_optimizationResult.solution[solIdx].objectives.other;
		}//getOtherObjectiveResults
	
	
		/// <summary>
		/// Get the [i]th optimization solution's dual variable values, where i equals the given solution index. 
		/// </summary>
		/// <param name="solIdx"> holds the solution index to get the dual variable values. </param>
		/// <returns> a double dense array of the dual variable values, null if none. </returns>
		public double[] getDualVariableValues(int solIdx){
			processOptimizationResult();
			if(m_optimizationResult == null) return null;
			if(m_optimizationResult.solution == null || m_optimizationResult.solution.Length <= 0) return null;
			int iNumberOfConstraints = this.getConstraintNumber();
			if(iNumberOfConstraints <= 0) return null;
			int iSolutions = m_optimizationResult.solution.Length;
			if(solIdx < 0 || solIdx >= iSolutions) return null;
			if(m_optimizationResult.solution[solIdx] == null) return null;
			if(m_optimizationResult.solution[solIdx].constraints == null) return null;
			if(m_optimizationResult.solution[solIdx].constraints.dualValues == null) return null;
			DualVarValue[] con = m_optimizationResult.solution[solIdx].constraints.dualValues.con; 
			int iCons = (con==null)?0:con.Length;
			double[] mdValues = new double[iNumberOfConstraints];
			for(int j = 0; j < iCons; j++){
				if(!Double.IsNaN(con[j].value)){
					mdValues[con[j].idx] = con[j].value;
				}
			}
			return mdValues;
		}//getDualVariableValues
		
		/// <summary>
		/// Get the [i]th optimization solution's other (non-standard/solver specific)constraint-related results, 
		/// where i equals the given solution index. 
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OtherConstraintResult
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OtherConResult
		/// </summary>
		/// <param name="solIdx"> holds the solution index to get the other constraint results. </param>
		/// <returns> an array of other constraint results in OtherConstraintResult[] array data structure, null if none. 
		/// Each other constraint result contains the name (required), an optional description (string) and an optional
		/// value (string). Each other constraint result can also optionally contain an array OtherConResult for each constraint. 
		/// The OtherConResult contains a constraint idx (required), and an optional string value.
		/// </returns>
		public OtherConstraintResult[] getOtherConstraintResults(int solIdx){
			if(m_optimizationResult == null) return null;
			if(m_optimizationResult.solution == null || m_optimizationResult.solution.Length <= 0) return null;
			int iNumberOfConstraints = this.getConstraintNumber();
			if(iNumberOfConstraints <= 0) return null;
			int iSolutions = m_optimizationResult.solution.Length;
			if(solIdx < 0 || solIdx >= iSolutions) return null;
			if(m_optimizationResult.solution[solIdx] == null) return null;
			if(m_optimizationResult.solution[solIdx].constraints == null) return null;
			return m_optimizationResult.solution[solIdx].constraints.other;	
		}//getOtherConstraintResults

		/// <summary>
		/// Get the [i]th optimization solution's other (non-standard/solver specific)optimization-related results, 
		/// where i equals the given solution index. These other results are usually on the general optimization, 
		/// not specifically on the variables, objective, or constraints. 
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OtherOptimizationResult
		/// </summary>
		/// <param name="solIdx"> holds the solution index to get the other optimization results. </param>
		/// <returns> an array of other optimization results in OtherOptimizationResult[] array data structure, null if none. 
		/// Each other optimization result contains the name (required), an optional description (string) and an optional
		/// value (string).   
		/// </returns>
		public OtherOptimizationResult[] getOtherOptimizationResults(int solIdx){
			processOptimizationResult();
			if(m_optimizationResult == null) return null;
			if(m_optimizationResult.solution == null || m_optimizationResult.solution.Length <= 0) return null;
			int iSolutions = m_optimizationResult.solution.Length;
			if(solIdx < 0 || solIdx >= iSolutions) return null;
			if(m_optimizationResult.solution[solIdx] == null) return null;
			return m_optimizationResult.solution[solIdx].other;	
		}//getOtherOptimizationResults


		/// <summary>
		/// Get the optimization analysis in the standard OSAnalysis data structure. 
		/// @see org.optimizationservices.oscommon.localinterface.OSAnalysis
		/// </summary>
		/// <returns> the optimization analysis in the standard OSAnalysis data structure, null if none.</returns>
		public OSAnalysis getOSAnalysis(){
			processOptimizationResult();
			if(m_optimizationResult == null) return null;
			return m_optimizationResult.osal;
		}//getOSAnalysis
		
	}//class OSrLReader
}//namespace