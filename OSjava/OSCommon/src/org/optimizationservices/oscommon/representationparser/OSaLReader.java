/**
 * @(#)OSaLReader 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.representationparser;

import java.util.Collection;
import java.util.GregorianCalendar;
import java.util.HashMap;
import java.util.Set;
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
import org.optimizationservices.oscommon.util.IOUtil;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.XMLUtil;
import org.w3c.dom.Element;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

/**
 * The <c>OSaLReader</c> class parses an OSaL instance into a DOM tree and
 * provides a set of "get" methods that can be used to retrieve different 
 * pieces of information of the instance.
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */
public class OSaLReader extends OSgLReader{
	/**
	 * m_osAnalysis holds the standard OSAnalysis, which is a local interface for 
	 * storing Optimization Services analysis result. 
	 */
	protected OSAnalysis m_osAnalysis = null;

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
	 * m_otherAnalysisHashMap holds a hash map of other alalyses.
	 */
	protected HashMap <String, String>	m_otherAnalysisHashMap = null;

	/**
	 * m_otherAnalysisDescriptionHashMap holds a hash map of other analyses' descriptions.
	 */
	protected HashMap <String, String>	m_otherAnalysisDescriptionHashMap = null;

	/**
	 * constructor.
	 * @param validate holds whether the reader	should be validating against the schema	or not.
	 */
	public OSaLReader(boolean validate){
		m_bXsdValidate = validate;
	}//constructor

	/**
	 * Default	constructor. 
	 *
	 */
	public OSaLReader(){
	}//constructor
	
	/**
	 * get the standard OSAnalysis, a local interface for 
	 * storing Optimization Services analysis result.
	 * 
	 * @return the OSAnalysis. 
	 * @throws Exception if there are errors getting the OSAnalysis. 
	 */
   	public OSAnalysis getOSAnalysis() throws Exception{
		if(m_osAnalysis != null){
			return m_osAnalysis;
		}
		m_osAnalysis = new OSAnalysis();		
		if(!m_osAnalysis.setAnalysisStatus(getAnalysisStatus())) throw new Exception("setAnalysis Unsuccessful");
		if(!m_osAnalysis.setServiceURI(getServiceURI())) throw new Exception("setServiceURI Unsuccessful");
		if(!m_osAnalysis.setServiceName(getServiceName())) throw new Exception("setServiceName Unsuccessful");
		if(!m_osAnalysis.setInstanceName(getInstanceName())) throw new Exception("setInstanceName Unsuccessful");
		if(!m_osAnalysis.setJobID(getJobID())) throw new Exception("setJobID Unsuccessful");
		if(!m_osAnalysis.setAnalysisTime(getAnalysisTime())) throw new Exception("setAnalysisTime Unsuccessful");
		if(!m_osAnalysis.setAnalysisMessage(getAnalysisMessage())) throw new Exception("setAnalysisMessage Unsuccessful");
		if(!m_osAnalysis.setVariableNumber(getVariableNumber())) throw new Exception("setVariableNumber Unsuccessful");
		if(!m_osAnalysis.setObjectiveNumber(getObjectiveNumber())) throw new Exception("setObjectiveNumber Unsuccessful");
		if(!m_osAnalysis.setConstraintNumber(getConstraintNumber())) throw new Exception("setConstraintNumber Unsuccessful");
		if(!m_osAnalysis.setInstanceAnalysis(getInstanceAnalysis())) throw new Exception("setInstanceAnalysis Unsuccessful");
		if(!m_osAnalysis.setVariableAnalysis(getVariableAnalysis())) throw new Exception("setVariableAnalysis Unsuccessful");
		if(!m_osAnalysis.setObjectiveAnalysis(getObjectiveAnalysis())) throw new Exception("setObjectiveeAnalysis Unsuccessful");
		if(!m_osAnalysis.setConstraintAnalysis(getConstraintAnalysis())) throw new Exception("setConstraintAnalysis Unsuccessful");
		if(!m_osAnalysis.setLinearConstraintCoefficientAnalysis(getLinearConstraintCoefficientAnalysis())) throw new Exception("setLinearConstraintCoefficients");
		if(!m_osAnalysis.setQuadraticCoefficientAnalysis(getQuadraticCoefficientAnalysis())) throw new Exception("setQuadraticCoefficientAnalysis Unsuccessful");
		if(!m_osAnalysis.setNonlinearExpressionAnalysis(getNonlinearExpressionAnalysis())) throw new Exception("setNonlinearExpressionAnalysis Unsuccessful");
		if(!m_osAnalysis.setOtherAnalyses(getOtherAnalysisNames(), getOtherAnalysisDescriptions(), getOtherAnalysisValues())) throw new Exception("setOtherAnalyses Unsuccessful");
		return m_osAnalysis;
   	}//getOSAnalysis
   	
