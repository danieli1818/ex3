//
// Created by daniel on 12/21/18.
//

#include "VarCommand.h"
#include "../Expression/ExpressionManager.h"
#include "../Vars/Variable.h"
#include "../Vars/ToolBox.h"

void VarCommand::doCommand(list<string>::iterator &it, list<string> &args) {
    try {
        ExpressionManager em;
        string varName = *it;
        if (!isValidVarName(varName)) {
            throw "Not Valid Var Command";
        }
        it++;
        if (*it != "=") {
            throw "Not Valid Var Command";
        }
        it++;
        if (ToolBox::getSymbolTable().getVariable(varName) != nullptr) {
            throw "Var Already Created!!!!";
        }
        if (*it == "bind") {
            auto v = new Variable();
            it++;
            if (it == args.end()) {
                throw "Not Valid Var Command";
            } else {
                string path = *it;
                if (path[0] != '\"' || path[path.length() - 1] != '\"') {
                    Variable * var2 = ToolBox::getSymbolTable().getVariable(*it);
                    if (var2 == nullptr) {
                        throw "Not Valid String!!!!";
                    }
                    auto v = new Variable();
                    v->setData(var2->getData(), false);
                    v->bind(var2, path);
                    it++;
                    ToolBox::getSymbolTable().setVariable(varName, v);
                }
                string pathWithoutQuotes = path.substr(1, path.length() - 2);
                v->bind(pathWithoutQuotes);
                it++;
                ToolBox::getSymbolTable().setVariable(varName, v);
            }
//        } else if (ToolBox::getSymbolTable().getVariable(*it) != nullptr) {
//            Variable * var2 = ToolBox::getSymbolTable().getVariable(*it);
//            auto v = new Variable();
//            v->setData(var2->getData(), false);
//            it++;
//            ToolBox::getSymbolTable().setVariable(varName, v);
        } else {
            auto v = new Variable();
            v->setData(em.calculate(it, args), false);
            ToolBox::getSymbolTable().setVariable(varName, v);
            //throw "Not Valid Var Command";
        }
    } catch (...) {
        throw;
    }
}

bool VarCommand::isNumber(string str) {
    try {
        stod(str);
        return true;
    } catch (...) {
        return false;
    }
//    return find_if(str.begin(), str.end(), [](char c){
//        return !isdigit(c);
//    }) == str.end();
}

bool VarCommand::isValidVarName(string varName) {
    if (varName.empty()) {
        return false;
    }
    if (!((varName[0] >= 'a' && varName[0] <= 'z') || (varName[0] >= 'A' && varName[0] <= 'Z'))) {
        return false;
    }
    for (auto const & character : varName) {
        if (!((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z') || (character >= '0' && character <= '9'))) {
            return false;
        }
    }
    ToolBox::initialize();
    list<string> savedWords = ToolBox::getSavedWords();
    if (find(savedWords.begin(), savedWords.end(), varName) != savedWords.end()) {
        return false;
    }
    return true;
}


