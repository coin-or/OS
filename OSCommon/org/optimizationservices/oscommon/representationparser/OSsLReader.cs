using System;
using System.Collections;
using System.Xml;

using org.optimizationservices.oscommon.util;
using org.optimizationservices.oscommon.localinterface;
using org.optimizationservices.oscommon.datastructure.ossimulation;

namespace org.optimizationservices.oscommon.representationparser{
	///	<summary>
	///	The	<c>OSsLReader</c> class	parses an OSsL instance	into a DOM tree	and
	///	provides a set of "get"	methods	that can be	
	///	used to	retrieve different pieces of information of	the	instance.
	///	@author	Jun	Ma	
	///	@version 1.0, 09/01/2005
	///	@since OS 1.0
	///	@copyright (c) 2005
	///	</summary>
	public class OSsLReader	: OSgLReader{
		/// <summary>
		/// m_osSimulation holds the standard OSSimulation, which is a local interface for 
		/// storing Optimization Services simulation input/output. 
		/// </summary>
		protected OSSimulation m_osSimulation = null;

		///	<summary>
		///	m_inputHashMap holds a hash	map	of the input of	name-value pairs for the simulation.
		///	</summary>
		protected Hashtable	m_inputHashMap = null;

		///	<summary>
		///	m_outputHashMap	holds a	hash map of	the	output of name-value pairs for the simulation.
		///	</summary>
		protected Hashtable	m_outputHashMap	= null;

		///	<summary>
		///	constructor.
		///	</summary>
		///	<param name="validate">holds whether the reader	should be validating against the schema	or not.</param>
		public OSsLReader(bool validate){
			m_bXsdValidate = validate;
		}//constructor
	
		///	<summary>
		///	Default	constructor. 
		///	</summary>
		public OSsLReader(){
		}//constructor

		/// <summary>
		/// get the standard OSSimulation, a local interface for 
		/// storing Optimization Services simulation.
		/// 
		/// </summary>
		/// <returns>the OSSimulation. </returns>
		public OSSimulation getOSSimulation(){
			if(m_osSimulation != null){
				return m_osSimulation;
			}
			m_osSimulation = new OSSimulation();
			if(!m_osSimulation.setSimulationInputElements(getSimulationInputElements())) throw new Exception("setSimulationInputElements Unsuccessful");
			if(!m_osSimulation.setSimulationOutputElements(getSimulationOutputElements())) throw new Exception("setSimulationOutputElements Unsuccessful");
			return m_osSimulation;
		}//getOSSimulation

		/// <summary>
		/// get simulation input elements.
		/// @see org.optimizationservices.oscommon.datastructure.ossimulation.SimulationElement
		/// </summary>
		/// <returns>an array of simulation input elements, null if none. Each member of array
		/// is a simulation element. </returns>
		public SimulationElement[] getSimulationInputElements(){
			XmlElement eInput = (XmlElement)XMLUtil.findChildNode(m_eRoot, "input");
			if(eInput == null) return null;
			XmlNodeList nls = eInput.GetElementsByTagName("el");
			int iNls = nls.Count;
			if (iNls <= 0) return null;
			SimulationElement[] mElements = new SimulationElement[iNls];		
			for(int i = 0; i < iNls; i++){
				mElements[i] = new SimulationElement();		
				XmlElement eEl = (XmlElement)(nls.Item(i));
				XmlNamedNodeMap attributes =  eEl.Attributes;
				int n =attributes.Count;
				String sName = "";
				String sType = "string";
				String sValue = XMLUtil.getElementValue(eEl);
				for (int j = 0; j < n; j++){
					XmlNode attr = attributes.Item(j);
					String sAttributeName  = attr.LocalName;
					String sAttributeValue = attr.Value;
					if (sAttributeName.Equals("name")){
						sName = sAttributeValue;
					}
					else if (sAttributeName.Equals("type")){
						sType = sAttributeValue;
					}
				}
				mElements[i].name = sName;
				mElements[i].type = sType;
				mElements[i].value = sValue;
			}
			return mElements;
		}//getSimulationInput

		/// <summary>
		/// get simulation output elements.
		/// @see org.optimizationservices.oscommon.datastructure.ossimulation.SimulationElement
		/// </summary>
		/// <returns>an array of simulation output elements, null if none. Each member of array 
		/// is a simulation element. </returns>
		public SimulationElement[] getSimulationOutputElements(){
			XmlElement eOutput = (XmlElement)XMLUtil.findChildNode(m_eRoot, "output");
			if(eOutput == null) return null;
			XmlNodeList nls = eOutput.GetElementsByTagName("el");
			int iNls = nls.Count;
			if (iNls <= 0) return null;
			SimulationElement[] mElements = new SimulationElement[iNls];		
			for(int i = 0; i < iNls; i++){
				mElements[i] = new SimulationElement();		
				XmlElement eEl = (XmlElement)(nls.Item(i));
				XmlNamedNodeMap attributes =  eEl.Attributes;
				int n =attributes.Count;
				String sName = "";
				String sType = "string";
				String sValue = XMLUtil.getElementValue(eEl);
				for (int j = 0; j < n; j++){
					XmlNode attr = attributes.Item(j);
					String sAttributeName  = attr.LocalName;
					String sAttributeValue = attr.Value;
					if (sAttributeName.Equals("name")){
						sName = sAttributeValue;
					}
					else if (sAttributeName.Equals("type")){
						sType = sAttributeValue;
					}
				}
				mElements[i].name = sName;
				mElements[i].type = sType;
				mElements[i].value = sValue;
			}
			return mElements;
		}//getSimulationOutput


