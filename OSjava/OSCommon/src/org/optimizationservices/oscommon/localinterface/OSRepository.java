/**
 * @(#)OSRepository 1.0 03/14/2005
 *
 * Copyright (c) 2005 
 */
package org.optimizationservices.oscommon.localinterface;

import java.util.GregorianCalendar;
import java.util.Vector;

import org.optimizationservices.oscommon.datastructure.osgeneral.News;
import org.optimizationservices.oscommon.datastructure.osgeneral.NewsElement;
import org.optimizationservices.oscommon.datastructure.osrepository.RepositoryInstance;
import org.optimizationservices.oscommon.representationparser.OSRepositoryReader;
import org.optimizationservices.oscommon.representationparser.OSRepositoryWriter;
import org.optimizationservices.oscommon.util.XMLUtil;

/**
*
* <P>The <code>OSRepository</code> class is a local interface for storing Optimization Services
* repository. Its design follows the Optimization Services Repository Language (OSRepository). 
* All the data structures in this class are standards specified in the OSRepository schema. 
*
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2005
* @since OS 1.0
*/

public class OSRepository {

	/**
	 * description holds the general description of the os repository. 
	 */
	public String description = "";

	/**
	 * news holds the news for the os repository. 
	 */
	public News news = null;
	
	/**
	 * instance holds an array of os repository instances. 
	 */
	public RepositoryInstance[] instance = null;
	
	/**
	 *
	 * Default constructor. 
	 */
	public OSRepository(){
	}//constructor
	
	/**
	 * read an OSRepository instance and return and OSRepository object.  
	 * 
	 * @param osRepository holds the optimization repository in a string which format follows the
	 * Optimization Services repository Language (OSRepository) schema.
	 * @param isFile holds whether the osRepository string is a file name or a string that literally holds the osRepository contents.  
	 * @param validate holds whether the reader should be validating against the schema or not.
	 * @return the OSRepository object constructed from the OSRepository String.  
	 * @throws Exception if there are errors in reading the string or setting the OSRepository. 
	 */
   	public OSRepository readOSRepository(String osRepository, boolean isFile, boolean validate) throws Exception{
   		OSRepositoryReader osRepositoryReader = new OSRepositoryReader(validate);
		boolean bRead = false;
		if(isFile){
			bRead = osRepositoryReader.readFile(osRepository);
		}
		else{
			bRead = osRepositoryReader.readString(osRepository);			
		}
		if(!bRead) throw new Exception("OSRepository string not valid");
		return osRepositoryReader.getOSRepository();
   	}//readOSRepository
   	
   	/**
   	 * write the OSRepository to an osRepository xml string. 
   	 * 
   	 * @return the osRepository xml string. 
	 * @throws Exception if there are errors in writing the osRepository string. 
   	 */
   	public String writeOSRepository() throws Exception{
		OSRepositoryWriter osRepositoryWriter = new OSRepositoryWriter();
		osRepositoryWriter.setOSRepository(this);
		return osRepositoryWriter.writeToString();
   	}//writeOSRepository
	
	
	/**
	 * Get the OSRepository description. 
	 * 
	 * @return the OSRepository description; null or empty string if none. 
	 */
	public String getDescription(){
		return description;
	}//getDescription
	
	/**
	 * Set the OSRepository description. 
	 * 
	 * @param description holds the OSRepository description. 
	 * 
	 * @return whether the description is set successfully or not. 
	 */
	public boolean setDescription(String description){
		this.description = description;
		return true;
	}//setDescription

	/**
	 * Get the OSRepository news. 
	 * 
	 * @return the news element array. Each element of the array corresponds to 
	 * a news element; null if none. 
	 * @see org.optimizationservices.oscommon.datastructure.osgeneral.NewsElement
	 */
	public NewsElement[] getNews(){
		if(news == null) return null;
		return news.el;
	}//getNews

	/**
	 * Set the OSRepository news. 
	 * 
	 * @newsElements holds an array of news elements. 
	 * Each element of the array corresponds to a news element. 
	 * @return whether the news is set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osgeneral.NewsElement
	 */
	public boolean setNews(NewsElement[] newsElements){
		if(news == null) news = new News();
		news.el = newsElements;
		return true;
	}//setNews
	
	/**
	 * Add an OSRepository news element. 
	 * 
	 * @newsElement holds a news element to add. 
	 * @return whether the news element is added successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osgeneral.NewsElement
	 */
	public boolean addNews(NewsElement newsElement){
		if(news == null) news = new News();
		int n = (news.el==null)?0:news.el.length;
		NewsElement[] newNewsElements = new NewsElement[n+1];
		for(int i = 0; i < n; i++){
			newNewsElements[i] = news.el[i];
		}
		newNewsElements[n] = newsElement;
		news.el = newNewsElements;
		return true;
	}//addNews
	
	/**
	 * Get the OSRepository instances. 
	 * 
	 * @return the instance array. Each element of the array corresponds to 
	 * an instance entry; null if none. 
	 * @see org.optimizationservices.oscommon.datastructure.osrepository.RepositoryInstance
	 */
	public RepositoryInstance[] getInstances(){
		return this.instance;
	}//getInstances
	
	/**
	 * Get an OSRepository instance. 
	 * 
	 * @instanceName holds the name of the instance to get.  
	 * @return the found instance, which is in the RepositoryInstance data structure.  
	 * @see org.optimizationservices.oscommon.datastructure.osrepository.RepositoryInstance
	 */
	public RepositoryInstance getInstance(String instanceName){
		if(instance == null || instance.length <= 0) return null;
		for(int i = 0; i < instance.length; i++){
			if(instance[i].name != null && instance[i].name.equals(instanceName)){
				return instance[i];
			}
		}
		return null;
	}//getInstance
	
	/**
	 * Set the OSRepository instances. 
	 * 
	 * @instances holds an array of instances. 
	 * Each element of the array corresponds to a instance entry. 
	 * @return whether the instances are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osrepository.RepositoryInstance
	 */
	public boolean setInstances(RepositoryInstance[] instances){
		this.instance = instances;
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
		int n = (this.instance==null)?0:this.instance.length;
		RepositoryInstance[] newInstances = new RepositoryInstance[n+1];
		for(int i = 0; i < n; i++){
			newInstances[i] = this.instance[i];
		}
		this.instance[n] = instance;
		this.instance = newInstances; 
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
		int m = (this.instance==null)?0:this.instance.length;
		if(m == 0) return true;
		Vector<RepositoryInstance> vNewInstances = new Vector<RepositoryInstance>();
		String sInstanceName;
		for(int i = 0; i < m; i++){
			sInstanceName = this.instance[i].name;
			if(!sInstanceName.equals(instanceName)){
				vNewInstances.add(this.instance[i]);
			}
		}
		int n = vNewInstances.size();
		if(n == 0){
			this.instance = null;
			return true;
		}
		RepositoryInstance[] mNewInstances = new RepositoryInstance[n];
		for(int i = 0; i < n; i++){
			mNewInstances[i] = vNewInstances.elementAt(i);
		}
		this.instance = mNewInstances; 
		return true;
	}//deleteInstance
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] args){
		System.out.println(XMLUtil.createXSDateTime(new GregorianCalendar()));
	}//main
}//class OSRepository

