using System;
using System.Collections;

using org.optimizationservices.oscommon.datastructure.osprocess;
using org.optimizationservices.oscommon.representationparser;

namespace org.optimizationservices.oscommon.localinterface{
	/// <summary>
	/// The <c>OSProcess</c> class is a local interface for storing OS 
	/// process. Its design follows the OSpL. Naming, structuring and layering 
	/// all are exactly the same as those in the OSpL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OSProcess{

		/// <summary>
		/// processHeader holds the first child of the OSProcess specified by the OSpL Schema.
		/// </summary>
		public ProcessHeader processHeader = new ProcessHeader();

		/// <summary>
		/// processData holds the second child of the OSProcess specified by the OSpL Schema. 
		/// </summary>
		public ProcessData processData = new ProcessData();

		/// <summary>
		/// Default constructor. 
		/// </summary>
		public OSProcess(){
		}//constructor

		/// <summary>
		/// read an OSpL instance and return and OSProcess object.  
		/// @throws Exception if there are errors in reading the string or setting the OSProcess. 
		/// </summary>
		/// <param name="ospl">holds the optimization process in a string which format follows the
		/// Optimization Services process Language (OSpL) schema</param>
		/// <param name="isFile">isFile holds whether the ospl string is a file name or a string that literally holds the ospl contents.  </param>
		/// <param name="validate">holds whether the reader should be validating against the schema or not.</param>
		/// <returns>the OSProcess object constructed from the OSpL String.  </returns>
		public OSProcess readOSpL(string ospl, bool isFile, bool validate){
			OSpLReader osplReader = new OSpLReader(validate);
			bool bRead = false;
			if(isFile){
				bRead = osplReader.readFile(ospl);
			}
			else{
				bRead = osplReader.readString(ospl);			
			}
			if(!bRead) throw new Exception("OSpL string not valid");
			return osplReader.getOSProcess();
		}//readOSpL
	   
		/// <summary>
		/// write the OSProcess to an ospl xml string. 
		/// @throws Exception if there are errors in writing the ospl string. 
		/// </summary>
		/// <returns>the ospl xml string. </returns>
		public string writeOSpL(){
			OSpLWriter osplWriter = new OSpLWriter();
			osplWriter.setOSProcess(this);
			return osplWriter.writeToString();
		}//writeOSpL

		/// <summary>
		/// Get the request action, which can be: 
		/// ping, notifyJobCompletion, requestJob, getServiceStatistics, setServiceStatistics, 
		/// getJobStatistics, setJobStatistics, getOptimization, setOptimization, getAll, setAll. 
		/// </summary>
		/// <returns>the request action, null or empty string if none. </returns>
		public string getRequestAction(){
			if(processHeader.request == null) return null;
			return processHeader.request.action;
		}//getRequestAction

		/// <summary>
		/// Set the request action. 
		/// </summary>
		/// <param name="action">action holds the request action, which can be: 
		/// ping, notifyJobCompletion, requestJob, getServiceStatistics, setServiceStatistics, 
		/// getJobStatistics, setJobStatistics, getOptimization, setOptimization, getAll, setAll. 
		/// </param>
		/// <returns>whether the requestion action is set successfully.  </returns>
		public bool setRequestAction(string action){
			if(!action.Equals("ping") && 
				!action.Equals("notifyJobCompletion") &&
				!action.Equals("requestJob") &&
				!action.Equals("getServiceStatistics") &&
				!action.Equals("setServiceStatistics") &&
				!action.Equals("getJobStatistics") &&
				!action.Equals("setJobStatistics") &&
				!action.Equals("getOptimization") &&
				!action.Equals("setOptimization") &&
				!action.Equals("getAll") &&
				!action.Equals("setAll")) return false;		   
			if(processHeader.request == null) processHeader.request = new ProcessRequest();
			processHeader.request.action = action;
			return true;
		}//setRequestAction

		/// <summary>
		/// Get the request description.
		/// </summary>
		/// <returns>the request description, null or empty string if none. </returns>
		public string getRequestDescription(){
			if(processHeader.request == null) return null;
			return processHeader.request.description;
		}//getRequestDescription

