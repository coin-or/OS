/**
 * @(#)OSoLWriter 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.representationparser;

import java.util.GregorianCalendar;
import java.util.Vector;

import org.optimizationservices.oscommon.datastructure.osoption.BranchingWeight;
import org.optimizationservices.oscommon.datastructure.osoption.InitBasStatus;
import org.optimizationservices.oscommon.datastructure.osoption.InitConValue;
import org.optimizationservices.oscommon.datastructure.osoption.InitDualVarValue;
import org.optimizationservices.oscommon.datastructure.osoption.InitObjBound;
import org.optimizationservices.oscommon.datastructure.osoption.InitObjValue;
import org.optimizationservices.oscommon.datastructure.osoption.InitVarValue;
import org.optimizationservices.oscommon.datastructure.osoption.InitVarValueString;
import org.optimizationservices.oscommon.datastructure.osoption.OtherConOption;
import org.optimizationservices.oscommon.datastructure.osoption.OtherObjOption;
import org.optimizationservices.oscommon.datastructure.osoption.OtherOption;
import org.optimizationservices.oscommon.datastructure.osoption.OtherVarOption;
import org.optimizationservices.oscommon.datastructure.osoption.PathPair;
import org.optimizationservices.oscommon.localinterface.OSOption;
import org.optimizationservices.oscommon.util.CommonUtil;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.XMLUtil;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.ProcessingInstruction;

/**
 * The <code>OSoLWriter</code> class is used to construct an instance that follows 
 * the OSoL format. 
 * </p>
 *
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */
public class OSoLWriter extends OSgLWriter{

	/**
	 * m_eOSoL holds the OSoL root element.
	 */
	protected Element m_eOSoL = null;

	/**
	 * constructor.
	 *
	 */
	public OSoLWriter(){
		m_document = XMLUtil.createNewDocument();
		if(OSParameter.XSLT_LOCATION != null && OSParameter.XSLT_LOCATION.length() > 0){
			ProcessingInstruction xsltPI = m_document.createProcessingInstruction("xml-stylesheet",
					"type=\"text/xsl\" href = \"" + OSParameter.XSLT_LOCATION + "OSoL.xslt\"");
			m_document.appendChild(xsltPI);     
		}
		m_eOSoL = XMLUtil.createOSxLRootElement(m_document, "osol");
		m_document.appendChild(m_eOSoL);
	}//constructor


	/**
	 * set the OSOption, a standard os option interface. 
	 * @param osOption holds the standard os option interface. 
	 * @return whether the OSOption is set successfully. 
	 */
	public boolean setOSOption(OSOption osOption) throws Exception{
		if(!setServiceURI(osOption.getServiceURI()))throw new Exception("setServiceURI Unsuccessful");
		if(!setServiceName(osOption.getServiceName())) throw new Exception("setServiceName Unsuccessful");		
		if(!setInstanceName(osOption.getInstanceName())) throw new Exception("setInstanceName Unsuccessful");		
		if(!setContactTransportType(osOption.getContactTransportType())) throw new Exception("setContactTransportType Unsuccessful");		
		if(!setInstanceLocation(osOption.getInstanceAddress())) throw new Exception("setInstanceAddress Unsuccessful");		
		if(!setInstanceLocationType(osOption.getInstanceLocationType())) throw new Exception("setInstanceLocationType Unsuccessful");		
		if(!setContact(osOption.getContactAddress())) throw new Exception("setContactAddress Unsuccessful");		
		if(!setJobID(osOption.getJobID())) throw new Exception("setJobID Unsuccessful");		
		if(!setSolverToInvoke(osOption.getSolverToInvoke())) throw new Exception("setSolverToInvoke Unsuccessful");		
		if(!setLicense(osOption.getLicense())) throw new Exception("setLicense Unsuccessful");		
		if(!setUserName(osOption.getUserName())) throw new Exception("setUserName Unsuccessful");		
		if(!setPassword(osOption.getPassword())) throw new Exception("setPassword Unsuccessful");		
		if(!setContactTransportType(osOption.getContactTransportType())) throw new Exception("setContactTransportType Unsuccessful");		
		if(!setContact(osOption.getContactAddress())) throw new Exception("setContactAddress Unsuccessful");		
		if(!setMinDiskSpace(osOption.getSystemMinDiskSpace())) throw new Exception("setSystemMinDiskSpace Unsuccessful");		
		if(!setMinMemorySize(osOption.getSystemMinMemorySize())) throw new Exception("setSystemMinMemorySize Unsuccessful");		
		if(!setMinCPUSpeed(osOption.getSystemMinCPUSpeed())) throw new Exception("setSystemMinCPUSpeed Unsuccessful");		
		if(!setServiceType(osOption.getServiceType())) throw new Exception("setServiceType Unsuccessful");		
		if(!setMaxTime(osOption.getJobMaxTime())) throw new Exception("setJobMaxTime Unsuccessful");		
		if(!setScheduledStartTime(osOption.getJobScheduledStartTime())) throw new Exception("setJobScheduledStartTime Unsuccessful");		
		if(!setJobDependencies(osOption.getJobDependencies())) throw new Exception("setJobDependencies Unsuccessful");		
		if(!setRequiredDirectories(osOption.getRequiredDirectories())) throw new Exception("setRequiredDirectories Unsuccessful");		
		if(!setRequiredFiles(osOption.getRequiredFiles())) throw new Exception("setRequiredFiles Unsuccessful");		
		if(!setDirectoriesToMake(osOption.getDirectoriesToMake())) throw new Exception("setDirectoriesToMake Unsuccessful");		
		if(!setFilesToMake(osOption.getFilesToMake())) throw new Exception("setFilesToMake Unsuccessful");		
		if(!setInputDirectoriesToMove(osOption.getInputFilesToMove())) throw new Exception("setInputFilesToMove Unsuccessful");		
		if(!setInputFilesToMove(osOption.getInputFilesToMove())) throw new Exception("setInputFilesToMove Unsuccessful");		
		if(!setOutputDirectoriesToMove(osOption.getInputFilesToMove())) throw new Exception("setOutputDirectoriesToMove Unsuccessful");		
		if(!setOutputFilesToMove(osOption.getInputFilesToMove())) throw new Exception("setOutputFilesToMove Unsuccessful");		
		if(!setFilesToDelete(osOption.getFilesToDelete())) throw new Exception("setFilesToDelete Unsuccessful");		
		if(!setDirectoriesToDelete(osOption.getDirectoriesToDelete())) throw new Exception("setDirectoriesToDelete Unsuccessful");		
		if(!setProcessesToKill(osOption.getProcessesToKill())) throw new Exception("setProcessesToKill Unsuccessful");		

		if(!setNumberOfVariables(osOption.getNumberOfVariables())) throw new Exception("setNumberOfVariables Unsuccessful");		
		if(!setNumberOfObjectives(osOption.getNumberOfObjectives())) throw new Exception("setNumberOfObjectives Unsuccessful");		
		if(!setNumberOfConstraints(osOption.getNumberOfConstraints())) throw new Exception("setNumberOfConstraints Unsuccessful");		
		if(!setInitVarValuesDense(osOption.getInitialVariableValues())) throw new Exception("setInitialVariableValues Unsuccessful");		
		if(osOption.optimization != null && osOption.optimization.solverOptions != null && osOption.optimization.solverOptions != null && osOption.optimization.solverOptions.solverOption.length > 0){
			int n = osOption.optimization.solverOptions.solverOption.length;
			String[] msNames = new String[n];
			String[] msValues = new String[n];
			String[] msDescriptions = new String[n];
			String[] msSolvers = new String[n];
			String[] msCategories = new String[n];
			String[] msTypes = new String[n];
			for(int i = 0; i < n; i++){
				msNames[i] = osOption.optimization.solverOptions.solverOption[i].name;
				msValues[i] = osOption.optimization.solverOptions.solverOption[i].value;
				msDescriptions[i] = osOption.optimization.solverOptions.solverOption[i].description;
				msSolvers[i] = osOption.optimization.solverOptions.solverOption[i].solver;
				msCategories[i] = osOption.optimization.solverOptions.solverOption[i].category;
				msTypes[i] = osOption.optimization.solverOptions.solverOption[i].type;
			}
			if(!setSolverOptions(msNames, msValues, msDescriptions, msSolvers, msCategories, msTypes)){
				throw new Exception("setOtherOptimizationOption Info Unsuccessful");
			}			
		}
		return true;
	}//setOSOption

	public boolean setOptionStr(String optionName, String optionValue){
		if (optionName.equalsIgnoreCase("serviceURI")){ 
			return this.setServiceURI(optionValue);
		}
		if (optionName.equalsIgnoreCase("serviceName") ){
			return this.setServiceName(optionValue);
		}
		if (optionName.equalsIgnoreCase("instanceName") ){
			return this.setInstanceName(optionValue);
		}
		if (optionName.equalsIgnoreCase("instanceLocation") ){
			return this.setInstanceLocation(optionValue);
		}
		if (optionName.equalsIgnoreCase("locationType") ){
			return this.setInstanceLocationType(optionValue);
		}
		if (optionName.equalsIgnoreCase("jobID") ){
			return this.setJobID(optionValue);
		}
		if (optionName.equalsIgnoreCase("solverName") ){
			return this.setSolverToInvoke(optionValue);
		}
		if (optionName.equalsIgnoreCase("solverToInvoke") ){
			return this.setSolverToInvoke(optionValue);
		}
		if (optionName.equalsIgnoreCase("license") ){
			return this.setLicense(optionValue);
		}
		if (optionName.equalsIgnoreCase("userName") ){
			return this.setUserName(optionValue);
		}
		if (optionName.equalsIgnoreCase("password") ){
			return this.setPassword(optionValue);
		}
		if (optionName.equalsIgnoreCase("contact") ){
			return this.setContact(optionValue);
		}
		if (optionName.equalsIgnoreCase("transportType") ){
			return this.setContactTransportType(optionValue);
		}
		if (optionName.equalsIgnoreCase("minDiskSpaceUnit") ){
			return this.setMinDiskSpaceUnit(optionValue);
		}
		if (optionName.equalsIgnoreCase("minMemoryUnit") ){
			return this.setMinMemorySizeUnit(optionValue);
		}
		if (optionName.equalsIgnoreCase("minCPUSpeedUnit") ){
			return this.setMinCPUSpeedUnit(optionValue);
		}
		if (optionName.equalsIgnoreCase("serviceType") ){
			return this.setServiceType(optionValue);
		}
		if (optionName.equalsIgnoreCase("maxTimeUnit") ){
			return this.setMaxTimeUnit(optionValue);
		}
		if (optionName.equalsIgnoreCase("scheduledStartTime") ){
			return this.setScheduledStartTime(XMLUtil.createNativeDateTime(optionValue));
		}
		return false;
	}//setOptionStr

	public boolean setOptionDbl(String optionName, double optionValue){
		if (optionName.equalsIgnoreCase("minDiskSpace")){ 
			return this.setMinDiskSpace(optionValue);
		}
		if (optionName.equalsIgnoreCase("minMemory")){ 
			return this.setMinMemorySize(optionValue);
		}
		if (optionName.equalsIgnoreCase("minCPUSpeed")){ 
			return this.setMinCPUSpeed(optionValue);
		}
		if (optionName.equalsIgnoreCase("maxTime")){ 
			return this.setMaxTime(optionValue);
		}
		return false;
	}//setOptionDbl

	public boolean setOptionInt(String optionName, int optionValue){
		if (optionName.equalsIgnoreCase("minCPUNumber")){
			return this.setMinCPUNumber(optionValue);
		}
		return false;
	}//setOptionInt

