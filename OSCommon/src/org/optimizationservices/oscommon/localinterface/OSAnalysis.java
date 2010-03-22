/**
 * @(#)OSAnalysis 1.0 03/14/2005
 *
 * Copyright (c) 2005 
 */
package org.optimizationservices.oscommon.localinterface;

import java.util.GregorianCalendar;
import java.util.Hashtable;

import org.optimizationservices.oscommon.datastructure.osanalysis.AnalysisData;
import org.optimizationservices.oscommon.datastructure.osanalysis.AnalysisHeader;
import org.optimizationservices.oscommon.datastructure.osanalysis.AnalysisStatus;
import org.optimizationservices.oscommon.datastructure.osanalysis.ConstraintAnalysis;
import org.optimizationservices.oscommon.datastructure.osanalysis.InstanceAnalysis;
import org.optimizationservices.oscommon.datastructure.osanalysis.LinearConstraintCoefficientAnalysis;
import org.optimizationservices.oscommon.datastructure.osanalysis.NonlinearExpressionAnalysis;
import org.optimizationservices.oscommon.datastructure.osanalysis.ObjectiveAnalysis;
import org.optimizationservices.oscommon.datastructure.osanalysis.OtherAnalysis;
import org.optimizationservices.oscommon.datastructure.osanalysis.QuadraticCoefficientAnalysis;
import org.optimizationservices.oscommon.datastructure.osanalysis.VariableAnalysis;
import org.optimizationservices.oscommon.representationparser.OSaLReader;
import org.optimizationservices.oscommon.representationparser.OSaLWriter;

/**
*
* <P>The <code>OSAnalysis</code> class is a local interface for storing Optimization Services
* problem analysis. Its design follows the Optimization Services analysis Language (OSaL). 
* All the data structures in this class are standards specified in OSaL. 
* Developers can add service-specific analyses by extending this class.  
*
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2005
* @see org.optimizationservices.oscommon.localinterface.OSInstance
* @see org.optimizationservices.oscommon.localinterface.OSResult
* @see org.optimizationservices.oscommon.localinterface.OSOption
* @since OS 1.0
*/
public class OSAnalysis {
	
	/**
	 * analysisHeader holds the first child of the OSAnalysis specified by the OSaL Schema. 
	 */
	public AnalysisHeader analysisHeader = new AnalysisHeader();

	/**
	 * analysisData holds the second child of the OSAnalysis specified by the OSaL Schema. 
	 */
	public AnalysisData analysisData = new AnalysisData();

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
	 *
	 * Default constructor. 
	 */
	public OSAnalysis(){
	}//constructor
	
	/**
	 * read an OSaL instance and return and OSAnalysis object.  
	 * 
	 * @param osal holds the optimization analysis in a string which format follows the
	 * Optimization Services analysis Language (OSaL) schema.
	 * @param isFile holds whether the osal string is a file name or a string that literally holds the osal contents.  
	 * @param validate holds whether the reader should be validating against the schema or not.
	 * @return the OSAnalysis object constructed from the OSaL String.  
	 * @throws Exception if there are errors in reading the string or setting the OSAnalyis. 
	 */
   	public OSAnalysis readOSaL(String osal, boolean isFile, boolean validate) throws Exception{
   		OSaLReader osalReader = new OSaLReader(validate);
		boolean bRead = false;
		if(isFile){
			bRead = osalReader.readFile(osal);
		}
		else{
			bRead = osalReader.readString(osal);			
		}
		if(!bRead) throw new Exception("OSaL string not valid");
		return osalReader.getOSAnalysis();
   	}//readOSaL
   	
   	/**
   	 * write the OSAnalysis to an osal xml string. 
   	 * 
   	 * @return the osal xml string. 
	 * @throws Exception if there are errors in writing the osal string. 
   	 */
   	public String writeOSaL() throws Exception{
		OSaLWriter osalWriter = new OSaLWriter();
		osalWriter.setOSAnalysis(this);
		return osalWriter.writeToString();
   	}//writeOSaL

   	/**
	 * Get analysis status
	 * 
	 * @return analysis status. 
	 */
	public AnalysisStatus getAnalysisStatus(){
		return analysisHeader.status;
	}//getAnalysisStatus

   	/**
	 * Set analysis status
	 * 
	 * @param status holds the analysis status.
	 * @return whether the analysis status is set successfully. 
	 */
	public boolean setAnalysisStatus(AnalysisStatus status){
		analysisHeader.status = status;
		return true;
	}//setAnalysisStatus

	/**
	 * Get service URI. 
	 * 
	 * @return the service URI, null or empty string if none. 
	 */
	public String getServiceURI(){
		return analysisHeader.serviceURI;
	}//getServiceURI
	
