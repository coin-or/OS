//===========================================================================//
// This file is part of the Decomp Solver Framework.                         //
//                                                                           //
// Decomp is distributed under the Common Public License as part of the      //
// COIN-OR repository (http://www.coin-or.org).                              //
//                                                                           //
// Author: Matthew Galati, Lehigh University                                 //
//                                                                           //
// Copyright (C) 2002-2009, Lehigh University, Matthew Galati, and Ted Ralphs//
// All Rights Reserved.                                                      //
//===========================================================================//

//===========================================================================//
#include "Bearcat_Status.h"
#include "Bearcat_DecompApp.h"
//===========================================================================//
#include "DecompVar.h"

using std::ostringstream;

void Bearcat_DecompApp::initializeApp(UtilParameters & utilParam) {

	UtilPrintFuncBegin(m_osLog, m_classTag, "initializeApp()",
			m_appParam.LogLevel, 2);

	//---
	//--- get application parameters
	//---
	m_appParam.getSettings(utilParam);
	if (m_appParam.LogLevel >= 1)
		m_appParam.dumpSettings(m_osLog);

	//---
	//--- read OSiL instance
	//
	std::string osilFile = "spl1.osil";
	m_osInterface.readOSiL(osilFile);

	//---
	//--- read OSoL instance
	//
	std::string osolFile = "dip-spl1.osol";
	m_osInterface.readOSoL(osolFile);

	//---
	//--- create models
	//---
	createModels();

	UtilPrintFuncEnd(m_osLog, m_classTag, "initializeApp()",
			m_appParam.LogLevel, 2);
}

//===========================================================================//
void Bearcat_DecompApp::findActiveColumns(const vector<int> & rowsPart,
		set<int> & activeColsSet) {

	const CoinPackedMatrix * M = m_osInterface.getCoinPackedMatrix();
	const int * ind = M->getIndices();
	const int * beg = M->getVectorStarts();
	const int * len = M->getVectorLengths();
	const int * indR = NULL;

	//---
	//--- which columns are present in this part's rows
	//---
	int k, r;
	vector<int>::const_iterator it;
	for (it = rowsPart.begin(); it != rowsPart.end(); it++) {
		r = *it;
		indR = ind + beg[r];
		for (k = 0; k < len[r]; k++) {
			activeColsSet.insert(indR[k]);
		}
	}
}

//===========================================================================//
void Bearcat_DecompApp::createModelPart(DecompConstraintSet * model,
		const int nRowsPart, const int * rowsPart) {

	const int nCols = m_osInterface.getVariableNumber();
	const double * rowLB = m_osInterface.getRowLower();
	const double * rowUB = m_osInterface.getRowUpper();
	const double * colLB = m_osInterface.getColLower();
	const double * colUB = m_osInterface.getColUpper();
	const char * integerVars = m_osInterface.getIntegerColumns();

	std::cout << "GAIL IS STARTING createModelPart" << std::endl;

	model->M = new CoinPackedMatrix(false, 0.0, 0.0);
	if (!model->M)
		throw UtilExceptionMemory("createModels", "Bearcat_DecompApp");
	model->reserve(nRowsPart, nCols);
	model->M->submatrixOf(*m_osInterface.getCoinPackedMatrix(), nRowsPart,
			rowsPart);

	//---
	//--- set the row upper and lower bounds
	//--- set the col upper and lower bounds
	//---
	int i, r;
	for (i = 0; i < nRowsPart; i++) {
		r = rowsPart[i];
		if (m_appParam.UseNames) {
			const char * rowName =
					m_osInterface.getConstraintNames()[r].c_str();
			if (rowName)
				model->rowNames.push_back(rowName);
		}
		model->rowLB.push_back(rowLB[r]);
		model->rowUB.push_back(rowUB[r]);
	}
	copy(colLB, colLB + nCols, back_inserter(model->colLB));
	copy(colUB, colUB + nCols, back_inserter(model->colUB));

	//---
	//--- big fat hack... we don't deal with dual rays yet,
	//---  so, we assume subproblems are bounded
	//---
	//--- NOTE: might also need to tighten LBs
	//---
	//--- Too small - ATM infeasible!
	//--- Too big   - round off issues with big coeffs in 
	//---             master-only vars
	//---
	//--- TODO: need extreme rays or bounded subproblems from user
	//---

	/*
	 if (m_appParam.ColumnUB < 1.0e15) {
	 for (i = 0; i < nCols; i++) {
	 if (colUB[i] > 1.0e15) {
	 model->colUB[i] = m_appParam.ColumnUB;
	 }
	 }
	 }
	 if (m_appParam.ColumnLB > -1.0e15) {
	 for (i = 0; i < nCols; i++) {
	 if (colLB[i] < -1.0e15) {
	 model->colLB[i] = m_appParam.ColumnLB;
	 }
	 }
	 }
	 */
	//---
	//--- set the indices of the integer variables of modelRelax
	//---  also set the column names, if they exist
	//---
	for (i = 0; i < nCols; i++) {
		if (m_appParam.UseNames) {
			//const char * colName =  m_osInterface.columnName(i);
			const char * colName =
					m_osInterface.getConstraintNames()[i].c_str();

			if (colName)
				model->colNames.push_back(colName);
		}
		if (integerVars && integerVars[i]) {
			model->integerVars.push_back(i);
		}
	}
}

