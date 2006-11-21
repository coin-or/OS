using System;
using org.optimizationservices.oscommon.util;
 
namespace org.optimizationservices.oscommon.exception{
	/// <summary>
	/// The <c>OSException</c> class holds a two array 
	/// data structure for sparse representation of vector. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public abstract class OSilReadingException : OSException{

		/// <summary>
		/// Default constructor. 
		/// </summary>
		public OSilReadingException(){
		}//constructor

		/// <summary>
		/// Constructs a new exception with the specified detail message.  
		/// </summary>
		/// <param name="message">holds the detail message</param>
		public OSilReadingException(string message) : base(message){
		}//constructor
    
		/// <summary>
		/// m_iExceptionId holds the exception id
		/// <summary>
		private int m_iExceptionId = 2001;

		/// <summary>
		/// m_sExceptionName holds the exception name
		/// <summary>
		private String m_sExceptionName = "OSiL Reading Exception";

		/// <summary>
		/// m_iExceptionType holds the exception type
		/// </summary>
		private int m_iExceptionType = OSConstant.ERROR;

		/// <summary>
		/// get exception id
		/// </summary>
		/// <returns> get exception id</returns>
		public override int getExceptionId(){
			return m_iExceptionId;
		}//getExceptionId
	
		/// <summary>
		/// get exception name
		/// </summary>
		/// <returns> get exception name</returns>
		public override string getExceptionName(){
			return m_sExceptionName;
		}//getExceptionName
	
		/// <summary>
		/// get exception type
		/// </summary>
		/// <returns> get exception type</returns>
		public override int getExceptionType(){
			return m_iExceptionType;
		}//getExceptionType

	}//class OSException
}//namespace


