// code for modifying an OSInstance


#include <iostream>
#include <vector>
#include <string>
#include <map>

using std::cout;
using std::endl;


// this is the virtual class that all command classes inherite from
class ModOSInstance {
	public:
	// build a queue of operations to perform
	virtual void accumulate() = 0;
	// this method will execute the operations that have been accumulated in the queue
	virtual void modify() = 0;
	// opid is an integer that identifies each kind of operation, e.g. delete a constraint,
	// add a variable etc.
	int opid;
	// the constructor and destructor
	 ModOSInstance(){}
	virtual	~ModOSInstance(){}
}; //class ModOSInstance

// an example command class, delete a bunch of constraints
class DeleteConstraints : public ModOSInstance{
	private:
	int conNumber;
	// this vector holds the list of constraints to delete
	static std::vector<int> conNums;
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
		opid = 1;
	}
	DeleteConstraints(){
	opid = 1;
	}
	~DeleteConstraints(){
	}
}; //class DeleteConstraints
// initialize static member conNums
std::vector<int> DeleteConstraints::conNums;

// an example class, add a bunch of variables
class AddVariables : public ModOSInstance{
	private:
	int varNumber;
	// a vector that holds the indicies of variables to add
	static std::vector<int> varNums;
	//
	public:
	void accumulate( ){
		varNums.push_back( varNumber);
		cout << "Accumulating a Variable with Index =  " << varNumber << endl;
	}
	void modify(){
		// for now just print out, later we actually do something and add a varible
		int i;
		int N = varNums.size();
		for(i = 0; i < N; i++){
			cout << "Delete Constraint with Index =  " << varNums[ i] << endl;
		}
	}
	// for now this constructor only takes a variable number. Later
	// we would take other information such as coeficients of the variable to add.
	AddVariables(int varNumber_){
		varNumber = varNumber_;
		opid = 2;
	}
	AddVariables(){
		opid = 2;
	}
	~AddVariables(){
	}
}; //class AddVariales
// initialize static member conNums
std::vector<int> AddVariables::varNums;

class RunAccumulate {
	// the vector accum stores operations used to modify the instance
	std::vector<ModOSInstance*> accum;
	public:
	std::map<int, ModOSInstance*> modObjectsMap;
	// add an object modifier
	void add( ModOSInstance* osmod){
		accum.push_back( osmod);
	}//add
	//run the accumulate method in each operation
	void runaccumulate(){
		std::vector<ModOSInstance*>::iterator iter =  accum.begin();
		while(iter != accum.end()){
			(*iter)->accumulate();
			// build a map of object operations that being performed
			// if the object is not in the map, add ii
			if( modObjectsMap.find( (*iter)->opid) == modObjectsMap.end() ){
				modObjectsMap[ (*iter)->opid] = *iter;
			}
			iter++;			
		}
	}
};// class RunAccumlate

int main(int argC, char* argV[])
{
	std::map<int, ModOSInstance*>::iterator objectPos;
	RunAccumulate accumulate;
	// delete some constraints and add some variables
	accumulate.add( new DeleteConstraints( 11) );
	accumulate.add( new DeleteConstraints( 19) );
	accumulate.add( new AddVariables( 1010) );
	accumulate.add( new DeleteConstraints( 37) );
	accumulate.add( new AddVariables( 20019) );
	accumulate.runaccumulate();
  
	
for(objectPos = accumulate.modObjectsMap.begin(); objectPos != accumulate.modObjectsMap.end(); ++objectPos){
		(objectPos->second)->modify();
	}
	return 0;
}

