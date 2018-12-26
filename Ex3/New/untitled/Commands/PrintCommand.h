//
// Created by daniel on 12/20/18.
//

#ifndef UNTITLED_PRINTCOMMAND_H
#define UNTITLED_PRINTCOMMAND_H


#include "Command.h"

class PrintCommand : public Command {
    virtual void doCommand(list<string>::iterator& it, list<string> & args);
};


#endif //UNTITLED_PRINTCOMMAND_H
