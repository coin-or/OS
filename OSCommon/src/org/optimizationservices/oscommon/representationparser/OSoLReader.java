/**
 * @(#)OSoLReader 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.representationparser;

import java.util.Collection;
import java.util.GregorianCalendar;
import java.util.HashMap;
import java.util.Set;
import java.util.Vector;

import org.optimizationservices.oscommon.localinterface.OSOption;
import org.optimizationservices.oscommon.util.IOUtil;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.XMLUtil;
import org.w3c.dom.Element;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

/**
 * The <c>OSoLReader</c> class parses an OSoL instance into a DOM tree and
 * provides a set of "get" methods that can be used to retrieve different 
 * pieces of information of the instance.
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */
public class OSoLReader extends OSgLReader{	
	/**
	 * m_osOption holds the standard OSOption, which is a local interface for 
	 * storing Optimization Services option. 
	 */
	protected OSOption m_osOption = null;

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
	 * m_otherOptmizationOptionHashMap holds a hash map of other optimization options.
	 */
	protected HashMap<String, String> m_otherOptimizationOptionHashMap = null;

	/**
	 * m_otherOptimizationOptionDescriptionHashMap holds a hash map of other optimization options' descriptions.
	 */
	protected HashMap<String, String>	m_otherOptimizationOptionDescriptionHashMap = null;

	/**
	 * m_otherOptionHashMap holds a hash map of other options.
	 */
	protected HashMap<String, String> m_otherOptionHashMap = null;

	/**
	 * m_otherOptionDescriptionHashMap holds a hash map of other options' descriptions.
	 */
	protected HashMap<String, String>	m_otherOptionDescriptionHashMap = null;

	/**
	 * constructor.
	 * @param validate holds whether the reader	should be validating against the schema	or not.
	 */
	public OSoLReader(boolean validate){
		m_bXsdValidate = validate;
	}//constructor

	/**
	 * Default	constructor. 
	 * 
	 */
	public OSoLReader(){
	}//constructor
	
	/**
	 * get the standard OSOption, a local interface for 
	 * storing Optimization Services option.
	 * 
	 * @return the OSOption. 
	 * @throws Exception if there are errors getting the OSOption. 
	 */
   	public OSOption getOSOption() throws Exception{
		if(m_osOption != null){
			return m_osOption;
		}
		m_osOption = new OSOption();
		if(!m_osOption.setServiceURI(getServiceURI())) throw new Exception("setServiceURI Unsuccessful");		
		if(!m_osOption.setServiceName(getServiceName())) throw new Exception("setServiceName Unsuccessful");		
		if(!m_osOption.setInstanceName(getInstanceName())) throw new Exception("setInstanceName Unsuccessful");		
		if(!m_osOption.setInstanceLocationType(getInstanceLocationType())) throw new Exception("setInstanceLocationType Unsuccessful");		
		if(!m_osOption.setInstanceAddress(getInstanceAddress())) throw new Exception("setInstanceAddress Unsuccessful");		
		if(!m_osOption.setJobID(getJobID())) throw new Exception("setJobID Unsuccessful");		
		if(!m_osOption.setLicense(getLicense())) throw new Exception("setLicense Unsuccessful");		
		if(!m_osOption.setUserName(getUserName())) throw new Exception("setUserName Unsuccessful");		
		if(!m_osOption.setPassword(getPassword())) throw new Exception("setPassword Unsuccessful");		
		if(!m_osOption.setContactTransportType(getContactTransportType())) throw new Exception("setContactTransportType Unsuccessful");		
		if(!m_osOption.setContactAddress(getContactAddress())) throw new Exception("setContactAddress Unsuccessful");		
		if(!m_osOption.setSystemMinDiskSpace(getSystemMinDiskSpace())) throw new Exception("setSystemMinDiskSpace Unsuccessful");		
		if(!m_osOption.setSystemMinMemorySize(getSystemMinMemorySize())) throw new Exception("setSystemMinMemorySize Unsuccessful");		
		if(!m_osOption.setSystemMinCPUSpeed(getSystemMinCPUSpeed())) throw new Exception("setSystemMinCPUSpeed Unsuccessful");		
		if(!m_osOption.setServiceType(getServiceType())) throw new Exception("setServiceType Unsuccessful");		
		if(!m_osOption.setJobMaxTime(getJobMaxTime())) throw new Exception("setJobMaxTime Unsuccessful");		
		if(!m_osOption.setJobScheduledStartTime(getJobScheduledStartTime())) throw new Exception("setJobScheduledStartTime Unsuccessful");		
		if(!m_osOption.setJobDependencies(getJobDependencies())) throw new Exception("setJobDependencies Unsuccessful");		
		if(!m_osOption.setRequiredDirectoriesAndFiles(getRequiredDirectoriesAndFiles())) throw new Exception("setRequiredDirectoriesAndFiles Unsuccessful");		
		if(!m_osOption.setDirectoriesToMake(getDirectoriesToMake())) throw new Exception("setDirectoriesToMake Unsuccessful");		
		if(!m_osOption.setFilesToCreate(getFilesToCreate())) throw new Exception("setFilesToCreate Unsuccessful");		
		if(!m_osOption.setInputFilesToCopyFrom(getInputFilesToCopyFrom())) throw new Exception("setInputFilesToCopyFrom Unsuccessful");		
		if(!m_osOption.setInputFilesToCopyTo(getInputFilesToCopyTo())) throw new Exception("setInputFilesToCopyTo Unsuccessful");		
		if(!m_osOption.setInputFilesToMoveFrom(getInputFilesToMoveFrom())) throw new Exception("setInputFilesToMoveFrom Unsuccessful");		
		if(!m_osOption.setInputFilesToMoveTo(getInputFilesToMoveTo())) throw new Exception("setInputFilesToMoveTo Unsuccessful");		
		if(!m_osOption.setOutputFilesToCopyFrom(getOutputFilesToCopyFrom())) throw new Exception("setOutputFilesToCopyFrom Unsuccessful");		
		if(!m_osOption.setOutputFilesToCopyTo(getOutputFilesToCopyTo())) throw new Exception("setOutputFilesToCopyTo Unsuccessful");		
		if(!m_osOption.setOutputFilesToMoveFrom(getOutputFilesToMoveFrom())) throw new Exception("setOutputFilesToMoveFrom Unsuccessful");		
		if(!m_osOption.setOutputFilesToMoveTo(getOutputFilesToMoveTo())) throw new Exception("setOutputFilesToMoveTo Unsuccessful");		
		if(!m_osOption.setFilesToDelete(getFilesToDelete())) throw new Exception("setFilesToDelete Unsuccessful");		
		if(!m_osOption.setDirectoriesToDelete(getDirectoriesToDelete())) throw new Exception("setDirectoriesToDelete Unsuccessful");		
		if(!m_osOption.setProcessesToKill(getProcessesToKill())) throw new Exception("setProcessesToKill Unsuccessful");		
		if(!m_osOption.setVariableNumber(getVariableNumber())) throw new Exception("setVariableNumber Unsuccessful");		
		if(!m_osOption.setObjectiveNumber(getObjectiveNumber())) throw new Exception("setObjectiveNumber Unsuccessful");		
		if(!m_osOption.setConstraintNumber(getConstraintNumber())) throw new Exception("setConstraintNumber Unsuccessful");		
		if(!m_osOption.setInitialVariableValues(getInitialVariableValues())) throw new Exception("setInitialVariableValues Unsuccessful");		
		if(!m_osOption.setOtherOptimizationOptions(getOtherOptimizationOptionNames(), getOtherOptimizationOptionDescriptions(), getOtherOptimizationOptionValues())) throw new Exception("setOtherOptimizationOptionInfo Unsuccessful");
		if(!m_osOption.setOtherOptions(getOtherOptionNames(), getOtherOptionDescriptions(), getOtherOptionValues())) throw new Exception("setOtherOptionInfo Unsuccessful");
		return m_osOption;
   	}//getOSOption

	

