using System;
using System.Collections;
using System.Xml;

using org.optimizationservices.oscommon.util;
using org.optimizationservices.oscommon.localinterface;
using org.optimizationservices.oscommon.datastructure.osanalysis;

namespace org.optimizationservices.oscommon.representationparser{
	///	<summary>
	///	The	<c>OSaLReader</c> class	parses an OSaL instance	into a DOM tree	and
	///	provides a set of "get"	methods	that can be	
	///	used to	retrieve different pieces of information of	the	instance.
	///	@author	Jun	Ma	
	///	@version 1.0, 09/01/2005
	///	@since OS 1.0
	///	@copyright (c) 2005
	///	</summary>
	public class OSaLReader	: OSgLReader{
		
		/// <summary>
		/// m_osAnalysis holds the standard OSAnalysis, which is a local interface for 
		/// storing Optimization Services analysis result. 
		/// </summary>
		protected OSAnalysis m_osAnalysis = null;

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

		///	<summary>
		///	m_otherAnalysisHashMap holds a hash map of other alalyses.
		///	</summary>
		protected Hashtable	m_otherAnalysisHashMap = null;

		///	<summary>
		///	m_otherAnalysisDescriptionHashMap holds a hash map of other analyses' descriptions.
		///	</summary>
		protected Hashtable	m_otherAnalysisDescriptionHashMap = null;

		///	<summary>
		///	constructor.
		///	</summary>
		///	<param name="validate">holds whether the reader	should be validating against the schema	or not.</param>
		public OSaLReader(bool validate){
			m_bXsdValidate = validate;
		}//constructor
	
		///	<summary>
		///	Default	constructor. 
		///	</summary>
		public OSaLReader(){
		}//constructor

