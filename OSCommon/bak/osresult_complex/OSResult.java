/**
 * @(#)OSResult 1.0 03/14/2005
 *
 * Copyright (c) 2005 
 */
package org.optimizationservices.oscommon.localinterface;

import java.util.GregorianCalendar;
import java.util.Hashtable;

import org.optimizationservices.oscommon.datastructure.osprocess.JobStatistics;
import org.optimizationservices.oscommon.datastructure.osprocess.Jobs;
import org.optimizationservices.oscommon.datastructure.osprocess.ProcessStatistics;
import org.optimizationservices.oscommon.datastructure.osresult.ConValue;
import org.optimizationservices.oscommon.datastructure.osresult.ConstraintAllowableDecreases;
import org.optimizationservices.oscommon.datastructure.osresult.ConstraintAllowableIncreases;
import org.optimizationservices.oscommon.datastructure.osresult.ConstraintIrreducibleInconsistentSystem;
import org.optimizationservices.oscommon.datastructure.osresult.ConstraintOVFunctions;
import org.optimizationservices.oscommon.datastructure.osresult.ConstraintSlacks;
import org.optimizationservices.oscommon.datastructure.osresult.ConstraintSolution;
import org.optimizationservices.oscommon.datastructure.osresult.ConstraintValues;
import org.optimizationservices.oscommon.datastructure.osresult.DualVarUnboundedDirection;
import org.optimizationservices.oscommon.datastructure.osresult.DualVarValue;
import org.optimizationservices.oscommon.datastructure.osresult.DualVariableUnboundedDirections;
import org.optimizationservices.oscommon.datastructure.osresult.DualVariableValues;
import org.optimizationservices.oscommon.datastructure.osresult.GeneralStatus;
import org.optimizationservices.oscommon.datastructure.osresult.ObjValue;
import org.optimizationservices.oscommon.datastructure.osresult.ObjectiveOVFunctions;
import org.optimizationservices.oscommon.datastructure.osresult.ObjectiveSolution;
import org.optimizationservices.oscommon.datastructure.osresult.ObjectiveValues;
import org.optimizationservices.oscommon.datastructure.osresult.OptimizationResult;
import org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolution;
import org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolutionStatus;
import org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolutionSubstatus;
import org.optimizationservices.oscommon.datastructure.osresult.OtherConstraintResult;
import org.optimizationservices.oscommon.datastructure.osresult.OtherObjectiveResult;
import org.optimizationservices.oscommon.datastructure.osresult.OtherOptimizationResult;
import org.optimizationservices.oscommon.datastructure.osresult.OtherResult;
import org.optimizationservices.oscommon.datastructure.osresult.OtherVariableResult;
import org.optimizationservices.oscommon.datastructure.osresult.PrimalVarUnboundedDirection;
import org.optimizationservices.oscommon.datastructure.osresult.PrimalVariableUnboundedDirections;
import org.optimizationservices.oscommon.datastructure.osresult.ReducedCosts;
import org.optimizationservices.oscommon.datastructure.osresult.ResultData;
import org.optimizationservices.oscommon.datastructure.osresult.ResultHeader;
import org.optimizationservices.oscommon.datastructure.osresult.VarStringValue;
import org.optimizationservices.oscommon.datastructure.osresult.VarValue;
import org.optimizationservices.oscommon.datastructure.osresult.VariableAllowableDecreases;
import org.optimizationservices.oscommon.datastructure.osresult.VariableAllowableIncreases;
import org.optimizationservices.oscommon.datastructure.osresult.VariableIrreducibleInconsistentSystem;
import org.optimizationservices.oscommon.datastructure.osresult.VariableOVFunctions;
import org.optimizationservices.oscommon.datastructure.osresult.VariableSlacks;
import org.optimizationservices.oscommon.datastructure.osresult.VariableSolution;
import org.optimizationservices.oscommon.datastructure.osresult.VariableStringValues;
import org.optimizationservices.oscommon.datastructure.osresult.VariableValues;
import org.optimizationservices.oscommon.representationparser.OSrLReader;
import org.optimizationservices.oscommon.representationparser.OSrLWriter;

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
	 * resultHeader holds the first child of the OSResult specified by the OSiL Schema. 
	 */
	public ResultHeader resultHeader = new ResultHeader();

	/**
	 * resultData holds the second child of the OSResult specified by the OSiL Schema. 
	 */
	public ResultData resultData = new ResultData();	
	
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
		return resultHeader.generalStatus;
	}//getGeneralStatus
	
   	/**
	 * Get the general status type, which can be: 
	 * success, error, warning. 
	 * 
	 * @return the general status type, null if none. 
	 */
	public String getGeneralStatusType(){
		if(resultHeader.generalStatus == null) return null;
		return resultHeader.generalStatus.type;
	}//getGeneralStatusType

   	/**
	 * Get the general status description. 
	 * 
	 * @return the general status description, null or empty string if none. 
	 */
	public String getGeneralStatusDescription(){
		if(resultHeader.generalStatus == null) return null;
		return resultHeader.generalStatus.description;
	}//getGeneralStatusDescription

   	/**
	 * Get service name.
	 * 
	 * @return the service name. 
	 */
	public String getServiceName(){
		return resultHeader.serviceName;
	}//getServiceName
	
  	/**
	 * Get service uri.
	 * 
	 * @return the service uri. 
	 */
	public String getServiceURI(){
		return resultHeader.serviceURI;
	}//getServiceURI
	
  	/**
	 * Get instance name.
	 * 
	 * @return the instance name. 
	 */
	public String getInstanceName(){
		return resultHeader.instanceName;
	}//getInstanceName
	
  	/**
	 * Get the job id.
	 * 
	 * @return the job id. 
	 */
	public String getJobID(){
		return resultHeader.jobID;
	}//getJobID
	
 	/**
	 * Get time of the result.
	 * 
	 * @return the time of the result.
	 */
	public GregorianCalendar getResultTime(){
		return resultHeader.time;
	}//getResultTime
	
   	/**
	 * Get the general message. 
	 * 
	 * @return the general message. 
	 */
	public String getGeneralMessage(){
		return resultHeader.message;
	}//getGeneralMessage
	
	/**
	 * Get the process statistics. 
	 * 
	 * @return the process statistics. 
	 */
	public ProcessStatistics getProcessStatistics(){
		return resultData.statistics;
	}//getProcessStatistics
	
	/**
	 * Get the statistics of all the jobs. 
	 * 
	 * @return the statistics of all the jobs, which is an array of jobStatistics with 
	 * each member corresponding to one job; null if none. 
	 */
	public JobStatistics[] getJobStatistics(){
		if(resultData.statistics == null) return null;
		if(resultData.statistics.jobs == null) return null;
		return resultData.statistics.jobs.job;
	}//getJobStatistics
	
	/**
	 * Get the current state, , which can be:
	 * "busy", "busyButAccepting", "idle", "idleButNotAccepting" and "noResponse".
	 * 
	 * @return the current status, "noResponse" if none.
	 */
	public String getCurrentState(){
		if(resultData.statistics == null) return "noResponse";
		return resultData.statistics.currentState;
	}//getCurrentState
	
	/**
	 * Get the available disk space (in bytes). 
	 * @return the available disk space, Double.NaN if none. 
	 */
	public double getAvailableDiskSpace(){
		if(resultData.statistics == null) return Double.NaN;
		return resultData.statistics.availableDiskSpace;
	}//getAvailableDiskSpace
	
	/**
	 * Get the available memory (in bytes). 
	 * @return the available memory, Double.NaN if none. 
	 */
	public double getAvailableMemory(){
		if(resultData.statistics == null) return Double.NaN;
		return resultData.statistics.availableMemory;
	}//getAvailableMemory
	
	
	/**
	 * Get the current job count. 
	 * @return the current job count, -1 if none. 
	 */
	public int getCurrentJobCount(){
		if(resultData.statistics == null) return -1;
		return resultData.statistics.currentJobCount;
	}//getCurrentJobCount
	
	
	/**
	 * Get the total jobs received so far. 
	 * @return the total jobs received so far, -1 if none. 
	 */
	public int getTotalJobsSoFar(){
		if(resultData.statistics == null) return -1;
		return resultData.statistics.totalJobsSoFar;
	}//getTotalJobsSoFar
	
	
	/**
	 * Get the time last job ended. 
	 * @return the time last job ended. If none, it returns unix creation time: GregorianCalendar(1970, 0, 1, 0, 0, 0). 
	 */
	public GregorianCalendar getTimeLastJobEnded(){
		if(resultData.statistics == null) return new GregorianCalendar(1970, 0, 1, 0, 0, 0);
		return resultData.statistics.timeLastJobEnded;
	}//getTimeLastJobEnded
	
	/**
	 * Get the time last job took (in seconds). 
	 * @return the the time last job took, Double.NaN if none. 
	 */
	public double getTimeLastJobTook(){
		if(resultData.statistics == null) return Double.NaN;
		return resultData.statistics.timeLastJobTook;
	}//getTimeLastJobTook
	
	/**
	 * Get the time the service started. 
	 * @return the time last job ended. If none, it returns unix creation time: GregorianCalendar(1970, 0, 1, 0, 0, 0). 
	 */
	public GregorianCalendar getTimeServiceStarted(){
		if(resultData.statistics == null) return new GregorianCalendar(1970, 0, 1, 0, 0, 0);
		return resultData.statistics.timeServiceStarted;
	}//getTimeServiceStarted
	
	
	/**
	 * Get the service utilization ([0, 1]). 
	 * @return the the time last job took, Double.NaN if none. 
	 */
	public double getServiceUtilization(){
		if(resultData.statistics == null) return Double.NaN;
		return resultData.statistics.serviceUtilization;
	}//getServiceUtilization
	
	
	/**
	 * get a string array of names of other results. 
	 * 
	 * @return a string array of names of other results, null if no other results.  
	 */
	public String[] getOtherResultNames(){
		if(resultData.other == null) return null;
		int n = resultData.other.length;
		if(n <= 0) return null;
		String[] otherResultNames = new String[n];
		for(int i = 0; i < n; i++){
			otherResultNames[i] = resultData.other[i].name;
		}
		return otherResultNames;
	}//getOtherResultNames
	
	/**
	 * get a hashmap of other result descriptions. 
	 * The keys of the hashmap are the result names, and 
	 * the values of the hashmap are the result descriptions.  
	 * 
	 * @return a hashmap of other result descriptions, null if no other results. 
	 */
	public Hashtable<String, String>  getOtherResultDescriptions(){
		if(resultData.other == null) return null;
		int n = resultData.other.length;
		if(n <= 0) return null;
		Hashtable<String, String> otherResultDescriptions = new Hashtable<String, String>();
		for(int i = 0; i < n; i++){
			otherResultDescriptions.put(resultData.other[i].name, resultData.other[i].description);
		}
		return otherResultDescriptions;
	}//getOtherResultDescriptions

	/**
	 * get a hashmap of other result values. 
	 * The keys of the hashmap are the result names, and 
	 * the values of the hashmap are the result values.  
	 * 
	 * @return a hashmap of other result values, null if no other results. 
	 */
	public Hashtable<String, String>  getOtherResultValues(){
		if(resultData.other == null) return null;
		int n = resultData.other.length;
		if(n <= 0) return null;
		Hashtable<String, String> otherResultValues = new Hashtable<String, String>();
		for(int i = 0; i < n; i++){
			otherResultValues.put(resultData.other[i].name, resultData.other[i].value);
		}
		return otherResultValues;
	}//getOtherResultValues

	/**
	 * Get variable number. 
	 * 
	 * @return variable number, -1 if no information. 
	 */
	public int getVariableNumber(){
		if(m_iVariableNumber == -1){
			if(resultData.optimization == null) return -1;
			m_iVariableNumber = resultData.optimization.numberOfVariables;
		}
		return m_iVariableNumber;
	}//getVariableNumber

	/**
	 * Get objective number. 
	 * 
	 * @return objective number, -1 if no information. 
	 */
	public int getObjectiveNumber(){
		if(m_iObjectiveNumber == -1){
			if(resultData.optimization == null) return -1;
			m_iObjectiveNumber = resultData.optimization.numberOfObjectives;
		}
		return m_iObjectiveNumber;
	}//getObjectiveNumber
	
	/**
	 * Get constraint number. 
	 * 
	 * @return constraint number, -1 if no information. 
	 */
	public int getConstraintNumber(){
		if(m_iConstraintNumber == -1){
			if(resultData.optimization == null) return -1;
			m_iConstraintNumber = resultData.optimization.numberOfConstraints;
		}
		return m_iConstraintNumber;
	}//getConstraintNumber


	/**
	 * Get one solution of optimal primal variable values. 
	 * 
	 * @param objIdx holds the objective index the optimal value corresponds to. 
	 * @return a double dense array of the optimal values, null if no optimal value. 
	 */
	public double[] getOptimalPrimalVariableValues(int objIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || resultData.optimization.solution.length <= 0) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		int iSolutions = resultData.optimization.solution.length;
		double[] mdValues = null;
		for(int i = 0; i < iSolutions; i++){
			if(resultData.optimization.solution[i] == null) continue;
			if(resultData.optimization.solution[i].objectiveIdx != objIdx) continue;
			if(resultData.optimization.solution[i].variables == null) continue;
			if(resultData.optimization.solution[i].variables.values == null) continue;
			if((resultData.optimization.solution[i].status.type.endsWith("ptimal") && mdValues == null)||
				    resultData.optimization.solution[i].status.type.equals("globallyOptimal")){				
				VarValue[] var = resultData.optimization.solution[i].variables.values.var; 
				int iVars = (var==null)?0:var.length;
				mdValues = new double[iNumberOfVariables];
				for(int j = 0; j < iVars; j++){
					mdValues[var[j].idx] = var[j].value;
				}
			}	
			if(resultData.optimization.solution[i].status.type.equals("globallyOptimal")){
				return mdValues;
			}
		}
		return mdValues;		
	}//getOptimalPrimalVariableValues

	/**
	 * Get one solution of optimal primal variable string values.
	 *  
	 * @param objIdx holds the objective index the optimal value corresponds to. 
	 * @return a string dense array of the optimal string values, null if no optimal value. 
	 */
	public String[] getOptimalPrimalVariableStringValues(int objIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || resultData.optimization.solution.length <= 0) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		int iSolutions = resultData.optimization.solution.length;
		String[] msValues = null;
		for(int i = 0; i < iSolutions; i++){
			if(resultData.optimization.solution[i] == null) continue;
			if(resultData.optimization.solution[i].objectiveIdx != objIdx) continue;
			if(resultData.optimization.solution[i].variables == null) continue;
			if(resultData.optimization.solution[i].variables.valuesString == null) continue;
			if((resultData.optimization.solution[i].status.type.endsWith("ptimal") && msValues == null)||
			    resultData.optimization.solution[i].status.type.equals("globallyOptimal")){
				VarStringValue[] var = resultData.optimization.solution[i].variables.valuesString.var; 
				int iVars = (var==null)?0:var.length;
				msValues = new String[iNumberOfVariables];
				for(int j = 0; j < iVars; j++){
					msValues[var[j].idx] = var[j].value;
				}
			}	
			if(resultData.optimization.solution[i].status.type.equals("globallyOptimal")){
				return msValues;
			}
		}
		return msValues;		
	}//getOptimalPrimalVariableStringValues
	
	/**
	 * Get one solution of optimal dual variable values. 
	 * 
	 * @param objIdx holds the objective index the optimal value corresponds to. 
	 * @return a double dense array of the optimal dual values, null if no optimal value. 
	 */
	public double[] getOptimalDualVariableValues(int objIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || resultData.optimization.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = resultData.optimization.solution.length;
		double[] mdValues = null;
		for(int i = 0; i < iSolutions; i++){
			if(resultData.optimization.solution[i] == null) continue;
			if(resultData.optimization.solution[i].objectiveIdx != objIdx) continue;
			if(resultData.optimization.solution[i].constraints == null) continue;
			if(resultData.optimization.solution[i].constraints.dualValues == null) continue;
			if((resultData.optimization.solution[i].status.type.endsWith("ptimal") && mdValues == null)||
				    resultData.optimization.solution[i].status.type.equals("globallyOptimal")){				
				DualVarValue[] con = resultData.optimization.solution[i].constraints.dualValues.con; 
				int iCons = (con==null)?0:con.length;
				mdValues = new double[iNumberOfConstraints];
				for(int j = 0; j < iCons; j++){
					if(!Double.isNaN(con[j].lbValue) && con[j].lbValue != 0){
						mdValues[con[j].idx] = con[j].lbValue;
					}
					else if(!Double.isNaN(con[j].ubValue) && con[j].ubValue != 0){
						mdValues[con[j].idx] = con[j].ubValue;
					}
				}
			}	
			if(resultData.optimization.solution[i].status.type.equals("globallyOptimal")){
				return mdValues;
			}
		}
		return mdValues;		
	}//getOptimalDualVariableValues
	
	/**
	 * get the number of solutions. 
	 * 
	 * @return the number of solutions, 0 if none.  
	 */
	public int getSolutionNumber(){
		if(m_iSolutionNumber == -1){
			if(resultData.optimization == null) return -1;
			m_iSolutionNumber = resultData.optimization.numberOfSolutions;
		}
		return m_iSolutionNumber;
	}//getSolutionNumber
	
	/**
	 * Get the [i]th optimization solution, where i equals the given solution index.
	 *    
	 * @param solIdx holds the solution index to get the solution. 
	 * @return the optimization solution that corresponds to solIdx, null if none. 
	 */
	public OptimizationSolution getSolution(int solIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  resultData.optimization.solution.length) return null;
		return resultData.optimization.solution[solIdx];
	}//getSolution
	
	
	/**
	 * Get the [i]th optimization solution status, where i equals the given solution index.   
	 * The solution status includes the status type, optional descriptions and possibly substatuses.
	 *  
	 * @param solIdx holds the solution index to get the solution status. 
	 * @return the optimization solution status that corresponds to solIdx, null if none.
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolutionStatus
	 */
	public OptimizationSolutionStatus getSolutionStatus( int solIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  resultData.optimization.solution.length) return null;
		if(resultData.optimization.solution[solIdx] == null) return null;
		return resultData.optimization.solution[solIdx].status;
	}//getSolutionStatus
	
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
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  resultData.optimization.solution.length) return null;
		if(resultData.optimization.solution[solIdx] == null) return null;
		if(resultData.optimization.solution[solIdx].status == null) return null;
		return resultData.optimization.solution[solIdx].status.type;		
	}//getSolutionStatusType
	
	/**
	 * Get the [i]th optimization solution status description, where i equals the given solution index.   
	 * 
	 * @param solIdx holds the solution index to get the solution status description. 
	 * @return the optimization solution status description that corresponds to solIdx, null or empty string if none.
	 */
	public String getSolutionStatusDescription(int solIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  resultData.optimization.solution.length) return null;
		if(resultData.optimization.solution[solIdx] == null) return null;
		if(resultData.optimization.solution[solIdx].status == null) return null;
		return resultData.optimization.solution[solIdx].status.description;				
	}//getSolutionStatusDescription
	
	/**
	 * Get the [i]th optimization solution subStatuses, where i equals the given solution index.   
	 * 
	 * @param solIdx holds the solution index to get the solution substatuses. 
	 * @return an array optimization solution subStatuses that corresponds to solIdx, null or empty string if none.
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolutionSubstatus;
	 */
	public OptimizationSolutionSubstatus[] getSolutionSubStatuses(int solIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  resultData.optimization.solution.length) return null;
		if(resultData.optimization.solution[solIdx] == null) return null;
		if(resultData.optimization.solution[solIdx].status == null) return null;
		return resultData.optimization.solution[solIdx].status.substatus;				
	}//getSolutionSubStatuses

	/**
	 * Get the [i]th optimization solution message, where i equals the given solution index.  
	 * 
	 * @param solIdx holds the solution index to get the solution message. 
	 * @return the optimization solution message that corresponds to solIdx, null or empty if none.
	 */
	public String getSolutionMessage(int solIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  resultData.optimization.solution.length) return null;
		if(resultData.optimization.solution[solIdx] == null) return null;
		return resultData.optimization.solution[solIdx].message;
	}//getSolutionMessage
	
	/**
	 * Get the [i]th optimization solution's objective index, where i equals the given solution index. 
	 * The first objective's index should be -1, the second -2, and so on.  
	 * 
	 * @param solIdx holds the solution index to get the variable string values. 
	 * @return the optimization objective index that corresponds to solIdx, 0 if none.
	 * All the objective indexes are negative starting from -1 downward. 
	 */
	public int getSolutionObjectiveIndex(int solIdx){
		if(resultData.optimization == null) return 0;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  resultData.optimization.solution.length) return 0;
		if(resultData.optimization.solution[solIdx] == null) return 0;
		return resultData.optimization.solution[solIdx].objectiveIdx;		
	}//getSolutionObjectiveIndex
	
	/**
	 * Get the [i]th optimization solution's variable values, where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the variable values. 
	 * @return a double dense array of variable values, null if no variable values. 
	 */
	public double[] getVariableValues(int solIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || resultData.optimization.solution.length <= 0) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		int iSolutions = resultData.optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(resultData.optimization.solution[solIdx] == null) return null;
		if(resultData.optimization.solution[solIdx].variables == null) return null;
		if(resultData.optimization.solution[solIdx].variables.values == null) return null;
		VarValue[] var = resultData.optimization.solution[solIdx].variables.values.var; 
		int iVars = (var==null)?0:var.length;
		double[] mdValues = new double[iNumberOfVariables];
		for(int i = 0; i < iVars; i++){
			mdValues[var[i].idx] = var[i].value;
		}
		return mdValues;		
	}//getVariableValues
	
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
	public VariableValues getSparseVariableValues(int solIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || resultData.optimization.solution.length <= 0) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		int iSolutions = resultData.optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(resultData.optimization.solution[solIdx] == null) return null;
		if(resultData.optimization.solution[solIdx].variables == null) return null;
		return resultData.optimization.solution[solIdx].variables.values;
	}//getSparseVariableValues
	
	/**
	 * Get the [i]th optimization solution's variable string values, where i equals the given solution index. 
	 * 
	 * @param solIdx holds the solution index to get the variable string values. 
	 * @return a string dense array of variable values, null if no variable values. 
	 */
	public double[] getVariableStringValues(int solIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || resultData.optimization.solution.length <= 0) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		int iSolutions = resultData.optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(resultData.optimization.solution[solIdx] == null) return null;
		if(resultData.optimization.solution[solIdx].variables == null) return null;
		if(resultData.optimization.solution[solIdx].variables.values == null) return null;
		VarValue[] var = resultData.optimization.solution[solIdx].variables.values.var; 
		int iVars = (var==null)?0:var.length;
		double[] mdValues = new double[iNumberOfVariables];
		for(int i = 0; i < iVars; i++){
			mdValues[var[i].idx] = var[i].value;
		}
		return mdValues;		
	}//getVariableStringValues
	
	/**
	 * Get the [i]th optimization solution's primal unbounded directions, where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the primal unbounded directions. 
	 * @return a double dense array of primal variable unbounded directions, null if no values. 
	 */
	public double[] getPrimalUnboundedDirections(int solIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || resultData.optimization.solution.length <= 0) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		int iSolutions = resultData.optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(resultData.optimization.solution[solIdx] == null) return null;
		if(resultData.optimization.solution[solIdx].variables == null) return null;
		if(resultData.optimization.solution[solIdx].variables.primalUnboundedDirections == null) return null;
		PrimalVarUnboundedDirection[] var = resultData.optimization.solution[solIdx].variables.primalUnboundedDirections.var; 
		int iVars = (var==null)?0:var.length;
		double[] mdValues = new double[iNumberOfVariables];
		for(int i = 0; i < iVars; i++){
			mdValues[var[i].idx] = var[i].value;
		}
		return mdValues;		
	}//getPrimalUnboundedDirections
	
	/**
	 * Get the [i]th optimization solution's Irreducible Inconsistent System (IIS), where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the IIS. 
	 * @return an Irreducible Inconsistent System (IIS) in the VariableIrreducibleInconsistentSystem data structure, null if none.
	 * The data structure holds an array var[]; each var member holds the variable idx and a type value (lb or ub) to indicate
	 * whether the IIS is on the variable's lower bound or upper bound. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.VariableIrreducibleInconsistentSystem
	 */
	public VariableIrreducibleInconsistentSystem getVariableIrreducibleInconsistentSystem(int solIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || resultData.optimization.solution.length <= 0) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		int iSolutions = resultData.optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(resultData.optimization.solution[solIdx] == null) return null;
		if(resultData.optimization.solution[solIdx].variables == null) return null;
		return resultData.optimization.solution[solIdx].variables.irreducibleInconsistentSystem;		
	}//getVariableIrreducibleInconsistentSystem
	
	/**
	 * Get the [i]th optimization solution's reduced costs, where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the reduced costs. 
	 * @return the reduced costs in the ReducedCosts data structure, null if none.
	 * The data structure holds an array var[]; each var member holds 
	 * a variable idx, a reduced cost value on the lower bound (lbValue) and on the upper bound (ubValue). 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.ReducedCosts
	 */
	public ReducedCosts getReducedCosts(int solIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || resultData.optimization.solution.length <= 0) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		int iSolutions = resultData.optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(resultData.optimization.solution[solIdx] == null) return null;
		if(resultData.optimization.solution[solIdx].variables == null) return null;
		return resultData.optimization.solution[solIdx].variables.reducedCosts;		
	}//getReducedCosts
	
	/**
	 * Get the [i]th optimization solution's variable slacks, where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the variable slacks. 
	 * @return the variable slacks in the VariableSlacks data structure, null if none.
	 * The data structure holds an array var[]; each var member holds 
	 * a variable idx, a slack value on the lower bound (lbValue) and on the upper bound (ubValue). 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.VariableSlacks
	 */
	public VariableSlacks getVariableSlacks(int solIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || resultData.optimization.solution.length <= 0) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		int iSolutions = resultData.optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(resultData.optimization.solution[solIdx] == null) return null;
		if(resultData.optimization.solution[solIdx].variables == null) return null;
		return resultData.optimization.solution[solIdx].variables.slacks;		
	}//getVariableSlacks
	
	/**
	 * Get the [i]th optimization solution's variable allowable increases, where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the variable allowable incresases. 
	 * @return the variable allowable incresases in the VariableAllowableIncreases data structure, null if none.
	 * The data structure holds an array var[]; each var member holds 
	 * a variable idx, an allowable increase value on the lower bound (lbValue) and on the upper bound (ubValue). 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.VariableAllowableIncreases
	 */
	public VariableAllowableIncreases getVariableAllowableIncreases(int solIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || resultData.optimization.solution.length <= 0) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		int iSolutions = resultData.optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(resultData.optimization.solution[solIdx] == null) return null;
		if(resultData.optimization.solution[solIdx].variables == null) return null;
		return resultData.optimization.solution[solIdx].variables.allowableIncreases;		
	}//getVariableAllowableIncreases
	
	/**
	 * Get the [i]th optimization solution's variable allowable decreases, where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the variable allowable decresases. 
	 * @return the variable allowable decresases in the VariableAllowableDecreases data structure, null if none.
	 * The data structure holds an array var[]; each var member holds 
	 * a variable idx, an allowable decrease value on the lower bound (lbValue) and on the upper bound (ubValue). 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.VariableAllowableDecreases
	 */
	public VariableAllowableDecreases getVariableAllowableDecreases(int solIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || resultData.optimization.solution.length <= 0) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		int iSolutions = resultData.optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(resultData.optimization.solution[solIdx] == null) return null;
		if(resultData.optimization.solution[solIdx].variables == null) return null;
		return resultData.optimization.solution[solIdx].variables.allowableDecreases;		
	}//getVariableAllowableDecreases
	
	/**
	 * Get the [i]th optimization solution's variable OVFunctions, where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the variable OVFunctions. 
	 * @return the variable OVFunctions in the VariableOVFunctions data structure, null if none.
	 * The data structure holds an array varBound[]; each varBound member corresponds to one OVFunction. 
	 * The varBound type can be eq, lb or ub and the varBound holds an idx for the index of the variable. 
	 * An OVFunction is a sequence (or array) of intervals, each interval contains a start value, an end value and a slope value. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.VariableOVFunctions
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OVFunction
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OVFunctionInterval
	 */
	public VariableOVFunctions getVariableOVFunctions(int solIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || resultData.optimization.solution.length <= 0) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		int iSolutions = resultData.optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(resultData.optimization.solution[solIdx] == null) return null;
		if(resultData.optimization.solution[solIdx].variables == null) return null;
		return resultData.optimization.solution[solIdx].variables.ovFunctions;		
	}//getVariableOVFunctions
	
	/**
	 * Get the [i]th optimization solution's other (non-standard/solver specific)variable-related results, 
	 * where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the other variable results. 
	 * @return an array of other variable results in OtherVariableResult[] array data structure, null if none. 
	 * Each other variable result contains the name (required), an optional description (string) and an optional
	 * value (string). Each other variable result can also optionally contain an array OtherVarResult for each variable. 
	 * The OtherVarResult contains a variable idx (required), an optional string value, an optional string value on the lower bound (lbValue) 
	 * and an optional string value on the upper bound (ubValue).  
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherVariableResult
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherVarResult
	 */
	public OtherVariableResult[] getOtherVariableResults(int solIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || resultData.optimization.solution.length <= 0) return null;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return null;
		int iSolutions = resultData.optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(resultData.optimization.solution[solIdx] == null) return null;
		if(resultData.optimization.solution[solIdx].variables == null) return null;
		return resultData.optimization.solution[solIdx].variables.other;	
	}//getOtherVariableResults
	
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
	public double[] getObjectiveValues(int solIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || resultData.optimization.solution.length <= 0) return null;
		int iNumberOfObjectives = this.getObjectiveNumber();
		if(iNumberOfObjectives <= 0) return null;
		int iSolutions = resultData.optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(resultData.optimization.solution[solIdx] == null) return null;
		if(resultData.optimization.solution[solIdx].objectives == null) return null;
		if(resultData.optimization.solution[solIdx].objectives.values == null) return null;
		ObjValue[] obj = resultData.optimization.solution[solIdx].objectives.values.obj; 
		int iObjs = (obj==null)?0:obj.length;
		double[] mdValues = new double[iNumberOfObjectives];
		for(int i = 0; i < iNumberOfObjectives; i++){
			mdValues[i] = Double.NaN;
		}
		for(int i = 0; i < iObjs; i++){
			mdValues[Math.abs(obj[i].idx)-1] = obj[i].value;
		}
		return mdValues;		
	}//getObjectiveValues
	
	/**
	 * Get the [i]th optimization solution's objective OVFunctions, where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the objective OVFunctions. 
	 * @return the objective OVFunctions in the ObjectiveOVFunctions data structure, null if none.
	 * The data structure holds an array varCoef[]; each varCoef member corresponds to one OVFunction (for each of the objective's variable coefficients). 
	 * The varCoef holds an idx for the index of the variable. 
	 * An OVFunction is a sequence (or array) of intervals, each interval contains a start value, an end value and a slope value. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.ObjectiveOVFunctions
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OVFunction
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OVFunctionInterval
	 */
	public ObjectiveOVFunctions getObjectiveOVFunctions(int solIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || resultData.optimization.solution.length <= 0) return null;
		int iNumberOfObjectives = this.getObjectiveNumber();
		if(iNumberOfObjectives <= 0) return null;
		int iSolutions = resultData.optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(resultData.optimization.solution[solIdx] == null) return null;
		if(resultData.optimization.solution[solIdx].objectives == null) return null;
		return resultData.optimization.solution[solIdx].objectives.ovFunctions;		
	}//getObjectiveOVFunctions
	
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
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || resultData.optimization.solution.length <= 0) return null;
		int iNumberOfObjectives = this.getObjectiveNumber();
		if(iNumberOfObjectives <= 0) return null;
		int iSolutions = resultData.optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(resultData.optimization.solution[solIdx] == null) return null;
		if(resultData.optimization.solution[solIdx].objectives == null) return null;
		return resultData.optimization.solution[solIdx].objectives.other;	
	}//getOtherObjectiveResults
	
	/**
	 * Get the [i]th optimization solution's constraint values, where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the constraint values. 
	 * @return a double dense array of constraint values, null if no constraint values. 
	 */
	public double[] getConstraintValues(int solIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || resultData.optimization.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = resultData.optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(resultData.optimization.solution[solIdx] == null) return null;
		if(resultData.optimization.solution[solIdx].constraints == null) return null;
		if(resultData.optimization.solution[solIdx].constraints.values == null) return null;
		ConValue[] con = resultData.optimization.solution[solIdx].constraints.values.con; 
		int iCons = (con==null)?0:con.length;
		double[] mdValues = new double[iNumberOfConstraints];
		for(int i = 0; i < iCons; i++){
			mdValues[con[i].idx] = con[i].value;
		}
		return mdValues;		
	}//getConstraintValues
	
	/**
	 * Get the [i]th optimization solution's constraint values in a sparse data structure, where i equals the given solution index. 
	 * The sparse data stucture is of the ConstraintValues datastructure. ConstraintValues holds con[], an array of ConValues. 
	 * Each con member contains an idx and a value. If con[] is null, all the constraint values are 0. 
	 * 
	 * @param solIdx holds the solution index to get the sparse constraint values. 
	 * @return a sparse constraint value data structure in ConstraintValues, null if no constraint values. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.ConstraintValues
	 * @see org.optimizationservices.oscommon.datastructure.osresult.ConValue
	 */
	public ConstraintValues getSparseConstraintValues(int solIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || resultData.optimization.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = resultData.optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(resultData.optimization.solution[solIdx] == null) return null;
		if(resultData.optimization.solution[solIdx].constraints == null) return null;
		return resultData.optimization.solution[solIdx].constraints.values;
	}//getSparseConstraintValues

	/**
	 * Get the [i]th optimization solution's dual variable unbounded directions at the lower bounds, where i equals the given solution index. 
	 * 
	 * @param solIdx holds the solution index to get the dual variable unbounded directions at the lower bounds. 
	 * @return a double dense array of the dual variable unbounded directions at the lower bounds, null if none. 
	 */
	public double[] getDualUnboundedDirectionsAtLowerBounds(int solIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || resultData.optimization.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = resultData.optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(resultData.optimization.solution[solIdx] == null) return null;
		if(resultData.optimization.solution[solIdx].constraints == null) return null;
		if(resultData.optimization.solution[solIdx].constraints.dualUnboundedDirections == null) return null;
		DualVarUnboundedDirection[] con = resultData.optimization.solution[solIdx].constraints.dualUnboundedDirections.con; 
		int iCons = (con==null)?0:con.length;
		double[] mdValues = new double[iNumberOfConstraints];
		for(int j = 0; j < iCons; j++){
			if(!Double.isNaN(con[j].lbValue)){
				mdValues[con[j].idx] = con[j].lbValue;
			}
		}
		return mdValues;				
	}//getDualVariableUnboundedAtLowerBounds
	
	/**
	 * Get the [i]th optimization solution's dual variable unbounded directions at the upper bounds, where i equals the given solution index. 
	 * 
	 * @param solIdx holds the solution index to get the dual variable unbounded directions at the upper bounds. 
	 * @return a double dense array of the dual variable unbounded directions at the upper bounds, null if none. 
	 */
	public double[] getDualUnboundedDirectionsAtUpperBounds(int solIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || resultData.optimization.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = resultData.optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(resultData.optimization.solution[solIdx] == null) return null;
		if(resultData.optimization.solution[solIdx].constraints == null) return null;
		if(resultData.optimization.solution[solIdx].constraints.dualUnboundedDirections == null) return null;
		DualVarUnboundedDirection[] con = resultData.optimization.solution[solIdx].constraints.dualUnboundedDirections.con; 
		int iCons = (con==null)?0:con.length;
		double[] mdValues = new double[iNumberOfConstraints];
		for(int j = 0; j < iCons; j++){
			if(!Double.isNaN(con[j].ubValue)){
				mdValues[con[j].idx] = con[j].ubValue;
			}
		}
		return mdValues;				
	}//getDualVariableUnboundedAtUpperBounds
	
	/**
	 * Get the [i]th optimization solution's dual variable unbounded directions in a sparse data structure, where i equals the given solution index. 
	 * The sparse data stucture is of the DualVariableUnboundedDirections data structure. DualVariableUnboundedDirections holds con[], an array of DualVarUnboundedDirections. 
	 * Each con member contains a constraint idx, a dual unbounded direction on the upper bound and lower bound. If con[] is null, all the dual variable unbounded directions are 0. 
	 * 
	 * @param solIdx holds the solution index to get the sparse dual variable unbounded directions. 
	 * @return a sparse variable unbounded direction data structure in DualVaribleUnboundedDirections, null if no dual unbounded directions. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.DualVariableUnboundedDirections
	 * @see org.optimizationservices.oscommon.datastructure.osresult.DualVarUnboundedDirection
	 */
	public DualVariableUnboundedDirections getSparseDualUnboundedDirections(int solIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || resultData.optimization.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = resultData.optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(resultData.optimization.solution[solIdx] == null) return null;
		if(resultData.optimization.solution[solIdx].constraints == null) return null;
		return resultData.optimization.solution[solIdx].constraints.dualUnboundedDirections;
	}//getSparseDualVariableUnboundedDirections
	
	/**
	 * Get the [i]th optimization solution's Irreducible Inconsistent System (IIS), where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the IIS. 
	 * @return an Irreducible Inconsistent System (IIS) in the ConstraintIrreducibleInconsistentSystem data structure, null if none.
	 * The data structure holds an array con[]; each con member holds the constraint idx and a type value (lb or ub) to indicate
	 * whether the IIS is on the constraint's lower bound or upper bound. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.ConstraintIrreducibleInconsistentSystem
	 */
	public ConstraintIrreducibleInconsistentSystem getConstraintIrreducibleInconsistentSystem(int solIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || resultData.optimization.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = resultData.optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(resultData.optimization.solution[solIdx] == null) return null;
		if(resultData.optimization.solution[solIdx].constraints == null) return null;
		return resultData.optimization.solution[solIdx].constraints.irreducibleInconsistentSystem;		
	}//getConstraintIrreducibleInconsistentSystem
	
	/**
	 * Get the [i]th optimization solution's dual variable values at the lower bounds, where i equals the given solution index. 
	 * 
	 * @param solIdx holds the solution index to get the dual variable values at the lower bounds. 
	 * @return a double dense array of the dual variable values at the lower bounds, null if none. 
	 */
	public double[] getDualVariableValuesAtLowerBounds(int solIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || resultData.optimization.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = resultData.optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(resultData.optimization.solution[solIdx] == null) return null;
		if(resultData.optimization.solution[solIdx].constraints == null) return null;
		if(resultData.optimization.solution[solIdx].constraints.dualValues == null) return null;
		DualVarValue[] con = resultData.optimization.solution[solIdx].constraints.dualValues.con; 
		int iCons = (con==null)?0:con.length;
		double[] mdValues = new double[iNumberOfConstraints];
		for(int j = 0; j < iCons; j++){
			if(!Double.isNaN(con[j].lbValue)){
				mdValues[con[j].idx] = con[j].lbValue;
			}
		}
		return mdValues;				
	}//getDualVariableValuesAtLowerBounds
	
	
	/**
	 * Get the [i]th optimization solution's dual variable values at the upper bounds, where i equals the given solution index. 
	 * 
	 * @param solIdx holds the solution index to get the dual variable values at the upper bounds. 
	 * @return a double dense array of the dual variable values at the upper bounds, null if none. 
	 */
	public double[] getDualVariableValuesAtUpperBounds(int solIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || resultData.optimization.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = resultData.optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(resultData.optimization.solution[solIdx] == null) return null;
		if(resultData.optimization.solution[solIdx].constraints == null) return null;
		if(resultData.optimization.solution[solIdx].constraints.dualValues == null) return null;
		DualVarValue[] con = resultData.optimization.solution[solIdx].constraints.dualValues.con; 
		int iCons = (con==null)?0:con.length;
		double[] mdValues = new double[iNumberOfConstraints];
		for(int j = 0; j < iCons; j++){
			if(!Double.isNaN(con[j].ubValue)){
				mdValues[con[j].idx] = con[j].ubValue;
			}
		}
		return mdValues;				
	}//getDualVariableValuesAtUpperBounds
	
	/**
	 * Get the [i]th optimization solution's dual variable values in a sparse data structure, where i equals the given solution index. 
	 * The sparse data stucture is of the DualVariableValues data structure. DualVariableValues holds con[], an array of DualVarValues. 
	 * Each con member contains a constraint idx, a dual value on the lower bound and upper bound. If con[] is null, all the dual variable values are 0. 
	 * 
	 * @param solIdx holds the solution index to get the sparse dual variable values. 
	 * @return a sparse variable value data structure in DualVaribleValues, null if no dual variable values. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.DualVariableValues
	 * @see org.optimizationservices.oscommon.datastructure.osresult.DualVarValue
	 */
	public DualVariableValues getSparseDualVariableValues(int solIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || resultData.optimization.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = resultData.optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(resultData.optimization.solution[solIdx] == null) return null;
		if(resultData.optimization.solution[solIdx].constraints == null) return null;
		return resultData.optimization.solution[solIdx].constraints.dualValues;
	}//getSparseDualVariableValues
	
	/**
	 * Get the [i]th optimization solution's constraint slacks, where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the constraint slacks. 
	 * @return the constraint slacks in the ConstraintSlacks data structure, null if none.
	 * The data structure holds an array con[]; each con member holds 
	 * a constraint idx, a slack value on the lower bound (lbValue) and on the upper bound (ubValue). 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.ConstraintSlacks
	 */
	public ConstraintSlacks getConstraintSlacks(int solIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || resultData.optimization.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = resultData.optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(resultData.optimization.solution[solIdx] == null) return null;
		if(resultData.optimization.solution[solIdx].constraints == null) return null;
		return resultData.optimization.solution[solIdx].constraints.slacks;		
	}//getConstraintSlacks
	
	/**
	 * Get the [i]th optimization solution's constraint allowable increases, where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the constraint allowable incresases. 
	 * @return the constraint allowable incresases in the ConstraintAllowableIncreases data structure, null if none.
	 * The data structure holds an array con[]; each con member holds 
	 * a constraint idx, an allowable increase value on the lower bound (lbValue) and on the upper bound (ubValue). 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.ConstraintAllowableIncreases
	 */
	public ConstraintAllowableIncreases getConstraintAllowableIncreases(int solIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || resultData.optimization.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = resultData.optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(resultData.optimization.solution[solIdx] == null) return null;
		if(resultData.optimization.solution[solIdx].constraints == null) return null;
		return resultData.optimization.solution[solIdx].constraints.allowableIncreases;		
	}//getConstraintAllowableIncreases
	
	/**
	 * Get the [i]th optimization solution's constraint allowable decreases, where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the constraint allowable decresases. 
	 * @return the constraint allowable decresases in the ConstraintAllowableDecreases data structure, null if none.
	 * The data structure holds an array con[]; each con member holds 
	 * a constraint idx, an allowable decrease value on the lower bound (lbValue) and on the upper bound (ubValue). 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.ConstraintAllowableDecreases
	 */
	public ConstraintAllowableDecreases getConstraintAllowableDecreases(int solIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || resultData.optimization.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = resultData.optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(resultData.optimization.solution[solIdx] == null) return null;
		if(resultData.optimization.solution[solIdx].constraints == null) return null;
		return resultData.optimization.solution[solIdx].constraints.allowableDecreases;		
	}//getConstraintAllowableDecreases
	
	/**
	 * Get the [i]th optimization solution's constraint OVFunctions, where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the constraint OVFunctions. 
	 * @return the constraint OVFunctions in the ConstraintOVFunctions data structure, null if none.
	 * The data structure holds an array conBound[]; each conBound member corresponds to one OVFunction. 
	 * The conBound type can be eq, lb or ub and the conBound holds an idx for the index of the constraint. 
	 * An OVFunction is a sequence (or array) of intervals, each interval contains a start value, an end value and a slope value. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.ConstraintOVFunctions
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OVFunction
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OVFunctionInterval
	 */
	public ConstraintOVFunctions getConstraintOVFunctions(int solIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || resultData.optimization.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = resultData.optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(resultData.optimization.solution[solIdx] == null) return null;
		if(resultData.optimization.solution[solIdx].constraints == null) return null;
		return resultData.optimization.solution[solIdx].constraints.ovFunctions;		
	}//getConstraintOVFunctions
	
	/**
	 * Get the [i]th optimization solution's other (non-standard/solver specific)constraint-related results, 
	 * where i equals the given solution index. 
	 *  
	 * @param solIdx holds the solution index to get the other constraint results. 
	 * @return an array of other constraint results in OtherConstraintResult[] array data structure, null if none. 
	 * Each other constraint result contains the name (required), an optional description (string) and an optional
	 * value (string). Each other constraint result can also optionally contain an array OtherConResult for each constraint. 
	 * The OtherConResult contains a constraint idx (required), an optional string value, an optional string value on the lower bound (lbValue) 
	 * and an optional string value on the upper bound (ubValue).  
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherConstraintResult
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherConResult
	 */
	public OtherConstraintResult[] getOtherConstraintResults(int solIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || resultData.optimization.solution.length <= 0) return null;
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return null;
		int iSolutions = resultData.optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(resultData.optimization.solution[solIdx] == null) return null;
		if(resultData.optimization.solution[solIdx].constraints == null) return null;
		return resultData.optimization.solution[solIdx].constraints.other;	
	}//getOtherConstraintResults

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
	public OtherOptimizationResult[] getOtherOptimizationResults(int solIdx){
		if(resultData.optimization == null) return null;
		if(resultData.optimization.solution == null || resultData.optimization.solution.length <= 0) return null;
		int iSolutions = resultData.optimization.solution.length;
		if(solIdx < 0 || solIdx >= iSolutions) return null;
		if(resultData.optimization.solution[solIdx] == null) return null;
		return resultData.optimization.solution[solIdx].other;	
	}//getOtherOptimizationResults


	/**
	 * Get the optimization analysis in the standard OSAnalysis data structure. 
	 * 
	 * @return the optimization analysis in the standard OSAnalysis data structure, null if none.
	 * @see org.optimizationservices.oscommon.localinterface.OSAnalysis
	 */
	public OSAnalysis getOSAnalysis(){
		if(resultData.optimization == null) return null;
		return resultData.optimization.osal;
	}//getOSAnalysis
	

   	/**
	 * Set service name.
	 * 
	 * @param serviceName holds the name of the service. 
	 * @return whether the service name is set successfully. 
	 */
	public boolean setServiceName(String serviceName){
		resultHeader.serviceName = serviceName;
		return true;
	}//setServiceName
	
   	/**
	 * Set service uri.
	 * 
	 * @param serviceURI holds the uri of the service. 
	 * @return whether the service uri is set successfully. 
	 */
	public boolean setServiceURI(String serviceURI){
		resultHeader.serviceURI = serviceURI;
		return true;
	}//setServiceURI
	
   	/**
	 * Set instance name.
	 * 
	 * @param instanceName holds the name of the instance. 
	 * @return whether the instance name is set successfully. 
	 */
	public boolean setInstanceName(String instanceName){
		resultHeader.instanceName = instanceName;
		return true;
	}//setInstanceName
	
   	/**
	 * Set job id.
	 * 
	 * @param jobID holds the job id. 
	 * @return whether the job id is set successfully. 
	 */
	public boolean setJobID(String jobID){
		resultHeader.jobID = jobID;
		return true;
	}//setJobID
	
   	/**
	 * Set time of the result.
	 * 
	 * @param time holds the time of the result.
	 * @return whether result time is set successfully. 
	 */
	public boolean setResultTime(GregorianCalendar time){
		resultHeader.time = time;
		return true;
	}//setResultTime
	
   	/**
	 * Set the general message. 
	 * 
	 * @param message holds the general message. 
	 * @return whether process message is set successfully. 
	 */
	public boolean setGeneralMessage(String message){
		resultHeader.message = message;
		return true;
	}//setGeneralMessage
	
   	/**
	 * Set the general status
	 * 
	 * @param status holds the general status.
	 * @return whether the general status is set successfully. 
	 */
	public boolean setGeneralStatus(GeneralStatus status){
		resultHeader.generalStatus = status;
		return true;
	}//setGeneralStatus
	
   	/**
	 * Set the general status type, which can be: 
	 * success, error, warning. 
	 * 
	 * @param type holds the general status type
	 * @return whether the general status type is set successfully or not. 
	 */
	public boolean setGeneralStatusType(String type){
		if(resultHeader.generalStatus == null) resultHeader.generalStatus = new GeneralStatus();
		resultHeader.generalStatus.type = type;
		return true;
	}//setGeneralStatusType

   	/**
	 * Set the general status description. 
	 * 
	 * @param description holds the general status description.
	 * @return whether the general status description is set successfully or not. 
	 */
	public boolean setGeneralStatusDescription(String description){
		if(resultHeader.generalStatus == null) resultHeader.generalStatus = new GeneralStatus();
		resultHeader.generalStatus.description = description;
		return true;
	}//setGeneralStatusDescription
	
	/**
	 * Set the process statistics. 
	 * 
	 * @param processStatistics holds the process statistics. 
	 * @return whether the process statistics is set successfully. 
	 */
	public boolean setProcessStatistics(ProcessStatistics processStatistics){
		resultData.statistics = processStatistics;
		return true;
	}//setprocessStatistics
	
	/**
	 * Set the statistics of all jobs. 
	 * 
	 * @param jobStatistics holds an array of jobStatistics with 
	 * each member corresponding to one job. 
	 * @return whether the job statistics are set successfully. 
	 */
	public boolean setJobStatistics(JobStatistics[] jobStatistics){
		if(resultData.statistics == null) resultData.statistics = new ProcessStatistics();
		if(resultData.statistics.jobs == null) resultData.statistics.jobs = new Jobs();
		resultData.statistics.jobs.job = jobStatistics;
		return true;
	}//setJobStatistics
	

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
		if(resultData.statistics == null) resultData.statistics = new ProcessStatistics();
		resultData.statistics.currentState = currentState;
		return true;
	}//setCurrentState
	

	/**
	 * Set the available disk space. 
	 * @param availableDiskSpace holds the available disk space (in bytes). 
	 * @return whether the available disk space is set successfully.
	 */
	public boolean setAvailableDiskSpace(double availableDiskSpace){
		if(resultData.statistics == null) resultData.statistics = new ProcessStatistics();
		resultData.statistics.availableDiskSpace = availableDiskSpace;
		return true;
	}//setAvailableDiskSpace
	
	/**
	 * Set the available memory (in bytes). 
	 * @param availableMemory holds the available memory. 
	 * @return whether the available memory is set successfully.
	 */
	public boolean setAvailableMemory(double availableMemory){
		if(resultData.statistics == null) resultData.statistics = new ProcessStatistics();
		resultData.statistics.availableMemory = availableMemory;
		return true;
	}//setAvailableMemory
	
	
	/**
	 * Set the current job count. 
	 * @param currentJobCount holds the current job count. 
	 * @return whether the current job count is set successfully.
	 */
	public boolean setCurrentJobCount(int currentJobCount){
		if(resultData.statistics == null) resultData.statistics = new ProcessStatistics();
		resultData.statistics.currentJobCount = currentJobCount;
		return true;
	}//setCurrentJobCount
	
	/**
	 * Set the total jobs received so far. 
	 * @param totalJobsSoFar holds the total jobs received so far. 
	 * @return whether the total jobs so far is set successfully.
	 */
	public boolean setTotalJobsSoFar(int totalJobsSoFar){
		if(resultData.statistics == null) resultData.statistics = new ProcessStatistics();
		resultData.statistics.totalJobsSoFar = totalJobsSoFar;
		return true;
	}//setTotalJobsSoFar
	
	/**
	 * Set the time last job ended. 
	 * @param timeLastJobEnded holds the time last job ended. 
	 * @return whether the time last job ended is set successfully.
	 */
	public boolean setTimeLastJobEnded(GregorianCalendar timeLastJobEnded){
		if(resultData.statistics == null) resultData.statistics = new ProcessStatistics();
		resultData.statistics.timeLastJobEnded = timeLastJobEnded;
		return true;
	}//setTimeLastJobEnded
	
	/**
	 * Set the time last job took. 
	 * @param timeLastJobTook holds the time last job took (in seconds). 
	 * @return whether the time last job took is set successfully.
	 */
	public boolean setTimeLastJobTook(double timeLastJobTook){
		if(resultData.statistics == null) resultData.statistics = new ProcessStatistics();
		resultData.statistics.timeLastJobTook = timeLastJobTook;
		return true;
	}//setTimeLastJobTook
	
	/**
	 * Set the time the service started. 
	 * @param timeServiceStarted holds the time the service started. 
	 * @return whether the time the service started is set successfully.
	 */
	public boolean setTimeServiceStarted(GregorianCalendar timeServiceStarted){
		if(resultData.statistics == null) resultData.statistics = new ProcessStatistics();
		resultData.statistics.timeServiceStarted = timeServiceStarted;
		return true;
	}//setTimeServiceStarted
	
	/**
	 * Set the service utilization. 
	 * @param serviceUtilization holds the service utilization ([0, 1]). 
	 * @return whether the time last job took is set successfully.
	 */
	public boolean setServiceUtilization(double serviceUtilization){
		if(resultData.statistics == null) resultData.statistics = new ProcessStatistics();
		resultData.statistics.serviceUtilization = serviceUtilization;
		return true;
	}//setServiceUtilization
	
	/**
	 * set other results, with their names (required), descriptions (optional) and values (optional). 
	 * 
	 * @param names holds the names of the other results; it is required.  
	 * @param descriptions holds the descriptions of the other results; null if none. 
	 * @param values holds the values of the other results; null if none. 
	 * @return whether the other anlysis information is set successfully. 
	 */
	public boolean setOtherResults(String[] names, String[] descriptions, String[] values){
		if(names == null) return false;
		if(descriptions != null && descriptions.length != names.length) return false;
		if(values != null && values.length != names.length) return false;
		int n = names.length;
		resultData.other = new OtherResult[n];
		for(int i = 0; i < n; i++){
			resultData.other[i] = new OtherResult();
		}
		for(int i = 0; i < n; i++){
			resultData.other[i].name = names[i];
		}
		if(descriptions != null){
			for(int i = 0; i < n; i++){
				resultData.other[i].description = descriptions[i];
			}	
		}
		if(values != null){
			for(int i = 0; i < n; i++){
				resultData.other[i].value = values[i];
			}	
		}
		return true;
	}//setOtherResults
	
	/**
	 * Set the variable number. 
	 * 
	 * @param variableNumber holds the number of variables
	 * @return whether the variable number is set successfully or not. 
	 */
	public boolean setVariableNumber(int variableNumber){
		if(variableNumber <= 0){
			return false;
		}
		if(resultData.optimization == null) resultData.optimization = new OptimizationResult();
		resultData.optimization.numberOfVariables = variableNumber;
		return true;
	}//setVariableNumber

	/**
	 * Set the objective number. 
	 * 
	 * @param objectiveNumber holds the number of objectives
	 * @return whether the objective number is set successfully or not. 
	 */
	public boolean setObjectiveNumber(int objectiveNumber){
		if(objectiveNumber < 0){
			return false;
		}
		if(resultData.optimization == null) resultData.optimization = new OptimizationResult();
		resultData.optimization.numberOfObjectives = objectiveNumber;
		return true;
	}//setObjectiveNumber

	/**
	 * Set the constraint number. 
	 * 
	 * @param constraintNumber holds the number of constraints
	 * @return whether the constraint number is set successfully or not. 
	 */
	public boolean setConstraintNumber(int constraintNumber){
		if(constraintNumber < 0){
			return false;
		}
		if(resultData.optimization == null) resultData.optimization = new OptimizationResult();
		resultData.optimization.numberOfConstraints = constraintNumber;
		return true;
	}//setConstraintNumber

	
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
		if(getVariableNumber() <= 0) return false;
		if(getObjectiveNumber() < 0) return false;
		if(getConstraintNumber() < 0) return false;
		if(solutionNumber < 0) return false; 
		if(resultData.optimization == null) resultData.optimization = new OptimizationResult();
		resultData.optimization.numberOfSolutions = solutionNumber;
		if(solutionNumber == 0) return true;
		resultData.optimization.solution = new OptimizationSolution[solutionNumber];
		for(int i = 0; i < solutionNumber; i++){
			resultData.optimization.solution[i] = new OptimizationSolution();
		}
		return true;
	}//setSolutionNumber
	
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
		if(resultData.optimization == null) return false;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  nSols) return false;
		resultData.optimization.solution[solIdx] = solution;
		return true;
	}//setSolution	
	
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
		if(resultData.optimization == null) return false;
		if(nSols <= 0) return false;
		if(resultData.optimization == null) return false;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  nSols) return false;
		if(resultData.optimization.solution[solIdx] == null){
			resultData.optimization.solution[solIdx] = new OptimizationSolution();
		}
		resultData.optimization.solution[solIdx].status = status;
		return true;
	}//setSolutionStatus
	
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
		if(resultData.optimization == null) return false;
		if(nSols <= 0) return false;
		if(resultData.optimization == null) return false;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  nSols) return false;
		if(resultData.optimization.solution[solIdx] == null){
			resultData.optimization.solution[solIdx] = new OptimizationSolution();
		}
		resultData.optimization.solution[solIdx].status = new OptimizationSolutionStatus();
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
		resultData.optimization.solution[solIdx].status.type = type;
		resultData.optimization.solution[solIdx].status.description = description;
		resultData.optimization.solution[solIdx].status.substatus = subStatuses;
		return true;
	}//setSolutionStatus
	
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
		if(resultData.optimization == null) return false;
		if(nSols <= 0) return false;
		if(resultData.optimization == null) return false;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  nSols) return false;
		if(resultData.optimization.solution[solIdx] == null){
			resultData.optimization.solution[solIdx] = new OptimizationSolution();
		}
		resultData.optimization.solution[solIdx].message = solutionMessage;
		return true;
	}//setSolutionMessage	
	
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
	public boolean setSolutionObjectiveIndex(int solIdx, int objectiveIdx){
		int nSols = this.getSolutionNumber();
		if(resultData.optimization == null) return false;
		if(nSols <= 0) return false;
		if(resultData.optimization == null) return false;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  nSols) return false;
		if(resultData.optimization.solution[solIdx] == null){
			resultData.optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(objectiveIdx >= 0) return false;
		resultData.optimization.solution[solIdx].objectiveIdx = objectiveIdx;
		return true;		
	}//setSolutionObjectiveIndex
	
	/**
	 * Set the [i]th optimization solution's primal variable values, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the primal variable values. 
	 * @param x holds a double dense array of variable values to set; it could be null if all variables are 0.
	 * 
	 * @return whether primal variable values are set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setPrimalVariableValues(int solIdx, double[] x){
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return false;
		if(x != null && x.length != iNumberOfVariables) return false;
		int nSols = this.getSolutionNumber();
		if(resultData.optimization == null) return false;
		if(nSols <= 0) return false;
		if(resultData.optimization == null) return false;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  nSols) return false;
		if(resultData.optimization.solution[solIdx] == null){
			resultData.optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(resultData.optimization.solution[solIdx].variables == null){
			resultData.optimization.solution[solIdx].variables = new VariableSolution();
		}
		if(resultData.optimization.solution[solIdx].variables.values == null){
			resultData.optimization.solution[solIdx].variables.values = new VariableValues();
		}
		if(x == null){
			resultData.optimization.solution[solIdx].variables.values.var = null;
			return true;
		}
		int iVars = 0;
		for(int i = 0; i < x.length; i++){
			if(x[i] != 0) iVars++;
		}
		resultData.optimization.solution[solIdx].variables.values.var = new VarValue[iVars];
		VarValue[] var = resultData.optimization.solution[solIdx].variables.values.var;
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
	}//setPrimalVariableValues
	
	/**
	 * Set the [i]th optimization solution's primal variable string values, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the primal variable string values. 
	 * @param x holds a dense string array of variable string values to set.
	 * 
	 * @return whether primal variable string values are set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setPrimalVariableStringValues(int solIdx, String[] x){
		if(x == null) return false;
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return false;
		if(x != null && x.length != iNumberOfVariables) return false;
		int nSols = this.getSolutionNumber();
		if(resultData.optimization == null) return false;
		if(nSols <= 0) return false;
		if(resultData.optimization == null) return false;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  nSols) return false;
		if(resultData.optimization.solution[solIdx] == null){
			resultData.optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(resultData.optimization.solution[solIdx].variables == null){
			resultData.optimization.solution[solIdx].variables = new VariableSolution();
		}
		if(resultData.optimization.solution[solIdx].variables.valuesString == null){
			resultData.optimization.solution[solIdx].variables.valuesString = new VariableStringValues();
		}
		resultData.optimization.solution[solIdx].variables.valuesString.var = new VarStringValue[iNumberOfVariables];
		VarStringValue[] var = resultData.optimization.solution[solIdx].variables.valuesString.var;
		for(int i = 0; i < iNumberOfVariables; i++) var[i] = new VarStringValue();
		for(int i = 0; i < iNumberOfVariables; i++){
			var[i].idx = i;
			var[i].value = x[i];
		}
		return true;
	}//setPrimalVariableStringValues

	/**
	 * Set the [i]th optimization solution's primal unbounded directions, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the primal unbounded directions. 
	 * @param directions holds a double dense array of primal unbounded directions to set; it could be null if all values are 0.
	 * 
	 * @return whether primal variable unbounded directions are set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setPrimalUnboundedDirections(int solIdx, double[] directions){
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return false;
		if(directions != null && directions.length != iNumberOfVariables) return false;
		int nSols = this.getSolutionNumber();
		if(resultData.optimization == null) return false;
		if(nSols <= 0) return false;
		if(resultData.optimization == null) return false;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  nSols) return false;
		if(resultData.optimization.solution[solIdx] == null){
			resultData.optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(resultData.optimization.solution[solIdx].variables == null){
			resultData.optimization.solution[solIdx].variables = new VariableSolution();
		}
		if(resultData.optimization.solution[solIdx].variables.primalUnboundedDirections == null){
			resultData.optimization.solution[solIdx].variables.primalUnboundedDirections = new PrimalVariableUnboundedDirections();
		}
		if(directions == null){
			resultData.optimization.solution[solIdx].variables.values.var = null;
			return true;
		}
		int iVars = 0;
		for(int i = 0; i < directions.length; i++){
			if(directions[i] != 0) iVars++;
		}
		resultData.optimization.solution[solIdx].variables.primalUnboundedDirections.var = new PrimalVarUnboundedDirection[iVars];
		PrimalVarUnboundedDirection[] var = resultData.optimization.solution[solIdx].variables.primalUnboundedDirections.var;
		for(int i = 0; i < iVars; i++) var[i] = new PrimalVarUnboundedDirection();
		int j = 0;
		for(int i = 0; i < directions.length; i++){
			if(directions[i] != 0){
				var[j].idx = i;
				var[j].value = directions[i];
				j++;
			}
		}
		return true;
	}//setPrimalUnboundedDirections
		
	/**
	 * Set the [i]th optimization solution's variable Irreducible Inconsistent System (IIS), where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the IIS. 
	 * @param variableIIS holds the variable Irreducible Inconsistent System in the VariableIrreducibleInconsistentSystem data structure
	 * 
	 * @return whether the variable IIS is set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.VariableIrreducibleInconsistentSystem
	 * @see #setSolutionNumber(int)
	 */
	public boolean setVariableIrreducibleInconsistentSystem(int solIdx, VariableIrreducibleInconsistentSystem variableIIS){
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return false;
		int nSols = this.getSolutionNumber();
		if(resultData.optimization == null) return false;
		if(nSols <= 0) return false;
		if(resultData.optimization == null) return false;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  nSols) return false;
		if(resultData.optimization.solution[solIdx] == null){
			resultData.optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(resultData.optimization.solution[solIdx].variables == null){
			resultData.optimization.solution[solIdx].variables = new VariableSolution();
		}
		resultData.optimization.solution[solIdx].variables.irreducibleInconsistentSystem = variableIIS;
		return true;		
	}//setVariableIrreducibleInconsistentSystem
	
	/**
	 * Set the [i]th optimization solution's reduced costs, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the reduced costs. 
	 * @param reducedCosts holds the reduced costs in the ReducedCosts data structure. 
	 * The data structure holds an array var[]; each var member holds 
	 * a variable idx, a reduced cost value on the lower bound (lbValue) and on the upper bound (ubValue). 
	 * 
	 * @return whether the reduced costs are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.ReducedCosts
	 * @see #setSolutionNumber(int)
	 */
	public boolean setReducedCosts(int solIdx, ReducedCosts reducedCosts){
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return false;
		int nSols = this.getSolutionNumber();
		if(resultData.optimization == null) return false;
		if(nSols <= 0) return false;
		if(resultData.optimization == null) return false;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  nSols) return false;
		if(resultData.optimization.solution[solIdx] == null){
			resultData.optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(resultData.optimization.solution[solIdx].variables == null){
			resultData.optimization.solution[solIdx].variables = new VariableSolution();
		}
		resultData.optimization.solution[solIdx].variables.reducedCosts = reducedCosts;
		return true;		
	}//setReducedCosts
	
	/**
	 * Set the [i]th optimization solution's variable slacks, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the variable slacks. 
	 * @param variableSlacks holds the variable slacks in the VariableSlacks data structure. 
	 * The data structure holds an array var[]; each var member holds 
	 * a variable idx, a slack value on the lower bound (lbValue) and on the upper bound (ubValue). 
	 * 
	 * @return whether the variable slacks are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.VariableSlacks
	 * @see #setSolutionNumber(int)
	 */
	public boolean setVariableSlacks(int solIdx, VariableSlacks variableSlacks){
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return false;
		int nSols = this.getSolutionNumber();
		if(resultData.optimization == null) return false;
		if(nSols <= 0) return false;
		if(resultData.optimization == null) return false;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  nSols) return false;
		if(resultData.optimization.solution[solIdx] == null){
			resultData.optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(resultData.optimization.solution[solIdx].variables == null){
			resultData.optimization.solution[solIdx].variables = new VariableSolution();
		}
		resultData.optimization.solution[solIdx].variables.slacks = variableSlacks;
		return true;		
	}//setVariableSlacks
	
	/**
	 * Set the [i]th optimization solution's variable allowable increases, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the variable allowable increases. 
	 * @param variableAllowableIncreases holds the variable allowable increases in the VariableAllowableIncreases data structure. 
	 * The data structure holds an array var[]; each var member holds 
	 * a variable idx, an allowable increase value on the lower bound (lbValue) and on the upper bound (ubValue). 
	 * 
	 * @return whether the variable allowable increases are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.VariableAllowableIncreases
	 * @see #setSolutionNumber(int)
	 */
	public boolean setVariableAllowableIncreases(int solIdx, VariableAllowableIncreases variableAllowableIncreases){
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return false;
		int nSols = this.getSolutionNumber();
		if(resultData.optimization == null) return false;
		if(nSols <= 0) return false;
		if(resultData.optimization == null) return false;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  nSols) return false;
		if(resultData.optimization.solution[solIdx] == null){
			resultData.optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(resultData.optimization.solution[solIdx].variables == null){
			resultData.optimization.solution[solIdx].variables = new VariableSolution();
		}
		resultData.optimization.solution[solIdx].variables.allowableIncreases = variableAllowableIncreases;
		return true;		
	}//setVariableAllowableIncreases
	
	/**
	 * Set the [i]th optimization solution's variable allowable decreases, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the variable allowable decreases. 
	 * @param variableAllowableDecreases holds the variable allowable decreases in the VariableAllowableDecreases data structure. 
	 * The data structure holds an array var[]; each var member holds 
	 * a variable idx, an allowable decrease value on the lower bound (lbValue) and on the upper bound (ubValue). 
	 * 
	 * @return whether the variable allowable decreases are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.VariableAllowableDecreases
	 * @see #setSolutionNumber(int)
	 */
	public boolean setVariableAllowableDecreases(int solIdx, VariableAllowableDecreases variableAllowableDecreases){
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return false;
		int nSols = this.getSolutionNumber();
		if(resultData.optimization == null) return false;
		if(nSols <= 0) return false;
		if(resultData.optimization == null) return false;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  nSols) return false;
		if(resultData.optimization.solution[solIdx] == null){
			resultData.optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(resultData.optimization.solution[solIdx].variables == null){
			resultData.optimization.solution[solIdx].variables = new VariableSolution();
		}
		resultData.optimization.solution[solIdx].variables.allowableDecreases = variableAllowableDecreases;
		return true;		
	}//setVariableAllowableDecreases
	
	
	/**
	 * Set the [i]th optimization solution's variable OVFunctions, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the variable OVFunctions. 
	 * @param variableOVFunctions holds the variable OVFunctions in the VariableOVFunctions data structure. 
	 * The data structure holds an array varBound[]; each varBound member corresponds to one OVFunction. 
	 * The varBound type can be eq, lb or ub and the varBound holds an idx for the index of the variable. 
	 * An OVFunction is a sequence (or array) of intervals, each interval contains a start value, an end value and a slope value. 
	 * 
	 * @return whether the variable OVFunctions are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.VariableOVFunctions
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OVFunction
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OVFunctionInterval
	 * @see #setSolutionNumber(int)
	 */
	public boolean setVariableOVFunctions(int solIdx, VariableOVFunctions variableOVFunctions){
		int iNumberOfVariables = this.getVariableNumber();
		if(iNumberOfVariables <= 0) return false;
		int nSols = this.getSolutionNumber();
		if(resultData.optimization == null) return false;
		if(nSols <= 0) return false;
		if(resultData.optimization == null) return false;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  nSols) return false;
		if(resultData.optimization.solution[solIdx] == null){
			resultData.optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(resultData.optimization.solution[solIdx].variables == null){
			resultData.optimization.solution[solIdx].variables = new VariableSolution();
		}
		resultData.optimization.solution[solIdx].variables.ovFunctions = variableOVFunctions;
		return true;		
	}//setVariableOVFunctions
		
	/**
	 * Set the [i]th optimization solution's other (non-standard/solver specific)variable-related results, 
	 * where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param otherVariableResults holds an array of other variable results in OtherVariableResult[] array data structure, null if none. 
	 * Each other variable result contains the name (required), an optional description (string) and an optional
	 * value (string). Each other variable result can also optionally contain an array OtherVarResult for each variable. 
	 * The OtherVarResult contains a variable idx (required), an optional string value, an optional string value on the lower bound (lbValue) 
	 * and an optional string value on the upper bound (ubValue).   
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
		if(resultData.optimization == null) return false;
		if(nSols <= 0) return false;
		if(resultData.optimization == null) return false;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  nSols) return false;
		if(resultData.optimization.solution[solIdx] == null){
			resultData.optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(resultData.optimization.solution[solIdx].variables == null){
			resultData.optimization.solution[solIdx].variables = new VariableSolution();
		}
		resultData.optimization.solution[solIdx].variables.other = otherVariableResults;
		return true;		
	}//setOtherVariableResults
	
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
	public boolean setObjectiveValues(int solIdx, double[] objectiveValues){
		int iNumberOfObjectives = this.getObjectiveNumber();
		if(iNumberOfObjectives < 0) return false;
		if(iNumberOfObjectives == 0) return true;
		if(objectiveValues == null) return false;
		if(objectiveValues.length != iNumberOfObjectives) return false;
		int nSols = this.getSolutionNumber();
		if(resultData.optimization == null) return false;
		if(nSols <= 0) return false;
		if(resultData.optimization == null) return false;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  nSols) return false;
		if(resultData.optimization.solution[solIdx] == null){
			resultData.optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(resultData.optimization.solution[solIdx].objectives == null){
			resultData.optimization.solution[solIdx].objectives = new ObjectiveSolution();
		}
		if(resultData.optimization.solution[solIdx].objectives.values == null){
			resultData.optimization.solution[solIdx].objectives.values = new ObjectiveValues();
		}
		int iObjs = 0;
		for(int i = 0; i < objectiveValues.length; i++){
			if(!Double.isNaN(objectiveValues[i])) iObjs++;
		}
		resultData.optimization.solution[solIdx].objectives.values.obj = new ObjValue[iObjs];
		ObjValue[] obj = resultData.optimization.solution[solIdx].objectives.values.obj;
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
	}//setObjectiveValues

	/**
	 * Set the [i]th optimization solution's objective OVFunctions, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the objective OVFunctions. 
	 * @param objectiveOVFunctions holds the objective OVFunctions in the ObjectiveOVFunctions data structure. 
	 * The data structure holds an array varCoef[]; each varCoef member corresponds to one OVFunction (for each of the objective's variable coefficients). 
	 * The varCoef holds an idx for the index of the variable. 
	 * An OVFunction is a sequence (or array) of intervals, each interval contains a start value, an end value and a slope value. 
	 * 
	 * @return whether the objective OVFunctions are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.ObjectiveOVFunctions
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OVFunction
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OVFunctionInterval
	 * @see #setSolutionNumber(int)
	 */
	public boolean setObjectiveOVFunctions(int solIdx, ObjectiveOVFunctions objectiveOVFunctions){
		int iNumberOfObjectives = this.getObjectiveNumber();
		if(iNumberOfObjectives <= 0) return false;
		int nSols = this.getSolutionNumber();
		if(resultData.optimization == null) return false;
		if(nSols <= 0) return false;
		if(resultData.optimization == null) return false;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  nSols) return false;
		if(resultData.optimization.solution[solIdx] == null){
			resultData.optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(resultData.optimization.solution[solIdx].objectives == null){
			resultData.optimization.solution[solIdx].objectives = new ObjectiveSolution();
		}
		resultData.optimization.solution[solIdx].objectives.ovFunctions = objectiveOVFunctions;
		return true;		
	}//setObjectiveOVFunctions
	
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
		if(resultData.optimization == null) return false;
		if(nSols <= 0) return false;
		if(resultData.optimization == null) return false;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  nSols) return false;
		if(resultData.optimization.solution[solIdx] == null){
			resultData.optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(resultData.optimization.solution[solIdx].objectives == null){
			resultData.optimization.solution[solIdx].objectives = new ObjectiveSolution();
		}
		resultData.optimization.solution[solIdx].objectives.other = otherObjectiveResults;
		return true;		
	}//setOtherObjectiveResults
	
	/**
	 * Set the [i]th optimization solution's constraint values, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the constraint values. 
	 * @param constraintValues holds a double dense array of constraint values to set; it could be null if all constraint values are 0.
	 * 
	 * @return whether constraint values are set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setConstraintValues(int solIdx, double[] constraintValues){
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return false;
		if(constraintValues != null && constraintValues.length != iNumberOfConstraints) return false;
		int nSols = this.getSolutionNumber();
		if(resultData.optimization == null) return false;
		if(nSols <= 0) return false;
		if(resultData.optimization == null) return false;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  nSols) return false;
		if(resultData.optimization.solution[solIdx] == null){
			resultData.optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(resultData.optimization.solution[solIdx].constraints == null){
			resultData.optimization.solution[solIdx].constraints = new ConstraintSolution();
		}
		if(resultData.optimization.solution[solIdx].constraints.values == null){
			resultData.optimization.solution[solIdx].constraints.values = new ConstraintValues();
		}
		if(constraintValues == null){
			resultData.optimization.solution[solIdx].constraints.values.con = null;
			return true;
		}
		int iCons = 0;
		for(int i = 0; i < constraintValues.length; i++){
			if(constraintValues[i] != 0) iCons++;
		}
		resultData.optimization.solution[solIdx].constraints.values.con = new ConValue[iCons];
		ConValue[] con = resultData.optimization.solution[solIdx].constraints.values.con;
		for(int i = 0; i < iCons; i++) con[i] = new ConValue();
		int j = 0;
		for(int i = 0; i < constraintValues.length; i++){
			if(constraintValues[i] != 0){
				con[j].idx = i;
				con[j].value = constraintValues[i];
				j++;
			}
		}
		return true;
	}//setConstraintValues

	/**
	 * Set the [i]th optimization solution's dual variable unbounded directions, where i equals the given solution index. 
	 * The method allows setting dual unbounded directions at both the constraints' lower and upper bounds.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the dual variable unbounded directions. 
	 * @param lbValues holds a double dense array of variable dual unbounded directions to set at the lower bounds; it could be null if all unbounded directions are 0.
	 * @param ubValues holds a double dense array of variable dual unbounded directions to set at the upper bounds; it could be null if all unbounded directions are 0.
	 * 
	 * @return whether dual variable unbounded directions are set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setDualUnboundedDirections(int solIdx, double[] lbValues, double[] ubValues){
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints < 0) return false;
		if(iNumberOfConstraints == 0) return true;
		if(lbValues != null && lbValues.length != iNumberOfConstraints) return false;
		if(ubValues != null && ubValues.length != iNumberOfConstraints) return false;
		int nSols = this.getSolutionNumber();
		if(resultData.optimization == null) return false;
		if(nSols <= 0) return false;
		if(resultData.optimization == null) return false;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  nSols) return false;
		if(resultData.optimization.solution[solIdx] == null){
			resultData.optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(resultData.optimization.solution[solIdx].constraints == null){
			resultData.optimization.solution[solIdx].constraints = new ConstraintSolution();
		}
		if(resultData.optimization.solution[solIdx].constraints.dualUnboundedDirections == null){
			resultData.optimization.solution[solIdx].constraints.dualUnboundedDirections = new DualVariableUnboundedDirections();
		}
		if(lbValues == null && ubValues == null){
			resultData.optimization.solution[solIdx].constraints.dualUnboundedDirections.con = null;
			return true;
		}
		int iCons = 0;
		if(lbValues == null){
			for(int i = 0; i < iNumberOfConstraints; i++){
				if(ubValues[i] != 0) iCons++;
			}
		}
		else if(ubValues == null){
			for(int i = 0; i < iNumberOfConstraints; i++){
				if(lbValues[i] != 0) iCons++;
			}
		}
		else{
			for(int i = 0; i < iNumberOfConstraints; i++){
				if(lbValues[i] != 0 || ubValues[i] != 0) iCons++;
			}
		}
		
		resultData.optimization.solution[solIdx].constraints.dualUnboundedDirections.con = new DualVarUnboundedDirection[iCons];
		DualVarUnboundedDirection[] con = resultData.optimization.solution[solIdx].constraints.dualUnboundedDirections.con;
		for(int i = 0; i < iCons; i++) con[i] = new DualVarUnboundedDirection();
		int j = 0;
		if(lbValues == null){
			for(int i = 0; i < iNumberOfConstraints; i++){
				if(ubValues[i] != 0){
					con[j].idx = i;
					con[j].ubValue = 0;
					con[j].ubValue = ubValues[i];
					j++;
				}
			}			
		}
		else if(ubValues == null){
			for(int i = 0; i < iNumberOfConstraints; i++){
				if(lbValues[i] != 0){
					con[j].idx = i;
					con[j].lbValue = lbValues[i];
					con[j].ubValue = 0;
					j++;
				}
			}
		}
		else{
			for(int i = 0; i < iNumberOfConstraints; i++){
				if(lbValues[i] != 0 || ubValues[i] != 0){
					con[j].idx = i;
					con[j].lbValue = lbValues[i];
					con[j].ubValue = ubValues[i];
					j++;
				}
			}
		}
		return true;
	}//setDualUnboundedDirections

		
	/**
	 * Set the [i]th optimization solution's constraint Irreducible Inconsistent System (IIS), where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the IIS. 
	 * @param constraintIIS holds the constraint Irreducible Inconsistent System in the ConstraintIrreducibleInconsistentSystem data structure
	 * 
	 * @return whether the constraint IIS is set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.ConstraintIrreducibleInconsistentSystem
	 * @see #setSolutionNumber(int)
	 */
	public boolean setConstraintIrreducibleInconsistentSystem(int solIdx, ConstraintIrreducibleInconsistentSystem constraintIIS){
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return false;
		int nSols = this.getSolutionNumber();
		if(resultData.optimization == null) return false;
		if(nSols <= 0) return false;
		if(resultData.optimization == null) return false;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  nSols) return false;
		if(resultData.optimization.solution[solIdx] == null){
			resultData.optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(resultData.optimization.solution[solIdx].constraints == null){
			resultData.optimization.solution[solIdx].constraints = new ConstraintSolution();
		}
		resultData.optimization.solution[solIdx].constraints.irreducibleInconsistentSystem = constraintIIS;
		return true;		
	}//setConstraintIrreducibleInconsistentSystem

	/**
	 * Set the [i]th optimization solution's dual variable values, where i equals the given solution index. 
	 * The method allows setting dual values at both the constraints' lower and upper bounds.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the dual variable values. 
	 * @param lbValues holds a double dense array of variable dual values to set at the lower bounds; it could be null if all values are 0.
	 * @param ubValues holds a double dense array of variable dual values to set at the upper bounds; it could be null if all values are 0.
	 * 
	 * @return whether dual variable values are set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setDualVariableValues(int solIdx, double[] lbValues, double[] ubValues){
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints < 0) return false;
		if(iNumberOfConstraints == 0) return true;
		if(lbValues != null && lbValues.length != iNumberOfConstraints) return false;
		if(ubValues != null && ubValues.length != iNumberOfConstraints) return false;
		int nSols = this.getSolutionNumber();
		if(resultData.optimization == null) return false;
		if(nSols <= 0) return false;
		if(resultData.optimization == null) return false;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  nSols) return false;
		if(resultData.optimization.solution[solIdx] == null){
			resultData.optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(resultData.optimization.solution[solIdx].constraints == null){
			resultData.optimization.solution[solIdx].constraints = new ConstraintSolution();
		}
		if(resultData.optimization.solution[solIdx].constraints.dualValues == null){
			resultData.optimization.solution[solIdx].constraints.dualValues = new DualVariableValues();
		}
		if(lbValues == null && ubValues == null){
			resultData.optimization.solution[solIdx].constraints.dualValues.con = null;
			return true;
		}
		int iCons = 0;
		if(lbValues == null){
			for(int i = 0; i < iNumberOfConstraints; i++){
				if(ubValues[i] != 0) iCons++;
			}
		}
		else if(ubValues == null){
			for(int i = 0; i < iNumberOfConstraints; i++){
				if(lbValues[i] != 0) iCons++;
			}
		}
		else{
			for(int i = 0; i < iNumberOfConstraints; i++){
				if(lbValues[i] != 0 || ubValues[i] != 0) iCons++;
			}
		}
		
		resultData.optimization.solution[solIdx].constraints.dualValues.con = new DualVarValue[iCons];
		DualVarValue[] con = resultData.optimization.solution[solIdx].constraints.dualValues.con;
		for(int i = 0; i < iCons; i++) con[i] = new DualVarValue();
		int j = 0;
		if(lbValues == null){
			for(int i = 0; i < iNumberOfConstraints; i++){
				if(ubValues[i] != 0){
					con[j].idx = i;
					con[j].ubValue = 0;
					con[j].ubValue = ubValues[i];
					j++;
				}
			}			
		}
		else if(ubValues == null){
			for(int i = 0; i < iNumberOfConstraints; i++){
				if(lbValues[i] != 0){
					con[j].idx = i;
					con[j].lbValue = lbValues[i];
					con[j].ubValue = 0;
					j++;
				}
			}
		}
		else{
			for(int i = 0; i < iNumberOfConstraints; i++){
				if(lbValues[i] != 0 || ubValues[i] != 0){
					con[j].idx = i;
					con[j].lbValue = lbValues[i];
					con[j].ubValue = ubValues[i];
					j++;
				}
			}
		}
		return true;
	}//setDualVariableValues
	
	/**
	 * Set the [i]th optimization solution's constraint slacks, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the constraint slacks. 
	 * @param constraintSlacks holds the constraint slacks in the ConstraintSlacks data structure. 
	 * The data structure holds an array con[]; each con member holds 
	 * a constraint idx, a slack value on the lower bound (lbValue) and on the upper bound (ubValue). 
	 * 
	 * @return whether the constraint slacks are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.ConstraintSlacks
	 * @see #setSolutionNumber(int)
	 */
	public boolean setConstraintSlacks(int solIdx, ConstraintSlacks constraintSlacks){
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return false;
		int nSols = this.getSolutionNumber();
		if(resultData.optimization == null) return false;
		if(nSols <= 0) return false;
		if(resultData.optimization == null) return false;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  nSols) return false;
		if(resultData.optimization.solution[solIdx] == null){
			resultData.optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(resultData.optimization.solution[solIdx].constraints == null){
			resultData.optimization.solution[solIdx].constraints = new ConstraintSolution();
		}
		resultData.optimization.solution[solIdx].constraints.slacks = constraintSlacks;
		return true;		
	}//setConstraintSlacks
	
	/**
	 * Set the [i]th optimization solution's constraint allowable increases, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the constraint allowable increases. 
	 * @param constraintAllowableIncreases holds the constraint allowable increases in the ConstraintAllowableIncreases data structure. 
	 * The data structure holds an array con[]; each con member holds 
	 * a constraint idx, an allowable increase value on the lower bound (lbValue) and on the upper bound (ubValue). 
	 * 
	 * @return whether the constraint allowable increases are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.ConstraintAllowableIncreases
	 * @see #setSolutionNumber(int)
	 */
	public boolean setConstraintAllowableIncreases(int solIdx, ConstraintAllowableIncreases constraintAllowableIncreases){
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return false;
		int nSols = this.getSolutionNumber();
		if(resultData.optimization == null) return false;
		if(nSols <= 0) return false;
		if(resultData.optimization == null) return false;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  nSols) return false;
		if(resultData.optimization.solution[solIdx] == null){
			resultData.optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(resultData.optimization.solution[solIdx].constraints == null){
			resultData.optimization.solution[solIdx].constraints = new ConstraintSolution();
		}
		resultData.optimization.solution[solIdx].constraints.allowableIncreases = constraintAllowableIncreases;
		return true;		
	}//setConstraintAllowableIncreases
	
	/**
	 * Set the [i]th optimization solution's constraint allowable decreases, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the constraint allowable decreases. 
	 * @param constraintAllowableDecreases holds the constraint allowable decreases in the ConstraintAllowableDecreases data structure. 
	 * The data structure holds an array con[]; each con member holds 
	 * a constraint idx, an allowable decrease value on the lower bound (lbValue) and on the upper bound (ubValue). 
	 * 
	 * @return whether the constraint allowable decreases are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.ConstraintAllowableDecreases
	 * @see #setSolutionNumber(int)
	 */
	public boolean setConstraintAllowableDecreases(int solIdx, ConstraintAllowableDecreases constraintAllowableDecreases){
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return false;
		int nSols = this.getSolutionNumber();
		if(resultData.optimization == null) return false;
		if(nSols <= 0) return false;
		if(resultData.optimization == null) return false;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  nSols) return false;
		if(resultData.optimization.solution[solIdx] == null){
			resultData.optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(resultData.optimization.solution[solIdx].constraints == null){
			resultData.optimization.solution[solIdx].constraints = new ConstraintSolution();
		}
		resultData.optimization.solution[solIdx].constraints.allowableDecreases = constraintAllowableDecreases;
		return true;		
	}//setConstraintAllowableDecreases
	
	
	/**
	 * Set the [i]th optimization solution's constraint OVFunctions, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the constraint OVFunctions. 
	 * @param constraintOVFunctions holds the constraint OVFunctions in the ConstraintOVFunctions data structure. 
	 * The data structure holds an array conBound[]; each conBound member corresponds to one OVFunction. 
	 * The conBound type can be eq, lb or ub and the conBound holds an idx for the index of the constraint. 
	 * An OVFunction is a sequence (or array) of intervals, each interval contains a start value, an end value and a slope value. 
	 * 
	 * @return whether the constraint OVFunctions are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.ConstraintOVFunctions
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OVFunction
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OVFunctionInterval
	 * @see #setSolutionNumber(int)
	 */
	public boolean setConstraintOVFunctions(int solIdx, ConstraintOVFunctions constraintOVFunctions){
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints <= 0) return false;
		int nSols = this.getSolutionNumber();
		if(resultData.optimization == null) return false;
		if(nSols <= 0) return false;
		if(resultData.optimization == null) return false;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  nSols) return false;
		if(resultData.optimization.solution[solIdx] == null){
			resultData.optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(resultData.optimization.solution[solIdx].constraints == null){
			resultData.optimization.solution[solIdx].constraints = new ConstraintSolution();
		}
		resultData.optimization.solution[solIdx].constraints.ovFunctions = constraintOVFunctions;
		return true;		
	}//setConstraintOVFunctions
		
	/**
	 * Set the [i]th optimization solution's other (non-standard/solver specific)constraint-related results, 
	 * where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param otherConstraintResults holds an array of other constraint results in OtherConstraintResult[] array data structure, null if none. 
	 * Each other constraint result contains the name (required), an optional description (string) and an optional
	 * value (string). Each other constraint result can also optionally contain an array OtherConstraint for each constraint. 
	 * The OtherConResult contains a constraint idx (required), an optional string value, an optional string value on the lower bound (lbValue) 
	 * and an optional string value on the upper bound (ubValue).   
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
		if(resultData.optimization == null) return false;
		if(nSols <= 0) return false;
		if(resultData.optimization == null) return false;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  nSols) return false;
		if(resultData.optimization.solution[solIdx] == null){
			resultData.optimization.solution[solIdx] = new OptimizationSolution();
		}
		if(resultData.optimization.solution[solIdx].constraints == null){
			resultData.optimization.solution[solIdx].constraints = new ConstraintSolution();
		}
		resultData.optimization.solution[solIdx].constraints.other = otherConstraintResults;
		return true;		
	}//setOtherConstraintResults

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
	public boolean setOtherOptimizationResults(int solIdx, OtherOptimizationResult[] otherOptimizationResults){
		int nSols = this.getSolutionNumber();
		if(resultData.optimization == null) return false;
		if(nSols <= 0) return false;
		if(resultData.optimization == null) return false;
		if(resultData.optimization.solution == null || 
		   resultData.optimization.solution.length <= 0 || 
		   solIdx < 0 || solIdx >=  nSols) return false;
		if(resultData.optimization.solution[solIdx] == null){
			resultData.optimization.solution[solIdx] = new OptimizationSolution();
		}
		resultData.optimization.solution[solIdx].other = otherOptimizationResults;
		return true;		
	}//setOtherOptimizationResults

	/**
	 * Set the optimization analysis. 
	 * 
	 * @param osAnalysis holds the optimization analysis in the standard OSAnalysis data structure. 
	 * @return the optimization analysis in the standard OSAnalysis data structure, null if none.
	 * @see org.optimizationservices.oscommon.localinterface.OSAnalysis
	 */	
	public boolean setOSAnalysis(OSAnalysis osAnalysis){
		if(resultData.optimization == null) resultData.optimization = new OptimizationResult();
		resultData.optimization.osal = osAnalysis;
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