   	/**
	 * Get service uri.
	 * 
	 * @return the service uri. 
	 */
	public String getServiceURI(){
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eRoot, "general");
		if(eGeneral == null) return "";
		String sServiceURI = XMLUtil.getElementValueByName(eGeneral, "serviceURI");
		if(sServiceURI == null) return "";
		return sServiceURI;	
	}//getServiceURI
	
	
   	/**
	 * Get service name.
	 * 
	 * @return the service name. 
	 */
	public String getServiceName(){
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eRoot, "general");
		if(eGeneral == null) return "";
		String sServiceName = XMLUtil.getElementValueByName(eGeneral, "serviceName");
		if(sServiceName == null) return "";
		return sServiceName;	
	}//getServiceName

	
   	/**
	 * Get instance name.
	 * 
	 * @return the instance name. 
	 */
	public String getInstanceName(){
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eRoot, "general");
		if(eGeneral == null) return "";
		String sInstanceName = XMLUtil.getElementValueByName(eGeneral, "instanceName");
		if(sInstanceName == null) return "";
		return sInstanceName;	
	}//getInstanceName

	/**
	 * Get the instance location type to get the instance. 
	 * e.g. local, http, ftp.
	 * 
	 * @return the instance location type, null or empty string if none. 
	 */
	public String getInstanceLocationType(){
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eRoot, "general");
		if(eGeneral == null) return "";
		Element eInstanceLocation = (Element)XMLUtil.findChildNode(eGeneral, "instanceLocation");
		if(eInstanceLocation == null) return "";
		String sLocationType = eInstanceLocation.getAttribute("locationType");
		if(sLocationType == null || sLocationType.length() <= 0) return "local";
		return sLocationType;
	}//getInstanceLocationType
	
	
	/**
	 * Get the instance address to get the instance. 
	 * 
	 * @return the instance address, null or empty string if none. 
	 */
	public String getInstanceAddress(){
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eRoot, "general");
		if(eGeneral == null) return "";
		String sInstanceAddress = XMLUtil.getElementValueByName(eGeneral, "instanceLocation");
		if(sInstanceAddress == null) return "";
		return sInstanceAddress;
	}//getInstanceAddress

	
	/**
	 * get the job ID
	 * @return the Job ID
	 */
	public String getJobID(){
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eRoot, "general");
		if(eGeneral == null) return "";
		String sJobID = XMLUtil.getElementValueByName(eGeneral, "jobID");
		if(sJobID == null) return "";
		return sJobID;			
	}//getJobID

	/**
	 * Get license. 
	 * 
	 * @return the license, null or empty string if none. 
	 */
	public String getLicense(){
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eRoot, "general");
		if(eGeneral == null) return "";
		String sLicense = XMLUtil.getElementValueByName(eGeneral, "license");
		if(sLicense == null) return "";
		return sLicense;	
	}//getLicense
	

	/**
	 * Get the userName. 
	 * 
	 * @return the user name, null or empty string if none. 
	 */
	public String getUserName(){
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eRoot, "general");
		if(eGeneral == null) return "";
		String sUserName = XMLUtil.getElementValueByName(eGeneral, "userName");
		if(sUserName == null) return "";
		return sUserName;
	}//getUserName
	
	
	/**
	 * Get the password. 
	 * 
	 * @return the password, null or empty string if none. 
	 */
	public String getPassword(){
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eRoot, "general");
		if(eGeneral == null) return "";
		String sPassword = XMLUtil.getElementValueByName(eGeneral, "password");
		if(sPassword == null) return "";
		return sPassword;
	}//getPassword

	
	/**
	 * Get the contact transport type to respond to the requester,
	 * smtp (for email), osp (for knocking back on the requester), etc.
	 * 
	 * @return the contact trasport type, null or empty string if none. 
	 */
	public String getContactTransportType(){
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eRoot, "general");
		if(eGeneral == null) return "";
		Element eContact = (Element)XMLUtil.findChildNode(eGeneral, "contact");
		if(eContact == null) return "";
		String sTransportType = eContact.getAttribute("transportType");
		if(sTransportType == null || sTransportType.length() <= 0) return "osp";
		return sTransportType;
	}//getContactTransportType
	
	
	/**
	 * Get the contact address to respond to the requester. 
	 * For example it can be an email address if the contact transport type is smtp
	 * or a http uri if the contact transport type is osp (for knocking back on the requester), etc.
	 * 
	 * @return the contact trasport address, null or empty string if none. 
	 */
	public String getContactAddress(){
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eRoot, "general");
		if(eGeneral == null) return "";
		String sContactAddress = XMLUtil.getElementValueByName(eGeneral, "contact");
		if(sContactAddress == null) return "";
		return sContactAddress;
	}//getContactAddress
	
	
	/**
	 * Get the system minimum disk space required to solve the job. 
	 * 
	 * @return the system minimum disk space, 0.0 if none. 
	 */
	public double getSystemMinDiskSpace(){
		Element eSystem = (Element)XMLUtil.findChildNode(m_eRoot, "system");
		if(eSystem == null) return 0.0;
		String sMinDiskSpace = XMLUtil.getElementValueByName(eSystem, "minDiskSpace");
		if(sMinDiskSpace == null || sMinDiskSpace.length() <= 0) return 0.0;
		try{
			double dMinDiskSpace = Double.parseDouble(sMinDiskSpace);
			return dMinDiskSpace;
		}
		catch(Exception e){
			return 0.0;
		}
	}//getSystemMinDiskSpace
	

	/**
	 * Get the system minimum memory size required to solve the job. 
	 * 
	 * @return the system minimum memory size, 0.0 if none. 
	 */
	public double getSystemMinMemorySize(){
		Element eSystem = (Element)XMLUtil.findChildNode(m_eRoot, "system");
		if(eSystem == null) return 0.0;
		String sMinMemorySize = XMLUtil.getElementValueByName(eSystem, "minMemorySize");
		if(sMinMemorySize == null || sMinMemorySize.length() <= 0) return 0.0;
		try{
			double dMinMemorySize = Double.parseDouble(sMinMemorySize);
			return dMinMemorySize;
		}
		catch(Exception e){
			return 0.0;
		}
	}//getSystemMinMeorySize

	/**
	 * Get the system minimum cpu speed required to solve the job. 
	 * 
	 * @return the system minimum cpu speed, 0.0 if none. 
	 */
	public double getSystemMinCPUSpeed(){
		Element eSystem = (Element)XMLUtil.findChildNode(m_eRoot, "system");
		if(eSystem == null) return 0.0;
		String sMinCPUSpeed = XMLUtil.getElementValueByName(eSystem, "minCPUSpeed");
		if(sMinCPUSpeed == null || sMinCPUSpeed.length() <= 0) return 0.0;
		try{
			double dMinCPUSpeed = Double.parseDouble(sMinCPUSpeed);
			return dMinCPUSpeed;
		}
		catch(Exception e){
			return 0.0;
		}
	}//getSystemMinCPUSpeed

	/**
	 * Get the service type, which can be: 
	 * solver, analyzer, scheduler, simulation, registry, modeler, agent 
	 * 
	 * @return the service type; null or empty string if none. 
	 */
	public String getServiceType(){
		Element eService = (Element)XMLUtil.findChildNode(m_eRoot, "service");
		if(eService == null) return "solver";
		String sServiceType = XMLUtil.getElementValueByName(eService, "type");
		if(sServiceType == null || sServiceType.length() <= 0) return "solver";
		return sServiceType;
	}//getServiceType
	

	/**
	 * Get the maximum time (in seconds) before the job is terminated.  
	 * 
	 * @return the maximum time, Double.POSITIVE_INFINITY if none. 
	 */
	public double getJobMaxTime(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return Double.POSITIVE_INFINITY;
		String sJobMaxTime = XMLUtil.getElementValueByName(eJob, "maxTime");
		if(sJobMaxTime == null || sJobMaxTime.length() <= 0) return Double.POSITIVE_INFINITY;
		try{
			double dJobMaxTime = Double.parseDouble(sJobMaxTime);
			return dJobMaxTime;
		}
		catch(Exception e){
			return Double.POSITIVE_INFINITY;
		}
	}//getJobMaxTime

	/**
	 * Get the scheduled start time for the job.   
	 * 
	 * @return the scheduled start time for the job, null or UNIX time (1970/1/1) if none. 
	 */
	public GregorianCalendar getJobScheduledStartTime(){ 
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return new GregorianCalendar(1970, 0, 1, 0, 0, 0);
		String sJobScheduledStartTime = XMLUtil.getElementValueByName(eJob, "scheduledStartTime");
		if(sJobScheduledStartTime == null || sJobScheduledStartTime.length() <= 0) return new GregorianCalendar(1970, 0, 1, 0, 0, 0);
		try{
			GregorianCalendar jobScheduledStartTime = XMLUtil.createNativeDateTime(sJobScheduledStartTime);
			return jobScheduledStartTime;
		}
		catch(Exception e){
			return new GregorianCalendar(1970, 0, 1, 0, 0, 0);
		}
	}//getJobScheduledStartTime
	
	/**
	 * Get the dependencies of the current job, which is 
	 * a string array of ids of the jobs that have run before the current job. 
	 * 
	 * @return a string array of ids of the jobs that have run before the current job, null if none.
	 */
	public String[] getJobDependencies(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return null;
		Element eDependencies = (Element)XMLUtil.findChildNode(eJob, "dependencies");
		if(eDependencies == null) return null;
		NodeList jobIDs = eDependencies.getElementsByTagName("jobID");
		if(jobIDs == null || jobIDs.getLength() <= 0) return null;
		int iJobIDs = jobIDs.getLength();
		String[] msJobIDs = new String[iJobIDs];
		for(int i = 0; i < iJobIDs; i++){
			msJobIDs[i] = XMLUtil.getElementValue((Element)jobIDs.item(i));
		}
		return msJobIDs;
	}//getJobDependencies

	/**
	 * Get the required directories and files to run the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of direcotry/file paths required to run the job. 
	 */
	public String[] getRequiredDirectoriesAndFiles(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return null;
		Element eRequiredDirectoriesAndFiles = (Element)XMLUtil.findChildNode(eJob, "requiredDirectoriesAndFiles");
		if(eRequiredDirectoriesAndFiles == null) return null;
		NodeList paths = eRequiredDirectoriesAndFiles.getElementsByTagName("path");
		if(paths == null || paths.getLength() <= 0) return null;
		int iPaths = paths.getLength();
		String[] msPaths = new String[iPaths];
		for(int i = 0; i < iPaths; i++){
			msPaths[i] = XMLUtil.getElementValue((Element)paths.item(i));
		}
		return msPaths;
	}//getRequiredDirectoriesAndFiles

	/**
	 * Get the directories to make before running the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of direcotry paths to make. 
	 */
	public String[] getDirectoriesToMake(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return null;
		Element eDirectoriesToMake = (Element)XMLUtil.findChildNode(eJob, "directoriesToMake");
		if(eDirectoriesToMake == null) return null;
		NodeList paths = eDirectoriesToMake.getElementsByTagName("path");
		if(paths == null || paths.getLength() <= 0) return null;
		int iPaths = paths.getLength();
		String[] msPaths = new String[iPaths];
		for(int i = 0; i < iPaths; i++){
			msPaths[i] = XMLUtil.getElementValue((Element)paths.item(i));
		}
		return msPaths;
	}//getDirectoriesToMake


	/**
	 * Get the files to create before running the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of file paths to create. 
	 */
	public String[] getFilesToCreate(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return null;
		Element eFilesToCreate = (Element)XMLUtil.findChildNode(eJob, "filesToCreate");
		if(eFilesToCreate == null) return null;
		NodeList paths = eFilesToCreate.getElementsByTagName("path");
		if(paths == null || paths.getLength() <= 0) return null;
		int iPaths = paths.getLength();
		String[] msPaths = new String[iPaths];
		for(int i = 0; i < iPaths; i++){
			msPaths[i] = XMLUtil.getElementValue((Element)paths.item(i));
		}
		return msPaths;
	}//getFilesToCreate


	/**
	 * Get the input files to copy from before running the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of file paths to copy from. 
	 */
	public String[] getInputFilesToCopyFrom(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return null;
		Element eInputFilesToCopyFrom = (Element)XMLUtil.findChildNode(eJob, "inputFilesToCopyFrom");
		if(eInputFilesToCopyFrom == null) return null;
		NodeList paths = eInputFilesToCopyFrom.getElementsByTagName("path");
		if(paths == null || paths.getLength() <= 0) return null;
		int iPaths = paths.getLength();
		String[] msPaths = new String[iPaths];
		for(int i = 0; i < iPaths; i++){
			msPaths[i] = XMLUtil.getElementValue((Element)paths.item(i));
		}
		return msPaths;
	}//getInputFilesToCopyFrom


	/**
	 * Get the input files to copy to before running the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of file paths to copy to. 
	 */
	public String[] getInputFilesToCopyTo(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return null;
		Element eInputFilesToCopyTo = (Element)XMLUtil.findChildNode(eJob, "inputFilesToCopyTo");
		if(eInputFilesToCopyTo == null) return null;
		NodeList paths = eInputFilesToCopyTo.getElementsByTagName("path");
		if(paths == null || paths.getLength() <= 0) return null;
		int iPaths = paths.getLength();
		String[] msPaths = new String[iPaths];
		for(int i = 0; i < iPaths; i++){
			msPaths[i] = XMLUtil.getElementValue((Element)paths.item(i));
		}
		return msPaths;
	}//getInputFilesToCopyTo


	/**
	 * Get the input files to move from before running the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of file paths to move from. 
	 */
	public String[] getInputFilesToMoveFrom(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return null;
		Element eInputFilesToMoveFrom = (Element)XMLUtil.findChildNode(eJob, "inputFilesToMoveFrom");
		if(eInputFilesToMoveFrom == null) return null;
		NodeList paths = eInputFilesToMoveFrom.getElementsByTagName("path");
		if(paths == null || paths.getLength() <= 0) return null;
		int iPaths = paths.getLength();
		String[] msPaths = new String[iPaths];
		for(int i = 0; i < iPaths; i++){
			msPaths[i] = XMLUtil.getElementValue((Element)paths.item(i));
		}
		return msPaths;
	}//getInputFilesToMoveFrom


	/**
	 * Get the input files to move to before running the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of file paths to move to. 
	 */
	public String[] getInputFilesToMoveTo(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return null;
		Element eInputFilesToMoveTo = (Element)XMLUtil.findChildNode(eJob, "inputFilesToMoveTo");
		if(eInputFilesToMoveTo == null) return null;
		NodeList paths = eInputFilesToMoveTo.getElementsByTagName("path");
		if(paths == null || paths.getLength() <= 0) return null;
		int iPaths = paths.getLength();
		String[] msPaths = new String[iPaths];
		for(int i = 0; i < iPaths; i++){
			msPaths[i] = XMLUtil.getElementValue((Element)paths.item(i));
		}
		return msPaths;
	}//getInputFilesToMoveTo


	/**
	 * Get the output files to copy from before running the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of file paths to copy from. 
	 */
	public String[] getOutputFilesToCopyFrom(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return null;
		Element eOutputFilesToCopyFrom = (Element)XMLUtil.findChildNode(eJob, "outputFilesToCopyFrom");
		if(eOutputFilesToCopyFrom == null) return null;
		NodeList paths = eOutputFilesToCopyFrom.getElementsByTagName("path");
		if(paths == null || paths.getLength() <= 0) return null;
		int iPaths = paths.getLength();
		String[] msPaths = new String[iPaths];
		for(int i = 0; i < iPaths; i++){
			msPaths[i] = XMLUtil.getElementValue((Element)paths.item(i));
		}
		return msPaths;
	}//getOutputFilesToCopyFrom

	/**
	 * Get the output files to copy to before running the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of file paths to copy to. 
	 */
	public String[] getOutputFilesToCopyTo(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return null;
		Element eOutputFilesToCopyTo = (Element)XMLUtil.findChildNode(eJob, "outputFilesToCopyTo");
		if(eOutputFilesToCopyTo == null) return null;
		NodeList paths = eOutputFilesToCopyTo.getElementsByTagName("path");
		if(paths == null || paths.getLength() <= 0) return null;
		int iPaths = paths.getLength();
		String[] msPaths = new String[iPaths];
		for(int i = 0; i < iPaths; i++){
			msPaths[i] = XMLUtil.getElementValue((Element)paths.item(i));
		}
		return msPaths;
	}//getOutputFilesToCopyTo

	/**
	 * Get the output files to move from before running the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of file paths to move from. 
	 */
	public String[] getOutputFilesToMoveFrom(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return null;
		Element eOutputFilesToMoveFrom = (Element)XMLUtil.findChildNode(eJob, "outputFilesToMoveFrom");
		if(eOutputFilesToMoveFrom == null) return null;
		NodeList paths = eOutputFilesToMoveFrom.getElementsByTagName("path");
		if(paths == null || paths.getLength() <= 0) return null;
		int iPaths = paths.getLength();
		String[] msPaths = new String[iPaths];
		for(int i = 0; i < iPaths; i++){
			msPaths[i] = XMLUtil.getElementValue((Element)paths.item(i));
		}
		return msPaths;
	}//getOutputFilesToMoveFrom


	/**
	 * Get the output files to move to before running the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of file paths to move to. 
	 */
	public String[] getOutputFilesToMoveTo(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return null;
		Element eOutputFilesToMoveTo = (Element)XMLUtil.findChildNode(eJob, "outputFilesToMoveTo");
		if(eOutputFilesToMoveTo == null) return null;
		NodeList paths = eOutputFilesToMoveTo.getElementsByTagName("path");
		if(paths == null || paths.getLength() <= 0) return null;
		int iPaths = paths.getLength();
		String[] msPaths = new String[iPaths];
		for(int i = 0; i < iPaths; i++){
			msPaths[i] = XMLUtil.getElementValue((Element)paths.item(i));
		}
		return msPaths;

	}//getOutputFilesToMoveTo


	/**
	 * Get the files to delete after running the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of file paths to delete. 
	 */
	public String[] getFilesToDelete(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return null;
		Element eFilesToDelete = (Element)XMLUtil.findChildNode(eJob, "filesToDelete");
		if(eFilesToDelete == null) return null;
		NodeList paths = eFilesToDelete.getElementsByTagName("path");
		if(paths == null || paths.getLength() <= 0) return null;
		int iPaths = paths.getLength();
		String[] msPaths = new String[iPaths];
		for(int i = 0; i < iPaths; i++){
			msPaths[i] = XMLUtil.getElementValue((Element)paths.item(i));
		}
		return msPaths;
	}//getFilesToDelete

	/**
	 * Get the directories to delete after running the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of directory paths to delete. 
	 */
	public String[] getDirectoriesToDelete(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return null;
		Element eDirectoriesToDelete = (Element)XMLUtil.findChildNode(eJob, "directoriesToDelete");
		if(eDirectoriesToDelete == null) return null;
		NodeList paths = eDirectoriesToDelete.getElementsByTagName("path");
		if(paths == null || paths.getLength() <= 0) return null;
		int iPaths = paths.getLength();
		String[] msPaths = new String[iPaths];
		for(int i = 0; i < iPaths; i++){
			msPaths[i] = XMLUtil.getElementValue((Element)paths.item(i));
		}
		return msPaths;
	}//getDirectoriesToDelete


	/**
	 * Get the processes to kill after running the job, which is 
	 * a string array of process names. 
	 * 
	 * @return a string array of process names to kill. 
	 */
	public String[] getProcessesToKill(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return null;
		Element eProcessesToKill = (Element)XMLUtil.findChildNode(eJob, "processesToKill");
		if(eProcessesToKill == null) return null;
		NodeList processess = eProcessesToKill.getElementsByTagName("process");
		if(processess == null || processess.getLength() <= 0) return null;
		int iProcesses = processess.getLength();
		String[] msProcesses = new String[iProcesses];
		for(int i = 0; i < iProcesses; i++){
			msProcesses[i] = XMLUtil.getElementValue((Element)processess.item(i));
		}
		return msProcesses;
	}//getProcessesToKill

	
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
			try {
				m_iVariableNumber = Integer.parseInt(sNumber);
			} 
			catch (Exception e) {
				
			}
			
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
			try {
				m_iObjectiveNumber = Integer.parseInt(sNumber);
			} 
			catch (Exception e) {
				
			}
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
			try {
				m_iConstraintNumber = Integer.parseInt(sNumber);
			} 
			catch (Exception e) {
				
			}
		}
		return m_iConstraintNumber;
	}//getConstraintNumber
	
	/**
	 * get initial variable values (double[]). 
	 * @return a double array of the initial variable values, null if none. 
	 */
	public double[] getInitialVariableValues(){
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
		if(eOptimization == null) return null;
		Element eVariables = (Element)XMLUtil.findChildNode(eOptimization, "variables");
		if(eVariables == null) return null;
		Element eInitialVariableValues = (Element)XMLUtil.findChildNode(eVariables, "initialVariableValues");
		if(eInitialVariableValues == null) return null;
		NodeList vars = eInitialVariableValues.getElementsByTagName("var");
		if(vars == null || vars.getLength() <= 0) return null;
		int iVars = vars.getLength();
		int iNumberVairables = this.getVariableNumber();
		double[] mdValues = new double[iNumberVairables];
		for(int i = 0; i < iVars; i++){
			try{
				int iIndex = Integer.parseInt(((Element)vars.item(i)).getAttribute("idx"));
				double dValue = Double.parseDouble(((Element)vars.item(i)).getAttribute("value"));
				mdValues[iIndex] = dValue;
			}
			catch(Exception e){
				return null;
			}
		}
		return mdValues;
	}//getInitialVariableValues
	
	/**
	 * Get the hash map of other optimization options. 
	 * 
	 * @return the hash map of other options.
	 */
	public HashMap getOtherOptimizationOptions(){
		if(m_otherOptimizationOptionHashMap != null) return m_otherOptimizationOptionHashMap;
		
		m_otherOptimizationOptionHashMap = new HashMap<String, String>();
		m_otherOptimizationOptionDescriptionHashMap = new HashMap<String, String>();

		Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
		if(eOptimization == null) return null;
		Vector<Element> vElements = XMLUtil.getChildElementsByTagName(eOptimization, "other");
		int iNls	= vElements==null?0:vElements.size();
		for(int i = 0; i < iNls; i++){
			Element eOther = (Element)(vElements.elementAt(i));
			NamedNodeMap	attributes =  eOther.getAttributes();
			int n =attributes.getLength();
			String sName = "";
			String sDescription = "";
			String sValue = XMLUtil.getElementValue(eOther);
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
			m_otherOptimizationOptionHashMap.put(sName, sValue);
			m_otherOptimizationOptionDescriptionHashMap.put(sName, sDescription);
		}
		return m_otherOptimizationOptionHashMap;
	}//getOtherOptimizationOptions

	/**
	 * Get the number of other optimization options.  
	 * 
	 * @return the number of other optimization options. 
	 */
	public int getOtherOptimizationOptionNumber(){
		getOtherOptimizationOptions();
		return m_otherOptimizationOptionHashMap.size();
	}//getOtherOptimizationOptionNumber
	
	/**
	 * Get the string value from the other optimization option hash map. 
	 * 
	 * @param name holds the name of optimization option to get.
	 * @return string value from the other optimization option hash map, null if none. 
	 */
	public String getOtherOptimizationOptionValueByName(String name){
		getOtherOptimizationOptions();
		if(name != null && name.trim().length() > 0 && m_otherOptimizationOptionHashMap.containsKey(name)){
			return (String)m_otherOptimizationOptionHashMap.get(name);
		}
		else{ 
			return null;
		}
	}//getOtherOptimizationOptionValueByName
	
	/**
	 * Get the string description from the other optimization option hash map.
	 * 
	 * @param name holds the name of optimization option to get. 
	 * @return string description from the other option hash map, null if none. 
	 */
	public String getOtherOptimizationOptionDescriptionByName(String name){
		getOtherOptimizationOptions();
		if(name != null && name.trim().length() > 0 && m_otherOptimizationOptionDescriptionHashMap.containsKey(name)){
			return (String)m_otherOptimizationOptionDescriptionHashMap.get(name);
		}
		else{ 
			return null;
		}
	}//getOtherOptimizationOptionDescriptionByName
	

	/**
	 * Get the names of all other optimization options. 
	 * 
	 * @return the names of all other optimization options. 
	 */
	public String[] getOtherOptimizationOptionNames(){
		getOtherOptimizationOptions();	
		Set nameSet = m_otherOptimizationOptionHashMap.keySet();
		Object[] moName = nameSet.toArray();
		String[] msName = new String[nameSet.size()];
		for (int i = 0; i < nameSet.size(); i++) {
			msName[i] = (String)moName[i];
		}
		return msName;		
	}//getOtherOptimizationOptionNames
	
	
	/**
	 * Get the values of all other optimization options. 
	 * 
	 * @return the values of all other optimization options. 
	 */
	public String[] getOtherOptimizationOptionValues(){
		getOtherOptimizationOptions();			
		Collection valueCollection = m_otherOptimizationOptionHashMap.values();
		Object[] moValue = valueCollection.toArray();
		String[] msValue = new String[valueCollection.size()];
		for (int i = 0; i < valueCollection.size(); i++) {
			msValue[i] = moValue[i].toString();
		}
		return msValue;
	}//getOtherOptimizationOptionValues
	

	/**
	 * Get the descriptions of all optimization other options. 
	 * 
	 * @return the descriptions of all other optimization options.
	 */
	public String[] getOtherOptimizationOptionDescriptions(){
		getOtherOptimizationOptions();			
		Collection valueCollection = m_otherOptimizationOptionDescriptionHashMap.values();
		Object[] moValue = valueCollection.toArray();
		String[] msDescription = new String[valueCollection.size()];
		for (int i = 0; i < valueCollection.size(); i++) {
			msDescription[i] = moValue[i].toString();
		}
		return msDescription;
	}//getOtherOptimizationOptionDescriptions
	
	/**
	 * Get the hash map of other options. 
	 * 
	 * @return the hash map of other options.
	 */
	public HashMap getOtherOptions(){
		if(m_otherOptionHashMap != null) return m_otherOptionHashMap;
		m_otherOptionHashMap = new HashMap<String, String>();
		m_otherOptionDescriptionHashMap = new HashMap<String, String>();

		Vector<Element> vElements = XMLUtil.getChildElementsByTagName(m_eRoot, "other");
		int iNls	= vElements==null?0:vElements.size();
		for(int i = 0; i < iNls; i++){
			Element eOther = (Element)(vElements.elementAt(i));
			NamedNodeMap	attributes =  eOther.getAttributes();
			int n =attributes.getLength();
			String sName = "";
			String sDescription = "";
			String sValue = XMLUtil.getElementValue(eOther);
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
			m_otherOptionHashMap.put(sName, sValue);
			m_otherOptionDescriptionHashMap.put(sName, sDescription);
		}
		return m_otherOptionHashMap;
	}//getOtherOptions

	/**
	 * Get the number of other options.  
	 * 
	 * @return the number of other options. 
	 */
	public int getOtherOptionNumber(){
		getOtherOptions();
		return m_otherOptionHashMap.size();
	}//getOtherOptionNumber

	/**
	 * Get the string value from the other option hash map. 
	 * 
	 * @param name holds the name of option to get.
	 * @return string value from the other option hash map, null if none. 
	 */
	public String getOtherOptionValueByName(String name){
		getOtherOptions();
		if(name != null && name.trim().length() > 0 && m_otherOptionHashMap.containsKey(name)){
			return (String)m_otherOptionHashMap.get(name);
		}
		else{ 
			return null;
		}
	}//getOtherOptionValueByName

	/**
	 * Get the string description from the other option hash map.
	 * 
	 * @param name holds the name of option to get. 
	 * @return string description from the other option hash map, null if none. 
	 */
	public String getOtherOptionDescriptionByName(String name){
		getOtherOptions();
		if(name != null && name.trim().length() > 0 && m_otherOptionDescriptionHashMap.containsKey(name)){
			return (String)m_otherOptionDescriptionHashMap.get(name);
		}
		else{ 
			return null;
		}
	}//getOtherOptionDescriptionByName

	/**
	 * Get the names of all other options. 
	 * 
	 * @return the names of all other options. 
	 */
	public String[] getOtherOptionNames(){
		getOtherOptions();	
		Set nameSet = m_otherOptionHashMap.keySet();
		Object[] moName = nameSet.toArray();
		String[] msName = new String[nameSet.size()];
		for (int i = 0; i < nameSet.size(); i++) {
			msName[i] = (String)moName[i];
		}
		return msName;		
	}//getOtherOptionNames
	
	/**
	 * Get the values of all other options. 
	 * 
	 * @return the values of all other options. 
	 */
	public String[] getOtherOptionValues(){
		getOtherOptions();			
		Collection valueCollection = m_otherOptionHashMap.values();
		Object[] moValue = valueCollection.toArray();
		String[] msValue = new String[valueCollection.size()];
		for (int i = 0; i < valueCollection.size(); i++) {
			msValue[i] = moValue[i].toString();
		}
		return msValue;
	}//getOtherOptionValues

	/**
	 * Get the descriptions of all other options. 
	 * 
	 * @return the descriptions of all other options.
	 */
	public String[] getOtherOptionDescriptions(){
		getOtherOptions();			
		Collection valueCollection = m_otherOptionDescriptionHashMap.values();
		Object[] moValue = valueCollection.toArray();
		String[] msDescription = new String[valueCollection.size()];
		for (int i = 0; i < valueCollection.size(); i++) {
			msDescription[i] = moValue[i].toString();
		}
		return msDescription;
	}//getOtherOptionDescriptions

	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		OSoLReader osolReader = new OSoLReader(false);
		System.out.println(IOUtil.readStringFromFile(OSParameter.CODE_HOME + "OSRepository/test/osol/osol.osol"));
		System.out.println(osolReader.readFile(OSParameter.CODE_HOME + "OSRepository/test/osol/osol.osol"));
		System.out.println(osolReader.getServiceName());
		System.out.println(osolReader.getServiceURI());
		System.out.println(osolReader.getInstanceName());		
		System.out.println(osolReader.getJobID());		
		System.out.println(osolReader.getLicense());		
		System.out.println(osolReader.getUserName());		
		System.out.println(osolReader.getPassword());		
		System.out.println(osolReader.getContactTransportType());		
		System.out.println(osolReader.getContactAddress());		
		System.out.println(osolReader.getSystemMinDiskSpace());		
		System.out.println(osolReader.getSystemMinMemorySize());		
		System.out.println(osolReader.getSystemMinCPUSpeed());		
		System.out.println(osolReader.getServiceType());		
		System.out.println(osolReader.getJobMaxTime());		
		System.out.println(XMLUtil.createXSDateTime(osolReader.getJobScheduledStartTime()));	
		String[] msJobs = osolReader.getJobDependencies();
		System.out.println(msJobs==null?"null":msJobs[0]);		
		System.out.println(osolReader.getVariableNumber());		
		System.out.println(osolReader.getObjectiveNumber());		
		System.out.println(osolReader.getConstraintNumber());	
		double[] mdInitValues = osolReader.getInitialVariableValues();
		System.out.println(mdInitValues==null?"NULL":mdInitValues[0]+"");		

		System.out.println(osolReader.getOtherOptionNumber());
		String sValue = osolReader.getOtherOptionValueByName("ad");
		if(sValue == null) System.out.println("null");
		else System.out.println(sValue);
		String sDescription = osolReader.getOtherOptionDescriptionByName("a");
		System.out.println(sDescription);
		for(int i=0;i<osolReader.getOtherOptionNumber();i++){
			System.out.println(osolReader.getOtherOptionNames()[i]);
			System.out.println(osolReader.getOtherOptionValues()[i]);
			System.out.println(osolReader.getOtherOptionDescriptions()[i]);
		}
		osolReader.writeToStandardOutput();
	}//main
	
}//class OSoLReader
