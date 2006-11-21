using System;
using System.Collections;
using System.Xml;

using org.optimizationservices.oscommon.util;
using org.optimizationservices.oscommon.localinterface;
using org.optimizationservices.oscommon.datastructure.osregistry;
using org.optimizationservices.oscommon.datastructure.osgeneral;

namespace org.optimizationservices.oscommon.representationparser{
	///	<summary>
	///	The	<c>OSRegistryReader</c> class	parses an osRegistry instance	into a DOM tree	and
	///	provides a set of "get"	methods	that can be	
	///	used to	retrieve different pieces of information of	the	instance.
	///	@author	Jun	Ma	
	///	@version 1.0, 09/01/2005
	///	@since OS 1.0
	///	@copyright (c) 2005
	///	</summary>
	public class OSRegistryReader	: OSgLReader{		
		/// <summary>
		/// m_osRegistry holds the standard OSRegistry, which is a local interface for 
		/// storing Optimization Services Registry. 
		/// </summary>
		protected OSRegistry m_osRegistry = null;

		///	<summary>
		///	constructor.
		///	</summary>
		///	<param name="validate">holds whether the reader	should be validating against the schema	or not.</param>
		public OSRegistryReader(bool validate){
			m_bXsdValidate = validate;
		}//constructor
	
		///	<summary>
		///	Default	constructor. 
		///	</summary>
		public OSRegistryReader(){
		}//constructor

		/// <summary>
		/// get the standard OSRegistry, a local interface for 
		/// storing Optimization Services registry.
		/// @throws Exception if there are errors getting the OSRegistry.  
		/// </summary>
		/// <returns>the OSRegistry. </returns>
		public OSRegistry getOSRegistry(){
			if(m_osRegistry != null){
				return m_osRegistry;
			}
			m_osRegistry = new OSRegistry();
			if(!m_osRegistry.setDescription(getDescription())) throw new Exception("setDescription Unsuccessful");
			if(!m_osRegistry.setNews(getNews())) throw new Exception("setNews Unsuccessful");
			if(!m_osRegistry.setServices(getServices())) throw new Exception("setServices Unsuccessful");
			return m_osRegistry;
   		}//getOSRegistry

		/// <summary>
		/// Get the OSRegistry description. 
		/// </summary>
		/// <returns>the OSRegistry description; null or empty string if none. </returns>
		public String getDescription(){
			XmlElement eDescription = (XmlElement)XMLUtil.findChildNode(m_eRoot, "description");
			if(eDescription == null) return null;
			String sDescription = XMLUtil.getElementValue(eDescription);
			return sDescription;
		}//getDescription

		/// <summary>
		/// Get the OSRegistry news. 
		/// @see org.optimizationservices.oscommon.datastructure.osgeneral.NewsElement
		/// </summary>
		/// <returns>the news element array. Each element of the array corresponds to 
		/// a news element; null if none. 
		/// </returns>
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
		/// Get the OSRegistry services. 
		/// @see org.optimizationservices.oscommon.datastructure.osregistry.ServiceEntry
		/// </summary>
		/// <returns>the service array. Each element of the array corresponds to 
		/// a service entry; null if none. </returns>
		public ServiceEntry[] getServices(){
			ArrayList nls = XMLUtil.getChildElementsByTagName(m_eRoot, "service");
			if(nls == null) return null;
			int iNls	= nls.Count;
			if(iNls <= 0) return null;
			ServiceEntry[] mService = new ServiceEntry[iNls];
			for(int i = 0; i < iNls; i++){
				mService[i] = new ServiceEntry();
				XmlElement eService = (XmlElement)(nls[i]);
				
				XmlElement eOSeL = (XmlElement)XMLUtil.findChildNode(eService, "osel");
				if(eOSeL != null){
					OSeLReader oselReader = new OSeLReader(OSParameter.VALIDATE);
					oselReader.setRootElement(eOSeL);
					OSEntity osEntity;
					try {
						osEntity = oselReader.getOSEntity();
						mService[i].osel = osEntity;
					} 
					catch (Exception e){
						Console.WriteLine(e.ToString());
					}
				}
				XmlElement eOSpL = (XmlElement)XMLUtil.findChildNode(eService, "ospl");
				if(eOSpL != null){
					OSpLReader osplReader = new OSpLReader(OSParameter.VALIDATE);
					osplReader.setRootElement(eOSpL);
					OSProcess osProcess;
					try {
						osProcess = osplReader.getOSProcess();
						mService[i].ospl = osProcess;
					} 
					catch (Exception e){
						Console.WriteLine(e.ToString());
					}
				}
				XmlElement eOSbL = (XmlElement)XMLUtil.findChildNode(eService, "osbl");
				if(eOSbL != null){
					OSbLReader osblReader = new OSbLReader(OSParameter.VALIDATE);
					osblReader.setRootElement(eOSbL);
					OSBenchmark osBenchmark;
					try {
						osBenchmark = osblReader.getOSBenchmark();
						mService[i].osbl = osBenchmark;
					} 
					catch (Exception e){
						Console.WriteLine(e.ToString());
					}
				}

			}
			return mService;
		}//getServices