//===========================================================================//
void Bearcat_DecompApp::createModelPartSparse(DecompConstraintSet * model,
		const int nRowsPart, const int * rowsPart) {

	const int nColsOrig = m_osInterface.getVariableNumber();
	const double * rowLB = m_osInterface.getRowLower();
	const double * rowUB = m_osInterface.getRowUpper();
	const double * colLB = m_osInterface.getColLower();
	const double * colUB = m_osInterface.getColUpper();
	const char * integerVars = m_osInterface.getIntegerColumns();

	//---
	//--- set model as sparse
	//---
	model->setSparse(nColsOrig);
	std::cout << "GAIL IS STARTING createModelSparse" << std::endl;
	int nCols, origIndex, newIndex;
	vector<int>::iterator vit;
	newIndex = 0;
	for (vit = model->activeColumns.begin(); vit != model->activeColumns.end(); vit++) {
		origIndex = *vit;

		//std::cout << "lower bound = " << colLB[origIndex] << std::endl;
		//std::cout << "upper bound = " << colUB[origIndex] << std::endl;

		model->pushCol(colLB[origIndex], colUB[origIndex],
				integerVars[origIndex] == 0 ? false : true, origIndex);

		//---
		//--- big fat hack... we don't deal with dual rays yet,
		//---  so, we assume subproblems are bounded
		//---

		if (m_appParam.ColumnUB < 1.0e15) {
			if (colUB[origIndex] > 1.0e15) {
				model->colUB[newIndex] = m_appParam.ColumnUB;
			}
		}
		if (m_appParam.ColumnLB > -1.0e15) {
			if (colLB[origIndex] < -1.0e15) {
				model->colLB[newIndex] = m_appParam.ColumnLB;
			}
		}

		if (m_appParam.UseNames) {
			//const char * colName =  m_osInterface.columnName(origIndex);
			const char * colName =
					m_osInterface.getConstraintNames()[origIndex].c_str();

			if (colName)
				model->colNames.push_back(colName);
		}
		newIndex++;
	}

	nCols = static_cast<int> (model->activeColumns.size());
	assert(static_cast<int> (model->colLB.size()) == nCols);
	assert(static_cast<int> (model->colUB.size()) == nCols);

	model->M = new CoinPackedMatrix(false, 0.0, 0.0);
	if (!model->M)
		throw UtilExceptionMemory("createModels", "Bearcat_DecompApp");
	model->M->setDimensions(0, nCols);
	model->reserve(nRowsPart, nCols);

	//---
	//--- for each row in rowsPart, create the row using sparse mapping
	//---
	int i, k, r, begInd;
	const map<int, int> & origToSparse = model->getMapOrigToSparse();
	const CoinPackedMatrix * M = m_osInterface.getCoinPackedMatrix();
	const int * matInd = M->getIndices();
	const CoinBigIndex * matBeg = M->getVectorStarts();
	const int * matLen = M->getVectorLengths();
	const double * matVal = M->getElements();
	const int * matIndI = NULL;
	const double * matValI = NULL;

	vector<CoinBigIndex> & rowBeg = model->m_rowBeg;//used as temp
	vector<int> & rowInd = model->m_rowInd;//used as temp
	vector<double> & rowVal = model->m_rowVal;//used as temp
	map<int, int>::const_iterator mit;

	begInd = 0;
	rowBeg.push_back(0);
	for (i = 0; i < nRowsPart; i++) {
		r = rowsPart[i];
		if (m_appParam.UseNames) {
			const char * rowName =
					m_osInterface.getConstraintNames()[r].c_str();
			if (rowName)
				model->rowNames.push_back(rowName);
		}
		model->rowLB.push_back(rowLB[r]);
		model->rowUB.push_back(rowUB[r]);

		matIndI = matInd + matBeg[r];
		matValI = matVal + matBeg[r];
		for (k = 0; k < matLen[r]; k++) {
			origIndex = matIndI[k];
			mit = origToSparse.find(origIndex);
			assert(mit != origToSparse.end());
			rowInd.push_back(mit->second);
			rowVal.push_back(matValI[k]);
		}
		begInd += matLen[r];
		rowBeg.push_back(begInd);
	}
	model->M->appendRows(nRowsPart, &rowBeg[0], &rowInd[0], &rowVal[0]);
	rowBeg.clear();
	rowInd.clear();
	rowVal.clear();
}

