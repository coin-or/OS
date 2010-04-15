/**
 * @(#)OSbLWriter 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.representationparser;
import java.util.GregorianCalendar;
import java.util.Vector;

import org.optimizationservices.oscommon.datastructure.osgeneral.JobDependencies;
import org.optimizationservices.oscommon.datastructure.osprocess.JobOptimization;
import org.optimizationservices.oscommon.datastructure.osprocess.JobStatistics;
import org.optimizationservices.oscommon.datastructure.osprocess.OptimizationProcess;
import org.optimizationservices.oscommon.datastructure.osprocess.OptimizationUpdate;
import org.optimizationservices.oscommon.datastructure.osprocess.ProcessStatistics;
import org.optimizationservices.oscommon.localinterface.OSProcess;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.XMLUtil;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.ProcessingInstruction;
/**
 * The <code>OSpLWriter</code> class is used to construct an instance that follows 
 * the OSpL format. 
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */
public class OSpLWriter extends OSgLWriter{

	/**
	 * m_eOSpL holds the OSpL root element.
	 */
	protected Element m_eOSpL = null;

	/**
	 * m_eProcessHeader holds the 1st child element ProcessHeader of root element OSpL.
	 */
	protected Element m_eProcessHeader = null;
	
	/**
	 * m_eProcessData holds the 2nd child element processData of root element OSpL.
	 */
	protected Element m_eProcessData = null;

		
	/**
	 * constructor. 
	 *
	 */
	public OSpLWriter(){
		m_document = XMLUtil.createNewDocument();
		if(OSParameter.XSLT_LOCATION != null && OSParameter.XSLT_LOCATION.length() > 0){
			ProcessingInstruction xsltPI = m_document.createProcessingInstruction("xml-stylesheet",
	           "type=\"text/xsl\" href = \"" + OSParameter.XSLT_LOCATION + "OSpL.xslt\"");
			m_document.appendChild(xsltPI);     
		}
		m_eOSpL = createOSpLRoot();
		m_document.appendChild(m_eOSpL);
	}//constructor
	
