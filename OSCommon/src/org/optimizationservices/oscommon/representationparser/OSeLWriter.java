/**
 * @(#)OSeLWriter 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.representationparser;
import java.util.GregorianCalendar;
import java.util.Vector;

import org.optimizationservices.oscommon.datastructure.osentity.AccessLimits;
import org.optimizationservices.oscommon.datastructure.osentity.FunctionType;
import org.optimizationservices.oscommon.datastructure.osentity.HardwareInfo;
import org.optimizationservices.oscommon.datastructure.osentity.Link;
import org.optimizationservices.oscommon.datastructure.osentity.Owner;
import org.optimizationservices.oscommon.datastructure.osentity.SpecialAlgorithm;
import org.optimizationservices.oscommon.datastructure.osentity.SpecialStructure;
import org.optimizationservices.oscommon.localinterface.OSEntity;
import org.optimizationservices.oscommon.localinterface.OSOption;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.XMLUtil;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.ProcessingInstruction;
/**
 * The <code>OSeLWriter</code> class is used to construct an instance that follows 
 * the OSeL format. 
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */
public class OSeLWriter extends OSgLWriter{

	/**
	 * m_eOSeL holds the OSeL root element.
	 */
	protected Element m_eOSeL = null;

	
	/**
	 * m_eEntityHeader holds the 1st child element entityHeader of root element OSeL.
	 */
	protected Element m_eEntityHeader = null;
	
	/**
	 * m_eEntityData holds the 2nd child element entityData of root element OSeL.
	 */
	protected Element m_eEntityData = null;
	
	/**
	 * constructor. 
	 *
	 */
	public OSeLWriter(){
		m_document = XMLUtil.createNewDocument();
		if(OSParameter.XSLT_LOCATION != null && OSParameter.XSLT_LOCATION.length() > 0){
			ProcessingInstruction xsltPI = m_document.createProcessingInstruction("xml-stylesheet",
	           "type=\"text/xsl\" href = \"" + OSParameter.XSLT_LOCATION + "OSeL.xslt\"");
			m_document.appendChild(xsltPI);     
		}
		m_eOSeL = createOSeLRoot();
		m_document.appendChild(m_eOSeL);
	}//constructor
	
