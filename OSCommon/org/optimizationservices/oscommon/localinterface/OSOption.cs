using System;
using System.Collections;

using org.optimizationservices.oscommon.datastructure.osoption;
using org.optimizationservices.oscommon.util;
using org.optimizationservices.oscommon.datastructure.osgeneral;
using org.optimizationservices.oscommon.representationparser;

namespace org.optimizationservices.oscommon.localinterface{
	/// <summary>
	/// The <c>OSOption</c> class is a local interface for storing OS 
	/// problem option. Its design follows the OSoL. Naming, structuring and layering 
	/// all are exactly the same as those in the OSoL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// <see cref="org.optimizationservices.oscommon.localinterface.OSInstance"/>
	/// <see cref="org.optimizationservices.oscommon.localinterface.OSResult"/>
	/// <see cref="org.optimizationservices.oscommon.localinterface.OSAnalysis"/>
	/// </summary>
	public class OSOption{

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

		/// <summary>
		/// general holds the general option specified by the OSoL Schema. 
		/// </summary>
		public GeneralOption general = new GeneralOption();

		/// <summary>
		/// system holds the system option specified by the OSoL Schema. 
		/// </summary>
		public SystemOption system = new SystemOption();

		/// <summary>
		/// service holds the service option specified by the OSoL Schema. 
		/// </summary>
		public ServiceOption service = new ServiceOption();

		/// <summary>
		/// job holds the job option specified by the OSoL Schema. 
		/// </summary>
		public JobOption job = new JobOption();

		/// <summary>
		/// optimization holds the optimization option specified by the OSoL Schema.  
		/// </summary>
		public OptimizationOption optimization = new OptimizationOption();

		/// <summary>
		/// other holds an array of all other options specified by the OSoL Schema. 
		/// </summary>
		public OtherOption[] other = null;

		/// <summary>
		/// Default constructor. 
		/// </summary>
		public OSOption(){
		}//constructor
		
		/// <summary>
		/// read an OSoL instance and return and OSOption object.  
		/// @throws Exception if there are errors in reading the string or setting the OSOption. 
		/// </summary>
		/// <param name="osol">holds the optimization option in a string which format follows the
		/// Optimization Services option Language (OSoL) schema</param>
		/// <param name="isFile">isFile holds whether the osol string is a file name or a string that literally holds the osol contents.  </param>
		/// <param name="validate">holds whether the reader should be validating against the schema or not.</param>
		/// <returns>the OSOption object constructed from the OSoL string.  </returns>
		public OSOption readOSoL(string osol, bool isFile, bool validate){
			OSoLReader osolReader = new OSoLReader(validate);
			bool bRead = false;
			if(isFile){
				bRead = osolReader.readFile(osol);
			}
			else{
				bRead = osolReader.readString(osol);			
			}
			if(!bRead) throw new Exception("OSoL string not valid");
			return osolReader.getOSOption();
		}//readOSoL
	   
		/// <summary>
		/// write the OSOption to an osol xml string. 
		/// @throws Exception if there are errors in writing the osol string. 
		/// </summary>
		/// <returns>the osol xml string. </returns>
		public string writeOSoL(){
			OSoLWriter osolWriter = new OSoLWriter();
			osolWriter.setOSOption(this);
			return osolWriter.writeToString();
		}//writeOSoL

		/// <summary>
		/// Get service name.
		/// </summary>
		/// <returns>the service name. </returns>
		public string getServiceName(){
			return general.serviceName;
		}//getServiceName

		/// <summary>
		/// Set service name.
		/// </summary>
		/// <param name="serviceName">holds the name of the service. </param>
		/// <returns>whether the service name is set successfully. </returns>
		public bool setServiceName(string serviceName){
			general.serviceName = serviceName;
			return true;
		}//setServiceName

		/// <summary>
		/// Get service uri.
		/// </summary>
		/// <returns>the service uri. </returns>
		public string getServiceURI(){
			return general.serviceURI;
		}//getServiceURI

		/// <summary>
		/// Set service uri.
		/// </summary>
		/// <param name="serviceURI">holds the uri of the service. </param>
		/// <returns>whether the service uri is set successfully. </returns>
		public bool setServiceURI(string serviceURI){
			general.serviceURI = serviceURI;
			return true;
		}//setServiceURI

