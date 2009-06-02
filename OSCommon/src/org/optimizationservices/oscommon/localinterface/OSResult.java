/**
 * @(#)OSResult 1.0 03/14/2005
 *
 * Copyright (c) 2005 
 */
package org.optimizationservices.oscommon.localinterface;

import java.util.GregorianCalendar;
import java.util.Vector;

import org.optimizationservices.oscommon.datastructure.osresult.CPUNumber;
import org.optimizationservices.oscommon.datastructure.osresult.CPUSpeed;
import org.optimizationservices.oscommon.datastructure.osresult.ConstraintSolution;
import org.optimizationservices.oscommon.datastructure.osresult.DiskSpace;
import org.optimizationservices.oscommon.datastructure.osresult.DualVarValue;
import org.optimizationservices.oscommon.datastructure.osresult.DualVariableValues;
import org.optimizationservices.oscommon.datastructure.osresult.GeneralResult;
import org.optimizationservices.oscommon.datastructure.osresult.GeneralStatus;
import org.optimizationservices.oscommon.datastructure.osresult.JobResult;
import org.optimizationservices.oscommon.datastructure.osresult.MemorySize;
import org.optimizationservices.oscommon.datastructure.osresult.ObjValue;
import org.optimizationservices.oscommon.datastructure.osresult.ObjectiveSolution;
import org.optimizationservices.oscommon.datastructure.osresult.ObjectiveValues;
import org.optimizationservices.oscommon.datastructure.osresult.OptimizationResult;
import org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolution;
import org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolutionStatus;
import org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolutionSubstatus;
import org.optimizationservices.oscommon.datastructure.osresult.OtherConstraintResult;
import org.optimizationservices.oscommon.datastructure.osresult.OtherObjectiveResult;
import org.optimizationservices.oscommon.datastructure.osresult.OtherResult;
import org.optimizationservices.oscommon.datastructure.osresult.OtherResults;
import org.optimizationservices.oscommon.datastructure.osresult.OtherSolutionResult;
import org.optimizationservices.oscommon.datastructure.osresult.OtherSolverOutput;
import org.optimizationservices.oscommon.datastructure.osresult.OtherVariableResult;
import org.optimizationservices.oscommon.datastructure.osresult.ServiceResult;
import org.optimizationservices.oscommon.datastructure.osresult.SolutionResults;
import org.optimizationservices.oscommon.datastructure.osresult.SolverOutput;
import org.optimizationservices.oscommon.datastructure.osresult.SystemResult;
import org.optimizationservices.oscommon.datastructure.osresult.TimingInformation;
import org.optimizationservices.oscommon.datastructure.osresult.VarStringValue;
import org.optimizationservices.oscommon.datastructure.osresult.VarValue;
import org.optimizationservices.oscommon.datastructure.osresult.VariableSolution;
import org.optimizationservices.oscommon.datastructure.osresult.VariableStringValues;
import org.optimizationservices.oscommon.datastructure.osresult.VariableValues;
import org.optimizationservices.oscommon.representationparser.OSrLReader;
import org.optimizationservices.oscommon.representationparser.OSrLWriter;
import org.optimizationservices.oscommon.util.XMLUtil;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;

/**
 *
 * <P>The <code>OSResult</code> class is a local interface for storing Optimization Services
 * problem result. Its design follows the Optimization Services result Language (OSrL). 
 * All the data structures in this class are standards specified in OSrL. 
 * Developers can add service-specific results by extending this class.  
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2005
 * @see org.optimizationservices.oscommon.localinterface.OSInstance
 * @see org.optimizationservices.oscommon.localinterface.OSAnalysis
 * @see org.optimizationservices.oscommon.localinterface.OSOption
 * @since OS 1.0
 */
public class OSResult {

	/**
	 * general holds the general result specified by the OSrL Schema. 
	 */
	public GeneralResult general = new GeneralResult();

	/**
	 * system holds the system result specified by the OSrL Schema. 
	 */
	public SystemResult system = new SystemResult();

	/**
	 * service holds the service result specified by the OSrL Schema. 
	 */
	public ServiceResult service = new ServiceResult();


	/**
	 * job holds the job result specified by the OSrL Schema. 
	 */
	public JobResult job = new JobResult();

	/**
	 * optimization holds the optimization result specified by the OSrL Schema. 
	 */
	public OptimizationResult optimization = new OptimizationResult();	
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
	 * m_iSolutionNumber holds the solution number. 
	 */
	private int m_iSolutionNumber = -1;

	/**
	 *
	 * Default constructor. 
	 */
	public OSResult(){
	}//constructor

	/**
	 * read an OSrL instance and return and OSResult object.  
	 * 
	 * @param osrl holds the optimization result in a string which format follows the
	 * Optimization Services result Language (OSrL) schema.
	 * @param isFile holds whether the osrl string is a file name or a string that literally holds the osrl contents.  
	 * @param validate holds whether the reader should be validating against the schema or not.
	 * @return the OSResult object constructed from the OSrL String.  
	 * @throws Exception if there are errors in reading the string or setting the OSResult. 
	 */
	public OSResult readOSrL(String osrl, boolean isFile, boolean validate) throws Exception{
		OSrLReader osrlReader = new OSrLReader(validate);
		boolean bRead = false;
		if(isFile){
			bRead = osrlReader.readFile(osrl);
		}
		else{
			bRead = osrlReader.readString(osrl);			
		}
		if(!bRead) throw new Exception("OSrL string not valid");
		return osrlReader.getOSResult();
	}//readOSrL

	/**
	 * write the OSResult to an osrl xml string. 
	 * 
	 * @return the osrl xml string. 
	 * @throws Exception if there are errors in writing the osrl string. 
	 */
	public String writeOSrL() throws Exception{
		OSrLWriter osrlWriter = new OSrLWriter();
		osrlWriter.setOSResult(this);
		return osrlWriter.writeToString();
	}//writeOSrL

	/**
	 * Get the general status.
	 * 
	 * @return the general status. 
	 */
	public GeneralStatus getGeneralStatus(){
		return general.generalStatus;
	}//getGeneralStatus

	/**
	 * Set the general status
	 * 
	 * @param status holds the general status.
	 * @return whether the general status is set successfully. 
	 */
	public boolean setGeneralStatus(GeneralStatus status){
		general.generalStatus = status;
		return true;
	}//setGeneralStatus

	/**
	 * Get the general status type, which can be: 
	 * success, error, warning. 
	 * 
	 * @return the general status type, null if none. 
	 */
	public String getGeneralStatusType(){
		if(general.generalStatus == null) return null;
		return general.generalStatus.type;
	}//getGeneralStatusType

	/**
	 * Set the general status type, which can be: 
	 * success, error, warning. 
	 * 
	 * @param type holds the general status type
	 * @return whether the general status type is set successfully or not. 
	 */
	public boolean setGeneralStatusType(String type){
		if(general.generalStatus == null) general.generalStatus = new GeneralStatus();
		general.generalStatus.type = type;
		return true;
	}//setGeneralStatusType

	/**
	 * Get the general status description. 
	 * 
	 * @return the general status description, null or empty string if none. 
	 */
	public String getGeneralStatusDescription(){
		if(general.generalStatus == null) return null;
		return general.generalStatus.description;
	}//getGeneralStatusDescription

	/**
	 * Set the general status description. 
	 * 
	 * @param description holds the general status description.
	 * @return whether the general status description is set successfully or not. 
	 */
	public boolean setGeneralStatusDescription(String description){
		if(general.generalStatus == null) general.generalStatus = new GeneralStatus();
		general.generalStatus.description = description;
		return true;
	}//setGeneralStatusDescription

	/**
	 * Get the general message. 
	 * 
	 * @return the general message. 
	 */
	public String getGeneralMessage(){
		return general.message;
	}//getGeneralMessage

	/**
	 * Set the general message. 
	 * 
	 * @param message holds the general message. 
	 * @return whether process message is set successfully. 
	 */
	public boolean setGeneralMessage(String message){
		general.message = message;
		return true;
	}//setGeneralMessage

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
	 * Get the job id.
	 * 
	 * @return the job id. 
	 */
	public String getJobID(){
		return general.jobID;
	}//getJobID

	/**
	 * Set job id.
	 * 
	 * @param jobID holds the job id. 
	 * @return whether the job id is set successfully. 
	 */
	public boolean setJobID(String jobID){
		general.jobID = jobID;
		return true;
	}//setJobID

	/**
	 * Get the solver invoked.
	 * 
	 * @return the solverInvoked. 
	 */
	public String getSolverInvoked(){
		return general.solverInvoked;
	}//getSolverInvoked

	/**
	 * Set solver invoked.
	 * 
	 * @param solverInvoked holds the solver invoked. 
	 * @return whether the solverInvoked is set successfully. 
	 */
	public boolean setSolverInvoked(String solverInvoked){
		general.solverInvoked = solverInvoked;
		return true;
	}//setSolverInvoked

	/**
	 * Get time stamp of the result.
	 * 
	 * @return the time stamp of the result.
	 */
	public GregorianCalendar getResultTimeStamp(){
		return general.timeStamp;
	}//getResultTimeStamp


	/**
	 * Set time  stamp of the result.
	 * 
	 * @param timeStamp holds the time of the result.
	 * @return whether result time stamp is set successfully. 
	 */
	public boolean setResultTimeStamp(GregorianCalendar timeStamp){
		general.timeStamp = timeStamp;
		return true;
	}//setResultTimeStamp

	/**
	 * get the number of other <general> results
	 * 
	 * @return the number of other <general> results
	 */
	public int  getNumberOfOtherGeneralResults(){
		if(general.otherResults == null) return 0;
		else return general.otherResults.numberOfOtherResults;
	}//getNumberOfOtherGeneralResults

