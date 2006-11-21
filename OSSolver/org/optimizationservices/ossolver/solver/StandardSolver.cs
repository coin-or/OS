using System;
using System.Threading;
using System.IO;
using System.Diagnostics;
using System.Collections;

using org.optimizationservices.oscommon.util;
using org.optimizationservices.oscommon.communicationinterface;
using org.optimizationservices.oscommon.representationparser;

namespace org.optimizationservices.ossolver.solver {
	
	/// <summary>
	/// The <c>StandardSolver</c> class is a standard solver engine. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class StandardSolver : org.optimizationservices.oscommon.localinterface.DefaultSolver{

		/// <summary>
		/// default constructor
		/// </summary>
		public StandardSolver(){
		}//constructor
		
		/// <summary>
		/// run the CG solver command that is specified in the batch file. 
		/// </summary>
		public override void solve(){
			string sOS = "window";
			string sJobID = osOption.getJobID();
		
			string sInstanceFile = OSParameter.TEMP_FILE_FOLDER+sJobID+".osil";
			string sOptionFile = OSParameter.TEMP_FILE_FOLDER+sJobID+".osol";
			string sResultFile = OSParameter.TEMP_FILE_FOLDER+sJobID+".osrl";
			OSrLWriter osrlWriter = new OSrLWriter();
			osrlWriter.setServiceURI(OSParameter.SERVICE_URI);
			osrlWriter.setServiceName(OSParameter.SERVICE_NAME);
			osrlWriter.setResultTime(DateTime.Now);

			//change starts
			string sSolverPath =  OSParameter.CODE_HOME + "solver/solver";
			if(sOS.IndexOf("window") >= 0) sSolverPath += ".exe";

			string sArguments = 
				"-osil " + sInstanceFile + 
				" -osol " + sOptionFile +
				" -osrl " + sResultFile; 

			string[] msCommandLine = {
				sSolverPath, 
				"-osil", sInstanceFile, 
				"-osol", sOptionFile,
			    "-osrl", sResultFile};
			
			//no need to change below
			bool bUseSimple = false;
			if(bUseSimple){//simple version - not registering process 
				ProcessUtil.launchAndWaitForFinish(sSolverPath, sArguments, null);
				base.osrl = IOUtil.readStringFromFile(sResultFile);
			}
			else{ //complex version - registering process
				try{
					StreamReader streamReader = null;
					ProcessStartInfo processStartInfo = new ProcessStartInfo();
					processStartInfo.RedirectStandardOutput = true;
					processStartInfo.FileName = sSolverPath;
					processStartInfo.Arguments = sArguments;
					processStartInfo.UseShellExecute = false;
					processStartInfo.WindowStyle = ProcessWindowStyle.Normal;

					Process process = Process.Start(processStartInfo);
					ArrayList vProcess = (ArrayList)OSServiceUtil.processsHashTable[sJobID];
					if(vProcess == null || vProcess.Count <= 0){
						vProcess = new ArrayList();
					}
					int iProcessID = process.Id;
					vProcess.Add(iProcessID);
					OSServiceUtil.processsHashTable.Add(sJobID, vProcess);
					streamReader = process.StandardOutput;
					string sProcessOutput = streamReader.ReadToEnd();
					process.WaitForExit();
				
					vProcess.Remove(iProcessID);
					if(vProcess.Count <= 0){
						OSServiceUtil.processsHashTable.Remove(sJobID);
					}
					streamReader.Close();
					base.osrl = IOUtil.readStringFromFile(sResultFile);
					return;
				}
				catch(Exception e){
					IOUtil.log(e.ToString(), null);
					osrlWriter.setGeneralStatusType("error");
					osrlWriter.setGeneralStatusDescription(e.Message);
					base.osrl = osrlWriter.writeToString();
					return;
				}
			}
		}//solve
	}//class StandardSolver
}//namespace
