/**
 * @(#)OSaLReader 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.representationparser;

import java.util.Collection;
import java.util.GregorianCalendar;
import java.util.HashMap;
import java.util.Set;
import java.util.Vector;

import org.optimizationservices.oscommon.datastructure.osgeneral.JobDependencies;
import org.optimizationservices.oscommon.datastructure.osgeneral.DirectoriesAndFiles;
import org.optimizationservices.oscommon.datastructure.osprocess.JobOptimization;
import org.optimizationservices.oscommon.datastructure.osprocess.JobStatistics;
import org.optimizationservices.oscommon.datastructure.osprocess.Jobs;
import org.optimizationservices.oscommon.datastructure.osprocess.OptimizationProcess;
import org.optimizationservices.oscommon.datastructure.osprocess.OptimizationUpdate;
import org.optimizationservices.oscommon.datastructure.osprocess.ProcessStatistics;
import org.optimizationservices.oscommon.datastructure.osprocess.StandardOptimizationProcessInformation;
import org.optimizationservices.oscommon.datastructure.osprocess.UpdatedConstraintValues;
import org.optimizationservices.oscommon.datastructure.osprocess.UpdatedDualValues;
import org.optimizationservices.oscommon.datastructure.osprocess.UpdatedVariableReducedCosts;
import org.optimizationservices.oscommon.datastructure.osprocess.UpdatedVariableValues;
import org.optimizationservices.oscommon.datastructure.osprocess.UpdatedVariableValuesString;
import org.optimizationservices.oscommon.localinterface.OSProcess;
import org.optimizationservices.oscommon.localinterface.OSResult;
import org.optimizationservices.oscommon.util.IOUtil;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.XMLUtil;
import org.w3c.dom.Element;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

/**
 * The <c>OSpLReader</c> class parses an OSpL instance into a DOM tree and
 * provides a set of "get" methods that can be used to retrieve different 
 * pieces of information of the instance.
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */
public class OSpLReader extends OSgLReader{
	/**
	 * m_osProcess holds the standard OSProcess, which is a local interface for 
	 * storing Optimization Services process. 
	 */
	protected OSProcess m_osProcess = null;

	/**
	 * m_otherProcessHashMap holds a hash map of other alalyses.
	 */
	protected HashMap <String, String>	m_otherProcessHashMap = null;

	/**
	 * m_otherProcessDescriptionHashMap holds a hash map of other processes' descriptions.
	 */
	protected HashMap <String, String>	m_otherProcessDescriptionHashMap = null;

	/**
	 * constructor.
	 * @param validate holds whether the reader	should be validating against the schema	or not.
	 */
	public OSpLReader(boolean validate){
		m_bXsdValidate = validate;
	}//constructor

	/**
	 * Default	constructor. 
	 *
	 */
	public OSpLReader(){
	}//constructor

	/**
	 * get the standard OSProcess, a local interface for 
	 * storing Optimization Services process.
	 * 
	 * @return the OSProcess. 
	 * @throws Exception if there are errors getting the OSOption. 
	 */
	public OSProcess getOSProcess() throws Exception{
		if(m_osProcess != null){
			return m_osProcess;
		}
		m_osProcess = new OSProcess();
		String sRequestAction = getRequestAction();
		String sResponseStatus = getResponseStatus();
		if(sRequestAction != null && sRequestAction.length() > 0){
			if(!m_osProcess.setRequestAction(getRequestAction())) throw new Exception("setRequestAction Unsuccessful");
			if(!m_osProcess.setRequestDescription(getRequestDescription())) throw new Exception("setRequestDescription Unsuccessful");
		}
		else if(sResponseStatus != null && sResponseStatus.length() > 0){
			if(!m_osProcess.setResponseStatus(getResponseStatus())) throw new Exception("setResponseStatus Unsuccessful");
			if(!m_osProcess.setResponseDescription(getResponseDescription())) throw new Exception("setResponseDescription Unsuccessful");
		}
		if(!m_osProcess.setServiceURI(getServiceURI())) throw new Exception("setServiceURI Unsuccessful");
		if(!m_osProcess.setServiceName(getServiceName())) throw new Exception("setServiceName Unsuccessful");
		if(!m_osProcess.setProcessTime(getProcessTime())) throw new Exception("setProcessTime Unsuccessful");
		if(!m_osProcess.setProcessMessage(getProcessMessage())) throw new Exception("setProcessMessage Unsuccessful");
		if(!m_osProcess.setProcessStatistics(getProcessStatistics())) throw new Exception("setProcessStatistics Unsuccessful");
		if(!m_osProcess.setOptimizationProcess(getOptimizationProcess()))throw new Exception("setOptimizationProcess Unsuccessful");
		if(!m_osProcess.setOtherProcesses(getOtherProcessNames(), getOtherProcessDescriptions(), getOtherProcessValues())) throw new Exception("setOtherProcessInfo Unsuccessful");

		return m_osProcess;
	}//getOSProcess

	/**
	 * Get the request action, which can be: 
	 * ping, notifyJobCompletion, requestJob, getServiceStatistics, setServiceStatistics, 
	 * getJobStatistics, setJobStatistics, getOptimization, setOptimization, getAll, setAll. 
	 * 
	 * 
	 * @return the request action, null or empty string if none. 
	 */
	public String getRequestAction(){
		Element eProcessHeader = (Element)XMLUtil.findChildNode(m_eRoot, "processHeader");
		Element eRequest = (Element)XMLUtil.findChildNode(eProcessHeader, "request");
		if(eRequest == null) return null;
		String sRequestAction = eRequest.getAttribute("action");
		return sRequestAction;
	}//getRequestAction


	/**
	 * Get the request description.
	 * 
	 * @return the request description, null or empty string if none. 
	 */
	public String getRequestDescription(){
		Element eProcessHeader = (Element)XMLUtil.findChildNode(m_eRoot, "processHeader");
		Element eRequest = (Element)XMLUtil.findChildNode(eProcessHeader, "request");
		if(eRequest == null) return null;
		String sRequestDescription = XMLUtil.getElementValue(eRequest);
		return sRequestDescription;
	}//getRequestDescription

	/**
	 * Get the response status, which can be: 
	 * success, error, warning. 
	 * 
	 * @return the response status, null or empty string if none. 
	 */
	public String getResponseStatus(){
		Element eProcessHeader = (Element)XMLUtil.findChildNode(m_eRoot, "processHeader");
		Element eResponse = (Element)XMLUtil.findChildNode(eProcessHeader, "response");
		if(eResponse == null) return null;
		String sResponseStatus = eResponse.getAttribute("status");
		return sResponseStatus;
	}//getResponseStatus

