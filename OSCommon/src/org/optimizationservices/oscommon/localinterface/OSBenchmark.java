/**
 * @(#)OSBenchmark 1.0 03/14/2005
 *
 * Copyright (c) 2005 
 */
package org.optimizationservices.oscommon.localinterface;

import java.util.GregorianCalendar;
import java.util.Hashtable;

import org.optimizationservices.oscommon.datastructure.osbenchmark.BenchmarkData;
import org.optimizationservices.oscommon.datastructure.osbenchmark.BenchmarkHeader;
import org.optimizationservices.oscommon.datastructure.osbenchmark.BenchmarkScores;
import org.optimizationservices.oscommon.datastructure.osbenchmark.BenchmarkStatistics;
import org.optimizationservices.oscommon.datastructure.osbenchmark.OptimizationBenchmark;
import org.optimizationservices.oscommon.datastructure.osbenchmark.OtherBenchmark;
import org.optimizationservices.oscommon.representationparser.OSbLReader;
import org.optimizationservices.oscommon.representationparser.OSbLWriter;

/**
*
* <P>The <code>OSBenchmark</code> class is a local interface for storing Optimization Services
* benchmark. Its design follows the Optimization Services benchmark Language (OSbL). 
* All the data structures in this class are standards specified in OSbL. 
*
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2005
* @since OS 1.0
*/

public class OSBenchmark {
	
	/**
	 * benchmarkHeader holds the first child of the OSBenchmark specified by the OSbL Schema. 
	 */
	public BenchmarkHeader benchmarkHeader = new BenchmarkHeader();

	/**
	 * benchmarkData holds the second child of the OSBenchmark specified by the OSbL Schema. 
	 */
	public BenchmarkData benchmarkData = new BenchmarkData();
	
	/**
	 *
	 * Default constructor. 
	 */
	public OSBenchmark(){
	}//constructor
	
	/**
	 * read an OSbL instance and return and OSBenchmark object.  
	 * 
	 * @param osbl holds the optimization benchmark in a string which format follows the
	 * Optimization Services benchmark Language (OSbL) schema.
	 * @param isFile holds whether the osbl string is a file name or a string that literally holds the osbl contents.  
	 * @param validate holds whether the reader should be validating against the schema or not.
	 * @return the OSBenchmark object constructed from the OSbL String.  
	 * @throws Exception if there are errors in reading the string or setting the OSBenchmark. 
	 */
   	public OSBenchmark readOSbL(String osbl, boolean isFile, boolean validate) throws Exception{
   		OSbLReader osblReader = new OSbLReader(validate);
		boolean bRead = false;
		if(isFile){
			bRead = osblReader.readFile(osbl);
		}
		else{
			bRead = osblReader.readString(osbl);			
		}
		if(!bRead) throw new Exception("OSbL string not valid");
		return osblReader.getOSBenchmark();
   	}//readOSbL
   	
   	/**
   	 * write the OSBenchmark to an osbl xml string. 
   	 * 
   	 * @return the osbl xml string. 
	 * @throws Exception if there are errors in writing the osbl string. 
   	 */
   	public String writeOSbL() throws Exception{
		OSbLWriter osblWriter = new OSbLWriter();
		osblWriter.setOSBenchmark(this);
		return osblWriter.writeToString();
   	}//writeOSbL
   	
   	/**
	 * Get service name.
	 * 
	 * @return the service name. 
	 */
	public String getServiceName(){
		return benchmarkHeader.serviceName;
	}//getServiceName
	
   	/**
	 * Set service name.
	 * 
	 * @param serviceName holds the name of the service. 
	 * @return whether the service name is set successfully. 
	 */
	public boolean setServiceName(String serviceName){
		benchmarkHeader.serviceName = serviceName;
		return true;
	}//setServiceName
	
   	/**
	 * Get service uri.
	 * 
	 * @return the service uri. 
	 */
	public String getServiceURI(){
		return benchmarkHeader.serviceURI;
	}//getServiceURI
	
   	/**
	 * Set service uri.
	 * 
	 * @param serviceURI holds the uri of the service. 
	 * @return whether the service uri is set successfully. 
	 */
	public boolean setServiceURI(String serviceURI){
		benchmarkHeader.serviceURI = serviceURI;
		return true;
	}//setServiceURI
	
   	/**
	 * Get time of the last benchmark.
	 * 
	 * @return the time of the last benchmark.
	 */
	public GregorianCalendar getBenchmarkTime(){
		return benchmarkHeader.time;
	}//getBenchmarkTime
	
   	/**
	 * Set time of the last benchmark.
	 * 
	 * @param time holds the time of the last benchmark.
	 * @return whether benchmark time is set successfully. 
	 */
	public boolean setBenchmarkTime(GregorianCalendar time){
		benchmarkHeader.time = time;
		return true;
	}//setBenchmarkTime
	
   	/**
	 * Get the benchmark message. 
	 * 
	 * @return the benchmark message. 
	 */
	public String getBenchmarkMessage(){
		return benchmarkHeader.message;
	}//getBenchmarkMessage
	
