//
// Created by daniel on 12/19/18.
//

#ifndef UNTITLED_COMMANDFACTORY_H
#define UNTITLED_COMMANDFACTORY_H


#include "Command.h"

class CommandFactory {
public:
    CommandFactory() = default;
    virtual Command* create() = 0;
    virtual ~CommandFactory() = default;
};


#endif //UNTITLED_COMMANDFACTORY_H
