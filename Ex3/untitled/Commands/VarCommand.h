//
// Created by daniel on 12/21/18.
//

#ifndef UNTITLED_VARCOMMAND_H
#define UNTITLED_VARCOMMAND_H

#include <string>
#include <list>
#include "Command.h"

using namespace std;

class VarCommand : public Command {
    bool isNumber(string str);
    bool isValidVarName(string varName);
public:
    VarCommand() = default;
    virtual void doCommand(list<string>::iterator& it, list<string> & args);
    virtual ~VarCommand() = default;
};


#endif //UNTITLED_VARCOMMAND_H
