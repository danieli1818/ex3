//
// Created by daniel on 12/23/18.
//

#include "WhileCommandFactory.h"
#include "WhileCommand.h"

Command* WhileCommandFactory::create() {
    return new WhileCommand();
}


