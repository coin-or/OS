/* --------------------------------------------------------------------------
CppAD: C++ Algorithmic Differentiation: Copyright (C) 2003-06 Bradley M. Bell

CppAD is distributed under multiple licenses. This distribution is under
the terms of the 
                    Common Public License Version 1.0.

A copy of this license is included in the COPYING file of this distribution.
Please visit http://www.coin-or.org/CppAD/ for information on other licenses.
-------------------------------------------------------------------------- */
/*
$begin StackMachine.cpp$$
$spell
$$

$section Example Differentiating a Stack Machine Interpreter$$

$index interpreter, example$$
$index example, interpreter$$
$index test, interpreter$$

$code
$verbatim%Example/StackMachine.cpp%0%// BEGIN PROGRAM%// END PROGRAM%1%$$
$$

$end
*/
// BEGIN PROGRAM

# include <cstddef>
# include <cstdlib>
# include <cctype>
# include <cassert>
# include <stack>

# include <CppAD/CppAD.h>

#include "OSnLNode.h"
#include <vector>  

using std::cout;
using std::endl;
 
namespace OSAD{ 
// Begin empty namespace ------------------------------------------------

bool is_number( const std::string &s )
{	char ch = s[0];
	bool number = strchr("0123456789.", ch);
	return number;
}
bool is_binary( const std::string &s )
{	char ch = s[0];
	bool binary = strchr("+-*/.", ch);
	return binary;
}
bool is_variable( const std::string &s )
{	char ch = s[0];
	bool variable = 'a' <= ch & ch <= 'z';
	return variable;
}

CppAD::AD<double> StackMachine( 
	std::stack< std::string >  &token_stack,
	CppAD::vector< CppAD::AD<double> > &variable, std::vector<OSnLNode*> postFixVec)
{	using std::string;
	using std::stack;
	using CppAD::AD;
	stack< AD<double> > value_stack;
	string   token;
	AD<double>  value_one;
	AD<double>  value_two;
	// comment out Brad's code
	/*while( ! token_stack.empty() )
	{	string s = token_stack.top();
		token_stack.pop();

		if( is_number(s) ){
			value_one = std::atof( s.c_str() );
			value_stack.push( value_one );
		}
		else if( is_variable(s) ){
			value_one = variable[ size_t(s[0]) - size_t('a') ];
			value_stack.push( value_one );
		}
		else if( is_binary(s) ) {
			assert( value_stack.size() >= 2 );
			value_one = value_stack.top();
			value_stack.pop();
			value_two = value_stack.top();
			value_stack.pop();
			switch( s[0] )
			{
				case '+':
				value_stack.push(value_one + value_two);
				break;

				case '-':
				value_stack.push(value_one - value_two);
				break;

				case '*':
				value_stack.push(value_one * value_two);
				break;

				case '/':
				value_stack.push(value_one / value_two);
				break;

				default:
				assert(0);
			}
		}//end if(is_binary)
	}// end while
	// now get the top of the stack
	assert( value_stack.size() >= 1 ); 	
	value_one = value_stack.top();
	value_stack.pop();
	return value_one;
	*/
	// put in the OS code -- Brad's code modified by Kipp and Jun
	int iVecSize = postFixVec.size();
	int iNodeID;
	int i;
	if(iVecSize > 0){
		for(i = 0; i < iVecSize; i++){ 
			iNodeID = postFixVec[i]->inodeInt;
			std::cout << "NODE ID = " << iNodeID<< std::endl;
			if(iNodeID == OS_NUMBER){
				OSnLNodeNumber *numNode;
				numNode = (OSnLNodeNumber*)postFixVec[i];
				value_one = numNode->value;
				value_stack.push( value_one );	
			}
			else if(iNodeID == OS_VARIABLE){
					OSnLNodeVariable *varNode;
					varNode = (OSnLNodeVariable*)postFixVec[i];
					// If the variable has a coefficient other than 1 push back 
					// that coefficient plus a multiplier
					if(varNode->coef != 1){
					// Kipp -- fix this -- we need coef != 1
					//	push back the number
					//	insList.push_back( EP_PUSH_NUM );
					//	pos = mapNewNumber.find( varNode->coef);
					//	if(pos == mapNewNumber.end() ){
					//		cout << "FOUND A NEW NUMBER  " << varNode->coef << endl;
					//		insList.push_back( iNumNonlinearNonz);
					//		mapNewNumber[ varNode->coef] =  iNumNonlinearNonz++;
					//	}
					//	else insList.push_back( pos->second);	
					//	insList.push_back( EP_MULTIPLY);
					}
					else{
					// for now assume coefficient is 1
					value_one = variable[ varNode->idx ];
					value_stack.push( value_one );
					}
			}
			else if(postFixVec[i]->inumberOfChildren == 2){
				assert( value_stack.size() >= 2 );
				value_two = value_stack.top();
				value_stack.pop();
				value_one = value_stack.top();
				value_stack.pop();
				std::cout << "value_one = " << value_one <<  std::endl;
				std::cout << "value_two = " << value_two <<  std::endl;
				switch (iNodeID){
					case OS_PLUS:  // the plus token
						value_stack.push(value_one + value_two);
						break;
					case OS_MINUS:  // the minus token
						value_stack.push(value_one - value_two);
						break;
					case OS_TIMES:  // the times token
						value_stack.push(value_one * value_two);
						break;
					case OS_DIVIDE:  // the divide token
						value_stack.push(value_one / value_two);
						break;
					case OS_POWER:  // the power token
						value_stack.push(CppAD::pow(value_one, value_two));						
						break;
					default:
						// throw an exception if here;
						//throw ErrorClass("Error: Put in appropriate message");					
						break;
				}//end switch
			}
			else if(postFixVec[i]->inumberOfChildren == 1){
				assert( value_stack.size() >= 1 );
				value_one = value_stack.top();
				value_stack.pop();
				switch (iNodeID){
					case OS_LN:  
						value_stack.push(CppAD::log(value_one) );
						break;
					case OS_EXP:  
						value_stack.push(CppAD::exp(value_one) );
						break;
					default:
						// throw an exception if here;
						break;
				}//end switch
			}
			else if(postFixVec[i]->inumberOfChildren == 0){
				switch (iNodeID){
					case OS_SUM:  // the sum token
						// kipp - implement this
						//insList.push_back( nlNodeIdxLindo[ OS_SUM] );
						//insList.push_back( postFixVec[i]->inumberOfChildren);
						//cout <<  "PUSH BACK A SUM" << endl;
						break;
					case OS_MAX:  // the max token
						//insList.push_back( nlNodeIdxLindo[ OS_MAX] );
						//insList.push_back( postFixVec[i]->inumberOfChildren);
						//cout <<  "PUSH BACK A MAX" << endl;
						break;
					case OS_PRODUCT:  // the product token
						//throw ErrorClass("Error: OS_PRODUCT operator not supported by CppAD");					
						break;
					default:
						// throw an exception if here;
						break;
				}//end switch
			}
			else{
				// throw an error we should not be here
			}
		}//end for loop over the postfix vector of OSnLNodes	 
	}// end if(iVecSize > 0)
	assert( value_stack.size() >= 1 ); 	
	value_one = value_stack.top();
	return value_one;
}// end StackMachine
}//end OSAD namespace
// END PROGRAM