	/**
	 * set the OSProcess, a standard os process interface. 
	 * @param osProcess holds the standard os process interface. 
	 * @return whether the OSProcess is set successfully. 
	 */
	public boolean setOSProcess(OSProcess osProcess) throws Exception{
		if(osProcess.processHeader.request != null){
			if(!setRequestAction(osProcess.getRequestAction())){ 
	   			throw new Exception("setRequestAction Unsuccessful");
			}
			if(!setRequestDescription(osProcess.getRequestDescription())){ 
	   			throw new Exception("setRequestDescription Unsuccessful");
			}
		}
		else if(osProcess.processHeader.response != null){
			if(!setResponseStatus(osProcess.getResponseStatus())){ 
	   			throw new Exception("setResponseStatus Unsuccessful");
			}
			if(!setResponseDescription(osProcess.getResponseDescription())){ 
	   			throw new Exception("setResponseDescription Unsuccessful");
			}
		}
		if(!setServiceURI(osProcess.getServiceURI())){ 
   			throw new Exception("setServiceURI Unsuccessful");
		}
		if(!setServiceName(osProcess.getServiceName())){ 
   			throw new Exception("setServiceName Unsuccessful");
		}
		if(!setProcessTime(osProcess.getProcessTime())){ 
   			throw new Exception("setProcessTime Unsuccessful");
		}
		if(!setProcessMessage(osProcess.getProcessMessage())){ 
   			throw new Exception("setProcessMessage Unsuccessful");
		}
		if(!setProcessStatistics(osProcess.getProcessStatistics())){ 
   			throw new Exception("setProcessStatistics Unsuccessful");
		}
		if(!setOptimizationProcess(osProcess.getOptimizationProcess())){ 
   			throw new Exception("setOptimizationProcess Unsuccessful");
		}
		if(osProcess.processData.other != null && osProcess.processData.other.length > 0){
			int n = osProcess.processData.other.length;
			String[] msNames = new String[n];
			String[] msValues = new String[n];
			String[] msDescriptions = new String[n];
			for(int i = 0; i < n; i++){
				msNames[i] = osProcess.processData.other[i].name;
				msValues[i] = osProcess.processData.other[i].value;
				msDescriptions[i] = osProcess.processData.other[i].description;
			}
			if(!setOtherProcesses(msNames, msValues, msDescriptions)){
				throw new Exception("setOtherProcesses Info Unsuccessful");
			}			
		}
   		return true;
	}//setOSProcess


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
		try{
			if(action != null && action.length() > 0){
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
				XMLUtil.removeChildrenByName(m_eProcessHeader, "response");
				Element eRequest = (Element)XMLUtil.findChildNode(m_eProcessHeader, "request");
				if(eRequest == null){
					eRequest = m_document.createElement("request");	
					eRequest.setAttribute("action", action);
					m_eProcessHeader.insertBefore(eRequest, m_eProcessHeader.getFirstChild());				}
				else{
					eRequest.setAttribute("action", action);
				}
			}
			else{
				XMLUtil.removeChildrenByName(m_eProcessHeader, "request");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setRequestAction

	
 	/**
	 * Set the request description.
	 * 
	 * @param description holds the request description
	 * @return whether the requestion description is set successfully.  
	 */
	public boolean setRequestDescription(String description){
		try{
			if(description != null && description.length() > 0){
				XMLUtil.removeChildrenByName(m_eProcessHeader, "response");
			}
			Element eRequest = (Element)XMLUtil.findChildNode(m_eProcessHeader, "request");
			if(eRequest == null){
				if(description == null || description.length() <= 0){
					return true;
				}
				eRequest = m_document.createElement("request");	
				eRequest.appendChild(m_document.createTextNode(description));
				m_eProcessHeader.insertBefore(eRequest, m_eProcessHeader.getFirstChild());				}
			else{
				if(description == null || description.length() <= 0){
					XMLUtil.removeAllChildren(eRequest);
					return true;
				}
				XMLUtil.removeAllChildren(eRequest);
				eRequest.appendChild(m_document.createTextNode(description));
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setRequestDescription
	
 	/**
	 * Set the response status.
	 * 
	 * @param status holds the response status, which can be:
	 * success, error, warning. 
	 * @return  whether the response status is set successfully.
	 */
	public boolean setResponseStatus(String status){
		try{
			if(status != null && status.length() > 0){
				if(!status.equals("success") && 
						   !status.equals("error") &&
						   !status.equals("warning")) return false;		 
				XMLUtil.removeChildrenByName(m_eProcessHeader, "request");
				Element eResponse = (Element)XMLUtil.findChildNode(m_eProcessHeader, "response");
				if(eResponse == null){
					eResponse = m_document.createElement("response");	
					eResponse.setAttribute("status", status);
					m_eProcessHeader.insertBefore(eResponse, m_eProcessHeader.getFirstChild());				}
				else{
					eResponse.setAttribute("status", status);
				}
			}
			else{
				XMLUtil.removeChildrenByName(m_eProcessHeader, "response");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setResponseStatus
	
 	/**
	 * Set the response description.
	 * 
	 * @param description holds the response description
	 * @return  whether the response description is set successfully.   
	 */
	public boolean setResponseDescription(String description){
		try{
			if(description != null && description.length() > 0){
				XMLUtil.removeChildrenByName(m_eProcessHeader, "request");
			}
			Element eResponse = (Element)XMLUtil.findChildNode(m_eProcessHeader, "response");
			if(eResponse == null){
				if(description == null || description.length() <= 0){
					return true;
				}
				eResponse = m_document.createElement("response");	
				eResponse.appendChild(m_document.createTextNode(description));
				m_eProcessHeader.insertBefore(eResponse, m_eProcessHeader.getFirstChild());				}
			else{
				if(description == null || description.length() <= 0){
					XMLUtil.removeAllChildren(eResponse);
					return true;
				}
				XMLUtil.removeAllChildren(eResponse);
				eResponse.appendChild(m_document.createTextNode(description));
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setResponseDescription
	
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
				Element eServiceURI = (Element)XMLUtil.findChildNode(m_eProcessHeader, "serviceURI");
				if(eServiceURI == null){
					eServiceURI = m_document.createElement("serviceURI");					
					eServiceURI.appendChild(m_document.createTextNode(serviceURI));
					nodeRef = XMLUtil.findChildNode(m_eProcessHeader, "serviceName");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(m_eProcessHeader, "time");
						if(nodeRef == null){
							nodeRef = XMLUtil.findChildNode(m_eProcessHeader, "message");
						}
					}
					m_eProcessHeader.insertBefore(eServiceURI, nodeRef);
				}
				else{
					XMLUtil.setElementValue(eServiceURI, serviceURI);
				}
			}
			else{
				XMLUtil.removeChildrenByName(m_eProcessHeader, "serviceURI");
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
				Element eServiceName = (Element)XMLUtil.findChildNode(m_eProcessHeader, "serviceName");
				if(eServiceName == null){
					eServiceName = m_document.createElement("serviceName");					
					eServiceName.appendChild(m_document.createTextNode(serviceName));
					nodeRef = XMLUtil.findChildNode(m_eProcessHeader, "time");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(m_eProcessHeader, "message");
					}
					m_eProcessHeader.insertBefore(eServiceName, nodeRef);
				}
				else{
					XMLUtil.setElementValue(eServiceName, serviceName);
				}
			}
			else{
				XMLUtil.removeChildrenByName(m_eProcessHeader, "serviceName");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setServiceName
	
   	/**
	 * Set time of the last process update.
	 * 
	 * @param time holds the time of the last process update.
	 * @return whether process time is set successfully. 
	 */
	public boolean setProcessTime(GregorianCalendar time){
		try{
			Node nodeRef = null;
			if(time != null){
				Element eTime = (Element)XMLUtil.findChildNode(m_eProcessHeader, "time");
				if(eTime == null){
					eTime = m_document.createElement("time");					
					eTime.appendChild(m_document.createTextNode(XMLUtil.createXSDateTime(time)));
					nodeRef = XMLUtil.findChildNode(m_eProcessHeader, "message");
					m_eProcessHeader.insertBefore(eTime, nodeRef);
				}
				else{
					XMLUtil.setElementValue(eTime, XMLUtil.createXSDateTime(time));
				}
			}
			else{
				XMLUtil.removeChildrenByName(m_eProcessHeader, "time");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setProcessTime
	
   	/**
	 * Set the process message. 
	 * 
	 * @param message holds the process message. 
	 * @return whether process message is set successfully. 
	 */
	public boolean setProcessMessage(String message){
		try{
			Node nodeRef = null;
			if(message != null && message.length() > 0){
				Element eMessage = (Element)XMLUtil.findChildNode(m_eProcessHeader, "message");
				if(eMessage == null){
					eMessage = m_document.createElement("message");					
					eMessage.appendChild(m_document.createTextNode(message));
					m_eProcessHeader.insertBefore(eMessage, nodeRef);
				}
				else{
					XMLUtil.setElementValue(eMessage, message);
				}
			}
			else{
				XMLUtil.removeChildrenByName(m_eProcessHeader, "message");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setProcessMessage
	
	/**
	 * Set the process statistics. 
	 * 
	 * @param processStatistics holds the process statistics. 
	 * @return whether the process statistics is set successfully. 
	 */
	public boolean setProcessStatistics(ProcessStatistics processStatistics){
		if(processStatistics == null){
			XMLUtil.removeChildrenByName(m_eProcessData, "statistics");
			return true;
		}
		Element eStatistics = (Element)XMLUtil.findChildNode(m_eProcessData, "statistics");
		if(eStatistics != null){
			XMLUtil.removeChildrenByName(m_eProcessData, "statistics");
		}
		eStatistics = m_document.createElement("statistics");
		m_eProcessData.insertBefore(eStatistics, m_eProcessData.getFirstChild());
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
					if(job.serviceURI != null && job.serviceURI.length() > 0){
						Element eServiceURI = m_document.createElement("serviceURI");
						eServiceURI.appendChild(m_document.createTextNode(job.serviceURI));	
						eJob.appendChild(eServiceURI);
					}
					if(job.userName != null && job.userName.length() > 0){
						Element eUserName = m_document.createElement("userName");
						eUserName.appendChild(m_document.createTextNode(job.userName));	
						eJob.appendChild(eUserName);
					}

					if(job.submitTime != null && job.submitTime.get(GregorianCalendar.YEAR) > 1970){
						Element eSubmitTime = m_document.createElement("submitTime");
						eSubmitTime.appendChild(m_document.createTextNode(XMLUtil.createXSDateTime(job.submitTime)));	
						eJob.appendChild(eSubmitTime);
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
					if(job.requiredDirectories != null && job.requiredDirectories.path != null && job.requiredDirectories.path.length > 0){
						Element eRequiredDirectories = m_document.createElement("requiredDirectories");
						int iPaths = processStatistics.jobs.job[i].requiredDirectories.path.length;
						for(int j = 0; j < iPaths; j++){
							Element ePath = m_document.createElement("path");
							ePath.appendChild(m_document.createTextNode(job.requiredDirectories.path[j]));	
							eRequiredDirectories.appendChild(ePath);
						}						
						eJob.appendChild(eRequiredDirectories);
					}
					if(job.requiredFiles != null && job.requiredFiles.path != null && job.requiredFiles.path.length > 0){
						Element eRequiredFiles = m_document.createElement("requiredFiles");
						int iPaths = processStatistics.jobs.job[i].requiredFiles.path.length;
						for(int j = 0; j < iPaths; j++){
							Element ePath = m_document.createElement("path");
							ePath.appendChild(m_document.createTextNode(job.requiredFiles.path[j]));	
							eRequiredFiles.appendChild(ePath);
						}						
						eJob.appendChild(eRequiredFiles);
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
		Element eStatistics = (Element)XMLUtil.findChildNode(m_eProcessData, "statistics");
		if(eStatistics == null){
			eStatistics = m_document.createElement("statistics");
			m_eProcessData.insertBefore(eStatistics, m_eProcessData.getFirstChild());
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
	 * Set the available disk space (in bytes). 
	 * @param availableDiskSpace holds the available disk space. 
	 * @return whether the available disk space is set successfully.
	 */
	public boolean setAvailableDiskSpace(double availableDiskSpace){
		Element eStatistics = (Element)XMLUtil.findChildNode(m_eProcessData, "statistics");
		if(eStatistics == null){
			eStatistics = m_document.createElement("statistics");
			m_eProcessData.insertBefore(eStatistics, m_eProcessData.getFirstChild());
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
		Element eStatistics = (Element)XMLUtil.findChildNode(m_eProcessData, "statistics");
		if(eStatistics == null){
			eStatistics = m_document.createElement("statistics");
			m_eProcessData.insertBefore(eStatistics, m_eProcessData.getFirstChild());
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
		Element eStatistics = (Element)XMLUtil.findChildNode(m_eProcessData, "statistics");
		if(eStatistics == null){
			eStatistics = m_document.createElement("statistics");
			m_eProcessData.insertBefore(eStatistics, m_eProcessData.getFirstChild());
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
	 * @return whether the total jobs received so far is set successfully.
	 */
	public boolean setTotalJobsSoFar(int totalJobsSoFar){
		Element eStatistics = (Element)XMLUtil.findChildNode(m_eProcessData, "statistics");
		if(eStatistics == null){
			eStatistics = m_document.createElement("statistics");
			m_eProcessData.insertBefore(eStatistics, m_eProcessData.getFirstChild());
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
	 * Set the time that the last job ended. 
	 * @param timeLastJobEnded holds the time (xs:dateTime) that the last job ended. 
	 * @return whether the time last job ended is set successfully.
	 */
	public boolean setTimeLastJobEnded(GregorianCalendar timeLastJobEnded){
		Element eStatistics = (Element)XMLUtil.findChildNode(m_eProcessData, "statistics");
		if(eStatistics == null){
			eStatistics = m_document.createElement("statistics");
			m_eProcessData.insertBefore(eStatistics, m_eProcessData.getFirstChild());
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
	 * Set the time that the last job took (in seconds). 
	 * @param timeLastJobTook holds the number of seconds that the last job took. 
	 * @return whether the time last job took is set successfully.
	 */
	public boolean setTimeLastJobTook(double timeLastJobTook){
		Element eStatistics = (Element)XMLUtil.findChildNode(m_eProcessData, "statistics");
		if(eStatistics == null){
			eStatistics = m_document.createElement("statistics");
			m_eProcessData.insertBefore(eStatistics, m_eProcessData.getFirstChild());
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
	 * Set the time that service last started. 
	 * @param timeServiceStarted holds the time (xs:dateTime) that the service last started. 
	 * @return whether the time the service started is set successfully.
	 */
	public boolean setTimeServiceStarted(GregorianCalendar timeServiceStarted){
		Element eStatistics = (Element)XMLUtil.findChildNode(m_eProcessData, "statistics");
		if(eStatistics == null){
			eStatistics = m_document.createElement("statistics");
			m_eProcessData.insertBefore(eStatistics, m_eProcessData.getFirstChild());
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
	 * Set the service utilization ([0, 1]). 
	 * @param serviceUtilization holds the service utilization (busy time/total time). 
	 * @return whether service utilization is set successfully.
	 */
	public boolean setServiceUtilization(double serviceUtilization){
		Element eStatistics = (Element)XMLUtil.findChildNode(m_eProcessData, "statistics");
		if(eStatistics == null){
			eStatistics = m_document.createElement("statistics");
			m_eProcessData.insertBefore(eStatistics, m_eProcessData.getFirstChild());
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
		Element eStatistics = (Element)XMLUtil.findChildNode(m_eProcessData, "statistics");
		if(eStatistics == null){
			eStatistics = m_document.createElement("statistics");
			m_eProcessData.insertBefore(eStatistics, m_eProcessData.getFirstChild());
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
					if(jobStatistics[i].serviceURI != null && jobStatistics[i].serviceURI.length() > 0){
						Element eServiceURI = m_document.createElement("serviceURI");
						eServiceURI.appendChild(m_document.createTextNode(jobStatistics[i].serviceURI));	
						eJob.appendChild(eServiceURI);
					}
					if(jobStatistics[i].userName != null && jobStatistics[i].userName.length() > 0){
						Element eUserName = m_document.createElement("userName");
						eUserName.appendChild(m_document.createTextNode(jobStatistics[i].userName));	
						eJob.appendChild(eUserName);
					}
					if(jobStatistics[i].submitTime != null && jobStatistics[i].submitTime.get(GregorianCalendar.YEAR) > 1970){
						Element eSubmitTime = m_document.createElement("submitTime");
						eSubmitTime.appendChild(m_document.createTextNode(XMLUtil.createXSDateTime(jobStatistics[i].submitTime)));	
						eJob.appendChild(eSubmitTime);
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
					if(jobStatistics[i].requiredDirectories != null && jobStatistics[i].requiredDirectories.path != null && jobStatistics[i].requiredDirectories.path.length > 0){
						Element eRequiredDirectories = m_document.createElement("requiredDirectories");
						int iPaths = jobStatistics[i].requiredDirectories.path.length;
						for(int j = 0; j < iPaths; j++){
							Element ePath = m_document.createElement("path");
							ePath.appendChild(m_document.createTextNode(jobStatistics[i].requiredDirectories.path[j]));	
							eRequiredDirectories.appendChild(ePath);
						}						
						eJob.appendChild(eRequiredDirectories);
					}
					if(jobStatistics[i].requiredFiles != null && jobStatistics[i].requiredFiles.path != null && jobStatistics[i].requiredFiles.path.length > 0){
						Element eRequiredFiles = m_document.createElement("requiredFiles");
						int iPaths = jobStatistics[i].requiredFiles.path.length;
						for(int j = 0; j < iPaths; j++){
							Element ePath = m_document.createElement("path");
							ePath.appendChild(m_document.createTextNode(jobStatistics[i].requiredFiles.path[j]));	
							eRequiredFiles.appendChild(ePath);
						}						
						eJob.appendChild(eRequiredFiles);
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
		Node nodeRef = null;
		if(optimizationProcess == null || optimizationProcess.job == null ||  optimizationProcess.job.length <= 0){
			XMLUtil.removeChildrenByName(m_eProcessData, "optimization");
			return true;
		}
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eProcessData, "optimization");
		if(eOptimization == null){
			eOptimization = m_document.createElement("optimization");
			nodeRef = XMLUtil.findChildNode(m_eProcessData, "statistics");			
			if(nodeRef != null){
				m_eProcessData.insertBefore(eOptimization, nodeRef.getNextSibling());			
			}
			else{
				m_eProcessData.insertBefore(eOptimization, m_eProcessData.getFirstChild());
			}			
		}
		XMLUtil.removeChildrenByName(eOptimization, "job");
		int iJobs = optimizationProcess.job.length;
		for(int i = 0; i < iJobs; i++){
			if(optimizationProcess.job[i] == null) continue;
			if(optimizationProcess.job[i].jobID == null) continue;
			if(optimizationProcess.job[i].standard == null && optimizationProcess.job[i].osrl == null) continue;
			Element eJob = m_document.createElement("job");
			eOptimization.appendChild(eJob);
			eJob.setAttribute("jobID", optimizationProcess.job[i].jobID);
			
			
			if(optimizationProcess.job[i].standard != null && 
					optimizationProcess.job[i].standard.update != null && 
					optimizationProcess.job[i].standard.update.length > 0){
				Element eStandard = m_document.createElement("standard");
				int iUpdates = optimizationProcess.job[i].standard.update.length;
				OptimizationUpdate update; 
				for(int j = 0; j < iUpdates; j++){
					update = optimizationProcess.job[i].standard.update[j];				
					if(update != null){
						Element eUpdate = m_document.createElement("update");
						if(update.ObjectiveIdx <= 0){
							eUpdate.setAttribute("objectiveIdx", update.ObjectiveIdx+"");
						}
						else{
							eUpdate.setAttribute("objectiveIdx", "0");
						}
						if(!Double.isNaN(update.updatedObjectiveValue)){
							Element eUpdatedObjectiveValue = m_document.createElement("updatedObjectiveValue");
							if(update.updatedObjectiveValue == Double.POSITIVE_INFINITY){
								eUpdatedObjectiveValue.appendChild(m_document.createTextNode("INF"));	
							}
							if(update.updatedObjectiveValue == Double.NEGATIVE_INFINITY){
								eUpdatedObjectiveValue.appendChild(m_document.createTextNode("-INF"));	
							}
							else{
								eUpdatedObjectiveValue.appendChild(m_document.createTextNode(update.updatedObjectiveValue + ""));	
							}
							eUpdate.appendChild(eUpdatedObjectiveValue);
						}
						if(!Double.isNaN(update.updatedObjectiveLowerBound)){
							Element eUpdatedObjectiveLowerBound = m_document.createElement("updatedObjectiveLowerBound");
							if(update.updatedObjectiveLowerBound == Double.POSITIVE_INFINITY){
								eUpdatedObjectiveLowerBound.appendChild(m_document.createTextNode("INF"));	
							}
							if(update.updatedObjectiveLowerBound == Double.NEGATIVE_INFINITY){
								eUpdatedObjectiveLowerBound.appendChild(m_document.createTextNode("-INF"));	
							}
							else{
								eUpdatedObjectiveLowerBound.appendChild(m_document.createTextNode(update.updatedObjectiveLowerBound + ""));	
							}
							eUpdate.appendChild(eUpdatedObjectiveLowerBound);
						}
						if(!Double.isNaN(update.updatedObjectiveUpperBound)){
							Element eUpdatedObjectiveUpperBound = m_document.createElement("updatedObjectiveUpperBound");
							if(update.updatedObjectiveUpperBound == Double.POSITIVE_INFINITY){
								eUpdatedObjectiveUpperBound.appendChild(m_document.createTextNode("INF"));	
							}
							if(update.updatedObjectiveUpperBound == Double.NEGATIVE_INFINITY){
								eUpdatedObjectiveUpperBound.appendChild(m_document.createTextNode("-INF"));	
							}
							else{
								eUpdatedObjectiveUpperBound.appendChild(m_document.createTextNode(update.updatedObjectiveUpperBound + ""));	
							}
							eUpdate.appendChild(eUpdatedObjectiveUpperBound);
						}

						if(update.updatedVariableValues != null && update.updatedVariableValues.var != null && update.updatedVariableValues.var.length > 0){
							Element eUpdatedVariableValues = m_document.createElement("updatedVariableValues");
							int iVars = update.updatedVariableValues.var.length;
							for(int k = 0; k < iVars; k++){
								Element eVar = m_document.createElement("var");
								if(update.updatedVariableValues.var[k] == Double.POSITIVE_INFINITY){
									eVar.appendChild(m_document.createTextNode("INF"));	
								}
								else if(update.updatedVariableValues.var[k] == Double.NEGATIVE_INFINITY){
									eVar.appendChild(m_document.createTextNode("-INF"));	
								}
								else if(Double.isNaN(update.updatedVariableValues.var[k])){
									eVar.appendChild(m_document.createTextNode("NaN"));	
								}
								else{
									eVar.appendChild(m_document.createTextNode(update.updatedVariableValues.var[k]+""));	
								}
								eUpdatedVariableValues.appendChild(eVar);
							}						
							eUpdate.appendChild(eUpdatedVariableValues);
						}

						
						if(update.updatedVariableValuesString != null && update.updatedVariableValuesString.var != null && update.updatedVariableValuesString.var.length > 0){
							Element eUpdatedVariableValuesString = m_document.createElement("updatedVariableValuesString");
							int iVars = update.updatedVariableValuesString.var.length;
							for(int k = 0; k < iVars; k++){
								Element eVar = m_document.createElement("var");
								eVar.appendChild(m_document.createTextNode(update.updatedVariableValuesString.var[k]));	
								eUpdatedVariableValuesString.appendChild(eVar);
							}						
							eUpdate.appendChild(eUpdatedVariableValuesString);
						}

						if(update.updatedVariableReducedCosts != null && update.updatedVariableReducedCosts.var != null && update.updatedVariableReducedCosts.var.length > 0){
							Element eUpdatedVariableReducedCosts = m_document.createElement("updatedVariableReducedCosts");
							int iVars = update.updatedVariableReducedCosts.var.length;
							for(int k = 0; k < iVars; k++){
								Element eVar = m_document.createElement("var");
								if(update.updatedVariableReducedCosts.var[k] == Double.POSITIVE_INFINITY){
									eVar.appendChild(m_document.createTextNode("INF"));	
								}
								else if(update.updatedVariableReducedCosts.var[k] == Double.NEGATIVE_INFINITY){
									eVar.appendChild(m_document.createTextNode("-INF"));	
								}
								else if(Double.isNaN(update.updatedVariableReducedCosts.var[k])){
									eVar.appendChild(m_document.createTextNode("NaN"));	
								}
								else{
									eVar.appendChild(m_document.createTextNode(update.updatedVariableReducedCosts.var[k]+""));	
								}
								eUpdatedVariableReducedCosts.appendChild(eVar);
							}						
							eUpdate.appendChild(eUpdatedVariableReducedCosts);
						}

						if(update.updatedConstraintValues != null && update.updatedConstraintValues.con != null && update.updatedConstraintValues.con.length > 0){
							Element eUpdatedConstraintValues = m_document.createElement("updatedConstraintValues");
							int iCons = update.updatedConstraintValues.con.length;
							for(int k = 0; k < iCons; k++){
								Element eCon = m_document.createElement("con");
								if(update.updatedConstraintValues.con[k] == Double.POSITIVE_INFINITY){
									eCon.appendChild(m_document.createTextNode("INF"));	
								}
								else if(update.updatedConstraintValues.con[k] == Double.NEGATIVE_INFINITY){
									eCon.appendChild(m_document.createTextNode("-INF"));	
								}
								else if(Double.isNaN(update.updatedConstraintValues.con[k])){
									eCon.appendChild(m_document.createTextNode("NaN"));	
								}
								else{
									eCon.appendChild(m_document.createTextNode(update.updatedConstraintValues.con[k]+""));	
								}
								eUpdatedConstraintValues.appendChild(eCon);
							}						
							eUpdate.appendChild(eUpdatedConstraintValues);
						}

						if(update.updatedDualValues != null && update.updatedDualValues.con != null && update.updatedDualValues.con.length > 0){
							Element eUpdatedDualValues = m_document.createElement("updatedDualValues");
							int iCons = update.updatedDualValues.con.length;
							for(int k = 0; k < iCons; k++){
								Element eCon = m_document.createElement("con");
								if(update.updatedDualValues.con[k] == Double.POSITIVE_INFINITY){
									eCon.appendChild(m_document.createTextNode("INF"));	
								}
								else if(update.updatedDualValues.con[k] == Double.NEGATIVE_INFINITY){
									eCon.appendChild(m_document.createTextNode("-INF"));	
								}
								else if(Double.isNaN(update.updatedDualValues.con[k])){
									eCon.appendChild(m_document.createTextNode("NaN"));	
								}
								else{
									eCon.appendChild(m_document.createTextNode(update.updatedDualValues.con[k]+""));	
								}
								eUpdatedDualValues.appendChild(eCon);
							}						
							eUpdate.appendChild(eUpdatedDualValues);
						}
						
						eStandard.appendChild(eUpdate);
					}
				}
				eJob.appendChild(eStandard);
			}
			
			
			
			
			
			if(optimizationProcess.job[i].osrl != null){
				OSrLWriter osrlWriter = new OSrLWriter();
				try {
					osrlWriter.setOSResult(optimizationProcess.job[i].osrl);
				} 
				catch (Exception e) {
					e.printStackTrace();
					return false;
				}
				Element eOSrL =  (Element)m_document.importNode(osrlWriter.m_eOSrL, true);
				XMLUtil.removeAllAttributes(eOSrL);
				eJob.appendChild(eOSrL);
			}
		}
		return true;
	}//setOptimizationProcess
	
	/**
	 * Set the other process related elements. 
	 * 
	 * @param names holds the names of the other processes. It is required. 
	 * @param values holds the values of the other processs, empty String "" if no value for an process.
	 * @param descriptions holds the descriptions of the other processs, empty String "" if no value for an process, null for
	 * the entire array if none of the processs have descriptions.
	 * @return whether the other processs element construction is successful.
	 */
	public boolean setOtherProcesses(String[] names, String[] values, String[] descriptions){
		if(names == null) return false;
		if(values == null) return false;
		if(names.length != values.length) return false;
		if(descriptions != null && names.length != descriptions.length) return false;
		for(int i = 0; i < names.length; i++){
			addOtherProcess(names[i], values[i], (descriptions==null)?"":descriptions[i]);
		}
		return true;
	}//setOtherProcesses
	
	/**
	 * Add an other process element. 
	 * 
	 * @param name holds the name of the other process element. It is required. 
	 * @param value holds the value of the other process element, empty String "" if none. 
	 * @param description holds the description of the other process element, empty String "" if none. 
	 * @return whether the other process element is added successfully.
	 */
	public boolean addOtherProcess(String name, String value, String description){
		if(name == null) return false;
		Vector<Element> vElements = XMLUtil.getChildElementsByTagName(m_eProcessData, "other");
		Element eOther;
		int iNls = vElements==null?0:vElements.size();
		for(int i = 0; i < iNls; i++){
			eOther = (Element)vElements.elementAt(i);
			if(eOther.getAttribute("name").equals(name)){
				m_eProcessData.removeChild(eOther);
				break;
			}
		}
		eOther = createOther(name, value, description);
		m_eProcessData.appendChild(eOther);
		return true;
	}//addOtherProcess

	
	/**
	 * Create the OSpL root element and its most basic required structure.
	 * 
	 * @return the OSpL element.
	 */
	protected Element createOSpLRoot(){
		Element eOSpL = XMLUtil.createOSxLRootElement(m_document, "ospl");
		m_eProcessHeader = createProcessHeader();
		eOSpL.appendChild(m_eProcessHeader);
		m_eProcessData = createProcessData();
		eOSpL.appendChild(m_eProcessData);
		return eOSpL;
	}//createOSpLRoot
	
	/**
	 * Create the processHeader element and its most basic required structure.
	 * 
	 * @return the processHeader element.
	 */
	protected Element createProcessHeader(){
		Element eProcessHeader = m_document.createElement("processHeader");
		return eProcessHeader;
	}//createProcessHeader
	
	/**
	 * Create the processData element and its most basic required structure.
	 * 
	 * @return the processData element.
	 */
	protected Element createProcessData(){
		Element eProcessData = m_document.createElement("processData");
		return eProcessData;
	}//createProcessData
	
	/**
	 * Create the other element and its most basic required structure.
	 * 
	 * @param name the name of the other element. 
	 * @param value the value of the other element, empty String "" if no value.
	 * @param description holds the description of the other process element, empty String "" if none. 
	 * @return the other element.
	 */
	protected Element createOther(String name, String value, String description){
		Element eOther = m_document.createElement("other");
		eOther.setAttribute("name", name);
		eOther.setAttribute("description", (description==null)?"":description);
		if(value != null && value.length() > 0){
			eOther.appendChild(m_document.createTextNode(value));
		}
		return eOther;
	}//createOther
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		OSpLWriter osplWriter = new OSpLWriter();
		String sFileName = OSParameter.CODE_HOME + "OSRepository/test/ospl/ospl.ospl";

		if(!osplWriter.setRequestAction("getAll")) System.out.println("setRequestAction!");
		if(!osplWriter.setRequestAction("setAll")) System.out.println("setRequestAction!");
		if(!osplWriter.setRequestDescription("setRequestDescription")) System.out.println("setRequestAction!");
		if(!osplWriter.setResponseStatus("success")) System.out.println("setResponseStatus!");
		if(!osplWriter.setResponseDescription("successfully done")) System.out.println("setResponseDescription!");
		
		if(!osplWriter.setProcessMessage("my message")) System.out.println("message!");
		if(!osplWriter.setProcessMessage("")) System.out.println("message!");
		if(!osplWriter.setServiceURI("my uri")) System.out.println("serviceURI!");
		if(!osplWriter.setServiceName("my name")) System.out.println("serviceName!");
		if(!osplWriter.setProcessTime(new GregorianCalendar())) System.out.println("time!");
		
		if(!osplWriter.setCurrentState("busy")) System.out.println("setCurrentState!");
		if(!osplWriter.setAvailableDiskSpace(1.2)) System.out.println("setAvailableDiskSpace!");
		if(!osplWriter.setAvailableMemory(3.4)) System.out.println("setAvailableMemory!");
		if(!osplWriter.setCurrentJobCount(0)) System.out.println("setCurrentJobCount!");
		if(!osplWriter.setTotalJobsSoFar(100)) System.out.println("setTotalJobsSoFar!");
		if(!osplWriter.setTimeLastJobEnded(new GregorianCalendar(2006, 1, 31, 15, 3, 4))) System.out.println("setTimeLastJobEnded!");
		if(!osplWriter.setTimeLastJobTook(200.4)) System.out.println("setTimeLastJobTook!");
		if(!osplWriter.setTimeServiceStarted(new GregorianCalendar(2003, 1, 31, 15, 3, 4))) System.out.println("setTimeServiceStarted!");
		if(!osplWriter.setServiceUtilization(1.3)) System.out.println("setServiceUtilization!");
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
		
		if(!osplWriter.setJobStatistics(jobstatistics)) System.out.println("setJobStatistics!");
//		ProcessStatistics processStatistics = new ProcessStatistics();
//		processStatistics.jobs = new Jobs();
//		processStatistics.jobs.job = jobstatistics;
//		if(!osplWriter.setProcessStatistics(processStatistics)) System.out.println("setJobStatistics!");
		
//		JobOptimization[] mJobOptimization = new JobOptimization[1];
//		mJobOptimization[0] = new JobOptimization();
//		mJobOptimization[0].jobID = "88888";
//		mJobOptimization[0].osrl = new OSResult();
//		if(!osplWriter.setOptimizationProcess(mJobOptimization)) System.out.println("setJobStatistics!");

		String[] msOtherProcessNames = {"other name 0", "other name 1"};
		String[] msOtherProcessValues = {"other value 0", "other value 1"};
		if(!osplWriter.setOtherProcesses(msOtherProcessNames, msOtherProcessValues, null)) System.out.println("set other!");
	
		
		if(!osplWriter.addOtherProcess("other name 2", "other value 2", null)) System.out.println("add other!");
		if(!osplWriter.addOtherProcess("other name 3", "other value 3", "other description 3")) System.out.println("add other!");

		////////////////////

		OSpLReader osplReader = new OSpLReader(false);
		if(!osplReader.readFile(sFileName)) System.out.println("reading");
		OSProcess osProcess;
		try {
			osProcess = osplReader.getOSProcess();
			if(!osplWriter.setOSProcess(osProcess)) System.out.println("set osProcess");
		} 
		catch (Exception e) {
			e.printStackTrace();
		}
		////////////////////
		
		//osplWriter.writeToStandardOutput();
		System.out.println(osplWriter.writeToString());
				
	}//main
	
}//class OSpLWriter
