using System;
using System.Collections;

using org.optimizationservices.oscommon.datastructure.osresult;
using org.optimizationservices.oscommon.datastructure.osprocess;
using org.optimizationservices.oscommon.representationparser;

namespace org.optimizationservices.oscommon.localinterface{
	/// <summary>
	/// The <c>OSResult</c> class is a local interface for storing OS 
	/// problem result. Its design follows the OSrL. Naming, structuring and layering 
	/// all are exactly the same as those in the OSrL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// <see cref="org.optimizationservices.oscommon.localinterface.OSInstance"/>
	/// <see cref="org.optimizationservices.oscommon.localinterface.OSAnalysis"/>
	/// <see cref="org.optimizationservices.oscommon.localinterface.OSOption"/>
	/// </summary>
	public class OSResult{

		/// <summary>
		/// resultHeader holds the first child of the OSResult specified by the OSiL Schema.  
		/// </summary>
		public ResultHeader resultHeader = new ResultHeader();

		/// <summary>
		/// resultData holds the second child of the OSResult specified by the OSiL Schema.  
		/// </summary>
		public ResultData resultData = new ResultData();	

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
		/// m_iSolutionNumber holds the solution number. 
		/// </summary>
		private int m_iSolutionNumber = -1;

		/// <summary>
		/// Default constructor. 
		/// </summary>
		public OSResult(){
		}//constructor

		/// <summary>
		/// read an OSrL instance and return and OSResult object.  
		/// @throws Exception if there are errors in reading the string or setting the OSResult. 
		/// </summary>
		/// <param name="osrl">holds the optimization result in a string which format follows the
		/// Optimization Services result Language (OSrL) schema</param>
		/// <param name="isFile">isFile holds whether the osrl string is a file name or a string that literally holds the osrl contents.  </param>
		/// <param name="validate">holds whether the reader should be validating against the schema or not.</param>
		/// <returns>the OSResult object constructed from the OSrL String.  </returns>
		public OSResult readOSrL(string osrl, bool isFile, bool validate){
			OSrLReader osrlReader = new OSrLReader(validate);
			bool bRead = false;
			if(isFile){
				bRead = osrlReader.readFile(osrl);
			}
			else{
				bRead = osrlReader.readString(osrl);			
			}
			if(!bRead) throw new Exception("OSrL string not valid");
			return osrlReader.getOSResult();
		}//readOSrL
	   
		/// <summary>
		/// write the OSResult to an osrl xml string. 
		/// @throws Exception if there are errors in writing the osrl string. 
		/// </summary>
		/// <returns>the osrl xml string. </returns>
		public string writeOSrL(){
			OSrLWriter osrlWriter = new OSrLWriter();
			osrlWriter.setOSResult(this);
			return osrlWriter.writeToString();
		}//writeOSrL

		/// <summary>
		/// Get the general status.
		/// </summary>
		/// <returns> the general status. </returns>
		public GeneralStatus getGeneralStatus(){
			return resultHeader.generalStatus;
		}//getGeneralStatus
	
		/// <summary>
		/// Get the general status type, which can be: 
		/// success, error, warning. 
		/// </summary>
		/// <returns> the general status type, null if none. </returns>
		public string getGeneralStatusType(){
			if(resultHeader.generalStatus == null) return null;
			return resultHeader.generalStatus.type;
		}//getGeneralStatusType

		/// <summary>
		/// Get the general status description. 
		/// </summary>
		/// <returns> the general status description, null or empty string if none.</returns> 
		public string getGeneralStatusDescription(){
			if(resultHeader.generalStatus == null) return null;
			return resultHeader.generalStatus.description;
		}//getGeneralStatusDescription

		/// <summary>
		/// Get service name.
		/// </summary>
		/// <returns> the service name.</returns>
		public string getServiceName(){
			return resultHeader.serviceName;
		}//getServiceName
	
		/// <summary>
		/// Get service uri.
		/// </summary>
		/// <returns> the service uri. </returns>
		public string getServiceURI(){
			return resultHeader.serviceURI;
		}//getServiceURI
	
		/// <summary>
		/// Get instance name.
		/// </summary>
		/// <returns> the instance name. </returns>
		public string getInstanceName(){
			return resultHeader.instanceName;
		}//getInstanceName
	
		/// <summary>
		/// Get the job id.
		/// </summary>
		/// <returns> the job id.</returns>
		public string getJobID(){
			return resultHeader.jobID;
		}//getJobID
	
		/// <summary>
		/// Get time of the result.
		/// </summary>
		/// <returns> the time of the result.</returns>
		public DateTime getResultTime(){
			return resultHeader.time;
		}//getResultTime
	
		/// <summary>
		/// Get the general message. 
		/// </summary>
		/// <returns> the general message. </returns>
		public string getGeneralMessage(){
			return resultHeader.message;
		}//getGeneralMessage
	
		/// <summary>
		/// Get the process statistics. 
		/// </summary>
		/// <returns> the process statistics. </returns>
		public ProcessStatistics getProcessStatistics(){
			return resultData.statistics;
		}//getProcessStatistics
	
		/// <summary>
		/// Get the statistics of all the jobs. 
		/// </summary>
		/// <returns> the statistics of all the jobs, which is an array of jobStatistics with 
		/// each member corresponding to one job; null if none. 
		/// </returns>
		public JobStatistics[] getJobStatistics(){
			if(resultData.statistics == null) return null;
			if(resultData.statistics.jobs == null) return null;
			return resultData.statistics.jobs.job;
		}//getJobStatistics
	
		/// <summary>
		/// Get the current state, , which can be:
		/// "busy", "busyButAccepting", "idle", "idleButNotAccepting" and "noResponse".
		/// </summary>
		/// <returns>the current status, "noResponse" if none.</returns>
		public String getCurrentState(){
			if(resultData.statistics == null) return "noResponse";
			return resultData.statistics.currentState;
		}//getCurrentState

		/// <summary>
		/// Get the available disk space (in bytes). 
		/// </summary>
		/// <returns>the available disk space, Double.NaN if none. </returns>
		public double getAvailableDiskSpace(){
			if(resultData.statistics == null) return Double.NaN;
			return resultData.statistics.availableDiskSpace;
		}//getAvailableDiskSpace

		/// <summary>
		/// Get the available memory (in bytes). 
		/// </summary>
		/// <returns>the available memory, Double.NaN if none. </returns>
		public double getAvailableMemory(){
			if(resultData.statistics == null) return Double.NaN;
			return resultData.statistics.availableMemory;
		}//getAvailableMemory

		/// <summary>
		/// Get the current job count. 
		/// </summary>
		/// <returns>the current job count, -1 if none. </returns>
		public int getCurrentJobCount(){
			if(resultData.statistics == null) return -1;
			return resultData.statistics.currentJobCount;
		}//getCurrentJobCount


		/// <summary>
		/// Get the total jobs received so far. 
		/// </summary>
		/// <returns>the total jobs received so far, -1 if none. </returns>
		public int getTotalJobsSoFar(){
			if(resultData.statistics == null) return -1;
			return resultData.statistics.totalJobsSoFar;
		}//getTotalJobsSoFar

		/// <summary>
		/// Get the time last job ended. 
		/// </summary>
		/// <returns>the time last job ended. If none, it returns unix creation time: DateTime(1970, 1, 1, 0, 0, 0). </returns>
		public DateTime getTimeLastJobEnded(){
			if(resultData.statistics == null) return new DateTime(1970, 1, 1, 0, 0, 0);
			return resultData.statistics.timeLastJobEnded;
		}//getTimeLastJobEnded

		/// <summary>
		/// Get the time last job took (in seconds). 
		/// </summary>
		/// <returns>the the time last job took, Double.NaN if none. </returns>
		public double getTimeLastJobTook(){
			if(resultData.statistics == null) return Double.NaN;
			return resultData.statistics.timeLastJobTook;
		}//getTimeLastJobTook

		/// <summary>
		/// Get the time the service started. 
		/// </summary>
		/// <returns>the time last job ended. If none, it returns unix creation time: DateTime(1970, 1, 1, 0, 0, 0). </returns>
		public DateTime getTimeServiceStarted(){
			if(resultData.statistics == null) return new DateTime(1970, 1, 1, 0, 0, 0);
			return resultData.statistics.timeServiceStarted;
		}//getTimeServiceStarted

