using System;

using org.optimizationservices.oscommon.datastructure.osgeneral;

namespace org.optimizationservices.oscommon.datastructure.osprocess{
	/// <summary>
	/// A data structure class that corresponds to an xml element in the OSpL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class JobStatistics {

		/// <summary>
		/// jobID holds the ID of the job, which can be served as a key in a hashmap. 
		/// </summary>
		public string jobID = null;		
		
		/// <summary>
		/// state holds the job state, which can be waiting, running, killed, finished, or unknown.  
		/// </summary>
		public string state = "unknown";

		/// <summary>
		/// serviceURI holds the URI of the service that the job is submitted to.
		/// </summary>
		public string serviceURI = "";

		/// <summary>
		/// userName holds the name of the user that submits the job.
		/// </summary>
		public string userName = "";

		/// <summary>
		/// startTime holds the submit time of the job. 
		/// </summary>
		public DateTime submitTime =new DateTime(1970, 1, 1, 0, 0, 0); 

		/// <summary>
		/// startTime holds the start time of the job. 
		/// </summary>
		public DateTime startTime =new DateTime(1970, 1, 1, 0, 0, 0); 

		/// <summary>
		/// endTime holds the end time of the job. 
		/// </summary>
		public DateTime endTime = new DateTime(1970, 1, 1, 0, 0, 0); 

		/// <summary>
		/// duration holds the duration of the job. 
		/// </summary>
		public double duration = Double.NaN;

		/// <summary>
		/// scheduledStartTime holds the scheduled start time of the job. 
		/// </summary>
		public DateTime scheduledStartTime = new DateTime(1970, 1, 1, 0, 0, 0);
	
		/// <summary>
		/// othter jobIDs that have to finish before this job starts. 
		/// </summary>
		public JobDependencies dependencies = null; 

		/// <summary>
		/// requiredDirectoriesAndFiles holds the required files and directories to run the job.
		/// </summary>
		public DirectoriesAndFiles requiredDirectoriesAndFiles = null;

		/// <summary>
		/// Default constructor. 
		/// </summary>
		public JobStatistics() {
		}//constructor

	}//JobStatistics
}//namespace
