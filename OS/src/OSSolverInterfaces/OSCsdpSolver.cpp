/* $Id: OSCsdpSolver.cpp 4787 2014-01-22 22:26:56Z Gassmann $ */
/** @file OSCsdpSolver.cpp
 *
 * \brief This file defines the CsdpSolver class.
 * \detail Read an OSInstance object and convert to CSDP data structures; write solution to OSResult
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2014-2015, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 * This first implementation is based on Brian Borchers' code example.c,
 * supplied in the CSDP distribution as an illustration of the CSDP API.
 */

#include "OSCsdpSolver.h"
#include "OSFileUtil.h"
#include "OSInstance.h"
#include "OSOption.h"
#include "OSGeneral.h"
#include "OSMatrix.h"
#include "OSrLReader.h"
#include "OSOutput.h"
#include "OSParameters.h"
#include "OSMathUtil.h"

#include "CoinTime.hpp"

#include <map>
#include <cstdio>

#include <iostream>
#ifdef HAVE_CTIME
# include <ctime>
#else
# ifdef HAVE_TIME_H
#  include <time.h>
# else
#  error "don't have header file for time"
# endif
#endif

using std::cout;
using std::endl;
using std::ostringstream;


CsdpSolver::CsdpSolver()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, 
        "inside CsdpSolver constructor\n");
#endif
    osrlwriter = new OSrLWriter();
    osresult   = new OSResult();
    m_osilreader = NULL;
    m_osolreader = NULL;
    csdpErrorMsg = new std::string("");

    nC_rows = -1;
    nC_blks = -1;
    ncon    = -1;

    //C_matrix     = NULL;
    C_matrix.nblocks = -1;
    rhsValues    = NULL;
    mconstraints = NULL;

    X.nblocks = -1;
    y = NULL;
    Z.nblocks = -1;

    tempOptionFile = "";
}

CsdpSolver::~CsdpSolver()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, "inside CsdpSolver destructor\n");
#endif
    if(m_osilreader != NULL) delete m_osilreader;
    m_osilreader = NULL;
    if(m_osolreader != NULL) delete m_osolreader;
    m_osolreader = NULL;
    delete osresult;
    osresult = NULL;
    delete osrlwriter;
    osrlwriter = NULL;
    //delete osinstance;
    //osinstance = NULL;
    delete csdpErrorMsg;

    // delete Csdp data structures
    // Note: Some data items are allocated in init_soln.c; these must be free'd. 
    // The others must be delete'd 
    if (y != NULL)
        delete(y); // free(y); 
    y = NULL;
//    if (X.nblocks != -1)
//        free_mat(X);
//    if (Z.nblocks != -1)
//        free_mat(Z);

    for (int i=1; i<=C_matrix.nblocks; i++)
    {
        if (C_matrix.blocks[i].blockcategory == DIAG) 
            delete[] C_matrix.blocks[i].data.vec;
        else
            delete[] C_matrix.blocks[i].data.mat;
    }
    if (C_matrix.nblocks != -1)
    delete [] C_matrix.blocks;

    for (int i=1; i<=X.nblocks; i++)
    {
        if (X.blocks[i].blockcategory == DIAG) 
            delete[] X.blocks[i].data.vec;
        else
            delete[] X.blocks[i].data.mat;
    }
    if (X.nblocks != -1)
    delete [] X.blocks;

    for (int i=1; i<=Z.nblocks; i++)
    {
        if (Z.blocks[i].blockcategory == DIAG) 
            delete[] Z.blocks[i].data.vec;
        else
            delete[] Z.blocks[i].data.mat;
    }
    if (Z.nblocks != -1)
    delete [] Z.blocks;


    // Finally clear out mconstraints;
    struct sparseblock *ptr;
    struct sparseblock *oldptr;

    if (mconstraints != NULL)
    {
        for (int i=1; i<=ncon; i++)
        {
            ptr = mconstraints[i].blocks;
            while (ptr != NULL)
            {
                delete[] ptr->entries;
                delete[] ptr->iindices;
                delete[] ptr->jindices;
                oldptr = ptr;
                ptr = ptr->next;
                delete oldptr;
            }
        }
        delete[] mconstraints;
    }
    if (tempOptionFile != "")
    {
        int IOStatus = rename ( tempOptionFile.c_str(), "param.csdp" );
        if (IOStatus != 0)
            throw ErrorClass("CsdpSolver: Cannot restore param.csdp");                    
    }
}

