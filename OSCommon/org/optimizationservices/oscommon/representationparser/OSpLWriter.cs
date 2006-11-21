using System;
using System.Xml;
using System.Collections;

using org.optimizationservices.oscommon.util;
using org.optimizationservices.oscommon.localinterface;
using org.optimizationservices.oscommon.datastructure.osprocess;

namespace org.optimizationservices.oscommon.representationparser{
	/// <summary>
	/// The <c>OSpLWriter</c> class is used to construct an instance that follows 
	/// the OSpL format. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OSpLWriter : OSgLWriter{
		/// <summary>
		/// m_eOSpL holds the OSpL root element.
		/// </summary>
		protected internal XmlElement m_eOSpL = null;

		/// <summary>
		/// m_eProcessHeader holds the 1st child element ProcessHeader of root element OSpL.
		/// </summary>
		protected XmlElement m_eProcessHeader = null;

		/// <summary>
		/// m_eProcessData holds the 2nd child element processData of root element OSpL.
		/// </summary>
		protected XmlElement m_eProcessData = null;


		/// <summary>
		/// constructor. 
		/// </summary>
		public OSpLWriter(){
			m_document = XMLUtil.createNewDocument();
			if(OSParameter.XSLT_LOCATION != null && OSParameter.XSLT_LOCATION.Length > 0){
				XmlProcessingInstruction xsltPI = m_document.CreateProcessingInstruction("xml-stylesheet",
					"type=\"text/xsl\" href = \"" + OSParameter.XSLT_LOCATION + "OSpL.xslt\"");
				m_document.AppendChild(xsltPI);     
			}
			m_eOSpL = createOSpLRoot();
			m_document.AppendChild(m_eOSpL);
		}//constructor

		/// <summary>
		/// set the OSProcess, a standard os process interface.  
		/// </summary>
		/// <param name="osProcess">the standard os process interface</param>
		/// <returns>whether the OSProcess is set successfully </returns>
		public bool setOSProcess(OSProcess osProcess){
			if(osProcess.processHeader.request != null){
				if(!setRequestAction(osProcess.getRequestAction())){ 
					throw new Exception("setRequestAction Unsuccessful");
				}
				if(!setRequestDescription(osProcess.getRequestDescription())){ 
					throw new Exception("setRequestDescription Unsuccessful");
				}
			}
			else if(osProcess.processHeader.response != null){
				if(!setResponseStatus(osProcess.getResponseStatus())){ 
					throw new Exception("setResponseStatus Unsuccessful");
				}
				if(!setResponseDescription(osProcess.getResponseDescription())){ 
					throw new Exception("setResponseDescription Unsuccessful");
				}
			}
			if(!setServiceURI(osProcess.getServiceURI())){ 
				throw new Exception("setServiceURI Unsuccessful");
			}
			if(!setServiceName(osProcess.getServiceName())){ 
				throw new Exception("setServiceName Unsuccessful");
			}
			if(!setProcessTime(osProcess.getProcessTime())){ 
				throw new Exception("setProcessTime Unsuccessful");
			}
			if(!setProcessMessage(osProcess.getProcessMessage())){ 
				throw new Exception("setProcessMessage Unsuccessful");
			}
			if(!setProcessStatistics(osProcess.getProcessStatistics())){ 
				throw new Exception("setProcessStatistics Unsuccessful");
			}
			if(!setOptimizationProcess(osProcess.getOptimizationProcess())){ 
				throw new Exception("setOptimizationProcess Unsuccessful");
			}
			if(osProcess.processData.other != null && osProcess.processData.other.Length > 0){
				int n = osProcess.processData.other.Length;
				string[] msNames = new string[n];
				string[] msValues = new string[n];
				string[] msDescriptions = new string[n];
				for(int i = 0; i < n; i++){
					msNames[i] = osProcess.processData.other[i].name;
					msValues[i] = osProcess.processData.other[i].value;
					msDescriptions[i] = osProcess.processData.other[i].description;
				}
				if(!setOtherProcesses(msNames, msValues, msDescriptions)){
					throw new Exception("setOtherProcesses Info Unsuccessful");
				}			
			}
			return true;
		}//setOSProcess