	/**
	 * Set service uri.
	 * 
	 * @param serviceURI holds the uri of the service. 
	 * @return whether the service uri is set successfully. 
	 */
	public boolean setServiceURI(String serviceURI){
		try{
			Element eGeneral = (Element)XMLUtil.findChildNode(m_eOSoL, "general");
			if(eGeneral == null){
				eGeneral = m_document.createElement("general");
				m_eOSoL.insertBefore(eGeneral, m_eOSoL.getFirstChild());
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
			Element eGeneral = (Element)XMLUtil.findChildNode(m_eOSoL, "general");
			if(eGeneral == null){
				eGeneral = m_document.createElement("general");
				m_eOSoL.insertBefore(eGeneral, m_eOSoL.getFirstChild());
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
			Element eGeneral = (Element)XMLUtil.findChildNode(m_eOSoL, "general");
			if(eGeneral == null){
				eGeneral = m_document.createElement("general");
				m_eOSoL.insertBefore(eGeneral, m_eOSoL.getFirstChild());
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
	 * Set the instance address to get the instance. 
	 * 
	 * @param instanceLocation holds the instance address. 
	 * @return whether the instance address is set successfully.
	 */
	public boolean setInstanceLocation(String instanceLocation){
		try{
			Element eGeneral = (Element)XMLUtil.findChildNode(m_eOSoL, "general");
			if(eGeneral == null){
				eGeneral = m_document.createElement("general");
				m_eOSoL.insertBefore(eGeneral, m_eOSoL.getFirstChild());
			}
			Element eInstanceLocation = (Element)XMLUtil.findChildNode(eGeneral, "instanceLocation");
			if(instanceLocation == null || instanceLocation.length() <= 0){
				if(eInstanceLocation == null){
					return true;
				}
				else{
					XMLUtil.removeAllChildren(eInstanceLocation);
					return true;
				}
			}
			if(eInstanceLocation == null){
				eInstanceLocation = m_document.createElement("instanceLocation");	
				eInstanceLocation.appendChild(m_document.createTextNode(instanceLocation));
				eGeneral.appendChild(eInstanceLocation);				
			}
			else{
				XMLUtil.setElementValue(eInstanceLocation, instanceLocation);
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setInstanceLocation

	/**
	 * Set the instance location type to get the instance. 
	 * 
	 * @param locationType holds the instance location type, e.g. local, http, ftp.
	 * @return whether the instance location type is set successfully.
	 */
	public boolean setInstanceLocationType(String locationType){
		try{
			Element eGeneral = (Element)XMLUtil.findChildNode(m_eOSoL, "general");
			if(eGeneral == null){
				eGeneral = m_document.createElement("general");
				m_eOSoL.insertBefore(eGeneral, m_eOSoL.getFirstChild());
			}
			Element eInstanceLocation = (Element)XMLUtil.findChildNode(eGeneral, "instanceLocation");
			if(locationType == null || locationType.length() <= 0){
				if(eInstanceLocation == null){
					return true;
				}
				else{
					eInstanceLocation.removeAttribute("locationType");
					return true;
				}
			}
			if(eInstanceLocation == null){
				eInstanceLocation = m_document.createElement("instanceLocation");	
				eInstanceLocation.setAttribute("locationType", locationType);
				eGeneral.appendChild(eInstanceLocation);
			}
			else{
				eInstanceLocation.setAttribute("locationType", locationType);
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setInstanceLocationType

	/**
	 * Set jobID.
	 * 
	 * @param jobID holds the jobID.
	 * @return whether the jobID is set successfully.
	 */
	public boolean setJobID(String jobID){
		try{
			Element eGeneral = (Element)XMLUtil.findChildNode(m_eOSoL, "general");
			if(eGeneral == null){
				eGeneral = m_document.createElement("general");
				m_eOSoL.insertBefore(eGeneral, m_eOSoL.getFirstChild());
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
	 * Set solverToInvoke.
	 * 
	 * @param solverToInvoke holds the solver to invoke.
	 * @return whether the solverToInvoke is set successfully.
	 */
	public boolean setSolverToInvoke(String solverToInvoke){
		try{
			Element eGeneral = (Element)XMLUtil.findChildNode(m_eOSoL, "general");
			if(eGeneral == null){
				eGeneral = m_document.createElement("general");
				m_eOSoL.insertBefore(eGeneral, m_eOSoL.getFirstChild());
			}
			if(solverToInvoke != null && solverToInvoke.length() > 0){
				Element eSolverToInvoke = (Element)XMLUtil.findChildNode(eGeneral, "solverToInvoke");
				if(eSolverToInvoke == null){
					eSolverToInvoke = m_document.createElement("solverToInvoke");	
					eSolverToInvoke.appendChild(m_document.createTextNode(solverToInvoke));
					eGeneral.appendChild(eSolverToInvoke);				
				}
				else{
					XMLUtil.setElementValue(eSolverToInvoke, solverToInvoke);
				}
			}
			else{
				XMLUtil.removeChildrenByName(eGeneral, "solverToInvoke");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setSolverToInvoke

	/**
	 * Set license.
	 * 
	 * @param license holds the license required by the service.
	 * @return whether the license is set successfully.
	 */
	public boolean setLicense(String license){
		try{
			Element eGeneral = (Element)XMLUtil.findChildNode(m_eOSoL, "general");
			if(eGeneral == null){
				eGeneral = m_document.createElement("general");
				m_eOSoL.insertBefore(eGeneral, m_eOSoL.getFirstChild());
			}
			if(license != null && license.length() > 0){
				Element eLicense = (Element)XMLUtil.findChildNode(eGeneral, "license");
				if(eLicense == null){
					eLicense = m_document.createElement("license");	
					eLicense.appendChild(m_document.createTextNode(license));
					eGeneral.appendChild(eLicense);				
				}
				else{
					XMLUtil.setElementValue(eLicense, license);
				}
			}
			else{
				XMLUtil.removeChildrenByName(eGeneral, "license");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setLicense

	/**
	 * Set the user name.
	 * 
	 * @param userName holds the user name required by the service.
	 * @return whether the user name is set successfully.
	 */
	public boolean setUserName(String userName){
		try{
			Element eGeneral = (Element)XMLUtil.findChildNode(m_eOSoL, "general");
			if(eGeneral == null){
				eGeneral = m_document.createElement("general");
				m_eOSoL.insertBefore(eGeneral, m_eOSoL.getFirstChild());
			}
			if(userName != null && userName.length() > 0){
				Element eUserName = (Element)XMLUtil.findChildNode(eGeneral, "userName");
				if(eUserName == null){
					eUserName = m_document.createElement("userName");	
					eUserName.appendChild(m_document.createTextNode(userName));
					eGeneral.appendChild(eUserName);				
				}
				else{
					XMLUtil.setElementValue(eUserName, userName);
				}
			}
			else{
				XMLUtil.removeChildrenByName(eGeneral, "userName");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setUserName

	/**
	 * Set the password.
	 * 
	 * @param password holds the password required by the service.
	 * @return whether the password is set successfully.
	 */
	public boolean setPassword(String password){
		try{
			Element eGeneral = (Element)XMLUtil.findChildNode(m_eOSoL, "general");
			if(eGeneral == null){
				eGeneral = m_document.createElement("general");
				m_eOSoL.insertBefore(eGeneral, m_eOSoL.getFirstChild());
			}
			if(password != null && password.length() > 0){
				Element ePassword = (Element)XMLUtil.findChildNode(eGeneral, "password");
				if(ePassword == null){
					ePassword = m_document.createElement("password");	
					ePassword.appendChild(m_document.createTextNode(password));
					eGeneral.appendChild(ePassword);				
				}
				else{
					XMLUtil.setElementValue(ePassword, password);
				}
			}
			else{
				XMLUtil.removeChildrenByName(eGeneral, "password");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setPassword

	/**
	 * Set the contact address to respond to the requester. 
	 * For example it can be an email address if the contact transport type is smtp
	 * or a http uri if the contact transport type is osp (for knocking back on the requester), etc.
	 * 
	 * @param address holds the contact address. 
	 * @return whether the contact address is set successfully.
	 */
	public boolean setContact(String address){
		try{
			Element eGeneral = (Element)XMLUtil.findChildNode(m_eOSoL, "general");
			if(eGeneral == null){
				eGeneral = m_document.createElement("general");
				m_eOSoL.insertBefore(eGeneral, m_eOSoL.getFirstChild());
			}
			Element eContact = (Element)XMLUtil.findChildNode(eGeneral, "contact");
			if(address == null || address.length() <= 0){
				if(eContact == null){
					return true;
				}
				else{
					XMLUtil.removeAllChildren(eContact);
					return true;
				}
			}
			if(eContact == null){
				eContact = m_document.createElement("contact");	
				eContact.appendChild(m_document.createTextNode(address));
				eGeneral.appendChild(eContact);				
			}
			else{
				XMLUtil.setElementValue(eContact, address);
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setContact

	/**
	 * Set the contact transport type to respond to the requester,
	 * smtp (for email), osp (for knocking back on the requester), etc.
	 * 
	 * @param transportType holds the contact transport type. 
	 * @return whether the contact transport type is set successfully.
	 */
	public boolean setContactTransportType(String transportType){
		try{
			Element eGeneral = (Element)XMLUtil.findChildNode(m_eOSoL, "general");
			if(eGeneral == null){
				eGeneral = m_document.createElement("general");
				m_eOSoL.insertBefore(eGeneral, m_eOSoL.getFirstChild());
			}
			Element eContact = (Element)XMLUtil.findChildNode(eGeneral, "contact");
			if(transportType == null || transportType.length() <= 0){
				if(eContact == null){
					return true;
				}
				else{
					eContact.removeAttribute("transportType");
					return true;
				}
			}
			if(eContact == null){
				eContact = m_document.createElement("contact");	
				eContact.setAttribute("transportType", transportType);
				eGeneral.appendChild(eContact);				
			}
			else{
				eContact.setAttribute("transportType", transportType);
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setContactTransportType

	/**
	 * Set the number of other general options. 
	 * 
	 * @param numberOfOtherGeneralOptions holds the number of other general options
	 * @return whether the number is set successfully or not. 
	 */
	public boolean setNumberOfOtherGeneralOptions(int numberOfOtherGeneralOptions){
		if(numberOfOtherGeneralOptions < 0){
			return true;
		}
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eOSoL, "general");
		if(eGeneral == null){
			eGeneral = m_document.createElement("general");
			m_eOSoL.insertBefore(eGeneral, m_eOSoL.getFirstChild());
		}
		Element eOtherOptions = (Element)XMLUtil.findChildNode(eGeneral, "otherOptions");
		if(eOtherOptions == null){
			eOtherOptions = m_document.createElement("otherOptions");	
			eGeneral.appendChild(eOtherOptions);				
		}
		try{
			eOtherOptions.setAttribute("numberOfOtherOptions", numberOfOtherGeneralOptions+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;	
	}//setNumberOfOtherGeneralOptions

	/**
	 * Set the other general options. 
	 * 
	 * @param names holds the names of the other options. It is required. 
	 * @param values holds the values of the other options, empty string "" or null if no value for an option.
	 * @param descriptions holds the descriptions of the other options, empty string "" or null if no value for an option, null for
	 * the entire array if none of the options have descriptions.
	 * @return whether the other options element construction is successful.
	 */
	public boolean setOtherGeneralOptions(String[] names, String[] values, String[] descriptions){
		if(names == null) return false;
		if(values == null) return false;
		if(names.length != values.length) return false;
		if(descriptions != null && names.length != descriptions.length) return false;
		for(int i = 0; i < names.length; i++){
			addOtherGeneralOption(names[i], values[i], (descriptions==null)?"":descriptions[i]);
		}
		return true;
	}//setOtherGeneralOptions

	/**
	 * Add an other general option element. 
	 * 
	 * @param name holds the name of the other option element. It is required.
	 * @param value holds the value of the other option element, empty string "" or null if none. 
	 * @param description holds the description of the other option element, empty string "" or null if none. 
	 * @return whether the other option element is added successfully.
	 */
	public boolean addOtherGeneralOption(String name, String value, String description){
		if(name == null || name.trim().length() <= 0) return false;
		try{
			Element eGeneral = (Element)XMLUtil.findChildNode(m_eOSoL, "general");
			if(eGeneral == null){
				eGeneral = m_document.createElement("general");
				m_eOSoL.insertBefore(eGeneral, m_eOSoL.getFirstChild());
			}
			Element eOtherOptions = (Element)XMLUtil.findChildNode(eGeneral, "otherOptions");
			if(eOtherOptions == null){
				eOtherOptions = m_document.createElement("otherOptions");	
				eGeneral.appendChild(eOtherOptions);				
			}
			try{
				Vector<Element> vElements = XMLUtil.getChildElementsByTagName(eOtherOptions, "other");
				Element eOther;
				int iNls = vElements==null?0:vElements.size();
				for(int i = 0; i < iNls; i++){
					eOther = (Element)vElements.elementAt(i);
					if(eOther.getAttribute("name").equals(name)){
						eOtherOptions.removeChild(eOther);
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
				eOtherOptions.appendChild(eOther);

				eOtherOptions.setAttribute("numberOfOtherOptions", (iNls+1)+"");

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
	}//addOtherGeneralOption

	/**
	 * Set the the system minimum disk space required to solve the job.
	 * 
	 * @param minDiskSpace holds the  minimum disk space required to solve the job. 
	 * @return whether the minimum disk space is set successfully.
	 */
	public boolean setMinDiskSpace(double minDiskSpace){
		Node nodeRef = null;
		try{
			Element eSystem = (Element)XMLUtil.findChildNode(m_eOSoL, "system");
			if(eSystem == null){
				eSystem = m_document.createElement("system");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eSystem, nodeRef.getNextSibling());			
				}
				else{
					m_eOSoL.insertBefore(eSystem, m_eOSoL.getFirstChild());
				}		
			}
			if(minDiskSpace >= 0){
				Element eMinDiskSpace = (Element)XMLUtil.findChildNode(eSystem, "minDiskSpace");
				if(eMinDiskSpace == null){
					eMinDiskSpace = m_document.createElement("minDiskSpace");	
					eMinDiskSpace.appendChild(m_document.createTextNode(minDiskSpace+""));
					eSystem.appendChild(eMinDiskSpace);				
				}
				else{
					XMLUtil.setElementValue(eMinDiskSpace, minDiskSpace+"");
				}
			}
			else{
				XMLUtil.removeChildrenByName(eSystem, "minDiskSpace");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setMinDiskSpace

	/**
	 * Set the unit of the system minimum disk space required to solve the job.
	 * 
	 * @param unit holds the unit of the disk space.
	 * @return whether the unit of the minimum disk space is set successfully.
	 */
	public boolean setMinDiskSpaceUnit(String unit){
		Node nodeRef = null;
		if(unit == null || unit.length() <=0 || unit.equalsIgnoreCase("byte")){
			return true;
		}
		try{
			Element eSystem = (Element)XMLUtil.findChildNode(m_eOSoL, "system");
			if(eSystem == null){
				eSystem = m_document.createElement("system");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eSystem, nodeRef.getNextSibling());			
				}
				else{
					m_eOSoL.insertBefore(eSystem, m_eOSoL.getFirstChild());
				}		
			}
			Element eMinDiskSpace = (Element)XMLUtil.findChildNode(eSystem, "minDiskSpace");
			if(eMinDiskSpace == null){
				eMinDiskSpace = m_document.createElement("minDiskSpace");	
				eSystem.appendChild(eMinDiskSpace);				
			}
			eMinDiskSpace.setAttribute("unit", unit);
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setMinDiskSpaceUnit

	/**
	 * Set the the system minimum memory size required to solve the job.
	 * 
	 * @param minMemorySize holds the  minimum memory size required to solve the job. 
	 * @return whether the minimum memory size is set successfully.
	 */
	public boolean setMinMemorySize(double minMemorySize){
		Node nodeRef = null;
		try{
			Element eSystem = (Element)XMLUtil.findChildNode(m_eOSoL, "system");
			if(eSystem == null){
				eSystem = m_document.createElement("system");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eSystem, nodeRef.getNextSibling());			
				}
				else{
					m_eOSoL.insertBefore(eSystem, m_eOSoL.getFirstChild());
				}		
			}
			if(minMemorySize >= 0){
				Element eMinMemorySize = (Element)XMLUtil.findChildNode(eSystem, "minMemorySize");
				if(eMinMemorySize == null){
					eMinMemorySize = m_document.createElement("minMemorySize");	
					eMinMemorySize.appendChild(m_document.createTextNode(minMemorySize+""));
					eSystem.appendChild(eMinMemorySize);				
				}
				else{
					XMLUtil.setElementValue(eMinMemorySize, minMemorySize+"");
				}
			}
			else{
				XMLUtil.removeChildrenByName(eSystem, "minMemorySize");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setMinMemorySize

	/**
	 * Set the unit of the system minimum memory size required to solve the job.
	 * 
	 * @param unit holds the unit of the memory size.
	 * @return whether the unit of the minimum memory size is set successfully.
	 */
	public boolean setMinMemorySizeUnit(String unit){
		Node nodeRef = null;
		if(unit == null || unit.length() <=0 || unit.equalsIgnoreCase("byte")){
			return true;
		}
		try{
			Element eSystem = (Element)XMLUtil.findChildNode(m_eOSoL, "system");
			if(eSystem == null){
				eSystem = m_document.createElement("system");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eSystem, nodeRef.getNextSibling());			
				}
				else{
					m_eOSoL.insertBefore(eSystem, m_eOSoL.getFirstChild());
				}		
			}
			Element eMinMemorySize = (Element)XMLUtil.findChildNode(eSystem, "minMemorySize");
			if(eMinMemorySize == null){
				eMinMemorySize = m_document.createElement("minMemorySize");	
				eSystem.appendChild(eMinMemorySize);				
			}
			eMinMemorySize.setAttribute("unit", unit);
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setMinMemorySizeUnit

	/**
	 * Set the the system minimum cpu speed required to solve the job.
	 * 
	 * @param minCPUSpeed holds the  minimum cpu speed required to solve the job. 
	 * @return whether the minimum cpu speed is set successfully.
	 */
	public boolean setMinCPUSpeed(double minCPUSpeed){
		Node nodeRef = null;
		try{
			Element eSystem = (Element)XMLUtil.findChildNode(m_eOSoL, "system");
			if(eSystem == null){
				eSystem = m_document.createElement("system");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eSystem, nodeRef.getNextSibling());			
				}
				else{
					m_eOSoL.insertBefore(eSystem, m_eOSoL.getFirstChild());
				}		
			}
			if(minCPUSpeed >= 0){
				Element eMinCPUSpeed = (Element)XMLUtil.findChildNode(eSystem, "minCPUSpeed");
				if(eMinCPUSpeed == null){
					eMinCPUSpeed = m_document.createElement("minCPUSpeed");	
					eMinCPUSpeed.appendChild(m_document.createTextNode(minCPUSpeed+""));
					eSystem.appendChild(eMinCPUSpeed);				
				}
				else{
					XMLUtil.setElementValue(eMinCPUSpeed, minCPUSpeed+"");
				}
			}
			else{
				XMLUtil.removeChildrenByName(eSystem, "minCPUSpeed");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setMinCPUSpeed

	/**
	 * Set the unit of the system cpu speed required to solve the job.
	 * 
	 * @param unit holds the unit of the cpu speed.
	 * @return whether the unit of the minimum cpu speed is set successfully.
	 */
	public boolean setMinCPUSpeedUnit(String unit){
		Node nodeRef = null;
		if(unit == null || unit.length() <=0 || unit.equalsIgnoreCase("hertz")){
			return true;
		}
		try{
			Element eSystem = (Element)XMLUtil.findChildNode(m_eOSoL, "system");
			if(eSystem == null){
				eSystem = m_document.createElement("system");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eSystem, nodeRef.getNextSibling());			
				}
				else{
					m_eOSoL.insertBefore(eSystem, m_eOSoL.getFirstChild());
				}		
			}
			Element eMinCPUSpeed = (Element)XMLUtil.findChildNode(eSystem, "minCPUSpeed");
			if(eMinCPUSpeed == null){
				eMinCPUSpeed = m_document.createElement("minCPUSpeed");	
				eSystem.appendChild(eMinCPUSpeed);				
			}
			eMinCPUSpeed.setAttribute("unit", unit);
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setMinCPUSpeedUnit

	/**
	 * Set the the system minimum cpu number required to solve the job.
	 * 
	 * @param minCPUNumber holds the  minimum cpu number required to solve the job. 
	 * @return whether the minimum cpu number is set successfully.
	 */
	public boolean setMinCPUNumber(int minCPUNumber){
		Node nodeRef = null;
		try{
			Element eSystem = (Element)XMLUtil.findChildNode(m_eOSoL, "system");
			if(eSystem == null){
				eSystem = m_document.createElement("system");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eSystem, nodeRef.getNextSibling());			
				}
				else{
					m_eOSoL.insertBefore(eSystem, m_eOSoL.getFirstChild());
				}		
			}
			if(minCPUNumber >= 0){
				Element eMinCPUNumber = (Element)XMLUtil.findChildNode(eSystem, "minCPUNumber");
				if(eMinCPUNumber == null){
					eMinCPUNumber = m_document.createElement("minCPUNumber");	
					eMinCPUNumber.appendChild(m_document.createTextNode(minCPUNumber+""));
					eSystem.appendChild(eMinCPUNumber);				
				}
				else{
					XMLUtil.setElementValue(eMinCPUNumber, minCPUNumber+"");
				}
			}
			else{
				XMLUtil.removeChildrenByName(eSystem, "minCPUNumber");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setMinCPUNumber

	/**
	 * Set the number of other system options. 
	 * 
	 * @param numberOfOtherSystemOptions holds the number of other system options
	 * @return whether the number is set successfully or not. 
	 */
	public boolean setNumberOfOtherSystemOptions(int numberOfOtherSystemOptions){
		Node nodeRef = null;
		if(numberOfOtherSystemOptions < 0){
			return true;
		}
		Element eSystem = (Element)XMLUtil.findChildNode(m_eOSoL, "system");
		if(eSystem == null){
			eSystem = m_document.createElement("system");
			nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
			if(nodeRef != null){
				m_eOSoL.insertBefore(eSystem, nodeRef.getNextSibling());			
			}
			else{
				m_eOSoL.insertBefore(eSystem, m_eOSoL.getFirstChild());
			}		
		}		
		Element eOtherOptions = (Element)XMLUtil.findChildNode(eSystem, "otherOptions");
		if(eOtherOptions == null){
			eOtherOptions = m_document.createElement("otherOptions");	
			eSystem.appendChild(eOtherOptions);				
		}
		try{
			eOtherOptions.setAttribute("numberOfOtherOptions", numberOfOtherSystemOptions+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;	
	}//setNumberOfOtherSystemOptions

	/**
	 * Set the other system options. 
	 * 
	 * @param names holds the names of the other options. It is required. 
	 * @param values holds the values of the other options, empty string "" or null if no value for an option.
	 * @param descriptions holds the descriptions of the other options, empty string "" or null if no value for an option, null for
	 * the entire array if none of the options have descriptions.
	 * @return whether the other options element construction is successful.
	 */
	public boolean setOtherSystemOptions(String[] names, String[] values, String[] descriptions){
		if(names == null) return false;
		if(values == null) return false;
		if(names.length != values.length) return false;
		if(descriptions != null && names.length != descriptions.length) return false;
		for(int i = 0; i < names.length; i++){
			addOtherSystemOption(names[i], values[i], (descriptions==null)?"":descriptions[i]);
		}
		return true;
	}//setOtherSystemOptions

	/**
	 * Add an other system option element. 
	 * 
	 * @param name holds the name of the other option element. It is required.
	 * @param value holds the value of the other option element, empty string "" or null if none. 
	 * @param description holds the description of the other option element, empty string "" or null if none. 
	 * @return whether the other option element is added successfully.
	 */
	public boolean addOtherSystemOption(String name, String value, String description){
		Node nodeRef = null;
		if(name == null || name.trim().length() <= 0) return false;
		try{
			Element eSystem = (Element)XMLUtil.findChildNode(m_eOSoL, "system");
			if(eSystem == null){
				eSystem = m_document.createElement("system");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eSystem, nodeRef.getNextSibling());			
				}
				else{
					m_eOSoL.insertBefore(eSystem, m_eOSoL.getFirstChild());
				}		
			}		
			Element eOtherOptions = (Element)XMLUtil.findChildNode(eSystem, "otherOptions");
			if(eOtherOptions == null){
				eOtherOptions = m_document.createElement("otherOptions");	
				eSystem.appendChild(eOtherOptions);				
			}
			try{
				Vector<Element> vElements = XMLUtil.getChildElementsByTagName(eOtherOptions, "other");
				Element eOther;
				int iNls = vElements==null?0:vElements.size();
				for(int i = 0; i < iNls; i++){
					eOther = (Element)vElements.elementAt(i);
					if(eOther.getAttribute("name").equals(name)){
						eOtherOptions.removeChild(eOther);
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
				eOtherOptions.appendChild(eOther);

				eOtherOptions.setAttribute("numberOfOtherOptions", (iNls+1)+"");

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
	}//addOtherSystemOption


	/**
	 * Set the service type. 
	 * 
	 * @param type holds the service type, which can be:
	 * solver, analyzer, scheduler, simulation, registry, modeler, agent 
	 * 
	 * @return whether the service type is set successfully or not. 
	 */
	public boolean setServiceType(String type){
		Node nodeRef = null;
		try{
			Element eService = (Element)XMLUtil.findChildNode(m_eOSoL, "service");
			if(eService == null){
				eService = m_document.createElement("service");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eService, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eService, nodeRef.getNextSibling());			
					}
					else{
						m_eOSoL.insertBefore(eService, m_eOSoL.getFirstChild());
					}		
				}		
			}
			if(type != null && type.length() > 0){
				if(!type.equals("solver") && 
						!type.equals("analyzer") &&
						!type.equals("scheduler") &&
						!type.equals("simulation") &&
						!type.equals("registry") &&
						!type.equals("modeler") &&
						!type.equals("agent")) return false;
				Element eType = (Element)XMLUtil.findChildNode(eService, "type");
				if(eType == null){
					eType = m_document.createElement("type");	
					eType.appendChild(m_document.createTextNode(type));
					eService.appendChild(eType);				
				}
				else{
					XMLUtil.setElementValue(eType, type);
				}
			}
			else{
				XMLUtil.removeChildrenByName(eService, "type");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setServiceType

	/**
	 * Set the number of other service options. 
	 * 
	 * @param numberOfOtherServiceOptions holds the number of other service options
	 * @return whether the number is set successfully or not. 
	 */
	public boolean setNumberOfOtherServiceOptions(int numberOfOtherServiceOptions){
		Node nodeRef = null;
		if(numberOfOtherServiceOptions < 0){
			return true;
		}
		Element eService = (Element)XMLUtil.findChildNode(m_eOSoL, "service");
		if(eService == null){
			eService = m_document.createElement("service");
			nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
			if(nodeRef != null){
				m_eOSoL.insertBefore(eService, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eService, nodeRef.getNextSibling());			
				}
				else{
					m_eOSoL.insertBefore(eService, m_eOSoL.getFirstChild());
				}		
			}		
		}		
		Element eOtherOptions = (Element)XMLUtil.findChildNode(eService, "otherOptions");
		if(eOtherOptions == null){
			eOtherOptions = m_document.createElement("otherOptions");	
			eService.appendChild(eOtherOptions);				
		}
		try{
			eOtherOptions.setAttribute("numberOfOtherOptions", numberOfOtherServiceOptions+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;	
	}//setNumberOfOtherServiceOptions

	/**
	 * Set the other service options. 
	 * 
	 * @param names holds the names of the other options. It is required. 
	 * @param values holds the values of the other options, empty string "" or null if no value for an option.
	 * @param descriptions holds the descriptions of the other options, empty string "" or null if no value for an option, null for
	 * the entire array if none of the options have descriptions.
	 * @return whether the other options element construction is successful.
	 */
	public boolean setOtherServiceOptions(String[] names, String[] values, String[] descriptions){
		if(names == null) return false;
		if(values == null) return false;
		if(names.length != values.length) return false;
		if(descriptions != null && names.length != descriptions.length) return false;
		for(int i = 0; i < names.length; i++){
			addOtherServiceOption(names[i], values[i], (descriptions==null)?"":descriptions[i]);
		}
		return true;
	}//setOtherServiceOptions

	/**
	 * Add an other service option element. 
	 * 
	 * @param name holds the name of the other option element. It is required.
	 * @param value holds the value of the other option element, empty string "" or null if none. 
	 * @param description holds the description of the other option element, empty string "" or null if none. 
	 * @return whether the other option element is added successfully.
	 */
	public boolean addOtherServiceOption(String name, String value, String description){
		Node nodeRef = null;
		if(name == null || name.trim().length() <= 0) return false;
		try{
			Element eService = (Element)XMLUtil.findChildNode(m_eOSoL, "service");
			if(eService == null){
				eService = m_document.createElement("service");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eService, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eService, nodeRef.getNextSibling());			
					}
					else{
						m_eOSoL.insertBefore(eService, m_eOSoL.getFirstChild());
					}		
				}		
			}			
			Element eOtherOptions = (Element)XMLUtil.findChildNode(eService, "otherOptions");
			if(eOtherOptions == null){
				eOtherOptions = m_document.createElement("otherOptions");	
				eService.appendChild(eOtherOptions);				
			}
			try{
				Vector<Element> vElements = XMLUtil.getChildElementsByTagName(eOtherOptions, "other");
				Element eOther;
				int iNls = vElements==null?0:vElements.size();
				for(int i = 0; i < iNls; i++){
					eOther = (Element)vElements.elementAt(i);
					if(eOther.getAttribute("name").equals(name)){
						eOtherOptions.removeChild(eOther);
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
				eOtherOptions.appendChild(eOther);

				eOtherOptions.setAttribute("numberOfOtherOptions", (iNls+1)+"");

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
	}//addOtherServiceOption

	/**
	 * Set the maximum time before the job is terminated.  
	 * 
	 * @param maxTime holds the maximum time in seconds. 
	 * @return whether the maximum time is set successfully.
	 */
	public boolean setMaxTime(double maxTime){
		if(maxTime <= 0) return false;
		Node nodeRef = null;
		try{
			Element eJob = (Element)XMLUtil.findChildNode(m_eOSoL, "job");
			if(eJob == null){
				eJob = m_document.createElement("job");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
						}
						else{
							m_eOSoL.insertBefore(eJob, m_eOSoL.getFirstChild());
						}		
					}		
				}
			}
			if(maxTime > 0){
				Element eMaxTime = (Element)XMLUtil.findChildNode(eJob, "maxTime");
				if(eMaxTime == null){
					eMaxTime = m_document.createElement("maxTime");	
					eMaxTime.appendChild(m_document.createTextNode(Double.isInfinite(maxTime)?"INF":maxTime+""));
					eJob.appendChild(eMaxTime);				
				}
				else{
					XMLUtil.setElementValue(eMaxTime, Double.isInfinite(maxTime)?"INF":maxTime+"");
				}
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
	}//setMaxTime

	/**
	 * Set the unit of the maximum time before the job is terminated.  
	 * 
	 * @param maxTime holds the maximum time in seconds. 
	 * @return whether the maximum time is set successfully.
	 */
	public boolean setMaxTimeUnit(String unit){
		Node nodeRef = null;
		if(unit == null || unit.length() <=0 || unit.equalsIgnoreCase("second")){
			return true;
		}
		try{
			Element eJob = (Element)XMLUtil.findChildNode(m_eOSoL, "job");
			if(eJob == null){
				eJob = m_document.createElement("job");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
						}
						else{
							m_eOSoL.insertBefore(eJob, m_eOSoL.getFirstChild());
						}		
					}		
				}
			}
			Element eMaxTime = (Element)XMLUtil.findChildNode(eJob, "maxTime");
			if(eMaxTime == null){
				eMaxTime = m_document.createElement("maxTime");	
				eJob.appendChild(eMaxTime);				
			}
			eMaxTime.setAttribute("unit", unit);

		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setMaxTimeUnit

	/**
	 * Set the scheduled start time for the job.   
	 * 
	 * @param scheduledStartTime holds the scheduled start time for the job.   
	 * @return whether the scheduled start time is set successfully.
	 */
	public boolean setScheduledStartTime(GregorianCalendar scheduledStartTime){
		Node nodeRef = null;
		try{
			Element eJob = (Element)XMLUtil.findChildNode(m_eOSoL, "job");
			if(eJob == null){
				eJob = m_document.createElement("job");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
						}
						else{
							m_eOSoL.insertBefore(eJob, m_eOSoL.getFirstChild());
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
	 * Get the dependencies of the current job, which is 
	 * a string array of ids of the jobs that have run before the current job. 
	 * @param jobIDs holds a string array of ids of the jobs that have run before the current job. 
	 * @return whether the job dependencies are set successfully.
	 */
	public boolean setJobDependencies(String[] jobIDs){
		Node nodeRef = null;
		try{
			Element eJob = (Element)XMLUtil.findChildNode(m_eOSoL, "job");
			if(eJob == null){
				eJob = m_document.createElement("job");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
						}
						else{
							m_eOSoL.insertBefore(eJob, m_eOSoL.getFirstChild());
						}		
					}		
				}
			}
			if(jobIDs != null && jobIDs.length > 0){
				Element eDependencies = (Element)XMLUtil.findChildNode(eJob, "dependencies");
				if(eDependencies == null){
					eDependencies = m_document.createElement("dependencies");	
					eJob.appendChild(eDependencies);									
				}
				XMLUtil.removeAllChildren(eDependencies);
				int iJobIDs = jobIDs.length;
				eDependencies.setAttribute("numberOfJobIDs", iJobIDs+"");
				for(int i = 0; i < iJobIDs; i++){
					if(jobIDs[i] != null && jobIDs[i].length() > 0){
						Element eJobID = m_document.createElement("jobID");	
						eJobID.appendChild(m_document.createTextNode(jobIDs[i]));
						eDependencies.appendChild(eJobID);				
					}
				}
			}
			else{
				XMLUtil.removeChildrenByName(eJob, "dependencies");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setJobDependencies

	/**
	 * Set the required directories to run the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of directory paths required to run the job. 
	 * @return whether the required directories are set successfully.
	 */
	public boolean setRequiredDirectories(String[] paths){
		Node nodeRef = null;
		try{
			Element eJob = (Element)XMLUtil.findChildNode(m_eOSoL, "job");
			if(eJob == null){
				eJob = m_document.createElement("job");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
						}
						else{
							m_eOSoL.insertBefore(eJob, m_eOSoL.getFirstChild());
						}		
					}		
				}
			}
			if(paths != null && paths.length > 0){
				Element eRequiredDirectories = (Element)XMLUtil.findChildNode(eJob, "requiredDirectories");
				if(eRequiredDirectories == null){
					eRequiredDirectories = m_document.createElement("requiredDirectories");	
					eJob.appendChild(eRequiredDirectories);									
				}
				XMLUtil.removeAllChildren(eRequiredDirectories);
				int iPaths = paths.length;
				eRequiredDirectories.setAttribute("numberOfPaths", iPaths+"");
				for(int i = 0; i < iPaths; i++){
					if(paths[i] != null && paths[i].length() > 0){
						Element ePath = m_document.createElement("path");	
						ePath.appendChild(m_document.createTextNode(paths[i]));
						eRequiredDirectories.appendChild(ePath);				
					}
				}
			}
			else{
				XMLUtil.removeChildrenByName(eJob, "requiredDirectories");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setRequiredDirectoriesjob

	/**
	 * Set the required files to run the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of file paths required to run the job. 
	 * @return whether the required files are set successfully.
	 */
	public boolean setRequiredFiles(String[] paths){
		Node nodeRef = null;
		try{
			Element eJob = (Element)XMLUtil.findChildNode(m_eOSoL, "job");
			if(eJob == null){
				eJob = m_document.createElement("job");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
						}
						else{
							m_eOSoL.insertBefore(eJob, m_eOSoL.getFirstChild());
						}		
					}		
				}
			}
			if(paths != null && paths.length > 0){
				Element eRequiredFiles = (Element)XMLUtil.findChildNode(eJob, "requiredFiles");
				if(eRequiredFiles == null){
					eRequiredFiles = m_document.createElement("requiredFiles");	
					eJob.appendChild(eRequiredFiles);									
				}
				XMLUtil.removeAllChildren(eRequiredFiles);
				int iPaths = paths.length;
				eRequiredFiles.setAttribute("numberOfPaths", iPaths+"");
				for(int i = 0; i < iPaths; i++){
					if(paths[i] != null && paths[i].length() > 0){
						Element ePath = m_document.createElement("path");	
						ePath.appendChild(m_document.createTextNode(paths[i]));
						eRequiredFiles.appendChild(ePath);				
					}
				}
			}
			else{
				XMLUtil.removeChildrenByName(eJob, "requiredFiles");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setRequiredFiles

	/**
	 * Set the directories to make before running the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of directories to make before running the job. 
	 * @return whether the directories to make are set successfully.
	 */
	public boolean setDirectoriesToMake(String[] paths){
		Node nodeRef = null;
		try{
			Element eJob = (Element)XMLUtil.findChildNode(m_eOSoL, "job");
			if(eJob == null){
				eJob = m_document.createElement("job");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
						}
						else{
							m_eOSoL.insertBefore(eJob, m_eOSoL.getFirstChild());
						}		
					}		
				}
			}
			if(paths != null && paths.length > 0){
				Element eDirectoriesToMake = (Element)XMLUtil.findChildNode(eJob, "directoriesToMake");
				if(eDirectoriesToMake == null){
					eDirectoriesToMake = m_document.createElement("directoriesToMake");	
					eJob.appendChild(eDirectoriesToMake);									
				}
				XMLUtil.removeAllChildren(eDirectoriesToMake);
				int iPaths = paths.length;
				eDirectoriesToMake.setAttribute("numberOfPaths", iPaths+"");
				for(int i = 0; i < iPaths; i++){
					if(paths[i] != null && paths[i].length() > 0){
						Element ePath = m_document.createElement("path");	
						ePath.appendChild(m_document.createTextNode(paths[i]));
						eDirectoriesToMake.appendChild(ePath);				
					}
				}
			}
			else{
				XMLUtil.removeChildrenByName(eJob, "directoriesToMake");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;

	}//setDirectoriesToMake

	/**
	 * Set the files to make before running the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of files to make before running the job. 
	 * @return whether the files to make are set successfully.
	 */
	public boolean setFilesToMake(String[] paths){
		Node nodeRef = null;
		try{
			Element eJob = (Element)XMLUtil.findChildNode(m_eOSoL, "job");
			if(eJob == null){
				eJob = m_document.createElement("job");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
						}
						else{
							m_eOSoL.insertBefore(eJob, m_eOSoL.getFirstChild());
						}		
					}		
				}
			}
			if(paths != null && paths.length > 0){
				Element eFilesToMake = (Element)XMLUtil.findChildNode(eJob, "filesToMake");
				if(eFilesToMake == null){
					eFilesToMake = m_document.createElement("filesToMake");	
					eJob.appendChild(eFilesToMake);									
				}
				XMLUtil.removeAllChildren(eFilesToMake);
				int iPaths = paths.length;
				eFilesToMake.setAttribute("numberOfPaths", iPaths+"");
				for(int i = 0; i < iPaths; i++){
					if(paths[i] != null && paths[i].length() > 0){
						Element ePath = m_document.createElement("path");	
						ePath.appendChild(m_document.createTextNode(paths[i]));
						eFilesToMake.appendChild(ePath);				
					}
				}
			}
			else{
				XMLUtil.removeChildrenByName(eJob, "filesToMake");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;

	}//setFilesToMake

	/**
	 * Set the list of input directories that need to be moved or copied
	 * 
	 * @param pathPairs hold an array of path pair to move or copy
	 * @return whether the path pairs are set successfully. 
	 */
	public boolean setInputDirectoriesToMove(PathPair[] pathPairs){
		Node nodeRef = null;
		try{
			Element eJob = (Element)XMLUtil.findChildNode(m_eOSoL, "job");
			if(eJob == null){
				eJob = m_document.createElement("job");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
						}
						else{
							m_eOSoL.insertBefore(eJob, m_eOSoL.getFirstChild());
						}		
					}		
				}
			}
			if(pathPairs != null && pathPairs.length > 0){
				Element eInputDirectoriesToMove = (Element)XMLUtil.findChildNode(eJob, "inputDirectoriesToMove");
				if(eInputDirectoriesToMove == null){
					eInputDirectoriesToMove = m_document.createElement("inputDirectoriesToMove");	
					eJob.appendChild(eInputDirectoriesToMove);									
				}
				XMLUtil.removeAllChildren(eInputDirectoriesToMove);
				int iPathPairs = pathPairs.length;
				int nPairs = 0;
				for(int i = 0; i < iPathPairs; i++){
					if(pathPairs[i] != null && 
							pathPairs[i].from != null && pathPairs[i].from.length() > 0 &&
							pathPairs[i].to != null && pathPairs[i].to.length() > 0){
						nPairs++;
						Element ePathPair = m_document.createElement("pathPair");	
						ePathPair.setAttribute("from", pathPairs[i].from);
						ePathPair.setAttribute("to", pathPairs[i].to);
						if(pathPairs[i].makeCopy) ePathPair.setAttribute("makeCopy", "true");
						eInputDirectoriesToMove.appendChild(ePathPair);				
					}
				}
				eInputDirectoriesToMove.setAttribute("numberOfPathPairs", nPairs+"");
			}
			else{
				XMLUtil.removeChildrenByName(eJob, "inputDirectoriesToMove");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;

	}//setInputDirectoriesToMove

	/**
	 * Set the list of input files that need to be moved or copied
	 * 
	 * @param pathPairs hold an array of path pair to move or copy
	 * @return whether the path pairs are set successfully. 
	 */
	public boolean setInputFilesToMove(PathPair[] pathPairs){
		Node nodeRef = null;
		try{
			Element eJob = (Element)XMLUtil.findChildNode(m_eOSoL, "job");
			if(eJob == null){
				eJob = m_document.createElement("job");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
						}
						else{
							m_eOSoL.insertBefore(eJob, m_eOSoL.getFirstChild());
						}		
					}		
				}
			}
			if(pathPairs != null && pathPairs.length > 0){
				Element eInputFilesToMove = (Element)XMLUtil.findChildNode(eJob, "inputFilesToMove");
				if(eInputFilesToMove == null){
					eInputFilesToMove = m_document.createElement("inputFilesToMove");	
					eJob.appendChild(eInputFilesToMove);									
				}
				XMLUtil.removeAllChildren(eInputFilesToMove);
				int iPathPairs = pathPairs.length;
				int nPairs = 0;
				for(int i = 0; i < iPathPairs; i++){
					if(pathPairs[i] != null && 
							pathPairs[i].from != null && pathPairs[i].from.length() > 0 &&
							pathPairs[i].to != null && pathPairs[i].to.length() > 0){
						nPairs++;
						Element ePathPair = m_document.createElement("pathPair");	
						ePathPair.setAttribute("from", pathPairs[i].from);
						ePathPair.setAttribute("to", pathPairs[i].to);
						if(pathPairs[i].makeCopy) ePathPair.setAttribute("makeCopy", "true");
						eInputFilesToMove.appendChild(ePathPair);				
					}
				}
				eInputFilesToMove.setAttribute("numberOfPathPairs", nPairs+"");
			}
			else{
				XMLUtil.removeChildrenByName(eJob, "inputFilesToMove");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;

	}//setInputFilesToMove

	/**
	 * Set the list of output directories that need to be moved or copied
	 * 
	 * @param pathPairs hold an array of path pair to move or copy
	 * @return whether the path pairs are set successfully. 
	 */
	public boolean setOutputDirectoriesToMove(PathPair[] pathPairs){
		Node nodeRef = null;
		try{
			Element eJob = (Element)XMLUtil.findChildNode(m_eOSoL, "job");
			if(eJob == null){
				eJob = m_document.createElement("job");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
						}
						else{
							m_eOSoL.insertBefore(eJob, m_eOSoL.getFirstChild());
						}		
					}		
				}
			}
			if(pathPairs != null && pathPairs.length > 0){
				Element eOutputDirectoriesToMove = (Element)XMLUtil.findChildNode(eJob, "outputDirectoriesToMove");
				if(eOutputDirectoriesToMove == null){
					eOutputDirectoriesToMove = m_document.createElement("outputDirectoriesToMove");	
					eJob.appendChild(eOutputDirectoriesToMove);									
				}
				XMLUtil.removeAllChildren(eOutputDirectoriesToMove);
				int iPathPairs = pathPairs.length;
				int nPairs = 0;
				for(int i = 0; i < iPathPairs; i++){
					if(pathPairs[i] != null && 
							pathPairs[i].from != null && pathPairs[i].from.length() > 0 &&
							pathPairs[i].to != null && pathPairs[i].to.length() > 0){
						nPairs++;
						Element ePathPair = m_document.createElement("pathPair");	
						ePathPair.setAttribute("from", pathPairs[i].from);
						ePathPair.setAttribute("to", pathPairs[i].to);
						if(pathPairs[i].makeCopy) ePathPair.setAttribute("makeCopy", "true");
						eOutputDirectoriesToMove.appendChild(ePathPair);				
					}
				}
				eOutputDirectoriesToMove.setAttribute("numberOfPathPairs", nPairs+"");
			}
			else{
				XMLUtil.removeChildrenByName(eJob, "outputDirectoriesToMove");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;

	}//setOutputDirectoriesToMove

	/**
	 * Set the list of output files that need to be moved or copied
	 * 
	 * @param pathPairs hold an array of path pair to move or copy
	 * @return whether the path pairs are set successfully. 
	 */
	public boolean setOutputFilesToMove(PathPair[] pathPairs){
		Node nodeRef = null;
		try{
			Element eJob = (Element)XMLUtil.findChildNode(m_eOSoL, "job");
			if(eJob == null){
				eJob = m_document.createElement("job");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
						}
						else{
							m_eOSoL.insertBefore(eJob, m_eOSoL.getFirstChild());
						}		
					}		
				}
			}
			if(pathPairs != null && pathPairs.length > 0){
				Element eOutputFilesToMove = (Element)XMLUtil.findChildNode(eJob, "outputFilesToMove");
				if(eOutputFilesToMove == null){
					eOutputFilesToMove = m_document.createElement("outputFilesToMove");	
					eJob.appendChild(eOutputFilesToMove);									
				}
				XMLUtil.removeAllChildren(eOutputFilesToMove);
				int iPathPairs = pathPairs.length;
				int nPairs = 0;
				for(int i = 0; i < iPathPairs; i++){
					if(pathPairs[i] != null && 
							pathPairs[i].from != null && pathPairs[i].from.length() > 0 &&
							pathPairs[i].to != null && pathPairs[i].to.length() > 0){
						nPairs++;
						Element ePathPair = m_document.createElement("pathPair");	
						ePathPair.setAttribute("from", pathPairs[i].from);
						ePathPair.setAttribute("to", pathPairs[i].to);
						if(pathPairs[i].makeCopy) ePathPair.setAttribute("makeCopy", "true");
						eOutputFilesToMove.appendChild(ePathPair);				
					}
				}
				eOutputFilesToMove.setAttribute("numberOfPathPairs", nPairs+"");
			}
			else{
				XMLUtil.removeChildrenByName(eJob, "outputFilesToMove");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;

	}//setOutputFilesToMove

//	/**
//	* Set the output files to move to before running the job, which is 
//	* a string array of paths. 
//	* @param paths holds a string array of output files to move to before running the job. 
//	* @return whether the output files to move to are set successfully.
//	*/
//	public boolean setOutputFilesToMoveTo(String[] paths){
//	Node nodeRef = null;
//	try{
//	Element eJob = (Element)XMLUtil.findChildNode(m_eOSoL, "job");
//	if(eJob == null){
//	eJob = m_document.createElement("job");
//	nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
//	if(nodeRef != null){
//	m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
//	}
//	else{
//	nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
//	if(nodeRef != null){
//	m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
//	}
//	else{
//	nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
//	if(nodeRef != null){
//	m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
//	}
//	else{
//	m_eOSoL.insertBefore(eJob, m_eOSoL.getFirstChild());
//	}		
//	}		
//	}
//	}
//	if(paths != null && paths.length > 0){
//	Element eOutputFilesToMoveTo = (Element)XMLUtil.findChildNode(eJob, "outputFilesToMoveTo");
//	if(eOutputFilesToMoveTo == null){
//	eOutputFilesToMoveTo = m_document.createElement("outputFilesToMoveTo");	
//	eJob.appendChild(eOutputFilesToMoveTo);									
//	}
//	XMLUtil.removeAllChildren(eOutputFilesToMoveTo);
//	int iPaths = paths.length;
//	for(int i = 0; i < iPaths; i++){
//	if(paths[i] != null && paths[i].length() > 0){
//	Element ePath = m_document.createElement("path");	
//	ePath.appendChild(m_document.createTextNode(paths[i]));
//	eOutputFilesToMoveTo.appendChild(ePath);				
//	}
//	}
//	}
//	else{
//	XMLUtil.removeChildrenByName(eJob, "outputFilesToMoveTo");
//	}
//	}
//	catch(Exception e){
//	e.printStackTrace();
//	return false;
//	}
//	return true;

//	}//setOutputFilesToMoveTo

	/**
	 * Set the files to delete after running the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of file paths to delete after running the job. 
	 * @return whether the files to delete are set successfully.
	 */
	public boolean setFilesToDelete(String[] paths){
		Node nodeRef = null;
		try{
			Element eJob = (Element)XMLUtil.findChildNode(m_eOSoL, "job");
			if(eJob == null){
				eJob = m_document.createElement("job");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
						}
						else{
							m_eOSoL.insertBefore(eJob, m_eOSoL.getFirstChild());
						}		
					}		
				}
			}
			if(paths != null && paths.length > 0){
				Element eFilesToDelete = (Element)XMLUtil.findChildNode(eJob, "filesToDelete");
				if(eFilesToDelete == null){
					eFilesToDelete = m_document.createElement("filesToDelete");	
					eJob.appendChild(eFilesToDelete);									
				}
				XMLUtil.removeAllChildren(eFilesToDelete);
				int iPaths = paths.length;
				eFilesToDelete.setAttribute("numberOfPaths", iPaths+"");
				for(int i = 0; i < iPaths; i++){
					if(paths[i] != null && paths[i].length() > 0){
						Element ePath = m_document.createElement("path");	
						ePath.appendChild(m_document.createTextNode(paths[i]));
						eFilesToDelete.appendChild(ePath);				
					}
				}
			}
			else{
				XMLUtil.removeChildrenByName(eJob, "filesToDelete");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;

	}//setFilesToDelete

	/**
	 * Set the directories to delete after running the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of directory paths to delete after running the job. 
	 * @return whether the directories to delete are set successfully.
	 */
	public boolean setDirectoriesToDelete(String[] paths){
		Node nodeRef = null;
		try{
			Element eJob = (Element)XMLUtil.findChildNode(m_eOSoL, "job");
			if(eJob == null){
				eJob = m_document.createElement("job");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
						}
						else{
							m_eOSoL.insertBefore(eJob, m_eOSoL.getFirstChild());
						}		
					}		
				}
			}
			if(paths != null && paths.length > 0){
				Element eDirectoriesToDelete = (Element)XMLUtil.findChildNode(eJob, "directoriesToDelete");
				if(eDirectoriesToDelete == null){
					eDirectoriesToDelete = m_document.createElement("directoriesToDelete");	
					eJob.appendChild(eDirectoriesToDelete);									
				}
				XMLUtil.removeAllChildren(eDirectoriesToDelete);
				int iPaths = paths.length;
				eDirectoriesToDelete.setAttribute("numberOfPaths", iPaths+"");
				for(int i = 0; i < iPaths; i++){
					if(paths[i] != null && paths[i].length() > 0){
						Element ePath = m_document.createElement("path");	
						ePath.appendChild(m_document.createTextNode(paths[i]));
						eDirectoriesToDelete.appendChild(ePath);				
					}
				}
			}
			else{
				XMLUtil.removeChildrenByName(eJob, "directoriesToDelete");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;

	}//setDirectoriesToDelete


	/**
	 * Set the processes to kill after running the job, which is 
	 * a string array of paths. 
	 * @param processNames holds a string array of process names to kill after running the job. 
	 * @return whether the processes to kill are set successfully.
	 */
	public boolean setProcessesToKill(String[] processNames){
		Node nodeRef = null;
		try{
			Element eJob = (Element)XMLUtil.findChildNode(m_eOSoL, "job");
			if(eJob == null){
				eJob = m_document.createElement("job");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
						}
						else{
							m_eOSoL.insertBefore(eJob, m_eOSoL.getFirstChild());
						}		
					}		
				}
			}
			if(processNames != null && processNames.length > 0){
				Element eProcessesToKill = (Element)XMLUtil.findChildNode(eJob, "processesToKill");
				if(eProcessesToKill == null){
					eProcessesToKill = m_document.createElement("processesToKill");	
					eJob.appendChild(eProcessesToKill);									
				}
				XMLUtil.removeAllChildren(eProcessesToKill);
				int iProcesses = processNames.length;
				eProcessesToKill.setAttribute("numberOfProcesses", iProcesses+"");
				for(int i = 0; i < iProcesses; i++){
					if(processNames[i] != null && processNames[i].length() > 0){
						Element eProcess = m_document.createElement("process");	
						eProcess.appendChild(m_document.createTextNode(processNames[i]));
						eProcessesToKill.appendChild(eProcess);				
					}
				}
			}
			else{
				XMLUtil.removeChildrenByName(eJob, "processesToKill");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;

	}//setProcessesToKill

	/**
	 * Set the number of other job options. 
	 * 
	 * @param numberOfOtherJobOptions holds the number of other job options
	 * @return whether the number is set successfully or not. 
	 */
	public boolean setNumberOfOtherJobOptions(int numberOfOtherJobOptions){
		Node nodeRef = null;
		if(numberOfOtherJobOptions < 0){
			return true;
		}
		Element eJob = (Element)XMLUtil.findChildNode(m_eOSoL, "job");
		if(eJob == null){
			eJob = m_document.createElement("job");
			nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
			if(nodeRef != null){
				m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
					}
					else{
						m_eOSoL.insertBefore(eJob, m_eOSoL.getFirstChild());
					}		
				}		
			}
		}
		Element eOtherOptions = (Element)XMLUtil.findChildNode(eJob, "otherOptions");
		if(eOtherOptions == null){
			eOtherOptions = m_document.createElement("otherOptions");	
			eJob.appendChild(eOtherOptions);				
		}
		try{
			eOtherOptions.setAttribute("numberOfOtherOptions", numberOfOtherJobOptions+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;	
	}//setNumberOfOtherJobOptions

	/**
	 * Set the other job options. 
	 * 
	 * @param names holds the names of the other options. It is required. 
	 * @param values holds the values of the other options, empty string "" or null if no value for an option.
	 * @param descriptions holds the descriptions of the other options, empty string "" or null if no value for an option, null for
	 * the entire array if none of the options have descriptions.
	 * @return whether the other options element construction is successful.
	 */
	public boolean setOtherJobOptions(String[] names, String[] values, String[] descriptions){
		if(names == null) return false;
		if(values == null) return false;
		if(names.length != values.length) return false;
		if(descriptions != null && names.length != descriptions.length) return false;
		for(int i = 0; i < names.length; i++){
			addOtherJobOption(names[i], values[i], (descriptions==null)?"":descriptions[i]);
		}
		return true;
	}//setOtherJobOptions

	/**
	 * Add an other job option element. 
	 * 
	 * @param name holds the name of the other option element. It is required.
	 * @param value holds the value of the other option element, empty string "" or null if none. 
	 * @param description holds the description of the other option element, empty string "" or null if none. 
	 * @return whether the other option element is added successfully.
	 */
	public boolean addOtherJobOption(String name, String value, String description){
		Node nodeRef = null;
		if(name == null || name.trim().length() <= 0) return false;
		try{
			Element eJob = (Element)XMLUtil.findChildNode(m_eOSoL, "job");
			if(eJob == null){
				eJob = m_document.createElement("job");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eJob, nodeRef.getNextSibling());			
						}
						else{
							m_eOSoL.insertBefore(eJob, m_eOSoL.getFirstChild());
						}		
					}		
				}
			}
			Element eOtherOptions = (Element)XMLUtil.findChildNode(eJob, "otherOptions");
			if(eOtherOptions == null){
				eOtherOptions = m_document.createElement("otherOptions");	
				eJob.appendChild(eOtherOptions);				
			}
			try{
				Vector<Element> vElements = XMLUtil.getChildElementsByTagName(eOtherOptions, "other");
				Element eOther;
				int iNls = vElements==null?0:vElements.size();
				for(int i = 0; i < iNls; i++){
					eOther = (Element)vElements.elementAt(i);
					if(eOther.getAttribute("name").equals(name)){
						eOtherOptions.removeChild(eOther);
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
				eOtherOptions.appendChild(eOther);

				eOtherOptions.setAttribute("numberOfOtherOptions", (iNls+1)+"");

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
	}//addOtherJobOption

	/**
	 * Set the variable number. 
	 * 
	 * @param variableNumber holds the number of variables
	 * @return whether the variable number is set successfully or not. 
	 */
	public boolean setNumberOfVariables(int variableNumber){
		if(variableNumber < 0){
			return true;
		}
		Node nodeRef = null;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSoL, "optimization");
		if(eOptimization == null){
			eOptimization = m_document.createElement("optimization");
			nodeRef = XMLUtil.findChildNode(m_eOSoL, "job");
			if(nodeRef != null){
				m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							m_eOSoL.insertBefore(eOptimization, m_eOSoL.getFirstChild());
						}		
					}		
				}
			}
		}
		try{
			eOptimization.setAttribute("numberOfVariables", variableNumber+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;	
	}//setNumberOfVariables

	/**
	 * Set the objective number. 
	 * 
	 * @param objectiveNumber holds the number of objectives
	 * @return whether the objective number is set successfully or not. 
	 */
	public boolean setNumberOfObjectives(int objectiveNumber){
		if(objectiveNumber < 0){
			return true;
		}
		Node nodeRef = null;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSoL, "optimization");
		if(eOptimization == null){
			eOptimization = m_document.createElement("optimization");
			nodeRef = XMLUtil.findChildNode(m_eOSoL, "job");
			if(nodeRef != null){
				m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							m_eOSoL.insertBefore(eOptimization, m_eOSoL.getFirstChild());
						}		
					}		
				}
			}
		}
		try{
			eOptimization.setAttribute("numberOfObjectives", objectiveNumber+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setNumberOfObjectives

	/**
	 * Set the constraint number. 
	 * 
	 * @param constraintNumber holds the number of constraints
	 * @return whether the constraint number is set successfully or not. 
	 */
	public boolean setNumberOfConstraints(int constraintNumber){
		if(constraintNumber < 0){
			return true;
		}
		Node nodeRef = null;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSoL, "optimization");
		if(eOptimization == null){
			eOptimization = m_document.createElement("optimization");
			nodeRef = XMLUtil.findChildNode(m_eOSoL, "job");
			if(nodeRef != null){
				m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							m_eOSoL.insertBefore(eOptimization, m_eOSoL.getFirstChild());
						}		
					}		
				}
			}
		}
		try{
			eOptimization.setAttribute("numberOfConstraints", constraintNumber+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;	
	}//setNumberOfConstraints

	/**
	 * Set initial variable values (double[]). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods are recommended  to be called first. 
	 * @param initialVariableValues holds a double array of initial variable values. 
	 * @return whether the initial variable values are set successfully or not. 
	 */
	public boolean setInitVarValuesDense(double[] initialVariableValues){
		Node nodeRef = null;
		try{
			Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSoL, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.createElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "job");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
							}
							else{
								m_eOSoL.insertBefore(eOptimization, m_eOSoL.getFirstChild());
							}		
						}		
					}
				}
			}
			Element eVariables = (Element)XMLUtil.findChildNode(eOptimization, "variables");
			if(eVariables == null){
				if(initialVariableValues == null || initialVariableValues.length <= 0){
					return true;
				}
				eVariables = m_document.createElement("variables");	
				eOptimization.insertBefore(eVariables, eOptimization.getFirstChild());									
			}
			Element eInitialVariableValues = (Element)XMLUtil.findChildNode(eVariables, "initialVariableValues");
			if(eInitialVariableValues == null){
				if(initialVariableValues == null || initialVariableValues.length <= 0){
					return true;
				}
				eInitialVariableValues = m_document.createElement("initialVariableValues");	
				eVariables.insertBefore(eInitialVariableValues, eVariables.getFirstChild());									
			}
			XMLUtil.removeAllChildren(eInitialVariableValues);
			int iVars = initialVariableValues==null?0:initialVariableValues.length;
			if(iVars == 0) return true;
			int nVar = 0;
			for(int i = 0; i < iVars; i++){
				if(initialVariableValues[i]==0) continue;
				Element eVar = m_document.createElement("var");	
				eVar.setAttribute("idx", i+"");
				eVar.setAttribute("value", initialVariableValues[i]+"");
				eInitialVariableValues.appendChild(eVar);				
				nVar++;
			}
			eInitialVariableValues.setAttribute("numberOfVar", nVar+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setInitVarValuesDense

	/**
	 * Set initial variable values (InitVarValue[]). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods are recommended  to be called first. 
	 * @param initialVariableValues holds the initial variable values in sparse form (InitVarValue[]). 
	 * @return whether the initial variable values are set successfully or not. 
	 */
	public boolean setInitVarValuesSparse(InitVarValue[] initialVariableValues){
		Node nodeRef = null;
		try{
			Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSoL, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.createElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "job");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
							}
							else{
								m_eOSoL.insertBefore(eOptimization, m_eOSoL.getFirstChild());
							}		
						}		
					}
				}
			}
			Element eVariables = (Element)XMLUtil.findChildNode(eOptimization, "variables");
			if(eVariables == null){
				if(initialVariableValues == null || initialVariableValues.length <= 0){
					return true;
				}
				eVariables = m_document.createElement("variables");	
				eOptimization.insertBefore(eVariables, eOptimization.getFirstChild());									
			}
			Element eInitialVariableValues = (Element)XMLUtil.findChildNode(eVariables, "initialVariableValues");
			if(eInitialVariableValues == null){
				if(initialVariableValues == null || initialVariableValues.length <= 0){
					return true;
				}
				eInitialVariableValues = m_document.createElement("initialVariableValues");	
				eVariables.insertBefore(eInitialVariableValues, eVariables.getFirstChild());									
			}
			XMLUtil.removeAllChildren(eInitialVariableValues);
			int iVars = initialVariableValues==null?0:initialVariableValues.length;
			if(iVars == 0) return true;
			int nVar = 0;
			for(int i = 0; i < iVars; i++){
				if(initialVariableValues[i].value==0) continue;
				Element eVar = m_document.createElement("var");	
				eVar.setAttribute("idx", initialVariableValues[i].idx+"");
				eVar.setAttribute("value", initialVariableValues[i].value+"");
				eInitialVariableValues.appendChild(eVar);				
				nVar++;
			}
			eInitialVariableValues.setAttribute("numberOfVar", nVar+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setInitVarValuesSparse

	/**
	 * Set initial variable values (string[]). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods are recommended  to be called first. 
	 * @param initialVariableValues holds a double array of initial variable values. 
	 * @return whether the initial variable values string are set successfully or not. 
	 */
	public boolean setInitVarValuesStringDense(String[] initialVariableValuesString){
		Node nodeRef = null;
		try{
			Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSoL, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.createElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "job");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
							}
							else{
								m_eOSoL.insertBefore(eOptimization, m_eOSoL.getFirstChild());
							}		
						}		
					}
				}
			}
			Element eVariables = (Element)XMLUtil.findChildNode(eOptimization, "variables");
			if(eVariables == null){
				if(initialVariableValuesString == null || initialVariableValuesString.length <= 0){
					return true;
				}
				eVariables = m_document.createElement("variables");	
				eOptimization.insertBefore(eVariables, eOptimization.getFirstChild());									
			}
			Element eInitialVariableValues = (Element)XMLUtil.findChildNode(eVariables, "initialVariableValuesString");
			if(eInitialVariableValues == null){
				if(initialVariableValuesString == null || initialVariableValuesString.length <= 0){
					return true;
				}
				eInitialVariableValues = m_document.createElement("initialVariableValuesString");	
				Node nodeRef2 = XMLUtil.findChildNode(eVariables, "initialVariableValues");
				if(nodeRef2 != null){
					eVariables.insertBefore(eInitialVariableValues, nodeRef2.getNextSibling());			
				}
				else{
					eVariables.insertBefore(eInitialVariableValues, eVariables.getFirstChild());									
				}
			}
			XMLUtil.removeAllChildren(eInitialVariableValues);
			int iVars = initialVariableValuesString==null?0:initialVariableValuesString.length;
			if(iVars == 0) return true;
			int nVar = 0;
			for(int i = 0; i < iVars; i++){
				Element eVar = m_document.createElement("var");	
				eVar.setAttribute("idx", i+"");
				eVar.setAttribute("value", initialVariableValuesString[i]);
				eInitialVariableValues.appendChild(eVar);				
				nVar++;
			}
			eInitialVariableValues.setAttribute("numberOfVar", nVar+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setInitVarValuesStringDense

	/**
	 * Set initial variable values (InitVarValueString[]). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods are recommended  to be called first. 
	 * @param initialVariableValues holds the initial variable values in sparse form (InitVarValue[]). 
	 * @return whether the initial variable values string are set successfully or not. 
	 */
	public boolean setInitVarValuesStringSparse(InitVarValueString[] initialVariableValuesString){
		Node nodeRef = null;
		try{
			Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSoL, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.createElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "job");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
							}
							else{
								m_eOSoL.insertBefore(eOptimization, m_eOSoL.getFirstChild());
							}		
						}		
					}
				}
			}
			Element eVariables = (Element)XMLUtil.findChildNode(eOptimization, "variables");
			if(eVariables == null){
				if(initialVariableValuesString == null || initialVariableValuesString.length <= 0){
					return true;
				}
				eVariables = m_document.createElement("variables");	
				eOptimization.insertBefore(eVariables, eOptimization.getFirstChild());									
			}
			Element eInitialVariableValues = (Element)XMLUtil.findChildNode(eVariables, "initialVariableValuesString");
			if(eInitialVariableValues == null){
				if(initialVariableValuesString == null || initialVariableValuesString.length <= 0){
					return true;
				}
				eInitialVariableValues = m_document.createElement("initialVariableValuesString");	
				Node nodeRef2 = XMLUtil.findChildNode(eVariables, "initialVariableValues");
				if(nodeRef2 != null){
					eVariables.insertBefore(eInitialVariableValues, nodeRef2.getNextSibling());			
				}
				else{
					eVariables.insertBefore(eInitialVariableValues, eVariables.getFirstChild());									
				}
			}
			XMLUtil.removeAllChildren(eInitialVariableValues);
			int iVars = initialVariableValuesString==null?0:initialVariableValuesString.length;
			if(iVars == 0) return true;
			int nVar = 0;
			for(int i = 0; i < iVars; i++){
				Element eVar = m_document.createElement("var");	
				eVar.setAttribute("idx", initialVariableValuesString[i].idx+"");
				eVar.setAttribute("value", initialVariableValuesString[i].value);
				eInitialVariableValues.appendChild(eVar);				
				nVar++;
			}
			eInitialVariableValues.setAttribute("numberOfVar", nVar+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setInitVarValuesStringSparse

	/**
	 * Set initial basis status (string[]). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods are recommended  to be called first. 
	 * @param initialBasisStatus holds a string array of initial basis status. 
	 * @return whether the initial basis status are set successfully or not. 
	 */
	public boolean setInitBasisStatusDense(String[] initialBasisStatus){
		Node nodeRef = null;
		try{
			Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSoL, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.createElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "job");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
							}
							else{
								m_eOSoL.insertBefore(eOptimization, m_eOSoL.getFirstChild());
							}		
						}		
					}
				}
			}
			Element eVariables = (Element)XMLUtil.findChildNode(eOptimization, "variables");
			if(eVariables == null){
				if(initialBasisStatus == null || initialBasisStatus.length <= 0){
					return true;
				}
				eVariables = m_document.createElement("variables");	
				eOptimization.insertBefore(eVariables, eOptimization.getFirstChild());									
			}
			Element eInitialBasisStatus = (Element)XMLUtil.findChildNode(eVariables, "initialBasisStatus");
			if(eInitialBasisStatus == null){
				if(initialBasisStatus == null || initialBasisStatus.length <= 0){
					return true;
				}
				eInitialBasisStatus = m_document.createElement("initialBasisStatus");	
				Node nodeRef2 = XMLUtil.findChildNode(eVariables, "initialVariableValuesString");
				if(nodeRef2 != null){
					eVariables.insertBefore(eInitialBasisStatus, nodeRef2.getNextSibling());			
				}
				else{
					nodeRef2 = XMLUtil.findChildNode(eVariables, "initialVariableValues");
					if(nodeRef2 != null){
						eVariables.insertBefore(eInitialBasisStatus, nodeRef2.getNextSibling());			
					}
					else{
						eVariables.insertBefore(eInitialBasisStatus, eVariables.getFirstChild());									
					}				
				}
			}
			XMLUtil.removeAllChildren(eInitialBasisStatus);
			int iVars = initialBasisStatus==null?0:initialBasisStatus.length;
			if(iVars == 0) return true;
			int nVar = 0;
			for(int i = 0; i < iVars; i++){
				Element eVar = m_document.createElement("var");	
				eVar.setAttribute("idx", i+"");
				eVar.setAttribute("value", initialBasisStatus[i]);
				eInitialBasisStatus.appendChild(eVar);				
				nVar++;
			}
			eInitialBasisStatus.setAttribute("numberOfVar", nVar+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setInitBasisStatusDense

	/**
	 * Set initial basis status (InitBasStatus[]). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods are recommended  to be called first. 
	 * @param initialVariableValues holds the initial basis status in sparse form (InitBasStatus[]). 
	 * @return whether the initial basis status are set successfully or not. 
	 */
	public boolean setInitBasisStatusSparse(InitBasStatus[] initialBasisStatus){
		Node nodeRef = null;
		try{
			Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSoL, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.createElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "job");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
							}
							else{
								m_eOSoL.insertBefore(eOptimization, m_eOSoL.getFirstChild());
							}		
						}		
					}
				}
			}
			Element eVariables = (Element)XMLUtil.findChildNode(eOptimization, "variables");
			if(eVariables == null){
				if(initialBasisStatus == null || initialBasisStatus.length <= 0){
					return true;
				}
				eVariables = m_document.createElement("variables");	
				eOptimization.insertBefore(eVariables, eOptimization.getFirstChild());									
			}
			Element eInitialBasisStatus = (Element)XMLUtil.findChildNode(eVariables, "initialBasisStatus");
			if(eInitialBasisStatus == null){
				if(initialBasisStatus == null || initialBasisStatus.length <= 0){
					return true;
				}
				eInitialBasisStatus = m_document.createElement("initialBasisStatus");	
				Node nodeRef2 = XMLUtil.findChildNode(eVariables, "initialVariableValuesString");
				if(nodeRef2 != null){
					eVariables.insertBefore(eInitialBasisStatus, nodeRef2.getNextSibling());			
				}
				else{
					nodeRef2 = XMLUtil.findChildNode(eVariables, "initialVariableValues");
					if(nodeRef2 != null){
						eVariables.insertBefore(eInitialBasisStatus, nodeRef2.getNextSibling());			
					}
					else{
						eVariables.insertBefore(eInitialBasisStatus, eVariables.getFirstChild());									
					}				
				}
			}
			XMLUtil.removeAllChildren(eInitialBasisStatus);
			int iVars = initialBasisStatus==null?0:initialBasisStatus.length;
			if(iVars == 0) return true;
			int nVar = 0;
			for(int i = 0; i < iVars; i++){
				Element eVar = m_document.createElement("var");	
				eVar.setAttribute("idx", initialBasisStatus[i].idx+"");
				eVar.setAttribute("value", initialBasisStatus[i].value);
				eInitialBasisStatus.appendChild(eVar);				
				nVar++;
			}
			eInitialBasisStatus.setAttribute("numberOfVar", nVar+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setInitBasisStatusSparse

	/**
	 * Set integer variable branching weights (double[]). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods are recommended  to be called first. 
	 * @param integerVariableBranchingWeights holds a double array of integer variable branching weights. 
	 * @return whether the integer variable branching weights are set successfully or not. 
	 */
	public boolean setIntegerVariableBranchingWeightsDense(double[] integerVariableBranchingWeights){
		Node nodeRef = null;
		try{
			Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSoL, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.createElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "job");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
							}
							else{
								m_eOSoL.insertBefore(eOptimization, m_eOSoL.getFirstChild());
							}		
						}		
					}
				}
			}
			Element eVariables = (Element)XMLUtil.findChildNode(eOptimization, "variables");
			if(eVariables == null){
				if(integerVariableBranchingWeights == null || integerVariableBranchingWeights.length <= 0){
					return true;
				}
				eVariables = m_document.createElement("variables");	
				eOptimization.insertBefore(eVariables, eOptimization.getFirstChild());									
			}
			Element eIntegerVariableBranchingWeights = (Element)XMLUtil.findChildNode(eVariables, "integerVariableBranchingWeights");
			if(eIntegerVariableBranchingWeights == null){
				if(integerVariableBranchingWeights == null || integerVariableBranchingWeights.length <= 0){
					return true;
				}
				eIntegerVariableBranchingWeights = m_document.createElement("integerVariableBranchingWeights");	
				Node nodeRef2 = XMLUtil.findChildNode(eVariables, "sosVariableBranchingWeights");
				if(nodeRef2 != null){
					eVariables.insertBefore(eIntegerVariableBranchingWeights, nodeRef2);			
				}
				else{
					nodeRef2 = XMLUtil.findChildNode(eVariables, "other");
					eVariables.insertBefore(eIntegerVariableBranchingWeights, nodeRef2);			
				}
			}
			XMLUtil.removeAllChildren(eIntegerVariableBranchingWeights);
			int iVars = integerVariableBranchingWeights==null?0:integerVariableBranchingWeights.length;
			if(iVars == 0) return true;
			int nVar = 0;
			for(int i = 0; i < iVars; i++){
				Element eVar = m_document.createElement("var");	
				eVar.setAttribute("idx", i+"");
				eVar.setAttribute("value", integerVariableBranchingWeights[i]+"");
				eIntegerVariableBranchingWeights.appendChild(eVar);				
				nVar++;
			}
			eIntegerVariableBranchingWeights.setAttribute("numberOfVar", nVar+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setIntegerVariableBranchingWeightsDense


	/**
	 * Set  integer variable branching weights  (InitBasStatus[]). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods are recommended  to be called first. 
	 * @param integerVariableBranchingWeights holds integer variable branching weights in sparse form (BranchingWeight[]). 
	 * @return whether the integer variable branching weights are set successfully or not. 
	 */
	public boolean setIntegerVariableBranchingWeightsSparse(BranchingWeight[] integerVariableBranchingWeights){
		Node nodeRef = null;
		try{
			Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSoL, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.createElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "job");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
							}
							else{
								m_eOSoL.insertBefore(eOptimization, m_eOSoL.getFirstChild());
							}		
						}		
					}
				}
			}
			Element eVariables = (Element)XMLUtil.findChildNode(eOptimization, "variables");
			if(eVariables == null){
				if(integerVariableBranchingWeights == null || integerVariableBranchingWeights.length <= 0){
					return true;
				}
				eVariables = m_document.createElement("variables");	
				eOptimization.insertBefore(eVariables, eOptimization.getFirstChild());									
			}
			Element eIintegerVariableBranchingWeights = (Element)XMLUtil.findChildNode(eVariables, "integerVariableBranchingWeights");
			if(eIintegerVariableBranchingWeights == null){
				if(integerVariableBranchingWeights == null || integerVariableBranchingWeights.length <= 0){
					return true;
				}
				eIintegerVariableBranchingWeights = m_document.createElement("integerVariableBranchingWeights");	
				Node nodeRef2 = XMLUtil.findChildNode(eVariables, "sosVariableBranchingWeights");
				if(nodeRef2 != null){
					eVariables.insertBefore(eIintegerVariableBranchingWeights, nodeRef2);			
				}
				else{
					nodeRef2 = XMLUtil.findChildNode(eVariables, "other");
					eVariables.insertBefore(eIintegerVariableBranchingWeights, nodeRef2);			
				}
			}
			XMLUtil.removeAllChildren(eIintegerVariableBranchingWeights);
			int iVars = integerVariableBranchingWeights==null?0:integerVariableBranchingWeights.length;
			if(iVars == 0) return true;
			int nVar = 0;
			for(int i = 0; i < iVars; i++){
				Element eVar = m_document.createElement("var");	
				eVar.setAttribute("idx", integerVariableBranchingWeights[i].idx+"");
				eVar.setAttribute("value", integerVariableBranchingWeights[i].value+"");
				eIintegerVariableBranchingWeights.appendChild(eVar);				
				nVar++;
			}
			eIintegerVariableBranchingWeights.setAttribute("numberOfVar", nVar+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setIntegerVariableBranchingWeightsSparse

	/**
	 * add variable branching weights for one SOS  (InitBasStatus[]). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods are recommended  to be called first.
	 * @param sosIdx
	 * @param groupWeight
	 * @param branchingWeights holds sos branching weights in sparse form (BranchingWeight[]). 
	 * @return whether the sos branching weights are set successfully or not. 
	 */
	public boolean addSOSVariableBranchingWeightsForOneSOS(int sosIdx, double groupWeight, BranchingWeight[] branchingWeights){
		Node nodeRef = null;
		try{
			Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSoL, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.createElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "job");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
							}
							else{
								m_eOSoL.insertBefore(eOptimization, m_eOSoL.getFirstChild());
							}		
						}		
					}
				}
			}
			Element eVariables = (Element)XMLUtil.findChildNode(eOptimization, "variables");
			if(eVariables == null){
				if(branchingWeights == null || branchingWeights.length <= 0 || sosIdx <0){
					return true;
				}
				eVariables = m_document.createElement("variables");	
				eOptimization.insertBefore(eVariables, eOptimization.getFirstChild());									
			}
			Element eSOSVariableBranchingWeights = (Element)XMLUtil.findChildNode(eVariables, "sosVariableBranchingWeights");
			if(eSOSVariableBranchingWeights == null){
				if(branchingWeights == null || branchingWeights.length <= 0 || sosIdx < 0){
					return true;
				}
				eSOSVariableBranchingWeights = m_document.createElement("sosVariableBranchingWeights");	
				Node nodeRef2 = XMLUtil.findChildNode(eVariables, "other");
				eVariables.insertBefore(eSOSVariableBranchingWeights, nodeRef2);			
			}
			String sNumberOfSOS = eSOSVariableBranchingWeights.getAttribute("numberOfSOS");
			int iNumberOfSOS = 1;
			if(sNumberOfSOS != null && sNumberOfSOS.length()>0){
				try {
					iNumberOfSOS=Integer.parseInt(sNumberOfSOS);
					iNumberOfSOS++;
				}
				catch (Exception e) {
					iNumberOfSOS=1;
				}
			}
			eSOSVariableBranchingWeights.setAttribute("numberOfSOS", iNumberOfSOS+"");
			Element eSOS = m_document.createElement("sos");
			eSOSVariableBranchingWeights.appendChild(eSOS);
			int iVars = branchingWeights==null?0:branchingWeights.length;
			eSOS.setAttribute("sosIdx", sosIdx+"");
			if(groupWeight != 1.0) eSOS.setAttribute("groupWeight", groupWeight+"");
			eSOS.setAttribute("numberOfVar", iVars+"");
			if(iVars == 0) return true;
			for(int i = 0; i < iVars; i++){
				Element eVar = m_document.createElement("var");	
				eVar.setAttribute("idx", branchingWeights[i].idx+"");
				eVar.setAttribute("value", branchingWeights[i].value+"");
				eSOS.appendChild(eVar);				
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//addSOSVariableBranchingWeightsForOneSOS

	/**
	 * Set the number of other variable options. 
	 * 
	 * @param numberOfOtherVariableOptions holds the number of other variable options
	 * @return whether the number is set successfully or not. 
	 */
	public boolean setNumberOfOtherVariableOptions(int numberOfOtherVariableOptions){
		Node nodeRef = null;
		if(numberOfOtherVariableOptions < 0){
			return true;
		}
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSoL, "optimization");
		if(eOptimization == null){
			eOptimization = m_document.createElement("optimization");
			nodeRef = XMLUtil.findChildNode(m_eOSoL, "job");
			if(nodeRef != null){
				m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							m_eOSoL.insertBefore(eOptimization, m_eOSoL.getFirstChild());
						}		
					}		
				}
			}
		}
		Element eVariables = (Element)XMLUtil.findChildNode(eOptimization, "variables");
		if(eVariables == null){
			eVariables = m_document.createElement("variables");	
			eOptimization.insertBefore(eVariables, eOptimization.getFirstChild());									
		}
		try{
			eVariables.setAttribute("numberOfOtherVariableOptions", numberOfOtherVariableOptions+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;	
	}//setNumberOfOtherVariableOptions

	/**
	 * Add another variable option element. 
	 * 
	 * @param name holds the name of the option element. It is required.
	 * @param value holds the value of the option element, empty string "" or null if none. 
	 * @param description holds the description of the option element, empty string "" or null if none. 
	 * @param solver holds the solver of the option element, empty string "" or null if no value. 
	 * @param category holds the category of the option element, empty string "" or null if no value. 
	 * @param type holds the type of the option element, empty string "" or null if no value. 
	 * @param vars holds an array of var options
	 * @return whether the other variable option element is added successfully.
	 */
	public boolean addOtherVariableOption(String name, String value, String description, String solver, String category, String type, OtherVarOption[] vars){
		Node nodeRef = null;
		try{
			Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSoL, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.createElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "job");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
							}
							else{
								m_eOSoL.insertBefore(eOptimization, m_eOSoL.getFirstChild());
							}		
						}		
					}
				}
			}
			Element eVariables = (Element)XMLUtil.findChildNode(eOptimization, "variables");
			if(eVariables == null){
				if(name == null || name.length() <= 0){
					return false;
				}
				eVariables = m_document.createElement("variables");	
				eOptimization.insertBefore(eVariables, eOptimization.getFirstChild());									
			}
			Element eOtherOption = m_document.createElement("other");	
			eOtherOption.setAttribute("name", name);
			if(value != null && value.length() > 0){
				eOtherOption.setAttribute("value", value);
			}
			if(description != null && description.length() > 0){
				eOtherOption.setAttribute("description", description);
			}
			if(solver != null && solver.length() > 0){
				eOtherOption.setAttribute("solver", solver);
			}
			if(category != null && category.length() > 0){
				eOtherOption.setAttribute("category", category);
			}
			if(type != null && type.length() > 0){
				if(type.equalsIgnoreCase("double") || type.equalsIgnoreCase("integer") || 
						type.equalsIgnoreCase("boolean") || type.equalsIgnoreCase("string")){
					eOtherOption.setAttribute("type",type.toLowerCase());
				}
				else eOtherOption.setAttribute("type","string");
			}
			int iVars = vars==null?0:vars.length;
			eOtherOption.setAttribute("numberOfVar", iVars+"");
			for(int i = 0; i < iVars; i++){
				Element eVar = m_document.createElement("var");	
				eVar.setAttribute("idx", vars[i].idx+"");
				if(vars[i].value != null && vars[i].value.length() > 0) eVar.setAttribute("value", vars[i].value+"");
				if(vars[i].lbValue != null && vars[i].lbValue.length() > 0) eVar.setAttribute("lbValue", vars[i].lbValue+"");
				if(vars[i].ubValue != null && vars[i].ubValue.length() > 0) eVar.setAttribute("ubValue", vars[i].ubValue+"");
				eOtherOption.appendChild(eVar);				
			}
			try{
				Vector<Element> vElements = XMLUtil.getChildElementsByTagName(eVariables, "other");
				Element eOther;
				int iNls = vElements==null?0:vElements.size();
				for(int i = 0; i < iNls; i++){
					eOther = (Element)vElements.elementAt(i);
					if(eOther.getAttribute("name").equals(name)){
						eVariables.removeChild(eOther);
						iNls--;
					}
				}
				eVariables.appendChild(eOtherOption);			
				eVariables.setAttribute("numberOfOtherVariableOptions", (iNls+1)+"");

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
	}//addOtherVariableOption

	/**
	 * Set initial objective values (double[]). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods are recommended  to be called first. 
	 * @param initialObjectiveValues holds a double array of initial objective values. 
	 * @return whether the initial objective values are set successfully or not. 
	 */
	public boolean setInitObjValuesDense(double[] initialObjectiveValues){
		Node nodeRef = null;
		try{
			Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSoL, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.createElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "job");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
							}
							else{
								m_eOSoL.insertBefore(eOptimization, m_eOSoL.getFirstChild());
							}		
						}		
					}
				}
			}
			Element eObjectives = (Element)XMLUtil.findChildNode(eOptimization, "objectives");
			if(eObjectives == null){
				if(initialObjectiveValues == null || initialObjectiveValues.length <= 0){
					return true;
				}
				eObjectives = m_document.createElement("objectives");	
				Node nodeRef2 = null;
				nodeRef2 = XMLUtil.findChildNode(eOptimization, "variables");
				if(nodeRef2 != null){
					eOptimization.insertBefore(eObjectives, nodeRef2.getNextSibling());			
				}
				else{
					eOptimization.insertBefore(eObjectives, eOptimization.getFirstChild());		
				}
			}
			Element eInitialObjectiveValues = (Element)XMLUtil.findChildNode(eObjectives, "initialObjectiveValues");
			if(eInitialObjectiveValues == null){
				if(initialObjectiveValues == null || initialObjectiveValues.length <= 0){
					return true;
				}
				eInitialObjectiveValues = m_document.createElement("initialObjectiveValues");	
				eObjectives.insertBefore(eInitialObjectiveValues, eObjectives.getFirstChild());									
			}
			XMLUtil.removeAllChildren(eInitialObjectiveValues);
			int iObjs = initialObjectiveValues==null?0:initialObjectiveValues.length;
			if(iObjs == 0) return true;
			int nObj = 0;
			for(int i = 0; i < iObjs; i++){
				if(initialObjectiveValues[i]==0) continue;
				Element eObj = m_document.createElement("obj");	
				eObj.setAttribute("idx", (-i-1)+"");
				eObj.setAttribute("value", initialObjectiveValues[i]+"");
				eInitialObjectiveValues.appendChild(eObj);				
				nObj++;
			}
			eInitialObjectiveValues.setAttribute("numberOfObj", nObj+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setInitObjValuesDense

	/**
	 * Set initial objective values (InitObjValue[]). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods are recommended  to be called first. 
	 * @param initialObjectiveValues holds the initial objective values in sparse form (InitObjValue[]). 
	 * @return whether the initial objective values are set successfully or not. 
	 */
	public boolean setInitObjValuesSparse(InitObjValue[] initialObjectiveValues){
		Node nodeRef = null;
		try{
			Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSoL, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.createElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "job");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
							}
							else{
								m_eOSoL.insertBefore(eOptimization, m_eOSoL.getFirstChild());
							}		
						}		
					}
				}
			}
			Element eObjectives = (Element)XMLUtil.findChildNode(eOptimization, "objectives");
			if(eObjectives == null){
				if(initialObjectiveValues == null || initialObjectiveValues.length <= 0){
					return true;
				}
				eObjectives = m_document.createElement("objectives");	
				Node nodeRef2 = null;
				nodeRef2 = XMLUtil.findChildNode(eOptimization, "variables");
				if(nodeRef2 != null){
					eOptimization.insertBefore(eObjectives, nodeRef2.getNextSibling());			
				}
				else{
					eOptimization.insertBefore(eObjectives, eOptimization.getFirstChild());		
				}
			}
			Element eInitialObjectiveValues = (Element)XMLUtil.findChildNode(eObjectives, "initialObjectiveValues");
			if(eInitialObjectiveValues == null){
				if(initialObjectiveValues == null || initialObjectiveValues.length <= 0){
					return true;
				}
				eInitialObjectiveValues = m_document.createElement("initialObjectiveValues");	
				eObjectives.insertBefore(eInitialObjectiveValues, eObjectives.getFirstChild());									
			}
			XMLUtil.removeAllChildren(eInitialObjectiveValues);
			int iObjs = initialObjectiveValues==null?0:initialObjectiveValues.length;
			if(iObjs == 0) return true;
			int nObj = 0;
			for(int i = 0; i < iObjs; i++){
				if(initialObjectiveValues[i].value==0) continue;
				Element eObj = m_document.createElement("obj");	
				eObj.setAttribute("idx", initialObjectiveValues[i].idx+"");
				eObj.setAttribute("value", initialObjectiveValues[i].value+"");
				eInitialObjectiveValues.appendChild(eObj);				
				nObj++;
			}
			eInitialObjectiveValues.setAttribute("numberOfObj", nObj+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setInitObjValuesSparse

	/**
	 * Set initial objective bounds (double[]). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods are recommended  to be called first. 
	 * @param initialObjectiveLowerBounds holds the initial objective lower bounds in sparse form (InitObjBound[]). 
	 * @param initialObjectiveUpperBounds holds the initial objective upper bounds in sparse form (InitObjBound[]). 
	 * @return whether the initial objective bounds are set successfully or not. 
	 */
	public boolean setInitObjBoundsDense(double[] initialObjectiveLowerBounds, double[] initialObjectiveUpperBounds){
		if(initialObjectiveLowerBounds == null && initialObjectiveUpperBounds == null ){
			return true;
		}
		if(initialObjectiveLowerBounds != null && initialObjectiveUpperBounds != null
				&& initialObjectiveLowerBounds.length != initialObjectiveUpperBounds.length){
			return false;
		}
		Node nodeRef = null;
		try{
			Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSoL, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.createElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "job");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
							}
							else{
								m_eOSoL.insertBefore(eOptimization, m_eOSoL.getFirstChild());
							}		
						}		
					}
				}
			}
			Element eObjectives = (Element)XMLUtil.findChildNode(eOptimization, "objectives");
			if(eObjectives == null){
				eObjectives = m_document.createElement("objectives");	
				Node nodeRef2 = null;
				nodeRef2 = XMLUtil.findChildNode(eOptimization, "variables");
				if(nodeRef2 != null){
					eOptimization.insertBefore(eObjectives, nodeRef2.getNextSibling());			
				}
				else{
					eOptimization.insertBefore(eObjectives, eOptimization.getFirstChild());		
				}
			}
			Element eInitialObjectiveBounds = (Element)XMLUtil.findChildNode(eObjectives, "initialObjectiveBounds");
			if(eInitialObjectiveBounds == null){
				eInitialObjectiveBounds = m_document.createElement("initialObjectiveBounds");	
				Node nodeRef3 = null;
				nodeRef3 = XMLUtil.findChildNode(eObjectives, "initialObjectiveValues");
				if(nodeRef3 != null){
					eObjectives.insertBefore(eInitialObjectiveBounds, nodeRef3.getNextSibling());			
				}
				else{
					eObjectives.insertBefore(eInitialObjectiveBounds, eObjectives.getFirstChild());	
				}
			}
			XMLUtil.removeAllChildren(eInitialObjectiveBounds);
			int iObjs = initialObjectiveLowerBounds==null?0:initialObjectiveLowerBounds.length;
			if(iObjs <= 0) iObjs = initialObjectiveUpperBounds==null?0:initialObjectiveUpperBounds.length;
			if(iObjs == 0) return true;
			int nObj = 0;
			for(int i = 0; i < iObjs; i++){
				Element eObj = m_document.createElement("obj");	
				eObj.setAttribute("idx", (-i-1)+"");
				eObj.setAttribute("lbValue", initialObjectiveLowerBounds[i]+"");
				eObj.setAttribute("ubValue", initialObjectiveUpperBounds[i]+"");
				eInitialObjectiveBounds.appendChild(eObj);				
				nObj++;
			}
			eInitialObjectiveBounds.setAttribute("numberOfObj", nObj+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setInitObjBoundsDense

	/**
	 * Set initial objective bounds (InitObjBound[]). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods are recommended  to be called first. 
	 * @param initialObjectiveBounds holds the initial objective bounds in sparse form (InitObjBound[]). 
	 * @return whether the initial objective bounds are set successfully or not. 
	 */
	public boolean setInitObjBoundsSparse(InitObjBound[] initialObjectiveBounds){
		Node nodeRef = null;
		try{
			Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSoL, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.createElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "job");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
							}
							else{
								m_eOSoL.insertBefore(eOptimization, m_eOSoL.getFirstChild());
							}		
						}		
					}
				}
			}
			Element eObjectives = (Element)XMLUtil.findChildNode(eOptimization, "objectives");
			if(eObjectives == null){
				if(initialObjectiveBounds == null || initialObjectiveBounds.length <= 0){
					return true;
				}
				eObjectives = m_document.createElement("objectives");	
				Node nodeRef2 = null;
				nodeRef2 = XMLUtil.findChildNode(eOptimization, "variables");
				if(nodeRef2 != null){
					eOptimization.insertBefore(eObjectives, nodeRef2.getNextSibling());			
				}
				else{
					eOptimization.insertBefore(eObjectives, eOptimization.getFirstChild());		
				}
			}
			Element eInitialObjectiveBounds = (Element)XMLUtil.findChildNode(eObjectives, "initialObjectiveBounds");
			if(eInitialObjectiveBounds == null){
				if(initialObjectiveBounds == null || initialObjectiveBounds.length <= 0){
					return true;
				}
				eInitialObjectiveBounds = m_document.createElement("initialObjectiveBounds");	
				Node nodeRef3 = null;
				nodeRef3 = XMLUtil.findChildNode(eObjectives, "initialObjectiveValues");
				if(nodeRef3 != null){
					eObjectives.insertBefore(eInitialObjectiveBounds, nodeRef3.getNextSibling());			
				}
				else{
					eObjectives.insertBefore(eInitialObjectiveBounds, eObjectives.getFirstChild());	
				}
			}
			XMLUtil.removeAllChildren(eInitialObjectiveBounds);
			int iObjs = initialObjectiveBounds==null?0:initialObjectiveBounds.length;
			if(iObjs == 0) return true;
			int nObj = 0;
			for(int i = 0; i < iObjs; i++){
				if(initialObjectiveBounds[i] == null) continue;
				Element eObj = m_document.createElement("obj");	
				eObj.setAttribute("idx", initialObjectiveBounds[i].idx+"");
				eObj.setAttribute("lbValue", initialObjectiveBounds[i].lbValue+"");
				eObj.setAttribute("ubValue", initialObjectiveBounds[i].ubValue+"");
				eInitialObjectiveBounds.appendChild(eObj);				
				nObj++;
			}
			eInitialObjectiveBounds.setAttribute("numberOfObj", nObj+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setInitObjBoundsSparse

	/**
	 * Set the number of other objective options. 
	 * 
	 * @param numberOfOtherObjectiveOptions holds the number of other objective options
	 * @return whether the number is set successfully or not. 
	 */
	public boolean setNumberOfOtherObjectiveOptions(int numberOfOtherObjectiveOptions){
		Node nodeRef = null;
		if(numberOfOtherObjectiveOptions < 0){
			return true;
		}
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSoL, "optimization");
		if(eOptimization == null){
			eOptimization = m_document.createElement("optimization");
			nodeRef = XMLUtil.findChildNode(m_eOSoL, "job");
			if(nodeRef != null){
				m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							m_eOSoL.insertBefore(eOptimization, m_eOSoL.getFirstChild());
						}		
					}		
				}
			}
		}
		Element eObjectives = (Element)XMLUtil.findChildNode(eOptimization, "objectives");
		if(eObjectives == null){
			eObjectives = m_document.createElement("objectives");	
			Node nodeRef2 = null;
			nodeRef2 = XMLUtil.findChildNode(eOptimization, "variables");
			if(nodeRef2 != null){
				eOptimization.insertBefore(eObjectives, nodeRef2.getNextSibling());			
			}
			else{
				eOptimization.insertBefore(eObjectives, eOptimization.getFirstChild());									
			}
		}
		try{
			eObjectives.setAttribute("numberOfOtherObjectiveOptions", numberOfOtherObjectiveOptions+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;	
	}//setNumberOfOtherObjectiveOptions

	/**
	 * Add another objective option element. 
	 * 
	 * @param name holds the name of the option element. It is required.
	 * @param value holds the value of the option element, empty string "" or null if none. 
	 * @param description holds the description of the option element, empty string "" or null if none. 
	 * @param solver holds the solver of the option element, empty string "" or null if no value. 
	 * @param category holds the category of the option element, empty string "" or null if no value. 
	 * @param type holds the type of the option element, empty string "" or null if no value. 
	 * @param objs holds an array of obj options
	 * @return whether the other objective option element is added successfully.
	 */
	public boolean addOtherObjectiveOption(String name, String value, String description, String solver, String category, String type, OtherObjOption[] objs){
		Node nodeRef = null;
		try{
			Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSoL, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.createElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "job");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
							}
							else{
								m_eOSoL.insertBefore(eOptimization, m_eOSoL.getFirstChild());
							}		
						}		
					}
				}
			}
			Element eObjectives = (Element)XMLUtil.findChildNode(eOptimization, "objectives");
			if(eObjectives == null){
				if(name == null || name.length() <= 0){
					return false;
				}
				eObjectives = m_document.createElement("objectives");	
				Node nodeRef2 = null;
				nodeRef2 = XMLUtil.findChildNode(eOptimization, "variables");
				if(nodeRef2 != null){
					eOptimization.insertBefore(eObjectives, nodeRef2.getNextSibling());			
				}
				else{
					eOptimization.insertBefore(eObjectives, eOptimization.getFirstChild());		
				}
			}
			Element eOtherOption = m_document.createElement("other");	
			eOtherOption.setAttribute("name", name);
			if(value != null && value.length() > 0){
				eOtherOption.setAttribute("value", value);
			}
			if(description != null && description.length() > 0){
				eOtherOption.setAttribute("description", description);
			}
			if(solver != null && solver.length() > 0){
				eOtherOption.setAttribute("solver", solver);
			}
			if(category != null && category.length() > 0){
				eOtherOption.setAttribute("category", category);
			}
			if(type != null && type.length() > 0){
				if(type.equalsIgnoreCase("double") || type.equalsIgnoreCase("integer") || 
						type.equalsIgnoreCase("boolean") || type.equalsIgnoreCase("string")){
					eOtherOption.setAttribute("type",type.toLowerCase());
				}
				else eOtherOption.setAttribute("type","string");
			}
			int iObjs = objs==null?0:objs.length;
			eOtherOption.setAttribute("numberOfObj", iObjs+"");
			for(int i = 0; i < iObjs; i++){
				Element eObj = m_document.createElement("obj");	
				eObj.setAttribute("idx", objs[i].idx+"");
				if(objs[i].value != null && objs[i].value.length() > 0) eObj.setAttribute("value", objs[i].value+"");
				if(objs[i].lbValue != null && objs[i].lbValue.length() > 0) eObj.setAttribute("lbValue", objs[i].lbValue+"");
				if(objs[i].ubValue != null && objs[i].ubValue.length() > 0) eObj.setAttribute("ubValue", objs[i].ubValue+"");
				eOtherOption.appendChild(eObj);				
			}
			try{
				Vector<Element> vElements = XMLUtil.getChildElementsByTagName(eObjectives, "other");
				Element eOther;
				int iNls = vElements==null?0:vElements.size();
				for(int i = 0; i < iNls; i++){
					eOther = (Element)vElements.elementAt(i);
					if(eOther.getAttribute("name").equals(name)){
						eObjectives.removeChild(eOther);
						iNls--;
					}
				}
				eObjectives.appendChild(eOtherOption);			
				eObjectives.setAttribute("numberOfOtherObjectiveOptions", (iNls+1)+"");

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
	}//addOtherObjectiveOption	

	/**
	 * Set initial constraint values (double[]). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods are recommended  to be called first. 
	 * @param initialConstraintValues holds a double array of initial constraint values. 
	 * @return whether the initial constraint values are set successfully or not. 
	 */
	public boolean setInitConValuesDense(double[] initialConstraintValues){
		Node nodeRef = null;
		try{
			Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSoL, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.createElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "job");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
							}
							else{
								m_eOSoL.insertBefore(eOptimization, m_eOSoL.getFirstChild());
							}		
						}		
					}
				}
			}
			Element eConstraints = (Element)XMLUtil.findChildNode(eOptimization, "constraints");
			if(eConstraints == null){
				if(initialConstraintValues == null || initialConstraintValues.length <= 0){
					return true;
				}
				eConstraints = m_document.createElement("constraints");	
				Node nodeRef2 = null;
				nodeRef2 = XMLUtil.findChildNode(eOptimization, "objectives");
				if(nodeRef2 != null){
					eOptimization.insertBefore(eConstraints, nodeRef2.getNextSibling());			
				}
				else{
					nodeRef2 = XMLUtil.findChildNode(eOptimization, "variables");
					if(nodeRef2 != null){
						eOptimization.insertBefore(eConstraints, nodeRef2.getNextSibling());			
					}
					else{
						eOptimization.insertBefore(eConstraints, eOptimization.getFirstChild());		
					}	
				}
			}
			Element eInitialConstraintValues = (Element)XMLUtil.findChildNode(eConstraints, "initialConstraintValues");
			if(eInitialConstraintValues == null){
				if(initialConstraintValues == null || initialConstraintValues.length <= 0){
					return true;
				}
				eInitialConstraintValues = m_document.createElement("initialConstraintValues");	
				eConstraints.insertBefore(eInitialConstraintValues, eConstraints.getFirstChild());									
			}
			XMLUtil.removeAllChildren(eInitialConstraintValues);
			int iCons = initialConstraintValues==null?0:initialConstraintValues.length;
			if(iCons == 0) return true;
			int nCon = 0;
			for(int i = 0; i < iCons; i++){
				if(initialConstraintValues[i]==0) continue;
				Element eCon = m_document.createElement("con");	
				eCon.setAttribute("idx", i+"");
				eCon.setAttribute("value", initialConstraintValues[i]+"");
				eInitialConstraintValues.appendChild(eCon);				
				nCon++;
			}
			eInitialConstraintValues.setAttribute("numberOfCon", nCon+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setInitConValuesDense

	/**
	 * Set initial constraint values (InitConValue[]). 
	 * Before this method is called, the setVariable(int), setConective(int), setConstraint(int)
	 * methods are recommended  to be called first. 
	 * @param initialConstraintValues holds the initial constraint values in sparse form (InitConValue[]). 
	 * @return whether the initial constraint values are set successfully or not. 
	 */
	public boolean setInitConValuesSparse(InitConValue[] initialConstraintValues){
		Node nodeRef = null;
		try{
			Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSoL, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.createElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "job");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
							}
							else{
								m_eOSoL.insertBefore(eOptimization, m_eOSoL.getFirstChild());
							}		
						}		
					}
				}
			}
			Element eConstraints = (Element)XMLUtil.findChildNode(eOptimization, "constraints");
			if(eConstraints == null){
				if(initialConstraintValues == null || initialConstraintValues.length <= 0){
					return true;
				}
				eConstraints = m_document.createElement("constraints");	
				Node nodeRef2 = null;
				nodeRef2 = XMLUtil.findChildNode(eOptimization, "objectives");
				if(nodeRef2 != null){
					eOptimization.insertBefore(eConstraints, nodeRef2.getNextSibling());			
				}
				else{
					nodeRef2 = XMLUtil.findChildNode(eOptimization, "variables");
					if(nodeRef2 != null){
						eOptimization.insertBefore(eConstraints, nodeRef2.getNextSibling());			
					}
					else{
						eOptimization.insertBefore(eConstraints, eOptimization.getFirstChild());		
					}	
				}
			}
			Element eInitialConstraintValues = (Element)XMLUtil.findChildNode(eConstraints, "initialConstraintValues");
			if(eInitialConstraintValues == null){
				if(initialConstraintValues == null || initialConstraintValues.length <= 0){
					return true;
				}
				eInitialConstraintValues = m_document.createElement("initialConstraintValues");	
				eConstraints.insertBefore(eInitialConstraintValues, eConstraints.getFirstChild());									
			}
			XMLUtil.removeAllChildren(eInitialConstraintValues);
			int iCons = initialConstraintValues==null?0:initialConstraintValues.length;
			if(iCons == 0) return true;
			int nCon = 0;
			for(int i = 0; i < iCons; i++){
				if(initialConstraintValues[i].value==0) continue;
				Element eCon = m_document.createElement("con");	
				eCon.setAttribute("idx", initialConstraintValues[i].idx+"");
				eCon.setAttribute("value", initialConstraintValues[i].value+"");
				eInitialConstraintValues.appendChild(eCon);				
				nCon++;
			}
			eInitialConstraintValues.setAttribute("numberOfCon", nCon+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setInitConValuesSparse

	/**
	 * Set initial dual values (double[]). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods are recommended  to be called first. 
	 * @param initialLbDualValues holds the initial dual value at lower bounds.
	 * @param initialUbDualValues holds the initial dual value at upper bounds. 
	 * @return whether the initial dual values are set successfully or not. 
	 */
	public boolean setInitDualValuesDense(double[] initialLbDualValues, double[] initialUbDualValues){
		if(initialLbDualValues == null && initialUbDualValues == null ){
			return true;
		}
		if(initialLbDualValues != null && initialUbDualValues != null
				&& initialLbDualValues.length != initialUbDualValues.length){
			return false;
		}
		Node nodeRef = null;
		try{
			Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSoL, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.createElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "job");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
							}
							else{
								m_eOSoL.insertBefore(eOptimization, m_eOSoL.getFirstChild());
							}		
						}		
					}
				}
			}
			Element eConstraints = (Element)XMLUtil.findChildNode(eOptimization, "constraints");
			if(eConstraints == null){
				eConstraints = m_document.createElement("constraints");	
				Node nodeRef2 = null;
				nodeRef2 = XMLUtil.findChildNode(eOptimization, "objectives");
				if(nodeRef2 != null){
					eOptimization.insertBefore(eConstraints, nodeRef2.getNextSibling());			
				}
				else{
					nodeRef2 = XMLUtil.findChildNode(eOptimization, "variables");
					if(nodeRef2 != null){
						eOptimization.insertBefore(eConstraints, nodeRef2.getNextSibling());			
					}
					else{
						eOptimization.insertBefore(eConstraints, eOptimization.getFirstChild());		
					}	
				}
			}
			Element eInitialDualValues = (Element)XMLUtil.findChildNode(eConstraints, "initialDualValues");
			if(eInitialDualValues == null){
				eInitialDualValues = m_document.createElement("initialDualValues");	
				Node nodeRef3 = null;
				nodeRef3 = XMLUtil.findChildNode(eConstraints, "initialConstraintValues");
				if(nodeRef3 != null){
					eConstraints.insertBefore(eInitialDualValues, nodeRef3.getNextSibling());			
				}
				else{
					eConstraints.insertBefore(eInitialDualValues, eConstraints.getFirstChild());	
				}
			}
			XMLUtil.removeAllChildren(eInitialDualValues);
			int iCons = initialLbDualValues==null?0:initialLbDualValues.length;
			if(iCons <= 0) iCons = initialUbDualValues==null?0:initialUbDualValues.length;
			if(iCons == 0) return true;
			int nCon = 0;
			for(int i = 0; i < iCons; i++){
				Element eCon = m_document.createElement("con");	
				eCon.setAttribute("idx", i+"");
				eCon.setAttribute("lbDualValue", initialLbDualValues[i]+"");
				eCon.setAttribute("ubDualValue", initialUbDualValues[i]+"");
				eInitialDualValues.appendChild(eCon);				
				nCon++;
			}
			eInitialDualValues.setAttribute("numberOfCon", nCon+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setInitDualValuesDense

	/**
	 * Set initial dual values (InitDualVarValue[]). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods are recommended  to be called first. 
	 * @param initialDualValues holds the initial dual values in sparse form (InitDualVarValue[]). 
	 * @return whether the initial dual values are set successfully or not. 
	 */
	public boolean setInitDualValuesSparse(InitDualVarValue[] initialDualValues){
		Node nodeRef = null;
		try{
			Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSoL, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.createElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "job");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
							}
							else{
								m_eOSoL.insertBefore(eOptimization, m_eOSoL.getFirstChild());
							}		
						}		
					}
				}
			}
			Element eConstraints = (Element)XMLUtil.findChildNode(eOptimization, "constraints");
			if(eConstraints == null){
				if(initialDualValues == null || initialDualValues.length <= 0){
					return true;
				}
				eConstraints = m_document.createElement("constraints");	
				Node nodeRef2 = null;
				nodeRef2 = XMLUtil.findChildNode(eOptimization, "objectives");
				if(nodeRef2 != null){
					eOptimization.insertBefore(eConstraints, nodeRef2.getNextSibling());			
				}
				else{
					nodeRef2 = XMLUtil.findChildNode(eOptimization, "variables");
					if(nodeRef2 != null){
						eOptimization.insertBefore(eConstraints, nodeRef2.getNextSibling());			
					}
					else{
						eOptimization.insertBefore(eConstraints, eOptimization.getFirstChild());		
					}	
				}
			}
			Element eInitialDualValues = (Element)XMLUtil.findChildNode(eConstraints, "initialDualValues");
			if(eInitialDualValues == null){
				if(initialDualValues == null || initialDualValues.length <= 0){
					return true;
				}
				eInitialDualValues = m_document.createElement("initialDualValues");	
				Node nodeRef3 = null;
				nodeRef3 = XMLUtil.findChildNode(eConstraints, "initialConstraintValues");
				if(nodeRef3 != null){
					eConstraints.insertBefore(eInitialDualValues, nodeRef3.getNextSibling());			
				}
				else{
					eConstraints.insertBefore(eInitialDualValues, eConstraints.getFirstChild());	
				}
			}
			XMLUtil.removeAllChildren(eInitialDualValues);
			int iCons = initialDualValues==null?0:initialDualValues.length;
			if(iCons == 0) return true;
			int nCon = 0;
			for(int i = 0; i < iCons; i++){
				if(initialDualValues[i] == null) continue;
				Element eCon = m_document.createElement("con");	
				eCon.setAttribute("idx", initialDualValues[i].idx+"");
				eCon.setAttribute("lbDualValue", initialDualValues[i].lbValue+"");
				eCon.setAttribute("ubDualValue", initialDualValues[i].ubValue+"");
				eInitialDualValues.appendChild(eCon);				
				nCon++;
			}
			eInitialDualValues.setAttribute("numberOfCon", nCon+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setInitDualValuesSparse

	/**
	 * Set the number of other constraint options. 
	 * 
	 * @param numberOfOtherConstraintOptions holds the number of other constraint options
	 * @return whether the number is set successfully or not. 
	 */
	public boolean setNumberOfOtherConstraintOptions(int numberOfOtherConstraintOptions){
		Node nodeRef = null;
		if(numberOfOtherConstraintOptions < 0){
			return true;
		}
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSoL, "optimization");
		if(eOptimization == null){
			eOptimization = m_document.createElement("optimization");
			nodeRef = XMLUtil.findChildNode(m_eOSoL, "job");
			if(nodeRef != null){
				m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							m_eOSoL.insertBefore(eOptimization, m_eOSoL.getFirstChild());
						}		
					}		
				}
			}
		}
		Element eConstraints = (Element)XMLUtil.findChildNode(eOptimization, "constraints");
		if(eConstraints == null){
			eConstraints = m_document.createElement("constraints");	
			Node nodeRef2 = null;
			nodeRef2 = XMLUtil.findChildNode(eOptimization, "objectives");
			if(nodeRef2 != null){
				eOptimization.insertBefore(eConstraints, nodeRef2.getNextSibling());			
			}
			else{
				nodeRef2 = XMLUtil.findChildNode(eOptimization, "variables");
				if(nodeRef2 != null){
					eOptimization.insertBefore(eConstraints, nodeRef2.getNextSibling());			
				}
				else{
					eOptimization.insertBefore(eConstraints, eOptimization.getFirstChild());									
				}
			}
		}
		try{
			eConstraints.setAttribute("numberOfOtherConstraintOptions", numberOfOtherConstraintOptions+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;	
	}//setNumberOfOtherConstraintOptions

	/**
	 * Add another constraint option element. 
	 * 
	 * @param name holds the name of the option element. It is required.
	 * @param value holds the value of the option element, empty string "" or null if none. 
	 * @param description holds the description of the option element, empty string "" or null if none. 
	 * @param solver holds the solver of the option element, empty string "" or null if no value. 
	 * @param category holds the category of the option element, empty string "" or null if no value. 
	 * @param type holds the type of the option element, empty string "" or null if no value. 
	 * @param cons holds an array of con options
	 * @return whether the other constraint option element is added successfully.
	 */
	public boolean addOtherConstraintOption(String name, String value, String description, String solver, String category, String type, OtherConOption[] cons){
		Node nodeRef = null;
		try{
			Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSoL, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.createElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "job");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
							}
							else{
								m_eOSoL.insertBefore(eOptimization, m_eOSoL.getFirstChild());
							}		
						}		
					}
				}
			}
			Element eConstraints = (Element)XMLUtil.findChildNode(eOptimization, "constraints");
			if(eConstraints == null){
				if(name == null || name.length() <= 0){
					return true;
				}
				eConstraints = m_document.createElement("constraints");	
				Node nodeRef2 = null;
				nodeRef2 = XMLUtil.findChildNode(eOptimization, "objectives");
				if(nodeRef2 != null){
					eOptimization.insertBefore(eConstraints, nodeRef2.getNextSibling());			
				}
				else{
					nodeRef2 = XMLUtil.findChildNode(eOptimization, "variables");
					if(nodeRef2 != null){
						eOptimization.insertBefore(eConstraints, nodeRef2.getNextSibling());			
					}
					else{
						eOptimization.insertBefore(eConstraints, eOptimization.getFirstChild());		
					}	
				}
			}
			Element eOtherOption = m_document.createElement("other");	
			eOtherOption.setAttribute("name", name);
			if(value != null && value.length() > 0){
				eOtherOption.setAttribute("value", value);
			}
			if(description != null && description.length() > 0){
				eOtherOption.setAttribute("description", description);
			}
			if(solver != null && solver.length() > 0){
				eOtherOption.setAttribute("solver", solver);
			}
			if(category != null && category.length() > 0){
				eOtherOption.setAttribute("category", category);
			}
			if(type != null && type.length() > 0){
				if(type.equalsIgnoreCase("double") || type.equalsIgnoreCase("integer") || 
						type.equalsIgnoreCase("boolean") || type.equalsIgnoreCase("string")){
					eOtherOption.setAttribute("type",type.toLowerCase());
				}
				else eOtherOption.setAttribute("type","string");
			}
			int iCons = cons==null?0:cons.length;
			eOtherOption.setAttribute("numberOfCon", iCons+"");
			for(int i = 0; i < iCons; i++){
				Element eCon = m_document.createElement("con");	
				eCon.setAttribute("idx", cons[i].idx+"");
				if(cons[i].value != null && cons[i].value.length() > 0) eCon.setAttribute("value", cons[i].value+"");
				if(cons[i].lbValue != null && cons[i].lbValue.length() > 0) eCon.setAttribute("lbValue", cons[i].lbValue+"");
				if(cons[i].ubValue != null && cons[i].ubValue.length() > 0) eCon.setAttribute("ubValue", cons[i].ubValue+"");
				eOtherOption.appendChild(eCon);				
			}
			try{
				Vector<Element> vElements = XMLUtil.getChildElementsByTagName(eConstraints, "other");
				Element eOther;
				int iNls = vElements==null?0:vElements.size();
				for(int i = 0; i < iNls; i++){
					eOther = (Element)vElements.elementAt(i);
					if(eOther.getAttribute("name").equals(name)){
						eConstraints.removeChild(eOther);
						iNls--;
					}
				}
				eConstraints.appendChild(eOtherOption);			
				eConstraints.setAttribute("numberOfOtherConstraintOptions", (iNls+1)+"");

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
	}//addOtherConstraintOption	

	/**
	 * Set the number of other solver options. 
	 * 
	 * @param numberOfOtherSolverOptions holds the number of other solver options
	 * @return whether the number is set successfully or not. 
	 */
	public boolean setNumberOfSolverOptions(int numberOfSolverOptions){
		Node nodeRef = null;
		if(numberOfSolverOptions < 0){
			return true;
		}
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSoL, "optimization");
		if(eOptimization == null){
			eOptimization = m_document.createElement("optimization");
			nodeRef = XMLUtil.findChildNode(m_eOSoL, "job");
			if(nodeRef != null){
				m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							m_eOSoL.insertBefore(eOptimization, m_eOSoL.getFirstChild());
						}		
					}		
				}
			}
		}
		Element eSolverOptions = (Element)XMLUtil.findChildNode(eOptimization, "solverOptions");
		if(eSolverOptions == null){
			eSolverOptions = m_document.createElement("solverOptions");	
			eOptimization.appendChild(eSolverOptions);				
		}
		try{
			eSolverOptions.setAttribute("numberOfSolverOptions", numberOfSolverOptions+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;	
	}//setNumberOfSolverOptions

	/**
	 * Set the solver options. 
	 * 
	 * @param names holds the names of the solver options. It is required. 
	 * @param values holds the values of the solver options, empty string "" or null if no value for an option.
	 * @param descriptions holds the descriptions of the solver options, empty string "" or null if no value for an option, null for
	 * the entire array if none of the options have descriptions.
	 * @param solvers holds the solvers of the solver options, empty string "" or null if no value for an option, null for
	 * the entire array if none of the options have solvers.
	 * @param categories holds the categories of the solver options, empty string "" or null if no value for an option, null for
	 * the entire array if none of the options have categories.
	 * @param types holds the types of the solver options, empty string "" or null if no value for an option, null for
	 * the entire array if none of the options have types.
	 * @return whether the solver options element construction is successful.
	 */
	public boolean setSolverOptions(String[] names, String[] values, String[] descriptions, String[] solvers, String[] categories, String[] types){
		if(names == null) return false;
		if(values == null) return false;
		if(names.length != values.length) return false;
		if(descriptions != null && names.length != descriptions.length) return false;
		for(int i = 0; i < names.length; i++){
			addSolverOption(names[i], values[i], (descriptions==null)?"":descriptions[i], (solvers==null)?"":solvers[i], (categories==null)?"":categories[i], (types==null)?"":types[i]);
		}
		return true;
	}//setSolverOptions

	/**
	 * Add a solver option element. 
	 * 
	 * @param name holds the name of the solver option element. It is required.
	 * @param value holds the value of the solver option element, empty string "" or null if none. 
	 * @param description holds the description of the solver option element, empty string "" or null if none. 
	 * @param solver holds the solver of the solverOption element, empty string "" or null if no value. 
	 * @param category holds the category of the solverOption element, empty string "" or null if no value. 
	 * @param type holds the type of the solverOption element, empty string "" or null if no value. 
	 * @return whether the solver option element is added successfully.
	 */
	public boolean addSolverOption(String name, String value, String description, String solver, String category, String type){
		Node nodeRef = null;
		if(name == null || name.trim().length() <= 0) return false;
		try{
			Element eOptimization = (Element)XMLUtil.findChildNode(m_eOSoL, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.createElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "job");
				if(nodeRef != null){
					m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.insertBefore(eOptimization, nodeRef.getNextSibling());			
							}
							else{
								m_eOSoL.insertBefore(eOptimization, m_eOSoL.getFirstChild());
							}		
						}		
					}
				}
			}
			Element eSolverOptions = (Element)XMLUtil.findChildNode(eOptimization, "solverOptions");
			if(eSolverOptions == null){
				eSolverOptions = m_document.createElement("solverOptions");	
				eOptimization.appendChild(eSolverOptions);				
			}
			try{
				Vector<Element> vElements = XMLUtil.getChildElementsByTagName(eSolverOptions, "solverOption");
				Element eSolverOption;
				int iNls = vElements==null?0:vElements.size();
				for(int i = 0; i < iNls; i++){
					eSolverOption = (Element)vElements.elementAt(i);
					if(eSolverOption.getAttribute("name").equals(name)){
						eSolverOptions.removeChild(eSolverOption);
						iNls--;
						break;
					}
				}
				eSolverOption = m_document.createElement("solverOption");
				eSolverOption.setAttribute("name", name);
				if(value != null && value.length() > 0){
					eSolverOption.setAttribute("value", value);
				}
				if(description != null && description.length() > 0){
					eSolverOption.setAttribute("description", description);
				}
				if(solver != null && solver.length() > 0){
					eSolverOption.setAttribute("solver", solver);
				}
				if(category != null && category.length() > 0){
					eSolverOption.setAttribute("category", category);
				}
				if(type != null && type.length() > 0){
					if(type.equalsIgnoreCase("double") || type.equalsIgnoreCase("integer") || 
							type.equalsIgnoreCase("boolean") || type.equalsIgnoreCase("string")){
						eSolverOption.setAttribute("type",type.toLowerCase());
					}
					else eSolverOption.setAttribute("type","string");
				}				
				eSolverOptions.appendChild(eSolverOption);

				eSolverOptions.setAttribute("numberOfSolverOptions", (iNls+1)+"");

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
	}//addSolverOption

	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		OSoLWriter osolWriter = new OSoLWriter();
