using System;
using System.Xml;
using System.Collections;

using org.optimizationservices.oscommon.util;
using org.optimizationservices.oscommon.localinterface;
using org.optimizationservices.oscommon.datastructure.osbenchmark;

namespace org.optimizationservices.oscommon.representationparser{
	/// <summary>
	/// The <c>OSbLWriter</c> class is used to construct an instance that follows 
	/// the OSbL format. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OSbLWriter : OSgLWriter{
		/// <summary>
		/// m_eOSbL holds the OSbL root element.
		/// </summary>
		protected internal XmlElement m_eOSbL = null;

		/// <summary>
		/// m_eBenchmarkHeader holds the 1st child element benchmarkHeader of root element OSbL.
		/// </summary>
		protected XmlElement m_eBenchmarkHeader = null;
	
		/// <summary>
		/// m_eBenchmarkData holds the 2nd child element benchmarkData of root element OSbL.
		/// </summary>
		protected XmlElement m_eBenchmarkData = null;


		/// <summary>
		/// constructor. 
		/// </summary>
		public OSbLWriter(){
			m_document = XMLUtil.createNewDocument();
			if(OSParameter.XSLT_LOCATION != null && OSParameter.XSLT_LOCATION.Length > 0){
				XmlProcessingInstruction xsltPI = m_document.CreateProcessingInstruction("xml-stylesheet",
					"type=\"text/xsl\" href = \"" + OSParameter.XSLT_LOCATION + "OSbL.xslt\"");
				m_document.AppendChild(xsltPI);     
			}
			m_eOSbL = createOSbLRoot();
			m_document.AppendChild(m_eOSbL);
		}//constructor

