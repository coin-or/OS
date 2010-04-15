/**
 * @(#)OSRepositoryWriter 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.representationparser;

import java.util.GregorianCalendar;
import java.util.Vector;

import org.optimizationservices.oscommon.datastructure.osgeneral.NewsElement;
import org.optimizationservices.oscommon.datastructure.osrepository.RepositoryInstance;
import org.optimizationservices.oscommon.localinterface.OSRepository;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.XMLUtil;
import org.w3c.dom.Element;
import org.w3c.dom.ProcessingInstruction;

/**
 * The <code>OSRepositoryWriter</code> class is used to construct an instance that follows 
 * the OSRepository format. 
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */
public class OSRepositoryWriter extends OSgLWriter{
	/**
	 * m_eOSRepository holds the OSRepository root element.
	 */
	protected Element m_eOSRepository = null;
	
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
	public OSRepositoryWriter(){
		m_document = XMLUtil.createNewDocument();
		if(OSParameter.XSLT_LOCATION != null && OSParameter.XSLT_LOCATION.length() > 0){
			ProcessingInstruction xsltPI = m_document.createProcessingInstruction("xml-stylesheet",
	           "type=\"text/xsl\" href = \"" + OSParameter.XSLT_LOCATION + "OSRepository.xslt\"");
			m_document.appendChild(xsltPI);     
		}
		m_eOSRepository = createOSRepositoryRoot();
		m_document.appendChild(m_eOSRepository);
	}//constructor
	
	/**
	 * set the OSRepository, a standard os repository data structure. 
	 * @param osRepository holds the standard os repository data structure. 
	 * @return whether the OSRepository is set successfully. 
	 */
	public boolean setOSRepository(OSRepository osRepository) throws Exception{
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
	public boolean setDescription(String description){
		try{
			XMLUtil.removeChildrenByName(m_eOSRepository, "description");
			Element eDescription = createDescription(description);
			m_eOSRepository.insertBefore(eDescription, m_eOSRepository.getFirstChild());
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
	 * Set the OSRepository news. 
	 * 
	 * @newsElements holds an array of news elements. 
	 * Each element of the array corresponds to a news element. 
	 * @return whether the news is set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osgeneral.NewsElement
	 */
	public boolean setNews(NewsElement[] newsElements){
		if(newsElements == null || newsElements.length <= 0){
			XMLUtil.removeChildrenByName(m_eOSRepository, "news");
			return true;
		}
		for(int i = 0; i < newsElements.length; i++){
			addNewsElement(newsElements[i].time, newsElements[i].value);
		}
		return true;
	}//setNews
	
	/**
	 * Set the OSRepository instances. 
	 * 
	 * @instances holds an array of instances. 
	 * Each element of the array corresponds to a instance entry. 
	 * @return whether the instances are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osrepository.RepositoryInstance
	 */
	public boolean setInstances(RepositoryInstance[] instances){
		if(instances == null || instances.length <= 0){
			XMLUtil.removeChildrenByName(m_eOSRepository, "instance");
			return true;
		}
		XMLUtil.removeChildrenByName(m_eOSRepository, "instance");
		for(int i = 0; i < instances.length; i++){
			if(!addInstance(instances[i])) return false;		
		}
		return true;
	}//setInstances 
	
	/**
	 * Add an OSRepository instance. 
	 * 
	 * @instance holds a instance to add. 
	 * @return whether the instance is added successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osrepository.RepositoryInstance
	 */
	public boolean addInstance(RepositoryInstance instance){
		if(instance == null) return false;
		Element eInstance = m_document.createElement("instance");
		
		Element eName = m_document.createElement("name");
		eName.appendChild(m_document.createTextNode(instance.name));
		eInstance.appendChild(eName);
		
		Element eSource = m_document.createElement("source");
		eSource.appendChild(m_document.createTextNode(instance.source));
		eInstance.appendChild(eSource);
		
		Element eDescription = m_document.createElement("description");
		eDescription.appendChild(m_document.createTextNode(instance.description));
		eInstance.appendChild(eDescription);
		
		Element eOriginalFileName = m_document.createElement("originalFileName");
		eOriginalFileName.appendChild(m_document.createTextNode(instance.originalFileName));
		eInstance.appendChild(eOriginalFileName);
		
		Element eOSDirectory = m_document.createElement("osDirectoty");
		eOSDirectory.appendChild(m_document.createTextNode(instance.osDirectoty));
		eInstance.appendChild(eOSDirectory);
		
		Element eOSFileName = m_document.createElement("osFileName");
		eOSFileName.appendChild(m_document.createTextNode(instance.osFileName));
		eInstance.appendChild(eOSFileName);
		
		m_eOSRepository.appendChild(eInstance);
		return true;
	}//addInstance
	
	/**
	 * Delete an OSRepository instance. 
	 * 
	 * @instanceName holds the name of the instance to delete.  
	 * @return whether the instance is deleted successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osrepository.RepositoryInstance
	 */
	public boolean deleteInstance(String instanceName){
		if(instanceName == null) return true;
		Vector<Element> nls = XMLUtil.getChildElementsByTagName(m_eOSRepository, "instance");
		if(nls == null) return true;
		int iNls	= nls.size();
		if(iNls <= 0) return true;
		for(int i = 0; i < iNls; i++){
			Element eInstance = (Element)(nls.elementAt(i));
			String sName = XMLUtil.getElementValueByName(eInstance, "name");
			if(sName.equals(instanceName)){	
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
	protected Element createOSRepositoryRoot(){
		Element eOSRepository = XMLUtil.createOSxLRootElement(m_document, "osRepository");
		m_eDescription = createDescription("OS Repository in OSRepository format.");
		eOSRepository.appendChild(m_eDescription);
		m_eNews = createNews();
		eOSRepository.appendChild(m_eNews);
		return eOSRepository;
	}//createOSRepositoryRoot
	
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
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		OSRepositoryWriter osRepositoryWriter = new OSRepositoryWriter();
		String sFileName = OSParameter.CODE_HOME + "OSRepository/OSRepositoryTemp.xml";
		
		if(!osRepositoryWriter.setDescription("registry description")) System.out.println("description!");
		for(int i = 0; i < 3; i++){
			osRepositoryWriter.addNewsElement(new GregorianCalendar(2006, 1, 2, 3, 4, i), "news: " + i);
		}
		RepositoryInstance[] mInstance = new RepositoryInstance[3];
		for(int i = 0; i < 3; i++){
			mInstance[i] = new RepositoryInstance();
			mInstance[i].name = "name"+i;
			mInstance[i].source = "source"+i;
			mInstance[i].description = "description"+i;
			mInstance[i].originalFileName = "originalFileName"+i;
			mInstance[i].osDirectoty = "osDirectoty"+i;
			mInstance[i].osFileName = "osFileName"+i;
			osRepositoryWriter.addInstance(mInstance[i]);
		}
		
		////////////////////
		
		OSRepositoryReader osRepositoryReader = new OSRepositoryReader(false);
		if(!osRepositoryReader.readFile(sFileName)) System.out.println("reading");
		OSRepository osRepository;
		try {
			osRepository = osRepositoryReader.getOSRepository();
			if(!osRepositoryWriter.setOSRepository(osRepository)) System.out.println("setOSRepository");
		} 
		catch (Exception e) {
			e.printStackTrace();
		}
		////////////////////
		//osRepositoryWriter.writeToStandardOutput();
		System.out.println(osRepositoryWriter.writeToString());
	}//main
}//class OSRepositoryWriter
