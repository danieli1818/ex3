//
// Created by daniel on 12/23/18.
//

#ifndef UNTITLED_WHILECOMMAND_H
#define UNTITLED_WHILECOMMAND_H


#include <vector>
#include "Command.h"

class WhileCommand : public Command {
    list<string> m_condition;
    vector<list<string>> m_commandsStrings;
public:
    WhileCommand() = default;
    virtual void doCommand(list<string>::iterator& it, list<string> & args);
    ~WhileCommand() = default;
};


#endif //UNTITLED_WHILECOMMAND_H