		/// <summary>
		/// Get the service utilization ([0, 1]). 
		/// </summary>
		/// <returns>the the time last job took, Double.NaN if none. </returns>
		public double getServiceUtilization(){
			if(resultData.statistics == null) return Double.NaN;
			return resultData.statistics.serviceUtilization;
		}//getServiceUtilization

		/// <summary>
		/// get a string array of names of other results. 
		/// </summary>
		/// <returns> a string array of names of other results, null if no other results.</returns>
		public string[] getOtherResultNames(){
			if(resultData.other == null) return null;
			int n = resultData.other.Length;
			if(n <= 0) return null;
			string[] otherResultNames = new string[n];
			for(int i = 0; i < n; i++){
				otherResultNames[i] = resultData.other[i].name;
			}
			return otherResultNames;
		}//getOtherResultNames
	
		/// <summary>
		/// get a hashmap of other result descriptions. 
		/// The keys of the hashmap are the result names, and 
		/// the values of the hashmap are the result descriptions.  
		/// </summary>
		/// <returns> a hashmap of other result descriptions, null if no other results. </returns>
		public Hashtable getOtherResultDescriptions(){
			if(resultData.other == null) return null;
			int n = resultData.other.Length;
			if(n <= 0) return null;
			Hashtable otherResultDescriptions = new Hashtable();
			for(int i = 0; i < n; i++){
				otherResultDescriptions.Add(resultData.other[i].name, resultData.other[i].description);
			}
			return otherResultDescriptions;
		}//getOtherResultDescriptions

		/// <summary>
		/// get a hashmap of other result values. 
		/// The keys of the hashmap are the result names, and 
		/// the values of the hashmap are the result values.  
		/// </summary>
		/// <returns> a hashmap of other result values, null if no other results. </returns>
		public Hashtable getOtherResultValues(){
			if(resultData.other == null) return null;
			int n = resultData.other.Length;
			if(n <= 0) return null;
			Hashtable otherResultValues = new Hashtable();
			for(int i = 0; i < n; i++){
				otherResultValues.Add(resultData.other[i].name, resultData.other[i].value);
			}
			return otherResultValues;
		}//getOtherResultValues

		/// <summary>
		/// Get variable number. 
		/// </summary>
		/// <returns> variable number, -1 if no information. </returns>
		public int getVariableNumber(){
			if(m_iVariableNumber == -1){
				if(resultData.optimization == null) return -1;
				m_iVariableNumber = resultData.optimization.numberOfVariables;
			}
			return m_iVariableNumber;
		}//getVariableNumber

		/// <summary>
		/// Get objective number. 
		/// </summary>
		/// <returns> objective number, -1 if no information. </returns>
		public int getObjectiveNumber(){
			if(m_iObjectiveNumber == -1){
				if(resultData.optimization == null) return -1;
				m_iObjectiveNumber = resultData.optimization.numberOfObjectives;
			}
			return m_iObjectiveNumber;
		}//getObjectiveNumber
	
		/// <summary>
		/// Get constraint number. 
		/// </summary>
		/// <returns> constraint number, -1 if no information. </returns>
		public int getConstraintNumber(){
			if(m_iConstraintNumber == -1){
				if(resultData.optimization == null) return -1;
				m_iConstraintNumber = resultData.optimization.numberOfConstraints;
			}
			return m_iConstraintNumber;
		}//getConstraintNumber


		/// <summary>
		/// Get one solution of optimal primal variable values. 
		/// </summary>
		/// <param name="objIdx"> holds the objective index the optimal value corresponds to. </param>
		/// <returns> a double dense array of the optimal values, null if no optimal value. </returns>
		public double[] getOptimalPrimalVariableValues(int objIdx){
			if(resultData.optimization == null) return null;
			if(resultData.optimization.solution == null || resultData.optimization.solution.Length <= 0) return null;
			int iNumberOfVariables = this.getVariableNumber();
			if(iNumberOfVariables <= 0) return null;
			int iSolutions = resultData.optimization.solution.Length;
			double[] mdValues = null;
			for(int i = 0; i < iSolutions; i++){
				if(resultData.optimization.solution[i] == null) continue;
				if(resultData.optimization.solution[i].objectiveIdx != objIdx) continue;
				if(resultData.optimization.solution[i].variables == null) continue;
				if(resultData.optimization.solution[i].variables.values == null) continue;
				if((resultData.optimization.solution[i].status.type.EndsWith("ptimal") && mdValues == null)||
					resultData.optimization.solution[i].status.type.Equals("globallyOptimal")){				
					VarValue[] var = resultData.optimization.solution[i].variables.values.var; 
					int iVars = (var==null)?0:var.Length;
					mdValues = new double[iNumberOfVariables];
					for(int j = 0; j < iVars; j++){
						mdValues[var[j].idx] = var[j].value;
					}
				}	
				if(resultData.optimization.solution[i].status.type.Equals("globallyOptimal")){
					return mdValues;
				}
			}
			return mdValues;		
		}//getOptimalPrimalVariableValues

		/// <summary>
		/// Get one solution of optimal primal variable string values.
		/// </summary>
		/// <param name="objIdx"> holds the objective index the optimal value corresponds to.</param> 
		/// <returns> a string dense array of the optimal string values, null if no optimal value. </returns>
		public string[] getOptimalPrimalVariablestringValues(int objIdx){
			if(resultData.optimization == null) return null;
			if(resultData.optimization.solution == null || resultData.optimization.solution.Length <= 0) return null;
			int iNumberOfVariables = this.getVariableNumber();
			if(iNumberOfVariables <= 0) return null;
			int iSolutions = resultData.optimization.solution.Length;
			string[] msValues = null;
			for(int i = 0; i < iSolutions; i++){
				if(resultData.optimization.solution[i] == null) continue;
				if(resultData.optimization.solution[i].objectiveIdx != objIdx) continue;
				if(resultData.optimization.solution[i].variables == null) continue;
				if(resultData.optimization.solution[i].variables.valuesString == null) continue;
				if((resultData.optimization.solution[i].status.type.EndsWith("ptimal") && msValues == null)||
					resultData.optimization.solution[i].status.type.Equals("globallyOptimal")){
					VarStringValue[] var = resultData.optimization.solution[i].variables.valuesString.var; 
					int iVars = (var==null)?0:var.Length;
					msValues = new string[iNumberOfVariables];
					for(int j = 0; j < iVars; j++){
						msValues[var[j].idx] = var[j].value;
					}
				}	
				if(resultData.optimization.solution[i].status.type.Equals("globallyOptimal")){
					return msValues;
				}
			}
			return msValues;		
		}//getOptimalPrimalVariablestringValues
	
		/// <summary>
		/// Get one solution of optimal dual variable values. 
		/// </summary>
		/// <param name="objIdx"> holds the objective index the optimal value corresponds to. </param>
		/// <returns> a double dense array of the optimal dual values, null if no optimal value. </returns>
		public double[] getOptimalDualVariableValues(int objIdx){
			if(resultData.optimization == null) return null;
			if(resultData.optimization.solution == null || resultData.optimization.solution.Length <= 0) return null;
			int iNumberOfConstraints = this.getConstraintNumber();
			if(iNumberOfConstraints <= 0) return null;
			int iSolutions = resultData.optimization.solution.Length;
			double[] mdValues = null;
			for(int i = 0; i < iSolutions; i++){
				if(resultData.optimization.solution[i] == null) continue;
				if(resultData.optimization.solution[i].objectiveIdx != objIdx) continue;
				if(resultData.optimization.solution[i].constraints == null) continue;
				if(resultData.optimization.solution[i].constraints.dualValues == null) continue;
				if((resultData.optimization.solution[i].status.type.EndsWith("ptimal") && mdValues == null)||
					resultData.optimization.solution[i].status.type.Equals("globallyOptimal")){				
					DualVarValue[] con = resultData.optimization.solution[i].constraints.dualValues.con; 
					int iCons = (con==null)?0:con.Length;
					mdValues = new double[iNumberOfConstraints];
					for(int j = 0; j < iCons; j++){
						mdValues[con[j].idx] = con[j].value;
					}
				}	
				if(resultData.optimization.solution[i].status.type.Equals("globallyOptimal")){
					return mdValues;
				}
			}
			return mdValues;		
		}//getOptimalDualVariableValues
	
		/// <summary>
		/// get the number of solutions. 
		/// </summary>
		/// <returns> the number of solutions, 0 if none.  </returns>
		public int getSolutionNumber(){
			if(m_iSolutionNumber == -1){
				if(resultData.optimization == null) return -1;
				m_iSolutionNumber = resultData.optimization.numberOfSolutions;
			}
			return m_iSolutionNumber;
		}//getSolutionNumber
	
