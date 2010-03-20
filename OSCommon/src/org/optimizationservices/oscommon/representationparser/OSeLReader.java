/**
 * @(#)OSeLReader 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.representationparser;
import java.util.Collection;
import java.util.GregorianCalendar;
import java.util.HashMap;
import java.util.Set;
import java.util.Vector;

import org.optimizationservices.oscommon.datastructure.osentity.AccessLimits;
import org.optimizationservices.oscommon.datastructure.osentity.Contact;
import org.optimizationservices.oscommon.datastructure.osentity.FunctionType;
import org.optimizationservices.oscommon.datastructure.osentity.HardwareInfo;
import org.optimizationservices.oscommon.datastructure.osentity.Link;
import org.optimizationservices.oscommon.datastructure.osentity.Owner;
import org.optimizationservices.oscommon.datastructure.osentity.SpecialAlgorithm;
import org.optimizationservices.oscommon.datastructure.osentity.SpecialStructure;
import org.optimizationservices.oscommon.localinterface.OSEntity;
import org.optimizationservices.oscommon.localinterface.OSOption;
import org.optimizationservices.oscommon.util.IOUtil;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.XMLUtil;
import org.w3c.dom.Element;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

/**
 * The <c>OSeLReader</c> class parses an OSeL instance into a DOM tree and
 * provides a set of "get" methods that can be used to retrieve different 
 * pieces of information of the instance.
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */
public class OSeLReader extends OSgLReader{
	/**
	 * m_osEntity holds the standard OSEntity, which is a local interface for 
	 * storing Optimization Services entity. 
	 */
	protected OSEntity m_osEntity = null;
		
	/**
	 * m_otherEntityInfoHashMap holds a hash map of other alalyses.
	 */
	protected HashMap<String, String>	m_otherEntityInfoHashMap = null;

	
	/**
	 * m_otherEntityDescriptionHashMap holds a hash map of other entity descriptions.
	 */
	protected HashMap<String, String>	m_otherEntityDescriptionHashMap = null;

	/**
	 * constructor.
	 * 
	 * @param validate holds whether the reader	should be validating against the schema	or not.
	 */
	public OSeLReader(boolean validate){
		m_bXsdValidate = validate;
	}//constructor
	
	/**
	 * Default	constructor. 
	 *
	 */
	public OSeLReader(){
	}//constructor
	
	/**
	 * get the standard OSEntity, a local interface for 
	 * storing Optimization Services entity.
	 * 
	 * @return the OSEntity. 
	 * @throws Exception if there are errors getting the OSEntity. 
	 */
   	public OSEntity getOSEntity() throws Exception{
		if(m_osEntity != null){
			return m_osEntity;
		}
		m_osEntity = new OSEntity();
		if(!m_osEntity.setServiceURI(getServiceURI())) throw new Exception("setServiceURI Unsuccessful");
		if(!m_osEntity.setServiceName(getServiceName())) throw new Exception("setServiceName Unsuccessful");
		if(!m_osEntity.setRegistrationDate(getRegistrationDate())) throw new Exception("setRegistrationDate Unsuccessful");
		if(!m_osEntity.setMessage(getMessage())) throw new Exception("setMessage Unsuccessful");
		if(!m_osEntity.setLicenseRequired(getLicenseRequired())) throw new Exception("setLicenseRequired Unsuccessful");
		if(!m_osEntity.setUserNameRequired(getUserNameRequired())) throw new Exception("setUserNameRequired Unsuccessful");
		if(!m_osEntity.setPasswordRequired(getPasswordRequired())) throw new Exception("setPasswordRequired Unsuccessful");
		if(!m_osEntity.setOwner(getOwner())) throw new Exception("setOwner Unsuccessful");
		if(!m_osEntity.setKeyWords(getKeyWords())) throw new Exception("setKeyWords Unsuccessful");
		if(!m_osEntity.setLinks(getLinks())) throw new Exception("setLinks Unsuccessful");
		if(!m_osEntity.setSystemDescription(getSystemDescription())) throw new Exception("setSystemDescription Unsuccessful");
		if(!m_osEntity.setSystemDedication(getSystemDedication())) throw new Exception("setSystemDedication Unsuccessful");
		if(!m_osEntity.setSystemHardwareInfo(getSystemHardwareInfo())) throw new Exception("setSystemHardwareInfo");
		if(!m_osEntity.setServiceDescription(getServiceDescription())) throw new Exception("setServiceDescription Unsuccessful");
		if(!m_osEntity.setServiceType(getServiceType())) throw new Exception("setServiceType Unsuccessful");
		if(!m_osEntity.setServiceCategory(getServiceCategory())) throw new Exception("setServiceCategory Unsuccessful");
		if(!m_osEntity.setServiceSoftwareDescription(getServiceSoftwareDescription())) throw new Exception("setServiceSoftwareDescription Unsuccessful");
		if(!m_osEntity.setServiceAlgorithmDescription(getServiceAlgorithmDescription())) throw new Exception("setServiceAlgorithmDescription Unsuccessful");
		if(!m_osEntity.setServiceWebPage(getServiceWebPage())) throw new Exception("setServiceWebPage Unsuccessful");
		if(!m_osEntity.setServiceWSDLLocation(getServiceWSDLLocation())) throw new Exception("setServiceWSDLLocation Unsuccessful");
		if(!m_osEntity.setServiceLogoImageLink(getServiceLogoImageLink())) throw new Exception("setServiceLogoImageLink Unsuccessful");
		if(!m_osEntity.setDefaultOptionNamesAndValues(getDefaultOptionNamesAndValues())) throw new Exception("setDefaultOptionNamesAndValues Unsuccessful");
		if(!m_osEntity.setOptimizationDescription(getOptimizationDescription())) throw new Exception("setOptimizationDescription Unsuccessful");
		if(!m_osEntity.setOptimizationVariableType(getOptimizationVariableType())) throw new Exception("setOptimizationVariableType Unsuccessful");
		if(!m_osEntity.setOptimizationObjectiveType(getOptimizationObjectiveType())) throw new Exception("setOptimizationObjectiveType Unsuccessful");
		if(!m_osEntity.setOptimizationConstraintType(getOptimizationConstraintType())) throw new Exception("setOptimizationConstraintType Unsuccessful");
		if(!m_osEntity.setOptimizationObjectiveLinearity(getOptimizationObjectiveLinearity())) throw new Exception("setOptimizationObjectiveLinearity Unsuccessful");
		if(!m_osEntity.setOptimizationConstraintLinearity(getOptimizationConstraintLinearity())) throw new Exception("setOptimizationConstraintLinearity Unsuccessful");
		if(!m_osEntity.setOptimizationObjectiveDifferentiability(getOptimizationObjectiveDifferentiability())) throw new Exception("setOptimizationObjectiveDifferentiability Unsuccessful");
		if(!m_osEntity.setOptimizationConstraintDifferentiability(getOptimizationConstraintDifferentiability())) throw new Exception("setOptimizationConstraintDifferentiability Unsuccessful");
		if(!m_osEntity.setOptimizationParameterType(getOptimizationParameterType())) throw new Exception("setOptimizationParameterType Unsuccessful");
		if(!m_osEntity.setOptimizationStochasticity(getOptimizationStochasticity())) throw new Exception("setOptimizationStochasticity Unsuccessful");
		if(!m_osEntity.setOptimizationRealTime(getOptimizationRealTime())) throw new Exception("setOptimizationRealTime Unsuccessful");
		if(!m_osEntity.setOptimizationFunctionType(getOptimizationFunctionType())) throw new Exception("setOptimizationFunctionType Unsuccessful");
		if(!m_osEntity.setOptimizationSpecialStructure(getOptimizationSpecialStructure())) throw new Exception("setOptimizationSpecialStructure Unsuccessful");
		if(!m_osEntity.setOptimizationSpecialAlgorithm(getOptimizationSpecialAlgorithm())) throw new Exception("setOptimizationSpecialAlgorithm Unsuccessful");
		if(!m_osEntity.setOtherEntityInfo(getOtherEntityInfoNames(), getOtherEntityDescriptions(), getOtherEntityInfoValues())) throw new Exception("setOtherEntityInfo Unsuccessful");
		return m_osEntity;
   	}//getOSEntity
   	
