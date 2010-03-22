/**
 * @(#)OSProcess 1.0 03/14/2005
 *
 * Copyright (c) 2005 
 */
package org.optimizationservices.oscommon.localinterface;

import java.util.GregorianCalendar;
import java.util.Hashtable;

import org.optimizationservices.oscommon.datastructure.osprocess.JobOptimization;
import org.optimizationservices.oscommon.datastructure.osprocess.JobStatistics;
import org.optimizationservices.oscommon.datastructure.osprocess.Jobs;
import org.optimizationservices.oscommon.datastructure.osprocess.OptimizationProcess;
import org.optimizationservices.oscommon.datastructure.osprocess.OtherProcess;
import org.optimizationservices.oscommon.datastructure.osprocess.ProcessData;
import org.optimizationservices.oscommon.datastructure.osprocess.ProcessHeader;
import org.optimizationservices.oscommon.datastructure.osprocess.ProcessRequest;
import org.optimizationservices.oscommon.datastructure.osprocess.ProcessResponse;
import org.optimizationservices.oscommon.datastructure.osprocess.ProcessStatistics;
import org.optimizationservices.oscommon.representationparser.OSpLReader;
import org.optimizationservices.oscommon.representationparser.OSpLWriter;

/**
*
* <P>The <code>OSProcess</code> class is a local interface for storing Optimization Services
* process. Its design follows the Optimization Services process Language (OSpL). 
* All the data structures in this class are standards specified in OSbL. 
*
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2005
* @since OS 1.0
*/

public class OSProcess {

	/**
	 * processHeader holds the first child of the OSProcess specified by the OSpL Schema. 
	 */
	public ProcessHeader processHeader = new ProcessHeader();

	/**
	 * processData holds the second child of the OSProcess specified by the OSpL Schema. 
	 */
	public ProcessData processData = new ProcessData();
	
	/**
	 *
	 * Default constructor. 
	 */
	public OSProcess(){
	}//constructor
	
	/**
	 * read an OSpL instance and return and OSProcess object.  
	 * 
	 * @param ospl holds the optimization process in a string which format follows the
	 * Optimization Services process Language (OSpL) schema.
	 * @param isFile holds whether the ospl string is a file name or a string that literally holds the ospl contents.  
	 * @param validate holds whether the reader should be validating against the schema or not.
	 * @return the OSProcess object constructed from the OSpL String.  
	 * @throws Exception if there are errors in reading the string or setting the OSProcess. 
	 */
   	public OSProcess readOSpL(String ospl, boolean isFile, boolean validate) throws Exception{
   		OSpLReader osplReader = new OSpLReader(validate);
		boolean bRead = false;
		if(isFile){
			bRead = osplReader.readFile(ospl);
		}
		else{
			bRead = osplReader.readString(ospl);			
		}
		if(!bRead) throw new Exception("OSpL string not valid");
		return osplReader.getOSProcess();
   	}//readOSpL
   	
   	/**
   	 * write the OSProcess to an ospl xml string. 
   	 * 
   	 * @return the ospl xml string. 
	 * @throws Exception if there are errors in writing the ospl string. 
   	 */
   	public String writeOSpL() throws Exception{
		OSpLWriter osplWriter = new OSpLWriter();
		osplWriter.setOSProcess(this);
		return osplWriter.writeToString();
   	}//writeOSpL
   	
 	/**
	 * Get the request action, which can be: 
	 * ping, notifyJobCompletion, requestJob, getServiceStatistics, setServiceStatistics, 
	 * getJobStatistics, setJobStatistics, getOptimization, setOptimization, getAll, setAll. 
	 * 
	 * 
	 * @return the request action, null or empty string if none. 
	 */
	public String getRequestAction(){
		if(processHeader.request == null) return null;
		return processHeader.request.action;
	}//getRequestAction
	
