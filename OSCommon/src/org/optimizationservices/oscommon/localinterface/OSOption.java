/**
 * @(#)OSOption 1.0 03/14/2005
 *
 * Copyright (c) 2005 
 */
package org.optimizationservices.oscommon.localinterface;

import java.util.GregorianCalendar;
import java.util.Hashtable;

import org.optimizationservices.oscommon.datastructure.osgeneral.JobDependencies;
import org.optimizationservices.oscommon.datastructure.osgeneral.DirectoriesAndFiles;
import org.optimizationservices.oscommon.datastructure.osgeneral.Processes;
import org.optimizationservices.oscommon.datastructure.osoption.ContactOption;
import org.optimizationservices.oscommon.datastructure.osoption.GeneralOption;
import org.optimizationservices.oscommon.datastructure.osoption.InitVarValue;
import org.optimizationservices.oscommon.datastructure.osoption.InitialVariableValues;
import org.optimizationservices.oscommon.datastructure.osoption.InstanceLocationOption;
import org.optimizationservices.oscommon.datastructure.osoption.JobOption;
import org.optimizationservices.oscommon.datastructure.osoption.OptimizationOption;
import org.optimizationservices.oscommon.datastructure.osoption.OtherOption;
import org.optimizationservices.oscommon.datastructure.osoption.ServiceOption;
import org.optimizationservices.oscommon.datastructure.osoption.SystemOption;
import org.optimizationservices.oscommon.datastructure.osoption.VariableOption;
import org.optimizationservices.oscommon.representationparser.OSoLReader;
import org.optimizationservices.oscommon.representationparser.OSoLWriter;


/**
*
* <P>The <code>OSOption</code> class is a local interface for storing Optimization Services
* options, especially solver service options. Its design follows the Optimization Services 
* option Language (OSoL). All the data structures in this class are standards specified in OSoL. 
* Developers can add service-specific options by extending this class.  
*
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2005
* @see org.optimizationservices.oscommon.localinterface.OSInstance
* @see org.optimizationservices.oscommon.localinterface.OSResult
* @see org.optimizationservices.oscommon.localinterface.OSAnalysis
* @since OS 1.0
*/
public class OSOption {

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
	 * general holds the general option specified by the OSoL Schema. 
	 */
	public GeneralOption general = new GeneralOption();
	
	/**
	 * system holds the system option specified by the OSoL Schema. 
	 */
	public SystemOption system = new SystemOption();

	/**
	 * service holds the service option specified by the OSoL Schema. 
	 */
	public ServiceOption service = new ServiceOption();

	
	/**
	 * job holds the job option specified by the OSoL Schema. 
	 */
	public JobOption job = new JobOption();
	
	/**
	 * optimization holds the optimization option specified by the OSoL Schema. 
	 */
	public OptimizationOption optimization = new OptimizationOption();

	/**
	 * other holds an array of all other options specified by the OSoL Schema. 
	 */
	public OtherOption[] other = null;

	/**
	 *
	 * Default constructor. 
	 */
	public OSOption(){
	}//constructor
	
	/**
	 * read an OSoL instance and return and OSOption object.  
	 * 
	 * @param osol holds the optimization option in a string which format follows the
	 * Optimization Services option Language (OSoL) schema.
	 * @param isFile holds whether the osol string is a file name or a string that literally holds the osol contents.  
	 * @param validate holds whether the reader should be validating against the schema or not.
	 * @return the OSOption object constructed from the OSoL String.  
	 * @throws Exception if there are errors in reading the string or setting the OSOption. 
	 */
   	public OSOption readOSoL(String osol, boolean isFile, boolean validate) throws Exception{
   		OSoLReader osolReader = new OSoLReader(validate);
		boolean bRead = false;
		if(isFile){
			bRead = osolReader.readFile(osol);
		}
		else{
			bRead = osolReader.readString(osol);			
		}
		if(!bRead) throw new Exception("OSoL string not valid");
		return osolReader.getOSOption();
   	}//readOSoL
   	
