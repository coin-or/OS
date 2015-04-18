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
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, "inside CsdpSolver constructor\n");
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

        mtxRef = new int[osinstance->getObjectiveNumber()+1];

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

        if (!tempMtx->isBlockDiagonal())
           throw ErrorClass("A0 matrix must be block-diagonal");

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

            if (!tempMtx->isBlockDiagonal())
                throw ErrorClass("Constraint matrix must be block-diagonal");

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

        blockOffset = new int[nRowBlocks];

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

        // Note: blockSize is 1-based, due to issues of Fortran compatibility
        blockSize = new int[nBlocks];
        for (int i=1; i < nBlocks; i++)
            blockSize[i] = blockOffset[i] - blockOffset[i-1]; 

#ifndef NOSHORTS
        /** If we're using unsigned shorts, make sure that the problem isn't too big. */
        if (osinstance->getConstraintNumber() >= USHRT_MAX) 
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
        if (osinstance->getConstraintNumber() > 23169)
            throw ErrorClass("This problem is too large to be solved in 32 bit mode!\n");
#endif

        /** Keep track of which blocks have off-diagonal entries. */
        isdiag = new bool[nBlocks+1];
        for (int i=1; i<=nBlocks; i++)
            isdiag[i] = true;

/*
        at this point we know the dimensions of all blocks. We need to extract
        the blocks from the data structure, perhaps by simply moving pointers,
        perhaps by combining several blocks into one, perhaps by going deeper
        into the data structure and the constructor list
        we should also keep track of diagonal blocks (no column has length more than 1
        and the single nonzero is on the diagonal)
 */

//Here we set up the CSDP data structures
// this is the signature of read_prob, which reads the SDPA problem from a file
//int read_prob(fname,pn,pk,pC,pa,pconstraints,printlevel)
//     char *fname;   // this is the name of the file
//     int *pn;       // pointer to n, the dimension of the matrices
//     int *pk;       // pointer to k, the number of constraints
     struct blockmatrix *pC; // the matrix in the objective (A0)
//     double **pa;   // for RHS values
     struct constraintmatrix **pconstraints;  // the matrices Ai
//     int printlevel;  // for printing error messages and such

//these declarations are used in example.c     
//{
  struct constraintmatrix *myconstraints;
//  FILE *fid;
//  int i,j;
//  int buflen;
//  char *buf;
//  int c;
//  int nblocks;
//  int blksz;
//  int blk;
//  char *ptr1;
//  char *ptr2;
//  int matno;
//  int blkno;
//  int indexi;
//  int indexj;
//  double ent;
//  int ret;
//  struct sparseblock *p;
//  struct sparseblock *q;
//  struct sparseblock *prev;
//  int *isdiag;
//  double *tempdiag;
//}

        /** Allocate space for the C matrix (A0). */
        pC->nblocks=nBlocks;
        pC->blocks=(struct blockrec *)malloc((nBlocks+1)*sizeof(struct blockrec));
        if (pC->blocks == NULL)
            throw ErrorClass("Storage allocation failed!\n");

        /** Allocate space for the constraints. */
        int pk = osinstance->instanceData->matrices->matrix[mtxRef[0]]->numberOfRows+1;
        myconstraints = new constraintmatrix[pk];
//            (struct constraintmatrix *)malloc((pk)*sizeof(struct constraintmatrix));

//        if (myconstraints == NULL)
//            throw ErrorClass("Storage allocation failed!\n");
  
        /** Null out all pointers in constraints. */
        for (int i=1; i<=pk; i++)
            myconstraints[i].blocks=NULL;

        double *pa = new double[pk+1];

//        if (*pa == NULL)
//            throw ErrorClass("Storage allocation failed!\n");