//		String sFileName = OSParameter.CODE_HOME + "OSRepository/test/osol/osol.osol";
//		String sFileName = "c:/test.osol";
//		if(!osolWriter.setServiceName("my service name")) System.out.println("service name");
//		if(!osolWriter.setServiceURI("my service uri")) System.out.println("uri");
//		if(!osolWriter.setInstanceName("instanceName")) System.out.println("setInstanceName Unsuccessful");		
//		if(!osolWriter.setInstanceLocation("instanceLocation")) System.out.println("setInstanceLocation Unsuccessful");		
//		if(!osolWriter.setInstanceLocationType("http")) System.out.println("setInstanceLocationType Unsuccessful");		
//		if(!osolWriter.setJobID("jobID")) System.out.println("setJobID Unsuccessful");		
//		if(!osolWriter.setSolverToInvoke("solverToInvoke")) System.out.println("setSolverToInvoke Unsuccessful");		
//		if(!osolWriter.setLicense("license")) System.out.println("setLicense Unsuccessful");		
//		if(!osolWriter.setUserName("userName")) System.out.println("setUserName Unsuccessful");		
//		if(!osolWriter.setPassword("password")) System.out.println("setPassword Unsuccessful");		
//		if(!osolWriter.setContactTransportType("smtp")) System.out.println("setContactTransportType Unsuccessful");		
//		if(!osolWriter.setContact("contactAddress")) System.out.println("setContactAddress Unsuccessful");		
//		if(!osolWriter.setNumberOfOtherGeneralOptions(0)) System.out.println("setNumberOfOtherGeneralOptions");		
//		if(!osolWriter.addOtherGeneralOption("gname0", null, "")) System.out.println("addOtherGeneralOption");		
//		String[] msNames = {"gname1", "gname2"};
//		String[] msValues = {"gvalue1", "gvalue2"};
//		String[] msDescs = {"gdesc1", "gdesc2"};
//		if(!osolWriter.setOtherGeneralOptions(msNames, msValues, msDescs)) System.out.println("setOtherGeneralOptions");		
//		if(!osolWriter.setOtherGeneralOptions(msNames, msValues, null)) System.out.println("setOtherGeneralOptions");		
//		if(!osolWriter.addOtherGeneralOption("gname1", null, "")) System.out.println("addOtherGeneralOption");		

