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
#include "OSInstance.h"
#include "OSOption.h"
#include "OSFileUtil.h"
#include "OSOutput.h"
#include "CoinTime.hpp"

#include "OSGeneral.h"
#include "OSMatrix.h"
#include "OSParameters.h"
#include "OSMathUtil.h"

#include <map>

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

/*
 * These standard declarations for the C library are needed.
 */

#include <stdlib.h>
#include <stdio.h>

/*
 * Include CSDP declarations so that we'll know the calling interfaces.
 */

extern "C"
{
#include "declarations.h"
}

#include "parameters.h"

using std::cout;
using std::endl;
using std::ostringstream;


/*
   An example showing how to call the easy_sdp() interface to CSDP.
   In this example, we solve the problem
 
      max tr(C*X)
          tr(A1*X)=1
          tr(A2*X)=2
          X >= 0       (X is PSD)
 
   where 
 
    C=[2 1
       1 2
           3 0 1
           0 2 0
           1 0 3
                 0
                   0]

   A1=[3 1
       1 3
           0 0 0
           0 0 0
           0 0 0
                 1
                   0] 

   A2=[0 0
       0 0
           3 0 1
           0 4 0
           1 0 5
                 0
                   1] 

  Notice that all of the matrices have block diagonal structure.  The first
  block is of size 2x2.  The second block is of size 3x3.  The third block
  is a diagonal block of size 2.  
 */



CsdpSolver::CsdpSolver()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, 
        "inside CsdpSolver constructor\n");
#endif
    osrlwriter = new OSrLWriter();
    osresult = new OSResult();
    m_osilreader = NULL;
    m_osolreader = NULL;
    csdpErrorMsg = new std::string("");
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
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_trace, "Leaving CsdpSolver destructor\n");
#endif
}

