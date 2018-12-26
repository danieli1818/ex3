//
// Created by daniel on 12/20/18.
//

#include "OpenServerCommandFactory.h"
#include "OpenServerCommand.h"

OpenServerCommandFactory::OpenServerCommandFactory() {}

Command* OpenServerCommandFactory::create() {
    return new OpenServerCommand();
}