		/// <summary>
		/// Get the hash map of the input or output of name-value pairs for the simulation. 
		/// </summary>
		/// <param name="input">holds whether to get input or output of OSsL. If true, will get the input.</param>
		/// <returns>the hash map of the input or output of name-value pairs for the simulation.</returns>
		public Hashtable getInputOrOutput(bool input){
			XmlElement eleInputOrOutput	= null;
			if(input){
				if(m_inputHashMap != null) return m_inputHashMap;
				eleInputOrOutput = (XmlElement)XMLUtil.findChildNode(m_eRoot, "input");
				m_inputHashMap = new Hashtable();
			}
			else{
				if(m_outputHashMap != null) return m_outputHashMap;
				eleInputOrOutput	= (XmlElement)XMLUtil.findChildNode(m_eRoot, "output");
				m_outputHashMap = new Hashtable();
			}
			XmlNodeList nls	= eleInputOrOutput.GetElementsByTagName("el");
			int iNls	= nls==null?0:nls.Count;
			for(int i = 0; i	< iNls;	i++){
				XmlElement eEl = (XmlElement)(nls.Item(i));
				XmlNamedNodeMap	attributes =  eEl.Attributes;
				int n =attributes.Count;
				string sName	= "";
				string sValue = "";
				string sType	= "string";
				for (int	j =	0; j < n; j++){
					XmlNode	attr = attributes.Item(j);
					string sAttributeName  =	attr.LocalName;
					string sAttributeValue =	attr.Value;
					if (sAttributeName.Equals("name")){
						sName = sAttributeValue;
					}
					else if (sAttributeName.Equals("type")){
						sType = sAttributeValue;
					}
				}
				if(sType.Equals("string")){
					sValue = XMLUtil.getElementValue(eEl);
				}
				else if(sType.Equals("link")){
					sValue = IOUtil.readStringFromURL(XMLUtil.getElementValue(eEl));
				}
				if(input) m_inputHashMap.Add(sName, sValue);
				else m_outputHashMap.Add(sName, sValue);
			}
			if(input) return m_inputHashMap;
			else return m_outputHashMap;
		}//getInputOrOutput

		/// <summary>
		/// Set the hash map of the input or output of name-value pairs for the simulation. 
		/// </summary>
		/// <param name="input">holds whether to set input or output of OSsL. If true, will set the input.</param>
		/// <param name="hashMap">hashMap holds the hash map to set. </param>
		public void setInputOrOutput(bool input, Hashtable hashMap){
			if(input) m_inputHashMap = hashMap;
			else m_outputHashMap = hashMap;
		}//setInputOrOutput

		/// <summary>
		/// Get the hash map of the inputs of name-value pairs for the simulation. 
		/// </summary>
		/// <returns>the hash map of the inputs of name-value pairs for the simulation.</returns>
		public Hashtable getInput(){
			return getInputOrOutput(true);	
		}//getInput

		/// <summary>
		/// Get the number of inputs of the simulation. 
		/// </summary>
		/// <returns>the number of inputs of the simulation. </returns>
		public int getInputNumber(){
			getInputOrOutput(true);
			return m_inputHashMap.Count;
		}//getInputNumber

		/// <summary>
		/// Get the string value from the input hash map of the simulation given the input name. 
		/// </summary>
		/// <param name="name">holds the input name of the simulation to be retrieved. </param>
		/// <returns>the string value from the input hash map of the simulation given the input name. </returns>
		public string getInputByName(string name){
			getInputOrOutput(true);
			return (string)m_inputHashMap[name];
		}//getInputByName

		/// <summary>
		/// Get the names of all the simulation inputs in an array of string. 
		/// </summary>
		/// <returns>the names of all the simulation inputs in an array of string. </returns>
		public string[] getInputNames(){
			getInputOrOutput(true);	
			System.Collections.ICollection nameSet = m_inputHashMap.Keys;
			string[] msName = new string[nameSet.Count];
			IDictionaryEnumerator dictionaryEnumerator = m_inputHashMap.GetEnumerator();
			int i = 0;
			while(dictionaryEnumerator.MoveNext()){
				msName[i] = (string)dictionaryEnumerator.Key;
				i++;
			}
			return msName;
		}//getInputNames

		/// <summary>
		/// Get the values of all the simulation inputs in an array of string. 
		/// </summary>
		/// <returns>the values of all the simulation inputs in an array of string. </returns>
		public string[] getInputValues(){
			getInputOrOutput(true);	
			System.Collections.ICollection valueCollection = m_inputHashMap.Values;
			string[] msValue = new string[valueCollection.Count];
			IDictionaryEnumerator dictionaryEnumerator = m_inputHashMap.GetEnumerator();
			int i = 0;
			while(dictionaryEnumerator.MoveNext()){
				msValue[i] = (string)dictionaryEnumerator.Value;
				i++;
			}
			return msValue;
		}//getInputValues