//		if(!osolWriter.setMinDiskSpace(10)) System.out.println("setMinDiskSpace Unsuccessful");		
//		if(!osolWriter.setMinDiskSpaceUnit("kilobyte")) System.out.println("setMinDiskSpaceUnit Unsuccessful");		
//		if(!osolWriter.setMinMemorySize(20)) System.out.println("setMinMemorySize Unsuccessful");		
//		if(!osolWriter.setMinMemorySizeUnit("megabyte")) System.out.println("setMinMemorySizeUnit Unsuccessful");		
//		if(!osolWriter.setMinCPUSpeed(30)) System.out.println("setMinCPUSpeed Unsuccessful");		
//		if(!osolWriter.setMinCPUSpeedUnit("hertz")) System.out.println("setMinCPUSpeedUnit Unsuccessful");		
//		if(!osolWriter.setMinCPUNumber(1)) System.out.println("setMinCPUNumber Unsuccessful");		
//		if(!osolWriter.setNumberOfOtherSystemOptions(0)) System.out.println("setNumberOfOtherSystemOptions");		
//		if(!osolWriter.addOtherSystemOption("sname0", null, "")) System.out.println("addOtherSystemOption");		
//		String[] msNames = {"sname1", "sname2"};
//		String[] msValues = {"svalue1", "svalue2"};
//		String[] msDescs = {"sdesc1", "sdesc2"};
//		if(!osolWriter.setOtherSystemOptions(msNames, msValues, msDescs)) System.out.println("setOtherSystemOptions");		
//		if(!osolWriter.setOtherSystemOptions(msNames, msValues, null)) System.out.println("setOtherSystemOptions");		
//		if(!osolWriter.addOtherSystemOption("sname1", null, "")) System.out.println("addOtherSystemOption");		

