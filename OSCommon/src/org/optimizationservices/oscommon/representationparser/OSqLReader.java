/**
 * @(#)OSaLReader 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.representationparser;

import org.optimizationservices.oscommon.datastructure.osentity.FunctionType;
import org.optimizationservices.oscommon.datastructure.osentity.OptimizationInfo;
import org.optimizationservices.oscommon.datastructure.osentity.SpecialAlgorithm;
import org.optimizationservices.oscommon.datastructure.osentity.SpecialStructure;
import org.optimizationservices.oscommon.datastructure.osquery.StandardQuery;
import org.optimizationservices.oscommon.localinterface.OSQuery;
import org.optimizationservices.oscommon.util.IOUtil;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.XMLUtil;
import org.w3c.dom.Element;

/**
 * The <c>OSqLReader</c> class parses an OSqL instance into a DOM tree and
 * provides a set of "get" methods that can be used to retrieve different 
 * pieces of information of the instance.
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */
public class OSqLReader extends OSgLReader{
	/**
	 * m_osQuery holds the standard OSQuery, which is a local interface for 
	 * storing Optimization Services query. 
	 */
	protected OSQuery m_osQuery = null;

	/**
	 * constructor.
	 * @param validate holds whether the reader	should be validating against the schema	or not.
	 */
	public OSqLReader(boolean validate){
		m_bXsdValidate = validate;
	}//constructor

	/**
	 * Default	constructor. 
	 *
	 */
	public OSqLReader(){
	}//constructor
	
	/**
	 * get the standard OSQuery, a local interface for 
	 * storing Optimization Services query.
	 * 
	 * @return the OSQuery. 
	 * @throws Exception if there are errors getting the OSQuery. 
	 */
   	public OSQuery getOSQuery() throws Exception{
		if(m_osQuery != null){
			return m_osQuery;
		}
		m_osQuery = new OSQuery();
		StandardQuery standardQuery = getStandardQuery();
		String sXQuery = getXQuery();
		if(standardQuery != null){
			if(!m_osQuery.setStandardQuery(standardQuery)) throw new Exception("setStandardQuery Unsuccessful");
		}
		else if(sXQuery != null && sXQuery.length() > 0){
			if(!m_osQuery.setXQuery(sXQuery)) throw new Exception("setXQuery Unsuccessful");
		}
		else{
			throw new Exception("No OSQuery specified");
		}
		return m_osQuery;
   	}//getOSQuery
   	