	/**
	 * Get the service uri.
	 * @return the service uri
	 */
	public String getServiceURI(){
		Element eEntityHeader = (Element)XMLUtil.findChildNode(m_eRoot, "entityHeader");
		String sServiceURI = XMLUtil.getElementValueByName(eEntityHeader, "serviceURI");
		if(sServiceURI == null) sServiceURI = "";
		return sServiceURI;	
	}//getServiceURI
	
	/**
	 * Get the service name.
	 * 
	 * @return the service name
	 */
	public String getServiceName(){
		Element eEntityHeader = (Element)XMLUtil.findChildNode(m_eRoot, "entityHeader");
		String sServiceName = XMLUtil.getElementValueByName(eEntityHeader, "serviceName");
		if(sServiceName == null) sServiceName = "";
		return sServiceName;
	}//getServiceName
	
   	/**
	 * Get time of the registration date.
	 * 
	 * @return the time of the registration date.
	 */
	public GregorianCalendar getRegistrationDate(){
		Element eEntityHeader = (Element)XMLUtil.findChildNode(m_eRoot, "entityHeader");
		String sRegistrationDate = XMLUtil.getElementValueByName(eEntityHeader, "registrationDate");
		if(sRegistrationDate == null) return null;
		GregorianCalendar date = XMLUtil.createNativeDateTime(sRegistrationDate);
		return date;
	}//getRegistrationDate
	
	
   	/**
	 * Get the message. 
	 * 
	 * @return the message. 
	 */
	public String getMessage(){
		Element eEntityHeader = (Element)XMLUtil.findChildNode(m_eRoot, "entityHeader");
		String sMessage = XMLUtil.getElementValueByName(eEntityHeader, "message");
		if(sMessage == null) sMessage = "";
		return sMessage;
	}//getMessage
	
	/**
	 * Get whether the license is reqired of the service or not. 
	 * 
	 * @return whether the license is reqired of the service or not. 
	 */
	public boolean getLicenseRequired(){
		Element eEntityData = (Element)XMLUtil.findChildNode(m_eRoot, "entityData");
		Element eGeneral = (Element)XMLUtil.findChildNode(eEntityData, "general");
		if(eGeneral == null) return false;
		Element eAccess = (Element)XMLUtil.findChildNode(eGeneral, "access");
		if(eAccess == null) return false;
		Element eType = (Element)XMLUtil.findChildNode(eAccess, "type");
		if(eType == null) return false;
		String sValue = eType.getAttribute("licenseRequired");
		if(sValue == null || sValue.length() <=0 || !sValue.startsWith("t")) return false;
		else return true;
	}//getLicenseRequired
	
	/**
	 * Get whether the user name is reqired of the service or not. 
	 * 
	 * @return whether the user name is reqired of the service or not. 
	 */
	public boolean getUserNameRequired(){
		Element eEntityData = (Element)XMLUtil.findChildNode(m_eRoot, "entityData");
		Element eGeneral = (Element)XMLUtil.findChildNode(eEntityData, "general");
		if(eGeneral == null) return false;
		Element eAccess = (Element)XMLUtil.findChildNode(eGeneral, "access");
		if(eAccess == null) return false;
		Element eType = (Element)XMLUtil.findChildNode(eAccess, "type");
		if(eType == null) return false;
		String sValue = eType.getAttribute("userNameRequired");
		if(sValue == null || sValue.length() <=0 || !sValue.startsWith("t")) return false;
		else return true;
	}//getUserNameRequired
	
	/**
	 * Get whether the password is reqired of the service or not. 
	 * 
	 * @return whether the password is reqired of the service or not. 
	 */
	public boolean getPasswordRequired(){
		Element eEntityData = (Element)XMLUtil.findChildNode(m_eRoot, "entityData");
		Element eGeneral = (Element)XMLUtil.findChildNode(eEntityData, "general");
		if(eGeneral == null) return false;
		Element eAccess = (Element)XMLUtil.findChildNode(eGeneral, "access");
		if(eAccess == null) return false;
		Element eType = (Element)XMLUtil.findChildNode(eAccess, "type");
		if(eType == null) return false;
		String sValue = eType.getAttribute("passwordRequired");
		if(sValue == null || sValue.length() <=0 || !sValue.startsWith("t")) return false;
		else return true;
	}//getPasswordRequired
	