		/// <summary>
		/// get the standard OSAnalysis, a local interface for storing Optimization Services analysis result.
		/// @throws Exception if there are errors getting the OSAnalysis. 
		/// </summary>
		/// <returns>the OSAnalysis. </returns>
   		public OSAnalysis getOSAnalysis(){
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

		/// <summary>
		/// Get analysis status
		/// </summary>
		/// <returns>analysis status, null if none. </returns>
		public AnalysisStatus getAnalysisStatus(){
			XmlElement eAnalysisHeader = (XmlElement)XMLUtil.findChildNode(m_eRoot, "analysisHeader");
			XmlElement eStatus = (XmlElement)XMLUtil.findChildNode(eAnalysisHeader, "status");
			if(eStatus == null) return null;
			AnalysisStatus status = new AnalysisStatus();
			string sStatusType = eStatus.GetAttribute("type");
			string sStatusDescription = eStatus.GetAttribute("description");
			status.type = sStatusType;
			status.description = sStatusDescription;
			XmlNodeList nodeList = eStatus.GetElementsByTagName("substatus");
			int iChildren = nodeList.Count;
			if(iChildren <= 0) return status;
			status.substatus = new AnalysisSubstatus[iChildren];
			for(int i = 0; i < iChildren; i++){
				status.substatus[i] = new AnalysisSubstatus();
				XmlElement eSubstatus = (XmlElement)(nodeList.Item(i));
				XmlNamedNodeMap attributes =  eSubstatus.Attributes;
				int n =attributes.Count;
				string sSubstatusName = "";
				string sSubstatusDescription = "";
				string sSubstatusValue = XMLUtil.getElementValue(eSubstatus);
				status.substatus[i].value = sSubstatusValue;
				for (int j = 0; j < n; j++) {
					XmlNode attr = attributes.Item(j);
					string sLocalName = attr.LocalName;
					string sValue = attr.Value;
					if (sLocalName.Equals("name")){
						sSubstatusName = sValue;
						status.substatus[i].name = sSubstatusName;
					}
					else if (sLocalName.Equals("description")){
						sSubstatusDescription = sValue;
						status.substatus[i].description = sSubstatusDescription;
					}
				}
			}
			return status;
		}//getAnalysisStatus

		/// <summary>
		/// Get service URI. 
		/// </summary>
		/// <returns>the service URI, null or empty string if none. </returns>
		public string getServiceURI(){
			XmlElement eAnalysisHeader = (XmlElement)XMLUtil.findChildNode(m_eRoot, "analysisHeader");
			string sServiceURI = XMLUtil.getElementValueByName(eAnalysisHeader, "serviceURI");
			if(sServiceURI == null) sServiceURI = "";
			return sServiceURI;	
		}//getServiceURI
		

		/// <summary>
		/// Get service name. 
		/// </summary>
		/// <returns>the service name, null or empty string if none. </returns>
		public string getServiceName(){
			XmlElement eAnalysisHeader = (XmlElement)XMLUtil.findChildNode(m_eRoot, "analysisHeader");
			string sServiceName = XMLUtil.getElementValueByName(eAnalysisHeader, "serviceName");
			if(sServiceName == null) sServiceName = "";
			return sServiceName;	
		}//getServiceName

		/// <summary>
		/// Get instance name. 
		/// </summary>
		/// <returns>the instance name, null or empty string if none. </returns>
		public string getInstanceName(){
			XmlElement eAnalysisHeader = (XmlElement)XMLUtil.findChildNode(m_eRoot, "analysisHeader");
			string sInstanceName = XMLUtil.getElementValueByName(eAnalysisHeader, "instanceName");
			if(sInstanceName == null) sInstanceName = "";
			return sInstanceName;	
		}//getInstanceName
	

		/// <summary>
		/// Get job ID. 
		/// </summary>
		/// <returns>the job ID, null or empty string if none. </returns>
		public string getJobID(){
			XmlElement eAnalysisHeader = (XmlElement)XMLUtil.findChildNode(m_eRoot, "analysisHeader");
			string sJobID = XMLUtil.getElementValueByName(eAnalysisHeader, "jobID");
			if(sJobID == null) sJobID = "";
			return sJobID;	
		}//getJobID

		/// <summary>
		/// Get analysis time. 
		/// </summary>
		/// <returns>the analysis time, null or empty string if none. </returns>
		public DateTime getAnalysisTime(){
			XmlElement eAnalysisHeader = (XmlElement)XMLUtil.findChildNode(m_eRoot, "analysisHeader");
			string sTime = XMLUtil.getElementValueByName(eAnalysisHeader, "time");
			if(sTime == null) return new DateTime(1970, 1, 1, 0, 0, 0);
			DateTime time = XMLUtil.createNativeDateTime(sTime);
			return time;	
		}//getAnalysisTime

		/// <summary>
		/// Get analysis message. 
		/// </summary>
		/// <returns>the analysis message, null or empty string if none. </returns>
		public string getAnalysisMessage(){
			XmlElement eAnalysisHeader = (XmlElement)XMLUtil.findChildNode(m_eRoot, "analysisHeader");
			string sMessage = XMLUtil.getElementValueByName(eAnalysisHeader, "message");
			if(sMessage == null) sMessage = "";
			return sMessage;	
		}//getAnalysisMessage

		/// <summary>
		/// Get variable number. 
		/// </summary>
		/// <returns>variable number, -1 if no information. </returns>
		public int getVariableNumber(){
			if(m_iVariableNumber == -1){
				XmlElement eAnalysisData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "analysisData");
				string sNumber =  eAnalysisData.GetAttribute("numberOfVariables");
				m_iVariableNumber = System.Convert.ToInt32(sNumber);
			}
			return m_iVariableNumber;
		}//getVariableNumber
		
		/// <summary>
		/// Get objective number. 
		/// </summary>
		/// <returns>objective number, -1 if no information. </returns>
		public int getObjectiveNumber(){
			if(m_iObjectiveNumber == -1){
				XmlElement eAnalysisData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "analysisData");
				string sNumber =  eAnalysisData.GetAttribute("numberOfObjectives");
				m_iObjectiveNumber = System.Convert.ToInt32(sNumber);
			}
			return m_iObjectiveNumber;
		}//getObjectiveNumber

