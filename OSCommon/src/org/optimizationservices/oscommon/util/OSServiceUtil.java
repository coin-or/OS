/**
 * @(#)OSServiceUtil 1.0 05/20/2005
 *
 *
 * Copyright (c) 2006 	Robert Fourer, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying file for terms. 
 */

package org.optimizationservices.oscommon.util;

import java.util.Calendar;
import java.util.Enumeration;
import java.util.GregorianCalendar;
import java.util.Hashtable;
import java.util.Timer;
import java.util.TimerTask;
import java.util.Vector;

import org.optimizationservices.oscommon.communicationagent.OSRegistryAgent;
import org.optimizationservices.oscommon.communicationagent.OSSolverAgent;
import org.optimizationservices.oscommon.datastructure.osgeneral.DirectoriesAndFiles;
import org.optimizationservices.oscommon.datastructure.osgeneral.JobDependencies;
import org.optimizationservices.oscommon.datastructure.osprocess.JobStatistics;
import org.optimizationservices.oscommon.datastructure.osprocess.OptimizationProcess;
import org.optimizationservices.oscommon.datastructure.osprocess.ProcessStatistics;
import org.optimizationservices.oscommon.datastructure.osquery.StandardQuery;
import org.optimizationservices.oscommon.datastructure.osuri.URI;
import org.optimizationservices.oscommon.localinterface.DefaultSimulation;
import org.optimizationservices.oscommon.localinterface.DefaultSolver;
import org.optimizationservices.oscommon.localinterface.OSOption;
import org.optimizationservices.oscommon.representationparser.OSiLReader;
import org.optimizationservices.oscommon.representationparser.OSiLWriter;
import org.optimizationservices.oscommon.representationparser.OSoLReader;
import org.optimizationservices.oscommon.representationparser.OSoLWriter;
import org.optimizationservices.oscommon.representationparser.OSpLReader;
import org.optimizationservices.oscommon.representationparser.OSpLWriter;
import org.optimizationservices.oscommon.representationparser.OSqLReader;
import org.optimizationservices.oscommon.representationparser.OSqLWriter;
import org.optimizationservices.oscommon.representationparser.OSrLReader;
import org.optimizationservices.oscommon.representationparser.OSrLWriter;
import org.optimizationservices.oscommon.representationparser.OSsLReader;
import org.optimizationservices.oscommon.representationparser.OSsLWriter;
import org.optimizationservices.oscommon.representationparser.OSuLReader;
import org.optimizationservices.oscommon.representationparser.OSuLWriter;

/**
 *
 * <P>The <code>OSServiceUtil</code> class provides a default implementation
 * for the optimization services.  
 *   
 *
 * </p>
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0 
 */
public class OSServiceUtil{// implements OShL{
	
	/**
	 * m_sSystemPassword holds the password used for communication between system components.
	 */
	private static String m_sSystemPassword = "";
	
	/**
	 * m_bSendEmailOnLowDiskSpace holds whether an email has been sent on low disk space warning. 
	 */
	private static boolean m_bSendEmailOnLowDiskSpace = false;

	/**
	 *  m_bValidate holds whether the parser should be validating against the xml schema or not
	 */
	protected boolean m_bValidate = OSParameter.VALIDATE; 
	
	/**
	 * serviceURI holds the service uri. 
	 */
	public String serviceURI = OSParameter.SERVICE_URI;
	
	/**
	 * serviceName holds the service name. 
	 */
	public String serviceName = OSParameter.SERVICE_NAME;
	
	/**
	 * serviceType holds the service type. 
	 */
	public String serviceType = OSParameter.SERVICE_TYPE;
	
	/**
	 * m_sServiceURIInOSoL holds the service uri in osol. 
	 */
	public String m_sServiceURIInOSoL = "";
	
	/**
	 * m_sServiceNameInOSoL holds the service name in osol. 
	 */
	public String m_sServiceNameInOSoL = "";
	
	/**
	 * m_sInstanceName holds the name of the instance being solved.
	 */
	protected String m_sInstanceName = "";
	
	/**
	 * m_sInstanceLocationType holds the instance location type. 
	 */
	protected String m_sInstanceLocationType = "";

	/**
	 * m_sInstanceAddress holds the instance address. 
	 */
	protected String m_sInstanceAddress = "";

	/**
	 * m_sJobID holds the job ID;
	 */
	protected String m_sJobID = "";
	
	/**
	 * m_sLicense holds the license. 
	 */
	protected String m_sLicense = "";

	/**
	 * m_sUserName holds the user name. 
	 */
	protected String m_sUserName = "";

	/**
	 * m_sPassword holds the password. 
	 */
	protected String m_sPassword = "";
	
	/**
	 * m_sContactTransportType holds the constact transport type. 
	 */
	protected String m_sContactTransportType = "";

	/**
	 * m_sContactAddress holds the contact address. 
	 */
	protected String m_sContactAddress = "";
	
	/**
	 * m_dMinDiskSpace holds the minimum disk sapce required by the job. 
	 */
	protected double m_dMinDiskSpace = 0;

	/**
	 * m_dMinMemorySize holds the minimum memory size required by the job. 
	 */
	protected double m_dMinMemorySize = 0;

	/**
	 * m_dMinCPUSpeed holds the minimum cpu speed required by the job. 
	 */
	protected double m_dMinCPUSpeed = 0;

	/**
	 * m_sServiceTypeInOSoL holds the service type in the osol
	 */
	protected String m_sServiceTypeInOSoL = "";
	
	/**
	 * m_dJobMaxTime holds the maximum time allowed for the job. 
	 */
	protected double m_dJobMaxTime = OSParameter.JOB_MAX_TIME;
	
	/**
	 * m_jobScheduledStartTime holds the job's scheduled start time.
	 */
	protected GregorianCalendar m_jobScheduledStartTime = new GregorianCalendar(1970, 0, 1, 0, 0, 0);

	/**
	 * m_msJobDependencies holds a string array of jobIDs the the current job depends on.
	 */
	protected String[] m_msJobDependencies = null;
	
	/**
	 * m_msRequiredDirectoriesAndFiles holds a list of file and directory names needed to run the job. 
	 */
	protected String[] m_msRequiredDirectoriesAndFiles = null;
	
	/**
	 * m_sCurrentState holds the current state of the service: which can be: 
	 * busy, busyButAccepting, idle, idleButNotAccepting, noResponse. 
	 */
	protected static String m_sCurrentState = "idle";
	
	/**
	 * m_dAvailableDiskSpace holds the available disk space. 
	 */
	protected static double m_dAvailableDiskSpace = Double.POSITIVE_INFINITY;

	/**
	 * m_dAvailableMemory holds the available memory. 
	 */
	protected static double m_dAvailableMemory = Double.POSITIVE_INFINITY;
	
	/**
	 * m_iCurrentJobCount holds the current number of active jobs. 
	 */
	protected static int m_iCurrentJobCount = 0;
	
	/**
	 * m_iTotalJobsSoFar holds the number of jobs so far recieved. 
	 */
	protected static int m_iTotalJobsSoFar = 0;

	/**
	 * m_lLastJobEnded holds the time the last job ended (in millisecond since 1970 UTC).  
	 */
	protected static long m_lTimeLastJobEnded = -1;

	/**
	 * m_lLastJobTook holds the time the last job took in millisecond.  
	 */
	protected static long m_lLastJobTook = -1;
	
	/**
	 * m_lTimeServiceStarted holds the service start time (in millisecond since 1970 UTC).    
	 */
	protected static long m_lTimeServiceStarted = System.currentTimeMillis();

	/**
	 * m_dServiceUtilization holds the service utilization (time solving jobs / total time since start)
	 */
	protected static double m_dServiceUtilization = 0; //TODO may be inapproriate for the scheduler
	
	/**
	 * m_lTotalBusyTime holds the total busy time (solving jobs) since service start. 
	 */
	protected static long m_lTotalBusyTime = 0;
	
	/**
	 * m_sJobState holds the job state, which can be waiting, running, killed, finished or unknown.  
	 */
	protected String m_sJobState= "unknown";
	
	/**
	 * serviceURI holds the service uri. 
	 */
	//public String serviceURI = OSParameter.SERVICE_URI;

	/**
	 * m_sUserName holds the user name. 
	 */
	//protected String m_sUserName = "";

	/**
	 * m_lJobSubmitTime holds the job submit time (in millisecond since 1970 UTC).  
	 */
	protected long m_lJobSubmitTime = -1;
	
	/**
	 * m_lJobStartTime holds the job start time. 
	 */
	protected long m_lJobStartTime = -1;
	
	/**
	 * m_lJobScheduledStartTime holds the job scheduled start time. 
	 */
	protected long m_lJobScheduledStartTime = -1;
	
	/**
	 * m_lJobEndTime holds the job end time. 
	 */
	protected long m_lJobEndTime = -1;

	/**
	 * m_lJobDuration holds the time the job took in millisecond. 
	 */
	protected long m_lJobDuration = -1;
	
	/**
	 * m_jobScheduledStartTime holds the job's scheduled start time.
	 */
	//protected GregorianCalendar m_jobScheduledStartTime = new GregorianCalendar(1970, 0, 1, 0, 0, 0);

	/**
	 * m_msJobDependencies holds a string array of jobIDs the the current job depends on.
	 */
	//protected String[] m_msJobDependencies = null;
	
	/**
	 * m_msRequiredDirectoriesAndFiles holds a list of file and directory names needed to run the job. 
	 */
	//protected String[] m_msRequiredDirectoriesAndFiles = null;
	
	/**
	 * solver holds the solver engine
	 */
	public DefaultSolver solver = null;

	/**
	 * m_solverThread holds the solver thread. 
	 */
	protected SolverThread m_solverThread = null;
	
	/**
	 * simulation holds the simulation engine
	 */
	public DefaultSimulation simulation = null;

	/**
	 * m_regis holds the os registry
	 */
	public DefaultRegistry registry = null;

	/**
	 * timer holds the timer thread
	 */
	protected static Timer timer  = null;

	
	/**
	 * m_osilReader holds the OSiL reader.
	 */
	protected OSiLReader m_osilReader = null;

	/**
	 * m_osolReader holds the OSoL reader.
	 */
	protected OSoLReader m_osolReader = null;

	/**
	 * m_osOption holds the parsed OSOption data structure read from the OSoL string.
	 */
	protected OSOption m_osOption = null;

	/**
	 * m_bReadOSoL holds whehter the OSoL string has been read or not. 
	 */
	protected boolean m_bReadOSoL = false;

	/**
	 * m_osslReader holds the OSsL reader.
	 */
	protected OSsLReader m_osslReader = null;
	
	/**
	 * m_osrlReader holds the OSrL reader.
	 */
	protected OSrLReader m_osrlReader = null;

	/**
	 * m_osplReader holds the OSpL reader.
	 */
	protected OSpLReader m_osplReader = null;
	
	/**
	 * m_osqlReader holds the OSqL reader.
	 */
	protected OSqLReader m_osqlReader = null;
	
	/**
	 * m_osulReader holds the OSuL reader.
	 */
	protected OSuLReader m_osulReader = null;
	
	/**
	 * m_osilWriter holds the OSiL writer.
	 */
	protected OSiLWriter m_osilWriter = null;

	/**
	 * m_osolWriter holds the OSoL writer.
	 */
	protected OSoLWriter m_osolWriter = null;
	
	/**
	 * m_osslWriter holds the OSsL writer.
	 */
	protected OSsLWriter m_osslWriter = null;

	/**
	 * m_osrlWriter holds the OSrL writer.
	 */
	protected OSrLWriter m_osrlWriter = null;

	/**
	 * m_osplWriter holds the OSpL writer.
	 */
	protected OSpLWriter m_osplWriter = null;
	
	/**
	 * m_osqlWriter holds the OSqL writer.
	 */
	protected OSqLWriter m_osqlWriter = null;
	
	/**
	 * m_osulWriter holds the OSuL writer.
	 */
	protected OSuLWriter m_osulWriter = null;
		
	/**
	 * m_solverThreadHashTable holds the solverThread instance that will be launched by a separate thread. 
	 */
	protected static Hashtable<String, SolverThread> m_solverThreadHashTable = new Hashtable<String, SolverThread>();

	/**
	 * m_threadHashTable holds a hashtable of all the threads that started the solve() 
	 * methods launched by this service. The hashtable names are the thread names (same as the jobIDs) and 
	 * the hashtable objects are the threads
	 */
	protected static Hashtable<String, Thread> m_threadHashTable = new Hashtable<String, Thread>();

	/**
	 * m_jobStatisticsTable holds a hashtable of job statistics. 
	 * The hashtable keys are the jobIDs and the hashtable objects are the job statistics
	 */
	protected static Hashtable<String, JobStatistics> m_jobStatisticsTable = new Hashtable<String, JobStatistics>();

	/**
	 * m_vCurrentJobIDs holds a sequence of current jobIDs according to the time the jobs are
	 * submitted, with the first one being the earliest. 
	 */
	protected static Vector<String> m_vCurrentJobIDs = new Vector<String>();
	
	/**
	 * m_vWaitingJobIDs holds a sequence of waiting jobIDs. 
	 */
	protected static Vector<String> m_vWaitingJobIDs = new Vector<String>();
	
	/**
	 * m_vFinishedJobIDs holds a sequence of finished (or killed) jobIDs according to the time the jobs are
	 * finished, with the first one being the earliest. 
	 */
	protected static Vector<String> m_vFinishedJobIDs = new Vector<String>();
		
	/**
	 * m_userJobCountTable holds the number of jobs currently run by a user. 
	 */
	protected static Hashtable<String, String> m_userJobCountTable = new Hashtable<String, String>();

	/**
	 * acceptingSolverURIs holds the URIs of accepting solvers. 
	 */
	protected static Vector<String> acceptingSolverURIs = new Vector<String>();

	/**
	 * m_processsHashTable holds a hashtable of all the process launched by this service. 
	 * The hashtable names are the thread names (same as the jobIDs) and 
	 * the hashtable objects are the a vector of processes launched by the thread. 
	 */
	public static Hashtable<String, Vector<Process>> processsHashTable = new Hashtable<String, Vector<Process>>();

	
	/**
	 * Default constructor. 
	 */
	public OSServiceUtil(){
		try {
			String sClassName = OSParameter.SOLVER_CLASS_NAME; //"org.optimizationservices.oscommon.util.StandardSolver";
			Class solverClass = Class.forName(sClassName);
			solver =(DefaultSolver)solverClass.newInstance();			
		} 
		catch (Exception e) {
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
		}
	}//constructor
	
	/**
	 * Get a unique job id from a service, before calling the service to solve a problem. This method call is always
	 * required before an asynchronous send call. It may be or may not be used before a synchronous solve call. 
	 * 
	 * @param osol holds the option in a string which format follows OSoL schema.
	 * @return jobID, a unique job ID generated by the service.
	 */	
	public String getJobID(String osol){
		if(osol == null) osol = "";
		return CommonUtil.getJobID(osol);
	}//getJobID
	
	/**
	 * read and parse the osol string. 
	 * 
	 * @param osol holds the option string to read. 
	 * @return whether the osol string is read successfully. 
	 */
	public boolean readOSoL(String osol){
		if(osol == null) osol = "";
		if(m_bReadOSoL) return true;
		m_osOption = new OSOption();

		if(osol == null || osol.length() <= 0){
			return true;
		}
		m_osolReader = new OSoLReader(m_bValidate);
		try{
			boolean bRead = m_osolReader.readString(osol);
			if(!bRead) throw new Exception("Invalid OSoL option");
			m_osOption = m_osolReader.getOSOption();
			if(m_osOption == null){
				m_osOption = new OSOption();
				throw new Exception("Invalid OSoL option");
			}
			
			//get general options
			m_sServiceURIInOSoL = m_osOption.getServiceURI();
			m_sServiceNameInOSoL = m_osOption.getServiceName();
			m_sInstanceName = m_osOption.getInstanceName();
			m_sInstanceLocationType = m_osOption.getInstanceLocationType();
			if(m_sInstanceLocationType == null || m_sInstanceLocationType.length() <= 0){
				m_sInstanceLocationType = "local";
			}
			m_sInstanceAddress = m_osOption.getInstanceAddress();					
			m_sJobID = m_osOption.getJobID();
			m_sLicense = m_osOption.getLicense();
			m_sUserName = m_osOption.getUserName();
			if(m_sUserName == null) m_sUserName = "";
			m_sPassword = m_osOption.getPassword();			
			m_sContactTransportType = m_osOption.getContactTransportType();
			if(m_sContactTransportType == null || m_sContactTransportType.length() <= 0){
				m_sContactTransportType = "osp";
			}
			m_sContactAddress = m_osOption.getContactAddress();			
			//get system related options
			m_dMinDiskSpace = m_osOption.getSystemMinDiskSpace();
			m_dMinMemorySize = m_osOption.getSystemMinMemorySize();
			m_dMinCPUSpeed = m_osOption.getSystemMinCPUSpeed();

			//get service related options
			m_sServiceTypeInOSoL = m_osOption.getServiceType();
			
			//get job related options
			double dJobMaxTime = m_osOption.getJobMaxTime();
			if(dJobMaxTime != Double.POSITIVE_INFINITY && dJobMaxTime < OSParameter.JOB_MAX_TIME && dJobMaxTime > 0){
				m_dJobMaxTime  = dJobMaxTime;
			}
			GregorianCalendar jobScheduledStartTime = m_osOption.getJobScheduledStartTime();
			if(jobScheduledStartTime != null && jobScheduledStartTime.get(GregorianCalendar.YEAR) > 1970){
				m_jobScheduledStartTime  = jobScheduledStartTime;
				m_lJobScheduledStartTime = m_jobScheduledStartTime.getTimeInMillis();
			}

			m_msJobDependencies = m_osOption.getJobDependencies();
			m_msRequiredDirectoriesAndFiles = m_osOption.getRequiredDirectoriesAndFiles();
			
			m_bReadOSoL = true;
			return true;
		}
		catch(Exception e){
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
			return false;
		}
	}//readOSoL
	
	/**
	 * check if the job is permitted. 
	 * 
	 * @return if the job should be permitted. 
	 */
	protected boolean checkPermision() throws Exception{
		boolean bCheck = true;
		String sMessage = "";
		if(OSParameter.REQUIRE_LICENSE || OSParameter.REQUIRE_USER_NAME || OSParameter.REQUIRE_PASSWORD){
			if(m_sPassword != null && m_sPassword.length() > 0 && OSParameter.checkSystemPassword(m_sPassword)){
				bCheck = true;
				return bCheck;
			}
			if(OSParameter.REQUIRE_LICENSE){
				bCheck = OSParameter.checkLicense(m_sUserName, m_sLicense);
				if(!bCheck){
					sMessage = "Permission error: wrong licence";
				}
			}
			if(bCheck && (OSParameter.REQUIRE_USER_NAME || OSParameter.REQUIRE_PASSWORD)){
				bCheck = OSParameter.checkUserNameAndPassword(m_sUserName, m_sPassword);
				if(!bCheck){
					sMessage = "Permission error: wrong user name and/or password";
				}
			}
			if(!bCheck){
				throw new Exception(sMessage);
			}
		}
		return bCheck;
	}//checkPermision

	/**
	 * check whether the job meets system requirement. 
	 * 
	 * @return whether the job meets system requirement
	 */
	protected boolean checkSystemRequirement() throws Exception{
		boolean bCheck = true;
		String sMessage = "";

		//check if service is full
		m_iCurrentJobCount = m_vCurrentJobIDs.size();
		if(m_iCurrentJobCount >= OSParameter.MAX_JOB_NUMBERS){
			sMessage = "System warning: server is busy and is already taking on maximum number of jobs.";
			throw new Exception(sMessage);
		}

		//check if disk space is enough
		try{
			m_dAvailableDiskSpace = IOUtil.getFreeDiskSpace(OSParameter.CODE_DRIVE);	
		}
		catch(Exception e){
			sMessage = "System warning: service (" + (OSParameter.SERVICE_URI) +") cannot check disk space.";
			IOUtil.log(sMessage, null);
			m_dAvailableDiskSpace = Double.POSITIVE_INFINITY;
			sMessage = "";
		}
		if(m_dAvailableDiskSpace <= OSParameter.MINIMUM_DISKSPACE_TRIGGER){
			sMessage = "System warning: service (" + (OSParameter.SERVICE_URI) +") is running low on disk space (" + m_dAvailableDiskSpace + ")";
			m_iCurrentJobCount = m_vCurrentJobIDs.size();
			if(m_iCurrentJobCount > 0){
				m_sCurrentState = "busy";				
			}
			else{
				m_sCurrentState = "idleButNotAccepting";
			}
			throw new Exception(sMessage);
		}
		
		//check if memory size is enough
		try{
			m_dAvailableMemory = ProcessUtil.getFreeMemory();	
		}
		catch(Exception e){
			sMessage = "System warning: Service (" + (OSParameter.SERVICE_URI) +") cannot check available memory size.";
			IOUtil.log(sMessage, null);
			m_dAvailableMemory = Double.POSITIVE_INFINITY;
			sMessage = "";
		}
		if(m_dAvailableMemory <= ((double)OSParameter.MINIMUM_MEMORY_TRIGGER)){
			sMessage = "System warning: service (" + (OSParameter.SERVICE_URI) +") is running low on memory (" + m_dAvailableMemory + ")";
			m_iCurrentJobCount = m_vCurrentJobIDs.size();
			if(m_iCurrentJobCount > 0){
				m_sCurrentState = "busy";
			}
			else{
				m_sCurrentState = "idleButNotAccepting";
			}
			throw new Exception(sMessage);
		}
		//check user quota
		if(m_sUserName == null) m_sUserName = "";
		if(OSParameter.MAX_JOBS_PER_USER > 0 && !m_vWaitingJobIDs.contains(m_sJobID)){
			String sCount = m_userJobCountTable.get(m_sUserName);
			int iCount;
			if(sCount == null || sCount.length() <= 0){
				iCount = 0;
			}
			else{
				try {
					iCount = Integer.parseInt(sCount);					
				} 
				catch (Exception e) {
					iCount = 0;
				}
				if(iCount < 0) iCount = 0;
			}
			if(iCount >= OSParameter.MAX_JOBS_PER_USER){
				sMessage = "System warning: the jobs submitted by the user " + m_sUserName + " has exceeded maximum allowed.";
				throw new Exception(sMessage);
			}
		}

		//check minimum system requirement needed by the job
		if(serviceType == null || !serviceType.equals("scheduler")){
			if(m_dAvailableDiskSpace < m_dMinDiskSpace){
				sMessage = "System warning: the server cannot meet the disk space requirement for the job";
			}
			else if(m_dAvailableMemory <  m_dMinMemorySize){
				sMessage = "System warning: the server cannot meet the memory space requirement for the job";
			}
			else if(OSParameter.CPU_SPEED < m_dMinCPUSpeed){
				sMessage = "System warning: the server cannot meet the cpu space requirement for the job";				
			}			
		}
		
		if(sMessage != null && sMessage.length() > 0){
			throw new Exception(sMessage);
		}
		return bCheck;
	}//checkSystemRequirement
	
	/**
	 * initialize statistics. 
	 *
	 */
	protected void initializeStatistics(){
		JobStatistics jobStatistics  = m_jobStatisticsTable.get(m_sJobID);
		if(jobStatistics == null){
			jobStatistics = new JobStatistics();
			jobStatistics.jobID = m_sJobID;
			m_jobStatisticsTable.put(m_sJobID, jobStatistics);
			m_iTotalJobsSoFar++;
			
			if(m_sUserName == null) m_sUserName = "";
			String sCount = m_userJobCountTable.get(m_sUserName);
			int iCount;
			if(sCount == null || sCount.length() <= 0){
				iCount = 0;
			}
			else{
				try {
					iCount = Integer.parseInt(sCount);					
				} 
				catch (Exception e) {
					iCount = 0;
				}
				if(iCount < 0) iCount = 0;
			}
			iCount += 1;
			m_userJobCountTable.remove(m_sUserName);
			m_userJobCountTable.put(m_sUserName, iCount+"");			
		}
		
		m_vWaitingJobIDs.remove(m_sJobID);
		m_vCurrentJobIDs.remove(m_sJobID);
		m_vCurrentJobIDs.add(m_sJobID);
		m_iCurrentJobCount = m_vCurrentJobIDs.size();
		
		if(m_iCurrentJobCount >= OSParameter.MAX_JOB_NUMBERS){
			m_sCurrentState = "busy";
		}
		else{
			m_sCurrentState = "busyButAccepting";
		}

		jobStatistics.jobID = m_sJobID;		
		jobStatistics.state = "running";
		m_sJobState = jobStatistics.state;		
		if(serviceType.equals("scheduler")){
			jobStatistics.serviceURI = "";			
		}
		else{
			jobStatistics.serviceURI = (OSParameter.SERVICE_URI);
		}		
		jobStatistics.userName = m_sUserName;		
		if(jobStatistics.submitTime == null || jobStatistics.submitTime.get(GregorianCalendar.YEAR) <= 1970){
			jobStatistics.submitTime = new GregorianCalendar(); 
		}
		m_lJobSubmitTime = jobStatistics.submitTime.getTimeInMillis();		
		jobStatistics.scheduledStartTime = m_jobScheduledStartTime;
		if(m_jobScheduledStartTime != null && m_jobScheduledStartTime.get(GregorianCalendar.YEAR) > 1970){
			m_lJobScheduledStartTime = m_jobScheduledStartTime.getTimeInMillis();
		}
		else{
			m_lJobScheduledStartTime = -1;
		}		
		jobStatistics.startTime = new GregorianCalendar(); 
		m_lJobStartTime = jobStatistics.startTime.getTimeInMillis();
		jobStatistics.endTime = new GregorianCalendar(1970, 0, 1, 0, 0, 0); 
		m_lJobEndTime = -1;
		jobStatistics.duration = Double.NaN; 
		m_lJobDuration = -1;
		if(m_msJobDependencies != null && m_msJobDependencies.length > 0){
			jobStatistics.dependencies = new JobDependencies();
			jobStatistics.dependencies.jobID = m_msJobDependencies;
		}		
		if(m_msRequiredDirectoriesAndFiles != null && m_msRequiredDirectoriesAndFiles.length > 0){
			jobStatistics.requiredDirectoriesAndFiles = new DirectoriesAndFiles();
			jobStatistics.requiredDirectoriesAndFiles.path = m_msRequiredDirectoriesAndFiles;
		}	
		//save ospl
		saveOSpL();		
	}//initializeStatistics
	
