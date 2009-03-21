/**
 * @(#)OSmLQueryResultToOSiL 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.osmodeler.parser.osml;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Vector;

import org.optimizationservices.oscommon.representationparser.OSiLWriter;
import org.optimizationservices.oscommon.util.IOUtil;
import org.optimizationservices.oscommon.util.XMLUtil;
import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.SAXParseException;
import org.xml.sax.helpers.DefaultHandler;

/**
 *
 * <P>The <code>OSmLQueryResultToOSiL</code> class is derived from the SAX DefaultHandler
 * class. When the SAX parser encounter the start and end of elements, methods
 * in OSmLQueryResultToOSiL are called. Within these methods OSiL elements are constructed using 
 * OSiLWriter.</p>
 *
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.oscommon.representationparser.OSiLWriter
 * @see org.xml.sax.helpers.DefaultHandler
 * @since OS 1.0
 */
public class OSmLQueryResultToOSiL
extends DefaultHandler {
	/**
	 * m_osilWriter is used to construct an optimization instance that follows
	 * the Optimization Services instance Language format. 
	 */
	private OSiLWriter m_osilWriter = null;
	
	/**
	 * m_sSource holds the source of the optimization instance. 
	 */
	private String m_sSource = "From Optimization Services modeling Language";
	/**
	 * m_sName holds the name of the optimization instance. 
	 */
	private String m_sName = "";
	
	/**
	 * m_sDescription holds the description of the optimization instance. 
	 */
	private String m_sDescription = "An Optimization Services modeling Language example";
	
	/**
	 * m_iConIdx holds the current constraint index. 
	 */
	private int m_iConIdx = 0;
	/**
	 * m_iVarIdx holds the current variable index. 
	 */
	private int m_iVarIdx = 0;
	
	/**
	 * m_sObjName holds the name of the objective function. 
	 */
	private String m_sObjName = "";
	
	/**
	 * m_bMaxOrMin holds whether the objective is minimization (true) or maximimization (false). 
	 */
	private boolean m_bMaxOrMin = true;
	
	/**
	 * m_dObjConstant holds the constant of the objective function. 
	 */
	private double m_dObjConstant = 0;
	
	/**
	 * m_sConName holds the name of the current constraint. 
	 */
	private String m_sConName = "";
	
	/**
	 * m_sVarName holds the name of the current variable. 
	 */
	private String m_sVarName = "";
	
	/**
	 * m_sLongVarName holds the name of the current variable in OSiLWriter format. 
	 */
	private String m_sLongVarName;
	
	/**
	 * m_sUserFunctionName holds the name of the current userFunction definition. 
	 */
	private String m_sUserFunctionName = "";
	
	/**
	 * m_iUserFunctionNumArg holds the number of arguments of the current userFunction definition. 
	 */
	private int m_iUserFunctionNumArg = -1;
	
	/**
	 * m_bObj holds whether we are inside &lt;obj&gt;.
	 */
	private boolean m_bObj = false;
	
	/**
	 * m_bVar holds whether we are inside <var>;&lt;/var&gt; or &lt;var&gt;&lt;/var&gt;.
	 */
	private boolean m_bVar = false;
	
	/**
	 * m_bCon holds whether we are inside &lt;con&gt;&lt;/con&gt; or &lt;con&gt;&lt;/con&gt;.
	 */
	private boolean m_bCon = false;
	
	/**
	 * m_bUserFunction holds whether we are inside &lt;userFunction&gt;&lt;/userFunction&gt;.
	 */
	private boolean m_bUserFunction = false;
	
	/**
	 * m_bSum holds whether we are inside &lt;sum&gt;&lt;/sum&gt;.
	 */
	private boolean m_bSum = false;
	
	/**
	 * m_bTerm holds whether we are inside &lt;term&gt;&lt;/term&gt;.
	 */
	private boolean m_bTerm = false;
	
	/**
	 * m_sObjective holds the string of the current objective. 
	 */
	private String m_sObjective= "";
	
	/**
	 * m_sConstraint holds the string of the current constraint. 
	 */
	private String m_sConstraint = "";
	
	/**
	 * m_sUserFunction holds the string of the current userFunction definition. 
	 */
	//private String m_sUserFunction= "";
	
	/**
	 * m_sSumString holds the string of the current summation. 
	 */
	//private String m_sSum = "";
	
	/**
	 * m_bWarning holds whether there is warning message in parsing the XML instance.
	 */
	private boolean m_bWarning = false;
	
	/**
	 * m_bWarning holds whether there is error message in parsing the XML instance.
	 */
	private boolean m_bError = false;
	
	/**
	 * m_bWarning holds whether there is fatal error message in parsing the XML instance.
	 */
	private boolean m_bFatalError = false;
	/**
	 * m_sBufferCon holds the constraint that is sent to OSiLWriter
	 */
	private StringBuffer m_sbBufferCon = new StringBuffer();
	/**
	 * m_sBufferObj holds the objective function that is sent to OSiLWriter
	 */
	private StringBuffer m_sbBufferObj = new StringBuffer();
	/**
	 * m_sbUserF holds the objective function that is sent to OSiLWriter
	 */
	private StringBuffer m_sbUserF = new StringBuffer(); 
	/**
	 * m_sbBufferSum holds the string in a buffer of the current summation. 
	 */
	private StringBuffer m_sbBufferSum  = new StringBuffer();
	/**
	 * m_inumTerms holds the <term> elements inside a <sum> element
	 */
	private int m_iNumTerms;
	/**
	 * m_bisLinearObj is true if we determine that we have a linear objective function
	 */
	private boolean m_bIsLinearObj;
	/**
	 * m_mdobjCoeff is a double array of objective function coefficients
	 */
	private double[] m_mdObjCoeff;
	/**
	 * m_bdeBug is true if we want debugging information
	 */
	private boolean m_bDeBug = false;
	
	
	/**
	 * Constructor
	 */
	public OSmLQueryResultToOSiL(){
		
	}//constructor
	
	/**
	 * Receive notification of a recoverable error.
	 *
	 * <p>This corresponds to the definition of "error" in section 1.2
	 * of the W3C XML 1.0 Recommendation such as a validity constraint.
	 * The implemented behavior is to print the xml style error message
	 * and set the error flag true.</p>
	 *
	 * <p>The SAX parser will continue to provide normal parsing events
	 * after invoking this method: it should still be possible for the
	 * application to process the document through to the end.  If the
	 * application cannot do so, then the parser will report a fatal
	 * error.</p>
	 *
	 * </p>
	 *
	 * @param exception The error information encapsulated in a SAX parse exception.
	 * @exception org.xml.sax.SAXException Any SAX exception, possibly wrapping
	 * another exception.
	 * @see org.xml.sax.SAXParseException
	 * @see org.xml.sax.ErrorHandler#error(org.xml.sax.SAXParseException)
	 */
	public void error(SAXParseException e) throws SAXException {
		super.warning(e);
		String sSaxException = XMLUtil.generateSaxParseExceptionInXML("error", e);
		System.err.println(sSaxException);
		m_bError = true;
	} //error
	
	/**
	 * Receive notification of a non-recoverable error.
	 *
	 * <p>This corresponds to the definition of "fatal error" in
	 * section 1.2 of the W3C XML 1.0 Recommendation, such as a
	 * well-formedness constraint.The implemented behavior is to
	 * print the xml style error message and set the fatalError flag
	 * true.</p>
	 *
	 * <p>The application will assume that the document is unusable
	 * after the parser has invoked this method, and will continue
	 * (if at all) only for the sake of collecting addition error
	 * messages: in fact, SAX parsers are free to stop reporting any
	 * other events once this method has been invoked.</p>
	 *
	 * </p>
	 *
	 * @param exception The error information encapsulated in a SAX parse exception.
	 * @exception org.xml.sax.SAXException Any SAX exception, possibly wrapping
	 * another exception.
	 * @see org.xml.sax.SAXParseException
	 * @see org.xml.sax.ErrorHandler#fatalError(org.xml.sax.SAXParseException)
	 */
	public void fatalError(SAXParseException e) throws SAXException {
		super.warning(e);
		String sSaxException = XMLUtil.generateSaxParseExceptionInXML("fatalError", e);
		System.err.println(sSaxException);
		m_bFatalError = true;
	} //fatalError
	
	/**
	 * Receive notification of a processing instruction.
	 *
	 * <p>The Parser will invoke this method once for each processing
	 * instruction found: note that processing instructions may occur
	 * before or after the main document element.</p>
	 *
	 * <p>The implemented method uses the default behavior from the super
	 * class <code>DefaultHandler</code></p>
	 *
	 * </p>
	 *
	 * @param target The processing instruction target.
	 * @param data The processing instruction data, or null if none was supplied.
	 * The data does not include any whitespace separating it from the target.
	 * @exception org.xml.sax.SAXException Any SAX exception, possibly wrapping another exception.
	 * @see org.xml.sax.ContentHandler#processingInstruction(java.lang.String, java.lang.String)
	 */
	public void processingInstruction(String target, String data) throws
	SAXException {
		super.processingInstruction(target, data);
	} //processingInstruction
	
	/**
	 * Receive notification of ignorable whitespace in element content.
	 *
	 * <p>The implemented method uses the default behavior from the super
	 * class <code>DefaultHandler</code></p>
	 *
	 * </p>
	 *
	 * @param ch The characters from the XML document.
	 * @param start The start position in the array.
	 * @param length The number of characters to read from the array.
	 * @exception org.xml.sax.SAXException Any SAX exception, possibly wrapping another exception.
	 * @see #characters
	 * @see org.xml.sax.ContentHandler#ignorableWhitespace(char[], int, int)
	 */
	public void ignorableWhitespace(char[] ch, int start, int length) throws
	SAXException {
		super.ignorableWhitespace(ch, start, length);
	} //ignorableWhitespace
	
	/**
	 * Receive notification of the beginning of an element.
	 *
	 * The implemented method assumes valid OSmL query result, detects the right elements and write OSiL
	 * or stores necessary information to be later used by the method {@link #endElement endElement}.
	 *
	 * <p>The Parser will invoke this method at the beginning of every
	 * element in the XML document; there will be a corresponding
	 * {@link #endElement endElement} event for every startElement event
	 * (even when the element is empty). All of the element's content will be
	 * reported, in order, before the corresponding endElement
	 * event.</p>
	 *
	 * <p>This event allows up to three name components for each
	 * element:</p>
	 *
	 * <ol>
	 * <li>the Namespace URI;</li>
	 * <li>the local name; and</li>
	 * <li>the qualified (prefixed) name.</li>
	 * </ol>
	 *
	 * </p>
	 *
	 * @param uri The Namespace URI, or the empty string if the element has no Namespace
	 * URI or if Namespace processing is not being performed.
	 * @param localName The local name (without prefix), or the empty string if Namespace
	 * processing is not being performed.
	 * @param qName The qualified name (with prefix), or the empty string if qualified
	 * names are not available.
	 * @param atts The attributes attached to the element.  If there are no attributes,
	 * it shall be an empty Attributes object.
	 * @exception org.xml.sax.SAXException Any SAX exception, possibly wrapping another exception.
	 * @see #endElement
	 * @see org.xml.sax.Attributes
	 * @see org.xml.sax.ContentHandler#startElement(java.lang.String, java.lang.String, java.lang.String, org.xml.sax.Attributes)
	 */
	public void startElement(String namespaceURI, String localName,
			String qualifiedName, Attributes atts) throws SAXException {
		if(localName.equals("row") || localName.equals("con")){
			m_bCon = true;
			m_sConstraint = "";
			//m_sSum = "" ;
			m_sbBufferSum.delete(0, m_sbBufferSum.length() );
			
			if(atts.getLength() == 1) m_sConName = atts.getValue(0);
		}			
		else if (localName.equals("col") || localName.equals("var")){
			m_bVar = true;
			m_iVarIdx = m_iVarIdx + 1;
			int n = atts.getLength();
			String sVarName = "";
			char cDomain = 'C';
			double dVarUb = Double.POSITIVE_INFINITY;
			double dVarLb = 0.0;			
			double dInit = Double.NaN;			
			for (int i = 0; i < n; i++) {
				String sLocalName = atts.getLocalName(i);
				String sValue = atts.getValue(i);
				if (sLocalName.equals("type")) {
					cDomain = sValue.charAt(0);
				}			
				else if (sLocalName.equals("name")) {
					sVarName = sValue;
					/* do some hashing */
					m_sLongVarName = ( String)InfixParser.variableHash.get( sVarName);
					if(m_sLongVarName == null){
						// we are using 0 based indexing on our variable incex
						m_sLongVarName = "variable:" + Integer.toString( InfixParser.variableHash.size() );
						InfixParser.variableHash.put( sVarName, m_sLongVarName);
					}		
				}
				else if (sLocalName.equals("ub")) {
					dVarUb = Double.parseDouble(sValue);
				}
				else if (sLocalName.equals("lb")) {
					dVarLb = Double.parseDouble(sValue);
				}
				else if (sLocalName.equals("init")) {
					dInit = Double.parseDouble(sValue);
				}
			}
			if(sVarName.length() <= 0)
				throw new SAXException("Variable number " + m_iVarIdx + " requires a name!");
			//System.out.println( sVarName);
			m_osilWriter.addVariable(sVarName, dVarLb, dVarUb, cDomain/*, dInit, null*/);
		}
		else if (localName.equals("sum")){
			m_bSum = true;
			//m_sSum = "";
			m_iNumTerms = 0;
			m_sbBufferSum.delete(0, m_sbBufferSum.length() );
		}
		else if (localName.equals("term")){
			m_bTerm = true;
			++m_iNumTerms;
			if( m_iNumTerms > 1 ){
				m_sbBufferSum.append(",");
			}
		}
		else if (localName.equals("obj")){
			m_bObj = true;
			//m_sObjective = "";
			String sAttrName = "";
			for (int i = 0; i < atts.getLength() ; i++) {
				sAttrName = atts.getLocalName(i);
				if (sAttrName.equals("maxOrMin")){
					m_bMaxOrMin = atts.getValue(i).equals("min")?true:false;
				}
				if (sAttrName.equals("name")){
					m_sObjName = atts.getValue(i);
				}
			}
		}
		else if (localName.equals("userFunction")){
			m_bUserFunction = true;
			//m_sUserFunction = "";	
			int n = atts.getLength();
			for (int i = 0; i < n; i++) {
				String sAttrName = atts.getLocalName(i);
				String sValue = atts.getValue(i);
				if (sAttrName.equals("name")) {
					m_sUserFunctionName = sValue;
				}
				else if (sAttrName.equals("numArg")) {
					m_iUserFunctionNumArg = Integer.parseInt(sValue);
				}
			}
		}
		else if (localName.equals("mathProgram")){
			int n = atts.getLength();
			for (int i = 0; i < n; i++) {
				String sAttrName = atts.getLocalName(i);
				String sValue = atts.getValue(i);
				if (sAttrName.equals("source")) {
					m_sSource = sValue;
				}
				else if (sAttrName.equals("description")) {
					m_sDescription = sValue;
				}
				else if (sAttrName.equals("name")) {
					m_sName = sValue;
				}
			}
		}
	}//startElement
	
	/**
	 * Receive notification of the end of an element.
	 *
	 * <p>The SAX parser will invoke this method at the end of every
	 * element in the XML document; there will be a corresponding
	 * {@link #startElement startElement} event for every endElement
	 * event (even when the element is empty).</p>
	 *
	 * <p>For information on the names, see startElement.</p>
	 *
	 * </p>
	 *
	 * @param uri The Namespace URI, or the empty string if the element has no
	 * Namespace URI or if Namespace processing is not being performed.
	 * @param localName The local name (without prefix), or the empty string if
	 * Namespace processing is not being performed.
	 * @param qName The qualified XML 1.0 name (with prefix), or the empty string
	 * if qualified names are not available.
	 * @exception org.xml.sax.SAXException Any SAX exception, possibly wrapping another exception.
	 * @see #startElement
	 * @see org.xml.sax.ContentHandler#endElement(java.lang.String, java.lang.String, java.lang.String)
	 */
	public void endElement(String namespaceURI, String localName,
			String qualifiedName) throws SAXException {
		if (localName.equals("row") || localName.equals("con")){ 
			m_bCon = false;		
			Vector conTokens = new Vector();
			int iStartIdx = -1;
			int iEndIdx = -1;
			double dConLB = Double.NEGATIVE_INFINITY;
			double dConUB = Double.POSITIVE_INFINITY;
			if(m_bDeBug)System.out.println("Constraint =  " + m_sbBufferCon);
			boolean bLookAheadTest = false;
			BufferedReader infixCon = new BufferedReader(new InputStreamReader(IOUtil.stringToInputStream( m_sbBufferCon.toString() )));
			//BufferedReader infixCon = new BufferedReader( m_sbBufferCon );
			try{
				infixCon.mark(1000);
			}
			catch(Exception e){
				throw new SAXException(e.getMessage());
			}
			InfixParser infixParser = new InfixParser(infixCon);
			
			try {
				conTokens = infixParser.lookAhead();
				bLookAheadTest = true;
			} 
			catch (ParseException e) {
				bLookAheadTest = false;
			}
			try {
				if (bLookAheadTest) 
					conTokens = infixParser.parseConstraint1();
				else{
					infixCon.reset();
					infixParser.ReInit(infixCon);  
					infixParser.tokenVector.clear();
					conTokens = infixParser.parseConstraint2();
				}
			} catch (Exception e) {
				throw new SAXException(e.getMessage());
			}
			if( infixParser.rel_op_array_idx == 2){
				String sOP0 = (String)conTokens.get(infixParser.rel_op_array[0]);
				String sOP1 = (String)conTokens.get(infixParser.rel_op_array[1]); 
				if(!sOP0.equals(sOP1) || sOP0.equals("eq") || sOP1.equals("eq")){
					throw new SAXException("Wrong relational operator combination at row " + m_iConIdx + ".");
				}
				else{
					iStartIdx = infixParser.rel_op_array[ 0] + 1;
					iEndIdx = infixParser.rel_op_array[ 1] - 1;
					if(iStartIdx == 3) dConLB = -1 * Double.parseDouble((String)conTokens.get(1));
					else dConLB = Double.parseDouble((String)conTokens.get(0));
					if(iEndIdx == conTokens.size() - 4) dConUB = -1 * Double.parseDouble((String)conTokens.get( conTokens.size() - 1));
					else dConUB = Double.parseDouble((String)conTokens.get( conTokens.size() - 1));
				}
			}
			else if( infixParser.rel_op_array_idx == 1){
				String sOP0 = (String)conTokens.get(infixParser.rel_op_array[0]);
				if( sOP0.equals("eq")){
					dConUB = 0.0;
					dConLB = 0.0;
				}
				if( sOP0.equals("lt") || sOP0.equals("leq")){
					dConUB = 0.0;
					dConLB = Double.NEGATIVE_INFINITY;
				}
				if( sOP0.equals("gt") || sOP0.equals("geq")){
					dConUB = Double.POSITIVE_INFINITY;
					dConLB = 0.0;
				}
				conTokens.set(infixParser.rel_op_array[0], "minus");
				conTokens.insertElementAt("(", infixParser.rel_op_array[0]+1);
				conTokens.add(")");
				iStartIdx = 0;
				iEndIdx = conTokens.size() - 1;        
			}
			m_osilWriter.addConstraint(m_sConName, dConLB, dConUB, 0);
			if(m_bDeBug)System.out.println(conTokens);
			
			m_osilWriter.addNlNode(conTokens, "infix", m_iConIdx, iStartIdx, iEndIdx);
			m_sConName = "";
			m_sbBufferCon.delete(0, m_sbBufferCon.length() );
			m_iConIdx++;
		}
		else if (localName.equals("col") || localName.equals("var")){
			m_bVar = false;
		}
		else if(localName.equals("sum") ){
			m_bSum = false;
			m_bTerm = false;
			if(m_bCon){
				//m_sConstraint = m_sConstraint + m_sSum;
				m_sbBufferCon.append( "sum");
				m_sbBufferCon.append( "(");
				m_sbBufferCon.append( m_sbBufferSum);
				m_sbBufferCon.append( ")");
			}
			else if(m_bObj){
				//m_sObjective = m_sObjective + m_sSum;
				m_sbBufferObj.append( "sum");
				m_sbBufferObj.append( "(");
				m_sbBufferObj.append( m_sbBufferSum);
				m_sbBufferObj.append( ")");
			}
			else if(m_bUserFunction){
				//m_sUserFunction = m_sUserFunction + m_sSum;
				m_sbUserF.append( "sum(");
				m_sbUserF.append( m_sbBufferSum);
				m_sbUserF.append( ")");
			}
			//m_sSum = "";
			m_sbBufferSum.delete(0, m_sbBufferSum.length() );
			
		}
		else if (localName.equals("term")) {
			m_bTerm = false;
		}
		else if (localName.equals("obj")) {
			m_bObj = false;
			Vector objToken = new Vector();
			if(m_bDeBug) System.out.println("The objective function is " + m_sbBufferObj);
			BufferedReader infixObj = new BufferedReader(new InputStreamReader(IOUtil.stringToInputStream( m_sbBufferObj.toString())));
			InfixParser infixParser = new InfixParser(infixObj);
			try{
				objToken = infixParser.start();
			}
			catch( Exception e){
				throw new SAXException(e.getMessage());
			}
			/* temporary code to get the objective coefficients in the linear case*/
			//
			m_bIsLinearObj = true;
			String varTest = "";
			int tokenIdx = 0;
			m_mdObjCoeff = new double[ InfixParser.variableHash.size()];
			if(m_bDeBug)System.out.println( objToken);
			while( tokenIdx < objToken.size()){
				varTest = (String)objToken.get( tokenIdx);
				if(varTest.startsWith("variable") ){
					/* we have a variable, get its index and coefficient*/
					m_mdObjCoeff[ Integer.parseInt( varTest.substring(9, varTest.lastIndexOf(":")))] += Double.parseDouble( varTest.substring(varTest.lastIndexOf(":") + 1, varTest.lastIndexOf("[")));
					++tokenIdx;	
				}
				else if(varTest.startsWith("sum[") || varTest.equals("(") || varTest.equals(")") || varTest.equals("plus") || varTest.equals("minus")){
					++tokenIdx;
				}
				else{
					m_bIsLinearObj = false;
					break;
				}
			}
			/* end of temporary code */
			//
			if(!m_bIsLinearObj){
				m_osilWriter.addObjective(m_sObjName, m_bMaxOrMin, m_dObjConstant, 1.0, null, null);
				System.out.println("The objective function has " + objToken.size() + " tokens");
				m_osilWriter.addNlNode(objToken, "infix", -1, 0, objToken.size()-1);
			}
			//m_sObjective = "";
			m_sbBufferObj.delete(0, m_sbBufferObj.length() );
		}
		else if (localName.equals("userFunction")){
			m_bUserFunction = false;
			Vector userFunctionToken = new Vector();
			BufferedReader infixUserFunction = new BufferedReader(new InputStreamReader(IOUtil.stringToInputStream(m_sbUserF.toString())));
			InfixParser infixParser = new InfixParser(infixUserFunction);
			try{
				userFunctionToken = infixParser.start();
			}
			catch( Exception e){
				throw new SAXException(e.getMessage());
			}
			m_osilWriter.addUserFunction(m_sUserFunctionName, m_iUserFunctionNumArg, userFunctionToken, "infix", 0, userFunctionToken.size()-1);
			m_sUserFunctionName = "";
			m_iUserFunctionNumArg = -1;
		}
	}//endElement
	
	/**
	 * Receive notification of character data.
	 *
	 * <p>The method stores the current characters in a string corresponding to
	 * each of the following element, to be processed later.
	 * <ol>
	 * <li>&lt;obj&gt;</li>
	 * <li>&lt;row&gt;</li>
	 * <li>&lt;sum&gt;</li>
	 * </ol>
	 * </p>
	 *
	 * </p>
	 *
	 * @param ch The characters from the XML document.
	 * @param start The start position in the array.
	 * @param length The number of characters to read from the array.
	 * @exception org.xml.sax.SAXException Any SAX exception, possibly wrapping another exception.
	 * @see #ignorableWhitespace
	 * @see org.xml.sax.Locator
	 * @see org.xml.sax.ContentHandler#characters(char[], int, int)
	 */
	public void characters(char[] ch, int start, int length) throws SAXException {
		if(m_bObj && !m_bSum){
			//m_sObjective = m_sObjective + new String(ch, start, length);
			m_sbBufferObj.append( ch, start, length);
			
		}
		else if(m_bCon && !m_bSum){
			//m_sConstraint = m_sConstraint + new String(ch, start, length);
			m_sbBufferCon.append(ch, start, length);
		}
		else if(m_bUserFunction && !m_bSum){
			//m_sUserFunction = m_sUserFunction + new String(ch, start, length);
			m_sbUserF.append( ch, start, length);
			
		}
		else if(m_bSum){
			//m_sSum = m_sSum + new String(ch, start, length);
			m_sbBufferSum.append(ch, start, length);
		}
	}//characters
	
	/**
	 * Receive notification of the end of a document.
	 *
	 * <p>The SAX parser will invoke this method only once, and it will
	 * be the last method invoked during the parse.  The parser will
	 * not invoke this method until it has either abandoned parsing
	 * (because of an unrecoverable error) or reached the end of
	 * input.</p>
	 *
	 * <p>The implemented method uses the default behavior from the super
	 * class <code>DefaultHandler</code></p>
	 *
	 * </p>
	 *
	 * @exception org.xml.sax.SAXException Any SAX exception, possibly wrapping another exception.
	 * @see #startDocument
	 * @see org.xml.sax.ContentHandler#endDocument()
	 */
	public void endDocument() throws SAXException {
		super.endDocument();
		/* varNames contains the names of variables that were in the constraints and obj, but
		 * NOT in listed in an attribute in the <columns> tags in OSmL
		 */
		for(int i = 0; i < InfixParser.variableNames.size(); i++){
			m_osilWriter.addVariable((String)InfixParser.variableNames.get( i), 0.0, Double.POSITIVE_INFINITY, 'C'/*, Double.NaN, null*/);
		}
		m_osilWriter.setInstanceHeader(m_sName, m_sSource, m_sDescription);
		/* if we had a linear objective function, add the coefficients to column arrays */
		if(m_bIsLinearObj){
			int[] objCoeffIdx = new int[ m_mdObjCoeff.length];
			for(int i = 0; i < m_mdObjCoeff.length; i++){
				objCoeffIdx[ i] = i;
			}
			m_osilWriter.addObjective(m_sObjName, m_bMaxOrMin, m_dObjConstant, 1.0, m_mdObjCoeff, objCoeffIdx);
		}
		InfixParser.variableHash = new java.util.HashMap(2741);
		InfixParser.variableNames = new java.util.Vector();
	} //endDocument 
	
	/**
	 * Parses the query result to OSiL. 
	 *
	 * @param queryResult holds the query result that is returned by an XQuery Engine. 
	 * @return the OSiL instance. 
	 */
	public String parseQueryResult(String queryResult){
		m_osilWriter = new OSiLWriter();
		String sOSiLInstance = "";
		XMLUtil.parseStringUsingSAX(queryResult, this, false);//TODO change false to true
		sOSiLInstance = XMLUtil.writeXMLDocumentToString(m_osilWriter.m_document);
		System.out.println("OSiL Instance Created!!!!!");
		return sOSiLInstance;
	}//parseQueryResult
	
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] args){
		
	}//main
	
}//class