void CsdpSolver::buildSolverInstance()
{
    std::ostringstream outStr;
    RealValuedExpressionTree* tempTree;
    ExprNode *tr;
    ExprNode *mt;
    ExprNode *mr;
    ExprNode *mv;
    OSMatrix* tempMtx;

    int*  blockOffset = NULL;
    int*  blockSize   = NULL;
    int*  mtxRef      = NULL;
    bool* isdiag      = NULL;
    ExpandedMatrixBlocks** mtxBlocks = NULL;
    try
    {
        if(osil.length() == 0 && osinstance == NULL) throw ErrorClass("there is no instance");
        clock_t start, finish;
        double duration;
        start = clock();
        if(osinstance == NULL)
        {
            m_osilreader = new OSiLReader();
            osinstance = m_osilreader->readOSiL( osil);
        }
        finish = clock();
        duration = (double) (finish - start) / CLOCKS_PER_SEC;

        /* Process the osinstance into the --- rather tricky --- CSDP data structures
         * and verify that the solver is appropriate - CSDP requires a very special type of problem 
         */

        // Check general problem characteristics
        if (osinstance->getNumberOfMatrixVariables() != 1)
            throw ErrorClass("There must be one matrixVar object");
        if (osinstance->getNumberOfNonlinearExpressions() != osinstance->getConstraintNumber() + 1)
            throw ErrorClass("There must be one nonlinear expression for each constraint and objective");
        if (osinstance->getLinearConstraintCoefficientNumber() > 0)
            throw ErrorClass("Additional linear constraint coefficients are not supported");
        if (osinstance->getNumberOfQuadraticTerms() > 0)
            throw ErrorClass("Additional quadratic terms are not supported");

        char* cType = osinstance->getConstraintTypes();
        for (int i=0; i < osinstance->getConstraintNumber(); i++)
            if (cType[i] != 'E') throw ErrorClass("Only equality constraints are supported");

        std::string* oType = osinstance->getObjectiveMaxOrMins();
        if (oType[0] != "max") throw ErrorClass("The problem must be of \"max\" type");

        //Check the form of the objective
        tempTree = osinstance->getNonlinearExpressionTree(-1);
        if (tempTree == NULL) throw ErrorClass("Expecting matrixTrace in objective row");
        tr = tempTree->m_treeRoot;
        if (tr->inodeInt != OS_MATRIX_TRACE)
            throw ErrorClass("Expecting matrixTrace in objective row");
        mt = tr->m_mChildren[0];
        if (mt->inodeInt != OS_MATRIX_TIMES)
            throw ErrorClass("Unsupported expression in objective row");
        mr = mt->m_mChildren[0];
        mv = mt->m_mChildren[1];
        if (mr->inodeInt != OS_MATRIX_REFERENCE || mv->inodeInt != OS_MATRIX_VAR)
            throw ErrorClass("Unsupported expression in objective row");

        mtxRef = new int[osinstance->getConstraintNumber()+1];

        // Analyze A0 matrix: Verify existence, block-diagonal structure, get block dimensions, etc.
        mtxRef[0] = ((OSnLMNodeMatrixReference*)mr)->idx;
        if (osinstance->instanceData->matrices == NULL) 
            throw ErrorClass("<matrices> section was never defined");
        if (mtxRef[0] < 0 || mtxRef[0] >= osinstance->getMatrixNumber())
            throw ErrorClass("Illegal matrix reference");
        tempMtx = osinstance->instanceData->matrices->matrix[mtxRef[0]];
        if (tempMtx == NULL) throw ErrorClass("A0 matrix was never defined");
        if (tempMtx->numberOfRows != tempMtx->numberOfColumns) 
           throw ErrorClass("A0 matrix must be square and symmetric"); 
        if (tempMtx->getMatrixType() != ENUM_MATRIX_TYPE_constant) 
           throw ErrorClass("A0 matrix must be of type \"constant\"");

        int*    rowOffsets = tempMtx->getRowPartition();
        int     nRowBlocks = tempMtx->getRowPartitionSize();
        int* columnOffsets = tempMtx->getColumnPartition();
        int  nColumnBlocks = tempMtx->getColumnPartitionSize();

        int* tempRowOffsets;
        int  tempNRowBlocks;
        int* tempColumnOffsets;
        int  tempNColumnBlocks;

        int i0, itemp, imerge;

// processBlockPartition();

        //do the same for all constraints
        for (int i=0; i < osinstance->getConstraintNumber(); i++)
        {
            tempTree = osinstance->getNonlinearExpressionTree(i);
            if (tempTree == NULL) throw ErrorClass("Expecting matrixTrace in constraint row");
            tr = tempTree->m_treeRoot; 
            if (tr->inodeInt != OS_MATRIX_TRACE)
                throw ErrorClass("Expecting matrixTrace in constraint row");
            mt = tr->m_mChildren[0];
            if (mt->inodeInt != OS_MATRIX_TIMES)
                throw ErrorClass("Unsupported expression in constraint row");
            mr = mt->m_mChildren[0];
            mv = mt->m_mChildren[1];
            if (mr->inodeInt != OS_MATRIX_REFERENCE || mv->inodeInt != OS_MATRIX_VAR)
                throw ErrorClass("Unsupported expression in constraint row");

            // Analyze Ai matrix: Verify existence, block-diagonal structure, get block dimensions, etc.
            mtxRef[i+1] = ((OSnLMNodeMatrixReference*)mr)->idx;
            if (mtxRef[i+1] < 0 || mtxRef[i+1] >= osinstance->getMatrixNumber())
                throw ErrorClass("Illegal matrix reference");
            tempMtx = osinstance->instanceData->matrices->matrix[mtxRef[i+1]];
            if (tempMtx == NULL) throw ErrorClass("Matrix in constraint was never defined");
            if (tempMtx->numberOfRows != tempMtx->numberOfColumns) 
                throw ErrorClass("Constraint matrix must be square and symmetric"); 
            if (tempMtx->getMatrixType() != ENUM_MATRIX_TYPE_constant) 
                throw ErrorClass("Constraint matrix must be of type \"constant\"");

            tempRowOffsets = tempMtx->getRowPartition();
            tempNRowBlocks = tempMtx->getRowPartitionSize();
            tempColumnOffsets = tempMtx->getColumnPartition();
            tempNColumnBlocks = tempMtx->getColumnPartitionSize();

            // merge row partitions
            i0 = 0;
            itemp = 0;
            imerge = 0;
            for (;;)
            {
                if (rowOffsets[i0] == tempRowOffsets[itemp])
                {
                    if (imerge != i0) rowOffsets[imerge] = rowOffsets[i0];
                    i0++;
                    itemp++;
                    imerge++;
                }
                else
                {
                    if (rowOffsets[i0] < tempRowOffsets[itemp])
                        i0++;
                    else
                        itemp++;
                }
                if (i0 >= nRowBlocks || itemp >= tempNRowBlocks)
                    break;
            }
            nRowBlocks = imerge;

            // merge column partititons
            i0 = 0;
            itemp = 0;
            imerge = 0;
            for (;;)
            {
                if (columnOffsets[i0] == tempColumnOffsets[itemp])
                {
                    if (imerge != i0) columnOffsets[imerge] = columnOffsets[i0];
                    i0++;
                    itemp++;
                    imerge++;
                }
                else
                {
                    if (columnOffsets[i0] < tempColumnOffsets[itemp])
                        i0++;
                    else
                        itemp++;
                }
                if (i0 >= nColumnBlocks || itemp >= tempNColumnBlocks)
                    break;
            }
            nColumnBlocks = imerge;
        }

        blockOffset = new int[nRowBlocks]; // step this through: nRowBlocks=?

        // make sure the row and column blocks are synchronized and compute block sizes
        int nBlocks;
        int jrow = 0;
        int jcol = 0;
        nBlocks  = 0;
        for (;;)
        {
            if (rowOffsets[jrow] == columnOffsets[jcol])
            {
                blockOffset[nBlocks] = rowOffsets[jrow];
                jrow++;
                jcol++;
                nBlocks++;
            }
            else
            {
                if (rowOffsets[jrow] < columnOffsets[jcol])
                    jrow++;
                else
                    jcol++;
            }
            if (jrow >= nRowBlocks || jcol >= nColumnBlocks)
                break;
        }

        // Note: nBlocks is one larger than the number of blocks. 
        //       blockSize is 1-based, due to issues of Fortran compatibility,
        //       so we will burn off blockSize[0] anyway...
        blockSize = new int[nBlocks];
        for (int i=1; i < nBlocks; i++)
        {
#ifndef NOSHORTS
            if (blockOffset[i] - blockOffset[i-1] >= USHRT_MAX)
                throw ErrorClass("This problem is too large to be solved by this version of the code!\n"
                               + "Recompile without -DUSERSHORTINDS to fix the problem.\n");
#endif
            blockSize[i] = blockOffset[i] - blockOffset[i-1]; 
        }

        nC_rows = blockOffset[nBlocks-1];
        nC_blks = nBlocks-1;
        ncon    = osinstance->getConstraintNumber();

#ifndef NOSHORTS
        /** If we're using unsigned shorts, make sure that the problem isn't too big. */
        if (ncon >= USHRT_MAX) 
            throw ErrorClass("This problem is too large to be solved by this version of the code!\n"
                           + "Recompile without -DUSERSHORTINDS to fix the problem.\n");

        if (nBlocks >= USHRT_MAX)
            throw ErrorClass("This problem is too large to be solved by this version of the code!\n"
                           + "Recompile without -DUSERSHORTINDS to fix the problem.\n");
#endif

#ifndef BIT64
        /*
         * If operating in 32 bit mode, make sure that the dimension mDIM isn't
         * too big for 32 bits.  If we don't do this check, then integer overflow
         * won't be detected, and we'll allocate a bogus amount of storage.
         */
        if (ncon > 23169)
            throw ErrorClass("This problem is too large to be solved in 32 bit mode!\n");
#endif

        // set up the right hand side values. Note: 1-based for Fortran interface.
        rhsValues = osinstance->getConstraintLowerBounds() - 1;

        // Set up storage and retrieve pointers.
        mtxBlocks = new ExpandedMatrixBlocks*[ncon+1];
        for (int j=0; j < ncon+1; j++)
            mtxBlocks[j] = NULL;

        // At this point we know the dimensions of all blocks.
        // Keep track of diagonal blocks. Note: isdiag is 1-indexed
        isdiag = new bool[nBlocks];
        int expIdx;
        for (int i=1; i<nBlocks; i++)
            isdiag[i] = true;

        GeneralSparseMatrix* tmpBlock;
        for (int j=0; j < ncon+1; j++)
        {
            try
            {
                expIdx = osinstance->instanceData->matrices->matrix[mtxRef[j]]
                            ->getBlockExpansion(blockOffset, nBlocks, blockOffset, nBlocks,
                                                osinstance->instanceData->matrices->matrix,
                                                true, false, ENUM_MATRIX_TYPE_constant);
                if (expIdx < 0)
                    throw ErrorClass("Error during block expansion in OSCsdpSolver");

                mtxBlocks[j] = osinstance->instanceData->matrices->matrix[mtxRef[j]]
                    ->expandedMatrixByBlocks[expIdx];
            }
            catch(const ErrorClass& eclass)
            {
                std::cout << "error during getBlocks()" << std::endl;
            }
            if (!mtxBlocks[j]->isBlockDiagonal())
                throw ErrorClass("Constraint matrix must be block-diagonal");

            for (int i=0; i<nBlocks-1; i++)
            {
                tmpBlock = mtxBlocks[j]->getBlock(i,i);
                if (tmpBlock != NULL && !(tmpBlock->isDiagonal()))
                    isdiag[i+1] = false;
            }
        }

        /** Allocate space for the C matrix (A0). 
         * 
         *  Note: Each block is allocated, even a zero block.
         *        Worse, if the block is deemed full (because one of the constraint
         *        matrices A_i is not diagonal), a dense block of zeroes is created.
         */
        C_matrix.nblocks=nBlocks-1;
        C_matrix.blocks = new blockrec[nBlocks];

        /** Handle diagonal blocks and matrix blocks separately. */
        for (int blk=1; blk < nBlocks; blk++)
        {
            tmpBlock = mtxBlocks[0]->getBlock(blk-1,blk-1);
            int blksz = blockSize[blk];
            if (isdiag[blk] == 1)
            {
                // diagonal block
                C_matrix.blocks[blk].blocksize = blksz;
                C_matrix.blocks[blk].blockcategory = DIAG;
                C_matrix.blocks[blk].data.vec = new double[blksz+1];

                for (int i=1; i<=blksz; i++)
                    C_matrix.blocks[blk].data.vec[i] = 0.0;

                if (tmpBlock != NULL)
                {
                    for (int i=0; i < tmpBlock->valueSize; i++)
                        C_matrix.blocks[blk].data.vec[tmpBlock->index[i]+1]
                            = ((ConstantMatrixValues*)tmpBlock->value)->el[i];
                }
            }
            else
            {
                // There are off-diagonal elements (i.e., "matrix block") --- treat as dense
                C_matrix.blocks[blk].blocksize = blksz;
                C_matrix.blocks[blk].blockcategory = MATRIX;
                C_matrix.blocks[blk].data.mat = new double[blksz*blksz];

                for (int i=1; i<=blksz; i++)
                for (int j=1; j<=blksz; j++)
                    C_matrix.blocks[blk].data.mat[ijtok(i,j,blksz)] = 0.0;

                if (tmpBlock != NULL)
                {
                    for (int i=1; i < tmpBlock->startSize; i++)
                    for (int j=tmpBlock->start[i-1]; j<tmpBlock->start[i]; j++)
                    {
                        C_matrix.blocks[blk].data.mat[ijtok(i,tmpBlock->index[j]+1,blksz)]
                            = ((ConstantMatrixValues*)tmpBlock->value)->el[j];
                        C_matrix.blocks[blk].data.mat[ijtok(tmpBlock->index[j]+1,i,blksz)]
                            = ((ConstantMatrixValues*)tmpBlock->value)->el[j];
                    }
                }
            }
        }

        /** Allocate space for the constraints (again using 1-based indexing). */
        mconstraints = new constraintmatrix[ncon+1]; // leaks memory ??
  
        /** Null out all pointers in constraints. */
        for (int i=1; i<=ncon; i++)
        {
            mconstraints[i].blocks = NULL;
        }

        struct sparseblock *p;
        struct sparseblock *q;
        struct sparseblock *prev;

        /**
         * Go through all of the blocks in each of the constraint matrices,
         * and allocate space for the entries and indices.
         */
        for (int i=1; i<=ncon; i++)
        {
            prev = NULL;
            for (int blk=1; blk < nBlocks; blk++)
            {
                tmpBlock = mtxBlocks[i]->getBlock(blk-1,blk-1);
                if (tmpBlock != NULL && tmpBlock->valueSize > 0)
                {
                    /**
                     * initialize and allocate storage for the entries 
                     * in this block of this constraint.
                     */
                    p = new sparseblock();
                    p->numentries = tmpBlock->valueSize;
                    p->entries = new double[p->numentries+1];
#ifdef NOSHORTS
                    p->iindices = new int[p->numentries+1];
                    p->jindices = new int[p->numentries+1];
#else
                    p->iindices = new unsigned short[p->numentries+1];
                    p->jindices = new unsigned short[p->numentries+1];
#endif
                    p->blocknum = blk;
                    p->blocksize = blockSize[blk];
                    p->constraintnum = i;
                    p->next        = NULL;
                    p->nextbyblock = NULL;
                    if (((p->numentries) > 0.25*(p->blocksize)) && ((p->numentries) > 15))
                        p->issparse=0;
                    else
                        p->issparse=1;

                    // Note: everything is 1-indexed, so both locations and indices are shifted 
                    for (int icol=1; icol < tmpBlock->startSize; icol++)
                    for (int jent=tmpBlock->start[icol-1]; jent<tmpBlock->start[icol]; jent++)
                    {
                        p->iindices[jent+1] = icol;
                        p->jindices[jent+1] = tmpBlock->index[jent] + 1;
                        p->entries [jent+1] = ((ConstantMatrixValues*)tmpBlock->value)->el[jent];
                    }

                    if (prev == NULL)
                    {
                        mconstraints[i].blocks = p;
                    }
                    else
                    {
                        prev->next        = p;
                        prev->nextbyblock = p;
                    }
                    prev = p;                  
                }
            }
        }

        //garbage collection
        if (blockOffset != NULL) delete [] blockOffset;
        if (blockSize   != NULL) delete [] blockSize;
        if (mtxRef      != NULL) delete [] mtxRef;
        if (isdiag      != NULL) delete [] isdiag;
        if (mtxBlocks   != NULL)
        {
            for (int i=0; i < ncon+1; i++)
            {
//                if (mtxBlocks[i] != NULL) delete mtxBlocks[i];
                mtxBlocks[i] = NULL;
            }
            delete []mtxBlocks;
            mtxBlocks = NULL;
        }

        this->bCallbuildSolverInstance = true;
        return;
    }

    catch(const ErrorClass& eclass)
    {
        if (blockOffset != NULL) delete [] blockOffset;
        if (blockSize   != NULL) delete [] blockSize;
        if (mtxRef      != NULL) delete [] mtxRef;
        if (isdiag      != NULL) delete [] isdiag;
        {
            for (int i=0; i <= ncon; i++)
            {
//                if (mtxBlocks[i] != NULL) delete mtxBlocks[i];
                mtxBlocks[i] = NULL;
            }
            delete []mtxBlocks;
            mtxBlocks = NULL;
        }

        osresult = new OSResult();
        osresult->setGeneralMessage( eclass.errormsg);
        osresult->setGeneralStatusType( "error");
        osrl = osrlwriter->writeOSrL( osresult);
        throw ErrorClass( osrl);
    }

}// end buildSolverInstance()


