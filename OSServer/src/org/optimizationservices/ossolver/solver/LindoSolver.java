/**
 * @(#)LindoSolver 1.0 03/14/2004
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
import org.optimizationservices.ossolver.parser.LindoOSiLReader;
/**
*
* <P>The <code>LindoSolver</code>class is the lindo solver engine. 
*
* </p>
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2004
* @since OS 1.0
*/
public class LindoSolver extends DefaultSolver{
	/**
	 * default constructor.
	 */
	public LindoSolver(){
	}//constructor

	/**
	 * run the CG solver command that is specified in the batch file. 
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
		//prepare
		boolean bUseOSiL = true;
		String sInstructionList = "";
		String sInstructionListFile = "";
		LindoOSiLReader lindoOSiLReader = new LindoOSiLReader();
		//instruction list generation from osil
		if(!bUseOSiL){
			try {
				sInstructionList = lindoOSiLReader.osilToInstructionLists(osil);				
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
				osrlWriter.setGeneralStatusType("error");
				osrlWriter.setGeneralStatusDescription("error converting from OsiL to Lindo's instruction list");
				osrlWriter.setGeneralMessage(IOUtil.exceptionStackToString(e));
				super.osrl = osrlWriter.writeToString();
				if(OSParameter.SERVICE_URI == null || OSParameter.SERVICE_URI.length() <= 0){
					IOUtil.deleteFile(sInstanceFile);
					IOUtil.deleteFile(sOptionFile);
					IOUtil.deleteFile(sResultFile);
					IOUtil.deleteFile(sInstructionListFile);
				}		
				return;
			}
			if(sInstructionList == null || sInstructionList.length() <= 0 || lindoOSiLReader.m_sLogicError.length() > 0){
				osrlWriter.setGeneralStatusType("error");
				osrlWriter.setGeneralStatusDescription("Lindo can't solve the problem. The input file (instruction list) is empty.");
				if(lindoOSiLReader.m_sLogicError.length() > 0){
					osrlWriter.setGeneralMessage(lindoOSiLReader.m_sLogicError);
				}
				super.osrl = osrlWriter.writeToString();
				if(OSParameter.SERVICE_URI == null || OSParameter.SERVICE_URI.length() <= 0){
					IOUtil.deleteFile(sInstanceFile);
					IOUtil.deleteFile(sOptionFile);
					IOUtil.deleteFile(sResultFile);
					IOUtil.deleteFile(sInstructionListFile);
				}		
				return;
			}
			sInstructionListFile = OSParameter.TEMP_FILE_FOLDER+sJobID+".dat";
			IOUtil.writeStringToFile(sInstructionList, sInstructionListFile);
		}		
		//lindo solver
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

		String sSolver = "lindo";		
		String sArguments = 
			" -osol " + sOptionFile +
			" -osrl " + sResultFile + 
			" -solver " + sSolver;
		if(bUseOSiL){
			sArguments += (" -osil " + sInstanceFile); 			
		}
		else{
			sArguments += (" -insList " + sInstructionListFile); 
		}

		String[] msCommandLineOSiL =    {sSolverPath, "-osil", sInstanceFile, "-osol", sOptionFile, "-osrl", sResultFile, "-solver", sSolver};
		String[] msCommandlineInsList = {sSolverPath, "-osol", sOptionFile, "-osrl", sResultFile, "-insList", sInstructionListFile, "-solver", sSolver};
		String[] msCommandLine = bUseOSiL?msCommandLineOSiL:msCommandlineInsList;
		
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
				//osrlWriter.setGeneralStatusDescription(e.getMessage());
				osrlWriter.setGeneralStatusDescription("Error invoking "+ OSParameter.SOLVER_EXECUTABLE);
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
				//osrlWriter.setGeneralStatusDescription(e.getMessage());
				osrlWriter.setGeneralStatusDescription("Error invoking "+ OSParameter.SOLVER_EXECUTABLE);
				super.osrl = osrlWriter.writeToString();
			}
		}
		if(OSParameter.SERVICE_URI == null || OSParameter.SERVICE_URI.length() <= 0){
			IOUtil.deleteFile(sInstanceFile);
			IOUtil.deleteFile(sOptionFile);
			IOUtil.deleteFile(sResultFile);
			IOUtil.deleteFile(sInstructionListFile);
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
	}//main

}//LindoSolver
