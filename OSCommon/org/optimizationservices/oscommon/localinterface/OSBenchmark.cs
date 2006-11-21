using System;
using System.Collections;

using org.optimizationservices.oscommon.datastructure.osbenchmark;
using org.optimizationservices.oscommon.representationparser;

namespace org.optimizationservices.oscommon.localinterface{
	/// <summary>
	/// The <c>OSBenchmark</c> class is a local interface for storing OS 
	/// benchmark. Its design follows the OSbL. Naming, structuring and layering 
	/// all are exactly the same as those in the OSbL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OSBenchmark{


		/// <summary>
		/// benchmarkHeader holds the first child of the OSBenchmark specified by the OSbL Schema. 
		/// </summary>
		public BenchmarkHeader benchmarkHeader = new BenchmarkHeader();

		/// <summary>
		/// benchmarkData holds the second child of the OSBenchmark specified by the OSbL Schema. 
		/// </summary>
		public BenchmarkData benchmarkData = new BenchmarkData();
	
		/// <summary>
		/// Default constructor. 
		/// </summary>
		public OSBenchmark(){
		}//constructor

		/// <summary>
		/// read an OSbL instance and return and OSBenchmark object.  
		/// @throws Exception if there are errors in reading the string or setting the OSBenchmark. 
		/// </summary>
		/// <param name="osbl">holds the optimization benchmark in a string which format follows the
		/// Optimization Services benchmark Language (OSbL) schema</param>
		/// <param name="isFile">isFile holds whether the osbl string is a file name or a string that literally holds the osbl contents.  </param>
		/// <param name="validate">holds whether the reader should be validating against the schema or not.</param>
		/// <returns>the OSBenchmark object constructed from the OSbL String.  </returns>
		public OSBenchmark readOSbL(string osbl, bool isFile, bool validate){
			OSbLReader osblReader = new OSbLReader(validate);
			bool bRead = false;
			if(isFile){
				bRead = osblReader.readFile(osbl);
			}
			else{
				bRead = osblReader.readString(osbl);			
			}
			if(!bRead) throw new Exception("OSbL string not valid");
			return osblReader.getOSBenchmark();
		}//readOSbL
	   
		/// <summary>
		/// write the OSBenchmark to an osbl xml string. 
		/// @throws Exception if there are errors in writing the osbl string. 
		/// </summary>
		/// <returns>the osbl xml string. </returns>
		public string writeOSbL(){
			OSbLWriter osblWriter = new OSbLWriter();
			osblWriter.setOSBenchmark(this);
			return osblWriter.writeToString();
		}//writeOSbL

		/// <summary>
		/// Get service name.
		/// </summary>
		/// <returns>the service name. </returns>
		public string getServiceName(){
			return benchmarkHeader.serviceName;
		}//getServiceName

		/// <summary>
		/// Set service name.
		/// </summary>
		/// <param name="serviceName">holds the name of the service. </param>
		/// <returns>whether the service name is set successfully. </returns>
		public bool setServiceName(string serviceName){
			benchmarkHeader.serviceName = serviceName;
			return true;
		}//setServiceName

		/// <summary>
		/// Get service uri.
		/// </summary>
		/// <returns>the service uri. </returns>
		public string getServiceURI(){
			return benchmarkHeader.serviceURI;
		}//getServiceURI

		/// <summary>
		/// Set service uri.
		/// </summary>
		/// <param name="serviceURI">serviceURI holds the uri of the service. </param>
		/// <returns>whether the service uri is set successfully. </returns>
		public bool setServiceURI(string serviceURI){
			benchmarkHeader.serviceURI = serviceURI;
			return true;
		}//setServiceURI
	
		/// <summary>
		/// Get time of the last benchmark.
		/// </summary>
		/// <returns>the time of the last benchmark.</returns>
		public DateTime getBenchmarkTime(){
			return benchmarkHeader.time;
		}//getBenchmarkTime

		/// <summary>
		/// Set time of the last benchmark.
		/// </summary>
		/// <param name="time">holds the time of the last benchmark.</param>
		/// <returns>whether benchmark time is set successfully. </returns>
		public bool setBenchmarkTime(DateTime time){
			benchmarkHeader.time = time;
			return true;
		}//setBenchmarkTime

		/// <summary>
		/// Get the benchmark message. 
		/// </summary>
		/// <returns>the benchmark message. </returns>
		public string getBenchmarkMessage(){
			return benchmarkHeader.message;
		}//getBenchmarkMessage
		
		/// <summary>
		/// Set the benchmark message.
		/// </summary>
		/// <param name="message">holds the benchmark message. </param>
		/// <returns>whether benchmark message is set successfully. </returns>
		public bool setBenchmarkMessage(string message){
			benchmarkHeader.message = message;
			return true;
		}//setBenchmarkMessage

		/// <summary>
		/// Get the benchmark scores. 
		/// </summary>
		/// <returns>the benchmark scores. </returns>
		public BenchmarkScores getBenchmarkScores(){
			return benchmarkData.scores;
		}//getBenchmarkScores