		/// <summary>
		/// Set the request description.
		/// </summary>
		/// <param name="description">holds the request description</param>
		/// <returns>whether the requestion description is set successfully.  </returns>
		public bool setRequestDescription(string description){
			if(processHeader.request == null) processHeader.request = new ProcessRequest();
			processHeader.request.description = description;
			return true;
		}//setRequestDescription

		/// <summary>
		/// Get the response status, which can be: 
		/// success, error, warning. 
		/// </summary>
		/// <returns>the response status, null or empty string if none. </returns>
		public string getResponseStatus(){
			if(processHeader.response == null) return null;
			return processHeader.response.status;
		}//getResponseStatus


		/// <summary>
		/// Set the response status.
		/// </summary>
		/// <param name="status">holds the response status, which can be:
		/// success, error, warning. 
		/// </param>
		/// <returns>whether the response status is set successfully.</returns>
		public bool setResponseStatus(string status){
			if(!status.Equals("error") && 
				!status.Equals("warning") &&
				!status.Equals("success")) return false;	
			if(processHeader.response == null) processHeader.response = new ProcessResponse();
			processHeader.response.status = status;
			return true;
		}//setResponseStatus

		/// <summary>
		/// Get the response description.
		/// </summary>
		/// <returns>the response description, null or empty string if none. </returns>
		public string getResponseDescription(){
			if(processHeader.response == null) return null;
			return processHeader.response.description;
		}//getResponseDescription

		/// <summary>
		/// Set the response description.
		/// </summary>
		/// <param name="description">holds the response description</param>
		/// <returns>whether the response description is set successfully.</returns>
		public bool setResponseDescription(string description){
			if(processHeader.response == null) processHeader.response = new ProcessResponse();
			processHeader.response.description = description;
			return true;
		}//setResponseDescription

		/// <summary>
		/// Get service name.
		/// </summary>
		/// <returns>the service name. </returns>
		public string getServiceName(){
			return processHeader.serviceName;
		}//getServiceName

		/// <summary>
		/// Set service name.
		/// </summary>
		/// <param name="serviceName">holds the name of the service. </param>
		/// <returns>whether the service name is set successfully. </returns>
		public bool setServiceName(string serviceName){
			processHeader.serviceName = serviceName;
			return true;
		}//setServiceName

		/// <summary>
		/// Get service uri.
		/// </summary>
		/// <returns>the service uri. </returns>
		public string getServiceURI(){
			return processHeader.serviceURI;
		}//getServiceURI

		/// <summary>
		/// Set service uri.
		/// </summary>
		/// <param name="serviceURI"holds the uri of the service. ></param>
		/// <returns>whether the service uri is set successfully. </returns>
		public bool setServiceURI(string serviceURI){
			processHeader.serviceURI = serviceURI;
			return true;
		}//setServiceURI

		/// <summary>
		/// Get time of the last process update.
		/// </summary>
		/// <returns>the time of the last process update.</returns>
		public DateTime getProcessTime(){
			return processHeader.time;
		}//getProcessTime

		/// <summary>
		/// Set time of the last process update.
		/// </summary>
		/// <param name="time">holds the time of the last process update.</param>
		/// <returns>whether process time is set successfully. </returns>
		public bool setProcessTime(DateTime time){
			processHeader.time = time;
			return true;
		}//setProcessTime

		/// <summary>
		/// Get the process message. 
		/// </summary>
		/// <returns>the process message. </returns>
		public string getProcessMessage(){
			return processHeader.message;
		}//getProcessMessage

		/// <summary>
		/// Set the process message. 
		/// </summary>
		/// <param name="message">holds the process message. </param>
		/// <returnswhether process message is set successfully. ></returns>
		public bool setProcessMessage(string message){
			processHeader.message = message;
			return true;
		}//setProcessMessage

		/// <summary>
		/// Get the process statistics. 
		/// </summary>
		/// <returns>the process statistics. </returns>
		public ProcessStatistics getProcessStatistics(){
			return processData.statistics;
		}//getProcessStatistics

		/// <summary>
		/// Set the process statistics. 
		/// </summary>
		/// <param name="processStatistics">holds the process statistics. </param>
		/// <returns>whether the process statistics is set successfully. </returns>
		public bool setProcessStatistics(ProcessStatistics processStatistics){
			processData.statistics = processStatistics;
			return true;
		}//setprocessStatistics

