//
// Created by daniel on 12/20/18.
//

#ifndef UNTITLED_OPENSERVERCOMMANDFACTORY_H
#define UNTITLED_OPENSERVERCOMMANDFACTORY_H


#include "CommandFactory.h"

class OpenServerCommandFactory : public CommandFactory {
public:
    OpenServerCommandFactory();
    virtual Command* create();
    ~OpenServerCommandFactory() = default;
};


#endif //UNTITLED_OPENSERVERCOMMANDFACTORY_H