		/// <summary>
		/// Get instance name.
		/// </summary>
		/// <returns>the instance name.</returns>
		public string getInstanceName(){
			return general.instanceName;
		}//getInstanceName

		/// <summary>
		/// Set instance name.
		/// </summary>
		/// <param name="instanceName">holds the name of the instance. </param>
		/// <returns>whether the instance name is set successfully. </returns>
		public bool setInstanceName(string instanceName){
			general.instanceName = instanceName;
			return true;
		}//setInstanceName

		/// <summary>
		/// Get the instance location type to get the instance.  
		/// e.g. local, http, ftp.
		/// </summary>
		/// <returns>the instance location type, null or empty string if none. </returns>
		public string getInstanceLocationType(){
			if(general.instanceLocation == null) general.instanceLocation = new InstanceLocationOption();
			return general.instanceLocation.locationType;
		}//getInstanceLocationType
	
		/// <summary>
		/// Set the instance location type to get the instance. 
		/// </summary>
		/// <param name="locationType">holds the instance location type, e.g. local, http, ftp.</param>
		/// <returns>whether the instance location type is set successfully.</returns>
		public bool setInstanceLocationType(String locationType){
			if(general.instanceLocation == null) general.instanceLocation = new InstanceLocationOption();
			general.instanceLocation.locationType = locationType;
			return true;
		}//setInstanceLocationType
	
		/// <summary>
		/// Get the instance address to get the instance.  
		/// </summary>
		/// <returns>the instance address, null or empty string if none. </returns>
		public string getInstanceAddress(){
			if(general.instanceLocation == null) general.instanceLocation = new InstanceLocationOption();
			return general.instanceLocation.value;
		}//getInstanceAddress
	
		/// <summary>
		/// Set the instance address to get the instance. 
		/// </summary>
		/// <param name="address">holds the instance address. </param>
		/// <returns>whether the instance address is set successfully.</returns>
		public bool setInstanceAddress(String address){
			if(general.instanceLocation == null) general.instanceLocation = new InstanceLocationOption();
			general.instanceLocation.value = address;
			return true;

		}//setInstanceAddress

		/// <summary>
		/// Get job ID. 
		/// </summary>
		/// <returns>the job ID, null or empty string if none. </returns>
		public string getJobID(){
			return general.jobID;
		}//getJobID

		/// <summary>
		/// Set jobID. 
		/// </summary>
		/// <param name="jobID">holds the jobID.</param>
		/// <returns>whether the jobID is set successfully.</returns>
		public bool setJobID(string jobID){
			general.jobID = jobID;
			return true;
		}//setJobID

		/// <summary>
		/// Get license. 
		/// </summary>
		/// <returns>the license, null or empty string if none. </returns>
		public string getLicense(){
			return general.license;
		}//getLicense

		/// <summary>
		/// Set license.
		/// </summary>
		/// <param name="license">holds the license required by the service.</param>
		/// <returns>whether the license is set successfully.</returns>
		public bool setLicense(string license){
			general.license = license;
			return true;
		}//setLicense

		/// <summary>
		/// Get the userName. 
		/// </summary>
		/// <returns>the user name, null or empty string if none. </returns>
		public string getUserName(){
			return general.userName;
		}//getUserName

		/// <summary>
		/// Set the user name.
		/// </summary>
		/// <param name="userName">holds the user name required by the service.</param>
		/// <returns>whether the user name is set successfully.</returns>
		public bool setUserName(string userName){
			general.userName = userName;
			return true;
		}//setUserName

		/// <summary>
		/// Get the password. 
		/// </summary>
		/// <returns>the password, null or empty string if none. </returns>
		public string getPassword(){
			return general.password;
		}//getPassword

		/// <summary>
		/// Set the password.
		/// </summary>
		/// <param name="password">holds the password required by the service.</param>
		/// <returns>whether the password is set successfully.</returns>
		public bool setPassword(string password){
			general.password = password;
			return true;
		}//setPassword

		/// <summary>
		/// Get the contact transport type to respond to the requester,
		/// smtp (for email), osp (for knocking back on the requester), etc.
		/// </summary>
		/// <returns>the contact trasport type, null or empty string if none. </returns>
		public string getContactTransportType(){
			if(general.contact == null) general.contact = new ContactOption();
			return general.contact.transportType;
		}//getContactTransportType

