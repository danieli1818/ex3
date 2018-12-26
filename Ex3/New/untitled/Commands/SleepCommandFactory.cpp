//
// Created by daniel on 12/24/18.
//

#include "SleepCommandFactory.h"
#include "SleepCommand.h"

Command* SleepCommandFactory::create() {
    return new SleepCommand();
}


