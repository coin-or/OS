using System;
using System.IO;
using System.Text;
using System.Collections;

using org.optimizationservices.oscommon.representationparser;

namespace org.optimizationservices.oscommon.util{
	/// <summary>
	/// The <c>OSParameter</c> class stores predefined parameters (public and static)
	/// used in other classes. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OSParameter{
		/// <summary>
		/// Default constructor. 
		/// </summary>
		public OSParameter(){
		}//constructor
		

		/*---------------------------------------------
		Routine/maintenance related parameters
		---------------------------------------------*/	
		/// <summary>
		/// CODE_DRIVE holds the disk drive of the code installation. 
		/// </summary>
		public static string CODE_DRIVE = "c:";  //change?

		/// <summary>
		/// CODE_HOME holds the home directory of home. 
		/// </summary>
		public static string CODE_HOME = "c:/code/";  //change?

		/// <summary>
		/// PARAMETER_FILE holds the file that keeps the parameter information.  
		/// </summary>
		public static string PARAMETER_FILE = CODE_HOME + "OSConfig/OSParameter.xml";

		/// <summary>
		/// REGISTRY_FILE holds the file that keeps the registry information. 
		/// </summary>
		public static string REGISTRY_FILE = CODE_HOME + "OSConfig/OSRegistry.xml";

		/// <summary>
		/// PROCESS_FILE holds the file that keeps the service process information in OSpL. 
		/// </summary>
		public static string PROCESS_FILE = CODE_HOME + "OSConfig/OSpL.xml";

		/// <summary>
		/// TEMP_FILE_FOLDER holds the folder to save temporary files. 
		/// </summary>
		public static string TEMP_FILE_FOLDER = CODE_HOME + "temp/";

		/// <summary>
		/// LOG_FOLDER holds the main system folder for logging messages and errors.
		/// </summary>
		public static string LOG_FOLDER = CODE_HOME + "log/";

		/// <summary>
		/// LOG_FILE holds the main system file for logging messages and errors.
		/// </summary>
		public static string LOG_FILE = LOG_FOLDER + "log.txt";
		
		/// <summary>
		/// MAX_LOG_FILE_SIZE holds the maximum size of the log file before it is backed up and started again. 
		/// </summary>
		public static long MAX_LOG_FILE_SIZE = 1000000;


		/// <summary>
		/// BACKUP_FOLDER holds the main system folder for backing up.
		/// </summary>
		public static string BACKUP_FOLDER = CODE_HOME + "backup/";

		/// <summary>
		/// REGISTRY_LOG_FOLDER holds the main registry folder for logging registy related messages.
		/// </summary>
		public static string REGISTRY_LOG_FOLDER =CODE_HOME + "log/";
		
		/// <summary>
		/// REGISTRY_LOG_FILE holds the main registry file for logging registy related messages.
		/// </summary>
		public static string REGISTRY_LOG_FILE = REGISTRY_LOG_FOLDER + "registryLog.txt";

		/// <summary>
		/// REGISTRY_REGISTRATION_FILE holds the main registry file for logging registration related messages.
		/// </summary>
		public static string REGISTRY_REGISTRATION_FILE = REGISTRY_LOG_FOLDER + "registryRegistration.txt";

		/// <summary>
		/// REGISTRY_SUMMARY_REPORT holds the file to log the registry summary report.
		/// </summary>
		public static string REGISTRY_SUMMARY_REPORT = REGISTRY_LOG_FOLDER + "registrySummaryReport.txt";

		/// <summary>
		/// REGISTRY_DETAILED_REPORT holds the file to log the registry detailed report.
		/// </summary>
		public static String REGISTRY_DETAILED_REPORT = REGISTRY_LOG_FOLDER + "registryDetailedReport.txt";

		/// <summary>
		/// PRINT_FOLDER holds the main system folder for printing a string.
		/// </summary>
		public static string PRINT_FOLDER = CODE_HOME + "log/";

		/// <summary>
		/// PRINT_FILE holds the main system file for printing a sting.
		/// </summary>
		public static string PRINT_FILE = PRINT_FOLDER + "print.txt";

		/// <summary>
		/// APPEND_PRINT_FILE holds whether to append or overwrite the PrintFile. 
		/// </summary>
		public static bool APPEND_PRINT_FILE = true;

		/// <summary>
		/// PRINT_STRING_WRITER holds the main system string writer for printing a string. 
		/// need to call the .toString() method to get the final print sting. 
		/// </summary>
		public static StringBuilder PRINT_STRING_WRITER = new StringBuilder();

		/// <summary>
		/// DEFAULT_OUTPUT holds the default output to print. 
		/// </summary>
		public static int DEFAULT_OUTPUT = OSConstant.FILE_OUT;
		
		/// <summary>
		/// MINIMUM_DISKSPACE_TRIGGER holds the minimum disk space before the automatic 
		/// clean up is triggered to delete temporary files. 
		/// </summary>
		public static long MINIMUM_DISKSPACE_TRIGGER = 1000000000; //change?
		
		/// <summary>
		/// MINIMUM_MEMORY_TRIGGER holds the minimum memory before the automatic 
		/// clean up is triggered to get more memory. 
		/// </summary>
		public static long MINIMUM_MEMORY_TRIGGER = 16000; //change?

		/// <summary>
		/// CLEAN_UP_FOLDER holds the folders to clean up. 
		/// </summary>
		public static string[] CLEAN_UP_FOLDERS = {TEMP_FILE_FOLDER, BACKUP_FOLDER, "c:/temp/"}; //change?

		/// <summary>
		/// MAX_JOBIDS_TO_KEEP holds the maximum number of job ids to keep before deleting them.
		/// </summary>
		public static int MAX_JOBIDS_TO_KEEP = 10; //change?

		/*---------------------------------------------
		Time related parameters
		---------------------------------------------*/		
		/// <summary>
		///JOB_MAX_HOUR holds the maximum hours allowed for a job.
		/// </summary>
		public static long JOB_MAX_HOURS = 48; //change?
		/// <summary>
		///JOB_MAX_MINUTE holds the maximum minutes allowed for a job.
		/// </summary>
		public static long JOB_MAX_MINUTES = 0;
		/// <summary>
		///JOB_MAX_SECOND holds the maximum seconds allowed for a job.
		/// </summary>
		public static long JOB_MAX_SECONDS = 0;

		/// <summary>
		/// JOB_MAX_TIME holds the maximum job time in seconds. 
		/// </summary>
		public static double JOB_MAX_TIME = OSParameter.JOB_MAX_HOURS*3600 + OSParameter.JOB_MAX_MINUTES*60 + OSParameter.JOB_MAX_SECONDS; //change?


		/// <summary>
		/// TEMP_FILE_MAX_DAY holds the maximum days allowed to keep a temporary file.
		/// </summary>
		public static long TEMP_FILE_MAX_DAYS = 0;

		/// <summary>
		/// TEMP_FILE_MAX_HOUR holds the maximum hours allowed to keep a temporary file.
		/// </summary>
		public static long TEMP_FILE_MAX_HOURS = 0;

		/// <summary>
		/// TEMP_FILE_MAX_MINUTE holds the maximum minutes allowed to keep a temporary file.
		/// </summary>
		public static long TEMP_FILE_MAX_MINUTES = 1;

		/// <summary>
		/// TEMP_FILE_MAX_SECOND holds the maximum seconds allowed to keep a temporary file.
		/// </summary>
		public static long TEMP_FILE_MAX_SECONDS = 0;

