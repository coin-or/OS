using System;
using System.Collections;
using System.Xml;

//using Iesi.Collections;

namespace org.optimizationservices.oscommon.nonlinear{
	/// <summary>
	/// The <c>OSnLNode</c> class represents a node in an expression tree 
	/// for a nonlinear function (linear ones being special cases) and provide 
	/// convenience methods to process the node. It is an abstract
	/// (or generic) node from which we derive concrete operator nodes.
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public abstract class OSnLNode{	
		protected internal static string[] msNodeNames = {
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
			"triangularDist", "triangularCum", "triangularInv",
			/*5--*/"number", "identifier", "PI", "E", "INF", "EPS", "TRUE", "FALSE", "EULERGAMMA", "NAN",
			/*6--*/"variable", "objective", "constraint",
			/*7--*/"if", "lt", "leq", "gt", "geq", "eq", "neq", "and", "or", "xor", "implies", "not",
			"forAll", "exists", "logicCount", "allDiff", /*"allDisjoint",*/ "atMost", "atLeast", "exactly", 
			"inSet", "inRealSet", "inPositiveRealSet", "inNonnegativeRealSet", "inIntegerSet", "inPositiveIntegerSet","inNonnegativeIntegerSet",
			/*8--*/
			/*9--*/"qpTerm", "quadratic", "sim", "simInput", "simOutput", "userF", "arg", "xPath", "xPathIndex",
			"nodeRef", "arcRef", "complements", /*"prob",*/
		};

		protected static string[] m_msNodeSymbols = {
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
			"triangularDist", "triangularCum", "triangularInv",
			/*5--*/"number", "identifier", "PI", "E", "INF", "EPS", "TRUE", "FALSE", "EULERGAMMA", "NAN",
			/*6--*/"X", "objective", "constraint", 
			/*7--*/"if", "lt", "leq", "gt", "geq", "eq", "neq", "and", "or", "xor", "implies", "not",
			"forAll", "exists", "logicCount", "allDiff", /*"allDisjoint",*/ "atMost", "atLeast", "exactly",
			"inSet", "inRealSet", "inPositiveRealSet", "inNonnegativeRealSet", "inIntegerSet", "inPositiveIntegerSet", "inNonnegativeIntegerSet",
			/*8--*/
			/*9--*/"quadratic", "qpTerm", "sim", "simInput", "simOutput", "userF", "arg", "xPath", "xPathIndex",
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
			4621, 4622, 4623,
			/*5--*/5001, 5002, 5003, 5004, 5005, 5006, 5007, 5008, 5009, 5010,
			/*6--*/6001, 6002, 6003,
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
			4, 4, 4,
			/*5--*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			/*6--*/-1, -1, -1,
			/*7--*/3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
			-1, -1, -1, -1, /*-1,*/ -1, -1, -1, 
			-1, 1, 1, 1, 1, 1, 1
			/*8--*/
			/*9--*/-1, -1, -1, -1, -1, -1, 0, -1, -1,
			-1, -1, 2, /*1,*/
		};


		/// <summary>
		/// m_dDelta holds the delta value used to calulate derivatives with numerical finite difference method. 
		/// </summary>
		protected internal const double m_dDelta = 10e-8;

		/// <summary>
		/// m_dIntTol holds the integer tolerance value to numerically decide if a value is integer or not.
		/// </summary>
		protected internal const double m_dIntTol = 10e-8;

		/// <summary>
		/// m_dTRUE holds the double value representation of the bool TRUE. 
		/// </summary>
		protected internal const double m_dTRUE = 1.847363582443103;

		/**
		 * m_dFALSE holds the double value representation of the bool FALSE.
		 */
		protected internal const double m_dFALSE = -m_dTRUE;

		/// <summary>
		/// m_sDelimiter holds the delimiter used in the expression postfix and prefix notation strings. 
		/// </summary>
		protected internal const string m_sDelimiter = ",";

		/// <summary>
		/// m_sSymbol holds the symbol that this nlNode looks in ASCII.
		/// </summary>
		//protected internal volatile string m_sSymbol = "node";

		/// <summary>
		/// m_sSymbol holds the description of this nlNode.
		/// </summary>
		//protected internal string m_sDescription = "Generic nonlinear node";

		/// <summary>
		/// <p>m_iSymbol holds the four digit integer that represents this nlNode, with the leftmost (first)
		/// integer representing the category and the right three digits representing a unique sequence number
		/// in the node category. </P>
		
		/// <p>Representation schema of leftmost digit:</p>
		/// <p>1 -- Arithmetic Nodes</p>
		/// <p>2 -- Elementary Function Nodes</p>
		/// <p>3 -- Trigonomic Function Nodes</p>
		/// <p>4 -- Statistical Function Nodes</p>
		/// <p>5 -- Constant, Number and Terminal Nodes</p>
		/// <p>6 -- Variable Nodes</p>
		/// <p>7 -- Logic and Relational Nodes</p>
		/// <p>8 -- Not used yet</p>
		/// <p>9 -- Special and Other Nodes</p>
		///  </summary>	
		//protected internal int m_iSymbol = 0;

		/// <summary>
		/// m_iType holds the integer representation of the type of this nlNode.
		///
		/// <p>Representation schema of the type:</p>
		/// <p>-1 -- indefinite number of operands (e.g. sum)</p>
		/// <p>0 -- no operands (e.g. constants or constant functions)</p>
		/// <p>1 -- unary (e.g. sin)</p>
		/// <p>2 -- unary (e.g. plus)</p>
		/// <p>3 or more (n) -- n-ary (e.g. normal, if-then-else)</p>
		///  </summary>	
		//protected internal int m_iType = -1;

		/// <summary>
		/// m_mChildren holds all the operands, that is nodes that the current node operate on.
		/// </summary>
		protected internal OSnLNode[] m_mChildren = null;

		/// <summary>
		/// m_iEvaluateUserFunctionArguments holds the nest level of evaluation over user function arguments.  
		/// </summary>
		protected internal static int m_iEvaluateUserFunctionArguments = 0;

		/// <summary>
		/// m_treeRoot holds the tree root of the current node. 
		/// </summary>
		protected internal static OSnLNode m_treeRoot = null;

		/// <summary>
		/// m_mdX holds a double array of the current values of variables.
		/// </summary>
		protected internal static double[] m_mdX = null;

		/// <summary>
		/// m_msX holds a string array of the current values of variables.
		/// </summary>
		protected internal static string[] m_msX = null;

		/// <summary>
		/// m_dFunctionValue holds the function value given the current variable values.
		/// </summary>
		protected internal double m_dFunctionValue = Double.NaN;

		/// <summary>
		/// m_sFunctionValue holds the string function value given the current variable values.
		/// </summary>
		protected internal string m_sFunctionValue = null;
		
		/// <summary>
		/// m_dNodeDerivative holds the derivative of function (root node) against this node.
		/// </summary>
		protected internal double m_dNodeDerivative = 1;

		/// <summary>
		/// m_mapDerivativeValues holds a hash map of the first partial derivatives w.r.t to each variable
		/// given the current variable values. The map keys are the variable indexes, and the map values are the derivatives.
		/// </summary>
		protected internal Hashtable m_mapDerivativeValues = new Hashtable();

		/// <summary>
		/// m_mapHessianValues holds a hash map of the second partial derivatives w.r.t to variable i and then j,
		/// given the current variable values. The map keys are the strings of variable indexes delimited by a comma,
		/// i.e. "i,j" and the map values are the Hessian values.
		/// </summary>
		protected internal Hashtable m_mapHessianValues = new Hashtable();

		/// <summary>
		/// Calculate the function value given the current variable values.
		/// This is an abstract method which is required to be implemented by the concrete
		/// operator nodes that derive or extend from this OSnLNode class.
		/// 
		/// </summary>
		/// <param name="x">holds the values of the variables in a double array.</param>
		/// <returns>the function value given the current variable values.</returns>
		abstract protected internal double calculateFunction(double[] x);


		/// <summary>
		/// Propogate the function derivatives w.r.t the nodes from the root to the node's children.
		/// This is mainly used for the the calculation of all derivatives at the same time to avoid
		/// redundancies, which is based on automatic differentiation.
		/// @see ExpressionTree#calculateDerivatives
		/// 
		/// </summary>
		/// <param name="rootNode">rootNode holds root node of this current node.</param>
		/// <param name="x">holds the values of the variables in a double array.</param>
		abstract protected internal void propogateDerivatives(OSnLNode rootNode, double[] x);

		/// <summary>
		/// Get the symbol of this nlNode in ASCII string.
		/// </summary>
		/// <returns>the symbol of this nlNode in ASCII string.</returns>
		abstract protected internal string getSymbol();

		/// <summary>
		/// Get the symbol of this nlNode in integer.
		/// </summary>
		/// <returns>the symbol of this nlNode in integer.</returns>
		abstract protected internal int getSymbolInteger();

		/// <summary>
		/// Get the type of this nlNode.
		/// </summary>
		/// <returns>the type of this nlNode.</returns>
		abstract protected internal int getType();

		/// <summary>
		/// Get the description of this nlNode.
		/// </summary>
		/// <returns>the description of this nlNode.</returns>
		abstract protected internal string getDescription();

		/// <summary>
		/// Get the string representation of the OSnLNode object. 
		/// </summary>
		/// <returns>the string representation of the OSnLNode object. </returns>
		public string toString(){
			return getSymbol();
		}//toString

		/// <summary>
		/// Get the child nodes of this nlNode.
		/// </summary>
		/// <returns>the child nodes of this nlNode.</returns>
		protected internal virtual OSnLNode[] getChildNodes(){
			return m_mChildren;
		}//getChildNodes

		/// <summary>
		/// Set the child nodes. 
		/// </summary>
		/// <param name="nodes">holds the array of node operands to the node operator.</param>
		protected internal virtual void setChildNodes(OSnLNode[] nodes){
			m_mChildren = nodes;
		}//setChildNodes

		/// <summary>
		/// set the child nodes. 
		/// </summary>
		/// <param name="nodes">holds the vector of node operands to the node operator.</param>
		protected internal virtual void setChildNodes(ArrayList nodes){
			OSnLNode[] mChildren = new OSnLNode[nodes.Count];
			for(int i = 0; i < nodes.Count; i++){
				mChildren[i] = (OSnLNode)nodes[i];
			}
			setChildNodes(mChildren);
		}//setChildNodes

		/// <summary>
		/// Calculate the function value given the current variable values.
		/// If the function has been evaluated over the current x values, the method will retrieve it.
		/// </summary>
		/// <param name="x">holds the values of the variables in a double array.</param>
		/// <param name="functionEvaluated">functionEvaluated holds whether the function has been evaluated.</param>
		/// <returns>the function value given the current variable values.</returns>
		protected internal virtual double calculateFunction(double[] x, bool functionEvaluated){
			if(functionEvaluated) return m_dFunctionValue;
			else{
				m_dFunctionValue = calculateFunction(x);
				return m_dFunctionValue;
			}
		}//calculateFunction
		
		/// <summary>
		/// Calculate the function value given the current variable values.
		/// If the function has been evaluated over the current x values, the method will retrieve it.
		/// </summary>
		/// <param name="x">holds the values of the variables in a string array.</param>
		/// <param name="functionEvaluated">holds whether the function has been evaluated.</param>
		/// <returns>the function derivative value given the current variable values in a string.</returns>
		protected internal virtual string calculateFunction(string[] x, bool functionEvaluated){
			if(functionEvaluated) return m_sFunctionValue;
			double[] mdX = new double[x.Length];
			for(int i = 0; i < x.Length; i++){
				try{
					mdX[i] = Convert.ToDouble(x[i]);
				}
				catch(Exception){
					mdX[i] = Double.NaN;
				}
			}
			m_mdX = mdX;
			m_dFunctionValue = calculateFunction(mdX, functionEvaluated);
			m_sFunctionValue = m_dFunctionValue + "";
			return m_sFunctionValue;
		}//calculateFunction - string based

		/// <summary>
		/// Calculate the function derivative value given the current variable values w.r.t one variable.
		/// This is an method which is recommended to be implemented by the concrete
		/// operator nodes that derive or extend from this OSnLNode class. By default this method
		/// uses the finite difference method to numerically calculate the derivative value.
		/// 
		/// </summary>
		/// <param name="x">holds the values of the variables in a double array.</param>
		/// <param name="index">holds the variable index on which to take the derivative.</param>
		/// <param name="functionEvaluated">holds whether the function has been evaluated.</param>
		/// <returns>the function derivative value given the current variable values w.r.t the specified variable.</returns>
		protected internal virtual double calculateDerivative(double[] x, int index, bool functionEvaluated){
			double dCurrentValue = calculateFunction(x, functionEvaluated);
			x[index] +=  m_dDelta;
			double dCurrentPlusDeltaValue = calculateFunction(x);
			x[index] -= m_dDelta;
			m_dFunctionValue = dCurrentValue;
			double dDerivative = (dCurrentPlusDeltaValue - dCurrentValue)/m_dDelta;
			return dDerivative;
		}//calculateDerivative


		/// <summary>
		/// Get the nonlinear expression starting with the current node in a postfix vector of operator symbols.
		/// </summary>
		/// <returns>the nonlinear expression starting with the current node in a postfix vector of operator symbols.</returns>
		protected internal virtual ArrayList getPostfix(){
			ArrayList vPostfix = new ArrayList();
				OSnLNode[] mChildren = getChildNodes();
			for(int i = 0; i < ((getChildNodes() == null)?0:mChildren.Length); i++){
				vPostfix.AddRange(mChildren[i].getPostfix());
			}
			string sSymbol = getSymbol();
			if(getType() == -1){
				sSymbol += "[";
				sSymbol += ((getChildNodes() == null)?0:mChildren.Length);
				sSymbol += "]";
			}
			vPostfix.Add(sSymbol);
			return vPostfix;
		}//getPostfix

		/// <summary>
		/// Get the nonlinear expression starting with the current node in a prefix vector of operator symbols.
		/// </summary>
		/// <returns>the nonlinear expression starting with the current node in a prefix vector of operator symbols.</returns>
		protected internal virtual ArrayList getPrefix(){
			ArrayList vPrefix  = new ArrayList();
				OSnLNode[] mChildren = getChildNodes();
			string sSymbol = getSymbol();
			if(getType() == -1){
				sSymbol += "[";
				sSymbol += ((getChildNodes() == null)?0:mChildren.Length);
				sSymbol += "]";
			}
			vPrefix.Add(sSymbol);
			for(int i = 0; i < ((mChildren == null)?0:mChildren.Length); i++){
				vPrefix.AddRange(mChildren[i].getPrefix());
			}
			return vPrefix;
		}//getPrefix

		/// <summary>
		/// Get the nonlinear expression starting with the current node in an infix vector of operator symbols.
		/// </summary>
		/// <returns>the nonlinear expression starting with the current node in an infix vector of operator symbols.</returns>
		protected internal virtual ArrayList getInfix(){
			ArrayList vInfix  = new ArrayList();
				OSnLNode[] mChildren = getChildNodes();
			string sSymbol = getSymbol();
			int iPrecedence = getPrecedence();
			if(getType() == -1){
				sSymbol += "[";
				sSymbol += ((getChildNodes() == null)?0:mChildren.Length);
				sSymbol += "]";
			}
			if(getType() == 2 && iPrecedence != 100){
				int iLeftPrecedence = mChildren[0].getPrecedence();
				int iRightPrecedence = mChildren[1].getPrecedence();
				if(getSymbol().Equals("power") && mChildren[0].getSymbol().Equals("power")){
					vInfix.Add("(");
					vInfix.AddRange(mChildren[0].getInfix());
					vInfix.Add(")");
				}
				else if(iPrecedence < iLeftPrecedence){
					vInfix.Add("(");
					vInfix.AddRange(mChildren[0].getInfix());
					vInfix.Add(")");
				}
				else{
					vInfix.AddRange(mChildren[0].getInfix());
				}
				vInfix.Add(sSymbol);
				if(iPrecedence <= iRightPrecedence){
					if(!getSymbol().Equals("power") && !mChildren[1].getSymbol().Equals("power")) vInfix.Add("(");
					vInfix.AddRange(mChildren[1].getInfix());
					if(!getSymbol().Equals("power") && !mChildren[1].getSymbol().Equals("power")) vInfix.Add(")");
				}
				else{
					vInfix.AddRange(mChildren[1].getInfix());
				}
			}
			else if(getType() == 0 || mChildren == null){
				vInfix.Add(sSymbol);
			}
			else{
				vInfix.Add(sSymbol);
				if(mChildren != null && mChildren.Length > 0) vInfix.Add("(");
				for(int i = 0; i < ((mChildren == null)?0:mChildren.Length); i++){
					vInfix.AddRange(mChildren[i].getInfix());
				}
				if(mChildren != null && mChildren.Length > 0) vInfix.Add(")");
			}
			return vInfix;
		}//getInfix

		/// <summary>
		/// Get the nonlinear expression starting with the current node in an XML DOM Tree.
		/// </summary>
		/// <param name="document">holds the W3C DOM type document to create XML elements and attributes.
		/// It is the parent of the root element, e.g. the &lt;OSiL&gt; element in OSiL. It is used
		/// to create all the nodes in the DOM tree.</param>
		/// <returns>the nonlinear expression starting with the current node in an XML DOM Tree.</returns>
		protected internal virtual XmlElement getDOMTree(XmlDocument document){
			XmlElement eRoot = document.CreateElement(getSymbol()); 
			OSnLNode[] mChildren = getChildNodes();
			for(int i = 0; i < ((mChildren == null)?0:mChildren.Length); i++){
				XmlElement eChild = mChildren[i].getDOMTree(document);
				eRoot.AppendChild(eChild);
			}
			return eRoot;
		}//getDOMTree

		/// <summary>
		/// Get the precedence of the current node, the lower the number, the higher the precedence.
		/// </summary>
		/// <returns>the precedence of the current node, the lower the number, the higher the precedence.</returns>
		protected internal virtual int getPrecedence(){
			int iPrecedence = 100;
			if(getChildNodes() == null || getChildNodes().Length == 0) iPrecedence = 0;
			else if(getSymbol().Equals("plus")) iPrecedence = 260;
			else if(getSymbol().Equals("minus")) iPrecedence = 260;
			else if(getSymbol().Equals("negate")) iPrecedence = 230;
			else if(getSymbol().Equals("times")) iPrecedence = 240;
			else if(getSymbol().Equals("divide")) iPrecedence = 240;
			else if(getSymbol().Equals("quotient")) iPrecedence = 240;
			else if(getSymbol().Equals("rem")) iPrecedence = 240;
			else if(getSymbol().Equals("power")) iPrecedence = 220;
			else if(getSymbol().Equals("lt")) iPrecedence = 320;
			else if(getSymbol().Equals("leq")) iPrecedence = 320;
			else if(getSymbol().Equals("gt")) iPrecedence = 320;
			else if(getSymbol().Equals("geq")) iPrecedence = 320;
			else if(getSymbol().Equals("eq")) iPrecedence = 320;
			else if(getSymbol().Equals("neq")) iPrecedence = 320;
			else if(getSymbol().Equals("and")) iPrecedence = 340;
			else if(getSymbol().Equals("or")) iPrecedence = 350;
			else if(getSymbol().Equals("xor")) iPrecedence = 340;
			else if(getSymbol().Equals("implies")) iPrecedence = 350;
			else if(getSymbol().Equals("not")) iPrecedence = 330;
			else if(getSymbol().Equals("complements")) iPrecedence = 325;
			return iPrecedence;
		}//getPrecedence

		/// <summary>
		/// implify the current node's children and return whether the current node's children
		/// can be simplified or not. The current node is simplifiable if it has all constants/numbers
		/// as its children.
		/// </summary>
		/// <returns>whether the node is simplifiable or not.</returns>
		protected internal virtual bool simplify(){//TODO reimplementation in "sum" perhaps
			if(m_mChildren == null) return false;
			bool bSimplifiable = true;
			for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.Length); i++){
				if(m_mChildren[i].simplify()){
					double dValue = m_mChildren[i].calculateFunction(null);
					OSnLNodeNumber osnlNodeNumber = new OSnLNodeNumber(null, dValue + "", "real");
					m_mChildren[i] = osnlNodeNumber;
				}
				else{
					int iChildIndex = m_mChildren[i].getSymbolInteger();
					if(iChildIndex == 5001){
						string sType = ((OSnLNodeNumber)m_mChildren[i]).getNumberType();
						if(sType.ToLower().Equals("string") || sType.ToLower().Equals("random")){
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

		/// <summary>
		/// Simplify the variables of the current node's children. The method converts number*variable into
		/// just a variable with the number as a coefficient of the varialbe. 
		/// </summary>
		protected internal virtual void simplifyVariables(){
			for(int k = 0; k < ((m_mChildren == null)?0:m_mChildren.Length); k++){
				m_mChildren[k].simplifyVariables();				
				if(m_mChildren[k].getSymbolInteger() == 1005){
					int i, j;
					i = m_mChildren[k].m_mChildren[0].getSymbolInteger();
					j = m_mChildren[k].m_mChildren[1].getSymbolInteger();
					if((i >= 5001 && i < 6000 && i != 5002) && j == 6001){
						if(m_mChildren[k].m_mChildren[0].getSymbolInteger() == 5001 && 
							!((OSnLNodeNumber)m_mChildren[k].m_mChildren[0]).getNumberType().Equals("real")){
						}
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
							!((OSnLNodeNumber)m_mChildren[k].m_mChildren[1]).getNumberType().Equals("real")){
						;
						}
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
							!((OSnLNodeNumber)m_mChildren[k].m_mChildren[1]).getNumberType().Equals("real")){
						}
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

		/// <summary>
		/// Linearize the current node so that it doesn't contain linear terms.
		/// The expression tree of the node will become smaller if there are linear terms.
		/// If the node is fully linear, the node becomes null. If the node is not linear
		/// at all, it will remain the same and the returned hash map has a size zero.
		/// </summary>
		/// <returns>a hashmap of linear terms extracted out from this node,
		/// with keys being the variable indices and values being the variable coefficients.</returns>
		protected internal virtual Hashtable linearize(){//TODO
			Hashtable mapIndexCoef = new Hashtable();
			return mapIndexCoef;
		}//linearize

		/// <summary>
		/// Quadratize the current node, or make all the quadratic terms written in the
		/// form of a quadratic node with its children being the quadratic terms.
		/// </summary>
		/// <returns>whether there is conversion of some quadratic terms.</returns>
		protected internal virtual bool quadratize(){//TODO
			return false;
		}//quadratize

		/// <summary>
		/// Get an integer set of indices of the variables that exist in the current node.
		/// </summary>
		/// <returns>an integer set of indices of the variables that exist in the current node.</returns>
		/*
		protected internal virtual HashSet getVariableIndices(){
			HashSet indexSet = new HashSet();		
			if(getSymbolInteger() == 6001 && ((OSnLNodeVariable)this).getIndex() >= 0){
				indexSet.Add(((OSnLNodeVariable)this).getIndex());
			}
			else if(getSymbolInteger() == 9001){
				indexSet.Add(((OSnLNodeQpTerm)this).getVarOneIndex());
				indexSet.Add(((OSnLNodeQpTerm)this).getVarTwoIndex());
			}
			else{
				for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.Length); i++){
					indexSet.AddAll(m_mChildren[i].getVariableIndices());
				}
			}
			return indexSet;
		}//getVariableIndices
		*/
		/// <summary>
		/// Get the tree size, i.e. the number of nodes, of the tree.
		/// </summary>
		/// <returns>the tree size, i.e. the number of nodes, of the tree.</returns>
		protected internal virtual int getSize(){
			int iSize = 1;
			for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.Length); i++){
				iSize += m_mChildren[i].getSize();
			}
			return iSize;
		}//getSize

		/// <summary>
		/// Get the number of trigonometric functions in the tree.
		/// </summary>
		/// <returns>the number of trigonometric functions in the tree.</returns>
		protected internal virtual int getNumberOfTrigonometricFunctions(){
			int iSize = 0;
			if(getSymbolInteger() >= 3000 && getSymbolInteger() < 4000) iSize = 1;
			for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.Length); i++){
				iSize += m_mChildren[i].getNumberOfTrigonometricFunctions();
			}
			return iSize;
		}//getNumberOfTrigonometricFunctions

		/// <summary>
		/// Get the number of statistic functions in the tree.
		/// </summary>
		/// <returns>the number of statistic functions in the tree.</returns>
		protected internal virtual int getNumberOfStatisticFunctions(){
			int iSize = 0;
			if(getSymbolInteger() >= 4000 && getSymbolInteger() < 4400) iSize = 1;
			for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.Length); i++){
				iSize += m_mChildren[i].getNumberOfStatisticFunctions();
			}
			return iSize;
		}//getNumberOfStatisticFunctions

