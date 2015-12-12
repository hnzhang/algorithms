#dag sort in python
import sys
import fileinput

class Part:
    def name(self):
        return "X";
class Operation:

    def __init__(self, _name):
        self.dfsFlag = 0
        self.parent_steps = []
        self.name = _name;
    def addEdge(self, operation):
        if(operation.name == self.name): return

        if(not operation.name in self.parent_steps):
            self.parent_steps.append(operation.name)

    def operate(self, part):
        print "Operation %s on Part %s" % ( self.name, part.name())

class StepManager:
    def __init__(self):
        self.Operations = {}
        self.OperationSequence = []

    def add_operation(self, operation_name, prerequisites):
        if(not self.Operations.has_key(operation_name)):
            self.Operations[operation_name] = Operation(operation_name);

        for i in prerequisites:
            i = i.rstrip()
            if(not self.Operations.has_key(i)):
                self.Operations[i] = Operation(i)

            self.Operations[operation_name].addEdge(self.Operations[i])

    def perform_operation(self, operation_name,  p):
        if(len(self.Operations) == 0): return
        for val in self.Operations.values():
            val.dfsFlag = 0

        self.OperationSequence = []
        self.dependency_sort(operation_name)

        for i in self.OperationSequence:
            self.Operations[i].operate(p)

    def dependency_sort(self, operation_name):
        if(self.Operations[operation_name].dfsFlag != 0): return

        self.Operations[operation_name].dfsFlag = 1
        for i in self.Operations[operation_name].parent_steps:
            self.dependency_sort(i)

        self.OperationSequence.append(operation_name)

if __name__ ==  "__main__":
    step_mgr = StepManager()
    for line in fileinput.input():
        if(len(line) == 0): continue
        if(line[0] == '#'):
            continue

        operations =line.split(',')
        if(operations):
            prerequisites = []
            if(len(operations) >1):
                prerequisites = operations[1:]
            step_mgr.add_operation(operations[0].rstrip(), prerequisites)
    print step_mgr.Operations.keys()
    step_mgr.perform_operation("final", Part())
    step_mgr.perform_operation("nine", Part())