	/**
	 * Get the response description.
	 * 
	 * @return the response description, null or empty string if none. 
	 */
	public String getResponseDescription(){
		Element eProcessHeader = (Element)XMLUtil.findChildNode(m_eRoot, "processHeader");
		Element eResponse = (Element)XMLUtil.findChildNode(eProcessHeader, "response");
		if(eResponse == null) return null;
		String sResponseDescription = XMLUtil.getElementValue(eResponse);
		return sResponseDescription;
	}//getResponseDescription

	/**
	 * Get service uri.
	 * 
	 * @return the service uri. 
	 */
	public String getServiceURI(){
		Element eProcessHeader = (Element)XMLUtil.findChildNode(m_eRoot, "processHeader");
		String sServiceURI = XMLUtil.getElementValueByName(eProcessHeader, "serviceURI");
		if(sServiceURI == null) sServiceURI = "";
		return sServiceURI;	
	}//getServiceURI

	/**
	 * Get service name.
	 * 
	 * @return the service name. 
	 */
	public String getServiceName(){
		Element eProcessHeader = (Element)XMLUtil.findChildNode(m_eRoot, "processHeader");
		String sServiceName = XMLUtil.getElementValueByName(eProcessHeader, "serviceName");
		if(sServiceName == null) sServiceName = "";
		return sServiceName;	
	}//getServiceName


	/**
	 * Get time of the last process update.
	 * 
	 * @return the time of the last process update.
	 */
	public GregorianCalendar getProcessTime(){
		Element eProcessHeader = (Element)XMLUtil.findChildNode(m_eRoot, "processHeader");
		String sProcessTime = XMLUtil.getElementValueByName(eProcessHeader, "time");
		if(sProcessTime == null) return null;
		GregorianCalendar date = XMLUtil.createNativeDateTime(sProcessTime);
		return date;
	}//getProcessTime

	/**
	 * Get the process message. 
	 * 
	 * @return the process message. 
	 */
	public String getProcessMessage(){
		Element eProcessHeader = (Element)XMLUtil.findChildNode(m_eRoot, "processHeader");
		String sMessage = XMLUtil.getElementValueByName(eProcessHeader, "message");
		if(sMessage == null) sMessage = "";
		return sMessage;
	}//getProcessMessage

