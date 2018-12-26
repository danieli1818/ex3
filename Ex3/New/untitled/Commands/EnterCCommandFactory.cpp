//
// Created by daniel on 12/26/18.
//

#include "EnterCCommandFactory.h"
#include "EnterCCommand.h"

Command* EnterCCommandFactory::create() {
    return new EnterCCommand();
}


