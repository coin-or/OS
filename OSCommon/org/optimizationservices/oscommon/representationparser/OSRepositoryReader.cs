using System;
using System.Collections;
using System.Xml;

using org.optimizationservices.oscommon.util;
using org.optimizationservices.oscommon.localinterface;
using org.optimizationservices.oscommon.datastructure.osrepository;
using org.optimizationservices.oscommon.datastructure.osgeneral;

namespace org.optimizationservices.oscommon.representationparser{
	///	<summary>
	///	The	<c>OSRepositoryReader</c> class	parses an osRepository instance	into a DOM tree	and
	///	provides a set of "get"	methods	that can be	
	///	used to	retrieve different pieces of information of	the	instance.
	///	@author	Jun	Ma	
	///	@version 1.0, 09/01/2005
	///	@since OS 1.0
	///	@copyright (c) 2005
	///	</summary>
	public class OSRepositoryReader	: OSgLReader{		
		/// <summary>
		/// m_osRepository holds the standard OSRepository, which is a local interface for 
		/// storing Optimization Services Repository. 
		/// </summary>
		protected OSRepository m_osRepository = null;

		///	<summary>
		///	constructor.
		///	</summary>
		///	<param name="validate">holds whether the reader	should be validating against the schema	or not.</param>
		public OSRepositoryReader(bool validate){
			m_bXsdValidate = validate;
		}//constructor
	
		///	<summary>
		///	Default	constructor. 
		///	</summary>
		public OSRepositoryReader(){
		}//constructor

		/// <summary>
		/// get the standard OSRepository, a local interface for 
		/// storing Optimization Services Repository.
		/// </summary>
		/// <returns>the OSRepository. </returns>
		public OSRepository getOSRepository(){
			if(m_osRepository != null){
				return m_osRepository;
			}
			m_osRepository = new OSRepository();
			if(!m_osRepository.setDescription(getDescription())) throw new Exception("setDescription Unsuccessful");
			if(!m_osRepository.setNews(getNews())) throw new Exception("setNews Unsuccessful");
			if(!m_osRepository.setInstances(getInstances())) throw new Exception("setInstances Unsuccessful");
			return m_osRepository;
		}//getOSRepository

		/// <summary>
		/// Get the OSRepository description. 
		/// </summary>
		/// <returns>the OSRepository description; null or empty string if none. </returns>
		public string getDescription(){
			XmlElement eDescription = (XmlElement)XMLUtil.findChildNode(m_eRoot, "description");
			if(eDescription == null) return null;
			String sDescription = XMLUtil.getElementValue(eDescription);
			return sDescription;
		}//getDescription

		/// <summary>
		/// Get the OSRepository news. 
		/// @see org.optimizationservices.oscommon.datastructure.osgeneral.NewsElement
		/// </summary>
		/// <returns>the news element array. Each element of the array corresponds to 
		/// a news element; null if none. </returns>
		public NewsElement[] getNews(){
			XmlElement eNews = (XmlElement)XMLUtil.findChildNode(m_eRoot, "news");
			if(eNews == null) return null;
			XmlNodeList nls = eNews.GetElementsByTagName("el");
			if(nls == null) return null;
			int iNls	= nls.Count;
			if(iNls <= 0) return null;
			NewsElement[] mEl = new NewsElement[iNls];
			for(int i = 0; i < iNls; i++){
				mEl[i] = new NewsElement();
				XmlElement eEl = (XmlElement)(nls.Item(i));
				XmlNamedNodeMap	attributes =  eEl.Attributes;
				int n =attributes.Count;
				String sValue = XMLUtil.getElementValue(eEl);
				DateTime time = new DateTime(1970, 1, 1, 1, 1, 1);
				for (int j = 0; j < n; j++){
					XmlNode	attr = attributes.Item(j);
					String sAttributeName  = attr.LocalName;
					String sAttributeValue = attr.Value;
					if (sAttributeName.Equals("time")){
						time = XMLUtil.createNativeDateTime(sAttributeValue);
					}
				}
				mEl[i].value = sValue;
				mEl[i].time = time;
			}
			return mEl;
		}//getNews

		/// <summary>
		/// Get the OSRepository instances. 
		/// @see org.optimizationservices.oscommon.datastructure.osrepository.RepositoryInstance
		/// </summary>
		/// <returns>the instance array. Each element of the array corresponds to 
		/// an instance entry; null if none. 
		/// </returns>
		public RepositoryInstance[] getInstances(){
			ArrayList nls = XMLUtil.getChildElementsByTagName(m_eRoot, "instance");
			if(nls == null) return null;
			int iNls	= nls.Count;
			if(iNls <= 0) return null;
			RepositoryInstance[] mInstance = new RepositoryInstance[iNls];
			for(int i = 0; i < iNls; i++){
				mInstance[i] = new RepositoryInstance();
				XmlElement eInstance = (XmlElement)(nls[i]);
				mInstance[i].name = XMLUtil.getElementValueByName(eInstance, "name");
				mInstance[i].source = XMLUtil.getElementValueByName(eInstance, "source");
				mInstance[i].description = XMLUtil.getElementValueByName(eInstance, "description");
				mInstance[i].originalFileName = XMLUtil.getElementValueByName(eInstance, "originalFileName");
				mInstance[i].osDirectoty = XMLUtil.getElementValueByName(eInstance, "osDirectoty");
				mInstance[i].osFileName = XMLUtil.getElementValueByName(eInstance, "osFileName");
			}	
			return mInstance;
		}//getInstances

		/// <summary>
		/// Get an OSRepository instance. 
		/// @see org.optimizationservices.oscommon.datastructure.osrepository.RepositoryInstance
		/// </summary>
		/// <param name="instanceName">the name of the instance to get.  </param>
		/// <returns>the found instance, which is in the RepositoryInstance data structure. </returns>
		public RepositoryInstance getInstance(string instanceName){
			ArrayList nls = XMLUtil.getChildElementsByTagName(m_eRoot, "instance");
			if(nls == null) return null;
			int iNls	= nls.Count;
			if(iNls <= 0) return null;
			RepositoryInstance instance = new RepositoryInstance();
			for(int i = 0; i < iNls; i++){
				XmlElement eInstance = (XmlElement)(nls[i]);
				string sName = XMLUtil.getElementValueByName(eInstance, "name");
				if(sName.Equals(instanceName)){		
					instance.name = sName;
					instance.source = XMLUtil.getElementValueByName(eInstance, "source");
					instance.description = XMLUtil.getElementValueByName(eInstance, "description");
					instance.originalFileName = XMLUtil.getElementValueByName(eInstance, "originalFileName");
					instance.osDirectoty = XMLUtil.getElementValueByName(eInstance, "osDirectoty");
					instance.osFileName = XMLUtil.getElementValueByName(eInstance, "osFileName");
					return instance;
				}
			}
			return null;	
		}//getInstance
	}//class OSRepositoryReader
}//namespace