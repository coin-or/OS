/**
 * @(#)OSFileUpload 1.0 05/20/2005
 *
 * Copyright (c) 2005 Kipp Martin 
 */
package org.optimizationservices.oscommon.util;
import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.apache.commons.fileupload.FileItem;
import org.apache.commons.fileupload.FileUploadException;
import org.apache.commons.fileupload.disk.DiskFileItemFactory;
import org.apache.commons.fileupload.servlet.ServletFileUpload;

public class OSFileUpload extends HttpServlet{
	public void init(ServletConfig config) throws ServletException {
	}
	
	public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException  {
		OSParameterFile.NAME = OSParameterFile.setParameterFile(request);
		// first check if the upload request coming in is a multipart request
		//boolean isMultipart = ServletFileUpload.isMultipartContent(request);

		// if not, send to message page with the error message
		//if(!isMultipart){
		//	request.setAttribute("msg", "Request was not multipart!");
		//	request.getRequestDispatcher("msg.jsp").forward(request, response);
		//	return;
		//}
		// Parse the request
		//List  items = upload.parseRequest( request) ;
		DiskFileItemFactory factory = new DiskFileItemFactory();
		// Configure the factory here, if desired.
		ServletFileUpload upload = new ServletFileUpload(factory);
		// Configure the uploader here, if desired.
		PrintWriter out = response.getWriter();
		try{
			java.util.List fileItems = upload.parseRequest(request);
			FileItem item;
			String fileName = "";
			item = (FileItem) fileItems.get( 0);
			fileName = item.getName();
			String path = OSParameter.TEMP_FILE_FOLDER;//"/home/kmartin/temp/";
			File uploadedFile = new File(path + fileName);
			try{
			item.write( uploadedFile);
			}
			catch(java.lang.Exception ioe){
				out.println("<html>");
				out.println( "There was an error trying to save the uploaded file.");
				out.println("</html>");		
                out.println("\r\n");	
			}
            out.println("<html>");
			out.println( "The file " + fileName + " was successfuly uploaded and saved on the following server directory:");
			out.println( OSParameter.TEMP_FILE_FOLDER+fileName);
			out.println("</html>");
            out.println("\r\n");
		}
		catch(FileUploadException fe) {
			out.println("<html>");
			out.println( "There was an error getting the file." );
            out.println(  fe );
			out.println("</html>");
            out.println("\r\n");
		}

	}

}

 