		/// <summary>
		/// Set the benchmark scores. 
		/// </summary>
		/// <param name="scores">holds the benchmark scores. </param>
		/// <returns>whether the benchmark scores is set successfully. </returns>
		public bool setBenchmarkScores(BenchmarkScores scores){
			benchmarkData.scores = scores;
			return true;
		}//setBenchmarkScores

		/// <summary>
		/// Get the benchmark statistics.
		/// </summary>
		/// <returns>the benchmark statistics.</returns>
		public BenchmarkStatistics getBenchmarkStatistics(){
			return benchmarkData.statistics;
		}//getBenchmarkStatistics

		/// <summary>
		/// Set the benchmark statistics. 
		/// </summary>
		/// <param name="benchmarkStatistics">holds the benchmark statistics. </param>
		/// <returns>whether the benchmark statistics is set successfully. </returns>
		public bool setBenchmarkStatistics(BenchmarkStatistics benchmarkStatistics){
			benchmarkData.statistics = benchmarkStatistics;
			return true;
		}//setBenchmarkStatistics

		/// <summary>
		/// Get the optimization benchmark information. 
		/// </summary>
		/// <returns>the optimization benchmark information. </returns>
		public OptimizationBenchmark getOptimizationBenchmark(){
			return benchmarkData.optimization;
		}//getOptimizationBenchmark
		
		/// <summary>
		/// Set the optimization benchmark information. 
		/// </summary>
		/// <param name="optimizationBenchmark">holds the optimization benchmark information. </param>
		/// <returns>whether optimization benchmark information is set successfully. </returns>
		public bool setOptimizationBenchmark(OptimizationBenchmark optimizationBenchmark){
			benchmarkData.optimization = optimizationBenchmark;
			return true;
		}//setOptimizationBenchmark

		/// <summary>
		/// get a string array of names of other benchmarks. 
		/// </summary>
		/// <returns>a string array of names of other benchmarks, null if no other benchmarks.  </returns>
		public string[] getOtherBenchmarkNames(){
			if(benchmarkData.other == null) return null;
			int n = benchmarkData.other.Length;
			if(n <= 0) return null;
			string[] otherBenchmarkNames = new String[n];
			for(int i = 0; i < n; i++){
				otherBenchmarkNames[i] = benchmarkData.other[i].name;
			}
			return otherBenchmarkNames;
		}//getOtherBenchmarkNames

		/// <summary>
		/// get a hashmap of other benchmark descriptions. 
		/// The keys of the hashmap are the benchmark names, and 
		/// the values of the hashmap are the benchmark descriptions.  
		/// </summary>
		/// <returns>a hashmap of other benchmark descriptions, null if no other benchmarks. </returns>
		public Hashtable  getOtherBenchmarkDescriptions(){
			if(benchmarkData.other == null) return null;
			int n = benchmarkData.other.Length;
			if(n <= 0) return null;
			Hashtable otherBenchmarkDescriptions = new Hashtable();
			for(int i = 0; i < n; i++){
				otherBenchmarkDescriptions.Add(benchmarkData.other[i].name, benchmarkData.other[i].description);
			}
			return otherBenchmarkDescriptions;
		}//getOtherBenchmarkDescriptions

		/// <summary>
		/// get a hashmap of other benchmark values. 
		/// The keys of the hashmap are the benchmark names, and 
		/// the values of the hashmap are the benchmark values.  
		/// </summary>
		/// <returns>a hashmap of other benchmark values, null if no other benchmarks. </returns>
		public Hashtable getOtherBenchmarkValues(){
			if(benchmarkData.other == null) return null;
			int n = benchmarkData.other.Length;
			if(n <= 0) return null;
			Hashtable otherBenchmarkValues = new Hashtable();
			for(int i = 0; i < n; i++){
				otherBenchmarkValues.Add(benchmarkData.other[i].name, benchmarkData.other[i].value);
			}
			return otherBenchmarkValues;
		}//getOtherBenchmarkValues

		/// <summary>
		/// set other benchmarks, with their names (required), descriptions (optional) and values (optional).
		/// </summary>
		/// <param name="names"holds the names of the other benchmarks; it is required.  ></param>
		/// <param name="descriptions">holds the descriptions of the other benchmarks; null if none. </param>
		/// <param name="values">holds the values of the other benchmarks; null if none. </param>
		/// <returns>whether the other anlysis information is set successfully. </returns>
		public bool setOtherBenchmarks(string[] names, string[] descriptions, string[] values){
			if(names == null) return false;
			if(descriptions != null && descriptions.Length != names.Length) return false;
			if(values != null && values.Length != names.Length) return false;
			int n = names.Length;
			benchmarkData.other = new OtherBenchmark[n];
			for(int i = 0; i < n; i++){
				benchmarkData.other[i] = new OtherBenchmark();
			}
			for(int i = 0; i < n; i++){
				benchmarkData.other[i].name = names[i];
			}
			if(descriptions != null){
				for(int i = 0; i < n; i++){
					benchmarkData.other[i].description = descriptions[i];
				}	
			}
			if(values != null){
				for(int i = 0; i < n; i++){
					benchmarkData.other[i].value = values[i];
				}	
			}
			return true;
		}//setOtherBenchmarks

	}//class OSBenchmark
}//namespace