   	/**
	 * Get analysis status
	 * 
	 * @return analysis status, null if none. 
	 */
	public AnalysisStatus getAnalysisStatus(){
		Element eAnalysisHeader = (Element)XMLUtil.findChildNode(m_eRoot, "analysisHeader");
		Element eStatus = (Element)XMLUtil.findChildNode(eAnalysisHeader, "status");
		if(eStatus == null) return null;
		AnalysisStatus status = new AnalysisStatus();
		String sStatusType = eStatus.getAttribute("type");
		String sStatusDescription = eStatus.getAttribute("description");
		status.type = sStatusType;
		status.description = sStatusDescription;
		NodeList nodeList = eStatus.getElementsByTagName("substatus");
		int iChildren = nodeList.getLength();
		if(iChildren <= 0) return status;
		status.substatus = new AnalysisSubstatus[iChildren];
		for(int i = 0; i < iChildren; i++){
			status.substatus[i] = new AnalysisSubstatus();
			Element eSubstatus = (Element)(nodeList.item(i));
			NamedNodeMap attributes =  eSubstatus.getAttributes();
			int n =attributes.getLength();
			String sSubstatusName = "";
			String sSubstatusDescription = "";
			String sSubstatusValue = XMLUtil.getElementValue(eSubstatus);
			status.substatus[i].value = sSubstatusValue;
			for (int j = 0; j < n; j++) {
				Node attr = attributes.item(j);
				String sLocalName = attr.getNodeName();
				String sValue = attr.getNodeValue();
				if (sLocalName.equals("name")){
					sSubstatusName = sValue;
					status.substatus[i].name = sSubstatusName;
				}
				else if (sLocalName.equals("description")){
					sSubstatusDescription = sValue;
					status.substatus[i].description = sSubstatusDescription;
				}
			}
		}
		return status;
	}//getAnalysisStatus
	
	/**
	 * Get service URI. 
	 * 
	 * @return the service URI, null or empty string if none. 
	 */
	public String getServiceURI(){
		Element eAnalysisHeader = (Element)XMLUtil.findChildNode(m_eRoot, "analysisHeader");
		String sServiceURI = XMLUtil.getElementValueByName(eAnalysisHeader, "serviceURI");
		if(sServiceURI == null) sServiceURI = "";
		return sServiceURI;	
	}//getServiceURI
	
	/**
	 * Get service name. 
	 * 
	 * @return the service name, null or empty string if none. 
	 */
	public String getServiceName(){
		Element eAnalysisHeader = (Element)XMLUtil.findChildNode(m_eRoot, "analysisHeader");
		String sServiceName = XMLUtil.getElementValueByName(eAnalysisHeader, "serviceName");
		if(sServiceName == null) sServiceName = "";
		return sServiceName;	
	}//getServiceName

	/**
	 * Get instance name. 
	 * 
	 * @return the instance name, null or empty string if none. 
	 */
	public String getInstanceName(){
		Element eAnalysisHeader = (Element)XMLUtil.findChildNode(m_eRoot, "analysisHeader");
		String sInstanceName = XMLUtil.getElementValueByName(eAnalysisHeader, "instanceName");
		if(sInstanceName == null) sInstanceName = "";
		return sInstanceName;	
	}//getInstanceName
	
	/**
	 * Get job ID. 
	 * 
	 * @return the job ID, null or empty string if none. 
	 */
	public String getJobID(){
		Element eAnalysisHeader = (Element)XMLUtil.findChildNode(m_eRoot, "analysisHeader");
		String sJobID = XMLUtil.getElementValueByName(eAnalysisHeader, "jobID");
		if(sJobID == null) sJobID = "";
		return sJobID;	
	}//getJobID

	/**
	 * Get analysis time. 
	 * 
	 * @return the analysis time, null or empty string if none. 
	 */
	public GregorianCalendar getAnalysisTime(){
		Element eAnalysisHeader = (Element)XMLUtil.findChildNode(m_eRoot, "analysisHeader");
		String sTime = XMLUtil.getElementValueByName(eAnalysisHeader, "time");
		if(sTime == null) return null;
		GregorianCalendar time = XMLUtil.createNativeDateTime(sTime);
		return time;	
	}//getAnalysisTime
	