		/// <summary>
		/// Set the contact transport type to respond to the requester,
		/// smtp (for email), osp (for knocking back on the requester), etc.
		/// </summary>
		/// <param name="transportType">holds the contact transport type. </param>
		/// <returns>whether the contact transport type is set successfully.</returns>
		public bool setContactTransportType(string transportType){
			if(general.contact == null) general.contact = new ContactOption();
			general.contact.transportType = transportType;
			return true;
		}//setContactTransportType

		/// <summary>
		/// Get the contact address to respond to the requester. 
		/// For example it can be an email address if the contact transport type is smtp
		/// or a http uri if the contact transport type is osp (for knocking back on the requester), etc.
		/// </summary>
		/// <returns>the contact trasport address, null or empty string if none. </returns>
		public string getContactAddress(){
			return general.contact.value;
		}//getContactAddress
	
		/// <summary>
		/// Set the contact address to respond to the requester. 
		/// For example it can be an email address if the contact transport type is smtp
		/// or a http uri if the contact transport type is osp (for knocking back on the requester), etc.
		/// </summary>
		/// <param name="address">holds the contact address. </param>
		/// <returns>whether the contact address is set successfully.</returns>
		public bool setContactAddress(string address){
			general.contact.value = address;
			return true;
		}//setContactAddress
		
		/// <summary>
		/// Get the system minimum disk space required to solve the job. 
		/// </summary>
		/// <returns>the system minimum disk space, 0.0 if none. </returns>
		public double getSystemMinDiskSpace(){
			return system.minDiskSpace;
		}//getSystemMinDiskSpace
	

		/// <summary>
		/// Set the the system minimum disk space required to solve the job.
		/// </summary>
		/// <param name="minDiskSpace">holds the  minimum disk space required to solve the job. </param>
		/// <returns>whether the minimum disk space is set successfully.</returns>
		public bool setSystemMinDiskSpace(double minDiskSpace){
			if(minDiskSpace < 0) system.minDiskSpace = 0;
			else system.minDiskSpace = minDiskSpace;
			return true;
		}//setSystemMinDiskSpace

		/// <summary>
		/// Get the system minimum memory size required to solve the job. 
		/// </summary>
		/// <returns>the system minimum memory size, 0.0 if none. </returns>
		public double getSystemMinMemorySize(){
			return system.minMemory;
		}//getSystemMinMeorySize

		/// <summary>
		/// Set the the system minimum memory size required to solve the job.
		/// </summary>
		/// <param name="minMemorySize">holds the  minimum memory size required to solve the job. </param>
		/// <returns>whether the minimum memory size is set successfully.</returns>
		public bool setSystemMinMemorySize(double minMemorySize){
			if(minMemorySize < 0) system.minMemory = 0;
			else system.minMemory = minMemorySize;
			return true;
		}//setSystemMinMemorySize

		/// <summary>
		/// Get the system minimum cpu speed required to solve the job. 
		/// </summary>
		/// <returns>the system minimum cpu speed, 0.0 if none. </returns>
		public double getSystemMinCPUSpeed(){
			return system.minCPUSpeed;
		}//getSystemMinCPUSpeed

		/// <summary>
		/// Set the the system minimum cpu speed required to solve the job.
		/// </summary>
		/// <param name="minCPUSpeed">holds the  minimum cpu speed required to solve the job. </param>
		/// <returns>whether the minimum cpu speed is set successfully.</returns>
		public bool setSystemMinCPUSpeed(double minCPUSpeed){
			if(minCPUSpeed < 0) system.minCPUSpeed = 0;
			else system.minCPUSpeed = minCPUSpeed;
			return true;
		}//setSystemMinCPUSpeed

		/// <summary>
		/// Get the service type, which can be: 
		/// solver, analyzer, scheduler, simulation, registry, modeler, agent 
		/// </summary>
		/// <returns>the service type; null or empty string if none. </returns>
		public string getServiceType(){
			return service.type;
		}//getServiceType

