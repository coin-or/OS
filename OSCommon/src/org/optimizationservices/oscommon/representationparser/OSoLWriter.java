/**
 * @(#)OSoLWriter 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.representationparser;

import java.util.GregorianCalendar;
import java.util.Vector;

import org.optimizationservices.oscommon.datastructure.osoption.PathPair;
import org.optimizationservices.oscommon.localinterface.OSOption;
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
		m_eOSoL = createOSoLRoot();
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
		if(!setSystemMinMemorySize(osOption.getSystemMinMemorySize())) throw new Exception("setSystemMinMemorySize Unsuccessful");		
		if(!setSystemMinCPUSpeed(osOption.getSystemMinCPUSpeed())) throw new Exception("setSystemMinCPUSpeed Unsuccessful");		
		if(!setServiceType(osOption.getServiceType())) throw new Exception("setServiceType Unsuccessful");		
		if(!setJobMaxTime(osOption.getJobMaxTime())) throw new Exception("setJobMaxTime Unsuccessful");		
		if(!setJobScheduledStartTime(osOption.getJobScheduledStartTime())) throw new Exception("setJobScheduledStartTime Unsuccessful");		
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

		if(!setVariableNumber(osOption.getVariableNumber())) throw new Exception("setVariableNumber Unsuccessful");		
		if(!setObjectiveNumber(osOption.getObjectiveNumber())) throw new Exception("setObjectiveNumber Unsuccessful");		
		if(!setConstraintNumber(osOption.getConstraintNumber())) throw new Exception("setConstraintNumber Unsuccessful");		
		if(!setInitialVariableValues(osOption.getInitialVariableValues())) throw new Exception("setInitialVariableValues Unsuccessful");		
		if(osOption.optimization != null && osOption.optimization.solverOptions != null && osOption.optimization.solverOptions != null && osOption.optimization.solverOptions.solverOption.length > 0){
			int n = osOption.optimization.solverOptions.solverOption.length;
			String[] msNames = new String[n];
			String[] msValues = new String[n];
			String[] msDescriptions = new String[n];
			for(int i = 0; i < n; i++){
				msNames[i] = osOption.optimization.solverOptions.solverOption[i].name;
				msValues[i] = osOption.optimization.solverOptions.solverOption[i].value;
				msDescriptions[i] = osOption.optimization.solverOptions.solverOption[i].description;
			}
			if(!setOtherOptimizationOptions(msNames, msValues, msDescriptions)){
				throw new Exception("setOtherOptimizationOption Info Unsuccessful");
			}			
		}
		if(osOption.other != null && osOption.other.length > 0){
			int n = osOption.other.length;
			String[] msNames = new String[n];
			String[] msValues = new String[n];
			String[] msDescriptions = new String[n];
			for(int i = 0; i < n; i++){
				msNames[i] = osOption.other[i].name;
				msValues[i] = osOption.other[i].value;
				msDescriptions[i] = osOption.other[i].description;
			}
			if(!setOtherOptions(msNames, msValues, msDescriptions)){
				throw new Exception("setOtherOption Info Unsuccessful");
			}			
		}
		return true;
	}//setOSOption


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
				eOther = createOther(name, value, description);
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
	}//addOtherOptimizationOption

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
	 * Set the the system minimum memory size required to solve the job.
	 * 
	 * @param minMemorySize holds the  minimum memory size required to solve the job. 
	 * @return whether the minimum memory size is set successfully.
	 */
	public boolean setSystemMinMemorySize(double minMemorySize){
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
	}//setSystemMinMemorySize


	/**
	 * Set the the system minimum cpu speed required to solve the job.
	 * 
	 * @param minCPUSpeed holds the  minimum cpu speed required to solve the job. 
	 * @return whether the minimum cpu speed is set successfully.
	 */
	public boolean setSystemMinCPUSpeed(double minCPUSpeed){
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
	}//setSystemMinCPUSpeed


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
	 * Set the maximum time before the job is terminated.  
	 * 
	 * @param maxTime holds the maximum time in seconds. 
	 * @return whether the maximum time is set successfully.
	 */
	public boolean setJobMaxTime(double maxTime){
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
	}//setJobMaxTime


	/**
	 * Set the scheduled start time for the job.   
	 * 
	 * @param scheduledStartTime holds the scheduled start time for the job.   
	 * @return whether the scheduled start time is set successfully.
	 */
	public boolean setJobScheduledStartTime(GregorianCalendar scheduledStartTime){
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
	}//setJobScheduledStartTime


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
	}//setRequiredFilesjob

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

	public boolean setInputDirectoriesToMove(PathPair[] pathPairs){
		return false;
	}
	public boolean setInputFilesToMove(PathPair[] pathPairs){
		return false;
	}
	public boolean setOutputDirectoriesToMove(PathPair[] pathPairs){
		return false;
	}
	public boolean setOutputFilesToMove(PathPair[] pathPairs){
		return false;
	}


	/**
	 * Set the input files to copy from before running the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of input files to copy from before running the job. 
	 * @return whether the input files to copy from are set successfully.
	 */
	public boolean setInputFilesToCopyFrom(String[] paths){
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
				Element eInputFilesToCopyFrom = (Element)XMLUtil.findChildNode(eJob, "inputFilesToCopyFrom");
				if(eInputFilesToCopyFrom == null){
					eInputFilesToCopyFrom = m_document.createElement("inputFilesToCopyFrom");	
					eJob.appendChild(eInputFilesToCopyFrom);									
				}
				XMLUtil.removeAllChildren(eInputFilesToCopyFrom);
				int iPaths = paths.length;
				for(int i = 0; i < iPaths; i++){
					if(paths[i] != null && paths[i].length() > 0){
						Element ePath = m_document.createElement("path");	
						ePath.appendChild(m_document.createTextNode(paths[i]));
						eInputFilesToCopyFrom.appendChild(ePath);				
					}
				}
			}
			else{
				XMLUtil.removeChildrenByName(eJob, "inputFilesToCopyFrom");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;

	}//setInputFilesToCopyFrom

	/**
	 * Set the input files to copy to before running the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of input files to copy to before running the job. 
	 * @return whether the input files to copy to are set successfully.
	 */
	public boolean setInputFilesToCopyTo(String[] paths){
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
				Element eInputFilesToCopyTo = (Element)XMLUtil.findChildNode(eJob, "inputFilesToCopyTo");
				if(eInputFilesToCopyTo == null){
					eInputFilesToCopyTo = m_document.createElement("inputFilesToCopyTo");	
					eJob.appendChild(eInputFilesToCopyTo);									
				}
				XMLUtil.removeAllChildren(eInputFilesToCopyTo);
				int iPaths = paths.length;
				for(int i = 0; i < iPaths; i++){
					if(paths[i] != null && paths[i].length() > 0){
						Element ePath = m_document.createElement("path");	
						ePath.appendChild(m_document.createTextNode(paths[i]));
						eInputFilesToCopyTo.appendChild(ePath);				
					}
				}
			}
			else{
				XMLUtil.removeChildrenByName(eJob, "inputFilesToCopyTo");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;

	}//setInputFilesToCopyTo

	/**
	 * Set the input files to move from before running the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of input files to move from before running the job. 
	 * @return whether the input files to move from are set successfully.
	 */
	public boolean setInputFilesToMoveFrom(String[] paths){
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
				Element eInputFilesToMoveFrom = (Element)XMLUtil.findChildNode(eJob, "inputFilesToMoveFrom");
				if(eInputFilesToMoveFrom == null){
					eInputFilesToMoveFrom = m_document.createElement("inputFilesToMoveFrom");	
					eJob.appendChild(eInputFilesToMoveFrom);									
				}
				XMLUtil.removeAllChildren(eInputFilesToMoveFrom);
				int iPaths = paths.length;
				for(int i = 0; i < iPaths; i++){
					if(paths[i] != null && paths[i].length() > 0){
						Element ePath = m_document.createElement("path");	
						ePath.appendChild(m_document.createTextNode(paths[i]));
						eInputFilesToMoveFrom.appendChild(ePath);				
					}
				}
			}
			else{
				XMLUtil.removeChildrenByName(eJob, "inputFilesToMoveFrom");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;

	}//setInputFilesToMoveFrom

	/**
	 * Set the input files to move to before running the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of input files to move to before running the job. 
	 * @return whether the input files to move to are set successfully.
	 */
	public boolean setInputFilesToMoveTo(String[] paths){
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
				Element eInputFilesToMoveTo = (Element)XMLUtil.findChildNode(eJob, "inputFilesToMoveTo");
				if(eInputFilesToMoveTo == null){
					eInputFilesToMoveTo = m_document.createElement("inputFilesToMoveTo");	
					eJob.appendChild(eInputFilesToMoveTo);									
				}
				XMLUtil.removeAllChildren(eInputFilesToMoveTo);
				int iPaths = paths.length;
				for(int i = 0; i < iPaths; i++){
					if(paths[i] != null && paths[i].length() > 0){
						Element ePath = m_document.createElement("path");	
						ePath.appendChild(m_document.createTextNode(paths[i]));
						eInputFilesToMoveTo.appendChild(ePath);				
					}
				}
			}
			else{
				XMLUtil.removeChildrenByName(eJob, "inputFilesToMoveTo");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;

	}//setInputFilesToMoveTo

	/**
	 * Set the output files to copy from before running the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of output files to copy from before running the job. 
	 * @return whether the output files to copy from are set successfully.
	 */
	public boolean setOutputFilesToCopyFrom(String[] paths){
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
				Element eOutputFilesToCopyFrom = (Element)XMLUtil.findChildNode(eJob, "outputFilesToCopyFrom");
				if(eOutputFilesToCopyFrom == null){
					eOutputFilesToCopyFrom = m_document.createElement("outputFilesToCopyFrom");	
					eJob.appendChild(eOutputFilesToCopyFrom);									
				}
				XMLUtil.removeAllChildren(eOutputFilesToCopyFrom);
				int iPaths = paths.length;
				for(int i = 0; i < iPaths; i++){
					if(paths[i] != null && paths[i].length() > 0){
						Element ePath = m_document.createElement("path");	
						ePath.appendChild(m_document.createTextNode(paths[i]));
						eOutputFilesToCopyFrom.appendChild(ePath);				
					}
				}
			}
			else{
				XMLUtil.removeChildrenByName(eJob, "outputFilesToCopyFrom");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;

	}//setOutputFilesToCopyFrom

	/**
	 * Set the output files to copy to before running the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of output files to copy to before running the job. 
	 * @return whether the output files to copy to are set successfully.
	 */
	public boolean setOutputFilesToCopyTo(String[] paths){
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
				Element eOutputFilesToCopyTo = (Element)XMLUtil.findChildNode(eJob, "outputFilesToCopyTo");
				if(eOutputFilesToCopyTo == null){
					eOutputFilesToCopyTo = m_document.createElement("outputFilesToCopyTo");	
					eJob.appendChild(eOutputFilesToCopyTo);									
				}
				XMLUtil.removeAllChildren(eOutputFilesToCopyTo);
				int iPaths = paths.length;
				for(int i = 0; i < iPaths; i++){
					if(paths[i] != null && paths[i].length() > 0){
						Element ePath = m_document.createElement("path");	
						ePath.appendChild(m_document.createTextNode(paths[i]));
						eOutputFilesToCopyTo.appendChild(ePath);				
					}
				}
			}
			else{
				XMLUtil.removeChildrenByName(eJob, "outputFilesToCopyTo");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;

	}//setOutputFilesToCopyTo

	/**
	 * Set the output files to move from before running the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of output files to move from before running the job. 
	 * @return whether the output files to move from are set successfully.
	 */
	public boolean setOutputFilesToMoveFrom(String[] paths){
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
				Element eOutputFilesToMoveFrom = (Element)XMLUtil.findChildNode(eJob, "outputFilesToMoveFrom");
				if(eOutputFilesToMoveFrom == null){
					eOutputFilesToMoveFrom = m_document.createElement("outputFilesToMoveFrom");	
					eJob.appendChild(eOutputFilesToMoveFrom);									
				}
				XMLUtil.removeAllChildren(eOutputFilesToMoveFrom);
				int iPaths = paths.length;
				for(int i = 0; i < iPaths; i++){
					if(paths[i] != null && paths[i].length() > 0){
						Element ePath = m_document.createElement("path");	
						ePath.appendChild(m_document.createTextNode(paths[i]));
						eOutputFilesToMoveFrom.appendChild(ePath);				
					}
				}
			}
			else{
				XMLUtil.removeChildrenByName(eJob, "outputFilesToMoveFrom");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;

	}//setOutputFilesToMoveFrom

	/**
	 * Set the output files to move to before running the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of output files to move to before running the job. 
	 * @return whether the output files to move to are set successfully.
	 */
	public boolean setOutputFilesToMoveTo(String[] paths){
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
				Element eOutputFilesToMoveTo = (Element)XMLUtil.findChildNode(eJob, "outputFilesToMoveTo");
				if(eOutputFilesToMoveTo == null){
					eOutputFilesToMoveTo = m_document.createElement("outputFilesToMoveTo");	
					eJob.appendChild(eOutputFilesToMoveTo);									
				}
				XMLUtil.removeAllChildren(eOutputFilesToMoveTo);
				int iPaths = paths.length;
				for(int i = 0; i < iPaths; i++){
					if(paths[i] != null && paths[i].length() > 0){
						Element ePath = m_document.createElement("path");	
						ePath.appendChild(m_document.createTextNode(paths[i]));
						eOutputFilesToMoveTo.appendChild(ePath);				
					}
				}
			}
			else{
				XMLUtil.removeChildrenByName(eJob, "outputFilesToMoveTo");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;

	}//setOutputFilesToMoveTo

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
	 * Set the variable number. 
	 * 
	 * @param variableNumber holds the number of variables
	 * @return whether the variable number is set successfully or not. 
	 */
	public boolean setVariableNumber(int variableNumber){
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
	}//setVariableNumber

	/**
	 * Set the objective number. 
	 * 
	 * @param objectiveNumber holds the number of objectives
	 * @return whether the objective number is set successfully or not. 
	 */
	public boolean setObjectiveNumber(int objectiveNumber){
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
	}//setObjectiveNumber

	/**
	 * Set the constraint number. 
	 * 
	 * @param constraintNumber holds the number of constraints
	 * @return whether the constraint number is set successfully or not. 
	 */
	public boolean setConstraintNumber(int constraintNumber){
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
	}//setConstraintNumber

	/**
	 * Set initial variable values (double[]). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods are recommended  to be called first. 
	 * @param initialVariableValues holds a double array of initial variable values. 
	 * @return whether the initial variable values are set successfully or not. 
	 */
	public boolean setInitialVariableValues(double[] initialVariableValues){
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
			for(int i = 0; i < iVars; i++){
				Element eVar = m_document.createElement("var");	
				eVar.setAttribute("idx", i+"");
				eVar.setAttribute("value", initialVariableValues[i]+"");
				eInitialVariableValues.appendChild(eVar);				
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setInitialVariableValues

	/**
	 * Set the other optimization options related elements. 
	 * 
	 * @param names holds the names of the other optimization options. It is required. 
	 * @param values holds the values of the other optimization options, empty string "" or null if no value for an option.
	 * @param descriptions holds the descriptions of the other optimization options, empty string "" or null if no value for an option, null for
	 * the entire array if none of the options have descriptions.
	 * @return whether the other optimization options element construction is successful.
	 */
	public boolean setOtherOptimizationOptions(String[] names, String[] values, String[] descriptions){
		if(names == null) return false;
		if(values == null) return false;
		if(names.length != values.length) return false;
		if(descriptions != null && names.length != descriptions.length) return false;
		for(int i = 0; i < names.length; i++){
			addOtherOptimizationOption(names[i], values[i], (descriptions==null)?"":descriptions[i]);
		}
		return true;
	}//setOtherOptimizationOptions

	/**
	 * Add an other optimization option element. 
	 * 
	 * @param name holds the name of the other optimization option element. It is required.
	 * @param value holds the value of the other optimization option element, empty string "" or null if none. 
	 * @param description holds the description of the other optimization option element, empty string "" or null if none. 
	 * @return whether the other optimization option element is added successfully.
	 */
	public boolean addOtherOptimizationOption(String name, String value, String description){
		if(name == null || name.trim().length() <= 0) return false;
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
			Vector<Element> vElements = XMLUtil.getChildElementsByTagName(eOptimization, "other");
			Element eOther;
			int iNls = vElements==null?0:vElements.size();
			for(int i = 0; i < iNls; i++){
				eOther = (Element)vElements.elementAt(i);
				if(eOther.getAttribute("name").equals(name)){
					eOptimization.removeChild(eOther);
					break;
				}
			}
			eOther = createOther(name, value, description);
			eOptimization.appendChild(eOther);
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//addOtherOptimizationOption

	/**
	 * Set the other options related elements. 
	 * 
	 * @param names holds the names of the other options. It is required. 
	 * @param values holds the values of the other options, empty string "" or null if no value for an option.
	 * @param descriptions holds the descriptions of the other options, empty string "" or null if no value for an option, null for
	 * the entire array if none of the options have descriptions.
	 * @return whether the other options element construction is successful.
	 */
	public boolean setOtherOptions(String[] names, String[] values, String[] descriptions){
		if(names == null) return false;
		if(values == null) return false;
		if(names.length != values.length) return false;
		if(descriptions != null && names.length != descriptions.length) return false;
		for(int i = 0; i < names.length; i++){
			addOtherOption(names[i], values[i], (descriptions==null)?"":descriptions[i]);
		}
		return true;
	}//setOtherOptions

	/**
	 * Add an other option element. 
	 * 
	 * @param name holds the name of the other option element. It is required.
	 * @param value holds the value of the other option element, empty string "" or null if none. 
	 * @param description holds the description of the other option element, empty string "" or null if none. 
	 * @return whether the other option element is added successfully.
	 */
	public boolean addOtherOption(String name, String value, String description){
		if(name == null || name.trim().length() <= 0) return false;

		Vector<Element> vElements = XMLUtil.getChildElementsByTagName(m_eOSoL, "other");
		Element eOther;
		int iNls = vElements==null?0:vElements.size();
		for(int i = 0; i < iNls; i++){
			eOther = (Element)vElements.elementAt(i);
			if(eOther.getAttribute("name").equals(name)){
				m_eOSoL.removeChild(eOther);
				break;
			}
		}
		eOther = createOther(name, value, description);
		m_eOSoL.appendChild(eOther);
		return true;
	}//addOtherOption


	/**
	 * Create the OSoL root element and its most basic required structure.
	 * 
	 * @return the OSoL element.
	 */
	protected Element createOSoLRoot(){
		Element eOSoL = XMLUtil.createOSxLRootElement(m_document, "osol");
		return eOSoL;
	}//createOSoLRoot

	/**
	 * Create the other element and its most basic required structure.
	 * 
	 * @param name the name of the other element. 
	 * @param value the value of the other element, empty string "" or null if no value. 
	 * @param description holds the description of the other option element, empty string "" or null if none. 
	 * @return the other element.
	 */
	protected Element createOther(String name, String value, String description){
		Element eOther = m_document.createElement("other");
		eOther.setAttribute("name", name);
		if(value != null && value.length() > 0){
			eOther.setAttribute("value", value);
		}
		if(description != null && description.length() > 0){
			eOther.setAttribute("description", description);
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
		if(!osolWriter.setContact("contactAddress")) System.out.println("setContactAddress Unsuccessful");		
		if(!osolWriter.setNumberOfOtherGeneralOptions(0)) System.out.println("setNumberOfOtherGeneralOptions");		
		if(!osolWriter.addOtherGeneralOption("gname0", null, "")) System.out.println("addOtherGeneralOption");		
		String[] msNames = {"gname1", "gname2"};
		String[] msValues = {"gvalue1", "gvalue2"};
		String[] msDescs = {"gdesc1", "gdesc2"};
		if(!osolWriter.setOtherGeneralOptions(msNames, msValues, msDescs)) System.out.println("setOtherGeneralOptions");		
		if(!osolWriter.setOtherGeneralOptions(msNames, msValues, null)) System.out.println("setOtherGeneralOptions");		
		if(!osolWriter.addOtherGeneralOption("gname1", null, "")) System.out.println("addOtherGeneralOption");		
		
		if(!osolWriter.setMinDiskSpace(10)) System.out.println("setMinDiskSpace Unsuccessful");		
//		if(!osolWriter.setSystemMinMemorySize(20)) System.out.println("setSystemMinMemorySize Unsuccessful");		
//		if(!osolWriter.setSystemMinCPUSpeed(30)) System.out.println("setSystemMinCPUSpeed Unsuccessful");		
//		if(!osolWriter.setServiceType("solver")) System.out.println("setServiceType Unsuccessful");		
//		if(!osolWriter.setJobMaxTime(9999)) System.out.println("setJobMaxTime Unsuccessful");		
//		if(!osolWriter.setJobScheduledStartTime(new GregorianCalendar(1970, 0, 1, 0, 0, 0))) System.out.println("setJobScheduledStartTime Unsuccessful");		
//		String[] jobDependencies = {"a1", "b3"};
//		if(!osolWriter.setJobDependencies(jobDependencies)) System.out.println("setJobDependencies Unsuccessful");		
//		String[] paths = {"p1", "p3"};
//		if(!osolWriter.setRequiredDirectories(paths)) System.out.println("setRequiredDirectories Unsuccessful");		
//		if(!osolWriter.setRequiredFiles(paths)) System.out.println("setRequiredFiles Unsuccessful");		
//		if(!osolWriter.setVariableNumber(3)) System.out.println("setVariableNumber Unsuccessful");		
//		if(!osolWriter.setObjectiveNumber(3)) System.out.println("setObjectiveNumber Unsuccessful");		
//		if(!osolWriter.setConstraintNumber(2)) System.out.println("setConstraintNumber Unsuccessful");		
//		double[] initialVariableValues = {1, 2, 3};
//		if(!osolWriter.setInitialVariableValues(initialVariableValues)) System.out.println("setInitialVariableValues Unsuccessful");		



//		String[] msOtherOptionNames = {"other name 0", "other name 1"};
//		String[] msOtherOptionValues = {"other value 0", "other value 1"};
//		if(!osolWriter.setOtherOptions(msOtherOptionNames, msOtherOptionValues, null)) System.out.println("set other!");

//		if(!osolWriter.addOtherOption("other name 2", "other value 2", null)) System.out.println("add other!");
//		if(!osolWriter.addOtherOption("other name 3", "other value 3", "other description 3")) System.out.println("add other!");

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

		//osolWriter.writeToStandardOutput();
		System.out.println(osolWriter.writeToString());
	}//main

}//class OSoLWriter