		/// <summary>
		/// Get the [i]th optimization solution, where i equals the given solution index.
		/// </summary>
		/// <param name="solIdx"> holds the solution index to get the solution. 
		/// <returns> the optimization solution that corresponds to solIdx, null if none. 
		public OptimizationSolution getSolution(int solIdx){
			if(resultData.optimization == null) return null;
			if(resultData.optimization.solution == null || 
				resultData.optimization.solution.Length <= 0 || 
				solIdx < 0 || solIdx >=  resultData.optimization.solution.Length) return null;
			return resultData.optimization.solution[solIdx];
		}//getSolution
	
	
		/// <summary>
		/// Get the [i]th optimization solution status, where i equals the given solution index.   
		/// The solution status includes the status type, optional descriptions and possibly substatuses.
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolutionStatus
		/// </summary>
		/// <param name="solIdx"> holds the solution index to get the solution status. </param>
		/// <returns> the optimization solution status that corresponds to solIdx, null if none. </returns>
		public OptimizationSolutionStatus getSolutionStatus( int solIdx){
			if(resultData.optimization == null) return null;
			if(resultData.optimization.solution == null || 
				resultData.optimization.solution.Length <= 0 || 
				solIdx < 0 || solIdx >=  resultData.optimization.solution.Length) return null;
			if(resultData.optimization.solution[solIdx] == null) return null;
			return resultData.optimization.solution[solIdx].status;
		}//getSolutionStatus
	
		/// <summary>
		/// Get the [i]th optimization solution status type, where i equals the given solution index.   
		/// The solution status type can be: 
		/// unbounded, globallyOptimal, locallyOptimal, optimal, bestSoFar, feasible, infeasible, 
		/// stoppedByLimit, unsure, error, other 
		/// </summary>
		/// <param name="solIdx"> holds the solution index to get the solution status type. </param>
		/// <returns> the optimization solution status type that corresponds to solIdx, null or empty string if none. </returns>
		public string getSolutionStatusType(int solIdx){
			if(resultData.optimization == null) return null;
			if(resultData.optimization.solution == null || 
				resultData.optimization.solution.Length <= 0 || 
				solIdx < 0 || solIdx >=  resultData.optimization.solution.Length) return null;
			if(resultData.optimization.solution[solIdx] == null) return null;
			if(resultData.optimization.solution[solIdx].status == null) return null;
			return resultData.optimization.solution[solIdx].status.type;		
		}//getSolutionStatusType
	
		/// <summary>
		/// Get the [i]th optimization solution status description, where i equals the given solution index.   
		/// </summary>
		/// <param name="solIdx"> holds the solution index to get the solution status description. </param>
		/// <returns> the optimization solution status description that corresponds to solIdx, null or empty string if none.</returns>
		public string getSolutionStatusDescription(int solIdx){
			if(resultData.optimization == null) return null;
			if(resultData.optimization.solution == null || 
				resultData.optimization.solution.Length <= 0 || 
				solIdx < 0 || solIdx >=  resultData.optimization.solution.Length) return null;
			if(resultData.optimization.solution[solIdx] == null) return null;
			if(resultData.optimization.solution[solIdx].status == null) return null;
			return resultData.optimization.solution[solIdx].status.description;				
		}//getSolutionStatusDescription
	
		/// <summary>
		/// Get the [i]th optimization solution subStatuses, where i equals the given solution index.   
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolutionSubstatus;
		/// </summary>
		/// <param name="solIdx"> holds the solution index to get the solution substatuses. </param>
		/// <returns> an array optimization solution subStatuses that corresponds to solIdx, null or empty string if none.</returns>
		public OptimizationSolutionSubstatus[] getSolutionSubStatuses(int solIdx){
			if(resultData.optimization == null) return null;
			if(resultData.optimization.solution == null || 
				resultData.optimization.solution.Length <= 0 || 
				solIdx < 0 || solIdx >=  resultData.optimization.solution.Length) return null;
			if(resultData.optimization.solution[solIdx] == null) return null;
			if(resultData.optimization.solution[solIdx].status == null) return null;
			return resultData.optimization.solution[solIdx].status.substatus;				
		}//getSolutionSubStatuses

		/// <summary>
		/// Get the [i]th optimization solution message, where i equals the given solution index.  
		/// </summary>
		/// <param name="solIdx"> holds the solution index to get the solution message. </param>
		/// <returns> the optimization solution message that corresponds to solIdx, null or empty if none.</returns>
		public string getSolutionMessage(int solIdx){
			if(resultData.optimization == null) return null;
			if(resultData.optimization.solution == null || 
				resultData.optimization.solution.Length <= 0 || 
				solIdx < 0 || solIdx >=  resultData.optimization.solution.Length) return null;
			if(resultData.optimization.solution[solIdx] == null) return null;
			return resultData.optimization.solution[solIdx].message;
		}//getSolutionMessage
	
		/// <summary>
		/// Get the [i]th optimization solution's objective index, where i equals the given solution index. 
		/// The first objective's index should be -1, the second -2, and so on.  
		/// </summary>
		/// <param name="solIdx"> holds the solution index to get the variable string values. </param>
		/// <returns> the optimization objective index that corresponds to solIdx, 0 if none.
		/// All the objective indexes are negative starting from -1 downward. </returns>
		public int getSolutionObjectiveIndex(int solIdx){
			if(resultData.optimization == null) return 0;
			if(resultData.optimization.solution == null || 
				resultData.optimization.solution.Length <= 0 || 
				solIdx < 0 || solIdx >=  resultData.optimization.solution.Length) return 0;
			if(resultData.optimization.solution[solIdx] == null) return 0;
			return resultData.optimization.solution[solIdx].objectiveIdx;		
		}//getSolutionObjectiveIndex
	
		/// <summary>
		/// Get the [i]th optimization solution's variable values, where i equals the given solution index. 
		/// </summary>
		/// <param name="solIdx"> holds the solution index to get the variable values. </param>
		/// <returns> a double dense array of variable values, null if no variable values. </returns>
		public double[] getVariableValues(int solIdx){
			if(resultData.optimization == null) return null;
			if(resultData.optimization.solution == null || resultData.optimization.solution.Length <= 0) return null;
			int iNumberOfVariables = this.getVariableNumber();
			if(iNumberOfVariables <= 0) return null;
			int iSolutions = resultData.optimization.solution.Length;
			if(solIdx < 0 || solIdx >= iSolutions) return null;
			if(resultData.optimization.solution[solIdx] == null) return null;
			if(resultData.optimization.solution[solIdx].variables == null) return null;
			if(resultData.optimization.solution[solIdx].variables.values == null) return null;
			VarValue[] var = resultData.optimization.solution[solIdx].variables.values.var; 
			int iVars = (var==null)?0:var.Length;
			double[] mdValues = new double[iNumberOfVariables];
			for(int i = 0; i < iVars; i++){
				mdValues[var[i].idx] = var[i].value;
			}
			return mdValues;		
		}//getVariableValues
	
		/// @see org.optimizationservices.oscommon.datastructure.osresult.VariableValues
		/// @see org.optimizationservices.oscommon.datastructure.osresult.VarValue
		/// <summary>
		/// Get the [i]th optimization solution's variable values in a sparse data structure, where i equals the given solution index. 
		/// The sparse data stucture is of the VariableValues data structure. VariableValues holds var[], an array of VarValues. 
		/// Each var member contains an idx and a value. If var[] is null, all the variable values are 0. 
		/// </summary>
		/// <param name="solIdx"> holds the solution index to get the sparse variable values. </param>
		/// <returns> a sparse variable value data structure in VaribleValues, null if no variable values.</returns> 
		public VariableValues getSparseVariableValues(int solIdx){
			if(resultData.optimization == null) return null;
			if(resultData.optimization.solution == null || resultData.optimization.solution.Length <= 0) return null;
			int iNumberOfVariables = this.getVariableNumber();
			if(iNumberOfVariables <= 0) return null;
			int iSolutions = resultData.optimization.solution.Length;
			if(solIdx < 0 || solIdx >= iSolutions) return null;
			if(resultData.optimization.solution[solIdx] == null) return null;
			if(resultData.optimization.solution[solIdx].variables == null) return null;
			return resultData.optimization.solution[solIdx].variables.values;
		}//getSparseVariableValues
	