	/**
	 * Get the access limits of the service. 
	 * 
	 * @return the access limits information of the service entity; null if none. 
	 */
	public AccessLimits getAccessLimits(){
		Element eEntityData = (Element)XMLUtil.findChildNode(m_eRoot, "entityData");
		Element eGeneral = (Element)XMLUtil.findChildNode(eEntityData, "general");
		if(eGeneral == null) return null;
		Element eAccess = (Element)XMLUtil.findChildNode(eGeneral, "access");
		if(eAccess == null) return null;
		Element eAccessLimits = (Element)XMLUtil.findChildNode(eAccess, "limits");
		if(eAccessLimits == null) return null;
		AccessLimits accessLimits = new AccessLimits();
		String sValue = "";		
		try {
			sValue = XMLUtil.getElementValueByName(eAccessLimits, "maxDiskSpace");
			if(sValue != null && sValue.length() > 0){
				double dValue = Double.parseDouble(sValue);
				accessLimits.maxDiskSpace = dValue;
			}	
		} 
		catch (Exception e) {
		}
		try {
			sValue = XMLUtil.getElementValueByName(eAccessLimits, "maxMemory");
			if(sValue != null && sValue.length() > 0){
				double dValue = Double.parseDouble(sValue);
				accessLimits.maxMemory = dValue;
			}	
		} 
		catch (Exception e) {
		}
		try {
			sValue = XMLUtil.getElementValueByName(eAccessLimits, "maxJobs");
			if(sValue != null && sValue.length() > 0){
				int iValue = Integer.parseInt(sValue);
				accessLimits.maxJobs = iValue;
			}	
		} 
		catch (Exception e) {
		}
		try {
			sValue = XMLUtil.getElementValueByName(eAccessLimits, "maxVariables");
			if(sValue != null && sValue.length() > 0){
				int iValue = Integer.parseInt(sValue);
				accessLimits.maxVariables = iValue;
			}	
		} 
		catch (Exception e) {
		}
		try {
			sValue = XMLUtil.getElementValueByName(eAccessLimits, "maxBinaryVariables");
			if(sValue != null && sValue.length() > 0){
				int iValue = Integer.parseInt(sValue);
				accessLimits.maxBinaryVariables = iValue;
			}	
		} 
		catch (Exception e) {
		}
		try {
			sValue = XMLUtil.getElementValueByName(eAccessLimits, "maxIntegerVariables");
			if(sValue != null && sValue.length() > 0){
				int iValue = Integer.parseInt(sValue);
				accessLimits.maxIntegerVariables = iValue;
			}	
		} 
		catch (Exception e) {
		}
		try {
			sValue = XMLUtil.getElementValueByName(eAccessLimits, "maxObjectives");
			if(sValue != null && sValue.length() > 0){
				int iValue = Integer.parseInt(sValue);
				accessLimits.maxObjectives = iValue;
			}	
		} 
		catch (Exception e) {
		}
		try {
			sValue = XMLUtil.getElementValueByName(eAccessLimits, "maxConstraints");
			if(sValue != null && sValue.length() > 0){
				int iValue = Integer.parseInt(sValue);
				accessLimits.maxConstraints = iValue;
			}	
		} 
		catch (Exception e) {
		}
		try {
			sValue = XMLUtil.getElementValueByName(eAccessLimits, "maxNonzeroLinearConstraintCoefficients");
			if(sValue != null && sValue.length() > 0){
				int iValue = Integer.parseInt(sValue);
				accessLimits.maxNonzeroLinearConstraintCoefficients = iValue;
			}	
		} 
		catch (Exception e) {
		}
		return accessLimits;
	}//getAccessLimits
	
	/**
	 * Get the owner information of the service entity. 
	 * 
	 * @return the owner information of the service entity; null if none. 
	 */
	public Owner getOwner(){
		Element eEntityData = (Element)XMLUtil.findChildNode(m_eRoot, "entityData");
		Element eGeneral = (Element)XMLUtil.findChildNode(eEntityData, "general");
		if(eGeneral == null) return null;
		Element eOwner = (Element)XMLUtil.findChildNode(eGeneral, "owner");
		if(eOwner == null) return null;
		String sValue = "";
		Owner owner = new Owner();
		sValue = XMLUtil.getElementValueByName(eOwner, "names");
		owner.names = sValue==null?"":sValue;
		sValue = XMLUtil.getElementValueByName(eOwner, "description");
		owner.description = sValue==null?"":sValue;
		sValue = XMLUtil.getElementValueByName(eOwner, "category");
		owner.category = sValue==null?"":sValue;
		sValue = XMLUtil.getElementValueByName(eOwner, "mainWebPage");
		owner.mainWebPage = sValue==null?"":sValue;
		sValue = XMLUtil.getElementValueByName(eOwner, "logoImageLink");
		owner.logoImageLink = sValue==null?"":sValue;
		Element eContact = (Element)XMLUtil.findChildNode(eOwner, "contact");
		if(eContact == null) return owner;
		owner.contact = new Contact();
		sValue = XMLUtil.getElementValueByName(eContact, "name");
		owner.contact.name = sValue==null?"":sValue;
		sValue = XMLUtil.getElementValueByName(eContact, "title");
		owner.contact.title = sValue==null?"":sValue;
		sValue = XMLUtil.getElementValueByName(eContact, "address");
		owner.contact.address = sValue==null?"":sValue;
		sValue = XMLUtil.getElementValueByName(eContact, "phone");
		owner.contact.phone = sValue==null?"":sValue;
		sValue = XMLUtil.getElementValueByName(eContact, "fax");
		owner.contact.fax = sValue==null?"":sValue;
		sValue = XMLUtil.getElementValueByName(eContact, "email");
		owner.contact.email = sValue==null?"":sValue;
		sValue = XMLUtil.getElementValueByName(eContact, "webPage");
		owner.contact.webPage = sValue==null?"":sValue;

		return owner;
	}//getOwner
	
	/**
	 * Get the key words of the service. 
	 * 
	 * @return the key words in a string array; null if none.  
	 */
	public String[] getKeyWords(){
		Element eEntityData = (Element)XMLUtil.findChildNode(m_eRoot, "entityData");
		Element eGeneral = (Element)XMLUtil.findChildNode(eEntityData, "general");
		if(eGeneral == null) return null;
		Element eKeyWords = (Element)XMLUtil.findChildNode(eGeneral, "keyWords");
		if(eKeyWords == null) return null;
		NodeList keys = eKeyWords.getElementsByTagName("key");
		if(keys == null || keys.getLength() <= 0) return null;
		int iKeys = keys.getLength();
		String[] msKeys = new String[iKeys];
		for(int i = 0; i < iKeys; i++){
			msKeys[i] = XMLUtil.getElementValue((Element)keys.item(i));
		}
		return msKeys;
	}//getKeyWords
	
