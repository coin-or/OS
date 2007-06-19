/**
 * @(#)MailUtil 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.util;

import java.io.File;
import java.util.Properties;
import java.util.Vector;

import javax.activation.DataHandler;
import javax.activation.FileDataSource;
import javax.mail.Message;
import javax.mail.Multipart;
import javax.mail.Session;
import javax.mail.Transport;
import javax.mail.internet.InternetAddress;
import javax.mail.internet.MimeBodyPart;
import javax.mail.internet.MimeMessage;
import javax.mail.internet.MimeMultipart;

 


/**
 *
 * <P>The <code>MailUtil</code> class contains methods for performing
 * common basic EMail related operations used by various classes in the
 * Optimization Services (OS) framework. </p>
 *
 * </p>
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since   OS1.0
 */

public class MailUtil{
	/**
	 * send an email. 
	 * 
	 * @param fromEmail holds the  from email address to send the email; uses default from email if null.  
	 * @param toEmail holds the to email address to send the email; uses default to email if null. Use comma (,), semicolon (;) or space to delimit if sending to multiple addresses
	 * @param ccEmail holds the cc (carbon copy) email address to send the email, no cc email if null. Use comma (,), semicolon (;) or space to delimit if cc sending to multiple addresses. 
	 * @param bccEmail holds the bcc (blind carbon copy) email address to send the email; no bcc email if null. Use comma (,), semicolon (;) or space to delimit if bcc sending to multiple addresses.
	 * @param subject holds the email subject; uses default suject if null.
	 * @param message holds the email message body; uses default message if null.
	 * @param attachedFiles holds an array of the file names (w/ full paths) to be attached; no file attached if null. Use comma (,), semicolon (;) or space to delimit if multiple file names.
	 * @return whether the mail is sent successfully or not. 
	 */
	public static boolean send(String fromEmail, String toEmail, String ccEmail, String bccEmail, String subject, String message, String attachedFiles){
		try{
			if(fromEmail == null || fromEmail.length() <= 0 || fromEmail.indexOf("@") < 0 || fromEmail.indexOf(".") < 0) return false;
			if(toEmail == null || toEmail.length() <= 0 || toEmail.indexOf("@") < 0 || toEmail.indexOf(".") < 0) return false;
			if(OSParameter.SMTP_SERVER == null || OSParameter.SMTP_SERVER.length() <= 0) return false;
			Properties props = System.getProperties();
			props.put("mail.smtp.host", OSParameter.SMTP_SERVER);
			//props.put("mail.protocol.user", OSParameter.FROM_EMAIL.substring(0, OSParameter.FROM_EMAIL.indexOf('@')));
			Session session = Session.getDefaultInstance(props, null);
			session.setDebug(false);
			MimeMessage msg = new MimeMessage(session);
			msg.setSentDate(new java.util.Date());
			if(fromEmail == null || fromEmail.length() == 0){
				msg.setFrom(new InternetAddress(OSParameter.FROM_EMAIL));
			}
			else{
				msg.setFrom(new InternetAddress(fromEmail));
			}
			if(toEmail != null && toEmail.length() > 0){
				Vector<String> vToEmails = CommonUtil.stringToVector(toEmail, ",; \t\r\n");
				for(int i = 0; i < vToEmails.size(); i++){
					msg.addRecipient(Message.RecipientType.TO, new InternetAddress((String)vToEmails.elementAt(i)));					
				}
			}
			else{
				msg.addRecipient(Message.RecipientType.TO, new InternetAddress(OSParameter.TO_EMAIL));
			}
			if(ccEmail != null && ccEmail.length() > 0){
				Vector<String> vCCEmails = CommonUtil.stringToVector(ccEmail, ",; \t\r\n");
				for(int i = 0; i < vCCEmails.size(); i++){
					msg.addRecipient(Message.RecipientType.CC, new InternetAddress((String)vCCEmails.elementAt(i)));					
				}
			}
			if(bccEmail != null && bccEmail.length() > 0){
				Vector<String> vBCCEmails = CommonUtil.stringToVector(bccEmail, ",; \t\r\n");
				for(int i = 0; i < vBCCEmails.size(); i++){
					msg.addRecipient(Message.RecipientType.BCC, new InternetAddress((String)vBCCEmails.elementAt(i)));					
				}
			}
			msg.setSubject(subject==null?OSParameter.MAIL_SUBJECT:subject);
			if(attachedFiles == null){
				msg.setText(message==null?OSParameter.MAIL_MESSAGE:message);
			}
			else{
			    MimeBodyPart textPart = new MimeBodyPart();
			    textPart.setContent(message==null?OSParameter.MAIL_MESSAGE:message, "text/plain");
			    Multipart multipart = new MimeMultipart();
			    multipart.addBodyPart(textPart);

			    MimeBodyPart attachedFilePart;
			    Vector<String> vAttachedFiles = CommonUtil.stringToVector(attachedFiles, ",; \t\r\n");
			    for(int i = 0; i < vAttachedFiles.size(); i++){
				    try {
				    	String sFileName = (String)vAttachedFiles.elementAt(i);
				    	File file = new File(sFileName);
				    	if(!file.exists()){
				    		IOUtil.log("File [" + sFileName + "] doesn't exisit.", null);
				    		continue;
				    	}
						FileDataSource fileDataSource = new FileDataSource(sFileName);
						attachedFilePart = new MimeBodyPart();
						attachedFilePart.setDataHandler(new DataHandler(fileDataSource));
						attachedFilePart.setFileName(fileDataSource.getName());
						multipart.addBodyPart(attachedFilePart);
					} 
				    catch (Exception e) {
						IOUtil.log(IOUtil.exceptionStackToString(e), null);
					}
			    }
			    msg.setContent(multipart);
			}
			Transport.send(msg);
			return true;
		}
		catch (Exception e){
			e.printStackTrace();
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
			return false;		   
		}
	}//send
	