	/**
	 * Set the number of other general results. 
	 * 
	 * @param numberOfOtherGeneralResults holds the number of other general results
	 * @return whether the number is set successfully or not. 
	 */
	public boolean setNumberOfOtherGeneralResults(int numberOfOtherGeneralResults){
		if(numberOfOtherGeneralResults < 0) return false;
		if(general.otherResults == null) general.otherResults = new OtherResults();
		general.otherResults.numberOfOtherResults = numberOfOtherGeneralResults;
		return true;
	}//setNumberOfOtherGeneralResults

	/**
	 * get other <general> results
	 * 
	 * @return other <general> results
	 */
	public OtherResults  getOtherGeneralResults(){
		return general.otherResults;
	}//getOtherGeneralResults

	/**
	 * Set the other general results. 
	 * 
	 * @param otherGeneralResults holds the other general results
	 * @return whether the other general results is set successfully or not. 
	 */
	public boolean setOtherGeneralResults(OtherResults otherGeneralResults){
		general.otherResults = otherGeneralResults;
		return true;
	}//setOtherGeneralResults

	/**
	 * Set the other general results. 
	 * 
	 * @param otherGeneralResults holds the other general results in the structure of OtherResult
	 * @return whether the other general results is set successfully or not. 
	 */
	public boolean setOtherGeneralResults(OtherResult[] otherGeneralResults){
		if(general.otherResults == null){
			general.otherResults = new OtherResults();
		}
		general.otherResults.numberOfOtherResults = otherGeneralResults==null?0:otherGeneralResults.length;
		general.otherResults.other = otherGeneralResults;
		return true;
	}//setOtherGeneralResults

	/**
	 * Get the system information.
	 * 
	 * @return the system information. 
	 */
	public String getSystemInformation(){
		return system.systemInformation;
	}//getSystemInformation

	/**
	 * Set system information.
	 * 
	 * @param systemInformation. holds the system information.. 
	 * @return whether the systemInformation is set successfully. 
	 */
	public boolean setSystemInformation(String systemInformation){
		system.systemInformation = systemInformation;
		return true;
	}//setSystemInformation

	/**
	 * Get the system available disk space. 
	 * 
	 * @return the available system disk space 
	 */
	public DiskSpace getAvailableDiskSpace(){
		return system.availableDiskSpace;
	}//getAvailableDiskSpace

	/**
	 * Set the system available disk space.
	 * 
	 * @param diskSpace holds the  available disk space value, unit and description. 
	 * @return whether the available disk space is set successfully.
	 */
	public boolean setAvailableDiskSpace(DiskSpace diskSpace){
		system.availableDiskSpace = diskSpace;
		return true;
	}//setAvailableDiskSpace

	/**
	 * Get the system available memory. 
	 * 
	 * @return the available system memory. 
	 */
	public MemorySize getAvailableMemory(){
		return system.availableMemory;
	}//getAvailableMemory

	/**
	 * Set the system available memory.
	 * 
	 * @param availableMemory holds the  available memory value, unit, and description. 
	 * @return whether the available memory is set successfully.
	 */
	public boolean setAvailableMemory(MemorySize availableMemory){
		system.availableMemory = availableMemory;
		return true;
	}//setAvailableMemory

	/**
	 * Get the system available CPU Speed. 
	 * 
	 * @return the available system CPU Speed. 
	 */
	public CPUSpeed getAvailableCPUSpeed(){
		return system.availableCPUSpeed;
	}//getAvailableCPUSpeed

	/**
	 * Set the system available CPU Speed.
	 * 
	 * @param availableCPUSpeed holds the  available CPU Speed value, unit and description. 
	 * @return whether the available CPU Speed is set successfully.
	 */
	public boolean setAvailableCPUSpeed(CPUSpeed availableCPUSpeed){
		system.availableCPUSpeed = availableCPUSpeed;
		return true;
	}//setAvailableCPUSpeed

	/**
	 * Get the system available CPU Number. 
	 * 
	 * @return the available system CPU number, -1.0 if none. 
	 */
	public CPUNumber getAvailableCPUNumber(){
		return system.availableCPUNumber;
	}//getAvailableCPUNumber

	/**
	 * Set the system available CPU Number.
	 * 
	 * @param availableCPUNumber holds the  available CPU Number value and description. 
	 * @return whether the available CPU Number is set successfully.
	 */
	public boolean setAvailableCPUNumber(CPUNumber availableCPUNumber){
		system.availableCPUNumber = availableCPUNumber;
		return true;
	}//setAvailableCPUNumber

	/**
	 * get other <system> results
	 * 
	 * @return other <system> results
	 */
	public OtherResults  getOtherSystemResults(){
		return system.otherResults;
	}//getOtherSystemResults

	/**
	 * Set the other system results. 
	 * 
	 * @param otherSystemResults holds the other system results
	 * @return whether the other system results is set successfully or not. 
	 */
	public boolean setOtherSystemResults(OtherResults otherSystemResults){
		system.otherResults = otherSystemResults;
		return true;
	}//setOtherSystemResults

	/**
	 * get the number of other <system> results
	 * 
	 * @return the number of other <system> results
	 */
	public int  getNumberOfOtherSystemResults(){
		if(system.otherResults == null) return 0;
		else return system.otherResults.numberOfOtherResults;
	}//getNumberOfOtherSystemResults

	/**
	 * Set the number of other system results. 
	 * 
	 * @param numberOfOtherSystemResults holds the number of other system results
	 * @return whether the number is set successfully or not. 
	 */
	public boolean setNumberOfOtherSystemResults(int numberOfOtherSystemResults){
		if(numberOfOtherSystemResults < 0) return false;
		if(system.otherResults == null) system.otherResults = new OtherResults();
		system.otherResults.numberOfOtherResults = numberOfOtherSystemResults;
		return true;
	}//setNumberOfOtherSystemResults

	/**
	 * Set the other system results. 
	 * 
	 * @param otherSystemResults holds the other system results in the structure of OtherResult
	 * @return whether the other system results is set successfully or not. 
	 */
	public boolean setOtherSystemResults(OtherResult[] otherSystemResults){
		if(system.otherResults == null){
			system.otherResults = new OtherResults();
		}
		system.otherResults.numberOfOtherResults = otherSystemResults==null?0:otherSystemResults.length;
		system.otherResults.other = otherSystemResults;
		return true;
	}//setOtherSystemResults

	/**
	 * Get the current state, , which can be:
	 * "busy", "busyButAccepting", "idle", "idleButNotAccepting" and "noResponse".
	 * 
	 * @return the current status, "noResponse" if none.
	 */
	public String getCurrentState(){
		return service.currentState;
	}//getCurrentState

	/**
	 * Set the current state. 
	 * @param currentState holds the current state, which can be:
	 * "busy", "busyButAccepting", "idle", "idleButNotAccepting" or "noResponse".
	 * @return whether the current state is set successfully.
	 */
	public boolean setCurrentState(String currentState){
		if(!currentState.equals("busy") && 
				!currentState.equals("busyButAccepting") &&
				!currentState.equals("idle") &&
				!currentState.equals("idleButNotAccepting") &&
				!currentState.equals("noResponse")) return false;		 
		service.currentState = currentState;
		return true;
	}//setCurrentState

	/**
	 * Get the current job count. 
	 * @return the current job count, -1 if none. 
	 */
	public int getCurrentJobCount(){
		return service.currentJobCount;
	}//getCurrentJobCount

	/**
	 * Set the current job count. 
	 * @param currentJobCount holds the current job count. 
	 * @return whether the current job count is set successfully.
	 */
	public boolean setCurrentJobCount(int currentJobCount){
		service.currentJobCount = currentJobCount;
		return true;
	}//setCurrentJobCount

	/**
	 * Get the total jobs received so far. 
	 * @return the total jobs received so far, -1 if none. 
	 */
	public int getTotalJobsSoFar(){
		return service.totalJobsSoFar;
	}//getTotalJobsSoFar


	/**
	 * Set the total jobs received so far. 
	 * @param totalJobsSoFar holds the total jobs received so far. 
	 * @return whether the total jobs so far is set successfully.
	 */
	public boolean setTotalJobsSoFar(int totalJobsSoFar){
		service.totalJobsSoFar = totalJobsSoFar;
		return true;
	}//setTotalJobsSoFar

	/**
	 * Get the time the service started. 
	 * @return the time last job ended. If none, it returns unix creation time: GregorianCalendar(1970, 0, 1, 0, 0, 0). 
	 */
	public GregorianCalendar getTimeServiceStarted(){
		return service.timeServiceStarted;
	}//getTimeServiceStarted

	/**
	 * Set the time the service started. 
	 * @param timeServiceStarted holds the time the service started. 
	 * @return whether the time the service started is set successfully.
	 */
	public boolean setTimeServiceStarted(GregorianCalendar timeServiceStarted){
		service.timeServiceStarted = timeServiceStarted;
		return true;
	}//setTimeServiceStarted

	/**
	 * Get the service utilization ([0, 1]). 
	 * @return the time last job took, Double.NaN if none. 
	 */
	public double getServiceUtilization(){
		return service.serviceUtilization;
	}//getServiceUtilization

	/**
	 * Set the service utilization. 
	 * @param serviceUtilization holds the service utilization ([0, 1]). 
	 * @return whether the time last job took is set successfully.
	 */
	public boolean setServiceUtilization(double serviceUtilization){
		service.serviceUtilization = serviceUtilization;
		return true;
	}//setServiceUtilization

	/**
	 * get the number of other <service> results
	 * 
	 * @return the number of other <service> results
	 */
	public int  getNumberOfOtherServiceResults(){
		if(service.otherResults == null) return 0;
		else return service.otherResults.numberOfOtherResults;
	}//getNumberOfOtherServiceResults

	/**
	 * Set the number of other service results. 
	 * 
	 * @param numberOfOtherServiceResults holds the number of other service results
	 * @return whether the number is set successfully or not. 
	 */
	public boolean setNumberOfOtherServiceResults(int numberOfOtherServiceResults){
		if(numberOfOtherServiceResults < 0) return false;
		if(service.otherResults == null) service.otherResults = new OtherResults();
		service.otherResults.numberOfOtherResults = numberOfOtherServiceResults;
		return true;
	}//setNumberOfOtherServiceResults

