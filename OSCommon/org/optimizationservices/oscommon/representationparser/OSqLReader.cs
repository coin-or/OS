using System;
using System.Collections;
using System.Xml;

using org.optimizationservices.oscommon.util;
using org.optimizationservices.oscommon.localinterface;
using org.optimizationservices.oscommon.datastructure.osquery;
using org.optimizationservices.oscommon.datastructure.osentity;

namespace org.optimizationservices.oscommon.representationparser{
	///	<summary>
	///	The	<c>OSqLReader</c> class	parses an OSqL instance	into a DOM tree	and
	///	provides a set of "get"	methods	that can be	
	///	used to	retrieve different pieces of information of	the	instance.
	///	@author	Jun	Ma	
	///	@version 1.0, 09/01/2005
	///	@since OS 1.0
	///	@copyright (c) 2005
	///	</summary>
	public class OSqLReader	: OSgLReader{
		/// <summary>
		/// m_osQuery holds the standard OSQuery, which is a local interface for 
		/// storing Optimization Services query. 
		/// </summary>
		protected OSQuery m_osQuery = null;
	
		///	<summary>
		///	constructor.
		///	</summary>
		///	<param name="validate">holds whether the reader	should be validating against the schema	or not.</param>
		public OSqLReader(bool validate){
			m_bXsdValidate = validate;
		}//constructor

		///	<summary>
		///	Default	constructor. 
		///	</summary>
		public OSqLReader(){
	
		}//constructor
	
		/// <summary>
		/// get the standard OSQuery, a local interface for 
		/// storing Optimization Services query.
		/// </summary>
		/// <returns>the OSQuery. </returns>
		public OSQuery getOSQuery(){
			if(m_osQuery != null){
				return m_osQuery;
			}
			m_osQuery = new OSQuery();
			StandardQuery standardQuery = getStandardQuery();
			String sXQuery = getXQuery();
			if(standardQuery != null){
				if(!m_osQuery.setStandardQuery(standardQuery)) throw new Exception("setStandardQuery Unsuccessful");
			}
			else if(sXQuery != null && sXQuery.Length > 0){
				if(!m_osQuery.setXQuery(sXQuery)) throw new Exception("setXQuery Unsuccessful");
			}
			else{
				throw new Exception("No OSQuery specified");
			}
			return m_osQuery;
		}//getOSQuery

