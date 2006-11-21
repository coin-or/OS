using System;
using System.Web.Mail;
using System.Collections;
using System.IO;
using System.Threading;

namespace org.optimizationservices.oscommon.util{
	/// <summary>
	/// The <c>MailUtil</c> class contains methods for performing
	/// EMail related operations used by all other classes and projects
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class MailUtil{
		public MailUtil(){
		}//constructor

		/// <summary>
		/// send an email. 
		/// </summary>
		/// <param name="fromEmail">holds the  from email address to send the email; uses default from email if null.  </param>
		/// <param name="toEmail">holds the to email address to send the email; uses default to email if null. Use comma (,), semicolon (;) or space to delimit if sending to multiple addresses</param>
		/// <param name="ccEmail">holds the cc (carbon copy) email address to send the email, no cc email if null. Use comma (,), semicolon (;) or space to delimit if cc sending to multiple addresses. </param>
		/// <param name="bccEmail">holds the bcc (blind carbon copy) email address to send the email; no bcc email if null. Use comma (,), semicolon (;) or space to delimit if bcc sending to multiple addresses.</param>
		/// <param name="subject">holds the email subject; uses default suject if null.</param>
		/// <param name="message">holds the email message body; uses default message if null.</param>
		/// <param name="attachedFiles">holds an array of the file names (w/ full paths) to be attached; no file attached if null. Use comma (,), semicolon (;) or space to delimit if multiple file names.</param>
		/// <returns>whether the mail is sent successfully or not. </returns>
		public static bool send(string fromEmail, string toEmail, string ccEmail, string bccEmail, string subject, string message, string attachedFiles){
			try{
				SmtpMail.SmtpServer = OSParameter.SMTP_SERVER;
				MailMessage msg = new MailMessage();
				
				if(fromEmail == null || fromEmail.Length == 0){
					msg.From = OSParameter.FROM_EMAIL;
				}
				else{
					msg.From = fromEmail;
				}
				if(toEmail != null && toEmail.Length > 0){
					ArrayList vToEmails = CommonUtil.stringToVector(toEmail, ",; \t\r\n");
					string sToEmail = "";
					int n = vToEmails.Count;
					for(int i = 0; i < n-1; i++){
						sToEmail += (string)vToEmails[i];
						sToEmail += ";";
					}
					sToEmail += (String)vToEmails[n-1];
					msg.To = sToEmail; 
				}
				else{
					msg.To = OSParameter.TO_EMAIL;
				}
				if(ccEmail != null && ccEmail.Length > 0){
					ArrayList vCCEmails = CommonUtil.stringToVector(ccEmail, ",; \t\r\n");
					string sCCEmail = "";
					int n = vCCEmails.Count;
					for(int i = 0; i < n-1; i++){
						sCCEmail += (string)vCCEmails[i];
						sCCEmail += ";";
					}
					sCCEmail += (String)vCCEmails[n-1];
					msg.Cc = sCCEmail; 
				}
				if(bccEmail != null && bccEmail.Length > 0){
					ArrayList vBCCEmails = CommonUtil.stringToVector(bccEmail, ",; \t\r\n");
					string sBCCEmail = "";
					int n = vBCCEmails.Count;
					for(int i = 0; i < n-1; i++){
						sBCCEmail += (string)vBCCEmails[i];
						sBCCEmail += ";";
					}
					sBCCEmail += (String)vBCCEmails[n-1];
					msg.Bcc = sBCCEmail; 
				}
				msg.Subject = (subject==null?OSParameter.MAIL_SUBJECT:subject);
				msg.Body = (message==null?OSParameter.MAIL_MESSAGE:message);
				if(attachedFiles != null){
					ArrayList vAttachedFiles = CommonUtil.stringToVector(attachedFiles, ",; \t\r\n");
					for(int i = 0; i < vAttachedFiles.Count; i++){
						try {
							string sFileName = (string)vAttachedFiles[i];
							if(!File.Exists(sFileName)){
								IOUtil.log("File [" + sFileName + "] doesn't exisit.", null);
								continue;
							}
							MailAttachment mailAttachment = new MailAttachment(sFileName); 
							msg.Attachments.Add(mailAttachment); 
						} 
						catch (Exception e) {
							IOUtil.log(e.ToString(), null);
						}
					}
				}
				SmtpMail.Send(msg);
				return true;
			}
			catch (Exception e){
				IOUtil.log(e.ToString(), null);
				return false;		   
			}
		}//send
	
		/// <summary>
		/// send an email in a thread so that there is no wait time. 
		/// </summary>
		/// <param name="fromEmail">holds the  from email address to send the email; uses default from email if null.  </param>
		/// <param name="toEmail">holds the to email address to send the email; uses default to email if null. Use comma (,), semicolon (;) or space to delimit if sending to multiple addresses</param>
		/// <param name="ccEmail">holds the cc (carbon copy) email address to send the email, no cc email if null. Use comma (,), semicolon (;) or space to delimit if cc sending to multiple addresses. </param>
		/// <param name="bccEmail">holds the bcc (blind carbon copy) email address to send the email; no bcc email if null. Use comma (,), semicolon (;) or space to delimit if bcc sending to multiple addresses.</param>
		/// <param name="subject">holds the email subject; uses default suject if null.</param>
		/// <param name="message">holds the email message body; uses default message if null.</param>
		/// <param name="attachedFiles">holds an array of the file names (w/ full paths) to be attached; no file attached if null. Use comma (,), semicolon (;) or space to delimit if multiple file names.</param>
		public static void sendInThread(String fromEmail, String toEmail, String ccEmail, String bccEmail, String subject, String message, String attachedFiles){
			SendThread sendThread = new SendThread(fromEmail, toEmail, ccEmail, bccEmail, subject, message, attachedFiles);
			Thread thread = new Thread(new ThreadStart(sendThread.send));
			thread.Start();
		}//sendInThread

		/// <summary>
		/// <c>SendThread</c> is an internal thread controlled by <c>MailUtil</c>.
		/// </summary>
		protected internal class SendThread{
			/// <summary>
			/// m_sFromEmail holds the  from email address to send the email; uses default from email if null.  
			/// </summary>
			protected String m_sFromEmail = null;
		
			/// <summary>
			///  m_sToEmail holds the to email address to send the email; uses default to email if null. Use comma (,), semicolon (;) or space to delimit if sending to multiple addresses.
			/// </summary>
			protected String m_sToEmail = null;
		
			/// <summary>
			///  m_sCCEmail holds the cc (carbon copy) email address to send the email, no cc email if null. Use comma (,), semicolon (;) or space to delimit if cc sending to multiple addresses.
			/// </summary>
			protected String m_sCCEmail = null;
		
			/// <summary>
			///  m_sBCCEmail holds the bcc (blind carbon copy) email address to send the email; no bcc email if null. Use comma (,), semicolon (;) or space to delimit if bcc sending to multiple addresses.
			/// </summary>
			protected String m_sBCCEmail = null;
		
			/// <summary>
			///  m_sSubject holds the email subject; uses default suject if null.
			/// </summary>
			protected String m_sSubject = null;
		
			/// <summary>
			///  m_sMessage holds the email message body; uses default message if null.
			/// </summary>
			protected String m_sMessage = null;
		
			/// <summary>
			///  m_sAttachedFiles holds an array of the file names (w/ full paths) to be attached; no file attached if null. Use comma (,), semicolon (;) or space to delimit if multiple file names.
			/// </summary>
			protected String m_sAttachedFiles = null;

			/// <summary>
			/// Constructor
			/// </summary>
			/// <param name="fromEmail">holds the  from email address to send the email; uses default from email if null.  </param>
			/// <param name="toEmail">holds the to email address to send the email; uses default to email if null. Use comma (,), semicolon (;) or space to delimit if sending to multiple addresses</param>
			/// <param name="ccEmail">holds the cc (carbon copy) email address to send the email, no cc email if null. Use comma (,), semicolon (;) or space to delimit if cc sending to multiple addresses. </param>
			/// <param name="bccEmail">holds the bcc (blind carbon copy) email address to send the email; no bcc email if null. Use comma (,), semicolon (;) or space to delimit if bcc sending to multiple addresses.</param>
			/// <param name="subject">holds the email subject; uses default suject if null.</param>
			/// <param name="message">holds the email message body; uses default message if null.</param>
			/// <param name="attachedFiles">holds an array of the file names (w/ full paths) to be attached; no file attached if null. Use comma (,), semicolon (;) or space to delimit if multiple file names.</param>
			protected internal SendThread(String fromEmail, String toEmail, String ccEmail, String bccEmail, String subject, String message, String attachedFiles){
				m_sFromEmail = fromEmail;
				m_sToEmail = toEmail;
				m_sCCEmail = ccEmail;
				m_sBCCEmail = bccEmail;
				m_sSubject = subject;
				m_sMessage = message;
				m_sAttachedFiles = attachedFiles;
			}//constructor

			/// <summary>
			/// The send method is implemented here. 
			/// </summary>
			protected internal virtual void send(){
				MailUtil.send(m_sFromEmail, m_sToEmail, m_sCCEmail, m_sBCCEmail, m_sSubject, m_sMessage, m_sAttachedFiles);
			}//send
	
		}//SendThread

	
	}//class MailUtil
}//namespace