	/**
	 * check if the job should wait: scheduled Time, job dependencies, required files/directories, solver availability
	 *  
	 * @param osil holds the instance in a string which format follows OSiL schema.
	 * @param osol holds the option in a string which format follows OSoL schema.
	 * @param checkSolverAvailability holds whether the method should check solver availability. 
	 * @param process holds whether the method should process the waiting jobs.
	 * 
	 * @return if the job should wait. 
	 */
	@SuppressWarnings("deprecation")
	protected boolean checkWaiting(String osil, String osol, boolean checkSolverAvailability, boolean process) throws Exception {
		if(osil == null) osil = "";
		if(osol == null) osol = "";

		boolean bWait = false;
		String sMessage = "";
		//check job scheduling
		if(m_lJobScheduledStartTime > 0){
			
			long lNow = new GregorianCalendar().getTimeInMillis();
			if(m_lJobScheduledStartTime > lNow){				
				bWait = true;
			}
		}
		//check job dependencies
		if(!bWait && m_msJobDependencies != null && m_msJobDependencies.length > 0){
			int iFinishedJob = m_vFinishedJobIDs.size();
			int iJobDependences = m_msJobDependencies == null?0:m_msJobDependencies.length;
			for(int i = 0; i < iJobDependences; i++){
				boolean bFound = false;
				for(int j = iFinishedJob-1; j >= 0 ; j--){
					try {
						if(m_msJobDependencies[i].equals(m_vFinishedJobIDs.elementAt(j))){
							bFound = true;
							break;
						}						
					} 
					catch (Exception e) {
					}
				}
				if(!bFound){
					bWait = true;
					break;
				}
			}
		}
		//check required directories or files
		if(!bWait && m_msRequiredDirectoriesAndFiles != null && m_msRequiredDirectoriesAndFiles.length > 0){
			int iRequiredDirectoriesAndFiles = m_msRequiredDirectoriesAndFiles.length;
			for(int i = 0; i < iRequiredDirectoriesAndFiles; i++){				
				if(!IOUtil.existsFileOrDir(m_msRequiredDirectoriesAndFiles[i])){
					bWait = true;
					break;
				}
			}
		}
		//if scheduler check for available solver service
		if(!bWait && serviceType.equals("scheduler") && checkSolverAvailability){
			if(acceptingSolverURIs.size() <= 0){
				m_osqlWriter = new OSqLWriter();
				StandardQuery standardQuery = new StandardQuery();
				standardQuery.currentState = "accepting";
				standardQuery.serviceType = "solver";
				m_osqlWriter.setStandardQuery(standardQuery);
				String sOSqL = m_osqlWriter.writeToString();
				
				m_osolWriter = new OSoLWriter();
				m_osolWriter.setServiceURI(OSParameter.SERVICE_URI);
				m_osolWriter.setServiceName(OSParameter.SERVICE_NAME);
				m_osolWriter.setJobID(m_sJobID);
				m_osolWriter.setUserName(m_sUserName);				
				m_osolWriter.setPassword(OSParameter.getSystemPassword());
				m_osolWriter.setServiceType("scheduler");
				String sOSoL = m_osolWriter.writeToString();
				
				String sOSuL = "";
				try{
					FindThread findThread = new FindThread();
					if(OSParameter.SCHEDULER_WITH_REGISTRY){
						OSServiceUtil osServiceUtil = new OSServiceUtil();						
						osServiceUtil.serviceName = "OSRegistryService";
						osServiceUtil.serviceURI = OSParameter.OS_REGISTRY_SITE; 
						osServiceUtil.serviceType = "registry";
						osServiceUtil.registry = new DefaultRegistry();
						findThread.m_osServiceUtil = osServiceUtil;						
					}
					else{
						OSRegistryAgent osRegistryAgent = new OSRegistryAgent(OSParameter.OS_REGISTRY_SITE);
						findThread.m_osRegistryAgent = osRegistryAgent;
					}
					findThread.m_sOSqL= sOSqL;
					findThread.m_sOSoL = sOSoL;
										
					Thread thread = new Thread(findThread);	
					thread.start();

					long lTimeSpan = 30000L;
					thread.join(lTimeSpan);

					sOSuL = findThread.m_sOSuL;
				}
				catch(Exception e){
					IOUtil.log(IOUtil.exceptionStackToString(e), null);
				}
				if(sOSuL != null && sOSuL.length() > 0){
					try {
						m_osulReader = new OSuLReader();
						boolean bRead = m_osulReader.readString(sOSuL);
						if(!bRead) throw new Exception("Invalid OSuL URIs");
						URI[] mURI = m_osulReader.getURIMatches();
						int iURIs = (mURI==null?0:mURI.length);
						for(int i = 0; i < iURIs; i++){
							acceptingSolverURIs.add(mURI[i].value);
						}
						acceptingSolverURIs.remove(OSParameter.OS_SCHEDULER_SITE);
						acceptingSolverURIs.remove(OSParameter.OS_REGISTRY_SITE);
					} 
					catch (Exception e) {
						IOUtil.log(IOUtil.exceptionStackToString(e), null);
					}								
				}
			}
			if(acceptingSolverURIs.size() <= 0){
				bWait = true;
			}
			else{
				if(m_solverThread == null){
					m_solverThread = new SolverThread();	
				}	
				m_solverThread.m_msURIs = new String[1];				
				m_solverThread.m_msURIs[0] = acceptingSolverURIs.remove(0);
			}
		}
		//process
		if(bWait && process){
			//update statistics
			JobStatistics jobStatistics  = m_jobStatisticsTable.get(m_sJobID);
			if(jobStatistics == null){
				jobStatistics = new JobStatistics();	
				jobStatistics.jobID = m_sJobID;
				m_jobStatisticsTable.put(m_sJobID, jobStatistics);
			}
			m_threadHashTable.remove(m_sJobID);
			m_solverThreadHashTable.remove(m_sJobID);
			processsHashTable.remove(m_sJobID);			
			m_vCurrentJobIDs.remove(m_sJobID);
			m_vWaitingJobIDs.remove(m_sJobID);
			m_vWaitingJobIDs.add(m_sJobID);			
			m_iCurrentJobCount = m_vCurrentJobIDs.size();
			
			if(m_iCurrentJobCount >= OSParameter.MAX_JOB_NUMBERS){
				m_sCurrentState = "busy";
			}
			else if(m_iCurrentJobCount > 0){
				m_sCurrentState = "busyButAccepting";
			}
			else {
				m_sCurrentState = "idle";
			}
			
			jobStatistics.jobID = m_sJobID;
			jobStatistics.state = "waiting";
			m_sJobState = jobStatistics.state;			
			if(serviceType.equals("scheduler")){
				jobStatistics.serviceURI = "";			
			}
			else{
				jobStatistics.serviceURI = (OSParameter.SERVICE_URI);
			}
			if(jobStatistics.userName == null || jobStatistics.userName.length() <= 0){
				jobStatistics.userName = m_sUserName;								
			}
			if(jobStatistics.submitTime == null || jobStatistics.submitTime.get(GregorianCalendar.YEAR) <= 1970){
				jobStatistics.submitTime = new GregorianCalendar(); 
			}
			m_lJobSubmitTime = jobStatistics.submitTime.getTimeInMillis();			
			jobStatistics.scheduledStartTime = m_jobScheduledStartTime;
			if(m_jobScheduledStartTime != null && m_jobScheduledStartTime.get(GregorianCalendar.YEAR) > 1970){
				m_lJobScheduledStartTime = m_jobScheduledStartTime.getTimeInMillis();
			}
			else{
				m_lJobScheduledStartTime = -1;			
			}			
			jobStatistics.startTime = new GregorianCalendar(1970, 0, 1, 0, 0, 0); 
			m_lJobStartTime = -1;
			jobStatistics.endTime = new GregorianCalendar(1970, 0, 1, 0, 0, 0); 
			m_lJobEndTime = -1;
			jobStatistics.duration = Double.NaN;
			m_lJobDuration = -1;
			if(m_msJobDependencies != null && m_msJobDependencies.length > 0){
				jobStatistics.dependencies = new JobDependencies();
				jobStatistics.dependencies.jobID = m_msJobDependencies;
			}
			if(m_msRequiredDirectoriesAndFiles != null && m_msRequiredDirectoriesAndFiles.length > 0){
				jobStatistics.requiredDirectoriesAndFiles = new DirectoriesAndFiles();
				jobStatistics.requiredDirectoriesAndFiles.path = m_msRequiredDirectoriesAndFiles;
			}	
			//save ospl
			saveOSpL();			
			
			boolean bRemoveWaitingJob = false;
			if(m_vWaitingJobIDs.size() > OSParameter.MAX_WAITING_NUMBERS){
				sMessage = "Waiting error: maximum waiting number reached";
				bRemoveWaitingJob = true;
			}
			else{
				//save files
				String sInstanceFile = OSParameter.TEMP_FILE_FOLDER+m_sJobID+".osil";
				String sOptionFile = OSParameter.TEMP_FILE_FOLDER+m_sJobID+".osol";
				boolean bWriteOSiL = true;
				if(!IOUtil.existsFileOrDir(sInstanceFile)){
					bWriteOSiL = IOUtil.writeStringToFile(osil, sInstanceFile);
				}
				if(!bWriteOSiL){
					bRemoveWaitingJob = true;
					sMessage = "Waiting error: unable to save OSiL arguments for future computation";
					IOUtil.log("the service is not able to write osil to file", null);
					IOUtil.deleteFile(sInstanceFile);
				}
				boolean bWriteOSoL = true;
				if(bWriteOSiL){
					if(!IOUtil.existsFileOrDir(sOptionFile)){
						bWriteOSoL = IOUtil.writeStringToFile(osol, sOptionFile);
					}
					if(!bWriteOSoL){
						bRemoveWaitingJob = true;
						sMessage = "Waiting error: unable to save OSoL arguments for future computation";
						IOUtil.log("the service is not able to write osol to file", null);
						IOUtil.deleteFile(sOptionFile);
					}
				}
			}
			if(bRemoveWaitingJob){
				removeWaitingJob(m_sJobID);			
				throw new Exception(sMessage);
			}
		}		
		return bWait;
	}//checkWaiting
		
	
	/**
	 * postprocess after the solve or send method. 
	 * 
	 * @param kill holds whether the process is called from a kill command. 
	 * 
	 */
	@SuppressWarnings("deprecation")
	protected void postprocess(boolean kill){
		if(m_vFinishedJobIDs.contains(m_sJobID)){
			return;
		}
		if(serviceType.equals("solver")  || serviceType.equals("analyzer")){
			Vector vProcess = (Vector)processsHashTable.get(m_sJobID);
			if(vProcess != null && vProcess.size() > 0){
				for(int i = 0; i < vProcess.size(); i++){
					try{
						Process process = (Process)vProcess.elementAt(i);
						process.destroy();
					}
					catch(Exception e){
						String sException = IOUtil.exceptionStackToString(e);
						IOUtil.log(sException, null);
					}
				}
			}
			processsHashTable.remove(m_sJobID);
		}
		Thread thread = (Thread)m_threadHashTable.get(m_sJobID);
		
		JobStatistics jobStatistics  = m_jobStatisticsTable.get(m_sJobID);
		if(jobStatistics == null){
			jobStatistics = new JobStatistics();
			jobStatistics.jobID = m_sJobID;
			m_jobStatisticsTable.put(m_sJobID, jobStatistics);
		}
		
		if(m_sUserName == null) m_sUserName = "";
		String sCount = m_userJobCountTable.get(m_sUserName);
		int iCount;
		if(sCount == null || sCount.length() <= 0){
			iCount = 0;
		}
		else{
			try {
				iCount = Integer.parseInt(sCount);					
			} 
			catch (Exception e) {
				iCount = 0;
			}
			if(iCount <= 0){
				iCount = 0;
			}
			else if(m_vWaitingJobIDs.contains(m_sJobID) || m_vCurrentJobIDs.contains(m_sJobID)){
				iCount -= 1;
			}		
		}		
		m_userJobCountTable.remove(m_sUserName);
		m_userJobCountTable.put(m_sUserName, iCount+"");
		
		m_threadHashTable.remove(m_sJobID);
		m_solverThreadHashTable.remove(m_sJobID);
		processsHashTable.remove(m_sJobID);
		m_vWaitingJobIDs.remove(m_sJobID);
		m_vCurrentJobIDs.remove(m_sJobID);
		m_vFinishedJobIDs.remove(m_sJobID);
		m_vFinishedJobIDs.add(m_sJobID);
		m_iCurrentJobCount = m_vCurrentJobIDs.size();
				
		try{
			m_dAvailableDiskSpace = IOUtil.getFreeDiskSpace(OSParameter.CODE_DRIVE);	
		}
		catch(Exception e){
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
			m_dAvailableDiskSpace = Double.POSITIVE_INFINITY;
		}
		try{
			System.gc();
			m_dAvailableMemory = ProcessUtil.getFreeMemory();	
		}
		catch(Exception e){
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
			m_dAvailableMemory = Double.POSITIVE_INFINITY;
		}
		if(m_dAvailableDiskSpace <= OSParameter.MINIMUM_DISKSPACE_TRIGGER ||
				   m_dAvailableMemory <= ((double)OSParameter.MINIMUM_MEMORY_TRIGGER)){
			if(m_iCurrentJobCount > 0){
				m_sCurrentState = "busy";				
			}
			else{
				m_sCurrentState = "idleButNotAccepting";
			}
		}
		else{
			if(m_iCurrentJobCount == 0){
				m_sCurrentState = "idle";
			}
			else if(m_iCurrentJobCount >= OSParameter.MAX_JOB_NUMBERS){
				m_sCurrentState = "busy";
			}
			else{
				m_sCurrentState = "busyButAccepting";
			}
		}
				
		jobStatistics.jobID = m_sJobID;
		jobStatistics.state = kill?"killed":"finished";
		m_sJobState = jobStatistics.state;

		jobStatistics.endTime = new GregorianCalendar(); 
		m_lJobEndTime = jobStatistics.endTime.getTimeInMillis();
		m_lTimeLastJobEnded = m_lJobEndTime;

		if(jobStatistics.startTime != null && jobStatistics.startTime.get(Calendar.YEAR) > 1970){
			m_lJobStartTime = jobStatistics.startTime.getTimeInMillis();
			m_lJobDuration = m_lJobEndTime - m_lJobStartTime;
			jobStatistics.duration = m_lJobDuration/1000.0;
			m_lLastJobTook = m_lJobDuration;
			if(m_lJobDuration >= 0){
				m_lTotalBusyTime += m_lJobDuration;				
			}
			else{
				m_lJobDuration = -1;
				jobStatistics.duration = -1;
				m_lLastJobTook = -1;
			}
		}
		else{
			m_lJobStartTime = -1;
			m_lJobDuration = -1;
			jobStatistics.duration = -1;
			m_lLastJobTook = -1;
		}
		m_dServiceUtilization = ((double)m_lTotalBusyTime/(m_lJobEndTime - m_lTimeServiceStarted));			
		
		//contact registry
		updateRegistry(false);

		//save ospl
		saveOSpL();

		//contact the sender
		contactSender();

		//request job at scheduler
		requestJob();
		
		if(kill){
			if(thread != null){
				try{
					thread.stop();
				}
				catch(Exception e){
					String sException = IOUtil.exceptionStackToString(e);
					IOUtil.log(sException, null);
				}
			}
		}
	}//postprocess

	/**
	 * update the registry
	 * 
	 * @param wait holds whether updateRegistry should be waited before it is finished. 
	 * @return if the registry is updated. 
	 */
	protected boolean updateRegistry(boolean wait){
		try {
			if(OSParameter.OS_REGISTRY_SITE == null || OSParameter.OS_REGISTRY_SITE.length() <= 0) return true;
			m_osplWriter = new OSpLWriter();
			m_osplWriter.setRequestAction("setServiceStatistics");
			m_osplWriter.setServiceURI(OSParameter.SERVICE_URI);
			m_osplWriter.setServiceName(OSParameter.SERVICE_NAME);
			m_osplWriter.setProcessTime(new GregorianCalendar());
			m_osplWriter.setCurrentState(m_sCurrentState);
			m_osplWriter.setAvailableDiskSpace(m_dAvailableDiskSpace);
			m_osplWriter.setAvailableMemory(m_dAvailableMemory);
			m_osplWriter.setCurrentJobCount(m_iCurrentJobCount);
			m_osplWriter.setTotalJobsSoFar(m_iTotalJobsSoFar);
			m_osplWriter.setTimeLastJobEnded(CommonUtil.createNativeDateTime(m_lTimeLastJobEnded));			
			if(m_lLastJobTook < 0){
				m_osplWriter.setTimeLastJobTook(-1);					
			}
			else{
				m_osplWriter.setTimeLastJobTook((double)(m_lLastJobTook/1000.0));
			}
			m_osplWriter.setTimeServiceStarted(CommonUtil.createNativeDateTime(m_lTimeServiceStarted));
			m_osplWriter.setServiceUtilization(m_dServiceUtilization);
			String sProcessInput = m_osplWriter.writeToString();

			m_osolWriter = new OSoLWriter();
			m_osolWriter.setServiceURI(OSParameter.SERVICE_URI);
			m_osolWriter.setServiceName(OSParameter.SERVICE_NAME);
			m_osolWriter.setJobID(m_sJobID);
			m_osolWriter.setLicense(m_sLicense);
			m_osolWriter.setUserName(m_sUserName);		
			m_osolWriter.setPassword(OSParameter.getSystemPassword());			
			String sServiceType = (serviceType==null||serviceType.length() <= 0)?"solver":serviceType;
			m_osolWriter.setServiceType(sServiceType);
			String sOption = m_osolWriter.writeToString();

			KnockRegistryThread knockRegistryThread = new KnockRegistryThread();
			if(sServiceType.equals("scheduler") && OSParameter.SCHEDULER_WITH_REGISTRY){
				OSServiceUtil osServiceUtil = new OSServiceUtil();						
				osServiceUtil.serviceName = "OSRegistryService";
				osServiceUtil.serviceURI = OSParameter.OS_REGISTRY_SITE; 
				osServiceUtil.serviceType = "registry";
				osServiceUtil.registry = new DefaultRegistry();
				knockRegistryThread.m_osServiceUtil = osServiceUtil;						
			}
			else{
				OSRegistryAgent osRegistryAgent = new OSRegistryAgent(OSParameter.OS_REGISTRY_SITE);
				knockRegistryThread.m_osRegistryAgent = osRegistryAgent;
			}
			knockRegistryThread.m_sOSpLInput = sProcessInput;
			knockRegistryThread.m_sOSoL = sOption;
								
			Thread thread = new Thread(knockRegistryThread);
			thread.start();
			if(wait){
				thread.join(10000);	
			}
			return true;
		} 
		catch (Exception e) {
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
			return false;
		}
	}//updateRegistry
	
	/**
	 * contact the sender
	 * 
	 * @return if the sender is contacted successfully. 
	 */
	protected boolean contactSender(){
		if((m_sContactAddress != null && m_sContactAddress.length() > 0) || 
				(m_sServiceTypeInOSoL != null && m_sServiceTypeInOSoL.equals("scheduler"))){
			if(m_sContactTransportType == null || m_sContactTransportType.length() <= 0){
				m_sContactTransportType = "osp";
			}
			String sMessage1 = "Your job " + m_sJobID + " has completed on " + (OSParameter.SERVICE_URI);
			try {
				if(m_sContactTransportType.equals("smtp") && (m_sContactAddress != null && m_sContactAddress.length() > 0)){
					MailUtil.sendInThread(OSParameter.FROM_EMAIL, m_sContactAddress, null, null, "notifyJobCompletion", sMessage1, null);						
				}
				if(m_sContactTransportType.equals("osp") || (m_sServiceTypeInOSoL != null && m_sServiceTypeInOSoL.equals("scheduler"))){
					m_osplWriter = new OSpLWriter();
					m_osplWriter.setRequestAction("notifyJobCompletion");
					m_osplWriter.setServiceURI(OSParameter.SERVICE_URI);
					m_osplWriter.setServiceName(OSParameter.SERVICE_NAME);
					m_osplWriter.setProcessTime(new GregorianCalendar());
					m_osplWriter.setProcessMessage(sMessage1);
					JobStatistics[] mJobStatistics = new JobStatistics[1];
					mJobStatistics[0] = m_jobStatisticsTable.get(m_sJobID);
					m_osplWriter.setJobStatistics(mJobStatistics);
					String sProcessInput = m_osplWriter.writeToString();

					m_osolWriter = new OSoLWriter();
					m_osolWriter.setServiceURI(OSParameter.SERVICE_URI);
					m_osolWriter.setServiceName(OSParameter.SERVICE_NAME);
					m_osolWriter.setJobID(m_sJobID);
					m_osolWriter.setLicense(m_sLicense);
					m_osolWriter.setUserName(m_sUserName);		
					m_osolWriter.setPassword(OSParameter.getSystemPassword());			
					String sServiceType = (serviceType==null||serviceType.length() <= 0)?"solver":serviceType;
					m_osolWriter.setServiceType(sServiceType);
					String sOption = m_osolWriter.writeToString();
					
					if(m_sContactAddress != null && m_sContactAddress.length() > 0 && m_sContactTransportType.equals("osp")){
						if(!(serviceType.equals("scheduler") && m_sContactAddress.equals(OSParameter.OS_SCHEDULER_SITE))){
							KnockSolverThread knockSolverThread1 = new KnockSolverThread();
							OSSolverAgent osSolverAgent1 = new OSSolverAgent(m_sContactAddress);
							knockSolverThread1.m_osSolverAgent = osSolverAgent1;
							knockSolverThread1.m_osplInput = sProcessInput;
							knockSolverThread1.m_osol = sOption;
												
							Thread thread1 = new Thread(knockSolverThread1);	
							thread1.start();						
						}
					}
					
					if(((m_sContactAddress == null || m_sContactAddress.length() <= 0) || 
					   (m_sContactAddress != null && !m_sContactAddress.equals(OSParameter.OS_SCHEDULER_SITE))) && 
					   ((m_sServiceTypeInOSoL != null && m_sServiceTypeInOSoL.equals("scheduler")))){
						if(!serviceType.equals("scheduler")){
							KnockSolverThread knockSolverThread2 = new KnockSolverThread();
							OSSolverAgent osSolverAgent2 = new OSSolverAgent(OSParameter.OS_SCHEDULER_SITE);
							knockSolverThread2.m_osSolverAgent = osSolverAgent2;
							knockSolverThread2.m_osplInput = sProcessInput;
							knockSolverThread2.m_osol = sOption;
							
							Thread thread2 = new Thread(knockSolverThread2);	
							thread2.start();									
						}
					}
				}
				return true;
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
				return false;
			}
		}
		return true;
	}//contactSender
	
	/**
	 * request job at scheduler
	 * 
	 * @return if the job request is successful. 
	 */
	protected boolean requestJob(){
		if((m_sCurrentState.equals("busyButAccepting") || m_sCurrentState.equals("idle")) && 
				(serviceType == null || serviceType.length() <= 0 || serviceType.equals("solver") || serviceType.equals("analyzer"))){
			try {
				String sMessage = "The current state of the service (" + (OSParameter.SERVICE_URI) + ") is: " + m_sCurrentState;
				m_osplWriter = new OSpLWriter();
				m_osplWriter.setRequestAction("requestJob");
				m_osplWriter.setServiceURI(OSParameter.SERVICE_URI);
				m_osplWriter.setServiceName(OSParameter.SERVICE_NAME);
				m_osplWriter.setProcessTime(new GregorianCalendar());
				m_osplWriter.setProcessMessage(sMessage);
				String sProcessInput = m_osplWriter.writeToString();
				
				m_osolWriter = new OSoLWriter();
				m_osolWriter.setServiceURI(OSParameter.SERVICE_URI);
				m_osolWriter.setServiceName(OSParameter.SERVICE_NAME);
				m_osolWriter.setJobID(m_sJobID);
				m_osolWriter.setLicense(m_sLicense);
				m_osolWriter.setUserName(m_sUserName);		
				m_osolWriter.setPassword(OSParameter.getSystemPassword());							
				String sServiceType = (serviceType==null||serviceType.length() <= 0)?"solver":serviceType;
				m_osolWriter.setServiceType(sServiceType);
				String sOption = m_osolWriter.writeToString();

				KnockSolverThread knockSolverThread = new KnockSolverThread();
				OSSolverAgent osSolverAgent = new OSSolverAgent(OSParameter.OS_SCHEDULER_SITE);
				knockSolverThread.m_osSolverAgent = osSolverAgent;
				knockSolverThread.m_osplInput = sProcessInput;
				knockSolverThread.m_osol = sOption;
									
				Thread thread = new Thread(knockSolverThread);	
				thread.start();
				return true;
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
				return false;
			}
		}	
		return true;
	}//requestJob
	
	/**
	 * presolve handles prerequisites before invoking the solve method.
	 * 
	 * @param osil holds the instance in a string which format follows OSiL schema.
	 * @param osol holds the option in a string which format follows OSoL schema.
	 * @return whether the presolve is successful. 
	 */
	protected boolean presolve(String osil, String osol){
		if(osil == null) osil = "";
		if(osol == null) osol = "";
		
		//from OSParameter
		if(OSParameter.DIRECTORIES_TO_MAKE !=null && OSParameter.DIRECTORIES_TO_MAKE.length > 0){
			for(int i = 0; i < OSParameter.DIRECTORIES_TO_MAKE.length; i++){
				boolean bSuccess = IOUtil.makeDir(OSParameter.DIRECTORIES_TO_MAKE[i]);
				if(! bSuccess){
					IOUtil.log("not able to make dir " + OSParameter.DIRECTORIES_TO_MAKE[i], null);	
				}
			}
		}
		if(OSParameter.FILES_TO_CREATE !=null && OSParameter.FILES_TO_CREATE.length > 0){
			for(int i = 0; i < OSParameter.FILES_TO_CREATE.length; i++){
				boolean bSuccess = IOUtil.createFile(OSParameter.FILES_TO_CREATE[i]);
				if(! bSuccess){
					IOUtil.log("not able to create file " + OSParameter.FILES_TO_CREATE[i], null);	
				}
			}
		}
		if(OSParameter.SAVE_INPUTS){
			String sInstanceFile = OSParameter.TEMP_FILE_FOLDER+m_sJobID+".osil";
			String sOptionFile = OSParameter.TEMP_FILE_FOLDER+m_sJobID+".osol";
			boolean bWrite = true;
			if(!IOUtil.existsFileOrDir(sInstanceFile)){
				bWrite = IOUtil.writeStringToFile(osil, sInstanceFile);
			}
			if(!bWrite){
				IOUtil.log("the solve method is not able to write osil to file", null);
				IOUtil.deleteFile(sInstanceFile);
			}
			bWrite = true;
			if(!IOUtil.existsFileOrDir(sOptionFile)){
				bWrite = IOUtil.writeStringToFile(osol, sOptionFile);
			}
			if(!bWrite){
				IOUtil.log("the solve method is not able to write osol to file", null);
				IOUtil.deleteFile(sOptionFile);
			}
		}
		if((OSParameter.INPUT_FILES_TO_COPY_FROM != null && OSParameter.INPUT_FILES_TO_COPY_FROM.length > 0) ||
				(OSParameter.INPUT_FILES_TO_COPY_TO !=null && OSParameter.INPUT_FILES_TO_COPY_TO.length > 0)){
			int m = OSParameter.INPUT_FILES_TO_COPY_FROM==null?0:OSParameter.INPUT_FILES_TO_COPY_FROM.length;
			int n = OSParameter.INPUT_FILES_TO_COPY_TO==null?0:OSParameter.INPUT_FILES_TO_COPY_TO.length;
			if(m != n){
				IOUtil.log("number of INPUT_FILES_TO_COPY_FROM not equal to number of INPUT_FILES_TO_COPY_TO", null);
			}
			else{
				for(int i = 0; i < m; i++){
					boolean bSuccess  = IOUtil.copyFile(OSParameter.INPUT_FILES_TO_COPY_FROM[i], OSParameter.INPUT_FILES_TO_COPY_TO[i]);
					if(! bSuccess){
						IOUtil.log("not able to copy file from " + OSParameter.INPUT_FILES_TO_COPY_FROM[i] + " to " +  OSParameter.INPUT_FILES_TO_COPY_TO[i], null);	
					}
				}
			}
		}
		if((OSParameter.INPUT_FILES_TO_MOVE_FROM != null && OSParameter.INPUT_FILES_TO_MOVE_FROM.length > 0) ||
			(OSParameter.INPUT_FILES_TO_MOVE_TO !=null && OSParameter.INPUT_FILES_TO_MOVE_TO.length > 0)){
			int m = OSParameter.INPUT_FILES_TO_MOVE_FROM==null?0:OSParameter.INPUT_FILES_TO_MOVE_FROM.length;
			int n = OSParameter.INPUT_FILES_TO_MOVE_TO==null?0:OSParameter.INPUT_FILES_TO_MOVE_TO.length;
			if(m != n){
				IOUtil.log("number of INPUT_FILES_TO_MOVE_FROM not equal to number of INPUT_FILES_TO_MOVE_TO", null);
			}
			else{
				for(int i = 0; i < m; i++){
					boolean bSuccess  = IOUtil.moveFile(OSParameter.INPUT_FILES_TO_MOVE_FROM[i], OSParameter.INPUT_FILES_TO_MOVE_TO[i]);
					if(! bSuccess){
						IOUtil.log("not able to move file from " + OSParameter.INPUT_FILES_TO_MOVE_FROM[i] + " to " +  OSParameter.INPUT_FILES_TO_MOVE_TO[i], null);	
					}
				}
			}
		}		
		
		//from OSoL	
		if(OSParameter.ALLOW_IO_OPERATIONS_BY_USERS){
			String[] msDirectoriesToMake = m_osOption.getDirectoriesToMake();
			if(msDirectoriesToMake !=null && msDirectoriesToMake.length > 0){
				for(int i = 0; i < msDirectoriesToMake.length; i++){
					boolean bSuccess = IOUtil.makeDir(msDirectoriesToMake[i]);
					if(! bSuccess){
						IOUtil.log("not able to make dir " + msDirectoriesToMake[i], null);	
					}
				}
			}
			String[] msFilesToCreate = m_osOption.getFilesToCreate();
			if(msFilesToCreate !=null && msFilesToCreate.length > 0){
				for(int i = 0; i < msFilesToCreate.length; i++){
					boolean bSuccess = IOUtil.createFile(msFilesToCreate[i]);
					if(! bSuccess){
						IOUtil.log("not able to create file " + msFilesToCreate[i], null);	
					}
				}
			}
			String[] msInputFilesToCopyFrom = m_osOption.getInputFilesToCopyFrom();
			String[] msInputFilesToCopyTo = m_osOption.getInputFilesToCopyTo();
			if((msInputFilesToCopyFrom != null && msInputFilesToCopyFrom.length > 0) ||
					(msInputFilesToCopyTo !=null && msInputFilesToCopyTo.length > 0)){
				int m = msInputFilesToCopyFrom==null?0:msInputFilesToCopyFrom.length;
				int n = msInputFilesToCopyTo==null?0:msInputFilesToCopyTo.length;
				if(m != n){
					IOUtil.log("number of INPUT_FILES_TO_COPY_FROM not equal to number of INPUT_FILES_TO_COPY_TO", null);
				}
				else{
					for(int i = 0; i < m; i++){
						boolean bSuccess  = IOUtil.copyFile(msInputFilesToCopyFrom[i], msInputFilesToCopyTo[i]);
						if(! bSuccess){
							IOUtil.log("not able to copy file from " + msInputFilesToCopyFrom[i] + " to " +  msInputFilesToCopyTo[i], null);	
						}
					}
				}
			}
			String[] msInputFilesToMoveFrom = m_osOption.getInputFilesToMoveFrom();
			String[] msInputFilesToMoveTo = m_osOption.getInputFilesToMoveTo();
			if((msInputFilesToMoveFrom != null && msInputFilesToMoveFrom.length > 0) ||
				(msInputFilesToMoveTo !=null && msInputFilesToMoveTo.length > 0)){
				int m = msInputFilesToMoveFrom==null?0:msInputFilesToMoveFrom.length;
				int n = msInputFilesToMoveTo==null?0:msInputFilesToMoveTo.length;
				if(m != n){
					IOUtil.log("number of INPUT_FILES_TO_MOVE_FROM not equal to number of INPUT_FILES_TO_MOVE_TO", null);
				}
				else{
					for(int i = 0; i < m; i++){
						boolean bSuccess  = IOUtil.moveFile(msInputFilesToMoveFrom[i], msInputFilesToMoveTo[i]);
						if(! bSuccess){
							IOUtil.log("not able to move file from " + msInputFilesToMoveFrom[i] + " to " +  msInputFilesToMoveTo[i], null);	
						}
					}
				}
			}				
		}
		return true;
	}//presolve
	
