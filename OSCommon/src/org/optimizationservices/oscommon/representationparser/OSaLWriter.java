/**
 * @(#)OSaLWriter 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.representationparser;
import java.util.GregorianCalendar;
import java.util.Vector;

import org.optimizationservices.oscommon.datastructure.osanalysis.AnalysisStatus;
import org.optimizationservices.oscommon.datastructure.osanalysis.AnalysisSubstatus;
import org.optimizationservices.oscommon.datastructure.osanalysis.ConstraintAnalysis;
import org.optimizationservices.oscommon.datastructure.osanalysis.InstanceAnalysis;
import org.optimizationservices.oscommon.datastructure.osanalysis.LinearConstraintCoefficientAnalysis;
import org.optimizationservices.oscommon.datastructure.osanalysis.NonlinearExpressionAnalysis;
import org.optimizationservices.oscommon.datastructure.osanalysis.ObjectiveAnalysis;
import org.optimizationservices.oscommon.datastructure.osanalysis.QuadraticCoefficientAnalysis;
import org.optimizationservices.oscommon.datastructure.osanalysis.VariableAnalysis;
import org.optimizationservices.oscommon.localinterface.OSAnalysis;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.XMLUtil;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.ProcessingInstruction;
/**
 * The <code>OSaLWriter</code> class is used to construct an instance that follows 
 * the OSaL format. 
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */
public class OSaLWriter extends OSgLWriter{

	/**
	 * m_eOSaL holds the OSaL root element.
	 */
	protected Element m_eOSaL = null;
	
	/**
	 * m_eAnalysisHeader holds the 1st child element analysisHeader of root element OSaL.
	 */
	protected Element m_eAnalysisHeader = null;
	
	/**
	 * m_eAnalysisData holds the 2nd child element analyisisData of root element OSaL.
	 */
	protected Element m_eAnalysisData = null;


	/**
	 * m_iVariableNumber holds the variable number. 
	 */
	private int m_iVariableNumber = -1;
	
	/**
	 * m_iObjectiveNumber holds the objective number. 
	 */
	private int m_iObjectiveNumber = -1;
	
	/**
	 * m_iConstraintNumber holds the constraint number. 
	 */
	private int m_iConstraintNumber = -1;
	
	/**
	 * constructor. 
	 *
	 */
	public OSaLWriter(){
		m_document = XMLUtil.createNewDocument();
		if(OSParameter.XSLT_LOCATION != null && OSParameter.XSLT_LOCATION.length() > 0){
			ProcessingInstruction xsltPI = m_document.createProcessingInstruction("xml-stylesheet",
	           "type=\"text/xsl\" href = \"" + OSParameter.XSLT_LOCATION + "OSaL.xslt\"");
			m_document.appendChild(xsltPI);     
		}
		m_eOSaL = createOSaLRoot();
		m_document.appendChild(m_eOSaL);
	}//constructor

