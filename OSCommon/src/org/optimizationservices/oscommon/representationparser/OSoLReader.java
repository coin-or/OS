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

import org.optimizationservices.oscommon.datastructure.osoption.InitBasStatus;
import org.optimizationservices.oscommon.datastructure.osoption.InitConValue;
import org.optimizationservices.oscommon.datastructure.osoption.InitDualVarValue;
import org.optimizationservices.oscommon.datastructure.osoption.InitObjBound;
import org.optimizationservices.oscommon.datastructure.osoption.InitObjValue;
import org.optimizationservices.oscommon.datastructure.osoption.InitVarValue;
import org.optimizationservices.oscommon.datastructure.osoption.InitVarValueString;
import org.optimizationservices.oscommon.datastructure.osoption.OtherOption;
import org.optimizationservices.oscommon.datastructure.osoption.PathPair;
import org.optimizationservices.oscommon.datastructure.osoption.SolverOption;
import org.optimizationservices.oscommon.localinterface.OSOption;
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
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
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
	 * m_solverOptionHashMap holds a hash map of other solver options.
	 */
	protected HashMap<String, SolverOption> m_solverOptionHashMap = new HashMap<String, SolverOption>();

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
		if(!m_osOption.setInstanceAddress(getInstanceLocation())) throw new Exception("setInstanceAddress Unsuccessful");		
		if(!m_osOption.setJobID(getJobID())) throw new Exception("setJobID Unsuccessful");		
		if(!m_osOption.setSolverToInvoke(getSolverToInvoke())) throw new Exception("setSolverToInvoke Unsuccessful");		
		if(!m_osOption.setLicense(getLicense())) throw new Exception("setLicense Unsuccessful");		
		if(!m_osOption.setUserName(getUserName())) throw new Exception("setUserName Unsuccessful");		
		if(!m_osOption.setPassword(getPassword())) throw new Exception("setPassword Unsuccessful");		
		if(!m_osOption.setContactTransportType(getContactTransportType())) throw new Exception("setContactTransportType Unsuccessful");		
		if(!m_osOption.setContactAddress(getContact())) throw new Exception("setContactAddress Unsuccessful");		
		if(!m_osOption.setSystemMinDiskSpace(getMinDiskSpace())) throw new Exception("setSystemMinDiskSpace Unsuccessful");		
		if(!m_osOption.setSystemMinMemorySize(getMinMemorySize())) throw new Exception("setSystemMinMemorySize Unsuccessful");		
		if(!m_osOption.setSystemMinCPUSpeed(getMinCPUSpeed())) throw new Exception("setSystemMinCPUSpeed Unsuccessful");		
		if(!m_osOption.setServiceType(getServiceType())) throw new Exception("setServiceType Unsuccessful");		
		if(!m_osOption.setJobMaxTime(getMaxTime())) throw new Exception("setJobMaxTime Unsuccessful");		
		if(!m_osOption.setJobScheduledStartTime(getScheduledStartTime())) throw new Exception("setJobScheduledStartTime Unsuccessful");		
		if(!m_osOption.setJobDependencies(getJobDependencies())) throw new Exception("setJobDependencies Unsuccessful");		
		if(!m_osOption.setRequiredDirectories(getRequiredDirectories())) throw new Exception("setRequiredDirectories Unsuccessful");		
		if(!m_osOption.setRequiredFiles(getRequiredFiles())) throw new Exception("setRequiredFiles Unsuccessful");		
		if(!m_osOption.setDirectoriesToMake(getDirectoriesToMake())) throw new Exception("setDirectoriesToMake Unsuccessful");		
		if(!m_osOption.setFilesToMake(getFilesToMake())) throw new Exception("setFilesToMake Unsuccessful");		
		if(!m_osOption.setInputDirectoriesToMove(getInputDirectoriesToMove())) throw new Exception("setInputDirectoriesToMove Unsuccessful");		
		if(!m_osOption.setInputFilesToMove(getInputFilesToMove())) throw new Exception("setInputFilesToMove Unsuccessful");		
		if(!m_osOption.setOutputDirectoriesToMove(getOutputDirectoriesToMove())) throw new Exception("setOutputDirectoriesToMove Unsuccessful");		
		if(!m_osOption.setOutputFilesToMove(getOutputFilesToMove())) throw new Exception("setOutputFilesToMove Unsuccessful");		
		if(!m_osOption.setFilesToDelete(getFilesToDelete())) throw new Exception("setFilesToDelete Unsuccessful");		
		if(!m_osOption.setDirectoriesToDelete(getDirectoriesToDelete())) throw new Exception("setDirectoriesToDelete Unsuccessful");		
		if(!m_osOption.setProcessesToKill(getProcessesToKill())) throw new Exception("setProcessesToKill Unsuccessful");		
		if(!m_osOption.setVariableNumber(getNumberOfVariables())) throw new Exception("setVariableNumber Unsuccessful");		
		if(!m_osOption.setObjectiveNumber(getNumberOfObjectives())) throw new Exception("setObjectiveNumber Unsuccessful");		
		if(!m_osOption.setConstraintNumber(getNumberOfConstraints())) throw new Exception("setConstraintNumber Unsuccessful");		
		if(!m_osOption.setInitialVariableValues(getInitVarValuesDense())) throw new Exception("setInitialVariableValues Unsuccessful");		
		if(!m_osOption.setSolverOptions(getSolverOptions(""))) throw new Exception("setSolverOptions Unsuccessful");
		return m_osOption;
	}//getOSOption

	/**
	 * get the value of a string-valued option
	 * @param optionName The name of the option
	 * @return the value of the option optionName
	 * @note This function returns the empty string "" if optionName is not found
	 */
	public String getOptionStr(String optionName){
		if (optionName.equals("serviceURI")){ 
			return getServiceURI();
		}
		else if (optionName.equals("serviceName")){ 
			return getServiceName();
		}
		else if (optionName.equals("instanceName")){
			return getInstanceName();
		}
		else if (optionName.equals("instanceLocation")){ 
			return getInstanceLocation();
		}
		else if (optionName.equals("locationType")){ 
			return getInstanceLocationType();
		}
		else if (optionName.equals("jobID")){ 
			return getJobID();
		}
		else if (optionName.equals("solverToInvoke")){ 
			return getSolverToInvoke();
		}
		else if (optionName.equals("license")){ 
			return getLicense();
		}
		else if (optionName.equals("userName")){ 
			return getUserName();
		}
		else if (optionName.equals("password")){ 
			return getPassword();
		}
		else if (optionName.equals("contact")){ 
			return getContact();
		}
		else if (optionName.equals("transportType")){ 
			return getContactTransportType();
		}
		else if (optionName.equals("minDiskSpaceUnit")){ 
			return getMinDiskSpaceUnit();
		}
		else if (optionName.equals("minMemoryUnit")){ 
			return getMinMemoryUnit();
		}
		else if (optionName.equals("minCPUSpeedUnit")){ 
			return getMinCPUSpeedUnit();
		}
		else if (optionName.equals("serviceType")){ 
			return getServiceType();
		}
		else if (optionName.equals("maxTimeUnit")){ 
			return getMaxTimeUnit();
		}
		else if (optionName.equals("scheduledStartTime")){ 
			Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
			if(eJob == null) return "1970-01-01T00:00:00-00:00";
			String sJobScheduledStartTime = XMLUtil.getElementValueByName(eJob, "scheduledStartTime");
			if(sJobScheduledStartTime == null || sJobScheduledStartTime.length() <= 0) return "1970-01-01T00:00:00-00:00";
			return sJobScheduledStartTime;
		}
		else{
			return "";
		}
	}//getOptionStr

	/**
	 * get the value of a double-valued option
	 * @param optionName The name of the option
	 * @return the value of the option optionName
	 * @note returns Double.NaN if optionName is not found
	 */
	double  getOptionDbl(String optionName){	
		if (optionName.equals("minDiskSpace")){ 
			return getMinDiskSpace();
		}
		else if (optionName.equals("minMemorySize")){ 
			return getMinMemorySize();
		}
		else if (optionName.equals("minCPUSpeed")){ 
			return getMinCPUSpeed();
		}
		else if (optionName == "maxTime"){ 
			return getMaxTime();
		}
		else{
			return Double.NaN;
		}
	}//getOptionDbl

	/**
	 * get the value of a integer-valued option
	 * @param optionName The name of the option
	 * @return the value of the option optionName
	 * @note returns 0 if optionName is not found
	 */
	public int  getOptionInt(String optionName){	
		if(optionName.equals("minCPUNumber")){
			return getMinCPUNumber();
		}	
		else if(optionName.equals("numberOfOtherGeneralOptions")){
			return getNumberOfOtherGeneralOptions();
		}	
		else if(optionName.equals("numberOfOtherSystemOptions")){
			return getNumberOfOtherSystemOptions();
		}	
		else if(optionName.equals("numberOfOtherServiceOptions")){
			return getNumberOfOtherServiceOptions();
		}
		else if(optionName.equals("numberOfOtherJobOptions")){
			return getNumberOfOtherJobOptions();
		}
		else if(optionName.equals("numberOfJobDependencies")){
			return getNumberOfJobDependencies();
		}
		else if(optionName.equals("numberOfRequiredDirectories")){
			return getNumberOfRequiredDirectories();
		}
		else if(optionName.equals("numberOfRequiredFiles")){
			return getNumberOfRequiredFiles();
		}
		else if(optionName.equals("numberOfDirectoriesToMake")){
			return getNumberOfDirectoriesToMake();
		}
		else if(optionName.equals("numberOfFilesToCreate")){
			return getNumberOfFilesToMake();
		}
		else if(optionName.equals("numberOfInputDirectoriesToMove")){
			return getNumberOfInputDirectoriesToMove();
		}
		else if(optionName.equals("numberOfInputFilesToMove")){
			return getNumberOfInputFilesToMove();
		}
		else if(optionName.equals("numberOfOutputDirectoriesToMove")){
			return getNumberOfOutputDirectoriesToMove();
		}
		else if(optionName.equals("numberOfOutputFilesToMove")){
			return getNumberOfOutputFilesToMove();
		}
		else if(optionName.equals("numberOfFilesToDelete")){
			return getNumberOfFilesToDelete();
		}
		else if(optionName.equals("numberOfDirectoriesToDelete")){
			return getNumberOfDirectoriesToDelete();
		}
		else if(optionName.equals("numberOfProcessesToKill")){
			return getNumberOfProcessesToKill();
		}
		else if(optionName.equals("numberOfVariables")){
			return getNumberOfVariables();
		}
		else if(optionName.equals("numberOfObjectives")){
			return getNumberOfObjectives();
		}
		else if(optionName.equals("numberOfConstraints")){
			return getNumberOfConstraints();
		}
		else if(optionName.equals("numberOfInitVarValues")){
			return getNumberOfInitVarValues();
		}
		else if(optionName.equals("numberOfInitVarValuesString")){
			return getNumberOfInitVarValuesString();
		}
		else if(optionName.equals("numberOfInitialBasisVariables")){
			return getNumberOfInitialBasisVariables();
		}
		else if(optionName.equals("numberOfIntegerVariableSelectionWeights")){
			return getNumberOfIntegerVariableSelectionWeights();
		}
		else if(optionName.equals("numberOfSOSVariableSelectionWeights")){
			return getNumberOfSOSVariableSelectionWeights();
		}
		else if(optionName.equals("numberOfOtherVariableOptions")){
			return getNumberOfOtherVariableOptions();
		}
		else if(optionName.equals("numberOfInitObjValues")){
			return getNumberOfInitObjValues();
		}
		else if(optionName.equals("numberOfInitObjBounds")){
			return getNumberOfInitObjBounds();
		}
		else if(optionName.equals("numberOfOtherObjectiveOptions")){
			return getNumberOfOtherObjectiveOptions();
		}
		else if(optionName.equals("numberOfInitConValues")){
			return getNumberOfInitConValues();
		}
		else if(optionName.equals("numberOfInitDualVarValues")){
			return getNumberOfInitDualVarValues();
		}
		else if(optionName.equals("numberOfOtherConstraintOptions")){
			return getNumberOfOtherConstraintOptions();
		}
		else if(optionName.equals("numberOfSolverOptions")){
			return getNumberOfSolverOptions();
		}
		else {
			return 0;	
		}
	}//getOptionInt

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
	 * Get the instance location address to get the instance. 
	 * 
	 * @return the instance address, null or empty string if none. 
	 */
	public String getInstanceLocation(){
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eRoot, "general");
		if(eGeneral == null) return "";
		String sInstanceAddress = XMLUtil.getElementValueByName(eGeneral, "instanceLocation");
		if(sInstanceAddress == null) return "";
		return sInstanceAddress;
	}//getInstanceLocation


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
	 * get the solver to invoke
	 * @return the solver to invoke
	 */
	public String getSolverToInvoke(){
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eRoot, "general");
		if(eGeneral == null) return "";
		String sSolverToInvoke = XMLUtil.getElementValueByName(eGeneral, "solverToInvoke");
		if(sSolverToInvoke == null) return "";
		return sSolverToInvoke;			
	}//getSolverName

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
	 * Get the contact address to respond to the requester. 
	 * For example it can be an email address if the contact transport type is smtp
	 * or a http uri if the contact transport type is osp (for knocking back on the requester), etc.
	 * 
	 * @return the contact trasport address, null or empty string if none. 
	 */
	public String getContact(){
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eRoot, "general");
		if(eGeneral == null) return "";
		String sContactAddress = XMLUtil.getElementValueByName(eGeneral, "contact");
		if(sContactAddress == null) return "";
		return sContactAddress;
	}//getContact

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
	 * get the number of other <general> options
	 * 
	 * @return the number of other <general> options
	 */
	public int  getNumberOfOtherGeneralOptions(){	
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eRoot, "general");
		if(eGeneral == null) return 0;
		Element eOtherOptions = (Element)XMLUtil.findChildNode(eGeneral, "otherOptions");
		if(eOtherOptions == null) return 0;
		String sNumberOfOtherOptions = eOtherOptions.getAttribute("numberOfOtherOptions");
		if(sNumberOfOtherOptions == null || sNumberOfOtherOptions.length() <= 0) return 0;
		try{
			int iNumberOfOtherOptions = Integer.parseInt(sNumberOfOtherOptions);
			return iNumberOfOtherOptions;
		}
		catch(Exception e){
			return 0;
		}	
	}//getNumberOfOtherGeneralOptions

	/**
	 * get the array of other <general> options
	 * 
	 * @return the array of other <general> options
	 */
	public OtherOption[] getOtherGeneralOptions(){	
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eRoot, "general");
		if(eGeneral == null) return null;
		Element eOtherOptions = (Element)XMLUtil.findChildNode(eGeneral, "otherOptions");
		if(eOtherOptions == null) return null;
		NodeList others = eOtherOptions.getElementsByTagName("other");
		if(others == null || others.getLength() <= 0) return null;
		int iOthers = others.getLength();
		OtherOption[] mOthers = new OtherOption[iOthers];
		for(int i = 0; i < iOthers; i++){
			Element eOther = (Element)others.item(i);
			mOthers[i] =new OtherOption();
			String sName = eOther.getAttribute("name"); 				
			String sValue = eOther.getAttribute("value");
			String sDescription = eOther.getAttribute("description");	
			mOthers[i].name = sName==null?"":sName;
			mOthers[i].value = sValue==null?"":sValue;
			mOthers[i].description = sDescription==null?"":sDescription;
		}
		return mOthers;
	}//getOtherGeneralOptions



	/**
	 * Get the system minimum disk space required to solve the job. 
	 * 
	 * @return the system minimum disk space, 0.0 if none. 
	 */
	public double getMinDiskSpace(){
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
	}//getMinDiskSpace

	/**
	 * Get the unit of the system minimum disk space required to solve the job. 
	 * 
	 * @return the unit of the system minimum disk space, byte if none. 
	 */
	public String getMinDiskSpaceUnit(){
		Element eSystem = (Element)XMLUtil.findChildNode(m_eRoot, "system");
		if(eSystem == null) return "byte";
		Element eMinDiskSpace = (Element)XMLUtil.findChildNode(eSystem, "minDiskSpace");
		if(eMinDiskSpace == null) return "byte";
		String sMinDiskSpaceUnit = eMinDiskSpace.getAttribute("unit");
		if(sMinDiskSpaceUnit == null || sMinDiskSpaceUnit.length() <= 0) return "byte";
		else return sMinDiskSpaceUnit;
	}//getMinDiskSpaceUnit

	/**
	 * Get the system minimum memory size required to solve the job. 
	 * 
	 * @return the system minimum memory size, 0.0 if none. 
	 */
	public double getMinMemorySize(){
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
	}//getMinMemorySize

	/**
	 * Get the unit of the system minimum memory size required to solve the job. 
	 * 
	 * @return the unit of the system minimum memory size, byte if none. 
	 */
	public String getMinMemoryUnit(){
		Element eSystem = (Element)XMLUtil.findChildNode(m_eRoot, "system");
		if(eSystem == null) return "byte";
		Element eMinMemorySize = (Element)XMLUtil.findChildNode(eSystem, "minMemorySize");
		if(eMinMemorySize == null) return "byte";
		String sMinMemoryUnit = eMinMemorySize.getAttribute("unit");
		if(sMinMemoryUnit == null || sMinMemoryUnit.length() <= 0) return "byte";
		else return sMinMemoryUnit;
	}//getMinMemoryUnit

	/**
	 * Get the system minimum cpu speed required to solve the job. 
	 * 
	 * @return the system minimum cpu speed, 0.0 if none. 
	 */
	public double getMinCPUSpeed(){
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
	}//getMinCPUSpeed

	/**
	 * Get the unit of the system minimum cpu speed required to solve the job. 
	 * 
	 * @return the unit of the system minimum cpu speed, 0.0 if none. 
	 */
	public String getMinCPUSpeedUnit(){
		Element eSystem = (Element)XMLUtil.findChildNode(m_eRoot, "system");
		if(eSystem == null) return "hertz";
		Element eMinCPUSpeed = (Element)XMLUtil.findChildNode(eSystem, "minCPUSpeed");
		if(eMinCPUSpeed == null) return "hertz";
		String sMinCPUSpeedUnit = eMinCPUSpeed.getAttribute("unit");
		if(sMinCPUSpeedUnit == null || sMinCPUSpeedUnit.length() <= 0) return "hertz";
		else return sMinCPUSpeedUnit;
	}//getMinCPUSpeedUnit

	/**
	 * Get the system minimum cpu number required to solve the job. 
	 * 
	 * @return the system minimum cpu number, 0 if none. 
	 */
	public int getMinCPUNumber(){
		Element eSystem = (Element)XMLUtil.findChildNode(m_eRoot, "system");
		if(eSystem == null) return 0;
		String sMinCPUNumber = XMLUtil.getElementValueByName(eSystem, "minCPUNumber");
		if(sMinCPUNumber == null || sMinCPUNumber.length() <= 0) return 0;
		try{
			int iMinCPUNumber = Integer.parseInt(sMinCPUNumber);
			return iMinCPUNumber;
		}
		catch(Exception e){
			return 0;
		}
	}//getMinCPUNumber

	/**
	 * get the number of other <system> options
	 * 
	 * @return the number of other <system> options
	 */
	public int  getNumberOfOtherSystemOptions(){	
		Element eSystem = (Element)XMLUtil.findChildNode(m_eRoot, "system");
		if(eSystem == null) return 0;
		Element eOtherOptions = (Element)XMLUtil.findChildNode(eSystem, "otherOptions");
		if(eOtherOptions == null) return 0;
		String sNumberOfOtherOptions = eOtherOptions.getAttribute("numberOfOtherOptions");
		if(sNumberOfOtherOptions == null || sNumberOfOtherOptions.length() <= 0) return 0;
		try{
			int iNumberOfOtherOptions = Integer.parseInt(sNumberOfOtherOptions);
			return iNumberOfOtherOptions;
		}
		catch(Exception e){
			return 0;
		}	
	}//getNumberOfOtherSystemOptions

	/**
	 * get the array of other <system> options
	 * 
	 * @return the array of other <system> options
	 */
	public OtherOption[] getOtherSystemOptions(){	
		Element eSystem = (Element)XMLUtil.findChildNode(m_eRoot, "system");
		if(eSystem == null) return null;
		Element eOtherOptions = (Element)XMLUtil.findChildNode(eSystem, "otherOptions");
		if(eOtherOptions == null) return null;
		NodeList others = eOtherOptions.getElementsByTagName("other");
		if(others == null || others.getLength() <= 0) return null;
		int iOthers = others.getLength();
		OtherOption[] mOthers = new OtherOption[iOthers];
		for(int i = 0; i < iOthers; i++){
			Element eOther = (Element)others.item(i);
			mOthers[i] =new OtherOption();
			String sName = eOther.getAttribute("name"); 				
			String sValue = eOther.getAttribute("value");
			String sDescription = eOther.getAttribute("description");	
			mOthers[i].name = sName==null?"":sName;
			mOthers[i].value = sValue==null?"":sValue;
			mOthers[i].description = sDescription==null?"":sDescription;
		}
		return mOthers;
	}//getOtherSystemOptions


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
	 * get the number of other <service> options
	 * 
	 * @return the number of other <service> options
	 */
	public int  getNumberOfOtherServiceOptions(){	
		Element eService = (Element)XMLUtil.findChildNode(m_eRoot, "service");
		if(eService == null) return 0;
		Element eOtherOptions = (Element)XMLUtil.findChildNode(eService, "otherOptions");
		if(eOtherOptions == null) return 0;
		String sNumberOfOtherOptions = eOtherOptions.getAttribute("numberOfOtherOptions");
		if(sNumberOfOtherOptions == null || sNumberOfOtherOptions.length() <= 0) return 0;
		try{
			int iNumberOfOtherOptions = Integer.parseInt(sNumberOfOtherOptions);
			return iNumberOfOtherOptions;
		}
		catch(Exception e){
			return 0;
		}	
	}//getNumberOfOtherServiceOptions

	/**
	 * get the array of other <service> options
	 * 
	 * @return the array of other <service> options
	 */
	public OtherOption[] getOtherServiceOptions(){	
		Element eService = (Element)XMLUtil.findChildNode(m_eRoot, "service");
		if(eService == null) return null;
		Element eOtherOptions = (Element)XMLUtil.findChildNode(eService, "otherOptions");
		if(eOtherOptions == null) return null;
		NodeList others = eOtherOptions.getElementsByTagName("other");
		if(others == null || others.getLength() <= 0) return null;
		int iOthers = others.getLength();
		OtherOption[] mOthers = new OtherOption[iOthers];
		for(int i = 0; i < iOthers; i++){
			Element eOther = (Element)others.item(i);
			mOthers[i] =new OtherOption();
			String sName = eOther.getAttribute("name"); 				
			String sValue = eOther.getAttribute("value");
			String sDescription = eOther.getAttribute("description");	
			mOthers[i].name = sName==null?"":sName;
			mOthers[i].value = sValue==null?"":sValue;
			mOthers[i].description = sDescription==null?"":sDescription;
		}
		return mOthers;
	}//getOtherServiceOptions


	/**
	 * Get the maximum time (in seconds) before the job is terminated.  
	 * 
	 * @return the maximum time, Double.POSITIVE_INFINITY if none. 
	 */
	public double getMaxTime(){
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
	}//getMaxTime

	/**
	 * Get the unit of the job max time required to solve the job. 
	 * 
	 * @return the unit of the system minimum cpu speed, 0.0 if none. 
	 */
	public String getMaxTimeUnit(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return "second";
		Element eJobMaxTime = (Element)XMLUtil.findChildNode(eJob, "maxTime");
		if(eJobMaxTime == null) return "second";
		String sJobMaxTimeUnit = eJobMaxTime.getAttribute("unit");
		if(sJobMaxTimeUnit == null || sJobMaxTimeUnit.length() <= 0) return "second";
		else return sJobMaxTimeUnit;
	}//getMaxTimeUnit

	/**
	 * Get the scheduled start time for the job.   
	 * 
	 * @return the scheduled start time for the job, null or UNIX time (1970/1/1) if none. 
	 */
	public GregorianCalendar getScheduledStartTime(){ 
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
	}//getScheduledStartTime

	/**
	 * get the number of job dependencies (in <job> element)
	 * 
	 * @return the number of job dependencies (in <job> element)
	 */
	int  getNumberOfJobDependencies(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return 0;
		Element eDependencies = (Element)XMLUtil.findChildNode(eJob, "dependencies");
		if(eDependencies == null) return 0;
		String sNumberOfJobIDs = eDependencies.getAttribute("numberOfJobIDs");
		if(sNumberOfJobIDs == null || sNumberOfJobIDs.length() <= 0) return 0;
		try{
			int iNumberOfJobIDs = Integer.parseInt(sNumberOfJobIDs);
			return iNumberOfJobIDs;
		}
		catch(Exception e){
			return 0;
		}	
	}//getNumberOfJobDependencies

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
	 * get the number of required directories (in <job> element)
	 * 
	 * @return the number of required directories (in <job> element)
	 */
	int  getNumberOfRequiredDirectories(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return 0;
		Element eDependencies = (Element)XMLUtil.findChildNode(eJob, "requiredDirectories");
		if(eDependencies == null) return 0;
		String sNumberRequiredDirectories = eDependencies.getAttribute("numberOfPaths");
		if(sNumberRequiredDirectories == null || sNumberRequiredDirectories.length() <= 0) return 0;
		try{
			int iNumberRequiredDirectories = Integer.parseInt(sNumberRequiredDirectories);
			return iNumberRequiredDirectories;
		}
		catch(Exception e){
			return 0;
		}	
	}//getNumberOfRequiredDirectories

	/**
	 * Get the required directories to run the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of direcotry paths required to run the job. 
	 */
	public String[] getRequiredDirectories(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return null;
		Element eRequiredDirectories = (Element)XMLUtil.findChildNode(eJob, "requiredDirectories");
		if(eRequiredDirectories == null) return null;
		NodeList paths = eRequiredDirectories.getElementsByTagName("path");
		if(paths == null || paths.getLength() <= 0) return null;
		int iPaths = paths.getLength();
		String[] msPaths = new String[iPaths];
		for(int i = 0; i < iPaths; i++){
			msPaths[i] = XMLUtil.getElementValue((Element)paths.item(i));
		}
		return msPaths;
	}//getRequiredDirectories

	/**
	 * get the number of required files (in <job> element)
	 * 
	 * @return the number of required files (in <job> element)
	 */
	int  getNumberOfRequiredFiles(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return 0;
		Element eDependencies = (Element)XMLUtil.findChildNode(eJob, "requiredFiles");
		if(eDependencies == null) return 0;
		String sNumberRequiredFiles = eDependencies.getAttribute("numberOfPaths");
		if(sNumberRequiredFiles == null || sNumberRequiredFiles.length() <= 0) return 0;
		try{
			int iNumberRequiredFiles = Integer.parseInt(sNumberRequiredFiles);
			return iNumberRequiredFiles;
		}
		catch(Exception e){
			return 0;
		}	
	}//getNumberOfRequiredFiles

	/**
	 * Get the required files to run the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of file paths required to run the job. 
	 */
	public String[] getRequiredFiles(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return null;
		Element eRequiredFiles = (Element)XMLUtil.findChildNode(eJob, "requiredFiles");
		if(eRequiredFiles == null) return null;
		NodeList paths = eRequiredFiles.getElementsByTagName("path");
		if(paths == null || paths.getLength() <= 0) return null;
		int iPaths = paths.getLength();
		String[] msPaths = new String[iPaths];
		for(int i = 0; i < iPaths; i++){
			msPaths[i] = XMLUtil.getElementValue((Element)paths.item(i));
		}
		return msPaths;
	}//getRequiredFiles

	/**
	 * get the number of directories to make (in <job> element)
	 * 
	 * @return the number of directories to make (in <job> element)
	 */
	int  getNumberOfDirectoriesToMake(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return 0;
		Element eDirectoriesToMake = (Element)XMLUtil.findChildNode(eJob, "directoriesToMake");
		if(eDirectoriesToMake == null) return 0;
		String sNumberDirectoriesToMake = eDirectoriesToMake.getAttribute("numberOfPaths");
		if(sNumberDirectoriesToMake == null || sNumberDirectoriesToMake.length() <= 0) return 0;
		try{
			int iNumberDirectoriesToMake = Integer.parseInt(sNumberDirectoriesToMake);
			return iNumberDirectoriesToMake;
		}
		catch(Exception e){
			return 0;
		}	
	}//getNumberOfDirectoriesToMake

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
	 * get the number of files to make (in <job> element)
	 * 
	 * @return the number of files to make (in <job> element)
	 */
	int  getNumberOfFilesToMake(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return 0;
		Element eFilesToMake = (Element)XMLUtil.findChildNode(eJob, "filesToMake");
		if(eFilesToMake == null) return 0;
		String sNumberFilesToMake = eFilesToMake.getAttribute("numberOfPaths");
		if(sNumberFilesToMake == null || sNumberFilesToMake.length() <= 0) return 0;
		try{
			int iNumberFilesToMake = Integer.parseInt(sNumberFilesToMake);
			return iNumberFilesToMake;
		}
		catch(Exception e){
			return 0;
		}	
	}//getNumberOfFlesToMake


	/**
	 * Get the files to make before running the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of file paths to make. 
	 */
	public String[] getFilesToMake(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return null;
		Element eFilesToMake = (Element)XMLUtil.findChildNode(eJob, "filesToMake");
		if(eFilesToMake == null) return null;
		NodeList paths = eFilesToMake.getElementsByTagName("path");
		if(paths == null || paths.getLength() <= 0) return null;
		int iPaths = paths.getLength();
		String[] msPaths = new String[iPaths];
		for(int i = 0; i < iPaths; i++){
			msPaths[i] = XMLUtil.getElementValue((Element)paths.item(i));
		}
		return msPaths;
	}//getFilesToMake

	/**
	 * get the number of input directories to move or copy (in <job> element)
	 * 
	 * @return the number of input directories to move or copy (in <job> element)
	 */
	int  getNumberOfInputDirectoriesToMove(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return 0;
		Element eInputDirectoriesToMove = (Element)XMLUtil.findChildNode(eJob, "inputDirectoriesToMove");
		if(eInputDirectoriesToMove == null) return 0;
		String sNumberOfInputDirectoriesToMove = eInputDirectoriesToMove.getAttribute("numberOfPathPairs");
		if(sNumberOfInputDirectoriesToMove == null || sNumberOfInputDirectoriesToMove.length() <= 0) return 0;
		try{
			int iNumberOfInputDirectoriesToMove = Integer.parseInt(sNumberOfInputDirectoriesToMove);
			return iNumberOfInputDirectoriesToMove;
		}
		catch(Exception e){
			return 0;
		}	
	}//getNumberOfInputDirectoriesToMove

	/**
	 * Get get the list of input directories that need to be moved or copied
	 * 
	 * @return the list of input directories that need to be moved or copied. 
	 */
	public PathPair[] getInputDirectoriesToMove(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return null;
		Element eInputDirectoriesToMove = (Element)XMLUtil.findChildNode(eJob, "inputDirectoriesToMove");
		if(eInputDirectoriesToMove == null) return null;
		NodeList pathPairs = eInputDirectoriesToMove.getElementsByTagName("pathPair");
		if(pathPairs == null || pathPairs.getLength() <= 0) return null;
		int iPathPairs = pathPairs.getLength();
		PathPair[] mPathPairs = new PathPair[iPathPairs];
		for(int i = 0; i < iPathPairs; i++){
			Element ePathPair = (Element)pathPairs.item(i);
			mPathPairs[i] =new PathPair();
			String sFrom = ePathPair.getAttribute("from"); 				
			String sTo = ePathPair.getAttribute("to");
			String sMakeCopy = ePathPair.getAttribute("makeCopy");	
			mPathPairs[i].from = sFrom==null?"":sFrom;
			mPathPairs[i].to = sTo==null?"":sTo;
			mPathPairs[i].makeCopy = (sMakeCopy!=null && sMakeCopy.equals("true"))?true:false;
		}
		return mPathPairs;
	}//getInputDirectoriesToMove

	/**
	 * get the number of input files to move or copy (in <job> element)
	 * 
	 * @return the number of input files to move or copy (in <job> element)
	 */
	int  getNumberOfInputFilesToMove(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return 0;
		Element eInputFilesToMove = (Element)XMLUtil.findChildNode(eJob, "inputFilesToMove");
		if(eInputFilesToMove == null) return 0;
		String sNumberOfInputFilesToMove = eInputFilesToMove.getAttribute("numberOfPathPairs");
		if(sNumberOfInputFilesToMove == null || sNumberOfInputFilesToMove.length() <= 0) return 0;
		try{
			int iNumberOfInputFilesToMove = Integer.parseInt(sNumberOfInputFilesToMove);
			return iNumberOfInputFilesToMove;
		}
		catch(Exception e){
			return 0;
		}	
	}//getNumberOfInputFilesToMove

	/**
	 * Get get the list of input files that need to be moved or copied
	 * 
	 * @return the list of input files that need to be moved or copied. 
	 */
	public PathPair[] getInputFilesToMove(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return null;
		Element eInputFilesToMove = (Element)XMLUtil.findChildNode(eJob, "inputFilesToMove");
		if(eInputFilesToMove == null) return null;
		NodeList pathPairs = eInputFilesToMove.getElementsByTagName("pathPair");
		if(pathPairs == null || pathPairs.getLength() <= 0) return null;
		int iPathPairs = pathPairs.getLength();
		PathPair[] mPathPairs = new PathPair[iPathPairs];
		for(int i = 0; i < iPathPairs; i++){
			Element ePathPair = (Element)pathPairs.item(i);
			mPathPairs[i] =new PathPair();
			String sFrom = ePathPair.getAttribute("from"); 				
			String sTo = ePathPair.getAttribute("to");
			String sMakeCopy = ePathPair.getAttribute("makeCopy");	
			mPathPairs[i].from = sFrom==null?"":sFrom;
			mPathPairs[i].to = sTo==null?"":sTo;
			mPathPairs[i].makeCopy = (sMakeCopy!=null && sMakeCopy.equals("true"))?true:false;
		}
		return mPathPairs;
	}//getInputFilesToMove

	/**
	 * get the number of output directories to move or copy (in <job> element)
	 * 
	 * @return the number of output directories to move or copy (in <job> element)
	 */
	int  getNumberOfOutputDirectoriesToMove(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return 0;
		Element eOutputDirectoriesToMove = (Element)XMLUtil.findChildNode(eJob, "outputDirectoriesToMove");
		if(eOutputDirectoriesToMove == null) return 0;
		String sNumberOfOutputDirectoriesToMove = eOutputDirectoriesToMove.getAttribute("numberOfPathPairs");
		if(sNumberOfOutputDirectoriesToMove == null || sNumberOfOutputDirectoriesToMove.length() <= 0) return 0;
		try{
			int iNumberOfOutputDirectoriesToMove = Integer.parseInt(sNumberOfOutputDirectoriesToMove);
			return iNumberOfOutputDirectoriesToMove;
		}
		catch(Exception e){
			return 0;
		}	
	}//getNumberOfOutputDirectoriesToMove

	/**
	 * Get get the list of output directories that need to be moved or copied
	 * 
	 * @return the list of output directories that need to be moved or copied. 
	 */
	public PathPair[] getOutputDirectoriesToMove(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return null;
		Element eOutputDirectoriesToMove = (Element)XMLUtil.findChildNode(eJob, "outputDirectoriesToMove");
		if(eOutputDirectoriesToMove == null) return null;
		NodeList pathPairs = eOutputDirectoriesToMove.getElementsByTagName("pathPair");
		if(pathPairs == null || pathPairs.getLength() <= 0) return null;
		int iPathPairs = pathPairs.getLength();
		PathPair[] mPathPairs = new PathPair[iPathPairs];
		for(int i = 0; i < iPathPairs; i++){
			Element ePathPair = (Element)pathPairs.item(i);
			mPathPairs[i] =new PathPair();
			String sFrom = ePathPair.getAttribute("from"); 				
			String sTo = ePathPair.getAttribute("to");
			String sMakeCopy = ePathPair.getAttribute("makeCopy");	
			mPathPairs[i].from = sFrom==null?"":sFrom;
			mPathPairs[i].to = sTo==null?"":sTo;
			mPathPairs[i].makeCopy = (sMakeCopy!=null && sMakeCopy.equals("true"))?true:false;
		}
		return mPathPairs;
	}//getOutputDirectoriesToMove

	/**
	 * get the number of output files to move or copy (in <job> element)
	 * 
	 * @return the number of output files to move or copy (in <job> element)
	 */
	int  getNumberOfOutputFilesToMove(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return 0;
		Element eOutputFilesToMove = (Element)XMLUtil.findChildNode(eJob, "outputFilesToMove");
		if(eOutputFilesToMove == null) return 0;
		String sNumberOfOutputFilesToMove = eOutputFilesToMove.getAttribute("numberOfPathPairs");
		if(sNumberOfOutputFilesToMove == null || sNumberOfOutputFilesToMove.length() <= 0) return 0;
		try{
			int iNumberOfOutputFilesToMove = Integer.parseInt(sNumberOfOutputFilesToMove);
			return iNumberOfOutputFilesToMove;
		}
		catch(Exception e){
			return 0;
		}	
	}//getNumberOfOutputFilesToMove

	/**
	 * Get get the list of output files that need to be moved or copied
	 * 
	 * @return the list of output files that need to be moved or copied. 
	 */
	public PathPair[] getOutputFilesToMove(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return null;
		Element eOutputFilesToMove = (Element)XMLUtil.findChildNode(eJob, "outputFilesToMove");
		if(eOutputFilesToMove == null) return null;
		NodeList pathPairs = eOutputFilesToMove.getElementsByTagName("pathPair");
		if(pathPairs == null || pathPairs.getLength() <= 0) return null;
		int iPathPairs = pathPairs.getLength();
		PathPair[] mPathPairs = new PathPair[iPathPairs];
		for(int i = 0; i < iPathPairs; i++){
			Element ePathPair = (Element)pathPairs.item(i);
			mPathPairs[i] =new PathPair();
			String sFrom = ePathPair.getAttribute("from"); 				
			String sTo = ePathPair.getAttribute("to");
			String sMakeCopy = ePathPair.getAttribute("makeCopy");	
			mPathPairs[i].from = sFrom==null?"":sFrom;
			mPathPairs[i].to = sTo==null?"":sTo;
			mPathPairs[i].makeCopy = (sMakeCopy!=null && sMakeCopy.equals("true"))?true:false;
		}
		return mPathPairs;
	}//getOutputFilesToMove

	/**
	 * get the number of files to delete (in <job> element)
	 * 
	 * @return the number of files to delete (in <job> element)
	 */
	int  getNumberOfFilesToDelete(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return 0;
		Element eFilesToDelete = (Element)XMLUtil.findChildNode(eJob, "filesToDelete");
		if(eFilesToDelete == null) return 0;
		String sNumberFilesToDelete = eFilesToDelete.getAttribute("numberOfPaths");
		if(sNumberFilesToDelete == null || sNumberFilesToDelete.length() <= 0) return 0;
		try{
			int iNumberFilesToDelete = Integer.parseInt(sNumberFilesToDelete);
			return iNumberFilesToDelete;
		}
		catch(Exception e){
			return 0;
		}	
	}//getNumberOfFilesToDelete


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
	 * get the number of directories to delete (in <job> element)
	 * 
	 * @return the number of directories to delete (in <job> element)
	 */
	int  getNumberOfDirectoriesToDelete(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return 0;
		Element eDirectoriesToDelete = (Element)XMLUtil.findChildNode(eJob, "directoriesToDelete");
		if(eDirectoriesToDelete == null) return 0;
		String sNumberDirectoriesToDelete = eDirectoriesToDelete.getAttribute("numberOfPaths");
		if(sNumberDirectoriesToDelete == null || sNumberDirectoriesToDelete.length() <= 0) return 0;
		try{
			int iNumberDirectoriesToDelete = Integer.parseInt(sNumberDirectoriesToDelete);
			return iNumberDirectoriesToDelete;
		}
		catch(Exception e){
			return 0;
		}	
	}//getNumberOfDirectoriesToDelete


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
	 * get the number of processes to kill (in <job> element)
	 * 
	 * @return the number of processes to kill (in <job> element)
	 */
	int  getNumberOfProcessesToKill(){
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return 0;
		Element eProcessesToKill = (Element)XMLUtil.findChildNode(eJob, "processesToKill");
		if(eProcessesToKill == null) return 0;
		String sNumberOfProcessesToKill = eProcessesToKill.getAttribute("numberOfProcesses");
		if(sNumberOfProcessesToKill == null || sNumberOfProcessesToKill.length() <= 0) return 0;
		try{
			int iNumberOfProcessesToKill = Integer.parseInt(sNumberOfProcessesToKill);
			return iNumberOfProcessesToKill;
		}
		catch(Exception e){
			return 0;
		}	
	}//getNumberOfProcessesToKill


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
	 * get the number of other <job> options
	 * 
	 * @return the number of other <job> options
	 */
	public int  getNumberOfOtherJobOptions(){	
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return 0;
		Element eOtherOptions = (Element)XMLUtil.findChildNode(eJob, "otherOptions");
		if(eOtherOptions == null) return 0;
		String sNumberOfOtherOptions = eOtherOptions.getAttribute("numberOfOtherOptions");
		if(sNumberOfOtherOptions == null || sNumberOfOtherOptions.length() <= 0) return 0;
		try{
			int iNumberOfOtherOptions = Integer.parseInt(sNumberOfOtherOptions);
			return iNumberOfOtherOptions;
		}
		catch(Exception e){
			return 0;
		}	
	}//getNumberOfOtherJobOptions

	/**
	 * get the array of other <job> options
	 * 
	 * @return the array of other <job> options
	 */
	public OtherOption[] getOtherJobOptions(){	
		Element eJob = (Element)XMLUtil.findChildNode(m_eRoot, "job");
		if(eJob == null) return null;
		Element eOtherOptions = (Element)XMLUtil.findChildNode(eJob, "otherOptions");
		if(eOtherOptions == null) return null;
		NodeList others = eOtherOptions.getElementsByTagName("other");
		if(others == null || others.getLength() <= 0) return null;
		int iOthers = others.getLength();
		OtherOption[] mOthers = new OtherOption[iOthers];
		for(int i = 0; i < iOthers; i++){
			Element eOther = (Element)others.item(i);
			mOthers[i] =new OtherOption();
			String sName = eOther.getAttribute("name"); 				
			String sValue = eOther.getAttribute("value");
			String sDescription = eOther.getAttribute("description");	
			mOthers[i].name = sName==null?"":sName;
			mOthers[i].value = sValue==null?"":sValue;
			mOthers[i].description = sDescription==null?"":sDescription;
		}
		return mOthers;
	}//getOtherJobOptions

	/**
	 * get the number of other options associated with a category
	 * @param category - The name of the option category
	 * @return the number of other options associated with the element <"category">
	 */
	public int getNumberOfOtherOptions(String category){
		if (category.equals("general")){
			return getNumberOfOtherGeneralOptions();
		}
		else if (category.equals("system")){
			return getNumberOfOtherSystemOptions();
		}
		else if (category.equals("service")){
			return getNumberOfOtherServiceOptions();
		}
		else if (category.equals("job")){
			return getNumberOfOtherJobOptions();
		}
		else{
			return 0;
		}
	}//getNumberOfOtherOptions


	/**
	 * get the array of other options associated with a category
	 * @param category - The name of the option category
	 * @return other options associated with the element <"category">
	 * @note This function returns NULL if category is not found
	 */
	public OtherOption[] getOtherOptions(String category){
		if (category.equals("general")){
			return getOtherGeneralOptions();
		}
		else if (category.equals("system")){
			return getOtherSystemOptions();
		}
		else if (category.equals("service")){
			return getOtherServiceOptions();
		}
		else if (category.equals("job")){
			return getOtherJobOptions();
		}
		else{
			return null;
		}
	}//getOtherOptions

	/**
	 * Get variable number. 
	 * 
	 * @return variable number, -1 if no information. 
	 */
	public int getNumberOfVariables(){
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
	}//getNumberOfVariables

	/**
	 * Get objective number. 
	 * 
	 * @return objective number, -1 if no information. 
	 */
	public int getNumberOfObjectives(){
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
	}//getNumberOfObjectives

	/**
	 * Get constraint number. 
	 * 
	 * @return constraint number, -1 if no information. 
	 */
	public int getNumberOfConstraints(){
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
	}//getNumberOfConstraints


	/**
	 * get the number of other variable options (in <optimization> element)
	 * @return the number of other variable options (in <optimization> element)
	 */
	public int getNumberOfOtherVariableOptions(){
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
		if(eOptimization == null) return 0;
		Element eVariables = (Element)XMLUtil.findChildNode(eOptimization, "variables");
		if(eVariables == null) return 0;
		String sNumber =  eVariables.getAttribute("numberOfOtherVariableOptions");
		try {
			int iNumber = Integer.parseInt(sNumber);
			return iNumber;
		} 
		catch (Exception e) {
			return 0;
		}
	}//getNumberOfOtherVariableOptions

	/**
	 * get the numer of variables that have initial values (in <optimization> element)
	 * @return the numer of variables that have initial values (in <optimization> element)
	 */
	public int getNumberOfInitVarValues(){
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
		if(eOptimization == null) return 0;
		Element eVariables = (Element)XMLUtil.findChildNode(eOptimization, "variables");
		if(eVariables == null) return 0;
		Element eInitialVariableValues = (Element)XMLUtil.findChildNode(eVariables, "initialVariableValues");
		if(eInitialVariableValues == null) return 0;
		String sNumber =  eInitialVariableValues.getAttribute("numberOfVar");
		try {
			int iNumber = Integer.parseInt(sNumber);
			return iNumber;
		} 
		catch (Exception e) {
			return 0;
		}
	}//getNumberOfInitVarValues

	/**
	 * get the number of string-valued variables that have initial values (in <optimization> element)
	 * @return the number of string-valued variables that have initial values (in <optimization> element)
	 */
	public int getNumberOfInitVarValuesString(){
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
		if(eOptimization == null) return 0;
		Element eVariables = (Element)XMLUtil.findChildNode(eOptimization, "variables");
		if(eVariables == null) return 0;
		Element eInitialVariableValuesString = (Element)XMLUtil.findChildNode(eVariables, "initialVariableValuesString");
		if(eInitialVariableValuesString == null) return 0;
		String sNumber =  eInitialVariableValuesString.getAttribute("numberOfVar");
		try {
			int iNumber = Integer.parseInt(sNumber);
			return iNumber;
		} 
		catch (Exception e) {
			return 0;
		}
	}//getNumberOfInitVarValuesString

	/**
	 * get the number of variables that are given initial basis status (in <optimization> element)
	 * @return the number of variables that are given initial basis status (in <optimization> element)
	 */
	public int getNumberOfInitialBasisVariables(){
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
		if(eOptimization == null) return 0;
		Element eVariables = (Element)XMLUtil.findChildNode(eOptimization, "variables");
		if(eVariables == null) return 0;
		Element eInitialBasisStatus = (Element)XMLUtil.findChildNode(eVariables, "initialBasisStatus");
		if(eInitialBasisStatus == null) return 0;
		String sNumber =  eInitialBasisStatus.getAttribute("numberOfVar");
		try {
			int iNumber = Integer.parseInt(sNumber);
			return iNumber;
		} 
		catch (Exception e) {
			return 0;
		}
	}//getNumberOfInitialBasisVariables

	/**
	 * get the number of variables that are given integer variable selection weights (in <optimization> element)
	 * @return the number of variables that are given integer variable selection weights (in <optimization> element)
	 */
	public int getNumberOfIntegerVariableSelectionWeights(){
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
		if(eOptimization == null) return 0;
		Element eVariables = (Element)XMLUtil.findChildNode(eOptimization, "variables");
		if(eVariables == null) return 0;
		Element eintegerVariableSelectionWeights = (Element)XMLUtil.findChildNode(eVariables, "integerVariableSelectionWeights");
		if(eintegerVariableSelectionWeights == null) return 0;
		String sNumber =  eintegerVariableSelectionWeights.getAttribute("numberOfVar");
		try {
			int iNumber = Integer.parseInt(sNumber);
			return iNumber;
		} 
		catch (Exception e) {
			return 0;
		}
	}//getNumberOfIntegerVariableSelectionWeights

	/**
	 * get the number of variables that are given integer variable selection weights (in <optimization> element)
	 * @return the number of variables that are given integer variable selection weights (in <optimization> element)
	 */
	public int getNumberOfSOSVariableSelectionWeights(){
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
		if(eOptimization == null) return 0;
		Element eVariables = (Element)XMLUtil.findChildNode(eOptimization, "variables");
		if(eVariables == null) return 0;
		Element eSOSVariableSelectionWeights = (Element)XMLUtil.findChildNode(eVariables, "SOSVariableSelectionWeights");
		if(eSOSVariableSelectionWeights == null) return 0;
		String sNumber =  eSOSVariableSelectionWeights.getAttribute("numberOfSets");
		try {
			int iNumber = Integer.parseInt(sNumber);
			return iNumber;
		} 
		catch (Exception e) {
			return 0;
		}
	}//getNumberOfSOSVariableSelectionWeights

	/**
	 * get the number of other objective options (in <optimization> element)
	 * @return the number of other objective options (in <optimization> element)
	 */
	public int getNumberOfOtherObjectiveOptions(){
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
		if(eOptimization == null) return 0;
		Element eObjectives = (Element)XMLUtil.findChildNode(eOptimization, "objectives");
		if(eObjectives == null) return 0;
		String sNumber =  eObjectives.getAttribute("numberOfOtherObjectiveOptions");
		try {
			int iNumber = Integer.parseInt(sNumber);
			return iNumber;
		} 
		catch (Exception e) {
			return 0;
		}
	}//getNumberOfOtherObjectiveOptions

	/**
	 * get the numer of objectives that have initial values (in <optimization> element)
	 * @return the numer of objectives that have initial values (in <optimization> element)
	 */
	public int getNumberOfInitObjValues(){
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
		if(eOptimization == null) return 0;
		Element eObjectives = (Element)XMLUtil.findChildNode(eOptimization, "objectives");
		if(eObjectives == null) return 0;
		Element eInitialObjectiveValues = (Element)XMLUtil.findChildNode(eObjectives, "initialObjectiveValues");
		if(eInitialObjectiveValues == null) return 0;
		String sNumber =  eInitialObjectiveValues.getAttribute("numberOfObj");
		try {
			int iNumber = Integer.parseInt(sNumber);
			return iNumber;
		} 
		catch (Exception e) {
			return 0;
		}
	}//getNumberOfInitObjectiveValues

	/**
	 * get the numer of objectives that have initial bounds (in <optimization> element)
	 * @return the numer of objectives that have initial bounds (in <optimization> element)
	 */
	public int getNumberOfInitObjBounds(){
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
		if(eOptimization == null) return 0;
		Element eObjectives = (Element)XMLUtil.findChildNode(eOptimization, "objectives");
		if(eObjectives == null) return 0;
		Element eInitialObjectiveBounds = (Element)XMLUtil.findChildNode(eObjectives, "initialObjectiveBounds");
		if(eInitialObjectiveBounds == null) return 0;
		String sNumber =  eInitialObjectiveBounds.getAttribute("numberOfObj");
		try {
			int iNumber = Integer.parseInt(sNumber);
			return iNumber;
		} 
		catch (Exception e) {
			return 0;
		}
	}//getNumberOfInitObjectiveBounds

	/**
	 * get the number of other constraint options (in <optimization> element)
	 * @return the number of other constraint options (in <optimization> element)
	 */
	public int getNumberOfOtherConstraintOptions(){
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
		if(eOptimization == null) return 0;
		Element eConstraints = (Element)XMLUtil.findChildNode(eOptimization, "constraints");
		if(eConstraints == null) return 0;
		String sNumber =  eConstraints.getAttribute("numberOfOtherConstraintOptions");
		try {
			int iNumber = Integer.parseInt(sNumber);
			return iNumber;
		} 
		catch (Exception e) {
			return 0;
		}
	}//getNumberOfOtherConstraintOptions

	/**
	 * get the numer of constraints that have initial values (in <optimization> element)
	 * @return the numer of constraints that have initial values (in <optimization> element)
	 */
	public int getNumberOfInitConValues(){
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
		if(eOptimization == null) return 0;
		Element eConstraints = (Element)XMLUtil.findChildNode(eOptimization, "constraints");
		if(eConstraints == null) return 0;
		Element eInitialConstraintValues = (Element)XMLUtil.findChildNode(eConstraints, "initialConstraintValues");
		if(eInitialConstraintValues == null) return 0;
		String sNumber =  eInitialConstraintValues.getAttribute("numberOfCon");
		try {
			int iNumber = Integer.parseInt(sNumber);
			return iNumber;
		} 
		catch (Exception e) {
			return 0;
		}
	}//getNumberOfInitConstraintValues

	/**
	 * get the numer of constraints that have initial dual values (in <optimization> element)
	 * @return the numer of constraints that have initial dual values (in <optimization> element)
	 */
	public int getNumberOfInitDualVarValues(){
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
		if(eOptimization == null) return 0;
		Element eConstraints = (Element)XMLUtil.findChildNode(eOptimization, "constraints");
		if(eConstraints == null) return 0;
		Element eInitialConstraintValues = (Element)XMLUtil.findChildNode(eConstraints, "initialDualValues");
		if(eInitialConstraintValues == null) return 0;
		String sNumber =  eInitialConstraintValues.getAttribute("numberOfCon");
		try {
			int iNumber = Integer.parseInt(sNumber);
			return iNumber;
		} 
		catch (Exception e) {
			return 0;
		}
	}//getNumberOfInitDualVarValues

	/**
	 * get the number of other solver options (in <optimization> element)
	 * @return the number of other solver options (in <optimization> element)
	 */
	public int getNumberOfSolverOptions(){
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
		if(eOptimization == null) return 0;
		Element eSolverOptions = (Element)XMLUtil.findChildNode(eOptimization, "solverOptions");
		if(eSolverOptions == null) return 0;
		String sNumber =  eSolverOptions.getAttribute("numberOfSolverOptions");
		try {
			int iNumber = Integer.parseInt(sNumber);
			return iNumber;
		} 
		catch (Exception e) {
			return 0;
		}
	}//getNumberOfSolverOptions


	/**
	 * get initial variable values (double[]). 
	 * @return a double array of the initial variable values, null if none. 
	 */
	public double[] getInitVarValuesDense(){
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
		if(eOptimization == null) return null;
		Element eVariables = (Element)XMLUtil.findChildNode(eOptimization, "variables");
		if(eVariables == null) return null;
		Element eInitialVariableValues = (Element)XMLUtil.findChildNode(eVariables, "initialVariableValues");
		if(eInitialVariableValues == null) return null;
		NodeList vars = eInitialVariableValues.getElementsByTagName("var");
		if(vars == null || vars.getLength() <= 0) return null;
		int iVars = vars.getLength();
		int iNumberVariables = this.getNumberOfVariables();
		double[] mdValues = new double[iNumberVariables];
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
	}//getInitVarValuesDense

	/**
	 * get the list of initial variable values in sparse form
	 * @return a list of index/value pairs.
	 */
	public InitVarValue[] getInitVarValuesSparse(){
		InitVarValue[] mVar = null;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
		if(eOptimization == null) return null;
		Element eVariables = (Element)XMLUtil.findChildNode(eOptimization, "variables");
		if(eVariables == null) return null;
		Element eInitialVariableValues = (Element)XMLUtil.findChildNode(eVariables, "initialVariableValues");
		if(eInitialVariableValues == null) return null;
		NodeList vars = eInitialVariableValues.getElementsByTagName("var");
		if(vars == null || vars.getLength() <= 0) return null;
		int iVars = vars.getLength();
		mVar = new InitVarValue[iVars];
		for(int i = 0; i < iVars; i++){
			try{
				mVar[i] = new InitVarValue();
				mVar[i].idx = Integer.parseInt(((Element)vars.item(i)).getAttribute("idx"));
				mVar[i].value = Double.parseDouble(((Element)vars.item(i)).getAttribute("value"));
			}
			catch(Exception e){
				return null;
			}
		}
		return mVar;
	}//getInitVarValuesSparse

	/**
	 * get the list of initial values for string-valued variables in dense form
	 * @return an array of value strings
	 *  @note return the null string for variables that are not initialed
	 */
	public String[] getInitVarStringsDense(){
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
		if(eOptimization == null) return null;
		Element eVariables = (Element)XMLUtil.findChildNode(eOptimization, "variables");
		if(eVariables == null) return null;
		Element eInitialVariableValues = (Element)XMLUtil.findChildNode(eVariables, "initialVariableValuesString");
		if(eInitialVariableValues == null) return null;
		NodeList vars = eInitialVariableValues.getElementsByTagName("var");
		if(vars == null || vars.getLength() <= 0) return null;
		int iVars = vars.getLength();
		int iNumberVairables = this.getNumberOfVariables();
		String[] msValues = new String[iNumberVairables];
		for(int i = 0; i < iVars; i++){
			try{
				int iIndex = Integer.parseInt(((Element)vars.item(i)).getAttribute("idx"));
				String sValue = ((Element)vars.item(i)).getAttribute("value");
				msValues[iIndex] = sValue;
			}
			catch(Exception e){
				return null;
			}
		}
		return msValues;
	}//getInitVarStringsDense


	/**
	 * get the list of initial values for string-valued variables in sparse form
	 * @return a list of index/value pairs
	 */
	public InitVarValueString[] getInitVarStringsSparse(){
		InitVarValueString[] mVar = null;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
		if(eOptimization == null) return null;
		Element eVariables = (Element)XMLUtil.findChildNode(eOptimization, "variables");
		if(eVariables == null) return null;
		Element eInitialVariableValues = (Element)XMLUtil.findChildNode(eVariables, "initialVariableValuesString");
		if(eInitialVariableValues == null) return null;
		NodeList vars = eInitialVariableValues.getElementsByTagName("var");
		if(vars == null || vars.getLength() <= 0) return null;
		int iVars = vars.getLength();
		mVar = new InitVarValueString[iVars];
		for(int i = 0; i < iVars; i++){
			try{
				mVar[i] = new InitVarValueString();
				mVar[i].idx = Integer.parseInt(((Element)vars.item(i)).getAttribute("idx"));
				mVar[i].value = ((Element)vars.item(i)).getAttribute("value");
			}
			catch(Exception e){
				return null;
			}
		}
		return mVar;
	}//getInitVarStringsSparse
	
	/**
	 * get the list of initial variable basis status in sparse form
	 * @return a list of index/value pairs.
	 */
	public InitBasStatus[] getInitialBasisStatusSparse(){
		InitBasStatus[] mVar = null;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
		if(eOptimization == null) return null;
		Element eVariables = (Element)XMLUtil.findChildNode(eOptimization, "variables");
		if(eVariables == null) return null;
		Element eInitialVariableValues = (Element)XMLUtil.findChildNode(eVariables, "initialBasisStatus");
		if(eInitialVariableValues == null) return null;
		NodeList vars = eInitialVariableValues.getElementsByTagName("var");
		if(vars == null || vars.getLength() <= 0) return null;
		int iVars = vars.getLength();
		mVar = new InitBasStatus[iVars];
		for(int i = 0; i < iVars; i++){
			try{
				mVar[i] = new InitBasStatus();
				mVar[i].idx = Integer.parseInt(((Element)vars.item(i)).getAttribute("idx"));
				mVar[i].value = ((Element)vars.item(i)).getAttribute("value");
			}
			catch(Exception e){
				return null;
			}
		}
		return mVar;
	}//getInitialBasisStatusSparse

	/**
	 * get the list of initial basis status for string-valued variables in dense form
	 * @return an array of value strings
	 */
	public String[] getInitialBasisStatusDense(){
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
		if(eOptimization == null) return null;
		Element eVariables = (Element)XMLUtil.findChildNode(eOptimization, "variables");
		if(eVariables == null) return null;
		Element eInitialVariableValues = (Element)XMLUtil.findChildNode(eVariables, "initialBasisStatus");
		if(eInitialVariableValues == null) return null;
		NodeList vars = eInitialVariableValues.getElementsByTagName("var");
		if(vars == null || vars.getLength() <= 0) return null;
		int iVars = vars.getLength();
		int iNumberVariables = this.getNumberOfVariables();
		String[] msValues = new String[iNumberVariables];
		for(int i = 0; i < iVars; i++){
			try{
				int iIndex = Integer.parseInt(((Element)vars.item(i)).getAttribute("idx"));
				String sValue = ((Element)vars.item(i)).getAttribute("value");
				msValues[iIndex] = sValue;
			}
			catch(Exception e){
				return null;
			}
		}
		return msValues;
	}//getInitialBasisStatusDense

	/**
	 * get initial objective values (double[]). 
	 * @return a double array of the initial objective values, null if none. 
	 */
	public double[] getInitObjValuesDense(){
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
		if(eOptimization == null) return null;
		Element eObjectives = (Element)XMLUtil.findChildNode(eOptimization, "objectives");
		if(eObjectives == null) return null;
		Element eInitialObjectiveValues = (Element)XMLUtil.findChildNode(eObjectives, "initialObjectiveValues");
		if(eInitialObjectiveValues == null) return null;
		NodeList objs = eInitialObjectiveValues.getElementsByTagName("obj");
		if(objs == null || objs.getLength() <= 0) return null;
		int iObjs = objs.getLength();
		int iNumberObjectives = this.getNumberOfObjectives();
		double[] mdValues = new double[iNumberObjectives];
		for(int i = 0; i < iObjs; i++){
			try{
				int iIndex = Integer.parseInt(((Element)objs.item(i)).getAttribute("idx"));
				double dValue = Double.parseDouble(((Element)objs.item(i)).getAttribute("value"));
				mdValues[Math.abs(iIndex)-1] = dValue;
			}
			catch(Exception e){
				return null;
			}
		}
		return mdValues;
	}//getInitObjValuesDense

	/**
	 * get the list of initial objective values in sparse form
	 * @return a list of index/value pairs.
	 */
	public InitObjValue[] getInitObjValuesSparse(){
		InitObjValue[] mObj = null;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
		if(eOptimization == null) return null;
		Element eObjectives = (Element)XMLUtil.findChildNode(eOptimization, "objectives");
		if(eObjectives == null) return null;
		Element eInitialObjectiveValues = (Element)XMLUtil.findChildNode(eObjectives, "initialObjectiveValues");
		if(eInitialObjectiveValues == null) return null;
		NodeList objs = eInitialObjectiveValues.getElementsByTagName("obj");
		if(objs == null || objs.getLength() <= 0) return null;
		int iObjs = objs.getLength();
		mObj = new InitObjValue[iObjs];
		for(int i = 0; i < iObjs; i++){
			try{
				mObj[i] = new InitObjValue();
				mObj[i].idx = Integer.parseInt(((Element)objs.item(i)).getAttribute("idx"));
				mObj[i].value = Double.parseDouble(((Element)objs.item(i)).getAttribute("value"));
			}
			catch(Exception e){
				return null;
			}
		}
		return mObj;
	}//getInitObjValuesSparse

	/**
	 * get initial objective lower bounds (double[]). 
	 * @return a double array of the initial objective lower bounds, null if none. 
	 */
	public double[] getInitObjLowerBoundsDense(){
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
		if(eOptimization == null) return null;
		Element eObjectives = (Element)XMLUtil.findChildNode(eOptimization, "objectives");
		if(eObjectives == null) return null;
		Element eInitialObjectiveBounds = (Element)XMLUtil.findChildNode(eObjectives, "initialObjectiveBounds");
		if(eInitialObjectiveBounds == null) return null;
		NodeList objs = eInitialObjectiveBounds.getElementsByTagName("obj");
		if(objs == null || objs.getLength() <= 0) return null;
		int iObjs = objs.getLength();
		int iNumberObjectives = this.getNumberOfObjectives();
		double[] mdBounds = new double[iNumberObjectives];
		for(int i = 0; i < iObjs; i++){
			try{
				int iIndex = Integer.parseInt(((Element)objs.item(i)).getAttribute("idx"));
				double dBound = Double.parseDouble(((Element)objs.item(i)).getAttribute("lbValue"));
				mdBounds[Math.abs(iIndex)-1] = dBound;
			}
			catch(Exception e){
				return null;
			}
		}
		return mdBounds;
	}//getInitObjLowerBoundsDense

	/**
	 * get initial objective uppper bounds (double[]). 
	 * @return a double array of the initial objective upper bounds, null if none. 
	 */
	public double[] getInitObjUpperBoundsDense(){
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
		if(eOptimization == null) return null;
		Element eObjectives = (Element)XMLUtil.findChildNode(eOptimization, "objectives");
		if(eObjectives == null) return null;
		Element eInitialObjectiveBounds = (Element)XMLUtil.findChildNode(eObjectives, "initialObjectiveBounds");
		if(eInitialObjectiveBounds == null) return null;
		NodeList objs = eInitialObjectiveBounds.getElementsByTagName("obj");
		if(objs == null || objs.getLength() <= 0) return null;
		int iObjs = objs.getLength();
		int iNumberofObjectives = this.getNumberOfObjectives();
		double[] mdBounds = new double[iNumberofObjectives];
		for(int i = 0; i < iObjs; i++){
			try{
				int iIndex = Integer.parseInt(((Element)objs.item(i)).getAttribute("idx"));
				double dBound = Double.parseDouble(((Element)objs.item(i)).getAttribute("ubValue"));
				mdBounds[Math.abs(iIndex)-1] = dBound;
			}
			catch(Exception e){
				return null;
			}
		}
		return mdBounds;
	}//getInitObjUpperBoundsDense

	/**
	 * get the list of initial objective bounds in sparse form
	 * @return a list of index/bound pairs.
	 */
	public InitObjBound[] getInitObjBoundsSparse(){
		InitObjBound[] mObj = null;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
		if(eOptimization == null) return null;
		Element eObjectives = (Element)XMLUtil.findChildNode(eOptimization, "objectives");
		if(eObjectives == null) return null;
		Element eInitialObjectiveBounds = (Element)XMLUtil.findChildNode(eObjectives, "initialObjectiveBounds");
		if(eInitialObjectiveBounds == null) return null;
		NodeList objs = eInitialObjectiveBounds.getElementsByTagName("obj");
		if(objs == null || objs.getLength() <= 0) return null;
		int iObjs = objs.getLength();
		mObj = new InitObjBound[iObjs];
		for(int i = 0; i < iObjs; i++){
			try{
				mObj[i] = new InitObjBound();
				mObj[i].idx = Integer.parseInt(((Element)objs.item(i)).getAttribute("idx"));
				mObj[i].lbValue = Double.parseDouble(((Element)objs.item(i)).getAttribute("lbValue"));
				mObj[i].ubValue = Double.parseDouble(((Element)objs.item(i)).getAttribute("ubValue"));
			}
			catch(Exception e){
				return null;
			}
		}
		return mObj;
	}//getInitObjValuesSparse

	/**
	 * get initial constraint values (double[]). 
	 * @return a double array of the initial constraint values, null if none. 
	 */
	public double[] getInitConValuesDense(){
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
		if(eOptimization == null) return null;
		Element eConstraints = (Element)XMLUtil.findChildNode(eOptimization, "constraints");
		if(eConstraints == null) return null;
		Element eInitialConstraintValues = (Element)XMLUtil.findChildNode(eConstraints, "initialConstraintValues");
		if(eInitialConstraintValues == null) return null;
		NodeList cons = eInitialConstraintValues.getElementsByTagName("con");
		if(cons == null || cons.getLength() <= 0) return null;
		int iCons = cons.getLength();
		int iNumberConstraints = this.getNumberOfConstraints();
		double[] mdValues = new double[iNumberConstraints];
		for(int i = 0; i < iCons; i++){
			try{
				int iIndex = Integer.parseInt(((Element)cons.item(i)).getAttribute("idx"));
				double dValue = Double.parseDouble(((Element)cons.item(i)).getAttribute("value"));
				mdValues[Math.abs(iIndex)-1] = dValue;
			}
			catch(Exception e){
				return null;
			}
		}
		return mdValues;
	}//getInitConValuesDense

	/**
	 * get the list of initial constraint values in sparse form
	 * @return a list of index/value pairs.
	 */
	public InitConValue[] getInitConValuesSparse(){
		InitConValue[] mCon = null;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
		if(eOptimization == null) return null;
		Element eConstraints = (Element)XMLUtil.findChildNode(eOptimization, "constraints");
		if(eConstraints == null) return null;
		Element eInitialConstraintValues = (Element)XMLUtil.findChildNode(eConstraints, "initialConstraintValues");
		if(eInitialConstraintValues == null) return null;
		NodeList cons = eInitialConstraintValues.getElementsByTagName("con");
		if(cons == null || cons.getLength() <= 0) return null;
		int iCons = cons.getLength();
		mCon = new InitConValue[iCons];
		for(int i = 0; i < iCons; i++){
			try{
				mCon[i] = new InitConValue();
				mCon[i].idx = Integer.parseInt(((Element)cons.item(i)).getAttribute("idx"));
				mCon[i].value = Double.parseDouble(((Element)cons.item(i)).getAttribute("value"));
			}
			catch(Exception e){
				return null;
			}
		}
		return mCon;
	}//getInitConValuesSparse

	/**
	 * get initial dual variable lower bounds (double[]). 
	 * @return a double array of the initial dual variable lower bounds, null if none. 
	 */
	public double[] getInitDualVarLowerBoundsDense(){
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
		if(eOptimization == null) return null;
		Element eConstraints = (Element)XMLUtil.findChildNode(eOptimization, "constraints");
		if(eConstraints == null) return null;
		Element eInitialDualValues = (Element)XMLUtil.findChildNode(eConstraints, "initialDualValues");
		if(eInitialDualValues == null) return null;
		NodeList cons = eInitialDualValues.getElementsByTagName("con");
		if(cons == null || cons.getLength() <= 0) return null;
		int iCons = cons.getLength();
		int iNumberConstraints = this.getNumberOfConstraints();
		double[] mdBounds = new double[iNumberConstraints];
		for(int i = 0; i < iCons; i++){
			try{
				int iIndex = Integer.parseInt(((Element)cons.item(i)).getAttribute("idx"));
				double dBound = Double.parseDouble(((Element)cons.item(i)).getAttribute("lbValue"));
				mdBounds[iIndex] = dBound;
			}
			catch(Exception e){
				return null;
			}
		}
		return mdBounds;
	}//getInitDualVarLowerBoundsDense

	/**
	 * get initial dual variable uppper bounds (double[]). 
	 * @return a double array of the initial  dual variable upper bounds, null if none. 
	 */
	public double[] getInitDualVarUpperBoundsDense(){
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
		if(eOptimization == null) return null;
		Element eConstraints = (Element)XMLUtil.findChildNode(eOptimization, "constraints");
		if(eConstraints == null) return null;
		Element eInitialDualValues = (Element)XMLUtil.findChildNode(eConstraints, "initialDualValues");
		if(eInitialDualValues == null) return null;
		NodeList cons = eInitialDualValues.getElementsByTagName("con");
		if(cons == null || cons.getLength() <= 0) return null;
		int iCons = cons.getLength();
		int iNumberConstraints = this.getNumberOfConstraints();
		double[] mdBounds = new double[iNumberConstraints];
		for(int i = 0; i < iCons; i++){
			try{
				int iIndex = Integer.parseInt(((Element)cons.item(i)).getAttribute("idx"));
				double dBound = Double.parseDouble(((Element)cons.item(i)).getAttribute("ubValue"));
				mdBounds[iIndex] = dBound;
			}
			catch(Exception e){
				return null;
			}
		}
		return mdBounds;
	}//getInitDualVarUpperBoundsDense

	/**
	 * get the list of initial dual variable values in sparse form
	 * @return a list of index/bound pairs.
	 */
	public InitDualVarValue[] getInitDualVarValuesSparse(){
		InitDualVarValue[] mCon = null;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
		if(eOptimization == null) return null;
		Element eConstraints = (Element)XMLUtil.findChildNode(eOptimization, "constraints");
		if(eConstraints == null) return null;
		Element eInitialDualValues = (Element)XMLUtil.findChildNode(eConstraints, "initialDualValues");
		if(eInitialDualValues == null) return null;
		NodeList cons = eInitialDualValues.getElementsByTagName("con");
		if(cons == null || cons.getLength() <= 0) return null;
		int iCons = cons.getLength();
		mCon = new InitDualVarValue[iCons];
		for(int i = 0; i < iCons; i++){
			try{
				mCon[i] = new InitDualVarValue();
				mCon[i].idx = Integer.parseInt(((Element)cons.item(i)).getAttribute("idx"));
				mCon[i].lbValue = Double.parseDouble(((Element)cons.item(i)).getAttribute("lbValue"));
				mCon[i].ubValue = Double.parseDouble(((Element)cons.item(i)).getAttribute("ubValue"));
			}
			catch(Exception e){
				return null;
			}
		}
		return mCon;
	}//getInitDualVarValuesSparse


	/**
	 * get the array of solver options associated with a particular solver
	 * @param solver_name is the name of the solver
	 * 
	 * @return an array of solver options associated with this solver
	 */
	public SolverOption[] getSolverOptions(String solverName){
		m_solverOptionHashMap = new HashMap<String, SolverOption>();
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eRoot, "optimization");
		if(eOptimization == null) return null;
		Element eSolverOptions = (Element)XMLUtil.findChildNode(eOptimization, "solverOptions");
		if(eSolverOptions == null) return null;
		Vector<Element> vElements = XMLUtil.getChildElementsByTagName(eSolverOptions, "solverOption");
		int iNls	= vElements==null?0:vElements.size();
		int nSolverOptions = getNumberOfSolverOptions();
		Vector<SolverOption> vSolverOptions = new Vector<SolverOption>();
		for(int i = 0; i < iNls; i++){
			Element eSolverOption = (Element)(vElements.elementAt(i));
			NamedNodeMap	attributes =  eSolverOption.getAttributes();
			int n =attributes.getLength();
			String sName = "";
			String sValue = "";
			String sSolver = "";
			String sCategory = "";
			String sType = "";
			String sDescription = "";
			for (int j = 0; j < n; j++){
				Node	attr = attributes.item(j);
				String sAttributeName  = attr.getNodeName();
				String sAttributeValue = attr.getNodeValue();
				if (sAttributeName.equals("name")){
					sName = sAttributeValue;
				}
				else if (sAttributeName.equals("value")){
					sValue = sAttributeValue;
				}
				else if (sAttributeName.equals("solver")){
					sSolver = sAttributeValue;
				}
				else if (sAttributeName.equals("category")){
					sCategory = sAttributeValue;
				}
				else if (sAttributeName.equals("type")){
					sType = sAttributeValue;
				}
				else if (sAttributeName.equals("description")){
					sDescription = sAttributeValue;
				}
			}
			SolverOption solverOption = new SolverOption();
			solverOption.name = sName;
			solverOption.value = sValue;
			solverOption.solver = sSolver;
			solverOption.category = sCategory;
			solverOption.type = sType;
			solverOption.description = sDescription;
			m_solverOptionHashMap.put(sName, solverOption);
			if(solverName == null || solverName.length() <= 0 || solverName.equals(sSolver) ){
				vSolverOptions.add(solverOption);
			}
		}
		int nSize = vSolverOptions.size();
		SolverOption[] mSolverOptions = new SolverOption[nSize];
		for(int i = 0; i < nSize; i++){
			mSolverOptions[i] = vSolverOptions.elementAt(i);
		}
		return mSolverOptions;
	}//getOtherOptimizationOptions

	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		OSoLReader osolReader = new OSoLReader(false);
		//System.out.println(IOUtil.readStringFromFile(OSParameter.CODE_HOME + "OSRepository/test/osol/osol.osol"));
		//System.out.println(osolReader.readFile(OSParameter.CODE_HOME + "OSRepository/test/osol/osol.osol"));
		//System.out.println(IOUtil.readStringFromFile("c:/test.osol"));
		System.out.println(osolReader.readFile("c:/test.osol"));