 	/**
	 * Set the request action. 
	 * 
	 * 
	 * @param action holds the request action, which can be: 
 	 * ping, notifyJobCompletion, requestJob, getServiceStatistics, setServiceStatistics, 
	 * getJobStatistics, setJobStatistics, getOptimization, setOptimization, getAll, setAll. 
	 * @return whether the requestion action is set successfully.  
	 */
	public boolean setRequestAction(String action){
		if(!action.equals("ping") && 
		   !action.equals("notifyJobCompletion") &&
		   !action.equals("requestJob") &&
		   !action.equals("getServiceStatistics") &&
		   !action.equals("setServiceStatistics") &&
		   !action.equals("getJobStatistics") &&
		   !action.equals("setJobStatistics") &&
		   !action.equals("getOptimization") &&
		   !action.equals("setOptimization") &&
		   !action.equals("getAll") &&
		   !action.equals("setAll")) return false;		   
		if(processHeader.request == null) processHeader.request = new ProcessRequest();
		processHeader.request.action = action;
		return true;
	}//setRequestAction
	
 	/**
	 * Get the request description.
	 * 
	 * @return the request description, null or empty string if none. 
	 */
	public String getRequestDescription(){
		if(processHeader.request == null) return null;
		return processHeader.request.description;
	}//getRequestDescription
	
 	/**
	 * Set the request description.
	 * 
	 * @param description holds the request description
	 * @return whether the requestion description is set successfully.  
	 */
	public boolean setRequestDescription(String description){
		if(processHeader.request == null) processHeader.request = new ProcessRequest();
		processHeader.request.description = description;
		return true;
	}//setRequestDescription
	
 	/**
	 * Get the response status, which can be: 
	 * success, error, warning. 
	 * 
	 * @return the response status, null or empty string if none. 
	 */
	public String getResponseStatus(){
		if(processHeader.response == null) return null;
		return processHeader.response.status;
	}//getResponseStatus
	
 	/**
	 * Set the response status.
	 * 
	 * @param status holds the response status, which can be:
	 * success, error, warning. 
	 * @return  whether the response status is set successfully.
	 */
	public boolean setResponseStatus(String status){
		if(!status.equals("error") && 
		   !status.equals("warning") &&
		   !status.equals("success")) return false;	
		if(processHeader.response == null) processHeader.response = new ProcessResponse();
		processHeader.response.status = status;
		return true;
	}//setResponseStatus

 	/**
	 * Get the response description.
	 * 
	 * @return the response description, null or empty string if none. 
	 */
	public String getResponseDescription(){
		if(processHeader.response == null) return null;
		return processHeader.response.description;
	}//getResponseDescription
	
 	/**
	 * Set the response description.
	 * 
	 * @param description holds the response description
	 * @return  whether the response description is set successfully.   
	 */
	public boolean setResponseDescription(String description){
		if(processHeader.response == null) processHeader.response = new ProcessResponse();
		processHeader.response.description = description;
		return true;
	}//setResponseDescription

	
   	/**
	 * Get service name.
	 * 
	 * @return the service name. 
	 */
	public String getServiceName(){
		return processHeader.serviceName;
	}//getServiceName
	
   	/**
	 * Set service name.
	 * 
	 * @param serviceName holds the name of the service. 
	 * @return whether the service name is set successfully. 
	 */
	public boolean setServiceName(String serviceName){
		processHeader.serviceName = serviceName;
		return true;
	}//setServiceName
	
  	/**
	 * Get service uri.
	 * 
	 * @return the service uri. 
	 */
	public String getServiceURI(){
		return processHeader.serviceURI;
	}//getServiceURI
	
   	/**
	 * Set service uri.
	 * 
	 * @param serviceURI holds the uri of the service. 
	 * @return whether the service uri is set successfully. 
	 */
	public boolean setServiceURI(String serviceURI){
		processHeader.serviceURI = serviceURI;
		return true;
	}//setServiceURI
	
 	/**
	 * Get time of the last process update.
	 * 
	 * @return the time of the last process update.
	 */
	public GregorianCalendar getProcessTime(){
		return processHeader.time;
	}//getProcessTime
	
   	/**
	 * Set time of the last process update.
	 * 
	 * @param time holds the time of the last process update.
	 * @return whether process time is set successfully. 
	 */
	public boolean setProcessTime(GregorianCalendar time){
		processHeader.time = time;
		return true;
	}//setProcessTime
	
   	/**
	 * Get the process message. 
	 * 
	 * @return the process message. 
	 */
	public String getProcessMessage(){
		return processHeader.message;
	}//getProcessMessage
	
