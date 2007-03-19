// code for modifying an OSInstance


#include <iostream>
#include <vector>
#include <string>
#include <map>

using std::cout;
using std::endl;


// this is the virtual class that all command classes inherite from
class OsiXForm {
	public:
	// build a queue of operations to perform
	virtual void record() = 0;
	// this method will execute the operations that have been accumulated in the queue
	virtual void modify() = 0;
	// opid is an integer that identifies each kind of operation, e.g. delete a constraint,
	// add a variable etc.
	int opid;
	// the constructor and destructor
	 OsiXForm(){}
	virtual	~OsiXForm(){}
}; //class OsiXForm

// an example command class, delete a bunch of constraints
class DeleteConstraints : public OsiXForm{
	private:
	int conNumber;
	// this vector holds the list of constraints to delete
	static std::vector<int> conNums;
	public:
	void record( ){
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
class AddVariables : public OsiXForm{
	private:
	int varNumber;
	// a vector that holds the indicies of variables to add
	static std::vector<int> varNums;
	//
	public:
	void record( ){
		varNums.push_back( varNumber);
		cout << "Accumulating a Variable with Index =  " << varNumber << endl;
	}
	void modify(){
		// for now just print out, later we actually do something and add a varible
		int i;
		int N = varNums.size();
		for(i = 0; i < N; i++){
			cout << "Delete Variable with Index =  " << varNums[ i] << endl;
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
// initialize static member varNums
std::vector<int> AddVariables::varNums;

class OsiXFormRec {
	// the vector modObjects stores operations used to modify the instance
	std::vector<OsiXForm*> modObjects;
	public:
	std::map<int, OsiXForm*> modObjectsMap;
	// add an object modifier
	void record( OsiXForm* osmod){
		modObjects.push_back( osmod);
	}//add
	//run the record method in each operation
	void callModClasses(){
		std::vector<OsiXForm*>::iterator iter =  modObjects.begin();
		while(iter != modObjects.end()){
			(*iter)->record();
			// build a map of object modifications/transormations
			// we use this map to record which modification classes have been used
			// the key is the opid of each modification class
			// if the object is not in the map, add it
			if( modObjectsMap.find( (*iter)->opid) == modObjectsMap.end() ){
				modObjectsMap[ (*iter)->opid] = *iter;
			}
			iter++;			
		}
	}
};// class OsiXFormRec  

int main(int argC, char* argV[])
{
	std::map<int, OsiXForm*>::iterator objectPos;
	OsiXFormRec modification;
	// delete some constraints and add some variables
	modification.record( new DeleteConstraints( 11) );
	modification.record( new DeleteConstraints( 19) );
	modification.record( new AddVariables( 1010) );
	modification.record( new DeleteConstraints( 37) );
	modification.record( new AddVariables( 20019) );
	modification.callModClasses();
  
	
for(objectPos = modification.modObjectsMap.begin(); objectPos != modification.modObjectsMap.end(); ++objectPos){
		(objectPos->second)->modify();
	}
	return 0;
}