//		System.out.println(osolReader.getOptionStr("scheduledStartTime"));
//		System.out.println(osolReader.getOptionDbl("minMemorySize"));
//		System.out.println(osolReader.getOptionInt("minCPUNumber"));
//		System.out.println(osolReader.getServiceURI());
//		System.out.println(osolReader.getServiceName());
//		System.out.println(osolReader.getInstanceName());		
//		System.out.println(osolReader.getInstanceLocation());		
//		System.out.println(osolReader.getInstanceLocationType());		
//		System.out.println(osolReader.getJobID());		
//		System.out.println(osolReader.getSolverToInvoke());		
//		System.out.println(osolReader.getLicense());		
//		System.out.println(osolReader.getUserName());		
//		System.out.println(osolReader.getPassword());		
//		System.out.println(osolReader.getContact());		
//		System.out.println(osolReader.getContactTransportType());		
//		int iNumberOfOtherGeneralOptions = osolReader.getNumberOfOtherGeneralOptions();
//		System.out.println(iNumberOfOtherGeneralOptions);
//		OtherOption[] mOtherGeneralOptions = osolReader.getOtherGeneralOptions();
//		for(int i = 0; i < iNumberOfOtherGeneralOptions; i++){
//		System.out.println(mOtherGeneralOptions[i].name);		
//		System.out.println(mOtherGeneralOptions[i].value);		
//		System.out.println(mOtherGeneralOptions[i].description);		
//		}

