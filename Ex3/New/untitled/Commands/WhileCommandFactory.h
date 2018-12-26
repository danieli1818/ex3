//
// Created by daniel on 12/23/18.
//

#ifndef UNTITLED_WHILECOMMANDFACTORY_H
#define UNTITLED_WHILECOMMANDFACTORY_H


#include "CommandFactory.h"

class WhileCommandFactory : public CommandFactory {
public:
    WhileCommandFactory() = default;
    virtual Command* create();
    ~WhileCommandFactory() = default;
};


#endif //UNTITLED_WHILECOMMANDFACTORY_H
