/**
 * @(#)StandardOSSolver 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.util;

import java.io.BufferedReader;
import java.io.File;
import java.io.InputStreamReader;
import java.util.GregorianCalendar;
import java.util.Vector;

import org.optimizationservices.oscommon.localinterface.DefaultSolver;
import org.optimizationservices.oscommon.localinterface.OSOption;
import org.optimizationservices.oscommon.representationparser.OSrLWriter;
import org.optimizationservices.oscommon.util.IOUtil;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.OSServiceUtil;
import org.optimizationservices.oscommon.util.ProcessUtil;
/**
*
* <P>The <code>StandardOSSolver</code>class is the standard solver engine. 
*
* </p>
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2004
* @since OS 1.0
*/
public class StandardOSSolver extends DefaultSolver{
	/**
	 * default constructor.
	 */
	public StandardOSSolver(){
	}//constructor

	/**
	 * run the standard solve method. 
	 */
	public void solve(){
		String sOS = System.getProperty("os.name");
		String sArch = System.getProperty("os.arch");
		String sJobID = osOption.getJobID();
//		String sOSSolver = osOption.getOtherOptimizationOptionValueByName("os_solver");
		String sOSSolver = osOption.getSolverToInvoke();
//		if(sOSSolver == null || sOSSolver.length() <= 0) sOSSolver = osOption.getOtherOptionValueByName("os_solver");
		if(sOSSolver == null || sOSSolver.length() <= 0) sOSSolver = osOption.getSolverToInvoke();
		if(sOSSolver == null || sOSSolver.length() <= 0) sOSSolver = OSParameter.OS_SOLVER;
		
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
		String sSolverPath = "";
		if(OSParameter.SOLVER_EXECUTABLE.startsWith("OSSolverService")){
			// Eclipse deploys to here a lot easier
			sSolverPath =  OSParameter.SERVICE_FOLDER + "WEB-INF/classes/OSSolverService";
			// normalize java to unix naming conventions.
			if(sArch.equals("i386"))
				sArch="i686";
			else if(sArch.equals("amd64"))
				sArch="x86_64";
			else if(sOS.startsWith("Windows"))
				sOS="Windows";
			else if(sOS.startsWith("Mac"))
				sOS="Mac";
			sSolverPath += "-" + sOS + "-" + sArch;
			// make executable if necessary (war deployment hack)
			File exe=new File(sSolverPath);
			if(! exe.canExecute()){
				exe.setExecutable(true);
			}
		}
		else{
			sSolverPath =  OSParameter.CODE_HOME + "solver/"+OSParameter.SOLVER_EXECUTABLE;
		}
		String sArguments = 
			" -osil " + sInstanceFile + 
			" -osol " + sOptionFile +
			" -osrl " + sResultFile + 
			((sOSSolver==null || sOSSolver.trim().length()<=0)?" ":(" -solver " + sOSSolver)); 
		
		String[] msCommandLine = {
				sSolverPath, 
				"-osil", sInstanceFile, 
				"-osol", sOptionFile,
				"-osrl", sResultFile,
				"-solver", sOSSolver};
		if(sOSSolver==null || sOSSolver.trim().length()<=0){
			String[] msCommandLineAlt = {
					sSolverPath, 
					"-osil", sInstanceFile, 
					"-osol", sOptionFile,
					"-osrl", sResultFile};
			msCommandLine = msCommandLineAlt;
		}
			
		//no need to change below
		boolean bUseSimple = false;
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
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		OSOption osOption = new OSOption();
		try {
			osOption = osOption.readOSoL("c:/remoteSolve1.osol", true, false);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
//		String sOSSolver = osOption.getOtherOptimizationOptionValueByName("os_solver");
		String sOSSolver = osOption.getSolverToInvoke();
		System.out.println(sOSSolver);
	}//main

}//StandardOSSolver