		/// <summary>
		/// Replace an input el element's value.
		/// </summary>
		/// <param name="name">holds the name of the input el element which value is to be replaced.</param>
		/// <param name="value">holds the new value of the input el element to replace. </param>
		/// <returns>whether the input el element value is replaced successfully.</returns>
		public bool replaceInputElementValue(string name, string value){
			getInputOrOutput(true);
			if(name == null) return false;
			if(value == null) return false;
			XmlElement eInput = (XmlElement)XMLUtil.findChildNode(m_eRoot, "input");
			if(eInput == null) return false;
			XmlNodeList nodeList = eInput.GetElementsByTagName("el");
			XmlElement eEl;
			int iNls = nodeList==null?0:nodeList.Count;
			for(int i = 0; i < iNls; i++){
				eEl = (XmlElement)nodeList.Item(i);
				if(eEl.GetAttribute("name").Equals(name)){
					XMLUtil.removeAllChildren(eEl);
					if(m_document == null) m_document = (XmlDocument)m_eRoot.ParentNode;
					eEl.AppendChild(m_document.CreateTextNode(value));
					m_inputHashMap.Remove(name);
					m_inputHashMap.Add(name, value);
					return true;
				}
			}
			return false;
		}//replaceInputElementValue


		/// <summary>
		/// Get the hash map of the outputs of name-value pairs for the simulation. 
		/// </summary>
		/// <returns>the hash map of the outputs of name-value pairs for the simulation.</returns>
		public Hashtable getOutput(){
			return getInputOrOutput(false);	
		}//getOutput

		/// <summary>
		/// Get the number of outputs of the simulation. 
		/// </summary>
		/// <returns>the number of outputs of the simulation. </returns>
		public int getOutputNumber(){
			getInputOrOutput(false);
			return m_outputHashMap.Count;
		}//getOutputNumber

		/// <summary>
		/// Get the string value from the output hash map of the simulation given the output name. 
		/// </summary>
		/// <param name="name">holds the output name of the simulation to be retrieved.</param>
		/// <returns>the string value from the output hash map of the simulation given the output name.</returns>
		public string getOutputByName(string name){
			getInputOrOutput(false);
			return (string)m_outputHashMap[name];
		}//getOutputByName

		/// <summary>
		/// Get the names of all the simulation outputs in an array of string. 
		/// </summary>
		/// <returns>the names of all the simulation outputs in an array of string. </returns>
		public string[] getOutputNames(){
			getInputOrOutput(false);	
			System.Collections.ICollection nameSet = m_outputHashMap.Keys;
			string[] msName = new string[nameSet.Count];
			IDictionaryEnumerator dictionaryEnumerator = m_outputHashMap.GetEnumerator();
			int i = 0;
			while(dictionaryEnumerator.MoveNext()){
				msName[i] = (string)dictionaryEnumerator.Key;
				i++;
			}
			return msName;
		}//getOutputNames

		/// <summary>
		/// Get the values of all the simulation outputs in an array of string. 
		/// </summary>
		/// <returns>the values of all the simulation outputs in an array of string. </returns>
		public string[] getOutputValues(){
			getInputOrOutput(false);	
			System.Collections.ICollection valueCollection = m_outputHashMap.Values;
			string[] msValue = new string[valueCollection.Count];
			IDictionaryEnumerator dictionaryEnumerator = m_outputHashMap.GetEnumerator();
			int i = 0;
			while(dictionaryEnumerator.MoveNext()){
				msValue[i] = (string)dictionaryEnumerator.Value;
				i++;
			}
			return msValue;
		}//getOutputValues

		/// <summary>
		/// Replace an output el element's value.
		/// </summary>
		/// <param name="name">holds the name of the output el element which value is to be replaced. </param>
		/// <param name="value">holds the new value of the output el element to replace.  </param>
		/// <returns>whether the output el element value is replaced successfully.</returns>
		public bool replaceOutputElementValue(string name, string value){
			getInputOrOutput(false);
			if(name == null) return false;
			if(value == null) return false;
			XmlElement eOutput = (XmlElement)XMLUtil.findChildNode(m_eRoot, "output");
			if(eOutput == null) return false;
			XmlNodeList nodeList = eOutput.GetElementsByTagName("el");
			XmlElement eEl;
			int iNls = nodeList==null?0:nodeList.Count;
			for(int i = 0; i < iNls; i++){
				eEl = (XmlElement)nodeList.Item(i);
				if(eEl.GetAttribute("name").Equals(name)){
					XMLUtil.removeAllChildren(eEl);
					if(m_document == null) m_document = (XmlDocument)m_eRoot.ParentNode;
					eEl.AppendChild(m_document.CreateTextNode(value));
					m_outputHashMap.Remove(name);
					m_outputHashMap.Add(name, value);
					return true;
				}
			}
			return false;
		}//replaceOutputElementValue



	}//class OSsLReader
}//namespace