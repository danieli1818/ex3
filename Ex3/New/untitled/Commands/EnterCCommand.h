//
// Created by daniel on 12/26/18.
//

#ifndef UNTITLED_ENTERCCOMMAND_H
#define UNTITLED_ENTERCCOMMAND_H


#include "Command.h"

class EnterCCommand : public Command {
public:
    EnterCCommand() = default;
    virtual void doCommand(list<string>::iterator& it, list<string> & args);
    ~EnterCCommand() = default;
};


#endif //UNTITLED_ENTERCCOMMAND_H