   	/**
   	 * write the OSOption to an osol xml string. 
   	 * 
   	 * @return the osol xml string. 
	 * @throws Exception if there are errors in writing the osol string. 
   	 */
   	public String writeOSoL() throws Exception{
		OSoLWriter osolWriter = new OSoLWriter();
		osolWriter.setOSOption(this);
		return osolWriter.writeToString();
   	}//writeOSoL
   	
   	/**
	 * Get service name.
	 * 
	 * @return the service name. 
	 */
	public String getServiceName(){
		return general.serviceName;
	}//getServiceName
	
   	/**
	 * Set service name.
	 * 
	 * @param serviceName holds the name of the service. 
	 * @return whether the service name is set successfully. 
	 */
	public boolean setServiceName(String serviceName){
		general.serviceName = serviceName;
		return true;
	}//setServiceName

   	/**
	 * Get service uri.
	 * 
	 * @return the service uri. 
	 */
	public String getServiceURI(){
		return general.serviceURI;
	}//getServiceURI
	
   	/**
	 * Set service uri.
	 * 
	 * @param serviceURI holds the uri of the service. 
	 * @return whether the service uri is set successfully. 
	 */
	public boolean setServiceURI(String serviceURI){
		general.serviceURI = serviceURI;
		return true;
	}//setServiceURI
	
   	/**
	 * Get instance name.
	 * 
	 * @return the instance name. 
	 */
	public String getInstanceName(){
		return general.instanceName;
	}//getInstanceName
	
   	/**
	 * Set instance name.
	 * 
	 * @param instanceName holds the name of the instance. 
	 * @return whether the instance name is set successfully. 
	 */
	public boolean setInstanceName(String instanceName){
		general.instanceName = instanceName;
		return true;
	}//setInstanceName

	/**
	 * Get the instance location type to get the instance. 
	 * e.g. local, http, ftp.
	 * 
	 * @return the instance location type, null or empty string if none. 
	 */
	public String getInstanceLocationType(){
		if(general.instanceLocation == null) general.instanceLocation = new InstanceLocationOption();
		return general.instanceLocation.locationType;
	}//getInstanceLocationType
	
	/**
	 * Set the instance location type to get the instance. 
	 * 
	 * @param locationType holds the instance location type, e.g. local, http, ftp.
	 * @return whether the instance location type is set successfully.
	 */
	public boolean setInstanceLocationType(String locationType){
		if(general.instanceLocation == null) general.instanceLocation = new InstanceLocationOption();
		general.instanceLocation.locationType = locationType;
		return true;
	}//setInstanceLocationType
	
	/**
	 * Get the instance address to get the instance. 
	 * 
	 * @return the instance address, null or empty string if none. 
	 */
	public String getInstanceAddress(){
		if(general.instanceLocation == null) general.instanceLocation = new InstanceLocationOption();
		return general.instanceLocation.value;
	}//getInstanceAddress
	
	/**
	 * Set the instance address to get the instance. 
	 * 
	 * @param address holds the instance address. 
	 * @return whether the instance address is set successfully.
	 */
	public boolean setInstanceAddress(String address){
		if(general.instanceLocation == null) general.instanceLocation = new InstanceLocationOption();
		general.instanceLocation.value = address;
		return true;
	}//setInstanceAddress

	/**
	 * Get job ID. 
	 * 
	 * @return the job ID, null or empty string if none. 
	 */
	public String getJobID(){
		return general.jobID;
	}//getJobID
	
	/**
	 * Set jobID.
	 * 
	 * @param jobID holds the jobID.
	 * @return whether the jobID is set successfully.
	 */
	public boolean setJobID(String jobID){
		general.jobID = jobID;
		return true;
	}//setJobID

	/**
	 * Get license. 
	 * 
	 * @return the license, null or empty string if none. 
	 */
	public String getLicense(){
		return general.license;
	}//getLicense
	
	/**
	 * Set license.
	 * 
	 * @param license holds the license required by the service.
	 * @return whether the license is set successfully.
	 */
	public boolean setLicense(String license){
		general.license = license;
		return true;
	}//setLicense

	/**
	 * Get the userName. 
	 * 
	 * @return the user name, null or empty string if none. 
	 */
	public String getUserName(){
		return general.userName;
	}//getUserName
	