		/// <summary>
		/// TEMP_FILE_MIN_DAY holds the minimum days allowed to keep a temporary file.
		/// </summary>
		public static long TEMP_FILE_MIN_DAYS = 0;

		/// <summary>
		/// TEMP_FILE_MIN_HOUR holds the minimum hours allowed to keep a temporary file.
		/// </summary>
		public static long TEMP_FILE_MIN_HOURS = 0;

		/// <summary>
		/// TEMP_FILE_MIN_MINUTE holds the minimum minutes allowed to keep a temporary file.
		/// </summary>
		public static long TEMP_FILE_MIN_MINUTES = 0;

		/// <summary>
		/// TEMP_FILE_MIN_SECOND holds the minimum seconds allowed to keep a temporary file.
		/// </summary>
		public static long TEMP_FILE_MIN_SECONDS = 30;

		/*---------------------------------------------
		Server related parameters
		---------------------------------------------*/	
		/// <summary>
		/// CPU_SPEED holds the cpu speed of the server. 
		/// </summary>
		public static double CPU_SPEED = Double.PositiveInfinity;

		/// <summary>
		/// MEMORY_SIZE holds the total physical memory of the server. 
		/// </summary>
		public static double MEMORY_SIZE = Double.PositiveInfinity;
		
		/// <summary>
		/// DISK_SPACE holds the total disk space of the server. 
		/// </summary>
		public static double DISK_SPACE = Double.PositiveInfinity;

		/// <summary>
		/// MAX_JOB_NUMBERS holds the maximum number of running jobs allowed per server. 
		/// </summary>
		public static int MAX_JOB_NUMBERS = 1;  //change?

		/// <summary>
		/// MAX_WAITING_NUMBERS holds the maximum number of waiting jobs allowed per service. 
		/// </summary>
		public static int MAX_WAITING_NUMBERS = 10;  //change?

		/// <summary>
		/// SERVICE_POLLING_INTERVAL holds the number of milli-seconds that a service 
		/// periodically carries out maintentance. It is relatively short.  
		/// </summary>
		public static int SERVICE_POLLING_INTERVAL_SHORT = 60000; //change?

		/// <summary>
		/// SERVICE_POLLING_INTERVAL_MEDIUM holds the number of milli-seconds that a service 
		/// periodically carries out maintentance. It is not too short and nor too long. 
		/// </summary>
		public static int SERVICE_POLLING_INTERVAL_MEDIUM = 3600000; //change?

		/// <summary>
		/// SERVICE_POLLING_INTERVAL_LONG holds the number of milli-seconds that a service 
		/// periodically carries out maintentance. It is relatively long.  
		/// </summary>
		public static int SERVICE_POLLING_INTERVAL_LONG = OSConstant.MILLISECONDS_PER_DAY; //change?

		/*---------------------------------------------
		Solver related parameters
		---------------------------------------------*/
		/// <summary>
		/// SOLVER_CLASS_NAME holds the full class name (including name space) of the solver
		/// </summary>
		public static string SOLVER_CLASS_NAME = ""; //change?

		/// <summary>
		/// SOLVER_LIBRARY holds the library file of the solver class. No need if the library is registered or on a class path. 
		/// </summary>
		public static string SOLVER_LIBRARY = ""; 

		/// <summary>
		/// MAXIMUM_TRIAL_NUMBER_FOR_SOLVE holds the maximum number of trials for a (failed) solve 
		/// before the service terminates. 
		/// </summary>
		public static int MAXIMUM_TRIAL_NUMBER_FOR_SOLVE = 1;
	
		/// <summary>
		/// MINIMUM_WAIT_TIME_BEFORE_NEXT_TRIAL holds the minimum wait time (in milliseconds before the 
		/// service tries another solve after the last solve. 
		/// </summary>
		public static int MINIMUM_WAIT_TIME_BEFORE_NEXT_TRIAL  = 1000;
	
		/// <summary>
		/// MAXIMUM_WAIT_TIME_BEFORE_NEXT_TRIAL holds the maximum wait time (in milliseconds before the 
		/// service tries another solve after the last solve. 
		/// </summary>
		public static int MAXIMUM_WAIT_TIME_BEFORE_NEXT_TRIAL  = 30000;

		/// <summary>
		/// REQUIRED_DIRECTORIES_AND_FILES holds the required directories and files for invoking the solver's solve method.
		/// </summary>
		public static string[] REQUIRED_DIRECTORIES_AND_FILES = {};

		/// <summary>
		/// DIRECTORIES_TO_MAKE holds the directories to make before invoking the solver's solve method.
		/// </summary>
		public static string[] DIRECTORIES_TO_MAKE = {};

		/// <summary>
		/// FILES_TO_CREATE holds the files to create before invoking the solver's solve method.
		/// </summary>
		public static string[] FILES_TO_CREATE = {};

		/// <summary>
		/// SAVE_INPUTS holds whether to save the OSiL and OSoL input arguments of the solve or send method.
		/// </summary>
		public static bool SAVE_INPUTS = true;

		/// <summary>
		/// PARSE_INSTANCE_INPUT holds whether to parse the OSiL instance input arguments of the solve or send method. 
		/// </summary>
		public static bool PARSE_INSTANCE_INPUT = true;

		/// <summary>
		/// INPUT_FILES_TO_COPY_FROM holds the names of the input files to copy from before invoking the 
		/// solver's solve method. It should countain the same number of files as in INPUT_FILES_TO_COPY_TO. 
		/// </summary>
		public static string[] INPUT_FILES_TO_COPY_FROM = {};

		/// <summary>
		/// INPUT_FILES_TO_COPY_TO holds the names of the input files to copy to before invoking the 
		/// solver's solve method. It should countain the same number of files as in INPUT_FILES_TO_COPY_FROM.
		/// </summary>
		public static string[] INPUT_FILES_TO_COPY_TO = {};
		
		/// <summary>
		/// INPUT_FILES_TO_MOVE_FROM holds the names of the input files to move from before invoking the 
		/// solver's solve method. It should countain the same number of files as in INPUT_FILES_TO_MOVE_TO. 
		/// </summary>
		public static string[] INPUT_FILES_TO_MOVE_FROM = {};

		/// <summary>
		/// INPUT_FILES_TO_MOVE_TO holds the names of the input files to move to before invoking the 
		/// solver's solve method. It should countain the same number of files as in INPUT_FILES_TO_MOVE_FROM.
		/// </summary>
		public static string[] INPUT_FILES_TO_MOVE_TO = {};

		/// <summary>
		/// OUTPUT_FILES_TO_COPY_FROM holds the names of the output files to copy from after the 
		/// solver's solve method is finished. It should countain the same number of files as in 
		/// OUTPUT_FILES_TO_COPY_TO. 
		/// </summary>
		public static string[] OUTPUT_FILES_TO_COPY_FROM = {};

		/// <summary>
		/// OUTPUT_FILES_TO_COPY_TO holds the names of the output files to copy to after the 
		/// solver's solve method is finished. It should countain the same number of files as in 
		/// OUTPUT_FILES_TO_COPY_FROM. 
		/// </summary>
		public static string[] OUTPUT_FILES_TO_COPY_TO = {};

		/// <summary>
		/// OUTPUT_FILES_TO_MOVE_FROM holds the names of the output files to move from after the 
		/// solver's solve method is finished. It should countain the same number of files as in 
		/// OUTPUT_FILES_TO_MOVE_TO. 
		/// </summary>
		public static string[] OUTPUT_FILES_TO_MOVE_FROM = {};

