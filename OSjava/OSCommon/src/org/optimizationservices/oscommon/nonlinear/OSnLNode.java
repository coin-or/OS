/**
 * @(#)OSnLNode 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.nonlinear;

import it.unimi.dsi.fastutil.ints.Int2DoubleOpenHashMap;
import it.unimi.dsi.fastutil.ints.IntOpenHashSet;
import it.unimi.dsi.fastutil.objects.Object2DoubleOpenHashMap;

import java.util.HashSet;
import java.util.Vector;

import org.w3c.dom.Document;
import org.w3c.dom.Element;

/**
 *
 * <P>The <code>OSnLNode</code> class represents a node in an expression tree for a nonlinear function
 * (linear ones being special cases) and provide convenience methods to process the node. It is an abstract
 * (or generic) node from which we derive concrete operator nodes.</p>
 *
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.oscommon.nonlinear.OSExpressionTree;
 * @since OS 1.0
 */
public abstract class OSnLNode{
	protected static String[] msNodeNames = {
			/*1--*/"plus", "sum", "minus", "negate", "times", "divide",
			"quotient", "rem", "power", "product",
			/*2--*/"abs", "floor", "ceiling", "percent", "square", "squareRoot", "ln", "log", "log10", "exp",
			"factorial", "combination", "permutation", "gcd", "lcm", "roundToInt", "round", "truncate", "sign", "rand","gammaFn", "gammaLn",
			/*3--*/"sin", "cos", "tan", "arcsin", "arccos", "arctan", "sinh", "cosh", "tanh", "arcsinh", "arccosh", "arctanh",
			"cot", "coth", "arccot", "arccoth", "sec", "sech", "arcsec", "arcsech", "csc", "csch", "arccsc", "arccsch",
			/*4--*/"mean", "geometricMean", "harmonicMean", "trimMean", "count", "median", "firstQuartile", "thirdQuartile", "mode", "min", "max",
			"percentile", "large", "small", "range", "interQuantileRange", "absdev", "stddev", "variance", "cv", "skewness", "kurtosis",
			"covariance", "correlation", "pearsonCorrelation", "rankCorrelation", "autoCorrelation1", "autoCorrelation", "npv", "irr", 
			/*"empiricalDiscreteDist", "empiricalDiscreteCum", */"discreteUniformDist", "discreteUniformCum", "discreteUniformInv",
			"bernoulliDist", "bernoulliCum", "bernoulliInv", "binomialDist", "binomialCum", "binomialInv", "multinomialDist", "multinomialCum", "multinomialInv",
			"hypergeometricDist", "hypergeometricCum", "hypergeometricInv", "poissonDist", "poissonCum", "poissonInv",
			"geometricDist", "geometricCum", "geometricInv", "negativeBinomialDist", "negativeBinomialCum", "negativeBinomialInv",
			/*"empiricalContinousDist", "empiricalContinuousCum",*/ "uniformDist", "uniformCum", "uniformInv",
			"normalDist", "normalCum", "normalInv", "stdNormalDist", "stdNormalCum", "stdNormalInv", "bivariateNormalDist", "bivariateNormalCum",
			"exponentialDist", "exponentialCum", "exponentialInv", "weibullDist", "weibullCum", "weibullInv", "erlangDist", "erlangCum", "erlangInv",
			"gammaDist", "gammaCum", "gammaInv", "betaDist", "betaCum", "betaInv", "betaGeneralDist", "betaGeneralCum", "betaGeneralInv",
			"lognormalDist", "lognormalCum", "lognormalInv", "cauchyDist", "cauchyCum", "cauchyInv", "tDist", "tCum", "tInv",
			"chiSquareDist", "chiSquareCum", "chiSquareInv", "fDist", "fCum", "fInv", "logisticDist", "logisticCum", "logisticInv",
			"logLogisticDist", "logLogisticCum", "logLogisticInv", "logarithmicDist", "logarithmicCum", "logarithmicInv",
			"paretoDist", "paretoCum", "paretoDist", "rayleighDist", "rayleighCum", "rayleighInv", "pertDist", "pertCum", "pertDist",
			"triangularDist", "triangularCum", "triangularInv","unitNormalLinearLoss",
			/*5--*/"number", "identifier", "PI", "E", "INF", "EPS", "TRUE", "FALSE", "EULERGAMMA", "NAN",
			/*6--*/"variable", "objective", "constraint", "parameter", "randomVariable",
			/*7--*/"if", "lt", "leq", "gt", "geq", "eq", "neq", "and", "or", "xor", "implies", "not",
			"forAll", "exists", "logicCount", "allDiff", /*"allDisjoint",*/ "atMost", "atLeast", "exactly", 
			"inSet", "inRealSet", "inPositiveRealSet", "inNonnegativeRealSet", "inIntegerSet", "inPositiveIntegerSet","inNonnegativeIntegerSet",
			/*8--*/
			/*9--*/"qTerm", "quadratic", "sim", "simInput", "simOutput", "userF", "arg", "xPath", "xPathIndex",
			"nodeRef", "arcRef", "complements", /*"prob",*/
	};

