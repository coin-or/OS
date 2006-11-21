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
import org.optimizationservices.oscommon.datastructure.osresult.ConstraintSolution;
import org.optimizationservices.oscommon.datastructure.osresult.DualVarValue;
import org.optimizationservices.oscommon.datastructure.osresult.DualVariableValues;
import org.optimizationservices.oscommon.datastructure.osresult.GeneralStatus;
import org.optimizationservices.oscommon.datastructure.osresult.ObjValue;
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
import org.optimizationservices.oscommon.datastructure.osresult.ResultData;
import org.optimizationservices.oscommon.datastructure.osresult.ResultHeader;
import org.optimizationservices.oscommon.datastructure.osresult.VarStringValue;
import org.optimizationservices.oscommon.datastructure.osresult.VarValue;
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
		if(resultData.optimization == null){
			m_iVariableNumber = -1;
			return -1;
		}
		m_iVariableNumber = resultData.optimization.numberOfVariables;
		return m_iVariableNumber;
	}//getVariableNumber

	/**
	 * Get objective number. 
	 * 
	 * @return objective number, -1 if no information. 
	 */
	public int getObjectiveNumber(){
			if(resultData.optimization == null){
				m_iObjectiveNumber = -1;
				return -1;
			}
			m_iObjectiveNumber = resultData.optimization.numberOfObjectives;
			return m_iObjectiveNumber;
	}//getObjectiveNumber
	
	/**
	 * Get constraint number. 
	 * 
	 * @return constraint number, -1 if no information. 
	 */
	public int getConstraintNumber(){
			if(resultData.optimization == null){
				m_iConstraintNumber = -1;
				return -1;
			}
			m_iConstraintNumber = resultData.optimization.numberOfConstraints;
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
					mdValues[con[j].idx] = con[j].value;
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
	 * Get the [i]th optimization solution's dual variable values, where i equals the given solution index. 
	 * 
	 * @param solIdx holds the solution index to get the dual variable values. 
	 * @return a double dense array of the dual variable values, null if none. 
	 */
	public double[] getDualVariableValues(int solIdx){
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
			if(!Double.isNaN(con[j].value)){
				mdValues[con[j].idx] = con[j].value;
			}
		}
		return mdValues;				
	}//getDualVariableValues
		
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
			m_iVariableNumber = -1;
			return true;
		}
		if(resultData.optimization == null) resultData.optimization = new OptimizationResult();
		resultData.optimization.numberOfVariables = variableNumber;
		m_iVariableNumber = variableNumber;
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
			m_iObjectiveNumber = -1;
			return true;
		}
		if(resultData.optimization == null) resultData.optimization = new OptimizationResult();
		resultData.optimization.numberOfObjectives = objectiveNumber;
		m_iObjectiveNumber = objectiveNumber;
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
			m_iConstraintNumber = -1;
			return true;
		}
		if(resultData.optimization == null) resultData.optimization = new OptimizationResult();
		resultData.optimization.numberOfConstraints = constraintNumber;
		m_iConstraintNumber = constraintNumber;
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
		if(getVariableNumber() <= 0) return true;
		if(getObjectiveNumber() < 0) return true;
		if(getConstraintNumber() < 0) return true;
		if(solutionNumber < 0) return true; 
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
	 * Set the [i]th optimization solution's dual variable values, where i equals the given solution index. 
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the dual variable values. 
	 * @param values holds a double dense array of variable dual values to set; it could be null if all values are 0.
	 * 
	 * @return whether dual variable values are set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	public boolean setDualVariableValues(int solIdx, double[] values){
		int iNumberOfConstraints = this.getConstraintNumber();
		if(iNumberOfConstraints < 0) return false;
		if(iNumberOfConstraints == 0) return true;
		if(values != null && values.length != iNumberOfConstraints) return false;
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
		if(values == null){
			resultData.optimization.solution[solIdx].constraints.dualValues.con = null;
			return true;
		}
		int iCons = 0;
		for(int i = 0; i < values.length; i++){
			if(values[i] != 0) iCons++;
		}
		resultData.optimization.solution[solIdx].constraints.dualValues.con = new DualVarValue[iCons];
		DualVarValue[] con = resultData.optimization.solution[solIdx].constraints.dualValues.con;
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
	}//setDualVariableValues
			
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
