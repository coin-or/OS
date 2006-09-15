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

void StackMachine( 
	std::stack< std::string >  &token_stack  ,
	CppAD::vector< CppAD::AD<double> > &variable )
{	using std::string;
	using std::stack;

	using CppAD::AD;

	stack< AD<double> > value_stack;
	string   token;
	AD<double>  value_one;
	AD<double>  value_two;

	while( ! token_stack.empty() )
	{	string s = token_stack.top();
		token_stack.pop();

		if( is_number(s) )
		{	value_one = std::atof( s.c_str() );
			value_stack.push( value_one );
		}
		else if( is_variable(s) )
		{	value_one = variable[ size_t(s[0]) - size_t('a') ];
			value_stack.push( value_one );
		}
		else if( is_binary(s) ) 
		{	assert( value_stack.size() >= 2 );
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
		}
		else if( s[0] == '=' )
		{	assert( value_stack.size() >= 1 ); 	
			assert( token_stack.size() >= 1 );
			//
			s = token_stack.top();
			token_stack.pop();
			//
			assert( is_variable( s ) );
			value_one = value_stack.top();
			value_stack.pop();
			//
			variable[ size_t(s[0]) - size_t('a') ] = value_one;
		}
		else assert(0);
	}
	return;
}

// End OSAD namespace ---------------------------------------------
}

// END PROGRAM
