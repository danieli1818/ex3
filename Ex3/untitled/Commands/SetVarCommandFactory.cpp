//
// Created by daniel on 12/22/18.
//

#include "SetVarCommandFactory.h"

Command* SetVarCommandFactory::create() {
    return new SetVarCommand();
}