	/**
	 * Get analysis message. 
	 * 
	 * @return the analysis message, null or empty string if none. 
	 */
	public String getAnalysisMessage(){
		Element eAnalysisHeader = (Element)XMLUtil.findChildNode(m_eRoot, "analysisHeader");
		String sMessage = XMLUtil.getElementValueByName(eAnalysisHeader, "message");
		if(sMessage == null) sMessage = "";
		return sMessage;	
	}//getAnalysisMessage
	
	/**
	 * Get variable number. 
	 * 
	 * @return variable number, -1 if no information. 
	 */
	public int getVariableNumber(){
		if(m_iVariableNumber == -1){
			Element eAnalysisData = (Element)XMLUtil.findChildNode(m_eRoot, "analysisData");
			String sNumber =  eAnalysisData.getAttribute("numberOfVariables");
			m_iVariableNumber = Integer.parseInt(sNumber);
		}
		return m_iVariableNumber;
	}//getVariableNumber
	
	/**
	 * Get objective number. 
	 * 
	 * @return objective number, -1 if no information. 
	 */
	public int getObjectiveNumber(){
		if(m_iObjectiveNumber == -1){
			Element eAnalysisData = (Element)XMLUtil.findChildNode(m_eRoot, "analysisData");
			String sNumber =  eAnalysisData.getAttribute("numberOfObjectives");
			m_iObjectiveNumber = Integer.parseInt(sNumber);
		}
		return m_iObjectiveNumber;
	}//getObjectiveNumber
	
	/**
	 * Get constraint number. 
	 * 
	 * @return constraint number, -1 if no information. 
	 */
	public int getConstraintNumber(){
		if(m_iConstraintNumber == -1){
			Element eAnalysisData = (Element)XMLUtil.findChildNode(m_eRoot, "analysisData");
			String sNumber =  eAnalysisData.getAttribute("numberOfConstraints");
			m_iConstraintNumber = Integer.parseInt(sNumber);
		}
		return m_iConstraintNumber;
	}//getConstraintNumber
	
	/**
	 * get analysis of the entire instance. 
	 * @return InstanceAnalysis, null if none.
	 */
	public InstanceAnalysis getInstanceAnalysis(){
		Element eAnalysisData = (Element)XMLUtil.findChildNode(m_eRoot, "analysisData");
		Element eInstance = (Element)XMLUtil.findChildNode(eAnalysisData, "instance");
		if(eInstance == null) return null;
		InstanceAnalysis instanceAnalysis = new InstanceAnalysis();
		//TODO
		return instanceAnalysis;
	}//getInstanceAnalysis
	

	/**
	 * get analysis of the variables 
	 * @return VariableAnalysis, null if none.
	 */
	public VariableAnalysis getVariableAnalysis(){
		Element eAnalysisData = (Element)XMLUtil.findChildNode(m_eRoot, "analysisData");
		Element eVariables = (Element)XMLUtil.findChildNode(eAnalysisData, "variables");
		if(eVariables == null) return null;
		VariableAnalysis variableAnalysis = new VariableAnalysis();
		//TODO
		return variableAnalysis;
	}//getVariableAnalysis
	
	/**
	 * get analysis of the objectives 
	 * @return ObjectiveAnalysis
	 */
	public ObjectiveAnalysis getObjectiveAnalysis(){
		Element eAnalysisData = (Element)XMLUtil.findChildNode(m_eRoot, "analysisData");
		Element eObjectives = (Element)XMLUtil.findChildNode(eAnalysisData, "objectives");
		if(eObjectives == null) return null;
		ObjectiveAnalysis objectiveAnalysis = new ObjectiveAnalysis();
		//TODO
		return objectiveAnalysis;
	}//getObjectiveAnalysis	
	
	/**
	 * get analysis of the constraints 
	 * @return ConstraintAnalysis, null if none. 
	 */
	public ConstraintAnalysis getConstraintAnalysis(){
		Element eAnalysisData = (Element)XMLUtil.findChildNode(m_eRoot, "analysisData");
		Element eConstraints = (Element)XMLUtil.findChildNode(eAnalysisData, "constraints");
		if(eConstraints == null) return null;
		ConstraintAnalysis constraintAnalysis = new ConstraintAnalysis();
		//TODO
		return constraintAnalysis;
	}//getConstraintAnalysis