void CsdpSolver::buildSolverInstance() throw (ErrorClass)
{
/*  These are declared in OSDefaultSolver.h (from which OSCsdpSolver inherits)
 *      std::string osil;
 *      std::string osol;
 *      std::string osrl;
 *      OSInstance *osinstance;
 *      OSOption   *osoption;
 *      OSResult   *osresult;
 *      std::string sSolverName;
 *      bool bCallbuildSolverInstance;
 *      bool bSetSolverOptions;
 */

/* Additional declarations from OSCsdpSolver.h
 *      int nC_rows;                            // number of rows/columns in each matrix
 *      int nC_blks;                            // number of blocks per matrix
 *      int ncon;                               // number of constraints (and constraint matrices A_i)
 *      struct blockmatrix *C_matrix;           // the matrix in the objective, A0
 *      double *rhsValues;                      // the right-hand side values of the constraints
 *      struct constraintmatrix **mconstraints; // the collection of matrices in the constraints (A_i)
 *      struct blockmatrix *X,*Z;               // for the primal and dual matrix values, respectively
 *      double *y;                              // dual variables of the constraints
 *      double pobj,dobj;                       // primal and dual objective values
 */

    std::ostringstream outStr;
    ScalarExpressionTree* tempTree;
    OSnLNode  *tr;
    OSnLMNode *mt;
    OSnLMNode *mr;
    OSnLMNode *mv;
    OSMatrix* tempMtx;

    int*  blockOffset = NULL;
    int*  blockSize   = NULL;
    int*  mtxRef      = NULL;
    bool* isdiag      = NULL;
    ExpandedMatrixBlocks** mtxBlocks;
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
        mt = tr->m_mMatrixChildren[0];
        if (mt->inodeInt != OS_MATRIX_TIMES)
            throw ErrorClass("Unsupported expression in objective row");
        mr = mt->m_mMatrixChildren[0];
        mv = mt->m_mMatrixChildren[1];
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

        //do the same for all constraints
        for (int i=0; i < osinstance->getConstraintNumber(); i++)
        {
            tempTree = osinstance->getNonlinearExpressionTree(i);
            if (tempTree == NULL) throw ErrorClass("Expecting matrixTrace in constraint row");
            tr = tempTree->m_treeRoot; 
            if (tr->inodeInt != OS_MATRIX_TRACE)
                throw ErrorClass("Expecting matrixTrace in constraint row");
            mt = tr->m_mMatrixChildren[0];
            if (mt->inodeInt != OS_MATRIX_TIMES)
                throw ErrorClass("Unsupported expression in constraint row");
            mr = mt->m_mMatrixChildren[0];
            mv = mt->m_mMatrixChildren[1];
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
//        rhsValues[0] = OSNaN(); // This is the tricky code to avoid having to copy. Legal?

        // Set up storage and retrieve pointers.
        mtxBlocks = new ExpandedMatrixBlocks*[ncon+1];
        GeneralSparseMatrix* tmpBlock;

        // At this point we know the dimensions of all blocks.
        // Keep track of diagonal blocks. Note: isdiag is 1-indexed
        isdiag = new bool[nBlocks];
        for (int i=1; i<nBlocks; i++)
            isdiag[i] = true;

        for (int j=0; j < ncon+1; j++)
        {
            mtxBlocks[j] = osinstance->instanceData->matrices->matrix[mtxRef[j]]
                ->getBlocks(blockOffset,nBlocks,blockOffset,nBlocks,false,true);

            if (!mtxBlocks[j]->isBlockDiagonal())
                throw ErrorClass("Constraint matrix must be block-diagonal");

            for (int i=0; i<nBlocks-1; i++)
            {
                tmpBlock = mtxBlocks[j]->getBlock(i,i);
                if (tmpBlock != NULL && !(tmpBlock->isDiagonal()))
                    isdiag[i+1] = false;
            }
        }

        /** Allocate space for the C matrix (A0). */
//        C_matrix = new blockmatrix();
        C_matrix.nblocks=nBlocks-1;
        C_matrix.blocks = new blockrec[nBlocks];

        /** Handle diagonal blocks and matrix blocks separately. */
        for (int blk=1; blk < nBlocks; blk++)
        {
            tmpBlock = mtxBlocks[0]->getBlock(blk-1,blk-1);
std::cout << "next block; blk= " << blk << std::endl;
std::cout << "block address: " << tmpBlock << std::endl;
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
                        C_matrix.blocks[blk].data.vec[tmpBlock->indexes[i]+1]
                            = ((ConstantMatrixValues*)tmpBlock->values)->el[i];
                }
            }
            else
            {
                // There are off-diagonals (i.e., "matrix block")
                C_matrix.blocks[blk].blocksize = blksz;
                C_matrix.blocks[blk].blockcategory = MATRIX;
                C_matrix.blocks[blk].data.mat = new double[blksz*blksz];

                for (int i=1; i<=blksz; i++)
                for (int j=1; j<=blksz; j++)
                    C_matrix.blocks[blk].data.mat[ijtok(i,j,blksz)] = 0.0;

                if (tmpBlock != NULL)
                {
                    for (int i=1; i < tmpBlock->startSize; i++)
                    for (int j=tmpBlock->starts[i-1]; j<tmpBlock->starts[i]; j++)
                    {
                        C_matrix.blocks[blk].data.mat[ijtok(i,tmpBlock->indexes[j]+1,blksz)]
                            = ((ConstantMatrixValues*)tmpBlock->values)->el[j];
                        C_matrix.blocks[blk].data.mat[ijtok(tmpBlock->indexes[j]+1,i,blksz)]
                            = ((ConstantMatrixValues*)tmpBlock->values)->el[j];
                    }
                }
            }
        }

        /** Allocate space for the constraints (again using 1-based indexing). */
        mconstraints = new constraintmatrix[ncon+1];
  
        /** Null out all pointers in constraints. */
        for (int i=1; i<=ncon; i++)
        {
//            mconstraints[i] = new constraintmatrix();
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
                    for (int jent=tmpBlock->starts[icol-1]; jent<tmpBlock->starts[icol]; jent++)
                    {
std::cout << "store element in col " << icol << ", row " << tmpBlock->indexes[jent] + 1;
std::cout << " (value " << ((ConstantMatrixValues*)tmpBlock->values)->el[jent];
std::cout << ") into location " << jent + 1 << std::endl;
                        p->iindices[jent+1] = icol;
                        p->jindices[jent+1] = tmpBlock->indexes[jent] + 1;
                        p->entries [jent+1] = ((ConstantMatrixValues*)tmpBlock->values)->el[jent];
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
#ifndef NDEBUG
        dataEchoCheck();
#endif

#if 0

  /*
   *  Put back all the returned values.
   */

//  *pconstraints=myconstraints;
  
  /*
   * Create an initial solution.  This allocates space for X, y, and Z,
   * and sets initial values.
   */

  initsoln(7,2,C,b,constraints,&X,&y,&Z);

  /* (This is from example.c)
   * Solve the problem.
   */

  ret=easy_sdp(7,2,C,b,constraints,0.0,&X,&y,&Z,&pobj,&dobj);


  /* (This is from csdp.c)
   * Call the solver.
   */

  ret=easy_sdp(n,k,C,a,constraints,0.0,&X,&y,&Z,&pobj,&dobj);


  if (ret == 0)
    printf("The objective value is %.7e \n",(dobj+pobj)/2);
  else
    printf("SDP failed.\n");

  /*
   * Write out the problem solution.
   */

  write_sol("prob.sol",7,2,X,y,Z);

  /*
   * Free storage allocated for the problem and return.
   */

  free_prob(7,2,C,b,constraints,X,y,Z);  
#endif
        //garbage collection
        if (blockOffset != NULL) delete [] blockOffset;
        if (blockSize   != NULL) delete [] blockSize;
        if (mtxRef      != NULL) delete [] mtxRef;
        if (isdiag      != NULL) delete [] isdiag;
        if (mtxBlocks   != NULL)
        {
            for (int i=0; i < ncon+1; i++)
            {
                if (mtxBlocks[i] != NULL) delete mtxBlocks[i];
                mtxBlocks[i] = NULL;
            }
            delete []mtxBlocks;
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
                if (mtxBlocks[i] != NULL) delete mtxBlocks[i];
                mtxBlocks[i] = NULL;
            }
            delete []mtxBlocks;
        }

        osresult = new OSResult();
        osresult->setGeneralMessage( eclass.errormsg);
        osresult->setGeneralStatusType( "error");
        osrl = osrlwriter->writeOSrL( osresult);
        throw ErrorClass( osrl);
    }

}// end buildSolverInstance()


