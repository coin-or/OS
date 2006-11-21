using System;
using System.Collections;
using System.Xml;

using org.optimizationservices.oscommon.localinterface;
using org.optimizationservices.oscommon.util;
using org.optimizationservices.oscommon.datastructure.osoption;

namespace org.optimizationservices.oscommon.representationparser{
	///	<summary>
	///	The	<c>OSoLReader</c> class	parses an OSoL instance	into a DOM tree	and
	///	provides a set of "get"	methods	that can be	
	///	used to	retrieve different pieces of information of	the	instance.
	///	@author	Jun	Ma	
	///	@version 1.0, 09/01/2005
	///	@since OS 1.0
	///	@copyright (c) 2005
	///	</summary>
	public class OSoLReader	: OSgLReader{
		/// <summary>
		/// m_osOption holds the standard OSOption, which is a local interface for 
		/// storing Optimization Services option. 
		/// </summary>
		protected OSOption m_osOption = null;

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
		///	m_otherOptionHashMap holds a hash map of other options.
		///	</summary>
		protected Hashtable	m_otherOptionHashMap = null;

		///	<summary>
		///	m_otherOptionDescriptionHashMap holds a hash map of other options' descriptions.
		///	</summary>
		protected Hashtable	m_otherOptionDescriptionHashMap = null;

		///	<summary>
		///	constructor.
		///	</summary>
		///	<param name="validate">holds whether the reader	should be validating against the schema	or not.</param>
		public OSoLReader(bool validate){
			m_bXsdValidate = validate;
		}//constructor
	
		///	<summary>
		///	Default	constructor. 
		///	</summary>
		public OSoLReader(){
		}//constructor

		/// <summary>
		/// get the standard OSOption, a local interface for 
		/// storing Optimization Services option.
		/// </summary>
		/// <returns>the OSOption.</returns>
		public OSOption getOSOption(){
			if(m_osOption != null){
				return m_osOption;
			}
			m_osOption = new OSOption();
			if(!m_osOption.setServiceURI(getServiceURI())) throw new Exception("setServiceURI Unsuccessful");		
			if(!m_osOption.setServiceName(getServiceName())) throw new Exception("setServiceName Unsuccessful");		
			if(!m_osOption.setInstanceName(getInstanceName())) throw new Exception("setInstanceName Unsuccessful");		
			if(!m_osOption.setInstanceLocationType(getInstanceLocationType())) throw new Exception("setInstanceLocationType Unsuccessful");		
			if(!m_osOption.setInstanceAddress(getInstanceAddress())) throw new Exception("setInstanceAddress Unsuccessful");		
			if(!m_osOption.setJobID(getJobID())) throw new Exception("setJobID Unsuccessful");		
			if(!m_osOption.setLicense(getLicense())) throw new Exception("setLicense Unsuccessful");		
			if(!m_osOption.setUserName(getUserName())) throw new Exception("setUserName Unsuccessful");		
			if(!m_osOption.setPassword(getPassword())) throw new Exception("setPassword Unsuccessful");		
			if(!m_osOption.setContactTransportType(getContactTransportType())) throw new Exception("setContactTransportType Unsuccessful");		
			if(!m_osOption.setContactAddress(getContactAddress())) throw new Exception("setContactAddress Unsuccessful");		
			if(!m_osOption.setSystemMinDiskSpace(getSystemMinDiskSpace())) throw new Exception("setSystemMinDiskSpace Unsuccessful");		
			if(!m_osOption.setSystemMinMemorySize(getSystemMinMemorySize())) throw new Exception("setSystemMinMemorySize Unsuccessful");		
			if(!m_osOption.setSystemMinCPUSpeed(getSystemMinCPUSpeed())) throw new Exception("setSystemMinCPUSpeed Unsuccessful");		
			if(!m_osOption.setServiceType(getServiceType())) throw new Exception("setServiceType Unsuccessful");		
			if(!m_osOption.setJobMaxTime(getJobMaxTime())) throw new Exception("setJobMaxTime Unsuccessful");		
			if(!m_osOption.setJobScheduledStartTime(getJobScheduledStartTime())) throw new Exception("setJobScheduledStartTime Unsuccessful");		
			if(!m_osOption.setJobDependencies(getJobDependencies())) throw new Exception("setJobDependencies Unsuccessful");		
			if(!m_osOption.setRequiredDirectoriesAndFiles(getRequiredDirectoriesAndFiles())) throw new Exception("setRequiredDirectoriesAndFiles Unsuccessful");		
			if(!m_osOption.setDirectoriesToMake(getDirectoriesToMake())) throw new Exception("setDirectoriesToMake Unsuccessful");		
			if(!m_osOption.setFilesToCreate(getFilesToCreate())) throw new Exception("setFilesToCreate Unsuccessful");		
			if(!m_osOption.setInputFilesToCopyFrom(getInputFilesToCopyFrom())) throw new Exception("setInputFilesToCopyFrom Unsuccessful");		
			if(!m_osOption.setInputFilesToCopyTo(getInputFilesToCopyTo())) throw new Exception("setInputFilesToCopyTo Unsuccessful");		
			if(!m_osOption.setInputFilesToMoveFrom(getInputFilesToMoveFrom())) throw new Exception("setInputFilesToMoveFrom Unsuccessful");		
			if(!m_osOption.setInputFilesToMoveTo(getInputFilesToMoveTo())) throw new Exception("setInputFilesToMoveTo Unsuccessful");		
			if(!m_osOption.setOutputFilesToCopyFrom(getOutputFilesToCopyFrom())) throw new Exception("setOutputFilesToCopyFrom Unsuccessful");		
			if(!m_osOption.setOutputFilesToCopyTo(getOutputFilesToCopyTo())) throw new Exception("setOutputFilesToCopyTo Unsuccessful");		
			if(!m_osOption.setOutputFilesToMoveFrom(getOutputFilesToMoveFrom())) throw new Exception("setOutputFilesToMoveFrom Unsuccessful");		
			if(!m_osOption.setOutputFilesToMoveTo(getOutputFilesToMoveTo())) throw new Exception("setOutputFilesToMoveTo Unsuccessful");		
			if(!m_osOption.setFilesToDelete(getFilesToDelete())) throw new Exception("setFilesToDelete Unsuccessful");		
			if(!m_osOption.setDirectoriesToDelete(getDirectoriesToDelete())) throw new Exception("setDirectoriesToDelete Unsuccessful");		
			if(!m_osOption.setProcessesToKill(getProcessesToKill())) throw new Exception("setProcessesToKill Unsuccessful");		
			if(!m_osOption.setVariableNumber(getVariableNumber())) throw new Exception("setVariableNumber Unsuccessful");		
			if(!m_osOption.setObjectiveNumber(getObjectiveNumber())) throw new Exception("setObjectiveNumber Unsuccessful");		
			if(!m_osOption.setConstraintNumber(getConstraintNumber())) throw new Exception("setConstraintNumber Unsuccessful");		
			if(!m_osOption.setInitialVariableValues(getInitialVariableValues())) throw new Exception("setInitialVariableValues Unsuccessful");		
			if(!m_osOption.setOtherOptions(getOtherOptionNames(), getOtherOptionDescriptions(), getOtherOptionValues())) throw new Exception("setOtherEntityInfo Unsuccessful");
			return m_osOption;
		}//getOSOption
	

