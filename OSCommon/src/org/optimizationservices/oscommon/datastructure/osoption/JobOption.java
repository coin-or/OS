/**
 * @(#)JobOption 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.datastructure.osoption;

import java.util.GregorianCalendar;

import org.optimizationservices.oscommon.datastructure.osgeneral.JobDependencies;
import org.optimizationservices.oscommon.datastructure.osgeneral.DirectoriesAndFiles;
import org.optimizationservices.oscommon.datastructure.osgeneral.Processes;


/**
 *
 * <p>A data structure class that corresponds to an xml element in the OSoL schema.  
 *  
 * </p>
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
*/
public class JobOption{
	
	public double maxTime = Double.POSITIVE_INFINITY;
	
	public GregorianCalendar scheduledStartTime = new GregorianCalendar(1970, 0, 1, 0, 0, 0);
	
	public JobDependencies dependencies = null;
	
	public DirectoriesAndFiles requiredDirectoriesAndFiles = null;

	public DirectoriesAndFiles directoriesToMake = null;

	public DirectoriesAndFiles filesToCreate = null;

	public DirectoriesAndFiles inputFilesToCopyFrom = null;

	public DirectoriesAndFiles inputFilesToCopyTo = null;

	public DirectoriesAndFiles inputFilesToMoveFrom = null;

	public DirectoriesAndFiles inputFilesToMoveTo = null;

	public DirectoriesAndFiles outputFilesToCopyFrom = null;

	public DirectoriesAndFiles outputFilesToCopyTo = null;

	public DirectoriesAndFiles outputFilesToMoveFrom = null;

	public DirectoriesAndFiles outputFilesToMoveTo = null;

	public DirectoriesAndFiles filesToDelete = null;

	public DirectoriesAndFiles directoriesToDelete = null;

	public Processes processesToKill = null;

	
}//class JobOption
