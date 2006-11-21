using System;
using System.Xml;
using System.Collections;

using org.optimizationservices.oscommon.util;
using org.optimizationservices.oscommon.localinterface;
using org.optimizationservices.oscommon.datastructure.osoption;

namespace org.optimizationservices.oscommon.representationparser{
	/// <summary>
	/// The <c>OSoLWriter</c> class is used to construct an instance that follows 
	/// the OSoL format. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OSoLWriter : OSgLWriter{
		/// <summary>
		/// m_eOSoL holds the OSoL root element.
		/// </summary>
		protected internal XmlElement m_eOSoL = null;
			
		/// <summary>
		/// constructor. 
		/// </summary>
		public OSoLWriter(){
			m_document = XMLUtil.createNewDocument();
			if(OSParameter.XSLT_LOCATION != null && OSParameter.XSLT_LOCATION.Length > 0){
				XmlProcessingInstruction xsltPI = m_document.CreateProcessingInstruction("xml-stylesheet",
					"type=\"text/xsl\" href = \"" + OSParameter.XSLT_LOCATION + "OSoL.xslt\"");
				m_document.AppendChild(xsltPI);     
			}
			m_eOSoL = createOSoLRoot();
			m_document.AppendChild(m_eOSoL);
		}//constructor

		/// <summary>
		/// set the OSOption, a standard os option interface. 
		/// </summary>
		/// <param name="osOption">holds the standard os option interface. </param>
		/// <returns>whether the OSOption is set successfully. </returns>
		public bool setOSOption(OSOption osOption){
			if(!setServiceURI(osOption.getServiceURI())){ 
				throw new Exception("setServiceURI Unsuccessful");
			}
			if(!setServiceName(osOption.getServiceName())) throw new Exception("setServiceName Unsuccessful");		
			if(!setInstanceName(osOption.getInstanceName())) throw new Exception("setInstanceName Unsuccessful");		
			if(!setInstanceAddress(osOption.getInstanceAddress())) throw new Exception("setInstanceAddress Unsuccessful");		
			if(!setInstanceLocationType(osOption.getInstanceLocationType())) throw new Exception("setInstanceLocationType Unsuccessful");		
			if(!setJobID(osOption.getJobID())) throw new Exception("setJobID Unsuccessful");		
			if(!setLicense(osOption.getLicense())) throw new Exception("setLicense Unsuccessful");		
			if(!setUserName(osOption.getUserName())) throw new Exception("setUserName Unsuccessful");		
			if(!setPassword(osOption.getPassword())) throw new Exception("setPassword Unsuccessful");		
			if(!setContactTransportType(osOption.getContactTransportType())) throw new Exception("setContactTransportType Unsuccessful");		
			if(!setContactAddress(osOption.getContactAddress())) throw new Exception("setContactAddress Unsuccessful");		
			if(!setSystemMinDiskSpace(osOption.getSystemMinDiskSpace())) throw new Exception("setSystemMinDiskSpace Unsuccessful");		
			if(!setSystemMinMemorySize(osOption.getSystemMinMemorySize())) throw new Exception("setSystemMinMemorySize Unsuccessful");		
			if(!setSystemMinCPUSpeed(osOption.getSystemMinCPUSpeed())) throw new Exception("setSystemMinCPUSpeed Unsuccessful");		
			if(!setServiceType(osOption.getServiceType())) throw new Exception("setServiceType Unsuccessful");		
			if(!setJobMaxTime(osOption.getJobMaxTime())) throw new Exception("setJobMaxTime Unsuccessful");		
			if(!setJobScheduledStartTime(osOption.getJobScheduledStartTime())) throw new Exception("setJobScheduledStartTime Unsuccessful");		
			if(!setJobDependencies(osOption.getJobDependencies())) throw new Exception("setJobDependencies Unsuccessful");		
			if(!setRequiredDirectoriesAndFiles(osOption.getRequiredDirectoriesAndFiles())) throw new Exception("setRequiredDirectoriesAndFiles Unsuccessful");		
			if(!setDirectoriesToMake(osOption.getDirectoriesToMake())) throw new Exception("setDirectoriesToMake Unsuccessful");		
			if(!setFilesToCreate(osOption.getFilesToCreate())) throw new Exception("setFilesToCreate Unsuccessful");		
			if(!setInputFilesToCopyFrom(osOption.getInputFilesToCopyFrom())) throw new Exception("setInputFilesToCopyFrom Unsuccessful");		
			if(!setInputFilesToCopyTo(osOption.getInputFilesToCopyTo())) throw new Exception("setInputFilesToCopyTo Unsuccessful");		
			if(!setInputFilesToMoveFrom(osOption.getInputFilesToMoveFrom())) throw new Exception("setInputFilesToMoveFrom Unsuccessful");		
			if(!setInputFilesToMoveTo(osOption.getInputFilesToMoveTo())) throw new Exception("setInputFilesToMoveTo Unsuccessful");		
			if(!setOutputFilesToCopyFrom(osOption.getOutputFilesToCopyFrom())) throw new Exception("setOutputFilesToCopyFrom Unsuccessful");		
			if(!setOutputFilesToCopyTo(osOption.getOutputFilesToCopyTo())) throw new Exception("setOutputFilesToCopyTo Unsuccessful");		
			if(!setOutputFilesToMoveFrom(osOption.getOutputFilesToMoveFrom())) throw new Exception("setOutputFilesToMoveFrom Unsuccessful");		
			if(!setOutputFilesToMoveTo(osOption.getOutputFilesToMoveTo())) throw new Exception("setOutputFilesToMoveTo Unsuccessful");		
			if(!setFilesToDelete(osOption.getFilesToDelete())) throw new Exception("setFilesToDelete Unsuccessful");		
			if(!setDirectoriesToDelete(osOption.getDirectoriesToDelete())) throw new Exception("setDirectoriesToDelete Unsuccessful");		
			if(!setProcessesToKill(osOption.getProcessesToKill())) throw new Exception("setProcessesToKill Unsuccessful");		

			if(!setVariableNumber(osOption.getVariableNumber())) throw new Exception("setVariableNumber Unsuccessful");		
			if(!setObjectiveNumber(osOption.getObjectiveNumber())) throw new Exception("setObjectiveNumber Unsuccessful");		
			if(!setConstraintNumber(osOption.getConstraintNumber())) throw new Exception("setConstraintNumber Unsuccessful");		
			if(!setInitialVariableValues(osOption.getInitialVariableValues())) throw new Exception("setInitialVariableValues Unsuccessful");		
			if(osOption.other != null && osOption.other.Length > 0){
				int n = osOption.other.Length;
				string[] msNames = new string[n];
				string[] msValues = new string[n];
				string[] msDescriptions = new string[n];
				for(int i = 0; i < n; i++){
					msNames[i] = osOption.other[i].name;
					msValues[i] = osOption.other[i].value;
					msDescriptions[i] = osOption.other[i].description;
				}
				if(!setOtherOptions(msNames, msValues, msDescriptions)){
					throw new Exception("setOtherEntity Info Unsuccessful");
				}			
			}
			return true;
		}//setOSOption


