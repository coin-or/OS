/**
 * @(#)OSbLWriter 1.0 03/14/2004
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
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.XMLUtil;
import org.w3c.dom.Element;
import org.w3c.dom.ProcessingInstruction;
/**
 * The <code>OSqLWriter</code> class is used to construct an instance that follows 
 * the OSqL format. 
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */
public class OSqLWriter extends OSgLWriter{

	/**
	 * m_eOSqL holds the OSqL root element.
	 */
	protected Element m_eOSqL = null;

	
	/**
	 * constructor. 
	 *
	 */
	public OSqLWriter(){
		m_document = XMLUtil.createNewDocument();
		if(OSParameter.XSLT_LOCATION != null && OSParameter.XSLT_LOCATION.length() > 0){
			ProcessingInstruction xsltPI = m_document.createProcessingInstruction("xml-stylesheet",
	           "type=\"text/xsl\" href = \"" + OSParameter.XSLT_LOCATION + "OSqL.xslt\"");
			m_document.appendChild(xsltPI);     
		}
		m_eOSqL = createOSqLRoot();
		m_document.appendChild(m_eOSqL);
	}//constructor
	
	/**
	 * set the OSQuery, a standard os query interface. 
	 * @param osQuery holds the standard os query interface. 
	 * @return whether the OSQuery is set successfully. 
	 */
	public boolean setOSQuery(OSQuery osQuery) throws Exception{
		if(osQuery.standard != null){
			if(!setStandardQuery(osQuery.getStandardQuery())){ 
	   			throw new Exception("setStandardQuery Unsuccessful");
			}
		}
		else if(osQuery.xQuery != null){
			if(!setXQuery(osQuery.getXQuery())){ 
	   			throw new Exception("setXQuery Unsuccessful");
			}
		}
		else{
			throw new Exception("No OSQuery specified");
		}
		return true;
	}//setOSQuery
		
