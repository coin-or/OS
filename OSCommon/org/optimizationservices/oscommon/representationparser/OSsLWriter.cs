using System;
using System.Xml;
using org.optimizationservices.oscommon.util;
using org.optimizationservices.oscommon.localinterface;
using org.optimizationservices.oscommon.datastructure.ossimulation;

namespace org.optimizationservices.oscommon.representationparser{
	/// <summary>
	/// The <c>OSsLWriter</c> class is used to construct an instance that follows 
	/// the OSsL format. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OSsLWriter : OSgLWriter{
		/// <summary>
		/// m_eOSsL holds the OSsL root element.
		/// </summary>
		protected internal XmlElement m_eOSsL = null;

		/// <summary>
		/// m_eInput holds the input child element of root element OSsL.
		/// </summary>
		protected XmlElement m_eInput = null;

		/// <summary>
		/// m_eOutput holds the output child element of root element OSsL.
		/// </summary>
		protected XmlElement m_eOutput = null;
			
		/// <summary>
		/// constructor. 
		/// </summary>
		public OSsLWriter(){
			m_document = XMLUtil.createNewDocument();
			if(OSParameter.XSLT_LOCATION != null && OSParameter.XSLT_LOCATION.Length > 0){
				XmlProcessingInstruction xsltPI = m_document.CreateProcessingInstruction("xml-stylesheet",
					"type=\"text/xsl\" href = \"" + OSParameter.XSLT_LOCATION + "OSsL.xslt\"");
				m_document.AppendChild(xsltPI);     
			}
			m_eOSsL = createOSsLRoot();
			m_document.AppendChild(m_eOSsL);
		}//constructor

		/// <summary>
		/// set the OSSimulation, a standard os simulation interface. 
		/// </summary>
		/// <param name="osSimulation">holds the standard os simulation interface. </param>
		/// <returns>whether the OSSimulation is set successfully. </returns>
		public bool setOSSimulation(OSSimulation osSimulation){
			if(!setSimulationInputElements(osSimulation.getSimulationInputElements())){ 
				throw new Exception("setSimulationInputElements Unsuccessful");
			}
			if(!setSimulationOutputElements(osSimulation.getSimulationOutputElements())){ 
				throw new Exception("setSimulationOutputElements Unsuccessful");
			}
			return true;
		}//setOSSimulation

		/// <summary>
		/// set simulation input elements.
		/// @see org.optimizationservices.oscommon.datastructure.ossimulation.SimulationElement
		/// </summary>
		/// <param name="simulationInputElements">holds an array of simulation input elements. 
		/// Each member of array is a simulation element. 
		/// </param>
		/// <returns>whether the simulation input elements are set successfully or not. </returns>
		public bool setSimulationInputElements(SimulationElement[] simulationInputElements){
			if(simulationInputElements == null || simulationInputElements.Length <= 0){
				XMLUtil.removeChildrenByName(m_eOSsL, "input");
				return true;
			}
			for(int i = 0; i < simulationInputElements.Length; i++){
				setInputElement(simulationInputElements[i].name, 
					simulationInputElements[i].type==null?"":simulationInputElements[i].type, 
					simulationInputElements[i].value);
			}
			return true;
		}//setSimulationInputElements

		/// <summary>
		/// set simulation output elements.
		/// @see org.optimizationservices.oscommon.datastructure.ossimulation.SimulationElement 
		/// </summary>
		/// <param name="simulationOutputElements">holds an array of simulation output elements. 
		/// Each member of array is a simulation element. 
		/// </param>
		/// <returns>whether the simulation output elements are set successfully or not. </returns>
		public bool setSimulationOutputElements(SimulationElement[] simulationOutputElements){
			if(simulationOutputElements == null || simulationOutputElements.Length <= 0){
				XMLUtil.removeChildrenByName(m_eOSsL, "output");
				return true;
			}
			for(int i = 0; i < simulationOutputElements.Length; i++){
				setOutputElement(simulationOutputElements[i].name, 
					simulationOutputElements[i].type==null?"":simulationOutputElements[i].type, 
					simulationOutputElements[i].value);
			}
			return true;
		}//setSimulationOutputElements

		/// <summary>
		/// Set the input related elements. If the elements (e.g. the required elements) are
		/// already there, it will reset the them. If the elements are not there (e.g. 
		/// the optional elements), it will add them.
		/// </summary>
		/// <param name="names">holds the names of the inputs. It is required. </param>
		/// <param name="types">holds the types of the inputs, either string (default) or link. </param>
		/// <param name="values">holds the values of inputs. It is required. </param>
		/// <returns>whether the input element construction is successful.</returns>
		public bool setInput(String[] names, String[] types, String[] values){
			if(names == null) return false;
			if(values == null) return false;
			if(names.Length != values.Length) return false;
			if(types != null && types.Length != names.Length) return false;
			for(int i = 0; i < names.Length; i++){
				setInputElement(names[i], (types==null)?"":types[i], values[i]);
			}
			return true;
		}//setInput


