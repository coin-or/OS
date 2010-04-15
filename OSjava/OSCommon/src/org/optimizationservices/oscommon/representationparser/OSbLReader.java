/**
 * @(#)OSbLReader 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.representationparser;

import java.util.Collection;
import java.util.GregorianCalendar;
import java.util.HashMap;
import java.util.Set;
import java.util.Vector;

import org.optimizationservices.oscommon.datastructure.osbenchmark.BenchmarkScores;
import org.optimizationservices.oscommon.datastructure.osbenchmark.BenchmarkStatistics;
import org.optimizationservices.oscommon.datastructure.osbenchmark.OptimizationBenchmark;
import org.optimizationservices.oscommon.localinterface.OSBenchmark;
import org.optimizationservices.oscommon.util.IOUtil;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.XMLUtil;
import org.w3c.dom.Element;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;

/**
 * The <c>OSbLReader</c> class parses an OSbL instance into a DOM tree and
 * provides a set of "get" methods that can be used to retrieve different 
 * pieces of information of the instance.
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */
public class OSbLReader extends OSgLReader{
	/**
	 * m_osBenchmark holds the standard OSBenchmark, which is a local interface for 
	 * storing Optimization Services benchmark result. 
	 */
	protected OSBenchmark m_osBenchmark = null;
	
	/**
	 * m_otherBenchmarkHashMap holds a hash map of other alalyses.
	 */
	protected HashMap <String, String>	m_otherBenchmarkHashMap = null;

	/**
	 * m_otherBenchmarkDescriptionHashMap holds a hash map of other benchmarks' descriptions.
	 */
	protected HashMap <String, String>	m_otherBenchmarkDescriptionHashMap = null;

	/**
	 * constructor.
	 * @param validate holds whether the reader	should be validating against the schema	or not.
	 */
	public OSbLReader(boolean validate){
		m_bXsdValidate = validate;
	}//constructor

	/**
	 * Default	constructor. 
	 *
	 */
	public OSbLReader(){
	}//constructor
	
