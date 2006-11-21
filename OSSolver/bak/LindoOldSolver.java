/**
 * @(#)LindoSolver 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.ossolver.solver;

import org.optimizationservices.oscommon.util.ProcessUtil;

/**
 *
 * <P>The <code>LindoSolver</code> .</p>
 *
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.oscommon.representationparser.FMLHandler
 * @see org.optimizationservices.oscommon.representationparser.FMLReader
 * @see org.xml.sax.XMLReader
 * @see org.optimizationservices.oscommon.representationparser.OSiLReader
 * @since OS 1.0
 */
public class LindoSolver{
	/**
	 * constructor
	 */
	public LindoSolver(){
		
	}//constructor
	
	/**
	 *
	 * @param instructionListFileName is the name of the file that holds
	 * the optimization instance in the Lindo Instruction List style input.
	 *
	 * @return the name of the file that holds the solution.
	 */
	public String solve(String instructionListFileName){
		String sOS = System.getProperty("os.name").toLowerCase();
		String sLindoSolutionFileName = "";
		String sLindoPathName = "";
		if(sOS.indexOf("window") >= 0){
			sLindoSolutionFileName = "c:\\code\\lindo\\win32\\temp\\lindosol.dat";
			String sCommand = "c:\\code\\lindo\\win32\\bin\\lindo " + instructionListFileName + " > " + sLindoSolutionFileName;
			ProcessUtil.launchAndWaitForFinish(sCommand);
			
		}
		else if(sOS.indexOf("window") < 0){
			String sUserHome = System.getProperty("user.home");
			sLindoSolutionFileName = sUserHome + "/Documents/files/code/lindo/macosx/projects/oslindo/instances/lindosol.dat";
			sLindoPathName = sUserHome +         "/Documents/files/code/lindo/macosx/projects/oslindo/bin/lindo";
			String sCommand = sLindoPathName + " " + instructionListFileName + " " +  sLindoSolutionFileName;
			System.out.println("sLindoPathName =  " + sLindoPathName);
			System.out.println("instructionListFileName =  " + instructionListFileName);
			System.out.println("sLindoSolutionFileName =  " + sLindoSolutionFileName);			
			//System.out.println("The command is  " + sCommand);
			ProcessUtil.launchAndWaitForFinish(sCommand);
		}
		return sLindoSolutionFileName;
	}//solve
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		String sOS = System.getProperty("os.name").toLowerCase();
		String sInstructionListFileName = "";
		if(sOS.indexOf("window") >= 0){
			sInstructionListFileName = "c:\\temp\\lindoinput.dat";
		}
		else if(sOS.indexOf("window") < 0){
			sInstructionListFileName = System.getProperty("user.home") + "/temp/lindoinput.dat";
		}
		LindoSolver lindoSolver = new LindoSolver();
		lindoSolver.solve(sInstructionListFileName);
	}//main
}//class LindoSolver
