using System;
using System.Net;
using System.Collections;
using System.Text;
using System.Text.RegularExpressions;

using org.optimizationservices.oscommon.util.misc;
using org.optimizationservices.oscommon.representationparser;

namespace org.optimizationservices.oscommon.util{
	/// <summary>
	/// The <c>CommonUtil</c> class contains methods for performing
	/// common basic operations used by all other classes and projects
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class CommonUtil{
		
		public CommonUtil(){
		}//constructor

		/// <summary>
		/// Check whether a number string is positive infinity or not, 
		/// including the following (case insensitive):
		/// infinity, inf,
		/// </summary>
		/// <param name="numberString">holds the number string to be checked</param>
		/// <returns> whether a number string is postive infinity or not </returns>
		public static bool isPostiveInfinity(String numberString){
			if(numberString.ToLower().Equals("infinity")) return true;
			if(numberString.ToLower().Equals("inf")) return true;
			return false;
		}//isPostiveInfinity

		
		/// <summary>
		/// Check whether a number string is negative infinity or not, 
		/// including the following (case insensitive):
		/// -infinity, -inf,
		/// </summary>
		/// <param name="numberString">holds the number string to be checked</param>
		/// <returns> whether a number string is negative infinity or not </returns>
		public static bool isNegativeInfinity(String numberString){
			if(numberString.ToLower().Equals("-infinity")) return true;
			if(numberString.ToLower().Equals("-inf")) return true;
			return false;
		}//isNegativeInfinity

		/// <summary>
		/// get a unique job id 
		/// </summary>
		/// <param name="option">holds the extra option for generating the job id.</param>
		/// <returns>a unique job id</returns>
		public static string getJobID(string option){
			if(option != null && option.Length > 0){
				try{
					OSoLReader osolReader = new OSoLReader(OSParameter.VALIDATE);
					osolReader.readString(option);
				}
				catch(Exception e){
					IOUtil.log(e.ToString(), null);
					
				}
			}
			string sJobID = "";
			string sHostName = Dns.GetHostName();
			sJobID += (sHostName + OSConstant.JODID_DELIMITER);
			
			IPHostEntry ipHostEntry = Dns.GetHostByName(sHostName);
			IPAddress[] mIPAddress = ipHostEntry.AddressList;

			int i;
			int iNumberIPAddress = (mIPAddress == null)?0:mIPAddress.Length;
			for(i = 0; i < iNumberIPAddress; i++){
				sJobID += mIPAddress[i].ToString();
				if(i != iNumberIPAddress -1) sJobID+="_";
			}
			sJobID += OSConstant.JODID_DELIMITER;

			DateTime dateTime = DateTime.Now;
			sJobID += (dateTime.Month + "." + 
					   dateTime.Day + "." +
					   dateTime.Year + "." + 
					   dateTime.DayOfWeek + "." + 
				       dateTime.Hour + "." + 
				       dateTime.Minute + "." + 
					   dateTime.Second + "." + 
				       dateTime.Millisecond  + OSConstant.JODID_DELIMITER);
			
			Random random = new Random();
			sJobID += random.Next(1000000000).ToString();
			sJobID = sJobID.Replace(':', '.');
			sJobID = sJobID.Replace('%', '.');

			return sJobID;
		}//getJobID

		/// <summary>
		/// Converts a delimited string to a vector. 
		/// </summary>
		/// <param name="theString">holds the string to be converted to a vector. </param>
		/// <param name="delimiter">holds the delimiter characters of the string. </param>
		/// <returns>the vector converted from the string</returns>
		public static ArrayList stringToVector(string theString, string delimiter){
			int iDelimiters = delimiter==null?0:delimiter.Length;
			char[] mcSeparator = new char[iDelimiters];
			for(int i = 0; i < iDelimiters; i++){
				mcSeparator[i] = delimiter[i];
			}
			String[] msTokens = theString.Split(mcSeparator);
			ArrayList vTokens = new ArrayList();
			int iTokens = msTokens==null?0:msTokens.Length;
			for(int i = 0; i < iTokens; i++){
				if(msTokens[i].Length > 0){
					vTokens.Add(msTokens[i]);
				}
			}
			return vTokens;
		}//stringToVector

		/// <summary>
		/// get the difference, measured in milliseconds, between
		/// the current time and midnight, January 1, 1970 UTC.
		/// </summary>
		/// <returns>the difference, measured in milliseconds, between 
		/// the current time and midnight, January 1, 1970 UTC</returns>
		public static long currentTimeMillis(){
			TimeSpan t = (DateTime.Now - new DateTime(1970, 1, 1, 0, 0, 0));
			long lTimeMillis  = (long) t.TotalMilliseconds;
			return lTimeMillis;
		}//currentTimeMillis

		/// <summary>
		/// get the difference, measured in milliseconds, between
		/// the specified time and midnight, January 1, 1970 UTC.
		/// </summary>
		/// <param name="time">holds the time to retrieve milliseconds</param>
		/// <returns>the difference, measured in milliseconds, between 
		/// the current time and midnight, January 1, 1970 UTC</returns>
		public static long timeMillis(DateTime time){
			TimeSpan t = (time - new DateTime(1970, 1, 1, 0, 0, 0));
			long lTimeMillis  = (long) t.TotalMilliseconds;
			return lTimeMillis;
		}//currentTimeMillis

		/// <summary>
		/// create the native dateTime from the timeMillis, which is the millisecond
		/// since 1/1/1970. 
		/// </summary>
		/// <param name="timeMillis">holds the time represented in milliseconds since 1/1/1970.</param>
		/// <returns>the converted native dateTime</returns>
		public static DateTime createNativeDateTime(long timeMillis){
			DateTime origin = new DateTime(1970, 1, 1, 0, 0, 0);
			if(timeMillis <= 0){
				return origin;
			}
			DateTime time = origin + new TimeSpan(timeMillis * TimeSpan.TicksPerMillisecond);
			time = time.ToLocalTime();
			return time;
		}//createNativeDateTime
		
	}//class CommonUtil
}//namespace