//		System.out.println(osolReader.getMinDiskSpace());		
//		System.out.println(osolReader.getMinDiskSpaceUnit());		
//		System.out.println(osolReader.getMinMemorySize());		
//		System.out.println(osolReader.getMinMemoryUnit());		
//		System.out.println(osolReader.getMinCPUSpeed());		
//		System.out.println(osolReader.getMinCPUSpeedUnit());		
//		System.out.println(osolReader.getMinCPUNumber());	
//		int iNumberOfOtherSystemOptions = osolReader.getNumberOfOtherSystemOptions();
//		System.out.println(iNumberOfOtherSystemOptions);
//		OtherOption[] mOtherSystemOptions = osolReader.getOtherSystemOptions();
//		for(int i = 0; i < iNumberOfOtherSystemOptions; i++){
//		System.out.println(mOtherSystemOptions[i].name);		
//		System.out.println(mOtherSystemOptions[i].value);		
//		System.out.println(mOtherSystemOptions[i].description);		
//		}

//		System.out.println(osolReader.getServiceType());	
//		int iNumberOfOtherServiceOptions = osolReader.getNumberOfOtherServiceOptions();
//		System.out.println(iNumberOfOtherServiceOptions);
//		OtherOption[] mOtherServiceOptions = osolReader.getOtherServiceOptions();
//		for(int i = 0; i < iNumberOfOtherServiceOptions; i++){
//		System.out.println(mOtherServiceOptions[i].name);		
//		System.out.println(mOtherServiceOptions[i].value);		
//		System.out.println(mOtherServiceOptions[i].description);		
//		}