   	/**
	 * Set the benchmark message. 
	 * 
	 * @param message holds the benchmark message. 
	 * @return whether benchmark message is set successfully. 
	 */
	public boolean setBenchmarkMessage(String message){
		benchmarkHeader.message = message;
		return true;
	}//setBenchmarkMessage
	
	/**
	 * Get the benchmark scores. 
	 * 
	 * @return the benchmark scores. 
	 */
	public BenchmarkScores getBenchmarkScores(){
		return benchmarkData.scores;
	}//getBenchmarkScores
	
	/**
	 * Set the benchmark scores. 
	 * 
	 * @param scores holds the benchmark scores. 
	 * @return whether the benchmark scores is set successfully. 
	 */
	public boolean setBenchmarkScores(BenchmarkScores scores){
		benchmarkData.scores = scores;
		return true;
	}//setBenchmarkScores

	/**
	 * Get the benchmark statistics. 
	 * 
	 * @return the benchmark statistics. 
	 */
	public BenchmarkStatistics getBenchmarkStatistics(){
		return benchmarkData.statistics;
	}//getBenchmarkStatistics
	
	/**
	 * Set the benchmark statistics. 
	 * 
	 * @param benchmarkStatistics holds the benchmark statistics. 
	 * @return whether the benchmark statistics is set successfully. 
	 */
	public boolean setBenchmarkStatistics(BenchmarkStatistics benchmarkStatistics){
		benchmarkData.statistics = benchmarkStatistics;
		return true;
	}//setBenchmarkStatistics

	/**
	 * Get the optimization benchmark information. 
	 * 
	 * @return the optimization benchmark information. 
	 */
	public OptimizationBenchmark getOptimizationBenchmark(){
		return benchmarkData.optimization;
	}//getOptimizationBenchmark
	
	/**
	 * Set the optimization benchmark information. 
	 * 
	 * @param optimizationBenchmark holds the optimization benchmark information. 
	 * @return whether optimization benchmark information is set successfully. 
	 */
	public boolean setOptimizationBenchmark(OptimizationBenchmark optimizationBenchmark){
		benchmarkData.optimization = optimizationBenchmark;
		return true;
	}//setOptimizationBenchmark
	
	/**
	 * get a string array of names of other benchmarks. 
	 * 
	 * @return a string array of names of other benchmarks, null if no other benchmarks.  
	 */
	public String[] getOtherBenchmarkNames(){
		if(benchmarkData.other == null) return null;
		int n = benchmarkData.other.length;
		if(n <= 0) return null;
		String[] otherBenchmarkNames = new String[n];
		for(int i = 0; i < n; i++){
			otherBenchmarkNames[i] = benchmarkData.other[i].name;
		}
		return otherBenchmarkNames;
	}//getOtherBenchmarkNames
	
	/**
	 * get a hashmap of other benchmark descriptions. 
	 * The keys of the hashmap are the benchmark names, and 
	 * the values of the hashmap are the benchmark descriptions.  
	 * 
	 * @return a hashmap of other benchmark descriptions, null if no other benchmarks. 
	 */
	public Hashtable<String, String>  getOtherBenchmarkDescriptions(){
		if(benchmarkData.other == null) return null;
		int n = benchmarkData.other.length;
		if(n <= 0) return null;
		Hashtable<String, String> otherBenchmarkDescriptions = new Hashtable<String, String>();
		for(int i = 0; i < n; i++){
			otherBenchmarkDescriptions.put(benchmarkData.other[i].name, benchmarkData.other[i].description);
		}
		return otherBenchmarkDescriptions;
	}//getOtherBenchmarkDescriptions

	/**
	 * get a hashmap of other benchmark values. 
	 * The keys of the hashmap are the benchmark names, and 
	 * the values of the hashmap are the benchmark values.  
	 * 
	 * @return a hashmap of other benchmark values, null if no other benchmarks. 
	 */
	public Hashtable<String, String>  getOtherBenchmarkValues(){
		if(benchmarkData.other == null) return null;
		int n = benchmarkData.other.length;
		if(n <= 0) return null;
		Hashtable<String, String> otherBenchmarkValues = new Hashtable<String, String>();
		for(int i = 0; i < n; i++){
			otherBenchmarkValues.put(benchmarkData.other[i].name, benchmarkData.other[i].value);
		}
		return otherBenchmarkValues;
	}//getOtherBenchmarkValues

	/**
	 * set other benchmarks, with their names (required), descriptions (optional) and values (optional). 
	 * 
	 * @param names holds the names of the other benchmarks; it is required.  
	 * @param descriptions holds the descriptions of the other benchmarks; null if none. 
	 * @param values holds the values of the other benchmarks; null if none. 
	 * @return whether the other anlysis information is set successfully. 
	 */
	public boolean setOtherBenchmarks(String[] names, String[] descriptions, String[] values){
		if(names == null) return false;
		if(descriptions != null && descriptions.length != names.length) return false;
		if(values != null && values.length != names.length) return false;
		int n = names.length;
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

	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] args){
		
	}//main
}//class OSBenchmark