	/**
	 * Set the user name.
	 * 
	 * @param userName holds the user name required by the service.
	 * @return whether the user name is set successfully.
	 */
	public boolean setUserName(String userName){
		general.userName = userName;
		return true;
	}//setUserName
	
	/**
	 * Get the password. 
	 * 
	 * @return the password, null or empty string if none. 
	 */
	public String getPassword(){
		return general.password;
	}//getPassword
	
	/**
	 * Set the password.
	 * 
	 * @param password holds the password required by the service.
	 * @return whether the password is set successfully.
	 */
	public boolean setPassword(String password){
		general.password = password;
		return true;
	}//setPassword
	
	/**
	 * Get the contact transport type to respond to the requester,
	 * smtp (for email), osp (for knocking back on the requester), etc.
	 * 
	 * @return the contact trasport type, null or empty string if none. 
	 */
	public String getContactTransportType(){
		if(general.contact == null) general.contact = new ContactOption();
		return general.contact.transportType;
	}//getContactTransportType
	
	/**
	 * Set the contact transport type to respond to the requester,
	 * smtp (for email), osp (for knocking back on the requester), etc.
	 * 
	 * @param transportType holds the contact transport type. 
	 * @return whether the contact transport type is set successfully.
	 */
	public boolean setContactTransportType(String transportType){
		if(general.contact == null) general.contact = new ContactOption();
		general.contact.transportType = transportType;
		return true;
	}//setContactTransportType
	
	/**
	 * Get the contact address to respond to the requester. 
	 * For example it can be an email address if the contact transport type is smtp
	 * or a http uri if the contact transport type is osp (for knocking back on the requester), etc.
	 * 
	 * @return the contact trasport address, null or empty string if none. 
	 */
	public String getContactAddress(){
		return general.contact.value;
	}//getContactAddress
	
	/**
	 * Set the contact address to respond to the requester. 
	 * For example it can be an email address if the contact transport type is smtp
	 * or a http uri if the contact transport type is osp (for knocking back on the requester), etc.
	 * 
	 * @param address holds the contact address. 
	 * @return whether the contact address is set successfully.
	 */
	public boolean setContactAddress(String address){
		general.contact.value = address;
		return true;
	}//setContactAddress
	
	/**
	 * Get the system minimum disk space required to solve the job. 
	 * 
	 * @return the system minimum disk space, 0.0 if none. 
	 */
	public double getSystemMinDiskSpace(){
		return system.minDiskSpace;
	}//getSystemMinDiskSpace
	
	/**
	 * Set the the system minimum disk space required to solve the job.
	 * 
	 * @param minDiskSpace holds the  minimum disk space required to solve the job. 
	 * @return whether the minimum disk space is set successfully.
	 */
	public boolean setSystemMinDiskSpace(double minDiskSpace){
		if(minDiskSpace < 0) system.minDiskSpace = 0;
		else system.minDiskSpace = minDiskSpace;
		return true;
	}//setSystemMinDiskSpace

	/**
	 * Get the system minimum memory size required to solve the job. 
	 * 
	 * @return the system minimum memory size, 0.0 if none. 
	 */
	public double getSystemMinMemorySize(){
		return system.minMemory;
	}//getSystemMinMeorySize
	
	/**
	 * Set the the system minimum memory size required to solve the job.
	 * 
	 * @param minMemorySize holds the  minimum memory size required to solve the job. 
	 * @return whether the minimum memory size is set successfully.
	 */
	public boolean setSystemMinMemorySize(double minMemorySize){
		if(minMemorySize < 0) system.minMemory = 0;
		else system.minMemory = minMemorySize;
		return true;
	}//setSystemMinMemorySize

	/**
	 * Get the system minimum cpu speed required to solve the job. 
	 * 
	 * @return the system minimum cpu speed, 0.0 if none. 
	 */
	public double getSystemMinCPUSpeed(){
		return system.minCPUSpeed;
	}//getSystemMinCPUSpeed
	
	/**
	 * Set the the system minimum cpu speed required to solve the job.
	 * 
	 * @param minCPUSpeed holds the  minimum cpu speed required to solve the job. 
	 * @return whether the minimum cpu speed is set successfully.
	 */
	public boolean setSystemMinCPUSpeed(double minCPUSpeed){
		if(minCPUSpeed < 0) system.minCPUSpeed = 0;
		else system.minCPUSpeed = minCPUSpeed;
		return true;
	}//setSystemMinCPUSpeed