//===========================================================================//
void Bearcat_DecompApp::createModels() {

	UtilPrintFuncBegin(m_osLog, m_classTag, "createModels()",
			m_appParam.LogLevel, 2);
	int i;
	int j;
	const int nCols = m_osInterface.getVariableNumber();

	//First the define the objective function over the entire variable space
	//Create the memory for the objective  function
	m_objective = new double[nCols];
	for (i = 0; i < nCols; i++) {
		m_objective[i] = m_osInterface.getObjectiveFunctionCoeff()[i];
		std::cout << "obj coeff = " << m_objective[i] << std::endl;
	}
	setModelObjective( m_objective);

	//---
	//--- Construct the core matrix.
	//---
	int nRowsRelax, nRowsCore;

	nRowsRelax = 0;
	nRowsCore = 0;

	//UTIL_MSG(m_appParam.LogLevel, 2,
	//		(*m_osLog) << "Instance    = " << m_appParam.Instance << endl;
	//		(*m_osLog) << " nRows      = " << nRows << endl;
	//		(*m_osLog) << " nCols      = " << nCols << endl;
	//		(*m_osLog) << " nBlocks    = " << nBlocks << endl;
	//		(*m_osLog) << " nRowsCore  = " << nRowsCore << endl;
	//		(*m_osLog) << " nRowsRelax = " << nRowsRelax << " [ " << 100
	//				* nRowsRelax / nRows << " % ]" << endl;
	//		);

	//---
	//--- setup markers for core and relax rows
	//---   

	int *rowsCore = NULL;
	//get the core constraints


	std::vector<OtherConstraintOption*> otherConstraintOptions;
	std::vector<OtherConstraintOption*>::iterator vit;

	if (m_osInterface.m_osoption != NULL
			&& m_osInterface.m_osoption->getNumberOfOtherConstraintOptions()
					> 0) {
		std::cout << "Number of other constraint options = "
				<< m_osInterface.m_osoption->getNumberOfOtherConstraintOptions()
				<< std::endl;
		otherConstraintOptions
				= m_osInterface.m_osoption->getOtherConstraintOptions("Dip");
		//iterate over the vector


		for (vit = otherConstraintOptions.begin(); vit
				!= otherConstraintOptions.end(); vit++) {

			// see if we have a Core Constraint Set

			if (((*vit)->name.compare("constraintSet") == 0)
					&& ((*vit)->type.compare("Core") == 0)) {

				// get the index of core constraints
				// first get the number of core constraints


				nRowsCore = (*vit)->numberOfCon;
				rowsCore = new int[nRowsCore];

				//now get the indexes

				for (i = 0; i < nRowsCore; i++) {

					rowsCore[i] = (*vit)->con[i]->idx;

				}

			}
		}
	}

	DecompConstraintSet * modelCore = new DecompConstraintSet();
	createModelPart(modelCore, nRowsCore, rowsCore);

	setModelCore(modelCore, "core");
	//---
	//--- save a pointer so we can delete it later
	//---
	m_modelC = modelCore;

	//
	// Now construct the relaxation matrices
	//
	int *rowsRelax;
	int whichBlock;
	DecompConstraintSet *modelRelax = NULL;
	char *ch = NULL;
	ostringstream blockName;
	std::set<int> blockVars; //variables in the block
	std::set<int> blockVarsAll; //all variables that appear in a block
	std::set<int>::iterator sit;
	CoinPackedVector *row;
	int *rowVars;
	int rowSize;
	
	m_numBlocks = 0;
	//kipp -- throw an exception if we get an index out of range
	if (m_osInterface.m_osoption != NULL
			&& m_osInterface.m_osoption->getNumberOfOtherConstraintOptions()
					> 0) {
		std::cout << "Number of other constraint options = "
				<< m_osInterface.m_osoption->getNumberOfOtherConstraintOptions()
				<< std::endl;
		otherConstraintOptions
				= m_osInterface.m_osoption->getOtherConstraintOptions("Dip");
		//iterate over the vector


		for (vit = otherConstraintOptions.begin(); vit
				!= otherConstraintOptions.end(); vit++) {

			// see if we have a Core Constraint Set

			if (((*vit)->name.compare("constraintSet") == 0)
					&& ((*vit)->type.compare("Block") == 0)) {
				
				m_numBlocks++;

				blockName << "Relax";

				// get the index of core constraints
				// first get the number of core constraints
				nRowsRelax = (*vit)->numberOfCon;
				rowsRelax = new int[nRowsRelax];

				//now get the indexes
				blockVars.clear();
				for (i = 0; i < nRowsRelax; i++) {

					rowsRelax[i] = (*vit)->con[i]->idx;
					//add the variables for this row to the set blockVars
					row = m_osInterface.getRow(rowsRelax[i]);
					rowSize = row->getNumElements();
					rowVars = row->getIndices();

					for (j = 0; j < rowSize; j++) {
						if (blockVars.find(rowVars[j]) == blockVars.end()) {
							blockVars.insert(rowVars[j]);
							blockVarsAll.insert(rowVars[j]);
						}
					}

				}

				modelRelax = new DecompConstraintSet();
				CoinAssertHint(modelRelax, "Error: Out of Memory");

				//get the block number

				ch = new char[(*vit)->value.size() + 1];
				ch[(*vit)->value.size()] = 0;
				memcpy(ch, (*vit)->value.c_str(), (*vit)->value.size());
				whichBlock = atoi(ch);
				delete ch;
				blockName << whichBlock;
				//create the active columns in this block
				for (sit = blockVars.begin(); sit != blockVars.end(); sit++) {

					modelRelax->activeColumns.push_back(*sit);

				}
				
				

				//
				//

				if (m_appParam.LogLevel >= 3) {
					(*m_osLog) << "Active Columns : " << whichBlock << endl;
					UtilPrintVector(modelRelax->activeColumns, m_osLog);

					if (modelCore->getColNames().size() > 0)
						UtilPrintVector(modelRelax->activeColumns,
								modelCore->getColNames(), m_osLog);
				}
				createModelPartSparse(modelRelax, nRowsRelax, rowsRelax);
				m_modelR.insert(make_pair(whichBlock + 1, modelRelax));
				setModelRelax(modelRelax, blockName.str(), whichBlock);
				blockName.str("");
			}
		}
	}
	/*
	//kipp hard code do one by one
	//block 1
	DecompConstraintSet * modelRelax1 = new DecompConstraintSet();
	CoinAssertHint(modelRelax1, "Error: Out of Memory");

	//---
	//--- find and set active columns

	//block 1

	 int * rowsRelax1 = new int[5];
	 nRowsRelax = 5;

	 rowsRelax1[0] = 5;
	 rowsRelax1[1] = 6;
	 rowsRelax1[2] = 7;
	 rowsRelax1[3] = 8;
	 rowsRelax1[4] = 9;

	 
	 modelRelax1->activeColumns.push_back(0);
	 modelRelax1->activeColumns.push_back(1);
	 modelRelax1->activeColumns.push_back(2);
	 modelRelax1->activeColumns.push_back(3);
	 modelRelax1->activeColumns.push_back(4);
	 modelRelax1->activeColumns.push_back(15);
	 

	 if (m_appParam.LogLevel >= 3) {
	 (*m_osLog) << "Active Columns 1:" << endl;
	 UtilPrintVector(modelRelax1->activeColumns, m_osLog);

	 if (modelCore->getColNames().size() > 0)
	 UtilPrintVector(modelRelax1->activeColumns,
	 modelCore->getColNames(), m_osLog);
	 }
	 createModelPartSparse(modelRelax1, nRowsRelax, rowsRelax1);
	 m_modelR.insert(make_pair(1, modelRelax1));
	 setModelRelax(modelRelax1, "relax1", 0);

	 //block 2
	 DecompConstraintSet * modelRelax2 = new DecompConstraintSet();
	 CoinAssertHint(modelRelax2, "Error: Out of Memory");

	 int * rowsRelax2 = new int[5];
	 nRowsRelax = 5;
	 rowsRelax2[0] = 10;
	 rowsRelax2[1] = 11;
	 rowsRelax2[2] = 12;
	 rowsRelax2[3] = 12;
	 rowsRelax2[4] = 14;

	 modelRelax2->activeColumns.push_back(5);
	 modelRelax2->activeColumns.push_back(6);
	 modelRelax2->activeColumns.push_back(7);
	 modelRelax2->activeColumns.push_back(8);
	 modelRelax2->activeColumns.push_back(9);
	 modelRelax2->activeColumns.push_back(16);

	 if (m_appParam.LogLevel >= 3) {
	 (*m_osLog) << "Active Columns 2:" << endl;
	 UtilPrintVector(modelRelax2->activeColumns, m_osLog);
	 if (modelCore->getColNames().size() > 0)
	 UtilPrintVector(modelRelax2->activeColumns,
	 modelCore->getColNames(), m_osLog);
	 }
	 createModelPartSparse(modelRelax2, nRowsRelax, rowsRelax2);
	 m_modelR.insert(make_pair(2, modelRelax2));
	 setModelRelax(modelRelax2, "relax2", 1);

	 //block 3
	 DecompConstraintSet * modelRelax3 = new DecompConstraintSet();
	 CoinAssertHint(modelRelax3, "Error: Out of Memory");

	 int * rowsRelax3 = new int[5];
	 nRowsRelax = 5;
	 rowsRelax3[0] = 15;
	 rowsRelax3[1] = 16;
	 rowsRelax3[2] = 17;
	 rowsRelax3[3] = 18;
	 rowsRelax3[4] = 19;

	 modelRelax3->activeColumns.push_back(10);
	 modelRelax3->activeColumns.push_back(11);
	 modelRelax3->activeColumns.push_back(12);
	 modelRelax3->activeColumns.push_back(13);
	 modelRelax3->activeColumns.push_back(14);
	 modelRelax3->activeColumns.push_back(17);

	 (*m_osLog) << "Active Columns 3:" << endl;

	 UtilPrintVector(modelRelax3->activeColumns, m_osLog);
	 if (modelCore->getColNames().size() > 0)
	 UtilPrintVector(modelRelax3->activeColumns,
	 modelCore->getColNames(), m_osLog);

	 createModelPartSparse(modelRelax3, nRowsRelax, rowsRelax3);
	 m_modelR.insert(make_pair(3, modelRelax3));
	 setModelRelax(modelRelax3, "relax3", 2);
	 */

	UtilPrintFuncBegin(m_osLog, m_classTag, "printCurrentProblem()",
			m_appParam.LogLevel, 2);
	
	//get the master only variables
	
	
	 //modelCore->masterOnlyCols.push_back(i);
	
	for(i = 0; i < nCols; i++){
		
		
		if (blockVarsAll.find( i ) == blockVarsAll.end() ) {
			
			modelCore->masterOnlyCols.push_back(i);
			
			std::cout << "MASTER ONLY VARIABLE " << i << std::endl;
			
		}
		
		
	}
	
   //---
   //--- create an extra "empty" block for the master-only vars
   //---   since I don't know what OSI will do with empty problem
   //---   we will make column bounds explicity rows
   //---
   int nMasterOnlyCols = static_cast<int>(modelCore->masterOnlyCols.size());
   if(nMasterOnlyCols){
	  if(m_appParam.LogLevel >= 1)
		 (*m_osLog) << "Create model part Master-Only." << endl;

	 // createModelMasterOnlys2(modelCore->masterOnlyCols);

   }

}// end createModels()