//		System.out.println(osolReader.getMaxTime());		
//		System.out.println(osolReader.getMaxTimeUnit());		
//		System.out.println(XMLUtil.createXSDateTime(osolReader.getScheduledStartTime()));

//		int iNumberOfJobDependencies = osolReader.getNumberOfJobDependencies();
//		System.out.println(iNumberOfJobDependencies);
//		String[] msJobs = osolReader.getJobDependencies();
//		for(int i = 0; i < iNumberOfJobDependencies; i++) System.out.println(msJobs==null?"null":msJobs[i]);

//		int iNumberOfRequiredDirectories = osolReader.getNumberOfRequiredDirectories();
//		System.out.println(iNumberOfRequiredDirectories);
//		String[] msRequiredDirectories = osolReader.getRequiredDirectories();
//		for(int i = 0; i < iNumberOfRequiredDirectories; i++) System.out.println(msRequiredDirectories==null?"null":msRequiredDirectories[i]);		

//		int iNumberOfRequiredFiles = osolReader.getNumberOfRequiredFiles();
//		System.out.println(iNumberOfRequiredFiles);
//		String[] msRequiredFiles = osolReader.getRequiredFiles();
//		for(int i = 0; i < iNumberOfRequiredFiles; i++) System.out.println(msRequiredFiles==null?"null":msRequiredFiles[i]);		

