/**
 * @(#)OSRegistry 1.0 03/14/2005
 *
 * Copyright (c) 2005 
 */
package org.optimizationservices.oscommon.localinterface;

import java.util.Vector;

import org.optimizationservices.oscommon.datastructure.osgeneral.News;
import org.optimizationservices.oscommon.datastructure.osgeneral.NewsElement;
import org.optimizationservices.oscommon.datastructure.osregistry.ServiceEntry;
import org.optimizationservices.oscommon.representationparser.OSRegistryReader;
import org.optimizationservices.oscommon.representationparser.OSRegistryWriter;
import org.optimizationservices.oscommon.util.DefaultRegistry;

/**
*
* <P>The <code>OSRegistry</code> class is a local interface for storing Optimization Services
* registry. Its design follows the Optimization Services Registry Language (OSRegistry). 
* All the data structures in this class are standards specified in the OSRegistry schema. 
*
* @author Robert Fourer, Jun Ma, Kipp Martin
* @see org.optimizationservices.oscommon.localinterface.OSEntity
* @see org.optimizationservices.oscommon.localinterface.OSProcess
* @see org.optimizationservices.oscommon.localinterface.OSBenchmark
* @version 1.0, 03/14/2005
* @since OS 1.0
*/

public class OSRegistry {

	/**
	 * description holds the general description of the os registry. 
	 */
	public String description = "";

	/**
	 * news holds the news for the os registry. 
	 */
	public News news = null;
	
	/**
	 * service holds an array of registered services in the os registry. 
	 */
	public ServiceEntry[] service = null;
	
	/**
	 *
	 * Default constructor. 
	 */
	public OSRegistry(){
	}//constructor
	
	/**
	 * read an OSRegistry instance and return and OSRegistry object.  
	 * 
	 * @param osRegistry holds the optimization registry in a string which format follows the
	 * Optimization Services registry Language (OSRegistry) schema.
	 * @param isFile holds whether the osRegistry string is a file name or a string that literally holds the osRegistry contents.  
	 * @param validate holds whether the reader should be validating against the schema or not.
	 * @return the OSRegistry object constructed from the OSRegistry String.  
	 * @throws Exception if there are errors in reading the string or setting the OSRegistry. 
	 */
   	public OSRegistry readOSRegistry(String osRegistry, boolean isFile, boolean validate) throws Exception{
   		OSRegistryReader osRegistryReader = new OSRegistryReader(validate);
		boolean bRead = false;
		if(isFile){
			bRead = osRegistryReader.readFile(osRegistry);
		}
		else{
			bRead = osRegistryReader.readString(osRegistry);			
		}
		if(!bRead) throw new Exception("OSRegistry string not valid");
		return osRegistryReader.getOSRegistry();
   	}//readOSRegistry
   	
   	/**
   	 * write the OSRegistry to an osRegistry xml string. 
   	 * 
   	 * @return the osRegistry xml string. 
	 * @throws Exception if there are errors in writing the osRegistry string. 
   	 */
   	public String writeOSRegistry() throws Exception{
		OSRegistryWriter osRegistryWriter = new OSRegistryWriter();
		osRegistryWriter.setOSRegistry(this);
		return osRegistryWriter.writeToString();
   	}//writeOSRegistry
	
	/**
	 * Get the OSRegistry description. 
	 * 
	 * @return the OSRegistry description; null or empty string if none. 
	 */
	public String getDescription(){
		return description;
	}//getDescription
	
	/**
	 * Set the OSRegistry description. 
	 * 
	 * @param description holds the OSRegistry description. 
	 * 
	 * @return whether the description is set successfully or not. 
	 */
	public boolean setDescription(String description){
		this.description = description;
		return true;
	}//setDescription

	/**
	 * Get the OSRegistry news. 
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
	 * Set the OSRegistry news. 
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
	 * Add an OSRegistry news element. 
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
	 * Get the OSRegistry services. 
	 * 
	 * @return the service array. Each element of the array corresponds to 
	 * a service entry; null if none. 
	 * @see org.optimizationservices.oscommon.datastructure.osregistry.ServiceEntry
	 */
	public ServiceEntry[] getServices(){
		return this.service;
	}//getServices
	
	/**
	 * Get an OSRegistry service. 
	 * 
	 * @serviceURI holds the uri of the service to get.  
	 * @return the found service, which is in the ServiceEntry data structure.  
	 * @see org.optimizationservices.oscommon.datastructure.osregistry.ServiceEntry
	 */
	public ServiceEntry getService(String serviceURI){
		if(service == null || service.length <= 0) return null;
		for(int i = 0; i < service.length; i++){
			String sServiceURI = service[i].osel.getServiceURI();
			if(sServiceURI != null && sServiceURI.equals(serviceURI)){
				return service[i];
			}
		}
		return null;
	}//getService
	
	/**
	 * Set the OSRegistry services. 
	 * 
	 * @services holds an array of services. 
	 * Each element of the array corresponds to a service entry. 
	 * @return whether the services are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osregistry.ServiceEntry
	 */
	public boolean setServices(ServiceEntry[] services){
		this.service = services;
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
		int n = (this.service==null)?0:this.service.length;
		ServiceEntry[] newServices = new ServiceEntry[n+1];
		for(int i = 0; i < n; i++){
			newServices[i] = this.service[i];
		}
		this.service[n] = service;
		this.service = newServices; 
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
		int m = (this.service==null)?0:this.service.length;
		if(m == 0) return true;
		Vector<ServiceEntry> vNewServices = new Vector<ServiceEntry>();
		String sServiceURI;
		for(int i = 0; i < m; i++){
			sServiceURI = this.service[i].osel.getServiceURI();
			if(!sServiceURI.equals(serviceURI)){
				vNewServices.add(this.service[i]);
			}
		}
		int n = vNewServices.size();
		if(n == 0){
			this.service = null;
			return true;
		}
		ServiceEntry[] mNewServices = new ServiceEntry[n];
		for(int i = 0; i < n; i++){
			mNewServices[i] = vNewServices.elementAt(i);
		}
		this.service = mNewServices; 
		return true;
	}//deleteService
	
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] args){
		OSRegistry osRegistry = DefaultRegistry.osRegistry;
		try {
			System.out.println(osRegistry.writeOSRegistry());
		} 
		catch (Exception e) {
			e.printStackTrace();
		}
	}//main
}//class OSRegistry