	/**
	 * set the OSEntity, a standard os entity interface.  
	 * 
	 * @param osEntity holds the standard os entity interface.  
	 * @return whether the OSEntity is set successfully 
	 * @throws Exception if there are errors setting the OSEntity. 
	 */
   	public boolean setOSEntity(OSEntity osEntity) throws Exception{
		if(!setServiceURI(osEntity.getServiceURI())){ 
   			throw new Exception("setServiceURI Unsuccessful");
		}
		if(!setServiceName(osEntity.getServiceName())){ 
   			throw new Exception("setServiceName Unsuccessful");
		}
		if(!setRegistrationDate(osEntity.getRegistrationDate())){ 
   			throw new Exception("setRegistrationDate Unsuccessful");
		}
		if(!setMessage(osEntity.getMessage())){ 
   			throw new Exception("setMessage Unsuccessful");
		}
		if(!setLicenseRequired(osEntity.getLicenseRequired())){ 
   			throw new Exception("setLicenseRequired Unsuccessful");
		}
		if(!setUserNameRequired(osEntity.getUserNameRequired())){ 
   			throw new Exception("setUserNameRequired Unsuccessful");
		}
		if(!setPasswordRequired(osEntity.getPasswordRequired())){ 
   			throw new Exception("setPasswordRequired Unsuccessful");
		}
		if(!setAccessLimits(osEntity.getAccessLimits())){ 
   			throw new Exception("setAccessLimits Unsuccessful");
		}
		if(!setOwner(osEntity.getOwner())){ 
   			throw new Exception("setOwner Unsuccessful");
		}
		if(!setKeyWords(osEntity.getKeyWords())){ 
   			throw new Exception("setKeyWords Unsuccessful");
		}
		if(!setLinks(osEntity.getLinks())){ 
   			throw new Exception("setLinks Unsuccessful");
		}
		if(!setSystemDescription(osEntity.getSystemDescription())){ 
   			throw new Exception("setSystemDescription Unsuccessful");
		}
		if(!setSystemDedication(osEntity.getSystemDedication())){ 
   			throw new Exception("setSystemDedication Unsuccessful");
		}
		if(!setSystemHardwareInfo(osEntity.getSystemHardwareInfo())){ 
   			throw new Exception("setSystemHardwareInfo Unsuccessful");
		}
		if(!setServiceDescription(osEntity.getServiceDescription())){ 
   			throw new Exception("setServiceDescription Unsuccessful");
		}
		if(!setServiceType(osEntity.getServiceType())){ 
   			throw new Exception("setServiceType Unsuccessful");
		}
		if(!setServiceCategory(osEntity.getServiceCategory())){ 
   			throw new Exception("setServiceCategory Unsuccessful");
		}
		if(!setServiceSoftwareDescription(osEntity.getServiceSoftwareDescription())){ 
   			throw new Exception("setServiceSoftwareDescription Unsuccessful");
		}
		if(!setServiceAlgorithmDescription(osEntity.getServiceAlgorithmDescription())){ 
   			throw new Exception("setServiceAlgorithmDescription Unsuccessful");
		}
		if(!setServiceWebPage(osEntity.getServiceWebPage())){ 
   			throw new Exception("setServiceWebPage Unsuccessful");
		}
		if(!setServiceWSDLLocation(osEntity.getServiceWSDLLocation())){ 
   			throw new Exception("setServiceWSDLLocation Unsuccessful");
		}
		if(!setServiceLogoImageLink(osEntity.getServiceLogoImageLink())){ 
   			throw new Exception("setServiceLogoImageLink Unsuccessful");
		}
		if(!setDefaultOptionNamesAndValues(osEntity.getDefaultOptionNamesAndValues())){ 
   			throw new Exception("setDefaultOptionNamesAndValues Unsuccessful");
		}
		if(!setOptimizationDescription(osEntity.getOptimizationDescription())){ 
   			throw new Exception("setOptimizationDescription Unsuccessful");
		}
		if(!setOptimizationVariableType(osEntity.getOptimizationVariableType())){ 
   			throw new Exception("setOptimizationVariableType Unsuccessful");
		}
		if(!setOptimizationObjectiveType(osEntity.getOptimizationObjectiveType())){ 
   			throw new Exception("setOptimizationObjectiveType Unsuccessful");
		}
		if(!setOptimizationConstraintType(osEntity.getOptimizationConstraintType())){ 
   			throw new Exception("setOptimizationConstraintType Unsuccessful");
		}
		if(!setOptimizationObjectiveLinearity(osEntity.getOptimizationObjectiveLinearity())){ 
   			throw new Exception("setOptimizationObjectiveLinearity Unsuccessful");
		}
		if(!setOptimizationConstraintLinearity(osEntity.getOptimizationConstraintLinearity())){ 
   			throw new Exception("setOptimizationConstraintLinearity Unsuccessful");
		}
		if(!setOptimizationObjectiveDifferentiability(osEntity.getOptimizationObjectiveDifferentiability())){ 
   			throw new Exception("setOptimizationObjectiveDifferentiability Unsuccessful");
		}
		if(!setOptimizationConstraintDifferentiability(osEntity.getOptimizationConstraintDifferentiability())){ 
   			throw new Exception("setOptimizationConstraintDifferentiability Unsuccessful");
		}
		if(!setOptimizationParameterType(osEntity.getOptimizationParameterType())){ 
   			throw new Exception("setOptimizationParameterType Unsuccessful");
		}
		if(!setOptimizationStochasticity(osEntity.getOptimizationStochasticity())){ 
   			throw new Exception("setOptimizationStochasticity Unsuccessful");
		}
		if(!setOptimizationRealTime(osEntity.getOptimizationRealTime())){ 
   			throw new Exception("setOptimizationRealTime Unsuccessful");
		}
		if(!setOptimizationFunctionType(osEntity.getOptimizationFunctionType())){ 
   			throw new Exception("setOptimizationFunctionType Unsuccessful");
		}
		if(!setOptimizationSpecialStructure(osEntity.getOptimizationSpecialStructure())){ 
   			throw new Exception("setOptimizationSpecialStructure Unsuccessful");
		}
		if(!setOptimizationSpecialAlgorithm(osEntity.getOptimizationSpecialAlgorithm())){ 
   			throw new Exception("setOptimizationSpecialAlgorithm Unsuccessful");
		}
		if(osEntity.entityData.other != null && osEntity.entityData.other.length > 0){
			int n = osEntity.entityData.other.length;
			String[] msNames = new String[n];
			String[] msValues = new String[n];
			String[] msDescriptions = new String[n];
			for(int i = 0; i < n; i++){
				msNames[i] = osEntity.entityData.other[i].name;
				msValues[i] = osEntity.entityData.other[i].value;
				msDescriptions[i] = osEntity.entityData.other[i].description;
			}
			if(!setOtherEntityInfo(msNames, msValues, msDescriptions)){
				throw new Exception("setOtherEntity Info Unsuccessful");
			}			
		}
   		return true;
   	}//setOSEntity
   	
	
   	/**
	 * Set service uri.
	 * 
	 * @param serviceURI holds the uri of the service. 
	 * @return whether the service uri is set successfully. 
	 */
	public boolean setServiceURI(String serviceURI){
		try{
			if(serviceURI != null && serviceURI.length() > 0){
				Element eServiceURI = (Element)XMLUtil.findChildNode(m_eEntityHeader, "serviceURI");
				if(eServiceURI == null){
					eServiceURI = m_document.createElement("serviceURI");	
					eServiceURI.appendChild(m_document.createTextNode(serviceURI));
					m_eEntityHeader.insertBefore(eServiceURI, m_eEntityHeader.getFirstChild());				}
				else{
					XMLUtil.setElementValue(eServiceURI, serviceURI);
				}
			}
			else{
				XMLUtil.removeChildrenByName(m_eEntityHeader, "serviceURI");
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
				Element eServiceName = (Element)XMLUtil.findChildNode(m_eEntityHeader, "serviceName");
				if(eServiceName == null){
					eServiceName = m_document.createElement("serviceName");					
					eServiceName.appendChild(m_document.createTextNode(serviceName));
					nodeRef = XMLUtil.findChildNode(m_eEntityHeader, "registrationDate");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(m_eEntityHeader, "message");
					}
					m_eEntityHeader.insertBefore(eServiceName, nodeRef);
				}
				else{
					XMLUtil.setElementValue(eServiceName, serviceName);
				}
			}
			else{
				XMLUtil.removeChildrenByName(m_eEntityHeader, "serviceName");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setServiceName

	
   	/**
	 * Set time of the registration date.
	 * 
	 * @param date holds the registration date.
	 * @return whether registration date is set successfully. 
	 */
	public boolean setRegistrationDate(GregorianCalendar date){
		try{
			Node nodeRef = null;
			if(date != null && date.get(GregorianCalendar.YEAR) > 1970){
				Element eRegistrationDate = (Element)XMLUtil.findChildNode(m_eEntityHeader, "registrationDate");
				if(eRegistrationDate == null){
					eRegistrationDate = m_document.createElement("registrationDate");					
					eRegistrationDate.appendChild(m_document.createTextNode(XMLUtil.createXSDateTime(date)));
					nodeRef = XMLUtil.findChildNode(m_eEntityHeader, "message");
					m_eEntityHeader.insertBefore(eRegistrationDate, nodeRef);
				}
				else{
					XMLUtil.setElementValue(eRegistrationDate, XMLUtil.createXSDateTime(date));
				}
			}
			else{
				XMLUtil.removeChildrenByName(m_eEntityHeader, "registrationDate");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setRegistrationDate
	
   	/**
	 * Set the message. 
	 * 
	 * @param message holds the message. 
	 * @return whether the message is set successfully. 
	 */
	public boolean setMessage(String message){
		try{
			Node nodeRef = null;
			if(message != null && message.length() > 0){
				Element eMessage = (Element)XMLUtil.findChildNode(m_eEntityHeader, "message");
				if(eMessage == null){
					eMessage = m_document.createElement("message");					
					eMessage.appendChild(m_document.createTextNode(message));
					m_eEntityHeader.insertBefore(eMessage, nodeRef);
				}
				else{
					XMLUtil.setElementValue(eMessage, message);
				}
			}
			else{
				XMLUtil.removeChildrenByName(m_eEntityHeader, "message");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setMessage

	
	/**
	 * Set whether the license is reqired of the service or not. 
	 * 
	 * @param licenseRequired holds whether the license is reqired of the service or not.
	 * 
	 * @return whether the licenseRequired is set successfully or not. 
	 */
	public boolean setLicenseRequired(boolean licenseRequired){
		if(!licenseRequired) return true;
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eEntityData, "general");
		if(eGeneral == null){
			eGeneral = m_document.createElement("general");
			m_eEntityData.insertBefore(eGeneral, m_eEntityData.getFirstChild());
		}
		Element eAccess = (Element)XMLUtil.findChildNode(eGeneral, "access");
		if(eAccess == null){
			eAccess = m_document.createElement("access");
			eGeneral.insertBefore(eAccess, eGeneral.getFirstChild());
		}
		Element eType = (Element)XMLUtil.findChildNode(eAccess, "type");
		if(eType == null){
			eType = m_document.createElement("type");
			eAccess.insertBefore(eType, eAccess.getFirstChild());
		}
		eType.setAttribute("licenseRequired", licenseRequired+"");
		return true;
	}//setLicenseRequired

	
	/**
	 * Set whether the user name is reqired of the service or not. 
	 * 
	 * @param userNameRequired holds whether the user name is reqired of the service or not.
	 * 
	 * @return whether the userNameRequired is set successfully or not. 
	 */
	public boolean setUserNameRequired(boolean userNameRequired){
		if(!userNameRequired) return true;
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eEntityData, "general");
		if(eGeneral == null){
			eGeneral = m_document.createElement("general");
			m_eEntityData.insertBefore(eGeneral, m_eEntityData.getFirstChild());
		}
		Element eAccess = (Element)XMLUtil.findChildNode(eGeneral, "access");
		if(eAccess == null){
			eAccess = m_document.createElement("access");
			eGeneral.insertBefore(eAccess, eGeneral.getFirstChild());
		}
		Element eType = (Element)XMLUtil.findChildNode(eAccess, "type");
		if(eType == null){
			eType = m_document.createElement("type");
			eAccess.insertBefore(eType, eAccess.getFirstChild());
		}
		eType.setAttribute("userNameRequired", userNameRequired+"");
		return true;
	}//setUserNameRequired


	/**
	 * Set whether the password is reqired of the service or not. 
	 * 
	 * @param passwordRequired holds whether the password is reqired of the service or not.
	 * 
	 * @return whether the passwordRequired is set successfully or not. 
	 */
	public boolean setPasswordRequired(boolean passwordRequired){
		if(!passwordRequired) return true;
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eEntityData, "general");
		if(eGeneral == null){
			eGeneral = m_document.createElement("general");
			m_eEntityData.insertBefore(eGeneral, m_eEntityData.getFirstChild());
		}
		Element eAccess = (Element)XMLUtil.findChildNode(eGeneral, "access");
		if(eAccess == null){
			eAccess = m_document.createElement("access");
			eGeneral.insertBefore(eAccess, eGeneral.getFirstChild());
		}
		Element eType = (Element)XMLUtil.findChildNode(eAccess, "type");
		if(eType == null){
			eType = m_document.createElement("type");
			eAccess.insertBefore(eType, eAccess.getFirstChild());
		}
		eType.setAttribute("passwordRequired", passwordRequired+"");
		return true;
	}//setPasswordRequired

	/**
	 * Set the access limit information of the service entity. 
	 * 
	 * @param accessLimits holds the access limit information.
	 * 
	 * @return whether the access limit information is set successfully or not. 
	 */
	public boolean setAccessLimits(AccessLimits accessLimits){
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eEntityData, "general");
		if(eGeneral == null){
			if(accessLimits == null) return true;
			eGeneral = m_document.createElement("general");
			m_eEntityData.insertBefore(eGeneral, m_eEntityData.getFirstChild());
		}
		Element eAccess = (Element)XMLUtil.findChildNode(eGeneral, "access");
		if(eAccess == null){
			if(accessLimits == null) return true;
			eAccess = m_document.createElement("access");
			eGeneral.insertBefore(eAccess, eGeneral.getFirstChild());
		}
		if(accessLimits == null){
			XMLUtil.removeChildrenByName(eAccess, "limits");
			return true;
		}
		Element eLimits = (Element)XMLUtil.findChildNode(eAccess, "limits");
		if(eLimits != null){
			XMLUtil.removeChildrenByName(eAccess, "limits");
		}
		eLimits = m_document.createElement("limits");
		if(!Double.isInfinite(accessLimits.maxDiskSpace)){
			Element eMaxDiskSpace = m_document.createElement("maxDiskSpace");
			eMaxDiskSpace.appendChild(m_document.createTextNode(Double.isInfinite(accessLimits.maxDiskSpace)?"INF":accessLimits.maxDiskSpace+""));	
			eLimits.appendChild(eMaxDiskSpace);
		}
		if(!Double.isInfinite(accessLimits.maxMemory)){
			Element eMaxMemory = m_document.createElement("maxMemory");
			eMaxMemory.appendChild(m_document.createTextNode(Double.isInfinite(accessLimits.maxMemory)?"INF":accessLimits.maxMemory+""));	
			eLimits.appendChild(eMaxMemory);
		}
		if(accessLimits.maxJobs >= 0){
			Element eMaxJobs = m_document.createElement("maxJobs");
			eMaxJobs.appendChild(m_document.createTextNode(accessLimits.maxJobs + ""));	
			eLimits.appendChild(eMaxJobs);
		}
		if(accessLimits.maxVariables >= 0){
			Element eMaxVariables = m_document.createElement("maxVariables");
			eMaxVariables.appendChild(m_document.createTextNode(accessLimits.maxVariables + ""));	
			eLimits.appendChild(eMaxVariables);
		}
		if(accessLimits.maxBinaryVariables >= 0){
			Element eMaxBinaryVariables = m_document.createElement("maxBinaryVariables");
			eMaxBinaryVariables.appendChild(m_document.createTextNode(accessLimits.maxBinaryVariables + ""));	
			eLimits.appendChild(eMaxBinaryVariables);
		}
		if(accessLimits.maxIntegerVariables >= 0){
			Element eMaxIntegerVariables = m_document.createElement("maxIntegerVariables");
			eMaxIntegerVariables.appendChild(m_document.createTextNode(accessLimits.maxIntegerVariables + ""));	
			eLimits.appendChild(eMaxIntegerVariables);
		}
		if(accessLimits.maxObjectives >= 0){
			Element eMaxObjectives = m_document.createElement("maxObjectives");
			eMaxObjectives.appendChild(m_document.createTextNode(accessLimits.maxObjectives + ""));	
			eLimits.appendChild(eMaxObjectives);
		}
		if(accessLimits.maxConstraints >= 0){
			Element eMaxConstraints = m_document.createElement("maxConstraints");
			eMaxConstraints.appendChild(m_document.createTextNode(accessLimits.maxConstraints + ""));	
			eLimits.appendChild(eMaxConstraints);
		}
		if(accessLimits.maxNonzeroLinearConstraintCoefficients >= 0){
			Element eMaxNonzeroLinearConstraintCoefficients = m_document.createElement("maxNonzeroLinearConstraintCoefficients");
			eMaxNonzeroLinearConstraintCoefficients.appendChild(m_document.createTextNode(accessLimits.maxNonzeroLinearConstraintCoefficients + ""));	
			eLimits.appendChild(eMaxNonzeroLinearConstraintCoefficients);
		}
		eAccess.appendChild(eLimits);
		return true;
	}//setAccessLimits
	
	/**
	 * Set the owner information of the service entity. 
	 * 
	 * @param owner holds the service owner.
	 * 
	 * @return whether the owner information is set successfully or not. 
	 */
	public boolean setOwner(Owner owner){
		Node nodeRef = null;
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eEntityData, "general");
		if(eGeneral == null && owner == null){
			return true;
		}
		if(eGeneral != null && owner == null){
			XMLUtil.removeChildrenByName(eGeneral, "owner");
			return true;
		}
		if(eGeneral == null){
			eGeneral = m_document.createElement("general");
			m_eEntityData.insertBefore(eGeneral, m_eEntityData.getFirstChild());
		}
		Element eOwner = (Element)XMLUtil.findChildNode(eGeneral, "owner");
		if(eOwner != null){
			XMLUtil.removeChildrenByName(eGeneral, "owner");
		}
		eOwner = m_document.createElement("owner");
		nodeRef = XMLUtil.findChildNode(eGeneral, "access");
		if(nodeRef != null){
			eGeneral.insertBefore(eOwner, nodeRef.getNextSibling());			
		}
		else{
			eGeneral.insertBefore(eOwner, eGeneral.getFirstChild());
		}			
		if(owner.names != null && owner.names.length() > 0){
			Element eNames = m_document.createElement("names");
			eNames.appendChild(m_document.createTextNode(owner.names));	
			eOwner.appendChild(eNames);
		}
		if(owner.description != null && owner.description.length() > 0){
			Element eDescription = m_document.createElement("description");
			eDescription.appendChild(m_document.createTextNode(owner.description));	
			eOwner.appendChild(eDescription);
		}
		if(owner.category != null && owner.category.length() > 0){
			Element eCategory = m_document.createElement("category");
			eCategory.appendChild(m_document.createTextNode(owner.category));	
			eOwner.appendChild(eCategory);
		}
		if(owner.mainWebPage != null && owner.mainWebPage.length() > 0){
			Element eMainWebPage = m_document.createElement("mainWebPage");
			eMainWebPage.appendChild(m_document.createTextNode(owner.mainWebPage));	
			eOwner.appendChild(eMainWebPage);
		}
		if(owner.logoImageLink != null && owner.logoImageLink.length() > 0){
			Element eLogoImageLink = m_document.createElement("logoImageLink");
			eLogoImageLink.appendChild(m_document.createTextNode(owner.logoImageLink));	
			eOwner.appendChild(eLogoImageLink);
		}
		if(owner.contact != null){
			Element eContact = m_document.createElement("contact");
			if(owner.contact.name != null && owner.contact.name.length() > 0){
				Element eName = m_document.createElement("name");
				eName.appendChild(m_document.createTextNode(owner.contact.name));	
				eContact.appendChild(eName);
			}
			if(owner.contact.title != null && owner.contact.title.length() > 0){
				Element eTitle = m_document.createElement("title");
				eTitle.appendChild(m_document.createTextNode(owner.contact.title));	
				eContact.appendChild(eTitle);
			}
			if(owner.contact.address != null && owner.contact.address.length() > 0){
				Element eAddress = m_document.createElement("address");
				eAddress.appendChild(m_document.createTextNode(owner.contact.address));	
				eContact.appendChild(eAddress);
			}
			if(owner.contact.phone != null && owner.contact.phone.length() > 0){
				Element ePhone = m_document.createElement("phone");
				ePhone.appendChild(m_document.createTextNode(owner.contact.phone));	
				eContact.appendChild(ePhone);
			}
			if(owner.contact.fax != null && owner.contact.fax.length() > 0){
				Element eFax = m_document.createElement("fax");
				eFax.appendChild(m_document.createTextNode(owner.contact.fax));	
				eContact.appendChild(eFax);
			}
			if(owner.contact.email != null && owner.contact.email.length() > 0){
				Element eEmail = m_document.createElement("email");
				eEmail.appendChild(m_document.createTextNode(owner.contact.email));	
				eContact.appendChild(eEmail);
			}
			if(owner.contact.webPage != null && owner.contact.webPage.length() > 0){
				Element eWebPage = m_document.createElement("name");
				eWebPage.appendChild(m_document.createTextNode(owner.contact.webPage));	
				eContact.appendChild(eWebPage);
			}
			eOwner.appendChild(eContact);
		}
		return true;
	}//setOwner
	
	/**
	 * Set the key words of the service. 
	 * 
	 * @param keyWords holds the service key words.
	 * 
	 * @return whether the key words of the service are set successfully or not. 
	 */
	public boolean setKeyWords(String[] keyWords){
		Node nodeRef = null;
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eEntityData, "general");
		if(eGeneral == null && (keyWords == null || keyWords.length <= 0)){
			return true;
		}
		if(eGeneral != null && (keyWords == null || keyWords.length <= 0)){
			XMLUtil.removeChildrenByName(eGeneral, "keyWords");
			return true;
		}
		if(eGeneral == null){
			eGeneral = m_document.createElement("general");
			m_eEntityData.insertBefore(eGeneral, m_eEntityData.getFirstChild());
		}
		Element eKeyWords = (Element)XMLUtil.findChildNode(eGeneral, "keyWords");
		if(eKeyWords != null){
			XMLUtil.removeChildrenByName(eGeneral, "keyWords");
		}
		eKeyWords = m_document.createElement("keyWords");
		nodeRef = XMLUtil.findChildNode(eGeneral, "owner");
		if(nodeRef != null){
			eGeneral.insertBefore(eKeyWords, nodeRef.getNextSibling());			
		}
		else{
			nodeRef = XMLUtil.findChildNode(eGeneral, "access");
			if(nodeRef != null){
				eGeneral.insertBefore(eKeyWords, nodeRef.getNextSibling());			
			}
			else{
				eGeneral.insertBefore(eKeyWords, eGeneral.getFirstChild());
			}			
		}		
		int iKeys = keyWords.length;
		for(int i = 0; i < iKeys; i++){
			if(keyWords[i]!= null && keyWords[i].length() > 0){
				Element eKey = m_document.createElement("key");
				eKey.appendChild(m_document.createTextNode(keyWords[i]));	
				eKeyWords.appendChild(eKey);
			}			
		}
		return true;
	}//setKeyWords
	
	/**
	 * Set the links of the service. 
	 * 
	 * @param links holds a Link array of the service links.  
	 * @return whether the links of the service are set successfully. 
	 */
	public boolean setLinks(Link[] links){
		Element eGeneral = (Element)XMLUtil.findChildNode(m_eEntityData, "general");
		if(eGeneral == null && (links == null || links.length <= 0)){
			return true;
		}
		if(eGeneral != null && (links == null || links.length <= 0)){
			XMLUtil.removeChildrenByName(eGeneral, "links");
			return true;
		}
		if(eGeneral == null){
			eGeneral = m_document.createElement("general");
			m_eEntityData.insertBefore(eGeneral, m_eEntityData.getFirstChild());
		}
		Element eLinks = (Element)XMLUtil.findChildNode(eGeneral, "links");
		if(eLinks != null){
			XMLUtil.removeChildrenByName(eGeneral, "links");
		}
		eLinks = m_document.createElement("links");
		eGeneral.appendChild(eLinks);			
		int iLinks = links.length;
		for(int i = 0; i < iLinks; i++){
			if(links[i]!= null){
				Element eLink = m_document.createElement("link");
				if(links[i].type != null && links[i].type.length() > 0){
					eLink.setAttribute("type", links[i].type);						
				}
				if(links[i].description != null && links[i].description.length() > 0){
					eLink.setAttribute("description", links[i].description);						
				}
				if(links[i].value != null && links[i].value.length() > 0){
					eLink.appendChild(m_document.createTextNode(links[i].value));						
				}
				eLinks.appendChild(eLink);
			}			
		}
		return true;
	}//setLinks

	
	/**
	 * Set the system description. 
	 * 
	 * @param description holds the system description. 
	 * 
	 * @return whether the system description is set successfully or not. 
	 */
	public boolean setSystemDescription(String description){
		Node nodeRef = null;
		Element eSystem = (Element)XMLUtil.findChildNode(m_eEntityData, "system");
		if(eSystem == null){
			eSystem = m_document.createElement("system");
			nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
			if(nodeRef != null){
				m_eEntityData.insertBefore(eSystem, nodeRef.getNextSibling());			
			}
			else{
				m_eEntityData.insertBefore(eSystem, m_eEntityData.getFirstChild());
			}			
		}
		if(description == null || description.length() <= 0){
			XMLUtil.removeChildrenByName(eSystem, "description");
			return true;
		}
		Element eDescription = (Element)XMLUtil.findChildNode(eSystem, "description");
		if(eDescription != null){
			XMLUtil.removeChildrenByName(eSystem, "description");
		}
		eDescription = m_document.createElement("description");
		eDescription.appendChild(m_document.createTextNode(description));
		eSystem.appendChild(eDescription);
		return true;
	}//setSystemDescription
	
	/**
	 * Set the system dedication. 
	 * 
	 * @param dedication holds the system dedication, a double between 0 and 1 with 1 being fully dedicated.  
	 * 
	 * @return whether the system dedication.  is set successfully or not. 
	 */
	public boolean setSystemDedication(double dedication){
		if(dedication < 0 || dedication > 1) return false;		
		if(Double.isNaN(dedication) || dedication==1.0) return  true;
		Node nodeRef = null;
		Element eSystem = (Element)XMLUtil.findChildNode(m_eEntityData, "system");
		if(eSystem == null){
			eSystem = m_document.createElement("system");
			nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
			if(nodeRef != null){
				m_eEntityData.insertBefore(eSystem, nodeRef.getNextSibling());			
			}
			else{
				m_eEntityData.insertBefore(eSystem, m_eEntityData.getFirstChild());
			}			
		}
		Element eDedication = (Element)XMLUtil.findChildNode(eSystem, "dedication");
		if(eDedication != null){
			XMLUtil.removeChildrenByName(eSystem, "dedication");
		}
		eDedication = m_document.createElement("dedication");
		eDedication.appendChild(m_document.createTextNode(dedication + ""));
		eSystem.appendChild(eDedication);
		return true;
	}//setSystemDedication
	
	
	/**
	 * Set the system hardware information.
	 * 
	 * @param hardwareInfo holds the system hardware information.
	 * 
	 * @return whether the system hardware information is set successfully or not. 
	 */
	public boolean setSystemHardwareInfo(HardwareInfo hardwareInfo){
		Node nodeRef = null;
		Element eSystem = (Element)XMLUtil.findChildNode(m_eEntityData, "system");
		if(eSystem == null){
			eSystem = m_document.createElement("system");
			nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
			if(nodeRef != null){
				m_eEntityData.insertBefore(eSystem, nodeRef.getNextSibling());			
			}
			else{
				m_eEntityData.insertBefore(eSystem, m_eEntityData.getFirstChild());
			}			
		}
		if(hardwareInfo == null){
			XMLUtil.removeChildrenByName(eSystem, "hardware");
			return true;
		}
		Element eHardwareInfo = (Element)XMLUtil.findChildNode(eSystem, "hardware");
		if(eHardwareInfo != null){
			XMLUtil.removeChildrenByName(eSystem, "hardware");
		}
		eHardwareInfo = m_document.createElement("hardware");
		if(hardwareInfo.cpuNumber > 0){
			Element eCPUNumber = m_document.createElement("cpuNumber");
			eCPUNumber.appendChild(m_document.createTextNode(hardwareInfo.cpuNumber + ""));	
			eHardwareInfo.appendChild(eCPUNumber);
		}
		if(hardwareInfo.cpuSpeed > 0){
			Element eCPUSpeed = m_document.createElement("cpuSpeed");
			eCPUSpeed.appendChild(m_document.createTextNode(hardwareInfo.cpuSpeed + ""));	
			eHardwareInfo.appendChild(eCPUSpeed);
		}
		if(hardwareInfo.memorySize > 0){
			Element eMemorySize = m_document.createElement("memorySize");
			eMemorySize.appendChild(m_document.createTextNode(hardwareInfo.memorySize + ""));	
			eHardwareInfo.appendChild(eMemorySize);
		}
		if(hardwareInfo.busSpeed > 0){
			Element eBusSpeed = m_document.createElement("busSpeed");
			eBusSpeed.appendChild(m_document.createTextNode(hardwareInfo.busSpeed + ""));	
			eHardwareInfo.appendChild(eBusSpeed);
		}
		if(hardwareInfo.diskSpace > 0){
			Element eDiskSpace = m_document.createElement("diskSpace");
			eDiskSpace.appendChild(m_document.createTextNode(hardwareInfo.diskSpace + ""));	
			eHardwareInfo.appendChild(eDiskSpace);
		}
		if(hardwareInfo.nicSpeed > 0){
			Element eNICSpeed = m_document.createElement("nicSpeed");
			eNICSpeed.appendChild(m_document.createTextNode(hardwareInfo.nicSpeed + ""));	
			eHardwareInfo.appendChild(eNICSpeed);
		}
		if(hardwareInfo.downloadSpeed > 0){
			Element eDownloadSpeed = m_document.createElement("downloadSpeed");
			eDownloadSpeed.appendChild(m_document.createTextNode(hardwareInfo.downloadSpeed + ""));	
			eHardwareInfo.appendChild(eDownloadSpeed);
		}
		if(hardwareInfo.uploadSpeed > 0){
			Element eUploadSpeed = m_document.createElement("uploadSpeed");
			eUploadSpeed.appendChild(m_document.createTextNode(hardwareInfo.uploadSpeed + ""));	
			eHardwareInfo.appendChild(eUploadSpeed);
		}		
		eSystem.appendChild(eHardwareInfo);
		return true;
	}//setSystemHardwareInfo

	
	/**
	 * Set the service description. 
	 * 
	 * @param description holds the service description.
	 * 
	 * @return whether the service description is set successfully or not. 
	 */
	public boolean setServiceDescription(String description){
		Node nodeRef = null;
		Element eService = (Element)XMLUtil.findChildNode(m_eEntityData, "service");
		if(eService == null){
			eService = m_document.createElement("service");
			nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
			if(nodeRef != null){
				m_eEntityData.insertBefore(eService, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
				if(nodeRef != null){
					m_eEntityData.insertBefore(eService, nodeRef.getNextSibling());			
				}
				else{
					m_eEntityData.insertBefore(eService, m_eEntityData.getFirstChild());
				}			
			}			
		}
		if(description == null || description.length() <= 0){
			XMLUtil.removeChildrenByName(eService, "description");
			return true;
		}
		Element eDescription = (Element)XMLUtil.findChildNode(eService, "description");
		if(eDescription != null){
			XMLUtil.removeChildrenByName(eService, "description");
		}
		eDescription = m_document.createElement("description");
		eDescription.appendChild(m_document.createTextNode(description));
		eService.appendChild(eDescription);
		return true;
	}//setServiceDescription

	
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
		Element eService = (Element)XMLUtil.findChildNode(m_eEntityData, "service");
		if(eService == null){
			eService = m_document.createElement("service");
			nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
			if(nodeRef != null){
				m_eEntityData.insertBefore(eService, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
				if(nodeRef != null){
					m_eEntityData.insertBefore(eService, nodeRef.getNextSibling());			
				}
				else{
					m_eEntityData.insertBefore(eService, m_eEntityData.getFirstChild());
				}			
			}			
		}
		if(type == null || type.length() <= 0){
			XMLUtil.removeChildrenByName(eService, "type");
			return true;
		}
		if(!type.equals("solver") && 
				   !type.equals("analyzer") &&
				   !type.equals("scheduler") &&
				   !type.equals("simulation") &&
				   !type.equals("registry") &&
				   !type.equals("modeler") &&
				   !type.equals("agent")) return false;
		Element eType = (Element)XMLUtil.findChildNode(eService, "type");
		if(eType != null){
			XMLUtil.removeChildrenByName(eService, "type");
		}
		eType = m_document.createElement("type");
		eType.appendChild(m_document.createTextNode(type));
		eService.appendChild(eType);
		return true;
	}//setServiceType

	
	/**
	 * Set the service category. 
	 * 
	 * @param category holds the service category, which can be:
	 * education, government, organization, company, military, personal, other
	 * 
	 * @return whether the service category is set successfully or not. 
	 */
	public boolean setServiceCategory(String category){
		Node nodeRef = null;
		Element eService = (Element)XMLUtil.findChildNode(m_eEntityData, "service");
		if(eService == null){
			eService = m_document.createElement("service");
			nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
			if(nodeRef != null){
				m_eEntityData.insertBefore(eService, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
				if(nodeRef != null){
					m_eEntityData.insertBefore(eService, nodeRef.getNextSibling());			
				}
				else{
					m_eEntityData.insertBefore(eService, m_eEntityData.getFirstChild());
				}			
			}			
		}
		if(category == null || category.length() <= 0){
			XMLUtil.removeChildrenByName(eService, "category");
			return true;
		}
		if(!category.equals("education") && 
				   !category.equals("government") &&
				   !category.equals("organization") &&
				   !category.equals("company") &&
				   !category.equals("military") &&
				   !category.equals("personal") &&
				   !category.equals("other")) return false;
		Element eCategory = (Element)XMLUtil.findChildNode(eService, "category");
		if(eCategory != null){
			XMLUtil.removeChildrenByName(eService, "category");
		}
		eCategory = m_document.createElement("category");
		eCategory.appendChild(m_document.createTextNode(category));
		eService.appendChild(eCategory);
		return true;
	}//setServiceCategory

	
	/**
	 * Set the service software description. 
	 * 
	 * @param softwareDescription holds the software description.
	 * 
	 * @return whether the software description is set successfully or not. 
	 */
	public boolean setServiceSoftwareDescription(String softwareDescription){
		Node nodeRef = null;
		Element eService = (Element)XMLUtil.findChildNode(m_eEntityData, "service");
		if(eService == null){
			eService = m_document.createElement("service");
			nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
			if(nodeRef != null){
				m_eEntityData.insertBefore(eService, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
				if(nodeRef != null){
					m_eEntityData.insertBefore(eService, nodeRef.getNextSibling());			
				}
				else{
					m_eEntityData.insertBefore(eService, m_eEntityData.getFirstChild());
				}			
			}			
		}
		if(softwareDescription == null || softwareDescription.length() <= 0){
			XMLUtil.removeChildrenByName(eService, "software");
			return true;
		}
		Element eSoftwareDescription = (Element)XMLUtil.findChildNode(eService, "software");
		if(eSoftwareDescription != null){
			XMLUtil.removeChildrenByName(eService, "software");
		}
		eSoftwareDescription = m_document.createElement("software");
		eSoftwareDescription.appendChild(m_document.createTextNode(softwareDescription));
		eService.appendChild(eSoftwareDescription);
		return true;
	}//setServiceSoftwareDescription


	/**
	 * Set the algorithm description. 
	 * 
	 * @param algorithmDescription holds the algorithm description.
	 * 
	 * @return whether the algorithm description is set successfully or not. 
	 */
	public boolean setServiceAlgorithmDescription(String algorithmDescription){
		Node nodeRef = null;
		Element eService = (Element)XMLUtil.findChildNode(m_eEntityData, "service");
		if(eService == null){
			eService = m_document.createElement("service");
			nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
			if(nodeRef != null){
				m_eEntityData.insertBefore(eService, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
				if(nodeRef != null){
					m_eEntityData.insertBefore(eService, nodeRef.getNextSibling());			
				}
				else{
					m_eEntityData.insertBefore(eService, m_eEntityData.getFirstChild());
				}			
			}			
		}
		if(algorithmDescription == null || algorithmDescription.length() <= 0){
			XMLUtil.removeChildrenByName(eService, "algorithmDescription");
			return true;
		}
		Element eAlgorithmDescription = (Element)XMLUtil.findChildNode(eService, "description");
		if(eAlgorithmDescription != null){
			XMLUtil.removeChildrenByName(eService, "description");
		}
		eAlgorithmDescription = m_document.createElement("description");
		eAlgorithmDescription.appendChild(m_document.createTextNode(algorithmDescription));
		eService.appendChild(eAlgorithmDescription);
		return true;
	}//setServiceAlgorithmDescription

	
	/**
	 * Set the service web page. 
	 * 
	 * @param webPage holds the service web page.
	 * 
	 * @return whether the service web page is set successfully or not. 
	 */
	public boolean setServiceWebPage(String webPage){
		Node nodeRef = null;
		Element eService = (Element)XMLUtil.findChildNode(m_eEntityData, "service");
		if(eService == null){
			eService = m_document.createElement("service");
			nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
			if(nodeRef != null){
				m_eEntityData.insertBefore(eService, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
				if(nodeRef != null){
					m_eEntityData.insertBefore(eService, nodeRef.getNextSibling());			
				}
				else{
					m_eEntityData.insertBefore(eService, m_eEntityData.getFirstChild());
				}			
			}			
		}
		if(webPage == null || webPage.length() <= 0){
			XMLUtil.removeChildrenByName(eService, "webPage");
			return true;
		}
		Element eWebPage = (Element)XMLUtil.findChildNode(eService, "webPage");
		if(eWebPage != null){
			XMLUtil.removeChildrenByName(eService, "webPage");
		}
		eWebPage = m_document.createElement("webPage");
		eWebPage.appendChild(m_document.createTextNode(webPage));
		eService.appendChild(eWebPage);
		return true;
	}//setServiceWebPage

	
	/**
	 * Set the service wsdl location. 
	 * 
	 * @param wsdlLocation holds the service wsdl location.
	 * 
	 * @return whether the service wsdlLocation is set successfully or not. 
	 */
	public boolean setServiceWSDLLocation(String wsdlLocation){
		Node nodeRef = null;
		Element eService = (Element)XMLUtil.findChildNode(m_eEntityData, "service");
		if(eService == null){
			eService = m_document.createElement("service");
			nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
			if(nodeRef != null){
				m_eEntityData.insertBefore(eService, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
				if(nodeRef != null){
					m_eEntityData.insertBefore(eService, nodeRef.getNextSibling());			
				}
				else{
					m_eEntityData.insertBefore(eService, m_eEntityData.getFirstChild());
				}			
			}			
		}
		if(wsdlLocation == null || wsdlLocation.length() <= 0){
			XMLUtil.removeChildrenByName(eService, "wsdlLocation");
			return true;
		}
		Element eWsdlLocation = (Element)XMLUtil.findChildNode(eService, "wsdlLocation");
		if(eWsdlLocation != null){
			XMLUtil.removeChildrenByName(eService, "wsdlLocation");
		}
		eWsdlLocation = m_document.createElement("wsdlLocation");
		eWsdlLocation.appendChild(m_document.createTextNode(wsdlLocation));
		eService.appendChild(eWsdlLocation);
		return true;
	}//setServiceWSDLLocation

	
	/**
	 * Set the service logo image link. 
	 * 
	 * @param logoImageLink holds the service logo image link.
	 * 
	 * @return whether the service logoImageLink is set successfully or not. 
	 */
	public boolean setServiceLogoImageLink(String logoImageLink){
		Node nodeRef = null;
		Element eService = (Element)XMLUtil.findChildNode(m_eEntityData, "service");
		if(eService == null){
			eService = m_document.createElement("service");
			nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
			if(nodeRef != null){
				m_eEntityData.insertBefore(eService, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
				if(nodeRef != null){
					m_eEntityData.insertBefore(eService, nodeRef.getNextSibling());			
				}
				else{
					m_eEntityData.insertBefore(eService, m_eEntityData.getFirstChild());
				}			
			}			
		}
		if(logoImageLink == null || logoImageLink.length() <= 0){
			XMLUtil.removeChildrenByName(eService, "logoImageLink");
			return true;
		}
		Element eLogoImageLink = (Element)XMLUtil.findChildNode(eService, "logoImageLink");
		if(eLogoImageLink != null){
			XMLUtil.removeChildrenByName(eService, "logoImageLink");
		}
		eLogoImageLink = m_document.createElement("logoImageLink");
		eLogoImageLink.appendChild(m_document.createTextNode(logoImageLink));
		eService.appendChild(eLogoImageLink);
		return true;
	}//setServiceLogoImageLink

	/**
	 * Set the default option names and values in the standard OSOption structure which 
	 * is specified by the OSoL schema. 
	 * 
	 * @param osOption holds the default option names and values in the standard OSOption structure. 
	 * @return wehter the the default option names and values are set successfully or not. 
	 */
	public boolean setDefaultOptionNamesAndValues(OSOption osOption){
		Node nodeRef = null;
		Element eJob = (Element)XMLUtil.findChildNode(m_eEntityData, "job");
		if(eJob == null && osOption == null){
			return true;
		}
		if(eJob != null && osOption == null){
			XMLUtil.removeChildrenByName(eJob, "osol");
			return true;
		}
		if(eJob == null){
			eJob = m_document.createElement("job");
			nodeRef = XMLUtil.findChildNode(m_eEntityData, "service");			
			if(nodeRef != null){
				m_eEntityData.insertBefore(eJob, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
				if(nodeRef != null){
					m_eEntityData.insertBefore(eJob, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
					if(nodeRef != null){
						m_eEntityData.insertBefore(eJob, nodeRef.getNextSibling());			
					}
					else{
						m_eEntityData.insertBefore(eJob, m_eEntityData.getFirstChild());
					}			
				}			
			}			
		}
		Element eOSoL = (Element)XMLUtil.findChildNode(eJob, "osol");
		if(eOSoL != null){
			XMLUtil.removeChildrenByName(eJob, "osol");
		}
		OSoLWriter osolWriter = new OSoLWriter();
		try {
			osolWriter.setOSOption(osOption);
		} 
		catch (Exception e) {
			e.printStackTrace();
		}
		eOSoL =  (Element)m_document.importNode(osolWriter.m_eOSoL, true);
		XMLUtil.removeAllAttributes(eOSoL);
		eJob.appendChild(eOSoL);
		return true;
	}//setDefaultOptionNamesAndValues
	
	/**
	 * Set the optimization description. 
	 * 
	 * @param description holds the optimization description.
	 * 
	 * @return whether the optimization description is set successfully or not. 
	 */
	public boolean setOptimizationDescription(String description){
		Node nodeRef = null;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eEntityData, "optimization");
		if(eOptimization == null){
			eOptimization = m_document.createElement("optimization");
			nodeRef = XMLUtil.findChildNode(m_eEntityData, "job");			
			if(nodeRef != null){
				m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "service");			
				if(nodeRef != null){
					m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
					if(nodeRef != null){
						m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
						if(nodeRef != null){
							m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							m_eEntityData.insertBefore(eOptimization, m_eEntityData.getFirstChild());
						}		
					}		
				}			
			}			
		}
		if(description == null || description.length() <= 0){
			XMLUtil.removeChildrenByName(eOptimization, "description");
			return true;
		}
		Element eDescription = (Element)XMLUtil.findChildNode(eOptimization, "description");
		if(eDescription != null){
			XMLUtil.removeChildrenByName(eOptimization, "description");
		}
		eDescription = m_document.createElement("description");
		eDescription.appendChild(m_document.createTextNode(description));
		eOptimization.appendChild(eDescription);
		return true;
	}//setOptimizationDescription
	
	/**
	 * Set the optimization variable type. 
	 * 
	 * @param variableType holds the optimization variable type, which can be:
	 * continuous, pureBinary, mixedBinary, pureInteger, mixedInteger, discrete
	 * 
	 * @return whether the optimization variable type is set successfully or not. 
	 */
	public boolean setOptimizationVariableType(String variableType){
		Node nodeRef = null;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eEntityData, "optimization");
		if(eOptimization == null){
			eOptimization = m_document.createElement("optimization");
			nodeRef = XMLUtil.findChildNode(m_eEntityData, "job");			
			if(nodeRef != null){
				m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "service");			
				if(nodeRef != null){
					m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
					if(nodeRef != null){
						m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
						if(nodeRef != null){
							m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							m_eEntityData.insertBefore(eOptimization, m_eEntityData.getFirstChild());
						}		
					}		
				}			
			}			
		}
		if(variableType == null || variableType.length() <= 0){
			XMLUtil.removeChildrenByName(eOptimization, "variableType");
			return true;
		}
		if(!variableType.equals("continuous") && 
				   !variableType.equals("pureBinary") &&
				   !variableType.equals("mixedBinary") &&
				   !variableType.equals("pureInteger") &&
				   !variableType.equals("mixedInteger") &&
				   !variableType.equals("discrete")) return false;
		Element eVariableType = (Element)XMLUtil.findChildNode(eOptimization, "variableType");
		if(eVariableType != null){
			XMLUtil.removeChildrenByName(eOptimization, "variableType");
		}
		eVariableType = m_document.createElement("variableType");
		eVariableType.appendChild(m_document.createTextNode(variableType));
		eOptimization.appendChild(eVariableType);
		return true;
	}//setOptimizationVariableType
	
	/**
	 * Set the optimization objective type. 
	 * 
	 * @param objectiveType holds the optimization objective type, which can be:
	 * none, singleObjective, multiObjectives
	 * 
	 * @return whether the optimization objective type is set successfully or not. 
	 */
	public boolean setOptimizationObjectiveType(String objectiveType){
		Node nodeRef = null;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eEntityData, "optimization");
		if(eOptimization == null){
			eOptimization = m_document.createElement("optimization");
			nodeRef = XMLUtil.findChildNode(m_eEntityData, "job");			
			if(nodeRef != null){
				m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "service");			
				if(nodeRef != null){
					m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
					if(nodeRef != null){
						m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
						if(nodeRef != null){
							m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							m_eEntityData.insertBefore(eOptimization, m_eEntityData.getFirstChild());
						}		
					}		
				}			
			}			
		}
		if(objectiveType == null || objectiveType.length() <= 0){
			XMLUtil.removeChildrenByName(eOptimization, "objectiveType");
			return true;
		}
		if(!objectiveType.equals("none") && 
				   !objectiveType.equals("singleObjective") &&
				   !objectiveType.equals("multiObjectives")) return false;
		Element eObjectiveType = (Element)XMLUtil.findChildNode(eOptimization, "objectiveType");
		if(eObjectiveType != null){
			XMLUtil.removeChildrenByName(eOptimization, "objectiveType");
		}
		eObjectiveType = m_document.createElement("objectiveType");
		eObjectiveType.appendChild(m_document.createTextNode(objectiveType));
		eOptimization.appendChild(eObjectiveType);
		return true;
	}//setOptimizationObjectiveType
	
	/**
	 * Set the optimization constraint type. 
	 * 
	 * @param constraintType holds the optimization constraint type, which can be:
	 * generalRange, pureEquality, pureBound, 
	 * pureLinearComplementarity, pureNonlinearComplementarity, 
	 * linearMixedComplementarity, nonlinearMixedComplementarity, generalMixedComplementarity,
	 * pureCone, mixedCone. 
	 * 
	 * @return whether the optimization constraint type is set successfully or not. 
	 */
	public boolean setOptimizationConstraintType(String constraintType){
		Node nodeRef = null;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eEntityData, "optimization");
		if(eOptimization == null){
			eOptimization = m_document.createElement("optimization");
			nodeRef = XMLUtil.findChildNode(m_eEntityData, "job");			
			if(nodeRef != null){
				m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "service");			
				if(nodeRef != null){
					m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
					if(nodeRef != null){
						m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
						if(nodeRef != null){
							m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							m_eEntityData.insertBefore(eOptimization, m_eEntityData.getFirstChild());
						}		
					}		
				}			
			}			
		}
		if(constraintType == null || constraintType.length() <= 0){
			XMLUtil.removeChildrenByName(eOptimization, "constraintType");
			return true;
		}
		if(!constraintType.equals("generalRange") && 
				   !constraintType.equals("pureEquality") &&
				   !constraintType.equals("pureBound") &&
				   !constraintType.equals("pureLinearComplementarity") &&
				   !constraintType.equals("pureNonlinearComplementarity") &&
				   !constraintType.equals("linearMixedComplementarity") &&
				   !constraintType.equals("nonlinearMixedComplementarity") &&
				   !constraintType.equals("generalMixedComplementarity") &&
				   !constraintType.equals("pureCone") &&
				   !constraintType.equals("mixedCone")) return false;
		Element eConstraintType = (Element)XMLUtil.findChildNode(eOptimization, "constraintType");
		if(eConstraintType != null){
			XMLUtil.removeChildrenByName(eOptimization, "constraintType");
		}
		eConstraintType = m_document.createElement("constraintType");
		eConstraintType.appendChild(m_document.createTextNode(constraintType));
		eOptimization.appendChild(eConstraintType);
		return true;
	}//setOptimizationConstraintType
	
	/**
	 * Set the optimization objective linearity. 
	 * 
	 * @param objectiveLinearity holds the optimization objective linearity, which can be:
	 * none, linearNetwork, linear sumOfSquares, convexQuadratic, convexNonlinear, generalQuadratic, generalNonlinear
	 * 
	 * @return whether the optimization objective linearity is set successfully or not. 
	 */
	public boolean setOptimizationObjectiveLinearity(String objectiveLinearity){
		Node nodeRef = null;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eEntityData, "optimization");
		if(eOptimization == null){
			eOptimization = m_document.createElement("optimization");
			nodeRef = XMLUtil.findChildNode(m_eEntityData, "job");			
			if(nodeRef != null){
				m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "service");			
				if(nodeRef != null){
					m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
					if(nodeRef != null){
						m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
						if(nodeRef != null){
							m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							m_eEntityData.insertBefore(eOptimization, m_eEntityData.getFirstChild());
						}		
					}		
				}			
			}			
		}
		if(objectiveLinearity == null || objectiveLinearity.length() <= 0){
			XMLUtil.removeChildrenByName(eOptimization, "objectiveLinearity");
			return true;
		}
		if(!objectiveLinearity.equals("none") && 
				   !objectiveLinearity.equals("linearNetwork") &&
				   !objectiveLinearity.equals("linear") &&
				   !objectiveLinearity.equals("sumOfSquares") &&
				   !objectiveLinearity.equals("convexQuadratic") &&
				   !objectiveLinearity.equals("convexNonlinear") &&
				   !objectiveLinearity.equals("generalQuadratic") &&
				   !objectiveLinearity.equals("generalNonlinear")) return false;
		Element eObjectiveLinearity = (Element)XMLUtil.findChildNode(eOptimization, "objectiveLinearity");
		if(eObjectiveLinearity != null){
			XMLUtil.removeChildrenByName(eOptimization, "objectiveLinearity");
		}
		eObjectiveLinearity = m_document.createElement("objectiveLinearity");
		eObjectiveLinearity.appendChild(m_document.createTextNode(objectiveLinearity));
		eOptimization.appendChild(eObjectiveLinearity);
		return true;
	}//setOptimizationObjectiveLinearity

	
	/**
	 * Set the optimization constraint linearity. 
	 * 
	 * @param constraintLinearity holds the optimization constraint linearity, which can be:
	 * none, bound, linearNetwork, linear, convexQuadratic, convexNonlinear, generalQuadratic, generalNonlinear
	 * 
	 * @return whether the optimization constraint linearity is set successfully or not. 
	 */
	public boolean setOptimizationConstraintLinearity(String constraintLinearity){
		Node nodeRef = null;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eEntityData, "optimization");
		if(eOptimization == null){
			eOptimization = m_document.createElement("optimization");
			nodeRef = XMLUtil.findChildNode(m_eEntityData, "job");			
			if(nodeRef != null){
				m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "service");			
				if(nodeRef != null){
					m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
					if(nodeRef != null){
						m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
						if(nodeRef != null){
							m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							m_eEntityData.insertBefore(eOptimization, m_eEntityData.getFirstChild());
						}		
					}		
				}			
			}			
		}
		if(constraintLinearity == null || constraintLinearity.length() <= 0){
			XMLUtil.removeChildrenByName(eOptimization, "constraintLinearity");
			return true;
		}
		if(!constraintLinearity.equals("none") && 
				   !constraintLinearity.equals("bound") &&
				   !constraintLinearity.equals("linearNetwork") &&
				   !constraintLinearity.equals("linear") &&
				   !constraintLinearity.equals("convexQuadratic") &&
				   !constraintLinearity.equals("convexNonlinear") &&
				   !constraintLinearity.equals("generalQuadratic") &&
				   !constraintLinearity.equals("generalNonlinear")) return false;
		Element eConstraintLinearity = (Element)XMLUtil.findChildNode(eOptimization, "constraintLinearity");
		if(eConstraintLinearity != null){
			XMLUtil.removeChildrenByName(eOptimization, "constraintLinearity");
		}
		eConstraintLinearity = m_document.createElement("constraintLinearity");
		eConstraintLinearity.appendChild(m_document.createTextNode(constraintLinearity));
		eOptimization.appendChild(eConstraintLinearity);
		return true;
	}//setOptimizationConstraintLinearity
	
	/**
	 * Set the optimization objective differentiability. 
	 * 
	 * @param objectiveDifferentiability holds the optimization objective differentiability, which can be:
	 * generallyDifferentiable, twiceDifferentiable, firstDifferentiable, 
	 * nonDifferentiableContinous, nonContinuous, simulation. 
	 * 
	 * @return whether the optimization objective differentiability is set successfully or not. 
	 */
	public boolean setOptimizationObjectiveDifferentiability(String objectiveDifferentiability){
		Node nodeRef = null;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eEntityData, "optimization");
		if(eOptimization == null){
			eOptimization = m_document.createElement("optimization");
			nodeRef = XMLUtil.findChildNode(m_eEntityData, "job");			
			if(nodeRef != null){
				m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "service");			
				if(nodeRef != null){
					m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
					if(nodeRef != null){
						m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
						if(nodeRef != null){
							m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							m_eEntityData.insertBefore(eOptimization, m_eEntityData.getFirstChild());
						}		
					}		
				}			
			}			
		}
		if(objectiveDifferentiability == null || objectiveDifferentiability.length() <= 0){
			XMLUtil.removeChildrenByName(eOptimization, "objectiveDifferentiability");
			return true;
		}
		if(!objectiveDifferentiability.equals("generallyDifferentiable") && 
				   !objectiveDifferentiability.equals("twiceDifferentiable") &&
				   !objectiveDifferentiability.equals("firstDifferentiable") &&
				   !objectiveDifferentiability.equals("nonDifferentiableContinous") &&
				   !objectiveDifferentiability.equals("nonContinuous") &&
				   !objectiveDifferentiability.equals("simulation")) return false;
		Element eObjectiveDifferentiability = (Element)XMLUtil.findChildNode(eOptimization, "objectiveDifferentiability");
		if(eObjectiveDifferentiability != null){
			XMLUtil.removeChildrenByName(eOptimization, "objectiveDifferentiability");
		}
		eObjectiveDifferentiability = m_document.createElement("objectiveDifferentiability");
		eObjectiveDifferentiability.appendChild(m_document.createTextNode(objectiveDifferentiability));
		eOptimization.appendChild(eObjectiveDifferentiability);
		return true;
	}//setOptimizationObjectiveDifferentiability

	
	/**
	 * Set the optimization constraint differentiability. 
	 * 
	 * @param constraintDifferentiability holds the optimization constraint differentiability, which can be:
	 * generallyDifferentiable, twiceDifferentiable, firstDifferentiable, 
	 * nonDifferentiableContinous, nonContinuous, simulation. 
	 * 
	 * @return whether the optimization constraint differentiability is set successfully or not. 
	 */
	public boolean setOptimizationConstraintDifferentiability(String constraintDifferentiability){
		Node nodeRef = null;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eEntityData, "optimization");
		if(eOptimization == null){
			eOptimization = m_document.createElement("optimization");
			nodeRef = XMLUtil.findChildNode(m_eEntityData, "job");			
			if(nodeRef != null){
				m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "service");			
				if(nodeRef != null){
					m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
					if(nodeRef != null){
						m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
						if(nodeRef != null){
							m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							m_eEntityData.insertBefore(eOptimization, m_eEntityData.getFirstChild());
						}		
					}		
				}			
			}			
		}
		if(constraintDifferentiability == null || constraintDifferentiability.length() <= 0){
			XMLUtil.removeChildrenByName(eOptimization, "constraintDifferentiability");
			return true;
		}
		if(!constraintDifferentiability.equals("generallyDifferentiable") && 
				   !constraintDifferentiability.equals("twiceDifferentiable") &&
				   !constraintDifferentiability.equals("firstDifferentiable") &&
				   !constraintDifferentiability.equals("nonDifferentiableContinous") &&
				   !constraintDifferentiability.equals("nonContinuous") &&
				   !constraintDifferentiability.equals("simulation")) return false;
		Element eConstraintDifferentiability = (Element)XMLUtil.findChildNode(eOptimization, "constraintDifferentiability");
		if(eConstraintDifferentiability != null){
			XMLUtil.removeChildrenByName(eOptimization, "constraintDifferentiability");
		}
		eConstraintDifferentiability = m_document.createElement("constraintDifferentiability");
		eConstraintDifferentiability.appendChild(m_document.createTextNode(constraintDifferentiability));
		eOptimization.appendChild(eConstraintDifferentiability);
		return true;
	}//setOptimizationConstraintDifferentiability

	
	/**
	 * Set the optimization parameter type. 
	 * 
	 * @param parameterType holds the optimization parameter type, which can be:
	 * number, string, both
	 * 
	 * @return whether the optimization parameter type is set successfully or not. 
	 */
	public boolean setOptimizationParameterType(String parameterType){
		Node nodeRef = null;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eEntityData, "optimization");
		if(eOptimization == null){
			eOptimization = m_document.createElement("optimization");
			nodeRef = XMLUtil.findChildNode(m_eEntityData, "job");			
			if(nodeRef != null){
				m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "service");			
				if(nodeRef != null){
					m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
					if(nodeRef != null){
						m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
						if(nodeRef != null){
							m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							m_eEntityData.insertBefore(eOptimization, m_eEntityData.getFirstChild());
						}		
					}		
				}			
			}			
		}
		if(parameterType == null || parameterType.length() <= 0){
			XMLUtil.removeChildrenByName(eOptimization, "parameterType");
			return true;
		}
		if(!parameterType.equals("number") && 
				   !parameterType.equals("string") &&
				   !parameterType.equals("both")) return false;
		Element eParameterType = (Element)XMLUtil.findChildNode(eOptimization, "parameterType");
		if(eParameterType != null){
			XMLUtil.removeChildrenByName(eOptimization, "parameterType");
		}
		eParameterType = m_document.createElement("parameterType");
		eParameterType.appendChild(m_document.createTextNode(parameterType));
		eOptimization.appendChild(eParameterType);
		return true;
	}//setOptimizationParameterType

	
	/**
	 * Set the optimization stochasticity. 
	 * 
	 * @param tochasticity holds the optimization stochasticity, which can be:
	 * deterministic, stochastic, both
	 * 
	 * @return whether the optimization stochasticity is set successfully or not. 
	 */
	public boolean setOptimizationStochasticity(String stochasticity){
		Node nodeRef = null;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eEntityData, "optimization");
		if(eOptimization == null){
			eOptimization = m_document.createElement("optimization");
			nodeRef = XMLUtil.findChildNode(m_eEntityData, "job");			
			if(nodeRef != null){
				m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "service");			
				if(nodeRef != null){
					m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
					if(nodeRef != null){
						m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
						if(nodeRef != null){
							m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							m_eEntityData.insertBefore(eOptimization, m_eEntityData.getFirstChild());
						}		
					}		
				}			
			}			
		}
		if(stochasticity == null || stochasticity.length() <= 0){
			XMLUtil.removeChildrenByName(eOptimization, "stochasticity");
			return true;
		}
		if(!stochasticity.equals("deterministic") && 
				   !stochasticity.equals("stochastic") &&
				   !stochasticity.equals("both")) return false;
		Element eStochasticity = (Element)XMLUtil.findChildNode(eOptimization, "stochasticity");
		if(eStochasticity != null){
			XMLUtil.removeChildrenByName(eOptimization, "stochasticity");
		}
		eStochasticity = m_document.createElement("stochasticity");
		eStochasticity.appendChild(m_document.createTextNode(stochasticity));
		eOptimization.appendChild(eStochasticity);
		return true;
	}//setOptimizationStochasticity

	
	/**
	 * Set whether the service supports real time optimization or not.  
	 * 
	 * @param realTime holds whether the service supports real time optimization or not.  
	 * 
	 * @return whether the service supports real time optimization or not.  
	 */
	public boolean setOptimizationRealTime(boolean realTime){
		Node nodeRef = null;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eEntityData, "optimization");
		if(eOptimization == null){
			eOptimization = m_document.createElement("optimization");
			nodeRef = XMLUtil.findChildNode(m_eEntityData, "job");			
			if(nodeRef != null){
				m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "service");			
				if(nodeRef != null){
					m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
					if(nodeRef != null){
						m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
						if(nodeRef != null){
							m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							m_eEntityData.insertBefore(eOptimization, m_eEntityData.getFirstChild());
						}		
					}		
				}			
			}			
		}
		if(realTime == false){
			XMLUtil.removeChildrenByName(eOptimization, "realTime");
			return true;
		}
		Element eRealTime = (Element)XMLUtil.findChildNode(eOptimization, "realTime");
		if(eRealTime != null){
			XMLUtil.removeChildrenByName(eOptimization, "realTime");
		}
		eRealTime = m_document.createElement("realTime");
		eRealTime.appendChild(m_document.createTextNode(realTime+""));
		eOptimization.appendChild(eRealTime);
		return true;
	}//setOptimizationRealTime

	
	/**
	 * Set the function types that the service supports.   
	 * 
	 * @param functionType holds the function types that the service supports.     
	 * 
	 * @return the function types that the service supports.   
	 */
	public boolean setOptimizationFunctionType(FunctionType functionType){
		Node nodeRef = null;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eEntityData, "optimization");
		if(eOptimization == null){
			eOptimization = m_document.createElement("optimization");
			nodeRef = XMLUtil.findChildNode(m_eEntityData, "job");			
			if(nodeRef != null){
				m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "service");			
				if(nodeRef != null){
					m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
					if(nodeRef != null){
						m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
						if(nodeRef != null){
							m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							m_eEntityData.insertBefore(eOptimization, m_eEntityData.getFirstChild());
						}		
					}		
				}			
			}			
		}
		if(functionType == null){
			XMLUtil.removeChildrenByName(eOptimization, "functionType");
			return true;
		}
		Element eFunctionType = (Element)XMLUtil.findChildNode(eOptimization, "functionType");
		if(eFunctionType != null){
			XMLUtil.removeChildrenByName(eOptimization, "functionType");
		}
		eFunctionType = m_document.createElement("functionType");
		Element eGeneral = m_document.createElement("general");
		eGeneral.appendChild(m_document.createTextNode(functionType.general + ""));
		eFunctionType.appendChild(eGeneral);
		Element eBasic = m_document.createElement("basic");
		eBasic.appendChild(m_document.createTextNode(functionType.basic + ""));
		eFunctionType.appendChild(eBasic);
		Element eArithmetic = m_document.createElement("arithmetic");
		eArithmetic.appendChild(m_document.createTextNode(functionType.arithmetic + ""));
		eFunctionType.appendChild(eArithmetic);
		Element eTrigonometric = m_document.createElement("trigonometric");
		eTrigonometric.appendChild(m_document.createTextNode(functionType.trigonometric + ""));
		eFunctionType.appendChild(eTrigonometric);
		Element eStatistics = m_document.createElement("statistics");
		eStatistics.appendChild(m_document.createTextNode(functionType.statistics + ""));
		eFunctionType.appendChild(eStatistics);
		Element eProbability = m_document.createElement("probability");
		eProbability.appendChild(m_document.createTextNode(functionType.probability + ""));
		eFunctionType.appendChild(eProbability);
		Element eRelationalAndLogic = m_document.createElement("relationalAndLogic");
		eRelationalAndLogic.appendChild(m_document.createTextNode(functionType.relationalAndLogic + ""));
		eFunctionType.appendChild(eRelationalAndLogic);
		Element eUserFunction = m_document.createElement("userFunction");
		eUserFunction.appendChild(m_document.createTextNode(functionType.userFunction + ""));
		eFunctionType.appendChild(eUserFunction);
		Element eSimulation = m_document.createElement("simulation");
		eSimulation.appendChild(m_document.createTextNode(functionType.simulation + ""));
		eFunctionType.appendChild(eSimulation);
		
		eOptimization.appendChild(eFunctionType);
		return true;
	}//setOptimizationFunctionType

	
	/**
	 * Set the special structures that the service supports.   
	 * 
	 * @param specialStructure holds the special structures that the service supports.     
	 * 
	 * @return the special structures that the service supports.   
	 */
	public boolean setOptimizationSpecialStructure(SpecialStructure specialStructure){
		Node nodeRef = null;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eEntityData, "optimization");
		if(eOptimization == null){
			eOptimization = m_document.createElement("optimization");
			nodeRef = XMLUtil.findChildNode(m_eEntityData, "job");			
			if(nodeRef != null){
				m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "service");			
				if(nodeRef != null){
					m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
					if(nodeRef != null){
						m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
						if(nodeRef != null){
							m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							m_eEntityData.insertBefore(eOptimization, m_eEntityData.getFirstChild());
						}		
					}		
				}			
			}			
		}
		if(specialStructure == null){
			XMLUtil.removeChildrenByName(eOptimization, "specialStructure");
			return true;
		}
		Element eSpecialStructure = (Element)XMLUtil.findChildNode(eOptimization, "specialStructure");
		if(eSpecialStructure != null){
			XMLUtil.removeChildrenByName(eOptimization, "specialStructure");
		}
		eSpecialStructure = m_document.createElement("specialStructure");
		Element eSemidefiniteProgram = m_document.createElement("semidefiniteProgram");
		eSemidefiniteProgram.appendChild(m_document.createTextNode(specialStructure.semidefiniteProgram + ""));
		eSpecialStructure.appendChild(eSemidefiniteProgram);
		Element eConeProgram = m_document.createElement("coneProgram");
		eConeProgram.appendChild(m_document.createTextNode(specialStructure.coneProgram + ""));
		eSpecialStructure.appendChild(eConeProgram);
		Element eDisjunctiveProgram = m_document.createElement("disjunctiveProgram");
		eDisjunctiveProgram.appendChild(m_document.createTextNode(specialStructure.disjunctiveProgram + ""));
		eSpecialStructure.appendChild(eDisjunctiveProgram);

		eOptimization.appendChild(eSpecialStructure);
		return true;
	}//setOptimizationSpecialStructure

	
	/**
	 * Set the special algorithms that the service supports.   
	 * 
	 * @param specialAlgorithm holds the special algorithms that the service supports.     
	 * 
	 * @return the special algorithms that the service supports.   
	 */
	public boolean setOptimizationSpecialAlgorithm(SpecialAlgorithm specialAlgorithm){
		Node nodeRef = null;
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eEntityData, "optimization");
		if(eOptimization == null){
			eOptimization = m_document.createElement("optimization");
			nodeRef = XMLUtil.findChildNode(m_eEntityData, "job");			
			if(nodeRef != null){
				m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "service");			
				if(nodeRef != null){
					m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
					if(nodeRef != null){
						m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
						if(nodeRef != null){
							m_eEntityData.insertBefore(eOptimization, nodeRef.getNextSibling());			
						}
						else{
							m_eEntityData.insertBefore(eOptimization, m_eEntityData.getFirstChild());
						}		
					}		
				}			
			}			
		}
		if(specialAlgorithm == null){
			XMLUtil.removeChildrenByName(eOptimization, "specialAlgorithm");
			return true;
		}
		Element eSpecialAlgorithm = (Element)XMLUtil.findChildNode(eOptimization, "specialAlgorithm");
		if(eSpecialAlgorithm != null){
			XMLUtil.removeChildrenByName(eOptimization, "specialAlgorithm");
		}
		eSpecialAlgorithm = m_document.createElement("specialAlgorithm");
		Element eDecomposition = m_document.createElement("decomposition");
		eDecomposition.appendChild(m_document.createTextNode(specialAlgorithm.decomposition + ""));
		eSpecialAlgorithm.appendChild(eDecomposition);
		Element eGlobalOptimization = m_document.createElement("globalOptimization");
		eGlobalOptimization.appendChild(m_document.createTextNode(specialAlgorithm.globalOptimization + ""));
		eSpecialAlgorithm.appendChild(eGlobalOptimization);
		Element eDynamicProgramming = m_document.createElement("dynamicProgramming");
		eDynamicProgramming.appendChild(m_document.createTextNode(specialAlgorithm.dynamicProgramming + ""));
		eSpecialAlgorithm.appendChild(eDynamicProgramming);
		Element eHeuristic = m_document.createElement("heuristic");
		eHeuristic.appendChild(m_document.createTextNode(specialAlgorithm.heuristic + ""));
		eSpecialAlgorithm.appendChild(eHeuristic);
		eOptimization.appendChild(eSpecialAlgorithm);
		return true;
	}//setOptimizationSpecialAlgorithm
	
	/**
	 * Set the other entity info related elements. 
	 * 
	 * @param names holds the names of the other entity info. It is required.
	 * @param values holds the values of the other entity info, empty String "" if no value for an entity info.
	 * @param descriptions holds the descriptions of other entity info, empty String "" if no value for an entity description, null for
	 * the entire array if none of the other entity info have descriptions.
	 * @return whether the other entity info element construction is successful.
	 */
	public boolean setOtherEntityInfo(String[] names, String[] values, String[] descriptions){
		if(names == null) return false;
		if(values == null) return false;
		if(names.length != values.length) return false;
		if(descriptions != null && names.length != descriptions.length) return false;
		for(int i = 0; i < names.length; i++){
			addOtherEntityInfo(names[i], values[i], (descriptions==null)?"":descriptions[i]);
		}
		return true;
	}//setOtherEntityInfo

	/**
	 * Add an other entity info element. 
	 * 
	 * @param name holds the name of the other entity info element. It is required. 
	 * @param value holds the value of the other entity info element, empty String "" if none. 
	 * @param description holds the description of the other entity info element, empty String "" if none. 
	 * @return whether the other entity info element is added successfully.
	 */
	public boolean addOtherEntityInfo(String name, String value, String description){
		if(name == null) return false;
		Vector<Element> vElements = XMLUtil.getChildElementsByTagName(m_eEntityData, "other");
		Element eOther;
		int iNls = vElements==null?0:vElements.size();
		for(int i = 0; i < iNls; i++){
			eOther = (Element)vElements.elementAt(i);
			if(eOther.getAttribute("name").equals(name)){
				m_eEntityData.removeChild(eOther);
				break;
			}
		}
		eOther = createOther(name, value, description);
		m_eEntityData.appendChild(eOther);
		return true;
	}//addOtherEntityInfo

	
	/**
	 * Create the OSeL root element and its most basic required structure.
	 * 
	 * @return the OSeL element.
	 */
	protected Element createOSeLRoot(){
		Element eOSeL = XMLUtil.createOSxLRootElement(m_document, "osel");
		m_eEntityHeader = createEntityHeader();
		eOSeL.appendChild(m_eEntityHeader);
		m_eEntityData = createEntityData();
		eOSeL.appendChild(m_eEntityData);
		return eOSeL;
	}//createOSeLRoot


	/**
	 * Create the entityHeader element and its most basic required structure.
	 * 
	 * @return the entityHeader element.
	 */
	protected Element createEntityHeader(){
		Element eEntityHeader = m_document.createElement("entityHeader");
		return eEntityHeader;
	}//createEntityHeader
	
	/**
	 * Create the entityData element and its most basic required structure.
	 * 
	 * @return the entityData element.
	 */
	protected Element createEntityData(){
		Element eEntityData = m_document.createElement("entityData");
		return eEntityData;
	}//createEntityData
	
	/**
	 * Create the other element and its most basic required structure.
	 * 
	 * @param name the name of the other element.
	 * @param value the value of the other element, empty String "" if no value. 
	 * @param description holds the description of the other entity info element, empty String "" if none. 
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
		OSeLWriter oselWriter = new OSeLWriter();
		String sFileName = OSParameter.CODE_HOME + "OSRepository/test/osel/osel.osel";
/*
		if(!oselWriter.setMessage("my message")) System.out.println("message!");
		if(!oselWriter.setMessage("")) System.out.println("message!");
		if(!oselWriter.setServiceName("my service name")) System.out.println("service name");
		if(!oselWriter.setServiceURI("my service uri")) System.out.println("uri");
		if(!oselWriter.setRegistrationDate(new GregorianCalendar())) System.out.println("time!");
		
		if(!oselWriter.setLicenseRequired(false))System.out.println("setLicenseRequired Unsuccessful");
		if(!oselWriter.setUserNameRequired(true)) System.out.println("setUserNameRequired Unsuccessful");
		if(!oselWriter.setPasswordRequired(true)) System.out.println("setPasswordRequired Unsuccessful");
		AccessLimits accessLimits = new AccessLimits();
		accessLimits.maxBinaryVariables = 8888;
		accessLimits.maxConstraints = 7777;
		accessLimits.maxBinaryVariables = 5555;
		if(!oselWriter.setAccessLimits(accessLimits)) System.out.println("setAccessLimits Unsuccessful");
		Owner owner = new Owner();
		owner.names = "Jun Ma";
		owner.description = "cool person";
		if(!oselWriter.setOwner(owner)) System.out.println("setOwner Unsuccessful");
		String[] keyWords = new String[2];
		keyWords[0] = "key0";
		keyWords[1] = "key1";
		if(!oselWriter.setKeyWords(keyWords))System.out.println("setKeyWords Unsuccessful");
		Link[] links = new Link[2];
		links[0] = new Link();
		links[0].description = "";
		links[0].type = "service";
		links[0].value = "http://yahoo.com";
		links[1] = new Link();
		links[1].description = "description 1";
		links[1].type = "service";
		links[1].value = "http://google.com";
		if(!oselWriter.setLinks(links)) System.out.println("setLinks Unsuccessful");
		if(!oselWriter.setSystemDescription("systemDescription"))System.out.println("setSystemDescription Unsuccessful");
		if(!oselWriter.setSystemDedication(0.3)) System.out.println("setSystemDedication Unsuccessful");
		HardwareInfo systemHardwareInfo = new HardwareInfo();
		
		if(!oselWriter.setOptimizationDescription("none!!!!!")) System.out.println("setOptimizationDescription Unsuccessful");

		systemHardwareInfo.busSpeed = 1.2;
		systemHardwareInfo.cpuNumber = 2;
		systemHardwareInfo.cpuSpeed = 3.4;
		systemHardwareInfo.diskSpace = 4.5;
		systemHardwareInfo.downloadSpeed = 5;
		systemHardwareInfo.memorySize = 4.5;
		systemHardwareInfo.nicSpeed = 4.6;
		systemHardwareInfo.uploadSpeed = 6.7;
		if(!oselWriter.setSystemHardwareInfo(systemHardwareInfo)) System.out.println("setSystemHardwareInfo Unsuccessful");
		//if(!oselWriter.setSystemHardwareInfo(null)) System.out.println("setSystemHardwareInfo Unsuccessful");
		if(!oselWriter.setServiceDescription("serviceDescription")) System.out.println("setServiceDescription Unsuccessful");
		if(!oselWriter.setServiceType("solver")) System.out.println("setServiceType Unsuccessful");
		if(!oselWriter.setServiceCategory("education")) System.out.println("setServiceCategory Unsuccessful");
		if(!oselWriter.setServiceSoftwareDescription("serviceSoftwareDescription")) System.out.println("setServiceSoftwareDescription Unsuccessful");
		if(!oselWriter.setServiceAlgorithmDescription("serviceAlgorithmDescription")) System.out.println("setServiceAlgorithmDescription Unsuccessful");
		if(!oselWriter.setServiceWebPage("serviceWebPage")) System.out.println("setServiceWebPage Unsuccessful");
		if(!oselWriter.setServiceWSDLLocation("serviceWSDLLocation")) System.out.println("setServiceWSDLLocation Unsuccessful");
		if(!oselWriter.setServiceLogoImageLink("serviceLogoImageLink")) System.out.println("setServiceLogoImageLink Unsuccessful");
		/////////////////option///////////////////
		OSOption defaultOptionNamesAndValues = new OSOption();
		defaultOptionNamesAndValues.setConstraintNumber(3);
		if(!oselWriter.setDefaultOptionNamesAndValues(defaultOptionNamesAndValues)) System.out.println("setDefaultOptionNamesAndValues Unsuccessful");
		/////////////////option///////////////////
		if(!oselWriter.setOptimizationVariableType("continuous")) System.out.println("setOptimizationVariableType Unsuccessful");
		if(!oselWriter.setOptimizationObjectiveType("singleObjective")) System.out.println("setOptimizationObjectiveType Unsuccessful");
		if(!oselWriter.setOptimizationConstraintType("generalRange")) System.out.println("setOptimizationConstraintType Unsuccessful");
		if(!oselWriter.setOptimizationObjectiveLinearity("linear")) System.out.println("setOptimizationObjectiveLinearity Unsuccessful");
		if(!oselWriter.setOptimizationConstraintLinearity("bound")) System.out.println("setOptimizationConstraintLinearity Unsuccessful");
		if(!oselWriter.setOptimizationObjectiveDifferentiability("simulation")) System.out.println("setOptimizationObjectiveDifferentiability Unsuccessful");
		if(!oselWriter.setOptimizationConstraintDifferentiability("nonContinuous")) System.out.println("setOptimizationConstraintDifferentiability Unsuccessful");
		if(!oselWriter.setOptimizationParameterType("number")) System.out.println("setOptimizationParameterType Unsuccessful");
		if(!oselWriter.setOptimizationStochasticity("deterministic")) System.out.println("setOptimizationStochasticity Unsuccessful");
		if(!oselWriter.setOptimizationRealTime(false)) System.out.println("setOptimizationRealTime Unsuccessful");
		FunctionType optimizationFunctionType = new FunctionType();
		optimizationFunctionType.probability = true;
		if(!oselWriter.setOptimizationFunctionType(optimizationFunctionType)) System.out.println("setOptimizationFunctionType Unsuccessful");
		SpecialStructure optimizationSpecialStructure = new SpecialStructure();
		optimizationSpecialStructure.disjunctiveProgram = true;
		if(!oselWriter.setOptimizationSpecialStructure(optimizationSpecialStructure)) System.out.println("setOptimizationSpecialStructure Unsuccessful");
		SpecialAlgorithm optimizationSpecialAlgorithm = new SpecialAlgorithm();
		optimizationSpecialAlgorithm.dynamicProgramming = true;
		if(!oselWriter.setOptimizationSpecialAlgorithm(optimizationSpecialAlgorithm)) System.out.println("setOptimizationSpecialAlgorithm Unsuccessful");
		String[] msOtherEntityNames = {"other name 0", "other name 1"};
		String[] msOtherEntityValues = {"other value 0", "other value 1"};
		if(!oselWriter.setOtherEntityInfo(msOtherEntityNames, msOtherEntityValues, null)) System.out.println("set other!");
	
		if(!oselWriter.addOtherEntityInfo("other name 2", "other value 2", null)) System.out.println("add other!");
		if(!oselWriter.addOtherEntityInfo("other name 3", "other value 3", "other description 3")) System.out.println("add other!");
*/
		////////////////////
		
		OSeLReader oselReader = new OSeLReader(false);
		if(!oselReader.readFile(sFileName)) System.out.println("reading");
		OSEntity osEntity;
		try {
			osEntity = oselReader.getOSEntity();
			if(!oselWriter.setOSEntity(osEntity)) System.out.println("set osEntity");
		} 
		catch (Exception e) {
			e.printStackTrace();
		}
		////////////////////
		
		//oselWriter.writeToStandardOutput();
		System.out.println(oselWriter.writeToString());
		
	}//main
	
}//class OSeLWriter