	/**
	 * Get the process statistics. 
	 * 
	 * @return the process statistics. 
	 */
	public ProcessStatistics getProcessStatistics(){
		Element eProcessData = (Element)XMLUtil.findChildNode(m_eRoot, "processData");
		Element eStatistics = (Element)XMLUtil.findChildNode(eProcessData, "statistics");
		if(eStatistics == null) return null;
		ProcessStatistics processStatistics = new ProcessStatistics();
		String sValue = "";
		int iValue;
		double dValue;
		sValue =  XMLUtil.getElementValueByName(eStatistics, "currentState");
		if(sValue != null && sValue.length() > 0){
			processStatistics.currentState = sValue;
		}
		try {
			sValue =  XMLUtil.getElementValueByName(eStatistics, "availableDiskSpace");
			if(sValue != null && sValue.length() > 0){
				if(sValue.equals("INF")) {
					processStatistics.availableDiskSpace = Double.POSITIVE_INFINITY;
				}
				else{
					dValue = Double.parseDouble(sValue);
					processStatistics.availableDiskSpace = dValue;
				}
			}
		} 
		catch (Exception e) {
			processStatistics.availableDiskSpace = Double.NaN;
		}
		try {
			sValue =  XMLUtil.getElementValueByName(eStatistics, "availableMemory");
			if(sValue != null && sValue.length() > 0){
				if(sValue.equals("INF")) {
					processStatistics.availableMemory = Double.POSITIVE_INFINITY;
				}
				else{
					dValue = Double.parseDouble(sValue);
					processStatistics.availableMemory = dValue;
				}
			}
		} 
		catch (Exception e) {
			processStatistics.availableMemory = Double.NaN;
		}
		try {
			sValue =  XMLUtil.getElementValueByName(eStatistics, "currentJobCount");
			if(sValue != null && sValue.length() > 0){
				iValue = Integer.parseInt(sValue);
				processStatistics.currentJobCount = iValue;
			}
		} 
		catch (Exception e) {
			processStatistics.currentJobCount = -1;
		}
		try {
			sValue =  XMLUtil.getElementValueByName(eStatistics, "totalJobsSoFar");
			if(sValue != null && sValue.length() > 0){
				iValue = Integer.parseInt(sValue);
				processStatistics.totalJobsSoFar = iValue;
			}
		} 
		catch (Exception e) {
			processStatistics.totalJobsSoFar = -1;
		}
		try {
			sValue =  XMLUtil.getElementValueByName(eStatistics, "timeLastJobEnded");
			if(sValue != null && sValue.length() > 0){
				processStatistics.timeLastJobEnded = XMLUtil.createNativeDateTime(sValue);
			}
		} 
		catch (Exception e) {
			processStatistics.timeLastJobEnded = new GregorianCalendar(1970, 0, 1, 0, 0, 0);
		}
		try {
			sValue =  XMLUtil.getElementValueByName(eStatistics, "timeLastJobTook");
			if(sValue != null && sValue.length() > 0){
				if(sValue.equals("INF")) {
					processStatistics.timeLastJobTook = Double.POSITIVE_INFINITY;
				}
				else{
					dValue = Double.parseDouble(sValue);
					processStatistics.timeLastJobTook = dValue;
				}
			}
		} 
		catch (Exception e) {
			processStatistics.timeLastJobTook = Double.NaN;
		}
		try {
			sValue =  XMLUtil.getElementValueByName(eStatistics, "timeServiceStarted");
			if(sValue != null && sValue.length() > 0){
				processStatistics.timeServiceStarted = XMLUtil.createNativeDateTime(sValue);
			}
		} 
		catch (Exception e) {
			processStatistics.timeServiceStarted = new GregorianCalendar(1970, 0, 1, 0, 0, 0);
		}
		try {
			sValue =  XMLUtil.getElementValueByName(eStatistics, "serviceUtilization");
			if(sValue != null && sValue.length() > 0){
				if(sValue.equals("INF")) {
					processStatistics.serviceUtilization = Double.POSITIVE_INFINITY;
				}
				else{
					dValue = Double.parseDouble(sValue);
					processStatistics.serviceUtilization = dValue;
				}
			}
		} 
		catch (Exception e) {
			processStatistics.serviceUtilization = Double.NaN;
		}
		Element eJobs = (Element)XMLUtil.findChildNode(eStatistics, "jobs");
		if(eJobs == null) return processStatistics;
		NodeList jobList = eJobs.getElementsByTagName("job");
		if(jobList == null || jobList.getLength() <= 0) return processStatistics;
		processStatistics.jobs = new Jobs();
		int iJobs = jobList.getLength();
		processStatistics.jobs.job = new JobStatistics[iJobs];
		for(int i = 0; i < iJobs; i++){
			processStatistics.jobs.job[i] = new JobStatistics();
			Element eJob = (Element)jobList.item(i);
			sValue =  eJob.getAttribute("jobID");
			if(sValue != null && sValue.length() > 0){
				processStatistics.jobs.job[i].jobID = sValue;
			}
			sValue =  XMLUtil.getElementValueByName(eJob, "state");
			if(sValue != null && sValue.length() > 0){
				processStatistics.jobs.job[i].state = sValue;
			}
			sValue =  XMLUtil.getElementValueByName(eJob, "serviceURI");
			if(sValue != null && sValue.length() > 0){
				processStatistics.jobs.job[i].serviceURI = sValue;
			}
			sValue =  XMLUtil.getElementValueByName(eJob, "userName");
			if(sValue != null && sValue.length() > 0){
				processStatistics.jobs.job[i].userName = sValue;
			}
			try {
				sValue =  XMLUtil.getElementValueByName(eJob, "submitTime");
				if(sValue != null && sValue.length() > 0){
					processStatistics.jobs.job[i].submitTime = XMLUtil.createNativeDateTime(sValue);
				}
			} 
			catch (Exception e) {
				processStatistics.jobs.job[i].submitTime = new GregorianCalendar(1970, 0, 1, 0, 0, 0);
			}
			try {
				sValue =  XMLUtil.getElementValueByName(eJob, "startTime");
				if(sValue != null && sValue.length() > 0){
					processStatistics.jobs.job[i].startTime = XMLUtil.createNativeDateTime(sValue);
				}
			} 
			catch (Exception e) {
				processStatistics.jobs.job[i].startTime = new GregorianCalendar(1970, 0, 1, 0, 0, 0);
			}
			try {
				sValue =  XMLUtil.getElementValueByName(eJob, "endTime");
				if(sValue != null && sValue.length() > 0){
					processStatistics.jobs.job[i].endTime = XMLUtil.createNativeDateTime(sValue);
				}
			} 
			catch (Exception e) {
				processStatistics.jobs.job[i].endTime = new GregorianCalendar(1970, 0, 1, 0, 0, 0);
			}
			try {
				sValue =  XMLUtil.getElementValueByName(eJob, "duration");
				if(sValue != null && sValue.length() > 0){
					if(sValue.equals("INF")) {
						processStatistics.jobs.job[i].duration = Double.POSITIVE_INFINITY;
					}
					else{
						dValue = Double.parseDouble(sValue);
						processStatistics.jobs.job[i].duration = dValue;
					}
				}
			} 
			catch (Exception e) {
				processStatistics.jobs.job[i].duration = Double.NaN;
			}
			try {
				sValue =  XMLUtil.getElementValueByName(eJob, "scheduledStartTime");
				if(sValue != null && sValue.length() > 0){
					processStatistics.jobs.job[i].scheduledStartTime = XMLUtil.createNativeDateTime(sValue);
				}
			} 
			catch (Exception e) {
				processStatistics.jobs.job[i].scheduledStartTime = new GregorianCalendar(1970, 0, 1, 0, 0, 0);
			}
			Element eDependencies = (Element)XMLUtil.findChildNode(eJob, "dependencies");
			if(eDependencies != null){
				NodeList jobIDList = eDependencies.getElementsByTagName("jobID");
				if(jobIDList != null && jobIDList.getLength() > 0){
					int iJobIDs = jobIDList.getLength();
					processStatistics.jobs.job[i].dependencies = new JobDependencies();
					processStatistics.jobs.job[i].dependencies.jobID = new String[iJobIDs];
					for(int j = 0; j < iJobIDs; j++){
						Element eJobID = (Element)jobIDList.item(j);
						processStatistics.jobs.job[i].dependencies.jobID[j] =  XMLUtil.getElementValue(eJobID);
					}				
				}
			}
			Element eRequiredDirectories = (Element)XMLUtil.findChildNode(eJob, "requiredDirectories");			
			if(eRequiredDirectories != null){
				NodeList pathList = eRequiredDirectories.getElementsByTagName("path");
				if(pathList != null && pathList.getLength() > 0){
					int iPaths = pathList.getLength();
					processStatistics.jobs.job[i].requiredDirectories = new DirectoriesAndFiles();
					processStatistics.jobs.job[i].requiredDirectories.path = new String[iPaths];
					for(int j = 0; j < iPaths; j++){
						Element ePath = (Element)pathList.item(j);
						processStatistics.jobs.job[i].requiredDirectories.path[j] =  XMLUtil.getElementValue(ePath);
					}				
				}
			}
			Element eRequiredFiles = (Element)XMLUtil.findChildNode(eJob, "requiredFiles");			
			if(eRequiredFiles != null){
				NodeList pathList = eRequiredFiles.getElementsByTagName("path");
				if(pathList != null && pathList.getLength() > 0){
					int iPaths = pathList.getLength();
					processStatistics.jobs.job[i].requiredFiles = new DirectoriesAndFiles();
					processStatistics.jobs.job[i].requiredFiles.path = new String[iPaths];
					for(int j = 0; j < iPaths; j++){
						Element ePath = (Element)pathList.item(j);
						processStatistics.jobs.job[i].requiredFiles.path[j] =  XMLUtil.getElementValue(ePath);
					}				
				}
			}
		}
		return processStatistics;
	}//getProcessStatistics

	/**
	 * Get the current state, , which can be:
	 * "busy", "busyButAccepting", "idle", "idleButNotAccepting" and "noResponse".
	 * 
	 * @return the current status, "noResponse" if none.
	 */
	public String getCurrentState(){
		Element eProcessData = (Element)XMLUtil.findChildNode(m_eRoot, "processData");
		Element eStatistics = (Element)XMLUtil.findChildNode(eProcessData, "statistics");
		if(eStatistics == null) return "noResponse";
		String sValue =  XMLUtil.getElementValueByName(eStatistics, "currentState");
		if(sValue == null || sValue.length() <= 0){
			return "noResponse";
		}
		return sValue;
	}//getCurrentState