	/**
	 * Get the service type, which can be: 
	 * solver, analyzer, scheduler, simulation, registry, modeler, agent 
	 * 
	 * @return the service type; null or empty string if none. 
	 */
	public String getServiceType(){
		return service.type;
	}//getServiceType
	
	/**
	 * Set the service type. 
	 * 
	 * @param type holds the service type, which can be:
	 * solver, analyzer, scheduler, simulation, registry, modeler, agent 
	 * 
	 * @return whether the service type is set successfully or not. 
	 */
	public boolean setServiceType(String type){
		if(!type.equals("solver") && 
		   !type.equals("analyzer") &&
		   !type.equals("scheduler") &&
		   !type.equals("simulation") &&
		   !type.equals("registry") &&
		   !type.equals("modeler") &&
		   !type.equals("agent")) return false;
		service.type = type;
		return true;
	}//setServiceType

	/**
	 * Get the maximum time (in seconds) before the job is terminated.  
	 * 
	 * @return the maximum time, Double.POSITIVE_INFINITY if none. 
	 */
	public double getJobMaxTime(){
		return job.maxTime;
	}//getJobMaxTime
	
	/**
	 * Set the maximum time before the job is terminated.  
	 * 
	 * @param maxTime holds the maximum time in seconds. 
	 * @return whether the maximum time is set successfully.
	 */
	public boolean setJobMaxTime(double maxTime){
		if(maxTime <= 0) return false;
		else job.maxTime = maxTime;
		return true;
	}//setJobMaxTime

	/**
	 * Get the scheduled start time for the job.   
	 * 
	 * @return the scheduled start time for the job, null or UNIX time (1970/1/1) if none. 
	 */
	public GregorianCalendar getJobScheduledStartTime(){ 
		return job.scheduledStartTime;
	}//getJobScheduledStartTime
	
	/**
	 * Set the scheduled start time for the job.   
	 * 
	 * @param scheduledStartTime holds the scheduled start time for the job.   
	 * @return whether the scheduled start time is set successfully.
	 */
	public boolean setJobScheduledStartTime(GregorianCalendar scheduledStartTime){
		if(scheduledStartTime.getTimeInMillis() <= 0) job.scheduledStartTime = new GregorianCalendar(1970, 0, 1, 0, 0, 0);
		else job.scheduledStartTime = scheduledStartTime;
		return true;
	}//setJobScheduledStartTime
	
	/**
	 * Get the dependencies of the current job, which is 
	 * a string array of ids of the jobs that have run before the current job. 
	 * 
	 * @return a string array of ids of the jobs that have to run before the current job. 
	 */
	public String[] getJobDependencies(){
		if(job.dependencies == null) return null;
		return job.dependencies.jobID;
	}//getJobDependencies
	
	/**
	 * Get the dependencies of the current job, which is 
	 * a string array of ids of the jobs that have run before the current job. 
	 * @param jobIDs holds a string array of ids of the jobs that have run before the current job. 
	 * @return whether the job dependencies are set successfully.
	 */
	public boolean setJobDependencies(String[] jobIDs){
		if(job.dependencies == null) job.dependencies = new JobDependencies();
		job.dependencies.jobID = jobIDs;
		return true;
	}//setJobDependencies

	/**
	 * Get the required directories and files to run the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of direcotry/file paths required to run the job. 
	 */
	public String[] getRequiredDirectoriesAndFiles(){
		if(job.requiredDirectoriesAndFiles == null) return null;
		return job.requiredDirectoriesAndFiles.path;
	}//getRequiredDirectoriesAndFiles

	/**
	 * Set the required directories and files to run the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of directory/file paths required to run the job. 
	 * @return whether the required directories and files are set successfully.
	 */
	public boolean setRequiredDirectoriesAndFiles(String[] paths){
		if(job.requiredDirectoriesAndFiles == null) job.requiredDirectoriesAndFiles = new DirectoriesAndFiles();
		job.requiredDirectoriesAndFiles.path = paths;
		return true;
	}//setRequiredDirectoriesAndFiles

