//
// Created by daniel on 12/24/18.
//

#ifndef UNTITLED_SLEEPCOMMAND_H
#define UNTITLED_SLEEPCOMMAND_H


#include "Command.h"

class SleepCommand : public Command {
public:
    SleepCommand() = default;
    virtual void doCommand(list<string>::iterator& it, list<string> & args);
    ~SleepCommand() = default;
};


#endif //UNTITLED_SLEEPCOMMAND_H
