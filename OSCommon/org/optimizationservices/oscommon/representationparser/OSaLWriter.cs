using System;
using System.Xml;
using System.Collections;

using org.optimizationservices.oscommon.util;
using org.optimizationservices.oscommon.localinterface;
using org.optimizationservices.oscommon.datastructure.osanalysis;

namespace org.optimizationservices.oscommon.representationparser{
	/// <summary>
	/// The <c>OSaLWriter</c> class is used to construct an instance that follows 
	/// the OSaL format. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OSaLWriter : OSgLWriter{
		/// <summary>
		/// m_eOSaL holds the OSaL root element.
		/// </summary>
		protected internal XmlElement m_eOSaL = null;
			
		/// <summary>
		/// m_eAnalysisHeader holds the 1st child element analysisHeader of root element OSaL.
		/// </summary>
		protected XmlElement m_eAnalysisHeader = null;
	
		/// <summary>
		/// m_eAnalysisData holds the 2nd child element analysisData of root element OSaL.
		/// </summary>
		protected XmlElement m_eAnalysisData = null;

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
		/// constructor. 
		/// </summary>
		public OSaLWriter(){
			m_document = XMLUtil.createNewDocument();
			if(OSParameter.XSLT_LOCATION != null && OSParameter.XSLT_LOCATION.Length > 0){
				XmlProcessingInstruction xsltPI = m_document.CreateProcessingInstruction("xml-stylesheet",
					"type=\"text/xsl\" href = \"" + OSParameter.XSLT_LOCATION + "OSaL.xslt\"");
				m_document.AppendChild(xsltPI);     
			}
			m_eOSaL = createOSaLRoot();
			m_document.AppendChild(m_eOSaL);
		}//constructor

		/// <summary>
		/// set the OSAnalysis, a standard os analysis interface. 
		/// </summary>
		/// <param name="osAnalysis">holds the standard os analysis interface. </param>
		/// <returns>whether the OSAnalysis is set successfully. </returns>
		public bool setOSAnalysis(OSAnalysis osAnalysis){
			if(!setVariableNumber(osAnalysis.getVariableNumber())){ 
   				throw new Exception("setVariableNumber Unsuccessful");
			}
			if(!setObjectiveNumber(osAnalysis.getObjectiveNumber())){ 
   				throw new Exception("setObjectiveNumber Unsuccessful");
			}
			if(!setConstraintNumber(osAnalysis.getConstraintNumber())){ 
   				throw new Exception("setConstraintNumber Unsuccessful");
			}		
			if(!setAnalysisStatus(osAnalysis.getAnalysisStatus())){ 
   				throw new Exception("setAnalysisStatus Unsuccessful");
			}
			if(!setServiceURI(osAnalysis.getServiceURI())){ 
   				throw new Exception("setServiceURI Unsuccessful");
			}
			if(!setServiceName(osAnalysis.getServiceName())){ 
   				throw new Exception("setServiceName Unsuccessful");
			}
			if(!setInstanceName(osAnalysis.getInstanceName())){ 
   				throw new Exception("setInstanceName Unsuccessful");
			}
			if(!setJobID(osAnalysis.getJobID())){ 
   				throw new Exception("setJobID Unsuccessful");
			}
			if(!setAnalysisTime(osAnalysis.getAnalysisTime())){ 
   				throw new Exception("setAnalysisTime Unsuccessful");
			}
			if(!setAnalysisMessage(osAnalysis.getAnalysisMessage())){ 
   				throw new Exception("setAnalysisMessage Unsuccessful");
			}
			if(!setVariableAnalysis(osAnalysis.getVariableAnalysis())){ 
   				throw new Exception("setVariableAnalysis Unsuccessful");
			}
			if(!setObjectiveAnalysis(osAnalysis.getObjectiveAnalysis())){ 
   				throw new Exception("setObjectiveAnalysis Unsuccessful");
			}
			if(!setConstraintAnalysis(osAnalysis.getConstraintAnalysis())){ 
   				throw new Exception("setConstraintAnalysis Unsuccessful");
			}
			if(!setLinearConstraintCoefficientAnalysis(osAnalysis.getLinearConstraintCoefficientAnalysis())){ 
   				throw new Exception("setLinearConstraintCoefficientAnalysis Unsuccessful");
			}
			if(!setQuadraticCoefficientAnalysis(osAnalysis.getQuadraticCoefficientAnalysis())){ 
   				throw new Exception("setQuadraticCoefficientAnalysis Unsuccessful");
			}
			if(!setNonlinearExpressionAnalysis(osAnalysis.getNonlinearExpressionAnalysis())){ 
   				throw new Exception("setNonlinearExpressionAnalysis Unsuccessful");
			}
			if(osAnalysis.analysisData.other != null && osAnalysis.analysisData.other.Length > 0){
				int n = osAnalysis.analysisData.other.Length;
				string[] msNames = new string[n];
				string[] msValues = new string[n];
				string[] msDescriptions = new string[n];
				for(int i = 0; i < n; i++){
					msNames[i] = osAnalysis.analysisData.other[i].name;
					msValues[i] = osAnalysis.analysisData.other[i].value;
					msDescriptions[i] = osAnalysis.analysisData.other[i].description;
				}
				if(!setOtherAnalyses(msNames, msValues, msDescriptions)){
					throw new Exception("setOtherAnalyses Unsuccessful");
				}			
			}
   			return true;
		}//setOSAnalysis

