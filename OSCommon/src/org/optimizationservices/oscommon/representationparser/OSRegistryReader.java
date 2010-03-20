/**
 * @(#)OSRegistryReader 1.0 03/14/2004
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
import org.optimizationservices.oscommon.util.IOUtil;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.XMLUtil;
import org.w3c.dom.Element;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

/**
 * The <c>OSRegistryReader</c> class parses an osRegistry instance into a DOM tree and
 * provides a set of "get" methods that can be used to retrieve different 
 * pieces of information of the instance.
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */
public class OSRegistryReader extends OSgLReader{	
	/**
	 * m_osRegistry holds the standard OSRegistry, which is a local interface for 
	 * storing Optimization Services Registry. 
	 */
	protected OSRegistry m_osRegistry = null;
	
	/**
	 * constructor
	 *
	 * </p>
	 *
	 * @param validate holds whether the reader should be validating against the schema or not.
	 */
	public OSRegistryReader(boolean validate){
		m_bXsdValidate = validate;
	}//constructor	
	
	
	/**
	 * Constructor.
	 */
	public OSRegistryReader(){
		
	}//constructor
	
	/**
	 * get the standard OSRegistry, a local interface for 
	 * storing Optimization Services registry.
	 * 
	 * @return the OSRegistry. 
	 * @throws Exception if there are errors getting the OSRegistry. 
	 */
   	public OSRegistry getOSRegistry() throws Exception{
		if(m_osRegistry != null){
			return m_osRegistry;
		}
		m_osRegistry = new OSRegistry();
		if(!m_osRegistry.setDescription(getDescription())) throw new Exception("setDescription Unsuccessful");
		if(!m_osRegistry.setNews(getNews())) throw new Exception("setNews Unsuccessful");
		if(!m_osRegistry.setServices(getServices())) throw new Exception("setServices Unsuccessful");
		return m_osRegistry;
   	}//getOSRegistry

   	
	/**
	 * Get the OSRegistry description. 
	 * 
	 * @return the OSRegistry description; null or empty string if none. 
	 */
	public String getDescription(){
		Element eDescription = (Element)XMLUtil.findChildNode(m_eRoot, "description");
		if(eDescription == null) return null;
		String sDescription = XMLUtil.getElementValue(eDescription);
		return sDescription;
	}//getDescription
	
	/**
	 * Get the OSRegistry news. 
	 * 
	 * @return the news element array. Each element of the array corresponds to 
	 * a news element; null if none. 
	 * @see org.optimizationservices.oscommon.datastructure.osgeneral.NewsElement
	 */
	public NewsElement[] getNews(){
		Element eNews = (Element)XMLUtil.findChildNode(m_eRoot, "news");
		if(eNews == null) return null;
		NodeList nls = eNews.getElementsByTagName("el");
		if(nls == null) return null;
		int iNls	= nls.getLength();
		if(iNls <= 0) return null;
		NewsElement[] mEl = new NewsElement[iNls];
		for(int i = 0; i < iNls; i++){
			mEl[i] = new NewsElement();
			Element eEl = (Element)(nls.item(i));
			NamedNodeMap	attributes =  eEl.getAttributes();
			int n =attributes.getLength();
			String sValue = XMLUtil.getElementValue(eEl);
			GregorianCalendar time = null;
			for (int j = 0; j < n; j++){
				Node	attr = attributes.item(j);
				String sAttributeName  = attr.getNodeName();
				String sAttributeValue = attr.getNodeValue();
				if (sAttributeName.equals("time")){
					time = XMLUtil.createNativeDateTime(sAttributeValue);
				}
			}
			mEl[i].value = sValue;
			mEl[i].time = time;
		}
		return mEl;
	}//getNews
	