#if 0
  /*
   * And read the block structure.
   */

  *pn=0;

  ret=get_line(fid,buf,buflen);
  if (ret == 0)
    {
      /*
       * Decode nblocks numbers out of the buffer.  Put the results in 
       * block_structure.
       */
      ptr1=buf;
      for (blk=1; blk<=nblocks; blk++)
	{
	  blksz=strtol(ptr1,&ptr2,10);
	  ptr1=ptr2;

#ifndef NOSHORTS
  /*
   * If we're using unsigned shorts, make sure that the problem isn't
   * too big.
   */

	  if (abs(blksz) >= USHRT_MAX)
	    {
	      printf("This problem is too large to be solved by this version of the code!\n");
	      printf("Recompile with -DNOSHORTS to fix the problem.\n");
	      exit(10);
	    };
#endif

	  /*
	   * negative numbers are used to indicate diagonal blocks.  First,
	   * update n.
	   */

	  *pn=*pn+abs(blksz);

	  /*
	   * Now, handle diagonal blocks and matrix blocks separately.
	   */
	  if (blksz < 0)
	    {
	      /*
	       * It's a diag block.
	       */
	      pC->blocks[blk].blocksize=abs(blksz);
	      pC->blocks[blk].blockcategory=DIAG;
	      pC->blocks[blk].data.vec=(double *)malloc((1+abs(blksz))*sizeof(double));
	      if (pC->blocks[blk].data.vec == NULL)
		{
		  printf("Storage allocation failed!\n");
		  exit(10);
		};
	      for (i=1; i<=abs(blksz); i++)
		pC->blocks[blk].data.vec[i]=0.0;

	    }
	  else
	    {
	      /*
	       * It's a matrix block.
	       */
	      pC->blocks[blk].blocksize=abs(blksz);
	      pC->blocks[blk].blockcategory=MATRIX;
	      pC->blocks[blk].data.mat=(double *)malloc((blksz*blksz)*sizeof(double));
	      if (pC->blocks[blk].data.mat == NULL)
		{
		  printf("Storage allocation failed!\n");
		  exit(10);
		};

	      for (j=1; j<=blksz; j++)
		for (i=1; i<=blksz; i++)
		  pC->blocks[blk].data.mat[ijtok(i,j,blksz)]=0.0;

	    };
		
	};

    }
  else
    {
      printf("Incorect SDPA file. Couldn't read block sizes.\n");
      fclose(fid);
      free(isdiag);
      return(1);
    };

  /*
   *  Read in the right hand side values.
   */

  ret=get_line(fid,buf,buflen);
  if (ret == 0)
    {
      /*
       * Decode k numbers out of the buffer.  Put the results in 
       * a.
       */
      ptr1=buf;
      for (i=1; i<=pk; i++)
	{
	  (pa)[i]=strtod(ptr1,&ptr2);
	  ptr1=ptr2;
	};
    }
  else
    {
      printf("Incorect SDPA file. Can't read values.\n");
      fclose(fid);
      free(isdiag);
      return(1);
    };

  /*
   *  Now, loop through the entries, 
   *  counting entries in the constraint matrices block by block.
   */

  ret=fscanf(fid,"%d %d %d %d %le ",&matno,&blkno,&indexi,&indexj,&ent);

  if (ret != 5)
    {
      printf("Incorect SDPA file. Return code from fscanf is %d, should be 5\n",ret);
      fclose(fid);
      free(isdiag);
      return(1);
    };

  do {

    /*
     * Check the validity of these values.
     */

    if ((matno < 0) || (matno > pk) ||
	(blkno<1) || (blkno>nblocks) ||
	(indexi < 1) || (indexi > pC->blocks[blkno].blocksize) ||
	(indexj < 1) || (indexj > pC->blocks[blkno].blocksize))
      {
	printf("Incorect SDPA file. Bad values in line: %d %d %d %d %e \n",
	       matno,blkno,indexi,indexj,ent);
	fclose(fid);
	free(isdiag);
	return(1);
      };

    if (matno != 0)
      {
	if (ent != 0.0)
	  countentry(myconstraints,matno,blkno,pC->blocks[blkno].blocksize);
      }
    else
      {
	/*
	 * An entry in C. ignore it for now.
	 */
      };
    ret=fscanf(fid,"%d %d %d %d %le",&matno,&blkno,&indexi,&indexj,&ent);
  } while (ret == 5);

  if ((ret != EOF) && (ret != 0))
    {
      printf("Incorrect SDPA file, while reading entries.  ret=%d \n",ret);
      fclose(fid);
      free(isdiag);
      return(1);
    };

  fclose(fid);

  /*
   * Now, go through each of the blks in each of the constraint matrices,
   * and allocate space for the entries and indices.
   */
  for (i=1; i<=pk; i++)
    {
      p=myconstraints[i].blocks;

      while (p != NULL)
	{
	  /*
	   * allocate storage for the entries in this block of this constraint.
	   */
	  p->entries=(double *)malloc((p->numentries+1)*sizeof(double));
          if (p->entries == NULL)
	    {
	      printf("Storage allocation failed!\n");
	      exit(10);
	    };

#ifdef NOSHORTS
	  p->iindices=(int *)malloc((p->numentries+1)*sizeof(int));
#else
	  p->iindices=(unsigned short *)malloc((p->numentries+1)*sizeof(unsigned short));
#endif
          if (p->iindices == NULL)
	    {
	      printf("Storage allocation failed!\n");
	      exit(10);
	    };

#ifdef NOSHORTS
	  p->jindices=(int *)malloc((p->numentries+1)*sizeof(int));
#else
	  p->jindices=(unsigned short *)malloc((p->numentries+1)*sizeof(unsigned short));
#endif
          if (p->jindices == NULL)
	    {
	      printf("Storage allocation failed!\n");
	      exit(10);
	    };

	  p->numentries=0;
	  p=p->next;
	};
    };


  /*
   *  In the final pass through the file, fill in the actual data.
   */

  zero_mat(*pC);
  
  /*
   * Open the file for reading, and then read in all of the actual 
   * matrix entries.
   * line.
   */
  fid=fopen(fname,"r");
 
  if (fid == (FILE *) NULL)
    {
      printf("Couldn't open problem file for reading! \n");
      exit(11);
    };

  /*
   * First, read through the comment lines.
   */
 
  c=getc(fid);
  while ((c == '"') || (c == '*'))
    {
      skip_to_end_of_line(fid);
      c=getc(fid);
    };

  ungetc(c,fid);

  /*
   * Get the number of constraints (primal variables in SDPA terminology)
   */

  ret=get_line(fid,buf,buflen);
  if (ret == 0)
    {
      sscanf(buf,"%d",pk);
    }
  else
    {
      printf("Incorect SDPA file. Couldn't read mDIM \n");
      fclose(fid);
      free(isdiag);
      return(1);
    };

  /*
   * Read in the number of blocks.
   */
  ret=get_line(fid,buf,buflen);
  if (ret == 0)
    {
      sscanf(buf,"%d",&nblocks);
    }
  else
    {
      printf("Incorect SDPA file. Couldn't read nBLOCKS. \n");
      fclose(fid);
      free(isdiag);
      return(1);
    };

  /*
   * And read the block structure.
   */

  ret=get_line(fid,buf,buflen);
  if (ret != 0)
    {
      printf("Incorect SDPA file. Couldn't read block sizes.\n");
      fclose(fid);
      free(isdiag);
      return(1);
    };

  /*
   *  Read in the right hand side values.
   */

  ret=get_line(fid,buf,buflen);
  if (ret == 0)
    {
      /*
       * Decode k numbers out of the buffer.  Put the results in 
       * a.
       */
      ptr1=buf;
      for (i=1; i<=pk; i++)
	{
	  (pa)[i]=strtod(ptr1,&ptr2);
	  ptr1=ptr2;
	};
    }
  else
    {
      printf("Incorect SDPA file. Can't read a values.\n");
      fclose(fid);
      free(isdiag);
      return(1);
    };

  /*
   * Now, read the actual entries.
   */
  ret=fscanf(fid,"%d %d %d %d %le ",&matno,&blkno,&indexi,&indexj,&ent);
  do {

    /*
     * No need for sanity checking the second time around.
     */

    /*
     * Mark this block as not diagonal if indexi!=indexj.
     */
    if ((indexi != indexj)  && (ent != 0.0))
      isdiag[blkno]=0;

    if (matno != 0)
      {
	if (ent != 0.0)
	  addentry(myconstraints,matno,blkno,indexi,indexj,ent);
      }
    else
      {
	/*
	 * An entry in C. 
	 */
	if (ent != 0.0)
	  {
	    blksz=pC->blocks[blkno].blocksize;
	    if (pC->blocks[blkno].blockcategory == DIAG)
	      {
		pC->blocks[blkno].data.vec[indexi]=ent;
	      }
	    else
	      {
		pC->blocks[blkno].data.mat[ijtok(indexi,indexj,blksz)]=ent;
		pC->blocks[blkno].data.mat[ijtok(indexj,indexi,blksz)]=ent;
	      };
	  };
      };
    ret=fscanf(fid,"%d %d %d %d %le ",&matno,&blkno,&indexi,&indexj,&ent);
  } while (ret == 5);

  if ((ret != EOF) && (ret != 0))
    {
      printf("Incorrect SDPA file. \n");
      fclose(fid);
      free(isdiag);
      return(1);
    };

  /*
   * At this point, we'll stop to recognize whether any of the blocks
   * are "hidden LP blocks"  and correct the block type if needed.
   */

  for (i=1; i<=nblocks; i++)
    {
      if ((pC->blocks[i].blockcategory != DIAG) && 
	  (isdiag[i]==1) && (pC->blocks[i].blocksize > 1))
	{
	  /*
	   * We have a hidden diagonal block!
	   */
	  if (printlevel >= 2)
	    {
	      printf("Block %d is actually diagonal.\n",i);
	    };
	  blksz=pC->blocks[i].blocksize;
	  tempdiag=(double *)malloc((blksz+1)*sizeof(double));
	  for (j=1; j<=blksz; j++)
	    tempdiag[j]=pC->blocks[i].data.mat[ijtok(j,j,blksz)];
	  free(pC->blocks[i].data.mat);
	  pC->blocks[i].data.vec=tempdiag;
	  pC->blocks[i].blockcategory=DIAG;
	};
    };

  /*
   * If the printlevel is high, print out info on constraints and block
   * matrix structure.
   */
  if (printlevel >= 3)
    {
      printf("Block matrix structure.\n");
      for (blk=1; blk<=pC->nblocks; blk++)
	{
	  if (pC->blocks[blk].blockcategory == DIAG)
	    printf("Block %d, DIAG, %d \n",blk,pC->blocks[blk].blocksize);
	  if (pC->blocks[blk].blockcategory == MATRIX)
	    printf("Block %d, MATRIX, %d \n",blk,pC->blocks[blk].blocksize);
	};
    };

  /*
   * Next, setup issparse and NULL out all nextbyblock pointers.
   */

  for (i=1; i<=pk; i++)
    {
      p=myconstraints[i].blocks;
      while (p != NULL)
	{
	  /*
	   * First, set issparse.
	   */
	  if (((p->numentries) > 0.25*(p->blocksize)) && ((p->numentries) > 15))
	    {
	      p->issparse=0;
	    }
	  else
	    {
	      p->issparse=1;
	    };
	  
	  if (pC->blocks[p->blocknum].blockcategory == DIAG)
	    p->issparse=1;
	  
	  /*
	   * Setup the cross links.
	   */
	  
	  p->nextbyblock=NULL;
	  p=p->next;
	};
    };
  
  /*
   * Now, cross link.
   */
  
  prev=NULL;
  for (i=1; i<=pk; i++)
    {
      p=myconstraints[i].blocks;
      while (p != NULL)
	{
	  if (p->nextbyblock == NULL)
	    {
	      blk=p->blocknum;
	      
	      /*
	       * link in the remaining blocks.
	       */
	      for (j=i+1; j<=pk; j++)
		{
		  q=myconstraints[j].blocks;
		  
		  while (q != NULL)
		    {
		      if (q->blocknum == p->blocknum)
			{
			  if (p->nextbyblock == NULL)
			    {
			      p->nextbyblock=q;
			      q->nextbyblock=NULL;
			      prev=q;
			    }
			  else
			    {
			      prev->nextbyblock=q;
			      q->nextbyblock=NULL;
			      prev=q;
			    };
			  break;
			};
		      q=q->next;
		    };
		};
	    };
	  p=p->next;
	};
    };

  /*
   * Free unneeded memory.
   */

  free(buf);
  free(isdiag);

  /*
   *  Put back all the returned values.
   */

  *pconstraints=myconstraints;
  
  fclose(fid);
  return(0);
}

        /*
         * The problem and solution data.
         */