	protected static String[] m_msNodeSymbols = {
			/*1--*/"plus", "sum", "minus", "negate", "times", "divide",
			"quotient", "rem", "power", "product",
			/*2--*/"abs", "floor", "ceiling", "percent", "square", "squareRoot", "ln", "log", "log10", "exp",
			"factorial", "combination", "permutation", "gcd", "lcm", "roundToInt", "round", "truncate", "sign", "rand","gammaFn", "gammaLn",
			/*3--*/"sin", "cos", "tan", "arcsin", "arccos", "arctan", "sinh", "cosh", "tanh", "arcsinh", "arccosh", "arctanh",
			"cot", "coth", "arccot", "arccoth", "sec", "sech", "arcsec", "arcsech", "csc", "csch", "arccsc", "arccsch",
			/*4--*/"mean", "geometricMean", "harmonicMean", "trimMean", "count", "median", "firstQuartile", "thirdQuartile", "mode", "min", "max",
			"percentile", "large", "small", "range", "interQuantileRange", "absdev", "stddev", "variance", "cv", "skewness", "kurtosis",
			"covariance", "correlation", "pearsonCorrelation", "rankCorrelation", "autoCorrelation1", "autoCorrelation", "npv", "irr", 
			/*"empiricalDiscreteDist", "empiricalDiscreteCum", */"discreteUniformDist", "discreteUniformCum", "discreteUniformInv",
			"bernoulliDist", "bernoulliCum", "bernoulliInv", "binomialDist", "binomialCum", "binomialInv", "multinomialDist", "multinomialCum", "multinomialInv",
			"hypergeometricDist", "hypergeometricCum", "hypergeometricInv", "poissonDist", "poissonCum", "poissonInv",
			"geometricDist", "geometricCum", "geometricInv", "negativeBinomialDist", "negativeBinomialCum", "negativeBinomialInv",
			/*"empiricalContinousDist", "empiricalContinuousCum", */"uniformDist", "uniformCum", "uniformInv",
			"normalDist", "normalCum", "normalInv", "stdNormalDist", "stdNormalCum", "stdNormalInv", "bivariateNormalDist", "bivariateNormalCum",
			"exponentialDist", "exponentialCum", "exponentialInv", "weibullDist", "weibullCum", "weibullInv", "erlangDist", "erlangCum", "erlangInv",
			"gammaDist", "gammaCum", "gammaInv", "betaDist", "betaCum", "betaInv", "betaGeneralDist", "betaGeneralCum", "betaGeneralInv",
			"lognormalDist", "lognormalCum", "lognormalInv", "cauchyDist", "cauchyCum", "cauchyInv", "tDist", "tCum", "tInv",
			"chiSquareDist", "chiSquareCum", "chiSquareInv", "fDist", "fCum", "fInv", "logisticDist", "logisticCum", "logisticInv",
			"logLogisticDist", "logLogisticCum", "logLogisticInv", "logarithmicDist", "logarithmicCum", "logarithmicInv",
			"paretoDist", "paretoCum", "paretoDist", "rayleighDist", "rayleighCum", "rayleighInv", "pertDist", "pertCum", "pertInv",
			"triangularDist", "triangularCum", "triangularInv", "unitNormalLinearLoss",
			/*5--*/"number", "identifier", "PI", "E", "INF", "EPS", "TRUE", "FALSE", "EULERGAMMA", "NAN",
			/*6--*/"X", "objective", "constraint", "parameter", "randomVariable",
			/*7--*/"if", "lt", "leq", "gt", "geq", "eq", "neq", "and", "or", "xor", "implies", "not",
			"forAll", "exists", "logicCount", "allDiff", /*"allDisjoint",*/ "atMost", "atLeast", "exactly",
			"inSet", "inRealSet", "inPositiveRealSet", "inNonnegativeRealSet", "inIntegerSet", "inPositiveIntegerSet", "inNonnegativeIntegerSet",
			/*8--*/
			/*9--*/"quadratic", "qTerm", "sim", "simInput", "simOutput", "userF", "arg", "xPath", "xPathIndex",
			"nodeRef", "arcRef", "complements", /*"prob",*/
	};

	protected static int[] m_miNodeIndexes = {
			/*1--*/1001, 1002, 1003, 1004, 1005, 1006,
			1007, 1008, 1009, 1010,
			/*2--*/2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010,
			2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018, 2019, 2020, 2021, 2022,
			/*3--*/3001, 3002, 3003, 3004, 3005, 3006, 3007, 3008, 3009, 3010, 3011, 3012,
			3013, 3014, 3015, 3016, 3017, 3018, 3019, 3020, 3021, 3022, 3023, 3024,
			/*4--*/4001, 4002, 4003, 4004, 4005, 4006, 4007, 4008, 4009, 4010, 4011,
			4012, 4013, 4014, 4015, 4016, 4017, 4018, 4019, 4020, 4021, 4022,
			4023, 4024, 4025, 4026, 4027, 4028, 4029, 4030,
			/*4101, 4102, */4111, 4112, 4113,
			4121, 4122, 4123, 4131, 4132, 4133, 4141, 4142, 4143,
			4151, 4152, 4153, 4161, 4162, 4163,
			4171, 4172, 4173, 4181, 4182, 4183,
			/*4401, 4402,*/ 4411, 4412, 4413,
			4421, 4422, 4423, 4431, 4432, 4433, 4441, 4442,
			4451, 4452, 4453, 4461, 4462, 4463, 4471, 4472, 4473,
			4481, 4482, 4483, 4491, 4492, 4493, 4501, 4502, 4503,
			4511, 4512, 4513, 4521, 4522, 4523, 4531, 4532, 4533,
			4541, 4542, 4543, 4551, 4552, 4553, 4561, 4562, 4563,
			4571, 4572, 4573, 4581, 4582, 4583,
			4591, 4592, 4593, 4601, 4602, 4603, 4611, 4612, 4613,
			4621, 4622, 4623, 4624,
			/*5--*/5001, 5002, 5003, 5004, 5005, 5006, 5007, 5008, 5009, 5010,
			/*6--*/6001, 6002, 6003, 6004, 6005,
			/*7--*/7001, 7002, 7003, 7004, 7005, 7006, 7007, 7008, 7009, 7010, 7011, 7012,
			7013, 7014, 7015, 7016, /*7017,*/ 7018, 7019, 7020, 
			7021, 7022, 7023, 7024, 7025, 7026, 7027,
			/*8--*/
			/*9--*/9001, 9002, 9003, 9004, 9005, 9006, 9007, 9008, 9009,
			9010, 9011, 9012, /*9013,*/
	};