	/**
	 * Get the directories to make before running the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of direcotry paths to make. 
	 */
	public String[] getDirectoriesToMake(){
		if(job.directoriesToMake == null) return null;
		return job.directoriesToMake.path;
	}//getDirectoriesToMake

	/**
	 * Set the directories to make before running the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of directories to make before running the job. 
	 * @return whether the directories to make are set successfully.
	 */
	public boolean setDirectoriesToMake(String[] paths){
		if(job.directoriesToMake == null) job.directoriesToMake = new DirectoriesAndFiles();
		job.directoriesToMake.path = paths;
		return true;
	}//setDirectoriesToMake

	/**
	 * Get the files to create before running the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of file paths to create. 
	 */
	public String[] getFilesToCreate(){
		if(job.filesToCreate == null) return null;
		return job.filesToCreate.path;
	}//getFilesToCreate

	/**
	 * Set the files to create before running the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of files to create before running the job. 
	 * @return whether the files to create are set successfully.
	 */
	public boolean setFilesToCreate(String[] paths){
		if(job.filesToCreate == null) job.filesToCreate = new DirectoriesAndFiles();
		job.filesToCreate.path = paths;
		return true;
	}//setFilesToCreate

	/**
	 * Get the input files to copy from before running the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of file paths to copy from. 
	 */
	public String[] getInputFilesToCopyFrom(){
		if(job.inputFilesToCopyFrom == null) return null;
		return job.inputFilesToCopyFrom.path;
	}//getInputFilesToCopyFrom

	/**
	 * Set the input files to copy from before running the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of input files to copy from before running the job. 
	 * @return whether the input files to copy from are set successfully.
	 */
	public boolean setInputFilesToCopyFrom(String[] paths){
		if(job.inputFilesToCopyFrom == null) job.inputFilesToCopyFrom = new DirectoriesAndFiles();
		job.inputFilesToCopyFrom.path = paths;
		return true;
	}//setInputFilesToCopyFrom

	/**
	 * Get the input files to copy to before running the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of file paths to copy to. 
	 */
	public String[] getInputFilesToCopyTo(){
		if(job.inputFilesToCopyTo == null) return null;
		return job.inputFilesToCopyTo.path;
	}//getInputFilesToCopyTo

	/**
	 * Set the input files to copy to before running the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of input files to copy to before running the job. 
	 * @return whether the input files to copy to are set successfully.
	 */
	public boolean setInputFilesToCopyTo(String[] paths){
		if(job.inputFilesToCopyTo == null) job.inputFilesToCopyTo = new DirectoriesAndFiles();
		job.inputFilesToCopyTo.path = paths;
		return true;
	}//setInputFilesToCopyTo

	/**
	 * Get the input files to move from before running the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of file paths to move from. 
	 */
	public String[] getInputFilesToMoveFrom(){
		if(job.inputFilesToMoveFrom == null) return null;
		return job.inputFilesToMoveFrom.path;
	}//getInputFilesToMoveFrom

	/**
	 * Set the input files to move from before running the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of input files to move from before running the job. 
	 * @return whether the input files to move from are set successfully.
	 */
	public boolean setInputFilesToMoveFrom(String[] paths){
		if(job.inputFilesToMoveFrom == null) job.inputFilesToMoveFrom = new DirectoriesAndFiles();
		job.inputFilesToMoveFrom.path = paths;
		return true;
	}//setInputFilesToMoveFrom

	/**
	 * Get the input files to move to before running the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of file paths to move to. 
	 */
	public String[] getInputFilesToMoveTo(){
		if(job.inputFilesToMoveTo == null) return null;
		return job.inputFilesToMoveTo.path;
	}//getInputFilesToMoveTo

	/**
	 * Set the input files to move to before running the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of input files to move to before running the job. 
	 * @return whether the input files to move to are set successfully.
	 */
	public boolean setInputFilesToMoveTo(String[] paths){
		if(job.inputFilesToMoveTo == null) job.inputFilesToMoveTo = new DirectoriesAndFiles();
		job.inputFilesToMoveTo.path = paths;
		return true;
	}//setInputFilesToMoveTo