		/// <summary>
		/// Set the service type. 
		/// </summary>
		/// <param name="type">holds the service type, which can be:
		/// solver, analyzer, scheduler, simulation, registry, modeler, agent 
		/// </param>
		/// <returns>whether the service type is set successfully or not. </returns>
		public bool setServiceType(string type){
			if(!type.Equals("solver") && 
				!type.Equals("analyzer") &&
				!type.Equals("scheduler") &&
				!type.Equals("simulation") &&
				!type.Equals("registry") &&
				!type.Equals("modeler") &&
				!type.Equals("agent")) return false;
			service.type = type;
			return true;
		}//setServiceType

		/// <summary>
		/// Get the maximum time (in seconds) before the job is terminated. 
		/// </summary>
		/// <returns>the maximum time, Double.POSITIVE_INFINITY if none. </returns>
		public double getJobMaxTime(){
			return job.maxTime;
		}//getJobMaxTime

		/// <summary>
		/// Set the maximum time before the job is terminated.  
		/// </summary>
		/// <param name="maxTime">holds the maximum time in seconds. </param>
		/// <returns>whether the maximum time is set successfully.</returns>
		public bool setJobMaxTime(double maxTime){
			if(maxTime <= 0) return false;
			else job.maxTime = maxTime;
			return true;
		}//setJobMaxTime

		/// <summary>
		/// Get the scheduled start time for the job.   
		/// </summary>
		/// <returns>the scheduled start time for the job, null or UNIX time (1970/1/1) if none.</returns>
		public DateTime getJobScheduledStartTime(){ 
			return job.scheduledStartTime;
		}//getJobScheduledStartTime

		/// <summary>
		/// Set the scheduled start time for the job.   
		/// </summary>
		/// <param name="scheduledStartTime">holds the scheduled start time for the job.   </param>
		/// <returns>whether the scheduled start time is set successfully.</returns>
		public bool setJobScheduledStartTime(DateTime scheduledStartTime){
			if(CommonUtil.timeMillis(scheduledStartTime) <= 0) job.scheduledStartTime = new DateTime(1970, 1, 1, 0, 0, 0);
			else job.scheduledStartTime = scheduledStartTime;
			return true;
		}//setJobScheduledStartTime

		/// <summary>
		/// Get the dependencies of the current job, which is 
		/// a string array of ids of the jobs that have run before the current job. 
		/// </summary>
		/// <returns>a string array of ids of the jobs that have to run before the current job. </returns>
		public string[] getJobDependencies(){
			if(job.dependencies == null) return null;
			return job.dependencies.jobID;
		}//getJobDependencies

		/// <summary>
		/// Get the dependencies of the current job, which is 
		/// a string array of ids of the jobs that have run before the current job. 
		/// </summary>
		/// <param name="jobIDs">holds a string array of ids of the jobs that have run before the current job. </param>
		/// <returns>whether the job dependencies are set successfully.</returns>
		public bool setJobDependencies(string[] jobIDs){
			if(job.dependencies == null) job.dependencies = new JobDependencies();
			job.dependencies.jobID = jobIDs;
			return true;
		}//setJobDependencies

		/// <summary>
		/// Get the required directories and files to run the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <returns>a string array of direcotry/file paths required to run the job. </returns>
		public string[] getRequiredDirectoriesAndFiles(){
			if(job.requiredDirectoriesAndFiles == null) return null;
			return job.requiredDirectoriesAndFiles.path;
		}//getRequiredDirectoriesAndFiles

		/// <summary>
		/// Set the required directories and files to run the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <param name="paths">holds a string array of directory/file paths required to run the job. </param>
		/// <returns>whether the required directories and files are set successfully.</returns>
		public bool setRequiredDirectoriesAndFiles(string[] paths){
			if(job.requiredDirectoriesAndFiles == null) job.requiredDirectoriesAndFiles = new DirectoriesAndFiles();
			job.requiredDirectoriesAndFiles.path = paths;
			return true;
		}//setRequiredDirectoriesAndFiles

		/// <summary>
		/// Get the directories to make before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <returns>a string array of direcotry paths to make. </returns>
		public string[] getDirectoriesToMake(){
			if(job.directoriesToMake == null) return null;
			return job.directoriesToMake.path;
		}//getDirectoriesToMake

