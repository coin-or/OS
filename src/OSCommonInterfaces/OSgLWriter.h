/* $Id: OSglWriter.h 2698 2009-06-09 04:14:07Z kmartin $ */
/** @file OSgLWriter.h
 *
 *
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * @version 1.0, 22/Oct/2010
 * @since   OS2.2
 *
 * \remarks
 * Copyright (C) 2005-2010, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */

#ifndef OSgLWRITER_H
#define OSgLWRITER_H

#include "OSGeneral.h"
#include "OSiLWriter.h"
#include "OSInstance.h"
#include "OSGeneral.h"
#include "OSParameters.h"
#include "OSBase64.h"
#include "OSMathUtil.h"

#include <string>
#include <sstream>

/*! \brief Take an IntVector object and write
 * a string that validates against the OSgL schema.
 *
 * @param v is the IntVector to be output
 * @param addWhiteSpace controls whether whitespace (i.e., line feed) is to be added
 * @param writeBase64 controls whether the IntVector is to be output in base64 format
 *        or as a sequence of <el> (including mult and incr attributes)
 */
std::string writeIntVectorData(IntVector *v, bool addWhiteSpace, bool writeBase64);


/*! \brief Take a GeneralFileHeader object and write
 * a string that validates against the OSgL schema.
 *
 * @param v is the header to be output
 * @param addWhiteSpace controls whether whitespace (i.e., line feed) is to be added
 */
std::string writeGeneralFileHeader(GeneralFileHeader *v, bool addWhiteSpace);

/*! \brief Take an OtherOptionOrResultEnumeration object and write
 * a string that validates against the OSgL schema.
 *
 * @param e is the OtherOptionOrResultEnumeration to be output
 * @param addWhiteSpace controls whether whitespace (i.e., line feed) is to be added
 * @param writeBase64 controls whether the embedded integer array is to be output in base64 format
 *        or as a sequence of <el> (including mult and incr attributes)
 */
std::string writeOtherOptionOrResultEnumeration(OtherOptionOrResultEnumeration *e, bool addWhiteSpace, bool writeBase64);


/*! \brief Take a DoubleVector object and write
 * a string that validates against the OSgL schema.
 *
 * @param v is the DoubleVector to be output
 * @param addWhiteSpace controls whether whitespace (i.e., line feed) is to be added
 * @param writeBase64 controls whether the IntVector is to be output in base64 format
 *        or as a sequence of <el> (including mult and incr attributes)
 */
std::string writeDblVectorData(DoubleVector *v, bool addWhiteSpace, bool writeBase64);


/*! \brief Take a BasisStatus object and write
 * a string that validates against the OSgL schema.
 *
 * @param bs is the basisStatus object to be output
 * @param addWhiteSpace controls whether whitespace (i.e., line feed) is to be added
 * @param writeBase64 controls whether the IntVectors contained in the enumerations are to be output in base64 format
 *        or as a sequence of <el> (including mult and incr attributes)
 */
std::string writeBasisStatus(BasisStatus *bs, bool addWhiteSpace, bool writeBase64);

#endif
