using System;
using System.Collections;

using org.optimizationservices.oscommon.datastructure.osanalysis;
using org.optimizationservices.oscommon.representationparser;

namespace org.optimizationservices.oscommon.localinterface{
	/// <summary>
	/// The <c>OSAnalysis</c> class is a local interface for storing OS 
	/// problem analysis. Its design follows the OSaL. Naming, structuring and layering 
	/// all are exactly the same as those in the OSaL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// <see cref="org.optimizationservices.oscommon.localinterface.OSInstance"/>
	/// <see cref="org.optimizationservices.oscommon.localinterface.OSResult"/>
	/// <see cref="org.optimizationservices.oscommon.localinterface.OSOption"/>
	/// </summary>
	public class OSAnalysis{

		/// <summary>
		/// analysisHeader holds the first child of the OSAnalysis specified by the OSaL Schema. 
		/// </summary>
		public AnalysisHeader analysisHeader = new AnalysisHeader();

		/// <summary>
		/// analysisData holds the second child of the OSAnalysis specified by the OSaL Schema. 
		/// </summary>
		public AnalysisData analysisData = new AnalysisData();

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
		/// Default constructor. 
		/// </summary>
		public OSAnalysis(){
		}//constructor

		/// <summary>
		/// read an OSaL instance and return and OSAnalysis object.  
		/// @throws Exception if there are errors in reading the string or setting the OSAnalysis. 
		/// </summary>
		/// <param name="osal">holds the optimization analysis in a string which format follows the
		/// Optimization Services analysis Language (OSaL) schema</param>
		/// <param name="isFile">isFile holds whether the osal string is a file name or a string that literally holds the osal contents.  </param>
		/// <param name="validate">holds whether the reader should be validating against the schema or not.</param>
		/// <returns>the OSAnalysis object constructed from the OSaL String.  </returns>
   		public OSAnalysis readOSaL(string osal, bool isFile, bool validate){
   			OSaLReader osalReader = new OSaLReader(validate);
			bool bRead = false;
			if(isFile){
				bRead = osalReader.readFile(osal);
			}
			else{
				bRead = osalReader.readString(osal);			
			}
			if(!bRead) throw new Exception("OSaL string not valid");
			return osalReader.getOSAnalysis();
   		}//readOSaL
	   
		/// <summary>
		/// write the OSAnalysis to an osal xml string. 
		/// @throws Exception if there are errors in writing the osal string. 
		/// </summary>
		/// <returns>the osal xml string. </returns>
   		public string writeOSaL(){
			OSaLWriter osalWriter = new OSaLWriter();
			osalWriter.setOSAnalysis(this);
			return osalWriter.writeToString();
   		}//writeOSaL

		/// <summary>
		/// Get analysis status
		/// </summary>
		/// <returns>analysis status.</returns>
		public AnalysisStatus getAnalysisStatus(){		
			return analysisHeader.status;
		}//getAnalysisStatus
		
		/// <summary>
		/// Set analysis status
		/// </summary>
		/// <param name="status">holds the analysis status.</param>
		/// <returns>whether the analysis status is set successfully. </returns>
		public bool setAnalysisStatus(AnalysisStatus status){
			analysisHeader.status = status;
			return true;
		}//setAnalysisStatus

		/// <summary>
		/// Get service URI. 
		/// </summary>
		/// <returns>the service URI, null or empty string if none. </returns>
		public string getServiceURI(){
			return analysisHeader.serviceURI;
		}//getServiceURI

		/// <summary>
		/// Set service URI.
		/// </summary>
		/// <param name="serviceURI">holds the service URI. </param>
		/// <returns>whether the service URI is set successfully.</returns>
		public bool setServiceURI(string serviceURI){
			analysisHeader.serviceURI = serviceURI;
			return true;
		}//setServiceURI