	/**
	 * Get the links of the service. 
	 * 
	 * @return the links of the service; null if none. 
	 */
	public Link[] getLinks(){
		Element eEntityData = (Element)XMLUtil.findChildNode(m_eRoot, "entityData");
		Element eGeneral = (Element)XMLUtil.findChildNode(eEntityData, "general");
		if(eGeneral == null) return null;
		Element eLinks = (Element)XMLUtil.findChildNode(eGeneral, "links");
		if(eLinks == null) return null;
		NodeList links = eLinks.getElementsByTagName("link");
		if(links == null || links.getLength() <= 0) return null;
		int iLinks = links.getLength();
		Link[] mLinks = new Link[iLinks];
		String sValue = "";
		for(int i = 0; i < iLinks; i++){
			mLinks[i] = new Link();
			Element eLink = (Element)links.item(i);
			sValue = eLink.getAttribute("type");
			mLinks[i].type = sValue==null?"":sValue;
			sValue = eLink.getAttribute("description");
			mLinks[i].description = sValue==null?"":sValue;
			sValue = XMLUtil.getElementValue(eLink);
			mLinks[i].value = sValue==null?"":sValue;
		}
		return mLinks;
	}//getLinks
	
	/**
	 * Get the system description. 
	 * 
	 * @return the system description; null or empty string if none. 
	 */
	public String getSystemDescription(){
		Element eEntityData = (Element)XMLUtil.findChildNode(m_eRoot, "entityData");
		Element eSystem = (Element)XMLUtil.findChildNode(eEntityData, "system");
		if(eSystem == null) return "";
		String sDescription = XMLUtil.getElementValueByName(eSystem, "description");
		return sDescription==null?"":sDescription;
	}//getSystemDescription

	/**
	 * Get the system dedication, a double between 0 and 1 with 1 being fully dedicated. 
	 * 
	 * @return the system dedication; Double.NaN if none. 
	 */
	public double getSystemDedication(){
		Element eEntityData = (Element)XMLUtil.findChildNode(m_eRoot, "entityData");
		Element eSystem = (Element)XMLUtil.findChildNode(eEntityData, "system");
		if(eSystem == null) return Double.NaN;
		try {
			String sValue =  XMLUtil.getElementValueByName(eSystem, "dedication");
			if(sValue == null || sValue.length() <= 0) return Double.NaN;
			double dValue = Double.parseDouble(sValue);
			return dValue;
		} 
		catch (Exception e) {
			return Double.NaN;
		}
	}//getSystemDedication
	
	/**
	 * Get the system hardware information.  
	 * 
	 * @return the system hardware information; null if none. 
	 */
	public HardwareInfo getSystemHardwareInfo(){
		Element eEntityData = (Element)XMLUtil.findChildNode(m_eRoot, "entityData");
		Element eSystem = (Element)XMLUtil.findChildNode(eEntityData, "system");
		if(eSystem == null) return null;
		Element eHardware = (Element)XMLUtil.findChildNode(eSystem, "hardware");
		if(eHardware == null) return null;
		HardwareInfo hardwareInfo = new HardwareInfo();
		String sValue = "";
		int iValue;
		double dValue;
		try {
			sValue =  XMLUtil.getElementValueByName(eHardware, "cpuNumber");
			if(sValue != null && sValue.length() > 0){
				iValue = Integer.parseInt(sValue);
				hardwareInfo.cpuNumber = iValue;
			}
		} 
		catch (Exception e) {
			hardwareInfo.cpuNumber = 1;
		}
		try {
			sValue =  XMLUtil.getElementValueByName(eHardware, "cpuSpeed");
			if(sValue != null && sValue.length() > 0){
				dValue = Double.parseDouble(sValue);
				hardwareInfo.cpuSpeed = dValue;
			}
		} 
		catch (Exception e) {
			hardwareInfo.cpuSpeed = Double.NaN;
		}
		try {
			sValue =  XMLUtil.getElementValueByName(eHardware, "memorySize");
			if(sValue != null && sValue.length() > 0){
				dValue = Double.parseDouble(sValue);
				hardwareInfo.memorySize = dValue;
			}
		} 
		catch (Exception e) {
			hardwareInfo.memorySize = Double.NaN;
		}
		try {
			sValue =  XMLUtil.getElementValueByName(eHardware, "busSpeed");
			if(sValue != null && sValue.length() > 0){
				dValue = Double.parseDouble(sValue);
				hardwareInfo.busSpeed = dValue;
			}
		} 
		catch (Exception e) {
			hardwareInfo.busSpeed = Double.NaN;
		}
		try {
			sValue =  XMLUtil.getElementValueByName(eHardware, "diskSpace");
			if(sValue != null && sValue.length() > 0){
				dValue = Double.parseDouble(sValue);
				hardwareInfo.diskSpace = dValue;
			}
		} 
		catch (Exception e) {
			hardwareInfo.diskSpace = Double.NaN;
		}
		try {
			sValue =  XMLUtil.getElementValueByName(eHardware, "nicSpeed");
			if(sValue != null && sValue.length() > 0){
				dValue = Double.parseDouble(sValue);
				hardwareInfo.nicSpeed = dValue;
			}
		} 
		catch (Exception e) {
			hardwareInfo.nicSpeed = Double.NaN;
		}
		try {
			sValue =  XMLUtil.getElementValueByName(eHardware, "downloadSpeed");
			if(sValue != null && sValue.length() > 0){
				dValue = Double.parseDouble(sValue);
				hardwareInfo.downloadSpeed = dValue;
			}
		} 
		catch (Exception e) {
			hardwareInfo.downloadSpeed = Double.NaN;
		}
		try {
			sValue =  XMLUtil.getElementValueByName(eHardware, "uploadSpeed");
			if(sValue != null && sValue.length() > 0){
				dValue = Double.parseDouble(sValue);
				hardwareInfo.uploadSpeed = dValue;
			}
		} 
		catch (Exception e) {
			hardwareInfo.uploadSpeed = Double.NaN;
		}
		return hardwareInfo;
	}//getSystemHardwareInfo
	
	/**
	 * Get the service description.  
	 * 
	 * @return the service description; null or empty string if none. 
	 */
	public String getServiceDescription(){
		Element eEntityData = (Element)XMLUtil.findChildNode(m_eRoot, "entityData");
		Element eService = (Element)XMLUtil.findChildNode(eEntityData, "service");
		if(eService == null) return "";
		String sValue = XMLUtil.getElementValueByName(eService, "description");
		return sValue==null?"":sValue;
	}//getServiceDescription
	
	/**
	 * Get the service type, which can be: 
	 * solver, analyzer, scheduler, simulation, registry, modeler, agent 
	 * 
	 * @return the service type; null or empty string if none. 
	 */
	public String getServiceType(){
		Element eEntityData = (Element)XMLUtil.findChildNode(m_eRoot, "entityData");
		Element eService = (Element)XMLUtil.findChildNode(eEntityData, "service");
		if(eService == null) return "";
		String sValue = XMLUtil.getElementValueByName(eService, "type");
		return sValue==null?"":sValue;
	}//getServiceType
	