	/**
	 * Get the output files to copy from before running the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of file paths to copy from. 
	 */
	public String[] getOutputFilesToCopyFrom(){
		if(job.outputFilesToCopyFrom == null) return null;
		return job.outputFilesToCopyFrom.path;
	}//getOutputFilesToCopyFrom

	/**
	 * Set the output files to copy from before running the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of output files to copy from before running the job. 
	 * @return whether the output files to copy from are set successfully.
	 */
	public boolean setOutputFilesToCopyFrom(String[] paths){
		if(job.outputFilesToCopyFrom == null) job.outputFilesToCopyFrom = new DirectoriesAndFiles();
		job.outputFilesToCopyFrom.path = paths;
		return true;
	}//setOutputFilesToCopyFrom

	/**
	 * Get the output files to copy to before running the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of file paths to copy to. 
	 */
	public String[] getOutputFilesToCopyTo(){
		if(job.outputFilesToCopyTo == null) return null;
		return job.outputFilesToCopyTo.path;
	}//getOutputFilesToCopyTo

	/**
	 * Set the output files to copy to before running the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of output files to copy to before running the job. 
	 * @return whether the output files to copy to are set successfully.
	 */
	public boolean setOutputFilesToCopyTo(String[] paths){
		if(job.outputFilesToCopyTo == null) job.outputFilesToCopyTo = new DirectoriesAndFiles();
		job.outputFilesToCopyTo.path = paths;
		return true;
	}//setOutputFilesToCopyTo

	/**
	 * Get the output files to move from before running the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of file paths to move from. 
	 */
	public String[] getOutputFilesToMoveFrom(){
		if(job.outputFilesToMoveFrom == null) return null;
		return job.outputFilesToMoveFrom.path;
	}//getOutputFilesToMoveFrom

	/**
	 * Set the output files to move from before running the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of output files to move from before running the job. 
	 * @return whether the output files to move from are set successfully.
	 */
	public boolean setOutputFilesToMoveFrom(String[] paths){
		if(job.outputFilesToMoveFrom == null) job.outputFilesToMoveFrom = new DirectoriesAndFiles();
		job.outputFilesToMoveFrom.path = paths;
		return true;
	}//setOutputFilesToMoveFrom

	/**
	 * Get the output files to move to before running the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of file paths to move to. 
	 */
	public String[] getOutputFilesToMoveTo(){
		if(job.outputFilesToMoveTo == null) return null;
		return job.outputFilesToMoveTo.path;
	}//getOutputFilesToMoveTo

	/**
	 * Set the output files to move to before running the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of output files to move to before running the job. 
	 * @return whether the output files to move to are set successfully.
	 */
	public boolean setOutputFilesToMoveTo(String[] paths){
		if(job.outputFilesToMoveTo == null) job.outputFilesToMoveTo = new DirectoriesAndFiles();
		job.outputFilesToMoveTo.path = paths;
		return true;
	}//setOutputFilesToMoveTo

	/**
	 * Get the files to delete after running the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of file paths to delete. 
	 */
	public String[] getFilesToDelete(){
		if(job.filesToDelete == null) return null;
		return job.filesToDelete.path;
	}//getFilesToDelete

	/**
	 * Set the files to delete after running the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of file paths to delete after running the job. 
	 * @return whether the files to delete are set successfully.
	 */
	public boolean setFilesToDelete(String[] paths){
		if(job.filesToDelete == null) job.filesToDelete = new DirectoriesAndFiles();
		job.filesToDelete.path = paths;
		return true;
	}//setFilesToDelete

	/**
	 * Get the directories to delete after running the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of directory paths to delete. 
	 */
	public String[] getDirectoriesToDelete(){
		if(job.directoriesToDelete == null) return null;
		return job.directoriesToDelete.path;
	}//getDirectoriesToDelete

	/**
	 * Set the directories to delete after running the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of directory paths to delete after running the job. 
	 * @return whether the directories to delete are set successfully.
	 */
	public boolean setDirectoriesToDelete(String[] paths){
		if(job.directoriesToDelete == null) job.directoriesToDelete = new DirectoriesAndFiles();
		job.directoriesToDelete.path = paths;
		return true;
	}//setDirectoriesToDelete

