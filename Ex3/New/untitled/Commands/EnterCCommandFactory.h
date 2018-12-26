//
// Created by daniel on 12/26/18.
//

#ifndef UNTITLED_ENTERCCOMMANDFACTORY_H
#define UNTITLED_ENTERCCOMMANDFACTORY_H


#include "CommandFactory.h"

class EnterCCommandFactory : public CommandFactory {
    virtual Command* create();
};


#endif //UNTITLED_ENTERCCOMMANDFACTORY_H
