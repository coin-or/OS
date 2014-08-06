/* $Id: OSnLParserData.h 4806 2014-06-07 11:37:46Z Gassmann $ */
/** @file OSnLParserData.h
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin,
 *
 * \remarks
 * Copyright (C) 2005-2014, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */
#ifndef OSNLPARSERDATA_H
#define OSNLPARSERDATA_H

#include "OSnLNode.h"
#include <vector>


/*! \class OSnLParserData
 *  \brief The OSnLParserData  Class.
 *
 * \remarks
 * The OSnLParserData class is used to temporarily
 * hold data found in parsing the OSnL schema elements.
 * We do this so we can have a reentrant parser.
 */
class OSnLParserData
{
public:

    /** generic attributes */
    bool categoryAttributePresent;
    std::string categoryAttribute;
    bool typeAttributePresent;
    std::string typeAttribute;
    bool varTypeAttributePresent;
    std::string varTypeAttribute;
    bool objTypeAttributePresent;
    std::string objTypeAttribute;
    bool conTypeAttributePresent;
    std::string conTypeAttribute;
    bool enumTypeAttributePresent;
    std::string enumTypeAttribute;
    bool nameAttributePresent;
    std::string nameAttribute;
    bool valueAttributePresent;
    std::string valueAttribute;
    bool lbValueAttributePresent;
    std::string lbValueAttribute;
    bool ubValueAttributePresent;
    std::string ubValueAttribute;
    bool descriptionAttributePresent;
    std::string descriptionAttribute;
    bool solverAttributePresent;
    std::string solverAttribute;
    bool unitAttributePresent;
    std::string unitAttribute;
    int  idxAttribute;

    /** some temporary items to facilitate code sharing */
    int tempInt;
    int numberOf;
    int kounter;
    int iOther;
    int iOption;
    double tempVal;
    std::string tempStr;

    /** the OSnLParserData class constructor */
    OSnLParserData( );

    /** the OSnLParserData class destructor */
    ~OSnLParserData() ;


    /** These entities are used for parsing <nonlinearExpressions> */

    /** a pointer to an OSnLNode object */
    OSnLNode *nlNodePoint;

    /** a pointer to an OSnLNode object that is a variable */
    OSnLNodeVariable *nlNodeVariablePoint;

    /** a pointer to an OSnLNode object that is a number */
    OSnLNodeNumber *nlNodeNumberPoint;

    /** nlnodecount is the number of nl nodes in the instance*/
    int nlnodecount;

    /** tmpnlcount counts the number of nl nodes actually found. 
     *  If this number differs from nlnodecount, then an exception is thrown
     */
    int tmpnlcount;

    /** numbertypeattON is set to true if the type attribute has been parsed
     * for an OSnLNodeNumber object, an exception is thrown if there is more than
     * one number attribute
     */
    bool numbertypeattON ;

    /** numbervalueattON is set to true if the value attribute has been parsed
     * for an OSnLNodeNumber object, an exception is thrown if there is more than
     * one value attribute
     */
    bool numbervalueattON;

    /** numberidattON is set to true if the id attribute has been parsed
     * for an OSnLNodeNumber object, an exception is thrown if there is more than
     * one id attribute
     */
    bool numberidattON;

    /** variableidxattON is set to true if the idx attribute has been parsed
     * for an OSnLNodeVariable, an exception is thrown if there is more than
     * one idx attribute
     */
    bool variableidxattON ;

    /** variablecoefattON is set to true if the coeff attribute has been parsed
     * for an OSnLNodeVariable, an exception is thrown if there is more than
     * one coeff attribute
     */
    bool variablecoefattON ;

    /** nlNodeVec holds a vector of pointers to OSnLNodes */
    std::vector<OSnLNode*> nlNodeVec;

    /** the OSnLNodeSum node can have any number of children, including
     * other children with an indeterminate number of children so when
     * parsing we need to temporarily store all of its children
     */
    std::vector<OSnLNode*> sumVec;

    /** the OSnLNodeallDiff node can have any number of children, including
     * other children with an indeterminate number of children so when
     * parsing we need to temporarily store all of its children
     */
    std::vector<OSnLNode*> allDiffVec;

    /** the OSnLNodeProduct node can have any number of children, including
     * other children with an indeterminate number of children so when
     * parsing we need to temporarily store all of its children
     */
    std::vector<OSnLNode*> productVec;

    /** the OSnLNodeMax node can have any number of children, including
     * other children with an indeterminate number of children so when
     * parsing we need to temporarily store all of its children
     */
    std::vector<OSnLNode*> maxVec;

    /** the OSnLNodeMin node can have any number of children, including
     * other children with an indeterminate number of children so when
     * parsing we need to temporarily store all of its children
     */
    std::vector<OSnLNode*> minVec;


    /** These entities are used for parsing linear and nonlinear matrix expressions */

    /** a pointer to an OSnLMNode object */
    OSnLMNode *nlMNodePoint;

    /** a pointer to an OSnLMNode object that is a simple matrix reference */
    OSnLMNodeMatrixReference *nlMNodeMatrixRef;

    /** nlmnodecount is the number of nlm nodes in the instance*/
    int nlmnodecount;

    /** tmpnlcount counts the number of nlm nodes actually found. 
     *  If this number differs from nlnodecount, then an exception is thrown
     */
    int tmpnlmcount;

    /** matrixreftypeattON is set to true if the type attribute has been parsed
     * for an OSnLMNodeMatrixReference object, an exception is thrown if there is more than
     * one matrixref attribute
     */
    bool matrixreftypeattON ;

    /** matrixidxattON is set to true if the idx attribute has been parsed
     * for an OSnLNodeVariable, an exception is thrown if there is more than
     * one idx attribute
     */
    bool matrixidxattON ;

    /** OSnLMNodeVec holds a vector of pointers to OSnLMNodes */
    std::vector<OSnLMNode*> OSnLMNodeVec;

    /** the OSnLMNodeMatrixSum node can have any number of children, including
     * other children with an indeterminate number of children so when
     * parsing we need to temporarily store all of its children
     */
    std::vector<OSnLMNode*> matrixSumVec;

    /** the OSnLMNodeProduct node can have any number of children, including
     * other children with an indeterminate number of children so when
     * parsing we need to temporarily store all of its children
     */
    std::vector<OSnLMNode*> matrixProductVec;

    /**  Attributes and other data items associated with parsing the OSnLMNodes */
    bool includeDiagonalAttributePresent;
    std::string includeDiagonalAttribute;

    /** if the parser finds invalid text it is held here and we delete
     *  if the file was not valid
     */
    char *errorText;

    /** used to accumulate error message so the parser does not die
     *  on the first error encountered
     */
    std::string parser_errors;

    /** two booleans to govern the behavior after an error has been encountered */
    bool ignoreDataAfterErrors;
    bool suppressFurtherErrorMessages; 
};//OSnLParserData


inline void osnl_empty_vectors( OSnLParserData* osnlData)
{

}//end osnl_empty_vectors



#endif /*OSNLPARSERDATA_H_*/