		/// <summary>
		/// Set an input el element. If the el element is already there, 
		/// it will reset the element. If the elements is not there, it will add the element.
		/// </summary>
		/// <param name="name">holds the name of the input el element. It is required. </param>
		/// <param name="type">holds the type of the input el element, either string (default) or link. </param>
		/// <param name="value">holds the value of the input el element. It is required. </param>
		/// <returns>whether the input el element is set successfully.</returns>
		public bool setInputElement(string name, string type, string value){
			if(name == null) return false;
			if(value == null) return false;
			if(m_eInput == null){
				m_eInput = createInput(new XmlElement[]{createEl(name, type, value)});
				m_eOSsL.AppendChild(m_eInput);
				return true;
			}
			XmlNodeList nodeList = m_eInput.GetElementsByTagName("el");
			XmlElement eEl;
			int iNls = nodeList==null?0:nodeList.Count;
			for(int i = 0; i < iNls; i++){
				eEl = (XmlElement)nodeList.Item(i);
				if(eEl.GetAttribute("name").Equals(name)){
					m_eInput.RemoveChild(eEl);
					break;
				}
			}
			eEl = createEl(name, type, value);
			m_eInput.AppendChild(eEl);
			return true;
		}//setInputElement

		/// <summary>
		/// Set the output related elements. If the elements (e.g. the required elements) are
		/// already there, it will reset the them. If the elements are not there (e.g. the optional
		/// elements), it will add them.
		/// </summary>
		/// <param name="names">holds the names of the outputs. It is required. </param>
		/// <param name="types">holds the types of the outputs, either string (default) or link. </param>
		/// <param name="values">holds the values of outputs. It is required. </param>
		/// <returns>whether the output element construction is successful.</returns>
		public bool setOutput(string[] names, string[] types, string[] values){
			if(names == null) return false;
			if(values == null) return false;
			if(names.Length != values.Length) return false;
			if(types != null && types.Length != names.Length) return false;
			for(int i = 0; i < names.Length; i++){
				setOutputElement(names[i], (types==null)?"":types[i], values[i]);
			}
			return true;
		}//setOutput

		/// <summary>
		/// Set an output el element. If the el element is already there, 
		/// it will reset the element. If the elements is not there, it will add the element.
		/// </summary>
		/// <param name="name">holds the name of the output el element. It is required. </param>
		/// <param name="type">holds the type of the output el element, either string (default) or link. </param>
		/// <param name="value">holds the value of the output el element. It is required. </param>
		/// <returns>whether the output el element is successfully.</returns>
		public bool setOutputElement(string name, string type, string value){
			if(name == null) return false;
			if(value == null) return false;
			if(m_eOutput == null){
				m_eOutput = createOutput(new XmlElement[]{createEl(name, type, value)});
				m_eOSsL.AppendChild(m_eOutput);
				return true;
			}
			XmlNodeList nodeList = m_eOutput.GetElementsByTagName("el");
			XmlElement eEl;
			int iNls = nodeList==null?0:nodeList.Count;
			for(int i = 0; i < iNls; i++){
				eEl = (XmlElement)nodeList.Item(i);
				if(eEl.GetAttribute("name").Equals(name)){
					m_eOutput.RemoveChild(eEl);
					break;
				}
			}
			eEl = createEl(name, type, value);
			m_eOutput.AppendChild(eEl);
			return true;
		}//setOutputElement

		/// <summary>
		/// Create the OSsL root element and its most basic required structure.
		/// </summary>
		/// <returns>the OSsL element.</returns>
		protected XmlElement createOSsLRoot(){
			XmlElement eOSsL = XMLUtil.createOSxLRootElement(m_document, "ossl");
			return eOSsL;
		}//createOSsLRoot

		/// <summary>
		/// Create the input element and its most basic required structure.
		/// </summary>
		/// <param name="elArray">holds an array of el element. </param>
		/// <returns>the input element.</returns>
		protected XmlElement createInput(XmlElement[] elArray){
			XmlElement eInput = m_document.CreateElement("input");
			if(elArray != null){
				for(int i = 0; i < elArray.Length; i++){
					eInput.AppendChild(elArray[i]);
				}
			}
			return eInput;
		}//createInput

		/// <summary>
		/// Create the output element and its most basic required structure.
		/// </summary>
		/// <param name="elArray">holds an array of el element. </param>
		/// <returns>the output element</returns>
		protected XmlElement createOutput(XmlElement[] elArray){
			XmlElement eOutput = m_document.CreateElement("output");
			if(elArray == null) return null;
			for(int i = 0; i < elArray.Length; i++){
				eOutput.AppendChild(elArray[i]);
			}
			return eOutput;
		}//createOutput

		/// <summary>
		/// Create the el element and its most basic required structure.
		/// </summary>
		/// <param name="name">the name of the el element. </param>
		/// <param name="type">the type of the el element, either string (default) or link. </param>
		/// <param name="value">the value of the el element. </param>
		/// <returns>the el element.</returns>
		protected XmlElement createEl(string name, string type, string value){
			XmlElement eEl = m_document.CreateElement("el");
			eEl.SetAttribute("name", name);
			if(type != null && type.Length > 0){
				if(type.Equals("link")) eEl.SetAttribute("type", "link");
				else eEl.SetAttribute("type", "string");
			}
			eEl.AppendChild(m_document.CreateTextNode(value));
			return eEl;
		}//createEl
	}//class OSsLWriter
}//namespace
