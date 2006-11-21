using System;
using System.Xml;
using System.Collections;

using org.optimizationservices.oscommon.util;
using org.optimizationservices.oscommon.localinterface;
using org.optimizationservices.oscommon.datastructure.osresult;
using org.optimizationservices.oscommon.datastructure.osgeneral;
using org.optimizationservices.oscommon.datastructure.osprocess;

namespace org.optimizationservices.oscommon.representationparser{
	/// <summary>
	/// The <c>OSrLWriter</c> class is used to construct an instance that follows 
	/// the OSrL format. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OSrLWriter : OSgLWriter{
		/// <summary>
		/// m_eOSrL holds the OSrL root element.
		/// </summary>
		protected internal XmlElement m_eOSrL = null;
			
		/// <summary>
		/// m_eResultHeader holds the 1st child element resultHeader of root element OSrL.
		/// </summary>
		protected XmlElement m_eResultHeader = null;
	
		/// <summary>
		/// m_eResultData holds the 2nd child element resultData of root element OSrL.
		/// </summary>
		protected XmlElement m_eResultData = null;

		/// <summary>
		/// m_iVariableNumber holds the variable number. 
		/// </summary>
		private int m_iVariableNumber = -1;

		/// <summary>
		/// m_iObjectiveNumber holds the objective number. 
		/// </summary>
		private int m_iObjectiveNumber = -1;

		/// <summary>
		/// m_iConstraintNumber holds the constraint number. 
		/// </summary>
		private int m_iConstraintNumber = -1;

		/// <summary>
		/// m_iSolutionNumber holds the solution number. 
		/// </summary>
		private int m_iSolutionNumber = -1;

		/// <summary>
		/// constructor. 
		/// </summary>
		public OSrLWriter(){
			m_document = XMLUtil.createNewDocument();
			if(OSParameter.XSLT_LOCATION != null && OSParameter.XSLT_LOCATION.Length > 0){
				XmlProcessingInstruction xsltPI = m_document.CreateProcessingInstruction("xml-stylesheet",
					"type=\"text/xsl\" href = \"" + OSParameter.XSLT_LOCATION + "OSrL.xslt\"");
				m_document.AppendChild(xsltPI);     
			}
			m_eOSrL = createOSrLRoot();
			m_document.AppendChild(m_eOSrL);
		}//constructor

		/// <summary>
		/// set the OSResult, a standard os result interface. 
		/// </summary>
		/// <param name="osResult">holds the standard os result interface. </param>
		/// <returns>whether the OSResult is set successfully. </returns>
		public bool setOSResult(OSResult osResult){
			if(!setGeneralStatus(osResult.getGeneralStatus())){ 
				throw new Exception("setGeneralStatus Unsuccessful");
			}
			if(!setServiceURI(osResult.getServiceURI())){ 
				throw new Exception("setServiceURI Unsuccessful");
			}
			if(!setServiceName(osResult.getServiceName())){ 
				throw new Exception("setServiceName Unsuccessful");
			}
			if(!setInstanceName(osResult.getInstanceName())){ 
				throw new Exception("setInstanceName Unsuccessful");
			}
			if(!setJobID(osResult.getJobID())){ 
				throw new Exception("setJobID Unsuccessful");
			}
			if(!setResultTime(osResult.getResultTime())){ 
				throw new Exception("setResultTime Unsuccessful");
			}
			if(!setGeneralMessage(osResult.getGeneralMessage())){ 
				throw new Exception("setGeneralMessage Unsuccessful");
			}
			if(!setProcessStatistics(osResult.getProcessStatistics())){ 
				throw new Exception("setProcessStatistics Unsuccessful");
			}
			if(osResult.resultData.other != null && osResult.resultData.other.Length > 0){
				int n = osResult.resultData.other.Length;
				String[] msNames = new String[n];
				String[] msValues = new String[n];
				String[] msDescriptions = new String[n];
				for(int i = 0; i < n; i++){
					msNames[i] = osResult.resultData.other[i].name;
					msValues[i] = osResult.resultData.other[i].value;
					msDescriptions[i] = osResult.resultData.other[i].description;
				}
				if(!setOtherResults(msNames, msValues, msDescriptions)){
					throw new Exception("setOtherResults Unsuccessful");
				}			
			}
			int iSolutionNumber = osResult.getSolutionNumber();
			if(iSolutionNumber >= 0){
				if(!setVariableNumber(osResult.getVariableNumber())){ 
					throw new Exception("setVariableNumber Unsuccessful");
				}
				if(!setObjectiveNumber(osResult.getObjectiveNumber())){ 
					throw new Exception("setObjectiveNumber Unsuccessful");
				}
				if(!setConstraintNumber(osResult.getConstraintNumber())){ 
					throw new Exception("setConstraintNumber Unsuccessful");
				}		
				if(!setSolutionNumber(osResult.getSolutionNumber())){ 
					throw new Exception("setVariableAnalysis Unsuccessful");
				}
				for(int i = 0; i < iSolutionNumber; i++){
					if(!setSolution(i, osResult.getSolution(i))){ 
						throw new Exception("setSolution Unsuccessful");
					}
				}
				if(!setOSAnalysis(osResult.getOSAnalysis())){ 
					throw new Exception("setOSAnalysis Unsuccessful");
				}			
			}
			return true;
		}//setOSResult

