//
// Created by daniel on 12/18/18.
//

#ifndef UNTITLED_SYMBOLTABLE_H
#define UNTITLED_SYMBOLTABLE_H

#include <string>
#include <map>
#include <vector>
#include "Variable.h"
#include "../Utils.h"

using namespace std;

class SymbolTable {
    map<string, Variable*> table;
    map<string, int> flightParameters;
public:
    SymbolTable();
    Variable* getVariable(string name);
    void setVariable(string name, Variable* var);
    void updateSymbolTable(string& message);
    void updateVariable(vector<string>& args, string varName);
    ~SymbolTable();
};


#endif //UNTITLED_SYMBOLTABLE_H