		/// <summary>
		/// Set service uri.
		/// </summary>
		/// <param name="serviceURI">holds the uri of the service. </param>
		/// <returns>whether the service uri is set successfully. </returns>
		public bool setServiceURI(string serviceURI){
			try{
				XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "general");
				if(eGeneral == null){
					eGeneral = m_document.CreateElement("general");
					m_eOSoL.InsertBefore(eGeneral, m_eOSoL.FirstChild);
				}
				if(serviceURI != null && serviceURI.Length > 0){
					XmlElement eServiceURI = (XmlElement)XMLUtil.findChildNode(eGeneral, "serviceURI");
					if(eServiceURI == null){
						eServiceURI = m_document.CreateElement("serviceURI");	
						eServiceURI.AppendChild(m_document.CreateTextNode(serviceURI));
						eGeneral.AppendChild(eServiceURI);				
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
				XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "general");
				if(eGeneral == null){
					eGeneral = m_document.CreateElement("general");
					m_eOSoL.InsertBefore(eGeneral, m_eOSoL.FirstChild);
				}
				if(serviceName != null && serviceName.Length > 0){
					XmlElement eServiceName = (XmlElement)XMLUtil.findChildNode(eGeneral, "serviceName");
					if(eServiceName == null){
						eServiceName = m_document.CreateElement("serviceName");	
						eServiceName.AppendChild(m_document.CreateTextNode(serviceName));
						eGeneral.AppendChild(eServiceName);				
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
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setServiceName

		/// <summary>
		/// Set instance name.
		/// </summary>
		/// <param name="instanceName">holds the name of the instance. </param>
		/// <returns>whether the instance name is set successfully. </returns>
		public bool setInstanceName(string instanceName){
			try{
				XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "general");
				if(eGeneral == null){
					eGeneral = m_document.CreateElement("general");
					m_eOSoL.InsertBefore(eGeneral, m_eOSoL.FirstChild);
				}
				if(instanceName != null && instanceName.Length > 0){
					XmlElement eInstanceName = (XmlElement)XMLUtil.findChildNode(eGeneral, "instanceName");
					if(eInstanceName == null){
						eInstanceName = m_document.CreateElement("instanceName");	
						eInstanceName.AppendChild(m_document.CreateTextNode(instanceName));
						eGeneral.AppendChild(eInstanceName);				
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
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setInstanceName

		/// <summary>
		/// Set the instance location type to get the instance. 
		/// </summary>
		/// <param name="locationType">holds the instance location type, e.g. local, http, ftp.</param>
		/// <returns>whether the instance location type is set successfully.</returns>
		public bool setInstanceLocationType(string locationType){
			try{
				XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "general");
				if(eGeneral == null){
					eGeneral = m_document.CreateElement("general");
					m_eOSoL.InsertBefore(eGeneral, m_eOSoL.FirstChild);
				}
				XmlElement eInstanceLocation = (XmlElement)XMLUtil.findChildNode(eGeneral, "instanceLocation");
				if(locationType == null || locationType.Length <= 0){
					if(eInstanceLocation == null){
						return true;
					}
					else{
						eInstanceLocation.RemoveAttribute("locationType");
						return true;
					}
				}
				if(eInstanceLocation == null){
					eInstanceLocation = m_document.CreateElement("instanceLocation");	
					eInstanceLocation.SetAttribute("locationType", locationType);
					eGeneral.AppendChild(eInstanceLocation);
				}
				else{
					eInstanceLocation.SetAttribute("locationType", locationType);
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setInstanceLocationType
	
		/// <summary>
		/// Set the instance address to get the instance.  
		/// </summary>
		/// <param name="address">holds the instance address. </param>
		/// <returns>whether the instance address is set successfully.</returns>
		public bool setInstanceAddress(string address){
			try{
				XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "general");
				if(eGeneral == null){
					eGeneral = m_document.CreateElement("general");
					m_eOSoL.InsertBefore(eGeneral, m_eOSoL.FirstChild);
				}
				XmlElement eInstanceLocation = (XmlElement)XMLUtil.findChildNode(eGeneral, "instanceLocation");
				if(address == null || address.Length <= 0){
					if(eInstanceLocation == null){
						return true;
					}
					else{
						XMLUtil.removeAllChildren(eInstanceLocation);
						return true;
					}
				}
				if(eInstanceLocation == null){
					eInstanceLocation = m_document.CreateElement("instanceLocation");	
					eInstanceLocation.AppendChild(m_document.CreateTextNode(address));
					eGeneral.AppendChild(eInstanceLocation);				
				}
				else{
					XMLUtil.setElementValue(eInstanceLocation, address);
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setInstanceAddress

		/// <summary>
		/// Set jobID. 
		/// </summary>
		/// <param name="jobID">holds the jobID.</param>
		/// <returns>whether the jobID is set successfully.</returns>
		public bool setJobID(string jobID){
			try{
				XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "general");
				if(eGeneral == null){
					eGeneral = m_document.CreateElement("general");
					m_eOSoL.InsertBefore(eGeneral, m_eOSoL.FirstChild);
				}
				if(jobID != null && jobID.Length > 0){
					XmlElement eJobID = (XmlElement)XMLUtil.findChildNode(eGeneral, "jobID");
					if(eJobID == null){
						eJobID = m_document.CreateElement("jobID");	
						eJobID.AppendChild(m_document.CreateTextNode(jobID));
						eGeneral.AppendChild(eJobID);				
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
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setJobID

		/// <summary>
		/// Set license.
		/// </summary>
		/// <param name="license">holds the license required by the service.</param>
		/// <returns>whether the license is set successfully.</returns>
		public bool setLicense(string license){
			try{
				XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "general");
				if(eGeneral == null){
					eGeneral = m_document.CreateElement("general");
					m_eOSoL.InsertBefore(eGeneral, m_eOSoL.FirstChild);
				}
				if(license != null && license.Length > 0){
					XmlElement eLicense = (XmlElement)XMLUtil.findChildNode(eGeneral, "license");
					if(eLicense == null){
						eLicense = m_document.CreateElement("license");	
						eLicense.AppendChild(m_document.CreateTextNode(license));
						eGeneral.AppendChild(eLicense);				
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
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setLicense

		/// <summary>
		/// Set the user name.
		/// </summary>
		/// <param name="userName">holds the user name required by the service.</param>
		/// <returns>whether the user name is set successfully.</returns>
		public bool setUserName(string userName){
			try{
				XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "general");
				if(eGeneral == null){
					eGeneral = m_document.CreateElement("general");
					m_eOSoL.InsertBefore(eGeneral, m_eOSoL.FirstChild);
				}
				if(userName != null && userName.Length > 0){
					XmlElement eUserName = (XmlElement)XMLUtil.findChildNode(eGeneral, "userName");
					if(eUserName == null){
						eUserName = m_document.CreateElement("userName");	
						eUserName.AppendChild(m_document.CreateTextNode(userName));
						eGeneral.AppendChild(eUserName);				
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
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setUserName

		/// <summary>
		/// Set the password.
		/// </summary>
		/// <param name="password">holds the password required by the service.</param>
		/// <returns>whether the password is set successfully.</returns>
		public bool setPassword(string password){
			try{
				XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "general");
				if(eGeneral == null){
					eGeneral = m_document.CreateElement("general");
					m_eOSoL.InsertBefore(eGeneral, m_eOSoL.FirstChild);
				}
				if(password != null && password.Length > 0){
					XmlElement ePassword = (XmlElement)XMLUtil.findChildNode(eGeneral, "password");
					if(ePassword == null){
						ePassword = m_document.CreateElement("password");	
						ePassword.AppendChild(m_document.CreateTextNode(password));
						eGeneral.AppendChild(ePassword);				
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
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setPassword


		/// <summary>
		/// Set the contact transport type to respond to the requester,
		/// smtp (for email), osp (for knocking back on the requester), etc.
		/// </summary>
		/// <param name="transportType">holds the contact transport type. </param>
		/// <returns>whether the contact transport type is set successfully.</returns>
		public bool setContactTransportType(string transportType){
			try{
				XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "general");
				if(eGeneral == null){
					eGeneral = m_document.CreateElement("general");
					m_eOSoL.InsertBefore(eGeneral, m_eOSoL.FirstChild);
				}
				XmlElement eContact = (XmlElement)XMLUtil.findChildNode(eGeneral, "contact");
				if(transportType == null || transportType.Length <= 0){
					if(eContact == null){
						return true;
					}
					else{
						eContact.RemoveAttribute("transportType");
						return true;
					}
				}
				if(eContact == null){
					eContact = m_document.CreateElement("contact");	
					eContact.SetAttribute("transportType", transportType);
					eGeneral.AppendChild(eContact);				
				}
				else{
					eContact.SetAttribute("transportType", transportType);
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setContactTransportType
	
		/// <summary>
		/// Set the contact address to respond to the requester. 
		/// For example it can be an email address if the contact transport type is smtp
		/// or a http uri if the contact transport type is osp (for knocking back on the requester), etc.
		/// </summary>
		/// <param name="address">holds the contact address. </param>
		/// <returns>whether the contact address is set successfully.</returns>
		public bool setContactAddress(string address){
			try{
				XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "general");
				if(eGeneral == null){
					eGeneral = m_document.CreateElement("general");
					m_eOSoL.InsertBefore(eGeneral, m_eOSoL.FirstChild);
				}
				XmlElement eContact = (XmlElement)XMLUtil.findChildNode(eGeneral, "contact");
				if(address == null || address.Length <= 0){
					if(eContact == null){
						return true;
					}
					else{
						XMLUtil.removeAllChildren(eContact);
						return true;
					}
				}
				if(eContact == null){
					eContact = m_document.CreateElement("contact");	
					eContact.AppendChild(m_document.CreateTextNode(address));
					eGeneral.AppendChild(eContact);				
				}
				else{
					XMLUtil.setElementValue(eContact, address);
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setContactAddress
		
	

		/// <summary>
		/// Set the the system minimum disk space required to solve the job.
		/// </summary>
		/// <param name="minDiskSpace">holds the  minimum disk space required to solve the job. </param>
		/// <returns>whether the minimum disk space is set successfully.</returns>
		public bool setSystemMinDiskSpace(double minDiskSpace){
			XmlNode nodeRef = null;
			try{
				XmlElement eSystem = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "system");
				if(eSystem == null){
					eSystem = m_document.CreateElement("system");
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
					if(nodeRef != null){
						m_eOSoL.InsertBefore(eSystem, nodeRef.NextSibling);			
					}
					else{
						m_eOSoL.InsertBefore(eSystem, m_eOSoL.FirstChild);
					}		
				}
				if(minDiskSpace >= 0){
					XmlElement eMinDiskSpace = (XmlElement)XMLUtil.findChildNode(eSystem, "minDiskSpace");
					if(eMinDiskSpace == null){
						eMinDiskSpace = m_document.CreateElement("minDiskSpace");	
						eMinDiskSpace.AppendChild(m_document.CreateTextNode(minDiskSpace+""));
						eSystem.AppendChild(eMinDiskSpace);				
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
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setSystemMinDiskSpace

		/// <summary>
		/// Set the the system minimum memory size required to solve the job.
		/// </summary>
		/// <param name="minMemorySize">holds the  minimum memory size required to solve the job. </param>
		/// <returns>whether the minimum memory size is set successfully.</returns>
		public bool setSystemMinMemorySize(double minMemorySize){
			XmlNode nodeRef = null;
			try{
				XmlElement eSystem = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "system");
				if(eSystem == null){
					eSystem = m_document.CreateElement("system");
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
					if(nodeRef != null){
						m_eOSoL.InsertBefore(eSystem, nodeRef.NextSibling);			
					}
					else{
						m_eOSoL.InsertBefore(eSystem, m_eOSoL.FirstChild);
					}		
				}
				if(minMemorySize >= 0){
					XmlElement eMinMemorySize = (XmlElement)XMLUtil.findChildNode(eSystem, "minMemorySize");
					if(eMinMemorySize == null){
						eMinMemorySize = m_document.CreateElement("minMemorySize");	
						eMinMemorySize.AppendChild(m_document.CreateTextNode(minMemorySize+""));
						eSystem.AppendChild(eMinMemorySize);				
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
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setSystemMinMemorySize

		/// <summary>
		/// Set the the system minimum cpu speed required to solve the job.
		/// </summary>
		/// <param name="minCPUSpeed">holds the  minimum cpu speed required to solve the job. </param>
		/// <returns>whether the minimum cpu speed is set successfully.</returns>
		public bool setSystemMinCPUSpeed(double minCPUSpeed){
			XmlNode nodeRef = null;
			try{
				XmlElement eSystem = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "system");
				if(eSystem == null){
					eSystem = m_document.CreateElement("system");
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
					if(nodeRef != null){
						m_eOSoL.InsertBefore(eSystem, nodeRef.NextSibling);			
					}
					else{
						m_eOSoL.InsertBefore(eSystem, m_eOSoL.FirstChild);
					}		
				}
				if(minCPUSpeed >= 0){
					XmlElement eMinCPUSpeed = (XmlElement)XMLUtil.findChildNode(eSystem, "minCPUSpeed");
					if(eMinCPUSpeed == null){
						eMinCPUSpeed = m_document.CreateElement("minCPUSpeed");	
						eMinCPUSpeed.AppendChild(m_document.CreateTextNode(minCPUSpeed+""));
						eSystem.AppendChild(eMinCPUSpeed);				
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
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setSystemMinCPUSpeed

		/// <summary>
		/// Set the service type. 
		/// </summary>
		/// <param name="type">holds the service type, which can be:
		/// solver, analyzer, scheduler, simulation, registry, modeler, agent 
		/// </param>
		/// <returns>whether the service type is set successfully or not. </returns>
		public bool setServiceType(string type){
			XmlNode nodeRef = null;
			try{
				XmlElement eService = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "service");
				if(eService == null){
					eService = m_document.CreateElement("service");
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
					if(nodeRef != null){
						m_eOSoL.InsertBefore(eService, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
						if(nodeRef != null){
							m_eOSoL.InsertBefore(eService, nodeRef.NextSibling);			
						}
						else{
							m_eOSoL.InsertBefore(eService, m_eOSoL.FirstChild);
						}		
					}		
				}
				if(type != null && type.Length > 0){
					if(!type.Equals("solver") && 
						!type.Equals("analyzer") &&
						!type.Equals("scheduler") &&
						!type.Equals("simulation") &&
						!type.Equals("registry") &&
						!type.Equals("modeler") &&
						!type.Equals("agent")) return false;
					XmlElement eType = (XmlElement)XMLUtil.findChildNode(eService, "type");
					if(eType == null){
						eType = m_document.CreateElement("type");	
						eType.AppendChild(m_document.CreateTextNode(type));
						eService.AppendChild(eType);				
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
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setServiceType

		/// <summary>
		/// Set the maximum time before the job is terminated.  
		/// </summary>
		/// <param name="maxTime">holds the maximum time in seconds. </param>
		/// <returns>whether the maximum time is set successfully.</returns>
		public bool setJobMaxTime(double maxTime){
			if(maxTime <= 0) return false;
			XmlNode nodeRef = null;
			try{
				XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "job");
				if(eJob == null){
					eJob = m_document.CreateElement("job");
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
							}
							else{
								m_eOSoL.InsertBefore(eJob, m_eOSoL.FirstChild);
							}		
						}		
					}
				}
				if(maxTime > 0){
					XmlElement eMaxTime = (XmlElement)XMLUtil.findChildNode(eJob, "maxTime");
					if(eMaxTime == null){
						eMaxTime = m_document.CreateElement("maxTime");	
						eMaxTime.AppendChild(m_document.CreateTextNode(Double.IsInfinity(maxTime)?"INF":maxTime+""));
						eJob.AppendChild(eMaxTime);				
					}
					else{
						XMLUtil.setElementValue(eMaxTime, Double.IsInfinity(maxTime)?"INF":maxTime+"");
					}
				}
				else{
					return false;
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setJobMaxTime


		/// <summary>
		/// Set the scheduled start time for the job.   
		/// </summary>
		/// <param name="scheduledStartTime">holds the scheduled start time for the job.   </param>
		/// <returns>whether the scheduled start time is set successfully.</returns>
		public bool setJobScheduledStartTime(DateTime scheduledStartTime){
			XmlNode nodeRef = null;
			try{
				XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "job");
				if(eJob == null){
					eJob = m_document.CreateElement("job");
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
							}
							else{
								m_eOSoL.InsertBefore(eJob, m_eOSoL.FirstChild);
							}		
						}		
					}
				}
				if(scheduledStartTime.Year > 1970){
					XmlElement eScheduledStartTime = (XmlElement)XMLUtil.findChildNode(eJob, "scheduledStartTime");
					if(eScheduledStartTime == null){
						eScheduledStartTime = m_document.CreateElement("scheduledStartTime");	
						eScheduledStartTime.AppendChild(m_document.CreateTextNode(XMLUtil.createXSDateTime(scheduledStartTime)));
						eJob.AppendChild(eScheduledStartTime);				
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
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setJobScheduledStartTime

		/// <summary>
		/// Get the dependencies of the current job, which is 
		/// a string array of ids of the jobs that have run before the current job. 
		/// </summary>
		/// <param name="jobIDs">holds a string array of ids of the jobs that have run before the current job. </param>
		/// <returns>whether the job dependencies are set successfully.</returns>
		public bool setJobDependencies(string[] jobIDs){
			XmlNode nodeRef = null;
			try{
				XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "job");
				if(eJob == null){
					eJob = m_document.CreateElement("job");
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
							}
							else{
								m_eOSoL.InsertBefore(eJob, m_eOSoL.FirstChild);
							}		
						}		
					}
				}
				if(jobIDs != null && jobIDs.Length > 0){
					XmlElement eDependencies = (XmlElement)XMLUtil.findChildNode(eJob, "dependencies");
					if(eDependencies == null){
						eDependencies = m_document.CreateElement("dependencies");	
						eJob.AppendChild(eDependencies);									
					}
					XMLUtil.removeAllChildren(eDependencies);
					int iJobIDs = jobIDs.Length;
					for(int i = 0; i < iJobIDs; i++){
						if(jobIDs[i] != null && jobIDs[i].Length > 0){
							XmlElement eJobID = m_document.CreateElement("jobID");	
							eJobID.AppendChild(m_document.CreateTextNode(jobIDs[i]));
							eDependencies.AppendChild(eJobID);				
						}
					}
				}
				else{
					XMLUtil.removeChildrenByName(eJob, "dependencies");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setJobDependencies

		/// <summary>
		/// Set the required directories and files to run the job, which is a string array of paths. 
		/// </summary>
		/// <param name="paths">holds a string array of directory/file paths required to run the job. </param>
		/// <returns>whether the required directories and files are set successfully.</returns>
		public bool setRequiredDirectoriesAndFiles(String[] paths){
			XmlNode nodeRef = null;
			try{
				XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "job");
				if(eJob == null){
					eJob = m_document.CreateElement("job");
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
							}
							else{
								m_eOSoL.InsertBefore(eJob, m_eOSoL.FirstChild);
							}		
						}		
					}
				}
				if(paths != null && paths.Length > 0){
					XmlElement eRequiredDirectoriesAndFiles = (XmlElement)XMLUtil.findChildNode(eJob, "requiredDirectoriesAndFiles");
					if(eRequiredDirectoriesAndFiles == null){
						eRequiredDirectoriesAndFiles = m_document.CreateElement("requiredDirectoriesAndFiles");	
						eJob.AppendChild(eRequiredDirectoriesAndFiles);									
					}
					XMLUtil.removeAllChildren(eRequiredDirectoriesAndFiles);
					int iPaths = paths.Length;
					for(int i = 0; i < iPaths; i++){
						if(paths[i] != null && paths[i].Length > 0){
							XmlElement ePath = m_document.CreateElement("path");	
							ePath.AppendChild(m_document.CreateTextNode(paths[i]));
							eRequiredDirectoriesAndFiles.AppendChild(ePath);				
						}
					}
				}
				else{
					XMLUtil.removeChildrenByName(eJob, "requiredDirectoriesAndFiles");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setRequiredDirectoriesAndFilesjob

		/// <summary>
		/// Set the directories to make before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <param name="paths">holds a string array of directories to make before running the job. </param>
		/// <returns>whether the directories to make are set successfully.</returns>
		public bool setDirectoriesToMake(string[] paths){
			XmlNode nodeRef = null;
			try{
				XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "job");
				if(eJob == null){
					eJob = m_document.CreateElement("job");
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
							}
							else{
								m_eOSoL.InsertBefore(eJob, m_eOSoL.FirstChild);
							}		
						}		
					}
				}
				if(paths != null && paths.Length > 0){
					XmlElement eDirectoriesToMake = (XmlElement)XMLUtil.findChildNode(eJob, "directoriesToMake");
					if(eDirectoriesToMake == null){
						eDirectoriesToMake = m_document.CreateElement("directoriesToMake");	
						eJob.AppendChild(eDirectoriesToMake);									
					}
					XMLUtil.removeAllChildren(eDirectoriesToMake);
					int iPaths = paths.Length;
					for(int i = 0; i < iPaths; i++){
						if(paths[i] != null && paths[i].Length > 0){
							XmlElement ePath = m_document.CreateElement("path");	
							ePath.AppendChild(m_document.CreateTextNode(paths[i]));
							eDirectoriesToMake.AppendChild(ePath);				
						}
					}
				}
				else{
					XMLUtil.removeChildrenByName(eJob, "directoriesToMake");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;

		}//setDirectoriesToMake

		/// <summary>
		/// Set the files to create before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <param name="paths">holds a string array of files to create before running the job. </param>
		/// <returns>whether the files to create are set successfully.</returns>
		public bool setFilesToCreate(string[] paths){
			XmlNode nodeRef = null;
			try{
				XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "job");
				if(eJob == null){
					eJob = m_document.CreateElement("job");
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
							}
							else{
								m_eOSoL.InsertBefore(eJob, m_eOSoL.FirstChild);
							}		
						}		
					}
				}
				if(paths != null && paths.Length > 0){
					XmlElement eFilesToCreate = (XmlElement)XMLUtil.findChildNode(eJob, "filesToCreate");
					if(eFilesToCreate == null){
						eFilesToCreate = m_document.CreateElement("filesToCreate");	
						eJob.AppendChild(eFilesToCreate);									
					}
					XMLUtil.removeAllChildren(eFilesToCreate);
					int iPaths = paths.Length;
					for(int i = 0; i < iPaths; i++){
						if(paths[i] != null && paths[i].Length > 0){
							XmlElement ePath = m_document.CreateElement("path");	
							ePath.AppendChild(m_document.CreateTextNode(paths[i]));
							eFilesToCreate.AppendChild(ePath);				
						}
					}
				}
				else{
					XMLUtil.removeChildrenByName(eJob, "filesToCreate");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;

		}//setFilesToCreate

		/// <summary>
		/// Set the input files to copy from before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <param name="paths">holds a string array of input files to copy from before running the job. </param>
		/// <returns>whether the input files to copy from are set successfully.</returns>
		public bool setInputFilesToCopyFrom(string[] paths){
			XmlNode nodeRef = null;
			try{
				XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "job");
				if(eJob == null){
					eJob = m_document.CreateElement("job");
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
							}
							else{
								m_eOSoL.InsertBefore(eJob, m_eOSoL.FirstChild);
							}		
						}		
					}
				}
				if(paths != null && paths.Length > 0){
					XmlElement eInputFilesToCopyFrom = (XmlElement)XMLUtil.findChildNode(eJob, "inputFilesToCopyFrom");
					if(eInputFilesToCopyFrom == null){
						eInputFilesToCopyFrom = m_document.CreateElement("inputFilesToCopyFrom");	
						eJob.AppendChild(eInputFilesToCopyFrom);									
					}
					XMLUtil.removeAllChildren(eInputFilesToCopyFrom);
					int iPaths = paths.Length;
					for(int i = 0; i < iPaths; i++){
						if(paths[i] != null && paths[i].Length > 0){
							XmlElement ePath = m_document.CreateElement("path");	
							ePath.AppendChild(m_document.CreateTextNode(paths[i]));
							eInputFilesToCopyFrom.AppendChild(ePath);				
						}
					}
				}
				else{
					XMLUtil.removeChildrenByName(eJob, "inputFilesToCopyFrom");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;

		}//setInputFilesToCopyFrom

		/// <summary>
		/// Set the input files to copy to before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <param name="paths">holds a string array of input files to copy to before running the job. </param>
		/// <returns>whether the input files to copy to are set successfully.</returns>
		public bool setInputFilesToCopyTo(string[] paths){
			XmlNode nodeRef = null;
			try{
				XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "job");
				if(eJob == null){
					eJob = m_document.CreateElement("job");
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
							}
							else{
								m_eOSoL.InsertBefore(eJob, m_eOSoL.FirstChild);
							}		
						}		
					}
				}
				if(paths != null && paths.Length > 0){
					XmlElement eInputFilesToCopyTo = (XmlElement)XMLUtil.findChildNode(eJob, "inputFilesToCopyTo");
					if(eInputFilesToCopyTo == null){
						eInputFilesToCopyTo = m_document.CreateElement("inputFilesToCopyTo");	
						eJob.AppendChild(eInputFilesToCopyTo);									
					}
					XMLUtil.removeAllChildren(eInputFilesToCopyTo);
					int iPaths = paths.Length;
					for(int i = 0; i < iPaths; i++){
						if(paths[i] != null && paths[i].Length > 0){
							XmlElement ePath = m_document.CreateElement("path");	
							ePath.AppendChild(m_document.CreateTextNode(paths[i]));
							eInputFilesToCopyTo.AppendChild(ePath);				
						}
					}
				}
				else{
					XMLUtil.removeChildrenByName(eJob, "inputFilesToCopyTo");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;

		}//setInputFilesToCopyTo

		/// <summary>
		/// Set the input files to move from before running the job, which is  
		/// a string array of paths.
		/// </summary>
		/// <param name="paths">holds a string array of input files to move from before running the job. </param>
		/// <returns>whether the input files to move from are set successfully.</returns>
		public bool setInputFilesToMoveFrom(string[] paths){
			XmlNode nodeRef = null;
			try{
				XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "job");
				if(eJob == null){
					eJob = m_document.CreateElement("job");
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
							}
							else{
								m_eOSoL.InsertBefore(eJob, m_eOSoL.FirstChild);
							}		
						}		
					}
				}
				if(paths != null && paths.Length > 0){
					XmlElement eInputFilesToMoveFrom = (XmlElement)XMLUtil.findChildNode(eJob, "inputFilesToMoveFrom");
					if(eInputFilesToMoveFrom == null){
						eInputFilesToMoveFrom = m_document.CreateElement("inputFilesToMoveFrom");	
						eJob.AppendChild(eInputFilesToMoveFrom);									
					}
					XMLUtil.removeAllChildren(eInputFilesToMoveFrom);
					int iPaths = paths.Length;
					for(int i = 0; i < iPaths; i++){
						if(paths[i] != null && paths[i].Length > 0){
							XmlElement ePath = m_document.CreateElement("path");	
							ePath.AppendChild(m_document.CreateTextNode(paths[i]));
							eInputFilesToMoveFrom.AppendChild(ePath);				
						}
					}
				}
				else{
					XMLUtil.removeChildrenByName(eJob, "inputFilesToMoveFrom");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;

		}//setInputFilesToMoveFrom

		/// <summary>
		/// Set the input files to move to before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <param name="paths">holds a string array of input files to move to before running the job. </param>
		/// <returns>whether the input files to move to are set successfully.</returns>
		public bool setInputFilesToMoveTo(string[] paths){
			XmlNode nodeRef = null;
			try{
				XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "job");
				if(eJob == null){
					eJob = m_document.CreateElement("job");
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
							}
							else{
								m_eOSoL.InsertBefore(eJob, m_eOSoL.FirstChild);
							}		
						}		
					}
				}
				if(paths != null && paths.Length > 0){
					XmlElement eInputFilesToMoveTo = (XmlElement)XMLUtil.findChildNode(eJob, "inputFilesToMoveTo");
					if(eInputFilesToMoveTo == null){
						eInputFilesToMoveTo = m_document.CreateElement("inputFilesToMoveTo");	
						eJob.AppendChild(eInputFilesToMoveTo);									
					}
					XMLUtil.removeAllChildren(eInputFilesToMoveTo);
					int iPaths = paths.Length;
					for(int i = 0; i < iPaths; i++){
						if(paths[i] != null && paths[i].Length > 0){
							XmlElement ePath = m_document.CreateElement("path");	
							ePath.AppendChild(m_document.CreateTextNode(paths[i]));
							eInputFilesToMoveTo.AppendChild(ePath);				
						}
					}
				}
				else{
					XMLUtil.removeChildrenByName(eJob, "inputFilesToMoveTo");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;

		}//setInputFilesToMoveTo

		/// <summary>
		/// Set the output files to copy from before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <param name="paths">holds a string array of output files to copy from before running the job. </param>
		/// <returns>whether the output files to copy from are set successfully.</returns>
		public bool setOutputFilesToCopyFrom(string[] paths){
			XmlNode nodeRef = null;
			try{
				XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "job");
				if(eJob == null){
					eJob = m_document.CreateElement("job");
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
							}
							else{
								m_eOSoL.InsertBefore(eJob, m_eOSoL.FirstChild);
							}		
						}		
					}
				}
				if(paths != null && paths.Length > 0){
					XmlElement eOutputFilesToCopyFrom = (XmlElement)XMLUtil.findChildNode(eJob, "outputFilesToCopyFrom");
					if(eOutputFilesToCopyFrom == null){
						eOutputFilesToCopyFrom = m_document.CreateElement("outputFilesToCopyFrom");	
						eJob.AppendChild(eOutputFilesToCopyFrom);									
					}
					XMLUtil.removeAllChildren(eOutputFilesToCopyFrom);
					int iPaths = paths.Length;
					for(int i = 0; i < iPaths; i++){
						if(paths[i] != null && paths[i].Length > 0){
							XmlElement ePath = m_document.CreateElement("path");	
							ePath.AppendChild(m_document.CreateTextNode(paths[i]));
							eOutputFilesToCopyFrom.AppendChild(ePath);				
						}
					}
				}
				else{
					XMLUtil.removeChildrenByName(eJob, "outputFilesToCopyFrom");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;

		}//setOutputFilesToCopyFrom

		/// <summary>
		/// Set the output files to copy to before running the job, which is 
		/// a string array of paths.  
		/// </summary>
		/// <param name="paths">holds a string array of output files to copy to before running the job. </param>
		/// <returns>whether the output files to copy to are set successfully.</returns>
		public bool setOutputFilesToCopyTo(string[] paths){
			XmlNode nodeRef = null;
			try{
				XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "job");
				if(eJob == null){
					eJob = m_document.CreateElement("job");
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
							}
							else{
								m_eOSoL.InsertBefore(eJob, m_eOSoL.FirstChild);
							}		
						}		
					}
				}
				if(paths != null && paths.Length > 0){
					XmlElement eOutputFilesToCopyTo = (XmlElement)XMLUtil.findChildNode(eJob, "outputFilesToCopyTo");
					if(eOutputFilesToCopyTo == null){
						eOutputFilesToCopyTo = m_document.CreateElement("outputFilesToCopyTo");	
						eJob.AppendChild(eOutputFilesToCopyTo);									
					}
					XMLUtil.removeAllChildren(eOutputFilesToCopyTo);
					int iPaths = paths.Length;
					for(int i = 0; i < iPaths; i++){
						if(paths[i] != null && paths[i].Length > 0){
							XmlElement ePath = m_document.CreateElement("path");	
							ePath.AppendChild(m_document.CreateTextNode(paths[i]));
							eOutputFilesToCopyTo.AppendChild(ePath);				
						}
					}
				}
				else{
					XMLUtil.removeChildrenByName(eJob, "outputFilesToCopyTo");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;

		}//setOutputFilesToCopyTo

		/// <summary>
		/// Set the output files to move from before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <param name="paths">holds a string array of output files to move from before running the job. </param>
		/// <returns>whether the output files to move from are set successfully.</returns>
		public bool setOutputFilesToMoveFrom(string[] paths){
			XmlNode nodeRef = null;
			try{
				XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "job");
				if(eJob == null){
					eJob = m_document.CreateElement("job");
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
							}
							else{
								m_eOSoL.InsertBefore(eJob, m_eOSoL.FirstChild);
							}		
						}		
					}
				}
				if(paths != null && paths.Length > 0){
					XmlElement eOutputFilesToMoveFrom = (XmlElement)XMLUtil.findChildNode(eJob, "outputFilesToMoveFrom");
					if(eOutputFilesToMoveFrom == null){
						eOutputFilesToMoveFrom = m_document.CreateElement("outputFilesToMoveFrom");	
						eJob.AppendChild(eOutputFilesToMoveFrom);									
					}
					XMLUtil.removeAllChildren(eOutputFilesToMoveFrom);
					int iPaths = paths.Length;
					for(int i = 0; i < iPaths; i++){
						if(paths[i] != null && paths[i].Length > 0){
							XmlElement ePath = m_document.CreateElement("path");	
							ePath.AppendChild(m_document.CreateTextNode(paths[i]));
							eOutputFilesToMoveFrom.AppendChild(ePath);				
						}
					}
				}
				else{
					XMLUtil.removeChildrenByName(eJob, "outputFilesToMoveFrom");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;

		}//setOutputFilesToMoveFrom

		/// <summary>
		/// Set the output files to move to before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <param name="paths">holds a string array of output files to move to before running the job. </param>
		/// <returns>whether the output files to move to are set successfully.</returns>
		public bool setOutputFilesToMoveTo(string[] paths){
			XmlNode nodeRef = null;
			try{
				XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "job");
				if(eJob == null){
					eJob = m_document.CreateElement("job");
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
							}
							else{
								m_eOSoL.InsertBefore(eJob, m_eOSoL.FirstChild);
							}		
						}		
					}
				}
				if(paths != null && paths.Length > 0){
					XmlElement eOutputFilesToMoveTo = (XmlElement)XMLUtil.findChildNode(eJob, "outputFilesToMoveTo");
					if(eOutputFilesToMoveTo == null){
						eOutputFilesToMoveTo = m_document.CreateElement("outputFilesToMoveTo");	
						eJob.AppendChild(eOutputFilesToMoveTo);									
					}
					XMLUtil.removeAllChildren(eOutputFilesToMoveTo);
					int iPaths = paths.Length;
					for(int i = 0; i < iPaths; i++){
						if(paths[i] != null && paths[i].Length > 0){
							XmlElement ePath = m_document.CreateElement("path");	
							ePath.AppendChild(m_document.CreateTextNode(paths[i]));
							eOutputFilesToMoveTo.AppendChild(ePath);				
						}
					}
				}
				else{
					XMLUtil.removeChildrenByName(eJob, "outputFilesToMoveTo");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;

		}//setOutputFilesToMoveTo

		/// <summary>
		/// Set the files to delete after running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <param name="paths">holds a string array of file paths to delete after running the job. </param>
		/// <returns>whether the files to delete are set successfully.</returns>
		public bool setFilesToDelete(string[] paths){
			XmlNode nodeRef = null;
			try{
				XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "job");
				if(eJob == null){
					eJob = m_document.CreateElement("job");
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
							}
							else{
								m_eOSoL.InsertBefore(eJob, m_eOSoL.FirstChild);
							}		
						}		
					}
				}
				if(paths != null && paths.Length > 0){
					XmlElement eFilesToDelete = (XmlElement)XMLUtil.findChildNode(eJob, "filesToDelete");
					if(eFilesToDelete == null){
						eFilesToDelete = m_document.CreateElement("filesToDelete");	
						eJob.AppendChild(eFilesToDelete);									
					}
					XMLUtil.removeAllChildren(eFilesToDelete);
					int iPaths = paths.Length;
					for(int i = 0; i < iPaths; i++){
						if(paths[i] != null && paths[i].Length > 0){
							XmlElement ePath = m_document.CreateElement("path");	
							ePath.AppendChild(m_document.CreateTextNode(paths[i]));
							eFilesToDelete.AppendChild(ePath);				
						}
					}
				}
				else{
					XMLUtil.removeChildrenByName(eJob, "filesToDelete");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;

		}//setFilesToDelete


		/// <summary>
		/// Set the directories to delete after running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <param name="paths">holds a string array of directory paths to delete after running the job. </param>
		/// <returns>whether the directories to delete are set successfully.</returns>
		public bool setDirectoriesToDelete(string[] paths){
			XmlNode nodeRef = null;
			try{
				XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "job");
				if(eJob == null){
					eJob = m_document.CreateElement("job");
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
							}
							else{
								m_eOSoL.InsertBefore(eJob, m_eOSoL.FirstChild);
							}		
						}		
					}
				}
				if(paths != null && paths.Length > 0){
					XmlElement eDirectoriesToDelete = (XmlElement)XMLUtil.findChildNode(eJob, "directoriesToDelete");
					if(eDirectoriesToDelete == null){
						eDirectoriesToDelete = m_document.CreateElement("directoriesToDelete");	
						eJob.AppendChild(eDirectoriesToDelete);									
					}
					XMLUtil.removeAllChildren(eDirectoriesToDelete);
					int iPaths = paths.Length;
					for(int i = 0; i < iPaths; i++){
						if(paths[i] != null && paths[i].Length > 0){
							XmlElement ePath = m_document.CreateElement("path");	
							ePath.AppendChild(m_document.CreateTextNode(paths[i]));
							eDirectoriesToDelete.AppendChild(ePath);				
						}
					}
				}
				else{
					XMLUtil.removeChildrenByName(eJob, "directoriesToDelete");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setDirectoriesToDelete

		/// <summary>
		/// Set the processes to kill after running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <param name="processNames">holds a string array of process names to kill after running the job. </param>
		/// <returns>whether the processes to kill are set successfully.</returns>
		public bool setProcessesToKill(string[] processNames){
			XmlNode nodeRef = null;
			try{
				XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "job");
				if(eJob == null){
					eJob = m_document.CreateElement("job");
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.InsertBefore(eJob, nodeRef.NextSibling);			
							}
							else{
								m_eOSoL.InsertBefore(eJob, m_eOSoL.FirstChild);
							}		
						}		
					}
				}
				if(processNames != null && processNames.Length > 0){
					XmlElement eProcessesToKill = (XmlElement)XMLUtil.findChildNode(eJob, "processesToKill");
					if(eProcessesToKill == null){
						eProcessesToKill = m_document.CreateElement("processesToKill");	
						eJob.AppendChild(eProcessesToKill);									
					}
					XMLUtil.removeAllChildren(eProcessesToKill);
					int iProcesses = processNames.Length;
					for(int i = 0; i < iProcesses; i++){
						if(processNames[i] != null && processNames[i].Length > 0){
							XmlElement eProcess = m_document.CreateElement("process");	
							eProcess.AppendChild(m_document.CreateTextNode(processNames[i]));
							eProcessesToKill.AppendChild(eProcess);				
						}
					}
				}
				else{
					XMLUtil.removeChildrenByName(eJob, "processesToKill");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;

		}//setProcessesToKill

		/// <summary>
		/// Set the variable number. 
		/// </summary>
		/// <param name="variableNumber">holds the number of variables</param>
		/// <returns>whether the variable number is set successfully or not. </returns>
		public bool setVariableNumber(int variableNumber){
			if(variableNumber < 0){
				return true;
			}
			XmlNode nodeRef = null;
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.CreateElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "job");
				if(nodeRef != null){
					m_eOSoL.InsertBefore(eOptimization, nodeRef.NextSibling);			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.InsertBefore(eOptimization, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.InsertBefore(eOptimization, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.InsertBefore(eOptimization, nodeRef.NextSibling);			
							}
							else{
								m_eOSoL.InsertBefore(eOptimization, m_eOSoL.FirstChild);
							}		
						}		
					}
				}
			}
			try{
				eOptimization.SetAttribute("numberOfVariables", variableNumber+"");
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;	
		}//setVariableNumber

		/// <summary>
		/// Set the objective number. 
		/// </summary>
		/// <param name="objectiveNumber">holds the number of objectives</param>
		/// <returns>whether the objective number is set successfully or not. </returns>
		public bool setObjectiveNumber(int objectiveNumber){
			if(objectiveNumber < 0){
				return true;
			}
			XmlNode nodeRef = null;
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.CreateElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "job");
				if(nodeRef != null){
					m_eOSoL.InsertBefore(eOptimization, nodeRef.NextSibling);			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.InsertBefore(eOptimization, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.InsertBefore(eOptimization, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.InsertBefore(eOptimization, nodeRef.NextSibling);			
							}
							else{
								m_eOSoL.InsertBefore(eOptimization, m_eOSoL.FirstChild);
							}		
						}		
					}
				}
			}
			try{
				eOptimization.SetAttribute("numberOfObjectives", objectiveNumber+"");
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;	
		}//setObjectiveNumber

		/// <summary>
		/// Set the constraint number. 
		/// </summary>
		/// <param name="constraintNumber">holds the number of constraints</param>
		/// <returns>whether the constraint number is set successfully or not. </returns>
		public bool setConstraintNumber(int constraintNumber){
			if(constraintNumber < 0){
				return true;
			}
			XmlNode nodeRef = null;
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.CreateElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eOSoL, "job");
				if(nodeRef != null){
					m_eOSoL.InsertBefore(eOptimization, nodeRef.NextSibling);			
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
					if(nodeRef != null){
						m_eOSoL.InsertBefore(eOptimization, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
						if(nodeRef != null){
							m_eOSoL.InsertBefore(eOptimization, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
							if(nodeRef != null){
								m_eOSoL.InsertBefore(eOptimization, nodeRef.NextSibling);			
							}
							else{
								m_eOSoL.InsertBefore(eOptimization, m_eOSoL.FirstChild);
							}		
						}		
					}
				}
			}
			try{
				eOptimization.SetAttribute("numberOfConstraints", constraintNumber+"");
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;		
		}//setConstraintNumber

		/// <summary>
		/// Set initial variable values (double[]). 
		/// Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
		/// methods are recommended  to be called first. 
		/// </summary>
		/// <param name="initialVariableValues">holds a double array of initial variable values. </param>
		/// <returns>whether the initial variable values are set successfully or not. </returns>
		public bool setInitialVariableValues(double[] initialVariableValues){//TODO
			XmlNode nodeRef = null;
			try{
				XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eOSoL, "optimization");
				if(eOptimization == null){
					eOptimization = m_document.CreateElement("optimization");
					nodeRef = XMLUtil.findChildNode(m_eOSoL, "job");
					if(nodeRef != null){
						m_eOSoL.InsertBefore(eOptimization, nodeRef.NextSibling);			
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eOSoL, "service");
						if(nodeRef != null){
							m_eOSoL.InsertBefore(eOptimization, nodeRef.NextSibling);			
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eOSoL, "system");
							if(nodeRef != null){
								m_eOSoL.InsertBefore(eOptimization, nodeRef.NextSibling);			
							}
							else{
								nodeRef = XMLUtil.findChildNode(m_eOSoL, "general");
								if(nodeRef != null){
									m_eOSoL.InsertBefore(eOptimization, nodeRef.NextSibling);			
								}
								else{
									m_eOSoL.InsertBefore(eOptimization, m_eOSoL.FirstChild);
								}		
							}		
						}
					}
				}
				XmlElement eVariables = (XmlElement)XMLUtil.findChildNode(eOptimization, "variables");
				if(eVariables == null){
					if(initialVariableValues == null || initialVariableValues.Length <= 0){
						return true;
					}
					eVariables = m_document.CreateElement("variables");	
					eOptimization.InsertBefore(eVariables, eOptimization.FirstChild);									
				}
				XmlElement eInitialVariableValues = (XmlElement)XMLUtil.findChildNode(eVariables, "initialVariableValues");
				if(eInitialVariableValues == null){
					if(initialVariableValues == null || initialVariableValues.Length <= 0){
						return true;
					}
					eInitialVariableValues = m_document.CreateElement("initialVariableValues");	
					eVariables.InsertBefore(eInitialVariableValues, eVariables.FirstChild);									
				}
				XMLUtil.removeAllChildren(eInitialVariableValues);
				int iVars = initialVariableValues==null?0:initialVariableValues.Length;
				if(iVars == 0) return true;
				for(int i = 0; i < iVars; i++){
					XmlElement eVar = m_document.CreateElement("var");	
					eVar.SetAttribute("idx", i+"");
					eVar.SetAttribute("value", initialVariableValues[i]+"");
					eInitialVariableValues.AppendChild(eVar);				
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setInitialVariableValues


		/// <summary>
		/// Set the other options related elements. 
		/// </summary>
		/// <param name="names">holds the names of the other options. It is required. </param>
		/// <param name="values">holds the values of the other options, empty string "" if no value for an option.</param>
		/// <param name="descriptions">holds the descriptions of the other options, empty string "" if no value for an option, null for
		/// the entire array if none of the options have descriptions.</param>
		/// <returns>whether the other options element construction is successful.</returns>
		public bool setOtherOptions(string[] names, string[] values, string[] descriptions){
			if(names == null) return false;
			if(values == null) return false;
			if(names.Length != values.Length) return false;
			if(descriptions != null && names.Length != descriptions.Length) return false;
			for(int i = 0; i < names.Length; i++){
				addOtherOption(names[i], values[i], (descriptions==null)?"":descriptions[i]);
			}
			return true;
		}//setOtherOptions


		/// <summary>
		/// Add an other option element. 
		/// </summary>
		/// <param name="name">holds the name of the other option element. It is required. </param>
		/// <param name="value">holds the value of the other option element, empty string "" if none. </param>
		/// <param name="description">holds the description of the other option element, empty string "" if none. </param>
		/// <returns>whether the other option element is added successfully.</returns>
		public bool addOtherOption(string name, string value, string description){
			if(name == null) return false;

			ArrayList vNodeList = XMLUtil.getChildElementsByTagName(m_eOSoL, "other"); 
			int iNls = vNodeList==null?0:vNodeList.Count;
			XmlElement eOther;
			for(int i = 0; i < iNls; i++){
				eOther = (XmlElement)vNodeList[i];
				if(eOther.GetAttribute("name").Equals(name)){
					m_eOSoL.RemoveChild(eOther);
					break;
				}
			}
			eOther = createOther(name, value, description);
			m_eOSoL.AppendChild(eOther);
			return true;
		}//addOtherOption

		/// <summary>
		/// Create the OSoL root element and its most basic required structure.
		/// </summary>
		/// <returns>the OSoL element.</returns>
		protected XmlElement createOSoLRoot(){
			XmlElement eOSoL = XMLUtil.createOSxLRootElement(m_document, "osol");
			return eOSoL;
		}//createOSoLRoot

		/// <summary>
		/// Create the other element and its most basic required structure.
		/// </summary>
		/// <param name="name">the name of the other element. </param>
		/// <param name="value">the value of the other element, empty string "" if no value. </param>
		/// <param name="description">holds the description of the other option element, empty string "" if none. </param>
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
	}//class OSoLWriter
}//namespace
