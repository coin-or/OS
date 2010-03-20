/**
 * @(#)XQueryUtil 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.util;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.StringWriter;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Properties;

import javax.xml.transform.Result;
import javax.xml.transform.sax.SAXSource;
import javax.xml.transform.stream.StreamResult;

import net.sf.saxon.Configuration;
import net.sf.saxon.om.DocumentInfo;
import net.sf.saxon.om.NodeInfo;
import net.sf.saxon.query.DynamicQueryContext;
import net.sf.saxon.query.QueryResult;
import net.sf.saxon.query.StaticQueryContext;
import net.sf.saxon.query.XQueryExpression;

import org.xml.sax.InputSource;

/**
 *
 * <P>The <code>XQueryUtil</code> class contains methods for performing
 * common basic XQuery-related operations used by various classes in the
 * Optimization Services (OS) framework. </p>
 *
 * </p>
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since   OS1.0
 */

public class XQueryUtil{
	/**
	 * m_configuration holds configuration for XQuery. 
	 */
	private Configuration m_configuration = null;
	
	/**
	 * m_staticQueryContext holds the static information (compile time) of a query processor. 
	 */
	private StaticQueryContext m_staticQueryContext = null;
	
	/**
	 * m_dynamicQueryContext holds the dynamic information (run time) of a query processor. 
	 */
	private DynamicQueryContext m_dynamicQueryContext = null;
	
	/**
	 * XQueryExpression holds an XQuery expression that can be used for evaluation. 
	 */
	private XQueryExpression m_xqueryExpression = null;
	
	/**
	 * constructor.
	 *
	 * </p>
	 * @param xqueryString holds the XQuery string that can be used to query xml data. 	 
	 * @param xmlData holds the name of the xml data to be queried. If null, the xml data 
	 * will be located from within the xquery, i.e. the doc(...) section of xquery.  The xmlData
	 * can either be a file name or an actual string that holds the xml data. 
	 * @param isFile holds whether the xmlData is a a file name or, otherwise (if false) an actual string
	 * that holds the xml data. 
	 */
	public XQueryUtil(String xqueryString, String xmlData, boolean isFile){
		m_configuration = new Configuration();
		m_configuration.setHostLanguage( Configuration.XQUERY);
		m_staticQueryContext = new StaticQueryContext(m_configuration); 
		m_dynamicQueryContext = new DynamicQueryContext(m_configuration);
		try{
			if(xmlData != null && xmlData.length() > 0){
				InputSource inputSource = null;
				if(isFile) inputSource = new InputSource(xmlData);	
				else inputSource = new InputSource(IOUtil.stringToInputStream(xmlData));
				SAXSource saxsource = new SAXSource(inputSource); 
				DocumentInfo docInfo = m_staticQueryContext.buildDocument(saxsource);
				m_dynamicQueryContext.setContextNode(docInfo);			
			}
			InputStream is = IOUtil.stringToInputStream(xqueryString);
			BufferedReader bfQuery = new BufferedReader(new InputStreamReader(is));
			m_xqueryExpression = m_staticQueryContext.compileQuery(bfQuery);
		}
		catch(Exception e){
			e.printStackTrace();
		}
	}//constructor
	
	/**
	 * Use an XQuery string to query xml data. 
	 * 
	 * </p>
	 * 
	 * @param variables holds a hashmap of external variable name-value pairs to be fed into the the xquery.
	 * @return a list of query result in type <code>java.util.List</code>. If there is an error querying, returns null.
	 */	
	public List query(HashMap variables){
		try{
			if(variables != null){
				Iterator it = variables.keySet().iterator();
				while(it.hasNext()){
					String sVarName = (String)it.next();
					Object oVarValue = variables.get(sVarName);
					m_dynamicQueryContext.setParameter(sVarName, oVarValue);
				}
			}
			List queryResult = m_xqueryExpression.evaluate(m_dynamicQueryContext);
			return queryResult;
		}
		catch(Exception e){
			e.printStackTrace();
			return null;
		}
	}//query
	
	/**
	 * Use an XQuery string to query xml data and return the first found object in a string. 
	 * 
	 * </p>
	 * 
	 * @param variables holds a hashmap of external variable name-value paris to be fed into the the xquery.
	 * @return a list of query result in type <code>java.util.List</code>. If there is an error querying, returns null.
	 */	
	public String queryFirst(HashMap variables){
		try{
			if(variables != null){
				Iterator it = variables.keySet().iterator();
				while(it.hasNext()){
					String sVarName = (String)it.next();
					Object oVarValue = variables.get(sVarName);
					m_dynamicQueryContext.setParameter(sVarName, oVarValue);
				}
			}
			Object oQueryResult = m_xqueryExpression.evaluateSingle(m_dynamicQueryContext);
			String sQueryResult = null;
			if(oQueryResult instanceof NodeInfo){
				NodeInfo node = (NodeInfo) oQueryResult;
				sQueryResult = node.getStringValue();
			}
			else{ 
				sQueryResult = oQueryResult.toString();
			}
			return sQueryResult;
		}
		catch(Exception e){
			e.printStackTrace();
			return null;
		}
	}//queryFirst
	