	protected static int[] m_miNodeTypes = {
			/*1--*/2, -1, 2, 1, 2, 2,
			2, 2, 2, -1,
			/*2--*/1, 1, 1, 1, 1, 1, 1, 2, 1, 1,
			1, 2, 2, -1, -1, 1, 2, 2, 1, 1, 1, 1,
			/*3--*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			/*4--*/-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1,
			/*-1, -1, */2, 2, 2,
			2, 2, 2, 3, 3, 3, -1, -1, -1,
			4, 4, 4, 2, 2, 2,
			2, 2, 2, 3, 3, 3,
			/*-1, -1,*/ 3, 3, 3,
			3, 3, 3, 1, 1, 1, 7, 7,
			2, 2, 2, 4, 4, 4, 3, 3, 3,
			3, 3, 3, 3, 3, 3, 5, 5, 5,
			3, 3, 3, 3, 3, 3, 2, 2, 2,
			2, 2, 2, 3, 3, 3, 3, 3, 3,
			3, 3, 3, 3, 3, 3,
			3, 3, 3, 2, 2, 2, 4, 4, 4,
			4, 4, 4, 1,
			/*5--*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			/*6--*/-1, -1, -1, 0, 0,
			/*7--*/3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
			-1, -1, -1, -1, /*-1,*/ -1, -1, -1, 
			-1, 1, 1, 1, 1, 1, 1
			/*8--*/
			/*9--*/-1, -1, -1, -1, -1, -1, 0, -1, -1,
			-1, -1, 2, /*1,*/
	};


	/**
	 * m_dDelta holds the delta value used to calulate derivatives with numerical finite difference method.
	 */
	protected static final double m_dDelta = 10e-8;

	/**
	 * m_dIntTol holds the integer tolerance value to numerically decide if a value is integer or not.
	 */
	protected static final double m_dIntTol = 10e-8;
	/**
	 * m_dTRUE holds the double value representation of the boolean TRUE.
	 */

	protected static final double m_dTRUE = 1.847363582443103;

	/**
	 * m_dFALSE holds the double value representation of the boolean FALSE.
	 */
	protected static final double m_dFALSE = -m_dTRUE;

	/**
	 * m_sDelimiter holds the delimiter used in the expression postfix and prefix notation strings.
	 */
	protected static final String m_sDelimiter = ",";

	/**
	 * m_sSymbol holds the symbol that this nlNode looks in ASCII.
	 */
	//protected volatile String m_sSymbol = "node";

	/**
	 * m_sDescription holds the description of this nlNode.
	 */
	//protected String m_sDescription = "Generic nonlinear node";

	/**
	 * <p>m_iSymbol holds the four digit integer that represents this nlNode, with the leftmost (first)
	 * integer representing the category and the right three digits representing a unique sequence number
	 * in the node category. </P>
	 *
	 * <p>Representation schema of leftmost digit:</p>
	 * <p>1 -- Arithmetic Nodes</p>
	 * <p>2 -- Elementary Function Nodes</p>
	 * <p>3 -- Trigonomic Function Nodes</p>
	 * <p>4 -- Statistical Function Nodes</p>
	 * <p>5 -- Constant, Number and Terminal Nodes</p>
	 * <p>6 -- Optimization Nodes</p>
	 * <p>7 -- Logic and Relational Nodes</p>
	 * <p>8 -- Not used yet</p>
	 * <p>9 -- Special and Other Nodes</p>
	 *
	 */
	//protected int m_iSymbol = 0;

	/**
	 * m_iType holds the integer representation of the type of this nlNode.
	 *
	 * <p>Representation schema of the type:</p>
	 * <p>-1 -- indefinite number of operands (e.g. sum)</p>
	 * <p>0 -- no operands (e.g. constants or constant functions)</p>
	 * <p>1 -- unary (e.g. sin)</p>
	 * <p>2 -- unary (e.g. plus)</p>
	 * <p>3 or more (n) -- n-ary (e.g. normal, if-then-else)</p>
	 */
	//protected int m_iType = -1;

	/**
	 * m_mChildren holds all the operands, that is nodes that the current node operate on.
	 */
	protected OSnLNode[] m_mChildren = null;

	/**
	 * m_iEvaluateUserFunctionArguments holds the nest level of evaluation over user function arguments.  
	 */
	protected static int m_iEvaluateUserFunctionArguments = 0;

	/**
	 * m_treeRoot holds the tree root of the current node. 
	 */
	protected static OSnLNode m_treeRoot = null;
	
	/**
	 * m_mdX holds a double array of the current values of variables.
	 */
	protected static double[] m_mdX = null;

	/**
	 * m_msX holds a String array of the current values of variables.
	 */
	protected static String[] m_msX = null;

	/**
	 * m_dFunctionValue holds the function value given the current variable values.
	 */
	protected double m_dFunctionValue = Double.NaN;

	/**
	 * m_sFunctionValue holds the string function value given the current variable values.
	 */
	protected String m_sFunctionValue = null;

	/**
	 * m_dNodeDerivative holds the derivative of function (root node) against this node.
	 */
	protected double m_dNodeDerivative = 1;

	/**
	 * m_mapDerivativeValues holds a hash map of the first partial derivatives w.r.t to each variable
	 * given the current variable values. The map keys are the variable indexes, and the map values are the derivatives.
	 */
	protected Int2DoubleOpenHashMap m_mapDerivativeValues = new Int2DoubleOpenHashMap();

