/**
 * @(#)OSParameter 1.0 05/20/2005
 *
 * Copyright (c) 2005 Impact 
 */
package org.optimizationservices.oscommon.util;

import java.io.StringWriter;
import java.util.Vector;

import javax.servlet.http.HttpServletRequest;

import org.apache.axis.MessageContext;
import org.apache.axis.transport.http.HTTPConstants;
import org.optimizationservices.oscommon.representationparser.OSParameterReader;
import org.optimizationservices.oscommon.representationparser.OSParameterWriter;
import org.optimizationservices.oscommon.util.CommonUtil;
import org.optimizationservices.oscommon.util.IOUtil;
import org.optimizationservices.oscommon.util.OSConstant;
import org.optimizationservices.oscommon.util.OSParameterFile;

/**
 *
 * <P>The <code>OSParameter</code> class stores predefined parameters/options (public an d static)
 * used in other Optimization Services classes.  
 *  
 *
 * </p>
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */
public final class OSParameter{
	/**
	 *
	 * Default constructor. 
	 */
	public OSParameter(){
	}//constructor

	/*---------------------------------------------
	Routine/maintenance related parameters
	---------------------------------------------*/	

	/**
	 * CODE_DRIVE holds the disk drive of the code installation. 
	 */
	public static String CODE_DRIVE = "";  //change?

	/**
	 * CODE_HOME holds the home directory of home.
	 */
	public static String CODE_HOME = "/code/"; //change?

	/**
	 * PARAMETER_FILE holds the file that keeps the parameter information. 
	 */
	public static String PARAMETER_FILE = CODE_HOME + "OSConfig/OSParameter.xml";

	/**
	 * REGISTRY_FILE holds the file that keeps the registry information. 
	 */
	public static String REGISTRY_FILE = CODE_HOME + "OSConfig/OSRegistry.xml";

	/**
	 * PROCESS_FILE holds the file that keeps the service process information in OSpL. 
	 */
	public static String PROCESS_FILE = CODE_HOME + "OSConfig/OSpL.xml";

	/**
	 * TEMP_FILE_FOLDER holds the folder to save temporary files. 
	 */
	public static String TEMP_FILE_FOLDER = CODE_HOME + "temp/";

	/**
	 * LOG_FOLDER holds the main system folder for logging messages and errors.
	 */
	public static String LOG_FOLDER = CODE_HOME + "log/";

	/**
	 * LOG_FILE holds the main system file for logging messages and errors.
	 */
	public static String LOG_FILE = LOG_FOLDER + "log.txt";

	/**
	 * MAX_LOG_FILE_SIZE holds the maximum size of the log file before it is backed up and started again. 
	 */
	public static long MAX_LOG_FILE_SIZE = 5000000;

	/**
	 * BACKUP_FOLDER holds the main system folder for backing up.
	 */
	public static String BACKUP_FOLDER = CODE_HOME + "backup/";

	/**
	 * REGISTRY_LOG_FOLDER holds the main registry folder for logging registy related messages.
	 */
	public static String REGISTRY_LOG_FOLDER = CODE_HOME + "log/";

	/**
	 * REGISTRY_LOG_FILE holds the main registry file for logging registy related messages.
	 */
	public static String REGISTRY_LOG_FILE = REGISTRY_LOG_FOLDER + "registryLog.txt";

	/**
	 * REGISTRY_REGISTRATION_FILE holds the main registry file for logging registration related messages.
	 */
	public static String REGISTRY_REGISTRATION_FILE = REGISTRY_LOG_FOLDER + "registryRegistration.txt";

	/**
	 * REGISTRY_SUMMARY_REPORT holds the file to log the registry summary report.
	 */
	public static String REGISTRY_SUMMARY_REPORT = REGISTRY_LOG_FOLDER + "registrySummaryReport.txt";

	/**
	 * REGISTRY_DETAILED_REPORT holds the file to log the registry detailed report.
	 */
	public static String REGISTRY_DETAILED_REPORT = REGISTRY_LOG_FOLDER + "registryDetailedReport.txt";

	/**
	 * PRINT_FOLDER holds the main system folder for printing a string.
	 */
	public static String PRINT_FOLDER = CODE_HOME + "log/";

	/**
	 * PRINT_FILE holds the main system file for printing a sting.
	 */
	public static String PRINT_FILE = PRINT_FOLDER + "print.txt";

	/**
	 * APPEND_PRINT_FILE holds whether to append or overwrite the PrintFile.
	 */
	public static boolean APPEND_PRINT_FILE = true;

	/**
	 * PRINT_STRING_WRITER holds the main system string writer for printing a string.
	 * need to call the .toString() method to get the final print sting.
	 */
	public static StringWriter PRINT_STRING_WRITER = new StringWriter();

	/**
	 * DEFAULT_OUTPUT holds the default output to print.
	 */
	public static int DEFAULT_OUTPUT = OSConstant.FILE_OUT;

	/**
	 * MINIMUM_DISKSPACE_TRIGGER holds the minimum disk space before the automatic 
	 * clean up is triggered to delete temporary files. 
	 */
	public static long MINIMUM_DISKSPACE_TRIGGER = 1000000000; //change?

	/**
	 * MINIMUM_MEMORY_TRIGGER holds the minimum memory before the automatic 
	 * clean up is triggered to get more memory. 
	 */
	public static long MINIMUM_MEMORY_TRIGGER = 100000000; //change?

	/**
	 * CLEAN_UP_FOLDERS holds the folder to clean up. 
	 */
	public static String[] CLEAN_UP_FOLDERS = {TEMP_FILE_FOLDER, BACKUP_FOLDER}; //change?

	/**
	 * MAX_JOBIDS_TO_KEEP holds the maximum number of job ids to keep before deleting them.
	 */
	public static int MAX_JOBIDS_TO_KEEP = 1000; //change?

	/*---------------------------------------------
	Time related parameters
	---------------------------------------------*/	

	/**
	 * JOB_MAX_HOUR holds the maximum hours allowed for a job.
	 */
	public static long JOB_MAX_HOURS = 24; //change?

	/**
	 * JOB_MAX_MINUTE holds the maximum minutes allowed for a job.
	 */
	public static long JOB_MAX_MINUTES = 0;

	/**
	 * JOB_MAX_SECOND holds the maximum seconds allowed for a job.
	 */
	public static long JOB_MAX_SECONDS = 0;

	/**
	 * JOB_MAX_TIME holds the maximum job time in seconds. 
	 */
	public static double JOB_MAX_TIME = OSParameter.JOB_MAX_HOURS*3600 + OSParameter.JOB_MAX_MINUTES*60 + OSParameter.JOB_MAX_SECONDS;  //change?

	/**
	 * TEMP_FILE_MAX_DAY holds the maximum days allowed to keep a temporary file.
	 */
	public static long TEMP_FILE_MAX_DAYS = 30;

	/**
	 * TEMP_FILE_MAX_HOUR holds the maximum hours allowed to keep a temporary file.
	 */
	public static long TEMP_FILE_MAX_HOURS = 0;

	/**
	 * TEMP_FILE_MAX_MINUTE holds the maximum minutes allowed to keep a temporary file.
	 */
	public static long TEMP_FILE_MAX_MINUTES = 0;

	/**
	 * TEMP_FILE_MAX_SECOND holds the maximum seconds allowed to keep a temporary file.
	 */
	public static long TEMP_FILE_MAX_SECONDS = 0;

	/**
	 * TEMP_FILE_MIN_DAY holds the minimum days allowed to keep a temporary file.
	 */
	public static long TEMP_FILE_MIN_DAYS = 2;