	/**
	 * get other <service> results
	 * 
	 * @return other <service> results
	 */
	public OtherResults  getOtherServiceResults(){
		return service.otherResults;
	}//getOtherServiceResults

	/**
	 * Set the other service results. 
	 * 
	 * @param otherServiceResults holds the other service results
	 * @return whether the other service results is set successfully or not. 
	 */
	public boolean setOtherServiceResults(OtherResults otherServiceResults){
		service.otherResults = otherServiceResults;
		return true;
	}//setOtherServiceResults

	/**
	 * Set the other service results. 
	 * 
	 * @param otherServiceResults holds the other service results in the structure of OtherResult
	 * @return whether the other service results is set successfully or not. 
	 */
	public boolean setOtherServiceResults(OtherResult[] otherServiceResults){
		if(service.otherResults == null){
			service.otherResults = new OtherResults();
		}
		service.otherResults.numberOfOtherResults = otherServiceResults==null?0:otherServiceResults.length;
		service.otherResults.other = otherServiceResults;
		return true;
	}//setOtherServiceResults

	/**
	 * Get the job status, , which can be:
	 * "waiting", "running", "killed", "finished" and "unknown".
	 * 
	 * @return the current status, "unknown" if none.
	 */
	public String getJobStatus(){
		return job.status;
	}//getCurrentState

	/**
	 * Set the job status. 
	 * @param jobStatus holds the current state, which can be:
	 * "waiting", "running", "killed", "finished" and "unknown".
	 * @return whether the current state is set successfully.
	 */
	public boolean setJobStatus(String jobStatus){
		if(!jobStatus.equals("waiting") && 
				!jobStatus.equals("running") &&
				!jobStatus.equals("killed") &&
				!jobStatus.equals("finished") &&
				!jobStatus.equals("unknown")) return false;		 
		job.status = jobStatus;
		return true;
	}//setJobStatus

	/**
	 * Get the submit time. 
	 * @return the submit time If none, it returns unix creation time: GregorianCalendar(1970, 0, 1, 0, 0, 0). 
	 */
	public GregorianCalendar getJobSubmitTime(){
		return job.submitTime;
	}//getJobSubmitTime

	/**
	 * Set the submit time. 
	 * @param submitTime holds the job submit time. 
	 * @return whether the submit time is set successfully.
	 */
	public boolean setJobSubmitTime(GregorianCalendar submitTime){
		job.submitTime = submitTime;
		return true;
	}//setJobSubmitTime

	/**
	 * Get the scheduled start time. 
	 * @return the scheduled start time If none, it returns unix creation time: GregorianCalendar(1970, 0, 1, 0, 0, 0). 
	 */
	public GregorianCalendar getScheduledStartTime(){
		return job.scheduledStartTime;
	}//getScheduledStartTime

	/**
	 * Set the scheduled start time. 
	 * @param scheduledStartTime holds the job scheduled start time. 
	 * @return whether the scheduled start time is set successfully.
	 */
	public boolean setScheduledStartTime(GregorianCalendar scheduledStartTime){
		job.scheduledStartTime = scheduledStartTime;
		return true;
	}//setScheduledStartTime

	/**
	 * Get the actual start time. 
	 * @return the actual start time If none, it returns unix creation time: GregorianCalendar(1970, 0, 1, 0, 0, 0). 
	 */
	public GregorianCalendar getActualStartTime(){
		return job.actualStartTime;
	}//getActualStartTime

	/**
	 * Set the actual start time. 
	 * @param actualStartTime holds the job actual start time. 
	 * @return whether the actual start time is set successfully.
	 */
	public boolean setActualStartTime(GregorianCalendar actualStartTime){
		job.actualStartTime = actualStartTime;
		return true;
	}//setActualStartTime

	/**
	 * Get the job timing information. 
	 * @return the job timing information. 
	 */
	public TimingInformation getTimeInformation(){
		return job.timingInformation;
	}//getTimeInformation

	/**
	 * Set the timingInformation. 
	 * @param timingInformation holds the timing information. 
	 * @return whether the timingInformation is set successfully.
	 */
	public boolean setTimingInformation(TimingInformation timingInformation){
		job.timingInformation = timingInformation;
		return true;
	}//setTimingInformation

	/**
	 * Get the end time. 
	 * @return the end time If none, it returns unix creation time: GregorianCalendar(1970, 0, 1, 0, 0, 0). 
	 */
	public GregorianCalendar getEndTime(){
		return job.endTime;
	}//getEndTime

	/**
	 * Set the end time. 
	 * @param endTime holds the end time. 
	 * @return whether the endTime is set successfully.
	 */
	public boolean setEndTime(GregorianCalendar endTime){
		job.endTime = endTime;
		return true;
	}//setEndTime

	/**
	 * Get the system used CPU Speed value, unit and description. 
	 * 
	 * @return the used system CPU Speed. 
	 */
	public CPUSpeed getUsedCPUSpeed(){
		return job.usedCPUSpeed;
	}//getUsedCPUSpeed

	/**
	 * Set the job used CPU Speed.
	 * 
	 * @param usedCPUSpeed holds the used CPU Speed. 
	 * @return whether the used CPU Speed is set successfully.
	 */
	public boolean setUsedCPUSpeed(CPUSpeed usedCPUSpeed){
		job.usedCPUSpeed = usedCPUSpeed;
		return true;
	}//setUsedCPUSpeed


	/**
	 * Get the job used CPU Number value and description. 
	 * 
	 * @return the used job CPU number. 
	 */
	public CPUNumber getUsedCPUNumber(){
		return job.usedCPUNumber;
	}//getUsedCPUNumber

	/**
	 * Set the job used CPU Number.
	 * 
	 * @param usedCPUNumber holds the  used CPU Number value and description. 
	 * @return whether the used CPU Number is set successfully.
	 */
	public boolean setUsedCPUNumber(CPUNumber usedCPUNumber){
		job.usedCPUNumber = usedCPUNumber;
		return true;
	}//setUsedCPUNumber

	/**
	 * Get the job available disk space value, unit and description. 
	 * 
	 * @return the available job disk space. 
	 */
	public DiskSpace getUsedDiskSpace(){
		return job.usedDiskSpace;
	}//getUsedDiskSpace

	/**
	 * Set the job used disk space.
	 * 
	 * @param usedDiskSpace holds the  used disk space value, unit and description. 
	 * @return whether the used disk space is set successfully.
	 */
	public boolean setUsedDiskSpace(DiskSpace usedDiskSpace){
		job.usedDiskSpace = usedDiskSpace;
		return true;
	}//setUsedDiskSpace

	/**
	 * Get the job used memory value, unit and description. 
	 * 
	 * @return the used job memory. 
	 */
	public MemorySize getUsedMemory(){
		return job.usedMemory;
	}//getUsedMemory

	/**
	 * Set the job used memory.
	 * 
	 * @param usedMemory holds the  used memory value, unit and description. 
	 * @return whether the used memory is set successfully.
	 */
	public boolean setUsedMemory(MemorySize usedMemory){
		job.usedMemory = usedMemory;
		return true;
	}//setUsedMemory


	/**
	 * get the number of other <service> results
	 * 
	 * @return the number of other <job> results
	 */
	public int  getNumberOfOtherJobResults(){
		if(job.otherResults == null) return 0;
		else return job.otherResults.numberOfOtherResults;
	}//getNumberOfOtherJobResults

	/**
	 * Set the number of other job results. 
	 * 
	 * @param numberOfOtherJobResults holds the number of other job results
	 * @return whether the number is set successfully or not. 
	 */
	public boolean setNumberOfOtherJobResults(int numberOfOtherJobResults){
		if(numberOfOtherJobResults < 0) return false;
		if(job.otherResults == null) job.otherResults = new OtherResults();
		job.otherResults.numberOfOtherResults = numberOfOtherJobResults;
		return true;
	}//setNumberOfOtherJobResults

	/**
	 * get other <job> results
	 * 
	 * @return other <job> results
	 */
	public OtherResults  getOtherJobResults(){
		return job.otherResults;
	}//getOtherJobResults

	/**
	 * Set the other job results. 
	 * 
	 * @param otherJobResults holds the other job results
	 * @return whether the other job results is set successfully or not. 
	 */
	public boolean setOtherJobResults(OtherResults otherJobResults){
		job.otherResults = otherJobResults;
		return true;
	}//setOtherJobResults

	/**
	 * Set the other job results. 
	 * 
	 * @param otherJobResults holds the other job results in the structure of OtherResult
	 * @return whether the other job results is set successfully or not. 
	 */
	public boolean setOtherJobResults(OtherResult[] otherJobResults){
		if(job.otherResults == null){
			job.otherResults = new OtherResults();
		}
		job.otherResults.numberOfOtherResults = otherJobResults==null?0:otherJobResults.length;
		job.otherResults.other = otherJobResults;
		return true;
	}//setOtherJobResults
	
	/**
	 * Get variable number. 
	 * 
	 * @return variable number, -1 if no information. 
	 */
	public int getVariableNumber(){
		if(optimization == null){
			m_iVariableNumber = -1;
			return -1;
		}
		m_iVariableNumber = optimization.numberOfVariables;
		return m_iVariableNumber;
	}//getVariableNumber


	/**
	 * Set the variable number. 
	 * 
	 * @param variableNumber holds the number of variables
	 * @return whether the variable number is set successfully or not. 
	 */
	public boolean setVariableNumber(int variableNumber){
		if(variableNumber <= 0){
			m_iVariableNumber = -1;
			return true;
		}
		if(optimization == null) optimization = new OptimizationResult();
		optimization.numberOfVariables = variableNumber;
		m_iVariableNumber = variableNumber;
		return true;
	}//setVariableNumber