   	/**
	 * Set the process message. 
	 * 
	 * @param message holds the process message. 
	 * @return whether process message is set successfully. 
	 */
	public boolean setProcessMessage(String message){
		processHeader.message = message;
		return true;
	}//setProcessMessage
	
	/**
	 * Get the process statistics. 
	 * 
	 * @return the process statistics. 
	 */
	public ProcessStatistics getProcessStatistics(){
		return processData.statistics;
	}//getProcessStatistics
	
	/**
	 * Set the process statistics. 
	 * 
	 * @param processStatistics holds the process statistics. 
	 * @return whether the process statistics is set successfully. 
	 */
	public boolean setProcessStatistics(ProcessStatistics processStatistics){
		processData.statistics = processStatistics;
		return true;
	}//setprocessStatistics
		
	/**
	 * Get the current state, , which can be:
	 * "busy", "busyButAccepting", "idle", "idleButNotAccepting" and "noResponse".
	 * 
	 * @return the current status, "noResponse" if none.
	 */
	public String getCurrentState(){
		if(processData.statistics == null) return "noResponse";
		return processData.statistics.currentState;
	}//getCurrentState

	/**
	 * Set the current state. 
	 * @param currentState holds the current state, which can be:
	 * "busy", "busyButAccepting", "idle", "idleButNotAccepting" or "noResponse".
	 * @return whether the current state is set successfully.
	 */
	public boolean setCurrentState(String currentState){
		if(!currentState.equals("busy") && 
		   !currentState.equals("busyButAccepting") &&
		   !currentState.equals("idle") &&
		   !currentState.equals("idleButNotAccepting") &&
		   !currentState.equals("noResponse")) return false;		 
		if(processData.statistics == null) processData.statistics = new ProcessStatistics();
		processData.statistics.currentState = currentState;
		return true;
	}//setCurrentState
	
	/**
	 * Get the available disk space (in bytes). 
	 * @return the available disk space, Double.NaN if none. 
	 */
	public double getAvailableDiskSpace(){
		if(processData.statistics == null) return Double.NaN;
		return processData.statistics.availableDiskSpace;
	}//getAvailableDiskSpace

	/**
	 * Set the available disk space. 
	 * @param availableDiskSpace holds the available disk space (in bytes). 
	 * @return whether the available disk space is set successfully.
	 */
	public boolean setAvailableDiskSpace(double availableDiskSpace){
		if(processData.statistics == null) processData.statistics = new ProcessStatistics();
		processData.statistics.availableDiskSpace = availableDiskSpace;
		return true;
	}//setAvailableDiskSpace
	
	/**
	 * Get the available memory (in bytes). 
	 * @return the available memory, Double.NaN if none. 
	 */
	public double getAvailableMemory(){
		if(processData.statistics == null) return Double.NaN;
		return processData.statistics.availableMemory;
	}//getAvailableMemory
	
	/**
	 * Set the available memory (in bytes). 
	 * @param availableMemory holds the available memory. 
	 * @return whether the available memory is set successfully.
	 */
	public boolean setAvailableMemory(double availableMemory){
		if(processData.statistics == null) processData.statistics = new ProcessStatistics();
		processData.statistics.availableMemory = availableMemory;
		return true;
	}//setAvailableMemory
	
	/**
	 * Get the current job count. 
	 * @return the current job count, -1 if none. 
	 */
	public int getCurrentJobCount(){
		if(processData.statistics == null) return -1;
		return processData.statistics.currentJobCount;
	}//getCurrentJobCount
	
	/**
	 * Set the current job count. 
	 * @param currentJobCount holds the current job count. 
	 * @return whether the current job count is set successfully.
	 */
	public boolean setCurrentJobCount(int currentJobCount){
		if(processData.statistics == null) processData.statistics = new ProcessStatistics();
		processData.statistics.currentJobCount = currentJobCount;
		return true;
	}//setCurrentJobCount
	
	/**
	 * Get the total jobs received so far. 
	 * @return the total jobs received so far, -1 if none. 
	 */
	public int getTotalJobsSoFar(){
		if(processData.statistics == null) return -1;
		return processData.statistics.totalJobsSoFar;
	}//getTotalJobsSoFar
	
