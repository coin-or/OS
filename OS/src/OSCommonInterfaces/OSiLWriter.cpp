/** @file OSiLWriter.cpp
 * 
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

#include "OSiLWriter.h"
#include "OSInstance.h"
#include "OSParameters.h" 
#include "OSCommonUtil.h"
#include "OSBase64.h"
#include "OSMathUtil.h"

#include <sstream>  

using std::cout;
using std::endl;
using std::ostringstream; 

//#define USE_DTOA


OSiLWriter::OSiLWriter( ) {	
	m_bWriteBase64 = false;
	m_bWhiteSpace = false;
}

OSiLWriter::~OSiLWriter(){
}

std::string OSiLWriter::writeOSiL( const OSInstance *theosinstance){

	m_OSInstance = theosinstance;
	ostringstream outStr;
	int i, j;
	if(m_OSInstance == NULL)  return outStr.str();
	outStr << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" ;
	outStr << "<osil xmlns=\"os.optimizationservices.org\"   xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" ";
	outStr << "xsi:schemaLocation=\"os.optimizationservices.org http://www.optimizationservices.org/schemas/";
	outStr << OS_SCHEMA_VERSION;
	outStr << "/OSiL.xsd\" >" ;
	outStr << "<instanceHeader>" ;
	if( m_bWhiteSpace == true) outStr << endl;
	if(m_OSInstance->instanceHeader != NULL){
		if(m_OSInstance->instanceHeader->name.length() > 0){
			outStr << "<name>" + m_OSInstance->instanceHeader->name + "</name>"  ;
		}

		if(m_OSInstance->instanceHeader->source.length() > 0){
			outStr << "<source>" + m_OSInstance->instanceHeader->source + "</source>"  ;
		}
		if(m_OSInstance->instanceHeader->description.length() > 0){
			outStr << "<description>" + m_OSInstance->instanceHeader->description  + "</description>";
		}
	}
	outStr << "</instanceHeader>" ;
	if( m_bWhiteSpace == true) outStr << endl;
	if(m_OSInstance->instanceData != NULL){
		outStr << "<instanceData>" ;
		if( m_bWhiteSpace == true) outStr << endl;
		if(m_OSInstance->instanceData->variables != NULL && m_OSInstance->instanceData->variables->numberOfVariables > 0){
			outStr << "<variables " ;
			outStr << "numberOfVariables=\"";
			outStr << m_OSInstance->instanceData->variables->numberOfVariables ;
			outStr << "\"" ;
			outStr << ">" ;
			if( m_bWhiteSpace == true) outStr << endl;
			// get variable information
			for(i = 0; i < m_OSInstance->instanceData->variables->numberOfVariables; i++){
				if(m_OSInstance->instanceData->variables->var[i] != NULL){
					outStr << "<var" ;
					if(m_OSInstance->instanceData->variables->var[i]->name.length() > 0){
						outStr << " name=\"" ;
						outStr << m_OSInstance->instanceData->variables->var[i]->name ;
						outStr <<  "\"";
					}
					if( m_OSInstance->instanceData->variables->var[i]->type != 'C'){
						outStr << " type=\"" ;
						outStr << m_OSInstance->instanceData->variables->var[i]->type ;
						outStr <<  "\"";
					}
					if( m_OSInstance->instanceData->variables->var[i]->lb != 0.0){
						outStr << " lb=\"" ;
						outStr << os_dtoa_format( m_OSInstance->instanceData->variables->var[i]->lb) ;
						outStr <<  "\"";  
					}
					if( m_OSInstance->instanceData->variables->var[i]->ub != OSDBL_MAX
						&& m_OSInstance->instanceData->variables->var[i]->ub != OSNAN ) {
						outStr << " ub=\"" ;
						outStr << os_dtoa_format( m_OSInstance->instanceData->variables->var[i]->ub) ;
						outStr <<  "\"";
					}
					/* we no longer do init
					if(CommonUtil::ISOSNAN(m_OSInstance->instanceData->variables->var[i]->init) == false){
						outStr << " init=\"" ;
						outStr << os_dtoa_format(m_OSInstance->instanceData->variables->var[i]->init) ;
						outStr <<  "\"";
					}
					
					if(m_OSInstance->instanceData->variables->var[i]->initString != ""){
						outStr << " initString=\"" ;
						outStr << m_OSInstance->instanceData->variables->var[i]->initString ;
						outStr <<  "\"";
					}
					*/
					outStr << "/>" ;
					if( m_bWhiteSpace == true) outStr << endl;
				}
			} // end the for loop
			outStr << "</variables>" ;
			if( m_bWhiteSpace == true) outStr << endl;
		}
		if(m_OSInstance->instanceData->objectives != NULL && m_OSInstance->instanceData->objectives->numberOfObjectives > 0){
			outStr << "<objectives " ; 
			outStr << "numberOfObjectives=\"";
			outStr << m_OSInstance->instanceData->objectives->numberOfObjectives ;
			outStr << "\"" ;
			outStr << ">" ;
			if( m_bWhiteSpace == true) outStr << endl;
			for (j = 0; j < m_OSInstance->instanceData->objectives->numberOfObjectives; j++){
				if(m_OSInstance->instanceData->objectives->obj[j] != NULL){
					outStr << "<obj" ;
					if(m_OSInstance->instanceData->objectives->obj[j]->maxOrMin.length() > 0){
						outStr << " maxOrMin=\"" ;
						outStr << m_OSInstance->instanceData->objectives->obj[j]->maxOrMin  ;
						outStr <<  "\"";
					}
					if(m_OSInstance->instanceData->objectives->obj[j]->constant != 0.0){
						outStr << " constant=\"" ;
						outStr <<  os_dtoa_format(m_OSInstance->instanceData->objectives->obj[j]->constant)  ;
						outStr <<  "\"";
					}
					if(m_OSInstance->instanceData->objectives->obj[j]->weight != 1.0){
						outStr << " weight=\"" ;
						outStr <<  os_dtoa_format(m_OSInstance->instanceData->objectives->obj[j]->weight)  ;
						outStr <<  "\"";
					}
					if(m_OSInstance->instanceData->objectives->obj[j]->name.length() > 0){
						outStr << " name=\"" ;
						outStr <<  m_OSInstance->instanceData->objectives->obj[j]->name  ;
						outStr <<  "\"";
					}
					outStr << " numberOfObjCoef=\"" ;
					outStr <<  m_OSInstance->instanceData->objectives->obj[j]->numberOfObjCoef  ;
					outStr <<  "\"";
					outStr << ">" ;
					if( m_bWhiteSpace == true) outStr << endl;
					if(m_OSInstance->instanceData->objectives->obj[j]->coef != NULL){
						for (i = 0; i < m_OSInstance->instanceData->objectives->obj[ j]->numberOfObjCoef; i++){
							if(m_OSInstance->instanceData->objectives->obj[j]->coef[i]->idx > -1 ){
								outStr << "<coef" ;
								outStr << " idx=\"" ;
								outStr <<  m_OSInstance->instanceData->objectives->obj[j]->coef[i]->idx ;
								outStr <<  "\"";
								outStr << ">";
								//
								//
								outStr << os_dtoa_format( m_OSInstance->instanceData->objectives->obj[j]->coef[i]->value) ;
								//outStr << m_OSInstance->instanceData->objectives->obj[j]->coef[i]->value ;
								outStr << "</coef>" ;
								if( m_bWhiteSpace == true) outStr << endl;
							}
						}
					}
					outStr << "</obj>" ;
					if( m_bWhiteSpace == true) outStr << endl;
				}
			}
			outStr << "</objectives>" ;
			if( m_bWhiteSpace == true) outStr << endl;
		}
		// Now the constraints
		if(m_OSInstance->instanceData->constraints != NULL && m_OSInstance->instanceData->constraints->numberOfConstraints > 0){
			outStr << "<constraints " ;
			outStr << "numberOfConstraints=\"";
			outStr << m_OSInstance->instanceData->constraints->numberOfConstraints ;
			outStr << "\"" ;
			outStr << ">" ;
			if( m_bWhiteSpace == true) outStr << endl;
			for (i = 0; i < m_OSInstance->instanceData->constraints->numberOfConstraints; i++){
				if(m_OSInstance->instanceData->constraints->con[i] != NULL){
					outStr << "<con" ; 
					if(m_OSInstance->instanceData->constraints->con[i]->name.length()){
						outStr << " name=\"" ;
						outStr << m_OSInstance->instanceData->constraints->con[i]->name ;
						outStr <<  "\"";
					}
					if(m_OSInstance->instanceData->constraints->con[i]->constant != 0){
						outStr << " constant=\"" ;
						outStr << os_dtoa_format( m_OSInstance->instanceData->constraints->con[i]->constant) ;
						outStr <<  "\"";
					}
					if(m_OSInstance->instanceData->constraints->con[i]->lb != -OSDBL_MAX ){
						outStr << " lb=\"" ;
						outStr << os_dtoa_format( m_OSInstance->instanceData->constraints->con[i]->lb) ;
						outStr <<  "\"";
					}
					if(m_OSInstance->instanceData->constraints->con[i]->ub != OSDBL_MAX){
						outStr << " ub=\"" ;
						outStr << os_dtoa_format( m_OSInstance->instanceData->constraints->con[i]->ub) ;
						outStr <<  "\"";
					}
					outStr << "/>" ;
					if( m_bWhiteSpace == true) outStr << endl;
				}
			}
		outStr << "</constraints>" ;
		if( m_bWhiteSpace == true) outStr << endl;
		}
		// now the linearConstraintsCoefficients
		if(m_OSInstance->instanceData->linearConstraintCoefficients != NULL && m_OSInstance->instanceData->linearConstraintCoefficients->numberOfValues > 0){
			outStr << "<linearConstraintCoefficients " ;
			outStr << "numberOfValues=\"";
			outStr << m_OSInstance->instanceData->linearConstraintCoefficients->numberOfValues ;
			outStr << "\"" ;
			outStr << ">" ;
			if( m_bWhiteSpace == true) outStr << endl;
			if( (m_OSInstance->instanceData->linearConstraintCoefficients->rowIdx != NULL) &&
				(m_OSInstance->instanceData->linearConstraintCoefficients->rowIdx->el != NULL) ){
					if(m_OSInstance->instanceData->linearConstraintCoefficients->start->el != NULL){
						outStr << "<start>" ;
						if( m_bWhiteSpace == true) outStr << endl;
						if(m_OSInstance->instanceData->variables != NULL && m_OSInstance->instanceData->variables->numberOfVariables > 0){
							if(m_bWriteBase64 == false){
								for(i = 0; i <= m_OSInstance->instanceData->variables->numberOfVariables; i++){
									outStr << "<el>" ;
									outStr << m_OSInstance->instanceData->linearConstraintCoefficients->start->el[i];
									outStr << "</el>" ;
									if( m_bWhiteSpace == true) outStr << endl;
								}
							}
							else{
								//outStr << "<base64BinaryData sizeOf=\"4\" numericType=\"int\" >" ;
								outStr << "<base64BinaryData sizeOf=\"4\"  >" ;
								outStr << Base64::encodeb64( (char*)m_OSInstance->instanceData->linearConstraintCoefficients->start->el, 
									(m_OSInstance->instanceData->variables->numberOfVariables + 1)*sizeof(int) );
								outStr<< "</base64BinaryData>" ;
								if( m_bWhiteSpace == true) outStr << endl;
							}
						}
						outStr << "</start>" ;
						if( m_bWhiteSpace == true) outStr << endl;
					}
					outStr << "<rowIdx>" ;
					if( m_bWhiteSpace == true) outStr << endl;
					if(m_bWriteBase64 == false){		
						for(i = 0; i < m_OSInstance->instanceData->linearConstraintCoefficients->numberOfValues; i++){
							outStr << "<el>" ;
							outStr << m_OSInstance->instanceData->linearConstraintCoefficients->rowIdx->el[i] ;
							outStr << "</el>"  ;
							if( m_bWhiteSpace == true) outStr << endl;
						}
					}
					else{
						//outStr << "<base64BinaryData sizeOf=\"4\" numericType=\"int\" >" ;
						outStr << "<base64BinaryData sizeOf=\"4\"  >" ;
						outStr << Base64::encodeb64( (char*)m_OSInstance->instanceData->linearConstraintCoefficients->rowIdx->el, 
							m_OSInstance->instanceData->linearConstraintCoefficients->numberOfValues*sizeof(int) );
						outStr<< "</base64BinaryData>" ;
						if( m_bWhiteSpace == true) outStr << endl;
					}
					outStr << "</rowIdx>" ;
					if( m_bWhiteSpace == true) outStr << endl;
			}
			else{
				if( (m_OSInstance->instanceData->linearConstraintCoefficients->colIdx != NULL)  &&
					(m_OSInstance->instanceData->linearConstraintCoefficients->colIdx->el != NULL) ){
						if(m_OSInstance->instanceData->linearConstraintCoefficients->start->el != NULL){
							outStr << "<start>" ;
							if( m_bWhiteSpace == true) outStr << endl;
							if(m_OSInstance->instanceData->constraints != NULL && m_OSInstance->instanceData->constraints->numberOfConstraints > 0){
								if(m_bWriteBase64 == false){
									for(i = 0; i <= m_OSInstance->instanceData->constraints->numberOfConstraints; i++){
										outStr << "<el>" ;
										outStr << m_OSInstance->instanceData->linearConstraintCoefficients->start->el[i];
										outStr << "</el>" ;
										if( m_bWhiteSpace == true) outStr << endl;
									}
								}
								else{
									//outStr << "<base64BinaryData sizeOf=\"4\" numericType=\"int\" >" ;
									outStr << "<base64BinaryData sizeOf=\"4\"  >" ;
									outStr << Base64::encodeb64( (char*)m_OSInstance->instanceData->linearConstraintCoefficients->start->el, 
										(m_OSInstance->instanceData->variables->numberOfVariables + 1)*sizeof(int) );
									outStr<< "</base64BinaryData>" ;
									if( m_bWhiteSpace == true) outStr << endl;
								}
							}
							outStr << "</start>" ;
							if( m_bWhiteSpace == true) outStr << endl;
						}
						outStr << "<colIdx>";
						if( m_bWhiteSpace == true) outStr << endl;
						if(m_bWriteBase64 == false){
							for(i = 0; i < m_OSInstance->instanceData->linearConstraintCoefficients->numberOfValues; i++){
								outStr << "<el>" ;
								outStr << m_OSInstance->instanceData->linearConstraintCoefficients->colIdx->el[i] ;
								outStr << "</el>"  ;
								if( m_bWhiteSpace == true) outStr << endl;
							}
						}
						else{
							//outStr << "<base64BinaryData sizeOf=\"4\" numericType=\"int\" >" ;
							outStr << "<base64BinaryData sizeOf=\"4\"  >" ;
							outStr << Base64::encodeb64( (char*)m_OSInstance->instanceData->linearConstraintCoefficients->colIdx->el, 
								m_OSInstance->instanceData->linearConstraintCoefficients->numberOfValues*sizeof(int) );
							outStr<< "</base64BinaryData>" ;
							if( m_bWhiteSpace == true) outStr << endl;
						}
						outStr << "</colIdx>" ;
						if( m_bWhiteSpace == true) outStr << endl;
					}
			}
			if(m_OSInstance->instanceData->linearConstraintCoefficients->value != NULL){
				outStr << "<value>" ;
				if( m_bWhiteSpace == true) outStr << endl;
				if(m_OSInstance->instanceData->linearConstraintCoefficients->value->el != NULL){
					if(m_bWriteBase64 == false){
						for(i = 0; i < m_OSInstance->instanceData->linearConstraintCoefficients->numberOfValues; i++){
							outStr << "<el>";
							outStr <<   os_dtoa_format( m_OSInstance->instanceData->linearConstraintCoefficients->value->el[i] );
							//outStr <<   m_OSInstance->instanceData->linearConstraintCoefficients->value->el[i] ;
							outStr << "</el>" ;
							if( m_bWhiteSpace == true) outStr << endl;		
						}
					}
					else{
						//outStr << "<base64BinaryData sizeOf=\"8\" numericType=\"double\" >" ;
						outStr << "<base64BinaryData sizeOf=\"8\"  >" ;
						outStr << Base64::encodeb64( (char*)m_OSInstance->instanceData->linearConstraintCoefficients->value->el, 
							m_OSInstance->instanceData->linearConstraintCoefficients->numberOfValues*sizeof( double) );
						outStr<< "</base64BinaryData>" ;
						if( m_bWhiteSpace == true) outStr << endl;
					}
				}
				outStr << "</value>" ;
				if( m_bWhiteSpace == true) outStr << endl;
			}
			outStr << "</linearConstraintCoefficients>" ;
			if( m_bWhiteSpace == true) outStr << endl;
		}
		if(m_OSInstance->instanceData->quadraticCoefficients != NULL && m_OSInstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms > 0){
			outStr << "<quadraticCoefficients";
			outStr << "  numberOfQuadraticTerms=\"";
			outStr << m_OSInstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms;
			outStr << "\" >"  ;
			if( m_bWhiteSpace == true) outStr << endl;
			for(i = 0; i < m_OSInstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms; i++){
				if(m_OSInstance->instanceData->quadraticCoefficients->qTerm[i]){
					outStr << "<qTerm" ;
					// the following attributes are required 
					outStr << "  idx=\"";
					outStr << m_OSInstance->instanceData->quadraticCoefficients->qTerm[i]->idx;
					outStr << "\"";
					outStr << "  idxOne=\"";
					outStr << m_OSInstance->instanceData->quadraticCoefficients->qTerm[i]->idxOne;
					outStr << "\"";
					outStr << "  idxTwo=\"";
					outStr << m_OSInstance->instanceData->quadraticCoefficients->qTerm[i]->idxTwo;
					outStr << "\"";
					if(m_OSInstance->instanceData->quadraticCoefficients->qTerm[i]->coef != 0){
						outStr << "  coef=\"";
						outStr << m_OSInstance->instanceData->quadraticCoefficients->qTerm[i]->coef;
						outStr << "\"";
					}
					outStr << "/>" ;
					if( m_bWhiteSpace == true) outStr << endl;
				}
			} 
			outStr << "</quadraticCoefficients>";
			if( m_bWhiteSpace == true) outStr << endl;
		}
		if(m_OSInstance->instanceData->nonlinearExpressions != NULL && m_OSInstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions > 0){	
			outStr << "<nonlinearExpressions";
			outStr << "  numberOfNonlinearExpressions=\"";
			outStr << m_OSInstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions;
			outStr << "\" >"  ;
			if( m_bWhiteSpace == true) outStr << endl;
			for(i = 0; i < m_OSInstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions; i++){
				if(m_OSInstance->instanceData->nonlinearExpressions->nl[i] != NULL){
					outStr << "<nl" ;
					// the following attribute is required 
					outStr << "  idx=\"";
					outStr << m_OSInstance->instanceData->nonlinearExpressions->nl[i]->idx;
					outStr << "\">";
					if(m_OSInstance->instanceData->nonlinearExpressions->nl[i]->osExpressionTree->m_treeRoot != NULL)
					outStr << m_OSInstance->instanceData->nonlinearExpressions->nl[i]->osExpressionTree->m_treeRoot->getNonlinearExpressionInXML();
					outStr << "</nl>";
				}
				if( m_bWhiteSpace == true) outStr << endl;
			}
			outStr << "</nonlinearExpressions>";
			if( m_bWhiteSpace == true) outStr << endl;
		}	
		outStr << "</instanceData>"  ;
		if( m_bWhiteSpace == true) outStr << endl;
	} // end instanceData if
	outStr << "</osil>" ;
	if( m_bWhiteSpace == true) outStr << endl;
	outStr << endl;
	return outStr.str();
} // end writeOSiL