		/// <summary>
		/// Get the [i]th optimization solution's variable string values, where i equals the given solution index. 
		/// </summary>
		/// <param name="solIdx"> holds the solution index to get the variable string values. </param>
		/// <returns> a string dense array of variable values, null if no variable values. </returns>
		public double[] getVariablestringValues(int solIdx){
			if(resultData.optimization == null) return null;
			if(resultData.optimization.solution == null || resultData.optimization.solution.Length <= 0) return null;
			int iNumberOfVariables = this.getVariableNumber();
			if(iNumberOfVariables <= 0) return null;
			int iSolutions = resultData.optimization.solution.Length;
			if(solIdx < 0 || solIdx >= iSolutions) return null;
			if(resultData.optimization.solution[solIdx] == null) return null;
			if(resultData.optimization.solution[solIdx].variables == null) return null;
			if(resultData.optimization.solution[solIdx].variables.values == null) return null;
			VarValue[] var = resultData.optimization.solution[solIdx].variables.values.var; 
			int iVars = (var==null)?0:var.Length;
			double[] mdValues = new double[iNumberOfVariables];
			for(int i = 0; i < iVars; i++){
				mdValues[var[i].idx] = var[i].value;
			}
			return mdValues;		
		}//getVariablestringValues
		
		/// <summary>
		/// Get the [i]th optimization solution's other (non-standard/solver specific)variable-related results, 
		/// where i equals the given solution index. 
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OtherVariableResult
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OtherVarResult
		/// </summary>
		/// <param name="solIdx"> holds the solution index to get the other variable results. </param>
		/// <returns> an array of other variable results in OtherVariableResult[] array data structure, null if none. 
		/// Each other variable result contains the name (required), an optional description (string) and an optional
		/// value (string). Each other variable result can also optionally contain an array OtherVarResult for each variable. 
		/// The OtherVarResult contains a variable idx (required), an optional string value.  
		/// </returns>
		public OtherVariableResult[] getOtherVariableResults(int solIdx){
			if(resultData.optimization == null) return null;
			if(resultData.optimization.solution == null || resultData.optimization.solution.Length <= 0) return null;
			int iNumberOfVariables = this.getVariableNumber();
			if(iNumberOfVariables <= 0) return null;
			int iSolutions = resultData.optimization.solution.Length;
			if(solIdx < 0 || solIdx >= iSolutions) return null;
			if(resultData.optimization.solution[solIdx] == null) return null;
			if(resultData.optimization.solution[solIdx].variables == null) return null;
			return resultData.optimization.solution[solIdx].variables.other;	
		}//getOtherVariableResults
	
		/// <summary>
		/// Get the [i]th optimization solution's objective values, where i equals the given solution index. 
		/// Usually one of the objective is what the solution was solved for (or based on). Its index should be indicated 
		/// in the solution's objectiveIdx attribute. Based on this objective's solution, the rest of the objective 
		/// values are (optionally) calculated. 
		/// </summary>
		/// <param name="solIdx"> holds the solution index to get the objective values. </param>
		/// <returns> a double dense array of objective values, null if null if no objective values. 
		/// Possibly only the objective that the solution is based on has the value, and the rest of the objective
		/// values all get a Double.NaN value, meaning that they are not calculated. </returns>  
		public double[] getObjectiveValues(int solIdx){
			if(resultData.optimization == null) return null;
			if(resultData.optimization.solution == null || resultData.optimization.solution.Length <= 0) return null;
			int iNumberOfObjectives = this.getObjectiveNumber();
			if(iNumberOfObjectives <= 0) return null;
			int iSolutions = resultData.optimization.solution.Length;
			if(solIdx < 0 || solIdx >= iSolutions) return null;
			if(resultData.optimization.solution[solIdx] == null) return null;
			if(resultData.optimization.solution[solIdx].objectives == null) return null;
			if(resultData.optimization.solution[solIdx].objectives.values == null) return null;
			ObjValue[] obj = resultData.optimization.solution[solIdx].objectives.values.obj; 
			int iObjs = (obj==null)?0:obj.Length;
			double[] mdValues = new double[iNumberOfObjectives];
			for(int i = 0; i < iNumberOfObjectives; i++){
				mdValues[i] = Double.NaN;
			}
			for(int i = 0; i < iObjs; i++){
				mdValues[Math.Abs(obj[i].idx)-1] = obj[i].value;
			}
			return mdValues;		
		}//getObjectiveValues
		
		/// <summary>
		/// Get the [i]th optimization solution's other (non-standard/solver specific)objective-related results, 
		/// where i equals the given solution index. 
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OtherObjectiveResult
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OtherObjResult
		/// </summary>
		/// <param name="solIdx"> holds the solution index to get the other objective results. </param>
		/// <returns> an array of other objective results in OtherObjectiveResult[] array data structure, null if none. 
		/// Each other objective result contains the name (required), an optional description (string) and an optional
		/// value (string). Each other objective result can also optionally contain an array OtherObjResult for each objective. 
		/// The OtherObjResult contains an objective idx (required) and an optional string value.  
		/// </returns>
		public OtherObjectiveResult[] getOtherObjectiveResults(int solIdx){
			if(resultData.optimization == null) return null;
			if(resultData.optimization.solution == null || resultData.optimization.solution.Length <= 0) return null;
			int iNumberOfObjectives = this.getObjectiveNumber();
			if(iNumberOfObjectives <= 0) return null;
			int iSolutions = resultData.optimization.solution.Length;
			if(solIdx < 0 || solIdx >= iSolutions) return null;
			if(resultData.optimization.solution[solIdx] == null) return null;
			if(resultData.optimization.solution[solIdx].objectives == null) return null;
			return resultData.optimization.solution[solIdx].objectives.other;	
		}//getOtherObjectiveResults
	
	
		/// <summary>
		/// Get the [i]th optimization solution's dual variable values, where i equals the given solution index. 
		/// </summary>
		/// <param name="solIdx"> holds the solution index to get the dual variable values. </param>
		/// <returns> a double dense array of the dual variable values, null if none. </returns>
		public double[] getDualVariableValues(int solIdx){
			if(resultData.optimization == null) return null;
			if(resultData.optimization.solution == null || resultData.optimization.solution.Length <= 0) return null;
			int iNumberOfConstraints = this.getConstraintNumber();
			if(iNumberOfConstraints <= 0) return null;
			int iSolutions = resultData.optimization.solution.Length;
			if(solIdx < 0 || solIdx >= iSolutions) return null;
			if(resultData.optimization.solution[solIdx] == null) return null;
			if(resultData.optimization.solution[solIdx].constraints == null) return null;
			if(resultData.optimization.solution[solIdx].constraints.dualValues == null) return null;
			DualVarValue[] con = resultData.optimization.solution[solIdx].constraints.dualValues.con; 
			int iCons = (con==null)?0:con.Length;
			double[] mdValues = new double[iNumberOfConstraints];
			for(int j = 0; j < iCons; j++){
				if(!Double.IsNaN(con[j].value)){
					mdValues[con[j].idx] = con[j].value;
				}
			}
			return mdValues;				
		}//getDualVariableValues
	
	
		/// <summary>
		/// Get the [i]th optimization solution's dual variable values in a sparse data structure, where i equals the given solution index. 
		/// The sparse data stucture is of the DualVariableValues data structure. DualVariableValues holds con[], an array of DualVarValues. 
		/// Each con member contains a constraint idx and a dual value. If con[] is null, all the dual variable values are 0. 
		/// @see org.optimizationservices.oscommon.datastructure.osresult.DualVariableValues
		/// @see org.optimizationservices.oscommon.datastructure.osresult.DualVarValue
		/// </summary>
		/// <param name="solIdx"> holds the solution index to get the sparse dual variable values. </param>
		/// <returns> a sparse variable value data structure in DualVaribleValues, null if no dual variable values. </returns>
		public DualVariableValues getSparseDualVariableValues(int solIdx){
			if(resultData.optimization == null) return null;
			if(resultData.optimization.solution == null || resultData.optimization.solution.Length <= 0) return null;
			int iNumberOfConstraints = this.getConstraintNumber();
			if(iNumberOfConstraints <= 0) return null;
			int iSolutions = resultData.optimization.solution.Length;
			if(solIdx < 0 || solIdx >= iSolutions) return null;
			if(resultData.optimization.solution[solIdx] == null) return null;
			if(resultData.optimization.solution[solIdx].constraints == null) return null;
			return resultData.optimization.solution[solIdx].constraints.dualValues;
		}//getSparseDualVariableValues
		
