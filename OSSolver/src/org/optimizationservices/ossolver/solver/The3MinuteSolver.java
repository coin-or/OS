/**
 * @(#)The3MinuteSolver 1.0 03/14/2004
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
import org.optimizationservices.oscommon.util.IOUtil;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.OSServiceUtil;
import org.optimizationservices.oscommon.util.ProcessUtil;
/**
*
* <P>The <code>The3MinuteSolver</code>class is a computing engine that always takes 3 minutes. 
*
* </p>
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2004
* @since OS 1.0
*/
public class The3MinuteSolver extends DefaultSolver{

	/**
	 * default constructor.
	 */
	public The3MinuteSolver(){
	}//constructor

	/**
	 * run the The3Minute solver command that is specified in the batch file. 
	 */
	public void solve(){
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

		//change starts
		String sSolverPath = OSParameter.CODE_HOME + "solver/OSSolverService";
		if(sOS.indexOf("window") >= 0){
			sSolverPath += "Win32.exe";
		}
		else if(sOS.indexOf("linux") >= 0){
			sSolverPath += "Linux";
		}
		else if(sOS.indexOf("mac") >= 0){
			sSolverPath += "Mac";
		}
		else{
			;
		}

		String sSolver = "3MinuteSolver"; 
		String sArguments = 
			" -osil " + sInstanceFile + 
			" -osol " + sOptionFile +
			" -osrl " + sResultFile + 
			" -solver " + sSolver;

		String[] msCommandLine = {
				sSolverPath, 
				"-osil", sInstanceFile, 
				"-osol", sOptionFile,
				"-osrl", sResultFile,
				"-solver", sSolver};

		//no need to change below
		boolean bUseSimple;
		if(OSParameter.SERVICE_URI == null || OSParameter.SERVICE_URI.length() <= 0){
			bUseSimple = true;
		}
		else{
			bUseSimple = false;
		}
		if(bUseSimple){//simple version - not registering process 
			try {
				ProcessUtil.launchAndWaitForFinish(sSolverPath + " " + sArguments);
				super.osrl = IOUtil.readStringFromFile(sResultFile);				
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
				osrlWriter.setGeneralStatusType("error");
				osrlWriter.setGeneralStatusDescription(e.getMessage());
				super.osrl = osrlWriter.writeToString();
			}
		}
		else{ //complex version - registering process
			try{
				Process process = null;		
				process = Runtime.getRuntime().exec(msCommandLine);		
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
				vProcess.remove(process);
				if(vProcess.size() <= 0){
					OSServiceUtil.processsHashTable.remove(sJobID);
				}
				br.close();	
				super.osrl = IOUtil.readStringFromFile(sResultFile);
			}
			catch(Exception e){
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
				osrlWriter.setGeneralStatusType("error");
				osrlWriter.setGeneralStatusDescription(e.getMessage());
				super.osrl = osrlWriter.writeToString();
			}
		}
		if(OSParameter.SERVICE_URI == null || OSParameter.SERVICE_URI.length() <= 0){
			IOUtil.deleteFile(sInstanceFile);
			IOUtil.deleteFile(sOptionFile);
			IOUtil.deleteFile(sResultFile);
		}
		return;
	}//solve
	
	/**
	 * main for test purposes.
	 *
	 * </p>

	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		
	}//main

}//The3MinuteSolver
