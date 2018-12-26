//
// Created by daniel on 12/23/18.
//

#include "IfCommandFactory.h"
#include "IfCommand.h"

Command* IfCommandFactory::create() {
    return new IfCommand();
}


