using System;
using System.Collections;
using System.Xml;
using org.optimizationservices.oscommon.util;
using org.optimizationservices.oscommon.localinterface;
using org.optimizationservices.oscommon.datastructure.osregistry;
using org.optimizationservices.oscommon.datastructure.osgeneral;

namespace org.optimizationservices.oscommon.representationparser{
	/// <summary>
	/// The <c>OSRegistryWriter</c> class is used to construct an instance that follows 
	/// the OSRegistry format. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OSRegistryWriter : OSgLWriter{
		/// <summary>
		/// m_eOSRegistry holds the osRegistry root element.
		/// </summary>
		protected internal XmlElement m_eOSRegistry = null;

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
		public OSRegistryWriter(){
			m_document = XMLUtil.createNewDocument();
			if(OSParameter.XSLT_LOCATION != null && OSParameter.XSLT_LOCATION.Length > 0){
				XmlProcessingInstruction xsltPI = m_document.CreateProcessingInstruction("xml-stylesheet",
					"type=\"text/xsl\" href = \"" + OSParameter.XSLT_LOCATION + "OSRegistry.xslt\"");
				m_document.AppendChild(xsltPI);     
			}
			m_eOSRegistry = createOSRegistryRoot();
			m_document.AppendChild(m_eOSRegistry);
		}//constructor

		/// <summary>
		/// set the OSRegistry, a standard os registry data structure. 
		/// </summary>
		/// <param name="osRegistry">holds the standard os registry data structure. </param>
		/// <returns>whether the OSRegistry is set successfully. </returns>
		public bool setOSRegistry(OSRegistry osRegistry){
			if(!setDescription(osRegistry.getDescription())){ 
				throw new Exception("setDescription Unsuccessful");
			}
			if(!setNews(osRegistry.getNews())){ 
				throw new Exception("setNews Unsuccessful");
			}
			if(!setServices(osRegistry.getServices())){ 
				throw new Exception("setServices Unsuccessful");
			}
			return true;
		}//setOSRegistry