	/**
	 * m_mapHessianValues holds a hash map of the second partial derivatives w.r.t to variable i and then j,
	 * given the current variable values. The map keys are the strings of variable indexes delimited by a comma,
	 * i.e. "i,j" and the map values are the Hessian values.
	 */
	protected Object2DoubleOpenHashMap m_mapHessianValues = new Object2DoubleOpenHashMap();

	/**
	 * m_vPostfix the nonlinear expression starting with the current node in a postfix vector of operator symbols
	 */
	private Vector<String> m_vPostfix = new Vector<String>();

	/**
	 * m_vPrefix the nonlinear expression starting with the current node in a prefix vector of operator symbols
	 */
	private Vector<String> m_vPrefix = new Vector<String>();

	/**
	 * m_vInfix the nonlinear expression starting with the current node in a infix vector of operator symbols
	 */
	private Vector<String> m_vInfix = new Vector<String>();

	/**
	 * Calculate the function value given the current variable values.
	 * This is an abstract method which is required to be implemented by the concrete
	 * operator nodes that derive or extend from this OSnLNode class.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @return the function value given the current variable values.
	 */
	abstract protected double calculateFunction(double[] x);

	/**
	 * Propogate the function derivatives w.r.t the nodes from the root to the node's children.
	 * This is mainly used for the the calculation of all derivatives at the same time to avoid
	 * redundancies, which is based on automatic differentiation.
	 *
	 * </p>
	 *
	 * @param rootNode holds root node of this current node.
	 * @param x holds the values of the variables in a double array.
	 * @see ExpressionTree#calculateDerivatives
	 */
	abstract protected void propogateDerivatives(OSnLNode rootNode, double[] x);

	/**
	 *
	 * @return the symbol of this nlNode in ASCII string.
	 */
	abstract protected String getSymbol();

	/**
	 *
	 * @return the symbol of this nlNode in integer.
	 */
	abstract protected int getSymbolInteger();

	/**
	 *
	 * @return the type of this nlNode.
	 */
	abstract protected int getType();

	/**
	 *
	 * @return the description of this nlNode.
	 */
	abstract protected String getDescription();

	/**
	 * 
	 * @return the string representation of the OSnLNode object. 
	 */
	public String toString(){
		return getSymbol();
	}//toString
	
	/**
	 *
	 * @return the child nodes of this nlNode.
	 */
	protected OSnLNode[] getChildNodes(){
		return m_mChildren;
	}//getChildNodes

	/**
	 *
	 * @param nodes holds the array of node operands to the node operator.
	 */
	protected void setChildNodes(OSnLNode[] nodes){
		m_mChildren = nodes;
	}//setChildNodes

	/**
	 *
	 * @param nodes holds the vector of node operands to the node operator.
	 */
	protected void setChildNodes(Vector nodes){
		OSnLNode[] mChildren = new OSnLNode[nodes.size()];
		for(int i = 0; i < nodes.size(); i++){
			mChildren[i] = (OSnLNode)nodes.elementAt(i);
		}
		setChildNodes(mChildren);
	}//setChildNodes

	/**
	 * Calculate the function value given the current variable values.
	 * If the function has been evaluated over the current x values, the method will retrieve it.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @param functionEvaluated holds whether the function has been evaluated.
	 * @return the function value given the current variable values.
	 */
	protected double calculateFunction(double[] x, boolean functionEvaluated){
		if(functionEvaluated) return m_dFunctionValue;
		else{
			m_dFunctionValue = calculateFunction(x);
			return m_dFunctionValue;
		}
	}//calculateFunction

	/**
	 * Calculate the function value given the current variable values.
	 * If the function has been evaluated over the current x values, the method will retrieve it.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a string array.
	 * @param functionEvaluated holds whether the function has been evaluated.
	 * @return the function derivative value given the current variable values in a string.
	 */
	protected String calculateFunction(String[] x, boolean functionEvaluated){
		if(functionEvaluated) return m_sFunctionValue;
		double[] mdX = new double[x.length];
		for(int i = 0; i < x.length; i++){
			try{
				mdX[i] = Double.parseDouble(x[i]);
			}
			catch(Exception e){
				mdX[i] = Double.NaN;
			}
		}
		m_mdX = mdX;
		m_dFunctionValue = calculateFunction(mdX, functionEvaluated);
		m_sFunctionValue = m_dFunctionValue + "";
		return m_sFunctionValue;
	}//calculateFunction - string based

	/**
	 * Calculate the function derivative value given the current variable values w.r.t one variable.
	 * This is an method which is recommended to be implemented by the concrete
	 * operator nodes that derive or extend from this OSnLNode class. By default this method
	 * uses the finite difference method to numerically calculate the derivative value.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @param index holds the variable index on which to take the derivative.
	 * @param functionEvaluated holds whether the function has been evaluated.
	 * @return the function derivative value given the current variable values w.r.t the specified variable.
	 */
	protected double calculateDerivative(double[] x, int index, boolean functionEvaluated){
		double dCurrentValue = calculateFunction(x, functionEvaluated);
		x[index] +=  m_dDelta;
		double dCurrentPlusDeltaValue = calculateFunction(x);
		x[index] -= m_dDelta;
		m_dFunctionValue = dCurrentValue;
		double dDerivative = (dCurrentPlusDeltaValue - dCurrentValue)/m_dDelta;
		return dDerivative;
	}//calculateDerivative


	/**
	 * This is call to be invoked externally. 
	 * @return the nonlinear expression starting with the current node in a postfix vector of operator symbols.
	 */
	protected Vector<String> getPostfix(){
		m_vPostfix = new Vector<String>();		
		return getPostfix(m_vPostfix);
	}//getPostfix
	