	/**
	 * set the standard query. 
	 * @param standardQuery holds the standard query in the StandardQuery data structure. 
	 * @return whether the standard query is set successfully. 
	 * @see org.optimizationservices.oscommon.datastructure.osquery.StandardQuery
	 */
	public boolean setStandardQuery(StandardQuery standardQuery){
		try{
			if(standardQuery != null){
				XMLUtil.removeAllChildren(m_eOSqL);
				Element eStandard = m_document.createElement("standard");
				if(standardQuery.currentState != null && standardQuery.currentState.length() > 0){				
					Element eCurrentState = m_document.createElement("currentState");
					eCurrentState.appendChild(m_document.createTextNode(standardQuery.currentState));
					eStandard.appendChild(eCurrentState);					
				}
				if(standardQuery.optimization != null){
					Element eOptimization = m_document.createElement("optimization");
					
					if(standardQuery.optimization.description != null && standardQuery.optimization.description.length() > 0){
						Element eDescription = m_document.createElement("description");
						eDescription.appendChild(m_document.createTextNode(standardQuery.optimization.description));
						eOptimization.appendChild(eDescription);
					}
					if(standardQuery.optimization.variableType != null && standardQuery.optimization.variableType.length() > 0){
						Element eVariableType = m_document.createElement("variableType");
						eVariableType.appendChild(m_document.createTextNode(standardQuery.optimization.variableType));
						eOptimization.appendChild(eVariableType);
					}
					if(standardQuery.optimization.objectiveType != null && standardQuery.optimization.objectiveType.length() > 0){
						Element eObjectiveType = m_document.createElement("objectiveType");
						eObjectiveType.appendChild(m_document.createTextNode(standardQuery.optimization.objectiveType));
						eOptimization.appendChild(eObjectiveType);
					}
					if(standardQuery.optimization.constraintType != null && standardQuery.optimization.constraintType.length() > 0){
						Element eConstraintType = m_document.createElement("constraintType");
						eConstraintType.appendChild(m_document.createTextNode(standardQuery.optimization.constraintType));
						eOptimization.appendChild(eConstraintType);
					}
					if(standardQuery.optimization.objectiveLinearity != null && standardQuery.optimization.objectiveLinearity.length() > 0){
						Element eObjectiveLinearity = m_document.createElement("objectiveLinearity");
						eObjectiveLinearity.appendChild(m_document.createTextNode(standardQuery.optimization.objectiveLinearity));
						eOptimization.appendChild(eObjectiveLinearity);
					}
					if(standardQuery.optimization.constraintLinearity != null && standardQuery.optimization.constraintLinearity.length() > 0){
						Element eConstraintLinearity = m_document.createElement("constraintLinearity");
						eConstraintLinearity.appendChild(m_document.createTextNode(standardQuery.optimization.constraintLinearity));
						eOptimization.appendChild(eConstraintLinearity);
					}
					if(standardQuery.optimization.objectiveDifferentiability != null && standardQuery.optimization.objectiveDifferentiability.length() > 0){
						Element eObjectiveDifferentiability = m_document.createElement("objectiveDifferentiability");
						eObjectiveDifferentiability.appendChild(m_document.createTextNode(standardQuery.optimization.objectiveDifferentiability));
						eOptimization.appendChild(eObjectiveDifferentiability);
					}
					if(standardQuery.optimization.constraintDifferentiability != null && standardQuery.optimization.constraintDifferentiability.length() > 0){
						Element eConstraintDifferentiability = m_document.createElement("constraintDifferentiability");
						eConstraintDifferentiability.appendChild(m_document.createTextNode(standardQuery.optimization.constraintDifferentiability));
						eOptimization.appendChild(eConstraintDifferentiability);
					}
					if(standardQuery.optimization.parameterType != null && standardQuery.optimization.parameterType.length() > 0){
						Element eParameterType = m_document.createElement("parameterType");
						eParameterType.appendChild(m_document.createTextNode(standardQuery.optimization.parameterType));
						eOptimization.appendChild(eParameterType);
					}
					if(standardQuery.optimization.stochasticity != null && standardQuery.optimization.stochasticity.length() > 0){
						Element eStochasticity = m_document.createElement("stochasticity");
						eStochasticity.appendChild(m_document.createTextNode(standardQuery.optimization.stochasticity));
						eOptimization.appendChild(eStochasticity);
					}
					if(standardQuery.optimization.realTime == true){
						Element eRealTime = m_document.createElement("realTime");
						eRealTime.appendChild(m_document.createTextNode("true"));
						eOptimization.appendChild(eRealTime);
					}
					if(standardQuery.optimization.functionType != null){
						Element eFunctionType = m_document.createElement("functionType");
						
						if(standardQuery.optimization.functionType.general == true){
							Element eGeneral = m_document.createElement("general");
							eGeneral.appendChild(m_document.createTextNode("true"));
							eFunctionType.appendChild(eGeneral);
						}
						if(standardQuery.optimization.functionType.basic == false){
							Element eBasic = m_document.createElement("basic");
							eBasic.appendChild(m_document.createTextNode("false"));
							eFunctionType.appendChild(eBasic);
						}
						if(standardQuery.optimization.functionType.arithmetic == false){
							Element eArithmetic = m_document.createElement("arithmetic");
							eArithmetic.appendChild(m_document.createTextNode("false"));
							eFunctionType.appendChild(eArithmetic);
						}
						if(standardQuery.optimization.functionType.trigonometric == true){
							Element eTrigonometric = m_document.createElement("trigonometric");
							eTrigonometric.appendChild(m_document.createTextNode("true"));
							eFunctionType.appendChild(eTrigonometric);
						}
						if(standardQuery.optimization.functionType.statistics == true){
							Element eStatistics = m_document.createElement("statistics");
							eStatistics.appendChild(m_document.createTextNode("true"));
							eFunctionType.appendChild(eStatistics);
						}
						if(standardQuery.optimization.functionType.probability == true){
							Element eProbability = m_document.createElement("probability");
							eProbability.appendChild(m_document.createTextNode("true"));
							eFunctionType.appendChild(eProbability);
						}
						if(standardQuery.optimization.functionType.relationalAndLogic == true){
							Element eRelationalAndLogic = m_document.createElement("relationalAndLogic");
							eRelationalAndLogic.appendChild(m_document.createTextNode("true"));
							eFunctionType.appendChild(eRelationalAndLogic);
						}
						if(standardQuery.optimization.functionType.userFunction == true){
							Element eUserFunction = m_document.createElement("userFunction");
							eUserFunction.appendChild(m_document.createTextNode("true"));
							eFunctionType.appendChild(eUserFunction);
						}
						if(standardQuery.optimization.functionType.simulation == true){
							Element eSimulation = m_document.createElement("simulation");
							eSimulation.appendChild(m_document.createTextNode("true"));
							eFunctionType.appendChild(eSimulation);
						}
						
						eOptimization.appendChild(eFunctionType);
					}
					if(standardQuery.optimization.specialStructure != null){
						Element eSpecialStructure = m_document.createElement("specialStructure");
						
						if(standardQuery.optimization.specialStructure.semidefiniteProgram == true){
							Element eSemidefiniteProgram = m_document.createElement("semidefiniteProgram");
							eSemidefiniteProgram.appendChild(m_document.createTextNode("true"));
							eSpecialStructure.appendChild(eSemidefiniteProgram);
						}
						if(standardQuery.optimization.specialStructure.coneProgram == true){
							Element eConeProgram = m_document.createElement("coneProgram");
							eConeProgram.appendChild(m_document.createTextNode("true"));
							eSpecialStructure.appendChild(eConeProgram);
						}						
						if(standardQuery.optimization.specialStructure.disjunctiveProgram == true){
							Element eDisjunctiveProgram = m_document.createElement("disjunctiveProgram");
							eDisjunctiveProgram.appendChild(m_document.createTextNode("true"));
							eSpecialStructure.appendChild(eDisjunctiveProgram);
						}
						
						eOptimization.appendChild(eSpecialStructure);
					}
					if(standardQuery.optimization.specialAlgorithm != null){
						Element eSpecialAlgorithm = m_document.createElement("specialAlgorithm");
						
						if(standardQuery.optimization.specialAlgorithm.decomposition == true){
							Element eDecomposition = m_document.createElement("decomposition");
							eDecomposition.appendChild(m_document.createTextNode("true"));
							eSpecialAlgorithm.appendChild(eDecomposition);
						}
						if(standardQuery.optimization.specialAlgorithm.globalOptimization == true){
							Element eGlobalOptimization = m_document.createElement("globalOptimization");
							eGlobalOptimization.appendChild(m_document.createTextNode("true"));
							eSpecialAlgorithm.appendChild(eGlobalOptimization);
						}
						if(standardQuery.optimization.specialAlgorithm.dynamicProgramming == true){
							Element eDynamicProgramming = m_document.createElement("dynamicProgramming");
							eDynamicProgramming.appendChild(m_document.createTextNode("true"));
							eSpecialAlgorithm.appendChild(eDynamicProgramming);
						}
						if(standardQuery.optimization.specialAlgorithm.heuristic == true){
							Element eHeuristic = m_document.createElement("heuristic");
							eHeuristic.appendChild(m_document.createTextNode("true"));
							eSpecialAlgorithm.appendChild(eHeuristic);
						}						
						
						eOptimization.appendChild(eSpecialAlgorithm);
					}
					eStandard.appendChild(eOptimization);
				}
				m_eOSqL.appendChild(eStandard);
			}
			else{
				XMLUtil.removeChildrenByName(m_eOSqL, "standard");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setStandardQuery
	
	
 	/**
	 * Set the XQuery. 
	 * 
	 * 
	 * @param xQuery holds the XQuery in a string. 
	 * @return whether the XQuery is set successfully or not. 
	 */
	public boolean setXQuery(String xQuery){
		try{
			if(xQuery != null && xQuery.length() > 0){
				XMLUtil.removeAllChildren(m_eOSqL);
				Element eXQuery = m_document.createElement("xQuery");
				eXQuery.appendChild(m_document.createTextNode(xQuery));
				m_eOSqL.appendChild(eXQuery);
			}
			else{
				XMLUtil.removeChildrenByName(m_eOSqL, "xQuery");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setXQuery

	
	/**
	 * Create the OSqL root element and its most basic required structure.
	 * 
	 * @return the OSqL element.
	 */
	protected Element createOSqLRoot(){
		Element eOSqL = XMLUtil.createOSxLRootElement(m_document, "osql");
		return eOSqL;
	}//createOSqLRoot
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		OSqLWriter osqlWriter = new OSqLWriter();
		String sFileName = OSParameter.CODE_HOME + "OSRepository/test/osql/osql.osql";

		if(!osqlWriter.setXQuery("xQuery xQuery xQuery")) System.out.println("setXQuery!");
		StandardQuery q = new StandardQuery();
		q.currentState = "busy";
		OptimizationInfo opt = new OptimizationInfo();
		opt.constraintType = "generalRange";
		opt.variableType = "mixedInteger";
		opt.objectiveLinearity = "linear";
		opt.functionType = new FunctionType();
		opt.functionType.probability = true;
		opt.specialAlgorithm = new SpecialAlgorithm();
		opt.specialAlgorithm.decomposition = true;
		opt.specialStructure = new SpecialStructure();
		opt.specialStructure.disjunctiveProgram = true;
		q.optimization = opt;
		if(!osqlWriter.setStandardQuery(q)) System.out.println("setStandardQuery!");
	
		////////////////////

		OSqLReader osqlReader = new OSqLReader(false);
		if(!osqlReader.readFile(sFileName)) System.out.println("reading");
		OSQuery osQuery;
		try {
			osQuery = osqlReader.getOSQuery();
			if(!osqlWriter.setOSQuery(osQuery)) System.out.println("set OSQuery");
		} 
		catch (Exception e) {
			e.printStackTrace();
		}
		////////////////////
		
		//osqlWriter.writeToStandardOutput();
		System.out.println(osqlWriter.writeToString());
	
	}//main
	
}//class OSqLWriter