//		if(!osolWriter.setServiceType("solver")) System.out.println("setServiceType Unsuccessful");		
//		if(!osolWriter.setNumberOfOtherServiceOptions(0)) System.out.println("setNumberOfOtherServiceOptions");		
//		if(!osolWriter.addOtherServiceOption("sname0", null, "")) System.out.println("addOtherServiceOption");		
//		String[] msNames = {"sname1", "sname2"};
//		String[] msValues = {"svalue1", "svalue2"};
//		String[] msDescs = {"sdesc1", "sdesc2"};
//		if(!osolWriter.setOtherServiceOptions(msNames, msValues, msDescs)) System.out.println("setOtherServiceOptions");		
//		if(!osolWriter.setOtherServiceOptions(msNames, msValues, null)) System.out.println("setOtherServiceOptions");		
//		if(!osolWriter.addOtherServiceOption("sname1", null, "")) System.out.println("addOtherServiceOption");		

//		if(!osolWriter.setMaxTime(9999)) System.out.println("setJobMaxTime Unsuccessful");		
//		if(!osolWriter.setMaxTimeUnit("second")) System.out.println("setMaxTimeUnit Unsuccessful");		
//		if(!osolWriter.setScheduledStartTime(new GregorianCalendar(1970, 0, 1, 0, 0, 0))) System.out.println("setJobScheduledStartTime Unsuccessful");		
//		String[] jobDependencies = {"a1", "b3"};
//		if(!osolWriter.setJobDependencies(jobDependencies)) System.out.println("setJobDependencies Unsuccessful");		
//		String[] mDirpaths = {"dp1", "dp3"};
//		if(!osolWriter.setRequiredDirectories(mDirpaths)) System.out.println("setRequiredDirectories Unsuccessful");		
//		String[] mFilepaths = {"fp1", "fp3"};
//		if(!osolWriter.setRequiredFiles(mFilepaths)) System.out.println("setRequiredFiles Unsuccessful");		
//		String[] mDirpaths = {"dp2", "dp4"};
//		if(!osolWriter.setDirectoriesToMake(mDirpaths)) System.out.println("setDirectoriesToMake Unsuccessful");		
//		String[] mFilepaths = {"fp2", "fp4"};
//		if(!osolWriter.setFilesToMake(mFilepaths)) System.out.println("setFilesToMake Unsuccessful");		
//		PathPair[] pathPairs = new PathPair[2];
//		pathPairs[0] = new PathPair(); pathPairs[0].from = "from1"; pathPairs[0].to = "to1"; pathPairs[0].makeCopy=false;
//		pathPairs[1] = new PathPair();pathPairs[1].from = "from2"; pathPairs[1].to = "to2"; pathPairs[1].makeCopy=true;
//		if(!osolWriter.setInputDirectoriesToMove(pathPairs)) System.out.println("setInputDirectoriesToMove Unsuccessful");		
//		if(!osolWriter.setInputFilesToMove(pathPairs)) System.out.println("setInputFilesToMove Unsuccessful");		
//		if(!osolWriter.setOutputDirectoriesToMove(pathPairs)) System.out.println("setOutputDirectoriesToMove Unsuccessful");		
//		if(!osolWriter.setOutputFilesToMove(pathPairs)) System.out.println("setOutputFilesToMove Unsuccessful");		
//		String[] mDirpaths = {"dp7", "dp8"};
//		if(!osolWriter.setDirectoriesToDelete(mDirpaths)) System.out.println("setDirectoriesToDelete Unsuccessful");		
//		String[] mFilepaths = {"fp7", "fp8"};
//		if(!osolWriter.setFilesToDelete(mFilepaths)) System.out.println("setFilesToDelete Unsuccessful");		
//		String[] mProcesses = {"proc1", "proc2"};
//		if(!osolWriter.setProcessesToKill(mProcesses)) System.out.println("setProcessesToKill Unsuccessful");		
//		if(!osolWriter.setNumberOfOtherJobOptions(0)) System.out.println("setNumberOfOtherJobOptions");		
//		if(!osolWriter.addOtherJobOption("jname0", null, "")) System.out.println("addOtherJobOption");		
//		String[] msNames = {"jname1", "jname2"};
//		String[] msValues = {"jvalue1", "jvalue2"};
//		String[] msDescs = {"jdesc1", "jdesc2"};
//		if(!osolWriter.setOtherJobOptions(msNames, msValues, msDescs)) System.out.println("setOtherJobOptions");		
//		if(!osolWriter.setOtherJobOptions(msNames, msValues, null)) System.out.println("setOtherJobOptions");		
//		if(!osolWriter.addOtherJobOption("jname1", null, "")) System.out.println("addOtherJobOption");		

