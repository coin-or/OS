using System;
using System.Diagnostics;
using System.IO;
using System.Management;

namespace org.optimizationservices.oscommon.util{
	/// <summary>
	/// The <c>ProcessUtil</c> class contains methods for performing
	/// process related operations used by all other classes and projects
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class ProcessUtil{
		public ProcessUtil(){
		}//constructor

		/// <summary>
		/// Launch a process specified by a command string. 
		/// Try use outputFile argument, NOT the redirect sign ">", to save output. 
		/// In some cases the command needs to be set to cmd.exe and the arguments need to begin 
		/// with /c and then somebatch.exe arg1, arg2, ....
		/// </summary>
		/// <param name="command">holds the command that is usually typed in a terminal. </param>
		/// <param name="arguments">holds the arguments of the command, null if none.</param>
		/// <param name="outputFile">holds the name of the output file to save the result of the command.
		/// use null or empty string if no output file</param>
		/// <returns>whether process is launched successfully.  </returns>
		public static bool launch(string command, string arguments, string outputFile){
			try{
				StreamReader streamReader = null;
				bool bWrite = true;
				ProcessStartInfo processStartInfo = new ProcessStartInfo();
				if(outputFile != null && outputFile.Length >= 0){
					processStartInfo.RedirectStandardOutput = true;
				}
				processStartInfo.FileName = command;
				processStartInfo.Arguments = arguments;
				processStartInfo.UseShellExecute = false;
				processStartInfo.WindowStyle = ProcessWindowStyle.Normal;

				Process process = Process.Start(processStartInfo);
				if(outputFile != null && outputFile.Length >= 0){
					streamReader = process.StandardOutput;
					bWrite = IOUtil.writeStringToFile(streamReader.ReadToEnd(), outputFile);
				}
				if(outputFile != null && outputFile.Length >= 0){
					streamReader.Close();
				}
				if(!bWrite){
					throw new Exception("standard output file not written successfully");
				}
				return true;
			}
			catch(Exception e){
				IOUtil.log(e.ToString(), null);
				return false;
			}
		}//launch

		/// <summary>
		/// Launch a command specified by a command string and wait for the process to finish before proceeding
		/// to the next line.  Try use outputFile argument, NOT the redirect sign ">", to save output. 
		/// In some cases the command needs to be set to cmd.exe and the arguments need to begin 
		/// with /c and then somebatch.exe arg1, arg2, ....
		/// </summary>
		/// <param name="command">holds the command that is usually typed in a terminal.  </param>
		/// <param name="arguments">holds the arguments of the command; use null if none.</param>
		/// <param name="outputFile">holds the name of the output file to save the result of the command; use null if none.</param>
		/// <returns>whether process is launched successfully.  </returns>
		public static bool launchAndWaitForFinish(string command, string arguments, string outputFile){
			try{
				StreamReader streamReader = null;
				bool bWrite = true;
				ProcessStartInfo processStartInfo = new ProcessStartInfo();
				if(outputFile != null && outputFile.Length >= 0){
					processStartInfo.RedirectStandardOutput = true;
				}
				processStartInfo.FileName = command;
				processStartInfo.Arguments = arguments;
				processStartInfo.UseShellExecute = false;
				processStartInfo.WindowStyle = ProcessWindowStyle.Normal;
				
				Process process = Process.Start(processStartInfo);
				if(outputFile != null && outputFile.Length >= 0){
					streamReader = process.StandardOutput;
					bWrite = IOUtil.writeStringToFile(streamReader.ReadToEnd(), outputFile);
				}
				process.WaitForExit();
				process.Kill();
				if(outputFile != null && outputFile.Length >= 0){
					streamReader.Close();
				}
				if(!bWrite){
					throw new Exception("standard output file not written successfully");
				}
				return true;
			}
			catch(Exception e){
				IOUtil.log(e.ToString(), null);
				return false;
			}
		}//launchAndWaitForFinish

		/// <summary>
		/// kill a process by the process name.  
		/// </summary>
		/// <param name="processName">holds the process name.  </param>
		/// <returns>whether the process is killed or not; it will return true if there was no such processName. </returns>
		public static bool killProcessByName(String processName){
			try{
				Process[] mProcess = Process.GetProcessesByName(processName);
				int iProcess = mProcess==null?0:mProcess.Length;
				for(int i = 0; i < iProcess; i++){
					mProcess[i].Kill();
				}
				string sModifiedProcessName = "";
				if(processName.EndsWith(".exe")){
					sModifiedProcessName = processName.Substring(0, processName.Length-4);
				}
				else{
					sModifiedProcessName = processName+".exe";
				}
				mProcess = Process.GetProcessesByName(sModifiedProcessName);
				iProcess = mProcess==null?0:mProcess.Length;
				for(int i = 0; i < iProcess; i++){
					mProcess[i].Kill();
				}
				return true;
			}
			catch(Exception){
				return false;
			}
		}//killProcessByName
	
		/// <summary>
		/// kill a process by the process id. 
		/// </summary>
		/// <param name="processID">processID holds the process id. </param>
		/// <returns>whether the process is killed or not; it will return true if there was no such processID. </returns>
		public static bool killProcessByID(string processID){
			int iProcessID = Int32.Parse(processID);
			try{
				Process process = Process.GetProcessById(iProcessID);
				process.Kill();
				return true;
			}
			catch(Exception){
				return false;
			}
		}//killProcessByID
		
		/// <summary>
		/// get free physical memory on the system.
		/// </summary>
		/// <returns>the free physical memory in bytes.  </returns>
		public static double getFreeMemory() {
			ManagementObjectSearcher mos = new ManagementObjectSearcher("SELECT * FROM Win32_OperatingSystem");
			foreach(ManagementObject mo in mos.Get()){
				return Double.Parse(mo["FreePhysicalMemory"].ToString());	  
			}
			return Double.NaN;
		}//getFreeMemory

	}//class ProcessUtil
}//namespace
