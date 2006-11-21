/**
 * @(#)OSRepositoryReader 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.representationparser;

import java.util.GregorianCalendar;
import java.util.Vector;

import org.optimizationservices.oscommon.datastructure.osgeneral.NewsElement;
import org.optimizationservices.oscommon.datastructure.osrepository.RepositoryInstance;
import org.optimizationservices.oscommon.localinterface.OSRepository;
import org.optimizationservices.oscommon.util.IOUtil;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.XMLUtil;
import org.w3c.dom.Element;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

/**
 * The <c>OSRepositoryReader</c> class parses an osRepository instance into a DOM tree and
 * provides a set of "get" methods that can be used to retrieve different 
 * pieces of information of the instance.
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */
public class OSRepositoryReader extends OSgLReader{	
	/**
	 * m_osRepository holds the standard OSRepository, which is a local interface for 
	 * storing Optimization Services Repository. 
	 */
	protected OSRepository m_osRepository = null;
	
	/**
	 * constructor
	 *
	 * </p>
	 *
	 * @param validate holds whether the reader should be validating against the schema or not.
	 */
	public OSRepositoryReader(boolean validate){
		m_bXsdValidate = validate;
	}//constructor	
	
	
	/**
	 * Constructor.
	 */
	public OSRepositoryReader(){
		
	}//constructor
	
	/**
	 * get the standard OSRepository, a local interface for 
	 * storing Optimization Services repository.
	 * 
	 * @return the OSRepository. 
	 * @throws Exception if there are errors getting the OSRepository. 
	 */
   	public OSRepository getOSRepository() throws Exception{
		if(m_osRepository != null){
			return m_osRepository;
		}
		m_osRepository = new OSRepository();
		if(!m_osRepository.setDescription(getDescription())) throw new Exception("setDescription Unsuccessful");
		if(!m_osRepository.setNews(getNews())) throw new Exception("setNews Unsuccessful");
		if(!m_osRepository.setInstances(getInstances())) throw new Exception("setInstances Unsuccessful");
		return m_osRepository;
   	}//getOSRepository
   	
	/**
	 * Get the OSRepository description. 
	 * 
	 * @return the OSRepository description; null or empty string if none. 
	 */
	public String getDescription(){
		Element eDescription = (Element)XMLUtil.findChildNode(m_eRoot, "description");
		if(eDescription == null) return null;
		String sDescription = XMLUtil.getElementValue(eDescription);
		return sDescription;
	}//getDescription
	

	/**
	 * Get the OSRepository news. 
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
	 * Get the OSRepository instances. 
	 * 
	 * @return the instance array. Each element of the array corresponds to 
	 * an instance entry; null if none. 
	 * @see org.optimizationservices.oscommon.datastructure.osrepository.RepositoryInstance
	 */
	public RepositoryInstance[] getInstances(){
		Vector<Element> nls = XMLUtil.getChildElementsByTagName(m_eRoot, "instance");
		if(nls == null) return null;
		int iNls	= nls.size();
		if(iNls <= 0) return null;
		RepositoryInstance[] mInstance = new RepositoryInstance[iNls];
		for(int i = 0; i < iNls; i++){
			mInstance[i] = new RepositoryInstance();
			Element eInstance = (Element)(nls.elementAt(i));
			mInstance[i].name = XMLUtil.getElementValueByName(eInstance, "name");
			mInstance[i].source = XMLUtil.getElementValueByName(eInstance, "source");
			mInstance[i].description = XMLUtil.getElementValueByName(eInstance, "description");
			mInstance[i].originalFileName = XMLUtil.getElementValueByName(eInstance, "originalFileName");
			mInstance[i].osDirectoty = XMLUtil.getElementValueByName(eInstance, "osDirectoty");
			mInstance[i].osFileName = XMLUtil.getElementValueByName(eInstance, "osFileName");
		}	
		return mInstance;
	}//getInstances
	
	/**
	 * Get an OSRepository instance. 
	 * 
	 * @instanceName holds the name of the instance to get.  
	 * @return the found instance, which is in the RepositoryInstance data structure.  
	 * @see org.optimizationservices.oscommon.datastructure.osrepository.RepositoryInstance
	 */
	public RepositoryInstance getInstance(String instanceName){
		Vector<Element> nls = XMLUtil.getChildElementsByTagName(m_eRoot, "instance");
		if(nls == null) return null;
		int iNls	= nls.size();
		if(iNls <= 0) return null;
		RepositoryInstance instance = new RepositoryInstance();
		for(int i = 0; i < iNls; i++){
			Element eInstance = (Element)(nls.elementAt(i));
			String sName = XMLUtil.getElementValueByName(eInstance, "name");
			if(sName.equals(instanceName)){		
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
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		OSRepositoryReader osRepositoryReader = new OSRepositoryReader(false);
		System.out.println(IOUtil.readStringFromFile(OSParameter.CODE_HOME + "OSRepository/OSRepositoryTemp.xml"));
		System.out.println(osRepositoryReader.readFile(OSParameter.CODE_HOME + "OSRepository/OSRepositoryTemp.xml"));
		System.out.println(osRepositoryReader.getDescription());
		System.out.println(osRepositoryReader.getNews()[0].value);
		System.out.println(osRepositoryReader.getInstances()[0].name);
		System.out.println(osRepositoryReader.getInstances().length);
		System.out.println(osRepositoryReader.getInstance("name2").source);
	}//main
	
}//class OSRepositoryReader