		/// <summary>
		/// Get the [i]th optimization solution's other (non-standard/solver specific)constraint-related results, 
		/// where i equals the given solution index. 
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OtherConstraintResult
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OtherConResult
		/// </summary>
		/// <param name="solIdx"> holds the solution index to get the other constraint results. </param>
		/// <returns> an array of other constraint results in OtherConstraintResult[] array data structure, null if none. 
		/// Each other constraint result contains the name (required), an optional description (string) and an optional
		/// value (string). Each other constraint result can also optionally contain an array OtherConResult for each constraint. 
		/// The OtherConResult contains a constraint idx (required), an optional string value 
		/// </returns>
		public OtherConstraintResult[] getOtherConstraintResults(int solIdx){
			if(resultData.optimization == null) return null;
			if(resultData.optimization.solution == null || resultData.optimization.solution.Length <= 0) return null;
			int iNumberOfConstraints = this.getConstraintNumber();
			if(iNumberOfConstraints <= 0) return null;
			int iSolutions = resultData.optimization.solution.Length;
			if(solIdx < 0 || solIdx >= iSolutions) return null;
			if(resultData.optimization.solution[solIdx] == null) return null;
			if(resultData.optimization.solution[solIdx].constraints == null) return null;
			return resultData.optimization.solution[solIdx].constraints.other;	
		}//getOtherConstraintResults

		/// <summary>
		/// Get the [i]th optimization solution's other (non-standard/solver specific)optimization-related results, 
		/// where i equals the given solution index. These other results are usually on the general optimization, 
		/// not specifically on the variables, objective, or constraints. 
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OtherOptimizationResult
		/// </summary>
		/// <param name="solIdx"> holds the solution index to get the other optimization results. </param>
		/// <returns> an array of other optimization results in OtherOptimizationResult[] array data structure, null if none. 
		/// Each other optimization result contains the name (required), an optional description (string) and an optional
		/// value (string).   
		/// </returns>
		public OtherOptimizationResult[] getOtherOptimizationResults(int solIdx){
			if(resultData.optimization == null) return null;
			if(resultData.optimization.solution == null || resultData.optimization.solution.Length <= 0) return null;
			int iSolutions = resultData.optimization.solution.Length;
			if(solIdx < 0 || solIdx >= iSolutions) return null;
			if(resultData.optimization.solution[solIdx] == null) return null;
			return resultData.optimization.solution[solIdx].other;	
		}//getOtherOptimizationResults


		/// <summary>
		/// Get the optimization analysis in the standard OSAnalysis data structure. 
		/// @see org.optimizationservices.oscommon.localinterface.OSAnalysis
		/// </summary>
		/// <returns> the optimization analysis in the standard OSAnalysis data structure, null if none.</returns>
		public OSAnalysis getOSAnalysis(){
			if(resultData.optimization == null) return null;
			return resultData.optimization.osal;
		}//getOSAnalysis
	
		/// <summary>
		/// Set service name.
		/// </summary>
		/// <param name="serviceName"> holds the name of the service. </param>
		/// <returns> whether the service name is set successfully. </returns>
		public bool setServiceName(string serviceName){
			resultHeader.serviceName = serviceName;
			return true;
		}//setServiceName
	
		/// <summary>
		/// Set service uri.
		/// </summary>
		/// <param name="serviceURI"> holds the uri of the service. </param>
		/// <returns> whether the service uri is set successfully. </returns>
		public bool setServiceURI(string serviceURI){
			resultHeader.serviceURI = serviceURI;
			return true;
		}//setServiceURI
	
		/// <summary>
		/// Set instance name.
		/// </summary>
		/// <param name="instanceName"> holds the name of the instance. </param>
		/// <returns> whether the instance name is set successfully. </returns>
		public bool setInstanceName(string instanceName){
			resultHeader.instanceName = instanceName;
			return true;
		}//setInstanceName
	
		/// <summary>
		/// Set job id.
		/// </summary>
		/// <param name="jobID"> holds the job id. </param>
		/// <returns> whether the job id is set successfully. </returns> 
		public bool setJobID(string jobID){
			resultHeader.jobID = jobID;
			return true;
		}//setJobID
	
		/// <summary>
		/// Set time of the result.
		/// </summary>
		/// <param name="time"> holds the time of the result.</param>
		/// <returns> whether result time is set successfully. </returns>
		public bool setResultTime(DateTime time){
			resultHeader.time = time;
			return true;
		}//setResultTime
	
		/// <summary>
		/// Set the general message. 
		/// </summary>
		/// <param name="message"> holds the general message. </param>
		/// <returns> whether process message is set successfully. </returns>
		public bool setGeneralMessage(string message){
			resultHeader.message = message;
			return true;
		}//setGeneralMessage

		/// <summary>
		/// Set the general status
		/// </summary>
		/// <param name="status">holds the general status.</param>
		/// <returns>whether the general status is set successfully. </returns>
		public bool setGeneralStatus(GeneralStatus status){
			resultHeader.generalStatus = status;
			return true;
		}//setGeneralStatus

		/// <summary>
		/// Set the general status type, which can be: 
		/// success, error, warning. 
		/// </summary>
		/// <param name="type"> holds the general status type</param>
		/// <returns> whether the general status type is set successfully or not. </returns>
		public bool setGeneralStatusType(string type){
			if(resultHeader.generalStatus == null) resultHeader.generalStatus = new GeneralStatus();
			resultHeader.generalStatus.type = type;
			return true;
		}//setGeneralStatusType

		/// <summary>
		/// Set the general status description. 
		/// </summary>
		/// <param name="description"> holds the general status description.</param>
		/// <returns> whether the general status description is set successfully or not. </returns>
		public bool setGeneralStatusDescription(string description){
			if(resultHeader.generalStatus == null) resultHeader.generalStatus = new GeneralStatus();
			resultHeader.generalStatus.description = description;
			return true;
		}//setGeneralStatusDescription
	
		/// <summary>
		/// Set the process statistics. 
		/// </summary>
		/// <param name="processStatistics"> holds the process statistics. </param>
		/// <returns> whether the process statistics is set successfully. </returns>
		public bool setProcessStatistics(ProcessStatistics processStatistics){
			resultData.statistics = processStatistics;
			return true;
		}//setprocessStatistics
	
		/// <summary>
		/// Set the statistics of all jobs. 
		/// </summary>
		/// <param name="jobStatistics"> holds an array of jobStatistics with 
		/// each member corresponding to one job. </param>
		/// <returns> whether the job statistics are set successfully. 
		public bool setJobStatistics(JobStatistics[] jobStatistics){
			if(resultData.statistics == null) resultData.statistics = new ProcessStatistics();
			if(resultData.statistics.jobs == null) resultData.statistics.jobs = new Jobs();
			resultData.statistics.jobs.job = jobStatistics;
			return true;
		}//setJobStatistics

		/// <summary>
		/// Set the current state. 
		/// </summary>
		/// <param name="currentState">holds the current state, which can be:
		/// "busy", "busyButAccepting", "idle", "idleButNotAccepting" or "noResponse".
		/// </param>
		/// <returns>whether the current state is set successfully.</returns>
		public bool setCurrentState(String currentState){
			if(!currentState.Equals("busy") && 
				!currentState.Equals("busyButAccepting") &&
				!currentState.Equals("idle") &&
				!currentState.Equals("idleButNotAccepting") &&
				!currentState.Equals("noResponse")) return false;		 
			if(resultData.statistics == null) resultData.statistics = new ProcessStatistics();
			resultData.statistics.currentState = currentState;
			return true;
		}//setCurrentState

		/// <summary>
		/// Set the available disk space. 
		/// </summary>
		/// <param name="availableDiskSpace">holds the available disk space  (in bytes). </param>
		/// <returns>whether the available disk space is set successfully.</returns>
		public bool setAvailableDiskSpace(double availableDiskSpace){
			if(resultData.statistics == null) resultData.statistics = new ProcessStatistics();
			resultData.statistics.availableDiskSpace = availableDiskSpace;
			return true;
		}//setAvailableDiskSpace

