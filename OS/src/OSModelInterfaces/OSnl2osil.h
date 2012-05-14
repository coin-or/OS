/* $Id$ */
/** @file OSnl2osil.h
 *
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 *
 * \remarks
 * Copyright (C) 2005-2011, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University, Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */


#ifndef OSNL2OSIL_H
#define OSNL2OSIL_H



#include "OSInstance.h"
#include "OSnLNode.h"
#include "OSMathUtil.h"
#include <string>
#include <vector>


/*! \class OSnl2osil
 *  \brief The OSnl2osil  Class.
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 *
 * \remarks
 * the OSnl2osil class is used for reading an instance
 * in AMPL nl format and creating an OSInstance object in OSiL format
 *
 */

struct ograd;
struct ASL;
struct expr;


class OSnl2osil
{
public:
    /** the OSnl2osil class constructor */
    OSnl2osil( std::string nlfilename);

    /** the OSnl2osil class destructor */
    ~OSnl2osil();

    /**
     * create an OSInstance from the AMPL nl instance representation
     *
     * @return whether the instance is created successfully.
     */
    bool createOSInstance();

    /**
     * parse an nl tree structure holding a nonlinear expression
     *
     * @return the AMPL nonlinear structure as an OSnLNode.
     */
    OSnLNode* walkTree(expr *e);

    /** osinstance is a pointer to the OSInstance object that gets
     * created from the instance represented in NL format
     */
    OSInstance *osinstance;

    std::vector<std::string> op_type;
    std::vector<double> operand;
    int numkount;
private:

    /** og is a pointer to the AMPL data structure holding the
     * objective function coefficients
     */
    ograd *og;

    /** Pointers to AMPL data structures.
	 * cw is loaded in column-wise format.
	 * rw is loaded in row-wise format.
	 * asl is for conveniently switching.
     */
    ASL *asl, *cw, *rw;

    /** stub is the name of the file with the nl instance
     */
    std::string stub;
};
#endif
