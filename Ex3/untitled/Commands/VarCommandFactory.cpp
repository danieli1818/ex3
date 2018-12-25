//
// Created by daniel on 12/22/18.
//

#include "VarCommandFactory.h"

Command* VarCommandFactory::create() {
    return new VarCommand();
}


