//
// Created by daniel on 12/22/18.
//

#include "SetVarCommand.h"

void SetVarCommand::doCommand(list<string>::iterator &it, list<string> &args) {
    if (it == args.end()) {
        throw "Not Enough Parameters!!!!";
    }
    string varName = *it;
    it++;
    Variable * var = ToolBox::getSymbolTable().getVariable(varName);
    if (var == nullptr) {
        throw "Var doesn't exists!!!!";
    }
    if (it == args.end()) {
        throw "Not Enough Parameters!!!!";
    }
    if (*it != "=") {
        throw "Not Valid Command!!!!";
    }
    it++;
    if (it == args.end()) {
        throw "Not Enough Parameters!!!!";
    }
    ExpressionManager em;
    var->setData(em.calculate(it, args), true);
}


