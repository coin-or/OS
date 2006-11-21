/**
 * @(#)OSrLReader 1.0 03/14/2004
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
import org.optimizationservices.oscommon.datastructure.osprocess.JobStatistics;
import org.optimizationservices.oscommon.datastructure.osprocess.Jobs;
import org.optimizationservices.oscommon.datastructure.osprocess.ProcessStatistics;
import org.optimizationservices.oscommon.datastructure.osresult.ConAllowableDecrease;
import org.optimizationservices.oscommon.datastructure.osresult.ConAllowableIncrease;
import org.optimizationservices.oscommon.datastructure.osresult.ConIrreducibleInconsistentSystem;
import org.optimizationservices.oscommon.datastructure.osresult.ConSlack;
import org.optimizationservices.oscommon.datastructure.osresult.ConValue;
import org.optimizationservices.oscommon.datastructure.osresult.ConstraintAllowableDecreases;
import org.optimizationservices.oscommon.datastructure.osresult.ConstraintAllowableIncreases;
import org.optimizationservices.oscommon.datastructure.osresult.ConstraintIrreducibleInconsistentSystem;
import org.optimizationservices.oscommon.datastructure.osresult.ConstraintOVFunctions;
import org.optimizationservices.oscommon.datastructure.osresult.ConstraintSlacks;
import org.optimizationservices.oscommon.datastructure.osresult.ConstraintSolution;
import org.optimizationservices.oscommon.datastructure.osresult.ConstraintValues;
import org.optimizationservices.oscommon.datastructure.osresult.DualVarUnboundedDirection;
import org.optimizationservices.oscommon.datastructure.osresult.DualVarValue;
import org.optimizationservices.oscommon.datastructure.osresult.DualVariableUnboundedDirections;
import org.optimizationservices.oscommon.datastructure.osresult.DualVariableValues;
import org.optimizationservices.oscommon.datastructure.osresult.GeneralStatus;
import org.optimizationservices.oscommon.datastructure.osresult.GeneralSubstatus;
import org.optimizationservices.oscommon.datastructure.osresult.OVFunction;
import org.optimizationservices.oscommon.datastructure.osresult.OVFunctionInterval;
import org.optimizationservices.oscommon.datastructure.osresult.ObjValue;
import org.optimizationservices.oscommon.datastructure.osresult.ObjectiveOVFunctions;
import org.optimizationservices.oscommon.datastructure.osresult.ObjectiveSolution;
import org.optimizationservices.oscommon.datastructure.osresult.ObjectiveValues;
import org.optimizationservices.oscommon.datastructure.osresult.OptimizationResult;
import org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolution;
import org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolutionStatus;
import org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolutionSubstatus;
import org.optimizationservices.oscommon.datastructure.osresult.OtherConResult;
import org.optimizationservices.oscommon.datastructure.osresult.OtherConstraintResult;
import org.optimizationservices.oscommon.datastructure.osresult.OtherObjResult;
import org.optimizationservices.oscommon.datastructure.osresult.OtherObjectiveResult;
import org.optimizationservices.oscommon.datastructure.osresult.OtherOptimizationResult;
import org.optimizationservices.oscommon.datastructure.osresult.OtherVarResult;
import org.optimizationservices.oscommon.datastructure.osresult.OtherVariableResult;
import org.optimizationservices.oscommon.datastructure.osresult.PrimalVarUnboundedDirection;
import org.optimizationservices.oscommon.datastructure.osresult.PrimalVariableUnboundedDirections;
import org.optimizationservices.oscommon.datastructure.osresult.ReducedCosts;
import org.optimizationservices.oscommon.datastructure.osresult.VarAllowableDecrease;
import org.optimizationservices.oscommon.datastructure.osresult.VarAllowableIncrease;
import org.optimizationservices.oscommon.datastructure.osresult.VarIrreducibleInconsistentSystem;
import org.optimizationservices.oscommon.datastructure.osresult.VarReducedCost;
import org.optimizationservices.oscommon.datastructure.osresult.VarSlack;
import org.optimizationservices.oscommon.datastructure.osresult.VarStringValue;
import org.optimizationservices.oscommon.datastructure.osresult.VarValue;
import org.optimizationservices.oscommon.datastructure.osresult.VariableAllowableDecreases;
import org.optimizationservices.oscommon.datastructure.osresult.VariableAllowableIncreases;
import org.optimizationservices.oscommon.datastructure.osresult.VariableIrreducibleInconsistentSystem;
import org.optimizationservices.oscommon.datastructure.osresult.VariableOVFunctions;
import org.optimizationservices.oscommon.datastructure.osresult.VariableSlacks;
import org.optimizationservices.oscommon.datastructure.osresult.VariableSolution;
import org.optimizationservices.oscommon.datastructure.osresult.VariableStringValues;
import org.optimizationservices.oscommon.datastructure.osresult.VariableValues;
import org.optimizationservices.oscommon.localinterface.OSAnalysis;
import org.optimizationservices.oscommon.localinterface.OSResult;
import org.optimizationservices.oscommon.util.IOUtil;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.XMLUtil;
import org.w3c.dom.Element;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

/**
 * The <c>OSrLReader</c> class parses an OSrL instance into a DOM tree and
 * provides a set of "get" methods that can be used to retrieve different 
 * pieces of information of the instance.
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */
public class OSrLReader extends OSgLReader{	
	/**
	 * m_osResult holds the standard OSResult, which is a local interface for 
	 * storing Optimization Services result. 
	 */
	protected OSResult m_osResult = null;
	
	/**
	 * m_iVariableNumber holds the variable number. 
	 */
	private int m_iVariableNumber = -1;
	
	/**
	 * m_iObjectiveNumber holds the objective number. 
	 */
	private int m_iObjectiveNumber = -1;
	
	/**
	 * m_iConstraintNumber holds the constraint number. 
	 */
	private int m_iConstraintNumber = -1;

	/**
	 * m_iSolutionNumber holds the solution number. 
	 */
	private int m_iSolutionNumber = -1;
	
	/**
	 * m_bProcessOptimizationResult holds whether the optimization result has been processed or not. 
	 */
	private boolean m_bProcessOptimizationResult = false;
	
	/**
	 * m_optimizationResult holds the optimization result in the result data. 
	 */
	private OptimizationResult m_optimizationResult = null;
	
	/**
	 * m_otherResultHashMap holds a hash map of other result information.
	 */
	protected HashMap<String, String>	m_otherResultHashMap = null;
	
	/**
	 * m_otherResultDescriptionHashMap holds a hash map of other result descriptions.
	 */
	protected HashMap<String, String>	m_otherResultDescriptionHashMap = null;

	/**
	 * constructor.
	 * 
	 * @param validate holds whether the reader	should be validating against the schema	or not.
	 */
	public OSrLReader(boolean validate){
		m_bXsdValidate = validate;
	}//constructor
	
	/**
	 * Default	constructor. 
	 *
	 */
	public OSrLReader(){
	}//constructor
	
	/**
	 * get the standard OSResult, a local interface for 
	 * storing Optimization Services result.
	 * 
	 * @return the OSResult. 
	 * @throws Exception if there are errors getting the OSResult. 
	 */
   	public OSResult getOSResult() throws Exception{
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
   		
   	/**
	 * Get the general status.
	 * 
	 * @return the general status. 
	 */
	public GeneralStatus getGeneralStatus(){
		Element eResultHeader = (Element)XMLUtil.findChildNode(m_eRoot, "resultHeader");
		Element eGeneralStatus = (Element)XMLUtil.findChildNode(eResultHeader, "generalStatus");
		if(eGeneralStatus == null) return null;
		GeneralStatus status = new GeneralStatus();
		String sStatusType = eGeneralStatus.getAttribute("type");
		String sStatusDescription = eGeneralStatus.getAttribute("description");
		status.type = sStatusType;
		status.description = sStatusDescription;
		NodeList nodeList = eGeneralStatus.getElementsByTagName("substatus");
		int iChildren = nodeList.getLength();
		if(iChildren <= 0) return status;
		status.substatus = new GeneralSubstatus[iChildren];
		for(int i = 0; i < iChildren; i++){
			status.substatus[i] = new GeneralSubstatus();
			Element eSubstatus = (Element)(nodeList.item(i));
			NamedNodeMap attributes =  eSubstatus.getAttributes();
			int n =attributes.getLength();
			String sSubstatusName = "";
			String sSubstatusDescription = "";
			String sSubstatusValue = XMLUtil.getElementValue(eSubstatus);
			status.substatus[i].value = sSubstatusValue;
			for (int j = 0; j < n; j++) {
				Node attr = attributes.item(j);
				String sLocalName = attr.getNodeName();
				String sValue = attr.getNodeValue();
				if (sLocalName.equals("name")){
					sSubstatusName = sValue;
					status.substatus[i].name = sSubstatusName;
				}
				else if (sLocalName.equals("description")){
					sSubstatusDescription = sValue;
					status.substatus[i].description = sSubstatusDescription;
				}
			}
		}
		return status;
	}//getGeneralStatus
	
   	/**
	 * Get the general status type, which can be: 
	 * success, error, warning. 
	 * 
	 * @return the general status type, null if none. 
	 */
	public String getGeneralStatusType(){
		Element eResultHeader = (Element)XMLUtil.findChildNode(m_eRoot, "resultHeader");
		Element eGeneralStatus = (Element)XMLUtil.findChildNode(eResultHeader, "generalStatus");
		if(eGeneralStatus == null) return null;
		String sStatusType = eGeneralStatus.getAttribute("type");
		return sStatusType;
	}//getGeneralStatusType

   	/**
	 * Get the general status description. 
	 * 
	 * @return the general status description, null or empty string if none. 
	 */
	public String getGeneralStatusDescription(){
		Element eResultHeader = (Element)XMLUtil.findChildNode(m_eRoot, "resultHeader");
		Element eGeneralStatus = (Element)XMLUtil.findChildNode(eResultHeader, "generalStatus");
		if(eGeneralStatus == null) return null;
		String sStatusDescription = eGeneralStatus.getAttribute("description");
		return sStatusDescription;
	}//getGeneralStatusDescription

  	/**
	 * Get service uri.
	 * 
	 * @return the service uri. 
	 */
	public String getServiceURI(){
		Element eResultHeader = (Element)XMLUtil.findChildNode(m_eRoot, "resultHeader");
		String sServiceURI = XMLUtil.getElementValueByName(eResultHeader, "serviceURI");
		if(sServiceURI == null) sServiceURI = "";
		return sServiceURI;	
	}//getServiceURI
	
   	/**
	 * Get service name.
	 * 
	 * @return the service name. 
	 */
	public String getServiceName(){
		Element eResultHeader = (Element)XMLUtil.findChildNode(m_eRoot, "resultHeader");
		String sServiceName = XMLUtil.getElementValueByName(eResultHeader, "serviceName");
		if(sServiceName == null) sServiceName = "";
		return sServiceName;
	}//getServiceName
	
  	/**
	 * Get instance name.
	 * 
	 * @return the instance name. 
	 */
	public String getInstanceName(){
		Element eResultHeader = (Element)XMLUtil.findChildNode(m_eRoot, "resultHeader");
		String sInstanceName = XMLUtil.getElementValueByName(eResultHeader, "instanceName");
		if(sInstanceName == null) sInstanceName = "";
		return sInstanceName;
	}//getInstanceName
	
  	/**
	 * Get the job id.
	 * 
	 * @return the job id. 
	 */
	public String getJobID(){
		Element eResultHeader = (Element)XMLUtil.findChildNode(m_eRoot, "resultHeader");
		String sJobID = XMLUtil.getElementValueByName(eResultHeader, "jobID");
		if(sJobID == null) sJobID = "";
		return sJobID;	
	}//getJobID
	
 	/**
	 * Get time of the result.
	 * 
	 * @return the time of the result.
	 */
	public GregorianCalendar getResultTime(){
		Element eResultHeader = (Element)XMLUtil.findChildNode(m_eRoot, "resultHeader");
		String sTime = XMLUtil.getElementValueByName(eResultHeader, "time");
		if(sTime == null) return null;
		GregorianCalendar time = XMLUtil.createNativeDateTime(sTime);
		return time;
	}//getResultTime
	
   	/**
	 * Get the general message. 
	 * 
	 * @return the general message. 
	 */
	public String getGeneralMessage(){
		Element eResultHeader = (Element)XMLUtil.findChildNode(m_eRoot, "resultHeader");
		String sMessage = XMLUtil.getElementValueByName(eResultHeader, "message");
		if(sMessage == null) sMessage = "";
		return sMessage;	
	}//getGeneralMessage
	
	/**
	 * Get the process statistics. 
	 * 
	 * @return the process statistics. 
	 */
	public ProcessStatistics getProcessStatistics(){
		Element eResultData = (Element)XMLUtil.findChildNode(m_eRoot, "resultData");
		Element eStatistics = (Element)XMLUtil.findChildNode(eResultData, "statistics");
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
			if(eDependencies == null) continue;
			NodeList jobIDList = eDependencies.getElementsByTagName("jobID");
			if(jobIDList == null || jobIDList.getLength() <= 0) continue;
			int iJobIDs = jobIDList.getLength();
			processStatistics.jobs.job[i].dependencies = new JobDependencies();
			processStatistics.jobs.job[i].dependencies.jobID = new String[iJobIDs];
			for(int j = 0; j < iJobIDs; j++){
				Element eJobID = (Element)jobIDList.item(j);
				processStatistics.jobs.job[i].dependencies.jobID[j] =  XMLUtil.getElementValue(eJobID);
			}
		}
		return processStatistics;
	}//getProcessStatistics
	
