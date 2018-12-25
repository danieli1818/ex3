//
// Created by daniel on 12/22/18.
//

#ifndef UNTITLED_SETVARCOMMAND_H
#define UNTITLED_SETVARCOMMAND_H


#include "Command.h"
#include "../Vars/ToolBox.h"
#include "../Expression/ExpressionManager.h"

class SetVarCommand : public Command {
public:
    SetVarCommand() = default;
    virtual void doCommand(list<string>::iterator& it, list<string> & args);
    ~SetVarCommand() = default;
};


#endif //UNTITLED_SETVARCOMMAND_H
