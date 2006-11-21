using System;

namespace org.optimizationservices.oscommon.exception{
	/// <summary>
	/// The <c>OSException</c> class is the the parent class of 
	/// all the OS related exception classes. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public abstract class OSException : System.ApplicationException{

		/// <summary>
		/// Default constructor. 
		/// </summary>
		public OSException(){
		}//constructor

		/// <summary>
		/// Constructs a new exception with the specified detail message.  
		/// </summary>
		/// <param name="message">holds the detail message</param>
		public OSException(string message) : base(message){
		}//constructor
    
		/// <summary>
		/// get exception id
		/// </summary>
		/// <returns> get exception id</returns>
		public abstract int getExceptionId();
	
		/// <summary>
		/// get exception name
		/// </summary>
		/// <returns> get exception name</returns>
		public abstract string getExceptionName();
	
		/// <summary>
		/// get exception type
		/// </summary>
		/// <returns> get exception type</returns>
		public abstract int getExceptionType();

	}//class OSException
}//namespace