	/**
	 * This is the recursive call. 
	 * @param vPostfix holds the vector to put in the postfix tokens. 
	 * @return the nonlinear expression starting with the current node in a postfix vector of operator symbols.
	 */
	protected Vector<String> getPostfix(Vector<String> vPostfix){
		OSnLNode[] mChildren = getChildNodes();
		for(int i = 0; i < ((getChildNodes() == null)?0:mChildren.length); i++){
			mChildren[i].getPostfix(vPostfix);
		}
		String sSymbol = getSymbol();
		if(getType() == -1){
			sSymbol += "[";
			sSymbol += ((getChildNodes() == null)?0:mChildren.length);
			sSymbol += "]";
		}
		vPostfix.addElement(sSymbol);
		return vPostfix;
	}//getPostfix

	/**
	 * This is call to be invoked externally. 
	 * @return the nonlinear expression starting with the current node in a prefix vector of operator symbols.
	 */
	protected Vector<String> getPrefix(){
		m_vPostfix = new Vector<String>();
		return getPrefix(m_vPrefix);
	}//getPrefix
	
	/**
	 * This is the recursive call. 
	 * @param vPrefix holds the vector to put in the prefix tokens. 
	 * @return the nonlinear expression starting with the current node in a prefix vector of operator symbols.
	 */
	protected Vector<String> getPrefix(Vector<String> vPrefix){
		OSnLNode[] mChildren = getChildNodes();
		String sSymbol = getSymbol();
		if(getType() == -1){
			sSymbol += "[";
			sSymbol += ((getChildNodes() == null)?0:mChildren.length);
			sSymbol += "]";
		}
		vPrefix.addElement(sSymbol);
		for(int i = 0; i < ((mChildren == null)?0:mChildren.length); i++){
			mChildren[i].getPrefix(vPrefix);
		}
		return vPrefix;
	}//getPrefix

	/**
	 * This is call to be invoked externally. 
	 * @return the nonlinear expression starting with the current node in a infix vector of operator symbols.
	 */
	protected Vector<String> getInfix(){
		m_vPostfix = new Vector<String>();
		return getInfix(m_vInfix);
	}//getInfix

	/**
	 * This is the recursive call. 
	 * @param vInfix holds the vector to put in the infix tokens. 
	 * @return the nonlinear expression starting with the current node in an infix vector of operator symbols.
	 */
	protected Vector<String> getInfix(Vector<String> vInfix){
		OSnLNode[] mChildren = getChildNodes();
		String sSymbol = getSymbol();
		int iPrecedence = getPrecedence();
		if(getType() == -1){
			sSymbol += "[";
			sSymbol += ((getChildNodes() == null)?0:mChildren.length);
			sSymbol += "]";
		}
		if(getType() == 2 && iPrecedence != 100){
			int iLeftPrecedence = mChildren[0].getPrecedence();
			int iRightPrecedence = mChildren[1].getPrecedence();
			if(getSymbol().equals("power") && mChildren[0].getSymbol().equals("power")){
				vInfix.addElement("(");
				mChildren[0].getInfix(vInfix);
				vInfix.addElement(")");
			}
			else if(iPrecedence < iLeftPrecedence){
				vInfix.addElement("(");
				mChildren[0].getInfix(vInfix);
				vInfix.addElement(")");
			}
			else{
				mChildren[0].getInfix(vInfix);
			}
			vInfix.addElement(sSymbol);
			if(iPrecedence <= iRightPrecedence){
				if(!getSymbol().equals("power") && !mChildren[1].getSymbol().equals("power")) vInfix.addElement("(");
				mChildren[1].getInfix(vInfix);
				if(!getSymbol().equals("power") && !mChildren[1].getSymbol().equals("power")) vInfix.addElement(")");
			}
			else{
				mChildren[1].getInfix(vInfix);
			}
		}
		else if(getType() == 0 || mChildren == null){
			vInfix.addElement(sSymbol);
		}
		else{
			vInfix.addElement(sSymbol);
			if(mChildren != null && mChildren.length > 0) vInfix.addElement("(");
			for(int i = 0; i < ((mChildren == null)?0:mChildren.length); i++){
				mChildren[i].getInfix(vInfix);
			}
			if(mChildren != null && mChildren.length > 0) vInfix.addElement(")");
		}
		return vInfix;
	}//getInfix

	/**
	 * 
	 * @param document holds the W3C DOM type document to create XML elements and attributes.
	 * It is the parent of the root element, e.g. the &lt;OSiL&gt; element in OSiL. It is used
	 * to create all the nodes in the DOM tree.
	 * @return the nonlinear expression starting with the current node in an XML DOM Tree.
	 */
	protected Element getDOMTree(Document document){
		Element eRoot = document.createElement(getSymbol()); 
		OSnLNode[] mChildren = getChildNodes();
		for(int i = 0; i < ((mChildren == null)?0:mChildren.length); i++){
			Element eChild = mChildren[i].getDOMTree(document);
			eRoot.appendChild(eChild);
		}
		return eRoot;
	}//getDOMTree
	