	/**
	 * Get the processes to kill after running the job, which is 
	 * a string array of process names. 
	 * 
	 * @return a string array of process names to kill. 
	 */
	public String[] getProcessesToKill(){
		if(job.processesToKill == null) return null;
		return job.processesToKill.process;
	}//getProcessesToKill

	/**
	 * Set the processes to kill after running the job, which is 
	 * a string array of paths. 
	 * @param processNames holds a string array of process names to kill after running the job. 
	 * @return whether the processes to kill are set successfully.
	 */
	public boolean setProcessesToKill(String[] processNames){
		if(job.processesToKill == null) job.processesToKill = new Processes();
		job.processesToKill.process = processNames;
		return true;
	}//setProcessesToKill
	
	/**
	 * Get variable number. 
	 * 
	 * @return variable number, -1 if no information. 
	 */
	public int getVariableNumber(){
		if(m_iVariableNumber == -1){
			if(optimization == null) return -1;
			m_iVariableNumber = optimization.numberOfVariables;
		}
		return m_iVariableNumber;
	}//getVariableNumber

	/**
	 * Set the variable number. 
	 * 
	 * @param variableNumber holds the number of variables
	 * @return whether the variable number is set successfully or not. 
	 */
	public boolean setVariableNumber(int variableNumber){
		if(variableNumber < 0){
			return true;
		}
		if(optimization == null) optimization = new OptimizationOption();
		m_iVariableNumber = variableNumber;
		optimization.numberOfVariables = variableNumber;
		return true;
	}//setVariableNumber
	
	/**
	 * Get objective number. 
	 * 
	 * @return objective number, -1 if no information. 
	 */
	public int getObjectiveNumber(){
		if(m_iObjectiveNumber == -1){
			if(optimization == null) return -1;
			m_iObjectiveNumber = optimization.numberOfObjectives;
		}
		return m_iObjectiveNumber;
	}//getObjectiveNumber
	
	/**
	 * Set the objective number. 
	 * 
	 * @param objectiveNumber holds the number of objectives
	 * @return whether the objective number is set successfully or not. 
	 */
	public boolean setObjectiveNumber(int objectiveNumber){
		if(objectiveNumber < 0){
			return true;
		}
		if(optimization == null) optimization = new OptimizationOption();
		m_iObjectiveNumber = objectiveNumber;
		optimization.numberOfObjectives = objectiveNumber;
		return true;
	}//setObjectiveNumber
	
	/**
	 * Get constraint number. 
	 * 
	 * @return constraint number, -1 if no information. 
	 */
	public int getConstraintNumber(){
		if(m_iConstraintNumber == -1){
			if(optimization == null) return -1;
			m_iConstraintNumber = optimization.numberOfConstraints;
		}
		return m_iConstraintNumber;
	}//getConstraintNumber

	/**
	 * Set the constraint number. 
	 * 
	 * @param constraintNumber holds the number of constraints
	 * @return whether the constraint number is set successfully or not. 
	 */
	public boolean setConstraintNumber(int constraintNumber){
		if(constraintNumber < 0){
			return true;
		}
		if(optimization == null) optimization = new OptimizationOption();
		m_iConstraintNumber = constraintNumber;
		optimization.numberOfConstraints = constraintNumber;
		return true;
	}//setConstraintNumber
	
	/**
	 * get initial variable values (double[]). 
	 * @return a double array of the initial variable values, null if none. 
	 */
	public double[] getInitialVariableValues(){
		if(optimization == null) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		if(optimization.variables == null) return null;
		if(optimization.variables.initialVariableValues == null) return null;
		InitVarValue[] var = optimization.variables.initialVariableValues.var; 
		int iVars = (var==null)?0:var.length;
		double[] mdValues = new double[iNumberOfVariables];
		for(int i = 0; i < iVars; i++){
			mdValues[var[i].idx] = var[i].value;
		}
		return mdValues;		
	}//getInitialVariableValues
	
