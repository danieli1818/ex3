//
// Created by daniel on 12/22/18.
//

#ifndef UNTITLED_SETVARCOMMANDFACTORY_H
#define UNTITLED_SETVARCOMMANDFACTORY_H


#include "CommandFactory.h"
#include "SetVarCommand.h"

class SetVarCommandFactory : public CommandFactory {
public:
    SetVarCommandFactory() = default;
    virtual Command* create();
    ~SetVarCommandFactory() = default;
};


#endif //UNTITLED_SETVARCOMMANDFACTORY_H
