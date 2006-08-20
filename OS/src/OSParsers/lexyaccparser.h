/** @file lexyaccparser.h
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


 
#ifndef LEXYACCPARSER
#define LEXYACCPARSER

#include "OSInstance.h"
#include "OSResult.h"
#include "ErrorClass.h"

#include <string>

using std::cout;
using std::endl;
using std::ostringstream;


typedef struct yy_buffer_state *YY_BUFFER_STATE;
YY_BUFFER_STATE osrl_scan_string(const char* osrl ); 
YY_BUFFER_STATE osil_scan_string(const char* osil ); 
 //YY_BUFFER_STATE osil_scan_buffer(char *base, unsigned int size);
//void osil_delete_buffer( YY_BUFFER_STATE buffer);

// YY_BUFFER_STATE osol_scan_buffer(char *base, unsigned int size);
void osol_delete_buffer( YY_BUFFER_STATE buffer);

YY_BUFFER_STATE osss_scan_string(const char* osss ); 




int osrllex(void); 
int osillex(void);
int osollex(void);
int ossslex(void);

OSInstance *yygetOSInstance(const char *osil) throw(ErrorClass);
OSResult *yygetOSResult(std::string osrl);


void osilClearMemory();
void osilerror(const char* errormsg) ;
void osrlClearMemory();
void osrlerror(const char* errormsg);
void ossserror(const char* errormsg);
#endif 
