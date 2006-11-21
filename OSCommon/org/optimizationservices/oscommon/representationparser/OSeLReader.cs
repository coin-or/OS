using System;
using System.Collections;
using System.Xml;

using org.optimizationservices.oscommon.util;
using org.optimizationservices.oscommon.localinterface;
using org.optimizationservices.oscommon.datastructure.osentity;
using org.optimizationservices.oscommon.representationparser;

namespace org.optimizationservices.oscommon.representationparser{
	///	<summary>
	///	The	<c>OSeLReader</c> class	parses an OSeL instance	into a DOM tree	and
	///	provides a set of "get"	methods	that can be	
	///	used to	retrieve different pieces of information of	the	instance.
	///	@author	Jun	Ma	
	///	@version 1.0, 09/01/2005
	///	@since OS 1.0
	///	@copyright (c) 2005
	///	</summary>
	public class OSeLReader	: OSgLReader{
		
		/// <summary>
		/// m_osEntity holds the standard OSEntity, which is a local interface for 
		/// storing Optimization Services entity. 
		/// </summary>
		protected OSEntity m_osEntity = null;

		///	<summary>
		///	m_otherEntityInfoHashMap holds a hash map of other alalyses.
		///	</summary>
		protected Hashtable	m_otherEntityInfoHashMap = null;

		///	<summary>
		///	m_otherEntityDescriptionHashMap holds a hash map of other entity descriptions.
		///	</summary>
		protected Hashtable	m_otherEntityDescriptionHashMap = null;

		///	<summary>
		///	constructor.
		///	</summary>
		///	<param name="validate">holds whether the reader	should be validating against the schema	or not.</param>
		public OSeLReader(bool validate){
			m_bXsdValidate = validate;
		}//constructor
	
		///	<summary>
		///	Default	constructor. 
		///	</summary>
		public OSeLReader(){
		}//constructor

