/** @file Base64.cpp
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

#include "OSBase64.h"
#include <sstream>  

/*
static const std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";
*/

namespace {

const char *base64_char_cstr = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";

}

std::string Base64::encodeb64(char* bytes, int string_size){
	unsigned char out_byte1, out_byte2, out_byte3, out_byte4;
	unsigned char in_byte1, in_byte2, in_byte3;

	const std::string base64_chars = base64_char_cstr ;

	std::ostringstream outStr;
	int remainder = string_size%3;
	// get a number divisible by 3
	int test = string_size - remainder;
	while(test > 0){
		in_byte1 = *(bytes++);
		in_byte2 = *(bytes++);
		in_byte3 = *(bytes++);
		out_byte1 = (in_byte1 >> 2);
		out_byte2 = (in_byte1 & 0x03) << 4 | (in_byte2 >> 4);
		out_byte3 = (in_byte2 & 0x0f) << 2 | (in_byte3 >> 6);
		out_byte4 = in_byte3 & 0x3f;
		outStr << base64_chars[out_byte1];
		outStr <<  base64_chars[out_byte2];  
		outStr << base64_chars[out_byte3];
		outStr << base64_chars[out_byte4]  ;
		test = test - 3;
	} 
	// now take care of padding
	if(remainder > 0){
		in_byte1 = *(bytes++);
		in_byte3 = '\0';
		out_byte1 = (in_byte1 >> 2);
		outStr << base64_chars[out_byte1];
		if(remainder == 1){
			in_byte2 = '\0';
			out_byte2 = (in_byte1 & 0x03) << 4 | (in_byte2 >> 4);
			outStr <<  base64_chars[out_byte2];  
			outStr << '=';
		}
		else{
			in_byte2 = *(bytes++);
			out_byte2 = (in_byte1 & 0x03) << 4 | (in_byte2 >> 4);
			out_byte3 = (in_byte2 & 0x0f) << 2 | (in_byte3 >> 6);
			outStr <<  base64_chars[out_byte2];  
			outStr << base64_chars[out_byte3];
		}
		outStr << '=';
	}
	return outStr.str();

}//encodeb64

std::string Base64::decodeb64(char* b64bytes){
	unsigned char out_byte1, out_byte2, out_byte3;
	unsigned char in_byte1, in_byte2, in_byte3, in_byte4;
	std::ostringstream outStr;

	const std::string base64_chars = base64_char_cstr ;

	// first take of the non-padded bytes
	while(*b64bytes != '=' && *b64bytes != '\0'){
		in_byte1 = base64_chars.find(*(b64bytes++));
		in_byte2 = base64_chars.find(*(b64bytes++));
		in_byte3 = base64_chars.find(*(b64bytes++));
		in_byte4 = base64_chars.find(*(b64bytes++));
		out_byte1 = (in_byte1 << 2)  | ((in_byte2 & 0x30)  >> 4)  ;
		out_byte2 = ((in_byte2 & 0x0f) << 4)  | ((in_byte3 & 0x3c)  >> 2)  ;
		out_byte3 = ((in_byte3  & 0x03) << 6)  |  in_byte4  ;
		outStr << out_byte1;
		outStr << out_byte2;  
		outStr << out_byte3;
	} 
	// now take into account the padding
	if(*b64bytes == '='){
		in_byte1 = base64_chars.find(*(b64bytes++));
		in_byte2 = base64_chars.find(*(b64bytes++));
		in_byte4 = '\0';
		out_byte1 = (in_byte1 << 2)  | ((in_byte2 & 0x30)  >> 4)  ;
		outStr << out_byte1;
		*b64bytes++;
		if(*b64bytes == '\0'){ //if null we had only one = in the padding
			in_byte3 = base64_chars.find(*(b64bytes++));
			out_byte2 = ((in_byte2 & 0x0f) << 4)  | ((in_byte3 & 0x3c)  >> 2)  ;
			out_byte3 = ((in_byte3  & 0x03) << 6)  |  in_byte4  ;
			outStr << out_byte2;  
		}
		else{ // we have == in the padding
			in_byte3 = '\0';
			out_byte2 = ((in_byte2 & 0x0f) << 4)  | ((in_byte3 & 0x3c)  >> 2)  ;
			out_byte3 = ((in_byte3  & 0x03) << 6)  |  in_byte4  ;
			//outStr << out_byte2;  
			//outStr << out_byte3;
		}
	}
	return outStr.str();
} // decodeb64