		/// <summary>
		/// Set the request action. 
		/// </summary>
		/// <param name="action">action holds the request action, which can be: 
		/// ping, notifyJobCompletion, requestJob, getServiceStatistics, setServiceStatistics, 
		/// getJobStatistics, setJobStatistics, getOptimization, setOptimization, getAll, setAll. 
		/// </param>
		/// <returns>whether the requestion action is set successfully.  </returns>
		public bool setRequestAction(string action){
			try{
				if(action != null && action.Length > 0){
					if(!action.Equals("ping") && 
						!action.Equals("notifyJobCompletion") &&
						!action.Equals("requestJob") &&
						!action.Equals("getServiceStatistics") &&
						!action.Equals("setServiceStatistics") &&
						!action.Equals("getJobStatistics") &&
						!action.Equals("setJobStatistics") &&
						!action.Equals("getOptimization") &&
						!action.Equals("setOptimization") &&
						!action.Equals("getAll") &&
						!action.Equals("setAll")) return false;		   
					XMLUtil.removeChildrenByName(m_eProcessHeader, "response");
					XmlElement eRequest = (XmlElement)XMLUtil.findChildNode(m_eProcessHeader, "request");
					if(eRequest == null){
						eRequest = m_document.CreateElement("request");	
						eRequest.SetAttribute("action", action);
						m_eProcessHeader.InsertBefore(eRequest, m_eProcessHeader.FirstChild);				}
					else{
						eRequest.SetAttribute("action", action);
					}
				}
				else{
					XMLUtil.removeChildrenByName(m_eProcessHeader, "request");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setRequestAction

		/// <summary>
		/// Set the request description.
		/// </summary>
		/// <param name="description">holds the request description</param>
		/// <returns>whether the requestion description is set successfully.  </returns>
		public bool setRequestDescription(string description){
			try{
				if(description != null && description.Length > 0){
					XMLUtil.removeChildrenByName(m_eProcessHeader, "response");
				}
				XmlElement eRequest = (XmlElement)XMLUtil.findChildNode(m_eProcessHeader, "request");
				if(eRequest == null){
					if(description == null || description.Length <= 0){
						return true;
					}
					eRequest = m_document.CreateElement("request");	
					eRequest.AppendChild(m_document.CreateTextNode(description));
					m_eProcessHeader.InsertBefore(eRequest, m_eProcessHeader.FirstChild);				}
				else{
					if(description == null || description.Length <= 0){
						XMLUtil.removeAllChildren(eRequest);
						return true;
					}
					XMLUtil.removeAllChildren(eRequest);
					eRequest.AppendChild(m_document.CreateTextNode(description));
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setRequestDescription

		/// <summary>
		/// Set the response status.
		/// </summary>
		/// <param name="status">holds the response status, which can be:
		/// success, error, warning. 
		/// </param>
		/// <returns>whether the response status is set successfully.</returns>
		public bool setResponseStatus(string status){
			try{
				if(status != null && status.Length > 0){
					if(!status.Equals("success") && 
						!status.Equals("error") &&
						!status.Equals("warning")) return false;		 
					XMLUtil.removeChildrenByName(m_eProcessHeader, "request");
					XmlElement eResponse = (XmlElement)XMLUtil.findChildNode(m_eProcessHeader, "response");
					if(eResponse == null){
						eResponse = m_document.CreateElement("response");	
						eResponse.SetAttribute("status", status);
						m_eProcessHeader.InsertBefore(eResponse, m_eProcessHeader.FirstChild);				}
					else{
						eResponse.SetAttribute("status", status);
					}
				}
				else{
					XMLUtil.removeChildrenByName(m_eProcessHeader, "response");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setResponseStatus


		/// <summary>
		/// Set the response description.
		/// </summary>
		/// <param name="description">holds the response description</param>
		/// <returns>whether the response description is set successfully.</returns>
		public bool setResponseDescription(string description){
			try{
				if(description != null && description.Length > 0){
					XMLUtil.removeChildrenByName(m_eProcessHeader, "request");
				}
				XmlElement eResponse = (XmlElement)XMLUtil.findChildNode(m_eProcessHeader, "response");
				if(eResponse == null){
					if(description == null || description.Length <= 0){
						return true;
					}
					eResponse = m_document.CreateElement("response");	
					eResponse.AppendChild(m_document.CreateTextNode(description));
					m_eProcessHeader.InsertBefore(eResponse, m_eProcessHeader.FirstChild);				}
				else{
					if(description == null || description.Length <= 0){
						XMLUtil.removeAllChildren(eResponse);
						return true;
					}
					XMLUtil.removeAllChildren(eResponse);
					eResponse.AppendChild(m_document.CreateTextNode(description));
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setResponseDescription

		/// <summary>
		/// Set service uri.
		/// </summary>
		/// <param name="serviceURI"holds the uri of the service. ></param>
		/// <returns>whether the service uri is set successfully. </returns>
		public bool setServiceURI(string serviceURI){
			try{
				XmlNode nodeRef = null;
				if(serviceURI != null && serviceURI.Length > 0){
					XmlElement eServiceURI = (XmlElement)XMLUtil.findChildNode(m_eProcessHeader, "serviceURI");
					if(eServiceURI == null){
						eServiceURI = m_document.CreateElement("serviceURI");					
						eServiceURI.AppendChild(m_document.CreateTextNode(serviceURI));
						nodeRef = XMLUtil.findChildNode(m_eProcessHeader, "serviceName");
						if(nodeRef == null){
							nodeRef = XMLUtil.findChildNode(m_eProcessHeader, "time");
							if(nodeRef == null){
								nodeRef = XMLUtil.findChildNode(m_eProcessHeader, "message");
							}
						}
						m_eProcessHeader.InsertBefore(eServiceURI, nodeRef);
					}
					else{
						XMLUtil.setElementValue(eServiceURI, serviceURI);
					}
				}
				else{
					XMLUtil.removeChildrenByName(m_eProcessHeader, "serviceURI");
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
					XmlElement eServiceName = (XmlElement)XMLUtil.findChildNode(m_eProcessHeader, "serviceName");
					if(eServiceName == null){
						eServiceName = m_document.CreateElement("serviceName");					
						eServiceName.AppendChild(m_document.CreateTextNode(serviceName));
						nodeRef = XMLUtil.findChildNode(m_eProcessHeader, "time");
						if(nodeRef == null){
							nodeRef = XMLUtil.findChildNode(m_eProcessHeader, "message");
						}
						m_eProcessHeader.InsertBefore(eServiceName, nodeRef);
					}
					else{
						XMLUtil.setElementValue(eServiceName, serviceName);
					}
				}
				else{
					XMLUtil.removeChildrenByName(m_eProcessHeader, "serviceName");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setServiceName

		/// <summary>
		/// Set time of the last process update.
		/// </summary>
		/// <param name="time">holds the time of the last process update.</param>
		/// <returns>whether process time is set successfully. </returns>
		public bool setProcessTime(DateTime time){
			try{
				XmlNode nodeRef = null;
				if(time.Year > 1970){
					XmlElement eTime = (XmlElement)XMLUtil.findChildNode(m_eProcessHeader, "time");
					if(eTime == null){
						eTime = m_document.CreateElement("time");					
						eTime.AppendChild(m_document.CreateTextNode(XMLUtil.createXSDateTime(time)));
						nodeRef = XMLUtil.findChildNode(m_eProcessHeader, "message");
						m_eProcessHeader.InsertBefore(eTime, nodeRef);
					}
					else{
						XMLUtil.setElementValue(eTime, XMLUtil.createXSDateTime(time));
					}
				}
				else{
					XMLUtil.removeChildrenByName(m_eProcessHeader, "time");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setProcessTime

		/// <summary>
		/// Set the process message. 
		/// </summary>
		/// <param name="message">holds the process message. </param>
		/// <returnswhether process message is set successfully. ></returns>
		public bool setProcessMessage(string message){
			try{
				XmlNode nodeRef = null;
				if(message != null && message.Length > 0){
					XmlElement eMessage = (XmlElement)XMLUtil.findChildNode(m_eProcessHeader, "message");
					if(eMessage == null){
						eMessage = m_document.CreateElement("message");					
						eMessage.AppendChild(m_document.CreateTextNode(message));
						m_eProcessHeader.InsertBefore(eMessage, nodeRef);
					}
					else{
						XMLUtil.setElementValue(eMessage, message);
					}
				}
				else{
					XMLUtil.removeChildrenByName(m_eProcessHeader, "message");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setProcessMessage

		/// <summary>
		/// Set the process statistics. 
		/// </summary>
		/// <param name="processStatistics">holds the process statistics. </param>
		/// <returns>whether the process statistics is set successfully. </returns>
		public bool setProcessStatistics(ProcessStatistics processStatistics){
			if(processStatistics == null){
				XMLUtil.removeChildrenByName(m_eProcessData, "statistics");
				return true;
			}
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(m_eProcessData, "statistics");
			if(eStatistics != null){
				XMLUtil.removeChildrenByName(m_eProcessData, "statistics");
			}
			eStatistics = m_document.CreateElement("statistics");
			m_eProcessData.InsertBefore(eStatistics, m_eProcessData.FirstChild);
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
						if(job.serviceURI != null && job.serviceURI.Length > 0){
							XmlElement eServiceURI = m_document.CreateElement("serviceURI");
							eServiceURI.AppendChild(m_document.CreateTextNode(job.serviceURI));	
							eJob.AppendChild(eServiceURI);
						}
						if(job.userName != null && job.userName.Length > 0){
							XmlElement eUserName = m_document.CreateElement("userName");
							eUserName.AppendChild(m_document.CreateTextNode(job.userName));	
							eJob.AppendChild(eUserName);
						}
						if(job.submitTime.Year > 1970){
							XmlElement eSubmitTime = m_document.CreateElement("submitTime");
							eSubmitTime.AppendChild(m_document.CreateTextNode(XMLUtil.createXSDateTime(job.submitTime)));	
							eJob.AppendChild(eSubmitTime);
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
						if(job.requiredDirectoriesAndFiles != null && job.requiredDirectoriesAndFiles.path != null && job.requiredDirectoriesAndFiles.path.Length > 0){
							XmlElement eRequiredDirectoriesAndFiles = m_document.CreateElement("requiredDirectoriesAndFiles");
							int iPaths = processStatistics.jobs.job[i].requiredDirectoriesAndFiles.path.Length;
							for(int j = 0; j < iPaths; j++){
								XmlElement ePath = m_document.CreateElement("path");
								ePath.AppendChild(m_document.CreateTextNode(job.requiredDirectoriesAndFiles.path[j]));	
								eRequiredDirectoriesAndFiles.AppendChild(ePath);
							}						
							eJob.AppendChild(eRequiredDirectoriesAndFiles);
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
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(m_eProcessData, "statistics");
			if(eStatistics == null){
				eStatistics = m_document.CreateElement("statistics");
				m_eProcessData.InsertBefore(eStatistics, m_eProcessData.FirstChild);
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
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(m_eProcessData, "statistics");
			if(eStatistics == null){
				eStatistics = m_document.CreateElement("statistics");
				m_eProcessData.InsertBefore(eStatistics, m_eProcessData.FirstChild);
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
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(m_eProcessData, "statistics");
			if(eStatistics == null){
				eStatistics = m_document.CreateElement("statistics");
				m_eProcessData.InsertBefore(eStatistics, m_eProcessData.FirstChild);
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
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(m_eProcessData, "statistics");
			if(eStatistics == null){
				eStatistics = m_document.CreateElement("statistics");
				m_eProcessData.InsertBefore(eStatistics, m_eProcessData.FirstChild);
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
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(m_eProcessData, "statistics");
			if(eStatistics == null){
				eStatistics = m_document.CreateElement("statistics");
				m_eProcessData.InsertBefore(eStatistics, m_eProcessData.FirstChild);
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
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(m_eProcessData, "statistics");
			if(eStatistics == null){
				eStatistics = m_document.CreateElement("statistics");
				m_eProcessData.InsertBefore(eStatistics, m_eProcessData.FirstChild);
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
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(m_eProcessData, "statistics");
			if(eStatistics == null){
				eStatistics = m_document.CreateElement("statistics");
				m_eProcessData.InsertBefore(eStatistics, m_eProcessData.FirstChild);
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
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(m_eProcessData, "statistics");
			if(eStatistics == null){
				eStatistics = m_document.CreateElement("statistics");
				m_eProcessData.InsertBefore(eStatistics, m_eProcessData.FirstChild);
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
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(m_eProcessData, "statistics");
			if(eStatistics == null){
				eStatistics = m_document.CreateElement("statistics");
				m_eProcessData.InsertBefore(eStatistics, m_eProcessData.FirstChild);
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
		/// <param name="jobStatistics">holds an array of jobStatistics with 
		/// each member corresponding to one job. 
		/// </param>
		/// <returns>whether the job statistics are set successfully. </returns>
		public bool setJobStatistics(JobStatistics[] jobStatistics){
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(m_eProcessData, "statistics");
			if(eStatistics == null){
				eStatistics = m_document.CreateElement("statistics");
				m_eProcessData.InsertBefore(eStatistics, m_eProcessData.FirstChild);
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
						if(jobStatistics[i].serviceURI != null && jobStatistics[i].serviceURI.Length > 0){
							XmlElement eServiceURI = m_document.CreateElement("serviceURI");
							eServiceURI.AppendChild(m_document.CreateTextNode(jobStatistics[i].serviceURI));	
							eJob.AppendChild(eServiceURI);
						}
						if(jobStatistics[i].userName != null && jobStatistics[i].userName.Length > 0){
							XmlElement eUserName = m_document.CreateElement("userName");
							eUserName.AppendChild(m_document.CreateTextNode(jobStatistics[i].userName));	
							eJob.AppendChild(eUserName);
						}
						if(jobStatistics[i].submitTime.Year > 1970){
							XmlElement eSubmitTime = m_document.CreateElement("submitTime");
							eSubmitTime.AppendChild(m_document.CreateTextNode(XMLUtil.createXSDateTime(jobStatistics[i].submitTime)));	
							eJob.AppendChild(eSubmitTime);
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
						if(jobStatistics[i].requiredDirectoriesAndFiles != null && jobStatistics[i].requiredDirectoriesAndFiles.path != null && jobStatistics[i].requiredDirectoriesAndFiles.path.Length > 0){
							XmlElement eRequiredDirectoriesAndFiles = m_document.CreateElement("requiredDirectoriesAndFiles");
							int iPaths = jobStatistics[i].requiredDirectoriesAndFiles.path.Length;
							for(int j = 0; j < iPaths; j++){
								XmlElement ePath = m_document.CreateElement("path");
								ePath.AppendChild(m_document.CreateTextNode(jobStatistics[i].requiredDirectoriesAndFiles.path[j]));	
								eRequiredDirectoriesAndFiles.AppendChild(ePath);
							}						
							eJob.AppendChild(eRequiredDirectoriesAndFiles);
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
		/// Set the optimization process of all the jobs, which are in effect
		/// intermediate (or occasionally final) optimization results. The intermediate process 
		/// can be some pre-built standard optimization information and/or the standard OSrL (Optimization
		/// Services result Language.
		/// </summary>
		/// <param name="optimizationProcess">holds the optimization process information which 
		/// contains an array, with each member corresponding to an optimization job. Each optimization job contains a job id string 
		/// and an optimization result, which data structure follow the OSrL schema.  
		/// </param>
		/// <returns>whether the optimization process is set successfully. </returns>
		public bool setOptimizationProcess(OptimizationProcess optimizationProcess){
			XmlNode nodeRef = null;
			if(optimizationProcess == null || optimizationProcess.job == null ||  optimizationProcess.job.Length <= 0){
				XMLUtil.removeChildrenByName(m_eProcessData, "optimization");
				return true;
			}
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eProcessData, "optimization");
			if(eOptimization == null){
				eOptimization = m_document.CreateElement("optimization");
				nodeRef = XMLUtil.findChildNode(m_eProcessData, "statistics");			
				if(nodeRef != null){
					m_eProcessData.InsertBefore(eOptimization, nodeRef.NextSibling);			
				}
				else{
					m_eProcessData.InsertBefore(eOptimization, m_eProcessData.FirstChild);
				}			
			}
			XMLUtil.removeChildrenByName(eOptimization, "job");
			int iJobs = optimizationProcess.job.Length;
			for(int i = 0; i < iJobs; i++){
				if(optimizationProcess.job[i] == null) continue;
				if(optimizationProcess.job[i].jobID == null) continue;
				if(optimizationProcess.job[i].standard == null && optimizationProcess.job[i].osrl == null) continue;
				XmlElement eJob = m_document.CreateElement("job");
				eOptimization.AppendChild(eJob);
				eJob.SetAttribute("jobID", optimizationProcess.job[i].jobID);
				
				if(optimizationProcess.job[i].standard != null && 
					optimizationProcess.job[i].standard.update != null && 
					optimizationProcess.job[i].standard.update.Length > 0){
					XmlElement eStandard = m_document.CreateElement("standard");
					int iUpdates = optimizationProcess.job[i].standard.update.Length;
					OptimizationUpdate update; 
					for(int j = 0; j < iUpdates; j++){
						update = optimizationProcess.job[i].standard.update[j];				
						if(update != null){
							XmlElement eUpdate = m_document.CreateElement("update");
							if(update.ObjectiveIdx <= 0){
								eUpdate.SetAttribute("objectiveIdx", update.ObjectiveIdx+"");
							}
							else{
								eUpdate.SetAttribute("objectiveIdx", "0");
							}
							if(!Double.IsNaN(update.updatedObjectiveValue)){
								XmlElement eUpdatedObjectiveValue = m_document.CreateElement("updatedObjectiveValue");
								if(update.updatedObjectiveValue == Double.PositiveInfinity){
									eUpdatedObjectiveValue.AppendChild(m_document.CreateTextNode("INF"));	
								}
								if(update.updatedObjectiveValue == Double.NegativeInfinity){
									eUpdatedObjectiveValue.AppendChild(m_document.CreateTextNode("-INF"));	
								}
								else{
									eUpdatedObjectiveValue.AppendChild(m_document.CreateTextNode(update.updatedObjectiveValue + ""));	
								}
								eUpdate.AppendChild(eUpdatedObjectiveValue);
							}
							if(!Double.IsNaN(update.updatedObjectiveLowerBound)){
								XmlElement eUpdatedObjectiveLowerBound = m_document.CreateElement("updatedObjectiveLowerBound");
								if(update.updatedObjectiveLowerBound == Double.PositiveInfinity){
									eUpdatedObjectiveLowerBound.AppendChild(m_document.CreateTextNode("INF"));	
								}
								if(update.updatedObjectiveLowerBound == Double.NegativeInfinity){
									eUpdatedObjectiveLowerBound.AppendChild(m_document.CreateTextNode("-INF"));	
								}
								else{
									eUpdatedObjectiveLowerBound.AppendChild(m_document.CreateTextNode(update.updatedObjectiveLowerBound + ""));	
								}
								eUpdate.AppendChild(eUpdatedObjectiveLowerBound);
							}
							if(!Double.IsNaN(update.updatedObjectiveUpperBound)){
								XmlElement eUpdatedObjectiveUpperBound = m_document.CreateElement("updatedObjectiveUpperBound");
								if(update.updatedObjectiveUpperBound == Double.PositiveInfinity){
									eUpdatedObjectiveUpperBound.AppendChild(m_document.CreateTextNode("INF"));	
								}
								if(update.updatedObjectiveUpperBound == Double.NegativeInfinity){
									eUpdatedObjectiveUpperBound.AppendChild(m_document.CreateTextNode("-INF"));	
								}
								else{
									eUpdatedObjectiveUpperBound.AppendChild(m_document.CreateTextNode(update.updatedObjectiveUpperBound + ""));	
								}
								eUpdate.AppendChild(eUpdatedObjectiveUpperBound);
							}

							if(update.updatedVariableValues != null && update.updatedVariableValues.var != null && update.updatedVariableValues.var.Length > 0){
								XmlElement eUpdatedVariableValues = m_document.CreateElement("updatedVariableValues");
								int iVars = update.updatedVariableValues.var.Length;
								for(int k = 0; k < iVars; k++){
									XmlElement eVar = m_document.CreateElement("var");
									if(update.updatedVariableValues.var[k] == Double.PositiveInfinity){
										eVar.AppendChild(m_document.CreateTextNode("INF"));	
									}
									else if(update.updatedVariableValues.var[k] == Double.NegativeInfinity){
										eVar.AppendChild(m_document.CreateTextNode("-INF"));	
									}
									else if(Double.IsNaN(update.updatedVariableValues.var[k])){
										eVar.AppendChild(m_document.CreateTextNode("NaN"));	
									}
									else{
										eVar.AppendChild(m_document.CreateTextNode(update.updatedVariableValues.var[k]+""));	
									}
									eUpdatedVariableValues.AppendChild(eVar);
								}						
								eUpdate.AppendChild(eUpdatedVariableValues);
							}

						
							if(update.updatedVariableValuesString != null && update.updatedVariableValuesString.var != null && update.updatedVariableValuesString.var.Length > 0){
								XmlElement eUpdatedVariableValuesString = m_document.CreateElement("updatedVariableValuesString");
								int iVars = update.updatedVariableValuesString.var.Length;
								for(int k = 0; k < iVars; k++){
									XmlElement eVar = m_document.CreateElement("var");
									eVar.AppendChild(m_document.CreateTextNode(update.updatedVariableValuesString.var[k]));	
									eUpdatedVariableValuesString.AppendChild(eVar);
								}						
								eUpdate.AppendChild(eUpdatedVariableValuesString);
							}

							if(update.updatedVariableReducedCosts != null && update.updatedVariableReducedCosts.var != null && update.updatedVariableReducedCosts.var.Length > 0){
								XmlElement eUpdatedVariableReducedCosts = m_document.CreateElement("updatedVariableReducedCosts");
								int iVars = update.updatedVariableReducedCosts.var.Length;
								for(int k = 0; k < iVars; k++){
									XmlElement eVar = m_document.CreateElement("var");
									if(update.updatedVariableReducedCosts.var[k] == Double.PositiveInfinity){
										eVar.AppendChild(m_document.CreateTextNode("INF"));	
									}
									else if(update.updatedVariableReducedCosts.var[k] == Double.NegativeInfinity){
										eVar.AppendChild(m_document.CreateTextNode("-INF"));	
									}
									else if(Double.IsNaN(update.updatedVariableReducedCosts.var[k])){
										eVar.AppendChild(m_document.CreateTextNode("NaN"));	
									}
									else{
										eVar.AppendChild(m_document.CreateTextNode(update.updatedVariableReducedCosts.var[k]+""));	
									}
									eUpdatedVariableReducedCosts.AppendChild(eVar);
								}						
								eUpdate.AppendChild(eUpdatedVariableReducedCosts);
							}

							if(update.updatedConstraintValues != null && update.updatedConstraintValues.con != null && update.updatedConstraintValues.con.Length > 0){
								XmlElement eUpdatedConstraintValues = m_document.CreateElement("updatedConstraintValues");
								int iCons = update.updatedConstraintValues.con.Length;
								for(int k = 0; k < iCons; k++){
									XmlElement eCon = m_document.CreateElement("con");
									if(update.updatedConstraintValues.con[k] == Double.PositiveInfinity){
										eCon.AppendChild(m_document.CreateTextNode("INF"));	
									}
									else if(update.updatedConstraintValues.con[k] == Double.NegativeInfinity){
										eCon.AppendChild(m_document.CreateTextNode("-INF"));	
									}
									else if(Double.IsNaN(update.updatedConstraintValues.con[k])){
										eCon.AppendChild(m_document.CreateTextNode("NaN"));	
									}
									else{
										eCon.AppendChild(m_document.CreateTextNode(update.updatedConstraintValues.con[k]+""));	
									}
									eUpdatedConstraintValues.AppendChild(eCon);
								}						
								eUpdate.AppendChild(eUpdatedConstraintValues);
							}

							if(update.updatedDualValues != null && update.updatedDualValues.con != null && update.updatedDualValues.con.Length > 0){
								XmlElement eUpdatedDualValues = m_document.CreateElement("updatedDualValues");
								int iCons = update.updatedDualValues.con.Length;
								for(int k = 0; k < iCons; k++){
									XmlElement eCon = m_document.CreateElement("con");
									if(update.updatedDualValues.con[k] == Double.PositiveInfinity){
										eCon.AppendChild(m_document.CreateTextNode("INF"));	
									}
									else if(update.updatedDualValues.con[k] == Double.NegativeInfinity){
										eCon.AppendChild(m_document.CreateTextNode("-INF"));	
									}
									else if(Double.IsNaN(update.updatedDualValues.con[k])){
										eCon.AppendChild(m_document.CreateTextNode("NaN"));	
									}
									else{
										eCon.AppendChild(m_document.CreateTextNode(update.updatedDualValues.con[k]+""));	
									}
									eUpdatedDualValues.AppendChild(eCon);
								}						
								eUpdate.AppendChild(eUpdatedDualValues);
							}
						
							eStandard.AppendChild(eUpdate);
						}
				
					}
					eJob.AppendChild(eStandard);
				}




				if(optimizationProcess.job[i].osrl != null){
					OSrLWriter osrlWriter = new OSrLWriter();
					try {
						osrlWriter.setOSResult(optimizationProcess.job[i].osrl);
					} 
					catch (Exception e) {
						Console.WriteLine(e.ToString());
						return false;
					}
					XmlElement eOSrL =  (XmlElement)m_document.ImportNode(osrlWriter.m_eOSrL, true);
					XMLUtil.removeAllAttributes(eOSrL);
					eJob.AppendChild(eOSrL);
				}
			}
			return true;
		}//setOptimizationProcess

		/// <summary>
		/// Set the other process related elements. 
		/// </summary>
		/// <param name="names">holds the names of the other processes. It is required. </param>
		/// <param name="values">holds the values of the other processes, empty string "" if no value for an process.</param>
		/// <param name="descriptions">holds the descriptions of the other processes, empty string "" if no value for an process, null for
		/// the entire array if none of the processes have descriptions.</param>
		/// <returns>whether the other processes element construction is successful.</returns>
		public bool setOtherProcesses(string[] names, string[] values, string[] descriptions){
			if(names == null) return false;
			if(values == null) return false;
			if(names.Length != values.Length) return false;
			if(descriptions != null && names.Length != descriptions.Length) return false;
			for(int i = 0; i < names.Length; i++){
				addOtherProcess(names[i], values[i], (descriptions==null)?"":descriptions[i]);
			}
			return true;
		}//setOtherProcesses


		/// <summary>
		/// Add an other process element. 
		/// </summary>
		/// <param name="name">holds the name of the other process element. It is required. </param>
		/// <param name="value">holds the value of the other process element, empty string "" if none. </param>
		/// <param name="description">holds the description of the other process element, empty string "" if none. </param>
		/// <returns>whether the other process element is added successfully.</returns>
		public bool addOtherProcess(string name, string value, string description){
			if(name == null) return false;
			ArrayList vNodeList = XMLUtil.getChildElementsByTagName(m_eProcessData, "other"); 
			int iNls = vNodeList==null?0:vNodeList.Count;
			XmlElement eOther;
			for(int i = 0; i < iNls; i++){
				eOther = (XmlElement)vNodeList[i];
				if(eOther.GetAttribute("name").Equals(name)){
					m_eProcessData.RemoveChild(eOther);
					break;
				}
			}
			eOther = createOther(name, value, description);
			m_eProcessData.AppendChild(eOther);
			return true;
		}//addOtherProcess

		/// <summary>
		/// Create the OSpL root element and its most basic required structure.
		/// </summary>
		/// <returns>the OSpL element.</returns>
		protected XmlElement createOSpLRoot(){
			XmlElement eOSpL = XMLUtil.createOSxLRootElement(m_document, "ospl");
			m_eProcessHeader = createProcessHeader();
			eOSpL.AppendChild(m_eProcessHeader);
			m_eProcessData = createProcessData();
			eOSpL.AppendChild(m_eProcessData);
			return eOSpL;
		}//createOSpLRoot

		/// <summary>
		/// Create the processHeader element and its most basic required structure.
		/// </summary>
		/// <returns>the processHeader element.</returns>
		protected XmlElement createProcessHeader(){
			XmlElement eProcessHeader = m_document.CreateElement("processHeader");
			return eProcessHeader;
		}//createProcessHeader

		/// <summary>
		/// Create the processData element and its most basic required structure.
		/// </summary>
		/// <returns>the processData element.</returns>
		protected XmlElement createProcessData(){
			XmlElement eProcessData = m_document.CreateElement("processData");
			return eProcessData;
		}//createProcessData

		/// <summary>
		/// Create the other element and its most basic required structure.
		/// </summary>
		/// <param name="name">the name of the other element. </param>
		/// <param name="value">the value of the other element, empty string "" if no value. </param>
		/// <param name="description">holds the description of the other process element, empty string "" if none. </param>
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
	}//class OSpLWriter
}//namespace