//		if(!osolWriter.setNumberOfVariables(3)) System.out.println("setNumberOfVariables Unsuccessful");		
//		if(!osolWriter.setNumberOfObjectives(3)) System.out.println("setNumberOfObjectives Unsuccessful");		
//		if(!osolWriter.setNumberOfConstraints(2)) System.out.println("setNumberOfConstraints Unsuccessful");		

//		double[] initialVariableValues = {1, 0, 3};
//		if(!osolWriter.setInitVarValuesDense(initialVariableValues)) System.out.println("setInitVarValuesDense Unsuccessful");		

//		InitVarValue[] var = new InitVarValue[3];
//		var[0]= new InitVarValue(); var[0].idx=0; var[0].value=0.1;
//		var[1]= new InitVarValue(); var[1].idx=1; var[1].value=1.1;
//		var[2]= new InitVarValue(); var[2].idx=2; var[2].value=2.2;
//		if(!osolWriter.setInitVarValuesSparse(var)) System.out.println("setInitVarValuesSparse Unsuccessful");		

//		String[] initialVariableValuesString = {"1", "0", "3"};
//		if(!osolWriter.setInitVarValuesStringDense(initialVariableValuesString)) System.out.println("setInitVarValuesStringDense Unsuccessful");		

//		InitVarValueString[] var = new InitVarValueString[3];
//		var[0]= new InitVarValueString(); var[0].idx=0; var[0].value="0.1";
//		var[1]= new InitVarValueString(); var[1].idx=1; var[1].value="1.1";
//		var[2]= new InitVarValueString(); var[2].idx=2; var[2].value="2.2";
//		if(!osolWriter.setInitVarValuesStringSparse(var)) System.out.println("setInitVarValuesStringSparse Unsuccessful");		