	/**
	 * get the standard OSBenchmark, a local interface for 
	 * storing Optimization Services benchmark result.
	 * 
	 * @return the OSBenchmark. 
	 * @throws Exception if there are errors getting the OSBenchmark. 
	 */
   	public OSBenchmark getOSBenchmark() throws Exception{
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
   	
	/**
	 * Get the service uri.
	 * @return the service uri
	 */
	public String getServiceURI(){
		Element eBenchmarkHeader = (Element)XMLUtil.findChildNode(m_eRoot, "benchmarkHeader");
		String sServiceURI = XMLUtil.getElementValueByName(eBenchmarkHeader, "serviceURI");
		if(sServiceURI == null) sServiceURI = "";
		return sServiceURI;	
	}//getServiceURI
	
	/**
	 * Get the service name.
	 * 
	 * @return the service name
	 */
	public String getServiceName(){
		Element eBenchmarkHeader = (Element)XMLUtil.findChildNode(m_eRoot, "benchmarkHeader");
		String sServiceName = XMLUtil.getElementValueByName(eBenchmarkHeader, "serviceName");
		if(sServiceName == null) sServiceName = "";
		return sServiceName;
	}//getServiceName
	
  	/**
	 * Get time of the last benchmark.
	 * 
	 * @return the time of the last benchmark.
	 */
	public GregorianCalendar getBenchmarkTime(){
		Element eBenchmarkHeader = (Element)XMLUtil.findChildNode(m_eRoot, "benchmarkHeader");
		String sTime = XMLUtil.getElementValueByName(eBenchmarkHeader, "time");
		if(sTime == null) return null;
		GregorianCalendar time = XMLUtil.createNativeDateTime(sTime);
		return time;	
	}//getBenchmarkTime
	
   	/**
	 * Get the benchmark message. 
	 * 
	 * @return the benchmark message. 
	 */
	public String getBenchmarkMessage(){
		Element eBenchmarkHeader = (Element)XMLUtil.findChildNode(m_eRoot, "benchmarkHeader");
		String sMessage = XMLUtil.getElementValueByName(eBenchmarkHeader, "message");
		if(sMessage == null) sMessage = "";
		return sMessage;
	}//getBenchmarkMessage
	
	/**
	 * Get the benchmark scores. 
	 * 
	 * @return the benchmark scores. 
	 */
	public BenchmarkScores getBenchmarkScores(){
		Element eBenchmarkData = (Element)XMLUtil.findChildNode(m_eRoot, "benchmarkData");
		Element eScores = (Element)XMLUtil.findChildNode(eBenchmarkData, "scores");
		if(eScores == null) return null;
		BenchmarkScores benchmarkScores = new BenchmarkScores();
		String sValue;
		sValue = XMLUtil.getElementValueByName(eScores, "overall");
		if(sValue != null && sValue.length() > 0){
			benchmarkScores.overall = Double.parseDouble(sValue);			
		}
		sValue = XMLUtil.getElementValueByName(eScores, "expertAssessment");
		if(sValue != null && sValue.length() > 0){
			benchmarkScores.expertAssessment = Double.parseDouble(sValue);			
		}
		sValue = XMLUtil.getElementValueByName(eScores, "userAssessment");
		if(sValue != null && sValue.length() > 0){
			benchmarkScores.userAssessment = Double.parseDouble(sValue);			
		}
		sValue = XMLUtil.getElementValueByName(eScores, "reputation");
		if(sValue != null && sValue.length() > 0){
			benchmarkScores.reputation = Double.parseDouble(sValue);			
		}
		sValue = XMLUtil.getElementValueByName(eScores, "popularity");
		if(sValue != null && sValue.length() > 0){
			benchmarkScores.popularity = Double.parseDouble(sValue);			
		}
		sValue = XMLUtil.getElementValueByName(eScores, "owner");
		if(sValue != null && sValue.length() > 0){
			benchmarkScores.owner = Double.parseDouble(sValue);			
		}
		sValue = XMLUtil.getElementValueByName(eScores, "support");
		if(sValue != null && sValue.length() > 0){
			benchmarkScores.support = Double.parseDouble(sValue);			
		}
		sValue = XMLUtil.getElementValueByName(eScores, "system");
		if(sValue != null && sValue.length() > 0){
			benchmarkScores.system = Double.parseDouble(sValue);			
		}
		sValue = XMLUtil.getElementValueByName(eScores, "service");
		if(sValue != null && sValue.length() > 0){
			benchmarkScores.service = Double.parseDouble(sValue);			
		}
		sValue = XMLUtil.getElementValueByName(eScores, "computation");
		if(sValue != null && sValue.length() > 0){
			benchmarkScores.computation = Double.parseDouble(sValue);			
		}
		return benchmarkScores;
	}//getBenchmarkScores
	
	/**
	 * Get the benchmark statistics. 
	 * 
	 * @return the benchmark statistics. 
	 */
	public BenchmarkStatistics getBenchmarkStatistics(){
		Element eBenchmarkData = (Element)XMLUtil.findChildNode(m_eRoot, "benchmarkData");
		Element eStatistics = (Element)XMLUtil.findChildNode(eBenchmarkData, "statistics");
		if(eStatistics == null) return null;
		BenchmarkStatistics benchmarkStatistics = new BenchmarkStatistics();
		String sValue;
		sValue = XMLUtil.getElementValueByName(eStatistics, "averageJobs");
		if(sValue != null && sValue.length() > 0){
			benchmarkStatistics.averageJobs = Double.parseDouble(sValue);			
		}
		sValue = XMLUtil.getElementValueByName(eStatistics, "averageWaitTime");
		if(sValue != null && sValue.length() > 0){
			benchmarkStatistics.averageWaitTime = Double.parseDouble(sValue);			
		}		
		sValue = XMLUtil.getElementValueByName(eStatistics, "averageServiceTime");
		if(sValue != null && sValue.length() > 0){
			benchmarkStatistics.averageServiceTime = Double.parseDouble(sValue);			
		}		
		return benchmarkStatistics;
	}//getBenchmarkStatistics
	
	/**
	 * Get the optimization benchmark information. 
	 * 
	 * @return the optimization benchmark information. 
	 */
	public OptimizationBenchmark getOptimizationBenchmark(){
		Element eBenchmarkData = (Element)XMLUtil.findChildNode(m_eRoot, "benchmarkData");
		Element eOptimization = (Element)XMLUtil.findChildNode(eBenchmarkData, "optimization");
		if(eOptimization == null) return null;
		OptimizationBenchmark optimizationBenchmark = new OptimizationBenchmark();
		return optimizationBenchmark;
	}//getOptimizationBenchmark
	
	/**
	 * Get the hash map of other benchmarks. 
	 * 
	 * @return the hash map of other benchmarks.
	 */
	public HashMap <String, String> getOtherBenchmarks(){
		if(m_otherBenchmarkHashMap != null) return m_otherBenchmarkHashMap;
		m_otherBenchmarkHashMap = new HashMap <String, String>();
		m_otherBenchmarkDescriptionHashMap = new HashMap <String, String>();
		Element eBenchmarkData = (Element)XMLUtil.findChildNode(m_eRoot, "benchmarkData");
		Vector<Element> vOtherElement = XMLUtil.getChildElementsByTagName(eBenchmarkData, "other");
		int iNls = vOtherElement==null?0:vOtherElement.size();
		for(int i = 0; i < iNls; i++){
			Element eOther = (Element)(vOtherElement.elementAt(i));
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
			m_otherBenchmarkHashMap.put(sName, sValue);
			m_otherBenchmarkDescriptionHashMap.put(sName, sDescription);
		}
		return m_otherBenchmarkHashMap;
	}//getOtherBenchmarks
		
	/**
	 * Get the number of other benchmarks.  
	 * 
	 * @return the number of other benchmarks. 
	 */
	public int getOtherBenchmarkNumber(){
		getOtherBenchmarks();
		return m_otherBenchmarkHashMap.size();
	}//getOtherBenchmarkNumber

	/**
	 * Get the String value from the other benchmark hash map. 
	 * 
	 * @param name holds the name of benchmark to get. 
	 * @return String value from the other benchmark hash map, null if none.
	 */
	public String getOtherBenchmarkValueByName(String name){
		getOtherBenchmarks();
		if(m_otherBenchmarkHashMap.containsKey(name)){
			return (String)m_otherBenchmarkHashMap.get(name);
		}
		else{ 
			return null;
		}
	}//getOtherBenchmarkValueByName

	/**
	 * Get the String value from the other benchmark hash map. 
	 * 
	 * @param name holds the name of benchmark to get.
	 * @return String value from the other benchmark hash map, null if none.
	 */
	public String getOtherBenchmarkDescriptionByName(String name){
		getOtherBenchmarks();
		if(m_otherBenchmarkDescriptionHashMap.containsKey(name)){
			return (String)m_otherBenchmarkDescriptionHashMap.get(name);
		}
		else{ 
			return null;
		}
	}//getOtherBenchmarkDescriptionByName

	
	/**
	 * Get the names of all other benchmarks. 
	 * 
	 * @return the names of all other benchmarks.
	 */
	public String[] getOtherBenchmarkNames(){
		getOtherBenchmarks();	
		Set nameSet = m_otherBenchmarkHashMap.keySet();
		Object[] moName = nameSet.toArray();
		String[] msName = new String[nameSet.size()];
		for (int i = 0; i < nameSet.size(); i++) {
			msName[i] = moName[i].toString();
		}
		return msName;		
	}//getOtherBenchmarkNames
	
	/**
	 *  Get the values of all other benchmarks. 
	 * 
	 * @return the values of all other benchmarks. 
	 */
	public String[] getOtherBenchmarkValues(){
		getOtherBenchmarks();		
		Collection valueCollection = m_otherBenchmarkHashMap.values();
		Object[] moValue = valueCollection.toArray();
		String[] msValue = new String[valueCollection.size()];
		for (int i = 0; i < valueCollection.size(); i++) {
			msValue[i] = moValue[i].toString();
		}
		return msValue;		
	}//getOtherBenchmarkValues

	
	/**
	 * Get the descriptions of all other benchmarks. 
	 * 
	 * @return the descriptions of all other benchmarks.
	 */
	public String[] getOtherBenchmarkDescriptions(){
		getOtherBenchmarks();			
		Collection valueCollection = m_otherBenchmarkDescriptionHashMap.values();
		Object[] moValue = valueCollection.toArray();
		String[] msDescription = new String[valueCollection.size()];
		for (int i = 0; i < valueCollection.size(); i++) {
			msDescription[i] = moValue[i].toString();
		}
		return msDescription;		
	}//getOtherBenchmarkDescriptions
	
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		OSbLReader osblReader = new OSbLReader(false);
		System.out.println(IOUtil.readStringFromFile(OSParameter.CODE_HOME + "OSRepository/test/osbl/osbl.osbl"));
		System.out.println(osblReader.readFile(OSParameter.CODE_HOME + "OSRepository/test/osbl/osbl.osbl"));
		System.out.println(osblReader.getBenchmarkMessage());
		System.out.println(XMLUtil.createXSDateTime(osblReader.getBenchmarkTime()));
		System.out.println(osblReader.getServiceName());
		System.out.println(osblReader.getServiceURI());
		BenchmarkScores benchmarkScores = osblReader.getBenchmarkScores();
		if(benchmarkScores != null){
			System.out.println(benchmarkScores.computation);
			System.out.println(benchmarkScores.expertAssessment);
			System.out.println(benchmarkScores.overall);
			System.out.println(benchmarkScores.owner);
			System.out.println(benchmarkScores.popularity);
			System.out.println(benchmarkScores.reputation);
			System.out.println(benchmarkScores.service);
			System.out.println(benchmarkScores.support);
			System.out.println(benchmarkScores.system);
			System.out.println(benchmarkScores.userAssessment);
		}
		BenchmarkStatistics benchmarkStatistics = osblReader.getBenchmarkStatistics();
		if(benchmarkStatistics != null){
			System.out.println(benchmarkStatistics.averageJobs);
			System.out.println(benchmarkStatistics.averageServiceTime);
			System.out.println(benchmarkStatistics.averageWaitTime);
		}
		osblReader.getOptimizationBenchmark();
		System.out.println(osblReader.getOtherBenchmarkNumber());
		String sValue = osblReader.getOtherBenchmarkValueByName("ad");
		if(sValue == null) System.out.println("null");
		else System.out.println(sValue);
		String sDescription = osblReader.getOtherBenchmarkDescriptionByName("a");
		System.out.println(sDescription);
		for(int i=0;i<osblReader.getOtherBenchmarkNumber();i++){
			System.out.println(osblReader.getOtherBenchmarkNames()[i]);
			System.out.println(osblReader.getOtherBenchmarkValues()[i]);
			System.out.println(osblReader.getOtherBenchmarkDescriptions()[i]);
		}
		
		osblReader.writeToStandardOutput();
	}//main
	
}//class OSbLReader
