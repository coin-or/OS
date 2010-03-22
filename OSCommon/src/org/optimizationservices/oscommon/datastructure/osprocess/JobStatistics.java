/**
 * @(#)JobStatistics 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.datastructure.osprocess;

import java.util.GregorianCalendar;

import org.optimizationservices.oscommon.datastructure.osgeneral.JobDependencies;
import org.optimizationservices.oscommon.datastructure.osgeneral.DirectoriesAndFiles;

/**
 *
 * <P>A data structure class that corresponds to an xml element in the OSpL schema.   
 *  
 * </p>
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */


public class JobStatistics {
	/**
	 * jobID holds the ID of the job, which can be served as a key in a hashmap. 
	 */
	public String jobID = null;
	
	/**
	 * state holds the job state, which can be waiting, running, killed, finished or unknown. 
	 */
	public String state = "unknown";

	/**
	 * serviceURI holds the URI of the service that the job is submitted to.
	 */
	public String serviceURI = "";

	/**
	 * userName holds the name of the user that submits the job.
	 */
	public String userName = "";

	/**
	 * startTime holds the submit time of the job. 
	 */
	public GregorianCalendar submitTime = new GregorianCalendar(1970, 0, 1, 0, 0, 0); 

	
	/**
	 * startTime holds the start time of the job. 
	 */
	public GregorianCalendar startTime = new GregorianCalendar(1970, 0, 1, 0, 0, 0); 

	/**
	 * endTime holds the end time of the job. 
	 */	
	public GregorianCalendar endTime = new GregorianCalendar(1970, 0, 1, 0, 0, 0); 
	
	/**
	 * duration holds the duration of the job. 
	 */	
	public double duration = Double.NaN; 
	
	/**
	 * scheduledStartTime holds the scheduled start time of the job. 
	 */
	public GregorianCalendar scheduledStartTime = new GregorianCalendar(1970, 0, 1, 0, 0, 0);
	
	/**
	 * dependencies holds the job dependencies, i.e. the list (String array) of 
	 * othter jobIDs that have to finish before this job starts. 
	 */
	public JobDependencies dependencies = null; 
	
	/**
	 * requiredDirectories holds the required directories to run the job.
	 */
	public DirectoriesAndFiles requiredDirectories = null;

	/**
	 * requiredFiles holds the required files to run the job.
	 */
	public DirectoriesAndFiles requiredFiles = null;

	/**
	 *
	 * Default constructor. 
	 */
	public JobStatistics(){
	}//constructor
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] args) {
	}//main
	
}//JobStatistics
