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
	/// The <c>CGSolver</c> class is the real CG computing engine. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class CGSolver : org.optimizationservices.oscommon.localinterface.DefaultSolver{

		/// <summary>
		/// default constructor
		/// </summary>
		public CGSolver(){
		}//constructor
		
		/// <summary>
		/// run the CG solver command that is specified in the batch file. 
		/// </summary>
		public override void solve(){
			OSrLWriter osrlWriter = new OSrLWriter();
			string sJobID = osOption.getJobID();
			OSsLReader osslReader = new OSsLReader(OSParameter.VALIDATE);
			bool bRead = osslReader.readString(base.osil);
			if(!bRead){
				osrlWriter.setGeneralStatusType("error");
				osrlWriter.setGeneralStatusDescription("OSsL input is not valid");
				osrlWriter.setResultTime(DateTime.Now);
				base.osrl = osrlWriter.writeToString();
				return;
			}			
			string sGlobdir = osslReader.getInputByName("Globdir");
			//string sJobName = "c:/CGWeb/RunCG.sas";
			string sJobName = osslReader.getInputByName("JobName");
			string sBatchFileName = osslReader.getInputByName("batchFile");
			bool bDoTest = false;

			if(bDoTest && sBatchFileName.ToLower().EndsWith("cgtest.exe")){
				try{
					Thread.Sleep(10000);
					StreamReader streamReader = null;
					ProcessStartInfo processStartInfo = new ProcessStartInfo();
					processStartInfo.RedirectStandardOutput = true;
					processStartInfo.FileName = sBatchFileName;
					processStartInfo.Arguments = null;
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
					process.Kill();
				
					vProcess.Remove(iProcessID);
					if(vProcess.Count <= 0){
						OSServiceUtil.processsHashTable.Remove(sJobID);
					}
					streamReader.Close();
					osrlWriter.setGeneralStatusType("success");
					osrlWriter.addOtherResult("processOutput", sProcessOutput, "standard output from launched process");
					base.osrl = osrlWriter.writeToString();
				}
				catch(Exception e){
					IOUtil.log(e.ToString(), null);
					/*
					osrlWriter = new OSrLWriter();
					osrlWriter.setGeneralStatusType("error");
					osrlWriter.setGeneralStatusDescription(e.Message);
					base.osrl = osrlWriter.writeToString();
					*/
					base.osrl = "";
					throw e;
				}	
			}
			else{
				string sInput = "";
				StringWriter sBuffer = new StringWriter();
				string sSASInputFile = "/CGWeb/"+ sJobID + ".dat";
				try{
					//process OSsL input
					if(!IOUtil.existsFileOrDir(sJobName)){
						osrlWriter.setGeneralStatusType("error");
						osrlWriter.setGeneralStatusDescription("SAS job input file: " + sJobName + " does not exist");
						osrlWriter.setResultTime(DateTime.Now);
						base.osrl = osrlWriter.writeToString();
						return;
					}

					int iInput = osslReader.getInputNumber();
					string[] msInputNames = osslReader.getInputNames();
					string[] msInputValues = osslReader.getInputValues();
					for(int i = 0; i < iInput; i++){
						sBuffer.Write(msInputNames[i]);
						sBuffer.Write(",");
						sBuffer.Write(msInputValues[i]);
						if(i < iInput-1){
							sBuffer.Write("\n");
						}
					}
					if(iInput > 0){
						sInput = sBuffer.ToString();
					}
					IOUtil.writeStringToFile(sInput, sSASInputFile);

					//run the process
					StreamReader streamReader = null;
					ProcessStartInfo processStartInfo = new ProcessStartInfo();
					processStartInfo.RedirectStandardOutput = true;
					processStartInfo.FileName = @"C:\Program Files\SAS Institute\SAS\V8\sas.exe";
					String sArguments = 
						("-log " + OSParameter.TEMP_FILE_FOLDER + sJobID +".log" +
						" -print " + OSParameter.TEMP_FILE_FOLDER + sJobID + ".lst" +
						" -sasinitialfolder c:/CGWeb " + 
                        " -sysin " + sJobName + 
						" -noworkterm -noxwait -noxsync -nosplash -icon -nostatuswin"); 		

					//processStartInfo.Arguments = @"-log c:\CGWeb\RunCG.log -print c:\CGWeb\RunCG.lst -sasinitialfolder c:\CGWeb -sysin c:\CGWeb\RunCG.sas -noworkterm  -noxwait -noxsync -nosplash -icon -nostatuswin"; //-noterminal
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
					osrlWriter.setGeneralStatusType("success");
					osrlWriter.addOtherResult("processOutput", sProcessOutput, "standard output from launched process");

					osrlWriter.addOtherResult("logFile", IOUtil.readStringFromFile("C:\\CGWeb\\RunCG.log"), "SAS log file");
					osrlWriter.addOtherResult("lstFile", IOUtil.readStringFromFile("C:\\CGWeb\\RunCG.lst"), "SAS output/print file");

					base.osrl = osrlWriter.writeToString();

					IOUtil.deleteFile(sSASInputFile);
				}
				catch(Exception e){
					IOUtil.deleteFile(sSASInputFile);
					IOUtil.log(e.ToString(), null);
					/*
					osrlWriter = new OSrLWriter();
					osrlWriter.setGeneralStatusType("error");
					osrlWriter.setGeneralStatusDescription(e.Message);
					base.osrl = osrlWriter.writeToString();
					*/
					base.osrl = "";
					throw e;
				}
			}
		}//solve
	}//class CGSolver
}//namespace