void  CsdpSolver::setSolverOptions() throw(ErrorClass)
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

            std::vector<SolverOption*> optionsVector;
            optionsVector = osoption->getSolverOptions( "csdp",true);
            char *pEnd;
            int i;
            int num_ipopt_options = optionsVector.size();
            for(i = 0; i < num_ipopt_options; i++)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "csdp solver option  ";
                outStr << optionsVector[ i]->name;
                outStr << std::endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
                optStr << optionsVector[ i]->name << "=" << optionsVector[ i]->value << std::endl;
            }

            FILE *paramfile;
            paramfile=fopen("param.csdp","w");
            if (!paramfile)
                throw ErrorClass("File open error during option initialization");

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


#if 0
void  CsdpSolver::setInitialValues() throw (ErrorClass)
{
    std::ostringstream outStr;
    try
    {
        if(osinstance->getObjectiveNumber() <= 0) 
            throw ErrorClass("Ipopt NEEDS AN OBJECTIVE FUNCTION\n(For pure feasibility problems, use zero function.)");
        this->bSetSolverOptions = true;
        /* set the default options */
        //app->Options()->SetNumericValue("tol", 1e-9);
        app->Options()->SetIntegerValue("print_level", 0);
        app->Options()->SetIntegerValue("max_iter", 20000);
        app->Options()->SetNumericValue("bound_relax_factor", 0, true, true);
        app->Options()->SetStringValue("mu_strategy", "adaptive", true, true);
        //app->Options()->SetStringValue("output_file", "ipopt.out");
        app->Options()->SetStringValue("check_derivatives_for_naninf", "yes");
        // hessian constant for an LP
        if( (osinstance->getNumberOfNonlinearExpressions() <= 0) && 
            (osinstance->getNumberOfQuadraticTerms() <= 0) )
        {
            app->Options()->SetStringValue("hessian_constant", "yes", true, true);
        }
        if(osinstance->getObjectiveNumber() > 0)
        {
            if( osinstance->instanceData->objectives->obj[ 0]->maxOrMin.compare("min") != 0)
            {
                app->Options()->SetStringValue("nlp_scaling_method", "user-scaling");
            }
        }
        /* end of the default options, now get options from OSoL */


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
            std::vector<SolverOption*> optionsVector;
            optionsVector = osoption->getSolverOptions( "ipopt",true);
            char *pEnd;
            int i;
            int num_ipopt_options = optionsVector.size();
            for(i = 0; i < num_ipopt_options; i++)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "ipopt solver option  ";
                outStr << optionsVector[ i]->name;
                outStr << std::endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
                if(optionsVector[ i]->type == "numeric" )
                {
#ifndef NDEBUG
                    outStr.str("");
                    outStr.clear();
                    outStr << "FOUND A NUMERIC OPTION  ";
                    outStr << os_strtod( optionsVector[ i]->value.c_str(), &pEnd );
                    outStr << std::endl;
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
                    app->Options()->SetNumericValue(optionsVector[ i]->name, os_strtod( optionsVector[ i]->value.c_str(), &pEnd ) );
                }
                else if(optionsVector[ i]->type == "integer" )
                {
#ifndef NDEBUG
                    outStr.str("");
                    outStr.clear();
                    outStr << "FOUND AN INTEGER OPTION  ";
                    outStr << atoi( optionsVector[ i]->value.c_str() );
                    outStr << std::endl;
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
                    app->Options()->SetIntegerValue(optionsVector[ i]->name, atoi( optionsVector[ i]->value.c_str() ) );
                }
                else if(optionsVector[ i]->type == "string" )
                {
#ifndef NDEBUG
                    outStr.str("");
                    outStr.clear();
                    outStr << "FOUND A STRING OPTION  ";
                    outStr << optionsVector[ i]->value.c_str();
                    outStr << std::endl;
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
                    app->Options()->SetStringValue(optionsVector[ i]->name, optionsVector[ i]->value);
                }
            }
        }
        return;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_error, "Error while setting options in IpoptSolver\n");
        osresult->setGeneralMessage( eclass.errormsg);
        osresult->setGeneralStatusType( "error");
        osrl = osrlwriter->writeOSrL( osresult);
        throw ErrorClass( osrl) ;
    }
}//end setInitialValues()

