/** @file TestOS.h
 * 
 * @author  Robert Fourer,  Jun Ma, Kipp Martin, 
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks 
 * Copyright (C) 2005, Robert Fourer, Jun Ma, Kipp Martin, Huanyuan Sheng
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */
 
#ifndef OSMATLAB_H
#define OSMATLAB_H
//
//OS headers
#include <OsiSolverInterface.hpp>   
#include "OSResult.h" 
#include "OSiLReader.h"       
#include "OSiLWriter.h" 
#include "OSrLReader.h"        
#include "OSrLWriter.h"      
#include "OSInstance.h"  
#include "FileUtil.h"  
#include "OSConfig.h" 
#include "CoinSolver.h"
#include "DefaultSolver.h"  
#include "OSDataStructures.h"
//#include "WSUtil.h" 
//#include "OSSolverAgent.h"   
//#include "OShL.h"     
#include "ErrorClass.h" 

#ifdef COIN_HAS_LINDO    
#include "LindoSolver.h"
#endif   
//end OS headers

#include <string>


class OSMatlab { 

public:

  OSMatlab();
  ~OSMatlab() ;
  SparseMatrix *sparseMat;
  double *bl;
  double *bu;
  double *obj;
  double *vl;
  double *vu;
  int numVar;
  int numCon;
  char *varType;
  bool objType;
  std::string display();
  void createOSInstance();
 	OSInstance *osinstance;
};

#endif
