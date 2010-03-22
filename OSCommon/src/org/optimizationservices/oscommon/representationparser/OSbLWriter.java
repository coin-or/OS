/**
 * @(#)OSbLWriter 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.representationparser;
import java.util.GregorianCalendar;
import java.util.Vector;

import org.optimizationservices.oscommon.datastructure.osbenchmark.BenchmarkScores;
import org.optimizationservices.oscommon.datastructure.osbenchmark.BenchmarkStatistics;
import org.optimizationservices.oscommon.datastructure.osbenchmark.OptimizationBenchmark;
import org.optimizationservices.oscommon.localinterface.OSBenchmark;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.XMLUtil;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.ProcessingInstruction;
/**
 * The <code>OSbLWriter</code> class is used to construct an instance that follows 
 * the OSbL format. 
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */
public class OSbLWriter extends OSgLWriter{

	/**
	 * m_eOSbL holds the OSbL root element.
	 */
	protected Element m_eOSbL = null;
	
	/**
	 * m_eBenchmarkHeader holds the 1st child element benchmarkHeader of root element OSbL.
	 */
	protected Element m_eBenchmarkHeader = null;
	
	/**
	 * m_eBenchmarkData holds the 2nd child element benchmarkData of root element OSbL.
	 */
	protected Element m_eBenchmarkData = null;
		
	/**
	 * constructor. 
	 *
	 */
	public OSbLWriter(){
		m_document = XMLUtil.createNewDocument();
		if(OSParameter.XSLT_LOCATION != null && OSParameter.XSLT_LOCATION.length() > 0){
			ProcessingInstruction xsltPI = m_document.createProcessingInstruction("xml-stylesheet",
	           "type=\"text/xsl\" href = \"" + OSParameter.XSLT_LOCATION + "OSbL.xslt\"");
			m_document.appendChild(xsltPI);     
		}
		m_eOSbL = createOSbLRoot();
		m_document.appendChild(m_eOSbL);
	}//constructor

	/**
	 * set the OSBenchmark, a standard os benchmark interface. 
	 * @param osBenchmark holds the standard os benchmark interface. 
	 * @return whether the OSBenchmark is set successfully. 
	 */
	public boolean setOSBenchmark(OSBenchmark osBenchmark) throws Exception{
		if(!setServiceURI(osBenchmark.getServiceURI())){ 
   			throw new Exception("setServiceURI Unsuccessful");
		}
		if(!setServiceName(osBenchmark.getServiceName())){ 
   			throw new Exception("setServiceName Unsuccessful");
		}
		if(!setBenchmarkTime(osBenchmark.getBenchmarkTime())){ 
   			throw new Exception("setBenchmarkTime Unsuccessful");
		}
		if(!setBenchmarkMessage(osBenchmark.getBenchmarkMessage())){ 
   			throw new Exception("setBenchmarkMessage Unsuccessful");
		}
		if(!setBenchmarkScores(osBenchmark.getBenchmarkScores())){ 
   			throw new Exception("setBenchmarkScores Unsuccessful");
		}
		if(!setBenchmarkStatistics(osBenchmark.getBenchmarkStatistics())){ 
   			throw new Exception("setBenchmarkStatistics Unsuccessful");
		}
		if(!setOptimizationBenchmark(osBenchmark.getOptimizationBenchmark())){ 
   			throw new Exception("setOptimizationBenchmark Unsuccessful");
		}
		if(osBenchmark.benchmarkData.other != null && osBenchmark.benchmarkData.other.length > 0){
			int n = osBenchmark.benchmarkData.other.length;
			String[] msNames = new String[n];
			String[] msValues = new String[n];
			String[] msDescriptions = new String[n];
			for(int i = 0; i < n; i++){
				msNames[i] = osBenchmark.benchmarkData.other[i].name;
				msValues[i] = osBenchmark.benchmarkData.other[i].value;
				msDescriptions[i] = osBenchmark.benchmarkData.other[i].description;
			}
			if(!setOtherBenchmarks(msNames, msValues, msDescriptions)){
				throw new Exception("setOtherBenchmarks Unsuccessful");
			}			
		}
   		return true;
	}//setOSBenchmark
	