	/**
	 * postsolve handles works after invoking the solve method.
	 * 
	 * @return whether the postsolve is successful. 
	 */
	protected boolean postsolve(){
		m_iCurrentJobCount = m_vCurrentJobIDs.size();
		if(m_iCurrentJobCount <= 1){
			if((OSParameter.OUTPUT_FILES_TO_COPY_FROM != null && OSParameter.OUTPUT_FILES_TO_COPY_FROM.length > 0) ||
					(OSParameter.OUTPUT_FILES_TO_COPY_TO !=null && OSParameter.OUTPUT_FILES_TO_COPY_TO.length > 0)){
				int m = OSParameter.OUTPUT_FILES_TO_COPY_FROM==null?0:OSParameter.OUTPUT_FILES_TO_COPY_FROM.length;
				int n = OSParameter.OUTPUT_FILES_TO_COPY_TO==null?0:OSParameter.OUTPUT_FILES_TO_COPY_TO.length;
				if(m != n){
					IOUtil.log("number of OUTPUT_FILES_TO_COPY_FROM not equal to number of OUTPUT_FILES_TO_COPY_TO", null);
				}
				else{
					for(int i = 0; i < m; i++){
						boolean bSuccess  = IOUtil.copyFile(OSParameter.OUTPUT_FILES_TO_COPY_FROM[i], OSParameter.OUTPUT_FILES_TO_COPY_TO[i]);
						if(! bSuccess){
							IOUtil.log("not able to copy file from " + OSParameter.OUTPUT_FILES_TO_COPY_FROM[i] + " to " +  OSParameter.OUTPUT_FILES_TO_COPY_TO[i], null);	
						}
					}
				}
			}
			if((OSParameter.OUTPUT_FILES_TO_MOVE_FROM != null && OSParameter.OUTPUT_FILES_TO_MOVE_FROM.length > 0) ||
				(OSParameter.OUTPUT_FILES_TO_MOVE_TO != null && OSParameter.OUTPUT_FILES_TO_MOVE_TO.length > 0)){
				int m = OSParameter.OUTPUT_FILES_TO_MOVE_FROM==null?0:OSParameter.OUTPUT_FILES_TO_MOVE_FROM.length;
				int n = OSParameter.OUTPUT_FILES_TO_MOVE_TO==null?0:OSParameter.OUTPUT_FILES_TO_MOVE_TO.length;
				if(m != n){
					IOUtil.log("number of OUTPUT_FILES_TO_MOVE_FROM not equal to number of OUTPUT_FILES_TO_MOVE_TO", null);
				}
				else{
					for(int i = 0; i < m; i++){
						boolean bSuccess  = IOUtil.moveFile(OSParameter.OUTPUT_FILES_TO_MOVE_FROM[i], OSParameter.OUTPUT_FILES_TO_MOVE_TO[i]);
						if(! bSuccess){
							IOUtil.log("not able to move file from " + OSParameter.OUTPUT_FILES_TO_MOVE_FROM[i] + " to " +  OSParameter.OUTPUT_FILES_TO_MOVE_TO[i], null);	
						}
					}
				}
			}	
			if(OSParameter.FILES_TO_DELETE !=null && OSParameter.FILES_TO_DELETE.length > 0){
				for(int i = 0; i < OSParameter.FILES_TO_DELETE.length; i++){
					boolean bSuccess = IOUtil.deleteFile(OSParameter.FILES_TO_DELETE[i]);
					if(! bSuccess){
						IOUtil.log("not able to delete file " + OSParameter.FILES_TO_DELETE[i], null);	
					}
				}
			}
			if(OSParameter.DIRECTORIES_TO_DELETE !=null && OSParameter.DIRECTORIES_TO_DELETE.length > 0){
				for(int i = 0; i < OSParameter.DIRECTORIES_TO_DELETE.length; i++){
					boolean bSuccess = IOUtil.deleteDir(OSParameter.DIRECTORIES_TO_DELETE[i]);
					if(! bSuccess){
						IOUtil.log("not able to delete dir " + OSParameter.DIRECTORIES_TO_DELETE[i], null);	
					}
				}
			}
			
			if(OSParameter.PROCESSES_TO_KILL != null && OSParameter.PROCESSES_TO_KILL.length > 0){
				for(int i = 0; i < OSParameter.PROCESSES_TO_KILL.length; i++){
					boolean bSuccess = ProcessUtil.killProcessByName(OSParameter.PROCESSES_TO_KILL[i]);
					if(!bSuccess){
						IOUtil.log("not able to kill process " + OSParameter.PROCESSES_TO_KILL[i], null);
					}
				}
			}
		}
		//from osol
		if(OSParameter.ALLOW_IO_OPERATIONS_BY_USERS){
			String[] msOutputFilesToCopyFrom = m_osOption.getOutputFilesToCopyFrom();
			String[] msOutputFilesToCopyTo = m_osOption.getOutputFilesToCopyTo();
			if((msOutputFilesToCopyFrom != null && msOutputFilesToCopyFrom.length > 0) ||
					(msOutputFilesToCopyTo !=null && msOutputFilesToCopyTo.length > 0)){
				int m = msOutputFilesToCopyFrom==null?0:msOutputFilesToCopyFrom.length;
				int n = msOutputFilesToCopyTo==null?0:msOutputFilesToCopyTo.length;
				if(m != n){
					IOUtil.log("number of OUTPUT_FILES_TO_COPY_FROM not equal to number of OUTPUT_FILES_TO_COPY_TO", null);
				}
				else{
					for(int i = 0; i < m; i++){
						boolean bSuccess  = IOUtil.copyFile(msOutputFilesToCopyFrom[i], msOutputFilesToCopyTo[i]);
						if(! bSuccess){
							IOUtil.log("not able to copy file from " + msOutputFilesToCopyFrom[i] + " to " +  msOutputFilesToCopyTo[i], null);	
						}
					}
				}
			}
			String[] msOutputFilesToMoveFrom = m_osOption.getOutputFilesToMoveFrom();
			String[] msOutputFilesToMoveTo = m_osOption.getOutputFilesToMoveTo();
			if((msOutputFilesToMoveFrom != null && msOutputFilesToMoveFrom.length > 0) ||
				(msOutputFilesToMoveTo !=null && msOutputFilesToMoveTo.length > 0)){
				int m = msOutputFilesToMoveFrom==null?0:msOutputFilesToMoveFrom.length;
				int n = msOutputFilesToMoveTo==null?0:msOutputFilesToMoveTo.length;
				if(m != n){
					IOUtil.log("number of OUTPUT_FILES_TO_MOVE_FROM not equal to number of OUTPUT_FILES_TO_MOVE_TO", null);
				}
				else{
					for(int i = 0; i < m; i++){
						boolean bSuccess  = IOUtil.moveFile(msOutputFilesToMoveFrom[i], msOutputFilesToMoveTo[i]);
						if(! bSuccess){
							IOUtil.log("not able to move file from " + msOutputFilesToMoveFrom[i] + " to " +  msOutputFilesToMoveTo[i], null);	
						}
					}
				}
			}

			String[] msFilesToDelete = m_osOption.getFilesToDelete();
			if(msFilesToDelete !=null && msFilesToDelete.length > 0){
				for(int i = 0; i < msFilesToDelete.length; i++){
					boolean bSuccess = IOUtil.deleteFile(msFilesToDelete[i]);
					if(! bSuccess){
						IOUtil.log("not able to delete file " + msFilesToDelete[i], null);	
					}
				}
			}
			String[] msDirectoriesToDelete = m_osOption.getDirectoriesToDelete();
			if(msDirectoriesToDelete !=null && msDirectoriesToDelete.length > 0){
				for(int i = 0; i < msDirectoriesToDelete.length; i++){
					boolean bSuccess = IOUtil.deleteDir(msDirectoriesToDelete[i]);
					if(! bSuccess){
						IOUtil.log("not able to delete dir " + msDirectoriesToDelete[i], null);	
					}
				}
			}
			String[] msProcessesToKill = m_osOption.getProcessesToKill();
			if(msProcessesToKill != null && msProcessesToKill.length > 0){
				for(int i = 0; i < msProcessesToKill.length; i++){
					boolean bSuccess = ProcessUtil.killProcessByName(msProcessesToKill[i]);
					if(!bSuccess){
						IOUtil.log("not able to kill process " + msProcessesToKill[i], null);
					}
				}
			}
		}
		return true;
	}//postsolve
	
	/**
	 * Call a solver or analyzer service whose input is given by a string following 
	 * the OSiL schema and returns the result in a string that follows OSrL schema. 
	 * @param osil holds the instance in a string which format follows OSiL schema.
	 * @param osol holds the option in a string which format follows OSoL schema.
	 * @return osrl, the result in a string which format follows the OSrL schema. 
	 */
	public String solve(String osil, String osol){
		if(osil == null) osil = "";
		if(osol == null) osol = "";
		String sOSrL = "";
		m_osrlWriter = new OSrLWriter();
		m_osrlWriter.setServiceURI(OSParameter.SERVICE_URI);
		m_osrlWriter.setServiceName(OSParameter.SERVICE_NAME);
		m_osrlWriter.setResultTime(new GregorianCalendar());
		
		//read osol
		if(osol != null && osol.length() > 0){
			if(!readOSoL(osol)){
				m_osrlWriter.setGeneralStatusType("error");
				m_osrlWriter.setGeneralStatusDescription("Invalid OSoL option");
				sOSrL = m_osrlWriter.writeToString();
				return sOSrL;
			}
		}
		if(m_osOption == null) m_osOption = new OSOption();
			
		//check permission
		try {
			if(!checkPermision()){
				m_osrlWriter.setGeneralStatusType("error");
				m_osrlWriter.setGeneralStatusDescription("Permission error.");
				sOSrL = m_osrlWriter.writeToString();
				return sOSrL;
			}
		} 
		catch (Exception e){
			IOUtil.log(e.getMessage(), null);
			m_osrlWriter.setGeneralStatusType("error");
			m_osrlWriter.setGeneralStatusDescription(e.getMessage());
			sOSrL = m_osrlWriter.writeToString();
			return sOSrL;
		}
		
		//if no jobID exists, automatically create one and establish job statistics 
		if(m_sJobID == null || m_sJobID.length() <= 0 ){
			m_sJobID = "AUTOJOBID_" + CommonUtil.getJobID(null);
			m_osOption.setJobID(m_sJobID);
		}
		m_osrlWriter.setJobID(m_sJobID);
		String sTime = XMLUtil.createXSDateTime(new GregorianCalendar());
		IOUtil.log("job ID: "+m_sJobID+":" + sTime, null);
		
		//see if the job is resubmit
		JobStatistics jobStatistics = m_jobStatisticsTable.get(m_sJobID);
		if(jobStatistics != null){
			if(jobStatistics.state.equals("finished") ){
				m_osrlWriter.setGeneralStatusType("error");
				m_osrlWriter.setGeneralStatusDescription("Job " + m_sJobID + " is alreday finished. Cannot submit again. ");
				sOSrL = m_osrlWriter.writeToString();
				return sOSrL;
			}
			else if(jobStatistics.state.equals("killed") ){
				m_osrlWriter.setGeneralStatusType("error");
				m_osrlWriter.setGeneralStatusDescription("Job " + m_sJobID + " is alreday killed. Cannot submit again. ");
				sOSrL = m_osrlWriter.writeToString();
				return sOSrL;
			}
			else if(jobStatistics.state.equals("running") ){
				m_osrlWriter.setGeneralStatusType("error");
				m_osrlWriter.setGeneralStatusDescription("Job " + m_sJobID + " is alreday running. Cannot submit again. ");
				sOSrL = m_osrlWriter.writeToString();
				return sOSrL;
			}
		}
		
		//check system requirement
		try {
			if(!checkSystemRequirement()) {
				m_osrlWriter.setGeneralStatusType("warning");
				m_osrlWriter.setGeneralStatusDescription("System warning: system requirement not met.");
				sOSrL = m_osrlWriter.writeToString();
				return sOSrL;
			}
		} 
		catch (Exception e) {
			IOUtil.log(e.getMessage(), null);
			m_osrlWriter.setGeneralStatusType("warning");
			m_osrlWriter.setGeneralStatusDescription(e.getMessage());
			sOSrL = m_osrlWriter.writeToString();
			return sOSrL;
		}
		
		String osol2 = osol; 
		try {
			osol2 = m_osOption.writeOSoL();
		} 
		catch (Exception e) {
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
			m_osrlWriter.setGeneralStatusType("error");
			m_osrlWriter.setGeneralStatusDescription(e.getMessage());
			m_osrlWriter.setGeneralMessage(IOUtil.exceptionStackToString(e));
			sOSrL = m_osrlWriter.writeToString();
			return sOSrL;
		}
		
		//check waiting: scheduleTime, jobdependencies, required files/directories, solver availability
		if(m_solverThread == null){
			m_solverThread = new SolverThread();	
		}
		if((m_sServiceTypeInOSoL != null && !m_sServiceTypeInOSoL.equals("scheduler")) || m_sServiceTypeInOSoL == null || 
			(serviceType != null && serviceType.equals("scheduler"))){
			try {		
				if(checkWaiting(osil, osol2, serviceType.equals("scheduler"), false)){
					m_osrlWriter.setGeneralStatusType("warning");
					m_osrlWriter.setGeneralStatusDescription("System warning: no waiting allowed for the solve method. Please call send.");
					sOSrL = m_osrlWriter.writeToString();
					return sOSrL;
				}	
			}
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
				m_osrlWriter.setGeneralStatusType("warning");
				m_osrlWriter.setGeneralStatusDescription(e.getMessage());
				m_osrlWriter.setGeneralMessage(IOUtil.exceptionStackToString(e));
				sOSrL = m_osrlWriter.writeToString();
				return sOSrL;			
			}			
		}
		
		//initializeStatistics
		initializeStatistics();
				