//===========================================================================
        struct blockmatrix C;
        double *b;
        struct constraintmatrix *constraints;

        /*
         * Storage for the initial and final solutions.
         */

        struct blockmatrix X,Z;
        double *y;
        double pobj,dobj;

        /*
         * blockptr will be used to point to blocks in constraint matrices.
         */

        struct sparseblock *blockptr;

        /*
         * A return code for the call to easy_sdp().
         */

        int ret;

        /*
         * The first major task is to setup the C matrix and right hand side b.
         */

        /*
         * First, allocate storage for the C matrix.  We have three blocks, but
         * because C starts arrays with index 0, we have to allocate space for
         * four blocks- we'll waste the 0th block.  Notice that we check to 
         * make sure that the malloc succeeded.
         */

        C.nblocks=3;
  C.blocks=(struct blockrec *)malloc(4*sizeof(struct blockrec));
  if (C.blocks == NULL)
    {
      printf("Couldn't allocate storage for C!\n");
      exit(1);
    };

  /*
   * Set up the first block.
   */
  
  C.blocks[1].blockcategory=MATRIX;
  C.blocks[1].blocksize=2;
  C.blocks[1].data.mat=(double *)malloc(2*2*sizeof(double));
  if (C.blocks[1].data.mat == NULL)
    {
      printf("Couldn't allocate storage for C!\n");
      exit(1);
    };

  /*
   * Put the entries into the first block.
   */

  C.blocks[1].data.mat[ijtok(1,1,2)]=2.0;
  C.blocks[1].data.mat[ijtok(1,2,2)]=1.0;
  C.blocks[1].data.mat[ijtok(2,1,2)]=1.0;
  C.blocks[1].data.mat[ijtok(2,2,2)]=2.0;

  /*
   * Set up the second block.
   */
  
  C.blocks[2].blockcategory=MATRIX;
  C.blocks[2].blocksize=3;
  C.blocks[2].data.mat=(double *)malloc(3*3*sizeof(double));
  if (C.blocks[2].data.mat == NULL)
    {
      printf("Couldn't allocate storage for C!\n");
      exit(1);
    };

  /*
   * Put the entries into the second block.
   */

  C.blocks[2].data.mat[ijtok(1,1,3)]=3.0;
  C.blocks[2].data.mat[ijtok(1,2,3)]=0.0;
  C.blocks[2].data.mat[ijtok(1,3,3)]=1.0;
  C.blocks[2].data.mat[ijtok(2,1,3)]=0.0;
  C.blocks[2].data.mat[ijtok(2,2,3)]=2.0;
  C.blocks[2].data.mat[ijtok(2,3,3)]=0.0;
  C.blocks[2].data.mat[ijtok(3,1,3)]=1.0;
  C.blocks[2].data.mat[ijtok(3,2,3)]=0.0;
  C.blocks[2].data.mat[ijtok(3,3,3)]=3.0;

  /*
   * Set up the third block.  Note that we have to allocate space for 3
   * entries because C starts array indexing with 0 rather than 1.
   */
  
  C.blocks[3].blockcategory=DIAG;
  C.blocks[3].blocksize=2;
  C.blocks[3].data.vec=(double *)malloc((2+1)*sizeof(double));
  if (C.blocks[3].data.vec == NULL)
    {
      printf("Couldn't allocate storage for C!\n");
      exit(1);
    };

  /*
   * Put the entries into the third block.
   */

  C.blocks[3].data.vec[1]=0.0;
  C.blocks[3].data.vec[2]=0.0;


  /*
   * Allocate storage for the right hand side, b.
   */

  b=(double *)malloc((2+1)*sizeof(double));
  if (b==NULL)
    {
      printf("Failed to allocate storage for a!\n");
      exit(1);
    };

  /*
   * Fill in the entries in b.
   */

  b[1]=1.0;
  b[2]=2.0;

  /*
   * The next major step is to set up the two constraint matrices A1 and A2.
   * Again, because C indexing starts with 0, we have to allocate space for
   * one more constraint.  constraints[0] is not used.
   */

  constraints=(struct constraintmatrix *)malloc((2+1)*sizeof(struct constraintmatrix));
  if (constraints==NULL)
    {
      printf("Failed to allocate storage for constraints!\n");
      exit(1);
    };

  /*
   * Setup the A1 matrix.  Note that we start with block 3 of A1 and then
   * do block 1 of A1.  We do this in this order because the blocks will
   * be inserted into the linked list of A1 blocks in reverse order.  
   */

  /*
   * Terminate the linked list with a NULL pointer.
   */

  constraints[1].blocks=NULL;

  /*
   * Now, we handle block 3 of A1.
   */

  /*
   * Allocate space for block 3 of A1.
   */

  blockptr=(struct sparseblock *)malloc(sizeof(struct sparseblock));
  if (blockptr==NULL)
    {
      printf("Allocation of constraint block failed!\n");
      exit(1);
    };

  /*
   * Initialize block 3.
   */

  blockptr->blocknum=3;
  blockptr->blocksize=2;
  blockptr->constraintnum=1;
  blockptr->next=NULL;
  blockptr->nextbyblock=NULL;
  blockptr->entries=(double *) malloc((1+1)*sizeof(double));
  if (blockptr->entries==NULL)
    {
      printf("Allocation of constraint block failed!\n");
      exit(1);
    };
  blockptr->iindices=(int *) malloc((1+1)*sizeof(int));
  if (blockptr->iindices==NULL)
    {
      printf("Allocation of constraint block failed!\n");
      exit(1);
    };
  blockptr->jindices=(int *) malloc((1+1)*sizeof(int));
  if (blockptr->jindices==NULL)
    {
      printf("Allocation of constraint block failed!\n");
      exit(1);
    };

  /*
   * We have 1 nonzero entry in the upper triangle of block 3 of A1.
   */

  blockptr->numentries=1;

  /*
   * The entry in the 1,1 position of block 3 of A1 is 1.0
   */

  blockptr->iindices[1]=1;
  blockptr->jindices[1]=1;
  blockptr->entries[1]=1.0;

  /*
   * Note that the entry in the 2,2 position of block 3 of A1 is 0, 
   * So we don't store anything for it.
   */

  /*
   * Insert block 3 into the linked list of A1 blocks.  
   */

  blockptr->next=constraints[1].blocks;
  constraints[1].blocks=blockptr;

  /*
   * Now, we handle block 1.  
   */

  /*
   * Allocate space for block 1.
   */

  blockptr=(struct sparseblock *)malloc(sizeof(struct sparseblock));
  if (blockptr==NULL)
    {
      printf("Allocation of constraint block failed!\n");
      exit(1);
    };

  /*
   * Initialize block 1.
   */

  blockptr->blocknum=1;
  blockptr->blocksize=2;
  blockptr->constraintnum=1;
  blockptr->next=NULL;
  blockptr->nextbyblock=NULL;
  blockptr->entries=(double *) malloc((3+1)*sizeof(double));
  if (blockptr->entries==NULL)
    {
      printf("Allocation of constraint block failed!\n");
      exit(1);
    };
  blockptr->iindices=(int *) malloc((3+1)*sizeof(int));
  if (blockptr->iindices==NULL)
    {
      printf("Allocation of constraint block failed!\n");
      exit(1);
    };
  blockptr->jindices=(int *) malloc((3+1)*sizeof(int));
  if (blockptr->jindices==NULL)
    {
      printf("Allocation of constraint block failed!\n");
      exit(1);
    };

  /*
   * We have 3 nonzero entries in the upper triangle of block 1 of A1.
   */

  blockptr->numentries=3;

  /*
   * The entry in the 1,1 position of block 1 of A1 is 3.0
   */

  blockptr->iindices[1]=1;
  blockptr->jindices[1]=1;
  blockptr->entries[1]=3.0;

  /*
   * The entry in the 1,2 position of block 1 of A1 is 1.0
   */

  blockptr->iindices[2]=1;
  blockptr->jindices[2]=2;
  blockptr->entries[2]=1.0;

  /*
   * The entry in the 2,2 position of block 1 of A1 is 3.0
   */

  blockptr->iindices[3]=2;
  blockptr->jindices[3]=2;
  blockptr->entries[3]=3.0;

  /*
   * Note that we don't have to store the 2,1 entry- this is assumed to be
   * equal to the 1,2 entry.
   */

  /*
   * Insert block 1 into the linked list of A1 blocks.  
   */

  blockptr->next=constraints[1].blocks;
  constraints[1].blocks=blockptr;

  /*
   * Note that the second block of A1 is 0, so we didn't store anything for it.
   */

  /*
   * Setup the A2 matrix.  This time, there are nonzero entries in block 3
   * and block 2.  We start with block 3 of A2 and then do block 1 of A2. 
   */

  /*
   * Terminate the linked list with a NULL pointer.
   */

  constraints[2].blocks=NULL;

  /*
   * First, we handle block 3 of A2.
   */

  /*
   * Allocate space for block 3 of A2.
   */

  blockptr=(struct sparseblock *)malloc(sizeof(struct sparseblock));
  if (blockptr==NULL)
    {
      printf("Allocation of constraint block failed!\n");
      exit(1);
    };

  /*
   * Initialize block 3.
   */

  blockptr->blocknum=3;
  blockptr->blocksize=2;
  blockptr->constraintnum=2;
  blockptr->next=NULL;
  blockptr->nextbyblock=NULL;
  blockptr->entries=(double *) malloc((1+1)*sizeof(double));
  if (blockptr->entries==NULL)
    {
      printf("Allocation of constraint block failed!\n");
      exit(1);
    };
  blockptr->iindices=(int *) malloc((1+1)*sizeof(int));
  if (blockptr->iindices==NULL)
    {
      printf("Allocation of constraint block failed!\n");
      exit(1);
    };
  blockptr->jindices=(int *) malloc((1+1)*sizeof(int));
  if (blockptr->jindices==NULL)
    {
      printf("Allocation of constraint block failed!\n");
      exit(1);
    };

  /*
   * We have 1 nonzero entry in the upper triangle of block 3 of A2.
   */

  blockptr->numentries=1;


  /*
   * The entry in the 2,2 position of block 3 of A2 is 1.0
   */

  blockptr->iindices[1]=2;
  blockptr->jindices[1]=2;
  blockptr->entries[1]=1.0;

  /*
   * Insert block 3 into the linked list of A2 blocks.  
   */

  blockptr->next=constraints[2].blocks;
  constraints[2].blocks=blockptr;

  /*
   * Now, we handle block 2.  
   */

  /*
   * Allocate space for block 2.
   */

  blockptr=(struct sparseblock *)malloc(sizeof(struct sparseblock));
  if (blockptr==NULL)
    {
      printf("Allocation of constraint block failed!\n");
      exit(1);
    };

  /*
   * Initialize block 2.
   */

  blockptr->blocknum=2;
  blockptr->blocksize=3;
  blockptr->constraintnum=2;
  blockptr->next=NULL;
  blockptr->nextbyblock=NULL;
  blockptr->entries=(double *) malloc((4+1)*sizeof(double));
  if (blockptr->entries==NULL)
    {
      printf("Allocation of constraint block failed!\n");
      exit(1);
    };
  blockptr->iindices=(int *) malloc((4+1)*sizeof(int));
  if (blockptr->iindices==NULL)
    {
      printf("Allocation of constraint block failed!\n");
      exit(1);
    };
  blockptr->jindices=(int *) malloc((4+1)*sizeof(int));
  if (blockptr->jindices==NULL)
    {
      printf("Allocation of constraint block failed!\n");
      exit(1);
    };

  /*
   * We have 4 nonzero entries in the upper triangle of block 2 of A2.
   */

  blockptr->numentries=4;


  /*
   * The entry in the 1,1 position of block 2 of A2 is 3.0
   */

  blockptr->iindices[1]=1;
  blockptr->jindices[1]=1;
  blockptr->entries[1]=3.0;

  /*
   * The entry in the 2,2 position of block 2 of A2 is 4.0
   */

  blockptr->iindices[2]=2;
  blockptr->jindices[2]=2;
  blockptr->entries[2]=4.0;

  /*
   * The entry in the 3,3 position of block 2 of A2 is 5.0
   */

  blockptr->iindices[3]=3;
  blockptr->jindices[3]=3;
  blockptr->entries[3]=5.0;

  /*
   * The entry in the 1,3 position of block 2 of A2 is 1.0
   */

  blockptr->iindices[4]=1;
  blockptr->jindices[4]=3;
  blockptr->entries[4]=1.0;

  /*
   * Note that we don't store the 0 entries and entries below the diagonal!
   */

  /*
   * Insert block 2 into the linked list of A2 blocks.  
   */

  blockptr->next=constraints[2].blocks;
  constraints[2].blocks=blockptr;

  /*
   * At this point, we have all of the problem data setup.
   */