	/**
	 * TEMP_FILE_MIN_HOUR holds the minimum hours allowed to keep a temporary file.
	 */
	public static long TEMP_FILE_MIN_HOURS = 0;

	/**
	 * TEMP_FILE_MIN_MINUTE holds the minimum minutes allowed to keep a temporary file.
	 */
	public static long TEMP_FILE_MIN_MINUTES = 0;

	/**
	 * TEMP_FILE_MIN_SECOND holds the minimum seconds allowed to keep a temporary file.
	 */
	public static long TEMP_FILE_MIN_SECONDS = 0;

	/*---------------------------------------------
	Server related parameters
	---------------------------------------------*/	
	/**
	 * CPU_SPEED holds the cpu speed of the server. 
	 */
	public static double CPU_SPEED = Double.POSITIVE_INFINITY;

	/**
	 * MEMORY_SIZE holds the total physical memory of the server. 
	 */
	public static double MEMORY_SIZE = Double.POSITIVE_INFINITY;

	/**
	 * DISK_SPACE holds the total disk space of the server. 
	 */
	public static double DISK_SPACE = Double.POSITIVE_INFINITY;

	/**
	 * MAX_JOB_NUMBERS holds the maximum number of running jobs allowed per service. 
	 */
	public static int MAX_JOB_NUMBERS = 3;  //change?

	/**
	 * MAX_WAITING_NUMBERS holds the maximum number of waiting jobs allowed per service. 
	 */
	public static int MAX_WAITING_NUMBERS = 5;  //change?

	/**
	 * SERVICE_POLLING_INTERVAL_SHORT holds the number of milli-seconds that a service 
	 * periodically carries out maintentance. It is relatively short.  
	 */
	public static int SERVICE_POLLING_INTERVAL_SHORT = 60000; //change?

	/**
	 * SERVICE_POLLING_INTERVAL_MEDIUM holds the number of milli-seconds that a service 
	 * periodically carries out maintentance. It is not too short and nor too long. 
	 */
	public static int SERVICE_POLLING_INTERVAL_MEDIUM = 3600000; //change?


	/**
	 * SERVICE_POLLING_INTERVAL_LONG holds the number of milli-seconds that a service 
	 * periodically carries out maintentance. It is relatively long.  
	 */
	public static int SERVICE_POLLING_INTERVAL_LONG = OSConstant.MILLISECONDS_PER_DAY; //change?

	/*---------------------------------------------
	Solver related parameters
	---------------------------------------------*/
	/**
	 * SOLVER_CLASS_NAME holds the full class name (including name space) of the solver
	 */
	public static String SOLVER_CLASS_NAME = "org.optimizationservices.oscommon.util.StandardOSSolver"; //change?

	/**
	 * SOLVER_EXECUTABLE holds the solver executable that the StandardOSSolver will launch.  
	 */
	public static String SOLVER_EXECUTABLE = "OSSolverService"; //change?

	/**
	 * OS_SOLVER holds the default solver name that the OSSolverService executable uses, e.g. cbc, clp. 
	 */
	public static String OS_SOLVER = "cbc"; //change?

	/**
	 * MAXIMUM_TRIAL_NUMBER_FOR_SOLVE holds the maximum number of trials for a (failed) solve
	 * before the service terminates. 
	 */
	public static int MAXIMUM_TRIAL_NUMBER_FOR_SOLVE = 1;

	/**
	 * MINIMUM_WAIT_TIME_BEFORE_NEXT_TRIAL holds the minimum wait time (in milliseconds before the 
	 * service tries another solve after the last solve. 
	 */
	public static int MINIMUM_WAIT_TIME_BEFORE_NEXT_TRIAL  = 1000;

	/**
	 * MAXIMUM_WAIT_TIME_BEFORE_NEXT_TRIAL holds the maximum wait time (in milliseconds before the 
	 * service tries another solve after the last solve. 
	 */
	public static int MAXIMUM_WAIT_TIME_BEFORE_NEXT_TRIAL  = 30000;

	/**
	 * REQUIRED_DIRECTORIES_AND_FILES holds the required directories and files for invoking the solver's solve method.
	 */
	public static String[] REQUIRED_DIRECTORIES_AND_FILES = {};

	/**
	 * DIRECTORIES_TO_MAKE holds the directories to make before invoking the solver's solve method.
	 */
	public static String[] DIRECTORIES_TO_MAKE = {};

	/**
	 * FILES_TO_CREATE holds the files to create before invoking the solver's solve method.
	 */
	public static String[] FILES_TO_CREATE = {};

	/**
	 * SAVE_INPUTS holds whether to save the OSiL and OSoL input arguments of the solve or send method.
	 */
	public static boolean SAVE_INPUTS = true;

	/**
	 * PARSE_INSTANCE_INPUT holds whether to parse the OSiL instance input arguments of the solve or send method. 
	 */
	public static boolean PARSE_INSTANCE_INPUT = false;

	/**
	 * INPUT_FILES_TO_MOVE_FROM holds the names of the input files to move from before invoking the 
	 * solver's solve method. It should countain the same number of files as in INPUT_FILES_TO_MOVE_TO. 
	 */
	public static String[] INPUT_FILES_TO_MOVE_FROM = {};

	/**
	 * INPUT_FILES_TO_MOVE_TO holds the names of the input files to move to before invoking the 
	 * solver's solve method. It should countain the same number of files as in INPUT_FILES_TO_MOVE_FROM.
	 */
	public static String[] INPUT_FILES_TO_MOVE_TO = {};

	/**
	 * INPUT_FILES_TO_COPY_FROM holds the names of the input files to copy from before invoking the 
	 * solver's solve method. It should countain the same number of files as in INPUT_FILES_TO_COPY_TO. 
	 */
	public static String[] INPUT_FILES_TO_COPY_FROM = {};

	/**
	 * INPUT_FILES_TO_COPY_TO holds the names of the input files to copy to before invoking the 
	 * solver's solve method. It should countain the same number of files as in INPUT_FILES_TO_COPY_FROM.
	 */
	public static String[] INPUT_FILES_TO_COPY_TO = {};

	/**
	 * OUTPUT_FILES_TO_COPY_FROM holds the names of the output files to copy from after the 
	 * solver's solve method is finished. It should countain the same number of files as in 
	 * OUTPUT_FILES_TO_COPY_TO. 
	 */
	public static String[] OUTPUT_FILES_TO_COPY_FROM = {};

	/**
	 * OUTPUT_FILES_TO_COPY_TO holds the names of the output files to copy to after the 
	 * solver's solve method is finished. It should countain the same number of files as in 
	 * OUTPUT_FILES_TO_COPY_FROM. 
	 */
	public static String[] OUTPUT_FILES_TO_COPY_TO = {};

	/**
	 * OUTPUT_FILES_TO_MOVE_FROM holds the names of the output files to move from after the 
	 * solver's solve method is finished. It should countain the same number of files as in 
	 * OUTPUT_FILES_TO_MOVE_TO. 
	 */
	public static String[] OUTPUT_FILES_TO_MOVE_FROM = {};

	/**
	 * OUTPUT_FILES_TO_MOVE_TO holds the names of the output files to move to after the 
	 * solver's solve method is finished. It should countain the same number of files as in 
	 * OUTPUT_FILES_TO_MOVE_FROM. 
	 */
	public static String[] OUTPUT_FILES_TO_MOVE_TO = {};


	/**
	 * FILES_TO_DELETE holds the files to delete after the solver's solve method is finished.
	 */
	public static String[] FILES_TO_DELETE = {};

	/**
	 * DIRECTORIES_TO_DELETE holds the directories to delete after the solver's solve method is finished.
	 */
	public static String[] DIRECTORIES_TO_DELETE = {};