void  CsdpSolver::setSolverOptions()
{
/**
 * Since CSDP provides no user interface for solver options 
 * other than reading them in from the file param.csdp (if this file exists)
 * the only choice is to write the options to file so that
 * they can be read back by the CSDP method initparams(), called from easy_sdp().
 *
 * Note also that initial values are not treated here; 
 * there is the special method setInitialValues() that should be used for that purpose.
 */

    struct paramstruc params;

    std::ostringstream outStr;
    std::ostringstream optStr;
    int printlevel = 0;

    try
    {
        /* set default values first
         * Unfortunately there seems to be no way around a complete enumeration of options
         */
        double axtol       = 1.0e-8;
        double atytol      = 1.0e-8;
        double objtol      = 1.0e-8;
        double pinftol     = 1.0e8;
        double dinftol     = 1.0e8;
        double minstepfrac = 0.90;
        double maxstepfrac = 0.97;
        double minstepp    = 1.0e-8;
        double minstepd    = 1.0e-8;
        int maxiter        = 100;
        int usexzgap       = 1;
        int tweakgap       = 0;
        int affine         = 0;
        int perturbobj     = 1;
        int fastmode       = 0;
        int pprintlevel    = 1;

        /* get options from OSoL */
        if(osoption == NULL && osol.length() > 0)
        {
            m_osolreader = new OSoLReader();
            osoption = m_osolreader->readOSoL( osol);
        }

        if( osoption != NULL  &&  osoption->getNumberOfSolverOptions() > 0 )
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "number of solver options ";
            outStr << osoption->getNumberOfSolverOptions();
            outStr << std::endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            std::vector<SolverOptionOrResult*> optionsVector;
            optionsVector = osoption->getSolverOptions( "csdp",true);
            char *pEnd;
            std::vector<SolverOptionOrResult*>::size_type i, num_csdp_options;
            num_csdp_options = optionsVector.size();
            for(i = 0; i < num_csdp_options; i++)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "csdp solver option  ";
                outStr << optionsVector[ i]->name;
                outStr << std::endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
                // Store value
                if (optionsVector[ i]->name == "axtol")
                    axtol = atof(optionsVector[ i]->value.c_str());
                else if (optionsVector[ i]->name == "atytol")
                    atytol = atof(optionsVector[ i]->value.c_str());
                else if (optionsVector[ i]->name == "objtol")
                    objtol = atof(optionsVector[ i]->value.c_str());
                else if (optionsVector[ i]->name == "pinftol")
                    pinftol = atof(optionsVector[ i]->value.c_str());
                else if (optionsVector[ i]->name == "dinftol")
                    dinftol = atof(optionsVector[ i]->value.c_str());
                else if (optionsVector[ i]->name == "minstepfrac")
                    minstepfrac = atof(optionsVector[ i]->value.c_str());
                else if (optionsVector[ i]->name == "maxstepfrac")
                    maxstepfrac = atof(optionsVector[ i]->value.c_str());
                else if (optionsVector[ i]->name == "minstepp")
                    minstepp = atof(optionsVector[ i]->value.c_str());
                else if (optionsVector[ i]->name == "minstepd")
                    minstepd = atof(optionsVector[ i]->value.c_str());
                else if (optionsVector[ i]->name == "maxiter")
                    maxiter = atoi(optionsVector[ i]->value.c_str());
                else if (optionsVector[ i]->name == "usexzgap")
                    usexzgap = atoi(optionsVector[ i]->value.c_str());
                else if (optionsVector[ i]->name == "tweakgap")
                    tweakgap = atoi(optionsVector[ i]->value.c_str());
                else if (optionsVector[ i]->name == "affine")
                    affine = atoi(optionsVector[ i]->value.c_str());
                else if (optionsVector[ i]->name == "perturbobj")
                    perturbobj = atoi(optionsVector[ i]->value.c_str());
                else if (optionsVector[ i]->name == "fastmode")
                    fastmode = atoi(optionsVector[ i]->value.c_str());
                else if (optionsVector[ i]->name == "pprintlevel")
                    pprintlevel = atoi(optionsVector[ i]->value.c_str());
            }

            // Write the values into the CSDP option file "param.csdp"
            optStr << "axtol="       << os_dtoa_format(axtol)       << std::endl;
            optStr << "atytol="      << os_dtoa_format(atytol)      << std::endl;
            optStr << "objtol="      << os_dtoa_format(objtol)      << std::endl;
            optStr << "pinftol="     << os_dtoa_format(pinftol)     << std::endl;
            optStr << "dinftol="     << os_dtoa_format(dinftol)     << std::endl;
            optStr << "maxiter="     <<                maxiter      << std::endl;
            optStr << "minstepfrac=" << os_dtoa_format(minstepfrac) << std::endl;
            optStr << "maxstepfrac=" << os_dtoa_format(maxstepfrac) << std::endl;
            optStr << "minstepp="    << os_dtoa_format(minstepp)    << std::endl;
            optStr << "minstepd="    << os_dtoa_format(minstepd)    << std::endl;
            optStr << "usexzgap="    <<                usexzgap     << std::endl;
            optStr << "tweakgap="    <<                tweakgap     << std::endl;
            optStr << "affine="      <<                affine       << std::endl;
            optStr << "printlevel="  <<                pprintlevel  << std::endl;
            optStr << "perturbobj="  <<                perturbobj   << std::endl;
            optStr << "fastmode="    <<                fastmode     << std::endl;

            FILE *paramfile;

            //Check if param.csdp exists already
            paramfile=fopen("param.csdp","r");
            if (paramfile != 0)
            {
                tempOptionFile = "param7834910.csdp";
                int IOStatus = rename ( "param.csdp", tempOptionFile.c_str() );
                if (IOStatus != 0)
                    throw ErrorClass("CsdpSolver: Cannot rename param.csdp");                    
            }

            paramfile=fopen("param.csdp","w");
            if (!paramfile)
                throw ErrorClass("CsdpSolver: File open error during option initialization");

            fprintf(paramfile,"%s",(optStr.str()).c_str());
            fclose(paramfile);
        }
        bSetSolverOptions = true;
        return;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, 
            "Error in setSolverOption\n");
        osresult->setGeneralMessage( eclass.errormsg);
        osresult->setGeneralStatusType( "error");
        osrl = osrlwriter->writeOSrL( osresult);
        throw ErrorClass( osrl);
    }
}//setSolverOptions