		/// <summary>
		/// Set the directories to make before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <param name="paths">holds a string array of directories to make before running the job. </param>
		/// <returns>whether the directories to make are set successfully.</returns>
		public bool setDirectoriesToMake(string[] paths){
			if(job.directoriesToMake == null) job.directoriesToMake = new DirectoriesAndFiles();
			job.directoriesToMake.path = paths;
			return true;
		}//setDirectoriesToMake

		/// <summary>
		/// Get the files to create before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <returns>a string array of file paths to create. </returns>
		public string[] getFilesToCreate(){
			if(job.filesToCreate == null) return null;
			return job.filesToCreate.path;
		}//getFilesToCreate

		/// <summary>
		/// Set the files to create before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <param name="paths">holds a string array of files to create before running the job. </param>
		/// <returns>whether the files to create are set successfully.</returns>
		public bool setFilesToCreate(string[] paths){
			if(job.filesToCreate == null) job.filesToCreate = new DirectoriesAndFiles();
			job.filesToCreate.path = paths;
			return true;
		}//setFilesToCreate

		/// <summary>
		/// Get the input files to copy from before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <returns>a string array of file paths to copy from. </returns>
		public string[] getInputFilesToCopyFrom(){
			if(job.inputFilesToCopyFrom == null) return null;
			return job.inputFilesToCopyFrom.path;
		}//getInputFilesToCopyFrom

		/// <summary>
		/// Set the input files to copy from before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <param name="paths">holds a string array of input files to copy from before running the job. </param>
		/// <returns>whether the input files to copy from are set successfully.</returns>
		public bool setInputFilesToCopyFrom(string[] paths){
			if(job.inputFilesToCopyFrom == null) job.inputFilesToCopyFrom = new DirectoriesAndFiles();
			job.inputFilesToCopyFrom.path = paths;
			return true;
		}//setInputFilesToCopyFrom

		/// <summary>
		/// Get the input files to copy to before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <returns>a string array of file paths to copy to. </returns>
		public string[] getInputFilesToCopyTo(){
			if(job.inputFilesToCopyTo == null) return null;
			return job.inputFilesToCopyTo.path;
		}//getInputFilesToCopyTo

		/// <summary>
		/// Set the input files to copy to before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <param name="paths">holds a string array of input files to copy to before running the job. </param>
		/// <returns>whether the input files to copy to are set successfully.</returns>
		public bool setInputFilesToCopyTo(string[] paths){
			if(job.inputFilesToCopyTo == null) job.inputFilesToCopyTo = new DirectoriesAndFiles();
			job.inputFilesToCopyTo.path = paths;
			return true;
		}//setInputFilesToCopyTo

		/// <summary>
		/// Get the input files to move from before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <returns>a string array of file paths to move from. </returns>
		public string[] getInputFilesToMoveFrom(){
			if(job.inputFilesToMoveFrom == null) return null;
			return job.inputFilesToMoveFrom.path;
		}//getInputFilesToMoveFrom

		/// <summary>
		/// Set the input files to move from before running the job, which is  
		/// a string array of paths.
		/// </summary>
		/// <param name="paths">holds a string array of input files to move from before running the job. </param>
		/// <returns>whether the input files to move from are set successfully.</returns>
		public bool setInputFilesToMoveFrom(string[] paths){
			if(job.inputFilesToMoveFrom == null) job.inputFilesToMoveFrom = new DirectoriesAndFiles();
			job.inputFilesToMoveFrom.path = paths;
			return true;
		}//setInputFilesToMoveFrom

		/// <summary>
		/// Get the input files to move to before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <returns>a string array of file paths to move to. </returns>
		public string[] getInputFilesToMoveTo(){
			if(job.inputFilesToMoveTo == null) return null;
			return job.inputFilesToMoveTo.path;
		}//getInputFilesToMoveTo

		/// <summary>
		/// Set the input files to move to before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <param name="paths">holds a string array of input files to move to before running the job. </param>
		/// <returns>whether the input files to move to are set successfully.</returns>
		public bool setInputFilesToMoveTo(string[] paths){
			if(job.inputFilesToMoveTo == null) job.inputFilesToMoveTo = new DirectoriesAndFiles();
			job.inputFilesToMoveTo.path = paths;
			return true;
		}//setInputFilesToMoveTo

