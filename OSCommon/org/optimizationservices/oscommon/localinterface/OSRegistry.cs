using System;
using System.Collections;

using org.optimizationservices.oscommon.datastructure.osregistry;
using org.optimizationservices.oscommon.localinterface;
using org.optimizationservices.oscommon.representationparser;
using org.optimizationservices.oscommon.datastructure.osgeneral;

namespace org.optimizationservices.oscommon.localinterface{
	/// <summary>
	/// The <c>OSRegistry</c> class is a local interface for storing OS 
	/// services. Its design follows the OSRegistry schema. Naming, structuring and layering 
	/// all are exactly the same as those in the OSRegistry schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// <see cref="org.optimizationservices.oscommon.localinterface.OSEntity/"/>
	/// <see cref="org.optimizationservices.oscommon.localinterface.OSProcess"/>
	/// <see cref="org.optimizationservices.oscommon.localinterface.OSBenchmark"/>
	/// </summary>
	public class OSRegistry{

		/// <summary>
		/// description holds the general description of the os registry. 
		/// </summary>
		public string description = "";

		/// <summary>
		/// news holds the news for the os registry. 
		/// </summary>
		public News news = null;

		/// <summary>
		/// service holds an array of registered services in the os registry. 
		/// </summary>
		public ServiceEntry[] service = null;

			
		/// <summary>
		/// Default constructor. 
		/// </summary>
		public OSRegistry(){
		}//constructor

		/// <summary>
		/// read an OSRegistry instance and return and OSRegistry object.  
		/// @throws Exception if there are errors in reading the string or setting the OSRegistry. 
		/// </summary>
		/// <param name="osRegistry">holds the optimization registry in a string which format follows the
		/// Optimization Services registry Language (OSRegistry) schema</param>
		/// <param name="isFile">isFile holds whether the osRegistry string is a file name or a string that literally holds the osRegistry contents.  </param>
		/// <param name="validate">holds whether the reader should be validating against the schema or not.</param>
		/// <returns>the OSRegistry object constructed from the OSRegistry String.  </returns>
		public OSRegistry readOSRegistry(string osRegistry, bool isFile, bool validate){
			OSRegistryReader osRegistryReader = new OSRegistryReader(validate);
			bool bRead = false;
			if(isFile){
				bRead = osRegistryReader.readFile(osRegistry);
			}
			else{
				bRead = osRegistryReader.readString(osRegistry);			
			}
			if(!bRead) throw new Exception("OSRegistry string not valid");
			return osRegistryReader.getOSRegistry();
		}//readOSRegistry
	   
		/// <summary>
		/// write the OSRegistry to an osRegistry xml string. 
		/// @throws Exception if there are errors in writing the osRegistry string. 
		/// </summary>
		/// <returns>the osRegistry xml string. </returns>
		public string writeOSRegistry(){
			OSRegistryWriter osRegistryWriter = new OSRegistryWriter();
			osRegistryWriter.setOSRegistry(this);
			return osRegistryWriter.writeToString();
		}//writeOSRegistry

		/// <summary>
		/// Get the OSRegistry description. 
		/// </summary>
		/// <returns>the OSRegistry description; null or empty string if none. </returns>
		public string getDescription(){
			return description;
		}//getDescription

		/// <summary>
		/// Set the OSRegistry description. 
		/// </summary>
		/// <param name="description">holds the OSRegistry description. </param>
		/// <returns>whether the description is set successfully or not. </returns>
		public bool setDescription(string description){
			this.description = description;
			return true;
		}//setDescription

		/// <summary>
		/// Get the OSRegistry news. 
		/// @see org.optimizationservices.oscommon.datastructure.osgeneral.NewsElement
		/// </summary>
		/// <returns>the news element array. Each element of the array corresponds to 
		/// a news element; null if none. </returns>
		public NewsElement[] getNews(){
			if(news == null) return null;
			return news.el;
		}//getNews

		/// <summary>
		/// Set the OSRegistry news. 
		/// @see org.optimizationservices.oscommon.datastructure.osgeneral.NewsElement
		/// </summary>
		/// <param name="newsElements">holds an array of news elements. 
		/// Each element of the array corresponds to a news element. 
		/// </param>
		/// <returns>whether the news is set successfully or not. </returns>
		public bool setNews(NewsElement[] newsElements){
			if(news == null) news = new News();
			news.el = newsElements;
			return true;
		}//setNews