	/**
	 * Set service URI. 
	 * 
	 * @param serviceURI holds the service URI. 
	 * @return whether the service URI is set successfully.
	 */
	public boolean setServiceURI(String serviceURI){
		analysisHeader.serviceURI = serviceURI;
		return true;
	}//setServiceURI

	/**
	 * Get service name. 
	 * 
	 * @return the service name, null or empty string if none. 
	 */
	public String getServiceName(){
		return analysisHeader.serviceName;
	}//getServiceName
	
	/**
	 * Set service name. 
	 * 
	 * @param serviceName holds the service name. 
	 * @return whether the service name is set successfully.
	 */
	public boolean setServiceName(String serviceName){
		analysisHeader.serviceName = serviceName;
		return true;
	}//setServiceName

	/**
	 * Get instance name. 
	 * 
	 * @return the instance name, null or empty string if none. 
	 */
	public String getInstanceName(){
		return analysisHeader.instanceName;
	}//getInstanceName
	
	/**
	 * Set instance name. 
	 * 
	 * @param instanceName holds the instance name. 
	 * @return whether the instance name is set successfully.
	 */
	public boolean setInstanceName(String instanceName){
		analysisHeader.instanceName = instanceName;
		return true;
	}//setInstanceName
	
	/**
	 * Get job ID. 
	 * 
	 * @return the job ID, null or empty string if none. 
	 */
	public String getJobID(){
		return analysisHeader.jobID;
	}//getJobID
	
	/**
	 * Set jobID.
	 * 
	 * @param jobID holds the jobID.
	 * @return whether the jobID is set successfully.
	 */
	public boolean setJobID(String jobID){
		analysisHeader.jobID = jobID;
		return true;
	}//setJobID

	
	/**
	 * Get analysis time. 
	 * 
	 * @return the analysis time, null or empty string if none. 
	 */
	public GregorianCalendar getAnalysisTime(){
		return analysisHeader.time;
	}//getAnalysisTime
	
	/**
	 * Set analysis time. 
	 * 
	 * @param time holds the analysis time. 
	 * @return whether the analysis time is set successfully.
	 */
	public boolean setAnalysisTime(GregorianCalendar time){
		analysisHeader.time = time;
		return true;
	}//setAnalysisTime

	/**
	 * Get analysis message. 
	 * 
	 * @return the analysis message, null or empty string if none. 
	 */
	public String getAnalysisMessage(){
		return analysisHeader.message;
	}//getAnalysisMessage
	
	/**
	 * Set analysis message. 
	 * 
	 * @param message holds the analysis message. 
	 * @return whether the analysis message is set successfully.
	 */
	public boolean setAnalysisMessage(String message){
		analysisHeader.message = message;
		return true;
	}//setAnalysisMessage

	/**
	 * Get variable number. 
	 * 
	 * @return variable number, -1 if no information. 
	 */
	public int getVariableNumber(){
		if(m_iVariableNumber == -1){
			if(analysisData == null) return -1;
			m_iVariableNumber = analysisData.numberOfVariables;
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
			return false;
		}
		if(analysisData == null) analysisData = new AnalysisData();
		m_iVariableNumber = variableNumber;
		analysisData.numberOfVariables = variableNumber;
		return true;
	}//setVariableNumber
	
	/**
	 * Get objective number. 
	 * 
	 * @return objective number, -1 if no information. 
	 */
	public int getObjectiveNumber(){
		if(m_iObjectiveNumber == -1){
			if(analysisData == null) return -1;
			m_iObjectiveNumber = analysisData.numberOfObjectives;
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
			return false;
		}
		if(analysisData == null) analysisData = new AnalysisData();
		m_iObjectiveNumber = objectiveNumber;
		analysisData.numberOfObjectives = objectiveNumber;
		return true;
	}//setObjectiveNumber
	
	/**
	 * Get constraint number. 
	 * 
	 * @return constraint number, -1 if no information. 
	 */
	public int getConstraintNumber(){
		if(m_iConstraintNumber == -1){
			if(analysisData == null) return -1;
			m_iConstraintNumber = analysisData.numberOfConstraints;
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
			return false;
		}
		if(analysisData == null) analysisData = new AnalysisData();
		m_iConstraintNumber = constraintNumber;
		analysisData.numberOfConstraints = constraintNumber;
		return true;
	}//setConstraintNumber
	
	/**
	 * get analysis of the entire instance. 
	 * @return InstanceAnalysis
	 */
	public InstanceAnalysis getInstanceAnalysis(){
		return analysisData.instance;
	}//getInstanceAnalysis

