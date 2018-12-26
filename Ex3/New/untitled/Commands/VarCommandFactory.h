//
// Created by daniel on 12/22/18.
//

#ifndef UNTITLED_VARCOMMANDFACTORY_H
#define UNTITLED_VARCOMMANDFACTORY_H


#include "CommandFactory.h"
#include "VarCommand.h"

class VarCommandFactory : public CommandFactory {
public:
    VarCommandFactory() = default;
    virtual Command* create();
    ~VarCommandFactory() = default;
};


#endif //UNTITLED_VARCOMMANDFACTORY_H
