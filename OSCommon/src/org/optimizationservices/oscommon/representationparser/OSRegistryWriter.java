/**
 * @(#)OSRegistryWriter 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.representationparser;

import java.util.GregorianCalendar;
import java.util.Vector;

import org.optimizationservices.oscommon.datastructure.osgeneral.NewsElement;
import org.optimizationservices.oscommon.datastructure.osregistry.ServiceEntry;
import org.optimizationservices.oscommon.localinterface.OSBenchmark;
import org.optimizationservices.oscommon.localinterface.OSEntity;
import org.optimizationservices.oscommon.localinterface.OSProcess;
import org.optimizationservices.oscommon.localinterface.OSRegistry;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.XMLUtil;
import org.w3c.dom.Element;
import org.w3c.dom.ProcessingInstruction;

/**
 * The <code>OSRegistryWriter</code> class is used to construct an instance that follows 
 * the OSRegistry format. 
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */
public class OSRegistryWriter extends OSgLWriter{
	/**
	 * m_eOSRegistry holds the OSRegistry root element.
	 */
	protected Element m_eOSRegistry = null;
	
	/**
	 * m_eDescription holds the description element of the root.  
	 */
	protected Element m_eDescription = null;
	
	/**
	 * m_eNews holds the news element of the root. 
	 */
	protected Element m_eNews = null;
	
	
	/**
	 * Constructor.
	 */
	public OSRegistryWriter(){
		m_document = XMLUtil.createNewDocument();
		if(OSParameter.XSLT_LOCATION != null && OSParameter.XSLT_LOCATION.length() > 0){
			ProcessingInstruction xsltPI = m_document.createProcessingInstruction("xml-stylesheet",
	           "type=\"text/xsl\" href = \"" + OSParameter.XSLT_LOCATION + "OSRegistry.xslt\"");
			m_document.appendChild(xsltPI);     
		}
		m_eOSRegistry = createOSRegistryRoot();
		m_document.appendChild(m_eOSRegistry);
	}//constructor
	