		/// <summary>
		/// Get service name. 
		/// </summary>
		/// <returns>the service name, null or empty string if none. </returns>
		public string getServiceName(){
			return analysisHeader.serviceName;
		}//getServiceName

		/// <summary>
		/// Set service name. 
		/// </summary>
		/// <param name="serviceName">serviceName holds the service name. </param>
		/// <returns>whether the service name is set successfully.</returns>
		public bool setServiceName(string serviceName){
			analysisHeader.serviceName = serviceName;
			return true;
		}//setServiceName

		/// <summary>
		/// Get instance name. 
		/// </summary>
		/// <returns>the instance name, null or empty string if none.</returns>
		public string getInstanceName(){
			return analysisHeader.instanceName;
		}//getInstanceName

		/// <summary>
		/// Set instance name. 
		/// </summary>
		/// <param name="instanceName">holds the instance name. </param>
		/// <returns>whether the instance name is set successfully.</returns>
		public bool setInstanceName(string instanceName){
			analysisHeader.instanceName = instanceName;
			return true;
		}//setInstanceName

		/// <summary>
		/// Get job ID. 
		/// </summary>
		/// <returns>the job ID, null or empty string if none. </returns>
		public string getJobID(){
			return analysisHeader.jobID;
		}//getJobID
	
		/// <summary>
		/// Set jobID.
		/// </summary>
		/// <param name="jobID">holds the jobID.</param>
		/// <returns>whether the jobID is set successfully.</returns>
		public bool setJobID(string jobID){
			analysisHeader.jobID = jobID;
			return true;
		}//setJobID

		/// <summary>
		/// Get analysis time. 
		/// </summary>
		/// <returns>the analysis time, null or empty string if none. </returns>
		public DateTime getAnalysisTime(){
			return analysisHeader.time;
		}//getAnalysisTime

		/// <summary>
		/// Set analysis time. 
		/// </summary>
		/// <param name="time">holds the analysis time. </param>
		/// <returns>whether the analysis time is set successfully.</returns>
		public bool setAnalysisTime(DateTime time){
			analysisHeader.time = time;
			return true;
		}//setAnalysisTime

		/// <summary>
		/// Get analysis message. 
		/// </summary>
		/// <returns>the analysis message, null or empty string if none.</returns>
		public string getAnalysisMessage(){
			return analysisHeader.message;
		}//getAnalysisMessage

		/// <summary>
		/// Set analysis message. 
		/// </summary>
		/// <param name="message">holds the analysis message. </param>
		/// <returns>whether the analysis message is set successfully.</returns>
		public bool setAnalysisMessage(String message){
			analysisHeader.message = message;
			return true;
		}//setAnalysisMessage

		/// <summary>
		/// Get variable number. 
		/// </summary>
		/// <returns> variable number, -1 if no information. </returns>
		public int getVariableNumber(){
			if(m_iVariableNumber == -1){
				if(analysisData == null) return -1;
				m_iVariableNumber = analysisData.numberOfVariables;
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
				return false;
			}
			if(analysisData == null) analysisData = new AnalysisData();
			m_iVariableNumber = variableNumber;
			analysisData.numberOfVariables = variableNumber;
			return true;
		}//setVariableNumber

		/// <summary>
		/// Get objective number. 
		/// </summary>
		/// <returns> objective number, -1 if no information. </returns>
		public int getObjectiveNumber(){
			if(m_iObjectiveNumber == -1){
				if(analysisData == null) return -1;
				m_iObjectiveNumber = analysisData.numberOfObjectives;
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
				return false;
			}
			if(analysisData == null) analysisData = new AnalysisData();
			m_iObjectiveNumber = objectiveNumber;
			analysisData.numberOfObjectives = objectiveNumber;
			return true;
		}//setObjectiveNumber
	