		/// <summary>
		/// set the OSBenchmark, a standard os benchmark interface. 
		/// </summary>
		/// <param name="osBenchmark">holds the standard os benchmark interface. </param>
		/// <returns>whether the OSBenchmark is set successfully. </returns>
		public bool setOSBenchmark(OSBenchmark osBenchmark){
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
			if(osBenchmark.benchmarkData.other != null && osBenchmark.benchmarkData.other.Length > 0){
				int n = osBenchmark.benchmarkData.other.Length;
				string[] msNames = new string[n];
				string[] msValues = new string[n];
				string[] msDescriptions = new string[n];
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

		/// <summary>
		/// Set the service uri. If the element is already there, it will reset it. If the element 
		/// is not there (e.g. optional element), it will add it. 
		/// </summary>
		/// <param name="serviceURI">holds the service URI.</param>
		/// <returns>whether the service uri is set successfully.</returns>
		public bool setServiceURI(string serviceURI){
			try{
				if(serviceURI != null && serviceURI.Length > 0){
					XmlElement eServiceURI = (XmlElement)XMLUtil.findChildNode(m_eBenchmarkHeader, "serviceURI");
					if(eServiceURI == null){
						eServiceURI = m_document.CreateElement("serviceURI");	
						eServiceURI.AppendChild(m_document.CreateTextNode(serviceURI));
						m_eBenchmarkHeader.InsertBefore(eServiceURI, m_eBenchmarkHeader.FirstChild);				}
					else{
						XMLUtil.setElementValue(eServiceURI, serviceURI);
					}
				}
				else{
					XMLUtil.removeChildrenByName(m_eBenchmarkHeader, "serviceURI");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;

		}//setServiceURI

		/// <summary>
		/// Set the service name. If the element is already there, it will reset it. If the element 
		/// is not there (e.g. optional element), it will add it. 
		/// </summary>
		/// <param name="serviceName">holds the service name.</param>
		/// <returns>whether the service name is set successfully.</returns>
		public bool setServiceName(string serviceName){
			try{
				XmlNode nodeRef = null;
				if(serviceName != null && serviceName.Length > 0){
					XmlElement eServiceName = (XmlElement)XMLUtil.findChildNode(m_eBenchmarkHeader, "serviceName");
					if(eServiceName == null){
						eServiceName = m_document.CreateElement("serviceName");					
						eServiceName.AppendChild(m_document.CreateTextNode(serviceName));
						nodeRef = XMLUtil.findChildNode(m_eBenchmarkHeader, "time");
						if(nodeRef == null){
							nodeRef = XMLUtil.findChildNode(m_eBenchmarkHeader, "message");
						}
						m_eBenchmarkHeader.InsertBefore(eServiceName, nodeRef);
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
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setServiceName

		/// <summary>
		/// Set time of the last benchmark.
		/// </summary>
		/// <param name="time">holds the time of the last benchmark.</param>
		/// <returns>whether benchmark time is set successfully. </returns>
		public bool setBenchmarkTime(DateTime time){
			try{
				XmlNode nodeRef = null;
				if(time.Year > 1970){
					XmlElement eTime = (XmlElement)XMLUtil.findChildNode(m_eBenchmarkHeader, "time");
					if(eTime == null){
						eTime = m_document.CreateElement("time");					
						eTime.AppendChild(m_document.CreateTextNode(XMLUtil.createXSDateTime(time)));
						nodeRef = XMLUtil.findChildNode(m_eBenchmarkHeader, "message");
						m_eBenchmarkHeader.InsertBefore(eTime, nodeRef);
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
				Console.WriteLine(e.ToString());;
				return false;
			}
			return true;
		}//setBenchmarkTime

		/// <summary>
		/// Set the benchmark message.
		/// </summary>
		/// <param name="message">holds the benchmark message. </param>
		/// <returns>whether benchmark message is set successfully. </returns>
		public bool setBenchmarkMessage(string message){
			try{
				XmlNode nodeRef = null;
				if(message != null && message.Length > 0){
					XmlElement eMessage = (XmlElement)XMLUtil.findChildNode(m_eBenchmarkHeader, "message");
					if(eMessage == null){
						eMessage = m_document.CreateElement("message");					
						eMessage.AppendChild(m_document.CreateTextNode(message));
						m_eBenchmarkHeader.InsertBefore(eMessage, nodeRef);
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
				Console.WriteLine(e.ToString());;
				return false;
			}
			return true;
		}//setBenchmarkMessage

		/// <summary>
		/// Set the benchmark scores. 
		/// </summary>
		/// <param name="scores">holds the benchmark scores. </param>
		/// <returns>whether the benchmark scores is set successfully. </returns>
		public bool setBenchmarkScores(BenchmarkScores scores){
			if(scores == null){
				XMLUtil.removeChildrenByName(m_eBenchmarkData, "scores");
				return true;
			}
			XmlElement eScores = (XmlElement)XMLUtil.findChildNode(m_eBenchmarkData, "scores");
			if(eScores != null){
				m_eBenchmarkData.RemoveChild(eScores);
			}
			eScores = m_document.CreateElement("scores");
		
			if(Double.IsNaN(scores.overall)) return false;
			XmlElement eOverall = m_document.CreateElement("overall");
			eOverall.AppendChild(m_document.CreateTextNode(scores.overall.ToString()));
			eScores.AppendChild(eOverall);
			if(!Double.IsNaN(scores.expertAssessment)){
				XmlElement eExpertAssessment = m_document.CreateElement("expertAssessment");
				eExpertAssessment.AppendChild(m_document.CreateTextNode(scores.expertAssessment.ToString()));	
				eScores.AppendChild(eExpertAssessment);
			}
			if(!Double.IsNaN(scores.userAssessment)){
				XmlElement eUserAssessment = m_document.CreateElement("userAssessment");			
				eUserAssessment.AppendChild(m_document.CreateTextNode(scores.userAssessment.ToString()));			
				eScores.AppendChild(eUserAssessment);
			}
			if(!Double.IsNaN(scores.reputation)){
				XmlElement eReputation = m_document.CreateElement("reputation");			
				eReputation.AppendChild(m_document.CreateTextNode(scores.reputation.ToString()));			
				eScores.AppendChild(eReputation);
			}
			if(!Double.IsNaN(scores.popularity)){
				XmlElement ePopularity = m_document.CreateElement("popularity");			
				ePopularity.AppendChild(m_document.CreateTextNode(scores.popularity.ToString()));			
				eScores.AppendChild(ePopularity);
			}
			if(!Double.IsNaN(scores.owner)){
				XmlElement eOwner = m_document.CreateElement("owner");			
				eOwner.AppendChild(m_document.CreateTextNode(scores.owner.ToString()));			
				eScores.AppendChild(eOwner);
			}
			if(!Double.IsNaN(scores.support)){
				XmlElement eSupport = m_document.CreateElement("support");			
				eSupport.AppendChild(m_document.CreateTextNode(scores.support.ToString()));			
				eScores.AppendChild(eSupport);
			}
			if(!Double.IsNaN(scores.system)){
				XmlElement eSystem = m_document.CreateElement("system");			
				eSystem.AppendChild(m_document.CreateTextNode(scores.system.ToString()));			
				eScores.AppendChild(eSystem);
			}
			if(!Double.IsNaN(scores.service)){
				XmlElement eService = m_document.CreateElement("service");			
				eService.AppendChild(m_document.CreateTextNode(scores.service.ToString()));			
				eScores.AppendChild(eService);
			}
			if(!Double.IsNaN(scores.computation)){
				XmlElement eComputation = m_document.CreateElement("computation");			
				eComputation.AppendChild(m_document.CreateTextNode(scores.computation.ToString()));			
				eScores.AppendChild(eComputation);
			}

			m_eBenchmarkData.InsertBefore(eScores, m_eBenchmarkData.FirstChild);
			return true;
		}//setBenchmarkScores

		/// <summary>
		/// Set the benchmark statistics. 
		/// </summary>
		/// <param name="benchmarkStatistics">holds the benchmark statistics. </param>
		/// <returns>whether the benchmark statistics is set successfully. </returns>
		public bool setBenchmarkStatistics(BenchmarkStatistics benchmarkStatistics){
			if(benchmarkStatistics == null){
				XMLUtil.removeChildrenByName(m_eBenchmarkData, "statistics");
				return true;
			}
			XmlElement eStatistics = (XmlElement)XMLUtil.findChildNode(m_eBenchmarkData, "statistics");
			if(eStatistics != null){
				m_eBenchmarkData.RemoveChild(eStatistics);
			}
			eStatistics = m_document.CreateElement("statistics");		
			if(!Double.IsNaN(benchmarkStatistics.averageJobs)){
				XmlElement eAverageJobs = m_document.CreateElement("averageJobs");			
				eAverageJobs.AppendChild(m_document.CreateTextNode(benchmarkStatistics.averageJobs.ToString()));			
				eStatistics.AppendChild(eAverageJobs);
			}
			if(!Double.IsNaN(benchmarkStatistics.averageWaitTime)){
				XmlElement eAverageWaitTime = m_document.CreateElement("averageWaitTime");			
				eAverageWaitTime.AppendChild(m_document.CreateTextNode(benchmarkStatistics.averageWaitTime.ToString()));			
				eStatistics.AppendChild(eAverageWaitTime);
			}
			if(!Double.IsNaN(benchmarkStatistics.averageServiceTime)){
				XmlElement eAverageServiceTime = m_document.CreateElement("averageServiceTime");			
				eAverageServiceTime.AppendChild(m_document.CreateTextNode(benchmarkStatistics.averageServiceTime.ToString()));			
				eStatistics.AppendChild(eAverageServiceTime);
			}
			XmlNode nodeRef = XMLUtil.findChildNode(m_eBenchmarkData, "scores");
			if(nodeRef != null){
				m_eBenchmarkData.InsertBefore(eStatistics, nodeRef.NextSibling);			
			}
			else{
				m_eBenchmarkData.InsertBefore(eStatistics, m_eBenchmarkData.FirstChild);
			}
			return true;
		}//setBenchmarkStatistics

		/// <summary>
		/// Set the optimization benchmark information. 
		/// </summary>
		/// <param name="optimizationBenchmark">holds the optimization benchmark information. </param>
		/// <returns>whether optimization benchmark information is set successfully. </returns>
		public bool setOptimizationBenchmark(OptimizationBenchmark optimizationBenchmark){
			if(optimizationBenchmark == null){
				XMLUtil.removeChildrenByName(m_eBenchmarkData, "optimization");
				return true;
			}
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eBenchmarkData, "optimization");
			if(eOptimization != null){
				m_eBenchmarkData.RemoveChild(eOptimization);
			}
			eOptimization = m_document.CreateElement("optimization");
			//TODO
			XmlNode nodeRef = XMLUtil.findChildNode(m_eBenchmarkData, "statistics");
			if(nodeRef != null){
				m_eBenchmarkData.InsertBefore(eOptimization, nodeRef.NextSibling);	
			}
			else{
				nodeRef = XMLUtil.findChildNode(m_eBenchmarkData, "scores");
				if(nodeRef != null){
					m_eBenchmarkData.InsertBefore(eOptimization, nodeRef.NextSibling);			
				}
				else{
					m_eBenchmarkData.InsertBefore(eOptimization, m_eBenchmarkData.FirstChild);
				}
			}
			return true;
		}//setOptimizationBenchmark

		/// <summary>
		/// Set the other benchmark related elements. 
		/// </summary>
		/// <param name="names">holds the names of the other benchmarks. It is required. </param>
		/// <param name="values">holds the values of the other benchmarks, empty string "" if no value for an benchmark.</param>
		/// <param name="descriptions">holds the descriptions of the other benchmarks, empty string "" if no value for an benchmark, null for
		/// the entire array if none of the benchmarks have descriptions.</param>
		/// <returns>whether the other benchmarks element construction is successful.</returns>
		public bool setOtherBenchmarks(string[] names, string[] values, string[] descriptions){
			if(names == null) return false;
			if(values == null) return false;
			if(names.Length != values.Length) return false;
			if(descriptions != null && names.Length != descriptions.Length) return false;
			for(int i = 0; i < names.Length; i++){
				addOtherBenchmark(names[i], values[i], (descriptions==null)?"":descriptions[i]);
			}
			return true;
		}//setOtherBenchmarks


		/// <summary>
		/// Add an other benchmark element. 
		/// </summary>
		/// <param name="name">holds the name of the other benchmark element. It is required. </param>
		/// <param name="value">holds the value of the other benchmark element, empty string "" if none. </param>
		/// <param name="description">holds the description of the other benchmark element, empty string "" if none. </param>
		/// <returns>whether the other benchmark element is added successfully.</returns>
		public bool addOtherBenchmark(string name, string value, string description){
			if(name == null) return false;

			ArrayList vNodeList  = XMLUtil.getChildElementsByTagName(m_eBenchmarkData, "other");
			int iNls = vNodeList==null?0:vNodeList.Count;
			XmlElement eOther;
			for(int i = 0; i < iNls; i++){
				eOther = (XmlElement)vNodeList[i];
				if(eOther.GetAttribute("name").Equals(name)){
					m_eBenchmarkData.RemoveChild(eOther);
					break;
				}
			}
			eOther = createOther(name, value, description);
			m_eBenchmarkData.AppendChild(eOther);
			return true;
		}//addOtherBenchmark

		/// <summary>
		/// Create the OSbL root element and its most basic required structure.
		/// </summary>
		/// <returns>the OSbL element.</returns>
		protected XmlElement createOSbLRoot(){
			XmlElement eOSbL = XMLUtil.createOSxLRootElement(m_document, "osbl");
			m_eBenchmarkHeader = createBenchmarkHeader();
			eOSbL.AppendChild(m_eBenchmarkHeader);
			m_eBenchmarkData = createBenchmarkData();
			eOSbL.AppendChild(m_eBenchmarkData);

			return eOSbL;
		}//createOSbLRoot

		/// <summary>
		/// Create the benchmarkHeader element and its most basic required structure.
		/// </summary>
		/// <returns>the benchmarkHeader element.</returns>
		protected XmlElement createBenchmarkHeader(){
			XmlElement eBenchmarkHeader = m_document.CreateElement("benchmarkHeader");
			return eBenchmarkHeader;
		}//createBenchmarkHeader

		/// <summary>
		/// Create the benchmarkData element and its most basic required structure.
		/// </summary>
		/// <returns>the benchmarkData element.</returns>
		protected XmlElement createBenchmarkData(){
			XmlElement eBenchmarkData = m_document.CreateElement("benchmarkData");
			return eBenchmarkData;
		}//createBenchmarkHeader

		/// <summary>
		/// Create the other element and its most basic required structure.
		/// </summary>
		/// <param name="name">the name of the other element. </param>
		/// <param name="value">the value of the other element, empty string "" if no value. </param>
		/// <param name="description">holds the description of the other benchmark element, empty string "" if none. </param>
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
	}//class OSbLWriter
}//namespace