		/// <summary>
		/// OUTPUT_FILES_TO_MOVE_TO holds the names of the output files to move to after the 
		/// solver's solve method is finished. It should countain the same number of files as in 
		/// OUTPUT_FILES_TO_MOVE_FROM. 
		/// </summary>
		public static string[] OUTPUT_FILES_TO_MOVE_TO = {};

		/// <summary>
		/// FILES_TO_DELETE holds the files to delete after the solver's solve method is finished.
		/// </summary>
		public static string[] FILES_TO_DELETE = {};

		/// <summary>
		/// DIRECTORIES_TO_DELETE holds the directories to delete after the solver's solve method is finished.
		/// </summary>
		public static string[] DIRECTORIES_TO_DELETE = {};

		/// <summary>
		/// PROCESSES_TO_KILL holds the names of the processes to kill after tge sikver's solve method is finished. 
		/// </summary>
		public static string[] PROCESSES_TO_KILL = {"excel"};


		/*---------------------------------------------
		Service site related parameters
		---------------------------------------------*/		

		/// <summary>
		/// SERVICE_NAME holds the service name. 
		/// </summary>
		public static string SERVICE_NAME = "XXXSolverService"; //change!

		/// <summary>
		/// SERVICE_URI holds the service uri. 
		/// </summary>
		public static string SERVICE_URI = "http://localhost/OSSolver/XXXSolverService.asmx"; //change!

		/// <summary>
		/// SERVICE_TYPE holds the service type. 
		/// </summary>
		public static string SERVICE_TYPE = "solver"; //change!


		/// <summary>
		/// OS_SERVICE_SITE holds the site of the OS Registry.
		/// </summary>
		public static string OS_SERVICE_SITE = "http://localhost/";
		
		/// <summary>
		/// OSREGISTRY_SITE holds the site of the OS Registry.
		/// </summary>
		public static string OS_REGISTRY_SITE = OS_SERVICE_SITE + "OSRegistry/OSRegistryService.asmx";  //change!

		/// <summary>
		/// OS_SCHEDULER_SITE holds the site of the OS scheduler.
		/// </summary>
		public static string OS_SCHEDULER_SITE = OS_SERVICE_SITE + "OSScheduler/OSSchedulerService.asmx"; //change!
		
		/// <summary>
		/// SCHEDULER_WITH_REGISTRY holds whether the scheduler service locally sits with the registry service in the same web application.
		/// </summary>
		public static bool SCHEDULER_WITH_REGISTRY = false;

		/*---------------------------------------------
		Mail related parameters
		---------------------------------------------*/
		/// <summary>
		/// SMTP_SERVER holds the smtp server address to send the email. 
		/// </summary>
		public static string SMTP_SERVER = "smtp.comcast.net";//"merle.it.northwestern.edu";  //change?
	
		/// <summary>
		/// FROM_EMAIL holds the from email address to send the email.  
		/// </summary>
		public static string FROM_EMAIL = "maj@northwestern.edu";
		
		/// <summary>
		/// FROM_PASSWORD holds the from email address to send the email.  
		/// </summary>
		public static string FROM_PASSWORD = "";

		/// <summary>
		/// TO_EMAIL holds the to email address to send the email.  
		/// </summary>
		public static string TO_EMAIL = "majxuh@hotmail.com";

		/// <summary>
		/// MAIL_SUBJECT holds the email subject.   
		/// </summary>
		public static string MAIL_SUBJECT ="OS SERVICE NOTIFICATION!!!";

		/// <summary>
		/// MAIL_MESSAGE holds the email message body.   
		/// </summary>
		public static string MAIL_MESSAGE ="Please check the service.";

		/*---------------------------------------------
		Security related parameters
		---------------------------------------------*/
		/// <summary>
		/// REQUIRE_USER_NAME holds whether the service needs user name to be submitted. 
		/// </summary>
		public static bool REQUIRE_USER_NAME = false;

		/// <summary>
		/// REQUIRE_PASSWORD holds whether the service needs a password for each user. 
		/// </summary>
		public static bool REQUIRE_PASSWORD = false; 

		/// <summary>
		/// REQUIRE_LICENSE holds whether the service needs a license number for each user. 
		/// </summary>
		public static bool REQUIRE_LICENSE = false;

		/// <summary>
		/// REQUIRE_ONLY_JOB_ID_TO_RETRIEVE_JOB holds whether only the job id (no user name/password/license) is needed to retrieve a job result. 
		/// </summary>
		public static bool REQUIRE_ONLY_JOB_ID_TO_RETRIEVE_JOB_RESULT = true;

		/// <summary>
		/// REQUIRE_ONLY_JOB_ID_TO_KILL_JOB holds whether only the job id (no user name/password/license) is needed to kill a job. 
		/// </summary>
		public static bool REQUIRE_ONLY_JOB_ID_TO_KILL_JOB = true;

		/// <summary>
		/// MAX_JOBS_PER_USER holds the maximum number of active jobs a user can run.  
		/// </summary>
		public static int MAX_JOBS_PER_USER = 5;

		/// <summary>
		/// USER_NAMES holds all the user names. 
		/// </summary>
		public static string[] USER_NAMES = {};
	
		/// <summary>
		/// PASSWORDS holds the passwords for all the users. 
		/// </summary>
		protected static string[] PASSWORDS = {};
	
		/// <summary>
		/// LICENSES holds the licenses for all the users.  
		/// </summary>
		protected static string[] LICENSES = {};
	
		/// <summary>
		/// ALLOW_IO_OPERATIONS_BY_USERS holds whether the users can carry out io operations (through option files). 
		/// </summary>
		public static bool ALLOW_IO_OPERATIONS_BY_USERS = true;

		/// <summary>
		/// check username and password
		/// </summary>
		/// <param name="userName">holds the user name; can be null if the service requires only the password.</param>
		/// <param name="password">holds the password to check; ; can be null if the service requires only the user name..</param>
		/// <returns>whether the user name and password are correct.</returns>
		public static bool checkUserNameAndPassword(string userName, string password){
			if(REQUIRE_USER_NAME && !REQUIRE_PASSWORD){
				if(userName == null || userName.Length <= 0) return false;
				int n = USER_NAMES==null?0:USER_NAMES.Length;
				for(int i = 0; i < n; i++){
					if(userName.Equals(USER_NAMES[i])){
						return true;
					}
				}
				return false;
			}
			else if(!REQUIRE_USER_NAME && REQUIRE_PASSWORD){
				if(password == null || password.Length <= 0) return false;
				int n = PASSWORDS==null?0:PASSWORDS.Length;
				for(int i = 0; i < n; i++) {
					if(password.Equals(PASSWORDS[i])) {
						return true;
					}
				}
				return false;
			}
			else if(REQUIRE_USER_NAME && REQUIRE_PASSWORD){
				if(userName == null || userName.Length <= 0) return false;
				if(password == null || password.Length <= 0) return false;
				int m = USER_NAMES==null?0:USER_NAMES.Length;
				int n = PASSWORDS==null?0:PASSWORDS.Length;
				if(m != n) return false;
				else{
					for(int i = 0; i < m; i++) {
						if(userName.Equals(USER_NAMES[i]) && password.Equals(PASSWORDS[i])) {
							return true;
						}
					}
					return false;
				}			
			}
			else{
				return true;
			}
		}//checkUserNameAndPassword
	
