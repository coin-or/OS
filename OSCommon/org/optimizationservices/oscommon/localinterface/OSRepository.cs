using System;
using System.Collections;

using org.optimizationservices.oscommon.datastructure.osrepository;
using org.optimizationservices.oscommon.datastructure.osgeneral;
using org.optimizationservices.oscommon.representationparser;

namespace org.optimizationservices.oscommon.localinterface{
	/// <summary>
	/// The <c>OSRepository</c> class is a local interface for storing OS 
	/// services. Its design follows the OSRepository schema. Naming, structuring and layering 
	/// all are exactly the same as those in the OSRepository schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OSRepository{

		/// <summary>
		/// description holds the general description of the os repository. 
		/// </summary>
		public string description = "";

		/// <summary>
		/// news holds the news for the os repository. 
		/// </summary>
		public News news = null;

		/// <summary>
		/// instance holds an array of os repository instances. 
		/// </summary>
		public RepositoryInstance[] instance = null;

			
		/// <summary>
		/// Default constructor. 
		/// </summary>
		public OSRepository(){
		}//constructor
		/// <summary>
		/// read an OSRepository instance and return and OSRepository object.  
		/// @throws Exception if there are errors in reading the string or setting the OSRepository. 
		/// </summary>
		/// <param name="osRepository">holds the optimization repository in a string which format follows the
		/// Optimization Services repository Language (OSRepository) schema</param>
		/// <param name="isFile">isFile holds whether the osRepository string is a file name or a string that literally holds the osRepository contents.  </param>
		/// <param name="validate">holds whether the reader should be validating against the schema or not.</param>
		/// <returns>the OSRepository object constructed from the OSRepository String.  </returns>
		public OSRepository readOSRepository(string osRepository, bool isFile, bool validate){
			OSRepositoryReader osRepositoryReader = new OSRepositoryReader(validate);
			bool bRead = false;
			if(isFile){
				bRead = osRepositoryReader.readFile(osRepository);
			}
			else{
				bRead = osRepositoryReader.readString(osRepository);			
			}
			if(!bRead) throw new Exception("OSRepository string not valid");
			return osRepositoryReader.getOSRepository();
		}//readOSRepository
  
		/// <summary>
		/// write the OSRepository to an osRepository xml string. 
		/// @throws Exception if there are errors in writing the osRepository string. 
		/// </summary>
		/// <returns>the osRepository xml string. </returns>
		public string writeOSRepository(){
			OSRepositoryWriter osRepositoryWriter = new OSRepositoryWriter();
			osRepositoryWriter.setOSRepository(this);
			return osRepositoryWriter.writeToString();
		}//writeOSRepository


		/// <summary>
		/// Get the OSRepository description. 
		/// </summary>
		/// <returns>the OSRepository description; null or empty string if none. </returns>
		public string getDescription(){
			return description;
		}//getDescription

		/// <summary>
		/// Set the OSRepository description. 
		/// </summary>
		/// <param name="description">holds the OSRepository description. </param>
		/// <returns>whether the description is set successfully or not. </returns>
		public bool setDescription(string description){
			this.description = description;
			return true;
		}//setDescription

		/// <summary>
		/// Get the OSRepository news. 
		/// @see org.optimizationservices.oscommon.datastructure.osgeneral.NewsElement
		/// </summary>
		/// <returns>the news element array. Each element of the array corresponds to 
		/// a news element; null if none. </returns>
		public NewsElement[] getNews(){
			if(news == null) return null;
			return news.el;
		}//getNews

		/// <summary>
		/// Set the OSRepository news. 
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
		/// Add an OSRepository news element.
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
		/// Get the OSRepository instances. 
		/// @see org.optimizationservices.oscommon.datastructure.osrepository.RepositoryInstance
		/// </summary>
		/// <returns>the instance array. Each element of the array corresponds to 
		/// an instance entry; null if none. 
		/// </returns>
		public RepositoryInstance[] getInstances(){
			return this.instance;
		}//getInstances

		/// <summary>
		/// Get an OSRepository instance. 
		/// @see org.optimizationservices.oscommon.datastructure.osrepository.RepositoryInstance
		/// </summary>
		/// <param name="instanceName">the name of the instance to get.  </param>
		/// <returns>the found instance, which is in the RepositoryInstance data structure. </returns>
		public RepositoryInstance getInstance(string instanceName){
			if(instance == null || instance.Length <= 0) return null;
			for(int i = 0; i < instance.Length; i++){
				if(instance[i].name != null && instance[i].name.Equals(instanceName)){
					return instance[i];
				}
			}
			return null;
		}//getInstance

		/// <summary>
		/// Set the OSRepository instances. 
		/// @see org.optimizationservices.oscommon.datastructure.osrepository.RepositoryInstance
		/// </summary>
		/// <param name="instances">holds an array of instances. 
		/// Each element of the array corresponds to a instance entry. </param>
		/// <returns>whether the instances are set successfully or not. </returns>
		public bool setInstances(RepositoryInstance[] instances){
			this.instance = instances;
			return true;
		}//setInstances 

		/// <summary>
		/// Add an OSRepository instance. 
		/// @see org.optimizationservices.oscommon.datastructure.osrepository.RepositoryInstance
		/// </summary>
		/// <param name="instance">holds a instance to add. </param>
		/// <returns>whether the instance is added successfully or not. </returns>
		public bool addInstance(RepositoryInstance instance){
			int n = (this.instance==null)?0:this.instance.Length;
			RepositoryInstance[] newInstances = new RepositoryInstance[n+1];
			for(int i = 0; i < n; i++){
				newInstances[i] = this.instance[i];
			}
			this.instance[n] = instance;
			this.instance = newInstances; 
			return true;
		}//addInstance

		/// <summary>
		/// Delete an OSRepository instance. 
		/// @see org.optimizationservices.oscommon.datastructure.osrepository.RepositoryInstance
		/// </summary>
		/// <param name="instanceName">holds the name of the instance to delete.  </param>
		/// <returns>whether the instance is deleted successfully or not. </returns>
		public bool deleteInstance(string instanceName){
			int m = (this.instance==null)?0:this.instance.Length;
			if(m == 0) return true;
			ArrayList vNewInstances = new ArrayList();
				string sInstanceName;
			for(int i = 0; i < m; i++){
				sInstanceName = this.instance[i].name;
				if(!sInstanceName.Equals(instanceName)){
					vNewInstances.Add(this.instance[i]);
				}
			}
			int n = vNewInstances.Count;
			if(n == 0){
				this.instance = null;
				return true;
			}
			RepositoryInstance[] mNewInstances = new RepositoryInstance[n];
			for(int i = 0; i < n; i++){
				mNewInstances[i] = (RepositoryInstance)vNewInstances[i];
			}
			this.instance = mNewInstances; 
			return true;
		}//deleteInstance
	}//class OSRepository
}//namespace
