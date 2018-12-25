//
// Created by daniel on 12/20/18.
//

#ifndef UNTITLED_PRINTCOMMANDFACTORY_H
#define UNTITLED_PRINTCOMMANDFACTORY_H


#include "CommandFactory.h"
#include "PrintCommand.h"

class PrintCommandFactory : public CommandFactory {
public:
    virtual Command* create();
};


#endif //UNTITLED_PRINTCOMMANDFACTORY_H