		/// <summary>
		/// get the standard OSEntity, a local interface for 
		/// storing Optimization Services entity.
		/// </summary>
		/// <returns>the OSEntity. </returns>
		public OSEntity getOSEntity(){
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

		/// <summary>
		/// get the service uri
		/// </summary>
		/// <returns>the service uri</returns>
		public string getServiceURI(){
			XmlElement eEntityHeader = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityHeader");
			string sServiceURI = XMLUtil.getElementValueByName(eEntityHeader, "serviceURI");
			if(sServiceURI == null) sServiceURI = "";
			return sServiceURI;
		}//getServiceURI

		/// <summary>
		/// get the service name
		/// </summary>
		/// <returns>the service name</returns>
		public string getServiceName(){
			XmlElement eEntityHeader = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityHeader");
			string sServiceName = XMLUtil.getElementValueByName(eEntityHeader, "serviceName");
			if(sServiceName == null) sServiceName = "";
			return sServiceName;
		}//getServiceName

		/// <summary>
		/// Get time of the registration date.
		/// </summary>
		/// <returns>the time of the registration date.</returns>
		public DateTime getRegistrationDate(){
			XmlElement eEntityHeader = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityHeader");
			string sRegistrationDate = XMLUtil.getElementValueByName(eEntityHeader, "registrationDate");
			if(sRegistrationDate == null) return new DateTime(1970, 1, 1, 0, 0, 0);
			DateTime date = XMLUtil.createNativeDateTime(sRegistrationDate);
			return date;
		}//getRegistrationDate

		/// <summary>
		/// Get the message. 
		/// </summary>
		/// <returns>the message. </returns>
		public string getMessage(){
			XmlElement eEntityHeader = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityHeader");
			string sMessage = XMLUtil.getElementValueByName(eEntityHeader, "message");
			if(sMessage == null) sMessage = "";
			return sMessage;
		}//getMessage

		/// <summary>
		/// Get whether the license is reqired of the service or not.
		/// </summary>
		/// <returns>whether the license is reqired of the service or not. </returns>
		public bool getLicenseRequired(){
			XmlElement eEntityData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityData");
			XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(eEntityData, "general");
			if(eGeneral == null) return false;
			XmlElement eAccess = (XmlElement)XMLUtil.findChildNode(eGeneral, "access");
			if(eAccess == null) return false;
			XmlElement eType = (XmlElement)XMLUtil.findChildNode(eAccess, "type");
			if(eType == null) return false;
			string sValue = eType.GetAttribute("licenseRequired");
			if(sValue == null || sValue.Length <=0 || !sValue.StartsWith("t")) return false;
			else return true;
		}//getLicenseRequired

		/// <summary>
		/// Get whether the user name is reqired of the service or not. 
		/// </summary>
		/// <returns>whether the user name is reqired of the service or not. </returns>
		public bool getUserNameRequired(){
			XmlElement eEntityData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityData");
			XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(eEntityData, "general");
			if(eGeneral == null) return false;
			XmlElement eAccess = (XmlElement)XMLUtil.findChildNode(eGeneral, "access");
			if(eAccess == null) return false;
			XmlElement eType = (XmlElement)XMLUtil.findChildNode(eAccess, "type");
			if(eType == null) return false;
			string sValue = eType.GetAttribute("userNameRequired");
			if(sValue == null || sValue.Length <=0 || !sValue.StartsWith("t")) return false;
			else return true;
		}//getUserNameRequired


		/// <summary>
		/// Get whether the password is reqired of the service or not.  
		/// </summary>
		/// <returns>whether the password is reqired of the service or not. </returns>
		public bool getPasswordRequired(){
			XmlElement eEntityData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityData");
			XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(eEntityData, "general");
			if(eGeneral == null) return false;
			XmlElement eAccess = (XmlElement)XMLUtil.findChildNode(eGeneral, "access");
			if(eAccess == null) return false;
			XmlElement eType = (XmlElement)XMLUtil.findChildNode(eAccess, "type");
			if(eType == null) return false;
			string sValue = eType.GetAttribute("passwordRequired");
			if(sValue == null || sValue.Length <=0 || !sValue.StartsWith("t")) return false;
			else return true;
		}//getPasswordRequired

		/// <summary>
		/// Get the access limits of the service. 
		/// </summary>
		/// <returns>the access limits information of the service entity; null if none. </returns>
		public AccessLimits getAccessLimits(){
			XmlElement eEntityData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityData");
			XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(eEntityData, "general");
			if(eGeneral == null) return null;
			XmlElement eAccess = (XmlElement)XMLUtil.findChildNode(eGeneral, "access");
			if(eAccess == null) return null;
			XmlElement eAccessLimits = (XmlElement)XMLUtil.findChildNode(eAccess, "limits");
			if(eAccessLimits == null) return null;
			AccessLimits accessLimits = new AccessLimits();
			String sValue = "";		
			try {
				sValue = XMLUtil.getElementValueByName(eAccessLimits, "maxDiskSpace");
				if(sValue != null && sValue.Length > 0){
					double dValue = Double.Parse(sValue);
					accessLimits.maxDiskSpace = dValue;
				}	
			} 
			catch (Exception) {
			}
			try {
				sValue = XMLUtil.getElementValueByName(eAccessLimits, "maxMemory");
				if(sValue != null && sValue.Length > 0){
					double dValue = Double.Parse(sValue);
					accessLimits.maxMemory = dValue;
				}	
			} 
			catch (Exception) {
			}
			try {
				sValue = XMLUtil.getElementValueByName(eAccessLimits, "maxJobs");
				if(sValue != null && sValue.Length > 0){
					int iValue = Int32.Parse(sValue);
					accessLimits.maxJobs = iValue;
				}	
			} 
			catch (Exception) {
			}
			try {
				sValue = XMLUtil.getElementValueByName(eAccessLimits, "maxVariables");
				if(sValue != null && sValue.Length > 0){
					int iValue = Int32.Parse(sValue);
					accessLimits.maxVariables = iValue;
				}	
			} 
			catch (Exception) {
			}
			try {
				sValue = XMLUtil.getElementValueByName(eAccessLimits, "maxBinaryVariables");
				if(sValue != null && sValue.Length > 0){
					int iValue = Int32.Parse(sValue);
					accessLimits.maxBinaryVariables = iValue;
				}	
			} 
			catch (Exception) {
			}
			try {
				sValue = XMLUtil.getElementValueByName(eAccessLimits, "maxIntegerVariables");
				if(sValue != null && sValue.Length > 0){
					int iValue = Int32.Parse(sValue);
					accessLimits.maxIntegerVariables = iValue;
				}	
			} 
			catch (Exception) {
			}
			try {
				sValue = XMLUtil.getElementValueByName(eAccessLimits, "maxObjectives");
				if(sValue != null && sValue.Length > 0){
					int iValue = Int32.Parse(sValue);
					accessLimits.maxObjectives = iValue;
				}	
			} 
			catch (Exception) {
			}
			try {
				sValue = XMLUtil.getElementValueByName(eAccessLimits, "maxConstraints");
				if(sValue != null && sValue.Length > 0){
					int iValue = Int32.Parse(sValue);
					accessLimits.maxConstraints = iValue;
				}	
			} 
			catch (Exception) {
			}
			try {
				sValue = XMLUtil.getElementValueByName(eAccessLimits, "maxNonzeroLinearConstraintCoefficients");
				if(sValue != null && sValue.Length > 0){
					int iValue = Int32.Parse(sValue);
					accessLimits.maxNonzeroLinearConstraintCoefficients = iValue;
				}	
			} 
			catch (Exception) {
			}
			return accessLimits;
		}//getAccessLimits

		/// <summary>
		/// Get the owner information of the service entity.
		/// </summary>
		/// <returns>the owner information of the service entity; null if none.</returns>
		public Owner getOwner(){
			XmlElement eEntityData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityData");
			XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(eEntityData, "general");
			if(eGeneral == null) return null;
			XmlElement eOwner = (XmlElement)XMLUtil.findChildNode(eGeneral, "owner");
			if(eOwner == null) return null;
			string sValue = "";
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
			XmlElement eContact = (XmlElement)XMLUtil.findChildNode(eOwner, "contact");
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

		/// <summary>
		/// Get the key words of the service. 
		/// </summary>
		/// <returns>the key words in a string array; null if none.  </returns>
		public string[] getKeyWords(){
			XmlElement eEntityData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityData");
			XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(eEntityData, "general");
			if(eGeneral == null) return null;
			XmlElement eKeyWords = (XmlElement)XMLUtil.findChildNode(eGeneral, "keyWords");
			if(eKeyWords == null) return null;
			XmlNodeList keys = eKeyWords.GetElementsByTagName("key");
			if(keys == null || keys.Count <= 0) return null;
			int iKeys = keys.Count;
			string[] msKeys = new string[iKeys];
			for(int i = 0; i < iKeys; i++){
				msKeys[i] = XMLUtil.getElementValue((XmlElement)keys.Item(i));
			}
			return msKeys;
		}//getKeyWords

		/// <summary>
		/// Get the links of the service. 
		/// </summary>
		/// <returns>the links of the service; null if none. </returns>
		public Link[] getLinks(){
			XmlElement eEntityData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityData");
			XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(eEntityData, "general");
			if(eGeneral == null) return null;
			XmlElement eLinks = (XmlElement)XMLUtil.findChildNode(eGeneral, "links");
			if(eLinks == null) return null;
			XmlNodeList links = eLinks.GetElementsByTagName("link");
			if(links == null || links.Count <= 0) return null;
			int iLinks = links.Count;
			Link[] mLinks = new Link[iLinks];
			string sValue = "";
			for(int i = 0; i < iLinks; i++){
				mLinks[i] = new Link();
				XmlElement eLink = (XmlElement)links.Item(i);
				sValue = eLink.GetAttribute("type");
				mLinks[i].type = sValue==null?"":sValue;
				sValue = eLink.GetAttribute("description");
				mLinks[i].description = sValue==null?"":sValue;
				sValue = XMLUtil.getElementValue(eLink);
				mLinks[i].value = sValue==null?"":sValue;
			}
			return mLinks;
		}//getLinks

		/// <summary>
		/// Get the system description. 
		/// </summary>
		/// <returns>the system description; null or empty string if none. </returns>
		public string getSystemDescription(){
			XmlElement eEntityData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityData");
			XmlElement eSystem = (XmlElement)XMLUtil.findChildNode(eEntityData, "system");
			if(eSystem == null) return "";
			string sDescription = XMLUtil.getElementValueByName(eSystem, "description");
			return sDescription==null?"":sDescription;
		}//getSystemDescription

		/// <summary>
		/// Get the system dedication, a double between 0 and 1 with 1 being fully dedicated. 
		/// </summary>
		/// <returns>the system dedication; Double.NaN if none. </returns>
		public double getSystemDedication(){
			XmlElement eEntityData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityData");
			XmlElement eSystem = (XmlElement)XMLUtil.findChildNode(eEntityData, "system");
			if(eSystem == null) return Double.NaN;
			try {
				string sValue =  XMLUtil.getElementValueByName(eSystem, "dedication");
				if(sValue == null || sValue.Length <= 0) return Double.NaN;
				double dValue = Double.Parse(sValue);
				return dValue;
			} 
			catch (Exception) {
				return Double.NaN;
			}
		}//getSystemDedication

		/// <summary>
		/// Get the system hardware information.  
		/// </summary>
		/// <returns>the system hardware information; null if none. </returns>
		public HardwareInfo getSystemHardwareInfo(){
			XmlElement eEntityData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityData");
			XmlElement eSystem = (XmlElement)XMLUtil.findChildNode(eEntityData, "system");
			if(eSystem == null) return null;
			XmlElement eHardware = (XmlElement)XMLUtil.findChildNode(eSystem, "hardware");
			if(eHardware == null) return null;
			HardwareInfo hardwareInfo = new HardwareInfo();
			string sValue = "";
			int iValue;
			double dValue;
			try {
				sValue =  XMLUtil.getElementValueByName(eHardware, "cpuNumber");
				if(sValue != null && sValue.Length > 0){
					iValue = Int32.Parse(sValue);
					hardwareInfo.cpuNumber = iValue;
				}
			} 
			catch (Exception) {
				hardwareInfo.cpuNumber = 1;
			}
			try {
				sValue =  XMLUtil.getElementValueByName(eHardware, "cpuSpeed");
				if(sValue != null && sValue.Length > 0){
					dValue = Double.Parse(sValue);
					hardwareInfo.cpuSpeed = dValue;
				}
			} 
			catch (Exception) {
				hardwareInfo.cpuSpeed = Double.NaN;
			}
			try {
				sValue =  XMLUtil.getElementValueByName(eHardware, "memorySize");
				if(sValue != null && sValue.Length > 0){
					dValue = Double.Parse(sValue);
					hardwareInfo.memorySize = dValue;
				}
			} 
			catch (Exception) {
				hardwareInfo.memorySize = Double.NaN;
			}
			try {
				sValue =  XMLUtil.getElementValueByName(eHardware, "busSpeed");
				if(sValue != null && sValue.Length > 0){
					dValue = Double.Parse(sValue);
					hardwareInfo.busSpeed = dValue;
				}
			} 
			catch (Exception) {
				hardwareInfo.busSpeed = Double.NaN;
			}
			try {
				sValue =  XMLUtil.getElementValueByName(eHardware, "diskSpace");
				if(sValue != null && sValue.Length > 0){
					dValue = Double.Parse(sValue);
					hardwareInfo.diskSpace = dValue;
				}
			} 
			catch (Exception) {
				hardwareInfo.diskSpace = Double.NaN;
			}
			try {
				sValue =  XMLUtil.getElementValueByName(eHardware, "nicSpeed");
				if(sValue != null && sValue.Length > 0){
					dValue = Double.Parse(sValue);
					hardwareInfo.nicSpeed = dValue;
				}
			} 
			catch (Exception) {
				hardwareInfo.nicSpeed = Double.NaN;
			}
			try {
				sValue =  XMLUtil.getElementValueByName(eHardware, "downloadSpeed");
				if(sValue != null && sValue.Length > 0){
					dValue = Double.Parse(sValue);
					hardwareInfo.downloadSpeed = dValue;
				}
			} 
			catch (Exception) {
				hardwareInfo.downloadSpeed = Double.NaN;
			}
			try {
				sValue =  XMLUtil.getElementValueByName(eHardware, "uploadSpeed");
				if(sValue != null && sValue.Length > 0){
					dValue = Double.Parse(sValue);
					hardwareInfo.uploadSpeed = dValue;
				}
			} 
			catch (Exception) {
				hardwareInfo.uploadSpeed = Double.NaN;
			}
			return hardwareInfo;
		}//getSystemHardwareInfo

		/// <summary>
		/// Get the service description.  
		/// </summary>
		/// <returns>the service description; null or empty string if none. </returns>
		public string getServiceDescription(){
			XmlElement eEntityData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityData");
			XmlElement eService = (XmlElement)XMLUtil.findChildNode(eEntityData, "service");
			if(eService == null) return "";
			string sValue = XMLUtil.getElementValueByName(eService, "description");
			return sValue==null?"":sValue;
		}//getServiceDescription


		/// <summary>
		/// Get the service type, which can be: 
		/// solver, analyzer, scheduler, simulation, registry, modeler, agent 
		/// </summary>
		/// <returns>the service type; null or empty string if none. </returns>
		public string getServiceType(){
			XmlElement eEntityData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityData");
			XmlElement eService = (XmlElement)XMLUtil.findChildNode(eEntityData, "service");
			if(eService == null) return "";
			string sValue = XMLUtil.getElementValueByName(eService, "type");
			return sValue==null?"":sValue;
		}//getServiceType

		/// <summary>
		/// Get the service category, which can be: 
		///  education, government, organization, company, military, personal, other
		/// </summary>
		/// <returns>the service category; null or empty string if none. </returns>
		public string getServiceCategory(){
			XmlElement eEntityData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityData");
			XmlElement eService = (XmlElement)XMLUtil.findChildNode(eEntityData, "service");
			if(eService == null) return "";
			string sValue = XMLUtil.getElementValueByName(eService, "category");
			return sValue==null?"":sValue;
		}//getServiceCategory

		/// <summary>
		/// Get the service software description.  
		/// </summary>
		/// <returns>the software description; null or empty string if none.</returns>
		public string getServiceSoftwareDescription(){
			XmlElement eEntityData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityData");
			XmlElement eService = (XmlElement)XMLUtil.findChildNode(eEntityData, "service");
			if(eService == null) return "";
			string sValue = XMLUtil.getElementValueByName(eService, "software");
			return sValue==null?"":sValue;
		}//getServiceSoftwareDescription

		/// <summary>
		/// Get the service algorithm description. 
		/// </summary>
		/// <returns>the algorithm description; null or empty string if none. </returns>
		public string getServiceAlgorithmDescription(){
			XmlElement eEntityData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityData");
			XmlElement eService = (XmlElement)XMLUtil.findChildNode(eEntityData, "service");
			if(eService == null) return "";
			string sValue = XMLUtil.getElementValueByName(eService, "algorithm");
			return sValue==null?"":sValue;
		}//getServiceAlgorithmDescription

		/// <summary>
		/// Get the service web page.  
		/// </summary>
		/// <returns>the service web page; null or empty string if none. </returns>
		public string getServiceWebPage(){
			XmlElement eEntityData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityData");
			XmlElement eService = (XmlElement)XMLUtil.findChildNode(eEntityData, "service");
			if(eService == null) return "";
			string sValue = XMLUtil.getElementValueByName(eService, "webPage");
			return sValue==null?"":sValue;
		}//getServiceWebPage

		/// <summary>
		/// Get the service wsdl location.  
		/// </summary>
		/// <returns>the service wsdl location; null or empty string if none. </returns>
		public string getServiceWSDLLocation(){
			XmlElement eEntityData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityData");
			XmlElement eService = (XmlElement)XMLUtil.findChildNode(eEntityData, "service");
			if(eService == null) return "";
			string sValue = XMLUtil.getElementValueByName(eService, "wsdlLocation");
			return sValue==null?"":sValue;
		}//getServiceWSDLLocation

		/// <summary>
		/// Get the service logo image link.  
		/// </summary>
		/// <returns>the service logo image link; null or empty string if none. </returns>
		public string getServiceLogoImageLink(){
			XmlElement eEntityData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityData");
			XmlElement eService = (XmlElement)XMLUtil.findChildNode(eEntityData, "service");
			if(eService == null) return "";
			string sValue = XMLUtil.getElementValueByName(eService, "logoImageLink");
			return sValue==null?"":sValue;
		}//getServiceLogoImageLink

		/// <summary>
		/// Get the default option names and values in the standard OSOption structure which 
		/// is specified by the OSoL schema.
		/// </summary>
		/// <returns>the default option names and values in the standard OSOption structure, null if none. </returns>
		public OSOption getDefaultOptionNamesAndValues(){
			XmlElement eEntityData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityData");
			XmlElement eJob = (XmlElement)XMLUtil.findChildNode(eEntityData, "job");
			if(eJob == null) return null;
			XmlElement eOSoL = (XmlElement)XMLUtil.findChildNode(eJob, "osol");
			if(eOSoL == null) return null;
			OSoLReader osolReader = new OSoLReader(OSParameter.VALIDATE);
			osolReader.setRootElement(eOSoL);
			OSOption osOption;
			try {
				osOption = osolReader.getOSOption();
				return osOption;
			} 
			catch (Exception){
				return null;
			}
		}//getDefaultOptionNamesAndValues

		/// <summary>
		/// Get the optimization description.  
		/// </summary>
		/// <returns>the optimization description; null or empty string if none. </returns>
		public string getOptimizationDescription(){
			XmlElement eEntityData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityData");
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(eEntityData, "optimization");
			if(eOptimization == null) return "";
			string sValue = XMLUtil.getElementValueByName(eOptimization, "description");
			return sValue==null?"":sValue;
		}//getOptimizationDescription
	

		/// <summary>
		/// Get the optimization variable type, which can be: 
		/// continuous, pureBinary, mixedBinary, pureInteger, mixedInteger, discrete.  
		/// </summary>
		/// <returns>the optimization variable type; null or empty string if none. </returns>
		public string getOptimizationVariableType(){
			XmlElement eEntityData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityData");
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(eEntityData, "optimization");
			if(eOptimization == null) return "";
			string sValue = XMLUtil.getElementValueByName(eOptimization, "variableType");
			return sValue==null?"":sValue;
		}//getOptimizationVariableType


		/// <summary>
		/// Get the optimization objective type, which can be: 
		/// none, singleObjective, multiObjectives
		/// </summary>
		/// <returns>the optimization objective type; null or empty string if none. </returns>
		public string getOptimizationObjectiveType(){
			XmlElement eEntityData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityData");
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(eEntityData, "optimization");
			if(eOptimization == null) return "";
			string sValue = XMLUtil.getElementValueByName(eOptimization, "objectiveType");
			return sValue==null?"":sValue;
		}//getOptimizationObjectiveType

		/// <summary>
		/// Get the optimization constraint type, which can be: 
		/// generalRange, pureEquality, pureBound, 
		/// pureLinearComplementarity, pureNonlinearComplementarity, 
		/// linearMixedComplementarity, nonlinearMixedComplementarity, generalMixedComplementarity,
		/// pureCone, mixedCone. 
		/// </summary>
		/// <returns>the optimization constraint type; null or empty string if none. </returns>
		public string getOptimizationConstraintType(){
			XmlElement eEntityData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityData");
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(eEntityData, "optimization");
			if(eOptimization == null) return "";
			string sValue = XMLUtil.getElementValueByName(eOptimization, "constraintType");
			return sValue==null?"":sValue;
		}//getOptimizationConstraintType

		/// <summary>
		/// Get the optimization objective linearity, which can be: 
		/// none, linearNetwork, linear, sumOfSquares, convexQuadratic, convexNonlinear, generalQuadratic, generalNonlinear
		/// </summary>
		/// <returns>the optimization objective linearity; null or empty string if none. </returns>
		public string getOptimizationObjectiveLinearity(){
			XmlElement eEntityData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityData");
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(eEntityData, "optimization");
			if(eOptimization == null) return "";
			string sValue = XMLUtil.getElementValueByName(eOptimization, "objectiveLinearity");
			return sValue==null?"":sValue;
		}//getOptimizationObjectiveLinearity

		/// <summary>
		/// Get the constraint objective linearity, which can be: 
		/// none, bound, linearNetwork, linear, convexQuadratic, convexNonlinear, generalQuadratic, generalNonlinear
		/// </summary>
		/// <returns>the optimization constraint linearity; null or empty string if none. </returns>
		public string getOptimizationConstraintLinearity(){
			XmlElement eEntityData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityData");
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(eEntityData, "optimization");
			if(eOptimization == null) return "";
			string sValue = XMLUtil.getElementValueByName(eOptimization, "constraintLinearity");
			return sValue==null?"":sValue;
		}//getOptimizationConstraintLinearity

		/// <summary>
		/// Get the optimization objective differentiability, which can be: 
		/// generallyDifferentiable, twiceDifferentiable, firstDifferentiable, 
		/// nonDifferentiableContinous, nonContinuous, simulation.  
		/// </summary>
		/// <returns>the optimization objective differentiability; null or empty string if none. </returns>
		public string getOptimizationObjectiveDifferentiability(){
			XmlElement eEntityData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityData");
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(eEntityData, "optimization");
			if(eOptimization == null) return "";
			string sValue = XMLUtil.getElementValueByName(eOptimization, "objectiveDifferentiability");
			return sValue==null?"":sValue;
		}//getOptimizationObjectiveDifferentiability


		/// <summary>
		/// Get the optimization constraint differentiability, which can be: 
		/// generallyDifferentiable, twiceDifferentiable, firstDifferentiable, 
		/// nonDifferentiableContinous, nonContinuous, simulation. 
		/// </summary>
		/// <returns>the optimization constraint differentiability; null or empty string if none. </returns>
		public string getOptimizationConstraintDifferentiability(){
			XmlElement eEntityData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityData");
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(eEntityData, "optimization");
			if(eOptimization == null) return "";
			string sValue = XMLUtil.getElementValueByName(eOptimization, "constraintDifferentiability");
			return sValue==null?"":sValue;
		}//getOptimizationConstraintDifferentiability

		/// <summary>
		/// Get the optimization parameter type, which can be:
		/// number, string, both
		/// </summary>
		/// <returns>the optimization parameter type; null or empty string if none. </returns>
		public string getOptimizationParameterType(){
			XmlElement eEntityData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityData");
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(eEntityData, "optimization");
			if(eOptimization == null) return "";
			string sValue = XMLUtil.getElementValueByName(eOptimization, "parameterType");
			return sValue==null?"":sValue;
		}//getOptimizationParameterType

		/// <summary>
		/// Get the optimization stochasticity, which can be: 
		/// deterministic, stochastic, both
		/// </summary>
		/// <returns>the optimization stochasticity; null or empty string if none. </returns>
		public string getOptimizationStochasticity(){
			XmlElement eEntityData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityData");
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(eEntityData, "optimization");
			if(eOptimization == null) return "";
			string sValue = XMLUtil.getElementValueByName(eOptimization, "stochasticity");
			return sValue==null?"":sValue;
		}//getOptimizationStochasticity

		/// <summary>
		/// Get whether the service supports real time optimization or not. 
		/// </summary>
		/// <returns>whether the service supports real time optimization or not.  </returns>
		public bool getOptimizationRealTime(){
			XmlElement eEntityData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityData");
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(eEntityData, "optimization");
			if(eOptimization == null) return false;
			string sValue = XMLUtil.getElementValueByName(eOptimization, "realTime");
			if(sValue == null || sValue.Length <= 0 || !sValue.StartsWith("t")) return false;
			else return true;
		}//getOptimizationRealTime


		/// <summary>
		/// Get the function types that the service supports.
		/// </summary>
		/// <returns>the function types that the service supports, null if none. </returns>
		public FunctionType getOptimizationFunctionType(){
			XmlElement eEntityData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityData");
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(eEntityData, "optimization");
			if(eOptimization == null) return null;
			XmlElement eFunctionType = (XmlElement)XMLUtil.findChildNode(eOptimization, "functionType");
			if(eFunctionType == null) return null;
			FunctionType functionType = new FunctionType();
			string sValue = ""; 
			sValue = XMLUtil.getElementValueByName(eFunctionType, "general");
			if(sValue != null && sValue.Length > 0){
				if(sValue.StartsWith("t")) functionType.general = true;
				else if(sValue.StartsWith("f")) functionType.general = false;
			}
			sValue = XMLUtil.getElementValueByName(eFunctionType, "basic");
			if(sValue != null && sValue.Length > 0){
				if(sValue.StartsWith("t")) functionType.basic = true;
				else if(sValue.StartsWith("f")) functionType.basic = false;
			}
			sValue = XMLUtil.getElementValueByName(eFunctionType, "arithmetic");
			if(sValue != null && sValue.Length > 0){
				if(sValue.StartsWith("t")) functionType.arithmetic = true;
				else if(sValue.StartsWith("f")) functionType.arithmetic = false;
			}
			sValue = XMLUtil.getElementValueByName(eFunctionType, "trigonometric");
			if(sValue != null && sValue.Length > 0){
				if(sValue.StartsWith("t")) functionType.trigonometric = true;
				else if(sValue.StartsWith("f")) functionType.trigonometric = false;
			}
			sValue = XMLUtil.getElementValueByName(eFunctionType, "statistics");
			if(sValue != null && sValue.Length > 0){
				if(sValue.StartsWith("t")) functionType.statistics = true;
				else if(sValue.StartsWith("f")) functionType.statistics = false;
			}
			sValue = XMLUtil.getElementValueByName(eFunctionType, "probability");
			if(sValue != null && sValue.Length > 0){
				if(sValue.StartsWith("t")) functionType.probability = true;
				else if(sValue.StartsWith("f")) functionType.probability = false;
			}
			sValue = XMLUtil.getElementValueByName(eFunctionType, "relationalAndLogic");
			if(sValue != null && sValue.Length > 0){
				if(sValue.StartsWith("t")) functionType.relationalAndLogic = true;
				else if(sValue.StartsWith("f")) functionType.relationalAndLogic = false;
			}
			sValue = XMLUtil.getElementValueByName(eFunctionType, "userFunction");
			if(sValue != null && sValue.Length > 0){
				if(sValue.StartsWith("t")) functionType.userFunction = true;
				else if(sValue.StartsWith("f")) functionType.userFunction = false;
			}
			sValue = XMLUtil.getElementValueByName(eFunctionType, "general");
			if(sValue != null && sValue.Length > 0){
				if(sValue.StartsWith("t")) functionType.simulation = true;
				else if(sValue.StartsWith("f")) functionType.simulation = false;
			}
			return functionType;
		}//getOptimizationFunctionType

		/// <summary>
		/// Get the special structures that the service supports.   
		/// </summary>
		/// <returns>the special structures that the service supports, null if none.    </returns>
		public SpecialStructure getOptimizationSpecialStructure(){
			XmlElement eEntityData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityData");
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(eEntityData, "optimization");
			if(eOptimization == null) return null;
			XmlElement eSpecialStructure = (XmlElement)XMLUtil.findChildNode(eOptimization, "specialStructure");
			if(eSpecialStructure == null) return null;
			SpecialStructure specialStructure = new SpecialStructure();
			string sValue = ""; 
			sValue = XMLUtil.getElementValueByName(eSpecialStructure, "semidefiniteProgram");
			if(sValue != null && sValue.Length > 0){
				if(sValue.StartsWith("t")) specialStructure.semidefiniteProgram = true;
				else if(sValue.StartsWith("f")) specialStructure.semidefiniteProgram = false;
			}
			sValue = XMLUtil.getElementValueByName(eSpecialStructure, "coneProgram");
			if(sValue != null && sValue.Length > 0){
				if(sValue.StartsWith("t")) specialStructure.coneProgram = true;
				else if(sValue.StartsWith("f")) specialStructure.coneProgram = false;
			}
			sValue = XMLUtil.getElementValueByName(eSpecialStructure, "arithmetic");
			if(sValue != null && sValue.Length > 0){
				if(sValue.StartsWith("t")) specialStructure.coneProgram = true;
				else if(sValue.StartsWith("f")) specialStructure.coneProgram = false;
			}
			return specialStructure;
		}//getOptimizationSpecialStructure



		/// <summary>
		/// Get the special algorithms that the service supports.   
		/// </summary>
		/// <returns>the special algorithms that the service supports, null if none.    </returns>
		public SpecialAlgorithm getOptimizationSpecialAlgorithm(){
			XmlElement eEntityData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityData");
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(eEntityData, "optimization");
			if(eOptimization == null) return null;
			XmlElement eSpecialAlgorithm = (XmlElement)XMLUtil.findChildNode(eOptimization, "specialAlgorithm");
			if(eSpecialAlgorithm == null) return null;
			SpecialAlgorithm specialAlgorithm = new SpecialAlgorithm();
			string sValue = ""; 
			sValue = XMLUtil.getElementValueByName(eSpecialAlgorithm, "decomposition");
			if(sValue != null && sValue.Length > 0){
				if(sValue.StartsWith("t")) specialAlgorithm.decomposition = true;
				else if(sValue.StartsWith("f")) specialAlgorithm.decomposition = false;
			}
			sValue = XMLUtil.getElementValueByName(eSpecialAlgorithm, "globalOptimization");
			if(sValue != null && sValue.Length > 0){
				if(sValue.StartsWith("t")) specialAlgorithm.globalOptimization = true;
				else if(sValue.StartsWith("f")) specialAlgorithm.globalOptimization = false;
			}
			sValue = XMLUtil.getElementValueByName(eSpecialAlgorithm, "dynamicProgramming");
			if(sValue != null && sValue.Length > 0){
				if(sValue.StartsWith("t")) specialAlgorithm.dynamicProgramming = true;
				else if(sValue.StartsWith("f")) specialAlgorithm.dynamicProgramming = false;
			}
			sValue = XMLUtil.getElementValueByName(eSpecialAlgorithm, "heuristic");
			if(sValue != null && sValue.Length > 0){
				if(sValue.StartsWith("t")) specialAlgorithm.heuristic = true;
				else if(sValue.StartsWith("f")) specialAlgorithm.heuristic = false;
			}
			return specialAlgorithm;
		}//getOptimizationSpecialAlgorithm

		/// <summary>
		/// Get the hash map of other entity information. 
		/// </summary>
		/// <returns>the hash map of other entity info.</returns>
		public Hashtable getOtherEntityInfo(){
			if(m_otherEntityInfoHashMap != null) return m_otherEntityInfoHashMap;
			m_otherEntityInfoHashMap = new Hashtable();
			m_otherEntityDescriptionHashMap = new Hashtable();

			XmlElement eEntityData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "entityData");
			ArrayList vOtherElement = XMLUtil.getChildElementsByTagName(eEntityData, "other");
			int iNls	= vOtherElement==null?0:vOtherElement.Count;
			for(int i = 0; i < iNls; i++){
				XmlElement eOther = (XmlElement)(vOtherElement[i]);
				XmlNamedNodeMap	attributes =  eOther.Attributes;
				int n =attributes.Count;
				string sName = "";
				string sDescription = "";
				string sValue = XMLUtil.getElementValue(eOther);
				for (int j = 0; j < n; j++){
					XmlNode	attr = attributes.Item(j);
					string sAttributeName  = attr.LocalName;
					string sAttributeValue = attr.Value;
					if (sAttributeName.Equals("name")){
						sName = sAttributeValue;
					}
					else if (sAttributeName.Equals("description")){
						sDescription = sAttributeValue;
					}
				}
				m_otherEntityInfoHashMap.Add(sName, sValue);
				m_otherEntityDescriptionHashMap.Add(sName, sDescription);
			}
			return m_otherEntityInfoHashMap;
		}//getOtherEntityInfo

		/// <summary>
		/// Get the number of other entity info.  
		/// </summary>
		/// <returns>the number of other entity info. </returns>
		public int getOtherEntityInfoNumber(){
			getOtherEntityInfo();
			return m_otherEntityInfoHashMap.Count;
		}//getOtherEntityInfoNumber

		/// <summary>
		/// Get the string value from the other entity info hash map. 
		/// </summary>
		/// <param name="name">holds the name of entity info to get. </param>
		/// <returns>string value from the other entity info hash map, null if none. </returns>
		public string getOtherEntityInfoValueByName(string name){
			getOtherEntityInfo();
			if(m_otherEntityInfoHashMap.Contains(name)){
				return (string)m_otherEntityInfoHashMap[name];
			}
			else{ 
				return null;
			}
		}//getOtherEntityInfoValueByName

		/// <summary>
		/// Get the string value from the other entity info hash map. 
		/// </summary>
		/// <param name="name">holds the name of entity info to get. </param>
		/// <returns>string value from the other entity info hash map, null if none. </returns>
		public string getOtherEntityDescriptionByName(string name){
			getOtherEntityInfo();
			if(m_otherEntityDescriptionHashMap.Contains(name)){
				return (string)m_otherEntityDescriptionHashMap[name];
			}
			else{ 
				return null;
			}
		}//getOtherEntityDescriptionByName

		/// <summary>
		/// Get the names of all other entity info. 
		/// </summary>
		/// <returns>the names of all other entity info. </returns>
		public string[] getOtherEntityInfoNames(){
			getOtherEntityInfo();	
			System.Collections.ICollection nameCollection = m_otherEntityInfoHashMap.Keys;
			string[] msName = new string[nameCollection.Count];
			IDictionaryEnumerator dictionaryEnumerator = m_otherEntityInfoHashMap.GetEnumerator();
			int i = 0;
			while(dictionaryEnumerator.MoveNext()){
				msName[i] = (string)dictionaryEnumerator.Key;
				i++;
			}
			return msName;
		}//getOtherEntityInfoNames

		/// <summary>
		/// Get the values of all other entity info. 
		/// </summary>
		/// <returns>the values of all other entity info. </returns>
		public string[] getOtherEntityInfoValues(){
			getOtherEntityInfo();	
			System.Collections.ICollection valueCollection = m_otherEntityInfoHashMap.Values;
			string[] msValue = new string[valueCollection.Count];
			IDictionaryEnumerator dictionaryEnumerator = m_otherEntityInfoHashMap.GetEnumerator();
			int i = 0;
			while(dictionaryEnumerator.MoveNext()){
				msValue[i] = (string)dictionaryEnumerator.Value;
				i++;
			}
			return msValue;
		}//getOtherEntityInfoValues

		/// <summary>
		/// Get the descriptions of all other entity info. 
		/// </summary>
		/// <returns>the descriptions of all other entity info. </returns>
		public string[] getOtherEntityDescriptions(){
			getOtherEntityInfo();	
			System.Collections.ICollection descriptionCollection = m_otherEntityDescriptionHashMap.Values;
			string[] msDescription = new string[descriptionCollection.Count];
			IDictionaryEnumerator dictionaryEnumerator = m_otherEntityDescriptionHashMap.GetEnumerator();
			int i = 0;
			while(dictionaryEnumerator.MoveNext()){
				msDescription[i] = (string)dictionaryEnumerator.Value;
				i++;
			}
			return msDescription;
		}//getOtherEntityDescriptions

	}//class OSeLReader
}//namespace