		/// <summary>
		/// Get the current state, , which can be:
		/// "busy", "busyButAccepting", "idle", "idleButNotAccepting" and "noResponse".
		/// </summary>
		/// <returns>the current status, "noResponse" if none.</returns>
		public String getCurrentState(){
			if(processData.statistics == null) return "noResponse";
			return processData.statistics.currentState;
		}//getCurrentState

		/// <summary>
		/// Set the current state. 
		/// </summary>
		/// <param name="currentState">holds the current state, which can be:
		/// "busy", "busyButAccepting", "idle", "idleButNotAccepting" or "noResponse".
		/// </param>
		/// <returns>whether the current state is set successfully.</returns>
		public bool setCurrentState(String currentState){
			if(!currentState.Equals("busy") && 
				!currentState.Equals("busyButAccepting") &&
				!currentState.Equals("idle") &&
				!currentState.Equals("idleButNotAccepting") &&
				!currentState.Equals("noResponse")) return false;		 
			if(processData.statistics == null) processData.statistics = new ProcessStatistics();
			processData.statistics.currentState = currentState;
			return true;
		}//setCurrentState

		/// <summary>
		/// Get the available disk space (in bytes). 
		/// </summary>
		/// <returns>the available disk space, Double.NaN if none. </returns>
		public double getAvailableDiskSpace(){
			if(processData.statistics == null) return Double.NaN;
			return processData.statistics.availableDiskSpace;
		}//getAvailableDiskSpace

		/// <summary>
		/// Set the available disk space. 
		/// </summary>
		/// <param name="availableDiskSpace">holds the available disk space  (in bytes). </param>
		/// <returns>whether the available disk space is set successfully.</returns>
		public bool setAvailableDiskSpace(double availableDiskSpace){
			if(processData.statistics == null) processData.statistics = new ProcessStatistics();
			processData.statistics.availableDiskSpace = availableDiskSpace;
			return true;
		}//setAvailableDiskSpace


		/// <summary>
		/// Get the available memory (in bytes). 
		/// </summary>
		/// <returns>the available memory, Double.NaN if none. </returns>
		public double getAvailableMemory(){
			if(processData.statistics == null) return Double.NaN;
			return processData.statistics.availableMemory;
		}//getAvailableMemory

		/// <summary>
		/// Set the available memory. 
		/// </summary>
		/// <param name="availableMemory">holds the available memory (in bytes). </param>
		/// <returns>whether the available memory is set successfully.</returns>
		public bool setAvailableMemory(double availableMemory){
			if(processData.statistics == null) processData.statistics = new ProcessStatistics();
			processData.statistics.availableMemory = availableMemory;
			return true;
		}//setAvailableMemory


		/// <summary>
		/// Get the current job count. 
		/// </summary>
		/// <returns>the current job count, -1 if none. </returns>
		public int getCurrentJobCount(){
			if(processData.statistics == null) return -1;
			return processData.statistics.currentJobCount;
		}//getCurrentJobCount

		/// <summary>
		/// Set the current job count. 
		/// </summary>
		/// <param name="currentJobCount">holds the current job count. </param>
		/// <returns>whether the current job count is set successfully.</returns>
		public bool setCurrentJobCount(int currentJobCount){
			if(processData.statistics == null) processData.statistics = new ProcessStatistics();
			processData.statistics.currentJobCount = currentJobCount;
			return true;
		}//setCurrentJobCount


		/// <summary>
		/// Get the total jobs received so far. 
		/// </summary>
		/// <returns>the total jobs received so far, -1 if none. </returns>
		public int getTotalJobsSoFar(){
			if(processData.statistics == null) return -1;
			return processData.statistics.totalJobsSoFar;
		}//getTotalJobsSoFar

		/// <summary>
		/// Set the total jobs received so far. 
		/// </summary>
		/// <param name="totalJobsSoFar">holds the total jobs received so far. </param>
		/// <returns>whether the total jobs so far is set successfully.</returns>
		public bool setTotalJobsSoFar(int totalJobsSoFar){
			if(processData.statistics == null) processData.statistics = new ProcessStatistics();
			processData.statistics.totalJobsSoFar = totalJobsSoFar;
			return true;
		}//setTotalJobsSoFar

