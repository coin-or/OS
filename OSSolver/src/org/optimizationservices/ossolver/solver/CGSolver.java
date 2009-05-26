/**
 * @(#)CGSolver 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.ossolver.solver;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.GregorianCalendar;
import java.util.Vector;

import org.optimizationservices.oscommon.localinterface.DefaultSolver;
import org.optimizationservices.oscommon.representationparser.OSrLWriter;
import org.optimizationservices.oscommon.representationparser.OSsLReader;
import org.optimizationservices.oscommon.util.IOUtil;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.OSServiceUtil;
/**
*
* <P>The <code>CGSolver</code>class is the real CG computing engine. 
*
* </p>
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2004
* @since OS 1.0
*/
public class CGSolver extends DefaultSolver{

	/**
	 * default constructor.
	 */
	public CGSolver(){
	}//constructor

	/**
	 * run the CG solver command that is specified in the batch file. 
	 */
	public void solve() throws Exception{
		String sOS = System.getProperty("os.name").toLowerCase();
		String sJobID = osOption.getJobID();

		String sInstanceFile = OSParameter.TEMP_FILE_FOLDER+sJobID+".osil";
		if(IOUtil.existsFileOrDir(sInstanceFile)){
			IOUtil.writeStringToFile(osil, sInstanceFile);
		}
		String sOptionFile = OSParameter.TEMP_FILE_FOLDER+sJobID+".osol";
		if(IOUtil.existsFileOrDir(sOptionFile)){
			IOUtil.writeStringToFile(osol, sOptionFile);
		}

		String sResultFile = OSParameter.TEMP_FILE_FOLDER+sJobID+".osrl";
		OSrLWriter osrlWriter = new OSrLWriter();
		osrlWriter.setServiceURI(OSParameter.SERVICE_URI);
		osrlWriter.setServiceName(OSParameter.SERVICE_NAME);
		osrlWriter.setResultTimeStamp(new GregorianCalendar());

		OSsLReader osslReader = new OSsLReader(OSParameter.VALIDATE);
		boolean bRead = osslReader.readString(super.osil);
		if(!bRead){
			osrlWriter.setGeneralStatusType("error");
			osrlWriter.setGeneralStatusDescription("OSsL input is not valid");
			osrlWriter.setResultTimeStamp(new GregorianCalendar());
			super.osrl = osrlWriter.writeToString();
			return;
		}
		String sGlobdir = osslReader.getInputByName("Globdir");
		//String sJobName = "c:/CGWeb/RunCG.sas";
		String sJobName = osslReader.getInputByName("JobName");
		String sBatchFileName = osslReader.getInputByName("batchFile");
		boolean bDoTest = false;
		
		if(bDoTest && (sBatchFileName == null || sBatchFileName.length() <= 0)){
			try {
				//Thread.sleep(10000); 
			} 
			catch (Exception e) {
			}
			super.osrl = sGlobdir + ": Got it!!!!!!!!!";			
		}
		else if(bDoTest && sBatchFileName != null && sBatchFileName.length() > 0 && sBatchFileName.toLowerCase().endsWith("cgtest.exe")){
			try{
				Thread.sleep(10000);
				Process process = null;			
				if(sOS.indexOf("window") >= 0){
					String[] msCommandLine = {sBatchFileName};
					process = Runtime.getRuntime().exec(msCommandLine);		
				}
				else if(sOS.indexOf("window") < 0){
					String[] msCommandLine = {sBatchFileName};
					process = Runtime.getRuntime().exec(msCommandLine);		
				}			
				Vector<Process> vProcess = (Vector<Process>)OSServiceUtil.processsHashTable.get(sJobID);
				if(vProcess == null || vProcess.size() <= 0){
					vProcess = new Vector<Process>();
				}
				vProcess.add(process);
				OSServiceUtil.processsHashTable.put(sJobID, vProcess);				
				BufferedReader br = new BufferedReader (new InputStreamReader(process.getInputStream ()));
				boolean bCont = true;
				String sProcessOutput = "";
				String sTemp;
				while (bCont){
					sTemp = br.readLine(); 
					if(sTemp != null){
						sProcessOutput += sTemp+"\n";							
					}
					else{
						bCont = false;
					}
				}
				process.waitFor();
				vProcess.remove(process);
				if(vProcess.size() <= 0){
					OSServiceUtil.processsHashTable.remove(sJobID);
				}
				br.close();	
				osrlWriter.setGeneralStatusType("success");
				osrlWriter.addOtherGeneralResult("processOutput", sProcessOutput, "standard output from launched process");
				super.osrl = osrlWriter.writeToString();
			}
			catch(Exception e){
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
				/*
				osrlWriter = new OSrLWriter();
				osrlWriter.setGeneralStatusType("error");
				osrlWriter.setGeneralStatusDescription(e.getMessage());
				super.osrl = osrlWriter.writeToString();
				*/
				super.osrl = "";
				throw e;
			}	
		}
		else{
			String sInput = "";
			StringBuffer sBuffer = new StringBuffer();
			String sSASInputFile = "/CGWeb/"+ sJobID + ".dat";
			try{
				//process OSsL input
				if(!IOUtil.existsFileOrDir(sJobName)){
					osrlWriter.setGeneralStatusType("error");
					osrlWriter.setGeneralStatusDescription("SAS job input file: " + sJobName + " does not exist");
					osrlWriter.setResultTimeStamp(new GregorianCalendar());
					super.osrl = osrlWriter.writeToString();
					return;
				}
				int iInput = osslReader.getInputNumber();
				String[] msInputNames = osslReader.getInputNames();
				String[] msInputValues = osslReader.getInputValues();
				for(int i = 0; i < iInput; i++){
					sBuffer.append(msInputNames[i]);
					sBuffer.append(",");
					sBuffer.append(msInputValues[i]);
					if(i < iInput-1){
						sBuffer.append("\n");
					}
				}
				if(iInput > 0){
					sInput = sBuffer.toString();
				}
				IOUtil.writeStringToFile(sInput, sSASInputFile);
				
				//run the process
				Process process = null;			
				if(sOS.indexOf("window") >= 0){
					String[] msCommandLine = {"c:/Program Files/SAS Institute/SAS/V8/sas.exe", 
							"-log", OSParameter.TEMP_FILE_FOLDER + sJobID +".log", "-print", OSParameter.TEMP_FILE_FOLDER + sJobID + ".lst", "-sasinitialfolder", "c:/CGWeb",
							"-sysin", sJobName, "-noworkterm", "-noxwait", "-noxsync", "-nosplash", "-icon", "-nostatuswin"}; 		
					process = Runtime.getRuntime().exec(msCommandLine);		
				}
				else if(sOS.indexOf("window") < 0){
					String[] msCommandLine = {"c:/Program Files/SAS Institute/SAS/V8/sas.exe", 
							"-log", OSParameter.TEMP_FILE_FOLDER + sJobID +".log", "-print", OSParameter.TEMP_FILE_FOLDER + sJobID + ".lst", "-sasinitialfolder", "c:/CGWeb",
							"-sysin", sJobName, "-noworkterm", "-noxwait", "-noxsync", "-nosplash", "-icon", "-nostatuswin"}; 		
					process = Runtime.getRuntime().exec(msCommandLine);		
				}		
				Vector<Process> vProcess = (Vector<Process>)OSServiceUtil.processsHashTable.get(sJobID);
				if(vProcess == null || vProcess.size() <= 0){
					vProcess = new Vector<Process>();
				}
				vProcess.add(process);
				OSServiceUtil.processsHashTable.put(sJobID, vProcess);
				BufferedReader br = new BufferedReader (new InputStreamReader(process.getInputStream ()));
				boolean bCont = true;
				String sProcessOutput = "";
				String sTemp;
				
				while (bCont){
					sTemp = br.readLine(); 
					if(sTemp != null){
						sProcessOutput += sTemp;							
					}
					else{
						bCont = false;
					}
				}
				
				process.waitFor();
				process.destroy();
				vProcess.remove(process);
				if(vProcess.size() <= 0){
					OSServiceUtil.processsHashTable.remove(sJobID);
				}
				br.close();	
				
				osrlWriter.setGeneralStatusType("success");
				osrlWriter.addOtherGeneralResult("processOutput", sProcessOutput, "standard output from launched process");

				osrlWriter.addOtherGeneralResult("logFile", IOUtil.readStringFromFile(OSParameter.TEMP_FILE_FOLDER + sJobID + ".log"), "SAS log file");
				osrlWriter.addOtherGeneralResult("lstFile", IOUtil.readStringFromFile(OSParameter.TEMP_FILE_FOLDER + sJobID + ".lst"), "SAS output/print file");
				
				super.osrl = osrlWriter.writeToString();
				
				IOUtil.deleteFile(sSASInputFile);

			}
			catch(Exception e){
				IOUtil.deleteFile(sSASInputFile);
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
				/*
				osrlWriter = new OSrLWriter();
				osrlWriter.setGeneralStatusType("error");
				osrlWriter.setGeneralStatusDescription(e.getMessage());
				super.osrl = osrlWriter.writeToString();
				*/
				super.osrl = "";
				throw e;
			}
		}
	}//solve
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
//		CGSolver cgSolver = new CGSolver();
//		cgSolver.m_sBatchFileName = "c:/CGWeb/CGTest.exe";
//		cgSolver.m_sJobID = "abcdefg";
//		cgSolver.solve();
//		System.out.println(cgSolver.osrl);
		
	}//main

}//CGSolver