		/// <summary>
		/// Get the number of probability functions in the tree.
		/// </summary>
		/// <returns>the number of probability functions in the tree.</returns>
		protected internal virtual int getNumberOfProbabilityFunctions(){
			int iSize = 0;
			if(getSymbolInteger() >= 4400 && getSymbolInteger() < 5000) iSize = 1;
			for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.Length); i++){
				iSize += m_mChildren[i].getNumberOfProbabilityFunctions();
			}
			return iSize;
		}//getNumberOfProbabilityFunctions

		/// <summary>
		/// Get a set of number values that exist in the current node.
		/// </summary>
		/// <returns>a set of number values that exist in the current node.</returns>
		/*
		protected internal  virtual HashSet getNumberValues(){
			HashSet numberValueSet = new HashSet();
				if(getSymbolInteger() == 5001){
					numberValueSet.Add(((OSnLNodeNumber)this).getNumberValue());
				}
			if(getSymbolInteger() >= 5003 && getSymbolInteger() < 6000){
				numberValueSet.Add(getSymbol());
			}
			for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.Length); i++){
				numberValueSet.AddAll(m_mChildren[i].getNumberValues());
			}
			return numberValueSet;
		}//getNumberValues
	*/
//TODO all the following

/*
		/// <summary>
		/// Get a set of names of identifiers that exist in the current node.
		/// </summary>
		/// <returns>a set of names of identifiers that exist in the current node.</returns>
		protected internal virtual HashSet getIdentifiers(){
			HashSet nameSet = new HashSet();
				if(getSymbolInteger() == 5002){
					nameSet.Add(((OSnLNodeIdentifier)this).getIdentifierName());
				}
			for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.Length); i++){
				nameSet.AddAll(m_mChildren[i].getIdentifiers());
			}
			return nameSet;
		}//getIdentifiers

		/// <summary>
		/// Get a set of logic and relational operator symbols that exist in the current node.
		/// </summary>
		/// <returns>a set of logic and relational operator symbols that exist in the current node.</returns>
		protected internal virtual HashSet getLogicAndRelationalSymbols(){
			HashSet logicRelationalSet = new HashSet();
				if(getSymbolInteger() >= 7000 && getSymbolInteger() < 8000){
					logicRelationalSet.Add(getSymbol());
				}
			for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.Length); i++){
				logicRelationalSet.AddAll(m_mChildren[i].getLogicAndRelationalSymbols());
			}
			return logicRelationalSet;
		}//getLogicAndRelationalSymbols

		/// <summary>
		/// Get a set of quadratic terms that exist in the current node.
		/// </summary>
		/// <returns>a set of quadratic terms that exist in the current node.</returns>
		protected internal virtual HashSet getQuadraticTerms(){
			HashSet quadraticTermSet = new HashSet();
				if(getSymbolInteger() == 9001){
					string s = ((OSnLNodeQpTerm)this).getSymbol();
					quadraticTermSet.Add(s);
				}
			for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.Length); i++){
				quadraticTermSet.AddAll(m_mChildren[i].getQuadraticTerms());
			}
			return quadraticTermSet;
		}//getQuadraticTerms



		/// <summary>
		/// Get a set of names of the simulations that exist in the current node.
		/// </summary>
		/// <returns>a set of names of the simulations that exist in the current node.</returns>
		protected internal virtual HashSet getSimulationNames(){
			HashSet simNameSet = new HashSet();
				if(getSymbolInteger() == 9003){
					simNameSet.Add(((OSnLNodeSim)this).getSimName());
				}
			for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.Length); i++){
				simNameSet.AddAll(m_mChildren[i].getSimulationNames());
			}
			return simNameSet;
		}//getSimulationNames

		/// <summary>
		/// Get a set of names of the user defined functions that exist in the current node.
		/// </summary>
		/// <returns>a set of names of the user defined functions that exist in the current node.</returns>
		protected internal virtual HashSet getUserFunctionNames(){
			HashSet userFNameSet = new HashSet();
				if(getSymbolInteger() == 9006){
					userFNameSet.Add(((OSnLNodeUserF)this).getUserFName());
				}
			for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.Length); i++){
				userFNameSet.AddAll(m_mChildren[i].getUserFunctionNames());
			}
			return userFNameSet;
		}//getUserFunctionNames

		/// <summary>
		/// Get a set of XPaths that exist in the current node, each set member is of the form:
		/// uri:path, that is uri and path delimited by :.
		/// </summary>
		/// <returns>a set of XPaths that exist in the current node, each set member is of the form:
		/// uri:path, that is uri and path delimited by :.</returns>
		protected internal virtual HashSet getXPath(){
			HashSet xPathSetSet = new HashSet();
				if(getSymbolInteger() == 9008){
					string s = "";
					s+= ((OSnLNodeXPath)this).getURI() + ":";
					s+= ((OSnLNodeXPath)this).getPath();
					xPathSetSet.Add(s);
				}
			for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.Length); i++){
				xPathSetSet.AddAll(m_mChildren[i].getXPath());
			}
			return xPathSetSet;
		}//getXPath
		
		/// <summary>
		/// a set of network nodes that are referred in the current node, each set member is of the form:
		/// nodeName:propertyName, that is nodeName and property name delimited :.
		/// </summary>
		/// <returns>a set of network nodes that are referred in the current node, each set member is of the form:
		/// nodeName:propertyName, that is nodeName and property name delimited :.</returns>
		protected internal virtual HashSet getNetworkNodes(){
			HashSet nodeSet = new HashSet();
				if(getSymbolInteger() == 9010){
					string s = "";
					//s+= ((OSnLNodeNodeRef)this).getNodeName() + ":";
					//s+= ((OSnLNodeNodeRef)this).getPropName();
					nodeSet.Add(s);
				}
			for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.Length); i++){
				nodeSet.AddAll(m_mChildren[i].getNetworkNodes());
			}
			return nodeSet;
		}//getNetworkNodes

		/// <summary>
		/// a set of network arcs that are referred in the current arc, each set member is of the form:
		/// arcName:propertyName, that is arcName and property name delimited :.
		/// </summary>
		/// <returns>a set of network arcs that are referred in the current arc, each set member is of the form:
		/// arcName:propertyName, that is arcName and property name delimited :.</returns>
		protected internal virtual HashSet getNetworkArcs(){
			HashSet arcSet = new HashSet();
				if(getSymbolInteger() == 9011){
					string s = "";
					//s+= ((OSnLNodeArcRef)this).getArcName() + ":";
					//s+= ((OSnLNodeArcRef)this).getPropName();
					arcSet.Add(s);
				}
			for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.Length); i++){
				arcSet.AddAll(m_mChildren[i].getNetworkArcs());
			}
			return arcSet;
		}//getNetworkArcs

		/// <summary>
		/// Get the number of the complements operator in current node.
		/// </summary>
		/// <returns>the number of the complements operator in current node.</returns>
		protected internal virtual int getNumberOfComplementsOperator(){
			int iSize = 0;
			if(getSymbolInteger() == 9012) iSize = 1;
			for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.Length); i++){
				iSize += m_mChildren[i].getNumberOfComplementsOperator();
			}
			return iSize;
		}//getNumberOfComplementsOperator

		/// <summary>
		/// Get the number of the probability operator (usually in a chance constraint in current node.
		/// </summary>
		/// <returns>the number of the probability operator (usually in a chance constraint in current node.</returns>
		protected virtual int getNumberOfProbOperator(){
			int iSize = 0;
			if(getSymbolInteger() == 9013) iSize = 1;
			for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.Length); i++){
				iSize += m_mChildren[i].getNumberOfProbOperator();
			}
			return iSize;
		}//getNumberOfProbOperator

		/// <summary>
		/// Set the string values of OSnLNodeArg. 
		/// </summary>
		/// <param name="args">holds a string array of all args used in a userFunction. </param>
		protected internal virtual void setArgumentStringValues(string[] args){
			if(getSymbolInteger() == 9007){
				((OSnLNodeArg)this).m_sFunctionValue = args[((OSnLNodeArg)this).getArgumentIndex()];
			}
			else{
				for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.Length); i++){
					m_mChildren[i].setArgumentStringValues(args);
				}
			}
		}//setArgumentStringValues
*/
	}//class OSnLNode
}//namespace