		/**
	 * Set the description element. If the element is already there, it will reset it. If the element
	 * is not there (e.g. optional element), it will add it. 
	 * 
	 * @param description holds the description of the os registry.
	 * @return whether the description is set successfully.
	 */
		public bool setDescription(String description){
			try{
				XMLUtil.removeChildrenByName(m_eOSRegistry, "description");
				XmlElement eDescription = createDescription(description);
				m_eOSRegistry.InsertBefore(eDescription, m_eOSRegistry.FirstChild);
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
		public bool addNewsElement(DateTime time, String value){
			m_eNews.AppendChild(createNewsEl(time, value));
			return true;
		}//addNewsElement

		/// <summary>
		/// Set the OSRegistry news. 
		/// @see org.optimizationservices.oscommon.datastructure.osgeneral.NewsElement
		/// </summary>
		/// <param name="newsElements">holds an array of news elements. 
		/// Each element of the array corresponds to a news element. 
		/// </param>
		/// <returns>whether the news is set successfully or not. </returns>
		public bool setNews(NewsElement[] newsElements){
			if(newsElements == null || newsElements.Length <= 0){
				XMLUtil.removeChildrenByName(m_eOSRegistry, "news");
				return true;
			}
			for(int i = 0; i < newsElements.Length; i++){
				addNewsElement(newsElements[i].time, newsElements[i].value);
			}
			return true;
		}//setNews

	
		/// <summary>
		/// Set the OSRegistry services. 
		/// @see org.optimizationservices.oscommon.datastructure.osregistry.ServiceEntry
		/// </summary>
		/// <param name="services">holds an array of services. 
		/// Each element of the array corresponds to a service entry. 
		/// </param>
		/// <returns>whether the services are set successfully or not. </returns>
		public bool setServices(ServiceEntry[] services){
			if(services == null || services.Length <= 0){
				XMLUtil.removeChildrenByName(m_eOSRegistry, "service");
				return true;
			}
			XMLUtil.removeChildrenByName(m_eOSRegistry, "service");
			for(int i = 0; i < services.Length; i++){
				if(!addService(services[i])) return false;		
			}
			return true;
		}//setServices 

		/// <summary>
		/// Add an OSRegistry service.
		/// @see org.optimizationservices.oscommon.datastructure.osregistry.ServiceEntry
		/// </summary>
		/// <param name="service">holds a service to add. </param>
		/// <returns>whether the service is added successfully or not. </returns>
		public bool addService(ServiceEntry service){
			if(service == null || service.osel == null) return false;
			deleteService(service.osel.getServiceURI());
			XmlElement eService = createService(service.osel.entityHeader.serviceName, service.osel.entityHeader.serviceURI);	
			if(service.osel != null){
				XmlElement eOSeLCopy = null;
				OSeLWriter oselWriter = new OSeLWriter();
				try{
					oselWriter.setOSEntity(service.osel);
				}
				catch (Exception e){
					Console.WriteLine(e.ToString());
					return false;
				}
				eOSeLCopy =  (XmlElement)m_document.ImportNode(oselWriter.m_eOSeL, true);
				XMLUtil.removeAllAttributes(eOSeLCopy);
				XMLUtil.removeChildrenByName(eService, "osel");
				eService.AppendChild(eOSeLCopy);
			}
			if(service.ospl != null){
				XmlElement eOSpLCopy = null;
				OSpLWriter osplWriter = new OSpLWriter();
				try {
					osplWriter.setOSProcess(service.ospl);
				} 
				catch (Exception e) {
					Console.WriteLine(e.ToString());
				}
				eOSpLCopy =  (XmlElement)m_document.ImportNode(osplWriter.m_eOSpL, true);
				XMLUtil.removeAllAttributes(eOSpLCopy);
				XMLUtil.removeChildrenByName(eService, "ospl");
				eService.AppendChild(eOSpLCopy);
			}		
			if(service.osbl != null){
				XmlElement eOSbLCopy = null;
				OSbLWriter osblWriter = new OSbLWriter();
				try {
					osblWriter.setOSBenchmark(service.osbl);
				} 
				catch (Exception e) {
					Console.WriteLine(e.ToString());
				}
				eOSbLCopy =  (XmlElement)m_document.ImportNode(osblWriter.m_eOSbL, true);
				XMLUtil.removeAllAttributes(eOSbLCopy);
				XMLUtil.removeChildrenByName(eService, "osbl");
				eService.AppendChild(eOSbLCopy);
			}
			m_eOSRegistry.AppendChild(eService);
			return true;
		}//addService

		/// <summary>
		/// Delete an OSRegistry service. 
		/// @see org.optimizationservices.oscommon.datastructure.osregistry.ServiceEntry
		/// </summary>
		/// <param name="serviceURI">holds the uri of the service to delete.  </param>
		/// <returns>whether the service is deleted successfully or not. </returns>
		public bool deleteService(String serviceURI){
			if(serviceURI == null) return true;
			ArrayList nls = XMLUtil.getChildElementsByTagName(m_eOSRegistry, "service");
			if(nls == null) return true;
			int iNls	= nls.Count;
			if(iNls <= 0) return true;
			for(int i = 0; i < iNls; i++){
				XmlElement eService = (XmlElement)(nls[i]);
				XmlElement eOSeL = (XmlElement)XMLUtil.findChildNode(eService, "osel");
				if(eOSeL == null) continue;
				XmlElement eEntityHeader = (XmlElement)XMLUtil.findChildNode(eOSeL, "entityHeader");
				if(eOSeL == null) continue;
				String sServiceURI = XMLUtil.getElementValueByName(eEntityHeader, "serviceURI");
				if(sServiceURI != null && sServiceURI.Equals(serviceURI)){	
					m_eOSRegistry.RemoveChild(eService);
					return true;
				}
			}
			return true;
		}//deleteService

		/// <summary>
		/// Create the osRegistry root element and its most basic required structure.
		/// </summary>
		/// <returns>the osRegistry element.</returns>
		protected XmlElement createOSRegistryRoot(){
			XmlElement eOSRegistry = XMLUtil.createOSxLRootElement(m_document, "osRegistry");
			m_eDescription = createDescription("OS Registry in OSRegistry format.");
			eOSRegistry.AppendChild(m_eDescription);
			m_eNews = createNews();
			eOSRegistry.AppendChild(m_eNews);
			return eOSRegistry;
		}//createOSRegistryRoot

		/// <summary>
		/// Create the description element and its most basic required structure.
		/// </summary>
		/// <param name="description">holds the description string. </param>
		/// <returns>the description element.</returns>
		protected XmlElement createDescription(String description){
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
		protected XmlElement createNewsEl(DateTime time, String value){
			XmlElement eEl = m_document.CreateElement("el");
			eEl.SetAttribute("time", XMLUtil.createXSDateTime(time));
			eEl.AppendChild(m_document.CreateTextNode(value));
			return eEl;
		}//createNewsEl

		/// <summary>
		/// Create the service element and its most basic required structure.
		/// </summary>
		/// <param name="serviceURI">holds the service uri.</param>
		/// <param name="serviceName">holds the service name.</param>
		/// <returns>the service element.</returns>
		protected XmlElement createService(String serviceURI, String serviceName){
			XmlElement eService = m_document.CreateElement("service");		
			try{
				OSEntity osEntity = new OSEntity();
				osEntity.entityHeader.serviceName = serviceName;
				osEntity.entityHeader.serviceURI = serviceURI;
				OSeLWriter oselWriter = new OSeLWriter();
				oselWriter.setOSEntity(osEntity);
				XmlElement eOSeLCopy =  (XmlElement)m_document.ImportNode(oselWriter.m_eOSeL, true);
				XMLUtil.removeAllAttributes(eOSeLCopy);
				eService.AppendChild(eOSeLCopy);
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
			}
			return eService;
		}//createService

	}//class OSRegistryWriter
}//namespace