	/**
	 * PROCESSES_TO_KILL holds the names of the processes to kill after tge sikver's solve method is finished. 
	 */
	public static String[] PROCESSES_TO_KILL = {};

	/*---------------------------------------------
	Service site related parameters
	---------------------------------------------*/	
	/**
	 * SERVICE_NAME holds the service name. 
	 */
	public static String SERVICE_NAME = "OSSolverService";  //change!

	/**
	 * SERVICE_EXTENSION holds the service extension. 
	 */
	public static String SERVICE_EXTENSION = "jws";  //change!

	/**
	 * SERVICE_FOLDER holds the service folder. 
	 */
	public static String SERVICE_FOLDER = "os";  //change!

	/**
	 * SERVICE_PORT holds the service port. 
	 */
	public static String SERVICE_PORT = "8080";  //change!

	/**
	 * SERVICE_HOST holds the service host. 
	 */
	public static String SERVICE_HOST = "http://localhost";  //change!

	/**
	 * SERVICE_URI holds the service uri. 
	 */
	public static String SERVICE_URI = SERVICE_HOST+":"+SERVICE_PORT+"/"+SERVICE_FOLDER+"/"+SERVICE_NAME + "." + SERVICE_EXTENSION; // http://localhost:8080/os/OSSolverService.jws"; //change!

	/**
	 * OS_SERVICE_SITE holds the main site of the OS services.
	 */
	public static String OS_SERVICE_SITE = SERVICE_HOST+":"+SERVICE_PORT+"/"+SERVICE_FOLDER; 

	/**
	 * SERVICE_TYPE holds the service type. 
	 */
	public static String SERVICE_TYPE = "solver"; //change!


	/**
	 * OS_REGISTRY_SITE holds the site of the OS Registry.
	 */
	public static String OS_REGISTRY_SITE = OS_SERVICE_SITE + "/osregistry/OSRegistryService.jws"; //change!

	/**
	 * OS_SCHEDULER_SITE holds the site of the OS scheduler.
	 */
	public static String OS_SCHEDULER_SITE = OS_SERVICE_SITE + "/osscheduler/OSSchedulerService.jws"; //change!

	/**
	 * SCHEDULER_WITH_REGISTRY holds whether the scheduler service locally sits with the registry service in the same web application.
	 */	
	public static boolean SCHEDULER_WITH_REGISTRY = true; 

	/*---------------------------------------------
	Mail related parameters
	---------------------------------------------*/
	/**
	 * SMTP_SERVER holds the smtp server address to send the email. 
	 */
	public static String SMTP_SERVER = "";//e.g. "smtp.comcast.net";  //change?

	/**
	 * FROM_EMAIL holds the from email address to send the email. 
	 */
	public static String FROM_EMAIL = "optservorg@optimizationservices.org"; 

	/**
	 * SMTP_USER holds the smtp user to send the email. 
	 */
	public static String SMTP_USER = ""; 

	/**
	 * SMTP_PASSWORD holds the smtp server password to send the email. 
	 */
	public static String SMTP_PASSWORD = "";

	/**
	 * CC_EMAIL holds the to email address to cc the email. 
	 */
	public static String CC_EMAIL = "";

	/**
	 * BCC_EMAIL holds the to email address to bcc the email. 
	 */
	public static String BCC_EMAIL = "";

	/**
	 * TO_EMAIL holds the to email address to send the email. 
	 */
	public static String TO_EMAIL = ""; //e.g. maj@northwestern.edu

	/**
	 * MAIL_SUBJECT holds the email subject.  
	 */
	public static String MAIL_SUBJECT ="OS SERVICE NOTIFICATION!!!";

	/**
	 * MAIL_MESSAGE holds the email message body.  
	 */
	public static String MAIL_MESSAGE ="Please check the service.";

	/**
	 * MAIL_ATTACHED_FILES  holds an array of the file names (w/ full paths) to be attached; 
	 * no file attached if null. Use comma (,), semicolon (;) or space to delimit if multiple file names. 
	 */
	public static String MAIL_ATTACHED_FILES ="";

	/*---------------------------------------------
	Security related parameters
	---------------------------------------------*/
	/**
	 * REQUIRE_USER_NAME holds whether the service needs user name to be submitted. 
	 */
	public static boolean REQUIRE_USER_NAME = false;

	/**
	 * REQUIRE_PASSWORD holds whether the service needs a password for each user. 
	 */
	public static boolean REQUIRE_PASSWORD = false; 

	/**
	 * REQUIRE_LICENSE holds whether the service needs a license number for each user. 
	 */
	public static boolean REQUIRE_LICENSE = false;

	/**
	 * REQUIRE_ONLY_JOB_ID_TO_RETRIEVE_JOB_RESULT holds whether only the job id (no user name/password/license) is needed to retrieve a job result. 
	 */
	public static boolean REQUIRE_ONLY_JOB_ID_TO_RETRIEVE_JOB_RESULT = true;

	/**
	 * REQUIRE_ONLY_JOB_ID_TO_KILL_JOB holds whether only the job id (no user name/password/license) is needed to kill a job. 
	 */
	public static boolean REQUIRE_ONLY_JOB_ID_TO_KILL_JOB = true;

	/**
	 * MAX_JOBS_PER_USER holds the maximum number of active jobs a user can run.  
	 */
	public static int MAX_JOBS_PER_USER = -1;

	/**
	 * USER_NAMES holds all the user names. 
	 */
	public static String[] USER_NAMES = {};

	/**
	 * PASSWORDS holds the passwords for all the users. 
	 */
	protected static String[] PASSWORDS = {};

	/**
	 * LICENSES holds the licenses for all the users.  
	 */
	protected static String[] LICENSES = {};

	/**
	 * ALLOW_IO_OPERATIONS_BY_USERS holds whether the users can carry out io operations (through option files). 
	 */
	public static boolean ALLOW_IO_OPERATIONS_BY_USERS = true;