		/// <summary>
		/// Get the output files to copy from before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <returns>a string array of file paths to copy from. </returns>
		public string[] getOutputFilesToCopyFrom(){
			if(job.outputFilesToCopyFrom == null) return null;
			return job.outputFilesToCopyFrom.path;
		}//getOutputFilesToCopyFrom

		/// <summary>
		/// Set the output files to copy from before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <param name="paths">holds a string array of output files to copy from before running the job. </param>
		/// <returns>whether the output files to copy from are set successfully.</returns>
		public bool setOutputFilesToCopyFrom(string[] paths){
			if(job.outputFilesToCopyFrom == null) job.outputFilesToCopyFrom = new DirectoriesAndFiles();
			job.outputFilesToCopyFrom.path = paths;
			return true;
		}//setOutputFilesToCopyFrom

		/// <summary>
		/// Get the output files to copy to before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <returns>a string array of file paths to copy to. </returns>
		public string[] getOutputFilesToCopyTo(){
			if(job.outputFilesToCopyTo == null) return null;
			return job.outputFilesToCopyTo.path;
		}//getOutputFilesToCopyTo

		/// <summary>
		/// Set the output files to copy to before running the job, which is 
		/// a string array of paths.  
		/// </summary>
		/// <param name="paths">holds a string array of output files to copy to before running the job. </param>
		/// <returns>whether the output files to copy to are set successfully.</returns>
		public bool setOutputFilesToCopyTo(string[] paths){
			if(job.outputFilesToCopyTo == null) job.outputFilesToCopyTo = new DirectoriesAndFiles();
			job.outputFilesToCopyTo.path = paths;
			return true;
		}//setOutputFilesToCopyTo

		/// <summary>
		/// Get the output files to move from before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <returns>a string array of file paths to move from.</returns>
		public string[] getOutputFilesToMoveFrom(){
			if(job.outputFilesToMoveFrom == null) return null;
			return job.outputFilesToMoveFrom.path;
		}//getOutputFilesToMoveFrom

		/// <summary>
		/// Set the output files to move from before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <param name="paths">holds a string array of output files to move from before running the job. </param>
		/// <returns>whether the output files to move from are set successfully.</returns>
		public bool setOutputFilesToMoveFrom(string[] paths){
			if(job.outputFilesToMoveFrom == null) job.outputFilesToMoveFrom = new DirectoriesAndFiles();
			job.outputFilesToMoveFrom.path = paths;
			return true;
		}//setOutputFilesToMoveFrom

		/// <summary>
		/// Get the output files to move to before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <returns>a string array of file paths to move to. </returns>
		public string[] getOutputFilesToMoveTo(){
			if(job.outputFilesToMoveTo == null) return null;
			return job.outputFilesToMoveTo.path;
		}//getOutputFilesToMoveTo

		/// <summary>
		/// Set the output files to move to before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <param name="paths">holds a string array of output files to move to before running the job. </param>
		/// <returns>whether the output files to move to are set successfully.</returns>
		public bool setOutputFilesToMoveTo(string[] paths){
			if(job.outputFilesToMoveTo == null) job.outputFilesToMoveTo = new DirectoriesAndFiles();
			job.outputFilesToMoveTo.path = paths;
			return true;
		}//setOutputFilesToMoveTo

		/// <summary>
		/// Get the files to delete after running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <returns>a string array of file paths to delete. </returns>
		public string[] getFilesToDelete(){
			if(job.filesToDelete == null) return null;
			return job.filesToDelete.path;
		}//getFilesToDelete

		/// <summary>
		/// Set the files to delete after running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <param name="paths">holds a string array of file paths to delete after running the job. </param>
		/// <returns>whether the files to delete are set successfully.</returns>
		public bool setFilesToDelete(string[] paths){
			if(job.filesToDelete == null) job.filesToDelete = new DirectoriesAndFiles();
			job.filesToDelete.path = paths;
			return true;
		}//setFilesToDelete

		/// <summary>
		/// Get the directories to delete after running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <returns>a string array of directory paths to delete. </returns>
		public string[] getDirectoriesToDelete(){
			if(job.directoriesToDelete == null) return null;
			return job.directoriesToDelete.path;
		}//getDirectoriesToDelete

