/* $Id$ */
/** @file OSiLWriter.cpp
 *
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2015, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */

#include "OSiLWriter.h"
#include "OSStringUtil.h"
#include "OSInstance.h"
#include "OSParameters.h"
#include "OSBase64.h"
#include "OSMathUtil.h"
#include "CoinFinite.hpp"

#include <sstream>

using std::endl;
using std::ostringstream;


OSiLWriter::OSiLWriter( )
{
    m_bWriteBase64 = false;
    m_bWhiteSpace = false;
}

OSiLWriter::~OSiLWriter()
{
}

std::string OSiLWriter::writeOSiL( const OSInstance *theosinstance)
{
    m_OSInstance = theosinstance;
    ostringstream outStr;
    int i, j, k, kk;
    int mult;
    int incr;
    std::string tmpname, tmpsense;
    double tmplb, tmpub, tmpconst, tmpweight;
    char tmptype;
    int tmpnum;

    if(m_OSInstance == NULL)  return outStr.str();
    outStr << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" ;
    if( m_bWhiteSpace == true) outStr << endl;
    outStr << "<osil xmlns=\"os.optimizationservices.org\"   xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" ";
    outStr << "xsi:schemaLocation=\"os.optimizationservices.org http://www.optimizationservices.org/schemas/";
    outStr << OS_SCHEMA_VERSION;
    outStr << "/OSiL.xsd\" >" ;
    if( m_bWhiteSpace == true) outStr << endl;
    outStr << "<instanceHeader>";
    if( m_bWhiteSpace == true) outStr << endl;
    if(m_OSInstance->instanceHeader != NULL)
    {
        if(m_OSInstance->instanceHeader->name.length() > 0)
        {
            outStr << "<name>" + m_OSInstance->instanceHeader->name + "</name>"  ;
            if( m_bWhiteSpace == true) outStr << endl;
        }

        if(m_OSInstance->instanceHeader->source.length() > 0)
        {
            outStr << "<source>" + m_OSInstance->instanceHeader->source + "</source>"  ;
            if( m_bWhiteSpace == true) outStr << endl;
        }
        if(m_OSInstance->instanceHeader->description.length() > 0)
        {
            outStr << "<description>" + m_OSInstance->instanceHeader->description  + "</description>";
            if( m_bWhiteSpace == true) outStr << endl;
        }
        if(m_OSInstance->instanceHeader->fileCreator.length() > 0)
        {
            outStr << "<fileCreator>" + m_OSInstance->instanceHeader->fileCreator  + "</fileCreator>";
            if( m_bWhiteSpace == true) outStr << endl;
        }
        if(m_OSInstance->instanceHeader->licence.length() > 0)
        {
            outStr << "<licence>" + m_OSInstance->instanceHeader->licence  + "</licence>";
            if( m_bWhiteSpace == true) outStr << endl;
        }
    }
    outStr << "</instanceHeader>" ;
    if( m_bWhiteSpace == true) outStr << endl;
    outStr << "<instanceData>" ;
    if(m_OSInstance->instanceData != NULL)
    {
        if( m_bWhiteSpace == true) outStr << endl;
        if(m_OSInstance->instanceData->variables != NULL && m_OSInstance->instanceData->variables->numberOfVariables > 0)
        {
            outStr << "<variables " ;
            outStr << "numberOfVariables=\"";
            outStr << m_OSInstance->instanceData->variables->numberOfVariables ;
            outStr << "\"" ;
            outStr << ">" ;
            if (m_bWhiteSpace == true) outStr << endl;
            // get variable information
            for (i = 0; i < m_OSInstance->instanceData->variables->numberOfVariables;)
            {
                mult = 1;
                if (m_OSInstance->instanceData->variables->var[i] != NULL)
                {
                    if (i < m_OSInstance->instanceData->variables->numberOfVariables - 1)
                    {
                        tmpname = m_OSInstance->instanceData->variables->var[i]->name;
                        tmptype = m_OSInstance->instanceData->variables->var[i]->type;
                        tmplb   = m_OSInstance->instanceData->variables->var[i]->lb;
                        tmpub   = m_OSInstance->instanceData->variables->var[i]->ub;
                        for (k=i+1; k < m_OSInstance->instanceData->variables->numberOfVariables; k++)
                        {
                            if (tmpname != m_OSInstance->instanceData->variables->var[k]->name) break;
                            if (tmptype != m_OSInstance->instanceData->variables->var[k]->type) break;
                            if (tmplb   != m_OSInstance->instanceData->variables->var[k]->lb) break;
                            if (tmpub   != m_OSInstance->instanceData->variables->var[k]->ub) break;
                            mult++;
                        }
                    }
                    outStr << "<var" ;
                    if (m_OSInstance->instanceData->variables->var[i]->name.length() > 0)
                    {
                        outStr << " name=" ;
                        outStr << writeStringData(m_OSInstance->instanceData->variables->var[i]->name);
                    }
                    if( m_OSInstance->instanceData->variables->var[i]->type != 'C')
                    {
                        outStr << " type=\"" ;
                        outStr << m_OSInstance->instanceData->variables->var[i]->type ;
                        outStr <<  "\"";
                    }
                    if( m_OSInstance->instanceData->variables->var[i]->lb != 0.0)
                    {
                        outStr << " lb=\"" ;
                        outStr << os_dtoa_format( m_OSInstance->instanceData->variables->var[i]->lb) ;
                        outStr <<  "\"";
                    }
                    if( m_OSInstance->instanceData->variables->var[i]->ub != OSDBL_MAX
                            && m_OSInstance->instanceData->variables->var[i]->ub != OSNaN() )
                    {
                        outStr << " ub=\"" ;
                        outStr << os_dtoa_format( m_OSInstance->instanceData->variables->var[i]->ub) ;
                        outStr <<  "\"";
                    }
                    if (mult > 1)
                        outStr << " mult=\"" << mult <<  "\"";
                    outStr << "/>" ;
                    if( m_bWhiteSpace == true) outStr << endl;
                }
                i += mult;
            } // end the for loop
            outStr << "</variables>" ;
            if( m_bWhiteSpace == true) outStr << endl;
        }
        if(m_OSInstance->instanceData->objectives != NULL && m_OSInstance->instanceData->objectives->numberOfObjectives > 0)
        {
            outStr << "<objectives " ;
            outStr << "numberOfObjectives=\"";
            outStr << m_OSInstance->instanceData->objectives->numberOfObjectives ;
            outStr << "\"" ;
            outStr << ">" ;
            if( m_bWhiteSpace == true) outStr << endl;
            for (j = 0; j < m_OSInstance->instanceData->objectives->numberOfObjectives;)
            {
                mult = 1;
                if(m_OSInstance->instanceData->objectives->obj[j] != NULL)
                {
                    if (j < m_OSInstance->instanceData->objectives->numberOfObjectives - 1)
                    {
                        tmpname   = m_OSInstance->instanceData->objectives->obj[j]->name;
                        tmpsense  = m_OSInstance->instanceData->objectives->obj[j]->maxOrMin;
                        tmpconst  = m_OSInstance->instanceData->objectives->obj[j]->constant;
                        tmpweight = m_OSInstance->instanceData->objectives->obj[j]->weight;
                        tmpnum    = m_OSInstance->instanceData->objectives->obj[j]->numberOfObjCoef;
                        for (k=j+1; k < m_OSInstance->instanceData->objectives->numberOfObjectives; k++)
                        {
                            if (tmpname   != m_OSInstance->instanceData->objectives->obj[k]->name) break;
                            if (tmpsense  != m_OSInstance->instanceData->objectives->obj[k]->maxOrMin) break;
                            if (tmpconst  != m_OSInstance->instanceData->objectives->obj[k]->constant) break;
                            if (!OSIsEqual(tmpweight, m_OSInstance->instanceData->objectives->obj[k]->weight)) break;
                            if (tmpnum    != m_OSInstance->instanceData->objectives->obj[k]->numberOfObjCoef) break;
                            for (kk=0; kk < tmpnum; kk++)
                            {
                                if (m_OSInstance->instanceData->objectives->obj[k]->coef[kk]->idx !=
                                        m_OSInstance->instanceData->objectives->obj[j]->coef[kk]->idx) break;
                                if (m_OSInstance->instanceData->objectives->obj[k]->coef[kk]->value !=
                                        m_OSInstance->instanceData->objectives->obj[j]->coef[kk]->value) break;
                            }
                            if ( kk < tmpnum) break;
                            mult++;
                        }
                    }
                    outStr << "<obj" ;
                    if(m_OSInstance->instanceData->objectives->obj[j]->maxOrMin.length() > 0)
                    {
                        outStr << " maxOrMin=\"" ;
                        outStr << m_OSInstance->instanceData->objectives->obj[j]->maxOrMin  ;
                        outStr <<  "\"";
                    }
                    if(m_OSInstance->instanceData->objectives->obj[j]->constant != 0.0)
                    {
                        outStr << " constant=\"" ;
                        outStr <<  os_dtoa_format(m_OSInstance->instanceData->objectives->obj[j]->constant)  ;
                        outStr <<  "\"";
                    }
                    if (!OSIsEqual(m_OSInstance->instanceData->objectives->obj[j]->weight,OSNaN()))
                    {
                        outStr << " weight=\"" ;
                        outStr <<  os_dtoa_format(m_OSInstance->instanceData->objectives->obj[j]->weight)  ;
                        outStr <<  "\"";
                    }
                    if(m_OSInstance->instanceData->objectives->obj[j]->name.length() > 0)
                    {
                        outStr << " name=" ;
                        outStr <<  writeStringData(m_OSInstance->instanceData->objectives->obj[j]->name);
                    }
                    outStr << " numberOfObjCoef=\"" ;
                    outStr <<  m_OSInstance->instanceData->objectives->obj[j]->numberOfObjCoef  ;
                    outStr <<  "\"";
                    if (mult > 1)
                        outStr << " mult=\"" << mult <<  "\"";
                    outStr << ">" ;
                    if( m_bWhiteSpace == true) outStr << endl;
                    if(m_OSInstance->instanceData->objectives->obj[j]->coef != NULL)
                    {
                        for (i = 0; i < m_OSInstance->instanceData->objectives->obj[ j]->numberOfObjCoef; i++)
                        {
                            if(m_OSInstance->instanceData->objectives->obj[j]->coef[i]->idx > -1 )
                            {
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
                j += mult;
            }
            outStr << "</objectives>" ;
            if( m_bWhiteSpace == true) outStr << endl;
        }
        // Now the constraints
        if(m_OSInstance->instanceData->constraints != NULL && m_OSInstance->instanceData->constraints->numberOfConstraints > 0)
        {
            outStr << "<constraints " ;
            outStr << "numberOfConstraints=\"";
            outStr << m_OSInstance->instanceData->constraints->numberOfConstraints ;
            outStr << "\"" ;
            outStr << ">" ;
            if( m_bWhiteSpace == true) outStr << endl;
            for (i = 0; i < m_OSInstance->instanceData->constraints->numberOfConstraints;)
            {
                mult = 1;
                if(m_OSInstance->instanceData->constraints->con[i] != NULL)
                {
                    if (i < m_OSInstance->instanceData->constraints->numberOfConstraints - 1)
                    {
                        tmpname  = m_OSInstance->instanceData->constraints->con[i]->name;
                        tmpconst = m_OSInstance->instanceData->constraints->con[i]->constant;
                        tmplb    = m_OSInstance->instanceData->constraints->con[i]->lb;
                        tmpub    = m_OSInstance->instanceData->constraints->con[i]->ub;
                        for (k=i+1; k < m_OSInstance->instanceData->constraints->numberOfConstraints; k++)
                        {
                            if (tmpname  != m_OSInstance->instanceData->constraints->con[k]->name) break;
                            if (tmpconst != m_OSInstance->instanceData->constraints->con[k]->constant) break;
                            if (tmplb    != m_OSInstance->instanceData->constraints->con[k]->lb) break;
                            if (tmpub    != m_OSInstance->instanceData->constraints->con[k]->ub) break;
                            mult++;
                        }
                    }
                    outStr << "<con" ;
                    if(m_OSInstance->instanceData->constraints->con[i]->name.length())
                    {
                        outStr << " name=" ;
                        outStr << writeStringData(m_OSInstance->instanceData->constraints->con[i]->name);
                    }
                    if(m_OSInstance->instanceData->constraints->con[i]->constant != 0)
                    {
                        outStr << " constant=\"" ;
                        outStr << os_dtoa_format( m_OSInstance->instanceData->constraints->con[i]->constant) ;
                        outStr <<  "\"";
                    }
                    if(m_OSInstance->instanceData->constraints->con[i]->lb != -OSDBL_MAX )
                    {
                        outStr << " lb=\"" ;
                        outStr << os_dtoa_format( m_OSInstance->instanceData->constraints->con[i]->lb) ;
                        outStr <<  "\"";
                    }
                    if(m_OSInstance->instanceData->constraints->con[i]->ub != OSDBL_MAX)
                    {
                        outStr << " ub=\"" ;
                        outStr << os_dtoa_format( m_OSInstance->instanceData->constraints->con[i]->ub) ;
                        outStr <<  "\"";
                    }
                    if (mult > 1)
                        outStr << " mult=\"" << mult <<  "\"";
                    outStr << "/>" ;
                    if( m_bWhiteSpace == true) outStr << endl;
                }
                i += mult;
            }
            outStr << "</constraints>" ;
            if( m_bWhiteSpace == true) outStr << endl;
        }
        // now the linearConstraintsCoefficients
        if(m_OSInstance->instanceData->linearConstraintCoefficients != NULL && m_OSInstance->instanceData->linearConstraintCoefficients->numberOfValues > 0)
        {
            outStr << "<linearConstraintCoefficients " ;
            outStr << "numberOfValues=\"";
            outStr << m_OSInstance->instanceData->linearConstraintCoefficients->numberOfValues ;
            outStr << "\"" ;
            outStr << ">" ;
            if( m_bWhiteSpace == true) outStr << endl;
            if( (m_OSInstance->instanceData->linearConstraintCoefficients->rowIdx != NULL) &&
                    (m_OSInstance->instanceData->linearConstraintCoefficients->rowIdx->el != NULL) )
            {
                if(m_OSInstance->instanceData->linearConstraintCoefficients->start->el != NULL)
                {
                    outStr << "<start>" ;
                    if( m_bWhiteSpace == true) outStr << endl;
                    if(m_OSInstance->instanceData->variables != NULL && m_OSInstance->instanceData->variables->numberOfVariables > 0)
                    {
                        if(m_bWriteBase64 == false)
                        {
                            for(i = 0; i <= m_OSInstance->instanceData->variables->numberOfVariables;)
                            {
                                getMultIncr(&(m_OSInstance->instanceData->linearConstraintCoefficients->start->el[i]),
                                            &mult, &incr, (m_OSInstance->instanceData->variables->numberOfVariables) + 1-i,1);
                                if (mult == 1)
                                    outStr << "<el>" ;
                                else if (incr == 0)
                                    outStr << "<el mult=\"" << mult << "\">";
                                else
                                    outStr << "<el mult=\"" << mult << "\" incr=\"" << incr << "\">";
                                outStr << m_OSInstance->instanceData->linearConstraintCoefficients->start->el[i];
                                outStr << "</el>" ;
                                if( m_bWhiteSpace == true) outStr << endl;
                                i += mult;
                            }
                        }
                        else
                        {
                            outStr << "<base64BinaryData sizeOf=\"" << sizeof(int) << "\"  >" ;
                            outStr << Base64::encodeb64( (char*)m_OSInstance->instanceData->linearConstraintCoefficients->start->el,
                                                         (m_OSInstance->instanceData->variables->numberOfVariables + 1)*sizeof(int) );
                            outStr << "</base64BinaryData>" ;
                            if( m_bWhiteSpace == true) outStr << endl;
                        }
                    }
                    outStr << "</start>" ;
                    if( m_bWhiteSpace == true) outStr << endl;
                }
                outStr << "<rowIdx>" ;
                if( m_bWhiteSpace == true) outStr << endl;
                if(m_bWriteBase64 == false)
                {
                    for(i = 0; i < m_OSInstance->instanceData->linearConstraintCoefficients->numberOfValues;)
                    {
                        getMultIncr(&(m_OSInstance->instanceData->linearConstraintCoefficients->rowIdx->el[i]),
                                    &mult, &incr, (m_OSInstance->instanceData->linearConstraintCoefficients->numberOfValues)-i,1);
                        if (mult == 1)
                            outStr << "<el>" ;
                        else if (incr == 0)
                            outStr << "<el mult=\"" << mult << "\">";
                        else
                            outStr << "<el mult=\"" << mult << "\" incr=\"" << incr << "\">";
                        outStr << m_OSInstance->instanceData->linearConstraintCoefficients->rowIdx->el[i];
                        outStr << "</el>" ;
                        if( m_bWhiteSpace == true) outStr << endl;
                        i += mult;
                    }
                }
                else
                {
                    //outStr << "<base64BinaryData sizeOf=\"4\" numericType=\"int\" >" ;
                    outStr << "<base64BinaryData sizeOf=\"" << sizeof(int) << "\"  >" ;
                    outStr << Base64::encodeb64( (char*)m_OSInstance->instanceData->linearConstraintCoefficients->rowIdx->el,
                                                 m_OSInstance->instanceData->linearConstraintCoefficients->numberOfValues*sizeof(int) );
                    outStr << "</base64BinaryData>" ;
                    if( m_bWhiteSpace == true) outStr << endl;
                }
                outStr << "</rowIdx>" ;
                if( m_bWhiteSpace == true) outStr << endl;
            }
            else
            {
                if( (m_OSInstance->instanceData->linearConstraintCoefficients->colIdx != NULL)  &&
                        (m_OSInstance->instanceData->linearConstraintCoefficients->colIdx->el != NULL) )
                {
                    if(m_OSInstance->instanceData->linearConstraintCoefficients->start->el != NULL)
                    {
                        outStr << "<start>" ;
                        if( m_bWhiteSpace == true) outStr << endl;
                        if(m_OSInstance->instanceData->constraints != NULL && m_OSInstance->instanceData->constraints->numberOfConstraints > 0)
                        {
                            if(m_bWriteBase64 == false)
                            {
                                for(i = 0; i <= m_OSInstance->instanceData->constraints->numberOfConstraints;)
                                {
                                    getMultIncr(&(m_OSInstance->instanceData->linearConstraintCoefficients->start->el[i]),
                                                &mult, &incr, (m_OSInstance->instanceData->constraints->numberOfConstraints) + 1-i,1);
                                    if (mult == 1)
                                        outStr << "<el>" ;
                                    else if (incr == 0)
                                        outStr << "<el mult=\"" << mult << "\">";
                                    else
                                        outStr << "<el mult=\"" << mult << "\" incr=\"" << incr << "\">";
                                    outStr << m_OSInstance->instanceData->linearConstraintCoefficients->start->el[i];
                                    outStr << "</el>" ;
                                    if( m_bWhiteSpace == true) outStr << endl;
                                    i += mult;
                                }
                            }
                            else
                            {
                                outStr << "<base64BinaryData sizeOf=\"" << sizeof(int) << "\"  >" ;
                                outStr << Base64::encodeb64( (char*)m_OSInstance->instanceData->linearConstraintCoefficients->start->el,
                                                             (m_OSInstance->instanceData->variables->numberOfVariables + 1)*sizeof(int) );
                                outStr << "</base64BinaryData>" ;
                                if( m_bWhiteSpace == true) outStr << endl;
                            }
                        }
                        outStr << "</start>" ;
                        if( m_bWhiteSpace == true) outStr << endl;
                    }
                    outStr << "<colIdx>";
                    if( m_bWhiteSpace == true) outStr << endl;
                    if(m_bWriteBase64 == false)
                    {
                        for(i = 0; i < m_OSInstance->instanceData->linearConstraintCoefficients->numberOfValues;)
                        {
                            getMultIncr(&(m_OSInstance->instanceData->linearConstraintCoefficients->colIdx->el[i]),
                                        &mult, &incr, (m_OSInstance->instanceData->linearConstraintCoefficients->numberOfValues)-i,1);
                            if (mult == 1)
                                outStr << "<el>" ;
                            else if (incr == 0)
                                outStr << "<el mult=\"" << mult << "\">";
                            else
                                outStr << "<el mult=\"" << mult << "\" incr=\"" << incr << "\">";
                            outStr << m_OSInstance->instanceData->linearConstraintCoefficients->colIdx->el[i];
                            outStr << "</el>" ;
                            if( m_bWhiteSpace == true) outStr << endl;
                            i += mult;
                        }
                    }
                    else
                    {
                        outStr << "<base64BinaryData sizeOf=\"" << sizeof(int) << "\"  >" ;
                        outStr << Base64::encodeb64( (char*)m_OSInstance->instanceData->linearConstraintCoefficients->colIdx->el,
                                                     m_OSInstance->instanceData->linearConstraintCoefficients->numberOfValues*sizeof(int) );
                        outStr << "</base64BinaryData>" ;
                        if( m_bWhiteSpace == true) outStr << endl;
                    }
                    outStr << "</colIdx>" ;
                    if( m_bWhiteSpace == true) outStr << endl;
                }
            }
            if(m_OSInstance->instanceData->linearConstraintCoefficients->value != NULL)
            {
                outStr << "<value>" ;
                if( m_bWhiteSpace == true) outStr << endl;
                if(m_OSInstance->instanceData->linearConstraintCoefficients->value->el != NULL)
                {
                    if(m_bWriteBase64 == false)
                    {
                        for(i = 0; i < m_OSInstance->instanceData->linearConstraintCoefficients->numberOfValues;)
                        {
                            mult = getMult(&(m_OSInstance->instanceData->linearConstraintCoefficients->value->el[i]),
                                           (m_OSInstance->instanceData->linearConstraintCoefficients->numberOfValues)-i);
                            if (mult == 1)
                                outStr << "<el>" ;
                            else
                                outStr << "<el mult=\"" << mult << "\">";
                            outStr <<   os_dtoa_format( m_OSInstance->instanceData->linearConstraintCoefficients->value->el[i] );
                            outStr << "</el>" ;
                            if( m_bWhiteSpace == true) outStr << endl;
                            i += mult;
                        }
                    }
                    else
                    {
                        outStr << "<base64BinaryData sizeOf=\"" << sizeof(double) << "\"  >" ;
                        outStr << Base64::encodeb64( (char*)m_OSInstance->instanceData->linearConstraintCoefficients->value->el,
                                                     m_OSInstance->instanceData->linearConstraintCoefficients->numberOfValues*sizeof( double) );
                        outStr << "</base64BinaryData>" ;
                        if( m_bWhiteSpace == true) outStr << endl;
                    }
                }
                outStr << "</value>" ;
                if( m_bWhiteSpace == true) outStr << endl;
            }
            outStr << "</linearConstraintCoefficients>" ;
            if( m_bWhiteSpace == true) outStr << endl;
        }
        if(m_OSInstance->instanceData->quadraticCoefficients != NULL && m_OSInstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms > 0)
        {
            outStr << "<quadraticCoefficients";
            outStr << "  numberOfQuadraticTerms=\"";
            outStr << m_OSInstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms;
            outStr << "\" >"  ;
            if( m_bWhiteSpace == true) outStr << endl;
            for(i = 0; i < m_OSInstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms; i++)
            {
                if(m_OSInstance->instanceData->quadraticCoefficients->qTerm[i])
                {
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
                    if(m_OSInstance->instanceData->quadraticCoefficients->qTerm[i]->coef != 0)
                    {
                        outStr << "  coef=\"";
                        outStr << os_dtoa_format(m_OSInstance->instanceData->quadraticCoefficients->qTerm[i]->coef);
                        outStr << "\"";
                    }
                    outStr << "/>" ;
                    if( m_bWhiteSpace == true) outStr << endl;
                }
            }
            outStr << "</quadraticCoefficients>";
            if( m_bWhiteSpace == true) outStr << endl;
        }
        //Now the nonlinear expressions
        if(m_OSInstance->instanceData->nonlinearExpressions != NULL && m_OSInstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions > 0)
        {
            outStr << "<nonlinearExpressions";
            outStr << "  numberOfNonlinearExpressions=\"";
            outStr << m_OSInstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions;
            outStr << "\" >"  ;
            if( m_bWhiteSpace == true) outStr << endl;
            for(i = 0; i < m_OSInstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions; i++)
            {
                if(m_OSInstance->instanceData->nonlinearExpressions->nl[i] != NULL)
                {
                    outStr << "<nl" ;
                    // the following attribute is required
                    outStr << " idx=\"";
                    outStr << m_OSInstance->instanceData->nonlinearExpressions->nl[i]->idx;
                    outStr << "\"";

                    // shape is an optional attribute, new since stable 2.9
                    std::string tempStr = returnExprShapeString(m_OSInstance->instanceData->nonlinearExpressions->nl[i]->shape);
                    if (tempStr != "" && tempStr != "general")
                    {
                        outStr << " shape=\"" << tempStr << "\"";
                    }
                    outStr << ">";
                    if(m_OSInstance->instanceData->nonlinearExpressions->nl[i]->osExpressionTree->m_treeRoot != NULL)
                        outStr << m_OSInstance->instanceData->nonlinearExpressions->nl[i]->osExpressionTree->m_treeRoot->getNonlinearExpressionInXML();
                    outStr << "</nl>";
                }
                if( m_bWhiteSpace == true) outStr << endl;
            }
            outStr << "</nonlinearExpressions>";
            if( m_bWhiteSpace == true) outStr << endl;
        }
        // Now the matrices element
        if(m_OSInstance->instanceData->matrices != NULL && m_OSInstance->instanceData->matrices->numberOfMatrices > 0)
        {
            outStr << "<matrices";
            outStr << " numberOfMatrices=\"";
            outStr << m_OSInstance->instanceData->matrices->numberOfMatrices ;
            outStr << "\"" ;
            outStr << ">" ;
            if( m_bWhiteSpace == true) outStr << endl;
            for (i = 0; i < m_OSInstance->instanceData->matrices->numberOfMatrices;i++)
            {
                if (m_OSInstance->instanceData->matrices->matrix[i] != NULL)
                outStr << m_OSInstance->instanceData->matrices->matrix[i]->getMatrixNodeInXML();  
            }
            if( m_bWhiteSpace == true) outStr << endl;
            outStr << "</matrices>" << endl;
        }
        // Now the cones element
        if(m_OSInstance->instanceData->cones != NULL && m_OSInstance->instanceData->cones->numberOfCones > 0)
        {
            outStr << "<cones";
            outStr << " numberOfCones=\"";
            outStr << m_OSInstance->instanceData->cones->numberOfCones ;
            outStr << "\"" ;
            outStr << ">" ;
            if( m_bWhiteSpace == true) outStr << endl;
            for (i = 0; i < m_OSInstance->instanceData->cones->numberOfCones;i++)
            {
                if (m_OSInstance->instanceData->cones->cone[i] != NULL)
                {
                    switch ( m_OSInstance->instanceData->cones->cone[i]->coneType )
                    {
                        case ENUM_CONE_TYPE_nonnegative: 
                            outStr << ((NonnegativeCone*)m_OSInstance->instanceData->cones->cone[i])->getConeInXML();
                            break;
                        case ENUM_CONE_TYPE_nonpositive: 
                            outStr << ((NonpositiveCone*)m_OSInstance->instanceData->cones->cone[i])->getConeInXML();
                            break;
                        case ENUM_CONE_TYPE_orthant: 
                            outStr << ((OrthantCone*)m_OSInstance->instanceData->cones->cone[i])->getConeInXML();
                            break;
                        case ENUM_CONE_TYPE_quadratic: 
                            outStr << ((QuadraticCone*)m_OSInstance->instanceData->cones->cone[i])->getConeInXML();
                            break;
                        case ENUM_CONE_TYPE_rotatedQuadratic: 
                            outStr << ((RotatedQuadraticCone*)m_OSInstance->instanceData->cones->cone[i])->getConeInXML();
                            break;
                        case ENUM_CONE_TYPE_semidefinite: 
                            outStr << ((SemidefiniteCone*)m_OSInstance->instanceData->cones->cone[i])->getConeInXML();
                            break;
                        case ENUM_CONE_TYPE_product: 
                            outStr << ((ProductCone*)m_OSInstance->instanceData->cones->cone[i])->getConeInXML();
                            break;
                        case ENUM_CONE_TYPE_intersection: 
                            outStr << ((IntersectionCone*)m_OSInstance->instanceData->cones->cone[i])->getConeInXML();
                            break;
                    }
                }
            }
            if( m_bWhiteSpace == true) outStr << endl;
            outStr << "</cones>" << endl;
        }
        // Now the matrixProgramming element
        if (m_OSInstance->instanceData->matrixProgramming != NULL)
        {
            outStr << "<matrixProgramming>";

            if (m_OSInstance->instanceData->matrixProgramming->matrixVariables != NULL)
            {
                outStr << "<matrixVariables";
                outStr << " numberOfMatrixVar=\"";         
                outStr << m_OSInstance->instanceData->matrixProgramming->matrixVariables->numberOfMatrixVar << "\">";
                for (int i=0; i < m_OSInstance->instanceData->matrixProgramming->matrixVariables->numberOfMatrixVar; i++)
                {
                    outStr << "<matrixVar";
                    outStr << " numberOfRows=\"";         
                    outStr << m_OSInstance->instanceData->matrixProgramming->matrixVariables->matrixVar[i]->numberOfRows << "\"";
                    outStr << " numberOfColumns=\"";         
                    outStr << m_OSInstance->instanceData->matrixProgramming->matrixVariables->matrixVar[i]->numberOfColumns << "\"";

                    if (m_OSInstance->instanceData->matrixProgramming->matrixVariables->matrixVar[i]->templateMatrixIdx >= 0)
                    {
                        outStr << " templateMatrixIdx=\"";         
                        outStr << m_OSInstance->instanceData->matrixProgramming->matrixVariables->matrixVar[i]->templateMatrixIdx << "\"";
                    }

                    if (m_OSInstance->instanceData->matrixProgramming->matrixVariables->matrixVar[i]->varReferenceMatrixIdx >= 0)
                    {
                        outStr << " varReferenceMatrixIdx=\"";         
                        outStr << m_OSInstance->instanceData->matrixProgramming->matrixVariables->matrixVar[i]->varReferenceMatrixIdx << "\"";
                    }

                    if (m_OSInstance->instanceData->matrixProgramming->matrixVariables->matrixVar[i]->lbMatrixIdx >= 0)
                    {
                        outStr << " lbMatrixIdx=\"";         
                        outStr << m_OSInstance->instanceData->matrixProgramming->matrixVariables->matrixVar[i]->lbMatrixIdx << "\"";
                    }

                    if (m_OSInstance->instanceData->matrixProgramming->matrixVariables->matrixVar[i]->lbConeIdx >= 0)
                    {
                        outStr << " lbConeIdx=\"";         
                        outStr << m_OSInstance->instanceData->matrixProgramming->matrixVariables->matrixVar[i]->lbConeIdx << "\"";
                    }

                    if (m_OSInstance->instanceData->matrixProgramming->matrixVariables->matrixVar[i]->ubMatrixIdx >= 0)
                    {
                        outStr << " ubMatrixIdx=\"";         
                        outStr << m_OSInstance->instanceData->matrixProgramming->matrixVariables->matrixVar[i]->ubMatrixIdx << "\"";
                    }

                    if (m_OSInstance->instanceData->matrixProgramming->matrixVariables->matrixVar[i]->ubConeIdx >= 0)
                    {
                        outStr << " ubConeIdx=\"";         
                        outStr << m_OSInstance->instanceData->matrixProgramming->matrixVariables->matrixVar[i]->ubConeIdx << "\"";
                    }

                    if (m_OSInstance->instanceData->matrixProgramming->matrixVariables->matrixVar[i]->name != "")
                    {
                        outStr << " name=\"";         
                        outStr << m_OSInstance->instanceData->matrixProgramming->matrixVariables->matrixVar[i]->name << "\"";
                    }

                    if (verifyVarType(m_OSInstance->instanceData->matrixProgramming->matrixVariables->matrixVar[i]->varType) && m_OSInstance->instanceData->matrixProgramming->matrixVariables->matrixVar[i]->varType != 'C')
                    {
                        outStr << " varType=\"";         
                        outStr << m_OSInstance->instanceData->matrixProgramming->matrixVariables->matrixVar[i]->varType << "\"";
                    }

                    outStr << "/>" << endl;                
                }
                outStr << "</matrixVariables>" << endl;                
            }

            if (m_OSInstance->instanceData->matrixProgramming->matrixObjectives != NULL)
            {
                outStr << "<matrixObjectives";
                outStr << " numberOfMatrixObj=\"";         
                outStr << m_OSInstance->instanceData->matrixProgramming->matrixObjectives->numberOfMatrixObj << "\">";
                for (int i=0; i < m_OSInstance->instanceData->matrixProgramming->matrixObjectives->numberOfMatrixObj; i++)
                {
                    outStr << "<matrixObj";
                    outStr << " numberOfRows=\""; 
                    outStr << m_OSInstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[i]->numberOfRows << "\"";
                    outStr << " numberOfColumns=\"";         
                    outStr << m_OSInstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[i]->numberOfColumns << "\"";

                    if (m_OSInstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[i]->templateMatrixIdx >= 0)
                    {
                        outStr << " templateMatrixIdx=\"";         
                        outStr << m_OSInstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[i]->templateMatrixIdx << "\"";
                    }

                    if (m_OSInstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[i]->objReferenceMatrixIdx >= 0)
                    {
                        outStr << " objReferenceMatrixIdx=\"";         
                        outStr << m_OSInstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[i]->objReferenceMatrixIdx << "\"";
                    }

                    if (m_OSInstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[i]->orderConeIdx >= 0)
                    {
                        outStr << " orderConeIdx=\"";         
                        outStr << m_OSInstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[i]->orderConeIdx << "\"";
                    }

                    if (m_OSInstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[i]->constantMatrixIdx >= 0)
                    {
                        outStr << " constantMatrixIdx=\"";         
                        outStr << m_OSInstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[i]->constantMatrixIdx << "\"";
                    }

                    if (m_OSInstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[i]->name != "")
                    {
                        outStr << " name=\"";         
                        outStr << m_OSInstance->instanceData->matrixProgramming->matrixObjectives->matrixObj[i]->name << "\"";
                    }

                    outStr << "/>" << endl;                
                }
                outStr << "</matrixObjectives>" << endl;                
            }

            if (m_OSInstance->instanceData->matrixProgramming->matrixConstraints != NULL)
            {
                outStr << "<matrixConstraints";
                outStr << " numberOfMatrixCon=\"";         
                outStr << m_OSInstance->instanceData->matrixProgramming->matrixConstraints->numberOfMatrixCon << "\">";
                for (int i=0; i < m_OSInstance->instanceData->matrixProgramming->matrixConstraints->numberOfMatrixCon; i++)
                {
                    outStr << "<matrixCon";
                    outStr << " numberOfRows=\"";         
                    outStr << m_OSInstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[i]->numberOfRows << "\"";
                    outStr << " numberOfColumns=\"";         
                    outStr << m_OSInstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[i]->numberOfColumns << "\"";

                    if (m_OSInstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[i]->templateMatrixIdx >= 0)
                    {
                        outStr << " templateMatrixIdx=\"";         
                        outStr << m_OSInstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[i]->templateMatrixIdx << "\"";
                    }

                    if (m_OSInstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[i]->conReferenceMatrixIdx >= 0)
                    {
                        outStr << " conReferenceMatrixIdx=\"";         
                        outStr << m_OSInstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[i]->conReferenceMatrixIdx << "\"";
                    }

                    if (m_OSInstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[i]->lbMatrixIdx >= 0)
                    {
                        outStr << " lbMatrixIdx=\"";         
                        outStr << m_OSInstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[i]->lbMatrixIdx << "\"";
                    }

                    if (m_OSInstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[i]->lbConeIdx >= 0)
                    {
                        outStr << " lbConeIdx=\"";         
                        outStr << m_OSInstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[i]->lbConeIdx << "\"";
                    }
    
                    if (m_OSInstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[i]->ubMatrixIdx >= 0)
                    {
                        outStr << " ubMatrixIdx=\"";         
                        outStr << m_OSInstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[i]->ubMatrixIdx << "\"";
                    }

                    if (m_OSInstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[i]->ubConeIdx >= 0)
                    {
                        outStr << " ubConeIdx=\"";         
                        outStr << m_OSInstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[i]->ubConeIdx << "\"";
                    }

                    if (m_OSInstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[i]->name != "")
                    {
                        outStr << " name=\"";         
                        outStr << m_OSInstance->instanceData->matrixProgramming->matrixConstraints->matrixCon[i]->name << "\"";
                    }

                    outStr << "/>" << endl;                
                }
                outStr << "</matrixConstraints>" << endl;                
            }

            if (m_OSInstance->instanceData->matrixProgramming->matrixExpressions != NULL)
            {
                outStr << "<matrixExpressions";
                outStr << " numberOfExpr=\"";         
                outStr << m_OSInstance->instanceData->matrixProgramming->matrixExpressions->numberOfExpr << "\">";
                if( m_bWhiteSpace == true) outStr << endl;
                for (int i=0; i < m_OSInstance->instanceData->matrixProgramming->matrixExpressions->numberOfExpr; i++)
                {
                    if (m_OSInstance->instanceData->matrixProgramming->matrixExpressions->expr[i] != NULL)
                    {
                        outStr << "<expr";

                        // the following attribute is required
                        outStr << " idx=\"";
                        outStr << m_OSInstance->instanceData->matrixProgramming->matrixExpressions->expr[i]->idx;
                        outStr << "\"";

                        // shape is an optional attribute, new since stable 2.9
                        std::string tempStr = returnExprShapeString(m_OSInstance->instanceData->matrixProgramming->matrixExpressions->expr[i]->shape);
                        if (tempStr != "" && tempStr != "general");
                        {
                            outStr << " shape=\"" << tempStr;
                        }

                        outStr << "\">";
                        if(m_OSInstance->instanceData->matrixProgramming->matrixExpressions->expr[i]->matrixExpressionTree->m_treeRoot != NULL)
                            outStr << m_OSInstance->instanceData->matrixProgramming->matrixExpressions->expr[i]->matrixExpressionTree->m_treeRoot->getNonlinearExpressionInXML();
                        outStr << "</expr>";
                        if( m_bWhiteSpace == true) outStr << endl;                
                    }
                }
                outStr << "</matrixExpressions>";
                if( m_bWhiteSpace == true) outStr << endl;                
            }

            outStr << "</matrixProgramming>" << endl;
        }
        if( m_bWhiteSpace == true) outStr << endl;
    } // end instanceData if
    outStr << "</instanceData>";
    outStr << "</osil>" ;
    if( m_bWhiteSpace == true) outStr << endl;
    outStr << endl;
    return outStr.str();
} // end writeOSiL
