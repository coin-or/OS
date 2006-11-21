using System;
using System.Collections;
using System.Xml;

using org.optimizationservices.oscommon.util;
using org.optimizationservices.oscommon.localinterface;
using org.optimizationservices.oscommon.datastructure.osbenchmark;

namespace org.optimizationservices.oscommon.representationparser{
	///	<summary>
	///	The	<c>OSbLReader</c> class	parses an OSbL instance	into a DOM tree	and
	///	provides a set of "get"	methods	that can be	
	///	used to	retrieve different pieces of information of	the	instance.
	///	@author	Jun	Ma	
	///	@version 1.0, 09/01/2005
	///	@since OS 1.0
	///	@copyright (c) 2005
	///	</summary>
	public class OSbLReader	: OSgLReader{

		/// <summary>
		/// m_osBenchmark holds the standard OSBenchmark, which is a local interface for 
		/// storing Optimization Services benchmark result. 
		/// </summary>
		protected OSBenchmark m_osBenchmark = null;

		///	<summary>
		///	m_otherBenchmarkHashMap holds a hash map of other alalyses.
		///	</summary>
		protected Hashtable	m_otherBenchmarkHashMap = null;

		///	<summary>
		///	m_otherBenchmarkDescriptionHashMap holds a hash map of other benchmarks' descriptions.
		///	</summary>
		protected Hashtable	m_otherBenchmarkDescriptionHashMap = null;

		///	<summary>
		///	constructor.
		///	</summary>
		///	<param name="validate">holds whether the reader	should be validating against the schema	or not.</param>
		public OSbLReader(bool validate){
			m_bXsdValidate = validate;
		}//constructor
	
		///	<summary>
		///	Default	constructor. 
		///	</summary>
		public OSbLReader(){
		}//constructor

		/// <summary>
		/// get the standard OSBenchmark, a local interface for 
		/// storing Optimization Services benchmark result.
		/// </summary>
		/// <returns>the OSBenchmark. </returns>
		public OSBenchmark getOSBenchmark(){
			if(m_osBenchmark != null){
				return m_osBenchmark;
			}
			m_osBenchmark = new OSBenchmark();		
			if(!m_osBenchmark.setServiceURI(getServiceURI())) throw new Exception("setServiceURI Unsuccessful");
			if(!m_osBenchmark.setServiceName(getServiceName())) throw new Exception("setServiceName Unsuccessful");
			if(!m_osBenchmark.setBenchmarkTime(getBenchmarkTime())) throw new Exception("setBenchmarkTime Unsuccessful");
			if(!m_osBenchmark.setBenchmarkMessage(getBenchmarkMessage())) throw new Exception("setBenchmarkMessage Unsuccessful");
			if(!m_osBenchmark.setBenchmarkScores(getBenchmarkScores())) throw new Exception("setBenchmarkScores Unsuccessful");
			if(!m_osBenchmark.setBenchmarkStatistics(getBenchmarkStatistics())) throw new Exception("setBenchmarkStatistics Unsuccessful");
			if(!m_osBenchmark.setOptimizationBenchmark(getOptimizationBenchmark())) throw new Exception("setOptimizationBenchmark Unsuccessful");
			if(!m_osBenchmark.setOtherBenchmarks(getOtherBenchmarkNames(), getOtherBenchmarkDescriptions(), getOtherBenchmarkValues())) throw new Exception("setOtherBenchmarks Unsuccessful");
			return m_osBenchmark;
		}//getOSBenchmark

		/// <summary>
		/// get the service uri
		/// </summary>
		/// <returns>the service uri</returns>
		public string getServiceURI(){
			XmlElement eBenchmarkHeader = (XmlElement)XMLUtil.findChildNode(m_eRoot, "benchmarkHeader");
			string sServiceURI = XMLUtil.getElementValueByName(eBenchmarkHeader, "serviceURI");
			if(sServiceURI == null) sServiceURI = "";
			return sServiceURI;
		}//getServiceURI

		/// <summary>
		/// get the service name
		/// </summary>
		/// <returns>the service name</returns>
		public string getServiceName(){
			XmlElement eBenchmarkHeader = (XmlElement)XMLUtil.findChildNode(m_eRoot, "benchmarkHeader");
			string sServiceName = XMLUtil.getElementValueByName(eBenchmarkHeader, "serviceName");
			if(sServiceName == null) sServiceName = "";
			return sServiceName;
		}//getServiceName

			
		/// <summary>
		/// Get time of the last benchmark.
		/// </summary>
		/// <returns>the time of the last benchmark.</returns>
		public DateTime getBenchmarkTime(){
			XmlElement eBenchmarkHeader = (XmlElement)XMLUtil.findChildNode(m_eRoot, "benchmarkHeader");
			string sTime = XMLUtil.getElementValueByName(eBenchmarkHeader, "time");
			if(sTime == null) return new DateTime(1970, 1, 1, 0, 0, 0);
			DateTime time = XMLUtil.createNativeDateTime(sTime);
			return time;
		}//getBenchmarkTime