//		int iNumberOfDirectoriesToMake = osolReader.getNumberOfDirectoriesToMake();
//		System.out.println(iNumberOfDirectoriesToMake);
//		String[] msDirectoriesToMake = osolReader.getDirectoriesToMake();
//		for(int i = 0; i < iNumberOfDirectoriesToMake; i++) System.out.println(msDirectoriesToMake==null?"null":msDirectoriesToMake[i]);		

//		int iNumberOfFilesToMake = osolReader.getNumberOfFilesToMake();
//		System.out.println(iNumberOfFilesToMake);
//		String[] msFilesToMake = osolReader.getFilesToMake();
//		for(int i = 0; i < iNumberOfFilesToMake; i++) System.out.println(msFilesToMake==null?"null":msFilesToMake[i]);		

//		int iNumberOfInputDirectoriesToMove = osolReader.getNumberOfInputDirectoriesToMove();
//		System.out.println(iNumberOfInputDirectoriesToMove);
//		PathPair[] mInputDirectoriesToMove = osolReader.getInputDirectoriesToMove();
//		for(int i = 0; i < iNumberOfInputDirectoriesToMove; i++){
//		System.out.println(mInputDirectoriesToMove[i].from);		
//		System.out.println(mInputDirectoriesToMove[i].to);		
//		System.out.println(mInputDirectoriesToMove[i].makeCopy);		
//		}