		/// <summary>
		/// Add an OSRegistry news element.
		/// @see org.optimizationservices.oscommon.datastructure.osgeneral.NewsElement
		/// </summary>
		/// <param name="newsElement">holds a news element to add. </param>
		/// <returns>whether the news element is added successfully or not. </returns>
		public bool addNews(NewsElement newsElement){
			if(news == null) news = new News();
			int n = (news.el==null)?0:news.el.Length;
			NewsElement[] newNewsElements = new NewsElement[n+1];
			for(int i = 0; i < n; i++){
				newNewsElements[i] = news.el[i];
			}
			newNewsElements[n] = newsElement;
			news.el = newNewsElements;
			return true;
		}//addNews

		/// <summary>
		/// Get the OSRegistry services. 
		/// @see org.optimizationservices.oscommon.datastructure.osregistry.ServiceEntry
		/// </summary>
		/// <returns>the service array. Each element of the array corresponds to 
		/// a service entry; null if none. 
		/// </returns>
		public ServiceEntry[] getServices(){
			return this.service;
		}//getServices

		/// <summary>
		/// Get an OSRegistry service. 
		/// @see org.optimizationservices.oscommon.datastructure.osregistry.ServiceEntry
		/// </summary>
		/// <param name="serviceURI">holds the uri of the service to get.  </param>
		/// <returns>the found service, which is in the ServiceEntry data structure.  </returns>
		public ServiceEntry getService(String serviceURI){
			if(service == null || service.Length <= 0) return null;
			for(int i = 0; i < service.Length; i++){
				string sServiceURI = service[i].osel.getServiceURI();
				if(sServiceURI != null && sServiceURI.Equals(serviceURI)){
					return service[i];
				}
			}
			return null;
		}//getService

		/// <summary>
		/// Set the OSRegistry services. 
		/// @see org.optimizationservices.oscommon.datastructure.osregistry.ServiceEntry
		/// </summary>
		/// <param name="services">holds an array of services. 
		/// Each element of the array corresponds to a service entry. 
		/// </param>
		/// <returns>whether the services are set successfully or not. </returns>
		public bool setServices(ServiceEntry[] services){
			this.service = services;
			return true;
		}//setServices 

		/// <summary>
		/// Add an OSRegistry service. 
		/// @see org.optimizationservices.oscommon.datastructure.osregistry.ServiceEntry
		/// </summary>
		/// <param name="service">holds a service to add. </param>
		/// <returns>whether the service is added successfully or not. </returns>
		public bool addService(ServiceEntry service){
			int n = (this.service==null)?0:this.service.Length;
			ServiceEntry[] newServices = new ServiceEntry[n+1];
			for(int i = 0; i < n; i++){
				newServices[i] = this.service[i];
			}
			this.service[n] = service;
			this.service = newServices; 
			return true;
		}//addService

		/// <summary>
		/// Delete an OSRegistry service. 
		/// @see org.optimizationservices.oscommon.datastructure.osregistry.ServiceEntry
		/// </summary>
		/// <param name="serviceURI">holds the uri of the service to delete.  </param>
		/// <returns>whether the service is deleted successfully or not. </returns>
		public bool deleteService(string serviceURI){
			int m = (this.service==null)?0:this.service.Length;
			if(m == 0) return true;
			ArrayList vNewServices = new ArrayList();
				string sServiceURI;
			for(int i = 0; i < m; i++){
				sServiceURI = this.service[i].osel.getServiceURI();
				if(!sServiceURI.Equals(serviceURI)){
					vNewServices.Add(this.service[i]);
				}
			}
			int n = vNewServices.Count;
			if(n == 0){
				this.service = null;
				return true;
			}
			ServiceEntry[] mNewServices = new ServiceEntry[n];
			for(int i = 0; i < n; i++){
				mNewServices[i] = (ServiceEntry)vNewServices[i];
			}
			this.service = mNewServices; 
			return true;
		}//deleteService

	}//class OSRegistry
}//namespace
