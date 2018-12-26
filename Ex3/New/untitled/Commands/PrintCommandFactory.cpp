//
// Created by daniel on 12/20/18.
//

#include "PrintCommandFactory.h"

Command* PrintCommandFactory::create() {
    return new PrintCommand();
}