		/// <summary>
		/// Get the time last job ended. 
		/// </summary>
		/// <returns>the time last job ended. If none, it returns unix creation time: DateTime(1970, 1, 1, 0, 0, 0). </returns>
		public DateTime getTimeLastJobEnded(){
			if(processData.statistics == null) return new DateTime(1970, 1, 1, 0, 0, 0);
			return processData.statistics.timeLastJobEnded;
		}//getTimeLastJobEnded

		/// <summary>
		/// Set the time last job ended. 
		/// </summary>
		/// <param name="timeLastJobEnded">holds the time last job ended. </param>
		/// <returns>whether the time last job ended is set successfully.</returns>
		public bool setTimeLastJobEnded(DateTime timeLastJobEnded){
			if(processData.statistics == null) processData.statistics = new ProcessStatistics();
			processData.statistics.timeLastJobEnded = timeLastJobEnded;
			return true;
		}//setTimeLastJobEnded

		/// <summary>
		/// Get the time last job took (in seconds). 
		/// </summary>
		/// <returns>the the time last job took, Double.NaN if none. </returns>
		public double getTimeLastJobTook(){
			if(processData.statistics == null) return Double.NaN;
			return processData.statistics.timeLastJobTook;
		}//getTimeLastJobTook

		/// <summary>
		/// Set the time last job took. 
		/// </summary>
		/// <param name="timeLastJobTook">holds the time last job took (in seconds). </param>
		/// <returns>whether the time last job took is set successfully.</returns>
		public bool setTimeLastJobTook(double timeLastJobTook){
			if(processData.statistics == null) processData.statistics = new ProcessStatistics();
			processData.statistics.timeLastJobTook = timeLastJobTook;
			return true;
		}//setTimeLastJobTook

		/// <summary>
		/// Get the time the service started. 
		/// </summary>
		/// <returns>the time last job ended. If none, it returns unix creation time: DateTime(1970, 1, 1, 0, 0, 0). </returns>
		public DateTime getTimeServiceStarted(){
			if(processData.statistics == null) return new DateTime(1970, 1, 1, 0, 0, 0);
			return processData.statistics.timeServiceStarted;
		}//getTimeServiceStarted

		/// <summary>
		/// Set the time the service started. 
		/// </summary>
		/// <param name="timeServiceStarted">holds the time the service started. </param>
		/// <returns>whether the time the service started is set successfully.</returns>
		public bool setTimeServiceStarted(DateTime timeServiceStarted){
			if(processData.statistics == null) processData.statistics = new ProcessStatistics();
			processData.statistics.timeServiceStarted = timeServiceStarted;
			return true;
		}//setTimeServiceStarted

		/// <summary>
		/// Get the service utilization ([0, 1]). 
		/// </summary>
		/// <returns>the the time last job took, Double.NaN if none. </returns>
		public double getServiceUtilization(){
			if(processData.statistics == null) return Double.NaN;
			return processData.statistics.serviceUtilization;
		}//getServiceUtilization

		/// <summary>
		/// Set the service utilization. 
		/// </summary>
		/// <param name="serviceUtilization">holds the service utilization ([0, 1]). </param>
		/// <returns>whether the time last job took is set successfully.</returns>
		public bool setServiceUtilization(double serviceUtilization){
			if(processData.statistics == null) processData.statistics = new ProcessStatistics();
			processData.statistics.serviceUtilization = serviceUtilization;
			return true;
		}//setServiceUtilization

		/// <summary>
		/// Get the statistics of all the jobs. 
		/// </summary>
		/// <returns>the statistics of all the jobs, which is an array of jobStatistics with
		///  each member corresponding to one job; null if none. 
		/// </returns>
		public JobStatistics[] getJobStatistics(){
			if(processData.statistics == null) return null;
			if(processData.statistics.jobs == null) return null;
			return processData.statistics.jobs.job;
		}//getJobStatistics