	/**
	 * Set the service uri. If the element is already there, it will reset it. If the element 
	 * is not there (e.g. optional element), it will add it. 
	 * 
	 * @param serviceURI holds the service URI.
	 * @return whether the service uri is set successfully.
	 */
	public boolean setServiceURI(String serviceURI){		
		try{
			if(serviceURI != null && serviceURI.length() > 0){
				Element eServiceURI = (Element)XMLUtil.findChildNode(m_eBenchmarkHeader, "serviceURI");
				if(eServiceURI == null){
					eServiceURI = m_document.createElement("serviceURI");	
					eServiceURI.appendChild(m_document.createTextNode(serviceURI));
					m_eBenchmarkHeader.insertBefore(eServiceURI, m_eBenchmarkHeader.getFirstChild());				}
				else{
					XMLUtil.setElementValue(eServiceURI, serviceURI);
				}
			}
			else{
				XMLUtil.removeChildrenByName(m_eBenchmarkHeader, "serviceURI");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setServiceURI

	
	/**
	 * Set the service name. If the element is already there, it will reset it. If the element 
	 * is not there (e.g. optional element), it will add it. 
	 * 
	 * @param serviceName holds the service name.
	 * @return whether the service name is set successfully.
	 */
	public boolean setServiceName(String serviceName){
		try{
			Node nodeRef = null;
			if(serviceName != null && serviceName.length() > 0){
				Element eServiceName = (Element)XMLUtil.findChildNode(m_eBenchmarkHeader, "serviceName");
				if(eServiceName == null){
					eServiceName = m_document.createElement("serviceName");					
					eServiceName.appendChild(m_document.createTextNode(serviceName));
					nodeRef = XMLUtil.findChildNode(m_eBenchmarkHeader, "time");
					if(nodeRef == null){
						nodeRef = XMLUtil.findChildNode(m_eBenchmarkHeader, "message");
					}
					m_eBenchmarkHeader.insertBefore(eServiceName, nodeRef);
				}
				else{
					XMLUtil.setElementValue(eServiceName, serviceName);
				}
			}
			else{
				XMLUtil.removeChildrenByName(m_eBenchmarkHeader, "serviceName");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setServiceName
	
   	/**
	 * Set time of the last benchmark.
	 * 
	 * @param time holds the time of the last benchmark.
	 * @return whether benchmark time is set successfully. 
	 */
	public boolean setBenchmarkTime(GregorianCalendar time){
		try{
			Node nodeRef = null;
			if(time != null && time.get(GregorianCalendar.YEAR) > 1970){
				Element eTime = (Element)XMLUtil.findChildNode(m_eBenchmarkHeader, "time");
				if(eTime == null){
					eTime = m_document.createElement("time");					
					eTime.appendChild(m_document.createTextNode(XMLUtil.createXSDateTime(time)));
					nodeRef = XMLUtil.findChildNode(m_eBenchmarkHeader, "message");
					m_eBenchmarkHeader.insertBefore(eTime, nodeRef);
				}
				else{
					XMLUtil.setElementValue(eTime, XMLUtil.createXSDateTime(time));
				}
			}
			else{
				XMLUtil.removeChildrenByName(m_eBenchmarkHeader, "time");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setBenchmarkTime
	
   	/**
	 * Set the benchmark message. 
	 * 
	 * @param message holds the benchmark message. 
	 * @return whether benchmark message is set successfully. 
	 */
	public boolean setBenchmarkMessage(String message){
		try{
			Node nodeRef = null;
			if(message != null && message.length() > 0){
				Element eMessage = (Element)XMLUtil.findChildNode(m_eBenchmarkHeader, "message");
				if(eMessage == null){
					eMessage = m_document.createElement("message");					
					eMessage.appendChild(m_document.createTextNode(message));
					m_eBenchmarkHeader.insertBefore(eMessage, nodeRef);
				}
				else{
					XMLUtil.setElementValue(eMessage, message);
				}
			}
			else{
				XMLUtil.removeChildrenByName(m_eBenchmarkHeader, "message");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setBenchmarkMessage
	
	/**
	 * Set the benchmark scores. 
	 * 
	 * @param scores holds the benchmark scores. 
	 * @return whether the benchmark scores is set successfully. 
	 */
	public boolean setBenchmarkScores(BenchmarkScores scores){
		if(scores == null){
			XMLUtil.removeChildrenByName(m_eBenchmarkData, "scores");
			return true;
		}
		Element eScores = (Element)XMLUtil.findChildNode(m_eBenchmarkData, "scores");
		if(eScores != null){
			m_eBenchmarkData.removeChild(eScores);
		}
		eScores = m_document.createElement("scores");
		if(Double.isNaN(scores.overall)) return false;
		Element eOverall = m_document.createElement("overall");
		eOverall.appendChild(m_document.createTextNode(scores.overall + ""));
		eScores.appendChild(eOverall);
		if(!Double.isNaN(scores.expertAssessment)){
			Element eExpertAssessment = m_document.createElement("expertAssessment");
			eExpertAssessment.appendChild(m_document.createTextNode(scores.expertAssessment + ""));	
			eScores.appendChild(eExpertAssessment);
		}
		if(!Double.isNaN(scores.userAssessment)){
			Element eUserAssessment = m_document.createElement("userAssessment");			
			eUserAssessment.appendChild(m_document.createTextNode(scores.userAssessment + ""));			
			eScores.appendChild(eUserAssessment);
		}
		if(!Double.isNaN(scores.reputation)){
			Element eReputation = m_document.createElement("reputation");			
			eReputation.appendChild(m_document.createTextNode(scores.reputation + ""));			
			eScores.appendChild(eReputation);
		}
		if(!Double.isNaN(scores.popularity)){
			Element ePopularity = m_document.createElement("popularity");			
			ePopularity.appendChild(m_document.createTextNode(scores.popularity + ""));			
			eScores.appendChild(ePopularity);
		}
		if(!Double.isNaN(scores.owner)){
			Element eOwner = m_document.createElement("owner");			
			eOwner.appendChild(m_document.createTextNode(scores.owner + ""));			
			eScores.appendChild(eOwner);
		}
		if(!Double.isNaN(scores.support)){
			Element eSupport = m_document.createElement("support");			
			eSupport.appendChild(m_document.createTextNode(scores.support + ""));			
			eScores.appendChild(eSupport);
		}
		if(!Double.isNaN(scores.system)){
			Element eSystem = m_document.createElement("system");			
			eSystem.appendChild(m_document.createTextNode(scores.system + ""));			
			eScores.appendChild(eSystem);
		}
		if(!Double.isNaN(scores.service)){
			Element eService = m_document.createElement("service");			
			eService.appendChild(m_document.createTextNode(scores.service + ""));			
			eScores.appendChild(eService);
		}
		if(!Double.isNaN(scores.computation)){
			Element eComputation = m_document.createElement("computation");			
			eComputation.appendChild(m_document.createTextNode(scores.computation + ""));			
			eScores.appendChild(eComputation);
		}
		m_eBenchmarkData.insertBefore(eScores, m_eBenchmarkData.getFirstChild());
		return true;
	}//setBenchmarkScores
	
	/**
	 * Set the benchmark statistics. 
	 * 
	 * @param benchmarkStatistics holds the benchmark statistics. 
	 * @return whether the benchmark statistics is set successfully. 
	 */
	public boolean setBenchmarkStatistics(BenchmarkStatistics benchmarkStatistics){
		if(benchmarkStatistics == null){
			XMLUtil.removeChildrenByName(m_eBenchmarkData, "statistics");
			return true;
		}
		Element eStatistics = (Element)XMLUtil.findChildNode(m_eBenchmarkData, "statistics");
		if(eStatistics != null){
			m_eBenchmarkData.removeChild(eStatistics);
		}
		eStatistics = m_document.createElement("statistics");		
		if(!Double.isNaN(benchmarkStatistics.averageJobs)){
			Element eAverageJobs = m_document.createElement("averageJobs");			
			eAverageJobs.appendChild(m_document.createTextNode(benchmarkStatistics.averageJobs + ""));			
			eStatistics.appendChild(eAverageJobs);
		}
		if(!Double.isNaN(benchmarkStatistics.averageWaitTime)){
			Element eAverageWaitTime = m_document.createElement("averageWaitTime");			
			eAverageWaitTime.appendChild(m_document.createTextNode(benchmarkStatistics.averageWaitTime + ""));			
			eStatistics.appendChild(eAverageWaitTime);
		}
		if(!Double.isNaN(benchmarkStatistics.averageServiceTime)){
			Element eAverageServiceTime = m_document.createElement("averageServiceTime");			
			eAverageServiceTime.appendChild(m_document.createTextNode(benchmarkStatistics.averageServiceTime + ""));			
			eStatistics.appendChild(eAverageServiceTime);
		}
		Node nodeRef = XMLUtil.findChildNode(m_eBenchmarkData, "scores");
		if(nodeRef != null){
			m_eBenchmarkData.insertBefore(eStatistics, nodeRef.getNextSibling());			
		}
		else{
			m_eBenchmarkData.insertBefore(eStatistics, m_eBenchmarkData.getFirstChild());
		}
		return true;
	}//setBenchmarkStatistics
	
	/**
	 * Set the optimization benchmark information. 
	 * 
	 * @param optimizationBenchmark holds the optimization benchmark information. 
	 * @return whether optimization benchmark information is set successfully. 
	 */
	public boolean setOptimizationBenchmark(OptimizationBenchmark optimizationBenchmark){
		if(optimizationBenchmark == null){
			XMLUtil.removeChildrenByName(m_eBenchmarkData, "optimization");
			return true;
		}
		Element eOptimization = (Element)XMLUtil.findChildNode(m_eBenchmarkData, "optimization");
		if(eOptimization != null){
			m_eBenchmarkData.removeChild(eOptimization);
		}
		eOptimization = m_document.createElement("optimization");
		//TODO
		Node nodeRef = XMLUtil.findChildNode(m_eBenchmarkData, "statistics");
		if(nodeRef != null){
			m_eBenchmarkData.insertBefore(eOptimization, nodeRef.getNextSibling());	
		}
		else{
			nodeRef = XMLUtil.findChildNode(m_eBenchmarkData, "scores");
			if(nodeRef != null){
				m_eBenchmarkData.insertBefore(eOptimization, nodeRef.getNextSibling());			
			}
			else{
				m_eBenchmarkData.insertBefore(eOptimization, m_eBenchmarkData.getFirstChild());
			}
		}
		return true;
	}//setOptimizationBenchmark
	
	/**
	 * Set the other benchmark related elements. 
	 * 
	 * @param names holds the names of the other benchmarks. It is required. 
	 * @param values holds the values of the other benchmarks, empty String "" if no value for an benchmark.
	 * @param descriptions holds the descriptions of the other benchmarks, empty String "" if no value for an benchmark, null for
	 * the entire array if none of the benchmarks have descriptions.
	 * @return whether the other benchmarks element construction is successful.
	 */
	public boolean setOtherBenchmarks(String[] names, String[] values, String[] descriptions){
		if(names == null) return false;
		if(values == null) return false;
		if(names.length != values.length) return false;
		if(descriptions != null && names.length != descriptions.length) return false;
		for(int i = 0; i < names.length; i++){
			addOtherBenchmark(names[i], values[i], (descriptions==null)?"":descriptions[i]);
		}
		return true;
	}//setOtherBenchmarks
	
	/**
	 * Add an other benchmark element. 
	 * 
	 * @param name holds the name of the other benchmark element. It is required. 
	 * @param value holds the value of the other benchmark element, empty String "" if none. 
	 * @param description holds the description of the other benchmark element, empty String "" if none. 
	 * @return whether the other benchmark element is added successfully.
	 */
	public boolean addOtherBenchmark(String name, String value, String description){
		if(name == null) return false;
		Vector<Element> vElements = XMLUtil.getChildElementsByTagName(m_eBenchmarkData, "scores");
		Element eOther;
		int iNls = vElements==null?0:vElements.size();
		for(int i = 0; i < iNls; i++){
			eOther = (Element)vElements.elementAt(i);
			if(eOther.getAttribute("name").equals(name)){
				m_eBenchmarkData.removeChild(eOther);
				break;
			}
		}
		eOther = createOther(name, value, description);
		m_eBenchmarkData.appendChild(eOther);
		return true;
	}//addOtherBenchmark

	
	/**
	 * Create the OSbL root element and its most basic required structure.
	 * 
	 * @return the OSbL element.
	 */
	protected Element createOSbLRoot(){
		Element eOSbL = XMLUtil.createOSxLRootElement(m_document, "osbl");
		m_eBenchmarkHeader = createBenchmarkHeader();
		eOSbL.appendChild(m_eBenchmarkHeader);
		m_eBenchmarkData = createBenchmarkData();
		eOSbL.appendChild(m_eBenchmarkData);
		return eOSbL;
	}//createOSbLRoot

	/**
	 * Create the benchmarkHeader element and its most basic required structure.
	 * 
	 * @return the benchmarkHeader element.
	 */
	protected Element createBenchmarkHeader(){
		Element eBenchmarkHeader = m_document.createElement("benchmarkHeader");
		return eBenchmarkHeader;
	}//createBenchmarkHeader
	
	/**
	 * Create the benchmarkData element and its most basic required structure.
	 * 
	 * @return the benchmarkData element.
	 */
	protected Element createBenchmarkData(){
		Element eBenchmarkData = m_document.createElement("benchmarkData");
		return eBenchmarkData;
	}//createBenchmarkHeader

	/**
	 * Create the other element and its most basic required structure.
	 * 
	 * @param name the name of the other element. 
	 * @param value the value of the other element, empty String "" if no value.
	 * @param description holds the description of the other benchmark element, empty String "" if none. 
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
		OSbLWriter osblWriter = new OSbLWriter();
		String sFileName = OSParameter.CODE_HOME + "OSRepository/test/osbl/osbl.osbl";
		if(!osblWriter.setBenchmarkMessage("my message")) System.out.println("message!");
		//if(!osblWriter.setBenchmarkMessage("")) System.out.println("message!");
		if(!osblWriter.setServiceName("my service name")) System.out.println("service name");
		if(!osblWriter.setServiceURI("my service uri")) System.out.println("uri");
		if(!osblWriter.setBenchmarkTime(new GregorianCalendar())) System.out.println("time!");
		BenchmarkScores benchmarkScores = new BenchmarkScores();
		benchmarkScores.computation = 1.1;
		benchmarkScores.expertAssessment = 1.2;
		benchmarkScores.overall = 1.3;
		benchmarkScores.owner = 1.4;
		benchmarkScores.popularity = 1.5;
		benchmarkScores.reputation = 1.6;
		benchmarkScores.service = 1.7;
		benchmarkScores.support = 1.8;
		benchmarkScores.system = 1.9;
		benchmarkScores.userAssessment = 2;
		if(!osblWriter.setBenchmarkScores(benchmarkScores)) System.out.println("setBenchmarkScores");
		if(!osblWriter.setOptimizationBenchmark(new OptimizationBenchmark())) System.out.println("setOptimizationBenchmark");
		BenchmarkStatistics benchmarkStatistics = new BenchmarkStatistics();
		benchmarkStatistics.averageJobs = 3.1;
		benchmarkStatistics.averageServiceTime = 3.2;
		benchmarkStatistics.averageWaitTime = 3.3;
		if(!osblWriter.setBenchmarkStatistics(benchmarkStatistics)) System.out.println("setBenchmarkStatistics");
		
		String[] msOtherBenchmarkNames = {"other name 0", "other name 1"};
		String[] msOtherBenchmarkValues = {"other value 0", "other value 1"};
		if(!osblWriter.setOtherBenchmarks(msOtherBenchmarkNames, msOtherBenchmarkValues, null)) System.out.println("set other!");
	
		if(!osblWriter.addOtherBenchmark("other name 2", "other value 2", null)) System.out.println("add other!");
		if(!osblWriter.addOtherBenchmark("other name 3", "other value 3", "other description 3")) System.out.println("add other!");

		////////////////////
		
		OSbLReader osblReader = new OSbLReader(false);
		if(!osblReader.readFile(sFileName)) System.out.println("reading");
		OSBenchmark osBenchmark;
		try {
			osBenchmark = osblReader.getOSBenchmark();
			if(!osblWriter.setOSBenchmark(osBenchmark)) System.out.println("set osBenchmark");
		} 
		catch (Exception e) {
			e.printStackTrace();
		}
		////////////////////
		
		//osblWriter.writeToStandardOutput();
		System.out.println(osblWriter.writeToString());
				
	}//main
	
}//class OSbLWriter
