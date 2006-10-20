/** @file CommonUtil.h
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
 */



#ifndef COMMONUTIL_H
#define COMMONUTIL_H

 #include "OSParameters.h"

/**
 *
 * <p>The <code>CommonUtil</code> class contains methods for performing
 * common operations used by many classes in the
 * Optimization Services (OS) framework. </p>
 *
 */
class CommonUtil{
	public:
	/**
	 * Constructor.
	 *
	 */
	CommonUtil();
	~CommonUtil();

	static bool ISOSNAN( double number);

};//class CommonUtil
#endif
