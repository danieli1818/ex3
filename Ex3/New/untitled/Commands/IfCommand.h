//
// Created by daniel on 12/20/18.
//

#ifndef UNTITLED_IFCOMMAND_H
#define UNTITLED_IFCOMMAND_H


#include <vector>
#include "Command.h"

class IfCommand : public Command {
public:
    IfCommand() = default;
    virtual void doCommand(list<string>::iterator& it, list<string> & args);
    virtual ~IfCommand() = default;
};


#endif //UNTITLED_IFCOMMAND_H