		/// <summary>
		/// Set the available memory. 
		/// </summary>
		/// <param name="availableMemory">holds the available memory (in bytes). </param>
		/// <returns>whether the available memory is set successfully.</returns>
		public bool setAvailableMemory(double availableMemory){
			if(resultData.statistics == null) resultData.statistics = new ProcessStatistics();
			resultData.statistics.availableMemory = availableMemory;
			return true;
		}//setAvailableMemory

		/// <summary>
		/// Set the current job count. 
		/// </summary>
		/// <param name="currentJobCount">holds the current job count. </param>
		/// <returns>whether the current job count is set successfully.</returns>
		public bool setCurrentJobCount(int currentJobCount){
			if(resultData.statistics == null) resultData.statistics = new ProcessStatistics();
			resultData.statistics.currentJobCount = currentJobCount;
			return true;
		}//setCurrentJobCount

		/// <summary>
		/// Set the total jobs received so far. 
		/// </summary>
		/// <param name="totalJobsSoFar">holds the total jobs received so far. </param>
		/// <returns>whether the total jobs so far is set successfully.</returns>
		public bool setTotalJobsSoFar(int totalJobsSoFar){
			if(resultData.statistics == null) resultData.statistics = new ProcessStatistics();
			resultData.statistics.totalJobsSoFar = totalJobsSoFar;
			return true;
		}//setTotalJobsSoFar

		/// <summary>
		/// Set the time last job ended. 
		/// </summary>
		/// <param name="timeLastJobEnded">holds the time last job ended. </param>
		/// <returns>whether the time last job ended is set successfully.</returns>
		public bool setTimeLastJobEnded(DateTime timeLastJobEnded){
			if(resultData.statistics == null) resultData.statistics = new ProcessStatistics();
			resultData.statistics.timeLastJobEnded = timeLastJobEnded;
			return true;
		}//setTimeLastJobEnded


		/// <summary>
		/// Set the time last job took. 
		/// </summary>
		/// <param name="timeLastJobTook">holds the time last job took (in seconds). </param>
		/// <returns>whether the time last job took is set successfully.</returns>
		public bool setTimeLastJobTook(double timeLastJobTook){
			if(resultData.statistics == null) resultData.statistics = new ProcessStatistics();
			resultData.statistics.timeLastJobTook = timeLastJobTook;
			return true;
		}//setTimeLastJobTook

		/// <summary>
		/// Set the time the service started. 
		/// </summary>
		/// <param name="timeServiceStarted">holds the time the service started. </param>
		/// <returns>whether the time the service started is set successfully.</returns>
		public bool setTimeServiceStarted(DateTime timeServiceStarted){
			if(resultData.statistics == null) resultData.statistics = new ProcessStatistics();
			resultData.statistics.timeServiceStarted = timeServiceStarted;
			return true;
		}//setTimeServiceStarted


		/// <summary>
		/// Set the service utilization. 
		/// </summary>
		/// <param name="serviceUtilization">holds the service utilization ([0, 1]). </param>
		/// <returns>whether the time last job took is set successfully.</returns>
		public bool setServiceUtilization(double serviceUtilization){
			if(resultData.statistics == null) resultData.statistics = new ProcessStatistics();
			resultData.statistics.serviceUtilization = serviceUtilization;
			return true;
		}//setServiceUtilization

