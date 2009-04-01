/**
 * @(#)JobOption 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.datastructure.osresult;

import java.util.GregorianCalendar;

import org.optimizationservices.oscommon.datastructure.osgeneral.JobDependencies;
import org.optimizationservices.oscommon.datastructure.osgeneral.DirectoriesAndFiles;
import org.optimizationservices.oscommon.datastructure.osgeneral.Processes;


/**
 *
 * <p>A data structure class that corresponds to an xml element in the OSoL schema.  
 *  
 * </p>
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
*/
public class JobResult{
	
	public MaxTime maxTime = new MaxTime();
	
	public GregorianCalendar requestedStartTime = new GregorianCalendar(1970, 0, 1, 0, 0, 0);
	
	public JobDependencies dependencies = null;
	
	public DirectoriesAndFiles requiredDirectories = null;

	public DirectoriesAndFiles requiredFiles = null;

	public DirectoriesAndFiles directoriesToMake = null;

	public DirectoriesAndFiles filesToMake = null;

	public PathPairs inputDirectoriesToMove = new PathPairs();

	public PathPairs inputFilesToMove = new PathPairs();

	public PathPairs outputDirectoriesToMove = new PathPairs();

	public PathPairs outputFilesToMove = new PathPairs();

	public DirectoriesAndFiles filesToDelete = null;

	public DirectoriesAndFiles directoriesToDelete = null;

	public Processes processesToKill = null;

	public OtherOptions otherOptions = null;
	
}//class JobOption
