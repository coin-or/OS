using System;

namespace org.optimizationservices.oscommon.datastructure.osanalysis{
	/// <summary>
	/// A data structure class that corresponds to an xml element in the OSaL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class AnalysisData{

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

	}//class AnalysisData
}//namespace
