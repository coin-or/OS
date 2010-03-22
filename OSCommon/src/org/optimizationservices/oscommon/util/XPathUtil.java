/**
 * @(#)XQueryUtil 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.util;

import java.io.InputStream;
import java.io.StringWriter;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Properties;

import javax.xml.transform.Result;
import javax.xml.transform.stream.StreamResult;
import javax.xml.transform.stream.StreamSource;

import net.sf.saxon.Configuration;
import net.sf.saxon.om.NodeInfo;
import net.sf.saxon.query.QueryResult;
import net.sf.saxon.sxpath.XPathStaticContext;
import net.sf.saxon.xpath.XPathEvaluator;

/**
 *
 * <P>The <code>XPathUtil</code> class contains methods for performing
 * common basic XPath-related operations used by various classes in the
 * Optimization Services (OS) framework. </p>
 *
 * </p>
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since   OS1.0
 */

public class XPathUtil{
	/**
	 * xPathEvaluator holds an xPath evaluator that can be used for evaluation. 
	 */
	private XPathEvaluator m_xPathEvaluator = null;
	
	/**
	 * constructor.
	 *
	 * </p>
	 * @param xmlData holds the name of the xml data to be queried. If null, the xml data 
	 * will be located from within the xPath, i.e. the doc(...) section of xpath.  The xmlData
	 * can either be a file name or an actual string that holds the xml data. 
	 * @param isFile holds whether the xmlData is a a file name or, otherwise (if false) an actual string
	 * that holds the xml data. 
	 */
	public XPathUtil(String xmlData, boolean isFile){
		try{
			m_xPathEvaluator = new XPathEvaluator();
			if(xmlData != null){
				if(isFile){
					StreamSource streamSource = new StreamSource(xmlData);
					m_xPathEvaluator.setSource(streamSource);	
				}
				else{
					InputStream inputStream = IOUtil.stringToInputStream(xmlData);
					StreamSource streamSource = new StreamSource(inputStream);
					m_xPathEvaluator.setSource(streamSource);
				}
			}
		}
		catch(Exception e){
			e.printStackTrace();
		}
	}//constructor
	
	/**
	 * Use an XPath string to query xml data. 
	 * 
	 * </p>
	 * 
	 * @param xPathString holds the XPath string that can be used to query xml data. 
	 * @param variables holds a hashmap of external variable name-value paris to be fed into the the XPath.
	 * @return a list of query result in type <code>java.util.List</code>. If there is an error querying, returns null.	 
	 */
	public List query(String xPathString, HashMap variables){
		try{
			if(variables != null){
				XPathStaticContext independentContext = (XPathStaticContext)m_xPathEvaluator.getStaticContext();
				Iterator it = variables.keySet().iterator();
				while(it.hasNext()){
					String sVarName = (String)it.next();
					String sVarValue = (String)variables.get(sVarName);
					independentContext.declareVariable(sVarName, sVarValue);
				}
			}
			List queryResult = m_xPathEvaluator.evaluate(xPathString);
			return queryResult;
		}
		catch(Exception e){
			e.printStackTrace();
			return null;
		}
	}//query
	
	/**
	 * Use an XPath string to query xml data and return the first found object in a string. 
	 * 
	 * </p>
	 * 
	 * @param xPathString holds the XPath string that can be used to query xml data. 
	 * @param variables holds a hashmap of external variable name-value paris to be fed into the the XPath.
	 * @return the first found object in string. 	 
	 */
	public String queryFirst(String xPathString, HashMap variables){
		try{
			if(variables != null){
				XPathStaticContext independentContext = (XPathStaticContext)m_xPathEvaluator.getStaticContext();
				Iterator it = variables.keySet().iterator();
				while(it.hasNext()){
					String sVarName = (String)it.next();
					String sVarValue = (String)variables.get(sVarName);
					independentContext.declareVariable(sVarName, sVarValue);
				}
			}
			Object oQueryResult = m_xPathEvaluator.evaluateSingle(xPathString);
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
				if (obj instanceof NodeInfo) {
					nodeInfo = (NodeInfo) obj;
					QueryResult.serialize(nodeInfo, fileResult, outputProp, config);
					sw.flush();
				}
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
		String sQuery1 = "bib/book[position()=$index]/title";
		String sQuery1replaced = sQuery1.replaceAll("\\$index", "1");
		System.out.println(sQuery1replaced);
		String sXmldata = "<bib><book><title>TCP/IP Illustrated</title>" + 
		"<author>Stevens</author>" +
		"<publisher>Addison-Wesley</publisher></book>" +
		"<book><title>Advanced Unix Programming</title>" +
		"<author>Stevens</author>" +
		"<publisher>Addison-Wesley</publisher></book>" +
		"<book><title>Data on the Web</title>" +
		"<author>Abiteboul</author>" +
		"<author>Buneman</author>" +
		"<author>Suciu</author></book></bib>";
		
		HashMap<String, Integer> map = new HashMap<String, Integer>();
		map.put("index", new Integer(3));
		
		long start = System.currentTimeMillis();
		XPathUtil xpathUtil = new XPathUtil(sXmldata, false);	
		System.out.println("Query 1 replaced: " + xpathUtil.queryFirst(sQuery1replaced, null));		
		System.out.println("Query 1: " + xpathUtil.queryFirst(sQuery1, map));
		List queryList = xpathUtil.query(sQuery1, map);	
		long finish = System.currentTimeMillis();
		System.out.println("CPU Time =  " +  Long.toString(finish - start));
		System.out.println("Query 1 list: ");
		//Iterator resultIterator = queryList.iterator();
		System.out.println("Number Nodes =  " +  queryList.size());
		String sResult = XPathUtil.printQueryResult(queryList);
		System.out.println(sResult);
	}//main
	
}//class XPathUtil