		//launch solver thread
		try{
			m_solverThread.m_sOSiL = osil;
			m_solverThread.m_sOSoL = osol2;
			m_solverThread.m_osOption = m_osOption;
			m_solverThread.m_bCalledFromSend = false;
			
			m_osrlWriter.setGeneralStatusType("warning");
			m_osrlWriter.setGeneralStatusDescription("No result returned or no result yet.");
			m_solverThread.m_sOSrL = m_osrlWriter.writeToString();
			
			Thread thread = new Thread(m_solverThread);
			thread.setName(m_sJobID);			
			
			m_solverThreadHashTable.remove(m_sJobID);
			m_solverThreadHashTable.put(m_sJobID, m_solverThread);
			m_threadHashTable.remove(m_sJobID);
			m_threadHashTable.put(m_sJobID, thread);
			
			thread.start();

			long lTimeSpan = (long)m_dJobMaxTime*1000;
			thread.join(lTimeSpan);
			if(!m_vFinishedJobIDs.contains(m_sJobID)){
				kill(osol2);
				m_osrlWriter.setGeneralStatusType("warning");
				m_osrlWriter.setGeneralStatusDescription("maximum job time reached");
				sOSrL = m_osrlWriter.writeToString();
			}
			else{
				sOSrL = m_solverThread.m_sOSrL;
			}
		}
		catch(Exception e){
			String sResult = "";
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
			String sResultFile = OSParameter.TEMP_FILE_FOLDER+m_sJobID+".osrl";
			boolean bWriteResult = false;
			if(!IOUtil.existsFileOrDir(sResultFile)) bWriteResult = true;
			else{
				sResult = IOUtil.readStringFromFile(sResultFile);
				if(sResult == null || sResult.length() <= 0){
					sResult = "";
					bWriteResult = true;
				}
				else{
					OSrLReader osrlReader = new OSrLReader();
					try {
						boolean bRead = osrlReader.readString(sResult);
						if(!bRead) throw new Exception("Invalid OSrL result");
						String sStatus = osrlReader.getGeneralStatusType();
						if(sStatus == null || !sStatus.equals("success")){
							bWriteResult = true;
						}
						else{
							bWriteResult = false;
						}
					}
					catch (Exception e1) {
						IOUtil.log(IOUtil.exceptionStackToString(e), null);
						bWriteResult = true;
					}
				}
			}
			if(bWriteResult){
				m_osrlWriter.setGeneralStatusType("error");
				m_osrlWriter.setGeneralStatusDescription(e.getMessage());
				m_osrlWriter.setGeneralMessage(IOUtil.exceptionStackToString(e));
				sOSrL = m_osrlWriter.writeToString();
				IOUtil.writeStringToFile(sOSrL, sResultFile);									
			}
			else{
				sOSrL = sResult;
			}
			try {
				postprocess(false);				
			} 
			catch (Exception e2) {
				IOUtil.log(IOUtil.exceptionStackToString(e2), null);
			}
		}
		if(sOSrL == null || sOSrL.length() <= 0){
			m_osrlWriter.setGeneralStatusType("warning");
			m_osrlWriter.setGeneralStatusDescription("No result");
			sOSrL = m_osrlWriter.writeToString();			
		}
		return sOSrL;
	}//solve
	
	/**
	 * Send (or asynchronously solve) an instance to a solver, analyzer or scheduler service
	 * whose input is given by a string following the OSiL schema and returns the result
	 * in a string that follows OSrL schema. 
	 * @param osil holds the instance in a string which format follows OSiL schema. 
	 * @param osol holds the option in a string which format follows OSoL schema. 
	 * It should contain the jobID information that is previous obtained from the service.
	 * @return success, whether the asynchronous communication is successful or not
	 */
	public boolean send(String osil, String osol){
		if(osil == null) osil = "";
		if(osol == null) osol = "";
		m_osrlWriter = new OSrLWriter();
		
		//check osol
		if(osol == null || osol.length() <= 0){
			IOUtil.log("Empty string for the send method", null);
			return false;
		}
		if(!readOSoL(osol)) return false;	
		if(m_osOption == null) m_osOption = new OSOption();

		//check permission
		try {
			if(!checkPermision()) return false;
		} 
		catch (Exception e) {
			IOUtil.log(e.getMessage(), null);
			return false;
		}
		
		//check if jobID exists 
		if(m_sJobID == null || m_sJobID.length() <= 0 ){
			IOUtil.log("No jobID in OSoL", null);
			return false;
		}
		String sTime = XMLUtil.createXSDateTime(new GregorianCalendar());
		IOUtil.log("job ID: "+m_sJobID+":" + sTime, null);

		//see if the job is resubmit
		JobStatistics jobStatistics = m_jobStatisticsTable.get(m_sJobID);
		if(jobStatistics != null){
			if(jobStatistics.state.equals("finished") ){
				IOUtil.log("Job " + m_sJobID + " is alreday finished. Cannot submit again. ", null);
				return false;
			}
			else if(jobStatistics.state.equals("killed") ){
				IOUtil.log("Job " + m_sJobID + " is alreday killed. Cannot submit again. ", null);
				return false;
			}
			else if(jobStatistics.state.equals("running") ){
				IOUtil.log("Job " + m_sJobID + " is alreday running. Cannot submit again. ", null);
				return false;
			}
		}

		//check system requirement
		try {
			if(!checkSystemRequirement()) return false;
		} 
		catch (Exception e) {
			IOUtil.log(e.getMessage(), null);
			return false;
		}

		//initializeStatistics
		initializeStatistics();
		
		if(m_solverThread == null){
			m_solverThread = new SolverThread();	
		}	
		String osol2 = osol; 
		try {
			osol2 = m_osOption.writeOSoL();
		} 
		catch (Exception e) {
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
			return false;
		}

		//check waiting: scheduleTime, jobdependencies, required files/directories, solver availability
		if((m_sServiceTypeInOSoL != null && !m_sServiceTypeInOSoL.equals("scheduler")) || m_sServiceTypeInOSoL == null ||
				(serviceType != null && serviceType.equals("scheduler"))){
			try {
				if(checkWaiting(osil, osol2, serviceType.equals("scheduler"), true)) return true;			
			} 
			catch (Exception e) {
				IOUtil.log(e.getMessage(), null);
				return false;
			}
		}

		//launch thread
		try{			
			m_solverThread.m_sOSiL = osil;
			m_solverThread.m_sOSoL = osol2;
			m_solverThread.m_osOption = m_osOption;
			m_solverThread.m_bCalledFromSend = true;

			m_osrlWriter.setGeneralStatusType("warning");
			m_osrlWriter.setGeneralStatusDescription("No result returned or no result yet.");
			m_solverThread.m_sOSrL = m_osrlWriter.writeToString();

			Thread thread = new Thread(m_solverThread);
			thread.setName(m_sJobID);
			
			m_solverThreadHashTable.remove(m_sJobID);
			m_solverThreadHashTable.put(m_sJobID, m_solverThread);
			m_threadHashTable.remove(m_sJobID);
			m_threadHashTable.put(m_sJobID, thread);
			
			thread.start();
		}
		catch(Exception e){
			String sResult = "";
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
			String sResultFile = OSParameter.TEMP_FILE_FOLDER+m_sJobID+".osrl";
			boolean bWriteResult = false;
			if(!IOUtil.existsFileOrDir(sResultFile)) bWriteResult = true;
			else{
				sResult = IOUtil.readStringFromFile(sResultFile);
				if(sResult == null || sResult.length() <= 0){
					sResult = "";
					bWriteResult = true;
				}
				else{
					OSrLReader osrlReader = new OSrLReader();
					try {
						boolean bRead = osrlReader.readString(sResult);
						if(!bRead) throw new Exception("Invalid OSrL result");
						String sStatus = osrlReader.getGeneralStatusType();
						if(sStatus == null || !sStatus.equals("success")){
							bWriteResult = true;
						}
						else{
							bWriteResult = false;
						}
					}
					catch (Exception e1) {
						IOUtil.log(IOUtil.exceptionStackToString(e), null);
						bWriteResult = true;
					}
				}
			}
			if(bWriteResult){
				m_osrlWriter = new OSrLWriter();
				m_osrlWriter.setServiceURI(OSParameter.SERVICE_URI);
				m_osrlWriter.setServiceName(OSParameter.SERVICE_NAME);
				m_osrlWriter.setJobID(m_sJobID);
				m_osrlWriter.setResultTime(new GregorianCalendar());
				m_osrlWriter.setGeneralStatusType("error");
				m_osrlWriter.setGeneralStatusDescription(e.getMessage());
				m_osrlWriter.setGeneralMessage(IOUtil.exceptionStackToString(e));
				String sOSrL = m_osrlWriter.writeToString();
				IOUtil.writeStringToFile(sOSrL, sResultFile);	
								
				try {
					postprocess(false);				
				} 
				catch (Exception e2) {
					IOUtil.log(IOUtil.exceptionStackToString(e2), null);
				}
				return false;			
			}
			else{
				postprocess(false);
				return true;
			}
		}
		return true;
	}//send

	/**
	 * Retrieve results from a previously sent/solved optimization job.  	
	 * 
	 * @param osol holds the option in a string which format follows OSoL schema
	 * It should contain the jobID information that is previous obtained from the service.
	 * @return osrl, the result in a string which format follows the OSrL schema. 
	 * If the result cannot be retrieved, it should be indicated in the message/status section of OSrL.
	 */
	@SuppressWarnings("deprecation")
	public String retrieve(String osol){
		if(osol == null) osol = "";

		String sOSrL = "";
		m_osrlWriter = new OSrLWriter();
		m_osrlWriter.setServiceURI(OSParameter.SERVICE_URI);
		m_osrlWriter.setServiceName(OSParameter.SERVICE_NAME);
		m_osrlWriter.setResultTime(new GregorianCalendar());

		//read osol
		if(osol == null || osol.length() <= 0){
			m_osrlWriter.setGeneralStatusType("error");
			m_osrlWriter.setGeneralStatusDescription("No OSoL option specified");
			sOSrL = m_osrlWriter.writeToString();
			return sOSrL;	
		}
		if(!readOSoL(osol)){
			m_osrlWriter.setGeneralStatusType("error");
			m_osrlWriter.setGeneralStatusDescription("Invalid OSoL option");
			sOSrL = m_osrlWriter.writeToString();
			return sOSrL;
		}
		if(m_osOption == null) m_osOption = new OSOption();

		//check permission
		if(!OSParameter.REQUIRE_ONLY_JOB_ID_TO_RETRIEVE_JOB_RESULT){
			try {
				if(!checkPermision()){
					m_osrlWriter.setGeneralStatusType("error");
					m_osrlWriter.setGeneralStatusDescription("Permission error.");
					sOSrL = m_osrlWriter.writeToString();
					return sOSrL;
				}
			} 
			catch (Exception e) {
				IOUtil.log(e.getMessage(), null);
				m_osrlWriter.setGeneralStatusType("error");
				m_osrlWriter.setGeneralStatusDescription(e.getMessage());
				sOSrL = m_osrlWriter.writeToString();
				return sOSrL;
			}
		}	
		//may also need to check if the user name matches the job's user name
				
		//check jobID
		if(m_sJobID == null || m_sJobID.length() <= 0 ){
			m_osrlWriter.setGeneralStatusType("error");
			m_osrlWriter.setGeneralStatusDescription("no job id found");
			sOSrL = m_osrlWriter.writeToString();
			return sOSrL;
		}
		m_osrlWriter.setJobID(m_sJobID);
		
		//retrieve
		try {
			sOSrL = IOUtil.readStringFromFile(OSParameter.TEMP_FILE_FOLDER+m_sJobID+".osrl");
			if(sOSrL == null){
				sOSrL = "";
			}
		} 
		catch (Exception e) {
		}
		
		//check if there is the job
		JobStatistics jobStatistics = m_jobStatisticsTable.get(m_sJobID);
		if(jobStatistics == null && (sOSrL == null || sOSrL.length() <= 0)){
			m_osrlWriter.setGeneralStatusType("warning");
			m_osrlWriter.setGeneralStatusDescription( m_sJobID+" is not found");
			sOSrL = m_osrlWriter.writeToString();
			return sOSrL;
		}

		if(sOSrL == null || sOSrL.length() <= 0){
			boolean bWarning = true;
			if(serviceType.equals("scheduler")){
				try {
					OSSolverAgent solverAgent = new OSSolverAgent();
					solverAgent.solverAddress = jobStatistics.serviceURI; 
					if(solverAgent.solverAddress != null && solverAgent.solverAddress.length() > 0 && 
							!solverAgent.solverAddress.equals(OSParameter.OS_SCHEDULER_SITE) &&
							!solverAgent.solverAddress.equals(OSParameter.SERVICE_URI)){
						sOSrL = solverAgent.retrieve(osol);
						if(sOSrL != null && sOSrL.length() > 0){
							try {
								OSrLReader osrlReader = new OSrLReader();
								boolean bRead = osrlReader.readString(sOSrL);
								if(!bRead) throw new Exception("Invalid OSrL result");
								bWarning = false;
								String sStatus = osrlReader.getGeneralStatusType();
								if(sStatus != null && (sStatus.equals("success") || sStatus.equals("error"))){
									String sResultFile = OSParameter.TEMP_FILE_FOLDER+m_sJobID+".osrl";
									boolean	bWrite = IOUtil.writeStringToFile(sOSrL, sResultFile);				
									if(!bWrite){
										IOUtil.log("result file not written successfully", null);
									}
								}								
							} 
							catch (Exception e) {
								IOUtil.log(IOUtil.exceptionStackToString(e), null);
							}
						}
						else{
							throw new Exception("no result found");
						}
					}
					else{
						throw new Exception("cannot find the right service address to retrieve the job");
					}
				} 
				catch (Exception e) {
					IOUtil.log(IOUtil.exceptionStackToString(e), null);
				}
			}
			if(bWarning){
				m_osrlWriter.setGeneralStatusType("warning");
				m_osrlWriter.setGeneralStatusDescription("no result found");
				sOSrL = m_osrlWriter.writeToString();
				return sOSrL;
			}
		}

		if(m_vFinishedJobIDs.contains(m_sJobID)) return sOSrL;
		
		Thread thread = (Thread)m_threadHashTable.get(m_sJobID);
		if(thread != null){
			try{
				thread.stop();
			}
			catch(Exception e){
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}

		jobStatistics  = m_jobStatisticsTable.get(m_sJobID);		
		if(jobStatistics == null){
			jobStatistics = new JobStatistics();						
			jobStatistics.jobID = m_sJobID;
			m_jobStatisticsTable.put(m_sJobID, jobStatistics);
		}		

		if(jobStatistics.userName == null || jobStatistics.userName.length() <= 0){
			jobStatistics.userName = m_sUserName;
		}		
		
		String sUserName = jobStatistics.userName;
		if(sUserName == null) sUserName = "";
		String sCount = m_userJobCountTable.get(sUserName);
		int iCount;
		if(sCount == null || sCount.length() <= 0){
			iCount = 0;
		}
		else{
			try {
				iCount = Integer.parseInt(sCount);					
			} 
			catch (Exception e) {
				iCount = 0;
			}
			if(iCount <= 0){
				iCount = 0;
			}
			else if(m_vWaitingJobIDs.contains(m_sJobID) || m_vCurrentJobIDs.contains(m_sJobID)){
				iCount -= 1;
			}
		}
		m_userJobCountTable.remove(sUserName);
		m_userJobCountTable.put(sUserName, iCount+"");

		m_solverThreadHashTable.remove(m_sJobID);
		m_threadHashTable.remove(m_sJobID);
		m_vCurrentJobIDs.remove(m_sJobID);
		m_vWaitingJobIDs.remove(m_sJobID);
		m_vFinishedJobIDs.remove(m_sJobID);
		m_vFinishedJobIDs.add(m_sJobID);
		m_iCurrentJobCount = m_vCurrentJobIDs.size();
		
		if(jobStatistics.jobID == null || jobStatistics.jobID.length() <= 0){
			jobStatistics.jobID = m_sJobID;
		}
		if((jobStatistics.serviceURI == null ||  jobStatistics.serviceURI.length() <= 0) && !serviceType.equals("scheduler")){
			jobStatistics.serviceURI = (OSParameter.SERVICE_URI);
		}
		if(jobStatistics.serviceURI != null && jobStatistics.serviceURI.equals(OSParameter.OS_SCHEDULER_SITE)){
			jobStatistics.serviceURI = "";
		}
		if(jobStatistics.state == null || (!jobStatistics.state.equals("finished") && !jobStatistics.state.equals("killed"))){
			jobStatistics.state = "finished";			
		}		
		if(jobStatistics.endTime == null || jobStatistics.endTime.get(Calendar.YEAR) <= 1970){
			if(serviceType.equals("scheduler")){	
				String sOSpLOutput = "";
				OSSolverAgent solverAgent = new OSSolverAgent();
				solverAgent.solverAddress = jobStatistics.serviceURI; 
				if(solverAgent.solverAddress != null && solverAgent.solverAddress.length() > 0 && 
						!solverAgent.solverAddress.equals(OSParameter.OS_SCHEDULER_SITE) &&
						!solverAgent.solverAddress.equals(OSParameter.SERVICE_URI)){
					OSpLWriter osplWriter = new OSpLWriter();
					osplWriter.setRequestAction("getJobStatistics");
					osplWriter.setServiceName(OSParameter.SERVICE_NAME);
					osplWriter.setServiceURI(OSParameter.OS_SCHEDULER_SITE);
					osplWriter.setProcessTime(new GregorianCalendar());
					String sOSpLInput = osplWriter.writeToString();
		
					OSoLWriter osolWriter = new OSoLWriter();
					osolWriter.setServiceName(OSParameter.SERVICE_NAME);
					osolWriter.setServiceURI(OSParameter.OS_SCHEDULER_SITE);
					osolWriter.setJobID(m_sJobID);
					osolWriter.setPassword(m_sSystemPassword);
					String sOSoL = osolWriter.writeToString();

					try{
						sOSpLOutput = solverAgent.knock(sOSpLInput, sOSoL);					
					} 
					catch(Exception e){
						IOUtil.log(IOUtil.exceptionStackToString(e), null);
					}
					JobStatistics[] mJobStatistics = null;
					OSpLReader osplReader = new OSpLReader(OSParameter.VALIDATE);					
					try {
						osplReader.readString(sOSpLOutput);
						mJobStatistics = osplReader.getJobStatistics();					
					} 
					catch (Exception e) {
						IOUtil.log(IOUtil.exceptionStackToString(e), null);
					}
					if(mJobStatistics != null && mJobStatistics.length > 0){
						int iJobStatistics = mJobStatistics.length;
						for(int i = 0; i < iJobStatistics; i++){							
							if(mJobStatistics[i] == null) continue;
							String sJobID = mJobStatistics[i].jobID;
							if(sJobID == null || !sJobID.equals(m_sJobID)) continue;
							String sJobState = mJobStatistics[i].state;
							if(sJobState != null && (sJobState.equals("finished") || sJobState.equals("killed"))){
								jobStatistics.endTime = mJobStatistics[i].endTime;
								jobStatistics.startTime = mJobStatistics[i].startTime;
								jobStatistics.state = mJobStatistics[i].state;
								break;
							}							
						}
					}
				}
			}
			else{
				jobStatistics.endTime = new GregorianCalendar();				
			}
		}
		if(jobStatistics.startTime != null && jobStatistics.startTime.get(Calendar.YEAR) > 1970 &&
				jobStatistics.endTime != null && jobStatistics.endTime.get(Calendar.YEAR) > 1970){
			jobStatistics.duration = (jobStatistics.endTime.getTimeInMillis() - jobStatistics.startTime.getTimeInMillis())/1000.0;
		}		
		//save ospl
		saveOSpL();
		
		return sOSrL;
	}//retrieve

	/**
	 * Kill a previously sent/solved optimization job. 
	 * 
	 * @param osol holds the option in a string which format follows OSoL schema
	 * It should contain the jobID information that is previous obtained from the service.
	 * @return ospl, the kill process status of the kill operation. 
	 */
	@SuppressWarnings("deprecation")
	public String kill(String osol){
		if(osol == null) osol = "";
		String sOSpL = "";
		m_osplWriter = new OSpLWriter();
		m_osplWriter.setServiceName(OSParameter.SERVICE_NAME);
		m_osplWriter.setServiceURI(OSParameter.SERVICE_URI);
		m_osplWriter.setProcessTime(new GregorianCalendar());


		//read osol
		if(osol == null || osol.length() <= 0){
			m_osplWriter.setResponseStatus("error");
			m_osplWriter.setResponseDescription("No OSoL option specified");
			sOSpL = m_osplWriter.writeToString();
			return sOSpL;	
		}
		if(!readOSoL(osol)){
			m_osplWriter.setResponseStatus("error");
			m_osplWriter.setResponseDescription("Invalid OSoL option");
			sOSpL = m_osplWriter.writeToString();
			return sOSpL;
		}
		if(m_osOption == null) m_osOption = new OSOption();

		//check permission
		if(!OSParameter.REQUIRE_ONLY_JOB_ID_TO_KILL_JOB){
			try {
				if(!checkPermision()){
					m_osplWriter.setResponseStatus("error");
					m_osplWriter.setResponseDescription("Permission error.");
					sOSpL = m_osplWriter.writeToString();
					return sOSpL;
				}
			} 
			catch (Exception e) {
				IOUtil.log(e.getMessage(), null);
				m_osplWriter.setResponseStatus("error");
				m_osplWriter.setResponseDescription(e.getMessage());
				sOSpL = m_osplWriter.writeToString();
				return sOSpL;
			}
		}
		//may also need to check if the user name matches the job's user name
				
		//check jobID
		if(m_sJobID == null || m_sJobID.length() <= 0 ){
			m_osplWriter.setResponseStatus("error");
			m_osplWriter.setResponseDescription("no job id found");
			sOSpL = m_osplWriter.writeToString();
			return sOSpL;
		}

		//check if there is the job
		JobStatistics jobStatistics = m_jobStatisticsTable.get(m_sJobID);
		if(jobStatistics == null){
			m_osplWriter.setResponseStatus("success");
			m_osplWriter.setResponseDescription( m_sJobID+" is not there to kill");
			sOSpL = m_osplWriter.writeToString();
			return sOSpL;
		}
		
		//check if already finished or killed
		if(jobStatistics.state != null && (jobStatistics.state.equals("finished"))){
			m_osplWriter.setResponseStatus("success");
			m_osplWriter.setResponseDescription( m_sJobID+" is already finished");
			sOSpL = m_osplWriter.writeToString();
			return sOSpL;
		}
		if(jobStatistics.state != null && (jobStatistics.state.equals("killed"))){
			m_osplWriter.setResponseStatus("success");
			m_osplWriter.setResponseDescription( m_sJobID+" is already killed");
			sOSpL = m_osplWriter.writeToString();
			return sOSpL;
		}

		//kill
		OSServiceUtil osServiceUtil = new OSServiceUtil();
		osServiceUtil.m_sJobID = m_sJobID;
		
		String sError = "";
		//call specific solver's extra kill implemenation		
		if(solver != null){
			solver.osol = osol;
			solver.osOption = m_osOption;
			try {
				solver.kill();
			} 
			catch (Exception e) {
				String sException = IOUtil.exceptionStackToString(e);
				IOUtil.log(sException, null);
				sError += (sException + "\r\n\r\n");
			}
		}
		if(serviceType.equals("solver")  || serviceType.equals("analyzer")){
			Vector vProcess = (Vector)processsHashTable.get(m_sJobID);
			if(vProcess != null && vProcess.size() > 0){
				for(int i = 0; i < vProcess.size(); i++){
					try{
						Process process = (Process)vProcess.elementAt(i);
						process.destroy();
					}
					catch(Exception e){
						String sException = IOUtil.exceptionStackToString(e);
						IOUtil.log(sException, null);
						sError += (sException + "\r\n\r\n");
					}
				}
			}
			processsHashTable.remove(m_sJobID);
		}
		
		Thread thread = (Thread)m_threadHashTable.get(m_sJobID);
		if(thread != null){
			try{
				thread.stop();
			}
			catch(Exception e){
				String sException = IOUtil.exceptionStackToString(e);
				IOUtil.log(sException, null);
				sError += (sException + "\r\n\r\n");
			}
		}
		if(serviceType.equals("scheduler") && 
		   jobStatistics != null && 
		   jobStatistics.serviceURI != null && 
		   !jobStatistics.serviceURI.equals(OSParameter.OS_SCHEDULER_SITE)){
			
			OSSolverAgent solverAgent = new OSSolverAgent();
			solverAgent.solverAddress = jobStatistics.serviceURI; 
			if(solverAgent.solverAddress != null && solverAgent.solverAddress.length() > 0){
				try {
					String sKillOSpL = solverAgent.kill(osol);
					OSpLReader osplReader = new OSpLReader();
					boolean bRead = osplReader.readString(sKillOSpL);
					if(!bRead) throw new Exception("Invalid OSpL process string");
					String sStatus = osplReader.getResponseStatus();
					if(!sStatus.equals("success")){
						sError += (osplReader.getResponseDescription() + "\r\n" + osplReader.getProcessMessage() + "\r\n\r\n");
					}
				} 
				catch (Exception e) {
					IOUtil.log(IOUtil.exceptionStackToString(e), null);
				}
			}
		}
		else{//not scheduler 
			//postsolve
			String sOptionFile = OSParameter.TEMP_FILE_FOLDER+m_sJobID+".osol";
			String sOSoL = "";
			if(IOUtil.existsFileOrDir(sOptionFile)){
				sOSoL = IOUtil.readStringFromFile(sOptionFile);
				if(sOSoL != null && sOSoL.length() > 0){
					OSoLReader osolReader = new OSoLReader(m_bValidate);
					try {
						boolean bRead = osolReader.readString(sOSoL);
						if(bRead){
							osServiceUtil.readOSoL(sOSoL);
							osServiceUtil.postsolve();
						}
					} 
					catch (Exception e) {}
				}
				else{
					sOSoL = "";
				}
			}
		}
		
		//postprocess
		if(osServiceUtil.m_sJobID == null || osServiceUtil.m_sJobID.length() <= 0){
			osServiceUtil.m_sJobID = m_sJobID;
		}
		
		try{
			osServiceUtil.postprocess(true);  
		}
		catch(Exception e){
			String sException = IOUtil.exceptionStackToString(e);
			IOUtil.log(sException, null);
			sError += (sException + "\r\n\r\n");
		}
		if(sError.length() > 0){
			m_osplWriter.setResponseStatus("warning");
			m_osplWriter.setResponseDescription(m_sJobID + " is not killed completely");			
			m_osplWriter.setProcessMessage(sError);			
		}
		else{
			m_osplWriter.setResponseStatus("success");
			m_osplWriter.setResponseDescription( m_sJobID+" is killed successfully");
		}
		sOSpL = m_osplWriter.writeToString();
		return sOSpL;					
	}//kill
	
	/**
	 * Set (push) and/or get (pull) runtime dynamic process information to and/or from the service.
	 * 
	 * @param osplInput holds the input process information in a string which format follows OSpL schema.
	 * @param osol holds the option in a string which format follows OSoL schema
	 * @return osplOutput, the output process information in a string which format follows the OSpL schema.
	 */
	@SuppressWarnings("deprecation")
	public String knock(String osplInput, String osol){
		/*
		if(serviceType != null && serviceType.equals("scheduler")){
			IOUtil.log(m_userJobCountTable.toString(), null);
		}
		*/

		if(osplInput == null) osplInput = "";
		if(osol == null) osol = "";

		if(solver!=null  || serviceType == null || serviceType.equals("solver") || serviceType.equals("analyzer") || serviceType.equals("scheduler")){
			String sOSpLOutput = "";
			m_osplWriter = new OSpLWriter();
			m_osplWriter.setServiceName(OSParameter.SERVICE_NAME);
			m_osplWriter.setServiceURI(OSParameter.SERVICE_URI);
			m_osplWriter.setProcessTime(new GregorianCalendar());

			//read osol
			if(osol != null && osol.length() > 0){
				if(!readOSoL(osol)){
					m_osplWriter.setResponseStatus("error");
					m_osplWriter.setResponseDescription("Invalid OSoL option");
					sOSpLOutput = m_osplWriter.writeToString();
					return sOSpLOutput;
				}
			}
			if(m_osOption == null) m_osOption = new OSOption();

			//check permission
			try {
				if(!checkPermision()){
					m_osplWriter.setResponseStatus("error");
					m_osplWriter.setResponseDescription("Permission error.");
					sOSpLOutput = m_osplWriter.writeToString();
					return sOSpLOutput;
				}
			} 
			catch (Exception e) {
				IOUtil.log(e.getMessage(), null);
				m_osplWriter.setResponseStatus("error");
				m_osplWriter.setResponseDescription(e.getMessage());
				sOSpLOutput = m_osplWriter.writeToString();
				return sOSpLOutput;
			}

			//check ospl
			m_osplReader = new OSpLReader(m_bValidate);
			String sAction = "";
			String sRequestDescription = "";
			String sServiceName = "";
			String sServiceURI = "";
			GregorianCalendar processTime = new GregorianCalendar(1970, 0, 1, 1, 1, 1);
			String sProcessMessage = "";
			ProcessStatistics processStatistics = null;
			JobStatistics[] mJobStatistics = null;
			OptimizationProcess optimizationProcess = null;
					
			if(osplInput == null || osplInput.length() == 0){
				m_osplWriter.setResponseStatus("error");
				m_osplWriter.setResponseDescription("ospl string is empty");
				sOSpLOutput = m_osplWriter.writeToString();
				return sOSpLOutput;
			}
			else{
				try {
					boolean bRead = m_osplReader.readString(osplInput);
					if(!bRead){
						m_osplWriter.setResponseStatus("error");
						m_osplWriter.setResponseDescription("Invalid OSpL process input");
						sOSpLOutput = m_osplWriter.writeToString();	
						return sOSpLOutput;
					}
					sAction = m_osplReader.getRequestAction();
					if((sAction == null || sAction.length() <= 0)){
						m_osplWriter.setResponseStatus("error");
						m_osplWriter.setResponseDescription("no request action specified in ospl");
						sOSpLOutput = m_osplWriter.writeToString();
						return sOSpLOutput;
					}
					else if(!sAction.equals("ping") &&
						    !sAction.equals("notifyJobCompletion") &&
						    !sAction.equals("requestJob") &&
						    !sAction.equals("getServiceStatistics") &&
						    !sAction.equals("setServiceStatistics") &&
						    !sAction.equals("getJobStatistics") &&
						    !sAction.equals("setJobStatistics") &&
						    !sAction.equals("getOptimization") &&
						    !sAction.equals("setOptimization") &&
						    !sAction.equals("getAll") &&
						    !sAction.equals("setAll")){
						m_osplWriter.setResponseStatus("error");
						m_osplWriter.setResponseDescription("request action specified in ospl has to one of the following values: " +
								"ping, notifyJobCompletion, requestJob, " +
								"getServiceStatistics, setServiceStatistics, " +
								"getJobStatistics, setJobStatistics, getOptimization, setOptimization, getAll, setAll");
						sOSpLOutput = m_osplWriter.writeToString();
						return sOSpLOutput;
					}
					sRequestDescription = m_osplReader.getRequestAction();
					sServiceName = m_osplReader.getServiceName();
					sServiceURI = m_osplReader.getServiceURI();
					processTime = m_osplReader.getProcessTime();
					sProcessMessage = m_osplReader.getProcessMessage();
					processStatistics = m_osplReader.getProcessStatistics();
					mJobStatistics = (processStatistics==null || processStatistics.jobs==null)?null:processStatistics.jobs.job;
					optimizationProcess = m_osplReader.getOptimizationProcess();
				}
				catch (Exception e) {
					IOUtil.log(IOUtil.exceptionStackToString(e), null);
					m_osplWriter.setResponseStatus("error");
					m_osplWriter.setResponseDescription(e.getMessage());
					m_osplWriter.setProcessMessage(IOUtil.exceptionStackToString(e));
					sOSpLOutput = m_osplWriter.writeToString();
					return sOSpLOutput;
				}
			}
			if(sAction.equals("ping")){
				m_osplWriter.setResponseStatus("success");
				m_osplWriter.setResponseDescription("The service is alive");
				sOSpLOutput = m_osplWriter.writeToString();
				return sOSpLOutput;
			}//ping
			if(sAction.equals("notifyJobCompletion")){ 
				if((m_sJobID == null || m_sJobID.length() <= 0) && 
						(mJobStatistics==null || mJobStatistics.length <= 0)){
					m_osplWriter.setResponseStatus("error");
					m_osplWriter.setResponseDescription("No job id is provided.");
					sOSpLOutput = m_osplWriter.writeToString();
					return sOSpLOutput;
				}
				if((m_sJobID == null || m_sJobID.length() <= 0) && (mJobStatistics != null && mJobStatistics.length >0)){
					m_sJobID = mJobStatistics[0].jobID;
				}
				if(m_sServiceURIInOSoL != null && m_sServiceURIInOSoL.length() > 0){
					sServiceURI = m_sServiceURIInOSoL;
				}
				if(sServiceURI == null || sServiceURI.length() <= 0){
					JobStatistics jobStatistics = m_jobStatisticsTable.get(m_sJobID);
					if(jobStatistics != null){
						sServiceURI = jobStatistics.serviceURI;	
					}
				}
				if(sServiceURI == null || sServiceURI.length() <= 0){
					m_osplWriter.setResponseStatus("error");
					m_osplWriter.setResponseDescription("No service URI is provided.");
					sOSpLOutput = m_osplWriter.writeToString();
					return sOSpLOutput;
				}
				String sWarningDescription = "";
				String sWarningMessage = "";
				if(serviceType.equals("scheduler") && 
						!sServiceURI.equals(OSParameter.OS_REGISTRY_SITE) &&
						!sServiceURI.equals(OSParameter.OS_SCHEDULER_SITE)){
					//retrieve job from solvers if it is scheduler as it is the client of solvers. 
					//no need to retrieve job if it is solver as a solver never sends jobs. 
					try{
						m_osolWriter = new OSoLWriter();
						m_osolWriter.setServiceName(OSParameter.SERVICE_NAME);
						m_osolWriter.setServiceURI(OSParameter.SERVICE_URI);
						m_osolWriter.setJobID(m_sJobID);
						m_osolWriter.setPassword(m_sSystemPassword);
						m_osolWriter.setServiceType("scheduler");
						String sOSoLInput = m_osolWriter.writeToString();					
						
						RetrieveThread retrieveThread = new RetrieveThread();
						OSSolverAgent osSolverAgent = new OSSolverAgent(sServiceURI);
						retrieveThread.m_osSolverAgent = osSolverAgent;
						retrieveThread.m_sOSoL = sOSoLInput;
						String sResultFile = OSParameter.TEMP_FILE_FOLDER+m_sJobID+".osrl";
						retrieveThread.m_sResultFile = sResultFile;
						
						Thread thread = new Thread(retrieveThread);
						thread.start();
					}	
					catch (Exception e){
						IOUtil.log(IOUtil.exceptionStackToString(e),null);
						sWarningDescription = "The service has got the notification. But there are some exceptions. See the message part.";
						sWarningMessage += (IOUtil.exceptionStackToString(e)+"\r\n"); 
					}
					//notify the client of the scheduler
					String sOSoL = "";
					try {
						sOSoL = IOUtil.readStringFromFile(OSParameter.TEMP_FILE_FOLDER+m_sJobID+".osol");			
					} 
					catch (Exception e){
					}
					if(sOSoL == null){
						sOSoL = "";
					}
					if(sOSoL != null && sOSoL.length() > 0){
						try {
							OSoLReader osolReader = new OSoLReader();
							boolean bRead = osolReader.readString(sOSoL);
							if(!bRead) throw new Exception("Invalid OSoL option");
							String sContactTransportType = osolReader.getContactTransportType();
							String sContactAddress = osolReader.getContactAddress();								
							if(sContactAddress != null && sContactAddress.length() > 0 && 
							   !sContactAddress.equals(OSParameter.OS_SCHEDULER_SITE)){
								if(sContactTransportType == null || sContactTransportType.length() <= 0){
									sContactTransportType = "osp";
								}
								String sMessage = "Your job " + m_sJobID + " has completed on " + (OSParameter.SERVICE_URI);
								try {
									if(sContactTransportType.equals("smtp")){
										MailUtil.sendInThread(OSParameter.FROM_EMAIL, sContactAddress, null, null, "notifyJobCompletion", sMessage, null);
									}
									if(sContactTransportType.equals("osp")){
										m_osplWriter = new OSpLWriter();
										m_osplWriter.setRequestAction("notifyJobCompletion");
										m_osplWriter.setServiceURI(OSParameter.SERVICE_URI);
										m_osplWriter.setServiceName(OSParameter.SERVICE_NAME);
										m_osplWriter.setProcessTime(new GregorianCalendar());
										m_osplWriter.setProcessMessage(sMessage);
										m_osplWriter.setJobStatistics(mJobStatistics);
										String sProcessInput = m_osplWriter.writeToString();

										m_osolWriter = new OSoLWriter();
										m_osolWriter.setServiceURI(OSParameter.SERVICE_URI);
										m_osolWriter.setServiceName(OSParameter.SERVICE_NAME);
										m_osolWriter.setJobID(m_sJobID);
										m_osolWriter.setLicense(m_sLicense);
										m_osolWriter.setUserName(m_sUserName);
										m_osolWriter.setPassword(OSParameter.getSystemPassword());
										String sServiceType = serviceType;
										m_osolWriter.setServiceType(sServiceType);
										String sOption = m_osolWriter.writeToString();
										
										KnockSolverThread knockSolverThread = new KnockSolverThread();
										OSSolverAgent osSolverAgent = new OSSolverAgent(sContactAddress);
										knockSolverThread.m_osSolverAgent = osSolverAgent;
										knockSolverThread.m_osplInput = sProcessInput;
										knockSolverThread.m_osol = sOption;
															
										Thread thread = new Thread(knockSolverThread);
										thread.start();
									}
								} 
								catch (Exception e) {
									IOUtil.log(IOUtil.exceptionStackToString(e), null);
								}
							}
						} 
						catch (Exception e) {
							IOUtil.log(IOUtil.exceptionStackToString(e), null);
						}
					}
				}//if scheduler
				//set job statistics
				try{
					int iJobs = mJobStatistics==null?0:mJobStatistics.length;
					for(int i = 0; i < iJobs; i++){
						if(mJobStatistics[i] != null && 
						   mJobStatistics[i].jobID != null && mJobStatistics[i].jobID.length() > 0 && 
						   mJobStatistics[i].state != null && 
						  (mJobStatistics[i].state.equals("killed") || mJobStatistics[i].state.equals("finished"))){
							Thread thread = (Thread)m_threadHashTable.get(mJobStatistics[i].jobID);
							if(thread != null){
								try{
									thread.stop();
								}
								catch(Exception e){
									IOUtil.log(IOUtil.exceptionStackToString(e), null);
								}
							}

							if(m_vWaitingJobIDs.contains(mJobStatistics[i].jobID) || m_vCurrentJobIDs.contains(mJobStatistics[i].jobID)){
								String sUserName = mJobStatistics[i].userName;
								if(sUserName == null) sUserName = "";
								String sCount = m_userJobCountTable.get(sUserName);
								int iCount;
								if(sCount == null || sCount.length() <= 0){
									iCount = 0;
								}
								else{
									try {
										iCount = Integer.parseInt(sCount);					
									} 
									catch (Exception e) {
										iCount = 0;
									}
									if(iCount <= 0){
										iCount = 0;
									}
									else{
										iCount -= 1;
									}
								}
								m_userJobCountTable.remove(sUserName);
								m_userJobCountTable.put(sUserName, iCount+"");
							}
							
							m_solverThreadHashTable.remove(mJobStatistics[i].jobID);
							m_threadHashTable.remove(mJobStatistics[i].jobID);							
							m_vCurrentJobIDs.remove(mJobStatistics[i].jobID);
							m_vWaitingJobIDs.remove(mJobStatistics[i].jobID);
							m_vFinishedJobIDs.remove(mJobStatistics[i].jobID);
							m_vFinishedJobIDs.add(mJobStatistics[i].jobID);	
							m_iCurrentJobCount = m_vCurrentJobIDs.size();
							
							JobStatistics jobStatistics = m_jobStatisticsTable.get(mJobStatistics[i].jobID);
							if(jobStatistics == null){
								m_jobStatisticsTable.put(mJobStatistics[i].jobID, mJobStatistics[i]);
							}
							else{
								jobStatistics.jobID = mJobStatistics[i].jobID;
								if(mJobStatistics[i].state != null && (mJobStatistics[i].state.equals("finished") || mJobStatistics[i].state.equals("killed"))){
									jobStatistics.state = mJobStatistics[i].state;												
								}
								if(mJobStatistics[i].endTime != null && mJobStatistics[i].endTime.get(Calendar.YEAR) > 1970){
									jobStatistics.endTime = mJobStatistics[i].endTime;
									long lJobEndTime = jobStatistics.endTime.getTimeInMillis();
									if(lJobEndTime > m_lTimeLastJobEnded){
										m_lTimeLastJobEnded = lJobEndTime;
									}
								}
								if(mJobStatistics[i].startTime != null && mJobStatistics[i].startTime.get(Calendar.YEAR) > 1970){
									jobStatistics.startTime = mJobStatistics[i].startTime;
								}
								if(!Double.isNaN(mJobStatistics[i].duration) && mJobStatistics[i].duration >= 0){
									jobStatistics.duration = mJobStatistics[i].duration;
								}
								if(mJobStatistics[i].endTime != null && mJobStatistics[i].endTime.get(Calendar.YEAR) > 1970 &&
								   mJobStatistics[i].startTime != null && mJobStatistics[i].startTime.get(Calendar.YEAR) > 1970	){
									jobStatistics.duration = (mJobStatistics[i].endTime.getTimeInMillis() - mJobStatistics[i].startTime.getTimeInMillis())/1000.0;
								}
								if(jobStatistics.serviceURI != null &&  jobStatistics.serviceURI.length() > 0){
									jobStatistics.serviceURI = mJobStatistics[i].serviceURI;
								}
								if((jobStatistics.serviceURI == null ||  jobStatistics.serviceURI.length() <= 0) && !sServiceURI.equals(OSParameter.OS_SCHEDULER_SITE)){
									jobStatistics.serviceURI = sServiceURI;
								}
								if(jobStatistics.serviceURI != null && jobStatistics.serviceURI.equals(OSParameter.OS_SCHEDULER_SITE)){
									jobStatistics.serviceURI = "";
								}									
								if(jobStatistics.userName == null || jobStatistics.userName.length() <= 0){
									jobStatistics.userName = mJobStatistics[i].userName;
								}
								if(jobStatistics.submitTime == null || jobStatistics.submitTime.get(Calendar.YEAR) <= 1970){
									jobStatistics.submitTime = mJobStatistics[i].submitTime;
								}
								if(jobStatistics.scheduledStartTime == null || jobStatistics.scheduledStartTime.get(Calendar.YEAR) <= 1970){
									jobStatistics.scheduledStartTime = mJobStatistics[i].scheduledStartTime;
								}
								if(jobStatistics.dependencies == null || jobStatistics.dependencies.jobID == null || jobStatistics.dependencies.jobID.length <= 0){
									jobStatistics.dependencies = mJobStatistics[i].dependencies;
								}
								if(jobStatistics.requiredDirectoriesAndFiles == null || jobStatistics.requiredDirectoriesAndFiles.path == null || jobStatistics.requiredDirectoriesAndFiles.path.length <= 0){
									jobStatistics.requiredDirectoriesAndFiles = mJobStatistics[i].requiredDirectoriesAndFiles;
								}
							}
						}
					}
					Thread thread1 = (Thread)m_threadHashTable.get(m_sJobID);
					if(thread1 != null){
						try{
							thread1.stop();
						}
						catch(Exception e){
							IOUtil.log(IOUtil.exceptionStackToString(e), null);
						}
					}

					JobStatistics jobStatistics1  = m_jobStatisticsTable.get(m_sJobID);		
					if(jobStatistics1 == null){
						jobStatistics1 = new JobStatistics();						
						jobStatistics1.jobID = m_sJobID;
						m_jobStatisticsTable.put(m_sJobID, jobStatistics1);
					}
					
					if(jobStatistics1.userName == null || jobStatistics1.userName.length() <= 0){
						jobStatistics1.userName = m_sUserName;
					}
					String sUserName1 = jobStatistics1.userName;
					if(sUserName1 == null) sUserName1 = "";
					String sCount1 = m_userJobCountTable.get(sUserName1);
					int iCount1;
					if(sCount1 == null || sCount1.length() <= 0){
						iCount1 = 0;
					}
					else{
						try {
							iCount1 = Integer.parseInt(sCount1);					
						} 
						catch (Exception e) {
							iCount1 = 0;
						}
						if(iCount1 <= 0){
							iCount1 = 0;
						}
						else if(m_vWaitingJobIDs.contains(m_sJobID) || m_vCurrentJobIDs.contains(m_sJobID)){
							iCount1 -= 1;
						}
					}
					m_userJobCountTable.remove(sUserName1);
					m_userJobCountTable.put(sUserName1, iCount1+"");
					
					m_solverThreadHashTable.remove(m_sJobID);
					m_threadHashTable.remove(m_sJobID);
					m_vCurrentJobIDs.remove(m_sJobID);
					m_vWaitingJobIDs.remove(m_sJobID);
					m_vFinishedJobIDs.remove(m_sJobID);
					m_vFinishedJobIDs.add(m_sJobID);
					
					jobStatistics1.jobID = m_sJobID;
					if((jobStatistics1.serviceURI == null ||  jobStatistics1.serviceURI.length() <= 0) && !sServiceURI.equals(OSParameter.OS_SCHEDULER_SITE)){
						jobStatistics1.serviceURI = sServiceURI;
					}
					if(jobStatistics1.serviceURI != null && jobStatistics1.serviceURI.equals(OSParameter.OS_SCHEDULER_SITE)){
						jobStatistics1.serviceURI = "";
					}
					if(jobStatistics1.state == null || (!jobStatistics1.state.equals("finished") && !jobStatistics1.state.equals("killed"))){
						jobStatistics1.state = "finished";			
					}
					if(jobStatistics1.endTime == null || jobStatistics1.endTime.get(Calendar.YEAR) <= 1970){
						jobStatistics1.endTime = new GregorianCalendar();
						if(jobStatistics1.startTime != null && jobStatistics1.startTime.get(Calendar.YEAR) > 1970){
							jobStatistics1.duration = (jobStatistics1.endTime.getTimeInMillis() - jobStatistics1.startTime.getTimeInMillis())/1000.0;
						}
					}
					else{
						long lJobEndTime = jobStatistics1.endTime.getTimeInMillis();
						if(lJobEndTime > m_lTimeLastJobEnded){
							m_lTimeLastJobEnded = lJobEndTime;
						}
					}
					if(jobStatistics1.userName == null || jobStatistics1.userName.length() <= 0){
						jobStatistics1.userName = m_sUserName;
					}
				}
				catch(Exception e){
					IOUtil.log(IOUtil.exceptionStackToString(e), null);
					sWarningDescription = "The service has got the notification. But there are some exceptions. See the message part.";
					sWarningMessage += (IOUtil.exceptionStackToString(e)+"\r\n"); 
				}
				//save ospl
				saveOSpL();
				
				//prepare result
				if(sWarningDescription.length() <= 0){
					m_osplWriter.setResponseStatus("success");
					m_osplWriter.setResponseDescription("The service has successfully processed the notification.");
				}
				else{
					m_osplWriter.setResponseStatus("warning");	
					m_osplWriter.setResponseDescription(sWarningDescription);
					m_osplWriter.setProcessMessage(sWarningMessage);
				}
				sOSpLOutput = m_osplWriter.writeToString();
				return sOSpLOutput;
			}//notifyJobCompletion
			if(sAction.equals("requestJob")){
				if(serviceType != null && serviceType.equals("scheduler")){
					if(m_sServiceURIInOSoL != null && m_sServiceURIInOSoL.length() > 0){
						sServiceURI = m_sServiceURIInOSoL;
					}
					if(sServiceURI == null || sServiceURI.length() <= 0){
						m_osplWriter.setResponseStatus("warning");
						m_osplWriter.setResponseDescription("No service URI is provided.");
						sOSpLOutput = m_osplWriter.writeToString();				
						return sOSpLOutput;
					}
					//process waiting jobs				
					try {
						int iWaitingJobs = (m_vWaitingJobIDs==null?0:m_vWaitingJobIDs.size());
						if(iWaitingJobs > 0){
							ProcessJobRequestThread processJobRequestThread = new ProcessJobRequestThread();	
							acceptingSolverURIs.remove(sServiceURI);
							processJobRequestThread.m_sRequestingServiceURI = sServiceURI;	
							Thread thread = new Thread(processJobRequestThread);	
							thread.start();			
						}
						m_osplWriter.setResponseStatus("success");
						m_osplWriter.setResponseDescription("Job request notification is processed.");
						sOSpLOutput = m_osplWriter.writeToString();
						return sOSpLOutput;	
					} 
					catch (Exception e) {
						IOUtil.log(IOUtil.exceptionStackToString(e), null);
						m_osplWriter.setResponseStatus("error");
						m_osplWriter.setResponseDescription("Job request notification is received but there is some error in processing.");
						m_osplWriter.setProcessMessage(IOUtil.exceptionStackToString(e));
						sOSpLOutput = m_osplWriter.writeToString();
						return sOSpLOutput;	
					}				
				}
				else{
					m_osplWriter.setResponseStatus("warning");
					m_osplWriter.setResponseDescription("The solver service does not take job request.");
					sOSpLOutput = m_osplWriter.writeToString();
					return sOSpLOutput;			
				}
			}//requestJob
			if(sAction.equals("getServiceStatistics")|| sAction.equals("getAll")){
				try{
					m_iCurrentJobCount = m_vCurrentJobIDs.size();
					try{
						m_dAvailableDiskSpace = IOUtil.getFreeDiskSpace(OSParameter.CODE_DRIVE);	
					}
					catch(Exception e){
						IOUtil.log(IOUtil.exceptionStackToString(e), null);
						m_dAvailableDiskSpace = Double.POSITIVE_INFINITY;
					}
					try{
						m_dAvailableMemory = ProcessUtil.getFreeMemory();	
					}
					catch(Exception e){
						IOUtil.log(IOUtil.exceptionStackToString(e), null);
						m_dAvailableMemory = Double.POSITIVE_INFINITY;
					}
					if(m_dAvailableDiskSpace <= OSParameter.MINIMUM_DISKSPACE_TRIGGER ||
					   m_dAvailableMemory <= ((double)OSParameter.MINIMUM_MEMORY_TRIGGER)){
						if(m_iCurrentJobCount > 0){
							m_sCurrentState = "busy";				
						}
						else{
							m_sCurrentState = "idleButNotAccepting";
						}
					}
					else{
						if(m_iCurrentJobCount == 0){
							m_sCurrentState = "idle";
						}
						else if(m_iCurrentJobCount >= OSParameter.MAX_JOB_NUMBERS){
							m_sCurrentState = "busy";
						}
						else{
							m_sCurrentState = "busyButAccepting";
						}
					}
					m_osplWriter.setCurrentState(m_sCurrentState);
					m_osplWriter.setAvailableDiskSpace(m_dAvailableDiskSpace);
					m_osplWriter.setAvailableMemory(m_dAvailableMemory);
					m_osplWriter.setCurrentJobCount(m_iCurrentJobCount);
					m_osplWriter.setTotalJobsSoFar(m_iTotalJobsSoFar);
					m_osplWriter.setTimeLastJobEnded(CommonUtil.createNativeDateTime(m_lTimeLastJobEnded));
					if(m_lLastJobTook < 0){
						m_osplWriter.setTimeLastJobTook(-1);					
					}
					else{
						m_osplWriter.setTimeLastJobTook((double)(m_lLastJobTook/1000.0));
					}
					m_osplWriter.setTimeServiceStarted(CommonUtil.createNativeDateTime(m_lTimeServiceStarted));
					m_osplWriter.setServiceUtilization(m_dServiceUtilization);
					
					String sCurrentJobIDs = "";
					int iCurrentJobIDs = m_vCurrentJobIDs.size();
					String[] msCurrentJobIDs = new String[iCurrentJobIDs];
					for(int i = iCurrentJobIDs-1; i >= 0; i--){
						try{
							msCurrentJobIDs[i] = (String)m_vCurrentJobIDs.elementAt(i);							
						}
						catch(Exception e){
							msCurrentJobIDs[i] = "";
						}
					}
					
					if(iCurrentJobIDs > 0){
						if(msCurrentJobIDs[0] != null && msCurrentJobIDs[0].length() > 0){
							sCurrentJobIDs += msCurrentJobIDs[0];							
						}
					}
					for(int i = 1; i < iCurrentJobIDs; i++){
						if(msCurrentJobIDs[i] != null && msCurrentJobIDs[i].length() > 0){
							sCurrentJobIDs += "\r\n";
							sCurrentJobIDs += msCurrentJobIDs[i];							
						}
					}
					if(sCurrentJobIDs != null && sCurrentJobIDs.length() > 0){
						m_osplWriter.addOtherProcess("currentJobIDs", sCurrentJobIDs, "jobs that are currently running");
					}
					
					Enumeration enumeration = processsHashTable.keys();
					String sProcesses = "";
					while(enumeration.hasMoreElements()){
						try{
							String sJobID = (String)enumeration.nextElement();
							if(sJobID == null || sJobID.length() <= 0){
								continue;
							}
							Vector<Process> vProcess = (Vector<Process>)processsHashTable.get(sJobID);
							int iProcess = vProcess==null?0:vProcess.size();
							for(int i = 0; i < iProcess; i++){
								sProcesses += ("process " + i + ": " + "launched by " + sJobID + "\n\r");				
							}							
						}
						catch(Exception e){							
						}
					}
					if(sProcesses.length() > 0){
						m_osplWriter.addOtherProcess("processes", sProcesses, "processes launched by the current jobs");					
					}
					
					//save ospl
					saveOSpL();
					
					if(!sAction.equals("getAll")){
						m_osplWriter.setResponseStatus("success");					
						m_osplWriter.setResponseDescription("The service statistics has been obtained. (No Job Statistics are included. To get job statistics, use action \"getJobStatistics\")");
						sOSpLOutput = m_osplWriter.writeToString();
						return sOSpLOutput;			
					}
				}
				catch(Exception e){
					IOUtil.log(IOUtil.exceptionStackToString(e), null);
					m_osplWriter.setResponseStatus("warning");				
					m_osplWriter.setResponseDescription(e.getMessage() + " (No Job Statistics are included. To get job statistics, use action \"getJobStatistics\")");
					m_osplWriter.setProcessMessage(IOUtil.exceptionStackToString(e));
					sOSpLOutput = m_osplWriter.writeToString();
					return sOSpLOutput;								
				}
			}//getServiceStatistics
			if(sAction.equals("setServiceStatistics")){
				m_osplWriter.setResponseStatus("warning");
				m_osplWriter.setResponseDescription("The service does not allow setting service statistics externally.");
				sOSpLOutput = m_osplWriter.writeToString();
				return sOSpLOutput;			
			}//setServiceStatistics
			if(sAction.equals("getJobStatistics") || sAction.equals("getAll")){
				JobStatistics[] mAllJobStatistics = null;
				try{					
					if(m_sJobID != null && m_sJobID.length() > 0){
						JobStatistics jobStatistics = m_jobStatisticsTable.get(m_sJobID);
						if(jobStatistics != null){
							mAllJobStatistics = new JobStatistics[1];
							mAllJobStatistics[0] = jobStatistics;
							m_osplWriter.setJobStatistics(mAllJobStatistics);
						}
					}
					else{
						int iCurrentJobs = m_vCurrentJobIDs.size();
						int iWaitingJobs = m_vWaitingJobIDs.size();
						int iFinishedJobs = m_vFinishedJobIDs.size();
						
						int iJobs =  iCurrentJobs + iWaitingJobs + iFinishedJobs;
						mAllJobStatistics = new JobStatistics[iJobs];
						int j = 0;
						for(int i = iCurrentJobs-1; i >= 0 ; i--){
							try{
								mAllJobStatistics[j] = (JobStatistics)m_jobStatisticsTable.get(m_vCurrentJobIDs.elementAt(i));
								j++;
							}
							catch(Exception e){
							}
						}
						for(int i = iWaitingJobs-1; i >= 0 ; i--){
							try{
								mAllJobStatistics[j] = (JobStatistics)m_jobStatisticsTable.get(m_vWaitingJobIDs.elementAt(i));
								j++;
							}
							catch(Exception e){
							}
						}
						for(int i = iFinishedJobs-1; i >= 0 ; i--){
							try{
								mAllJobStatistics[j] = (JobStatistics)m_jobStatisticsTable.get(m_vFinishedJobIDs.elementAt(i));
								j++;
							}
							catch(Exception e){
							}
						}
						if(iJobs > 0){
							m_osplWriter.setJobStatistics(mAllJobStatistics);
						}
					}
					if(!sAction.equals("getAll")){
						if(mAllJobStatistics == null || mAllJobStatistics.length <= 0){
							m_osplWriter.setResponseStatus("warning");					
							m_osplWriter.setResponseDescription("No job statistics has been obtained.");
						}
						else{
							m_osplWriter.setResponseStatus("success");					
							m_osplWriter.setResponseDescription("The job statistics has been obtained.");							
						}
						sOSpLOutput = m_osplWriter.writeToString();
						return sOSpLOutput;	
					}
				}
				catch(Exception e){
					IOUtil.log(IOUtil.exceptionStackToString(e), null);
					m_osplWriter.setResponseStatus("warning");				
					m_osplWriter.setResponseDescription(e.getMessage());
					m_osplWriter.setProcessMessage(IOUtil.exceptionStackToString(e));
					sOSpLOutput = m_osplWriter.writeToString();
					return sOSpLOutput;			
				}
			}//getJobStatistics
			if(sAction.equals("setJobStatistics")){
				m_osplWriter.setResponseStatus("warning");
				m_osplWriter.setResponseDescription("The service does not allow setting job statistics externally.");
				sOSpLOutput = m_osplWriter.writeToString();
				return sOSpLOutput;			
			}//setJobStatistics
			if(sAction.equals("getOptimization") || sAction.equals("getAll")){
				if(!sAction.equals("getAll")){
					m_osplWriter.setResponseStatus("warning");
					m_osplWriter.setResponseDescription("Getting optimization information is not implemented.");
					sOSpLOutput = m_osplWriter.writeToString();
					return sOSpLOutput;
				}
			}//getOptimization
			if(sAction.equals("setOptimization") || sAction.equals("setAll")){
				if(!sAction.equals("setAll")){
					m_osplWriter.setResponseStatus("warning");
					m_osplWriter.setResponseDescription("Setting optimization information is not implemented.");
					sOSpLOutput = m_osplWriter.writeToString();
					return sOSpLOutput;
				}
			}//setOptimization
			if(sAction.equals("getAll")){
				m_osplWriter.setResponseStatus("success");					
				m_osplWriter.setResponseDescription("All the information has been obtained.");
				sOSpLOutput = m_osplWriter.writeToString();
				return sOSpLOutput;	
			}//getAll
			if(sAction.equals("setAll")){
				m_osplWriter.setResponseStatus("success");					
				m_osplWriter.setResponseDescription("All the information has been set.");
				sOSpLOutput = m_osplWriter.writeToString();
				return sOSpLOutput;	
			}//setAll
			m_osplWriter.setResponseStatus("error");
			m_osplWriter.setResponseDescription("Request action is not recognized.");
			sOSpLOutput = m_osplWriter.writeToString();
			return sOSpLOutput;				
		}
		else if(registry!=null || serviceType.equals("registry")){
			String sOSpLOutput = "";
			//log
			Calendar calendar = new GregorianCalendar();
			String sTime = ((calendar.get(Calendar.MONTH)+1) + "." + 
					   calendar.get(Calendar.DAY_OF_MONTH) + "." +
					   calendar.get(Calendar.YEAR) + "." + 
					   calendar.get(Calendar.DAY_OF_WEEK) + "." + 
					   calendar.get(Calendar.HOUR_OF_DAY) + "." + 
					   calendar.get(Calendar.MINUTE) + "." + 
					   calendar.get(Calendar.SECOND) + "." + 
					   calendar.get(Calendar.MILLISECOND)  + OSConstant.JODID_DELIMITER);

			IOUtil.log("knock:"+sTime, OSParameter.REGISTRY_LOG_FILE);
			//set input
			registry.serviceName = serviceName;
			registry.serviceURI = serviceURI;
			registry.serviceType = "registry";
			try{
				registry.osplKnockInput = osplInput;
			}
			catch(Exception e){
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
			try{
				registry.osolKnock = osol;
			}
			catch(Exception e){
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}

			//knock
			try{
				registry.knock();
			}
			catch(Exception e){
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}

			//get output
			try{
				sOSpLOutput = registry.osplKnockOutput;
			}
			catch(Exception e){
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
			return sOSpLOutput;
		}
		else{
			String sOSpLOutput = "";
			IOUtil.log("no service engine (e.g. solver, registry) found", null);
			m_osplWriter = new OSpLWriter();
			m_osplWriter.setResponseStatus("error");
			m_osplWriter.setResponseDescription("no service engine (e.g. solver, scheduler, registry) found");
			sOSpLOutput = m_osplWriter.writeToString();
			return sOSpLOutput;
		}
	}//knock 
	
	/**
	 * Discover an Optimization Service whose instance is given by a string following 
	 * the Optimization Services query Language (OSqL) schema and returns the location information
	 * in a string that follows the Optimization Services URI, or Universal Resource Indentifier 
	 * Language, (OSuL) schema.
	 * 
	 * </P>
	 *
	 * @param OSqL holds the Optimization Service query in a string which format follows the 
	 * Optimization Services query Language (OSqL) schema.  
	 * @param osol holds the optimization option in a string which format follows the 
	 * Optimization Services option Language (OSoL) schema.    
	 * @return the location information in a string that follows the Optimization Services URI, 
	 * or Universal Resource Indentifier Language, (OSuL) schema.
	 */
	public String find(String osql, String osol){
		if(osql == null) osql = "";
		if(osol == null) osol = "";

		String sOSuL = "";
		//log
		String sTime = XMLUtil.createXSDateTime(new GregorianCalendar());
		IOUtil.log("find:"+sTime, OSParameter.REGISTRY_LOG_FILE);
		//set input
		registry.serviceName = serviceName;
		registry.serviceURI = serviceURI;
		registry.serviceType = "registry";			
		try{
			registry.osql = osql;
		}
		catch(Exception e){
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
		}
		try{
			registry.osolFind = osol;
		}
		catch(Exception e){
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
		}

		//find
		try{
			registry.find();
		}
		catch(Exception e){
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
		}
		//get output
		try{
			sOSuL = registry.osul;
		}
		catch(Exception e){
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
		}
		return sOSuL;
	}//find
	
	/**
	 * register an Optimization Service whose instance is given by a string following 
	 * the Optimization Services entity Language (OSeL) schema and returns a string that contains 
	 * an XSLT style sheet transformation so that it can be used for standard web pubblication of the 
	 * Optimization Service that just joined. The XSLT is espcially used to publish the OSeL. 
	 * 
	 * </P>
	 * 
	 * @param osel holds the Optimization Service entity description in a string which format follows the 
	 * Optimization Services entity Language (OSeL) schema.  
	 * @param osol holds the optimization option in a string which format follows the 
	 * Optimization Services option Language (OSoL) schema.    
	 * @return the register process output information in a string which format follows the OSpL schema.
	 */
	public String register(String osel, String osol){
		if(osel == null) osel = "";
		if(osol == null) osol = "";

		String sOSpLOutput = "";
		//log
		String sTime = XMLUtil.createXSDateTime(new GregorianCalendar());
		IOUtil.log("register:"+sTime, OSParameter.REGISTRY_LOG_FILE);
		//set input
		registry.serviceName = serviceName;
		registry.serviceURI = serviceURI;
		registry.serviceType = "registry";			
		try{
			registry.osel = osel;
		}
		catch(Exception e){
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
		}
		try{
			registry.osolRegister = osol;
		}
		catch(Exception e){
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
		}
		//register
		try{
			registry.register();
		}
		catch(Exception e){
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
		}
		//get output
		try{
			sOSpLOutput = registry.osplRegisterOutput;
		}
		catch(Exception e){
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
		}
		return sOSpLOutput;
	}//register

	/**
	 * Validate an osxl string according to the corresponding OSxL schema.
	 *
	 * </P>
	 *
	 * @param osxl holds the xml string to be validated. 
	 * @param osol holds the optimization option in a string which format follows the 
	 * Optimization Services option Language (OSoL) schema.    
	 * @return the validate process output information in a string which format follows the OSpL schema.
	 */	
	public String validate(String osxl, String osol){
		if(osxl == null) osxl = "";
		if(osol == null) osol = "";

		String sOSpLOutput = "";
		//log
		String sTime = XMLUtil.createXSDateTime(new GregorianCalendar());

		IOUtil.log("validate:"+sTime, OSParameter.REGISTRY_LOG_FILE);
		//set input
		registry.serviceName = serviceName;
		registry.serviceURI = serviceURI;
		registry.serviceType = "registry";			
		try{
			registry.osxl = osxl;
		}
		catch(Exception e){
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
		}
		try{
			registry.osolValidate = osol;
		}
		catch(Exception e){
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
		}
		//validate
		try{
			registry.validate();
		}
		catch(Exception e){
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
		}
		//get output
		try{
			sOSpLOutput = registry.osplValidateOutput;
		}
		catch(Exception e){
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
		}
		return sOSpLOutput;
	}//validate

	/**
	 * Call a simulation service whose input is given by a string following 
	 * the Optimization Services simulation Language (OSsL) schema and returns the result
	 * in a string that follows the Optimization Services simulation Language (OSsL) schema, 
	 * since OSsL specifies both simulation service input and output.
	 * 
	 * </P>
	 * 
	 * @param osslInput holds the simulation input in a string which format follows the 
	 * Optimization Services simulation Language (OSsL) schema.  
	 * @param osol holds the optimization option in a string which format follows the 
	 * Optimization Services option Language (OSoL) schema.    
	 * @return osslOutput, the simulation output in a string which format follows the Optimization
	 * Services simulation Language (OSsL) schema.  
	 */
	public String call(String osslInput, String osol){
		if(osslInput == null) osslInput = "";
		if(osol == null) osol = "";

		String sOSsLOutput = "";
		try{
			//set input
			SimulationThread simulationThread = new SimulationThread();
			simulationThread.m_simulation = this.simulation;
			simulationThread.m_sOSsLInput = osslInput;
			simulationThread.m_sOSoL = osol;
		
			//launch simulation thread
			Thread thread = new Thread(simulationThread);
			thread.start();

			long lTimeSpan = (long)m_dJobMaxTime*1000;
			thread.join(lTimeSpan);
			
			//get output
			sOSsLOutput = simulationThread.m_sOSsLOutput;	
			return sOSsLOutput;
		}
		catch(Exception e){
			IOUtil.log(IOUtil.exceptionStackToString(e), null);			
			return sOSsLOutput;
		}
	}//call

	/**
	 * <P>The <code>SolveThread</code> class is an internal thread controlled by <code>OSServiceUtil</code> to call the solve method.
	 */
	protected class SolveThread implements Runnable{
		/**
		 * osServiceUtil holds the interface to call the local solve method. 
		 */
		protected OSServiceUtil m_osServiceUtil = null;
		
		/**
		 * m_osSolverAgent holds the agent to call the remote solve method. 
		 */
		protected OSSolverAgent m_osSolverAgent = null;
		
		/**
		 * m_sOSiL holds the osil input for the solve method. 
		 */
		protected String m_sOSiL = "";
		
		/**
		 * m_sOSoL holds the osol input for the solve method. 
		 */
		protected String m_sOSoL = "";

		/**
		 * m_sOSrL holds the osrl output for the solve method. 
		 */
		protected String m_sOSrL = "";

		
		/**
		 * A solve method is implemented here. 
		 */
		public void run(){	
			try {
				if(m_osServiceUtil != null){
					m_sOSrL = m_osServiceUtil.solve(m_sOSiL, m_sOSoL);
				}
				else if(m_osSolverAgent != null){
					m_sOSrL = m_osSolverAgent.solve(m_sOSiL, m_sOSoL);
				}				
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}//run
		
	}//SolveThread

	/**
	 * <P>The <code>SendThread</code> class is an internal thread controlled by <code>OSServiceUtil</code> to call the send method.
	 */
	protected class SendThread implements Runnable{
		/**
		 * osServiceUtil holds the interface to call the local send method. 
		 */
		protected OSServiceUtil m_osServiceUtil = null;
		
		/**
		 * m_osSolverAgent holds the agent to call the remote send method. 
		 */
		protected OSSolverAgent m_osSolverAgent = null;
		
		/**
		 * m_sOSiL holds the osil input for the send method. 
		 */
		protected String m_sOSiL = "";
		
		/**
		 * m_sOSoL holds the osol input for the send method. 
		 */
		protected String m_sOSoL = "";

		/**
		 * m_bSend holds the boolean output for the send method. 
		 */
		protected boolean m_bSend = false;
		
		/**
		 * A send method is implemented here. 
		 */
		public void run(){	
			try {
				if(m_osServiceUtil != null){
					m_bSend = m_osServiceUtil.send(m_sOSiL, m_sOSoL);
				}
				else if(m_osSolverAgent != null){
					m_bSend = m_osSolverAgent.send(m_sOSiL, m_sOSoL);
				}				
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}//run
		
	}//SendThread

	/**
	 * <P>The <code>RetrieveThread</code> class is an internal thread controlled by <code>OSServiceUtil</code> to call the retrieve method.
	 */
	protected class RetrieveThread implements Runnable{
		/**
		 * osServiceUtil holds the interface to call the local retrieve method. 
		 */
		protected OSServiceUtil m_osServiceUtil = null;
		
		/**
		 * m_osSolverAgent holds the agent to call the remote retrieve method. 
		 */
		protected OSSolverAgent m_osSolverAgent = null;
				
		/**
		 * m_sOSoL holds the osol input for the retrieve method. 
		 */
		protected String m_sOSoL = "";

		/**
		 * m_sOSrL holds the osrl output for the retrieve method. 
		 */
		protected String m_sOSrL = "";

		/**
		 * m_sResultFile holds the result file name.  
		 */
		protected String m_sResultFile = "";
		
		/**
		 * A retrieve method is implemented here. 
		 */
		public void run(){	
			if(m_sResultFile != null && m_sResultFile.length() > 0  && IOUtil.existsFileOrDir(m_sResultFile)){
				OSrLReader osrlReader = new OSrLReader();
				try {
					boolean bRead = osrlReader.readFile(m_sResultFile);
					if(bRead){
						String sStatus = osrlReader.getGeneralStatusType();
						if(sStatus != null && (sStatus.equals("success") || sStatus.equals("error"))){
							m_sOSrL = IOUtil.readStringFromFile(m_sResultFile);
							if(m_sOSrL == null){
								m_sOSrL = "";
							}
							return;
						}	
					}
				}
				catch (Exception e) {
					IOUtil.log(IOUtil.exceptionStackToString(e), null);
				}
			}

			try {
				if(m_osServiceUtil != null){
					m_sOSrL = m_osServiceUtil.retrieve(m_sOSoL);
				}
				else if(m_osSolverAgent != null){
					m_sOSrL = m_osSolverAgent.retrieve(m_sOSoL);
				}
			}
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
				return;
			}
			
			if(m_sResultFile == null || m_sResultFile.length() <= 0) return;
			
			if(m_sOSrL != null && m_sOSrL.length() > 0){
				OSrLReader osrlReader = new OSrLReader();
				try {
					boolean bRead = osrlReader.readString(m_sOSrL);
					if(!bRead) throw new Exception("Invalid OSrL result");
					String sStatus = osrlReader.getGeneralStatusType();
					if(sStatus != null && (sStatus.equals("success") || sStatus.equals("error"))){
						boolean bWrite = IOUtil.writeStringToFile(m_sOSrL, m_sResultFile);
						if(!bWrite){
							IOUtil.log("result file " + m_sResultFile + " not written successfully", null);
						}
					}	
				}
				catch (Exception e) {
					IOUtil.log(IOUtil.exceptionStackToString(e), null);
				}
			}
			return;
		}//run
	}//RetrieveThread

	/**
	 * <P>The <code>KillThread</code> class is an internal thread controlled by <code>OSServiceUtil</code> to call the kill method.
	 */
	protected class KillThread implements Runnable{
		/**
		 * osServiceUtil holds the interface to call the local kill method. 
		 */
		protected OSServiceUtil m_osServiceUtil = null;
		
		/**
		 * m_osSolverAgent holds the agent to call the remote kill method. 
		 */
		protected OSSolverAgent m_osSolverAgent = null;
				
		/**
		 * m_sOSoL holds the osol input for the kill method. 
		 */
		protected String m_sOSoL = "";

		/**
		 * m_sOSpL holds the ospl output for the kill method. 
		 */
		protected String m_sOSpL = "";

		
		/**
		 * A kill method is implemented here. 
		 */
		public void run(){	
			try {
				if(m_osServiceUtil != null){
					m_sOSpL = m_osServiceUtil.kill(m_sOSoL);
				}
				else if(m_osSolverAgent != null){
					m_sOSpL = m_osSolverAgent.kill(m_sOSoL);
				}				
			}
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}//run
		
	}//KillThread

	/**
	 * <P>The <code>KnockSolverThread</code> class is an internal thread controlled by <code>OSServiceUtil</code> to call the knock method on a solver.
	 */
	protected class KnockSolverThread implements Runnable{
		/**
		 * osServiceUtil holds the interface to call the local knock method. 
		 */
		protected OSServiceUtil m_osServiceUtil = null;
		
		/**
		 * m_osSolverAgent holds the agent to call the remote knock method. 
		 */
		protected OSSolverAgent m_osSolverAgent = null;

		/**
		 * m_osplInput holds the ospl input for the knock method. 
		 */
		protected String m_osplInput = "";

		/**
		 * m_osol holds the osol input for the knock method. 
		 */
		protected String m_osol = "";

		/**
		 * m_osplOutput holds the ospl output for the knock method. 
		 */
		protected String m_osplOutput = "";

		
		/**
		 * A knock method is implemented here. 
		 */
		public void run(){	
			try {
				if(m_osServiceUtil != null){
					m_osplOutput = m_osServiceUtil.knock(m_osplInput, m_osol);
				}
				else if(m_osSolverAgent != null){
					m_osplOutput = m_osSolverAgent.knock(m_osplInput, m_osol);
				}				
			}
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}//run
		
	}//KnockSolverThread

	/**
	 * <P>The <code>KnockRegistryThread</code> class is an internal thread controlled by <code>OSServiceUtil</code> to call the knock method on a registry.
	 */
	protected class KnockRegistryThread implements Runnable{
		/**
		 * osServiceUtil holds the interface to call the local knock method. 
		 */
		protected OSServiceUtil m_osServiceUtil = null;
		
		/**
		 * m_osRegistryAgent holds the agent to call the remote knock method. 
		 */
		protected OSRegistryAgent m_osRegistryAgent = null;

		/**
		 * m_sOSpLInput holds the ospl input for the knock method. 
		 */
		protected String m_sOSpLInput = "";

		/**
		 * m_sOSoL holds the osol input for the knock method. 
		 */
		protected String m_sOSoL = "";

		/**
		 * m_sOSpLOutput holds the ospl output for the knock method. 
		 */
		protected String m_sOSpLOutput = "";

		
		/**
		 * A knock method is implemented here. 
		 */
		public void run(){	
			try {
				if(m_osServiceUtil != null){
					m_sOSpLOutput = m_osServiceUtil.knock(m_sOSpLInput, m_sOSoL);
				}
				else if(m_osRegistryAgent != null){
					m_sOSpLOutput = m_osRegistryAgent.knock(m_sOSpLInput, m_sOSoL);
				}				
			}
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}//run
	}//KnockRegistryThread

	/**
	 * <P>The <code>FindThread</code> class is an internal thread controlled by <code>OSServiceUtil</code> to call the find method on a registry.
	 */
	protected class FindThread implements Runnable{
		/**
		 * osServiceUtil holds the interface to call the local find method. 
		 */
		protected OSServiceUtil m_osServiceUtil = null;
		
		/**
		 * m_osRegistryAgent holds the agent to call the remote find method. 
		 */
		protected OSRegistryAgent m_osRegistryAgent = null;

		/**
		 * m_sOSqL holds the osql input for the find method. 
		 */
		protected String m_sOSqL = "";

		/**
		 * m_sOSoL holds the osol input for the find method. 
		 */
		protected String m_sOSoL = "";

		/**
		 * m_osul holds the osul output for the find method. 
		 */
		protected String m_sOSuL = "";

		
		/**
		 * A find method is implemented here. 
		 */
		public void run(){	
			try {
				if(m_osServiceUtil != null){
					m_sOSuL = m_osServiceUtil.find(m_sOSqL, m_sOSoL);
				}
				else if(m_osRegistryAgent != null){
					m_sOSuL = m_osRegistryAgent.find(m_sOSqL, m_sOSoL);
				}				
			}
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}//run
	}//FindThread

	/**
	 * remove a waiting job
	 * 
	 * @param jobID holds the jobID of the waiting job to remove. 
	 * @return whether the job is removed from the waiting list. 
	 */
	@SuppressWarnings("deprecation")
	protected static boolean removeWaitingJob(String jobID){
		if(m_vFinishedJobIDs.contains(jobID)){
			return true;
		}

		Thread thread = (Thread)m_threadHashTable.get(jobID);	
		if(thread != null){
			try{
				thread.stop();
			}
			catch(Exception e){
				String sException = IOUtil.exceptionStackToString(e);
				IOUtil.log(sException, null);
			}
		}
		
		JobStatistics jobStatistics  = m_jobStatisticsTable.get(jobID);
		if(jobStatistics == null){
			jobStatistics = new JobStatistics();
			jobStatistics.jobID = jobID;
			m_jobStatisticsTable.put(jobID, jobStatistics);
		}
		
		String sUserName = jobStatistics.userName;
		if(sUserName == null) sUserName = "";
		String sCount = m_userJobCountTable.get(sUserName);
		int iCount;
		if(sCount == null || sCount.length() <= 0){
			iCount = 0;
		}
		else{
			try {
				iCount = Integer.parseInt(sCount);					
			} 
			catch (Exception e) {
				iCount = 0;
			}
			if(iCount <= 0){
				iCount = 0;
			}
			else if( m_vWaitingJobIDs.contains(jobID) || m_vCurrentJobIDs.contains(jobID)){
				iCount -= 1;
			}
		}		
		m_userJobCountTable.remove(sUserName);
		m_userJobCountTable.put(sUserName, iCount+"");			

		m_solverThreadHashTable.remove(jobID);
		m_threadHashTable.remove(jobID);
		m_vCurrentJobIDs.remove(jobID);
		m_vWaitingJobIDs.remove(jobID);
		processsHashTable.remove(jobID);
		m_vFinishedJobIDs.remove(jobID);
		m_vFinishedJobIDs.add(jobID);
		m_iCurrentJobCount = m_vCurrentJobIDs.size();

		jobStatistics.jobID = jobID;
		jobStatistics.state = "killed";
		jobStatistics.startTime = new GregorianCalendar(); 
		jobStatistics.endTime = jobStatistics.startTime;
		m_lTimeLastJobEnded = jobStatistics.endTime.getTimeInMillis();
		jobStatistics.duration = 0;			
		m_dServiceUtilization = ((double)m_lTotalBusyTime/(m_lTimeLastJobEnded - m_lTimeServiceStarted));
		
		//save ospl
		saveOSpL();

		return true;
	}//removeWaitingJob
	
	/**
	 * <P>The <code>ProcessJobRequestThread</code> class is an internal thread controlled by <code>OSServiceUtil</code> 
	 * to process job request. 
	 */
	protected class ProcessJobRequestThread implements Runnable{
		/**
		 * m_sRequestingServiceURI holds the serviceURI of the requesting service. 
		 */
		protected String m_sRequestingServiceURI = "";
		
		/**
		 * The job request process is implemented here. 
		 */
		public void run(){	
			if(OSParameter.SERVICE_TYPE == null || !OSParameter.SERVICE_TYPE.equals("scheduler")){
				return;
			}
			if(!m_sCurrentState.equals("idle") && !m_sCurrentState.equals("busyButAccepting")){
				return;
			}
			int iWaitingJobs = (m_vWaitingJobIDs==null?0:m_vWaitingJobIDs.size());
			if(iWaitingJobs <= 0){
				return;
			}
			String[] msWaitingJobIDs = new String[iWaitingJobs];
			for(int i = iWaitingJobs-1; i >=0; i--){
				try{
					msWaitingJobIDs[i] = m_vWaitingJobIDs.elementAt(i);
				}
				catch(Exception e){
					msWaitingJobIDs[i] = "";
				}
			}
			for(int i = 0; i < iWaitingJobs; i++){
				String sJobID = msWaitingJobIDs[i];

				acceptingSolverURIs.remove(m_sRequestingServiceURI);
				OSServiceUtil osServiceUtil = new OSServiceUtil();						
				osServiceUtil.serviceName = OSParameter.SERVICE_NAME;
				osServiceUtil.serviceURI = OSParameter.OS_SCHEDULER_SITE; 
				osServiceUtil.serviceType = "scheduler";
				osServiceUtil.m_sJobID = sJobID;

				if(sJobID == null || sJobID.length() <= 0){
					continue;
				}

				if(!m_vWaitingJobIDs.contains(sJobID)){
					continue;
				}
				String sOptionFile = OSParameter.TEMP_FILE_FOLDER+sJobID+".osol";
				if(!IOUtil.existsFileOrDir(sOptionFile)){
					removeWaitingJob(sJobID);
					continue;
				}
				String sOSoL = IOUtil.readStringFromFile(sOptionFile);
				if(sOSoL == null || sOSoL.length() <= 0){
					sOSoL = "";
					removeWaitingJob(sJobID);
					continue;
				}

				if(!osServiceUtil.readOSoL(sOSoL)){
					removeWaitingJob(sJobID);
					continue;
				}

				try {
					if(osServiceUtil.checkWaiting("", sOSoL, false, false)){
						continue;
					}
				} 
				catch (Exception e) {
					removeWaitingJob(sJobID);
				}
				String sInstanceFile = OSParameter.TEMP_FILE_FOLDER+sJobID+".osil";
				String sOSiL = IOUtil.readStringFromFile(sInstanceFile);
				if(sOSiL == null){
					sOSiL = "";
				}
				acceptingSolverURIs.remove(m_sRequestingServiceURI);
				acceptingSolverURIs.add(0, m_sRequestingServiceURI);
				boolean bSend = osServiceUtil.send(sOSiL, sOSoL);
				if(m_vWaitingJobIDs.contains(sJobID)){
					m_vWaitingJobIDs.remove(sJobID);
					m_vWaitingJobIDs.add(sJobID);
				}
				if(!acceptingSolverURIs.contains(sJobID)){
					return;
				}
				if(!m_sCurrentState.equals("idle") && !m_sCurrentState.equals("busyButAccepting")){
					return;
				}
			}
		}//run		
	}//ProcessJobRequestThread
	
	/**
	 * <P>The <code>ProcessWaitingJobsThread</code> class is an internal thread controlled by <code>OSServiceUtil</code> 
	 * to process waiting jobs. 
	 */
	protected static class ProcessWaitingJobsThread implements Runnable{
		/**
		 * The waiting job process is implemented here. 
		 */
		public void run(){	
			if(!m_sCurrentState.equals("idle") && !m_sCurrentState.equals("busyButAccepting")){
				return;
			}
			int iWaitingJobs = (m_vWaitingJobIDs==null?0:m_vWaitingJobIDs.size());
			if(iWaitingJobs <= 0){
				return;
			}
			String[] msWaitingJobIDs = new String[iWaitingJobs];
			for(int i = iWaitingJobs-1; i >=0; i--){
				try{
					msWaitingJobIDs[i] = m_vWaitingJobIDs.elementAt(i);
				}
				catch(Exception e){
					msWaitingJobIDs[i] = "";
				}
			}
			int iEmptyAcceptingSolverURIs = 0;
			if(OSParameter.SERVICE_TYPE != null && OSParameter.SERVICE_TYPE.equals("scheduler")){
				int iAcceptingSolverURIs = (acceptingSolverURIs == null?0:acceptingSolverURIs.size());
				if(iAcceptingSolverURIs == 0) iEmptyAcceptingSolverURIs++;
			}
			for(int i = 0; i < iWaitingJobs; i++){
				String sJobID = msWaitingJobIDs[i];
				OSServiceUtil osServiceUtil = new OSServiceUtil();						
				osServiceUtil.m_sJobID = sJobID;

				if(sJobID == null || sJobID.length() <= 0){
					continue;
				}
				if(!m_vWaitingJobIDs.contains(sJobID)){
					continue;
				}				
				long lNow = new GregorianCalendar().getTimeInMillis();								
				JobStatistics jobStatistics  = m_jobStatisticsTable.get(sJobID);
				if(jobStatistics == null){
					jobStatistics = new JobStatistics();
					jobStatistics.jobID = sJobID;
					m_jobStatisticsTable.put(sJobID, jobStatistics);
				}
				if(jobStatistics.submitTime == null || jobStatistics.submitTime.get(GregorianCalendar.YEAR) <= 1970){
					jobStatistics.submitTime = new GregorianCalendar();
				}
				if(((lNow - jobStatistics.submitTime.getTimeInMillis())/1000.0 > (2*OSParameter.JOB_MAX_TIME))){	
					removeWaitingJob(sJobID);
					continue;
				}				
				String sOptionFile = OSParameter.TEMP_FILE_FOLDER+sJobID+".osol";
				if(!IOUtil.existsFileOrDir(sOptionFile)){
					removeWaitingJob(sJobID);
					continue;
				}
				String sOSoL = IOUtil.readStringFromFile(sOptionFile);
				if(sOSoL == null || sOSoL.length() <= 0){
					sOSoL = "";
					removeWaitingJob(sJobID);
					continue;
				}
				if(!osServiceUtil.readOSoL(sOSoL)){
					removeWaitingJob(sJobID);
					continue;
				}
				try {
					if(osServiceUtil.checkWaiting("", sOSoL, false, false)){
						continue;
					}
				} 
				catch (Exception e) {
					removeWaitingJob(sJobID);
				}

				String sInstanceFile = OSParameter.TEMP_FILE_FOLDER+sJobID+".osil";
				String sOSiL = IOUtil.readStringFromFile(sInstanceFile);
				if(sOSiL == null){
					sOSiL = "";
				}
				boolean bSend = osServiceUtil.send(sOSiL, sOSoL);
				if(m_vWaitingJobIDs.contains(sJobID)){ 		
					m_vWaitingJobIDs.remove(sJobID);
					m_vWaitingJobIDs.add(sJobID);			
				}
				if(!m_sCurrentState.equals("idle") && !m_sCurrentState.equals("busyButAccepting")){
					return;
				}
				if(OSParameter.SERVICE_TYPE != null && OSParameter.SERVICE_TYPE.equals("scheduler")){
					int iAcceptingSolverURIs = (acceptingSolverURIs == null?0:acceptingSolverURIs.size());
					if(iAcceptingSolverURIs == 0) iEmptyAcceptingSolverURIs++;
					if(iEmptyAcceptingSolverURIs >= 2){
						return;
					}
				}
			}
		}//run		
	}//ProcessWaitingJobsThread
	
	/**
	 * <P>The <code>CheckSchedulerCurrentJobsThread</code> class is an internal thread controlled by <code>OSServiceUtil</code> 
	 * to process current jobs in the scheduler 
	 */
	protected static class CheckSchedulerCurrentJobsThread implements Runnable{
		/**
		 * m_sCurrentJobID holds the jobID of the current Job. 
		 */
		protected String m_sCurrentJobID = "";
		
		
		/**
		 * The current scheculer jobs processing are implemented here. 
		 */
		public void run(){
			/* get job statistics from scheduler to solver reference*/
			if(OSParameter.SERVICE_TYPE == null || !OSParameter.SERVICE_TYPE.equals("scheduler")) return;
			if(m_sCurrentJobID == null || m_sCurrentJobID.length() <= 0) return;
			JobStatistics jobStatistics = m_jobStatisticsTable.get(m_sCurrentJobID);
			if(jobStatistics == null){
				jobStatistics = new JobStatistics();						
				jobStatistics.jobID = m_sCurrentJobID;
				m_jobStatisticsTable.put(m_sCurrentJobID, jobStatistics);
			}
			jobStatistics.jobID = m_sCurrentJobID;
			String sServiceURI = jobStatistics.serviceURI;
			if(sServiceURI != null && sServiceURI.equals(OSParameter.OS_SCHEDULER_SITE)) sServiceURI = "";
			if(sServiceURI == null || sServiceURI.length() <= 0){
				jobStatistics.state = "waiting";
				jobStatistics.startTime = new GregorianCalendar(1970, 0, 1, 0, 0, 0);
				m_vCurrentJobIDs.remove(m_sCurrentJobID);
				m_vWaitingJobIDs.remove(m_sCurrentJobID);
				m_vWaitingJobIDs.add(m_sCurrentJobID);
				return;
			}
			try {
				OSpLWriter osplWriter = new OSpLWriter();
				osplWriter.setRequestAction("getJobStatistics");
				osplWriter.setServiceName(OSParameter.SERVICE_NAME);
				osplWriter.setServiceURI(OSParameter.OS_SCHEDULER_SITE);
				osplWriter.setProcessTime(new GregorianCalendar());
				String sOSpLInput = osplWriter.writeToString();

				OSoLWriter osolWriter = new OSoLWriter();
				osolWriter.setServiceName(OSParameter.SERVICE_NAME);
				osolWriter.setServiceURI(OSParameter.OS_SCHEDULER_SITE);
				osolWriter.setJobID(m_sCurrentJobID);
				osolWriter.setPassword(m_sSystemPassword);
				String sOSoL = osolWriter.writeToString();

				String sOSpLOutput = "";
				try{
					OSSolverAgent osSolverAgent = new OSSolverAgent(sServiceURI);
					sOSpLOutput = osSolverAgent.knock(sOSpLInput, sOSoL);					
				} 
				catch(Exception e){
					IOUtil.log(IOUtil.exceptionStackToString(e), null);
					return;
				}
				JobStatistics[] mJobStatistics = null;
				OSpLReader osplReader = new OSpLReader(OSParameter.VALIDATE);
				
				try {
					osplReader.readString(sOSpLOutput);
					mJobStatistics = osplReader.getJobStatistics();					
				} 
				catch (Exception e) {
					IOUtil.log(IOUtil.exceptionStackToString(e), null);
				}
				if(mJobStatistics == null || mJobStatistics.length <= 0) return;
				int iJobStatistics = mJobStatistics.length;
				boolean bRemoveCurrentJob = false;
				JobStatistics newJobStatistics = null;
				for(int i = 0; i < iJobStatistics; i++){
					if(mJobStatistics[i] == null) continue;
					String sJobID = mJobStatistics[i].jobID;
					if(sJobID == null || !sJobID.equals(m_sCurrentJobID)){
						continue;
					}
					else{
						String sJobState = mJobStatistics[i].state;
						if(sJobState != null && (sJobState.equals("finished") || sJobState.equals("killed"))){
							newJobStatistics = mJobStatistics[i];
							bRemoveCurrentJob = true;
						}						
						break;
					}
				}
				if(bRemoveCurrentJob){
					osplWriter = new OSpLWriter();
					osplWriter.setRequestAction("notifyJobCompletion");
					osplWriter.setServiceURI(sServiceURI);
					osplWriter.setProcessTime(new GregorianCalendar());
					JobStatistics[] mJobStatistics1 = new JobStatistics[1];
					mJobStatistics1[0] = newJobStatistics;
					osplWriter.setJobStatistics(mJobStatistics1);
					String sProcessInput = osplWriter.writeToString();
					
					osolWriter = new OSoLWriter();
					osolWriter.setServiceURI(sServiceURI);
					osolWriter.setJobID(m_sCurrentJobID);
					osolWriter.setPassword(OSParameter.getSystemPassword());			
					osolWriter.setServiceType("solver");
					String sOption = osolWriter.writeToString();
					
					OSServiceUtil osServiceUtil = new OSServiceUtil();						
					osServiceUtil.m_sJobID = m_sCurrentJobID;
					osServiceUtil.knock(sProcessInput, sOption);
					
					/* The following does partially what the osServiceUtil.knock (action="notifyJobCompletion") does.  
					if(jobStatistics.userName == null || jobStatistics.userName.length() <= 0){
						jobStatistics.userName = newJobStatistics.userName;
					}
					Thread thread = (Thread)m_threadHashTable.get(m_sCurrentJobID);
					if(thread != null){
						try{
							thread.stop();
						}
						catch(Exception e){
							IOUtil.log(IOUtil.exceptionStackToString(e), null);
						}
					}
					String sUserName = jobStatistics.userName;
					if(sUserName == null) sUserName = "";
					String sCount = m_userJobCountTable.get(sUserName);
					int iCount;
					if(sCount == null || sCount.length() <= 0){
						iCount = 0;
					}
					else{
						try {
							iCount = Integer.parseInt(sCount);					
						} 
						catch (Exception e) {
							iCount = 0;
						}
						if(iCount <= 0){
							iCount = 0;
						}
						else if(m_vWaitingJobIDs.contains(m_sCurrentJobID) || m_vCurrentJobIDs.contains(m_sCurrentJobID)){
							iCount -= 1;
						}
					}
					m_userJobCountTable.remove(sUserName);
					m_userJobCountTable.put(sUserName, iCount+"");

					m_solverThreadHashTable.remove(m_sCurrentJobID);
					m_threadHashTable.remove(m_sCurrentJobID);
					m_vCurrentJobIDs.remove(m_sCurrentJobID);
					m_vWaitingJobIDs.remove(m_sCurrentJobID);
					m_vFinishedJobIDs.remove(m_sCurrentJobID);
					m_vFinishedJobIDs.add(m_sCurrentJobID);
					m_iCurrentJobCount = m_vCurrentJobIDs.size();
					
					jobStatistics.state = newJobStatistics.state;
					if(jobStatistics.submitTime == null || jobStatistics.submitTime.get(Calendar.YEAR) <= 1970){
						jobStatistics.submitTime = newJobStatistics.submitTime;
					}
					if(newJobStatistics.startTime != null && newJobStatistics.startTime.get(Calendar.YEAR) > 1970){
						jobStatistics.startTime = newJobStatistics.startTime;
					}
					if(newJobStatistics.endTime != null && newJobStatistics.endTime.get(Calendar.YEAR) > 1970){
						jobStatistics.endTime = newJobStatistics.endTime;
					}
					if(jobStatistics.startTime != null && jobStatistics.startTime.get(Calendar.YEAR) > 1970 &&
						jobStatistics.endTime != null && jobStatistics.endTime.get(Calendar.YEAR) > 1970){
						jobStatistics.duration = (jobStatistics.endTime.getTimeInMillis() - jobStatistics.startTime.getTimeInMillis())/1000.0;
					}
					//retrieve job
					try{
						OSoLWriter osolWriter2 = new OSoLWriter();
						osolWriter2.setServiceName(OSParameter.SERVICE_NAME);
						osolWriter2.setServiceURI(OSParameter.SERVICE_URI);
						osolWriter2.setJobID(m_sCurrentJobID);
						osolWriter2.setPassword(m_sSystemPassword);
						osolWriter2.setServiceType("scheduler");
						String sOSoLInput = osolWriter2.writeToString();					
						
						OSServiceUtil osServiceUtil = new OSServiceUtil();
						RetrieveThread retrieveThread = osServiceUtil.new RetrieveThread();
						OSSolverAgent osSolverAgent = new OSSolverAgent(sServiceURI);
						retrieveThread.m_osSolverAgent = osSolverAgent;
						retrieveThread.m_sOSoL = sOSoLInput;
						String sResultFile = OSParameter.TEMP_FILE_FOLDER+m_sCurrentJobID+".osrl";
						retrieveThread.m_sResultFile = sResultFile;
						
						Thread thread2 = new Thread(retrieveThread);
						thread2.start();
					}	
					catch (Exception e){
						IOUtil.log(IOUtil.exceptionStackToString(e),null);
					}	
					*/				
				}
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}//run
	}//CheckSchedulerCurrentJobsThread

	/**
	 * save process information in OSpL. 
	 * 
	 * @return whether the process information is save successfully or not. 
	 */
	protected static boolean saveOSpL(){		
		try {
			OSpLWriter osplWriter = new OSpLWriter();
			osplWriter.setServiceURI(OSParameter.SERVICE_URI);
			osplWriter.setServiceName(OSParameter.SERVICE_NAME);
			osplWriter.setProcessTime(new GregorianCalendar());
			osplWriter.setCurrentState(m_sCurrentState);
			osplWriter.setAvailableDiskSpace(m_dAvailableDiskSpace);
			osplWriter.setAvailableMemory(m_dAvailableMemory);
			osplWriter.setCurrentJobCount(m_vCurrentJobIDs==null?0:m_vCurrentJobIDs.size());
			osplWriter.setTotalJobsSoFar(m_iTotalJobsSoFar);
			osplWriter.setTimeLastJobEnded(CommonUtil.createNativeDateTime(m_lTimeLastJobEnded));			
			if(m_lLastJobTook < 0){
				osplWriter.setTimeLastJobTook(-1);					
			}
			else{
				osplWriter.setTimeLastJobTook((double)(m_lLastJobTook/1000.0));
			}
			osplWriter.setTimeServiceStarted(CommonUtil.createNativeDateTime(m_lTimeServiceStarted));
			osplWriter.setServiceUtilization(m_dServiceUtilization);
			
			
			int iCurrentJobs = m_vCurrentJobIDs.size();
			int iWaitingJobs = m_vWaitingJobIDs.size();
			int iFinishedJobs = m_vFinishedJobIDs.size();

			int iJobs =  iCurrentJobs + iWaitingJobs + iFinishedJobs;
			JobStatistics[] mAllJobStatistics = new JobStatistics[iJobs];
			int j = 0;
			for(int i = iCurrentJobs-1; i >= 0 ; i--){
				try{
					mAllJobStatistics[j] = (JobStatistics)m_jobStatisticsTable.get(m_vCurrentJobIDs.elementAt(i));
					j++;
				}
				catch(Exception e){
				}
			}
			for(int i = iWaitingJobs-1; i >= 0 ; i--){
				try{
					mAllJobStatistics[j] = (JobStatistics)m_jobStatisticsTable.get(m_vWaitingJobIDs.elementAt(i));
					j++;
				}
				catch(Exception e){
				}
			}
			for(int i = iFinishedJobs-1; i >= 0 ; i--){
				try{
					mAllJobStatistics[j] = (JobStatistics)m_jobStatisticsTable.get(m_vFinishedJobIDs.elementAt(i));
					j++;
				}
				catch(Exception e){
				}
			}
			if(iJobs > 0){
				osplWriter.setJobStatistics(mAllJobStatistics);
			}
			osplWriter.writeToFile(OSParameter.PROCESS_FILE+"_backup");
			return true;
		} 
		catch (Exception e) {
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
			return false;
		}		
	}//saveOSpL 
	
	/**
	 * clear up jobs from the three queues in memory and also files from the disk.
	 * 
	 * @return whether the jobs are cleared up successfully. 
	 */
	protected static boolean clearUpJobs(){
		int iCurrentJobs = (m_vCurrentJobIDs==null?0:m_vCurrentJobIDs.size());
		String[] msCurrentJobIDs = new String[iCurrentJobs];
		for(int i = iCurrentJobs-1; i >= 0; i--){
			try{
				msCurrentJobIDs[i] = m_vCurrentJobIDs.elementAt(i);
			}
			catch(Exception e){
				msCurrentJobIDs[i] = "";
			}
		}
		for(int i = 0; i < iCurrentJobs; i++){
			String sJobID = msCurrentJobIDs[i];
			if(sJobID == null || sJobID.length() <= 0){
				continue;
			}
			if(!m_vCurrentJobIDs.contains(sJobID)){
				continue;
			}
			OSServiceUtil osServiceUtil = new OSServiceUtil();						
			osServiceUtil.m_sJobID = sJobID;
			
			long lNow = new GregorianCalendar().getTimeInMillis();	
			JobStatistics jobStatistics = (JobStatistics)m_jobStatisticsTable.get(sJobID);
			if(jobStatistics == null){
				jobStatistics = new JobStatistics();
				jobStatistics.jobID = sJobID;
				m_jobStatisticsTable.put(sJobID, jobStatistics);
			}
			if(jobStatistics.startTime == null || jobStatistics.startTime.get(GregorianCalendar.YEAR) <= 1970){
				jobStatistics.startTime = new GregorianCalendar();
			}
			if((lNow - jobStatistics.startTime.getTimeInMillis())/1000.0 > OSParameter.JOB_MAX_TIME){	
				try {
					String sOptionFile = OSParameter.TEMP_FILE_FOLDER+sJobID+".osol";
					String sOSoL = IOUtil.readStringFromFile(sOptionFile);
					if(sOSoL == null || sOSoL.length() <= 0 || !osServiceUtil.readOSoL(sOSoL)){
						OSoLWriter osolWriter = new OSoLWriter();
						osolWriter.setServiceURI(OSParameter.SERVICE_URI);
						osolWriter.setServiceName(OSParameter.SERVICE_NAME);
						osolWriter.setJobID(sJobID);
						osolWriter.setPassword(OSParameter.getSystemPassword());
						osolWriter.setServiceType(OSParameter.SERVICE_TYPE);
						sOSoL = osolWriter.writeToString();
					}
					osServiceUtil.kill(sOSoL);		
				} 
				catch (Exception e) {
					IOUtil.log(IOUtil.exceptionStackToString(e), null);
					osServiceUtil.m_sJobID = sJobID;
					osServiceUtil.postprocess(true);
				}	
			}
		}
		m_iCurrentJobCount = m_vCurrentJobIDs.size();

		while(m_vCurrentJobIDs.size() > OSParameter.MAX_JOB_NUMBERS){
			String sJobID = "";
			try {
				sJobID = m_vCurrentJobIDs.elementAt(0);
			} 
			catch (Exception e) {
				break;
			}

			OSServiceUtil osServiceUtil = new OSServiceUtil();						
			osServiceUtil.m_sJobID = sJobID;

			try {
				String sOptionFile = OSParameter.TEMP_FILE_FOLDER+sJobID+".osol";
				String sOSoL = IOUtil.readStringFromFile(sOptionFile);
				if(sOSoL == null || sOSoL.length() <= 0 || !osServiceUtil.readOSoL(sOSoL)){
					OSoLWriter osolWriter = new OSoLWriter();
					osolWriter.setServiceURI(OSParameter.SERVICE_URI);
					osolWriter.setServiceName(OSParameter.SERVICE_NAME);
					osolWriter.setJobID(sJobID);
					osolWriter.setPassword(OSParameter.getSystemPassword());
					osolWriter.setServiceType(OSParameter.SERVICE_TYPE);
					sOSoL = osolWriter.writeToString();
				}
				osServiceUtil.kill(sOSoL);		
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
				osServiceUtil.m_sJobID = sJobID;
				osServiceUtil.postprocess(true);
			}
		}		
		m_iCurrentJobCount = m_vCurrentJobIDs.size();

		
		while(m_vWaitingJobIDs.size() > OSParameter.MAX_WAITING_NUMBERS){
			try {
				String sJobID = m_vWaitingJobIDs.elementAt(0);
				removeWaitingJob(sJobID);
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}

		while(m_vFinishedJobIDs.size() > OSParameter.MAX_JOBIDS_TO_KEEP){
			try {
				String sJobID = m_vFinishedJobIDs.elementAt(0);
				m_vFinishedJobIDs.removeElementAt(0);
				m_jobStatisticsTable.remove(sJobID);
				String sInstanceFile = OSParameter.TEMP_FILE_FOLDER+sJobID+".osil";
				String sOptionFile = OSParameter.TEMP_FILE_FOLDER+sJobID+".osol";
				String sResultFile = OSParameter.TEMP_FILE_FOLDER+sJobID+".osrl";
				String sInstanceFileBackup = OSParameter.BACKUP_FOLDER+sJobID+".osil";
				String sOptionFileBackup = OSParameter.BACKUP_FOLDER+sJobID+".osol";
				String sResultFileBackup = OSParameter.BACKUP_FOLDER+sJobID+".osrl";
				String sDatFile = OSParameter.BACKUP_FOLDER+sJobID+".dat";
				String sTxtFile = OSParameter.BACKUP_FOLDER+sJobID+".txt";
				String sTmpFile = OSParameter.BACKUP_FOLDER+sJobID+".tmp";
				IOUtil.moveFile(sInstanceFile, sInstanceFileBackup);
				IOUtil.moveFile(sOptionFile, sOptionFileBackup);
				IOUtil.moveFile(sResultFile, sResultFileBackup);
				IOUtil.deleteFile(sDatFile);
				IOUtil.deleteFile(sTxtFile);
				IOUtil.deleteFile(sTmpFile);
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}
		
		return true;
	}//clearUpJobs
	
	/**
	 * update process statistics 
	 * 
	 * @return whether the process statistics is updated successfully or not. 
	 */
	protected static boolean updateProcessStatistics(){
		Enumeration enumeration = m_jobStatisticsTable.keys();
		while(enumeration.hasMoreElements()){
			try{
				String sJobID = (String)enumeration.nextElement();
				JobStatistics jobStatistics = (JobStatistics)m_jobStatisticsTable.get(sJobID);
				//make sure all jobStatistics are not null
				if(jobStatistics == null){
					jobStatistics = new JobStatistics();
					if(OSParameter.SERVICE_TYPE == null || OSParameter.SERVICE_TYPE.length() <= 0 || 
							OSParameter.SERVICE_TYPE.equals("solver") || OSParameter.SERVICE_TYPE.equals("analyzer")){
						jobStatistics.serviceURI = OSParameter.SERVICE_URI;
					}
					m_jobStatisticsTable.put(sJobID, jobStatistics);
				}
				//make sure all jobStatistics have jobIDs
				jobStatistics.jobID = sJobID;
				
				//make sure serviceURI is correct
				if(jobStatistics.serviceURI == null){
					jobStatistics.serviceURI = "";
				}
				if(jobStatistics.serviceURI.equals(OSParameter.OS_SCHEDULER_SITE)){
					jobStatistics.serviceURI = "";
				}
				
				//make sure all jobStatistics have states: waiting, running, finished/killed
				if(jobStatistics.state == null || jobStatistics.state.length() <= 0 || jobStatistics.state.equals("unknown")){
					if(m_vFinishedJobIDs.contains(sJobID)){
						jobStatistics.state = "finished";
					}
					else if(m_vCurrentJobIDs.contains(sJobID)){
						jobStatistics.state = "running";
					}
					else{						
						jobStatistics.state = "waiting";
						m_vWaitingJobIDs.remove(sJobID);
						m_vWaitingJobIDs.add(sJobID);
					}
				}						
				//make sure all jobs are in one of the three queues (waiting, running, finished/killed)
				if(jobStatistics.state.equals("running")){
					if(!m_vCurrentJobIDs.contains(sJobID)){
						if(m_threadHashTable.containsKey(sJobID) || (OSParameter.SERVICE_TYPE != null && OSParameter.SERVICE_TYPE.equals("scheduler"))){
							m_vCurrentJobIDs.add(sJobID);							
						}
						else{
							jobStatistics.state = "waiting";
							m_vWaitingJobIDs.remove(sJobID);
							m_vWaitingJobIDs.add(sJobID);	
						}
					}
				}
				else if(jobStatistics.state.equals("waiting")){
					if(!m_vWaitingJobIDs.contains(sJobID)){
						m_vWaitingJobIDs.add(sJobID);
					}
				}
				else if(jobStatistics.state.equals("killed") || jobStatistics.state.equals("finished")){
					if(!m_vFinishedJobIDs.contains(sJobID)){
						m_vFinishedJobIDs.add(sJobID);
					}
					//update time related values
					if(jobStatistics.endTime == null || jobStatistics.endTime.get(Calendar.YEAR) <= 1970){
						jobStatistics.endTime = new GregorianCalendar();
						if(jobStatistics.startTime != null && jobStatistics.startTime.get(Calendar.YEAR) > 1970){
							jobStatistics.duration = (jobStatistics.endTime.getTimeInMillis() - jobStatistics.startTime.getTimeInMillis())/1000.0;
						}
					}
					if(jobStatistics.duration < 0 && jobStatistics.endTime != null && jobStatistics.endTime.get(Calendar.YEAR) > 1970 &&
							jobStatistics.startTime != null && jobStatistics.startTime.get(Calendar.YEAR) > 1970){
						jobStatistics.duration = (jobStatistics.endTime.getTimeInMillis() - jobStatistics.startTime.getTimeInMillis())/1000.0;
					}

				}
				else{
					jobStatistics.state = "waiting";
					m_vWaitingJobIDs.remove(sJobID);
					m_vWaitingJobIDs.add(sJobID);
				}				
			}
			catch(Exception e){
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}
		m_iCurrentJobCount = m_vCurrentJobIDs.size();
		
		//make sure each job is only in one queue. 
		//make sure that all jobs have a corresponding job statistics
		//make sure running jobs are in thread table.
		int iFinishedJobs = m_vFinishedJobIDs.size();
		for(int i = 0; i < iFinishedJobs; i++){
			String sJobID = "";
			try {
				sJobID = m_vFinishedJobIDs.elementAt(i);				
			} 
			catch (Exception e){
				break;
			}
			if(sJobID == null || sJobID.length() <= 0){
				break;
			}

			JobStatistics jobStatistics = (JobStatistics)m_jobStatisticsTable.get(sJobID);
			if(jobStatistics == null){
				jobStatistics = new JobStatistics();
				jobStatistics.jobID = sJobID;
				jobStatistics.endTime = new GregorianCalendar();
				if(OSParameter.SERVICE_TYPE == null || OSParameter.SERVICE_TYPE.length() <= 0 || 
						OSParameter.SERVICE_TYPE.equals("solver") || OSParameter.SERVICE_TYPE.equals("analyzer")){
					jobStatistics.serviceURI = OSParameter.SERVICE_URI;
				}
				m_jobStatisticsTable.put(sJobID, jobStatistics);
			}
			if(jobStatistics.state == null || !(jobStatistics.state.equals("finished") || jobStatistics.state.equals("killed"))){
				jobStatistics.state = "finished";
			}
			m_vWaitingJobIDs.remove(sJobID);
			if(m_vCurrentJobIDs.contains(sJobID)){
				if(m_threadHashTable.containsKey(sJobID) || (OSParameter.SERVICE_TYPE != null && OSParameter.SERVICE_TYPE.equals("scheduler"))){
					m_vFinishedJobIDs.remove(sJobID);
					jobStatistics.state = "running";
					jobStatistics.endTime = new GregorianCalendar(1970, 0, 1, 0, 0, 0);
				}
				else{					
					m_vCurrentJobIDs.remove(sJobID);

				}
			}
		}
		m_iCurrentJobCount = m_vCurrentJobIDs.size();

		//make sure that all jobs in the waiting queue have a corresponding job statistics
		int iWaitingJobs = m_vWaitingJobIDs.size();
		for(int i = 0; i < iWaitingJobs; i++){
			String sJobID = "";
			try {
				sJobID = m_vWaitingJobIDs.elementAt(i);				
			} 
			catch (Exception e) {
				break;
			}
			if(sJobID == null || sJobID.length() <= 0){
				break;
			}
			JobStatistics jobStatistics = (JobStatistics)m_jobStatisticsTable.get(sJobID);
			if(jobStatistics == null){
				jobStatistics = new JobStatistics();
				jobStatistics.jobID = sJobID;
				if(OSParameter.SERVICE_TYPE == null || OSParameter.SERVICE_TYPE.length() <= 0 || 
						OSParameter.SERVICE_TYPE.equals("solver") || OSParameter.SERVICE_TYPE.equals("analyzer")){
					jobStatistics.serviceURI = OSParameter.SERVICE_URI;
				}
				m_jobStatisticsTable.put(sJobID, jobStatistics);
			}
			if(jobStatistics.state == null || !jobStatistics.state.equals("waiting")){
				jobStatistics.state = "waiting";
			}
			if(m_vCurrentJobIDs.contains(sJobID)){
				if(m_threadHashTable.containsKey(sJobID)|| (OSParameter.SERVICE_TYPE != null && OSParameter.SERVICE_TYPE.equals("scheduler"))){
					m_vWaitingJobIDs.remove(sJobID);
					jobStatistics.state = "running";
				}
				else{					
					m_vCurrentJobIDs.remove(sJobID);

				}
			}
		}
		m_iCurrentJobCount = m_vCurrentJobIDs.size();

		//make sure that all jobs in the running queue have a corresponding job statistics
		int iCurrentJobs = m_vCurrentJobIDs.size();
		for(int i = 0; i < iCurrentJobs; i++){
			String sJobID = "";
			try {
				sJobID = m_vCurrentJobIDs.elementAt(i);				
			} 
			catch (Exception e) {
				break;
			}
			if(sJobID == null || sJobID.length() <= 0){
				break;
			}
			JobStatistics jobStatistics = (JobStatistics)m_jobStatisticsTable.get(sJobID);
			if(jobStatistics == null){
				jobStatistics = new JobStatistics();
				jobStatistics.jobID = sJobID;
				if(OSParameter.SERVICE_TYPE == null || OSParameter.SERVICE_TYPE.length() <= 0 || 
						OSParameter.SERVICE_TYPE.equals("solver") || OSParameter.SERVICE_TYPE.equals("analyzer")){
					jobStatistics.serviceURI = OSParameter.SERVICE_URI;
				}
				m_jobStatisticsTable.put(sJobID, jobStatistics);
			}
			if(jobStatistics.state == null || !jobStatistics.state.equals("running")){
				jobStatistics.state = "running";
			}
		}
		m_iCurrentJobCount = m_vCurrentJobIDs.size();

		//update user statistics
		boolean bSuccess = true;
		iCurrentJobs = (m_vCurrentJobIDs==null?0:m_vCurrentJobIDs.size());
		iWaitingJobs = (m_vWaitingJobIDs==null?0:m_vWaitingJobIDs.size());
		int iUnfinishedJobs = iCurrentJobs + iWaitingJobs;
		String[] msUnfinishedJobIDs = new String[iUnfinishedJobs];
		int j = 0;
		for(int i = 0; i < iCurrentJobs; i++){
			try{
				msUnfinishedJobIDs[j] = m_vCurrentJobIDs.elementAt(i);
				j++;
				if(m_vCurrentJobIDs.size() != iCurrentJobs){
					bSuccess = false;
					break;
				}
			}
			catch(Exception e){
				bSuccess = false;
				break;
			}
		}
		if(bSuccess){
			for(int i = 0; i < iWaitingJobs; i++){
				try{
					msUnfinishedJobIDs[j] = m_vWaitingJobIDs.elementAt(i);
					j++;
					if(m_vWaitingJobIDs.size() != iWaitingJobs){
						bSuccess = false;
						break;
					}
				}
				catch(Exception e){
					bSuccess = false;
					break;
				}
			}
		}
		if(bSuccess){
			m_userJobCountTable = new Hashtable<String, String>();
			for(int i = 0; i < iUnfinishedJobs; i++){
				JobStatistics jobStatistics = m_jobStatisticsTable.get(msUnfinishedJobIDs[i]);
				String sUserName = "";
				if(jobStatistics != null){
					sUserName = jobStatistics.userName;					
				}
				if(sUserName == null){
					sUserName = "";
				}
				String sCount = m_userJobCountTable.get(sUserName);
				int iCount;
				if(sCount == null || sCount.length() <= 0){
					iCount = 0;
				}
				else{
					try {
						iCount = Integer.parseInt(sCount);					
					} 
					catch (Exception e) {
						iCount = 0;
					}
					if(iCount < 0) iCount = 0;
				}
				if(m_vWaitingJobIDs.contains(msUnfinishedJobIDs[i]) || m_vCurrentJobIDs.contains(msUnfinishedJobIDs[i])){
					iCount += 1;
					m_userJobCountTable.remove(sUserName);
					m_userJobCountTable.put(sUserName, iCount+"");				
				}

			}
		}
		
		//update stats
		GregorianCalendar now = new GregorianCalendar();
		m_dServiceUtilization = ((double)m_lTotalBusyTime/(now.getTimeInMillis() - m_lTimeServiceStarted));

		try{
			m_dAvailableDiskSpace = IOUtil.getFreeDiskSpace(OSParameter.CODE_DRIVE);	
		}
		catch(Exception e){
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
			m_dAvailableDiskSpace = Double.POSITIVE_INFINITY;
		}
		try{
			m_dAvailableMemory = ProcessUtil.getFreeMemory();	
		}
		catch(Exception e){
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
			m_dAvailableMemory = Double.POSITIVE_INFINITY;
		}
		
		if(m_dAvailableDiskSpace <= OSParameter.MINIMUM_DISKSPACE_TRIGGER ||
				   m_dAvailableMemory <= ((double)OSParameter.MINIMUM_MEMORY_TRIGGER)){
			if(m_iCurrentJobCount > 0){
				m_sCurrentState = "busy";				
			}
			else{
				m_sCurrentState = "idleButNotAccepting";
			}
		}
		else{
			if(m_iCurrentJobCount == 0){
				m_sCurrentState = "idle";
			}
			else if(m_iCurrentJobCount >= OSParameter.MAX_JOB_NUMBERS){
				m_sCurrentState = "busy";
			}
			else{
				m_sCurrentState = "busyButAccepting";
			}
		}

		return true;
	}//updateProcessStatistics
		
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] args){
		
	}//main

	/**
	 * <P>The <code>SolverThread</code> class is an internal thread controlled by <code>OSServiceUtil</code>.
	 */
	protected class SolverThread implements Runnable{
		
		/**
		 * m_bCalledFromSend holds whether the SolverThread is called from solve or send. 
		 */
		protected boolean m_bCalledFromSend = false; 
		
		/**
		 * m_msURIs holds the found service URIs. 
		 */
		protected String[] m_msURIs = null;
		
		/**
		 * m_sOSiL holds the osil string.
		 */
		protected String m_sOSiL = null;

		/**
		 * m_sOSoL holds the osol string.
		 */
		protected String m_sOSoL = null;
		
		/**
		 * m_osOption holds the parsed OSOption data structure read from the OSoL string.
		 */
		protected OSOption m_osOption = null;
		
		/**
		 * m_sOSrL holds osrl string.
		 */
		protected String m_sOSrL = null;
 
		/**
		 * default constructor.
		 */
		protected SolverThread(){
		}//constructor

		/**
		 * A synchronous solve method is implemented here. 
		 */
		public void run(){
			//Monitor.Enter(this);
			Thread thread = Thread.currentThread();
			String sTime = XMLUtil.createXSDateTime(new GregorianCalendar());
			IOUtil.log("thread name: "+thread.getName()+":"+":"+ sTime, null);

			//updateRegistry
			updateRegistry(true);
			
			//save ospl
			saveOSpL();

			//solver
			if(serviceType == null || serviceType.length() <= 0 || 
					serviceType.equals("solver") || serviceType.equals("analyzer")){
				//make sure solver is registered
				if(solver == null){
					try {
						Class solverClass = Class.forName(OSParameter.SOLVER_CLASS_NAME);
						solver =(DefaultSolver)solverClass.newInstance();			
					} 
					catch (Exception e) {
						IOUtil.log(IOUtil.exceptionStackToString(e), null);
					}
				}
				if(solver != null){
					//presolve
					presolve(m_sOSiL, m_sOSoL);

					//prepare osol
					solver.osol = this.m_sOSoL;
					solver.osOption = m_osOption;
					
					//prepare osil
					if(m_sInstanceAddress != null && m_sInstanceAddress.length() > 0 && (m_sOSiL == null || m_sOSiL.length() <= 0)){
						if(m_sInstanceLocationType == null || m_sInstanceLocationType.length() <= 0 || m_sInstanceLocationType.equals("local")){
							if(OSParameter.SAVE_INPUTS){
								String sInstanceFile = OSParameter.TEMP_FILE_FOLDER+m_sJobID+".osil";
								boolean bCopy  = IOUtil.copyFile(m_sInstanceAddress, sInstanceFile);
								if(!bCopy){
									IOUtil.log("not able to copy file from " + m_sInstanceAddress + " to " +  sInstanceFile, null);	
								}							
							}
							m_sOSiL = IOUtil.readStringFromFile(m_sInstanceAddress);
							if(m_sOSiL == null || m_sOSiL.length() <= 0){
								m_sOSiL = "";
								IOUtil.log("not able to read from file " + m_sInstanceAddress, null);								
							}
						}
						else if(m_sInstanceLocationType.equals("http")){
							m_sOSiL = IOUtil.readStringFromURL(m_sInstanceAddress);
							if(m_sOSiL == null || m_sOSiL.length() <= 0){
								m_sOSiL = "";
								IOUtil.log("not able to read from file " + m_sInstanceAddress, null);								
							}
							if(OSParameter.SAVE_INPUTS){
								String sInstanceFile = OSParameter.TEMP_FILE_FOLDER+m_sJobID+".osil";
								boolean bSave  = IOUtil.writeStringToFile(m_sOSiL, sInstanceFile);
								if(!bSave){
									IOUtil.log("not able to save osil string to " +  sInstanceFile, null);	
								}							
							}
						}
					}
					try{
						solver.osil = this.m_sOSiL;
						if(solver.osInstance == null && solver.osil != null && solver.osil.length() > 0 && OSParameter.PARSE_INSTANCE_INPUT){
							OSiLReader osilReader = new OSiLReader(OSParameter.VALIDATE);
							boolean bRead = osilReader.readString(this.m_sOSiL);
							if(bRead){
								solver.osInstance = osilReader.getOSInstance();							
							}
						}				
					}
					catch(Exception e){}

					//start solve
					for(int i = 0; i < OSParameter.MAXIMUM_TRIAL_NUMBER_FOR_SOLVE; i++){
						try{
							/****for wait simulation****
							String sWait = m_osOption.getOtherOptionValues().get("wait");;
							if(sWait != null && sWait.equalsIgnoreCase("true")){
								try {
									Thread.sleep(15000); 
								} catch (InterruptedException e) {
									IOUtil.log(IOUtil.exceptionStackToString(e), null);
								}
							}
							****end wait simulation****/

							solver.solve();
							if(solver.osResult != null || (solver.osrl != null && solver.osrl.length() > 0)){
								break;
							}
						}
						catch(Exception e){
							IOUtil.log(IOUtil.exceptionStackToString(e), null);
						}
						if(i < OSParameter.MAXIMUM_TRIAL_NUMBER_FOR_SOLVE - 1){
							try {
								Thread.sleep((long)(Math.random()*
								(OSParameter.MAXIMUM_WAIT_TIME_BEFORE_NEXT_TRIAL-OSParameter.MINIMUM_WAIT_TIME_BEFORE_NEXT_TRIAL)
								+OSParameter.MINIMUM_WAIT_TIME_BEFORE_NEXT_TRIAL));
							} 
							catch (InterruptedException e){}
							catch (Exception e){}
						}

					}

					//prepare osrl
					try{
						if(solver.osResult != null && (solver.osrl == null || solver.osrl.length() <= 0)){
							try {
								solver.osrl = solver.osResult.writeOSrL();
							} 
							catch (Exception e) {
								IOUtil.log(IOUtil.exceptionStackToString(e), null);
							}
						}
						if(solver.osrl != null && solver.osrl.length() > 0){
							m_sOSrL = solver.osrl;
							String sResultFile = OSParameter.TEMP_FILE_FOLDER+m_sJobID+".osrl";
							boolean bWrite = IOUtil.writeStringToFile(m_sOSrL, sResultFile);
							if(!bWrite){
								IOUtil.log("standard output file not written successfully", null);
							}
						}
						else{
							IOUtil.log("no result returned from solver", null);
							m_osrlWriter = new OSrLWriter();
							m_osrlWriter.setGeneralStatusType("warning");
							m_osrlWriter.setGeneralStatusDescription("no result returned from the solver");
							m_osrlWriter.setServiceURI(OSParameter.SERVICE_URI);
							m_osrlWriter.setServiceName(OSParameter.SERVICE_NAME);
							m_osrlWriter.setJobID(m_sJobID);
							m_osrlWriter.setResultTime(new GregorianCalendar());
							m_sOSrL = m_osrlWriter.writeToString();
						}
					}
					catch(Exception e){
						IOUtil.log(IOUtil.exceptionStackToString(e), null);
						m_osrlWriter = new OSrLWriter();
						m_osrlWriter.setGeneralStatusType("error");
						m_osrlWriter.setGeneralStatusDescription(e.getMessage());
						m_osrlWriter.setServiceURI(OSParameter.SERVICE_URI);
						m_osrlWriter.setServiceName(OSParameter.SERVICE_NAME);
						m_osrlWriter.setJobID(m_sJobID);
						m_osrlWriter.setResultTime(new GregorianCalendar());
						m_osrlWriter.setGeneralMessage(IOUtil.exceptionStackToString(e));
						m_sOSrL = m_osrlWriter.writeToString();
						String sResultFile = OSParameter.TEMP_FILE_FOLDER+m_sJobID+".osrl";
						boolean bWrite = IOUtil.writeStringToFile(m_sOSrL, sResultFile);
						if(!bWrite){
							IOUtil.log("standard output file not written successfully", null);
						}
					}

					//postsolve
					postsolve();

					//postprocess
					postprocess(false);

				}
				else{//no solver engine

					postprocess(true);							
				}
			}//solver
			
			//scheduler
			else{
				int iURI = (m_msURIs == null)?0:m_msURIs.length;
				//save inputs
				String sInstanceFile = OSParameter.TEMP_FILE_FOLDER+m_sJobID+".osil";
				String sOptionFile = OSParameter.TEMP_FILE_FOLDER+m_sJobID+".osol";
				boolean bWrite = true;
				if(!IOUtil.existsFileOrDir(sInstanceFile)){
					bWrite = IOUtil.writeStringToFile(m_sOSiL, sInstanceFile);
				}
				if(!bWrite){
					IOUtil.log("the solve method is not able to write osil to file", null);
					IOUtil.deleteFile(sInstanceFile);
				}
				bWrite = true;
				if(!IOUtil.existsFileOrDir(sOptionFile)){
					bWrite = IOUtil.writeStringToFile(m_sOSoL, sOptionFile);
				}
				if(!bWrite){
					IOUtil.log("the solve method is not able to write osol to file", null);
					IOUtil.deleteFile(sOptionFile);
				}

				JobStatistics jobStatistics  = m_jobStatisticsTable.get(m_sJobID);
				if(jobStatistics == null){
					initializeStatistics();
					jobStatistics  = m_jobStatisticsTable.get(m_sJobID);
				}

				//called from send
				if(m_bCalledFromSend){
					boolean bSend = false;
					for(int i = 0; i < iURI; i++){
						try {
							String sServiceType = m_osOption.getServiceType();
							String sContactTransportType = m_osOption.getServiceType();
							String sContactAddress = m_osOption.getContactAddress();
							m_osOption.setServiceType("scheduler");	
							m_osOption.setContactTransportType("osp");
							m_osOption.setContactAddress(OSParameter.SERVICE_URI);
							String sOSoL = m_osOption.writeOSoL();
							m_osOption.setServiceType(sServiceType);	
							m_osOption.setContactTransportType(sContactTransportType);
							m_osOption.setContactAddress(sContactAddress);

							
							OSSolverAgent solverAgent = new OSSolverAgent();
							solverAgent.solverAddress = m_msURIs[i];
							jobStatistics.serviceURI = m_msURIs[i];
							bSend = solverAgent.send(m_sOSiL, sOSoL);
							if(bSend){
								break;
							}
							else{
								IOUtil.log("job not sent successfully", null);
							}
						}
						catch (Exception e) {
							IOUtil.log(IOUtil.exceptionStackToString(e), null);
						}
					}
					if(bSend){
						m_threadHashTable.remove(m_sJobID);
						m_solverThreadHashTable.remove(m_sJobID);
						processsHashTable.remove(m_sJobID);
						m_vWaitingJobIDs.remove(m_sJobID);
						m_vCurrentJobIDs.remove(m_sJobID);
						m_vCurrentJobIDs.add(m_sJobID);						
						m_iCurrentJobCount = m_vCurrentJobIDs.size();
						
						if(m_iCurrentJobCount >= OSParameter.MAX_JOB_NUMBERS){
							m_sCurrentState = "busy";
						}
						else if(m_iCurrentJobCount > 0){
							m_sCurrentState = "busyButAccepting";
						}
						else {
							m_sCurrentState = "idle";
						}

						jobStatistics.jobID = m_sJobID;
						jobStatistics.state = "running";
						m_sJobState = jobStatistics.state;
						if(jobStatistics.userName == null || jobStatistics.userName.length() <= 0){
							jobStatistics.userName = m_sUserName;									
						}
						if(jobStatistics.submitTime == null || jobStatistics.submitTime.get(GregorianCalendar.YEAR) <= 1970){
							jobStatistics.submitTime = new GregorianCalendar(); 
						}
						m_lJobSubmitTime = jobStatistics.submitTime.getTimeInMillis();			

						jobStatistics.startTime = new GregorianCalendar(); 
						m_lJobStartTime = jobStatistics.startTime.getTimeInMillis();

						jobStatistics.endTime = new GregorianCalendar(1970, 0, 1, 0, 0, 0); 
						m_lJobEndTime = -1;

						jobStatistics.duration = Double.NaN;
						m_lJobDuration = -1;						
					}
					else{
						//put on wait list
						m_threadHashTable.remove(m_sJobID);
						m_solverThreadHashTable.remove(m_sJobID);
						processsHashTable.remove(m_sJobID);
						m_vCurrentJobIDs.remove(m_sJobID);
						m_vWaitingJobIDs.remove(m_sJobID);
						m_vWaitingJobIDs.add(m_sJobID);		
						m_iCurrentJobCount = m_vCurrentJobIDs.size();
						
						if(m_iCurrentJobCount >= OSParameter.MAX_JOB_NUMBERS){
							m_sCurrentState = "busy";
						}
						else if(m_iCurrentJobCount > 0){
							m_sCurrentState = "busyButAccepting";
						}
						else {
							m_sCurrentState = "idle";
						}

						jobStatistics.jobID = m_sJobID;
						jobStatistics.state = "waiting";
						m_sJobState = jobStatistics.state;
						jobStatistics.serviceURI = "";			
						if(jobStatistics.userName == null || jobStatistics.userName.length() <= 0){
							jobStatistics.userName = m_sUserName;									
						}						
						if(jobStatistics.submitTime == null || jobStatistics.submitTime.get(GregorianCalendar.YEAR) <= 1970){
							jobStatistics.submitTime = new GregorianCalendar(); 
						}
						m_lJobSubmitTime = jobStatistics.submitTime.getTimeInMillis();			

						jobStatistics.startTime = new GregorianCalendar(1970, 0, 1, 0, 0, 0); 
						m_lJobStartTime = -1;

						jobStatistics.endTime = new GregorianCalendar(1970, 0, 1, 0, 0, 0); 
						m_lJobEndTime = -1;

						jobStatistics.duration = Double.NaN;
						m_lJobDuration = -1;
					}
					
					//save ospl
					saveOSpL();

					
					//updateRegistry
					updateRegistry(true);
					
				}
				//called from solve
				else{
					boolean bSolved = false;
					boolean bWarning = false;
					for(int i = 0; i < iURI; i++){
						try {
							String sServiceType = m_osOption.getServiceType();
							String sContactTransportType = m_osOption.getServiceType();
							String sContactAddress = m_osOption.getContactAddress();
							m_osOption.setServiceType("scheduler");	
							m_osOption.setContactTransportType("osp");
							m_osOption.setContactAddress(OSParameter.SERVICE_URI);
							String sOSoL = m_osOption.writeOSoL();
							m_osOption.setServiceType(sServiceType);	
							m_osOption.setContactTransportType(sContactTransportType);
							m_osOption.setContactAddress(sContactAddress);


							OSSolverAgent solverAgent = new OSSolverAgent();
							solverAgent.solverAddress = m_msURIs[i];
							jobStatistics.serviceURI = m_msURIs[i];
							m_sOSrL = solverAgent.solve(m_sOSiL, sOSoL);
							if(m_sOSrL != null && m_sOSrL.length() > 0){
								try {
									OSrLReader osrlReader = new OSrLReader(m_bValidate);
									boolean bRead = osrlReader.readString(m_sOSrL);
									if(bRead){
										bSolved = true;
										String sStatus = osrlReader.getGeneralStatusType();
										if(sStatus != null && sStatus.equals("warning")) bWarning = true;
										break;
									}
									else{
										IOUtil.log("result not read successfully", null);
									}
								} 
								catch (Exception e) {
									IOUtil.log(IOUtil.exceptionStackToString(e), null);
								}
							}
							else{
								IOUtil.log("empty result returned", null);
							}
						} 
						catch (Exception e) {
							IOUtil.log(IOUtil.exceptionStackToString(e), null);
						}
						//alwasy kill the remote process when the solve is finished. 
						//If the remote solver has already finished the job, it is ok as the remote solver will simply return. 
						KillThread killThread = new KillThread();
						OSSolverAgent osSolverAgent = new OSSolverAgent(m_msURIs[i]);
						killThread.m_osSolverAgent = osSolverAgent;
						killThread.m_sOSoL = m_sOSoL;
						
						Thread thread0 = new Thread(killThread);	
						thread0.start();
					}
					if(bSolved && !bWarning){
						String sResultFile = OSParameter.TEMP_FILE_FOLDER+m_sJobID+".osrl";
						bWrite = IOUtil.writeStringToFile(m_sOSrL, sResultFile);
						if(!bWrite){
							IOUtil.log("not able to save file " + m_sJobID, null);
						}							
					}
					else{
						IOUtil.log("not able to get a solver to solve the problem", null);
						m_osrlWriter = new OSrLWriter();
						m_osrlWriter.setGeneralStatusType("warning");
						m_osrlWriter.setGeneralStatusDescription("not able to get a solver to solve the problem");
						m_osrlWriter.setServiceURI(OSParameter.SERVICE_URI);
						m_osrlWriter.setServiceName(OSParameter.SERVICE_NAME);
						m_osrlWriter.setJobID(m_sJobID);
						m_osrlWriter.setResultTime(new GregorianCalendar());
						m_sOSrL = m_osrlWriter.writeToString();
					}
					//postprocess
					postprocess(false);
				}
			}//scheduler		
			
			//Monitor.Pulse(this);
			//Monitor.Exit(this);	
		}//run
	}//class SolverThread
	
	/**
	 * <P>The <code>SimulationThread</code> class is an internal thread controlled by <code>OSServiceUtil</code>.
	 */
	protected class SimulationThread implements Runnable{

		/**
		 * m_sOSsLInput holds the ossl input string.
		 */
		protected String m_sOSsLInput = null;
	
		/**
		 * m_sOSoL holds the osol string.
		 */
		protected String m_sOSoL = null;

		/**
		 * m_sOSsLOutput holds the ossl output string.
		 */
		protected String m_sOSsLOutput = null;

		/**
		 * m_simulation holds the simulation engine.
		 */
		protected DefaultSimulation m_simulation = null;
 
		/**
		 * default constructor.
		 *
		 */
		protected SimulationThread(){
		}//constructor
		
		/**
		 * A synchronous simulation call method is implemented here. 
		 * @throws Exception 
		 *
		 */
		public void run(){
			//Monitor.Enter(this);	
			Thread thread = Thread.currentThread();
			String sTime = XMLUtil.createXSDateTime(new GregorianCalendar());
			IOUtil.log("thread name:"+thread.getName()+":"+":"+sTime, null);

			try{
				m_simulation.osslInput = this.m_sOSsLInput;
				if(m_simulation.osSimulationInput == null && m_simulation.osslInput != null){
					OSsLReader osslReader = new OSsLReader(OSParameter.VALIDATE);
					osslReader.readString(this.m_sOSsLInput);
					m_simulation.osSimulationInput = osslReader.getOSSimulation();
				}				
			}
			catch(Exception e){
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
			try{
				m_simulation.osol = this.m_sOSoL;
				if(m_simulation.osOption == null && m_simulation.osol != null){
					OSoLReader osolReader = new OSoLReader(OSParameter.VALIDATE);
					osolReader.readString(this.m_sOSoL);
					m_simulation.osOption = osolReader.getOSOption();
				}				
			}
			catch(Exception e){
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
			
			try{
				m_simulation.call();
			}
			catch(Exception e){
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
			
			try{
				if(m_simulation.osslOutput != null){
					m_sOSsLOutput = m_simulation.osslOutput;
				}
				else if(m_simulation.osSimulationOutput != null){
					OSsLWriter osslWriter = new OSsLWriter();
					osslWriter.setOSSimulation(m_simulation.osSimulationOutput);
					m_simulation.osslOutput = osslWriter.writeToString();
				}
				else{
					throw new Exception("no result returned");
				}
			}
			catch(Exception e){
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}//call
	}//class SimulationThread

	/**
	 * <P>The <code>ServiceTask1</code> class is an internal 
	 * timer task class called by <code>OSServiceUtil</code>.
	 * It is carried out in short intervals periodically.  
	 */
    protected static class ServiceTask1 extends TimerTask { 
    	/**
    	 * Specifies the task to run. 
    	 */
        public void run() {
    		//process waiting jobs
	    	ProcessWaitingJobsThread processWaitingJobsThread = new ProcessWaitingJobsThread();	
	    	Thread thread = new Thread(processWaitingJobsThread);	
	    	thread.start();	
	    	
	    	//send periodic warning
			if(m_dAvailableDiskSpace <= OSParameter.MINIMUM_DISKSPACE_TRIGGER ){
				if(!m_bSendEmailOnLowDiskSpace){
					String sMessage = "System warning: service (" + (OSParameter.SERVICE_URI) +") is running low on disk space (" + m_dAvailableDiskSpace + ")";
					MailUtil.sendInThread(OSParameter.FROM_EMAIL, OSParameter.TO_EMAIL, null, null, "System Warning: low disk space", sMessage, null);
					m_bSendEmailOnLowDiskSpace = true;
				}
			}
			else{
				m_bSendEmailOnLowDiskSpace = false;
			}

        	//save ospl
			saveOSpL();
          }//run
    }//class ServiceTask1
    
	/**
	 * <P>The <code>ServiceTask3</code> class is an internal 
	 * timer task class called by <code>OSServiceUtil</code>.
	 * It is carried out periodically in intervals that are neither too short nor too long. 
	 */
    protected static class ServiceTask2 extends TimerTask {
    	/**
    	 * Specifies the task to run. 
    	 */
        public void run() {     
        	//when idle periodically request job from solver to scheduler?
        	//periodically check registry against the accepting solver table?
        	
        	
			//update process statistics
			updateProcessStatistics();

        	//clear up jobs (from memory and disks)
        	//remove and kill long waiting and running jobs
        	clearUpJobs();


        	//clean up disk
            IOUtil.cleanUpDisk();

            //save ospl
            saveOSpL();

            //check scheduler's current jobs statistics
            if(OSParameter.SERVICE_TYPE != null && OSParameter.SERVICE_TYPE.equals("scheduler")){
            	int iCurrentJobs = (m_vCurrentJobIDs==null?0:m_vCurrentJobIDs.size());
            	String[] msCurrentJobIDs = new String[iCurrentJobs];
            	for(int i = iCurrentJobs-1; i >= 0; i--){
            		try{
            			msCurrentJobIDs[i] = m_vCurrentJobIDs.elementAt(i);
            		}
            		catch(Exception e){
            			msCurrentJobIDs[i] = "";
            		}
            	}
	    		for(int i = 0; i < iCurrentJobs; i++){
	    			String sJobID = msCurrentJobIDs[i];
	    			if(sJobID == null || sJobID.length() <= 0){
	    				continue;
	    			}
	    			if(!m_vCurrentJobIDs.contains(sJobID)){
	    				continue;
	    			}  
		            CheckSchedulerCurrentJobsThread checkSchedulerCurrentJobsThread = new CheckSchedulerCurrentJobsThread();	
		            checkSchedulerCurrentJobsThread.m_sCurrentJobID = sJobID;
			    	Thread thread = new Thread(checkSchedulerCurrentJobsThread);	
			    	thread.start();	
	    		}
            }
        }//run
    }//class ServiceTask2
    

	/**
	 * <P>The <code>ServiceTask3</code> class is an internal 
	 * timer task class called by <code>OSServiceUtil</code>.
	 * It is carried out periodically in long intervals. 
	 */
    protected static class ServiceTask3 extends TimerTask {
    	/**
    	 * Specifies the task to run. 
    	 */
        public void run(){
			try{
				m_dAvailableDiskSpace = IOUtil.getFreeDiskSpace(OSParameter.CODE_DRIVE);	
			}
			catch(Exception e){
				m_dAvailableDiskSpace = Double.POSITIVE_INFINITY;
			}
			try{
				System.gc();
				m_dAvailableMemory = ProcessUtil.getFreeMemory();	
			}
			catch(Exception e){
				m_dAvailableMemory = Double.POSITIVE_INFINITY;
			}
        	saveOSpL();
        	//send process info to admin. 
			String sSubject = "Service Status [" + OSParameter.SERVICE_URI + "]";
			String sProcessFileName = OSParameter.PROCESS_FILE+"_backup";
			String sMessage = IOUtil.readStringFromFile(sProcessFileName);
			if(sMessage == null || sMessage.length() <= 0){
				sMessage = "Not able to retrieve process info of the service [" + OSParameter.SERVICE_URI + "]"; 
			}
			MailUtil.sendInThread(OSParameter.FROM_EMAIL, OSParameter.TO_EMAIL, null, null, sSubject, sMessage, null );					

        }//run
    }//class ServiceTask3
    

	/**
	 * static constructor
	 */
	static {//TODO coordinate with registry
		if(OSParameter.SERVICE_TYPE == null || !OSParameter.SERVICE_TYPE.equals("registry")){
			m_sSystemPassword = OSParameter.getSystemPassword();
	
			m_lTimeServiceStarted = System.currentTimeMillis();
			try{
				m_dAvailableDiskSpace = IOUtil.getFreeDiskSpace(OSParameter.CODE_DRIVE);	
			}
			catch(Exception e){
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
				m_dAvailableDiskSpace = Double.POSITIVE_INFINITY;
			}
			try{
				m_dAvailableMemory = ProcessUtil.getFreeMemory();	
			}
			catch(Exception e){
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
				m_dAvailableMemory = Double.POSITIVE_INFINITY;
			}
			//load ospl information from backup file if it is more updated
			OSpLReader osplReader = new OSpLReader();
			String sFileName = OSParameter.PROCESS_FILE;
			String sBackupFileName = sFileName+"_backup";
			try {
				if((!IOUtil.existsFileOrDir(sFileName) && IOUtil.existsFileOrDir(sBackupFileName)) || 
						(IOUtil.existsFileOrDir(sBackupFileName) && IOUtil.getLastWriteTime(sBackupFileName) > IOUtil.getLastWriteTime(sFileName))){
					IOUtil.copyFile(sBackupFileName, sFileName);				
				}
				if(IOUtil.existsFileOrDir(sFileName)){
					boolean bRead = osplReader.readFile(sFileName);
					if(bRead){
						ProcessStatistics processStatistics = osplReader.getProcessStatistics();
						JobStatistics[] mJobStatistics = (processStatistics==null || processStatistics.jobs==null)?null:processStatistics.jobs.job;
						
						int iJobs = mJobStatistics==null?0:mJobStatistics.length;
						
						
						for(int i = iJobs-1; i >= 0; i--){						
							if(mJobStatistics[i] != null && mJobStatistics[i].jobID != null && mJobStatistics[i].jobID.length() > 0){
								if(m_jobStatisticsTable.containsKey(mJobStatistics[i].jobID)){
									continue;
								}
								m_jobStatisticsTable.put(mJobStatistics[i].jobID, mJobStatistics[i]);
								if(mJobStatistics[i].state == null || mJobStatistics[i].state.length() <= 0 || mJobStatistics[i].state.equals("unknown")){
									mJobStatistics[i].state = "waiting";
								}
								if(mJobStatistics[i].state.equals("finished") || mJobStatistics[i].state.equals("killed")){
									m_vFinishedJobIDs.remove(mJobStatistics[i].jobID);
									m_vFinishedJobIDs.add(mJobStatistics[i].jobID);
								}
								else{
									m_iTotalJobsSoFar++;
									String sUserName = mJobStatistics[i].userName;
									if(sUserName == null){
										sUserName = "";
									}
									String sCount = m_userJobCountTable.get(sUserName);
									int iCount;
									if(sCount == null || sCount.length() <= 0){
										iCount = 0;
									}
									else{
										try {
											iCount = Integer.parseInt(sCount);					
										} 
										catch (Exception e) {
											iCount = 0;
										}
										if(iCount < 0) iCount = 0;
									}
									iCount += 1;
									m_userJobCountTable.remove(sUserName);
									m_userJobCountTable.put(sUserName, iCount+"");
								}
								if(mJobStatistics[i].state.equals("waiting") || mJobStatistics[i].state.equals("unknown")){ 
									m_vWaitingJobIDs.remove(mJobStatistics[i].jobID);
									m_vWaitingJobIDs.add(mJobStatistics[i].jobID);
									mJobStatistics[i].state = "waiting";
								}
								if(mJobStatistics[i].state.equals("running")){
									if(OSParameter.SERVICE_TYPE == null || !OSParameter.SERVICE_TYPE.equals("scheduler")){
										m_vWaitingJobIDs.remove(mJobStatistics[i].jobID);
										m_vWaitingJobIDs.add(mJobStatistics[i].jobID);
										mJobStatistics[i].state = "waiting";
									}
									else{
										if(mJobStatistics[i].serviceURI == null || mJobStatistics[i].serviceURI.length() <= 0){
											m_vWaitingJobIDs.remove(mJobStatistics[i].jobID);
											m_vWaitingJobIDs.add(mJobStatistics[i].jobID);
											mJobStatistics[i].state = "waiting";										
										}
										else{
											m_vCurrentJobIDs.remove(mJobStatistics[i].jobID);
											m_vCurrentJobIDs.add(mJobStatistics[i].jobID);
										}
									}
								}
							}					
						}
						m_iCurrentJobCount = m_vCurrentJobIDs.size();
						if(m_iCurrentJobCount == 0){
							m_sCurrentState = "idle";
						}
						else if(m_iCurrentJobCount >= OSParameter.MAX_JOB_NUMBERS){
							m_sCurrentState = "busy";
						}
						else{
							m_sCurrentState = "busyButAccepting";
						}
					}
				}
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
			
			saveOSpL();
			
			new OSServiceUtil().updateRegistry(false);
			
			timer = new Timer();
			timer.schedule(new ServiceTask1(), 0, OSParameter.SERVICE_POLLING_INTERVAL_SHORT);
			timer.schedule(new ServiceTask2(), 1, OSParameter.SERVICE_POLLING_INTERVAL_MEDIUM);
			timer.schedule(new ServiceTask3(), 2, OSParameter.SERVICE_POLLING_INTERVAL_LONG);
		}
	}//static constructor.
}//OSServiceUtil
