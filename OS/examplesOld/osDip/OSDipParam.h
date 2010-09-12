//===========================================================================//
// This file is part of the Decomp Solver Framework.                         //
//                                                                           //
// Decomp is distributed under the Common Public License as part of the      //
// COIN-OR repository (http://www.coin-or.org).                              //
//                                                                           //
// Author: Matthew Galati, Lehigh University                                 //
//                                                                           //
// Copyright (C) 2002-2007, Lehigh University, Matthew Galati, and Ted Ralphs//
// All Rights Reserved.                                                      //
//===========================================================================//

#ifndef OSDIPPARAM_H
#define OSDIPPARAM_H

//===========================================================================//
#include "UtilParameters.h"

//===========================================================================//
/*!
 * \class OSDipParam
 * Storage for parameters for the 
 *  OSDip Problem ().
 * 
 * \todo think about this design, register parameters, isoptional
 *       combos that violate, throw exceptions
 *
 */

//===========================================================================//
class OSDipParam {
	
	
	
public:
   int    LogLevel;   
   string DataDir;
   string OSiLFile;
   string OSoLFile;
   string solverFactory;
   int    UseNames;  //col/row names for debugging
   int    UseSparse; //create all blocks sparsely
   int    FullModel; //create full model for CPM or direct
   double BestKnownLB;
   double BestKnownUB;
   double ColumnUB; //hack since missing extreme rays
   double ColumnLB; //hack since missing extreme rays
   //=1 if all master-only vars in one block
   //=0 if one block per master-only var
   //int    MasterOnlyOneBlock;

public:
   void getSettings(UtilParameters & utilParam){
      static const char * common ="OSDip";
      LogLevel     = utilParam.GetSetting("LogLevel",     3,     common);
      DataDir      = utilParam.GetSetting("DataDir",      "",    common);
      OSiLFile     = utilParam.GetSetting("OSiLFile",     "",    common);   
      OSoLFile     = utilParam.GetSetting("OSoLFile",     "",    common); 
      solverFactory     = utilParam.GetSetting("solverFactory",     "",    common); 
      UseNames     = utilParam.GetSetting("UseNames",       0, common);
      UseSparse    = utilParam.GetSetting("UseSparse",      0, common);
      FullModel    = utilParam.GetSetting("FullModel",      0, common);
      BestKnownLB  = utilParam.GetSetting("BestKnownLB",  -1.e100, common);
      BestKnownUB  = utilParam.GetSetting("BestKnownUB",   1.e100, common);
      ColumnUB     = utilParam.GetSetting("ColumnUB",      1.0,  common);
      ColumnLB     = utilParam.GetSetting("ColumnLB",     0.0,  common);

   }

   void dumpSettings(ostream * os = &cout){
      static const char * common = "OSDip";
      (*os) << "\n=====================================================\n"
            << "OSDipParam PARAMETER SETTINGS \n";
      (*os) << common << ": LogLevel          : " << LogLevel         << endl;
      (*os) << common << ": DataDir           : " << DataDir          << endl;
      (*os) << common << ": OSiLFile          : " << OSiLFile         << endl;
      (*os) << common << ": OSoLFile          : " << OSoLFile         << endl;
      (*os) << common << ": solverFactory     : " << solverFactory         << endl;
      (*os) << common << ": UseNames          : " << UseNames         << endl;
      (*os) << common << ": UseSparse         : " << UseSparse        << endl;
      (*os) << common << ": FullModel         : " << FullModel        << endl;
      (*os) << common << ": BestKnownLB       : " << BestKnownLB      << endl;
      (*os) << common << ": BestKnownUB       : " << BestKnownUB      << endl;
      (*os) << common << ": ColumnUB          : " << ColumnUB         << endl;
      (*os) << common << ": ColumnLB          : " << ColumnLB         << endl;

      (*os) << "\n=====================================================\n";
   }
   
public:
   OSDipParam():    
      LogLevel        (3 ),
      DataDir         (""),
      OSiLFile        (""),
      OSoLFile        (""),
      solverFactory        (""),
      UseNames        (0),
      UseSparse       (1),
      FullModel       (0),
      BestKnownLB     (-1.e100),
      BestKnownUB     ( 1.e100),
      ColumnUB        ( 1.0),
      ColumnLB        (0.0)
   
{};
   ~OSDipParam() {};

};

#endif