		/// <summary>
		/// Get constraint number. 
		/// </summary>
		/// <returns> constraint number, -1 if no information. </returns>
		public int getConstraintNumber(){
			if(m_iConstraintNumber == -1){
				if(analysisData == null) return -1;
				m_iConstraintNumber = analysisData.numberOfConstraints;
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
				return false;
			}
			if(analysisData == null) analysisData = new AnalysisData();
			m_iConstraintNumber = constraintNumber;
			analysisData.numberOfConstraints = constraintNumber;
			return true;
		}//setConstraintNumber

		/// <summary>
		/// get analysis of the entire instance. 
		/// </summary>
		/// <returns>InstanceAnalysis</returns>
		public InstanceAnalysis getInstanceAnalysis(){
			return analysisData.instance;
		}//getInstanceAnalysis

		/// <summary>
		/// Set analysis of the entire instance.
		/// Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
		/// methods have to be called first. 	    
		/// @see #setVariableNumber(int)
	    /// @see #setObjectiveNumber(int)
	    /// @see #setConstraintNumber(int)
		/// </summary>
		/// <param name="instanceAnalysis">holds the analysis of the entire instance.</param>
		/// <returns>whether the instanceAnalysis is set successfully.</returns>
		public bool setInstanceAnalysis(InstanceAnalysis instanceAnalysis){
			if(m_iVariableNumber < 0 || m_iObjectiveNumber < 0 || m_iConstraintNumber < 0) return false;
			analysisData.instance = instanceAnalysis;
			return true;
		}//setInstanceAnalysis

		/// <summary>
		/// get analysis of the variables 
		/// </summary>
		/// <returns>VariableAnalysis</returns>
		public VariableAnalysis getVariableAnalysis(){
			return analysisData.variables;
		}//getVariableAnalysis

		/// <summary>
		/// Set analysis of the variables. 
		/// Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
		/// methods have to be called first. 	    
		/// @see #setVariableNumber(int)
		/// @see #setObjectiveNumber(int)
		/// @see #setConstraintNumber(int)
		/// </summary>
		/// <param name="variableAnalysis">holds the analysis of the variables.</param>
		/// <returns>whether the variableAnalysis is set successfully.</returns>
		public bool setVariableAnalysis(VariableAnalysis variableAnalysis){
			if(m_iVariableNumber < 0 || m_iObjectiveNumber < 0 || m_iConstraintNumber < 0) return false;
			analysisData.variables = variableAnalysis;
			return true;
		}//setVariableAnalysis

		/// <summary>
		/// get analysis of the objectives. 
		/// </summary>
		/// <returns>ObjectiveAnalysis</returns>
		public ObjectiveAnalysis getObjectiveAnalysis(){
			return analysisData.objectives;
		}//getObjectiveAnalysis

		/// <summary>
		/// Set analysis of the objectives.
		/// Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
		/// methods have to be called first. 	    
		/// @see #setVariableNumber(int)
		/// @see #setObjectiveNumber(int)
		/// @see #setConstraintNumber(int)
		/// </summary>
		/// <param name="objectiveAnalysis">holds the analysis of the objectives.</param>
		/// <returns>whether the objectiveAnalysis is set successfully.</returns>
		public bool setObjectiveAnalysis(ObjectiveAnalysis objectiveAnalysis){
			if(m_iVariableNumber < 0 || m_iObjectiveNumber < 0 || m_iConstraintNumber < 0) return false;
			analysisData.objectives = objectiveAnalysis;
			return true;
		}//setObjectiveAnalysis

		/// <summary>
		/// get analysis of the constraints. 
		/// </summary>
		/// <returns>ConstraintAnalysis</returns>
		public ConstraintAnalysis getConstraintAnalysis(){
			return analysisData.constraints;
		}//getConstraintAnalysis
	
