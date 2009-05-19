/** @file CommonUtil.cpp
 * 
 * @author  Robert Fourer,  Jun Ma, Kipp Martin, 
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005, Robert Fourer, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 * <p>The <code>CommonUtil</code> class contains methods for performing
 * common operations used by many classes in the
 * Optimization Services (OS) framework. </p>
 *
 */

#include "OSCommonUtil.h"
//using namespace std;

CommonUtil::CommonUtil(){
}

CommonUtil::~CommonUtil(){
}


/* below is the CoinUtils implementation
inline bool CoinIsnan(double val)
{
#ifdef MY_C_ISNAN
  //    return static_cast<bool>(MY_C_ISNAN(val));
    return MY_C_ISNAN(val)!=0;
#else
    return false;
#endif
}
*/


	
//bool CommonUtil::ISOSNAN( double number){
// copy from CoinUtils	-- CoinFinite.hpp
//#ifdef MY_C_ISNAN
//	if(MY_C_ISNAN( number) == true){
//		return true;
//	}
//	else return(number == OSNAN);
//#else
	//#ifdef NAN 
	//	return isnan( number);
	//#elif defined NaN
	//	return isnan( number);
	//#elif defined nan
	//	return isnan( number);
	//#else
	//	return (number == OSNAN);
	//#endif
//	return (number == OSNAN);
//#endif
//}