//===========================================================================//
/*
 void Bearcat_DecompApp::createModelMasterOnlys2(vector<int> & masterOnlyCols) {


	 int nBlocks = m_numBlocks;
	 const int nCols =  m_osInterface.getVariableNumber();
	 const double * colLB =  m_osInterface.getColLower();
	 const double * colUB =  m_osInterface.getColUpper();
	 const char * integerVars =  m_osInterface.getIntegerColumns();
	 int nMasterOnlyCols = static_cast<int> (masterOnlyCols.size());
	
	 if (m_appParam.LogLevel >= 1) {
		 (*m_osLog) << "nCols = " << nCols << endl;
		 (*m_osLog) << "nMasterOnlyCols = " << nMasterOnlyCols << endl;
	 }
	
	 if (nMasterOnlyCols == 0)
	 return;
	
	 int i;
	 vector<int>::iterator vit;
	 for (vit = masterOnlyCols.begin(); vit != masterOnlyCols.end(); vit++) {
		 i = *vit;
		
		 //THINK:
		 //  what-if master-only var is integer and bound is not at integer
		
		 DecompConstraintSet * model = new DecompConstraintSet();
		 model->m_masterOnly = true;
		 model->m_masterOnlyIndex = i;
		 model->m_masterOnlyLB = colLB[i];
		 std::cout << "MASTER ONLY LB =  " << model->m_masterOnlyLB << std::endl;
		 model->m_masterOnlyUB = colUB[i];
		 std::cout << "MASTER ONLY UB =  " << model->m_masterOnlyUB << std::endl;
		 //0=cont, 1=integer
		 model->m_masterOnlyIsInt = integerVars[i] ? true : false;
		 if (m_appParam.ColumnUB < 1.0e15)
		 if (colUB[i] > 1.0e15)
		 model->m_masterOnlyUB = m_appParam.ColumnUB;
		 if (m_appParam.ColumnLB > -1.0e15)
		 if (colLB[i] < -1.0e15)
		 model->m_masterOnlyLB = m_appParam.ColumnLB;
		
		 //m_modelR.insert(make_pair(nBlocks, model));
		 setModelRelax(model, "master_only" + UtilIntToStr(i), nBlocks);
		 nBlocks++;
	 }

	 return;
 }//end createModelMasterOnlys2
*/