	/**
	 * Get objective number. 
	 * 
	 * @return objective number, -1 if no information. 
	 */
	public int getObjectiveNumber(){
		if(optimization == null){
			m_iObjectiveNumber = -1;
			return -1;
		}
		m_iObjectiveNumber = optimization.numberOfObjectives;
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
			m_iObjectiveNumber = -1;
			return true;
		}
		if(optimization == null) optimization = new OptimizationResult();
		optimization.numberOfObjectives = objectiveNumber;
		m_iObjectiveNumber = objectiveNumber;
		return true;
	}//setObjectiveNumber

	/**
	 * Get constraint number. 
	 * 
	 * @return constraint number, -1 if no information. 
	 */
	public int getConstraintNumber(){
		if(optimization == null){
			m_iConstraintNumber = -1;
			return -1;
		}
		m_iConstraintNumber = optimization.numberOfConstraints;
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
			m_iConstraintNumber = -1;
			return true;
		}
		if(optimization == null) optimization = new OptimizationResult();
		optimization.numberOfConstraints = constraintNumber;
		m_iConstraintNumber = constraintNumber;
		return true;
	}//setConstraintNumber

	/**
	 * get the number of solutions. 
	 * 
	 * @return the number of solutions, 0 if none.  
	 */
	public int getSolutionNumber(){
		if(m_iSolutionNumber == -1){
			if(optimization == null) return -1;
			m_iSolutionNumber = optimization.numberOfSolutions;
		}
		return m_iSolutionNumber;
	}//getSolutionNumber

	/**
	 * set the number of solutions. This method must be called before setting other optimization solution 
	 * related results.  
	 * Before this method is called, the setVariableNumber(int), setObjectiveNumber(int), setConstraintNumber(int) methods 
	 * have to be called first. 
	 * 
	 * @param solutionNumber holds the number of solutions to set. 
	 * @return whether the solution number is set successfully.   
	 * @see #setVariableNumber(int)
	 * @see #setObjectiveNumber(int)
	 * @see #setConstraintNumber(int)
	 */
	public boolean setSolutionNumber(int solutionNumber){
		if(getVariableNumber() <= 0) return true;
		if(getObjectiveNumber() < 0) return true;
		if(getConstraintNumber() < 0) return true;
		if(solutionNumber < 0) return true; 
		optimization.numberOfSolutions = solutionNumber;
		if(solutionNumber == 0) return true;
		optimization.solution = new OptimizationSolution[solutionNumber];
		for(int i = 0; i < solutionNumber; i++){
			optimization.solution[i] = new OptimizationSolution();
		}
		return true;
	}//setSolutionNumber

	/**
	 * Get one solution of optimal primal variable values. 
	 * 
	 * @param objIdx holds the objective index the optimal value corresponds to. 
	 * @return a double dense array of the optimal values, null if no optimal value. 
	 */
	public double[] getOptimalVariableValuesDense(int objIdx){
		if(optimization.solution == null || optimization.solution.length <= 0) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		int iSolutions = optimization.solution.length;
		double[] mdValues = null;
		for(int i = 0; i < iSolutions; i++){
			if(optimization.solution[i] == null) continue;
			if(optimization.solution[i].targetObjectiveIdx != objIdx) continue;
			if(optimization.solution[i].variables == null) continue;
			if(optimization.solution[i].variables.values == null) continue;
			if((optimization.solution[i].status.type.endsWith("ptimal") && mdValues == null)||
					optimization.solution[i].status.type.equals("globallyOptimal")){				
				VarValue[] var = optimization.solution[i].variables.values.var; 
				int iVars = (var==null)?0:var.length;
				mdValues = new double[iNumberOfVariables];
				for(int j = 0; j < iVars; j++){
					mdValues[var[j].idx] = var[j].value;
				}
			}	
			if(optimization.solution[i].status.type.equals("globallyOptimal")){
				return mdValues;
			}
		}
		return mdValues;		
	}//getOptimalVariableValuesDense

	/**
	 * Get one solution of optimal primal variable values. 
	 * 
	 * @param objIdx holds the objective index the optimal value corresponds to. 
	 * @return sparse structure of the optimal values, null if no optimal value. 
	 */
	public VariableValues getOptimalVariableValuesSparse(int objIdx){
		if(optimization.solution == null || optimization.solution.length <= 0) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		int iSolutions = optimization.solution.length;
		VariableValues variableValues = null;
		for(int i = 0; i < iSolutions; i++){
			if(optimization.solution[i] == null) continue;
			if(optimization.solution[i].targetObjectiveIdx != objIdx) continue;
			if(optimization.solution[i].variables == null) continue;
			if(optimization.solution[i].variables.values == null) continue;
			if((optimization.solution[i].status.type.endsWith("ptimal") && variableValues == null)||
					optimization.solution[i].status.type.equals("globallyOptimal")){				
				variableValues = optimization.solution[i].variables.values; 
			}	
			if(optimization.solution[i].status.type.equals("globallyOptimal")){
				return variableValues;
			}
		}
		return variableValues;		
	}//getOptimalVariableValuesSparse

	/**
	 * Get one solution of optimal primal variable string values.
	 *  
	 * @param objIdx holds the objective index the optimal value corresponds to. 
	 * @return a string dense array of the optimal string values, null if no optimal value. 
	 */
	public String[] getOptimalVariableStringValues(int objIdx){
		if(optimization.solution == null || optimization.solution.length <= 0) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		int iSolutions = optimization.solution.length;
		String[] msValues = null;
		for(int i = 0; i < iSolutions; i++){
			if(optimization.solution[i] == null) continue;
			if(optimization.solution[i].targetObjectiveIdx != objIdx) continue;
			if(optimization.solution[i].variables == null) continue;
			if(optimization.solution[i].variables.valuesString == null) continue;
			if((optimization.solution[i].status.type.endsWith("ptimal") && msValues == null)||
					optimization.solution[i].status.type.equals("globallyOptimal")){
				VarStringValue[] var = optimization.solution[i].variables.valuesString.var; 
				int iVars = (var==null)?0:var.length;
				msValues = new String[iNumberOfVariables];
				for(int j = 0; j < iVars; j++){
					msValues[var[j].idx] = var[j].value;
				}
			}	
			if(optimization.solution[i].status.type.equals("globallyOptimal")){
				return msValues;
			}
		}
		return msValues;		
	}//getOptimalVariableStringValues

	/**
	 * Get one solution of optimal dual variable values.
	 *
	 * @param objIdx holds the objective index the optimal value corresponds to.
	 * @return a double dense array of the optimal dual values, null if no optimal value.
	 */
	public double[] getOptimalDualVariableValuesDense(int objIdx){
		if(optimization.solution == null || optimization.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = optimization.solution.length;
		double[] mdValues = null;
		for(int i = 0; i < iSolutions; i++){
			if(optimization.solution[i] == null) continue;
			if(optimization.solution[i].targetObjectiveIdx != objIdx) continue;
			if(optimization.solution[i].constraints == null) continue;
			if(optimization.solution[i].constraints.dualValues == null) continue;
			if((optimization.solution[i].status.type.endsWith("ptimal") && mdValues == null)||
					optimization.solution[i].status.type.equals("globallyOptimal")){                           
				DualVarValue[] con = optimization.solution[i].constraints.dualValues.con;
				int iCons = (con==null)?0:con.length;
				mdValues = new double[iNumberOfConstraints];
				for(int j = 0; j < iCons; j++){
					mdValues[con[j].idx] = con[j].value;
				}
			}       
			if(optimization.solution[i].status.type.equals("globallyOptimal")){
				return mdValues;
			}
		}
		return mdValues;               
	}//getOptimalDualVariableValuesDense

	/**
	 * Get one solution of optimal dual variable values. 
	 * 
	 * @param objIdx holds the objective index the optimal value corresponds to. 
	 * @return a double dense array of the optimal dual values, null if no optimal value. 
	 */
	public DualVariableValues getOptimalDualVariableValuesSparse(int objIdx){
		if(optimization.solution == null || optimization.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = optimization.solution.length;
		DualVariableValues dualVariableValues = null;
		for(int i = 0; i < iSolutions; i++){
			if(optimization.solution[i] == null) continue;
			if(optimization.solution[i].targetObjectiveIdx != objIdx) continue;
			if(optimization.solution[i].constraints == null) continue;
			if(optimization.solution[i].constraints.dualValues == null) continue;
			if((optimization.solution[i].status.type.endsWith("ptimal") && dualVariableValues == null)||
					optimization.solution[i].status.type.equals("globallyOptimal")){				
				dualVariableValues = optimization.solution[i].constraints.dualValues; 
			}	
			if(optimization.solution[i].status.type.equals("globallyOptimal")){
				return dualVariableValues;
			}
		}
		return dualVariableValues;		
	}//getOptimalDualVariableValuesSparse

	/**
	 * Get the [i]th optimization solution, where i equals the given solution index.
	 *    
	 * @param solIdx holds the solution index to get the solution. 
	 * @return the optimization solution that corresponds to solIdx, null if none. 
	 */
	public OptimizationSolution getSolution(int solIdx){
		if(optimization == null) return null;
		if(optimization.solution == null || 
				optimization.solution.length <= 0 || 
				solIdx < 0 || solIdx >=  optimization.solution.length) return null;
		return optimization.solution[solIdx];
	}//getSolution

	/**
	 * Set the [i]th optimization solution, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the solution. 
	 * @param solution holds the optimization solution to set. 
	 * 
	 * @return whether the optimization solution is set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolution
	 * @see #setSolutionNumber(int)
	 */
	public boolean setSolution(int solIdx, OptimizationSolution solution){
		int nSols = this.getSolutionNumber();
		if(nSols <= 0) return false;
		if(optimization == null) return false;
		if(optimization.solution == null || 
				optimization.solution.length <= 0 || 
				solIdx < 0 || solIdx >=  nSols) return false;
		optimization.solution[solIdx] = solution;
		return true;
	}//setSolution	

	/**
	 * Get the [i]th optimization solution status, where i equals the given solution index.   
	 * The solution status includes the status type, optional descriptions and possibly substatuses.
	 *  
	 * @param solIdx holds the solution index to get the solution status. 
	 * @return the optimization solution status that corresponds to solIdx, null if none.
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolutionStatus
	 */
	public OptimizationSolutionStatus getSolutionStatus( int solIdx){
		if(optimization.solution == null || 
				optimization.solution.length <= 0 || 
				solIdx < 0 || solIdx >=  optimization.solution.length) return null;
		if(optimization.solution[solIdx] == null) return null;
		return optimization.solution[solIdx].status;
	}//getSolutionStatus

	/**
	 * Set the [i]th optimization solution status, where i equals the given solution index.   
	 * The solution status includes the status type, optional descriptions and possibly substatuses. 
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * 
	 * @param solIdx holds the solution index to set the solution status.
	 * @param status holds the optimization solution status to set.  
	 * 
	 * @return whether the optimization solution status is set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolutionStatus
	 * @see #setSolutionNumber(int)
	 */
	public boolean setSolutionStatus(int solIdx, OptimizationSolutionStatus status){
		int nSols = this.getSolutionNumber();
		if(optimization == null) return false;
		if(nSols <= 0) return false;
		if(optimization == null) return false;
		if(optimization.solution == null || 
				optimization.solution.length <= 0 || 
				solIdx < 0 || solIdx >=  nSols) return false;
		if(optimization.solution[solIdx] == null){
			optimization.solution[solIdx] = new OptimizationSolution();
		}
		optimization.solution[solIdx].status = status;
		return true;
	}//setSolutionStatus

	/**
	 * Get the [i]th optimization solution status type, where i equals the given solution index.   
	 * The solution status type can be: 
	 * unbounded, globallyOptimal, locallyOptimal, optimal, bestSoFar, feasible, infeasible, 
	 * stoppedByLimit, unsure, error, other 
	 * 
	 * @param solIdx holds the solution index to get the solution status type. 
	 * @return the optimization solution status type that corresponds to solIdx, null or empty string if none.
	 */
	public String getSolutionStatusType(int solIdx){
		if(optimization.solution == null || 
				optimization.solution.length <= 0 || 
				solIdx < 0 || solIdx >=  optimization.solution.length) return null;
		if(optimization.solution[solIdx] == null) return null;
		if(optimization.solution[solIdx].status == null) return null;
		return optimization.solution[solIdx].status.type;		
	}//getSolutionStatusType

	/**
	 * Get the [i]th optimization solution subStatuses, where i equals the given solution index.   
	 * 
	 * @param solIdx holds the solution index to get the solution substatuses. 
	 * @return an array optimization solution subStatuses that corresponds to solIdx, null or empty string if none.
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolutionSubstatus;
	 */
	public OptimizationSolutionSubstatus[] getSolutionSubStatuses(int solIdx){
		if(optimization.solution == null || 
				optimization.solution.length <= 0 || 
				solIdx < 0 || solIdx >=  optimization.solution.length) return null;
		if(optimization.solution[solIdx] == null) return null;
		if(optimization.solution[solIdx].status == null) return null;
		return optimization.solution[solIdx].status.substatus;				
	}//getSolutionSubStatuses

	/**
	 * Get the [i]th optimization solution status description, where i equals the given solution index.   
	 * 
	 * @param solIdx holds the solution index to get the solution status description. 
	 * @return the optimization solution status description that corresponds to solIdx, null or empty string if none.
	 */
	public String getSolutionStatusDescription(int solIdx){
		if(optimization.solution == null || 
				optimization.solution.length <= 0 || 
				solIdx < 0 || solIdx >=  optimization.solution.length) return null;
		if(optimization.solution[solIdx] == null) return null;
		if(optimization.solution[solIdx].status == null) return null;
		return optimization.solution[solIdx].status.description;				
	}//getSolutionStatusDescription

	/**
	 * Set the [i]th optimization solution status, where i equals the given solution index.   
	 * The solution status includes the status type, optional descriptions and possibly substatuses. 
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * 
	 * @param solIdx holds the solution index to set the solution status.
	 * @param type holds the optimization solution status type to set; it is required.   
	 * The solution status type can be: 
	 * unbounded, globallyOptimal, locallyOptimal, optimal, bestSoFar, feasible, infeasible, 
	 * stoppedByLimit, unsure, error, other 
	 * @param description holds the optimization solution status description to set, null or empty string if none.  
	 * @param subStatus holds an array of optimization solution subStatuses to set, null if none. 
	 * 
	 * @return whether the optimization solution status is set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolutionStatus
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolutionSubStatus
	 * @see #setSolutionNumber(int)
	 */
	public boolean setSolutionStatus(int solIdx, String type, String description, OptimizationSolutionSubstatus[] subStatuses){
		int nSols = this.getSolutionNumber();
		if(optimization == null) return false;
		if(nSols <= 0) return false;
		if(optimization == null) return false;
		if(optimization.solution == null || 
				optimization.solution.length <= 0 || 
				solIdx < 0 || solIdx >=  nSols) return false;
		if(optimization.solution[solIdx] == null){
			optimization.solution[solIdx] = new OptimizationSolution();
		}
		optimization.solution[solIdx].status = new OptimizationSolutionStatus();
		if(!type.equals("unbounded") && 
				!type.equals("globallyOptimal") && 
				!type.equals("locallyOptimal") && 
				!type.equals("optimal") && 
				!type.equals("bestSoFar") && 
				!type.equals("feasible") && 
				!type.equals("infeasible") && 
				!type.equals("stoppedByLimit") && 
				!type.equals("unsure") && 
				!type.equals("error") && 
				!type.equals("other")) return false;
		optimization.solution[solIdx].status.type = type;
		optimization.solution[solIdx].status.description = description;
		optimization.solution[solIdx].status.substatus = subStatuses;
		return true;
	}//setSolutionStatus

	/**
	 * Get the [i]th optimization solution message, where i equals the given solution index.  
	 * 
	 * @param solIdx holds the solution index to get the solution message. 
	 * @return the optimization solution message that corresponds to solIdx, null or empty if none.
	 */
	public String getSolutionMessage(int solIdx){
		if(optimization.solution == null || 
				optimization.solution.length <= 0 || 
				solIdx < 0 || solIdx >=  optimization.solution.length) return null;
		if(optimization.solution[solIdx] == null) return null;
		return optimization.solution[solIdx].message;
	}//getSolutionMessage

	/**
	 * Set the [i]th optimization solution message, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * 
	 * @param solIdx holds the solution index to set the solution message.
	 * @param solutionMessage holds the solution message to set.  
	 * 
	 * @return whether the optimization solution message is set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setSolutionMessage(int solIdx, String solutionMessage){
		int nSols = this.getSolutionNumber();
		if(optimization == null) return false;
		if(nSols <= 0) return false;
		if(optimization == null) return false;
		if(optimization.solution == null || 
				optimization.solution.length <= 0 || 
				solIdx < 0 || solIdx >=  nSols) return false;
		if(optimization.solution[solIdx] == null){
			optimization.solution[solIdx] = new OptimizationSolution();
		}
		optimization.solution[solIdx].message = solutionMessage;
		return true;
	}//setSolutionMessage	

	/**
	 * Get the [i]th optimization solution's objective index, where i equals the given solution index. 
	 * The first objective's index should be -1, the second -2, and so on.  
	 * 
	 * @param solIdx holds the solution index to get the variable string values. 
	 * @return the optimization objective index that corresponds to solIdx, 0 if none.
	 * All the objective indexes are negative starting from -1 downward. 
	 */
	public int getSolutionTargetObjectiveIndex(int solIdx){
		if(optimization.solution == null || 
				optimization.solution.length <= 0 || 
				solIdx < 0 || solIdx >=  optimization.solution.length) return 0;
		if(optimization.solution[solIdx] == null) return 0;
		return optimization.solution[solIdx].targetObjectiveIdx;		
	}//getSolutionTargetObjectiveIndex

	/**
	 * Set the [i]th optimization solution's objective index, where i equals the given solution index.   
	 * The first objective's index should be -1, the second -2, and so on.  
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * 
	 * @param solIdx holds the solution index to set the objective index.
	 * @param objectiveIdx holds the objective index to set.  
	 * All the objective indexes are negative starting from -1 downward. 
	 * 
	 * @return whether the optimization objective index is set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setSolutionTargetObjectiveIndex(int solIdx, int objectiveIdx){
		int nSols = this.getSolutionNumber();
		if(optimization == null) return false;
		if(nSols <= 0) return false;
		if(optimization == null) return false;
		if(optimization.solution == null || 
				optimization.solution.length <= 0 || 
				solIdx < 0 || solIdx >=  nSols) return false;
		if(optimization.solution[solIdx] == null){
			optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(objectiveIdx >= 0) return false;
		optimization.solution[solIdx].targetObjectiveIdx = objectiveIdx;
		return true;		
	}//setSolutionTargetObjectiveIndex

	/**
	 * Get whether the [i]th optimization solution's is 	 
	 * computed on weighted objectives.  
	 * @param solIdx holds the solution index to get wehther it is weighted objective. 
	 * @return whether the [i]th optimization solution's is computed on weighted objectives. 
	 */
	public boolean getSolutionWeightedObjectives(int solIdx){
		if(optimization.solution == null || 
				optimization.solution.length <= 0 || 
				solIdx < 0 || solIdx >=  optimization.solution.length) return false;
		if(optimization.solution[solIdx] == null) return false;
		return optimization.solution[solIdx].weightedObjectives;		
	}//getSolutionTargetObjectiveIndex

	/**
	 * Set the [i]th optimization solution's weighted objectives flag, where i equals the given solution index.   
	 * If the solution is solved against the weighted objectives as specified by the weights in the corresponding OSiL, 
	 * the weightedObjectives should be set to true.
	 * 
	 * @param solIdx holds the solution index to set the weightedObjectives flag.
	 * @param weightedObjectives holds whether the solution is solved against the weighted objectives  
	 * 
	 * @return whether the weightedObjectives is set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setSolutionWeightedObjectives(int solIdx, boolean weightedObjectives){
		int nSols = this.getSolutionNumber();
		if(optimization == null) return false;
		if(nSols <= 0) return false;
		if(optimization == null) return false;
		if(optimization.solution == null || 
				optimization.solution.length <= 0 || 
				solIdx < 0 || solIdx >=  nSols) return false;
		if(optimization.solution[solIdx] == null){
			optimization.solution[solIdx] = new OptimizationSolution();
		}
		optimization.solution[solIdx].weightedObjectives = weightedObjectives;
		if(weightedObjectives) optimization.solution[solIdx].targetObjectiveIdx = 0;
		return true;		
	}//setSolutionTargetObjectiveIndex

	/**
	 * Get the [i]th optimization solution's variable values, where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the variable values. 
	 * @return a double dense array of variable values, null if no variable values. 
	 */
	public double[] getVariableValuesDense(int solIdx){
		if(optimization.solution == null || optimization.solution.length <= 0) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		int iSolutions = optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(optimization.solution[solIdx] == null) return null;
		if(optimization.solution[solIdx].variables == null) return null;
		if(optimization.solution[solIdx].variables.values == null) return null;
		VarValue[] var = optimization.solution[solIdx].variables.values.var; 
		int iVars = (var==null)?0:var.length;
		double[] mdValues = new double[iNumberOfVariables];
		for(int i = 0; i < iVars; i++){
			mdValues[var[i].idx] = var[i].value;
		}
		return mdValues;		
	}//getVariableValuesDense

	/**
	 * Set the [i]th optimization solution's primal variable values, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the primal variable values. 
	 * @param x holds a double dense array of variable values to set; it could be null if all variables are 0.
	 * 
	 * @return whether primal variable values are set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setVariableValuesDense(int solIdx, double[] x){
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return false;
		if(x != null && x.length != iNumberOfVariables) return false;
		int nSols = this.getSolutionNumber();
		if(optimization == null) return false;
		if(nSols <= 0) return false;
		if(optimization == null) return false;
		if(optimization.solution == null || 
				optimization.solution.length <= 0 || 
				solIdx < 0 || solIdx >=  nSols) return false;
		if(optimization.solution[solIdx] == null){
			optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(optimization.solution[solIdx].variables == null){
			optimization.solution[solIdx].variables = new VariableSolution();
		}
		if(optimization.solution[solIdx].variables.values == null){
			optimization.solution[solIdx].variables.values = new VariableValues();
		}
		if(x == null){
			optimization.solution[solIdx].variables.values.var = null;
			return true;
		}
		int iVars = 0;
		for(int i = 0; i < x.length; i++){
			if(x[i] != 0) iVars++;
		}
		optimization.solution[solIdx].variables.values.var = new VarValue[iVars];
		VarValue[] var = optimization.solution[solIdx].variables.values.var;
		for(int i = 0; i < iVars; i++) var[i] = new VarValue();
		int j = 0;
		for(int i = 0; i < x.length; i++){
			if(x[i] != 0){
				var[j].idx = i;
				var[j].value = x[i];
				j++;
			}
		}
		return true;
	}//setVariableValuesDense

	/**
	 * Get the [i]th optimization solution's variable values in a sparse data structure, where i equals the given solution index. 
	 * The sparse data stucture is of the VariableValues data structure. VariableValues holds var[], an array of VarValues. 
	 * Each var member contains an idx and a value. If var[] is null, all the variable values are 0. 
	 * 
	 * @param solIdx holds the solution index to get the sparse variable values. 
	 * @return a sparse variable value data structure in VaribleValues, null if no variable values. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.VariableValues
	 * @see org.optimizationservices.oscommon.datastructure.osresult.VarValue
	 */
	public VariableValues getVariableValuesSparse(int solIdx){ 
		if(optimization.solution == null || optimization.solution.length <= 0) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		int iSolutions = optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(optimization.solution[solIdx] == null) return null;
		if(optimization.solution[solIdx].variables == null) return null;
		return optimization.solution[solIdx].variables.values;
	}//getVariableValuesSparse

	/**
	 * Set the [i]th optimization solution's primal variable values, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the primal variable values. 
	 * @param variableValues holds a sparse structure of variable values to set; it could be null if all variables are 0.
	 * 
	 * @return whether primal variable values are set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setVariableValuesSparse(int solIdx, VariableValues variableValues){
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return false;
		int nSols = this.getSolutionNumber();
		if(optimization == null) return false;
		if(nSols <= 0) return false;
		if(optimization == null) return false;
		if(optimization.solution == null || 
				optimization.solution.length <= 0 || 
				solIdx < 0 || solIdx >=  nSols) return false;
		if(optimization.solution[solIdx] == null){
			optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(optimization.solution[solIdx].variables == null){
			optimization.solution[solIdx].variables = new VariableSolution();
		}
		optimization.solution[solIdx].variables.values = variableValues;
		return true;
	}//setVariableValuesSparse

	/**
	 * Get the [i]th optimization solution's variable string values, where i equals the given solution index. 
	 * 
	 * @param solIdx holds the solution index to get the variable string values. 
	 * @return a string dense array of variable values, null if no variable values. 
	 */
	public double[] getVariableStringValues(int solIdx){
		if(optimization.solution == null || optimization.solution.length <= 0) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		int iSolutions = optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(optimization.solution[solIdx] == null) return null;
		if(optimization.solution[solIdx].variables == null) return null;
		if(optimization.solution[solIdx].variables.values == null) return null;
		VarValue[] var = optimization.solution[solIdx].variables.values.var; 
		int iVars = (var==null)?0:var.length;
		double[] mdValues = new double[iNumberOfVariables];
		for(int i = 0; i < iVars; i++){
			mdValues[var[i].idx] = var[i].value;
		}
		return mdValues;		
	}//getVariableStringValues

	/**
	 * Set the [i]th optimization solution's primal variable string values, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the primal variable string values. 
	 * @param x holds a dense string array of variable string values to set.
	 * 
	 * @return whether primal variable string values are set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setVariableStringValues(int solIdx, String[] x){
		if(x == null) return false;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return false;
		if(x != null && x.length != iNumberOfVariables) return false;
		int nSols = this.getSolutionNumber();
		if(optimization == null) return false;
		if(nSols <= 0) return false;
		if(optimization == null) return false;
		if(optimization.solution == null || 
				optimization.solution.length <= 0 || 
				solIdx < 0 || solIdx >=  nSols) return false;
		if(optimization.solution[solIdx] == null){
			optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(optimization.solution[solIdx].variables == null){
			optimization.solution[solIdx].variables = new VariableSolution();
		}
		if(optimization.solution[solIdx].variables.valuesString == null){
			optimization.solution[solIdx].variables.valuesString = new VariableStringValues();
		}
		optimization.solution[solIdx].variables.valuesString.var = new VarStringValue[iNumberOfVariables];
		VarStringValue[] var = optimization.solution[solIdx].variables.valuesString.var;
		for(int i = 0; i < iNumberOfVariables; i++) var[i] = new VarStringValue();
		for(int i = 0; i < iNumberOfVariables; i++){
			var[i].idx = i;
			var[i].value = x[i];
		}
		return true;
	}//setVariableStringValues

	/**
	 * Get the [i]th optimization solution's other (non-standard/solver specific)variable-related results, 
	 * where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the other variable results. 
	 * @return an array of other variable results in OtherVariableResult[] array data structure, null if none. 
	 * Each other variable result contains the name (required), an optional description (string) and an optional
	 * value (string). Each other variable result can also optionally contain an array OtherVarResult for each variable. 
	 * The OtherVarResult contains a variable idx (required), and an optional string value.  
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherVariableResult
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherVarResult
	 */
	public OtherVariableResult[] getOtherVariableResults(int solIdx){
		if(optimization.solution == null || optimization.solution.length <= 0) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		int iSolutions = optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(optimization.solution[solIdx] == null) return null;
		if(optimization.solution[solIdx].variables == null) return null;
		return optimization.solution[solIdx].variables.other;	
	}//getOtherVariableResults

	/**
	 * Set the [i]th optimization solution's other (non-standard/solver specific)variable-related results, 
	 * where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param otherVariableResults holds an array of other variable results in OtherVariableResult[] array data structure, null if none. 
	 * Each other variable result contains the name (required), an optional description (string) and an optional
	 * value (string). Each other variable result can also optionally contain an array OtherVarResult for each variable. 
	 * The OtherVarResult contains a variable idx (required) and an optional string value.   
	 * 
	 * @return whether the other variable results are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherVariableResult
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherVarResult
	 * @see #setSolutionNumber(int)
	 */
	public boolean setOtherVariableResults(int solIdx, OtherVariableResult[] otherVariableResults){
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return false;
		int nSols = this.getSolutionNumber();
		if(optimization == null) return false;
		if(nSols <= 0) return false;
		if(optimization == null) return false;
		if(optimization.solution == null || 
				optimization.solution.length <= 0 || 
				solIdx < 0 || solIdx >=  nSols) return false;
		if(optimization.solution[solIdx] == null){
			optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(optimization.solution[solIdx].variables == null){
			optimization.solution[solIdx].variables = new VariableSolution();
		}
		optimization.solution[solIdx].variables.other = otherVariableResults;
		return true;		
	}//setOtherVariableResults

	/**
	 * Get the [i]th optimization solution's objective values, where i equals the given solution index. 
	 * Usually one of the objective is what the solution was solved for (or based on). Its index should be indicated 
	 * in the solution's objectiveIdx attribute. Based on this objective's solution, the rest of the objective 
	 * values are (optionally) calculated. 
	 * @param solIdx holds the solution index to get the objective values. 
	 * @return a double dense array of objective values, null if null if no objective values. 
	 * Possibly only the objective that the solution is based on has the value, and the rest of the objective
	 * values all get a Double.NaN value, meaning that they are not calculated.   
	 */
	public double[] getObjectiveValuesDense(int solIdx){
		if(optimization.solution == null || optimization.solution.length <= 0) return null;
		int iNumberOfObjectives = this.getObjectiveNumber();
		if(iNumberOfObjectives <= 0) return null;
		int iSolutions = optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(optimization.solution[solIdx] == null) return null;
		if(optimization.solution[solIdx].objectives == null) return null;
		if(optimization.solution[solIdx].objectives.values == null) return null;
		ObjValue[] obj = optimization.solution[solIdx].objectives.values.obj; 
		int iObjs = (obj==null)?0:obj.length;
		double[] mdValues = new double[iNumberOfObjectives];
		for(int i = 0; i < iNumberOfObjectives; i++){
			mdValues[i] = Double.NaN;
		}
		for(int i = 0; i < iObjs; i++){
			mdValues[Math.abs(obj[i].idx)-1] = obj[i].value;
		}
		return mdValues;		
	}//getObjectiveValuesDense


	/**
	 * Set the [i]th optimization solution's objective values, where i equals the given solution index.   
	 * Usually one of the objective is what the solution was solved for (or based on). Its index should be indicated 
	 * in the solution's objectiveIdx attribute. Based on this objective's solution, the rest of the objective 
	 * values are (optionally) calculated. 
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the objective values. 
	 * @param objectiveValues holds a double dense array of objective values to set.
	 * Possibly only the objective that the solution is based on has the value, and the rest of the objective
	 * values all get a Double.NaN value, meaning that they are not calculated.   
	 * 
	 * @return whether objective values are set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setObjectiveValuesDense(int solIdx, double[] objectiveValues){
		int iNumberOfObjectives = this.getObjectiveNumber();
		if(iNumberOfObjectives < 0) return false;
		if(iNumberOfObjectives == 0) return true;
		if(objectiveValues == null) return false;
		if(objectiveValues.length != iNumberOfObjectives) return false;
		int nSols = this.getSolutionNumber();
		if(optimization == null) return false;
		if(nSols <= 0) return false;
		if(optimization == null) return false;
		if(optimization.solution == null || 
				optimization.solution.length <= 0 || 
				solIdx < 0 || solIdx >=  nSols) return false;
		if(optimization.solution[solIdx] == null){
			optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(optimization.solution[solIdx].objectives == null){
			optimization.solution[solIdx].objectives = new ObjectiveSolution();
		}
		if(optimization.solution[solIdx].objectives.values == null){
			optimization.solution[solIdx].objectives.values = new ObjectiveValues();
		}
		int iObjs = 0;
		for(int i = 0; i < objectiveValues.length; i++){
			if(!Double.isNaN(objectiveValues[i])) iObjs++;
		}
		optimization.solution[solIdx].objectives.values.obj = new ObjValue[iObjs];
		ObjValue[] obj = optimization.solution[solIdx].objectives.values.obj;
		for(int i = 0; i < iObjs; i++) obj[i] = new ObjValue();
		int j = 0;
		for(int i = 0; i < objectiveValues.length; i++){
			if(!Double.isNaN(objectiveValues[i])){
				obj[j].idx = -(i+1);
				obj[j].value = objectiveValues[i];
				j++;
			}
		}
		return true;
	}//setObjectiveValuesDense

	/**
	 * Get the [i]th optimization solution's objective values, where i equals the given solution index. 
	 * Usually one of the objective is what the solution was solved for (or based on). Its index should be indicated 
	 * in the solution's objectiveIdx attribute. Based on this objective's solution, the rest of the objective 
	 * values are (optionally) calculated. 
	 * @param solIdx holds the solution index to get the objective values. 
	 * @return a sparse structure of objective values, null if null if no objective values. 
	 * Possibly only the objective that the solution is based on has the value, and the rest of the objective
	 * values all get a Double.NaN value, meaning that they are not calculated.   
	 */
	public ObjectiveValues getObjectiveValuesSparse(int solIdx){
		if(optimization.solution == null || optimization.solution.length <= 0) return null;
		int iNumberOfObjectives = this.getObjectiveNumber();
		if(iNumberOfObjectives <= 0) return null;
		int iSolutions = optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(optimization.solution[solIdx] == null) return null;
		if(optimization.solution[solIdx].objectives == null) return null;
		return optimization.solution[solIdx].objectives.values;
	}//getObjectiveValuesSparse

	/**
	 * Set the [i]th optimization solution's objective values, where i equals the given solution index.   
	 * Usually one of the objective is what the solution was solved for (or based on). Its index should be indicated 
	 * in the solution's objectiveIdx attribute. Based on this objective's solution, the rest of the objective 
	 * values are (optionally) calculated. 
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the objective values. 
	 * @param objectiveValues holds a double dense array of objective values to set.
	 * Possibly only the objective that the solution is based on has the value, and the rest of the objective
	 * values all get a Double.NaN value, meaning that they are not calculated.   
	 * 
	 * @return whether objective values are set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setObjectiveValuesSparse(int solIdx, ObjectiveValues objectiveValues){
		int iNumberOfObjectives = this.getObjectiveNumber();
		if(iNumberOfObjectives < 0) return false;
		if(iNumberOfObjectives == 0) return true;
		if(objectiveValues == null) return false;
		int nSols = this.getSolutionNumber();
		if(optimization == null) return false;
		if(nSols <= 0) return false;
		if(optimization == null) return false;
		if(optimization.solution == null || 
				optimization.solution.length <= 0 || 
				solIdx < 0 || solIdx >=  nSols) return false;
		if(optimization.solution[solIdx] == null){
			optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(optimization.solution[solIdx].objectives == null){
			optimization.solution[solIdx].objectives = new ObjectiveSolution();
		}
		optimization.solution[solIdx].objectives.values = objectiveValues;
		return true;
	}//setObjectiveValuesSparse
	
	/**
	 * Get the [i]th optimization solution's other (non-standard/solver specific)objective-related results, 
	 * where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the other objective results. 
	 * @return an array of other objective results in OtherObjectiveResult[] array data structure, null if none. 
	 * Each other objective result contains the name (required), an optional description (string) and an optional
	 * value (string). Each other objective result can also optionally contain an array OtherObjResult for each objective. 
	 * The OtherObjResult contains an objective idx (required) and an optional string value.  
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherObjectiveResult
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherObjResult
	 */
	public OtherObjectiveResult[] getOtherObjectiveResults(int solIdx){
		if(optimization.solution == null || optimization.solution.length <= 0) return null;
		int iNumberOfObjectives = this.getObjectiveNumber();
		if(iNumberOfObjectives <= 0) return null;
		int iSolutions = optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(optimization.solution[solIdx] == null) return null;
		if(optimization.solution[solIdx].objectives == null) return null;
		return optimization.solution[solIdx].objectives.other;	
	}//getOtherObjectiveResults


	/**
	 * Set the [i]th optimization solution's other (non-standard/solver specific)objective-related results, 
	 * where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the other objective results. 
	 * @param otherObjectiveResults holds an array of other objective results in OtherObjectiveResult[] array data structure, null if none. 
	 * Each other objective result contains the name (required), an optional description (string) and an optional
	 * value (string). Each other objective result can also optionally contain an array OtherObjResult for each objective. 
	 * The OtherObjResult contains an objective idx (required), an optional string value.    
	 * 
	 * @return whether the other objective results are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherObjectiveResult
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherObjResult
	 * @see #setSolutionNumber(int)
	 */
	public boolean setOtherObjectiveResults(int solIdx, OtherObjectiveResult[] otherObjectiveResults){
		int iNumberOfObjectives = this.getObjectiveNumber();
		if(iNumberOfObjectives <= 0) return false;
		int nSols = this.getSolutionNumber();
		if(optimization == null) return false;
		if(nSols <= 0) return false;
		if(optimization == null) return false;
		if(optimization.solution == null || 
				optimization.solution.length <= 0 || 
				solIdx < 0 || solIdx >=  nSols) return false;
		if(optimization.solution[solIdx] == null){
			optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(optimization.solution[solIdx].objectives == null){
			optimization.solution[solIdx].objectives = new ObjectiveSolution();
		}
		optimization.solution[solIdx].objectives.other = otherObjectiveResults;
		return true;		
	}//setOtherObjectiveResults

	/**
	 * Get the [i]th optimization solution's dual variable values, where i equals the given solution index. 
	 * 
	 * @param solIdx holds the solution index to get the dual variable values. 
	 * @return a double dense array of the dual variable values, null if none. 
	 */
	public double[] getDualVariableValuesDense(int solIdx){
		if(optimization.solution == null || optimization.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(optimization.solution[solIdx] == null) return null;
		if(optimization.solution[solIdx].constraints == null) return null;
		if(optimization.solution[solIdx].constraints.dualValues == null) return null;
		DualVarValue[] con = optimization.solution[solIdx].constraints.dualValues.con; 
		int iCons = (con==null)?0:con.length;
		double[] mdValues = new double[iNumberOfConstraints];
		for(int j = 0; j < iCons; j++){
			if(!Double.isNaN(con[j].value)){
				mdValues[con[j].idx] = con[j].value;
			}
		}
		return mdValues;				
	}//getDualVariableValuesDense

	/**
	 * Set the [i]th optimization solution's dual variable values, where i equals the given solution index. 
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the dual variable values. 
	 * @param values holds a double dense array of variable dual values to set; it could be null if all values are 0.
	 * 
	 * @return whether dual variable values are set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setDualVariableValuesDense(int solIdx, double[] values){
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints < 0) return false;
		if(iNumberOfConstraints == 0) return true;
		if(values != null && values.length != iNumberOfConstraints) return false;
		int nSols = this.getSolutionNumber();
		if(optimization == null) return false;
		if(nSols <= 0) return false;
		if(optimization == null) return false;
		if(optimization.solution == null || 
				optimization.solution.length <= 0 || 
				solIdx < 0 || solIdx >=  nSols) return false;
		if(optimization.solution[solIdx] == null){
			optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(optimization.solution[solIdx].constraints == null){
			optimization.solution[solIdx].constraints = new ConstraintSolution();
		}
		if(optimization.solution[solIdx].constraints.dualValues == null){
			optimization.solution[solIdx].constraints.dualValues = new DualVariableValues();
		}		
		if(values == null){
			optimization.solution[solIdx].constraints.dualValues.con = null;
			return true;
		}
		int iCons = 0;
		for(int i = 0; i < values.length; i++){
			if(values[i] != 0) iCons++;
		}
		optimization.solution[solIdx].constraints.dualValues.con = new DualVarValue[iCons];
		DualVarValue[] con = optimization.solution[solIdx].constraints.dualValues.con;
		for(int i = 0; i < iCons; i++) con[i] = new DualVarValue();
		int j = 0;
		for(int i = 0; i < values.length; i++){
			if(values[i] != 0){
				con[j].idx = i;
				con[j].value = values[i];
				j++;
			}
		}
		return true;	
	}//setDualVariableValuesDense

	/**
	 * Set the [i]th optimization solution's dual variable values, where i equals the given solution index. 
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the dual variable values. 
	 * @param values holds sparse structure of variable dual values to set; it could be null if all values are 0.
	 * 
	 * @return whether dual variable values are set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setDualVariableValuesSparse(int solIdx, DualVariableValues values){
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints < 0) return false;
		if(iNumberOfConstraints == 0) return true;
		int nSols = this.getSolutionNumber();
		if(optimization == null) return false;
		if(nSols <= 0) return false;
		if(optimization == null) return false;
		if(optimization.solution == null || 
				optimization.solution.length <= 0 || 
				solIdx < 0 || solIdx >=  nSols) return false;
		if(optimization.solution[solIdx] == null){
			optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(optimization.solution[solIdx].constraints == null){
			optimization.solution[solIdx].constraints = new ConstraintSolution();
		}
		optimization.solution[solIdx].constraints.dualValues= values;
		return true;	
	}//setDualVariableValuesDense
	
	/**
	 * Get the [i]th optimization solution's dual variable values in a sparse data structure, where i equals the given solution index. 
	 * The sparse data stucture is of the DualVariableValues data structure. DualVariableValues holds con[], an array of DualVarValues. 
	 * Each con member contains a constraint idx and a dual value. If con[] is null, all the dual variable values are 0. 
	 * 
	 * @param solIdx holds the solution index to get the sparse dual variable values. 
	 * @return a sparse variable value data structure in DualVaribleValues, null if no dual variable values. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.DualVariableValues
	 * @see org.optimizationservices.oscommon.datastructure.osresult.DualVarValue
	 */
	public DualVariableValues getDualVariableValuesSparse(int solIdx){
		if(optimization.solution == null || optimization.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(optimization.solution[solIdx] == null) return null;
		if(optimization.solution[solIdx].constraints == null) return null;
		return optimization.solution[solIdx].constraints.dualValues;
	}//getDualVariableValuesSparse

	/**
	 * Get the [i]th optimization solution's other (non-standard/solver specific)constraint-related results, 
	 * where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the other constraint results. 
	 * @return an array of other constraint results in OtherConstraintResult[] array data structure, null if none. 
	 * Each other constraint result contains the name (required), an optional description (string) and an optional
	 * value (string). Each other constraint result can also optionally contain an array OtherConResult for each constraint. 
	 * The OtherConResult contains a constraint idx (required) and an optional string value.  
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherConstraintResult
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherConResult
	 */
	public OtherConstraintResult[] getOtherConstraintResults(int solIdx){
		if(optimization.solution == null || optimization.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(optimization.solution[solIdx] == null) return null;
		if(optimization.solution[solIdx].constraints == null) return null;
		return optimization.solution[solIdx].constraints.other;	
	}//getOtherConstraintResults

	/**
	 * Set the [i]th optimization solution's other (non-standard/solver specific)constraint-related results, 
	 * where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param otherConstraintResults holds an array of other constraint results in OtherConstraintResult[] array data structure, null if none. 
	 * Each other constraint result contains the name (required), an optional description (string) and an optional
	 * value (string). Each other constraint result can also optionally contain an array OtherConstraint for each constraint. 
	 * The OtherConResult contains a constraint idx (required) and an optional string value.   
	 * 
	 * @return whether the other constraint results are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherConstraintResult
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherConResult
	 * @see #setSolutionNumber(int)
	 */
	public boolean setOtherConstraintResults(int solIdx, OtherConstraintResult[] otherConstraintResults){
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return false;
		int nSols = this.getSolutionNumber();
		if(optimization == null) return false;
		if(nSols <= 0) return false;
		if(optimization == null) return false;
		if(optimization.solution == null || 
				optimization.solution.length <= 0 || 
				solIdx < 0 || solIdx >=  nSols) return false;
		if(optimization.solution[solIdx] == null){
			optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(optimization.solution[solIdx].constraints == null){
			optimization.solution[solIdx].constraints = new ConstraintSolution();
		}
		optimization.solution[solIdx].constraints.other = otherConstraintResults;
		return true;		
	}//setOtherConstraintResults

	/**
	 * Get the [i]th optimization solution's other (non-standard/solver specific)optimization-related results, 
	 * where i equals the given solution index. These other results are usually on the general optimization, 
	 * not specifically on the variables, objective, or constraints. 
	 *  
	 * @param solIdx holds the solution index to get the other optimization results. 
	 * @return an array of other optimization results in OtherOptimizationResult[] array data structure, null if none. 
	 * Each other optimization result contains the name (required), an optional description (string) and an optional
	 * value (string).   
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherOptimizationResult
	 */
	public OtherSolutionResult[] getOtherOptimizationSolutionResults(int solIdx){
		if(optimization.solution == null || optimization.solution.length <= 0) return null;
		int iSolutions = optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(optimization.solution[solIdx] == null) return null;
		if(optimization.solution[solIdx].otherSolutionResults == null) return null;	
		return optimization.solution[solIdx].otherSolutionResults.otherSolutionResult;	
	}//getOtherOptimizationSolutionResults


	/**
	 * Set the [i]th optimization solution's other (non-standard/solver specific)optimization-related results, 
	 * where i equals the given solution index.  These other results are usually on the general optimization, 
	 * not specifically on the variables, objective, or constraints.  
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param otherOptimizationResults holds an array of other optimization results in OtherOptimizationResult[] array data structure, null if none. 
	 * Each other optimization result contains the name (required), an optional description (string) and an optional
	 * value (string).  
	 * @return whether the other optimization results are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherOptimizationResult
	 * @see #setSolutionNumber(int)
	 */
	public boolean setOtherOptimizationSolutionResults(int solIdx, OtherSolutionResult[] otherOptimizationSolutionResults){
		int nSols = this.getSolutionNumber();
		if(optimization == null) return false;
		if(nSols <= 0) return false;
		if(optimization == null) return false;
		if(optimization.solution == null || 
				optimization.solution.length <= 0 || 
				solIdx < 0 || solIdx >=  nSols) return false;
		if(optimization.solution[solIdx] == null){
			optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(optimization.solution[solIdx].otherSolutionResults == null){
			optimization.solution[solIdx].otherSolutionResults = new SolutionResults();
		}
		optimization.solution[solIdx].otherSolutionResults.otherSolutionResult = otherOptimizationSolutionResults;
		return true;		
	}//setOtherOptimizationSolutionResults

	/**
	 * Get number of other optimization related solver output not specific to any solution. 
	 * @return the number of other solver output. 
	 */
	public int  getNumberOfOtherOptimizationSolverOuput(){
		if(optimization.otherSolverOutput == null) return 0;
		else return optimization.otherSolverOutput.numberOfOutputs;

	}//getNumberOfOtherOptimizationSolverOuput
	
	/**
	 * Get other optimization related solver output not specific to any solution. 
	 * @return an array of other solver output. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.SolverOutput
	 */
	public SolverOutput[] getOtherOptimizationSolverOuput(){
		if(optimization == null) return null;
		if(optimization.otherSolverOutput ==  null) return null;
		return optimization.otherSolverOutput.output;
	
	}//getOtherOptimizationSolverOuput
	
	/**
	 * Set other optimization related solver output not specific to any solution. 
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param ohterSolverOuput holds an array of other optimization related solver output in OtherSolverOutput[] array data structure, null if none. 
	 * Each other optimization solver output contains the name (required), an optional category an optional description (string) and an optional
	 * value (string).  
	 * @return whether the other optimization solver output are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherSolverOutput
	 * @see #setSolutionNumber(int)
	 */
	public boolean setOtherOptimizationSolverOuput(SolverOutput[] otherSolverOutput){
		if(optimization.otherSolverOutput == null){
			optimization.otherSolverOutput = new OtherSolverOutput();
		}
		optimization.otherSolverOutput.numberOfOutputs = otherSolverOutput==null?0:otherSolverOutput.length;
		optimization.otherSolverOutput.output = otherSolverOutput;
		return true;
	}//setOtherOptimizationSolverOuput
	

	/**
	 * Get the optimization analysis in the standard OSAnalysis data structure. 
	 * 
	 * @return the optimization analysis in the standard OSAnalysis data structure, null if none.
	 * @see org.optimizationservices.oscommon.localinterface.OSAnalysis
	 */
	public OSAnalysis getOSAnalysis(){
		return optimization.osal;
	}//getOSAnalysis

	/**
	 * Set the optimization analysis. 
	 * 
	 * @param osAnalysis holds the optimization analysis in the standard OSAnalysis data structure. 
	 * @return the optimization analysis in the standard OSAnalysis data structure, null if none.
	 * @see org.optimizationservices.oscommon.localinterface.OSAnalysis
	 */	
	public boolean setOSAnalysis(OSAnalysis osAnalysis){
		if(optimization == null) optimization = new OptimizationResult();
		optimization.osal = osAnalysis;
		return false;
	}//setOSAnalysis


	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] args){

	}//main
}//class OSResult
