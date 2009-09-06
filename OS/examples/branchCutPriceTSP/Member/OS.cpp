// Copyright (C) 2003, International Business Machines
// Corporation and others.  All Rights Reserved.

#include "OS.hpp"
#include "CoinPackedMatrix.hpp"

/****************************************************************************/
OS_prob::OS_prob() :
	EPSILON(1e-8),
	osinstance( NULL),
	osilreader( NULL),
  
	ttlcuts(0),
	conscount(0),
	initialcons(0),

	haveBranched( false)
	
	

	
 {
addtxtstr << "";
}

/****************************************************************************/
OS_prob::~OS_prob()
{
	std::cout << "inside OS_prob destructor" << std::endl;

}