		/// <summary>
		/// Set analysis of the constraints.
		/// Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
		/// methods have to be called first. 	    
		/// @see #setVariableNumber(int)
		/// @see #setObjectiveNumber(int)
		/// @see #setConstraintNumber(int)
		/// </summary>
		/// <param name="constraintAnalysis">holds the analysis of the constraints.</param>
		/// <returns>whether the constraintAnalysis is set successfully.</returns>
		public bool setConstraintAnalysis(ConstraintAnalysis constraintAnalysis){
			if(m_iVariableNumber < 0 || m_iObjectiveNumber < 0 || m_iConstraintNumber < 0) return false;
			analysisData.constraints = constraintAnalysis;
			return true;
		}//setConstraintAnalysis

		/// <summary>
		/// get analysis of the linear constraint coefficients. 
		/// </summary>
		/// <returns>LinearConstraintCoefficientAnalysis</returns>
		public LinearConstraintCoefficientAnalysis getLinearConstraintCoefficientAnalysis(){
			return analysisData.linearConstraintCoefficients;
		}//getLinearConstraintCoefficientsAnalysis

		/// <summary>
		/// Set analysis of the linear constraint coefficients. 
		/// Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
		/// methods have to be called first. 	    
		/// @see #setVariableNumber(int)
		/// @see #setObjectiveNumber(int)
		/// @see #setConstraintNumber(int)
		/// </summary>
		/// <param name="linearConstraintCoefficientAnalysis">holds the analysis of the linear constraint coefficients.</param>
		/// <returns>whether the linearConstraintCoefficientAnalysis is set successfully.</returns>
		public bool setLinearConstraintCoefficientAnalysis(LinearConstraintCoefficientAnalysis linearConstraintCoefficientAnalysis){
			if(m_iVariableNumber < 0 || m_iObjectiveNumber < 0 || m_iConstraintNumber < 0) return false;
			analysisData.linearConstraintCoefficients = linearConstraintCoefficientAnalysis;
			return true;
		}//setLinearConstraintCoefficientAnalysis

		/// <summary>
		/// get analysis of the entire quadratic coefficients. 
		/// </summary>
		/// <returns>QuadraticCoefficientAnalysis</returns>
		public QuadraticCoefficientAnalysis getQuadraticCoefficientAnalysis(){
			return analysisData.quadraticCoefficients;
		}//getQuadraticCoefficientsAnalysis

		/// <summary>
		/// Set analysis of the entire quadratic coefficients.
		/// Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
		/// methods have to be called first. 	    
		/// @see #setVariableNumber(int)
		/// @see #setObjectiveNumber(int)
		/// @see #setConstraintNumber(int)
		/// </summary>
		/// <param name="quadraticCoefficientAnalysis">holds the analysis of the entire quadratic coefficients.</param>
		/// <returns>whether the quadraticCoefficientAnalysis is set successfully.</returns>
		public bool setQuadraticCoefficientAnalysis(QuadraticCoefficientAnalysis quadraticCoefficientAnalysis){
			if(m_iVariableNumber < 0 || m_iObjectiveNumber < 0 || m_iConstraintNumber < 0) return false;
			analysisData.quadraticCoefficients = quadraticCoefficientAnalysis;
			return true;
		}//setQuadraticCoefficientAnalysis

		/// <summary>
		/// get analysis of the entire nonlinear expressions. 
		/// </summary>
		/// <returns>NonlinearExpressions</returns>
		public NonlinearExpressionAnalysis getNonlinearExpressionAnalysis(){
			return analysisData.nonlinearExpressions;
		}//getNonlinearExpressionAnalysis

		/// <summary>
		/// Set analysis of the entire nonlinear expressions.
		/// Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
		/// methods have to be called first. 	    
		/// @see #setVariableNumber(int)
		/// @see #setObjectiveNumber(int)
		/// @see #setConstraintNumber(int)
		/// </summary>
		/// <param name="nonlinearExpressionAnalysis">holds the analysis of the entire nonlinear expressions.</param>
		/// <returns>whether the nonlinearExpressionAnalysis is set successfully.</returns>
		public bool setNonlinearExpressionAnalysis(NonlinearExpressionAnalysis nonlinearExpressionAnalysis){
			if(m_iVariableNumber < 0 || m_iObjectiveNumber < 0 || m_iConstraintNumber < 0) return false;
			analysisData.nonlinearExpressions = nonlinearExpressionAnalysis;
			return true;
		}//setNonlinearExpressionAnalysis