		/// <summary>
		/// Set the general status
		/// </summary>
		/// <param name="status">holds the general status.</param>
		/// <returns>whether the general status is set successfully. </returns>
		public bool setGeneralStatus(GeneralStatus status){
			try{
				if(status != null){
					XmlElement eStatus = (XmlElement)XMLUtil.findChildNode(m_eResultHeader, "generalStatus");
					if(eStatus != null){
						m_eResultHeader.RemoveChild(eStatus);
					}
					eStatus = m_document.CreateElement("generalStatus");
					if(status.type != null && status.type.Length > 0){
						eStatus.SetAttribute("type", status.type);					
					}
					else{
						return false;
					}
					if(status.description != null && status.description.Length > 0){
						eStatus.SetAttribute("description", status.description);					
					}
					if(status.substatus != null && status.substatus.Length > 0){
						int iSubstatus = status.substatus.Length;
						for(int i = 0; i < iSubstatus; i++){
							XmlElement eSubstatus =  m_document.CreateElement("substatus");
							if(status.substatus[i].name != null && status.substatus[i].name.Length > 0){
								eSubstatus.SetAttribute("name", status.substatus[i].name);
							}						
							if(status.substatus[i].description != null && status.substatus[i].description.Length > 0){
								eSubstatus.SetAttribute("description", status.substatus[i].description);
							}						
							if(status.substatus[i].value != null && status.substatus[i].value.Length > 0){
								eSubstatus.AppendChild(m_document.CreateTextNode(status.substatus[i].value));
							}
							eStatus.AppendChild(eSubstatus);
						}					
					}
					m_eResultHeader.InsertBefore(eStatus, m_eResultHeader.FirstChild);
				}
				else{
					XMLUtil.removeChildrenByName(m_eResultHeader, "generalStatus");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setGeneralStatus

		/// <summary>
		/// Set the general status type, which can be: 
		/// success, error, warning. 
		/// </summary>
		/// <param name="type"> holds the general status type</param>
		/// <returns> whether the general status type is set successfully or not. </returns>
		public bool setGeneralStatusType(string type){
			try{
				if(type != null && type.Length > 0){
					if(!type.Equals("success") && !type.Equals("warning") && !type.Equals("error")) return false;
					XmlElement eStatus = (XmlElement)XMLUtil.findChildNode(m_eResultHeader, "generalStatus");
					if(eStatus == null){
						eStatus = m_document.CreateElement("generalStatus");
						m_eResultHeader.InsertBefore(eStatus, m_eResultHeader.FirstChild);
					}
					eStatus.SetAttribute("type", type);					
				}
				else{
					XMLUtil.removeChildrenByName(m_eResultHeader, "generalStatus");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setGeneralStatusType

		/// <summary>
		/// Set the general status description. 
		/// </summary>
		/// <param name="description"> holds the general status description.</param>
		/// <returns> whether the general status description is set successfully or not. </returns>
		public bool setGeneralStatusDescription(string description){
			try{
				XmlElement eStatus = (XmlElement)XMLUtil.findChildNode(m_eResultHeader, "generalStatus");
				if(eStatus == null){
					eStatus = m_document.CreateElement("generalStatus");
					m_eResultHeader.InsertBefore(eStatus, m_eResultHeader.FirstChild);
				}
				if(description != null && description.Length > 0){
					eStatus.SetAttribute("description", description);					
				}
				else{
					eStatus.RemoveAttribute("description");				
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setGeneralStatusDescription
	
		/// <summary>
		/// Set service uri.
		/// </summary>
		/// <param name="serviceURI"> holds the uri of the service. </param>
		/// <returns> whether the service uri is set successfully. </returns>
		public bool setServiceURI(string serviceURI){
			try{
				XmlNode nodeRef = null;
				if(serviceURI != null && serviceURI.Length > 0){
					XmlElement eServiceURI = (XmlElement)XMLUtil.findChildNode(m_eResultHeader, "serviceURI");
					if(eServiceURI == null){
						eServiceURI = m_document.CreateElement("serviceURI");					
						eServiceURI.AppendChild(m_document.CreateTextNode(serviceURI));
						nodeRef = XMLUtil.findChildNode(m_eResultHeader, "serviceName");
						if(nodeRef == null){
							nodeRef = XMLUtil.findChildNode(m_eResultHeader, "instanceName");
							if(nodeRef == null){
								nodeRef = XMLUtil.findChildNode(m_eResultHeader, "jobID");
								if(nodeRef == null){
									nodeRef = XMLUtil.findChildNode(m_eResultHeader, "time");
									if(nodeRef == null){
										nodeRef = XMLUtil.findChildNode(m_eResultHeader, "message");
									}
								}
							}
						}
						m_eResultHeader.InsertBefore(eServiceURI, nodeRef);
					}
					else{
						XMLUtil.setElementValue(eServiceURI, serviceURI);
					}
				}
				else{
					XMLUtil.removeChildrenByName(m_eResultHeader, "serviceURI");
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
		/// <param name="serviceName"> holds the name of the service. </param>
		/// <returns> whether the service name is set successfully. </returns>
		public bool setServiceName(string serviceName){
			try{
				XmlNode nodeRef = null;
				if(serviceName != null && serviceName.Length > 0){
					XmlElement eServiceName = (XmlElement)XMLUtil.findChildNode(m_eResultHeader, "serviceName");
					if(eServiceName == null){
						eServiceName = m_document.CreateElement("serviceName");					
						eServiceName.AppendChild(m_document.CreateTextNode(serviceName));
						nodeRef = XMLUtil.findChildNode(m_eResultHeader, "instanceName");
						if(nodeRef == null){
							nodeRef = XMLUtil.findChildNode(m_eResultHeader, "jobID");
							if(nodeRef == null){
								nodeRef = XMLUtil.findChildNode(m_eResultHeader, "time");
								if(nodeRef == null){
									nodeRef = XMLUtil.findChildNode(m_eResultHeader, "message");
								}
							}
						}
						m_eResultHeader.InsertBefore(eServiceName, nodeRef);
					}
					else{
						XMLUtil.setElementValue(eServiceName, serviceName);
					}
				}
				else{
					XMLUtil.removeChildrenByName(m_eResultHeader, "serviceName");
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
		/// <param name="instanceName"> holds the name of the instance. </param>
		/// <returns> whether the instance name is set successfully. </returns>
		public bool setInstanceName(string instanceName){
			try{
				XmlNode nodeRef = null;
				if(instanceName != null && instanceName.Length > 0){
					XmlElement eInstanceName = (XmlElement)XMLUtil.findChildNode(m_eResultHeader, "instanceName");
					if(eInstanceName == null){
						eInstanceName = m_document.CreateElement("instanceName");					
						eInstanceName.AppendChild(m_document.CreateTextNode(instanceName));
						nodeRef = XMLUtil.findChildNode(m_eResultHeader, "jobID");
						if(nodeRef == null){
							nodeRef = XMLUtil.findChildNode(m_eResultHeader, "time");
							if(nodeRef == null){
								nodeRef = XMLUtil.findChildNode(m_eResultHeader, "message");
							}
						}
						m_eResultHeader.InsertBefore(eInstanceName, nodeRef);
					}
					else{
						XMLUtil.setElementValue(eInstanceName, instanceName);
					}
				}
				else{
					XMLUtil.removeChildrenByName(m_eResultHeader, "instanceName");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setInstanceName
	
		/// <summary>
		/// Set job id.
		/// </summary>
		/// <param name="jobID"> holds the job id. </param>
		/// <returns> whether the job id is set successfully. </returns> 
		public bool setJobID(string jobID){
			try{
				XmlNode nodeRef = null;
				if(jobID != null && jobID.Length > 0){
					XmlElement eJobID = (XmlElement)XMLUtil.findChildNode(m_eResultHeader, "jobID");
					if(eJobID == null){
						eJobID = m_document.CreateElement("jobID");					
						eJobID.AppendChild(m_document.CreateTextNode(jobID));
						nodeRef = XMLUtil.findChildNode(m_eResultHeader, "time");
						if(nodeRef == null){
							nodeRef = XMLUtil.findChildNode(m_eResultHeader, "message");
						}
						m_eResultHeader.InsertBefore(eJobID, nodeRef);
					}
					else{
						XMLUtil.setElementValue(eJobID, jobID);
					}
				}
				else{
					XMLUtil.removeChildrenByName(m_eResultHeader, "jobID");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setJobID
	
		/// <summary>
		/// Set time of the result.
		/// </summary>
		/// <param name="time"> holds the time of the result.</param>
		/// <returns> whether result time is set successfully. </returns>
		public bool setResultTime(DateTime time){
			try{
				XmlNode nodeRef = null;
				if(time.Year > 1970){
					XmlElement eTime = (XmlElement)XMLUtil.findChildNode(m_eResultHeader, "time");
					if(eTime == null){
						eTime = m_document.CreateElement("time");					
						eTime.AppendChild(m_document.CreateTextNode(XMLUtil.createXSDateTime(time)));
						nodeRef = XMLUtil.findChildNode(m_eResultHeader, "message");
						m_eResultHeader.InsertBefore(eTime, nodeRef);
					}
					else{
						XMLUtil.setElementValue(eTime, XMLUtil.createXSDateTime(time));
					}
				}
				else{
					XMLUtil.removeChildrenByName(m_eResultHeader, "time");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());;
				return false;
			}
			return true;
		}//setResultTime
	
		/// <summary>
		/// Set the general message. 
		/// </summary>
		/// <param name="message"> holds the general message. </param>
		/// <returns> whether process message is set successfully. </returns>
		public bool setGeneralMessage(string message){
			try{
				XmlNode nodeRef = null;
				if(message != null && message.Length > 0){
					XmlElement eMessage = (XmlElement)XMLUtil.findChildNode(m_eResultHeader, "message");
					if(eMessage == null){
						eMessage = m_document.CreateElement("message");					
						eMessage.AppendChild(m_document.CreateTextNode(message));
						m_eResultHeader.InsertBefore(eMessage, nodeRef);
					}
					else{
						XMLUtil.setElementValue(eMessage, message);
					}
				}
				else{
					XMLUtil.removeChildrenByName(m_eResultHeader, "message");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setGeneralMessage
	
	
		/// <summary>
		/// Set the process statistics. 
		/// </summary>
		/// <param name="processStatistics"> holds the process statistics. </param>
		/// <returns> whether the process statistics is set successfully. </returns>
		public bool setProcessStatistics(ProcessStatistics processStatistics){
			if(processStatistics == null){
				XMLUtil.removeChildrenByName(m_eResultData, "statistics");
				return true;
			}
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(m_eResultData, "statistics");
			if(eStatistics != null){
				XMLUtil.removeChildrenByName(m_eResultData, "statistics");
			}
			eStatistics = m_document.CreateElement("statistics");
			m_eResultData.InsertBefore(eStatistics, m_eResultData.FirstChild);
			if(processStatistics.currentState != null && processStatistics.currentState.Length > 0){
				XmlElement eCurrentState = m_document.CreateElement("currentState");
				eCurrentState.AppendChild(m_document.CreateTextNode(processStatistics.currentState));	
				eStatistics.AppendChild(eCurrentState);
			}
			if(processStatistics.availableDiskSpace > 0){
				XmlElement eAvailableDiskSpace = m_document.CreateElement("availableDiskSpace");
				if(Double.IsInfinity(processStatistics.availableDiskSpace)){
					eAvailableDiskSpace.AppendChild(m_document.CreateTextNode("INF"));	
				}
				else{
					eAvailableDiskSpace.AppendChild(m_document.CreateTextNode(processStatistics.availableDiskSpace + ""));	
				}
				eStatistics.AppendChild(eAvailableDiskSpace);
			}
			if(processStatistics.availableMemory > 0){
				XmlElement eAvailableMemory = m_document.CreateElement("availableMemory");
				if(Double.IsInfinity(processStatistics.availableMemory)){
					eAvailableMemory.AppendChild(m_document.CreateTextNode("INF"));	
				}
				else{
					eAvailableMemory.AppendChild(m_document.CreateTextNode(processStatistics.availableMemory + ""));	
				}
				eStatistics.AppendChild(eAvailableMemory);
			}
			if(processStatistics.currentJobCount >= 0){
				XmlElement eCurrentJobCount = m_document.CreateElement("currentJobCount");
				eCurrentJobCount.AppendChild(m_document.CreateTextNode(processStatistics.currentJobCount + ""));	
				eStatistics.AppendChild(eCurrentJobCount);
			}
			if(processStatistics.totalJobsSoFar >= 0){
				XmlElement eTotalJobsSoFar = m_document.CreateElement("totalJobsSoFar");
				eTotalJobsSoFar.AppendChild(m_document.CreateTextNode(processStatistics.totalJobsSoFar + ""));	
				eStatistics.AppendChild(eTotalJobsSoFar);
			}
			if(processStatistics.timeLastJobEnded.Year > 1970){
				XmlElement eTimeLastJobEnded = m_document.CreateElement("timeLastJobEnded");
				eTimeLastJobEnded.AppendChild(m_document.CreateTextNode(XMLUtil.createXSDateTime(processStatistics.timeLastJobEnded)));	
				eStatistics.AppendChild(eTimeLastJobEnded);
			}
			if(processStatistics.timeLastJobTook >= 0){
				XmlElement eTimeLastJobTook = m_document.CreateElement("timeLastJobTook");
				if(Double.IsInfinity(processStatistics.timeLastJobTook)){
					eTimeLastJobTook.AppendChild(m_document.CreateTextNode("INF"));	
				}
				else{
					eTimeLastJobTook.AppendChild(m_document.CreateTextNode(processStatistics.timeLastJobTook + ""));	
				}
				eStatistics.AppendChild(eTimeLastJobTook);
			}
			if(processStatistics.timeServiceStarted.Year > 1970){
				XmlElement eTimeServiceStarted = m_document.CreateElement("timeServiceStarted");
				eTimeServiceStarted.AppendChild(m_document.CreateTextNode(XMLUtil.createXSDateTime(processStatistics.timeServiceStarted)));	
				eStatistics.AppendChild(eTimeServiceStarted);
			}
		
			if(processStatistics.jobs != null && processStatistics.jobs.job != null && processStatistics.jobs.job.Length > 0){
				XmlElement eJobs = m_document.CreateElement("jobs");
				int iJobs = processStatistics.jobs.job.Length;
				for(int i = 0; i < iJobs; i++){
					if(processStatistics.jobs.job[i] != null){
						XmlElement eJob = m_document.CreateElement("job");
						JobStatistics job = processStatistics.jobs.job[i];
						if(job.jobID != null && job.jobID.Length > 0){
							eJob.SetAttribute("jobID", job.jobID);
						}
						else{
							return false;
						}						
						if(job.state != null && job.state.Length > 0 && !job.state.Equals("unknown")){
							XmlElement eState = m_document.CreateElement("state");
							eState.AppendChild(m_document.CreateTextNode(job.state));	
							eJob.AppendChild(eState);
						}
						if(job.startTime.Year > 1970){
							XmlElement eStartTime = m_document.CreateElement("startTime");
							eStartTime.AppendChild(m_document.CreateTextNode(XMLUtil.createXSDateTime(job.startTime)));	
							eJob.AppendChild(eStartTime);
						}
						if(job.endTime.Year > 1970){
							XmlElement eEndTime = m_document.CreateElement("endTime");
							eEndTime.AppendChild(m_document.CreateTextNode(XMLUtil.createXSDateTime(job.endTime)));	
							eJob.AppendChild(eEndTime);
						}
						if(job.duration >= 0){
							XmlElement eDuration = m_document.CreateElement("duration");
							if(Double.IsInfinity(job.duration)){
								eDuration.AppendChild(m_document.CreateTextNode("INF"));	
							}
							else{
								eDuration.AppendChild(m_document.CreateTextNode(job.duration + ""));	
							}
							eJob.AppendChild(eDuration);
						}
						if(job.scheduledStartTime.Year > 1970){
							XmlElement eScheduledStartTime = m_document.CreateElement("scheduledStartTime");
							eScheduledStartTime.AppendChild(m_document.CreateTextNode(XMLUtil.createXSDateTime(job.scheduledStartTime)));	
							eJob.AppendChild(eScheduledStartTime);
						}
						if(job.dependencies != null && job.dependencies.jobID != null && job.dependencies.jobID.Length > 0){
							XmlElement eDependencies = m_document.CreateElement("dependencies");
							int iJobIDs = processStatistics.jobs.job[i].dependencies.jobID.Length;
							for(int j = 0; j < iJobIDs; j++){
								XmlElement eJobID = m_document.CreateElement("jobID");
								eJobID.AppendChild(m_document.CreateTextNode(job.dependencies.jobID[j]));	
								eDependencies.AppendChild(eJobID);
							}						
							eJob.AppendChild(eDependencies);
						}
						eJobs.AppendChild(eJob);
					}
				}
				eStatistics.AppendChild(eJobs);
			}
			return true;
		}//setprocessStatistics
	
		/// <summary>
		/// Set the current state. 
		/// </summary>
		/// <param name="currentState">holds the current state, which can be:
		/// "busy", "busyButAccepting", "idle", "idleButNotAccepting" or "noResponse".
		/// </param>
		/// <returns>whether the current state is set successfully.</returns>
		public bool setCurrentState(string currentState){
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(m_eResultData, "statistics");
			if(eStatistics == null){
				eStatistics = m_document.CreateElement("statistics");
				m_eResultData.InsertBefore(eStatistics, m_eResultData.FirstChild);
			}
			if(currentState != null && currentState.Length > 0){
				if(!currentState.Equals("busy") && 
					!currentState.Equals("busyButAccepting") &&
					!currentState.Equals("idle") &&
					!currentState.Equals("idleButNotAccepting") &&
					!currentState.Equals("noResponse")) return false;		 
				XmlElement eCurrentState = (XmlElement)XMLUtil.findChildNode(eStatistics, "currentState");
				if(eCurrentState == null){
					eCurrentState = m_document.CreateElement("currentState");					
					eCurrentState.AppendChild(m_document.CreateTextNode(currentState));					
					eStatistics.AppendChild(eCurrentState);
				}
				else{
					XMLUtil.setElementValue(eCurrentState, currentState);
				}
			}
			else{
				XMLUtil.removeChildrenByName(eStatistics, "currentState");
			}
			return true;
		}//setCurrentState

		/// <summary>
		/// Set the available disk space. 
		/// </summary>
		/// <param name="availableDiskSpace">holds the available disk space  (in bytes). </param>
		/// <returns>whether the available disk space is set successfully.</returns>
		public bool setAvailableDiskSpace(double availableDiskSpace){
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(m_eResultData, "statistics");
			if(eStatistics == null){
				eStatistics = m_document.CreateElement("statistics");
				m_eResultData.InsertBefore(eStatistics, m_eResultData.FirstChild);
			}
			if(!Double.IsNaN(availableDiskSpace) && availableDiskSpace >= 0){
				XmlElement eAvailableDiskSpace = (XmlElement)XMLUtil.findChildNode(eStatistics, "availableDiskSpace");
				if(eAvailableDiskSpace == null){
					eAvailableDiskSpace = m_document.CreateElement("availableDiskSpace");			
					if(Double.IsInfinity(availableDiskSpace)){
						eAvailableDiskSpace.AppendChild(m_document.CreateTextNode("INF"));
					}
					else{
						eAvailableDiskSpace.AppendChild(m_document.CreateTextNode(availableDiskSpace + ""));
					}
					eStatistics.AppendChild(eAvailableDiskSpace);
				}
				else{
					XMLUtil.setElementValue(eAvailableDiskSpace, Double.IsInfinity(availableDiskSpace)?"INF":(availableDiskSpace+""));
				}
			}
			else{
				XMLUtil.removeChildrenByName(eStatistics, "availableDiskSpace");
			}
			return true;
		}//setAvailableDiskSpace

		/// <summary>
		/// Set the available memory. 
		/// </summary>
		/// <param name="availableMemory">holds the available memory (in bytes). </param>
		/// <returns>whether the available memory is set successfully.</returns>
		public bool setAvailableMemory(double availableMemory){
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(m_eResultData, "statistics");
			if(eStatistics == null){
				eStatistics = m_document.CreateElement("statistics");
				m_eResultData.InsertBefore(eStatistics, m_eResultData.FirstChild);
			}
			if(!Double.IsNaN(availableMemory) && availableMemory >= 0){
				XmlElement eAvailableMemory = (XmlElement)XMLUtil.findChildNode(eStatistics, "availableMemory");
				if(eAvailableMemory == null){
					eAvailableMemory = m_document.CreateElement("availableMemory");			
					if(Double.IsInfinity(availableMemory)){
						eAvailableMemory.AppendChild(m_document.CreateTextNode("INF"));
					}
					else{
						eAvailableMemory.AppendChild(m_document.CreateTextNode(availableMemory + ""));
					}
					eStatistics.AppendChild(eAvailableMemory);
				}
				else{
					XMLUtil.setElementValue(eAvailableMemory, Double.IsInfinity(availableMemory)?"INF":(availableMemory+""));
				}
			}
			else{
				XMLUtil.removeChildrenByName(eStatistics, "availableMemory");
			}
			return true;
		}//setAvailableMemory

		/// <summary>
		/// Set the current job count. 
		/// </summary>
		/// <param name="currentJobCount">holds the current job count. </param>
		/// <returns>whether the current job count is set successfully.</returns>
		public bool setCurrentJobCount(int currentJobCount){
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(m_eResultData, "statistics");
			if(eStatistics == null){
				eStatistics = m_document.CreateElement("statistics");
				m_eResultData.InsertBefore(eStatistics, m_eResultData.FirstChild);
			}
			if(currentJobCount >= 0){
				XmlElement eCurrentJobCount = (XmlElement)XMLUtil.findChildNode(eStatistics, "currentJobCount");
				if(eCurrentJobCount == null){
					eCurrentJobCount = m_document.CreateElement("currentJobCount");			
					eCurrentJobCount.AppendChild(m_document.CreateTextNode(currentJobCount + ""));
					eStatistics.AppendChild(eCurrentJobCount);
				}
				else{
					XMLUtil.setElementValue(eCurrentJobCount, currentJobCount+"");
				}
			}
			else{
				XMLUtil.removeChildrenByName(eStatistics, "currentJobCount");
			}
			return true;
		}//setCurrentJobCount

		/// <summary>
		/// Set the total jobs received so far. 
		/// </summary>
		/// <param name="totalJobsSoFar">holds the total jobs received so far. </param>
		/// <returns>whether the total jobs so far is set successfully.</returns>
		public bool setTotalJobsSoFar(int totalJobsSoFar){
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(m_eResultData, "statistics");
			if(eStatistics == null){
				eStatistics = m_document.CreateElement("statistics");
				m_eResultData.InsertBefore(eStatistics, m_eResultData.FirstChild);
			}
			if(totalJobsSoFar >= 0){
				XmlElement eTotalJobsSoFar = (XmlElement)XMLUtil.findChildNode(eStatistics, "totalJobsSoFar");
				if(eTotalJobsSoFar == null){
					eTotalJobsSoFar = m_document.CreateElement("totalJobsSoFar");			
					eTotalJobsSoFar.AppendChild(m_document.CreateTextNode(totalJobsSoFar + ""));
					eStatistics.AppendChild(eTotalJobsSoFar);
				}
				else{
					XMLUtil.setElementValue(eTotalJobsSoFar, totalJobsSoFar+"");
				}
			}
			else{
				XMLUtil.removeChildrenByName(eStatistics, "totalJobsSoFar");
			}
			return true;
		}//setTotalJobsSoFar

		/// <summary>
		/// Set the time last job ended. 
		/// </summary>
		/// <param name="timeLastJobEnded">holds the time last job ended. </param>
		/// <returns>whether the time last job ended is set successfully.</returns>
		public bool setTimeLastJobEnded(DateTime timeLastJobEnded){
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(m_eResultData, "statistics");
			if(eStatistics == null){
				eStatistics = m_document.CreateElement("statistics");
				m_eResultData.InsertBefore(eStatistics, m_eResultData.FirstChild);
			}
			if(timeLastJobEnded.Year > 1970){
				XmlElement eTimeLastJobEnded = (XmlElement)XMLUtil.findChildNode(eStatistics, "timeLastJobEnded");
				if(eTimeLastJobEnded == null){
					eTimeLastJobEnded = m_document.CreateElement("timeLastJobEnded");			
					eTimeLastJobEnded.AppendChild(m_document.CreateTextNode(XMLUtil.createXSDateTime(timeLastJobEnded)));
					eStatistics.AppendChild(eTimeLastJobEnded);
				}
				else{
					XMLUtil.setElementValue(eTimeLastJobEnded, XMLUtil.createXSDateTime(timeLastJobEnded));
				}
			}
			else{
				XMLUtil.removeChildrenByName(eStatistics, "timeLastJobEnded");
			}
			return true;
		}//setTimeLastJobEnded


		/// <summary>
		/// Set the time last job took. 
		/// </summary>
		/// <param name="timeLastJobTook">holds the time last job took (in seconds). </param>
		/// <returns>whether the time last job took is set successfully.</returns>
		public bool setTimeLastJobTook(double timeLastJobTook){
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(m_eResultData, "statistics");
			if(eStatistics == null){
				eStatistics = m_document.CreateElement("statistics");
				m_eResultData.InsertBefore(eStatistics, m_eResultData.FirstChild);
			}
			if(!Double.IsNaN(timeLastJobTook) && timeLastJobTook >= 0){
				XmlElement eTimeLastJobTook = (XmlElement)XMLUtil.findChildNode(eStatistics, "timeLastJobTook");
				if(eTimeLastJobTook == null){
					eTimeLastJobTook = m_document.CreateElement("timeLastJobTook");			
					if(Double.IsInfinity(timeLastJobTook)){
						eTimeLastJobTook.AppendChild(m_document.CreateTextNode("INF"));
					}
					else{
						eTimeLastJobTook.AppendChild(m_document.CreateTextNode(timeLastJobTook + ""));
					}
					eStatistics.AppendChild(eTimeLastJobTook);
				}
				else{
					XMLUtil.setElementValue(eTimeLastJobTook, Double.IsInfinity(timeLastJobTook)?"INF":(timeLastJobTook+""));
				}
			}
			else{
				XMLUtil.removeChildrenByName(eStatistics, "timeLastJobTook");
			}
			return true;
		}//setTimeLastJobTook

		/// <summary>
		/// Set the time the service started. 
		/// </summary>
		/// <param name="timeServiceStarted">holds the time the service started. </param>
		/// <returns>whether the time the service started is set successfully.</returns>
		public bool setTimeServiceStarted(DateTime timeServiceStarted){
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(m_eResultData, "statistics");
			if(eStatistics == null){
				eStatistics = m_document.CreateElement("statistics");
				m_eResultData.InsertBefore(eStatistics, m_eResultData.FirstChild);
			}
			if(timeServiceStarted.Year > 1970){
				XmlElement eTimeServiceStarted = (XmlElement)XMLUtil.findChildNode(eStatistics, "timeServiceStarted");
				if(eTimeServiceStarted == null){
					eTimeServiceStarted = m_document.CreateElement("timeServiceStarted");			
					eTimeServiceStarted.AppendChild(m_document.CreateTextNode(XMLUtil.createXSDateTime(timeServiceStarted)));
					eStatistics.AppendChild(eTimeServiceStarted);
				}
				else{
					XMLUtil.setElementValue(eTimeServiceStarted, XMLUtil.createXSDateTime(timeServiceStarted));
				}
			}
			else{
				XMLUtil.removeChildrenByName(eStatistics, "timeServiceStarted");
			}
			return true;
		}//setTimeServiceStarted


		/// <summary>
		/// Set the service utilization. 
		/// </summary>
		/// <param name="serviceUtilization">holds the service utilization ([0, 1]). </param>
		/// <returns>whether the time last job took is set successfully.</returns>
		public bool setServiceUtilization(double serviceUtilization){
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(m_eResultData, "statistics");
			if(eStatistics == null){
				eStatistics = m_document.CreateElement("statistics");
				m_eResultData.InsertBefore(eStatistics, m_eResultData.FirstChild);
			}
			if(!Double.IsNaN(serviceUtilization) && serviceUtilization >= 0){
				XmlElement eServiceUtilization = (XmlElement)XMLUtil.findChildNode(eStatistics, "serviceUtilization");
				if(eServiceUtilization == null){
					eServiceUtilization = m_document.CreateElement("serviceUtilization");			
					eServiceUtilization.AppendChild(m_document.CreateTextNode(serviceUtilization + ""));
					eStatistics.AppendChild(eServiceUtilization);
				}
				else{
					XMLUtil.setElementValue(eServiceUtilization, serviceUtilization+"");
				}
			}
			else{
				XMLUtil.removeChildrenByName(eStatistics, "serviceUtilization");
			}
			return true;
		}//setServiceUtilization

		/// <summary>
		/// Set the statistics of all jobs. 
		/// </summary>
		/// <param name="jobStatistics"> holds an array of jobStatistics with 
		/// each member corresponding to one job. </param>
		/// <returns> whether the job statistics are set successfully. 
		public bool setJobStatistics(JobStatistics[] jobStatistics){
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(m_eResultData, "statistics");
			if(eStatistics == null){
				eStatistics = m_document.CreateElement("statistics");
				m_eResultData.InsertBefore(eStatistics, m_eResultData.FirstChild);
			}
			if(jobStatistics != null && jobStatistics.Length > 0){
				XmlElement eJobs = (XmlElement)XMLUtil.findChildNode(eStatistics, "jobs");
				if(eJobs == null){
					XMLUtil.removeChildrenByName(eStatistics, "jobs");
				}
				eJobs = m_document.CreateElement("jobs");
				eStatistics.AppendChild(eJobs);
				int iJobs = jobStatistics.Length;
				for(int i = 0; i < iJobs; i++){
					if(jobStatistics[i] != null){
						XmlElement eJob = m_document.CreateElement("job");
						if(jobStatistics[i].jobID != null && jobStatistics[i].jobID.Length > 0){
							eJob.SetAttribute("jobID", jobStatistics[i].jobID);
						}
						else{
							return false;
						}					
						if(jobStatistics[i].state != null && jobStatistics[i].state.Length > 0 && !jobStatistics[i].state.Equals("unknown")){
							XmlElement eState = m_document.CreateElement("state");
							eState.AppendChild(m_document.CreateTextNode(jobStatistics[i].state));	
							eJob.AppendChild(eState);
						}
						if(jobStatistics[i].startTime.Year > 1970){
							XmlElement eStartTime = m_document.CreateElement("startTime");
							eStartTime.AppendChild(m_document.CreateTextNode(XMLUtil.createXSDateTime(jobStatistics[i].startTime)));	
							eJob.AppendChild(eStartTime);
						}
						if(jobStatistics[i].endTime.Year > 1970){
							XmlElement eEndTime = m_document.CreateElement("endTime");
							eEndTime.AppendChild(m_document.CreateTextNode(XMLUtil.createXSDateTime(jobStatistics[i].endTime)));	
							eJob.AppendChild(eEndTime);
						}
						if(jobStatistics[i].duration >= 0){
							XmlElement eDuration = m_document.CreateElement("duration");
							if(Double.IsInfinity(jobStatistics[i].duration)){
								eDuration.AppendChild(m_document.CreateTextNode("INF"));	
							}
							else{
								eDuration.AppendChild(m_document.CreateTextNode(jobStatistics[i].duration + ""));	
							}
							eJob.AppendChild(eDuration);
						}
						if(jobStatistics[i].scheduledStartTime.Year > 1970){
							XmlElement eScheduledStartTime = m_document.CreateElement("scheduledStartTime");
							eScheduledStartTime.AppendChild(m_document.CreateTextNode(XMLUtil.createXSDateTime(jobStatistics[i].scheduledStartTime)));	
							eJob.AppendChild(eScheduledStartTime);
						}
						if(jobStatistics[i].dependencies != null && jobStatistics[i].dependencies.jobID != null && jobStatistics[i].dependencies.jobID.Length > 0){
							XmlElement eDependencies = m_document.CreateElement("dependencies");
							int iJobIDs = jobStatistics[i].dependencies.jobID.Length;
							for(int j = 0; j < iJobIDs; j++){
								XmlElement eJobID = m_document.CreateElement("jobID");
								eJobID.AppendChild(m_document.CreateTextNode(jobStatistics[i].dependencies.jobID[j]));	
								eDependencies.AppendChild(eJobID);
							}						
							eJob.AppendChild(eDependencies);
						}
						eJobs.AppendChild(eJob);
					}
				}
			}
			else{
				XMLUtil.removeChildrenByName(eStatistics, "jobs");
			}
			return true;
		}//setJobStatistics

		/// <summary>
		/// Set all the otherResult related elements. 
		/// </summary>
		/// <param name="names">holds the names of all the other result information. It is required. </param>
		/// <param name="values">holds the values of all the other result information, empty string "" if no value for one otherResult element.</param>
		/// <param name="descriptions">holds the descriptions of all the other result information, empty string "" if no value for one otherResult, null for
		/// the entire array if none of the otherResult elements have descriptions.</param>
		/// <returns>whether the otherResult elements are set successfully.</returns>
		public bool setOtherResults(string[] names, string[] values, string[] descriptions){
			if(names == null) return false;
			if(values == null) return false;
			if(names.Length != values.Length) return false;
			if(descriptions != null && names.Length != descriptions.Length) return false;
			for(int i = 0; i < names.Length; i++){
				addOtherResult(names[i], values[i], (descriptions==null)?"":descriptions[i]);
			}
			return true;
		}//setOtherResults


		/// <summary>
		/// Add an otherResult element. 
		/// </summary>
		/// <param name="name">holds the name of the otherResult element. It is required. </param>
		/// <param name="value">holds the value of the otherResult element, empty string "" if none. </param>
		/// <param name="description">holds the description of the otherResult element, empty string "" if none. </param>
		/// <returns>whether the otherResult element is added successfully.</returns>
		public bool addOtherResult(string name, string value, string description){
			if(name == null) return false;
			ArrayList vNodeList = XMLUtil.getChildElementsByTagName(m_eResultData, "other"); 
			int iNls = vNodeList==null?0:vNodeList.Count;
			XmlElement eOtherResult;
			for(int i = 0; i < iNls; i++){
				eOtherResult = (XmlElement)vNodeList[i];
				if(eOtherResult.GetAttribute("name").Equals(name)){
					m_eResultData.RemoveChild(eOtherResult);
					break;
				}
			}
			eOtherResult = createOther(name, value, description);
			m_eResultData.AppendChild(eOtherResult);
			return true;
		}//addOtherResult

		/// <summary>
		/// Set the variable number. 
		/// </summary>
		/// <param name="variableNumber"> holds the number of variables</param>
		/// <returns> whether the variable number is set successfully or not. </returns>
		public bool setVariableNumber(int variableNumber){
			XmlNode nodeRef = null;		
			if(variableNumber <= 0){
				return false;
			}
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eResultData, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.CreateElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eResultData, "statistics");			
				if(nodeRef != null){
					m_eResultData.InsertBefore(eOptimization, nodeRef.NextSibling);			
				}
				else{
					m_eResultData.InsertBefore(eOptimization, m_eResultData.FirstChild);
				}					
			}		
			m_iVariableNumber = variableNumber;
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
		/// <param name="objectiveNumber"> holds the number of objectives</param>
		/// <returns> whether the objective number is set successfully or not. </returns>
		public bool setObjectiveNumber(int objectiveNumber){
			XmlNode nodeRef = null;		
			if(objectiveNumber < 0){
				return false;
			}
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eResultData, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.CreateElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eResultData, "statistics");			
				if(nodeRef != null){
					m_eResultData.InsertBefore(eOptimization, nodeRef.NextSibling);			
				}
				else{
					m_eResultData.InsertBefore(eOptimization, m_eResultData.FirstChild);
				}					
			}		
			m_iObjectiveNumber = objectiveNumber;
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
		/// <param name="constraintNumber"> holds the number of constraints</param>
		/// <returns> whether the constraint number is set successfully or not. </returns>
		public bool setConstraintNumber(int constraintNumber){
			XmlNode nodeRef = null;		
			if(constraintNumber < 0){
				return false;
			}
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eResultData, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.CreateElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eResultData, "statistics");			
				if(nodeRef != null){
					m_eResultData.InsertBefore(eOptimization, nodeRef.NextSibling);			
				}
				else{
					m_eResultData.InsertBefore(eOptimization, m_eResultData.FirstChild);
				}					
			}		
			m_iConstraintNumber = constraintNumber;
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
		/// set the number of solutions. This method must be called before setting other optimization solution 
		/// related results.  
		/// Before this method is called, the setVariableNumber(int), setObjectiveNumber(int), setConstraintNumber(int) methods 
		/// have to be called first. 
		/// @see #setVariableNumber(int)
		/// @see #setObjectiveNumber(int)
		/// @see #setConstraintNumber(int)
		/// </summary>
		/// <param name="solutionNumber"> holds the number of solutions to set. </param>
		/// <returns> whether the solution number is set successfully.   </returns>
		public bool setSolutionNumber(int solutionNumber){
			XmlNode nodeRef = null;		
			if(solutionNumber < 0){
				return false;
			}
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eResultData, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.CreateElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eResultData, "statistics");			
				if(nodeRef != null){
					m_eResultData.InsertBefore(eOptimization, nodeRef.NextSibling);			
				}
				else{
					m_eResultData.InsertBefore(eOptimization, m_eResultData.FirstChild);
				}					
			}		
			m_iSolutionNumber = solutionNumber;
			try{
				eOptimization.SetAttribute("numberOfSolutions", solutionNumber+"");
				for(int i = 0; i < solutionNumber; i++){
					XmlElement eSolution = m_document.CreateElement("solution");
					XmlElement eStatus = m_document.CreateElement("status");
					eStatus.SetAttribute("type", "other");
					eSolution.AppendChild(eStatus);
					eOptimization.InsertBefore(eSolution, eOptimization.FirstChild);
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setSolutionNumber
	
		/// <summary>
		/// Set the [i]th optimization solution, where i equals the given solution index.   
		/// Before this method is called, the setSolutionNumber(int) method has to be called first. 
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolution
		/// @see #setSolutionNumber(int)
		/// </summary>
		/// <param name="solIdx"> holds the solution index to set the solution. </param>
		/// <param name="solution"> holds the optimization solution to set.</param> 
		/// <returns> whether the optimization solution is set successfully or not. </returns>
		public bool setSolution(int solIdx, OptimizationSolution solution){
			if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
			bool bSetSolution = true;
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eResultData, "optimization");
			if(eOptimization == null) return false;
			ArrayList vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
			if(solIdx >= vSolutions.Count) return false;
			XmlElement eSolution = (XmlElement)vSolutions[solIdx];
			eSolution = m_document.CreateElement("solution");
			XmlElement eStatus = m_document.CreateElement("status");
			eStatus.SetAttribute("type", "other");
			eSolution.AppendChild(eStatus);

			bSetSolution = setSolutionObjectiveIndex(solIdx, solution.objectiveIdx);
			if(!bSetSolution) return false;
			bSetSolution = setSolutionStatus(solIdx, solution.status);
			if(!bSetSolution) return false;
			bSetSolution = setSolutionMessage(solIdx, solution.message);
			if(!bSetSolution) return false;

			if(solution.variables != null){
				if(solution.variables.values != null){
					double[] mdValues = new double[m_iVariableNumber];
					VarValue[] var = solution.variables.values.var;
					int iVars = var==null?0:var.Length;
					for(int i = 0; i < iVars; i++){
						mdValues[var[i].idx] = var[i].value;
					}
					bSetSolution = setPrimalVariableValues(solIdx, mdValues);
					if(!bSetSolution) return false;	
				}		
				if(solution.variables.valuesString != null){
					string[] msValues = new string[m_iVariableNumber];
					VarStringValue[] var = solution.variables.valuesString.var;
					int iVars = var==null?0:var.Length;
					for(int i = 0; i < iVars; i++){
						msValues[var[i].idx] = var[i].value;
					}
					bSetSolution = setPrimalVariableStringValues(solIdx, msValues);
					if(!bSetSolution) return false;	
				}		
				if(solution.variables.other!= null){
					bSetSolution = setOtherVariableResults(solIdx, solution.variables.other);
					if(!bSetSolution) return false;	
				}		
			}

			if(solution.objectives != null){
				if(solution.objectives.values != null){
					double[] mdValues = new double[m_iObjectiveNumber];
					ObjValue[] obj = solution.objectives.values.obj;
					int iObjs = obj==null?0:obj.Length;
					for(int i = 0; i < m_iObjectiveNumber; i++){
						mdValues[i] = Double.NaN;
					}
					for(int i = 0; i < iObjs; i++){
						mdValues[Math.Abs(obj[i].idx)-1] = obj[i].value;
					}
					bSetSolution = setObjectiveValues(solIdx, mdValues);
					if(!bSetSolution) return false;	
				}	
				if(solution.objectives.other!= null){
					bSetSolution = setOtherObjectiveResults(solIdx, solution.objectives.other);
					if(!bSetSolution) return false;	
				}		
			}

			if(solution.constraints != null){
				if(solution.constraints.dualValues != null){
					double[] mdValues = new double[m_iConstraintNumber];
					DualVarValue[] con = solution.constraints.dualValues.con;
					int iCons = con==null?0:con.Length;
					for(int i = 0; i < iCons; i++){
						mdValues[con[i].idx] = con[i].value;
					}
					bSetSolution = setDualVariableValues(solIdx, mdValues);
					if(!bSetSolution) return false;	
				}	
				if(solution.constraints.other != null){
					bSetSolution = setOtherConstraintResults(solIdx, solution.constraints.other);
					if(!bSetSolution) return false;	
				}
			}
			if(solution.other != null){
				bSetSolution = setOtherOptimizationResults(solIdx, solution.other);
				if(!bSetSolution) return false;	
			}
			return bSetSolution;
		}//setSolution	
	
		/// <summary>
		/// Set the [i]th optimization solution status, where i equals the given solution index.   
		/// The solution status includes the status type, optional descriptions and possibly substatuses. 
		/// Before this method is called, the setSolutionNumber(int) method has to be called first. 
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolutionStatus
		/// @see #setSolutionNumber(int)
		/// </summary>
		/// <param name="solIdx"> holds the solution index to set the solution status.</param>
		/// <param name="status"> holds the optimization solution status to set.  </param>
		/// <returns> whether the optimization solution status is set successfully or not. </returns> 
		public bool setSolutionStatus(int solIdx, OptimizationSolutionStatus status){
			if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eResultData, "optimization");
			if(eOptimization == null) return false;
			ArrayList vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
			if(solIdx >= vSolutions.Count) return false;
			XmlElement eSolution = (XmlElement)vSolutions[solIdx];
			if(eSolution == null){
				eSolution = m_document.CreateElement("solution");
			}
			try{
				if(status != null){
					XmlElement eStatus = (XmlElement)XMLUtil.findChildNode(eSolution, "status");
					if(eStatus != null){
						eSolution.RemoveChild(eStatus);
					}
					eStatus = m_document.CreateElement("status");
					if(status.type != null && status.type.Length > 0){
						eStatus.SetAttribute("type", status.type);					
					}
					else{
						return false;
					}
					if(status.description != null && status.description.Length > 0){
						eStatus.SetAttribute("description", status.description);					
					}
					if(status.substatus != null && status.substatus.Length > 0){
						int iSubstatus = status.substatus.Length;
						for(int i = 0; i < iSubstatus; i++){
							XmlElement eSubstatus =  m_document.CreateElement("substatus");
							if(status.substatus[i].name != null && status.substatus[i].name.Length > 0){
								eSubstatus.SetAttribute("name", status.substatus[i].name);
							}						
							if(status.substatus[i].description != null && status.substatus[i].description.Length > 0){
								eSubstatus.SetAttribute("description", status.substatus[i].description);
							}						
							if(status.substatus[i].value != null && status.substatus[i].value.Length > 0){
								eSubstatus.AppendChild(m_document.CreateTextNode(status.substatus[i].value));
							}
							eStatus.AppendChild(eSubstatus);
						}					
					}
					eSolution.InsertBefore(eStatus, eSolution.FirstChild);
				}
				else{
					XMLUtil.removeChildrenByName(eSolution, "status");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setSolutionStatus
	
		/// <summary>
		/// Set the [i]th optimization solution status, where i equals the given solution index.   
		/// The solution status includes the status type, optional descriptions and possibly substatuses. 
		/// Before this method is called, the setSolutionNumber(int) method has to be called first. 
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolutionStatus
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolutionSubStatus
		/// @see #setSolutionNumber(int)
		/// </summary>
		/// <param name="solIdx"> holds the solution index to set the solution status.</param>
		/// <param name="type"> holds the optimization solution status type to set; it is required.   
		/// The solution status type can be: 
		/// unbounded, globallyOptimal, locallyOptimal, optimal, bestSoFar, feasible, infeasible, 
		/// stoppedByLimit, unsure, error, other 
		/// </param>
		/// <param name="description"> holds the optimization solution status description to set, null or empty string if none. </param>
		/// <param name="subStatus"> holds an array of optimization solution subStatuses to set, null if none. </param>
		/// <returns> whether the optimization solution status is set successfully or not. </returns>
		public bool setSolutionStatus(int solIdx, string type, string description, OptimizationSolutionSubstatus[] subStatuses){
			if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eResultData, "optimization");
			if(eOptimization == null) return false;
			ArrayList vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
			if(solIdx >= vSolutions.Count) return false;
			XmlElement eSolution = (XmlElement)vSolutions[solIdx];
			if(eSolution == null){
				eSolution = m_document.CreateElement("solution");
			}
			try{
				if(type != null && type.Length > 0){
					XmlElement eStatus = (XmlElement)XMLUtil.findChildNode(eSolution, "status");
					if(eStatus != null){
						eSolution.RemoveChild(eStatus);
					}
					eStatus = m_document.CreateElement("status");
					eStatus.SetAttribute("type", type);					
					if(description != null && description.Length > 0){
						eStatus.SetAttribute("description", description);					
					}
					else{
						eStatus.RemoveAttribute("description");
					}
					if(subStatuses != null && subStatuses.Length > 0){
						int iSubstatus = subStatuses.Length;
						for(int i = 0; i < iSubstatus; i++){
							XmlElement eSubstatus =  m_document.CreateElement("substatus");
							if(subStatuses[i].name != null && subStatuses[i].name.Length > 0){
								eSubstatus.SetAttribute("name", subStatuses[i].name);
							}						
							if(subStatuses[i].description != null && subStatuses[i].description.Length > 0){
								eSubstatus.SetAttribute("description", subStatuses[i].description);
							}						
							if(subStatuses[i].value != null && subStatuses[i].value.Length > 0){
								eSubstatus.AppendChild(m_document.CreateTextNode(subStatuses[i].value));
							}
							eStatus.AppendChild(eSubstatus);
						}					
					}
					eSolution.InsertBefore(eStatus, eSolution.FirstChild);
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
		}//setSolutionStatus
	
		/// <summary>
		/// Set the [i]th optimization solution message, where i equals the given solution index.   
		/// Before this method is called, the setSolutionNumber(int) method has to be called first. 
		/// @see #setSolutionNumber(int)
		/// </summary>
		/// <param name="solIdx"> holds the solution index to set the solution message.</param>
		/// <param name="solutionMessage"> holds the solution message to set.  </param>
		/// <returns> whether the optimization solution message is set successfully or not. </returns>
		public bool setSolutionMessage(int solIdx, string solutionMessage){
			if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eResultData, "optimization");
			if(eOptimization == null) return false;
			ArrayList vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
			if(solIdx >= vSolutions.Count) return false;
			XmlElement eSolution = (XmlElement)vSolutions[solIdx];
			if(eSolution == null){
				eSolution = m_document.CreateElement("solution");
			}
			try{
				XMLUtil.removeChildrenByName(eSolution, "message");
				if(solutionMessage != null && solutionMessage.Length > 0){
					XmlElement eMessage = m_document.CreateElement("message");
					eMessage.AppendChild(m_document.CreateTextNode(solutionMessage));
					XmlNode nodeRef = XMLUtil.findChildNode(eSolution, "status");			
					if(nodeRef != null){
						eSolution.InsertBefore(eMessage, nodeRef.NextSibling);			
					}
					else{
						eSolution.InsertBefore(eMessage, eSolution.FirstChild);
					}					
				}		
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setSolutionMessage	
	
		/// <summary>
		/// Set the [i]th optimization solution's objective index, where i equals the given solution index.   
		/// The first objective's index should be -1, the second -2, and so on.  
		/// Before this method is called, the setSolutionNumber(int) method has to be called first. 
		/// @see #setSolutionNumber(int)
		/// </summary>
		/// <param name="solIdx"> holds the solution index to set the objective index.</param>
		/// <param name="objectiveIdx"> holds the objective index to set. 
		/// All the objective indexes are negative starting from -1 downward. 
		/// </param>
		/// <returns> whether the optimization objective index is set successfully or not. </returns>
		public bool setSolutionObjectiveIndex(int solIdx, int objectiveIdx){
			if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eResultData, "optimization");
			if(eOptimization == null) return false;
			ArrayList vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
			if(solIdx >= vSolutions.Count) return false;
			XmlElement eSolution = (XmlElement)vSolutions[solIdx];
			if(eSolution == null){
				eSolution = m_document.CreateElement("solution");
			}
			try{
				eSolution.SetAttribute("objectiveIdx", objectiveIdx+"");
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;	
		}//setSolutionObjectiveIndex
	
		/// <summary>
		/// Set the [i]th optimization solution's primal variable values, where i equals the given solution index.   
		/// Before this method is called, the setSolutionNumber(int) method has to be called first. 
		/// @see #setSolutionNumber(int)
		/// </summary>
		/// <param name="solIdx"> holds the solution index to set the primal variable values. </param>
		/// <param name="x"> holds a double dense array of variable values to set; it could be null if all variables are 0.</param>
		/// <returns> whether primal variable values are set successfully or not. </returns>
		public bool setPrimalVariableValues(int solIdx, double[] x){
			if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eResultData, "optimization");
			if(eOptimization == null) return false;
			ArrayList vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
			if(solIdx >= vSolutions.Count) return false;
			XmlElement eSolution = (XmlElement)vSolutions[solIdx];
			if(eSolution == null){
				eSolution = m_document.CreateElement("solution");
			}
			XmlNode nodeRef = null;
			try{
				XmlElement eVariables = (XmlElement)XMLUtil.findChildNode(eSolution, "variables");
				if(eVariables == null){
					eVariables = m_document.CreateElement("variables");	
					nodeRef = XMLUtil.findChildNode(eSolution, "objectives");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(eSolution, "constraints");
						if(nodeRef == null){
							nodeRef = XMLUtil.findChildNode(eSolution, "other");
						}
					}
					eSolution.InsertBefore(eVariables, nodeRef);
				}
				XmlElement eValues = (XmlElement)XMLUtil.findChildNode(eVariables, "values");
				if(eValues == null){
					eValues = m_document.CreateElement("values");	
					eVariables.InsertBefore(eValues, eVariables.FirstChild);									
				}
				XMLUtil.removeAllChildren(eValues);
				int iVars = x==null?0:x.Length;
				if(iVars == 0) return true;
				if(iVars != m_iVariableNumber) return false;
				for(int i = 0; i < iVars; i++){
					if(x[i] != 0){
						XmlElement eVar = m_document.CreateElement("var");	
						eVar.SetAttribute("idx", i+"");
						eVar.AppendChild(m_document.CreateTextNode(x[i]+""));
						eValues.AppendChild(eVar);				
					}
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setPrimalVariableValues
	
		/// <summary>
		/// Set the [i]th optimization solution's primal variable string values, where i equals the given solution index.   
		/// Before this method is called, the setSolutionNumber(int) method has to be called first. 
		/// @see #setSolutionNumber(int)
		/// </summary>
		/// <param name="solIdx"> holds the solution index to set the primal variable string values. </param>
		/// <param name="x"> holds a dense string array of variable string values to set.</param>
		/// <returns> whether primal variable string values are set successfully or not. </returns>
		public bool setPrimalVariableStringValues(int solIdx, string[] x){
			if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eResultData, "optimization");
			if(eOptimization == null) return false;
			ArrayList vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
			if(solIdx >= vSolutions.Count) return false;
			XmlElement eSolution = (XmlElement)vSolutions[solIdx];
			if(eSolution == null){
				eSolution = m_document.CreateElement("solution");
			}
			XmlNode nodeRef = null;
			try{
				XmlElement eVariables = (XmlElement)XMLUtil.findChildNode(eSolution, "variables");
				if(eVariables == null){
					eVariables = m_document.CreateElement("variables");	
					nodeRef = XMLUtil.findChildNode(eSolution, "objectives");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(eSolution, "constraints");
						if(nodeRef == null){
							nodeRef = XMLUtil.findChildNode(eSolution, "other");
						}
					}
					eSolution.InsertBefore(eVariables, nodeRef);
				}
				XmlElement eValuesString = (XmlElement)XMLUtil.findChildNode(eVariables, "valuesString");
				if(eValuesString == null){
					eValuesString = m_document.CreateElement("valuesString");
					nodeRef = XMLUtil.findChildNode(eVariables, "other");
					eVariables.InsertBefore(eValuesString, nodeRef);
				}
				XMLUtil.removeAllChildren(eValuesString);
				int iVars = x==null?0:x.Length;
				if(iVars == 0) return true;
				if(iVars != m_iVariableNumber) return false;
				for(int i = 0; i < iVars; i++){
					XmlElement eVar = m_document.CreateElement("var");	
					eVar.SetAttribute("idx", i+"");
					eVar.AppendChild(m_document.CreateTextNode(x[i]));
					eValuesString.AppendChild(eVar);				
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setPrimalVariableStringValues

		
		/// <summary>
		/// Set the [i]th optimization solution's other (non-standard/solver specific)variable-related results, 
		/// where i equals the given solution index.   
		/// Before this method is called, the setSolutionNumber(int) method has to be called first. 
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OtherVariableResult
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OtherVarResult
		/// @see #setSolutionNumber(int)
		/// </summary>
		/// <param name="otherVariableResults"> holds an array of other variable results in OtherVariableResult[] array data structure, null if none. 
		/// Each other variable result contains the name (required), an optional description (string) and an optional
		/// value (string). Each other variable result can also optionally contain an array OtherVarResult for each variable. 
		/// The OtherVarResult contains a variable idx (required), and an optional string value.   
		/// </param>
		/// <returns> whether the other variable results are set successfully or not. </returns>
		public bool setOtherVariableResults(int solIdx, OtherVariableResult[] otherVariableResults){
			if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eResultData, "optimization");
			if(eOptimization == null) return false;
			ArrayList vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
			if(solIdx >= vSolutions.Count) return false;
			XmlElement eSolution = (XmlElement)vSolutions[solIdx];
			if(eSolution == null){
				eSolution = m_document.CreateElement("solution");
			}
			XmlNode nodeRef = null;
			try{
				XmlElement eVariables = (XmlElement)XMLUtil.findChildNode(eSolution, "variables");
				if(eVariables == null){
					eVariables = m_document.CreateElement("variables");	
					nodeRef = XMLUtil.findChildNode(eSolution, "objectives");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(eSolution, "constraints");
						if(nodeRef == null){
							nodeRef = XMLUtil.findChildNode(eSolution, "other");
						}
					}
					eSolution.InsertBefore(eVariables, nodeRef);
				}
				XMLUtil.removeChildrenByName(eVariables, "other");
				int iOthers = otherVariableResults==null?0:otherVariableResults.Length;
				if(iOthers == 0) return true;
				for(int i = 0; i < iOthers; i++){
					XmlElement eOther = m_document.CreateElement("other");
					if(otherVariableResults[i].name == null || otherVariableResults[i].name.Length <= 0){
						return false;
					}
					else{
						eOther.SetAttribute("name", otherVariableResults[i].name);
					}
					if(otherVariableResults[i].description != null && otherVariableResults[i].description.Length > 0){
						eOther.SetAttribute("description", otherVariableResults[i].description);					
					}
					if(otherVariableResults[i].value != null && otherVariableResults[i].value.Length > 0){
						eOther.AppendChild(m_document.CreateTextNode(otherVariableResults[i].value));
					}
					int iVars = (otherVariableResults[i]==null || otherVariableResults[i].var == null)?0:otherVariableResults[i].var.Length;
					if(iVars > 0){
						for(int j = 0; j < iVars; j++){
							XmlElement eVar = m_document.CreateElement("var");	
							eVar.SetAttribute("idx", otherVariableResults[i].var[j].idx+"");
							if(otherVariableResults[i].var[j].value != null && otherVariableResults[i].var[j].value.Length > 0){
								eVar.AppendChild(m_document.CreateTextNode(otherVariableResults[i].var[j].value));
							}
							eOther.AppendChild(eVar);	
						}
					}
					eVariables.AppendChild(eOther);
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setOtherVariableResults
	
		/// <summary>
		/// Set the [i]th optimization solution's objective values, where i equals the given solution index.   
		/// Usually one of the objective is what the solution was solved for (or based on). Its index should be indicated 
		/// in the solution's objectiveIdx attribute. Based on this objective's solution, the rest of the objective 
		/// values are (optionally) calculated. 
		/// Before this method is called, the setSolutionNumber(int) method has to be called first. 
		/// @see #setSolutionNumber(int)
		/// </summary>
		/// <param name="solIdx"> holds the solution index to set the objective values. </param>
		/// <param name="objectiveValues"> holds a double dense array of objective values to set.
		/// Possibly only the objective that the solution is based on has the value, and the rest of the objective
		/// values all get a Double.NaN value, meaning that they are not calculated.   
		/// </param>
		/// <returns> whether objective values are set successfully or not. </returns>
		public bool setObjectiveValues(int solIdx, double[] objectiveValues){
			if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eResultData, "optimization");
			if(eOptimization == null) return false;
			ArrayList vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
			if(solIdx >= vSolutions.Count) return false;
			XmlElement eSolution = (XmlElement)vSolutions[solIdx];
			if(eSolution == null){
				eSolution = m_document.CreateElement("solution");
			}
			XmlNode nodeRef = null;
			try{
				XmlElement eObjectives = (XmlElement)XMLUtil.findChildNode(eSolution, "objectives");
				if(eObjectives == null){
					eObjectives = m_document.CreateElement("objectives");	
					nodeRef = XMLUtil.findChildNode(eSolution, "constraints");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(eSolution, "other");
					}
					eSolution.InsertBefore(eObjectives, nodeRef);
				}
				XmlElement eValues = (XmlElement)XMLUtil.findChildNode(eObjectives, "values");
				if(eValues == null){
					eValues = m_document.CreateElement("values");	
					eObjectives.InsertBefore(eValues, eObjectives.FirstChild);									
				}
				XMLUtil.removeAllChildren(eValues);
				int iObjs = objectiveValues==null?0:objectiveValues.Length;
				if(iObjs == 0) return true;
				if(iObjs != m_iObjectiveNumber) return false;
				for(int i = 0; i < iObjs; i++){
					if(!Double.IsNaN(objectiveValues[i])){
						XmlElement eObj = m_document.CreateElement("obj");	
						eObj.SetAttribute("idx", (-i-1)+"");
						eObj.AppendChild(m_document.CreateTextNode(objectiveValues[i]+""));
						eValues.AppendChild(eObj);				
					}
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setObjectiveValues

	
		/// <summary>
		/// Set the [i]th optimization solution's other (non-standard/solver specific)objective-related results, 
		/// where i equals the given solution index.   
		/// Before this method is called, the setSolutionNumber(int) method has to be called first. 
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OtherObjectiveResult
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OtherObjResult
		/// @see #setSolutionNumber(int)
		/// </summary>
		/// <param name="solIdx"> holds the solution index to set the other objective results. </param>
		/// <param name="otherObjectiveResults"> holds an array of other objective results in OtherObjectiveResult[] array data structure, null if none. 
		/// Each other objective result contains the name (required), an optional description (string) and an optional
		/// value (string). Each other objective result can also optionally contain an array OtherObjResult for each objective. 
		/// The OtherObjResult contains an objective idx (required), an optional string value.  
		/// </param>  
		/// <returns> whether the other objective results are set successfully or not. </returns>
		public bool setOtherObjectiveResults(int solIdx, OtherObjectiveResult[] otherObjectiveResults){
			if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eResultData, "optimization");
			if(eOptimization == null) return false;
			ArrayList vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
			if(solIdx >= vSolutions.Count) return false;
			XmlElement eSolution = (XmlElement)vSolutions[solIdx];
			if(eSolution == null){
				eSolution = m_document.CreateElement("solution");
			}
			XmlNode nodeRef = null;
			try{
				XmlElement eObjectives = (XmlElement)XMLUtil.findChildNode(eSolution, "objectives");
				if(eObjectives == null){
					eObjectives = m_document.CreateElement("objectives");	
					nodeRef = XMLUtil.findChildNode(eSolution, "constraints");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(eSolution, "other");
					}
					eSolution.InsertBefore(eObjectives, nodeRef);
				}
				XMLUtil.removeChildrenByName(eObjectives, "other");
				int iOthers = otherObjectiveResults==null?0:otherObjectiveResults.Length;
				if(iOthers == 0) return true;
				for(int i = 0; i < iOthers; i++){
					XmlElement eOther = m_document.CreateElement("other");
					if(otherObjectiveResults[i].name == null || otherObjectiveResults[i].name.Length <= 0){
						return false;
					}
					else{
						eOther.SetAttribute("name", otherObjectiveResults[i].name);
					}
					if(otherObjectiveResults[i].description != null && otherObjectiveResults[i].description.Length > 0){
						eOther.SetAttribute("description", otherObjectiveResults[i].description);					
					}
					if(otherObjectiveResults[i].value != null && otherObjectiveResults[i].value.Length > 0){
						eOther.AppendChild(m_document.CreateTextNode(otherObjectiveResults[i].value));
					}
					int iObjs = (otherObjectiveResults[i]==null || otherObjectiveResults[i].obj == null)?0:otherObjectiveResults[i].obj.Length;
					if(iObjs > 0){
						for(int j = 0; j < iObjs; j++){
							XmlElement eObj = m_document.CreateElement("obj");	
							eObj.SetAttribute("idx", otherObjectiveResults[i].obj[j].idx+"");
							if(otherObjectiveResults[i].obj[j].value != null && otherObjectiveResults[i].obj[j].value.Length > 0){
								eObj.AppendChild(m_document.CreateTextNode(otherObjectiveResults[i].obj[j].value));
							}
							eOther.AppendChild(eObj);	
						}
					}
					eObjectives.AppendChild(eOther);
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;	
		}//setOtherObjectiveResults
	
		/// <summary>
		/// Set the [i]th optimization solution's dual variable values, where i equals the given solution index. 
		/// Before this method is called, the setSolutionNumber(int) method has to be called first. 
		/// @see #setSolutionNumber(int)
		/// </summary>
		/// <param name="solIdx"> holds the solution index to set the dual variable values. </param>
		/// <param name="values"> holds a double dense array of variable dual values to set; it could be null if all values are 0.</param>
		/// <returns> whether dual variable values are set successfully or not. </returns>
		public bool setDualVariableValues(int solIdx, double[] values){
			if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eResultData, "optimization");
			if(eOptimization == null) return false;
			ArrayList vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
			if(solIdx >= vSolutions.Count) return false;
			XmlElement eSolution = (XmlElement)vSolutions[solIdx];
			if(eSolution == null){
				eSolution = m_document.CreateElement("solution");
			}
			XmlNode nodeRef = null;
			try{
				XmlElement eConstraints = (XmlElement)XMLUtil.findChildNode(eSolution, "constraints");
				if(eConstraints == null){
					eConstraints = m_document.CreateElement("constraints");	
					nodeRef = XMLUtil.findChildNode(eSolution, "other");
					eSolution.InsertBefore(eConstraints, nodeRef);
				}
				XmlElement eDualValues = (XmlElement)XMLUtil.findChildNode(eConstraints, "dualValues");
				if(eDualValues == null){
					eDualValues = m_document.CreateElement("dualValues");	
					nodeRef = XMLUtil.findChildNode(eConstraints, "slacks");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(eConstraints, "allowableIncreases");
						if(nodeRef == null){
							nodeRef = XMLUtil.findChildNode(eConstraints, "allowableDecreases");
							if(nodeRef == null){
								nodeRef = XMLUtil.findChildNode(eConstraints, "ovFunctions");
								if(nodeRef == null){
									nodeRef = XMLUtil.findChildNode(eConstraints, "other");
								}
							}

						}
					}
					eConstraints.InsertBefore(eDualValues, nodeRef);
				}
				XMLUtil.removeAllChildren(eDualValues);
				int iCons;
				iCons = values == null?0:values.Length;
				if(iCons == 0) return true;
				if(iCons != m_iConstraintNumber) return false;
				for(int i = 0; i < iCons; i++){
					XmlElement eCon = m_document.CreateElement("con");	
					eCon.SetAttribute("idx", i+"");
					if(values[i] != 0){
						eCon.AppendChild(m_document.CreateTextNode(values[i]+""));
					}
					eDualValues.AppendChild(eCon);				
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setDualVariableValues
			
		/// <summary>
		/// Set the [i]th optimization solution's other (non-standard/solver specific)constraint-related results, 
		/// where i equals the given solution index.   
		/// Before this method is called, the setSolutionNumber(int) method has to be called first. 
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OtherConstraintResult
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OtherConResult
		/// @see #setSolutionNumber(int)
		/// </summary>
		/// <param name="otherConstraintResults"> holds an array of other constraint results in OtherConstraintResult[] array data structure, null if none. 
		/// Each other constraint result contains the name (required), an optional description (string) and an optional
		/// value (string). Each other constraint result can also optionally contain an array OtherConstraint for each constraint. 
		/// The OtherConResult contains a constraint idx (required), and an optional string value.   
		/// </param>
		/// <returns> whether the other constraint results are set successfully or not. </returns>
		public bool setOtherConstraintResults(int solIdx, OtherConstraintResult[] otherConstraintResults){
			if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eResultData, "optimization");
			if(eOptimization == null) return false;
			ArrayList vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
			if(solIdx >= vSolutions.Count) return false;
			XmlElement eSolution = (XmlElement)vSolutions[solIdx];
			if(eSolution == null){
				eSolution = m_document.CreateElement("solution");
			}
			XmlNode nodeRef = null;
			try{
				XmlElement eConstraints = (XmlElement)XMLUtil.findChildNode(eSolution, "constraints");
				if(eConstraints == null){
					eConstraints = m_document.CreateElement("constraints");	
					nodeRef = XMLUtil.findChildNode(eSolution, "other");
					eSolution.InsertBefore(eConstraints, nodeRef);
				}
				XMLUtil.removeChildrenByName(eConstraints, "other");
				int iOthers = otherConstraintResults==null?0:otherConstraintResults.Length;
				if(iOthers == 0) return true;
				for(int i = 0; i < iOthers; i++){
					XmlElement eOther = m_document.CreateElement("other");
					if(otherConstraintResults[i].name == null || otherConstraintResults[i].name.Length <= 0){
						return false;
					}
					else{
						eOther.SetAttribute("name", otherConstraintResults[i].name);
					}
					if(otherConstraintResults[i].description != null && otherConstraintResults[i].description.Length > 0){
						eOther.SetAttribute("description", otherConstraintResults[i].description);					
					}
					if(otherConstraintResults[i].value != null && otherConstraintResults[i].value.Length > 0){
						eOther.AppendChild(m_document.CreateTextNode(otherConstraintResults[i].value));
					}
					int iCons = (otherConstraintResults[i]==null || otherConstraintResults[i].con == null)?0:otherConstraintResults[i].con.Length;
					if(iCons > 0){
						for(int j = 0; j < iCons; j++){
							XmlElement eCon = m_document.CreateElement("con");	
							eCon.SetAttribute("idx", otherConstraintResults[i].con[j].idx+"");
							if(otherConstraintResults[i].con[j].value != null && otherConstraintResults[i].con[j].value.Length > 0){
								eCon.AppendChild(m_document.CreateTextNode(otherConstraintResults[i].con[j].value));
							}
							eOther.AppendChild(eCon);	
						}
					}
					eConstraints.AppendChild(eOther);
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setOtherConstraintResults

		/// <summary>
		/// Set the [i]th optimization solution's other (non-standard/solver specific)optimization-related results, 
		/// where i equals the given solution index.  These other results are usually on the general optimization, 
		/// not specifically on the variables, objective, or constraints.  
		/// Before this method is called, the setSolutionNumber(int) method has to be called first. 
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OtherOptimizationResult
		/// @see #setSolutionNumber(int)
		/// </summary>
		/// <param name="otherOptimizationResults"> holds an array of other optimization results in OtherOptimizationResult[] array data structure, null if none. 
		/// Each other optimization result contains the name (required), an optional description (string) and an optional
		/// value (string).  
		/// </param>
		/// <returns> whether the other optimization results are set successfully or not. </returns>
		public bool setOtherOptimizationResults(int solIdx, OtherOptimizationResult[] otherOptimizationResults){
			if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eResultData, "optimization");
			if(eOptimization == null) return false;
			ArrayList vSolutions= XMLUtil.getChildElementsByTagName(eOptimization, "solution");
			if(solIdx >= vSolutions.Count) return false;
			XmlElement eSolution = (XmlElement)vSolutions[solIdx];
			if(eSolution == null){
				eSolution = m_document.CreateElement("solution");
			}
			try{
				XMLUtil.removeChildrenByName(eSolution, "other");
				int iOthers = otherOptimizationResults==null?0:otherOptimizationResults.Length;
				if(iOthers == 0) return true;
				for(int i = 0; i < iOthers; i++){
					XmlElement eOther = m_document.CreateElement("other");
					if(otherOptimizationResults[i].name == null || otherOptimizationResults[i].name.Length <= 0){
						return false;
					}
					else{
						eOther.SetAttribute("name", otherOptimizationResults[i].name);
					}
					if(otherOptimizationResults[i].description != null && otherOptimizationResults[i].description.Length > 0){
						eOther.SetAttribute("description", otherOptimizationResults[i].description);					
					}
					if(otherOptimizationResults[i].value != null && otherOptimizationResults[i].value.Length > 0){
						eOther.AppendChild(m_document.CreateTextNode(otherOptimizationResults[i].value));
					}
					eSolution.AppendChild(eOther);
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		
		}//setOtherOptimizationResults

		/// <summary>
		/// Set the optimization analysis. 
		/// @see org.optimizationservices.oscommon.localinterface.OSAnalysis
		/// </summary>
		/// <param name="osAnalysis"> holds the optimization analysis in the standard OSAnalysis data structure. </param>
		/// <returns> the optimization analysis in the standard OSAnalysis data structure, null if none.</returns>
		public bool setOSAnalysis(OSAnalysis osAnalysis){
			if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1 || m_iSolutionNumber == -1) return false;
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eResultData, "optimization");
			if(eOptimization == null) return false;
		
			XMLUtil.removeChildrenByName(eOptimization, "osal");
			if(osAnalysis == null) return true;
			OSaLWriter osalWriter = new OSaLWriter();
			try {
				osalWriter.setOSAnalysis(osAnalysis);
			} 
			catch (Exception e) {
				Console.WriteLine(e.ToString());
			}
			XmlElement eOSaL =  (XmlElement)m_document.ImportNode(osalWriter.m_eOSaL, true);
			XMLUtil.removeAllAttributes(eOSaL);		
			eOptimization.AppendChild(eOSaL);
			return true;
		}//setOSAnalysis

		/// <summary>
		/// Create the OSrL root element and its most basic required structure.
		/// </summary>
		/// <returns>the OSrL element.</returns>
		protected XmlElement createOSrLRoot(){
			XmlElement eOSrL = XMLUtil.createOSxLRootElement(m_document, "osrl");
			m_eResultHeader = m_document.CreateElement("resultHeader");
			eOSrL.AppendChild(m_eResultHeader);
			XmlElement eGeneralStatus = m_document.CreateElement("generalStatus");
			eGeneralStatus.SetAttribute("type", "success");
			m_eResultHeader.AppendChild(eGeneralStatus);
			m_eResultData = m_document.CreateElement("resultData");
			eOSrL.AppendChild(m_eResultData);
			return eOSrL;
		}//createOSrLRoot

		/// <summary>
		/// Create the otherResult element and its most basic required structure.
		/// </summary>
		/// <param name="name">the name of the otherResult element. </param>
		/// <param name="value">the value of the otherResult element, empty string "" if no value. </param>
		/// <param name="description">holds the description of the otherResult element, empty string "" if none. </param>
		/// <returns>the otherResult element.</returns>
		protected XmlElement createOther(string name, string value, string description){
			XmlElement eOtherResult = m_document.CreateElement("other");
			eOtherResult.SetAttribute("name", name);
			eOtherResult.SetAttribute("description", (description==null)?"":description);
			if(value != null && value.Length > 0){
				eOtherResult.AppendChild(m_document.CreateTextNode(value));
			}
			return eOtherResult;
		}//createOtherResult
	}//class OSrLWriter
}//namespace
