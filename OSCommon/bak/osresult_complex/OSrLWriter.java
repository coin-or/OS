/**
 * @(#)OSrLWriter 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.representationparser;
import java.util.GregorianCalendar;
import java.util.Vector;

import org.optimizationservices.oscommon.datastructure.osgeneral.JobDependencies;
import org.optimizationservices.oscommon.datastructure.osprocess.JobStatistics;
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
import org.optimizationservices.oscommon.datastructure.osresult.DualVarUnboundedDirection;
import org.optimizationservices.oscommon.datastructure.osresult.DualVarValue;
import org.optimizationservices.oscommon.datastructure.osresult.GeneralStatus;
import org.optimizationservices.oscommon.datastructure.osresult.GeneralSubstatus;
import org.optimizationservices.oscommon.datastructure.osresult.OVFunction;
import org.optimizationservices.oscommon.datastructure.osresult.OVFunctionInterval;
import org.optimizationservices.oscommon.datastructure.osresult.ObjValue;
import org.optimizationservices.oscommon.datastructure.osresult.ObjectiveOVFunctions;
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
import org.optimizationservices.oscommon.localinterface.OSAnalysis;
import org.optimizationservices.oscommon.localinterface.OSResult;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.XMLUtil;
import org.w3c.dom.Element;
import org.w3c.dom.Node;

/**
 * The <code>OSrLWriter</code> class is used to construct an instance that follows 
 * the OSrL format. 
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */
public class OSrLWriter extends OSgLWriter{
	
	/**
	 * m_eOSrL holds the OSrL root element.
	 */
	protected Element m_eOSrL = null;
	
	/**
	 * m_eResultHeader holds the 1st child element resultHeader of root element OSrL.
	 */
	protected Element m_eResultHeader = null;
	
	/**
	 * m_eResultData holds the 2nd child element analyisisData of root element OSrL.
	 */
	protected Element m_eResultData = null;
	
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
	 * constructor. 
	 *
	 */
	public OSrLWriter(){
		m_document = XMLUtil.createNewDocument();
		m_eOSrL = createOSrLRoot();
		m_document.appendChild(m_eOSrL);
	}//constructor
	
	/**
	 * set the OSResult, a standard os result interface. 
	 * @param osResult holds the standard os result interface. 
	 * @return whether the OSResult is set successfully. 
	 */
	public boolean setOSResult(OSResult osResult) throws Exception{
		if(!setGeneralStatus(osResult.getGeneralStatus())){ 
   			throw new Exception("setGeneralStatus Unsuccessful");
		}
		if(!setServiceURI(osResult.getServiceURI())){ 
   			throw new Exception("setServiceURI Unsuccessful");
		}
		if(!setServiceName(osResult.getServiceName())){ 
   			throw new Exception("setServiceName Unsuccessful");
		}
		if(!setInstanceName(osResult.getInstanceName())){ 
   			throw new Exception("setInstanceName Unsuccessful");
		}
		if(!setJobID(osResult.getJobID())){ 
   			throw new Exception("setJobID Unsuccessful");
		}
		if(!setResultTime(osResult.getResultTime())){ 
   			throw new Exception("setResultTime Unsuccessful");
		}
		if(!setGeneralMessage(osResult.getGeneralMessage())){ 
   			throw new Exception("setGeneralMessage Unsuccessful");
		}
		if(!setProcessStatistics(osResult.getProcessStatistics())){ 
   			throw new Exception("setProcessStatistics Unsuccessful");
		}
		if(osResult.resultData.other != null && osResult.resultData.other.length > 0){
			int n = osResult.resultData.other.length;
			String[] msNames = new String[n];
			String[] msValues = new String[n];
			String[] msDescriptions = new String[n];
			for(int i = 0; i < n; i++){
				msNames[i] = osResult.resultData.other[i].name;
				msValues[i] = osResult.resultData.other[i].value;
				msDescriptions[i] = osResult.resultData.other[i].description;
			}
			if(!setOtherResults(msNames, msValues, msDescriptions)){
				throw new Exception("setOtherResults Unsuccessful");
			}			
		}
		int iSolutionNumber = osResult.getSolutionNumber();
		if(iSolutionNumber >= 0){
			if(!setVariableNumber(osResult.getVariableNumber())){ 
	   			throw new Exception("setVariableNumber Unsuccessful");
			}
			if(!setObjectiveNumber(osResult.getObjectiveNumber())){ 
	   			throw new Exception("setObjectiveNumber Unsuccessful");
			}
			if(!setConstraintNumber(osResult.getConstraintNumber())){ 
	   			throw new Exception("setConstraintNumber Unsuccessful");
			}		
			if(!setSolutionNumber(osResult.getSolutionNumber())){ 
	   			throw new Exception("setVariableAnalysis Unsuccessful");
			}
			for(int i = 0; i < iSolutionNumber; i++){
				if(!setSolution(i, osResult.getSolution(i))){ 
		   			throw new Exception("setSolution Unsuccessful");
				}
			}
			if(!setOSAnalysis(osResult.getOSAnalysis())){ 
	   			throw new Exception("setOSAnalysis Unsuccessful");
			}			
		}
   		return true;
	}//setOSResult
	
