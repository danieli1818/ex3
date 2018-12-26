//
// Created by daniel on 12/23/18.
//

#ifndef UNTITLED_IFCOMMANDFACTORY_H
#define UNTITLED_IFCOMMANDFACTORY_H


#include "CommandFactory.h"

class IfCommandFactory : public CommandFactory {
    virtual Command* create();
};


#endif //UNTITLED_IFCOMMANDFACTORY_H