	/**
	 * Print out the query result to a string for easy reading. 
	 * 
	 * </p>
	 * 
	 * @param queryResult holds a list of query result in type <code>java.util.List</code>. 
	 * @return the query result in a string for easy reading. 
	 */
	public static String printQueryResult(List queryResult){
		String sResult = "";
		try{
			Iterator resultIterator = queryResult.iterator();
			Object obj;
			NodeInfo node;
			while (resultIterator.hasNext()){
				obj = resultIterator.next();
				if (obj instanceof NodeInfo){
					node = (NodeInfo) obj;
					sResult += (node.getStringValue() + "\n");
				}
				else{ 
					sResult += ("Atomic type =  " + obj.toString() + "\n");
				}
			}
			return sResult;
		}
		catch (Exception e) {
			e.printStackTrace();
			return null;
		}
	}//printQueryResult
	
	/**
	 * Convert a query result to a string. 
	 * 
	 * </p>
	 * 
	 * @param queryResult holds a list of query result in type <code>java.util.List</code>. 
	 * @return a string representation of the query result. 
	 */
	public static String queryResultToString(List queryResult){
		String sResult = "";
		try{
			Iterator resultIterator = queryResult.iterator();
			Object obj;
			NodeInfo nodeInfo;
			Properties outputProp = new Properties();
			Configuration config = new Configuration();
			config.setHostLanguage( Configuration.XQUERY);
			//outputProp.setProperty(OutputKeys.METHOD, "xml");
			StringWriter sw = new StringWriter();
			Result fileResult = new StreamResult(sw);
			while (resultIterator.hasNext()){				
				obj = resultIterator.next();				
				if (obj instanceof NodeInfo){					
					nodeInfo = (NodeInfo) obj;					
					QueryResult.serialize(nodeInfo, fileResult, outputProp, config);					
					sw.flush();					
				}
				else sw.write(obj.toString() + " ");
			}
			sw.flush();
			sResult = sw.toString();
			sw.close();
			int index = -1;
			int oldindex = 0;
			index = sResult.indexOf("&#xD;");
			while (index > -1){
				StringBuffer tempBuf = new StringBuffer( sResult);
				tempBuf.delete(index, index + 5);
				sResult = tempBuf.toString();
				index = sResult.indexOf("&#xD;", oldindex);
				oldindex = index;
			}
			return sResult;
		}
		catch (Exception e) {
			e.printStackTrace();
			return null;
		}
	}//queryResultToString
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] args){
		String sQuery1 = "for  $a in fn:distinct-values(//author)" +
		"return (xs:string($a)," +
		"for $b in //book[author = $a]" +
		"return $b/title)";
		String sQuery2 = "/bib/book[position()=$index]/title";
		String sQuery2replaced = sQuery2.replaceAll("\\$index", "1");
		System.out.println(sQuery2replaced);
		String sQuery3 = "declare variable $index as xs:integer external; /bib/book[position()=$index]/title";
		String sXmldata = "<bib><book><title>TCP/IP Illustrated</title>" + 
		"<author>Stevens</author>" +
		"<publisher>Addison-Wesley</publisher></book>" +
		"<book><title>Advanced Unix Programming</title>" +
		"<author>Stevens</author>" +
		"<publisher>Addison-Wesley</publisher></book>" +
		"<book><title>Data on the Web</title>" +
		"<author>Abiteboul</author>" +
		"<author>Buneman</author>" +
		"<author>Suciu</author></book>" +
		"<book>" +
		"<title>Large Scale Linear and Integer Optimization: A Unified Approach</title>" +
		"<author>Martin</author>" +
		"<publisher>Kluwer Academic Press</publisher>" +
		"</book>" +
		"<book>" +
		"<title>AMPL</title>" +
		"<author>Fourer</author>" +
		"<author>Gay</author>" +
		"<author>Kernighan</author>" +
		"<publisher> Duxbury Press </publisher>" +
		"</book></bib>";
		
		System.out.println(sXmldata);
		System.out.println(sQuery1);
		HashMap<String, Integer> map = new HashMap<String, Integer>();
		map.put("index", new Integer(3));
		
		long start = System.currentTimeMillis();
		XQueryUtil xqueryUtil = new XQueryUtil(sQuery1, sXmldata, false);
		System.out.println(XQueryUtil.printQueryResult(xqueryUtil.query(null)));

		//xqueryUtil = new XQueryUtil(sQuery2, sXmldata, false);
		//System.out.println("Query 2: " + xqueryUtil.queryFirst(map)); //must declear variable
		xqueryUtil = new XQueryUtil(sQuery2replaced, sXmldata, false);
		System.out.println("Query 2 replaced: " + xqueryUtil.query(null));		
		xqueryUtil = new XQueryUtil(sQuery3, sXmldata, false);
		List queryList = xqueryUtil.query(map);	
		long finish = System.currentTimeMillis();
		System.out.println("CPU Time =  " +  Long.toString(finish - start));
		System.out.println("Query 3: ");
		//Iterator resultIterator = queryList.iterator();
		System.out.println("Number Nodes =  " +  queryList.size());
		String sResult = XQueryUtil.printQueryResult(queryList);
		System.out.println(sResult);
	}//main
	
}//class XQueryUtil