//		String[] initialBasisStatus = {"basic", "unknown", "atLower"};
//		if(!osolWriter.setInitBasisStatusDense(initialBasisStatus)) System.out.println("setInitBasisStatusDense Unsuccessful");		

//		InitBasStatus[] var = new InitBasStatus[3];
//		var[0]= new InitBasStatus(); var[0].idx=0; var[0].value="unknown";
//		var[1]= new InitBasStatus(); var[1].idx=1; var[1].value="basic";
//		var[2]= new InitBasStatus(); var[2].idx=2; var[2].value="atLower";
//		if(!osolWriter.setInitBasisStatusSparse(var)) System.out.println("setInitBasisStatusSparse Unsuccessful");		
//		if(!osolWriter.setNumberOfOtherVariableOptions(1)) System.out.println("setNumberOfOtherVariableOptions");		

//		double[] integerVariableBranchingWeights = {1.0, 0, 3.0};
//		if(!osolWriter.setIntegerVariableBranchingWeightsDense(integerVariableBranchingWeights)) System.out.println("setIntegerVariableBranchingWeightsDense Unsuccessful");		

//		BranchingWeight[] var = new BranchingWeight[3];
//		var[0]= new BranchingWeight(); var[0].idx=0; var[0].value=0.1;
//		var[1]= new BranchingWeight(); var[1].idx=1; var[1].value=1.1;
//		var[2]= new BranchingWeight(); var[2].idx=2; var[2].value=2.2;
//		if(!osolWriter.setIntegerVariableBranchingWeightsSparse(var)) System.out.println("setIntegerVariableBranchingWeightsSparse Unsuccessful");		

