using System;
using System.Collections;
using System.Xml;
using org.optimizationservices.oscommon.util;
using org.optimizationservices.oscommon.localinterface;
using org.optimizationservices.oscommon.datastructure.osgeneral;
using org.optimizationservices.oscommon.datastructure.osrepository;

namespace org.optimizationservices.oscommon.representationparser{
	/// <summary>
	/// The <c>OSRepositoryWriter</c> class is used to construct an instance that follows 
	/// the OSRepository format. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OSRepositoryWriter : OSgLWriter{
		/// <summary>
		/// m_eOSRepository holds the osRepository root element.
		/// </summary>
		protected internal XmlElement m_eOSRepository = null;

		/// <summary>
		/// m_eDescription holds the description element of the root.  
		/// </summary>
		protected XmlElement m_eDescription = null;
	
		/// <summary>
		/// m_eNews holds the news element of the root. 
		/// </summary>
		protected XmlElement m_eNews = null;
	
		/// <summary>
		/// constructor. 
		/// </summary>
		public OSRepositoryWriter(){
			m_document = XMLUtil.createNewDocument();
			if(OSParameter.XSLT_LOCATION != null && OSParameter.XSLT_LOCATION.Length > 0){
				XmlProcessingInstruction xsltPI = m_document.CreateProcessingInstruction("xml-stylesheet",
					"type=\"text/xsl\" href = \"" + OSParameter.XSLT_LOCATION + "OSRepository.xslt\"");
				m_document.AppendChild(xsltPI);     
			}
			m_eOSRepository = createOSRepositoryRoot();
			m_document.AppendChild(m_eOSRepository);
		}//constructor

		/// <summary>
		/// set the OSRepository, a standard os repository data structure. 
		/// </summary>
		/// <param name="osRepository">holds the standard os repository data structure. </param>
		/// <returns>whether the OSRepository is set successfully. </returns>
		public bool setOSRepository(OSRepository osRepository){
			if(!setDescription(osRepository.getDescription())){ 
				throw new Exception("setDescription Unsuccessful");
			}
			if(!setNews(osRepository.getNews())){ 
				throw new Exception("setNews Unsuccessful");
			}
			if(!setInstances(osRepository.getInstances())){ 
				throw new Exception("setInstances Unsuccessful");
			}
			return true;
		}//setOSRepository