		/// <summary>
		/// Get the benchmark message. 
		/// </summary>
		/// <returns>the benchmark message. </returns>
		public string getBenchmarkMessage(){
			XmlElement eBenchmarkHeader = (XmlElement)XMLUtil.findChildNode(m_eRoot, "benchmarkHeader");
			string sMessage = XMLUtil.getElementValueByName(eBenchmarkHeader, "message");
			if(sMessage == null) sMessage = "";
			return sMessage;	
		}//getBenchmarkMessage

		
		/// <summary>
		/// Get the benchmark scores. 
		/// </summary>
		/// <returns>the benchmark scores. </returns>
		public BenchmarkScores getBenchmarkScores(){
			XmlElement eBenchmarkData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "benchmarkData");
			XmlElement eScores = (XmlElement)XMLUtil.findChildNode(eBenchmarkData, "scores");
			if(eScores == null) return null;
			BenchmarkScores benchmarkScores = new BenchmarkScores();
			string sValue;
			sValue = XMLUtil.getElementValueByName(eScores, "overall");
			if(sValue != null && sValue.Length > 0){
				benchmarkScores.overall = Double.Parse(sValue);			
			}
			sValue = XMLUtil.getElementValueByName(eScores, "expertAssessment");
			if(sValue != null && sValue.Length > 0){
				benchmarkScores.expertAssessment = Double.Parse(sValue);			
			}
			sValue = XMLUtil.getElementValueByName(eScores, "userAssessment");
			if(sValue != null && sValue.Length > 0){
				benchmarkScores.userAssessment = Double.Parse(sValue);			
			}
			sValue = XMLUtil.getElementValueByName(eScores, "reputation");
			if(sValue != null && sValue.Length > 0){
				benchmarkScores.reputation = Double.Parse(sValue);			
			}
			sValue = XMLUtil.getElementValueByName(eScores, "popularity");
			if(sValue != null && sValue.Length > 0){
				benchmarkScores.popularity = Double.Parse(sValue);			
			}
			sValue = XMLUtil.getElementValueByName(eScores, "owner");
			if(sValue != null && sValue.Length > 0){
				benchmarkScores.owner = Double.Parse(sValue);			
			}
			sValue = XMLUtil.getElementValueByName(eScores, "support");
			if(sValue != null && sValue.Length > 0){
				benchmarkScores.support = Double.Parse(sValue);			
			}
			sValue = XMLUtil.getElementValueByName(eScores, "system");
			if(sValue != null && sValue.Length > 0){
				benchmarkScores.system = Double.Parse(sValue);			
			}
			sValue = XMLUtil.getElementValueByName(eScores, "service");
			if(sValue != null && sValue.Length > 0){
				benchmarkScores.service = Double.Parse(sValue);			
			}
			sValue = XMLUtil.getElementValueByName(eScores, "computation");
			if(sValue != null && sValue.Length > 0){
				benchmarkScores.computation = Double.Parse(sValue);			
			}
			return benchmarkScores;
		}//getBenchmarkScores

