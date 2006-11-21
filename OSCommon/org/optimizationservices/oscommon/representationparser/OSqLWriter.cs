using System;
using System.Xml;
using System.Collections;

using org.optimizationservices.oscommon.util;
using org.optimizationservices.oscommon.localinterface;
using org.optimizationservices.oscommon.datastructure.osquery;
using org.optimizationservices.oscommon.datastructure.osentity;

namespace org.optimizationservices.oscommon.representationparser{
	/// <summary>
	/// The <c>OSqLWriter</c> class is used to construct an instance that follows 
	/// the OSqL format. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OSqLWriter : OSgLWriter{
		/// <summary>
		/// m_eOSqL holds the OSqL root element.
		/// </summary>
		protected internal XmlElement m_eOSqL = null;

        /// <summary>
		/// constructor. 
		/// </summary>
		public OSqLWriter(){
			m_document = XMLUtil.createNewDocument();
			if(OSParameter.XSLT_LOCATION != null && OSParameter.XSLT_LOCATION.Length > 0){
				XmlProcessingInstruction xsltPI = m_document.CreateProcessingInstruction("xml-stylesheet",
					"type=\"text/xsl\" href = \"" + OSParameter.XSLT_LOCATION + "OSqL.xslt\"");
				m_document.AppendChild(xsltPI);     
			}
			m_eOSqL = createOSqLRoot();
			m_document.AppendChild(m_eOSqL);
		}//constructor
		
