//
// Created by daniel on 12/21/18.
//

#ifndef UNTITLED_CONNECTCOMMANDFACTORY_H
#define UNTITLED_CONNECTCOMMANDFACTORY_H


#include "CommandFactory.h"

class ConnectCommandFactory : public CommandFactory {
public:
    ConnectCommandFactory() = default;
    Command* create();
    virtual ~ConnectCommandFactory() = default;
};


#endif //UNTITLED_CONNECTCOMMANDFACTORY_H
