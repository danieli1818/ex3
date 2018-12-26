//
// Created by danie on 17/12/2018.
//

#ifndef UNTITLED_PARSER_H
#define UNTITLED_PARSER_H

#include <string>
#include <map>
#include "Commands/Command.h"
#include "Commands/OpenServerCommand.h"
#include "Commands/CommandFactory.h"
#include "Commands/OpenServerCommandFactory.h"
#include "Commands/PrintCommandFactory.h"
#include "Commands/ConnectCommandFactory.h"
#include "Commands/VarCommandFactory.h"
#include "Commands/SetVarCommand.h"
#include "Vars/ToolBox.h"

using namespace std;

class Parser {
    static map<string, CommandFactory*> parserMap;
    Command* getCommandFromString(string str);
public:
    static void initialize();
    Parser() = default;
    void parser(list<string> elements);
    ~Parser();
};


#endif //UNTITLED_PARSER_H