	/**
	 * Get the service category, which can be: 
	 * education, government, organization, company, military, personal, other
	 * 
	 * @return the service category; null or empty string if none. 
	 */
	public String getServiceCategory(){
		Element eEntityData = (Element)XMLUtil.findChildNode(m_eRoot, "entityData");
		Element eService = (Element)XMLUtil.findChildNode(eEntityData, "service");
		if(eService == null) return "";
		String sValue = XMLUtil.getElementValueByName(eService, "category");
		return sValue==null?"":sValue;
	}//getServiceCategory
	
	/**
	 * Get the service software description.  
	 * 
	 * @return the software description; null or empty string if none. 
	 */
	public String getServiceSoftwareDescription(){
		Element eEntityData = (Element)XMLUtil.findChildNode(m_eRoot, "entityData");
		Element eService = (Element)XMLUtil.findChildNode(eEntityData, "service");
		if(eService == null) return "";
		String sValue = XMLUtil.getElementValueByName(eService, "software");
		return sValue==null?"":sValue;
	}//getServiceSoftwareDescription
	
	/**
	 * Get the service algorithm description.  
	 * 
	 * @return the algorithm description; null or empty string if none. 
	 */
	public String getServiceAlgorithmDescription(){
		Element eEntityData = (Element)XMLUtil.findChildNode(m_eRoot, "entityData");
		Element eService = (Element)XMLUtil.findChildNode(eEntityData, "service");
		if(eService == null) return "";
		String sValue = XMLUtil.getElementValueByName(eService, "algorithm");
		return sValue==null?"":sValue;
	}//getServiceAlgorithmDescription

	/**
	 * Get the service web page.  
	 * 
	 * @return the service web page; null or empty string if none. 
	 */
	public String getServiceWebPage(){
		Element eEntityData = (Element)XMLUtil.findChildNode(m_eRoot, "entityData");
		Element eService = (Element)XMLUtil.findChildNode(eEntityData, "service");
		if(eService == null) return "";
		String sValue = XMLUtil.getElementValueByName(eService, "webPage");
		return sValue==null?"":sValue;
	}//getServiceWebPage
	
	/**
	 * Get the service wsdl location.  
	 * 
	 * @return the service wsdl location; null or empty string if none. 
	 */
	public String getServiceWSDLLocation(){
		Element eEntityData = (Element)XMLUtil.findChildNode(m_eRoot, "entityData");
		Element eService = (Element)XMLUtil.findChildNode(eEntityData, "service");
		if(eService == null) return "";
		String sValue = XMLUtil.getElementValueByName(eService, "wsdlLocation");
		return sValue==null?"":sValue;
	}//getServiceWSDLLocation
	
	/**
	 * Get the service logo image link.  
	 * 
	 * @return the service logo image link; null or empty string if none. 
	 */
	public String getServiceLogoImageLink(){
		Element eEntityData = (Element)XMLUtil.findChildNode(m_eRoot, "entityData");
		Element eService = (Element)XMLUtil.findChildNode(eEntityData, "service");
		if(eService == null) return "";
		String sValue = XMLUtil.getElementValueByName(eService, "logoImageLink");
		return sValue==null?"":sValue;
	}//getServiceLogoImageLink
	
	/**
	 * Get the default option names and values in the standard OSOption structure which 
	 * is specified by the OSoL schema. 
	 * 
	 * @return the default option names and values in the standard OSOption structure, null if none. 
	 */
	public OSOption getDefaultOptionNamesAndValues(){
		Element eEntityData = (Element)XMLUtil.findChildNode(m_eRoot, "entityData");
		Element eJob = (Element)XMLUtil.findChildNode(eEntityData, "job");
		if(eJob == null) return null;
		Element eOSoL = (Element)XMLUtil.findChildNode(eJob, "osol");
		if(eOSoL == null){
			return null;
		}
		OSoLReader osolReader = new OSoLReader(OSParameter.VALIDATE);
		osolReader.setRootElement(eOSoL);
		OSOption osOption;
		try {
			osOption = osolReader.getOSOption();
			return osOption;
		} 
		catch (Exception e){
			return null;
		}
	}//getDefaultOptionNamesAndValues
	
	/**
	 * Get the optimization description.  
	 * 
	 * @return the optimization description; null or empty string if none. 
	 */
	public String getOptimizationDescription(){
		Element eEntityData = (Element)XMLUtil.findChildNode(m_eRoot, "entityData");
		Element eOptimization = (Element)XMLUtil.findChildNode(eEntityData, "optimization");
		if(eOptimization == null) return "";
		String sValue = XMLUtil.getElementValueByName(eOptimization, "description");
		return sValue==null?"":sValue;
	}//getOptimizationDescription
	
	/**
	 * Get the optimization variable type, which can be: 
	 * continuous, pureBinary, mixedBinary, pureInteger, mixedInteger, discrete.  
	 * 
	 * @return the optimization variable type; null or empty string if none. 
	 */
	public String getOptimizationVariableType(){
		Element eEntityData = (Element)XMLUtil.findChildNode(m_eRoot, "entityData");
		Element eOptimization = (Element)XMLUtil.findChildNode(eEntityData, "optimization");
		if(eOptimization == null) return "";
		String sValue = XMLUtil.getElementValueByName(eOptimization, "variableType");
		return sValue==null?"":sValue;
	}//getOptimizationVariableType
	
	/**
	 * Get the optimization objective type, which can be: 
	 * none, singleObjective, multiObjectives
	 * 
	 * @return the optimization objective type; null or empty string if none. 
	 */
	public String getOptimizationObjectiveType(){
		Element eEntityData = (Element)XMLUtil.findChildNode(m_eRoot, "entityData");
		Element eOptimization = (Element)XMLUtil.findChildNode(eEntityData, "optimization");
		if(eOptimization == null) return "";
		String sValue = XMLUtil.getElementValueByName(eOptimization, "objectiveType");
		return sValue==null?"":sValue;
	}//getOptimizationObjectiveType
	
	/**
	 * Get the optimization constraint type, which can be: 
	 * generalRange, pureEquality, pureBound, 
	 * pureLinearComplementarity, pureNonlinearComplementarity, 
	 * linearMixedComplementarity, nonlinearMixedComplementarity, generalMixedComplementarity,
	 * pureCone, mixedCone. 
	 * 
	 * @return the optimization constraint type; null or empty string if none. 
	 */
	public String getOptimizationConstraintType(){
		Element eEntityData = (Element)XMLUtil.findChildNode(m_eRoot, "entityData");
		Element eOptimization = (Element)XMLUtil.findChildNode(eEntityData, "optimization");
		if(eOptimization == null) return "";
		String sValue = XMLUtil.getElementValueByName(eOptimization, "constraintType");
		return sValue==null?"":sValue;
	}//getOptimizationConstraintType
	
