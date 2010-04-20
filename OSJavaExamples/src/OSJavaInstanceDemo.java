/** @file OSJavaDemo.java
 * 
 * @author  Gus Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.0, 29/01/2010
 * @since   OS2.0
 *
 * \remarks
 * Copyright (C) 2008, Gus Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University, Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 * Based on example of Olivier Cailloux
 * 
 */ 



import java.io.File;

//import org.apache.axis.MessageContext;

import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.OSParameterFile;
import org.optimizationservices.oscommon.util.OSServiceUtil;
import org.optimizationservices.oscommon.util.StandardOSSolver;
import org.optimizationservices.oscommon.util.IOUtil;
import org.optimizationservices.oscommon.util.ProcessUtil;
import org.optimizationservices.oscommon.localinterface.OSInstance;
import org.optimizationservices.oscommon.datastructure.osgeneral.SparseVector;
import org.optimizationservices.oscommon.localinterface.OSInstance;
import org.optimizationservices.oscommon.representationparser.OSiLWriter;

/**
 the following are in my CLASSPATH
 OSCommon.jar
 axis.jar
 jaxrpc.jar
 xerces.jar
 commons-logging.jar
 commons-discovery.jar
 or124.jar
 */


public class OSJavaInstanceDemo {
	
	
	
	public static void main(String args[]){

		try {
			// location of parameter file -- in same directory
			OSParameterFile.NAME = "OSParameter.xml";
			// build the parinc problem -- see parincLinear.osil
			OSInstance osinstance = new OSInstance();
			osinstance.setInstanceName("parinc problem");
			
			//add the variables
			osinstance.setVariableNumber(2);
			osinstance.addVariable(0, "x0", 0, Double.POSITIVE_INFINITY, 'C');
			osinstance.addVariable(1, "x1", 0, Double.POSITIVE_INFINITY, 'C');
			
			//add the objective function
			osinstance.setObjectiveNumber(1);
			SparseVector objCoeff = new SparseVector();
			objCoeff.indexes = new int[] { 0, 1 };
			objCoeff.values = new double[] { 10.0, 9.0 };
			osinstance.addObjective(-1, "maxProfit", "max", 0.0, 1.0, objCoeff);
			
			//now add the constraints
			osinstance.setConstraintNumber(4);
			osinstance.addConstraint(0, "row0", Double.NEGATIVE_INFINITY, 630, 0); 
			osinstance.addConstraint(1, "row1", Double.NEGATIVE_INFINITY, 600, 0);
			osinstance.addConstraint(2, "row2", Double.NEGATIVE_INFINITY, 708, 0);
			osinstance.addConstraint(3, "row3", Double.NEGATIVE_INFINITY, 135, 0); 
			
			//now add the <linearConstraintCoefficients> in column major format
			//bool setLinearConstraintCoefficients(int numberOfValues, bool isColumnMajor, 
			//	double* values, int valuesBegin, int valuesEnd, 
			//	int* indexes, int indexesBegin, int indexesEnd,   			
			//	int* starts, int startsBegin, int startsEnd);	
			double[] values = new double[8];
			int[] indexes = new int[ 8];
			int[] starts = new int[ 3]; 
			values[ 0] = .7;
			values[ 1] = .5;
			values[ 2] = 1.0;
			values[ 3] = .1;
			values[ 4] = 1.0;
			values[ 5] = 5./6.;
			values[ 6] = 2./3.;
			values[ 7] = .25;
			indexes[ 0] = 0;
			indexes[ 1] = 1;
			indexes[ 2] = 2;
			indexes[ 3] = 3;
			indexes[ 4] = 0;
			indexes[ 5] = 1;
			indexes[ 6] = 2;  
			indexes[ 7] = 3;
			starts[ 0] = 0;
			starts[ 1] = 4;
			starts[ 2] = 8; 
			osinstance.setLinearConstraintCoefficients(8, true, values, 0, 7, 
													   indexes, 0, 7, starts, 0, 2);
			String osil = osinstance.writeOSiL();
			IOUtil.writeStringToFile(osil, "parincLinear.osil");
			
			// now let's solve this guy
			// we are assuming that the OSSolverService executable is in the same directory as
			// this OSJavaDemo class
			String sArguments = 
			" -osil parincLinear.osil -osrl answer.osrl" ;
			String sOS = System.getProperty("os.name");
			String sArch = System.getProperty("os.arch");

			System.out.print(sOS );
			System.out.print(sArch );
			//sArguments = 
			//	" -osil parincLinear.osil -osrl answer.osrl -serviceLocation http://127.0.0.1:8080/OSServer/services/OSSolverService" ;
			
			sArguments = 
				" -osil parincLinear.osil " ;
			String sSolverPath = "../../OSThirdParty/lib/coin-or/OSSolverService" + "-"+ sOS + "-"+ sArch;
			System.out.print(sSolverPath );
			ProcessUtil.launchAndWaitForFinish(sSolverPath + " " + sArguments);			


		}//end try
		catch( Exception e ) {
			e.printStackTrace();
		}//end catch
	}//end main
	
}//end class OSInstanceDemo