		/// <summary>
		/// get a string array of names of other analyses. 
		/// </summary>
		/// <returns>a string array of names of other analyses, null if no other analyses.  </returns>
		public string[] getOtherAnalysisNames(){
			if(analysisData.other == null) return null;
			int n = analysisData.other.Length;
			if(n <= 0) return null;
			string[] otherAnalysisNames = new String[n];
			for(int i = 0; i < n; i++){
				otherAnalysisNames[i] = analysisData.other[i].name;
			}
			return otherAnalysisNames;
		}//getOtherAnalysisNames

		/// <summary>
		/// get a hashmap of other analysis descriptions. 
		/// The keys of the hashmap are the analysis names, and 
		/// the values of the hashmap are the analysis descriptions.  
		/// </summary>
		/// <returns>a hashmap of other analysis descriptions, null if no other analyses. </returns>
		public Hashtable getOtherAnalysisDescriptions(){
			if(analysisData.other == null) return null;
			int n = analysisData.other.Length;
			if(n <= 0) return null;
			Hashtable otherAnalysisDescriptions = new Hashtable();
			for(int i = 0; i < n; i++){
				otherAnalysisDescriptions.Add(analysisData.other[i].name, analysisData.other[i].description);
			}
			return otherAnalysisDescriptions;
		}//getOtherAnalysisDescriptions

		/// <summary>
		/// get a hashmap of other analysis values. 
		/// The keys of the hashmap are the analysis names, and 
		/// the values of the hashmap are the analysis values.  
		/// </summary>
		/// <returns>a hashmap of other analysis values, null if no other analyses. </returns>
		public Hashtable  getOtherAnalysisValues(){
			if(analysisData.other == null) return null;
			int n = analysisData.other.Length;
			if(n <= 0) return null;
			Hashtable otherAnalysisValues = new Hashtable();
			for(int i = 0; i < n; i++){
				otherAnalysisValues.Add(analysisData.other[i].name, analysisData.other[i].value);
			}
			return otherAnalysisValues;
		}//getOtherAnalysisValues

		/// <summary>
		/// set other analyses, with their names (required), descriptions (optional) and values (optional). 
		/// Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
		/// methods have to be called first. 	    
		/// @see #setVariableNumber(int)
		/// @see #setObjectiveNumber(int)
		/// @see #setConstraintNumber(int)
		/// </summary>
		/// <param name="names">holds the names of the other analyses; it is required.  </param>
		/// <param name="descriptions">holds the descriptions of the other analyses; null if none. </param>
		/// <param name="values">holds the values of the other analyses; null if none. </param>
		/// <returns>whether the other anlysis information is set successfully. </returns>
		public bool setOtherAnalyses(string[] names, string[] descriptions, string[] values){
			if(m_iVariableNumber < 0 || m_iObjectiveNumber < 0 || m_iConstraintNumber < 0) return false;
			if(names == null) return false;
			if(descriptions != null && descriptions.Length != names.Length) return false;
			if(values != null && values.Length != names.Length) return false;
			int n = names.Length;
			analysisData.other = new OtherAnalysis[n];
			for(int i = 0; i < n; i++){
				analysisData.other[i] = new OtherAnalysis();
			}
			for(int i = 0; i < n; i++){
				analysisData.other[i].name = names[i];
			}
			if(descriptions != null){
				for(int i = 0; i < n; i++){
					analysisData.other[i].description = descriptions[i];
				}	
			}
			if(values != null){
				for(int i = 0; i < n; i++){
					analysisData.other[i].value = values[i];
				}	
			}
			return true;
		}//setOtherAnalyses

	}//class OSAnalysis
}//namespace