	/**
	 * Get the optimization objective linearity, which can be: 
	 * none, linearNetwork, linear, sumOfSquares, convexQuadratic, convexNonlinear, generalQuadratic, generalNonlinear
	 * 
	 * @return the optimization objective linearity; null or empty string if none. 
	 */
	public String getOptimizationObjectiveLinearity(){
		Element eEntityData = (Element)XMLUtil.findChildNode(m_eRoot, "entityData");
		Element eOptimization = (Element)XMLUtil.findChildNode(eEntityData, "optimization");
		if(eOptimization == null) return "";
		String sValue = XMLUtil.getElementValueByName(eOptimization, "objectiveLinearity");
		return sValue==null?"":sValue;
	}//getOptimizationObjectiveLinearity


	/**
	 * Get the constraint objective linearity, which can be: 
	 * none, bound, linearNetwork, linear, convexQuadratic, convexNonlinear, generalQuadratic, generalNonlinear
	 * 
	 * @return the optimization constraint linearity; null or empty string if none. 
	 */
	public String getOptimizationConstraintLinearity(){
		Element eEntityData = (Element)XMLUtil.findChildNode(m_eRoot, "entityData");
		Element eOptimization = (Element)XMLUtil.findChildNode(eEntityData, "optimization");
		if(eOptimization == null) return "";
		String sValue = XMLUtil.getElementValueByName(eOptimization, "constraintLinearity");
		return sValue==null?"":sValue;
	}//getOptimizationConstraintLinearity

	
	/**
	 * Get the optimization objective differentiability, which can be: 
	 * generallyDifferentiable, twiceDifferentiable, firstDifferentiable, 
	 * nonDifferentiableContinous, nonContinuous, simulation. 
	 * 
	 * @return the optimization objective differentiability; null or empty string if none. 
	 */
	public String getOptimizationObjectiveDifferentiability(){
		Element eEntityData = (Element)XMLUtil.findChildNode(m_eRoot, "entityData");
		Element eOptimization = (Element)XMLUtil.findChildNode(eEntityData, "optimization");
		if(eOptimization == null) return "";
		String sValue = XMLUtil.getElementValueByName(eOptimization, "objectiveDifferentiability");
		return sValue==null?"":sValue;
	}//getOptimizationObjectiveDifferentiability


	/**
	 * Get the optimization constraint differentiability, which can be: 
	 * generallyDifferentiable, twiceDifferentiable, firstDifferentiable, 
	 * nonDifferentiableContinous, nonContinuous, simulation. 
	 * 
	 * @return the optimization constraint differentiability; null or empty string if none. 
	 */
	public String getOptimizationConstraintDifferentiability(){
		Element eEntityData = (Element)XMLUtil.findChildNode(m_eRoot, "entityData");
		Element eOptimization = (Element)XMLUtil.findChildNode(eEntityData, "optimization");
		if(eOptimization == null) return "";
		String sValue = XMLUtil.getElementValueByName(eOptimization, "constraintDifferentiability");
		return sValue==null?"":sValue;
	}//getOptimizationConstraintDifferentiability


	/**
	 * Get the optimization parameter type, which can be: 
	 * number, string, both
	 * 
	 * @return the optimization parameter type; null or empty string if none. 
	 */
	public String getOptimizationParameterType(){
		Element eEntityData = (Element)XMLUtil.findChildNode(m_eRoot, "entityData");
		Element eOptimization = (Element)XMLUtil.findChildNode(eEntityData, "optimization");
		if(eOptimization == null) return "";
		String sValue = XMLUtil.getElementValueByName(eOptimization, "parameterType");
		return sValue==null?"":sValue;
	}//getOptimizationParameterType
	

	/**
	 * Get the optimization stochasticity, which can be: 
	 * deterministic, stochastic, both
	 * 
	 * @return the optimization stochasticity; null or empty string if none. 
	 */
	public String getOptimizationStochasticity(){
		Element eEntityData = (Element)XMLUtil.findChildNode(m_eRoot, "entityData");
		Element eOptimization = (Element)XMLUtil.findChildNode(eEntityData, "optimization");
		if(eOptimization == null) return "";
		String sValue = XMLUtil.getElementValueByName(eOptimization, "stochasticity");
		return sValue==null?"":sValue;
	}//getOptimizationStochasticity

	/**
	 * Get whether the service supports real time optimization or not.  
	 * 
	 * @return whether the service supports real time optimization or not.  
	 */
	public boolean getOptimizationRealTime(){
		Element eEntityData = (Element)XMLUtil.findChildNode(m_eRoot, "entityData");
		Element eOptimization = (Element)XMLUtil.findChildNode(eEntityData, "optimization");
		if(eOptimization == null) return false;
		String sValue = XMLUtil.getElementValueByName(eOptimization, "realTime");
		if(sValue == null || sValue.length() <= 0 || !sValue.startsWith("t")) return false;
		else return true;
	}//getOptimizationRealTime