		/// <summary>
		/// Get an OSRegistry service. 
		/// @see org.optimizationservices.oscommon.datastructure.osregistry.ServiceEntry
		/// </summary>
		/// <param name="serviceURI">holds the uri of the service to get.  </param>
		/// <returns>the found service, which is in the ServiceEntry data structure.  </returns>
		public ServiceEntry getService(String serviceURI){
			ArrayList nls = XMLUtil.getChildElementsByTagName(m_eRoot, "service");
			if(nls == null) return null;
			int iNls	= nls.Count;
			if(iNls <= 0) return null;
			ServiceEntry service = new ServiceEntry();
			for(int i = 0; i < iNls; i++){
				XmlElement eService = (XmlElement)(nls[i]);
				XmlElement eOSeL = (XmlElement)XMLUtil.findChildNode(eService, "osel");
				if(eOSeL == null) continue;
				XmlElement eEntityHeader = (XmlElement)XMLUtil.findChildNode(eOSeL, "entityHeader");
				if(eOSeL == null) continue;
				String sServiceURI = XMLUtil.getElementValueByName(eEntityHeader, "serviceURI");
				if(sServiceURI != null && sServiceURI.Equals(serviceURI)){		
					if(eOSeL != null){
						OSeLReader oselReader = new OSeLReader(OSParameter.VALIDATE);
						oselReader.setRootElement(eOSeL);
						OSEntity osEntity;
						try {
							osEntity = oselReader.getOSEntity();
							service.osel = osEntity;
						} 
						catch (Exception e){
							Console.WriteLine(e.ToString());
						}
					}
					XmlElement eOSpL = (XmlElement)XMLUtil.findChildNode(eService, "ospl");
					if(eOSpL != null){
						OSpLReader osplReader = new OSpLReader(OSParameter.VALIDATE);
						osplReader.setRootElement(eOSpL);
						OSProcess osProcess;
						try {
							osProcess = osplReader.getOSProcess();
							service.ospl = osProcess;
						} 
						catch (Exception e){
							Console.WriteLine(e.ToString());
						}
					}
					XmlElement eOSbL = (XmlElement)XMLUtil.findChildNode(eService, "osbl");
					if(eOSbL != null){
						OSbLReader osblReader = new OSbLReader(OSParameter.VALIDATE);
						osblReader.setRootElement(eOSbL);
						OSBenchmark osBenchmark;
						try {
							osBenchmark = osblReader.getOSBenchmark();
							service.osbl = osBenchmark;
						} 
						catch (Exception e){
							Console.WriteLine(e.ToString());
						}
					}
					return service;
				}
			}
			return null;		
		}//getService
   	

	}//class OSRegistryReader
}//namespace