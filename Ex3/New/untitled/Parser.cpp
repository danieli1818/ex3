//
// Created by danie on 17/12/2018.
//

#include "Parser.h"
#include "Interpreter.h"
#include "Commands/IfCommandFactory.h"
#include "Commands/WhileCommandFactory.h"
#include "Commands/SleepCommandFactory.h"
#include "Vars/ToolBox.h"
#include "Commands/EnterCCommandFactory.h"

map<string, CommandFactory*> Parser::parserMap;

Command* Parser::getCommandFromString(string str) {
    if (parserMap.count(str) == 0) {
        return nullptr;
    } else {
        return parserMap[str]->create();
    }
}

void Parser::initialize() {
    Parser::parserMap =  {
            {"openDataServer", new OpenServerCommandFactory()},
            {"print", new PrintCommandFactory()},
            {"connect", new ConnectCommandFactory()},
            {"var", new VarCommandFactory()},
            {"if", new IfCommandFactory()},
            {"while", new WhileCommandFactory()},
            {"sleep", new SleepCommandFactory()},
            {"enterc", new EnterCCommandFactory()}
    };
}

void Parser::parser(list<string> elements) {
    list<string>::iterator it = elements.begin();
    Command* currentCommand;
    while (it != elements.end()) {
        currentCommand = Interpreter::getParser().getCommandFromString(*it);
        if (currentCommand == nullptr) {
            if (ToolBox::getSymbolTable().getVariable(*it) != nullptr) {
                currentCommand = new SetVarCommand();
            } else {
                throw "Not Valid Command " + *it;
            }
        } else {
            it++;
        }
        currentCommand->doCommand(it, elements);
        delete currentCommand;
    }
}

Parser::~Parser() {
    for (auto & elem : parserMap) {
        delete elem.second;
    }
    parserMap.clear();
}


