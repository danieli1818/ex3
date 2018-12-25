//
// Created by daniel on 12/21/18.
//

#include "ConnectCommandFactory.h"
#include "ConnectCommand.h"

Command* ConnectCommandFactory::create() {
    return new ConnectCommand();
}


