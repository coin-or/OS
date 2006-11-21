/**
 * @(#)FMLHandler 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.representationparser;

import java.util.Stack;
import java.util.Vector;

import org.optimizationservices.oscommon.util.CommonUtil;
import org.optimizationservices.oscommon.util.XMLUtil;
import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.SAXParseException;
import org.xml.sax.helpers.DefaultHandler;


/**
 *
 * <P>The <code>FMLHandler</code> class is derived from the SAX DefaultHandler
 * class. When the SAX parser encounter the start and end of elements, methods
 * in FMLHandler are called. These methods return values for the element
 * attributes and text content. These data are then used in the arguments for
 * methods such as onConstraints in the class <code>FMLReader</code>.</p>
 *
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.oscommon.representationparser.FMLReader
 * @see org.xml.sax.helpers.DefaultHandler
 * @since OS 1.0
 */
public class FMLHandler
extends DefaultHandler {
	
	/**
	 * m_fmlReader is the parser that registers this <code>FMLHandler</code>
	 * and reads the FML. It is passed in through the <code>FMLHandler
	 * </code> constructor by the <code>FMLReader</code>. <code>FMLHandler
	 * </code> needs to be parser aware because all the optimization-related
	 * callbacks (e.g. onConstraints) that <code>FMLHandler</code> invokes
	 * are, by design, specified inside the <code>FMLReader</code> class,
	 * so that solver developer should not have to deal with the <code>
	 * FMLHandler</code> class.
	 */
	protected FMLReader m_fmlReader = null;
	
	/**
	 * m_vsElement holds a stack of all the encountered elements
	 * that are not ended.
	 *
	 * <p>Elements are stored by their local names in string type.
	 * The first element is the current tag element.</p>
	 */
	protected Stack<String> m_vsElement = new Stack<String>();
	
	/**
	 * m_iMult holds the multiplicity information, one of the two attributes
	 * of an &lt;el&gt; element. It is used to indicate number of
	 * consecutive elements of a common pattern. It is usually combined with
	 * m_iInc in a purpose to compress the nonzero elements and row (or
	 * column) index elements. The information is retrieved from the mult
	 * attribute of the &lt;el&gt; element.
	 */
	protected int m_iMult = 1;
	
	/**
	 * m_iInc holds the increment information, one of the two attributes
	 * of an &lt;el&gt; element. It is used to indicate increment of
	 * consecutive element values. It is usually combined with m_iMult in a
	 * purpose to compress the nonzero elements and row (or column) index
	 * elements. The information is retrieved from the incr attribute of the
	 * &lt;el&gt; element.
	 */
	protected int m_iInc = 0;
	
	/**
	 * m_iMajorGapInAMatrix holds the value of the major gap of a sparse
	 * matrix in AMatrix.
	 */
	protected int m_iMajorGapInAMatrix = 0;
	
	/**
	 * m_iMinorGapInAMatrix holds the value of the minor gap of a sparse
	 * matrix in AMatrix.
	 */
	protected int m_iMinorGapInAMatrix = 0;
	
	/**
	 * m_sNumberRows holds the number of rows, i.e. constraint number.
	 */
	protected String m_sNumberRows = "0";
	
	/**
	 * m_sNumberVars holds the number of columns, i.e. variable number.
	 */
	protected String m_sNumberVars = "0";
	
	/**
	 * m_sEl holds an value in element &lt;el&gt;.
	 */
	protected String m_sEl = "";
	
	/**
	 * m_sObjConstant holds the value of objective function constant.
	 */
	protected String m_sObjConstant = "0";
	
	/**
	 * m_dOptimalValue holds the value of the optimal solution.
	 */
	protected String m_sOptimalValue = "";
	
	/**
	 * m_sMaxOrMin holds whether the objective is of type max or min.
	 */
	protected String m_sMaxOrMin = "";
	
	/**
	 * m_sSource holds the source information of the optimization problem.
	 */
	protected String m_sSource = "";
	
	/**
	 * m_sStatus holds the status message of the optimization solution.
	 */
	protected String m_sStatus = "";
	
	/**
	 * m_sSolverMessage holds the value of solver message.
	 */
	protected String m_sSolverMessage = "";
	
	/**
	 * m_sStatusId holds the information of optimization solution status id
	 * (e.g. infeasible). The information is retrieved from the statusId
	 * attribute of the &lt;status&gt; element.
	 */
	protected String m_sStatusId = "";
	
	/**
	 * m_sDataInfo holds the name of a metadata, which contains information
	 * about optimization data.
	 */
	protected String m_sDataInfo = "";
	
	/**
	 * m_sDataObject holds the value of a metadata, which contains
	 * information about optimization data.
	 */
	protected String m_sDataObject = "";
	
	/**
	 * m_sSolutionInfo holds the name of a metadata, which contains information about
	 * optimization Solution.
	 */
	protected String m_sSolutionInfo = "";
	
	/**
	 * m_sSolutionObject holds the value of a metadata, which contains information about
	 * optimization solution.
	 */
	protected String m_sSolutionObject = "";
	
	/**
	 * m_sIterativeInfo holds the name of a metadata, which contains information about
	 * iterative optimization.
	 */
	protected String m_sIterativeInfo = "";
	
	/**
	 * m_sIterativeObject holds the value of a metadata, which contains information about
	 * iterative optimization.
	 */
	protected String m_sIterativeObject = "";
	
	/**
	 * m_bColumnMajor holds whether the AMatrix holding linear program
	 * data is stored by column. If false, the matrix is stored by row.
	 */
	protected boolean m_bColumnMajorInAMatrix = true;
	
	/**
	 * m_bWarning holds whether there is warning message in parsing the XML instance.
	 */
	protected boolean m_bWarning = false;
	
	/**
	 * m_bWarning holds whether there is error message in parsing the XML instance.
	 */
	protected boolean m_bError = false;
	
	/**
	 * m_bWarning holds whether there is fatal error message in parsing the XML instance.
	 */
	protected boolean m_bFatalError = false;
	
	/**
	 * m_viNumNonzInAMatrix holds the values of the vector element numNonz in AMatrix.
	 * The vector numNonz, if present, stores the number of nonzero elements
	 * in the column (row). If numNonz is not present, then nonz stores the columns
	 * (rows) in matrix order. If the matrix is stored by column (row), rowIdx (colIdx)
	 * is the vector of row (column) indices.
	 */
	protected Vector<Integer> m_viNumNonzInAMatrix = new Vector<Integer>();
	
	/**
	 * m_viPntANonzInAMatrix holds the values of the vector element pntANonz in AMatrix,
	 * which points to the end of a column (row) of nonzero elements in AMatrix.
	 */
	protected Vector<Integer> m_viPntANonzInAMatrix = new Vector<Integer>();
	
	/**
	 * m_viIdx holds the values of the vector element rowIdx or colIdx in AMatrix.
	 * If the matrix is stored by column (row), rowIdx (colIdx) is the vector of
	 * row (column) indices.
	 */
	protected Vector<Integer> m_viIdxInAMatrix = new Vector<Integer>();
	
	/**
	 * m_viPrIdx holds the idx attribute values of variable solutions of
	 * the vector element primalSolution.
	 */
	protected Vector<Integer> m_viPrIdx = new Vector<Integer>();
	
	/**
	 * m_viDuIdx holds the idx attribute values of variable solutions of
	 * the vector element dualSolution.
	 */
	protected Vector<Integer> m_viDuIdx = new Vector<Integer>();
	
	/**
	 * m_vdNz holds the values of the vector element nonz in AMatrix,
	 * which contains nonzero elements.
	 */
	protected Vector<Double> m_vdNzInAMatrix = new Vector<Double>();
	
	/**
	 * m_vdObjCoef holds the values of the objective function coefficients.
	 */
	protected Vector<Double> m_vdObjCoef = new Vector<Double>();
	
	/**
	 * m_vdLb holds the values of lower bounds for the variables.
	 */
	protected Vector<Double> m_vdLb = new Vector<Double>();
	
	/**
	 * m_vdUb holds the values of upper bounds for the variables.
	 */
	protected Vector<Double> m_vdUb = new Vector<Double>();
	
	/**
	 * m_vdLhs holds the values of the lower bounds for the constraints.
	 */
	protected Vector<Double> m_vdLhs = new Vector<Double>();
	
	/**
	 * m_vdRhs holds the values of the upper bounds for the constraints.
	 */
	protected Vector<Double> m_vdRhs = new Vector<Double>();
	
	/**
	 * m_vdPrimal holds the values of primal solutions.
	 */
	protected Vector<Double> m_vdPrimal = new Vector<Double>();
	
	/**
	 * m_vdDual holds the values of dual solutions.
	 */
	protected Vector<Double> m_vdDual = new Vector<Double>();
	
	/**
	 * m_vsColName holds the names of all the columns, i.e. variable names.
	 */
	protected Vector<String> m_vsColName = new Vector<String>();
	
	/**
	 * m_vsRowName holds the names of all the rows, i.e. constraint names.
	 */
	protected Vector<String> m_vsRowName = new Vector<String>();
	
	/**
	 * m_vsPrName holds the names of all the primal solutions, usu. same as
	 * variable names.
	 */
	protected Vector<String> m_vsPrName = new Vector<String>();
	
	/**
	 * m_vsDuName holds the names of all the dual solutions, usu. same as
	 * constraint names.
	 */
	protected Vector<String> m_vsDuName = new Vector<String>();
	
	/**
	 * m_vsOptionName holds the names of all the options.
	 */
	protected Vector<String> m_vsOptionName = new Vector<String>();
	
	/**
	 * m_vsOptionValue holds the values of all the options.
	 */
	protected Vector<String> m_vsOptionValue = new Vector<String>();
	
	/**
	 * m_vcColDomain holds the types of all the variables, (e.g. 'C' for continuous
	 * type, 'I' for integer type, and 'B' for binary type).
	 */
	protected Vector<Character> m_vcColDomain = new Vector<Character>();
	
	/**
	 * constructor of FMLHandler. FMLHandler is aware of the parser that registers it.
	 *
	 * </p>
	 *
	 * @param fmlParser The FML Parser that registers this handler.
	 */
	public FMLHandler(FMLReader fmlParser) {
		m_fmlReader = fmlParser;
	} //constructor
	
	/**
	 * Receive notification of a warning.
	 *
	 * <p>SAX parsers will use this method to report conditions that
	 * are not errors or fatal errors as defined by the XML 1.0
	 * recommendation.  The implemented behavior is to print
	 * the xml style warning message and set the warning flag true.</p>
	 *
	 * <p>The SAX parser will continue to provide normal parsing events
	 * after invoking this method: it should still be possible for the
	 * application to process the document through to the end.</p>
	 *
	 * </p>
	 *
	 * @param e The warning information encapsulated in a SAX parse exception.
	 * @exception org.xml.sax.SAXException Any SAX exception, possibly
	 * wrapping another exception.
	 * @see org.xml.sax.SAXParseException
	 * @see org.xml.sax.ErrorHandler#warning(org.xml.sax.SAXParseException)
	 */
	public void warning(SAXParseException e) throws SAXException {
		super.warning(e);
		String sSaxException = XMLUtil.generateSaxParseExceptionInXML("warning", e);
		System.err.println(sSaxException);
		m_bWarning = true;
	} //warning
	
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
	 * Receive notification of character data.
	 *
	 * <p>The method stores the current characters in a string corresponding to
	 * each of the following element, to be processed later.
	 * <ol>
	 * <li>&lt;el&gt;</li>
	 * <li>&lt;maxOrMin&gt;</li>
	 * <li>&lt;numberRows&gt;</li>
	 * <li>&lt;numberVars&gt;</li>
	 * <li>&lt;objConstant&gt;</li>
	 * <li>&lt;source&gt;</li>
	 * <li>&lt;status&gt;</li>
	 * <li>&lt;optimalValue&gt;</li>
	 * <li>&lt;solverMessage&gt;</li>
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
		String sParent = (String) m_vsElement.elementAt(0);
		String sValue = new String(ch, start, length);
		//the following if checks are by sequence of first appearance of the element definition in FML Schema
		if (sParent.equals("optimalValue")) {
			m_sOptimalValue += sValue;
		}
		else if (sParent.equals("status")) {
			m_sStatus += sValue;
		}
		else if (sParent.equals("solverMessage")) {
			m_sSolverMessage += sValue;
		}
		else if (sParent.equals("el")) {
			m_sEl += sValue;
		}
		else if (sParent.equals("source")) {
			m_sSource += sValue;
		}
		else if (sParent.equals("maxOrMin")) {
			m_sMaxOrMin += sValue;
		}
		else if (sParent.equals("objConstant")) {
			m_sObjConstant += sValue;
		}
		else if (sParent.equals("numberRows")) {
			m_sNumberRows += sValue;
		}
		else if (sParent.equals("numberVars")) {
			m_sNumberVars += sValue;
		}
	} //characters
	
	/**
	 * Receive notification of the beginning of a document.
	 *
	 * <p>The SAX parser will invoke this method only once, before any
	 * other methods in this interface or in {@link org.xml.sax.DTDHandler
	 * DTDHandler} (except for {@link #setDocumentLocator
	 * setDocumentLocator}).</p>
	 *
	 * <p>The implemented method uses the default behavior from the super
	 * class <code>DefaultHandler</code></p>
	 *
	 * </p>
	 *
	 * @exception org.xml.sax.SAXException Any SAX exception, possibly wrapping
	 * another exception.
	 * @see #endDocument
	 * @see org.xml.sax.ContentHandler#startDocument()
	 */
	public void startDocument() throws SAXException {
		super.startDocument();
	} //startDocument
	
	/**
	 * Receive notification of the beginning of an element.
	 *
	 * The implemented method assumes valid FML, detects elements defined
	 * by the schema, and stores necessary information to be later used by
	 * the method {@link #endElement endElement}.
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
	public void startElement(String uri, String localName, String qName,
			Attributes attributes) throws SAXException {
		m_vsElement.add(0, localName);
		//the following "if" checks are by sequence of first appearance of element definition in FML Schema
		//most do nothing (single ;) and are for logical completeness sake and place holders for future development
		if (localName.equals("mathProgram")) {
			;
		}
		else if (localName.equals("sparseVector")) {
			String sParent = (String) m_vsElement.elementAt(1);
			if (sParent.equals("mathProgram")) {
				;
			}
			else if (sParent.equals("metaData")) {
				String sGrandParent = (String) m_vsElement.elementAt(2);
				if (sGrandParent.equals("linearProgramData")) {
					;
				}
				else if (sGrandParent.equals("linearProgramSolution")) {
					;
				}
				else if (sGrandParent.equals("linearProgramIterative")) {
					;
				}
			}
		}
		else if (localName.equals("sparseMatrix")) {
			String sParent = (String) m_vsElement.elementAt(1);
			if (sParent.equals("mathProgram")) {
				;
			}
			else if (sParent.equals("amatrix")) {
				int n = attributes.getLength();
				for (int i = 0; i < n; i++) {
					String sLocalName = attributes.getLocalName(i);
					String sValue = attributes.getValue(i);
					if (sLocalName.equals("majorGap")) {
						m_iMajorGapInAMatrix = Integer.parseInt(sValue);
					}
					else if (sLocalName.equals("minorGap")) {
						m_iMinorGapInAMatrix = Integer.parseInt(sValue);
					}
				}
			}
		}
		else if (localName.equals("linearProgramDescription")) {
			;
		}
		else if (localName.equals("linearProgramData")) {
			;
		}
		else if (localName.equals("linearProgramSolution")) {
			;
		}
		else if (localName.equals("linearProgramIterative")) {
			;
		}
		else if (localName.equals("idx")) {
			//idx's parent is always sparseVector
			String sGrandParent = (String) m_vsElement.elementAt(2);
			if (sGrandParent.equals("mathProgram")) {
				;
			}
			else if (sGrandParent.equals("metaData")) {
				String sGreatGrandParent = (String) m_vsElement.elementAt(3);
				if (sGreatGrandParent.equals("linearProgramData")) {
					;
				}
				else if (sGreatGrandParent.equals("linearProgramSolution")) {
					;
				}
				else if (sGreatGrandParent.equals("linearProgramIterative")) {
					;
				}
			}
		}
		else if (localName.equals("nonz")) {
			String sParent = (String) m_vsElement.elementAt(1);
			if (sParent.equals("sparseVector")) {
				String sGrandParent = (String) m_vsElement.elementAt(2);
				if (sGrandParent.equals("mathProgram")) {
					;
				}
				else if (sGrandParent.equals("metaData")) {
					String sGreatGrandParent = (String) m_vsElement.elementAt(3);
					if (sGreatGrandParent.equals("linearProgramData")) {
						;
					}
					else if (sGreatGrandParent.equals("linearProgramSolution")) {
						;
					}
					else if (sGreatGrandParent.equals("linearProgramIterative")) {
						;
					}
				}
			}
			else if (sParent.equals("sparseMatrix")) {
				String sGrandParent = (String) m_vsElement.elementAt(2);
				if (sGrandParent.equals("mathProgram")) {
					;
				}
				else if (sGrandParent.equals("amatrix")) {
					;
				}
			}
		}
		else if (localName.equals("pntANonz")) {
			//pntANonz's parent is always sparseMatrix
			String sGrandParent = (String) m_vsElement.elementAt(2);
			if (sGrandParent.equals("mathProgram")) {
				;
			}
			else if (sGrandParent.equals("amatrix")) {
				;
			}
		}
		else if (localName.equals("rowIdx")) {
			//rowIdx' parent is always sparseMatrix
			String sGrandParent = (String) m_vsElement.elementAt(2);
			if (sGrandParent.equals("mathProgram")) {
				;
			}
			else if (sGrandParent.equals("amatrix")) {
				m_bColumnMajorInAMatrix = true;
			}
		}
		else if (localName.equals("colIdx")) {
			//colIdx' parent always sparseMatrix
			String sGrandParent = (String) m_vsElement.elementAt(2);
			if (sGrandParent.equals("mathProgram")) {
				;
			}
			else if (sGrandParent.equals("amatrix")) {
				m_bColumnMajorInAMatrix = false;
			}
		}
		else if (localName.equals("numNonz")) {
			//numNonz's parent is always sparseMatrix
			String sGrandParent = (String) m_vsElement.elementAt(2);
			if (sGrandParent.equals("mathProgram")) {
				;
			}
			else if (sGrandParent.equals("amatrix")) {
				;
			}
		}
		else if (localName.equals("rows")) {
			;
		}
		else if (localName.equals("row")) {
			processRow(attributes);
		}
		else if (localName.equals("columns")) {
			;
		}
		else if (localName.equals("col")) {
			processColumn(attributes);
		}
		else if (localName.equals("amatrix")) {
			;
		}
		else if (localName.equals("metaData")) {
			String sParent = (String) m_vsElement.elementAt(1);
			if (sParent.equals("linearProgramData")) {
				int n = attributes.getLength();
				for (int i = 0; i < n; i++) {
					if (attributes.getLocalName(i).equals("info")) {
						m_sDataInfo = attributes.getValue(i);
					}
					else if (attributes.getLocalName(i).equals("object")) {
						m_sDataObject = attributes.getValue(i);
					}
				}
			}
			else if (sParent.equals("linearProgramSolution")) {
				int n = attributes.getLength();
				for (int i = 0; i < n; i++) {
					if (attributes.getLocalName(i).equals("info")) {
						m_sSolutionInfo = attributes.getValue(i);
					}
					else if (attributes.getLocalName(i).equals("object")) {
						m_sSolutionObject = attributes.getValue(i);
					}
				}
			}
			else if (sParent.equals("linearProgramIterative")) {
				int n = attributes.getLength();
				for (int i = 0; i < n; i++) {
					if (attributes.getLocalName(i).equals("info")) {
						m_sIterativeInfo = attributes.getValue(i);
					}
					else if (attributes.getLocalName(i).equals("object")) {
						m_sIterativeObject = attributes.getValue(i);
					}
				}
			}
		}
		else if (localName.equals("primalSolution")) {
			;
		}
		else if (localName.equals("sol")) {
			processSolutionValue(attributes);
		}
		else if (localName.equals("dualSolution")) {
			;
		}
		else if (localName.equals("optimalValue")) {
			;
		}
		else if (localName.equals("status")) {
			int n = attributes.getLength();
			for (int i = 0; i < n; i++) {
				if (attributes.getLocalName(i).equals("statusId")) {
					m_sStatusId = attributes.getValue(i);
				}
			}
		}
		else if (localName.equals("solverMessage")) {
			;
		}
		else if (localName.equals("base64BinaryData")) {
			;
		}
		else if (localName.equals("el")) {
			processEl(attributes);
		}
		else if (localName.equals("source")) {
			;
		}
		else if (localName.equals("maxOrMin")) {
			;
		}
		else if (localName.equals("objConstant")) {
			;
		}
		else if (localName.equals("numberRows")) {
			;
		}
		else if (localName.equals("numberVars")) {
			;
		}
		else if (localName.equals("option")) {
			processOption(attributes);
		}
		else if (localName.equals("newColumn")) {
			;
		}
		else if (localName.equals("newRow")) {
			;
		}
	} //startElement
	
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
	public void endElement(String uri, String localName, String qName) throws
	SAXException {
		//the following "if" checks are by sequence of first appearance of element definition in FML Schema
		//most do nothing (single ;) and are for logical completeness sake and place holders for future development
		if (localName.equals("mathProgram")) {
			;
		}
		else if (localName.equals("sparseVector")) {
			String sParent = (String) m_vsElement.elementAt(1);
			if (sParent.equals("mathProgram")) {
				;
			}
			else if (sParent.equals("metaData")) {
				String sGrandParent = (String) m_vsElement.elementAt(2);
				if (sGrandParent.equals("linearProgramData")) {
					;
				}
				else if (sGrandParent.equals("linearProgramSolution")) {
					;
				}
				else if (sGrandParent.equals("linearProgramIterative")) {
					;
				}
			}
		}
		else if (localName.equals("sparseMatrix")) {
			String sParent = (String) m_vsElement.elementAt(1);
			if (sParent.equals("mathProgram")) {
				;
			}
			else if (sParent.equals("amatrix")) {
				double[] mdNzInAMatrix = CommonUtil.vectorToDblArray(m_vdNzInAMatrix);
				int[] miIdxInAMatrix = CommonUtil.vectorToIntArray(m_viIdxInAMatrix);
				int[] miPntANonzInAMatrix = CommonUtil.vectorToIntArray(
						m_viPntANonzInAMatrix);
				int[] miNumNonzInAMatrix = CommonUtil.vectorToIntArray(
						m_viNumNonzInAMatrix);
				if (m_fmlReader.onAMatrix(m_bColumnMajorInAMatrix, mdNzInAMatrix,
						miIdxInAMatrix, miPntANonzInAMatrix, miNumNonzInAMatrix)) {
					m_vdNzInAMatrix.clear();
					m_viIdxInAMatrix.clear();
					m_viPntANonzInAMatrix.clear();
					m_viNumNonzInAMatrix.clear();
				}
			}
		}
		else if (localName.equals("linearProgramDescription")) {
			m_fmlReader.onDescription(m_sSource, Integer.parseInt(m_sNumberVars), Integer.parseInt(m_sNumberRows));
			String[] msOptionName = CommonUtil.vectorToStrArray(m_vsOptionName);
			String[] msOptionValue = CommonUtil.vectorToStrArray(m_vsOptionValue);
			if (m_fmlReader.onOption(msOptionName, msOptionValue)) {
				m_vsOptionName.clear();
				m_vsOptionValue.clear();
			}
		}
		else if (localName.equals("linearProgramData")) {
			;
		}
		else if (localName.equals("linearProgramSolution")) {
			m_fmlReader.onSolution(m_sStatusId, m_sStatus, m_sSolverMessage, Double.parseDouble(m_sOptimalValue));
		}
		else if (localName.equals("linearProgramIterative")) {
			;
		}
		else if (localName.equals("idx")) {
			//idx's parent is always sparseVector
			String sGrandParent = (String) m_vsElement.elementAt(2);
			if (sGrandParent.equals("mathProgram")) {
				;
			}
			else if (sGrandParent.equals("metaData")) {
				String sGreatGrandParent = (String) m_vsElement.elementAt(3);
				if (sGreatGrandParent.equals("linearProgramData")) {
					;
				}
				else if (sGreatGrandParent.equals("linearProgramSolution")) {
					;
				}
				else if (sGreatGrandParent.equals("linearProgramIterative")) {
					;
				}
			}
		}
		else if (localName.equals("nonz")) {
			String sParent = (String) m_vsElement.elementAt(1);
			if (sParent.equals("sparseVector")) {
				String sGrandParent = (String) m_vsElement.elementAt(2);
				if (sGrandParent.equals("mathProgram")) {
					;
				}
				else if (sGrandParent.equals("metaData")) {
					String sGreatGrandParent = (String) m_vsElement.elementAt(3);
					if (sGreatGrandParent.equals("linearProgramData")) {
						;
					}
					else if (sGreatGrandParent.equals("linearProgramSolution")) {
						;
					}
					else if (sGreatGrandParent.equals("linearProgramIterative")) {
						;
					}
				}
			}
			else if (sParent.equals("sparseMatrix")) {
				String sGrandParent = (String) m_vsElement.elementAt(2);
				if (sGrandParent.equals("mathProgram")) {
					;
				}
				else if (sGrandParent.equals("amatrix")) {
					;
				}
			}
		}
		else if (localName.equals("pntANonz")) {
			//pntANonz's parent is always sparseMatrix
			String sGrandParent = (String) m_vsElement.elementAt(2);
			if (sGrandParent.equals("mathProgram")) {
				;
			}
			else if (sGrandParent.equals("amatrix")) {
				;
			}
		}
		else if (localName.equals("rowIdx")) {
			//rowIdx' parent is always sparseMatrix
			String sGrandParent = (String) m_vsElement.elementAt(2);
			if (sGrandParent.equals("mathProgram")) {
				;
			}
			else if (sGrandParent.equals("amatrix")) {
				;
			}
		}
		else if (localName.equals("colIdx")) {
			//colIdx' parent is always sparseMatrix
			String sGrandParent = (String) m_vsElement.elementAt(2);
			if (sGrandParent.equals("mathProgram")) {
				;
			}
			else if (sGrandParent.equals("amatrix")) {
				;
			}
		}
		else if (localName.equals("numNonz")) {
			//numNonz's parent is always sparseMatrix
			String sGrandParent = (String) m_vsElement.elementAt(2);
			if (sGrandParent.equals("mathProgram")) {
				;
			}
			else if (sGrandParent.equals("amatrix")) {
				;
			}
		}
		else if (localName.equals("rows")) {
			String[] msRowName = CommonUtil.vectorToStrArray(m_vsRowName);
			double[] mdLhs = CommonUtil.vectorToDblArray(m_vdLhs);
			double[] mdRhs = CommonUtil.vectorToDblArray(m_vdRhs);
			if (m_fmlReader.onConstraints(msRowName, mdLhs, mdRhs)) {
				m_vsRowName.clear();
				m_vdLhs.clear();
				m_vdRhs.clear();
			}
		}
		else if (localName.equals("row")) {
			;
		}
		else if (localName.equals("columns")) {
			boolean bIsMin = m_sMaxOrMin.equals("min") ? true : false;
			double[] mdObjCoef = CommonUtil.vectorToDblArray(m_vdObjCoef);
			if (m_fmlReader.onObjective(bIsMin, Double.parseDouble(m_sObjConstant), mdObjCoef)) {
				m_vdObjCoef.clear();
			}
			String[] msColName = CommonUtil.vectorToStrArray(m_vsColName);
			double[] mdLb = CommonUtil.vectorToDblArray(m_vdLb);
			double[] mdUb = CommonUtil.vectorToDblArray(m_vdUb);
			char[] mcColDomain = CommonUtil.vectorToChaArray(m_vcColDomain);
			if (m_fmlReader.onVariables(msColName, mdLb, mdUb, mcColDomain)) {
				m_vsColName.clear();
				m_vdLb.clear();
				m_vdUb.clear();
				m_vcColDomain.clear();
			}
		}
		else if (localName.equals("col")) {
			;
		}
		else if (localName.equals("amatrix")) {
			;
		}
		else if (localName.equals("metaData")) {
			String sParent = (String) m_vsElement.elementAt(1);
			if (sParent.equals("linearProgramData")) {
				;
			}
			else if (sParent.equals("linearProgramSolution")) {
				;
			}
			else if (sParent.equals("linearProgramIterative")) {
				;
			}
		}
		else if (localName.equals("primalSolution")) {
			String[] msPrName = CommonUtil.vectorToStrArray(m_vsPrName);
			double[] mdPrimal = CommonUtil.vectorToDblArray(m_vdPrimal);
			int[] miPrIdx = CommonUtil.vectorToIntArray(m_viPrIdx);
			if (m_fmlReader.onPrimalSolution(msPrName, mdPrimal, miPrIdx)) {
				m_vsPrName.clear();
				m_vdPrimal.clear();
				m_viPrIdx.clear();
			}
		}
		else if (localName.equals("sol")) {
			;
		}
		else if (localName.equals("dualSolution")) {
			String[] msDuName = CommonUtil.vectorToStrArray(m_vsDuName);
			double[] mdDual = CommonUtil.vectorToDblArray(m_vdDual);
			int[] miDuIdx = CommonUtil.vectorToIntArray(m_viDuIdx);
			if (m_fmlReader.onDualSolution(msDuName, mdDual, miDuIdx)) {
				m_vsDuName.clear();
				m_vdDual.clear();
				m_viDuIdx.clear();
			}
		}
		else if (localName.equals("optimalValue")) {
			;
		}
		else if (localName.equals("status")) {
			;
		}
		else if (localName.equals("solverMessage")) {
			;
		}
		else if (localName.equals("base64BinaryData")) {
			;
		}
		else if (localName.equals("el")) {
			String sParent = (String) m_vsElement.elementAt(1);
			if (sParent.equals("idx")) {
				//idx's parent is always sparseVector
				String sGreatGrandParent = (String) m_vsElement.elementAt(3);
				if (sGreatGrandParent.equals("mathProgram")) {
					;
				}
				else if (sGreatGrandParent.equals("metaData")) {
					String sGreatGreatGrandParent = (String) m_vsElement.elementAt(4);
					if (sGreatGreatGrandParent.equals("linearProgramData")) {
						;
					}
					else if (sGreatGreatGrandParent.equals("linearProgramSolution")) {
						;
					}
					else if (sGreatGreatGrandParent.equals("linearProgramIterative")) {
						;
					}
				}
			}
			else if (sParent.equals("numNonz")) {
				//numNonz's parent is always sparseMatrix
				String sGreatGrandParent = (String) m_vsElement.elementAt(3);
				if (sGreatGrandParent.equals("mathProgram")) {
					;
				}
				else if (sGreatGrandParent.equals("amatrix")) {
					for (int i = 0; i < m_iMult; i++) {
						m_viNumNonzInAMatrix.add(new Integer( Integer.parseInt(m_sEl) + m_iInc * i));
					}
				}
			}
			else if (sParent.equals("pntANonz")) {
				//pntANonz's parent is always sparseMatrix
				String sGreatGrandParent = (String) m_vsElement.elementAt(3);
				if (sGreatGrandParent.equals("mathProgram")) {
					;
				}
				else if (sGreatGrandParent.equals("amatrix")) {
					for (int i = 0; i < m_iMult; i++) {
						m_viPntANonzInAMatrix.add(new Integer( Integer.parseInt(m_sEl) + m_iInc * i));
					}
				}
			}
			else if (sParent.equals("rowIdx")) {
				//rowIdx' parent is always sparseMatrix
				String sGreatGrandParent = (String) m_vsElement.elementAt(3);
				if (sGreatGrandParent.equals("mathProgram")) {
					;
				}
				else if (sGreatGrandParent.equals("amatrix")) {
					for (int i = 0; i < m_iMult; i++) {
						m_viIdxInAMatrix.add(new Integer( Integer.parseInt(m_sEl) + m_iInc * i));
					}
				}
			}
			else if (sParent.equals("colIdx")) {
				//colIdx' parent is always sparseMatrix
				String sGreatGrandParent = (String) m_vsElement.elementAt(3);
				if (sGreatGrandParent.equals("mathProgram")) {
					;
				}
				else if (sGreatGrandParent.equals("amatrix")) {
					for (int i = 0; i < m_iMult; i++) {
						m_viIdxInAMatrix.add(new Integer( Integer.parseInt(m_sEl) + m_iInc * i));
					}
				}
			}
			else if (sParent.equals("nonz")) {
				String sGrandParent = (String) m_vsElement.elementAt(2);
				if (sGrandParent.equals("sparseVector")) {
					String sGreatGrandParent = (String) m_vsElement.elementAt(3);
					if (sGreatGrandParent.equals("mathProgram")) {
						;
					}
					else if (sGreatGrandParent.equals("metaData")) {
						String sGreatGreatGrandParent = (String) m_vsElement.elementAt(4);
						if (sGreatGreatGrandParent.equals("linearProgramData")) {
							;
						}
						else if (sGreatGreatGrandParent.equals("linearProgramSolution")) {
							;
						}
						else if (sGreatGreatGrandParent.equals("linearProgramIterative")) {
							;
						}
					}
				}
				else if (sGrandParent.equals("sparseMatrix")) {
					String sGreatGrandParent = (String) m_vsElement.elementAt(3);
					if (sGreatGrandParent.equals("mathProgram")) {
						;
					}
					else if (sGreatGrandParent.equals("amatrix")) {
						for (int i = 0; i < m_iMult; i++) {
							m_vdNzInAMatrix.add(new Double(Double.parseDouble(m_sEl) + m_iInc * i));
						}
					}
				}
			}
			else {
			}
			m_sEl = "";
			m_iMult = 1;
			m_iInc = 0;
		}
		else if (localName.equals("source")) {
			
		}
		else if (localName.equals("maxOrMin")) {
			;
		}
		else if (localName.equals("objConstant")) {
			;
		}
		else if (localName.equals("numberRows")) {
			;
		}
		else if (localName.equals("numberVars")) {
			;
		}
		else if (localName.equals("option")) {
			;
		}
		else if (localName.equals("newColumn")) {
			;
		}
		else if (localName.equals("newRow")) {
			;
		}
		m_vsElement.remove(0);
	} //endElement
	
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
	} //endDocument
	
	/**
	 * This method is called when a &lt;row&gt; element is encountered,
	 * which corresponds to one variable, . It looks at all the
	 * attributes of the this element, and appends the element's attribute
	 * information to the corresponding variable related vectors (e.g. variable
	 * names) to be processed later.
	 *
	 * </p>
	 *
	 * @param attributes Attributes of the &lt;row&gt element, which corresponds to one variable.
	 */
	protected void processRow(Attributes attributes) {
		int n = attributes.getLength();
		String sRowName = "";
		double dLhs = Double.NEGATIVE_INFINITY;
		double dRhs = Double.POSITIVE_INFINITY;
		for (int i = 0; i < n; i++) {
			String sLocalName = attributes.getLocalName(i);
			String sValue = attributes.getValue(i);
			if (sLocalName.equals("rowName")) {
				sRowName = sValue;
			}
			else if (sLocalName.equals("rowLB")) {
				dLhs = Double.parseDouble(sValue);
			}
			else if (sLocalName.equals("rowUB")) {
				dRhs = Double.parseDouble(sValue);
			}
			else if (sLocalName.equals("mult")) {
				m_iMult = Integer.parseInt(sValue);
			}
		}
		for (int i = 0; i < m_iMult; i++) {
			m_vsRowName.add(sRowName);
			m_vdLhs.add(new Double(dLhs));
			m_vdRhs.add(new Double(dRhs));
		}
		m_iMult = 1;
	} //processRow
	
	/**
	 * This method is called when a &lt;col&gt; element is encountered,
	 * which corresponds to one constraint, . It looks at all the
	 * attributes of the this element, and appends the element's attribute
	 * values to the corresponding constraint related vectors (e.g.
	 * constraint names) to be processed later.
	 *
	 * </p>
	 *
	 * @param attributes Attributes of the &lt;col&gt element, which corresponds to one constraint.
	 */
	protected void processColumn(Attributes attributes) {
		int n = attributes.getLength();
		double dObjCoef = 0.0;
		String sColName = "";
		char cDomain = 'C';
		double dColUb = Double.POSITIVE_INFINITY;
		double dColLb = 0.0;
		for (int i = 0; i < n; i++) {
			String sLocalName = attributes.getLocalName(i);
			String sValue = attributes.getValue(i);
			if (sLocalName.equals("objVal")) {
				dObjCoef = Double.parseDouble(sValue);
			}
			else if (sLocalName.equals("colName")) {
				sColName = sValue;
			}
			else if (sLocalName.equals("colType")) {
				cDomain = sValue.charAt(0);
			}
			else if (sLocalName.equals("colUB")) {
				dColUb = Double.parseDouble(sValue);
			}
			else if (sLocalName.equals("colLB")) {
				dColLb = Double.parseDouble(sValue);
			}
			else if (sLocalName.equals("mult")) {
				m_iMult = Integer.parseInt(sValue);
			}
		}
		for (int i = 0; i < m_iMult; i++) {
			m_vdObjCoef.add(new Double(dObjCoef));
			m_vsColName.add(sColName);
			m_vcColDomain.add(new Character(cDomain));
			m_vdUb.add(new Double(dColUb));
			m_vdLb.add(new Double(dColLb));
		}
		m_iMult = 1;
	} //processColumn
	
	/**
	 * This method is called when an &lt;el&gt; element is encountered, It
	 * looks at the mult and incr attributes of the this element, and
	 * stores them to the corresponding variables to be processed later.
	 *
	 * </p>
	 *
	 * @param attributes Attributes of an &lt;el&gt element.
	 */
	protected void processEl(Attributes attributes) {
		int n = attributes.getLength();
		for (int i = 0; i < n; i++) {
			String sLocalName = attributes.getLocalName(i);
			String sValue = attributes.getValue(i);
			if (sLocalName.equals("mult")) {
				m_iMult = Integer.parseInt(sValue);
			}
			else if (sLocalName.equals("incr")) {
				m_iInc = Integer.parseInt(sValue);
			}
		}
	} //processEl
	
	/**
	 * This method is called when a &lt;sol&gt; element is encountered,
	 * which corresponds to one variable solution, . It looks at all the
	 * attributes of the this element, and appends the element's attribute
	 * values to the corresponding variable solution related vectors
	 * (e.g. solution names) to be processed later.
	 *
	 * </p>
	 *
	 * @param attributes Attributes of the &lt;sol&gt element, which corresponds to
	 * one variable solution.
	 */
	protected void processSolutionValue(Attributes attributes) {
		String sParent = (String) m_vsElement.elementAt(1);
		if (sParent.equals("primalSolution")) {
			int n = attributes.getLength();
			for (int i = 0; i < n; i++) {
				String sLocalName = attributes.getLocalName(i);
				String sValue = attributes.getValue(i);
				if (sLocalName.equals("idx")) {
					m_viPrIdx.add(new Integer(sValue));
				}
				else if (sLocalName.equals("name")) {
					m_vsPrName.add(sValue);
				}
				else if (sLocalName.equals("val")) {
					m_vdPrimal.add(new Double(sValue));
				}
			}
		}
		else if (sParent.equals("dualSolution")) {
			int n = attributes.getLength();
			for (int i = 0; i < n; i++) {
				String sLocalName = attributes.getLocalName(i);
				String sValue = attributes.getValue(i);
				if (sLocalName.equals("idx")) {
					m_viDuIdx.add(new Integer(sValue));
				}
				else if (sLocalName.equals("name")) {
					m_vsDuName.add(sValue);
				}
				else if (sLocalName.equals("val")) {
					m_vdDual.add(new Double(sValue));
				}
			}
		}
	} //processSolutionValue
	
	/**
	 * This method is called when a &lt;option&gt; element is encountered,
	 * which corresponds to one solver option. It looks at all the
	 * attributes of the this element, and appends the element's attribute
	 * values to the corresponding solver option related vectors
	 * (e.g. option names) to be processed later.
	 *
	 * </p>
	 *
	 * @param attributes Attributes of an &lt;option&gt element.
	 */
	protected void processOption(Attributes attributes) {
		int n = attributes.getLength();
		for (int i = 0; i < n; i++) {
			String sLocalName = attributes.getLocalName(i);
			String sValue = attributes.getValue(i);
			if (sLocalName.equals("name")) {
				m_vsOptionName.add(sValue);
			}
			else if (sLocalName.equals("value")) {
				m_vsOptionValue.add(sValue);
			}
		}
	}//processOption
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv) {
		String fmlString = "xml/lpfml/lpparinc.xml";
		FMLHandler fmlHandler = new FMLHandler(new FMLReader());
		boolean bRead =  XMLUtil.parseFileUsingSAX(fmlString, fmlHandler, false);
		if(fmlHandler.m_bError || fmlHandler.m_bFatalError) bRead = false;
		System.out.println(bRead);
	} //main
	
} //class FMLHandler
