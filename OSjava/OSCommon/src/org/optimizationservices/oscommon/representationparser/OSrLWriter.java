/**
 * @(#)OSrLWriter 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.representationparser;
import java.util.GregorianCalendar;
import java.util.Vector;

import org.optimizationservices.oscommon.datastructure.osresult.BasStatus;
import org.optimizationservices.oscommon.datastructure.osresult.CPUNumber;
import org.optimizationservices.oscommon.datastructure.osresult.CPUSpeed;
import org.optimizationservices.oscommon.datastructure.osresult.DiskSpace;
import org.optimizationservices.oscommon.datastructure.osresult.DualVarValue;
import org.optimizationservices.oscommon.datastructure.osresult.DualVariableValues;
import org.optimizationservices.oscommon.datastructure.osresult.GeneralStatus;
import org.optimizationservices.oscommon.datastructure.osresult.GeneralSubstatus;
import org.optimizationservices.oscommon.datastructure.osresult.MemorySize;
import org.optimizationservices.oscommon.datastructure.osresult.ObjValue;
import org.optimizationservices.oscommon.datastructure.osresult.ObjectiveValues;
import org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolution;
import org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolutionStatus;
import org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolutionSubstatus;
import org.optimizationservices.oscommon.datastructure.osresult.OtherConResult;
import org.optimizationservices.oscommon.datastructure.osresult.OtherConstraintResult;
import org.optimizationservices.oscommon.datastructure.osresult.OtherObjResult;
import org.optimizationservices.oscommon.datastructure.osresult.OtherObjectiveResult;
import org.optimizationservices.oscommon.datastructure.osresult.OtherResults;
import org.optimizationservices.oscommon.datastructure.osresult.OtherSolutionResult;
import org.optimizationservices.oscommon.datastructure.osresult.OtherVarResult;
import org.optimizationservices.oscommon.datastructure.osresult.OtherVariableResult;
import org.optimizationservices.oscommon.datastructure.osresult.SolverOutput;
import org.optimizationservices.oscommon.datastructure.osresult.TimingInformation;
import org.optimizationservices.oscommon.datastructure.osresult.VarStringValue;
import org.optimizationservices.oscommon.datastructure.osresult.VarValue;
import org.optimizationservices.oscommon.datastructure.osresult.VariableValues;
import org.optimizationservices.oscommon.localinterface.OSAnalysis;
import org.optimizationservices.oscommon.localinterface.OSResult;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.XMLUtil;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.ProcessingInstruction;

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
		if(OSParameter.XSLT_LOCATION != null && OSParameter.XSLT_LOCATION.length() > 0){
			ProcessingInstruction xsltPI = m_document.createProcessingInstruction("xml-stylesheet",
					"type=\"text/xsl\" href = \"" + OSParameter.XSLT_LOCATION + "OSrL.xslt\"");
			m_document.appendChild(xsltPI);     
		}
		m_eOSrL = XMLUtil.createOSxLRootElement(m_document, "osrl");		
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
		if(!setGeneralMessage(osResult.getGeneralMessage())){ 
			throw new Exception("setGeneralMessage Unsuccessful");
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
		if(!setSolverInvoked(osResult.getSolverInvoked())){ 
			throw new Exception("setSolverInvoked Unsuccessful");
		}
		if(!setResultTimeStamp(osResult.getResultTimeStamp())){ 
			throw new Exception("setResultTimeStamp Unsuccessful");
		}
		if(!setOtherGeneralResults(osResult.getOtherGeneralResults())){
			throw new Exception("setOtherGeneralResults");			
		}

		if(!setSystemInformation(osResult.getSystemInformation())){
			throw new Exception("setSystemInformation");	
		}
		if(!setAvailableDiskSpace(osResult.getAvailableDiskSpace())){
			throw new Exception("setAvailableDiskSpace");	
		}
		if(!setAvailableMemory(osResult.getAvailableMemory())){
			throw new Exception("setAvailableMemory");	
		}
		if(!setAvailableCPUSpeed(osResult.getAvailableCPUSpeed())){
			throw new Exception("setAvailableCPUSpeed");	
		}
		if(!setAvailableCPUNumber(osResult.getAvailableCPUNumber())){
			throw new Exception("setAvailableCPUNumber");	
		}
		if(!setOtherSystemResults(osResult.getOtherSystemResults())){
			throw new Exception("setOtherSystemResults");			
		}

		if(!setCurrentState(osResult.getCurrentState())){
			throw new Exception("setCurrentState");	
		}
		if(!setCurrentJobCount(osResult.getCurrentJobCount())){
			throw new Exception("setCurrentJobCount");	
		}
		if(!setTotalJobsSoFar(osResult.getTotalJobsSoFar())){
			throw new Exception("setCurrentJobCount");	
		}
		if(!setTimeServiceStarted(osResult.getTimeServiceStarted())){
			throw new Exception("setTimeServiceStarted");	
		}
		if(!setServiceUtilization(osResult.getServiceUtilization())){
			throw new Exception("setServiceUtilization");	
		}
		if(!setOtherServiceResults(osResult.getOtherServiceResults())){
			throw new Exception("setOtherServiceResults");			
		}

		if(!setJobStatus(osResult.getJobStatus())){
			throw new Exception("setJobStatus");		
		}
		if(!setJobSubmitTime(osResult.getJobSubmitTime())){
			throw new Exception("setJobSubmitTime");	
		}
		if(!setScheduledStartTime(osResult.getScheduledStartTime())){
			throw new Exception("setScheduledStartTime");
		}
		if(!setActualStartTime(osResult.getActualStartTime())){
			throw new Exception("setActualStartTime");
		}
		if(!setEndTime(osResult.getEndTime())){
			throw new Exception("setEndTime");
		}
		if(!setTimingInformation(osResult.getTimeInformation())){
			throw new Exception("setTimingInformation");			
		}
		if(!setUsedDiskSpace(osResult.getUsedDiskSpace())){
			throw new Exception("setUsedDiskSpace");		
		}
		if(!setUsedMemory(osResult.getUsedMemory())){
			throw new Exception("setUsedMemory");	
		}
		if(!setUsedCPUSpeed(osResult.getUsedCPUSpeed())){
			throw new Exception("setUsedCPUSpeed");	
		}
		if(!setUsedCPUNumber(osResult.getUsedCPUNumber())){
			throw new Exception("setUsedCPUNumber");	
		}
		if(!setOtherJobResults(osResult.getOtherJobResults())){
			throw new Exception("setOtherJobResults");			
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
			if(!setOtherOptimizationSolverOuput(osResult.getOtherOptimizationSolverOuput())){
				throw new Exception("setOtherOptimizationSolverOuput");
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
			Element eGeneral = (Element)XMLUtil.findChildNode(m_eOSrL, "general");
			if(eGeneral == null){
				eGeneral = m_document.createElement("general");
				m_eOSrL.insertBefore(eGeneral, m_eOSrL.getFirstChild());
			}
			if(status != null){
				Element eStatus = (Element)XMLUtil.findChildNode(eGeneral, "generalStatus");
				if(eStatus != null){
					eGeneral.removeChild(eStatus);
				}
				eStatus = m_document.createElement("generalStatus");
				if(status.type != null && status.type.length() > 0){
					if(!status.type.equals("normal") && !status.type.equals("warning") && !status.type.equals("error")){
						return false;
					}
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
					eStatus.setAttribute("numberOfSubstatuses", iSubstatus+"");

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
				else{
					eStatus.setAttribute("numberOfSubstatuses", "0");
				}
				eGeneral.insertBefore(eStatus, eGeneral.getFirstChild());
			}
			else{
				XMLUtil.removeChildrenByName(eGeneral, "generalStatus");
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
			Element eGeneral = (Element)XMLUtil.findChildNode(m_eOSrL, "general");
			if(eGeneral == null){
				eGeneral = m_document.createElement("general");
				m_eOSrL.insertBefore(eGeneral, m_eOSrL.getFirstChild());
			}
			if(type != null && type.length() > 0){
				if(!type.equals("success") && !type.equals("warning") && !type.equals("error")) return false;
				Element eStatus = (Element)XMLUtil.findChildNode(eGeneral, "generalStatus");
				if(eStatus == null){
					eStatus = m_document.createElement("generalStatus");
					eGeneral.insertBefore(eStatus, eGeneral.getFirstChild());
				}
				eStatus.setAttribute("type", type);					
			}
			else{
				XMLUtil.removeChildrenByName(eGeneral, "generalStatus");
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
			Element eGeneral = (Element)XMLUtil.findChildNode(m_eOSrL, "general");
			if(eGeneral == null){
				eGeneral = m_document.createElement("general");
				m_eOSrL.insertBefore(eGeneral, m_eOSrL.getFirstChild());
			}
			Element eStatus = (Element)XMLUtil.findChildNode(eGeneral, "generalStatus");
			if(eStatus == null){
				eStatus = m_document.createElement("generalStatus");
				eGeneral.insertBefore(eStatus, eGeneral.getFirstChild());
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
	 * Set the general message. 
	 * 
	 * @param message holds the general message. 
	 * @return whether process message is set successfully. 
	 */
	public boolean setGeneralMessage(String message){
		try{
			Element eGeneral = (Element)XMLUtil.findChildNode(m_eOSrL, "general");
			if(eGeneral == null){
				eGeneral = m_document.createElement("general");
				m_eOSrL.insertBefore(eGeneral, m_eOSrL.getFirstChild());
			}
			if(message != null && message.length() > 0){
				Element eMessage = (Element)XMLUtil.findChildNode(eGeneral, "message");
				if(eMessage == null){
					eMessage = m_document.createElement("message");					
					eMessage.appendChild(m_document.createTextNode(message));
					eGeneral.appendChild(eMessage);
				}
				else{
					XMLUtil.setElementValue(eMessage, message);
				}
			}
			else{
				XMLUtil.removeChildrenByName(eGeneral, "message");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setGeneralMessage


	/**
	 * Set service uri.
	 * 
	 * @param serviceURI holds the uri of the service. 
	 * @return whether the service uri is set successfully. 
	 */
	public boolean setServiceURI(String serviceURI){
		try{
			Element eGeneral = (Element)XMLUtil.findChildNode(m_eOSrL, "general");
			if(eGeneral == null){
				eGeneral = m_document.createElement("general");
				m_eOSrL.insertBefore(eGeneral, m_eOSrL.getFirstChild());
			}
			if(serviceURI != null && serviceURI.length() > 0){
				Element eServiceURI = (Element)XMLUtil.findChildNode(eGeneral, "serviceURI");
				if(eServiceURI == null){
					eServiceURI = m_document.createElement("serviceURI");					
					eServiceURI.appendChild(m_document.createTextNode(serviceURI));
					eGeneral.appendChild(eServiceURI);
				}
				else{
					XMLUtil.setElementValue(eServiceURI, serviceURI);
				}
			}
			else{
				XMLUtil.removeChildrenByName(eGeneral, "serviceURI");
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
			Element eGeneral = (Element)XMLUtil.findChildNode(m_eOSrL, "general");
			if(eGeneral == null){
				eGeneral = m_document.createElement("general");
				m_eOSrL.insertBefore(eGeneral, m_eOSrL.getFirstChild());
			}
			if(serviceName != null && serviceName.length() > 0){
				Element eServiceName = (Element)XMLUtil.findChildNode(eGeneral, "serviceName");
				if(eServiceName == null){
					eServiceName = m_document.createElement("serviceName");					
					eServiceName.appendChild(m_document.createTextNode(serviceName));
					eGeneral.appendChild(eServiceName);
				}
				else{
					XMLUtil.setElementValue(eServiceName, serviceName);
				}
			}
			else{
				XMLUtil.removeChildrenByName(eGeneral, "serviceName");
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
			Element eGeneral = (Element)XMLUtil.findChildNode(m_eOSrL, "general");
			if(eGeneral == null){
				eGeneral = m_document.createElement("general");
				m_eOSrL.insertBefore(eGeneral, m_eOSrL.getFirstChild());
			}
			if(instanceName != null && instanceName.length() > 0){
				Element eInstanceName = (Element)XMLUtil.findChildNode(eGeneral, "instanceName");
				if(eInstanceName == null){
					eInstanceName = m_document.createElement("instanceName");					
					eInstanceName.appendChild(m_document.createTextNode(instanceName));
					eGeneral.appendChild(eInstanceName);
				}
				else{
					XMLUtil.setElementValue(eInstanceName, instanceName);
				}
			}
			else{
				XMLUtil.removeChildrenByName(eGeneral, "instanceName");
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
			Element eGeneral = (Element)XMLUtil.findChildNode(m_eOSrL, "general");
			if(eGeneral == null){
				eGeneral = m_document.createElement("general");
				m_eOSrL.insertBefore(eGeneral, m_eOSrL.getFirstChild());
			}
			if(jobID != null && jobID.length() > 0){
				Element eJobID = (Element)XMLUtil.findChildNode(eGeneral, "jobID");
				if(eJobID == null){
					eJobID = m_document.createElement("jobID");					
					eJobID.appendChild(m_document.createTextNode(jobID));
					eGeneral.appendChild(eJobID);
				}
				else{
					XMLUtil.setElementValue(eJobID, jobID);
				}
			}
			else{
				XMLUtil.removeChildrenByName(eGeneral, "jobID");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setJobID

	/**
	 * Set solver invoked.
	 * 
	 * @param solverInvoked holds the solver invoked. 
	 * @return whether the solverInvoked is set successfully. 
	 */
	public boolean setSolverInvoked(String solverInvoked){
		try{
			Element eGeneral = (Element)XMLUtil.findChildNode(m_eOSrL, "general");
			if(eGeneral == null){
				eGeneral = m_document.createElement("general");
				m_eOSrL.insertBefore(eGeneral, m_eOSrL.getFirstChild());
			}
			if(solverInvoked != null && solverInvoked.length() > 0){
				Element eSolverInvoked = (Element)XMLUtil.findChildNode(eGeneral, "solverInvoked");
				if(eSolverInvoked == null){
					eSolverInvoked = m_document.createElement("solverInvoked");					
					eSolverInvoked.appendChild(m_document.createTextNode(solverInvoked));
					eGeneral.appendChild(eSolverInvoked);
				}
				else{
					XMLUtil.setElementValue(eSolverInvoked, solverInvoked);
				}
			}
			else{
				XMLUtil.removeChildrenByName(eGeneral, "solverInvoked");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setSolverInvoked

	/**
	 * Set time  stamp of the result.
	 * 
	 * @param timeStamp holds the time of the result.
	 * @return whether result time stamp is set successfully. 
	 */
	public boolean setResultTimeStamp(GregorianCalendar timeStamp){
		try{
			Element eGeneral = (Element)XMLUtil.findChildNode(m_eOSrL, "general");
			if(eGeneral == null){
				eGeneral = m_document.createElement("general");
				m_eOSrL.insertBefore(eGeneral, m_eOSrL.getFirstChild());
			}
			if(timeStamp != null && timeStamp.get(GregorianCalendar.YEAR) > 1970){
				Element eTimeStamp = (Element)XMLUtil.findChildNode(eGeneral, "timeStamp");
				if(eTimeStamp == null){
					eTimeStamp = m_document.createElement("timeStamp");					
					eTimeStamp.appendChild(m_document.createTextNode(XMLUtil.createXSDateTime(timeStamp)));
					eGeneral.appendChild(eTimeStamp);
				}
				else{
					XMLUtil.setElementValue(eTimeStamp, XMLUtil.createXSDateTime(timeStamp));
				}
			}
			else{
				XMLUtil.removeChildrenByName(eGeneral, "timeStamp");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setResultTimeStamp


	/**
	 * Set the number of other general results. 
	 * 
	 * @param numberOfOtherGeneralResults holds the number of other general results
	 * @return whether the number is set successfully or not. 
	 */
	public boolean setNumberOfOtherGeneralResults(int numberOfOtherGeneralResults){
		if(numberOfOtherGeneralResults < 0){
			return true;
		}
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eOSrL, "general");
		if(eGeneral == null){
			eGeneral = m_document.createElement("general");
			m_eOSrL.insertBefore(eGeneral, m_eOSrL.getFirstChild());
		}
		Element eOtherResults = (Element)XMLUtil.findChildNode(eGeneral, "otherResults");
		if(eOtherResults == null){
			eOtherResults = m_document.createElement("otherResults");	
			eGeneral.appendChild(eOtherResults);				
		}
		try{
			eOtherResults.setAttribute("numberOfOtherResults", numberOfOtherGeneralResults+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;	
	}//setNumberOfOtherGeneralResults

	/**
	 * Set the other general results. 
	 * 
	 * @param names holds the names of the other results. It is required. 
	 * @param values holds the values of the other results, empty string "" or null if no value for an result.
	 * @param descriptions holds the descriptions of the other results, empty string "" or null if no value for an result, null for
	 * the entire array if none of the results have descriptions.
	 * @return whether the other results element construction is successful.
	 */
	public boolean setOtherGeneralResults(String[] names, String[] values, String[] descriptions){
		if(names == null) return false;
		if(values == null) return false;
		if(names.length != values.length) return false;
		if(descriptions != null && names.length != descriptions.length) return false;
		for(int i = 0; i < names.length; i++){
			addOtherGeneralResult(names[i], values[i], (descriptions==null)?"":descriptions[i]);
		}
		return true;
	}//setOtherGeneralResults

	/**
	 * Set the other general results. 
	 * 
	 * @param otherGeneralResults holds the other general results
	 * @return whether the other results element construction is successful.
	 */
	public boolean setOtherGeneralResults(OtherResults otherGeneralResults){
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eOSrL, "general");
		if(eGeneral == null){
			eGeneral = m_document.createElement("general");
			m_eOSrL.insertBefore(eGeneral, m_eOSrL.getFirstChild());
		}
		if(otherGeneralResults == null || otherGeneralResults.numberOfOtherResults <= 0 || otherGeneralResults.other == null){
			XMLUtil.removeChildrenByName(eGeneral, "otherResults");
			return true;
		}
		if(otherGeneralResults.other.length != otherGeneralResults.numberOfOtherResults) return false;
		for(int i = 0; i < otherGeneralResults.numberOfOtherResults; i++){
			addOtherGeneralResult(otherGeneralResults.other[i].name, 
					otherGeneralResults.other[i].value, otherGeneralResults.other[i].description);
		}
		return true;
	}//setOtherGeneralResults

	/**
	 * Add an other general result element. 
	 * 
	 * @param name holds the name of the other result element. It is required.
	 * @param value holds the value of the other result element, empty string "" or null if none. 
	 * @param description holds the description of the other result element, empty string "" or null if none. 
	 * @return whether the other result element is added successfully.
	 */
	public boolean addOtherGeneralResult(String name, String value, String description){
		if(name == null || name.trim().length() <= 0) return false;
		try{
			Element eGeneral = (Element)XMLUtil.findChildNode(m_eOSrL, "general");
			if(eGeneral == null){
				eGeneral = m_document.createElement("general");
				m_eOSrL.insertBefore(eGeneral, m_eOSrL.getFirstChild());
			}
			Element eOtherResults = (Element)XMLUtil.findChildNode(eGeneral, "otherResults");
			if(eOtherResults == null){
				eOtherResults = m_document.createElement("otherResults");	
				eGeneral.appendChild(eOtherResults);				
			}
			try{
				Vector<Element> vElements = XMLUtil.getChildElementsByTagName(eOtherResults, "other");
				Element eOther;
				int iNls = vElements==null?0:vElements.size();
				for(int i = 0; i < iNls; i++){
					eOther = (Element)vElements.elementAt(i);
					if(eOther.getAttribute("name").equals(name)){
						eOtherResults.removeChild(eOther);
						iNls--;
						break;
					}
				}
				eOther = m_document.createElement("other");
				eOther.setAttribute("name", name);
				if(value != null && value.length() > 0){
					eOther.setAttribute("value", value);
				}
				if(description != null && description.length() > 0){
					eOther.setAttribute("description", description);
				}
				eOtherResults.appendChild(eOther);

				eOtherResults.setAttribute("numberOfOtherResults", (iNls+1)+"");

			}
			catch(Exception e){
				e.printStackTrace();
				return false;
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//addOtherGeneralResult

	/**
	 * Set system information.
	 * 
	 * @param systemInformation. holds the system information.. 
	 * @return whether the systemInformation is set successfully. 
	 */
	public boolean setSystemInformation(String systemInformation){
		Node nodeRef = null;
		try{
			Element eSystem = (Element)XMLUtil.findChildNode(m_eOSrL, "system");
			if(eSystem == null){
				eSystem = m_document.createElement("system");
				nodeRef = XMLUtil.findChildNode(m_eOSrL, "general");
				if(nodeRef != null){
					m_eOSrL.insertBefore(eSystem, nodeRef.getNextSibling());			
				}
				else{
					m_eOSrL.insertBefore(eSystem, m_eOSrL.getFirstChild());
				}		
			}
			if(systemInformation != null && systemInformation.length() >= 0){
				Element eAvailableDiskSpace = (Element)XMLUtil.findChildNode(eSystem, "systemInformation");
				if(eAvailableDiskSpace == null){
					eAvailableDiskSpace = m_document.createElement("systemInformation");	
					eAvailableDiskSpace.appendChild(m_document.createTextNode(systemInformation));
					eSystem.appendChild(eAvailableDiskSpace);				
				}
				else{
					XMLUtil.setElementValue(eAvailableDiskSpace, systemInformation);
				}
			}
			else{
				XMLUtil.removeChildrenByName(eSystem, "systemInformation");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setSystemInformation

	/**
	 * Set the system available disk space.
	 * 
	 * @param diskSpace holds the  available disk space value, unit and description. 
	 * @return whether the available disk space is set successfully.
	 */
	public boolean setAvailableDiskSpace(DiskSpace availableDiskSpace){
		Node nodeRef = null;
		try{
			Element eSystem = (Element)XMLUtil.findChildNode(m_eOSrL, "system");
			if(eSystem == null){
				eSystem = m_document.createElement("system");
				nodeRef = XMLUtil.findChildNode(m_eOSrL, "general");
				if(nodeRef != null){
					m_eOSrL.insertBefore(eSystem, nodeRef.getNextSibling());			
				}
				else{
					m_eOSrL.insertBefore(eSystem, m_eOSrL.getFirstChild());
				}		
			}
			if(availableDiskSpace != null){
				String sValue = "";
				if(Double.isInfinite(availableDiskSpace.value) && availableDiskSpace.value < 0) sValue = "-INF";
				else if(Double.isInfinite(availableDiskSpace.value) && availableDiskSpace.value > 0) sValue = "INF";
				else sValue = availableDiskSpace.value+"";

				XMLUtil.removeChildrenByName(eSystem, "availableDiskSpace");
				Element eAvailableDiskSpace = (Element)XMLUtil.findChildNode(eSystem, "availableDiskSpace");
				eAvailableDiskSpace = m_document.createElement("availableDiskSpace");	
				eAvailableDiskSpace.appendChild(m_document.createTextNode(sValue));
				eAvailableDiskSpace.setAttribute("unit", availableDiskSpace.unit);
				eAvailableDiskSpace.removeAttribute("description");
				if(availableDiskSpace.description != null && availableDiskSpace.description.length() > 0){
					eAvailableDiskSpace.setAttribute("description", availableDiskSpace.description);
				}
				eSystem.appendChild(eAvailableDiskSpace);				
				XMLUtil.setElementValue(eAvailableDiskSpace, sValue);
			}
			else{
				XMLUtil.removeChildrenByName(eSystem, "availableDiskSpace");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setAvailableDiskSpace

	/**
	 * Set the system available memory.
	 * 
	 * @param availableMemory holds the  available memory value, unit and description. 
	 * @return whether the available memory is set successfully.
	 */
	public boolean setAvailableMemory(MemorySize availableMemory){
		Node nodeRef = null;
		try{
			Element eSystem = (Element)XMLUtil.findChildNode(m_eOSrL, "system");
			if(eSystem == null){
				eSystem = m_document.createElement("system");
				nodeRef = XMLUtil.findChildNode(m_eOSrL, "general");
				if(nodeRef != null){
					m_eOSrL.insertBefore(eSystem, nodeRef.getNextSibling());			
				}
				else{
					m_eOSrL.insertBefore(eSystem, m_eOSrL.getFirstChild());
				}		
			}
			if(availableMemory != null){
				String sValue = "";
				if(Double.isInfinite(availableMemory.value) && availableMemory.value < 0) sValue = "-INF";
				else if(Double.isInfinite(availableMemory.value) && availableMemory.value > 0) sValue = "INF";
				else sValue = availableMemory.value+"";

				XMLUtil.removeChildrenByName(eSystem, "availableMemory");
				Element eAvailableMemory = (Element)XMLUtil.findChildNode(eSystem, "availableMemory");
				eAvailableMemory = m_document.createElement("availableMemory");	
				eAvailableMemory.appendChild(m_document.createTextNode(sValue));
				eAvailableMemory.setAttribute("unit", availableMemory.unit);
				eAvailableMemory.removeAttribute("description");
				if(availableMemory.description != null && availableMemory.description.length() > 0){
					eAvailableMemory.setAttribute("description", availableMemory.description);
				}
				eSystem.appendChild(eAvailableMemory);				
				XMLUtil.setElementValue(eAvailableMemory, sValue);
			}
			else{
				XMLUtil.removeChildrenByName(eSystem, "availableMemory");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setAvailableMemory

	/**
	 * Set the system available CPU Speed.
	 * 
	 * @param availableCPUSpeed holds the  available CPU Speed value, unit and description. 
	 * @return whether the available CPU Speed is set successfully.
	 */
	public boolean setAvailableCPUSpeed(CPUSpeed availableCPUSpeed){
		Node nodeRef = null;
		try{
			Element eSystem = (Element)XMLUtil.findChildNode(m_eOSrL, "system");
			if(eSystem == null){
				eSystem = m_document.createElement("system");
				nodeRef = XMLUtil.findChildNode(m_eOSrL, "general");
				if(nodeRef != null){
					m_eOSrL.insertBefore(eSystem, nodeRef.getNextSibling());			
				}
				else{
					m_eOSrL.insertBefore(eSystem, m_eOSrL.getFirstChild());
				}		
			}
			if(availableCPUSpeed != null){
				String sValue = "";
				if(Double.isInfinite(availableCPUSpeed.value) && availableCPUSpeed.value < 0) sValue = "-INF";
				else if(Double.isInfinite(availableCPUSpeed.value) && availableCPUSpeed.value > 0) sValue = "INF";
				else sValue = availableCPUSpeed.value+"";

				XMLUtil.removeChildrenByName(eSystem, "availableCPUSpeed");
				Element eAvailableCPUSpeed = (Element)XMLUtil.findChildNode(eSystem, "availableCPUSpeed");
				eAvailableCPUSpeed = m_document.createElement("availableCPUSpeed");	
				eAvailableCPUSpeed.appendChild(m_document.createTextNode(sValue));
				eAvailableCPUSpeed.setAttribute("unit", availableCPUSpeed.unit);
				eAvailableCPUSpeed.removeAttribute("description");
				if(availableCPUSpeed.description != null && availableCPUSpeed.description.length() > 0){
					eAvailableCPUSpeed.setAttribute("description", availableCPUSpeed.description);
				}
				eSystem.appendChild(eAvailableCPUSpeed);				
				XMLUtil.setElementValue(eAvailableCPUSpeed, sValue);
			}
			else{
				XMLUtil.removeChildrenByName(eSystem, "availableCPUSpeed");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;	
	}//setAvailableCPUSpeed

	/**
	 * Set the system available CPU Number.
	 * 
	 * @param availableCPUNumber holds the  available CPU Number value and description. 
	 * @return whether the available CPU Number is set successfully.
	 */
	public boolean setAvailableCPUNumber(CPUNumber availableCPUNumber){
		Node nodeRef = null;
		try{
			Element eSystem = (Element)XMLUtil.findChildNode(m_eOSrL, "system");
			if(eSystem == null){
				eSystem = m_document.createElement("system");
				nodeRef = XMLUtil.findChildNode(m_eOSrL, "general");
				if(nodeRef != null){
					m_eOSrL.insertBefore(eSystem, nodeRef.getNextSibling());			
				}
				else{
					m_eOSrL.insertBefore(eSystem, m_eOSrL.getFirstChild());
				}		
			}
			if(availableCPUNumber != null){
				String sValue = "";
				if(Double.isInfinite(availableCPUNumber.value) && availableCPUNumber.value < 0) sValue = "-INF";
				else if(Double.isInfinite(availableCPUNumber.value) && availableCPUNumber.value > 0) sValue = "INF";
				else sValue = availableCPUNumber.value+"";

				XMLUtil.removeChildrenByName(eSystem, "availableCPUNumber");
				Element eAvailableCPUNumber = (Element)XMLUtil.findChildNode(eSystem, "availableCPUNumber");
				eAvailableCPUNumber = m_document.createElement("availableCPUNumber");	
				eAvailableCPUNumber.appendChild(m_document.createTextNode(sValue));
				eAvailableCPUNumber.removeAttribute("description");
				if(availableCPUNumber.description != null && availableCPUNumber.description.length() > 0){
					eAvailableCPUNumber.setAttribute("description", availableCPUNumber.description);
				}
				eSystem.appendChild(eAvailableCPUNumber);				
				XMLUtil.setElementValue(eAvailableCPUNumber, sValue);
			}
			else{
				XMLUtil.removeChildrenByName(eSystem, "availableCPUNumber");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;		
	}//setAvailableCPUNumber


	/**
	 * Set the number of other system results. 
	 * 
	 * @param numberOfOtherSystemResults holds the number of other system results
	 * @return whether the number is set successfully or not. 
	 */
	public boolean setNumberOfOtherSystemResults(int numberOfOtherSystemResults){
		Node nodeRef = null;
		if(numberOfOtherSystemResults < 0){
			return true;
		}
		Element eSystem = (Element)XMLUtil.findChildNode(m_eOSrL, "system");
		if(eSystem == null){
			eSystem = m_document.createElement("system");
			nodeRef = XMLUtil.findChildNode(m_eOSrL, "general");
			if(nodeRef != null){
				m_eOSrL.insertBefore(eSystem, nodeRef.getNextSibling());			
			}
			else{
				m_eOSrL.insertBefore(eSystem, m_eOSrL.getFirstChild());
			}		
		}		
		Element eOtherResults = (Element)XMLUtil.findChildNode(eSystem, "otherResults");
		if(eOtherResults == null){
			eOtherResults = m_document.createElement("otherResults");	
			eSystem.appendChild(eOtherResults);				
		}
		try{
			eOtherResults.setAttribute("numberOfOtherResults", numberOfOtherSystemResults+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;	
	}//setNumberOfOtherSystemResults

	/**
	 * Set the other system results. 
	 * 
	 * @param names holds the names of the other results. It is required. 
	 * @param values holds the values of the other results, empty string "" or null if no value for an result.
	 * @param descriptions holds the descriptions of the other results, empty string "" or null if no value for an result, null for
	 * the entire array if none of the results have descriptions.
	 * @return whether the other results element construction is successful.
	 */
	public boolean setOtherSystemResults(String[] names, String[] values, String[] descriptions){
		if(names == null) return false;
		if(values == null) return false;
		if(names.length != values.length) return false;
		if(descriptions != null && names.length != descriptions.length) return false;
		for(int i = 0; i < names.length; i++){
			addOtherSystemResult(names[i], values[i], (descriptions==null)?"":descriptions[i]);
		}
		return true;
	}//setOtherSystemResults

	/**
	 * Set the other system results. 
	 * 
	 * @param otherSystemResults holds the other system results
	 * @return whether the other results element construction is successful.
	 */
	public boolean setOtherSystemResults(OtherResults otherSystemResults){
		Node nodeRef = null;
		Element eSystem = (Element)XMLUtil.findChildNode(m_eOSrL, "system");
		if(eSystem == null){
			eSystem = m_document.createElement("system");
			nodeRef = XMLUtil.findChildNode(m_eOSrL, "general");
			if(nodeRef != null){
				m_eOSrL.insertBefore(eSystem, nodeRef.getNextSibling());			
			}
			else{
				m_eOSrL.insertBefore(eSystem, m_eOSrL.getFirstChild());
			}		
		}
		if(otherSystemResults == null || otherSystemResults.numberOfOtherResults <= 0 || otherSystemResults.other == null){
			XMLUtil.removeChildrenByName(eSystem, "otherResults");
			return true;
		}
		if(otherSystemResults.other.length != otherSystemResults.numberOfOtherResults) return false;
		for(int i = 0; i < otherSystemResults.numberOfOtherResults; i++){
			addOtherSystemResult(otherSystemResults.other[i].name, 
					otherSystemResults.other[i].value, otherSystemResults.other[i].description);
		}
		return true;
	}//setOtherSystemResults

	/**
	 * Add an other system result element. 
	 * 
	 * @param name holds the name of the other result element. It is required.
	 * @param value holds the value of the other result element, empty string "" or null if none. 
	 * @param description holds the description of the other result element, empty string "" or null if none. 
	 * @return whether the other result element is added successfully.
	 */
	public boolean addOtherSystemResult(String name, String value, String description){
		Node nodeRef = null;
		if(name == null || name.trim().length() <= 0) return false;
		try{
			Element eSystem = (Element)XMLUtil.findChildNode(m_eOSrL, "system");
			if(eSystem == null){
				eSystem = m_document.createElement("system");
				nodeRef = XMLUtil.findChildNode(m_eOSrL, "general");
				if(nodeRef != null){
					m_eOSrL.insertBefore(eSystem, nodeRef.getNextSibling());			
				}
				else{
					m_eOSrL.insertBefore(eSystem, m_eOSrL.getFirstChild());
				}		
			}		
			Element eOtherResults = (Element)XMLUtil.findChildNode(eSystem, "otherResults");
			if(eOtherResults == null){
				eOtherResults = m_document.createElement("otherResults");	
				eSystem.appendChild(eOtherResults);				
			}
			try{
				Vector<Element> vElements = XMLUtil.getChildElementsByTagName(eOtherResults, "other");
				Element eOther;
				int iNls = vElements==null?0:vElements.size();
				for(int i = 0; i < iNls; i++){
					eOther = (Element)vElements.elementAt(i);
					if(eOther.getAttribute("name").equals(name)){
						eOtherResults.removeChild(eOther);
						iNls--;
						break;
					}
				}
				eOther = m_document.createElement("other");
				eOther.setAttribute("name", name);
				if(value != null && value.length() > 0){
					eOther.setAttribute("value", value);
				}
				if(description != null && description.length() > 0){
					eOther.setAttribute("description", description);
				}
				eOtherResults.appendChild(eOther);

				eOtherResults.setAttribute("numberOfOtherResults", (iNls+1)+"");

			}
			catch(Exception e){
				e.printStackTrace();
				return false;
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//addOtherSystemResult

	/**
	 * Set the current state. 
	 * @param currentState holds the current state, which can be:
	 * "busy", "busyButAccepting", "idle", "idleButNotAccepting", "noResponse" or "unknown" (default).
	 * @return whether the current state is set successfully.
	 */
	public boolean setCurrentState(String currentState){
		Node nodeRef = null;
		try{
			Element eService = (Element)XMLUtil.findChildNode(m_eOSrL, "service");
			if(eService == null){
				eService = m_document.createElement("service");
				nodeRef = XMLUtil.findChildNode(m_eOSrL, "system");
				if(nodeRef != null){
					m_eOSrL.insertBefore(eService, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSrL, "general");
					if(nodeRef != null){
						m_eOSrL.insertBefore(eService, nodeRef.getNextSibling());			
					}
					else{
						m_eOSrL.insertBefore(eService, m_eOSrL.getFirstChild());
					}		
				}		
			}
			if(currentState != null && currentState.length() > 0){
				if(!currentState.equals("busy") && 
						!currentState.equals("busyButAccepting") &&
						!currentState.equals("idle") &&
						!currentState.equals("idleButNotAccepting") &&
						!currentState.equals("noResponse") &&
						!currentState.equals("unknown")) return false;
				Element eCurrentState = (Element)XMLUtil.findChildNode(eService, "currentState");
				if(eCurrentState == null){
					eCurrentState = m_document.createElement("currentState");	
					eCurrentState.appendChild(m_document.createTextNode(currentState));
					eService.appendChild(eCurrentState);				
				}
				else{
					XMLUtil.setElementValue(eCurrentState, currentState);
				}
			}
			else{
				XMLUtil.removeChildrenByName(eService, "currentState");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setCurrentState

	/**
	 * Set the current job count. 
	 * @param currentJobCount holds the current job count. 
	 * @return whether the current job count is set successfully.
	 */
	public boolean setCurrentJobCount(int currentJobCount){
		Node nodeRef = null;
		try{
			Element eService = (Element)XMLUtil.findChildNode(m_eOSrL, "service");
			if(eService == null){
				eService = m_document.createElement("service");
				nodeRef = XMLUtil.findChildNode(m_eOSrL, "system");
				if(nodeRef != null){
					m_eOSrL.insertBefore(eService, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSrL, "general");
					if(nodeRef != null){
						m_eOSrL.insertBefore(eService, nodeRef.getNextSibling());			
					}
					else{
						m_eOSrL.insertBefore(eService, m_eOSrL.getFirstChild());
					}		
				}		
			}
			if(currentJobCount >= 0){
				Element eCurrentJobCount = (Element)XMLUtil.findChildNode(eService, "currentJobCount");
				if(eCurrentJobCount == null){
					eCurrentJobCount = m_document.createElement("currentJobCount");	
					eCurrentJobCount.appendChild(m_document.createTextNode(currentJobCount+""));
					eService.appendChild(eCurrentJobCount);				
				}
				else{
					XMLUtil.setElementValue(eCurrentJobCount, currentJobCount+"");
				}
			}
			else{
				XMLUtil.removeChildrenByName(eService, "currentJobCount");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setCurrentJobCount

	/**
	 * Set the total jobs received so far. 
	 * @param totalJobsSoFar holds the total jobs received so far. 
	 * @return whether the total jobs so far is set successfully.
	 */
	public boolean setTotalJobsSoFar(int totalJobsSoFar){
		Node nodeRef = null;
		try{
			Element eService = (Element)XMLUtil.findChildNode(m_eOSrL, "service");
			if(eService == null){
				eService = m_document.createElement("service");
				nodeRef = XMLUtil.findChildNode(m_eOSrL, "system");
				if(nodeRef != null){
					m_eOSrL.insertBefore(eService, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSrL, "general");
					if(nodeRef != null){
						m_eOSrL.insertBefore(eService, nodeRef.getNextSibling());			
					}
					else{
						m_eOSrL.insertBefore(eService, m_eOSrL.getFirstChild());
					}		
				}		
			}
			if(totalJobsSoFar >= 0){
				Element eTotalJobsSoFar = (Element)XMLUtil.findChildNode(eService, "totalJobsSoFar");
				if(eTotalJobsSoFar == null){
					eTotalJobsSoFar = m_document.createElement("totalJobsSoFar");	
					eTotalJobsSoFar.appendChild(m_document.createTextNode(totalJobsSoFar+""));
					eService.appendChild(eTotalJobsSoFar);				
				}
				else{
					XMLUtil.setElementValue(eTotalJobsSoFar, totalJobsSoFar+"");
				}
			}
			else{
				XMLUtil.removeChildrenByName(eService, "totalJobsSoFar");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setTotalJobsSoFar

	/**
	 * Set the time the service started. 
	 * @param timeServiceStarted holds the time the service started. 
	 * @return whether the time the service started is set successfully.
	 */
	public boolean setTimeServiceStarted(GregorianCalendar timeServiceStarted){
		Node nodeRef = null;
		try{
			Element eService = (Element)XMLUtil.findChildNode(m_eOSrL, "service");
			if(eService == null){
				eService = m_document.createElement("service");
				nodeRef = XMLUtil.findChildNode(m_eOSrL, "system");
				if(nodeRef != null){
					m_eOSrL.insertBefore(eService, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSrL, "general");
					if(nodeRef != null){
						m_eOSrL.insertBefore(eService, nodeRef.getNextSibling());			
					}
					else{
						m_eOSrL.insertBefore(eService, m_eOSrL.getFirstChild());
					}		
				}		
			}
			if(timeServiceStarted != null && timeServiceStarted.get(GregorianCalendar.YEAR) > 1970){
				Element eTtimeServiceStarted = (Element)XMLUtil.findChildNode(eService, "timeServiceStarted");
				if(eTtimeServiceStarted == null){
					eTtimeServiceStarted = m_document.createElement("timeServiceStarted");	
					eTtimeServiceStarted.appendChild(m_document.createTextNode(XMLUtil.createXSDateTime(timeServiceStarted)));
					eService.appendChild(eTtimeServiceStarted);				
				}
				else{
					XMLUtil.setElementValue(eTtimeServiceStarted, XMLUtil.createXSDateTime(timeServiceStarted));
				}
			}
			else{
				XMLUtil.removeChildrenByName(eService, "timeServiceStarted");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setTimeServiceStarted

	/**
	 * Set the service utilization. 
	 * @param serviceUtilization holds the service utilization ([0, 1]). 
	 * @return whether the time last job took is set successfully.
	 */
	public boolean setServiceUtilization(double serviceUtilization){
		Node nodeRef = null;
		try{
			Element eService = (Element)XMLUtil.findChildNode(m_eOSrL, "service");
			if(eService == null){
				eService = m_document.createElement("service");
				nodeRef = XMLUtil.findChildNode(m_eOSrL, "system");
				if(nodeRef != null){
					m_eOSrL.insertBefore(eService, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSrL, "general");
					if(nodeRef != null){
						m_eOSrL.insertBefore(eService, nodeRef.getNextSibling());			
					}
					else{
						m_eOSrL.insertBefore(eService, m_eOSrL.getFirstChild());
					}		
				}		
			}
			if(serviceUtilization >= 0){
				Element eServiceUtilization = (Element)XMLUtil.findChildNode(eService, "serviceUtilization");
				if(eServiceUtilization == null){
					eServiceUtilization = m_document.createElement("serviceUtilization");	
					eServiceUtilization.appendChild(m_document.createTextNode(serviceUtilization+""));
					eService.appendChild(eServiceUtilization);				
				}
				else{
					XMLUtil.setElementValue(eServiceUtilization, serviceUtilization+"");
				}
			}
			else{
				XMLUtil.removeChildrenByName(eService, "serviceUtilization");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setServiceUtilization

	/**
	 * Set the number of other service results. 
	 * 
	 * @param numberOfOtherServiceResults holds the number of other service results
	 * @return whether the number is set successfully or not. 
	 */
	public boolean setNumberOfOtherServiceResults(int numberOfOtherServiceResults){
		Node nodeRef = null;
		if(numberOfOtherServiceResults < 0){
			return true;
		}
		Element eService = (Element)XMLUtil.findChildNode(m_eOSrL, "service");
		if(eService == null){
			eService = m_document.createElement("service");
			nodeRef = XMLUtil.findChildNode(m_eOSrL, "system");
			if(nodeRef != null){
				m_eOSrL.insertBefore(eService, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eOSrL, "general");
				if(nodeRef != null){
					m_eOSrL.insertBefore(eService, nodeRef.getNextSibling());			
				}
				else{
					m_eOSrL.insertBefore(eService, m_eOSrL.getFirstChild());
				}		
			}		
		}		
		Element eOtherResults = (Element)XMLUtil.findChildNode(eService, "otherResults");
		if(eOtherResults == null){
			eOtherResults = m_document.createElement("otherResults");	
			eService.appendChild(eOtherResults);				
		}
		try{
			eOtherResults.setAttribute("numberOfOtherResults", numberOfOtherServiceResults+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;	
	}//setNumberOfOtherServiceResults

	/**
	 * Set the other service results. 
	 * 
	 * @param names holds the names of the other results. It is required. 
	 * @param values holds the values of the other results, empty string "" or null if no value for an result.
	 * @param descriptions holds the descriptions of the other results, empty string "" or null if no value for an result, null for
	 * the entire array if none of the results have descriptions.
	 * @return whether the other results element construction is successful.
	 */
	public boolean setOtherServiceResults(String[] names, String[] values, String[] descriptions){
		if(names == null) return false;
		if(values == null) return false;
		if(names.length != values.length) return false;
		if(descriptions != null && names.length != descriptions.length) return false;
		for(int i = 0; i < names.length; i++){
			addOtherServiceResult(names[i], values[i], (descriptions==null)?"":descriptions[i]);
		}
		return true;
	}//setOtherServiceResults

	/**
	 * Set the other service results. 
	 * 
	 * @param otherServiceResults holds the other service results
	 * @return whether the other results element construction is successful.
	 */
	public boolean setOtherServiceResults(OtherResults otherServiceResults){
		Node nodeRef = null;
		Element eService = (Element)XMLUtil.findChildNode(m_eOSrL, "service");
		if(eService == null){
			eService = m_document.createElement("service");
			nodeRef = XMLUtil.findChildNode(m_eOSrL, "system");
			if(nodeRef != null){
				m_eOSrL.insertBefore(eService, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eOSrL, "general");
				if(nodeRef != null){
					m_eOSrL.insertBefore(eService, nodeRef.getNextSibling());			
				}
				else{
					m_eOSrL.insertBefore(eService, m_eOSrL.getFirstChild());
				}		
			}		
		}
		if(otherServiceResults == null || otherServiceResults.numberOfOtherResults <= 0 || otherServiceResults.other == null){
			XMLUtil.removeChildrenByName(eService, "otherResults");
			return true;
		}
		if(otherServiceResults.other.length != otherServiceResults.numberOfOtherResults) return false;
		for(int i = 0; i < otherServiceResults.numberOfOtherResults; i++){
			addOtherServiceResult(otherServiceResults.other[i].name, 
					otherServiceResults.other[i].value, otherServiceResults.other[i].description);
		}
		return true;
	}//setOtherServiceResults

	/**
	 * Add an other service result element. 
	 * 
	 * @param name holds the name of the other result element. It is required.
	 * @param value holds the value of the other result element, empty string "" or null if none. 
	 * @param description holds the description of the other result element, empty string "" or null if none. 
	 * @return whether the other result element is added successfully.
	 */
	public boolean addOtherServiceResult(String name, String value, String description){
		Node nodeRef = null;
		if(name == null || name.trim().length() <= 0) return false;
		try{
			Element eService = (Element)XMLUtil.findChildNode(m_eOSrL, "service");
			if(eService == null){
				eService = m_document.createElement("service");
				nodeRef = XMLUtil.findChildNode(m_eOSrL, "system");
				if(nodeRef != null){
					m_eOSrL.insertBefore(eService, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSrL, "general");
					if(nodeRef != null){
						m_eOSrL.insertBefore(eService, nodeRef.getNextSibling());			
					}
					else{
						m_eOSrL.insertBefore(eService, m_eOSrL.getFirstChild());
					}		
				}		
			}			
			Element eOtherResults = (Element)XMLUtil.findChildNode(eService, "otherResults");
			if(eOtherResults == null){
				eOtherResults = m_document.createElement("otherResults");	
				eService.appendChild(eOtherResults);				
			}
			try{
				Vector<Element> vElements = XMLUtil.getChildElementsByTagName(eOtherResults, "other");
				Element eOther;
				int iNls = vElements==null?0:vElements.size();
				for(int i = 0; i < iNls; i++){
					eOther = (Element)vElements.elementAt(i);
					if(eOther.getAttribute("name").equals(name)){
						eOtherResults.removeChild(eOther);
						iNls--;
						break;
					}
				}
				eOther = m_document.createElement("other");
				eOther.setAttribute("name", name);
				if(value != null && value.length() > 0){
					eOther.setAttribute("value", value);
				}
				if(description != null && description.length() > 0){
					eOther.setAttribute("description", description);
				}
				eOtherResults.appendChild(eOther);

				eOtherResults.setAttribute("numberOfOtherResults", (iNls+1)+"");

			}
			catch(Exception e){
				e.printStackTrace();
				return false;
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//addOtherServiceResult

	/**
	 * Set the job status. 
	 * @param jobStatus holds the current state, which can be:
	 * "waiting", "running", "killed", "finished" and "unknown".
	 * @return whether the current state is set successfully.
	 */
	public boolean setJobStatus(String jobStatus){
		if(jobStatus != null && jobStatus.length() > 0 && 
				!jobStatus.equals("waiting") && 
				!jobStatus.equals("running") &&
				!jobStatus.equals("killed") &&
				!jobStatus.equals("finished") &&
				!jobStatus.equals("unknown")) return false;
		Node nodeRef = null;
		try{
			Element eJob = (Element)XMLUtil.findChildNode(m_eOSrL, "job");
			if(eJob == null){
				eJob = m_document.createElement("job");
				nodeRef = XMLUtil.findChildNode(m_eOSrL, "service");
				if(nodeRef != null){
					m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSrL, "system");
					if(nodeRef != null){
						m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSrL, "general");
						if(nodeRef != null){
							m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
						}
						else{
							m_eOSrL.insertBefore(eJob, m_eOSrL.getFirstChild());
						}		
					}		
				}
			}
			if(jobStatus != null && jobStatus.length() > 0){
				Element eStatus = (Element)XMLUtil.findChildNode(eJob, "status");
				if(eStatus == null){
					eStatus = m_document.createElement("status");	
					eStatus.appendChild(m_document.createTextNode(jobStatus));
					eJob.appendChild(eStatus);				
				}
				else{
					XMLUtil.setElementValue(eStatus, jobStatus);
				}
			}
			else{
				XMLUtil.removeChildrenByName(eJob, "status");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setJobStatus

	/**
	 * Set the submit time. 
	 * @param submitTime holds the job submit time. 
	 * @return whether the submit time is set successfully.
	 */
	public boolean setJobSubmitTime(GregorianCalendar submitTime){
		Node nodeRef = null;
		try{
			Element eJob = (Element)XMLUtil.findChildNode(m_eOSrL, "job");
			if(eJob == null){
				eJob = m_document.createElement("job");
				nodeRef = XMLUtil.findChildNode(m_eOSrL, "service");
				if(nodeRef != null){
					m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSrL, "system");
					if(nodeRef != null){
						m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSrL, "general");
						if(nodeRef != null){
							m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
						}
						else{
							m_eOSrL.insertBefore(eJob, m_eOSrL.getFirstChild());
						}		
					}		
				}
			}
			if(submitTime != null && submitTime.get(GregorianCalendar.YEAR) > 1970){
				Element eSubmitTime = (Element)XMLUtil.findChildNode(eJob, "submitTime");
				if(eSubmitTime == null){
					eSubmitTime = m_document.createElement("submitTime");	
					eSubmitTime.appendChild(m_document.createTextNode(XMLUtil.createXSDateTime(submitTime)));
					eJob.appendChild(eSubmitTime);				
				}
				else{
					XMLUtil.setElementValue(eSubmitTime, XMLUtil.createXSDateTime(submitTime));
				}
			}
			else{
				XMLUtil.removeChildrenByName(eJob, "submitTime");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setJobSubmitTime

	/**
	 * Set the scheduled start time. 
	 * @param scheduledStartTime holds the job scheduled start time. 
	 * @return whether the scheduled start time is set successfully.
	 */
	public boolean setScheduledStartTime(GregorianCalendar scheduledStartTime){
		Node nodeRef = null;
		try{
			Element eJob = (Element)XMLUtil.findChildNode(m_eOSrL, "job");
			if(eJob == null){
				eJob = m_document.createElement("job");
				nodeRef = XMLUtil.findChildNode(m_eOSrL, "service");
				if(nodeRef != null){
					m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSrL, "system");
					if(nodeRef != null){
						m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSrL, "general");
						if(nodeRef != null){
							m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
						}
						else{
							m_eOSrL.insertBefore(eJob, m_eOSrL.getFirstChild());
						}		
					}		
				}
			}
			if(scheduledStartTime != null && scheduledStartTime.get(GregorianCalendar.YEAR) > 1970){
				Element eScheduledStartTime = (Element)XMLUtil.findChildNode(eJob, "scheduledStartTime");
				if(eScheduledStartTime == null){
					eScheduledStartTime = m_document.createElement("scheduledStartTime");	
					eScheduledStartTime.appendChild(m_document.createTextNode(XMLUtil.createXSDateTime(scheduledStartTime)));
					eJob.appendChild(eScheduledStartTime);				
				}
				else{
					XMLUtil.setElementValue(eScheduledStartTime, XMLUtil.createXSDateTime(scheduledStartTime));
				}
			}
			else{
				XMLUtil.removeChildrenByName(eJob, "scheduledStartTime");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setScheduledStartTime

	/**
	 * Set the actual start time. 
	 * @param actualStartTime holds the job actual start time. 
	 * @return whether the actual start time is set successfully.
	 */
	public boolean setActualStartTime(GregorianCalendar actualStartTime){
		Node nodeRef = null;
		try{
			Element eJob = (Element)XMLUtil.findChildNode(m_eOSrL, "job");
			if(eJob == null){
				eJob = m_document.createElement("job");
				nodeRef = XMLUtil.findChildNode(m_eOSrL, "service");
				if(nodeRef != null){
					m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSrL, "system");
					if(nodeRef != null){
						m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSrL, "general");
						if(nodeRef != null){
							m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
						}
						else{
							m_eOSrL.insertBefore(eJob, m_eOSrL.getFirstChild());
						}		
					}		
				}
			}
			if(actualStartTime != null && actualStartTime.get(GregorianCalendar.YEAR) > 1970){
				Element eActualStartTime = (Element)XMLUtil.findChildNode(eJob, "actualStartTime");
				if(eActualStartTime == null){
					eActualStartTime = m_document.createElement("actualStartTime");	
					eActualStartTime.appendChild(m_document.createTextNode(XMLUtil.createXSDateTime(actualStartTime)));
					eJob.appendChild(eActualStartTime);				
				}
				else{
					XMLUtil.setElementValue(eActualStartTime, XMLUtil.createXSDateTime(actualStartTime));
				}
			}
			else{
				XMLUtil.removeChildrenByName(eJob, "actualStartTime");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setActualStartTime

	/**
	 * Set the end time. 
	 * @param endTime holds the end time. 
	 * @return whether the endTime is set successfully.
	 */
	public boolean setEndTime(GregorianCalendar endTime){
		Node nodeRef = null;
		try{
			Element eJob = (Element)XMLUtil.findChildNode(m_eOSrL, "job");
			if(eJob == null){
				eJob = m_document.createElement("job");
				nodeRef = XMLUtil.findChildNode(m_eOSrL, "service");
				if(nodeRef != null){
					m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSrL, "system");
					if(nodeRef != null){
						m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSrL, "general");
						if(nodeRef != null){
							m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
						}
						else{
							m_eOSrL.insertBefore(eJob, m_eOSrL.getFirstChild());
						}		
					}		
				}
			}
			if(endTime != null && endTime.get(GregorianCalendar.YEAR) > 1970){
				Element eEndTime = (Element)XMLUtil.findChildNode(eJob, "endTime");
				if(eEndTime == null){
					eEndTime = m_document.createElement("endTime");	
					eEndTime.appendChild(m_document.createTextNode(XMLUtil.createXSDateTime(endTime)));
					eJob.appendChild(eEndTime);				
				}
				else{
					XMLUtil.setElementValue(eEndTime, XMLUtil.createXSDateTime(endTime));
				}
			}
			else{
				XMLUtil.removeChildrenByName(eJob, "endTime");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setEndTime


	/**
	 * set timing information
	 * @param types: cpuTime, elapsedTime,other
	 * @param categories: total, input, preprocessing, optimization, postprocessing, output, other
	 * @param units: tick, millisecond, second, minute, hour, day, week, month, year
	 * @param descriptions
	 * @return
	 */
	public boolean setTimingInformation(String[] types, String[] categories,String[] units, String[] descriptions, double[] values){
		int n = values==null?0:values.length;

		if(types != null && types.length != n) return false;
		if(categories != null && categories.length != n) return false;
		if(units != null && units.length != n) return false;
		if(descriptions != null && descriptions.length != n) return false;

		for(int i = 0; i < types.length; i++){
			addTimingInformation((types==null)?"elapsedTime":types[i], 
					(categories==null)?"total":categories[i], 
							(units==null)?"second":units[i], 
									(descriptions==null)?"":units[i], 
											values[i]  );
		}
		return true;
	}//setTimingInformation

	/**
	 * set timing information
	 * 
	 * @param timingInformation holds the job timing information
	 * @return whether the timing information element construction is successful.
	 */
	public boolean setTimingInformation(TimingInformation timingInformation){
		Node nodeRef = null;
		Element eJob = (Element)XMLUtil.findChildNode(m_eOSrL, "job");
		if(eJob == null){
			eJob = m_document.createElement("job");
			nodeRef = XMLUtil.findChildNode(m_eOSrL, "service");
			if(nodeRef != null){
				m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eOSrL, "system");
				if(nodeRef != null){
					m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSrL, "general");
					if(nodeRef != null){
						m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
					}
					else{
						m_eOSrL.insertBefore(eJob, m_eOSrL.getFirstChild());
					}		
				}		
			}
		}
		if(timingInformation == null || timingInformation.numberOfTimes <= 0 || timingInformation.time == null){
			XMLUtil.removeChildrenByName(eJob, "timingInformation");
			return true;
		}
		if(timingInformation.time.length != timingInformation.numberOfTimes) return false;
		for(int i = 0; i < timingInformation.numberOfTimes; i++){
			addTimingInformation(timingInformation.time[i].type, timingInformation.time[i].category,
					timingInformation.time[i].unit, timingInformation.time[i].description, 
					timingInformation.time[i].value);
		}
		return true;
	}//setTimingInformation

	/**
	 * add timing information
	 * @param type: cpuTime, elapsedTime,other
	 * @param category: total, input, preprocessing, optimization, postprocessing, output, other
	 * @param unit: tick, millisecond, second, minute, hour, day, week, month, year
	 * @param description
	 * @return whether the timing information is set successfully
	 */
	public boolean addTimingInformation(String type, String category, String unit, String description, double value){
		Node nodeRef = null;
		if(value < 0) return false;
		try{
			Element eJob = (Element)XMLUtil.findChildNode(m_eOSrL, "job");
			if(eJob == null){
				eJob = m_document.createElement("job");
				nodeRef = XMLUtil.findChildNode(m_eOSrL, "service");
				if(nodeRef != null){
					m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSrL, "system");
					if(nodeRef != null){
						m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSrL, "general");
						if(nodeRef != null){
							m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
						}
						else{
							m_eOSrL.insertBefore(eJob, m_eOSrL.getFirstChild());
						}		
					}		
				}
			}
			Element eTimingInformation = (Element)XMLUtil.findChildNode(eJob, "timingInformation");
			if(eTimingInformation == null){
				eTimingInformation = m_document.createElement("timingInformation");	
				eJob.appendChild(eTimingInformation);				
			}
			try{
				Vector<Element> vElements = XMLUtil.getChildElementsByTagName(eTimingInformation, "time");
				Element eTime;
				int iNls = vElements==null?0:vElements.size();
				for(int i = 0; i < iNls; i++){
					eTime = (Element)vElements.elementAt(i);
					if(eTime.getAttribute("type").equals(type) && eTime.getAttribute("category").equals(category)){
						eTimingInformation.removeChild(eTime);
						iNls--;
						break;
					}
				}
				eTime = m_document.createElement("time");
				eTime.setAttribute("type", type);
				eTime.setAttribute("category", category);
				eTime.setAttribute("unit", unit);
				if(description != null && description.length() > 0){
					eTime.setAttribute("description", description);
				}
				XMLUtil.setElementValue(eTime, value+"");
				eTimingInformation.appendChild(eTime);

				eTimingInformation.setAttribute("numberOfTimes", (iNls+1)+"");

			}
			catch(Exception e){
				e.printStackTrace();
				return false;
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//addJobTiming


	/**
	 * Set the job used CPU Speed.
	 * 
	 * @param usedCPUSpeed holds the used CPU Speed. 
	 * @return whether the used CPU Speed is set successfully.
	 */
	public boolean setUsedCPUSpeed(CPUSpeed usedCPUSpeed){
		Node nodeRef = null;
		try{
			Element eJob = (Element)XMLUtil.findChildNode(m_eOSrL, "job");
			if(eJob == null){
				eJob = m_document.createElement("job");
				nodeRef = XMLUtil.findChildNode(m_eOSrL, "service");
				if(nodeRef != null){
					m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSrL, "system");
					if(nodeRef != null){
						m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSrL, "general");
						if(nodeRef != null){
							m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
						}
						else{
							m_eOSrL.insertBefore(eJob, m_eOSrL.getFirstChild());
						}		
					}		
				}
			}
			if(usedCPUSpeed != null){
				String sValue = "";
				if(Double.isInfinite(usedCPUSpeed.value) && usedCPUSpeed.value < 0) sValue = "-INF";
				else if(Double.isInfinite(usedCPUSpeed.value) && usedCPUSpeed.value > 0) sValue = "INF";
				else sValue = usedCPUSpeed.value+"";

				XMLUtil.removeChildrenByName(eJob, "usedCPUSpeed");
				Element eUsedCPUSpeed = (Element)XMLUtil.findChildNode(eJob, "usedCPUSpeed");
				eUsedCPUSpeed = m_document.createElement("usedCPUSpeed");	
				eUsedCPUSpeed.appendChild(m_document.createTextNode(sValue));
				eUsedCPUSpeed.setAttribute("unit", usedCPUSpeed.unit);
				eUsedCPUSpeed.removeAttribute("description");
				if(usedCPUSpeed.description != null && usedCPUSpeed.description.length() > 0){
					eUsedCPUSpeed.setAttribute("description", usedCPUSpeed.description);
				}
				eJob.appendChild(eUsedCPUSpeed);				
				XMLUtil.setElementValue(eUsedCPUSpeed, sValue);
			}
			else{
				XMLUtil.removeChildrenByName(eJob, "usedCPUSpeed");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setUsedCPUSpeed


	/**
	 * Set the job used CPU Number.
	 * 
	 * @param usedCPUNumber holds the  used CPU Number value and description. 
	 * @return whether the used CPU Number is set successfully.
	 */
	public boolean setUsedCPUNumber(CPUNumber usedCPUNumber){
		Node nodeRef = null;
		try{
			Element eJob = (Element)XMLUtil.findChildNode(m_eOSrL, "job");
			if(eJob == null){
				eJob = m_document.createElement("job");
				nodeRef = XMLUtil.findChildNode(m_eOSrL, "service");
				if(nodeRef != null){
					m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSrL, "system");
					if(nodeRef != null){
						m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSrL, "general");
						if(nodeRef != null){
							m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
						}
						else{
							m_eOSrL.insertBefore(eJob, m_eOSrL.getFirstChild());
						}		
					}		
				}
			}
			if(usedCPUNumber != null){
				String sValue = "";
				if(Double.isInfinite(usedCPUNumber.value) && usedCPUNumber.value < 0) sValue = "-INF";
				else if(Double.isInfinite(usedCPUNumber.value) && usedCPUNumber.value > 0) sValue = "INF";
				else sValue = usedCPUNumber.value+"";

				XMLUtil.removeChildrenByName(eJob, "usedCPUNumber");
				Element eUsedCPUNumber = (Element)XMLUtil.findChildNode(eJob, "usedCPUNumber");
				eUsedCPUNumber = m_document.createElement("usedCPUNumber");	
				eUsedCPUNumber.appendChild(m_document.createTextNode(sValue));
				eUsedCPUNumber.removeAttribute("description");
				if(usedCPUNumber.description != null && usedCPUNumber.description.length() > 0){
					eUsedCPUNumber.setAttribute("description", usedCPUNumber.description);
				}
				eJob.appendChild(eUsedCPUNumber);				
				XMLUtil.setElementValue(eUsedCPUNumber, sValue);
			}
			else{
				XMLUtil.removeChildrenByName(eJob, "usedCPUNumber");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setUsedCPUNumber

	/**
	 * Set the job used disk space.
	 * 
	 * @param usedDiskSpace holds the  used disk space value, unit and description. 
	 * @return whether the used disk space is set successfully.
	 */
	public boolean setUsedDiskSpace(DiskSpace usedDiskSpace){
		Node nodeRef = null;
		try{
			Element eJob = (Element)XMLUtil.findChildNode(m_eOSrL, "job");
			if(eJob == null){
				eJob = m_document.createElement("job");
				nodeRef = XMLUtil.findChildNode(m_eOSrL, "service");
				if(nodeRef != null){
					m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSrL, "system");
					if(nodeRef != null){
						m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSrL, "general");
						if(nodeRef != null){
							m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
						}
						else{
							m_eOSrL.insertBefore(eJob, m_eOSrL.getFirstChild());
						}		
					}		
				}
			}
			if(usedDiskSpace != null){
				String sValue = "";
				if(Double.isInfinite(usedDiskSpace.value) && usedDiskSpace.value < 0) sValue = "-INF";
				else if(Double.isInfinite(usedDiskSpace.value) && usedDiskSpace.value > 0) sValue = "INF";
				else sValue = usedDiskSpace.value+"";

				XMLUtil.removeChildrenByName(eJob, "usedDiskSpace");
				Element eUsedDiskSpace = (Element)XMLUtil.findChildNode(eJob, "usedDiskSpace");
				eUsedDiskSpace = m_document.createElement("usedDiskSpace");	
				eUsedDiskSpace.appendChild(m_document.createTextNode(sValue));
				eUsedDiskSpace.setAttribute("unit", usedDiskSpace.unit);
				eUsedDiskSpace.removeAttribute("description");
				if(usedDiskSpace.description != null && usedDiskSpace.description.length() > 0){
					eUsedDiskSpace.setAttribute("description", usedDiskSpace.description);
				}
				eJob.appendChild(eUsedDiskSpace);				
				XMLUtil.setElementValue(eUsedDiskSpace, sValue);
			}
			else{
				XMLUtil.removeChildrenByName(eJob, "usedDiskSpace");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setUsedDiskSpace

	/**
	 * Set the job used memory.
	 * 
	 * @param usedMemory holds the  used memory value, unit and description. 
	 * @return whether the used memory is set successfully.
	 */
	public boolean setUsedMemory(MemorySize usedMemory){
		Node nodeRef = null;
		try{
			Element eJob = (Element)XMLUtil.findChildNode(m_eOSrL, "job");
			if(eJob == null){
				eJob = m_document.createElement("job");
				nodeRef = XMLUtil.findChildNode(m_eOSrL, "service");
				if(nodeRef != null){
					m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSrL, "system");
					if(nodeRef != null){
						m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSrL, "general");
						if(nodeRef != null){
							m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
						}
						else{
							m_eOSrL.insertBefore(eJob, m_eOSrL.getFirstChild());
						}		
					}		
				}
			}
			if(usedMemory != null){
				String sValue = "";
				if(Double.isInfinite(usedMemory.value) && usedMemory.value < 0) sValue = "-INF";
				else if(Double.isInfinite(usedMemory.value) && usedMemory.value > 0) sValue = "INF";
				else sValue = usedMemory.value+"";

				XMLUtil.removeChildrenByName(eJob, "usedMemory");
				Element eUsedMemory = (Element)XMLUtil.findChildNode(eJob, "usedMemory");
				eUsedMemory = m_document.createElement("usedMemory");	
				eUsedMemory.appendChild(m_document.createTextNode(sValue));
				eUsedMemory.setAttribute("unit", usedMemory.unit);
				eUsedMemory.removeAttribute("description");
				if(usedMemory.description != null && usedMemory.description.length() > 0){
					eUsedMemory.setAttribute("description", usedMemory.description);
				}
				eJob.appendChild(eUsedMemory);				
				XMLUtil.setElementValue(eUsedMemory, sValue);
			}
			else{
				XMLUtil.removeChildrenByName(eJob, "usedMemory");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setUsedMemory

	/**
	 * Set the number of other job results. 
	 * 
	 * @param numberOfOtherJobResults holds the number of other job results
	 * @return whether the number is set successfully or not. 
	 */
	public boolean setNumberOfOtherJobResults(int numberOfOtherJobResults){
		Node nodeRef = null;
		if(numberOfOtherJobResults < 0){
			return true;
		}
		Element eJob = (Element)XMLUtil.findChildNode(m_eOSrL, "job");
		if(eJob == null){
			eJob = m_document.createElement("job");
			nodeRef = XMLUtil.findChildNode(m_eOSrL, "service");
			if(nodeRef != null){
				m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eOSrL, "system");
				if(nodeRef != null){
					m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSrL, "general");
					if(nodeRef != null){
						m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
					}
					else{
						m_eOSrL.insertBefore(eJob, m_eOSrL.getFirstChild());
					}		
				}		
			}
		}
		Element eOtherResults = (Element)XMLUtil.findChildNode(eJob, "otherResults");
		if(eOtherResults == null){
			eOtherResults = m_document.createElement("otherResults");	
			eJob.appendChild(eOtherResults);				
		}
		try{
			eOtherResults.setAttribute("numberOfOtherResults", numberOfOtherJobResults+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setNumberOfOtherJobResults


	/**
	 * Set the other job results. 
	 * 
	 * @param names holds the names of the other results. It is required. 
	 * @param values holds the values of the other results, empty string "" or null if no value for an result.
	 * @param descriptions holds the descriptions of the other results, empty string "" or null if no value for an result, null for
	 * the entire array if none of the results have descriptions.
	 * @return whether the other results element construction is successful.
	 */
	public boolean setOtherJobResults(String[] names, String[] values, String[] descriptions){
		if(names == null) return false;
		if(values == null) return false;
		if(names.length != values.length) return false;
		if(descriptions != null && names.length != descriptions.length) return false;
		for(int i = 0; i < names.length; i++){
			addOtherJobResult(names[i], values[i], (descriptions==null)?"":descriptions[i]);
		}
		return true;
	}//setOtherJobResults

	/**
	 * Set the other job results. 
	 * 
	 * @param otherJobResults holds the other job results
	 * @return whether the other results element construction is successful.
	 */
	public boolean setOtherJobResults(OtherResults otherJobResults){
		Node nodeRef = null;
		Element eJob = (Element)XMLUtil.findChildNode(m_eOSrL, "job");
		if(eJob == null){
			eJob = m_document.createElement("job");
			nodeRef = XMLUtil.findChildNode(m_eOSrL, "service");
			if(nodeRef != null){
				m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eOSrL, "system");
				if(nodeRef != null){
					m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSrL, "general");
					if(nodeRef != null){
						m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
					}
					else{
						m_eOSrL.insertBefore(eJob, m_eOSrL.getFirstChild());
					}		
				}		
			}
		}
		if(otherJobResults == null || otherJobResults.numberOfOtherResults <= 0 || otherJobResults.other == null){
			XMLUtil.removeChildrenByName(eJob, "otherResults");
			return true;
		}
		if(otherJobResults.other.length != otherJobResults.numberOfOtherResults) return false;
		for(int i = 0; i < otherJobResults.numberOfOtherResults; i++){
			addOtherJobResult(otherJobResults.other[i].name, 
					otherJobResults.other[i].value, otherJobResults.other[i].description);
		}
		return true;
	}//setOtherJobResults

	/**
	 * Add an other job result element. 
	 * 
	 * @param name holds the name of the other result element. It is required.
	 * @param value holds the value of the other result element, empty string "" or null if none. 
	 * @param description holds the description of the other result element, empty string "" or null if none. 
	 * @return whether the other result element is added successfully.
	 */
	public boolean addOtherJobResult(String name, String value, String description){
		Node nodeRef = null;
		if(name == null || name.trim().length() <= 0) return false;
		try{
			Element eJob = (Element)XMLUtil.findChildNode(m_eOSrL, "job");
			if(eJob == null){
				eJob = m_document.createElement("job");
				nodeRef = XMLUtil.findChildNode(m_eOSrL, "service");
				if(nodeRef != null){
					m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSrL, "system");
					if(nodeRef != null){
						m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSrL, "general");
						if(nodeRef != null){
							m_eOSrL.insertBefore(eJob, nodeRef.getNextSibling());			
						}
						else{
							m_eOSrL.insertBefore(eJob, m_eOSrL.getFirstChild());
						}		
					}		
				}
			}
			Element eOtherResults = (Element)XMLUtil.findChildNode(eJob, "otherResults");
			if(eOtherResults == null){
				eOtherResults = m_document.createElement("otherResults");	
				eJob.appendChild(eOtherResults);				
			}
			try{
				Vector<Element> vElements = XMLUtil.getChildElementsByTagName(eOtherResults, "other");
				Element eOther;
				int iNls = vElements==null?0:vElements.size();
				for(int i = 0; i < iNls; i++){
					eOther = (Element)vElements.elementAt(i);
					if(eOther.getAttribute("name").equals(name)){
						eOtherResults.removeChild(eOther);
						iNls--;
						break;
					}
				}
				eOther = m_document.createElement("other");
				eOther.setAttribute("name", name);
				if(value != null && value.length() > 0){
					eOther.setAttribute("value", value);
				}
				if(description != null && description.length() > 0){
					eOther.setAttribute("description", description);
				}
				eOtherResults.appendChild(eOther);

				eOtherResults.setAttribute("numberOfOtherResults", (iNls+1)+"");

			}
			catch(Exception e){
				e.printStackTrace();
				return false;
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//addOtherJobResult

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
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSrL, "optimization");
		if(eOptimization == null){
			eOptimization = m_document.createElement("optimization");
			m_eOSrL.appendChild(eOptimization);
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
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSrL, "optimization");
		if(eOptimization == null){
			eOptimization = m_document.createElement("optimization");
			m_eOSrL.appendChild(eOptimization);
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
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSrL, "optimization");
		if(eOptimization == null){
			eOptimization = m_document.createElement("optimization");
			m_eOSrL.appendChild(eOptimization);
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
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSrL, "optimization");
		if(eOptimization == null){
			eOptimization = m_document.createElement("optimization");
			m_eOSrL.appendChild(eOptimization);
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
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSrL, "optimization");
		if(eOptimization == null) return false;
		Vector<Element> vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
		if(solIdx >= vSolutions.size()) return false;
		Element eSolution = (Element)vSolutions.elementAt(solIdx);
		eSolution = m_document.createElement("solution");
		Element eStatus = m_document.createElement("status");
		eStatus.setAttribute("type", "other");
		eSolution.appendChild(eStatus);

		bSetSolution = setSolutionTargetObjectiveIndex(solIdx, solution.targetObjectiveIdx);
		if(!bSetSolution) return false;
		bSetSolution = setSolutionWeightedObjectives(solIdx, solution.weightedObjectives);
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
				bSetSolution = setVariableValuesDense(solIdx, mdValues);
				if(!bSetSolution) return false;	
			}		
			if(solution.variables.valuesString != null){
				String[] msValues = new String[m_iVariableNumber];
				VarStringValue[] var = solution.variables.valuesString.var;
				int iVars = var==null?0:var.length;
				for(int i = 0; i < iVars; i++){
					msValues[var[i].idx] = var[i].value;
				}
				bSetSolution = setVariableStringValues(solIdx, msValues);
				if(!bSetSolution) return false;	
			}		
			if(solution.variables.basisStatus != null){
				String[] msStatuses = new String[m_iVariableNumber];
				BasStatus[] var = solution.variables.basisStatus.var;
				int iVars = var==null?0:var.length;
				for(int i = 0; i < iVars; i++){
					msStatuses[var[i].idx] = var[i].value;
				}
				bSetSolution = setVariableBasisStatuses(solIdx, msStatuses);
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
				bSetSolution = setObjectiveValuesDense(solIdx, mdValues);
				if(!bSetSolution) return false;	
			}	
			if(solution.objectives.other!= null){
				bSetSolution = setOtherObjectiveResults(solIdx, solution.objectives.other);
				if(!bSetSolution) return false;	
			}		
		}

		if(solution.constraints != null){
			if(solution.constraints.dualValues != null){
				double[] mdValues = new double[m_iConstraintNumber];
				DualVarValue[] con = solution.constraints.dualValues.con;
				int iCons = con==null?0:con.length;
				for(int i = 0; i < iCons; i++){
					mdValues[con[i].idx] = con[i].value;
				}
				bSetSolution = setDualVariableValuesDense(solIdx, mdValues);
				if(!bSetSolution) return false;	
			}	
			if(solution.constraints.other != null){
				bSetSolution = setOtherConstraintResults(solIdx, solution.constraints.other);
				if(!bSetSolution) return false;	
			}
		}
		if(solution.otherSolutionResults != null && solution.otherSolutionResults.otherSolutionResult != null){
			bSetSolution = setOtherOptimizationSolutionResults(solIdx, solution.otherSolutionResults.otherSolutionResult);
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
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSrL, "optimization");
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
					eStatus.setAttribute("numberOfSubstatuses", iSubstatus+"");
					for(int i = 0; i < iSubstatus; i++){
						Element eSubstatus =  m_document.createElement("substatus");
						if(status.substatus[i].type != null && status.substatus[i].type.length() > 0){
							eSubstatus.setAttribute("type", status.substatus[i].type);
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
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSrL, "optimization");
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
						if(subStatuses[i].type != null && subStatuses[i].type.length() > 0){
							eSubstatus.setAttribute("type", subStatuses[i].type);
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
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSrL, "optimization");
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
	 * @param targetObjectiveIdx holds the objective index to set.  
	 * All the objective indexes are negative starting from -1 downward. 
	 * 
	 * @return whether the optimization objective index is set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setSolutionTargetObjectiveIndex(int solIdx, int targetObjectiveIdx){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSrL, "optimization");
		if(eOptimization == null) return false;
		Vector<Element> vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
		if(solIdx >= vSolutions.size()) return false;
		Element eSolution = (Element)vSolutions.elementAt(solIdx);
		if(eSolution == null){
			eSolution = m_document.createElement("solution");
		}
		try{
			eSolution.setAttribute("targetObjectiveIdx", targetObjectiveIdx+"");
			eSolution.removeAttribute("weightedObjectives");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setSolutionTargetObjectiveIndex

	/**
	 * Set the [i]th optimization solution's weighted objectives flag, where i equals the given solution index.   
	 * If the solution is solved against the weighted objectives as specified by the weights in the corresponding OSiL, 
	 * the weightedObjectives should be set to true.
	 * 
	 * @param solIdx holds the solution index to set the weightedObjectives flag.
	 * @param weightedObjectives holds whether the solution is solved against the weighted objectives  
	 * 
	 * @return whether the weightedObjectives is set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setSolutionWeightedObjectives(int solIdx, boolean weightedObjectives){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSrL, "optimization");
		if(eOptimization == null) return false;
		Vector<Element> vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
		if(solIdx >= vSolutions.size()) return false;
		Element eSolution = (Element)vSolutions.elementAt(solIdx);
		if(eSolution == null){
			eSolution = m_document.createElement("solution");
		}
		try{
			if(weightedObjectives){
				eSolution.setAttribute("weightedObjectives", weightedObjectives?"true":"false");
				eSolution.removeAttribute("targetObjectiveIdx");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setSolutionTargetObjectiveIndex

	/**
	 * Set the [i]th optimization solution's primal variable values, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the primal variable values. 
	 * @param x holds a double dense array of variable values to set; it could be null if all variables are 0.
	 * 
	 * @return whether primal variable values are set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setVariableValuesDense(int solIdx, double[] x){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSrL, "optimization");
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
						nodeRef = XMLUtil.findChildNode(eSolution, "otherSolutionResults");
					}
				}
				eSolution.insertBefore(eVariables, nodeRef);
			}
			if(x == null){
				XMLUtil.removeChildrenByName(eVariables, "values");
				return true;
			}
			Element eValues = (Element)XMLUtil.findChildNode(eVariables, "values");
			if(eValues == null){
				eValues = m_document.createElement("values");	
				eVariables.insertBefore(eValues, eVariables.getFirstChild());									
			}
			XMLUtil.removeAllChildren(eValues);
			int iVars = x==null?0:x.length;
			eValues.setAttribute("numberOfVar", iVars+"");
			if(iVars == 0) return true;
			if(iVars != m_iVariableNumber) return false;
			int iCount = 0;
			for(int i = 0; i < iVars; i++){
				if(x[i] != 0){
					iCount++;
					Element eVar = m_document.createElement("var");	
					eVar.setAttribute("idx", i+"");
					String sValue = "";
					if(Double.isInfinite(x[i]) && x[i] < 0) sValue = "-INF";
					else if(Double.isInfinite(x[i]) && x[i] > 0) sValue = "INF";
					else sValue = x[i]+"";
					eVar.appendChild(m_document.createTextNode(sValue));
					eValues.appendChild(eVar);				
				}
			}
			eValues.setAttribute("numberOfVar", iCount+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setVariableValuesDense

	/**
	 * Set the [i]th optimization solution's primal variable values, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the primal variable values. 
	 * @param variableValues holds a sparse structure of variable values to set; it could be null if all variables are 0.
	 * 
	 * @return whether primal variable values are set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setVariableValuesSparse(int solIdx, VariableValues variableValues){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSrL, "optimization");
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
						nodeRef = XMLUtil.findChildNode(eSolution, "otherSolutionResults");
					}
				}
				eSolution.insertBefore(eVariables, nodeRef);
			}
			if(variableValues == null){
				XMLUtil.removeChildrenByName(eVariables, "values");
				return true;
			}
			Element eValues = (Element)XMLUtil.findChildNode(eVariables, "values");
			if(eValues == null){
				eValues = m_document.createElement("values");	
				eVariables.insertBefore(eValues, eVariables.getFirstChild());									
			}
			XMLUtil.removeAllChildren(eValues);
			int iVars = variableValues==null?0:variableValues.numberOfVar;
			eValues.setAttribute("numberOfVar", iVars+"");
			if(iVars == 0) return true;
			if(iVars != m_iVariableNumber) return false;
			int iCount = 0;
			for(int i = 0; i < iVars; i++){
				if(variableValues.var[i].value != 0){
					iCount++;
					Element eVar = m_document.createElement("var");	
					eVar.setAttribute("idx", variableValues.var[i].idx+"");
					String sValue = "";
					if(Double.isInfinite(variableValues.var[i].value) && variableValues.var[i].value < 0) sValue = "-INF";
					else if(Double.isInfinite(variableValues.var[i].value) && variableValues.var[i].value > 0) sValue = "INF";
					else sValue = variableValues.var[i].value+"";
					eVar.appendChild(m_document.createTextNode(sValue));
					eValues.appendChild(eVar);				
				}
			}
			eValues.setAttribute("numberOfVar", iCount+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setVariableValuesSparse

	/**
	 * Set the [i]th optimization solution's primal variable string values, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the primal variable string values. 
	 * @param x holds a dense string array of variable string values to set.
	 * 
	 * @return whether primal variable string values are set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setVariableStringValues(int solIdx, String[] x){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSrL, "optimization");
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
						nodeRef = XMLUtil.findChildNode(eSolution, "otherSolutionResults");
					}
				}
				eSolution.insertBefore(eVariables, nodeRef);
			}
			if(x == null){
				XMLUtil.removeChildrenByName(eVariables, "valuesString");
				return true;
			}
			Element eValuesString = (Element)XMLUtil.findChildNode(eVariables, "valuesString");
			if(eValuesString == null){
				eValuesString = m_document.createElement("valuesString");
				nodeRef = XMLUtil.findChildNode(eVariables, "basisStatus");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(eVariables, "other");
				}
				eVariables.insertBefore(eValuesString, nodeRef);
			}
			XMLUtil.removeAllChildren(eValuesString);
			int iVars = x==null?0:x.length;
			eValuesString.setAttribute("numberOfVar", iVars+"");
			if(iVars == 0) return true;
			if(iVars != m_iVariableNumber) return false;
			for(int i = 0; i < iVars; i++){
				Element eVar = m_document.createElement("var");	
				eVar.setAttribute("idx", i+"");
				eVar.appendChild(m_document.createTextNode(x[i]));
				eValuesString.appendChild(eVar);				
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setVariableStringValues

	/**
	 * Set the [i]th optimization solution's primal variable basis status, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the primal variable string values. 
	 * @param x holds a dense string array of variable basis statuses to set: unknown, basic, atLower, atUpper, superBasic
	 * 
	 * @return whether primal variable basis statuses are set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setVariableBasisStatuses(int solIdx, String[] x){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSrL, "optimization");
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
						nodeRef = XMLUtil.findChildNode(eSolution, "otherSolutionResults");
					}
				}
				eSolution.insertBefore(eVariables, nodeRef);
			}
			if(x == null){
				XMLUtil.removeChildrenByName(eVariables, "basisStatus");
				return true;
			}
			Element eBasisStatus = (Element)XMLUtil.findChildNode(eVariables, "basisStatus");
			if(eBasisStatus == null){
				eBasisStatus = m_document.createElement("basisStatus");
				nodeRef = XMLUtil.findChildNode(eVariables, "other");
				eVariables.insertBefore(eBasisStatus, nodeRef);
			}
			XMLUtil.removeAllChildren(eBasisStatus);
			int iVars = x==null?0:x.length;
			eBasisStatus.setAttribute("numberOfVar", iVars+"");
			if(iVars == 0) return true;
			if(iVars != m_iVariableNumber) return false;
			for(int i = 0; i < iVars; i++){
				Element eVar = m_document.createElement("var");	
				eVar.setAttribute("idx", i+"");
				eVar.appendChild(m_document.createTextNode(x[i]));
				eBasisStatus.appendChild(eVar);				
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setVariableBasisStatuses

	/**
	 * Set the [i]th optimization solution's other (non-standard/solver specific)variable-related results, 
	 * where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param otherVariableResults holds an array of other variable results in OtherVariableResult[] array data structure, null if none. 
	 * Each other variable result contains the name (required), an optional description (string) and an optional
	 * value (string). Each other variable result can also optionally contain an array OtherVarResult for each variable. 
	 * The OtherVarResult contains a variable idx (required), and an optional string value.   
	 * 
	 * @return whether the other variable results are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherVariableResult
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherVarResult
	 * @see #setSolutionNumber(int)
	 */
	public boolean setOtherVariableResults(int solIdx, OtherVariableResult[] otherVariableResults){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSrL, "optimization");
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
						nodeRef = XMLUtil.findChildNode(eSolution, "otherSolutionResults");
					}
				}
				eSolution.insertBefore(eVariables, nodeRef);
			}
			XMLUtil.removeChildrenByName(eVariables, "other");
			int iOthers = otherVariableResults==null?0:otherVariableResults.length;
			eVariables.setAttribute("numberOfOtherVariableResults", iOthers+"");
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
				eOther.setAttribute("numberOfVar", iVars+"");
				if(iVars > 0){
					for(int j = 0; j < iVars; j++){
						Element eVar = m_document.createElement("var");	
						eVar.setAttribute("idx", otherVariableResults[i].var[j].idx+"");
						if(otherVariableResults[i].var[j].value != null && otherVariableResults[i].var[j].value.length() > 0){
							eVar.appendChild(m_document.createTextNode(otherVariableResults[i].var[j].value));
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
	public boolean setObjectiveValuesDense(int solIdx, double[] objectiveValues){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSrL, "optimization");
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
					nodeRef = XMLUtil.findChildNode(eSolution, "otherSolutionResults");
				}
				eSolution.insertBefore(eObjectives, nodeRef);
			}
			if(objectiveValues == null){
				XMLUtil.removeChildrenByName(eObjectives, "values");
				return true;
			}
			Element eValues = (Element)XMLUtil.findChildNode(eObjectives, "values");
			if(eValues == null){
				eValues = m_document.createElement("values");	
				eObjectives.insertBefore(eValues, eObjectives.getFirstChild());									
			}
			XMLUtil.removeAllChildren(eValues);
			int iObjs = objectiveValues==null?0:objectiveValues.length;
			eValues.setAttribute("numberOfObj", iObjs+"");
			if(iObjs == 0) return true;
			if(iObjs != m_iObjectiveNumber) return false;
			int iCount = 0;
			for(int i = 0; i < iObjs; i++){
				if(!Double.isNaN(objectiveValues[i])){
					iCount++;
					Element eObj = m_document.createElement("obj");	
					eObj.setAttribute("idx", (-i-1)+"");
					String sValue = "";
					if(Double.isInfinite(objectiveValues[i]) && objectiveValues[i] < 0) sValue = "-INF";
					else if(Double.isInfinite(objectiveValues[i]) && objectiveValues[i] > 0) sValue = "INF";
					else sValue = objectiveValues[i]+"";
					eObj.appendChild(m_document.createTextNode(sValue));
					eValues.appendChild(eObj);				
				}
			}
			eValues.setAttribute("numberOfObj", iCount+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setObjectiveValuesDense

	/**
	 * Set the [i]th optimization solution's objective values, where i equals the given solution index.   
	 * Usually one of the objective is what the solution was solved for (or based on). Its index should be indicated 
	 * in the solution's objectiveIdx attribute. Based on this objective's solution, the rest of the objective 
	 * values are (optionally) calculated. 
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the objective values. 
	 * @param objectiveValues holds a sparse structure of objective values to set.
	 * Possibly only the objective that the solution is based on has the value, and the rest of the objective
	 * values all get a Double.NaN value, meaning that they are not calculated.   
	 * 
	 * @return whether objective values are set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setObjectiveValuesSparse(int solIdx, ObjectiveValues objectiveValues){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSrL, "optimization");
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
					nodeRef = XMLUtil.findChildNode(eSolution, "otherSolutionResults");
				}
				eSolution.insertBefore(eObjectives, nodeRef);
			}
			if(objectiveValues == null){
				XMLUtil.removeChildrenByName(eObjectives, "values");
				return true;
			}
			Element eValues = (Element)XMLUtil.findChildNode(eObjectives, "values");
			if(eValues == null){
				eValues = m_document.createElement("values");	
				eObjectives.insertBefore(eValues, eObjectives.getFirstChild());									
			}
			XMLUtil.removeAllChildren(eValues);
			int iObjs = objectiveValues==null?0:objectiveValues.numberOfObj;
			eValues.setAttribute("numberOfObj", iObjs+"");
			if(iObjs == 0) return true;
			if(iObjs != m_iObjectiveNumber) return false;
			int iCount = 0;
			for(int i = 0; i < iObjs; i++){
				if(!Double.isNaN(objectiveValues.obj[i].value)){
					iCount++;
					Element eObj = m_document.createElement("obj");	
					eObj.setAttribute("idx", objectiveValues.obj[i].idx+"");
					String sValue = "";
					if(Double.isInfinite(objectiveValues.obj[i].value) && objectiveValues.obj[i].value < 0) sValue = "-INF";
					else if(Double.isInfinite(objectiveValues.obj[i].value) && objectiveValues.obj[i].value > 0) sValue = "INF";
					else sValue = objectiveValues.obj[i].value+"";
					eObj.appendChild(m_document.createTextNode(sValue));
					eValues.appendChild(eObj);				
				}
			}
			eValues.setAttribute("numberOfObj", iCount+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setObjectiveValuesSparse

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
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSrL, "optimization");
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
					nodeRef = XMLUtil.findChildNode(eSolution, "otherSolutionResults");
				}
				eSolution.insertBefore(eObjectives, nodeRef);
			}
			XMLUtil.removeChildrenByName(eObjectives, "other");
			int iOthers = otherObjectiveResults==null?0:otherObjectiveResults.length;
			eObjectives.setAttribute("numberOfOtherObjectiveResults", iOthers+"");
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
				eOther.setAttribute("numberOfObj", iObjs+"");
				if(iObjs > 0){
					for(int j = 0; j < iObjs; j++){
						Element eObj = m_document.createElement("obj");	
						eObj.setAttribute("idx", otherObjectiveResults[i].obj[j].idx+"");
						if(otherObjectiveResults[i].obj[j].value != null && otherObjectiveResults[i].obj[j].value.length() > 0){
							eObj.appendChild(m_document.createTextNode(otherObjectiveResults[i].obj[j].value));
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
	 * Set the [i]th optimization solution's dual variable values, where i equals the given solution index. 
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the dual variable values. 
	 * @param dualVariableValues holds a double dense array of variable dual values to set; it could be null if all values are 0.
	 * 
	 * @return whether dual variable values are set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setDualVariableValuesDense(int solIdx, double[] dualVariableValues){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSrL, "optimization");
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
				nodeRef = XMLUtil.findChildNode(eSolution, "otherSolutionResults");
				eSolution.insertBefore(eConstraints, nodeRef);
			}
			if(dualVariableValues == null){
				XMLUtil.removeChildrenByName(eConstraints, "dualValues");
				return true;
			}
			Element eDualValues = (Element)XMLUtil.findChildNode(eConstraints, "dualValues");
			if(eDualValues == null){
				eDualValues = m_document.createElement("dualValues");	
				nodeRef = XMLUtil.findChildNode(eConstraints, "other");
				eConstraints.insertBefore(eDualValues, nodeRef);
			}
			XMLUtil.removeAllChildren(eDualValues);
			int iCons;
			iCons = dualVariableValues == null?0:dualVariableValues.length;
			eDualValues.setAttribute("numberOfCon", iCons+"");
			if(iCons == 0) return true;
			if(iCons != m_iConstraintNumber) return false;
			int iCount = 0;
			for(int i = 0; i < iCons; i++){
				if(dualVariableValues[i] != 0){
					iCount++;
					Element eCon = m_document.createElement("con");	
					eCon.setAttribute("idx", i+"");
					String sValue = "";
					if(Double.isInfinite(dualVariableValues[i]) && dualVariableValues[i] < 0) sValue = "-INF";
					else if(Double.isInfinite(dualVariableValues[i]) && dualVariableValues[i] > 0) sValue = "INF";
					else sValue = dualVariableValues[i]+"";
					eCon.appendChild(m_document.createTextNode(sValue));
					eDualValues.appendChild(eCon);				
				}
			}
			eDualValues.setAttribute("numberOfCon", iCount+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setDualVariableValuesDense

	/**
	 * Set the [i]th optimization solution's dual variable values, where i equals the given solution index. 
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the dual variable values. 
	 * @param dualVariableValues holds a sparse structure of variable dual values to set; it could be null if all values are 0.
	 * 
	 * @return whether dual variable values are set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setDualVariableValuesSparse(int solIdx, DualVariableValues dualVariableValues){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSrL, "optimization");
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
				nodeRef = XMLUtil.findChildNode(eSolution, "otherSolutionResults");
				eSolution.insertBefore(eConstraints, nodeRef);
			}
			if(dualVariableValues == null){
				XMLUtil.removeChildrenByName(eConstraints, "dualValues");
				return true;
			}
			Element eDualValues = (Element)XMLUtil.findChildNode(eConstraints, "dualValues");
			if(eDualValues == null){
				eDualValues = m_document.createElement("dualValues");	
				nodeRef = XMLUtil.findChildNode(eConstraints, "other");
				eConstraints.insertBefore(eDualValues, nodeRef);
			}
			XMLUtil.removeAllChildren(eDualValues);
			int iCons;
			iCons = dualVariableValues == null?0:dualVariableValues.numberOfCon;
			eDualValues.setAttribute("numberOfCon", iCons+"");
			if(iCons == 0) return true;
			if(iCons != m_iConstraintNumber) return false;
			int iCount = 0;
			for(int i = 0; i < iCons; i++){
				if(dualVariableValues.con[i].value != 0){
					iCount++;
					Element eCon = m_document.createElement("con");	
					eCon.setAttribute("idx", dualVariableValues.con[i].idx+"");
					String sValue = "";
					if(Double.isInfinite(dualVariableValues.con[i].value) && dualVariableValues.con[i].value < 0) sValue = "-INF";
					else if(Double.isInfinite(dualVariableValues.con[i].value) && dualVariableValues.con[i].value > 0) sValue = "INF";
					else sValue = dualVariableValues.con[i].value+"";
					eCon.appendChild(m_document.createTextNode(sValue));
					eDualValues.appendChild(eCon);				
				}
			}
			eDualValues.setAttribute("numberOfCon", iCount+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setDualVariableValuesSparse

	/**
	 * Set the [i]th optimization solution's other (non-standard/solver specific)constraint-related results, 
	 * where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param otherConstraintResults holds an array of other constraint results in OtherConstraintResult[] array data structure, null if none. 
	 * Each other constraint result contains the name (required), an optional description (string) and an optional
	 * value (string). Each other constraint result can also optionally contain an array OtherConstraint for each constraint. 
	 * The OtherConResult contains a constraint idx (required), and an optional string value.   
	 * 
	 * @return whether the other constraint results are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherConstraintResult
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherConResult
	 * @see #setSolutionNumber(int)
	 */
	public boolean setOtherConstraintResults(int solIdx, OtherConstraintResult[] otherConstraintResults){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSrL, "optimization");
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
				nodeRef = XMLUtil.findChildNode(eSolution, "otherSolutionResults");
				eSolution.insertBefore(eConstraints, nodeRef);
			}
			XMLUtil.removeChildrenByName(eConstraints, "other");
			int iOthers = otherConstraintResults==null?0:otherConstraintResults.length;
			eConstraints.setAttribute("numberOfOtherConstraintResults", iOthers+"");
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
				eOther.setAttribute("numberOfCon", iCons+"");
				if(iCons > 0){
					for(int j = 0; j < iCons; j++){
						Element eCon = m_document.createElement("con");	
						eCon.setAttribute("idx", otherConstraintResults[i].con[j].idx+"");
						if(otherConstraintResults[i].con[j].value != null && otherConstraintResults[i].con[j].value.length() > 0){
							eCon.appendChild(m_document.createTextNode(otherConstraintResults[i].con[j].value));
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
	 * @param otherSolutionResults holds an array of other optimization solution results in OtherSolutionResult[] array data structure, null if none. 
	 * Each other optimization solution result contains the name (required), an optional category, an optional description (string) and an optional
	 * value (string).  
	 * @return whether the other optimization solution results are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherSolutionResult
	 * @see #setSolutionNumber(int)
	 */
	public boolean setOtherOptimizationSolutionResults(int solIdx, OtherSolutionResult[] otherSolutionResults){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSrL, "optimization");
		if(eOptimization == null) return false;
		Vector<Element> vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
		if(solIdx >= vSolutions.size()) return false;
		Element eSolution = (Element)vSolutions.elementAt(solIdx);
		if(eSolution == null){
			eSolution = m_document.createElement("solution");
			eOptimization.appendChild(eSolution);
		}
		if(otherSolutionResults == null || otherSolutionResults.length <= 0){
			XMLUtil.removeChildrenByName(eSolution, "otherSolutionResults");			
		}
		else{
			try{
				XMLUtil.removeChildrenByName(eSolution, "otherSolutionResults");
				Element eOtherSolutionResults =  m_document.createElement("otherSolutionResults");
				eSolution.appendChild(eOtherSolutionResults);
				int iOthers = otherSolutionResults==null?0:otherSolutionResults.length;
				eOtherSolutionResults.setAttribute("numberOfSolutionResults", iOthers+"");
				if(iOthers == 0) return true;
				for(int i = 0; i < iOthers; i++){
					Element eOtherSolutionResult = m_document.createElement("otherSolutionResult");
					if(otherSolutionResults[i].name == null || otherSolutionResults[i].name.length() <= 0){
						return false;
					}
					else{
						eOtherSolutionResult.setAttribute("name", otherSolutionResults[i].name);
					}
					if(otherSolutionResults[i].category != null && otherSolutionResults[i].category.length() > 0){
						eOtherSolutionResult.setAttribute("category", otherSolutionResults[i].category);					
					}
					if(otherSolutionResults[i].description != null && otherSolutionResults[i].description.length() > 0){
						eOtherSolutionResult.setAttribute("description", otherSolutionResults[i].description);					
					}
					if(otherSolutionResults[i].value != null && otherSolutionResults[i].value.length() > 0){
						eOtherSolutionResult.appendChild(m_document.createTextNode(otherSolutionResults[i].value));
					}
					eOtherSolutionResults.appendChild(eOtherSolutionResult);
				}
			}
			catch(Exception e){
				e.printStackTrace();
				return false;
			}
		}
		return true;
	}//setOtherOptimizationSolutionResults

	/**
	 * Set other optimization related solver output not specific to any solution. 
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param ohterSolverOuput holds an array of other optimization related solver output in OtherSolverOutput[] array data structure, null if none. 
	 * Each other optimization solver output contains the name (required), an optional category an optional description (string) and an optional
	 * value (string).  
	 * @return whether the other optimization solver output are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherSolverOutput
	 * @see #setSolutionNumber(int)
	 */
	public boolean setOtherOptimizationSolverOuput(SolverOutput[] otherSolverOutput){
		if(m_iSolutionNumber == -1) return false;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSrL, "optimization");
		if(eOptimization == null) return false;
		if(otherSolverOutput == null || otherSolverOutput.length <= 0){
			XMLUtil.removeChildrenByName(eOptimization, "otherSolverOutput");			
		}
		else{
			try{
				Element eOtherSolverOutput = (Element)XMLUtil.findChildNode(eOptimization, "otherSolverOutput");
				if(eOtherSolverOutput == null){
					eOtherSolverOutput = m_document.createElement("otherSolverOutput");	
					Node nodeRef = XMLUtil.findChildNode(eOptimization, "osal");
					eOptimization.insertBefore(eOtherSolverOutput, nodeRef);
				}
				int iOthers = otherSolverOutput==null?0:otherSolverOutput.length;
				eOtherSolverOutput.setAttribute("numberOfOutputs", iOthers+"");
				if(iOthers == 0) return true;
				for(int i = 0; i < iOthers; i++){
					Element eOutput = m_document.createElement("output");
					if(otherSolverOutput[i].name == null || otherSolverOutput[i].name.length() <= 0){
						return false;
					}
					else{
						eOutput.setAttribute("name", otherSolverOutput[i].name);
					}
					if(otherSolverOutput[i].category != null && otherSolverOutput[i].category.length() > 0){
						eOutput.setAttribute("category", otherSolverOutput[i].category);					
					}
					if(otherSolverOutput[i].description != null && otherSolverOutput[i].description.length() > 0){
						eOutput.setAttribute("description", otherSolverOutput[i].description);					
					}
					if(otherSolverOutput[i].value != null && otherSolverOutput[i].value.length() > 0){
						eOutput.appendChild(m_document.createTextNode(otherSolverOutput[i].value));
					}
					eOtherSolverOutput.appendChild(eOutput);
				}
			}
			catch(Exception e){
				e.printStackTrace();
				return false;
			}
		}
		return true;
	}//setOtherOptimizationSolverOuput
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
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSrL, "optimization");
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
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		OSrLWriter osrlWriter = new OSrLWriter();
		String sFileName = "/code/OSRepository/test/osrl/osrl.osrl";
		String sAnalysisFileName = "/code/OSRepository/test/osal/osal.osal";
		
		String[] msNames={"n1", "n2"};
		String[] msValues={"v1", "v2"};
		String[] msDescriptions={"d1", "d2"};

		DiskSpace diskSpace = new DiskSpace();
		diskSpace.unit = "byte";
		diskSpace.value = 3.2;
		diskSpace.description = "diskspace desc";

		MemorySize memory = new MemorySize();
		memory.unit = "megabyte";
		memory.value = 3.3;
		memory.description = "memory size";

		CPUNumber cpuNumber = new CPUNumber();
		cpuNumber.value = 2;
		cpuNumber.description = "cpuNumber";

		CPUSpeed cpuSpeed = new CPUSpeed();
		cpuSpeed.unit = "kilohertz";		
		cpuSpeed.value = 4.4;
		cpuSpeed.description = "cpudesc";
		if(!osrlWriter.setAvailableDiskSpace(diskSpace)) System.out.println("setAvailableDiskSpace!");
		if(!osrlWriter.setAvailableMemory(memory)) System.out.println("setAvailableMemory!");
		if(!osrlWriter.setAvailableCPUNumber(cpuNumber)) System.out.println("setAvailableCPUNumber");
		if(!osrlWriter.setAvailableCPUSpeed(cpuSpeed)) System.out.println("setAvailableCPUSpeed");
		if(!osrlWriter.setSystemInformation("systemInformation")) System.out.println("setSystemInformation");
		if(!osrlWriter.setOtherSystemResults(msNames, msValues, msDescriptions)) System.out.println("other system results");;


		GeneralStatus status = new GeneralStatus();
		status.type= "normal";
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
		if(!osrlWriter.setSolverInvoked("my solver invoked")) System.out.println("solver invoked");
		if(!osrlWriter.setResultTimeStamp(new GregorianCalendar())) System.out.println("time!");
		if(!osrlWriter.setOtherGeneralResults(msNames, msValues, msDescriptions)) System.out.println("other general results");;


		if(!osrlWriter.setCurrentState("busy")) System.out.println("setCurrentState!");
		if(!osrlWriter.setCurrentJobCount(3)) System.out.println("setCurrentJobCount!");
		if(!osrlWriter.setTotalJobsSoFar(4)) System.out.println("setTotalJobsSoFar");
		if(!osrlWriter.setTimeServiceStarted(new GregorianCalendar())) System.out.println("setTimeServiceStarted");
		if(!osrlWriter.setServiceUtilization(0.2)) System.out.println("setServiceUtilization!");
		if(!osrlWriter.setOtherServiceResults(msNames, msValues, msDescriptions)) System.out.println("other service results");;

		if(!osrlWriter.setJobStatus("waiting")) System.out.println("setJobStatus!");
		if(!osrlWriter.setJobSubmitTime(new GregorianCalendar())) System.out.println("setJobSubmitTime!");
		if(!osrlWriter.setScheduledStartTime(new GregorianCalendar())) System.out.println("setScheduledStartTime!");
		if(!osrlWriter.setActualStartTime(new GregorianCalendar())) System.out.println("setActualStartTime!");
		if(!osrlWriter.setEndTime(new GregorianCalendar())) System.out.println("setEndTime!");

		String[] msTimingTypes = {"cpuTime", "cpuTime"};
		String[] msTimingCategories = {"optimization", "input"};
		String[] msTimingUnits = {"second", "second"};
		String[] msTimingDescriptions = {"d1", "d2"};
		double[] mdTimingValues = {1.1, 2.2};
		if(!osrlWriter.setTimingInformation(msTimingTypes, msTimingCategories, msTimingUnits, msTimingDescriptions, mdTimingValues)) System.out.println("setTimingInformation!");
		if(!osrlWriter.addTimingInformation("cpuTime", "total", "second", "d3", 3.3)) System.out.println("addTimingInformation!");

		if(!osrlWriter.setOtherJobResults(msNames, msValues, msDescriptions)) System.out.println("other service results");;



		osrlWriter.setVariableNumber(3);
		osrlWriter.setObjectiveNumber(2);
		osrlWriter.setConstraintNumber(4);
		osrlWriter.setSolutionNumber(3);

		OptimizationSolutionSubstatus substatus = new OptimizationSolutionSubstatus();
		substatus.description = "sub desc";
		substatus.type = "stoppedByBounds";
		substatus.value = "abc";
		OptimizationSolutionSubstatus[] mSubstatus = new OptimizationSolutionSubstatus[1];
		mSubstatus[0] = substatus;

		if(!osrlWriter.setSolutionStatus(0, "optimal", "solved", null)) System.out.println("setSolutionStatus");
		if(!osrlWriter.setSolutionStatus(1, "infeasible", "solved", mSubstatus)) System.out.println("setSolutionStatus");
		if(!osrlWriter.setSolutionStatus(2, "globallyOptimal", "solved", null)) System.out.println("setSolutionStatus");

		if(!osrlWriter.setSolutionMessage(0, "sol0 message")) System.out.println("setSolutionMessage");
		if(!osrlWriter.setSolutionMessage(1, "sol1 message")) System.out.println("setSolutionMessage");
		if(!osrlWriter.setSolutionMessage(2, "sol2 message")) System.out.println("setSolutionMessage");


		if(!osrlWriter.setSolutionTargetObjectiveIndex(0, -1)) System.out.println("setSolutionObjectiveIndex");
		if(!osrlWriter.setSolutionTargetObjectiveIndex(1, -1)) System.out.println("setSolutionObjectiveIndex");
		if(!osrlWriter.setSolutionTargetObjectiveIndex(2, -1)) System.out.println("setSolutionObjectiveIndex");

		if(!osrlWriter.setSolutionTargetObjectiveIndex(0, -1)) System.out.println("setSolutionObjectiveIndex");
		if(!osrlWriter.setSolutionWeightedObjectives(0, true)) System.out.println("setSolutionObjectiveIndex");

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

		double[] mdValues11 = {1, Double.NaN};
		//if(!osrlWriter.setObjectiveValuesDense(0, mdValues11)) System.out.println("setObjectiveValuesDense");
		ObjectiveValues objectiveValues = new ObjectiveValues();
		objectiveValues.numberOfObj = 2;
		ObjValue[] mObjValues = new ObjValue[2];
		mObjValues[0] = new ObjValue(); mObjValues[0].idx = -1;mObjValues[0].value = Double.NaN;
		mObjValues[1] = new ObjValue(); mObjValues[1].idx = -2;mObjValues[1].value = 4.4;		
		objectiveValues.obj = mObjValues; 
		if(!osrlWriter.setObjectiveValuesSparse(0, objectiveValues)) System.out.println("setObjectiveValuesSparse");

		double[] mdValues22 = {2, 3};
		if(!osrlWriter.setObjectiveValuesDense(1, mdValues22)) System.out.println("setObjectiveValuesDense");
		double[] mdValues33 = {3, 4};
		if(!osrlWriter.setObjectiveValuesDense(2, mdValues33)) System.out.println("setObjectiveValuesDense");

		double[] mdValues77 = {4, 2, 3, 4};
		//if(!osrlWriter.setDualVariableValuesDense(0, mdValues77)) System.out.println("setDualVariableValuesDense");
		DualVariableValues dualVariableValues = new DualVariableValues();
		dualVariableValues.numberOfCon = 4;
		dualVariableValues.con = new DualVarValue[4];
		dualVariableValues.con[0] = new DualVarValue(); dualVariableValues.con[0].idx = 0; dualVariableValues.con[0].value = 11.00;
		dualVariableValues.con[1] = new DualVarValue(); dualVariableValues.con[1].idx = 1; dualVariableValues.con[1].value = 11.11;
		dualVariableValues.con[2] = new DualVarValue(); dualVariableValues.con[2].idx = 2; dualVariableValues.con[2].value = 11.22;
		dualVariableValues.con[3] = new DualVarValue(); dualVariableValues.con[3].idx = 3; dualVariableValues.con[3].value = 0;
		if(!osrlWriter.setDualVariableValuesSparse(0, dualVariableValues)) System.out.println("setDualVariableValuesSparse");
		double[] mdValues88 = {5, 3, 4, 5};
		if(!osrlWriter.setDualVariableValuesDense(1, mdValues88)) System.out.println("setDualVariableValuesDense");
		double[] mdValues99 = {6, 4, 5, 6};
		if(!osrlWriter.setDualVariableValuesDense(2, mdValues99)) System.out.println("setDualVariableValuesDense");

		OtherConstraintResult[] conOT1 = new OtherConstraintResult[2];
		conOT1[0] = new OtherConstraintResult();	
		conOT1[0].con = new OtherConResult[2];
		conOT1[0].con[0] = new OtherConResult();
		conOT1[0].name = "conOT1 name";
		conOT1[0].description = "conOT1 description";
		conOT1[0].value = "conOT1 value";		
		conOT1[0].con[0].idx = 0;
		conOT1[0].con[0].value = "a";
		conOT1[0].con[1] = new OtherConResult();
		conOT1[0].con[1].idx = 1;
		conOT1[0].con[1].value = "b";
		conOT1[1] = new OtherConstraintResult();	
		conOT1[1].name = "conOT2 name";
		conOT1[1].description = "conOT2 description";
		conOT1[1].value = "conOT2 value";		
		conOT1[1].con = new OtherConResult[2];
		conOT1[1].con[0] = new OtherConResult();
		conOT1[1].con[0].idx = 0;
		conOT1[1].con[0].value = "a";
		conOT1[1].con[1] = new OtherConResult();
		conOT1[1].con[1].idx = 1;
		conOT1[1].con[1].value = "b";
		if(!osrlWriter.setOtherConstraintResults(0, conOT1)) System.out.println("setOtherConstraintResults");
		if(!osrlWriter.setOtherConstraintResults(1, conOT1)) System.out.println("setOtherConstraintResults");
		if(!osrlWriter.setOtherConstraintResults(2, conOT1)) System.out.println("setOtherConstraintResults");


		String[] msValues1 = {"a", "b", "c"};
		if(!osrlWriter.setVariableStringValues(0, msValues1)) System.out.println("setVariableStringValues");
		String[] msValues2 = {"b", "c", "d"};
		if(!osrlWriter.setVariableStringValues(1, msValues2)) System.out.println("setVariableStringValues");
		String[] msValues3 = {"c", "d", "e"};
		if(!osrlWriter.setVariableStringValues(2, msValues3)) System.out.println("setVariableStringValues");


		double[] mdValues1 = {1, 2, 3};
		//if(!osrlWriter.setVariableValuesDense(0, mdValues1)) System.out.println("setVariableValuesDense");
		VariableValues variableValues = new VariableValues();
		variableValues.numberOfVar = 3;
		variableValues.var = new VarValue[3];
		variableValues.var[0] = new VarValue(); variableValues.var[0].idx = 0; variableValues.var[0].value = 111.00;
		variableValues.var[1] = new VarValue(); variableValues.var[1].idx = 0; variableValues.var[1].value = 111.11;
		variableValues.var[2] = new VarValue(); variableValues.var[2].idx = 0; variableValues.var[2].value = 0;
		if(!osrlWriter.setVariableValuesSparse(0, variableValues)) System.out.println("setVariableValuesSparse");
		double[] mdValues2 = {2, 3, 4};
		if(!osrlWriter.setVariableValuesDense(1, mdValues2)) System.out.println("setVariableValuesDense");
		double[] mdValues3 = {3, 4, 5};
		if(!osrlWriter.setVariableValuesDense(2, mdValues3)) System.out.println("setVariableValuesDense");

		String[] msBasisStatus1 = {"unknown", "basic", "atLower"};
		if(!osrlWriter.setVariableBasisStatuses(0, msBasisStatus1)) System.out.println("setVariableBasisStatuses");
		String[] msBasisStatus2 = {"basic", "atLower", "atUpper"};
		if(!osrlWriter.setVariableBasisStatuses(1, msBasisStatus2)) System.out.println("setVariableBasisStatuses");
		String[] msBasisStatus3 = {"atLower", "atUpper", "superBasic"};
		if(!osrlWriter.setVariableBasisStatuses(2, msBasisStatus3)) System.out.println("setVariableBasisStatuses");


		OtherVariableResult[] varOT1 = new OtherVariableResult[2];
		varOT1[0] = new OtherVariableResult();	
		varOT1[0].var = new OtherVarResult[2];
		varOT1[0].var[0] = new OtherVarResult();
		varOT1[0].name = "varOT1 name";
		varOT1[0].description = "varOT1 description";
		varOT1[0].value = "varOT1 value";		
		varOT1[0].var[0].idx = 0;
		varOT1[0].var[0].value = "a";
		varOT1[0].var[1] = new OtherVarResult();
		varOT1[0].var[1].idx = 1;
		varOT1[0].var[1].value = "b";
		varOT1[1] = new OtherVariableResult();	
		varOT1[1].name = "varOT2 name";
		varOT1[1].description = "varOT2 description";
		varOT1[1].value = "varOT2 value";		
		varOT1[1].var = new OtherVarResult[2];
		varOT1[1].var[0] = new OtherVarResult();
		varOT1[1].var[0].idx = 0;
		varOT1[1].var[0].value = "a";
		varOT1[1].var[1] = new OtherVarResult();
		varOT1[1].var[1].idx = 1;
		varOT1[1].var[1].value = "b";
		if(!osrlWriter.setOtherVariableResults(0, varOT1)) System.out.println("setOtherVariableResults");
		if(!osrlWriter.setOtherVariableResults(1, varOT1)) System.out.println("setOtherVariableResults");
		if(!osrlWriter.setOtherVariableResults(2, varOT1)) System.out.println("setOtherVariableResults");


		SolverOutput[] otherSolverOutput = new SolverOutput[2];
		otherSolverOutput[0] = new SolverOutput();
		otherSolverOutput[0].name = "othetOpt0 name";
		otherSolverOutput[0].category = "othetOpt0 cat";
		otherSolverOutput[0].value = "othetOpt0 value";
		otherSolverOutput[0].description = "othetOpt0 description";
		otherSolverOutput[1] = new SolverOutput();
		otherSolverOutput[1].name = "othetOpt1 name";
		otherSolverOutput[1].category = "othetOpt1 cat";
		otherSolverOutput[1].value = "othetOpt1 value";
		otherSolverOutput[1].description = "othetOpt1 description";
		if(!osrlWriter.setOtherOptimizationSolverOuput(otherSolverOutput)) System.out.println("setOtherOptimizationSolverOuput");

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