		/// <summary>
		/// Get service uri.
		/// </summary>
		/// <returns>the service uri. </returns>
		public string getServiceURI(){
			XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(m_eRoot, "general");
			if(eGeneral == null) return "";
			string sServiceURI = XMLUtil.getElementValueByName(eGeneral, "serviceURI");
			if(sServiceURI == null) return "";
			return sServiceURI;	

		}//getServiceURI

		/// <summary>
		/// Get service name.
		/// </summary>
		/// <returns>the service name. </returns>
		public string getServiceName(){
			XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(m_eRoot, "general");
			if(eGeneral == null) return "";
			string sServiceName = XMLUtil.getElementValueByName(eGeneral, "serviceName");
			if(sServiceName == null) return "";
			return sServiceName;	
		}//getServiceName


		/// <summary>
		/// Get instance name.
		/// </summary>
		/// <returns>the instance name.</returns>
		public string getInstanceName(){
			XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(m_eRoot, "general");
			if(eGeneral == null) return "";
			string sInstanceName = XMLUtil.getElementValueByName(eGeneral, "instanceName");
			if(sInstanceName == null) return "";
			return sInstanceName;	
		}//getInstanceName

		/// <summary>
		/// Get the instance location type to get the instance. 
		/// e.g. local, http, ftp.
		/// </summary>
		/// <returns>the instance location type, null or empty string if none. </returns>
		public string getInstanceLocationType(){
			XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(m_eRoot, "general");
			if(eGeneral == null) return "";
			XmlElement eInstanceLocation = (XmlElement)XMLUtil.findChildNode(eGeneral, "instanceLocation");
			if(eInstanceLocation == null) return "";
			string sLocationType = eInstanceLocation.GetAttribute("locationType");
			if(sLocationType == null || sLocationType.Length <= 0) return "local";
			return sLocationType;
		}//getInstanceLocationType
	