	/**
	 * Get the function types that the service supports.   
	 * 
	 * @return the function types that the service supports, null if none.    
	 */
	public FunctionType getOptimizationFunctionType(){
		Element eEntityData = (Element)XMLUtil.findChildNode(m_eRoot, "entityData");
		Element eOptimization = (Element)XMLUtil.findChildNode(eEntityData, "optimization");
		if(eOptimization == null) return null;
		Element eFunctionType = (Element)XMLUtil.findChildNode(eOptimization, "functionType");
		if(eFunctionType == null) return null;
		FunctionType functionType = new FunctionType();
		String sValue = ""; 
		sValue = XMLUtil.getElementValueByName(eFunctionType, "general");
		if(sValue != null && sValue.length() > 0){
			if(sValue.startsWith("t")) functionType.general = true;
			else if(sValue.startsWith("f")) functionType.general = false;
		}
		sValue = XMLUtil.getElementValueByName(eFunctionType, "basic");
		if(sValue != null && sValue.length() > 0){
			if(sValue.startsWith("t")) functionType.basic = true;
			else if(sValue.startsWith("f")) functionType.basic = false;
		}
		sValue = XMLUtil.getElementValueByName(eFunctionType, "arithmetic");
		if(sValue != null && sValue.length() > 0){
			if(sValue.startsWith("t")) functionType.arithmetic = true;
			else if(sValue.startsWith("f")) functionType.arithmetic = false;
		}
		sValue = XMLUtil.getElementValueByName(eFunctionType, "trigonometric");
		if(sValue != null && sValue.length() > 0){
			if(sValue.startsWith("t")) functionType.trigonometric = true;
			else if(sValue.startsWith("f")) functionType.trigonometric = false;
		}
		sValue = XMLUtil.getElementValueByName(eFunctionType, "statistics");
		if(sValue != null && sValue.length() > 0){
			if(sValue.startsWith("t")) functionType.statistics = true;
			else if(sValue.startsWith("f")) functionType.statistics = false;
		}
		sValue = XMLUtil.getElementValueByName(eFunctionType, "probability");
		if(sValue != null && sValue.length() > 0){
			if(sValue.startsWith("t")) functionType.probability = true;
			else if(sValue.startsWith("f")) functionType.probability = false;
		}
		sValue = XMLUtil.getElementValueByName(eFunctionType, "relationalAndLogic");
		if(sValue != null && sValue.length() > 0){
			if(sValue.startsWith("t")) functionType.relationalAndLogic = true;
			else if(sValue.startsWith("f")) functionType.relationalAndLogic = false;
		}
		sValue = XMLUtil.getElementValueByName(eFunctionType, "userFunction");
		if(sValue != null && sValue.length() > 0){
			if(sValue.startsWith("t")) functionType.userFunction = true;
			else if(sValue.startsWith("f")) functionType.userFunction = false;
		}
		sValue = XMLUtil.getElementValueByName(eFunctionType, "general");
		if(sValue != null && sValue.length() > 0){
			if(sValue.startsWith("t")) functionType.simulation = true;
			else if(sValue.startsWith("f")) functionType.simulation = false;
		}
		return functionType;
	}//getOptimizationFunctionType

	
	/**
	 * Get the special structures that the service supports.   
	 * 
	 * @return the special structures that the service supports, null if none.    
	 */
	public SpecialStructure getOptimizationSpecialStructure(){
		Element eEntityData = (Element)XMLUtil.findChildNode(m_eRoot, "entityData");
		Element eOptimization = (Element)XMLUtil.findChildNode(eEntityData, "optimization");
		if(eOptimization == null) return null;
		Element eSpecialStructure = (Element)XMLUtil.findChildNode(eOptimization, "specialStructure");
		if(eSpecialStructure == null) return null;
		SpecialStructure specialStructure = new SpecialStructure();
		String sValue = ""; 
		sValue = XMLUtil.getElementValueByName(eSpecialStructure, "semidefiniteProgram");
		if(sValue != null && sValue.length() > 0){
			if(sValue.startsWith("t")) specialStructure.semidefiniteProgram = true;
			else if(sValue.startsWith("f")) specialStructure.semidefiniteProgram = false;
		}
		sValue = XMLUtil.getElementValueByName(eSpecialStructure, "coneProgram");
		if(sValue != null && sValue.length() > 0){
			if(sValue.startsWith("t")) specialStructure.coneProgram = true;
			else if(sValue.startsWith("f")) specialStructure.coneProgram = false;
		}
		sValue = XMLUtil.getElementValueByName(eSpecialStructure, "arithmetic");
		if(sValue != null && sValue.length() > 0){
			if(sValue.startsWith("t")) specialStructure.coneProgram = true;
			else if(sValue.startsWith("f")) specialStructure.coneProgram = false;
		}
		return specialStructure;
	}//getOptimizationSpecialStructure

	/**
	 * Get the special algorithms that the service supports.   
	 * 
	 * @return the special algorithms that the service supports, null if none.    
	 */
	public SpecialAlgorithm getOptimizationSpecialAlgorithm(){
		Element eEntityData = (Element)XMLUtil.findChildNode(m_eRoot, "entityData");
		Element eOptimization = (Element)XMLUtil.findChildNode(eEntityData, "optimization");
		if(eOptimization == null) return null;
		Element eSpecialAlgorithm = (Element)XMLUtil.findChildNode(eOptimization, "specialAlgorithm");
		if(eSpecialAlgorithm == null) return null;
		SpecialAlgorithm specialAlgorithm = new SpecialAlgorithm();
		String sValue = ""; 
		sValue = XMLUtil.getElementValueByName(eSpecialAlgorithm, "decomposition");
		if(sValue != null && sValue.length() > 0){
			if(sValue.startsWith("t")) specialAlgorithm.decomposition = true;
			else if(sValue.startsWith("f")) specialAlgorithm.decomposition = false;
		}
		sValue = XMLUtil.getElementValueByName(eSpecialAlgorithm, "globalOptimization");
		if(sValue != null && sValue.length() > 0){
			if(sValue.startsWith("t")) specialAlgorithm.globalOptimization = true;
			else if(sValue.startsWith("f")) specialAlgorithm.globalOptimization = false;
		}
		sValue = XMLUtil.getElementValueByName(eSpecialAlgorithm, "dynamicProgramming");
		if(sValue != null && sValue.length() > 0){
			if(sValue.startsWith("t")) specialAlgorithm.dynamicProgramming = true;
			else if(sValue.startsWith("f")) specialAlgorithm.dynamicProgramming = false;
		}
		sValue = XMLUtil.getElementValueByName(eSpecialAlgorithm, "heuristic");
		if(sValue != null && sValue.length() > 0){
			if(sValue.startsWith("t")) specialAlgorithm.heuristic = true;
			else if(sValue.startsWith("f")) specialAlgorithm.heuristic = false;
		}
		return specialAlgorithm;
	}//getOptimizationSpecialAlgorithm

	
	/**
	 * Get the hash map of other entity information.
	 *  
	 * @return the hash map of other entity info.
	 */
	public HashMap<String, String> getOtherEntityInfo(){
		if(m_otherEntityInfoHashMap != null) return m_otherEntityInfoHashMap;
		m_otherEntityInfoHashMap = new HashMap<String, String>();
		m_otherEntityDescriptionHashMap = new HashMap<String, String>();

		Element eEntityData = (Element)XMLUtil.findChildNode(m_eRoot, "entityData");
		Vector<Element> vOtherElement = XMLUtil.getChildElementsByTagName(eEntityData, "other");
		int iNls	= vOtherElement==null?0:vOtherElement.size();
		for(int i = 0; i < iNls; i++){
			Element eOther = (Element)(vOtherElement.elementAt(i));
			NamedNodeMap attributes =  eOther.getAttributes();
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
			m_otherEntityInfoHashMap.put(sName, sValue);
			m_otherEntityDescriptionHashMap.put(sName, sDescription);
		}
		return m_otherEntityInfoHashMap;
	}//getOtherEntityInfo


	/**
	 * Get the number of other entity info.  
	 * 
	 * @return the number of other entity info. 
	 */
	public int getOtherEntityInfoNumber(){
		getOtherEntityInfo();
		return m_otherEntityInfoHashMap.size();
	}//getOtherEntityInfoNumber
	