//		int iNumberOfInputFilesToMove = osolReader.getNumberOfInputFilesToMove();
//		System.out.println(iNumberOfInputFilesToMove);
//		PathPair[] mInputFilesToMove = osolReader.getInputFilesToMove();
//		for(int i = 0; i < iNumberOfInputFilesToMove; i++){
//		System.out.println(mInputFilesToMove[i].from);		
//		System.out.println(mInputFilesToMove[i].to);		
//		System.out.println(mInputFilesToMove[i].makeCopy);		
//		}

//		int iNumberOfOutputDirectoriesToMove = osolReader.getNumberOfOutputDirectoriesToMove();
//		System.out.println(iNumberOfOutputDirectoriesToMove);
//		PathPair[] mOutputDirectoriesToMove = osolReader.getOutputDirectoriesToMove();
//		for(int i = 0; i < iNumberOfOutputDirectoriesToMove; i++){
//		System.out.println(mOutputDirectoriesToMove[i].from);		
//		System.out.println(mOutputDirectoriesToMove[i].to);		
//		System.out.println(mOutputDirectoriesToMove[i].makeCopy);		
//		}

//		int iNumberOfOutputFilesToMove = osolReader.getNumberOfOutputFilesToMove();
//		System.out.println(iNumberOfOutputFilesToMove);
//		PathPair[] mOutputFilesToMove = osolReader.getOutputFilesToMove();
//		for(int i = 0; i < iNumberOfOutputFilesToMove; i++){
//		System.out.println(mOutputFilesToMove[i].from);		
//		System.out.println(mOutputFilesToMove[i].to);		
//		System.out.println(mOutputFilesToMove[i].makeCopy);		
//		}