		/// <summary>
		/// Get the instance address to get the instance. 
		/// </summary>
		/// <returns>the instance address, null or empty string if none. </returns>
		public string getInstanceAddress(){
			XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(m_eRoot, "general");
			if(eGeneral == null) return "";
			string sInstanceAddress = XMLUtil.getElementValueByName(eGeneral, "instanceLocation");
			if(sInstanceAddress == null) return "";
			return sInstanceAddress;
		}//getInstanceAddress

		/// <summary>
		/// Get job ID. 
		/// </summary>
		/// <returns>the job ID, null or empty string if none. </returns>
		public string getJobID(){
			XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(m_eRoot, "general");
			if(eGeneral == null) return "";
			string sJobID = XMLUtil.getElementValueByName(eGeneral, "jobID");
			if(sJobID == null) return "";
			return sJobID;	
		}//getJobID


		/// <summary>
		/// Get license. 
		/// </summary>
		/// <returns>the license, null or empty string if none. </returns>
		public string getLicense(){
			XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(m_eRoot, "general");
			if(eGeneral == null) return "";
			string sLicense = XMLUtil.getElementValueByName(eGeneral, "license");
			if(sLicense == null) return "";
			return sLicense;
		}//getLicense

		/// <summary>
		/// Get the userName. 
		/// </summary>
		/// <returns>the user name, null or empty string if none. </returns>
		public string getUserName(){
			XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(m_eRoot, "general");
			if(eGeneral == null) return "";
			string sUserName = XMLUtil.getElementValueByName(eGeneral, "userName");
			if(sUserName == null) return "";
			return sUserName;
		}//getUserName


		/// <summary>
		/// Get the password. 
		/// </summary>
		/// <returns>the password, null or empty string if none. </returns>
		public string getPassword(){
			XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(m_eRoot, "general");
			if(eGeneral == null) return "";
			string sPassword = XMLUtil.getElementValueByName(eGeneral, "password");
			if(sPassword == null) return "";
			return sPassword;
		}//getPassword

		/// <summary>
		/// Get the contact transport type to respond to the requester,
		/// smtp (for email), osp (for knocking back on the requester), etc.
		/// </summary>
		/// <returns>the contact trasport type, null or empty string if none. </returns>
		public string getContactTransportType(){
			XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(m_eRoot, "general");
			if(eGeneral == null) return "";
			XmlElement eContact = (XmlElement)XMLUtil.findChildNode(eGeneral, "contact");
			if(eContact == null) return "";
			string sTransportType = eContact.GetAttribute("transportType");
			if(sTransportType == null || sTransportType.Length <= 0) return "osp";
			return sTransportType;
		}//getContactTransportType


		/// <summary>
		/// Get the contact address to respond to the requester. 
		/// For example it can be an email address if the contact transport type is smtp
		/// or a http uri if the contact transport type is osp (for knocking back on the requester), etc.
		/// </summary>
		/// <returns>the contact trasport address, null or empty string if none. </returns>
		public string getContactAddress(){
			XmlElement eGeneral = (XmlElement)XMLUtil.findChildNode(m_eRoot, "general");
			if(eGeneral == null) return "";
			string sContactAddress = XMLUtil.getElementValueByName(eGeneral, "contact");
			if(sContactAddress == null) return "";
			return sContactAddress;
		}//getContactAddress

		
		/// <summary>
		/// Get the system minimum disk space required to solve the job. 
		/// </summary>
		/// <returns>the system minimum disk space, 0.0 if none. </returns>
		public double getSystemMinDiskSpace(){
			XmlElement eSystem = (XmlElement)XMLUtil.findChildNode(m_eRoot, "system");
			if(eSystem == null) return 0.0;
			string sMinDiskSpace = XMLUtil.getElementValueByName(eSystem, "minDiskSpace");
			if(sMinDiskSpace == null || sMinDiskSpace.Length <= 0) return 0.0;
			try{
				double dMinDiskSpace = Double.Parse(sMinDiskSpace);
				return dMinDiskSpace;
			}
			catch(Exception){
				return 0.0;
			}
		}//getSystemMinDiskSpace
	

		/// <summary>
		/// Get the system minimum memory size required to solve the job. 
		/// </summary>
		/// <returns>the system minimum memory size, 0.0 if none. </returns>
		public double getSystemMinMemorySize(){
			XmlElement eSystem = (XmlElement)XMLUtil.findChildNode(m_eRoot, "system");
			if(eSystem == null) return 0.0;
			string sMinMemorySize = XMLUtil.getElementValueByName(eSystem, "minMemorySize");
			if(sMinMemorySize == null || sMinMemorySize.Length <= 0) return 0.0;
			try{
				double dMinMemorySize = Double.Parse(sMinMemorySize);
				return dMinMemorySize;
			}
			catch(Exception){
				return 0.0;
			}
		}//getSystemMinMeorySize

