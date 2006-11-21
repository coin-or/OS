using System;
using System.Collections;
using System.Xml;
using org.optimizationservices.oscommon.util;
using org.optimizationservices.oscommon.localinterface;
using org.optimizationservices.oscommon.datastructure.osentity;

namespace org.optimizationservices.oscommon.representationparser{
	/// <summary>
	/// The <c>OSeLWriter</c> class is used to construct an instance that follows 
	/// the OSeL format. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OSeLWriter : OSgLWriter{
		/// <summary>
		/// m_eOSeL holds the OSeL root element.
		/// </summary>
		protected internal XmlElement m_eOSeL = null;

		/// <summary>
		/// m_eEntityHeader holds the 1st child element entityHeader of root element OSeL.
		/// </summary>
		protected XmlElement m_eEntityHeader = null;
	
		/// <summary>
		/// m_eEntityData holds the 2nd child element entityData of root element OSeL.
		/// </summary>
		protected XmlElement m_eEntityData = null;
		
		/// <summary>
		/// constructor. 
		/// </summary>
		public OSeLWriter(){
			m_document = XMLUtil.createNewDocument();
			if(OSParameter.XSLT_LOCATION != null && OSParameter.XSLT_LOCATION.Length > 0){
				XmlProcessingInstruction xsltPI = m_document.CreateProcessingInstruction("xml-stylesheet",
					"type=\"text/xsl\" href = \"" + OSParameter.XSLT_LOCATION + "OSeL.xslt\"");
				m_document.AppendChild(xsltPI);     
			}
			m_eOSeL = createOSeLRoot();
			m_document.AppendChild(m_eOSeL);
		}//constructor