		/**
		 * check license given a user name and license
		 * @param userName holds the user name. can be null if the service requires only the license. 
		 * @param license holds the license to check.
		 * @return whether the license is correct given the user name (if the user name is required.)
		 */
		public static bool checkLicense(string userName, string license) {
			if(!REQUIRE_USER_NAME && REQUIRE_LICENSE) {
				if(license == null || license.Length <= 0) return false;
				int n = LICENSES==null?0:LICENSES.Length;
				for(int i = 0; i < n; i++) {
					if(license.Equals(LICENSES[i])) {
						return true;
					}
				}
				return false;
			}
			else if(REQUIRE_USER_NAME && REQUIRE_LICENSE) {
				if(userName == null || userName.Length <= 0) return false;
				if(license == null || license.Length <= 0) return false;
				int m = USER_NAMES==null?0:USER_NAMES.Length;
				int n = LICENSES==null?0:LICENSES.Length;
				if(m != n) return false;
				else {
					for(int i = 0; i < m; i++) {
						if(userName.Equals(USER_NAMES[i]) && license.Equals(LICENSES[i])) {
							return true;
						}
					}
					return false;
				}			
			}
			else {
				return true;
			}
		}//checkLicense

		/// <summary>
		/// Get the system password used for communication between system components.
		/// </summary>
		/// <returns>system password in a string. </returns>
		internal static string getSystemPassword(){
			return "OSSystemPassword";
		}//getSystemPassword

		/// <summary>
		/// Check the system password used for communication between system components.
		/// </summary>
		/// <param name="systemPassword">holds the system password used for communication between system components.</param>
		/// <returns>whether the system password is correct. </returns>
		internal static bool checkSystemPassword(String systemPassword){
			if(systemPassword == null || systemPassword.Length <= 0) return false;
			return systemPassword.Equals(getSystemPassword());
		}//getSystemPassword

		/*---------------------------------------------
		XML related parameters
		---------------------------------------------*/
		/// <summary>
		/// VALIDATE holds whether the parser should be validating against the xml schema or not.
		/// </summary>
		public static bool VALIDATE = false;

		/// <summary>
		/// XML_INDENTING holds whether to write out the xml indented. 
		/// </summary>
		public static bool XML_INDENTING = true;

	
		/// <summary>
		/// FML_PUBLIC_SITE holds the value of the FML schema public site.
		/// </summary>
		public static string FML_PUBLIC_SITE = "http://gsbkip.chicagogsb.edu/fml/testproblems/lpfml.xsd";

		/// <summary>
		/// OS_SITE holds the site of optimizationservices.org.
		/// </summary>
		public static string OS_SITE = "http://www.optimizationservices.org";

		/// <summary>
		/// OS_SCHEMA_SITE holds the value of the OSxL schema's public site.
		/// </summary>
		public static string OS_SCHEMA_SITE = "http://www.optimizationservices.org/schemas/";
		
		/// <summary>
		/// XML_ENCODING_STYLE holds the xml encoding style. 
		/// </summary>
		public static string XML_ENCODING_STYLE = "http://schemas.xmlsoap.org/soap/encoding";

		/*---------------------------------------------
		Exception related parameters
		---------------------------------------------*/

		/*---------------------------------------------
		WEBSERVICES related parameters
		---------------------------------------------*/

		/*---------------------------------------------
		XQUERY related parameters
		---------------------------------------------*/

		/*---------------------------------------------
		XPATH related parameters
		---------------------------------------------*/

		/*---------------------------------------------
		XSLT related parameters
		---------------------------------------------*/
		/// <summary>
		/// XSLT_LOCATION holds the location of XSLT; no XSLT file name should be there. 
		/// </summary>
		public static string XSLT_LOCATION = "http://www.optimizationservices.org/stylesheets/";

		/// <summary>
		/// read an osParameter file or string and and set the parameters. 
		/// </summary>
		/// <param name="osParameter">holds the OS Parameter in a string which format follows the OSParameter schema.</param>
		/// <param name="isFile">holds whether the osParameter string is a file name or a string that literally holds the osParameter contents.</param>
		/// <param name="validate">holds whether the reader should be validating against the schema or not.</param>
		/// <returns>whether the osParameter is read and set successfully or not.  </returns>
		public static bool readAndSetOSParameter(string osParameter, bool isFile, bool validate){
			OSParameterReader  osParameterReader = new OSParameterReader(validate);
			bool bRead = false;
			if(isFile){
				bRead = osParameterReader.readFile(osParameter);
			}
			else{
				bRead = osParameterReader.readString(osParameter);			
			}
			if(!bRead) throw new Exception("osParameter string not valid");
			//set the parameters.
			/*---------------------------------------------
			Routine/maintenance related parameters
			---------------------------------------------*/	
			string sValue = "";
			sValue = osParameterReader.getOSParameterValueByName("CODE_DRIVE");
			if(sValue != null && sValue.Length > 0) CODE_DRIVE = sValue;

			sValue = osParameterReader.getOSParameterValueByName("CODE_HOME");
			if(sValue != null && sValue.Length > 0) CODE_HOME = sValue;
		
			sValue = osParameterReader.getOSParameterValueByName("REGISTRY_FILE");
			if(sValue != null && sValue.Length > 0) REGISTRY_FILE = CODE_HOME + sValue;

			sValue = osParameterReader.getOSParameterValueByName("PROCESS_FILE");
			if(sValue != null && sValue.Length > 0) PROCESS_FILE = CODE_HOME + sValue;

			sValue = osParameterReader.getOSParameterValueByName("TEMP_FILE_FOLDER");
			if(sValue != null && sValue.Length > 0) TEMP_FILE_FOLDER = CODE_HOME + sValue;
		
			sValue = osParameterReader.getOSParameterValueByName("LOG_FOLDER");
			if(sValue != null && sValue.Length > 0) LOG_FOLDER = CODE_HOME + sValue;
		
			sValue = osParameterReader.getOSParameterValueByName("LOG_FILE");
			if(sValue != null && sValue.Length > 0) LOG_FILE = LOG_FOLDER + sValue;
		
			sValue = osParameterReader.getOSParameterValueByName("MAX_LOG_FILE_SIZE");
			if(sValue != null && sValue.Length > 0){
				try{
					MAX_LOG_FILE_SIZE = Int64.Parse(sValue);
				} 
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}
			}
		
			sValue = osParameterReader.getOSParameterValueByName("BACKUP_FOLDER");
			if(sValue != null && sValue.Length > 0) BACKUP_FOLDER = CODE_HOME + sValue;
		
			sValue = osParameterReader.getOSParameterValueByName("REGISTRY_LOG_FOLDER");
			if(sValue != null && sValue.Length > 0) REGISTRY_LOG_FOLDER = CODE_HOME + sValue;
		
			sValue =osParameterReader.getOSParameterValueByName("REGISTRY_LOG_FILE");
			if(sValue != null && sValue.Length > 0) REGISTRY_LOG_FILE =  REGISTRY_LOG_FOLDER + sValue;
		
			sValue = osParameterReader.getOSParameterValueByName("REGISTRY_REGISTRATION_FILE");
			if(sValue != null && sValue.Length > 0) REGISTRY_REGISTRATION_FILE = REGISTRY_LOG_FOLDER + sValue;

			sValue = osParameterReader.getOSParameterValueByName("REGISTRY_SUMMARY_REPORT");
			if(sValue != null && sValue.Length > 0) REGISTRY_SUMMARY_REPORT = REGISTRY_LOG_FOLDER + sValue;