		/// <summary>
		/// Set analysis status
		/// </summary>
		/// <param name="status">holds the analysis status.</param>
		/// <returns>whether the analysis status is set successfully. </returns>
		public bool setAnalysisStatus(AnalysisStatus status){
			try{
				if(status != null){
					XmlElement eStatus = (XmlElement)XMLUtil.findChildNode(m_eAnalysisHeader, "status");
					if(eStatus != null){
						m_eAnalysisHeader.RemoveChild(eStatus);
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
					m_eAnalysisHeader.InsertBefore(eStatus, m_eAnalysisHeader.FirstChild);
				}
				else{
					XMLUtil.removeChildrenByName(m_eAnalysisHeader, "status");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setAnalysisStatus

		/// <summary>
		/// Set service URI. 
		/// </summary>
		/// <param name="serviceURI">holds the service URI. </param>
		/// <returns>whether the service URI is set successfully.</returns>
		public bool setServiceURI(string serviceURI){
			try{
				XmlNode nodeRef = null;
				if(serviceURI != null && serviceURI.Length > 0){
					XmlElement eServiceURI = (XmlElement)XMLUtil.findChildNode(m_eAnalysisHeader, "serviceURI");
					if(eServiceURI == null){
						eServiceURI = m_document.CreateElement("serviceURI");					
						eServiceURI.AppendChild(m_document.CreateTextNode(serviceURI));
						nodeRef = XMLUtil.findChildNode(m_eAnalysisHeader, "serviceName");
						if(nodeRef == null){
							nodeRef = XMLUtil.findChildNode(m_eAnalysisHeader, "instanceName");
							if(nodeRef == null){
								nodeRef = XMLUtil.findChildNode(m_eAnalysisHeader, "jobID");
								if(nodeRef == null){
									nodeRef = XMLUtil.findChildNode(m_eAnalysisHeader, "time");
									if(nodeRef == null){
										nodeRef = XMLUtil.findChildNode(m_eAnalysisHeader, "message");
									}
								}
							}
						}
						m_eAnalysisHeader.InsertBefore(eServiceURI, nodeRef);
					}
					else{
						XMLUtil.setElementValue(eServiceURI, serviceURI);
					}
				}
				else{
					XMLUtil.removeChildrenByName(m_eAnalysisHeader, "serviceURI");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());;
				return false;
			}
			return true;
		}//setServiceURI

		/// <summary>
		/// Set service name. 
		/// </summary>
		/// <param name="serviceName">olds the service name. </param>
		/// <returns>whether the service name is set successfully.</returns>
		public bool setServiceName(string serviceName){
			try{
				XmlNode nodeRef = null;
				if(serviceName != null && serviceName.Length > 0){
					XmlElement eServiceName = (XmlElement)XMLUtil.findChildNode(m_eAnalysisHeader, "serviceName");
					if(eServiceName == null){
						eServiceName = m_document.CreateElement("serviceName");					
						eServiceName.AppendChild(m_document.CreateTextNode(serviceName));
						nodeRef = XMLUtil.findChildNode(m_eAnalysisHeader, "instanceName");
						if(nodeRef == null){
							nodeRef = XMLUtil.findChildNode(m_eAnalysisHeader, "jobID");
							if(nodeRef == null){
								nodeRef = XMLUtil.findChildNode(m_eAnalysisHeader, "time");
								if(nodeRef == null){
									nodeRef = XMLUtil.findChildNode(m_eAnalysisHeader, "message");
								}
							}
						}
						m_eAnalysisHeader.InsertBefore(eServiceName, nodeRef);
					}
					else{
						XMLUtil.setElementValue(eServiceName, serviceName);
					}
				}
				else{
					XMLUtil.removeChildrenByName(m_eAnalysisHeader, "serviceName");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());;
				return false;
			}
			return true;
		}//setServiceName

		/// <summary>
		/// Set instance name. 
		/// </summary>
		/// <param name="instanceName">holds the instance name. </param>
		/// <returns>whether the instance name is set successfully.</returns>
		public bool setInstanceName(string instanceName){
			try{
				XmlNode nodeRef = null;
				if(instanceName != null && instanceName.Length > 0){
					XmlElement eInstanceName = (XmlElement)XMLUtil.findChildNode(m_eAnalysisHeader, "instanceName");
					if(eInstanceName == null){
						eInstanceName = m_document.CreateElement("instanceName");					
						eInstanceName.AppendChild(m_document.CreateTextNode(instanceName));
						nodeRef = XMLUtil.findChildNode(m_eAnalysisHeader, "jobID");
						if(nodeRef == null){
							nodeRef = XMLUtil.findChildNode(m_eAnalysisHeader, "time");
							if(nodeRef == null){
								nodeRef = XMLUtil.findChildNode(m_eAnalysisHeader, "message");
							}
						}
						m_eAnalysisHeader.InsertBefore(eInstanceName, nodeRef);
					}
					else{
						XMLUtil.setElementValue(eInstanceName, instanceName);
					}
				}
				else{
					XMLUtil.removeChildrenByName(m_eAnalysisHeader, "instanceName");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());;
				return false;
			}
			return true;
		}//setInstanceName
		

		/// <summary>
		/// Set jobID.
		/// </summary>
		/// <param name="jobID">holds the jobID.</param>
		/// <returns>whether the jobID is set successfully.</returns>
		public bool setJobID(string jobID){
			try{
				XmlNode nodeRef = null;
				if(jobID != null && jobID.Length > 0){
					XmlElement eJobID = (XmlElement)XMLUtil.findChildNode(m_eAnalysisHeader, "jobID");
					if(eJobID == null){
						eJobID = m_document.CreateElement("jobID");					
						eJobID.AppendChild(m_document.CreateTextNode(jobID));
						nodeRef = XMLUtil.findChildNode(m_eAnalysisHeader, "time");
						if(nodeRef == null){
							nodeRef = XMLUtil.findChildNode(m_eAnalysisHeader, "message");
						}
						m_eAnalysisHeader.InsertBefore(eJobID, nodeRef);
					}
					else{
						XMLUtil.setElementValue(eJobID, jobID);
					}
				}
				else{
					XMLUtil.removeChildrenByName(m_eAnalysisHeader, "jobID");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());;
				return false;
			}
			return true;
		}//setJobID

		/// <summary>
		/// Set analysis time.
		/// </summary>
		/// <param name="time">holds the analysis time. </param>
		/// <returns>whether the analysis time is set successfully.</returns>
		public bool setAnalysisTime(DateTime time){
			try{
				XmlNode nodeRef = null;
				if(time.Year > 1970){
					XmlElement eTime = (XmlElement)XMLUtil.findChildNode(m_eAnalysisHeader, "time");
					if(eTime == null){
						eTime = m_document.CreateElement("time");					
						eTime.AppendChild(m_document.CreateTextNode(XMLUtil.createXSDateTime(time)));
						nodeRef = XMLUtil.findChildNode(m_eAnalysisHeader, "message");
						m_eAnalysisHeader.InsertBefore(eTime, nodeRef);
					}
					else{
						XMLUtil.setElementValue(eTime, XMLUtil.createXSDateTime(time));
					}
				}
				else{
					XMLUtil.removeChildrenByName(m_eAnalysisHeader, "time");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());;
				return false;
			}
			return true;
		}//setAnalysisTime

		/// <summary>
		/// Set analysis message. 
		/// </summary>
		/// <param name="message">holds the analysis message. </param>
		/// <returns>whether the analysis message is set successfully.</returns>
		public bool setAnalysisMessage(string message){
			try{
				XmlNode nodeRef = null;
				if(message != null && message.Length > 0){
					XmlElement eMessage = (XmlElement)XMLUtil.findChildNode(m_eAnalysisHeader, "message");
					if(eMessage == null){
						eMessage = m_document.CreateElement("message");					
						eMessage.AppendChild(m_document.CreateTextNode(message));
						m_eAnalysisHeader.InsertBefore(eMessage, nodeRef);
					}
					else{
						XMLUtil.setElementValue(eMessage, message);
					}
				}
				else{
					XMLUtil.removeChildrenByName(m_eAnalysisHeader, "message");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());;
				return false;
			}
			return true;
		}//setAnalysisMessage

		/// <summary>
		/// Set the variable number. 
		/// </summary>
		/// <param name="variableNumber">holds the number of variables</param>
		/// <returns>whether the variable number is set successfully or not. </returns>
		public bool setVariableNumber(int variableNumber){
			if(variableNumber < 0){
				return false;
			}
			m_iVariableNumber = variableNumber;
			try{
				m_eAnalysisData.SetAttribute("numberOfVariables", variableNumber+"");
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());;
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
				return false;
			}
			m_iObjectiveNumber = objectiveNumber;
			try{
				m_eAnalysisData.SetAttribute("numberOfObjectives", objectiveNumber+"");
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());;
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
				return false;
			}
			m_iConstraintNumber = constraintNumber;
			try{
				m_eAnalysisData.SetAttribute("numberOfConstraints", constraintNumber+"");
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());;
				return false;
			}
			return true;	
		}//setConstraintNumber

		/// <summary>
		/// Set analysis of the entire instance.
		/// Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
		/// methods have to be called first. 
		/// @see #setVariableNumber(int)
		/// @see #setObjectiveNumber(int)
		/// @see #setConstraintNumber(int)
		/// </summary>
		/// <param name="instanceAnalysis">holds the analysis of the entire instance.</param>
		/// <returns>whether the instanceAnalysis is set successfully.</returns>
		public bool setInstanceAnalysis(InstanceAnalysis instanceAnalysis){
			if(m_iVariableNumber <= 0 || m_iObjectiveNumber < 0 || m_iConstraintNumber< 0) return false;
			if(instanceAnalysis == null){
				XMLUtil.removeChildrenByName(m_eAnalysisData, "instance");
				return true;
			}
			XmlElement eInstance = (XmlElement)XMLUtil.findChildNode(m_eAnalysisData, "instance");
			if(eInstance != null){
				m_eAnalysisData.RemoveChild(eInstance);
			}
			eInstance = m_document.CreateElement("instance");
			//TODO
			m_eAnalysisData.InsertBefore(eInstance, m_eAnalysisData.FirstChild);
			return true;
		}//setInstanceAnalysis

		/// <summary>
		/// Set analysis of the variables.
		/// Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
		/// methods have to be called first. 
		/// @see #setVariableNumber(int)
		/// @see #setObjectiveNumber(int)
		/// @see #setConstraintNumber(int)
		/// </summary>
		/// <param name="variableAnalysis">holds the analysis of the variables.</param>
		/// <returns>whether the variableAnalysis is set successfully.</returns>
		public bool setVariableAnalysis(VariableAnalysis variableAnalysis){
			if(m_iVariableNumber <= 0 || m_iObjectiveNumber < 0 || m_iConstraintNumber< 0) return false;
			if(variableAnalysis == null){
				XMLUtil.removeChildrenByName(m_eAnalysisData, "variables");
				return true;
			}
			XmlElement eVariables = (XmlElement)XMLUtil.findChildNode(m_eAnalysisData, "variables");
			if(eVariables != null){
				m_eAnalysisData.RemoveChild(eVariables);
			}
			eVariables = m_document.CreateElement("variables");
			//TODO
			XmlNode nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "instance");
			if(nodeRef != null){
				m_eAnalysisData.InsertBefore(eVariables, nodeRef.NextSibling);			
			}
			else{
				m_eAnalysisData.InsertBefore(eVariables, m_eAnalysisData.FirstChild);
			}
			return true;
		}//setVariableAnalysis