		/// <summary>
		/// set the OSQuery, a standard os query interface. 
		/// </summary>
		/// <param name="osQuery">holds the standard os query interface. </param>
		/// <returns>whether the OSQuery is set successfully. </returns>
		public bool setOSQuery(OSQuery osQuery){
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

		/// <summary>
		/// set the standard query. 
		/// @see org.optimizationservices.oscommon.datastructure.osquery.StandardQuery
		/// </summary>
		/// <param name="standardQuery">holds the standard query in the StandardQuery data structure. </param>
		/// <returns>whether the standard query is set successfully. </returns>
		public bool setStandardQuery(StandardQuery standardQuery){
			try{
				if(standardQuery != null){
					XMLUtil.removeAllChildren(m_eOSqL);
					XmlElement eStandard = m_document.CreateElement("standard");
					if(standardQuery.currentState != null && standardQuery.currentState.Length > 0){				
						XmlElement eCurrentState = m_document.CreateElement("currentState");
						eCurrentState.AppendChild(m_document.CreateTextNode(standardQuery.currentState));
						eStandard.AppendChild(eCurrentState);					
					}
					if(standardQuery.optimization != null){
						XmlElement eOptimization = m_document.CreateElement("optimization");
					
						if(standardQuery.optimization.description != null && standardQuery.optimization.description.Length > 0){
							XmlElement eDescription = m_document.CreateElement("description");
							eDescription.AppendChild(m_document.CreateTextNode(standardQuery.optimization.description));
							eOptimization.AppendChild(eDescription);
						}
						if(standardQuery.optimization.variableType != null && standardQuery.optimization.variableType.Length > 0){
							XmlElement eVariableType = m_document.CreateElement("variableType");
							eVariableType.AppendChild(m_document.CreateTextNode(standardQuery.optimization.variableType));
							eOptimization.AppendChild(eVariableType);
						}
						if(standardQuery.optimization.objectiveType != null && standardQuery.optimization.objectiveType.Length > 0){
							XmlElement eObjectiveType = m_document.CreateElement("objectiveType");
							eObjectiveType.AppendChild(m_document.CreateTextNode(standardQuery.optimization.objectiveType));
							eOptimization.AppendChild(eObjectiveType);
						}
						if(standardQuery.optimization.constraintType != null && standardQuery.optimization.constraintType.Length > 0){
							XmlElement eConstraintType = m_document.CreateElement("constraintType");
							eConstraintType.AppendChild(m_document.CreateTextNode(standardQuery.optimization.constraintType));
							eOptimization.AppendChild(eConstraintType);
						}
						if(standardQuery.optimization.objectiveLinearity != null && standardQuery.optimization.objectiveLinearity.Length > 0){
							XmlElement eObjectiveLinearity = m_document.CreateElement("objectiveLinearity");
							eObjectiveLinearity.AppendChild(m_document.CreateTextNode(standardQuery.optimization.objectiveLinearity));
							eOptimization.AppendChild(eObjectiveLinearity);
						}
						if(standardQuery.optimization.constraintLinearity != null && standardQuery.optimization.constraintLinearity.Length > 0){
							XmlElement eConstraintLinearity = m_document.CreateElement("constraintLinearity");
							eConstraintLinearity.AppendChild(m_document.CreateTextNode(standardQuery.optimization.constraintLinearity));
							eOptimization.AppendChild(eConstraintLinearity);
						}
						if(standardQuery.optimization.objectiveDifferentiability != null && standardQuery.optimization.objectiveDifferentiability.Length > 0){
							XmlElement eObjectiveDifferentiability = m_document.CreateElement("objectiveDifferentiability");
							eObjectiveDifferentiability.AppendChild(m_document.CreateTextNode(standardQuery.optimization.objectiveDifferentiability));
							eOptimization.AppendChild(eObjectiveDifferentiability);
						}
						if(standardQuery.optimization.constraintDifferentiability != null && standardQuery.optimization.constraintDifferentiability.Length > 0){
							XmlElement eConstraintDifferentiability = m_document.CreateElement("constraintDifferentiability");
							eConstraintDifferentiability.AppendChild(m_document.CreateTextNode(standardQuery.optimization.constraintDifferentiability));
							eOptimization.AppendChild(eConstraintDifferentiability);
						}
						if(standardQuery.optimization.parameterType != null && standardQuery.optimization.parameterType.Length > 0){
							XmlElement eParameterType = m_document.CreateElement("parameterType");
							eParameterType.AppendChild(m_document.CreateTextNode(standardQuery.optimization.parameterType));
							eOptimization.AppendChild(eParameterType);
						}
						if(standardQuery.optimization.stochasticity != null && standardQuery.optimization.stochasticity.Length > 0){
							XmlElement eStochasticity = m_document.CreateElement("stochasticity");
							eStochasticity.AppendChild(m_document.CreateTextNode(standardQuery.optimization.stochasticity));
							eOptimization.AppendChild(eStochasticity);
						}
						if(standardQuery.optimization.realTime == true){
							XmlElement eRealTime = m_document.CreateElement("realTime");
							eRealTime.AppendChild(m_document.CreateTextNode("true"));
							eOptimization.AppendChild(eRealTime);
						}
						if(standardQuery.optimization.functionType != null){
							XmlElement eFunctionType = m_document.CreateElement("functionType");
						
							if(standardQuery.optimization.functionType.general == true){
								XmlElement eGeneral = m_document.CreateElement("general");
								eGeneral.AppendChild(m_document.CreateTextNode("true"));
								eFunctionType.AppendChild(eGeneral);
							}
							if(standardQuery.optimization.functionType.basic == false){
								XmlElement eBasic = m_document.CreateElement("basic");
								eBasic.AppendChild(m_document.CreateTextNode("false"));
								eFunctionType.AppendChild(eBasic);
							}
							if(standardQuery.optimization.functionType.arithmetic == false){
								XmlElement eArithmetic = m_document.CreateElement("arithmetic");
								eArithmetic.AppendChild(m_document.CreateTextNode("false"));
								eFunctionType.AppendChild(eArithmetic);
							}
							if(standardQuery.optimization.functionType.trigonometric == true){
								XmlElement eTrigonometric = m_document.CreateElement("trigonometric");
								eTrigonometric.AppendChild(m_document.CreateTextNode("true"));
								eFunctionType.AppendChild(eTrigonometric);
							}
							if(standardQuery.optimization.functionType.statistics == true){
								XmlElement eStatistics = m_document.CreateElement("statistics");
								eStatistics.AppendChild(m_document.CreateTextNode("true"));
								eFunctionType.AppendChild(eStatistics);
							}
							if(standardQuery.optimization.functionType.probability == true){
								XmlElement eProbability = m_document.CreateElement("probability");
								eProbability.AppendChild(m_document.CreateTextNode("true"));
								eFunctionType.AppendChild(eProbability);
							}
							if(standardQuery.optimization.functionType.relationalAndLogic == true){
								XmlElement eRelationalAndLogic = m_document.CreateElement("relationalAndLogic");
								eRelationalAndLogic.AppendChild(m_document.CreateTextNode("true"));
								eFunctionType.AppendChild(eRelationalAndLogic);
							}
							if(standardQuery.optimization.functionType.userFunction == true){
								XmlElement eUserFunction = m_document.CreateElement("userFunction");
								eUserFunction.AppendChild(m_document.CreateTextNode("true"));
								eFunctionType.AppendChild(eUserFunction);
							}
							if(standardQuery.optimization.functionType.simulation == true){
								XmlElement eSimulation = m_document.CreateElement("simulation");
								eSimulation.AppendChild(m_document.CreateTextNode("true"));
								eFunctionType.AppendChild(eSimulation);
							}
						
							eOptimization.AppendChild(eFunctionType);
						}
						if(standardQuery.optimization.specialStructure != null){
							XmlElement eSpecialStructure = m_document.CreateElement("specialStructure");
						
							if(standardQuery.optimization.specialStructure.semidefiniteProgram == true){
								XmlElement eSemidefiniteProgram = m_document.CreateElement("semidefiniteProgram");
								eSemidefiniteProgram.AppendChild(m_document.CreateTextNode("true"));
								eSpecialStructure.AppendChild(eSemidefiniteProgram);
							}
							if(standardQuery.optimization.specialStructure.coneProgram == true){
								XmlElement eConeProgram = m_document.CreateElement("coneProgram");
								eConeProgram.AppendChild(m_document.CreateTextNode("true"));
								eSpecialStructure.AppendChild(eConeProgram);
							}						
							if(standardQuery.optimization.specialStructure.disjunctiveProgram == true){
								XmlElement eDisjunctiveProgram = m_document.CreateElement("disjunctiveProgram");
								eDisjunctiveProgram.AppendChild(m_document.CreateTextNode("true"));
								eSpecialStructure.AppendChild(eDisjunctiveProgram);
							}
						
							eOptimization.AppendChild(eSpecialStructure);
						}
						if(standardQuery.optimization.specialAlgorithm != null){
							XmlElement eSpecialAlgorithm = m_document.CreateElement("specialAlgorithm");
						
							if(standardQuery.optimization.specialAlgorithm.decomposition == true){
								XmlElement eDecomposition = m_document.CreateElement("decomposition");
								eDecomposition.AppendChild(m_document.CreateTextNode("true"));
								eSpecialAlgorithm.AppendChild(eDecomposition);
							}
							if(standardQuery.optimization.specialAlgorithm.globalOptimization == true){
								XmlElement eGlobalOptimization = m_document.CreateElement("globalOptimization");
								eGlobalOptimization.AppendChild(m_document.CreateTextNode("true"));
								eSpecialAlgorithm.AppendChild(eGlobalOptimization);
							}
							if(standardQuery.optimization.specialAlgorithm.dynamicProgramming == true){
								XmlElement eDynamicProgramming = m_document.CreateElement("dynamicProgramming");
								eDynamicProgramming.AppendChild(m_document.CreateTextNode("true"));
								eSpecialAlgorithm.AppendChild(eDynamicProgramming);
							}
							if(standardQuery.optimization.specialAlgorithm.heuristic == true){
								XmlElement eHeuristic = m_document.CreateElement("heuristic");
								eHeuristic.AppendChild(m_document.CreateTextNode("true"));
								eSpecialAlgorithm.AppendChild(eHeuristic);
							}						
						
							eOptimization.AppendChild(eSpecialAlgorithm);
						}
						eStandard.AppendChild(eOptimization);
					}
					m_eOSqL.AppendChild(eStandard);
				}
				else{
					XMLUtil.removeChildrenByName(m_eOSqL, "standard");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setStandardQuery

		/// <summary>
		/// Set the XQuery. 
		/// </summary>
		/// <param name="xQuery">holds the XQuery in a string. </param>
		/// <returns>whether the XQuery is set successfully or not. </returns>
		public bool setXQuery(string xQuery){
			try{
				if(xQuery != null && xQuery.Length > 0){
					XMLUtil.removeAllChildren(m_eOSqL);
					XmlElement eXQuery = m_document.CreateElement("xQuery");
					eXQuery.AppendChild(m_document.CreateTextNode(xQuery));
					m_eOSqL.AppendChild(eXQuery);
			
				}
				else{
					XMLUtil.removeChildrenByName(m_eOSqL, "xQuery");
				}
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;
		}//setXQuery
	
		

		/// <summary>
		/// Create the OSqL root element and its most basic required structure.
		/// </summary>
		/// <returns>the OSqL element.</returns>
		protected XmlElement createOSqLRoot(){
			XmlElement eOSqL = XMLUtil.createOSxLRootElement(m_document, "osql");
			return eOSqL;
		}//createOSqLRoot

	}//class OSqLWriter
}//namespace
