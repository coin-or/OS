/**
 * @(#)OSrLReader 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.representationparser;
import java.util.GregorianCalendar;
import java.util.HashMap;
import java.util.Vector;

import org.optimizationservices.oscommon.datastructure.osresult.CPUNumber;
import org.optimizationservices.oscommon.datastructure.osresult.CPUSpeed;
import org.optimizationservices.oscommon.datastructure.osresult.ConstraintSolution;
import org.optimizationservices.oscommon.datastructure.osresult.DiskSpace;
import org.optimizationservices.oscommon.datastructure.osresult.DualVarValue;
import org.optimizationservices.oscommon.datastructure.osresult.DualVariableValues;
import org.optimizationservices.oscommon.datastructure.osresult.GeneralStatus;
import org.optimizationservices.oscommon.datastructure.osresult.GeneralSubstatus;
import org.optimizationservices.oscommon.datastructure.osresult.MemorySize;
import org.optimizationservices.oscommon.datastructure.osresult.ObjValue;
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
import org.optimizationservices.oscommon.datastructure.osresult.OtherResult;
import org.optimizationservices.oscommon.datastructure.osresult.OtherSolutionResult;
import org.optimizationservices.oscommon.datastructure.osresult.OtherVarResult;
import org.optimizationservices.oscommon.datastructure.osresult.OtherVariableResult;
import org.optimizationservices.oscommon.datastructure.osresult.SolutionResults;
import org.optimizationservices.oscommon.datastructure.osresult.Time;
import org.optimizationservices.oscommon.datastructure.osresult.TimingInformation;
import org.optimizationservices.oscommon.datastructure.osresult.VarStringValue;
import org.optimizationservices.oscommon.datastructure.osresult.VarValue;
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
		if(!m_osResult.setResultTimeStamp(getResultTimeStamp())) throw new Exception("setResultTime Unsuccessful");
		if(!m_osResult.setGeneralMessage(getGeneralMessage())) throw new Exception("setGeneralMessage Unsuccessful");
		if(!m_osResult.setVariableNumber(getVariableNumber())) throw new Exception("setVariableNumber Unsuccessful");
		if(!m_osResult.setObjectiveNumber(getObjectiveNumber())) throw new Exception("setObjectiveNumber Unsuccessful");
		if(!m_osResult.setConstraintNumber(getConstraintNumber())) throw new Exception("setConstraintNumber Unsuccessful");
		if(!m_osResult.setSolutionNumber(getSolutionNumber())) throw new Exception("setSolutionNumber Unsuccessful");
		processOptimizationResult();
		m_osResult.optimization = m_optimizationResult;
		return m_osResult;
	}//getOSResult

	/**
	 * Get the general status.
	 * 
	 * @return the general status. 
	 */
	public GeneralStatus getGeneralStatus(){
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eRoot, "general");
		Element eGeneralStatus = (Element)XMLUtil.findChildNode(eGeneral, "generalStatus");
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
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eRoot, "general");
		Element eGeneralStatus = (Element)XMLUtil.findChildNode(eGeneral, "generalStatus");
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
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eRoot, "general");
		Element eGeneralStatus = (Element)XMLUtil.findChildNode(eGeneral, "generalStatus");
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
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eRoot, "general");
		String sServiceURI = XMLUtil.getElementValueByName(eGeneral, "serviceURI");
		if(sServiceURI == null) sServiceURI = "";
		return sServiceURI;	
	}//getServiceURI

	/**
	 * Get service name.
	 * 
	 * @return the service name. 
	 */
	public String getServiceName(){
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eRoot, "general");
		String sServiceName = XMLUtil.getElementValueByName(eGeneral, "serviceName");
		if(sServiceName == null) sServiceName = "";
		return sServiceName;
	}//getServiceName

	/**
	 * Get instance name.
	 * 
	 * @return the instance name. 
	 */
	public String getInstanceName(){
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eRoot, "general");
		String sInstanceName = XMLUtil.getElementValueByName(eGeneral, "instanceName");
		if(sInstanceName == null) sInstanceName = "";
		return sInstanceName;
	}//getInstanceName

	/**
	 * Get the job id.
	 * 
	 * @return the job id. 
	 */
	public String getJobID(){
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eRoot, "general");
		String sJobID = XMLUtil.getElementValueByName(eGeneral, "jobID");
		if(sJobID == null) sJobID = "";
		return sJobID;	
	}//getJobID

	/**
	 * Get time of the result.
	 * 
	 * @return the time of the result.
	 */
	public GregorianCalendar getResultTimeStamp(){
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eRoot, "general");
		String sTime = XMLUtil.getElementValueByName(eGeneral, "time");
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
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eRoot, "general");
		String sMessage = XMLUtil.getElementValueByName(eGeneral, "message");
		if(sMessage == null) sMessage = "";
		return sMessage;	
	}//getGeneralMessage

	/**
	 * Get the solver invoked.
	 * 
	 * @return the solverInvoked. 
	 */
	public String getSolverInvoked(){
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eRoot, "general");
		String sSolverInvoked = XMLUtil.getElementValueByName(eGeneral, "solverInvoked");
		if(sSolverInvoked == null) sSolverInvoked = "";
		return sSolverInvoked;	
	}//getSolverInvoked


	/**
	 * get the number of other <general> results
	 * 
	 * @return the number of other <general> results
	 */
	public int  getNumberOfOtherGeneralResults(){	
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eRoot, "general");
		if(eGeneral == null) return 0;
		Element eOtherResults = (Element)XMLUtil.findChildNode(eGeneral, "otherResults");
		if(eOtherResults == null) return 0;
		String sNumberOfOtherResults = eOtherResults.getAttribute("numberOfOtherResults");
		if(sNumberOfOtherResults == null || sNumberOfOtherResults.length() <= 0) return 0;
		try{
			int iNumberOfOtherResults = Integer.parseInt(sNumberOfOtherResults);
			return iNumberOfOtherResults;
		}
		catch(Exception e){
			return 0;
		}	
	}//getNumberOfOtherGeneralResults

	/**
	 * get the array of other <general> results
	 * 
	 * @return the array of other <general> results
	 */
	public OtherResult[] getOtherGeneralResults(){	
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eRoot, "general");
		if(eGeneral == null) return null;
		Element eOtherResults = (Element)XMLUtil.findChildNode(eGeneral, "otherResults");
		if(eOtherResults == null) return null;
		NodeList others = eOtherResults.getElementsByTagName("other");
		if(others == null || others.getLength() <= 0) return null;
		int iOthers = others.getLength();
		OtherResult[] mOthers = new OtherResult[iOthers];
		for(int i = 0; i < iOthers; i++){
			Element eOther = (Element)others.item(i);
			mOthers[i] =new OtherResult();
			String sName = eOther.getAttribute("name"); 				
			String sValue = eOther.getAttribute("value");
			String sDescription = eOther.getAttribute("description");	
			mOthers[i].name = sName==null?"":sName;
			mOthers[i].value = sValue==null?"":sValue;
			mOthers[i].description = sDescription==null?"":sDescription;
		}
		return mOthers;
	}//getOtherGeneralResults

	/**
	 * Get the system information.
	 * 
	 * @return the system information. 
	 */
	public String getSystemInformation(){
		Element eSystem = (Element)XMLUtil.findChildNode(m_eRoot, "system");
		String sSystemInformation = XMLUtil.getElementValueByName(eSystem, "systemInformation");
		if(sSystemInformation == null) sSystemInformation = "";
		return sSystemInformation;	
	}//getSystemInformation

	/**
	 * Get the system available disk space. 
	 * 
	 * @return the available system disk space 
	 */
	public DiskSpace getAvailableDiskSpace(){
		Element eSystem = (Element)XMLUtil.findChildNode(m_eRoot, "system");
		if(eSystem == null) return null;
		Element eAvailableDiskSpace = (Element)XMLUtil.findChildNode(eSystem, "availableDiskSpace");
		if(eAvailableDiskSpace == null) return null;
		String sAvailableDiskSpace = XMLUtil.getElementValue(eAvailableDiskSpace);
		if(sAvailableDiskSpace == null || sAvailableDiskSpace.length() <= 0) return null;
		DiskSpace diskSpace = new DiskSpace();
		try{
			if(sAvailableDiskSpace.equals("INF")) diskSpace.value = Double.POSITIVE_INFINITY;
			if(sAvailableDiskSpace.equals("-INF")) diskSpace.value = Double.NEGATIVE_INFINITY;
			if(sAvailableDiskSpace.equals("NaN") || sAvailableDiskSpace.equals("-NaN")) diskSpace.value = Double.NaN;			
			double dAvailableDiskSpace = Double.parseDouble(sAvailableDiskSpace);
			diskSpace.value = dAvailableDiskSpace;
			diskSpace.unit = eAvailableDiskSpace.getAttribute("unit");
			diskSpace.description = eAvailableDiskSpace.getAttribute("description");
			return diskSpace;
		}
		catch(Exception e){
			return null;
		}
	}//getAvailableDiskSpace

	/**
	 * Get the system available memory. 
	 * 
	 * @return the available system memory 
	 */
	public MemorySize getAvailableMemory(){
		Element eSystem = (Element)XMLUtil.findChildNode(m_eRoot, "system");
		if(eSystem == null) return null;
		Element eAvailableMemory = (Element)XMLUtil.findChildNode(eSystem, "availableMemory");
		if(eAvailableMemory == null) return null;
		String sAvailableMemory = XMLUtil.getElementValue(eAvailableMemory);
		if(sAvailableMemory == null || sAvailableMemory.length() <= 0) return null;
		MemorySize memory = new MemorySize();
		try{
			if(sAvailableMemory.equals("INF")) memory.value = Double.POSITIVE_INFINITY;
			if(sAvailableMemory.equals("-INF")) memory.value = Double.NEGATIVE_INFINITY;
			if(sAvailableMemory.equals("NaN") || sAvailableMemory.equals("-NaN")) memory.value = Double.NaN;			
			double dAvailableMemory = Double.parseDouble(sAvailableMemory);
			memory.value = dAvailableMemory;
			memory.unit = eAvailableMemory.getAttribute("unit");
			memory.description = eAvailableMemory.getAttribute("description");
			return memory;
		}
		catch(Exception e){
			return null;
		}
	}//getAvailableMemory

	/**
	 * Get the system available CPU speed. 
	 * 
	 * @return the available system CPU speed 
	 */
	public CPUSpeed getAvailableCPUSpeed(){
		Element eSystem = (Element)XMLUtil.findChildNode(m_eRoot, "system");
		if(eSystem == null) return null;
		Element eAvailableCPUSpeed = (Element)XMLUtil.findChildNode(eSystem, "availableCPUSpeed");
		if(eAvailableCPUSpeed == null) return null;
		String sAvailableCPUSpeed = XMLUtil.getElementValue(eAvailableCPUSpeed);
		if(sAvailableCPUSpeed == null || sAvailableCPUSpeed.length() <= 0) return null;
		CPUSpeed cpuSpeed = new CPUSpeed();
		try{
			if(sAvailableCPUSpeed.equals("INF")) cpuSpeed.value = Double.POSITIVE_INFINITY;
			if(sAvailableCPUSpeed.equals("-INF")) cpuSpeed.value = Double.NEGATIVE_INFINITY;
			if(sAvailableCPUSpeed.equals("NaN") || sAvailableCPUSpeed.equals("-NaN")) cpuSpeed.value = Double.NaN;			
			double dAvailableCPUSpeed = Double.parseDouble(sAvailableCPUSpeed);
			cpuSpeed.value = dAvailableCPUSpeed;
			cpuSpeed.unit = eAvailableCPUSpeed.getAttribute("unit");
			cpuSpeed.description = eAvailableCPUSpeed.getAttribute("description");
			return cpuSpeed;
		}
		catch(Exception e){
			return null;
		}
	}//getAvailableCPUSpeed

	/**
	 * Get the system available CPU number. 
	 * 
	 * @return the available system CPU number 
	 */
	public CPUNumber getAvailableCPUNumber(){
		Element eSystem = (Element)XMLUtil.findChildNode(m_eRoot, "system");
		if(eSystem == null) return null;
		Element eAvailableCPUNumber = (Element)XMLUtil.findChildNode(eSystem, "availableCPUNumber");
		if(eAvailableCPUNumber == null) return null;
		String sAvailableCPUNumber = XMLUtil.getElementValue(eAvailableCPUNumber);
		if(sAvailableCPUNumber == null || sAvailableCPUNumber.length() <= 0) return null;
		CPUNumber cpuNumber = new CPUNumber();
		try{
			int iAvailableCPUNumber = Integer.parseInt(sAvailableCPUNumber);
			cpuNumber.value = iAvailableCPUNumber;
			cpuNumber.description = eAvailableCPUNumber.getAttribute("description");
			return cpuNumber;
		}
		catch(Exception e){
			return null;
		}
	}//getAvailableCPUNumber

	/**
	 * get the number of other <system> results
	 * 
	 * @return the number of other <system> results
	 */
	public int  getNumberOfOtherSystemResults(){	
		Element eSystem = (Element)XMLUtil.findChildNode(m_eRoot, "system");
		if(eSystem == null) return 0;
		Element eOtherResults = (Element)XMLUtil.findChildNode(eSystem, "otherResults");
		if(eOtherResults == null) return 0;
		String sNumberOfOtherResults = eOtherResults.getAttribute("numberOfOtherResults");
		if(sNumberOfOtherResults == null || sNumberOfOtherResults.length() <= 0) return 0;
		try{
			int iNumberOfOtherResults = Integer.parseInt(sNumberOfOtherResults);
			return iNumberOfOtherResults;
		}
		catch(Exception e){
			return 0;
		}	
	}//getNumberOfOtherSystemResults

	/**
	 * get the array of other <system> results
	 * 
	 * @return the array of other <system> results
	 */
	public OtherResult[] getOtherSystemResults(){	
		Element eSystem = (Element)XMLUtil.findChildNode(m_eRoot, "system");
		if(eSystem == null) return null;
		Element eOtherResults = (Element)XMLUtil.findChildNode(eSystem, "otherResults");
		if(eOtherResults == null) return null;
		NodeList others = eOtherResults.getElementsByTagName("other");
		if(others == null || others.getLength() <= 0) return null;
		int iOthers = others.getLength();
		OtherResult[] mOthers = new OtherResult[iOthers];
		for(int i = 0; i < iOthers; i++){
			Element eOther = (Element)others.item(i);
			mOthers[i] =new OtherResult();
			String sName = eOther.getAttribute("name"); 				
			String sValue = eOther.getAttribute("value");
			String sDescription = eOther.getAttribute("description");	
			mOthers[i].name = sName==null?"":sName;
			mOthers[i].value = sValue==null?"":sValue;
			mOthers[i].description = sDescription==null?"":sDescription;
		}
		return mOthers;
	}//getOtherSystemResults

	/**
	 * Get the current state, , which can be:
	 * "busy", "busyButAccepting", "idle", "idleButNotAccepting" and "noResponse".
	 * 
	 * @return the current status, "noResponse" if none.
	 */
	public String getCurrentState(){
		Element eService = (Element)XMLUtil.findChildNode(m_eRoot, "service");
		if(eService == null) return "noResponse";
		String sStatus = XMLUtil.getElementValueByName(eService, "currentState");
		if(sStatus == null || sStatus.length() <= 0) return "noResponse";
		return sStatus;
	}//getCurrentState

	/**
	 * Get the current job count. 
	 * @return the current job count, -1 if none. 
	 */
	public int getCurrentJobCount(){
		Element eService = (Element)XMLUtil.findChildNode(m_eRoot, "service");
		if(eService == null) return -1;
		String sCurrentJobCount = XMLUtil.getElementValueByName(eService, "currentJobCount");
		if(sCurrentJobCount == null || sCurrentJobCount.length() <= 0) return -1;
		try {
			return Integer.parseInt(sCurrentJobCount);
		} 
		catch (Exception e) {
			return -1;
		}
	}//getCurrentJobCount

	/**
	 * Get the total jobs received so far. 
	 * @return the total jobs received so far, -1 if none. 
	 */
	public int getTotalJobsSoFar(){
		Element eService = (Element)XMLUtil.findChildNode(m_eRoot, "service");
		if(eService == null) return -1;
		String sTotalJobsSoFar = XMLUtil.getElementValueByName(eService, "currentJobCount");
		if(sTotalJobsSoFar == null || sTotalJobsSoFar.length() <= 0) return -1;
		try {
			return Integer.parseInt(sTotalJobsSoFar);
		} 
		catch (Exception e) {
			return -1;
		}
	}//getTotalJobsSoFar


	/**
	 * Get the time the service started. 
	 * @return the time last job ended. If none, it returns unix creation time: GregorianCalendar(1970, 0, 1, 0, 0, 0). 
	 */
	public GregorianCalendar getTimeServiceStarted(){
		Element eService = (Element)XMLUtil.findChildNode(m_eRoot, "service");
		if(eService == null) return new GregorianCalendar(1970, 0, 1, 0, 0, 0);
		String sTimeServiceStarted = XMLUtil.getElementValueByName(eService, "timeServiceStarted");
		if(sTimeServiceStarted == null || sTimeServiceStarted.length() <= 0) return new GregorianCalendar(1970, 0, 1, 0, 0, 0);
		try{
			GregorianCalendar timeServiceStarted = XMLUtil.createNativeDateTime(sTimeServiceStarted);
			return timeServiceStarted;
		}
		catch(Exception e){
			return new GregorianCalendar(1970, 0, 1, 0, 0, 0);
		}
	}//getTimeServiceStarted

	/**
	 * Get the service utilization ([0, 1]). 
	 * @return the time last job took, Double.NaN if none. 
	 */
	public double getServiceUtilization(){
		Element eService = (Element)XMLUtil.findChildNode(m_eRoot, "service");
		if(eService == null) return -1;
		String sServiceUtilization = XMLUtil.getElementValueByName(eService, "serviceUtilization");
		if(sServiceUtilization == null || sServiceUtilization.length() <= 0) return Double.NaN;
		try {
			return Double.parseDouble(sServiceUtilization);
		} 
		catch (Exception e) {
			return Double.NaN;
		}
	}//getServiceUtilization

	/**
	 * get the number of other <service> results
	 * 
	 * @return the number of other <service> results
	 */
	public int  getNumberOfOtherServiceResults(){
		Element eService = (Element)XMLUtil.findChildNode(m_eRoot, "service");
		if(eService == null) return 0;
		Element eOtherResults = (Element)XMLUtil.findChildNode(eService, "otherResults");
		if(eOtherResults == null) return 0;
		String sNumberOfOtherResults = eOtherResults.getAttribute("numberOfOtherResults");
		if(sNumberOfOtherResults == null || sNumberOfOtherResults.length() <= 0) return 0;
		try{
			int iNumberOfOtherResults = Integer.parseInt(sNumberOfOtherResults);
			return iNumberOfOtherResults;
		}
		catch(Exception e){
			return 0;
		}	
	}//getNumberOfOtherServiceResults

	/**
	 * get other <service> results
	 * 
	 * @return other <service> results
	 */
	public OtherResult[]  getOtherServiceResults(){
		Element eService = (Element)XMLUtil.findChildNode(m_eRoot, "service");
		if(eService == null) return null;
		Element eOtherResults = (Element)XMLUtil.findChildNode(eService, "otherResults");
		if(eOtherResults == null) return null;
		NodeList others = eOtherResults.getElementsByTagName("other");
		if(others == null || others.getLength() <= 0) return null;
		int iOthers = others.getLength();
		OtherResult[] mOthers = new OtherResult[iOthers];
		for(int i = 0; i < iOthers; i++){
			Element eOther = (Element)others.item(i);
			mOthers[i] =new OtherResult();
			String sName = eOther.getAttribute("name"); 				
			String sValue = eOther.getAttribute("value");
			String sDescription = eOther.getAttribute("description");	
			mOthers[i].name = sName==null?"":sName;
			mOthers[i].value = sValue==null?"":sValue;
			mOthers[i].description = sDescription==null?"":sDescription;
		}
		return mOthers;	
	}//getOtherServiceResults

	/**
	 * Get the job status, , which can be:
	 * "waiting", "running", "killed", "finished" and "unknown".
	 * 
	 * @return the current status, "unknown" if none.
	 */
	public String getJobStatus(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return "unknown";
		String sStatus = XMLUtil.getElementValueByName(eJob, "status");
		if(sStatus == null || sStatus.length() <= 0) return "unknown";
		return sStatus;
	}//getCurrentState


	/**
	 * Get the submit time. 
	 * @return the submit time If none, it returns unix creation time: GregorianCalendar(1970, 0, 1, 0, 0, 0). 
	 */
	public GregorianCalendar getJobSubmitTime(){
		Element eJobSubmitTime = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJobSubmitTime == null) return new GregorianCalendar(1970, 0, 1, 0, 0, 0);
		String sJobSubmitTime = XMLUtil.getElementValueByName(eJobSubmitTime, "submitTime");
		if(sJobSubmitTime == null || sJobSubmitTime.length() <= 0) return new GregorianCalendar(1970, 0, 1, 0, 0, 0);
		try{
			GregorianCalendar jobSubmitTime = XMLUtil.createNativeDateTime(sJobSubmitTime);
			return jobSubmitTime;
		}
		catch(Exception e){
			return new GregorianCalendar(1970, 0, 1, 0, 0, 0);
		}
	}//getJobSubmitTime

	/**
	 * Get the scheduled start time. 
	 * @return the scheduled start time If none, it returns unix creation time: GregorianCalendar(1970, 0, 1, 0, 0, 0). 
	 */
	public GregorianCalendar getScheduledStartTime(){
		Element eJobScheduledStartTime = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJobScheduledStartTime == null) return new GregorianCalendar(1970, 0, 1, 0, 0, 0);
		String sJobScheduledStartTime = XMLUtil.getElementValueByName(eJobScheduledStartTime, "scheduledStartTime");
		if(sJobScheduledStartTime == null || sJobScheduledStartTime.length() <= 0) return new GregorianCalendar(1970, 0, 1, 0, 0, 0);
		try{
			GregorianCalendar jobScheduledStartTime = XMLUtil.createNativeDateTime(sJobScheduledStartTime);
			return jobScheduledStartTime;
		}
		catch(Exception e){
			return new GregorianCalendar(1970, 0, 1, 0, 0, 0);
		}
	}//getScheduledStartTime

	/**
	 * Get the actual start time. 
	 * @return the actual start time If none, it returns unix creation time: GregorianCalendar(1970, 0, 1, 0, 0, 0). 
	 */
	public GregorianCalendar getActualStartTime(){
		Element eJobActualStartTime = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJobActualStartTime == null) return new GregorianCalendar(1970, 0, 1, 0, 0, 0);
		String sJobActualStartTime = XMLUtil.getElementValueByName(eJobActualStartTime, "actualStartTime");
		if(sJobActualStartTime == null || sJobActualStartTime.length() <= 0) return new GregorianCalendar(1970, 0, 1, 0, 0, 0);
		try{
			GregorianCalendar jobActualStartTime = XMLUtil.createNativeDateTime(sJobActualStartTime);
			return jobActualStartTime;
		}
		catch(Exception e){
			return new GregorianCalendar(1970, 0, 1, 0, 0, 0);
		}
	}//getActualStartTime


	/**
	 * Get the end time. 
	 * @return the end time If none, it returns unix creation time: GregorianCalendar(1970, 0, 1, 0, 0, 0). 
	 */
	public GregorianCalendar getEndTime(){
		Element eJobEndTime = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJobEndTime == null) return new GregorianCalendar(1970, 0, 1, 0, 0, 0);
		String sJobEndTime = XMLUtil.getElementValueByName(eJobEndTime, "endTime");
		if(sJobEndTime == null || sJobEndTime.length() <= 0) return new GregorianCalendar(1970, 0, 1, 0, 0, 0);
		try{
			GregorianCalendar jobEndTime = XMLUtil.createNativeDateTime(sJobEndTime);
			return jobEndTime;
		}
		catch(Exception e){
			return new GregorianCalendar(1970, 0, 1, 0, 0, 0);
		}
	}//getEndTime


	/**
	 * Get the job timing information. 
	 * @return the job timing information. 
	 */
	public TimingInformation getTimeInformation(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return null;
		Element eTimingInformation = (Element)XMLUtil.findChildNode(eJob, "timingInformation");
		if(eTimingInformation == null) return null;
		NodeList times = eTimingInformation.getElementsByTagName("time");
		if(times == null || times.getLength() <= 0) return null;
		int iTimes = times.getLength();
		TimingInformation timingInformation = new TimingInformation();
		timingInformation.time = new Time[iTimes];
		for(int i = 0; i < iTimes; i++){
			Element eTime = (Element)times.item(i);
			timingInformation.time[i] =new Time();
			String sType = eTime.getAttribute("type"); 				
			String sCategory = eTime.getAttribute("category"); 				
			String sUnit = eTime.getAttribute("unit"); 				
			String sDescription = eTime.getAttribute("description");	
			String sValue = eTime.getAttribute("value");
			timingInformation.time[i].type = sType==null?"":sType;
			timingInformation.time[i].category = sCategory==null?"":sCategory;
			timingInformation.time[i].unit = sUnit==null?"":sUnit;
			timingInformation.time[i].description = sDescription==null?"":sDescription;
			try {
				timingInformation.time[i].value = Double.parseDouble(sValue);
			} 
			catch (Exception e) {
				timingInformation.time[i].value = Double.NaN;
			}
		}
		return timingInformation;
	}//getTimeInformation

	/**
	 * Get the system used CPU Speed value, unit and description. 
	 * 
	 * @return the used system CPU Speed. 
	 */
	public CPUSpeed getUsedCPUSpeed(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return null;
		Element eUsedCPUSpeed = (Element)XMLUtil.findChildNode(eJob, "usedCPUSpeed");
		if(eUsedCPUSpeed == null) return null;
		String sUsedCPUSpeed = XMLUtil.getElementValue(eUsedCPUSpeed);
		if(sUsedCPUSpeed == null || sUsedCPUSpeed.length() <= 0) return null;
		CPUSpeed cpuSpeed = new CPUSpeed();
		try{
			if(sUsedCPUSpeed.equals("INF")) cpuSpeed.value = Double.POSITIVE_INFINITY;
			if(sUsedCPUSpeed.equals("-INF")) cpuSpeed.value = Double.NEGATIVE_INFINITY;
			if(sUsedCPUSpeed.equals("NaN") || sUsedCPUSpeed.equals("-NaN")) cpuSpeed.value = Double.NaN;			
			double dUsedCPUSpeed = Double.parseDouble(sUsedCPUSpeed);
			cpuSpeed.value = dUsedCPUSpeed;
			cpuSpeed.unit = eUsedCPUSpeed.getAttribute("unit");
			cpuSpeed.description = eUsedCPUSpeed.getAttribute("description");
			return cpuSpeed;
		}
		catch(Exception e){
			return null;
		}
	}//getUsedCPUSpeed


	/**
	 * Get the job used CPU Number value and description. 
	 * 
	 * @return the used job CPU number. 
	 */
	public CPUNumber getUsedCPUNumber(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return null;
		Element eUsedCPUNumber = (Element)XMLUtil.findChildNode(eJob, "usedCPUNumber");
		if(eUsedCPUNumber == null) return null;
		String sUsedCPUNumber = XMLUtil.getElementValue(eUsedCPUNumber);
		if(sUsedCPUNumber == null || sUsedCPUNumber.length() <= 0) return null;
		CPUNumber cpuNumber = new CPUNumber();
		try{
			int iUsedCPUNumber = Integer.parseInt(sUsedCPUNumber);
			cpuNumber.value = iUsedCPUNumber;
			cpuNumber.description = eUsedCPUNumber.getAttribute("description");
			return cpuNumber;
		}
		catch(Exception e){
			return null;
		}
	}//getUsedCPUNumber

	/**
	 * Get the job available disk space value, unit and description. 
	 * 
	 * @return the available job disk space. 
	 */
	public DiskSpace getUsedDiskSpace(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return null;
		Element eUsedDiskSpace = (Element)XMLUtil.findChildNode(eJob, "usedDiskSpace");
		if(eUsedDiskSpace == null) return null;
		String sUsedDiskSpace = XMLUtil.getElementValue(eUsedDiskSpace);
		if(sUsedDiskSpace == null || sUsedDiskSpace.length() <= 0) return null;
		DiskSpace diskSpace = new DiskSpace();
		try{
			if(sUsedDiskSpace.equals("INF")) diskSpace.value = Double.POSITIVE_INFINITY;
			if(sUsedDiskSpace.equals("-INF")) diskSpace.value = Double.NEGATIVE_INFINITY;
			if(sUsedDiskSpace.equals("NaN") || sUsedDiskSpace.equals("-NaN")) diskSpace.value = Double.NaN;			
			double dUsedDiskSpace = Double.parseDouble(sUsedDiskSpace);
			diskSpace.value = dUsedDiskSpace;
			diskSpace.unit = eUsedDiskSpace.getAttribute("unit");
			diskSpace.description = eUsedDiskSpace.getAttribute("description");
			return diskSpace;
		}
		catch(Exception e){
			return null;
		}
	}//getUsedDiskSpace

	/**
	 * Get the job used memory value, unit and description. 
	 * 
	 * @return the used job memory. 
	 */
	public MemorySize getUsedMemory(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return null;
		Element eUsedMemory = (Element)XMLUtil.findChildNode(eJob, "usedMemory");
		if(eUsedMemory == null) return null;
		String sUsedMemory = XMLUtil.getElementValue(eUsedMemory);
		if(sUsedMemory == null || sUsedMemory.length() <= 0) return null;
		MemorySize memory = new MemorySize();
		try{
			if(sUsedMemory.equals("INF")) memory.value = Double.POSITIVE_INFINITY;
			if(sUsedMemory.equals("-INF")) memory.value = Double.NEGATIVE_INFINITY;
			if(sUsedMemory.equals("NaN") || sUsedMemory.equals("-NaN")) memory.value = Double.NaN;			
			double dUsedMemory = Double.parseDouble(sUsedMemory);
			memory.value = dUsedMemory;
			memory.unit = eUsedMemory.getAttribute("unit");
			memory.description = eUsedMemory.getAttribute("description");
			return memory;
		}
		catch(Exception e){
			return null;
		}
	}//getUsedMemory

	/**
	 * get the number of other <service> results
	 * 
	 * @return the number of other <job> results
	 */
	public int  getNumberOfOtherJobResults(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return 0;
		Element eOtherResults = (Element)XMLUtil.findChildNode(eJob, "otherResults");
		if(eOtherResults == null) return 0;
		String sNumberOfOtherResults = eOtherResults.getAttribute("numberOfOtherResults");
		if(sNumberOfOtherResults == null || sNumberOfOtherResults.length() <= 0) return 0;
		try{
			int iNumberOfOtherResults = Integer.parseInt(sNumberOfOtherResults);
			return iNumberOfOtherResults;
		}
		catch(Exception e){
			return 0;
		}	
	}//getNumberOfOtherJobResults

	/**
	 * get other <job> results
	 * 
	 * @return other <job> results
	 */
	public OtherResult[]  getOtherJobResults(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return null;
		Element eOtherResults = (Element)XMLUtil.findChildNode(eJob, "otherResults");
		if(eOtherResults == null) return null;
		NodeList others = eOtherResults.getElementsByTagName("other");
		if(others == null || others.getLength() <= 0) return null;
		int iOthers = others.getLength();
		OtherResult[] mOthers = new OtherResult[iOthers];
		for(int i = 0; i < iOthers; i++){
			Element eOther = (Element)others.item(i);
			mOthers[i] =new OtherResult();
			String sName = eOther.getAttribute("name"); 				
			String sValue = eOther.getAttribute("value");
			String sDescription = eOther.getAttribute("description");	
			mOthers[i].name = sName==null?"":sName;
			mOthers[i].value = sValue==null?"":sValue;
			mOthers[i].description = sDescription==null?"":sDescription;
		}
		return mOthers;
	}//getOtherJobResults

	/**
	 * Get variable number. 
	 * 
	 * @return variable number, -1 if no information. 
	 */
	public int getVariableNumber(){
		if(m_iVariableNumber == -1){
			Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
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
			Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
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
			Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
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
			Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
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
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
		if(eOptimization == null){
			m_bProcessOptimizationResult = true;
			return true;
		}
		m_optimizationResult = new OptimizationResult();

		String sVariableNumber =  eOptimization.getAttribute("numberOfVariables");
		m_iVariableNumber = Integer.parseInt(sVariableNumber);
		m_optimizationResult.numberOfVariables = m_iVariableNumber;

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
					solution.targetObjectiveIdx = Integer.parseInt(sObjectiveIdx);
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
							String sSubstatusType = "";
							String sSubstatusDescription = "";
							String sSubstatusValue = XMLUtil.getElementValue(eSubstatus);
							solution.status.substatus[j].value = sSubstatusValue;
							for (int k = 0; k < n; k++) {
								Node attr = attributes.item(k);
								String sLocalName = attr.getNodeName();
								String sValue = attr.getNodeValue();
								if (sLocalName.equals("name")){
									sSubstatusType = sValue;
									solution.status.substatus[j].type = sSubstatusType;
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
									String sValue = XMLUtil.getElementValue(((Element)vars.item(j)));
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
								String sValue = XMLUtil.getElementValue((Element)vars.item(j));
								solution.variables.valuesString.var[j].value = sValue;
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
								solution.variables.other[j].name = eOther.getAttribute("name");
								solution.variables.other[j].value = eOther.getAttribute("value");
								solution.variables.other[j].description = eOther.getAttribute("description");
								for(int k = 0; k < iVars; k++){
									solution.variables.other[j].var[k] = new OtherVarResult();
									try{
										int iIndex = Integer.parseInt(((Element)vars.item(k)).getAttribute("idx"));
										solution.variables.other[j].var[k].idx = iIndex;
										String sValue = XMLUtil.getElementValue((Element)vars.item(k));
										if(sValue != null && sValue.length() > 0){
											solution.variables.other[j].var[k].value = sValue;
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
									String sValue = XMLUtil.getElementValue((Element)objs.item(j));
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
								solution.objectives.other[j].name = eOther.getAttribute("name");
								solution.objectives.other[j].value = eOther.getAttribute("value");
								solution.objectives.other[j].description = eOther.getAttribute("description");
								for(int k = 0; k < iObjs; k++){
									solution.objectives.other[j].obj[k] = new OtherObjResult();
									try{
										int iIndex = Integer.parseInt(((Element)objs.item(k)).getAttribute("idx"));
										solution.objectives.other[j].obj[k].idx = iIndex;
										String sValue = XMLUtil.getElementValue((Element)objs.item(k));
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
									String sValue = XMLUtil.getElementValue((Element)cons.item(j));
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
									solution.constraints.dualValues.con[j].value = dValue;
								}
								catch(Exception e){									
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
								solution.constraints.other[j].name = eOther.getAttribute("name");
								solution.constraints.other[j].value = eOther.getAttribute("value");
								solution.constraints.other[j].description = eOther.getAttribute("description");
								for(int k = 0; k < icons; k++){
									solution.constraints.other[j].con[k] = new OtherConResult();
									try{
										int iIndex = Integer.parseInt(((Element)cons.item(k)).getAttribute("idx"));
										solution.constraints.other[j].con[k].idx = iIndex;
										String sValue = XMLUtil.getElementValue((Element)cons.item(k));
										if(sValue != null && sValue.length() > 0){
											solution.constraints.other[j].con[k].value = sValue;
										}
									}
									catch(Exception e){									
									}
								}
							}
						}
					}
				}//solution constraints

				Element eOtherSolutionResults = (Element)XMLUtil.findChildNode(eSolution, "otherSolutionResults");
				if(eOtherSolutionResults != null){
					solution.otherSolutionResults = new SolutionResults();
					Vector<Element> vOtherOptimizationSolutionResults = XMLUtil.getChildElementsByTagName(eOtherSolutionResults, "otherSolutionResult");
					if(vOtherOptimizationSolutionResults != null && vOtherOptimizationSolutionResults.size() > 0){
						int iOthers = vOtherOptimizationSolutionResults.size();
						solution.otherSolutionResults.otherSolutionResult = new OtherSolutionResult[iOthers];
						for(int j = 0; j < iOthers; j++){
							Element eOther = (Element)vOtherOptimizationSolutionResults.elementAt(j);						
							solution.otherSolutionResults.otherSolutionResult[j] = new OtherSolutionResult();
							solution.otherSolutionResults.otherSolutionResult[j].name = eOther.getAttribute("name");
							solution.otherSolutionResults.otherSolutionResult[j].category = eOther.getAttribute("category");
							solution.otherSolutionResults.otherSolutionResult[j].type = eOther.getAttribute("type");
							solution.otherSolutionResults.otherSolutionResult[j].description = eOther.getAttribute("description");
							solution.otherSolutionResults.otherSolutionResult[j].value = XMLUtil.getElementValue(eOther);
						}//for each other result
					}//solution other results
				}
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
			if(m_optimizationResult.solution[i].targetObjectiveIdx != objIdx) continue;
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
			if(m_optimizationResult.solution[i].targetObjectiveIdx != objIdx) continue;
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
			if(m_optimizationResult.solution[i].targetObjectiveIdx != objIdx) continue;
			if(m_optimizationResult.solution[i].constraints == null) continue;
			if(m_optimizationResult.solution[i].constraints.dualValues == null) continue;
			if((m_optimizationResult.solution[i].status.type.endsWith("ptimal") && mdValues == null)||
					m_optimizationResult.solution[i].status.type.equals("globallyOptimal")){				
				DualVarValue[] con = m_optimizationResult.solution[i].constraints.dualValues.con; 
				int iCons = (con==null)?0:con.length;
				mdValues = new double[iNumberOfConstraints];
				for(int j = 0; j < iCons; j++){
					if(!Double.isNaN(con[j].value) && con[j].value != 0){
						mdValues[con[j].idx] = con[j].value;
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
		return m_optimizationResult.solution[solIdx].targetObjectiveIdx;		
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
	public String[] getVariableStringValues(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || m_optimizationResult.solution.length <= 0) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		int iSolutions = m_optimizationResult.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		if(m_optimizationResult.solution[solIdx].variables == null) return null;
		if(m_optimizationResult.solution[solIdx].variables.valuesString == null) return null;
		VarStringValue[] var = m_optimizationResult.solution[solIdx].variables.valuesString.var; 
		int iVars = (var==null)?0:var.length;
		String[] msValues = new String[iNumberOfVariables];
		for(int i = 0; i < iVars; i++){
			msValues[var[i].idx] = var[i].value;
		}
		return msValues;	
	}//getVariableStringValues

	/**
	 * Get the [i]th optimization solution's other (non-standard/solver specific)variable-related results, 
	 * where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the other variable results. 
	 * @return an array of other variable results in OtherVariableResult[] array data structure, null if none. 
	 * Each other variable result contains the name (required), an optional description (string) and an optional
	 * value (string). Each other variable result can also optionally contain an array OtherVarResult for each variable. 
	 * The OtherVarResult contains a variable idx (required), and an optional string value.  
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
	 * Get the [i]th optimization solution's dual variable values, where i equals the given solution index. 
	 * 
	 * @param solIdx holds the solution index to get the dual variable values. 
	 * @return a double dense array of the dual variable values, null if none. 
	 */
	public double[] getDualVariableValues(int solIdx){
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
			if(!Double.isNaN(con[j].value)){
				mdValues[con[j].idx] = con[j].value;
			}
		}
		return mdValues;
	}//getDualVariableValues

	/**
	 * Get the [i]th optimization solution's other (non-standard/solver specific)constraint-related results, 
	 * where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the other constraint results. 
	 * @return an array of other constraint results in OtherConstraintResult[] array data structure, null if none. 
	 * Each other constraint result contains the name (required), an optional description (string) and an optional
	 * value (string). Each other constraint result can also optionally contain an array OtherConResult for each constraint. 
	 * The OtherConResult contains a constraint idx (required), and an optional string value.  
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
	public OtherSolutionResult[] getOtherOptimizationSolutionResults(int solIdx){
		processOptimizationResult();
		if(m_optimizationResult == null) return null;
		if(m_optimizationResult.solution == null || m_optimizationResult.solution.length <= 0) return null;
		int iSolutions = m_optimizationResult.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(m_optimizationResult.solution[solIdx] == null) return null;
		if(m_optimizationResult.solution[solIdx].otherSolutionResults == null) return null;
		return m_optimizationResult.solution[solIdx].otherSolutionResults.otherSolutionResult;	
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
		System.out.println(XMLUtil.createXSDateTime(osrlReader.getResultTimeStamp()));
		System.out.println(osrlReader.getInstanceName());
		System.out.println(osrlReader.getServiceName());
		System.out.println(osrlReader.getServiceURI());


//		System.out.println(osrlReader.getOtherResultNumber());
//		String sValue = osrlReader.getOtherResultValueByName("ad");
//		if(sValue == null) System.out.println("null");
//		else System.out.println(sValue);
//		String sDescription = osrlReader.getOtherResultDescriptionByName("a");
//		System.out.println(sDescription);
//		for(int i=0;i<osrlReader.getOtherResultNumber();i++){
//			System.out.println(osrlReader.getOtherResultNames()[i]);
//			System.out.println(osrlReader.getOtherResultValues()[i]);
//			System.out.println(osrlReader.getOtherResultDescriptions()[i]);
//		}

		System.out.println("get process stat");
		System.out.println(osrlReader.getCurrentState());
		System.out.println(osrlReader.getAvailableDiskSpace());
		System.out.println(osrlReader.getAvailableMemory());
		System.out.println(osrlReader.getCurrentJobCount());
		System.out.println(osrlReader.getTotalJobsSoFar());
//		System.out.println(XMLUtil.createXSDateTime(osrlReader.getTimeLastJobEnded()));
//		System.out.println(XMLUtil.createXSDateTime(osrlReader.getTimeServiceStarted()));
//		System.out.println(osrlReader.getTimeLastJobTook());
//		System.out.println(osrlReader.getServiceUtilization());
//		ProcessStatistics processStatistics = osrlReader.getProcessStatistics();
//		System.out.println(processStatistics.currentState);
//		System.out.println(processStatistics.availableDiskSpace);
//		System.out.println(processStatistics.availableMemory);
//		System.out.println(processStatistics.currentJobCount);
//		System.out.println(processStatistics.totalJobsSoFar);
//		System.out.println(XMLUtil.createXSDateTime(processStatistics.timeLastJobEnded));
//		System.out.println(XMLUtil.createXSDateTime(processStatistics.timeServiceStarted));
//		System.out.println(processStatistics.timeLastJobTook);
//		System.out.println(processStatistics.serviceUtilization);
//		Jobs jobs = processStatistics.jobs;
//		if(jobs != null){
//			JobStatistics[] mJobStatistics = jobs.job;
//			int iJobStatistics = mJobStatistics==null?0:mJobStatistics.length; 
//			if(iJobStatistics > 0){
//				System.out.println(iJobStatistics);
//				System.out.println(mJobStatistics[0].jobID);
//				System.out.println(mJobStatistics[0].duration);
//				if(mJobStatistics[0].dependencies != null)
//					System.out.println(mJobStatistics[0].dependencies.jobID[0]);
//			}
//		}


		System.out.println(osrlReader.getVariableNumber());	
		System.out.println(osrlReader.getObjectiveNumber());
		System.out.println(osrlReader.getConstraintNumber());
		System.out.println(osrlReader.getSolutionNumber());
		for(int i = 0; i < osrlReader.getSolutionNumber(); i++){
			System.out.println("************solution: " + i);
			System.out.println(osrlReader.getSolutionStatusType(i));			
			System.out.println(osrlReader.getSolutionStatusDescription(i));			
			System.out.println(osrlReader.getSolutionObjectiveIndex(i));			
			System.out.println(osrlReader.getSolutionMessage(i));	
			OptimizationSolutionSubstatus[] substatus = osrlReader.getSolutionSubStatuses(i);
			System.out.println("sub # " + (substatus==null?0:substatus.length));
			OptimizationSolutionStatus optStatus = osrlReader.getSolutionStatus(i);
			System.out.println(optStatus.type);
			System.out.println(osrlReader.getVariableValues(i)[0]);
			System.out.println(osrlReader.getVariableStringValues(i)[0]);
			OtherVariableResult[] otherVar = osrlReader.getOtherVariableResults(i);
			if(otherVar != null){
				System.out.println(otherVar.length);
				System.out.println(otherVar[0].name);
				System.out.println(otherVar[0].value);
				System.out.println(otherVar[0].description);
				System.out.println(otherVar[0].var[0].idx);
				System.out.println(otherVar[0].var[0].value);
			}
			System.out.println(osrlReader.getObjectiveValues(i)[0]);
			OtherObjectiveResult[] otherObj = osrlReader.getOtherObjectiveResults(i);
			if(otherObj != null){
				System.out.println(otherObj.length);
				System.out.println(otherObj[0].name);
				System.out.println(otherObj[0].value);
				System.out.println(otherObj[0].description);
				System.out.println(otherObj[0].obj[0].idx);
				System.out.println(otherObj[0].obj[0].value);
			}
			double[] mdValues = osrlReader.getDualVariableValues(i);
			System.out.println(mdValues==null?"null":mdValues[0]+"");

			OtherConstraintResult[] otherCon = osrlReader.getOtherConstraintResults(i);
			if(otherCon != null){
				System.out.println(otherCon.length);
				System.out.println(otherCon[0].name);
				System.out.println(otherCon[0].value);
				System.out.println(otherCon[0].description);
				System.out.println(otherCon[0].con[0].idx);
				System.out.println(otherCon[0].con[0].value);
			}

			OtherSolutionResult[] otherOPT = osrlReader.getOtherOptimizationSolutionResults(i);
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