	/**
	 * Set analysis of the entire instance.
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods have to be called first. 
	 * @param instanceAnalysis holds the analysis of the entire instance.
	 * @return whether the instanceAnalysis is set successfully.
	 * @see #setVariableNumber(int)
	 * @see #setObjectiveNumber(int)
	 * @see #setConstraintNumber(int)
	 */
	public boolean setInstanceAnalysis(InstanceAnalysis instanceAnalysis){
		if(m_iVariableNumber < 0 || m_iObjectiveNumber < 0 || m_iConstraintNumber < 0) return false;
		analysisData.instance = instanceAnalysis;
		return true;
	}//setInstanceAnalysis

	/**
	 * get analysis of the variables 
	 * 
	 * @return VariableAnalysis
	 */
	public VariableAnalysis getVariableAnalysis(){
		return analysisData.variables;
	}//getVariableAnalysis
	
	/**
	 * Set analysis of the variables.
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods have to be called first. 
	 * 
	 * @param variableAnalysis holds the analysis of the variables.
	 * @return whether the variableAnalysis is set successfully.
	 * @see #setVariableNumber(int)
	 * @see #setObjectiveNumber(int)
	 * @see #setConstraintNumber(int)
	 */
	public boolean setVariableAnalysis(VariableAnalysis variableAnalysis){
		if(m_iVariableNumber < 0 || m_iObjectiveNumber < 0 || m_iConstraintNumber < 0) return false;
		analysisData.variables = variableAnalysis;
		return true;
	}//setVariableAnalysis

	/**
	 * get analysis of the objectives. 
	 * 
	 * @return ObjectiveAnalysis
	 */
	public ObjectiveAnalysis getObjectiveAnalysis(){
		return analysisData.objectives;
	}//getObjectiveAnalysis
	
	/**
	 * Set analysis of the objectives.
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods have to be called first. 
	 * 
	 * @param objectiveAnalysis holds the analysis of the objectives.
	 * @return whether the objectiveAnalysis is set successfully.
	 * @see #setVariableNumber(int)
	 * @see #setObjectiveNumber(int)
	 * @see #setConstraintNumber(int)
	 */
	public boolean setObjectiveAnalysis(ObjectiveAnalysis objectiveAnalysis){
		if(m_iVariableNumber < 0 || m_iObjectiveNumber < 0 || m_iConstraintNumber < 0) return false;
		analysisData.objectives = objectiveAnalysis;
		return true;
	}//setObjectiveAnalysis
	
	/**
	 * get analysis of the constraints. 
	 * @return ConstraintAnalysis
	 */
	public ConstraintAnalysis getConstraintAnalysis(){
		return analysisData.constraints;
	}//getConstraintAnalysis
	
	/**
	 * Set analysis of the constraints.
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods have to be called first. 
	 * 
	 * @param constraintAnalysis holds the analysis of the constraints.
	 * @return whether the constraintAnalysis is set successfully.
	 * @see #setVariableNumber(int)
	 * @see #setObjectiveNumber(int)
	 * @see #setConstraintNumber(int)
	 */
	public boolean setConstraintAnalysis(ConstraintAnalysis constraintAnalysis){
		if(m_iVariableNumber < 0 || m_iObjectiveNumber < 0 || m_iConstraintNumber < 0) return false;
		analysisData.constraints = constraintAnalysis;
		return true;
	}//setConstraintAnalysis
	
	/**
	 * get analysis of the linear constraint coefficients. 
	 * @return LinearConstraintCoefficientAnalysis
	 */
	public LinearConstraintCoefficientAnalysis getLinearConstraintCoefficientAnalysis(){
		return analysisData.linearConstraintCoefficients;
	}//getLinearConstraintCoefficientsAnalysis

	/**
	 * Set analysis of the linear constraint coefficients. 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods have to be called first. 
	 * 
	 * @param linearConstraintCoefficients holds the analysis of the linear constraint coefficients. 
	 * @return whether the linearConstraintCoefficientAnalysis is set successfully.
	 * @see #setVariableNumber(int)
	 * @see #setObjectiveNumber(int)
	 * @see #setConstraintNumber(int)
	 */
	public boolean setLinearConstraintCoefficientAnalysis(LinearConstraintCoefficientAnalysis linearConstraintCoefficientAnalysis){
		if(m_iVariableNumber < 0 || m_iObjectiveNumber < 0 || m_iConstraintNumber < 0) return false;
		analysisData.linearConstraintCoefficients = linearConstraintCoefficientAnalysis;
		return true;
	}//setLinearConstraintCoefficientAnalysis
	
	/**
	 * get analysis of the entire quadratic coefficients. 
	 * @return QuadraticCoefficientAnalysis
	 */
	public QuadraticCoefficientAnalysis getQuadraticCoefficientAnalysis(){
		return analysisData.quadraticCoefficients;
	}//getQuadraticCoefficientsAnalysis