   	/**
	 * Set the general status
	 * 
	 * @param status holds the general status.
	 * @return whether the general status is set successfully. 
	 */
	public boolean setGeneralStatus(GeneralStatus status){
		try{
			if(status != null){
				Element eStatus = (Element)XMLUtil.findChildNode(m_eResultHeader, "generalStatus");
				if(eStatus != null){
					m_eResultHeader.removeChild(eStatus);
				}
				eStatus = m_document.createElement("generalStatus");
				if(status.type != null && status.type.length() > 0){
					eStatus.setAttribute("type", status.type);					
				}
				else{
					return false;
				}
				if(status.description != null && status.description.length() > 0){
					eStatus.setAttribute("description", status.description);					
				}
				if(status.substatus != null && status.substatus.length > 0){
					int iSubstatus = status.substatus.length;
					for(int i = 0; i < iSubstatus; i++){
						Element eSubstatus =  m_document.createElement("substatus");
						if(status.substatus[i].name != null && status.substatus[i].name.length() > 0){
							eSubstatus.setAttribute("name", status.substatus[i].name);
						}						
						if(status.substatus[i].description != null && status.substatus[i].description.length() > 0){
							eSubstatus.setAttribute("description", status.substatus[i].description);
						}						
						if(status.substatus[i].value != null && status.substatus[i].value.length() > 0){
							eSubstatus.appendChild(m_document.createTextNode(status.substatus[i].value));
						}
						eStatus.appendChild(eSubstatus);
					}					
				}
				m_eResultHeader.insertBefore(eStatus, m_eResultHeader.getFirstChild());
			}
			else{
				XMLUtil.removeChildrenByName(m_eResultHeader, "generalStatus");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setGeneralStatus
	
   	/**
	 * Set the general status type, which can be: 
	 * success, error, warning. 
	 * 
	 * @param type holds the general status type
	 * @return whether the general status type is set successfully or not. 
	 */
	public boolean setGeneralStatusType(String type){
		try{
			if(type != null && type.length() > 0){
				if(!type.equals("success") && !type.equals("warning") && !type.equals("error")) return false;
				Element eStatus = (Element)XMLUtil.findChildNode(m_eResultHeader, "generalStatus");
				if(eStatus == null){
					eStatus = m_document.createElement("generalStatus");
					m_eResultHeader.insertBefore(eStatus, m_eResultHeader.getFirstChild());
				}
				eStatus.setAttribute("type", type);					
			}
			else{
				XMLUtil.removeChildrenByName(m_eResultHeader, "generalStatus");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setGeneralStatusType

   	/**
	 * Set the general status description. 
	 * 
	 * @param description holds the general status description.
	 * @return whether the general status description is set successfully or not. 
	 */
	public boolean setGeneralStatusDescription(String description){
		try{
			Element eStatus = (Element)XMLUtil.findChildNode(m_eResultHeader, "generalStatus");
			if(eStatus == null){
					eStatus = m_document.createElement("generalStatus");
					m_eResultHeader.insertBefore(eStatus, m_eResultHeader.getFirstChild());
				}
			if(description != null && description.length() > 0){
				eStatus.setAttribute("description", description);					
			}
			else{
				eStatus.removeAttribute("description");				
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setGeneralStatusDescription
	
   	/**
	 * Set service uri.
	 * 
	 * @param serviceURI holds the uri of the service. 
	 * @return whether the service uri is set successfully. 
	 */
	public boolean setServiceURI(String serviceURI){
		try{
			Node nodeRef = null;
			if(serviceURI != null && serviceURI.length() > 0){
				Element eServiceURI = (Element)XMLUtil.findChildNode(m_eResultHeader, "serviceURI");
				if(eServiceURI == null){
					eServiceURI = m_document.createElement("serviceURI");					
					eServiceURI.appendChild(m_document.createTextNode(serviceURI));
					nodeRef = XMLUtil.findChildNode(m_eResultHeader, "serviceName");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(m_eResultHeader, "instanceName");
						if(nodeRef == null){
							nodeRef = XMLUtil.findChildNode(m_eResultHeader, "jobID");
							if(nodeRef == null){
								nodeRef = XMLUtil.findChildNode(m_eResultHeader, "time");
								if(nodeRef == null){
									nodeRef = XMLUtil.findChildNode(m_eResultHeader, "message");
								}
							}
						}
					}
					m_eResultHeader.insertBefore(eServiceURI, nodeRef);
				}
				else{
					XMLUtil.setElementValue(eServiceURI, serviceURI);
				}
			}
			else{
				XMLUtil.removeChildrenByName(m_eResultHeader, "serviceURI");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setServiceURI
	
  	/**
	 * Set service name.
	 * 
	 * @param serviceName holds the name of the service. 
	 * @return whether the service name is set successfully. 
	 */
	public boolean setServiceName(String serviceName){
		try{
			Node nodeRef = null;
			if(serviceName != null && serviceName.length() > 0){
				Element eServiceName = (Element)XMLUtil.findChildNode(m_eResultHeader, "serviceName");
				if(eServiceName == null){
					eServiceName = m_document.createElement("serviceName");					
					eServiceName.appendChild(m_document.createTextNode(serviceName));
					nodeRef = XMLUtil.findChildNode(m_eResultHeader, "instanceName");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(m_eResultHeader, "jobID");
						if(nodeRef == null){
							nodeRef = XMLUtil.findChildNode(m_eResultHeader, "time");
							if(nodeRef == null){
								nodeRef = XMLUtil.findChildNode(m_eResultHeader, "message");
							}
						}
					}
					m_eResultHeader.insertBefore(eServiceName, nodeRef);
				}
				else{
					XMLUtil.setElementValue(eServiceName, serviceName);
				}
			}
			else{
				XMLUtil.removeChildrenByName(m_eResultHeader, "serviceName");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setServiceName
	
   	/**
	 * Set instance name.
	 * 
	 * @param instanceName holds the name of the instance. 
	 * @return whether the instance name is set successfully. 
	 */
	public boolean setInstanceName(String instanceName){
		try{
			Node nodeRef = null;
			if(instanceName != null && instanceName.length() > 0){
				Element eInstanceName = (Element)XMLUtil.findChildNode(m_eResultHeader, "instanceName");
				if(eInstanceName == null){
					eInstanceName = m_document.createElement("instanceName");					
					eInstanceName.appendChild(m_document.createTextNode(instanceName));
					nodeRef = XMLUtil.findChildNode(m_eResultHeader, "jobID");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(m_eResultHeader, "time");
						if(nodeRef == null){
							nodeRef = XMLUtil.findChildNode(m_eResultHeader, "message");
						}
					}
					m_eResultHeader.insertBefore(eInstanceName, nodeRef);
				}
				else{
					XMLUtil.setElementValue(eInstanceName, instanceName);
				}
			}
			else{
				XMLUtil.removeChildrenByName(m_eResultHeader, "instanceName");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setInstanceName
	
   	/**
	 * Set job id.
	 * 
	 * @param jobID holds the job id. 
	 * @return whether the job id is set successfully. 
	 */
	public boolean setJobID(String jobID){
		try{
			Node nodeRef = null;
			if(jobID != null && jobID.length() > 0){
				Element eJobID = (Element)XMLUtil.findChildNode(m_eResultHeader, "jobID");
				if(eJobID == null){
					eJobID = m_document.createElement("jobID");					
					eJobID.appendChild(m_document.createTextNode(jobID));
					nodeRef = XMLUtil.findChildNode(m_eResultHeader, "time");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(m_eResultHeader, "message");
					}
					m_eResultHeader.insertBefore(eJobID, nodeRef);
				}
				else{
					XMLUtil.setElementValue(eJobID, jobID);
				}
			}
			else{
				XMLUtil.removeChildrenByName(m_eResultHeader, "jobID");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setJobID
	
   	/**
	 * Set time of the result.
	 * 
	 * @param time holds the time of the result.
	 * @return whether result time is set successfully. 
	 */
	public boolean setResultTime(GregorianCalendar time){
		try{
			Node nodeRef = null;
			if(time != null && time.get(GregorianCalendar.YEAR) > 1970){
				Element eTime = (Element)XMLUtil.findChildNode(m_eResultHeader, "time");
				if(eTime == null){
					eTime = m_document.createElement("time");					
					eTime.appendChild(m_document.createTextNode(XMLUtil.createXSDateTime(time)));
					nodeRef = XMLUtil.findChildNode(m_eResultHeader, "message");
					m_eResultHeader.insertBefore(eTime, nodeRef);
				}
				else{
					XMLUtil.setElementValue(eTime, XMLUtil.createXSDateTime(time));
				}
			}
			else{
				XMLUtil.removeChildrenByName(m_eResultHeader, "time");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setResultTime
	
   	/**
	 * Set the general message. 
	 * 
	 * @param message holds the general message. 
	 * @return whether process message is set successfully. 
	 */
	public boolean setGeneralMessage(String message){
		try{
			Node nodeRef = null;
			if(message != null && message.length() > 0){
				Element eMessage = (Element)XMLUtil.findChildNode(m_eResultHeader, "message");
				if(eMessage == null){
					eMessage = m_document.createElement("message");					
					eMessage.appendChild(m_document.createTextNode(message));
					m_eResultHeader.insertBefore(eMessage, nodeRef);
				}
				else{
					XMLUtil.setElementValue(eMessage, message);
				}
			}
			else{
				XMLUtil.removeChildrenByName(m_eResultHeader, "message");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setGeneralMessage

	
	/**
	 * Set the process statistics. 
	 * 
	 * @param processStatistics holds the process statistics. 
	 * @return whether the process statistics is set successfully. 
	 */
	public boolean setProcessStatistics(ProcessStatistics processStatistics){
		if(processStatistics == null){
			XMLUtil.removeChildrenByName(m_eResultData, "statistics");
			return true;
		}
		Element eStatistics = (Element)XMLUtil.findChildNode(m_eResultData, "statistics");
		if(eStatistics != null){
			XMLUtil.removeChildrenByName(m_eResultData, "statistics");
		}
		eStatistics = m_document.createElement("statistics");
		m_eResultData.insertBefore(eStatistics, m_eResultData.getFirstChild());
		if(processStatistics.currentState != null && processStatistics.currentState.length() > 0){
			Element eCurrentState = m_document.createElement("currentState");
			eCurrentState.appendChild(m_document.createTextNode(processStatistics.currentState));	
			eStatistics.appendChild(eCurrentState);
		}
		if(processStatistics.availableDiskSpace > 0){
			Element eAvailableDiskSpace = m_document.createElement("availableDiskSpace");
			if(Double.isInfinite(processStatistics.availableDiskSpace)){
				eAvailableDiskSpace.appendChild(m_document.createTextNode("INF"));	
			}
			else{
				eAvailableDiskSpace.appendChild(m_document.createTextNode(processStatistics.availableDiskSpace + ""));	
			}
			eStatistics.appendChild(eAvailableDiskSpace);
		}
		if(processStatistics.availableMemory > 0){
			Element eAvailableMemory = m_document.createElement("availableMemory");
			if(Double.isInfinite(processStatistics.availableMemory)){
				eAvailableMemory.appendChild(m_document.createTextNode("INF"));	
			}
			else{
				eAvailableMemory.appendChild(m_document.createTextNode(processStatistics.availableMemory + ""));	
			}
			eStatistics.appendChild(eAvailableMemory);
		}
		if(processStatistics.currentJobCount >= 0){
			Element eCurrentJobCount = m_document.createElement("currentJobCount");
			eCurrentJobCount.appendChild(m_document.createTextNode(processStatistics.currentJobCount + ""));	
			eStatistics.appendChild(eCurrentJobCount);
		}
		if(processStatistics.totalJobsSoFar >= 0){
			Element eTotalJobsSoFar = m_document.createElement("totalJobsSoFar");
			eTotalJobsSoFar.appendChild(m_document.createTextNode(processStatistics.totalJobsSoFar + ""));	
			eStatistics.appendChild(eTotalJobsSoFar);
		}
		if(processStatistics.timeLastJobEnded !=  null){
			Element eTimeLastJobEnded = m_document.createElement("timeLastJobEnded");
			eTimeLastJobEnded.appendChild(m_document.createTextNode(XMLUtil.createXSDateTime(processStatistics.timeLastJobEnded)));	
			eStatistics.appendChild(eTimeLastJobEnded);
		}
		if(processStatistics.timeLastJobTook >= 0){
			Element eTimeLastJobTook = m_document.createElement("timeLastJobTook");
			if(Double.isInfinite(processStatistics.timeLastJobTook)){
				eTimeLastJobTook.appendChild(m_document.createTextNode("INF"));	
			}
			else{
				eTimeLastJobTook.appendChild(m_document.createTextNode(processStatistics.timeLastJobTook + ""));	
			}
			eStatistics.appendChild(eTimeLastJobTook);
		}
		if(processStatistics.timeServiceStarted !=  null){
			Element eTimeServiceStarted = m_document.createElement("timeServiceStarted");
			eTimeServiceStarted.appendChild(m_document.createTextNode(XMLUtil.createXSDateTime(processStatistics.timeServiceStarted)));	
			eStatistics.appendChild(eTimeServiceStarted);
		}
		
		if(processStatistics.jobs != null && processStatistics.jobs.job != null && processStatistics.jobs.job.length > 0){
			Element eJobs = m_document.createElement("jobs");
			int iJobs = processStatistics.jobs.job.length;
			for(int i = 0; i < iJobs; i++){
				if(processStatistics.jobs.job[i] != null){
					Element eJob = m_document.createElement("job");
					JobStatistics job = processStatistics.jobs.job[i];
					if(job.jobID != null && job.jobID.length() > 0){
						eJob.setAttribute("jobID", job.jobID);
					}
					else{
						return false;
					}
					if(job.state != null && job.state.length() > 0 && !job.state.equals("unknown")){
						Element eState = m_document.createElement("state");
						eState.appendChild(m_document.createTextNode(job.state));	
						eJob.appendChild(eState);
					}
					if(job.startTime != null && job.startTime.get(GregorianCalendar.YEAR) > 1970){
						Element eStartTime = m_document.createElement("startTime");
						eStartTime.appendChild(m_document.createTextNode(XMLUtil.createXSDateTime(job.startTime)));	
						eJob.appendChild(eStartTime);
					}
					if(job.endTime != null && job.endTime.get(GregorianCalendar.YEAR) > 1970){
						Element eEndTime = m_document.createElement("endTime");
						eEndTime.appendChild(m_document.createTextNode(XMLUtil.createXSDateTime(job.endTime)));	
						eJob.appendChild(eEndTime);
					}
					if(job.duration >= 0){
						Element eDuration = m_document.createElement("duration");
						if(Double.isInfinite(job.duration)){
							eDuration.appendChild(m_document.createTextNode("INF"));	
						}
						else{
							eDuration.appendChild(m_document.createTextNode(job.duration + ""));	
						}
						eJob.appendChild(eDuration);
					}
					if(job.scheduledStartTime != null && job.scheduledStartTime.get(GregorianCalendar.YEAR) > 1970){
						Element eScheduledStartTime = m_document.createElement("scheduledStartTime");
						eScheduledStartTime.appendChild(m_document.createTextNode(XMLUtil.createXSDateTime(job.scheduledStartTime)));	
						eJob.appendChild(eScheduledStartTime);
					}
					if(job.dependencies != null && job.dependencies.jobID != null && job.dependencies.jobID.length > 0){
						Element eDependencies = m_document.createElement("dependencies");
						int iJobIDs = processStatistics.jobs.job[i].dependencies.jobID.length;
						for(int j = 0; j < iJobIDs; j++){
							Element eJobID = m_document.createElement("jobID");
							eJobID.appendChild(m_document.createTextNode(job.dependencies.jobID[j]));	
							eDependencies.appendChild(eJobID);
						}						
						eJob.appendChild(eDependencies);
					}
					eJobs.appendChild(eJob);
				}
			}
			eStatistics.appendChild(eJobs);
		}
		return true;
	}//setprocessStatistics
		
	/**
	 * Set the current state. 
	 * @param currentState holds the current state, which can be:
	 * "busy", "busyButAccepting", "idle", "idleButNotAccepting" or "noResponse".
	 * @return whether the current state is set successfully.
	 */
	public boolean setCurrentState(String currentState){
		Element eStatistics = (Element)XMLUtil.findChildNode(m_eResultData, "statistics");
		if(eStatistics == null){
			eStatistics = m_document.createElement("statistics");
			m_eResultData.insertBefore(eStatistics, m_eResultData.getFirstChild());
		}
		if(currentState != null && currentState.length() > 0){
			if(!currentState.equals("busy") && 
			   !currentState.equals("busyButAccepting") &&
			   !currentState.equals("idle") &&
			   !currentState.equals("idleButNotAccepting") &&
			   !currentState.equals("noResponse")) return false;		 
			Element eCurrentState = (Element)XMLUtil.findChildNode(eStatistics, "currentState");
			if(eCurrentState == null){
				eCurrentState = m_document.createElement("currentState");					
				eCurrentState.appendChild(m_document.createTextNode(currentState));					
				eStatistics.appendChild(eCurrentState);
			}
			else{
				XMLUtil.setElementValue(eCurrentState, currentState);
			}
		}
		else{
			XMLUtil.removeChildrenByName(eStatistics, "currentState");
		}
		return true;
	}//setCurrentState
	

	/**
	 * Set the available disk space. 
	 * @param availableDiskSpace holds the available disk space (in bytes). 
	 * @return whether the available disk space is set successfully.
	 */
	public boolean setAvailableDiskSpace(double availableDiskSpace){
		Element eStatistics = (Element)XMLUtil.findChildNode(m_eResultData, "statistics");
		if(eStatistics == null){
			eStatistics = m_document.createElement("statistics");
			m_eResultData.insertBefore(eStatistics, m_eResultData.getFirstChild());
		}
		if(!Double.isNaN(availableDiskSpace) && availableDiskSpace >= 0){
			Element eAvailableDiskSpace = (Element)XMLUtil.findChildNode(eStatistics, "availableDiskSpace");
			if(eAvailableDiskSpace == null){
				eAvailableDiskSpace = m_document.createElement("availableDiskSpace");			
				if(Double.isInfinite(availableDiskSpace)){
					eAvailableDiskSpace.appendChild(m_document.createTextNode("INF"));
				}
				else{
					eAvailableDiskSpace.appendChild(m_document.createTextNode(availableDiskSpace + ""));
				}
				eStatistics.appendChild(eAvailableDiskSpace);
			}
			else{
				XMLUtil.setElementValue(eAvailableDiskSpace, Double.isInfinite(availableDiskSpace)?"INF":(availableDiskSpace+""));
			}
		}
		else{
			XMLUtil.removeChildrenByName(eStatistics, "availableDiskSpace");
		}
		return true;
	}//setAvailableDiskSpace
	
	/**
	 * Set the available memory (in bytes). 
	 * @param availableMemory holds the available memory. 
	 * @return whether the available memory is set successfully.
	 */
	public boolean setAvailableMemory(double availableMemory){
		Element eStatistics = (Element)XMLUtil.findChildNode(m_eResultData, "statistics");
		if(eStatistics == null){
			eStatistics = m_document.createElement("statistics");
			m_eResultData.insertBefore(eStatistics, m_eResultData.getFirstChild());
		}
		if(!Double.isNaN(availableMemory) && availableMemory >= 0){
			Element eAvailableMemory = (Element)XMLUtil.findChildNode(eStatistics, "availableMemory");
			if(eAvailableMemory == null){
				eAvailableMemory = m_document.createElement("availableMemory");			
				if(Double.isInfinite(availableMemory)){
					eAvailableMemory.appendChild(m_document.createTextNode("INF"));
				}
				else{
					eAvailableMemory.appendChild(m_document.createTextNode(availableMemory + ""));
				}
				eStatistics.appendChild(eAvailableMemory);
			}
			else{
				XMLUtil.setElementValue(eAvailableMemory, Double.isInfinite(availableMemory)?"INF":(availableMemory+""));
			}
		}
		else{
			XMLUtil.removeChildrenByName(eStatistics, "availableMemory");
		}
		return true;
	}//setAvailableMemory
	
	
	/**
	 * Set the current job count. 
	 * @param currentJobCount holds the current job count. 
	 * @return whether the current job count is set successfully.
	 */
	public boolean setCurrentJobCount(int currentJobCount){
		Element eStatistics = (Element)XMLUtil.findChildNode(m_eResultData, "statistics");
		if(eStatistics == null){
			eStatistics = m_document.createElement("statistics");
			m_eResultData.insertBefore(eStatistics, m_eResultData.getFirstChild());
		}
		if(currentJobCount >= 0){
			Element eCurrentJobCount = (Element)XMLUtil.findChildNode(eStatistics, "currentJobCount");
			if(eCurrentJobCount == null){
				eCurrentJobCount = m_document.createElement("currentJobCount");			
				eCurrentJobCount.appendChild(m_document.createTextNode(currentJobCount + ""));
				eStatistics.appendChild(eCurrentJobCount);
			}
			else{
				XMLUtil.setElementValue(eCurrentJobCount, currentJobCount+"");
			}
		}
		else{
			XMLUtil.removeChildrenByName(eStatistics, "currentJobCount");
		}
		return true;
	}//setCurrentJobCount
	
	/**
	 * Set the total jobs received so far. 
	 * @param totalJobsSoFar holds the total jobs received so far. 
	 * @return whether the total jobs so far is set successfully.
	 */
	public boolean setTotalJobsSoFar(int totalJobsSoFar){
		Element eStatistics = (Element)XMLUtil.findChildNode(m_eResultData, "statistics");
		if(eStatistics == null){
			eStatistics = m_document.createElement("statistics");
			m_eResultData.insertBefore(eStatistics, m_eResultData.getFirstChild());
		}
		if(totalJobsSoFar >= 0){
			Element eTotalJobsSoFar = (Element)XMLUtil.findChildNode(eStatistics, "totalJobsSoFar");
			if(eTotalJobsSoFar == null){
				eTotalJobsSoFar = m_document.createElement("totalJobsSoFar");			
				eTotalJobsSoFar.appendChild(m_document.createTextNode(totalJobsSoFar + ""));
				eStatistics.appendChild(eTotalJobsSoFar);
			}
			else{
				XMLUtil.setElementValue(eTotalJobsSoFar, totalJobsSoFar+"");
			}
		}
		else{
			XMLUtil.removeChildrenByName(eStatistics, "totalJobsSoFar");
		}
		return true;
	}//setTotalJobsSoFar
	
	/**
	 * Set the time last job ended. 
	 * @param timeLastJobEnded holds the time last job ended. 
	 * @return whether the time last job ended is set successfully.
	 */
	public boolean setTimeLastJobEnded(GregorianCalendar timeLastJobEnded){
		Element eStatistics = (Element)XMLUtil.findChildNode(m_eResultData, "statistics");
		if(eStatistics == null){
			eStatistics = m_document.createElement("statistics");
			m_eResultData.insertBefore(eStatistics, m_eResultData.getFirstChild());
		}
		if(timeLastJobEnded != null){
			Element eTimeLastJobEnded = (Element)XMLUtil.findChildNode(eStatistics, "timeLastJobEnded");
			if(eTimeLastJobEnded == null){
				eTimeLastJobEnded = m_document.createElement("timeLastJobEnded");			
				eTimeLastJobEnded.appendChild(m_document.createTextNode(XMLUtil.createXSDateTime(timeLastJobEnded)));
				eStatistics.appendChild(eTimeLastJobEnded);
			}
			else{
				XMLUtil.setElementValue(eTimeLastJobEnded, XMLUtil.createXSDateTime(timeLastJobEnded));
			}
		}
		else{
			XMLUtil.removeChildrenByName(eStatistics, "timeLastJobEnded");
		}
		return true;
	}//setTimeLastJobEnded
	
	/**
	 * Set the time last job took. 
	 * @param timeLastJobTook holds the time last job took (in seconds). 
	 * @return whether the time last job took is set successfully.
	 */
	public boolean setTimeLastJobTook(double timeLastJobTook){
		Element eStatistics = (Element)XMLUtil.findChildNode(m_eResultData, "statistics");
		if(eStatistics == null){
			eStatistics = m_document.createElement("statistics");
			m_eResultData.insertBefore(eStatistics, m_eResultData.getFirstChild());
		}
		if(!Double.isNaN(timeLastJobTook) && timeLastJobTook >= 0){
			Element eTimeLastJobTook = (Element)XMLUtil.findChildNode(eStatistics, "timeLastJobTook");
			if(eTimeLastJobTook == null){
				eTimeLastJobTook = m_document.createElement("timeLastJobTook");			
				if(Double.isInfinite(timeLastJobTook)){
					eTimeLastJobTook.appendChild(m_document.createTextNode("INF"));
				}
				else{
					eTimeLastJobTook.appendChild(m_document.createTextNode(timeLastJobTook + ""));
				}
				eStatistics.appendChild(eTimeLastJobTook);
			}
			else{
				XMLUtil.setElementValue(eTimeLastJobTook, Double.isInfinite(timeLastJobTook)?"INF":(timeLastJobTook+""));
			}
		}
		else{
			XMLUtil.removeChildrenByName(eStatistics, "timeLastJobTook");
		}
		return true;
	}//setTimeLastJobTook
	
	/**
	 * Set the time the service started. 
	 * @param timeServiceStarted holds the time the service started. 
	 * @return whether the time the service started is set successfully.
	 */
	public boolean setTimeServiceStarted(GregorianCalendar timeServiceStarted){
		Element eStatistics = (Element)XMLUtil.findChildNode(m_eResultData, "statistics");
		if(eStatistics == null){
			eStatistics = m_document.createElement("statistics");
			m_eResultData.insertBefore(eStatistics, m_eResultData.getFirstChild());
		}
		if(timeServiceStarted != null){
			Element eTimeServiceStarted = (Element)XMLUtil.findChildNode(eStatistics, "timeServiceStarted");
			if(eTimeServiceStarted == null){
				eTimeServiceStarted = m_document.createElement("timeServiceStarted");			
				eTimeServiceStarted.appendChild(m_document.createTextNode(XMLUtil.createXSDateTime(timeServiceStarted)));
				eStatistics.appendChild(eTimeServiceStarted);
			}
			else{
				XMLUtil.setElementValue(eTimeServiceStarted, XMLUtil.createXSDateTime(timeServiceStarted));
			}
		}
		else{
			XMLUtil.removeChildrenByName(eStatistics, "timeServiceStarted");
		}
		return true;
	}//setTimeServiceStarted
	
	/**
	 * Set the service utilization. 
	 * @param serviceUtilization holds the service utilization ([0, 1]). 
	 * @return whether the time last job took is set successfully.
	 */
	public boolean setServiceUtilization(double serviceUtilization){
		Element eStatistics = (Element)XMLUtil.findChildNode(m_eResultData, "statistics");
		if(eStatistics == null){
			eStatistics = m_document.createElement("statistics");
			m_eResultData.insertBefore(eStatistics, m_eResultData.getFirstChild());
		}
		if(!Double.isNaN(serviceUtilization) && serviceUtilization >= 0){
			Element eServiceUtilization = (Element)XMLUtil.findChildNode(eStatistics, "serviceUtilization");
			if(eServiceUtilization == null){
				eServiceUtilization = m_document.createElement("serviceUtilization");			
				eServiceUtilization.appendChild(m_document.createTextNode(serviceUtilization + ""));
				eStatistics.appendChild(eServiceUtilization);
			}
			else{
				XMLUtil.setElementValue(eServiceUtilization, serviceUtilization+"");
			}
		}
		else{
			XMLUtil.removeChildrenByName(eStatistics, "serviceUtilization");
		}
		return true;
	}//setServiceUtilization
	
	/**
	 * Set the statistics of all jobs. 
	 * 
	 * @param jobStatistics holds an array of jobStatistics with 
	 * each member corresponding to one job. 
	 * @return whether the job statistics are set successfully. 
	 */
	public boolean setJobStatistics(JobStatistics[] jobStatistics){
		Element eStatistics = (Element)XMLUtil.findChildNode(m_eResultData, "statistics");
		if(eStatistics == null){
			eStatistics = m_document.createElement("statistics");
			m_eResultData.insertBefore(eStatistics, m_eResultData.getFirstChild());
		}
		if(jobStatistics != null && jobStatistics.length > 0){
			Element eJobs = (Element)XMLUtil.findChildNode(eStatistics, "jobs");
			if(eJobs == null){
				XMLUtil.removeChildrenByName(eStatistics, "jobs");
			}
			eJobs = m_document.createElement("jobs");
			eStatistics.appendChild(eJobs);
			int iJobs = jobStatistics.length;
			for(int i = 0; i < iJobs; i++){
				if(jobStatistics[i] != null){
					Element eJob = m_document.createElement("job");
					if(jobStatistics[i].jobID != null && jobStatistics[i].jobID.length() > 0){
						eJob.setAttribute("jobID", jobStatistics[i].jobID);
					}
					else{
						return false;
					}					
					if(jobStatistics[i].state != null && jobStatistics[i].state.length() > 0 && !jobStatistics[i].state.equals("unknown")){
						Element eState = m_document.createElement("state");
						eState.appendChild(m_document.createTextNode(jobStatistics[i].state));	
						eJob.appendChild(eState);
					}
					if(jobStatistics[i].startTime != null && jobStatistics[i].startTime.get(GregorianCalendar.YEAR) > 1970){
						Element eStartTime = m_document.createElement("startTime");
						eStartTime.appendChild(m_document.createTextNode(XMLUtil.createXSDateTime(jobStatistics[i].startTime)));	
						eJob.appendChild(eStartTime);
					}
					if(jobStatistics[i].endTime != null && jobStatistics[i].endTime.get(GregorianCalendar.YEAR) > 1970){
						Element eEndTime = m_document.createElement("endTime");
						eEndTime.appendChild(m_document.createTextNode(XMLUtil.createXSDateTime(jobStatistics[i].endTime)));	
						eJob.appendChild(eEndTime);
					}
					if(jobStatistics[i].duration >= 0){
						Element eDuration = m_document.createElement("duration");
						if(Double.isInfinite(jobStatistics[i].duration)){
							eDuration.appendChild(m_document.createTextNode("INF"));	
						}
						else{
							eDuration.appendChild(m_document.createTextNode(jobStatistics[i].duration + ""));	
						}
						eJob.appendChild(eDuration);
					}
					if(jobStatistics[i].scheduledStartTime != null && jobStatistics[i].scheduledStartTime.get(GregorianCalendar.YEAR) > 1970){
						Element eScheduledStartTime = m_document.createElement("scheduledStartTime");
						eScheduledStartTime.appendChild(m_document.createTextNode(XMLUtil.createXSDateTime(jobStatistics[i].scheduledStartTime)));	
						eJob.appendChild(eScheduledStartTime);
					}
					if(jobStatistics[i].dependencies != null && jobStatistics[i].dependencies.jobID != null && jobStatistics[i].dependencies.jobID.length > 0){
						Element eDependencies = m_document.createElement("dependencies");
						int iJobIDs = jobStatistics[i].dependencies.jobID.length;
						for(int j = 0; j < iJobIDs; j++){
							Element eJobID = m_document.createElement("jobID");
							eJobID.appendChild(m_document.createTextNode(jobStatistics[i].dependencies.jobID[j]));	
							eDependencies.appendChild(eJobID);
						}						
						eJob.appendChild(eDependencies);
					}
					eJobs.appendChild(eJob);
				}
			}
		}
		else{
			XMLUtil.removeChildrenByName(eStatistics, "jobs");
		}
		return true;
	}//setJobStatistics
	
	/**
	 * Set all the otherResult related elements. 
	 * 
	 * @param names holds the names of all the other result information. It is required.
	 * @param values holds the values of all the other result information, empty String "" if no value for one otherResult element.
	 * @param descriptions holds the descriptions of all the other result information, empty String "" if no value for one otherResult, null for
	 * the entire array if none of the otherResult elements have descriptions.
	 * @return whether the otherResult elements are set successfully.
	 */
	public boolean setOtherResults(String[] names, String[] values, String[] descriptions){
		if(names == null) return false;
		if(values == null) return false;
		if(names.length != values.length) return false;
		if(descriptions != null && names.length != descriptions.length) return false;
		for(int i = 0; i < names.length; i++){
			addOtherResult(names[i], values[i], (descriptions==null)?"":descriptions[i]);
		}
		return true;
	}//setOtherResults
	
	/**
	 * Add an otherResult element. 
	 * 
	 * @param name holds the name of the otherResult element. It is required.
	 * @param value holds the value of the otherResult element, empty String "" if none. 
	 * @param description  holds the description of the otherResult element, empty String "" if none.
	 * @return whether the otherResult element is added successfully.
	 */
	public boolean addOtherResult(String name, String value, String description){
		if(name == null) return false;
		Vector<Element> vElements = XMLUtil.getChildElementsByTagName(m_eResultData, "other");
		Element eOtherResult;
		int iNls = vElements==null?0:vElements.size();
		for(int i = 0; i < iNls; i++){
			eOtherResult = (Element)vElements.elementAt(i);
			if(eOtherResult.getAttribute("name").equals(name)){
				m_eResultData.removeChild(eOtherResult);
				break;
			}
		}
		eOtherResult = createOther(name, value, description);
		m_eResultData.appendChild(eOtherResult);
		return true;
	}//addOtherResult
	
	/**
	 * Set the variable number. 
	 * 
	 * @param variableNumber holds the number of variables
	 * @return whether the variable number is set successfully or not. 
	 */
	public boolean setVariableNumber(int variableNumber){
		Node nodeRef = null;		
		if(variableNumber <= 0){
			return false;
		}
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eResultData, "optimization");
		if(eOptimization == null){
			eOptimization = m_document.createElement("optimization");
			nodeRef = XMLUtil.findChildNode(m_eResultData, "statistics");			
			if(nodeRef != null){
				m_eResultData.insertBefore(eOptimization, nodeRef.getNextSibling());			
			}
			else{
				m_eResultData.insertBefore(eOptimization, m_eResultData.getFirstChild());
			}					
		}		
		m_iVariableNumber = variableNumber;
		try{
			eOptimization.setAttribute("numberOfVariables", variableNumber+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;	
	}//setVariableNumber

	/**
	 * Set the objective number. 
	 * 
	 * @param objectiveNumber holds the number of objectives
	 * @return whether the objective number is set successfully or not. 
	 */
	public boolean setObjectiveNumber(int objectiveNumber){
		Node nodeRef = null;		
		if(objectiveNumber < 0){
			return false;
		}
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eResultData, "optimization");
		if(eOptimization == null){
			eOptimization = m_document.createElement("optimization");
			nodeRef = XMLUtil.findChildNode(m_eResultData, "statistics");			
			if(nodeRef != null){
				m_eResultData.insertBefore(eOptimization, nodeRef.getNextSibling());			
			}
			else{
				m_eResultData.insertBefore(eOptimization, m_eResultData.getFirstChild());
			}					
		}		
		m_iObjectiveNumber = objectiveNumber;
		try{
			eOptimization.setAttribute("numberOfObjectives", objectiveNumber+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;	
	}//setObjectiveNumber

	/**
	 * Set the constraint number. 
	 * 
	 * @param constraintNumber holds the number of constraints
	 * @return whether the constraint number is set successfully or not. 
	 */
	public boolean setConstraintNumber(int constraintNumber){
		Node nodeRef = null;		
		if(constraintNumber < 0){
			return false;
		}
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eResultData, "optimization");
		if(eOptimization == null){
			eOptimization = m_document.createElement("optimization");
			nodeRef = XMLUtil.findChildNode(m_eResultData, "statistics");			
			if(nodeRef != null){
				m_eResultData.insertBefore(eOptimization, nodeRef.getNextSibling());			
			}
			else{
				m_eResultData.insertBefore(eOptimization, m_eResultData.getFirstChild());
			}					
		}		
		m_iConstraintNumber = constraintNumber;
		try{
			eOptimization.setAttribute("numberOfConstraints", constraintNumber+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setConstraintNumber

	
	/**
	 * set the number of solutions. This method must be called before setting other optimization solution 
	 * related results.  
	 * Before this method is called, the setVariableNumber(int), setObjectiveNumber(int), setConstraintNumber(int) methods 
	 * have to be called first. 
	 * 
	 * @param solutionNumber holds the number of solutions to set. 
	 * @return whether the solution number is set successfully.   
	 * @see #setVariableNumber(int)
	 * @see #setObjectiveNumber(int)
	 * @see #setConstraintNumber(int)
	 */
	public boolean setSolutionNumber(int solutionNumber){
		Node nodeRef = null;		
		if(solutionNumber < 0){
			return false;
		}
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eResultData, "optimization");
		if(eOptimization == null){
			eOptimization = m_document.createElement("optimization");
			nodeRef = XMLUtil.findChildNode(m_eResultData, "statistics");			
			if(nodeRef != null){
				m_eResultData.insertBefore(eOptimization, nodeRef.getNextSibling());			
			}
			else{
				m_eResultData.insertBefore(eOptimization, m_eResultData.getFirstChild());
			}					
		}		
		m_iSolutionNumber = solutionNumber;
		try{
			eOptimization.setAttribute("numberOfSolutions", solutionNumber+"");
			for(int i = 0; i < solutionNumber; i++){
				Element eSolution = m_document.createElement("solution");
				Element eStatus = m_document.createElement("status");
				eStatus.setAttribute("type", "other");
				eSolution.appendChild(eStatus);
				eOptimization.insertBefore(eSolution, eOptimization.getFirstChild());
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setSolutionNumber
	
	/**
	 * Set the [i]th optimization solution, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the solution. 
	 * @param solution holds the optimization solution to set. 
	 * 
	 * @return whether the optimization solution is set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolution
	 * @see #setSolutionNumber(int)
	 */
	public boolean setSolution(int solIdx, OptimizationSolution solution){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		boolean bSetSolution = true;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eResultData, "optimization");
		if(eOptimization == null) return false;
		Vector<Element> vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
		if(solIdx >= vSolutions.size()) return false;
		Element eSolution = (Element)vSolutions.elementAt(solIdx);
		eSolution = m_document.createElement("solution");
		Element eStatus = m_document.createElement("status");
		eStatus.setAttribute("type", "other");
		eSolution.appendChild(eStatus);

		bSetSolution = setSolutionObjectiveIndex(solIdx, solution.objectiveIdx);
		if(!bSetSolution) return false;
		bSetSolution = setSolutionStatus(solIdx, solution.status);
		if(!bSetSolution) return false;
		bSetSolution = setSolutionMessage(solIdx, solution.message);
		if(!bSetSolution) return false;

		if(solution.variables != null){
			if(solution.variables.values != null){
				double[] mdValues = new double[m_iVariableNumber];
				VarValue[] var = solution.variables.values.var;
				int iVars = var==null?0:var.length;
				for(int i = 0; i < iVars; i++){
					mdValues[var[i].idx] = var[i].value;
				}
				bSetSolution = setPrimalVariableValues(solIdx, mdValues);
				if(!bSetSolution) return false;	
			}		
			if(solution.variables.valuesString != null){
				String[] msValues = new String[m_iVariableNumber];
				VarStringValue[] var = solution.variables.valuesString.var;
				int iVars = var==null?0:var.length;
				for(int i = 0; i < iVars; i++){
					msValues[var[i].idx] = var[i].value;
				}
				bSetSolution = setPrimalVariableStringValues(solIdx, msValues);
				if(!bSetSolution) return false;	
			}		
			if(solution.variables.primalUnboundedDirections != null){
				double[] mdValues = new double[m_iVariableNumber];
				PrimalVarUnboundedDirection[] var = solution.variables.primalUnboundedDirections.var;
				int iVars = var==null?0:var.length;
				for(int i = 0; i < iVars; i++){
					mdValues[var[i].idx] = var[i].value;
				}
				bSetSolution = setPrimalUnboundedDirections(solIdx, mdValues);
				if(!bSetSolution) return false;	
			}		
			if(solution.variables.irreducibleInconsistentSystem != null){
				bSetSolution = setVariableIrreducibleInconsistentSystem(solIdx, solution.variables.irreducibleInconsistentSystem);
				if(!bSetSolution) return false;	
			}		
			if(solution.variables.reducedCosts != null){
				bSetSolution = setReducedCosts(solIdx, solution.variables.reducedCosts);
				if(!bSetSolution) return false;	
			}		
			if(solution.variables.slacks != null){
				bSetSolution = setVariableSlacks(solIdx, solution.variables.slacks);
				if(!bSetSolution) return false;	
			}		
			if(solution.variables.allowableIncreases!= null){
				bSetSolution = setVariableAllowableIncreases(solIdx, solution.variables.allowableIncreases);
				if(!bSetSolution) return false;	
			}
			if(solution.variables.allowableDecreases!= null){
				bSetSolution = setVariableAllowableDecreases(solIdx, solution.variables.allowableDecreases);
				if(!bSetSolution) return false;	
			}		
			if(solution.variables.ovFunctions!= null){
				bSetSolution = setVariableOVFunctions(solIdx, solution.variables.ovFunctions);
				if(!bSetSolution) return false;	
			}		
			if(solution.variables.other!= null){
				bSetSolution = setOtherVariableResults(solIdx, solution.variables.other);
				if(!bSetSolution) return false;	
			}		
		}

		if(solution.objectives != null){
			if(solution.objectives.values != null){
				double[] mdValues = new double[m_iObjectiveNumber];
				ObjValue[] obj = solution.objectives.values.obj;
				int iObjs = obj==null?0:obj.length;
				for(int i = 0; i < m_iObjectiveNumber; i++){
					mdValues[i] = Double.NaN;
				}
				for(int i = 0; i < iObjs; i++){
					mdValues[Math.abs(obj[i].idx)-1] = obj[i].value;
				}
				bSetSolution = setObjectiveValues(solIdx, mdValues);
				if(!bSetSolution) return false;	
			}	
			if(solution.objectives.ovFunctions!= null){
				bSetSolution = setObjectiveOVFunctions(solIdx, solution.objectives.ovFunctions);
				if(!bSetSolution) return false;	
			}		
			if(solution.objectives.other!= null){
				bSetSolution = setOtherObjectiveResults(solIdx, solution.objectives.other);
				if(!bSetSolution) return false;	
			}		
		}

		if(solution.constraints != null){
			if(solution.constraints.values != null){
				double[] mdValues = new double[m_iConstraintNumber];
				ConValue[] con = solution.constraints.values.con;
				int iCons = con==null?0:con.length;
				for(int i = 0; i < iCons; i++){
					mdValues[con[i].idx] = con[i].value;
				}
				bSetSolution = setConstraintValues(solIdx, mdValues);
				if(!bSetSolution) return false;	
			}		
			if(solution.constraints.dualUnboundedDirections != null){
				double[] mdLbValues = new double[m_iConstraintNumber];
				double[] mdUbValues = new double[m_iConstraintNumber];
				DualVarUnboundedDirection[] con = solution.constraints.dualUnboundedDirections.con;
				int iCons = con==null?0:con.length;
				for(int i = 0; i < iCons; i++){
					mdLbValues[con[i].idx] = con[i].lbValue;
					mdUbValues[con[i].idx] = con[i].ubValue;
				}
				bSetSolution = setDualUnboundedDirections(solIdx, mdLbValues, mdUbValues);
				if(!bSetSolution) return false;	
			}	
			if(solution.constraints.irreducibleInconsistentSystem != null){
				bSetSolution = setConstraintIrreducibleInconsistentSystem(solIdx, solution.constraints.irreducibleInconsistentSystem);
				if(!bSetSolution) return false;	
			}		
			if(solution.constraints.dualValues != null){
				double[] mdLbValues = new double[m_iConstraintNumber];
				double[] mdUbValues = new double[m_iConstraintNumber];
				DualVarValue[] con = solution.constraints.dualValues.con;
				int iCons = con==null?0:con.length;
				for(int i = 0; i < iCons; i++){
					mdLbValues[con[i].idx] = con[i].lbValue;
					mdUbValues[con[i].idx] = con[i].ubValue;
				}
				bSetSolution = setDualVariableValues(solIdx, mdLbValues, mdUbValues);
				if(!bSetSolution) return false;	
			}	
			if(solution.constraints.slacks != null){
				bSetSolution = setConstraintSlacks(solIdx, solution.constraints.slacks);
				if(!bSetSolution) return false;	
			}
			if(solution.constraints.allowableIncreases != null){
				bSetSolution = setConstraintAllowableIncreases(solIdx, solution.constraints.allowableIncreases);
				if(!bSetSolution) return false;	
			}
			if(solution.constraints.allowableDecreases != null){
				bSetSolution = setConstraintAllowableDecreases(solIdx, solution.constraints.allowableDecreases);
				if(!bSetSolution) return false;	
			}
			if(solution.constraints.ovFunctions != null){
				bSetSolution = setConstraintOVFunctions(solIdx, solution.constraints.ovFunctions);
				if(!bSetSolution) return false;	
			}
			if(solution.constraints.other != null){
				bSetSolution = setOtherConstraintResults(solIdx, solution.constraints.other);
				if(!bSetSolution) return false;	
			}
		}
		if(solution.other != null){
			bSetSolution = setOtherOptimizationResults(solIdx, solution.other);
			if(!bSetSolution) return false;	
		}
		return bSetSolution;
	}//setSolution	
	
	/**
	 * Set the [i]th optimization solution status, where i equals the given solution index.   
	 * The solution status includes the status type, optional descriptions and possibly substatuses. 
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * 
	 * @param solIdx holds the solution index to set the solution status.
	 * @param status holds the optimization solution status to set.  
	 * 
	 * @return whether the optimization solution status is set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolutionStatus
	 * @see #setSolutionNumber(int)
	 */
	public boolean setSolutionStatus(int solIdx, OptimizationSolutionStatus status){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eResultData, "optimization");
		if(eOptimization == null) return false;
		Vector<Element> vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
		if(solIdx >= vSolutions.size()) return false;
		Element eSolution = (Element)vSolutions.elementAt(solIdx);
		if(eSolution == null){
			eSolution = m_document.createElement("solution");
		}
		try{
			if(status != null){
				Element eStatus = (Element)XMLUtil.findChildNode(eSolution, "status");
				if(eStatus != null){
					eSolution.removeChild(eStatus);
				}
				eStatus = m_document.createElement("status");
				if(status.type != null && status.type.length() > 0){
					eStatus.setAttribute("type", status.type);					
				}
				else{
					return false;
				}
				if(status.description != null && status.description.length() > 0){
					eStatus.setAttribute("description", status.description);					
				}
				if(status.substatus != null && status.substatus.length > 0){
					int iSubstatus = status.substatus.length;
					for(int i = 0; i < iSubstatus; i++){
						Element eSubstatus =  m_document.createElement("substatus");
						if(status.substatus[i].name != null && status.substatus[i].name.length() > 0){
							eSubstatus.setAttribute("name", status.substatus[i].name);
						}						
						if(status.substatus[i].description != null && status.substatus[i].description.length() > 0){
							eSubstatus.setAttribute("description", status.substatus[i].description);
						}						
						if(status.substatus[i].value != null && status.substatus[i].value.length() > 0){
							eSubstatus.appendChild(m_document.createTextNode(status.substatus[i].value));
						}
						eStatus.appendChild(eSubstatus);
					}					
				}
				eSolution.insertBefore(eStatus, eSolution.getFirstChild());
			}
			else{
				XMLUtil.removeChildrenByName(eSolution, "status");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;

	}//setSolutionStatus
	
	/**
	 * Set the [i]th optimization solution status, where i equals the given solution index.   
	 * The solution status includes the status type, optional descriptions and possibly substatuses. 
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * 
	 * @param solIdx holds the solution index to set the solution status.
	 * @param type holds the optimization solution status type to set; it is required.   
	 * The solution status type can be: 
	 * unbounded, globallyOptimal, locallyOptimal, optimal, bestSoFar, feasible, infeasible, 
	 * stoppedByLimit, unsure, error, other 
	 * @param description holds the optimization solution status description to set, null or empty string if none.  
	 * @param subStatus holds an array of optimization solution subStatuses to set, null if none. 
	 * 
	 * @return whether the optimization solution status is set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolutionStatus
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolutionSubStatus
	 * @see #setSolutionNumber(int)
	 */
	public boolean setSolutionStatus(int solIdx, String type, String description, OptimizationSolutionSubstatus[] subStatuses){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eResultData, "optimization");
		if(eOptimization == null) return false;
		Vector<Element> vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
		if(solIdx >= vSolutions.size()) return false;
		Element eSolution = (Element)vSolutions.elementAt(solIdx);
		if(eSolution == null){
			eSolution = m_document.createElement("solution");
		}
		try{
			if(type != null && type.length() > 0){
				Element eStatus = (Element)XMLUtil.findChildNode(eSolution, "status");
				if(eStatus != null){
					eSolution.removeChild(eStatus);
				}
				eStatus = m_document.createElement("status");
				eStatus.setAttribute("type", type);					
				if(description != null && description.length() > 0){
					eStatus.setAttribute("description", description);					
				}
				else{
					eStatus.removeAttribute("description");
				}
				if(subStatuses != null && subStatuses.length > 0){
					int iSubstatus = subStatuses.length;
					for(int i = 0; i < iSubstatus; i++){
						Element eSubstatus =  m_document.createElement("substatus");
						if(subStatuses[i].name != null && subStatuses[i].name.length() > 0){
							eSubstatus.setAttribute("name", subStatuses[i].name);
						}						
						if(subStatuses[i].description != null && subStatuses[i].description.length() > 0){
							eSubstatus.setAttribute("description", subStatuses[i].description);
						}						
						if(subStatuses[i].value != null && subStatuses[i].value.length() > 0){
							eSubstatus.appendChild(m_document.createTextNode(subStatuses[i].value));
						}
						eStatus.appendChild(eSubstatus);
					}					
				}
				eSolution.insertBefore(eStatus, eSolution.getFirstChild());
			}
			else{
				return false;
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setSolutionStatus
	
	/**
	 * Set the [i]th optimization solution message, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * 
	 * @param solIdx holds the solution index to set the solution message.
	 * @param solutionMessage holds the solution message to set.  
	 * 
	 * @return whether the optimization solution message is set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setSolutionMessage(int solIdx, String solutionMessage){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eResultData, "optimization");
		if(eOptimization == null) return false;
		Vector<Element> vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
		if(solIdx >= vSolutions.size()) return false;
		Element eSolution = (Element)vSolutions.elementAt(solIdx);
		if(eSolution == null){
			eSolution = m_document.createElement("solution");
		}
		try{
			XMLUtil.removeChildrenByName(eSolution, "message");
			if(solutionMessage != null && solutionMessage.length() > 0){
				Element eMessage = m_document.createElement("message");
				eMessage.appendChild(m_document.createTextNode(solutionMessage));
				Node nodeRef = XMLUtil.findChildNode(eSolution, "status");			
				if(nodeRef != null){
					eSolution.insertBefore(eMessage, nodeRef.getNextSibling());			
				}
				else{
					eSolution.insertBefore(eMessage, eSolution.getFirstChild());
				}					
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setSolutionMessage	
	
	/**
	 * Set the [i]th optimization solution's objective index, where i equals the given solution index.   
	 * The first objective's index should be -1, the second -2, and so on.  
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * 
	 * @param solIdx holds the solution index to set the objective index.
	 * @param objectiveIdx holds the objective index to set.  
	 * All the objective indexes are negative starting from -1 downward. 
	 * 
	 * @return whether the optimization objective index is set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setSolutionObjectiveIndex(int solIdx, int objectiveIdx){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eResultData, "optimization");
		if(eOptimization == null) return false;
		Vector<Element> vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
		if(solIdx >= vSolutions.size()) return false;
		Element eSolution = (Element)vSolutions.elementAt(solIdx);
		if(eSolution == null){
			eSolution = m_document.createElement("solution");
		}
		try{
			eSolution.setAttribute("objectiveIdx", objectiveIdx+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setSolutionObjectiveIndex
	
	/**
	 * Set the [i]th optimization solution's primal variable values, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the primal variable values. 
	 * @param x holds a double dense array of variable values to set; it could be null if all variables are 0.
	 * 
	 * @return whether primal variable values are set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setPrimalVariableValues(int solIdx, double[] x){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eResultData, "optimization");
		if(eOptimization == null) return false;
		Vector<Element> vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
		if(solIdx >= vSolutions.size()) return false;
		Element eSolution = (Element)vSolutions.elementAt(solIdx);
		if(eSolution == null){
			eSolution = m_document.createElement("solution");
		}
		Node nodeRef = null;
		try{
			Element eVariables = (Element)XMLUtil.findChildNode(eSolution, "variables");
			if(eVariables == null){
				eVariables = m_document.createElement("variables");	
				nodeRef = XMLUtil.findChildNode(eSolution, "objectives");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(eSolution, "constraints");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(eSolution, "other");
					}
				}
				eSolution.insertBefore(eVariables, nodeRef);
			}
			Element eValues = (Element)XMLUtil.findChildNode(eVariables, "values");
			if(eValues == null){
				eValues = m_document.createElement("values");	
				eVariables.insertBefore(eValues, eVariables.getFirstChild());									
			}
			XMLUtil.removeAllChildren(eValues);
			int iVars = x==null?0:x.length;
			if(iVars == 0) return true;
			if(iVars != m_iVariableNumber) return false;
			for(int i = 0; i < iVars; i++){
				if(x[i] != 0){
					Element eVar = m_document.createElement("var");	
					eVar.setAttribute("idx", i+"");
					eVar.setAttribute("value", x[i]+"");
					eValues.appendChild(eVar);				
				}
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setPrimalVariableValues
	
	/**
	 * Set the [i]th optimization solution's primal variable string values, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the primal variable string values. 
	 * @param x holds a dense string array of variable string values to set.
	 * 
	 * @return whether primal variable string values are set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setPrimalVariableStringValues(int solIdx, String[] x){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eResultData, "optimization");
		if(eOptimization == null) return false;
		Vector<Element> vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
		if(solIdx >= vSolutions.size()) return false;
		Element eSolution = (Element)vSolutions.elementAt(solIdx);
		if(eSolution == null){
			eSolution = m_document.createElement("solution");
		}
		Node nodeRef = null;
		try{
			Element eVariables = (Element)XMLUtil.findChildNode(eSolution, "variables");
			if(eVariables == null){
				eVariables = m_document.createElement("variables");	
				nodeRef = XMLUtil.findChildNode(eSolution, "objectives");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(eSolution, "constraints");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(eSolution, "other");
					}
				}
				eSolution.insertBefore(eVariables, nodeRef);
			}
			Element eValuesString = (Element)XMLUtil.findChildNode(eVariables, "valuesString");
			if(eValuesString == null){
				eValuesString = m_document.createElement("valuesString");
				nodeRef = XMLUtil.findChildNode(eVariables, "primalUnboundedDirections");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(eVariables, "irreducibleInconsistentSystem");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(eVariables, "reducedCosts");
						if(nodeRef == null){
							nodeRef = XMLUtil.findChildNode(eVariables, "slacks");
							if(nodeRef == null){
								nodeRef = XMLUtil.findChildNode(eVariables, "allowableIncreases");
								if(nodeRef == null){
									nodeRef = XMLUtil.findChildNode(eVariables, "allowableDecreases");
									if(nodeRef == null){
										nodeRef = XMLUtil.findChildNode(eVariables, "ovFunctions");
										if(nodeRef == null){
											nodeRef = XMLUtil.findChildNode(eVariables, "other");
										}
									}

								}
							}
						}
					}
				}
				eVariables.insertBefore(eValuesString, nodeRef);
			}
			XMLUtil.removeAllChildren(eValuesString);
			int iVars = x==null?0:x.length;
			if(iVars == 0) return true;
			if(iVars != m_iVariableNumber) return false;
			for(int i = 0; i < iVars; i++){
				Element eVar = m_document.createElement("var");	
				eVar.setAttribute("idx", i+"");
				eVar.setAttribute("value", x[i]);
				eValuesString.appendChild(eVar);				
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setPrimalVariableStringValues

	/**
	 * Set the [i]th optimization solution's primal unbounded directions, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the primal unbounded directions. 
	 * @param directions holds a double dense array of primal unbounded directions to set; it could be null if all values are 0.
	 * 
	 * @return whether primal variable unbounded directions are set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setPrimalUnboundedDirections(int solIdx, double[] directions){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eResultData, "optimization");
		if(eOptimization == null) return false;
		Vector<Element> vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
		if(solIdx >= vSolutions.size()) return false;
		Element eSolution = (Element)vSolutions.elementAt(solIdx);
		if(eSolution == null){
			eSolution = m_document.createElement("solution");
		}
		Node nodeRef = null;
		try{
			Element eVariables = (Element)XMLUtil.findChildNode(eSolution, "variables");
			if(eVariables == null){
				eVariables = m_document.createElement("variables");	
				nodeRef = XMLUtil.findChildNode(eSolution, "objectives");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(eSolution, "constraints");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(eSolution, "other");
					}
				}
				eSolution.insertBefore(eVariables, nodeRef);
			}
			Element ePrimalUnboundedDirections = (Element)XMLUtil.findChildNode(eVariables, "primalUnboundedDirections");
			if(ePrimalUnboundedDirections == null){
				ePrimalUnboundedDirections = m_document.createElement("primalUnboundedDirections");	
				nodeRef = XMLUtil.findChildNode(eVariables, "irreducibleInconsistentSystem");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(eVariables, "reducedCosts");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(eVariables, "slacks");
						if(nodeRef == null){
							nodeRef = XMLUtil.findChildNode(eVariables, "allowableIncreases");
							if(nodeRef == null){
								nodeRef = XMLUtil.findChildNode(eVariables, "allowableDecreases");
								if(nodeRef == null){
									nodeRef = XMLUtil.findChildNode(eVariables, "ovFunctions");
									if(nodeRef == null){
										nodeRef = XMLUtil.findChildNode(eVariables, "other");
									}
								}

							}
						}
					}
				}
				eVariables.insertBefore(ePrimalUnboundedDirections, nodeRef);
			}
			XMLUtil.removeAllChildren(ePrimalUnboundedDirections);
			int iVars = directions==null?0:directions.length;
			if(iVars == 0) return true;
			if(iVars != m_iVariableNumber) return false;
			for(int i = 0; i < iVars; i++){
				if(directions[i] != 0){
					Element eVar = m_document.createElement("var");	
					eVar.setAttribute("idx", i+"");
					eVar.setAttribute("value", directions[i]+"");
					ePrimalUnboundedDirections.appendChild(eVar);				
				}
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setPrimalUnboundedDirections
		
	/**
	 * Set the [i]th optimization solution's variable Irreducible Inconsistent System (IIS), where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the IIS. 
	 * @param variableIIS holds the variable Irreducible Inconsistent System in the VariableIrreducibleInconsistentSystem data structure
	 * 
	 * @return whether the variable IIS is set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.VariableIrreducibleInconsistentSystem
	 * @see #setSolutionNumber(int)
	 */
	public boolean setVariableIrreducibleInconsistentSystem(int solIdx, VariableIrreducibleInconsistentSystem variableIIS){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eResultData, "optimization");
		if(eOptimization == null) return false;
		Vector<Element> vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
		if(solIdx >= vSolutions.size()) return false;
		Element eSolution = (Element)vSolutions.elementAt(solIdx);
		if(eSolution == null){
			eSolution = m_document.createElement("solution");
		}
		Node nodeRef = null;
		try{
			Element eVariables = (Element)XMLUtil.findChildNode(eSolution, "variables");
			if(eVariables == null){
				eVariables = m_document.createElement("variables");	
				nodeRef = XMLUtil.findChildNode(eSolution, "objectives");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(eSolution, "constraints");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(eSolution, "other");
					}
				}
				eSolution.insertBefore(eVariables, nodeRef);
			}
			Element eIrreducibleInconsistentSystem = (Element)XMLUtil.findChildNode(eVariables, "irreducibleInconsistentSystem");
			if(eIrreducibleInconsistentSystem == null){
				eIrreducibleInconsistentSystem = m_document.createElement("irreducibleInconsistentSystem");	
				nodeRef = XMLUtil.findChildNode(eVariables, "reducedCosts");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(eVariables, "slacks");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(eVariables, "allowableIncreases");
						if(nodeRef == null){
							nodeRef = XMLUtil.findChildNode(eVariables, "allowableDecreases");
							if(nodeRef == null){
								nodeRef = XMLUtil.findChildNode(eVariables, "ovFunctions");
								if(nodeRef == null){
									nodeRef = XMLUtil.findChildNode(eVariables, "other");
								}
							}

						}
					}
				}
				eVariables.insertBefore(eIrreducibleInconsistentSystem, nodeRef);
			}
			XMLUtil.removeAllChildren(eIrreducibleInconsistentSystem);
			int iVars = (variableIIS==null || variableIIS.var == null)?0:variableIIS.var.length;
			if(iVars == 0) return true;
			for(int i = 0; i < iVars; i++){
				Element eVar = m_document.createElement("var");	
				eVar.setAttribute("idx", variableIIS.var[i].idx+"");
				eVar.setAttribute("type", variableIIS.var[i].type);
				eIrreducibleInconsistentSystem.appendChild(eVar);	
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setVariableIrreducibleInconsistentSystem
	
	/**
	 * Set the [i]th optimization solution's reduced costs, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the reduced costs. 
	 * @param reducedCosts holds the reduced costs in the ReducedCosts data structure. 
	 * The data structure holds an array var[]; each var member holds 
	 * a variable idx, a reduced cost value on the lower bound (lbValue) and on the upper bound (ubValue). 
	 * 
	 * @return whether the reduced costs are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.ReducedCosts
	 * @see #setSolutionNumber(int)
	 */
	public boolean setReducedCosts(int solIdx, ReducedCosts reducedCosts){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eResultData, "optimization");
		if(eOptimization == null) return false;
		Vector<Element> vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
		if(solIdx >= vSolutions.size()) return false;
		Element eSolution = (Element)vSolutions.elementAt(solIdx);
		if(eSolution == null){
			eSolution = m_document.createElement("solution");
		}
		Node nodeRef = null;
		try{
			Element eVariables = (Element)XMLUtil.findChildNode(eSolution, "variables");
			if(eVariables == null){
				eVariables = m_document.createElement("variables");	
				nodeRef = XMLUtil.findChildNode(eSolution, "objectives");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(eSolution, "constraints");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(eSolution, "other");
					}
				}
				eSolution.insertBefore(eVariables, nodeRef);
			}
			Element eReducedCosts = (Element)XMLUtil.findChildNode(eVariables, "reducedCosts");
			if(eReducedCosts == null){
				eReducedCosts = m_document.createElement("reducedCosts");	
				nodeRef = XMLUtil.findChildNode(eVariables, "slacks");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(eVariables, "allowableIncreases");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(eVariables, "allowableDecreases");
						if(nodeRef == null){
							nodeRef = XMLUtil.findChildNode(eVariables, "ovFunctions");
							if(nodeRef == null){
								nodeRef = XMLUtil.findChildNode(eVariables, "other");
							}
						}

					}
				}
				eVariables.insertBefore(eReducedCosts, nodeRef);
			}
			XMLUtil.removeAllChildren(eReducedCosts);
			int iVars = (reducedCosts==null || reducedCosts.var == null)?0:reducedCosts.var.length;
			if(iVars == 0) return true;
			for(int i = 0; i < iVars; i++){
				Element eVar = m_document.createElement("var");	
				eVar.setAttribute("idx", reducedCosts.var[i].idx+"");
				if(reducedCosts.var[i].lbValue == Double.POSITIVE_INFINITY){
					eVar.setAttribute("lbValue", "INF");
				}
				else if(reducedCosts.var[i].lbValue == Double.NEGATIVE_INFINITY){
					eVar.setAttribute("lbValue", "-INF");
				}
				else{
					eVar.setAttribute("lbValue", reducedCosts.var[i].lbValue+"");
				}
				if(reducedCosts.var[i].ubValue == Double.POSITIVE_INFINITY){
					eVar.setAttribute("ubValue", "INF");
				}
				else if(reducedCosts.var[i].ubValue == Double.NEGATIVE_INFINITY){
					eVar.setAttribute("ubValue", "-INF");
				}
				else{
					eVar.setAttribute("ubValue", reducedCosts.var[i].ubValue+"");
				}
				eReducedCosts.appendChild(eVar);	
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setReducedCosts
	
	/**
	 * Set the [i]th optimization solution's variable slacks, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the variable slacks. 
	 * @param variableSlacks holds the variable slacks in the VariableSlacks data structure. 
	 * The data structure holds an array var[]; each var member holds 
	 * a variable idx, a slack value on the lower bound (lbValue) and on the upper bound (ubValue). 
	 * 
	 * @return whether the variable slacks are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.VariableSlacks
	 * @see #setSolutionNumber(int)
	 */
	public boolean setVariableSlacks(int solIdx, VariableSlacks variableSlacks){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eResultData, "optimization");
		if(eOptimization == null) return false;
		Vector<Element> vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
		if(solIdx >= vSolutions.size()) return false;
		Element eSolution = (Element)vSolutions.elementAt(solIdx);
		if(eSolution == null){
			eSolution = m_document.createElement("solution");
		}
		Node nodeRef = null;
		try{
			Element eVariables = (Element)XMLUtil.findChildNode(eSolution, "variables");
			if(eVariables == null){
				eVariables = m_document.createElement("variables");	
				nodeRef = XMLUtil.findChildNode(eSolution, "objectives");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(eSolution, "constraints");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(eSolution, "other");
					}
				}
				eSolution.insertBefore(eVariables, nodeRef);
			}
			Element eSlacks = (Element)XMLUtil.findChildNode(eVariables, "slacks");
			if(eSlacks == null){
				eSlacks = m_document.createElement("slacks");	
				nodeRef = XMLUtil.findChildNode(eVariables, "allowableIncreases");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(eVariables, "allowableDecreases");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(eVariables, "ovFunctions");
						if(nodeRef == null){
							nodeRef = XMLUtil.findChildNode(eVariables, "other");
						}
					}

				}
				eVariables.insertBefore(eSlacks, nodeRef);
			}
			XMLUtil.removeAllChildren(eSlacks);
			int iVars = (variableSlacks==null || variableSlacks.var == null)?0:variableSlacks.var.length;
			if(iVars == 0) return true;
			for(int i = 0; i < iVars; i++){
				Element eVar = m_document.createElement("var");	
				eVar.setAttribute("idx", variableSlacks.var[i].idx+"");
				eVar.setAttribute("lbValue", variableSlacks.var[i].lbValue+"");
				eVar.setAttribute("ubValue", variableSlacks.var[i].ubValue+"");
				eSlacks.appendChild(eVar);	
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setVariableSlacks
	
	/**
	 * Set the [i]th optimization solution's variable allowable increases, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the variable allowable increases. 
	 * @param variableAllowableIncreases holds the variable allowable increases in the VariableAllowableIncreases data structure. 
	 * The data structure holds an array var[]; each var member holds 
	 * a variable idx, an allowable increase value on the lower bound (lbValue) and on the upper bound (ubValue). 
	 * 
	 * @return whether the variable allowable increases are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.VariableAllowableIncreases
	 * @see #setSolutionNumber(int)
	 */
	public boolean setVariableAllowableIncreases(int solIdx, VariableAllowableIncreases variableAllowableIncreases){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eResultData, "optimization");
		if(eOptimization == null) return false;
		Vector<Element> vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
		if(solIdx >= vSolutions.size()) return false;
		Element eSolution = (Element)vSolutions.elementAt(solIdx);
		if(eSolution == null){
			eSolution = m_document.createElement("solution");
		}
		Node nodeRef = null;
		try{
			Element eVariables = (Element)XMLUtil.findChildNode(eSolution, "variables");
			if(eVariables == null){
				eVariables = m_document.createElement("variables");	
				nodeRef = XMLUtil.findChildNode(eSolution, "objectives");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(eSolution, "constraints");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(eSolution, "other");
					}
				}
				eSolution.insertBefore(eVariables, nodeRef);
			}
			Element eAllowableIncreases = (Element)XMLUtil.findChildNode(eVariables, "allowableIncreases");
			if(eAllowableIncreases == null){
				eAllowableIncreases = m_document.createElement("allowableIncreases");	
				nodeRef = XMLUtil.findChildNode(eVariables, "allowableDecreases");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(eVariables, "ovFunctions");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(eVariables, "other");
					}
				}
				eVariables.insertBefore(eAllowableIncreases, nodeRef);
			}
			XMLUtil.removeAllChildren(eAllowableIncreases);
			int iVars = (variableAllowableIncreases==null || variableAllowableIncreases.var == null)?0:variableAllowableIncreases.var.length;
			if(iVars == 0) return true;
			for(int i = 0; i < iVars; i++){
				Element eVar = m_document.createElement("var");	
				eVar.setAttribute("idx", variableAllowableIncreases.var[i].idx+"");
				if(variableAllowableIncreases.var[i].lbValue == Double.POSITIVE_INFINITY){
					eVar.setAttribute("lbValue", "INF");
				}
				else if(variableAllowableIncreases.var[i].lbValue == Double.NEGATIVE_INFINITY){
					eVar.setAttribute("lbValue", "-INF");
				}
				else{
					eVar.setAttribute("lbValue", variableAllowableIncreases.var[i].lbValue+"");
				}
				if(variableAllowableIncreases.var[i].ubValue == Double.POSITIVE_INFINITY){
					eVar.setAttribute("ubValue", "INF");
				}
				else if(variableAllowableIncreases.var[i].ubValue == Double.NEGATIVE_INFINITY){
					eVar.setAttribute("ubValue", "-INF");
				}
				else{
					eVar.setAttribute("ubValue", variableAllowableIncreases.var[i].ubValue+"");
				}
				eAllowableIncreases.appendChild(eVar);	
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;	
	}//setVariableAllowableIncreases
	
	/**
	 * Set the [i]th optimization solution's variable allowable decreases, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the variable allowable decreases. 
	 * @param variableAllowableDecreases holds the variable allowable decreases in the VariableAllowableDecreases data structure. 
	 * The data structure holds an array var[]; each var member holds 
	 * a variable idx, an allowable decrease value on the lower bound (lbValue) and on the upper bound (ubValue). 
	 * 
	 * @return whether the variable allowable decreases are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.VariableAllowableDecreases
	 * @see #setSolutionNumber(int)
	 */
	public boolean setVariableAllowableDecreases(int solIdx, VariableAllowableDecreases variableAllowableDecreases){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eResultData, "optimization");
		if(eOptimization == null) return false;
		Vector<Element> vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
		if(solIdx >= vSolutions.size()) return false;
		Element eSolution = (Element)vSolutions.elementAt(solIdx);
		if(eSolution == null){
			eSolution = m_document.createElement("solution");
		}
		Node nodeRef = null;
		try{
			Element eVariables = (Element)XMLUtil.findChildNode(eSolution, "variables");
			if(eVariables == null){
				eVariables = m_document.createElement("variables");	
				nodeRef = XMLUtil.findChildNode(eSolution, "objectives");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(eSolution, "constraints");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(eSolution, "other");
					}
				}
				eSolution.insertBefore(eVariables, nodeRef);
			}
			Element eAllowableDecreases = (Element)XMLUtil.findChildNode(eVariables, "allowableDecreases");
			if(eAllowableDecreases == null){
				eAllowableDecreases = m_document.createElement("allowableDecreases");	
				nodeRef = XMLUtil.findChildNode(eVariables, "ovFunctions");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(eVariables, "other");
				}
				eVariables.insertBefore(eAllowableDecreases, nodeRef);
			}
			XMLUtil.removeAllChildren(eAllowableDecreases);
			int iVars = (variableAllowableDecreases==null || variableAllowableDecreases.var == null)?0:variableAllowableDecreases.var.length;
			if(iVars == 0) return true;
			for(int i = 0; i < iVars; i++){
				Element eVar = m_document.createElement("var");	
				eVar.setAttribute("idx", variableAllowableDecreases.var[i].idx+"");
				if(variableAllowableDecreases.var[i].lbValue == Double.POSITIVE_INFINITY){
					eVar.setAttribute("lbValue", "INF");
				}
				else if(variableAllowableDecreases.var[i].lbValue == Double.NEGATIVE_INFINITY){
					eVar.setAttribute("lbValue", "-INF");
				}
				else{
					eVar.setAttribute("lbValue", variableAllowableDecreases.var[i].lbValue+"");
				}
				if(variableAllowableDecreases.var[i].ubValue == Double.POSITIVE_INFINITY){
					eVar.setAttribute("ubValue", "INF");
				}
				else if(variableAllowableDecreases.var[i].ubValue == Double.NEGATIVE_INFINITY){
					eVar.setAttribute("ubValue", "-INF");
				}
				else{
					eVar.setAttribute("ubValue", variableAllowableDecreases.var[i].ubValue+"");
				}
				eAllowableDecreases.appendChild(eVar);	
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setVariableAllowableDecreases
	
	
	/**
	 * Set the [i]th optimization solution's variable OVFunctions, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the variable OVFunctions. 
	 * @param variableOVFunctions holds the variable OVFunctions in the VariableOVFunctions data structure. 
	 * The data structure holds an array varBound[]; each varBound member corresponds to one OVFunction. 
	 * The varBound type can be eq, lb or ub and the varBound holds an idx for the index of the variable. 
	 * An OVFunction is a sequence (or array) of intervals, each interval contains a start value, an end value and a slope value. 
	 * 
	 * @return whether the variable OVFunctions are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.VariableOVFunctions
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OVFunction
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OVFunctionInterval
	 * @see #setSolutionNumber(int)
	 */
	public boolean setVariableOVFunctions(int solIdx, VariableOVFunctions variableOVFunctions){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eResultData, "optimization");
		if(eOptimization == null) return false;
		Vector<Element> vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
		if(solIdx >= vSolutions.size()) return false;
		Element eSolution = (Element)vSolutions.elementAt(solIdx);
		if(eSolution == null){
			eSolution = m_document.createElement("solution");
		}
		Node nodeRef = null;
		try{
			Element eVariables = (Element)XMLUtil.findChildNode(eSolution, "variables");
			if(eVariables == null){
				eVariables = m_document.createElement("variables");	
				nodeRef = XMLUtil.findChildNode(eSolution, "objectives");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(eSolution, "constraints");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(eSolution, "other");
					}
				}
				eSolution.insertBefore(eVariables, nodeRef);
			}
			Element eOVFunctions = (Element)XMLUtil.findChildNode(eVariables, "ovFunctions");
			if(eOVFunctions == null){
				eOVFunctions = m_document.createElement("ovFunctions");	
				nodeRef = XMLUtil.findChildNode(eVariables, "other");
				eVariables.insertBefore(eOVFunctions, nodeRef);
			}
			XMLUtil.removeAllChildren(eOVFunctions);
			int iVarBounds = (variableOVFunctions==null || variableOVFunctions.varBound == null)?0:variableOVFunctions.varBound.length;
			if(iVarBounds == 0) return false;
			for(int i = 0; i < iVarBounds; i++){
				Element eVarBound = m_document.createElement("varBound");	
				eVarBound.setAttribute("idx", variableOVFunctions.varBound[i].idx+"");
				eVarBound.setAttribute("type", variableOVFunctions.varBound[i].type);
				int iIntervals = (variableOVFunctions.varBound[i].interval == null)?0:variableOVFunctions.varBound[i].interval.length;
				if(iIntervals == 0) return false;
				for(int j = 0; j < iIntervals; j++){
					Element eInterval = m_document.createElement("interval");
					if(!Double.isNaN(variableOVFunctions.varBound[i].interval[j].start)){
						if(variableOVFunctions.varBound[i].interval[j].start == Double.POSITIVE_INFINITY){
							eInterval.setAttribute("start", "INF");
						}
						else if(variableOVFunctions.varBound[i].interval[j].start == Double.NEGATIVE_INFINITY){
							eInterval.setAttribute("start", "-INF");
						}
						else{
							eInterval.setAttribute("start", variableOVFunctions.varBound[i].interval[j].start+"");
						}
					}
					if(variableOVFunctions.varBound[i].interval[j].end == Double.POSITIVE_INFINITY){
						eInterval.setAttribute("end", "INF");
					}
					else if(variableOVFunctions.varBound[i].interval[j].end == Double.NEGATIVE_INFINITY){
						eInterval.setAttribute("end", "-INF");
					}
					else{
						eInterval.setAttribute("end", variableOVFunctions.varBound[i].interval[j].end+"");
					}
					if(variableOVFunctions.varBound[i].interval[j].slope == Double.POSITIVE_INFINITY){
						eInterval.setAttribute("slope", "INF");
					}
					else if(variableOVFunctions.varBound[i].interval[j].slope == Double.NEGATIVE_INFINITY){
						eInterval.setAttribute("slope", "-INF");
					}
					else{
						eInterval.setAttribute("slope", variableOVFunctions.varBound[i].interval[j].slope+"");
					}
					eVarBound.appendChild(eInterval);						
				}
				eOVFunctions.appendChild(eVarBound);	
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;	
	}//setVariableOVFunctions
		
	/**
	 * Set the [i]th optimization solution's other (non-standard/solver specific)variable-related results, 
	 * where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param otherVariableResults holds an array of other variable results in OtherVariableResult[] array data structure, null if none. 
	 * Each other variable result contains the name (required), an optional description (string) and an optional
	 * value (string). Each other variable result can also optionally contain an array OtherVarResult for each variable. 
	 * The OtherVarResult contains a variable idx (required), an optional string value, an optional string value on the lower bound (lbValue) 
	 * and an optional string value on the upper bound (ubValue).   
	 * 
	 * @return whether the other variable results are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherVariableResult
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherVarResult
	 * @see #setSolutionNumber(int)
	 */
	public boolean setOtherVariableResults(int solIdx, OtherVariableResult[] otherVariableResults){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eResultData, "optimization");
		if(eOptimization == null) return false;
		Vector<Element> vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
		if(solIdx >= vSolutions.size()) return false;
		Element eSolution = (Element)vSolutions.elementAt(solIdx);
		if(eSolution == null){
			eSolution = m_document.createElement("solution");
		}
		Node nodeRef = null;
		try{
			Element eVariables = (Element)XMLUtil.findChildNode(eSolution, "variables");
			if(eVariables == null){
				eVariables = m_document.createElement("variables");	
				nodeRef = XMLUtil.findChildNode(eSolution, "objectives");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(eSolution, "constraints");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(eSolution, "other");
					}
				}
				eSolution.insertBefore(eVariables, nodeRef);
			}
			XMLUtil.removeChildrenByName(eVariables, "other");
			int iOthers = otherVariableResults==null?0:otherVariableResults.length;
			if(iOthers == 0) return true;
			for(int i = 0; i < iOthers; i++){
				Element eOther = m_document.createElement("other");
				if(otherVariableResults[i].name == null || otherVariableResults[i].name.length() <= 0){
					return false;
				}
				else{
					eOther.setAttribute("name", otherVariableResults[i].name);
				}
				if(otherVariableResults[i].description != null && otherVariableResults[i].description.length() > 0){
					eOther.setAttribute("description", otherVariableResults[i].description);					
				}
				if(otherVariableResults[i].value != null && otherVariableResults[i].value.length() > 0){
					eOther.setAttribute("value", otherVariableResults[i].value);					
				}
				int iVars = (otherVariableResults[i]==null || otherVariableResults[i].var == null)?0:otherVariableResults[i].var.length;
				if(iVars > 0){
					for(int j = 0; j < iVars; j++){
						Element eVar = m_document.createElement("var");	
						eVar.setAttribute("idx", otherVariableResults[i].var[j].idx+"");
						if(otherVariableResults[i].var[j].value != null && otherVariableResults[i].var[j].value.length() > 0){
							eVar.setAttribute("value", otherVariableResults[i].var[j].value);								
						}
						if(otherVariableResults[i].var[j].lbValue != null && otherVariableResults[i].var[j].lbValue.length() > 0){
							eVar.setAttribute("lbValue", otherVariableResults[i].var[j].lbValue);								
						}
						if(otherVariableResults[i].var[j].ubValue != null && otherVariableResults[i].var[j].ubValue.length() > 0){
							eVar.setAttribute("ubValue", otherVariableResults[i].var[j].ubValue);								
						}
						eOther.appendChild(eVar);	
					}
				}
				eVariables.appendChild(eOther);
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setOtherVariableResults
	
	/**
	 * Set the [i]th optimization solution's objective values, where i equals the given solution index.   
	 * Usually one of the objective is what the solution was solved for (or based on). Its index should be indicated 
	 * in the solution's objectiveIdx attribute. Based on this objective's solution, the rest of the objective 
	 * values are (optionally) calculated. 
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the objective values. 
	 * @param objectiveValues holds a double dense array of objective values to set.
	 * Possibly only the objective that the solution is based on has the value, and the rest of the objective
	 * values all get a Double.NaN value, meaning that they are not calculated.   
	 * 
	 * @return whether objective values are set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setObjectiveValues(int solIdx, double[] objectiveValues){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eResultData, "optimization");
		if(eOptimization == null) return false;
		Vector<Element> vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
		if(solIdx >= vSolutions.size()) return false;
		Element eSolution = (Element)vSolutions.elementAt(solIdx);
		if(eSolution == null){
			eSolution = m_document.createElement("solution");
		}
		Node nodeRef = null;
		try{
			Element eObjectives = (Element)XMLUtil.findChildNode(eSolution, "objectives");
			if(eObjectives == null){
				eObjectives = m_document.createElement("objectives");	
				nodeRef = XMLUtil.findChildNode(eSolution, "constraints");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(eSolution, "other");
				}
				eSolution.insertBefore(eObjectives, nodeRef);
			}
			Element eValues = (Element)XMLUtil.findChildNode(eObjectives, "values");
			if(eValues == null){
				eValues = m_document.createElement("values");	
				eObjectives.insertBefore(eValues, eObjectives.getFirstChild());									
			}
			XMLUtil.removeAllChildren(eValues);
			int iObjs = objectiveValues==null?0:objectiveValues.length;
			if(iObjs == 0) return true;
			if(iObjs != m_iObjectiveNumber) return false;
			for(int i = 0; i < iObjs; i++){
				if(!Double.isNaN(objectiveValues[i])){
					Element eObj = m_document.createElement("obj");	
					eObj.setAttribute("idx", (-i-1)+"");
					eObj.setAttribute("value", objectiveValues[i]+"");
					eValues.appendChild(eObj);				
				}
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setObjectiveValues

	/**
	 * Set the [i]th optimization solution's objective OVFunctions, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the objective OVFunctions. 
	 * @param objectiveOVFunctions holds the objective OVFunctions in the ObjectiveOVFunctions data structure. 
	 * The data structure holds an array varCoef[]; each varCoef member corresponds to one OVFunction (for each of the objective's variable coefficients). 
	 * The varCoef holds an idx for the index of the variable. 
	 * An OVFunction is a sequence (or array) of intervals, each interval contains a start value, an end value and a slope value. 
	 * 
	 * @return whether the objective OVFunctions are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.ObjectiveOVFunctions
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OVFunction
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OVFunctionInterval
	 * @see #setSolutionNumber(int)
	 */
	public boolean setObjectiveOVFunctions(int solIdx, ObjectiveOVFunctions objectiveOVFunctions){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eResultData, "optimization");
		if(eOptimization == null) return false;
		Vector<Element> vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
		if(solIdx >= vSolutions.size()) return false;
		Element eSolution = (Element)vSolutions.elementAt(solIdx);
		if(eSolution == null){
			eSolution = m_document.createElement("solution");
		}
		Node nodeRef = null;
		try{
			Element eObjectives = (Element)XMLUtil.findChildNode(eSolution, "objectives");
			if(eObjectives == null){
				eObjectives = m_document.createElement("objectives");	
				nodeRef = XMLUtil.findChildNode(eSolution, "constraints");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(eSolution, "other");
				}
				eSolution.insertBefore(eObjectives, nodeRef);
			}
			Element eOVFunctions = (Element)XMLUtil.findChildNode(eObjectives, "ovFunctions");
			if(eOVFunctions == null){
				eOVFunctions = m_document.createElement("ovFunctions");	
				nodeRef = XMLUtil.findChildNode(eObjectives, "other");
				eObjectives.insertBefore(eOVFunctions, nodeRef);
			}
			XMLUtil.removeAllChildren(eOVFunctions);
			int iVarCoefs = (objectiveOVFunctions==null || objectiveOVFunctions.varCoef == null)?0:objectiveOVFunctions.varCoef.length;
			if(iVarCoefs == 0) return false;
			for(int i = 0; i < iVarCoefs; i++){
				Element eVarCoef = m_document.createElement("varCoef");	
				eVarCoef.setAttribute("idx", objectiveOVFunctions.varCoef[i].idx+"");
				eVarCoef.setAttribute("type", objectiveOVFunctions.varCoef[i].type);
				int iIntervals = (objectiveOVFunctions.varCoef[i].interval == null)?0:objectiveOVFunctions.varCoef[i].interval.length;
				if(iIntervals == 0) return false;
				for(int j = 0; j < iIntervals; j++){
					Element eInterval = m_document.createElement("interval");
					if(!Double.isNaN(objectiveOVFunctions.varCoef[i].interval[j].start)){
						if(objectiveOVFunctions.varCoef[i].interval[j].start == Double.POSITIVE_INFINITY){
							eInterval.setAttribute("start", "INF");
						}
						else if(objectiveOVFunctions.varCoef[i].interval[j].start == Double.NEGATIVE_INFINITY){
							eInterval.setAttribute("start", "-INF");
						}
						else{
							eInterval.setAttribute("start", objectiveOVFunctions.varCoef[i].interval[j].start+"");
						}
					}
					if(objectiveOVFunctions.varCoef[i].interval[j].end == Double.POSITIVE_INFINITY){
						eInterval.setAttribute("end", "INF");
					}
					else if(objectiveOVFunctions.varCoef[i].interval[j].end == Double.NEGATIVE_INFINITY){
						eInterval.setAttribute("end", "-INF");
					}
					else{
						eInterval.setAttribute("end", objectiveOVFunctions.varCoef[i].interval[j].end+"");
					}
					if(objectiveOVFunctions.varCoef[i].interval[j].slope == Double.POSITIVE_INFINITY){
						eInterval.setAttribute("slope", "INF");
					}
					else if(objectiveOVFunctions.varCoef[i].interval[j].slope == Double.NEGATIVE_INFINITY){
						eInterval.setAttribute("slope", "-INF");
					}
					else{
						eInterval.setAttribute("slope", objectiveOVFunctions.varCoef[i].interval[j].slope+"");
					}
					eVarCoef.appendChild(eInterval);						
				}
				eOVFunctions.appendChild(eVarCoef);	
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setObjectiveOVFunctions
	
	/**
	 * Set the [i]th optimization solution's other (non-standard/solver specific)objective-related results, 
	 * where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the other objective results. 
	 * @param otherObjectiveResults holds an array of other objective results in OtherObjectiveResult[] array data structure, null if none. 
	 * Each other objective result contains the name (required), an optional description (string) and an optional
	 * value (string). Each other objective result can also optionally contain an array OtherObjResult for each objective. 
	 * The OtherObjResult contains an objective idx (required), an optional string value.    
	 * 
	 * @return whether the other objective results are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherObjectiveResult
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherObjResult
	 * @see #setSolutionNumber(int)
	 */
	public boolean setOtherObjectiveResults(int solIdx, OtherObjectiveResult[] otherObjectiveResults){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eResultData, "optimization");
		if(eOptimization == null) return false;
		Vector<Element> vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
		if(solIdx >= vSolutions.size()) return false;
		Element eSolution = (Element)vSolutions.elementAt(solIdx);
		if(eSolution == null){
			eSolution = m_document.createElement("solution");
		}
		Node nodeRef = null;
		try{
			Element eObjectives = (Element)XMLUtil.findChildNode(eSolution, "objectives");
			if(eObjectives == null){
				eObjectives = m_document.createElement("objectives");	
				nodeRef = XMLUtil.findChildNode(eSolution, "constraints");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(eSolution, "other");
				}
				eSolution.insertBefore(eObjectives, nodeRef);
			}
			XMLUtil.removeChildrenByName(eObjectives, "other");
			int iOthers = otherObjectiveResults==null?0:otherObjectiveResults.length;
			if(iOthers == 0) return true;
			for(int i = 0; i < iOthers; i++){
				Element eOther = m_document.createElement("other");
				if(otherObjectiveResults[i].name == null || otherObjectiveResults[i].name.length() <= 0){
					return false;
				}
				else{
					eOther.setAttribute("name", otherObjectiveResults[i].name);
				}
				if(otherObjectiveResults[i].description != null && otherObjectiveResults[i].description.length() > 0){
					eOther.setAttribute("description", otherObjectiveResults[i].description);					
				}
				if(otherObjectiveResults[i].value != null && otherObjectiveResults[i].value.length() > 0){
					eOther.setAttribute("value", otherObjectiveResults[i].value);					
				}
				int iObjs = (otherObjectiveResults[i]==null || otherObjectiveResults[i].obj == null)?0:otherObjectiveResults[i].obj.length;
				if(iObjs > 0){
					for(int j = 0; j < iObjs; j++){
						Element eObj = m_document.createElement("obj");	
						eObj.setAttribute("idx", otherObjectiveResults[i].obj[j].idx+"");
						if(otherObjectiveResults[i].obj[j].value != null && otherObjectiveResults[i].obj[j].value.length() > 0){
							eObj.setAttribute("value", otherObjectiveResults[i].obj[j].value);								
						}
						eOther.appendChild(eObj);	
					}
				}
				eObjectives.appendChild(eOther);
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setOtherObjectiveResults
	
	/**
	 * Set the [i]th optimization solution's constraint values, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the constraint values. 
	 * @param constraintValues holds a double dense array of constraint values to set; it could be null if all constraint values are 0.
	 * 
	 * @return whether constraint values are set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setConstraintValues(int solIdx, double[] constraintValues){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eResultData, "optimization");
		if(eOptimization == null) return false;
		Vector<Element> vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
		if(solIdx >= vSolutions.size()) return false;
		Element eSolution = (Element)vSolutions.elementAt(solIdx);
		if(eSolution == null){
			eSolution = m_document.createElement("solution");
		}
		Node nodeRef = null;
		try{
			Element eConstraints = (Element)XMLUtil.findChildNode(eSolution, "constraints");
			if(eConstraints == null){
				eConstraints = m_document.createElement("constraints");	
				nodeRef = XMLUtil.findChildNode(eSolution, "other");
				eSolution.insertBefore(eConstraints, nodeRef);
			}
			Element eValues = (Element)XMLUtil.findChildNode(eConstraints, "values");
			if(eValues == null){
				eValues = m_document.createElement("values");	
				eConstraints.insertBefore(eValues, eConstraints.getFirstChild());									
			}
			XMLUtil.removeAllChildren(eValues);
			int iCons = constraintValues==null?0:constraintValues.length;
			if(iCons == 0) return true;
			if(iCons != m_iConstraintNumber) return false;
			for(int i = 0; i < iCons; i++){
				if(constraintValues[i] != 0){
					Element eCon = m_document.createElement("con");	
					eCon.setAttribute("idx", i+"");
					eCon.setAttribute("value", constraintValues[i]+"");
					eValues.appendChild(eCon);				
				}
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setConstraintValues

	/**
	 * Set the [i]th optimization solution's dual variable unbounded directions, where i equals the given solution index. 
	 * The method allows setting dual unbounded directions at both the constraints' lower and upper bounds.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the dual variable unbounded directions. 
	 * @param lbValues holds a double dense array of variable dual unbounded directions to set at the lower bounds; it could be null if all unbounded directions are 0.
	 * @param ubValues holds a double dense array of variable dual unbounded directions to set at the upper bounds; it could be null if all unbounded directions are 0.
	 * 
	 * @return whether dual variable unbounded directions are set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setDualUnboundedDirections(int solIdx, double[] lbValues, double[] ubValues){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eResultData, "optimization");
		if(eOptimization == null) return false;
		Vector<Element> vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
		if(solIdx >= vSolutions.size()) return false;
		Element eSolution = (Element)vSolutions.elementAt(solIdx);
		if(eSolution == null){
			eSolution = m_document.createElement("solution");
		}
		Node nodeRef = null;
		try{
			Element eConstraints = (Element)XMLUtil.findChildNode(eSolution, "constraints");
			if(eConstraints == null){
				eConstraints = m_document.createElement("constraints");	
				nodeRef = XMLUtil.findChildNode(eSolution, "other");
				eSolution.insertBefore(eConstraints, nodeRef);
			}
			Element eDualUnboundedDirections = (Element)XMLUtil.findChildNode(eConstraints, "dualUnboundedDirections");
			if(eDualUnboundedDirections == null){
				eDualUnboundedDirections = m_document.createElement("dualUnboundedDirections");	
				nodeRef = XMLUtil.findChildNode(eConstraints, "irreducibleInconsistentSystem");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(eConstraints, "dualValues");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(eConstraints, "slacks");
						if(nodeRef == null){
							nodeRef = XMLUtil.findChildNode(eConstraints, "allowableIncreases");
							if(nodeRef == null){
								nodeRef = XMLUtil.findChildNode(eConstraints, "allowableDecreases");
								if(nodeRef == null){
									nodeRef = XMLUtil.findChildNode(eConstraints, "ovFunctions");
									if(nodeRef == null){
										nodeRef = XMLUtil.findChildNode(eConstraints, "other");
									}
								}

							}
						}
					}
				}
				eConstraints.insertBefore(eDualUnboundedDirections, nodeRef);
			}
			XMLUtil.removeAllChildren(eDualUnboundedDirections);
			int iCons;
			if(lbValues != null && ubValues != null && lbValues.length != ubValues.length){
				return false;
			}
			iCons = lbValues == null?0:lbValues.length;
			if(iCons == 0){
				iCons = ubValues == null?0:ubValues.length;				
			}
			if(iCons == 0) return true;
			if(iCons != m_iConstraintNumber) return false;
			for(int i = 0; i < iCons; i++){
				Element eCon = m_document.createElement("con");	
				eCon.setAttribute("idx", i+"");
				if(lbValues != null && lbValues[i] != 0){
					eCon.setAttribute("lbValue", lbValues[i]+"");						
				}
				if(ubValues != null && ubValues[i] != 0){
					eCon.setAttribute("ubValue", ubValues[i]+"");						
				}
				eDualUnboundedDirections.appendChild(eCon);				
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setDualUnboundedDirections

		
	/**
	 * Set the [i]th optimization solution's constraint Irreducible Inconsistent System (IIS), where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the IIS. 
	 * @param constraintIIS holds the constraint Irreducible Inconsistent System in the ConstraintIrreducibleInconsistentSystem data structure
	 * 
	 * @return whether the constraint IIS is set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.ConstraintIrreducibleInconsistentSystem
	 * @see #setSolutionNumber(int)
	 */
	public boolean setConstraintIrreducibleInconsistentSystem(int solIdx, ConstraintIrreducibleInconsistentSystem constraintIIS){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eResultData, "optimization");
		if(eOptimization == null) return false;
		Vector<Element> vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
		if(solIdx >= vSolutions.size()) return false;
		Element eSolution = (Element)vSolutions.elementAt(solIdx);
		if(eSolution == null){
			eSolution = m_document.createElement("solution");
		}
		Node nodeRef = null;
		try{
			Element eConstraints = (Element)XMLUtil.findChildNode(eSolution, "constraints");
			if(eConstraints == null){
				eConstraints = m_document.createElement("constraints");	
				nodeRef = XMLUtil.findChildNode(eSolution, "other");
				eSolution.insertBefore(eConstraints, nodeRef);
			}
			Element eIrreducibleInconsistentSystem = (Element)XMLUtil.findChildNode(eConstraints, "irreducibleInconsistentSystem");
			if(eIrreducibleInconsistentSystem == null){
				eIrreducibleInconsistentSystem = m_document.createElement("irreducibleInconsistentSystem");	
				nodeRef = XMLUtil.findChildNode(eConstraints, "reducedCosts");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(eConstraints, "dualValues");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(eConstraints, "allowableIncreases");
						if(nodeRef == null){
							nodeRef = XMLUtil.findChildNode(eConstraints, "allowableDecreases");
							if(nodeRef == null){
								nodeRef = XMLUtil.findChildNode(eConstraints, "ovFunctions");
								if(nodeRef == null){
									nodeRef = XMLUtil.findChildNode(eConstraints, "other");
								}
							}

						}
					}
				}
				eConstraints.insertBefore(eIrreducibleInconsistentSystem, nodeRef);
			}
			XMLUtil.removeAllChildren(eIrreducibleInconsistentSystem);
			int iCons = (constraintIIS==null || constraintIIS.con == null)?0:constraintIIS.con.length;
			if(iCons == 0) return true;
			for(int i = 0; i < iCons; i++){
				Element eCon = m_document.createElement("con");	
				eCon.setAttribute("idx", constraintIIS.con[i].idx+"");
				eCon.setAttribute("type", constraintIIS.con[i].type);
				eIrreducibleInconsistentSystem.appendChild(eCon);	
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setConstraintIrreducibleInconsistentSystem

	/**
	 * Set the [i]th optimization solution's dual variable values, where i equals the given solution index. 
	 * The method allows setting dual values at both the constraints' lower and upper bounds.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the dual variable values. 
	 * @param lbValues holds a double dense array of variable dual values to set at the lower bounds; it could be null if all values are 0.
	 * @param ubValues holds a double dense array of variable dual values to set at the upper bounds; it could be null if all values are 0.
	 * 
	 * @return whether dual variable values are set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setDualVariableValues(int solIdx, double[] lbValues, double[] ubValues){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eResultData, "optimization");
		if(eOptimization == null) return false;
		Vector<Element> vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
		if(solIdx >= vSolutions.size()) return false;
		Element eSolution = (Element)vSolutions.elementAt(solIdx);
		if(eSolution == null){
			eSolution = m_document.createElement("solution");
		}
		Node nodeRef = null;
		try{
			Element eConstraints = (Element)XMLUtil.findChildNode(eSolution, "constraints");
			if(eConstraints == null){
				eConstraints = m_document.createElement("constraints");	
				nodeRef = XMLUtil.findChildNode(eSolution, "other");
				eSolution.insertBefore(eConstraints, nodeRef);
			}
			Element eDualValues = (Element)XMLUtil.findChildNode(eConstraints, "dualValues");
			if(eDualValues == null){
				eDualValues = m_document.createElement("dualValues");	
				nodeRef = XMLUtil.findChildNode(eConstraints, "slacks");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(eConstraints, "allowableIncreases");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(eConstraints, "allowableDecreases");
						if(nodeRef == null){
							nodeRef = XMLUtil.findChildNode(eConstraints, "ovFunctions");
							if(nodeRef == null){
								nodeRef = XMLUtil.findChildNode(eConstraints, "other");
							}
						}

					}
				}
				eConstraints.insertBefore(eDualValues, nodeRef);
			}
			XMLUtil.removeAllChildren(eDualValues);
			int iCons;
			if(lbValues != null && ubValues != null && lbValues.length != ubValues.length){
				return false;
			}
			iCons = lbValues == null?0:lbValues.length;
			if(iCons == 0){
				iCons = ubValues == null?0:ubValues.length;				
			}
			if(iCons == 0) return true;
			if(iCons != m_iConstraintNumber) return false;
			for(int i = 0; i < iCons; i++){
				Element eCon = m_document.createElement("con");	
				eCon.setAttribute("idx", i+"");
				if(lbValues != null && lbValues[i] != 0){
					eCon.setAttribute("lbValue", lbValues[i]+"");						
				}
				if(ubValues != null && ubValues[i] != 0){
					eCon.setAttribute("ubValue", ubValues[i]+"");						
				}
				eDualValues.appendChild(eCon);				
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setDualVariableValues
	
	/**
	 * Set the [i]th optimization solution's constraint slacks, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the constraint slacks. 
	 * @param constraintSlacks holds the constraint slacks in the ConstraintSlacks data structure. 
	 * The data structure holds an array con[]; each con member holds 
	 * a constraint idx, a slack value on the lower bound (lbValue) and on the upper bound (ubValue). 
	 * 
	 * @return whether the constraint slacks are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.ConstraintSlacks
	 * @see #setSolutionNumber(int)
	 */
	public boolean setConstraintSlacks(int solIdx, ConstraintSlacks constraintSlacks){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eResultData, "optimization");
		if(eOptimization == null) return false;
		Vector<Element> vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
		if(solIdx >= vSolutions.size()) return false;
		Element eSolution = (Element)vSolutions.elementAt(solIdx);
		if(eSolution == null){
			eSolution = m_document.createElement("solution");
		}
		Node nodeRef = null;
		try{
			Element eConstraints = (Element)XMLUtil.findChildNode(eSolution, "constraints");
			if(eConstraints == null){
				eConstraints = m_document.createElement("constraints");	
				nodeRef = XMLUtil.findChildNode(eSolution, "other");
				eSolution.insertBefore(eConstraints, nodeRef);
			}
			Element eSlacks = (Element)XMLUtil.findChildNode(eConstraints, "slacks");
			if(eSlacks == null){
				eSlacks = m_document.createElement("slacks");	
				nodeRef = XMLUtil.findChildNode(eConstraints, "allowableIncreases");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(eConstraints, "allowableDecreases");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(eConstraints, "ovFunctions");
						if(nodeRef == null){
							nodeRef = XMLUtil.findChildNode(eConstraints, "other");
						}
					}

				}
				eConstraints.insertBefore(eSlacks, nodeRef);
			}
			XMLUtil.removeAllChildren(eSlacks);
			int iCons = (constraintSlacks==null || constraintSlacks.con == null)?0:constraintSlacks.con.length;
			if(iCons == 0) return true;
			for(int i = 0; i < iCons; i++){
				Element eCon = m_document.createElement("con");	
				eCon.setAttribute("idx", constraintSlacks.con[i].idx+"");
				eCon.setAttribute("lbValue", constraintSlacks.con[i].lbValue+"");
				eCon.setAttribute("ubValue", constraintSlacks.con[i].ubValue+"");
				eSlacks.appendChild(eCon);	
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setConstraintSlacks
	
	/**
	 * Set the [i]th optimization solution's constraint allowable increases, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the constraint allowable increases. 
	 * @param constraintAllowableIncreases holds the constraint allowable increases in the ConstraintAllowableIncreases data structure. 
	 * The data structure holds an array con[]; each con member holds 
	 * a constraint idx, an allowable increase value on the lower bound (lbValue) and on the upper bound (ubValue). 
	 * 
	 * @return whether the constraint allowable increases are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.ConstraintAllowableIncreases
	 * @see #setSolutionNumber(int)
	 */
	public boolean setConstraintAllowableIncreases(int solIdx, ConstraintAllowableIncreases constraintAllowableIncreases){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eResultData, "optimization");
		if(eOptimization == null) return false;
		Vector<Element> vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
		if(solIdx >= vSolutions.size()) return false;
		Element eSolution = (Element)vSolutions.elementAt(solIdx);
		if(eSolution == null){
			eSolution = m_document.createElement("solution");
		}
		Node nodeRef = null;
		try{
			Element eConstraints = (Element)XMLUtil.findChildNode(eSolution, "constraints");
			if(eConstraints == null){
				eConstraints = m_document.createElement("constraints");	
				nodeRef = XMLUtil.findChildNode(eSolution, "other");
				eSolution.insertBefore(eConstraints, nodeRef);
			}
			Element eAllowableIncreases = (Element)XMLUtil.findChildNode(eConstraints, "allowableIncreases");
			if(eAllowableIncreases == null){
				eAllowableIncreases = m_document.createElement("allowableIncreases");	
				nodeRef = XMLUtil.findChildNode(eConstraints, "allowableDecreases");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(eConstraints, "ovFunctions");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(eConstraints, "other");
					}
				}
				eConstraints.insertBefore(eAllowableIncreases, nodeRef);
			}
			XMLUtil.removeAllChildren(eAllowableIncreases);
			int iCons = (constraintAllowableIncreases==null || constraintAllowableIncreases.con == null)?0:constraintAllowableIncreases.con.length;
			if(iCons == 0) return true;
			for(int i = 0; i < iCons; i++){
				Element eCon = m_document.createElement("con");	
				eCon.setAttribute("idx", constraintAllowableIncreases.con[i].idx+"");
				if(constraintAllowableIncreases.con[i].lbValue == Double.POSITIVE_INFINITY){
					eCon.setAttribute("lbValue", "INF");
				}
				else if(constraintAllowableIncreases.con[i].lbValue == Double.NEGATIVE_INFINITY){
					eCon.setAttribute("lbValue", "-INF");
				}
				else{
					eCon.setAttribute("lbValue", constraintAllowableIncreases.con[i].lbValue+"");
				}
				if(constraintAllowableIncreases.con[i].ubValue == Double.POSITIVE_INFINITY){
					eCon.setAttribute("ubValue", "INF");
				}
				else if(constraintAllowableIncreases.con[i].ubValue == Double.NEGATIVE_INFINITY){
					eCon.setAttribute("ubValue", "-INF");
				}
				else{
					eCon.setAttribute("ubValue", constraintAllowableIncreases.con[i].ubValue+"");
				}
				eAllowableIncreases.appendChild(eCon);	
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;	
	}//setConstraintAllowableIncreases
	
	/**
	 * Set the [i]th optimization solution's constraint allowable decreases, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the constraint allowable decreases. 
	 * @param constraintAllowableDecreases holds the constraint allowable decreases in the ConstraintAllowableDecreases data structure. 
	 * The data structure holds an array con[]; each con member holds 
	 * a constraint idx, an allowable decrease value on the lower bound (lbValue) and on the upper bound (ubValue). 
	 * 
	 * @return whether the constraint allowable decreases are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.ConstraintAllowableDecreases
	 * @see #setSolutionNumber(int)
	 */
	public boolean setConstraintAllowableDecreases(int solIdx, ConstraintAllowableDecreases constraintAllowableDecreases){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eResultData, "optimization");
		if(eOptimization == null) return false;
		Vector<Element> vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
		if(solIdx >= vSolutions.size()) return false;
		Element eSolution = (Element)vSolutions.elementAt(solIdx);
		if(eSolution == null){
			eSolution = m_document.createElement("solution");
		}
		Node nodeRef = null;
		try{
			Element eConstraints = (Element)XMLUtil.findChildNode(eSolution, "constraints");
			if(eConstraints == null){
				eConstraints = m_document.createElement("constraints");	
				nodeRef = XMLUtil.findChildNode(eSolution, "other");
				eSolution.insertBefore(eConstraints, nodeRef);
			}
			Element eAllowableDecreases = (Element)XMLUtil.findChildNode(eConstraints, "allowableDecreases");
			if(eAllowableDecreases == null){
				eAllowableDecreases = m_document.createElement("allowableDecreases");	
				nodeRef = XMLUtil.findChildNode(eConstraints, "ovFunctions");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(eConstraints, "other");
				}
				eConstraints.insertBefore(eAllowableDecreases, nodeRef);
			}
			XMLUtil.removeAllChildren(eAllowableDecreases);
			int iCons = (constraintAllowableDecreases==null || constraintAllowableDecreases.con == null)?0:constraintAllowableDecreases.con.length;
			if(iCons == 0) return true;
			for(int i = 0; i < iCons; i++){
				Element eCon = m_document.createElement("con");	
				eCon.setAttribute("idx", constraintAllowableDecreases.con[i].idx+"");
				if(constraintAllowableDecreases.con[i].lbValue == Double.POSITIVE_INFINITY){
					eCon.setAttribute("lbValue", "INF");
				}
				else if(constraintAllowableDecreases.con[i].lbValue == Double.NEGATIVE_INFINITY){
					eCon.setAttribute("lbValue", "-INF");
				}
				else{
					eCon.setAttribute("lbValue", constraintAllowableDecreases.con[i].lbValue+"");
				}
				if(constraintAllowableDecreases.con[i].ubValue == Double.POSITIVE_INFINITY){
					eCon.setAttribute("ubValue", "INF");
				}
				else if(constraintAllowableDecreases.con[i].ubValue == Double.NEGATIVE_INFINITY){
					eCon.setAttribute("ubValue", "-INF");
				}
				else{
					eCon.setAttribute("ubValue", constraintAllowableDecreases.con[i].ubValue+"");
				}
				eAllowableDecreases.appendChild(eCon);	
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;	
	}//setConstraintAllowableDecreases
	
	
	/**
	 * Set the [i]th optimization solution's constraint OVFunctions, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the constraint OVFunctions. 
	 * @param constraintOVFunctions holds the constraint OVFunctions in the ConstraintOVFunctions data structure. 
	 * The data structure holds an array conBound[]; each conBound member corresponds to one OVFunction. 
	 * The conBound type can be eq, lb or ub and the conBound holds an idx for the index of the constraint. 
	 * An OVFunction is a sequence (or array) of intervals, each interval contains a start value, an end value and a slope value. 
	 * 
	 * @return whether the constraint OVFunctions are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.ConstraintOVFunctions
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OVFunction
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OVFunctionInterval
	 * @see #setSolutionNumber(int)
	 */
	public boolean setConstraintOVFunctions(int solIdx, ConstraintOVFunctions constraintOVFunctions){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eResultData, "optimization");
		if(eOptimization == null) return false;
		Vector<Element> vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
		if(solIdx >= vSolutions.size()) return false;
		Element eSolution = (Element)vSolutions.elementAt(solIdx);
		if(eSolution == null){
			eSolution = m_document.createElement("solution");
		}
		Node nodeRef = null;
		try{
			Element eConstraints = (Element)XMLUtil.findChildNode(eSolution, "constraints");
			if(eConstraints == null){
				eConstraints = m_document.createElement("constraints");	
				nodeRef = XMLUtil.findChildNode(eSolution, "other");
				eSolution.insertBefore(eConstraints, nodeRef);
			}
			Element eOVFunctions = (Element)XMLUtil.findChildNode(eConstraints, "ovFunctions");
			if(eOVFunctions == null){
				eOVFunctions = m_document.createElement("ovFunctions");	
				nodeRef = XMLUtil.findChildNode(eConstraints, "other");
				eConstraints.insertBefore(eOVFunctions, nodeRef);
			}
			XMLUtil.removeAllChildren(eOVFunctions);
			int iConBounds = (constraintOVFunctions==null || constraintOVFunctions.conBound == null)?0:constraintOVFunctions.conBound.length;
			if(iConBounds == 0) return false;
			for(int i = 0; i < iConBounds; i++){
				Element eConBound = m_document.createElement("conBound");	
				eConBound.setAttribute("idx", constraintOVFunctions.conBound[i].idx+"");
				eConBound.setAttribute("type", constraintOVFunctions.conBound[i].type);
				int iIntervals = (constraintOVFunctions.conBound[i].interval == null)?0:constraintOVFunctions.conBound[i].interval.length;
				if(iIntervals == 0) return false;
				for(int j = 0; j < iIntervals; j++){
					Element eInterval = m_document.createElement("interval");
					if(!Double.isNaN(constraintOVFunctions.conBound[i].interval[j].start)){
						if(constraintOVFunctions.conBound[i].interval[j].start == Double.POSITIVE_INFINITY){
							eInterval.setAttribute("start", "INF");
						}
						else if(constraintOVFunctions.conBound[i].interval[j].start == Double.NEGATIVE_INFINITY){
							eInterval.setAttribute("start", "-INF");
						}
						else{
							eInterval.setAttribute("start", constraintOVFunctions.conBound[i].interval[j].start+"");
						}
					}
					if(constraintOVFunctions.conBound[i].interval[j].end == Double.POSITIVE_INFINITY){
						eInterval.setAttribute("end", "INF");
					}
					else if(constraintOVFunctions.conBound[i].interval[j].end == Double.NEGATIVE_INFINITY){
						eInterval.setAttribute("end", "-INF");
					}
					else{
						eInterval.setAttribute("end", constraintOVFunctions.conBound[i].interval[j].end+"");
					}
					if(constraintOVFunctions.conBound[i].interval[j].slope == Double.POSITIVE_INFINITY){
						eInterval.setAttribute("slope", "INF");
					}
					else if(constraintOVFunctions.conBound[i].interval[j].slope == Double.NEGATIVE_INFINITY){
						eInterval.setAttribute("slope", "-INF");
					}
					else{
						eInterval.setAttribute("slope", constraintOVFunctions.conBound[i].interval[j].slope+"");
					}
					eConBound.appendChild(eInterval);						
				}
				eOVFunctions.appendChild(eConBound);	
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setConstraintOVFunctions
		
	/**
	 * Set the [i]th optimization solution's other (non-standard/solver specific)constraint-related results, 
	 * where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param otherConstraintResults holds an array of other constraint results in OtherConstraintResult[] array data structure, null if none. 
	 * Each other constraint result contains the name (required), an optional description (string) and an optional
	 * value (string). Each other constraint result can also optionally contain an array OtherConstraint for each constraint. 
	 * The OtherConResult contains a constraint idx (required), an optional string value, an optional string value on the lower bound (lbValue) 
	 * and an optional string value on the upper bound (ubValue).   
	 * 
	 * @return whether the other constraint results are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherConstraintResult
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherConResult
	 * @see #setSolutionNumber(int)
	 */
	public boolean setOtherConstraintResults(int solIdx, OtherConstraintResult[] otherConstraintResults){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eResultData, "optimization");
		if(eOptimization == null) return false;
		Vector<Element> vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
		if(solIdx >= vSolutions.size()) return false;
		Element eSolution = (Element)vSolutions.elementAt(solIdx);
		if(eSolution == null){
			eSolution = m_document.createElement("solution");
		}
		Node nodeRef = null;
		try{
			Element eConstraints = (Element)XMLUtil.findChildNode(eSolution, "constraints");
			if(eConstraints == null){
				eConstraints = m_document.createElement("constraints");	
				nodeRef = XMLUtil.findChildNode(eSolution, "other");
				eSolution.insertBefore(eConstraints, nodeRef);
			}
			XMLUtil.removeChildrenByName(eConstraints, "other");
			int iOthers = otherConstraintResults==null?0:otherConstraintResults.length;
			if(iOthers == 0) return true;
			for(int i = 0; i < iOthers; i++){
				Element eOther = m_document.createElement("other");
				if(otherConstraintResults[i].name == null || otherConstraintResults[i].name.length() <= 0){
					return false;
				}
				else{
					eOther.setAttribute("name", otherConstraintResults[i].name);
				}
				if(otherConstraintResults[i].description != null && otherConstraintResults[i].description.length() > 0){
					eOther.setAttribute("description", otherConstraintResults[i].description);					
				}
				if(otherConstraintResults[i].value != null && otherConstraintResults[i].value.length() > 0){
					eOther.setAttribute("value", otherConstraintResults[i].value);					
				}
				int iCons = (otherConstraintResults[i]==null || otherConstraintResults[i].con == null)?0:otherConstraintResults[i].con.length;
				if(iCons > 0){
					for(int j = 0; j < iCons; j++){
						Element eCon = m_document.createElement("con");	
						eCon.setAttribute("idx", otherConstraintResults[i].con[j].idx+"");
						if(otherConstraintResults[i].con[j].value != null && otherConstraintResults[i].con[j].value.length() > 0){
							eCon.setAttribute("value", otherConstraintResults[i].con[j].value);								
						}
						if(otherConstraintResults[i].con[j].lbValue != null && otherConstraintResults[i].con[j].lbValue.length() > 0){
							eCon.setAttribute("lbValue", otherConstraintResults[i].con[j].lbValue);								
						}
						if(otherConstraintResults[i].con[j].ubValue != null && otherConstraintResults[i].con[j].ubValue.length() > 0){
							eCon.setAttribute("ubValue", otherConstraintResults[i].con[j].ubValue);								
						}
						eOther.appendChild(eCon);	
					}
				}
				eConstraints.appendChild(eOther);
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setOtherConstraintResults

	/**
	 * Set the [i]th optimization solution's other (non-standard/solver specific)optimization-related results, 
	 * where i equals the given solution index.  These other results are usually on the general optimization, 
	 * not specifically on the variables, objective, or constraints.  
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param otherOptimizationResults holds an array of other optimization results in OtherOptimizationResult[] array data structure, null if none. 
	 * Each other optimization result contains the name (required), an optional description (string) and an optional
	 * value (string).  
	 * @return whether the other optimization results are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherOptimizationResult
	 * @see #setSolutionNumber(int)
	 */
	public boolean setOtherOptimizationResults(int solIdx, OtherOptimizationResult[] otherOptimizationResults){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eResultData, "optimization");
		if(eOptimization == null) return false;
		Vector<Element> vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
		if(solIdx >= vSolutions.size()) return false;
		Element eSolution = (Element)vSolutions.elementAt(solIdx);
		if(eSolution == null){
			eSolution = m_document.createElement("solution");
		}
		try{
			XMLUtil.removeChildrenByName(eSolution, "other");
			int iOthers = otherOptimizationResults==null?0:otherOptimizationResults.length;
			if(iOthers == 0) return true;
			for(int i = 0; i < iOthers; i++){
				Element eOther = m_document.createElement("other");
				if(otherOptimizationResults[i].name == null || otherOptimizationResults[i].name.length() <= 0){
					return false;
				}
				else{
					eOther.setAttribute("name", otherOptimizationResults[i].name);
				}
				if(otherOptimizationResults[i].description != null && otherOptimizationResults[i].description.length() > 0){
					eOther.setAttribute("description", otherOptimizationResults[i].description);					
				}
				if(otherOptimizationResults[i].value != null && otherOptimizationResults[i].value.length() > 0){
					eOther.setAttribute("value", otherOptimizationResults[i].value);					
				}
				eSolution.appendChild(eOther);
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setOtherOptimizationResults

	/**
	 * Set the optimization analysis. 
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * 
	 * @param osAnalysis holds the optimization analysis in the standard OSAnalysis data structure. 
	 * @return the optimization analysis in the standard OSAnalysis data structure, null if none.
	 * @see org.optimizationservices.oscommon.localinterface.OSAnalysis
	 * @see #setSolutionNumber(int)
	 */	
	public boolean setOSAnalysis(OSAnalysis osAnalysis){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eResultData, "optimization");
		if(eOptimization == null) return false;
		
		XMLUtil.removeChildrenByName(eOptimization, "osal");
		if(osAnalysis == null) return true;
		OSaLWriter osalWriter = new OSaLWriter();
		try {
			osalWriter.setOSAnalysis(osAnalysis);
		} 
		catch (Exception e) {
			e.printStackTrace();
		}
		Element eOSaL =  (Element)m_document.importNode(osalWriter.m_eOSaL, true);
		XMLUtil.removeAllAttributes(eOSaL);		
		eOptimization.appendChild(eOSaL);
		return true;
	}//setOSAnalysis
	
	/**
	 * Create the OSrL root element and its most basic required structure.
	 * 
	 * @return the OSrL element.
	 */
	protected Element createOSrLRoot(){
		Element eOSrL = XMLUtil.createOSxLRootElement(m_document, "osrl");
		m_eResultHeader = m_document.createElement("resultHeader");
		eOSrL.appendChild(m_eResultHeader);
		Element eGeneralStatus = m_document.createElement("generalStatus");
		eGeneralStatus.setAttribute("type", "success");
		m_eResultHeader.appendChild(eGeneralStatus);
		m_eResultData = m_document.createElement("resultData");
		eOSrL.appendChild(m_eResultData);
		return eOSrL;
	}//createOSrLRoot
	
	
	/**
	 * Create the otherResult element and its most basic required structure.
	 * @param name the name of the otherResult element. 
	 * @param value the value of the otherResult element, empty String "" if no value. 
	 * @param description holds the description of the otherResult element, empty String "" if none.
	 * @return the otherResult element.
	 */
	protected Element createOther(String name, String value, String description){
		Element eOtherResult = m_document.createElement("other");
		eOtherResult.setAttribute("name", name);
		eOtherResult.setAttribute("description", (description==null)?"":description);
		if(value != null && value.length() > 0){
			eOtherResult.appendChild(m_document.createTextNode(value));
		}
		return eOtherResult;
	}//createOtherResult
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		OSrLWriter osrlWriter = new OSrLWriter();
		String sFileName = OSParameter.CODE_HOME + "OSRepository/test/osrl/osrl.osrl";
		String sAnalysisFileName = OSParameter.CODE_HOME + "OSRepository/test/osal/osal.osal";

		GeneralStatus status = new GeneralStatus();
		status.type= "success";
		status.description = "my status description";
		GeneralSubstatus[] substatuses = new GeneralSubstatus[2];
		substatuses[0] = new GeneralSubstatus();
		substatuses[0].name = "sub name 0";
		substatuses[0].description = "sub description 0";
		substatuses[0].value = "sub value 0";
		substatuses[1] = new GeneralSubstatus();
		substatuses[1].name = "sub name 1";
		substatuses[1].description = "sub description 1";
		substatuses[1].value = "sub value 1";
		status.substatus = substatuses;
		if(!osrlWriter.setGeneralStatus(status)) System.out.println("status!");
		if(!osrlWriter.setGeneralMessage("my message")) System.out.println("message!");
		//if(!osrlWriter.setGeneralMessage("")) System.out.println("message!");
		if(!osrlWriter.setInstanceName("my instance")) System.out.println("instance");
		if(!osrlWriter.setServiceName("my service name")) System.out.println("service name");
		if(!osrlWriter.setServiceURI("my service uri")) System.out.println("uri");
		if(!osrlWriter.setJobID("my job ID")) System.out.println("job ID");
		if(!osrlWriter.setResultTime(new GregorianCalendar())) System.out.println("time!");

		
		if(!osrlWriter.setCurrentState("busy")) System.out.println("setCurrentState!");
		if(!osrlWriter.setAvailableDiskSpace(1.2)) System.out.println("setAvailableDiskSpace!");
		if(!osrlWriter.setAvailableMemory(3.4)) System.out.println("setAvailableMemory!");
		if(!osrlWriter.setCurrentJobCount(0)) System.out.println("setCurrentJobCount!");
		if(!osrlWriter.setTotalJobsSoFar(100)) System.out.println("setTotalJobsSoFar!");
		if(!osrlWriter.setTimeLastJobEnded(new GregorianCalendar(2006, 1, 31, 15, 3, 4))) System.out.println("setTimeLastJobEnded!");
		if(!osrlWriter.setTimeLastJobTook(200.4)) System.out.println("setTimeLastJobTook!");
		if(!osrlWriter.setTimeServiceStarted(new GregorianCalendar(2003, 1, 31, 15, 3, 4))) System.out.println("setTimeServiceStarted!");
		if(!osrlWriter.setServiceUtilization(1.3)) System.out.println("setServiceUtilization!");
		JobStatistics[] jobstatistics = new JobStatistics[2];
		jobstatistics[0] = new JobStatistics();
		jobstatistics[1] = new JobStatistics();
		jobstatistics[0].jobID = "job0000";
		jobstatistics[1].jobID = "job1111";
		jobstatistics[0].duration = 2.3;
		jobstatistics[0].startTime = new GregorianCalendar(2006, 1, 3);
		jobstatistics[0].endTime = new GregorianCalendar(2006, 1, 4);
		jobstatistics[0].scheduledStartTime = new GregorianCalendar(2006, 1, 3);
		jobstatistics[0].state = "running";
		JobDependencies dependencies = new JobDependencies();
		dependencies.jobID = new String[2];
		dependencies.jobID[0] = "333";
		dependencies.jobID[1] = "aaa";
		jobstatistics[0].dependencies = dependencies;	
		if(!osrlWriter.setJobStatistics(jobstatistics)) System.out.println("setJobStatistics!");
//		ProcessStatistics processStatistics = new ProcessStatistics();
//		processStatistics.jobs = new Jobs();
//		processStatistics.jobs.job = jobstatistics;
//		if(!osrlWriter.setProcessStatistics(processStatistics)) System.out.println("setJobStatistics!");

		
		String[] msOtherResultNames = {"other name 0", "other name 1"};
		String[] msOtherResultValues = {"other value 0", "other value 1"};
		if(!osrlWriter.setOtherResults(msOtherResultNames, msOtherResultValues, null)) System.out.println("set other!");
	
		if(!osrlWriter.addOtherResult("other name 2", "other value 2", null)) System.out.println("add other!");
		if(!osrlWriter.addOtherResult("other name 3", "other value 3", "other description 3")) System.out.println("add other!");

		
		osrlWriter.setVariableNumber(3);
		osrlWriter.setObjectiveNumber(2);
		osrlWriter.setConstraintNumber(4);
		osrlWriter.setSolutionNumber(3);
		
		if(!osrlWriter.setSolutionStatus(0, "optimal", "solved", null)) System.out.println("setSolutionStatus");
		if(!osrlWriter.setSolutionStatus(1, "infeasible", "solved", null)) System.out.println("setSolutionStatus");
		if(!osrlWriter.setSolutionStatus(2, "globallyOptimal", "solved", null)) System.out.println("setSolutionStatus");

		if(!osrlWriter.setSolutionMessage(0, "sol0 message")) System.out.println("setSolutionMessage");
		if(!osrlWriter.setSolutionMessage(1, "sol1 message")) System.out.println("setSolutionMessage");
		if(!osrlWriter.setSolutionMessage(2, "sol2 message")) System.out.println("setSolutionMessage");


		if(!osrlWriter.setSolutionObjectiveIndex(0, -1)) System.out.println("setSolutionObjectiveIndex");
		if(!osrlWriter.setSolutionObjectiveIndex(1, -1)) System.out.println("setSolutionObjectiveIndex");
		if(!osrlWriter.setSolutionObjectiveIndex(2, -1)) System.out.println("setSolutionObjectiveIndex");

		String[] msValues1 = {"a", "b", "c"};
		if(!osrlWriter.setPrimalVariableStringValues(0, msValues1)) System.out.println("setPrimalVariableStringValues");
		String[] msValues2 = {"b", "c", "d"};
		if(!osrlWriter.setPrimalVariableStringValues(1, msValues2)) System.out.println("setPrimalVariableStringValues");
		String[] msValues3 = {"c", "d", "e"};
		if(!osrlWriter.setPrimalVariableStringValues(2, msValues3)) System.out.println("setPrimalVariableStringValues");

		
		double[] mdValues1 = {1, 2, 3};
		if(!osrlWriter.setPrimalVariableValues(0, mdValues1)) System.out.println("setPrimalVariableValues");
		double[] mdValues2 = {2, 3, 4};
		if(!osrlWriter.setPrimalVariableValues(1, mdValues2)) System.out.println("setPrimalVariableValues");
		double[] mdValues3 = {3, 4, 5};
		if(!osrlWriter.setPrimalVariableValues(2, mdValues3)) System.out.println("setPrimalVariableValues");

		double[] mdValues11 = {1, 2};
		if(!osrlWriter.setObjectiveValues(0, mdValues11)) System.out.println("setObjectiveValues");
		double[] mdValues22 = {2, 3};
		if(!osrlWriter.setObjectiveValues(1, mdValues22)) System.out.println("setObjectiveValues");
		double[] mdValues33 = {3, 4};
		if(!osrlWriter.setObjectiveValues(2, mdValues33)) System.out.println("setObjectiveValues");

		double[] mdValues111 = {1, 2, 3, 4};
		if(!osrlWriter.setConstraintValues(0, mdValues111)) System.out.println("setConstraintValues");
		double[] mdValues222 = {2, 3, 4, 5};
		if(!osrlWriter.setConstraintValues(1, mdValues222)) System.out.println("setConstraintValues");
		double[] mdValues333 = {3, 4, 5, 6};
		if(!osrlWriter.setConstraintValues(2, mdValues333)) System.out.println("setConstraintValues");

		
		double[] mdValues4 = {4, 2, 3};
		if(!osrlWriter.setPrimalUnboundedDirections(0, mdValues4)) System.out.println("setPrimalUnboundedDirections");
		double[] mdValues5 = {5, 3, 4};
		if(!osrlWriter.setPrimalVariableValues(1, mdValues5)) System.out.println("setPrimalVariableValues");
		double[] mdValues6 = {6, 4, 5};
		if(!osrlWriter.setPrimalUnboundedDirections(2, mdValues6)) System.out.println("setPrimalUnboundedDirections");

		double[] mdValues44 = {4, 2, 3, 4};
		if(!osrlWriter.setDualUnboundedDirections(0, mdValues44, null)) System.out.println("setDualUnboundedDirections");
		double[] mdValues55 = {5, 3, 4, 5};
		if(!osrlWriter.setDualUnboundedDirections(1, mdValues55, mdValues44)) System.out.println("setDualUnboundedDirections");
		double[] mdValues66 = {6, 4, 5, 6};
		if(!osrlWriter.setDualUnboundedDirections(2, mdValues66, mdValues55)) System.out.println("setDualUnboundedDirections");

		
		VariableIrreducibleInconsistentSystem varIIS1 = new VariableIrreducibleInconsistentSystem();
		varIIS1.var = new VarIrreducibleInconsistentSystem[4];
		varIIS1.var[0] = new VarIrreducibleInconsistentSystem();
		varIIS1.var[1] = new VarIrreducibleInconsistentSystem();
		varIIS1.var[2] = new VarIrreducibleInconsistentSystem();
		varIIS1.var[3] = new VarIrreducibleInconsistentSystem();
		varIIS1.var[0].idx = 0;
		varIIS1.var[1].idx = 2;
		varIIS1.var[2].idx = 1;
		varIIS1.var[3].idx = 0;
		varIIS1.var[0].type = "lb";
		varIIS1.var[1].type = "ub";
		varIIS1.var[2].type = "lb";
		varIIS1.var[3].type = "ub";
		if(!osrlWriter.setVariableIrreducibleInconsistentSystem(0, varIIS1)) System.out.println("setVariableIrreducibleInconsistentSystem");
		if(!osrlWriter.setVariableIrreducibleInconsistentSystem(1, varIIS1)) System.out.println("setVariableIrreducibleInconsistentSystem");
		if(!osrlWriter.setVariableIrreducibleInconsistentSystem(2, varIIS1)) System.out.println("setVariableIrreducibleInconsistentSystem");
		
		ConstraintIrreducibleInconsistentSystem conIIS1 = new ConstraintIrreducibleInconsistentSystem();
		conIIS1.con = new ConIrreducibleInconsistentSystem[4];
		conIIS1.con[0] = new ConIrreducibleInconsistentSystem();
		conIIS1.con[1] = new ConIrreducibleInconsistentSystem();
		conIIS1.con[2] = new ConIrreducibleInconsistentSystem();
		conIIS1.con[3] = new ConIrreducibleInconsistentSystem();
		conIIS1.con[0].idx = 0;
		conIIS1.con[1].idx = 2;
		conIIS1.con[2].idx = 1;
		conIIS1.con[3].idx = 0;
		conIIS1.con[0].type = "lb";
		conIIS1.con[1].type = "ub";
		conIIS1.con[2].type = "lb";
		conIIS1.con[3].type = "ub";
		if(!osrlWriter.setConstraintIrreducibleInconsistentSystem(0, conIIS1)) System.out.println("setConstraintIrreducibleInconsistentSystem");
		if(!osrlWriter.setConstraintIrreducibleInconsistentSystem(1, conIIS1)) System.out.println("setConstraintIrreducibleInconsistentSystem");
		if(!osrlWriter.setConstraintIrreducibleInconsistentSystem(2, conIIS1)) System.out.println("setConstraintIrreducibleInconsistentSystem");

		ReducedCosts varRC1 = new ReducedCosts();
		varRC1.var = new VarReducedCost[2];
		varRC1.var[0] = new VarReducedCost();
		varRC1.var[0].idx = 0;
		varRC1.var[0].lbValue = 1.1;
		varRC1.var[0].ubValue = 2.2;
		varRC1.var[1] = new VarReducedCost();
		varRC1.var[1].idx = 1;
		varRC1.var[1].lbValue = 3.3;
		varRC1.var[1].ubValue = 4.4;
		if(!osrlWriter.setReducedCosts(0, varRC1)) System.out.println("setReducedCosts");
		if(!osrlWriter.setReducedCosts(1, varRC1)) System.out.println("setReducedCosts");
		if(!osrlWriter.setReducedCosts(2, varRC1)) System.out.println("setReducedCosts");

		double[] mdValues77 = {4, 2, 3, 4};
		if(!osrlWriter.setDualVariableValues(0, null, mdValues77)) System.out.println("setDualVariableValues");
		double[] mdValues88 = {5, 3, 4, 5};
		if(!osrlWriter.setDualVariableValues(1, mdValues88, mdValues77)) System.out.println("setDualVariableValues");
		double[] mdValues99 = {6, 4, 5, 6};
		if(!osrlWriter.setDualVariableValues(2, mdValues99, mdValues88)) System.out.println("setDualVariableValues");

		VariableSlacks varSl1 = new VariableSlacks();
		varSl1.var = new VarSlack[2];
		varSl1.var[0] = new VarSlack();
		varSl1.var[0].idx = 0;
		varSl1.var[0].lbValue = 1.11;
		varSl1.var[0].ubValue = 2.22;
		varSl1.var[1] = new VarSlack();
		varSl1.var[1].idx = 1;
		varSl1.var[1].lbValue = 3.33;
		varSl1.var[1].ubValue = 4.44;
		if(!osrlWriter.setVariableSlacks(0, varSl1)) System.out.println("setVariableSlacks");
		if(!osrlWriter.setVariableSlacks(1, varSl1)) System.out.println("setVariableSlacks");
		if(!osrlWriter.setVariableSlacks(2, varSl1)) System.out.println("setVariableSlacks");

		ConstraintSlacks conSl1 = new ConstraintSlacks();
		conSl1.con = new ConSlack[2];
		conSl1.con[0] = new ConSlack();
		conSl1.con[0].idx = 0;
		conSl1.con[0].lbValue = 1.11;
		conSl1.con[0].ubValue = 2.22;
		conSl1.con[1] = new ConSlack();
		conSl1.con[1].idx = 1;
		conSl1.con[1].lbValue = 3.33;
		conSl1.con[1].ubValue = 4.44;
		if(!osrlWriter.setConstraintSlacks(0, conSl1)) System.out.println("setConstraintSlacks");
		if(!osrlWriter.setConstraintSlacks(1, conSl1)) System.out.println("setConstraintSlacks");
		if(!osrlWriter.setConstraintSlacks(2, conSl1)) System.out.println("setConstraintSlacks");
		
		VariableAllowableIncreases varInc1 = new VariableAllowableIncreases();
		varInc1.var = new VarAllowableIncrease[2];
		varInc1.var[0] = new VarAllowableIncrease();
		varInc1.var[0].idx = 0;
		varInc1.var[0].lbValue = 1.111;
		varInc1.var[0].ubValue = 2.222;
		varInc1.var[1] = new VarAllowableIncrease();
		varInc1.var[1].idx = 1;
		varInc1.var[1].lbValue = 3.333;
		varInc1.var[1].ubValue = 4.444;
		if(!osrlWriter.setVariableAllowableIncreases(0, varInc1)) System.out.println("setVariableAllowableIncreases");
		if(!osrlWriter.setVariableAllowableIncreases(1, varInc1)) System.out.println("setVariableAllowableIncreases");
		if(!osrlWriter.setVariableAllowableIncreases(2, varInc1)) System.out.println("setVariableAllowableIncreases");

		ConstraintAllowableIncreases conInc1 = new ConstraintAllowableIncreases();
		conInc1.con = new ConAllowableIncrease[2];
		conInc1.con[0] = new ConAllowableIncrease();
		conInc1.con[0].idx = 0;
		conInc1.con[0].lbValue = 1.111;
		conInc1.con[0].ubValue = 2.222;
		conInc1.con[1] = new ConAllowableIncrease();
		conInc1.con[1].idx = 1;
		conInc1.con[1].lbValue = 3.333;
		conInc1.con[1].ubValue = 4.444;
		if(!osrlWriter.setConstraintAllowableIncreases(0, conInc1)) System.out.println("setConstraintAllowableIncreases");
		if(!osrlWriter.setConstraintAllowableIncreases(1, conInc1)) System.out.println("setConstraintAllowableIncreases");
		if(!osrlWriter.setConstraintAllowableIncreases(2, conInc1)) System.out.println("setConstraintAllowableIncreases");
		
		VariableAllowableDecreases varDec1 = new VariableAllowableDecreases();
		varDec1.var = new VarAllowableDecrease[2];
		varDec1.var[0] = new VarAllowableDecrease();
		varDec1.var[0].idx = 0;
		varDec1.var[0].lbValue = 1.1111;
		varDec1.var[0].ubValue = 2.2222;
		varDec1.var[1] = new VarAllowableDecrease();
		varDec1.var[1].idx = 1;
		varDec1.var[1].lbValue = 3.3333;
		varDec1.var[1].ubValue = 4.4444;
		if(!osrlWriter.setVariableAllowableDecreases(0, varDec1)) System.out.println("setVariableAllowableDecreases");
		if(!osrlWriter.setVariableAllowableDecreases(1, varDec1)) System.out.println("setVariableAllowableDecreases");
		if(!osrlWriter.setVariableAllowableDecreases(2, varDec1)) System.out.println("setVariableAllowableDecreases");

		ConstraintAllowableDecreases conDec1 = new ConstraintAllowableDecreases();
		conDec1.con = new ConAllowableDecrease[2];
		conDec1.con[0] = new ConAllowableDecrease();
		conDec1.con[0].idx = 0;
		conDec1.con[0].lbValue = 1.1111;
		conDec1.con[0].ubValue = 2.2222;
		conDec1.con[1] = new ConAllowableDecrease();
		conDec1.con[1].idx = 1;
		conDec1.con[1].lbValue = 3.3333;
		conDec1.con[1].ubValue = 4.4444;
		if(!osrlWriter.setConstraintAllowableDecreases(0, conDec1)) System.out.println("setConstraintAllowableDecreases");
		if(!osrlWriter.setConstraintAllowableDecreases(1, conDec1)) System.out.println("setConstraintAllowableDecreases");
		if(!osrlWriter.setConstraintAllowableDecreases(2, conDec1)) System.out.println("setConstraintAllowableDecreases");
		
		VariableOVFunctions varOV1 = new VariableOVFunctions();
		varOV1.varBound = new OVFunction[2];
		varOV1.varBound[0] = new OVFunction();
		varOV1.varBound[0].idx = 0;
		varOV1.varBound[0].type = "lb";
		varOV1.varBound[0].interval = new OVFunctionInterval[3];
		varOV1.varBound[0].interval[0] = new OVFunctionInterval();
		varOV1.varBound[0].interval[0].start = 1.1;
		varOV1.varBound[0].interval[0].end = 2.2;
		varOV1.varBound[0].interval[0].slope = 101;
		varOV1.varBound[0].interval[1] = new OVFunctionInterval();
		varOV1.varBound[0].interval[1].start = 2.2;
		varOV1.varBound[0].interval[1].end = 3.3;
		varOV1.varBound[0].interval[1].slope = 202;
		varOV1.varBound[0].interval[2] = new OVFunctionInterval();
		varOV1.varBound[0].interval[2].start = 3.3;
		varOV1.varBound[0].interval[2].end = 4.4;
		varOV1.varBound[0].interval[2].slope = 303;
		varOV1.varBound[1] = new OVFunction();
		varOV1.varBound[1].idx = 0;
		varOV1.varBound[1].type = "lb";
		varOV1.varBound[1].interval = new OVFunctionInterval[3];
		varOV1.varBound[1].interval[0] = new OVFunctionInterval();
		varOV1.varBound[1].interval[0].start = 1.1;
		varOV1.varBound[1].interval[0].end = 2.2;
		varOV1.varBound[1].interval[0].slope = 101;
		varOV1.varBound[1].interval[1] = new OVFunctionInterval();
		varOV1.varBound[1].interval[1].end = 3.3;
		varOV1.varBound[1].interval[1].slope = 202;
		varOV1.varBound[1].interval[2] = new OVFunctionInterval();
		varOV1.varBound[1].interval[2].start = 3.3;
		varOV1.varBound[1].interval[2].end = 4.4;
		varOV1.varBound[1].interval[2].slope = 303;

		if(!osrlWriter.setVariableOVFunctions(0, varOV1)) System.out.println("setVariableOVFunctions");
		if(!osrlWriter.setVariableOVFunctions(1, varOV1)) System.out.println("setVariableOVFunctions");
		if(!osrlWriter.setVariableOVFunctions(2, varOV1)) System.out.println("setVariableOVFunctions");

		ConstraintOVFunctions conOV1 = new ConstraintOVFunctions();
		conOV1.conBound = new OVFunction[2];
		conOV1.conBound[0] = new OVFunction();
		conOV1.conBound[0].idx = 0;
		conOV1.conBound[0].type = "lb";
		conOV1.conBound[0].interval = new OVFunctionInterval[3];
		conOV1.conBound[0].interval[0] = new OVFunctionInterval();
		conOV1.conBound[0].interval[0].start = 1.1;
		conOV1.conBound[0].interval[0].end = 2.2;
		conOV1.conBound[0].interval[0].slope = 101;
		conOV1.conBound[0].interval[1] = new OVFunctionInterval();
		conOV1.conBound[0].interval[1].start = 2.2;
		conOV1.conBound[0].interval[1].end = 3.3;
		conOV1.conBound[0].interval[1].slope = 202;
		conOV1.conBound[0].interval[2] = new OVFunctionInterval();
		conOV1.conBound[0].interval[2].start = 3.3;
		conOV1.conBound[0].interval[2].end = 4.4;
		conOV1.conBound[0].interval[2].slope = 303;
		conOV1.conBound[1] = new OVFunction();
		conOV1.conBound[1].idx = 0;
		conOV1.conBound[1].type = "lb";
		conOV1.conBound[1].interval = new OVFunctionInterval[3];
		conOV1.conBound[1].interval[0] = new OVFunctionInterval();
		conOV1.conBound[1].interval[0].start = 1.1;
		conOV1.conBound[1].interval[0].end = 2.2;
		conOV1.conBound[1].interval[0].slope = 101;
		conOV1.conBound[1].interval[1] = new OVFunctionInterval();
		conOV1.conBound[1].interval[1].end = 3.3;
		conOV1.conBound[1].interval[1].slope = 202;
		conOV1.conBound[1].interval[2] = new OVFunctionInterval();
		conOV1.conBound[1].interval[2].start = 3.3;
		conOV1.conBound[1].interval[2].end = 4.4;
		conOV1.conBound[1].interval[2].slope = 303;

		if(!osrlWriter.setConstraintOVFunctions(0, conOV1)) System.out.println("setConstraintOVFunctions");
		if(!osrlWriter.setConstraintOVFunctions(1, conOV1)) System.out.println("setConstraintOVFunctions");
		if(!osrlWriter.setConstraintOVFunctions(2, conOV1)) System.out.println("setConstraintOVFunctions");

		ObjectiveOVFunctions objOV1 = new ObjectiveOVFunctions();
		objOV1.varCoef = new OVFunction[2];
		objOV1.varCoef[0] = new OVFunction();
		objOV1.varCoef[0].idx = 0;
		objOV1.varCoef[0].type = "lb";
		objOV1.varCoef[0].interval = new OVFunctionInterval[3];
		objOV1.varCoef[0].interval[0] = new OVFunctionInterval();
		objOV1.varCoef[0].interval[0].start = 1.1;
		objOV1.varCoef[0].interval[0].end = 2.2;
		objOV1.varCoef[0].interval[0].slope = 101;
		objOV1.varCoef[0].interval[1] = new OVFunctionInterval();
		objOV1.varCoef[0].interval[1].start = 2.2;
		objOV1.varCoef[0].interval[1].end = 3.3;
		objOV1.varCoef[0].interval[1].slope = 202;
		objOV1.varCoef[0].interval[2] = new OVFunctionInterval();
		objOV1.varCoef[0].interval[2].start = 3.3;
		objOV1.varCoef[0].interval[2].end = 4.4;
		objOV1.varCoef[0].interval[2].slope = 303;
		objOV1.varCoef[1] = new OVFunction();
		objOV1.varCoef[1].idx = 0;
		objOV1.varCoef[1].type = "lb";
		objOV1.varCoef[1].interval = new OVFunctionInterval[3];
		objOV1.varCoef[1].interval[0] = new OVFunctionInterval();
		objOV1.varCoef[1].interval[0].start = 1.1;
		objOV1.varCoef[1].interval[0].end = 2.2;
		objOV1.varCoef[1].interval[0].slope = 101;
		objOV1.varCoef[1].interval[1] = new OVFunctionInterval();
		objOV1.varCoef[1].interval[1].end = 3.3;
		objOV1.varCoef[1].interval[1].slope = 202;
		objOV1.varCoef[1].interval[2] = new OVFunctionInterval();
		objOV1.varCoef[1].interval[2].start = 3.3;
		objOV1.varCoef[1].interval[2].end = 4.4;
		objOV1.varCoef[1].interval[2].slope = 303;

		if(!osrlWriter.setObjectiveOVFunctions(0, objOV1)) System.out.println("setObjectiveOVFunctions");
		if(!osrlWriter.setObjectiveOVFunctions(1, objOV1)) System.out.println("setObjectiveOVFunctions");
		if(!osrlWriter.setObjectiveOVFunctions(2, objOV1)) System.out.println("setObjectiveOVFunctions");

		OtherVariableResult[] varOT1 = new OtherVariableResult[2];
		varOT1[0] = new OtherVariableResult();	
		varOT1[0].var = new OtherVarResult[2];
		varOT1[0].var[0] = new OtherVarResult();
		varOT1[0].name = "varOT1 name";
		varOT1[0].description = "varOT1 description";
		varOT1[0].value = "varOT1 value";		
		varOT1[0].var[0].idx = 0;
		varOT1[0].var[0].lbValue = "aL";
		varOT1[0].var[0].ubValue = "aU";
		varOT1[0].var[0].value = "a";
		varOT1[0].var[1] = new OtherVarResult();
		varOT1[0].var[1].idx = 1;
		varOT1[0].var[1].lbValue = "bL";
		varOT1[0].var[1].ubValue = "bU";
		varOT1[0].var[1].value = "b";
		varOT1[1] = new OtherVariableResult();	
		varOT1[1].name = "varOT2 name";
		varOT1[1].description = "varOT2 description";
		varOT1[1].value = "varOT2 value";		
		varOT1[1].var = new OtherVarResult[2];
		varOT1[1].var[0] = new OtherVarResult();
		varOT1[1].var[0].idx = 0;
		varOT1[1].var[0].lbValue = "aL";
		varOT1[1].var[0].ubValue = "aU";
		varOT1[1].var[0].value = "a";
		varOT1[1].var[1] = new OtherVarResult();
		varOT1[1].var[1].idx = 1;
		varOT1[1].var[1].lbValue = "bL";
		varOT1[1].var[1].ubValue = "bU";
		varOT1[1].var[1].value = "b";
		if(!osrlWriter.setOtherVariableResults(0, varOT1)) System.out.println("setOtherVariableResults");
		if(!osrlWriter.setOtherVariableResults(1, varOT1)) System.out.println("setOtherVariableResults");
		if(!osrlWriter.setOtherVariableResults(2, varOT1)) System.out.println("setOtherVariableResults");

		OtherConstraintResult[] conOT1 = new OtherConstraintResult[2];
		conOT1[0] = new OtherConstraintResult();	
		conOT1[0].con = new OtherConResult[2];
		conOT1[0].con[0] = new OtherConResult();
		conOT1[0].name = "conOT1 name";
		conOT1[0].description = "conOT1 description";
		conOT1[0].value = "conOT1 value";		
		conOT1[0].con[0].idx = 0;
		conOT1[0].con[0].lbValue = "aL";
		conOT1[0].con[0].ubValue = "aU";
		conOT1[0].con[0].value = "a";
		conOT1[0].con[1] = new OtherConResult();
		conOT1[0].con[1].idx = 1;
		conOT1[0].con[1].lbValue = "bL";
		conOT1[0].con[1].ubValue = "bU";
		conOT1[0].con[1].value = "b";
		conOT1[1] = new OtherConstraintResult();	
		conOT1[1].name = "conOT2 name";
		conOT1[1].description = "conOT2 description";
		conOT1[1].value = "conOT2 value";		
		conOT1[1].con = new OtherConResult[2];
		conOT1[1].con[0] = new OtherConResult();
		conOT1[1].con[0].idx = 0;
		conOT1[1].con[0].lbValue = "aL";
		conOT1[1].con[0].ubValue = "aU";
		conOT1[1].con[0].value = "a";
		conOT1[1].con[1] = new OtherConResult();
		conOT1[1].con[1].idx = 1;
		conOT1[1].con[1].lbValue = "bL";
		conOT1[1].con[1].ubValue = "bU";
		conOT1[1].con[1].value = "b";
		if(!osrlWriter.setOtherConstraintResults(0, conOT1)) System.out.println("setOtherConstraintResults");
		if(!osrlWriter.setOtherConstraintResults(1, conOT1)) System.out.println("setOtherConstraintResults");
		if(!osrlWriter.setOtherConstraintResults(2, conOT1)) System.out.println("setOtherConstraintResults");
		
		
		OtherObjectiveResult[] objOT1 = new OtherObjectiveResult[2];
		objOT1[0] = new OtherObjectiveResult();	
		objOT1[0].obj = new OtherObjResult[2];
		objOT1[0].obj[0] = new OtherObjResult();
		objOT1[0].name = "objOT1 name";
		objOT1[0].description = "objOT1 description";
		objOT1[0].value = "objOT1 value";		
		objOT1[0].obj[0].idx = -1;
		objOT1[0].obj[0].value = "a";
		objOT1[0].obj[1] = new OtherObjResult();
		objOT1[0].obj[1].idx = -2;
		objOT1[0].obj[1].value = "b";
		objOT1[1] = new OtherObjectiveResult();	
		objOT1[1].name = "objOT2 name";
		objOT1[1].description = "objOT2 description";
		objOT1[1].value = "objOT2 value";		
		objOT1[1].obj = new OtherObjResult[2];
		objOT1[1].obj[0] = new OtherObjResult();
		objOT1[1].obj[0].idx = -1;
		objOT1[1].obj[0].value = "a";
		objOT1[1].obj[1] = new OtherObjResult();
		objOT1[1].obj[1].idx = -2;
		objOT1[1].obj[1].value = "b";
		if(!osrlWriter.setOtherObjectiveResults(0, objOT1)) System.out.println("setOtherObjectiveResults");
		if(!osrlWriter.setOtherObjectiveResults(1, objOT1)) System.out.println("setOtherObjectiveResults");
		if(!osrlWriter.setOtherObjectiveResults(2, objOT1)) System.out.println("setOtherObjectiveResults");
		
		OtherOptimizationResult[] otherOpt = new OtherOptimizationResult[2];
		otherOpt[0] = new OtherOptimizationResult();
		otherOpt[0].name = "othetOpt0 name";
		otherOpt[0].value = "othetOpt0 value";
		otherOpt[0].description = "othetOpt0 description";
		otherOpt[1] = new OtherOptimizationResult();
		otherOpt[1].name = "othetOpt1 name";
		otherOpt[1].value = "othetOpt1 value";
		otherOpt[1].description = "othetOpt1 description";
		if(!osrlWriter.setOtherOptimizationResults(0, otherOpt)) System.out.println("setOtherOptimizationResults");
		if(!osrlWriter.setOtherOptimizationResults(1, otherOpt)) System.out.println("setOtherOptimizationResults");
		if(!osrlWriter.setOtherOptimizationResults(0, otherOpt)) System.out.println("setOtherOptimizationResults");
		
		OSaLReader osalReader = new OSaLReader(false);
		if(!osalReader.readFile(sAnalysisFileName)) System.out.println("reading");
		OSAnalysis osAnalysis = null;
		try {
			osAnalysis = osalReader.getOSAnalysis();
		} 
		catch (Exception e) {
			e.printStackTrace();
		}
		if(!osrlWriter.setOSAnalysis(osAnalysis)) System.out.println("setOSAnalysis");

		
		///////////////////////
		
		OSrLReader osrlReader = new OSrLReader(false);
		if(!osrlReader.readFile(sFileName)) System.out.println("reading");
		OSResult osResult = null;
		try {
			osResult = osrlReader.getOSResult();
			osrlWriter = new OSrLWriter();
			if(!osrlWriter.setOSResult(osResult)) System.out.println("setOSResult");
		} 
		catch (Exception e) {
			e.printStackTrace();
		}
		///////////////////////
		System.out.println(osrlWriter.writeToString());
	}//main
	
}//class OSrLWriter