	/**
	 * Get the String value from the other entity info hash map. 
	 * 
	 * @param name holds the name of entity info to get. 
	 * @return String value from the other entity info hash map, null if none. 
	 */
	public String getOtherEntityInfoValueByName(String name){
		getOtherEntityInfo();
		if(m_otherEntityInfoHashMap.containsKey(name)){
			return (String)m_otherEntityInfoHashMap.get(name);
		}
		else{ 
			return null;
		}
	}//getOtherEntityInfoValueByName
	
	/**
	 * Get the String value from the other entity info hash map. 
	 * 
	 * @param name holds the name of entity info to get. 
	 * @return String value from the other entity info hash map, null if none. 
	 */
	public String getOtherEntityDescriptionByName(String name){
		getOtherEntityInfo();
		if(m_otherEntityDescriptionHashMap.containsKey(name)){
			return (String)m_otherEntityDescriptionHashMap.get(name);
		}
		else{ 
			return null;
		}
	}//getOtherEntityDescriptionByName

	/**
	 * Get the names of all other entity info. 
	 * 
	 * @return the names of all other entity info.
	 */
	public String[] getOtherEntityInfoNames(){
		getOtherEntityInfo();	
		Set nameSet = m_otherEntityInfoHashMap.keySet();
		Object[] moName = nameSet.toArray();
		String[] msName = new String[nameSet.size()];
		for (int i = 0; i < nameSet.size(); i++) {
			msName[i] = (String)moName[i];
		}
		return msName;		
	}//getOtherEntityInfoNames


	
	/**
	 * Get the values of all other entity info. 
	 * 
	 * @return the values of all other entity info.
	 */
	public String[] getOtherEntityInfoValues(){
		getOtherEntityInfo();			
		Collection valueCollection = m_otherEntityInfoHashMap.values();
		Object[] moValue = valueCollection.toArray();
		String[] msValue = new String[valueCollection.size()];
		for (int i = 0; i < valueCollection.size(); i++) {
			msValue[i] = moValue[i].toString();
		}
		return msValue;				
	}//getOtherEntityInfoValues
	
	/**
	 * Get the descriptions of all other entity info. 
	 * 
	 * @return the descriptions of all other entity info.
	 */
	public String[] getOtherEntityDescriptions(){
		getOtherEntityInfo();		
		Collection valueCollection = m_otherEntityDescriptionHashMap.values();
		Object[] moValue = valueCollection.toArray();
		String[] msDescription = new String[valueCollection.size()];
		for (int i = 0; i < valueCollection.size(); i++) {
			msDescription[i] = moValue[i].toString();
		}
		return msDescription;		
		
	}//getOtherEntityDescriptions
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		OSeLReader oselReader = new OSeLReader(false);
		System.out.println(IOUtil.readStringFromFile(OSParameter.CODE_HOME + "OSRepository/test/osel/osel.osel"));
		System.out.println(oselReader.readFile(OSParameter.CODE_HOME + "OSRepository/test/osel/osel.osel"));
		System.out.println(oselReader.getMessage());
		System.out.println(XMLUtil.createXSDateTime(oselReader.getRegistrationDate()));
		System.out.println(oselReader.getServiceName());
		System.out.println(oselReader.getServiceURI());
		System.out.println(oselReader.getLicenseRequired());
		System.out.println(oselReader.getUserNameRequired());
		System.out.println(oselReader.getPasswordRequired());
		System.out.println(oselReader.getOwner().names);
		System.out.println(oselReader.getOwner().contact);
		System.out.println(oselReader.getKeyWords()==null?0:oselReader.getKeyWords().length);
		Link[] links = oselReader.getLinks();
		System.out.println(links==null?null:(links[0]).value);
		System.out.println(oselReader.getSystemDescription());
		System.out.println(oselReader.getSystemDedication());
		System.out.println(oselReader.getSystemHardwareInfo().busSpeed);
		System.out.println(oselReader.getSystemHardwareInfo().cpuNumber);
		System.out.println(oselReader.getServiceDescription());
		System.out.println(oselReader.getServiceType());
		System.out.println(oselReader.getServiceCategory());
		System.out.println(oselReader.getServiceSoftwareDescription());
		System.out.println(oselReader.getServiceAlgorithmDescription());
		System.out.println(oselReader.getServiceWebPage());
		System.out.println(oselReader.getServiceWSDLLocation());
		System.out.println(oselReader.getServiceLogoImageLink());
		System.out.println("**************option***************");
		OSOption osOption = oselReader.getDefaultOptionNamesAndValues();
		if(osOption != null){
			System.out.println(osOption.getNumberOfConstraints());
			System.out.println(osOption.getMaxTime());			
		}
		System.out.println("**************option***************");
		System.out.println(oselReader.getOptimizationDescription());
		System.out.println(oselReader.getOptimizationVariableType());
		System.out.println(oselReader.getOptimizationObjectiveType());
		System.out.println(oselReader.getOptimizationConstraintType());
		System.out.println(oselReader.getOptimizationObjectiveLinearity());
		System.out.println(oselReader.getOptimizationConstraintLinearity());
		System.out.println(oselReader.getOptimizationObjectiveDifferentiability());
		System.out.println(oselReader.getOptimizationConstraintDifferentiability());
		System.out.println(oselReader.getOptimizationParameterType());
		System.out.println(oselReader.getOptimizationStochasticity());
		System.out.println(oselReader.getOptimizationRealTime());
		System.out.println(oselReader.getOptimizationFunctionType().probability);
		System.out.println(oselReader.getOptimizationFunctionType().basic);
		System.out.println(oselReader.getOptimizationSpecialStructure().coneProgram);
		System.out.println(oselReader.getOptimizationSpecialStructure().disjunctiveProgram);
		System.out.println(oselReader.getOptimizationSpecialAlgorithm().dynamicProgramming);
		System.out.println(oselReader.getOptimizationSpecialAlgorithm().globalOptimization);
		System.out.println(oselReader.getOtherEntityInfoNumber());
		String sValue = oselReader.getOtherEntityInfoValueByName("ad");
		if(sValue == null) System.out.println("null");
		else System.out.println(sValue);
		String sDescription = oselReader.getOtherEntityDescriptionByName("a");
		System.out.println(sDescription);
		for(int i=0;i<oselReader.getOtherEntityInfoNumber();i++){
			System.out.println(oselReader.getOtherEntityInfoNames()[i]);
			System.out.println(oselReader.getOtherEntityInfoValues()[i]);
			System.out.println(oselReader.getOtherEntityDescriptions()[i]);
		}
		

		oselReader.writeToStandardOutput();
	}//main
	
}//class OSeLReader