		/// <summary>
		/// Get the system minimum cpu speed required to solve the job. 
		/// </summary>
		/// <returns>the system minimum cpu speed, 0.0 if none. </returns>
		public double getSystemMinCPUSpeed(){
			XmlElement eSystem = (XmlElement)XMLUtil.findChildNode(m_eRoot, "system");
			if(eSystem == null) return 0.0;
			string sMinCPUSpeed = XMLUtil.getElementValueByName(eSystem, "minCPUSpeed");
			if(sMinCPUSpeed == null || sMinCPUSpeed.Length <= 0) return 0.0;
			try{
				double dMinCPUSpeed = Double.Parse(sMinCPUSpeed);
				return dMinCPUSpeed;
			}
			catch(Exception){
				return 0.0;
			}
		}//getSystemMinCPUSpeed

		/// <summary>
		/// Get the service type, which can be: 
		/// solver, analyzer, scheduler, simulation, registry, modeler, agent 
		/// </summary>
		/// <returns>the service type; null or empty string if none. </returns>
		public string getServiceType(){
			XmlElement eService = (XmlElement)XMLUtil.findChildNode(m_eRoot, "service");
			if(eService == null) return "solver";
			string sServiceType = XMLUtil.getElementValueByName(eService, "type");
			if(sServiceType == null || sServiceType.Length <= 0) return "solver";
			return sServiceType;
		}//getServiceType


		/// <summary>
		/// Get the maximum time (in seconds) before the job is terminated. 
		/// </summary>
		/// <returns>the maximum time, Double.PositiveInfinity if none. </returns>
		public double getJobMaxTime(){
			XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eRoot, "job");
			if(eJob == null) return Double.PositiveInfinity;
			string sJobMaxTime = XMLUtil.getElementValueByName(eJob, "maxTime");
			if(sJobMaxTime == null || sJobMaxTime.Length <= 0) return Double.PositiveInfinity;
			try{
				double dJobMaxTime = Double.Parse(sJobMaxTime);
				return dJobMaxTime;
			}
			catch(Exception){
				return Double.PositiveInfinity;
			}
		}//getJobMaxTime