	/**
	 * get analysis of the linear constraint coefficients. 
	 * @return LinearConstraintCoefficientAnalysis
	 */
	public LinearConstraintCoefficientAnalysis getLinearConstraintCoefficientAnalysis(){
		Element eAnalysisData = (Element)XMLUtil.findChildNode(m_eRoot, "analysisData");
		Element eLinearConstraintCoefficients = (Element)XMLUtil.findChildNode(eAnalysisData, "linearConstraintCoefficients");
		if(eLinearConstraintCoefficients == null) return null;
		LinearConstraintCoefficientAnalysis linearConstraintCoefficientAnalysis = new LinearConstraintCoefficientAnalysis();
		//TODO
		return linearConstraintCoefficientAnalysis;
	}//getLinearConstraintCoefficientsAnalysis
	
	/**
	 * get analysis of the entire quadratic coefficients. 
	 * @return QuadraticCoefficientAnalysis
	 */
	public QuadraticCoefficientAnalysis getQuadraticCoefficientAnalysis(){
		Element eAnalysisData = (Element)XMLUtil.findChildNode(m_eRoot, "analysisData");
		Element eQuadraticCoefficients = (Element)XMLUtil.findChildNode(eAnalysisData, "quadraticCoefficients");
		if(eQuadraticCoefficients == null) return null;
		QuadraticCoefficientAnalysis quadraticCoefficientAnalysis = new QuadraticCoefficientAnalysis();
		//TODO
		return quadraticCoefficientAnalysis;
	}//getQuadraticCoefficientsAnalysis
	
	/**
	 * get analysis of the entire nonlinear expressions. 
	 * @return NonlinearExpressions
	 */
	public NonlinearExpressionAnalysis getNonlinearExpressionAnalysis(){
		Element eAnalysisData = (Element)XMLUtil.findChildNode(m_eRoot, "analysisData");
		Element eNonlinearExpressions = (Element)XMLUtil.findChildNode(eAnalysisData, "nonlinearExpressions");
		if(eNonlinearExpressions == null) return null;
		NonlinearExpressionAnalysis nonlinearExpressionAnalysis = new NonlinearExpressionAnalysis();
		//TODO
		return nonlinearExpressionAnalysis;
	}//getNonlinearExpressionAnalysis
	
	/**
	 * Get the hash map of other analyses. 
	 * 
	 * @return the hash map of other analyses.
	 */
	public HashMap <String, String> getOtherAnalyses(){
		if(m_otherAnalysisHashMap != null) return m_otherAnalysisHashMap;
		m_otherAnalysisHashMap = new HashMap <String, String>();
		m_otherAnalysisDescriptionHashMap = new HashMap <String, String>();

		Element eAnalysisData = (Element)XMLUtil.findChildNode(m_eRoot, "analysisData");
		Vector<Element> vElements	= XMLUtil.getChildElementsByTagName(eAnalysisData, "other");
		int iNls	= vElements==null?0:vElements.size();
		for(int i = 0; i < iNls; i++){
			Element eOther = (Element)(vElements.elementAt(i));
			NamedNodeMap	attributes =  eOther.getAttributes();
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
			m_otherAnalysisHashMap.put(sName, sValue);
			m_otherAnalysisDescriptionHashMap.put(sName, sDescription);
		}
		return m_otherAnalysisHashMap;
	}//getOtherAnalyses
	
	/**
	 * Get the number of other analyses.  
	 * 
	 * @return the number of other analyses. 
	 */
	public int getOtherAnalysisNumber(){
		getOtherAnalyses();
		return m_otherAnalysisHashMap.size();
	}//getOtherAnalysisNumber

	/**
	 * Get the String value from the other analysis hash map. 
	 * 
	 * @param name holds the name of analysis to get. 
	 * @return String value from the other analysis hash map, null if none.
	 */
	public String getOtherAnalysisValueByName(String name){
		getOtherAnalyses();
		if(m_otherAnalysisHashMap.containsKey(name)){
			return (String)m_otherAnalysisHashMap.get(name);
		}
		else{ 
			return null;
		}
	}//getOtherAnalysisValueByName