		/// <summary>
		/// get the standard query data structure.  
		/// @see org.optimizationservices.oscommon.datastructure.osquery.StandardQuery
		/// </summary>
		/// <returns>standard query in the StandardQuery data structure; null if none.  </returns>
		public StandardQuery getStandardQuery(){
			XmlElement eStadnard = (XmlElement)XMLUtil.findChildNode(m_eRoot, "standard");
			if(eStadnard == null) return null;
			StandardQuery standardQuery = new StandardQuery();
			standardQuery.currentState = XMLUtil.getElementValueByName(eStadnard, "currentState");
			OptimizationInfo optimizationInfo = new OptimizationInfo();
			XmlElement eOptimization = (XmlElement)XMLUtil.findChildNode(eStadnard, "optimization");
			if(eOptimization != null){
				standardQuery.optimization = optimizationInfo;
				standardQuery.optimization.description = XMLUtil.getElementValueByName(eOptimization, "description");
				standardQuery.optimization.variableType = XMLUtil.getElementValueByName(eOptimization, "variableType");
				standardQuery.optimization.objectiveType = XMLUtil.getElementValueByName(eOptimization, "objectiveType");
				standardQuery.optimization.constraintType = XMLUtil.getElementValueByName(eOptimization, "constraintType");
				standardQuery.optimization.objectiveLinearity = XMLUtil.getElementValueByName(eOptimization, "objectiveLinearity");
				standardQuery.optimization.constraintLinearity = XMLUtil.getElementValueByName(eOptimization, "constraintLinearity");
				standardQuery.optimization.objectiveDifferentiability = XMLUtil.getElementValueByName(eOptimization, "objectiveDifferentiability");
				standardQuery.optimization.constraintDifferentiability = XMLUtil.getElementValueByName(eOptimization, "constraintDifferentiability");
				standardQuery.optimization.parameterType = XMLUtil.getElementValueByName(eOptimization, "parameterType");
				standardQuery.optimization.stochasticity = XMLUtil.getElementValueByName(eOptimization, "stochasticity");
				String sValue = XMLUtil.getElementValueByName(eOptimization, "realTime");
				if(sValue != null && sValue.StartsWith("t")) standardQuery.optimization.realTime = true;
				else standardQuery.optimization.realTime = false;
				XmlElement eFunctionType = (XmlElement)XMLUtil.findChildNode(eOptimization, "functionType");
				if(eFunctionType != null){
					standardQuery.optimization.functionType = new FunctionType();
					sValue = XMLUtil.getElementValueByName(eFunctionType, "general");
					if(sValue != null && sValue.StartsWith("t")) standardQuery.optimization.functionType.general = true;
					sValue = XMLUtil.getElementValueByName(eFunctionType, "basic");
					if(sValue != null && sValue.StartsWith("f")) standardQuery.optimization.functionType.basic = false;
					sValue = XMLUtil.getElementValueByName(eFunctionType, "arithmetic");
					if(sValue != null && sValue.StartsWith("f")) standardQuery.optimization.functionType.arithmetic = false;
					sValue = XMLUtil.getElementValueByName(eFunctionType, "trigonometric");
					if(sValue != null && sValue.StartsWith("t")) standardQuery.optimization.functionType.trigonometric = true;
					sValue = XMLUtil.getElementValueByName(eFunctionType, "statistics");
					if(sValue != null && sValue.StartsWith("t")) standardQuery.optimization.functionType.statistics = true;
					sValue = XMLUtil.getElementValueByName(eFunctionType, "probability");
					if(sValue != null && sValue.StartsWith("t")) standardQuery.optimization.functionType.probability  = true;
					sValue = XMLUtil.getElementValueByName(eFunctionType, "relationalAndLogic");
					if(sValue != null && sValue.StartsWith("t")) standardQuery.optimization.functionType.relationalAndLogic = true;
					sValue = XMLUtil.getElementValueByName(eFunctionType, "userFunction");
					if(sValue != null && sValue.StartsWith("t")) standardQuery.optimization.functionType.userFunction = true;
					sValue = XMLUtil.getElementValueByName(eFunctionType, "simulation");
					if(sValue != null && sValue.StartsWith("t")) standardQuery.optimization.functionType.simulation = true;
				}
				XmlElement eSpecialStructure = (XmlElement)XMLUtil.findChildNode(eOptimization, "specialStructure");
				if(eSpecialStructure != null){
					standardQuery.optimization.specialStructure = new SpecialStructure();
					sValue = XMLUtil.getElementValueByName(eSpecialStructure, "semidefiniteProgram");
					if(sValue != null && sValue.StartsWith("t")) standardQuery.optimization.specialStructure.semidefiniteProgram = true;
					sValue = XMLUtil.getElementValueByName(eSpecialStructure, "coneProgram");
					if(sValue != null && sValue.StartsWith("t")) standardQuery.optimization.specialStructure.coneProgram = true;
					sValue = XMLUtil.getElementValueByName(eSpecialStructure, "disjunctiveProgram");
					if(sValue != null && sValue.StartsWith("t")) standardQuery.optimization.specialStructure.disjunctiveProgram = true;
				}
				XmlElement eSpecialAlgorithm = (XmlElement)XMLUtil.findChildNode(eOptimization, "specialAlgorithm");
				if(eSpecialAlgorithm != null){
					standardQuery.optimization.specialAlgorithm = new SpecialAlgorithm();
					sValue = XMLUtil.getElementValueByName(eSpecialAlgorithm, "decomposition");
					if(sValue != null && sValue.StartsWith("t")) standardQuery.optimization.specialAlgorithm.decomposition = true;
					sValue = XMLUtil.getElementValueByName(eSpecialAlgorithm, "globalOptimization");
					if(sValue != null && sValue.StartsWith("t")) standardQuery.optimization.specialAlgorithm.globalOptimization = true;
					sValue = XMLUtil.getElementValueByName(eSpecialAlgorithm, "dynamicProgramming");
					if(sValue != null && sValue.StartsWith("t")) standardQuery.optimization.specialAlgorithm.dynamicProgramming = true;
					sValue = XMLUtil.getElementValueByName(eSpecialAlgorithm, "heuristic");
					if(sValue != null && sValue.StartsWith("t")) standardQuery.optimization.specialAlgorithm.heuristic = true;
				}			
			}
			return standardQuery;
		}//getStandardQuery


		/// <summary>
		/// Get the xQuery in a string.  
		/// </summary>
		/// <returns>the xQuery. </returns>
		public string getXQuery(){
			XmlElement eXQuery = (XmlElement)XMLUtil.findChildNode(m_eRoot, "xQuery");
			if(eXQuery == null) return null;
			string sXQuery = XMLUtil.getElementValue(eXQuery);
			return sXQuery;
		}//getXQuery


	}//class OSqLReader
}//namespace