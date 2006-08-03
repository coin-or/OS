/** @file OSSolverService.cpp
 * 
 * @author  Robert Fourer,  Jun Ma, Kipp Martin, 
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005, Robert Fourer, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */
 
 // this is test code, e.g. test the parser or a solver, etc. 
 // this is just for playing around, do not confuse it with the unitTest
 
 
#include "OSResult.h"
#include "OSiLReader.h"
#include "OSiLWriter.h"
#include "OSrLReader.h"
#include "OSrLWriter.h"
#include "OSInstance.h"
#include "OSnLNode.h"
#include "FileUtil.h"
#include "ErrorClass.h"
#include <time.h>
#include <sstream>
#include <ctype.h>
#include <vector>
#include <string>

using std::cout;
using std::endl;

int main(int argC, char* argV[])
{
	FileUtil *fileUtil = NULL;
	std::string osilFileName;
	std::string osrlFileName;
	std::string osil;
	std::string osrl;
		osilFileName =  "/Users/kmartin/Documents/files/code/cpp/Coin-OS/OS/data/testb64.osil";
		osilFileName =  "/Users/kmartin/Documents/files/code/OSRepository/linear/continuous/osa-60.osil";
		osilFileName =  "/Users/kmartin/Documents/files/code/cpp/Coin-OS/OS/data/osilrosenbrockmodsum.osil";
		osrlFileName =  "/Users/kmartin/Documents/files/code/cpp/Coin-OS/OS/data/coinsolution.dat";
	fileUtil = new FileUtil();
	osil = fileUtil->getFileAsString( &osilFileName[0]);
	osrl = fileUtil->getFileAsString( &osrlFileName[0]);
	try{
		// check parsing of osil
		OSiLReader *osilreader = NULL;
		OSInstance *osinstance = NULL;
		osilreader = new OSiLReader();
		//cout << osil << endl;
		clock_t start, finish;
		double duration;
		start = clock();
		cout << "start parsing" << endl;
		osinstance = osilreader->readOSiL( &osil);
		finish = clock();
		duration = (double) (finish - start) / CLOCKS_PER_SEC;
		cout << "Parsing took (seconds): "<< duration << endl;
		//
	
		OSiLWriter *osilwriter = NULL;
		osilwriter = new OSiLWriter();
		if(osinstance != NULL){ 
			osilwriter = new OSiLWriter();
			osil = osilwriter->writeOSiL( osinstance);
			cout << osil << endl;
		}
		std::string sToken;
		OSnLNode* nlnode1;
		OSnLNode* nlnode;
		cout << "START TEST "  << endl;
		std::vector<OSnLNode*> test;
		std::vector<OSnLNode*> test1;
		OSnLNode::setnlNodeIdxMap();
		test = osinstance->getNonlinearExpressionTree( -1)->getPostfixFromExpressionTree();
		for(int kl = 0; kl < test.size(); kl++){
			sToken = test[ kl]->getTokenNumberFromOSnLNode() ;
			cout << "Untranslated Token " << sToken << endl;
			nlnode = OSnLNode::getOSnLNodeFromToken( sToken );
			cout << "Translated Token  " << nlnode->getTokenNameFromOSnLNode()   << endl;
			test[ kl] = nlnode;
		}
		cout << endl << endl;
		nlnode = test[ test.size() - 1];
		nlnode1 = nlnode->createExpressionTreeFromPostfix( test);
		test = nlnode1->getPostfixFromExpressionTree();
		for(int kl = 0; kl < test.size(); kl++){
			 cout << test[ kl]->getTokenNameFromOSnLNode() << endl ;
		}
		cout << endl << endl << endl << endl;
		cout << "DONE WITH TEST" << endl << endl;
		cout << "TEST PREFIX" << endl;
		cout << nlnode1->getNonlinearExpressionInXML();
		cout << endl << endl << endl << endl;
		std::vector<OSnLNode*> prefixVector;
		prefixVector = osinstance->instanceData->nonlinearExpressions->nl[ 0]->osExpressionTree->m_treeRoot->getPrefixFromExpressionTree();
		cout << "DONE TEST PREFIX" << endl;
		for(int kj = 0; kj < prefixVector.size(); kj++){
			cout << prefixVector[kj]->snodeName << endl;
		}
		nlnode = prefixVector[0]->createExpressionTreeFromPrefix(prefixVector);
		cout << nlnode->getNonlinearExpressionInXML() << endl;
		
		
		
		std::vector<OSnLNode*> postfixVector;
		postfixVector = osinstance->instanceData->nonlinearExpressions->nl[ 1]->osExpressionTree->m_treeRoot->getPostfixFromExpressionTree();
		cout << "DONE TEST POSTFIX" << endl;
		for(int kj = 0; kj < postfixVector.size(); kj++){
			cout << postfixVector[kj]->snodeName << endl;
		}
		nlnode = postfixVector.back()->createExpressionTreeFromPostfix(postfixVector);
		cout << nlnode->getNonlinearExpressionInXML() << endl;
		cout << "NOW REALLY DONE TEST POSTFIX" << endl;
		delete osilwriter;
		osilwriter = NULL;
		delete osilreader;
		osilreader = NULL;
		return 0;
		// check parsing of osrl
		OSrLReader *osrlreader = NULL;
		OSResult *osresult = NULL;
		osrlreader = new OSrLReader();
		osresult = osrlreader->readOSrL( osrl);
		OSrLWriter *osrlwriter;
		if(osresult != NULL){
			osrlwriter = new OSrLWriter();
			osrl = osrlwriter->writeOSrL( osresult);
		}
		cout << osrl << endl;
		delete osrlreader;
		osrlreader = NULL;
		delete osrlwriter;
		osrlwriter = NULL;
	}	
		catch(const ErrorClass& eclass){
		cout << eclass.errormsg <<  endl;
		cout << "THERE WAS AN ERROR!!!!!" << endl;
	}	
	//
    
	return 0;
}