		/// <summary>
		///  Set analysis of the objectives.
		///  Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
		///  methods have to be called first. 
		///  @see #setVariableNumber(int)
		///  @see #setObjectiveNumber(int)
		///  @see #setConstraintNumber(int)
		/// </summary>
		/// <param name="objectiveAnalysis">holds the analysis of the objectives.</param>
		/// <returns>whether the objectiveAnalysis is set successfully.</returns>
		public bool setObjectiveAnalysis(ObjectiveAnalysis objectiveAnalysis){
			if(m_iVariableNumber <= 0 || m_iObjectiveNumber < 0 || m_iConstraintNumber< 0) return false;
			if(objectiveAnalysis == null){
				XMLUtil.removeChildrenByName(m_eAnalysisData, "objectives");
				return true;
			}
			XmlElement eObjectives = (XmlElement)XMLUtil.findChildNode(m_eAnalysisData, "objectives");
			if(eObjectives != null){
				m_eAnalysisData.RemoveChild(eObjectives);
			}
			eObjectives = m_document.CreateElement("objectives");
			//TODO
			XmlNode nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "variables");
			if(nodeRef != null){
				m_eAnalysisData.InsertBefore(eObjectives, nodeRef.NextSibling);	
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "instance");
				if(nodeRef != null){
					m_eAnalysisData.InsertBefore(eObjectives, nodeRef.NextSibling);			
				}
				else{
					m_eAnalysisData.InsertBefore(eObjectives, m_eAnalysisData.FirstChild);
				}
			}
			return true;
		}//setObjectiveAnalysis

		/// <summary>
		/// Set analysis of the constraints.
		/// Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
		///  methods have to be called first. 
		/// @see #setVariableNumber(int)
		/// @see #setObjectiveNumber(int)
		/// @see #setConstraintNumber(int)
		/// </summary>
		/// <param name="constraintAnalysis">holds the analysis of the constraints.</param>
		/// <returns>whether the constraintAnalysis is set successfully.</returns>
		public bool setConstraintAnalysis(ConstraintAnalysis constraintAnalysis){
			if(m_iVariableNumber <= 0 || m_iObjectiveNumber < 0 || m_iConstraintNumber< 0) return false;
			if(constraintAnalysis == null){
				XMLUtil.removeChildrenByName(m_eAnalysisData, "constraints");
				return true;
			}
			XmlElement eConstraints = (XmlElement)XMLUtil.findChildNode(m_eAnalysisData, "constraints");
			if(eConstraints != null){
				m_eAnalysisData.RemoveChild(eConstraints);
			}
			eConstraints = m_document.CreateElement("constraints");
			//TODO
			XmlNode nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "objectives");
			if(nodeRef != null){
				m_eAnalysisData.InsertBefore(eConstraints, nodeRef.NextSibling);
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "variables");
				if(nodeRef != null){
					m_eAnalysisData.InsertBefore(eConstraints, nodeRef.NextSibling);	
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "instance");
					if(nodeRef != null){
						m_eAnalysisData.InsertBefore(eConstraints, nodeRef.NextSibling);			
					}
					else{
						m_eAnalysisData.InsertBefore(eConstraints, m_eAnalysisData.FirstChild);
					}
				}
			}
			return true;
		}//setConstraintAnalysis
		
		/// <summary>
		/// Set analysis of the linear constraint coefficients. 
		/// Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
		/// methods have to be called first. 
		/// @see #setVariableNumber(int)
		/// @see #setObjectiveNumber(int)
		/// @see #setConstraintNumber(int)
		/// </summary>
		/// <param name="linearConstraintCoefficientAnalysis">holds the analysis of the linear constraint coefficients.</param>
		/// <returns>whether the linearConstraintCoefficientAnalysis is set successfully.</returns>
		public bool setLinearConstraintCoefficientAnalysis(LinearConstraintCoefficientAnalysis linearConstraintCoefficientAnalysis){
			if(m_iVariableNumber <= 0 || m_iObjectiveNumber < 0 || m_iConstraintNumber< 0) return false;
			if(linearConstraintCoefficientAnalysis == null){
				XMLUtil.removeChildrenByName(m_eAnalysisData, "linearConstraintCoefficients");
				return true;
			}
			XmlElement eLinearConstraintCoefficients = (XmlElement)XMLUtil.findChildNode(m_eAnalysisData, "linearConstraintCoefficients");
			if(eLinearConstraintCoefficients != null){
				m_eAnalysisData.RemoveChild(eLinearConstraintCoefficients);
			}
			eLinearConstraintCoefficients = m_document.CreateElement("linearConstraintCoefficients");
			//TODO
			XmlNode nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "constraints");
			if(nodeRef != null){
				m_eAnalysisData.InsertBefore(eLinearConstraintCoefficients, nodeRef.NextSibling);
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "objectives");
				if(nodeRef != null){
					m_eAnalysisData.InsertBefore(eLinearConstraintCoefficients, nodeRef.NextSibling);
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "variables");
					if(nodeRef != null){
						m_eAnalysisData.InsertBefore(eLinearConstraintCoefficients, nodeRef.NextSibling);	
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "instance");
						if(nodeRef != null){
							m_eAnalysisData.InsertBefore(eLinearConstraintCoefficients, nodeRef.NextSibling);			
						}
						else{
							m_eAnalysisData.InsertBefore(eLinearConstraintCoefficients, m_eAnalysisData.FirstChild);
						}
					}
				}
			}
			return true;
		}//setLinearConstraintCoefficientAnalysis

		/// <summary>
		/// Set analysis of the entire quadratic coefficients.
		/// Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
		/// methods have to be called first. 
		/// @see #setVariableNumber(int)
		/// @see #setObjectiveNumber(int)
		/// @see #setConstraintNumber(int)
		/// </summary>
		/// <param name="quadraticCoefficientAnalysis">holds the analysis of the entire quadratic coefficients.</param>
		/// <returns>whether the quadraticCoefficientAnalysis is set successfully.</returns>
		public bool setQuadraticCoefficientAnalysis(QuadraticCoefficientAnalysis quadraticCoefficientAnalysis){
			if(m_iVariableNumber <= 0 || m_iObjectiveNumber < 0 || m_iConstraintNumber< 0) return false;
			if(quadraticCoefficientAnalysis == null){
				XMLUtil.removeChildrenByName(m_eAnalysisData, "quadraticCoefficients");
				return true;
			}
			XmlElement eQuadraticCoefficients = (XmlElement)XMLUtil.findChildNode(m_eAnalysisData, "quadraticCoefficients");
			if(eQuadraticCoefficients != null){
				m_eAnalysisData.RemoveChild(eQuadraticCoefficients);
			}
			eQuadraticCoefficients = m_document.CreateElement("quadraticCoefficients");
			//TODO
			XmlNode nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "linearConstraintCoefficients");
			if(nodeRef != null){
				m_eAnalysisData.InsertBefore(eQuadraticCoefficients, nodeRef.NextSibling);
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "constraints");
				if(nodeRef != null){
					m_eAnalysisData.InsertBefore(eQuadraticCoefficients, nodeRef.NextSibling);
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "objectives");
					if(nodeRef != null){
						m_eAnalysisData.InsertBefore(eQuadraticCoefficients, nodeRef.NextSibling);
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "variables");
						if(nodeRef != null){
							m_eAnalysisData.InsertBefore(eQuadraticCoefficients, nodeRef.NextSibling);	
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "instance");
							if(nodeRef != null){
								m_eAnalysisData.InsertBefore(eQuadraticCoefficients, nodeRef.NextSibling);			
							}
							else{
								m_eAnalysisData.InsertBefore(eQuadraticCoefficients, m_eAnalysisData.FirstChild);
							}
						}
					}
				}
			}
			return true;
		}//setQuadraticCoefficientAnalysis

		/// <summary>
		/// Set analysis of the entire nonlinear expressions.
		/// Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
		/// methods have to be called first.  
		/// @see #setVariableNumber(int)
		/// @see #setObjectiveNumber(int)
		/// @see #setConstraintNumber(int)
		/// </summary>
		/// <param name="nonlinearExpressionAnalysis"holds the analysis of the entire nonlinear expressions.></param>
		/// <returns>whether the nonlinearExpressionAnalysis is set successfully.</returns>
		public bool setNonlinearExpressionAnalysis(NonlinearExpressionAnalysis nonlinearExpressionAnalysis){
			if(m_iVariableNumber <= 0 || m_iObjectiveNumber < 0 || m_iConstraintNumber< 0) return false;
			if(nonlinearExpressionAnalysis == null){
				XMLUtil.removeChildrenByName(m_eAnalysisData, "nonlinearExpressions");
				return true;
			}
			XmlElement eNonlinearExpression = (XmlElement)XMLUtil.findChildNode(m_eAnalysisData, "nonlinearExpressions");
			if(eNonlinearExpression != null){
				m_eAnalysisData.RemoveChild(eNonlinearExpression);
			}
			eNonlinearExpression = m_document.CreateElement("nonlinearExpressions");
			//TODO

			XmlNode nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "quadraticCoefficients");
			if(nodeRef != null){
				m_eAnalysisData.InsertBefore(eNonlinearExpression, nodeRef.NextSibling);
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "linearConstraintCoefficients");
				if(nodeRef != null){
					m_eAnalysisData.InsertBefore(eNonlinearExpression, nodeRef.NextSibling);
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "constraints");
					if(nodeRef != null){
						m_eAnalysisData.InsertBefore(eNonlinearExpression, nodeRef.NextSibling);
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "objectives");
						if(nodeRef != null){
							m_eAnalysisData.InsertBefore(eNonlinearExpression, nodeRef.NextSibling);
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "variables");
							if(nodeRef != null){
								m_eAnalysisData.InsertBefore(eNonlinearExpression, nodeRef.NextSibling);	
							}
							else{
								nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "instance");
								if(nodeRef != null){
									m_eAnalysisData.InsertBefore(eNonlinearExpression, nodeRef.NextSibling);			
								}
								else{
									m_eAnalysisData.InsertBefore(eNonlinearExpression, m_eAnalysisData.FirstChild);
								}
							}
						}
					}
				}
			}
			return true;
		}//setNonlinearExpressionAnalysis

		/// <summary>
		/// Set the other analysis related elements. 
		/// Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
		/// methods have to be called first. 	    
		/// @see #setVariableNumber(int)
		/// @see #setObjectiveNumber(int)
		/// @see #setConstraintNumber(int)
		/// </summary>
		/// <param name="names">holds the names of the other analyses. It is required. </param>
		/// <param name="values">holds the values of the other analyses, empty string "" if no value for an analysis.</param>
		/// <param name="descriptions">holds the descriptions of the other analyses, empty string "" if no value for an analysis, null for
		/// the entire array if none of the analyses have descriptions.</param>
		/// <returns>whether the other analyses element construction is successful.</returns>
		public bool setOtherAnalyses(string[] names, string[] values, string[] descriptions){
			if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1) return false;
			if(names == null) return false;
			if(values == null) return false;
			if(names.Length != values.Length) return false;
			if(descriptions != null && names.Length != descriptions.Length) return false;
			for(int i = 0; i < names.Length; i++){
				addOtherAnalysis(names[i], values[i], (descriptions==null)?"":descriptions[i]);
			}
			return true;
		}//setOtherAnalyses


		/// <summary>
		/// Add an other analysis element. 
		/// Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
		/// methods have to be called first. 	    
		/// @see #setVariableNumber(int)
		/// @see #setObjectiveNumber(int)
		/// @see #setConstraintNumber(int)
		/// </summary>
		/// <param name="name">holds the name of the other analysis element. It is required. </param>
		/// <param name="value">holds the value of the other analysis element, empty string "" if none. </param>
		/// <param name="description">holds the description of the other analysis element, empty string "" if none. </param>
		/// <returns>whether the other analysis element is added successfully.</returns>
		public bool addOtherAnalysis(string name, string value, string description){
			if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1) return false;
			if(name == null) return false;
			
			ArrayList vNodeList = XMLUtil.getChildElementsByTagName(m_eAnalysisData, "other");
			int iNls = vNodeList==null?0:vNodeList.Count;
			XmlElement eOther;
			for(int i = 0; i < iNls; i++){
				eOther = (XmlElement)vNodeList[i];
				if(eOther.GetAttribute("name").Equals(name)){
					m_eAnalysisData.RemoveChild(eOther);
					break;
				}
			}
			eOther = createOther(name, value, description);
			m_eAnalysisData.AppendChild(eOther);
			return true;
		}//addOtherAnalysis

		/// <summary>
		/// Create the OSaL root element and its most basic required structure.
		/// </summary>
		/// <returns>the OSaL element.</returns>
		protected XmlElement createOSaLRoot(){
			XmlElement eOSaL = XMLUtil.createOSxLRootElement(m_document, "osal");
			m_eAnalysisHeader = createAnalysisHeader();
			eOSaL.AppendChild(m_eAnalysisHeader);
			m_eAnalysisData = createAnalysisData();
			eOSaL.AppendChild(m_eAnalysisData);
			return eOSaL;
		}//createOSaLRoot

		/// <summary>
		/// Create the analysisHeader element and its most basic required structure.
		/// </summary>
		/// <returns>the analysisHeader element.</returns>
		protected XmlElement createAnalysisHeader(){
			XmlElement eAnalysisHeader = m_document.CreateElement("analysisHeader");
			return eAnalysisHeader;
		}//createAnalysisHeader

		/// <summary>
		/// Create the analysisData element and its most basic required structure.
		/// </summary>
		/// <returns>the analysisData element.</returns>
		protected XmlElement createAnalysisData(){
			XmlElement eAnalysisData = m_document.CreateElement("analysisData");
			return eAnalysisData;
		}//createAnalysisHeader

		/// <summary>
		/// Create the other element and its most basic required structure.
		/// </summary>
		/// <param name="name">the name of the other element. </param>
		/// <param name="value">the value of the other element, empty string "" if no value. </param>
		/// <param name="description">holds the description of the other analysis element, empty string "" if none. </param>
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
	}//class OSaLWriter
}//namespace