	/**
	 *
	 * @return the precedence of the current node, the lower the number, the higher the precedence.
	 */
	protected int getPrecedence(){
		int iPrecedence = 100;
		if(getChildNodes() == null || getChildNodes().length == 0) iPrecedence = 0;
		else if(getSymbol().equals("plus")) iPrecedence = 260;
		else if(getSymbol().equals("minus")) iPrecedence = 260;
		else if(getSymbol().equals("negate")) iPrecedence = 230;
		else if(getSymbol().equals("times")) iPrecedence = 240;
		else if(getSymbol().equals("divide")) iPrecedence = 240;
		else if(getSymbol().equals("quotient")) iPrecedence = 240;
		else if(getSymbol().equals("rem")) iPrecedence = 240;
		else if(getSymbol().equals("power")) iPrecedence = 220;
		else if(getSymbol().equals("lt")) iPrecedence = 320;
		else if(getSymbol().equals("leq")) iPrecedence = 320;
		else if(getSymbol().equals("gt")) iPrecedence = 320;
		else if(getSymbol().equals("geq")) iPrecedence = 320;
		else if(getSymbol().equals("eq")) iPrecedence = 320;
		else if(getSymbol().equals("neq")) iPrecedence = 320;
		else if(getSymbol().equals("and")) iPrecedence = 340;
		else if(getSymbol().equals("or")) iPrecedence = 350;
		else if(getSymbol().equals("xor")) iPrecedence = 340;
		else if(getSymbol().equals("implies")) iPrecedence = 350;
		else if(getSymbol().equals("not")) iPrecedence = 330;
		else if(getSymbol().equals("complements")) iPrecedence = 325;
		return iPrecedence;
	}//getPrecedence