	/**
	 * Get the OSRegistry services. 
	 * 
	 * @return the service array. Each element of the array corresponds to 
	 * a service entry; null if none. 
	 * @see org.optimizationservices.oscommon.datastructure.osregistry.ServiceEntry
	 */
	public ServiceEntry[] getServices(){
		Vector<Element> nls = XMLUtil.getChildElementsByTagName(m_eRoot, "service");
		if(nls == null) return null;
		int iNls	= nls.size();
		if(iNls <= 0) return null;
		ServiceEntry[] mService = new ServiceEntry[iNls];
		for(int i = 0; i < iNls; i++){
			mService[i] = new ServiceEntry();
			Element eService = (Element)(nls.elementAt(i));
			
			Element eOSeL = (Element)XMLUtil.findChildNode(eService, "osel");
			if(eOSeL != null){
				OSeLReader oselReader = new OSeLReader(OSParameter.VALIDATE);
				oselReader.setRootElement(eOSeL);
				OSEntity osEntity;
				try {
					osEntity = oselReader.getOSEntity();
					mService[i].osel = osEntity;
				} 
				catch (Exception e){
					e.printStackTrace();
				}
			}
			Element eOSpL = (Element)XMLUtil.findChildNode(eService, "ospl");
			if(eOSpL != null){
				OSpLReader osplReader = new OSpLReader(OSParameter.VALIDATE);
				osplReader.setRootElement(eOSpL);
				OSProcess osProcess;
				try {
					osProcess = osplReader.getOSProcess();
					mService[i].ospl = osProcess;
				} 
				catch (Exception e){
					e.printStackTrace();
				}
			}
			Element eOSbL = (Element)XMLUtil.findChildNode(eService, "osbl");
			if(eOSbL != null){
				OSbLReader osblReader = new OSbLReader(OSParameter.VALIDATE);
				osblReader.setRootElement(eOSbL);
				OSBenchmark osBenchmark;
				try {
					osBenchmark = osblReader.getOSBenchmark();
					mService[i].osbl = osBenchmark;
				} 
				catch (Exception e){
					e.printStackTrace();
				}
			}
		}
		return mService;
	}//getServices
	
	/**
	 * Get an OSRegistry service. 
	 * 
	 * @serviceURI holds the uri of the service to get.  
	 * @return the found service, which is in the ServiceEntry data structure.  
	 * @see org.optimizationservices.oscommon.datastructure.osregistry.ServiceEntry
	 */
	public ServiceEntry getService(String serviceURI){
		Vector<Element> nls = XMLUtil.getChildElementsByTagName(m_eRoot, "service");
		if(nls == null) return null;
		int iNls	= nls.size();
		if(iNls <= 0) return null;
		ServiceEntry service = new ServiceEntry();
		for(int i = 0; i < iNls; i++){
			Element eService = (Element)(nls.elementAt(i));
			Element eOSeL = (Element)XMLUtil.findChildNode(eService, "osel");
			if(eOSeL == null) continue;
			Element eEntityHeader = (Element)XMLUtil.findChildNode(eOSeL, "entityHeader");
			if(eOSeL == null) continue;
			String sServiceURI = XMLUtil.getElementValueByName(eEntityHeader, "serviceURI");
			if(sServiceURI != null && sServiceURI.equals(serviceURI)){		
				if(eOSeL != null){
					OSeLReader oselReader = new OSeLReader(OSParameter.VALIDATE);
					oselReader.setRootElement(eOSeL);
					OSEntity osEntity;
					try {
						osEntity = oselReader.getOSEntity();
						service.osel = osEntity;
					} 
					catch (Exception e){
						e.printStackTrace();
					}
				}
				Element eOSpL = (Element)XMLUtil.findChildNode(eService, "ospl");
				if(eOSpL != null){
					OSpLReader osplReader = new OSpLReader(OSParameter.VALIDATE);
					osplReader.setRootElement(eOSpL);
					OSProcess osProcess;
					try {
						osProcess = osplReader.getOSProcess();
						service.ospl = osProcess;
					} 
					catch (Exception e){
						e.printStackTrace();
					}
				}
				Element eOSbL = (Element)XMLUtil.findChildNode(eService, "osbl");
				if(eOSbL != null){
					OSbLReader osblReader = new OSbLReader(OSParameter.VALIDATE);
					osblReader.setRootElement(eOSbL);
					OSBenchmark osBenchmark;
					try {
						osBenchmark = osblReader.getOSBenchmark();
						service.osbl = osBenchmark;
					} 
					catch (Exception e){
						e.printStackTrace();
					}
				}
				return service;
			}
		}
		return null;		
	}//getService
   	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		OSRegistryReader osRegistryReader = new OSRegistryReader(false);
		System.out.println(IOUtil.readStringFromFile(OSParameter.CODE_HOME + "OSRepository/test/osregistry/osregistry.xml"));
		System.out.println(osRegistryReader.readFile(OSParameter.CODE_HOME + "OSRepository/test/osregistry/osregistry.xml"));
		System.out.println(osRegistryReader.getDescription());
		System.out.println(osRegistryReader.getNews()[0].value);
		System.out.println(osRegistryReader.getServices()[0].osel.entityHeader.serviceName);
		System.out.println(osRegistryReader.getService("xxx2").ospl.getRequestAction());
	}//main
	
}//class OSRegistryReader
