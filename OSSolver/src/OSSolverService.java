

import org.optimizationservices.oscommon.communicationinterface.OShL;
import org.optimizationservices.oscommon.localinterface.DefaultSolver;
import org.optimizationservices.oscommon.util.IOUtil;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.OSParameterFile;
import org.optimizationservices.oscommon.util.OSServiceUtil;

/**
 *
 * <P>The <code>OSSolverService</code> is the default OS Solver's Web Service facade. 
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
		//All the things in this constructor are optional and should all be deleted just fine. 
		m_osServiceUtil.serviceName = OSParameter.SERVICE_NAME;
		m_osServiceUtil.serviceURI = OSParameter.SERVICE_URI;
		m_osServiceUtil.serviceType = OSParameter.SERVICE_TYPE;
		try {
			String sClassName = OSParameter.SOLVER_CLASS_NAME; //"org.optimizationservices.oscommon.util.StandardSolver";
			Class solverClass = Class.forName(sClassName);
			m_osServiceUtil.solver =(DefaultSolver)solverClass.newInstance();			
		} 
		catch (Exception e) {
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
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
		return m_osServiceUtil.getJobID(osol);
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
		//automatically detect where the tomcat installation and webapp context is. 
		String sDir = IOUtil.getCurrentDir();
		if(sDir.toLowerCase().endsWith("bin") || 
				sDir.toLowerCase().endsWith("bin\\") ||
				sDir.toLowerCase().endsWith("bin/")){
			int iIndex = sDir.lastIndexOf("bin");
			sDir = sDir.substring(0, iIndex);
		}
		OSParameterFile.NAME = sDir+= "webapps/os/WEB-INF/code/OSParameter.xml";
		//all the above line can be rewritten with one line, e.g. on windows, the following hardcoded parameter file address:
		//OSParameterFile.NAME = sDir+= "/Program Files/Apache Software Foundation/Tomcat 5.5/webapps/os/WEB-INF/code/OSParameter.xml";
	}//static constructor
}//class OSSolverService