//		int iNumberOfDirectoriesToDelete = osolReader.getNumberOfDirectoriesToDelete();
//		System.out.println(iNumberOfDirectoriesToDelete);
//		String[] msDirectoriesToDelete = osolReader.getDirectoriesToDelete();
//		for(int i = 0; i < iNumberOfDirectoriesToDelete; i++) System.out.println(msDirectoriesToDelete==null?"null":msDirectoriesToDelete[i]);		

//		int iNumberOfFilesToDelete = osolReader.getNumberOfFilesToDelete();
//		System.out.println(iNumberOfFilesToDelete);
//		String[] msFilesToDelete = osolReader.getFilesToDelete();
//		for(int i = 0; i < iNumberOfFilesToDelete; i++) System.out.println(msFilesToDelete==null?"null":msFilesToDelete[i]);		

//		int iNumberOfProcessesToKill = osolReader.getNumberOfProcessesToKill();
//		System.out.println(iNumberOfProcessesToKill);
//		String[] msProcessesToKill = osolReader.getProcessesToKill();
//		for(int i = 0; i < iNumberOfProcessesToKill; i++) System.out.println(msProcessesToKill==null?"null":msProcessesToKill[i]);		

//		int iNumberOfOtherJobOptions = osolReader.getNumberOfOtherJobOptions();
//		System.out.println(iNumberOfOtherJobOptions);
//		OtherOption[] mOtherJobOptions = osolReader.getOtherJobOptions();
//		for(int i = 0; i < iNumberOfOtherJobOptions; i++){
//		System.out.println(mOtherJobOptions[i].name);		
//		System.out.println(mOtherJobOptions[i].value);		
//		System.out.println(mOtherJobOptions[i].description);		
//		}

