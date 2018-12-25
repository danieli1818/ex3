//
// Created by daniel on 12/18/18.
//

#include "SymbolTable.h"
#include "ToolBox.h"

SymbolTable::SymbolTable() {
    flightParameters = {
            {"/instrumentation/airspeed-indicator/indicated-speed-kt", 0},
            {"/instrumentation/altimeter/indicated-altitude-ft", 1},
            {"/instrumentation/altimeter/pressure-alt-ft", 2},
            {"/instrumentation/attitude-indicator/indicated-pitch-deg", 3},
            {"/instrumentation/attitude-indicator/indicated-roll-deg", 4},
            {"/instrumentation/attitude-indicator/internal-pitch-deg", 5},
            {"/instrumentation/attitude-indicator/internal-roll-deg", 6},
            {"/instrumentation/encoder/indicated-altitude-ft", 7},
            {"/instrumentation/encoder/pressure-alt-ft", 8},
            {"/instrumentation/gps/indicated-altitude-ft", 9},
            {"/instrumentation/gps/indicated-ground-speed-kt", 10},
            {"/instrumentation/gps/indicated-vertical-speed", 11},
            {"/instrumentation/heading-indicator/indicated-heading-deg", 12},
            {"/instrumentation/magnetic-compass/indicated-heading-deg", 13},
            {"/instrumentation/slip-skid-ball/indicated-slip-skid", 14},
            {"/instrumentation/turn-indicator/indicated-turn-rate", 15},
            {"/instrumentation/vertical-speed-indicator/indicated-speed-fpm", 16},
            {"/controls/flight/aileron", 17},
            {"/controls/flight/elevator", 18},
            {"/controls/flight/rudder", 19},
            {"/controls/flight/flaps", 20},
            {"/controls/engines/engine/throttle", 21},
            {"/engines/engine/rpm", 22}

    };
}

Variable* SymbolTable::getVariable(string name) {
    if (table.count(name) == 1) {
        return table[name];
    }
    return nullptr;
}

void SymbolTable::setVariable(string name, Variable *var) {
    pthread_mutex_lock(&(ToolBox::getMutex()));
    if (table.count(name) == 1) {
        delete table[name]; //TODO check if to throw exception for variable is set twice.
        table[name] = var;
    } else {
        table[name] = var;
    }
    pthread_mutex_unlock(&(ToolBox::getMutex()));
}

SymbolTable::~SymbolTable() {
    for (auto & elem : table) {
        delete elem.second;
    }
    table.clear();
}

void SymbolTable::updateSymbolTable(string& message) { //TODO
    pthread_mutex_lock(&(ToolBox::getMutex()));
    vector<string> args = Utils::split(message, ",");
    for (auto & pair : table) {
        Variable* currentVar = pair.second;
        currentVar->setUpdate(false);
    }
    for (auto & pair : table) {
        updateVariable(args, pair.first);
    }
    pthread_mutex_unlock(&(ToolBox::getMutex()));
}

void SymbolTable::updateVariable(vector<string> &args, string varName) {
    if (table.count(varName) == 0) {
        throw "Var doesn't exist!!!!";
    }
    Variable * var = table[varName];
    if (var->updated()) {
        return;
    }
    if (var->isBinded() && flightParameters.count(var->getBindedPath()) == 1) {
        var->setData(stod(args[flightParameters[var->getBindedPath()]]), false);
        var->setUpdate(true);
        return;
    }
    if (var->getBindedVariable() != "") {
        var->setUpdate(true);
        updateVariable(args, var->getBindedVariable());
        var->setData(table[var->getBindedVariable()]->getData(), false);
    }
}