	/**
	 * set the OSRegistry, a standard os registry data structure. 
	 * @param osRegistry holds the standard os registry data structure. 
	 * @return whether the OSRegistry is set successfully. 
	 */
	public boolean setOSRegistry(OSRegistry osRegistry) throws Exception{
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
	public boolean setDescription(String description){
		try{
			XMLUtil.removeChildrenByName(m_eOSRegistry, "description");
			Element eDescription = createDescription(description);
			m_eOSRegistry.insertBefore(eDescription, m_eOSRegistry.getFirstChild());
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;

	}//setDescription

	/**
	 * Add a news element. 
	 * @param time holds the time. 
	 * @param value holds the news element value. 
	 * 
	 * @return whether the news is added successfully.  
	 */
	public boolean addNewsElement(GregorianCalendar time, String value){
		m_eNews.appendChild(createNewsEl(time, value));
		return true;
	}//addNewsElement
	
	/**
	 * Set the OSRegistry news. 
	 * 
	 * @newsElements holds an array of news elements. 
	 * Each element of the array corresponds to a news element. 
	 * @return whether the news is set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osgeneral.NewsElement
	 */
	public boolean setNews(NewsElement[] newsElements){
		if(newsElements == null || newsElements.length <= 0){
			XMLUtil.removeChildrenByName(m_eOSRegistry, "news");
			return true;
		}
		for(int i = 0; i < newsElements.length; i++){
			addNewsElement(newsElements[i].time, newsElements[i].value);
		}
		return true;
	}//setNews
	
	/**
	 * Set the OSRegistry services. 
	 * 
	 * @services holds an array of services. 
	 * Each element of the array corresponds to a service entry. 
	 * @return whether the services are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osregistry.ServiceEntry
	 */
	public boolean setServices(ServiceEntry[] services){
		if(services == null || services.length <= 0){
			XMLUtil.removeChildrenByName(m_eOSRegistry, "service");
			return true;
		}
		XMLUtil.removeChildrenByName(m_eOSRegistry, "service");
		for(int i = 0; i < services.length; i++){
			if(!addService(services[i])) return false;		
		}
		return true;
	}//setServices 
	
	/**
	 * Add an OSRegistry service. 
	 * 
	 * @service holds a service to add. 
	 * @return whether the service is added successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osregistry.ServiceEntry
	 */
	public boolean addService(ServiceEntry service){
		if(service == null || service.osel == null) return false;
		deleteService(service.osel.getServiceURI());
		Element eService = createService(service.osel.entityHeader.serviceName, service.osel.entityHeader.serviceURI);	
		if(service.osel != null){
			Element eOSeLCopy = null;
			OSeLWriter oselWriter = new OSeLWriter();
			try{
				oselWriter.setOSEntity(service.osel);
			}
			catch (Exception e){
				e.printStackTrace();
				return false;
			}
			eOSeLCopy =  (Element)m_document.importNode(oselWriter.m_eOSeL, true);
			XMLUtil.removeAllAttributes(eOSeLCopy);
			XMLUtil.removeChildrenByName(eService, "osel");
			eService.appendChild(eOSeLCopy);
		}
		if(service.ospl != null){
			Element eOSpLCopy = null;
			OSpLWriter osplWriter = new OSpLWriter();
			try {
				osplWriter.setOSProcess(service.ospl);
			} 
			catch (Exception e) {
				e.printStackTrace();
			}
			eOSpLCopy =  (Element)m_document.importNode(osplWriter.m_eOSpL, true);
			XMLUtil.removeAllAttributes(eOSpLCopy);
			XMLUtil.removeChildrenByName(eService, "ospl");
			eService.appendChild(eOSpLCopy);
		}		
		if(service.osbl != null){
			Element eOSbLCopy = null;
			OSbLWriter osblWriter = new OSbLWriter();
			try {
				osblWriter.setOSBenchmark(service.osbl);
			} 
			catch (Exception e) {
				e.printStackTrace();
			}
			eOSbLCopy =  (Element)m_document.importNode(osblWriter.m_eOSbL, true);
			XMLUtil.removeAllAttributes(eOSbLCopy);
			XMLUtil.removeChildrenByName(eService, "osbl");
			eService.appendChild(eOSbLCopy);
		}
		m_eOSRegistry.appendChild(eService);
		return true;
	}//addService
	
	/**
	 * Delete an OSRegistry service. 
	 * 
	 * @serviceURI holds the uri of the service to delete.  
	 * @return whether the service is deleted successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osregistry.ServiceEntry
	 */
	public boolean deleteService(String serviceURI){
		if(serviceURI == null) return true;
		Vector<Element> nls = XMLUtil.getChildElementsByTagName(m_eOSRegistry, "service");
		if(nls == null) return true;
		int iNls	= nls.size();
		if(iNls <= 0) return true;
		for(int i = 0; i < iNls; i++){
			Element eService = (Element)(nls.elementAt(i));
			Element eOSeL = (Element)XMLUtil.findChildNode(eService, "osel");
			if(eOSeL == null) continue;
			Element eEntityHeader = (Element)XMLUtil.findChildNode(eOSeL, "entityHeader");
			if(eOSeL == null) continue;
			String sServiceURI = XMLUtil.getElementValueByName(eEntityHeader, "serviceURI");
			if(sServiceURI != null && sServiceURI.equals(serviceURI)){	
				m_eOSRegistry.removeChild(eService);
				return true;
			}
		}
		return true;
	}//deleteService
	
	/**
	 * Create the osRegistry root element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the osRegistry element.
	 */
	protected Element createOSRegistryRoot(){
		Element eOSRegistry = XMLUtil.createOSxLRootElement(m_document, "osRegistry");
		m_eDescription = createDescription("OS Registry in OSRegistry format.");
		eOSRegistry.appendChild(m_eDescription);
		m_eNews = createNews();
		eOSRegistry.appendChild(m_eNews);
		return eOSRegistry;
	}//createOSRegistryRoot
	
	/**
	 * Create the description element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @param description holds the description string. 
	 * @return the description element.
	 */
	protected Element createDescription(String description){
		Element eDescription = m_document.createElement("description");
		eDescription.appendChild(m_document.createTextNode(description));
		return eDescription;
	}//createDescription

	/**
	 * Create the news element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the news element.
	 */
	protected Element createNews(){
		Element eNews = m_document.createElement("news");
		return eNews;
	}//createNews
	
	/**
	 * Create the news el element and its most basic required structure.
	 * @param time holds the time. 
	 * @param value holds the news value. 
	 * 
	 * @return the news el element. 
	 */
	protected Element createNewsEl(GregorianCalendar time, String value){
		Element eEl = m_document.createElement("el");
		eEl.setAttribute("time", XMLUtil.createXSDateTime(time));
		eEl.appendChild(m_document.createTextNode(value));
		return eEl;
	}//createNewsEl
	
	/**
	 * Create the service element and its most basic required structure.
	 * 
	 * @param serviceURI holds the service uri.
	 * @param serviceName holds the service name.
	 * @return the service element.
	 */
	protected Element createService(String serviceURI, String serviceName){
		Element eService = m_document.createElement("service");		
		try{
			OSEntity osEntity = new OSEntity();
			osEntity.entityHeader.serviceName = serviceName;
			osEntity.entityHeader.serviceURI = serviceURI;
			OSeLWriter oselWriter = new OSeLWriter();
			oselWriter.setOSEntity(osEntity);
			Element eOSeLCopy =  (Element)m_document.importNode(oselWriter.m_eOSeL, true);
			XMLUtil.removeAllAttributes(eOSeLCopy);
			eService.appendChild(eOSeLCopy);
		}
		catch(Exception e){
			e.printStackTrace();
		}
		return eService;
	}//createService
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		OSRegistryWriter osRegistryWriter = new OSRegistryWriter();
		String sFileName = OSParameter.CODE_HOME + "OSRepository/test/osregistry/osregistry.xml";
		
		if(!osRegistryWriter.setDescription("registry description")) System.out.println("description!");
		for(int i = 0; i < 3; i++){
			osRegistryWriter.addNewsElement(new GregorianCalendar(2006, 1, 2, 3, 4, i), "news: " + i);
		}
		ServiceEntry service = new ServiceEntry();
		OSeLReader oselReader = new OSeLReader(false);
		String sOSeLFileName = OSParameter.CODE_HOME + "OSRepository/test/osel/osel.osel";
		if(!oselReader.readFile(sOSeLFileName)) System.out.println("reading");
		OSEntity osEntity = null;
		try {
			osEntity = oselReader.getOSEntity();
		} 
		catch (Exception e) {
			e.printStackTrace();
		}
		service.osel = osEntity;
		
		OSpLReader osplReader = new OSpLReader(false);
		String sOSpLFileName = OSParameter.CODE_HOME + "OSRepository/test/ospl/ospl.ospl";
		if(!osplReader.readFile(sOSpLFileName)) System.out.println("reading");
		OSProcess osProcess = null;
		try {
			osProcess = osplReader.getOSProcess();
		} 
		catch (Exception e) {
			e.printStackTrace();
		}
		service.ospl = osProcess;
		
		OSbLReader osblReader = new OSbLReader(false);
		String sOSbLFileName = OSParameter.CODE_HOME + "OSRepository/test/osbl/osbl.osbl";
		if(!osblReader.readFile(sOSbLFileName)) System.out.println("reading");
		OSBenchmark osBenchmark = null;
		try {
			osBenchmark = osblReader.getOSBenchmark();
		} 
		catch (Exception e) {
			e.printStackTrace();
		}
		service.osbl = osBenchmark;
		osRegistryWriter.addService(service);
		service.osel.setServiceURI("xxx2");
		osRegistryWriter.addService(service);
		
		
		////////////////////
		
		OSRegistryReader osRegistryReader = new OSRegistryReader(false);
		if(!osRegistryReader.readFile(sFileName)) System.out.println("reading");
		OSRegistry osRegistry;
		try {
			osRegistry = osRegistryReader.getOSRegistry();
			if(!osRegistryWriter.setOSRegistry(osRegistry)) System.out.println("setOSRegistry");
		} 
		catch (Exception e) {
			e.printStackTrace();
		}
		
		////////////////////
		//osregistryWriter.writeToStandardOutput();
		System.out.println(osRegistryWriter.writeToString());
	}//main
	
}//class OSRegistryWriter