		/// <summary>
		/// set the OSEntity, a standard os entity interface.  
		/// </summary>
		/// <param name="osEntity">the standard os entity interface</param>
		/// <returns>whether the OSEntity is set successfully </returns>
		public bool setOSEntity(OSEntity osEntity){
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
			if(osEntity.entityData.other != null && osEntity.entityData.other.Length > 0){
				int n = osEntity.entityData.other.Length;
				string[] msNames = new string[n];
				string[] msValues = new string[n];
				string[] msDescriptions = new string[n];
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
		
		/// <summary>
		/// Set service uri.
		/// </summary>
		/// <param name="serviceURI">holds the uri of the service. </param>
		/// <returns>whether the service uri is set successfully. </returns>
		public bool setServiceURI(string serviceURI){
			try{
				if(serviceURI != null && serviceURI.Length > 0){
					XmlElement eServiceURI = (XmlElement )XMLUtil.findChildNode(m_eEntityHeader, "serviceURI");
					if(eServiceURI == null){
						eServiceURI = m_document.CreateElement("serviceURI");	
						eServiceURI.AppendChild(m_document.CreateTextNode(serviceURI));
						m_eEntityHeader.InsertBefore(eServiceURI, m_eEntityHeader.FirstChild);				}
					else{
						XMLUtil.setElementValue(eServiceURI, serviceURI);
					}
				}
				else{
					XMLUtil.removeChildrenByName(m_eEntityHeader, "serviceURI");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setServiceURI

		/// <summary>
		/// Set service name.
		/// </summary>
		/// <param name="serviceName">holds the name of the service. </param>
		/// <returns>whether the service name is set successfully. </returns>
		public bool setServiceName(string serviceName){
			try{
				XmlNode nodeRef = null;
				if(serviceName != null && serviceName.Length > 0){
					XmlElement eServiceName = (XmlElement)XMLUtil.findChildNode(m_eEntityHeader, "serviceName");
					if(eServiceName == null){
						eServiceName = m_document.CreateElement("serviceName");					
						eServiceName.AppendChild(m_document.CreateTextNode(serviceName));
						nodeRef = XMLUtil.findChildNode(m_eEntityHeader, "registrationDate");
						if(nodeRef == null){
							nodeRef = XMLUtil.findChildNode(m_eEntityHeader, "message");
						}
						m_eEntityHeader.InsertBefore(eServiceName, nodeRef);
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
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setServiceName

		/// <summary>
		/// Set time of the registration date.
		/// </summary>
		/// <param name="date">holds the registration date.</param>
		/// <returns>whether registration date is set successfully. </returns>
		public bool setRegistrationDate(DateTime date){
			try{
				XmlNode nodeRef = null;
				if(date.Year > 1970){
					XmlElement eRegistrationDate = (XmlElement)XMLUtil.findChildNode(m_eEntityHeader, "registrationDate");
					if(eRegistrationDate == null){
						eRegistrationDate = m_document.CreateElement("registrationDate");					
						eRegistrationDate.AppendChild(m_document.CreateTextNode(XMLUtil.createXSDateTime(date)));
						nodeRef = XMLUtil.findChildNode(m_eEntityHeader, "message");
						m_eEntityHeader.InsertBefore(eRegistrationDate, nodeRef);
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
				Console.WriteLine(e.ToString());;
				return false;
			}
			return true;
		}//setRegistrationDate
	
		/// <summary>
		/// Set the message. 
		/// </summary>
		/// <param name="message">holds the message. </param>
		/// <returns>whether the message is set successfully. </returns>
		public bool setMessage(string message){
			try{
				XmlNode nodeRef = null;
				if(message != null && message.Length > 0){
					XmlElement eMessage = (XmlElement)XMLUtil.findChildNode(m_eEntityHeader, "message");
					if(eMessage == null){
						eMessage = m_document.CreateElement("message");					
						eMessage.AppendChild(m_document.CreateTextNode(message));
						m_eEntityHeader.InsertBefore(eMessage, nodeRef);
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
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setMessage

		/// <summary>
		/// Set whether the license is reqired of the service or not. 
		/// </summary>
		/// <param name="licenseRequired">whether the license is reqired of the service or not.</param>
		/// <returns>the licenseRequired is set successfully or not. </returns>
		public bool setLicenseRequired(bool licenseRequired){
			if(!licenseRequired) return true;
			XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(m_eEntityData, "general");
			if(eGeneral == null){
				eGeneral = m_document.CreateElement("general");
				m_eEntityData.InsertBefore(eGeneral, m_eEntityData.FirstChild);
			}
			XmlElement eAccess = (XmlElement)XMLUtil.findChildNode(eGeneral, "access");
			if(eAccess == null){
				eAccess = m_document.CreateElement("access");
				eGeneral.InsertBefore(eAccess, eGeneral.FirstChild);
			}
			XmlElement eType = (XmlElement)XMLUtil.findChildNode(eAccess, "type");
			if(eType == null){
				eType = m_document.CreateElement("type");
				eAccess.InsertBefore(eType, eAccess.FirstChild);
			}
			eType.SetAttribute("licenseRequired", licenseRequired?"true":"false");
			return true;
		}//setLicenseRequired
	
		/// <summary>
		/// Set whether the user name is reqired of the service or not. 
		/// </summary>
		/// <param name="userNameRequired">holds whether the user name is reqired of the service or not.</param>
		/// <returns>whether the userNameRequired is set successfully or not.</returns>
		public bool setUserNameRequired(bool userNameRequired){
			if(!userNameRequired) return true;
			XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(m_eEntityData, "general");
			if(eGeneral == null){
				eGeneral = m_document.CreateElement("general");
				m_eEntityData.InsertBefore(eGeneral, m_eEntityData.FirstChild);
			}
			XmlElement eAccess = (XmlElement)XMLUtil.findChildNode(eGeneral, "access");
			if(eAccess == null){
				eAccess = m_document.CreateElement("access");
				eGeneral.InsertBefore(eAccess, eGeneral.FirstChild);
			}
			XmlElement eType = (XmlElement)XMLUtil.findChildNode(eAccess, "type");
			if(eType == null){
				eType = m_document.CreateElement("type");
				eAccess.InsertBefore(eType, eAccess.FirstChild);
			}
			eType.SetAttribute("userNameRequired", userNameRequired?"true":"false");
			return true;
		}//setUserNameRequired

		/// <summary>
		/// Set whether the password is reqired of the service or not. 
		/// </summary>
		/// <param name="passwordRequired">holds whether the password is reqired of the service or not.</param>
		/// <returns>whether the passwordRequired is set successfully or not. </returns>
		public bool setPasswordRequired(bool passwordRequired){
			if(!passwordRequired) return true;
			XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(m_eEntityData, "general");
			if(eGeneral == null){
				eGeneral = m_document.CreateElement("general");
				m_eEntityData.InsertBefore(eGeneral, m_eEntityData.FirstChild);
			}
			XmlElement eAccess = (XmlElement)XMLUtil.findChildNode(eGeneral, "access");
			if(eAccess == null){
				eAccess = m_document.CreateElement("access");
				eGeneral.InsertBefore(eAccess, eGeneral.FirstChild);
			}
			XmlElement eType = (XmlElement)XMLUtil.findChildNode(eAccess, "type");
			if(eType == null){
				eType = m_document.CreateElement("type");
				eAccess.InsertBefore(eType, eAccess.FirstChild);
			}
			eType.SetAttribute("passwordRequired", passwordRequired?"true":"false");
			return true;
		}//setPasswordRequired

		/// <summary>
		/// Set the access limit information of the service entity. 
		/// </summary>
		/// <param name="accessLimits">holds the service access limit information.</param>
		/// <returns>whether the access limit information is set successfully or not. </returns>
		public bool setAccessLimits(AccessLimits accessLimits){
			XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(m_eEntityData, "general");
			if(eGeneral == null){
				if(accessLimits == null) return true;
				eGeneral = m_document.CreateElement("general");
				m_eEntityData.InsertBefore(eGeneral, m_eEntityData.FirstChild);
			}
			XmlElement eAccess = (XmlElement)XMLUtil.findChildNode(eGeneral, "access");
			if(eAccess == null){
				if(accessLimits == null) return true;
				eAccess = m_document.CreateElement("access");
				eGeneral.InsertBefore(eAccess, eGeneral.FirstChild);
			}
			if(accessLimits == null){
				XMLUtil.removeChildrenByName(eAccess, "limits");
				return true;
			}
			XmlElement eLimits = (XmlElement)XMLUtil.findChildNode(eAccess, "limits");
			if(eLimits != null){
				XMLUtil.removeChildrenByName(eAccess, "limits");
			}
			eLimits = m_document.CreateElement("limits");
			if(!Double.IsInfinity(accessLimits.maxDiskSpace)){
				XmlElement eMaxDiskSpace = m_document.CreateElement("maxDiskSpace");
				eMaxDiskSpace.AppendChild(m_document.CreateTextNode(Double.IsInfinity(accessLimits.maxDiskSpace)?"INF":accessLimits.maxDiskSpace+""));	
				eLimits.AppendChild(eMaxDiskSpace);
			}
			if(!Double.IsInfinity(accessLimits.maxMemory)){
				XmlElement eMaxMemory = m_document.CreateElement("maxMemory");
				eMaxMemory.AppendChild(m_document.CreateTextNode(Double.IsInfinity(accessLimits.maxMemory)?"INF":accessLimits.maxMemory+""));	
				eLimits.AppendChild(eMaxMemory);
			}
			if(accessLimits.maxJobs >= 0){
				XmlElement eMaxJobs = m_document.CreateElement("maxJobs");
				eMaxJobs.AppendChild(m_document.CreateTextNode(accessLimits.maxJobs + ""));	
				eLimits.AppendChild(eMaxJobs);
			}
			if(accessLimits.maxVariables >= 0){
				XmlElement eMaxVariables = m_document.CreateElement("maxVariables");
				eMaxVariables.AppendChild(m_document.CreateTextNode(accessLimits.maxVariables + ""));	
				eLimits.AppendChild(eMaxVariables);
			}
			if(accessLimits.maxBinaryVariables >= 0){
				XmlElement eMaxBinaryVariables = m_document.CreateElement("maxBinaryVariables");
				eMaxBinaryVariables.AppendChild(m_document.CreateTextNode(accessLimits.maxBinaryVariables + ""));	
				eLimits.AppendChild(eMaxBinaryVariables);
			}
			if(accessLimits.maxIntegerVariables >= 0){
				XmlElement eMaxIntegerVariables = m_document.CreateElement("maxIntegerVariables");
				eMaxIntegerVariables.AppendChild(m_document.CreateTextNode(accessLimits.maxIntegerVariables + ""));	
				eLimits.AppendChild(eMaxIntegerVariables);
			}
			if(accessLimits.maxObjectives >= 0){
				XmlElement eMaxObjectives = m_document.CreateElement("maxObjectives");
				eMaxObjectives.AppendChild(m_document.CreateTextNode(accessLimits.maxObjectives + ""));	
				eLimits.AppendChild(eMaxObjectives);
			}
			if(accessLimits.maxConstraints >= 0){
				XmlElement eMaxConstraints = m_document.CreateElement("maxConstraints");
				eMaxConstraints.AppendChild(m_document.CreateTextNode(accessLimits.maxConstraints + ""));	
				eLimits.AppendChild(eMaxConstraints);
			}
			if(accessLimits.maxNonzeroLinearConstraintCoefficients >= 0){
				XmlElement eMaxNonzeroLinearConstraintCoefficients = m_document.CreateElement("maxNonzeroLinearConstraintCoefficients");
				eMaxNonzeroLinearConstraintCoefficients.AppendChild(m_document.CreateTextNode(accessLimits.maxNonzeroLinearConstraintCoefficients + ""));	
				eLimits.AppendChild(eMaxNonzeroLinearConstraintCoefficients);
			}
			eAccess.AppendChild(eLimits);
			return true;
		}//setAccessLimits

		/// <summary>
		/// Set the owner information of the service entity. 
		/// </summary>
		/// <param name="owner">holds the service owner.</param>
		/// <returns>whether the owner information is set successfully or not. </returns>
		public bool setOwner(Owner owner){
			XmlNode nodeRef = null;
			XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(m_eEntityData, "general");
			if(eGeneral == null && owner == null){
				return true;
			}
			if(eGeneral != null && owner == null){
				XMLUtil.removeChildrenByName(eGeneral, "owner");
				return true;
			}
			if(eGeneral == null){
				eGeneral = m_document.CreateElement("general");
				m_eEntityData.InsertBefore(eGeneral, m_eEntityData.FirstChild);
			}
			XmlElement eOwner = (XmlElement)XMLUtil.findChildNode(eGeneral, "owner");
			if(eOwner != null){
				XMLUtil.removeChildrenByName(eGeneral, "owner");
			}
			eOwner = m_document.CreateElement("owner");
			nodeRef = XMLUtil.findChildNode(eGeneral, "access");
			if(nodeRef != null){
				eGeneral.InsertBefore(eOwner, nodeRef.NextSibling);			
			}
			else{
				eGeneral.InsertBefore(eOwner, eGeneral.FirstChild);
			}			
			if(owner.names != null && owner.names.Length > 0){
				XmlElement eNames = m_document.CreateElement("names");
				eNames.AppendChild(m_document.CreateTextNode(owner.names));	
				eOwner.AppendChild(eNames);
			}
			if(owner.description != null && owner.description.Length > 0){
				XmlElement eDescription = m_document.CreateElement("description");
				eDescription.AppendChild(m_document.CreateTextNode(owner.description));	
				eOwner.AppendChild(eDescription);
			}
			if(owner.category != null && owner.category.Length > 0){
				XmlElement eCategory = m_document.CreateElement("category");
				eCategory.AppendChild(m_document.CreateTextNode(owner.category));	
				eOwner.AppendChild(eCategory);
			}
			if(owner.mainWebPage != null && owner.mainWebPage.Length > 0){
				XmlElement eMainWebPage = m_document.CreateElement("mainWebPage");
				eMainWebPage.AppendChild(m_document.CreateTextNode(owner.mainWebPage));	
				eOwner.AppendChild(eMainWebPage);
			}
			if(owner.logoImageLink != null && owner.logoImageLink.Length > 0){
				XmlElement eLogoImageLink = m_document.CreateElement("logoImageLink");
				eLogoImageLink.AppendChild(m_document.CreateTextNode(owner.logoImageLink));	
				eOwner.AppendChild(eLogoImageLink);
			}
			if(owner.contact != null){
				XmlElement eContact = m_document.CreateElement("contact");
				if(owner.contact.name != null && owner.contact.name.Length > 0){
					XmlElement eName = m_document.CreateElement("name");
					eName.AppendChild(m_document.CreateTextNode(owner.contact.name));	
					eContact.AppendChild(eName);
				}
				if(owner.contact.title != null && owner.contact.title.Length > 0){
					XmlElement eTitle = m_document.CreateElement("title");
					eTitle.AppendChild(m_document.CreateTextNode(owner.contact.title));	
					eContact.AppendChild(eTitle);
				}
				if(owner.contact.address != null && owner.contact.address.Length > 0){
					XmlElement eAddress = m_document.CreateElement("address");
					eAddress.AppendChild(m_document.CreateTextNode(owner.contact.address));	
					eContact.AppendChild(eAddress);
				}
				if(owner.contact.phone != null && owner.contact.phone.Length > 0){
					XmlElement ePhone = m_document.CreateElement("phone");
					ePhone.AppendChild(m_document.CreateTextNode(owner.contact.phone));	
					eContact.AppendChild(ePhone);
				}
				if(owner.contact.fax != null && owner.contact.fax.Length > 0){
					XmlElement eFax = m_document.CreateElement("fax");
					eFax.AppendChild(m_document.CreateTextNode(owner.contact.fax));	
					eContact.AppendChild(eFax);
				}
				if(owner.contact.email != null && owner.contact.email.Length > 0){
					XmlElement eEmail = m_document.CreateElement("email");
					eEmail.AppendChild(m_document.CreateTextNode(owner.contact.email));	
					eContact.AppendChild(eEmail);
				}
				if(owner.contact.webPage != null && owner.contact.webPage.Length > 0){
					XmlElement eWebPage = m_document.CreateElement("name");
					eWebPage.AppendChild(m_document.CreateTextNode(owner.contact.webPage));	
					eContact.AppendChild(eWebPage);
				}
				eOwner.AppendChild(eContact);
			}
			return true;
		}//setOwner
	

		/// <summary>
		/// Set the key words of the service. 
		/// </summary>
		/// <param name="keyWords">holds the service key words.</param>
		/// <returns>whether the key words of the service are set successfully or not. </returns>
		public bool setKeyWords(string[] keyWords){
			XmlNode nodeRef = null;
			XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(m_eEntityData, "general");
			if(eGeneral == null && (keyWords == null || keyWords.Length <= 0)){
				return true;
			}
			if(eGeneral != null && (keyWords == null || keyWords.Length <= 0)){
				XMLUtil.removeChildrenByName(eGeneral, "keyWords");
				return true;
			}
			if(eGeneral == null){
				eGeneral = m_document.CreateElement("general");
				m_eEntityData.InsertBefore(eGeneral, m_eEntityData.FirstChild);
			}
			XmlElement eKeyWords = (XmlElement)XMLUtil.findChildNode(eGeneral, "keyWords");
			if(eKeyWords != null){
				XMLUtil.removeChildrenByName(eGeneral, "keyWords");
			}
			eKeyWords = m_document.CreateElement("keyWords");
			nodeRef = XMLUtil.findChildNode(eGeneral, "owner");
			if(nodeRef != null){
				eGeneral.InsertBefore(eKeyWords, nodeRef.NextSibling);			
			}
			else{
				nodeRef = XMLUtil.findChildNode(eGeneral, "access");
				if(nodeRef != null){
					eGeneral.InsertBefore(eKeyWords, nodeRef.NextSibling);			
				}
				else{
					eGeneral.InsertBefore(eKeyWords, eGeneral.FirstChild);
				}			
			}		
			int iKeys = keyWords.Length;
			for(int i = 0; i < iKeys; i++){
				if(keyWords[i]!= null && keyWords[i].Length > 0){
					XmlElement eKey = m_document.CreateElement("key");
					eKey.AppendChild(m_document.CreateTextNode(keyWords[i]));	
					eKeyWords.AppendChild(eKey);
				}			
			}
			return true;
		}//setKeyWords


		/// <summary>
		/// Set the links of the service.
		/// </summary>
		/// <param name="links">holds a Link array of the service links.  </param>
		/// <returns>the links of the service are set successfully. </returns>
		public bool setLinks(Link[] links){
			XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(m_eEntityData, "general");
			if(eGeneral == null && (links == null || links.Length <= 0)){
				return true;
			}
			if(eGeneral != null && (links == null || links.Length <= 0)){
				XMLUtil.removeChildrenByName(eGeneral, "links");
				return true;
			}
			if(eGeneral == null){
				eGeneral = m_document.CreateElement("general");
				m_eEntityData.InsertBefore(eGeneral, m_eEntityData.FirstChild);
			}
			XmlElement eLinks = (XmlElement)XMLUtil.findChildNode(eGeneral, "links");
			if(eLinks != null){
				XMLUtil.removeChildrenByName(eGeneral, "links");
			}
			eLinks = m_document.CreateElement("links");
			eGeneral.AppendChild(eLinks);			
			int iLinks = links.Length;
			for(int i = 0; i < iLinks; i++){
				if(links[i]!= null){
					XmlElement eLink = m_document.CreateElement("link");
					if(links[i].type != null && links[i].type.Length > 0){
						eLink.SetAttribute("type", links[i].type);						
					}
					if(links[i].description != null && links[i].description.Length > 0){
						eLink.SetAttribute("description", links[i].description);						
					}
					if(links[i].value != null && links[i].value.Length > 0){
						eLink.AppendChild(m_document.CreateTextNode(links[i].value));						
					}
					eLinks.AppendChild(eLink);
				}			
			}
			return true;
		}//setLinks

		/// <summary>
		///  Set the system description. 
		/// </summary>
		/// <param name="description">holds the system description. </param>
		/// <returns>whether the system description is set successfully or not. </returns>
		public bool setSystemDescription(string description){
			XmlNode nodeRef = null;
			XmlElement eSystem = (XmlElement)XMLUtil.findChildNode(m_eEntityData, "system");
			if(eSystem == null){
				eSystem = m_document.CreateElement("system");
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
				if(nodeRef != null){
					m_eEntityData.InsertBefore(eSystem, nodeRef.NextSibling);			
				}
				else{
					m_eEntityData.InsertBefore(eSystem, m_eEntityData.FirstChild);
				}			
			}
			if(description == null || description.Length <= 0){
				XMLUtil.removeChildrenByName(eSystem, "description");
				return true;
			}
			XmlElement eDescription = (XmlElement)XMLUtil.findChildNode(eSystem, "description");
			if(eDescription != null){
				XMLUtil.removeChildrenByName(eSystem, "description");
			}
			eDescription = m_document.CreateElement("description");
			eDescription.AppendChild(m_document.CreateTextNode(description));
			eSystem.AppendChild(eDescription);
			return true;
		}//setSystemDescription


		/// <summary>
		/// Set the system dedication. 
		/// </summary>
		/// <param name="dedication">holds the system dedication, a double between 0 and 1 with 1 being fully dedicated.  </param>
		/// <returns>whether the system dedication.  is set successfully or not. </returns>
		public bool setSystemDedication(double dedication){
			if(dedication < 0 || dedication > 1) return false;		
			if(Double.IsNaN(dedication) || dedication==1.0) return  true;
			XmlNode nodeRef = null;
			XmlElement eSystem = (XmlElement)XMLUtil.findChildNode(m_eEntityData, "system");
			if(eSystem == null){
				eSystem = m_document.CreateElement("system");
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
				if(nodeRef != null){
					m_eEntityData.InsertBefore(eSystem, nodeRef.NextSibling);			
				}
				else{
					m_eEntityData.InsertBefore(eSystem, m_eEntityData.FirstChild);
				}			
			}
			XmlElement eDedication = (XmlElement)XMLUtil.findChildNode(eSystem, "dedication");
			if(eDedication != null){
				XMLUtil.removeChildrenByName(eSystem, "dedication");
			}
			eDedication = m_document.CreateElement("dedication");
			eDedication.AppendChild(m_document.CreateTextNode(dedication.ToString()));
			eSystem.AppendChild(eDedication);
			return true;
		}//setSystemDedication

		/// <summary>
		/// Set the system hardware information.
		/// </summary>
		/// <param name="hardwareInfo">holds the system hardware information.</param>
		/// <returns>whether the system hardware information is set successfully or not.</returns>
		public bool setSystemHardwareInfo(HardwareInfo hardwareInfo){
			XmlNode nodeRef = null;
			XmlElement eSystem = (XmlElement)XMLUtil.findChildNode(m_eEntityData, "system");
			if(eSystem == null){
				eSystem = m_document.CreateElement("system");
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
				if(nodeRef != null){
					m_eEntityData.InsertBefore(eSystem, nodeRef.NextSibling);			
				}
				else{
					m_eEntityData.InsertBefore(eSystem, m_eEntityData.FirstChild);
				}			
			}
			if(hardwareInfo == null){
				XMLUtil.removeChildrenByName(eSystem, "hardware");
				return true;
			}
			XmlElement eHardwareInfo = (XmlElement)XMLUtil.findChildNode(eSystem, "hardware");
			if(eHardwareInfo != null){
				XMLUtil.removeChildrenByName(eSystem, "hardware");
			}
			eHardwareInfo = m_document.CreateElement("hardware");
			if(hardwareInfo.cpuNumber > 0){
				XmlElement eCPUNumber = m_document.CreateElement("cpuNumber");
				eCPUNumber.AppendChild(m_document.CreateTextNode(hardwareInfo.cpuNumber + ""));	
				eHardwareInfo.AppendChild(eCPUNumber);
			}
			if(hardwareInfo.cpuSpeed > 0){
				XmlElement eCPUSpeed = m_document.CreateElement("cpuSpeed");
				eCPUSpeed.AppendChild(m_document.CreateTextNode(hardwareInfo.cpuSpeed + ""));	
				eHardwareInfo.AppendChild(eCPUSpeed);
			}
			if(hardwareInfo.memorySize > 0){
				XmlElement eMemorySize = m_document.CreateElement("memorySize");
				eMemorySize.AppendChild(m_document.CreateTextNode(hardwareInfo.memorySize + ""));	
				eHardwareInfo.AppendChild(eMemorySize);
			}
			if(hardwareInfo.busSpeed > 0){
				XmlElement eBusSpeed = m_document.CreateElement("busSpeed");
				eBusSpeed.AppendChild(m_document.CreateTextNode(hardwareInfo.busSpeed + ""));	
				eHardwareInfo.AppendChild(eBusSpeed);
			}
			if(hardwareInfo.diskSpace > 0){
				XmlElement eDiskSpace = m_document.CreateElement("diskSpace");
				eDiskSpace.AppendChild(m_document.CreateTextNode(hardwareInfo.diskSpace + ""));	
				eHardwareInfo.AppendChild(eDiskSpace);
			}
			if(hardwareInfo.nicSpeed > 0){
				XmlElement eNICSpeed = m_document.CreateElement("nicSpeed");
				eNICSpeed.AppendChild(m_document.CreateTextNode(hardwareInfo.nicSpeed + ""));	
				eHardwareInfo.AppendChild(eNICSpeed);
			}
			if(hardwareInfo.downloadSpeed > 0){
				XmlElement eDownloadSpeed = m_document.CreateElement("downloadSpeed");
				eDownloadSpeed.AppendChild(m_document.CreateTextNode(hardwareInfo.downloadSpeed + ""));	
				eHardwareInfo.AppendChild(eDownloadSpeed);
			}
			if(hardwareInfo.uploadSpeed > 0){
				XmlElement eUploadSpeed = m_document.CreateElement("uploadSpeed");
				eUploadSpeed.AppendChild(m_document.CreateTextNode(hardwareInfo.uploadSpeed + ""));	
				eHardwareInfo.AppendChild(eUploadSpeed);
			}		
			eSystem.AppendChild(eHardwareInfo);
			return true;
		}//setSystemHardwareInfo


		/// <summary>
		/// Set the service description. 
		/// </summary>
		/// <param name="description">holds the service description.</param>
		/// <returns>whether the service description is set successfully or not. </returns>
		public bool setServiceDescription(string description){
			XmlNode nodeRef = null;
			XmlElement eService = (XmlElement)XMLUtil.findChildNode(m_eEntityData, "service");
			if(eService == null){
				eService = m_document.CreateElement("service");
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
				if(nodeRef != null){
					m_eEntityData.InsertBefore(eService, nodeRef.NextSibling);			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
					if(nodeRef != null){
						m_eEntityData.InsertBefore(eService, nodeRef.NextSibling);			
					}
					else{
						m_eEntityData.InsertBefore(eService, m_eEntityData.FirstChild);
					}			
				}			
			}
			if(description == null || description.Length <= 0){
				XMLUtil.removeChildrenByName(eService, "description");
				return true;
			}
			XmlElement eDescription = (XmlElement)XMLUtil.findChildNode(eService, "description");
			if(eDescription != null){
				XMLUtil.removeChildrenByName(eService, "description");
			}
			eDescription = m_document.CreateElement("description");
			eDescription.AppendChild(m_document.CreateTextNode(description));
			eService.AppendChild(eDescription);
			return true;
		}//setServiceDescription


		/// <summary>
		/// Set the service type. 
		/// </summary>
		/// <param name="type">holds the service type, which can be:
		/// solver, analyzer, scheduler, simulation, registry, modeler, agent </param>
		/// <returns>whether the service type is set successfully or not. </returns>
		public bool setServiceType(string type){
			XmlNode nodeRef = null;
			XmlElement eService = (XmlElement)XMLUtil.findChildNode(m_eEntityData, "service");
			if(eService == null){
				eService = m_document.CreateElement("service");
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
				if(nodeRef != null){
					m_eEntityData.InsertBefore(eService, nodeRef.NextSibling);			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
					if(nodeRef != null){
						m_eEntityData.InsertBefore(eService, nodeRef.NextSibling);			
					}
					else{
						m_eEntityData.InsertBefore(eService, m_eEntityData.FirstChild);
					}			
				}			
			}
			if(type == null || type.Length <= 0){
				XMLUtil.removeChildrenByName(eService, "type");
				return true;
			}
			if(!type.Equals("solver") && 
				!type.Equals("analyzer") &&
				!type.Equals("scheduler") &&
				!type.Equals("simulation") &&
				!type.Equals("registry") &&
				!type.Equals("modeler") &&
				!type.Equals("agent")) return false;
			XmlElement eType = (XmlElement)XMLUtil.findChildNode(eService, "type");
			if(eType != null){
				XMLUtil.removeChildrenByName(eService, "type");
			}
			eType = m_document.CreateElement("type");
			eType.AppendChild(m_document.CreateTextNode(type));
			eService.AppendChild(eType);
			return true;
		}//setServiceType


		/// <summary>
		/// Set the service category. 
		/// </summary>
		/// <param name="category">holds the service category, which can be:
		///  education, government, organization, company, military, personal, other</param>
		/// <returns>whether the service category is set successfully or not. </returns>
		public bool setServiceCategory(string category){
			XmlNode nodeRef = null;
			XmlElement eService = (XmlElement)XMLUtil.findChildNode(m_eEntityData, "service");
			if(eService == null){
				eService = m_document.CreateElement("service");
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
				if(nodeRef != null){
					m_eEntityData.InsertBefore(eService, nodeRef.NextSibling);			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
					if(nodeRef != null){
						m_eEntityData.InsertBefore(eService, nodeRef.NextSibling);			
					}
					else{
						m_eEntityData.InsertBefore(eService, m_eEntityData.FirstChild);
					}			
				}			
			}
			if(category == null || category.Length <= 0){
				XMLUtil.removeChildrenByName(eService, "category");
				return true;
			}
			if(!category.Equals("education") && 
				!category.Equals("government") &&
				!category.Equals("organization") &&
				!category.Equals("company") &&
				!category.Equals("military") &&
				!category.Equals("personal") &&
				!category.Equals("other")) return false;
			XmlElement eCategory = (XmlElement)XMLUtil.findChildNode(eService, "category");
			if(eCategory != null){
				XMLUtil.removeChildrenByName(eService, "category");
			}
			eCategory = m_document.CreateElement("category");
			eCategory.AppendChild(m_document.CreateTextNode(category));
			eService.AppendChild(eCategory);
			return true;
		}//setServiceCategory


		/// <summary>
		/// Set the service software description. 
		/// </summary>
		/// <param name="softwareDescription">holds the software description.</param>
		/// <returns>whether the software description is set successfully or not. </returns>
		public bool setServiceSoftwareDescription(string softwareDescription){
			XmlNode nodeRef = null;
			XmlElement eService = (XmlElement)XMLUtil.findChildNode(m_eEntityData, "service");
			if(eService == null){
				eService = m_document.CreateElement("service");
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
				if(nodeRef != null){
					m_eEntityData.InsertBefore(eService, nodeRef.NextSibling);			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
					if(nodeRef != null){
						m_eEntityData.InsertBefore(eService, nodeRef.NextSibling);			
					}
					else{
						m_eEntityData.InsertBefore(eService, m_eEntityData.FirstChild);
					}			
				}			
			}
			if(softwareDescription == null || softwareDescription.Length <= 0){
				XMLUtil.removeChildrenByName(eService, "software");
				return true;
			}
			XmlElement eSoftwareDescription = (XmlElement)XMLUtil.findChildNode(eService, "software");
			if(eSoftwareDescription != null){
				XMLUtil.removeChildrenByName(eService, "software");
			}
			eSoftwareDescription = m_document.CreateElement("software");
			eSoftwareDescription.AppendChild(m_document.CreateTextNode(softwareDescription));
			eService.AppendChild(eSoftwareDescription);
			return true;
		}//setServiceSoftwareDescription



		/// <summary>
		/// Set the algorithm description. 
		/// </summary>
		/// <param name="algorithmDescription">holds the algorithm description.</param>
		/// <returns>whether the algorithm description is set successfully or not. </returns>
		public bool setServiceAlgorithmDescription(string algorithmDescription){
			XmlNode nodeRef = null;
			XmlElement eService = (XmlElement)XMLUtil.findChildNode(m_eEntityData, "service");
			if(eService == null){
				eService = m_document.CreateElement("service");
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
				if(nodeRef != null){
					m_eEntityData.InsertBefore(eService, nodeRef.NextSibling);			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
					if(nodeRef != null){
						m_eEntityData.InsertBefore(eService, nodeRef.NextSibling);			
					}
					else{
						m_eEntityData.InsertBefore(eService, m_eEntityData.FirstChild);
					}			
				}			
			}
			if(algorithmDescription == null || algorithmDescription.Length <= 0){
				XMLUtil.removeChildrenByName(eService, "algorithmDescription");
				return true;
			}
			XmlElement eAlgorithmDescription = (XmlElement)XMLUtil.findChildNode(eService, "description");
			if(eAlgorithmDescription != null){
				XMLUtil.removeChildrenByName(eService, "description");
			}
			eAlgorithmDescription = m_document.CreateElement("description");
			eAlgorithmDescription.AppendChild(m_document.CreateTextNode(algorithmDescription));
			eService.AppendChild(eAlgorithmDescription);
			return true;
		}//setServiceAlgorithmDescription


		/// <summary>
		/// Set the service web page. 
		/// </summary>
		/// <param name="webPage">webPage holds the service web page.</param>
		/// <returns>whether the service web page is set successfully or not. </returns>
		public bool setServiceWebPage(string webPage){
			XmlNode nodeRef = null;
			XmlElement eService = (XmlElement)XMLUtil.findChildNode(m_eEntityData, "service");
			if(eService == null){
				eService = m_document.CreateElement("service");
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
				if(nodeRef != null){
					m_eEntityData.InsertBefore(eService, nodeRef.NextSibling);			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
					if(nodeRef != null){
						m_eEntityData.InsertBefore(eService, nodeRef.NextSibling);			
					}
					else{
						m_eEntityData.InsertBefore(eService, m_eEntityData.FirstChild);
					}			
				}			
			}
			if(webPage == null || webPage.Length <= 0){
				XMLUtil.removeChildrenByName(eService, "webPage");
				return true;
			}
			XmlElement eWebPage = (XmlElement)XMLUtil.findChildNode(eService, "webPage");
			if(eWebPage != null){
				XMLUtil.removeChildrenByName(eService, "webPage");
			}
			eWebPage = m_document.CreateElement("webPage");
			eWebPage.AppendChild(m_document.CreateTextNode(webPage));
			eService.AppendChild(eWebPage);
			return true;
		}//setServiceWebPage


		/// <summary>
		/// Set the service wsdl location. 
		/// </summary>
		/// <param name="wsdlLocation">holds the service wsdl location.</param>
		/// <returns>whether the service wsdlLocation is set successfully or not. </returns>
		public bool setServiceWSDLLocation(string wsdlLocation){
			XmlNode nodeRef = null;
			XmlElement eService = (XmlElement)XMLUtil.findChildNode(m_eEntityData, "service");
			if(eService == null){
				eService = m_document.CreateElement("service");
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
				if(nodeRef != null){
					m_eEntityData.InsertBefore(eService, nodeRef.NextSibling);			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
					if(nodeRef != null){
						m_eEntityData.InsertBefore(eService, nodeRef.NextSibling);			
					}
					else{
						m_eEntityData.InsertBefore(eService, m_eEntityData.FirstChild);
					}			
				}			
			}
			if(wsdlLocation == null || wsdlLocation.Length <= 0){
				XMLUtil.removeChildrenByName(eService, "wsdlLocation");
				return true;
			}
			XmlElement eWsdlLocation = (XmlElement)XMLUtil.findChildNode(eService, "wsdlLocation");
			if(eWsdlLocation != null){
				XMLUtil.removeChildrenByName(eService, "wsdlLocation");
			}
			eWsdlLocation = m_document.CreateElement("wsdlLocation");
			eWsdlLocation.AppendChild(m_document.CreateTextNode(wsdlLocation));
			eService.AppendChild(eWsdlLocation);
			return true;
		}//setServiceWSDLLocation

		/// <summary>
		/// Set the service logo image link. 
		/// </summary>
		/// <param name="logoImageLink">holds the service logo image link.</param>
		/// <returns>whether the service logoImageLink is set successfully or not. </returns>
		public bool setServiceLogoImageLink(string logoImageLink){
			XmlNode nodeRef = null;
			XmlElement eService = (XmlElement)XMLUtil.findChildNode(m_eEntityData, "service");
			if(eService == null){
				eService = m_document.CreateElement("service");
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
				if(nodeRef != null){
					m_eEntityData.InsertBefore(eService, nodeRef.NextSibling);			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
					if(nodeRef != null){
						m_eEntityData.InsertBefore(eService, nodeRef.NextSibling);			
					}
					else{
						m_eEntityData.InsertBefore(eService, m_eEntityData.FirstChild);
					}			
				}			
			}
			if(logoImageLink == null || logoImageLink.Length <= 0){
				XMLUtil.removeChildrenByName(eService, "logoImageLink");
				return true;
			}
			XmlElement eLogoImageLink = (XmlElement)XMLUtil.findChildNode(eService, "logoImageLink");
			if(eLogoImageLink != null){
				XMLUtil.removeChildrenByName(eService, "logoImageLink");
			}
			eLogoImageLink = m_document.CreateElement("logoImageLink");
			eLogoImageLink.AppendChild(m_document.CreateTextNode(logoImageLink));
			eService.AppendChild(eLogoImageLink);
			return true;
		}//setServiceLogoImageLink


		/// <summary>
		/// Set the default option names and values in the standard OSOption structure which 
		/// is specified by the OSoL schema. 
		/// </summary>
		/// <param name="osOption">holds the default option names and values in the standard OSOption structure. </param>
		/// <returns>wehter the the default option names and values are set successfully or not. </returns>
		public bool setDefaultOptionNamesAndValues(OSOption osOption){
			XmlNode nodeRef = null;
			XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eEntityData, "job");
			if(eJob == null && osOption == null){
				return true;
			}
			if(eJob != null && osOption == null){
				XMLUtil.removeChildrenByName(eJob, "osol");
				return true;
			}
			if(eJob == null){
				eJob = m_document.CreateElement("job");
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "service");			
				if(nodeRef != null){
					m_eEntityData.InsertBefore(eJob, nodeRef.NextSibling);			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
					if(nodeRef != null){
						m_eEntityData.InsertBefore(eJob, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
						if(nodeRef != null){
							m_eEntityData.InsertBefore(eJob, nodeRef.NextSibling);			
						}
						else{
							m_eEntityData.InsertBefore(eJob, m_eEntityData.FirstChild);
						}			
					}			
				}			
			}
			XmlElement eOSoL = (XmlElement)XMLUtil.findChildNode(eJob, "osol");
			if(eOSoL != null){
				XMLUtil.removeChildrenByName(eJob, "osol");
			}
			OSoLWriter osolWriter = new OSoLWriter();
			try {
				osolWriter.setOSOption(osOption);
			} 
			catch (Exception e) {
				Console.WriteLine(e.ToString());
			}
			eOSoL =  (XmlElement)m_document.ImportNode(osolWriter.m_eOSoL, true);
			XMLUtil.removeAllAttributes(eOSoL);
			eJob.AppendChild(eOSoL);
			return true;
		}//setDefaultOptionNamesAndValues

		/// <summary>
		/// Set the optimization description. 
		/// </summary>
		/// <param name="description">holds the optimization description.</param>
		/// <returns>whether the optimization description is set successfully or not. </returns>
		public bool setOptimizationDescription(string description){
			XmlNode nodeRef = null;
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eEntityData, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.CreateElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "job");			
				if(nodeRef != null){
					m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "service");			
					if(nodeRef != null){
						m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
						if(nodeRef != null){
							m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
							if(nodeRef != null){
								m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
							}
							else{
								m_eEntityData.InsertBefore(eOptimization, m_eEntityData.FirstChild);
							}		
						}		
					}			
				}			
			}
			if(description == null || description.Length <= 0){
				XMLUtil.removeChildrenByName(eOptimization, "description");
				return true;
			}
			XmlElement eDescription = (XmlElement)XMLUtil.findChildNode(eOptimization, "description");
			if(eDescription != null){
				XMLUtil.removeChildrenByName(eOptimization, "description");
			}
			eDescription = m_document.CreateElement("description");
			eDescription.AppendChild(m_document.CreateTextNode(description));
			eOptimization.AppendChild(eDescription);
			return true;
		}//setOptimizationDescription

		/// <summary>
		/// Set the optimization variable type. 
		/// </summary>
		/// <param name="variableType">holds the optimization variable type, which can be:
		/// continuous, pureBinary, mixedBinary, pureInteger, mixedInteger, discrete</param>
		/// <returns>whether the optimization variable type is set successfully or not. </returns>
		public bool setOptimizationVariableType(string variableType){
			XmlNode nodeRef = null;
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eEntityData, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.CreateElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "job");			
				if(nodeRef != null){
					m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "service");			
					if(nodeRef != null){
						m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
						if(nodeRef != null){
							m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
							if(nodeRef != null){
								m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
							}
							else{
								m_eEntityData.InsertBefore(eOptimization, m_eEntityData.FirstChild);
							}		
						}		
					}			
				}			
			}
			if(variableType == null || variableType.Length <= 0){
				XMLUtil.removeChildrenByName(eOptimization, "variableType");
				return true;
			}
			if(!variableType.Equals("continuous") && 
				!variableType.Equals("pureBinary") &&
				!variableType.Equals("mixedBinary") &&
				!variableType.Equals("pureInteger") &&
				!variableType.Equals("mixedInteger") &&
				!variableType.Equals("discrete")) return false;
			XmlElement eVariableType = (XmlElement)XMLUtil.findChildNode(eOptimization, "variableType");
			if(eVariableType != null){
				XMLUtil.removeChildrenByName(eOptimization, "variableType");
			}
			eVariableType = m_document.CreateElement("variableType");
			eVariableType.AppendChild(m_document.CreateTextNode(variableType));
			eOptimization.AppendChild(eVariableType);
			return true;
		}//setOptimizationVariableType

		/// <summary>
		/// Set the optimization objective type. 
		/// </summary>
		/// <param name="objectiveType">holds the optimization objective type, which can be:
		/// none, singleObjective, multiObjectives</param>
		/// <returns>whether the optimization objective type is set successfully or not.</returns>
		public bool setOptimizationObjectiveType(string objectiveType){
			XmlNode nodeRef = null;
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eEntityData, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.CreateElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "job");			
				if(nodeRef != null){
					m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "service");			
					if(nodeRef != null){
						m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
						if(nodeRef != null){
							m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
							if(nodeRef != null){
								m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
							}
							else{
								m_eEntityData.InsertBefore(eOptimization, m_eEntityData.FirstChild);
							}		
						}		
					}			
				}			
			}
			if(objectiveType == null || objectiveType.Length <= 0){
				XMLUtil.removeChildrenByName(eOptimization, "objectiveType");
				return true;
			}
			if(!objectiveType.Equals("none") && 
				!objectiveType.Equals("singleObjective") &&
				!objectiveType.Equals("multiObjectives")) return false;
			if(objectiveType == null || objectiveType.Length <= 0){
				XMLUtil.removeChildrenByName(eOptimization, "objectiveType");
				return true;
			}
			XmlElement eObjectiveType = (XmlElement)XMLUtil.findChildNode(eOptimization, "objectiveType");
			if(eObjectiveType != null){
				XMLUtil.removeChildrenByName(eOptimization, "objectiveType");
			}
			eObjectiveType = m_document.CreateElement("objectiveType");
			eObjectiveType.AppendChild(m_document.CreateTextNode(objectiveType));
			eOptimization.AppendChild(eObjectiveType);
			return true;
		}//setOptimizationObjectiveType

		/// <summary>
		/// Set the optimization constraint type. 
		/// </summary>
		/// <param name="constraintType">holds the optimization constraint type, which can be:
		/// generalRange, pureEquality, pureBound, 
		/// pureLinearComplementarity, pureNonlinearComplementarity, 
		/// linearMixedComplementarity, nonlinearMixedComplementarity, generalMixedComplementarity,
		/// pureCone, mixedCone. 
		/// </param>
		/// <returns></returns>
		public bool setOptimizationConstraintType(string constraintType){
			XmlNode nodeRef = null;
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eEntityData, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.CreateElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "job");			
				if(nodeRef != null){
					m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "service");			
					if(nodeRef != null){
						m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
						if(nodeRef != null){
							m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
							if(nodeRef != null){
								m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
							}
							else{
								m_eEntityData.InsertBefore(eOptimization, m_eEntityData.FirstChild);
							}		
						}		
					}			
				}			
			}
			if(constraintType == null || constraintType.Length <= 0){
				XMLUtil.removeChildrenByName(eOptimization, "constraintType");
				return true;
			}
			if(!constraintType.Equals("generalRange") && 
				!constraintType.Equals("pureEquality") &&
				!constraintType.Equals("pureBound") &&
				!constraintType.Equals("pureLinearComplementarity") &&
				!constraintType.Equals("pureNonlinearComplementarity") &&
				!constraintType.Equals("linearMixedComplementarity") &&
				!constraintType.Equals("nonlinearMixedComplementarity") &&
				!constraintType.Equals("generalMixedComplementarity") &&
				!constraintType.Equals("pureCone") &&
				!constraintType.Equals("mixedCone")) return false;
			XmlElement eConstraintType = (XmlElement)XMLUtil.findChildNode(eOptimization, "constraintType");
			if(eConstraintType != null){
				XMLUtil.removeChildrenByName(eOptimization, "constraintType");
			}
			eConstraintType = m_document.CreateElement("constraintType");
			eConstraintType.AppendChild(m_document.CreateTextNode(constraintType));
			eOptimization.AppendChild(eConstraintType);
			return true;
		}//setOptimizationConstraintType



		/// <summary>
		/// Set the optimization objective linearity. 
		/// </summary>
		/// <param name="objectiveLinearity">holds the optimization objective linearity, which can be:
		/// none, linearNetwork, linear sumOfSquares, convexQuadratic, convexNonlinear, generalQuadratic, generalNonlinear
		/// </param>
		/// <returns>whether the optimization objective linearity is set successfully or not. </returns>
		public bool setOptimizationObjectiveLinearity(string objectiveLinearity){
			XmlNode nodeRef = null;
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eEntityData, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.CreateElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "job");			
				if(nodeRef != null){
					m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "service");			
					if(nodeRef != null){
						m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
						if(nodeRef != null){
							m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
							if(nodeRef != null){
								m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
							}
							else{
								m_eEntityData.InsertBefore(eOptimization, m_eEntityData.FirstChild);
							}		
						}		
					}			
				}			
			}
			if(objectiveLinearity == null || objectiveLinearity.Length <= 0){
				XMLUtil.removeChildrenByName(eOptimization, "objectiveLinearity");
				return true;
			}
			if(!objectiveLinearity.Equals("none") && 
				!objectiveLinearity.Equals("linearNetwork") &&
				!objectiveLinearity.Equals("linear") &&
				!objectiveLinearity.Equals("sumOfSquares") &&
				!objectiveLinearity.Equals("convexQuadratic") &&
				!objectiveLinearity.Equals("convexNonlinear") &&
				!objectiveLinearity.Equals("generalQuadratic") &&
				!objectiveLinearity.Equals("generalNonlinear")) return false;
			XmlElement eObjectiveLinearity = (XmlElement)XMLUtil.findChildNode(eOptimization, "objectiveLinearity");
			if(eObjectiveLinearity != null){
				XMLUtil.removeChildrenByName(eOptimization, "objectiveLinearity");
			}
			eObjectiveLinearity = m_document.CreateElement("objectiveLinearity");
			eObjectiveLinearity.AppendChild(m_document.CreateTextNode(objectiveLinearity));
			eOptimization.AppendChild(eObjectiveLinearity);
			return true;
		}//setOptimizationObjectiveLinearity

		/// <summary>
		/// Set the optimization constraint linearity. 
		/// </summary>
		/// <param name="constraintLinearity">holds the optimization constraint linearity, which can be:
		///  none, bound, linearNetwork, linear, convexQuadratic, convexNonlinear, generalQuadratic, generalNonlinear
		/// </param>
		/// <returns>whether the optimization constraint linearity is set successfully or not. </returns>
		public bool setOptimizationConstraintLinearity(string constraintLinearity){
			XmlNode nodeRef = null;
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eEntityData, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.CreateElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "job");			
				if(nodeRef != null){
					m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "service");			
					if(nodeRef != null){
						m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
						if(nodeRef != null){
							m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
							if(nodeRef != null){
								m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
							}
							else{
								m_eEntityData.InsertBefore(eOptimization, m_eEntityData.FirstChild);
							}		
						}		
					}			
				}			
			}
			if(constraintLinearity == null || constraintLinearity.Length <= 0){
				XMLUtil.removeChildrenByName(eOptimization, "constraintLinearity");
				return true;
			}
			if(!constraintLinearity.Equals("none") && 
				!constraintLinearity.Equals("bound") &&
				!constraintLinearity.Equals("linearNetwork") &&
				!constraintLinearity.Equals("linear") &&
				!constraintLinearity.Equals("convexQuadratic") &&
				!constraintLinearity.Equals("convexNonlinear") &&
				!constraintLinearity.Equals("generalQuadratic") &&
				!constraintLinearity.Equals("generalNonlinear")) return false;
			XmlElement eConstraintLinearity = (XmlElement)XMLUtil.findChildNode(eOptimization, "constraintLinearity");
			if(eConstraintLinearity != null){
				XMLUtil.removeChildrenByName(eOptimization, "constraintLinearity");
			}
			eConstraintLinearity = m_document.CreateElement("constraintLinearity");
			eConstraintLinearity.AppendChild(m_document.CreateTextNode(constraintLinearity));
			eOptimization.AppendChild(eConstraintLinearity);
			return true;
		}//setOptimizationConstraintLinearity
	
		/// <summary>
		/// Set the optimization objective differentiability. 
		/// </summary>
		/// <param name="objectiveDifferentiability">holds the optimization objective differentiability, which can be:
		/// generallyDifferentiable, twiceDifferentiable, firstDifferentiable, 
		/// nonDifferentiableContinous, nonContinuous, simulation. 
		/// </param>
		/// <returns>whether the optimization objective differentiability is set successfully or not. </returns>
		public bool setOptimizationObjectiveDifferentiability(string objectiveDifferentiability){
			XmlNode nodeRef = null;
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eEntityData, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.CreateElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "job");			
				if(nodeRef != null){
					m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "service");			
					if(nodeRef != null){
						m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
						if(nodeRef != null){
							m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
							if(nodeRef != null){
								m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
							}
							else{
								m_eEntityData.InsertBefore(eOptimization, m_eEntityData.FirstChild);
							}		
						}		
					}			
				}			
			}
			if(objectiveDifferentiability == null || objectiveDifferentiability.Length <= 0){
				XMLUtil.removeChildrenByName(eOptimization, "objectiveDifferentiability");
				return true;
			}
			if(!objectiveDifferentiability.Equals("generallyDifferentiable") && 
				!objectiveDifferentiability.Equals("twiceDifferentiable") &&
				!objectiveDifferentiability.Equals("firstDifferentiable") &&
				!objectiveDifferentiability.Equals("nonDifferentiableContinous") &&
				!objectiveDifferentiability.Equals("nonContinuous") &&
				!objectiveDifferentiability.Equals("simulation")) return false;
			XmlElement eObjectiveDifferentiability = (XmlElement)XMLUtil.findChildNode(eOptimization, "objectiveDifferentiability");
			if(eObjectiveDifferentiability != null){
				XMLUtil.removeChildrenByName(eOptimization, "objectiveDifferentiability");
			}
			eObjectiveDifferentiability = m_document.CreateElement("objectiveDifferentiability");
			eObjectiveDifferentiability.AppendChild(m_document.CreateTextNode(objectiveDifferentiability));
			eOptimization.AppendChild(eObjectiveDifferentiability);
			return true;
		}//setOptimizationObjectiveDifferentiability

		/// <summary>
		/// Set the optimization constraint differentiability. 
		/// </summary>
		/// <param name="constraintDifferentiability">holds the optimization constraint differentiability, which can be:
		/// generallyDifferentiable, twiceDifferentiable, firstDifferentiable, 
		/// nonDifferentiableContinous, nonContinuous, simulation. 
		/// </param>
		/// <returns>whether the optimization constraint differentiability is set successfully or not. </returns>
		public bool setOptimizationConstraintDifferentiability(string constraintDifferentiability){
			XmlNode nodeRef = null;
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eEntityData, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.CreateElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "job");			
				if(nodeRef != null){
					m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "service");			
					if(nodeRef != null){
						m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
						if(nodeRef != null){
							m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
							if(nodeRef != null){
								m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
							}
							else{
								m_eEntityData.InsertBefore(eOptimization, m_eEntityData.FirstChild);
							}		
						}		
					}			
				}			
			}
			if(constraintDifferentiability == null || constraintDifferentiability.Length <= 0){
				XMLUtil.removeChildrenByName(eOptimization, "constraintDifferentiability");
				return true;
			}
			if(!constraintDifferentiability.Equals("generallyDifferentiable") && 
				!constraintDifferentiability.Equals("twiceDifferentiable") &&
				!constraintDifferentiability.Equals("firstDifferentiable") &&
				!constraintDifferentiability.Equals("nonDifferentiableContinous") &&
				!constraintDifferentiability.Equals("nonContinuous") &&
				!constraintDifferentiability.Equals("simulation")) return false;
			XmlElement eConstraintDifferentiability = (XmlElement)XMLUtil.findChildNode(eOptimization, "constraintDifferentiability");
			if(eConstraintDifferentiability != null){
				XMLUtil.removeChildrenByName(eOptimization, "constraintDifferentiability");
			}
			eConstraintDifferentiability = m_document.CreateElement("constraintDifferentiability");
			eConstraintDifferentiability.AppendChild(m_document.CreateTextNode(constraintDifferentiability));
			eOptimization.AppendChild(eConstraintDifferentiability);
			return true;
		}//setOptimizationConstraintDifferentiability

		/// <summary>
		/// Set the optimization parameter type. 
		/// </summary>
		/// <param name="parameterType">parameterType holds the optimization parameter type, which can be:
		/// number, string, both
		/// </param>
		/// <returns>whether the optimization parameter type is set successfully or not. </returns>
		public bool setOptimizationParameterType(string parameterType){
			XmlNode nodeRef = null;
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eEntityData, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.CreateElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "job");			
				if(nodeRef != null){
					m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "service");			
					if(nodeRef != null){
						m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
						if(nodeRef != null){
							m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
							if(nodeRef != null){
								m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
							}
							else{
								m_eEntityData.InsertBefore(eOptimization, m_eEntityData.FirstChild);
							}		
						}		
					}			
				}			
			}
			if(parameterType == null || parameterType.Length <= 0){
				XMLUtil.removeChildrenByName(eOptimization, "parameterType");
				return true;
			}
			if(!parameterType.Equals("number") && 
				!parameterType.Equals("string") &&
				!parameterType.Equals("both")) return false;
			XmlElement eParameterType = (XmlElement)XMLUtil.findChildNode(eOptimization, "parameterType");
			if(eParameterType != null){
				XMLUtil.removeChildrenByName(eOptimization, "parameterType");
			}
			eParameterType = m_document.CreateElement("parameterType");
			eParameterType.AppendChild(m_document.CreateTextNode(parameterType));
			eOptimization.AppendChild(eParameterType);
			return true;
		}//setOptimizationParameterType

		/// <summary>
		/// Set the optimization stochasticity. 
		/// </summary>
		/// <param name="stochasticity">holds the optimization stochasticity, which can be:
		/// deterministic, stochastic, both
		/// </param>
		/// <returns>whether the optimization stochasticity is set successfully or not. </returns>
		public bool setOptimizationStochasticity(string stochasticity){
			XmlNode nodeRef = null;
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eEntityData, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.CreateElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "job");			
				if(nodeRef != null){
					m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "service");			
					if(nodeRef != null){
						m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
						if(nodeRef != null){
							m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
							if(nodeRef != null){
								m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
							}
							else{
								m_eEntityData.InsertBefore(eOptimization, m_eEntityData.FirstChild);
							}		
						}		
					}			
				}			
			}
			if(stochasticity == null || stochasticity.Length <= 0){
				XMLUtil.removeChildrenByName(eOptimization, "stochasticity");
				return true;
			}
			if(!stochasticity.Equals("deterministic") && 
				!stochasticity.Equals("stochastic") &&
				!stochasticity.Equals("both")) return false;
			XmlElement eStochasticity = (XmlElement)XMLUtil.findChildNode(eOptimization, "stochasticity");
			if(eStochasticity != null){
				XMLUtil.removeChildrenByName(eOptimization, "stochasticity");
			}
			eStochasticity = m_document.CreateElement("stochasticity");
			eStochasticity.AppendChild(m_document.CreateTextNode(stochasticity));
			eOptimization.AppendChild(eStochasticity);
			return true;
		}//setOptimizationStochasticity


		/// <summary>
		/// Set whether the service supports real time optimization or not.  
		/// </summary>
		/// <param name="realTime">holds whether the service supports real time optimization or not.  </param>
		/// <returns>whether the service supports real time optimization or not.  </returns>
		public bool setOptimizationRealTime(bool realTime){
			XmlNode nodeRef = null;
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eEntityData, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.CreateElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "job");			
				if(nodeRef != null){
					m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "service");			
					if(nodeRef != null){
						m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
						if(nodeRef != null){
							m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
							if(nodeRef != null){
								m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
							}
							else{
								m_eEntityData.InsertBefore(eOptimization, m_eEntityData.FirstChild);
							}		
						}		
					}			
				}			
			}
			if(realTime == false){
				XMLUtil.removeChildrenByName(eOptimization, "realTime");
				return true;
			}
			XmlElement eRealTime = (XmlElement)XMLUtil.findChildNode(eOptimization, "realTime");
			if(eRealTime != null){
				XMLUtil.removeChildrenByName(eOptimization, "realTime");
			}
			eRealTime = m_document.CreateElement("realTime");
			eRealTime.AppendChild(m_document.CreateTextNode(realTime?"true":"false"));
			eOptimization.AppendChild(eRealTime);
			return true;
		}//setOptimizationRealTime



		/// <summary>
		/// Set the function types that the service supports.   
		/// </summary>
		/// <param name="functionType">holds the function types that the service supports.    </param>
		/// <returns>the function types that the service supports. </returns>
		public bool setOptimizationFunctionType(FunctionType functionType){
			XmlNode nodeRef = null;
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eEntityData, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.CreateElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "job");			
				if(nodeRef != null){
					m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "service");			
					if(nodeRef != null){
						m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
						if(nodeRef != null){
							m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
							if(nodeRef != null){
								m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
							}
							else{
								m_eEntityData.InsertBefore(eOptimization, m_eEntityData.FirstChild);
							}		
						}		
					}			
				}			
			}
			if(functionType == null){
				XMLUtil.removeChildrenByName(eOptimization, "functionType");
				return true;
			}
			XmlElement eFunctionType = (XmlElement)XMLUtil.findChildNode(eOptimization, "functionType");
			if(eFunctionType != null){
				XMLUtil.removeChildrenByName(eOptimization, "functionType");
			}
			eFunctionType = m_document.CreateElement("functionType");
			XmlElement eGeneral = m_document.CreateElement("general");
			eGeneral.AppendChild(m_document.CreateTextNode(functionType.general?"true":"false"));
			eFunctionType.AppendChild(eGeneral);
			XmlElement eBasic = m_document.CreateElement("basic");
			eBasic.AppendChild(m_document.CreateTextNode(functionType.basic?"true":"false"));
			eFunctionType.AppendChild(eBasic);
			XmlElement eArithmetic = m_document.CreateElement("arithmetic");
			eArithmetic.AppendChild(m_document.CreateTextNode(functionType.arithmetic?"true":"false"));
			eFunctionType.AppendChild(eArithmetic);
			XmlElement eTrigonometric = m_document.CreateElement("trigonometric");
			eTrigonometric.AppendChild(m_document.CreateTextNode(functionType.trigonometric?"true":"false"));
			eFunctionType.AppendChild(eTrigonometric);
			XmlElement eStatistics = m_document.CreateElement("statistics");
			eStatistics.AppendChild(m_document.CreateTextNode(functionType.statistics?"true":"false"));
			eFunctionType.AppendChild(eStatistics);
			XmlElement eProbability = m_document.CreateElement("probability");
			eProbability.AppendChild(m_document.CreateTextNode(functionType.probability?"true":"false"));
			eFunctionType.AppendChild(eProbability);
			XmlElement eRelationalAndLogic = m_document.CreateElement("relationalAndLogic");
			eRelationalAndLogic.AppendChild(m_document.CreateTextNode(functionType.relationalAndLogic?"true":"false"));
			eFunctionType.AppendChild(eRelationalAndLogic);
			XmlElement eUserFunction = m_document.CreateElement("userFunction");
			eUserFunction.AppendChild(m_document.CreateTextNode(functionType.userFunction?"true":"false"));
			eFunctionType.AppendChild(eUserFunction);
			XmlElement eSimulation = m_document.CreateElement("simulation");
			eSimulation.AppendChild(m_document.CreateTextNode(functionType.simulation?"true":"false"));
			eFunctionType.AppendChild(eSimulation);
		
			eOptimization.AppendChild(eFunctionType);
			return true;
		}//setOptimizationFunctionType

		/// <summary>
		/// Set the special structures that the service supports.   
		/// </summary>
		/// <param name="specialStructure">holds the special structures that the service supports.     </param>
		/// <returns>the special structures that the service supports.   </returns>
		public bool setOptimizationSpecialStructure(SpecialStructure specialStructure){
			XmlNode nodeRef = null;
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eEntityData, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.CreateElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "job");			
				if(nodeRef != null){
					m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "service");			
					if(nodeRef != null){
						m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
						if(nodeRef != null){
							m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
							if(nodeRef != null){
								m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
							}
							else{
								m_eEntityData.InsertBefore(eOptimization, m_eEntityData.FirstChild);
							}		
						}		
					}			
				}			
			}
			if(specialStructure == null){
				XMLUtil.removeChildrenByName(eOptimization, "specialStructure");
				return true;
			}
			XmlElement eSpecialStructure = (XmlElement)XMLUtil.findChildNode(eOptimization, "specialStructure");
			if(eSpecialStructure != null){
				XMLUtil.removeChildrenByName(eOptimization, "specialStructure");
			}
			eSpecialStructure = m_document.CreateElement("specialStructure");
			XmlElement eSemidefiniteProgram = m_document.CreateElement("semidefiniteProgram");
			eSemidefiniteProgram.AppendChild(m_document.CreateTextNode(specialStructure.semidefiniteProgram?"true":"false"));
			eSpecialStructure.AppendChild(eSemidefiniteProgram);
			XmlElement eConeProgram = m_document.CreateElement("coneProgram");
			eConeProgram.AppendChild(m_document.CreateTextNode(specialStructure.coneProgram?"true":"false"));
			eSpecialStructure.AppendChild(eConeProgram);
			XmlElement eDisjunctiveProgram = m_document.CreateElement("disjunctiveProgram");
			eDisjunctiveProgram.AppendChild(m_document.CreateTextNode(specialStructure.disjunctiveProgram?"true":"false"));
			eSpecialStructure.AppendChild(eDisjunctiveProgram);

			eOptimization.AppendChild(eSpecialStructure);
			return true;
		}//setOptimizationSpecialStructure


		/// <summary>
		/// Set the special algorithms that the service supports.   
		/// </summary>
		/// <param name="specialAlgorithm">holds the special algorithms that the service supports.    </param>
		/// <returns>the special algorithms that the service supports.   </returns>
		public bool setOptimizationSpecialAlgorithm(SpecialAlgorithm specialAlgorithm){
			XmlNode nodeRef = null;
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eEntityData, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.CreateElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eEntityData, "job");			
				if(nodeRef != null){
					m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eEntityData, "service");			
					if(nodeRef != null){
						m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eEntityData, "system");			
						if(nodeRef != null){
							m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eEntityData, "general");			
							if(nodeRef != null){
								m_eEntityData.InsertBefore(eOptimization, nodeRef.NextSibling);			
							}
							else{
								m_eEntityData.InsertBefore(eOptimization, m_eEntityData.FirstChild);
							}		
						}		
					}			
				}			
			}
			if(specialAlgorithm == null){
				XMLUtil.removeChildrenByName(eOptimization, "specialAlgorithm");
				return true;
			}
			XmlElement eSpecialAlgorithm = (XmlElement)XMLUtil.findChildNode(eOptimization, "specialAlgorithm");
			if(eSpecialAlgorithm != null){
				XMLUtil.removeChildrenByName(eOptimization, "specialAlgorithm");
			}
			eSpecialAlgorithm = m_document.CreateElement("specialAlgorithm");
			XmlElement eDecomposition = m_document.CreateElement("decomposition");
			eDecomposition.AppendChild(m_document.CreateTextNode(specialAlgorithm.decomposition?"true":"false"));
			eSpecialAlgorithm.AppendChild(eDecomposition);
			XmlElement eGlobalOptimization = m_document.CreateElement("globalOptimization");
			eGlobalOptimization.AppendChild(m_document.CreateTextNode(specialAlgorithm.globalOptimization?"true":"false"));
			eSpecialAlgorithm.AppendChild(eGlobalOptimization);
			XmlElement eDynamicProgramming = m_document.CreateElement("dynamicProgramming");
			eDynamicProgramming.AppendChild(m_document.CreateTextNode(specialAlgorithm.dynamicProgramming?"true":"false"));
			eSpecialAlgorithm.AppendChild(eDynamicProgramming);
			XmlElement eHeuristic = m_document.CreateElement("heuristic");
			eHeuristic.AppendChild(m_document.CreateTextNode(specialAlgorithm.heuristic?"true":"false"));
			eSpecialAlgorithm.AppendChild(eHeuristic);
			eOptimization.AppendChild(eSpecialAlgorithm);
			return true;
		}//setOptimizationSpecialAlgorithm

		/// <summary>
		/// Set the other entity info related elements. 
		/// </summary>
		/// <param name="names">holds the names of the other entity info. It is required. </param>
		/// <param name="values">holds the values of the other entity info, empty string "" if no value for an entity info.</param>
		/// <param name="descriptions">holds the descriptions of other entity info, empty string "" if no value for an entity description, null for
		/// the entire array if none of the other entity info have descriptions.</param>
		/// <returns>whether the other entity info element construction is successful.</returns>
		public bool setOtherEntityInfo(string[] names, string[] values, string[] descriptions){
			if(names == null) return false;
			if(values == null) return false;
			if(names.Length != values.Length) return false;
			if(descriptions != null && names.Length != descriptions.Length) return false;
			for(int i = 0; i < names.Length; i++){
				addOtherEntityInfo(names[i], values[i], (descriptions==null)?"":descriptions[i]);
			}
			return true;
		}//setOtherEntityInfo


		/// <summary>
		/// Add an other entity info element. 
		/// </summary>
		/// <param name="name">holds the name of the other entity info element. It is required. </param>
		/// <param name="value">holds the value of the other entity info element, empty string "" if none. </param>
		/// <param name="description">holds the description of the other entity info element, empty string "" if none. </param>
		/// <returns>whether the other entity info element is added successfully.</returns>
		public bool addOtherEntityInfo(string name, string value, string description){
			if(name == null) return false;
			ArrayList vElements = XMLUtil.getChildElementsByTagName(m_eEntityData, "other");
			XmlElement eOther;
			for(int i = 0; i < vElements.Count; i++){
				eOther = (XmlElement)vElements[i];
				if(eOther.GetAttribute("name").Equals(name)){
					m_eEntityData.RemoveChild(eOther);
					break;
				}
			}
			eOther = createOther(name, value, description);
			m_eEntityData.AppendChild(eOther);
			return true;
		}//addOtherEntityInfo

		/// <summary>
		/// Create the OSeL root element and its most basic required structure.
		/// </summary>
		/// <returns>the OSeL element.</returns>
		protected XmlElement createOSeLRoot(){
			XmlElement eOSeL = XMLUtil.createOSxLRootElement(m_document, "osel");
			m_eEntityHeader = createEntityHeader();
			eOSeL.AppendChild(m_eEntityHeader);
			m_eEntityData = createEntityData();
			eOSeL.AppendChild(m_eEntityData);
			return eOSeL;
		}//createOSeLRoot

		/// <summary>
		/// Create the entityHeader element and its most basic required structure.
		/// </summary>
		/// <returns>the entityHeader element.</returns>
		protected XmlElement createEntityHeader(){
			XmlElement eEntityHeader = m_document.CreateElement("entityHeader");
			return eEntityHeader;
		}//createEntityHeader

		/// <summary>
		/// Create the entityData element and its most basic required structure.
		/// </summary>
		/// <returns>the entityData element.</returns>
		protected XmlElement createEntityData(){
			XmlElement eEntityData = m_document.CreateElement("entityData");
			return eEntityData;
		}//createEntityData


		/// <summary>
		/// Create the other element and its most basic required structure.
		/// </summary>
		/// <param name="name">the name of the other element. </param>
		/// <param name="value">the value of the other element, empty string "" if no value. </param>
		/// <param name="description">holds the description of the other entity info element, empty string "" if none. </param>
		/// <returns>the other element.</returns>
		protected XmlElement createOther(string name, string value, string description){
			XmlElement eOther = m_document.CreateElement("other");
			eOther.SetAttribute("name", name);
			eOther.SetAttribute("description", (description==null)?"":description);
			if(value != null && value.Length > 0){
				eOther.AppendChild(m_document.CreateTextNode(value));
			}
			return eOther;
		}//createOther
	}//class OSeLWriter
}//namespace