		/// <summary>
		/// Get the scheduled start time for the job.   
		/// </summary>
		/// <returns>the scheduled start time for the job, null or UNIX time (1970/1/1) if none.</returns>
		public DateTime getJobScheduledStartTime(){ 
			XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eRoot, "job");
			if(eJob == null) return new DateTime(1970, 1, 1, 0, 0, 0);
			string sJobScheduledStartTime = XMLUtil.getElementValueByName(eJob, "scheduledStartTime");
			if(sJobScheduledStartTime == null || sJobScheduledStartTime.Length <= 0) return new DateTime(1970, 1, 1, 0, 0, 0);
			try{
				DateTime jobScheduledStartTime = XMLUtil.createNativeDateTime(sJobScheduledStartTime);
				return jobScheduledStartTime;
			}
			catch(Exception){
				return new DateTime(1970, 1, 1, 0, 0, 0);
			}
		}//getJobScheduledStartTime

		/// <summary>
		/// Get the dependencies of the current job, which is 
		/// a string array of ids of the jobs that have run before the current job. 
		/// </summary>
		/// <returns>a string array of ids of the jobs that have run before the current job, null if none. </returns>
		public string[] getJobDependencies(){
			XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eRoot, "job");
			if(eJob == null) return null;
			XmlElement eDependencies = (XmlElement)XMLUtil.findChildNode(eJob, "dependencies");
			if(eDependencies == null) return null;
			XmlNodeList jobIDs = eDependencies.GetElementsByTagName("jobID");
			if(jobIDs == null || jobIDs.Count <= 0) return null;
			int iJobIDs = jobIDs.Count;
			string[] msJobIDs = new string[iJobIDs];
			for(int i = 0; i < iJobIDs; i++){
				msJobIDs[i] = XMLUtil.getElementValue((XmlElement)jobIDs.Item(i));
			}
			return msJobIDs;
		}//getJobDependencies

		/// <summary>
		/// Get the required directories and files to run the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <returns>a string array of direcotry/file paths required to run the job. </returns>
		public string[] getRequiredDirectoriesAndFiles(){
			XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eRoot, "job");
			if(eJob == null) return null;
			XmlElement eRequiredDirectoriesAndFiles = (XmlElement)XMLUtil.findChildNode(eJob, "requiredDirectoriesAndFiles");
			if(eRequiredDirectoriesAndFiles == null) return null;
			XmlNodeList paths = eRequiredDirectoriesAndFiles.GetElementsByTagName("path");
			if(paths == null || paths.Count <= 0) return null;
			int iPaths = paths.Count;
			string[] msPaths = new string[iPaths];
			for(int i = 0; i < iPaths; i++){
				msPaths[i] = XMLUtil.getElementValue((XmlElement)paths.Item(i));
			}
			return msPaths;
		}//getRequiredDirectoriesAndFiles

		/// <summary>
		/// Get the directories to make before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <returns>a string array of direcotry paths to make. </returns>
		public string[] getDirectoriesToMake(){
			XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eRoot, "job");
			if(eJob == null) return null;
			XmlElement eDirectoriesToMake = (XmlElement)XMLUtil.findChildNode(eJob, "directoriesToMake");
			if(eDirectoriesToMake == null) return null;
			XmlNodeList paths = eDirectoriesToMake.GetElementsByTagName("path");
			if(paths == null || paths.Count <= 0) return null;
			int iPaths = paths.Count;
			string[] msPaths = new string[iPaths];
			for(int i = 0; i < iPaths; i++){
				msPaths[i] = XMLUtil.getElementValue((XmlElement)paths.Item(i));
			}
			return msPaths;
		}//getDirectoriesToMake

		/// <summary>
		/// Get the files to create before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <returns>a string array of file paths to create. </returns>
		public string[] getFilesToCreate(){
			XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eRoot, "job");
			if(eJob == null) return null;
			XmlElement eFilesToCreate = (XmlElement)XMLUtil.findChildNode(eJob, "filesToCreate");
			if(eFilesToCreate == null) return null;
			XmlNodeList paths = eFilesToCreate.GetElementsByTagName("path");
			if(paths == null || paths.Count <= 0) return null;
			int iPaths = paths.Count;
			string[] msPaths = new string[iPaths];
			for(int i = 0; i < iPaths; i++){
				msPaths[i] = XMLUtil.getElementValue((XmlElement)paths.Item(i));
			}
			return msPaths;
		}//getFilesToCreate

		/// <summary>
		/// Get the input files to copy from before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <returns>a string array of file paths to copy from. </returns>
		public string[] getInputFilesToCopyFrom(){
			XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eRoot, "job");
			if(eJob == null) return null;
			XmlElement eInputFilesToCopyFrom = (XmlElement)XMLUtil.findChildNode(eJob, "inputFilesToCopyFrom");
			if(eInputFilesToCopyFrom == null) return null;
			XmlNodeList paths = eInputFilesToCopyFrom.GetElementsByTagName("path");
			if(paths == null || paths.Count <= 0) return null;
			int iPaths = paths.Count;
			string[] msPaths = new string[iPaths];
			for(int i = 0; i < iPaths; i++){
				msPaths[i] = XMLUtil.getElementValue((XmlElement)paths.Item(i));
			}
			return msPaths;
		}//getInputFilesToCopyFrom

		/// <summary>
		/// Get the input files to copy to before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <returns>a string array of file paths to copy to. </returns>
		public string[] getInputFilesToCopyTo(){
			XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eRoot, "job");
			if(eJob == null) return null;
			XmlElement eInputFilesToCopyTo = (XmlElement)XMLUtil.findChildNode(eJob, "inputFilesToCopyTo");
			if(eInputFilesToCopyTo == null) return null;
			XmlNodeList paths = eInputFilesToCopyTo.GetElementsByTagName("path");
			if(paths == null || paths.Count <= 0) return null;
			int iPaths = paths.Count;
			string[] msPaths = new string[iPaths];
			for(int i = 0; i < iPaths; i++){
				msPaths[i] = XMLUtil.getElementValue((XmlElement)paths.Item(i));
			}
			return msPaths;
		}//getInputFilesToCopyTo

		/// <summary>
		/// Get the input files to move from before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <returns>a string array of file paths to move from. </returns>
		public string[] getInputFilesToMoveFrom(){
			XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eRoot, "job");
			if(eJob == null) return null;
			XmlElement eInputFilesToMoveFrom = (XmlElement)XMLUtil.findChildNode(eJob, "inputFilesToMoveFrom");
			if(eInputFilesToMoveFrom == null) return null;
			XmlNodeList paths = eInputFilesToMoveFrom.GetElementsByTagName("path");
			if(paths == null || paths.Count <= 0) return null;
			int iPaths = paths.Count;
			string[] msPaths = new string[iPaths];
			for(int i = 0; i < iPaths; i++){
				msPaths[i] = XMLUtil.getElementValue((XmlElement)paths.Item(i));
			}
			return msPaths;
		}//getInputFilesToMoveFrom

		/// <summary>
		/// Get the input files to move to before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <returns>a string array of file paths to move to. </returns>
		public string[] getInputFilesToMoveTo(){
			XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eRoot, "job");
			if(eJob == null) return null;
			XmlElement eInputFilesToMoveTo = (XmlElement)XMLUtil.findChildNode(eJob, "inputFilesToMoveTo");
			if(eInputFilesToMoveTo == null) return null;
			XmlNodeList paths = eInputFilesToMoveTo.GetElementsByTagName("path");
			if(paths == null || paths.Count <= 0) return null;
			int iPaths = paths.Count;
			string[] msPaths = new string[iPaths];
			for(int i = 0; i < iPaths; i++){
				msPaths[i] = XMLUtil.getElementValue((XmlElement)paths.Item(i));
			}
			return msPaths;
		}//getInputFilesToMoveTo

		/// <summary>
		/// Get the output files to copy from before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <returns>a string array of file paths to copy from. </returns>
		public string[] getOutputFilesToCopyFrom(){
			XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eRoot, "job");
			if(eJob == null) return null;
			XmlElement eOutputFilesToCopyFrom = (XmlElement)XMLUtil.findChildNode(eJob, "outputFilesToCopyFrom");
			if(eOutputFilesToCopyFrom == null) return null;
			XmlNodeList paths = eOutputFilesToCopyFrom.GetElementsByTagName("path");
			if(paths == null || paths.Count <= 0) return null;
			int iPaths = paths.Count;
			string[] msPaths = new string[iPaths];
			for(int i = 0; i < iPaths; i++){
				msPaths[i] = XMLUtil.getElementValue((XmlElement)paths.Item(i));
			}
			return msPaths;

		}//getOutputFilesToCopyFrom

		/// <summary>
		/// Get the output files to copy to before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <returns>a string array of file paths to copy to. </returns>
		public string[] getOutputFilesToCopyTo(){
			XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eRoot, "job");
			if(eJob == null) return null;
			XmlElement eOutputFilesToCopyTo = (XmlElement)XMLUtil.findChildNode(eJob, "outputFilesToCopyTo");
			if(eOutputFilesToCopyTo == null) return null;
			XmlNodeList paths = eOutputFilesToCopyTo.GetElementsByTagName("path");
			if(paths == null || paths.Count <= 0) return null;
			int iPaths = paths.Count;
			string[] msPaths = new string[iPaths];
			for(int i = 0; i < iPaths; i++){
				msPaths[i] = XMLUtil.getElementValue((XmlElement)paths.Item(i));
			}
			return msPaths;
		}//getOutputFilesToCopyTo

		/// <summary>
		/// Get the output files to move from before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <returns>a string array of file paths to move from.</returns>
		public string[] getOutputFilesToMoveFrom(){
			XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eRoot, "job");
			if(eJob == null) return null;
			XmlElement eOutputFilesToMoveFrom = (XmlElement)XMLUtil.findChildNode(eJob, "outputFilesToMoveFrom");
			if(eOutputFilesToMoveFrom == null) return null;
			XmlNodeList paths = eOutputFilesToMoveFrom.GetElementsByTagName("path");
			if(paths == null || paths.Count <= 0) return null;
			int iPaths = paths.Count;
			string[] msPaths = new string[iPaths];
			for(int i = 0; i < iPaths; i++){
				msPaths[i] = XMLUtil.getElementValue((XmlElement)paths.Item(i));
			}
			return msPaths;

		}//getOutputFilesToMoveFrom

		/// <summary>
		/// Get the output files to move to before running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <returns>a string array of file paths to move to. </returns>
		public string[] getOutputFilesToMoveTo(){
			XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eRoot, "job");
			if(eJob == null) return null;
			XmlElement eOutputFilesToMoveTo = (XmlElement)XMLUtil.findChildNode(eJob, "outputFilesToMoveTo");
			if(eOutputFilesToMoveTo == null) return null;
			XmlNodeList paths = eOutputFilesToMoveTo.GetElementsByTagName("path");
			if(paths == null || paths.Count <= 0) return null;
			int iPaths = paths.Count;
			string[] msPaths = new string[iPaths];
			for(int i = 0; i < iPaths; i++){
				msPaths[i] = XMLUtil.getElementValue((XmlElement)paths.Item(i));
			}
			return msPaths;
		}//getOutputFilesToMoveTo

		/// <summary>
		/// Get the files to delete after running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <returns>a string array of file paths to delete. </returns>
		public string[] getFilesToDelete(){
			XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eRoot, "job");
			if(eJob == null) return null;
			XmlElement eFilesToDelete = (XmlElement)XMLUtil.findChildNode(eJob, "filesToDelete");
			if(eFilesToDelete == null) return null;
			XmlNodeList paths = eFilesToDelete.GetElementsByTagName("path");
			if(paths == null || paths.Count <= 0) return null;
			int iPaths = paths.Count;
			string[] msPaths = new string[iPaths];
			for(int i = 0; i < iPaths; i++){
				msPaths[i] = XMLUtil.getElementValue((XmlElement)paths.Item(i));
			}
			return msPaths;
		}//getFilesToDelete

		/// <summary>
		/// Get the directories to delete after running the job, which is 
		/// a string array of paths. 
		/// </summary>
		/// <returns>a string array of directory paths to delete. </returns>
		public string[] getDirectoriesToDelete(){
			XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eRoot, "job");
			if(eJob == null) return null;
			XmlElement eDirectoriesToDelete = (XmlElement)XMLUtil.findChildNode(eJob, "directoriesToDelete");
			if(eDirectoriesToDelete == null) return null;
			XmlNodeList paths = eDirectoriesToDelete.GetElementsByTagName("path");
			if(paths == null || paths.Count <= 0) return null;
			int iPaths = paths.Count;
			string[] msPaths = new string[iPaths];
			for(int i = 0; i < iPaths; i++){
				msPaths[i] = XMLUtil.getElementValue((XmlElement)paths.Item(i));
			}
			return msPaths;

		}//getDirectoriesToDelete

		/// <summary>
		/// Get the processes to kill after running the job, which is 
		/// a string array of process names. 
		/// </summary>
		/// <returns>a string array of process names to kill. </returns>
		public string[] getProcessesToKill(){
			XmlElement eJob = (XmlElement)XMLUtil.findChildNode(m_eRoot, "job");
			if(eJob == null) return null;
			XmlElement eProcessesToKill = (XmlElement)XMLUtil.findChildNode(eJob, "processesToKill");
			if(eProcessesToKill == null) return null;
			XmlNodeList processess = eProcessesToKill.GetElementsByTagName("process");
			if(processess == null || processess.Count <= 0) return null;
			int iProcesses = processess.Count;
			string[] msProcesses = new string[iProcesses];
			for(int i = 0; i < iProcesses; i++){
				msProcesses[i] = XMLUtil.getElementValue((XmlElement)processess.Item(i));
			}
			return msProcesses;
		}//getProcessesToKill

		/// <summary>
		/// Get variable number. 
		/// </summary>
		/// <returns>variable number, -1 if no information. </returns>
		public int getVariableNumber(){
			if(m_iVariableNumber == -1){
				XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eRoot, "optimization");
				if(eOptimization == null) return -1;
				String sNumber =  eOptimization.GetAttribute("numberOfVariables");
				try{
					m_iVariableNumber = Int32.Parse(sNumber);
				}
				catch(Exception){
				}
			}
			return m_iVariableNumber;
		}//getVariableNumber
		
		/// <summary>
		/// Get objective number. 
		/// </summary>
		/// <returns>objective number, -1 if no information. </returns>
		public int getObjectiveNumber(){
			if(m_iObjectiveNumber == -1){
				XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eRoot, "optimization");
				if(eOptimization == null) return -1;
				String sNumber =  eOptimization.GetAttribute("numberOfObjectives");
				try{
					m_iObjectiveNumber = Int32.Parse(sNumber);
				}
				catch(Exception){
				}
			}
			return m_iObjectiveNumber;
		}//getObjectiveNumber

		/// <summary>
		/// Get constraint number. 
		/// </summary>
		/// <returns>constraint number, -1 if no information. </returns>
		public int getConstraintNumber(){
			if(m_iConstraintNumber == -1){
				XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eRoot, "optimization");
				if(eOptimization == null) return -1;
				String sNumber =  eOptimization.GetAttribute("numberOfConstraints");
				try{
					m_iConstraintNumber = Int32.Parse(sNumber);
				}
				catch(Exception){
				}
			}
			return m_iConstraintNumber;
		}//getConstraintNumber

		/// <summary>
		/// get initial variable values (double[]).
		/// </summary>
		/// <returns>a double array of the initial variable values, null if none. </returns>
		public double[] getInitialVariableValues(){//TODO
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(m_eRoot, "optimization");
			if(eOptimization == null) return null;
			XmlElement eVariables = (XmlElement)XMLUtil.findChildNode(eOptimization, "variables");
			if(eVariables == null) return null;
			XmlElement eInitialVariableValues = (XmlElement)XMLUtil.findChildNode(eVariables, "initialVariableValues");
			if(eInitialVariableValues == null) return null;
			XmlNodeList vars = eInitialVariableValues.GetElementsByTagName("var");
			if(vars == null || vars.Count <= 0) return null;
			int iVars = vars.Count;
			int iNumberVairables = this.getVariableNumber();
			double[] mdValues = new double[iNumberVairables];
			for(int i = 0; i < iVars; i++){
				try{
					int iIndex = Int32.Parse(((XmlElement)vars.Item(i)).GetAttribute("idx"));
					double dValue = Double.Parse(((XmlElement)vars.Item(i)).GetAttribute("value"));
					mdValues[iIndex] = dValue;
				}
				catch(Exception){
					return null;
				}
			}
			return mdValues;
		}//getInitialVariableValues

		/// <summary>
		/// Get the hash map of other options. 
		/// </summary>
		/// <returns>the hash map of other options.</returns>
		public Hashtable getOtherOptions(){
			if(m_otherOptionHashMap != null) return m_otherOptionHashMap;
			m_otherOptionHashMap = new Hashtable();
			m_otherOptionDescriptionHashMap = new Hashtable();

			ArrayList vNodeList = XMLUtil.getChildElementsByTagName(m_eRoot, "other"); 
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
				m_otherOptionHashMap.Add(sName, sValue);
				m_otherOptionDescriptionHashMap.Add(sName, sDescription);
			}
			return m_otherOptionHashMap;
		}//getOtherOptions

		/// <summary>
		/// Get the number of other options.  
		/// </summary>
		/// <returns>the number of other options. </returns>
		public int getOtherOptionNumber(){
			getOtherOptions();
			return m_otherOptionHashMap.Count;
		}//getOtherOptionNumber

		/// <summary>
		/// Get the string value from the other option hash map. 
		/// </summary>
		/// <param name="name">holds the name of option to get. </param>
		/// <returns>string value from the other option hash map, null if none. </returns>
		public string getOtherOptionValueByName(string name){
			getOtherOptions();
			if(m_otherOptionHashMap.Contains(name)){
				return (string)m_otherOptionHashMap[name];
			}
			else{ 
				return null;
			}
		}//getOtherOptionValueByName

		/// <summary>
		/// Get the string value from the other option hash map. 
		/// </summary>
		/// <param name="name">holds the name of option to get. </param>
		/// <returns>string value from the other option hash map, null if none. </returns>
		public string getOtherOptionDescriptionByName(string name){
			getOtherOptions();
			if(m_otherOptionDescriptionHashMap.Contains(name)){
				return (string)m_otherOptionDescriptionHashMap[name];
			}
			else{ 
				return null;
			}
		}//getOtherOptionDescriptionByName

		/// <summary>
		/// Get the names of all other options. 
		/// </summary>
		/// <returns>the names of all other options. </returns>
		public string[] getOtherOptionNames(){
			getOtherOptions();	
			System.Collections.ICollection nameCollection = m_otherOptionHashMap.Keys;
			string[] msName = new string[nameCollection.Count];
			IDictionaryEnumerator dictionaryEnumerator = m_otherOptionHashMap.GetEnumerator();
			int i = 0;
			while(dictionaryEnumerator.MoveNext()){
				msName[i] = (string)dictionaryEnumerator.Key;
				i++;
			}
			return msName;
		}//getOtherOptionNames

		/// <summary>
		/// Get the values of all other options. 
		/// </summary>
		/// <returns>the values of all other options. </returns>
		public string[] getOtherOptionValues(){
			getOtherOptions();	
			System.Collections.ICollection valueCollection = m_otherOptionHashMap.Values;
			string[] msValue = new string[valueCollection.Count];
			IDictionaryEnumerator dictionaryEnumerator = m_otherOptionHashMap.GetEnumerator();
			int i = 0;
			while(dictionaryEnumerator.MoveNext()){
				msValue[i] = (string)dictionaryEnumerator.Value;
				i++;
			}
			return msValue;
		}//getOtherOptionValues

		/// <summary>
		/// Get the descriptions of all other options. 
		/// </summary>
		/// <returns>the descriptions of all other options. </returns>
		public string[] getOtherOptionDescriptions(){
			getOtherOptions();	
			System.Collections.ICollection descriptionCollection = m_otherOptionDescriptionHashMap.Values;
			string[] msDescription = new string[descriptionCollection.Count];
			IDictionaryEnumerator dictionaryEnumerator = m_otherOptionDescriptionHashMap.GetEnumerator();
			int i = 0;
			while(dictionaryEnumerator.MoveNext()){
				msDescription[i] = (string)dictionaryEnumerator.Value;
				i++;
			}
			return msDescription;
		}//getOtherOptionDescriptions

	}//class OSoLReader
}//namespace