	/**
	 * Set the total jobs received so far. 
	 * @param totalJobsSoFar holds the total jobs received so far. 
	 * @return whether the total jobs so far is set successfully.
	 */
	public boolean setTotalJobsSoFar(int totalJobsSoFar){
		if(processData.statistics == null) processData.statistics = new ProcessStatistics();
		processData.statistics.totalJobsSoFar = totalJobsSoFar;
		return true;
	}//setTotalJobsSoFar
	
	/**
	 * Get the time last job ended. 
	 * @return the time last job ended. If none, it returns unix creation time: GregorianCalendar(1970, 0, 1, 0, 0, 0). 
	 */
	public GregorianCalendar getTimeLastJobEnded(){
		if(processData.statistics == null) return new GregorianCalendar(1970, 0, 1, 0, 0, 0);
		return processData.statistics.timeLastJobEnded;
	}//getTimeLastJobEnded
	
	/**
	 * Set the time last job ended. 
	 * @param timeLastJobEnded holds the time last job ended. 
	 * @return whether the time last job ended is set successfully.
	 */
	public boolean setTimeLastJobEnded(GregorianCalendar timeLastJobEnded){
		if(processData.statistics == null) processData.statistics = new ProcessStatistics();
		processData.statistics.timeLastJobEnded = timeLastJobEnded;
		return true;
	}//setTimeLastJobEnded
	
	/**
	 * Get the time last job took (in seconds). 
	 * @return the the time last job took, Double.NaN if none. 
	 */
	public double getTimeLastJobTook(){
		if(processData.statistics == null) return Double.NaN;
		return processData.statistics.timeLastJobTook;
	}//getTimeLastJobTook
	
	/**
	 * Set the time last job took. 
	 * @param timeLastJobTook holds the time last job took (in seconds). 
	 * @return whether the time last job took is set successfully.
	 */
	public boolean setTimeLastJobTook(double timeLastJobTook){
		if(processData.statistics == null) processData.statistics = new ProcessStatistics();
		processData.statistics.timeLastJobTook = timeLastJobTook;
		return true;
	}//setTimeLastJobTook
	
	/**
	 * Get the time the service started. 
	 * @return the time last job ended. If none, it returns unix creation time: GregorianCalendar(1970, 0, 1, 0, 0, 0). 
	 */
	public GregorianCalendar getTimeServiceStarted(){
		if(processData.statistics == null) return new GregorianCalendar(1970, 0, 1, 0, 0, 0);
		return processData.statistics.timeServiceStarted;
	}//getTimeServiceStarted
	
	/**
	 * Set the time the service started. 
	 * @param timeServiceStarted holds the time the service started. 
	 * @return whether the time the service started is set successfully.
	 */
	public boolean setTimeServiceStarted(GregorianCalendar timeServiceStarted){
		if(processData.statistics == null) processData.statistics = new ProcessStatistics();
		processData.statistics.timeServiceStarted = timeServiceStarted;
		return true;
	}//setTimeServiceStarted
	
	/**
	 * Get the service utilization ([0, 1]). 
	 * @return the the time last job took, Double.NaN if none. 
	 */
	public double getServiceUtilization(){
		if(processData.statistics == null) return Double.NaN;
		return processData.statistics.serviceUtilization;
	}//getServiceUtilization
	
	/**
	 * Set the service utilization. 
	 * @param serviceUtilization holds the service utilization ([0, 1]). 
	 * @return whether the time last job took is set successfully.
	 */
	public boolean setServiceUtilization(double serviceUtilization){
		if(processData.statistics == null) processData.statistics = new ProcessStatistics();
		processData.statistics.serviceUtilization = serviceUtilization;
		return true;
	}//setServiceUtilization
	
	/**
	 * Get the statistics of all the jobs. 
	 * 
	 * @return the statistics of all the jobs, which is an array of jobStatistics with 
	 * each member corresponding to one job; null if none. 
	 */
	public JobStatistics[] getJobStatistics(){
		if(processData.statistics == null) return null;
		if(processData.statistics.jobs == null) return null;
		return processData.statistics.jobs.job;
	}//getJobStatistics
	
