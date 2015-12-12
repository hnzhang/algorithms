#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Part {
public:
	string name() {
		return "X";
	}   
};

class Operation {
public:
	string name;

	Operation( ) : mDFSFlag(0) {}
	Operation( const Operation& operation) : name(operation.name),  mDFSFlag(0) { }
	Operation(string _name) : name(_name),  mDFSFlag(0) {
    }

	void operate(Part p) {
		cout << "Operation " << name << " on part " << p.name() << endl;
    }
    
    Operation& operator=(Operation other) {
        name = other.name;
        return *this;
    }
    void addEdge(Operation& operation){
        if(operation.name.compare(name) == 0) return;
        auto p = find (mParentSteps.begin(), mParentSteps.end(), operation.name);
        if(p == mParentSteps.end()) {
            mParentSteps.push_back(operation.name);
        }
	}

    void set_flag(int flag){
        mDFSFlag = flag;
    }

    int get_flag(){
        return mDFSFlag;
    }

    const vector<string>& get_next_steps() const{
        return mParentSteps;
    }
private:
    vector<string> mParentSteps; //for all dependencies
    int mDFSFlag;//0--not visited, 1--visited;
};

class StepManager {
public:
	void add_operation(Operation operation, vector<string> prerequisites) {
		// Add your implementation here. This method is called
		// once for each type of operation during setup.

        auto got = mOperations.find (operation.name);
        if(got == mOperations.end())//doesn't exists
            mOperations[operation.name] = operation;

        for(auto i:prerequisites){//construct the graph
           auto got = mOperations.find (i);
           if(got == mOperations.end())//doesn't exists, add it in.
                mOperations[i] = Operation(i);
            mOperations[operation.name].addEdge(mOperations[i]);
        }
	}

	void perform_operation(string operation_name, Part p) {
		// Add your implementation here. When this method is called,
		// you must call the 'operate()' method for the named operation,
		// as well as all prerequisites for that operation.

        if(mOperations.empty())
            return;

        //perform an dfs
        mOperationSequence.clear();
 
        //reset dfs flags to 0;
        for ( auto it = mOperations.begin(); it != mOperations.end(); ++it ){
            it->second.set_flag(0);
        }

        dependency_sort(operation_name);

        cout << "All Operations for final" << endl;
        //do operations in sequence, which are in reversed order
        for(auto o :mOperationSequence)
        {
            mOperations[o].operate(p);
        }
}
private:
    void dependency_sort(const string& name){
        if(mOperations[name].get_flag() != 0)//processed already
            return;
        cout <<"discover operation: " << name << endl;
        mOperations[name].set_flag(1);
        for( auto next : mOperations[name].get_next_steps()){
            Operation& operation = mOperations[next];
            if(operation.get_flag() == 0) {
                dependency_sort(operation.name);
            }
        }
        //update operationSequence;
        cout << "add operation: " << name << endl;
        mOperationSequence.push_back(name);
    }
    unordered_map<std::string,Operation> mOperations;
    vector<string> mOperationSequence;    
};

int main() {
	StepManager step_mgr;

	string s;
	while (getline(cin, s)) {
		if (s[0] == '#')
			continue;
        if(s.length() == 0)
            break;

		stringstream ss(s);
		string name, tmp;
		vector<string> prerequisites;

		getline(ss, name, ',');
		while (getline(ss, tmp, ',')) {
			prerequisites.push_back(tmp);
		}

		step_mgr.add_operation(Operation(name), prerequisites);
	}

	step_mgr.perform_operation("final", Part());
}