	/**
	 * send an email in a thread so that there is no wait time. 
	 * 
	 * @param fromEmail holds the  from email address to send the email; uses default from email if null.  
	 * @param toEmail holds the to email address to send the email; uses default to email if null. Use comma (,), semicolon (;) or space to delimit if sending to multiple addresses
	 * @param ccEmail holds the cc (carbon copy) email address to send the email, no cc email if null. Use comma (,), semicolon (;) or space to delimit if cc sending to multiple addresses. 
	 * @param bccEmail holds the bcc (blind carbon copy) email address to send the email; no bcc email if null. Use comma (,), semicolon (;) or space to delimit if bcc sending to multiple addresses.
	 * @param subject holds the email subject; uses default suject if null.
	 * @param message holds the email message body; uses default message if null.
	 * @param attachedFiles holds an array of the file names (w/ full paths) to be attached; no file attached if null. Use comma (,), semicolon (;) or space to delimit if multiple file names. 
	 */
	public static void sendInThread(String fromEmail, String toEmail, String ccEmail, String bccEmail, String subject, String message, String attachedFiles){
		MailUtil mailUtil = new MailUtil();
		SendThread sendThread = mailUtil.new SendThread(fromEmail, toEmail, ccEmail, bccEmail, subject, message, attachedFiles);
		Thread thread = new Thread(sendThread);
		thread.start();
	}//sendInThread
	
	/**
	 * <P>The <code>SendThread</code> class is an internal thread controlled by <code>MailUtil</code>.
	 */
	protected class SendThread implements Runnable{
		/**
		 * m_sFromEmail holds the  from email address to send the email; uses default from email if null.  
		 */
		protected String m_sFromEmail = null;
		
		/**
		 * m_sToEmail holds the to email address to send the email; uses default to email if null. Use comma (,), semicolon (;) or space to delimit if sending to multiple addresses.
		 */
		protected String m_sToEmail = null;
		
		/**
		 * m_sCCEmail holds the cc (carbon copy) email address to send the email, no cc email if null. Use comma (,), semicolon (;) or space to delimit if cc sending to multiple addresses.
		 */
		protected String m_sCCEmail = null;
		
		/**
		 * m_sBCCEmail holds the bcc (blind carbon copy) email address to send the email; no bcc email if null. Use comma (,), semicolon (;) or space to delimit if bcc sending to multiple addresses.
		 */
		protected String m_sBCCEmail = null;
		
		/**
		 * m_sSubject holds the email subject; uses default suject if null.
		 */
		protected String m_sSubject = null;
		
		/**
		 * m_sMessage holds the email message body; uses default message if null.
		 */
		protected String m_sMessage = null;
		
		/**
		 * m_sAttachedFiles holds an array of the file names (w/ full paths) to be attached; no file attached if null. Use comma (,), semicolon (;) or space to delimit if multiple file names.
		 */
		protected String m_sAttachedFiles = null;

		/**
		 * Constructor
		 * 
		 * @param fromEmail holds the  from email address to send the email; uses default from email if null.  
		 * @param toEmail holds the to email address to send the email; uses default to email if null. Use comma (,), semicolon (;) or space to delimit if sending to multiple addresses.
		 * @param ccEmail holds the cc (carbon copy) email address to send the email, no cc email if null. Use comma (,), semicolon (;) or space to delimit if cc sending to multiple addresses. 
		 * @param bccEmail holds the bcc (blind carbon copy) email address to send the email; no bcc email if null. Use comma (,), semicolon (;) or space to delimit if bcc sending to multiple addresses.
		 * @param subject holds the email subject; uses default suject if null.
		 * @param message holds the email message body; uses default message if null.
		 * @param attachedFiles holds an array of the file names (w/ full paths) to be attached; no file attached if null. Use comma (,), semicolon (;) or space to delimit if multiple file names. 
		 */
		protected SendThread(String fromEmail, String toEmail, String ccEmail, String bccEmail, String subject, String message, String attachedFiles){
			m_sFromEmail = fromEmail;
			m_sToEmail = toEmail;
			m_sCCEmail = ccEmail;
			m_sBCCEmail = bccEmail;
			m_sSubject = subject;
			m_sMessage = message;
			m_sAttachedFiles = attachedFiles;
		}//constructor
		
		/**
		 * A send method is implemented here. 
		 */
		public void run(){	
			MailUtil.send(m_sFromEmail, m_sToEmail, m_sCCEmail, m_sBCCEmail, m_sSubject, m_sMessage, m_sAttachedFiles);
		}//run		
	}//SendThread
	
	/**
	 * main for test purposes.
	 * 
	 * </p>
	 * 
	 * @param argv command line arguments.
	 */
	public static void main(String[] args){
		MailUtil.sendInThread("majxuh@hotmail.com",  null,  "", "", "Hi", "Hello World", null);
		//System.out.println(MailUtil.send("maj@northwestern.edu", "majxuh@hotmail.com", "maj@northwestern.edu", "maj@northwestern.edu", "hii", "Hello World", null));
		//System.out.println(MailUtil.send("maj@northwestern.edu",  null,  "", "xuhmaj@hotmail.com, majxuh@hotmail.com", "bccHii", "Hello World", OSParameter.LOG_FILE+" "+"c:/s19o.qr"));
		//System.out.println(MailUtil.send(null, null,null, null, null));
		//System.out.println(MailUtil.send(null, null, "maj@iems.northwestern.edu", "maj@northwestern.edu", null, null, OSParameter.LOG_FILE));
	}//main
	
}//class MailUtil