	/**
	 * Get the String value from the other analysis hash map. 
	 * 
	 * @param name holds the name of analysis to get.
	 * @return String value from the other analysis hash map, null if none.
	 */
	public String getOtherAnalysisDescriptionByName(String name){
		getOtherAnalyses();
		if(m_otherAnalysisDescriptionHashMap.containsKey(name)){
			return (String)m_otherAnalysisDescriptionHashMap.get(name);
		}
		else{ 
			return null;
		}
	}//getOtherAnalysisDescriptionByName

	
	/**
	 * Get the names of all other analyses. 
	 * 
	 * @return the names of all other analyses.
	 */
	public String[] getOtherAnalysisNames(){
		getOtherAnalyses();	
		Set nameSet = m_otherAnalysisHashMap.keySet();
		Object[] moName = nameSet.toArray();
		String[] msName = new String[nameSet.size()];
		for (int i = 0; i < nameSet.size(); i++) {
			msName[i] = (String)moName[i];
		}
		return msName;		
	}//getOtherAnalysisNames
	
	/**
	 *  Get the values of all other analyses. 
	 * 
	 * @return the values of all other analyses. 
	 */
	public String[] getOtherAnalysisValues(){
		getOtherAnalyses();		
		Collection valueCollection = m_otherAnalysisHashMap.values();
		Object[] moValue = valueCollection.toArray();
		String[] msValue = new String[valueCollection.size()];
		for (int i = 0; i < valueCollection.size(); i++) {
			msValue[i] = (String)moValue[i];
		}
		return msValue;		
	}//getOtherAnalysisValues

	
	/**
	 * Get the descriptions of all other analyses. 
	 * 
	 * @return the descriptions of all other analyses.
	 */
	public String[] getOtherAnalysisDescriptions(){
		getOtherAnalyses();			
		Collection valueCollection = m_otherAnalysisDescriptionHashMap.values();
		Object[] moValue = valueCollection.toArray();
		String[] msDescription = new String[valueCollection.size()];
		for (int i = 0; i < valueCollection.size(); i++) {
			msDescription[i] = 
				moValue[i].toString();
		}
		return msDescription;		
	}//getOtherAnalysisDescriptions
	
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		OSaLReader osalReader = new OSaLReader(false);
		System.out.println(IOUtil.readStringFromFile(OSParameter.CODE_HOME + "OSRepository/test/osal/osal.osal"));
		System.out.println(osalReader.readFile(OSParameter.CODE_HOME + "OSRepository/test/osal/osal.osal"));
		System.out.println(osalReader.getAnalysisMessage());
		System.out.println(osalReader.getJobID());
		AnalysisStatus status = osalReader.getAnalysisStatus();
		System.out.println(status.type);
		System.out.println(status.description);
		int iSubstatus = status.substatus==null?0:status.substatus.length;
		for(int i = 0; i < iSubstatus; i++){
			System.out.println(status.substatus[i].name);
			System.out.println(status.substatus[i].description);
			System.out.println(status.substatus[i].value);			
		}
		System.out.println(XMLUtil.createXSDateTime(osalReader.getAnalysisTime()));
		System.out.println(osalReader.getInstanceName());
		System.out.println(osalReader.getServiceName());
		System.out.println(osalReader.getServiceURI());
		System.out.println(osalReader.getVariableNumber());	
		System.out.println(osalReader.getObjectiveNumber());
		System.out.println(osalReader.getConstraintNumber());
		osalReader.getInstanceAnalysis();
		osalReader.getVariableAnalysis();
		osalReader.getObjectiveAnalysis();
		osalReader.getConstraintAnalysis();
		osalReader.getLinearConstraintCoefficientAnalysis();
		osalReader.getQuadraticCoefficientAnalysis();
		osalReader.getNonlinearExpressionAnalysis();
		System.out.println(osalReader.getOtherAnalysisNumber());
		String sValue = osalReader.getOtherAnalysisValueByName("ad");
		if(sValue == null) System.out.println("null");
		else System.out.println(sValue);
		String sDescription = osalReader.getOtherAnalysisDescriptionByName("a");
		System.out.println(sDescription);
		for(int i=0;i<osalReader.getOtherAnalysisNumber();i++){
			System.out.println(osalReader.getOtherAnalysisNames()[i]);
			System.out.println(osalReader.getOtherAnalysisValues()[i]);
			System.out.println(osalReader.getOtherAnalysisDescriptions()[i]);
		}
		
		osalReader.writeToStandardOutput();
	}//main
	
}//class OSaLReader
