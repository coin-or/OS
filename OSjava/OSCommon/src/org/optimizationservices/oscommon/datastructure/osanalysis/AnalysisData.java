/**
 * @(#)AnalysisData 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.datastructure.osanalysis;

/**
*
* <p>A data structure class that corresponds to an xml element in the OSaL schema.  
*  
* </p>
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2004
* @since OS 1.0
*/
public class AnalysisData {

	public int numberOfVariables = -1;
	
	public int numberOfObjectives = -1;

    public int numberOfConstraints = -1;
    
	public InstanceAnalysis instance = null;
	
	public VariableAnalysis variables = null;
	
	public ObjectiveAnalysis objectives = null;
	
	public ConstraintAnalysis constraints = null;
	
	public LinearConstraintCoefficientAnalysis linearConstraintCoefficients  = null;
	
	public QuadraticCoefficientAnalysis quadraticCoefficients = null;
	
	public NonlinearExpressionAnalysis nonlinearExpressions = null;
	
	public SemidefiniteBlockAnalysis semidefiniteBlocks = null;
	
	public ConeAnalysis cones = null;
	
	public DisjunctiveInformationAnalysis disjunctiveInformation = null;
	
	public StageAnalysis stages = null;
	
	public StochasticInformationAnalysis stochasticInformation = null;
	
	public UserFunctionAnalysis userFunctions = null;
	
	public SimulationAnalysis simulations = null;
	
	public RealTimeDataAnalysis realTimeData = null;
	
	public XMLDataAnalysis xmlData = null;
	
	public OtherAnalysis[] other = null;
	
	
}//AnalysisData