int Bearcat_DecompApp::generateInitVars(DecompVarList & initVars) {

	//---
	//--- generateInitVars is a virtual method and can be overriden
	//---   if the user has some idea how to initialize the list of 
	//---   initial variables (columns in the DW master)
	//---
	std::cout << "GENERATE INIT VARS" << std::endl;
	UtilPrintFuncBegin(m_osLog, m_classTag, "generateInitVars()",
			m_appParam.LogLevel, 2);

	//---
	//--- Get the initial solution from the OSOption object
	//--- we want the variable other option where name="initialCol"
	//---

	//std::vector<OtherVariableOption*> getOtherVariableOptions(std::string solver_name); 
	std::vector<OtherVariableOption*> otherVarOptions;
	std::vector<OtherVariableOption*>::iterator vit;
	int *index = NULL;
	double *value = NULL;
	int i;
	double objValue;
	char *pEnd;
	char *ch;
	int whichBlock;
	DecompVar *var;

	if (m_osInterface.m_osoption != NULL
			&& m_osInterface.m_osoption->getNumberOfOtherVariableOptions() > 0) {
		std::cout << "Number of other variable options = "
				<< m_osInterface.m_osoption->getNumberOfOtherVariableOptions()
				<< std::endl;
		otherVarOptions = m_osInterface.m_osoption->getOtherVariableOptions(
				"Dip");
		//iterate over the vector

		for (vit = otherVarOptions.begin(); vit != otherVarOptions.end(); vit++) {

			// see if we have an initialCol option

			if ((*vit)->name.compare("initialCol") == 0) {

				index = new int[(*vit)->numberOfVar];
				value = new double[(*vit)->numberOfVar];

				objValue = 0.0;

				for (i = 0; i < (*vit)->numberOfVar; i++) {

					index[i] = (*vit)->var[i]->idx;

					//convert the string to integer
					//std::string s
					ch = new char[(*vit)->var[i]->value.size() + 1];
					ch[(*vit)->var[i]->value.size()] = 0;
					memcpy(ch, (*vit)->var[i]->value.c_str(),
							(*vit)->var[i]->value.size());
					value[i] = os_strtod_wrap(ch, &pEnd);
					delete ch;
					//std::cout  << "value = " << value[ i] << std::endl;
					objValue += m_objective[index[i]];

				}

				ch = new char[(*vit)->value.size() + 1];
				ch[(*vit)->value.size()] = 0;
				memcpy(ch, (*vit)->value.c_str(), (*vit)->value.size());
				whichBlock = atoi(ch);
				delete ch;
				std::cout << "value = " << whichBlock << std::endl;
				std::cout << "object coefficient =  " << objValue << std::endl;
				// now add the column

				var
						= new DecompVar((*vit)->numberOfVar, index, value,
								objValue);
				var->setBlockId(whichBlock);
				initVars.push_back(var);

			}

		}

	}

	UtilPrintFuncEnd(m_osLog, m_classTag, "generateInitVars()",
			m_appParam.LogLevel, 2);
	return static_cast<int> (initVars.size());
}