	/**
	 * check user name and password.
	 * @param userName holds the user name; can be null if the service requires only the password. 
	 * @param password holds the password to check; can be null if the service requires only the user name.
	 * @return whether the user name and password are correct. 
	 */
	public static boolean checkUserNameAndPassword(String userName, String password){
		if(REQUIRE_USER_NAME && !REQUIRE_PASSWORD){
			if(userName == null || userName.length() <= 0) return false;
			int n = USER_NAMES==null?0:USER_NAMES.length;
			for(int i = 0; i < n; i++){
				if(userName.equals(USER_NAMES[i])){
					return true;
				}
			}
			return false;
		}
		else if(!REQUIRE_USER_NAME && REQUIRE_PASSWORD){
			if(password == null || password.length() <= 0) return false;
			int n = PASSWORDS==null?0:PASSWORDS.length;
			for(int i = 0; i < n; i++){
				if(password.equals(PASSWORDS[i])){
					return true;
				}
			}
			return false;
		}
		else if(REQUIRE_USER_NAME && REQUIRE_PASSWORD){
			if(userName == null || userName.length() <= 0) return false;
			if(password == null || password.length() <= 0) return false;
			int m = USER_NAMES==null?0:USER_NAMES.length;
			int n = PASSWORDS==null?0:PASSWORDS.length;
			if(m != n) return false;
			else{
				for(int i = 0; i < m; i++){
					if(userName.equals(USER_NAMES[i]) && password.equals(PASSWORDS[i])){
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
	public static boolean checkLicense(String userName, String license){
		if(!REQUIRE_USER_NAME && REQUIRE_LICENSE){
			if(license == null || license.length() <= 0) return false;
			int n = LICENSES==null?0:LICENSES.length;
			for(int i = 0; i < n; i++){
				if(license.equals(LICENSES[i])){
					return true;
				}
			}
			return false;
		}
		else if(REQUIRE_USER_NAME && REQUIRE_LICENSE){
			if(userName == null || userName.length() <= 0) return false;
			if(license == null || license.length() <= 0) return false;
			int m = USER_NAMES==null?0:USER_NAMES.length;
			int n = LICENSES==null?0:LICENSES.length;
			if(m != n) return false;
			else{
				for(int i = 0; i < m; i++){
					if(userName.equals(USER_NAMES[i]) && license.equals(LICENSES[i])){
						return true;
					}
				}
				return false;
			}			
		}
		else{
			return true;
		}
	}//checkLicense

	/**
	 * Get the system password used for communication between system components.
	 *  
	 * @return system password in a string. 
	 */
	public static String getSystemPassword(){
		String sSystemPassword = "OSSystemPassword";
		return sSystemPassword;
	}//getSystemPassword

	/**
	 * Check the system password used for communication between system components.
	 *  
	 * @param systemPassword holds the system password used for communication between system components.
	 * @return whether the system password is correct. 
	 */
	public static boolean checkSystemPassword(String systemPassword){
		if(systemPassword == null || systemPassword.length() <= 0) return false;
		return systemPassword.equals(getSystemPassword());
	}//getSystemPassword

	/*---------------------------------------------
	XML related parameters
	---------------------------------------------*/
	/**
	 * VALIDATE holds whether the parser should be validating against the xml schema or not.
	 */
	public static boolean VALIDATE = false;

	/**
	 * XML_INDENTING holds whether to write out the xml indented. 
	 */
	public static boolean XML_INDENTING = true;

	/**
	 * FML_PUBLIC_SITE holds the value of the FML schema public site.
	 */
	public static String FML_PUBLIC_SITE = "http://gsbkip.chicagogsb.edu/fml/testproblems/lpfml.xsd";

	/**
	 * OS_SITE holds the site of optimizationservices.org.
	 */
	public static String OS_SITE = "http://www.optimizationservices.org";

	/**
	 * OS_SCHEMA_SITE holds the value of the OSxL schema's public site.
	 */
	public static String OS_SCHEMA_SITE = "http://www.optimizationservices.org/schemas/";

	/**
	 * XML_ENCODING_STYLE holds the xml encoding style. 
	 */
	public static String XML_ENCODING_STYLE = "http://schemas.xmlsoap.org/soap/encoding";


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

	/**
	 * XSLT_LOCATION holds the location of XSLT; no XSLT file name should be there. 
	 */
	public static String XSLT_LOCATION = "http://www.optimizationservices.org/stylesheets/";

	/**
	 * read an osParameter file or string and and set the parameters. 
	 * 
	 * @param osParameter holds the OS Parameter in a string which format follows the
	 * OSParameter schema.
	 * @param isFile holds whether the osParameter string is a file name or a string that literally holds the osParameter contents.  
	 * @param validate holds whether the reader should be validating against the schema or not.
	 * @return whether the osParameter is read and set successfully or not.  
	 */
	public static boolean readAndSetOSParameter(String osParameter, boolean isFile, boolean validate){
		OSParameterReader  osParameterReader = new OSParameterReader(validate);
		boolean bRead = false;
		try{
			if(isFile){
				bRead = osParameterReader.readFile(osParameter);
			}
			else{
				bRead = osParameterReader.readString(osParameter);			
			}			
		}
		catch(Exception e){
			bRead = false;
			IOUtil.log("osParameter string not valid", null);
		}

		//set the parameters.
		/*---------------------------------------------
		Routine/maintenance related parameters
		---------------------------------------------*/	
		String sValue = "";
		if(bRead) sValue = osParameterReader.getOSParameterValueByName("SERVICE_FOLDER");
		if(sValue != null && sValue.length() > 0) SERVICE_FOLDER = sValue;
		else{
			try{
				MessageContext messageContext = MessageContext.getCurrentContext();
				//HttpServlet servlet = (HttpServlet)messageContext.getProperty(HTTPConstants.MC_HTTP_SERVLET);
				//ServletContext servletContext = (ServletContext)servlet.getServletContext();
				HttpServletRequest request = (HttpServletRequest)messageContext.getProperty(HTTPConstants.MC_HTTP_SERVLETREQUEST);
				//HttpSession session =((HttpServletRequest)messageContext.getProperty(HTTPConstants.MC_HTTP_SERVLETREQUEST)).getSession();		
				SERVICE_FOLDER = request.getContextPath();
				if(SERVICE_FOLDER != null && SERVICE_FOLDER.length() > 0)SERVICE_FOLDER = SERVICE_FOLDER.substring(1);
			}
			catch(Exception e){

			}
			if(SERVICE_FOLDER == null || SERVICE_FOLDER.length() <= 0) SERVICE_FOLDER = "os";	
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("CODE_HOME");
		if(sValue != null && sValue.length() > 0) CODE_HOME = sValue;
		else{
			String sDir = IOUtil.getCurrentDir();
			if(sDir.toLowerCase().endsWith("bin") || 
					sDir.toLowerCase().endsWith("bin\\") ||
					sDir.toLowerCase().endsWith("bin/")){
				int iIndex = sDir.lastIndexOf("bin");
				sDir = sDir.substring(0, iIndex);
			}
			if(!sDir.endsWith("/")){
				sDir += "/";
			}

			CODE_HOME = sDir+= "webapps/"+ SERVICE_FOLDER+"/WEB-INF/code/";
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("CODE_DRIVE");
		if(sValue != null && sValue.length() > 0) CODE_DRIVE = sValue;
		else{
			String sOS = System.getProperty("os.name").toLowerCase();
			if(CODE_DRIVE == null || CODE_DRIVE.length() <= 0){
				if(sOS.toLowerCase().indexOf("window") >= 0){
					CODE_DRIVE = CODE_HOME.trim().substring(0, 2);
				}
				else{ //nix system
					try{
						CODE_DRIVE = IOUtil.getUnixDrive(".");
					}
					catch(Exception e){
						CODE_DRIVE = "c:";
					}
				}
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("REGISTRY_FILE");
		if(sValue != null && sValue.length() > 0) REGISTRY_FILE = CODE_HOME + sValue;
		else REGISTRY_FILE = CODE_HOME + "OSConfig/OSRegistry.xml";

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("PROCESS_FILE");
		if(sValue != null && sValue.length() > 0) PROCESS_FILE = CODE_HOME + sValue;
		else PROCESS_FILE = CODE_HOME + "OSConfig/OSpL.xml";

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("TEMP_FILE_FOLDER");
		if(sValue != null && sValue.length() > 0) TEMP_FILE_FOLDER = CODE_HOME + sValue;
		else TEMP_FILE_FOLDER = CODE_HOME + "temp/"; 

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("LOG_FOLDER");
		if(sValue != null && sValue.length() > 0) LOG_FOLDER = CODE_HOME + sValue;
		else LOG_FOLDER = CODE_HOME + "log/";

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("LOG_FILE");
		if(sValue != null && sValue.length() > 0) LOG_FILE = LOG_FOLDER + sValue;
		else LOG_FILE = LOG_FOLDER + "log.txt";

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("MAX_LOG_FILE_SIZE");
		if(sValue != null && sValue.length() > 0){
			try {
				MAX_LOG_FILE_SIZE = Long.parseLong(sValue);	
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("BACKUP_FOLDER");
		if(sValue != null && sValue.length() > 0) BACKUP_FOLDER = CODE_HOME + sValue;
		else BACKUP_FOLDER = CODE_HOME + "backup/";

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("REGISTRY_LOG_FOLDER");
		if(sValue != null && sValue.length() > 0) REGISTRY_LOG_FOLDER = CODE_HOME + sValue;
		else REGISTRY_LOG_FOLDER = CODE_HOME + "log/";

		if(bRead) sValue =osParameterReader.getOSParameterValueByName("REGISTRY_LOG_FILE");
		if(sValue != null && sValue.length() > 0) REGISTRY_LOG_FILE =  REGISTRY_LOG_FOLDER + sValue;
		else REGISTRY_LOG_FILE = REGISTRY_LOG_FOLDER + "registryLog.txt";

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("REGISTRY_REGISTRATION_FILE");
		if(sValue != null && sValue.length() > 0) REGISTRY_REGISTRATION_FILE = REGISTRY_LOG_FOLDER + sValue;
		else REGISTRY_REGISTRATION_FILE = REGISTRY_LOG_FOLDER + "registryRegistration.txt";

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("REGISTRY_SUMMARY_REPORT");
		if(sValue != null && sValue.length() > 0) REGISTRY_SUMMARY_REPORT = REGISTRY_LOG_FOLDER + sValue;
		else REGISTRY_SUMMARY_REPORT = REGISTRY_LOG_FOLDER + "registrySummaryReport.txt";

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("REGISTRY_DETAILED_REPORT");
		if(sValue != null && sValue.length() > 0) REGISTRY_DETAILED_REPORT = REGISTRY_LOG_FOLDER + sValue;
		else REGISTRY_DETAILED_REPORT = REGISTRY_LOG_FOLDER + "registryDetailedReport.txt";

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("PRINT_FOLDER");
		if(sValue != null && sValue.length() > 0) PRINT_FOLDER = CODE_HOME + sValue;
		else PRINT_FOLDER = CODE_HOME + "log/";

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("PRINT_FILE");
		if(sValue != null && sValue.length() > 0) PRINT_FILE = PRINT_FOLDER + sValue;
		else PRINT_FILE = PRINT_FOLDER + "print.txt";

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("APPEND_PRINT_FILE");
		if(sValue != null && sValue.length() > 0) APPEND_PRINT_FILE = sValue.startsWith("t")?true:false;

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("MINIMUM_DISKSPACE_TRIGGER");
		if(sValue != null && sValue.length() > 0){
			try{
				MINIMUM_DISKSPACE_TRIGGER = Long.parseLong(sValue);
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("MINIMUM_MEMORY_TRIGGER");
		if(sValue != null && sValue.length() > 0){
			try{
				MINIMUM_MEMORY_TRIGGER =Long.parseLong(sValue);
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("CLEAN_UP_FOLDERS");
		if(sValue != null && sValue.length() > 0){
			Vector<String> vValues = CommonUtil.stringToVector(sValue, ",");
			CLEAN_UP_FOLDERS = new String[vValues.size()];
			int iSize = vValues.size();
			for(int i = 0; i < iSize; i++){
				String sToken = ((String)vValues.elementAt(i)).trim();
				if(sToken.indexOf(":") >= 0 || sToken.startsWith("/") || sToken.startsWith("\\")){
					CLEAN_UP_FOLDERS[i] = sToken;
				}
				else{
					CLEAN_UP_FOLDERS[i] = CODE_HOME + sToken;				
				}
			}
		}
		else{
			CLEAN_UP_FOLDERS[0] = TEMP_FILE_FOLDER;
			CLEAN_UP_FOLDERS[1] = BACKUP_FOLDER; 
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("MAX_JOBIDS_TO_KEEP");
		if(sValue != null && sValue.length() > 0){
			try{
				MAX_JOBIDS_TO_KEEP = Integer.parseInt(sValue);
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}

		/*---------------------------------------------
		Time related parameters
		---------------------------------------------*/	

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("JOB_MAX_HOURS");
		if(sValue != null && sValue.length() > 0){
			try{
				JOB_MAX_HOURS = Long.parseLong(sValue);
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("JOB_MAX_MINUTES");
		if(sValue != null && sValue.length() > 0){
			try{
				JOB_MAX_MINUTES = Long.parseLong(sValue);
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("JOB_MAX_SECONDS");
		if(sValue != null && sValue.length() > 0){
			try{
				JOB_MAX_SECONDS = Long.parseLong(sValue);
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}

		JOB_MAX_TIME = OSParameter.JOB_MAX_HOURS*3600 + OSParameter.JOB_MAX_MINUTES*60 + OSParameter.JOB_MAX_SECONDS;

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("TEMP_FILE_MAX_DAYS");
		if(sValue != null && sValue.length() > 0){
			try{
				TEMP_FILE_MAX_DAYS = Long.parseLong(sValue);
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("TEMP_FILE_MAX_HOURS");
		if(sValue != null && sValue.length() > 0){
			try{
				TEMP_FILE_MAX_HOURS = Long.parseLong(sValue);
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("TEMP_FILE_MAX_MINUTES");
		if(sValue != null && sValue.length() > 0){
			try{
				TEMP_FILE_MAX_MINUTES = Long.parseLong(sValue);
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("TEMP_FILE_MAX_SECONDS");
		if(sValue != null && sValue.length() > 0){
			try{
				TEMP_FILE_MAX_SECONDS = Long.parseLong(sValue);
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("TEMP_FILE_MIN_DAYS");
		if(sValue != null && sValue.length() > 0){
			try{
				TEMP_FILE_MIN_DAYS = Long.parseLong(sValue);
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("TEMP_FILE_MIN_HOURS");
		if(sValue != null && sValue.length() > 0){
			try{
				TEMP_FILE_MIN_HOURS = Long.parseLong(sValue);
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("TEMP_FILE_MIN_MINUTES");
		if(sValue != null && sValue.length() > 0){
			try{	
				TEMP_FILE_MIN_MINUTES = Long.parseLong(sValue);
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("TEMP_FILE_MIN_SECONDS");
		if(sValue != null && sValue.length() > 0){
			try{
				TEMP_FILE_MIN_SECONDS = Long.parseLong(sValue);
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}

		/*---------------------------------------------
		Server related parameters
		---------------------------------------------*/	

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("CPU_SPEED");
		if(sValue != null && sValue.length() > 0){
			if(sValue.indexOf("INF") >= 0) CPU_SPEED = Double.POSITIVE_INFINITY;
			else {
				try {
					CPU_SPEED = Double.parseDouble(sValue);								
				} 
				catch (Exception e) {
					IOUtil.log(IOUtil.exceptionStackToString(e), null);
				}			
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("MEMORY_SIZE");
		if(sValue != null && sValue.length() > 0){
			if(sValue.indexOf("INF") >= 0) MEMORY_SIZE = Double.POSITIVE_INFINITY;
			else{
				try {
					MEMORY_SIZE = Double.parseDouble(sValue);								
				} 
				catch (Exception e) {
					IOUtil.log(IOUtil.exceptionStackToString(e), null);
				}
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("DISK_SPACE");
		if(sValue != null && sValue.length() > 0){
			if(sValue.indexOf("INF") >= 0) DISK_SPACE = Double.POSITIVE_INFINITY;
			else{
				try {
					DISK_SPACE = Double.parseDouble(sValue);								
				} 
				catch (Exception e) {
					IOUtil.log(IOUtil.exceptionStackToString(e), null);
				}
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("MAX_JOB_NUMBERS");
		if(sValue != null && sValue.length() > 0){
			try{
				MAX_JOB_NUMBERS = Integer.parseInt(sValue);
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("MAX_WAITING_NUMBERS");
		if(sValue != null && sValue.length() > 0){
			try{
				MAX_WAITING_NUMBERS = Integer.parseInt(sValue);
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("SERVICE_POLLING_INTERVAL_SHORT");
		if(sValue != null && sValue.length() > 0){
			try{
				SERVICE_POLLING_INTERVAL_SHORT = Integer.parseInt(sValue);
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("SERVICE_POLLING_INTERVAL_MEDIUM");
		if(sValue != null && sValue.length() > 0){
			try{
				SERVICE_POLLING_INTERVAL_MEDIUM = Integer.parseInt(sValue);
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("SERVICE_POLLING_INTERVAL_LONG");
		if(sValue != null && sValue.length() > 0){
			try{
				SERVICE_POLLING_INTERVAL_LONG = Integer.parseInt(sValue);
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}

		/*---------------------------------------------
		Solver related parameters
		---------------------------------------------*/	
		if(bRead) sValue = osParameterReader.getOSParameterValueByName("SOLVER_CLASS_NAME");
		if(sValue != null && sValue.length() > 0) SOLVER_CLASS_NAME = sValue;

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("SOLVER_EXECUTABLE");
		if(sValue != null && sValue.length() > 0) SOLVER_EXECUTABLE = sValue;

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("OS_SOLVER");
		if(sValue != null && sValue.length() > 0) OS_SOLVER = sValue;


		if(bRead) sValue = osParameterReader.getOSParameterValueByName("MAXIMUM_TRIAL_NUMBER_FOR_SOLVE");
		if(sValue != null && sValue.length() > 0){
			try{
				MAXIMUM_TRIAL_NUMBER_FOR_SOLVE = Integer.parseInt(sValue);
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}
		if(bRead) sValue = osParameterReader.getOSParameterValueByName("MINIMUM_WAIT_TIME_BEFORE_NEXT_TRIAL");
		if(sValue != null && sValue.length() > 0){
			try{
				MINIMUM_WAIT_TIME_BEFORE_NEXT_TRIAL = Integer.parseInt(sValue);
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("MAXIMUM_WAIT_TIME_BEFORE_NEXT_TRIAL");
		if(sValue != null && sValue.length() > 0){
			try{
				MAXIMUM_WAIT_TIME_BEFORE_NEXT_TRIAL = Integer.parseInt(sValue);
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("REQUIRED_DIRECTORIES_AND_FILES");
		if(sValue != null && sValue.length() > 0){
			Vector<String> vValues = CommonUtil.stringToVector(sValue, ",");
			REQUIRED_DIRECTORIES_AND_FILES = new String[vValues.size()];
			int iSize = vValues.size();
			for(int i = 0; i < iSize; i++){
				String sToken = ((String)vValues.elementAt(i)).trim();
				if(sToken.indexOf(":") >= 0 || sToken.startsWith("/") || sToken.startsWith("\\")){
					REQUIRED_DIRECTORIES_AND_FILES[i] = sToken;
				}
				else{
					REQUIRED_DIRECTORIES_AND_FILES[i] = CODE_HOME + sToken;				
				}
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("DIRECTORIES_TO_MAKE");
		if(sValue != null && sValue.length() > 0){
			Vector<String> vValues = CommonUtil.stringToVector(sValue, ",");
			DIRECTORIES_TO_MAKE = new String[vValues.size()];
			int iSize = vValues.size();
			for(int i = 0; i < iSize; i++){
				String sToken = ((String)vValues.elementAt(i)).trim();
				if(sToken.indexOf(":") >= 0 || sToken.startsWith("/") || sToken.startsWith("\\")){
					DIRECTORIES_TO_MAKE[i] = sToken;
				}
				else{
					DIRECTORIES_TO_MAKE[i] = CODE_HOME + sToken;				
				}
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("FILES_TO_CREATE");
		if(sValue != null && sValue.length() > 0){
			Vector<String> vValues = CommonUtil.stringToVector(sValue, ",");
			FILES_TO_CREATE = new String[vValues.size()];
			int iSize = vValues.size();
			for(int i = 0; i < iSize; i++){
				String sToken = ((String)vValues.elementAt(i)).trim();
				if(sToken.indexOf(":") >= 0 || sToken.startsWith("/") || sToken.startsWith("\\")){
					FILES_TO_CREATE[i] = sToken;
				}
				else{
					FILES_TO_CREATE[i] = CODE_HOME + sToken;				
				}
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("SAVE_INPUTS");
		if(sValue != null && sValue.length() > 0) SAVE_INPUTS = sValue.startsWith("t")?true:false;

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("PARSE_INSTANCE_INPUT");
		if(sValue != null && sValue.length() > 0) PARSE_INSTANCE_INPUT = sValue.startsWith("t")?true:false;

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("INPUT_FILES_TO_MOVE_FROM");
		if(sValue != null && sValue.length() > 0){
			Vector<String> vValues = CommonUtil.stringToVector(sValue, ",");
			INPUT_FILES_TO_MOVE_FROM = new String[vValues.size()];
			int iSize = vValues.size();
			for(int i = 0; i < iSize; i++){
				String sToken = ((String)vValues.elementAt(i)).trim();
				if(sToken.indexOf(":") >= 0 || sToken.startsWith("/") || sToken.startsWith("\\")){
					INPUT_FILES_TO_MOVE_FROM[i] = sToken;
				}
				else{
					INPUT_FILES_TO_MOVE_FROM[i] = CODE_HOME + sToken;				
				}
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("SAVE_INPUTS");
		if(sValue != null && sValue.length() > 0) SAVE_INPUTS = sValue.startsWith("t")?true:false;

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("INPUT_FILES_TO_MOVE_TO");
		if(sValue != null && sValue.length() > 0){
			Vector<String> vValues = CommonUtil.stringToVector(sValue, ",");
			INPUT_FILES_TO_MOVE_TO = new String[vValues.size()];
			int iSize = vValues.size();
			for(int i = 0; i < iSize; i++){
				String sToken = ((String)vValues.elementAt(i)).trim();
				if(sToken.indexOf(":") >= 0 || sToken.startsWith("/") || sToken.startsWith("\\")){
					INPUT_FILES_TO_MOVE_TO[i] = sToken;
				}
				else{
					INPUT_FILES_TO_MOVE_TO[i] = CODE_HOME + sToken;				
				}
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("INPUT_FILES_TO_COPY_FROM");
		if(sValue != null && sValue.length() > 0){
			Vector<String> vValues = CommonUtil.stringToVector(sValue, ",");
			INPUT_FILES_TO_COPY_FROM = new String[vValues.size()];
			int iSize = vValues.size();
			for(int i = 0; i < iSize; i++){
				String sToken = ((String)vValues.elementAt(i)).trim();
				if(sToken.indexOf(":") >= 0 || sToken.startsWith("/") || sToken.startsWith("\\")){
					INPUT_FILES_TO_COPY_FROM[i] = sToken;
				}
				else{
					INPUT_FILES_TO_COPY_FROM[i] = CODE_HOME + sToken;				
				}
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("INPUT_FILES_TO_COPY_TO");
		if(sValue != null && sValue.length() > 0){
			Vector<String> vValues = CommonUtil.stringToVector(sValue, ",");
			INPUT_FILES_TO_COPY_TO = new String[vValues.size()];
			int iSize = vValues.size();
			for(int i = 0; i < iSize; i++){
				String sToken = ((String)vValues.elementAt(i)).trim();
				if(sToken.indexOf(":") >= 0 || sToken.startsWith("/") || sToken.startsWith("\\")){
					INPUT_FILES_TO_COPY_TO[i] = sToken;
				}
				else{
					INPUT_FILES_TO_COPY_TO[i] = CODE_HOME + sToken;				
				}
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("OUTPUT_FILES_TO_COPY_FROM");
		if(sValue != null && sValue.length() > 0){
			Vector<String> vValues = CommonUtil.stringToVector(sValue, ",");
			OUTPUT_FILES_TO_COPY_FROM = new String[vValues.size()];
			int iSize = vValues.size();
			for(int i = 0; i < iSize; i++){
				String sToken = ((String)vValues.elementAt(i)).trim();
				if(sToken.indexOf(":") >= 0 || sToken.startsWith("/") || sToken.startsWith("\\")){
					OUTPUT_FILES_TO_COPY_FROM[i] = sToken;
				}
				else{
					OUTPUT_FILES_TO_COPY_FROM[i] = CODE_HOME + sToken;				
				}
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("OUTPUT_FILES_TO_COPY_TO");
		if(sValue != null && sValue.length() > 0){
			Vector<String> vValues = CommonUtil.stringToVector(sValue, ",");
			OUTPUT_FILES_TO_COPY_TO = new String[vValues.size()];
			int iSize = vValues.size();
			for(int i = 0; i < iSize; i++){
				String sToken = ((String)vValues.elementAt(i)).trim();
				if(sToken.indexOf(":") >= 0 || sToken.startsWith("/") || sToken.startsWith("\\")){
					OUTPUT_FILES_TO_COPY_TO[i] = sToken;
				}
				else{
					OUTPUT_FILES_TO_COPY_TO[i] = CODE_HOME + sToken;				
				}
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("OUTPUT_FILES_TO_MOVE_FROM");
		if(sValue != null && sValue.length() > 0){
			Vector<String> vValues = CommonUtil.stringToVector(sValue, ",");
			OUTPUT_FILES_TO_MOVE_FROM = new String[vValues.size()];
			int iSize = vValues.size();
			for(int i = 0; i < iSize; i++){
				String sToken = ((String)vValues.elementAt(i)).trim();
				if(sToken.indexOf(":") >= 0 || sToken.startsWith("/") || sToken.startsWith("\\")){
					OUTPUT_FILES_TO_MOVE_FROM[i] = sToken;
				}
				else{
					OUTPUT_FILES_TO_MOVE_FROM[i] = CODE_HOME + sToken;				
				}
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("OUTPUT_FILES_TO_MOVE_TO");
		if(sValue != null && sValue.length() > 0){
			Vector<String> vValues = CommonUtil.stringToVector(sValue, ",");
			OUTPUT_FILES_TO_MOVE_TO = new String[vValues.size()];
			int iSize = vValues.size();
			for(int i = 0; i < iSize; i++){
				String sToken = ((String)vValues.elementAt(i)).trim();
				if(sToken.indexOf(":") >= 0 || sToken.startsWith("/") || sToken.startsWith("\\")){
					OUTPUT_FILES_TO_MOVE_TO[i] = sToken;
				}
				else{
					OUTPUT_FILES_TO_MOVE_TO[i] = CODE_HOME + sToken;				
				}
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("FILES_TO_DELETE");
		if(sValue != null && sValue.length() > 0){
			Vector<String> vValues = CommonUtil.stringToVector(sValue, ",");
			FILES_TO_DELETE = new String[vValues.size()];
			int iSize = vValues.size();
			for(int i = 0; i < iSize; i++){
				String sToken = ((String)vValues.elementAt(i)).trim();
				if(sToken.indexOf(":") >= 0 || sToken.startsWith("/") || sToken.startsWith("\\")){
					FILES_TO_DELETE[i] = sToken;
				}
				else{
					FILES_TO_DELETE[i] = CODE_HOME + sToken;				
				}
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("DIRECTORIES_TO_DELETE");
		if(sValue != null && sValue.length() > 0){
			Vector<String> vValues = CommonUtil.stringToVector(sValue, ",");
			DIRECTORIES_TO_DELETE = new String[vValues.size()];
			int iSize = vValues.size();
			for(int i = 0; i < iSize; i++){
				String sToken = ((String)vValues.elementAt(i)).trim();
				if(sToken.indexOf(":") >= 0 || sToken.startsWith("/") || sToken.startsWith("\\")){
					DIRECTORIES_TO_DELETE[i] = sToken;
				}
				else{
					DIRECTORIES_TO_DELETE[i] = CODE_HOME + sToken;				
				}
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("PROCESSES_TO_KILL");
		if(sValue != null && sValue.length() > 0){
			Vector<String> vValues = CommonUtil.stringToVector(sValue, ",");
			PROCESSES_TO_KILL = new String[vValues.size()];
			int iSize = vValues.size();
			for(int i = 0; i < iSize; i++){
				String sToken = ((String)vValues.elementAt(i)).trim();
				PROCESSES_TO_KILL[i] = sToken;
			}
		}

		/*---------------------------------------------
		Service site related parameters
		---------------------------------------------*/
		if(bRead) sValue = osParameterReader.getOSParameterValueByName("SERVICE_NAME");
		if(sValue != null && sValue.length() > 0) SERVICE_NAME = sValue;

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("SERVICE_EXTENSION");
		if(sValue != null && sValue.length() > 0) SERVICE_EXTENSION = sValue;

		//SERVICE_FOLDER moved to the top (before CODE_HOME and CODE_DRIVE, which depend on SERVICE_FOLDER)

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("SERVICE_PORT");
		if(sValue != null && sValue.length() > 0) SERVICE_PORT = sValue;
		else{
			//try read from Tomcat
			try{
				String sDir = IOUtil.getCurrentDir();
				if(sDir.toLowerCase().endsWith("bin") || 
						sDir.toLowerCase().endsWith("bin\\") ||
						sDir.toLowerCase().endsWith("bin/")){
					int iIndex = sDir.lastIndexOf("bin");
					sDir = sDir.substring(0, iIndex);
				}
				if(!sDir.endsWith("/")){
					sDir += "/";
				}

				String sTomcatServerXMLFile = sDir+= "conf/server.xml";
				String sTomcatServerXMLString = IOUtil.fileToString(sTomcatServerXMLFile);
				int iIdx0 = sTomcatServerXMLString.indexOf("Connector port=");
				int iIdx1 = sTomcatServerXMLString.indexOf("\"", iIdx0);
				int iIdx2 = sTomcatServerXMLString.indexOf("\"", iIdx1+1);
				SERVICE_PORT = sTomcatServerXMLString.substring(iIdx1+1, iIdx2).trim();
				if(SERVICE_PORT == null || SERVICE_PORT.trim().length()<=0){
					SERVICE_PORT = "8080";
				}
			}
			catch(Exception e){
				SERVICE_PORT = "8080";
			}


		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("SERVICE_HOST");
		if(sValue != null && sValue.length() > 0) SERVICE_HOST = sValue;
		else{
			String sIP = CommonUtil.getIPAddress();
			SERVICE_HOST = "http://" + sIP;
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("SERVICE_URI");
		if(sValue != null && sValue.length() > 0) SERVICE_URI = sValue;
		else{
			SERVICE_URI = SERVICE_HOST+":"+SERVICE_PORT+"/"+SERVICE_FOLDER+"/"+SERVICE_NAME + "." + SERVICE_EXTENSION;
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("OS_SERVICE_SITE");
		if(sValue != null && sValue.length() > 0) OS_SERVICE_SITE = sValue;
		else{
			OS_SERVICE_SITE = SERVICE_HOST+":"+SERVICE_PORT+"/"+SERVICE_FOLDER;
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("SERVICE_TYPE");
		if(sValue != null && sValue.length() > 0) SERVICE_TYPE = sValue;

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("OS_REGISTRY_SITE");
		if(sValue != null && sValue.length() > 0) OS_REGISTRY_SITE = sValue;
		//else OS_REGISTRY_SITE = OS_SERVICE_SITE + "/osregistry/OSRegistryService.jws"; 

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("OS_SCHEDULER_SITE");
		if(sValue != null && sValue.length() > 0) OS_SCHEDULER_SITE = sValue;
		else OS_SCHEDULER_SITE = OS_SERVICE_SITE + "/osscheduler/OSSchedulerService.jws"; 

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("SCHEDULER_WITH_REGISTRY");
		if(sValue != null && sValue.length() > 0) SCHEDULER_WITH_REGISTRY = sValue.startsWith("t")?true:false;

		/*---------------------------------------------
		Mail related parameters
		---------------------------------------------*/
		if(bRead) sValue = osParameterReader.getOSParameterValueByName("SMTP_SERVER");
		if(sValue != null && sValue.length() > 0) SMTP_SERVER = sValue;

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("SMTP_USER");
		if(sValue != null && sValue.length() > 0) SMTP_USER = sValue;

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("FROM_EMAIL");
		if(sValue != null && sValue.length() > 0) FROM_EMAIL = sValue;

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("SMTP_PASSWORD");
		if(sValue != null && sValue.length() > 0) SMTP_PASSWORD = sValue;

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("TO_EMAIL");
		if(sValue != null && sValue.length() > 0) TO_EMAIL = sValue;

		sValue = osParameterReader.getOSParameterValueByName("CC_EMAIL");
		if(sValue != null && sValue.length() > 0) CC_EMAIL = sValue;

		sValue = osParameterReader.getOSParameterValueByName("BCC_EMAIL");
		if(sValue != null && sValue.length() > 0) BCC_EMAIL = sValue;

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("MAIL_SUBJECT");
		if(sValue != null && sValue.length() > 0) MAIL_SUBJECT = sValue;

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("MAIL_MESSAGE");
		if(sValue != null && sValue.length() > 0) MAIL_MESSAGE = sValue;

		sValue = osParameterReader.getOSParameterValueByName("MAIL_ATTACHED_FILES");
		if(sValue != null && sValue.length() > 0) MAIL_ATTACHED_FILES = sValue;


		/*---------------------------------------------
		Security related parameters
		---------------------------------------------*/
		if(bRead) sValue = osParameterReader.getOSParameterValueByName("REQUIRE_USER_NAME");
		if(sValue != null && sValue.length() > 0) REQUIRE_USER_NAME = sValue.startsWith("t")?true:false;

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("REQUIRE_PASSWORD");
		if(sValue != null && sValue.length() > 0) REQUIRE_PASSWORD = sValue.startsWith("t")?true:false;

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("REQUIRE_LICENSE");
		if(sValue != null && sValue.length() > 0) REQUIRE_LICENSE = sValue.startsWith("t")?true:false;

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("REQUIRE_ONLY_JOB_ID_TO_RETRIEVE_JOB_RESULT");
		if(sValue != null && sValue.length() > 0) REQUIRE_ONLY_JOB_ID_TO_RETRIEVE_JOB_RESULT = sValue.startsWith("t")?true:false;

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("REQUIRE_ONLY_JOB_ID_TO_KILL_JOB");
		if(sValue != null && sValue.length() > 0) REQUIRE_ONLY_JOB_ID_TO_KILL_JOB = sValue.startsWith("t")?true:false;

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("MAX_JOBS_PER_USER");
		if(sValue != null && sValue.length() > 0){
			try{
				MAX_JOBS_PER_USER = Integer.parseInt(sValue);
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("USER_NAMES");
		if(sValue != null && sValue.length() > 0){
			Vector<String> vValues = CommonUtil.stringToVector(sValue, ",");
			USER_NAMES = new String[vValues.size()];
			int iSize = vValues.size();
			for(int i = 0; i < iSize; i++){
				String sToken = ((String)vValues.elementAt(i)).trim();
				USER_NAMES[i] = sToken;	
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("PASSWORDS");
		if(sValue != null && sValue.length() > 0){
			Vector<String> vValues = CommonUtil.stringToVector(sValue, ",");
			PASSWORDS = new String[vValues.size()];
			int iSize = vValues.size();
			for(int i = 0; i < iSize; i++){
				String sToken = ((String)vValues.elementAt(i)).trim();
				PASSWORDS[i] = sToken;	
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("LICENSES");
		if(sValue != null && sValue.length() > 0){
			Vector<String> vValues = CommonUtil.stringToVector(sValue, ",");
			LICENSES = new String[vValues.size()];
			int iSize = vValues.size();
			for(int i = 0; i < iSize; i++){
				String sToken = ((String)vValues.elementAt(i)).trim();
				LICENSES[i] = sToken;	
			}
		}

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("ALLOW_IO_OPERATIONS_BY_USERS");
		if(sValue != null && sValue.length() > 0) ALLOW_IO_OPERATIONS_BY_USERS = sValue.startsWith("t")?true:false;

		/*---------------------------------------------
		XML related parameters
		---------------------------------------------*/
		if(bRead) sValue = osParameterReader.getOSParameterValueByName("VALIDATE");
		if(sValue != null && sValue.length() > 0) VALIDATE = sValue.startsWith("t")?true:false;

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("XML_INDENTING");
		if(sValue != null && sValue.length() > 0) XML_INDENTING = sValue.startsWith("t")?true:false;


		if(bRead) sValue = osParameterReader.getOSParameterValueByName("FML_PUBLIC_SITE");
		if(sValue != null && sValue.length() > 0) FML_PUBLIC_SITE = sValue;

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("OS_SITE");
		if(sValue != null && sValue.length() > 0) OS_SITE = sValue;


		if(bRead) sValue = osParameterReader.getOSParameterValueByName("OS_SCHEMA_SITE");
		if(sValue != null && sValue.length() > 0) OS_SCHEMA_SITE = sValue;

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("XML_ENCODING_STYLE");
		if(sValue != null && sValue.length() > 0) XML_ENCODING_STYLE = sValue;

		if(bRead) sValue = osParameterReader.getOSParameterValueByName("XSLT_LOCATION");
		if(sValue != null && sValue.length() > 0) XSLT_LOCATION = sValue;

		return true;
	}//readAndSetOSParameter

	/**
	 * write the OSParameter to an xml string. 
	 * 
	 * @return the osParameter xml string. 
	 * @throws Exception if there are errors in writing the osParameter string. 
	 */
	public static String writeOSParameter() throws Exception{
		OSParameterWriter osParameterWriter = new OSParameterWriter();
		//TODO write the parameters. 
		return osParameterWriter.writeToString();
	}//writeOSParameter

	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] args){
	}//main

	/**
	 * static constructor
	 */
	static{
		String sOSParameterFile = "";
		if(OSParameterFile.NAME !=null && OSParameterFile.NAME.length() > 0){
			sOSParameterFile = OSParameterFile.NAME;
			PARAMETER_FILE = OSParameterFile.NAME;
		}
		else{
			sOSParameterFile = PARAMETER_FILE;
		}

		//String sOSParameterFile = IOUtil.getCurrentDir()+"webapps/os/ossolver/OSParameter.xml";
		//In Eclipse the current directory is the project that the main is in -- e.g. C:/code/java/OSjava/OSTest/
		//in Tomcat Linux the current directory is PathToTomcat/Tomcat/bin/
		//in Tomcat the current directory is C:/Program Files/Apache Software Foundation/Tomcat 5.5/???
		//suggestion: have a file in which each service name is mapped to a different osparam file. 
		if(sOSParameterFile != null && sOSParameterFile.length() > 0){
			readAndSetOSParameter(sOSParameterFile, true, false);
		}

	}//static constructor
}//OSParameter