//		int iNumberOfOtherOptions = osolReader.getNumberOfOtherOptions("general");
//		System.out.println(iNumberOfOtherOptions);
//		OtherOption[] mOtherOptions = osolReader.getOtherOptions("job");
//		for(int i = 0; i < iNumberOfOtherOptions; i++){
//		System.out.println(mOtherOptions[i].name);		
//		System.out.println(mOtherOptions[i].value);		
//		System.out.println(mOtherOptions[i].description);		
//		}

		/*********************optimization*****************************/
//		System.out.println(osolReader.getNumberOfVariables());		
//		System.out.println(osolReader.getNumberOfObjectives());		
//		System.out.println(osolReader.getNumberOfConstraints());	
//
//		System.out.println(osolReader.getNumberOfOtherVariableOptions());	
//		System.out.println(osolReader.getNumberOfInitVarValues());	
//		System.out.println(osolReader.getNumberOfInitVarValuesString());	
//		System.out.println(osolReader.getNumberOfInitialBasisVariables());	
//		System.out.println(osolReader.getNumberOfIntegerVariableSelectionWeights());	
//		System.out.println(osolReader.getNumberOfSOSVariableSelectionWeights());	
//		System.out.println(osolReader.getNumberOfOtherVariableOptions());

//		double[] mdInitValues = osolReader.getInitVarValuesDense();
//		for(int i=0; i < osolReader.getNumberOfVariables(); i++)
//		System.out.println(mdInitValues==null?"NULL":mdInitValues[i]+"");		

//		InitVarValue[] mdVar = osolReader.getInitVarValuesSparse();
//		for(int i=0; i < osolReader.getNumberOfInitVarValues(); i++)
//		System.out.println(mdVar[i].idx+": " + mdVar[i].value);		


//		String[] msInitValues = osolReader.getInitVarStringsDense();
//		for(int i=0; i < osolReader.getNumberOfVariables(); i++)
//		System.out.println(msInitValues==null?"NULL":msInitValues[i]+"");		

//		InitVarValueString[] msVar = osolReader.getInitVarStringsSparse();
//		for(int i=0; i < osolReader.getNumberOfInitVarValues(); i++)
//		System.out.println(msVar[i].idx+": " + msVar[i].value);		

//		String[] msInitValues = osolReader.getInitialBasisStatusDense();
//		for(int i=0; i < osolReader.getNumberOfVariables(); i++)
//		System.out.println(msInitValues==null?"NULL":msInitValues[i]+"");		

//		InitBasStatus[] msVar = osolReader.getInitialBasisStatusSparse();
//		for(int i=0; i < osolReader.getNumberOfInitVarValues(); i++)
//		System.out.println(msVar[i].idx+": " + msVar[i].value);		

//		System.out.println(osolReader.getNumberOfOtherObjectiveOptions());	
//		System.out.println(osolReader.getNumberOfInitObjValues());	
//		System.out.println(osolReader.getNumberOfInitObjBounds());			

//		double[] mdInitValues = osolReader.getInitObjValuesDense();
//		for(int i=0; i < osolReader.getNumberOfObjectives(); i++)
//		System.out.println(mdInitValues==null?"NULL":mdInitValues[i]+"");		

//		System.out.println();
//		InitObjValue[] mdObj = osolReader.getInitObjValuesSparse();
//		for(int i=0; i < osolReader.getNumberOfInitObjValues(); i++)
//		System.out.println(mdObj[i].idx+": " + mdObj[i].value);		


//		double[] mdInitLBBounds = osolReader.getInitObjLowerBoundsDense();
//		for(int i=0; i < osolReader.getNumberOfObjectives(); i++)
//		System.out.println(mdInitLBBounds==null?"NULL":mdInitLBBounds[i]+"");		
//
//		double[] mdInitUBBounds = osolReader.getInitObjUpperBoundsDense();
//		for(int i=0; i < osolReader.getNumberOfObjectives(); i++)
//		System.out.println(mdInitUBBounds==null?"NULL":mdInitUBBounds[i]+"");		
//
//		System.out.println();
//		InitObjBound[] mdObj = osolReader.getInitObjBoundsSparse();
//		for(int i=0; i < osolReader.getNumberOfInitObjBounds(); i++)
//		System.out.println(mdObj[i].idx+": " + mdObj[i].lbValue+": " + mdObj[i].ubValue);				
		
		
		
//		System.out.println(osolReader.getNumberOfOtherConstraintOptions());	
//		System.out.println(osolReader.getNumberOfInitConValues());	
//		System.out.println(osolReader.getNumberOfInitDualVarValues());	
//		double[] mdInitLBBounds = osolReader.getInitDualVarLowerBoundsDense();
//		for(int i=0; i < osolReader.getNumberOfConstraints(); i++)
//		System.out.println(mdInitLBBounds==null?"NULL":mdInitLBBounds[i]+"");		
//
//		double[] mdInitUBBounds = osolReader.getInitDualVarUpperBoundsDense();
//		for(int i=0; i < osolReader.getNumberOfConstraints(); i++)
//		System.out.println(mdInitUBBounds==null?"NULL":mdInitUBBounds[i]+"");		
//
//		InitDualVarValue[] mdCon = osolReader.getInitDualVarValuesSparse();
//		for(int i=0; i < osolReader.getNumberOfInitDualVarValues(); i++)
//		System.out.println(mdCon[i].idx+": " + mdCon[i].lbValue+": " + mdCon[i].ubValue);				
		
//		System.out.println(osolReader.getNumberOfSolverOptions());	
//		SolverOption[] mSolverOptions = osolReader.getSolverOptions("solver2");
//		int nSolverOptions = mSolverOptions==null?0:mSolverOptions.length;
//		for(int i=0; i < nSolverOptions; i++)
//		System.out.println(mSolverOptions[i].name+": "+mSolverOptions[i].value+": "+mSolverOptions[i].solver+": "+mSolverOptions[i].type+": "+mSolverOptions[i].category+": "+mSolverOptions[i].description+": "+mSolverOptions[i].value);				

//		osolReader.writeToStandardOutput();
	}//main

}//class OSoLReader