		/// <summary>
		/// Set the statistics of all jobs. 
		/// </summary>
		/// <param name="jobStatistics">holds an array of jobStatistics with 
		/// each member corresponding to one job. 
		/// </param>
		/// <returns>whether the job statistics are set successfully. </returns>
		public bool setJobStatistics(JobStatistics[] jobStatistics){
			if(processData.statistics == null) processData.statistics = new ProcessStatistics();
			if(processData.statistics.jobs == null) processData.statistics.jobs = new Jobs();
			processData.statistics.jobs.job = jobStatistics;
			return true;
		}//setJobStatistics

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
			return processData.optimization;
		}//getOptimizationProcess

		/// <summary>
		/// Set the optimization process of all the jobs, which are in effect
		/// intermediate (or occasionally final) optimization results. The intermediate process 
		/// can be some pre-built standard optimization information and/or the standard OSrL (Optimization
		/// Services result Language.
		/// </summary>
		/// <param name="optimizationProcess">holds the optimization process information which 
		/// contains an array, with each member corresponding to an optimization job. Each optimization job contains a job id string 
		/// and an optimization result, which data structure follow the OSrL schema.  
		/// </param>
		/// <returns>whether the optimization process is set successfully. </returns>
		public bool setOptimizationProcess(OptimizationProcess optimizationProcess){
			processData.optimization = optimizationProcess;
			return true;
		}//setOptimizationProcess

		/// <summary>
		/// get a string array of names of other processes. 
		/// </summary>
		/// <returns>a string array of names of other processes, null if no other processes.  </returns>
		public string[] getOtherProcessNames(){
			if(processData.other == null) return null;
			int n = processData.other.Length;
			if(n <= 0) return null;
			string[] otherProcessNames = new string[n];
			for(int i = 0; i < n; i++){
				otherProcessNames[i] = processData.other[i].name;
			}
			return otherProcessNames;
		}//getOtherProcessNames

		/// <summary>
		/// get a hashmap of other process descriptions. 
		/// The keys of the hashmap are the process names, and 
		/// the values of the hashmap are the process descriptions.  
		/// </summary>
		/// <returns>a hashmap of other process descriptions, null if no other processes. </returns>
		public Hashtable getOtherProcessDescriptions(){
			if(processData.other == null) return null;
			int n = processData.other.Length;
			if(n <= 0) return null;
			Hashtable otherProcessDescriptions = new Hashtable();
			for(int i = 0; i < n; i++){
				otherProcessDescriptions.Add(processData.other[i].name, processData.other[i].description);
			}
			return otherProcessDescriptions;
		}//getOtherProcessDescriptions

		/// <summary>
		/// get a hashmap of other process values. 
		/// The keys of the hashmap are the process names, and 
		/// the values of the hashmap are the process values.  
		/// </summary>
		/// <returns>a hashmap of other process values, null if no other processes. </returns>
		public Hashtable  getOtherProcessValues(){
			if(processData.other == null) return null;
			int n = processData.other.Length;
			if(n <= 0) return null;
			Hashtable otherProcessValues = new Hashtable();
			for(int i = 0; i < n; i++){
				otherProcessValues.Add(processData.other[i].name, processData.other[i].value);
			}
			return otherProcessValues;
		}//getOtherProcessValues

		/// <summary>
		/// set other processes, with their names (required), descriptions (optional) and values (optional). 
		/// </summary>
		/// <param name="names">holds the names of the other processes; it is required.  </param>
		/// <param name="descriptions">holds the descriptions of the other processes; null if none. </param>
		/// <param name="values">holds the values of the other processes; null if none. </param>
		/// <returns>whether the other anlysis information is set successfully. </returns>
		public bool setOtherProcesses(string[] names, string[] descriptions, string[] values){
			if(names == null) return false;
			if(descriptions != null && descriptions.Length != names.Length) return false;
			if(values != null && values.Length != names.Length) return false;
			int n = names.Length;
			processData.other = new OtherProcess[n];
			for(int i = 0; i < n; i++){
				processData.other[i] = new OtherProcess();
			}
			for(int i = 0; i < n; i++){
				processData.other[i].name = names[i];
			}
			if(descriptions != null){
				for(int i = 0; i < n; i++){
					processData.other[i].description = descriptions[i];
				}	
			}
			if(values != null){
				for(int i = 0; i < n; i++){
					processData.other[i].value = values[i];
				}	
			}
			return true;
		}//setOtherProcesses
	}//class OSProcess
}//namespace