/**
 * Build an initial solution for an SDP problem.
 * The default value is taken from Brian Borchers' code CSDP.
 * However, this initialization routine allows user-defined starting values
 */
void CsdpSolver::setInitialValues(int n, int k, struct blockmatrix C, double *a, 
    struct constraintmatrix *constraints, struct blockmatrix *pX0,
    double **py0, struct blockmatrix *pZ0)
{
    try
    {
        std::ostringstream outStr;
        int i,j;
        double alpha,beta;
        double maxnrmA,nrmA;
        double nrmC;
        double scale1, scale2;
        struct sparseblock *ptr;

        /*
         *  First, allocate storage for X0, Z0, and y0.
         *  For X0 and Y0 use the same dimensions and structure as the C_matrix.
         */
        int nBlk  = C_matrix.nblocks + 1;
        X.nblocks = C_matrix.nblocks;
        Z.nblocks = C_matrix.nblocks;
        X.blocks  = new blockrec[nBlk];
        Z.blocks  = new blockrec[nBlk];

        /** Handle diagonal blocks and matrix blocks separately. */
        for (int blk=1; blk < nBlk; blk++)
        {
            int blksz = C_matrix.blocks[blk].blocksize;
            X.blocks[blk].blocksize = blksz;
            Z.blocks[blk].blocksize = blksz;
            X.blocks[blk].blockcategory = C_matrix.blocks[blk].blockcategory;
            Z.blocks[blk].blockcategory = C_matrix.blocks[blk].blockcategory;
            if (C_matrix.blocks[blk].blockcategory == DIAG)
            {
                // diagonal block
                X.blocks[blk].data.vec = new double[blksz+1];
                Z.blocks[blk].data.vec = new double[blksz+1];

                for (int i=1; i<=blksz; i++)
                {
                    X.blocks[blk].data.vec[i] = 0.0;
                    Z.blocks[blk].data.vec[i] = 0.0;
                }
            }
            else
            {
                // There are off-diagonal elements (i.e., "matrix block") --- treat as dense
                X.blocks[blk].data.mat = new double[blksz*blksz];
                Z.blocks[blk].data.mat = new double[blksz*blksz];

                for (int i=1; i<=blksz; i++)
                for (int j=1; j<=blksz; j++)
                {
                    X.blocks[blk].data.mat[ijtok(i,j,blksz)] = 0.0;
                    Z.blocks[blk].data.mat[ijtok(i,j,blksz)] = 0.0;
                }
            }
        }

        y = new double[k+1];

        /**
         *  Retrieve user-defined initial values (if any)
         *  Infer partition from the block sizes of the C matrix
         */
        int* blockPartition = new int[nBlk];
        blockPartition[0] = 0;
        for (int i=0; i < nBlk; i++)
            blockPartition[i+1] = blockPartition[i] + C_matrix.blocks[i+1].blocksize;

        ExpandedMatrixBlocks* initPrimal = NULL;
        ExpandedMatrixBlocks* initDual   = NULL;

        if (osoption != NULL)
        {
            OSMatrix** mtxArray = NULL;
            if (osoption->optimization                   != NULL &&
                osoption->optimization->matrices         != NULL &&
                osoption->optimization->matrices->matrix != NULL)
                mtxArray = osoption->optimization->matrices->matrix;

            initPrimal = osoption->getInitialMatrixVarBlocks(0, mtxArray,
                                                    blockPartition, nBlk,
                                                    blockPartition, nBlk,
                                                    ENUM_MATRIX_TYPE_constant,
                                                    ENUM_MATRIX_SYMMETRY_lower);

            initDual = osoption->getInitialMatrixDualVarBlocks(0, mtxArray,
                                                    blockPartition, nBlk,
                                                    blockPartition, nBlk,
                                                    ENUM_MATRIX_TYPE_constant,
                                                    ENUM_MATRIX_SYMMETRY_lower);
        }

        if (initPrimal != NULL)
        {
            initPrimal->printBlocks();

            /* Verify the shape: blockdiagonal, with blocks of the right shape */
            if (!initPrimal->isBlockDiagonal())
                throw ErrorClass("CsdpSolver::setInitialValues: matrix not block-diagonal");

            for (int i=1; i < nBlk; i++)
            {
                if ( ( C_matrix.blocks[i].blockcategory == DIAG ) &&
                     ( !(initPrimal->blocks[i-1]->isDiagonal() ) ) )
                    throw ErrorClass("CsdpSolver::setInitialValues: matrix block not diagonal");
            }
        }

        if (initDual != NULL)
        {
            initDual->printBlocks();

            /* Check the shape again */
            if (!initDual->isBlockDiagonal())
                throw ErrorClass("CsdpSolver::setInitialDualValues: matrix not block-diagonal");

            for (int i=1; i < nBlk; i++)
            {
                if ( ( C_matrix.blocks[i].blockcategory == DIAG ) &&
                     ( !(initPrimal->blocks[i-1]->isDiagonal() ) ) )
                    throw ErrorClass("CsdpSolver::setInitialDualValues: matrix block not diagonal");
            }
        }

        /*  if either initial primal or dual values are NULL, we need to compute 
         * 
         *       alpha = n*max_i((1+|a_i|)/(1+||A_i||)).  
         */
        if (initPrimal == NULL || initDual == NULL)
        {
            maxnrmA = 0.0;
            alpha   = 0.0;
            for (i=1; i<=k; i++)
            {
                nrmA = 0.0;
                ptr  = mconstraints[i].blocks;

                while (ptr != NULL)
	            {
	                for (j=1; j<=ptr->numentries; j++)
	                {
	                    nrmA += (ptr->entries[j])*(ptr->entries[j]);
	                    if (ptr->iindices[j] != ptr->jindices[j])
	    	                nrmA += (ptr->entries[j])*(ptr->entries[j]);
	                }
	                ptr = ptr->next;
	            }

                nrmA = sqrt(nrmA);
                if (nrmA > maxnrmA)
	                maxnrmA = nrmA;

                if ((1+fabs(a[i]))/(1+nrmA) > alpha)
                    alpha = (1+fabs(a[i]))/(1+nrmA);
            }

            alpha = n*alpha;
        }

        /* If initial dual values is NULL, we also need a default initial dual value
         * based on the F norm of C.
         */
        if (initDual == NULL)
        {
            nrmC = Fnorm(C_matrix);

            if (nrmC > maxnrmA)
            {
                beta = (1+nrmC)/sqrt(n*1.0);
            }
            else
            {
                beta = (1+maxnrmA)/sqrt(n*1.0);
            }
        }
        
        /*
         * Now initial the values. Defaults are X=100*alpha*I, Z=100*beta*I, y=0.
         */

        if (initPrimal == NULL)
        {
            scale1=10*alpha;

            for (int blk=1; blk < nBlk; blk++)
            {
                int blksz = X.blocks[blk].blocksize;
                if (X.blocks[blk].blockcategory == DIAG)
                {
                    for (int i=0; i < blksz; i++)
                        X.blocks[blk].data.vec[i+1] = scale1;
                }
                else
                {
                    for (int i=1; i <= blksz; i++)
                        X.blocks[blk].data.mat[ijtok(i,i,blksz)] = scale1;
                }
            }
        }
        else
        {
            // note that the matrix X0 was allocated already. Structure and shape is in place

            /** Handle diagonal blocks and matrix blocks separately. */
            for (int blk=1; blk < nBlk; blk++)
            {
                GeneralSparseMatrix* tmpBlock = initPrimal->getBlock(blk-1,blk-1);
                int blksz = X.blocks[blk].blocksize;
                if (X.blocks[blk].blockcategory == DIAG)
                {
                    if (tmpBlock != NULL)
                    {
                        for (int i=0; i < tmpBlock->valueSize; i++)
                            X.blocks[blk].data.vec[tmpBlock->index[i]+1]
                                = ((ConstantMatrixValues*)tmpBlock->value)->el[i];
                    }
                }
                else
                {
                    if (tmpBlock != NULL)
                    {
                        for (int i=1; i < tmpBlock->startSize; i++)
                        for (int j=tmpBlock->start[i-1]; j<tmpBlock->start[i]; j++)
                        {
                            X.blocks[blk].data.mat[ijtok(i,tmpBlock->index[j]+1,blksz)]
                                = ((ConstantMatrixValues*)tmpBlock->value)->el[j];
                            X.blocks[blk].data.mat[ijtok(tmpBlock->index[j]+1,i,blksz)]
                                = ((ConstantMatrixValues*)tmpBlock->value)->el[j];
                        }
                    }
                }
            }
        }

#ifndef NDEBUG
        outStr.str("");
        outStr.clear();

        outStr << std::endl << std::endl << "Initial X matrix:" << std::endl;
        for (int blk=1; blk < nBlk; blk++)
        {
            int blksz = X.blocks[blk].blocksize;
            if (X.blocks[blk].blockcategory == DIAG)
            {
                // diagonal block
                outStr << "Block " << blk << " is diagonal; size = " << blksz << std::endl;
                outStr << "   Diagonal entries: ";
                for (int i=1; i<=blksz; i++)
                {
                    outStr << X.blocks[blk].data.vec[i] << "    ";
                }
                outStr << std::endl;
            }
            else
            {
                // dense matrix
                outStr << "Block " << blk << " is dense; size = " << blksz << std::endl;

                for (int i=1; i<=blksz; i++)
                {
                    outStr << std::endl << "col " << i << " has entries:" << std::endl;
                    for (int j=1; j<=blksz; j++)
                    {
                        outStr << "(loc " << ijtok(i,j,blksz) << ") ";
                        outStr << X.blocks[blk].data.mat[ijtok(i,j,blksz)] << std::endl;
                    }
                }
                outStr << std::endl;
            }
        }
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif

        if (initDual == NULL)
        {
            scale2=10*beta;

            for (int blk=1; blk < nBlk; blk++)
            {
                int blksz = Z.blocks[blk].blocksize;
                if (Z.blocks[blk].blockcategory == DIAG)
                {
                    for (int i=0; i < blksz; i++)
                        Z.blocks[blk].data.vec[i+1] = scale2;
                }
                else
                {
                    for (int i=1; i <= blksz; i++)
                        Z.blocks[blk].data.mat[ijtok(i,i,blksz)] = scale2;
                }
            }
        }
        else
        {
            /** Handle diagonal blocks and matrix blocks separately. */
            for (int blk=1; blk < nBlk; blk++)
            {
                GeneralSparseMatrix* tmpBlock = initDual->getBlock(blk-1,blk-1);
                int blksz = Z.blocks[blk].blocksize;
                if (Z.blocks[blk].blockcategory == DIAG)
                {
                    if (tmpBlock != NULL)
                    {
                        for (int i=0; i < tmpBlock->valueSize; i++)
                            Z.blocks[blk].data.vec[tmpBlock->index[i]+1]
                                = ((ConstantMatrixValues*)tmpBlock->value)->el[i];
                    }
                }
                else
                {
                    if (tmpBlock != NULL)
                    {
                        for (int i=1; i < tmpBlock->startSize; i++)
                        for (int j=tmpBlock->start[i-1]; j<tmpBlock->start[i]; j++)
                        {
                            Z.blocks[blk].data.mat[ijtok(i,tmpBlock->index[j]+1,blksz)]
                                = ((ConstantMatrixValues*)tmpBlock->value)->el[j];
                            Z.blocks[blk].data.mat[ijtok(tmpBlock->index[j]+1,i,blksz)]
                                = ((ConstantMatrixValues*)tmpBlock->value)->el[j];
                        }
                    }
                }
            }
        }

#ifndef NDEBUG
        outStr.str("");
        outStr.clear();

        outStr << std::endl << std::endl << "Initial Z matrix:" << std::endl;
        for (int blk=1; blk < nBlk; blk++)
        {
            int blksz = Z.blocks[blk].blocksize;
            if (Z.blocks[blk].blockcategory == DIAG)
            {
                // diagonal block
                outStr << "Block " << blk << " is diagonal; size = " << blksz << std::endl;
                outStr << "   Diagonal entries: ";
                for (int i=1; i<=blksz; i++)
                {
                    outStr << Z.blocks[blk].data.vec[i] << "    ";
                }
                outStr << std::endl;
            }
            else
            {
                // dense matrix
                outStr << "Block " << blk << " is dense; size = " << blksz << std::endl;

                for (int i=1; i<=blksz; i++)
                {
                    outStr << std::endl << "col " << i << " has entries:" << std::endl;
                    for (int j=1; j<=blksz; j++)
                    {
                        outStr << "(loc " << ijtok(i,j,blksz) << ") ";
                        outStr << Z.blocks[blk].data.mat[ijtok(i,j,blksz)] << std::endl;
                    }
                }
                outStr << std::endl;
            }
        }
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif


        /** Finally the dual variables for the original constraints */
        double* initUBDuals = NULL;
        double* initLBDuals = NULL;

        if (osoption != NULL)
        {
            initUBDuals = osoption->getInitDualVarUpperBoundsDense();
            initLBDuals = osoption->getInitDualVarLowerBoundsDense();
        }

        if (initUBDuals != NULL && initLBDuals != NULL)
        {
            for (i=1; i<=k; i++)
                (*py0)[i] = initUBDuals[i-1] + initLBDuals[i-1];
        }
        else
        {
            for (i=1; i<=k; i++)
                (*py0)[i]=0;

        }

        return;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_error, "Error while setting options in CSDPSolver\n");
        osresult->setGeneralMessage( eclass.errormsg);
        osresult->setGeneralStatusType( "error");
        osrl = osrlwriter->writeOSrL( osresult);
        throw ErrorClass( osrl) ;
    }
}//end setInitialValues()

 
void  CsdpSolver::solve()
{
    std::ostringstream outStr;
    double* mdObjValues = NULL;
    int* colOffset = NULL;
    int* colOffsetD = NULL;
    int* rowOffset = NULL;
    int* rowOffsetD = NULL;


    if( this->bCallbuildSolverInstance == false) buildSolverInstance();
    if( this->bSetSolverOptions == false) setSolverOptions();
    try
    {
        /*
         * Create an initial solution.  This allocates space for X, y, and Z,
         * and sets initial values.
         */
        setInitialValues(nC_rows,ncon,C_matrix,rhsValues,mconstraints,&X,&y,&Z);

        //call solver
        int returnCode = easy_sdp(nC_rows, ncon, C_matrix, rhsValues, 
                                  mconstraints, 0.0, &X, &y, &Z, &pobj, &dobj);

        unsigned int solIdx = 0;
        unsigned int numberOfOtherVariableResults;
        unsigned int otherIdx;
        unsigned int numCon = osinstance->getConstraintNumber();

        if(osinstance->getObjectiveNumber() > 0)   
        {
            mdObjValues = new double[1];
            mdObjValues[0] = (dobj+pobj)/2;
            outStr << std::endl << "Objective value f(x*) = " << os_dtoa_format(mdObjValues[0]);
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_summary, outStr.str());
        }

        std::string message = "Csdp solver finishes to the end.";
        std::string solutionDescription = "";

        // write resultHeader information
        if(osresult->setSolverInvoked( "COIN-OR Csdp") != true)
            throw ErrorClass("OSResult error: setSolverInvoked");
        if(osresult->setServiceName( OSgetVersionInfo()) != true)
            throw ErrorClass("OSResult error: setServiceName");
        if(osresult->setInstanceName(  osinstance->getInstanceName()) != true)
            throw ErrorClass("OSResult error: setInstanceName");

        //if(osresult->setJobID( osoption->jobID) != true)
        //    throw ErrorClass("OSResult error: setJobID");

        // set basic problem parameters
        if(osresult->setVariableNumber( osinstance->getVariableNumber()) != true)
            throw ErrorClass("OSResult error: setVariableNumer");

        if(osresult->setObjectiveNumber( 1) != true)
            throw ErrorClass("OSResult error: setObjectiveNumber");
        if(osresult->setConstraintNumber( osinstance->getConstraintNumber()) != true)
            throw ErrorClass("OSResult error: setConstraintNumber");
        if(osresult->setSolutionNumber(  1) != true)
            throw ErrorClass("OSResult error: setSolutionNumer");
        if(osresult->setGeneralMessage( message) != true)
            throw ErrorClass("OSResult error: setGeneralMessage");


        switch( returnCode)
        {
        case 0:
        case 3:
        {
            if (returnCode == 0)
            {
                solutionDescription = "SUCCESS[Csdp]: Algorithm terminated normally at an optimal point, satisfying the convergence tolerances.";
                osresult->setSolutionStatus(solIdx,  "optimal", solutionDescription);
            }
            else
            {
                solutionDescription = "PARTIAL SUCCESS[Csdp]: A solution has been found, but full accuracy was not achieved.";
                osresult->setSolutionStatus(solIdx,  "unsure", solutionDescription);
            }

            if (osinstance->getObjectiveNumber() > 0)
                osresult->setObjectiveValuesDense(solIdx, mdObjValues);
            //set X, y, Z
            if(numCon > 0)
                osresult->setDualVariableValuesDense(solIdx, y+1); // !! Csdp uses Fortran indexing 

            colOffset = new int[X.nblocks+1];
            colOffset[0] = 0;
            for (int i=1; i<=X.nblocks; i++)
                colOffset[i] = colOffset[i-1] + X.blocks[i].blocksize;

            colOffsetD = new int[Z.nblocks+1];
            colOffsetD[0] = 0;
            for (int i=1; i<=Z.nblocks; i++)
                colOffsetD[i] = colOffsetD[i-1] + Z.blocks[i].blocksize;

            // initial the <variables> element: one primal matrixVar, one dual matrixVar (in <other>)
            if (!osresult->setMatrixVariableSolution(0,1,1))
                throw ErrorClass("OSResult error: setMatrixVariableSolution");


            if (!osresult->setMatrixVarValuesAttributes(0,0,0,colOffset[X.nblocks],
                                                   colOffset[X.nblocks], ENUM_MATRIX_SYMMETRY_lower))
                throw ErrorClass("OSResult error: setMatrixVarValuesAttributes");

            if (!osresult->setMatrixVariablesOtherResultGeneralAttributes(0, 0, "dual matrix", 
                                                                     "", "", "", "csdp", "", 1))
                throw ErrorClass("OSResult error: setMatrixVariablesOtherResultGeneralAttributes");
            if (!osresult->setMatrixVariablesOtherResultMatrixAttributes(0, 0, 0, 
                            colOffset[Z.nblocks],colOffset[Z.nblocks], ENUM_MATRIX_SYMMETRY_lower))
                throw ErrorClass("OSResult error: setMatrixVariablesOtherResultMatrixAttributes");

            if (!osresult->setMatrixVarValuesBlockStructure(0, 0, colOffset, X.nblocks + 1,
                                                       colOffset, X.nblocks + 1, X.nblocks))
                throw ErrorClass("OSResult error: setMatrixVarValuesBlockStructure");

            if (!osresult->setMatrixVariablesOtherResultBlockStructure(0, 0, 0, colOffsetD, Z.nblocks + 1,
                                                       colOffsetD, Z.nblocks + 1, Z.nblocks))
                throw ErrorClass("OSResult error: setMatrixVariablesOtherResultBlockStructure");

            int*    start;
            int*    index;
            ConstantMatrixValues* value;

            int nonz;
            double ent;

            //count nonzeroes and set column starts
            for (int blk=1; blk<=X.nblocks; blk++)
            {
                start = new int[colOffset[blk]-colOffset[blk-1]+1]; // leaks memory
                start[0] = 0;
                nonz = 0;

                switch (X.blocks[blk].blockcategory)
                {
                    case DIAG:
                        for (int i=1; i<=X.blocks[blk].blocksize; i++)
                        {
                            ent=X.blocks[blk].data.vec[i];
                            if (ent != 0.0)
                                nonz++;
                            start[i] = nonz;
                        };
                        break;
                    case MATRIX:
                        for (int i=1; i<=X.blocks[blk].blocksize; i++)
                        {
                            for (int j=i; j<=X.blocks[blk].blocksize; j++)
                            {
                                ent=X.blocks[blk].data.mat[ijtok(i,j,X.blocks[blk].blocksize)];
                                if (ent != 0.0)
                                    nonz++;
                            };
                            start[i] = nonz;
                        };
                        break;
                    case PACKEDMATRIX:
                    default:
                        throw ErrorClass("Invalid Block Type in CSDP solution");
                }; // end switch

                // go through nonzeros a second time and store values
                index = new    int[nonz]; // leaks memory
                value = new ConstantMatrixValues(); // leaks memory
                value->numberOfEl = nonz;
                value->el = new double[nonz];

                nonz = 0;
                switch (X.blocks[blk].blockcategory)
                {
                    case DIAG:
                        for (int i=1; i<=X.blocks[blk].blocksize; i++)
                        {
                            ent=X.blocks[blk].data.vec[i];
                            if (ent != 0.0)
                            {
                                index[nonz] = i-1;
                                value->el[nonz] = ent;
                                nonz++;
                            }
                        };
                        break;
                    case MATRIX:
                        for (int i=1; i<=X.blocks[blk].blocksize; i++)
                        {
                            for (int j=i; j<=X.blocks[blk].blocksize; j++)
                            {
                                ent=X.blocks[blk].data.mat[ijtok(i,j,X.blocks[blk].blocksize)];
                                if (ent != 0.0)
                                {
                                    index[nonz] = j-1;
                                    value->el[nonz] = ent;
                                    nonz++;
                                }
                            };
                            start[i] = nonz;
                        };
                        break;
                    case PACKEDMATRIX:
                    default:
                        throw ErrorClass("Invalid Block Type in CSDP solution");
                }; // end switch


                if (!osresult->setMatrixVarValuesBlockElements(0, 0, blk-1, blk-1, blk-1, nonz, 
                                                          start, index, value,
                                                          ENUM_MATRIX_TYPE_constant, 
                                                          ENUM_MATRIX_SYMMETRY_lower))
                    throw ErrorClass("OSResult error: setMatrixVarValuesBlockElements");
                if (start != NULL)
                    delete[] start;
                start = NULL;
                if (index != NULL)
                    delete[] index;
                index = NULL;
                if (value != NULL)
                    delete value;
                value = NULL;
            }; // end block

            // now the dual variables
            for (int blk=1; blk<=Z.nblocks; blk++)
            {
                start = new int[colOffsetD[blk]-colOffsetD[blk-1]+1]; // leaks memory
                start[0] = 0;
                nonz = 0;

                switch (Z.blocks[blk].blockcategory)
                {
                    case DIAG:
                        for (int i=1; i<=Z.blocks[blk].blocksize; i++)
                        {
                            ent=Z.blocks[blk].data.vec[i];
                            if (ent != 0.0)
                                nonz++;
                            start[i] = nonz;
                        };

                        break;
                    case MATRIX:
                        for (int i=1; i<=Z.blocks[blk].blocksize; i++)
                        {
                            for (int j=i; j<=Z.blocks[blk].blocksize; j++)
                            {
                                ent=Z.blocks[blk].data.mat[ijtok(i,j,Z.blocks[blk].blocksize)];
                                if (ent != 0.0)
                                    nonz++;
                            };
                            start[i] = nonz;
                        };
                        break;
                    case PACKEDMATRIX:
                    default:
                        throw ErrorClass("Invalid Block Type in CSDP solution");
                }; // end switch

                // go through nonzeros a second time and store values
                index = new    int[nonz]; // leaks memory
                value = new ConstantMatrixValues(); // leaks memory
                value->numberOfEl = nonz;
                value->el = new double[nonz];

                nonz = 0;
                switch (Z.blocks[blk].blockcategory)
                {
                    case DIAG:
                        for (int i=1; i<=Z.blocks[blk].blocksize; i++)
                        {
                            ent=Z.blocks[blk].data.vec[i];
                            if (ent != 0.0)
                            {
                                index[nonz] = i-1;
                                value->el[nonz] = ent;
                                nonz++;
                            }
                        };
                        break;
                    case MATRIX:
                        for (int i=1; i<=Z.blocks[blk].blocksize; i++)
                        {
                            for (int j=i; j<=Z.blocks[blk].blocksize; j++)
                            {
                                ent=Z.blocks[blk].data.mat[ijtok(i,j,Z.blocks[blk].blocksize)];
                                if (ent != 0.0)
                                {
                                    index[nonz] = j-1;
                                    value->el[nonz] = ent;
                                    nonz++;
                                }
                            };
                            start[i] = nonz;
                        };
                        break;
                    case PACKEDMATRIX:
                    default:
                        throw ErrorClass("Invalid Block Type in CSDP solution");

                }; // end switch

                if (!osresult->setMatrixVariablesOtherResultBlockElements(0, 0, 0, blk-1, blk-1, blk-1,  
                                                          nonz, start, index, value,
                                                          ENUM_MATRIX_TYPE_constant, 
                                                          ENUM_MATRIX_SYMMETRY_lower))
                    throw ErrorClass("OSResult error: setMatrixVariablesOtherResultBlockElements");
                if (start != NULL)
                    delete[] start;
                start = NULL;
                if (index != NULL)
                    delete[] index;
                index = NULL;
                if (value != NULL)
                    delete value;
                value = NULL;
            }; // end block
            break;
        }
        case 1:
            solutionDescription = "PRIMAL_INFEASIBILITY[Csdp]: Problem is primal infeasible.";
            osresult->setSolutionStatus(solIdx,  "infeasible", solutionDescription);
            break;

        case 2:
            solutionDescription = "DUAL_INFEASIBILITY[Csdp]: Problem is dual infeasible.";
            osresult->setSolutionStatus(solIdx,  "infeasible", solutionDescription);
            break;

        case 4:
            solutionDescription = "MAXITER_EXCEEDED[Csdp]: Maximum number of iterations exceeded.";
            osresult->setSolutionStatus(solIdx,  "stoppedByLimit", solutionDescription);
            break;

        case 5:
            solutionDescription = "STUCK AT EDGE[Csdp]: Stuck at edge of primal infeasibility.";
            osresult->setSolutionStatus(solIdx,  "error", solutionDescription);
            break;

        case 6:
            solutionDescription = "STUCK AT EDGE[Csdp]: Stuck at edge of dual infeasibility.";
            osresult->setSolutionStatus(solIdx,  "error", solutionDescription);
            break;

        case 7:
            solutionDescription = "LACK OF PROGRESS[Csdp]: Stopped due to lack of progress.";
            osresult->setSolutionStatus(solIdx,  "error", solutionDescription);
            break;

        case 8:
            solutionDescription = "SINGULARITY DETECTED[Csdp]: X, Z or O was singular.";
            osresult->setSolutionStatus(solIdx,  "error", solutionDescription);
            break;

        case 9:
            solutionDescription = "NaN or INF[Csdp]: Detected NaN or Infinity during computations.";
            osresult->setSolutionStatus(solIdx,  "error", solutionDescription);
            break;
        }

        if (returnCode != 0)
            throw ErrorClass("Csdp FAILED TO SOLVE THE PROBLEM");

        osrl = osrlwriter->writeOSrL( osresult);

        if (mdObjValues != NULL)
            delete[] mdObjValues;
        mdObjValues = NULL;

        if (colOffset != NULL)
            delete[] colOffset;
        colOffset = NULL;

        if (colOffsetD != NULL)
            delete[] colOffsetD;
        colOffsetD = NULL;
    }

    catch (const ErrorClass& eclass)
    {
        if (mdObjValues != NULL)
            delete[] mdObjValues;
        mdObjValues = NULL;

        if (colOffset != NULL)
            delete[] colOffset;
        colOffset = NULL;

        if (colOffsetD != NULL)
            delete[] colOffsetD;
        colOffsetD = NULL;

        outStr.str("");
        outStr.clear();
        outStr << "error in OSCsdpSolver routine solve():\n" << eclass.errormsg << endl;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_error, outStr.str());

        osresult->setGeneralMessage( eclass.errormsg);
        osresult->setGeneralStatusType( "error");
        osrl = osrlwriter->writeOSrL( osresult);
        throw ErrorClass( osrl) ;
    }
}