	/**
	 * Set initial variable values (double[]). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods are recommended  to be called first. 
	 * @param initialVariableValues holds a double array of initial variable values. 
	 * @return whether the initial variable values are set successfully or not. 
	 */
	public boolean setInitialVariableValues(double[] initialVariableValues){//TODO
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return true;
		if(initialVariableValues != null && initialVariableValues.length != iNumberOfVariables) return false;
		if(optimization == null) optimization = new OptimizationOption();
		if(optimization.variables == null){
			optimization.variables = new VariableOption();
		}
		if(optimization.variables.initialVariableValues == null){
			optimization.variables.initialVariableValues = new InitialVariableValues();
		}
		if(initialVariableValues == null){
			optimization.variables.initialVariableValues.var = null;
			return true;
		}
		int iVars = 0;
		for(int i = 0; i < initialVariableValues.length; i++){
			if(initialVariableValues[i] != 0) iVars++;
		}
		optimization.variables.initialVariableValues.var = new InitVarValue[iVars];
		InitVarValue[] var = optimization.variables.initialVariableValues.var;
		for(int i = 0; i < iVars; i++) var[i] = new InitVarValue();
		int j = 0;
		for(int i = 0; i < initialVariableValues.length; i++){
			if(initialVariableValues[i] != 0){
				var[j].idx = i;
				var[j].value = initialVariableValues[i];
				j++;
			}
		}
		return true; 
	}//setInitialVariableValues
	
	/**
	 * get a string array of names of other options. 
	 * 
	 * @return a string array of names of other options, null if no other options.  
	 */
	public String[] getOtherOptionNames(){
		if(other == null) return null;
		int n = other.length;
		if(n <= 0) return null;
		String[] otherOptionNames = new String[n];
		for(int i = 0; i < n; i++){
			otherOptionNames[i] = other[i].name;
		}
		return otherOptionNames;
	}//getOtherOptionNames
	
	/**
	 * get a hashmap of other option descriptions. 
	 * The keys of the hashmap are the option names, and 
	 * the values of the hashmap are the option descriptions.  
	 * 
	 * @return a hashmap of other option descriptions, null if no other options. 
	 */
	public Hashtable<String, String>  getOtherOptionDescriptions(){
		if(other == null) return null;
		int n = other.length;
		if(n <= 0) return null;
		Hashtable<String, String> otherOptionDescriptions = new Hashtable<String, String>();
		for(int i = 0; i < n; i++){
			otherOptionDescriptions.put(other[i].name, other[i].description);
		}
		return otherOptionDescriptions;
	}//getOtherOptionDescriptions

	/**
	 * get a hashmap of other option values. 
	 * The keys of the hashmap are the option names, and 
	 * the values of the hashmap are the option values.  
	 * 
	 * @return a hashmap of other option values, null if no other options. 
	 */
	public Hashtable<String, String>  getOtherOptionValues(){
		if(other == null) return null;
		int n = other.length;
		if(n <= 0) return null;
		Hashtable<String, String> otherOptionValues = new Hashtable<String, String>();
		for(int i = 0; i < n; i++){
			otherOptionValues.put(other[i].name, other[i].value);
		}
		return otherOptionValues;
	}//getOtherOptionValues

	/**
	 * set other options, with their names (required), descriptions (optional) and values (optional). 
	 * 
	 * @param names holds the names of the other options; it is required.  
	 * @param descriptions holds the descriptions of the other options; null if none. 
	 * @param values holds the values of the other options; null if none. 
	 * @return whether the other anlysis information is set successfully. 
	 */
	public boolean setOtherOptions(String[] names, String[] descriptions, String[] values){
		if(names == null) return false;
		if(descriptions != null && descriptions.length != names.length) return false;
		if(values != null && values.length != names.length) return false;
		int n = names.length;
		other = new OtherOption[n];
		for(int i = 0; i < n; i++){
			other[i] = new OtherOption();
		}
		for(int i = 0; i < n; i++){
			other[i].name = names[i];
		}
		if(descriptions != null){
			for(int i = 0; i < n; i++){
				other[i].description = descriptions[i];
			}	
		}
		if(values != null){
			for(int i = 0; i < n; i++){
				other[i].value = values[i];
			}	
		}
		return true;
	}//setOtherOptions
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] args){

	}//main
	
}//class OSOption
