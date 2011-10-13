import java.io.File;

import javax.servlet.http.HttpServletRequest;

import org.apache.axis.MessageContext;
import org.apache.axis.transport.http.HTTPConstants;
import org.apache.log4j.Logger;
import org.optimizationservices.oscommon.communicationinterface.OShL;
import org.optimizationservices.oscommon.util.IOUtil;
import org.optimizationservices.oscommon.util.OSLog;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.OSServiceUtil;
import org.optimizationservices.ossolver.util.OSParameterFile;


/**
 *
 * the OS Solver's Web Service facade. 
 *
 * </p>
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.ossolver.api.OShL
 * @since OS 1.0
 */
public class OSSolverService implements OShL{
     
	/**
	 * m_osServiceUtil holds a default implementation of the solver service.
	 */
	private OSServiceUtil m_osServiceUtil = new OSServiceUtil();

	/**
	 * default constructor.
	 */
	public OSSolverService(){
		String sServiceName = OSParameter.SERVICE_NAME;
		if(sServiceName != null && sServiceName.length() > 0 && sServiceName.equalsIgnoreCase("OSSolverService")){
			String sSimpleName = this.getClass().getSimpleName();
			if(!sSimpleName.equalsIgnoreCase("OSSolverService")){
				OSParameter.SERVICE_NAME = this.getClass().getName();

			}
		}
	}//constructor
	
	/**
	 * Solve an optimization problem whose instance is given by a string following
	 * the Optimization Services instance Language (OSiL) schema and returns the solution
	 * in a string that follows the Optimization Services result Language (OSrL) schema.
	 *
	 * </P>
	 *
	 * @param osil holds the optimization instance in a string which format follows the
	 * Optimization Services instance Language (OSiL) schema.
	 * @param osol holds the optimization option in a string which format follows the 
	 * Optimization Services option Language (OSoL) schema.    
	 * @return the optimization result in a string which format follows the Optimization
	 * Services result Language (OSrL) schema.
	 * @see org.optimizationservices.ossolver.api.OShL#solve
	 */ 
	public String solve(String osil, String osol){
		return m_osServiceUtil.solve(osil, osol);
	}//solve


	/**
	 * get a job id 
	 * 
	 * @param osol holds the option for job id retrieval
	 * @return a jobID string. 
	 */
	public String getJobID(String osol){
		IOUtil.writeStringToFile(IOUtil.getCurrentDir()+":"+OSParameterFile.NAME+":"+OSParameter.LOG_FILE+":"+OSParameter.SOLVER_CLASS_NAME+":"+OSParameter.SOLVER_EXECUTABLE, "/Users/majxuh/Desktop/log.txt");
		String jobid=m_osServiceUtil.getJobID(osol);
		OSLog.log.info(jobid);
		return jobid;
	}//getJobID

	/**
	 * An asynchronous send method with instance and option for the Solver. 
	 * The option must contain a job id so that the job result can be retrieved later.
	 * 
	 * @param  osil holds the input instance. 
	 * @param osol holds the input option. 
	 * @return whether the instance and option are sent and received by this method successfully. 
	 */
	public boolean send(String osil, String osol){
		return m_osServiceUtil.send(osil, osol);
	}//send
	
	/**
	 * 
	 * Retrieve a previously sent job's result with a job id. If the job result is not ready, an empty string 
	 * will be returned.
	 * 
	 * @param osol holds input option, that contains the job id. 
	 * @return Retrieved result in a string, null or empty if result not ready. 
	 */
	public String retrieve(String osol){
		return m_osServiceUtil.retrieve(osol);
	}//retrieve
	
	/**
	 * Kill a previously sent job.
	 * 
	 * @param osol holds input option, that contains the job id. 
	 * @return the kill process status of the kill operation. 
	 */
	public String kill(String osol){
		return m_osServiceUtil.kill(osol);
	}//kill
	
	/**
	 * Set (push) and/or get (pull) runtime dynamic process information to and/or from the service. 
	 *
	 * @param osplInput holds the input process information in a string which format follows OSpL schema.
	 * @param holds the option in a string which format follows OSoL schema. 
	 * @return the output process information in a string which format follows the OSpL schema.
	 */
	public String knock(String osplInput, String osol){
		return m_osServiceUtil.knock(osplInput, osol);
	}//knock

	public static void main(String[] argv){
		
	}
	/**
	 * static constructor
	 */
	static{ 
		OSParameter.readAndSetOSParameter(OSParameterFile.setParameterFile());
	}//static constructor
}//class 