	/**
	 * Get the available disk space (in bytes). 
	 * @return the available disk space, Double.NaN if none. 
	 */
	public double getAvailableDiskSpace(){
		Element eProcessData = (Element)XMLUtil.findChildNode(m_eRoot, "processData");
		Element eStatistics = (Element)XMLUtil.findChildNode(eProcessData, "statistics");
		if(eStatistics == null) return Double.NaN;
		String sValue =  XMLUtil.getElementValueByName(eStatistics, "availableDiskSpace");
		Double dValue;
		if(sValue == null || sValue.length() <= 0){
			return Double.NaN;
		}		
		try {
			if(sValue.equals("INF")) {
				dValue = Double.POSITIVE_INFINITY;
			}
			else{
				dValue = Double.parseDouble(sValue);
			}
		}
		catch (Exception e) {
			dValue = Double.NaN;
		}
		return dValue;
	}//getAvailableDiskSpace


	/**
	 * Get the available memory (in bytes). 
	 * @return the available memory, Double.NaN if none. 
	 */
	public double getAvailableMemory(){
		Element eProcessData = (Element)XMLUtil.findChildNode(m_eRoot, "processData");
		Element eStatistics = (Element)XMLUtil.findChildNode(eProcessData, "statistics");
		if(eStatistics == null) return Double.NaN;
		String sValue =  XMLUtil.getElementValueByName(eStatistics, "availableMemory");
		Double dValue;
		if(sValue == null || sValue.length() <= 0){
			return Double.NaN;
		}		
		try {
			if(sValue.equals("INF")) {
				dValue = Double.POSITIVE_INFINITY;
			}
			else{
				dValue = Double.parseDouble(sValue);
			}
		}
		catch (Exception e) {
			dValue = Double.NaN;
		}
		return dValue;
	}//getAvailableMemory

	/**
	 * Get the current job count. 
	 * @return the current job count, -1 if none. 
	 */
	public int getCurrentJobCount(){
		Element eProcessData = (Element)XMLUtil.findChildNode(m_eRoot, "processData");
		Element eStatistics = (Element)XMLUtil.findChildNode(eProcessData, "statistics");
		if(eStatistics == null) return -1;
		String sValue =  XMLUtil.getElementValueByName(eStatistics, "currentJobCount");
		int iValue;
		if(sValue == null || sValue.length() <= 0){
			return -1;
		}		
		try {
			iValue = Integer.parseInt(sValue);
		}
		catch (Exception e) {
			iValue = -1;
		}
		return iValue;
	}//getCurrentJobCount

	/**
	 * Get the total jobs received so far. 
	 * @return the total jobs received so far, -1 if none. 
	 */
	public int getTotalJobsSoFar(){
		Element eProcessData = (Element)XMLUtil.findChildNode(m_eRoot, "processData");
		Element eStatistics = (Element)XMLUtil.findChildNode(eProcessData, "statistics");
		if(eStatistics == null) return -1;
		String sValue =  XMLUtil.getElementValueByName(eStatistics, "totalJobsSoFar");
		int iValue;
		if(sValue == null || sValue.length() <= 0){
			return -1;
		}		
		try {
			iValue = Integer.parseInt(sValue);
		}
		catch (Exception e) {
			iValue = -1;
		}
		return iValue;
	}//getTotalJobsSoFar

	/**
	 * Get the time last job ended. 
	 * @return the time last job ended. If none, it returns unix creation time: GregorianCalendar(1970, 0, 1, 0, 0, 0). 
	 */
	public GregorianCalendar getTimeLastJobEnded(){
		Element eProcessData = (Element)XMLUtil.findChildNode(m_eRoot, "processData");
		Element eStatistics = (Element)XMLUtil.findChildNode(eProcessData, "statistics");
		if(eStatistics == null) return new GregorianCalendar(1970, 0, 1, 0, 0, 0);
		String sValue =  XMLUtil.getElementValueByName(eStatistics, "timeLastJobEnded");
		if(sValue == null || sValue.length() <= 0) return new GregorianCalendar(1970, 0, 1, 0, 0, 0);
		try{
			GregorianCalendar time = XMLUtil.createNativeDateTime(sValue);
			if(time == null)  return new GregorianCalendar(1970, 0, 1, 0, 0, 0);
			return time;
		}
		catch(Exception e){
			return new GregorianCalendar(1970, 0, 1, 0, 0, 0);
		}
	}//getTimeLastJobEnded

	/**
	 * Get the time last job took (in seconds). 
	 * @return the the time last job took, Double.NaN if none. 
	 */
	public double getTimeLastJobTook(){
		Element eProcessData = (Element)XMLUtil.findChildNode(m_eRoot, "processData");
		Element eStatistics = (Element)XMLUtil.findChildNode(eProcessData, "statistics");
		if(eStatistics == null) return Double.NaN;
		String sValue =  XMLUtil.getElementValueByName(eStatistics, "timeLastJobTook");
		Double dValue;
		if(sValue == null || sValue.length() <= 0){
			return Double.NaN;
		}		
		try {
			if(sValue.equals("INF")) {
				dValue = Double.POSITIVE_INFINITY;
			}
			else{
				dValue = Double.parseDouble(sValue);
			}
		}
		catch (Exception e) {
			dValue = Double.NaN;
		}
		return dValue;
	}//getTimeLastJobTook

	/**
	 * Get the time the service started. 
	 * @return the time last job ended. If none, it returns unix creation time: GregorianCalendar(1970, 0, 1, 0, 0, 0). 
	 */
	public GregorianCalendar getTimeServiceStarted(){
		Element eProcessData = (Element)XMLUtil.findChildNode(m_eRoot, "processData");
		Element eStatistics = (Element)XMLUtil.findChildNode(eProcessData, "statistics");
		if(eStatistics == null) return new GregorianCalendar(1970, 0, 1, 0, 0, 0);
		String sValue =  XMLUtil.getElementValueByName(eStatistics, "timeServiceStarted");
		if(sValue == null || sValue.length() <= 0) return new GregorianCalendar(1970, 0, 1, 0, 0, 0);
		try{
			GregorianCalendar time = XMLUtil.createNativeDateTime(sValue);
			if(time == null)  return new GregorianCalendar(1970, 0, 1, 0, 0, 0);
			return time;
		}
		catch(Exception e){
			return new GregorianCalendar(1970, 0, 1, 0, 0, 0);
		}
	}//getTimeServiceStarted