		/// <summary>
		/// set other results, with their names (required), descriptions (optional) and values (optional). 
		/// </summary>
		/// <param name="names"> holds the names of the other results; it is required.  </param>
		/// <param name="descriptions"> holds the descriptions of the other results; null if none. </param>
		/// <param name="values"> holds the values of the other results; null if none. </param>
		/// <returns> whether the other anlysis information is set successfully. </returns>
		/// </summary>
		public bool setOtherResults(string[] names, string[] descriptions, string[] values){
			if(names == null) return false;
			if(descriptions != null && descriptions.Length != names.Length) return false;
			if(values != null && values.Length != names.Length) return false;
			int n = names.Length;
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
	
		/// <summary>
		/// Set the variable number. 
		/// </summary>
		/// <param name="variableNumber"> holds the number of variables</param>
		/// <returns> whether the variable number is set successfully or not. </returns>
		public bool setVariableNumber(int variableNumber){
			if(variableNumber <= 0){
				return false;
			}
			if(resultData.optimization == null) resultData.optimization = new OptimizationResult();
			resultData.optimization.numberOfVariables = variableNumber;
			return true;
		}//setVariableNumber

		/// <summary>
		/// Set the objective number. 
		/// </summary>
		/// <param name="objectiveNumber"> holds the number of objectives</param>
		/// <returns> whether the objective number is set successfully or not. </returns>
		public bool setObjectiveNumber(int objectiveNumber){
			if(objectiveNumber < 0){
				return false;
			}
			if(resultData.optimization == null) resultData.optimization = new OptimizationResult();
			resultData.optimization.numberOfObjectives = objectiveNumber;
			return true;
		}//setObjectiveNumber

		/// <summary>
		/// Set the constraint number. 
		/// </summary>
		/// <param name="constraintNumber"> holds the number of constraints</param>
		/// <returns> whether the constraint number is set successfully or not. </returns>
		public bool setConstraintNumber(int constraintNumber){
			if(constraintNumber < 0){
				return false;
			}
			if(resultData.optimization == null) resultData.optimization = new OptimizationResult();
			resultData.optimization.numberOfConstraints = constraintNumber;
			return true;
		}//setConstraintNumber

	
		/// <summary>
		/// set the number of solutions. This method must be called before setting other optimization solution 
		/// related results.  
		/// Before this method is called, the setVariableNumber(int), setObjectiveNumber(int), setConstraintNumber(int) methods 
		/// have to be called first. 
		/// @see #setVariableNumber(int)
		/// @see #setObjectiveNumber(int)
		/// @see #setConstraintNumber(int)
		/// </summary>
		/// <param name="solutionNumber"> holds the number of solutions to set. </param>
		/// <returns> whether the solution number is set successfully.   </returns>
		public bool setSolutionNumber(int solutionNumber){
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
	
		/// <summary>
		/// Set the [i]th optimization solution, where i equals the given solution index.   
		/// Before this method is called, the setSolutionNumber(int) method has to be called first. 
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolution
		/// @see #setSolutionNumber(int)
		/// </summary>
		/// <param name="solIdx"> holds the solution index to set the solution. </param>
		/// <param name="solution"> holds the optimization solution to set.</param> 
		/// <returns> whether the optimization solution is set successfully or not. </returns>
		public bool setSolution(int solIdx, OptimizationSolution solution){
			int nSols = this.getSolutionNumber();
			if(nSols <= 0) return false;
			if(resultData.optimization == null) return false;
			if(resultData.optimization.solution == null || 
				resultData.optimization.solution.Length <= 0 || 
				solIdx < 0 || solIdx >=  nSols) return false;
			resultData.optimization.solution[solIdx] = solution;
			return true;
		}//setSolution	
	
		/// <summary>
		/// Set the [i]th optimization solution status, where i equals the given solution index.   
		/// The solution status includes the status type, optional descriptions and possibly substatuses. 
		/// Before this method is called, the setSolutionNumber(int) method has to be called first. 
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolutionStatus
		/// @see #setSolutionNumber(int)
		/// </summary>
		/// <param name="solIdx"> holds the solution index to set the solution status.</param>
		/// <param name="status"> holds the optimization solution status to set.  </param>
		/// <returns> whether the optimization solution status is set successfully or not. </returns> 
		public bool setSolutionStatus(int solIdx, OptimizationSolutionStatus status){
			int nSols = this.getSolutionNumber();
			if(resultData.optimization == null) return false;
			if(nSols <= 0) return false;
			if(resultData.optimization == null) return false;
			if(resultData.optimization.solution == null || 
				resultData.optimization.solution.Length <= 0 || 
				solIdx < 0 || solIdx >=  nSols) return false;
			if(resultData.optimization.solution[solIdx] == null){
				resultData.optimization.solution[solIdx] = new OptimizationSolution();
			}
			resultData.optimization.solution[solIdx].status = status;
			return true;
		}//setSolutionStatus
	
		/// <summary>
		/// Set the [i]th optimization solution status, where i equals the given solution index.   
		/// The solution status includes the status type, optional descriptions and possibly substatuses. 
		/// Before this method is called, the setSolutionNumber(int) method has to be called first. 
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolutionStatus
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolutionSubStatus
		/// @see #setSolutionNumber(int)
		/// </summary>
		/// <param name="solIdx"> holds the solution index to set the solution status.</param>
		/// <param name="type"> holds the optimization solution status type to set; it is required.   
		/// The solution status type can be: 
		/// unbounded, globallyOptimal, locallyOptimal, optimal, bestSoFar, feasible, infeasible, 
		/// stoppedByLimit, unsure, error, other 
		/// </param>
		/// <param name="description"> holds the optimization solution status description to set, null or empty string if none. </param>
		/// <param name="subStatus"> holds an array of optimization solution subStatuses to set, null if none. </param>
		/// <returns> whether the optimization solution status is set successfully or not. </returns>
		public bool setSolutionStatus(int solIdx, string type, string description, OptimizationSolutionSubstatus[] subStatuses){
			int nSols = this.getSolutionNumber();
			if(resultData.optimization == null) return false;
			if(nSols <= 0) return false;
			if(resultData.optimization == null) return false;
			if(resultData.optimization.solution == null || 
				resultData.optimization.solution.Length <= 0 || 
				solIdx < 0 || solIdx >=  nSols) return false;
			if(resultData.optimization.solution[solIdx] == null){
				resultData.optimization.solution[solIdx] = new OptimizationSolution();
			}
			resultData.optimization.solution[solIdx].status = new OptimizationSolutionStatus();
			if(!type.Equals("unbounded") && 
				!type.Equals("globallyOptimal") && 
				!type.Equals("locallyOptimal") && 
				!type.Equals("optimal") && 
				!type.Equals("bestSoFar") && 
				!type.Equals("feasible") && 
				!type.Equals("infeasible") && 
				!type.Equals("stoppedByLimit") && 
				!type.Equals("unsure") && 
				!type.Equals("error") && 
				!type.Equals("other")) return false;
			resultData.optimization.solution[solIdx].status.type = type;
			resultData.optimization.solution[solIdx].status.description = description;
			resultData.optimization.solution[solIdx].status.substatus = subStatuses;
			return true;
		}//setSolutionStatus
	
		/// <summary>
		/// Set the [i]th optimization solution message, where i equals the given solution index.   
		/// Before this method is called, the setSolutionNumber(int) method has to be called first. 
		/// @see #setSolutionNumber(int)
		/// </summary>
		/// <param name="solIdx"> holds the solution index to set the solution message.</param>
		/// <param name="solutionMessage"> holds the solution message to set.  </param>
		/// <returns> whether the optimization solution message is set successfully or not. </returns>
		public bool setSolutionMessage(int solIdx, string solutionMessage){
			int nSols = this.getSolutionNumber();
			if(resultData.optimization == null) return false;
			if(nSols <= 0) return false;
			if(resultData.optimization == null) return false;
			if(resultData.optimization.solution == null || 
				resultData.optimization.solution.Length <= 0 || 
				solIdx < 0 || solIdx >=  nSols) return false;
			if(resultData.optimization.solution[solIdx] == null){
				resultData.optimization.solution[solIdx] = new OptimizationSolution();
			}
			resultData.optimization.solution[solIdx].message = solutionMessage;
			return true;
		}//setSolutionMessage	
	
		/// <summary>
		/// Set the [i]th optimization solution's objective index, where i equals the given solution index.   
		/// The first objective's index should be -1, the second -2, and so on.  
		/// Before this method is called, the setSolutionNumber(int) method has to be called first. 
		/// @see #setSolutionNumber(int)
		/// </summary>
		/// <param name="solIdx"> holds the solution index to set the objective index.</param>
		/// <param name="objectiveIdx"> holds the objective index to set. 
		/// All the objective indexes are negative starting from -1 downward. 
		/// </param>
		/// <returns> whether the optimization objective index is set successfully or not. </returns>
		public bool setSolutionObjectiveIndex(int solIdx, int objectiveIdx){
			int nSols = this.getSolutionNumber();
			if(resultData.optimization == null) return false;
			if(nSols <= 0) return false;
			if(resultData.optimization == null) return false;
			if(resultData.optimization.solution == null || 
				resultData.optimization.solution.Length <= 0 || 
				solIdx < 0 || solIdx >=  nSols) return false;
			if(resultData.optimization.solution[solIdx] == null){
				resultData.optimization.solution[solIdx] = new OptimizationSolution();
			}
			if(objectiveIdx >= 0) return false;
			resultData.optimization.solution[solIdx].objectiveIdx = objectiveIdx;
			return true;		
		}//setSolutionObjectiveIndex
	
		/// <summary>
		/// Set the [i]th optimization solution's primal variable values, where i equals the given solution index.   
		/// Before this method is called, the setSolutionNumber(int) method has to be called first. 
		/// @see #setSolutionNumber(int)
		/// </summary>
		/// <param name="solIdx"> holds the solution index to set the primal variable values. </param>
		/// <param name="x"> holds a double dense array of variable values to set; it could be null if all variables are 0.</param>
		/// <returns> whether primal variable values are set successfully or not. </returns>
		public bool setPrimalVariableValues(int solIdx, double[] x){
			int iNumberOfVariables = this.getVariableNumber();
			if(iNumberOfVariables <= 0) return false;
			if(x != null && x.Length != iNumberOfVariables) return false;
			int nSols = this.getSolutionNumber();
			if(resultData.optimization == null) return false;
			if(nSols <= 0) return false;
			if(resultData.optimization == null) return false;
			if(resultData.optimization.solution == null || 
				resultData.optimization.solution.Length <= 0 || 
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
			for(int i = 0; i < x.Length; i++){
				if(x[i] != 0) iVars++;
			}
			resultData.optimization.solution[solIdx].variables.values.var = new VarValue[iVars];
			VarValue[] var = resultData.optimization.solution[solIdx].variables.values.var;
			for(int i = 0; i < iVars; i++) var[i] = new VarValue();
			int j = 0;
			for(int i = 0; i < x.Length; i++){
				if(x[i] != 0){
					var[j].idx = i;
					var[j].value = x[i];
					j++;
				}
			}
			return true;
		}//setPrimalVariableValues
	
		/// <summary>
		/// Set the [i]th optimization solution's primal variable string values, where i equals the given solution index.   
		/// Before this method is called, the setSolutionNumber(int) method has to be called first. 
		/// @see #setSolutionNumber(int)
		/// </summary>
		/// <param name="solIdx"> holds the solution index to set the primal variable string values. </param>
		/// <param name="x"> holds a dense string array of variable string values to set.</param>
		/// <returns> whether primal variable string values are set successfully or not. </returns>
		public bool setPrimalVariablestringValues(int solIdx, string[] x){
			if(x == null) return false;
			int iNumberOfVariables = this.getVariableNumber();
			if(iNumberOfVariables <= 0) return false;
			if(x != null && x.Length != iNumberOfVariables) return false;
			int nSols = this.getSolutionNumber();
			if(resultData.optimization == null) return false;
			if(nSols <= 0) return false;
			if(resultData.optimization == null) return false;
			if(resultData.optimization.solution == null || 
				resultData.optimization.solution.Length <= 0 || 
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
		}//setPrimalVariablestringValues
		
		/// <summary>
		/// Set the [i]th optimization solution's other (non-standard/solver specific)variable-related results, 
		/// where i equals the given solution index.   
		/// Before this method is called, the setSolutionNumber(int) method has to be called first. 
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OtherVariableResult
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OtherVarResult
		/// @see #setSolutionNumber(int)
		/// </summary>
		/// <param name="otherVariableResults"> holds an array of other variable results in OtherVariableResult[] array data structure, null if none. 
		/// Each other variable result contains the name (required), an optional description (string) and an optional
		/// value (string). Each other variable result can also optionally contain an array OtherVarResult for each variable. 
		/// The OtherVarResult contains a variable idx (required), an optional string value.   
		/// </param>
		/// <returns> whether the other variable results are set successfully or not. </returns>
		public bool setOtherVariableResults(int solIdx, OtherVariableResult[] otherVariableResults){
			int iNumberOfVariables = this.getVariableNumber();
			if(iNumberOfVariables <= 0) return false;
			int nSols = this.getSolutionNumber();
			if(resultData.optimization == null) return false;
			if(nSols <= 0) return false;
			if(resultData.optimization == null) return false;
			if(resultData.optimization.solution == null || 
				resultData.optimization.solution.Length <= 0 || 
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
	
		/// <summary>
		/// Set the [i]th optimization solution's objective values, where i equals the given solution index.   
		/// Usually one of the objective is what the solution was solved for (or based on). Its index should be indicated 
		/// in the solution's objectiveIdx attribute. Based on this objective's solution, the rest of the objective 
		/// values are (optionally) calculated. 
		/// Before this method is called, the setSolutionNumber(int) method has to be called first. 
		/// @see #setSolutionNumber(int)
		/// </summary>
		/// <param name="solIdx"> holds the solution index to set the objective values. </param>
		/// <param name="objectiveValues"> holds a double dense array of objective values to set.
		/// Possibly only the objective that the solution is based on has the value, and the rest of the objective
		/// values all get a Double.NaN value, meaning that they are not calculated.   
		/// </param>
		/// <returns> whether objective values are set successfully or not. </returns>
		public bool setObjectiveValues(int solIdx, double[] objectiveValues){
			int iNumberOfObjectives = this.getObjectiveNumber();
			if(iNumberOfObjectives < 0) return false;
			if(iNumberOfObjectives == 0) return true;
			if(objectiveValues == null) return false;
			if(objectiveValues.Length != iNumberOfObjectives) return false;
			int nSols = this.getSolutionNumber();
			if(resultData.optimization == null) return false;
			if(nSols <= 0) return false;
			if(resultData.optimization == null) return false;
			if(resultData.optimization.solution == null || 
				resultData.optimization.solution.Length <= 0 || 
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
			for(int i = 0; i < objectiveValues.Length; i++){
				if(!Double.IsNaN(objectiveValues[i])) iObjs++;
			}
			resultData.optimization.solution[solIdx].objectives.values.obj = new ObjValue[iObjs];
			ObjValue[] obj = resultData.optimization.solution[solIdx].objectives.values.obj;
			for(int i = 0; i < iObjs; i++) obj[i] = new ObjValue();
			int j = 0;
			for(int i = 0; i < objectiveValues.Length; i++){
				if(!Double.IsNaN(objectiveValues[i])){
					obj[j].idx = -(i+1);
					obj[j].value = objectiveValues[i];
					j++;
				}
			}
			return true;
		}//setObjectiveValues
	
		/// <summary>
		/// Set the [i]th optimization solution's other (non-standard/solver specific)objective-related results, 
		/// where i equals the given solution index.   
		/// Before this method is called, the setSolutionNumber(int) method has to be called first. 
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OtherObjectiveResult
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OtherObjResult
		/// @see #setSolutionNumber(int)
		/// </summary>
		/// <param name="solIdx"> holds the solution index to set the other objective results. </param>
		/// <param name="otherObjectiveResults"> holds an array of other objective results in OtherObjectiveResult[] array data structure, null if none. 
		/// Each other objective result contains the name (required), an optional description (string) and an optional
		/// value (string). Each other objective result can also optionally contain an array OtherObjResult for each objective. 
		/// The OtherObjResult contains an objective idx (required), an optional string value.  
		/// </param>  
		/// <returns> whether the other objective results are set successfully or not. </returns>
		public bool setOtherObjectiveResults(int solIdx, OtherObjectiveResult[] otherObjectiveResults){
			int iNumberOfObjectives = this.getObjectiveNumber();
			if(iNumberOfObjectives <= 0) return false;
			int nSols = this.getSolutionNumber();
			if(resultData.optimization == null) return false;
			if(nSols <= 0) return false;
			if(resultData.optimization == null) return false;
			if(resultData.optimization.solution == null || 
				resultData.optimization.solution.Length <= 0 || 
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
	

		/// <summary>
		/// Set the [i]th optimization solution's dual variable values, where i equals the given solution index. 
		/// Before this method is called, the setSolutionNumber(int) method has to be called first. 
		/// @see #setSolutionNumber(int)
		/// </summary>
		/// <param name="solIdx"> holds the solution index to set the dual variable values. </param>
		/// <param name="values"> holds a double dense array of variable values to set; it could be null if all values are 0.</param>
		/// <returns> whether dual variable values are set successfully or not. </returns>
		public bool setDualVariableValues(int solIdx, double[] values){
			int iNumberOfConstraints = this.getConstraintNumber();
			if(iNumberOfConstraints < 0) return false;
			if(iNumberOfConstraints == 0) return true;
			if(values != null && values.Length != iNumberOfConstraints) return false;
			int nSols = this.getSolutionNumber();
			if(resultData.optimization == null) return false;
			if(nSols <= 0) return false;
			if(resultData.optimization == null) return false;
			if(resultData.optimization.solution == null || 
				resultData.optimization.solution.Length <= 0 || 
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
			for(int i = 0; i < values.Length; i++){
				if(values[i] != 0) iCons++;
			}
			resultData.optimization.solution[solIdx].constraints.dualValues.con = new DualVarValue[iCons];
			DualVarValue[] con = resultData.optimization.solution[solIdx].constraints.dualValues.con;
			for(int i = 0; i < iCons; i++) con[i] = new DualVarValue();
			int j = 0;
			for(int i = 0; i < values.Length; i++){
				if(values[i] != 0){
					con[j].idx = i;
					con[j].value = values[i];
					j++;
				}
			}
			return true;	
		}//setDualVariableValues
	
		
		/// <summary>
		/// Set the [i]th optimization solution's other (non-standard/solver specific)constraint-related results, 
		/// where i equals the given solution index.   
		/// Before this method is called, the setSolutionNumber(int) method has to be called first. 
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OtherConstraintResult
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OtherConResult
		/// @see #setSolutionNumber(int)
		/// </summary>
		/// <param name="otherConstraintResults"> holds an array of other constraint results in OtherConstraintResult[] array data structure, null if none. 
		/// Each other constraint result contains the name (required), an optional description (string) and an optional
		/// value (string). Each other constraint result can also optionally contain an array OtherConstraint for each constraint. 
		/// The OtherConResult contains a constraint idx (required), an optional string value.   
		/// </param>
		/// <returns> whether the other constraint results are set successfully or not. </returns>
		public bool setOtherConstraintResults(int solIdx, OtherConstraintResult[] otherConstraintResults){
			int iNumberOfConstraints = this.getConstraintNumber();
			if(iNumberOfConstraints <= 0) return false;
			int nSols = this.getSolutionNumber();
			if(resultData.optimization == null) return false;
			if(nSols <= 0) return false;
			if(resultData.optimization == null) return false;
			if(resultData.optimization.solution == null || 
				resultData.optimization.solution.Length <= 0 || 
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

		/// <summary>
		/// Set the [i]th optimization solution's other (non-standard/solver specific)optimization-related results, 
		/// where i equals the given solution index.  These other results are usually on the general optimization, 
		/// not specifically on the variables, objective, or constraints.  
		/// Before this method is called, the setSolutionNumber(int) method has to be called first. 
		/// @see org.optimizationservices.oscommon.datastructure.osresult.OtherOptimizationResult
		/// @see #setSolutionNumber(int)
		/// </summary>
		/// <param name="otherOptimizationResults"> holds an array of other optimization results in OtherOptimizationResult[] array data structure, null if none. 
		/// Each other optimization result contains the name (required), an optional description (string) and an optional
		/// value (string).  
		/// </param>
		/// <returns> whether the other optimization results are set successfully or not. </returns>
		public bool setOtherOptimizationResults(int solIdx, OtherOptimizationResult[] otherOptimizationResults){
			int nSols = this.getSolutionNumber();
			if(resultData.optimization == null) return false;
			if(nSols <= 0) return false;
			if(resultData.optimization == null) return false;
			if(resultData.optimization.solution == null || 
				resultData.optimization.solution.Length <= 0 || 
				solIdx < 0 || solIdx >=  nSols) return false;
			if(resultData.optimization.solution[solIdx] == null){
				resultData.optimization.solution[solIdx] = new OptimizationSolution();
			}
			resultData.optimization.solution[solIdx].other = otherOptimizationResults;
			return true;		
		}//setOtherOptimizationResults

		/// <summary>
		/// Set the optimization analysis. 
		/// @see org.optimizationservices.oscommon.localinterface.OSAnalysis
		/// </summary>
		/// <param name="osAnalysis"> holds the optimization analysis in the standard OSAnalysis data structure. </param>
		/// <returns> the optimization analysis in the standard OSAnalysis data structure, null if none.</returns>
		public bool setOSAnalysis(OSAnalysis osAnalysis){
			if(resultData.optimization == null) resultData.optimization = new OptimizationResult();
			resultData.optimization.osal = osAnalysis;
			return false;
		}//setOSAnalysis
	


	}//class OSResult
}//namespace
