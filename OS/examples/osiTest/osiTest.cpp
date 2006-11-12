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
 
 

#include <time.h>
#include <iostream>
#include <ctype.h>
#include <vector>
#include <string>

using std::cout;
using std::endl;

class ModOSInstance {
	public:
	virtual void accumulate() = 0;
	virtual void modify() = 0;
}; //class ModOSInstance

std::vector<int> conNums;
class DeleteConstraints : public ModOSInstance{
	public:
	int conNumber;

	//
	public:
	void accumulate( ){
		conNums.push_back( conNumber);
		cout << "Accumulating Constraint with Index =  " << conNumber << endl;
	}
	void modify(){
		// for now just print out, later we actually do something
		int i;
		int N = conNums.size();
		for(i = 0; i < N; i++){
			cout << "Delete Constraint with Index =  " << conNums[ i] << endl;
		}
	}
	DeleteConstraints(int conNumber_){
		conNumber = conNumber_;
	}
	DeleteConstraints(){
	}
}; //class DeleteConstraints

class RunAccumulate {
	std::vector<ModOSInstance*> accum;
	public:
	void add( ModOSInstance* osmod){
		accum.push_back( osmod);
	}//add
	void runaccumulate(){
		std::vector<ModOSInstance*>::iterator iter =  accum.begin();
		while(iter != accum.end()) (*iter++)->accumulate();
	}
};// class RunAccumlate

int main(int argC, char* argV[])
{
	RunAccumulate accumulate;
	accumulate.add( new DeleteConstraints( 11) );
	accumulate.add( new DeleteConstraints( 19) );
	accumulate.add( new DeleteConstraints( 37) );
	accumulate.runaccumulate();
	cout << "HELLO GAIL" << endl;   
	ModOSInstance *delcon;
	delcon = new DeleteConstraints();
	delcon->modify();
	return 0;
}

