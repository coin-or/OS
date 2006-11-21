/**
 * @(#)ResultData 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.datastructure.osresult;

import org.optimizationservices.oscommon.datastructure.osprocess.ProcessStatistics;

/**
*
* <p>A data structure class that corresponds to an xml element in the OSrL schema.  
*  
* </p>
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2004
* @since OS 1.0
*/
public class ResultData {

		public ProcessStatistics statistics = null;

		public OptimizationResult optimization = null;
			
		public OtherResult[] other = null;
		
}//ResultData