		/// <summary>
		/// Get constraint number. 
		/// </summary>
		/// <returns>constraint number, -1 if no information. </returns>
		public int getConstraintNumber(){
			if(m_iConstraintNumber == -1){
				XmlElement eAnalysisData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "analysisData");
				string sNumber =  eAnalysisData.GetAttribute("numberOfConstraints");
				m_iConstraintNumber = System.Convert.ToInt32(sNumber);
			}
			return m_iConstraintNumber;
		}//getConstraintNumber

		/// <summary>
		/// get analysis of the entire instance. 
		/// </summary>
		/// <returns>InstanceAnalysis, null if none.</returns>
		public InstanceAnalysis getInstanceAnalysis(){
			XmlElement eAnalysisData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "analysisData");
			XmlElement eInstance = (XmlElement)XMLUtil.findChildNode(eAnalysisData, "instance");
			if(eInstance == null) return null;
			InstanceAnalysis instanceAnalysis = new InstanceAnalysis();
			//TODO
			return instanceAnalysis;
		}//getInstanceAnalysis


		/// <summary>
		/// get analysis of the variables
		/// </summary>
		/// <returns>VariableAnalysis, null if none.</returns>
		public VariableAnalysis getVariableAnalysis(){
			XmlElement eAnalysisData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "analysisData");
			XmlElement eVariables = (XmlElement)XMLUtil.findChildNode(eAnalysisData, "variables");
			if(eVariables == null) return null;
			VariableAnalysis variableAnalysis = new VariableAnalysis();
			//TODO
			return variableAnalysis;
		}//getVariableAnalysis

		/// <summary>
		///  get analysis of the objectives 
		/// </summary>
		/// <returns>ObjectiveAnalysis</returns>
		public ObjectiveAnalysis getObjectiveAnalysis(){
			XmlElement eAnalysisData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "analysisData");
			XmlElement eObjectives = (XmlElement)XMLUtil.findChildNode(eAnalysisData, "objectives");
			if(eObjectives == null) return null;
			ObjectiveAnalysis objectiveAnalysis = new ObjectiveAnalysis();
			//TODO
			return objectiveAnalysis;
		}//getObjectiveAnalysis	

		/// <summary>
		/// get analysis of the constraints 
		/// </summary>
		/// <returns>ConstraintAnalysis, null if none. </returns>
		public ConstraintAnalysis getConstraintAnalysis(){
			XmlElement eAnalysisData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "analysisData");
			XmlElement eConstraints = (XmlElement)XMLUtil.findChildNode(eAnalysisData, "constraints");
			if(eConstraints == null) return null;
			ConstraintAnalysis constraintAnalysis = new ConstraintAnalysis();
			//TODO
			return constraintAnalysis;
		}//getConstraintAnalysis

		/// <summary>
		/// get analysis of the linear constraint coefficients. 
		/// </summary>
		/// <returns>LinearConstraintCoefficientAnalysis</returns>
		public LinearConstraintCoefficientAnalysis getLinearConstraintCoefficientAnalysis(){
			XmlElement eAnalysisData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "analysisData");
			XmlElement eLinearConstraintCoefficients = (XmlElement)XMLUtil.findChildNode(eAnalysisData, "linearConstraintCoefficients");
			if(eLinearConstraintCoefficients == null) return null;
			LinearConstraintCoefficientAnalysis linearConstraintCoefficientAnalysis = new LinearConstraintCoefficientAnalysis();
			//TODO
			return linearConstraintCoefficientAnalysis;
		}//getLinearConstraintCoefficientsAnalysis

		/// <summary>
		/// get analysis of the entire quadratic coefficients. 
		/// </summary>
		/// <returns>QuadraticCoefficientAnalysis</returns>
		public QuadraticCoefficientAnalysis getQuadraticCoefficientAnalysis(){
			XmlElement eAnalysisData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "analysisData");
			XmlElement eQuadraticCoefficients = (XmlElement)XMLUtil.findChildNode(eAnalysisData, "quadraticCoefficients");
			if(eQuadraticCoefficients == null) return null;
			QuadraticCoefficientAnalysis quadraticCoefficientAnalysis = new QuadraticCoefficientAnalysis();
			//TODO
			return quadraticCoefficientAnalysis;
		}//getQuadraticCoefficientsAnalysis
		
		/// <summary>
		/// get analysis of the entire nonlinear expressions. 
		/// </summary>
		/// <returns>NonlinearExpressions</returns>
		public NonlinearExpressionAnalysis getNonlinearExpressionAnalysis(){
			XmlElement eAnalysisData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "analysisData");
			XmlElement eNonlinearExpressions = (XmlElement)XMLUtil.findChildNode(eAnalysisData, "nonlinearExpressions");
			if(eNonlinearExpressions == null) return null;
			NonlinearExpressionAnalysis nonlinearExpressionAnalysis = new NonlinearExpressionAnalysis();
			//TODO
			return nonlinearExpressionAnalysis;
		}//getNonlinearExpressionAnalysis


		/// <summary>
		/// Get the hash map of other analyses. 
		/// </summary>
		/// <returns>the hash map of other analyses.</returns>
		public Hashtable getOtherAnalyses(){
			if(m_otherAnalysisHashMap != null) return m_otherAnalysisHashMap;
			m_otherAnalysisHashMap = new Hashtable();
			m_otherAnalysisDescriptionHashMap = new Hashtable();

			XmlElement eAnalysisData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "analysisData");
			ArrayList vNodeList	= XMLUtil.getChildElementsByTagName(eAnalysisData, "other");
			int iNls = vNodeList==null?0:vNodeList.Count;
			for(int i = 0; i < iNls; i++){
				XmlElement eOther = (XmlElement)(vNodeList[i]);
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
				m_otherAnalysisHashMap.Add(sName, sValue);
				m_otherAnalysisDescriptionHashMap.Add(sName, sDescription);
			}
			return m_otherAnalysisHashMap;
		}//getOtherAnalyses

		/// <summary>
		/// Get the number of other analyses.  
		/// </summary>
		/// <returns>the number of other analyses. </returns>
		public int getOtherAnalysisNumber(){
			getOtherAnalyses();
			return m_otherAnalysisHashMap.Count;
		}//getOtherAnalysisNumber

		/// <summary>
		/// Get the string value from the other analysis hash map. 
		/// </summary>
		/// <param name="name">holds the name of analysis to get. </param>
		/// <returns>string value from the other analysis hash map, null if none. </returns>
		public string getOtherAnalysisValueByName(string name){
			getOtherAnalyses();
			if(m_otherAnalysisHashMap.Contains(name)){
				return (string)m_otherAnalysisHashMap[name];
			}
			else{ 
				return null;
			}
		}//getOtherAnalysisValueByName

		/// <summary>
		/// Get the string value from the other analysis hash map. 
		/// </summary>
		/// <param name="name">holds the name of analysis to get. </param>
		/// <returns>string value from the other analysis hash map, null if none. </returns>
		public string getOtherAnalysisDescriptionByName(string name){
			getOtherAnalyses();
			if(m_otherAnalysisDescriptionHashMap.Contains(name)){
				return (string)m_otherAnalysisDescriptionHashMap[name];
			}
			else{ 
				return null;
			}
		}//getOtherAnalysisDescriptionByName

		/// <summary>
		/// Get the names of all other analyses. 
		/// </summary>
		/// <returns>the names of all other analyses. </returns>
		public string[] getOtherAnalysisNames(){
			getOtherAnalyses();	
			System.Collections.ICollection nameCollection = m_otherAnalysisHashMap.Keys;
			string[] msName = new string[nameCollection.Count];
			IDictionaryEnumerator dictionaryEnumerator = m_otherAnalysisHashMap.GetEnumerator();
			int i = 0;
			while(dictionaryEnumerator.MoveNext()){
				msName[i] = (string)dictionaryEnumerator.Key;
				i++;
			}
			return msName;
		}//getOtherAnalysisNames

		/// <summary>
		/// Get the values of all other analyses. 
		/// </summary>
		/// <returns>the values of all other analyses. </returns>
		public string[] getOtherAnalysisValues(){
			getOtherAnalyses();	
			System.Collections.ICollection valueCollection = m_otherAnalysisHashMap.Values;
			string[] msValue = new string[valueCollection.Count];
			IDictionaryEnumerator dictionaryEnumerator = m_otherAnalysisHashMap.GetEnumerator();
			int i = 0;
			while(dictionaryEnumerator.MoveNext()){
				msValue[i] = (string)dictionaryEnumerator.Value;
				i++;
			}
			return msValue;
		}//getOtherAnalysisValues

		/// <summary>
		/// Get the descriptions of all other analyses. 
		/// </summary>
		/// <returns>the descriptions of all other analyses. </returns>
		public string[] getOtherAnalysisDescriptions(){
			getOtherAnalyses();	
			System.Collections.ICollection descriptionCollection = m_otherAnalysisDescriptionHashMap.Values;
			string[] msDescription = new string[descriptionCollection.Count];
			IDictionaryEnumerator dictionaryEnumerator = m_otherAnalysisDescriptionHashMap.GetEnumerator();
			int i = 0;
			while(dictionaryEnumerator.MoveNext()){
				msDescription[i] = (string)dictionaryEnumerator.Value;
				i++;
			}
			return msDescription;
		}//getOtherAnalysisDescriptions

	}//class OSaLReader
}//namespace