void CsdpSolver::dataEchoCheck()
{
    int i0, j0, blk0;
    struct sparseblock *pp;
    std::ostringstream outStr;

    outStr << std::endl << "Check problem data:" << std::endl << std::endl;

    outStr << "Dimension of matrices (number of rows):   n=" << nC_rows << std::endl;
    outStr << "Number of constraints (and matrices A_i): k=" << ncon  << std::endl;
    for (i0=1; i0 <= ncon; i0++)
    {
        outStr  << std::endl << "Right-hand side of constraint " << i0 << ": " 
                << rhsValues[i0] << std::endl;
        outStr << std::endl << "Data for matrix A_" << i0 << ":" << std::endl;
        pp = mconstraints[i0].blocks;
        while (pp != NULL)
        {
            outStr << std::endl << "Block " << pp->blocknum << ":" << std::endl;;
            outStr << "Block size: " << pp->blocksize << std::endl;
            outStr << "Number of entries: " << pp->numentries << std::endl;
            for (j0=1; j0 <= pp->numentries; j0++)
                outStr << "Entry in row " << pp->iindices[j0] << ", col " << pp->jindices[j0] 
                       << " has value " << pp->entries[j0] << std::endl;
            pp = pp->next;
        }
    }

    outStr << std::endl << "Data for matrix C:" << std::endl;
    outStr << "Number of blocks: " << C_matrix.nblocks << std::endl;
    for (blk0=1; blk0 <= C_matrix.nblocks; blk0++)
    {
        outStr << std::endl << "Data for block " << blk0 << ":" << std::endl;
        outStr << "Size: " << C_matrix.blocks[blk0].blocksize << std::endl;
        if (C_matrix.blocks[blk0].blockcategory == DIAG)
        {
            outStr << "Type: diagonal" << std::endl;
            for (i0=1; i0 <= C_matrix.blocks[blk0].blocksize; i0++)
                outStr << "Entry in row " << i0 << ", col " << i0 << " has value " 
                       << C_matrix.blocks[blk0].data.vec[i0] << std::endl;
        }
        else
        {
            outStr << "Type: dense" << std::endl;
            for (i0=1; i0 <= C_matrix.blocks[blk0].blocksize; i0++)
            for (j0=1; j0 <= C_matrix.blocks[blk0].blocksize; j0++)
                outStr << "Entry in row " << i0 << ", col " << j0 << " has value " 
                       << C_matrix.blocks[blk0].data.mat[ijtok(i0,j0,C_matrix.blocks[blk0].blocksize)]
                       << std::endl;
        }
    }
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
}