		/// <summary>
		/// Get the benchmark statistics.
		/// </summary>
		/// <returns>the benchmark statistics.</returns>
		public BenchmarkStatistics getBenchmarkStatistics(){
			XmlElement eBenchmarkData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "benchmarkData");
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(eBenchmarkData, "statistics");
			if(eStatistics == null) return null;
			BenchmarkStatistics benchmarkStatistics = new BenchmarkStatistics();
			string sValue;
			sValue = XMLUtil.getElementValueByName(eStatistics, "averageJobs");
			if(sValue != null && sValue.Length > 0){
				benchmarkStatistics.averageJobs = Double.Parse(sValue);			
			}
			sValue = XMLUtil.getElementValueByName(eStatistics, "averageWaitTime");
			if(sValue != null && sValue.Length > 0){
				benchmarkStatistics.averageWaitTime = Double.Parse(sValue);			
			}		
			sValue = XMLUtil.getElementValueByName(eStatistics, "averageServiceTime");
			if(sValue != null && sValue.Length > 0){
				benchmarkStatistics.averageServiceTime = Double.Parse(sValue);			
			}					
			return benchmarkStatistics;
		}//getBenchmarkStatistics

		/// <summary>
		/// Get the optimization benchmark information. 
		/// </summary>
		/// <returns>the optimization benchmark information. </returns>
		public OptimizationBenchmark getOptimizationBenchmark(){
			XmlElement eBenchmarkData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "benchmarkData");
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(eBenchmarkData, "optimization");
			if(eOptimization == null) return null;
			OptimizationBenchmark optimizationBenchmark = new OptimizationBenchmark();
			return optimizationBenchmark;
		}//getOptimizationBenchmark

		/// <summary>
		/// Get the hash map of other benchmarks. 
		/// </summary>
		/// <returns>the hash map of other benchmarks.</returns>
		public Hashtable getOtherBenchmarks(){
			if(m_otherBenchmarkHashMap != null) return m_otherBenchmarkHashMap;
			m_otherBenchmarkHashMap = new Hashtable();
			m_otherBenchmarkDescriptionHashMap = new Hashtable();

			XmlElement eBenchmarkData = (XmlElement)XMLUtil.findChildNode(m_eRoot, "benchmarkData");
			ArrayList vOtherElement = XMLUtil.getChildElementsByTagName(eBenchmarkData, "other");
			int iNls	= vOtherElement==null?0:vOtherElement.Count;
			for(int i = 0; i < iNls; i++){
				XmlElement eOther = (XmlElement)(vOtherElement[i]);
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
				m_otherBenchmarkHashMap.Add(sName, sValue);
				m_otherBenchmarkDescriptionHashMap.Add(sName, sDescription);
			}
			return m_otherBenchmarkHashMap;
		}//getOtherBenchmarks

		/// <summary>
		/// Get the number of other benchmarks.  
		/// </summary>
		/// <returns>the number of other benchmarks. </returns>
		public int getOtherBenchmarkNumber(){
			getOtherBenchmarks();
			return m_otherBenchmarkHashMap.Count;
		}//getOtherBenchmarkNumber

		/// <summary>
		/// Get the string value from the other benchmark hash map. 
		/// </summary>
		/// <param name="name">holds the name of benchmark to get. </param>
		/// <returns>string value from the other benchmark hash map, null if none. </returns>
		public string getOtherBenchmarkValueByName(string name){
			getOtherBenchmarks();
			if(m_otherBenchmarkHashMap.Contains(name)){
				return (string)m_otherBenchmarkHashMap[name];
			}
			else{ 
				return null;
			}
		}//getOtherBenchmarkValueByName

		/// <summary>
		/// Get the string value from the other benchmark hash map. 
		/// </summary>
		/// <param name="name">holds the name of benchmark to get. </param>
		/// <returns>string value from the other benchmark hash map, null if none. </returns>
		public string getOtherBenchmarkDescriptionByName(string name){
			getOtherBenchmarks();
			if(m_otherBenchmarkDescriptionHashMap.Contains(name)){
				return (string)m_otherBenchmarkDescriptionHashMap[name];
			}
			else{ 
				return null;
			}
		}//getOtherBenchmarkDescriptionByName

		/// <summary>
		/// Get the names of all other benchmarks. 
		/// </summary>
		/// <returns>the names of all other benchmarks. </returns>
		public string[] getOtherBenchmarkNames(){
			getOtherBenchmarks();	
			System.Collections.ICollection nameCollection = m_otherBenchmarkHashMap.Keys;
			string[] msName = new string[nameCollection.Count];
			IDictionaryEnumerator dictionaryEnumerator = m_otherBenchmarkHashMap.GetEnumerator();
			int i = 0;
			while(dictionaryEnumerator.MoveNext()){
				msName[i] = (string)dictionaryEnumerator.Key;
				i++;
			}
			return msName;
		}//getOtherBenchmarkNames

		/// <summary>
		/// Get the values of all other benchmarks. 
		/// </summary>
		/// <returns>the values of all other benchmarks. </returns>
		public string[] getOtherBenchmarkValues(){
			getOtherBenchmarks();	
			System.Collections.ICollection valueCollection = m_otherBenchmarkHashMap.Values;
			string[] msValue = new string[valueCollection.Count];
			IDictionaryEnumerator dictionaryEnumerator = m_otherBenchmarkHashMap.GetEnumerator();
			int i = 0;
			while(dictionaryEnumerator.MoveNext()){
				msValue[i] = (string)dictionaryEnumerator.Value;
				i++;
			}
			return msValue;
		}//getOtherBenchmarkValues

		/// <summary>
		/// Get the descriptions of all other benchmarks. 
		/// </summary>
		/// <returns>the descriptions of all other benchmarks. </returns>
		public string[] getOtherBenchmarkDescriptions(){
			getOtherBenchmarks();	
			System.Collections.ICollection descriptionCollection = m_otherBenchmarkDescriptionHashMap.Values;
			string[] msDescription = new string[descriptionCollection.Count];
			IDictionaryEnumerator dictionaryEnumerator = m_otherBenchmarkDescriptionHashMap.GetEnumerator();
			int i = 0;
			while(dictionaryEnumerator.MoveNext()){
				msDescription[i] = (string)dictionaryEnumerator.Value;
				i++;
			}
			return msDescription;
		}//getOtherBenchmarkDescriptions

	}//class OSbLReader
}//namespace