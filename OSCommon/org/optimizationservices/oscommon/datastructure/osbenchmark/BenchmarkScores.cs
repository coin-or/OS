using System;

namespace org.optimizationservices.oscommon.datastructure.osbenchmark{
	/// <summary>
	/// A data structure class that corresponds to an xml element in the OSbL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class BenchmarkScores{

		public double overall = Double.NaN;
	
		public double expertAssessment = Double.NaN;
	
		public double userAssessment = Double.NaN;
	
		public double reputation = Double.NaN;
	
		public double popularity = Double.NaN;
	
		public double owner = Double.NaN;
	
		public double support = Double.NaN;
	
		public double system = Double.NaN;
	
		public double service = Double.NaN;
	
		public double computation = Double.NaN;

	}//class BenchmarkScores
}//namespace