		/// <summary>
		/// Set the directories to delete after running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <param name="paths">holds a string array of directory paths to delete after running the job. </param>
		/// <returns>whether the directories to delete are set successfully.</returns>
		public bool setDirectoriesToDelete(string[] paths){
			if(job.directoriesToDelete == null) job.directoriesToDelete = new DirectoriesAndFiles();
			job.directoriesToDelete.path = paths;
			return true;
		}//setDirectoriesToDelete

		/// <summary>
		/// Get the processes to kill after running the job, which is 
		/// a string array of process names. 
		/// </summary>
		/// <returns>a string array of process names to kill. </returns>
		public string[] getProcessesToKill(){
			if(job.processesToKill == null) return null;
			return job.processesToKill.process;
		}//getProcessesToKill

		/// <summary>
		/// Set the processes to kill after running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <param name="processNames">holds a string array of process names to kill after running the job. </param>
		/// <returns>whether the processes to kill are set successfully.</returns>
		public bool setProcessesToKill(string[] processNames){
			if(job.processesToKill == null) job.processesToKill = new Processes();
			job.processesToKill.process = processNames;
			return true;
		}//setProcessesToKill

		/// <summary>
		/// Get variable number. 
		/// </summary>
		/// <returns> variable number, -1 if no information. </returns>
		public int getVariableNumber(){
			if(m_iVariableNumber == -1){
				if(optimization == null)  return -1;
				m_iVariableNumber = optimization.numberOfVariables;
			}
			return m_iVariableNumber;
		}//getVariableNumber

		/// <summary>
		/// Set the variable number. 
		/// </summary>
		/// <param name="variableNumber"> holds the number of variables</param>
		/// <returns> whether the variable number is set successfully or not. </returns>
		public bool setVariableNumber(int variableNumber){
			if(variableNumber < 0){
				return true;
			}
			if(optimization == null) optimization = new OptimizationOption();
			m_iVariableNumber = variableNumber;
			optimization.numberOfVariables = variableNumber;
			return true;
		}//setVariableNumber

		/// <summary>
		/// Get objective number. 
		/// </summary>
		/// <returns> objective number, -1 if no information. </returns>
		public int getObjectiveNumber(){
			if(m_iObjectiveNumber == -1){
				if(optimization == null) return -1;
				m_iObjectiveNumber = optimization.numberOfObjectives;
			}
			return m_iObjectiveNumber;
		}//getObjectiveNumber

		/// <summary>
		/// Set the objective number. 
		/// </summary>
		/// <param name="objectiveNumber"> holds the number of objectives</param>
		/// <returns> whether the objective number is set successfully or not. </returns>
		public bool setObjectiveNumber(int objectiveNumber){
			if(objectiveNumber < 0){
				return true;
			}
			if(optimization == null) optimization = new OptimizationOption();
			m_iObjectiveNumber = objectiveNumber;
			optimization.numberOfObjectives = objectiveNumber;
			return true;
		}//setObjectiveNumber
	
		/// <summary>
		/// Get constraint number. 
		/// </summary>
		/// <returns> constraint number, -1 if no information. </returns>
		public int getConstraintNumber(){
			if(m_iConstraintNumber == -1){
				
				if(optimization == null)  return -1;
				m_iConstraintNumber = optimization.numberOfConstraints;
			}
			return m_iConstraintNumber;
		}//getConstraintNumber

		/// <summary>
		/// Set the constraint number. 
		/// </summary>
		/// <param name="constraintNumber"> holds the number of constraints</param>
		/// <returns> whether the constraint number is set successfully or not. </returns>
		public bool setConstraintNumber(int constraintNumber){
			if(constraintNumber < 0){
				return true;
			}
			if(optimization == null) optimization = new OptimizationOption();
			m_iConstraintNumber = constraintNumber;
			optimization.numberOfConstraints = constraintNumber;
			return true;
		}//setConstraintNumber

