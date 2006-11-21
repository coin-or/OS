using System;
using System.IO;
using System.Net;
using System.Text;
using System.Collections;
using System.Management;

namespace org.optimizationservices.oscommon.util
{
	/// <summary>
	/// The <c>IOUtil</c> class contains methods for performing
	/// IO related operations used by all other classes and projects
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class IOUtil{
		public IOUtil(){
		}//constructor

		public string readFile(string fileName){
			return readStringFromFile(fileName);
		}

		/// <summary>
		/// Reads from a text file to a string in memory.
		/// </summary>
		/// <param name="fileName">holds the file name of the file to be converted into a string</param>
		/// <returns>the string to that is constructed from the file. 
		/// A null value will be returned if there is any error in the reading.</returns>
		public static string readStringFromFile(string fileName){
			string sOut = "";
			FileStream fileStream;
			StreamReader streamReader;
			try{
				fileStream = new FileStream(fileName, FileMode.Open, FileAccess.Read, FileShare.Read);
				streamReader = new StreamReader(fileStream);
				sOut = streamReader.ReadToEnd();
				streamReader.Close();
				fileStream.Close();
				return sOut;
			}
			catch(Exception e){
				IOUtil.log(e.ToString(), null);
				return null;
			}
		}//readStringFromFile


		/// <summary>
		/// Writes a string to a file. 
		/// </summary> 
		/// <param name="inputString">holds the string to be written to a file.</param>
		/// <param name="inputFileName">holds the file name of the file to save the string.</param>
		/// <returns>whether the string is saved to the file successfully or not.</returns>
		public static bool writeStringToFile(string inputString, string inputFileName){
			FileStream fileStream;
			StreamWriter streamWriter;
			try{
				fileStream = new FileStream(inputFileName, FileMode.OpenOrCreate);
				streamWriter = new StreamWriter(fileStream);
				streamWriter.Write(inputString);
				streamWriter.Flush();
				streamWriter.Close();
				fileStream.Close();
				return true;
			}
			catch(Exception	e){
				IOUtil.log(e.ToString(), null);
				return false;
			}		
		}//writeStringToFile

		/// <summary>
		/// Appends a string to a file. 
		/// </summary> 
		/// <param name="inputString">holds the string to be appended to a file.</param>
		/// <param name="inputFileName">holds the file name of the file to append the string.</param>
		/// <returns>whether the string is appended to the file successfully or not.</returns>
		public static bool appendStringToFile(string inputString, string inputFileName){
			StreamWriter streamWriter;
			try{
				streamWriter = File.AppendText(inputFileName);
				streamWriter.WriteLine(inputString);
				streamWriter.Flush();
				streamWriter.Close();
				return true;
			}
			catch(Exception	e){
				IOUtil.log(e.ToString(), null);
				return false;
			}		
		}//appendStringToFile

		/// <summary>
		/// logs message to a file. 
		/// </summary> 
		/// <param name="logMessage">holds the log message to be appended to the log file.</param>
		/// <param name="logFileName">holds the log file name. 
		/// The method uses a default log file if the file name is null or empty.</param>
		/// <returns>whether the string is appended to the file successfully or not.</returns>
		public static bool log(string logMessage, string logFileName){
			StreamWriter streamWriter;
			try{
				string sLogFileName = OSParameter.LOG_FILE;
				if(logFileName != null && logFileName.Length > 0) sLogFileName = logFileName;
				streamWriter = File.AppendText(sLogFileName);
				streamWriter.Write("\r\nLog Entry: ");
				//streamWriter.WriteLine("{0} {1}", DateTime.Now.ToLongTimeString(), DateTime.Now.ToLongTimeString());
				streamWriter.WriteLine("{0}", DateTime.Now.ToLongTimeString());
				streamWriter.WriteLine("  :");
				streamWriter.WriteLine("  :{0}", logMessage);
				streamWriter.WriteLine("---------------------------------");
				streamWriter.Flush();
				streamWriter.Close();
				return true;
			}
			catch(Exception	e){
				Console.WriteLine(e.ToString());
				return false;
			}		
		}//log

		/// <summary>
		/// Reads from a url to a string in memory.
		/// </summary>
		/// <param name="url">holds the link address of the content to be converted into a string.</param>
		/// <returns>the string constructed from reading the content of the link. A null value will be 
		/// returned if there is any error in the reading.</returns>
		public static string readStringFromURL(string url){
			StringBuilder stringBuilder = new StringBuilder();
			byte[] mbBuffer = new byte[8192];
			HttpWebRequest httpWebRequest = (HttpWebRequest)WebRequest.Create(url);
			HttpWebResponse httpWebResponse = (HttpWebResponse)httpWebRequest.GetResponse();
			Stream stream = httpWebResponse.GetResponseStream();
			string sTempString = null;
			int iCount = 0;
			do{
				iCount = stream.Read(mbBuffer, 0, mbBuffer.Length);
				if(iCount != 0){
					sTempString = Encoding.ASCII.GetString(mbBuffer, 0, iCount);
					stringBuilder.Append(sTempString);
				}
			}
			while(iCount > 0);
			return stringBuilder.ToString();
		}//readStringFromURL

		/// <summary>
		/// Print out a string message.
		/// </summary>
		/// <param name="s">holds the string message to print.</param>
		/// <param name="outputStream">holds the output stream to print the message to.</param>
		/// <returns>whether the print is successful. </returns>
		public static bool print(string s, TextWriter outputStream){
			try {
				if(outputStream == null){
					Console.Write(s);
				}
				else{
					outputStream.Write(s);
					outputStream.Close();
				}
				return true;
			} 
			catch (Exception e) {
				Console.WriteLine(e.ToString());
				return false;
			}
		
		}//print with the output stream 

		/// <summary>
		/// Print out a line feed "\n".
		/// </summary>
		/// <returns>whether the print is successful.</returns>
		public static bool println(){
			return print("\n");
		}//println

		/// <summary>
		/// Print out a string message with an extra line feed "\n". 
		/// </summary>
		/// <param name="s">holds the string message to print. </param>
		/// <returns>whether the print is successful. </returns>
		public static bool println(String s){
			return print(s+"\n");
		}//println

		/// <summary>
		/// Print out a string message. 
		/// </summary>
		/// <param name="s">holds the string message to print. </param>
		/// <returns>whether the print is successful. </returns>
		public static bool print(string s){
			TextWriter outputStream = null;
			if(OSParameter.DEFAULT_OUTPUT == OSConstant.STD_OUT){
				outputStream = Console.Out;
				return print(s, outputStream);
			}
			else if(OSParameter.DEFAULT_OUTPUT == OSConstant.STD_ERR){
				outputStream = Console.Error;
				return print(s, outputStream);
			}
			else if(OSParameter.DEFAULT_OUTPUT == OSConstant.FILE_OUT){
				try {
					if(OSParameter.APPEND_PRINT_FILE){
						outputStream = File.AppendText(OSParameter.PRINT_FILE);
					}
					else{
						FileStream fileStream = new FileStream(OSParameter.PRINT_FILE, FileMode.OpenOrCreate);
						outputStream = new StreamWriter(fileStream);					
					}								 
				} 
				catch (FileNotFoundException e){
					Console.WriteLine(e.ToString());
				}
				return print(s, outputStream);
			}
			else{//if(OSParameter.DefaultOutput == ImpactConstant.StringOut)
				OSParameter.PRINT_STRING_WRITER.Append(s);
				return true;
			}	
		}//print

		/// <summary>
		/// clean up disks, mainly including deleting temp files. 
		/// </summary>
		/// <returns>whether the clean up is successful or not. </returns>
		public static bool cleanUpDisk(){
			long lTempFileKeepTime;
			double dFreeDiskSpace = -1.0;
			try{
				dFreeDiskSpace = getFreeDiskSpace(OSParameter.CODE_DRIVE);
			}
			catch(Exception e){
				IOUtil.log(e.ToString(), null);
			}
			if(dFreeDiskSpace != -1 && dFreeDiskSpace < OSParameter.MINIMUM_DISKSPACE_TRIGGER){
				lTempFileKeepTime= OSParameter.TEMP_FILE_MIN_DAYS*86400000
					+OSParameter.TEMP_FILE_MIN_HOURS*3600000
					+OSParameter.TEMP_FILE_MIN_MINUTES*60000
					+OSParameter.TEMP_FILE_MIN_SECONDS*1000;
			}
			else{
				lTempFileKeepTime= OSParameter.TEMP_FILE_MAX_DAYS*86400000
					+OSParameter.TEMP_FILE_MAX_HOURS*3600000
					+OSParameter.TEMP_FILE_MAX_MINUTES*60000
					+OSParameter.TEMP_FILE_MAX_SECONDS*1000;
			}

			int iFolderNumber = OSParameter.CLEAN_UP_FOLDERS==null?0:OSParameter.CLEAN_UP_FOLDERS.Length;
			int i, j, k;

			//delete files and dirs
			for(i = 0; i < iFolderNumber; i++){
				String[] msAllFiles = Directory.GetFiles(OSParameter.CLEAN_UP_FOLDERS[i]);
				ArrayList vFiles = new ArrayList();
				int m = msAllFiles==null?0:msAllFiles.Length;
				String[] msAllDirs = Directory.GetDirectories(OSParameter.CLEAN_UP_FOLDERS[i]);
				ArrayList vDirs = new ArrayList();
				int n = msAllDirs==null?0:msAllDirs.Length;
				DateTime now = DateTime.Now;
				//filter
				for(k = 0; k < m; k++){//file
					bool bAccept = false;
					DateTime lastModified = File.GetLastWriteTime(msAllFiles[k]);
					TimeSpan difference = now - lastModified ;
					if( difference.TotalMilliseconds > (double)lTempFileKeepTime){
						bAccept = true;
					}
					else if(msAllFiles[k].EndsWith(".tmp") || 
						msAllFiles[k].EndsWith(".temp")){
						bAccept = true;
					}
					if(bAccept){
						vFiles.Add(msAllFiles[k]);
					}
				}
				for(k = 0; k < n; k++){//dir
					bool bAccept = false;
					DateTime lastModified = Directory.GetLastWriteTime(msAllDirs[k]);
					TimeSpan difference = now - lastModified ;
					if( difference.TotalMilliseconds > (double)lTempFileKeepTime){
						bAccept = true;
					}
					if(bAccept){
						vFiles.Add(msAllDirs[k]);
					}
				}
				//end filter
				int iFileNumber = vFiles.Count;
				string sPath;
				for(j = 0; j < iFileNumber; j++){					
					sPath = (string)vFiles[j];
					if(isDir(sPath)){
						deleteDir(sPath);
					}
					else{
						deleteFile(sPath);
					}
				}
			}
			//backup files and dirs
			if((OSParameter.SERVICE_TYPE != null && OSParameter.SERVICE_TYPE.Equals("registry")) || 
				(OSParameter.SERVICE_TYPE != null && OSParameter.SERVICE_TYPE.Equals("scheduler") && OSParameter.SCHEDULER_WITH_REGISTRY)){
				FileInfo registryLogFile = new FileInfo(OSParameter.REGISTRY_LOG_FILE);
				if(registryLogFile.Exists){
					if(registryLogFile.Length >= OSParameter.MAX_LOG_FILE_SIZE){
						string sTimeStamp = XMLUtil.createXSDateTime(DateTime.Now); 
						sTimeStamp = sTimeStamp.Replace(':', '.');
						string sBackUpRegistryLogFile = OSParameter.BACKUP_FOLDER + "registryLog_" + sTimeStamp + ".txt";
						IOUtil.moveFile(OSParameter.REGISTRY_LOG_FILE, sBackUpRegistryLogFile);
						IOUtil.createFile(OSParameter.REGISTRY_LOG_FILE);
					}
				}
				FileInfo registrySummaryReport = new FileInfo(OSParameter.REGISTRY_SUMMARY_REPORT);
				if(registrySummaryReport.Exists){
					if(registrySummaryReport.Length >= OSParameter.MAX_LOG_FILE_SIZE){
						string sTimeStamp = XMLUtil.createXSDateTime(DateTime.Now); 
						sTimeStamp = sTimeStamp.Replace(':', '.');
						string sBackUpRegistrySummaryReport = OSParameter.BACKUP_FOLDER + "registrySummaryReport_" + sTimeStamp + ".txt";
						IOUtil.moveFile(OSParameter.REGISTRY_SUMMARY_REPORT, sBackUpRegistrySummaryReport);
						IOUtil.createFile(OSParameter.REGISTRY_SUMMARY_REPORT);
					}
				}
				FileInfo registryDetailedReport = new FileInfo(OSParameter.REGISTRY_DETAILED_REPORT);
				if(registryDetailedReport.Exists){
					if(registryDetailedReport.Length >= OSParameter.MAX_LOG_FILE_SIZE){
						string sTimeStamp = XMLUtil.createXSDateTime(DateTime.Now); 
						sTimeStamp = sTimeStamp.Replace(':', '.');
						string sBackUpRegistryDetailedReport = OSParameter.BACKUP_FOLDER + "registryDetailedReport_" + sTimeStamp + ".txt";
						IOUtil.moveFile(OSParameter.REGISTRY_DETAILED_REPORT, sBackUpRegistryDetailedReport);
						IOUtil.createFile(OSParameter.REGISTRY_DETAILED_REPORT);
					}
				}
			}
			if(OSParameter.SERVICE_TYPE == null || !OSParameter.SERVICE_TYPE.Equals("registry")){
				FileInfo logFile = new FileInfo(OSParameter.LOG_FILE);
				if(logFile.Exists){
					if(logFile.Length >= OSParameter.MAX_LOG_FILE_SIZE){
						string sTimeStamp = XMLUtil.createXSDateTime(DateTime.Now); 
						sTimeStamp = sTimeStamp.Replace(':', '.');
						string sBackUpLogFile = OSParameter.BACKUP_FOLDER + "log_" + sTimeStamp + ".txt";
						IOUtil.moveFile(OSParameter.LOG_FILE, sBackUpLogFile);
						IOUtil.createFile(OSParameter.LOG_FILE);
					}
				}
			}
			FileInfo printFile = new FileInfo(OSParameter.PRINT_FILE);
			if(printFile.Exists){
				if(printFile.Length >= OSParameter.MAX_LOG_FILE_SIZE){
					string sTimeStamp = XMLUtil.createXSDateTime(DateTime.Now); 
					sTimeStamp = sTimeStamp.Replace(':', '.');
					string sBackUpPrintFile = OSParameter.BACKUP_FOLDER + "print_" + sTimeStamp + ".txt";
					IOUtil.moveFile(OSParameter.PRINT_FILE, sBackUpPrintFile);
					IOUtil.createFile(OSParameter.PRINT_FILE);
				}
			}
			FileInfo osplFile = new FileInfo(OSParameter.PROCESS_FILE+"_backup");
			if(osplFile.Exists){
				string sTimeStamp = XMLUtil.createXSDateTime(DateTime.Now);
				sTimeStamp = sTimeStamp.Replace(':', '.');
				string sBackUpOSpLFile = OSParameter.BACKUP_FOLDER + "OSpL_" + sTimeStamp + ".xml";
				IOUtil.copyFile(OSParameter.PROCESS_FILE+"_backup", sBackUpOSpLFile);
			}			
			return true;
		}//cleanUpDisk

		/// <summary>
		/// check if a file or directory exists. 
		/// </summary>
		/// <param name="path">holds the the file or dir path to check. </param>
		/// <returns>whether a file or directory exists. </returns>
		public static bool existsFileOrDir(String path){
			return (File.Exists(path) || Directory.Exists(path));
		}//existsFile

		/// <summary>
		/// get the last write time of the file. 
		/// </summary>
		/// <param name="file">holds the name of the file to check. </param>
		/// <returns>the last write time of the file in millisecond.  </returns>
		public static long getLastWriteTime(String file){
			return CommonUtil.timeMillis(File.GetLastWriteTime(file));
		}//getLastWriteTime

		/// <summary>
		/// test whether a path is a directory or not. 
		/// </summary>
		/// <param name="path">holds the file or dir path. </param>
		/// <returns>true if the path is not a directory, false otherwise. </returns>
		public static bool isDir(string path){
			try {
				return Directory.Exists(path);
			} 
			catch (Exception e) {
				Console.WriteLine(e.ToString());
				return false;
			}
		}//isDir

		/// <summary>
		/// create a file. 
		/// </summary>
		/// <param name="file">holds the name of the file to create</param>
		/// <returns>whether the file is created successfully. </returns>
		public static bool createFile(String file){
			try {
				if (!File.Exists(file)) {
					File.Create(file);
				}
				return true;
			} 
			catch (Exception e) {
				IOUtil.log(e.ToString(), null);
				return false;
			}
		}//createFile

		/// <summary>
		/// delete a file. 
		/// </summary>
		/// <param name="file">holds the name of the file to delete. </param>
		/// <returns>whether the file is deleted successfully. </returns>
		public static bool deleteFile(String file){
			try{
				File.Delete(file);
				return true;
			}
			catch(Exception e){
				IOUtil.log(e.ToString(), null);
				return false;
			}
		}//deleteFile

		/// <summary>
		/// copy a file. 
		/// </summary>
		/// <param name="from">holds the file to copy from.</param>
		/// <param name="to">holds the file to copy to.</param>
		/// <returns>whether the file is copied successfully. </returns>
		public static bool copyFile(string from, string to) {
			try {
				if(File.Exists(from) && File.Exists(to)) {
					File.Delete(to);
				}
				File.Copy(from, to);
				return true;
			} 
			catch (Exception e) {
				IOUtil.log(e.ToString(), null);
				return false;
			}
		}//copyFile

		/// <summary>
		/// move a file. 
		/// </summary>
		/// <param name="from">holds the file to move from.</param>
		/// <param name="to">holds the file to move to.</param>
		/// <returns>whether the file is moved successfully. </returns>
		public static bool moveFile(string from, string to) {
			try {
				if(File.Exists(from) && File.Exists(to)){
					File.Delete(to);
				}
				File.Move(from, to);
				return true;
			} 
			catch (Exception e) {
				IOUtil.log(e.ToString(), null);
				return false;
			}
		}//moveFile

		/// <summary>
		/// Make a directory. 
		/// </summary>
		/// <param name="dir">holds the directory path</param>
		/// <returns>whether the directory is made successfully. </returns>
		public static bool makeDir(String dir){
			try {
				if (!Directory.Exists(dir)) {
					Directory.CreateDirectory(dir);
				}
				return true;
			} 
			catch (Exception e) {
				IOUtil.log(e.ToString(), null);
				return false;
			}
		}//makeDir

		/// <summary>
		/// Delete a directory. 
		/// </summary>
		/// <param name="dir">holds the directory path</param>
		/// <returns>whether the directory is deleted successfully. </returns>
		static public bool deleteDir(String dir) {
			try {
				if (Directory.Exists(dir)) {
					Directory.Delete(dir, true);
				}
				
				return true;
			} catch (Exception e) {
				IOUtil.log(e.ToString(), null);
				return false;
			}	
		}//deleteDir

		/// <summary>
		/// copy directory. 
		/// </summary>
		/// <param name="fromDir">holds the directory to copy from.</param>
		/// <param name="toDir">holds the directory to copy to.</param>
		/// <returns>whether the directory is copied successfully. </returns>
		static public bool copyDir(String fromDir, String toDir) {
			try {
				string[] msFiles;
				if(toDir[toDir.Length-1]!=Path.DirectorySeparatorChar) 
					toDir += Path.DirectorySeparatorChar;
				if(!Directory.Exists(toDir)){
					Directory.CreateDirectory(toDir);
				}
				msFiles = Directory.GetFileSystemEntries(fromDir);
				foreach(string sFile in msFiles){
					// Sub directories
						if(Directory.Exists(sFile)){
							copyDir(sFile,toDir+Path.GetFileName(sFile));
						}
					// Files in directory
					else{ 
						File.Copy(sFile,toDir+Path.GetFileName(sFile),true);
					}
				}
				return true;
			} 
			catch (Exception e) {
				IOUtil.log(e.ToString(), null);
				return false;
			}	
		}//copyDir

		/// <summary>
		/// move directory. 
		/// </summary>
		/// <param name="fromDir">holds the directory to move from.</param>
		/// <param name="toDir">holds the directory to move to.</param>
		/// <returns>whether the directory is copied successfully. </returns>
		static public bool moveDir(String fromDir, String toDir) {
			try {
				string[] msFiles;
				if(toDir[toDir.Length-1]!=Path.DirectorySeparatorChar) 
					toDir += Path.DirectorySeparatorChar;
				if(!Directory.Exists(toDir)){
					Directory.CreateDirectory(toDir);
				}
				msFiles = Directory.GetFileSystemEntries(fromDir);
				foreach(string sFile in msFiles){
					// Sub directories
					if(Directory.Exists(sFile)){
						moveDir(sFile,toDir+Path.GetFileName(sFile));
					}
						// Files in directory
					else{ 
						File.Move(sFile,toDir+Path.GetFileName(sFile));
					}
				}
				deleteDir(fromDir);
				return true;
			} 
			catch (Exception e) {
				IOUtil.log(e.ToString(), null);
				return false;
			}	
		}//moveDir

		/// <summary>
		/// Get the current directory. Note the path is denoted by "/". 
		/// If there any error, null will be returned.  
		/// </summary>
		/// <returns>the current directory in a path ending with "/"</returns>
		public static string getCurrentDir(){
			try {
				String sCurrentDir = Directory.GetCurrentDirectory();
				sCurrentDir = sCurrentDir.Replace('\\', '/');
				if(!sCurrentDir.EndsWith("/")){
					sCurrentDir += "/";
				}
				return sCurrentDir;
			}
			catch(Exception e) {
				IOUtil.log(e.ToString(), null);
				return null;
			}	     
		
		}//getCurrentDir

		/// <summary>
		/// Get the parent directory. Note the path is denoted by "/". 
		/// If there any error, null will be returned.  
		/// </summary>
		/// <returns>the parent directory in a path ending with "/"</returns>
		public static string getParentDir(){
			try {
				String sParentDir = Directory.GetParent(".").FullName;
				sParentDir = sParentDir.Replace('\\', '/');
				if(!sParentDir.EndsWith("/")){
					sParentDir += "/";
				}
				return sParentDir;
			}
			catch(Exception e) {
				IOUtil.log(e.ToString(), null);
				return null;
			}	     
		
		}//getParentDir

		/// <summary>
		/// get free disk space.
		/// @throws Exception if an error occurs
		/// </summary>
		/// <param name="path">holds the path to get free space for, (including the colon on the windows system.)</param>
		/// <returns>the amount of free drive space on the drive</returns>
		public static double getFreeDiskSpace(String path){
			ManagementObject disk = new ManagementObject("win32_logicaldisk.deviceid=\"" + path + "\""); 
			disk.Get(); 			
			return System.Convert.ToDouble(disk["FreeSpace"]); //also disk["Size"] 
		}//getFreeDiskSpace

	}//class IOUtil
}//namespace