	/**
	 * relabel variable indices, e.g. X0 -> X2; X1 -> X0; X2 -> X1. 
	 * 
	 * @param newVariableIndices holds the new varialbe indices. For the example above it would be [2, 0, 1]. 
	 * @return whether the relabeling is successful or not. 
	 */
	public boolean reLabelVariableIndices(int[] newVariableIndices){
		if(getSymbolInteger() == 6001){
			int iIndex = ((OSnLNodeVariable)this).getIndex();
			int iVarLength = newVariableIndices==null?0:newVariableIndices.length;
			if(iIndex < 0){
				;
			}
			else if(iIndex >= iVarLength){
				return false;
			}
			else{
				((OSnLNodeVariable)this).setIndex(newVariableIndices[iIndex]);
			}
		}	
		if(getSymbolInteger() == 9001){
			int iIndex1 = ((OSnLNodeQTerm)this).getVarOneIndex();
			int iIndex2 = ((OSnLNodeQTerm)this).getVarTwoIndex();
			int iVarLength = newVariableIndices==null?0:newVariableIndices.length;
			if(iIndex1 < 0 || iIndex2 < 0 || iIndex1 >= iVarLength || iIndex2 >= iVarLength){
				return false;
			}
			else{
				((OSnLNodeQTerm)this).setVarOneIndex(newVariableIndices[iIndex1]);
				((OSnLNodeQTerm)this).setVarTwoIndex(newVariableIndices[iIndex2]);
				return true;
			}
		}
		for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
			boolean bRelabel = m_mChildren[i].reLabelVariableIndices(newVariableIndices);
			if(!bRelabel){
				return false;
			}
		}
		return true;
	}//reLabelVariableIndices
	
	/**
	 * <p>Simplify the current node's children and return whether the current node's children
	 * can be simplified or not. The current node is simplifiable if it has all constants/numbers
	 * as its children.
	 *
	 * @return whether the node is simplifiable or not.
	 */
	protected boolean simplify(){//TODO reimplementation in "sum" perhaps
		if(m_mChildren == null) return false;
		boolean bSimplifiable = true;
		for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
			if(m_mChildren[i].simplify()){
				double dValue = m_mChildren[i].calculateFunction(null);
				OSnLNodeNumber osnlNodeNumber = new OSnLNodeNumber(null, dValue + "", "real");
				m_mChildren[i] = osnlNodeNumber;
			}
			else{
				int iChildIndex = m_mChildren[i].getSymbolInteger();
				if(iChildIndex == 5001){
					String sType = ((OSnLNodeNumber)m_mChildren[i]).getNumberType();
					if(sType.equalsIgnoreCase("string") || sType.equalsIgnoreCase("random")){
						bSimplifiable = false;
					}
					else{
					}
				}
				else if(iChildIndex >= 5003 && iChildIndex < 6000){
				}
				else{
					bSimplifiable = false;
				}
			}
		}
		return bSimplifiable;
	}//simplify

	/**
	 * <p>Simplify the variables of the current node's children. The method converts number*variable into
	 * just a variable with the number as a coefficient of the varialbe. 
	 */
	protected void simplifyVariables(){
		for(int k = 0; k < ((m_mChildren == null)?0:m_mChildren.length); k++){
			m_mChildren[k].simplifyVariables();				
			if(m_mChildren[k].getSymbolInteger() == 1005){
				int i, j;
				i = m_mChildren[k].m_mChildren[0].getSymbolInteger();
				j = m_mChildren[k].m_mChildren[1].getSymbolInteger();
				if((i >= 5001 && i < 6000 && i != 5002) && j == 6001){
					if(m_mChildren[k].m_mChildren[0].getSymbolInteger() == 5001 && 
							!((OSnLNodeNumber)m_mChildren[k].m_mChildren[0]).getNumberType().equals("real"));
					else{
						OSnLNodeVariable varNode = (OSnLNodeVariable)m_mChildren[k].m_mChildren[1];
						double dCoef = varNode.getCoef();
						dCoef *= m_mChildren[k].m_mChildren[0].calculateFunction(null);
						varNode.setCoef(dCoef);
						m_mChildren[k] = varNode;
					}
				}
				else if(i == 6001 && (j >= 5001 && j < 6000 && j != 5002)){
					if(m_mChildren[k].m_mChildren[1].getSymbolInteger() == 5001 && 
							!((OSnLNodeNumber)m_mChildren[k].m_mChildren[1]).getNumberType().equals("real"));
					else{
						OSnLNodeVariable varNode = (OSnLNodeVariable)m_mChildren[k].m_mChildren[0];
						double dCoef = varNode.getCoef();
						dCoef *= m_mChildren[k].m_mChildren[1].calculateFunction(null);
						varNode.setCoef(dCoef);
						m_mChildren[k] = varNode;
					}
				}
			}
			else if(m_mChildren[k].getSymbolInteger() == 1004){
				int i;
				i = m_mChildren[k].m_mChildren[0].getSymbolInteger();
				if(i == 6001){
					OSnLNodeVariable varNode = (OSnLNodeVariable)m_mChildren[k].m_mChildren[0];
					double dCoef = varNode.getCoef()*(-1);
					varNode.setCoef(dCoef);
					m_mChildren[k] = varNode;
				}
			}			
			else if(m_mChildren[k].getSymbolInteger() == 1006){
				int i, j;
				i = m_mChildren[k].m_mChildren[0].getSymbolInteger();
				j = m_mChildren[k].m_mChildren[1].getSymbolInteger();
				if(i == 6001 && (j >= 5001 && j < 6000 && j != 5002)){
					if(m_mChildren[k].m_mChildren[1].getSymbolInteger() == 5001 && 
							!((OSnLNodeNumber)m_mChildren[k].m_mChildren[1]).getNumberType().equals("real"));
					else{
						OSnLNodeVariable varNode = (OSnLNodeVariable)m_mChildren[k].m_mChildren[0];
						double dCoef = varNode.getCoef();
						dCoef /= m_mChildren[k].m_mChildren[1].calculateFunction(null);
						varNode.setCoef(dCoef);
						m_mChildren[k] = varNode;
					}
				}
			}
		}
	}//simplifyVariables

	/**
	 * <p>Linearize the current node so that it doesn't contain linear terms.
	 * The expression tree of the node will become smaller if there are linear terms.
	 * If the node is fully linear, the node becomes null. If the node is not linear
	 * at all, it will remain the same and the returned hash map has a size zero.
	 *
	 * @return a hashmap of linear terms extracted out from this node,
	 * with keys being the variable indices and values being the variable coefficients.
	 */
	protected Int2DoubleOpenHashMap linearize(){//TODO
		Int2DoubleOpenHashMap mapIndexCoef = new Int2DoubleOpenHashMap();
		return mapIndexCoef;
	}//linearize

	/**
	 * <p>Quadratize the current node, or make all the quadratic terms written in the
	 * form of a quadratic node with its children being the quadratic terms.
	 *
	 * @return whether there is conversion of some quadratic terms.
	 */
	protected boolean quadratize(){//TODO
		return false;
	}//quadratize

	/**
	 *
	 * @return an integer set of indices of the variables that exist in the current node.
	 */
	protected IntOpenHashSet getVariableIndices(){
		IntOpenHashSet indexSet = new IntOpenHashSet();		
		if(getSymbolInteger() == 6001 && ((OSnLNodeVariable)this).getIndex() >= 0){
			indexSet.add(((OSnLNodeVariable)this).getIndex());
		}
		else if(getSymbolInteger() == 9001){
			indexSet.add(((OSnLNodeQTerm)this).getVarOneIndex());
			indexSet.add(((OSnLNodeQTerm)this).getVarTwoIndex());
		}
		else{
			for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
				indexSet.addAll(m_mChildren[i].getVariableIndices());
			}
		}
		return indexSet;
	}//getVariableIndices

	/**
	 *
	 * @return the tree size, i.e. the number of nodes, of the tree.
	 */
	protected int getSize(){
		int iSize = 1;
		for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
			iSize += m_mChildren[i].getSize();
		}
		return iSize;
	}//getSize

	/**
	 *
	 * @return the number of trigonometric functions in the tree.
	 */
	protected int getNumberOfTrigonometricFunctions(){
		int iSize = 0;
		if(getSymbolInteger() >= 3000 && getSymbolInteger() < 4000) iSize = 1;
		for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
			iSize += m_mChildren[i].getNumberOfTrigonometricFunctions();
		}
		return iSize;
	}//getNumberOfTrigonometricFunctions

	/**
	 *
	 * @return the number of statistic functions in the tree.
	 */
	protected int getNumberOfStatisticFunctions(){
		int iSize = 0;
		if(getSymbolInteger() >= 4000 && getSymbolInteger() < 4400) iSize = 1;
		for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
			iSize += m_mChildren[i].getNumberOfStatisticFunctions();
		}
		return iSize;
	}//getNumberOfStatisticFunctions

	/**
	 *
	 * @return the number of probability functions in the tree.
	 */
	protected int getNumberOfProbabilityFunctions(){
		int iSize = 0;
		if(getSymbolInteger() >= 4400 && getSymbolInteger() < 5000) iSize = 1;
		for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
			iSize += m_mChildren[i].getNumberOfProbabilityFunctions();
		}
		return iSize;
	}//getNumberOfProbabilityFunctions

	/**
	 *
	 * @return a set of number values that exist in the current node.
	 */
	protected  HashSet<String> getNumberValues(){
		HashSet<String> numberValueSet = new HashSet<String>();
		if(getSymbolInteger() == 5001){
			numberValueSet.add(((OSnLNodeNumber)this).getNumberValue());
		}
		if(getSymbolInteger() >= 5003 && getSymbolInteger() < 6000){
			numberValueSet.add(getSymbol());
		}
		for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
			numberValueSet.addAll(m_mChildren[i].getNumberValues());
		}
		return numberValueSet;
	}//getNumberValues

	/**
	 *
	 * @return a set of names of identifiers that exist in the current node.
	 */
	protected  HashSet<String> getIdentifiers(){
		HashSet<String> nameSet = new HashSet<String>();
		if(getSymbolInteger() == 5002){
			nameSet.add(((OSnLNodeIdentifier)this).getIdentifierName());
		}
		for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
			nameSet.addAll(m_mChildren[i].getIdentifiers());
		}
		return nameSet;
	}//getIdentifiers

	/**
	 *
	 * @return a set of logic and relational operator symbols that exist in the current node.
	 */
	protected  HashSet<String> getLogicAndRelationalSymbols(){
		HashSet<String> logicRelationalSet = new HashSet<String>();
		if(getSymbolInteger() >= 7000 && getSymbolInteger() < 8000){
			logicRelationalSet.add(getSymbol());
		}
		for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
			logicRelationalSet.addAll(m_mChildren[i].getLogicAndRelationalSymbols());
		}
		return logicRelationalSet;
	}//getLogicAndRelationalSymbols

	/**
	 *
	 * @return a set of quadratic terms that exist in the current node.
	 */
	protected  HashSet<String> getQuadraticTerms(){
		HashSet<String> quadraticTermSet = new HashSet<String>();
		if(getSymbolInteger() == 9001){
			String s = ((OSnLNodeQTerm)this).getSymbol();
			quadraticTermSet.add(s);
		}
		for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
			quadraticTermSet.addAll(m_mChildren[i].getQuadraticTerms());
		}
		return quadraticTermSet;
	}//getQuadraticTerms

	/**
	 *
	 * @return a set of names of the simulations that exist in the current node.
	 */
	protected  HashSet<String> getSimulationNames(){
		HashSet<String> simNameSet = new HashSet<String>();
		if(getSymbolInteger() == 9003){
			simNameSet.add(((OSnLNodeSim)this).getSimName());
		}
		for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
			simNameSet.addAll(m_mChildren[i].getSimulationNames());
		}
		return simNameSet;
	}//getSimulationNames

	/**
	 *
	 * @return a set of names of the user defined functions that exist in the current node.
	 */
	protected  HashSet<String> getUserFunctionNames(){
		HashSet<String> userFNameSet = new HashSet<String>();
		if(getSymbolInteger() == 9006){
			userFNameSet.add(((OSnLNodeUserF)this).getUserFName());
		}
		for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
			userFNameSet.addAll(m_mChildren[i].getUserFunctionNames());
		}
		return userFNameSet;
	}//getUserFunctionNames

	/**
	 *
	 * @return a set of XPaths that exist in the current node, each set member is of the form:
	 * uri:path, that is uri and path delimited by :.
	 */
	protected  HashSet<String> getXPath(){
		HashSet<String> xPathSetSet = new HashSet<String>();
		if(getSymbolInteger() == 9008){
			String s = "";
			s+= ((OSnLNodeXPath)this).getURI() + ":";
			s+= ((OSnLNodeXPath)this).getPath();
			xPathSetSet.add(s);
		}
		for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
			xPathSetSet.addAll(m_mChildren[i].getXPath());
		}
		return xPathSetSet;
	}//getXPath

	/**
	 *
	 * @return a set of network nodes that are referred in the current node, each set member is of the form:
	 * nodeName:propertyName, that is nodeName and property name delimited :.
	 */
	protected  HashSet<String> getNetworkNodes(){
		HashSet<String> nodeSet = new HashSet<String>();
		if(getSymbolInteger() == 9010){
			String s = "";
			//s+= ((OSnLNodeNodeRef)this).getNodeName() + ":";
			//s+= ((OSnLNodeNodeRef)this).getPropName();
			nodeSet.add(s);
		}
		for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
			nodeSet.addAll(m_mChildren[i].getNetworkNodes());
		}
		return nodeSet;
	}//getNetworkNodes

	/**
	 *
	 * @return a set of network arcs that are referred in the current arc, each set member is of the form:
	 * arcName:propertyName, that is arcName and property name delimited :.
	 */
	protected  HashSet<String> getNetworkArcs(){
		HashSet<String> arcSet = new HashSet<String>();
		if(getSymbolInteger() == 9011){
			String s = "";
			//s+= ((OSnLNodeArcRef)this).getArcName() + ":";
			//s+= ((OSnLNodeArcRef)this).getPropName();
			arcSet.add(s);
		}
		for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
			arcSet.addAll(m_mChildren[i].getNetworkArcs());
		}
		return arcSet;
	}//getNetworkArcs

	/**
	 *
	 * @return the number of the complements operator in current node.
	 */
	protected int getNumberOfComplementsOperator(){
		int iSize = 0;
		if(getSymbolInteger() == 9012) iSize = 1;
		for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
			iSize += m_mChildren[i].getNumberOfComplementsOperator();
		}
		return iSize;
	}//getNumberOfComplementsOperator

	/**
	 *
	 * @return the number of the probability operator (usually in a chance constraint in current node.
	 */
	protected int getNumberOfProbOperator(){
		int iSize = 0;
		if(getSymbolInteger() == 9013) iSize = 1;
		for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
			iSize += m_mChildren[i].getNumberOfProbOperator();
		}
		return iSize;
	}//getNumberOfProbOperator

	/**
	 * Set the string values of OSnLNodeArg. 
	 * 
	 * @param args holds a string array of all args used in a userFunction. 
	 */
	protected void setArgumentStringValues(String[] args){
		if(getSymbolInteger() == 9007){
			((OSnLNodeArg)this).m_sFunctionValue = args[((OSnLNodeArg)this).getArgumentIndex()];
		}
		else{
			for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
				m_mChildren[i].setArgumentStringValues(args);
			}
		}
	}//setArgumentStringValues	
	
}//class OSnLNode