#ifndef NDEBUG
        //dataEchoCheck();
#endif

  /*
   * Write the problem out in SDPA sparse format.
   */

  write_prob("prob.dat-s",7,2,C,b,constraints);

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
    }

    catch(const ErrorClass& eclass)
    {
        if (blockOffset != NULL) delete [] blockOffset;
        if (blockSize   != NULL) delete [] blockSize;
        if (mtxRef      != NULL) delete [] mtxRef;
        if (isdiag      != NULL) delete [] isdiag;

        osresult = new OSResult();
        osresult->setGeneralMessage( eclass.errormsg);
        osresult->setGeneralStatusType( "error");
        osrl = osrlwriter->writeOSrL( osresult);
        throw ErrorClass( osrl);
    }

}// end buildSolverInstance()
 
void  CsdpSolver::solve() throw (ErrorClass)
{
}

void  CsdpSolver::setSolverOptions() throw(ErrorClass)
{
/*
 * This is very rudimentary due to the limited API provided by CSDP
 * A full enumeration of available options is required
 */

    struct paramstruc params;

    std::ostringstream outStr;
    int printlevel = 0;

    try
    {
        initparams(&params,&printlevel);

        /* now get options from OSoL */
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
                if (optionsVector[ i]->name == "axtol" )
                    params.axtol = os_strtod( optionsVector[ i]->value.c_str(), &pEnd );
                else if (optionsVector[ i]->name == "atytol" )
                    params.atytol = os_strtod( optionsVector[ i]->value.c_str(), &pEnd );
                else if (optionsVector[ i]->name == "objtol" )
                    params.objtol = os_strtod( optionsVector[ i]->value.c_str(), &pEnd );
                else if (optionsVector[ i]->name == "pinftol" )
                    params.pinftol = os_strtod( optionsVector[ i]->value.c_str(), &pEnd );
                else if (optionsVector[ i]->name == "dinftol" )
                    params.dinftol = os_strtod( optionsVector[ i]->value.c_str(), &pEnd );
                else if (optionsVector[ i]->name == "minstepfrac" )
                    params.minstepfrac = os_strtod( optionsVector[ i]->value.c_str(), &pEnd );
                else if (optionsVector[ i]->name == "maxstepfrac" )
                    params.maxstepfrac = os_strtod( optionsVector[ i]->value.c_str(), &pEnd );
                else if (optionsVector[ i]->name == "minstepp" )
                    params.minstepp = os_strtod( optionsVector[ i]->value.c_str(), &pEnd );
                else if (optionsVector[ i]->name == "minstepd" )
                    params.minstepd = os_strtod( optionsVector[ i]->value.c_str(), &pEnd );
                else if (optionsVector[ i]->name == "perturbobj" )
                    params.perturbobj = os_strtod( optionsVector[ i]->value.c_str(), &pEnd );
                else if (optionsVector[ i]->name == "maxiter" )
                    params.maxiter = atoi( optionsVector[ i]->value.c_str() );
                else if (optionsVector[ i]->name == "usexzgap" )
                    params.usexzgap = atoi( optionsVector[ i]->value.c_str() );
                else if (optionsVector[ i]->name == "tweakgap" )
                    params.tweakgap = atoi( optionsVector[ i]->value.c_str() );
                else if (optionsVector[ i]->name == "affine" )
                    params.affine = atoi( optionsVector[ i]->value.c_str() );
                else if (optionsVector[ i]->name == "fastmode" )
                    params.fastmode = atoi( optionsVector[ i]->value.c_str() );
                else 
                    throw ErrorClass("Unrecognized option for solver csdp");
            }
        }
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, "THERE IS AN ERROR\n");
        osresult->setGeneralMessage( eclass.errormsg);
        osresult->setGeneralStatusType( "error");
        osrl = osrlwriter->writeOSrL( osresult);
        throw ErrorClass( osrl);
    }
}//setSolverOptions


void CsdpSolver::dataEchoCheck()
{
}