	/**
	 * Get the service utilization ([0, 1]). 
	 * @return the the time last job took, Double.NaN if none. 
	 */
	public double getServiceUtilization(){
		Element eProcessData = (Element)XMLUtil.findChildNode(m_eRoot, "processData");
		Element eStatistics = (Element)XMLUtil.findChildNode(eProcessData, "statistics");
		if(eStatistics == null) return Double.NaN;
		String sValue =  XMLUtil.getElementValueByName(eStatistics, "serviceUtilization");
		Double dValue;
		if(sValue == null || sValue.length() <= 0){
			return Double.NaN;
		}		
		try {
			if(sValue.equals("INF")) {
				dValue = Double.POSITIVE_INFINITY;
			}
			else{
				dValue = Double.parseDouble(sValue);
			}
		}
		catch (Exception e) {
			dValue = Double.NaN;
		}
		return dValue;
	}//getServiceUtilization

	/**
	 * Get the statistics of all the jobs. 
	 * 
	 * @return the statistics of all the jobs, which is an array of jobStatistics with 
	 * each member corresponding to one job; null if none. 
	 */
	public JobStatistics[] getJobStatistics(){
		Element eProcessData = (Element)XMLUtil.findChildNode(m_eRoot, "processData");
		Element eStatistics = (Element)XMLUtil.findChildNode(eProcessData, "statistics");
		if(eStatistics == null) return null;
		Element eJobs = (Element)XMLUtil.findChildNode(eStatistics, "jobs");
		if(eJobs == null) return null;
		NodeList jobList = eJobs.getElementsByTagName("job");
		if(jobList == null || jobList.getLength() <= 0) return null;
		Jobs jobs = new Jobs();
		int iJobs = jobList.getLength();
		jobs.job = new JobStatistics[iJobs];
		String sValue = "";
		double dValue;
		for(int i = 0; i < iJobs; i++){
			jobs.job[i] = new JobStatistics();
			Element eJob = (Element)jobList.item(i);
			sValue =  eJob.getAttribute("jobID");
			if(sValue != null && sValue.length() > 0){
				jobs.job[i].jobID = sValue;
			}
			sValue =  XMLUtil.getElementValueByName(eJob, "state");
			if(sValue != null && sValue.length() > 0){
				jobs.job[i].state = sValue;
			}
			sValue =  XMLUtil.getElementValueByName(eJob, "serviceURI");
			if(sValue != null && sValue.length() > 0){
				jobs.job[i].serviceURI = sValue;
			}
			sValue =  XMLUtil.getElementValueByName(eJob, "userName");
			if(sValue != null && sValue.length() > 0){
				jobs.job[i].userName = sValue;
			}
			try {
				sValue =  XMLUtil.getElementValueByName(eJob, "submitTime");
				if(sValue != null && sValue.length() > 0){
					jobs.job[i].submitTime = XMLUtil.createNativeDateTime(sValue);
				}
			} 
			catch (Exception e) {
				jobs.job[i].submitTime = new GregorianCalendar(1970, 0, 1, 0, 0, 0);
			}
			try {
				sValue =  XMLUtil.getElementValueByName(eJob, "startTime");
				if(sValue != null && sValue.length() > 0){
					jobs.job[i].startTime = XMLUtil.createNativeDateTime(sValue);
				}
			} 
			catch (Exception e) {
				jobs.job[i].startTime = new GregorianCalendar(1970, 0, 1, 0, 0, 0);
			}
			try {
				sValue =  XMLUtil.getElementValueByName(eJob, "endTime");
				if(sValue != null && sValue.length() > 0){
					jobs.job[i].endTime = XMLUtil.createNativeDateTime(sValue);
				}
			} 
			catch (Exception e) {
				jobs.job[i].endTime = new GregorianCalendar(1970, 0, 1, 0, 0, 0);
			}
			try {
				sValue =  XMLUtil.getElementValueByName(eJob, "duration");
				if(sValue != null && sValue.length() > 0){
					if(sValue.equals("INF")) {
						jobs.job[i].duration = Double.POSITIVE_INFINITY;
					}
					else{
						dValue = Double.parseDouble(sValue);
						jobs.job[i].duration = dValue;
					}
				}
			} 
			catch (Exception e) {
				jobs.job[i].duration = Double.NaN;
			}
			try {
				sValue =  XMLUtil.getElementValueByName(eJob, "scheduledStartTime");
				if(sValue != null && sValue.length() > 0){
					jobs.job[i].scheduledStartTime = XMLUtil.createNativeDateTime(sValue);
				}
			} 
			catch (Exception e) {
				jobs.job[i].scheduledStartTime = new GregorianCalendar(1970, 0, 1, 0, 0, 0);
			}
			Element eDependencies = (Element)XMLUtil.findChildNode(eJob, "dependencies");
			if(eDependencies != null){
				NodeList jobIDList = eDependencies.getElementsByTagName("jobID");
				if(jobIDList != null && jobIDList.getLength() > 0){
					int iJobIDs = jobIDList.getLength();
					jobs.job[i].dependencies = new JobDependencies();
					jobs.job[i].dependencies.jobID = new String[iJobIDs];
					for(int j = 0; j < iJobIDs; j++){
						Element eJobID = (Element)jobIDList.item(j);
						jobs.job[i].dependencies.jobID[j] =  XMLUtil.getElementValue(eJobID);
					}
				}
			}
			Element eRequiredDirectories = (Element)XMLUtil.findChildNode(eJob, "requiredDirectories");			
			if(eRequiredDirectories != null){
				NodeList pathList = eRequiredDirectories.getElementsByTagName("path");
				if(pathList != null && pathList.getLength() > 0){
					int iPaths = pathList.getLength();
					jobs.job[i].requiredDirectories = new DirectoriesAndFiles();
					jobs.job[i].requiredDirectories.path = new String[iPaths];
					for(int j = 0; j < iPaths; j++){
						Element ePath = (Element)pathList.item(j);
						jobs.job[i].requiredDirectories.path[j] =  XMLUtil.getElementValue(ePath);
					}				
				}
			}
			Element eRequiredFiles = (Element)XMLUtil.findChildNode(eJob, "requiredFiles");			
			if(eRequiredFiles != null){
				NodeList pathList = eRequiredFiles.getElementsByTagName("path");
				if(pathList != null && pathList.getLength() > 0){
					int iPaths = pathList.getLength();
					jobs.job[i].requiredFiles = new DirectoriesAndFiles();
					jobs.job[i].requiredFiles.path = new String[iPaths];
					for(int j = 0; j < iPaths; j++){
						Element ePath = (Element)pathList.item(j);
						jobs.job[i].requiredFiles.path[j] =  XMLUtil.getElementValue(ePath);
					}				
				}
			}

		}
		return jobs.job;
	}//getJobStatistics


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
		Element eProcessData = (Element)XMLUtil.findChildNode(m_eRoot, "processData");
		Element eOptimization = (Element)XMLUtil.findChildNode(eProcessData, "optimization");
		if(eOptimization == null) return null;
		NodeList jobList = eOptimization.getElementsByTagName("job");
		if(jobList == null || jobList.getLength() <= 0) return null;
		int iJobs = jobList.getLength();
		OptimizationProcess optimizqationProcess = new OptimizationProcess();
		JobOptimization[] mJobOptimization = new JobOptimization[iJobs]; 
		optimizqationProcess.job = mJobOptimization;
		for(int i = 0; i < iJobs; i++){
			mJobOptimization[i] = new JobOptimization();
			Element eJob = (Element)jobList.item(i);

			Element eStandard = (Element)XMLUtil.findChildNode(eJob, "standard");
			if(eStandard == null){
				mJobOptimization[i].standard = null;
			}
			else{
				NodeList updateList = eStandard.getElementsByTagName("update");
				if(updateList != null && updateList.getLength() > 0){
					mJobOptimization[i].standard = new StandardOptimizationProcessInformation();
					int iUpdate = updateList.getLength();
					mJobOptimization[i].standard.update = new OptimizationUpdate[iUpdate];
					String sValue = "";
					int iValue;
					double dValue;
					for(int j = 0; j < iUpdate; j++){
						mJobOptimization[i].standard.update[j] = new OptimizationUpdate();
						Element eUpdate = (Element)updateList.item(j);
						sValue =  eUpdate.getAttribute("objectiveIdx");
						if(sValue != null && sValue.length() > 0){
							try {
								iValue = Integer.parseInt(sValue);
							} 
							catch (Exception e) {
								iValue = -1;
							}
							if(iValue > 0){
								iValue = 0;
							}
							mJobOptimization[i].standard.update[j].ObjectiveIdx = iValue;
						}
						try {
							sValue =  XMLUtil.getElementValueByName(eUpdate, "updatedObjectiveValue");
							if(sValue != null && sValue.length() > 0){
								if(sValue.equals("INF")) {
									mJobOptimization[i].standard.update[j].updatedObjectiveValue = Double.POSITIVE_INFINITY;
								}
								else if(sValue.equals("-INF")) {
									mJobOptimization[i].standard.update[j].updatedObjectiveValue = Double.NEGATIVE_INFINITY;
								}
								else{
									dValue = Double.parseDouble(sValue);
									mJobOptimization[i].standard.update[j].updatedObjectiveValue = dValue;
								}
							}
						} 
						catch (Exception e) {
							mJobOptimization[i].standard.update[j].updatedObjectiveValue = Double.NaN;
						}

						try {
							sValue =  XMLUtil.getElementValueByName(eUpdate, "updatedObjectiveLowerBound");
							if(sValue != null && sValue.length() > 0){
								if(sValue.equals("INF")) {
									mJobOptimization[i].standard.update[j].updatedObjectiveLowerBound = Double.POSITIVE_INFINITY;
								}
								else if(sValue.equals("-INF")) {
									mJobOptimization[i].standard.update[j].updatedObjectiveLowerBound = Double.NEGATIVE_INFINITY;
								}
								else{
									dValue = Double.parseDouble(sValue);
									mJobOptimization[i].standard.update[j].updatedObjectiveLowerBound = dValue;
								}
							}
						} 
						catch (Exception e) {
							mJobOptimization[i].standard.update[j].updatedObjectiveLowerBound = Double.NaN;
						}

						try {
							sValue =  XMLUtil.getElementValueByName(eUpdate, "updatedObjectiveUpperBound");
							if(sValue != null && sValue.length() > 0){
								if(sValue.equals("INF")) {
									mJobOptimization[i].standard.update[j].updatedObjectiveUpperBound = Double.POSITIVE_INFINITY;
								}
								else if(sValue.equals("-INF")) {
									mJobOptimization[i].standard.update[j].updatedObjectiveUpperBound = Double.NEGATIVE_INFINITY;
								}
								else{
									dValue = Double.parseDouble(sValue);
									mJobOptimization[i].standard.update[j].updatedObjectiveUpperBound = dValue;
								}
							}
						} 
						catch (Exception e) {
							mJobOptimization[i].standard.update[j].updatedObjectiveUpperBound = Double.NaN;
						}

						Element eUpdatedVariableValues = (Element)XMLUtil.findChildNode(eUpdate, "updatedVariableValues");
						if(eUpdatedVariableValues != null){
							NodeList varList = eUpdatedVariableValues.getElementsByTagName("var");
							if(varList != null && varList.getLength() > 0){
								int iVars = varList.getLength();
								mJobOptimization[i].standard.update[j].updatedVariableValues = new UpdatedVariableValues();
								mJobOptimization[i].standard.update[j].updatedVariableValues.var = new double[iVars];
								Element eVar;
								for(int k = 0; k < iVars; k++){
									eVar = (Element)varList.item(k);
									try {
										sValue = XMLUtil.getElementValue(eVar);
										if(sValue.equals("INF")) {
											mJobOptimization[i].standard.update[j].updatedVariableValues.var[k] = Double.POSITIVE_INFINITY;
										}
										else if(sValue.equals("-INF")) {
											mJobOptimization[i].standard.update[j].updatedVariableValues.var[k] = Double.NEGATIVE_INFINITY;
										}
										else{
											mJobOptimization[i].standard.update[j].updatedVariableValues.var[k] = Double.parseDouble(sValue);
										}
									} 
									catch (Exception e) {
										mJobOptimization[i].standard.update[j].updatedVariableValues.var[k] = Double.NaN;	
									}
								}
							}
						}

						Element eUpdatedVariableReducedCosts = (Element)XMLUtil.findChildNode(eUpdate, "updatedVariableReducedCosts");
						if(eUpdatedVariableReducedCosts != null){
							NodeList varList = eUpdatedVariableReducedCosts.getElementsByTagName("var");
							if(varList != null && varList.getLength() > 0){
								int iVars = varList.getLength();
								mJobOptimization[i].standard.update[j].updatedVariableReducedCosts = new UpdatedVariableReducedCosts();
								mJobOptimization[i].standard.update[j].updatedVariableReducedCosts.var = new double[iVars];
								Element eVar;
								for(int k = 0; k < iVars; k++){
									eVar = (Element)varList.item(k);
									try {
										sValue = XMLUtil.getElementValue(eVar);
										if(sValue.equals("INF")) {
											mJobOptimization[i].standard.update[j].updatedVariableReducedCosts.var[k] = Double.POSITIVE_INFINITY;
										}
										else if(sValue.equals("-INF")) {
											mJobOptimization[i].standard.update[j].updatedVariableReducedCosts.var[k] = Double.NEGATIVE_INFINITY;
										}
										else{
											mJobOptimization[i].standard.update[j].updatedVariableReducedCosts.var[k] = Double.parseDouble(sValue);
										}
									} 
									catch (Exception e) {
										mJobOptimization[i].standard.update[j].updatedVariableReducedCosts.var[k] = Double.NaN;	
									}
								}
							}
						}

						Element eUpdatedVariableValuesString = (Element)XMLUtil.findChildNode(eUpdate, "updatedVariableValuesString");
						if(eUpdatedVariableValuesString != null){
							NodeList varList = eUpdatedVariableValuesString.getElementsByTagName("var");
							if(varList != null && varList.getLength() > 0){
								int iVars = varList.getLength();
								mJobOptimization[i].standard.update[j].updatedVariableValuesString = new UpdatedVariableValuesString();
								mJobOptimization[i].standard.update[j].updatedVariableValuesString.var = new String[iVars];
								Element eVar;
								for(int k = 0; k < iVars; k++){
									eVar = (Element)varList.item(k);
									mJobOptimization[i].standard.update[j].updatedVariableValuesString.var[k] = XMLUtil.getElementValue(eVar);
								}
							}
						}

						Element eUpdatedConstraintValues = (Element)XMLUtil.findChildNode(eUpdate, "updatedConstraintValues");
						if(eUpdatedConstraintValues != null){
							NodeList conList = eUpdatedConstraintValues.getElementsByTagName("con");
							if(conList != null && conList.getLength() > 0){
								int iCons = conList.getLength();
								mJobOptimization[i].standard.update[j].updatedConstraintValues = new UpdatedConstraintValues();
								mJobOptimization[i].standard.update[j].updatedConstraintValues.con = new double[iCons];
								Element eCon;
								for(int k = 0; k < iCons; k++){
									eCon = (Element)conList.item(k);
									try {
										sValue = XMLUtil.getElementValue(eCon);
										if(sValue.equals("INF")) {
											mJobOptimization[i].standard.update[j].updatedConstraintValues.con[k] = Double.POSITIVE_INFINITY;
										}
										else if(sValue.equals("-INF")) {
											mJobOptimization[i].standard.update[j].updatedConstraintValues.con[k] = Double.NEGATIVE_INFINITY;
										}
										else{
											mJobOptimization[i].standard.update[j].updatedConstraintValues.con[k] = Double.parseDouble(sValue);
										}
									} 
									catch (Exception e) {
										mJobOptimization[i].standard.update[j].updatedConstraintValues.con[k] = Double.NaN;	
									}
								}
							}
						}

						Element eUpdatedDualValues = (Element)XMLUtil.findChildNode(eUpdate, "updatedDualValues");
						if(eUpdatedDualValues != null){
							NodeList conList = eUpdatedDualValues.getElementsByTagName("con");
							if(conList != null && conList.getLength() > 0){
								int iCons = conList.getLength();
								mJobOptimization[i].standard.update[j].updatedDualValues = new UpdatedDualValues();
								mJobOptimization[i].standard.update[j].updatedDualValues.con = new double[iCons];
								Element eCon;
								for(int k = 0; k < iCons; k++){
									eCon = (Element)conList.item(k);
									try {
										sValue = XMLUtil.getElementValue(eCon);
										if(sValue.equals("INF")) {
											mJobOptimization[i].standard.update[j].updatedDualValues.con[k] = Double.POSITIVE_INFINITY;
										}
										else if(sValue.equals("-INF")) {
											mJobOptimization[i].standard.update[j].updatedDualValues.con[k] = Double.NEGATIVE_INFINITY;
										}
										else{
											mJobOptimization[i].standard.update[j].updatedDualValues.con[k] = Double.parseDouble(sValue);
										}
									} 
									catch (Exception e) {
										mJobOptimization[i].standard.update[j].updatedDualValues.con[k] = Double.NaN;	
									}
								}
							}
						}
					}
				}
			}

			Element eOSrL = (Element)XMLUtil.findChildNode(eJob, "osrl");
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
				catch (Exception e){
					mJobOptimization[i].osrl = null;				
				}
			}
		}
		return optimizqationProcess;
	}//getOptimizationProcess


	/**
	 * Get the hash map of other processes. 
	 * 
	 * @return the hash map of other processes.
	 */
	public HashMap <String, String> getOtherProcesses(){
		if(m_otherProcessHashMap != null) return m_otherProcessHashMap;
		m_otherProcessHashMap = new HashMap <String, String>();
		m_otherProcessDescriptionHashMap = new HashMap <String, String>();

		Element eProcessData = (Element)XMLUtil.findChildNode(m_eRoot, "processData");
		Vector<Element> vOtherElement = XMLUtil.getChildElementsByTagName(eProcessData, "other");
		int iNls = vOtherElement==null?0:vOtherElement.size();
		for(int i = 0; i < iNls; i++){
			Element eOther = (Element)(vOtherElement.elementAt(i));
			NamedNodeMap	attributes =  eOther.getAttributes();
			int n =attributes.getLength();
			String sName = "";
			String sDescription = "";
			String  sValue = XMLUtil.getElementValue(eOther);
			for (int j = 0; j < n; j++){
				Node	attr = attributes.item(j);
				String sAttributeName  = attr.getNodeName();
				String sAttributeValue = attr.getNodeValue();
				if (sAttributeName.equals("name")){
					sName = sAttributeValue;
				}
				else if (sAttributeName.equals("description")){
					sDescription = sAttributeValue;
				}
			}
			m_otherProcessHashMap.put(sName, sValue);
			m_otherProcessDescriptionHashMap.put(sName, sDescription);
		}
		return m_otherProcessHashMap;
	}//getOtherProcesses

	/**
	 * Get the number of other processes.  
	 * 
	 * @return the number of other processes. 
	 */
	public int getOtherProcessNumber(){
		getOtherProcesses();
		return m_otherProcessHashMap.size();
	}//getOtherProcessNumber

	/**
	 * Get the String value from the other process hash map. 
	 * 
	 * @param name holds the name of process to get. 
	 * @return String value from the other process hash map, null if none.
	 */
	public String getOtherProcessValueByName(String name){
		getOtherProcesses();
		if(m_otherProcessHashMap.containsKey(name)){
			return (String)m_otherProcessHashMap.get(name);
		}
		else{ 
			return null;
		}
	}//getOtherProcessValueByName

	/**
	 * Get the String value from the other process hash map. 
	 * 
	 * @param name holds the name of process to get.
	 * @return String value from the other process hash map, null if none.
	 */
	public String getOtherProcessDescriptionByName(String name){
		getOtherProcesses();
		if(m_otherProcessDescriptionHashMap.containsKey(name)){
			return (String)m_otherProcessDescriptionHashMap.get(name);
		}
		else{ 
			return null;
		}
	}//getOtherProcessDescriptionByName


	/**
	 * Get the names of all other processes. 
	 * 
	 * @return the names of all other processes.
	 */
	public String[] getOtherProcessNames(){
		getOtherProcesses();	
		Set nameSet = m_otherProcessHashMap.keySet();
		Object[] moName = nameSet.toArray();
		String[] msName = new String[nameSet.size()];
		for (int i = 0; i < nameSet.size(); i++) {
			msName[i] = (String)moName[i];
		}
		return msName;		
	}//getOtherProcessNames

	/**
	 *  Get the values of all other processes. 
	 * 
	 * @return the values of all other processes. 
	 */
	public String[] getOtherProcessValues(){
		getOtherProcesses();		
		Collection valueCollection = m_otherProcessHashMap.values();
		Object[] moValue = valueCollection.toArray();
		String[] msValue = new String[valueCollection.size()];
		for (int i = 0; i < valueCollection.size(); i++) {
			msValue[i] = moValue[i].toString();
		}
		return msValue;		
	}//getOtherProcessValues


	/**
	 * Get the descriptions of all other processes. 
	 * 
	 * @return the descriptions of all other processes.
	 */
	public String[] getOtherProcessDescriptions(){
		getOtherProcesses();			
		Collection valueCollection = m_otherProcessDescriptionHashMap.values();
		Object[] moValue = valueCollection.toArray();
		String[] msDescription = new String[valueCollection.size()];
		for (int i = 0; i < valueCollection.size(); i++) {
			msDescription[i] = moValue[i].toString();
		}
		return msDescription;		
	}//getOtherProcessDescriptions


	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		OSpLReader osplReader = new OSpLReader(false);
		System.out.println(IOUtil.readStringFromFile(OSParameter.CODE_HOME + "OSRepository/test/ospl/ospl.ospl"));
		System.out.println(osplReader.readFile(OSParameter.CODE_HOME + "OSRepository/test/ospl/ospl.ospl"));
		System.out.println(osplReader.getRequestAction());
		System.out.println(osplReader.getRequestDescription());
		System.out.println(osplReader.getResponseStatus());
		System.out.println(osplReader.getResponseDescription());

		System.out.println(osplReader.getProcessMessage());
		System.out.println(XMLUtil.createXSDateTime(osplReader.getProcessTime()));
		System.out.println(osplReader.getServiceName());
		System.out.println(osplReader.getServiceURI());

		System.out.println(osplReader.getCurrentState());
		System.out.println(osplReader.getAvailableDiskSpace());
		System.out.println(osplReader.getAvailableMemory());
		System.out.println(osplReader.getCurrentJobCount());
		System.out.println(osplReader.getTotalJobsSoFar());
		System.out.println(XMLUtil.createXSDateTime(osplReader.getTimeLastJobEnded()));
		System.out.println(XMLUtil.createXSDateTime(osplReader.getTimeServiceStarted()));
		System.out.println(osplReader.getTimeLastJobTook());
		System.out.println(osplReader.getServiceUtilization());
		ProcessStatistics processStatistics = osplReader.getProcessStatistics();
		System.out.println(processStatistics.currentState);
		System.out.println(processStatistics.availableDiskSpace);
		System.out.println(processStatistics.availableMemory);
		System.out.println(processStatistics.currentJobCount);
		System.out.println(processStatistics.totalJobsSoFar);
		System.out.println(XMLUtil.createXSDateTime(processStatistics.timeLastJobEnded));
		System.out.println(XMLUtil.createXSDateTime(processStatistics.timeServiceStarted));
		System.out.println(processStatistics.timeLastJobTook);
		System.out.println(processStatistics.serviceUtilization);
		Jobs jobs = processStatistics.jobs;
		if(jobs != null){
			JobStatistics[] mJobStatistics = jobs.job;
			int iJobStatistics = mJobStatistics==null?0:mJobStatistics.length; 
			if(iJobStatistics > 0){
				System.out.println(iJobStatistics);
				System.out.println(mJobStatistics[0].jobID);
				System.out.println(mJobStatistics[0].duration);
				if(mJobStatistics[0].dependencies != null)
					System.out.println(mJobStatistics[0].dependencies.jobID[0]);
			}
		}

		OptimizationProcess optimizationProcess = osplReader.getOptimizationProcess();
		int iJobOptimization = (optimizationProcess == null || optimizationProcess.job == null)?0:optimizationProcess.job.length; 
		if(iJobOptimization > 0){
			System.out.println(iJobOptimization);
			System.out.println(optimizationProcess.job[0].jobID);
		}
		System.out.println(osplReader.getOtherProcessNumber());
		String sValue = osplReader.getOtherProcessValueByName("ad");
		if(sValue == null) System.out.println("null");
		else System.out.println(sValue);
		String sDescription = osplReader.getOtherProcessDescriptionByName("a");
		System.out.println(sDescription);
		for(int i=0;i<osplReader.getOtherProcessNumber();i++){
			System.out.println(osplReader.getOtherProcessNames()[i]);
			System.out.println(osplReader.getOtherProcessValues()[i]);
			System.out.println(osplReader.getOtherProcessDescriptions()[i]);
		}


		osplReader.writeToStandardOutput();

	}//main

}//class OSpLReader
