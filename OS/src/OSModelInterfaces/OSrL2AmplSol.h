/* $Id: OSrL2AmplSol.h 4249 2011-08-11 01:08:14Z Gassmann $ */
/** @file OSrL2AmplSol.h
 * 
 * @author  Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2012, Horand Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */
 

#ifndef OSRL2AMPLSOL_H
#define OSRL2AMPLSOL_H



#include "OSResult.h"
#include "OSMathUtil.h"
#include <string>
#include <vector>


/*! \class OSrL2AmplSol
 *  \brief The OSrL2AmplSol  Class.
 * 
 * @author Horand Gassmann, Jun Ma, Kipp Martin
 * 
 * \remarks
 * The OSrL2AmplSol class is used for writing an AMPL sol file, 
 * including any results indexed over variables, constraints, objectives. 
 * 
 */ 

struct ograd;
struct cgrad;
struct ASL;
struct expr;


class OSrL2AmplSol
{
public:
    /** the OSrL2AmplSol class constructor */
    OSrL2AmplSol( std::string nlfilename, std::string osol);
 
    /** the OSrL2AmplSol class destructor */
    ~OSrL2AmplSol();
    
    /**
     * create an OSInstance and OS option representation from the AMPL nl content 
     * Since some of the information in the nl file 
     * (such as initial values, basis information, branching priorities)
     * cannot be stored into an OSInstance and must be stored in an
     * OSOption object instead, all other options must be provided
     * to this method as well.
     *
     * @param osrl is a string containing the result information
     * (e.g., as returned from the solver). 
     * @return whether the .sol file was created successfully. 
     */
    bool writeSolFile(std::string osrl); 

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

};  //end of OSrL2AmplSol

#endif
