//
// Created by daniel on 12/24/18.
//

#ifndef UNTITLED_SLEEPCOMMANDFACTORY_H
#define UNTITLED_SLEEPCOMMANDFACTORY_H


#include "CommandFactory.h"

class SleepCommandFactory : public CommandFactory {
public:
    SleepCommandFactory() = default;
    virtual Command* create();
    ~SleepCommandFactory() = default;
};


#endif //UNTITLED_SLEEPCOMMANDFACTORY_H