	/**
	 * Set the statistics of all jobs. 
	 * 
	 * @param jobStatistics holds an array of jobStatistics with 
	 * each member corresponding to one job. 
	 * @return whether the job statistics are set successfully. 
	 */
	public boolean setJobStatistics(JobStatistics[] jobStatistics){
		if(processData.statistics == null) processData.statistics = new ProcessStatistics();
		if(processData.statistics.jobs == null) processData.statistics.jobs = new Jobs();
		processData.statistics.jobs.job = jobStatistics;
		return true;
	}//setJobStatistics

	/**
	 * Get the optimization process of all the jobs, which are in effect
	 * intermediate (or occasionally final) optimization results. The intermediate process 
	 * can be some pre-built standard optimization information and/or the standard OSrL (Optimization Services result Language).  
	 * 
	 * @return the optimization process, null if none. It contains an array, with each member 
	 * corresponding to an optimization job. Each optimization job has a job id string; 
	 * and contains some pre-built standard optimization information and/or 
	 * an optimization result, which data structure follow the OSrL schema.  
	 * 
	 */
	public OptimizationProcess getOptimizationProcess(){
		return processData.optimization;
	}//getOptimizationProcess
	
	/**
	 * Set the optimization process of all the jobs, which are in effect
	 * intermediate (or occasionally final) optimization results. The intermediate process 
	 * can be some pre-built standard optimization information and/or the standard OSrL (Optimization Services result Language).  
	 * 
	 * @param optimizationProcess contain holds the optimization process information which 
	 * contains an array, with each member corresponding to an optimization job. Each optimization job contains a job id string 
	 * and an optimization result, which data structure follow the OSrL schema.  
	 * @return whether the optimization process is set successfully. 
	 */
	public boolean setOptimizationProcess(OptimizationProcess optimizationProcess){
		processData.optimization = optimizationProcess;
		return true;
	}//setOptimizationProcess

	/**
	 * get a string array of names of other processes. 
	 * 
	 * @return a string array of names of other processes, null if no other processes.  
	 */
	public String[] getOtherProcessNames(){
		if(processData.other == null) return null;
		int n = processData.other.length;
		if(n <= 0) return null;
		String[] otherProcessNames = new String[n];
		for(int i = 0; i < n; i++){
			otherProcessNames[i] = processData.other[i].name;
		}
		return otherProcessNames;
	}//getOtherProcessNames
	
	/**
	 * get a hashmap of other process descriptions. 
	 * The keys of the hashmap are the process names, and 
	 * the values of the hashmap are the process descriptions.  
	 * 
	 * @return a hashmap of other process descriptions, null if no other processes. 
	 */
	public Hashtable<String, String>  getOtherProcessDescriptions(){
		if(processData.other == null) return null;
		int n = processData.other.length;
		if(n <= 0) return null;
		Hashtable<String, String> otherProcessDescriptions = new Hashtable<String, String>();
		for(int i = 0; i < n; i++){
			otherProcessDescriptions.put(processData.other[i].name, processData.other[i].description);
		}
		return otherProcessDescriptions;
	}//getOtherProcessDescriptions

	/**
	 * get a hashmap of other process values. 
	 * The keys of the hashmap are the process names, and 
	 * the values of the hashmap are the process values.  
	 * 
	 * @return a hashmap of other process values, null if no other processes. 
	 */
	public Hashtable<String, String>  getOtherProcessValues(){
		if(processData.other == null) return null;
		int n = processData.other.length;
		if(n <= 0) return null;
		Hashtable<String, String> otherProcessValues = new Hashtable<String, String>();
		for(int i = 0; i < n; i++){
			otherProcessValues.put(processData.other[i].name, processData.other[i].value);
		}
		return otherProcessValues;
	}//getOtherProcessValues

	/**
	 * set other processes, with their names (required), descriptions (optional) and values (optional). 
	 * 
	 * @param names holds the names of the other processes; it is required.  
	 * @param descriptions holds the descriptions of the other processes; null if none. 
	 * @param values holds the values of the other processes; null if none. 
	 * @return whether the other anlysis information is set successfully. 
	 */
	public boolean setOtherProcesses(String[] names, String[] descriptions, String[] values){
		if(names == null) return false;
		if(descriptions != null && descriptions.length != names.length) return false;
		if(values != null && values.length != names.length) return false;
		int n = names.length;
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
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] args){
		
	}//main
}//class OSProcess