		/// <summary>
		/// get initial variable values (double[]).
		/// </summary>
		/// <returns>a double array of the initial variable values, null if none. </returns>
		public double[] getInitialVariableValues(){//TODO
			if(optimization == null) return null;
			int iNumberOfVariables = this.getVariableNumber();
			if(iNumberOfVariables <= 0) return null;
			if(optimization.variables == null) return null;
			if(optimization.variables.initialVariableValues == null) return null;
			InitVarValue[] var = optimization.variables.initialVariableValues.var; 
			int iVars = (var==null)?0:var.Length;
			double[] mdValues = new double[iNumberOfVariables];
			for(int i = 0; i < iVars; i++){
				mdValues[var[i].idx] = var[i].value;
			}
			return mdValues;	
		}//getInitialVariableValues
	
		/// <summary>
		/// Set initial variable values (double[]). 
	    /// Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	    /// methods are recommended  to be called first. 
		/// </summary>
		/// <param name="initialVariableValues">holds a double array of initial variable values. </param>
		/// <returns>whether the initial variable values are set successfully or not. </returns>
		public bool setInitialVariableValues(double[] initialVariableValues){//TODO
			int iNumberOfVariables = this.getVariableNumber();
			if(iNumberOfVariables <= 0) return true;
			if(initialVariableValues != null && initialVariableValues.Length != iNumberOfVariables) return false;
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
			for(int i = 0; i < initialVariableValues.Length; i++){
				if(initialVariableValues[i] != 0) iVars++;
			}
			optimization.variables.initialVariableValues.var = new InitVarValue[iVars];
			InitVarValue[] var = optimization.variables.initialVariableValues.var;
			for(int i = 0; i < iVars; i++) var[i] = new InitVarValue();
			int j = 0;
			for(int i = 0; i < initialVariableValues.Length; i++){
				if(initialVariableValues[i] != 0){
					var[j].idx = i;
					var[j].value = initialVariableValues[i];
					j++;
				}
			}
			return true; 
		}//setInitialVariableValues

		/// <summary>
		/// get a string array of names of other options. 
		/// </summary>
		/// <returns>a string array of names of other options, null if no other options.  </returns>
		public string[] getOtherOptionNames(){
			if(other == null) return null;
			int n = other.Length;
			if(n <= 0) return null;
			string[] otherOptionNames = new string[n];
			for(int i = 0; i < n; i++){
				otherOptionNames[i] = other[i].name;
			}
			return otherOptionNames;
		}//getOtherOptionNames


		/// <summary>
		/// get a hashmap of other option descriptions. 
		/// The keys of the hashmap are the option names, and 
		///  the values of the hashmap are the option descriptions.  
		/// 
		/// </summary>
		/// <returns>a hashmap of other option descriptions, null if no other options. </returns>
		public Hashtable  getOtherOptionDescriptions(){
			if(other == null) return null;
			int n = other.Length;
			if(n <= 0) return null;
			Hashtable otherOptionDescriptions = new Hashtable();
			for(int i = 0; i < n; i++){
				otherOptionDescriptions.Add(other[i].name, other[i].description);
			}
			return otherOptionDescriptions;
		}//getOtherOptionDescriptions

		/// <summary>
		///  get a hashmap of other option values. 
		///  The keys of the hashmap are the option names, and 
		///  the values of the hashmap are the option values.  
		/// </summary>
		/// <returns>a hashmap of other option values, null if no other options. </returns>
		public Hashtable  getOtherOptionValues(){
			if(other == null) return null;
			int n = other.Length;
			if(n <= 0) return null;
			Hashtable otherOptionValues = new Hashtable();
			for(int i = 0; i < n; i++){
				otherOptionValues.Add(other[i].name, other[i].value);
			}
			return otherOptionValues;
		}//getOtherOptionValues


		/// <summary>
		/// set other options, with their names (required), descriptions (optional) and values (optional). 
		/// </summary>
		/// <param name="names">the names of the other options; it is required.  </param>
		/// <param name="descriptions">holds the descriptions of the other options; null if none. </param>
		/// <param name="values">the values of the other options; null if none. </param>
		/// <returns>whether the other anlysis information is set successfully. </returns>
		public bool setOtherOptions(string[] names, string[] descriptions, string[] values){
			if(names == null) return false;
			if(descriptions != null && descriptions.Length != names.Length) return false;
			if(values != null && values.Length != names.Length) return false;
			int n = names.Length;
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

	}//class OSOption
}//namespace