	/**
	 * Get the statistics of all the jobs. 
	 * 
	 * @return the statistics of all the jobs, which is an array of jobStatistics with 
	 * each member corresponding to one job; null if none. 
	 */
	public JobStatistics[] getJobStatistics(){
		Element eResultData = (Element)XMLUtil.findChildNode(m_eRoot, "resultData");
		Element eStatistics = (Element)XMLUtil.findChildNode(eResultData, "statistics");
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
			if(eDependencies == null) continue;
			NodeList jobIDList = eDependencies.getElementsByTagName("jobID");
			if(jobIDList == null || jobIDList.getLength() <= 0) continue;
			int iJobIDs = jobIDList.getLength();
			jobs.job[i].dependencies = new JobDependencies();
			jobs.job[i].dependencies.jobID = new String[iJobIDs];
			for(int j = 0; j < iJobIDs; j++){
				Element eJobID = (Element)jobIDList.item(j);
				jobs.job[i].dependencies.jobID[j] =  XMLUtil.getElementValue(eJobID);
			}
		}
		return jobs.job;
	}//getJobStatistics
   	
	/**
	 * Get the current state, , which can be:
	 * "busy", "busyButAccepting", "idle", "idleButNotAccepting" and "noResponse".
	 * 
	 * @return the current status, "noResponse" if none.
	 */
	public String getCurrentState(){
		Element eResultData = (Element)XMLUtil.findChildNode(m_eRoot, "resultData");
		Element eStatistics = (Element)XMLUtil.findChildNode(eResultData, "statistics");
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
		Element eResultData = (Element)XMLUtil.findChildNode(m_eRoot, "resultData");
		Element eStatistics = (Element)XMLUtil.findChildNode(eResultData, "statistics");
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
		Element eResultData = (Element)XMLUtil.findChildNode(m_eRoot, "resultData");
		Element eStatistics = (Element)XMLUtil.findChildNode(eResultData, "statistics");
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
		Element eResultData = (Element)XMLUtil.findChildNode(m_eRoot, "resultData");
		Element eStatistics = (Element)XMLUtil.findChildNode(eResultData, "statistics");
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
		Element eResultData = (Element)XMLUtil.findChildNode(m_eRoot, "resultData");
		Element eStatistics = (Element)XMLUtil.findChildNode(eResultData, "statistics");
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
		Element eResultData = (Element)XMLUtil.findChildNode(m_eRoot, "resultData");
		Element eStatistics = (Element)XMLUtil.findChildNode(eResultData, "statistics");
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
		Element eResultData = (Element)XMLUtil.findChildNode(m_eRoot, "resultData");
		Element eStatistics = (Element)XMLUtil.findChildNode(eResultData, "statistics");
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
		Element eResultData = (Element)XMLUtil.findChildNode(m_eRoot, "resultData");
		Element eStatistics = (Element)XMLUtil.findChildNode(eResultData, "statistics");
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
		Element eResultData = (Element)XMLUtil.findChildNode(m_eRoot, "resultData");
		Element eStatistics = (Element)XMLUtil.findChildNode(eResultData, "statistics");
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
	 * Get the hash map of other result information. 
	 * 
	 * @return the hash map of other result information.
	 */
	public HashMap<String, String> getOtherResults(){
		if(m_otherResultHashMap != null) return m_otherResultHashMap;
		m_otherResultHashMap = new HashMap<String, String>();
		m_otherResultDescriptionHashMap = new HashMap<String, String>();
		
		Element eResultData = (Element)XMLUtil.findChildNode(m_eRoot, "resultData");
		Vector<Element> vElements	= XMLUtil.getChildElementsByTagName(eResultData, "other"); 
		int iNls	= vElements==null?0:vElements.size();
		for(int i = 0; i < iNls; i++){
			Element eOtherResult = (Element)(vElements.elementAt(i));
			NamedNodeMap	attributes =  eOtherResult.getAttributes();
			int n =attributes.getLength();
			String sName = "";
			String sDescription = "";
			String sValue = XMLUtil.getElementValue(eOtherResult);
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
			m_otherResultHashMap.put(sName, sValue);
			m_otherResultDescriptionHashMap.put(sName, sDescription);
		}
		return m_otherResultHashMap;
	}//getOtherResults
	
	
	/**
	 * Get the number of other result information.  
	 * @return the number of other result information. 
	 */
	public int getOtherResultNumber(){
		getOtherResults();
		return m_otherResultHashMap.size();
	}//getOtherResultNumber
	
	/**
	 * Get the String value from the other info hash map. 
	 * 
	 * @param name holds the name of the other info to get. 
	 * @return String value from the other info hash map, null if none.
	 */
	public String getOtherResultValueByName(String name){
		getOtherResults();
		if(m_otherResultHashMap.containsKey(name)){
			return (String)m_otherResultHashMap.get(name);
		}
		else{ 
			return null;
		}
	}//getOtherResultValueByName
	
	/**
	 * Get the String value from the other info hash map. 
	 * 
	 * @param name holds the name of the other info to get. 
	 * @return String value from the other info hash map, null if none. 
	 */
	public String getOtherResultDescriptionByName(String name){
		getOtherResults();
		if(m_otherResultDescriptionHashMap.containsKey(name)){
			return (String)m_otherResultDescriptionHashMap.get(name);
		}
		else{ 
			return null;
		}
	}//getOtherResultDescriptionByName
	
	/**
	 * Get the names of all other result information. 
	 * 
	 * @return the names of all other result information. 
	 */
	public String[] getOtherResultNames(){
		getOtherResults();	
		Set nameSet = m_otherResultHashMap.keySet();
		Object[] moName = nameSet.toArray();
		String[] msName = new String[nameSet.size()];
		for (int i = 0; i < nameSet.size(); i++) {
			msName[i] = (String)moName[i];
		}
		return msName;	
	}//getOtherResultNames
	
	/**
	 * Get the values of all other result information. 
	 * @return the values of all other result information.
	 */
	public String[] getOtherResultValues(){
		getOtherResults();		
		Collection valueCollection = m_otherResultHashMap.values();
		Object[] moValue = valueCollection.toArray();
		String[] msValue = new String[valueCollection.size()];
		for (int i = 0; i < valueCollection.size(); i++) {
			msValue[i] = moValue[i].toString();
		}
		return msValue;		
	}//getOtherResultValues
	
	/**
	 * Get the descriptions of all other result information. 
	 * 
	 * @return the descriptions of all other result information.
	 */
	public String[] getOtherResultDescriptions(){
		getOtherResults();			
		Collection valueCollection = m_otherResultDescriptionHashMap.values();
		Object[] moValue = valueCollection.toArray();
		String[] msDescription = new String[valueCollection.size()];
		for (int i = 0; i < valueCollection.size(); i++) {
			msDescription[i] = moValue[i].toString();
		}
		return msDescription;		
	}//getOtherResultDescriptions
	
	/**
	 * Get variable number. 
	 * 
	 * @return variable number, -1 if no information. 
	 */
	public int getVariableNumber(){
		if(m_iVariableNumber == -1){
			Element eResultData = (Element)XMLUtil.findChildNode(m_eRoot, "resultData");
			Element eOptimization = (Element)XMLUtil.findChildNode(eResultData, "optimization");
			if(eOptimization == null) return -1;
			String sNumber =  eOptimization.getAttribute("numberOfVariables");
			m_iVariableNumber = Integer.parseInt(sNumber);
		}
		return m_iVariableNumber;
	}//getVariableNumber

	/**
	 * Get objective number. 
	 * 
	 * @return objective number, -1 if no information. 
	 */
	public int getObjectiveNumber(){
		if(m_iObjectiveNumber == -1){
			Element eResultData = (Element)XMLUtil.findChildNode(m_eRoot, "resultData");
			Element eOptimization = (Element)XMLUtil.findChildNode(eResultData, "optimization");
			if(eOptimization == null) return -1;
			String sNumber =  eOptimization.getAttribute("numberOfObjectives");
			m_iObjectiveNumber = Integer.parseInt(sNumber);
		}
		return m_iObjectiveNumber;
	}//getObjectiveNumber
	
	/**
	 * Get constraint number. 
	 * 
	 * @return constraint number, -1 if no information. 
	 */
	public int getConstraintNumber(){
		if(m_iConstraintNumber == -1){
			Element eResultData = (Element)XMLUtil.findChildNode(m_eRoot, "resultData");
			Element eOptimization = (Element)XMLUtil.findChildNode(eResultData, "optimization");
			if(eOptimization == null) return -1;
			String sNumber =  eOptimization.getAttribute("numberOfConstraints");
			m_iConstraintNumber = Integer.parseInt(sNumber);
		}
		return m_iConstraintNumber;
	}//getConstraintNumber

	/**
	 * get the number of solutions. 
	 * 
	 * @return the number of solutions, 0 if none.  
	 */
	public int getSolutionNumber(){
		if(m_iSolutionNumber == -1){
			Element eResultData = (Element)XMLUtil.findChildNode(m_eRoot, "resultData");
			Element eOptimization = (Element)XMLUtil.findChildNode(eResultData, "optimization");
			if(eOptimization == null) return -1;
			String sNumber =  eOptimization.getAttribute("numberOfSolutions");
			m_iSolutionNumber = Integer.parseInt(sNumber);
		}
		return m_iSolutionNumber;
	}//getSolutionNumber
	
	/**
	 * process the optimization result
	 * 
	 * @return whether the optimization result is process successfully or not.
	 */
	private boolean processOptimizationResult(){
		if(m_bProcessOptimizationResult){
			return true;
		}
		Element eResultData = (Element)XMLUtil.findChildNode(m_eRoot, "resultData");
		Element eOptimization = (Element)XMLUtil.findChildNode(eResultData, "optimization");
		if(eOptimization == null){
			m_bProcessOptimizationResult = true;
			return true;
		}
		m_optimizationResult = new OptimizationResult();

		String sVariableNumber =  eOptimization.getAttribute("numberOfVariables");
		m_iVariableNumber = Integer.parseInt(sVariableNumber);
		m_optimizationResult.numberOfSolutions = m_iVariableNumber;

		String sObjectiveNumber =  eOptimization.getAttribute("numberOfObjectives");
		m_iObjectiveNumber = Integer.parseInt(sObjectiveNumber);
		m_optimizationResult.numberOfObjectives = m_iObjectiveNumber;
		
		String sConstraintNumber =  eOptimization.getAttribute("numberOfConstraints");
		m_iConstraintNumber = Integer.parseInt(sConstraintNumber);
		m_optimizationResult.numberOfConstraints = m_iConstraintNumber;

		String sSolutionNumber =  eOptimization.getAttribute("numberOfSolutions");
		m_iSolutionNumber = Integer.parseInt(sSolutionNumber);
		m_optimizationResult.numberOfSolutions = m_iSolutionNumber;
				
		Vector<Element> vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
		if(vSolutions != null || vSolutions.size() > 0){
			int iSolutions = vSolutions.size();
			m_optimizationResult.solution = new OptimizationSolution[iSolutions];
			for(int i = 0; i < iSolutions; i++){
				Element eSolution = (Element)vSolutions.elementAt(i);
				if(eSolution == null){
					continue;
				}
				m_optimizationResult.solution[i] = new OptimizationSolution();
				OptimizationSolution solution = m_optimizationResult.solution[i];
				String sObjectiveIdx = eSolution.getAttribute("objectiveIdx");
				if(sObjectiveIdx != null && sObjectiveIdx.length() > 0){
					solution.objectiveIdx = Integer.parseInt(sObjectiveIdx);
				}//solution objectiveIdx
				
				Element eStatus = (Element)XMLUtil.findChildNode(eSolution, "status");
				if(eStatus != null){
					solution.status = new OptimizationSolutionStatus();
					String sStatusType = eStatus.getAttribute("type");
					String sStatusDescription = eStatus.getAttribute("description");
					solution.status.type = sStatusType;
					solution.status.description = sStatusDescription;
					NodeList nodeList = eStatus.getElementsByTagName("substatus");
					int iChildren = nodeList.getLength();
					if(iChildren > 0){
						solution.status.substatus = new OptimizationSolutionSubstatus[iChildren];
						for(int j = 0; j < iChildren; j++){
							solution.status.substatus[j] = new OptimizationSolutionSubstatus();
							Element eSubstatus = (Element)(nodeList.item(j));
							NamedNodeMap attributes =  eSubstatus.getAttributes();
							int n =attributes.getLength();
							String sSubstatusName = "";
							String sSubstatusDescription = "";
							String sSubstatusValue = XMLUtil.getElementValue(eSubstatus);
							solution.status.substatus[j].value = sSubstatusValue;
							for (int k = 0; k < n; k++) {
								Node attr = attributes.item(k);
								String sLocalName = attr.getNodeName();
								String sValue = attr.getNodeValue();
								if (sLocalName.equals("name")){
									sSubstatusName = sValue;
									solution.status.substatus[j].name = sSubstatusName;
								}
								else if (sLocalName.equals("description")){
									sSubstatusDescription = sValue;
									solution.status.substatus[j].description = sSubstatusDescription;
								}
							}
						}
					}					
				}//solution status 
				
				Element eMessage = (Element)XMLUtil.findChildNode(eSolution, "message");
				if(eMessage != null){
					solution.message = XMLUtil.getElementValue(eMessage);					
				}//solution message
				
				Element eVariables = (Element)XMLUtil.findChildNode(eSolution, "variables");
				if(eVariables != null){
					solution.variables = new VariableSolution();			
					//variable values
					Element eValues = (Element)XMLUtil.findChildNode(eVariables, "values");
					if(eValues != null){
						solution.variables.values = new VariableValues(); 
						NodeList vars = eValues.getElementsByTagName("var");
						if(vars != null && vars.getLength() > 0){
							int iVars = vars.getLength();
							solution.variables.values.var = new VarValue[iVars];
							for(int j = 0; j < iVars; j++){
								solution.variables.values.var[j] = new VarValue();
								try{
									int iIndex = Integer.parseInt(((Element)vars.item(j)).getAttribute("idx"));
									solution.variables.values.var[j].idx = iIndex;
									String sValue = ((Element)vars.item(j)).getAttribute("value");
									double dValue = 0;
									if(sValue == null || sValue.length() == 0){
										dValue = 0;
									}
									else if(sValue.equals("INF")){
										dValue = Double.POSITIVE_INFINITY;
									}
									else if(sValue.equals("-INF")){
										dValue = Double.NEGATIVE_INFINITY;
									}
									else{
										dValue = Double.parseDouble(sValue);
									}
									solution.variables.values.var[j].value = dValue;
								}
								catch(Exception e){									
								}
							}
						}
					}
					//variable valuesString
					Element eValuesString = (Element)XMLUtil.findChildNode(eVariables, "valuesString");
					if(eValuesString != null){
						solution.variables.valuesString = new VariableStringValues(); 
						NodeList vars = eValuesString.getElementsByTagName("var");
						if(vars != null && vars.getLength() > 0){
							int iVars = vars.getLength();
							solution.variables.valuesString.var = new VarStringValue[iVars];
							for(int j = 0; j < iVars; j++){
								solution.variables.valuesString.var[j] = new VarStringValue();
								int iIndex = Integer.parseInt(((Element)vars.item(j)).getAttribute("idx"));
								solution.variables.valuesString.var[j].idx = iIndex;
								String sValue = ((Element)vars.item(j)).getAttribute("value");
								solution.variables.valuesString.var[j].value = sValue;
							}
						}
					}	
					//variable primalUnboundedDirections
					Element ePrimalUnboundedDirections = (Element)XMLUtil.findChildNode(eVariables, "primalUnboundedDirections");
					if(ePrimalUnboundedDirections != null){
						solution.variables.primalUnboundedDirections = new PrimalVariableUnboundedDirections(); 
						NodeList vars = ePrimalUnboundedDirections.getElementsByTagName("var");
						if(vars != null && vars.getLength() > 0){
							int iVars = vars.getLength();
							solution.variables.primalUnboundedDirections.var = new PrimalVarUnboundedDirection[iVars];
							for(int j = 0; j < iVars; j++){
								solution.variables.primalUnboundedDirections.var[j] = new PrimalVarUnboundedDirection();
								try{
									int iIndex = Integer.parseInt(((Element)vars.item(j)).getAttribute("idx"));
									solution.variables.primalUnboundedDirections.var[j].idx = iIndex;
									String sValue = ((Element)vars.item(j)).getAttribute("value");
									double dValue = Double.NaN;
									if(sValue == null || sValue.length() == 0){
										dValue = 0;
									}
									else if(sValue.equals("INF")){
										dValue = Double.POSITIVE_INFINITY;
									}
									else if(sValue.equals("-INF")){
										dValue = Double.NEGATIVE_INFINITY;
									}
									else{
										dValue = Double.parseDouble(sValue);
									}
									solution.variables.primalUnboundedDirections.var[j].value = dValue;
								}
								catch(Exception e){									
								}
							}
						}
					}
					//variable irreducibleInconsistentSystem
					Element eIrreducibleInconsistentSystem = (Element)XMLUtil.findChildNode(eVariables, "irreducibleInconsistentSystem");
					if(eIrreducibleInconsistentSystem != null){
						solution.variables.irreducibleInconsistentSystem = new VariableIrreducibleInconsistentSystem(); 
						NodeList vars = eIrreducibleInconsistentSystem.getElementsByTagName("var");
						if(vars != null && vars.getLength() > 0){
							int iVars = vars.getLength();
							solution.variables.irreducibleInconsistentSystem.var = new VarIrreducibleInconsistentSystem[iVars];
							for(int j = 0; j < iVars; j++){
								solution.variables.irreducibleInconsistentSystem.var[j] = new VarIrreducibleInconsistentSystem();
								int iIndex = Integer.parseInt(((Element)vars.item(j)).getAttribute("idx"));
								solution.variables.irreducibleInconsistentSystem.var[j].idx = iIndex;
								String sType = ((Element)vars.item(j)).getAttribute("type");
								solution.variables.irreducibleInconsistentSystem.var[j].type = sType;
							}
						}
					}
					//variable reducedCosts
					Element eReducedCosts = (Element)XMLUtil.findChildNode(eVariables, "reducedCosts");
					if(eReducedCosts != null){
						solution.variables.reducedCosts = new ReducedCosts(); 
						NodeList vars = eReducedCosts.getElementsByTagName("var");
						if(vars != null && vars.getLength() > 0){
							int iVars = vars.getLength();
							solution.variables.reducedCosts.var = new VarReducedCost[iVars];
							for(int j = 0; j < iVars; j++){
								solution.variables.reducedCosts.var[j] = new VarReducedCost();
								try{
									int iIndex = Integer.parseInt(((Element)vars.item(j)).getAttribute("idx"));
									solution.variables.reducedCosts.var[j].idx = iIndex;
									String sLbValue = ((Element)vars.item(j)).getAttribute("lbValue");
									double dLbValue = 0;
									if(sLbValue == null || sLbValue.length() == 0){
										dLbValue = 0;
									}
									else if(sLbValue.equals("INF")){
										dLbValue = Double.POSITIVE_INFINITY;
									}
									else if(sLbValue.equals("-INF")){
										dLbValue = Double.NEGATIVE_INFINITY;
									}
									else{
										dLbValue = Double.parseDouble(sLbValue);
									}
									solution.variables.reducedCosts.var[j].lbValue = dLbValue;
									String sUbValue = ((Element)vars.item(j)).getAttribute("ubValue");
									double dUbValue = 0;
									if(sUbValue == null || sUbValue.length() == 0){
										dUbValue = 0;
									}
									if(sUbValue.equals("INF")){
										dUbValue = Double.POSITIVE_INFINITY;
									}
									else if(sUbValue.equals("-INF")){
										dUbValue = Double.NEGATIVE_INFINITY;
									}
									else{
										dUbValue = Double.parseDouble(sUbValue);
									}
									solution.variables.reducedCosts.var[j].ubValue = dUbValue;
								}
								catch(Exception e){									
								}
							}
						}
					}
					//variable slacks
					Element eSlacks = (Element)XMLUtil.findChildNode(eVariables, "slacks");
					if(eSlacks != null){
						solution.variables.slacks = new VariableSlacks(); 
						NodeList vars = eSlacks.getElementsByTagName("var");
						if(vars != null && vars.getLength() > 0){
							int iVars = vars.getLength();
							solution.variables.slacks.var = new VarSlack[iVars];
							for(int j = 0; j < iVars; j++){
								solution.variables.slacks.var[j] = new VarSlack();
								try{
									int iIndex = Integer.parseInt(((Element)vars.item(j)).getAttribute("idx"));
									solution.variables.slacks.var[j].idx = iIndex;
									String sLbValue = ((Element)vars.item(j)).getAttribute("lbValue");
									double dLbValue = Double.NaN;
									if(sLbValue == null || sLbValue.length() == 0){
										dLbValue = 0;
									}
									else if(sLbValue.equals("INF")){
										dLbValue = Double.POSITIVE_INFINITY;
									}
									else if(sLbValue.equals("-INF")){
										dLbValue = Double.NEGATIVE_INFINITY;
									}
									else{
										dLbValue = Double.parseDouble(sLbValue);
									}
									solution.variables.slacks.var[j].lbValue = dLbValue;
									String sUbValue = ((Element)vars.item(j)).getAttribute("ubValue");
									double dUbValue = Double.NaN;
									if(sUbValue == null || sUbValue.length() == 0){
										dUbValue = 0;
									}
									else if(sUbValue.equals("INF")){
										dUbValue = Double.POSITIVE_INFINITY;
									}
									else if(sUbValue.equals("-INF")){
										dUbValue = Double.NEGATIVE_INFINITY;
									}
									else{
										dUbValue = Double.parseDouble(sUbValue);
									}
									solution.variables.slacks.var[j].ubValue = dUbValue;
								}
								catch(Exception e){									
								}
							}
						}
					}
					//variable allowableIncreases
					Element eAllowableIncreases = (Element)XMLUtil.findChildNode(eVariables, "allowableIncreases");
					if(eAllowableIncreases != null){
						solution.variables.allowableIncreases = new VariableAllowableIncreases(); 
						NodeList vars = eAllowableIncreases.getElementsByTagName("var");
						if(vars != null && vars.getLength() > 0){
							int iVars = vars.getLength();
							solution.variables.allowableIncreases.var = new VarAllowableIncrease[iVars];
							for(int j = 0; j < iVars; j++){
								solution.variables.allowableIncreases.var[j] = new VarAllowableIncrease();
								try{
									int iIndex = Integer.parseInt(((Element)vars.item(j)).getAttribute("idx"));
									solution.variables.allowableIncreases.var[j].idx = iIndex;
									String sLbValue = ((Element)vars.item(j)).getAttribute("lbValue");
									double dLbValue = Double.NaN;
									if(sLbValue == null || sLbValue.length() == 0){
										dLbValue = 0;
									}
									else if(sLbValue.equals("INF")){
										dLbValue = Double.POSITIVE_INFINITY;
									}
									else if(sLbValue.equals("-INF")){
										dLbValue = Double.NEGATIVE_INFINITY;
									}
									else{
										dLbValue = Double.parseDouble(sLbValue);
									}
									solution.variables.allowableIncreases.var[j].lbValue = dLbValue;
									String sUbValue = ((Element)vars.item(j)).getAttribute("ubValue");
									double dUbValue = Double.NaN;
									if(sUbValue == null || sUbValue.length() == 0){
										dUbValue = 0;
									}
									else if(sUbValue.equals("INF")){
										dUbValue = Double.POSITIVE_INFINITY;
									}
									else if(sUbValue.equals("-INF")){
										dUbValue = Double.NEGATIVE_INFINITY;
									}
									else{
										dUbValue = Double.parseDouble(sUbValue);
									}
									solution.variables.allowableIncreases.var[j].ubValue = dUbValue;
								}
								catch(Exception e){									
								}
							}
						}
					}
					//variable allowableDecreases
					Element eAllowableDecreases = (Element)XMLUtil.findChildNode(eVariables, "allowableDecreases");
					if(eAllowableDecreases != null){
						solution.variables.allowableDecreases = new VariableAllowableDecreases(); 
						NodeList vars = eAllowableDecreases.getElementsByTagName("var");
						if(vars != null && vars.getLength() > 0){
							int iVars = vars.getLength();
							solution.variables.allowableDecreases.var = new VarAllowableDecrease[iVars];
							for(int j = 0; j < iVars; j++){
								solution.variables.allowableDecreases.var[j] = new VarAllowableDecrease();
								try{
									int iIndex = Integer.parseInt(((Element)vars.item(j)).getAttribute("idx"));
									solution.variables.allowableDecreases.var[j].idx = iIndex;
									String sLbValue = ((Element)vars.item(j)).getAttribute("lbValue");
									double dLbValue = Double.NaN;
									if(sLbValue == null || sLbValue.length() == 0){
										dLbValue = 0;
									}
									else if(sLbValue.equals("INF")){
										dLbValue = Double.POSITIVE_INFINITY;
									}
									else if(sLbValue.equals("-INF")){
										dLbValue = Double.NEGATIVE_INFINITY;
									}
									else{
										dLbValue = Double.parseDouble(sLbValue);
									}
									solution.variables.allowableDecreases.var[j].lbValue = dLbValue;
									String sUbValue = ((Element)vars.item(j)).getAttribute("ubValue");
									double dUbValue = Double.NaN;
									if(sUbValue == null || sUbValue.length() == 0){
										dUbValue = 0;
									}
									else if(sUbValue.equals("INF")){
										dUbValue = Double.POSITIVE_INFINITY;
									}
									else if(sUbValue.equals("-INF")){
										dUbValue = Double.NEGATIVE_INFINITY;
									}
									else{
										dUbValue = Double.parseDouble(sUbValue);
									}
									solution.variables.allowableDecreases.var[j].ubValue = dUbValue;
								}
								catch(Exception e){									
								}
							}
						}
					}
					//variable ovFunctions
					Element eOVFunctions = (Element)XMLUtil.findChildNode(eVariables, "ovFunctions");
					if(eOVFunctions != null){
						solution.variables.ovFunctions = new VariableOVFunctions(); 
						Vector<Element> vVarBounds = XMLUtil.getChildElementsByTagName(eOVFunctions, "varBound");
						if(vVarBounds != null && vVarBounds.size() > 0){
							int iVarBounds = vVarBounds.size();
							solution.variables.ovFunctions.varBound = new OVFunction[iVarBounds];
							for(int j = 0; j < iVarBounds; j++){
								solution.variables.ovFunctions.varBound[j] = new OVFunction();
								Element eVarBound = (Element)vVarBounds.elementAt(j);
								try{
									int iIndex = Integer.parseInt(eVarBound.getAttribute("idx"));
									solution.variables.ovFunctions.varBound[j].idx = iIndex;
									solution.variables.ovFunctions.varBound[j].type = eVarBound.getAttribute("type");
								}
								catch(Exception e){
								}
								NodeList intervals = eVarBound.getElementsByTagName("interval");
								if(intervals != null && intervals.getLength() > 0){
									int iIntervals = intervals.getLength();
									solution.variables.ovFunctions.varBound[j].interval = new OVFunctionInterval[iIntervals];
									for(int k = 0; k < iIntervals; k++){
										double dLastStart = Double.NEGATIVE_INFINITY;
										solution.variables.ovFunctions.varBound[j].interval[k] = new OVFunctionInterval();
										Element eInterval = (Element)intervals.item(k);
										try{
											String sStart = eInterval.getAttribute("start");
											double dStart = Double.NaN;
											if(sStart == null || sStart.length() == 0){
												dStart = dLastStart;
											}
											if(sStart.equals("INF")){
												dStart = Double.POSITIVE_INFINITY;
											}
											else if(sStart.equals("-INF")){
												dStart = Double.NEGATIVE_INFINITY;
											}
											else{
												dStart = Double.parseDouble(sStart);
											}
											solution.variables.ovFunctions.varBound[j].interval[k].start = dStart;
											String sEnd = eInterval.getAttribute("end");
											double dEnd = Double.NaN;
											if(sEnd == null || sEnd.length() == 0){
												dEnd = Double.POSITIVE_INFINITY;
											}
											if(sEnd.equals("INF")){
												dEnd = Double.POSITIVE_INFINITY;
											}
											else if(sEnd.equals("-INF")){
												dEnd = Double.NEGATIVE_INFINITY;
											}
											else{
												dEnd = Double.parseDouble(sEnd);
											}
											dLastStart = dEnd;
											solution.variables.ovFunctions.varBound[j].interval[k].end = dEnd;
											String sSlope = eInterval.getAttribute("slope");
											double dSlope = Double.NaN;
											if(sSlope == null || sSlope.length() == 0){
												dSlope = 0;
											}
											if(sSlope.equals("INF")){
												dSlope = Double.POSITIVE_INFINITY;
											}
											else if(sSlope.equals("-INF")){
												dSlope = Double.NEGATIVE_INFINITY;
											}
											else{
												dSlope = Double.parseDouble(sSlope);
											}
											solution.variables.ovFunctions.varBound[j].interval[k].slope = dSlope;
										}
										catch(Exception e){		
										}
									}
								}
							}
						}
					}
					//variable other
					Vector<Element> vOther = XMLUtil.getChildElementsByTagName(eVariables, "other");
					if(vOther != null && vOther.size() > 0){
						int iOther = vOther.size();
						solution.variables.other = new OtherVariableResult[iOther];
						for(int j = 0; j < iOther; j++){
							Element eOther = (Element)vOther.elementAt(j);
							solution.variables.other[j] = new OtherVariableResult(); 
							NodeList vars = eOther.getElementsByTagName("var");
							if(vars != null && vars.getLength() > 0){
								int iVars = vars.getLength();
								solution.variables.other[j].var = new OtherVarResult[iVars];
								for(int k = 0; k < iVars; k++){
									solution.variables.other[j].var[k] = new OtherVarResult();
									solution.variables.other[j].name = eOther.getAttribute("name");
									solution.variables.other[j].value = eOther.getAttribute("value");
									solution.variables.other[j].description = eOther.getAttribute("description");
									try{
										int iIndex = Integer.parseInt(((Element)vars.item(k)).getAttribute("idx"));
										solution.variables.other[j].var[k].idx = iIndex;
										String sValue = ((Element)vars.item(k)).getAttribute("value");
										if(sValue != null && sValue.length() > 0){
											solution.variables.other[j].var[k].value = sValue;
										}
										String sLbValue = ((Element)vars.item(k)).getAttribute("lbValue");
										if(sLbValue != null && sLbValue.length() > 0){
											solution.variables.other[j].var[k].lbValue = sLbValue;
										}
										String sUbValue = ((Element)vars.item(k)).getAttribute("ubValue");
										if(sUbValue != null && sUbValue.length() > 0){
											solution.variables.other[j].var[k].ubValue = sUbValue;
										}										
									}
									catch(Exception e){									
									}
								}
							}
						}
					}
				}//solution variables
				
				Element eObjectives = (Element)XMLUtil.findChildNode(eSolution, "objectives");
				if(eObjectives != null){
					solution.objectives = new ObjectiveSolution();
					//objective values
					Element eValues = (Element)XMLUtil.findChildNode(eObjectives, "values");
					if(eValues != null){
						solution.objectives.values = new ObjectiveValues(); 
						NodeList objs = eValues.getElementsByTagName("obj");
						if(objs != null && objs.getLength() > 0){
							int iObjs = objs.getLength();
							solution.objectives.values.obj = new ObjValue[iObjs];
							for(int j = 0; j < iObjs; j++){
								solution.objectives.values.obj[j] = new ObjValue();
								try{
									int iIndex = Integer.parseInt(((Element)objs.item(j)).getAttribute("idx"));
									solution.objectives.values.obj[j].idx = iIndex;
									String sValue = ((Element)objs.item(j)).getAttribute("value");
									double dValue = 0;
									if(sValue == null || sValue.length() == 0){
										dValue = 0;
									}
									else if(sValue.equals("INF")){
										dValue = Double.POSITIVE_INFINITY;
									}
									else if(sValue.equals("-INF")){
										dValue = Double.NEGATIVE_INFINITY;
									}
									else{
										dValue = Double.parseDouble(sValue);
									}
									solution.objectives.values.obj[j].value = dValue;
								}
								catch(Exception e){									
								}
							}
						}
					}
					//objective ovFunctions
					Element eOVFunctions = (Element)XMLUtil.findChildNode(eObjectives, "ovFunctions");
					if(eOVFunctions != null){
						solution.objectives.ovFunctions = new ObjectiveOVFunctions(); 
						Vector<Element> vVarCoefs = XMLUtil.getChildElementsByTagName(eOVFunctions, "varCoef");
						if(vVarCoefs != null && vVarCoefs.size() > 0){
							int iVarCoefs = vVarCoefs.size();
							solution.objectives.ovFunctions.varCoef = new OVFunction[iVarCoefs];
							for(int j = 0; j < iVarCoefs; j++){
								solution.objectives.ovFunctions.varCoef[j] = new OVFunction();
								Element eVarCoef = (Element)vVarCoefs.elementAt(j);
								try{
									int iIndex = Integer.parseInt(eVarCoef.getAttribute("idx"));
									solution.objectives.ovFunctions.varCoef[j].idx = iIndex;
									solution.objectives.ovFunctions.varCoef[j].type = eVarCoef.getAttribute("type");
								}
								catch(Exception e){
								}
								NodeList intervals = eVarCoef.getElementsByTagName("interval");
								if(intervals != null && intervals.getLength() > 0){
									int iIntervals = intervals.getLength();
									solution.objectives.ovFunctions.varCoef[j].interval = new OVFunctionInterval[iIntervals];
									for(int k = 0; k < iIntervals; k++){
										double dLastStart = Double.NEGATIVE_INFINITY;
										solution.objectives.ovFunctions.varCoef[j].interval[k] = new OVFunctionInterval();
										Element eInterval = (Element)intervals.item(k);
										try{
											String sStart = eInterval.getAttribute("start");
											double dStart = Double.NaN;
											if(sStart == null || sStart.length() == 0){
												dStart = dLastStart;
											}
											if(sStart.equals("INF")){
												dStart = Double.POSITIVE_INFINITY;
											}
											else if(sStart.equals("-INF")){
												dStart = Double.NEGATIVE_INFINITY;
											}
											else{
												dStart = Double.parseDouble(sStart);
											}
											solution.objectives.ovFunctions.varCoef[j].interval[k].start = dStart;
											String sEnd = eInterval.getAttribute("end");
											double dEnd = Double.NaN;
											if(sEnd == null || sEnd.length() == 0){
												dEnd = Double.POSITIVE_INFINITY;
											}
											if(sEnd.equals("INF")){
												dEnd = Double.POSITIVE_INFINITY;
											}
											else if(sEnd.equals("-INF")){
												dEnd = Double.NEGATIVE_INFINITY;
											}
											else{
												dEnd = Double.parseDouble(sEnd);
											}
											dLastStart = dEnd;
											solution.objectives.ovFunctions.varCoef[j].interval[k].end = dEnd;
											String sSlope = eInterval.getAttribute("slope");
											double dSlope = Double.NaN;
											if(sSlope == null || sSlope.length() == 0){
												dSlope = 0;
											}
											if(sSlope.equals("INF")){
												dSlope = Double.POSITIVE_INFINITY;
											}
											else if(sSlope.equals("-INF")){
												dSlope = Double.NEGATIVE_INFINITY;
											}
											else{
												dSlope = Double.parseDouble(sSlope);
											}
											solution.objectives.ovFunctions.varCoef[j].interval[k].slope = dSlope;
										}
										catch(Exception e){		
										}
									}
								}
							}
						}
					}
					//objective other
					Vector<Element> vOther = XMLUtil.getChildElementsByTagName(eObjectives, "other");
					if(vOther != null && vOther.size() > 0){
						int iOther = vOther.size();
						solution.objectives.other = new OtherObjectiveResult[iOther];
						for(int j = 0; j < iOther; j++){
							Element eOther = (Element)vOther.elementAt(j);
							solution.objectives.other[j] = new OtherObjectiveResult(); 
							NodeList objs = eOther.getElementsByTagName("obj");
							if(objs != null && objs.getLength() > 0){
								int iObjs = objs.getLength();
								solution.objectives.other[j].obj = new OtherObjResult[iObjs];
								for(int k = 0; k < iObjs; k++){
									solution.objectives.other[j].obj[k] = new OtherObjResult();
									solution.objectives.other[j].name = eOther.getAttribute("name");
									solution.objectives.other[j].value = eOther.getAttribute("value");
									solution.objectives.other[j].description = eOther.getAttribute("description");
									try{
										int iIndex = Integer.parseInt(((Element)objs.item(k)).getAttribute("idx"));
										solution.objectives.other[j].obj[k].idx = iIndex;
										String sValue = ((Element)objs.item(k)).getAttribute("value");
										if(sValue != null && sValue.length() > 0){
											solution.objectives.other[j].obj[k].value = sValue;
										}
									}
									catch(Exception e){									
									}
								}
							}
						}
					}
				}//solution objectives
				
				Element eConstraints = (Element)XMLUtil.findChildNode(eSolution, "constraints");
				if(eConstraints != null){
					solution.constraints = new ConstraintSolution();
					//constraint values
					Element eValues = (Element)XMLUtil.findChildNode(eConstraints, "values");
					if(eValues != null){
						solution.constraints.values = new ConstraintValues(); 
						NodeList cons = eValues.getElementsByTagName("con");
						if(cons != null && cons.getLength() > 0){
							int icons = cons.getLength();
							solution.constraints.values.con = new ConValue[icons];
							for(int j = 0; j < icons; j++){
								solution.constraints.values.con[j] = new ConValue();
								try{
									int iIndex = Integer.parseInt(((Element)cons.item(j)).getAttribute("idx"));
									solution.constraints.values.con[j].idx = iIndex;
									String sValue = ((Element)cons.item(j)).getAttribute("value");
									double dValue = 0;
									if(sValue == null || sValue.length() == 0){
										dValue = 0;
									}
									else if(sValue.equals("INF")){
										dValue = Double.POSITIVE_INFINITY;
									}
									else if(sValue.equals("-INF")){
										dValue = Double.NEGATIVE_INFINITY;
									}
									else{
										dValue = Double.parseDouble(sValue);
									}
									solution.constraints.values.con[j].value = dValue;
								}
								catch(Exception e){									
								}
							}
						}
					}
					//constraint dualUnboundedDirections
					Element eDualUnboundedDirections = (Element)XMLUtil.findChildNode(eConstraints, "dualUnboundedDirections");
					if(eDualUnboundedDirections != null){
						solution.constraints.dualUnboundedDirections = new DualVariableUnboundedDirections(); 
						NodeList cons = eDualUnboundedDirections.getElementsByTagName("con");
						if(cons != null && cons.getLength() > 0){
							int icons = cons.getLength();
							solution.constraints.dualUnboundedDirections.con = new DualVarUnboundedDirection[icons];
							for(int j = 0; j < icons; j++){
								solution.constraints.dualUnboundedDirections.con[j] = new DualVarUnboundedDirection();
								try{
									int iIndex = Integer.parseInt(((Element)cons.item(j)).getAttribute("idx"));
									solution.constraints.dualUnboundedDirections.con[j].idx = iIndex;
									String sLbValue = ((Element)cons.item(j)).getAttribute("lbValue");
									double dLbValue = Double.NaN;
									if(sLbValue == null || sLbValue.length() == 0){
										dLbValue = 0;
									}
									else if(sLbValue.equals("INF")){
										dLbValue = Double.POSITIVE_INFINITY;
									}
									else if(sLbValue.equals("-INF")){
										dLbValue = Double.NEGATIVE_INFINITY;
									}
									else{
										dLbValue = Double.parseDouble(sLbValue);
									}
									solution.constraints.dualUnboundedDirections.con[j].lbValue = dLbValue;
									String sUbValue = ((Element)cons.item(j)).getAttribute("ubValue");
									double dUbValue = Double.NaN;
									if(sUbValue == null || sUbValue.length() == 0){
										dUbValue = 0;
									}
									else if(sUbValue.equals("INF")){
										dUbValue = Double.POSITIVE_INFINITY;
									}
									else if(sUbValue.equals("-INF")){
										dUbValue = Double.NEGATIVE_INFINITY;
									}
									else{
										dUbValue = Double.parseDouble(sUbValue);
									}
									solution.constraints.dualUnboundedDirections.con[j].ubValue = dUbValue;
								}
								catch(Exception e){									
								}
							}
						}
					}
					//constraint irreducibleInconsistentSystem
					Element eIrreducibleInconsistentSystem = (Element)XMLUtil.findChildNode(eConstraints, "irreducibleInconsistentSystem");
					if(eIrreducibleInconsistentSystem != null){
						solution.constraints.irreducibleInconsistentSystem = new ConstraintIrreducibleInconsistentSystem(); 
						NodeList cons = eIrreducibleInconsistentSystem.getElementsByTagName("con");
						if(cons != null && cons.getLength() > 0){
							int icons = cons.getLength();
							solution.constraints.irreducibleInconsistentSystem.con = new ConIrreducibleInconsistentSystem[icons];
							for(int j = 0; j < icons; j++){
								solution.constraints.irreducibleInconsistentSystem.con[j] = new ConIrreducibleInconsistentSystem();
								int iIndex = Integer.parseInt(((Element)cons.item(j)).getAttribute("idx"));
								solution.constraints.irreducibleInconsistentSystem.con[j].idx = iIndex;
								String sType = ((Element)cons.item(j)).getAttribute("type");
								solution.constraints.irreducibleInconsistentSystem.con[j].type = sType;
							}
						}
					}
					//constraint dualValues
					Element eDualValues = (Element)XMLUtil.findChildNode(eConstraints, "dualValues");
					if(eDualValues != null){
						solution.constraints.dualValues = new DualVariableValues(); 
						NodeList cons = eDualValues.getElementsByTagName("con");
						if(cons != null && cons.getLength() > 0){
							int icons = cons.getLength();
							solution.constraints.dualValues.con = new DualVarValue[icons];
							for(int j = 0; j < icons; j++){
								solution.constraints.dualValues.con[j] = new DualVarValue();
								try{
									int iIndex = Integer.parseInt(((Element)cons.item(j)).getAttribute("idx"));
									solution.constraints.dualValues.con[j].idx = iIndex;
									String sLbValue = ((Element)cons.item(j)).getAttribute("lbValue");
									double dLbValue = 0;
									if(sLbValue == null || sLbValue.length() == 0){
										dLbValue = 0;
									}
									else if(sLbValue.equals("INF")){
										dLbValue = Double.POSITIVE_INFINITY;
									}
									else if(sLbValue.equals("-INF")){
										dLbValue = Double.NEGATIVE_INFINITY;
									}
									else{
										dLbValue = Double.parseDouble(sLbValue);
									}
									solution.constraints.dualValues.con[j].lbValue = dLbValue;
									String sUbValue = ((Element)cons.item(j)).getAttribute("ubValue");
									double dUbValue = 0;
									if(sUbValue == null || sUbValue.length() == 0){
										dUbValue = 0;
									}
									if(sUbValue.equals("INF")){
										dUbValue = Double.POSITIVE_INFINITY;
									}
									else if(sUbValue.equals("-INF")){
										dUbValue = Double.NEGATIVE_INFINITY;
									}
									else{
										dUbValue = Double.parseDouble(sUbValue);
									}
									solution.constraints.dualValues.con[j].ubValue = dUbValue;
								}
								catch(Exception e){									
								}
							}
						}
					}
					//constraint slacks
					Element eSlacks = (Element)XMLUtil.findChildNode(eConstraints, "slacks");
					if(eSlacks != null){
						solution.constraints.slacks = new ConstraintSlacks(); 
						NodeList cons = eSlacks.getElementsByTagName("con");
						if(cons != null && cons.getLength() > 0){
							int icons = cons.getLength();
							solution.constraints.slacks.con = new ConSlack[icons];
							for(int j = 0; j < icons; j++){
								solution.constraints.slacks.con[j] = new ConSlack();
								try{
									int iIndex = Integer.parseInt(((Element)cons.item(j)).getAttribute("idx"));
									solution.constraints.slacks.con[j].idx = iIndex;
									String sLbValue = ((Element)cons.item(j)).getAttribute("lbValue");
									double dLbValue = Double.NaN;
									if(sLbValue == null || sLbValue.length() == 0){
										dLbValue = 0;
									}
									else if(sLbValue.equals("INF")){
										dLbValue = Double.POSITIVE_INFINITY;
									}
									else if(sLbValue.equals("-INF")){
										dLbValue = Double.NEGATIVE_INFINITY;
									}
									else{
										dLbValue = Double.parseDouble(sLbValue);
									}
									solution.constraints.slacks.con[j].lbValue = dLbValue;
									String sUbValue = ((Element)cons.item(j)).getAttribute("ubValue");
									double dUbValue = Double.NaN;
									if(sUbValue == null || sUbValue.length() == 0){
										dUbValue = 0;
									}
									else if(sUbValue.equals("INF")){
										dUbValue = Double.POSITIVE_INFINITY;
									}
									else if(sUbValue.equals("-INF")){
										dUbValue = Double.NEGATIVE_INFINITY;
									}
									else{
										dUbValue = Double.parseDouble(sUbValue);
									}
									solution.constraints.slacks.con[j].ubValue = dUbValue;
								}
								catch(Exception e){									
								}
							}
						}
					}
					//constraint allowableIncreases
					Element eAllowableIncreases = (Element)XMLUtil.findChildNode(eConstraints, "allowableIncreases");
					if(eAllowableIncreases != null){
						solution.constraints.allowableIncreases = new ConstraintAllowableIncreases(); 
						NodeList cons = eAllowableIncreases.getElementsByTagName("con");
						if(cons != null && cons.getLength() > 0){
							int icons = cons.getLength();
							solution.constraints.allowableIncreases.con = new ConAllowableIncrease[icons];
							for(int j = 0; j < icons; j++){
								solution.constraints.allowableIncreases.con[j] = new ConAllowableIncrease();
								try{
									int iIndex = Integer.parseInt(((Element)cons.item(j)).getAttribute("idx"));
									solution.constraints.allowableIncreases.con[j].idx = iIndex;
									String sLbValue = ((Element)cons.item(j)).getAttribute("lbValue");
									double dLbValue = Double.NaN;
									if(sLbValue == null || sLbValue.length() == 0){
										dLbValue = 0;
									}
									else if(sLbValue.equals("INF")){
										dLbValue = Double.POSITIVE_INFINITY;
									}
									else if(sLbValue.equals("-INF")){
										dLbValue = Double.NEGATIVE_INFINITY;
									}
									else{
										dLbValue = Double.parseDouble(sLbValue);
									}
									solution.constraints.allowableIncreases.con[j].lbValue = dLbValue;
									String sUbValue = ((Element)cons.item(j)).getAttribute("ubValue");
									double dUbValue = Double.NaN;
									if(sUbValue == null || sUbValue.length() == 0){
										dUbValue = 0;
									}
									else if(sUbValue.equals("INF")){
										dUbValue = Double.POSITIVE_INFINITY;
									}
									else if(sUbValue.equals("-INF")){
										dUbValue = Double.NEGATIVE_INFINITY;
									}
									else{
										dUbValue = Double.parseDouble(sUbValue);
									}
									solution.constraints.allowableIncreases.con[j].ubValue = dUbValue;
								}
								catch(Exception e){									
								}
							}
						}
					}
					//constraint allowableDecreases
					Element eAllowableDecreases = (Element)XMLUtil.findChildNode(eConstraints, "allowableDecreases");
					if(eAllowableDecreases != null){
						solution.constraints.allowableDecreases = new ConstraintAllowableDecreases(); 
						NodeList cons = eAllowableDecreases.getElementsByTagName("con");
						if(cons != null && cons.getLength() > 0){
							int icons = cons.getLength();
							solution.constraints.allowableDecreases.con = new ConAllowableDecrease[icons];
							for(int j = 0; j < icons; j++){
								solution.constraints.allowableDecreases.con[j] = new ConAllowableDecrease();
								try{
									int iIndex = Integer.parseInt(((Element)cons.item(j)).getAttribute("idx"));
									solution.constraints.allowableDecreases.con[j].idx = iIndex;
									String sLbValue = ((Element)cons.item(j)).getAttribute("lbValue");
									double dLbValue = Double.NaN;
									if(sLbValue == null || sLbValue.length() == 0){
										dLbValue = 0;
									}
									else if(sLbValue.equals("INF")){
										dLbValue = Double.POSITIVE_INFINITY;
									}
									else if(sLbValue.equals("-INF")){
										dLbValue = Double.NEGATIVE_INFINITY;
									}
									else{
										dLbValue = Double.parseDouble(sLbValue);
									}
									solution.constraints.allowableDecreases.con[j].lbValue = dLbValue;
									String sUbValue = ((Element)cons.item(j)).getAttribute("ubValue");
									double dUbValue = Double.NaN;
									if(sUbValue == null || sUbValue.length() == 0){
										dUbValue = 0;
									}
									else if(sUbValue.equals("INF")){
										dUbValue = Double.POSITIVE_INFINITY;
									}
									else if(sUbValue.equals("-INF")){
										dUbValue = Double.NEGATIVE_INFINITY;
									}
									else{
										dUbValue = Double.parseDouble(sUbValue);
									}
									solution.constraints.allowableDecreases.con[j].ubValue = dUbValue;
								}
								catch(Exception e){									
								}
							}
						}
					}
					//constraint ovFunctions
					Element eOVFunctions = (Element)XMLUtil.findChildNode(eConstraints, "ovFunctions");
					if(eOVFunctions != null){
						solution.constraints.ovFunctions = new ConstraintOVFunctions(); 
						Vector<Element> vConBounds = XMLUtil.getChildElementsByTagName(eOVFunctions, "conBound");
						if(vConBounds != null && vConBounds.size() > 0){
							int iConBounds = vConBounds.size();
							solution.constraints.ovFunctions.conBound = new OVFunction[iConBounds];
							for(int j = 0; j < iConBounds; j++){
								solution.constraints.ovFunctions.conBound[j] = new OVFunction();
								Element eConBound = (Element)vConBounds.elementAt(j);
								try{
									int iIndex = Integer.parseInt(eConBound.getAttribute("idx"));
									solution.constraints.ovFunctions.conBound[j].idx = iIndex;
									solution.constraints.ovFunctions.conBound[j].type = eConBound.getAttribute("type");
								}
								catch(Exception e){
								}
								NodeList intervals = eConBound.getElementsByTagName("interval");
								if(intervals != null && intervals.getLength() > 0){
									int iIntervals = intervals.getLength();
									solution.constraints.ovFunctions.conBound[j].interval = new OVFunctionInterval[iIntervals];
									for(int k = 0; k < iIntervals; k++){
										double dLastStart = Double.NEGATIVE_INFINITY;
										solution.constraints.ovFunctions.conBound[j].interval[k] = new OVFunctionInterval();
										Element eInterval = (Element)intervals.item(k);
										try{
											String sStart = eInterval.getAttribute("start");
											double dStart = Double.NaN;
											if(sStart == null || sStart.length() == 0){
												dStart = dLastStart;
											}
											if(sStart.equals("INF")){
												dStart = Double.POSITIVE_INFINITY;
											}
											else if(sStart.equals("-INF")){
												dStart = Double.NEGATIVE_INFINITY;
											}
											else{
												dStart = Double.parseDouble(sStart);
											}
											solution.constraints.ovFunctions.conBound[j].interval[k].start = dStart;
											String sEnd = eInterval.getAttribute("end");
											double dEnd = Double.NaN;
											if(sEnd == null || sEnd.length() == 0){
												dEnd = Double.POSITIVE_INFINITY;
											}
											if(sEnd.equals("INF")){
												dEnd = Double.POSITIVE_INFINITY;
											}
											else if(sEnd.equals("-INF")){
												dEnd = Double.NEGATIVE_INFINITY;
											}
											else{
												dEnd = Double.parseDouble(sEnd);
											}
											dLastStart = dEnd;
											solution.constraints.ovFunctions.conBound[j].interval[k].end = dEnd;
											String sSlope = eInterval.getAttribute("slope");
											double dSlope = Double.NaN;
											if(sSlope == null || sSlope.length() == 0){
												dSlope = 0;
											}
											if(sSlope.equals("INF")){
												dSlope = Double.POSITIVE_INFINITY;
											}
											else if(sSlope.equals("-INF")){
												dSlope = Double.NEGATIVE_INFINITY;
											}
											else{
												dSlope = Double.parseDouble(sSlope);
											}
											solution.constraints.ovFunctions.conBound[j].interval[k].slope = dSlope;
										}
										catch(Exception e){		
										}
									}
								}
							}
						}
					}
					//constraint other
					Vector<Element> vOther = XMLUtil.getChildElementsByTagName(eConstraints, "other");
					if(vOther != null && vOther.size() > 0){
						int iOther = vOther.size();
						solution.constraints.other = new OtherConstraintResult[iOther];
						for(int j = 0; j < iOther; j++){
							Element eOther = (Element)vOther.elementAt(j);
							solution.constraints.other[j] = new OtherConstraintResult(); 
							NodeList cons = eOther.getElementsByTagName("con");
							if(cons != null && cons.getLength() > 0){
								int icons = cons.getLength();
								solution.constraints.other[j].con = new OtherConResult[icons];
								for(int k = 0; k < icons; k++){
									solution.constraints.other[j].con[k] = new OtherConResult();
									solution.constraints.other[j].name = eOther.getAttribute("name");
									solution.constraints.other[j].value = eOther.getAttribute("value");
									solution.constraints.other[j].description = eOther.getAttribute("description");
									try{
										int iIndex = Integer.parseInt(((Element)cons.item(k)).getAttribute("idx"));
										solution.constraints.other[j].con[k].idx = iIndex;
										String sValue = ((Element)cons.item(k)).getAttribute("value");
										if(sValue != null && sValue.length() > 0){
											solution.constraints.other[j].con[k].value = sValue;
										}
										String sLbValue = ((Element)cons.item(k)).getAttribute("lbValue");
										if(sLbValue != null && sLbValue.length() > 0){
											solution.constraints.other[j].con[k].lbValue = sLbValue;
										}
										String sUbValue = ((Element)cons.item(k)).getAttribute("ubValue");
										if(sUbValue != null && sUbValue.length() > 0){
											solution.constraints.other[j].con[k].ubValue = sUbValue;
										}										
									}
									catch(Exception e){									
									}
								}
							}
						}
					}
				}//solution constraints
				
				Vector<Element> vOtherOptimizationResults = XMLUtil.getChildElementsByTagName(eSolution, "other");
				if(vOtherOptimizationResults != null && vOtherOptimizationResults.size() > 0){
					int iOthers = vOtherOptimizationResults.size();
					solution.other = new OtherOptimizationResult[iOthers];
					for(int j = 0; j < iOthers; j++){
						Element eOther = (Element)vOtherOptimizationResults.elementAt(j);						
						solution.other[j] = new OtherOptimizationResult();
						solution.other[j].name = eOther.getAttribute("name");
						solution.other[j].value = eOther.getAttribute("value");
						solution.other[j].description = eOther.getAttribute("description");
					}//for each other result
				}//solution other results
			}//for each solution	
			
			Element eOSaL = (Element)XMLUtil.findChildNode(eOptimization, "osal");
			if(eOSaL != null){
				OSaLReader osalReader = new OSaLReader(OSParameter.VALIDATE);
				osalReader.setRootElement(eOSaL);
				OSAnalysis osAnalysis;
				try {
					osAnalysis = osalReader.getOSAnalysis();
					m_optimizationResult.osal = osAnalysis;
				} 
				catch (Exception e){
					return false;
				}
			}//last optional osal		
		}//if there are solutions

		m_bProcessOptimizationResult = true;
		return true;
	}//processOptimizationResult
	
	/**
	 * Get one solution of optimal primal variable values. 
	 * 
	 * @param objIdx holds the objective index the optimal value corresponds to. 
	 * @return a double dense array of the optimal values, null if no optimal value. 
	 */
	public double[] getOptimalPrimalVariableValues(int objIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || m_optimizationResult.solution.length <= 0) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		int iSolutions = m_optimizationResult.solution.length;
		double[] mdValues = null;
		for(int i = 0; i < iSolutions; i++){
			if(m_optimizationResult.solution[i] == null) continue;
			if(m_optimizationResult.solution[i].objectiveIdx != objIdx) continue;
			if(m_optimizationResult.solution[i].variables == null) continue;
			if(m_optimizationResult.solution[i].variables.values == null) continue;
			if((m_optimizationResult.solution[i].status.type.endsWith("ptimal") && mdValues == null)||
				    m_optimizationResult.solution[i].status.type.equals("globallyOptimal")){				
				VarValue[] var = m_optimizationResult.solution[i].variables.values.var; 
				int iVars = (var==null)?0:var.length;
				mdValues = new double[iNumberOfVariables];
				for(int j = 0; j < iVars; j++){
					mdValues[var[j].idx] = var[j].value;
				}
			}	
			if(m_optimizationResult.solution[i].status.type.equals("globallyOptimal")){
				return mdValues;
			}
		}
		return mdValues;
	}//getOptimalPrimalVariableValues

	/**
	 * Get one solution of optimal primal variable string values.
	 *  
	 * @param objIdx holds the objective index the optimal value corresponds to. 
	 * @return a string dense array of the optimal string values, null if no optimal value. 
	 */
	public String[] getOptimalPrimalVariableStringValues(int objIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || m_optimizationResult.solution.length <= 0) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		int iSolutions = m_optimizationResult.solution.length;
		String[] msValues = null;
		for(int i = 0; i < iSolutions; i++){
			if(m_optimizationResult.solution[i] == null) continue;
			if(m_optimizationResult.solution[i].objectiveIdx != objIdx) continue;
			if(m_optimizationResult.solution[i].variables == null) continue;
			if(m_optimizationResult.solution[i].variables.valuesString == null) continue;
			if((m_optimizationResult.solution[i].status.type.endsWith("ptimal") && msValues == null)||
			    m_optimizationResult.solution[i].status.type.equals("globallyOptimal")){
				VarStringValue[] var = m_optimizationResult.solution[i].variables.valuesString.var; 
				int iVars = (var==null)?0:var.length;
				msValues = new String[iNumberOfVariables];
				for(int j = 0; j < iVars; j++){
					msValues[var[j].idx] = var[j].value;
				}
			}	
			if(m_optimizationResult.solution[i].status.type.equals("globallyOptimal")){
				return msValues;
			}
		}
		return msValues;		
	}//getOptimalPrimalVariableStringValues
	
	/**
	 * Get one solution of optimal dual variable values. 
	 * 
	 * @param objIdx holds the objective index the optimal value corresponds to. 
	 * @return a double dense array of the optimal dual values, null if no optimal value. 
	 */
	public double[] getOptimalDualVariableValues(int objIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || m_optimizationResult.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = m_optimizationResult.solution.length;
		double[] mdValues = null;
		for(int i = 0; i < iSolutions; i++){
			if(m_optimizationResult.solution[i] == null) continue;
			if(m_optimizationResult.solution[i].objectiveIdx != objIdx) continue;
			if(m_optimizationResult.solution[i].constraints == null) continue;
			if(m_optimizationResult.solution[i].constraints.dualValues == null) continue;
			if((m_optimizationResult.solution[i].status.type.endsWith("ptimal") && mdValues == null)||
				    m_optimizationResult.solution[i].status.type.equals("globallyOptimal")){				
				DualVarValue[] con = m_optimizationResult.solution[i].constraints.dualValues.con; 
				int iCons = (con==null)?0:con.length;
				mdValues = new double[iNumberOfConstraints];
				for(int j = 0; j < iCons; j++){
					if(!Double.isNaN(con[j].lbValue) && con[j].lbValue != 0){
						mdValues[con[j].idx] = con[j].lbValue;
					}
					else if(!Double.isNaN(con[j].ubValue) && con[j].ubValue != 0){
						mdValues[con[j].idx] = con[j].ubValue;
					}
				}
			}	
			if(m_optimizationResult.solution[i].status.type.equals("globallyOptimal")){
				return mdValues;
			}
		}
		return mdValues;		
	}//getOptimalDualVariableValues
	
	/**
	 * Get the [i]th optimization solution, where i equals the given solution index.
	 *    
	 * @param solIdx holds the solution index to get the solution. 
	 * @return the optimization solution that corresponds to solIdx, null if none. 
	 */
	public OptimizationSolution getSolution(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || 
		   m_optimizationResult.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  m_optimizationResult.solution.length) return null;
		return m_optimizationResult.solution[solIdx];
	}//getSolution
	
	
	/**
	 * Get the [i]th optimization solution status, where i equals the given solution index.   
	 * The solution status includes the status type, optional descriptions and possibly substatuses.
	 *  
	 * @param solIdx holds the solution index to get the solution status. 
	 * @return the optimization solution status that corresponds to solIdx, null if none.
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolutionStatus
	 */
	public OptimizationSolutionStatus getSolutionStatus( int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || 
		   m_optimizationResult.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  m_optimizationResult.solution.length) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		return m_optimizationResult.solution[solIdx].status;
	}//getSolutionStatus
	
	/**
	 * Get the [i]th optimization solution status type, where i equals the given solution index.   
	 * The solution status type can be: 
	 * unbounded, globallyOptimal, locallyOptimal, optimal, bestSoFar, feasible, infeasible, 
	 * stoppedByLimit, unsure, error, other 
	 * 
	 * @param solIdx holds the solution index to get the solution status type. 
	 * @return the optimization solution status type that corresponds to solIdx, null or empty string if none.
	 */
	public String getSolutionStatusType(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || 
		   m_optimizationResult.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  m_optimizationResult.solution.length) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		if(m_optimizationResult.solution[solIdx].status == null) return null;
		return m_optimizationResult.solution[solIdx].status.type;
	}//getSolutionStatusType
	
	/**
	 * Get the [i]th optimization solution status description, where i equals the given solution index.   
	 * 
	 * @param solIdx holds the solution index to get the solution status description. 
	 * @return the optimization solution status description that corresponds to solIdx, null or empty string if none.
	 */
	public String getSolutionStatusDescription(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || 
		   m_optimizationResult.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  m_optimizationResult.solution.length) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		if(m_optimizationResult.solution[solIdx].status == null) return null;
		return m_optimizationResult.solution[solIdx].status.description;	
	}//getSolutionStatusDescription
	
	/**
	 * Get the [i]th optimization solution subStatuses, where i equals the given solution index.   
	 * 
	 * @param solIdx holds the solution index to get the solution substatuses. 
	 * @return an array optimization solution subStatuses that corresponds to solIdx, null or empty string if none.
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolutionSubstatus;
	 */
	public OptimizationSolutionSubstatus[] getSolutionSubStatuses(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || 
		   m_optimizationResult.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  m_optimizationResult.solution.length) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		if(m_optimizationResult.solution[solIdx].status == null) return null;
		return m_optimizationResult.solution[solIdx].status.substatus;
	}//getSolutionSubStatuses

	/**
	 * Get the [i]th optimization solution message, where i equals the given solution index.  
	 * 
	 * @param solIdx holds the solution index to get the solution message. 
	 * @return the optimization solution message that corresponds to solIdx, null or empty if none.
	 */
	public String getSolutionMessage(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || 
		   m_optimizationResult.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  m_optimizationResult.solution.length) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		return m_optimizationResult.solution[solIdx].message;
	}//getSolutionMessage
	
	/**
	 * Get the [i]th optimization solution's objective index, where i equals the given solution index. 
	 * The first objective's index should be -1, the second -2, and so on.  
	 * 
	 * @param solIdx holds the solution index to get the variable string values. 
	 * @return the optimization objective index that corresponds to solIdx, 0 if none.
	 * All the objective indexes are negative starting from -1 downward. 
	 */
	public int getSolutionObjectiveIndex(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return 0;
		if(m_optimizationResult.solution == null || 
		   m_optimizationResult.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  m_optimizationResult.solution.length) return 0;
		if(m_optimizationResult.solution[solIdx] == null) return 0;
		return m_optimizationResult.solution[solIdx].objectiveIdx;		
	}//getSolutionObjectiveIndex
	
	/**
	 * Get the [i]th optimization solution's variable values, where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the variable values. 
	 * @return a double dense array of variable values, null if no variable values. 
	 */
	public double[] getVariableValues(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || m_optimizationResult.solution.length <= 0) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		int iSolutions = m_optimizationResult.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		if(m_optimizationResult.solution[solIdx].variables == null) return null;
		if(m_optimizationResult.solution[solIdx].variables.values == null) return null;
		VarValue[] var = m_optimizationResult.solution[solIdx].variables.values.var; 
		int iVars = (var==null)?0:var.length;
		double[] mdValues = new double[iNumberOfVariables];
		for(int i = 0; i < iVars; i++){
			mdValues[var[i].idx] = var[i].value;
		}
		return mdValues;	
	}//getVariableValues
	
	/**
	 * Get the [i]th optimization solution's variable values in a sparse data structure, where i equals the given solution index. 
	 * The sparse data stucture is of the VariableValues data structure. VariableValues holds var[], an array of VarValues. 
	 * Each var member contains an idx and a value. If var[] is null, all the variable values are 0. 
	 * 
	 * @param solIdx holds the solution index to get the sparse variable values. 
	 * @return a sparse variable value data structure in VaribleValues, null if no variable values. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.VariableValues
	 * @see org.optimizationservices.oscommon.datastructure.osresult.VarValue
	 */
	public VariableValues getSparseVariableValues(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || m_optimizationResult.solution.length <= 0) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		int iSolutions = m_optimizationResult.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		if(m_optimizationResult.solution[solIdx].variables == null) return null;
		return m_optimizationResult.solution[solIdx].variables.values;
	}//getSparseVariableValues
	
	/**
	 * Get the [i]th optimization solution's variable string values, where i equals the given solution index. 
	 * 
	 * @param solIdx holds the solution index to get the variable string values. 
	 * @return a string dense array of variable values, null if no variable values. 
	 */
	public double[] getVariableStringValues(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || m_optimizationResult.solution.length <= 0) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		int iSolutions = m_optimizationResult.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		if(m_optimizationResult.solution[solIdx].variables == null) return null;
		if(m_optimizationResult.solution[solIdx].variables.values == null) return null;
		VarValue[] var = m_optimizationResult.solution[solIdx].variables.values.var; 
		int iVars = (var==null)?0:var.length;
		double[] mdValues = new double[iNumberOfVariables];
		for(int i = 0; i < iVars; i++){
			mdValues[var[i].idx] = var[i].value;
		}
		return mdValues;	
	}//getVariableStringValues
	
	/**
	 * Get the [i]th optimization solution's primal unbounded directions, where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the primal unbounded directions. 
	 * @return a double dense array of primal variable unbounded directions, null if no values. 
	 */
	public double[] getPrimalUnboundedDirections(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || m_optimizationResult.solution.length <= 0) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		int iSolutions = m_optimizationResult.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		if(m_optimizationResult.solution[solIdx].variables == null) return null;
		if(m_optimizationResult.solution[solIdx].variables.primalUnboundedDirections == null) return null;
		PrimalVarUnboundedDirection[] var = m_optimizationResult.solution[solIdx].variables.primalUnboundedDirections.var; 
		int iVars = (var==null)?0:var.length;
		double[] mdValues = new double[iNumberOfVariables];
		for(int i = 0; i < iVars; i++){
			mdValues[var[i].idx] = var[i].value;
		}
		return mdValues;	
	}//getPrimalUnboundedDirections
	
	/**
	 * Get the [i]th optimization solution's Irreducible Inconsistent System (IIS), where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the IIS. 
	 * @return an Irreducible Inconsistent System (IIS) in the VariableIrreducibleInconsistentSystem data structure, null if none.
	 * The data structure holds an array var[]; each var member holds the variable idx and a type value (lb or ub) to indicate
	 * whether the IIS is on the variable's lower bound or upper bound. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.VariableIrreducibleInconsistentSystem
	 */
	public VariableIrreducibleInconsistentSystem getVariableIrreducibleInconsistentSystem(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || m_optimizationResult.solution.length <= 0) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		int iSolutions = m_optimizationResult.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		if(m_optimizationResult.solution[solIdx].variables == null) return null;
		return m_optimizationResult.solution[solIdx].variables.irreducibleInconsistentSystem;	
	}//getVariableIrreducibleInconsistentSystem
	
	/**
	 * Get the [i]th optimization solution's reduced costs, where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the reduced costs. 
	 * @return the reduced costs in the ReducedCosts data structure, null if none.
	 * The data structure holds an array var[]; each var member holds 
	 * a variable idx, a reduced cost value on the lower bound (lbValue) and on the upper bound (ubValue). 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.ReducedCosts
	 */
	public ReducedCosts getReducedCosts(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || m_optimizationResult.solution.length <= 0) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		int iSolutions = m_optimizationResult.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		if(m_optimizationResult.solution[solIdx].variables == null) return null;
		return m_optimizationResult.solution[solIdx].variables.reducedCosts;		
	}//getReducedCosts
	
	/**
	 * Get the [i]th optimization solution's variable slacks, where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the variable slacks. 
	 * @return the variable slacks in the VariableSlacks data structure, null if none.
	 * The data structure holds an array var[]; each var member holds 
	 * a variable idx, a slack value on the lower bound (lbValue) and on the upper bound (ubValue). 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.VariableSlacks
	 */
	public VariableSlacks getVariableSlacks(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || m_optimizationResult.solution.length <= 0) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		int iSolutions = m_optimizationResult.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		if(m_optimizationResult.solution[solIdx].variables == null) return null;
		return m_optimizationResult.solution[solIdx].variables.slacks;	
	}//getVariableSlacks
	
	/**
	 * Get the [i]th optimization solution's variable allowable increases, where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the variable allowable incresases. 
	 * @return the variable allowable incresases in the VariableAllowableIncreases data structure, null if none.
	 * The data structure holds an array var[]; each var member holds 
	 * a variable idx, an allowable increase value on the lower bound (lbValue) and on the upper bound (ubValue). 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.VariableAllowableIncreases
	 */
	public VariableAllowableIncreases getVariableAllowableIncreases(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || m_optimizationResult.solution.length <= 0) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		int iSolutions = m_optimizationResult.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		if(m_optimizationResult.solution[solIdx].variables == null) return null;
		return m_optimizationResult.solution[solIdx].variables.allowableIncreases;
	}//getVariableAllowableIncreases
	
	/**
	 * Get the [i]th optimization solution's variable allowable decreases, where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the variable allowable decresases. 
	 * @return the variable allowable decresases in the VariableAllowableDecreases data structure, null if none.
	 * The data structure holds an array var[]; each var member holds 
	 * a variable idx, an allowable decrease value on the lower bound (lbValue) and on the upper bound (ubValue). 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.VariableAllowableDecreases
	 */
	public VariableAllowableDecreases getVariableAllowableDecreases(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || m_optimizationResult.solution.length <= 0) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		int iSolutions = m_optimizationResult.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		if(m_optimizationResult.solution[solIdx].variables == null) return null;
		return m_optimizationResult.solution[solIdx].variables.allowableDecreases;	
	}//getVariableAllowableDecreases
	
	/**
	 * Get the [i]th optimization solution's variable OVFunctions, where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the variable OVFunctions. 
	 * @return the variable OVFunctions in the VariableOVFunctions data structure, null if none.
	 * The data structure holds an array varBound[]; each varBound member corresponds to one OVFunction. 
	 * The varBound type can be eq, lb or ub and the varBound holds an idx for the index of the variable. 
	 * An OVFunction is a sequence (or array) of intervals, each interval contains a start value, an end value and a slope value. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.VariableOVFunctions
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OVFunction
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OVFunctionInterval
	 */
	public VariableOVFunctions getVariableOVFunctions(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || m_optimizationResult.solution.length <= 0) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		int iSolutions = m_optimizationResult.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		if(m_optimizationResult.solution[solIdx].variables == null) return null;
		return m_optimizationResult.solution[solIdx].variables.ovFunctions;	
	}//getVariableOVFunctions
	
	/**
	 * Get the [i]th optimization solution's other (non-standard/solver specific)variable-related results, 
	 * where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the other variable results. 
	 * @return an array of other variable results in OtherVariableResult[] array data structure, null if none. 
	 * Each other variable result contains the name (required), an optional description (string) and an optional
	 * value (string). Each other variable result can also optionally contain an array OtherVarResult for each variable. 
	 * The OtherVarResult contains a variable idx (required), an optional string value, an optional string value on the lower bound (lbValue) 
	 * and an optional string value on the upper bound (ubValue).  
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherVariableResult
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherVarResult
	 */
	public OtherVariableResult[] getOtherVariableResults(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || m_optimizationResult.solution.length <= 0) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		int iSolutions = m_optimizationResult.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		if(m_optimizationResult.solution[solIdx].variables == null) return null;
		return m_optimizationResult.solution[solIdx].variables.other;
	}//getOtherVariableResults
	
	/**
	 * Get the [i]th optimization solution's objective values, where i equals the given solution index. 
	 * Usually one of the objective is what the solution was solved for (or based on). Its index should be indicated 
	 * in the solution's objectiveIdx attribute. Based on this objective's solution, the rest of the objective 
	 * values are (optionally) calculated. 
	 * @param solIdx holds the solution index to get the objective values. 
	 * @return a double dense array of objective values, null if null if no objective values. 
	 * Possibly only the objective that the solution is based on has the value, and the rest of the objective
	 * values all get a Double.NaN value, meaning that they are not calculated.   
	 */
	public double[] getObjectiveValues(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || m_optimizationResult.solution.length <= 0) return null;
		int iNumberOfObjectives = this.getObjectiveNumber();
		if(iNumberOfObjectives <= 0) return null;
		int iSolutions = m_optimizationResult.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		if(m_optimizationResult.solution[solIdx].objectives == null) return null;
		if(m_optimizationResult.solution[solIdx].objectives.values == null) return null;
		ObjValue[] obj = m_optimizationResult.solution[solIdx].objectives.values.obj; 
		int iObjs = (obj==null)?0:obj.length;
		double[] mdValues = new double[iNumberOfObjectives];
		for(int i = 0; i < iNumberOfObjectives; i++){
			mdValues[i] = Double.NaN;
		}
		for(int i = 0; i < iObjs; i++){
			mdValues[Math.abs(obj[i].idx)-1] = obj[i].value;
		}
		return mdValues;
	}//getObjectiveValues
	
	/**
	 * Get the [i]th optimization solution's objective OVFunctions, where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the objective OVFunctions. 
	 * @return the objective OVFunctions in the ObjectiveOVFunctions data structure, null if none.
	 * The data structure holds an array varCoef[]; each varCoef member corresponds to one OVFunction (for each of the objective's variable coefficients). 
	 * The varCoef holds an idx for the index of the variable. 
	 * An OVFunction is a sequence (or array) of intervals, each interval contains a start value, an end value and a slope value. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.ObjectiveOVFunctions
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OVFunction
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OVFunctionInterval
	 */
	public ObjectiveOVFunctions getObjectiveOVFunctions(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || m_optimizationResult.solution.length <= 0) return null;
		int iNumberOfObjectives = this.getObjectiveNumber();
		if(iNumberOfObjectives <= 0) return null;
		int iSolutions = m_optimizationResult.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		if(m_optimizationResult.solution[solIdx].objectives == null) return null;
		return m_optimizationResult.solution[solIdx].objectives.ovFunctions;		
	}//getObjectiveOVFunctions
	
	/**
	 * Get the [i]th optimization solution's other (non-standard/solver specific)objective-related results, 
	 * where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the other objective results. 
	 * @return an array of other objective results in OtherObjectiveResult[] array data structure, null if none. 
	 * Each other objective result contains the name (required), an optional description (string) and an optional
	 * value (string). Each other objective result can also optionally contain an array OtherObjResult for each objective. 
	 * The OtherObjResult contains an objective idx (required) and an optional string value.  
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherObjectiveResult
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherObjResult
	 */
	public OtherObjectiveResult[] getOtherObjectiveResults(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || m_optimizationResult.solution.length <= 0) return null;
		int iNumberOfObjectives = this.getObjectiveNumber();
		if(iNumberOfObjectives <= 0) return null;
		int iSolutions = m_optimizationResult.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		if(m_optimizationResult.solution[solIdx].objectives == null) return null;
		return m_optimizationResult.solution[solIdx].objectives.other;
	}//getOtherObjectiveResults
	
	/**
	 * Get the [i]th optimization solution's constraint values, where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the constraint values. 
	 * @return a double dense array of constraint values, null if no constraint values. 
	 */
	public double[] getConstraintValues(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || m_optimizationResult.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = m_optimizationResult.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		if(m_optimizationResult.solution[solIdx].constraints == null) return null;
		if(m_optimizationResult.solution[solIdx].constraints.values == null) return null;
		ConValue[] con = m_optimizationResult.solution[solIdx].constraints.values.con; 
		int iCons = (con==null)?0:con.length;
		double[] mdValues = new double[iNumberOfConstraints];
		for(int i = 0; i < iCons; i++){
			mdValues[con[i].idx] = con[i].value;
		}
		return mdValues;
	}//getConstraintValues
	
	/**
	 * Get the [i]th optimization solution's constraint values in a sparse data structure, where i equals the given solution index. 
	 * The sparse data stucture is of the ConstraintValues datastructure. ConstraintValues holds con[], an array of ConValues. 
	 * Each con member contains an idx and a value. If con[] is null, all the constraint values are 0. 
	 * 
	 * @param solIdx holds the solution index to get the sparse constraint values. 
	 * @return a sparse constraint value data structure in ConstraintValues, null if no constraint values. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.ConstraintValues
	 * @see org.optimizationservices.oscommon.datastructure.osresult.ConValue
	 */
	public ConstraintValues getSparseConstraintValues(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || m_optimizationResult.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = m_optimizationResult.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		if(m_optimizationResult.solution[solIdx].constraints == null) return null;
		return m_optimizationResult.solution[solIdx].constraints.values;
	}//getSparseConstraintValues

	/**
	 * Get the [i]th optimization solution's dual variable unbounded directions at the lower bounds, where i equals the given solution index. 
	 * 
	 * @param solIdx holds the solution index to get the dual variable unbounded directions at the lower bounds. 
	 * @return a double dense array of the dual variable unbounded directions at the lower bounds, null if none. 
	 */
	public double[] getDualUnboundedDirectionsAtLowerBounds(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || m_optimizationResult.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = m_optimizationResult.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		if(m_optimizationResult.solution[solIdx].constraints == null) return null;
		if(m_optimizationResult.solution[solIdx].constraints.dualUnboundedDirections == null) return null;
		DualVarUnboundedDirection[] con = m_optimizationResult.solution[solIdx].constraints.dualUnboundedDirections.con; 
		int iCons = (con==null)?0:con.length;
		double[] mdValues = new double[iNumberOfConstraints];
		for(int j = 0; j < iCons; j++){
			if(!Double.isNaN(con[j].lbValue)){
				mdValues[con[j].idx] = con[j].lbValue;
			}
		}
		return mdValues;
	}//getDualVariableUnboundedAtLowerBounds
	
	/**
	 * Get the [i]th optimization solution's dual variable unbounded directions at the upper bounds, where i equals the given solution index. 
	 * 
	 * @param solIdx holds the solution index to get the dual variable unbounded directions at the upper bounds. 
	 * @return a double dense array of the dual variable unbounded directions at the upper bounds, null if none. 
	 */
	public double[] getDualUnboundedDirectionsAtUpperBounds(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || m_optimizationResult.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = m_optimizationResult.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		if(m_optimizationResult.solution[solIdx].constraints == null) return null;
		if(m_optimizationResult.solution[solIdx].constraints.dualUnboundedDirections == null) return null;
		DualVarUnboundedDirection[] con = m_optimizationResult.solution[solIdx].constraints.dualUnboundedDirections.con; 
		int iCons = (con==null)?0:con.length;
		double[] mdValues = new double[iNumberOfConstraints];
		for(int j = 0; j < iCons; j++){
			if(!Double.isNaN(con[j].ubValue)){
				mdValues[con[j].idx] = con[j].ubValue;
			}
		}
		return mdValues;		
	}//getDualVariableUnboundedAtUpperBounds
	
	/**
	 * Get the [i]th optimization solution's dual variable unbounded directions in a sparse data structure, where i equals the given solution index. 
	 * The sparse data stucture is of the DualVariableUnboundedDirections data structure. DualVariableUnboundedDirections holds con[], an array of DualVarUnboundedDirections. 
	 * Each con member contains a constraint idx, a dual unbounded direction on the upper bound and lower bound. If con[] is null, all the dual variable unbounded directions are 0. 
	 * 
	 * @param solIdx holds the solution index to get the sparse dual variable unbounded directions. 
	 * @return a sparse variable unbounded direction data structure in DualVaribleUnboundedDirections, null if no dual unbounded directions. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.DualVariableUnboundedDirections
	 * @see org.optimizationservices.oscommon.datastructure.osresult.DualVarUnboundedDirection
	 */
	public DualVariableUnboundedDirections getSparseDualUnboundedDirections(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || m_optimizationResult.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = m_optimizationResult.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		if(m_optimizationResult.solution[solIdx].constraints == null) return null;
		return m_optimizationResult.solution[solIdx].constraints.dualUnboundedDirections;
	}//getSparseDualVariableUnboundedDirections
	
	/**
	 * Get the [i]th optimization solution's Irreducible Inconsistent System (IIS), where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the IIS. 
	 * @return an Irreducible Inconsistent System (IIS) in the ConstraintIrreducibleInconsistentSystem data structure, null if none.
	 * The data structure holds an array con[]; each con member holds the constraint idx and a type value (lb or ub) to indicate
	 * whether the IIS is on the constraint's lower bound or upper bound. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.ConstraintIrreducibleInconsistentSystem
	 */
	public ConstraintIrreducibleInconsistentSystem getConstraintIrreducibleInconsistentSystem(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || m_optimizationResult.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = m_optimizationResult.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		if(m_optimizationResult.solution[solIdx].constraints == null) return null;
		return m_optimizationResult.solution[solIdx].constraints.irreducibleInconsistentSystem;	
	}//getConstraintIrreducibleInconsistentSystem
	
	/**
	 * Get the [i]th optimization solution's dual variable values at the lower bounds, where i equals the given solution index. 
	 * 
	 * @param solIdx holds the solution index to get the dual variable values at the lower bounds. 
	 * @return a double dense array of the dual variable values at the lower bounds, null if none. 
	 */
	public double[] getDualVariableValuesAtLowerBounds(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || m_optimizationResult.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = m_optimizationResult.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		if(m_optimizationResult.solution[solIdx].constraints == null) return null;
		if(m_optimizationResult.solution[solIdx].constraints.dualValues == null) return null;
		DualVarValue[] con = m_optimizationResult.solution[solIdx].constraints.dualValues.con; 
		int iCons = (con==null)?0:con.length;
		double[] mdValues = new double[iNumberOfConstraints];
		for(int j = 0; j < iCons; j++){
			if(!Double.isNaN(con[j].lbValue)){
				mdValues[con[j].idx] = con[j].lbValue;
			}
		}
		return mdValues;
	}//getDualVariableValuesAtLowerBounds
	
	
	/**
	 * Get the [i]th optimization solution's dual variable values at the upper bounds, where i equals the given solution index. 
	 * 
	 * @param solIdx holds the solution index to get the dual variable values at the upper bounds. 
	 * @return a double dense array of the dual variable values at the upper bounds, null if none. 
	 */
	public double[] getDualVariableValuesAtUpperBounds(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || m_optimizationResult.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = m_optimizationResult.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		if(m_optimizationResult.solution[solIdx].constraints == null) return null;
		if(m_optimizationResult.solution[solIdx].constraints.dualValues == null) return null;
		DualVarValue[] con = m_optimizationResult.solution[solIdx].constraints.dualValues.con; 
		int iCons = (con==null)?0:con.length;
		double[] mdValues = new double[iNumberOfConstraints];
		for(int j = 0; j < iCons; j++){
			if(!Double.isNaN(con[j].ubValue)){
				mdValues[con[j].idx] = con[j].ubValue;
			}
		}
		return mdValues;	
	}//getDualVariableValuesAtUpperBounds
	
	/**
	 * Get the [i]th optimization solution's dual variable values in a sparse data structure, where i equals the given solution index. 
	 * The sparse data stucture is of the DualVariableValues data structure. DualVariableValues holds con[], an array of DualVarValues. 
	 * Each con member contains a constraint idx, a dual value on the lower bound and upper bound. If con[] is null, all the dual variable values are 0. 
	 * 
	 * @param solIdx holds the solution index to get the sparse dual variable values. 
	 * @return a sparse variable value data structure in DualVaribleValues, null if no dual variable values. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.DualVariableValues
	 * @see org.optimizationservices.oscommon.datastructure.osresult.DualVarValue
	 */
	public DualVariableValues getSparseDualVariableValues(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || m_optimizationResult.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = m_optimizationResult.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		if(m_optimizationResult.solution[solIdx].constraints == null) return null;
		return m_optimizationResult.solution[solIdx].constraints.dualValues;
	}//getSparseDualVariableValues
	
	/**
	 * Get the [i]th optimization solution's constraint slacks, where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the constraint slacks. 
	 * @return the constraint slacks in the ConstraintSlacks data structure, null if none.
	 * The data structure holds an array con[]; each con member holds 
	 * a constraint idx, a slack value on the lower bound (lbValue) and on the upper bound (ubValue). 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.ConstraintSlacks
	 */
	public ConstraintSlacks getConstraintSlacks(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || m_optimizationResult.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = m_optimizationResult.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		if(m_optimizationResult.solution[solIdx].constraints == null) return null;
		return m_optimizationResult.solution[solIdx].constraints.slacks;		
	}//getConstraintSlacks
	
	/**
	 * Get the [i]th optimization solution's constraint allowable increases, where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the constraint allowable incresases. 
	 * @return the constraint allowable incresases in the ConstraintAllowableIncreases data structure, null if none.
	 * The data structure holds an array con[]; each con member holds 
	 * a constraint idx, an allowable increase value on the lower bound (lbValue) and on the upper bound (ubValue). 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.ConstraintAllowableIncreases
	 */
	public ConstraintAllowableIncreases getConstraintAllowableIncreases(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || m_optimizationResult.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = m_optimizationResult.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		if(m_optimizationResult.solution[solIdx].constraints == null) return null;
		return m_optimizationResult.solution[solIdx].constraints.allowableIncreases;
	}//getConstraintAllowableIncreases
	
	/**
	 * Get the [i]th optimization solution's constraint allowable decreases, where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the constraint allowable decresases. 
	 * @return the constraint allowable decresases in the ConstraintAllowableDecreases data structure, null if none.
	 * The data structure holds an array con[]; each con member holds 
	 * a constraint idx, an allowable decrease value on the lower bound (lbValue) and on the upper bound (ubValue). 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.ConstraintAllowableDecreases
	 */
	public ConstraintAllowableDecreases getConstraintAllowableDecreases(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || m_optimizationResult.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = m_optimizationResult.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		if(m_optimizationResult.solution[solIdx].constraints == null) return null;
		return m_optimizationResult.solution[solIdx].constraints.allowableDecreases;	
	}//getConstraintAllowableDecreases
	
	/**
	 * Get the [i]th optimization solution's constraint OVFunctions, where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the constraint OVFunctions. 
	 * @return the constraint OVFunctions in the ConstraintOVFunctions data structure, null if none.
	 * The data structure holds an array conBound[]; each conBound member corresponds to one OVFunction. 
	 * The conBound type can be eq, lb or ub and the conBound holds an idx for the index of the constraint. 
	 * An OVFunction is a sequence (or array) of intervals, each interval contains a start value, an end value and a slope value. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.ConstraintOVFunctions
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OVFunction
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OVFunctionInterval
	 */
	public ConstraintOVFunctions getConstraintOVFunctions(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || m_optimizationResult.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = m_optimizationResult.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		if(m_optimizationResult.solution[solIdx].constraints == null) return null;
		return m_optimizationResult.solution[solIdx].constraints.ovFunctions;
	}//getConstraintOVFunctions
	
	/**
	 * Get the [i]th optimization solution's other (non-standard/solver specific)constraint-related results, 
	 * where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the other constraint results. 
	 * @return an array of other constraint results in OtherConstraintResult[] array data structure, null if none. 
	 * Each other constraint result contains the name (required), an optional description (string) and an optional
	 * value (string). Each other constraint result can also optionally contain an array OtherConResult for each constraint. 
	 * The OtherConResult contains a constraint idx (required), an optional string value, an optional string value on the lower bound (lbValue) 
	 * and an optional string value on the upper bound (ubValue).  
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherConstraintResult
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherConResult
	 */
	public OtherConstraintResult[] getOtherConstraintResults(int solIdx){
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || m_optimizationResult.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = m_optimizationResult.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		if(m_optimizationResult.solution[solIdx].constraints == null) return null;
		return m_optimizationResult.solution[solIdx].constraints.other;	
	}//getOtherConstraintResults

	/**
	 * Get the [i]th optimization solution's other (non-standard/solver specific)optimization-related results, 
	 * where i equals the given solution index. These other results are usually on the general optimization, 
	 * not specifically on the variables, objective, or constraints. 
	 *  
	 * @param solIdx holds the solution index to get the other optimization results. 
	 * @return an array of other optimization results in OtherOptimizationResult[] array data structure, null if none. 
	 * Each other optimization result contains the name (required), an optional description (string) and an optional
	 * value (string).   
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherOptimizationResult
	 */
	public OtherOptimizationResult[] getOtherOptimizationResults(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || m_optimizationResult.solution.length <= 0) return null;
		int iSolutions = m_optimizationResult.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		return m_optimizationResult.solution[solIdx].other;	
	}//getOtherOptimizationResults


	/**
	 * Get the optimization analysis in the standard OSAnalysis data structure. 
	 * 
	 * @return the optimization analysis in the standard OSAnalysis data structure, null if none.
	 * @see org.optimizationservices.oscommon.localinterface.OSAnalysis
	 */
	public OSAnalysis getOSAnalysis(){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		return m_optimizationResult.osal;
	}//getOSAnalysis
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		OSrLReader osrlReader = new OSrLReader(false);
		System.out.println(IOUtil.readStringFromFile(OSParameter.CODE_HOME + "OSRepository/test/osrl/osrl.osrl"));
		System.out.println(osrlReader.readFile(OSParameter.CODE_HOME + "OSRepository/test/osrl/osrl.osrl"));
		
		System.out.println(osrlReader.getGeneralMessage());
		System.out.println(osrlReader.getJobID());
		GeneralStatus status = osrlReader.getGeneralStatus();
		System.out.println(status.type);
		System.out.println(status.description);
		int iSubstatus = status.substatus==null?0:status.substatus.length;
		for(int i = 0; i < iSubstatus; i++){
			System.out.println(status.substatus[i].name);
			System.out.println(status.substatus[i].description);
			System.out.println(status.substatus[i].value);			
		}
		System.out.println(XMLUtil.createXSDateTime(osrlReader.getResultTime()));
		System.out.println(osrlReader.getInstanceName());
		System.out.println(osrlReader.getServiceName());
		System.out.println(osrlReader.getServiceURI());

		
		System.out.println(osrlReader.getOtherResultNumber());
		String sValue = osrlReader.getOtherResultValueByName("ad");
		if(sValue == null) System.out.println("null");
		else System.out.println(sValue);
		String sDescription = osrlReader.getOtherResultDescriptionByName("a");
		System.out.println(sDescription);
		for(int i=0;i<osrlReader.getOtherResultNumber();i++){
			System.out.println(osrlReader.getOtherResultNames()[i]);
			System.out.println(osrlReader.getOtherResultValues()[i]);
			System.out.println(osrlReader.getOtherResultDescriptions()[i]);
		}
		
		System.out.println("get process stat");
		System.out.println(osrlReader.getCurrentState());
		System.out.println(osrlReader.getAvailableDiskSpace());
		System.out.println(osrlReader.getAvailableMemory());
		System.out.println(osrlReader.getCurrentJobCount());
		System.out.println(osrlReader.getTotalJobsSoFar());
		System.out.println(XMLUtil.createXSDateTime(osrlReader.getTimeLastJobEnded()));
		System.out.println(XMLUtil.createXSDateTime(osrlReader.getTimeServiceStarted()));
		System.out.println(osrlReader.getTimeLastJobTook());
		System.out.println(osrlReader.getServiceUtilization());
		ProcessStatistics processStatistics = osrlReader.getProcessStatistics();
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
		
		
		System.out.println(osrlReader.getVariableNumber());	
		System.out.println(osrlReader.getObjectiveNumber());
		System.out.println(osrlReader.getConstraintNumber());
		System.out.println(osrlReader.getSolutionNumber());
		for(int i = 0; i < osrlReader.getSolutionNumber(); i++){
			System.out.println("************solution: " + i);
			System.out.println(osrlReader.getSolutionStatusType(i));			
			System.out.println(osrlReader.getSolutionStatusDescription(i));			
			System.out.println(osrlReader.getSolutionStatusDescription(i));			
			System.out.println(osrlReader.getSolutionObjectiveIndex(i));			
			System.out.println(osrlReader.getSolutionMessage(i));	
			OptimizationSolutionSubstatus[] substatus = osrlReader.getSolutionSubStatuses(i);
			System.out.println("sub # " + (substatus==null?0:substatus.length));
			OptimizationSolutionStatus optStatus = osrlReader.getSolutionStatus(i);
			System.out.println(optStatus.type);
			System.out.println(osrlReader.getVariableValues(i)[0]);
			System.out.println(osrlReader.getVariableStringValues(i)[0]);
			double[] mdValues = osrlReader.getPrimalUnboundedDirections(i);
			System.out.println(mdValues==null?"null":mdValues[0]);
			VariableIrreducibleInconsistentSystem varIIS = osrlReader.getVariableIrreducibleInconsistentSystem(i);
			if(varIIS != null)System.out.println(varIIS.var[1].type);
			ReducedCosts varRC = osrlReader.getReducedCosts(i);
			if(varRC != null)System.out.println(varRC.var[1].ubValue);
			VariableSlacks varSL = osrlReader.getVariableSlacks(i);
			if(varSL != null)System.out.println(varSL.var[1].ubValue);
			VariableAllowableIncreases varInc = osrlReader.getVariableAllowableIncreases(i);
			if(varInc != null)System.out.println(varInc.var[1].ubValue);
			VariableAllowableDecreases varDec = osrlReader.getVariableAllowableDecreases(i);
			if(varDec != null)System.out.println(varDec.var[1].ubValue);
			VariableOVFunctions varOV = osrlReader.getVariableOVFunctions(i);
			if(varOV != null)System.out.println(varOV.varBound[1].idx);
			if(varOV != null)System.out.println(varOV.varBound[1].type);
			if(varOV != null)System.out.println(varOV.varBound[0].interval[1].start);
			if(varOV != null)System.out.println(varOV.varBound[0].interval[1].end);
			if(varOV != null)System.out.println(varOV.varBound[0].interval[1].slope);
			OtherVariableResult[] otherVar = osrlReader.getOtherVariableResults(i);
			if(otherVar != null){
				System.out.println(otherVar.length);
				System.out.println(otherVar[0].name);
				System.out.println(otherVar[0].value);
				System.out.println(otherVar[0].description);
				System.out.println(otherVar[0].var[0].idx);
				System.out.println(otherVar[0].var[0].value);
				System.out.println(otherVar[0].var[0].lbValue);
				System.out.println(otherVar[0].var[0].ubValue);
			}
			System.out.println(osrlReader.getObjectiveValues(i)[0]);
			ObjectiveOVFunctions objOV = osrlReader.getObjectiveOVFunctions(i);
			System.out.println("objov");
			if(objOV != null)System.out.println(objOV.varCoef[1].idx);
			if(objOV != null)System.out.println(objOV.varCoef[1].type);
			if(objOV != null)System.out.println(objOV.varCoef[0].interval[1].start);
			if(objOV != null)System.out.println(objOV.varCoef[0].interval[1].end);
			if(objOV != null)System.out.println(objOV.varCoef[0].interval[1].slope);
			OtherObjectiveResult[] otherObj = osrlReader.getOtherObjectiveResults(i);
			if(otherObj != null){
				System.out.println(otherObj.length);
				System.out.println(otherObj[0].name);
				System.out.println(otherObj[0].value);
				System.out.println(otherObj[0].description);
				System.out.println(otherObj[0].obj[0].idx);
				System.out.println(otherObj[0].obj[0].value);
			}
			System.out.println(osrlReader.getConstraintValues(i)[0]);

			mdValues = osrlReader.getDualUnboundedDirectionsAtLowerBounds(i);
			System.out.println(mdValues==null?"null":mdValues[0]);
			mdValues = osrlReader.getDualUnboundedDirectionsAtUpperBounds(i);
			System.out.println(mdValues==null?"null":mdValues[0]);
			DualVariableUnboundedDirections dualUBD = osrlReader.getSparseDualUnboundedDirections(i);
			System.out.println("dualUBD");
			System.out.println(dualUBD==null?"null":dualUBD.con[0].lbValue);
			System.out.println("***");
			mdValues = osrlReader.getDualVariableValuesAtLowerBounds(i);
			System.out.println(mdValues==null?"null":mdValues[0]);
			mdValues = osrlReader.getDualVariableValuesAtUpperBounds(i);
			System.out.println(mdValues==null?"null":mdValues[0]);
			DualVariableValues dualVal = osrlReader.getSparseDualVariableValues(i);
			System.out.println("dualVal");
			System.out.println(dualVal==null?"null":dualVal.con[0].lbValue);

			ConstraintIrreducibleInconsistentSystem conIIS = osrlReader.getConstraintIrreducibleInconsistentSystem(i);
			if(conIIS != null)System.out.println(conIIS.con[1].type);
			ConstraintSlacks conSL = osrlReader.getConstraintSlacks(i);
			if(conSL != null)System.out.println(conSL.con[1].ubValue);
			ConstraintAllowableIncreases conInc = osrlReader.getConstraintAllowableIncreases(i);
			if(conInc != null)System.out.println(conInc.con[1].ubValue);
			ConstraintAllowableDecreases conDec = osrlReader.getConstraintAllowableDecreases(i);
			if(conDec != null)System.out.println(conDec.con[1].ubValue);


			ConstraintOVFunctions conOV = osrlReader.getConstraintOVFunctions(i);
			if(conOV != null)System.out.println(conOV.conBound[1].idx);
			if(conOV != null)System.out.println(conOV.conBound[1].type);
			if(conOV != null)System.out.println(conOV.conBound[0].interval[1].start);
			if(conOV != null)System.out.println(conOV.conBound[0].interval[1].end);
			if(conOV != null)System.out.println(conOV.conBound[0].interval[1].slope);
			OtherConstraintResult[] otherCon = osrlReader.getOtherConstraintResults(i);
			if(otherCon != null){
				System.out.println(otherCon.length);
				System.out.println(otherCon[0].name);
				System.out.println(otherCon[0].value);
				System.out.println(otherCon[0].description);
				System.out.println(otherCon[0].con[0].idx);
				System.out.println(otherCon[0].con[0].value);
				System.out.println(otherCon[0].con[0].lbValue);
				System.out.println(otherCon[0].con[0].ubValue);
			}
			
			OtherOptimizationResult[] otherOPT = osrlReader.getOtherOptimizationResults(i);
			if(otherOPT != null){
				System.out.println(otherOPT.length);
				System.out.println(otherOPT[0].name);
				System.out.println(otherOPT[0].description);
				System.out.println(otherOPT[0].value);
			}
		}
		System.out.println(osrlReader.getOSAnalysis().getJobID());
		
		double[] mdValues2 = osrlReader.getOptimalPrimalVariableValues(-1);
		if(mdValues2 == null) System.out.println("no optimal variable values");
		else{
			for(int i = 0; i < mdValues2.length; i++){
				System.out.println(mdValues2[i]);
			}
			
		}
		String[] msValues2 = osrlReader.getOptimalPrimalVariableStringValues(-1);
		if(msValues2 == null) System.out.println("no optimal variable string values");
		else{
			for(int i = 0; i < msValues2.length; i++){
				System.out.println(msValues2[i]);
			}
			
		}
		mdValues2 = osrlReader.getOptimalDualVariableValues(-1);
		if(mdValues2 == null) System.out.println("no optimal dual variable values");
		else{
			for(int i = 0; i < mdValues2.length; i++){
				System.out.println(mdValues2[i]);
			}
			
		}
		//osrlReader.writeToStandardOutput();
	}//main
	
}//class OSrLReader