	/**
	 * Set analysis of the entire quadratic coefficients.
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods have to be called first. 
	 * 
	 * @param quadraticCoefficientAnalysis holds the analysis of the entire quadratic coefficients.
	 * @return whether the quadraticCoefficientAnalysis is set successfully.
	 * @see #setVariableNumber(int)
	 * @see #setObjectiveNumber(int)
	 * @see #setConstraintNumber(int)
	 */
	public boolean setQuadraticCoefficientAnalysis(QuadraticCoefficientAnalysis quadraticCoefficientAnalysis){
		if(m_iVariableNumber < 0 || m_iObjectiveNumber < 0 || m_iConstraintNumber < 0) return false;
		analysisData.quadraticCoefficients = quadraticCoefficientAnalysis;
		return true;
	}//setQuadraticCoefficientAnalysis
	
	/**
	 * get analysis of the entire nonlinear expressions. 
	 * @return NonlinearExpressions
	 */
	public NonlinearExpressionAnalysis getNonlinearExpressionAnalysis(){
		return analysisData.nonlinearExpressions;
	}//getNonlinearExpressionAnalysis

	/**
	 * Set analysis of the entire nonlinear expressions.
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods have to be called first. 
	 * 
	 * @param nonlinearExpressionAnalysis holds the analysis of the entire nonlinear expressions.
	 * @return whether the nonlinearExpressionAnalysis is set successfully.
	 * @see #setVariableNumber(int)
	 * @see #setObjectiveNumber(int)
	 * @see #setConstraintNumber(int)
	 */
	public boolean setNonlinearExpressionAnalysis(NonlinearExpressionAnalysis nonlinearExpressionAnalysis){
		if(m_iVariableNumber < 0 || m_iObjectiveNumber < 0 || m_iConstraintNumber < 0) return false;
		analysisData.nonlinearExpressions = nonlinearExpressionAnalysis;
		return true;
	}//setNonlinearExpressionAnalysis
	
	/**
	 * get a string array of names of other analyses. 
	 * 
	 * @return a string array of names of other analyses, null if no other analyses.  
	 */
	public String[] getOtherAnalysisNames(){
		if(analysisData.other == null) return null;
		int n = analysisData.other.length;
		if(n <= 0) return null;
		String[] otherAnalysisNames = new String[n];
		for(int i = 0; i < n; i++){
			otherAnalysisNames[i] = analysisData.other[i].name;
		}
		return otherAnalysisNames;
	}//getOtherAnalysisNames
	
	/**
	 * get a hashmap of other analysis descriptions. 
	 * The keys of the hashmap are the analysis names, and 
	 * the values of the hashmap are the analysis descriptions.  
	 * 
	 * @return a hashmap of other analysis descriptions, null if no other analyses. 
	 */
	public Hashtable<String, String>  getOtherAnalysisDescriptions(){
		if(analysisData.other == null) return null;
		int n = analysisData.other.length;
		if(n <= 0) return null;
		Hashtable<String, String> otherAnalysisDescriptions = new Hashtable<String, String>();
		for(int i = 0; i < n; i++){
			otherAnalysisDescriptions.put(analysisData.other[i].name, analysisData.other[i].description);
		}
		return otherAnalysisDescriptions;
	}//getOtherAnalysisDescriptions
	
	/**
	 * get a hashmap of other analysis values. 
	 * The keys of the hashmap are the analysis names, and 
	 * the values of the hashmap are the analysis values.  
	 * 
	 * @return a hashmap of other analysis values, null if no other analyses. 
	 */
	public Hashtable<String, String>  getOtherAnalysisValues(){
		if(analysisData.other == null) return null;
		int n = analysisData.other.length;
		if(n <= 0) return null;
		Hashtable<String, String> otherAnalysisValues = new Hashtable<String, String>();
		for(int i = 0; i < n; i++){
			otherAnalysisValues.put(analysisData.other[i].name, analysisData.other[i].value);
		}
		return otherAnalysisValues;
	}//getOtherAnalysisValues

	/**
	 * set other analyses, with their names (required), descriptions (optional) and values (optional). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods have to be called first. 
	 * 
	 * @param names holds the names of the other analyses; it is required.  
	 * @param descriptions holds the descriptions of the other analyses; null if none. 
	 * @param values holds the values of the other analyses; null if none. 
	 * @return whether the other anlysis information is set successfully. 
	 * @see #setVariableNumber(int)
	 * @see #setObjectiveNumber(int)
	 * @see #setConstraintNumber(int)
	 */
	public boolean setOtherAnalyses(String[] names, String[] descriptions, String[] values){
		if(m_iVariableNumber < 0 || m_iObjectiveNumber < 0 || m_iConstraintNumber < 0) return false;
		if(names == null) return false;
		if(descriptions != null && descriptions.length != names.length) return false;
		if(values != null && values.length != names.length) return false;
		int n = names.length;
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
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] args){
		
	}//main
}//class OSAnalysis