#endif

 
void  CsdpSolver::solve() throw (ErrorClass)
{
    std::ostringstream outStr;

    if( this->bCallbuildSolverInstance == false) buildSolverInstance();
    if( this->bSetSolverOptions == false) setSolverOptions();
    try
    {

// what about initial values for X and Y? perhaps even y?
//if osoption->...->initialmatrix != NUll, set initial values. Make sure that defaults are there
//in case X or Z is empty
  
        /*
         * Create an initial solution.  This allocates space for X, y, and Z,
         * and sets initial values.
         */
//else
            initsoln(nC_rows,ncon,C_matrix,rhsValues,mconstraints,&X,&y,&Z);


        //call solver
        int ret = easy_sdp(nC_rows,ncon,C_matrix,rhsValues,mconstraints,0.0,&X,&y,&Z,&pobj,&dobj);
        if (ret == 0) // return codes are in csdp.c
            printf("The objective value is %.7e \n",(dobj+pobj)/2);
        else
            printf("SDP failed.\n");

        // build osresult
//        osrl = osrlwriter->writeOSrL( osresult);
//        if (status < -2)
//        {
//            throw ErrorClass("Ipopt FAILED TO SOLVE THE PROBLEM: " + *ipoptErrorMsg);
//        }
//        return;

    }
    catch(const ErrorClass& eclass)
    {
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