		/**
	 * Set the description element. If the element is already there, it will reset it. If the element
	 * is not there (e.g. optional element), it will add it. 
	 * 
	 * @param description holds the description of the os repository.
	 * @return whether the description is set successfully.
	 */
		public bool setDescription(string description){
			try{
				XMLUtil.removeChildrenByName(m_eOSRepository, "description");
				XmlElement eDescription = createDescription(description);
				m_eOSRepository.InsertBefore(eDescription, m_eOSRepository.FirstChild);
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
			return true;

		}//setDescription

		/// <summary>
		/// Add a news element. 
		/// </summary>
		/// <param name="time">holds the time. </param>
		/// <param name="value">holds the news element value. </param>
		/// <returns>whether the news is added successfully.  </returns>
		public bool addNewsElement(DateTime time, string value){
			m_eNews.AppendChild(createNewsEl(time, value));
			return true;
		}//addNewsElement

		/// <summary>
		/// Set the OSRepository news. 
		/// @see org.optimizationservices.oscommon.datastructure.osgeneral.NewsElement
		/// </summary>
		/// <param name="newsElements">holds an array of news elements. 
		/// Each element of the array corresponds to a news element. 
		/// </param>
		/// <returns>whether the news is set successfully or not. </returns>
		public bool setNews(NewsElement[] newsElements){
			if(newsElements == null || newsElements.Length <= 0){
				XMLUtil.removeChildrenByName(m_eOSRepository, "news");
				return true;
			}
			for(int i = 0; i < newsElements.Length; i++){
				addNewsElement(newsElements[i].time, newsElements[i].value);
			}
			return true;
		}//setNews

		/// <summary>
		/// Set the OSRepository instances. 
		/// @see org.optimizationservices.oscommon.datastructure.osrepository.RepositoryInstance
		/// </summary>
		/// <param name="instances">holds an array of instances. 
		/// Each element of the array corresponds to a instance entry. </param>
		/// <returns>whether the instances are set successfully or not. </returns>
		public bool setInstances(RepositoryInstance[] instances){
			if(instances == null || instances.Length <= 0){
				XMLUtil.removeChildrenByName(m_eOSRepository, "instance");
				return true;
			}
			XMLUtil.removeChildrenByName(m_eOSRepository, "instance");
			for(int i = 0; i < instances.Length; i++){
				if(!addInstance(instances[i])) return false;		
			}
			return true;
		}//setInstances 

		/// <summary>
		/// Add an OSRepository instance. 
		/// @see org.optimizationservices.oscommon.datastructure.osrepository.RepositoryInstance
		/// </summary>
		/// <param name="instance">holds a instance to add. </param>
		/// <returns>whether the instance is added successfully or not. </returns>
		public bool addInstance(RepositoryInstance instance){
			if(instance == null) return false;
			XmlElement eInstance = m_document.CreateElement("instance");
		
			XmlElement eName = m_document.CreateElement("name");
			eName.AppendChild(m_document.CreateTextNode(instance.name));
			eInstance.AppendChild(eName);
		
			XmlElement eSource = m_document.CreateElement("source");
			eSource.AppendChild(m_document.CreateTextNode(instance.source));
			eInstance.AppendChild(eSource);
		
			XmlElement eDescription = m_document.CreateElement("description");
			eDescription.AppendChild(m_document.CreateTextNode(instance.description));
			eInstance.AppendChild(eDescription);
		
			XmlElement eOriginalFileName = m_document.CreateElement("originalFileName");
			eOriginalFileName.AppendChild(m_document.CreateTextNode(instance.originalFileName));
			eInstance.AppendChild(eOriginalFileName);
		
			XmlElement eOSDirectory = m_document.CreateElement("osDirectoty");
			eOSDirectory.AppendChild(m_document.CreateTextNode(instance.osDirectoty));
			eInstance.AppendChild(eOSDirectory);
		
			XmlElement eOSFileName = m_document.CreateElement("osFileName");
			eOSFileName.AppendChild(m_document.CreateTextNode(instance.osFileName));
			eInstance.AppendChild(eOSFileName);
		
			m_eOSRepository.AppendChild(eInstance);
			return true;
		}//addInstance

		/// <summary>
		/// Delete an OSRepository instance. 
		/// @see org.optimizationservices.oscommon.datastructure.osrepository.RepositoryInstance
		/// </summary>
		/// <param name="instanceName">holds the name of the instance to delete.  </param>
		/// <returns>whether the instance is deleted successfully or not. </returns>
		public bool deleteInstance(string instanceName){
			if(instanceName == null) return true;
			ArrayList nls = XMLUtil.getChildElementsByTagName(m_eOSRepository, "instance");
			if(nls == null) return true;
			int iNls	= nls.Count;
			if(iNls <= 0) return true;
			for(int i = 0; i < iNls; i++){
				XmlElement eInstance = (XmlElement)(nls[i]);
				string sName = XMLUtil.getElementValueByName(eInstance, "name");
				if(sName.Equals(instanceName)){	
					XMLUtil.removeChildrenByName(eInstance, "name");
					return true;
				}
			}
			return true;
		}//deleteInstance

		/**
		 * Create the osRepository root element and its most basic required structure.
		 *
		 * </p>
		 *
		 * @return the osRepository element.
		 */
		protected XmlElement createOSRepositoryRoot(){
			XmlElement eOSRepository = XMLUtil.createOSxLRootElement(m_document, "osRepository");
			m_eDescription = createDescription("OS Repository in OSRepository format.");
			eOSRepository.AppendChild(m_eDescription);
			m_eNews = createNews();
			eOSRepository.AppendChild(m_eNews);
			return eOSRepository;
		}//createOSRepositoryRoot
	
		/// <summary>
		/// Create the description element and its most basic required structure.
		/// </summary>
		/// <param name="description">holds the description string. </param>
		/// <returns>the description element.</returns>
		protected XmlElement createDescription(string description){
			XmlElement eDescription = m_document.CreateElement("description");
			eDescription.AppendChild(m_document.CreateTextNode(description));
			return eDescription;
		}//createDescription

		/// <summary>
		/// Create the news element and its most basic required structure.
		/// </summary>
		/// <returns>the news element.</returns>
		protected XmlElement createNews(){
			XmlElement eNews = m_document.CreateElement("news");
			return eNews;
		}//createNews
	
		/// <summary>
		/// Create the news el element and its most basic required structure.
		/// </summary>
		/// <param name="time">holds the time. </param>
		/// <param name="value">holds the news value. </param>
		/// <returns>the news el element. </returns>
		protected XmlElement createNewsEl(DateTime time, string value){
			XmlElement eEl = m_document.CreateElement("el");
			eEl.SetAttribute("time", XMLUtil.createXSDateTime(time));
			eEl.AppendChild(m_document.CreateTextNode(value));
			return eEl;
		}//createNewsEl
	

	}//class OSRepositoryWriter
}//namespace