			sValue = osParameterReader.getOSParameterValueByName("REGISTRY_DETAILED_REPORT");
			if(sValue != null && sValue.Length > 0) REGISTRY_DETAILED_REPORT = REGISTRY_LOG_FOLDER + sValue;

			sValue = osParameterReader.getOSParameterValueByName("PRINT_FOLDER");
			if(sValue != null && sValue.Length > 0) PRINT_FOLDER = CODE_HOME + sValue;
		
			sValue = osParameterReader.getOSParameterValueByName("PRINT_FILE");
			if(sValue != null && sValue.Length > 0) PRINT_FILE = PRINT_FOLDER + sValue;
		
			sValue = osParameterReader.getOSParameterValueByName("APPEND_PRINT_FILE");
			if(sValue != null && sValue.Length > 0) APPEND_PRINT_FILE = sValue.StartsWith("t")?true:false;
		
			sValue = osParameterReader.getOSParameterValueByName("MINIMUM_DISKSPACE_TRIGGER");
			if(sValue != null && sValue.Length > 0){
				try{
					MINIMUM_DISKSPACE_TRIGGER = Int64.Parse(sValue);
				}
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}
			}		
			sValue = osParameterReader.getOSParameterValueByName("MINIMUM_MEMORY_TRIGGER");
			if(sValue != null && sValue.Length > 0){
				try{
					MINIMUM_MEMORY_TRIGGER =Int64.Parse(sValue);
				}
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}
			}

			sValue = osParameterReader.getOSParameterValueByName("CLEAN_UP_FOLDERS");
			if(sValue != null && sValue.Length > 0){
				ArrayList vValues = CommonUtil.stringToVector(sValue, ",");
				CLEAN_UP_FOLDERS = new string[vValues.Count];
				int iSize = vValues.Count;
				for(int i = 0; i < iSize; i++){
					string sToken = ((string)vValues[i]).Trim();
					if(sToken.IndexOf(":") >= 0 || sToken.StartsWith("/") || sToken.StartsWith("\\")){
						CLEAN_UP_FOLDERS[i] = sToken;
					}
					else{
						CLEAN_UP_FOLDERS[i] = CODE_HOME + sToken;				
					}
				}
			}

			sValue = osParameterReader.getOSParameterValueByName("MAX_JOBIDS_TO_KEEP");
			if(sValue != null && sValue.Length > 0){
				try{
					MAX_JOBIDS_TO_KEEP = Int32.Parse(sValue);
				}
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}
			}
		
			/*---------------------------------------------
			Time related parameters
			---------------------------------------------*/	
		
			sValue = osParameterReader.getOSParameterValueByName("JOB_MAX_HOURS");
			if(sValue != null && sValue.Length > 0){
				try{
					JOB_MAX_HOURS = Int64.Parse(sValue);
				}
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}
			}

			sValue = osParameterReader.getOSParameterValueByName("JOB_MAX_MINUTES");
			if(sValue != null && sValue.Length > 0){
				try{
					JOB_MAX_MINUTES = Int64.Parse(sValue);
				}
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}
			}

			sValue = osParameterReader.getOSParameterValueByName("JOB_MAX_SECONDS");
			if(sValue != null && sValue.Length > 0){
				try{
					JOB_MAX_SECONDS = Int64.Parse(sValue);
				}
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}
			}

			JOB_MAX_TIME = OSParameter.JOB_MAX_HOURS*3600 + OSParameter.JOB_MAX_MINUTES*60 + OSParameter.JOB_MAX_SECONDS;
		
			sValue = osParameterReader.getOSParameterValueByName("TEMP_FILE_MAX_DAYS");
			if(sValue != null && sValue.Length > 0){
				try{
					TEMP_FILE_MAX_DAYS = Int64.Parse(sValue);
				}
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}
			}
		
			sValue = osParameterReader.getOSParameterValueByName("TEMP_FILE_MAX_HOURS");
			if(sValue != null && sValue.Length > 0){
				try{
					TEMP_FILE_MAX_HOURS = Int64.Parse(sValue);
				}
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}
			}

			sValue = osParameterReader.getOSParameterValueByName("TEMP_FILE_MAX_MINUTES");
			if(sValue != null && sValue.Length > 0){
				try{
					TEMP_FILE_MAX_MINUTES = Int64.Parse(sValue);
				}
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}
			}

			sValue = osParameterReader.getOSParameterValueByName("TEMP_FILE_MAX_SECONDS");
			if(sValue != null && sValue.Length > 0){
				try{
					TEMP_FILE_MAX_SECONDS = Int64.Parse(sValue);
				}
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}
			}

			sValue = osParameterReader.getOSParameterValueByName("TEMP_FILE_MIN_DAYS");
			if(sValue != null && sValue.Length > 0){
				try{
					TEMP_FILE_MIN_DAYS = Int64.Parse(sValue);
				}
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}
			}

			sValue = osParameterReader.getOSParameterValueByName("TEMP_FILE_MIN_HOURS");
			if(sValue != null && sValue.Length > 0){
				try{
					TEMP_FILE_MIN_HOURS = Int64.Parse(sValue);
				}
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}
			}

			sValue = osParameterReader.getOSParameterValueByName("TEMP_FILE_MIN_MINUTES");
			if(sValue != null && sValue.Length > 0){
				try{
					TEMP_FILE_MIN_MINUTES = Int64.Parse(sValue);
				}
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}
			}

			sValue = osParameterReader.getOSParameterValueByName("TEMP_FILE_MIN_SECONDS");
			if(sValue != null && sValue.Length > 0){
				try{
					TEMP_FILE_MIN_SECONDS = Int64.Parse(sValue);
				}
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}
			}

			/*---------------------------------------------
			Server related parameters
			---------------------------------------------*/	

			sValue = osParameterReader.getOSParameterValueByName("CPU_SPEED");
			if(sValue != null && sValue.Length > 0){
				if(sValue.IndexOf("INF") >= 0) CPU_SPEED = Double.PositiveInfinity;
				else{
					try{
						CPU_SPEED = Double.Parse(sValue);			
					}
					catch (Exception e) {
						IOUtil.log(e.ToString(), null);
					}
				}
			}
		
			sValue = osParameterReader.getOSParameterValueByName("MEMORY_SIZE");
			if(sValue != null && sValue.Length > 0){
				if(sValue.IndexOf("INF") >= 0) MEMORY_SIZE = Double.PositiveInfinity;
				else{
					try{
						MEMORY_SIZE = Double.Parse(sValue);			
					}
					catch (Exception e) {
						IOUtil.log(e.ToString(), null);
					}
				}
			}

			sValue = osParameterReader.getOSParameterValueByName("DISK_SPACE");
			if(sValue != null && sValue.Length > 0){
				if(sValue.IndexOf("INF") >= 0) DISK_SPACE = Double.PositiveInfinity;
				else{
					try{
						DISK_SPACE = Double.Parse(sValue);			
					}
					catch (Exception e) {
						IOUtil.log(e.ToString(), null);
					}
				}
			}

			sValue = osParameterReader.getOSParameterValueByName("MAX_JOB_NUMBERS");
			if(sValue != null && sValue.Length > 0){
				try{
					MAX_JOB_NUMBERS = Int32.Parse(sValue);
				}
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}			
			}

			sValue = osParameterReader.getOSParameterValueByName("MAX_WAITING_NUMBERS");
			if(sValue != null && sValue.Length > 0){
				try{
					MAX_WAITING_NUMBERS = Int32.Parse(sValue);
				}
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}
			}

			sValue = osParameterReader.getOSParameterValueByName("SERVICE_POLLING_INTERVAL_SHORT");
			if(sValue != null && sValue.Length > 0){
				try{
					SERVICE_POLLING_INTERVAL_SHORT = Int32.Parse(sValue);
				}
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}
			}
		
			sValue = osParameterReader.getOSParameterValueByName("SERVICE_POLLING_INTERVAL_MEDIUM");
			if(sValue != null && sValue.Length > 0){
				try{
					SERVICE_POLLING_INTERVAL_MEDIUM = Int32.Parse(sValue);
				}
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}
			}
		
			sValue = osParameterReader.getOSParameterValueByName("SERVICE_POLLING_INTERVAL_LONG");
			if(sValue != null && sValue.Length > 0){
				try{
					SERVICE_POLLING_INTERVAL_LONG = Int32.Parse(sValue);
				}
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}
			}

			/*---------------------------------------------
			Solver related parameters
			---------------------------------------------*/	
			sValue = osParameterReader.getOSParameterValueByName("SOLVER_CLASS_NAME");
			if(sValue != null && sValue.Length > 0) SOLVER_CLASS_NAME = sValue;

			sValue = osParameterReader.getOSParameterValueByName("SOLVER_LIBRARY");
			if(sValue != null && sValue.Length > 0) SOLVER_LIBRARY = sValue;

			sValue = osParameterReader.getOSParameterValueByName("MAXIMUM_TRIAL_NUMBER_FOR_SOLVE");
			if(sValue != null && sValue.Length > 0){
				try{
					MAXIMUM_TRIAL_NUMBER_FOR_SOLVE = Int32.Parse(sValue);
				}
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}
			}
			sValue = osParameterReader.getOSParameterValueByName("MINIMUM_WAIT_TIME_BEFORE_NEXT_TRIAL");
			if(sValue != null && sValue.Length > 0){
				try{
					MINIMUM_WAIT_TIME_BEFORE_NEXT_TRIAL = Int32.Parse(sValue);
				}
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}
			}

			sValue = osParameterReader.getOSParameterValueByName("MAXIMUM_WAIT_TIME_BEFORE_NEXT_TRIAL");
			if(sValue != null && sValue.Length > 0){
				try{
					MAXIMUM_WAIT_TIME_BEFORE_NEXT_TRIAL = Int32.Parse(sValue);
				}
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}
			}

			sValue = osParameterReader.getOSParameterValueByName("REQUIRED_DIRECTORIES_AND_FILES");
			if(sValue != null && sValue.Length > 0){
				ArrayList vValues = CommonUtil.stringToVector(sValue, ",");
				REQUIRED_DIRECTORIES_AND_FILES = new string[vValues.Count];
				int iSize = vValues.Count;
				for(int i = 0; i < iSize; i++){
					string sToken = ((string)vValues[i]).Trim();
					if(sToken.IndexOf(":") >= 0 || sToken.StartsWith("/") || sToken.StartsWith("\\")){
						REQUIRED_DIRECTORIES_AND_FILES[i] = sToken;
					}
					else{
						REQUIRED_DIRECTORIES_AND_FILES[i] = CODE_HOME + sToken;				
					}
				}
			}

			sValue = osParameterReader.getOSParameterValueByName("DIRECTORIES_TO_MAKE");
			if(sValue != null && sValue.Length > 0){
				ArrayList vValues = CommonUtil.stringToVector(sValue, ",");
				DIRECTORIES_TO_MAKE = new string[vValues.Count];
				int iSize = vValues.Count;
				for(int i = 0; i < iSize; i++){
					string sToken = ((string)vValues[i]).Trim();
					if(sToken.IndexOf(":") >= 0 || sToken.StartsWith("/") || sToken.StartsWith("\\")){
						DIRECTORIES_TO_MAKE[i] = sToken;
					}
					else{
						DIRECTORIES_TO_MAKE[i] = CODE_HOME + sToken;				
					}
				}
			}

			sValue = osParameterReader.getOSParameterValueByName("FILES_TO_CREATE");
			if(sValue != null && sValue.Length > 0){
				ArrayList vValues = CommonUtil.stringToVector(sValue, ",");
				FILES_TO_CREATE = new string[vValues.Count];
				int iSize = vValues.Count;
				for(int i = 0; i < iSize; i++){
					string sToken = ((string)vValues[i]).Trim();
					if(sToken.IndexOf(":") >= 0 || sToken.StartsWith("/") || sToken.StartsWith("\\")){
						FILES_TO_CREATE[i] = sToken;
					}
					else{
						FILES_TO_CREATE[i] = CODE_HOME + sToken;				
					}
				}
			}

			sValue = osParameterReader.getOSParameterValueByName("SAVE_INPUTS");
			if(sValue != null && sValue.Length > 0) SAVE_INPUTS = sValue.StartsWith("t")?true:false;

			sValue = osParameterReader.getOSParameterValueByName("PARSE_INSTANCE_INPUT");
			if(sValue != null && sValue.Length > 0) PARSE_INSTANCE_INPUT = sValue.StartsWith("t")?true:false;

			sValue = osParameterReader.getOSParameterValueByName("INPUT_FILES_TO_MOVE_FROM");
			if(sValue != null && sValue.Length > 0){
				ArrayList vValues = CommonUtil.stringToVector(sValue, ",");
				INPUT_FILES_TO_MOVE_FROM = new string[vValues.Count];
				int iSize = vValues.Count;
				for(int i = 0; i < iSize; i++){
					string sToken = ((string)vValues[i]).Trim();
					if(sToken.IndexOf(":") >= 0 || sToken.StartsWith("/") || sToken.StartsWith("\\")){
						INPUT_FILES_TO_MOVE_FROM[i] = sToken;
					}
					else{
						INPUT_FILES_TO_MOVE_FROM[i] = CODE_HOME + sToken;				
					}
				}
			}

			sValue = osParameterReader.getOSParameterValueByName("SAVE_INPUTS");
			if(sValue != null && sValue.Length > 0) SAVE_INPUTS = sValue.StartsWith("t")?true:false;

			sValue = osParameterReader.getOSParameterValueByName("INPUT_FILES_TO_MOVE_TO");
			if(sValue != null && sValue.Length > 0){
				ArrayList vValues = CommonUtil.stringToVector(sValue, ",");
				INPUT_FILES_TO_MOVE_TO = new string[vValues.Count];
				int iSize = vValues.Count;
				for(int i = 0; i < iSize; i++){
					string sToken = ((string)vValues[i]).Trim();
					if(sToken.IndexOf(":") >= 0 || sToken.StartsWith("/") || sToken.StartsWith("\\")){
						INPUT_FILES_TO_MOVE_TO[i] = sToken;
					}
					else{
						INPUT_FILES_TO_MOVE_TO[i] = CODE_HOME + sToken;				
					}
				}
			}

			sValue = osParameterReader.getOSParameterValueByName("INPUT_FILES_TO_COPY_FROM");
			if(sValue != null && sValue.Length > 0){
				ArrayList vValues = CommonUtil.stringToVector(sValue, ",");
				INPUT_FILES_TO_COPY_FROM = new string[vValues.Count];
				int iSize = vValues.Count;
				for(int i = 0; i < iSize; i++){
					string sToken = ((string)vValues[i]).Trim();
					if(sToken.IndexOf(":") >= 0 || sToken.StartsWith("/") || sToken.StartsWith("\\")){
						INPUT_FILES_TO_COPY_FROM[i] = sToken;
					}
					else{
						INPUT_FILES_TO_COPY_FROM[i] = CODE_HOME + sToken;				
					}
				}
			}

			sValue = osParameterReader.getOSParameterValueByName("INPUT_FILES_TO_COPY_TO");
			if(sValue != null && sValue.Length > 0){
				ArrayList vValues = CommonUtil.stringToVector(sValue, ",");
				INPUT_FILES_TO_COPY_TO = new string[vValues.Count];
				int iSize = vValues.Count;
				for(int i = 0; i < iSize; i++){
					string sToken = ((string)vValues[i]).Trim();
					if(sToken.IndexOf(":") >= 0 || sToken.StartsWith("/") || sToken.StartsWith("\\")){
						INPUT_FILES_TO_COPY_TO[i] = sToken;
					}
					else{
						INPUT_FILES_TO_COPY_TO[i] = CODE_HOME + sToken;				
					}
				}
			}

			sValue = osParameterReader.getOSParameterValueByName("OUTPUT_FILES_TO_COPY_FROM");
			if(sValue != null && sValue.Length > 0){
				ArrayList vValues = CommonUtil.stringToVector(sValue, ",");
				OUTPUT_FILES_TO_COPY_FROM = new string[vValues.Count];
				int iSize = vValues.Count;
				for(int i = 0; i < iSize; i++){
					string sToken = ((string)vValues[i]).Trim();
					if(sToken.IndexOf(":") >= 0 || sToken.StartsWith("/") || sToken.StartsWith("\\")){
						OUTPUT_FILES_TO_COPY_FROM[i] = sToken;
					}
					else{
						OUTPUT_FILES_TO_COPY_FROM[i] = CODE_HOME + sToken;				
					}
				}
			}

			sValue = osParameterReader.getOSParameterValueByName("OUTPUT_FILES_TO_COPY_TO");
			if(sValue != null && sValue.Length > 0){
				ArrayList vValues = CommonUtil.stringToVector(sValue, ",");
				OUTPUT_FILES_TO_COPY_TO = new string[vValues.Count];
				int iSize = vValues.Count;
				for(int i = 0; i < iSize; i++){
					string sToken = ((string)vValues[i]).Trim();
					if(sToken.IndexOf(":") >= 0 || sToken.StartsWith("/") || sToken.StartsWith("\\")){
						OUTPUT_FILES_TO_COPY_TO[i] = sToken;
					}
					else{
						OUTPUT_FILES_TO_COPY_TO[i] = CODE_HOME + sToken;				
					}
				}
			}

			sValue = osParameterReader.getOSParameterValueByName("OUTPUT_FILES_TO_MOVE_FROM");
			if(sValue != null && sValue.Length > 0){
				ArrayList vValues = CommonUtil.stringToVector(sValue, ",");
				OUTPUT_FILES_TO_MOVE_FROM = new string[vValues.Count];
				int iSize = vValues.Count;
				for(int i = 0; i < iSize; i++){
					string sToken = ((string)vValues[i]).Trim();
					if(sToken.IndexOf(":") >= 0 || sToken.StartsWith("/") || sToken.StartsWith("\\")){
						OUTPUT_FILES_TO_MOVE_FROM[i] = sToken;
					}
					else{
						OUTPUT_FILES_TO_MOVE_FROM[i] = CODE_HOME + sToken;				
					}
				}
			}

			sValue = osParameterReader.getOSParameterValueByName("OUTPUT_FILES_TO_MOVE_TO");
			if(sValue != null && sValue.Length > 0){
				ArrayList vValues = CommonUtil.stringToVector(sValue, ",");
				OUTPUT_FILES_TO_MOVE_TO = new string[vValues.Count];
				int iSize = vValues.Count;
				for(int i = 0; i < iSize; i++){
					string sToken = ((string)vValues[i]).Trim();
					if(sToken.IndexOf(":") >= 0 || sToken.StartsWith("/") || sToken.StartsWith("\\")){
						OUTPUT_FILES_TO_MOVE_TO[i] = sToken;
					}
					else{
						OUTPUT_FILES_TO_MOVE_TO[i] = CODE_HOME + sToken;				
					}
				}
			}

			sValue = osParameterReader.getOSParameterValueByName("FILES_TO_DELETE");
			if(sValue != null && sValue.Length > 0){
				ArrayList vValues = CommonUtil.stringToVector(sValue, ",");
				FILES_TO_DELETE = new string[vValues.Count];
				int iSize = vValues.Count;
				for(int i = 0; i < iSize; i++){
					string sToken = ((string)vValues[i]).Trim();
					if(sToken.IndexOf(":") >= 0 || sToken.StartsWith("/") || sToken.StartsWith("\\")){
						FILES_TO_DELETE[i] = sToken;
					}
					else{
						FILES_TO_DELETE[i] = CODE_HOME + sToken;				
					}
				}
			}

			sValue = osParameterReader.getOSParameterValueByName("DIRECTORIES_TO_DELETE");
			if(sValue != null && sValue.Length > 0){
				ArrayList vValues = CommonUtil.stringToVector(sValue, ",");
				DIRECTORIES_TO_DELETE = new string[vValues.Count];
				int iSize = vValues.Count;
				for(int i = 0; i < iSize; i++){
					string sToken = ((string)vValues[i]).Trim();
					if(sToken.IndexOf(":") >= 0 || sToken.StartsWith("/") || sToken.StartsWith("\\")){
						DIRECTORIES_TO_DELETE[i] = sToken;
					}
					else{
						DIRECTORIES_TO_DELETE[i] = CODE_HOME + sToken;				
					}
				}
			}

			sValue = osParameterReader.getOSParameterValueByName("PROCESSES_TO_KILL");
			if(sValue != null && sValue.Length > 0){
				ArrayList vValues = CommonUtil.stringToVector(sValue, ",");
				PROCESSES_TO_KILL = new string[vValues.Count];
				int iSize = vValues.Count;
				for(int i = 0; i < iSize; i++){
					string sToken = ((string)vValues[i]).Trim();
					PROCESSES_TO_KILL[i] = sToken;
				}
			}

			/*---------------------------------------------
			Service site related parameters
			---------------------------------------------*/
			sValue = osParameterReader.getOSParameterValueByName("SERVICE_NAME");
			if(sValue != null && sValue.Length > 0) SERVICE_NAME = sValue;

			sValue = osParameterReader.getOSParameterValueByName("SERVICE_URI");
			if(sValue != null && sValue.Length > 0) SERVICE_URI = sValue;

			sValue = osParameterReader.getOSParameterValueByName("SERVICE_TYPE");
			if(sValue != null && sValue.Length > 0) SERVICE_TYPE = sValue;

			sValue = osParameterReader.getOSParameterValueByName("OS_SERVICE_SITE");
			if(sValue != null && sValue.Length > 0) OS_SERVICE_SITE = sValue;

			sValue = osParameterReader.getOSParameterValueByName("OS_REGISTRY_SITE");
			if(sValue != null && sValue.Length > 0) OS_REGISTRY_SITE = sValue;

			sValue = osParameterReader.getOSParameterValueByName("OS_SCHEDULER_SITE");
			if(sValue != null && sValue.Length > 0) OS_SCHEDULER_SITE = sValue;

			sValue = osParameterReader.getOSParameterValueByName("SCHEDULER_WITH_REGISTRY");
			if(sValue != null && sValue.Length > 0) SCHEDULER_WITH_REGISTRY = sValue.StartsWith("t")?true:false;

			/*---------------------------------------------
			Mail related parameters
			---------------------------------------------*/
			sValue = osParameterReader.getOSParameterValueByName("SMTP_SERVER");
			if(sValue != null && sValue.Length > 0) SMTP_SERVER = sValue;

			sValue = osParameterReader.getOSParameterValueByName("FROM_EMAIL");
			if(sValue != null && sValue.Length > 0) FROM_EMAIL = sValue;

			sValue = osParameterReader.getOSParameterValueByName("FROM_PASSWORD");
			if(sValue != null && sValue.Length > 0) FROM_PASSWORD = sValue;

			sValue = osParameterReader.getOSParameterValueByName("TO_EMAIL");
			if(sValue != null && sValue.Length > 0) TO_EMAIL = sValue;

			sValue = osParameterReader.getOSParameterValueByName("MAIL_SUBJECT");
			if(sValue != null && sValue.Length > 0) MAIL_SUBJECT = sValue;

			sValue = osParameterReader.getOSParameterValueByName("MAIL_MESSAGE");
			if(sValue != null && sValue.Length > 0) MAIL_MESSAGE = sValue;


			/*---------------------------------------------
			Security related parameters
			---------------------------------------------*/
			sValue = osParameterReader.getOSParameterValueByName("REQUIRE_USER_NAME");
			if(sValue != null && sValue.Length > 0) REQUIRE_USER_NAME = sValue.StartsWith("t")?true:false;

			sValue = osParameterReader.getOSParameterValueByName("REQUIRE_PASSWORD");
			if(sValue != null && sValue.Length > 0) REQUIRE_PASSWORD = sValue.StartsWith("t")?true:false;

			sValue = osParameterReader.getOSParameterValueByName("REQUIRE_LICENSE");
			if(sValue != null && sValue.Length > 0) REQUIRE_LICENSE = sValue.StartsWith("t")?true:false;

			sValue = osParameterReader.getOSParameterValueByName("REQUIRE_ONLY_JOB_ID_TO_RETRIEVE_JOB_RESULT");
			if(sValue != null && sValue.Length > 0) REQUIRE_ONLY_JOB_ID_TO_RETRIEVE_JOB_RESULT = sValue.StartsWith("t")?true:false;

			sValue = osParameterReader.getOSParameterValueByName("REQUIRE_ONLY_JOB_ID_TO_KILL_JOB");
			if(sValue != null && sValue.Length > 0) REQUIRE_ONLY_JOB_ID_TO_KILL_JOB = sValue.StartsWith("t")?true:false;

			sValue = osParameterReader.getOSParameterValueByName("MAX_JOBS_PER_USER");
			if(sValue != null && sValue.Length > 0){
				try{
					MAX_JOBS_PER_USER = Int32.Parse(sValue);
				}
				catch (Exception e) {
					IOUtil.log(e.ToString(), null);
				}
			}

			sValue = osParameterReader.getOSParameterValueByName("USER_NAMES");
			if(sValue != null && sValue.Length > 0){
				ArrayList vValues = CommonUtil.stringToVector(sValue, ",");
				USER_NAMES = new string[vValues.Count];
				int iSize = vValues.Count;
				for(int i = 0; i < iSize; i++){
					string sToken = ((string)vValues[i]).Trim();
					USER_NAMES[i] = sToken;	
				}
			}

			sValue = osParameterReader.getOSParameterValueByName("PASSWORDS");
			if(sValue != null && sValue.Length > 0){
				ArrayList vValues = CommonUtil.stringToVector(sValue, ",");
				PASSWORDS = new string[vValues.Count];
				int iSize = vValues.Count;
				for(int i = 0; i < iSize; i++){
					string sToken = ((string)vValues[i]).Trim();
					PASSWORDS[i] = sToken;	
				}
			}

			sValue = osParameterReader.getOSParameterValueByName("LICENSES");
			if(sValue != null && sValue.Length > 0){
				ArrayList vValues = CommonUtil.stringToVector(sValue, ",");
				LICENSES = new string[vValues.Count];
				int iSize = vValues.Count;
				for(int i = 0; i < iSize; i++){
					string sToken = ((string)vValues[i]).Trim();
					LICENSES[i] = sToken;	
				}
			}

			sValue = osParameterReader.getOSParameterValueByName("ALLOW_IO_OPERATIONS_BY_USERS");
			if(sValue != null && sValue.Length > 0) ALLOW_IO_OPERATIONS_BY_USERS = sValue.StartsWith("t")?true:false;

			/*---------------------------------------------
			XML related parameters
			---------------------------------------------*/
			sValue = osParameterReader.getOSParameterValueByName("VALIDATE");
			if(sValue != null && sValue.Length > 0) VALIDATE = sValue.StartsWith("t")?true:false;
		
			sValue = osParameterReader.getOSParameterValueByName("XML_INDENTING");
			if(sValue != null && sValue.Length > 0) XML_INDENTING = sValue.StartsWith("t")?true:false;
		
		
			sValue = osParameterReader.getOSParameterValueByName("FML_PUBLIC_SITE");
			if(sValue != null && sValue.Length > 0) FML_PUBLIC_SITE = sValue;

			sValue = osParameterReader.getOSParameterValueByName("OS_SITE");
			if(sValue != null && sValue.Length > 0) OS_SITE = sValue;

		
			sValue = osParameterReader.getOSParameterValueByName("OS_SCHEMA_SITE");
			if(sValue != null && sValue.Length > 0) OS_SCHEMA_SITE = sValue;

			sValue = osParameterReader.getOSParameterValueByName("XML_ENCODING_STYLE");
			if(sValue != null && sValue.Length > 0) XML_ENCODING_STYLE = sValue;

			sValue = osParameterReader.getOSParameterValueByName("XSLT_LOCATION");
			if(sValue != null && sValue.Length > 0) XSLT_LOCATION = sValue;

			return true;
		}//readAndSetOSParameter
	  

		/// <summary>
		/// write the OSParameter to an xml string. 
		/// @throws Exception if there are errors in writing the osParameter string.  
		/// </summary>
		/// <returns>the osParameter xml string. </returns>
		public static string writeOSParameter(){
			OSParameterWriter osParameterWriter = new OSParameterWriter();
			//TODO write the parameters. 
			return osParameterWriter.writeToString();
		}//writeOSParameter

		/// <summary>
		/// static constructor. 
		/// </summary>
		static OSParameter(){
			string sOSParameterFile = "";
			if(OSParameterFile.NAME !=null || OSParameterFile.NAME.Length > 0){
				sOSParameterFile = OSParameterFile.NAME;
			}
			else{
				sOSParameterFile = PARAMETER_FILE;
			}		
			//String sOSParameterFile = IOUtil.getCurrentDir()+"../../code/OSConfig/OSParameter.xml";
			//In Visual Studio the current directory is the project that the main is in -- e.g. C:/code/csharp/OScsharp/OSMain/bin/
			//in IIS the current directory is C:/WINDOWS/system32/
			//suggestion: have a file in which each service name is mapped to a different osparam file. 
			if(sOSParameterFile != null && sOSParameterFile.Length > 0){
				try {
					bool bRead = readAndSetOSParameter(sOSParameterFile, true, false);
					if(!bRead) throw new Exception("OSParameter.xml configuration file is not read successfully.");
				} 
				catch (Exception e) {
					IOUtil.log(e.Message, null);
				}			
			}
		}//static constructor

	}//class OSParameter
}//namespace


