// Copyright (C) GAMS Development and others 2008-2009
// All Rights Reserved.
// This code is published under the Eclipse Public License.
//
// $Id$
//
// Author: Stefan Vigerske

#ifndef OSGAMS2OSIL_HPP_
#define OSGAMS2OSIL_HPP_

#include <string>

class OSInstance;
class OSnLNode;

struct gmoRec;
struct gevRec;

/** Creating a OSInstance from a GAMS model given as GAMS Modeling Object (GMO).
 */
class OSgams2osil
{
private:
    struct gevRec* gev;
    struct gmoRec* gmo;

    OSnLNode* parseGamsInstructions(int codelen, int* opcodes, int* fields, int constantlen, double* constants);


public:
    OSInstance *osinstance;

    OSgams2osil(struct gmoRec* gmo_ = NULL);

    OSgams2osil( std::string gamsControlFile);

    ~OSgams2osil();

    bool initGMO(const char* datfile);

    /** Creates an OSInstance from the GAMS smag instance representation
     * @return whether the instance is created successfully.
     */
    bool createOSInstance();

    /** Gives OSInstance and ownership to calling function.
     * This object forgets about the created instance.
     */
    OSInstance* takeOverOSInstance();

    /** Gives OSInstances but keeps ownership.
     * Destruction will destruct OSInstance.
     */
    OSInstance* getOSInstance()
    {
        return osinstance;
    }
};


#endif /*GAMS2OSIL_HPP_*/