	/**
	 * set the OSAnalysis, a standard os analysis interface. 
	 * @param osAnalysis holds the standard os analysis interface. 
	 * @return whether the OSAnalysis is set successfully. 
	 */
	public boolean setOSAnalysis(OSAnalysis osAnalysis) throws Exception{
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
		if(osAnalysis.analysisData.other != null && osAnalysis.analysisData.other.length > 0){
			int n = osAnalysis.analysisData.other.length;
			String[] msNames = new String[n];
			String[] msValues = new String[n];
			String[] msDescriptions = new String[n];
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

   	/**
	 * Set analysis status
	 * 
	 * @param status holds the analysis status.
	 * @return whether the analysis status is set successfully. 
	 */
	public boolean setAnalysisStatus(AnalysisStatus status){
		try{
			if(status != null){
				Element eStatus = (Element)XMLUtil.findChildNode(m_eAnalysisHeader, "status");
				if(eStatus != null){
					m_eAnalysisHeader.removeChild(eStatus);
				}
				eStatus = m_document.createElement("status");
				if(status.type != null && status.type.length() > 0){
					eStatus.setAttribute("type", status.type);					
				}
				else{
					return false;
				}
				if(status.description != null && status.description.length() > 0){
					eStatus.setAttribute("description", status.description);					
				}
				if(status.substatus != null && status.substatus.length > 0){
					int iSubstatus = status.substatus.length;
					for(int i = 0; i < iSubstatus; i++){
						Element eSubstatus =  m_document.createElement("substatus");
						if(status.substatus[i].name != null && status.substatus[i].name.length() > 0){
							eSubstatus.setAttribute("name", status.substatus[i].name);
						}						
						if(status.substatus[i].description != null && status.substatus[i].description.length() > 0){
							eSubstatus.setAttribute("description", status.substatus[i].description);
						}						
						if(status.substatus[i].value != null && status.substatus[i].value.length() > 0){
							eSubstatus.appendChild(m_document.createTextNode(status.substatus[i].value));
						}
						eStatus.appendChild(eSubstatus);
					}					
				}
				m_eAnalysisHeader.insertBefore(eStatus, m_eAnalysisHeader.getFirstChild());
			}
			else{
				XMLUtil.removeChildrenByName(m_eAnalysisHeader, "status");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setAnalysisStatus
	
	/**
	 * Set service URI. 
	 * 
	 * @param serviceURI holds the service URI. 
	 * @return whether the service URI is set successfully.
	 */
	public boolean setServiceURI(String serviceURI){
		try{
			Node nodeRef = null;
			if(serviceURI != null && serviceURI.length() > 0){
				Element eServiceURI = (Element)XMLUtil.findChildNode(m_eAnalysisHeader, "serviceURI");
				if(eServiceURI == null){
					eServiceURI = m_document.createElement("serviceURI");					
					eServiceURI.appendChild(m_document.createTextNode(serviceURI));
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
					m_eAnalysisHeader.insertBefore(eServiceURI, nodeRef);
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
			e.printStackTrace();
			return false;
		}
		return true;
	}//setServiceURI

	/**
	 * Set service name. 
	 * 
	 * @param serviceName holds the service name. 
	 * @return whether the service name is set successfully.
	 */
	public boolean setServiceName(String serviceName){
		try{
			Node nodeRef = null;
			if(serviceName != null && serviceName.length() > 0){
				Element eServiceName = (Element)XMLUtil.findChildNode(m_eAnalysisHeader, "serviceName");
				if(eServiceName == null){
					eServiceName = m_document.createElement("serviceName");					
					eServiceName.appendChild(m_document.createTextNode(serviceName));
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
					m_eAnalysisHeader.insertBefore(eServiceName, nodeRef);
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
			e.printStackTrace();
			return false;
		}
		return true;
	}//setServiceName
	
	/**
	 * Set instance name. 
	 * 
	 * @param instanceName holds the instance name. 
	 * @return whether the instance name is set successfully.
	 */
	public boolean setInstanceName(String instanceName){
		try{
			Node nodeRef = null;
			if(instanceName != null && instanceName.length() > 0){
				Element eInstanceName = (Element)XMLUtil.findChildNode(m_eAnalysisHeader, "instanceName");
				if(eInstanceName == null){
					eInstanceName = m_document.createElement("instanceName");					
					eInstanceName.appendChild(m_document.createTextNode(instanceName));
					nodeRef = XMLUtil.findChildNode(m_eAnalysisHeader, "jobID");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(m_eAnalysisHeader, "time");
						if(nodeRef == null){
							nodeRef = XMLUtil.findChildNode(m_eAnalysisHeader, "message");
						}
					}
					m_eAnalysisHeader.insertBefore(eInstanceName, nodeRef);
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
			e.printStackTrace();
			return false;
		}
		return true;
	}//setInstanceName
	
	/**
	 * Set jobID.
	 * 
	 * @param jobID holds the jobID.
	 * @return whether the jobID is set successfully.
	 */
	public boolean setJobID(String jobID){
		try{
			Node nodeRef = null;
			if(jobID != null && jobID.length() > 0){
				Element eJobID = (Element)XMLUtil.findChildNode(m_eAnalysisHeader, "jobID");
				if(eJobID == null){
					eJobID = m_document.createElement("jobID");					
					eJobID.appendChild(m_document.createTextNode(jobID));
					nodeRef = XMLUtil.findChildNode(m_eAnalysisHeader, "time");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(m_eAnalysisHeader, "message");
					}
					m_eAnalysisHeader.insertBefore(eJobID, nodeRef);
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
			e.printStackTrace();
			return false;
		}
		return true;
	}//setJobID
	

	/**
	 * Set analysis time. 
	 * 
	 * @param time holds the analysis time. 
	 * @return whether the analysis time is set successfully.
	 */
	public boolean setAnalysisTime(GregorianCalendar time){
		try{
			Node nodeRef = null;
			if(time != null && time.get(GregorianCalendar.YEAR) > 1970){
				Element eTime = (Element)XMLUtil.findChildNode(m_eAnalysisHeader, "time");
				if(eTime == null){
					eTime = m_document.createElement("time");					
					eTime.appendChild(m_document.createTextNode(XMLUtil.createXSDateTime(time)));
					nodeRef = XMLUtil.findChildNode(m_eAnalysisHeader, "message");
					m_eAnalysisHeader.insertBefore(eTime, nodeRef);
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
			e.printStackTrace();
			return false;
		}
		return true;
	}//setAnalysisTime
	/**
	 * Set analysis message. 
	 * 
	 * @param message holds the analysis message. 
	 * @return whether the analysis message is set successfully.
	 */
	public boolean setAnalysisMessage(String message){
		try{
			Node nodeRef = null;
			if(message != null && message.length() > 0){
				Element eMessage = (Element)XMLUtil.findChildNode(m_eAnalysisHeader, "message");
				if(eMessage == null){
					eMessage = m_document.createElement("message");					
					eMessage.appendChild(m_document.createTextNode(message));
					m_eAnalysisHeader.insertBefore(eMessage, nodeRef);
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
			e.printStackTrace();
			return false;
		}
		return true;
	}//setAnalysisMessage
	
	/**
	 * Set the variable number. 
	 * 
	 * @param variableNumber holds the number of variables
	 * @return whether the variable number is set successfully or not. 
	 */
	public boolean setVariableNumber(int variableNumber){
		if(variableNumber < 0){
			return false;
		}
		m_iVariableNumber = variableNumber;
		try{
			m_eAnalysisData.setAttribute("numberOfVariables", variableNumber+"");
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
			return false;
		}
		m_iObjectiveNumber = objectiveNumber;
		try{
			m_eAnalysisData.setAttribute("numberOfObjectives", objectiveNumber+"");
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
			return false;
		}
		m_iConstraintNumber = constraintNumber;
		try{
			m_eAnalysisData.setAttribute("numberOfConstraints", constraintNumber+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;	
	}//setConstraintNumber

	/**
	 * Set analysis of the entire instance.
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods have to be called first. 
	 * @param instanceAnalysis holds the analysis of the entire instance.
	 * @return whether the instanceAnalysis is set successfully.
	 * @see #setVariableNumber(int)
	 * @see #setObjectiveNumber(int)
	 * @see #setConstraintNumber(int)
	 */
	public boolean setInstanceAnalysis(InstanceAnalysis instanceAnalysis){
		if(m_iVariableNumber <= 0 || m_iObjectiveNumber < 0 || m_iConstraintNumber< 0) return false;
		if(instanceAnalysis == null){
			XMLUtil.removeChildrenByName(m_eAnalysisData, "instance");
			return true;
		}
		Element eInstance = (Element)XMLUtil.findChildNode(m_eAnalysisData, "instance");
		if(eInstance != null){
			m_eAnalysisData.removeChild(eInstance);
		}
		eInstance = m_document.createElement("instance");
		//TODO
		m_eAnalysisData.insertBefore(eInstance, m_eAnalysisData.getFirstChild());
		return true;
	}//setInstanceAnalysis
	
	/**
	 * Set analysis of the variables.
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods have to be called first. 
	 * 
	 * @param variableAnalysis holds the analysis of the variables.
	 * @return whether the variableAnalysis is set successfully.
	 * @see #setVariableNumber(int)
	 * @see #setObjectiveNumber(int)
	 * @see #setConstraintNumber(int)
	 */
	public boolean setVariableAnalysis(VariableAnalysis variableAnalysis){
		if(m_iVariableNumber <= 0 || m_iObjectiveNumber < 0 || m_iConstraintNumber< 0) return false;
		if(variableAnalysis == null){
			XMLUtil.removeChildrenByName(m_eAnalysisData, "variables");
			return true;
		}
		Element eVariables = (Element)XMLUtil.findChildNode(m_eAnalysisData, "variables");
		if(eVariables != null){
			m_eAnalysisData.removeChild(eVariables);
		}
		eVariables = m_document.createElement("variables");
		//TODO
		Node nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "instance");
		if(nodeRef != null){
			m_eAnalysisData.insertBefore(eVariables, nodeRef.getNextSibling());			
		}
		else{
			m_eAnalysisData.insertBefore(eVariables, m_eAnalysisData.getFirstChild());
		}
		return true;
	}//setVariableAnalysis
	
	/**
	 * Set analysis of the objectives.
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods have to be called first. 
	 * 
	 * @param objectiveAnalysis holds the analysis of the objectives.
	 * @return whether the objectiveAnalysis is set successfully.
	 * @see #setVariableNumber(int)
	 * @see #setObjectiveNumber(int)
	 * @see #setConstraintNumber(int)
	 */
	public boolean setObjectiveAnalysis(ObjectiveAnalysis objectiveAnalysis){
		if(m_iVariableNumber <= 0 || m_iObjectiveNumber < 0 || m_iConstraintNumber< 0) return false;
		if(objectiveAnalysis == null){
			XMLUtil.removeChildrenByName(m_eAnalysisData, "objectives");
			return true;
		}
		Element eObjectives = (Element)XMLUtil.findChildNode(m_eAnalysisData, "objectives");
		if(eObjectives != null){
			m_eAnalysisData.removeChild(eObjectives);
		}
		eObjectives = m_document.createElement("objectives");
		//TODO
		Node nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "variables");
		if(nodeRef != null){
			m_eAnalysisData.insertBefore(eObjectives, nodeRef.getNextSibling());	
		}
		else{
			nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "instance");
			if(nodeRef != null){
				m_eAnalysisData.insertBefore(eObjectives, nodeRef.getNextSibling());			
			}
			else{
				m_eAnalysisData.insertBefore(eObjectives, m_eAnalysisData.getFirstChild());
			}
		}
		return true;
	}//setObjectiveAnalysis
	
	/**
	 * Set analysis of the constraints.
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods have to be called first. 
	 * 
	 * @param constraintAnalysis holds the analysis of the constraints.
	 * @return whether the constraintAnalysis is set successfully.
	 * @see #setVariableNumber(int)
	 * @see #setObjectiveNumber(int)
	 * @see #setConstraintNumber(int)
	 */
	public boolean setConstraintAnalysis(ConstraintAnalysis constraintAnalysis){
		if(m_iVariableNumber <= 0 || m_iObjectiveNumber < 0 || m_iConstraintNumber< 0) return false;
		if(constraintAnalysis == null){
			XMLUtil.removeChildrenByName(m_eAnalysisData, "constraints");
			return true;
		}
		Element eConstraints = (Element)XMLUtil.findChildNode(m_eAnalysisData, "constraints");
		if(eConstraints != null){
			m_eAnalysisData.removeChild(eConstraints);
		}
		eConstraints = m_document.createElement("constraints");
		//TODO
		Node nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "objectives");
		if(nodeRef != null){
			m_eAnalysisData.insertBefore(eConstraints, nodeRef.getNextSibling());
		}
		else{
			nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "variables");
			if(nodeRef != null){
				m_eAnalysisData.insertBefore(eConstraints, nodeRef.getNextSibling());	
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "instance");
				if(nodeRef != null){
					m_eAnalysisData.insertBefore(eConstraints, nodeRef.getNextSibling());			
				}
				else{
					m_eAnalysisData.insertBefore(eConstraints, m_eAnalysisData.getFirstChild());
				}
			}
		}
		return true;
	}//setConstraintAnalysis
	
	/**
	 * Set analysis of the linear constraint coefficients. 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods have to be called first. 
	 * 
	 * @param linearConstraintCoefficients holds the analysis of the linear constraint coefficients. 
	 * @return whether the linearConstraintCoefficientAnalysis is set successfully.
	 * @see #setVariableNumber(int)
	 * @see #setObjectiveNumber(int)
	 * @see #setConstraintNumber(int)
	 */
	public boolean setLinearConstraintCoefficientAnalysis(LinearConstraintCoefficientAnalysis linearConstraintCoefficientAnalysis){
		if(m_iVariableNumber <= 0 || m_iObjectiveNumber < 0 || m_iConstraintNumber< 0) return false;
		if(linearConstraintCoefficientAnalysis == null){
			XMLUtil.removeChildrenByName(m_eAnalysisData, "linearConstraintCoefficients");
			return true;
		}
		Element eLinearConstraintCoefficients = (Element)XMLUtil.findChildNode(m_eAnalysisData, "linearConstraintCoefficients");
		if(eLinearConstraintCoefficients != null){
			m_eAnalysisData.removeChild(eLinearConstraintCoefficients);
		}
		eLinearConstraintCoefficients = m_document.createElement("linearConstraintCoefficients");
		//TODO
		Node nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "constraints");
		if(nodeRef != null){
			m_eAnalysisData.insertBefore(eLinearConstraintCoefficients, nodeRef.getNextSibling());
		}
		else{
			nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "objectives");
			if(nodeRef != null){
				m_eAnalysisData.insertBefore(eLinearConstraintCoefficients, nodeRef.getNextSibling());
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "variables");
				if(nodeRef != null){
					m_eAnalysisData.insertBefore(eLinearConstraintCoefficients, nodeRef.getNextSibling());	
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "instance");
					if(nodeRef != null){
						m_eAnalysisData.insertBefore(eLinearConstraintCoefficients, nodeRef.getNextSibling());			
					}
					else{
						m_eAnalysisData.insertBefore(eLinearConstraintCoefficients, m_eAnalysisData.getFirstChild());
					}
				}
			}
		}
		return true;
	}//setLinearConstraintCoefficientAnalysis
	
	/**
	 * Set analysis of the entire quadratic coefficients.
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods have to be called first. 
	 * 
	 * @param quadraticCoefficientAnalysis holds the analysis of the entire quadratic coefficients.
	 * @return whether the quadraticCoefficientAnalysis is set successfully.
	 * @see #setVariableNumber(int)
	 * @see #setObjectiveNumber(int)
	 * @see #setConstraintNumber(int)
	 */
	public boolean setQuadraticCoefficientAnalysis(QuadraticCoefficientAnalysis quadraticCoefficientAnalysis){
		if(m_iVariableNumber <= 0 || m_iObjectiveNumber < 0 || m_iConstraintNumber< 0) return false;
		if(quadraticCoefficientAnalysis == null){
			XMLUtil.removeChildrenByName(m_eAnalysisData, "quadraticCoefficients");
			return true;
		}
		Element eQuadraticCoefficients = (Element)XMLUtil.findChildNode(m_eAnalysisData, "quadraticCoefficients");
		if(eQuadraticCoefficients != null){
			m_eAnalysisData.removeChild(eQuadraticCoefficients);
		}
		eQuadraticCoefficients = m_document.createElement("quadraticCoefficients");
		//TODO
		Node nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "linearConstraintCoefficients");
		if(nodeRef != null){
			m_eAnalysisData.insertBefore(eQuadraticCoefficients, nodeRef.getNextSibling());
		}
		else{
			nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "constraints");
			if(nodeRef != null){
				m_eAnalysisData.insertBefore(eQuadraticCoefficients, nodeRef.getNextSibling());
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "objectives");
				if(nodeRef != null){
					m_eAnalysisData.insertBefore(eQuadraticCoefficients, nodeRef.getNextSibling());
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "variables");
					if(nodeRef != null){
						m_eAnalysisData.insertBefore(eQuadraticCoefficients, nodeRef.getNextSibling());	
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "instance");
						if(nodeRef != null){
							m_eAnalysisData.insertBefore(eQuadraticCoefficients, nodeRef.getNextSibling());			
						}
						else{
							m_eAnalysisData.insertBefore(eQuadraticCoefficients, m_eAnalysisData.getFirstChild());
						}
					}
				}
			}
		}
		return true;
	}//setQuadraticCoefficientAnalysis
	
	/**
	 * Set analysis of the entire nonlinear expressions.
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods have to be called first. 
	 * 
	 * @param nonlinearExpressionAnalysis holds the analysis of the entire nonlinear expressions.
	 * @return whether the nonlinearExpressionAnalysis is set successfully.
	 * @see #setVariableNumber(int)
	 * @see #setObjectiveNumber(int)
	 * @see #setConstraintNumber(int)
	 */
	public boolean setNonlinearExpressionAnalysis(NonlinearExpressionAnalysis nonlinearExpressionAnalysis){
		if(m_iVariableNumber <= 0 || m_iObjectiveNumber < 0 || m_iConstraintNumber< 0) return false;
		if(nonlinearExpressionAnalysis == null){
			XMLUtil.removeChildrenByName(m_eAnalysisData, "nonlinearExpressions");
			return true;
		}
		Element eNonlinearExpression = (Element)XMLUtil.findChildNode(m_eAnalysisData, "nonlinearExpressions");
		if(eNonlinearExpression != null){
			m_eAnalysisData.removeChild(eNonlinearExpression);
		}
		eNonlinearExpression = m_document.createElement("nonlinearExpressions");
		//TODO

		Node nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "quadraticCoefficients");
		if(nodeRef != null){
			m_eAnalysisData.insertBefore(eNonlinearExpression, nodeRef.getNextSibling());
		}
		else{
			nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "linearConstraintCoefficients");
			if(nodeRef != null){
				m_eAnalysisData.insertBefore(eNonlinearExpression, nodeRef.getNextSibling());
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "constraints");
				if(nodeRef != null){
					m_eAnalysisData.insertBefore(eNonlinearExpression, nodeRef.getNextSibling());
				}
				else{
					nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "objectives");
					if(nodeRef != null){
						m_eAnalysisData.insertBefore(eNonlinearExpression, nodeRef.getNextSibling());
					}
					else{
						nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "variables");
						if(nodeRef != null){
							m_eAnalysisData.insertBefore(eNonlinearExpression, nodeRef.getNextSibling());	
						}
						else{
							nodeRef = XMLUtil.findChildNode(m_eAnalysisData, "instance");
							if(nodeRef != null){
								m_eAnalysisData.insertBefore(eNonlinearExpression, nodeRef.getNextSibling());			
							}
							else{
								m_eAnalysisData.insertBefore(eNonlinearExpression, m_eAnalysisData.getFirstChild());
							}
						}
					}
				}
			}
		}
		return true;
	}//setNonlinearExpressionAnalysis
	
	
	/**
	 * set other analyses, with their names (required), descriptions (optional) and values (optional). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods have to be called first. 
	 * 
	 * @param names holds the names of the other analyses; it is required.  
	 * @param descriptions holds the descriptions of the other analyses; null if none. 
	 * @param values holds the values of the other analyses; null if none. 
	 * @return whether the other anlysis information is set successfully. 
	 * @see #setVariableNumber(int)
	 * @see #setObjectiveNumber(int)
	 * @see #setConstraintNumber(int)
	 */
	public boolean setOtherAnalyses(String[] names, String[] values, String[] descriptions){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1) return false;
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1) return false;
		if(names == null) return false;
		if(values == null) return false;
		if(names.length != values.length) return false;
		if(descriptions != null && names.length != descriptions.length) return false;
		for(int i = 0; i < names.length; i++){
			addOtherAnalysis(names[i], values[i], (descriptions==null)?"":descriptions[i]);
		}
		return true;
	}//setOtherAnalyses
	
	/**
	 * Add an other analysis element. 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods have to be called first. 	 
	 *  
	 * @param name holds the name of the other analysis element. It is required. 
	 * @param value holds the value of the other analysis element, empty String "" if none.
	 * @param description holds the description of the other analysis element, empty String "" if none.
	 * @return whether the other analysis element is added successfully.
	 * @see #setVariableNumber(int)
	 * @see #setObjectiveNumber(int)
	 * @see #setConstraintNumber(int)
	 */
	public boolean addOtherAnalysis(String name, String value, String description){
		if(m_iVariableNumber == -1 || m_iObjectiveNumber == -1 || m_iConstraintNumber == -1) return false;
		if(name == null) return false;
		Vector<Element> vElements = XMLUtil.getChildElementsByTagName(m_eAnalysisData, "other");
		Element eOther;
		int iNls = vElements==null?0:vElements.size();
		for(int i = 0; i < iNls; i++){
			eOther = (Element)vElements.elementAt(i);
			if(eOther.getAttribute("name").equals(name)){
				m_eAnalysisData.removeChild(eOther);
				break;
			}
		}
		eOther = createOther(name, value, description);
		m_eAnalysisData.appendChild(eOther);
		return true;
	}//addOtherAnalysis

	
	/**
	 * Create the OSaL root element and its most basic required structure.
	 * 
	 * @return the OSaL element.
	 */
	protected Element createOSaLRoot(){
		Element eOSaL = XMLUtil.createOSxLRootElement(m_document, "osal");
		m_eAnalysisHeader = createAnalysisHeader();
		eOSaL.appendChild(m_eAnalysisHeader);
		m_eAnalysisData = createAnalysisData();
		eOSaL.appendChild(m_eAnalysisData);
		return eOSaL;
	}//createOSaLRoot
	
	/**
	 * Create the analysisHeader element and its most basic required structure.
	 * 
	 * @return the analysisHeader element.
	 */
	protected Element createAnalysisHeader(){
		Element eAnalysisHeader = m_document.createElement("analysisHeader");
		return eAnalysisHeader;
	}//createAnalysisHeader
	
	/**
	 * Create the analysisData element and its most basic required structure.
	 * 
	 * @return the analysisData element.
	 */
	protected Element createAnalysisData(){
		Element eAnalysisData = m_document.createElement("analysisData");
		return eAnalysisData;
	}//createAnalysisHeader

	
	/**
	 * Create the other element and its most basic required structure.
	 * @param name the name of the other element.
	 * @param value the value of the other element, empty String "" if no value.
	 * @param description holds the description of the other analysis element, empty String "" if none. 
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
		OSaLWriter osalWriter = new OSaLWriter();
		String sFileName = OSParameter.CODE_HOME + "OSRepository/test/osal/osal.osal";
		osalWriter.setVariableNumber(1);
		osalWriter.setObjectiveNumber(0);
		osalWriter.setConstraintNumber(0);
		AnalysisStatus status = new AnalysisStatus();
		status.type= "success";
		status.description = "my status description";
		AnalysisSubstatus[] substatuses = new AnalysisSubstatus[2];
		substatuses[0] = new AnalysisSubstatus();
		substatuses[0].name = "sub name 0";
		substatuses[0].description = "sub description 0";
		substatuses[0].value = "sub value 0";
		substatuses[1] = new AnalysisSubstatus();
		substatuses[1].name = "sub name 1";
		substatuses[1].description = "sub description 1";
		substatuses[1].value = "sub value 1";
		status.substatus = substatuses;
		if(!osalWriter.setAnalysisStatus(status)) System.out.println("status!");
		if(!osalWriter.setAnalysisMessage("my message")) System.out.println("message!");
		//if(!osalWriter.setAnalysisMessage("")) System.out.println("message!");
		if(!osalWriter.setInstanceName("my instance")) System.out.println("instance");
		if(!osalWriter.setServiceName("my service name")) System.out.println("service name");
		if(!osalWriter.setServiceURI("my service uri")) System.out.println("uri");
		if(!osalWriter.setJobID("my job ID")) System.out.println("job ID");
		if(!osalWriter.setAnalysisTime(new GregorianCalendar())) System.out.println("time!");
		
		if(!osalWriter.setInstanceAnalysis(new InstanceAnalysis())) System.out.println("instance analysis");
		if(!osalWriter.setVariableAnalysis(new VariableAnalysis())) System.out.println("variable analysis");
		if(!osalWriter.setObjectiveAnalysis(new ObjectiveAnalysis())) System.out.println("objective analysis");
		if(!osalWriter.setConstraintAnalysis(new ConstraintAnalysis())) System.out.println("constraint analysis");
		if(!osalWriter.setLinearConstraintCoefficientAnalysis(new LinearConstraintCoefficientAnalysis())) System.out.println("linearConstraintCoef analysis");
		if(!osalWriter.setQuadraticCoefficientAnalysis(new QuadraticCoefficientAnalysis())) System.out.println("quadraticCoef analysis");
		if(!osalWriter.setNonlinearExpressionAnalysis(null)) System.out.println("nonlinear expression analysis");
		if(!osalWriter.setNonlinearExpressionAnalysis(new NonlinearExpressionAnalysis())) System.out.println("nonlinear expression analysis");
		if(!osalWriter.setNonlinearExpressionAnalysis(new NonlinearExpressionAnalysis())) System.out.println("nonlinear expression analysis");
		
		String[] msOtherAnalysisNames = {"other name 0", "other name 1"};
		String[] msOtherAnalysisValues = {"other value 0", "other value 1"};
		if(!osalWriter.setOtherAnalyses(msOtherAnalysisNames, msOtherAnalysisValues, null)) System.out.println("set other!");
	
		if(!osalWriter.addOtherAnalysis("other name 2", "other value 2", null)) System.out.println("add other!");
		if(!osalWriter.addOtherAnalysis("other name 3", "other value 3", "other description 3")) System.out.println("add other!");

		///////////////////////
		
		OSaLReader osalReader = new OSaLReader(false);
		if(!osalReader.readFile(sFileName)) System.out.println("reading");
		OSAnalysis osAnalysis;
		try {
			osAnalysis = osalReader.getOSAnalysis();
			if(!osalWriter.setOSAnalysis(osAnalysis)) System.out.println("set osAnalysis");
		} 
		catch (Exception e) {
			e.printStackTrace();
		}
		///////////////////////
		
		//osalWriter.writeToStandardOutput();
		System.out.println(osalWriter.writeToString());
	}//main
	
}//class OSaLWriter
