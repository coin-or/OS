using System;
using System.Collections;
using System.Xml;

using org.optimizationservices.oscommon.localinterface;
using org.optimizationservices.oscommon.util;

namespace org.optimizationservices.oscommon.representationparser{
	///	<summary>
	///	The	<c>OSParameterReader</c> class parses an osParameter instance into a DOM tree and
	///	provides a set of "get" methods that can be used to retrieve different 
	///	pieces of information of the instance.
	///	@author	Jun	Ma	
	///	@version 1.0, 09/01/2005
	///	@since OS 1.0
	///	@copyright (c) 2005
	///	</summary>
	public class OSParameterReader	: OSgLReader{
		///	<summary>
		///	m_osParameterHashMap holds a hash map of os parameters.
		///	</summary>
		protected Hashtable	m_osParameterHashMap = null;

		///	<summary>
		///	m_osParameterDescriptionHashMap holds a hash map of os parameter descriptions.
		///	</summary>
		protected Hashtable	m_osParameterDescriptionHashMap = null;

		///	<summary>
		///	constructor.
		///	</summary>
		///	<param name="validate">holds whether the reader	should be validating against the schema	or not.</param>
		public OSParameterReader(bool validate){
			m_bXsdValidate = validate;
		}//constructor
	
		///	<summary>
		///	Default	constructor. 
		///	</summary>
		public OSParameterReader(){
		}//constructor

		/// <summary>
		/// Get the hash map of os parameters. 
		/// </summary>
		/// <returns>the hash map of os parameters.</returns>
		public Hashtable getOSParameters(){
			if(m_osParameterHashMap != null) return m_osParameterHashMap;
			m_osParameterHashMap = new Hashtable();
			m_osParameterDescriptionHashMap = new Hashtable();

			ArrayList vNodeList = XMLUtil.getChildElementsByTagName(m_eRoot, "param"); 
			int iNls = vNodeList==null?0:vNodeList.Count;
			for(int i = 0; i < iNls; i++){
				XmlElement eParam = (XmlElement)(vNodeList[i]);
				XmlNamedNodeMap	attributes =  eParam.Attributes;
				int n =attributes.Count;
				string sName = "";
				string sDescription = "";
				string sValue = XMLUtil.getElementValue(eParam);
				for (int j = 0; j < n; j++){
					XmlNode	attr = attributes.Item(j);
					string sAttributeName  = attr.LocalName;
					string sAttributeValue = attr.Value;
					if (sAttributeName.Equals("name")){
						sName = sAttributeValue;
					}
					else if (sAttributeName.Equals("description")){
						sDescription = sAttributeValue;
					}
				}
				m_osParameterHashMap.Add(sName, sValue);
				m_osParameterDescriptionHashMap.Add(sName, sDescription);
			}
			return m_osParameterHashMap;
		}//getOSParameters

		/// <summary>
		/// Get the number of os parameters.  
		/// </summary>
		/// <returns>the number of os parameters. </returns>
		public int getOSParameterNumber(){
			getOSParameters();
			return m_osParameterHashMap.Count;
		}//getOSParameterNumber

		/// <summary>
		/// Get the string value from the os parameter hash map. 
		/// </summary>
		/// <param name="name">holds the name of option to get. </param>
		/// <returns>string value from the os parameter hash map, null if none. </returns>
		public string getOSParameterValueByName(string name){
			getOSParameters();
			if(m_osParameterHashMap.Contains(name)){
				return (string)m_osParameterHashMap[name];
			}
			else{ 
				return null;
			}
		}//getOSParameterValueByName

		/// <summary>
		/// Get the string value from the os parameter hash map. 
		/// </summary>
		/// <param name="name">holds the name of option to get. </param>
		/// <returns>string value from the os parameter hash map, null if none. </returns>
		public string getOSParameterDescriptionByName(string name){
			getOSParameters();
			if(m_osParameterDescriptionHashMap.Contains(name)){
				return (string)m_osParameterDescriptionHashMap[name];
			}
			else{ 
				return null;
			}
		}//getOSParameterDescriptionByName

		/// <summary>
		/// Get the names of all os parameters. 
		/// </summary>
		/// <returns>the names of all os parameters. </returns>
		public string[] getOSParameterNames(){
			getOSParameters();	
			System.Collections.ICollection nameCollection = m_osParameterHashMap.Keys;
			string[] msName = new string[nameCollection.Count];
			IDictionaryEnumerator dictionaryEnumerator = m_osParameterHashMap.GetEnumerator();
			int i = 0;
			while(dictionaryEnumerator.MoveNext()){
				msName[i] = (string)dictionaryEnumerator.Key;
				i++;
			}
			return msName;
		}//getOSParameterNames

		/// <summary>
		/// Get the values of all os parameters. 
		/// </summary>
		/// <returns>the values of all os parameters. </returns>
		public string[] getOSParameterValues(){
			getOSParameters();	
			System.Collections.ICollection valueCollection = m_osParameterHashMap.Values;
			string[] msValue = new string[valueCollection.Count];
			IDictionaryEnumerator dictionaryEnumerator = m_osParameterHashMap.GetEnumerator();
			int i = 0;
			while(dictionaryEnumerator.MoveNext()){
				msValue[i] = (string)dictionaryEnumerator.Value;
				i++;
			}
			return msValue;
		}//getOSParameterValues

		/// <summary>
		/// Get the descriptions of all os parameters. 
		/// </summary>
		/// <returns>the descriptions of all os parameters. </returns>
		public string[] getOSParameterDescriptions(){
			getOSParameters();	
			System.Collections.ICollection descriptionCollection = m_osParameterDescriptionHashMap.Values;
			string[] msDescription = new string[descriptionCollection.Count];
			IDictionaryEnumerator dictionaryEnumerator = m_osParameterDescriptionHashMap.GetEnumerator();
			int i = 0;
			while(dictionaryEnumerator.MoveNext()){
				msDescription[i] = (string)dictionaryEnumerator.Value;
				i++;
			}
			return msDescription;
		}//getOSParameterDescriptions
	}//class OSParameterReader
}//namespace