	/**
	 * get the standard query data structure.  
	 * 
	 * @return standard query in the StandardQuery data structure; null if none.  
	 * @see org.optimizationservices.oscommon.datastructure.osquery.StandardQuery
	 */
	public StandardQuery getStandardQuery(){
		Element eStadnard = (Element)XMLUtil.findChildNode(m_eRoot, "standard");
		if(eStadnard == null) return null;
		StandardQuery standardQuery = new StandardQuery();
		standardQuery.currentState = XMLUtil.getElementValueByName(eStadnard, "currentState");
		OptimizationInfo optimizationInfo = new OptimizationInfo();
		Element eOptimization = (Element)XMLUtil.findChildNode(eStadnard, "optimization");
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
			if(sValue != null && sValue.startsWith("t")) standardQuery.optimization.realTime = true;
			else standardQuery.optimization.realTime = false;
			Element eFunctionType = (Element)XMLUtil.findChildNode(eOptimization, "functionType");
			if(eFunctionType != null){
				standardQuery.optimization.functionType = new FunctionType();
				sValue = XMLUtil.getElementValueByName(eFunctionType, "general");
				if(sValue != null && sValue.startsWith("t")) standardQuery.optimization.functionType.general = true;
				sValue = XMLUtil.getElementValueByName(eFunctionType, "basic");
				if(sValue != null && sValue.startsWith("f")) standardQuery.optimization.functionType.basic = false;
				sValue = XMLUtil.getElementValueByName(eFunctionType, "arithmetic");
				if(sValue != null && sValue.startsWith("f")) standardQuery.optimization.functionType.arithmetic = false;
				sValue = XMLUtil.getElementValueByName(eFunctionType, "trigonometric");
				if(sValue != null && sValue.startsWith("t")) standardQuery.optimization.functionType.trigonometric = true;
				sValue = XMLUtil.getElementValueByName(eFunctionType, "statistics");
				if(sValue != null && sValue.startsWith("t")) standardQuery.optimization.functionType.statistics = true;
				sValue = XMLUtil.getElementValueByName(eFunctionType, "probability");
				if(sValue != null && sValue.startsWith("t")) standardQuery.optimization.functionType.probability  = true;
				sValue = XMLUtil.getElementValueByName(eFunctionType, "relationalAndLogic");
				if(sValue != null && sValue.startsWith("t")) standardQuery.optimization.functionType.relationalAndLogic = true;
				sValue = XMLUtil.getElementValueByName(eFunctionType, "userFunction");
				if(sValue != null && sValue.startsWith("t")) standardQuery.optimization.functionType.userFunction = true;
				sValue = XMLUtil.getElementValueByName(eFunctionType, "simulation");
				if(sValue != null && sValue.startsWith("t")) standardQuery.optimization.functionType.simulation = true;
			}
			Element eSpecialStructure = (Element)XMLUtil.findChildNode(eOptimization, "specialStructure");
			if(eSpecialStructure != null){
				standardQuery.optimization.specialStructure = new SpecialStructure();
				sValue = XMLUtil.getElementValueByName(eSpecialStructure, "semidefiniteProgram");
				if(sValue != null && sValue.startsWith("t")) standardQuery.optimization.specialStructure.semidefiniteProgram = true;
				sValue = XMLUtil.getElementValueByName(eSpecialStructure, "coneProgram");
				if(sValue != null && sValue.startsWith("t")) standardQuery.optimization.specialStructure.coneProgram = true;
				sValue = XMLUtil.getElementValueByName(eSpecialStructure, "disjunctiveProgram");
				if(sValue != null && sValue.startsWith("t")) standardQuery.optimization.specialStructure.disjunctiveProgram = true;
			}
			Element eSpecialAlgorithm = (Element)XMLUtil.findChildNode(eOptimization, "specialAlgorithm");
			if(eSpecialAlgorithm != null){
				standardQuery.optimization.specialAlgorithm = new SpecialAlgorithm();
				sValue = XMLUtil.getElementValueByName(eSpecialAlgorithm, "decomposition");
				if(sValue != null && sValue.startsWith("t")) standardQuery.optimization.specialAlgorithm.decomposition = true;
				sValue = XMLUtil.getElementValueByName(eSpecialAlgorithm, "globalOptimization");
				if(sValue != null && sValue.startsWith("t")) standardQuery.optimization.specialAlgorithm.globalOptimization = true;
				sValue = XMLUtil.getElementValueByName(eSpecialAlgorithm, "dynamicProgramming");
				if(sValue != null && sValue.startsWith("t")) standardQuery.optimization.specialAlgorithm.dynamicProgramming = true;
				sValue = XMLUtil.getElementValueByName(eSpecialAlgorithm, "heuristic");
				if(sValue != null && sValue.startsWith("t")) standardQuery.optimization.specialAlgorithm.heuristic = true;
			}
		}
		return standardQuery;
	}//getStandardQuery
		

 	/**
	 * Get the xQuery in a string.  
	 * 
	 * 
	 * @return the xQuery, null or empty string if none. 
	 */
	public String getXQuery(){
		Element eXQuery = (Element)XMLUtil.findChildNode(m_eRoot, "xQuery");
		if(eXQuery == null) return null;
		String sXQuery = XMLUtil.getElementValue(eXQuery);
		return sXQuery;
	}//getXQuery
	
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		OSqLReader osqlReader = new OSqLReader(false);
		System.out.println(IOUtil.readStringFromFile(OSParameter.CODE_HOME + "OSRepository/test/osql/osql.osql"));
		System.out.println(osqlReader.readFile(OSParameter.CODE_HOME + "OSRepository/test/osql/osql.osql"));
		System.out.println(osqlReader.getXQuery());
		StandardQuery q = osqlReader.getStandardQuery();
		System.out.println(q.currentState);
		if(q.optimization != null){
			System.out.println(q.optimization.variableType);	
			System.out.println(q.optimization.constraintDifferentiability);	
			System.out.println(q.optimization.constraintType);	
			System.out.println(q.optimization.objectiveLinearity);	
			if(q.optimization.functionType != null){
				System.out.println(q.optimization.functionType.arithmetic);
				System.out.println(q.optimization.functionType.probability);
				System.out.println(q.optimization.functionType.statistics);
			}
			if(q.optimization.specialStructure != null){
				System.out.println(q.optimization.specialStructure.disjunctiveProgram);
				System.out.println(q.optimization.specialStructure.coneProgram);
			}
			if(q.optimization.specialAlgorithm != null){
				System.out.println(q.optimization.specialAlgorithm.globalOptimization);
				System.out.println(q.optimization.specialAlgorithm.decomposition);
			}
		}
		
		osqlReader.writeToStandardOutput();
	}//main
	
}//class OSqLReader
