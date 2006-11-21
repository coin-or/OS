using System;

using org.optimizationservices.oscommon.datastructure.osgeneral;

namespace org.optimizationservices.oscommon.datastructure.osoption{
	/// <summary>
	/// A data structure class that corresponds to an xml element in the OSoL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class JobOption{

		public double maxTime = Double.PositiveInfinity;
		
		public DateTime scheduledStartTime = new DateTime(1970, 1, 1, 0, 0, 0);
	
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
}//namespace