//		BranchingWeight[] var = new BranchingWeight[3];
//		var[0]= new BranchingWeight(); var[0].idx=0; var[0].value=0.1;
//		var[1]= new BranchingWeight(); var[1].idx=1; var[1].value=1.1;
//		var[2]= new BranchingWeight(); var[2].idx=2; var[2].value=2.2;
//		if(!osolWriter.addSOSVariableBranchingWeightsForOneSOS(1, 2.0, var)) System.out.println("addSOSVariableBranchingWeightsForOneSOS Unsuccessful");		
//		if(!osolWriter.addSOSVariableBranchingWeightsForOneSOS(2, 1.0, var)) System.out.println("addSOSVariableBranchingWeightsForOneSOS Unsuccessful");		

//		OtherVarOption[] vars = new OtherVarOption[3];
//		vars[0]= new OtherVarOption(); vars[0].idx=0; vars[0].value="0.1"; vars[0].lbValue="0.1L";  vars[0].ubValue="0.1U";
//		vars[1]= new OtherVarOption(); vars[1].idx=1; vars[1].value="1.1"; vars[0].lbValue="0.1L";  vars[0].ubValue="0.1U";
//		vars[2]= new OtherVarOption(); vars[2].idx=2; vars[2].value="2.2"; vars[0].lbValue="0.1L";  vars[0].ubValue="0.1U";
//		if(!osolWriter.addOtherVariableOption("ovname0", null, "", "solver0", "category0", "double", vars)) System.out.println("addOtherVariableOption");		
//		if(!osolWriter.addOtherVariableOption("ovname1", null, "", "solver0", "category0", "Boolean", vars)) System.out.println("addOtherVariableOption");		
//		if(!osolWriter.addOtherVariableOption("ovname0", null, "", "solver0", "category0", "Boolean", null)) System.out.println("addOtherVariableOption");		

//		if(!osolWriter.setNumberOfOtherObjectiveOptions(2)) System.out.println("setNumberOfOtherObjectiveOptions");		
//		double[] initialObjectiveValues = {1, 0, 3};
//		if(!osolWriter.setInitObjValuesDense(initialObjectiveValues)) System.out.println("setInitObjValuesDense Unsuccessful");		

//		InitObjValue[] obj = new InitObjValue[3];
//		obj[0]= new InitObjValue(); obj[0].idx=-1; obj[0].value=0.0;
//		obj[1]= new InitObjValue(); obj[1].idx=-2; obj[1].value=1.1;
//		obj[2]= new InitObjValue(); obj[2].idx=-3; obj[2].value=2.2;
//		if(!osolWriter.setInitObjValuesSparse(obj)) System.out.println("setInitObjValuesSparse Unsuccessful");		

//		double[] initialObjectiveLbBounds = {1, 0, 3};
//		double[] initialObjectiveUbBounds = {1.1, 0.1, 3.1};
//		if(!osolWriter.setInitObjBoundsDense(initialObjectiveLbBounds, initialObjectiveUbBounds)) System.out.println("setInitObjBoundsDense Unsuccessful");		

//		InitObjBound[] obj = new InitObjBound[3];
//		obj[0]= new InitObjBound(); obj[0].idx=-1; obj[0].lbValue=0.0; obj[0].ubValue=0.1;
//		obj[1]= new InitObjBound(); obj[1].idx=-2; obj[1].lbValue=1.0;obj[1].ubValue=1.1;
//		obj[2]= new InitObjBound(); obj[2].idx=-3; obj[2].lbValue=2.0;obj[2].ubValue=2.1;
//		if(!osolWriter.setInitObjBoundsSparse(obj)) System.out.println("setInitObjBoundsSparse Unsuccessful");		

//		OtherObjOption[] objs = new OtherObjOption[3];
//		objs[0]= new OtherObjOption(); objs[0].idx=-1; objs[0].value="0.1"; objs[0].lbValue="0.1L";  objs[0].ubValue="0.1U";
//		objs[1]= new OtherObjOption(); objs[1].idx=-2; objs[1].value="1.1"; objs[0].lbValue="0.1L";  objs[0].ubValue="0.1U";
//		objs[2]= new OtherObjOption(); objs[2].idx=-3; objs[2].value="2.2"; objs[0].lbValue="0.1L";  objs[0].ubValue="0.1U";
//		if(!osolWriter.addOtherObjectiveOption("obname0", null, "", "solver0", "category0", "double", objs)) System.out.println("addOtherObjectiveOption");		
//		if(!osolWriter.addOtherObjectiveOption("obname1", null, "", "solver0", "category0", "Boolean", objs)) System.out.println("addOtherObjectiveOption");		
//		if(!osolWriter.addOtherObjectiveOption("obname0", null, "", "solver0", "category0", "Boolean", null)) System.out.println("addOtherObjectiveOption");		

//		double[] initialConstraintValues = {1, 0, 3};
//		if(!osolWriter.setInitConValuesDense(initialConstraintValues)) System.out.println("setInitConValuesDense Unsuccessful");		

//		InitConValue[] con = new InitConValue[3];
//		con[0]= new InitConValue(); con[0].idx=0; con[0].value=0.0;
//		con[1]= new InitConValue(); con[1].idx=1; con[1].value=1.1;
//		con[2]= new InitConValue(); con[2].idx=2; con[2].value=2.2;
//		if(!osolWriter.setInitConValuesSparse(con)) System.out.println("setInitConValuesSparse Unsuccessful");		

//		double[] initialLbDualBounds = {1, 0, 3};
//		double[] initialUbDualBounds = {1.1, 0.1, 3.1};
//		if(!osolWriter.setInitDualValuesDense(initialLbDualBounds, initialUbDualBounds)) System.out.println("setInitDualValuesDense Unsuccessful");		

//		InitDualVarValue[] con = new InitDualVarValue[3];
//		con[0]= new InitDualVarValue(); con[0].idx=0; con[0].lbValue=0.0; con[0].ubValue=0.1;
//		con[1]= new InitDualVarValue(); con[1].idx=1; con[1].lbValue=1.0;con[1].ubValue=1.1;
//		con[2]= new InitDualVarValue(); con[2].idx=2; con[2].lbValue=2.0;con[2].ubValue=2.1;
//		if(!osolWriter.setInitDualValuesSparse(con)) System.out.println("setInitDualValuesSparse Unsuccessful");		

//		if(!osolWriter.setNumberOfOtherConstraintOptions(3)) System.out.println("setNumberOfOtherConstraintOptions");		
//		OtherConOption[] cons = new OtherConOption[3];
//		cons[0]= new OtherConOption(); cons[0].idx=1; cons[0].value="0.1"; cons[0].lbValue="0.1L";  cons[0].ubValue="0.1U";
//		cons[1]= new OtherConOption(); cons[1].idx=2; cons[1].value="1.1"; cons[0].lbValue="0.1L";  cons[0].ubValue="0.1U";
//		cons[2]= new OtherConOption(); cons[2].idx=3; cons[2].value="2.2"; cons[0].lbValue="0.1L";  cons[0].ubValue="0.1U";
//		if(!osolWriter.addOtherConstraintOption("ocname0", null, "", "solver0", "category0", "double", cons)) System.out.println("addOtherObjectiveOption");		
//		if(!osolWriter.addOtherConstraintOption("ocname1", null, "", "solver0", "category0", "Boolean", cons)) System.out.println("addOtherObjectiveOption");		
//		if(!osolWriter.addOtherConstraintOption("ocname0", null, "", "solver0", "category0", "Boolean", null)) System.out.println("addOtherObjectiveOption");		

//		if(!osolWriter.setNumberOfSolverOptions(4)) System.out.println("setNumberOfSolverOptions");		
//		if(!osolWriter.addSolverOption("sname0", null, "", "solver0", "category0", "type0")) System.out.println("addSolverOption");		
//		String[] msNames = {"sname1", "sname2"};
//		String[] msValues = {"svalue1", "svalue2"};
//		String[] msDescs = {"sdesc1", "sdesc2"};
//		String[] msSolvers = {"ssolver1", "ssolver2"};
//		String[] msCats = {"scat1", "scat2"};
//		String[] msTypes = {"stype1", "stype2"};
//		if(!osolWriter.setSolverOptions(msNames, msValues, msDescs, msSolvers, msCats, msTypes)) System.out.println("setSolverOptions");		
//		if(!osolWriter.setSolverOptions(msNames, msValues, null, msSolvers, msCats, msTypes)) System.out.println("setSolverOptions");		
//		if(!osolWriter.addSolverOption("sname3", null, "", "solver1", "category1", "type1")) System.out.println("addSolverOption");		


		////////////////////

//		OSoLReader osolReader = new OSoLReader(false);
//		if(!osolReader.readFile(sFileName)) System.out.println("reading");
//		OSOption osOption;
//		try {
//		osOption = osolReader.getOSOption();
//		if(!osolWriter.setOSOption(osOption)) System.out.println("set osOption");
//		} 
//		catch (Exception e) {
//		e.printStackTrace();
//		}

		////////////////////

		System.out.println(osolWriter.writeToString());
	}//main

}//class OSoLWriter
